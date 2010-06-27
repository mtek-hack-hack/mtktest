#ifndef __L_VWLIB_STRING_H__
#define __L_VWLIB_STRING_H__

#include "vwmemory.h"

/*
 *	VW_String : 带长度前缀的字符串,NULL 为空串. !ptr && *src 为失败.
 *  | length | data ( size_is( length ) ) | \0 |
 *			 * <--- PTR.
 */
typedef		vwcharp				VW_String_It;
typedef		vwcharcp			VW_String_CIt;

typedef		vwcharcp			VW_RawString;
typedef		vwcharp				VW_String;
typedef		vwcharcp			VW_CString;
typedef		vwcharp				VW_String_Buffer;
typedef		vwcharcp			VW_CString_Buffer;

VW_EXTERN_C	VW_String			VW_String_Create ( VW_Alloc* alloc , const char* src );
VW_EXTERN_C	VW_String			VW_String_Create2( VW_Alloc* alloc , VW_String_CIt beg , VW_String_CIt end );
VW_EXTERN_C VW_String			VW_String_Clone	 ( VW_Alloc* alloc , VW_String src );
VW_EXTERN_C	void				VW_String_Destroy( VW_Alloc* alloc , VW_String str );
VW_EXTERN_C	size_t				VW_String_Length ( VW_String str );

/*
 *	VW_String_Buffer : 带最大长度和当前长度前缀的字符串, NULL为非法.
 *	VW_String_Buffer 也是一个合法的 VW_String.
 *	| max_size | length | data( length_is( length ) , size_is( max_size ) | \0 |
 *						* <--- PTR.
 */
VW_EXTERN_C	VW_String_Buffer	VW_StringBuf_Create		( VW_Alloc* alloc , size_t	maxsz );
VW_EXTERN_C VW_String_Buffer	VW_StringBuf_CreateAt	( vwvoidp   ptr   , size_t	ptrlen	);
VW_EXTERN_C	void				VW_StringBuf_Destroy	( VW_Alloc* alloc , VW_String_Buffer str );
VW_EXTERN_C	size_t				VW_StringBuf_MaxSize	( VW_String_Buffer str );
/* use for this lib only. */
VW_EXTERN_C	VWRESULT			_VW_StringBuf_Adjust	( VW_String_Buffer str );

VW_EXTERN_C VW_EXTERN VW_CString	VW_NullString;

VW_EXTERN_C	VWRESULT			VW_StringBuf_Copy_	( VW_String_Buffer str , VW_RawString	src );
VW_EXTERN_C	VWRESULT			VW_StringBuf_Copy	( VW_String_Buffer str , VW_CString		src );
VW_EXTERN_C	VWRESULT			VW_StringBuf_Copy2	( VW_String_Buffer str , VW_String_CIt	beg , VW_String_CIt end );
VW_EXTERN_C	VWRESULT			VW_StringBuf_Format	( VW_String_Buffer str , VW_RawString	fmt , ... );

VW_EXTERN_C	VWRESULT			VW_StringBuf_Join_	( VW_String_Buffer str , VW_RawString	src );
VW_EXTERN_C	VWRESULT			VW_StringBuf_Join	( VW_String_Buffer str , VW_CString		src );
VW_EXTERN_C	VWRESULT			VW_StringBuf_Join2	( VW_String_Buffer str , VW_String_CIt	beg , VW_String_CIt end );
VW_EXTERN_C	VWRESULT			VW_StringBuf_JoinA	( VW_String_Buffer str , VW_RawString	fmt , ... );

VW_EXTERN_C	void				VW_StringBuf_TrimLeft	( VW_String_Buffer str );
VW_EXTERN_C	void				VW_StringBuf_TrimRight	( VW_String_Buffer str );
VW_EXTERN_C	void				VW_StringBuf_Trim		( VW_String_Buffer str );
VW_EXTERN_C VW_String_It		VW_String_Trim_Left_	( VW_RawString	   str );
VW_EXTERN_C	VW_String_It		VW_String_Trim_Right_	( VW_RawString	   str );

#define VW_StringBuf_SubStr( str , n )			VWVERIFYOK( VW_StringBuf_Copy_ ( (str) , ( (str) + (n) ) ) )

#define	VW_StringBuf_SubStr_Trim( str , n )		do {			\
		VW_StringBuf_SubStr( str , n );							\
		VW_StringBuf_TrimLeft( str );							\
	}	while( 0 )

VW_EXTERN_C	VW_String_It		VW_String_Strrchr ( VW_CString	  str , int ch );
VW_EXTERN_C	VW_String_It		VW_String_Strrstr_( VW_CString	  str , VW_RawString tok );
VW_EXTERN_C	VW_String_It		VW_String_FindOne_( VW_RawString  str , VW_RawString tok );

VW_EXTERN_C	vw_bool				VW_String_Equal	  ( VW_CString	  lhs , VW_CString	 rhs );
VW_EXTERN_C	vw_bool				VW_String_NotEqual( VW_CString	  lhs , VW_CString	 rhs );
VW_EXTERN_C	int					VW_String_Strcmp  ( VW_CString	  lhs , VW_CString   rhs );
VW_EXTERN_C	int					VW_String_Strncmp ( VW_CString    lhs , VW_CString   rhs , size_t sz );

#endif
