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









#ifndef _uis_job_h
#define _uis_job_h

#ifndef _uis_list_h
#include "uis_list.h"
#endif

#ifndef _uis_sig_h
#include "uis_sig.h"
#endif







typedef struct uis_job_q_head_st {
  uis_list_t joblist;
} uis_job_q_head_t;


struct uis_job_q_element_st;

typedef enum
{
  UIS_JOB_SIGNAL_USED, 
  UIS_JOB_SIGNAL_NOT_USED 
} uis_job_signal_t;


typedef uis_job_signal_t uis_execute_job_func_t (uis_job_q_head_t *jobQ, 
                                    struct uis_job_q_element_st *p, 
                                    uis_signal_t *sig);
typedef void uis_release_job_func_t (void *job);

typedef enum
{
  UIS_JOB_TYPE_NORMAL, 
  UIS_JOB_TYPE_RUNING  
} uis_job_type_t;

typedef enum
{
  UIS_JOB_STATE_WANTS_TO_RUN,
  UIS_JOB_STATE_WAITING_FOR_SIGNAL, 
  UIS_JOB_STATE_DONE           
} uis_job_state_t;




typedef struct uis_job_q_element_st {
  void                          *job;     
  uis_execute_job_func_t        *execJob; 
  uis_release_job_func_t        *releaseJob; 
  uis_job_state_t               state;    
  
  
  uis_job_type_t                job_type;  
} uis_job_q_element_t;




  




void
uis_jobQ_init(uis_job_q_head_t *jobQ);

void 
uis_jobQ_release(uis_job_q_head_t *jobQ);

uis_job_signal_t
uis_jobQ_process (uis_job_q_head_t *jobQ, uis_signal_t *sig);

void 
uis_jobQ_process_job (uis_job_q_head_t *jobQ);

void
uis_jobQ_add (uis_job_q_head_t *jobQ,
              void *job,
              uis_execute_job_func_t *func,
              uis_release_job_func_t *release,
              uis_job_state_t state);

void
uis_jobQ_addFirst (uis_job_q_head_t *jobQ, 
                   void *job,
                   uis_execute_job_func_t *func,
                   uis_release_job_func_t *release,
                   uis_job_state_t state);

void
uis_jobQ_removeFirst (uis_job_q_head_t *jobQ);


int
uis_jobQ_has_running_jobs (uis_job_q_head_t *jobQ);





typedef struct {
  int           fileHandle;
  unsigned char *data;
  long          data_size;
  long          *result;
} uis_job_file_t;


void
uis_file_read_job (uis_job_q_head_t* jobQ,
                               int fileHandle, 
                               void *data, 
                               long size,
                               long *result);

void 
uis_file_write_job (uis_job_q_head_t* jobQ,
                                int fileHandle, 
                                void *data, 
                                long size,
                                long *result);





void
uis_file_write_mem_job (uis_job_q_head_t* jobQ,
                                    int fileHandle, 
                                    void **data, 
                                    long size,
                                    long *result);


void
uis_file_open_read_close_job (uis_job_q_head_t* jobQ,
                               const char *file_name, 
                               void **data, 
                               long *size,
                               long *result);

void 
uis_file_open_rewrite_close_job (uis_job_q_head_t* jobQ,
                                const char *file_name, 
                                void *data, 
                                long size,
                                long *result);

void
uis_file_open_rewrite_mem_close_job (uis_job_q_head_t* jobQ,
                                    const char *file_name, 
                                    void **data, 
                                    long size,
                                    long *result);


#endif


