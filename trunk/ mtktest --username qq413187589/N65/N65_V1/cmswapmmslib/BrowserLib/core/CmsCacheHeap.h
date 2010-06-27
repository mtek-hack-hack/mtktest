/*****************************************************************************
    Copyright (c) 2001-2002 MobileSoft Corporation All Rights Reserved.
    
    Created:	    2005-2-24  	
	Author:         Thunis; zhenghaip@mobilesoft.com.cn
    File name:      CmsCacheHeap.h
    File ext:       h file 
	
	purpose:		½Ó¿Ú
    History:
*******************************************************************************/


#ifndef _CMS_CACHEHEAP_H_
#define _CMS_CACHEHEAP_H_


typedef void* VW_MVABLE_HEAP_HANDLE;
typedef void* VW_MVABLE_MEM_HANDLE;


typedef  VW_MVABLE_HEAP_HANDLE CACHE_HANDLE;
typedef  VW_MVABLE_MEM_HANDLE  CACHEFILE_HANDLE;

extern CACHE_HANDLE	VW_MVAbleHeapCreate	( void* ptr , unsigned int heapsize , int bLoadHeap );
extern unsigned int	VW_MvAbleHeapStorage ( CACHE_HANDLE heap    );
extern void					VW_MvAbleHeapClean	( CACHE_HANDLE heap    );

extern CACHEFILE_HANDLE	VW_MvAbleAlloc__( CACHE_HANDLE heap , unsigned int sz );
extern void*					VW_MvAbleLock	( CACHE_HANDLE heap , CACHEFILE_HANDLE hm );
extern void					VW_MvAbleUnlock	( CACHE_HANDLE heap , CACHEFILE_HANDLE hm );
extern void					VW_MvAbleFree	( CACHE_HANDLE heap , CACHEFILE_HANDLE hm );

extern unsigned int					VW_MvAbleSize	( CACHE_HANDLE heap , CACHEFILE_HANDLE hm );
extern int					VW_MvAbleLocked	( CACHE_HANDLE heap , CACHEFILE_HANDLE hm );
extern unsigned int					VW_MvAbleHeapFreeSize( CACHE_HANDLE heap );

#define CacheHeap_Create VW_MVAbleHeapCreate
#define CacheHeap_Store  VW_MvAbleHeapStorage
#define CacheHeap_Clean  VW_MvAbleHeapClean
#define CacheHeap_Malloc VW_MvAbleAlloc__
#define CacheHeap_Lock   VW_MvAbleLock
#define CacheHeap_UnLock VW_MvAbleUnlock
#define CacheHeap_Free   VW_MvAbleFree
#define CacheHeap_Size   VW_MvAbleSize
#define CacheHeap_IsLocked VW_MvAbleLocked
#define CacheHeap_LeftSize VW_MvAbleHeapFreeSize


#endif