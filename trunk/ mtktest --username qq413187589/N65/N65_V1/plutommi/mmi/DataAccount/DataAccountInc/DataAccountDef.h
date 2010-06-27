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
 * DataAccountDef.h
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

#ifndef _PIXTEL_DATA_ACCOUNT_DEF_H
#define _PIXTEL_DATA_ACCOUNT_DEF_H

#ifndef MAX_DATA_ACCOUNT_NAME_LEN
#define MAX_DATA_ACCOUNT_NAME_LEN            31
#endif 
#define MAX_DIAL_NUM_LEN                  22
#define MAX_USER_LEN                   31
#define MAX_PASSWD_LEN                    31
#define MAX_IPADDRES_LEN                  4
#ifdef CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#define MAX_DATA_ACCOUNT_GSM_LIMIT           CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else 
#define MAX_DATA_ACCOUNT_GSM_LIMIT           5
#endif 
#define MAX_PART_IP_ADDRESS                  4
#define DATA_ACCOUNT_HILITED_ITEM            0
#define DATA_ACCOUNT_UCS                  0x08
#define DATA_ACCOUNT_ASCII                0x00
#define MITEM_DATA_ACCOUNT_PARENT_ZERO       0
#define MAX_INLINE_ITEM_DATA_ACCOUNT_LIST    14
#define DATA_ACCOUNT_INLINE_DATA_RATE_OPTION 3
#define DATA_ACCOUNT_INLINE_DIAL_TYPE_OPTION 2
#define DATA_ACCOUNT_NOTIFY_TIMEOUT          UI_POPUP_NOTIFYDURATION_TIME

#define DATA_RATE_2400    2400
#define DATA_RATE_4800    4800
#define DATA_RATE_9600    9600
#define DATA_RATE_14400   14400

#ifdef __MMI_GPRS_FEATURES__

#ifdef MAX_GPRS_PROFILE_NUM
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else /* __MMI_OP01_GPRS_DATACFG__ */
#define MAX_DATA_ACCOUNT_GPRS_LIMIT                MAX_GPRS_PROFILE_NUM
#endif
#else 
#define MAX_DATA_ACCOUNT_GPRS_LIMIT                5
#endif 
#define MAX_INLINE_ITEM_GPRSDATA_ACCOUNT_LIST         10
#define GPRS_DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION     2
#define MAX_GPRS_DATAACCOUNT_NAME                  31
#ifdef MAX_GPRS_USER_NAME_LEN
#define MAX_GPRS_USERNAME                       (MAX_GPRS_USER_NAME_LEN-1)
#else 
#define MAX_GPRS_USERNAME                       15
#endif 
#ifdef MAX_GPRS_PASSWORD_LEN
#define MAX_GPRS_USERPASSWD                     (MAX_GPRS_PASSWORD_LEN-1)
#else 
#define MAX_GPRS_USERPASSWD                     15
#endif 
#ifdef MAX_GPRS_APN_LEN
#define MAX_GPRS_MMI_APN_LEN                    (MAX_GPRS_APN_LEN-1)
#else 
#define MAX_GPRS_MMI_APN_LEN                    99
#endif 

#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__

#define MAX_CHANNEL_NUMBER          15
#define MAX_WLAN_DATA_ACCOUNT_NUM   10
#define MAX_SSID_LEN                (32+1)
#define MAX_SCAN_RESULT_NUM         8
#define MAX_PASSPHRASE_LEN          (63+1)
#define MAX_WEP_KEYSTR_LEN          (26+1)
#define MAX_WEP_KEY_NUM             4
#define MAX_USERNAME_LEN            (32+1)
#define MAX_PASSWORD_LEN            (32+1)
#define MAX_CR_PATH_LEN             32
#define MAX_MAC_ADDR_LEN            6
#define MAX_BSSID_LEN               6
#define MAX_WLAN_PROF_NAME_LEN      MAX_SSID_LEN

#define DTCNT_WIFI_ID               20

#define BIT(n)              ( (kal_uint32)1 << (n) )

#define WPA_CIPHER_NONE BIT(0)
#define WPA_CIPHER_WEP40 BIT(1)
#define WPA_CIPHER_WEP104 BIT(2)
#define WPA_CIPHER_TKIP BIT(3)
#define WPA_CIPHER_CCMP BIT(4)

#define WPA_KEY_MGMT_IEEE8021X BIT(0)
#define WPA_KEY_MGMT_PSK BIT(1)
#define WPA_KEY_MGMT_NONE BIT(2)
#define WPA_KEY_MGMT_IEEE8021X_NO_WPA BIT(3)
#define WPA_KEY_MGMT_WPA_NONE BIT(4)

#define WPA_PROTO_WPA BIT(0)
#define WPA_PROTO_RSN BIT(1)

#define WPA_AUTH_ALG_OPEN BIT(0)
#define WPA_AUTH_ALG_SHARED BIT(1)
#define WPA_AUTH_ALG_LEAP BIT(2)

#define WLAN_EAP_TLS_SUPPORT
//#define WLAN_EAP_MD5_SUPPORT
#define WLAN_EAP_PEAP_SUPPORT
#define WLAN_EAP_TTLS_SUPPORT
#define WLAN_EAP_SIM_SUPPORT
// #define WLAN_EAP_FAST_SUPPORT
#define WLAN_EAP_MSCHAP2_SUPPORT
#define WLAN_EAP_GTC_SUPPORT
#define WLAN_PAP_SUPPORT
#define WLAN_CHAP_SUPPORT
#define WLAN_MSCHAP_SUPPORT
#define WLAN_MSCHAP2_SUPPORT

#define DEFAULT_PEAP_PHASE1_PARAM SUPC_PHASE1_LABLEL_0 | SUPC_PHASE1_OUTER_SUCCESS_0 
#define DEFAULT_ANONYMOUS_IDENTITY "anonymous"

#define AUTO_POWER_ON
#define MAX_WLAN_EVENT_REGISTRAR_NUM 10


#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

#define MIN_PASSPHRASE_LEN      (8 + 1)
#define MAX_NODE_ID_LEN         (64 + 1)
#define MAX_WLAN_OTA_PROF_NUM   (6)

/* Change max OTA profile# according to max WLAN profile# */
#if MAX_WLAN_OTA_PROF_NUM > MAX_WLAN_DATA_ACCOUNT_NUM
    #undef  MAX_WLAN_OTA_PROF_NUM
    #define MAX_WLAN_OTA_PROF_NUM MAX_WLAN_DATA_ACCOUNT_NUM
#endif

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */ 

#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)

#define DTCNT_ITEM_GPRS_NODE_ID		"CHT GPRS"
#define DTCNT_ITEM_CSD_NODE_ID		"CHT CSD"
#define DTCNT_DM_CHECK              2

#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */

#endif /* _PIXTEL_DATA_ACCOUNT_DEF_H */ 

