/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  wap_mem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * msf_mem.c
 *
 * Created by Anders Edenbrandt, Wed Sep 26 09:33:36 2001.
 *
 *
 * Memory allocation routines, tailored for platforms
 * with scarce RAM resources.
 *
 */

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "custom_config.h"
#include "custom_wap_config.h"
#include "kal_trace.h"
#include "gv.h"
#include "tst_def.h"

#include "msf_mem.h"
#include "msf_errc.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_cmmn.h"

#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif
#ifdef __MED_MEM_POOL__
#include "..\..\media\common\include\med_utility.h"
#endif


#ifdef WAP_USE_ADM
#include "kal_adm.h"
#else /* WAP_USE_ADM */ 



#ifdef __MED_MEM_POOL__
#define WAP_USE_ASM 
#endif
#define CHUNKHEADERSIZE        (2 * sizeof(MSF_UINT32))
#define MINCHUNKSIZE           sizeof(wapadp_chunk_t)
#define MALLOC_ALIGNMENT       4
#define MALLOC_ALIGN_MASK      3
#define MINBLOCKSIZE           (12 * MINCHUNKSIZE)

typedef struct wapadp_chunk_st
{
    MSF_UINT32 prev_size;           /* Size of previous chunk.            */
    MSF_UINT32 size;                /* Size in bytes, including overhead, inuse bit is also stored here. */
    struct wapadp_chunk_st *fwd;    /* Double links -- used only if free. */
    struct wapadp_chunk_st *bck;
} wapadp_chunk_t;
typedef wapadp_chunk_t *wapadp_chunkptr;

/*
 * We use segregated free lists, with separate lists for
 * chunks of different sizes. Currently, we use sizes that are
 * powers of two.
 * In list number n is kept all the free chunks whose size is
 * strictly less than maxsizes[n].
 */
#define NUM_FREE_LISTS 10
const static MSF_UINT32 maxsizes[NUM_FREE_LISTS] = 
{
    16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0x8FFFFFFF
};

typedef struct
{
    unsigned char *baseptr;
    wapadp_chunkptr firstchunk;
    wapadp_chunkptr lastchunk;
    wapadp_chunkptr freelists[NUM_FREE_LISTS];
} wapadp_mem_internal_t;

#endif /* WAP_USE_ADM */ 

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
#define MEM_CHECK_EXTRA_SIZE(x)  (x*5/4)        /* Increase memory heap due to space overheads */
#else 
#define MEM_CHECK_EXTRA_SIZE(x)  (x)
#endif 

/* 
 * WAP_GLOBAL_MEM_SIZE is to define the size of WAP dynamic memory pool for application part, which 
 * determines the size of web page and MMS supported. If WAP_GLOBAL_MEM_SIZE is larger, then more 
 * web page or larger MMS can be displayed and supported. If WAP_GLOBAL_MEM_SIZE is defined in 
 * custom_wap_config.h, then WAP_INT_GLOBAL_MEM_SIZE equals WAP_GLOBAL_MEM_SIZE, otherwise, 
 * WAP_INT_GLOBAL_MEM_SIZE is (1024*200) by default. Customer can change this value if she want to
 * support bigger or richer web page or MMS.
 */
#ifdef WAP_GLOBAL_MEM_SIZE
#define WAP_INT_GLOBAL_MEM_SIZE WAP_GLOBAL_MEM_SIZE
#else 
#if 0
//Huyanwei Modify it For RAM Space
#define WAP_INT_GLOBAL_MEM_SIZE (1024*150)
#else
#define WAP_INT_GLOBAL_MEM_SIZE (1024*100)
#endif
#endif 

/* 
 * WAP_SYS_MEM_SIZE is to define the size of WAP dynamic memory pool for obigo system part.
 * If WAP_SYS_MEM_SIZE is defined in custom_wap_config.h, then WAP_INT_SYS_MEMSIZE equals 
 * WAP_SYS_MEM_SIZE, otherwise, WAP_INT_SYS_MEMSIZE is (1024*80) by default. Genernally, 
 * customer do not need to change this value unless "Internal Error" happen at run-time, which
 * means the memory is not enough for system.
 */
#ifdef WAP_SYS_MEM_SIZE
#define WAP_INT_SYS_MEMSIZE WAP_SYS_MEM_SIZE
#else 
#define WAP_INT_SYS_MEMSIZE (1024*80)
#endif 

#define WAP_APP_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_INT_GLOBAL_MEM_SIZE)
#define WAP_SYS_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_INT_SYS_MEMSIZE)
#define WAP_SPARE_MEM_SIZE (1024*4)

#ifdef WAP_USE_ASM
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_SPARE_MEM_SIZE)
#else 
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_APP_MEM_SIZE+WAP_SPARE_MEM_SIZE)
#endif 

#ifdef WAP_MEM_DEBUG
#ifndef __MTK_TARGET__
#define WAP_MEM_DEBUG_ENTRY_NUM 5120
#define WAP_MEM_DUMP_NAME "wap_mem_dump.log"
#else /* __MTK_TARGET__ */ 
#define WAP_MEM_DEBUG_ENTRY_NUM 512
#endif /* __MTK_TARGET__ */ 

typedef struct
{
    MSF_UINT8 modId;
    MSF_UINT32 addr;
    MSF_UINT32 size;
    MSF_UINT32 realsize;
    char filename[16];
    MSF_UINT32 lineno;
} mem_log_t;

#endif /* WAP_MEM_DEBUG */ 

/*
 * Global variables.
 */
#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif 

#ifdef WAP_USE_ADM
static KAL_ADM_ID wap_mem_pool[WAP_MEM_POOL_NUM];
#else 
static wapadp_mem_internal_t wapadp_mem_internal[WAP_MEM_POOL_NUM];
#endif 

unsigned int wap_global_mem[WAP_MEM_SIZE / 4];

#ifdef WAP_USE_ASM
void *wap_app_mem;
#endif 
void *wap_spare_mem;
unsigned int wapadp_alloc_mem[WAP_MEM_POOL_NUM];

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif 

#ifdef WAP_MEM_DEBUG
mem_log_t mlt[WAP_MEM_DEBUG_ENTRY_NUM];
MSF_UINT8 debug_modId = MSF_MODID_BRA;
unsigned int wapadp_alloc_bytes[MSF_NUMBER_OF_MODULES];
unsigned int wapadp_max_mem[WAP_MEM_POOL_NUM];
unsigned int wapadp_max_bytes[MSF_NUMBER_OF_MODULES];
#endif /* WAP_MEM_DEBUG */ 

#ifdef WAP_USE_ADM

const kal_uint32 maxsizes[11] = 
{
    16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0xffffffff, 0
};

#else /* WAP_USE_ADM */ 
/*
 * Return the number of the list that a chunk of size "n"
 * belongs to.
 */


/*****************************************************************************
 * FUNCTION
 *  list_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  n       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int list_idx(MSF_UINT32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (l = 0; maxsizes[l] <= n; l++);

    return l;
}

/*
 * Macros, rather than function calls, are used for maximum performance:
 */

/* Conversion from chunk headers to user pointers, and back */
#define chunk2mem(p)    ((void*)((unsigned char *)(p) + CHUNKHEADERSIZE))
#define mem2chunk(mem)  ((wapadp_chunkptr)((unsigned char *)(mem) - CHUNKHEADERSIZE))

/* Reading and writing of the size fields.
   The rightmost bit in the size field also
   holds the in use bit. */

#define chunksize(p)        (((p)->size & ~0x01) >> 1)

#define set_hd1(p, v)   ((p)->prev_size = (MSF_UINT32)(v))
#define set_hd2(p, v)   ((p)->size = (MSF_UINT32)(v))

/* The next and previous links */
#define prevchunk(p)    ((wapadp_chunkptr)(((unsigned char *)(p)) - p->prev_size))
#define nextchunk(p)    ((wapadp_chunkptr)(((unsigned char *)(p)) + chunksize (p)))

/* The IN USE bit */
#define chunk_isfree(p) ((((wapadp_chunkptr)(p))->size & 0x01) == 0)
#define chunk_inuse(p) ((((wapadp_chunkptr)(p))->size & 0x01) == 1)

/*
 * List operations.
 */
#define remove_from_list(p) \
  (p)->fwd->bck = (p)->bck; \
  (p)->bck->fwd = (p)->fwd;

#define add_to_list(l, p) \
  (p)->fwd = (l)->fwd;    \
  (p)->bck = l;           \
  (l)->fwd->bck = p;      \
  (l)->fwd = p;

/*
 * Compute the chunk size we will need for an allocation request:
 */
#define request2size(req)                                          \
 (((MSF_UINT32)((req) + CHUNKHEADERSIZE + MALLOC_ALIGN_MASK) <     \
  (MSF_UINT32)(MINCHUNKSIZE + MALLOC_ALIGN_MASK)) ? MINCHUNKSIZE : \
  (MSF_UINT32)(((req) + CHUNKHEADERSIZE + MALLOC_ALIGN_MASK) & ~(MALLOC_ALIGN_MASK)))

/*
 * Initialize the internal memory allocation library.
 * The first parameter indicates which module initialise
 * the memory library, the second is a pointer to a block
 * of memory and the third is the size of the memory area.
 * Returns 0 on success, and -1 otherwise.
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_internal_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 *  mem         [?]         
 *  memsize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int wapadp_mem_internal_init(MSF_UINT8 poolId, void *mem, MSF_UINT32 memsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wapadp_mem_internal_t *mod_mem;
    wapadp_chunkptr p;
    MSF_UINT32 size;
    MSF_INT16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mod_mem = &(wapadp_mem_internal[poolId]);

    /* Truncate to nearest multiple of the alignment. */
    memsize &= ~MALLOC_ALIGN_MASK;
    if ((mem == NULL) || (memsize < MINBLOCKSIZE) || (memsize > 0x7FFFFFFF))
    {
        mod_mem->baseptr = NULL;
        return -1;
    }
    mod_mem->baseptr = mem;

    /* For each of the lists of free chunks, we need one chunk to
       serve as list header. We mark each one as "in use" to avoid
       having it merged with an adjacent chunk on freeing. */
    for (i = 0; i < NUM_FREE_LISTS; i++)
    {
        p = (wapadp_chunkptr) (mod_mem->baseptr + i * MINCHUNKSIZE);
        set_hd1(p, 0);
        set_hd2(p, (MINCHUNKSIZE << 1) | 0x01);
        p->fwd = p;
        p->bck = p;
        mod_mem->freelists[i] = p;
    }

    /* This chunk starts out on the appropriate free list and
       contains all of the available memory. */
    mod_mem->firstchunk = (wapadp_chunkptr) (mod_mem->baseptr + NUM_FREE_LISTS * MINCHUNKSIZE);
    set_hd1(mod_mem->firstchunk, MINCHUNKSIZE);
    size = memsize - ((NUM_FREE_LISTS + 1) * MINCHUNKSIZE);
    set_hd2(mod_mem->firstchunk, size << 1);
    add_to_list(mod_mem->freelists[list_idx(size)], mod_mem->firstchunk);

    /* The last chunk is never placed on any list; it is marked "in use",
       and simply acts as a sentry element, when scanning all the chunks. */
    mod_mem->lastchunk = (wapadp_chunkptr) (((unsigned char*)(mod_mem->baseptr)) + memsize - MINCHUNKSIZE);
    set_hd1(mod_mem->lastchunk, size);
    set_hd2(mod_mem->lastchunk, (MINCHUNKSIZE << 1) | 0x01);

    return 0;
}

/*
 * Allocate and return a pointer to a memory area of at least
 * the indicated size. The allocated block of memory will be aligned
 * on a 4-byte boundary.
 * Returns 0 if allocation fails.
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_internal_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *wapadp_mem_internal_malloc(MSF_UINT8 poolId, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wapadp_mem_internal_t *mod_mem;
    wapadp_chunkptr p = 0, ptmp;
    MSF_UINT32 nb;

#ifdef WAP_USE_ASM
    MSF_UINT32 sz = ((poolId == WAP_APP_MEM_POOL) ? WAP_APP_MEM_SIZE : WAP_MEM_SIZE);
#else 
    MSF_UINT32 sz = WAP_MEM_SIZE;
#endif 
    MSF_UINT32 remsize;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mod_mem = &(wapadp_mem_internal[poolId]);

    if (mod_mem->baseptr == NULL)
    {
        return 0;
    }
    /* We add space for our overhead (4 bytes) plus round to nearest
       larger multiple of 4, plus never allocate a chunk less than 8 bytes. */
    nb = request2size(size);

    /* Check all relevant free lists, until a non-empty one is found. */
    for (i = list_idx(nb); i < NUM_FREE_LISTS; i++)
    {
        wapadp_chunkptr freelist = mod_mem->freelists[i];

        /* Search the entire list, select chunk with closest fit */
        for (ptmp = freelist->fwd; ptmp != freelist; ptmp = ptmp->fwd)
        {
            MSF_UINT32 tmpsz = chunksize(ptmp);

            if (tmpsz == nb)
            {   /* Exact fit: no need to search any further. */
                p = ptmp;
                sz = tmpsz;
                goto found;
            }
            else if (tmpsz > nb)
            {   /* Chunk is large enough */
                if (tmpsz < sz)
                {
                    /* This is the best so far. */
                    p = ptmp;
                    sz = tmpsz;
                }
            }
        }
        if (p != 0)
        {
            goto found;
        }
    }
    /* Searched all lists, but found no large enough chunk */
    return 0;

  found:
    /* We have found a large enough chunk, namely "p" of size "sz". */
    remove_from_list(p);
    remsize = sz - nb;

    if (remsize >= MINCHUNKSIZE)
    {
        /* The remainder is large enough to become a separate chunk */
        wapadp_chunkptr q, next;
        wapadp_chunkptr l;

        sz = nb;
        /* "q" will be the new chunk */
        q = (wapadp_chunkptr) ((unsigned char*)p + sz);
        set_hd2(q, remsize << 1);
        set_hd1(q, nb);
        next = nextchunk(q);
        next->prev_size = remsize;

        l = mod_mem->freelists[list_idx(remsize)];
        add_to_list(l, q);
    }
    set_hd2(p, (sz << 1) | 0x01);

    return chunk2mem(p);
}

/*
 * Free a memory area previously allocated with msf_mem_internal_malloc.
 * Calling this routine with 'mem' equal to 0 has no effect.
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_internal_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 *  mem         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wapadp_mem_internal_free(MSF_UINT8 poolId, void *mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wapadp_mem_internal_t *mod_mem;
    wapadp_chunkptr p;      /* chunk corresponding to mem */
    MSF_UINT32 sz;          /* its size */
    wapadp_chunkptr next;   /* next adjacent chunk */
    wapadp_chunkptr prev;   /* previous adjacent chunk */
    wapadp_chunkptr l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mod_mem = &(wapadp_mem_internal[poolId]);

    if (mem == 0 || mod_mem->baseptr == NULL)
    {
        return;
    }

    p = mem2chunk(mem);

    if (chunk_isfree(p))
    {
        return;
    }
    sz = chunksize(p);
    prev = prevchunk(p);
    next = nextchunk(p);

    if (chunk_isfree(prev))
    {   /* Join with previous chunk */
        sz += chunksize(prev);
        p = prev;
        remove_from_list(prev);
    }
    if (chunk_isfree(next))
    {   /* Join with next chunk */
        sz += chunksize(next);
        remove_from_list(next);
    }
    set_hd2(p, sz << 1);
    next = nextchunk(p);
    next->prev_size = sz;

    l = mod_mem->freelists[list_idx(sz)];
    add_to_list(l, p);
}

/*
 * Free all memory areas allocated by a module, by doing a new Initialize.
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_internal_free_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wapadp_mem_internal_free_all(MSF_UINT8 poolId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem;
    MSF_UINT32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mem = wapadp_mem_internal[poolId].baseptr;

    if (mem != NULL)
    {
        size =
            (MSF_UINT32) (((unsigned char*)(wapadp_mem_internal[poolId].lastchunk)) + MINCHUNKSIZE -
                          (unsigned char*)mem);
        wapadp_mem_internal_init(poolId, mem, size);
    }
}

#endif /* WAP_USE_ADM */ 

/**********************************************************************
 * Memory allocation
 **********************************************************************/

/*
 * Return the size of an allocated memory area.
 * The reported size includes the overhead used by the memory allocation
 * system.
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_get_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 wapadp_mem_get_size(void *mem)
{
#ifdef WAP_USE_ADM
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ADM_MB_HEAD *adm_mb_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_MEM_CHECK
    mem = (void*)((kal_uint8*) mem - sizeof(ADM_MB_LOG));
#endif 
    adm_mb_head = ADM_GET_MB_HEAD(mem);
    return (MSF_UINT32) ADM_MB_SIZE(adm_mb_head);
#else /* WAP_USE_ADM */ 
    wapadp_chunkptr p;  /* chunk corresponding to mem */
    MSF_UINT32 size;

    p = mem2chunk(mem);
    size = chunksize(p);

#ifdef WAP_USE_ASM
    ASSERT((size < WAP_MEM_SIZE || size < WAP_APP_MEM_SIZE))
#else 
    ASSERT(size < WAP_MEM_SIZE)
#endif 
        return size;
#endif /* WAP_USE_ADM */ 
}

/*
 * Allocate memory
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 *  user        [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *wapadp_mem_alloc(MSF_UINT8 poolId, MSF_UINT8 user, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *memory = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_USE_ASM
    if (poolId == WAP_APP_MEM_POOL)
    {
    ASSERT(size < WAP_APP_MEM_SIZE)}
    else
#endif /* WAP_USE_ASM */ 
        ASSERT(size < WAP_MEM_SIZE)
#ifdef WAP_USE_ADM
        if ((memory = kal_adm_alloc(wap_mem_pool[poolId], size)) == NULL)
        {
        return NULL;
        }
#else /* WAP_USE_ADM */ 
        if (((memory = wapadp_mem_internal_malloc(poolId, size)) == NULL))
    {
        /*
         * Out-of-memory handling:
         * *
         * * If the module have an exception
         * * function call it, otherwise return NULL.
         * * 
         */
        return NULL;
    }
#endif /* WAP_USE_ADM */ 

    wapadp_alloc_mem[poolId] += wapadp_mem_get_size(memory);
#ifdef WAP_MEM_DEBUG
    wapadp_max_mem[poolId] =
        ((wapadp_alloc_mem[poolId] > wapadp_max_mem[poolId]) ? wapadp_alloc_mem[poolId] : wapadp_max_mem[poolId]);
    wapadp_alloc_bytes[user] += wapadp_mem_get_size(memory);
    wapadp_max_bytes[user] =
        ((wapadp_alloc_bytes[user] > wapadp_max_bytes[user]) ? wapadp_alloc_bytes[user] : wapadp_max_bytes[user]);
#endif /* WAP_MEM_DEBUG */ 
    return memory;
}

/*
 * Free memory
 */


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 *  user        [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wapadp_mem_free(MSF_UINT8 poolId, MSF_UINT8 user, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
    {
        return;
    }

    wapadp_alloc_mem[poolId] -= wapadp_mem_get_size(p);
#ifdef WAP_MEM_DEBUG
    wapadp_alloc_bytes[user] -= wapadp_mem_get_size(p);
#endif 
#ifdef WAP_USE_ADM
    kal_adm_free(wap_mem_pool[poolId], p);
#else 
    wapadp_mem_internal_free(poolId, p);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_free_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wapadp_mem_free_all(MSF_UINT8 poolId)
{
#ifdef WAP_USE_ADM
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_delete(wap_mem_pool[poolId]);
#else /* WAP_USE_ADM */ 
    wapadp_mem_internal_free_all(poolId);
#endif /* WAP_USE_ADM */ 

#ifdef WAP_USE_ASM
    if (poolId == WAP_APP_MEM_POOL)
    {
#ifndef __MED_MEM_POOL__
        ASSERT(wap_app_mem != NULL) kal_app_mem_free(wap_app_mem);
#else
	ASSERT(wap_app_mem != NULL) med_free_ext_mem((void **)&wap_app_mem);
#endif	    

        wap_app_mem = NULL;
    }
#endif /* WAP_USE_ASM */ 
}


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wapadp_mem_init(MSF_UINT8 poolId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool debug;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_MEM_DEBUG
    memset(mlt, 0, WAP_MEM_DEBUG_ENTRY_NUM * sizeof(mem_log_t));
    memset(wapadp_alloc_bytes, 0, MSF_NUMBER_OF_MODULES * sizeof(unsigned int));
#endif /* WAP_MEM_DEBUG */ 

#ifdef WAP_MEM_CHECK
    debug = KAL_TRUE;
#else 
    debug = KAL_FALSE;
#endif 

    memset(wapadp_alloc_mem, 0, sizeof(unsigned int) * WAP_MEM_POOL_NUM);

    if (poolId == WAP_MEM_POOL)
    {
    #ifdef WAP_USE_ADM
        wap_mem_pool[poolId] = kal_adm_create(wap_global_mem, WAP_MEM_SIZE, (kal_uint32*) maxsizes, debug);
        ASSERT(wap_mem_pool[poolId])
    #else /* WAP_USE_ADM */ 
        wapadp_mem_internal_init(poolId, wap_global_mem, WAP_MEM_SIZE);
    #endif /* WAP_USE_ADM */ 
        wap_spare_mem = MSF_MEM_ALLOC(MSF_MODID_MSM, WAP_SPARE_MEM_SIZE);
    }
#ifdef WAP_USE_ASM
    else if (poolId == WAP_APP_MEM_POOL)
    {
#ifndef __MED_MEM_POOL__
	ASSERT(wap_app_mem == NULL) wap_app_mem = kal_app_mem_alloc(WAP_APP_MEM_SIZE, KAL_APPMEM_APP, MOD_WAP);
#else

    kal_prompt_trace(MOD_MMI,"sergeycao wap med_ext_left_size=%x",med_ext_left_size());
    ASSERT(wap_app_mem == NULL) wap_app_mem=med_alloc_ext_mem(WAP_APP_MEM_SIZE);
    kal_prompt_trace(MOD_MMI,"sergeycao wap after med_ext_left_size=%x",med_ext_left_size());
#endif
	
   //     ASSERT(wap_app_mem == NULL) wap_app_mem = kal_app_mem_alloc(WAP_APP_MEM_SIZE, KAL_APPMEM_APP, MOD_WAP);
    #ifdef WAP_USE_ADM
        wap_mem_pool[poolId] = kal_adm_create(wap_app_mem, WAP_APP_MEM_SIZE, (kal_uint32*) maxsizes, debug);
        ASSERT(wap_mem_pool[poolId])
    #else /* WAP_USE_ADM */ 
        wapadp_mem_internal_init(poolId, wap_app_mem, WAP_APP_MEM_SIZE);
    #endif /* WAP_USE_ADM */ 
    }
#endif /* WAP_USE_ASM */ 
}


/*****************************************************************************
 * FUNCTION
 *  wapadp_mem_enable_spare_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wapadp_mem_enable_spare_mem(MSF_UINT8 poolId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_MSM, wap_spare_mem);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mem_balance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  poolId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int wap_mem_balance(MSF_UINT8 poolId)
{
#ifdef WAP_USE_ASM
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (poolId == WAP_APP_MEM_POOL)
    {
        return (int)(WAP_APP_MEM_SIZE - wapadp_alloc_mem[poolId]);
    }
#endif /* WAP_USE_ASM */ 
    return (int)(WAP_MEM_SIZE - wapadp_alloc_mem[poolId]);
}

#ifdef WAP_MEM_DEBUG


/*****************************************************************************
 * FUNCTION
 *  wap_set_mem_debug_mod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_set_mem_debug_mod(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    debug_modId = modId;
    memset(mlt, 0, WAP_MEM_DEBUG_ENTRY_NUM * sizeof(mem_log_t));
}


/*****************************************************************************
 * FUNCTION
 *  wap_mem_debug
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  mem_log     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mem_debug(MSF_UINT8 modId, const char *mem_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char alloc;
    char filename[32];
    unsigned int addr, lognum, size, realsize, id, lineno;
    void *memory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (debug_modId != modId)
    {
        return;
    }
#endif /* __MTK_TARGET__ */ 

    sscanf(mem_log, "MEM: %c", &alloc);

    if (alloc == '+')
    {
        /* memory allocation */
        int i;

        /* "MEM: + 0xb3e094      0    112     0 msf_signal.c (99)"; */
        sscanf(mem_log, "MEM: %c %x %d %d %d %s (%d)", &alloc, &addr, &lognum, &size, &id, filename, &lineno);

        /*
         * size += 12; // SIZE_OF_HEAD 
         * size += 8;  // DEBUG OVERHEAD
         * size = request2size (size); // CHUNKSIZE
         */
    #if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
        memory = (void*)((char*)addr - (12 + 4));
    #else 
        memory = (void*)((char*)addr - 12);
    #endif 
        realsize = wapadp_mem_get_size(memory);

        for (i = 0; i < WAP_MEM_DEBUG_ENTRY_NUM; i++)
        {
            if (mlt[i].addr == 0)
            {
                mlt[i].modId = id;
                mlt[i].addr = addr;
                mlt[i].size = size + 12 /* SIZE OF HEAD */ ;
                mlt[i].realsize = realsize;
                mlt[i].lineno = lineno;
                strcpy(mlt[i].filename, filename);
                break;
            }
        }
    }
    else
    {
        /* memory free */
        int i;

        /* MEM: - 0xb3e094      0            0 msf_signal.c (99) */
        sscanf(mem_log, "MEM: %c %x", &alloc, &addr);
        for (i = 0; i < WAP_MEM_DEBUG_ENTRY_NUM; i++)
        {
            if (mlt[i].addr == addr)
            {
                mlt[i].addr = 0;
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mem_debug_dump_catcher
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mem_debug_dump_catcher(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WAP_MEM_DEBUG_ENTRY_NUM; i++)
    {
        if (mlt[i].addr != 0)
        {
            char s[128];

            sprintf(
                s,
                "Module(%d), %#08x, %6d(%6d), %s(%d)\n",
                mlt[i].modId,
                mlt[i].addr,
                mlt[i].size,
                mlt[i].realsize,
                mlt[i].filename,
                mlt[i].lineno);
            s[127] = '\0';
            kal_prompt_trace(MOD_WAP, "%s", s);
        }
    }
}

#ifndef __MTK_TARGET__


/*****************************************************************************
 * FUNCTION
 *  wap_mem_debug_dump_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mem_debug_dump_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    FILE *f = fopen(WAP_MEM_DUMP_NAME, "w");
    unsigned int mod_overhead[MSF_NUMBER_OF_MODULES];
    unsigned int entry_num[MSF_NUMBER_OF_MODULES];
    unsigned int mod_alloc[MSF_NUMBER_OF_MODULES];
    unsigned int overhead = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mod_overhead, 0, sizeof(unsigned int) * MSF_NUMBER_OF_MODULES);
    memset(entry_num, 0, sizeof(unsigned int) * MSF_NUMBER_OF_MODULES);
    memset(mod_alloc, 0, sizeof(unsigned int) * MSF_NUMBER_OF_MODULES);

    for (j = 0; j < MSF_NUMBER_OF_MODULES; j++)
    {
        for (i = 0; i < WAP_MEM_DEBUG_ENTRY_NUM; i++)
        {
            if (mlt[i].addr != 0 && j == mlt[i].modId)
            {
                fprintf(
                    f,
                    "Module(%d), %#08x, %6d(%6d), %s(%d)\n",
                    mlt[i].modId,
                    mlt[i].addr,
                    mlt[i].size,
                    mlt[i].realsize,
                    mlt[i].filename,
                    mlt[i].lineno);
                entry_num[mlt[i].modId]++;
                mod_overhead[mlt[i].modId] += (mlt[i].realsize - mlt[i].size);
                overhead += (mlt[i].realsize - mlt[i].size);
                mod_alloc[mlt[i].modId] += mlt[i].realsize;
            }
        }
        fprintf(f, "statistics:\n");
        fprintf(f, "module(%2d): %3d, %6d, %6d\n\n", j, entry_num[j], mod_overhead[j], mod_alloc[j]);
    }
    fprintf(f, "Total: %d\n", overhead);
    fclose(f);
}
#endif /* __MTK_TARGET__ */ 

#endif /* WAP_MEM_DEBUG */ 

