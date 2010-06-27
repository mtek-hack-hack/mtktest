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





















#ifndef _uis_list_h
#define _uis_list_h




#ifndef _msf_def_h
#include "msf_def.h"
#endif 










typedef int uis_list_func_compare_t(void* key_a, void* key_b);


typedef struct uis_list_element_st{
  struct uis_list_element_st *prev; 
  struct uis_list_element_st *next;
  void                       *value;
} uis_list_element_t;



typedef struct {
  uis_list_element_t  head;
  int                 size;
  MSF_UINT8           mod_id;
}uis_list_t;

typedef struct {
  uis_list_element_t *current;
  uis_list_t         *list;
}uis_list_iterator_t;


typedef uis_list_t          uis_queue_t;





#define UIS_LIST_ITERATOR_EQUAL(a,b) \
  ((a.current == b.current) && (a.list == b.list))

#define UIS_LIST_ITERATOR_NOT_EQUAL(a,b) \
  ((a.current != b.current) || (a.list != b.list))

#define UIS_LIST_ITERATOR_GET(it) (it.current->value)
#define UIS_LIST_ITERATOR_GET_TYPE(it,type) ((type*) (it.current->value))
#define UIS_LIST_ITERATOR_NEXT(it) \
  ((it).current = (it).current->next)
#define UIS_LIST_ITERATOR_PREV(it) \
  ((it).current = (it).current->prev)




#define UIS_LIST_SIZE(list) \
  ((list)->size)

#define UIS_LIST_EMPTY(list) \
  (UIS_LIST_SIZE  (list) <= 0 )

#define UIS_LIST_END(l,i)    \
  ((i).current = &(l)->head, \
  (i).list = (l))

#define UIS_LIST_BEGIN(l,it)        \
  ((it).current = (l)->head.next,   \
  (it).list = (l))




#define UIS_LIST_FRONT(list)   \
  ((list)->head.next->value)






#define UIS_LIST_FOR_EACH(list, type, func)                              \
{                                                                        \
  uis_list_iterator_t it ;                                               \
  uis_list_iterator_t end;                                               \
  UIS_LIST_BEGIN(list,it);                                               \
  UIS_LIST_END(list,end);                                                \
  for ( ; UIS_LIST_ITERATOR_NOT_EQUAL(it,end); UIS_LIST_ITERATOR_NEXT(it)\
  {                                                                      \
    func((type*)it.current->value);                                      \
  }                                                                      \
}




#define uis_list_declare (TYPE) \
  TYPE uis_list_get_##TYPE (uis_list_iterator_t it){   \
    return (TYPE*)it->current->value;                  \
}                                                      \












#define UIS_QUEUE_DECLARE(type,prefix)                \
void                                                  \
prefix##init(uis_queue_t* p,                          \
               MSF_UINT8 mod_id)                      \
{                                                     \
  uis_list_init(p,mod_id);                            \
}                                                     \
int                                                   \
prefix##empty(uis_queue_t* que)                       \
{                                                     \
  return UIS_LIST_SIZE(que)==0;                       \
}                                                     \
int                                                   \
prefix##size(uis_queue_t* que)                        \
{                                                     \
  return UIS_LIST_SIZE(que);                          \
}                                                     \
type*                                                 \
prefix##top(uis_queue_t* que)                         \
{                                                     \
  return (type*)uis_list_front(que);                  \
}                                                     \
void                                                  \
prefix##push(uis_queue_t* que, type *p)               \
{                                                     \
  uis_list_push_back(que,p);                          \
}                                                     \
void                                                  \
prefix##pop(uis_queue_t* que)                         \
{                                                     \
  uis_list_pop_front(que);                            \
}










void 
uis_list_init (uis_list_t* list, 
               MSF_UINT8 mod_id);






void
uis_list_release (uis_list_t* list);





uis_list_iterator_t
uis_list_begin(uis_list_t* list);





uis_list_iterator_t
uis_list_end(uis_list_t* list);





uis_list_iterator_t
uis_list_erase(uis_list_iterator_t it);





uis_list_iterator_t
uis_list_erase_sequence(uis_list_iterator_t first, uis_list_iterator_t last);




void 
uis_list_pop_front (uis_list_t* list);




void 
uis_list_pop_back (uis_list_t *list);




uis_list_iterator_t
uis_list_insert (uis_list_iterator_t it, void* data);




void 
uis_list_push_front (uis_list_t* list, void* data);




void 
uis_list_push_back (uis_list_t* list, void* data );





void* 
uis_list_back (uis_list_t* list);







uis_list_iterator_t
uis_list_find (uis_list_iterator_t begin, 
               uis_list_iterator_t end, 
               void* value,
               uis_list_func_compare_t* compare);


uis_list_iterator_t
uis_list_iterator_at( uis_list_t* list, int index);

#endif


