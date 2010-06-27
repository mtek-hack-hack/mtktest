#ifndef __L_VWLIB_DS_HASH_IMPL_H__
#define __L_VWLIB_DS_HASH_IMPL_H__

#include "vwdsbase.h"

/* do not include this file in your project.	*/

#define		VW_Hash_Impl_Invalid_Index			(0XFFFFFFFF)

typedef struct vw_hash_impl_t
{
	VW_Alloc*			alloc;
	VWDS_METHODCP		meth;
	size_t				szblock;
	size_t				szcur      , szmax;			/* assert( isprime( szmax ) ). assert( szcur * 2 <= szmax ). */
	size_t				szdel;
	vwuint8p			usedbits , delbits;			/* bits( szmax ) pack( 32b )			*/
	vwuint8p			pdata;						/* size_is( szmax * szblock ) , pack(4) */
}	vw_hash_impl;

VW_EXTERN_C	VWRESULT	VW_HashTable_Impl_Create( VW_Alloc* alloc , VWDS_METHODCP meth , vw_hash_impl* pInit , size_t szblock , size_t szinit );
VW_EXTERN_C void		VW_HashTable_Impl_Clear	( vw_hash_impl* pThis );
#define VW_HashTable_Impl_Size( pThis )			( (pThis)->szcur )
VW_EXTERN_C VWRESULT	VW_HashTable_Impl_Resize( vw_hash_impl* pThis , size_t sznew );

VW_EXTERN_C	size_t		VW_HashTable_Impl_Insert( vw_hash_impl* pThis , vwvoidcp src , vw_bool unique , vw_bool* bInsert );
VW_EXTERN_C size_t		_VW_HashTable_Impl_Insert_NoResize( vw_hash_impl* pThis , vwvoidcp src , vw_bool unique , vw_bool* bInsert );
VW_EXTERN_C vw_bool		VW_HashTable_Impl_Delete( vw_hash_impl* pThis , vwvoidcp src );
VW_EXTERN_C vw_bool		VW_HashTable_Impl_Erase ( vw_hash_impl* pThis , size_t	 it  );
/*
 *	the after 2 func return VW_Hash_Impl_Invalid_Index for element not found.  
 *	VW_HashTable_Impl_Find_N find elements at next pos of itbeg. 
 */
VW_EXTERN_C size_t		VW_HashTable_Impl_Find	( vw_hash_impl* pThis , vwvoidcp src );
VW_EXTERN_C size_t		VW_HashTable_Impl_Find_N( vw_hash_impl* pThis , vwvoidcp src , size_t itbeg );

#define VW_HashTable_Impl_Data( pThis , i )			( (pThis)->pdata + (i) * (pThis)->szblock )

VW_EXTERN_C size_t		VW_HashTable_Impl_Begin		( vw_hash_impl* pThis );
VW_EXTERN_C size_t		VW_HashTable_Impl_RBegin	( vw_hash_impl* pThis );
VW_EXTERN_C size_t		VW_HashTable_Impl_It_Next	( vw_hash_impl* pThis , size_t it );
VW_EXTERN_C size_t		VW_HashTable_Impl_It_Prev	( vw_hash_impl* pThis , size_t it );

VW_EXTERN_C VWRESULT	VW_HashTable_Impl_For_Each	( vw_hash_impl* pThis , vwds_enum_callback func );
VW_EXTERN_C VWRESULT	VW_HashTable_Impl_For_Each_A( vw_hash_impl* pThis , vwds_enum_callback_arg func , vwvoidp arg );

#endif