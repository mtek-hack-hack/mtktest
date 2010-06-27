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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/sarray.h,v 1.1 2007/05/17 07:26:03 bw Exp $
*
* $Id: sarray.h,v 1.1 2007/05/17 07:26:03 bw Exp $
*
* $Date: 2007/05/17 07:26:03 $
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
* $Log: sarray.h,v $
* Revision 1.1  2007/05/17 07:26:03  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/sarray.h,v 1.1 2007/05/14 09:47:15 bw Exp $
*
* ~Id: sarray.h,v 1.1 2007/05/14 09:47:15 bw Exp $
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
* ~Log: sarray.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/sarray.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Id: sarray.h,v 1.2 2007/04/04 06:51:41 bw Exp $
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
* ~Log: sarray.h,v $
* Revision 1.2  2007/04/04 06:51:41  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* Sparse Arrays for Objective C dispatch tables
   Copyright (C) 1993, 1995, 1996 Free Software Foundation, Inc.
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

/* As a special exception, if you link this library with files
   compiled with GCC to produce an executable, this does not cause
   the resulting executable to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

#ifndef __sarray_INCLUDE_GNU
#define __sarray_INCLUDE_GNU

#define OBJC_SPARSE2		/* 2-level sparse array */
/* #define OBJC_SPARSE3 */      /* 3-level sparse array */

#ifdef OBJC_SPARSE2
extern const char* __objc_sparse2_id;
#endif

#ifdef OBJC_SPARSE3
extern const char* __objc_sparse3_id;
#endif

#include <stddef.h>

#include "objc/thr.h"

extern int nbuckets;		/* for stats */
extern int nindices;
extern int narrays;
extern int idxsize;

#include <assert.h>

/* An unsigned integer of same size as a pointer */
#define SIZET_BITS (sizeof(size_t)*8)

#if defined(__sparc__) || defined(OBJC_SPARSE2)
#define PRECOMPUTE_SELECTORS
#endif

#ifdef OBJC_SPARSE3

/* Buckets are 8 words each */
#define BUCKET_BITS 3
#define BUCKET_SIZE (1<<BUCKET_BITS)
#define BUCKET_MASK (BUCKET_SIZE-1)

/* Indices are 16 words each */
#define INDEX_BITS 4
#define INDEX_SIZE (1<<INDEX_BITS)
#define INDEX_MASK (INDEX_SIZE-1)

#define INDEX_CAPACITY (BUCKET_SIZE*INDEX_SIZE)

#else /* OBJC_SPARSE2 */

/* Buckets are 32 words each */
#define BUCKET_BITS 5
#define BUCKET_SIZE (1<<BUCKET_BITS)
#define BUCKET_MASK (BUCKET_SIZE-1)

#endif /* OBJC_SPARSE2 */

typedef size_t sidx;

#ifdef PRECOMPUTE_SELECTORS

struct soffset {
#ifdef OBJC_SPARSE3
  unsigned int unused : SIZET_BITS/4;
  unsigned int eoffset : SIZET_BITS/4;
  unsigned int boffset : SIZET_BITS/4;
  unsigned int ioffset : SIZET_BITS/4;
#else /* OBJC_SPARSE2 */
#ifdef __sparc__
  unsigned long boffset : (SIZET_BITS - 2) - BUCKET_BITS;
  unsigned int eoffset : BUCKET_BITS;
  unsigned int unused  : 2;
#else
  unsigned int boffset : SIZET_BITS/2;
  unsigned int eoffset : SIZET_BITS/2;
#endif
#endif /* OBJC_SPARSE2 */
};

union sofftype {
  struct soffset off;
  sidx idx;
};

#endif /* not PRECOMPUTE_SELECTORS */

union sversion {
  int	version;
  void *next_free;
};

struct sbucket {
  void* elems[BUCKET_SIZE];	/* elements stored in array */
  union sversion	version;		/* used for copy-on-write */
};

#ifdef OBJC_SPARSE3

struct sindex {
  struct sbucket* buckets[INDEX_SIZE];
  union sversion	version;		/* used for copy-on-write */
};

#endif /* OBJC_SPARSE3 */

struct sarray {
#ifdef OBJC_SPARSE3
  struct sindex** indices;
  struct sindex* empty_index;
#else /* OBJC_SPARSE2 */
  struct sbucket** buckets;
#endif  /* OBJC_SPARSE2 */
  struct sbucket* empty_bucket;
  union sversion	version;		/* used for copy-on-write */
  short ref_count;
  struct sarray* is_copy_of;
  size_t capacity;
};

struct sarray* sarray_new(int, void* default_element);
void sarray_free(struct sarray*);
struct sarray* sarray_lazy_copy(struct sarray*);
void sarray_realloc(struct sarray*, int new_size);
void sarray_at_put(struct sarray*, sidx index, void* elem);
void sarray_at_put_safe(struct sarray*, sidx index, void* elem);

struct sarray* sarray_hard_copy(struct sarray*); /* ... like the name? */
void sarray_remove_garbage(void);


#ifdef PRECOMPUTE_SELECTORS
/* Transform soffset values to ints and vica verca */
static inline unsigned int
soffset_decode(sidx index)
{
  union sofftype x;
  x.idx = index;
#ifdef OBJC_SPARSE3
  return x.off.eoffset
    + (x.off.boffset*BUCKET_SIZE)
      + (x.off.ioffset*INDEX_CAPACITY);
#else /* OBJC_SPARSE2 */
  return x.off.eoffset + (x.off.boffset*BUCKET_SIZE);
#endif /* OBJC_SPARSE2 */
}

static inline sidx
soffset_encode(size_t offset)
{
  union sofftype x;
  x.off.eoffset = offset%BUCKET_SIZE;
#ifdef OBJC_SPARSE3
  x.off.boffset = (offset/BUCKET_SIZE)%INDEX_SIZE;
  x.off.ioffset = offset/INDEX_CAPACITY;
#else /* OBJC_SPARSE2 */
  x.off.boffset = offset/BUCKET_SIZE;
#endif
  return (sidx)x.idx;
}

#else /* not PRECOMPUTE_SELECTORS */

static inline size_t
soffset_decode(sidx index)
{
  return index;
}

static inline sidx
soffset_encode(size_t offset)
{
  return offset;
}
#endif /* not PRECOMPUTE_SELECTORS */

/* Get element from the Sparse array `array' at offset `index' */

static inline void* sarray_get(struct sarray* array, sidx index)
{
#ifdef PRECOMPUTE_SELECTORS
  union sofftype x;
  x.idx = index;
#ifdef OBJC_SPARSE3
  return 
    array->
      indices[x.off.ioffset]->
	buckets[x.off.boffset]->
	  elems[x.off.eoffset];
#else /* OBJC_SPARSE2 */
  return array->buckets[x.off.boffset]->elems[x.off.eoffset];
#endif /* OBJC_SPARSE2 */
#else /* not PRECOMPUTE_SELECTORS */
#ifdef OBJC_SPARSE3
  return array->
    indices[index/INDEX_CAPACITY]->
      buckets[(index/BUCKET_SIZE)%INDEX_SIZE]->
	elems[index%BUCKET_SIZE];
#else /* OBJC_SPARSE2 */
  return array->buckets[index/BUCKET_SIZE]->elems[index%BUCKET_SIZE];
#endif /* not OBJC_SPARSE3 */
#endif /* not PRECOMPUTE_SELECTORS */
}

static inline void* sarray_get_safe(struct sarray* array, sidx index)
{
  if(soffset_decode(index) < array->capacity)
    return sarray_get(array, index);
  else
    return (array->empty_bucket->elems[0]);
}

#endif /* __sarray_INCLUDE_GNU */
