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
 *	osc_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for OSCAR (Operating System Call Adapter) internal use only
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

#ifndef __OSC_INTERNAL_H__
#define __OSC_INTERNAL_H__

/* INCLUDES ***********************************************************************/

#include <conio.h> //for debug to get key only

/* MACROS *************************************************************************/

#define  OSC_CONST_MAX_TIMEOUT   4294967295   //fit check U32

//extend flag for all structure
//#define  OSC_EXT_FLAG_MALLOC_STRUCT 0x00000001
#define  OSC_EXT_FLAG_MALLOC_POOL   0x00000002
#define  OSC_EXT_FLAG_MALLOC_QUEUE  0x00000004

//for console processing and error return
#define  OSC_ERR(x, y)           osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_NULL, (void *)0, (void *)NULL)
#define  OSC_ERR_D(x, y, z)      osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_D, (void *)z, (void *)NULL)
#define  OSC_ERR_X(x, y, z)      osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_X, (void *)z, (void *)NULL)
#define  OSC_ERR_S(x, y, z)      osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_S, (void *)0, (void *)z)
#define  OSC_ERR_DD(x, y, z, w)  osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_DD, (void *)z, (void *)w)
#define  OSC_ERR_XX(x, y, z, w)  osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_XX, (void *)z, (void *)w)
#define  OSC_ERR_SD(x, y, z, w)  osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_SD, (void *)z, (void *)w)
#define  OSC_ERR_NOFATAL(x, y)   osc_show_error(__FILE__, __LINE__, x, y, OSC_PRINT_NOFATAL, (void *)0, (void *)NULL)

#ifdef _OSC_DEBUG_
#define  OSC_PRINT               osc_platform_print_msg
#else
#define  OSC_PRINT
#endif //_OSC_DEBUG_

#ifdef _OSC_DEBUG_ALL_
#ifndef  OSC_PRINT
#define  OSC_PRINT               osc_platform_print_msg
#endif //OSC_PRINT
#define  OSC_DEBUG_PRINT         osc_platform_print_msg
#define  OSC_DEBUG_KEY(x)        {OSC_PRINT("%d\n", x); _getch();}
#else
#ifndef  OSC_PRINT
#define  OSC_PRINT
#endif //OSC_PRINT
#define  OSC_DEBUG_PRINT
#define  OSC_DEBUG_KEY
#endif //_OSC_DEBUG_ALL_

/* ENUM ***************************************************************************/

//flag for OSC_PRINT
typedef enum
{
   OSC_PRINT_NULL = 0,
   OSC_PRINT_D,
   OSC_PRINT_S,
   OSC_PRINT_X,
   OSC_PRINT_DD,
   OSC_PRINT_XX,
   OSC_PRINT_SD,
   OSC_PRINT_NOFATAL
} osc_enum_print_type;

//flag for dd_list
typedef enum
{
   OSC_DD_PRIORITY = 1,
   OSC_DD_TIMEOUT,
   OSC_DD_CHECK_REGULAR_END = 10,
   OSC_DD_APPEND,
   OSC_DD_INSERT_FIRST,
   OSC_DD_CHECK_END
} osc_enum_dd_flag;

/* STRUCTURE **********************************************************************/
typedef struct _osc_struct_ext_timer
{
   osc_type_void_ptr info;
   osc_type_u32      malloc_tag;
}  osc_struct_ext_timer;

/* GLOBL DATA EXTERN **************************************************************/

//osc_main.c -----------------------------------------------------------------------
extern osc_struct_thread   g_osc_Sthread_main;

//osc_thread.c ---------------------------------------------------------------------
extern osc_struct_dd_hdr   g_osc_Uthread_ready_list;
extern osc_struct_dd_hdr   g_osc_Uthread_waiting_list;
extern osc_struct_thread   *g_osc_Uthread_current;
extern osc_type_u32        g_osc_system_initialized;
extern osc_type_u32        g_thread_preemption;

//osc_system.c ---------------------------------------------------------------------
extern osc_struct_thread   g_osc_Sthread_tickhdl;
extern osc_struct_thread   g_osc_Sthread_isrhdl;
extern osc_type_u32        g_osc_system_tick;
extern osc_type_u32        g_osc_tick_unit;
extern osc_type_u32        g_osc_interrupt_record[];
extern osc_type_func_ptr   g_osc_interrupt_handle[];

//osc_semaphore.c ------------------------------------------------------------------
extern osc_struct_sema     g_osc_sema_system_lock;
extern osc_struct_dd_hdr   g_osc_sema_lock_list;
extern osc_struct_sema     g_osc_sema_schedule_lock;

//osc_event.c ------------------------------------------------------------------
extern osc_struct_dd_hdr   g_osc_event_list;

//osc_queue.c ------------------------------------------------------------------
extern osc_struct_dd_hdr   g_osc_queue_list;

//osc_timer.c ------------------------------------------------------------------
extern osc_struct_dd_hdr   g_osc_active_timer_list;

//osc_buffer.c ------------------------------------------------------------------
extern osc_struct_dd_hdr   g_osc_buff_pool_list;

//osc_utility.c ------------------------------------------------------------------
extern osc_struct_sema     g_osc_sema_list_lock;

/* FUNCTION EXTERN ****************************************************************/

//windows --------------------------------------------------------------------------
#if 0
#ifdef __OSCAR_ON_WIN32__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

//osc_utility.c --------------------------------------------------------------------
extern osc_type_s32        osc_show_error (
                              osc_type_u8          *filename, 
                              osc_type_s32         fileline,
                              osc_type_u8          *err_caller, 
                              osc_type_s32         err_code,
                              osc_enum_print_type  print_type,
                              void                 *err_value1,
                              void                 *err_value2 );

extern void osc_dd_list_pool_init (void);

extern osc_type_s32        osc_dd_list_add (
                              osc_struct_dd_hdr    *list, 
                              void                 *candidate,
                              osc_enum_dd_flag     dd_type );

extern osc_type_s32        osc_dd_list_del ( 
                              osc_struct_dd_hdr    *list,  
                              void                 *candidate,
                              osc_enum_bool        raise_error );

extern osc_type_s32        osc_dd_list_free ( 
                              osc_struct_dd_hdr    *list, 
                              osc_enum_bool        free_this );

//osc_platform.c -------------------------------------------------------------------
extern osc_type_s32        osc_platform_main ( void );

extern osc_type_s32        osc_platform_thread_create ( osc_struct_thread *new_thread );

extern osc_type_s32        osc_platform_thread_delete ( 
                              osc_struct_thread *handle, 
                              osc_enum_bool suspend );

extern osc_type_s32        osc_platform_thread_suspend ( 
                              osc_struct_thread *thread, 
                              osc_type_u32      timeout,
                              osc_enum_bool     check_lock );

extern osc_type_s32        osc_platform_thread_resume ( osc_struct_thread *thread );

extern osc_type_s32        osc_platform_thread_alive ( osc_struct_thread *thread );

extern osc_type_s32        osc_platform_create_lock ( osc_struct_sema *lock );

extern osc_type_s32        osc_platform_lock (                                  
                              osc_struct_sema   *lock, 
                              osc_type_u32      timeout,
                              osc_struct_thread *thread );

extern osc_type_s32        osc_platform_unlock ( 
                              osc_struct_sema   *lock, 
                              osc_struct_thread *thread );

extern osc_type_s32        osc_platform_sema_delete (osc_struct_sema *sema);

extern void                osc_platform_check_caller ( void );

// Improve timer accuracy
extern osc_type_s32			osc_platform_timer_init ( void );

extern osc_type_s32			osc_platform_timer_waitfor_tick_event ( void );

//osc_system.c ---------------------------------------------------------------------
extern OSC_MACRO_STD_CALL  osc_tick_handler ( void * argv);

extern OSC_MACRO_STD_CALL  osc_isr_handler ( void * argv );

extern osc_type_s32        osc_system_lock ( osc_struct_thread *thread );

extern osc_type_s32        osc_system_unlock ( osc_struct_thread *thread );

extern void                osc_system_resource_penalty ( 
                              osc_struct_thread *thread,
                              osc_enum_state    new_state );

extern void                osc_system_fatal_error ( void );

#endif //__OSC_INTERNAL_H__
