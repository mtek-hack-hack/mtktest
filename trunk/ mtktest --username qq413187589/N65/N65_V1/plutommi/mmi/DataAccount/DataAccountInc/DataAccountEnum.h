/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * DataAccountEnum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_DATA_ACCOUNT_ENUM_H
#define _PIXTEL_DATA_ACCOUNT_ENUM_H

typedef enum
{
    DIAL_TYPE_ANALOGUE,
    DIAL_TYPE_ISDN
} DATA_ACCOUNT_DIAL_TYPE_ENUM;

typedef enum
{
    DATA_RATE_TWO_FOUR,
    DATA_RATE_FOUR_EIGHT,
    DATA_RATE_NINE_SIX,
    DATA_RATE_FOURTEEN_FOUR,
    DATA_RATE_AUTO
} DATA_ACCOUNT_DATA_RATE_ENUM;

typedef enum
{
    DATA_ACCOUNT_NAME_STR = 0,
    DATA_ACCOUNT_NAME,
    DATA_ACCOUNT_DIAL_NUMBER_STR,
    DATA_ACCOUNT_DIAL_NUMBER,
    DATA_ACCOUNT_USER_NAME_STR,
    DATA_ACCOUNT_USER_NAME,
    DATA_ACCOUNT_PASSWD_STR,
    DATA_ACCOUNT_PASSWD,
    DATA_ACCOUNT_DIAL_TYPE_STR,
    DATA_ACCOUNT_DIAL_TYPE,
    DATA_ACCOUNT_DATA_RATE_STR,
    DATA_ACCOUNT_DATA_RATE,
    DATA_ACCOUNT_DNS_ADDRESS_STR,
    DATA_ACCOUNT_DNS_ADDRESS
} DATA_ACCOUNT_INLINE;

typedef enum
{
    GPRS_DATA_ACCOUNT_NAME_STR = 0,
    GPRS_DATA_ACCOUNT_NAME,
    GPRS_DATA_ACCOUNT_APN_STR,
    GPRS_DATA_ACCOUNT_APN,
    GPRS_DATA_ACCOUNT_USER_NAME_STR,
    GPRS_DATA_ACCOUNT_USER_NAME,
    GPRS_DATA_ACCOUNT_PASSWD_STR,
    GPRS_DATA_ACCOUNT_PASSWD,
    GPRS_DATA_ACCOUNT_AUTH_TYPE_STR,
    GPRS_DATA_ACCOUNT_AUTH_TYPE,
    GPRS_DATA_ACCOUNT_DNS_ADDRESS_STR,
    GPRS_DATA_ACCOUNT_DNS_ADDRESS
} GPRS_DATA_ACCOUNT_INLINE;

#ifdef __MMI_CCA_SUPPORT__

typedef enum
{
    MMI_DTCNT_UCS2_UTF8 = 0,
    MMI_DTCNT_UTF8_UCS2,
    MMI_DTCNT_TOTAL
} dtcnt_string_convert_enum;

typedef enum
{
    DTCNT_FOR_DM,
    DTCNT_FOR_PROVISIONING,
    DTCNT_FOR_NULL
}dtacc_func_enum;

#endif /* __MMI_CCA_SUPPORT__ */

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)

/* Bearer type enum */
typedef enum 
{
    DTCNT_BEARER_IP_ANY,
    DTCNT_BEARER_GSM_CSD,
    DTCNT_BEARER_GSM_GPRS,
    DTCNT_BEARER_WIFI
} dtcnt_bearer_enum;

#endif /* SYNCML_DM_SUPPORT */

#ifdef OBIGO_Q03C
/* Bearer type enum */
typedef enum 
{
    DTCNT_LIST_BEARER_CSD,
    DTCNT_LIST_BEARER_GPRS,
    DTCNT_LIST_BEARER_GPRS_CSD,
    DTCNT_LIST_BEARER_WIFI,    
#ifdef __CBM_ALWAYS_ASK_FEATURE__
    DTCNT_LIST_BEARER_ALWAYS_ASK,
#endif /* __CBM_ALWAYS_ASK_FEATURE__ */ 
    DTCNT_LIST_BEARER_TOTAL
} dtcnt_list_bearer_enum;
#endif /*OBIGO_Q03C*/

#ifdef __MMI_WLAN_FEATURES__

typedef enum
{
    WLAN_TCPIP_USEDHCP_STR = 0,
    WLAN_TCPIP_USEDHCP,
    WLAN_TCPIP_IPADDR_STR,
    WLAN_TCPIP_IPADDR,
    WLAN_TCPIP_NETMASK_STR,
    WLAN_TCPIP_NETMASK,
    WLAN_TCPIP_GATEWAY_STR,
    WLAN_TCPIP_GATEWAY,
    WLAN_TCPIP_DNS1_STR,
    WLAN_TCPIP_DNS1,
    WLAN_TCPIP_DNS2_STR,
    WLAN_TCPIP_DNS2,
    WLAN_TCPIP_INLINE_TOTAL
} wlan_tcpip_settings_inline_enum;

typedef enum
{
    WLAN_NETWORK_EDIT_NAME_STR = 0,
    WLAN_NETWORK_EDIT_NAME,
    WLAN_NETWORK_EDIT_SSID_STR,
    WLAN_NETWORK_EDIT_SSID,
    WLAN_NETWORK_EDIT_NETWORK_TYPE_STR,
    WLAN_NETWORK_EDIT_NETWORK_TYPE,
    /*WLAN_NETWORK_EDIT_CHANNEL_STR,
    WLAN_NETWORK_EDIT_CHANNEL,*/
    WLAN_NETWORK_EDIT_AUTH_MODE_STR,
    WLAN_NETWORK_EDIT_AUTH_MODE,
    WLAN_NETWORK_EDIT_ENCRYPT_MODE_STR,
    WLAN_NETWORK_EDIT_ENCRYPT_MODE,
    /*WLAN_NETWORK_EDIT_USE_ANONYMOUS_STR,
    WLAN_NETWORK_EDIT_USE_ANONYMOUS,*/
    WLAN_NETWORK_EDIT_SECURITY_SETTINGS,
    WLAN_NETWORK_EDIT_TCPIP_SETTINGS,
    WLAN_NETWORK_EDIT_INLINE_TOTAL
} wlan_network_edit_inline_enum;

typedef enum
{
    WLAN_WEP_EDIT_WEP_KEY_ID_STR = 0,
    WLAN_WEP_EDIT_WEP_KEY_ID,
    WLAN_WEP_EDIT_WEP_KEY_ENCRYPT_STR,
    WLAN_WEP_EDIT_WEP_KEY_ENCRYPT,
    WLAN_WEP_EDIT_WEP_KEY_FORMAT_STR,
    WLAN_WEP_EDIT_WEP_KEY_FORMAT,
    WLAN_WEP_EDIT_WEP_KEY_STR,
    WLAN_WEP_EDIT_WEP_KEY,
    WLAN_WEP_EDIT_INLINE_TOTAL
} wlan_wep_edit_inline_enum;

typedef enum
{
    WLAN_USER_INFO_USERNAME_STR = 0,
    WLAN_USER_INFO_USERNAME,
    WLAN_USER_INFO_PASSWORD_STR,
    WLAN_USER_INFO_PASSWORD,
    WLAN_USER_INFO_INLINE_TOTAL
} wlan_user_info_inline_enum;

typedef enum
{
    WLAN_EAP_TLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_TLS_SETTINGS_CA_CERT,
    WLAN_EAP_TLS_SETTINGS_USER_CERT_STR,
    WLAN_EAP_TLS_SETTINGS_USER_CERT,
#ifndef __CERTMAN_SUPPORT__
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_STR,
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY,
#endif /* __CERTMAN_SUPPORT__ */
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR,
    WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD,
    WLAN_EAP_TLS_SETTINGS_USERNAME_STR,
    WLAN_EAP_TLS_SETTINGS_USERNAME,
    WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL
} wlan_eap_tls_settings_inline_enum;

typedef enum
{
    WLAN_EAP_PEAP_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_PEAP_SETTINGS_CA_CERT,
/*    WLAN_EAP_PEAP_SETTINGS_USERNAME_STR,
    WLAN_EAP_PEAP_SETTINGS_USERNAME,
    WLAN_EAP_PEAP_SETTINGS_USE_ANONYMOUS_STR,
    WLAN_EAP_PEAP_SETTINGS_USE_ANONYMOUS,
    WLAN_EAP_PEAP_ALLOW_PEAP_0_STR,
    WLAN_EAP_PEAP_ALLOW_PEAP_0,
    WLAN_EAP_PEAP_ALLOW_PEAP_1_STR,
    WLAN_EAP_PEAP_ALLOW_PEAP_1,*/
    WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL
} wlan_eap_peap_settings_inline_enum;

typedef enum
{
    WLAN_EAP_TTLS_SETTINGS_CA_CERT_STR = 0,
    WLAN_EAP_TTLS_SETTINGS_CA_CERT,
/*    WLAN_EAP_TTLS_SETTINGS_USERNAME_STR,
    WLAN_EAP_TTLS_SETTINGS_USERNAME,
    WLAN_EAP_TTLS_SETTINGS_USE_ANONYMOUS_STR,
    WLAN_EAP_TTLS_SETTINGS_USE_ANONYMOUS,*/
    WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL,
    WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL
} wlan_eap_ttls_settings_inline_enum;

typedef enum
{
    WLAN_STATE_NULL,
    WLAN_STATE_DEINIT_WAIT,
    WLAN_STATE_INIT_WAIT,
    WLAN_STATE_INIT,
    WLAN_STATE_DISCONNECT_WAIT,
    WLAN_STATE_CONNECT_WAIT,
    WLAN_STATE_CONNECTED,
    WLAN_STATE_TOTAL
} wlan_state_enum;

typedef enum
{
    WLAN_SCAN_STATE_NULL,
    WLAN_SCAN_STATE_WAITING,
    WLAN_SCAN_STATE_ABORTING,
    WLAN_SCAN_STATE_TOTAL
} wlan_scan_state_enum;

typedef enum
{
    WLAN_NETWORK_TYPE_INFRA,
    WLAN_NETWORK_TYPE_ADHOC,
    /*WLAN_NETWORK_TYPE_AUTO,*/
    WLAN_NETWORK_TYPE_TOTAL
} mmi_wlan_network_type_enum;

typedef enum
{
    WLAN_AUTH_MODE_OPEN,
    WLAN_AUTH_MODE_SHARED,
    WLAN_AUTH_MODE_IEEE8021X,
    WLAN_AUTH_MODE_WPA,
    WLAN_AUTH_MODE_WPAPSK,
    WLAN_AUTH_MODE_TOTAL
} mmi_wlan_auth_mode_enum;

typedef enum
{
    WLAN_ENCRYPT_MODE_NONE,
    WLAN_ENCRYPT_MODE_WEP,
    WLAN_ENCRYPT_MODE_TKIP,
    WLAN_ENCRYPT_MODE_AES,
    WLAN_ENCRYPT_MODE_TOTAL
} mmi_wlan_encrypt_mode_enum;

typedef enum
{
    WLAN_WEP_KEY_ENCRYPT_64,
    WLAN_WEP_KEY_ENCRYPT_128,
    /*WLAN_WEP_KEY_ENCRYPT_256,*/
    WLAN_WEP_KEY_ENCRYPT_TOTAL
} mmi_wlan_wep_key_encrypt_enum;

typedef enum
{
    WLAN_WEP_KEY_FORMAT_HEX,
    WLAN_WEP_KEY_FORMAT_ASCII,
    WLAN_WEP_KEY_FORMAT_TOTAL
} mmi_wlan_wep_key_format_enum;

typedef enum
{
#ifdef WLAN_EAP_TLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    WLAN_AUTH_TYPE_EAP_MD5,
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    WLAN_AUTH_TYPE_EAP_PEAP,
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TTLS,
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    WLAN_AUTH_TYPE_EAP_FAST,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_PAP_SUPPORT
    WLAN_AUTH_TYPE_PAP,
#endif 
#ifdef WLAN_CHAP_SUPPORT
    WLAN_AUTH_TYPE_CHAP,
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP,
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP2,
#endif 
    WLAN_AUTH_TYPE_TOTAL
} wlan_auth_type_enum;

#define WLAN_AUTH_TYPE_END 0xFF

typedef enum
{
    WLAN_ACTION_NULL = 0,
    WLAN_ACTION_INIT,
    WLAN_ACTION_CONNECT,
    WLAN_ACTION_DISCONNECT,
    WLAN_ACTION_DEINIT,
    WLAN_ACTION_SCAN,
    WLAN_ACTION_TOTAL
} wlan_action_enum;

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/* Converted symbols to define CCA namespace mapping table. */
typedef enum
{
    /* for proprietary OTA provisioning spec */
    WLAN_OTAP_NS_INFRA,
    WLAN_OTAP_NS_ADHOC,

    /* for OMA WLAN OTA provisioning extension */
    WLAN_OTAP_NS_NAPDEF,
    WLAN_OTAP_NS_WLAN,
    WLAN_OTAP_NS_SEC_SSID,
    WLAN_OTAP_NS_EAP,
    WLAN_OTAP_NS_CERT,
    WLAN_OTAP_NS_WEPKEY
} dtacc_cca_symbol_enum;

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _PIXTEL_DATA_ACCOUNT_ENUM_H */ 
