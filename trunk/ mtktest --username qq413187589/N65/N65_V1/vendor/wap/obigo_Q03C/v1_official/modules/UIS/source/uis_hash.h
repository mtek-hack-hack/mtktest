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









#ifndef _uis_hash_h
#define _uis_hash_h

#ifndef _uis_list_h
#include "uis_list.h"
#endif






#define UIS_HASH_ITERATOR_GET(i)  \
  ((i).it.current->value)
#define UIS_HASH_ITERATOR_GET_TYPE(i,type) \
  ((type*)((i).it.current->value))




#define UIS_HASH_ITERATOR_NEXT(it) uis_hash_iterator_next(&(it))


#define UIS_HASH_ITERATOR_EQUAL(i,ii)       \
  (((i).set        == (ii).set)         &&  \
   ((i).it.list    == (ii).it.list)     &&  \
   ((i).it.current == (ii).it.current))

#define UIS_HASH_ITERATOR_NOT_EQUAL(i,ii)     \
  (!(((i).set        == (ii).set)         &&  \
   ((i).it.list    == (ii).it.list)       &&  \
   ((i).it.current == (ii).it.current)))



#define UIS_HASH_SIZE(set) ((set)->size)

#define UIS_HASH_END(hash, end_it)                                         \
  ((end_it).set = (hash),                                                  \
  (end_it).it = uis_list_end( &(hash)->buckets[(hash)->bucket_count-1] ))







typedef int uis_hash_func_t(void* data);




typedef uis_list_func_compare_t uis_hash_func_compare_t;




typedef struct {
  unsigned int             bucket_count;
  uis_list_t              *buckets;
  uis_hash_func_t         *hash;
  uis_hash_func_compare_t *compare;
  int                      size;
} uis_hash_t;





typedef struct {
  uis_list_iterator_t it;
  uis_hash_t          *set;
} uis_hash_iterator_t;













void
uis_hash_init (uis_hash_t              *set, 
               MSF_UINT8                mod_id,                
               unsigned int             bucket_count,
               uis_hash_func_t         *hash,
               uis_hash_func_compare_t *compare);





void
uis_hash_release (uis_hash_t* set);




int
uis_hash_insert (uis_hash_t* set, void* data);





uis_hash_iterator_t
uis_hash_find (uis_hash_t* set, void* data);





uis_hash_iterator_t
uis_hash_erase(uis_hash_iterator_t it);





int
uis_hash_erase_data( uis_hash_t *set, void* data);

uis_hash_iterator_t
uis_hash_begin (uis_hash_t* set);



uis_hash_iterator_t
uis_hash_end (uis_hash_t* set);

uis_hash_iterator_t
uis_hash_iterator_at (uis_hash_t* set, int index);




void
uis_hash_iterator_next (uis_hash_iterator_t* it);




#endif


