#ifndef __L_VWLIB_CFGUSER_H__
#define __L_VWLIB_CFGUSER_H__

#ifndef __L_VWLIB_CONFIG_H__
#	error do not include this file in your project. 
#endif

#ifndef __VW_NO_USE_CMS_COMM_FUNC__

#include "cms_debug.h"
#include "cms_sysfun.h"

/* 关闭所有的 TRACE , LOG , MEMCHECK 版本. */
#ifdef CMS_RELEASE
#	define __VW_FINAL_RELEASE_VERSION__
#endif

/* 内存错误检查*/
#if !defined( __VW_FINAL_RELEASE_VERSION__ ) && !defined( CMS_NMEM_CHECK )
#	define VW_MEM_FUNC_CHECK_DECL
#endif

#define VW_WATCH_DOG()			cms_watchdog()

/* armcc gcc cl icl support __inline keyword */
#define VW_COMM_INLINE_KEYWORD
#define VW_INLINE	__inline

#define	VW_USE_USER_TRACE_FUNC
#define	vw_printf	cms_trace

/* define trace level here. */
/*
#if !defined( __VW_TRACE_LEVEL0__ ) && !defined( __VW_TRACE_LEVEL1__ ) && !defined( __VW_TRACE_LEVEL2__ )
#	if  !defined( NDEBUG ) && !defined( __VW_NOTRACE_INFO__ )
#		define __VW_TRACE_LEVEL2__
#	elif defined( NDEBUG ) && !defined( __VW_NOTRACE_INFO__ )
#		define __VW_TRACE_LEVEL0__
#	endif
#endif
*/

#ifndef VW_MEM_ALLOC_FUNCS_DECLARE
#	define	vw_malloc				cms_malloc
#	define	vw_free					cms_free
#define VW_MEM_ALLOC_FUNCS_DECLARE
#endif

#ifndef VW_MEM_STRING_FUNCS_DECLARE
#	define	vw_memcpy( dst , src , sz )		cms_memcpy( dst , src , sz )
#	define	vw_memcmp( lhs , rhs , sz )		cms_memcmp( lhs , rhs , sz )
#	define	vw_memset( dst , val , sz )		cms_memset( dst , val , sz )
#	define	vw_strcpy( dst , src )			cms_strcpy( dst , src )
#	define	vw_strncpy( dst , src , sz )	cms_strncpy( dst , src , sz )
#	define	vw_strlen( str )				cms_strlen( str )
#	define	vw_strstr( str , tok )			cms_strstr( str , tok )
#	define	vw_strcat( str , s2  )			cms_strcat( str , s2 )
#	define	vw_strncat( str , s2 , sz )		cms_strncat( str , s2 , sz )
#	define	vw_strcmp( lhs , rhs )			cms_strcmp( lhs , rhs )
#	define  vw_stricmp( lhs , rhs )			cms_stricmp( lhs , rhs )
#	define	vw_strncmp( lhs , rhs , sz )	cms_strncmp( lhs , rhs , sz )
#	define	vw_strnicmp( lhs , rhs , sz )	cms_strnicmp( lhs , rhs , sz )
#	define	vw_strchr( str , ch )			cms_strchr( str , ch )
#	define	vw_strrchr( str , ch )			cms_strrchr( str , ch )
#	define  vw_memmove( lhs , rhs , sz )	cms_memmove( lhs , rhs , sz )
#define VW_MEM_STRING_FUNCS_DECLARE
#endif

#endif	/* __VW_NO_USE_CMS_COMM_FUNC__ */

#endif
