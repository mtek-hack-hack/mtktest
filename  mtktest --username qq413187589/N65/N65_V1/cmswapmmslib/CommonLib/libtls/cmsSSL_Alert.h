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
/*   cmsSSL_Alert.h                                                         */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   27/12/04   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_ALERT_H__
#define __CMSSSL_ALERT_H__

#include "cmsSSL_Msg.h"

VW_EXTERN_C_BEGIN


enum cms_SSL_Alert_Level
{
	cmsSSL_AL_Warning					=	1,
	cmsSSL_AL_FATAL						=	2
};

enum cms_SSL_Alert_Description
{
	cmsSSL_AD_Close						=	0,

	cmsSSL_AD_Unexcepted_Message		=	10,

	cmsSSL_AD_Bad_Record_Mac			=	20,
	cmsSSL_AD_Decryption_Failed			=	21,
	cmsSSL_AD_Record_Overflow			=	22,

	cmsSSL_AD_Decompression_Failure		=	30,
	
	cmsSSL_AD_Handshake_Failure			=	40,

	cmsSSL_AD_Bad_Certificate			=	42,
	cmsSSL_AD_Unsupported_Certificate	=	43,
	cmsSSL_AD_Certificate_Revoked		=	44,
	cmsSSL_AD_Certificate_Expired		=	45,
	cmsSSL_AD_Certificate_Unknown		=	46,
	cmsSSL_AD_Illegal_Parameter			=	47,
	cmsSSL_AD_Unknown_CA				=	48,
	cmsSSL_AD_Access_Denied				=	49,
	cmsSSL_AD_Decode_Error				=	50,
	cmsSSL_AD_Decrypt_Error				=	51,

	cmsSSL_AD_Export_Restriction		=	60,
	cmsSSL_AD_Protocol_Version			=	70,
	cmsSSL_AD_Insufficient_Security		=	71,
	cmsSSL_AD_Internal_Error			=	80,
	cmsSSL_AD_User_Canceled				=	90,
	cmsSSL_AD_No_Renegotiation			=	100
};

VWRESULT	cms_SSL_OnSkt_Recv_Alert( cms_tls1_raw_package* package );

VWRESULT	cms_SSL_Send_AlertInfo( vwuint8 lvl , vwuint8 desc );

VWRESULT	cms_SSL_Decrypt_AlertInfo( cms_tls1_raw_package* package );

#define cmsSSL_AL_Send_Close()					cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Close						)

#define cmsSSL_AL_Send_Unexp_Msg()				cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Unexcepted_Message		)

#define cmsSSL_AL_Send_Bad_Rec_Mac()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Bad_Record_Mac			)

#define cmsSSL_AL_Send_Decr_Failed()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Decryption_Failed			)

#define cmsSSL_AL_Send_Rec_Overflow()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Record_Overflow			)

#define cmsSSL_AL_Send_Decomp_Failed()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Decompression_Failure		)

#define cmsSSL_AL_Send_HandShake_Failed()		cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Handshake_Failure			)

#define cmsSSL_AL_Send_Bad_Cert()				cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Bad_Certificate			)

#define cmsSSL_AL_Send_Unsup_Cert()				cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Unsupported_Certificate	)

#define cmsSSL_AL_Send_Cert_Revoked()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Certificate_Revoked		)

#define cmsSSL_AL_Send_Cert_Expired()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Certificate_Expired		)

#define cmsSSL_AL_Send_Cert_Unknown()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Certificate_Unknown		)

#define cmsSSL_AL_Send_Illegal_Param()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Illegal_Parameter			)

#define cmsSSL_AL_Send_Unknown_CA()				cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Unknown_CA				)

#define cmsSSL_AL_Send_Access_Denied()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Access_Denied				)

#define cmsSSL_AL_Send_Decode_Error()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Decode_Error				)

#define cmsSSL_AL_Send_Decrypt_Error()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_Decrypt_Error				)

#define cmsSSL_AL_Send_Export_Rest()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Export_Restriction		)

#define cmsSSL_AL_Send_Protocol_Version()		cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Protocol_Version			)

#define cmsSSL_AL_Send_Insuff_Security()		cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Insufficient_Security		)

#define cmsSSL_AL_Send_Internal_Error()			cms_SSL_Send_AlertInfo( cmsSSL_AL_FATAL   , cmsSSL_AD_Internal_Error			)

#define cmsSSL_AL_Send_User_Cancelled()			cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_User_Canceled				)

#define cmsSSL_AL_Send_No_Renegotiation()		cms_SSL_Send_AlertInfo( cmsSSL_AL_Warning , cmsSSL_AD_No_Renegotiation			)

#define SSLE_ALT_ERROR_TYPE				(0X15)
#define SSLE_ALT_INVALID_PACKAGE		VWMK_ERROR_CODE( SSLE_ALT_ERROR_TYPE , 0X0001 )
#define SSLE_ALT_FATAL					VWMK_ERROR_CODE( SSLE_ALT_ERROR_TYPE , 0X0002 )
#define SSLE_ALT_S_WARNING				VWMK_SUC_CODE( SSLE_ALT_ERROR_TYPE , 0X0001 )

VW_EXTERN_C_END

#endif

