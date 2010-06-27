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
 *   med_c_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media c task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/


#ifndef MED_C_NOT_PRESENT


/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h" 
#include "kal_trace.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"          /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"         /* Task creation */
#include "app_buff_alloc.h"        /* Declaration of buffer management API */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"          /* Event scheduler */
#include "stack_timer.h"         /* Stack timer */



/* global includes */


/* local include */
#include "med_global.h"
#include "med_struct.h"
#include "cam_main.h"
#include "med_c_struct.h"
#include "med_c_context.h"
#include "med_c_main.h"

/* global variables */
//med_c_context_struct   med_c_context;
//med_c_context_struct*   med_c_context_p = &med_c_context;



/*==== FUNCTIONS ===========*/

/******************************************************************
 * FUNCTION
 *    med_c_startup_hdlr
 * DESCRIPTION
 *    This function is handle startup procedure of media c task.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
void med_c_startup_hdlr(ilm_struct *ilm_ptr)
{

}




/******************************************************************
 * FUNCTION
 *    med_c_main
 * DESCRIPTION
 *    This function is main message dispatching function of media c task.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
void med_c_main( ilm_struct *ilm_ptr)
{
   switch( ilm_ptr->msg_id )
   {
#ifdef __MED_CAM_MOD__  
    case MSG_ID_MEDIA_C_CAM_EVENT_IND:
         cam_hp_event_ind_hdlr(ilm_ptr);
         break;

    case MSG_ID_MEDIA_CAM_PREVIEW_REQ:
         cam_preview_req_hdlr(ilm_ptr);
         break;
#endif
      default:
         break;
   }
}

/******************************************************************
 * FUNCTION
 *    med_c_task_main
 * DESCRIPTION
 *    This function is main function of media c task.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
void med_c_task_main( task_entry_struct *task_entry_ptr)
{
   ilm_struct current_ilm;
   kal_uint32 my_index;

   kal_get_my_task_index(&my_index);

   while (1) 
   {
      receive_msg_ext_q( task_info_g[task_entry_ptr->task_indx].task_ext_qid, 
                           &current_ilm);
      stack_set_active_module_id( my_index, current_ilm.dest_mod_id);

      med_c_main((void *) &current_ilm);
            
      free_ilm( &current_ilm);
   }

}


/******************************************************************
 * FUNCTION
 *    med_c_init
 * DESCRIPTION
 *    This function is used to init media c task.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
kal_bool med_c_init( task_indx_type task_indx )
{
//   VIS_ENTER_STATE(VISUAL_IDLE);
   return KAL_TRUE;
}

/******************************************************************
 * FUNCTION
 *    med_c_reset
 * DESCRIPTION
 *    This function is used to reset media c task.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
kal_bool med_c_reset( task_indx_type task_indx )
{
   return KAL_TRUE;
}

/******************************************************************
 * FUNCTION
 *    med_c_create
 * DESCRIPTION
 *    This function is used to create media c task configuration info.
 * PARAMETERS
 *    
 *    
 * RETURNS
 *
 * GLOBALS AFFECTED
 *  
 *  
 ******************************************************************/
kal_bool med_c_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct med_c_handler_info = 
   {
      med_c_task_main,         /* task entry function */
      med_c_init,         /* task initialization function */
      NULL,      /* task configuration function */
      med_c_reset,            /* task reset handler */
      NULL,            /* task termination handler */
   };

   *handle = (comptask_handler_struct*)&med_c_handler_info;
   
   return KAL_TRUE;
}



#endif /* MED_C_NOT_PRESENT */

