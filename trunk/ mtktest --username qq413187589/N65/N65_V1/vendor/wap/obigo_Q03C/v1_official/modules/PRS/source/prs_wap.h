/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */






#ifndef _prs_wap_h
#define _prs_wap_h

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _prs_cfg_h
#include "prs_cfg.h"
#endif









#define PRS_WAP_ELEMENT_WAP_PROVDOC         0x05
#define PRS_WAP_ELEMENT_CHARCT              0x06
#define PRS_WAP_ELEMENT_PARAM               0x07




#define PRS_WAP_ATTRIBUTE_VERSION           0x00
#define PRS_WAP_ATTRIBUTE_TYPE              0x01
#define PRS_WAP_ATTRIBUTE_NAME              0x02
#define PRS_WAP_ATTRIBUTE_VALUE             0x03





#define PRS_WAP_ATTRVAL_TYPE                0x0A00
#define PRS_WAP_ATTRVAL_PXLOGICAL           0x0A01
#define PRS_WAP_ATTRVAL_PXPHYSICAL          0x0A02
#define PRS_WAP_ATTRVAL_NAPDEF              0x0A03
#define PRS_WAP_ATTRVAL_BOOTSTRAP           0x0A04
#define PRS_WAP_ATTRVAL_VENDORCONFIG        0x0A05
#define PRS_WAP_ATTRVAL_CLIENTIDENTITY      0x0A06
#define PRS_WAP_ATTRVAL_PORT                0x0A07
#define PRS_WAP_ATTRVAL_VALIDITY            0x0A08
#define PRS_WAP_ATTRVAL_PXAUTHINFO          0x0A09
#define PRS_WAP_ATTRVAL_NAPAUTHINFO         0x0A0A
#define PRS_WAP_ATTRVAL_APPLICATION         0x0A0B
#define PRS_WAP_ATTRVAL_ACCESS              0x0A0C
#define PRS_WAP_ATTRVAL_APPADDR             0x0A0D
#define PRS_WAP_ATTRVAL_APPAUTH             0x0A0E
#define PRS_WAP_ATTRVAL_RESOURCE            0x0A0F
#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
#define PRS_WAP_ATTRVAL_WLAN                0x0A16
#define PRS_WAP_ATTRVAL_SEC_SSID            0x0A17
#define PRS_WAP_ATTRVAL_EAP                 0x0A18
#define PRS_WAP_ATTRVAL_CERT                0x0A19
#define PRS_WAP_ATTRVAL_WEPKEY              0x0A1A
#endif  /* MTK_TMP_PATCH CR27923 */


#define PRS_WAP_ATTRVAL_NAME                0x0B00
#define PRS_WAP_ATTRVAL_NAP_ADDRESS         0x0B01
#define PRS_WAP_ATTRVAL_NAP_ADDRTYPE        0x0B02
#define PRS_WAP_ATTRVAL_CALLTYPE            0x0B03
#define PRS_WAP_ATTRVAL_VALIDUNTIL          0x0B04
#define PRS_WAP_ATTRVAL_AUTHTYPE            0x0B05
#define PRS_WAP_ATTRVAL_AUTHNAME            0x0B06
#define PRS_WAP_ATTRVAL_AUTHSECRET          0x0B07
#define PRS_WAP_ATTRVAL_LINGER              0x0B08
#define PRS_WAP_ATTRVAL_BEARER              0x0B09
#define PRS_WAP_ATTRVAL_NAPID               0x0B0A
#define PRS_WAP_ATTRVAL_COUNTRY             0x0B0B
#define PRS_WAP_ATTRVAL_NETWORK             0x0B0C
#define PRS_WAP_ATTRVAL_INTERNET            0x0B0D
#define PRS_WAP_ATTRVAL_PROXY_ID            0x0B0E
#define PRS_WAP_ATTRVAL_PROXY_PROVIDER_ID   0x0B0F
#define PRS_WAP_ATTRVAL_DOMAIN              0x0B10
#define PRS_WAP_ATTRVAL_PROVURL             0x0B11
#define PRS_WAP_ATTRVAL_PXAUTH_TYPE         0x0B12
#define PRS_WAP_ATTRVAL_PXAUTH_ID           0x0B13
#define PRS_WAP_ATTRVAL_PXAUTH_PW           0x0B14
#define PRS_WAP_ATTRVAL_STARTPAGE           0x0B15
#define PRS_WAP_ATTRVAL_BASAUTH_ID          0x0B16
#define PRS_WAP_ATTRVAL_BASAUTH_PW          0x0B17
#define PRS_WAP_ATTRVAL_PUSHENABLED         0x0B18
#define PRS_WAP_ATTRVAL_PXADDR              0x0B19
#define PRS_WAP_ATTRVAL_PXADDRTYPE          0x0B1A
#define PRS_WAP_ATTRVAL_TO_NAPID            0x0B1B
#define PRS_WAP_ATTRVAL_PORTNBR             0x0B1C
#define PRS_WAP_ATTRVAL_SERVICE             0x0B1D
#define PRS_WAP_ATTRVAL_LINKSPEED           0x0B1E
#define PRS_WAP_ATTRVAL_DNLINKSPEED         0x0B1F
#define PRS_WAP_ATTRVAL_LOCAL_ADDR          0x0B20
#define PRS_WAP_ATTRVAL_LOCAL_ADDRTYPE      0x0B21
#define PRS_WAP_ATTRVAL_CONTEXT_ALLOW       0x0B22
#define PRS_WAP_ATTRVAL_TRUST               0x0B23
#define PRS_WAP_ATTRVAL_MASTER              0x0B24
#define PRS_WAP_ATTRVAL_SID                 0x0B25
#define PRS_WAP_ATTRVAL_SOC                 0x0B26
#define PRS_WAP_ATTRVAL_WSP_VERSION         0x0B27
#define PRS_WAP_ATTRVAL_PHYSICAL_PROXY_ID   0x0B28
#define PRS_WAP_ATTRVAL_CLIENT_ID           0x0B29
#define PRS_WAP_ATTRVAL_DELIVERY_ERR_SDU    0x0B2A
#define PRS_WAP_ATTRVAL_DELIVERY_ORDER      0x0B2B
#define PRS_WAP_ATTRVAL_TRAFFIC_CLASS       0x0B2C
#define PRS_WAP_ATTRVAL_MAX_SDU_SIZE        0x0B2D
#define PRS_WAP_ATTRVAL_MAX_BR_UPLINK       0x0B2E
#define PRS_WAP_ATTRVAL_MAX_BR_DNLINK       0x0B2F
#define PRS_WAP_ATTRVAL_RESIDUAL_BER        0x0B30
#define PRS_WAP_ATTRVAL_SDU_ERROR_RATIO     0x0B31
#define PRS_WAP_ATTRVAL_TRAFFIC_HANDL_PRIO  0x0B32
#define PRS_WAP_ATTRVAL_TRANSFER_DELAY      0x0B33
#define PRS_WAP_ATTRVAL_GUAR_BR_UPLINK      0x0B34
#define PRS_WAP_ATTRVAL_GUAR_BR_DNLINK      0x0B35
#define PRS_WAP_ATTRVAL_PXADDR_FQDN         0x0B36
#define PRS_WAP_ATTRVAL_PROXY_PW            0x0B37
#define PRS_WAP_ATTRVAL_PPGAUTH_TYPE        0x0B38
#define PRS_WAP_ATTRVAL_PULLENABLED         0x0B39
#define PRS_WAP_ATTRVAL_DNS_ADDR            0x0B3A
#define PRS_WAP_ATTRVAL_MAX_NUM_RETRY       0x0B3B
#define PRS_WAP_ATTRVAL_FIRST_RETRY_TIMEOUT 0x0B3C
#define PRS_WAP_ATTRVAL_REREG_THRESHOLD     0x0B3D
#define PRS_WAP_ATTRVAL_T_BIT               0x0B3E
#define PRS_WAP_ATTRVAL_AUTH_ENTITY         0x0B3F
#define PRS_WAP_ATTRVAL_SPI                 0x0B40
#define PRS_WAP_ATTRVAL_AACCEPT             0x0B41
#define PRS_WAP_ATTRVAL_AAUTHDATA           0x0B42
#define PRS_WAP_ATTRVAL_AAUTHLEVEL          0x0B43
#define PRS_WAP_ATTRVAL_AAUTHNAME           0x0B44
#define PRS_WAP_ATTRVAL_AAUTHSECRET         0x0B45
#define PRS_WAP_ATTRVAL_AAUTHTYPE           0x0B46
#define PRS_WAP_ATTRVAL_ADDR                0x0B47
#define PRS_WAP_ATTRVAL_ADDRTYPE            0x0B48
#define PRS_WAP_ATTRVAL_APPID               0x0B49
#define PRS_WAP_ATTRVAL_APROTOCOL           0x0B4A
#define PRS_WAP_ATTRVAL_PROVIDER_ID         0x0B4B
#define PRS_WAP_ATTRVAL_TO_PROXY            0x0B4C
#define PRS_WAP_ATTRVAL_URI                 0x0B4D
#define PRS_WAP_ATTRVAL_RULE                0x0B4E
#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
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
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
/* WLAN */
#define PRS_WAP_ATTRVAL_PRI_SSID            0x0B75
#define PRS_WAP_ATTRVAL_PRI_U_SSID          0x0B76
#define PRS_WAP_ATTRVAL_PRI_H_SSID          0x0B77
#define PRS_WAP_ATTRVAL_S_SSID              0x0B78
#define PRS_WAP_ATTRVAL_S_U_SSID            0x0B79
#define PRS_WAP_ATTRVAL_NETMODE             0x0B7A
#define PRS_WAP_ATTRVAL_SECMODE             0x0B7B
#ifndef PRS_WAP_ATTRVAL_EAPTYPE
#define PRS_WAP_ATTRVAL_EAPTYPE             0x0B7C
#endif
#define PRS_WAP_ATTRVAL_USERNAME            0x0B7D
#define PRS_WAP_ATTRVAL_PASSWORD            0x0B7E
#define PRS_WAP_ATTRVAL_REALM               0x0B7F
#define PRS_WAP_ATTRVAL_USE_PSEUD           0x0B80
#define PRS_WAP_ATTRVAL_MAXAUTHS            0x0B81
#define PRS_WAP_ATTRVAL_ENCAPS              0x0B82
#define PRS_WAP_ATTRVAL_VER_SER_REALM       0x0B83
#define PRS_WAP_ATTRVAL_CLIENT_AUTH         0x0B84
#define PRS_WAP_ATTRVAL_SES_VAL_TIME        0x0B85
#define PRS_WAP_ATTRVAL_CIP_SUIT            0x0B86
#define PRS_WAP_ATTRVAL_PEAP_V0             0x0B87
#define PRS_WAP_ATTRVAL_PEAP_V1             0x0B88
#define PRS_WAP_ATTRVAL_PEAP_V2             0x0B89
#define PRS_WAP_ATTRVAL_ISS_NAME            0x0B8A
#define PRS_WAP_ATTRVAL_SUB_NAME            0x0B8B
#define PRS_WAP_ATTRVAL_CERT_TYPE           0x0B8C
#define PRS_WAP_ATTRVAL_SER_NUM             0x0B8D
#define PRS_WAP_ATTRVAL_SUB_KEY_ID          0x0B8E
#define PRS_WAP_ATTRVAL_THUMBPRINT          0x0B8F
#define PRS_WAP_ATTRVAL_WPA_PRES_KEY_ASC    0x0B90
#define PRS_WAP_ATTRVAL_WPA_PRES_KEY_HEX    0x0B91
#define PRS_WAP_ATTRVAL_WEPKEYIND           0x0B92
#define PRS_WAP_ATTRVAL_WEPAUTHMODE         0x0B93
#define PRS_WAP_ATTRVAL_LENGTH              0x0B94
#define PRS_WAP_ATTRVAL_INDEX               0x0B95
#define PRS_WAP_ATTRVAL_DATA                0x0B96
#define PRS_WAP_ATTRVAL_WLANHAND            0x0B97
#define PRS_WAP_ATTRVAL_EDIT_SET            0x0B98
#define PRS_WAP_ATTRVAL_VIEW_SET            0x0B99
#define PRS_WAP_ATTRVAL_FORW_SET            0x0B9A
/* Application-Specific Parameters */
#define PRS_WAP_ATTRVAL_SERVICES            0x0BA0
#define PRS_WAP_ATTRVAL_CIDPREFIX           0x0BA1
#define PRS_WAP_ATTRVAL_FROM                0x0BA2
#define PRS_WAP_ATTRVAL_RT_ADDR             0x0BA3
#define PRS_WAP_ATTRVAL_CLIURI              0x0BA4
#define PRS_WAP_ATTRVAL_SYNCTYPE            0x0BA5
#define PRS_WAP_ATTRVAL_INIT                0x0BA6
#endif  /* MTK_TMP_PATCH CR27923 */


#define PRS_MAX_NBR_PARMS         32


#if defined PRS_CONFIG_WAP || defined PRS_CONFIG_WAP_WBXML
extern const msf_strtable_info_t prs_wap_Elements;
extern const msf_strtable_info_t prs_wap_Attributes;
extern const msf_strtable_info_t prs_wap_Attrvals;
extern const unsigned char       prs_wap_Element_table[];
extern const MSF_UINT16          prs_wap_AttributeTypes[];

#ifdef PRS_CONFIG_WAP_WBXML
extern const MSF_UINT8           prs_wap_AttrTransform[];
extern const msf_strtable_info_t prs_wap_AttrStart;
extern const msf_strtable_info_t prs_wap_AttrValue;


#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
#else
/* OMA Extension */
    #define PRS_WAP_TRANSFORM_SIZE 244
#endif
#else   /* MTK_TMP_PATCH CR27923 */
    #define PRS_WAP_TRANSFORM_SIZE 218
#endif  /* MTK_TMP_PATCH CR27923 */

#endif


#endif


#endif


