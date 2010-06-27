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









#ifndef _brs_memp_h
#define _brs_memp_h





















typedef struct {
  int    buf_size;
  int    num_bufs;
  int    current_bufidx;
  char  *current_pos;
  char  *current_end;
  char **bufs;
} brs_mempool_t;

typedef struct {
  int    buf_size;
  int    num_bufs;
  int    current_bufidx;
  char  *current_pos;
  char  *current_end;
  char **bufs;
  int    obj_size;
  int    log_num_objs;
  int    buf_size_mask;
} brs_objpool_t;










void
brs_memp_init (brs_mempool_t *pool, int buf_size);





void
brs_memp_terminate (brs_mempool_t *pool);






void *
brs_memp_allocate (brs_mempool_t *pool, int size);







void *
brs_memp_get_current (brs_mempool_t *pool);





void
brs_memp_release (brs_mempool_t *pool, void *p);











void
brs_memp_obj_init (brs_objpool_t *pool, int obj_size, int log_num_objs);





void
brs_memp_obj_terminate (brs_objpool_t *pool);





void *
brs_memp_obj_allocate (brs_objpool_t *pool);







void *
brs_memp_obj_get_current (brs_objpool_t *pool);





void
brs_memp_obj_release (brs_objpool_t *pool, void *obj);






void *
brs_memp_obj_indx2obj (brs_objpool_t *pool, int idx);







int
brs_memp_obj_obj2indx (brs_objpool_t *pool, void *obj);

#endif
