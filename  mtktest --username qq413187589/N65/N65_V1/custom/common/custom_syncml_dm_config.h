/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
*
* Filename:
* ---------
*   custom_syncml_dm_config.h
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   The file contains DM configuration default value. 
*
* Author:
* -------
*   Xiangjun Dan
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
* 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
#include "DMTypeDef.h"

#ifndef _CUSTOM_SYNCML_DM_CONFIG_H
#define _CUSTOM_SYNCML_DM_CONFIG_H

#ifdef SYNCML_DM_SUPPORT

#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* default DM server ID */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID  L"OMADM"
#endif

/* default DM server password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW L"mvpdm"
#endif

/* default DM server address */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR   L"http://219.141.227.16:8001"
#endif

/* default DM user name */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME  L"mvpdm"
#endif

/* default DM user password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW    L"mvpdm"
#endif

/* default DM auth type */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE DM_AUTH_TYPE_HMAC
#endif

/* ----------------------- default connection setting information start ------------------------ */
/* default data account id */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID   -1
#endif

/* default use proxy */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USE_PROXY
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USE_PROXY 1
#endif

/* default proxy IP */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP  L"010.000.000.172"
#endif

/* default proxy port */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT    80
#endif

/* default proxy user name */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERNAME
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERNAME    L""
#endif

/* default proxy user password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERPW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERPW      L""
#endif

/* ----------------------- default connection setting information end ------------------------ */

#else /* __MMI_OP01_DM_PROFILE_SETTING__ */

/* default DM server ID */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVERID  L"OMADM"
#endif

/* default DM server password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_PW L"mvpdm"
#endif

/* default DM server address */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_SERVER_ADDR   L"http://"
#endif

/* default DM user name */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USERNAME  L"mvpdm"
#endif

/* default DM user password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USERPW    L"mvpdm"
#endif

/* default DM auth type */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_AUTH_TYPE DM_AUTH_TYPE_HMAC
#endif

/* ----------------------- default connection setting information start ------------------------ */
/* default data account id */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_ACCT_ID   -1
#endif

/* default use proxy */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_USE_PROXY
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_USE_PROXY 1
#endif

/* default proxy IP */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_IP  L"000.000.000.000"
#endif

/* default proxy port */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_PORT    -1
#endif

/* default proxy user name */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERNAME
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERNAME    L""
#endif

/* default proxy user password */
#ifndef DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERPW
#define DM_CUSTOM_CFG_DEFAULT_PROFILE_PROXY_USERPW      L""
#endif
/* ----------------------- default connection setting information end ------------------------ */

#endif /* __MMI_OP01_DM_PROFILE_SETTING__ */

#endif /* SYNCML_DM_SUPPORT */

#endif /* _CUSTOM_SYNCML_DM_CONFIG_H */
