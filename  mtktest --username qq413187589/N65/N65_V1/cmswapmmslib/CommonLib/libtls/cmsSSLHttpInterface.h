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
/*   cmsSSLHttpInterface.h                                                  */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   08/01/05   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSLHTTPINTERFACE_H__
#define __CMSSSLHTTPINTERFACE_H__

#include "cmsSSL_stream.h"

VW_EXTERN_C_BEGIN

VWRESULT	cms_Openssl_Lib_Init( void );
void		cms_Openssl_Lib_Deinit( void );

VWRESULT	cms_SSL_Initialize( vwvoidp reserved );
void		cms_SSL_Uninitialize( void );

VWRESULT	cms_SSL_Tls_Set_Callback_Funcs( 
					cms_Tls_SendMessage_Func		func_msg,
					cms_Socket_Send_Data_Functype	func_send,
					cms_SSL_App_Data_Callback		func_recv_data );

VWRESULT	cms_SSL_Socket_On_Recv_Data ( vwvoidcp buf , size_t len );
vwuint32	cms_ConvHostAddr2int	( const char* host );
VWRESULT	cms_SSL_Begin_HandShake	( VW_RawString host , vwuint16 port , cmsSSL_Handshake_Stat_Changed_callback func );
VWRESULT	cms_SSL_Write			( vwvoidcp buf , size_t len );
void		cms_SSL_Close			( vw_bool bSktClose , vw_bool bSaveSession );

void		cms_SSL_SetBrwState		( void );
void		cms_SSL_CleanBrwState	( void );
void		cms_SSL_ShowInfomation	( const char* title , const char* strInfo );

void		cms_SSL_OnUserConfirmCert ( int bOK );

VW_EXTERN_C_END

#endif

