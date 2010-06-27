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
/*   cmsSSL_CliSession.h                                                    */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   27/12/04   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_CLISESSION_H__
#define __CMSSSL_CLISESSION_H__

#include "cmsSSL_Msg.h"
#include <openssl/evp.h>
#include <time.h>

VW_EXTERN_C_BEGIN

typedef struct cms_SSL_Session_Info
{
	time_t			tm_crt;					/* session created time. 0 : not used. */
	vwchar			hostName[64];			/* host_name */	
	vwuint16		port;					/* port. */
	size_t			sess_len;				/* 1 - 32. */
	vwuint8			sees_id[32];			/* length_is( sess_len ) */
	vwuint8			cipher_type[2];			/* rfc2246 P61. */
	vwuint8			comp_type[2];			/* not used. */
	vwuint8			master_secret[48];		/* master secret. */
}	cms_SSL_Session_Info;

VW_EXTERN	int		cms_ssl_current_sessionId;

int			cmsSSL_Get_SessionIndex_ByHostInfo( VW_RawString host , vwuint16 port );

/*
 *	return->sess_len == 0 : new session.
 */
cms_SSL_Session_Info*	cmsSSL_Get_Session( int id );	/* id : return by cmsSSL_Get_Client_Session_ByIP. */

/*
 *	clean current session.
 */
void		cmsSSL_Clean_Session_ByID( int id );

/*
 *	clean all session.
 */
void		cmsSSL_Clean_Session_Info( void );

/*
 *	添加用户已确认证书.
 */
void		cmsSSL_InsertUserConfirmedCert( /*size_is(SHA_DEGIST_LENGTH)*/vwuint8cp sha1Value );

/*
 *	检查是否为用户已确认证书.
 */
vw_bool		cmsSSL_IsUserConfirmedCert(  /*size_is(SHA_DEGIST_LENGTH)*/vwuint8cp sha1Value );


VW_EXTERN_C_END

#endif

