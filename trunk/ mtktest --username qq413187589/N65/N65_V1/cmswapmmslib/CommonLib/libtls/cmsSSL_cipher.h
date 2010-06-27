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
/*   cmsSSL_cipher.h                                                        */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   30/12/04   |  Liang Li       |n   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_CHIPHER_H__
#define __CMSSSL_CHIPHER_H__

#include "cmsSSL_HandShake.h"

VW_EXTERN_C_BEGIN

void		cms_SSL_Cipher_Cleanup	  ( void );
VWRESULT	cms_SSL_Update_Cipher_Stat( cms_SSL_Handshake_Context* ctx );
VWRESULT	cms_SSL_Encrpt_Data       ( vwuint8 type , vwuint8p buf , size_t len , size_t *outlen );
VWRESULT	cms_SSL_Decrypt_Data	  ( vwuint8 type , vwuint8p buf , size_t len , size_t *outlen );
VWRESULT	cms_SSL_Decrypt_Package	  ( cms_tls1_raw_package* package );
vwuint8p	cms_SSL_SHA1_Value		  ( vwuint8p ptr , size_t len , vwuint8p shaval );

VW_EXTERN_C_END

#endif

