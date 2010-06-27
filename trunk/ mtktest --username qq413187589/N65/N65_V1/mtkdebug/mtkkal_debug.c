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
 *   mtkkal_debug.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements MediaTek KAL (Kernel Abstraction Layer) Self-Debug
 *   functions.
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/
#include "kal_release.h"      /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "tst_ltlcom.h"

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h"       /* Event scheduler */

#include "stack_timer.h"      /* Stack timer */

#include "stdio.h"
#include "uart_sw.h"

#ifdef DEBUG_FLC
   #include "gprs_flc_kal.h"  /* Flow control */
#endif /* DEBUG_FLC */

#if defined(__MAUI_BASIC__) && defined(__NOR_FLASH_HARDWARE_TEST__)
extern void NOR_Flash_Test(void);
#endif
#if defined(__MAUI_BASIC__) && defined(__NAND_FLASH_HARDWARE_TEST__)
extern void NAND_Flash_Test(void);
#endif

#ifdef MTK_SYSSERV_DEBUG
/*******************************************************************************
 * Internal structure definition
 *******************************************************************************/
typedef struct ssdbg1_context_struct_t {
   stack_timer_struct  ssdbg1_timer0;
   stack_timer_struct  ssdbg1_base_timer;
   event_scheduler     *ssdbg1_event_scheduler_ptr;
   eventid             ssdbg1_event_id;
} ssdbg1_context_struct_t;

ssdbg1_context_struct_t ssdbg1_context;

typedef struct ssdbg2_context_struct_t {
   stack_timer_struct  ssdbg2_timer0;

   stack_timer_struct  ssdbg2_base_timer;
   event_scheduler     *ssdbg2_event_scheduler_ptr;
   eventid             ssdbg2_event_id;
} ssdbg2_context_struct_t;

ssdbg2_context_struct_t ssdbg2_context;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint32 id;
} ssdbg1_localpara_struct;

typedef struct {
   PEER_BUFF_HDR
   char* data;
} ssdbg1_peerbuff_struct;

/*******************************************************************************
 * Function declaration
 *******************************************************************************/
kal_bool ssdbg1_init(task_indx_type task_indx);
void ssdbg1_main ( task_entry_struct * task_entry_ptr );
void ssdbg2_main ( task_entry_struct * task_entry_ptr );
void ssdbg2_start_base_timer(void *base_timer_ptr,unsigned int time_out);
void ssdbg2_stop_base_timer(void *base_timer_ptr);
void ssdbg2_base_timer_timeout_hdler( void* msg_ptr );

/*************************************************************************
* FUNCTION
*  ssdbg1_create
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
ssdbg1_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct ssdbg1_handler_info =
   {
      ssdbg1_main,              /* task entry function */
      ssdbg1_init,              /* task initialization function */
      NULL,                     /* task configuration function */
      NULL,                     /* task reset handler */
      NULL                      /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&ssdbg1_handler_info;
   return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ssdbg2_create
*
* DESCRIPTION
*  This function implements ssdbg2 entity's create handler.
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
ssdbg2_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct ssdbg2_handler_info =
   {
      ssdbg2_main,              /* task entry function */
      NULL,                     /* task initialization function */
      NULL,                     /* task configuration function */
      NULL,                     /* task reset handler */
      NULL                      /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&ssdbg2_handler_info;
   return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  ssdbg1_main
*
* DESCRIPTION
*   This routine creates system service debug task 1.
*
* PARAMETERS
*
* RETURNS
*  kal_taskid (Id of the created task)
*
* GLOBALS AFFECTED
*
*************************************************************************/
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
#else

kal_bool ssdbg1_init(task_indx_type task_indx)
{
#ifdef _LOW_COST_SINGLE_BANK_FLASH_

#if defined(__MAUI_BASIC__) && defined( __NOR_FLASH_HARDWARE_TEST__)
   NOR_Flash_Test();
#endif

#endif   

   return KAL_TRUE;
}

void
ssdbg1_main ( task_entry_struct * task_entry_ptr )
{
   kal_uint32 Task_Time = 0;
   char display_str[128];
   ilm_struct current_ilm;
   ilm_struct *send_ilm;
   ssdbg1_localpara_struct *paraptr;
   ssdbg1_peerbuff_struct *peerbufptr;
   kal_uint8 *pduptr;
   kal_uint16 pdulength;
#ifdef DEBUG_KAL
   kal_uint32 my_index;
#endif /* DEBUG_KAL */
   int i;

#ifndef _LOW_COST_SINGLE_BANK_FLASH_

#if defined(__MAUI_BASIC__) && defined( __NOR_FLASH_HARDWARE_TEST__)
   NOR_Flash_Test();
#endif

#if defined(__MAUI_BASIC__) && defined(__NAND_FLASH_HARDWARE_TEST__)
   NAND_Flash_Test();
#endif
   
#endif
   
   kal_get_my_task_index (&my_index);
   stack_set_active_module_id ( my_index, MOD_SSDBG1 );

   /* Initialize ILM, and timer */
   stack_init_timer(&ssdbg1_context.ssdbg1_timer0, "SSDBG1 Timer0", MOD_SSDBG1);

   stack_start_timer(&ssdbg1_context.ssdbg1_timer0, 0, 10);

   while ( 1 ) {
      Task_Time++;

      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );

      switch (current_ilm.msg_id) {
      #ifdef TOUCH_PANEL_DEBUG
      case MSG_ID_TP_EVENT_IND:
         tp_track_sample_point();         
         break;
     case MSG_ID_TP_CALI_DONE:
         dbg_printWithTime("Cali. Done\r\n");
         break;
      #endif   
      default:
         break;
      }
      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION
*  ssdbg2_main
*
* DESCRIPTION
*   This routine creates system service debug task 2.
*
* PARAMETERS
*
* RETURNS
*  kal_taskid (Id of the created task)
*
* GLOBALS AFFECTED
*
*************************************************************************/
   #define SSDBG2_STACK_TIMER0      0

void
ssdbg2_main ( task_entry_struct * task_entry_ptr )
{
   kal_uint32 Task_Time = 0;
   char display_str[128];
   ilm_struct current_ilm;
   ssdbg1_localpara_struct *paraptr;
   ssdbg1_peerbuff_struct *peerbufptr;
   kal_uint8 *pduptr;
   kal_uint16 pdulength;
#ifdef DEBUG_KAL
   kal_uint32 my_index;
#endif /* DEBUG_KAL */

   kal_get_my_task_index (&my_index);
   stack_set_active_module_id ( my_index, MOD_SSDBG2 );

   stack_init_timer(&ssdbg2_context.ssdbg2_base_timer, "SSDBG2 Base Timer", MOD_SSDBG2);

   ssdbg2_context.ssdbg2_event_scheduler_ptr = new_evshed(&ssdbg2_context.ssdbg2_base_timer,
                                                          ssdbg2_start_base_timer,
                                                          ssdbg2_stop_base_timer,
                                                          0 , kal_evshed_get_mem, kal_evshed_free_mem, 0);

   /* Set an event after 200 msec later */
   ssdbg2_context.ssdbg2_event_id = evshed_set_event(ssdbg2_context.ssdbg2_event_scheduler_ptr,
                                                     (kal_timer_func_ptr)ssdbg2_base_timer_timeout_hdler, NULL, KAL_TICKS_500_MSEC);

   /* kal_mem_set(&current_ilm, 0, sizeof(ilm_struct)); */

   while ( 1 ) {
      Task_Time++;

      /* Process internal queue first */
#if 0 /* Remove internal Queue */
#ifdef MTK_NEW_API
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MTK_NEW_API */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

      /* Process external queue */
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
      switch (current_ilm.msg_id) {
      case MSG_ID_SSDBG2_SSDBG2_INTQ_REQ:
         kal_print("SSDBG task2 status:  \n");
         sprintf(display_str, "SSDBG2 task time (2)         :   %d\n", Task_Time);
         kal_print(display_str);
         kal_print("Receive from internal queue.  \n");

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         break;

      case MSG_ID_TIMER_EXPIRY:
         kal_print("SSDBG task2 status:  \n");
         sprintf(display_str, "SSDBG2 task time (2)         :   %d\n", Task_Time);
         kal_print(display_str);
         kal_print("Receive from external queue.  \n");

         /* Check if the base timer is stopped or not */
         if (stack_is_time_out_valid(&ssdbg2_context.ssdbg2_base_timer)) {
            /* Execute event's timeout handler */
            evshed_timer_handler(ssdbg2_context.ssdbg2_event_scheduler_ptr);
         }
         /* Shoulbe be paired with stack_is_time_out_valid() */
         stack_process_time_out(&ssdbg2_context.ssdbg2_base_timer);

         break;
      case MSG_ID_SSDBG1_SSDBG2_EXTQ_REQ:
         kal_print("SSDBG task2 status:  \n");
         sprintf(display_str, "SSDBG2 task time (2)         :   %d\n", Task_Time);
         kal_print(display_str);
         kal_print("Receive from external queue.  \n");
         paraptr = (ssdbg1_localpara_struct*)current_ilm.local_para_ptr;
         peerbufptr = (ssdbg1_peerbuff_struct*)current_ilm.peer_buff_ptr;
         pduptr = (kal_uint8*)get_pdu_ptr((peer_buff_struct *)peerbufptr, &pdulength);

         /* kal_settimeout(paraptr, kal_default_timeouthandler, NULL, 500); */
         break;
      case MSG_ID_CUSTOM_SSDBG2_EXTQ_REQ:
         kal_print("SSDBG task2 status:  \n");
         sprintf(display_str, "SSDBG2 task time (2)         :   %d\n", Task_Time);
         kal_print(display_str);
         kal_print("Receive from custom task\n");
         break;
      default:
         break;
      }
      free_ilm(&current_ilm);
   }
}
#endif
void
ssdbg2_start_base_timer(void *base_timer_ptr,unsigned int time_out)
{
   stack_start_timer((stack_timer_struct *)base_timer_ptr, SSDBG2_STACK_TIMER0, time_out);
   return;
}

void
ssdbg2_stop_base_timer(void *base_timer_ptr)
{
   stack_stop_timer((stack_timer_struct *)base_timer_ptr);
   return;
}

void
ssdbg2_base_timer_timeout_hdler( void* msg_ptr )
{
   ilm_struct *send_ilm;
#if defined(DEBUG_FLC) && defined(__FLC_SOCKET_TCP__)
   kal_bool ret_status;
   kal_uint32 req_ul_sz;
   void* peerbuff_ptr;

   /* Socket Send Buffer */
   kal_print("** Socket Send Buffer **\n");
   ret_status = gprs_flc_activate_context(SPDU_DATA,	/* data type */
                                          GPRS_INVALID_SAPI,/* sapi type */
                                          GPRS_FLC_UL,   /* dir*/
                                          2);               /* context id*/

   kal_print("Allocate Socket Send Buffer\n");
   peerbuff_ptr = gprs_flc_get_peer_buff(SPDU_DATA,   /* data type */
                                         GPRS_INVALID_SAPI, /* sapi type */
                                         GPRS_FLC_UL,       /* dir */
                                         2,                 /* context id */
                                         128,               /* pdu length */
                                         0,                 /* header length */
                                         0,                 /* tailer length */
                                         NULL);             /* is pool created */

   gprs_flc_print_stats(SPDU_DATA);

   gprs_flc_grow_context_memory( SPDU_DATA,			/* data type */
			  GPRS_INVALID_SAPI,  				 			/* sapi type */
              GPRS_FLC_UL,									/* dir */
			  2,											/* context id */
              2048,											/* grow length */
              0,											/* useless */
              &req_ul_sz,									/* return grow length */
              NULL );										/* useless */

   gprs_flc_print_stats(SPDU_DATA);

   kal_print("Release Socket Send Buffer\n");
   gprs_flc_free_peer_buff(SPDU_DATA,                 /* data type */
                           GPRS_INVALID_SAPI,               /* sapi type */
                           GPRS_FLC_UL,                     /* dir */
                           2,                               /* context id */
                           peerbuff_ptr);                   /* peer buff pointer */

   gprs_flc_print_stats(SPDU_DATA);

   gprs_flc_deactivate_context(SPDU_DATA,             /* data type */
                               GPRS_INVALID_SAPI,           /* sapi type */
                               GPRS_FLC_UL,              	/* dir*/
                               2);                          /* context id*/

   /* Socket Recv Buffer */
   kal_print("** Socket Recv Buffer **\n");
   ret_status = gprs_flc_activate_context(SPDU_DATA,	/* data type */
                                          GPRS_INVALID_SAPI,/* sapi type */
                                          GPRS_FLC_DL,   	/* dir*/
                                          0);               /* context id*/

   kal_print("Allocate Socket Recv Buffer\n");
   peerbuff_ptr = gprs_flc_get_peer_buff(SPDU_DATA,   /* data type */
                                         GPRS_INVALID_SAPI, /* sapi type */
                                         GPRS_FLC_DL,       /* dir */
                                         0,                 /* context id */
                                         1528,              /* pdu length */
                                         0,                 /* header length */
                                         0,                 /* tailer length */
                                         NULL);             /* is pool created */

   gprs_flc_print_stats(SPDU_DATA);

   kal_print("Release Socket Recv Buffer\n");
   gprs_flc_free_peer_buff(SPDU_DATA,                 /* data type */
                           GPRS_INVALID_SAPI,               /* sapi type */
                           GPRS_FLC_DL,                     /* dir */
                           0,                               /* context id */
                           peerbuff_ptr);                   /* peer buff pointer */

   gprs_flc_print_stats(SPDU_DATA);

   gprs_flc_deactivate_context(SPDU_DATA,             /* data type */
                               GPRS_INVALID_SAPI,           /* sapi type */
                               GPRS_FLC_DL,              	/* dir*/
                               0);                          /* context id*/

   /* TCP Buffer */
   kal_print("** TCP Buffer **\n");
   ret_status = gprs_flc_activate_context(TPDU_DATA,		/* data type */
                                          GPRS_INVALID_SAPI,/* sapi type */
                                          GPRS_FLC_UL,   	/* dir*/
                                          0);               /* context id*/

   kal_print("Allocate TCP Buffer\n");
   peerbuff_ptr = gprs_flc_get_peer_buff(TPDU_DATA,   	/* data type */
                                         GPRS_INVALID_SAPI, /* sapi type */
                                         GPRS_FLC_UL,       /* dir */
                                         0,                 /* context id */
                                         128,               /* pdu length */
                                         0,                 /* header length */
                                         0,                 /* tailer length */
                                         NULL);             /* is pool created */

   gprs_flc_print_stats(TPDU_DATA);

   kal_print("Release TCP Buffer\n");
   gprs_flc_free_peer_buff(TPDU_DATA,                 	/* data type */
                           GPRS_INVALID_SAPI,               /* sapi type */
                           GPRS_FLC_UL,                     /* dir */
                           0,                               /* context id */
                           peerbuff_ptr);                   /* peer buff pointer */

   gprs_flc_print_stats(TPDU_DATA);

   gprs_flc_deactivate_context(TPDU_DATA,             	/* data type */
                               GPRS_INVALID_SAPI,           /* sapi type */
                               GPRS_FLC_UL,              	/* dir*/
                               0);                          /* context id*/
#endif /* DEBUG_FLC */

   ssdbg2_context.ssdbg2_event_id =
   evshed_set_event(ssdbg2_context.ssdbg2_event_scheduler_ptr,
                    (kal_timer_func_ptr)ssdbg2_base_timer_timeout_hdler,
                    NULL, KAL_TICKS_500_MSEC);

   send_ilm = allocate_ilm(MOD_SSDBG2);
   send_ilm->src_mod_id = MOD_SSDBG2;
   send_ilm->dest_mod_id = MOD_SSDBG2;
   send_ilm->msg_id = MSG_ID_SSDBG2_SSDBG2_INTQ_REQ;
   msg_send_ext_queue(send_ilm);
}
#endif /* MTK_SYSSERV_DEBUG */


