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
 *   kal_debug_common_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file has definations for Debug version of KAL that
 *   are common across different OSs.
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

#if !defined(_KAL_DEBUG_COMMON_DEFS_H)

#define _KAL_DEBUG_COMMON_DEFS_H

#ifndef DEBUG_KAL
	#error "kal_debug_common_defs.h must included for debug only"
#endif	/* ifndef DEBUG_KAL */

/*******************************************************************************
 * Macros Without Parameters
 *******************************************************************************/
#define KAL_TIMER_SCALING_FACTOR    1
#define KAL_MAX_NUM_QUEUES          50
#define KAL_BUFF_HEAD_PRINT         (kal_uint8)0xF1
#define KAL_BUFF_FOOT_PRINT         (kal_uint8)0xF2
#define KAL_BUFF_HDR_STAMP          (kal_uint32)0xF1F1F1F1
#define KAL_BUFF_FOOT_STAMP         (kal_uint32)0xF2F2F2F2
#define KAL_MAX_ALLOCATIONS         5000
#define KAL_MAX_BUFF_SIZE           ((~(kal_uint16)0)-(KAL_BUFFER_OVERHEAD + 1))
#define KAL_MAX_BUFF_HISTORY        3
#define KAL_MAX_NUM_BUFF_POOLS      40
#define KAL_TASK_NAME_SIZE          16

/*
 * Using one more than KAL_MAX_ALLOC_ID allowed for external
 * allocations
 */
#define KAL_INTERNAL_ALLOC_ID     ( KAL_MAX_ALLOC_ID + 1 )

/*******************************************************************************
 * Partial debug statistics structure definition
 *******************************************************************************/

#ifdef DEBUG_BUF

typedef enum {
   KAL_BUFF_DEALLOCATED,
   KAL_BUFF_ALLOCATED,
   KAL_BUFF_CORRUPTED
} kal_buff_state;

typedef struct kal_history_node {
   kal_buff_state                 buffer_state;
   struct kal_int_task_struct*    owner_task;
   kal_char*                      file_name;
   kal_uint32                     line;
   kal_uint32                     alloc_id;
#ifdef __ROMSA_SUPPORT__   
   kal_uint16                     size;
#else
   kal_uint32                     size;
#endif   
} kal_history_node_t;

typedef struct kal_int_buff_stats {
   kal_internal_taskid owner_task;
   kal_uint8 buffer_state;
   LCD_IP_CQUEUE( kal_history_node_t, KAL_MAX_BUFF_HISTORY ) buff_history;
#ifdef DEBUG_BUF3
   kal_uint32 ticks_alloc;
   kal_uint32 ticks_dealloc;
#endif	/* DEBUG_BUF3 */
} *kal_internal_buff_statistics, kal_buff_stat_type;

#endif /* DEBUG_BUF */

/*******************************************************************************
 * Exported Function Prototypes
 *******************************************************************************/
#ifdef DEBUG_BUF

#ifdef DEBUG_BUF2
extern void kal_debug_validate_poolid(kal_internal_poolid pool_id, kal_uint32* pool_index_p);

extern void kal_debug_update_buff_history(buff_hdr_t* buff_hdr_p,
                                          kal_buff_state buff_state,
                                          kal_uint32 size,
                                          kal_char* file,
                                          kal_uint32 line,
                                          kal_uint32 alloc_id);

extern kal_bool is_buff_over_run(void* dest_ptr, kal_uint32 size, kal_uint32 pool_index);

extern void kal_reset_pool(kal_internal_poolid pool_id);

extern void kal_debug_validate_buff_hdr(buff_hdr_t* buff_hdr);

extern kal_bool kal_debug_is_buff_footer_corrupted(kal_uint8* usr_buff,
                                                   kal_history_node_t* tail_node_p);

extern void kal_debug_get_last_history_node(void* buff_ptr, kal_history_node_t* tail_node_ptr);

#else	/* DEBUG_BUF2 */

#define is_buff_over_run(ptr, size, index)   (KAL_FALSE)

#endif /* DEBUG_BUF2 */

extern kal_bool kal_debug_get_poolindex(void* buff_ptr, kal_uint32* index_p);

#ifdef KAL_ON_NUCLEUS
extern void * kal_nu_get_buff(kal_poolid pool_id_ptr);
extern void kal_nu_free_buff(void * buff_pt);
#endif

extern kal_uint16 kal_get_buff_num(void *buff_ptr);

extern void kal_debug_validate_buff_hdr( buff_hdr_t* buff_hdr );

extern void kal_debug_validate_buff_footer(kal_uint8* usr_buff, kal_history_node_t* tail_node_p);



#endif /* DEBUG_BUF */

extern void kal_uint_2_hex_str( kal_uint32 num, kal_char* string );

extern void kal_uint_2_str( kal_uint32 num, kal_char* string );

extern kal_bool kal_debug_is_history_empty( kal_internal_poolid pool_id, void*  buff_ptr );

#if defined(DEBUG_BUF) && defined(DEBUG_MEM)
extern void kal_debug_check_over_run(void* dest_ptr, kal_uint32 size);
#endif /* defined(DEBUG_BUF) && defined(DEBUG_MEM) */

extern void kal_validate_buff_footer(void *buff_ptr, kal_uint32 buff_size );

extern void kal_take_reentrant_mutex(kal_os_mutex_type *mutex_id);

extern void kal_give_reentrant_mutex(kal_os_mutex_type *mutex_id);

/*******************************************************************************
 * Memory Management
 *******************************************************************************/
#ifdef DEBUG_MEM
extern kal_bool is_mem_over_run( void* mem_ptr, kal_uint32 size );
#endif /* DEBUG_MEM */

/*******************************************************************************
 * Declarations Of Exported Globals
 *******************************************************************************/
extern kal_buff_pool_info   pool_info_g [ KAL_MAX_NUM_BUFF_POOLS ];
extern kal_uint8            num_buff_pools_created_g;

#ifdef DEBUG_MEM
extern kal_mem_info_struct kal_mem_g[ KAL_MAX_ALLOCATIONS ];
extern kal_int32        kal_min_free_index_g;
extern kal_int32        kal_max_allocated_index_g;
#endif /* DEBUG_MEM */

extern kal_internal_taskid  kal_task_ptrs_g [ RPS_TOTAL_STACK_TASKS ];
extern kal_internal_hisrid  kal_hisr_ptrs_g [ KAL_MAX_NUM_HISRS ];

#endif /* _KAL_DEBUG_COMMON_DEFS_H */


