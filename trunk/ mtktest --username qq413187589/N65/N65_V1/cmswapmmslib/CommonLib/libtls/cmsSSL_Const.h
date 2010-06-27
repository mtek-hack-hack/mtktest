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
/*   cmsSSL_Const.h                                                         */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   28/12/04   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __CMSSSL_CONST_H__
#define __CMSSSL_CONST_H__

#define CMS_SSL_VER_MAJOR							(0X03)
#define CMS_SSL_VER_MINOR							(0X01)

#define CMS_SSL_PT_CHANGE_CIPHER_SPEC				(20)
#define CMS_SSL_PT_ALERT							(21)
#define CMS_SSL_PT_HANDSHAKE						(22)
#define CMS_SSL_PT_APPLICATION_DATA					(23)

/*
 *	handshake const value.
 */
#define CMS_SSL_HS_HELLO_REQUST						(0)
#define CMS_SSL_HS_CLIENT_HELLO						(1)
#define CMS_SSL_HS_SERVER_HELLO						(2)
#define CMS_SSL_HS_CERTIFICATE						(11)
#define CMS_SSL_HS_SERVER_KEY_EXCH					(12)
#define CMS_SSL_HS_CERT_REQUEST						(13)
#define CMS_SSL_HS_SERVER_HELLO_DONE				(14)
#define CMS_SSL_HS_CERT_VERIFY						(15)
#define CMS_SSL_HS_CLIENT_KEY_EXCH					(16)
#define CMS_SSL_HS_FINISH							(20)

#endif

