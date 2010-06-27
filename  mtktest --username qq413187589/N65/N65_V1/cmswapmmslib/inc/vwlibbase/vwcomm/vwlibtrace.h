#ifndef __L_VWLIB_TRACE_H__
#define __L_VWLIB_TRACE_H__

#ifndef __L_VWLIB_CONFIG_H__
#	error do not include this file in your project. 
#endif

/*
 *	trace info level :
 *		0 : important	trace info.
 *		1 : normal		trace info.
 *		2 : unimportant trace info.
 *		3 : just use for this library. 
 */
#ifndef VW_USE_USER_TRACE_FUNC
VW_EXTERN_C	void __vw_trace__( const char* fmt , ... );
#elif !defined ( __vw_trace__ )
#	define		 __vw_trace__	vw_printf
#endif
VW_EXTERN_C	void __vw_assert__( const char* expr , const char* file , int line );
VW_EXTERN_C	void __vw_trace_data__( vwvoidcp data, size_t len );

#if	!defined( __VW_TRACE_LEVEL0__ ) && !defined( __VW_TRACE_LEVEL1__ ) && !defined( __VW_TRACE_LEVEL2__ )
#	if  !defined( NDEBUG ) && !defined( __VW_NOTRACE_INFO__ )
#		define __VW_TRACE_LEVEL2__
#	elif defined( NDEBUG ) && !defined( __VW_NOTRACE_INFO__ )
#		define __VW_TRACE_LEVEL0__
#	endif
#endif

#if defined( __VW_TRACE_LEVEL3__ ) && !defined( __VW_TRACE_LEVEL2__ )
#	define __VW_TRACE_LEVEL2__
#endif

#if defined( __VW_TRACE_LEVEL2__ ) && !defined( __VW_TRACE_LEVEL1__ )
#	define	__VW_TRACE_LEVEL1__
#endif

#if defined( __VW_TRACE_LEVEL1__ ) && !defined( __VW_TRACE_LEVEL0__ )
#	define	__VW_TRACE_LEVEL0__
#endif

#if defined( VW_ARM_CC ) && !defined( __VW_NDEBUG__ )
#	undef  __VW_DEBUG__
#	define __VW_NDEBUG__
#endif

#if !defined( __VW_DEBUG__ ) && !defined( __VW_NDEBUG__ )
#	if !defined( NDEBUG )
#		define	__VW_DEBUG__
#	else
#		define	__VW_NDEBUG__
#	endif
#endif

#ifdef __VW_NDEBUG__
#	undef	__VW_DEBUG__
#endif

#if  !defined( __VW_NDEBUG__ )
#	define	VWASSERT( expr )	( (void)( (expr) || (__vw_assert__( #expr, __FILE__ , __LINE__), 0 ) ) )
#	define	VWVERIFY( expr )	VWASSERT( expr )
#	define	VWVERIFYOK( expr )	VWVERIFY( (expr) >= 0 )
#	define	VWDBGONLY( expr )	((void)(expr))
#else
#	define	VWASSERT( expr )	((void)0)
#	define	VWVERIFY( expr )	((void)(expr))
#	define	VWVERIFYOK( expr )	((void)(expr))
#	define	VWDBGONLY( expr )	((void)0)
#endif

#ifdef __VW_TRACE_LEVEL0__

#	define	VW_TRACE_RAW1( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a )
#	define	VW_TRACE_RAW2( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a , b )
#	define	VW_TRACE_RAW3( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a , b , c )
#	define	VW_TRACE_RAW4( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a , b , c , d )
#	define	VW_TRACE_RAW5( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a , b , c , d , e )
#	define	VW_TRACE_RAW6( fmt , a , b , c , d , e , f )	__vw_trace__( fmt , a , b , c , d , e , f )
#	define	VW0TRACEDATA( data , len )						__vw_trace_data__( (data) , (len) )

#else

#	define	VW_TRACE_RAW1( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW_TRACE_RAW2( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW_TRACE_RAW3( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW_TRACE_RAW4( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW_TRACE_RAW5( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW_TRACE_RAW6( fmt , a , b , c , d , e , f )	((void)0)
#	define	VW0TRACEDATA( data , len )						((void)0)

#endif

#	define		VW0TRACE0( a )								VW_TRACE_RAW1( "%s" , a , 0 , 0 , 0 , 0 , 0 )
#	define		VW0TRACE1( fmt , a )						VW_TRACE_RAW1( fmt ,  a , 0 , 0 , 0 , 0 , 0 )
#	define		VW0TRACE2( fmt , a , b )					VW_TRACE_RAW2( fmt ,  a , b , 0 , 0 , 0 , 0 )
#	define		VW0TRACE3( fmt , a , b , c )				VW_TRACE_RAW3( fmt ,  a , b , c , 0 , 0 , 0 )
#	define		VW0TRACE4( fmt , a , b , c , d )			VW_TRACE_RAW4( fmt ,  a , b , c , d , 0 , 0 )
#	define		VW0TRACE5( fmt , a , b , c , d , e )		VW_TRACE_RAW5( fmt ,  a , b , c , d , e , 0 )
#	define		VW0TRACE6( fmt , a , b , c , d , e , f )	VW_TRACE_RAW6( fmt ,  a , b , c , d , e , f )

#ifdef __VW_TRACE_LEVEL1__

#	define		VW1TRACE0( a )								VW_TRACE_RAW1( "%s" , a , 0 , 0 , 0 , 0 , 0 )
#	define		VW1TRACE1( fmt , a )						VW_TRACE_RAW1( fmt ,  a , 0 , 0 , 0 , 0 , 0 )
#	define		VW1TRACE2( fmt , a , b )					VW_TRACE_RAW2( fmt ,  a , b , 0 , 0 , 0 , 0 )
#	define		VW1TRACE3( fmt , a , b , c )				VW_TRACE_RAW3( fmt ,  a , b , c , 0 , 0 , 0 )
#	define		VW1TRACE4( fmt , a , b , c , d )			VW_TRACE_RAW4( fmt ,  a , b , c , d , 0 , 0 )
#	define		VW1TRACE5( fmt , a , b , c , d , e )		VW_TRACE_RAW5( fmt ,  a , b , c , d , e , 0 )
#	define		VW1TRACE6( fmt , a , b , c , d , e , f )	VW_TRACE_RAW6( fmt ,  a , b , c , d , e , f )
#	define		VW1TRACEDATA( data , len )					__vw_trace_data__( (data) , (len) )

#else

#	define		VW1TRACE0( a )								((void)0)
#	define		VW1TRACE1( fmt , a )						((void)0)
#	define		VW1TRACE2( fmt , a , b )					((void)0)
#	define		VW1TRACE3( fmt , a , b , c )				((void)0)
#	define		VW1TRACE4( fmt , a , b , c , d )			((void)0)
#	define		VW1TRACE5( fmt , a , b , c , d , e )		((void)0)
#	define		VW1TRACE6( fmt , a , b , c , d , e , f )	((void)0)
#	define		VW1TRACEDATA( data , len )					((void)0)

#endif

#ifdef __VW_TRACE_LEVEL2__

#	define		VW2TRACE0( a )								VW_TRACE_RAW1( "%s" , a , 0 , 0 , 0 , 0 , 0 )
#	define		VW2TRACE1( fmt , a )						VW_TRACE_RAW1( fmt ,  a , 0 , 0 , 0 , 0 , 0 )
#	define		VW2TRACE2( fmt , a , b )					VW_TRACE_RAW2( fmt ,  a , b , 0 , 0 , 0 , 0 )
#	define		VW2TRACE3( fmt , a , b , c )				VW_TRACE_RAW3( fmt ,  a , b , c , 0 , 0 , 0 )
#	define		VW2TRACE4( fmt , a , b , c , d )			VW_TRACE_RAW4( fmt ,  a , b , c , d , 0 , 0 )
#	define		VW2TRACE5( fmt , a , b , c , d , e )		VW_TRACE_RAW5( fmt ,  a , b , c , d , e , 0 )
#	define		VW2TRACE6( fmt , a , b , c , d , e , f )	VW_TRACE_RAW6( fmt ,  a , b , c , d , e , f )
#	define		VW2TRACEDATA( data , len )					__vw_trace_data__( (data) , (len) )

#else

#	define		VW2TRACE0( a )								((void)0)
#	define		VW2TRACE1( fmt , a )						((void)0)
#	define		VW2TRACE2( fmt , a , b )					((void)0)
#	define		VW2TRACE3( fmt , a , b , c )				((void)0)
#	define		VW2TRACE4( fmt , a , b , c , d )			((void)0)
#	define		VW2TRACE5( fmt , a , b , c , d , e )		((void)0)
#	define		VW2TRACE6( fmt , a , b , c , d , e , f )	((void)0)
#	define		VW2TRACEDATA( data , len )					((void)0)

#endif

#ifdef __VW_TRACE_LEVEL3__

#	define		VW3TRACE0( a )								VW_TRACE_RAW1( "%s" , a , 0 , 0 , 0 , 0 , 0 )
#	define		VW3TRACE1( fmt , a )						VW_TRACE_RAW1( fmt ,  a , 0 , 0 , 0 , 0 , 0 )
#	define		VW3TRACE2( fmt , a , b )					VW_TRACE_RAW2( fmt ,  a , b , 0 , 0 , 0 , 0 )
#	define		VW3TRACE3( fmt , a , b , c )				VW_TRACE_RAW3( fmt ,  a , b , c , 0 , 0 , 0 )
#	define		VW3TRACE4( fmt , a , b , c , d )			VW_TRACE_RAW4( fmt ,  a , b , c , d , 0 , 0 )
#	define		VW3TRACE5( fmt , a , b , c , d , e )		VW_TRACE_RAW5( fmt ,  a , b , c , d , e , 0 )
#	define		VW3TRACE6( fmt , a , b , c , d , e , f )	VW_TRACE_RAW6( fmt ,  a , b , c , d , e , f )
#	define		VW3TRACEDATA( data , len )					__vw_trace_data__( (data) , (len) )

#else

#	define		VW3TRACE0( a )								((void)0)
#	define		VW3TRACE1( fmt , a )						((void)0)
#	define		VW3TRACE2( fmt , a , b )					((void)0)
#	define		VW3TRACE3( fmt , a , b , c )				((void)0)
#	define		VW3TRACE4( fmt , a , b , c , d )			((void)0)
#	define		VW3TRACE5( fmt , a , b , c , d , e )		((void)0)
#	define		VW3TRACE6( fmt , a , b , c , d , e , f )	((void)0)
#	define		VW3TRACEDATA( data , len )					((void)0)

#endif

#if !defined(__VW_TRACE_MEMALLOC__) && !defined( __VW_NTRACE_MEMALLOC__) && defined( __VW_TRACE_LEVEL1__ ) && ( defined( _MSC_VER ) || defined( __GNUC__ ) )
#	define	__VW_TRACE_MEMALLOC__
#endif

#ifdef __VW_NTRACE_MEMALLOC__
#	undef	__VW_TRACE_MEMALLOC__
#endif

#endif