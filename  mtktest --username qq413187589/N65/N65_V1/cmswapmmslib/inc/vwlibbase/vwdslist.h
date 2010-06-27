#ifndef __L_VWLIB_DS_LIST_H__
#define __L_VWLIB_DS_LIST_H__

#include "vwdsbase.h"

typedef struct vw_list_node_t
{
	struct vw_list_node_t *	next , *prev;
	vwuint8					data[4];		/* size_is( szblock ) , pack( 4 ). */
}	vw_list_node , *vw_list_it;

#define VW_List_Data( type , it )		( (type)( (it)->data ) )
#define VW_List_DataRef( type , it )	( *(type*)( (it)->data ) )

typedef struct vw_list_t
{
	VW_Alloc*		alloc;
	VWDS_METHODCP	meth;
	size_t			szblock;
	vw_list_node	lsthead;	/* data field not used. */
	vw_list_node	lstend;
	size_t			szdata , sznode;	
}	vw_list;

VW_EXTERN_C VWRESULT	VW_List_Create	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_list* pInit , size_t szblock );
VW_EXTERN_C VWRESULT	VW_List_Create2	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_list* pInit , size_t szblock ,
										  vwvoidcp	beg , vwvoidcp end );

VW_EXTERN_C	void		VW_List_Clear	( vw_list* pThis );

#define	VW_List_Size( pThis )			( (pThis)->szdata )
#define VW_List_Begin( pThis )			( (pThis)->lsthead.next )
#define VW_List_End( pThis )			( &( (pThis)->lstend ) )
#define VW_List_RBegin( pThis )			( (pThis)->lstend.prev )
#define VW_List_REnd( pThis )			( &( (pThis)->lsthead ) )

#define VW_List_It_Next( pThis , it )	((it)->next)
#define VW_List_It_Prev( pThis , it )	((it)->prev)

VW_EXTERN_C vw_list_it	VW_List_InsertAfter	( vw_list* pThis , vw_list_it it , vwvoidcp src );
VW_EXTERN_C vw_list_it	VW_List_InsertBefore( vw_list* pThis , vw_list_it it , vwvoidcp src );
VW_EXTERN_C VWRESULT	VW_List_InsertBefore_R( vw_list* pThis , vw_list_it it , vwvoidcp beg , vwvoidcp end );
VW_EXTERN_C VWRESULT	VW_List_InsertAfter_R ( vw_list* pThis , vw_list_it it , vwvoidcp beg , vwvoidcp end );

VW_EXTERN_C vw_list_it	VW_List_PushBack	( vw_list* pThis , vwvoidcp src );
VW_EXTERN_C vw_list_it	VW_List_PushFront	( vw_list* pThis , vwvoidcp src );
VW_EXTERN_C void		VW_List_PopBack		( vw_list* pThis );
VW_EXTERN_C void		VW_List_PopFront	( vw_list* pThis );

VW_EXTERN_C void		VW_List_Erase		( vw_list* pThis , vw_list_it beg , vw_list_it end );
VW_EXTERN_C VWRESULT	VW_List_For_Each	( vw_list* pThis , vwds_enum_callback func );
VW_EXTERN_C VWRESULT	VW_List_For_Each_A	( vw_list* pThis , vwds_enum_callback_arg func , vwvoidp arg );

#endif