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
 *   kal_debug.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file would be used as a kal header file for the compilation
 *   of any module using debug version of kal.
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

/*********************************************************************
	(C) _____ (year of first publication) Sasken communication
	Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _KAL_DEBUG_H
#define _KAL_DEBUG_H

#if defined(__MTK_TARGET__) || defined(MTK_KAL_MNT) || defined (KAL_ON_OSCAR)
/*************************************************************************
 * Type Definitions
 *************************************************************************/
struct ptr_node {
	void* ptr;
	kal_uint32 size;
	struct ptr_node* next_ptr;
};

#if defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF3)
typedef struct {
	kal_uint32 max_allocation;
	kal_uint32 current_allocation;
	kal_uint32 total_num_allocation;
} kal_alloc_struct;
#endif	/* defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF3) */

typedef struct kal_pool_statistics_struct {
	kal_uint16 num_buffs;
#ifdef __ROMSA_SUPPORT__
	kal_uint16 buff_size;
#else
	kal_uint32 buff_size;
#endif
	/* kal_uint16 total_num_allocation; */
	kal_uint16 current_allocation;
	kal_uint16 max_num_allocated;
	kal_uint16 max_size_requested;/* Maximum requested size from the pool */
#if defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF3)
	kal_alloc_struct alloc_info[LAST_MOD_ID + 1];
#endif	/* defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF3) */
} *kal_pool_statistics;

#if defined(DEBUG_KAL) && defined(DEBUG_MEM)

typedef struct {
	kal_taskid task_id;
	kal_char task_name[ KAL_TASK_NAME_SIZE ];
	kal_uint32 max_allocation;
	kal_uint32 current_allocation;
	struct ptr_node* ptr_node;
} kal_task_mem_info_struct_t;

extern kal_task_mem_info_struct_t kal_mem_info_g[ RPS_TOTAL_STACK_TASKS ];
#if 0
/* under construction !*/
#endif
extern kal_bool                   kal_mem_over_run_check_g;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_MEM) */

#if defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF2)

extern kal_bool                  kal_buff_over_run_check_g;

typedef struct kal_ext_buff_stats {
	kal_buff_state  buffer_state;
	kal_char*       task_name;
} *kal_ext_buff_statistics, kal_ext_buff_stat_type;

typedef struct kal_buff_stats {
	kal_uint8   unused;
}* kal_buff_statistics;

typedef struct kal_int_pool_statistics_struct {
	struct kal_pool_statistics_struct   pool_info;
	struct kal_int_buff_stats*          buff_stat;
} *kal_internal_pool_statistics, kal_pool_stat_type;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF2) */

typedef void(*kal_print_string_func_ptr)(kal_char*);

typedef enum {
	KAL_DEBUG_DISABLE,
	KAL_DEBUG_ENABLE
} kal_debug_state;

typedef enum {
	KAL_BUFFMGR     = 0x1,
	KAL_TIMERMGR    = 0x2,
	KAL_TASKMGR     = 0x4,
	KAL_ITC         = 0x8
} kal_module;

#if defined(DEBUG_KAL) && defined(DEBUG_TASK)
typedef struct kal_task_statistics_struct {
	kal_uint8   unused;
} *kal_task_statistics;
#endif /* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

typedef struct kal_queue_statistics_struct {
	kal_uint8   unused;
}* kal_queue_statistics;

typedef struct kal_mutex_statistics_struct {
	kal_uint8   unused;
}* kal_mutex_statistics;

typedef struct kal_sem_statistics_struct {
	kal_uint8   unused;
}* kal_sem_statistics;

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

#if defined(DEBUG_TIMER) && defined(DEBUG_KAL)
typedef struct kal_timer_statistics_struct {
	kal_uint8   unused;
}* kal_timer_statistics;
#endif /* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

/*************************************************************************
 * Task Management
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_TASK)

#if 0 /* XXX!!! - Not Implemented yet */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else	/* if 0 */

#define kal_get_task_statistics( task_id, stat_ptr ) {}
#define kal_reset_task_statistics(  task_id ) {}

#endif	/* if 0 */

#else	/* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

#define kal_get_task_statistics( task_id, stat_ptr ) {}
#define kal_reset_task_statistics(  task_id ) {}

#endif /* defined(DEBUG_KAL) && defined(DEBUG_TASK) */

/*************************************************************************
 * ITC Management
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_ITC)

#define kal_get_q_statistics(queue_id, stat_ptr ) \
      kal_debug_get_q_statistics(queue_id, stat_ptr )

#define kal_reset_q_statistics(  queue_id )\
      kal_debug_reset_q_statistics(  queue_id )

void kal_debug_get_q_statistics( kal_msgqid  queue_id, kal_queue_statistics* stat_ptr );
void kal_debug_reset_q_statistics( kal_msgqid    queue_id );

#else	/* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

#define kal_get_q_statistics(queue_id, stat_ptr ) {}
#define kal_reset_q_statistics(  queue_id ) {}

#endif /* defined(DEBUG_KAL) && defined(DEBUG_ITC) */

/*************************************************************************
 * Buffer Management
 *************************************************************************/
#if defined(DEBUG_KAL) && defined(DEBUG_BUF)
#ifdef DEBUG_BUF2

void kal_debug_get_all_buff_statistics(kal_poolid pool_id, kal_ext_buff_statistics buff_stat_ptr);
void kal_debug_reset_pool_statistics(kal_poolid pool_id);
void kal_debug_get_buffer_statistics(void* buffer_ptr, kal_buff_statistics* stat_ptr);
void kal_debug_reset_buffer_statistics(void* buffer_ptr);

#define KAL_GET_POOL_STATISTICS_ADDR( pool_id ) \
	(kal_pool_statistics) ((kal_internal_poolid) pool_id)->pool_stat

#define kal_get_all_buffer_statistics( pool_id, buff_stat_ptr) ;\
         kal_debug_get_all_buff_statistics( pool_id , buff_stat_ptr);

#define kal_reset_pool_statistics(pool_id) \
         kal_debug_reset_pool_statistics(pool_id)

#define kal_get_buffer_statistics( buffer_ptr, stat_ptr )\
         kal_debug_get_buffer_statistics( buffer_ptr, stat_ptr )

#define kal_reset_buffer_statistics( buffer_ptr )\
         kal_debug_reset_buffer_statistics( buffer_ptr )

#else	/* DEBUG_BUF2 */

/* **NULL**
 * trap error if developer invoke any function which is DEBUG_BUF2 only
 */

#endif /* DEBUG_BUF2 */

void kal_debug_is_valid_buffer(void* buff_ptr, kal_bool* status_ptr);

#else	/* defined(DEBUG_KAL) && defined(DEBUG_BUF) */

/* #define KAL_GET_POOL_STATISTICS_ADDR( pool_id )
   #define kal_get_all_buffer_statistics(  pool_id, buff_stat_ptr) ; {}
   #define kal_reset_pool_statistics(  pool_id) {}
 *            #error "Not Supported"
 * trap error if developer try to get pool_statistic 
 */
#define kal_get_buffer_statistics( buffer_ptr, stat_ptr ) {}
#define kal_reset_buffer_statistics( buffer_ptr ) {}

#endif /* defined(DEBUG_KAL) && defined(DEBUG_BUF) */

/*************************************************************************
 * Memory Management
  *************************************************************************/


/*************************************************************************
 * Timer Management
 *************************************************************************/
#if defined(DEBUG_TIMER) && defined(DEBUG_KAL)

void kal_debug_get_timer_statistics(kal_timerid timer_id, kal_timer_statistics* stat_ptr);
void kal_debug_reset_timer_statistics(kal_timerid timer_id );

#define kal_get_timer_statistics(  timer_id, stat_ptr ) ;\
      kal_debug_get_timer_statistics(  timer_id, stat_ptr ) ;

#define kal_reset_timer_statistics(timer_id )\
      kal_debug_reset_timer_statistics(timer_id )

#else	/* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

#define kal_get_timer_statistics(  timer_id, stat_ptr ) ; {}
#define kal_reset_timer_statistics(timer_id ) {}

#endif /* defined(DEBUG_TIMER) && defined(DEBUG_KAL) */

/*************************************************************************
 * Error Handling and Debug Management
 *************************************************************************/
#if defined(DEBUG_KAL)

#ifdef DEBUG_LEAK
void kal_settimeout(void* addr, kal_timer_func_ptr handler_func_ptr,
						  void* handler_param_ptr, kal_uint32 delay);
void kal_untimeout(void* addr);
void kal_default_timeouthandler(void*);
#endif /* DEBUG_LEAK */

void kal_debug_register_print_string_function (kal_print_string_func_ptr func_ptr);
void kal_debug_print(kal_char* string_to_be_printed);
void kal_debug_print_int(kal_int32 int_to_be_printed);
void kal_debug_print_uint(kal_uint32 int_to_be_printed);
void kal_debug_print_uint_in_hex(kal_uint32 int_to_be_printed);
void kal_debug_enable_debug( kal_module debug_code, kal_debug_state    flag);
void kal_debug_abort( void );
void kal_debug_reset( void );

#define kal_register_print_string_function( to_be_registered_func)\
      kal_debug_register_print_string_function( to_be_registered_func)

#define kal_print_int( int_to_be_printed )\
      kal_debug_print_int( int_to_be_printed )

#define kal_print_uint( int_to_be_printed )\
      kal_debug_print_uint( int_to_be_printed )

#define kal_print_uint_in_hex( int_to_be_printed )\
      kal_debug_print_uint_in_hex( int_to_be_printed )

#define kal_enable_debug( debug_code, flag )\
      kal_debug_enable_debug( debug_code, flag )

#define kal_abort() kal_debug_abort()

#define kal_reset() kal_debug_reset()

#else	/* defined(DEBUG_KAL) */

#define kal_register_print_string_function( to_be_registered_func) {}
#define kal_print_int( int_to_be_printed )  {}
#define kal_print_uint( int_to_be_printed )  {}
#define kal_print_uint_in_hex( int_to_be_printed )  {}
#define kal_enable_debug( debug_code, flag ) {}
#define kal_abort() {}
#define kal_reset() {}

#endif	/* defined(DEBUG_KAL) */

#endif /* defined(__MTK_TARGET__) || defined(MTK_KAL_MNT) || defined (KAL_ON_OSCAR) */

#endif /* _KAL_DEBUG_H */

