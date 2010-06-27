#ifndef __L_VWLIB_CFGCOMM_H__
#define __L_VWLIB_CFGCOMM_H__

#ifndef __L_VWLIB_CONFIG_H__
#	error do not include this file in your project. 
#endif

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus ) && __cplusplus
#	define		VW_CPLUSPLUS
#endif
#endif

#ifndef VW_EXTERN_C
#	if defined( VW_CPLUSPLUS )
#		define	VW_EXTERN_C	extern "C"
#	else
#		define	VW_EXTERN_C
#	endif
#endif

#ifdef VW_CPLUSPLUS
#	define	VW_EXTERN_C_BEGIN		extern "C"	{
#	define	VW_EXTERN_C_END			};
#else
#	define	VW_EXTERN_C_BEGIN
#	define	VW_EXTERN_C_END
#endif

#ifndef VW_EXTERN
#	define VW_EXTERN	extern
#endif

#ifndef VW_LOCAL
#	define VW_LOCAL		static
#endif

#ifdef __VW_FINAL_RELEASE_VERSION__
#	ifndef __VW_NTRACE_MEMALLOC__
#		define __VW_NTRACE_MEMALLOC__
#	endif
#	ifndef NDEBUG
#		define NDEBUG
#	endif
#	ifndef __VW_NDEBUG__
#		define __VW_NDEBUG__
#	endif
#	ifndef __VW_NOTRACE_INFO__
#		define __VW_NOTRACE_INFO__
#	endif
#	undef  __VW_TRACE_MEMALLOC__
#	undef  __VW_TRACE_LEVEL0__
#	undef  __VW_TRACE_LEVEL1__
#	undef  __VW_TRACE_LEVEL3__
#endif

#if !defined( VW_INLINE ) && defined( VW_COMM_INLINE_KEYWORD )
#	define VW_INLINE	__inline 
#elif !defined( VW_INLINE )
#	define VW_INLINE
#endif

#ifndef VW_WATCH_DOG
#	define VW_WATCH_DOG()			((void)0)
#endif

#if defined( __CC_ARM ) || defined( __ARM_CC )
#	define VW_ARM_CC
#	if !defined( NDEBUG )
#		define NDEBUG
#	endif
#endif

#if !defined( VW_ARM_CC ) && !defined( VW_NO_ARM_CC ) && !defined( __CC_ARM ) && !defined( __ARM_CC )
#	define VW_NO_ARM_CC
#else
#	define VW_ARM_CC
#endif

#if defined( VW_NO_ARM_CC )
#	undef	VW_ARM_CC
#endif

#ifndef __VW_DATETYPE_DEFINED__
typedef char					vwchar  ,	* vwcharp ; typedef const char*		vwcharcp;
typedef	signed		char		vwsint8 ,	*vwsint8p ;	typedef const vwsint8*	vwsint8cp;
typedef unsigned	char		vwuint8 ,	*vwuint8p ; typedef const vwuint8*	vwuint8cp;
typedef signed		short		vwsint16,	*vwsint16p; typedef const vwsint16*	vwsint16cp;
typedef unsigned	short		vwuint16,	*vwuint16p; typedef const vwuint16*	vwuint16cp;
typedef signed		long		vwsint32,	*vwsint32p; typedef const vwsint32*	vwsint32cp;
typedef unsigned	long		vwuint32,	*vwuint32p; typedef const vwuint32*	vwuint32cp;
typedef	void*					vwvoidp;				typedef const void*		vwvoidcp;
typedef	enum { vw_false , vw_true }		vw_bool;
#define __VW_DATETYPE_DEFINED__
#endif

#ifndef VW_DECLARE_HANDLE
#	define VW_DECLARE_HANDLE(name)	typedef struct { int unused; } name##__ , *name;
#endif

// define this if running on a big-endian CPU
#if !defined(IS_LITTLE_ENDIAN) && ( defined(__BIG_ENDIAN__) || defined(__BIG_ENDIAN) || defined(__sparc) || defined(__sparc__) || defined(__hppa__) || defined(__mips__) || (defined(__MWERKS__) && !defined(__INTEL__) ) )
#	define IS_BIG_ENDIAN
#endif

// define this if running on a little-endian CPU
// big endian will be assumed if IS_LITTLE_ENDIAN is not defined
#ifndef IS_BIG_ENDIAN
#	define IS_LITTLE_ENDIAN
#endif

#if defined( IS_BIG_ENDIAN ) && defined( IS_LITTLE_ENDIAN )
#	error	invalid. 
#endif

#ifndef vw_printf
#	define	vw_printf				printf
#endif

#ifndef vw_sprintf
#	define	vw_sprintf				sprintf
#endif

#ifndef vw_vsnprintf
#	define	vw_vsnprintf			_vsnprintf
#endif
	
#ifndef vw_snprintf
#	define	vw_snprintf				_snprintf
#endif

#ifndef VW_MEM_ALLOC_FUNCS_DECLARE
#	define	vw_malloc				malloc
#	define	vw_free					free
#define VW_MEM_ALLOC_FUNCS_DECLARE
#endif

#ifndef VW_MEM_STRING_FUNCS_DECLARE
#	define	vw_memcpy( dst , src , sz )		memcpy( dst , src , sz )
#	define	vw_memcmp( lhs , rhs , sz )		memcmp( lhs , rhs , sz )
#	define	vw_memset( dst , val , sz )		memset( dst , val , sz )
#	define	vw_strcpy( dst , src )			strcpy( dst , src )
#	define	vw_strncpy( dst , src , sz )	strncpy( dst , src , sz )
#	define	vw_strlen( str )				strlen( str )
#	define	vw_strstr( str , tok )			strstr( str , tok )
#	define	vw_strcat( str , s2  )			strcat( str , s2 )
#	define	vw_strncat( str , s2 , sz )		strncat( str , s2 , sz )
#	define	vw_strcmp( lhs , rhs )			strcmp( lhs , rhs )
#	define  vw_stricmp( lhs , rhs )			stricmp( lhs , rhs )
#	define	vw_strncmp( lhs , rhs , sz )	strncmp( lhs , rhs , sz )
#	define	vw_strnicmp( lhs , rhs , sz )	strnicmp( lhs , rhs , sz )
#	define	vw_strchr( str , ch )			strchr( str , ch )
#	define	vw_strrchr( str , ch )			strrchr( str , ch )
#	define  vw_memmove( lhs , rhs , sz )	memmove( lhs , rhs , sz )
#define VW_MEM_STRING_FUNCS_DECLARE
#endif

#endif