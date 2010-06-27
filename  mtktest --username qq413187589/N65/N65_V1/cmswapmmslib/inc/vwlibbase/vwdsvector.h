#ifndef __L_VWLIB_DS_VECTOR_H__
#define __L_VWLIB_DS_VECTOR_H__

#include "vwdsbase.h"

/*
 *	incr block size = ( sz = curr / VW_DS_VECTOR_INCR_PT , 
 *						sz = min( sz , VW_DS_VECTOR_MAX_INCR ) , 
 *						sz = max( sz , VW_DS_VECTOR_MIN_INCR ) );
 */
#define		VW_DS_VECTOR_MIN_INCR		(8)
#define		VW_DS_VECTOR_MAX_INCR		(128)
#define		VW_DS_VECTOR_INCR_PT		(4)

typedef struct vw_vector_t 
{
	VW_Alloc*		alloc;
	VWDS_METHODCP	meth;
	size_t			szblock;
	vwuint8p		itFirst , itLast , itEnd;
}	vw_vector;

VW_EXTERN_C VWRESULT	VW_Vector_Create	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_vector* pInit , size_t blocksz , size_t szinit );
VW_EXTERN_C VWRESULT	VW_Vector_Create2	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_vector* pInit , size_t blocksz , vwvoidcp beg , vwvoidcp end );
VW_EXTERN_C size_t		VW_Vector_Size		( const vw_vector* pThis );
VW_EXTERN_C size_t		VW_Vector_Capacity	( const vw_vector* pThis );
VW_EXTERN_C void		VW_Vector_Clear		( vw_vector* pThis );

#define VW_Vector_GetAt( pThis , index )	( (vwvoidp)( (pThis)->itFirst + (index) * (pThis)->szblock ) )
#define VW_Vector_GetAtPtr( type , pThis , index )	( (type)VW_Vector_GetAt( (pThis) , (index) ) )
#define VW_Vector_GetAtRef( type , pThis , index )	( *(type)VW_Vector_GetAt( (pThis) , (index) ) )

VW_EXTERN_C	VWRESULT	VW_Vector_Resize	( vw_vector* pThis , size_t newsz );

VW_EXTERN_C VWRESULT	VW_Vector_PushBack	( vw_vector* pThis , vwvoidcp src );
VW_EXTERN_C VWRESULT	VW_Vector_PushBack_N( vw_vector* pThis , vwvoidcp src , size_t n );
VW_EXTERN_C VWRESULT	VW_Vector_PushBack_R( vw_vector* pThis , vwvoidcp beg , vwvoidcp end );

VW_EXTERN_C VWRESULT	VW_Vector_PopBack	( vw_vector* pThis );
VW_EXTERN_C void		VW_Vector_EraseEnd	( vw_vector* pThis , vwvoidp beg );

VW_EXTERN_C vwvoidp		VW_Vector_Begin		( const vw_vector* pThis );
VW_EXTERN_C vwvoidp		VW_Vector_End		( const vw_vector* pThis );

VW_EXTERN_C vwvoidp		VW_Vector_It_Next	( const vw_vector* pThis , vwvoidcp it );
VW_EXTERN_C vwvoidp		VW_Vector_It_Prev	( const vw_vector* pThis , vwvoidcp it );
VW_EXTERN_C vwvoidp		VW_Vector_It_Advance( const vw_vector* pThis , vwvoidcp it , int n );

VW_EXTERN_C	void		VW_Vector_Sort		( vw_vector* pThis );

VW_EXTERN_C VWRESULT	VW_Vector_For_Each	( vw_vector* pThis , vwds_enum_callback func );
VW_EXTERN_C VWRESULT	VW_Vector_For_Each_A( vw_vector* pThis , vwds_enum_callback_arg func , vwvoidp arg );

#endif