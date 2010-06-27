#ifndef __L_VWLIB_DS_HASH_SET_H__
#define __L_VWLIB_DS_HASH_SET_H__

#include "_vwds_hash_impl.h"

typedef vw_hash_impl	vw_hash_set;
typedef vw_hash_impl	vw_hash_multi_set;

#define	VW_Hash_Set_Invalid_Index										VW_Hash_Impl_Invalid_Index

#define VW_Hash_Set_Data( type , pThis , it )							\
	( (type)VW_HashTable_Impl_Data( ( pThis ) , (it) ) )

#define VW_Hash_Set_DataRef( type , pThis , it )						\
	( *(type*)VW_HashTable_Impl_Data( (pThis) , (it) ) )

#define VW_Hash_Set_Create( alloc , meth , pInit , szblock , szinit )	\
	VW_HashTable_Impl_Create( ( alloc ) , ( meth ) , (pInit) , ( szblock ) , ( szinit ) )

#define VW_Hash_Set_Clear( pThis )										\
	VW_HashTable_Impl_Clear( ( pThis ) )

#define VW_Hash_Set_Size( pThis )										\
	VW_HashTable_Impl_Size( ( pThis ) )

#define VW_Hash_Set_Resize( pThis , sznew )								\
	VW_HashTable_Impl_Resize( ( pThis ) , ( sznew ) )

#define VW_Hash_Set_Insert( pThis , src , bInsert )						\
	VW_HashTable_Impl_Insert( ( pThis ) , ( src ) , ( vw_true ) , ( bInsert ) )

#define VW_Hash_Set_Delete( pThis , src )								\
	VW_HashTable_Impl_Delete( ( pThis ) , ( src ) )

#define VW_Hash_Set_Erase( pThis , it )									\
	VW_HashTable_Impl_Erase( ( pThis ) , ( it ) )

#define VW_Hash_Set_Find( pThis , src )									\
	VW_HashTable_Impl_Find( ( pThis ) , ( src ) )

#define VW_Hash_Set_Begin( pThis )										\
	VW_HashTable_Impl_Begin( ( pThis ) )

#define VW_Hash_Set_RBegin( pThis )										\
	VW_HashTable_Impl_RBegin( ( pThis ) )

#define VW_Hash_Set_It_Next( pThis , it )								\
	VW_HashTable_Impl_It_Next( (pThis) , (it) )

#define VW_Hash_Set_It_Prev( pThis , it )								\
	VW_HashTable_Impl_It_Prev( ( pThis ) , ( it ) )

#define VW_Hash_Set_For_Each( pThis , func )							\
	VW_HashTable_Impl_For_Each( ( pThis ) , ( func ) )

#define VW_Hash_Set_For_Each_A( pThis , func , arg )					\
	VW_HashTable_Impl_For_Each_A( ( pThis ) , ( func ) , ( arg ) )

#define VW_Hash_MultiSet_Invalid_Index									VW_Hash_Impl_Invalid_Index

#define VW_Hash_MultiSet_Data( type , pThis , it )								\
	( (type)VW_HashTable_Impl_Data( ( pThis ) , (it) ) )

#define VW_Hash_MultiSet_DataRef( type , pThis , it )							\
	( *(type*)VW_HashTable_Impl_Data( ( pThis ) , (it) ) )

#define VW_Hash_MultiSet_Create( alloc , meth , pInit , szblock , szinit )		\
	VW_HashTable_Impl_Create( ( alloc ) , ( meth ) , ( pInit ) , ( szblock ) , ( szinit ) )

#define VW_Hash_MultiSet_Clear( pThis )											\
	VW_HashTable_Impl_Clear( ( pThis ) )

#define VW_Hash_MultiSet_Size( pThis )											\
	VW_HashTable_Impl_Size( ( pThis ) )

#define VW_Hash_MultiSet_Resize( pThis , sznew )								\
	VW_HashTable_Impl_Resize( ( pThis ) , ( sznew ) )

#define VW_Hash_MultiSet_Insert( pThis , src , bInsert )						\
	VW_HashTable_Impl_Insert( ( pThis ) , ( src ) , ( vw_false ) , ( bInsert ) )

#define VW_Hash_MultiSet_Delete( pThis , src )									\
	VW_HashTable_Impl_Delete( ( pThis ) , ( src ) )

#define VW_Hash_MultiSet_Erase( pThis , it )									\
	VW_HashTable_Impl_Erase( ( pThis ) , ( it ) )

#define VW_Hash_MultiSet_Find( pThis , src )									\
	VW_HashTable_Impl_Find( ( pThis ) , ( src ) )

#define VW_Hash_MultiSet_Find_N( pThis , src , it )								\
	VW_HashTable_Impl_Find_N( ( pThis ) , ( src ) , ( it ) )

#define VW_Hash_MultiSet_Begin( pThis )											\
	VW_HashTable_Impl_Begin( ( pThis ) )

#define VW_Hash_MultiSet_RBegin( pThis )										\
	VW_HashTable_Impl_RBegin( ( pThis ) )

#define VW_Hash_MultiSet_It_Next( pThis , it )									\
	VW_HashTable_Impl_It_Next( (pThis) , (it) )

#define VW_Hash_MultiSet_It_Prev( pThis , it )									\
	VW_HashTable_Impl_It_Prev( ( pThis ) , ( it ) )

#define VW_Hash_MultiSet_For_Each( pThis , func )								\
	VW_HashTable_Impl_For_Each( ( pThis ) , ( func ) )

#define VW_Hash_MultiSet_For_Each_A( pThis , func , arg )						\
	VW_HashTable_Impl_For_Each_A( ( pThis ) , ( func ) , ( arg ) )

#endif

