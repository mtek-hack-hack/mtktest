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
/*   cmsSSLCertManager.h                                                    */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   21/01/05   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSLCERTMANAGER_H__
#define __CMSSSLCERTMANAGER_H__

#include "cmsSSL_stream.h"
#include <openssl/x509.h>

//#	define __USE_STUB_STORAGE_CERT__

#if ( !defined( __CC_ARM ) && !defined( __ARM_CC ) ) && !defined( __USE_STUB_STORAGE_CERT__ )
#	define __USE_STUB_STORAGE_CERT__
#endif

VW_EXTERN_C_BEGIN

typedef struct cms_SSL_Certificate_Info
{
	vwuint8p		pCertData;	/* size_is( szCertDataLen ) */
	size_t			szCertDataLen;
}	cms_SSL_Certificate_Info;

typedef struct cms_SSL_Storage_Certificate_info
{
	const char*						cstrStorageName;		/* name of provider.	  */
	size_t							szCertCount;			/* count of certificate.  */
	cms_SSL_Certificate_Info**		infoCerts;				/* size_is(1,szCertCount) */
}	cms_SSL_Storage_Certificate_info;

/**
 *	获得存储的根证书列表信息,需要目标平台实现.
 */
VWRESULT	cms_SSL_Get_Storage_Certificate_Info( 
				/* out */cms_SSL_Storage_Certificate_info* pInfoCerts
			);

/**
 *	释放存储的根证书列表信息,需要目标平台实现.
 */
void		cms_SSL_Release_Storage_Certificate_Info( 
				/*in*/cms_SSL_Storage_Certificate_info* pInfoCerts		/* return by cms_SSL_Get_Storage_Certificate_Info. */
			);

#ifdef __USE_STUB_STORAGE_CERT__
VWRESULT	_cms_SSL_Get_Storage_Certificate_Info_dummy( 
				/* out */cms_SSL_Storage_Certificate_info* pInfoCerts
			);
void		_cms_SSL_Release_Storage_Certificate_Info_dummy( 
				/*in*/cms_SSL_Storage_Certificate_info* pInfoCerts		/* return by cms_SSL_Get_Storage_Certificate_Info. */
			);
#endif

VW_String_Buffer	cms_SSL_Get_Certificate_Info( X509* x509Cert , VW_String_Buffer infoRet , vwuint8p sha1val , vw_bool bshowsign );

enum cms_SSL_Cert_Verify_State_Mask
{
	/* 错误的证书.							 */
	cms_SCVSM_Bad_Cert			=		0X00000001 ,	/* 错误的证书如错误的签名等. */
	cms_SCVSM_Unsupported_Cert	=		0X00000002 ,	/* 不支持的证书.			 */

	/* 无法验证证书的有效性,证书可能有问题.  */
	cms_SCVSM_Unknown_CA		=		0X00000004 ,	/* 无有效的CA证书验证.		 */	
	cms_SCVSM_Revoked			=		0X00000008 ,	/* 已经被签发者吊销.         */
	cms_SCVSM_Expired			=		0X00000010 ,	/* 证书已经过期.             */
	cms_SCVSM_Unmatch_Host		=		0X00000020 ,	/* 证书标识与站点不匹配.     */	
	cms_SCVSM_Invalid_Purpose	=		0X00000040 		/* 证书标明的用途不匹配.     */
};

enum  cms_SSL_Cert_Verify_Prompt_Caller
{
	cms_SCVPC_TLS				=	0 ,
	cms_SCVPC_WTLS				=	1 ,
	cms_SCVPC_WPKI				=	2 ,
	cms_SCVPC_WIM				=	3 ,

	//////////////////////////////////////////////////////////////////////////	
	cms_SCVPC_UNKNOWN			=	-1
};


/**
 *  当收到服务器证书时,由用户确认,需要目标平台实现.
 *		返回值 : 
 *			vw_true : 用户已确认,继续操作.
 *			vw_false: 用户取消操作.
 */
vw_bool		cms_SSL_Certificate_Verify_Prompt(
					vwuint32			nCallFrom	  ,	/* 调用者标识. 如 cms_SCVPC_TLS , cms_SCVPC_WTLS 等  */
					vwuint32			nStateMask    ,	/* 见 cms_SSL_Cert_Verify_State_Mask , 0 表示有效.   */
					const char*			strHostName   ,	/* 服务器名称.                                       */
					const char*			strOnlineName ,	/* 证书的名称.									     */
					const char*			strInfo		  , /* 证书验证信息.								     */
					size_t				nCertCount    , /* 包括的证书列表个数.							     */
					X509**				certList		/* 证书列表.							             */
			);

/*
 * 返回从 pInfoCerts 载入的证书个数, 0 表示失败.
 */
size_t		cms_SSL_Load_Storage_Certificate( /*in*/cms_SSL_Storage_Certificate_info* pInfoCerts );

/*
 * 释放 X509 对象,请不要直接调用 X509_free.
 */
void		cms_SSL_X509_free( X509* objX509 );

/*
 * 载入一个存储的证书,返回NULL表示失败,释放证书请使用 cms_SSL_X509_free.
 */
X509*		cms_SSL_Load_Certificate( vwuint8p pCertData , size_t szCertDataLen );

/*
 * 向存储证书列表中添加一个新的证书.
 */
VWRESULT	cms_SSL_Add_Certificate( X509* objX509 , vw_bool bReleaseIfFailed );

/*
 * 存储证书列表的个数.
 */
size_t		cms_SSL_Get_Storage_Certificate_Count( void );

/*
 * 获得存储的证书. 0 <= index < cms_SSL_Get_Storage_Certificate_Count()
 */
X509*		cms_SSL_Get_Storage_Certificate( int index );

/*
 * 获得证书信息. nID : ie. NID_cNAMERecord .... 
 */
const char*	cms_SSL_Get_CertificateInfo( X509* x509 , int nID );

#define		cms_SSL_Get_CertificateName( x509 )	cms_SSL_Get_CertificateInfo( (x509) , NID_commonName )

/*
 * 释放所有存储的证书.
 */
void		cms_SSL_Release_All_Storage_Certificate( void );

/*
 *	return VWE_S_OK		for verify ok.
 *	return VWE_S_FALSE  for verify failed.
 *	return VWFAILED( vr ) for error.
 */
VWRESULT	cms_SSL_Verify_Certificate_List( 
				vwuint32	nCallFrom		,		/* */
				int			purpose			,		/* 使用目的.			*/
				const char* strCommName		,		/* 期望的证书名称.      */
				size_t		szCertCount	    ,		/* 收到的证书列表长度.  */
				X509**		certList				/* 收到的证书列表       */
			);

VW_EXTERN_C_END

#endif

