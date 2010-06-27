#include "ut.h"

#ifdef __cplusplus
extern "C" {
#endif

/* HEAP FUNCTIONS
 *
 * These are memory heap functions, used for thread-local memory
 * management.
 */

typedef struct ut_Heap_s ut_Heap;

/* creation */

/* create a new heap able to hold at least size. */
extern ut_Heap *
ut_Heap_new
(u32 size);

/* destroy a heap. */
extern ut_Heap *
ut_Heap_dispose
(ut_Heap *heap);

/* query and manipulate */

/* return notional heap size. */
extern u32
ut_Heap_size
(ut_Heap *heap);

/* assign heap's next pointer and return heap. */
extern ut_Heap *
ut_Heap_link
(ut_Heap *heap, ut_Heap *next);

/* return heap's next pointer. */
extern ut_Heap *
ut_Heap_next
(ut_Heap *heap);

/* set heap's released flag. */
extern void
ut_Heap_release
(ut_Heap *heap, utb released);

/* get heap's release flag. */
extern utb
ut_Heap_released
(ut_Heap *heap);

/* allocation */

/* test whether heap can hold amount (=> 1); a tidy may help. */
extern utb
ut_Heap_test
(ut_Heap *heap, u32 amount);

/* allocate amount; a tidy may help. */
extern void *
ut_Heap_alloc
(ut_Heap *heap, u32 amount);

/* reallocate data to be able to hold amount on heap.
 * frees data only on success. may not move it if already big enough. */
extern void *
ut_Heap_realloc
(ut_Heap *heap, void *data, u32 amount);

/* reallocate data to be able to hold amount with malloc.
 * frees data only on success. */
extern void *
ut_Heap_remalloc
(void *data, u32 amount);

/* free data. */
extern void
ut_Heap_free
(void *data);

/* tidy heap; combines adjacent free blocks. */
extern u32
ut_Heap_tidy
(ut_Heap *heap);

/* statistics */

/* get total free space. some may not be available. */
extern u32
ut_Heap_getFree
(ut_Heap *heap);

/* get total used space. */
extern u32
ut_Heap_getUsed
(ut_Heap *heap);

/* get total available space. */
extern u32
ut_Heap_getAvailable
(ut_Heap *heap);

/* get free blocks. */
extern u32
ut_Heap_getFreeBlocks
(ut_Heap *heap);

/* get used blocks. */
extern u32
ut_Heap_getUsedBlocks
(ut_Heap *heap);

/* get available blocks. */
extern u32
ut_Heap_getAvailableBlocks
(ut_Heap *heap);

#ifdef __cplusplus
}
#endif
