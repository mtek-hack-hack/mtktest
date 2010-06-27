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
 *   stack_timer.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This module has prototypes of the functions and a structure
 *   defined to support concurrency issues related to a timer.
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
 * removed!
 * removed!
 * removed!
 *
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

#ifndef _STACK_TIMER_H
#define _STACK_TIMER_H


/*************************************************************************
 * Type Definitions
 *************************************************************************/
typedef enum {
	STACK_TIMER_INITIALIZED,
	STACK_TIMER_NOT_RUNNING = STACK_TIMER_INITIALIZED,
	STACK_TIMER_RUNNING,
	STACK_TIMER_NOT_TIMED_OUT = STACK_TIMER_RUNNING,		/* Backward compatiable */
	STACK_TIMER_EXPIRED,
	STACK_TIMER_TIMED_OUT = STACK_TIMER_EXPIRED,				/* Backward compatiable */
	STACK_TIMER_STOPPED
} stack_timer_status_type;

typedef void  *stack_timer_msg_ptr;
typedef void (*stack_msg_post_fptr)(stack_timer_msg_ptr);

typedef struct stack_timer_struct_t {
	module_type             dest_mod_id;
	kal_timerid             kal_timer_id;
	kal_uint16              timer_indx;
	stack_timer_status_type timer_status;
	kal_uint8               invalid_time_out_count;
#if defined(KAL_ON_OSCAR) || defined(MTK_KAL_MNT)
   kal_uint8               ut_not_send_msg;
#endif
} stack_timer_struct;


/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
extern void stack_init_timer(stack_timer_struct *stack_timer, kal_char *timer_name, module_type module_id);

extern void stack_start_timer(stack_timer_struct *stack_timer, kal_uint16 timer_indx, kal_uint32 init_time);

extern stack_timer_status_type stack_stop_timer(stack_timer_struct *stack_timer);

extern stack_timer_status_type stack_timer_status(stack_timer_struct *stack_timer, kal_uint32 *time_remaining);

extern kal_bool stack_is_time_out_valid(stack_timer_struct *stack_timer);

extern void stack_process_time_out(stack_timer_struct *stack_timer);

extern kal_uint8 stack_time_out_messages_in_queue(stack_timer_struct *stack_timer);

//extern void stack_deinit_timer(stack_timer_struct *stack_timer);

/*************************************************************************
 * Exported Data
 *************************************************************************/
#if defined(KAL_ON_OSCAR) || defined(MTK_KAL_MNT)
extern kal_uint8 ut_monitor_mod[];
extern kal_uint8 ut_send_msg;

typedef struct
{
    kal_uint8     ref_count;
    kal_uint16    msg_len;
    kal_uint32    init_time;
   module_type src_module;
   kal_uint16  timer_id;
} stack_sim_timer_start_struct, stack_sim_timer_stop_struct, stack_sim_timer_expiry_struct;
#endif

#endif /* _STACK_TIMER_H */


