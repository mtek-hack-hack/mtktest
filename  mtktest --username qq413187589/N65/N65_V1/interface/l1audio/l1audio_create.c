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
 * l1sp_create.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements layer1 speech component task 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*************************************************************************
* Include Statements
 *************************************************************************/
#include "kal_release.h"      /* Basic data type */

#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "mph_types.h"
#include "mph_cs_def.h"
#include "mph_cs_msg.h"

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool l1sp_create(comptask_handler_struct **handle);
static void l1audio_main(task_entry_struct * task_entry_ptr);
void L1Audio_Task(unsigned argc, void *argv);

/*************************************************************************
* FUNCTION
*  l1sp_create
*
* DESCRIPTION
*  This function implements l1sp entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool l1sp_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct l1sp_handler_info =
   {
      l1audio_main,     /* task entry function */
      NULL,          /* task initialization function */
      NULL,          /* task configuration function */
      NULL,          /* task reset handler */
      NULL           /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&l1sp_handler_info;
   return KAL_TRUE;
}

static void l1audio_main(task_entry_struct * task_entry_ptr)
{
   kal_uint32 my_index;     

   kal_get_my_task_index( &my_index );     
   stack_set_active_module_id( my_index, MOD_L1SP );
   
   L1Audio_Task( 0, 0 );
/*   
   ilm_struct current_ilm;
   ilm_struct *ilm_ptr;

   ilm_ptr = allocate_ilm(MOD_L1SP);
   ilm_ptr->msg_id = MSG_ID_MPHC_POWER_SCAN_REQ;

   kal_print("Dummy PS:\n");
   kal_print(" Send Power Scan Request Primitive.\n");

   SEND_ILM(MOD_L1SP, MOD_L1, MPAL_L1_SAP, ilm_ptr);

   while ( 1 ) {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );

      switch (current_ilm.msg_id) {
      case MSG_ID_MPHC_POWER_SCAN_CNF:
         kal_print("Dummy PS:\n");
         kal_print("  Receive Power Scan Confirm Primitive.\n");

         ilm_ptr = allocate_ilm(MOD_L1SP);
         ilm_ptr->msg_id = MSG_ID_MPHC_POWER_SCAN_REQ;

         kal_print("Dummy PS:\n");
         kal_print(" Send Power Scan Request Primitive.\n");

         SEND_ILM(MOD_L1SP, MOD_L1, MPAL_L1_SAP, ilm_ptr);
         kal_sleep_task(100);
         break;
      default:
         break;
      }
      if (current_ilm.src_mod_id != MOD_TIMER) free_ilm(&current_ilm);
   }
*/
}


