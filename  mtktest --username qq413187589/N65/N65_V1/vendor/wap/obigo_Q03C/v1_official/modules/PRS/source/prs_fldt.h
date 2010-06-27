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






#ifndef _prs_fldt_h
#define _prs_fldt_h

#ifdef PRS_LOG

extern const char* prs_br_element_names[];
extern const char* prs_wap_element_names[];


typedef struct prs_field_str_st {
  const int element;
  const int field;
  const char* str;
} prs_field_str_t;

#define PRS_FIELD_STR(e,f,s) { (e), (f), s}

const prs_field_str_t prs_br_field_str[] = {
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_BEARER, 
                 "PRS_BR_ADR_BEARER"),
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PROXY, 
                 "PRS_BR_ADR_PROXY"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PORT, 
                 "PRS_BR_ADR_PORT"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PROXY_TYPE, 
                 "PRS_BR_ADR_PROXY_TYPE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PROXY_AUTHNAME, 
                 "PRS_BR_ADR_PROXY_AUTHNAME"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PROXY_AUTHSECRET, 
                 "PRS_BR_ADR_PROXY_AUTHSECRET"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_SMS_SMSC_ADDRESS, 
                 "PRS_BR_ADR_SMS_SMSC_ADDRESS"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_USSD_SERVICE_CODE, 
                 "PRS_BR_ADR_USSD_SERVICE_CODE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_GPRS_ACCESSPOINTNAME,
                 "PRS_BR_ADR_GPRS_ACCESSPOINTNAME"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PPP_LOGINTYPE, 
                 "PRS_BR_ADR_PPP_LOGINTYPE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PROXY_LOGINTYPE, 
                 "PRS_BR_ADR_PROXY_LOGINTYPE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_CSD_DIALSTRING, 
                 "PRS_BR_ADR_CSD_DIALSTRING"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PPP_AUTHTYPE, 
                 "PRS_BR_ADR_PPP_AUTHTYPE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PPP_AUTHNAME, 
                 "PRS_BR_ADR_PPP_AUTHNAME"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_PPP_AUTHSECRET, 
                 "PRS_BR_ADR_PPP_AUTHSECRET"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_CSD_CALLTYPE, 
                 "PRS_BR_ADR_CSD_CALLTYPE"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_CSD_CALLSPEED, 
                 "PRS_BR_ADR_CSD_CALLSPEED"), 
  PRS_FIELD_STR (PRS_BR_ADDRESS, PRS_BR_ADR_ISP_NAME, 
                 "PRS_BR_ADR_ISP_NAME"), 
  PRS_FIELD_STR (PRS_BR_URL, PRS_BR_URL_URL, 
                 "PRS_BR_URL_URL"), 
  PRS_FIELD_STR (PRS_BR_MMSURL, PRS_BR_MMSURL_URL, 
                 "PRS_BR_MMSURL_URL"), 
  PRS_FIELD_STR (PRS_BR_NAME, PRS_BR_NM_NAME, 
                 "PRS_BR_NM_NAME"), 
  PRS_FIELD_STR (PRS_BR_BOOKMARK, PRS_BR_BKM_URL, 
                 "PRS_BR_BKM_URL"), 
  PRS_FIELD_STR (PRS_BR_BOOKMARK, PRS_BR_BKM_NAME, 
                 "PRS_BR_BKM_NAME"), 
  PRS_FIELD_STR (PRS_BR_ID, PRS_BR_ID_NAME, 
                 "PRS_BR_ID_NAME")              
};

const prs_field_str_t prs_wap_field_str[] = {
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PROXY_ID, 
                 "PRS_WAP_PX_PROXY_ID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PROXY_PW, 
                 "PRS_WAP_PX_PROXY_PW"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PPGAUTH_TYPE, 
                 "PRS_WAP_PX_PPGAUTH_TYPE"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PROXY_PROVIDER_ID, 
                 "PRS_WAP_PX_PROXY_PROVIDER_ID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_NAME, 
                 "PRS_WAP_PX_NAME"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_TRUST, 
                 "PRS_WAP_PX_TRUST"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_MASTER, 
                 "PRS_WAP_PX_MASTER"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_STARTPAGE, 
                 "PRS_WAP_PX_STARTPAGE"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_BASAUTH_ID, 
                 "PRS_WAP_PX_BASAUTH_ID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_BASAUTH_PW, 
                 "PRS_WAP_PX_BASAUTH_PW"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_WSP_VERSION, 
                 "PRS_WAP_PX_WSP_VERSION"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PUSHENABLED, 
                 "PRS_WAP_PX_PUSHENABLED"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PULLENABLED, 
                 "PRS_WAP_PX_PULLENABLED"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXAUTH_TYPE, 
                 "PRS_WAP_PX_PXAUTH_TYPE"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXAUTH_ID, 
                 "PRS_WAP_PX_PXAUTH_ID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXAUTH_PW, 
                 "PRS_WAP_PX_PXAUTH_PW"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PHYSICAL_PROXY_ID, 
                 "PRS_WAP_PX_PHYSICAL_PROXY_ID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXADDR, 
                 "PRS_WAP_PX_PXADDR"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXADDRTYPE, 
                 "PRS_WAP_PX_PXADDRTYPE"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PXADDR_FQDN, 
                 "PRS_WAP_PX_PXADDR_FQDN"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_TO_NAPID, 
                 "PRS_WAP_PX_TO_NAPID"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_PORTNBR, 
                 "PRS_WAP_PX_PORTNBR"),
  PRS_FIELD_STR (PRS_WAP_PROXY, PRS_WAP_PX_SERVICE, 
                 "PRS_WAP_PX_SERVICE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_NAPID, 
                 "PRS_WAP_NAP_NAPID"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_BEARER, 
                 "PRS_WAP_NAP_BEARER"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_NAME, 
                 "PRS_WAP_NAP_NAME"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_INTERNET, 
                 "PRS_WAP_NAP_INTERNET"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_NAP_ADDRESS, 
                 "PRS_WAP_NAP_NAP_ADDRESS"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_NAP_ADDRTYPE, 
                 "PRS_WAP_NAP_NAP_ADDRTYPE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_DNS_ADDR, 
                 "PRS_WAP_NAP_DNS_ADDR"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_CALLTYPE, 
                 "PRS_WAP_NAP_CALLTYPE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_LOCAL_ADDR, 
                 "PRS_WAP_NAP_LOCAL_ADDR"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_LOCAL_ADDRTYPE, 
                 "PRS_WAP_NAP_LOCAL_ADDRTYPE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_LINKSPEED, 
                 "PRS_WAP_NAP_LINKSPEED"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_DNLINKSPEED, 
                 "PRS_WAP_NAP_DNLINKSPEED"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_LINGER, 
                 "PRS_WAP_NAP_LINGER"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_DELIVERY_ERR_SDU, 
                 "PRS_WAP_NAP_DELIVERY_ERR_SDU"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_DELIVERY_ORDER, 
                 "PRS_WAP_NAP_DELIVERY_ORDER"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_TRAFFIC_CLASS, 
                 "PRS_WAP_NAP_TRAFFIC_CLASS"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_MAX_SDU_SIZE, 
                 "PRS_WAP_NAP_MAX_SDU_SIZE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_MAX_BITRATE_UPLINK, 
                 "PRS_WAP_NAP_MAX_BITRATE_UPLINK"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_MAX_BITRATE_DNLINK, 
                 "PRS_WAP_NAP_MAX_BITRATE_DNLINK"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_RESIDUAL_BER, 
                 "PRS_WAP_NAP_RESIDUAL_BER"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_SDU_ERROR_RATIO, 
                 "PRS_WAP_NAP_SDU_ERROR_RATIO"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_TRAFFIC_HAND_PRIO, 
                 "PRS_WAP_NAP_TRAFFIC_HAND_PRIO"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_TRANSFER_DELAY, 
                 "PRS_WAP_NAP_TRANSFER_DELAY"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_GUARANTEED_RATE_UP, 
                 "PRS_WAP_NAP_GUARANTEED_RATE_UP"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_GUARANTEED_RATE_DN, 
                 "PRS_WAP_NAP_GUARANTEED_RATE_DN"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_MAX_NUM_RETRY, 
                 "PRS_WAP_NAP_MAX_NUM_RETRY"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_FIRST_RETRY_TIMEOUT, 
                 "PRS_WAP_NAP_FIRST_RETRY_TIMEOUT"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_REREG_THRESHOLD, 
                 "PRS_WAP_NAP_REREG_THRESHOLD"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_T_BIT, 
                 "PRS_WAP_NAP_T_BIT"),
#ifdef MTK_TMP_PATCH /* CR30632 */
  PRS_FIELD_STR (PRS_WAP_NAPAUTHINFO, PRS_WAP_NAP_AUTHTYPE, 
                 "PRS_WAP_NAP_AUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_NAPAUTHINFO, PRS_WAP_NAP_AUTHNAME, 
                 "PRS_WAP_NAP_AUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_NAPAUTHINFO, PRS_WAP_NAP_AUTHSECRET, 
                 "PRS_WAP_NAP_AUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_NAPAUTHINFO, PRS_WAP_NAP_AUTH_ENTITY, 
                 "PRS_WAP_NAP_AUTH_ENTITY"),
  PRS_FIELD_STR (PRS_WAP_NAPAUTHINFO, PRS_WAP_NAP_SPI, 
                 "PRS_WAP_NAP_SPI"),
#else   /* MTK_TMP_PATCH */
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_AUTHTYPE, 
                 "PRS_WAP_NAP_AUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_AUTHNAME, 
                 "PRS_WAP_NAP_AUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_AUTHSECRET, 
                 "PRS_WAP_NAP_AUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_AUTH_ENTITY, 
                 "PRS_WAP_NAP_AUTH_ENTITY"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_SPI, 
                 "PRS_WAP_NAP_SPI"),
#endif  /* MTK_TMP_PATCH */
#ifdef MTK_TMP_PATCH /* CR30632 */
  PRS_FIELD_STR (PRS_WAP_VALIDITY, PRS_WAP_NAP_COUNTRY, 
                 "PRS_WAP_NAP_COUNTRY"),
  PRS_FIELD_STR (PRS_WAP_VALIDITY, PRS_WAP_NAP_NETWORK, 
                 "PRS_WAP_NAP_NETWORK"),
  PRS_FIELD_STR (PRS_WAP_VALIDITY, PRS_WAP_NAP_SID, 
                 "PRS_WAP_NAP_SID"),
  PRS_FIELD_STR (PRS_WAP_VALIDITY, PRS_WAP_NAP_SOC, 
                 "PRS_WAP_NAP_SOC"),
  PRS_FIELD_STR (PRS_WAP_VALIDITY, PRS_WAP_NAP_VALIDUNTIL, 
                 "PRS_WAP_NAP_VALIDUNTIL"),
#else   /* MTK_TMP_PATCH */
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_COUNTRY, 
                 "PRS_WAP_NAP_COUNTRY"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_NETWORK, 
                 "PRS_WAP_NAP_NETWORK"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_SID, 
                 "PRS_WAP_NAP_SID"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_SOC, 
                 "PRS_WAP_NAP_SOC"),
  PRS_FIELD_STR (PRS_WAP_NAPDEF, PRS_WAP_NAP_VALIDUNTIL, 
                 "PRS_WAP_NAP_VALIDUNTIL"),
#endif  /* MTK_TMP_PATCH */
  PRS_FIELD_STR (PRS_WAP_BOOTSTRAP, PRS_WAP_BTS_NAME, 
                 "PRS_WAP_BTS_NAME"),
  PRS_FIELD_STR (PRS_WAP_BOOTSTRAP, PRS_WAP_BTS_NETWORK, 
                 "PRS_WAP_BTS_NETWORK"),
  PRS_FIELD_STR (PRS_WAP_BOOTSTRAP, PRS_WAP_BTS_COUNTRY, 
                 "PRS_WAP_BTS_COUNTRY"),
  PRS_FIELD_STR (PRS_WAP_BOOTSTRAP, PRS_WAP_BTS_PROXY_ID, 
                 "PRS_WAP_BTS_PROXY_ID"),
  PRS_FIELD_STR (PRS_WAP_CLIENTIDENTITY, PRS_WAP_CID_CLIENT_ID, 
                 "PRS_WAP_CID_CLIENT_ID"),
  PRS_FIELD_STR (PRS_WAP_VENDORCONFIG, PRS_WAP_VDC_NAME, 
                 "PRS_WAP_VDC_NAME"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_APPID, 
                 "PRS_WAP_APP_APPID"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_PROVIDER_ID, 
                 "PRS_WAP_APP_PROVIDER_ID"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_NAME, 
                 "PRS_WAP_APP_NAME"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AACCEPT, 
                 "PRS_WAP_APP_AACCEPT"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_APROTOCOL, 
                 "PRS_WAP_APP_APROTOCOL"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_TO_PROXY, 
                 "PRS_WAP_APP_TO_PROXY"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_TO_NAPID, 
                 "PRS_WAP_APP_TO_NAPID"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_ADDR, 
                 "PRS_WAP_APP_ADDR"),
#ifdef MTK_TMP_PATCH /* CR30632 */
  PRS_FIELD_STR (PRS_WAP_APPADDR, PRS_WAP_APP_ADDR2, 
                 "PRS_WAP_APP_ADDR"),
  PRS_FIELD_STR (PRS_WAP_APPADDR, PRS_WAP_APP_ADDRTYPE, 
                 "PRS_WAP_APP_APPID"),
  PRS_FIELD_STR (PRS_WAP_APPADDR, PRS_WAP_APP_PORTNBR, 
                 "PRS_WAP_APP_PORTNBR"),
  PRS_FIELD_STR (PRS_WAP_APPADDR, PRS_WAP_APP_SERVICE, 
                 "PRS_WAP_APP_SERVICE"),
#else   /* MTK_TMP_PATCH  */
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_ADDRTYPE, 
                 "PRS_WAP_APP_APPID"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_PORTNBR, 
                 "PRS_WAP_APP_PORTNBR"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_SERVICE, 
                 "PRS_WAP_APP_SERVICE"),
#endif  /* MTK_TMP_PATCH  */
#ifdef MTK_TMP_PATCH /* CR30632 */
  PRS_FIELD_STR (PRS_WAP_APPAUTH, PRS_WAP_APP_AAUTHLEVEL, 
                 "PRS_WAP_APP_AAUTHLEVEL"),
  PRS_FIELD_STR (PRS_WAP_APPAUTH, PRS_WAP_APP_AAUTHTYPE, 
                 "PRS_WAP_APP_AAUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_APPAUTH, PRS_WAP_APP_AAUTHNAME, 
                 "PRS_WAP_APP_AAUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_APPAUTH, PRS_WAP_APP_AAUTHSECRET, 
                 "PRS_WAP_APP_AAUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_APPAUTH, PRS_WAP_APP_AAUTHDATA, 
                 "PRS_WAP_APP_AAUTHDATA"),
#else   /* MTK_TMP_PATCH  */
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AAUTHLEVEL, 
                 "PRS_WAP_APP_AAUTHLEVEL"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AAUTHTYPE, 
                 "PRS_WAP_APP_AAUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AAUTHNAME, 
                 "PRS_WAP_APP_AAUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AAUTHSECRET, 
                 "PRS_WAP_APP_AAUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_AAUTHDATA, 
                 "PRS_WAP_APP_AAUTHDATA"),
#endif  /* MTK_TMP_PATCH  */
#ifdef MTK_TMP_PATCH /* CR30632 */
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_URI, 
                 "PRS_WAP_APP_RES_URI"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_NAME, 
                 "PRS_WAP_APP_RES_NAME"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_AACCEPT, 
                 "PRS_WAP_APP_RES_AACCEPT"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_AAUTHTYPE, 
                 "PRS_WAP_APP_RES_AAUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_AAUTHNAME, 
                 "PRS_WAP_APP_RES_AAUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_AAUTHSECRET, 
                 "PRS_WAP_APP_RES_AAUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_AAUTHDATA, 
                 "PRS_WAP_APP_RES_AAUTHDATA"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_STARTPAGE, 
                 "PRS_WAP_APP_RES_STARTPAGE"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_CLIURI, 
                 "PRS_WAP_APP_RES_CLIURI"),
  PRS_FIELD_STR (PRS_WAP_RESOURCE, PRS_WAP_APP_RES_SYNCTYPE, 
                 "PRS_WAP_APP_RES_SYNCTYPE"),
#else   /* MTK_TMP_PATCH  */
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_URI, 
                 "PRS_WAP_APP_RES_URI"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_NAME, 
                 "PRS_WAP_APP_RES_NAME"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_AACCEPT, 
                 "PRS_WAP_APP_RES_AACCEPT"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_AAUTHTYPE, 
                 "PRS_WAP_APP_RES_AAUTHTYPE"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_AAUTHNAME, 
                 "PRS_WAP_APP_RES_AAUTHNAME"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_AAUTHSECRET, 
                 "PRS_WAP_APP_RES_AAUTHSECRET"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_AAUTHDATA, 
                 "PRS_WAP_APP_RES_AAUTHDATA"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RES_STARTPAGE, 
                 "PRS_WAP_APP_RES_STARTPAGE"),
#endif  /* MTK_TMP_PATCH  */
#ifdef MTK_TMP_PATCH /* CR27923 */
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_SERVICES, 
                 "PRS_WAP_APP_SERVICES"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_CIDPREFIX, 
                 "PRS_WAP_APP_CIDPREFIX"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_FROM, 
                 "PRS_WAP_APP_FROM"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_RT_ADDR, 
                 "PRS_WAP_APP_RT_ADDR"),
  PRS_FIELD_STR (PRS_WAP_APPLICATION, PRS_WAP_APP_INIT, 
                 "PRS_WAP_APP_INIT"),
#endif  /* MTK_TMP_PATCH */
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_RULE, 
                 "PRS_WAP_ACC_RULE"),
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_APPID, 
                 "PRS_WAP_ACC_APPID"),
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_PORTNBR, 
                 "PRS_WAP_ACC_PORTNBR"),
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_DOMAIN, 
                 "PRS_WAP_ACC_DOMAIN"),
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_TO_NAPID, 
                 "PRS_WAP_ACC_TO_NAPID"),
  PRS_FIELD_STR (PRS_WAP_ACCESS, PRS_WAP_ACC_TO_PROXY, 
                 "PRS_WAP_ACC_TO_PROXY")
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
  ,PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_PRI_SSID, 
                 "PRS_WAP_WLAN_PRI_SSID"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_PRI_U_SSID, 
                 "PRS_WAP_WLAN_PRI_U_SSID"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_PRI_H_SSID, 
                 "PRS_WAP_WLAN_PRI_H_SSID"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_NETMODE, 
                 "PRS_WAP_WLAN_NETMODE"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_SECMODE, 
                 "PRS_WAP_WLAN_SECMODE"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_WPA_PRES_KEY_ASC, 
                 "PRS_WAP_WLAN_WPA_PRES_KEY_ASC"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_WPA_PRES_KEY_HEX, 
                 "PRS_WAP_WLAN_WPA_PRES_KEY_HEX"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_WEPKEYIND, 
                 "PRS_WAP_WLAN_WEPKEYIND"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_WEPAUTHMODE, 
                 "PRS_WAP_WLAN_WEPAUTHMODE"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_WLANHAND, 
                 "PRS_WAP_WLAN_WLANHAND"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_EDIT_SET, 
                 "PRS_WAP_WLAN_EDIT_SET"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_VIEW_SET, 
                 "PRS_WAP_WLAN_VIEW_SET"),
  PRS_FIELD_STR (PRS_WAP_WLAN, PRS_WAP_WLAN_FORW_SET, 
                 "PRS_WAP_WLAN_FORW_SET"),

  PRS_FIELD_STR (PRS_WAP_SEC_SSID, PRS_WAP_SEC_SSID_S_SSID, 
                 "PRS_WAP_SEC_SSID_S_SSID"),
  PRS_FIELD_STR (PRS_WAP_SEC_SSID, PRS_WAP_SEC_SSID_S_U_SSID, 
                 "PRS_WAP_SEC_SSID_S_U_SSID"),

  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_EAPTYPE, 
                 "PRS_WAP_EAP_EAPTYPE"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_USERNAME, 
                 "PRS_WAP_EAP_USERNAME"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_PASSWORD, 
                 "PRS_WAP_EAP_PASSWORD"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_REALM, 
                 "PRS_WAP_EAP_REALM"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_USE_PSEUD, 
                 "PRS_WAP_EAP_USE_PSEUD"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_MAXAUTHS, 
                 "PRS_WAP_EAP_MAXAUTHS"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_ENCAPS, 
                 "PRS_WAP_EAP_ENCAPS"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_VER_SER_REALM, 
                 "PRS_WAP_EAP_VER_SER_REALM"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_CLIENT_AUTH, 
                 "PRS_WAP_EAP_CLIENT_AUTH"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_SES_VAL_TIME, 
                 "PRS_WAP_EAP_SES_VAL_TIME"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_CIP_SUIT, 
                 "PRS_WAP_EAP_CIP_SUIT"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_PEAP_V0, 
                 "PRS_WAP_EAP_PEAP_V0"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_PEAP_V1, 
                 "PRS_WAP_EAP_PEAP_V1"),
  PRS_FIELD_STR (PRS_WAP_EAP, PRS_WAP_EAP_PEAP_V2, 
                 "PRS_WAP_EAP_PEAP_V2"),

  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_ISS_NAME, 
                 "PRS_WAP_CERT_ISS_NAME"),
  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_SUB_NAME, 
                 "PRS_WAP_CERT_SUB_NAME"),
  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_CERT_TYPE, 
                 "PRS_WAP_CERT_CERT_TYPE"),
  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_SER_NUM, 
                 "PRS_WAP_CERT_SER_NUM"),
  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_SUB_KEY_ID, 
                 "PRS_WAP_CERT_SUB_KEY_ID"),
  PRS_FIELD_STR (PRS_WAP_CERT, PRS_WAP_CERT_THUMBPRINT, 
                 "PRS_WAP_CERT_THUMBPRINT"),

  PRS_FIELD_STR (PRS_WAP_WEPKEY, PRS_WAP_WEPKEY_LENGTH, 
                 "PRS_WAP_WEPKEY_LENGTH"),
  PRS_FIELD_STR (PRS_WAP_WEPKEY, PRS_WAP_WEPKEY_INDEX, 
                 "PRS_WAP_WEPKEY_INDEX"),
  PRS_FIELD_STR (PRS_WAP_WEPKEY, PRS_WAP_WEPKEY_DATA, 
                 "PRS_WAP_WEPKEY_DATA")
#endif  /* MTK_TMP_PATCH CR27923 */
};
#endif

#endif


