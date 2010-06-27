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
 *   kal_debug_sysdebug_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements system debug task which check timeout address
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Included header files
 *******************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stacklib.h"
#include "event_shed.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_timer.h"
#include "task_main_func.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "stack_init.h"
#include "syscomp_config.h"

#ifdef DEBUG_LEAK
/*******************************************************************************
 * Internal routines declaration
 *******************************************************************************/
static void sysdbg_start_base_timer(void *base_timer_ptr,unsigned int time_out);
static void sysdbg_stop_base_timer(void *base_timer_ptr);
static void sysdbg_base_timer_timeout_hdler( void* msg_ptr );
static kal_int32 sysdbg_timeout_cmp(const void *a, const void *b);
static lcd_dll_node* sysdbg_search_timeoutnode(lcd_dll *dll, void *addr);

   #define SYS_HASH_KEY    7

/*******************************************************************************
 * Internal data structure definition
 *******************************************************************************/
typedef struct timeout_node_struct_t {
   void                 *timeout_addr;
   eventid              timeout_event_id;
   kal_timer_func_ptr   timeout_handler;
   void                 *timeout_param_ptr;
} timeout_node_struct;

typedef struct sysdebug_context_struct_t {
   stack_timer_struct   sysdbg_base_timer;
   event_scheduler      *sysdbg_event_scheduler_ptr;
   lcd_dll*             sysdbg_timeout_hash[SYS_HASH_KEY];
} sysdebug_context_struct;

sysdebug_context_struct sysdebug_context;

/*************************************************************************
* FUNCTION
*  sysdebug_main
*
* DESCRIPTION
*  This function implements main function of system debug task
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*       Rex Luo         2002/07/09           Create initial version 1.0
*
*************************************************************************/
void sysdebug_main( task_entry_struct * task_entry_ptr )
{
   ilm_struct current_ilm;
   kal_uint32 my_index;
   int i;

   kal_get_my_task_index (&my_index);
   stack_set_active_module_id ( my_index, MOD_SYSDEBUG );

   /* Initialize ILM, and timer */
   stack_init_timer(&sysdebug_context.sysdbg_base_timer, "SYS Debug", MOD_SYSDEBUG);


   sysdebug_context.sysdbg_event_scheduler_ptr = new_evshed(&sysdebug_context.sysdbg_base_timer,
                                                            sysdbg_start_base_timer,
                                                            sysdbg_stop_base_timer,
                                                            0, kal_evshed_get_mem, kal_evshed_free_mem, 0);

   /* Initialize internal hash table */
   for (i=0; i<SYS_HASH_KEY; i++) {
      sysdebug_context.sysdbg_timeout_hash[i] = lcd_new_dll(sysdbg_timeout_cmp, kal_evshed_get_mem,
                                                            kal_evshed_free_mem);
   }

   while ( 1 ) {
      /* Process external queue */
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      switch (current_ilm.msg_id) {
      case MSG_ID_TIMER_EXPIRY:
         /* Check if the base timer is stopped or not */
         if (stack_is_time_out_valid(&sysdebug_context.sysdbg_base_timer)) {
            /* Execute event's timeout handler */
            evshed_timer_handler(sysdebug_context.sysdbg_event_scheduler_ptr);
         }
         /* Shoulbe be paired with stack_is_time_out_valid() */
         stack_process_time_out(&sysdebug_context.sysdbg_base_timer);

         break;
      default:
         break;
      }
      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION
*  sysdbg_timeout_cmp
*
* DESCRIPTION
*  This functions implement operations of system debug task base timer
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*       Rex Luo         2002/07/09           Create initial version 1.0
*
*************************************************************************/
static kal_int32
sysdbg_timeout_cmp(const void *a, const void *b)
{
   return(kal_int32)((kal_uint32)((timeout_node_struct*)a)->timeout_addr -
                     (kal_uint32)((timeout_node_struct*)a)->timeout_addr);
}

static void
sysdbg_start_base_timer(void *base_timer_ptr,unsigned int time_out)
{
   stack_start_timer((stack_timer_struct *)base_timer_ptr,
                     0,
                     time_out);
   return;
}

static void
sysdbg_stop_base_timer(void *base_timer_ptr)
{
   stack_stop_timer((stack_timer_struct *)base_timer_ptr);
   return;
}

static void
sysdbg_base_timer_timeout_hdler( void* msg_ptr )
{
   timeout_node_struct *timeout_node_ptr;

   timeout_node_ptr = (timeout_node_struct *)msg_ptr;
   kal_untimeout(timeout_node_ptr->timeout_addr);
   timeout_node_ptr->timeout_handler(timeout_node_ptr->timeout_param_ptr);

   lcd_dll_delete_node(
                      sysdebug_context.sysdbg_timeout_hash\
                      [(kal_uint32)(timeout_node_ptr->timeout_addr) % SYS_HASH_KEY],
                      (lcd_dll_node*)timeout_node_ptr);
}

static lcd_dll_node*
sysdbg_search_timeoutnode(lcd_dll *dll, void *addr)
{
   lcd_dll_node *node = dll->tail;

   if (node == NULL)
      return NULL;

   while (node != NULL) {
      if ( ((timeout_node_struct *)(node->data))->timeout_addr == addr)
         break;
      node = node->next;
   }
   return node;
}

/*************************************************************************
* FUNCTION
*  kal_settimeout
*
* DESCRIPTION
*  This function implements API of set timeout to an address, and callback
* routine, and parameter.
*
* CALLS
*
* PARAMETERS
*  addr           -  timeout address
*  handler_func_ptr  -  timeout handler
*  handler_param_ptr -  timeout handler's parameter
*  delay          -  delay time
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*       Rex Luo         2002/07/09           Create initial version 1.0
*
*************************************************************************/
void
kal_settimeout(void* addr, kal_timer_func_ptr handler_func_ptr,
               void* handler_param_ptr, kal_uint32 delay)
{
   timeout_node_struct *timeout_node_ptr;

   timeout_node_ptr = (timeout_node_struct*)kal_evshed_get_mem(sizeof(timeout_node_struct));
   timeout_node_ptr->timeout_addr = addr;

   timeout_node_ptr->timeout_handler = handler_func_ptr;
   timeout_node_ptr->timeout_param_ptr = handler_param_ptr;

   lcd_dll_insert_end(sysdebug_context.sysdbg_timeout_hash[(kal_uint32)addr % SYS_HASH_KEY],
                      timeout_node_ptr);

   timeout_node_ptr->timeout_event_id = evshed_set_event(
                                                        sysdebug_context.sysdbg_event_scheduler_ptr,
                                                        (kal_timer_func_ptr)sysdbg_base_timer_timeout_hdler, timeout_node_ptr,
                                                        delay);
}

/*************************************************************************
* FUNCTION
*  kal_untimeout
*
* DESCRIPTION
*  This function implements API of unset timeout to an address
*
* CALLS
*
* PARAMETERS
*  addr           -  untimeout address
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*       Rex Luo         2002/07/09           Create initial version 1.0
*
*************************************************************************/
void
kal_untimeout(void* addr)
{
   lcd_dll_node *node = sysdbg_search_timeoutnode(
                                                 sysdebug_context.sysdbg_timeout_hash[(kal_uint32)addr % SYS_HASH_KEY],
                                                 addr);
   lcd_dll_delete_node(sysdebug_context.sysdbg_timeout_hash[(kal_uint32)addr % SYS_HASH_KEY], node);
}

/* default timeout handler */
void
kal_default_timeouthandler(void* param)
{
   kal_assert_fail("address timeout", __FILE__, __LINE__, KAL_FALSE, 0, 0, 0);
}

/*************************************************************************
* FUNCTION
*  sysdebug_create
*
* DESCRIPTION
*  This function implements sysdebug entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
sysdebug_create(comptask_handler_struct **handle)
{
   static comptask_handler_struct sysdebug_handler_info =
   {
      sysdebug_main,             /* task entry function */
      NULL,                      /* task initialization function */
      NULL,                      /* task configuration function */
      NULL,                      /* task reset handler */
      NULL                       /* task termination handler */
   };

   *handle = &sysdebug_handler_info;
   return KAL_TRUE;
}
#endif /* DEBUG_LEAK */


