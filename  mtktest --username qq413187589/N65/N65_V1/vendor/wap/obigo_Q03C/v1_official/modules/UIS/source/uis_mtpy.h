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









#ifndef _uis_mtpy_h_
#define _uis_mtpy_h_ 




#ifndef _uis_hash_h
#include "uis_hash.h"
#endif

#ifndef _uis_job_h
#include "uis_job.h"
#endif

#ifndef _uis_msg_h
#include "uis_msg.h"
#endif




typedef enum{
  UIS_MSG_TYPE_STARTING,
  UIS_MSG_TYPE_RUNNING
} uis_msg_type_state_t;

typedef struct {
  int                               msg_type;
  uis_hash_t                        msg_hash;
  unsigned long                     next_free_file_id;
  int                               file_handle;
  uis_job_q_head_t                  job_queue;
  long                              file_size;
  long                              file_fragmentation_begins;
  int                               un_touched_count;
  uis_msg_type_state_t              state;
  int                               ndx_file_exist;                             
} uis_msg_type_t;






#define UIS_MSG_TYPE_ADD_SUB_JOB(msg_ptr,job_data,func,release_func,state) \
  uis_jobQ_addFirst (&msg_ptr->job_queue, job_data, func, release_func, state)

#define UIS_MSG_TYPE_ADD_JOB(msg_ptr,job_data,func,release_func,state) \
  uis_jobQ_add (&msg_ptr->job_queue, job_data, func, release_func, state)

#define UIS_MSG_TYPE_ADD_JOB_AND_RUN(msg_ptr,job_data, func, release_func, state)   \
  uis_jobQ_add (&((msg_ptr)->job_queue), (job_data), (func), (release_func), (state));          \
  uis_jobQ_process_job (&((msg_ptr)->job_queue))

#define UIS_MSG_TYPE_PROCESS_SIGNAL(msg_type, sig)            \
  uis_jobQ_process (&msg_type->job_queue, sig)



#define UIS_MSG_GET_NEXT_FREE_FILE_ID(mtype) \
  ((mtype)->next_free_file_id = (((mtype)->next_free_file_id == 0x3FFFFF)? (1) :  \
    (++((mtype)->next_free_file_id))))












void  
uis_msg_type_init_job (uis_msg_type_t* mtype, 
                       int msg_type,
                       const char* file_name,
                       long file_size);

void
uis_msg_type_release (uis_msg_type_t* p);

int
uis_msg_ready_to_terminate (uis_msg_type_t* p);





int
uis_msg_type_delete_msg_from_handle (uis_msg_type_t* p, uis_msg_handle_t *handle);

int 
uis_msg_type_delete_msg (uis_msg_type_t* p, uis_msg_item_t* msg);







void
uis_msg_type_write_del_msg_job (uis_msg_type_t* p, uis_msg_handle_t *handle, long *result);


int
uis_msg_type_get_nbr_of_msgs (uis_msg_type_t* p, uis_key_value_array_t *filter);





uis_msg_list_item_t*
uis_msg_type_get_msg_list (uis_msg_type_t* p, 
                           uis_key_value_array_t *filter,
                           int srcModule,
                           int startFromMsg,
                           long maxResultMemSize,
                           int *result_nextMsg,
                           int *result_nbrOfMsgs);


uis_msg_item_t*
uis_msg_type_get_msg_from_handle (uis_msg_type_t* p, uis_msg_handle_t *handle);

void
uis_msg_type_get_msg_hidden_properties_job (uis_msg_type_t* p, 
                                            uis_msg_handle_t *handle,
                                            int *result,
                                            uis_key_value_array_t *result_array);

void
uis_msg_type_get_msg_data_job (uis_msg_type_t* p, 
                               uis_msg_handle_t *handle,
                               int *result,
                               long *result_dataLen,
                               unsigned char **result_data);

void
uis_msg_type_change_msg_job (uis_msg_type_t* p, 
                             uis_msg_handle_t *handle, 
                             uis_key_value_array_t *changePropArray,
                             uis_key_value_array_t *changeHiddenPropArray,
                             int changeData,
                             unsigned long dataLen,
                             unsigned char *data,
                             int *result);

void
uis_msg_type_create_msg_job (uis_msg_type_t* p, 
                             uis_msg_handle_t *handle, 
                             uis_key_value_array_t *propArray,
                             uis_key_value_array_t *hiddenPropArray,
                             unsigned long dataLen,
                             unsigned char *data,
                             int *result);

#endif


