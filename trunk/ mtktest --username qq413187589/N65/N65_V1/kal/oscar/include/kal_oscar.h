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
 *   kal_oscar.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the type definations related to OSCAR.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__KAL_OSCAR_H__)
#define __KAL_OSCAR_H__

#ifndef KAL_ON_OSCAR
#error "Should define KAL_ON_OSCAR before include this file!"
#endif

/*************************************************************************
 * Constant definition
 *************************************************************************/
#define KAL_OSC_BUFF_OVERHEAD	sizeof(osc_struct_block_hdr)

#if defined(DEBUG_KAL) && defined(DEBUG_BUF)
#define KAL_BUFFER_OVERHEAD (KAL_BUFF_HEADER_SIZE + KAL_BUFF_FOOTER_SIZE)
#else	/* DEBUG_KAL && DEBUG_BUF */
#define KAL_BUFFER_OVERHEAD 0
#endif /* DEBUG_KAL && DEBUG_BUF */

#define KAL_MAX_ALLOC_ID 64
#define KAL_TOTAL_BUFF_OVERHEAD (KAL_OSC_BUFF_OVERHEAD + KAL_BUFFER_OVERHEAD)
#define KAL_MAX_NUM_TIMERS 500

#if defined(__CS_SERVICE__) && defined(__PS_SERVICE__)
#define KAL_MAX_EVSHED_BUFF_NUM 80
#elif defined(__CS_SERVICE__)
#define KAL_MAX_EVSHED_BUFF_NUM 40
#endif	/* defined(__CS_SERVICE__) && defined(__PS_SERVICE__) */

/*************************************************************************
 * Types used for task manager
 *************************************************************************/
#if defined(DEBUG_KAL)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
typedef struct kal_int_task_struct {
   kal_os_task_type task_id;
   kal_char *task_name;
   kal_uint32 task_index;
} *kal_internal_taskid, kal_task_type;
#endif

typedef struct kal_int_hisr_struct {
   kal_os_hisr_type hisr_id;
   kal_char *hisr_name;
} *kal_internal_hisrid, kal_hisr_type;

#else	/* defined(DEBUG_KAL) */

#if 0
/* under construction !*/
#else
typedef struct kal_int_task_struct {
   kal_os_task_type task_id;
   kal_uint32 task_index;
} *kal_internal_taskid, kal_task_type;
#endif

typedef kal_os_hisr_type *kal_internal_hisrid, kal_hisr_type;

#endif /* defined(DEBUG_KAL) */


/*************************************************************************
 * Types used by ITC
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

typedef struct kal_int_queue_statistics_struct {
   /* kal_char*     queue_name; */
#ifdef DEBUG_ITC3
   kal_uint16    max_msg_size_enqued;
#endif	/* DEBUG_ITC3 */
   kal_uint16    current_num_msgs;
   kal_uint16    max_num_msgs_enqued;
} *kal_internal_queue_statistics, kal_queue_stat_type;

typedef struct {
   kal_os_queue_type    queue_id;
   kal_uint16           max_msg_size;
   kal_internal_queue_statistics    q_stat;
} *kal_internal_msgqid, kal_queue_type;

typedef struct kal_int_mutex_statistics_struct {
   /* kal_char                      *mutex_name; */
   struct kal_int_task_struct    *owner_task;
   kal_mutex_state               mutex_state;
} *kal_internal_mutex_statistics, kal_mutex_stat_type;

typedef struct {
   kal_os_mutex_type                         mutex_id;
   kal_os_task_type                          *owner_task;
   kal_mutex_state                           mutex_state;
   struct kal_int_mutex_statistics_struct    *mutex_stat;
} *kal_internal_mutexid, kal_mutex_type;

typedef struct kal_int_sem_statistics {
   /* kal_char*            sem_name; */
   kal_uint16           current_value;
   kal_uint16           max_value;
   kal_uint16           min_value;
} *kal_internal_sem_statistics, kal_sem_stat_type;

typedef struct {
   kal_os_sem_type                           sem_id;
   kal_sem_state                             sem_state;
   struct kal_int_sem_statistics             *sem_stat;
}*kal_internal_semid, kal_sem_type;

#else	/* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

typedef struct {
   kal_os_queue_type    queue_id;
   kal_uint16           max_msg_size;
}* kal_internal_msgqid, kal_queue_type;

typedef struct {
   kal_os_mutex_type    mutex_id;
   kal_os_task_type     *owner_task;
   kal_mutex_state      mutex_state;
} *kal_internal_mutexid, kal_mutex_type;

typedef kal_os_sem_type *kal_internal_semid, kal_sem_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

typedef kal_os_eventgrp_type *kal_internal_eventgrpid, kal_eventgrp_type;


/*************************************************************************
 * Types related to timers
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_TIMER)

typedef enum {
   KAL_TIMER_CREATED,
   KAL_TIMER_SET,
   KAL_TIMER_CANCELED,
   KAL_TIMER_EXPIRED
} kal_timer_state;

typedef struct kal_int_timer_statistics_struct {
   kal_timer_state     timer_state;
   kal_char*           timer_name;
   kal_uint16          num_times_expired;
   kal_uint16          num_times_canceled;
} *kal_internal_timer_statistics, kal_timer_stat_type;

typedef struct {
   kal_os_timer_type       timer_id;
   kal_timer_func_ptr      func_ptr;
   void *                  timer_param_ptr;
   kal_uint32              set_time;
   kal_internal_timer_statistics    timer_stat;
}*kal_internal_timerid, kal_timer_type;

#else	/* defined(DEBUG_KAL) && defined(DEBUG_TIMER) */

typedef struct {
   kal_os_timer_type       timer_id;
   kal_timer_func_ptr      func_ptr;
   void *                  timer_param_ptr;
   kal_uint32              set_time;
} * kal_internal_timerid, kal_timer_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_TIMER) */


/*************************************************************************
 * Types used for buffer manager
 * NoteXXX: Below data strucutre cannot be modified.
 *          Buffer-relative ROM code will reference them.
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_BUF)

typedef struct kal_int_pool_struct {
   kal_os_pool_type        pool_id;
   kal_bool                pool_debug_mask;
   kal_uint32              buff_size;
#ifdef DEBUG_BUF2
   struct kal_int_pool_statistics_struct    *pool_stat;
   kal_mutexid             protecting_mutex;
#endif /* DEBUG_BUF2 */
} *kal_internal_poolid, kal_pool_type;

typedef struct {
   kal_uint32 hdr_stamp;
   kal_internal_taskid task_id;
   kal_internal_poolid pool_id;
   kal_uint8 usr_buff[1];
} buff_hdr_t;

#else	/* defined(DEBUG_KAL) && defined(DEBUG_BUF) */

typedef struct kal_int_pool_struct {
   kal_os_pool_type        pool_id;
} *kal_internal_poolid, kal_pool_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_BUF) */


/*************************************************************************
 * Types used for mem manager
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_MEM)

typedef struct {
   kal_bool      is_allocated;
   kal_uint32    size;
   kal_char      * alloc_file;
   kal_uint32    alloc_line;
   kal_char      * dealloc_file;
   kal_uint32    dealloc_line;
   kal_taskid    task_id;
   kal_uint32    * ptr;
} kal_mem_info_struct;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_MEM) */


/*************************************************************************
 * Exported Data Declaration
 *************************************************************************/
extern kal_char sys_info_str[128];


/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
kal_uint32 kal_milli_secs_to_ticks( kal_uint32 milli_secs );
kal_uint32 kal_secs_to_ticks ( kal_uint32 secs );

#endif //__KAL_OSCAR_H__

