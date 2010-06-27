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





















#ifndef _brs_list_h
#define _brs_list_h




#ifndef _msf_def_h
#include "msf_def.h"
#endif 










typedef int brs_list_func_compare_t(void* key_a, void* key_b);


typedef struct brs_list_element_st{
  struct brs_list_element_st *prev; 
  struct brs_list_element_st *next;
  void                       *value;
} brs_list_element_t;



typedef struct {
  brs_list_element_t  head;
  int                 size;
  MSF_UINT8           mod_id;
}brs_list_t;

typedef struct {
  brs_list_element_t *current;
  brs_list_t         *list;
}brs_list_iterator_t;


typedef brs_list_t          brs_queue_t;





#define BRS_LIST_ITERATOR_EQUAL(a,b) \
  ((a.current == b.current) && (a.list == b.list))

#define BRS_LIST_ITERATOR_NOT_EQUAL(a,b) \
  ((a.current != b.current) || (a.list != b.list))

#define BRS_LIST_ITERATOR_GET(it) (it.current->value)
#define BRS_LIST_ITERATOR_GET_TYPE(it,type) ((type*) (it.current->value))
#define BRS_LIST_ITERATOR_NEXT(it) \
  ((it).current = (it).current->next)
#define BRS_LIST_ITERATOR_PREV(it) \
  ((it).current = (it).current->prev)




#define BRS_LIST_SIZE(list) \
  ((list)->size)

#define BRS_LIST_EMPTY(list) \
  (BRS_LIST_SIZE  (list) <= 0 )

#define BRS_LIST_END(l,i)    \
  ((i).current = &(l)->head, \
  (i).list = (l))

#define BRS_LIST_BEGIN(l,it)        \
  ((it).current = (l)->head.next,   \
  (it).list = (l))




#define BRS_LIST_FRONT(list)   \
  ((list)->head.next->value)






#define BRS_LIST_FOR_EACH(list, type, func)                              \
{                                                                        \
  brs_list_iterator_t it ;                                               \
  brs_list_iterator_t end;                                               \
  BRS_LIST_BEGIN(list,it);                                               \
  BRS_LIST_END(list,end);                                                \
  for ( ; BRS_LIST_ITERATOR_NOT_EQUAL(it,end); BRS_LIST_ITERATOR_NEXT(it)\
  {                                                                      \
    func((type*)it.current->value);                                      \
  }                                                                      \
}




#define brs_list_declare (TYPE) \
  TYPE brs_list_get_##TYPE (brs_list_iterator_t it){   \
    return (TYPE*)it->current->value;                  \
}                                                      \












#define brs_QUEUE_DECLARE(type,prefix)                \
void                                                  \
prefix##init(brs_queue_t* p,                          \
               MSF_UINT8 mod_id)                      \
{                                                     \
  brs_list_init(p,mod_id);                            \
}                                                     \
int                                                   \
prefix##empty(brs_queue_t* que)                       \
{                                                     \
  return BRS_LIST_SIZE(que)==0;                       \
}                                                     \
int                                                   \
prefix##size(brs_queue_t* que)                        \
{                                                     \
  return BRS_LIST_SIZE(que);                          \
}                                                     \
type*                                                 \
prefix##top(brs_queue_t* que)                         \
{                                                     \
  return (type*)brs_list_front(que);                  \
}                                                     \
void                                                  \
prefix##push(brs_queue_t* que, type *p)               \
{                                                     \
  brs_list_push_back(que,p);                          \
}                                                     \
void                                                  \
prefix##pop(brs_queue_t* que)                         \
{                                                     \
  brs_list_pop_front(que);                            \
}










void 
brs_list_init (brs_list_t* list, 
               MSF_UINT8 mod_id);






void
brs_list_release (brs_list_t* list);





brs_list_iterator_t
brs_list_begin(brs_list_t* list);





brs_list_iterator_t
brs_list_end(brs_list_t* list);





brs_list_iterator_t
brs_list_erase(brs_list_iterator_t it);





brs_list_iterator_t
brs_list_erase_sequence(brs_list_iterator_t first, brs_list_iterator_t last);




void 
brs_list_pop_front (brs_list_t* list);




void 
brs_list_pop_back (brs_list_t *list);




brs_list_iterator_t
brs_list_insert (brs_list_iterator_t it, void* data);




void 
brs_list_push_front (brs_list_t* list, void* data);




void 
brs_list_push_back (brs_list_t* list, void* data );





void* 
brs_list_back (brs_list_t* list);







brs_list_iterator_t
brs_list_find (brs_list_iterator_t begin, 
               brs_list_iterator_t end, 
               void* value,
               brs_list_func_compare_t* compare);


brs_list_iterator_t
brs_list_iterator_at( brs_list_t* list, int index);

#endif
