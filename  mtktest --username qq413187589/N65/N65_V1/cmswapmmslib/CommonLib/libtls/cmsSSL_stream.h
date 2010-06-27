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
/*   cmsSSL_stream.h                                                        */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   31/12/04   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_STREAM_H__
#define __CMSSSL_STREAM_H__

#include "cmsSSL_cipher.h"

VW_EXTERN_C_BEGIN

typedef VWRESULT	(*cms_SSL_App_Data_Callback)( vwvoidp buf , size_t len );

VWRESULT	cms_SSL_Write			( vwvoidcp buf , size_t len );
VWRESULT	cms_SSL_Decrypt_App_Data( cms_tls1_raw_package* package );
void		cms_SSL_Close			( vw_bool bSktClose , vw_bool bSaveSession );

cms_SSL_App_Data_Callback	cms_SSL_Set_AppData_Callback( cms_SSL_App_Data_Callback func );

VW_EXTERN_C_END

#endif

