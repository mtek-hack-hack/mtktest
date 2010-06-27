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
 *	osc_type.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for OSCAR (Operating System Call Adapter) type definition
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

#ifndef __OSC_TYPE_H__
#define __OSC_TYPE_H__

/* INCLUDES ***********************************************************************/

/* MACROS *************************************************************************/

#define  OSC_CONST_NAME_LENGTH			  60
#define  OSC_CONST_MIN_PRIORITY           20
#define  OSC_CONST_RESERVE_PRIORITY       10
#define  OSC_CONST_MAX_ISR_SRC            64
#define  OSC_CONST_1_TICK                 5  //in milli-sec, ajustable

//guard pattern
#define  OSC_U32ID_THREAD                 0x80808080
#define  OSC_U32ID_SEMA                   0x81818181
#define  OSC_U32ID_TIMER                  0x82828282
#define  OSC_U32ID_QUEUE                  0x83838383
#define  OSC_U32ID_EVENT                  0x84848484
#define  OSC_U32ID_BUFFER                 0x85858585

/* -------------------------------------------------
CONFIGURE / QUERY Flag
--------------------------------------------------*/
//Reserve 0x00000001~0x00008000 for common flag
#define  OSC_U32FLAG_COMMON_NAME          0x00000001
#define  OSC_U32FLAG_COMMON_STATE         0x00000002
#define  OSC_U32FLAG_COMMON_WAIT_LIST     0x00000004

//Thread only: start from 0x00010000
#define  OSC_U32FLAG_THREAD_Priority      0x00010000
#define  OSC_U32FLAG_THREAD_TIME_SLICE    0x00020000
#define  OSC_U32FLAG_THREAD_TIME_LEFT     0x00040000
#define  OSC_U32FLAG_THREAD_STACK_SIZE    0x00080000
#define  OSC_U32FLAG_THREAD_STACK_ADDR    0x00100000
#define  OSC_U32FLAG_THREAD_STACK_PTR     0x00200000

//Semaphonre only: start from 0x00010000
#define  OSC_U32FLAG_SEMA_COUNT           0x00010000
#define  OSC_U32FLAG_SEMA_LEFT            0x00020000
#define  OSC_U32FLAG_SEMA_OWNER_LIST      0x00040000

//Timer only: start from 0x00010000
#define  OSC_U32FLAG_TIMER_DEFAULT        0x00010000
#define  OSC_U32FLAG_TIMER_PERIODIC       0x00020000
#define  OSC_U32FLAG_TIMER_LEFT           0x00040000
#define  OSC_U32FLAG_TIMER_EXPIRE_FUNC    0x00080000
#define  OSC_U32FLAG_TIMER_EXPIRE_PARAM   0x00100000

//Queue only: start from 0x00010000
#define  OSC_U32FLAG_QUEUE_SIZE           0x00010000
#define  OSC_U32FLAG_QUEUE_ADDR           0x00020000
#define  OSC_U32FLAG_QUEUE_MSG_SIZE       0x00040000
#define  OSC_U32FLAG_QUEUE_MSG_TOTAL      0x00080000
#define  OSC_U32FLAG_QUEUE_MSG_FREE       0x00100000
#define  OSC_U32FLAG_QUEUE_MSG_USED       0x00200000

//Event only: start from 0x00010000
#define  OSC_U32FLAG_EVENT_FLAG           0x00010000

//Buffer only: start from 0x00010000
#define  OSC_U32FLAG_BUFF_POOL_SIZE       0x00010000
#define  OSC_U32FLAG_BUFF_POOL_ADDR       0x00020000
#define  OSC_U32FLAG_BUFF_BLOCK_SIZE      0x00040000
#define  OSC_U32FLAG_BUFF_BLOCK_TOTAL     0x00080000
#define  OSC_U32FLAG_BUFF_FREE_LIST       0x00100000
#define  OSC_U32FLAG_BUFF_USED_LIST       0x00200000

/* -------------------------------------------------
ACTION Flag
--------------------------------------------------*/
#define  OSC_ACTION_FULL_SET              0x00000001 //W: write through; R: resume if all match
#define  OSC_ACTION_PART_SET              0x00000002 //W: write if not; R: resume if any match
#define  OSC_ACTION_CLS					      0x00000004
#define  OSC_ACTION_INSERT_APPEND         0x00000008
#define  OSC_ACTION_INSERT_FIRST          0x00000010

/* ENUM ***************************************************************************/

typedef enum
{
   OSC_ISR_SRC_RESERVED,
   OSC_ISR_SRC_CTIRQ1,
   OSC_ISR_SRC_SYS_END,

   //mtk user add start
   OSC_ISR_SRC_BT_BCHS_RX,              //Requested by Max for CSR BT RX ISR
   OSC_ISR_SRC_BT_BCHS_TX,              //Requested by Max for CSR BT TX ISR
   OSC_ISR_SRC_BT_BCHS_RESTART,         //Requested by Max for CSR BT reset chip ISR
   OSC_ISR_SRC_USB,			//Requested by Brad for ESI BT USB driver
   OSC_ISR_SRC_UART,                    //Requested by KS for UART driver
   OSC_ISR_SRC_MTE_MMI_RX,							//Requested by Glory for MTE RX ISR
   OSC_ISR_SRC_MTE_MMI_TX,							//Requested by Glory for MTE TX ISR
   //mtk user add end

   //customer add start, cannot be modified by customer
   OSC_ISR_SRC_CUSTOM1,
   OSC_ISR_SRC_CUSTOM2,
   OSC_ISR_SRC_CUSTOM3,
   OSC_ISR_SRC_CUSTOM4,
   OSC_ISR_SRC_CUSTOM5,
   OSC_ISR_SRC_CUSTOM6,
   OSC_ISR_SRC_CUSTOM7,
   OSC_ISR_SRC_CUSTOM8,
   OSC_ISR_SRC_CUSTOM9,
   OSC_ISR_SRC_CUSTOM10,
   //customer add end, cannot be modified by customer

   OSC_ISR_SRC_END = OSC_CONST_MAX_ISR_SRC
}  osc_enum_isr_src;

typedef enum
{
   OSC_BOOL_FALSE,
   OSC_BOOL_TRUE
}  osc_enum_bool;

typedef enum
{
   OSC_STATE_INIT,            //thread, timer
   OSC_STATE_READY,           //thread only
   OSC_STATE_RUNNING,         //thread, timer
   OSC_STATE_SUSPEND_FOREVER, //thread only
   OSC_STATE_SUSPEND_SLEEP,   //thread only
   OSC_STATE_SUSPEND_SEMA,    //thread only
   OSC_STATE_SUSPEND_QUEUE,   //thread only
   OSC_STATE_SUSPEND_EVENT,   //thread only
   OSC_STATE_EXPIRE,          //timer only
   OSC_STATE_STOP,            //timer only
   OSC_STATE_DELETED,         //thread only
   OSC_STATE_END              = 0xFFFFFFFF //for extend to U32
}  osc_enum_state;

typedef enum
{
   OSC_TIMEOUT_NONE           = 0,
   OSC_TIMEOUT_LOCK,
   OSC_TIMEOUT_ABANDON,
   OSC_TIMEOUT_FOREVER        = 0xFFFFFFFF //this is also "INFINITE" in windows
}  osc_enum_timeout;

/* MISC TYPE **********************************************************************/

// basic data type -----------------------------------------------------------------
#ifdef __OSCAR_ON_WIN32__
typedef  signed   char     osc_type_s8;
typedef  unsigned char     osc_type_u8;
typedef  signed   short    osc_type_s16;
typedef  unsigned short    osc_type_u16;
typedef  signed   int      osc_type_s32;
typedef  unsigned int      osc_type_u32;
#endif //__OSCAR_ON_WIN32__

typedef void*  osc_type_void_ptr;
typedef void*  (* osc_type_func_ptr)(void * param1, ...);

/* STRUCTURE **********************************************************************/

/* ---------------------------------------------------
Predefined structure to forward
----------------------------------------------------*/
#ifndef __cplusplus

struct osc_struct_dd_hdr;
struct osc_struct_dd_list;
struct osc_struct_thread;
struct osc_struct_timer;
struct osc_struct_sema;
struct osc_struct_queue;
struct osc_struct_event;
struct osc_struct_buffer;

#endif

/* ---------------------------------------------------
Double linked list structure for head
----------------------------------------------------*/
typedef struct _osc_struct_dd_hdr
{
   osc_type_u8                name[OSC_CONST_NAME_LENGTH + 30]; //more internal string
   osc_type_u32               dd_list_count;
   struct _osc_struct_dd_list *ptr_first;
   struct _osc_struct_dd_list *ptr_last;
}  osc_struct_dd_hdr;

/* ---------------------------------------------------
Double linked list structure for node
----------------------------------------------------*/
typedef struct _osc_struct_dd_list
{
   void                       *ptr_this;
   struct _osc_struct_dd_list *ptr_prev;
   struct _osc_struct_dd_list *ptr_next;
   void                       *ptr_extend;
}  osc_struct_dd_list;

/* ---------------------------------------------------
Thread control structure
----------------------------------------------------*/
typedef struct _osc_struct_thread
{
   osc_type_u32               guard;      //must put at 1st place
   void                       *handle;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_enum_state			      state;
   osc_type_u32				   priority;
   osc_type_u32				   time_slice;
   osc_type_u32               time_left;
   osc_type_u32				   stack_size;
   osc_type_u32				   stack_addr; //could be taken as thread id
   osc_type_u32				   stack_ptr;
   osc_type_func_ptr		      entry_func;
   osc_type_void_ptr          entry_param;
   struct _osc_struct_dd_hdr  *timer;
   osc_type_void_ptr          waiting_list;
   osc_type_void_ptr          extend;
}  osc_struct_thread;

/* ---------------------------------------------------
Timer control structure
----------------------------------------------------*/
typedef struct _osc_struct_timer
{
   osc_type_u32               guard;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_enum_state			      state;
   osc_type_u32				   time_default;
   osc_type_u32				   time_periodic;
   osc_type_u32               time_left;
   osc_type_func_ptr		      expiry_func;
   osc_type_void_ptr		      expiry_param;
   struct _osc_struct_dd_hdr  *waiting_list;
   osc_type_void_ptr          extend;
}  osc_struct_timer;

/* ---------------------------------------------------
Semaphore control structure
----------------------------------------------------*/
typedef struct _osc_struct_sema
{
   osc_type_u32               guard;
   void                       *handle;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_type_u32				   count_num;
   osc_type_u32				   count_left;
   struct _osc_struct_dd_hdr  *owner_list;
   struct _osc_struct_dd_hdr  *waiting_list;
   osc_type_void_ptr          extend;
}  osc_struct_sema;

/* ---------------------------------------------------
Queue control structure
----------------------------------------------------*/
typedef struct _osc_struct_queue
{
   osc_type_u32               guard;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_type_u32				   queue_size;
   osc_type_u32				   *queue_addr;
   osc_type_u32				   msg_size;
   osc_type_u32				   msg_num_total;
   struct _osc_struct_dd_hdr  *msg_free_list;   //for write
   struct _osc_struct_dd_hdr  *msg_used_list;   //for read
   struct _osc_struct_dd_hdr  *waiting_list;
   osc_type_void_ptr          extend;
}  osc_struct_queue;

/* ---------------------------------------------------
Event group control structure
----------------------------------------------------*/
typedef struct _osc_struct_event
{
   osc_type_u32               guard;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_type_u32				   event_flag;
   struct _osc_struct_dd_hdr  *waiting_list;
   osc_type_void_ptr          extend;
}  osc_struct_event;

typedef struct _osc_struct_event_waiting
{
   struct _osc_struct_thread  *thread;
   osc_type_u32               event_need;
   osc_type_u32               event_actual;
   osc_type_u32               action;
   osc_type_void_ptr          extend;
}  osc_struct_event_waiting;

/* ---------------------------------------------------
Buffer pool control structure
----------------------------------------------------*/
typedef struct _osc_struct_buffer
{
   osc_type_u32               guard;
   osc_type_u8				      name[OSC_CONST_NAME_LENGTH];
   osc_type_u32				   pool_size;
   osc_type_u32				   *pool_addr;
   osc_type_u32				   block_size;
   osc_type_u32				   block_num_total;
   struct _osc_struct_dd_hdr  *block_free_list;
   struct _osc_struct_dd_hdr  *block_used_list;
   osc_type_void_ptr          extend;
}  osc_struct_buffer;

typedef struct _osc_struct_block_hdr
{
   osc_type_u32               threadid;
   osc_struct_buffer          *pool;
   osc_type_void_ptr          extend;
}  osc_struct_block_hdr;

#endif //__OSC_TYPE_H__
