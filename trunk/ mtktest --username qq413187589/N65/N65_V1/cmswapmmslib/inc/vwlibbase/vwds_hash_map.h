#include "_vwds_hash_impl.h"

typedef struct vw_hash_map_t
{
	vw_hash_impl		key_hash;
	vwuint32p			index_buf;	/* size_is( key_hash.szmax ) */
	vwuint8p			val_buf;	/* size_is( key_hash.szmax ) * sz_val_block */
	vwuint8p			usedbits;	/* bits_is( key_hash.szmax ) , pack( 32b ) */
	size_t				szvalblock;
	VWDS_METHODCP		val_meth;
}	vw_hash_map;

typedef vw_hash_map	vw_hash_multi_map;

#define VW_Hash_Map_Key( type , pThis , it )	( (type)( VW_HashTable_Impl_Data( &(pThis)->key_hash , (it) ) ) )
#define VW_Hash_Map_KeyRef( type , pThis , it )	( *(type*)( VW_HashTable_Impl_Data( &(pThis)->key_hash , (it) ) ) )
#define VW_Hash_Map_Value( type , pThis , it )	( (type)( (pThis)->val_buf + ( (pThis)->index_buf[ (it) ] ) * (pThis)->szvalblock ) )
#define VW_Hash_Map_ValueRef( type , pThis , it )	( *(type*)( (pThis)->val_buf + ( (pThis)->index_buf[ (it) ] ) * (pThis)->szvalblock ) )
#define VW_Hash_Map_Size( pThis )				( (pThis)->key_hash.szcur )
#define VW_Hash_Map_Invalid_Index				VW_Hash_Impl_Invalid_Index

VW_EXTERN_C VWRESULT	VW_Hash_Map_Create( VW_Alloc* alloc , VWDS_METHODCP key_meth , VWDS_METHODCP val_meth , 
										 vw_hash_map* pInit , size_t szkeyblock , size_t szvalblock , size_t szinit );

VW_EXTERN_C void		VW_Hash_Map_Clear ( vw_hash_map* pThis );
VW_EXTERN_C VWRESULT	VW_Hash_Map_Resize( vw_hash_map* pThis , size_t sznew );

VW_EXTERN_C size_t		VW_Hash_Map_Insert( vw_hash_map* pThis , vwvoidcp key , vwvoidcp val , vw_bool *bInsert );
VW_EXTERN_C vw_bool		VW_Hash_Map_Delete( vw_hash_map* pThis , vwvoidcp key );
VW_EXTERN_C vw_bool		VW_Hash_Map_Erase ( vw_hash_map* pThis , size_t	  it  );

#define VW_Hash_Map_Find( pThis , key )			VW_HashTable_Impl_Find( &(pThis)->key_hash , (key) )
#define VW_Hash_Map_Begin( pThis )				VW_HashTable_Impl_Begin( &(pThis)->key_hash )
#define VW_Hash_Map_RBegin( pThis )				VW_HashTable_Impl_RBegin( &(pThis)->key_hash )
#define VW_Hash_Map_It_Next( pThis , it )		VW_HashTable_Impl_It_Next( &(pThis)->key_hash , (it) )
#define VW_Hash_Map_It_Prev( pThis , it )		VW_HashTable_Impl_It_Prev( &(pThis)->key_hash , (it) )

typedef VWRESULT ( *vsds_enum_map_callback )( VW_Alloc* alloc , vwvoidp key , vwvoidp val , size_t szkey , size_t szval );
typedef VWRESULT ( *vsds_enum_map_callback_arg )( VW_Alloc* alloc , vwvoidp key , vwvoidp val , size_t szkey , size_t szval , vwvoidp arg );

VW_EXTERN_C VWRESULT	VW_Hash_Map_For_Each( vw_hash_map* pThis , vsds_enum_map_callback func );
VW_EXTERN_C VWRESULT	VW_Hash_Map_For_Each_A( vw_hash_map* pThis , vsds_enum_map_callback_arg func , vwvoidp arg );

#define VW_Hash_Multi_Map_Key( type , pThis , it )				VW_Hash_Map_Key( (type) , (pThis) , (it) )
#define VW_Hash_Multi_Map_KeyRef( type , pThis , it )			VW_Hash_Map_KeyRef( (type) , (pThis) , (it) )
#define VW_Hash_Multi_Map_Value( type , pThis , it )			VW_Hash_Map_Value( (type) , (pThis) , (it) )
#define VW_Hash_Multi_Map_ValueRef( type , pThis , it )			VW_Hash_Map_ValueRef( (type) , (pThis) , (it) )
#define VW_Hash_Multi_Map_Size( pThis )							VW_Hash_Map_Size( (pThis) )
#define VW_Hash_Multi_Map_Create( alloc , km , vm , pp , szk , szv , szi )		\
				VW_Hash_Map_Create( (alloc) , (km) , (vm) , (pp) , (szk) , (szv) , (szi) )

#define VW_Hash_Multi_Map_Clear( pThis )						VW_Hash_Map_Clear( (pThis) )
#define VW_Hash_Multi_Map_Resize( pThis , sznew )				VW_Hash_Map_Resize( ( pThis ) , (sznew) )

VW_EXTERN_C size_t		VW_Hash_Multi_Map_Insert( vw_hash_map* pThis , vwvoidcp key , vwvoidcp val , vw_bool *bInsert );

#define VW_Hash_Multi_Map_Delete( pThis , key )					VW_Hash_Map_Delete( (pThis) , (key) )
#define VW_Hash_Multi_Map_Erase( pThis , it )					VW_Hash_Map_Erase( (pThis) , (it) )

#define VW_Hash_Multi_Map_Find( pThis , key )					VW_Hash_Map_Find( (pThis) , (key) )
#define VW_Hash_Multi_Map_Find_N( pThis , key , it )			VW_HashTable_Impl_Find_N( &(pThis)->key_hash , (key) , (it) )

#define VW_Hash_Multi_Map_Begin( pThis )						VW_Hash_Map_Begin( (pThis) )
#define VW_Hash_Multi_Map_RBegin( pThis )						VW_Hash_Map_RBegin( (pThis) )
#define VW_Hash_Multi_Map_It_Next( pThis , it )					VW_Hash_Map_It_Next( (pThis) , (it) )
#define VW_Hash_Multi_Map_It_Prev( pThis , it )					VW_Hash_Map_It_Prev( (pThis) , (it) )

#define VW_Hash_Multi_Map_For_Each( pThis , func )				VW_Hash_Map_For_Each( (pThis) , (func) )
#define VW_Hash_Multi_Map_For_Each_A( pThis , func , arg )		VW_Hash_Map_For_Each_A( (pThis) , (func) , (arg) )