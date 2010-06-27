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
 *   kal_common_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *
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

#ifndef _KAL_COMMON_DEFS_H
#define _KAL_COMMON_DEFS_H

/*************************************************************************
 * Constant Definition
 *************************************************************************/
#define KAL_MAX_NUM_HISRS           20

/*************************************************************************
 * Type Definitions
 *************************************************************************/
typedef enum {
    KAL_NO_WAIT,
    KAL_INFINITE_WAIT
} kal_wait_mode;

typedef enum {
    KAL_SUCCESS,
    KAL_ERROR,
    KAL_Q_FULL,
    KAL_Q_EMPTY,
    KAL_SEM_NOT_AVAILABLE,
    KAL_WOULD_BLOCK,
    KAL_MESSAGE_TOO_BIG,
    KAL_INVALID_ID,
    KAL_NOT_INITIALIZED,
    KAL_INVALID_LENGHT,
    KAL_NULL_ADDRESS,
    KAL_NOT_RECEIVE,
    KAL_NOT_SEND,
    KAL_MEMORY_NOT_VALID,
    KAL_NOT_PRESENT,
    KAL_MEMORY_NOT_RELEASE
} kal_status;

typedef enum {
    KAL_SEM_GIVEN,
    KAL_SEM_TAKEN
} kal_sem_state;

typedef enum {
    KAL_MUTEX_GIVEN,
    KAL_MUTEX_TAKEN
} kal_mutex_state;

typedef enum {
    /* General KAL Error */
    KAL_ERROR_KAL_INTERNAL_FAIL                     = 0,

    KAL_ERROR_KAL_SUB_ERROR_CODE1                   = 1,
    KAL_ERROR_KAL_SUB_ERROR_CODE2                   = 2,
    KAL_ERROR_KAL_SUB_ERROR_CODE3                   = 3,
    KAL_ERROR_KAL_SUB_ERROR_CODE4                   = 4,
    KAL_ERROR_KAL_SUB_ERROR_CODE5                   = 5,
    KAL_ERROR_KAL_SUB_ERROR_CODE6                   = 6,
    KAL_ERROR_KAL_SUB_ERROR_CODE7                   = 7,
    KAL_ERROR_KAL_SUB_ERROR_CODE8                   = 8,

    /* System Initialization */
    KAL_ERROR_KALINIT_INIT_FAILED                   = 0x0101,
    KAL_ERROR_KALINIT_INIT_CREATE_SEM_FAILED,
    KAL_ERROR_KALINIT_INIT_CREATE_QU_MUTEX_FAILED,
    KAL_ERROR_KALINIT_INIT_CREATE_POOL_MUTEX_FAILED,
    KAL_ERROR_KALINIT_INIT_CREATE_TIMER_MUTEX_FAILED,
    KAL_ERROR_KALINIT_INIT_CREATE_MEM_MUTEX_FAILED,
    KAL_ERROR_KALINIT_INIT_MEMFAILED,
    KAL_ERROR_KALINIT_MEMINIT_FAILED,
    KAL_ERROR_KALINIT_CACHEINIT_FAILED,
    KAL_ERROR_KALINIT_CRCCHECK_FAILED,

    /* Task Management Error */
    KAL_ERROR_TASKMNGT_CREATE_MEMFAILED             = 0x0201,
    KAL_ERROR_TASKMNGT_CREATE_STACKFAILED,
    KAL_ERROR_TASKMNGT_CREATE_FAILED,
    KAL_ERROR_TASKMNGT_DELETE_FAILED,
    KAL_ERROR_TASKMNGT_SLEEP_FAILED,
    KAL_ERROR_TASKMNGT_GETID_FAILED,
    KAL_ERROR_TASKMNGT_STACKOVERFLOW,

    /* HISR Management Error */
    KAL_ERROR_HISRMNGT_CREATE_MEMFAILED             = 0x0211,
    KAL_ERROR_HISRMNGT_CREATE_STACKFAILED,
    KAL_ERROR_HISRMNGT_CREATE_FAILED,
    KAL_ERROR_HISRMNGT_DELETE_FAILED,
    KAL_ERROR_HISRMNGT_SLEEP_FAILED,
    KAL_ERROR_HISRMNGT_ACTIVATE_FAILED,
    KAL_ERROR_HISRMNGT_GETID_FAILED,
    KAL_ERROR_HISRMNGT_STACKOVERFLOW,
    KAL_HISRMNGT_REG_FAILED,

    /* Communication Management */
    KAL_ERROR_ITC_QCREATE_MEMFAILED                 = 0x0301,
    KAL_ERROR_ITC_QCREATE_DATAMEMFAILED,
    KAL_ERROR_ITC_QCREATE_FAILED,    
    KAL_ERROR_ITC_QCREATE_FAILED_INT,
    KAL_ERROR_ITC_QDELETE_FAILED = KAL_ERROR_ITC_QCREATE_FAILED_INT,
    KAL_ERROR_ITC_QENQUE_FAILED,
    KAL_ERROR_ITC_QENQUE_MEMFAILED,
    KAL_ERROR_ITC_QDEQUE_FAILED,

    KAL_ERROR_ITC_MCREATE_MEMFAILED                 = 0x0401,
    KAL_ERROR_ITC_MDELETE_FAILED,
    KAL_ERROR_ITC_MCREATE_FAILED,
    KAL_ERROR_ITC_MTAKE_FAILED,
    KAL_ERROR_ITC_MGIVE_FAILED,
    KAL_ERROR_ITC_MTAKE_INTERNAL_FAILED,
    KAL_ERROR_ITC_MGIVE_INTERNAL_FAILED,

    KAL_ERROR_ITC_SCREATE_MEMFAILED                 = 0x0411,
    KAL_ERROR_ITC_SDELETE_FAILED,
    KAL_ERROR_ITC_SCREATE_FAILED,
    KAL_ERROR_ITC_STAKE_FAILED,
    KAL_ERROR_ITC_SGIVE_FAILED,

    KAL_ERROR_ITC_EGCREATE_MEMFAILED                = 0x0421,
    KAL_ERROR_ITC_EGDELETE_FAILED,
    KAL_ERROR_ITC_EGCREATE_FAILED,
    KAL_ERROR_ITC_EGSET_FAILED,
    KAL_ERROR_ITC_EGRETRIEVE_FAILED,

    KAL_ERROR_ITC_ILM_MULTIALLOC                    = 0x0431,
    KAL_ERROR_ITC_ILM_NOT_ALLOC,

    KAL_ERROR_ITC_MSGID_CODE_EXCEED                 = 0x441,

    /* Timer Management */
    KAL_ERROR_TIMER_CREATE_MEMFAILED                = 0x0601,
    KAL_ERROR_TIMER_CREATE_FAILED,
    KAL_ERROR_TIMER_DELETE_FAILED,
    KAL_ERROR_TIMER_SET_FAILED,
    KAL_ERROR_TIMER_CANCEL_FAILED,
    KAL_ERROR_TIMER_GETTIME_FAILED,
    KAL_ERROR_TIMER_GETTIMEREMAINING_FAILED,
    KAL_ERROR_TIMER_SCHED_FAILED,
    KAL_ERROR_TIMER_CONTROL_FAILED,

    /* Resource Management */
    KAL_ERROR_MEMMNGT_ALLOC_FAILED                  = 0x0701,
    KAL_ERROR_MEMMNGT_ALLOC_DEBUGMEM_FAILED,
    KAL_ERROR_MEMMNGT_DEALLOC_FAILED,
    KAL_ERROR_MEMMNGT_DEALLOC_DEBUGMEM_FAILED,
    KAL_ERROR_MEMMNGT_MEMCPY_FAILED,
    KAL_ERROR_MEMMNGT_MEMSET_FAILED,

    /* Control Buffer */
    KAL_ERROR_BUFFMNGR_CREATE_MEMFAILED             = 0x0801,
    KAL_ERROR_BUFFMNGR_CREATE_FAILED,
    KAL_ERROR_BUFFMNGR_DELETE_FAILED,
    KAL_ERROR_BUFFMNGR_GETBUFF_FAILED,
    KAL_ERROR_BUFFMNGR_GETBUFF_SIZE_FAILED,
    KAL_ERROR_BUFFMNGR_GET_DATABUFF_FAILED,
    KAL_ERROR_BUFFMNGR_RELEASEBUFF_FAILED,
    KAL_ERROR_BUFFMNGR_RELEASE_DATABUFF_FAILED,
    KAL_ERROR_BUFFMNGR_ISVALID_FAILED,
    KAL_ERROR_BUFFMNGR_FOOTER_FAILED,
    KAL_ERROR_BUFFMNGR_HEADER_FAILED,
    KAL_ERROR_BUFFMNGR_FOOTER_FAILED_GET,
    KAL_ERROR_BUFFMNGR_HEADER_FAILED_GET,   
    KAL_ERROR_BUFFMNGR_STAMP_FAILED,
    KAL_ERROR_BUFFMNGR_GETBUFF_INTERNAL_FAILED,
    KAL_ERROR_BUFFMNGR_FREEBUFF_INTERNAL_FAILED,

    /* Error Message */
    KAL_ERROR_ERRORMNGR_FATALHANDLER_FAILED         = 0x0901,
    KAL_ERROR_ERRORMNGR_REGISTERHANDLER_FAILED,

    /* File System */
    KAL_ERROR_FILESYS_INTERNAL_FAILED               = 0x0a01,

    /* MISC */
    KAL_ERROR_NUCLEUS_INTERNAL_FAILED               = 0x0b01,
    KAL_ERROR_DIV_BY_0_FAILED,
    KAL_ERROR_ABNORMAL_RESET_FAILED,
    KAL_ERROR_NON_REGISTERED_LISR,
    KAL_ERROR_DEBUGJ2ME_INTERNAL_ALERT,
    KAL_ERROR_SHOULD_NOT_EXECUTE,

    /* Event Scheduler */
    KAL_ERROR_EVTSCH_CREATE_MEMFAILED               = 0x0c01,
    KAL_ERROR_EVTSCH_CREATE_FAILED,
    KAL_ERROR_EVTSCH_GETBUFF_FAILED,
    KAL_ERROR_EVTSCH_RELEASEBUFF_FAILED,
    KAL_ERROR_EVTSCH_CANCEL_FAILED,

    /* DEBUG */
    KAL_ERROR_DEBUGBUFFMNGR_GETPOOLSTAT_FAILED      = 0x1001,
    KAL_ERROR_DEBUGBUFFMNGR_RESETPOOLSTAT_FAILED,
    KAL_ERROR_DEBUGBUFFMNGR_GETBUFFSTAT_FAILED,
    KAL_ERROR_DEBUGBUFFMNGR_RESETBUFFSTAT_FAILED,
    KAL_ERROR_DEBUGBUFFMNGR_POOLID_VALIDATION_FALIED,
    KAL_ERROR_DEBUGBUFFMNGR_BUFF_OVERRUN_FAILED,

    KAL_ERROR_DEBUGERRORMNGR_REGISTERPRINT_FAILED   = 0x1101,
    KAL_ERROR_DEBUGERRORMNGR_PRINT_FAILED,

    KAL_ERROR_DEBUGITC_GETQSTAT_FAILED              = 0x1201,
    KAL_ERROR_DEBUGITC_RESETQSTAT_FAILED,

    KAL_ERROR_DEBUGTIMER_GETTIMERSTAT_FAILED        = 0x1301,
    KAL_ERROR_DEBUGTIMER_RESETTIMERSTAT_FAILED,

    KAL_ERROR_CUSTOMER_TASK_ID_EXCEED_UPPER_BOUND   = 0x1501,
    KAL_ERROR_CUSTOMER_MOD_ID_EXCEED_UPPER_BOUND,
    KAL_ERROR_CUSTOMER_MEESAGE_ID_EXCEED_UPPER_BOUND,
    KAL_ERROR_CUSTOMER_SAP_ID_EXCEED_UPPER_BOUND,

    KAL_ERROR_ESM_ADD_INSTANCE_FAILED                = 0x1601,
    KAL_ERROR_ESM_ADD_1stINSTANCEENTRY_FAILED,
    KAL_ERROR_ESM_DEL_INSTANCEENTRY_FAILED,
    KAL_ERROR_ESM_EXEC_CONTEXT_FAILED,
    KAL_ERROR_ESM_GET_INSTANCEPOINTER_FAILED,
    KAL_ERROR_ESM_POPULATE_FAILED,
    KAL_ERROR_ESM_INIT_INSTANCEARRAY_FAILED,
    KAL_ERROR_FSM_ADD_EVENTS2LIST_FAILED,
    KAL_ERROR_FSM_ADD_INSTANCEENTRY_FAILED,
    KAL_ERROR_FSM_DEL_INSTANCE_FAILED,
    KAL_ERROR_FSM_EXEC_TRANSITIONFUNC_FAILED,
    KAL_ERROR_FSM_GET_FREEINSTANCE_FAILED,
    KAL_ERROR_FSM_GET_INSTANCEDATA_FAILED,
    KAL_ERROR_FSM_HANDLE_SAVEDEVENTS_FAILED,
    KAL_ERROR_FSM_INIT_CONTEXT_FAILED,
    KAL_ERROR_FSM_PROCESS_EVENTS_FAILED,
    KAL_ERROR_LSM_DEL_EVENTLIST_FAILED,
    KAL_ERROR_LSM_UNDEL_LISTOBJ_FAILED,
    KAL_ERROR_MSM_TRANSITION_FAILED


} kal_error_type;

typedef struct
{
    kal_uint32 param1;
    kal_uint32 param2;
    kal_uint32 param3;
    kal_uint32 param4;
    kal_uint32 param5;
    kal_uint32 param6;
    kal_uint32 param7;
} kal_error_param;

#define KAL_ENH_MUTEX_MAX_NUM			64
#define KAL_ENH_MUTEX_FLAG32_NUM		((KAL_ENH_MUTEX_MAX_NUM + 31) / 32)

typedef struct {
   kal_uint32	mutex_id;
   kal_uint8	priority;
   kal_uint8	index;
   kal_uint8	head;   
   kal_uint8	tail;   
} *kal_internal_enh_mutexid, kal_enh_mutex_type;

#if defined(__MTK_TARGET__) || defined(KAL_ON_NUCLEUS) || defined (MTK_KAL_MNT) || defined (KAL_ON_OSCAR) || defined(KAL_ON_THREADX) || defined(L1_SIM)
typedef void (* kal_task_func_ptr)(task_entry_struct *task_entry_ptr);
typedef void (* kal_hisr_func_ptr)(void);
typedef void (* kal_error_func_ptr)(kal_char *, kal_uint32, kal_uint32);
typedef void (* kal_timer_func_ptr)(void *);
#endif

#endif /* _KAL_COMMON_DEFS_H */


