#ifndef __L_LIBPPP_H__
#define __L_LIBPPP_H__

#include <vwlibbase/vwmemory.h>

#ifndef LIBPPP_EXPORT
#	ifdef LIBPPP_CRT_LL
#		define LIBPPP_EXPORT __declspec(dllexport)
#	else
#		define LIBPPP_EXPORT __declspec(dllimport)
#	endif
#endif

typedef vwuint32					PPPSOCKET;
#define INVALID_PPPSOCKET			((PPPSOCKET)(0XFFFFFFFF))

#define	VWE_S_PPP_CLOSE_BY_REMOTE	VWMK_SUC_CODE( 10 , 100 )

VW_EXTERN_C vw_bool		LIBPPP_EXPORT _PPPConnectInit( vwcharcp comPort );	
VW_EXTERN_C void		LIBPPP_EXPORT _PPPConnectDeinit( void );

VW_EXTERN_C PPPSOCKET	LIBPPP_EXPORT _PPPSocketCreate( vw_bool bTCP );
VW_EXTERN_C void		LIBPPP_EXPORT _PPPSocketClose ( PPPSOCKET skt );
VW_EXTERN_C vw_bool		LIBPPP_EXPORT _PPPSocketReady ( PPPSOCKET skt , vw_bool bTcp );

VW_EXTERN_C vw_bool		LIBPPP_EXPORT _PPPTCPConnect( 
				PPPSOCKET				skt  ,
				vwcharcp				host ,
				vwuint16				port );

VW_EXTERN_C size_t		LIBPPP_EXPORT _PPPTCPSend(
				PPPSOCKET				skt	 ,
				vwvoidcp				buf  ,
				size_t					len	);

VW_EXTERN_C size_t		LIBPPP_EXPORT _PPPTCPRecv(
				PPPSOCKET				skt	 ,
				vwvoidp					buf  ,
				size_t					len	 ,
				VWRESULT*				vr );

VW_EXTERN_C vw_bool		LIBPPP_EXPORT _PPPUDPSendTo(
				PPPSOCKET				skt	 ,
				vwvoidcp				buf  ,
				size_t					len  ,
				struct sockaddr*		addr ,
				vwuint16				port );

VW_EXTERN_C size_t		LIBPPP_EXPORT _PPPUDPRecvFrom(
				PPPSOCKET				skt	 ,
				vwvoidp					buf  ,
				size_t					len  ,
	
	/* out */	struct in_addr*			addr_from ,
	/* out */	vwuint16*				port_from );


#endif

