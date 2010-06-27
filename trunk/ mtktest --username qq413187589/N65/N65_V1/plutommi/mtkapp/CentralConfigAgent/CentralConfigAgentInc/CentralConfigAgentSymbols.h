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
 *  CentralConfigAgentSymbols.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_CCASYMBOLS_H
#define MMI_CCASYMBOLS_H


/* CCA Proprietary Symbols */
typedef enum
{
    CCA_NS__START = (0x0000 | CCA_NS_CCA),

    CCA_NS_DOCROOT,
    CCA_NS_NODEID,
    CCA_NS_DATAACCTID,
    CCA_NS_L1NODEID,
    CCA_NS_DEPREL,
    CCA_NS_DEP_PROXY,
    CCA_NS_DEP_APPLICATION,
    CCA_NS_DEP_BOOTSTRAP,
    CCA_NS_DEP_ACCESS,
    CCA_NS_DEP_NAPDEF,
    CCA_NS_HSRCNODE,
    CCA_NS_REFNAPID,
    CCA_NS_REFPXID,
    CCA_NS_DEP_DATAACCT,
    CCA_NS_ISUSED,
    CCA_NS_TRIGNODE,
    CCA_NS_TRIGPARM,
    CCA_NS_INAPPCONTEXT,

    CCA_NS__LAST
} cca_symbols_enum;

/* CCA Proprietary Value Symbols */
typedef enum
{
    CCA_NS_VAL__START = (0x0000 | CCA_NS_VAL__SECTION_NULL),

    CCA_NS_VAL__EMPTY,
    CCA_NS_VAL__INVALID,

    CCA_NS_VAL__LAST
} cca_values_enum;


/* OMA Client Provisioning v1.1 Symbols */
typedef enum
{
    CCA_NS_OMA__START = (0x0000 | CCA_NS_OMA),

    CCA_NS_OMA_PROXY,
    CCA_NS_OMA_PROXY_ID,
    CCA_NS_OMA_PROXY_PW,
    CCA_NS_OMA_PPGAUTH_TYPE,
    CCA_NS_OMA_PROXY_PROVIDER_ID,
    CCA_NS_OMA_NAME,
    CCA_NS_OMA_DOMAIN,
    CCA_NS_OMA_TRUST,
    CCA_NS_OMA_MASTER,
    CCA_NS_OMA_STARTPAGE,
    CCA_NS_OMA_BASAUTH_ID,
    CCA_NS_OMA_BASAUTH_PW,
    CCA_NS_OMA_WSP_VERSION,
    CCA_NS_OMA_PUSHENABLED,
    CCA_NS_OMA_PULLENABLED,

    CCA_NS_OMA_PXAUTHINFO,
    CCA_NS_OMA_PXAUTH_TYPE,
    CCA_NS_OMA_PXAUTH_ID,
    CCA_NS_OMA_PXAUTH_PW,
    CCA_NS_OMA_PORT,
    CCA_NS_OMA_PORTNBR,
    CCA_NS_OMA_SERVICE,
    CCA_NS_OMA_PHYSICAL_PROXY_ID,
    CCA_NS_OMA_PXADDR,
    CCA_NS_OMA_PXADDRTYPE,
    CCA_NS_OMA_PXADDR_FQDN,
    CCA_NS_OMA_TO_NAPID,
    CCA_NS_OMA_NAPDEF,
    CCA_NS_OMA_NAPID,
    CCA_NS_OMA_BEARER,
    CCA_NS_OMA_INTERNET,
    CCA_NS_OMA_NAP_ADDRESS,
    CCA_NS_OMA_NAP_ADDRTYPE,
    CCA_NS_OMA_DNS_ADDR,
    CCA_NS_OMA_CALLTYPE,
    CCA_NS_OMA_LOCAL_ADDR,
    CCA_NS_OMA_LOCAL_ADDRTYPE,
    CCA_NS_OMA_LINKSPEED,
    CCA_NS_OMA_DNLINKSPEED,
    CCA_NS_OMA_LINGER,
    CCA_NS_OMA_DELIVERY_ERR_SDU,
    CCA_NS_OMA_DELIVERY_ORDER,
    CCA_NS_OMA_TRAFFIC_CLASS,
    CCA_NS_OMA_MAX_SDU_SIZE,
    CCA_NS_OMA_MAX_BITRATE_UPLINK,
    CCA_NS_OMA_MAX_BITRATE_DNLINK,
    CCA_NS_OMA_RESIDUAL_BER,
    CCA_NS_OMA_SDU_ERROR_RATIO,
    CCA_NS_OMA_TRAFFIC_HANDL_PRIO,
    CCA_NS_OMA_TRANSFER_DELAY,
    CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK,
    CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK,
    CCA_NS_OMA_MAX_NUM_RETRY,
    CCA_NS_OMA_FIRST_RETRY_TIMEOUT,
    CCA_NS_OMA_REREG_THRESHOLD,
    CCA_NS_OMA_T_BIT,
    CCA_NS_OMA_NAPAUTHINFO,
    CCA_NS_OMA_AUTHTYPE,
    CCA_NS_OMA_AUTHNAME,
    CCA_NS_OMA_AUTHSECRET,
    CCA_NS_OMA_AUTH_ENTITY,
    CCA_NS_OMA_SPI,
    CCA_NS_OMA_VALIDITY,
    CCA_NS_OMA_COUNTRY,
    CCA_NS_OMA_NETWORK,
    CCA_NS_OMA_SID,
    CCA_NS_OMA_SOC,
    CCA_NS_OMA_VALIDUNTIL,
    CCA_NS_OMA_BOOTSTRAP,
    CCA_NS_OMA_PROVURL,
    CCA_NS_OMA_CONTEXT_ALLOW,
    CCA_NS_OMA_CLIENTIDENTITY,
    CCA_NS_OMA_CLIENT_ID,
    CCA_NS_OMA_VENDORCONFIG,
    CCA_NS_OMA_APPLICATION,
    CCA_NS_OMA_APPID,
    CCA_NS_OMA_PROVIDER_ID,
    CCA_NS_OMA_AACCEPT,
    CCA_NS_OMA_APROTOCOL,
    CCA_NS_OMA_TO_PROXY,
    CCA_NS_OMA_ADDR,
    CCA_NS_OMA_APPADDR,
    CCA_NS_OMA_ADDRTYPE,
    CCA_NS_OMA_APPAUTH,
    CCA_NS_OMA_AAUTHLEVEL,
    CCA_NS_OMA_AAUTHTYPE,
    CCA_NS_OMA_AAUTHNAME,
    CCA_NS_OMA_AAUTHSECRET,
    CCA_NS_OMA_AAUTHDATA,
    CCA_NS_OMA_RESOURCE,
    CCA_NS_OMA_URI,
    CCA_NS_OMA_ACCESS,
    CCA_NS_OMA_RULE,
    CCA_NS_OMA_LOGINTYPE,   /* Conversion from Nokia OTA Spec */
    CCA_NS_OMA_FROM,        /* SMTP */
    CCA_NS_OMA_RT_ADDR,     /* SMTP */
    CCA_NS_OMA_SERVICES,    /* IMPS */
    CCA_NS_OMA_CIDPREFIX,   /* IMPS */
    CCA_NS_OMA_CLIURI,      /* SyncML-DS */
    CCA_NS_OMA_SYNCTYPE,    /* SyncML-DS */
    CCA_NS_OMA_INIT,        /* SyncML-DM */

/* OMA Extension */
    /* OMA Client Provisioning Extension WLAN Symbols */
    CCA_NS_OMA_WLAN,
    CCA_NS_OMA_PRI_SSID,
    CCA_NS_OMA_PRI_U_SSID,
    CCA_NS_OMA_PRI_H_SSID,
    CCA_NS_OMA_SEC_SSID,
    CCA_NS_OMA_S_SSID,
    CCA_NS_OMA_S_U_SSID,
    CCA_NS_OMA_NETMODE,
    CCA_NS_OMA_SECMODE,
    CCA_NS_OMA_EAP,
    CCA_NS_OMA_EAPTYPE,
    CCA_NS_OMA_USERNAME,
    CCA_NS_OMA_PASSWORD,
    CCA_NS_OMA_REALM,
    CCA_NS_OMA_USE_PSEUD,
    CCA_NS_OMA_MAXAUTHS,
    CCA_NS_OMA_ENCAPS,
    CCA_NS_OMA_VER_SER_REALM,
    CCA_NS_OMA_CLIENT_AUTH,
    CCA_NS_OMA_SES_VAL_TIME,
    CCA_NS_OMA_CIP_SUIT,
    CCA_NS_OMA_PEAP_V0,
    CCA_NS_OMA_PEAP_V1,
    CCA_NS_OMA_PEAP_V2,
    CCA_NS_OMA_CERT,
    CCA_NS_OMA_ISS_NAME,
    CCA_NS_OMA_SUB_NAME,
    CCA_NS_OMA_CERT_TYPE,
    CCA_NS_OMA_SER_NUM,
    CCA_NS_OMA_SUB_KEY_ID,
    CCA_NS_OMA_THUMBPRINT,
    CCA_NS_OMA_WPA_PRES_KEY_ASC,
    CCA_NS_OMA_WPA_PRES_KEY_HEX,
    CCA_NS_OMA_WEPKEYIND,
    CCA_NS_OMA_WEPAUTHMODE,
    CCA_NS_OMA_WEPKEY,
    CCA_NS_OMA_LENGTH,
    CCA_NS_OMA_INDEX,
    CCA_NS_OMA_DATA,
    CCA_NS_OMA_WLANHAND,
    CCA_NS_OMA_EDIT_SET,
    CCA_NS_OMA_VIEW_SET,
    CCA_NS_OMA_FORW_SET,

    CCA_NS_OMA__LAST
} cca_oma_symbols_enum;


#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    CCA_NS_VAL__OMA_START = (0x0000 | CCA_NS_VAL__SECTION_OMA),

    /* PROXY: PPGAUTH-TYPE */
    /* PROXY/PXAUTHINFO: PXAUTH-TYPE*/
    /* APPLICATION/APPAUTH: AAUTHTYPE(official) */
    /* APPLICATION/RESOURCE: AAUTHTYPE */
    CCA_NS_VAL_HTTP_BASIC,
    CCA_NS_VAL_HTTP_DIGEST,
    CCA_NS_VAL_WTLS_SS,
    CCA_NS_VAL_BASIC,
    CCA_NS_VAL_DIGEST,

    /* APPLICATION/APPAUTH: AAUTHTYPE */
    CCA_NS_VAL_CRAM_MD5,
    CCA_NS_VAL_DIGEST_MD5,
    CCA_NS_VAL_LOGIN,
    CCA_NS_VAL_PLAIN,
    CCA_NS_VAL_APOP,
    CCA_NS_VAL_GSSAPI,
    CCA_NS_VAL_KERBEROS_V4,
    CCA_NS_VAL_SKEY,
    CCA_NS_VAL_CLIENT,
    CCA_NS_VAL_X509,
    CCA_NS_VAL_SECURID,
    CCA_NS_VAL_SAFEWORD,
    CCA_NS_VAL_DIGIPASS,
    CCA_NS_VAL_HMAC,

    /* PROXY: PXADDRTYPE */
    /* NAPDEF: NAP-ADDRTYPE */
    /* NAPDEF: LOCAL-ADDRTYPE */
    /* APPLICATION/APPADDR: ADDRTYPE */
    CCA_NS_VAL_IPV4,
    CCA_NS_VAL_IPV6,
    CCA_NS_VAL_E164,
    CCA_NS_VAL_ALPHA,
    CCA_NS_VAL_APN,
    CCA_NS_VAL_SCODE,
    CCA_NS_VAL_TETRA_ITSI,
    CCA_NS_VAL_MAN,

    /* PROXY: PUSHENABLED/PULLENABLED */
    CCA_NS_VAL_ENABLED,
    CCA_NS_VAL_DISABLED,

    /* PROXY/PORT: SERVICE */
    CCA_NS_VAL_CL_WSP,
    CCA_NS_VAL_CO_WSP,
    CCA_NS_VAL_CL_SEC_WSP,
    CCA_NS_VAL_CO_SEC_WSP,
    CCA_NS_VAL_CO_SEC_WTA,
    CCA_NS_VAL_CL_SEC_WTA,
    CCA_NS_VAL_OTA_HTTP_TO,
    CCA_NS_VAL_OTA_HTTP_TLS_TO,
    CCA_NS_VAL_OTA_HTTP_PO,
    CCA_NS_VAL_OTA_HTTP_TLS_PO,
    CCA_NS_VAL_STARTTLS,

    /* NAPDEF: BEARER */
    CCA_NS_VAL_GSM_CSD,
    CCA_NS_VAL_GSM_GPRS,
    CCA_NS_VAL_GSM_USSD,
    CCA_NS_VAL_GSM_SMS,
    CCA_NS_VAL_CDMA_SMS,
    CCA_NS_VAL_CDMA_CSD,
    CCA_NS_VAL_CDMA_PACKET,
    CCA_NS_VAL_ANSI_136_GUTS,
    CCA_NS_VAL_ANSI_136_CSD,
    CCA_NS_VAL_ANSI_136_GPRS,
    CCA_NS_VAL_ANSI_136_GHOST,
    CCA_NS_VAL_AMPS_CDPD,
    CCA_NS_VAL_PDC_CSD,
    CCA_NS_VAL_PDC_PACKET,
    CCA_NS_VAL_IDEN_SMS,
    CCA_NS_VAL_IDEN_CSD,
    CCA_NS_VAL_IDEN_PACKET,
    CCA_NS_VAL_FLEX_REFLEX,
    CCA_NS_VAL_PHS_SMS,
    CCA_NS_VAL_PHS_CSD,
    CCA_NS_VAL_TETRA_SDS,
    CCA_NS_VAL_TETRA_PACKET,
    CCA_NS_VAL_MOBITEX_MPAK,
    CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP,
    CCA_NS_VAL_CDMA2000_1X_MOBILE_IP,
    CCA_NS_VAL_WLAN,    /* OMA Extension */

    /* NAPDEF: CALLTYPE */
    CCA_NS_VAL_ANALOG_MODEM,
    CCA_NS_VAL_V120,
    CCA_NS_VAL_V110,
    CCA_NS_VAL_X31,
    CCA_NS_VAL_BIT_TRANSPARENT,
    CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE,

    /* NAPDEF: LINKSPEED */
    /* NAPDEF: DNLINKSPEED */
    CCA_NS_VAL_AUTOBAUDING,

    /* NAPDEF/NAPAUTHINFO: AUTHTYPE */
    CCA_NS_VAL_PAP,
    CCA_NS_VAL_CHAP,
    CCA_NS_VAL_MD5,

    /* NAPDEF/NAPAUTHINFO: AUTH-ENTITY */
    CCA_NS_VAL_AAA,
    CCA_NS_VAL_HA,

    /* APPLICATION/APPAUTH: AAUTHLEVEL */
    CCA_NS_VAL_APPSRV,
    CCA_NS_VAL_OBEX,

/* Conversion from Nokia OTA Spec */
    /* PROXY: LOGINTYPE */
    /* NAPDEF: LOGINTYPE */
    CCA_NS_VAL_AUTOMATIC,
    CCA_NS_VAL_MANUAL,

/* OMA Extension */
    /* WLAN: NETMODE */
    CCA_NS_VAL_INFRA,
    CCA_NS_VAL_ADHOC,

    /* WLAN: SECMODE */
    CCA_NS_VAL_WEP,
    CCA_NS_VAL_8021X,
    CCA_NS_VAL_WPA,
    CCA_NS_VAL_WPA_PRESHARED_KEY,
    CCA_NS_VAL_WPA2,
    CCA_NS_VAL_WPA2_PRESHARED_KEY,

    /* WLAN: WEPAUTHMODE */
    CCA_NS_VAL_OPEN,
    CCA_NS_VAL_SHARED,

    /* WLAN: EAP-TYPE */
    CCA_NS_VAL_EAP_SIM,
    CCA_NS_VAL_EAP_AKA,
    CCA_NS_VAL_EAP_TLS,
    CCA_NS_VAL_EAP_PEAP,
    CCA_NS_VAL_EAP_TTLS,
    CCA_NS_VAL_EAP_LEAP,
    CCA_NS_VAL_EAP_MSCHAPV2,
    CCA_NS_VAL_EAP_GTC,

    /* WLAN: CERT-TYPE */
    CCA_NS_VAL_USER,
    CCA_NS_VAL_CA,

    CCA_NS_VAL__OMA_LAST
} cca_oma_values_enum;

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif  /* MMI_CCASYMBOLS_H */
