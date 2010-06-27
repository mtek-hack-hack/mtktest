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
 *	osc_platform.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for OSCAR (Operating System Call Adapter) platform dependent
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __OSC_FUNC_H__
#define __OSC_FUNC_H__

/* INCLUDES ***********************************************************************/

#ifndef __OSC_TYPE_H__
#error "Should inlucde osc_type.h first!"
#endif //__OSC_TYPE_H__

/* MACROS *************************************************************************/

#define  OSC_Print_Msg  osc_platform_print_msg

/* GLOBAL DATA DECLARATION ********************************************************/

extern osc_struct_dd_hdr g_osc_timer_list;

extern osc_type_u32      g_osc_system_tick;

/* PUBLIC FUNCTION DECLARATION ****************************************************/

extern osc_type_s32        osc_platform_print_msg ( const char *format, ... );

extern void                OSC_Register_ISR ( 
                                       osc_enum_isr_src  src_idx, 
                                       osc_type_func_ptr isr_func );

extern void                OSC_Activate_ISR ( osc_enum_isr_src isr_idx );

extern void                OSC_Sys_Schedule_Enable ( osc_type_u32 bEnable);

extern osc_type_s32				 OSC_Sys_if_lisr (void);

/* ---------------------------------------------------
Thread API
----------------------------------------------------*/
extern osc_type_s32 OSC_Thread_Create (
         osc_type_u8          *name,
         osc_type_u32         *stack_addr,
         osc_enum_state       state_init,
         osc_type_u32         priority,
         osc_type_u32         time_slice,
         osc_type_u32         stack_size,
         osc_type_func_ptr    entry_func,
         osc_type_void_ptr    entry_param,
         osc_type_void_ptr    *thread_return );

extern osc_type_s32 OSC_Thread_Delete (
         osc_struct_thread    *thread );

extern osc_type_s32 OSC_Thread_Suspend (
         osc_struct_thread    *thread,
         osc_type_u32         timeout );

extern osc_type_s32 OSC_Thread_Resume (
         osc_struct_thread    *thread );

extern osc_type_s32 OSC_Thread_Config (
         osc_struct_thread    *thread,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u32         priority,
         osc_type_u32         time_slice,
         osc_type_u32         time_left );

extern osc_type_s32 OSC_Thread_Query (
         osc_struct_thread    *thread,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *state,
         osc_type_u32         *priority,
         osc_type_u32         *time_slice,
         osc_type_u32         *time_left,
         osc_type_u32         *stack_size,
         osc_type_u32         *stack_addr,
         osc_type_u32         *stack_ptr );

extern osc_type_s32 OSC_Thread_Current (
         osc_type_void_ptr    *thread );

/* ---------------------------------------------------
Timer API
----------------------------------------------------*/
extern osc_type_s32 OSC_Timer_Create (
         osc_type_u8          *name,
         osc_enum_state       state_init,
         osc_type_u32         time_default,
         osc_type_u32         time_periodic,
         osc_type_func_ptr    expiry_func,
         osc_type_void_ptr    expiry_param,
         osc_type_void_ptr    *timer_return );

extern osc_type_s32 OSC_Timer_Delete (
         osc_struct_timer     *timer );

extern osc_type_s32 OSC_Timer_Config (
         osc_struct_timer     *timer,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u32         state,
         osc_type_u32         time_default,
         osc_type_u32         time_periodic,
         osc_type_func_ptr    expiry_func,
         osc_type_void_ptr    expiry_param );


extern osc_type_s32 OSC_Timer_Query (
         osc_struct_timer     *timer,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *state,
         osc_type_u32         *time_default,
         osc_type_u32         *time_periodic,
         osc_type_u32         *time_left,
         osc_struct_dd_hdr    *waiting_list );

extern osc_type_s32 OSC_Get_Current_Tick (
         osc_type_u32         *current_tick );

extern osc_type_s32 OSC_Adjust_Tick_Unit (
         osc_type_u32         ms_unit );

extern osc_type_s32 OSC_Adjust_Tick_Time (
         osc_type_s32         delta );

/* ---------------------------------------------------
Semaphore API
----------------------------------------------------*/
extern osc_type_s32 OSC_Semaphore_Create (
         osc_type_u8          *name,
         osc_type_u32         count,
         osc_type_void_ptr    *sema_return );

extern osc_type_s32 OSC_Semaphore_Delete (
         osc_struct_sema      *sema );

extern osc_type_s32 OSC_Semaphore_Take (
         osc_struct_sema      *sema,
         osc_type_u32         timeout);

extern osc_type_s32 OSC_Semaphore_Give (
         osc_struct_sema      *sema );

extern osc_type_s32 OSC_Semaphore_Config (
         osc_struct_sema      *sema,
         osc_type_u32         flag,
         osc_type_void_ptr    value );

extern osc_type_s32 OSC_Semaphore_Query (
         osc_struct_sema      *sema,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *count_num,
         osc_type_u32         *count_left,
         osc_struct_dd_hdr    *owner_list,
         osc_struct_dd_hdr    *waiting_list );

/* ---------------------------------------------------
Queue API
----------------------------------------------------*/
extern osc_type_s32 OSC_Queue_Create (
         osc_type_u8          *name,
         osc_type_u32         *queue_addr,
         osc_type_u32         queue_size,
         osc_type_u32         msg_size,
         osc_type_void_ptr    *queue_return );

extern osc_type_s32 OSC_Queue_Delete (
         osc_struct_queue     *queue );

extern osc_type_s32 OSC_Queue_Write (
         osc_struct_queue     *queue,
         osc_type_u32         msg_size,
         osc_type_void_ptr    msg_buff,
         osc_type_u32         action );

extern osc_type_s32 OSC_Queue_Read (
         osc_struct_queue     *queue,
         osc_enum_bool        need_wait,
         osc_type_void_ptr    msg_buff, 
         osc_type_u32         *return_size );

extern osc_type_s32 OSC_Queue_Config (
         osc_struct_queue     *pool,
         osc_type_u32         flag,
         osc_type_void_ptr    value );

extern osc_type_s32 OSC_Queue_Query (
         osc_struct_queue     *queue,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *queue_size,
         osc_type_u32         *queue_addr,
         osc_type_u32         *msg_size,
         osc_type_u32         *msg_num_total,
         osc_struct_dd_hdr    *msg_free_list,
         osc_struct_dd_hdr    *msg_used_list,
         osc_struct_dd_hdr    *waiting_list );

/* ---------------------------------------------------
Event API
----------------------------------------------------*/
extern osc_type_s32 OSC_Event_Create (
         osc_type_u8          *name,
         osc_type_void_ptr    *event_return );

extern osc_type_s32 OSC_Event_Delete (
         osc_struct_event     *event );

extern osc_type_s32 OSC_Event_Write (
         osc_struct_event     *event,
         osc_type_u32         event_flag,
         osc_type_u32         action );

extern osc_type_s32 OSC_Event_Read (
         osc_struct_event     *event,
         osc_enum_bool        need_suspend,
         osc_type_u32         event_flag,
         osc_type_u32         action,
         osc_type_u32         *event_flag_actual );

extern osc_type_s32 OSC_Event_Config (
         osc_struct_event     *event,
         osc_type_u32         flag,
         osc_type_void_ptr    value );

extern osc_type_s32 OSC_Event_Query (
         osc_struct_event     *event,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *event_flag,
         osc_struct_dd_hdr    *waiting_list );

/* ---------------------------------------------------
Buffer API
----------------------------------------------------*/
extern osc_type_s32 OSC_Buffer_Create (
         osc_type_u8          *name,
         osc_type_u32         *pool_addr,
         osc_type_u32         pool_size,
         osc_type_u32         block_size,
         osc_type_void_ptr    *return_pool );

extern osc_type_s32 OSC_Buffer_Delete (
         osc_struct_buffer    *pool );

extern osc_type_s32 OSC_Buffer_Alloc (
         osc_struct_buffer    *pool,
         osc_type_void_ptr    *block_addr );

extern osc_type_s32 OSC_Buffer_Free (
         osc_type_void_ptr    block_addr );

extern osc_type_s32 OSC_Buffer_Config (
         osc_struct_buffer    *pool,
         osc_type_u32         flag,
         osc_type_void_ptr    value );

extern osc_type_s32 OSC_Buffer_Query (
         osc_struct_buffer    *pool,
         osc_type_u32         flag,
         osc_type_void_ptr    value,
         osc_type_u8          *name,
         osc_type_u32         *pool_size,
         osc_type_u32         *pool_addr,
         osc_type_u32         *block_size,
         osc_type_u32         *block_num_total,
         osc_struct_dd_hdr    *block_free_list, 
         osc_struct_dd_hdr    *block_used_list );

#endif //__OSC_FUNC_H__
