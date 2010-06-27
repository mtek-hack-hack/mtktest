/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */











#ifndef _brs_job_h
#define _brs_job_h

#ifndef _brs_list_h
#include "brs_list.h"
#endif

#ifndef _brs_sig_h
#include "brs_sig.h"
#endif







typedef struct brs_job_q_head_st {
  brs_list_t joblist;
} brs_job_q_head_t;


struct brs_job_q_element_st;

typedef enum
{
  BRS_JOB_SIGNAL_USED, 
  BRS_JOB_SIGNAL_NOT_USED 
} brs_job_signal_t;


typedef brs_job_signal_t brs_execute_job_func_t (brs_job_q_head_t *jobQ, 
                                    struct brs_job_q_element_st *p, 
                                    brs_signal_t *sig);
typedef void brs_release_job_func_t (void *job);

typedef enum
{
  BRS_JOB_TYPE_NORMAL, 
  BRS_JOB_TYPE_RUNING  
} brs_job_type_t;

typedef enum
{
  BRS_JOB_STATE_WANTS_TO_RUN,
  BRS_JOB_STATE_WAITING_FOR_SIGNAL, 
  BRS_JOB_STATE_DONE           
} brs_job_state_t;




typedef struct brs_job_q_element_st {
  void                          *job;     
  brs_execute_job_func_t        *execJob; 
  brs_release_job_func_t        *releaseJob; 
  brs_job_state_t               state;    
  
  
  brs_job_type_t                job_type;  
} brs_job_q_element_t;




  




void
brs_jobQ_init(brs_job_q_head_t *jobQ);

void 
brs_jobQ_release(brs_job_q_head_t *jobQ);

brs_job_signal_t
brs_jobQ_process (brs_job_q_head_t *jobQ, brs_signal_t *sig);

void 
brs_jobQ_process_job (brs_job_q_head_t *jobQ);

void
brs_jobQ_add (brs_job_q_head_t *jobQ,
              void *job,
              brs_execute_job_func_t *func,
              brs_release_job_func_t *release,
              brs_job_state_t state);

void
brs_jobQ_addFirst (brs_job_q_head_t *jobQ, 
                   void *job,
                   brs_execute_job_func_t *func,
                   brs_release_job_func_t *release,
                   brs_job_state_t state);

void
brs_jobQ_removeFirst (brs_job_q_head_t *jobQ);


int
brs_jobQ_has_running_jobs (brs_job_q_head_t *jobQ);





typedef struct {
  int           fileHandle;
  unsigned char *data;
  long          data_size;
  long          *result;
} brs_job_file_t;


void
brs_file_read_job (brs_job_q_head_t* jobQ,
                               int fileHandle, 
                               void *data, 
                               long size,
                               long *result);

void 
brs_file_write_job (brs_job_q_head_t* jobQ,
                                int fileHandle, 
                                void *data, 
                                long size,
                                long *result);





void
brs_file_write_mem_job (brs_job_q_head_t* jobQ,
                                    int fileHandle, 
                                    void **data, 
                                    long size,
                                    long *result);


void
brs_file_open_read_close_job (brs_job_q_head_t* jobQ,
                               const char *file_name, 
                               void **data, 
                               long *size,
                               long *result);

void 
brs_file_open_rewrite_close_job (brs_job_q_head_t* jobQ,
                                const char *file_name, 
                                void *data, 
                                long size,
                                long *result);

void
brs_file_open_rewrite_mem_close_job (brs_job_q_head_t* jobQ,
                                    const char *file_name, 
                                    void **data, 
                                    long size,
                                    long *result);

void
brs_file_open_append_mem_close_job (brs_job_q_head_t* jobQ,
																    const char* file_name, 
																    void **data, 
																    long size,
																    long *result);

void
brs_file_copy_job (brs_job_q_head_t* jobQ,
                   const char* src_file_name,
                   const char* dst_file_name,
                   long *result);

void
brs_file_copy_to_pipe_job (brs_job_q_head_t* jobQ,
                   const char* src_file_name,
                   const char* dst_pipe_name);

#endif


