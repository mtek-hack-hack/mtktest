/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/objc-list.h,v 1.1 2007/05/17 07:25:45 bw Exp $
*
* $Id: objc-list.h,v 1.1 2007/05/17 07:25:45 bw Exp $
*
* $Date: 2007/05/17 07:25:45 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: objc-list.h,v $
* Revision 1.1  2007/05/17 07:25:45  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2007
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/objc-list.h,v 1.1 2007/05/14 09:47:15 bw Exp $
*
* ~Id: objc-list.h,v 1.1 2007/05/14 09:47:15 bw Exp $
*
* ~Date: 2007/05/14 09:47:15 $
*
* ~Name: 1.1 $
*
* ~Locker$
*
* ~Revision: 1.1 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: objc-list.h,v $
* Revision 1.1  2007/05/14 09:47:15  bw
* UNI@bw_20070514 17:21:01 MTK初始版本.合并U25V20到U26V28.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/objc-list.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Id: objc-list.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Date: 2007/04/04 06:51:41 $
*
* ~Name: 1.2 $
*
* ~Locker$
*
* ~Revision: 1.2 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: objc-list.h,v $
* Revision 1.2  2007/04/04 06:51:41  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* Generic single linked list to keep various information 
   Copyright (C) 1993, 1994, 1996 Free Software Foundation, Inc.
   Contributed by Kresten Krab Thorup.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with files compiled with
   GCC to produce an executable, this does not cause the resulting executable
   to be covered by the GNU General Public License. This exception does not
   however invalidate any other reasons why the executable file might be
   covered by the GNU General Public License.  */

#ifndef __GNU_OBJC_LIST_H
#define __GNU_OBJC_LIST_H

struct objc_list {
  void *head;
  struct objc_list *tail;
};

/* Return a cons cell produced from (head . tail) */

static inline struct objc_list* 
list_cons(void* head, struct objc_list* tail)
{
  struct objc_list* cell;

  cell = (struct objc_list*)objc_malloc(sizeof(struct objc_list));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Return the length of a list, list_length(NULL) returns zero */

static inline int
list_length(struct objc_list* list)
{
  int i = 0;
  while(list)
    {
      i += 1;
      list = list->tail;
    }
  return i;
}

/* Return the Nth element of LIST, where N count from zero.  If N 
   larger than the list length, NULL is returned  */

static inline void*
list_nth(int index, struct objc_list* list)
{
  while(index-- != 0)
    {
      if(list->tail)
	list = list->tail;
      else
	return 0;
    }
  return list->head;
}

/* Remove the element at the head by replacing it by its successor */

static inline void
list_remove_head(struct objc_list** list)
{
  if ((*list)->tail)
    {
      struct objc_list* tail = (*list)->tail; /* fetch next */
      *(*list) = *tail;		/* copy next to list head */
      objc_free(tail);			/* free next */
    }
  else				/* only one element in list */
    {
      objc_free(*list);
      (*list) = 0;
    }
}


/* Remove the element with `car' set to ELEMENT */

static inline void
list_remove_elem(struct objc_list** list, void* elem)
{
  while (*list) {
    if ((*list)->head == elem)
      list_remove_head(list);
    list = &((*list)->tail);
  }
}

/* Map FUNCTION over all elements in LIST */

static inline void
list_mapcar(struct objc_list* list, void(*function)(void*))
{
  while(list)
    {
      (*function)(list->head);
      list = list->tail;
    }
}

/* Return element that has ELEM as car */

static inline struct objc_list**
list_find(struct objc_list** list, void* elem)
{
  while(*list)
    {
    if ((*list)->head == elem)
      return list;
    list = &((*list)->tail);
    }
  return NULL;
}

/* Free list (backwards recursive) */

static void
list_free(struct objc_list* list)
{
  if(list)
    {
      list_free(list->tail);
      objc_free(list);
    }
}
#endif /* not __GNU_OBJC_LIST_H */
