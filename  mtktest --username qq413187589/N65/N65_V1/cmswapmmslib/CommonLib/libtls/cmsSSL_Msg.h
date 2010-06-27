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
/*   cmsSSL_msg.h                                                           */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   07/01/05   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_MSG_H__
#define __CMSSSL_MSG_H__

#include "cmsSSL_base.h"

VW_EXTERN_C_BEGIN

/*
 *	tls 1.0 only.
 */
typedef struct cms_tls1_raw_package
{
	vwuint8			type;			/* package type. */
	vwuint8			ver_major;		/* 0X03. */
	vwuint8			ver_minor;		/* 0X01. */
	vwuint8			unused1;
	vwuint16		length;			/* data size. */
	vwuint16		__len2;			/* do not use this value in your proj. */
	vwuint8			data[1];		/* package data , size_is( length ) */	
}	cms_tls1_raw_package;

#define CMS_SSL_MSG_BEGIN			(0X12345600)
/*
 *	CMS_SSL_MSG_SEND_MSG : NOT USED.
 */
#define CMS_SSL_MSG_SEND_MSG		( CMS_SSL_MSG_BEGIN + 1 )

/*
 *	when recv msg.	param ( cms_tls1_raw_package* )
 */
#define CMS_SSL_MSG_RECV_MSG		( CMS_SSL_MSG_BEGIN + 2 )

/*
 *	invalid package. param NULL.
 */
#define CMS_SSL_MSG_INVALID_PACKAGE	( CMS_SSL_MSG_BEGIN + 3 )

/*
 *	socket shut down by remote. param NULL.
 */
#define CMS_SSL_MSG_SKT_SHUT_DOWN	( CMS_SSL_MSG_BEGIN + 4 )

/*
 *	failed.	param NULL.
 */
#define CMS_SSL_MSG_FAILED			( CMS_SSL_MSG_BEGIN + 5 )

/*
 *	close.	param NULL.
 */
#define CMS_SSL_MSG_CLOSE			( CMS_SSL_MSG_BEGIN + 6 )

/* 
 *	when system is idle , post this message to ssl subsystem.
 *		* update rand number generator....
 *		* ................................
 *		* param NULL.
 */
#define CMS_SSL_MSG_IDLE			( CMS_SSL_MSG_BEGIN + 7 )

/*
 *	ssl message loop , call back function.
 */
VWRESULT	cms_SSL_message_proc( vwuint32	msg , vwvoidp	param );

#define SSLE_MSG_ERROR_TYPE						(0X12)
#define SSLE_MSG_INVALID_PACKAGE				VWMK_ERROR_CODE( SSLE_MSG_ERROR_TYPE , 0X0001 )
#define SSLE_MSG_SHUTDOWN						VWMK_ERROR_CODE( SSLE_MSG_ERROR_TYPE , 0X0002 )
#define SSLE_MSG_FAILED							VWMK_ERROR_CODE( SSLE_MSG_ERROR_TYPE , 0X0003 )
#define SSLE_MSG_USER_CANCELED					VWMK_ERROR_CODE( SSLE_MSG_ERROR_TYPE , 0X0004 )

VW_EXTERN_C_END

#endif

