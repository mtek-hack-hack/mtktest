#ifndef __L_VWLIB_MVABLEMEMORY_H__
#define __L_VWLIB_MVABLEMEMORY_H__

#include "vwmemory.h"

#ifndef VW_MM_MAX_ALLOC_COUNT
#define VW_MM_MAX_ALLOC_COUNT		(128)
#endif

#ifndef VW_MM_MIN_HEAP_SIZE
#define VW_MM_MIN_HEAP_SIZE			( 5 * 1024 )
#endif

typedef struct vw_mmstat
{
	vwuint32	mmszpadding	: 8;			/* 0 - 7. */
	vwuint32	mmsize		: 24;			/* pack(8)... 0 for not alloc memory.   */
	vwuint32	offset;
} vw_mmstat;

typedef struct vw_mmfreelist
{
	size_t		szblock;		/* .ge. 8 , include this struct.		*/
	vwuint32	nextoffset;		/* next block offset.					*/
}	vw_mmfreelist;

#define VW_MD5_CHECK_OFFSET		28

typedef struct vw_mm_heap
{
	vwuint32			mm_dummy_zero[2];
	/*
	 * store md5 check number. 
	 */
	vwuint8				mm_md5_check_number[16];
	/*
	 * data length.
	 */
	vwuint32			mm_store_data_len;
#define VW_MVABLE_MAGIC_NUM1		(0XABCDEABC)
	vwuint32			mm_magic_num1;
	vw_mmstat			mmstat[ VW_MM_MAX_ALLOC_COUNT ];		/* index 0 reserved. */
#define VW_MVABLE_MAGIC_NUM2		(0X12345678)
	vwuint32			mm_magic_num2;
	size_t				mmszmax , mmszcur , szblock;			/* */
	vwuint32			mmfirstfreelistoffset;					/* 0 for no free memory. */
#define VW_MVABLE_MAGIC_NUM3		(0X87654321)
	vwuint32			mm_magic_num3;
	vw_bool				mmlocked;
	vwuint32			mmlockindex;
#define VW_MVABLE_MAGIC_NUM4		(0XCBAEDCBA)
	vwuint32			mm_magic_num4;
}	vw_mm_heap;

#ifndef VW_MVABLE_HEAP_HANDLE_DECLARE__
typedef vw_mm_heap*		VW_MVABLE_HEAP_HANDLE;
#define VW_MVABLE_HEAP_HANDLE_DECLARE__
#endif

#ifndef __VWMVABLEMEMHANDLE_DECLARE__
typedef vwuint32		VW_MVABLE_MEM_HANDLE;
#define __VWMVABLEMEMHANDLE_DECLARE__
#endif

#define VW_MM_VALID_PAD( heap , hm )		( (heap)->mmstat[ (hm) ].mmszpadding < 8 )

#include "vwmvablemem.h"

VW_EXTERN_C_BEGIN

vw_bool					_VW_MVAbleHeapCheckValid	( VW_MVABLE_HEAP_HANDLE heap , size_t heapsize );
VWRESULT				_VW_MVAbleHeapInitNew		( VW_MVABLE_HEAP_HANDLE heap , size_t heapsize );
VWRESULT				_VW_MVAbleHeapAdjust		( VW_MVABLE_HEAP_HANDLE heap );
VW_MVABLE_MEM_HANDLE	_VW_MvAbleAlloc_raw			( VW_MVABLE_HEAP_HANDLE heap , size_t sz );
void					_VW_MvAbleFree_raw			( VW_MVABLE_HEAP_HANDLE heap , VW_MVABLE_MEM_HANDLE hm );
vw_bool					_VW_MvAbleHeapCheckLocked	( VW_MVABLE_HEAP_HANDLE heap );
size_t					_VW_MvAbleHeapInitSize		( VW_MVABLE_HEAP_HANDLE heap );

void					_VW_MvAbleAlloc_Freelist_Check( VW_MVABLE_HEAP_HANDLE heap );

VW_EXTERN_C_END

#endif