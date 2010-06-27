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
 *   event_shed.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file for Event Scheduler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _EVENT_SHED_H
#define _EVENT_SHED_H


/*************************************************************************
 * Type Definitions
 *************************************************************************/
typedef void (*start_timer_fptr)(void *, unsigned int);
typedef void (*stop_timer_fptr)(void *);

typedef struct event_scheduler {
   /* event's double-linked list */
   lcd_dll        *dll;

   /* event's expired dll list split in evshed_timer_handler() */
   lcd_dll_node   *expired_dllhead;

   /* scheduler's reference time base */
   kal_uint32     t_ref_ticks;

   /* scheduler's reference suspend time base for suspend operation */
   kal_uint32     t_susp_ticks;

   /* scheduler's suspend flag */
   kal_bool       is_suspend;

   /* scheduler's timer's set time */
   kal_uint32     t_set_time;

   void           *timer_id;
   void           (*start_timer)(void *, unsigned int);
   void           (*stop_timer)(void *);
   unsigned int   fuzz;

   /* event's storage allocation/deallocation handler */
   malloc_fp_t    alloc_fn_p;
   free_fp_t      free_fn_p;

#ifdef MTK_REMOVED_API
   kal_bool       is_ext_mem;
#endif /* MTK_REMOVED_API */
} event_scheduler;

typedef struct event {
   kal_timer_func_ptr event_hf;
   void *event_hf_param;
   kal_uint32 abs_time;
	event_scheduler *owneres;	/* a pointer points back to the event's onwer(event scheduler) */
} event;

typedef lcd_dll_node *eventid;


/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
/*
 * Important:
 *  Current implementation max_delay_ticks only support 0, and non-0.
 */
extern event_scheduler *new_evshed(void *timer_id,
                                   void (*start_timer)(void *, unsigned int),
                                   void (*stop_timer)(void *),
                                   kal_uint32 fuzz,
                                   malloc_fp_t alloc_fn_p,
                                   free_fp_t free_fn_p,
                                   kal_uint8 max_delay_ticks);

/*
 * Important
 *  System will allocate memory for event id, and return to caller.
 *  If caller need to save event id, please be careful to reset when
 *  cancel the event or the event expired.
 */
extern eventid evshed_set_event(event_scheduler *es,
                                kal_timer_func_ptr event_hf,
                                void *event_hf_param,
                                kal_uint32 elapse_time);

/*
 * Important
 *  System would reset *eid to NULL before return, however, caller
 *  should pay attention to saved event id.
 */
extern kal_int32 evshed_cancel_event(event_scheduler *es, eventid *eid);

extern kal_uint32 evshed_get_rem_time(event_scheduler *es, eventid eid);

extern void evshed_suspend_all_events(event_scheduler *es);

extern void evshed_resume_all_events(event_scheduler *es);

extern void evshed_delete_all_events(event_scheduler *es);

//extern void delete_evshed(event_scheduler *es);

/*
 * NoteXXX:
 *  In evshed_timer_handler(), system would execute event regisited timeout callback function.
 *  Caller should reset saved event id in regisited timeout callback function,
 *  or cause potential bug to cancel wrong timer event.
 */
extern void evshed_timer_handler(event_scheduler *es);

extern kal_bool evshed_events_pending(event_scheduler *es);

#ifdef MTK_REMOVED_API

extern event_scheduler *new_evshed_with_mem(void *timer_id,
                                            void (*start_timer)(void *, unsigned int),
                                            void (*stop_timer)(void *),
                                            kal_uint32 fuzz,
                                            malloc_fp_t alloc_fn_p,
                                            free_fp_t free_fn_p,
                                            void *mem_ptr);

extern eventid evshed_set_event_with_mem(event_scheduler *es,
                                         kal_timer_func_ptr event_hf,
                                         void *event_hf_param,
                                         kal_uint32 elapse_time,
                                         void *mem_ptr);

extern kal_uint32 new_evshed_mem_size(void);

extern kal_uint32 new_event_mem_size(void);

#endif /* MTK_REMOVED_API */

#endif /* _EVENT_SHED_H */


