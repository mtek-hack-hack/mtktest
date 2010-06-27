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
/*
 * prs_xtrn.c
 *
 * External provisioning add-ons.
 */

#include "prs_type.h"
#include "prs_def.h"
#include "prs_cnst.h"
#include "prs_xtrn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_url.h"
#include "msf_cfg.h"

#ifdef WAP_SUPPORT
#include "bra_str.h"
#include "bra_if.h"
#ifdef __MMI_CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#endif
#ifdef __MMI_DUAL_SIM__
#include "ConnectManageGProt.h"
#endif
#endif


/**********************************************************************/
/*                       Network Account Add-on                       */
/**********************************************************************/

#if defined PRS_CONFIG_WAP || defined PRS_CONFIG_WAP_WBXML || \
    defined PRS_CONFIG_OTA_BROWSER || defined PRS_CONFIG_OTA_BROWSER_WBXML

/*************************************
 * Macro definitions
 *************************************/

#define PRS_EXTERNAL(n) (1L << n)

#ifdef WAP_SUPPORT
/* PRS_CCA_ENABLE_BROWSER_MMS_PROV
 *   defining this macro will trigger Browser/MMS provisioning to be directed to CCA
 *   undefine this macro to follow the existing Browser/MMS provisioning execution flow
 */
#ifdef __MMI_CCA_SUPPORT__
#define PRS_CCA_ENABLE_BROWSER_MMS_PROV
#endif
#endif

/*************************************
 * Constants
 *************************************/

/*
 * The transform tables defines what data to use when calling the
 * PRSa_networkAccount. Add or remove and renumber the items to
 * configure.
 *
 * The order within each table is not significant. 
 *
 * The numbering is what is returned to PRSa_networkAccountData as
 * 'type'. The nubers are not used by the PRS in any other way then
 * as return values and are owned by the adaptation. They can be
 * chosen in any way and does not need to be consecutive or unique.
 */

/* OTA Browser Settings */
static const prs_net_account_transform_t prs_br_transform[] = {
  {PRS_BR_ADR_ISP_NAME,              0},
  {PRS_BR_ADR_GPRS_ACCESSPOINTNAME,  1},
  {PRS_BR_ADR_PPP_LOGINTYPE,         2},
  {PRS_BR_ADR_PPP_AUTHTYPE,          3},
  {PRS_BR_ADR_PPP_AUTHNAME,          4},
  {PRS_BR_ADR_PPP_AUTHSECRET,        5},
  {PRS_BR_ADR_CSD_DIALSTRING,        6},
  {PRS_BR_ADR_CSD_CALLTYPE,          7},
  {PRS_BR_ADR_CSD_CALLSPEED,         8}
/*{PRS_BR_ADR_SMS_SMSC_ADDRESS,      -},*/
/*{PRS_BR_ADR_USSD_SERVICE_CODE,     -}*/
};

/* WAP */
static const prs_net_account_transform_t prs_wap_transform[] = {
  {PRS_WAP_NAP_NAME,                 0},
  {PRS_WAP_NAP_NAP_ADDRESS,          9},
  {PRS_WAP_NAP_NAP_ADDRTYPE,        10},
  {PRS_WAP_NAP_AUTHTYPE,            11},
  {PRS_WAP_NAP_AUTHNAME,            12},
  {PRS_WAP_NAP_AUTHSECRET,          13},
  {PRS_WAP_NAP_BEARER,              14},
  {PRS_WAP_NAP_TRAFFIC_CLASS,       15},
  {PRS_WAP_NAP_MAX_SDU_SIZE,        16},
  {PRS_WAP_NAP_LINKSPEED,           17},
  {PRS_WAP_NAP_LINGER,              18}
/*{PRS_WAP_NAP_COUNTRY,              -},*/
/*{PRS_WAP_NAP_NETWORK,              -},*/
/*{PRS_WAP_NAP_INTERNET,             -},*/
/*{PRS_WAP_NAP_DNLINKSPEED,          -},*/
/*{PRS_WAP_NAP_LOCAL_ADDR,           -},*/
/*{PRS_WAP_NAP_LOCAL_ADDRTYPE,       -},*/
/*{PRS_WAP_NAP_SID,                  -},*/
/*{PRS_WAP_NAP_SOC,                  -},*/
/*{PRS_WAP_NAP_DELIVERY_ERR_SDU,     -},*/
/*{PRS_WAP_NAP_DELIVERY_ORDER,       -},*/
/*{PRS_WAP_NAP_MAX_BITRATE_UPLINK,   -},*/
/*{PRS_WAP_NAP_MAX_BITRATE_DNLINK,   -},*/
/*{PRS_WAP_NAP_RESIDUAL_BER,         -},*/
/*{PRS_WAP_NAP_SDU_ERROR_RATIO,      -},*/
/*{PRS_WAP_NAP_CALLTYPE,             -},*/
/*{PRS_WAP_NAP_VALIDUNTIL,           -},*/
/*{PRS_WAP_NAP_TRAFFIC_HAND_PRIO,    -},*/
/*{PRS_WAP_NAP_TRANSFER_DELAY,       -},*/
/*{PRS_WAP_NAP_GUARANTEED_RATE_UP,   -},*/
/*{PRS_WAP_NAP_GUARANTEED_RATE_DN,   -}*/
};

#ifdef WAP_SUPPORT
#ifdef __MMI_CCA_SUPPORT__
/*----------------------------------------------------------------*/
/* TYPEDEFs                                                       */
/*----------------------------------------------------------------*/
typedef enum {
    PRS_CCA_CONV_STR,
    PRS_CCA_CONV_ENUM_FROM_STR,
    PRS_CCA_CONV_ENUM_FROM_ENUM,
    PRS_CCA_CONV_INT
} prs_cca_conv_type_t;

typedef struct {
    union {
        const char *s;
        const int i;
    } src;
    U16 ccaValSymbol;
} prs_cca_value_conv_t;

typedef struct {
    int prsSymbol;
    U16 ccaSymbol;
    prs_cca_conv_type_t type;
    const prs_cca_value_conv_t *enumTable;
    int enumTableSize;
} prs_cca_conversion_t;


/*----------------------------------------------------------------*/
/* ATTRIBUTE VALUES                                               */
/*----------------------------------------------------------------*/
/* PROXY: PPGAUTH-TYPE */
const prs_cca_value_conv_t prs_cca_value_authtype[] = 
{
    {(const char*)PRS_VAL_WAP_HTTP_BASIC, CCA_NS_VAL_HTTP_BASIC},
    {(const char*)PRS_VAL_WAP_HTTP_DIGEST, CCA_NS_VAL_HTTP_DIGEST},
    {(const char*)PRS_VAL_WAP_BASIC, CCA_NS_VAL_BASIC},
    {(const char*)PRS_VAL_WAP_DIGEST, CCA_NS_VAL_DIGEST}
};

/* PROXY/PXAUTHINFO: PXAUTH-TYPE*/
/* APPLICATION/APPAUTH: AAUTHTYPE */
/* APPLICATION/RESOURCE: AAUTHTYPE */
const prs_cca_value_conv_t prs_cca_value_authtype_str[] = 
{
    {"HTTP-BASIC", CCA_NS_VAL_HTTP_BASIC},
    {"HTTP-DIGEST", CCA_NS_VAL_HTTP_DIGEST},
    {"BASIC", CCA_NS_VAL_BASIC},
    {"DIGEST", CCA_NS_VAL_DIGEST},
    {"WTLS-SS", CCA_NS_VAL_WTLS_SS},
    /* Application Added Values */
    {"CRAM-MD5", CCA_NS_VAL_CRAM_MD5},
    {"DIGEST-MD5", CCA_NS_VAL_DIGEST_MD5},
    {"LOGIN", CCA_NS_VAL_LOGIN},
    {"PLAIN", CCA_NS_VAL_PLAIN},
    {"APOP", CCA_NS_VAL_APOP},
    {"GSSAPI", CCA_NS_VAL_GSSAPI},
    {"KERBEROS_V4", CCA_NS_VAL_KERBEROS_V4},
    {"SKEY", CCA_NS_VAL_SKEY},
    {"APPSRV", CCA_NS_VAL_APPSRV},
    {"CLIENT", CCA_NS_VAL_CLIENT},
    {"OBEX", CCA_NS_VAL_OBEX},
    {"X509", CCA_NS_VAL_X509},
    {"SECURID", CCA_NS_VAL_SECURID},
    {"SAFEWORD", CCA_NS_VAL_SAFEWORD},
    {"DIGIPASS", CCA_NS_VAL_DIGIPASS},
    {"HMAC", CCA_NS_VAL_HMAC},
};

/* PROXY: PXADDRTYPE */
/* NAPDEF: NAP-ADDRTYPE */
/* NAPDEF: LOCAL-ADDRTYPE */
/* APPLICATION/APPADDR: ADDRTYPE */
const prs_cca_value_conv_t prs_cca_value_addrtype[] = 
{
    {(const char*)PRS_VAL_WAP_IPV4, CCA_NS_VAL_IPV4},
    {(const char*)PRS_VAL_WAP_IPV6, CCA_NS_VAL_IPV6},
    {(const char*)PRS_VAL_WAP_E164, CCA_NS_VAL_E164},
    {(const char*)PRS_VAL_WAP_ALPHA, CCA_NS_VAL_ALPHA},
    {(const char*)PRS_VAL_WAP_APN, CCA_NS_VAL_APN},
    {(const char*)PRS_VAL_WAP_SCODE, CCA_NS_VAL_SCODE},
    {(const char*)PRS_VAL_WAP_TETRA_ITSI, CCA_NS_VAL_TETRA_ITSI},
    {(const char*)PRS_VAL_WAP_MAN, CCA_NS_VAL_MAN}
};

/* PROXY: PUSHENABLED/PULLENABLED */
const prs_cca_value_conv_t prs_cca_value_enabled[] = 
{
    {(const char*)0, CCA_NS_VAL_DISABLED},
    {(const char*)1, CCA_NS_VAL_ENABLED}
};

/* PROXY/PORT: SERVICE */
const prs_cca_value_conv_t prs_cca_value_service[] = 
{
    {(const char*)PRS_VAL_WAP_CL_WSP, CCA_NS_VAL_CL_WSP},
    {(const char*)PRS_VAL_WAP_CO_WSP, CCA_NS_VAL_CO_WSP},
    {(const char*)PRS_VAL_WAP_CL_SEC_WSP, CCA_NS_VAL_CL_SEC_WSP},
    {(const char*)PRS_VAL_WAP_CO_SEC_WSP, CCA_NS_VAL_CO_SEC_WSP},
    //{"CO-SEC-WTA", CCA_NS_VAL_CO_SEC_WTA},
    //{"CL-SEC-WTA", CCA_NS_VAL_CL_SEC_WTA},
    {(const char*)PRS_VAL_WAP_OTA_HTTP_TO, CCA_NS_VAL_OTA_HTTP_TO},
    {(const char*)PRS_VAL_WAP_OTA_HTTP_TLS_TO, CCA_NS_VAL_OTA_HTTP_TLS_TO},
    {(const char*)PRS_VAL_WAP_OTA_HTTP_PO, CCA_NS_VAL_OTA_HTTP_PO},
    {(const char*)PRS_VAL_WAP_OTA_HTTP_TLS_PO, CCA_NS_VAL_OTA_HTTP_TLS_PO}
};

/* NAPDEF: BEARER */
const prs_cca_value_conv_t prs_cca_value_bearer[] = 
{
    {(const char*)PRS_VAL_WAP_GSM_CSD, CCA_NS_VAL_GSM_CSD},
    {(const char*)PRS_VAL_WAP_GSM_GPRS, CCA_NS_VAL_GSM_GPRS},
    {(const char*)PRS_VAL_WAP_GSM_USSD, CCA_NS_VAL_GSM_USSD},
    {(const char*)PRS_VAL_WAP_GSM_SMS, CCA_NS_VAL_GSM_SMS},
    {(const char*)PRS_VAL_WAP_CDMA_SMS, CCA_NS_VAL_CDMA_SMS},
    {(const char*)PRS_VAL_WAP_CDMA_CSD, CCA_NS_VAL_CDMA_CSD},
    {(const char*)PRS_VAL_WAP_CDMA_PACKET, CCA_NS_VAL_CDMA_PACKET},
    {(const char*)PRS_VAL_WAP_ANSI_136_GUTS, CCA_NS_VAL_ANSI_136_GUTS},
    {(const char*)PRS_VAL_WAP_ANSI_136_CSD, CCA_NS_VAL_ANSI_136_CSD},
    {(const char*)PRS_VAL_WAP_ANSI_136_GPRS, CCA_NS_VAL_ANSI_136_GPRS},
    {(const char*)PRS_VAL_WAP_ANSI_136_GHOST, CCA_NS_VAL_ANSI_136_GHOST},
    {(const char*)PRS_VAL_WAP_AMPS_CDPD, CCA_NS_VAL_AMPS_CDPD},
    {(const char*)PRS_VAL_WAP_PDC_CSD, CCA_NS_VAL_PDC_CSD},
    {(const char*)PRS_VAL_WAP_PDC_PACKET, CCA_NS_VAL_PDC_PACKET},
    {(const char*)PRS_VAL_WAP_IDEN_SMS, CCA_NS_VAL_IDEN_SMS},
    {(const char*)PRS_VAL_WAP_IDEN_CSD, CCA_NS_VAL_IDEN_CSD},
    {(const char*)PRS_VAL_WAP_IDEN_PACKET, CCA_NS_VAL_IDEN_PACKET},
    {(const char*)PRS_VAL_WAP_FLEX_REFLEX, CCA_NS_VAL_FLEX_REFLEX},
    {(const char*)PRS_VAL_WAP_PHS_SMS, CCA_NS_VAL_PHS_SMS},
    {(const char*)PRS_VAL_WAP_PHS_CSD, CCA_NS_VAL_PHS_CSD},
    {(const char*)PRS_VAL_WAP_TETRA_SDS, CCA_NS_VAL_TETRA_SDS},
    {(const char*)PRS_VAL_WAP_TETRA_PACKET, CCA_NS_VAL_TETRA_PACKET},
    {(const char*)PRS_VAL_WAP_MOBITEX_MPAK, CCA_NS_VAL_MOBITEX_MPAK},
    {(const char*)PRS_VAL_WAP_CDMA2000_1X_SIMPLE_IP, CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP},
    {(const char*)PRS_VAL_WAP_CDMA2000_1X_MOBILE_IP, CCA_NS_VAL_CDMA2000_1X_MOBILE_IP}
};

/* NAPDEF: CALLTYPE */
const prs_cca_value_conv_t prs_cca_value_calltype[] = 
{
    {(const char*)PRS_VAL_WAP_ANALOG_MODEM, CCA_NS_VAL_ANALOG_MODEM},
    {(const char*)PRS_VAL_WAP_V120, CCA_NS_VAL_V120},
    {(const char*)PRS_VAL_WAP_V110, CCA_NS_VAL_V110},
    {(const char*)PRS_VAL_WAP_X31, CCA_NS_VAL_X31},
    {(const char*)PRS_VAL_WAP_BIT_TRANSP, CCA_NS_VAL_BIT_TRANSPARENT},
    {(const char*)PRS_VAL_WAP_DIRECT_ASYNC, CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE}
};

/* NAPDEF: LINKSPEED */
/* NAPDEF: DNLINKSPEED */
const prs_cca_value_conv_t prs_cca_value_linkspeed[] = 
{
    {(const char*)PRS_VAL_WAP_AUTOBAUDING, 0}
    //or any numeric numbers
};

/* NAPDEF/NAPAUTHINFO: AUTHTYPE */
const prs_cca_value_conv_t prs_cca_value_napauthtype[] = 
{
    {"PAP", CCA_NS_VAL_PAP},
    {"CHAP", CCA_NS_VAL_CHAP},
    {"MD5", CCA_NS_VAL_MD5}
};

/* NAPDEF/NAPAUTHINFO: AUTH-ENTITY */
const prs_cca_value_conv_t prs_cca_value_napauthentity[] = 
{
    {(const char*)PRS_VAL_WAP_AAA, CCA_NS_VAL_AAA},
    {(const char*)PRS_VAL_WAP_HA, CCA_NS_VAL_HA}
};

/* APPLICATION/APPAUTH: AAUTHLEVEL */
const prs_cca_value_conv_t prs_cca_value_aauthlevel[] = 
{
    {"APPSRV", CCA_NS_VAL_APPSRV},
    {"OBEX", CCA_NS_VAL_OBEX},
    {"CLIENT", CCA_NS_VAL_CLIENT}
};

/* APPLICATION/APPADDR: SERVICE */
const prs_cca_value_conv_t prs_cca_value_appportservice[] = 
{
    {"CL-WSP", CCA_NS_VAL_CL_WSP},
    {"CO-WSP", CCA_NS_VAL_CO_WSP},
    {"CL-SEC-WSP", CCA_NS_VAL_CL_SEC_WSP},
    {"CO-SEC-WSP", CCA_NS_VAL_CO_SEC_WSP},
    {"CO-SEC-WTA", CCA_NS_VAL_CO_SEC_WTA},
    {"CL-SEC-WTA", CCA_NS_VAL_CL_SEC_WTA},
    {"OTA-HTTP-TO", CCA_NS_VAL_OTA_HTTP_TO},
    {"OTA-HTTP-TLS-TO", CCA_NS_VAL_OTA_HTTP_TLS_TO},
    {"OTA-HTTP-PO", CCA_NS_VAL_OTA_HTTP_PO},
    {"OTA-HTTP-TLS-PO", CCA_NS_VAL_OTA_HTTP_TLS_PO},

    {"STARTTLS", CCA_NS_VAL_STARTTLS},
};

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
#endif  /* PRS_CONFIG_DMP_SUPPORT */


/* OMA Extension */
/* WLAN: NETMODE */
const prs_cca_value_conv_t prs_cca_value_wlan_netmode[] = 
{
    {"INFRA", CCA_NS_VAL_INFRA},
    {"ADHOC", CCA_NS_VAL_ADHOC}
};
/* WLAN: SECMODE */
const prs_cca_value_conv_t prs_cca_value_wlan_secmode[] = 
{
    {"WEP", CCA_NS_VAL_WEP},
    {"8021X", CCA_NS_VAL_8021X},
    {"WPA", CCA_NS_VAL_WPA},
    {"WPA-PRESHARED-KEY", CCA_NS_VAL_WPA_PRESHARED_KEY},
    {"WPA2", CCA_NS_VAL_WPA2},
    {"WPA2-PRESHARED-KEY", CCA_NS_VAL_WPA2_PRESHARED_KEY}
};
/* WLAN: WEPAUTHMODE */
const prs_cca_value_conv_t prs_cca_value_wlan_wepauthmode[] = 
{
    {"OPEN", CCA_NS_VAL_OPEN},
    {"SHARED", CCA_NS_VAL_SHARED}
};
/* WLAN: EAP-TYPE */
const prs_cca_value_conv_t prs_cca_value_wlan_eaptype[] = 
{
    {"EAP-SIM", CCA_NS_VAL_EAP_SIM},
    {"EAP-AKA", CCA_NS_VAL_EAP_AKA},
    {"EAP-TLS", CCA_NS_VAL_EAP_TLS},
    {"EAP-PEAP", CCA_NS_VAL_EAP_PEAP},
    {"EAP-TTLS", CCA_NS_VAL_EAP_TTLS},
    {"EAP-LEAP", CCA_NS_VAL_EAP_LEAP},
    {"EAP-MSCHAPV2", CCA_NS_VAL_EAP_MSCHAPV2},
    {"EAP-GTC", CCA_NS_VAL_EAP_GTC}
};
/* WLAN: CERT-TYPE */
const prs_cca_value_conv_t prs_cca_value_wlan_certtype[] = 
{
    {"USER", CCA_NS_VAL_USER},
    {"CA", CCA_NS_VAL_CA}
};


/*----------------------------------------------------------------*/
/* MAPPING TABLE: PRS -> CCA                                      */
/*----------------------------------------------------------------*/
/* PROXY */
const prs_cca_conversion_t prs_cca_conv_proxy_table[] = {
    { PRS_WAP_PX_PROXY_ID, CCA_NS_OMA_PROXY_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_PROXY_PW, CCA_NS_OMA_PROXY_PW, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_PPGAUTH_TYPE, CCA_NS_OMA_PPGAUTH_TYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_authtype, sizeof(prs_cca_value_authtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_PX_PROXY_PROVIDER_ID, CCA_NS_OMA_PROXY_PROVIDER_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_NAME, CCA_NS_OMA_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_TRUST, CCA_NS_OMA_TRUST, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_MASTER, CCA_NS_OMA_MASTER, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_STARTPAGE, CCA_NS_OMA_STARTPAGE, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_BASAUTH_ID, CCA_NS_OMA_BASAUTH_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_BASAUTH_PW, CCA_NS_OMA_BASAUTH_PW, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_WSP_VERSION, CCA_NS_OMA_WSP_VERSION, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_PUSHENABLED, CCA_NS_OMA_PUSHENABLED, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_enabled, sizeof(prs_cca_value_enabled)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_PX_PULLENABLED, CCA_NS_OMA_PULLENABLED, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_enabled, sizeof(prs_cca_value_enabled)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_PX_PHYSICAL_PROXY_ID, CCA_NS_OMA_PHYSICAL_PROXY_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_PXADDR, CCA_NS_OMA_PXADDR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_PXADDRTYPE, CCA_NS_OMA_PXADDRTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_addrtype, sizeof(prs_cca_value_addrtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_PX_PXADDR_FQDN, CCA_NS_OMA_PXADDR_FQDN, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_PX_TO_NAPID, CCA_NS_OMA_TO_NAPID, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_PX_PXAUTH_TYPE, CCA_NS_OMA_PXAUTH_TYPE, PRS_CCA_CONV_ENUM, prs_cca_value_authtype_str, sizeof(prs_cca_value_authtype_str)/sizeof(prs_cca_value_conv_t) },
    //{ PRS_WAP_PX_PXAUTH_ID, CCA_NS_OMA_PXAUTH_ID, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_PX_PXAUTH_PW, CCA_NS_OMA_PXAUTH_PW, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_PX_PORTNBR, CCA_NS_OMA_PORTNBR, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_PX_SERVICE, CCA_NS_OMA_SERVICE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_service, sizeof(prs_cca_value_service)/sizeof(prs_cca_value_conv_t) },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* NAPDEF */
const prs_cca_conversion_t prs_cca_conv_napdef_table[] = {
    { PRS_WAP_NAP_NAPID, CCA_NS_OMA_NAPID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_BEARER, CCA_NS_OMA_BEARER, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_bearer, sizeof(prs_cca_value_bearer)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_NAME, CCA_NS_OMA_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_INTERNET, CCA_NS_OMA_INTERNET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_NAP_ADDRESS, CCA_NS_OMA_NAP_ADDRESS, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_NAP_ADDRTYPE, CCA_NS_OMA_NAP_ADDRTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_addrtype, sizeof(prs_cca_value_addrtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_DNS_ADDR, CCA_NS_OMA_DNS_ADDR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_CALLTYPE, CCA_NS_OMA_CALLTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_calltype, sizeof(prs_cca_value_calltype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_LOCAL_ADDR, CCA_NS_OMA_LOCAL_ADDR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_LOCAL_ADDRTYPE, CCA_NS_OMA_LOCAL_ADDRTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_addrtype, sizeof(prs_cca_value_addrtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_LINKSPEED, CCA_NS_OMA_LINKSPEED, PRS_CCA_CONV_INT, prs_cca_value_linkspeed, sizeof(prs_cca_value_linkspeed)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_DNLINKSPEED, CCA_NS_OMA_DNLINKSPEED, PRS_CCA_CONV_INT, prs_cca_value_linkspeed, sizeof(prs_cca_value_linkspeed)/sizeof(prs_cca_value_conv_t) },

    { PRS_WAP_NAP_LINGER, CCA_NS_OMA_LINGER, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_DELIVERY_ERR_SDU, CCA_NS_OMA_DELIVERY_ERR_SDU, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_DELIVERY_ORDER, CCA_NS_OMA_DELIVERY_ORDER, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_TRAFFIC_CLASS, CCA_NS_OMA_TRAFFIC_CLASS, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_MAX_SDU_SIZE, CCA_NS_OMA_MAX_SDU_SIZE, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_MAX_BITRATE_UPLINK, CCA_NS_OMA_MAX_BITRATE_UPLINK, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_MAX_BITRATE_DNLINK, CCA_NS_OMA_MAX_BITRATE_DNLINK, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_RESIDUAL_BER, CCA_NS_OMA_RESIDUAL_BER, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_SDU_ERROR_RATIO, CCA_NS_OMA_SDU_ERROR_RATIO, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_TRAFFIC_HAND_PRIO, CCA_NS_OMA_TRAFFIC_HANDL_PRIO, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_TRANSFER_DELAY, CCA_NS_OMA_TRANSFER_DELAY, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_GUARANTEED_RATE_UP, CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_GUARANTEED_RATE_DN, CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_MAX_NUM_RETRY, CCA_NS_OMA_MAX_NUM_RETRY, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_FIRST_RETRY_TIMEOUT, CCA_NS_OMA_FIRST_RETRY_TIMEOUT, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_REREG_THRESHOLD, CCA_NS_OMA_REREG_THRESHOLD, PRS_CCA_CONV_INT, 0, 0 },
    { PRS_WAP_NAP_T_BIT, CCA_NS_OMA_T_BIT, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* NAPAUTHINFO */
const prs_cca_conversion_t prs_cca_conv_napauthinfo_table[] = {
    { PRS_WAP_NAP_AUTHTYPE, CCA_NS_OMA_AUTHTYPE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_napauthtype, sizeof(prs_cca_value_napauthtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_AUTHNAME, CCA_NS_OMA_AUTHNAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_AUTHSECRET, CCA_NS_OMA_AUTHSECRET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_AUTH_ENTITY, CCA_NS_OMA_AUTH_ENTITY, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_napauthentity, sizeof(prs_cca_value_napauthentity)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_NAP_SPI, CCA_NS_OMA_SPI, PRS_CCA_CONV_STR, 0, 0},
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* VALIDITY */
const prs_cca_conversion_t prs_cca_conv_validity_table[] = {
    { PRS_WAP_NAP_COUNTRY, CCA_NS_OMA_COUNTRY, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_NETWORK, CCA_NS_OMA_NETWORK, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_SID, CCA_NS_OMA_SID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_SOC, CCA_NS_OMA_SOC, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_NAP_VALIDUNTIL, CCA_NS_OMA_VALIDUNTIL, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* BOOTSTRAP */
const prs_cca_conversion_t prs_cca_conv_bootstrap_table[] = {
    { PRS_WAP_BTS_NAME, CCA_NS_OMA_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_BTS_NETWORK, CCA_NS_OMA_NETWORK, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_BTS_COUNTRY, CCA_NS_OMA_COUNTRY, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_BTS_PROXY_ID, CCA_NS_OMA_PROXY_ID, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* APPLICATION */
const prs_cca_conversion_t prs_cca_conv_application_table[] = {
    { PRS_WAP_APP_APPID, CCA_NS_OMA_APPID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_PROVIDER_ID, CCA_NS_OMA_PROVIDER_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_NAME, CCA_NS_OMA_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_AACCEPT, CCA_NS_OMA_AACCEPT, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_APROTOCOL, CCA_NS_OMA_APROTOCOL, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_TO_PROXY, CCA_NS_OMA_TO_PROXY, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_APP_TO_NAPID, CCA_NS_OMA_TO_NAPID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_ADDR, CCA_NS_OMA_ADDR, PRS_CCA_CONV_STR, 0, 0 },
    /* SMTP symbols */
    { PRS_WAP_APP_FROM, CCA_NS_OMA_FROM, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RT_ADDR, CCA_NS_OMA_RT_ADDR, PRS_CCA_CONV_STR, 0, 0 },
    /* IMPS symbols */
    { PRS_WAP_APP_CIDPREFIX, CCA_NS_OMA_CIDPREFIX, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_SERVICES, CCA_NS_OMA_SERVICES, PRS_CCA_CONV_STR, 0, 0 },
    /* SyncML-DM symbols */
    { PRS_WAP_APP_INIT, CCA_NS_OMA_INIT, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* APPADDR */
const prs_cca_conversion_t prs_cca_conv_appaddr_table[] = {
    { PRS_WAP_APP_ADDR2, CCA_NS_OMA_ADDR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_ADDRTYPE, CCA_NS_OMA_ADDRTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_addrtype, sizeof(prs_cca_value_addrtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_APP_PORTNBR, CCA_NS_OMA_PORTNBR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_SERVICE, CCA_NS_OMA_SERVICE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_appportservice, sizeof(prs_cca_value_appportservice)/sizeof(prs_cca_value_conv_t) },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* APPAUTH */
const prs_cca_conversion_t prs_cca_conv_appauth_table[] = {
    { PRS_WAP_APP_AAUTHLEVEL, CCA_NS_OMA_AAUTHLEVEL, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_aauthlevel, sizeof(prs_cca_value_aauthlevel)/sizeof(prs_cca_value_conv_t) },    
    //{ PRS_WAP_APP_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_authtype, sizeof(prs_cca_value_authtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_APP_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_authtype_str, sizeof(prs_cca_value_authtype_str)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_APP_AAUTHNAME, CCA_NS_OMA_AAUTHNAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_AAUTHSECRET, CCA_NS_OMA_AAUTHSECRET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_AAUTHDATA, CCA_NS_OMA_AAUTHDATA, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* RESOURCE */
const prs_cca_conversion_t prs_cca_conv_resource_table[] = {
    { PRS_WAP_APP_RES_URI, CCA_NS_OMA_URI, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_NAME, CCA_NS_OMA_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_AACCEPT, CCA_NS_OMA_AACCEPT, PRS_CCA_CONV_STR, 0, 0 },
    //{ PRS_WAP_APP_RES_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PRS_CCA_CONV_ENUM_FROM_ENUM, prs_cca_value_authtype, sizeof(prs_cca_value_authtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_APP_RES_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_authtype_str, sizeof(prs_cca_value_authtype_str)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_APP_RES_AAUTHNAME, CCA_NS_OMA_AAUTHNAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_AAUTHSECRET, CCA_NS_OMA_AAUTHSECRET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_AAUTHDATA, CCA_NS_OMA_AAUTHDATA, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_STARTPAGE, CCA_NS_OMA_STARTPAGE, PRS_CCA_CONV_STR, 0, 0 },
    /* SyncML-DM symbols */
    { PRS_WAP_APP_RES_CLIURI, CCA_NS_OMA_CLIURI, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_APP_RES_SYNCTYPE, CCA_NS_OMA_SYNCTYPE, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

/* ACCESS */
const prs_cca_conversion_t prs_cca_conv_access_table[] = {
    { PRS_WAP_ACC_RULE, CCA_NS_OMA_RULE, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_ACC_APPID, CCA_NS_OMA_APPID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_ACC_PORTNBR, CCA_NS_OMA_PORTNBR, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_ACC_DOMAIN, CCA_NS_OMA_DOMAIN, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_ACC_TO_NAPID, CCA_NS_OMA_TO_NAPID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_ACC_TO_PROXY, CCA_NS_OMA_TO_PROXY, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};

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
const prs_cca_conversion_t prs_cca_conv_wlan_table[] =
{
    { PRS_WAP_WLAN_PRI_SSID, CCA_NS_OMA_PRI_SSID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_PRI_U_SSID, CCA_NS_OMA_PRI_U_SSID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_PRI_H_SSID, CCA_NS_OMA_PRI_H_SSID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_NETMODE, CCA_NS_OMA_NETMODE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_wlan_netmode, sizeof(prs_cca_value_wlan_netmode)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_WLAN_SECMODE, CCA_NS_OMA_SECMODE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_wlan_secmode, sizeof(prs_cca_value_wlan_secmode)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_WLAN_WPA_PRES_KEY_ASC, CCA_NS_OMA_WPA_PRES_KEY_ASC, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_WPA_PRES_KEY_HEX, CCA_NS_OMA_WPA_PRES_KEY_HEX, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_WEPKEYIND, CCA_NS_OMA_WEPKEYIND, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_WEPAUTHMODE, CCA_NS_OMA_WEPAUTHMODE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_wlan_wepauthmode, sizeof(prs_cca_value_wlan_wepauthmode)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_WLAN_WLANHAND, CCA_NS_OMA_WLANHAND, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_EDIT_SET, CCA_NS_OMA_EDIT_SET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_VIEW_SET, CCA_NS_OMA_VIEW_SET, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WLAN_FORW_SET, CCA_NS_OMA_FORW_SET, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};
/* WLAN/SEC-SSID */
const prs_cca_conversion_t prs_cca_conv_secssid_table[] =
{
    { PRS_WAP_SEC_SSID_S_SSID, CCA_NS_OMA_S_SSID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_SEC_SSID_S_U_SSID, CCA_NS_OMA_S_U_SSID, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};
/* WLAN/EAP */
const prs_cca_conversion_t prs_cca_conv_eap_table[] =
{
    { PRS_WAP_EAP_EAPTYPE, CCA_NS_OMA_EAPTYPE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_wlan_eaptype, sizeof(prs_cca_value_wlan_eaptype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_EAP_USERNAME, CCA_NS_OMA_USERNAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_PASSWORD, CCA_NS_OMA_PASSWORD, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_REALM, CCA_NS_OMA_REALM, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_USE_PSEUD, CCA_NS_OMA_USE_PSEUD, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_MAXAUTHS, CCA_NS_OMA_MAXAUTHS, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_ENCAPS, CCA_NS_OMA_ENCAPS, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_VER_SER_REALM, CCA_NS_OMA_VER_SER_REALM, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_CLIENT_AUTH, CCA_NS_OMA_CLIENT_AUTH, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_SES_VAL_TIME, CCA_NS_OMA_SES_VAL_TIME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_CIP_SUIT, CCA_NS_OMA_CIP_SUIT, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_PEAP_V0, CCA_NS_OMA_PEAP_V0, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_PEAP_V1, CCA_NS_OMA_PEAP_V1, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_EAP_PEAP_V2, CCA_NS_OMA_PEAP_V2, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};
/* WLAN/CERT */
const prs_cca_conversion_t prs_cca_conv_cert_table[] =
{
    { PRS_WAP_CERT_ISS_NAME, CCA_NS_OMA_ISS_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_CERT_SUB_NAME, CCA_NS_OMA_SUB_NAME, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_CERT_CERT_TYPE, CCA_NS_OMA_CERT_TYPE, PRS_CCA_CONV_ENUM_FROM_STR, prs_cca_value_wlan_certtype, sizeof(prs_cca_value_wlan_certtype)/sizeof(prs_cca_value_conv_t) },
    { PRS_WAP_CERT_SER_NUM, CCA_NS_OMA_SER_NUM, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_CERT_SUB_KEY_ID, CCA_NS_OMA_SUB_KEY_ID, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_CERT_THUMBPRINT, CCA_NS_OMA_THUMBPRINT, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};
/* WLAN/WEPKEY */
const prs_cca_conversion_t prs_cca_conv_wepkey_table[] =
{
    { PRS_WAP_WEPKEY_LENGTH, CCA_NS_OMA_LENGTH, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WEPKEY_INDEX, CCA_NS_OMA_INDEX, PRS_CCA_CONV_STR, 0, 0 },
    { PRS_WAP_WEPKEY_DATA, CCA_NS_OMA_DATA, PRS_CCA_CONV_STR, 0, 0 },
    { 0xFFFFFFFF, 0xFFFF, PRS_CCA_CONV_STR, 0, 0 }
};


/*----------------------------------------------------------------*/
/* PRS -> CCA CONVERSION TABLES SUMMARY                           */
/*----------------------------------------------------------------*/
const prs_cca_conversion_t* prs_cca_conv_table_summary[] =
{
  0, /* 0th index */
  prs_cca_conv_proxy_table, /* PRS_WAP_PROXY */
  prs_cca_conv_napdef_table, /* PRS_WAP_NAPDEF */
  prs_cca_conv_bootstrap_table, /* PRS_WAP_BOOTSTRAP */
  0, /* PRS_WAP_VENDORCONFIG */
  0, /* PRS_WAP_CLIENTIDENTITY */
  prs_cca_conv_application_table, /* PRS_WAP_APPLICATION */
  prs_cca_conv_access_table, /* PRS_WAP_ACCESS */
  0, /* PRS_WAP_PXPHYSICAL */
  0, /* PRS_WAP_PXAUTHINFO */
  prs_cca_conv_validity_table, /* PRS_WAP_VALIDITY */
  prs_cca_conv_napauthinfo_table, /* PRS_WAP_NAPAUTHINFO */
  0, /* PRS_WAP_PORT_PXL */
  0, /* PRS_WAP_PORT_PXP */
  prs_cca_conv_appaddr_table, /* PRS_WAP_APPADDR */
  prs_cca_conv_appauth_table, /* PRS_WAP_APPAUTH */
  prs_cca_conv_resource_table, /* PRS_WAP_RESOURCE */
  0, /* PRS_WAP_PXLOGICAL */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
  0, /* */
  0, /* */
  0, /* */
  0, /* */
  0, /* */
  0, /* */
#endif
/* OMA Extension */
  prs_cca_conv_wlan_table, /* PRS_WAP_WLAN */
  prs_cca_conv_secssid_table, /* PRS_WAP_SEC_SSID */
  prs_cca_conv_eap_table, /* PRS_WAP_EAP */
  prs_cca_conv_cert_table, /* PRS_WAP_CERT */
  prs_cca_conv_wepkey_table /* PRS_WAP_WEPKEY */
};
#endif  /* __MMI_CCA_SUPPORT__ */
#endif  /* WAP_SUPPORT */

/*
 * Registry values for the MMSC provisioning.
 * Must be syncronized with the MMS application.
 */
#define PRS_REG_PATH_MMSC               "/MMS/com/mmsc"
#define PRS_REG_KEY_MMSC_PORT           "Port"
#define PRS_REG_KEY_MMSC_PATH           "Uri"
#define PRS_REG_KEY_MMSC_HOST           "Name"
#define PRS_REG_KEY_MMSC_SCHEME         "Scheme"

/*************************************
 * External functions
 *************************************/
extern PRSa_networkAccountData (const prs_net_account_data_t* netAccountData, int size);


/*************************************
 * Functions
 *************************************/


#ifdef __MMI_DUAL_SIM__
MSF_UINT16
prs_get_sim_id(int network_account_id)
{
  always_ask_sim_info_enum simid;

  simid = always_ask_get_sim_info_data_account((kal_uint32)network_account_id);
  if (simid == ALWAYS_ASK_SIM_INFO_SIM2)
    return PRS_VAL_SIM_2;

  return PRS_VAL_SIM_1;
}
#endif

void
prs_br_add_sim_id_to_output(prs_node_list_t* list)
{
  extern void prs_output_path (prs_output_obj_t* obj, int path);

  if (list)
  {
    extern prs_output_obj_t* prs_get_object(prs_node_list_t* list, int dest);
    prs_output_obj_t *obj;
    MSF_UINT32 val_int;

    obj = (prs_output_obj_t*)prs_get_object(list, MSF_MODID_BRA);
    if (obj == NULL)
      return;

#ifdef __MMI_DUAL_SIM__
    val_int = (MSF_UINT32)prs_get_sim_id(list->network_account_id);
#else
    val_int = PRS_VAL_SIM_1;
#endif

    prs_output_path(obj, PRS_PATH_MTK_INFO);
    prs_output_add(obj, PRS_OUTPUT_INT, prs_Str_resources[PRS_STR_MTK_SIM_ID], val_int, NULL);
  }
}


/* 
 * Network account provisioning
 * ----------------------------
 *
 * Go through the list and extact network account information.
 * The information is passed on to PRSa_networkAccountData and
 * the returned id is saved in the user data element node in the
 * list.
 *
 * If data for multiple accounts are present in the list, then
 * PRSa_networkAccountData is called one time for each set of data.
 * Only the account id returned first is saved.
 */
static void
prs_net_account_process (prs_node_list_t* list,
                         int              element,
                         int              elementSize,
                         const prs_net_account_transform_t* transform,
                         int              transformSize)
{
  prs_net_account_data_t* netAccountData;
  prs_node_t* node;
  MSF_UINT32  externalFieldsLow;
  MSF_UINT32  externalFieldsHigh;
  MSF_UINT32  temp;
  int         netAccountId;
  int         fieldsToExport;
  int         pos;
  int         field;
  
  node = list->firstNode;
  
  for (node = list->firstNode; node; node = node->next) {
    if (node->element != element)
      continue;

    /* Build a bit array with the fields containing data to export */
    externalFieldsLow = 0;
    externalFieldsHigh = 0;
    for (pos = 0; pos < transformSize; pos++)
      if (transform[pos].field < PRS_FIELD_HIGH_START)
        externalFieldsLow |= 1L << transform[pos].field;
      else
        externalFieldsHigh |= 1L << (transform[pos].field - PRS_FIELD_HIGH_START);
    externalFieldsLow  &= node->usedLow;
    externalFieldsHigh &= node->usedHigh;

    /* Count the fields to export */
    fieldsToExport = 0;
    temp = externalFieldsLow;
    while (temp > 0) {
      if (temp & 1)
        fieldsToExport++;
      temp >>= 1;
    }
    temp = externalFieldsHigh;
    while (temp > 0) {
      if (temp & 1)
        fieldsToExport++;
      temp >>= 1;
    }

    if (fieldsToExport == 0) /* No network account information */
      break;    
    
    /* Copy data to the netAccountData array */
    netAccountData = PRS_ALLOC (sizeof (prs_net_account_data_t) * fieldsToExport);
    pos = 0;
   
    for (field = 0; field < elementSize; field++) {
      if (((field < PRS_FIELD_HIGH_START) && (externalFieldsLow & (1L << field))) || 
          ((field >= PRS_FIELD_HIGH_START) && (externalFieldsHigh & (1L << (field - PRS_FIELD_HIGH_START))))) { /* This is an used field with net account data */
        int i;
        prs_field_t *fieldPtr;

        for (i = 0; i < transformSize; i++) {
          if (transform[i].field == field)
            break;
        }
        netAccountData[pos].type     = transform[i].number;
        netAccountData[pos].isString = prs_is_string (node, field);

       
        if (prs_is_multi (node, field))
          fieldPtr = node->fieldVec[field].next;
        else
          fieldPtr = &node->fieldVec[field];

        if (prs_is_string (node, field)) {
          netAccountData[pos].value.s = fieldPtr->data.s;
          if (netAccountData[pos].value.s != NULL)
            netAccountData[pos].strLen = strlen (netAccountData[pos].value.s);
          else
            netAccountData[pos].strLen = 0;
        } else {
          netAccountData[pos].value.i = fieldPtr->data.i;
          netAccountData[pos].strLen = 0;
        }
        pos++;
      }
    }

    /* Export data and save the returned value in the user data
     * element node. The id is late extracted by the normal
     * filtering process and sent together with other data in
     * a signal.
     * 
     * If a network account id has set in the user data, the
     * new account id is ignored. */
    netAccountId = PRSa_networkAccountData (netAccountData, fieldsToExport);
    prs_set_field (list->userDataNode, PRS_USER_DATA, FALSE, netAccountId, NULL);
    PRS_FREE (netAccountData);
  }  
}


#if 0
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
#endif /* #if 0 */

#endif


/**********************************************************************/
/*                            OTA Settings                            */
/*                Browser Settings & Browser Bookmarks                */
/**********************************************************************/

#if defined PRS_CONFIG_OTA_BROWSER || defined PRS_CONFIG_OTA_BROWSER_WBXML


/*************************************
 * Functions
 *************************************/

/*
 * Process node list. Pre-processing step.
 */
int
prs_br_process_list_pre (prs_node_list_t* list)
{
  prs_net_account_process (list,
                           PRS_BR_ADDRESS,
                           PRS_BR_ADDRESS_SIZE,
                           prs_br_transform,
                           sizeof (prs_br_transform) / sizeof (prs_net_account_transform_t));

  prs_br_add_sim_id_to_output(list);

  /* MMS configuration is removed because following function commits MMS settings to registry directly!
     but we need to save it to user-selected profile first (to file), and only commit to registry if user activates that profile */
  /* prs_mmsc_process (list); */

  return PRS_STATUS_OK;
}



/*
 * Process node.
 */
int
prs_br_process_node (prs_node_t* node)
{
  node = node;

  return PRS_STATUS_OK;
}



/*
 * Process node list. Post-processing step.
 */
int
prs_br_process_list_post (prs_node_list_t* list)
{
  list = list;

  prs_br_add_sim_id_to_output(list);
  return PRS_STATUS_OK;
}


#endif


/**********************************************************************/
/*                            OTA Settings                            */
/*                           SyncML settings                          */
/**********************************************************************/

#if defined PRS_CONFIG_OTA_SYNCML || defined PRS_CONFIG_OTA_SYNCML_WBXML

/************************************
 * Constants
 ************************************/

 
/************************************
 * Macro definitions
 ************************************/


/************************************
 * Type definitions
 ************************************/

 
/************************************
 * Function declaration
 ************************************/


/*************************************
 * Constants
 *************************************/


/*************************************
 * Functions
 *************************************/

/*
 * Process node list. Pre-processing step.
 */
int
prs_syn_process_list_pre (prs_node_list_t* list)
{
  list = list;

  return PRS_STATUS_OK;
}



/*
 * Process node.
 */
int
prs_syn_process_node (prs_node_t* node)
{
  node = node;

  return PRS_STATUS_OK;
}



/*
 * Process node list. Post-processing step.
 */
int
prs_syn_process_list_post (prs_node_list_t* list)
{
  list = list;

  return PRS_STATUS_OK;
}

#endif



/**********************************************************************/
/*                          WAP Provisioning                          */
/**********************************************************************/

#if defined PRS_CONFIG_WAP || defined PRS_CONFIG_WAP_WBXML


/*************************************
 * Functions
 *************************************/
#ifdef WAP_SUPPORT
#ifdef __MMI_CCA_SUPPORT__

static S8 prs_wap_cca_nodeid = (S8)'0';
#define PRS_CCA_NODEID_SIZE 2

S8* prs_wap_process_get_next_nodeid(S8 nodeid[2])
{
    nodeid[0] = prs_wap_cca_nodeid;
    nodeid[1] = 0;

    prs_wap_cca_nodeid++;
    if (prs_wap_cca_nodeid > 'z')
	  prs_wap_cca_nodeid = '0';

    return nodeid;
}

int
prs_wap_process_fill_cca_node_strings(prs_node_t *prsnode, S32 ccanode, const int mapping[][2])
{
  /* returns 1:success, 0:mem full(failed) */
  int i = 0;
  
  while ( mapping[i][0]!=0xFFFFFFFF )
  {
    if (prs_is_used(prsnode, mapping[i][0]))
    {
      if (CCA_STATUS_MEMFULL == mmi_cca_doc_add_nodedata_str(ccanode, (U16)(mapping[i][1]), (const S8*)(prsnode->fieldVec[mapping[i][0]].data.s)))
        return 0;
    }
    i++;
  }
  return 1;
}

int
prs_wap_process_get_enum(char *prsValue, const prs_cca_value_conv_t valuesTable[], int size)
{
    int i;

    if (prsValue == 0)
        return CCA_NS_VAL__EMPTY;

    for (i=0; i<size; i++)
        if (strcmp(prsValue, valuesTable[i].src.s) == 0)
            return valuesTable[i].ccaValSymbol;

    return CCA_NS_VAL__INVALID;
}

int
prs_wap_process_get_enum_by_enum(int prsValue, const prs_cca_value_conv_t valuesTable[], int size)
{
    int i;

    for (i=0; i<size; i++)
        if (prsValue == valuesTable[i].src.i)
            return valuesTable[i].ccaValSymbol;

    return CCA_NS_VAL__INVALID;
}

int
prs_wap_process_fill_by_entry(prs_node_t *prsnode, S32 ccanode, const prs_cca_conversion_t *entry)
{
    /* returns 1:success, 0:mem full(failed) */
    int ccaValue;
    cca_status_enum status;
    prs_field_t *fieldPtr;

    if (!prs_is_used(prsnode, entry->prsSymbol))
        return 1;

    status = CCA_STATUS_OK;
    fieldPtr = &prsnode->fieldVec[entry->prsSymbol];
    while (1)
    {
      if (prs_is_multi(prsnode, entry->prsSymbol))
        fieldPtr = fieldPtr->next;

      if (!fieldPtr)
        break;

      /* STR */
      if (entry->type == PRS_CCA_CONV_STR)
        status = mmi_cca_doc_add_nodedata_str(ccanode, entry->ccaSymbol, (const S8*)(fieldPtr->data.s));
      /* ENUM from str */
      else if (entry->type == PRS_CCA_CONV_ENUM_FROM_STR)
      {
        ccaValue = prs_wap_process_get_enum(
                        fieldPtr->data.s,
                        entry->enumTable,
                        entry->enumTableSize);
        status = mmi_cca_doc_add_nodedata_int(ccanode, entry->ccaSymbol, ccaValue);
      }
      /* ENUM from enum */
      else if (entry->type == PRS_CCA_CONV_ENUM_FROM_ENUM)
      {
        ccaValue = prs_wap_process_get_enum_by_enum(
                        fieldPtr->data.i,
                        entry->enumTable,
                        entry->enumTableSize);
        status = mmi_cca_doc_add_nodedata_int(ccanode, entry->ccaSymbol, ccaValue);
      }
      /* INT */
      else if (entry->type == PRS_CCA_CONV_INT)
      {
        ccaValue = CCA_NS_VAL__EMPTY;
        if (entry->enumTable && entry->enumTableSize>0)
          ccaValue = prs_wap_process_get_enum_by_enum(
                            fieldPtr->data.i,
                            entry->enumTable,
                            entry->enumTableSize);
        if (ccaValue!=CCA_NS_VAL__EMPTY && ccaValue!=CCA_NS_VAL__INVALID)
          status = mmi_cca_doc_add_nodedata_int(ccanode, entry->ccaSymbol, ccaValue);
        else
          status = mmi_cca_doc_add_nodedata_int(ccanode, entry->ccaSymbol, fieldPtr->data.i);
      }

      if (!prs_is_multi(prsnode, entry->prsSymbol))
        break;
    }

    return (status!=CCA_STATUS_MEMFULL);
}

int
prs_wap_process_fill_by_param(prs_node_t *prsnode, S32 ccanode, const prs_cca_conversion_t table[], int prsSymbol)
{
    /* returns 1:success, 0:mem full(failed) */
    int i = -1;

    while (table[++i].prsSymbol != 0xFFFFFFFF)
    {
        if (table[i].prsSymbol != prsSymbol)
            continue;

        return prs_wap_process_fill_by_entry(prsnode, ccanode, (const prs_cca_conversion_t*)(table+i));
    }
    return 1;
}

int
prs_wap_process_fill_cca_node(prs_node_t *prsnode, S32 ccanode, const prs_cca_conversion_t table[])
{
    /* returns 1:success, 0:mem full(failed) */
    int i = 0;

    if (!table)
        return 1;

    while (table[i].prsSymbol != 0xFFFFFFFF)
    {
        if (prs_wap_process_fill_by_entry(prsnode, ccanode, (const prs_cca_conversion_t*)(table+i)) == 0)
            return 0;
        i++;
    }
    return 1;
}

int
prs_wap_process_conv_to_cca_node(prs_node_t *prsnode, S32 ccanode)
{
  /* returns 1:success, 0:mem full(failed) */
  //int ret = 1;
  S8 nodeid[2];
  S32 hNodePort, hNodePxAuthInfo;
  int fieldVecIndex;
  int ccaValue;

  switch (prsnode->element) {
    case PRS_WAP_NAPDEF:
    case PRS_WAP_PROXY:
    case PRS_WAP_APPLICATION:
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */
      if (mmi_cca_doc_add_nodedata_str(ccanode, CCA_NS_NODEID, prs_wap_process_get_next_nodeid(nodeid)) == CCA_STATUS_MEMFULL)
        return 0;
  };

  switch (prsnode->element) {
    case PRS_WAP_PROXY:
      if (prs_is_used(prsnode, PRS_WAP_PX_PORTNBR) || prs_is_used(prsnode, PRS_WAP_PX_SERVICE))
      {
        if ((hNodePort=mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, ccanode)) == 0)
          return 0;

        fieldVecIndex = PRS_WAP_PX_PORTNBR;
        if (prs_is_used(prsnode, fieldVecIndex))
          if (mmi_cca_doc_add_nodedata_str(hNodePort, CCA_NS_OMA_PORTNBR, prsnode->fieldVec[fieldVecIndex].data.s) == CCA_STATUS_MEMFULL)
            return 0;

        fieldVecIndex = PRS_WAP_PX_SERVICE;
        if (prs_is_used(prsnode, fieldVecIndex))
        {
          ccaValue = prs_wap_process_get_enum_by_enum(
                            prsnode->fieldVec[fieldVecIndex].data.i,
                            prs_cca_value_service,
                            sizeof(prs_cca_value_service)/sizeof(prs_cca_value_conv_t));
          if (mmi_cca_doc_add_nodedata_int(hNodePort, CCA_NS_OMA_SERVICE, ccaValue) == CCA_STATUS_MEMFULL)
            return 0;
        }
      }

      if (prs_is_used(prsnode, PRS_WAP_PX_PXAUTH_TYPE) || prs_is_used(prsnode, PRS_WAP_PX_PXAUTH_ID) || prs_is_used(prsnode, PRS_WAP_PX_PXAUTH_PW))
      {
        if ((hNodePxAuthInfo=mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, ccanode)) == 0)
          return 0;

        fieldVecIndex = PRS_WAP_PX_PXAUTH_TYPE;
        if (prs_is_used(prsnode, fieldVecIndex))
        {
          ccaValue = prs_wap_process_get_enum(
                            prsnode->fieldVec[fieldVecIndex].data.s,
                            prs_cca_value_authtype_str,
                            sizeof(prs_cca_value_authtype_str)/sizeof(prs_cca_value_conv_t));
          if (mmi_cca_doc_add_nodedata_int(hNodePxAuthInfo, CCA_NS_OMA_PXAUTH_TYPE, ccaValue) == CCA_STATUS_MEMFULL)
            return 0;
        }

        fieldVecIndex = PRS_WAP_PX_PXAUTH_ID;
        if (prs_is_used(prsnode, fieldVecIndex))
          if (mmi_cca_doc_add_nodedata_str(hNodePxAuthInfo, CCA_NS_OMA_PXAUTH_ID, prsnode->fieldVec[fieldVecIndex].data.s) == CCA_STATUS_MEMFULL)
            return 0;

        fieldVecIndex = PRS_WAP_PX_PXAUTH_PW;
        if (prs_is_used(prsnode, fieldVecIndex))
          if (mmi_cca_doc_add_nodedata_str(hNodePxAuthInfo, CCA_NS_OMA_PXAUTH_PW, prsnode->fieldVec[fieldVecIndex].data.s) == CCA_STATUS_MEMFULL)
            return 0;
      }
  }

  return prs_wap_process_fill_cca_node(prsnode, ccanode, prs_cca_conv_table_summary[prsnode->element]);
}

static char*
prs_wap_process_generate_virtual_proxy_id(const char *tonapid)
{
  S8 *newProxyID;
  S8 idPrefix[] = "@CCA@GEN@";
  int prefix_len, tonapid_len;

  prefix_len = strlen(idPrefix);
  tonapid_len = strlen(tonapid);

  newProxyID = (S8*)PRS_ALLOC(sizeof(S8)*(prefix_len+tonapid_len+1));
  memset(newProxyID, 0, sizeof(S8)*(prefix_len+tonapid_len+1));
  memcpy(newProxyID, idPrefix, prefix_len);
  memcpy(newProxyID+strlen(idPrefix), tonapid, tonapid_len);

  return newProxyID;
}

static S32
prs_wap_process_create_virtual_proxy(const char *tonapid, S32 ccaRoot, prs_node_t *prsAppNode)
{
  /* returns 1:created node, 0:mem full(failed) */
  extern int prs_wap_add_data (prs_node_t* node, int type, char** s);
  S32 vrProxy;
  S32 hNodePort;
  S8 nodeid[2];
  S8 *newProxyID;

  ASSERT(tonapid && ccaRoot);

  if ((vrProxy=mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, ccaRoot)) == 0)
    return 0;

  /* add CCA NODE_ID */
  if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_NODEID, prs_wap_process_get_next_nodeid(nodeid)) == CCA_STATUS_MEMFULL)
    return 0;

  /* add PROXY-ID */
  newProxyID = (S8*)prs_wap_process_generate_virtual_proxy_id(tonapid);
  if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_PROXY_ID, newProxyID) == CCA_STATUS_MEMFULL)
  {
    PRS_FREE(newProxyID);
    return 0;
  }

  /* add TO-PROXY to PRS node */
  prs_wap_add_data(prsAppNode, PRS_WAP_ATTRVAL_TO_PROXY, &newProxyID); 

  /* add NAME */
  if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_NAME, "Virtual Proxy") == CCA_STATUS_MEMFULL)
    return 0;

  /* add PXADDR */
  if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_PXADDR, "0.0.0.0") == CCA_STATUS_MEMFULL)
    return 0;

  /* add PXADDR-TYPE */
  if (mmi_cca_doc_add_nodedata_int(vrProxy, CCA_NS_OMA_PXADDRTYPE, CCA_NS_VAL_IPV4) == CCA_STATUS_MEMFULL)
    return 0;

  /* add TO-NAPID */
  if (mmi_cca_doc_add_nodedata_str(vrProxy, CCA_NS_OMA_TO_NAPID, (const S8*)tonapid) == CCA_STATUS_MEMFULL)
    return 0;

  /* add PORT */
  if ((hNodePort=mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, vrProxy)) == 0)
    return 0;
  if (mmi_cca_doc_add_nodedata_str(hNodePort, CCA_NS_OMA_PORTNBR, "0") == CCA_STATUS_MEMFULL)
    return 0;
  if (mmi_cca_doc_add_nodedata_int(hNodePort, CCA_NS_OMA_SERVICE, CCA_NS_VAL_OTA_HTTP_TO) == CCA_STATUS_MEMFULL)
    return 0;

  return vrProxy;
}

typedef enum {
  PRS_CCA_LAST_NAP = 0,
  PRS_CCA_LAST_APP,

/* OMA Extension */
  PRS_CCA_LAST_WLAN,
  PRS_CCA_LAST_EAP,

#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */

  PRS_CCA_LAST_NODE_COUNT
} prs_cca_last_node_enum;

S32 prs_cca_last_node[PRS_CCA_LAST_NODE_COUNT];

void prs_wap_cca_reset_last_nodes(void)
{
  memset(prs_cca_last_node, 0, PRS_CCA_LAST_NODE_COUNT*sizeof(S32));
}


static void
prs_wap_process_add_tonapid(char **lstToNapIDs, int size, const char *tonapid)
{
  int i;
  for (i=0; i<size; i++) {
    if (!(lstToNapIDs[i])) {
      lstToNapIDs[i] = msf_cmmn_strdup(MSF_MODID_PRS, tonapid);
      return;
    }
  }
}

static int
prs_wap_process_find_tonapid(char **lstToNapIDs, int size, const char *tonapid)
{
  int i;
  for (i=0; i<size && lstToNapIDs[i]; i++)
    if (strcmp(lstToNapIDs[i], tonapid) == 0)
      return 1;
  return 0;
}

static void
prs_wap_process_release_tonapid(char **lstToNapIDs, int size)
{
  int i;
  for (i=0; i<size && lstToNapIDs[i]; i++) {
    PRS_FREE(lstToNapIDs[i]);
    lstToNapIDs[i] = 0;
  }
}

static void
prs_wap_process_show_cca_memfull_dialog(void)
{
  BRAif_showDialog(MsfError, (MSF_UINT32)BRA_STR_OUT_OF_MEMORY);
}

int
prs_wap_process_construct_cca_doc(prs_node_list_t *list)
{
  /* return 0=continue with original provisioning path (ie, direct data to BRA)
   *        1=prov data has already routed to CCA
   */

#ifndef PRS_CCA_ENABLE_BROWSER_MMS_PROV
  return 0;
#else
  extern void wap_cca_register_new_doc(MSF_UINT16 spec_id, MSF_UINT16 sim_id, MSF_INT32 hConfig);
  extern int prs_wap_add_data (prs_node_t* node, int type, char** s);

  prs_node_t* node;
  S32 hConfig;
  S32 root;
  S32 crtHNode;
  int fieldVecIndex;
  prs_field_t *fieldPtr;
  int isBrowserMMS;
  S32 deprel;
  char *lstToNapIDs[20];

  memset(lstToNapIDs, 0, 20*sizeof(char*));

  /* construct root node */
  root = mmi_cca_doc_new_rootnode();
  if (!root) {
    prs_wap_process_show_cca_memfull_dialog();
    return 1;
  }

  /* init local variables */
  isBrowserMMS = 1;
  crtHNode = 0;
  prs_wap_cca_reset_last_nodes();

  /* construct CCA document (structural) */
  for (node=list->firstNode; node; node=node->next) {
    switch (node->element) {
      case PRS_WAP_NAPDEF:
        prs_wap_cca_reset_last_nodes();
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPDEF, root);
        prs_cca_last_node[PRS_CCA_LAST_NAP] = crtHNode;
        break;
      case PRS_WAP_PROXY:
        prs_wap_cca_reset_last_nodes();
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, root);
        break;
      case PRS_WAP_APPLICATION:
        prs_wap_cca_reset_last_nodes();
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, root);
        prs_cca_last_node[PRS_CCA_LAST_APP] = crtHNode;
        
        fieldVecIndex = PRS_WAP_APP_APPID;
        if (prs_is_used(node, fieldVecIndex))
        {
          if (strcmp(node->fieldVec[fieldVecIndex].data.s, "w4") != 0 &&
              strcmp(node->fieldVec[fieldVecIndex].data.s, "w2") != 0)
            isBrowserMMS = 0;
        }
        break;
      case PRS_WAP_BOOTSTRAP:
        prs_wap_cca_reset_last_nodes();
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_BOOTSTRAP, root);
        break;
      case PRS_WAP_ACCESS:
        prs_wap_cca_reset_last_nodes();
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_ACCESS, root);
        break;
      case PRS_WAP_VALIDITY:
        if (!prs_cca_last_node[PRS_CCA_LAST_NAP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_VALIDITY, prs_cca_last_node[PRS_CCA_LAST_NAP]);
        break;
      case PRS_WAP_NAPAUTHINFO:
        if (!prs_cca_last_node[PRS_CCA_LAST_NAP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPAUTHINFO, prs_cca_last_node[PRS_CCA_LAST_NAP]);
        break;
      case PRS_WAP_APPADDR:
        if (!prs_cca_last_node[PRS_CCA_LAST_APP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPADDR, prs_cca_last_node[PRS_CCA_LAST_APP]);
        break;
      case PRS_WAP_APPAUTH:
        if (!prs_cca_last_node[PRS_CCA_LAST_APP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPAUTH, prs_cca_last_node[PRS_CCA_LAST_APP]);
        break;
      case PRS_WAP_RESOURCE:
        if (!prs_cca_last_node[PRS_CCA_LAST_APP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_RESOURCE, prs_cca_last_node[PRS_CCA_LAST_APP]);
        break;
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
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
      case PRS_WAP_WLAN:
        if (!prs_cca_last_node[PRS_CCA_LAST_NAP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_WLAN, prs_cca_last_node[PRS_CCA_LAST_NAP]);
        prs_cca_last_node[PRS_CCA_LAST_WLAN] = crtHNode;
        prs_cca_last_node[PRS_CCA_LAST_NAP] = 0;
        break;
      case PRS_WAP_SEC_SSID:
        if (!prs_cca_last_node[PRS_CCA_LAST_WLAN])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_SEC_SSID, prs_cca_last_node[PRS_CCA_LAST_WLAN]);
        prs_cca_last_node[PRS_CCA_LAST_EAP] = 0;
        break;
      case PRS_WAP_EAP:
        if (!prs_cca_last_node[PRS_CCA_LAST_WLAN])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_EAP, prs_cca_last_node[PRS_CCA_LAST_WLAN]);
        prs_cca_last_node[PRS_CCA_LAST_EAP] = crtHNode;
        break;
      case PRS_WAP_CERT:
        if (!prs_cca_last_node[PRS_CCA_LAST_EAP])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_CERT, prs_cca_last_node[PRS_CCA_LAST_EAP]);
        break;
      case PRS_WAP_WEPKEY:
        if (!prs_cca_last_node[PRS_CCA_LAST_WLAN])
          continue;
        crtHNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_WEPKEY, prs_cca_last_node[PRS_CCA_LAST_WLAN]);
        prs_cca_last_node[PRS_CCA_LAST_EAP] = 0;
        break;
      default:
        continue;
    }

    if (!crtHNode) {
      mmi_cca_docroot_release(root);
      prs_wap_process_show_cca_memfull_dialog();
      return 1;
    }

    /* convert APPLICATION's TO-NAPID to virtual proxy */
    if (node->element == PRS_WAP_APPLICATION) {
      fieldVecIndex = PRS_WAP_APP_TO_NAPID;
      if (prs_is_used(node, fieldVecIndex)) {
        S32 vrProxy;
        char *newProxyID;

        fieldPtr = node->fieldVec[fieldVecIndex].next;
        while (fieldPtr) {
          if (!prs_wap_process_find_tonapid((char**)lstToNapIDs, 20, fieldPtr->data.s)) {
            prs_wap_process_add_tonapid((char**)lstToNapIDs, 20, fieldPtr->data.s);

            /* create virtual proxy + add new TO-PROXY to CCA APPLICATION node */
            if ((vrProxy=prs_wap_process_create_virtual_proxy(fieldPtr->data.s, root, node)) == 0) {
              mmi_cca_docroot_release(root);
              prs_wap_process_release_tonapid((char**)lstToNapIDs, 20);
              prs_wap_process_show_cca_memfull_dialog();
              return 1;
            }
          } else {
            /* generate virtual proxy id */
            newProxyID = (S8*)prs_wap_process_generate_virtual_proxy_id(fieldPtr->data.s);

            /* add TO-PROXY to PRS node */
            prs_wap_add_data(node, PRS_WAP_ATTRVAL_TO_PROXY, &newProxyID); 
          }

          fieldPtr = fieldPtr->next;
        }
      }
    }

    if (!prs_wap_process_conv_to_cca_node(node, crtHNode)) {
      mmi_cca_docroot_release(root);
      prs_wap_process_release_tonapid((char**)lstToNapIDs, 20);
      prs_wap_process_show_cca_memfull_dialog();
      return 1;
    }
  }
  prs_wap_process_release_tonapid((char**)lstToNapIDs, 20);

  /* validate and fix OMA document */
  mmi_cca_oma_fix_doc(root);

  /* generate dependency relationship node */
  deprel = mmi_cca_oma_generate_deprel_node(root);
  if (!deprel) {
    mmi_cca_docroot_release(root);
    prs_wap_process_show_cca_memfull_dialog();
    return 1;
  }
  mmi_cca_doc_attach_node_to_parent(deprel, root);

  /* sort document */
  mmi_cca_oma_sort_new_doc(root);

  /* construct CCA document */
  hConfig = mmi_cca_doc_new(root);
  if (!hConfig) {
    mmi_cca_docroot_release(root);
    prs_wap_process_show_cca_memfull_dialog();
    return 1;
  }

  //MMI_CCA_LOG_DOC(hConfig);

  /* create new HDIa API to send hConfig to CCA */
#ifdef __MMI_DUAL_SIM__
  wap_cca_register_new_doc(CCA_SPEC_OMA, prs_get_sim_id(list->network_account_id), (MSF_INT32)hConfig);
#else
  wap_cca_register_new_doc(CCA_SPEC_OMA, PRS_VAL_SIM_1, (MSF_INT32)hConfig);
#endif
  return 1;
#endif  /* PRS_CCA_ENABLE_BROWSER_MMS_PROV */
}

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
#endif  /* PRS_CONFIG_DMP_SUPPORT */

#endif  /* __MMI_CCA_SUPPORT__ */
#endif  /* WAP_SUPPORT */

/*
 * Process node list. Pre-processing step.
 */
int
prs_wap_process_list_pre (prs_node_list_t* list)
{
  prs_net_account_process (list,
                           PRS_WAP_NAPDEF,
                           PRS_WAP_NAPDEF_SIZE,
                           prs_wap_transform,
                           sizeof (prs_wap_transform) / sizeof (prs_net_account_transform_t));

#ifdef WAP_SUPPORT
#ifdef __MMI_CCA_SUPPORT__
  if (prs_wap_process_construct_cca_doc(list))
    return PRS_ERROR_ABORT;
#endif  /* __MMI_CCA_SUPPORT__ */
#endif  /* WAP_SUPPORT */

  /* MMS configuration is removed because following function commits MMS settings to registry directly!
     but we need to save it to user-selected profile first (to file), and only commit to registry if user activates that profile */
  /* prs_mmsc_process (list); */

  return PRS_STATUS_OK;
}



/*
 * Process node.
 */
int
prs_wap_process_node (prs_node_t* node)
{
  node = node;

  return PRS_STATUS_OK;
}



/*
 * Process node list. Post-processing step.
 */
int
prs_wap_process_list_post (prs_node_list_t* list)
{
  list = list;

  return PRS_STATUS_OK;
}

#endif


/**********************************************************************/
/*                          IOTA Provisioning                         */
/**********************************************************************/

#if defined PRS_CONFIG_IOTA || defined PRS_CONFIG_IOTA_WBXML

/************************************
 * Constants
 ************************************/

 
/************************************
 * Macro definitions
 ************************************/


/************************************
 * Type definitions
 ************************************/

 
/************************************
 * Function declaration
 ************************************/


/*************************************
 * Constants
 *************************************/


/*************************************
 * Functions
 *************************************/

#endif

