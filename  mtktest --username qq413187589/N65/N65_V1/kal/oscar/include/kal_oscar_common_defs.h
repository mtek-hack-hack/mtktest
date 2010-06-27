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
 *   kal_oscar_common_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   It includes the definations that are common to target and
 *   debug version of KAL on OSCAR
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

#ifndef __KAL_OSCAR_COMMON_DEFS_H__
#define __KAL_OSCAR_COMMON_DEFS_H__

/*************************************************************************
 * Constant definition
 *************************************************************************/
/* Following defines are internal to the KAL */
   #define KAL_MAX_TICKS                  (2715648)   /* 2048 * 26 * 51 */
   #define KAL_SIM_MSECS_PER_TICK      OSC_CONST_1_TICK
   #define KAL_TICKS_10_MSEC           (10/KAL_SIM_MSECS_PER_TICK)   /* 10 msec */
   #define KAL_TICKS_50_MSEC           (50/KAL_SIM_MSECS_PER_TICK)   /* 50 msec */
   #define KAL_TICKS_100_MSEC          (100/KAL_SIM_MSECS_PER_TICK)  /* 100 msec */
   #define KAL_TICKS_500_MSEC          (500/KAL_SIM_MSECS_PER_TICK)  /* 500 msec */
   #define KAL_TICKS_1_SEC             (1000/KAL_SIM_MSECS_PER_TICK) /* 1 sec */
   #define KAL_TICKS_5_SEC             (5000/KAL_SIM_MSECS_PER_TICK) /* 5 sec */
   #define KAL_TICKS_30_SEC            (30000/KAL_SIM_MSECS_PER_TICK)/* 30 sec */
   #define KAL_TICKS_1_MIN             (60000/KAL_SIM_MSECS_PER_TICK)/* 1 min */

#define ALIGNED_TIMER_ID 0xcbcbcbcb
#define UNALIGNED_TIMER_ID 0xbcbcbcbc
#define ALIGNED_TIMER_MAX_DELAY 255


/*************************************************************************
 * Type Definitions
 *************************************************************************/
/* Genenral types that are used by KAL */
typedef osc_struct_thread  kal_os_task_type;
typedef osc_struct_thread  kal_os_hisr_type;
typedef osc_struct_queue   kal_os_queue_type;
typedef osc_struct_sema    kal_os_mutex_type;
typedef osc_struct_sema    kal_os_sem_type;
typedef osc_struct_event   kal_os_eventgrp_type;
typedef osc_struct_timer   kal_os_timer_type;
typedef osc_struct_buffer  kal_os_pool_type;

typedef osc_type_func_ptr kal_nu_task_func_ptr;
typedef osc_type_func_ptr kal_nu_hisr_func_ptr;
typedef osc_type_func_ptr kal_nu_timer_func_ptr;

typedef struct {
   struct kal_int_pool_struct*  pool_id;
   void *                       start_address;
   void *                       end_address;
} kal_buff_pool_info;

/*************************************************************************
 * Macros With Parameters
 *************************************************************************/

   #define KAL_INIT_MEM_PROTECT(pool_id) { \
      pool_id->protecting_mutex = kal_create_mutex("Protecting mutex"); \
   }

   #define KAL_BEGIN_MEM_PROTECT(pool_id) { \
      kal_take_mutex(pool_id->protecting_mutex); \
   }

   #define KAL_END_MEM_PROTECT(pool_id) { \
      kal_give_mutex(pool_id->protecting_mutex); \
   }
#endif // __KAL_OSCAR_COMMON_DEFS_H__ 
