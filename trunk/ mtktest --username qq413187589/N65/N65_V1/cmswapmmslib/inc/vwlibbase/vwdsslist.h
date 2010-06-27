#ifndef __L_VWLIB_DS_SLIST_H__
#define __L_VWLIB_DS_SLIST_H__

#include "vwdsbase.h"

typedef struct vw_slist_node_t
{
	struct vw_slist_node_t *	next;
	vwuint8						data[4];	/* size_is( szblock ) , pack( 4 ) */
}	vw_slist_node ,	*vw_slist_it;

#define	VW_SList_Data( type , it )		( (type)( (it)->data ) )
#define VW_SList_DataRef( type , it )	( *(type*)( (it)->data ) )

typedef struct vw_slist_t
{
	VW_Alloc*		alloc;
	VWDS_METHODCP	meth;
	size_t			szblock;
	vw_slist_node*	lsthead;
	size_t			szdata;
	size_t			sznode;	/* szblock + sizeof( vw_slist_node_t * ) , pack( 4 ) */
}	vw_slist;

VW_EXTERN_C	VWRESULT	VW_SList_Create	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_slist* pInit , size_t szblock );

VW_EXTERN_C VWRESULT	VW_SList_Create2( VW_Alloc* alloc , VWDS_METHODCP meth , vw_slist* pInit , size_t szblock , 
										  vwvoidcp  beg , vwvoidcp end );

VW_EXTERN_C void		VW_SList_Clear	( vw_slist* pThis );

#define	VW_SList_Size( pThis )			( (pThis)->szdata )
#define VW_SList_Begin( pThis )			( (pThis)->lsthead )
#define	VW_SList_End( pThis )			(NULL)

#define VW_SList_It_Next( pThis , it )	((it)->next)

VW_EXTERN_C vw_slist_it	VW_SList_InsertAfter( vw_slist* pThis , vw_slist_it it , vwvoidcp src );
VW_EXTERN_C VWRESULT	VW_SList_InsertAfter_R ( vw_slist* pThis , vw_slist_it it , vwvoidcp beg , vwvoidcp end );
VW_EXTERN_C vw_slist_it	VW_SList_PushFront	( vw_slist* pThis , vwvoidcp src );

VW_EXTERN_C void		VW_SList_PopFront	( vw_slist* pThis );
VW_EXTERN_C void		VW_SList_Erase		( vw_slist* pThis , vw_slist_it pre , vw_slist_it beg , vw_slist_it end );

VW_EXTERN_C	VWRESULT	VW_SList_For_Each	( vw_slist* pThis , vwds_enum_callback func );
VW_EXTERN_C VWRESULT	VW_SList_For_Each_A	( vw_slist* pThis , vwds_enum_callback_arg func , vwvoidp arg );

#endif