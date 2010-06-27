/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */









#ifndef _uis_main_h
#define _uis_main_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _uis_cfg_h
#include "uis_cfg.h"
#endif

#ifndef _uis_if_h
#include "uis_if.h"
#endif





#define UIS_MAIN_SIG_REGISTER                 (UIS_MODULE_MAIN + 1)
#define UIS_MAIN_SIG_REPLY_REGISTER           (UIS_MODULE_MAIN + 2)
#define UIS_MAIN_SIG_DEREGISTER               (UIS_MODULE_MAIN + 3)
#define UIS_MAIN_SIG_GET_NBR_OF_MSGS          (UIS_MODULE_MAIN + 4)
#define UIS_MAIN_SIG_REPLY_NBR_OF_MSGS        (UIS_MODULE_MAIN + 5)
#define UIS_MAIN_SIG_GET_MSG_LIST             (UIS_MODULE_MAIN + 6)
#define UIS_MAIN_SIG_REPLY_MSG_LIST           (UIS_MODULE_MAIN + 7)
#define UIS_MAIN_SIG_GET_MSG                  (UIS_MODULE_MAIN + 8)
#define UIS_MAIN_SIG_REPLY_MSG                (UIS_MODULE_MAIN + 9)
#define UIS_MAIN_SIG_GET_FULL_MSG             (UIS_MODULE_MAIN + 10)
#define UIS_MAIN_SIG_REPLY_FULL_MSG           (UIS_MODULE_MAIN + 11)
#define UIS_MAIN_SIG_DELETE_MSG               (UIS_MODULE_MAIN + 12)
#define UIS_MAIN_SIG_REPLY_DELETE_MSG         (UIS_MODULE_MAIN + 13)
#define UIS_MAIN_SIG_NOTIFY_MSG_DELETED       (UIS_MODULE_MAIN + 14)
#define UIS_MAIN_SIG_CHANGE_MSG               (UIS_MODULE_MAIN + 15)
#define UIS_MAIN_SIG_REPLY_CHANGE_MSG         (UIS_MODULE_MAIN + 16)
#define UIS_MAIN_SIG_NOTIFY_MSG_CHANGED       (UIS_MODULE_MAIN + 17)
#define UIS_MAIN_SIG_NOTIFY_NEW_MSG           (UIS_MODULE_MAIN + 18)
#define UIS_MAIN_SIG_CREATE_MSG               (UIS_MODULE_MAIN + 19)
#define UIS_MAIN_SIG_REPLY_CREATE_MSG         (UIS_MODULE_MAIN + 20)
#define UIS_MAIN_SIG_NOTIFY_UNREAD_MSG_COUNT  (UIS_MODULE_MAIN + 21)
#define UIS_MAIN_SIG_NOTIFY_INVALIDATE_ALL    (UIS_MODULE_MAIN + 22)
#define UIS_MAIN_SIG_SET_MSG_PROPERTY         (UIS_MODULE_MAIN + 23)
#define UIS_MAIN_SIG_REPLY_SET_MSG_PROPERTY   (UIS_MODULE_MAIN + 24)

#define UIS_MAIN_SIG_MODULE_STATUS            (UIS_MODULE_MAIN + 25)





extern jmp_buf uis_jmp_buf;
extern int     uis_inside_run;





void
uis_init (void);

void
uis_terminate (void);

void
uis_start_termination (void);

void
uis_terminate_msg_store_done (void);


int
uis_main_deregisterTransaction (int transactionId, unsigned *pSrcTransactionId);

unsigned*
uis_main_getTitlePropertiesDefinition (int msgType, int srcModule, int *result_nbrInArray);

void
uis_main_free_msg_handle (uis_msg_handle_t *p);

void
uis_main_free_key_value (uis_key_value_t *p);

void
uis_main_free_key_value_array (uis_key_value_t **p, int arraySize);

void
uis_main_free_full_msg (uis_full_msg_t *p);













void 
uis_replyNbrOfMsgs (int dst, 
                          unsigned transactionId,
                          int msgType,
                          unsigned nbrOfMsgs);









void 
uis_replyMsgList (int dst, 
                        unsigned transactionId,
                        int msgType,
                        unsigned msgListSize,
                        uis_msg_list_item_t *msgList,
                        unsigned nextMsg);








void 
uis_replyMsg (int dst, 
                    unsigned transactionId,
                    int msgType,
                    int result,
                    uis_msg_t *msg);








void 
uis_replyDeleteMsg (int dst,
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);







void 
uis_replyFullMsg (int dst,
                        unsigned transactionId,
                        int msgType,
                        int result,
                        uis_full_msg_t *msg);








void 
uis_replyChangeMsg (int dst, 
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);








void 
uis_replyCreateMsg (int dst, 
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);









void
uis_replySetMsgProperty (int dst,
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);





void
uis_handle_msg_main_notifyMsgDeleted (int srcModule, uis_notify_msg_deleted_t *p);

void
uis_handle_msg_main_notifyMsgChanged (int srcModule, uis_notify_msg_changed_t *p);

void
uis_handle_msg_main_notifyNewMsg (int srcModule, uis_notify_new_msg_t *p);






#define UIS_MEM_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_UIS, (x))
#define UIS_MEM_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_UIS, x)
#define UIS_MEM_FREE(x)       MSF_MEM_FREE (MSF_MODID_UIS, (x))

#ifdef MSF_LOG_MODULE

  #define UIS_LOG_FILE_IF(cond,func, fileop, res) \
  {if (cond){                                                        \
        MSF_LOG_MSG((MSF_LOG_DETAIL_LOW, MSF_MODID_UIS,                  \
        "UIS: " #fileop " failed (result = %i) [" #func "]\n",res));      \
  }}

  #define UIS_LOG_FILE_ERROR(func,fileop,res) UIS_LOG_FILE_IF(((res)<0),func,fileop,res)
  #define UIS_LOG_FILE_ERROR_ASYNC(func,fileop,res) \
    UIS_LOG_FILE_IF( (res<0 && res!=MSF_FILE_ERROR_DELAYED),func,fileop,res)

#else
  #define UIS_LOG_FILE_IF(cond,func, fileop, res) UNREFERENCED_PARAMETER(res)
  #define UIS_LOG_FILE_ERROR(func,fileop,res) UNREFERENCED_PARAMETER(res)
  #define UIS_LOG_FILE_ERROR_ASYNC(func,fileop,res) UNREFERENCED_PARAMETER(res)
#endif

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)          \
       \
      { \
          (P) = (P); \
      } \
      
#endif

#endif


