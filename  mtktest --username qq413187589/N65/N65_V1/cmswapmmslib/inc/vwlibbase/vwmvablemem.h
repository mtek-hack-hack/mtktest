#ifndef __INC_VWMVABLEMEM_H__
#define __INC_VWMVABLEMEM_H__

#include "vwmemory.h"

VW_EXTERN_C_BEGIN

#ifndef VW_MVABLE_HEAP_HANDLE_DECLARE__
VW_DECLARE_HANDLE( VW_MVABLE_HEAP_HANDLE )
#define VW_MVABLE_HEAP_HANDLE_DECLARE__
#endif

#ifndef __VWMVABLEMEMHANDLE_DECLARE__
VW_DECLARE_HANDLE( VW_MVABLE_MEM_HANDLE )
#define __VWMVABLEMEMHANDLE_DECLARE__
#endif

VW_MVABLE_HEAP_HANDLE	VW_MVAbleHeapCreate	( vwvoidp ptr , size_t heapsize , vw_bool bLoadHeap );
size_t					VW_MvAbleHeapStorage( VW_MVABLE_HEAP_HANDLE heap    );
void					VW_MvAbleHeapClean	( VW_MVABLE_HEAP_HANDLE heap    );

VW_MVABLE_MEM_HANDLE	VW_MvAbleAlloc__( VW_MVABLE_HEAP_HANDLE heap , size_t sz );
void*					VW_MvAbleLock	( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );
void					VW_MvAbleUnlock	( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );
void					VW_MvAbleFree	( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );

size_t					VW_MvAbleSize	( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );
vw_bool					VW_MvAbleLocked	( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );
size_t					VW_MvAbleHeapFreeSize( VW_MVABLE_HEAP_HANDLE heap );

#ifdef __VW_TRACE_MEMALLOC__
#	define VW_MvAbleAlloc( heap , sz )			((VW_MVABLE_MEM_HANDLE)__vw_insert_alloc_info(	heap , VW_MvAbleAlloc__( (heap) , (sz) ) , __FILE__ , __LINE__ , (sz) ))
#else
#	define VW_MvAbleAlloc( heap , sz )			((VW_MVABLE_MEM_HANDLE)VW_MvAbleAlloc__( (heap) , (sz) ))
#endif

VW_EXTERN_C_END

#endif