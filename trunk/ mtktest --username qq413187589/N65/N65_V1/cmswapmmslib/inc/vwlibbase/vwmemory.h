#ifndef __L_VWLIB_MEMORY_H__
#define __L_VWLIB_MEMORY_H__

#include "vwlibconfig.h"

#ifndef VW_ALLOC_
#define VW_ALLOC_
typedef struct VW_Alloc VW_Alloc;
#endif

typedef struct VW_AllocVtbl
{
	void	(*vwclear)  ( VW_Alloc* pThis );
	vwvoidp	(*vwalloc)  ( VW_Alloc* pThis , size_t sz );
	void	(*vwdealloc)( VW_Alloc* pThis , vwvoidp pv , size_t sz );
	/* 特别地, vwrealloc 在分配失败时pv依然有效. */
	vwvoidp (*vwrealloc)( VW_Alloc* pThis , vwvoidp pv , size_t szold , size_t sznew );
	/* optional , default( false ) , 检查分配器对象是否能被释放. */
	vw_bool	(*vwalloccanunload)( VW_Alloc* pThis );
	/* optional , default( NULL ) , 输出对象调试信息. */
	void	(*__vwdumpinfo)( VW_Alloc* pThis );
}	VW_AllocVtbl;

/*typedef struct VW_Alloc
{
	const VW_AllocVtbl*	vtbl;
}	VW_Alloc;*/  //  Modified by TIPrj[2005/6/29]
struct VW_Alloc
{
	const VW_AllocVtbl*	vtbl;
};

VW_EXTERN_C vwvoidp	VW_Alloc_Default_Realloc( VW_Alloc* pThis , vwvoidp pv , size_t szold , size_t sznew );
VW_EXTERN_C	vw_bool VW_Alloc_Default_CanUnload( VW_Alloc* pThis );
VW_EXTERN_C void	VW_Alloc_Default_DumpAllocInfo( VW_Alloc* pThis );

VW_EXTERN_C vw_bool VW_Alloc_CanUnloadNow( VW_Alloc* pThis );
VW_EXTERN_C void	__VW_Alloc_DumpAllocInfo( VW_Alloc* pThis );

VW_EXTERN_C VW_EXTERN VW_Alloc* const	VW_Default_Alloc;

VW_EXTERN_C	VW_Alloc*	VW_Heap_Alloc_Create( vwvoidp pv , size_t sz );

#ifndef __VW_HEAP_HANDLE_DECLARE__
#define __VW_HEAP_HANDLE_DECLARE__
VW_DECLARE_HANDLE( VW_Heap_Handle )
#endif

#ifndef __VW_MINI_HEAP_HANDLE_DECLARE__
#define __VW_MINI_HEAP_HANDLE_DECLARE__
VW_DECLARE_HANDLE( VW_Mini_Heap_Handle )
#endif

#define	VW_MIN_HEAP_SIZE		( 10 * 1024 )

VW_EXTERN_C VW_Heap_Handle		VW_Heap_Create ( vwvoidp pv , size_t sz );
VW_EXTERN_C vwvoidp				VW_Heap_Alloc__( VW_Heap_Handle hhp , size_t sz );
VW_EXTERN_C void				VW_Heap_Free   ( VW_Heap_Handle hhp , vwvoidp pv , size_t sz );
VW_EXTERN_C void				VW_Heap_Clear  ( VW_Heap_Handle hhp );
VW_EXTERN_C vwvoidp				VW_Heap_MemResize( VW_Heap_Handle hhp , vwvoidp pv , size_t szold , size_t sznew );
VW_EXTERN_C VWRESULT			VW_Heap_IsValidMemPtr( VW_Heap_Handle hhp , vwvoidp ptr , size_t sz );

VW_EXTERN_C	VW_Mini_Heap_Handle	VW_Mini_Heap_Create ( vwvoidp pv , size_t sz , size_t blocksize );
VW_EXTERN_C	vwvoidp				VW_Mini_Heap_Alloc__( VW_Mini_Heap_Handle hhp );	/* size_is(blocksize) */
VW_EXTERN_C	void				VW_Mini_Heap_Free	( VW_Mini_Heap_Handle hhp , vwvoidp pv );
VW_EXTERN_C void				VW_Mini_Heap_Clear	( VW_Mini_Heap_Handle hhp );
VW_EXTERN_C	size_t				VW_Mini_Heap_BlockSize( VW_Mini_Heap_Handle hhp );

#ifdef __VW_TRACE_MEMALLOC__
VW_EXTERN_C	vwvoidp	__vw_insert_alloc_info( vwvoidcp hhp , vwvoidp pv , const char* file , int line , size_t sz );
VW_EXTERN_C	void	__vw_delete_alloc_info( vwvoidcp hhp , vwvoidcp pv , size_t sz );
VW_EXTERN_C void	__vw_dump_alloc_info  ( vwvoidcp hhp , const char* func );	
VW_EXTERN_C void	__vw_clear_alloc_info ( vwvoidcp hhp );
VW_EXTERN_C void	__vw_undump_mem_info  ( vwvoidcp hhp );
#	define 	VW_Heap_Alloc( hhp , sz )	__vw_insert_alloc_info( (hhp) , VW_Heap_Alloc__( (hhp) , (sz) ) , __FILE__ , __LINE__ , (sz) )
#	define	VW_Mini_Heap_Alloc( hhp )	__vw_insert_alloc_info( (hhp) , VW_Mini_Heap_Alloc__( (hhp) ) , __FILE__ , __LINE__ ,  VW_Mini_Heap_BlockSize( hhp ) )
#else
#	define __vw_insert_alloc_info( hhp , pv , file , line , sz )		(pv)
#	define __vw_delete_alloc_info( hhp , pv , sz )						((void)0)
#	define __vw_dump_alloc_info( hhp , func )							((void)0)
#	define __vw_clear_alloc_info( hhp )									((void)0)
#	define __vw_undump_mem_info( hhp )									((void)0)
#	define VW_Heap_Alloc( hhp , sz )									VW_Heap_Alloc__( (hhp) , (sz) )
#	define VW_Mini_Heap_Alloc( hhp )									VW_Mini_Heap_Alloc__( (hhp) )
#endif

#define VW_Alloc_Clear( obj )						do {		\
		__vw_dump_alloc_info( (obj) , "VW_Alloc_Alloc" );		\
		( (obj)->vtbl->vwclear( (obj) ) );						\
		__vw_clear_alloc_info( obj );							\
	}	while( 0 )

#define VW_Alloc_Alloc__( obj , sz )					( (obj)->vtbl->vwalloc( (obj) , (sz) ) )
#define VW_Alloc_Dealloc__( obj , pv , sz )				( (obj)->vtbl->vwdealloc( (obj) , (pv) , (sz) ) )
#define VW_Alloc_Realloc__( obj , pv , szold , sznew )	( (obj)->vtbl->vwrealloc( (obj) , (pv) , (szold) , (sznew) ) )

#define VW_Alloc_Alloc( obj , sz )						__vw_insert_alloc_info( (obj) , VW_Alloc_Alloc__( (obj) , (sz) ) , __FILE__ , __LINE__ , (sz) )
#define VW_Alloc_Alloc_Type( obj , sz , type )			( (type)VW_Alloc_Alloc( obj , sz ) )

#define VW_Alloc_AllocNew( var , obj , sz )			do {		\
		(var) = VW_Alloc_Alloc( (obj) , (sz) );					\
		if( (var) ) vw_memset( (var) , 0 , (sz) );				\
	}	while( 0 )

#define VW_Alloc_Dealloc( obj , pv , sz )	do {					\
		/* free pv possible change the alloc field , so. */			\
		VW_Alloc* __palloc = (obj);									\
		size_t	  __szblock = (sz);									\
		VW_Alloc_Dealloc__( (__palloc) , (pv) , (__szblock) );		\
		__vw_delete_alloc_info( (__palloc) , (pv) , (__szblock) );	\
	}	while( 0 )

#define VW_Alloc_Realloc( obj , pv , szold , sznew )	__vw_insert_alloc_info( (obj) , VW_Alloc_Realloc__( (obj) , (pv) , (szold) , (sznew) ) , __FILE__ , __LINE__ , (sznew) )

#define VW_Alloc_Dealloc_Null( obj , pv , sz )	do {	\
		VW_Alloc_Dealloc( (obj) , (pv) , (sz) );		\
		(pv) = NULL;									\
	}	while( 0 )
		
#ifdef __VW_TRACE_MEMALLOC__
//////////////////////////////////////////////////////////////////////////
//	these function declare for hook memory leak.
typedef void ( *VW_Alloc_InsertPv_Hook_Func_Type )( vwvoidcp pv , const char* file , int line , size_t sz );
VW_EXTERN_C void	_VW_SetAllocInsertPvHookFunction( VW_Alloc_InsertPv_Hook_Func_Type func );
#else
#	define _VW_SetAllocInsertPvHookFunction( func )			((void)(func))
#endif

/* malloc , free , realloc link interface. */
VW_EXTERN_C vwvoidp		_VW_Alloc_Alloc_Memeory_DBG( VW_Alloc* alloc , size_t szAlloc , const char* file , int line );
VW_EXTERN_C	vwvoidp		_VW_Alloc_Alloc_Memeory( VW_Alloc* alloc , size_t szAlloc );
VW_EXTERN_C	void		_VW_Alloc_Free_Memory( VW_Alloc* alloc , vwvoidp pv );
VW_EXTERN_C	vwvoidp		_VW_Alloc_ReAlloc_Memory_DBG( VW_Alloc* alloc , vwvoidp pv , size_t szNew , const char* file , int line );
VW_EXTERN_C vwvoidp		_VW_Alloc_ReAlloc_Memory( VW_Alloc* alloc , vwvoidp pv , size_t szNew );

#endif