/****************************************************************************/
/*                                                                          */
/*   MOBILESOFT CHINA (CMS) SYSTEMS, INC.                                   */
/*                WIRELESS APPLICATION DESIGN CENTER (NANJING CHINA)        */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*   CMS CONFIDENTIAL AND PROPRIETARY                                       */
/*                                                                          */
/*   This source is the sole property of CMS Systems, Inc. Reproduction     */
/*   or utilization of this source in whole or in part is forbidden without */
/*   the written consent of CMS Systems, Inc.                               */
/*                                                                          */
/*   (c) Copyright CMS Systems, Inc., 2000.  All Rights Reserved.           */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*   cmsSSL_base.h                                                          */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   07/01/05   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_BASE_H__
#define __CMSSSL_BASE_H__

#include <vwlibbase/vwmemory.h>
#include <vwlibbase/vwstring.h>

/*
 * compile openssl with these options.
 *	-DOPENSSL_NO_KRB5 -DOPENSSL_NO_ENGINE -DOPENSSL_NO_ERR 
 *  -DOPENSSL_NO_SOCK -DGETPID_IS_MEANINGLESS -DOPENSSL_NO_LOCKING
 */

#ifndef OPENSSL_NO_KRB5
#	define OPENSSL_NO_KRB5
#endif

#ifndef OPENSSL_NO_ENGINE
#	define OPENSSL_NO_ENGINE
#endif

#ifndef OPENSSL_NO_ERR
#	define OPENSSL_NO_ERR
#endif

#ifndef OPENSSL_NO_SOCK
#	define OPENSSL_NO_SOCK
#endif

#ifndef GETPID_IS_MEANINGLESS
#	define GETPID_IS_MEANINGLESS
#endif

#ifndef OPENSSL_NO_LOCKING
#	define OPENSSL_NO_LOCKING
#endif

#if !defined( VW_ARM_CC ) && ( defined( WIN32 ) || defined( WIN64 ) || defined( _MSC_VER ) )
#	define CMS_TLS_USE_HEAP_MEMORY_FUNCTION
#endif

VW_EXTERN_C_BEGIN

/*
 *	set cmsTls1Alloc or use VW_Default_Alloc.
 */
//#define		cmsTls1Alloc		((VW_Alloc*)cms_get_heap_handle())
VW_EXTERN	VW_Alloc*			cmsTls1Alloc;

typedef size_t	( *cms_Socket_Send_Data_Functype )( vwvoidcp buf , size_t sz );

#define	CMS_TLS_HANDSHAKE_SUCC			(200)
#define	CMS_TLS_FAIL					(201)
#define CMS_TLS_CLOSE_BY_SERVER			(202)

/* msg in ( CMS_TLS_HANDSHAKE_SUCC , CMS_TLS_FAIL , CMS_TLS_CLOSE_BY_SERVER ) */
typedef VWRESULT ( *cms_Tls_SendMessage_Func )( vwuint32 msg );

VW_EXTERN	cms_Tls_SendMessage_Func		cmsTlsSendMsgCallBack;

#define cmsSSL_SendHandShake_Succ()			((void)( cmsTlsSendMsgCallBack && cmsTlsSendMsgCallBack( CMS_TLS_HANDSHAKE_SUCC ) ) )
#define cmsSSL_SendFail()					((void)( cmsTlsSendMsgCallBack && cmsTlsSendMsgCallBack( CMS_TLS_FAIL ) ) )
#define	cmsSSL_SendCloseByServer()			((void)( cmsTlsSendMsgCallBack && cmsTlsSendMsgCallBack( CMS_TLS_CLOSE_BY_SERVER ) ) )

/*
 *	set send data function after call cms_SSL_Initialize immediately.
 */
cms_Socket_Send_Data_Functype	cms_SSL_Set_Send_Data_Func( cms_Socket_Send_Data_Functype func );

/*
 *	message call back.
 */
cms_Tls_SendMessage_Func		cms_SSL_Set_SendMessage_Func( cms_Tls_SendMessage_Func func );

/*
 *	RFC2246 Page17 , The length should not exceed 2^14 + 2048 ext data.
 */
#define	cmsSSL_MAX_PACKAGE_SIZE			( ( 16 + 2 ) * 1024 )

/*
 *	send data buffer.
 */
#define cmsSSL_TMP_BUF_SIZE				( 8 * 1024 )

/*
 *	ssl_subsystem initialize.
 */
VWRESULT	cms_SSL_Initialize( vwvoidp reserved );

/*
 *	ssl_subsystem cleanup.
 */
void		cms_SSL_Uninitialize( void );

/*
 *	^_^
 */
#define cms_SSL_Socket_Close()			(VWE_S_FALSE)

/* init recv buffer. */
void		cms_SSL_Recv_Buffer_Init	( void );

/* */
VWRESULT	cms_SSL_Socket_On_Recv_Data ( vwvoidcp buf , size_t len );

/*
 *	send data.
 */
VWRESULT	cms_SSL_Socket_Send ( vwvoidcp buf , size_t len );

struct cms_ssl_wb_tmp_buf
{
	size_t			sz;
	vwuint8			buf[ cmsSSL_TMP_BUF_SIZE ];	
};

VW_EXTERN struct	cms_ssl_wb_tmp_buf		cms_ssl_wb_buf;

#define cms_ssl_wb_clr()				((void)( cms_ssl_wb_buf.sz = 0 ))
#define cms_ssl_wb_new( ptr , lenptr , type )	do {			\
			ptr  = cms_ssl_wb_buf.buf + cms_ssl_wb_buf.sz;		\
			ptr[0] = (type); ptr[1] = 0X03; ptr[2] = 0X01;		\
			lenptr = ptr + 3;									\
			ptr += 5;											\
	}	while( 0 )
#define cms_ssl_wb_add( ptr , buf , len )			do {		\
			vw_memcpy( ptr , buf , len );						\
			ptr += len;											\
	}	while( 0 )
#define cms_ssl_wb_addb( ptr , by )		((void)(*(ptr++) = (by)))
#define cms_ssl_wb_adds( ptr , s  )		do { s2n( s , ptr ); } while( 0 )
#define cms_ssl_wb_addl( ptr , l  )		do { l2n( l , ptr ); } while( 0 )

#define cms_ssl_wb_len( ptr , lenptr )	do {					\
			vwuint16	__t_len = ptr - lenptr - 2;				\
			s2n( __t_len , lenptr );							\
	}	while( 0 )

#define cms_ssl_wb_end( ptr , lenptr )	do {					\
			vwuint16	__t_len = ptr - lenptr - 2;				\
			s2n( __t_len , lenptr );							\
			cms_ssl_wb_buf.sz += __t_len + 5;					\
	}	while( 0 )

#define cms_ssl_wb_send( vr )			do {										\
			(vr) = cms_SSL_Socket_Send( cms_ssl_wb_buf.buf , cms_ssl_wb_buf.sz );	\
			cms_ssl_wb_buf.sz = 0;													\
	}	while( 0 )


#define SSLERROR_SKT_TYPE				(0X10)

#define SSLE_SKT_TOO_MANY_CONN		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0001 )
#define SSLE_SKT_INVALID_PORT		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0002 )
#define SSLE_SKT_INVALID_HOST		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0003 )
#define SSLE_SKT_CRT_SKT_FAIL		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0004 )
#define SSLE_SKT_CONNECT_FAIL		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0005 )
#define SSLE_SKT_SENDDATA_FAIL		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0006 )
#define SSLE_SKT_RECVDATA_FAIL		VWMK_ERROR_CODE( SSLERROR_SKT_TYPE , 0X0007 )

VW_EXTERN_C_END

#endif

