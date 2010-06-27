#ifndef __T_VWLIB_MEMHEAP_H__
#define __T_VWLIB_MEMHEAP_H__

#ifndef __L_VWLIB_CONFIG_H__
#include "vwlibconfig.h"
#endif

#ifdef __L_VWLIB_MEMORY_H__
#	error #include "vwmemory.h" is invalid.
#endif

/*
 *	do not include this file in your project.
 */
typedef union __VW_MemPool_Link __VW_MemPool_Link;
typedef union __VW_MemPool_Link
{
	__VW_MemPool_Link*	next;		/* link list in memory pool */
	vwuint32			data[1];	/* user data */
}	__VW_MemPool_Link;

typedef union	__VW_MemBlock_Link __VW_MemBlock_Link;
typedef struct	__VW_FreeMemNode
{	
	__VW_MemBlock_Link*		next;		/*	link to next free memory block. */
	size_t					blocksize;	/*	memory block size. include node size. */
}	__VW_FreeMemNode;

typedef union	__VW_MemBlock_Link
{
	__VW_FreeMemNode		block;	/* memory block size .ge. 8 */
	vwuint32				data[2];	
}	__VW_MemBlock_Link;

typedef struct  __VW_Valid_MemoryRangeRcd
{
	/* [ minptr , maxptr ) */
	vwuint8p	minptr , maxptr;
}	__VW_Valid_MemoryRangeRcd;


#ifndef __VW_HEAP_HANDLE_DECLARE__
#define __VW_HEAP_HANDLE_DECLARE__

typedef struct 
{
	/*
	 *	use for memory pool.
	 */
	__VW_MemPool_Link		mempool[16];
	
	/*
	 *	free memory link list.
	 */
	__VW_MemBlock_Link*		freememlist;
	size_t					memrefcount; /* 分配计数. */

	/*
	 *	valid memory record.
	 */
	__VW_Valid_MemoryRangeRcd	rcdList[4];

	/*
	 *	有其他未记录的内存地址范围.
	 */
	vw_bool						bextmemory;

	/*
	 *	错误的内存状态.
	 */
	vw_bool						bfatalerror;	
}	VW_Heap_Handle_t , VW_Heap_Handle__ , *VW_Heap_Handle , *VW_Heap_Handle_tp;


#endif	/* __VW_HEAP_HANDLE_DECLARE__ */

#ifndef __VW_MINI_HEAP_HANDLE_DECLARE__
#define __VW_MINI_HEAP_HANDLE_DECLARE__

typedef	struct
{
	__VW_MemPool_Link		pool;
	size_t					blocksize;
}	VW_Mini_Heap_Handle_t , *VW_Mini_Heap_Handle , *VW_Mini_Heap_Handle_tp;

#endif	/* __VW_MINI_HEAP_HANDLE_DECLARE__ */

#endif