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
 * JProvCCAHandler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file interfaces between Jataayu and CCA
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _JPROVCCAHANDLER_C
#define _JPROVCCAHANDLER_C

#include "ddl.h"
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#include "JParserHandler.h"
#include "JProvCCAHandler.h"
#include "Conversions.h"

const prov_characteristic_param_tag_hdlr_struct prov_proxy_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_PROXY_ID, CCA_NS_OMA_PROXY_ID, PROV_CCA_CONV_STR, NULL /* mmi_prov_proxy_param_proxyid_tag_hdlr */ },
    {(U8 *) PROV_PROXY_PW, CCA_NS_OMA_PROXY_PW, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_PPGAUTH_TYPE, CCA_NS_OMA_PPGAUTH_TYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_authtype_tag_hdlr},
    {(U8 *) PROV_PROXY_PROVIDER_ID, CCA_NS_OMA_PROXY_PROVIDER_ID, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL /* mmi_prov_proxy_param_name_tag_hdlr */ },
    {(U8 *) PROV_TRUST, CCA_NS_OMA_TRUST, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_MASTER, CCA_NS_OMA_MASTER, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_STARTPAGE, CCA_NS_OMA_STARTPAGE, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_BASAUTH_ID, CCA_NS_OMA_BASAUTH_ID, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_BASAUTH_PW, CCA_NS_OMA_BASAUTH_PW, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_WSP_VERSION, CCA_NS_OMA_WSP_VERSION, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_PUSHENABLED, CCA_NS_OMA_PUSHENABLED, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_proxy_param_pushpullenabled_tag_hdlr},
    {(U8 *) PROV_PULLENABLED, CCA_NS_OMA_PULLENABLED, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_proxy_param_pushpullenabled_tag_hdlr},
    {(U8 *) PROV_PHYSICAL_PROXY_ID, CCA_NS_OMA_PHYSICAL_PROXY_ID, PROV_CCA_CONV_STR,
     NULL /* mmi_prov_proxy_param_phyproxyid_tag_hdlr */ },
    {(U8 *) PROV_PXADDR, CCA_NS_OMA_PXADDR, PROV_CCA_CONV_STR, NULL /* mmi_prov_proxy_param_pxaddr_tag_hdlr */ },
    {(U8 *) PROV_PXADDRTYPE, CCA_NS_OMA_PXADDRTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_addrtype_tag_hdlr},
    {(U8 *) PROV_PXADDR_FQDN, CCA_NS_OMA_PXADDR_FQDN, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_TO_NAPID, CCA_NS_OMA_TO_NAPID, PROV_CCA_CONV_STR, NULL /* mmi_prov_proxy_param_tonapid_tag_hdlr */ },

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};

const prov_characteristic_param_tag_hdlr_struct prov_port_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_PORTNBR, CCA_NS_OMA_PORTNBR, PROV_CCA_CONV_STR, NULL /* mmi_prov_port_param_port_tag_hdlr */ },
    {(U8 *) PROV_SERVICE, CCA_NS_OMA_SERVICE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_port_param_service_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_pxauthinfo_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_PXAUTH_TYPE, CCA_NS_OMA_PXAUTH_TYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_authtype_tag_hdlr},
    {(U8 *) PROV_PXAUTH_ID, CCA_NS_OMA_PXAUTH_ID, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_PXAUTH_PW, CCA_NS_OMA_PXAUTH_PW, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_application_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_APPID, CCA_NS_OMA_APPID, PROV_CCA_CONV_STR, NULL /* mmi_prov_application_param_appid_tag_hdlr */ },
    {(U8 *) PROV_PROVIDER_ID, CCA_NS_OMA_PROVIDER_ID, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AACCEPT, CCA_NS_OMA_AACCEPT, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_APROTOCOL, CCA_NS_OMA_APROTOCOL, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_TO_PROXY, CCA_NS_OMA_TO_PROXY, PROV_CCA_CONV_STR,
     NULL /* mmi_prov_application_param_toproxy_tag_hdlr */ },
    {(U8 *) PROV_ADDR, CCA_NS_OMA_ADDR, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_TO_NAPID, 0xFFFF, PROV_CCA_CONV_TOTAL, mmi_prov_application_param_tonapid_tag_hdlr},
    {(U8 *) PROV_FROM, CCA_NS_OMA_FROM, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_RT_ADDR, CCA_NS_OMA_RT_ADDR, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_CIDPREFIX, CCA_NS_OMA_CIDPREFIX, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_SERVICES, CCA_NS_OMA_SERVICES, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_INIT, CCA_NS_OMA_INIT, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_resource_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_URI, CCA_NS_OMA_URI, PROV_CCA_CONV_STR, NULL /* mmi_prov_pxauthinfo_param_uri_tag_hdlr */ },
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AACCEPT, CCA_NS_OMA_AACCEPT, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_authtype_tag_hdlr},
    {(U8 *) PROV_AAUTHNAME, CCA_NS_OMA_AAUTHNAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AAUTHSECRET, CCA_NS_OMA_AAUTHSECRET, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AAUTHDATA, CCA_NS_OMA_AAUTHDATA, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_STARTPAGE, CCA_NS_OMA_STARTPAGE, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_CLIURI, CCA_NS_OMA_CLIURI, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_SYNCTYPE, CCA_NS_OMA_SYNCTYPE, PROV_CCA_CONV_STR, NULL},
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
    {(U8 *) PROV_NE_URL, CCA_NS_OMA_URI, PROV_CCA_CONV_STR, NULL},
#endif 
    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_appaddr_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_ADDR, CCA_NS_OMA_ADDR, PROV_CCA_CONV_STR, NULL /* mmi_prov_appaddr_param_addr_tag_hdlr */ },
    {(U8 *) PROV_ADDRTYPE, CCA_NS_OMA_ADDRTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_addrtype_tag_hdlr},
    {(U8 *) PROV_PORTNBR, CCA_NS_OMA_PORTNBR, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_SERVICE, CCA_NS_OMA_SERVICE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_port_param_service_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_appauth_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_AAUTHLEVEL, CCA_NS_OMA_AAUTHLEVEL, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_appauth_param_authlevel_tag_hdlr},
    {(U8 *) PROV_AAUTHTYPE, CCA_NS_OMA_AAUTHTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_authtype_tag_hdlr},
    {(U8 *) PROV_AAUTHNAME, CCA_NS_OMA_AAUTHNAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AAUTHSECRET, CCA_NS_OMA_AAUTHSECRET, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AAUTHDATA, CCA_NS_OMA_AAUTHDATA, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_bootstrap_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NETWORK, CCA_NS_OMA_NETWORK, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_COUNTRY, CCA_NS_OMA_COUNTRY, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_PROXY_ID, CCA_NS_OMA_PROXY_ID, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_napdef_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_NAPID, CCA_NS_OMA_NAPID, PROV_CCA_CONV_STR, NULL /* mmi_prov_napdef_param_napid_tag_hdlr */ },
    {(U8 *) PROV_BEARER, CCA_NS_OMA_BEARER, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_napdef_param_bearer_tag_hdlr},
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_INTERNET, CCA_NS_OMA_INTERNET, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NAP_ADDRESS, CCA_NS_OMA_NAP_ADDRESS, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NAP_ADDRTYPE, CCA_NS_OMA_NAP_ADDRTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_addrtype_tag_hdlr},
    {(U8 *) PROV_DNS_ADDR, CCA_NS_OMA_DNS_ADDR, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_CALLTYPE, CCA_NS_OMA_CALLTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_napdef_param_calltype_tag_hdlr},
    {(U8 *) PROV_LOCAL_ADDR, CCA_NS_OMA_LOCAL_ADDR, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_LOCAL_ADDRTYPE, CCA_NS_OMA_LOCAL_ADDRTYPE, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_param_addrtype_tag_hdlr},
    {(U8 *) PROV_LINKSPEED, CCA_NS_OMA_LINKSPEED, PROV_CCA_CONV_INT, NULL},     /* take care for auto-bauding */
    {(U8 *) PROV_DNLINKSPEED, CCA_NS_OMA_DNLINKSPEED, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_LINGER, CCA_NS_OMA_LINGER, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_DELIVERY_ERR_SDU, CCA_NS_OMA_DELIVERY_ERR_SDU, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_DELIVERY_ORDER, CCA_NS_OMA_DELIVERY_ORDER, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_TRAFFIC_CLASS, CCA_NS_OMA_TRAFFIC_CLASS, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_MAX_SDU_SIZE, CCA_NS_OMA_MAX_SDU_SIZE, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_MAX_BITRATE_UPLINK, CCA_NS_OMA_MAX_BITRATE_UPLINK, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_MAX_BITRATE_DNLINK, CCA_NS_OMA_MAX_BITRATE_DNLINK, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_RESIDUAL_BER, CCA_NS_OMA_RESIDUAL_BER, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_SDU_ERROR_RATIO, CCA_NS_OMA_SDU_ERROR_RATIO, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_TRAFFIC_HANDL_PRIO, CCA_NS_OMA_TRAFFIC_HANDL_PRIO, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_TRANSFER_DELAY, CCA_NS_OMA_TRANSFER_DELAY, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_GUARANTEED_BITRATE_UPLINK, CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_GUARANTEED_BITRATE_DNLINK, CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_MAX_NUM_RETRY, CCA_NS_OMA_MAX_NUM_RETRY, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_FIRST_RETRY_TIMEOUT, CCA_NS_OMA_FIRST_RETRY_TIMEOUT, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_REREG_THRESHOLD, CCA_NS_OMA_REREG_THRESHOLD, PROV_CCA_CONV_INT, NULL},
    {(U8 *) PROV_T_BIT, CCA_NS_OMA_T_BIT, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_napauthinfo_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_AUTHTYPE, CCA_NS_OMA_AUTHTYPE, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_param_authtype_tag_hdlr},
    {(U8 *) PROV_AUTHNAME, CCA_NS_OMA_AUTHNAME, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AUTHSECRET, CCA_NS_OMA_AUTHSECRET, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_AUTH_ENTITY, CCA_NS_OMA_AUTH_ENTITY, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_napauthinfo_param_authentity_tag_hdlr},
    {(U8 *) PROV_SPI, CCA_NS_OMA_SPI, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_validity_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_COUNTRY, CCA_NS_OMA_COUNTRY, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_NETWORK, CCA_NS_OMA_NETWORK, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_SID, CCA_NS_OMA_SID, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_SOC, CCA_NS_OMA_SOC, PROV_CCA_CONV_STR, NULL},
    {(U8 *) PROV_VALIDUNTIL, CCA_NS_OMA_VALIDUNTIL, PROV_CCA_CONV_STR, NULL},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_access_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};
const prov_characteristic_param_tag_hdlr_struct prov_root_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};

#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

const prov_characteristic_param_tag_hdlr_struct prov_ne_address_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_BEARER, CCA_NS_OMA_BEARER, PROV_CCA_CONV_ENUM_FROM_STR, mmi_prov_napdef_param_bearer_tag_hdlr},
    {(U8 *) PROV_NE_ISP_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_STR, NULL},

    {(U8 *) PROV_NE_SMS_SMSC_ADDRESS, CCA_NS_OMA_NAP_ADDRESS, PROV_CCA_CONV_STR,
     mmi_prov_ne_address_param_sms_smsc_tag_hdlr},
    {(U8 *) PROV_NE_USSD_SERVICE_CODE, CCA_NS_OMA_NAP_ADDRESS, PROV_CCA_CONV_STR,
     mmi_prov_ne_address_param_ussd_sevice_tag_hdlr},
    {(U8 *) PROV_NE_GPRS_ACCESSPOINTNAME, CCA_NS_OMA_NAP_ADDRESS, PROV_CCA_CONV_STR,
     mmi_prov_ne_address_param_gprs_accesspoint_tag_hdlr},
    {(U8 *) PROV_NE_CSD_DIALSTRING, CCA_NS_OMA_NAP_ADDRESS, PROV_CCA_CONV_STR,
     mmi_prov_ne_address_param_sms_smsc_tag_hdlr},

    {(U8 *) PROV_NE_CSD_CALLTYPE, CCA_NS_OMA_CALLTYPE, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_napdef_param_calltype_tag_hdlr},

    {(U8 *) PROV_NE_CSD_CALLSPEED, CCA_NS_OMA_LINKSPEED, PROV_CCA_CONV_INT, NULL},      /* take care for auto-bauding */

    {(U8 *) PROV_NE_PPP_AUTHTYPE, CCA_NS_OMA_AUTHTYPE, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_ppp_authtype_tag_hdlr},
    {(U8 *) PROV_NE_PPP_AUTHNAME, CCA_NS_OMA_AUTHNAME, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_ppp_authname_tag_hdlr},
    {(U8 *) PROV_NE_PPP_AUTHSECRET, CCA_NS_OMA_AUTHSECRET, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_ppp_authsecret_tag_hdlr},

    {(U8 *) PROV_NE_PPP_LOGINTYPE, CCA_NS_OMA_LOGINTYPE, PROV_CCA_CONV_ENUM_FROM_STR,
     mmi_prov_ne_address_param_ppp_logintype_tag_hdlr},
    {(U8 *) PROV_NE_PROXY_LOGINTYPE, CCA_NS_OMA_LOGINTYPE, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_proxy_logintype_tag_hdlr},

    {(U8 *) PROV_NE_PROXY, CCA_NS_OMA_PXADDR, PROV_CCA_CONV_TOTAL, mmi_prov_ne_address_param_proxy_tag_hdlr},
    {(U8 *) PROV_NE_PROXY_TYPE, CCA_NS_OMA_PXADDRTYPE, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_proxy_type_tag_hdlr},

    {(U8 *) PROV_NE_PROXY_AUTHNAME, CCA_NS_OMA_PXAUTH_ID, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_proxy_authname_tag_hdlr},
    {(U8 *) PROV_NE_PROXY_AUTHSECRET, CCA_NS_OMA_PXAUTH_PW, PROV_CCA_CONV_TOTAL,
     mmi_prov_ne_address_param_proxy_authsecret_tag_hdlr},

    {(U8 *) PROV_NE_PORT, 0xFFFF, PROV_CCA_CONV_TOTAL, mmi_prov_ne_address_param_port_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};

const prov_characteristic_param_tag_hdlr_struct prov_ne_name_param_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_NAME, CCA_NS_OMA_NAME, PROV_CCA_CONV_TOTAL, mmi_prov_ne_name_param_name_tag_hdlr},

    {(U8 *) NULL, 0xFFFF, PROV_CCA_CONV_TOTAL, NULL}

};

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */ /* #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */

const prov_characteristic_tag_hdlr_struct prov_oma_characteristic_tag_hdlr_mapping_table[] = 
{
    {(U8 *) PROV_PXPHYSICAL, CCA_NS_OMA_PROXY, PROV_PXLOGICAL_NODE_VAL, PROV_PXPHYSICAL_NODE_VAL,
     mmi_prov_characteristic_pxphysical_tag_hdlr,
     prov_proxy_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_PXLOGICAL, CCA_NS_OMA_PROXY, PROV_ROOT_NODE_VAL, PROV_PXLOGICAL_NODE_VAL,
     mmi_prov_characteristic_pxlogical_tag_hdlr,
     prov_proxy_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_PORT, CCA_NS_OMA_PORT, PROV_PXLOGICAL_NODE_VAL | PROV_PXPHYSICAL_NODE_VAL | PROV_APPADDR_NODE_VAL,
     PROV_PORT_NODE_VAL, mmi_prov_characteristic_port_tag_hdlr,
     prov_port_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_PXAUTHINFO, CCA_NS_OMA_PXAUTHINFO, PROV_PXLOGICAL_NODE_VAL, PROV_PXAUTHINFO_NODE_VAL,
     mmi_prov_characteristic_pxauthinfo_tag_hdlr,
     prov_pxauthinfo_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_APPLICATION, CCA_NS_OMA_APPLICATION, PROV_ROOT_NODE_VAL, PROV_APPLICATION_NODE_VAL,
     mmi_prov_characteristic_application_tag_hdlr,
     prov_application_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_RESOURCE, CCA_NS_OMA_RESOURCE, PROV_APPLICATION_NODE_VAL, PROV_RESOURCE_NODE_VAL,
     mmi_prov_characteristic_resource_tag_hdlr,
     prov_resource_param_tag_hdlr_mapping_table},

    {(U8 *) "APPADDR", CCA_NS_OMA_APPADDR, PROV_APPLICATION_NODE_VAL, PROV_APPADDR_NODE_VAL,
     mmi_prov_characteristic_appaddr_tag_hdlr,
     prov_appaddr_param_tag_hdlr_mapping_table},

    {(U8 *) "APPAUTH", CCA_NS_OMA_APPAUTH, PROV_APPLICATION_NODE_VAL, PROV_APPAUTH_NODE_VAL,
     mmi_prov_characteristic_appauth_tag_hdlr,
     prov_appauth_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_BOOTSTRAP, CCA_NS_OMA_BOOTSTRAP, PROV_ROOT_NODE_VAL, PROV_BOOTSTRAP_NODE_VAL,
     mmi_prov_characteristic_bootstrap_tag_hdlr,
     prov_bootstrap_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_NAPDEF, CCA_NS_OMA_NAPDEF, PROV_ROOT_NODE_VAL, PROV_NAPDEF_NODE_VAL,
     mmi_prov_characteristic_napdef_tag_hdlr,
     prov_napdef_param_tag_hdlr_mapping_table},

    {(U8 *) PROV_NAPAUTHINFO, CCA_NS_OMA_NAPAUTHINFO, PROV_NAPDEF_NODE_VAL, PROV_NAPAUTHINFO_NODE_VAL,
     mmi_prov_characteristic_napauthinfo_tag_hdlr,
     prov_napauthinfo_param_tag_hdlr_mapping_table},

    {(U8 *) "VALIDITY", CCA_NS_OMA_VALIDITY, PROV_NAPDEF_NODE_VAL, PROV_VALIDITY_NODE_VAL,
     mmi_prov_characteristic_validity_tag_hdlr,
     prov_validity_param_tag_hdlr_mapping_table},

    {(U8 *) "ACCESS", CCA_NS_OMA_ACCESS, PROV_ROOT_NODE_VAL, PROV_ACCESS_NODE_VAL,
     mmi_prov_characteristic_access_tag_hdlr,
     prov_access_param_tag_hdlr_mapping_table},

    {NULL, 0xFFFF}
};

const prov_characteristic_tag_hdlr_struct prov_non_oma_characteristic_tag_hdlr_mapping_table[] = 
{
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

    {(U8 *) PROV_NE_ADDRESS, CCA_NS_OMA_NAPDEF, PROV_ROOT_NODE_VAL, PROV_NE_ADRESS_NODE_VAL,
     mmi_prov_characteristic_ne_address_tag_hdlr,
     prov_ne_address_param_tag_hdlr_mapping_table},

    /* {(U8 *)PROV_NE_URL, CCA_NS_OMA_RESOURCE, PROV_ROOT_NODE_VAL, PROV_NE_URL_NODE_VAL,
       mmi_prov_characteristic_ne_url_tag_hdlr,
       NULL}, */

    {(U8 *) PROV_NE_MMSURL, CCA_NS_OMA_APPLICATION, PROV_ROOT_NODE_VAL, PROV_NE_MMSURL_NODE_VAL,
     mmi_prov_characteristic_ne_mmsurl_tag_hdlr,
     NULL},

    {(U8 *) PROV_NE_BOOKMARK, CCA_NS_OMA_RESOURCE, PROV_ROOT_NODE_VAL, PROV_NE_BOOKMARK_NODE_VAL,
     mmi_prov_characteristic_ne_bookmark_tag_hdlr,
     prov_resource_param_tag_hdlr_mapping_table},

    /* {(U8 *)PROV_NE_ID, CCA_NS_OMA_CLIENTIDENTITY, PROV_ROOT_NODE_VAL, PROV_NE_ID_NODE_VAL,
       mmi_prov_characteristic_ne_id_tag_hdlr,
       prov_ne_id_param_tag_hdlr_mapping_table}, */

    /* dummy resource node is created for handling its param values and then deleted the node */
    {(U8 *) PROV_NAME, CCA_NS_OMA_RESOURCE, PROV_ROOT_NODE_VAL, PROV_NE_NAME_NODE_VAL,
     mmi_prov_characteristic_ne_name_tag_hdlr,
     prov_ne_name_param_tag_hdlr_mapping_table},

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

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
 #endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */ /* #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */

    {NULL, 0xFFFF}
};

const prov_convert_str_to_enum_struct prov_param_authtype_str_enum_table[] = 
{
    {(U8 *) "HTTP-BASIC", CCA_NS_VAL_HTTP_BASIC},
    {(U8 *) "HTTP-DIGEST", CCA_NS_VAL_HTTP_DIGEST},
    {(U8 *) "BASIC", CCA_NS_VAL_BASIC},
    {(U8 *) "DIGEST", CCA_NS_VAL_DIGEST},
    {(U8 *) "WTLS-SS", CCA_NS_VAL_WTLS_SS},
    {(U8 *) "CRAM-MD5", CCA_NS_VAL_CRAM_MD5},
    {(U8 *) "DIGEST-MD5", CCA_NS_VAL_DIGEST_MD5},
    {(U8 *) "LOGIN", CCA_NS_VAL_LOGIN},
    {(U8 *) "PLAIN", CCA_NS_VAL_PLAIN},
    {(U8 *) "APOP", CCA_NS_VAL_APOP},
    {(U8 *) "GSSAPI", CCA_NS_VAL_GSSAPI},
    {(U8 *) "KERBEROS_V4", CCA_NS_VAL_KERBEROS_V4},
    {(U8 *) "SKEY", CCA_NS_VAL_SKEY},
    {(U8 *) "PAP", CCA_NS_VAL_PAP},
    {(U8 *) "CHAP", CCA_NS_VAL_CHAP},
    {(U8 *) "MS_CHAP", CCA_NS_VAL_CHAP},    /* to be discuss */
    {(U8 *) "MD5", CCA_NS_VAL_MD5},

    {(U8 *) "X509", CCA_NS_VAL_X509},
    {(U8 *) "SECURID", CCA_NS_VAL_SECURID},
    {(U8 *) "SAFEWORD", CCA_NS_VAL_SAFEWORD},
    {(U8 *) "DIGIPASS", CCA_NS_VAL_DIGIPASS},
    {(U8 *) "HMAC", CCA_NS_VAL_HMAC},

    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_param_authlevel_str_enum_table[] = 
{
    {(U8 *) "APPSRV", CCA_NS_VAL_APPSRV},
    {(U8 *) "OBEX", CCA_NS_VAL_OBEX},
    {(U8 *) "CLIENT", CCA_NS_VAL_CLIENT},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_param_authentity_str_enum_table[] = 
{
    {(U8 *) "AAA", CCA_NS_VAL_AAA},
    {(U8 *) "HA", CCA_NS_VAL_HA},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_param_pushpullenabled_str_enum_table[] = 
{
    {(U8 *) "0", CCA_NS_VAL_DISABLED},
    {(U8 *) "1", CCA_NS_VAL_ENABLED},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_param_addrtype_str_enum_table[] = 
{
    {(U8 *) PROV_IPV4, CCA_NS_VAL_IPV4},
    {(U8 *) PROV_IPV6, CCA_NS_VAL_IPV6},
    {(U8 *) PROV_E164, CCA_NS_VAL_E164},
    {(U8 *) PROV_ALPHA, CCA_NS_VAL_ALPHA},
    {(U8 *) PROV_APN, CCA_NS_VAL_APN},
    {(U8 *) PROV_SCODE, CCA_NS_VAL_SCODE},
    {(U8 *) PROV_TETRA_ITSI, CCA_NS_VAL_TETRA_ITSI},
    {(U8 *) PROV_MAN, CCA_NS_VAL_MAN},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_port_param_service_str_enum_table[] = 
{
    {(U8 *) PROV_CL_WSP, CCA_NS_VAL_CL_WSP},
    {(U8 *) PROV_CO_WSP, CCA_NS_VAL_CO_WSP},
    {(U8 *) PROV_CL_SEC_WSP, CCA_NS_VAL_CL_SEC_WSP},
    {(U8 *) PROV_CO_SEC_WSP, CCA_NS_VAL_CO_SEC_WSP},
    {(U8 *) PROV_CO_SEC_WTA, CCA_NS_VAL_CO_SEC_WTA},
    {(U8 *) PROV_CL_SEC_WTA, CCA_NS_VAL_CL_SEC_WTA},
    {(U8 *) PROV_OTA_HTTP_TO, CCA_NS_VAL_OTA_HTTP_TO},
    {(U8 *) PROV_OTA_HTTP_TLS_TO, CCA_NS_VAL_OTA_HTTP_TLS_TO},
    {(U8 *) PROV_OTA_HTTP_PO, CCA_NS_VAL_OTA_HTTP_PO},
    {(U8 *) PROV_OTA_HTTP_TLS_PO, CCA_NS_VAL_OTA_HTTP_TLS_PO},
    {(U8 *) PROV_STARTTLS, CCA_NS_VAL_STARTTLS},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_napdef_param_bearer_str_enum_table[] = 
{
    {(U8 *) PROV_GSM_CSD, CCA_NS_VAL_GSM_CSD},
    {(U8 *) PROV_GSM_GPRS, CCA_NS_VAL_GSM_GPRS},
    {(U8 *) PROV_GSM_USSD, CCA_NS_VAL_GSM_USSD},
    {(U8 *) PROV_GSM_SMS, CCA_NS_VAL_GSM_SMS},
    {(U8 *) PROV_CDMA_SMS, CCA_NS_VAL_CDMA_SMS},
    {(U8 *) PROV_CDMA_CSD, CCA_NS_VAL_CDMA_CSD},
    {(U8 *) PROV_CDMA_PACKET, CCA_NS_VAL_CDMA_PACKET},
    {(U8 *) PROV_ANSI_136_GUTS, CCA_NS_VAL_ANSI_136_GUTS},
    {(U8 *) PROV_ANSI_136_CSD, CCA_NS_VAL_ANSI_136_CSD},
    {(U8 *) PROV_ANSI_136_GPRS, CCA_NS_VAL_ANSI_136_GPRS},
    {(U8 *) PROV_ANSI_136_GHOST, CCA_NS_VAL_ANSI_136_GHOST},
    {(U8 *) PROV_AMPS_CDPD, CCA_NS_VAL_AMPS_CDPD},
    {(U8 *) PROV_PDC_CSD, CCA_NS_VAL_PDC_CSD},
    {(U8 *) PROV_PDC_PACKET, CCA_NS_VAL_PDC_PACKET},
    {(U8 *) PROV_IDEN_SMS, CCA_NS_VAL_IDEN_SMS},
    {(U8 *) PROV_IDEN_CSD, CCA_NS_VAL_IDEN_CSD},
    {(U8 *) PROV_IDEN_PACKET, CCA_NS_VAL_IDEN_PACKET},
    {(U8 *) PROV_FLEX_REFLEX, CCA_NS_VAL_FLEX_REFLEX},
    {(U8 *) PROV_PHS_SMS, CCA_NS_VAL_PHS_SMS},
    {(U8 *) PROV_PHS_CSD, CCA_NS_VAL_PHS_CSD},
    {(U8 *) PROV_TETRA_SDS, CCA_NS_VAL_TETRA_SDS},
    {(U8 *) PROV_TETRA_PACKET, CCA_NS_VAL_TETRA_PACKET},
    {(U8 *) PROV_MOBITEX_MPAK, CCA_NS_VAL_MOBITEX_MPAK},
    {(U8 *) PROV_CDMA2000_1X_SIMPLE_IP, CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP},
    {(U8 *) PROV_CDMA2000_1X_MOBILE_IP, CCA_NS_VAL_CDMA2000_1X_MOBILE_IP},
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

    {(U8 *) PROV_NE_GSM_CSD, CCA_NS_VAL_GSM_CSD},
    {(U8 *) PROV_NE_GPRS, CCA_NS_VAL_GSM_GPRS},
    {(U8 *) PROV_NE_GSM_USSD, CCA_NS_VAL_GSM_USSD},
    {(U8 *) PROV_NE_GSM_SMS, CCA_NS_VAL_GSM_SMS},
    {(U8 *) PROV_NE_IS_136_CSD, CCA_NS_VAL_ANSI_136_CSD},

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_napdef_param_calltype_str_enum_table[] = 
{
    {(U8 *) PROV_ANALOG_MODEM, CCA_NS_VAL_ANALOG_MODEM},
    {(U8 *) PROV_V120, CCA_NS_VAL_V120},
    {(U8 *) PROV_V110, CCA_NS_VAL_V110},
    {(U8 *) PROV_X31, CCA_NS_VAL_X31},
    {(U8 *) PROV_BIT_TRANSPARENT, CCA_NS_VAL_BIT_TRANSPARENT},
    {(U8 *) PROV_DIRECT_ASYNC_DATA_SERVICE, CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE},
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

    {(U8 *) PROV_NE_ANALOGUE, CCA_NS_VAL_ANALOG_MODEM},
    {(U8 *) PROV_NE_ISDN, CCA_NS_VAL_V120},

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

    {(U8 *) NULL, 0xffff},

};

#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

const prov_convert_str_to_enum_struct prov_param_ne_addrtype_str_enum_table[] = 
{
    {(U8 *) PROV_NE_IPV4, CCA_NS_VAL_IPV4},
    {(U8 *) PROV_NE_MSISDN_NO, CCA_NS_VAL_E164},
    {(U8 *) NULL, 0xffff},

};

const prov_convert_str_to_enum_struct prov_param_ne_logintype_str_enum_table[] = 
{
    {(U8 *) "AUTOMATIC", CCA_NS_VAL_AUTOMATIC},
    {(U8 *) "MANUAL", CCA_NS_VAL_MANUAL},
    {(U8 *) NULL, 0xffff},

};

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

prov_cca_handler_context_st g_prov_cca_handler_ctx;
static prov_curr_ccanode_characteristic_tag_hdlr_st g_cur_cca_node_char_taghdlr[MAX_NODE_LEVEL];

static prov_cca_queue_data_struct *prov_data_queue[PROV_CCA_MAX_NBR_DOCUMENTS];
static S8 g_prov_data_queue_current_item = 0;
static S8 g_prov_data_queue_last_item = 0;
static S8 g_prov_data_queue_size = 0;

#ifndef __MMI_JATAAYU_WBXML_SUPPORT__
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_check_queue_size
 * DESCRIPTION
 *  This Add's the new settings received into the queue to be processed later on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_prov_cca_check_queue_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_data_queue_size == PROV_CCA_MAX_NBR_DOCUMENTS)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_add_to_queue
 * DESCRIPTION
 *  This Add's the new settings received into the queue to be processed later on.
 * PARAMETERS
 *  prov_buffer_p       [IN]        Provisioing data buffer
 *  prov_length         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_add_to_queue(S8 *prov_buffer_p, U32 prov_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_data_queue_last_item >= PROV_CCA_MAX_NBR_DOCUMENTS)
    {
        g_prov_data_queue_last_item = 0;
    }

    prov_data_queue[g_prov_data_queue_last_item] =
        (prov_cca_queue_data_struct*) jdd_MemAlloc(sizeof(prov_cca_queue_data_struct), 1);
    ASSERT(prov_data_queue[g_prov_data_queue_last_item]);
    prov_data_queue[g_prov_data_queue_last_item]->pbuffer = prov_buffer_p;

    prov_data_queue[g_prov_data_queue_last_item]->plength = prov_length;

    g_prov_data_queue_last_item++;
    g_prov_data_queue_size++;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_delete_queue_entry
 * DESCRIPTION
 *  Deletes the current queue entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_delete_queue_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prov_data_queue[g_prov_data_queue_current_item]->pbuffer)
    {
        jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]->pbuffer);
        prov_data_queue[g_prov_data_queue_current_item]->pbuffer = NULL;
    }
    if (prov_data_queue[g_prov_data_queue_current_item])
    {
        jdd_MemFree(prov_data_queue[g_prov_data_queue_current_item]);
        prov_data_queue[g_prov_data_queue_current_item] = NULL;
    }

    ++g_prov_data_queue_current_item;
    --g_prov_data_queue_size;
    if (g_prov_data_queue_current_item >= PROV_CCA_MAX_NBR_DOCUMENTS)
    {
        g_prov_data_queue_current_item = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_memory
 * DESCRIPTION
 *  This function freed the allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_prov_cca_handler_ctx.sibling_node_list_p)
    {

        temp_node = (prov_cca_node_hdlr_st*) g_prov_cca_handler_ctx.sibling_node_list_p;
        g_prov_cca_handler_ctx.sibling_node_list_p =
            (prov_cca_node_hdlr_st*) g_prov_cca_handler_ctx.sibling_node_list_p->node_hdlr_next;
        jdd_MemFree(temp_node);
        temp_node = NULL;
    }
    mmi_prov_free_application_param_tonapid_value();
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__

    while (g_prov_cca_handler_ctx.cca_proxy_node_list_p)
    {

        temp_node = (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_proxy_node_list_p;
        g_prov_cca_handler_ctx.cca_proxy_node_list_p =
            (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_proxy_node_list_p->node_next;
        jdd_MemFree(temp_node);
        temp_node = NULL;
    }
    while (g_prov_cca_handler_ctx.cca_resorce_node_list_p)
    {

        temp_node = (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_resorce_node_list_p;
        g_prov_cca_handler_ctx.cca_resorce_node_list_p =
            (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_resorce_node_list_p->node_next;
        jdd_MemFree(temp_node);
        temp_node = NULL;
    }
    while (g_prov_cca_handler_ctx.cca_brw_app_node_list_p)
    {

        temp_node = (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_brw_app_node_list_p;
        g_prov_cca_handler_ctx.cca_brw_app_node_list_p =
            (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_brw_app_node_list_p->node_next;
        jdd_MemFree(temp_node);
        temp_node = NULL;
    }
    while (g_prov_cca_handler_ctx.cca_mms_app_node_list_p)
    {

        temp_node = (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_mms_app_node_list_p;
        g_prov_cca_handler_ctx.cca_mms_app_node_list_p =
            (prov_cca_node_list_struct*) g_prov_cca_handler_ctx.cca_mms_app_node_list_p->node_next;
        jdd_MemFree(temp_node);
        temp_node = NULL;
    }
    if (g_prov_cca_handler_ctx.setting_name)
    {
        jdd_MemFree(g_prov_cca_handler_ctx.setting_name);
        g_prov_cca_handler_ctx.setting_name = NULL;
    }
    if (g_prov_cca_handler_ctx.app_url)
    {
        jdd_MemFree(g_prov_cca_handler_ctx.app_url);
        g_prov_cca_handler_ctx.app_url = NULL;
    }

#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_ui_auth_req
 * DESCRIPTION
 *  write MSG_ID_MMI_CCA_SOURCE_UI_AUTH_IND event to mmi task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_ui_auth_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_ui_auth_res_hdlr
 * DESCRIPTION
 *  handle MSG_ID_MMI_CCA_SOURCE_UI_AUTH_RSP events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_ui_auth_res_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_new_setting_ind_req
 * DESCRIPTION
 *  write MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND event to mmi task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_new_setting_ind_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_new_setting_ind_struct *data;
    MYQUEUE Message;
    static S32 transid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_cca_new_setting_ind_req");
    data =
        (mmi_cca_source_ui_new_setting_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_ui_new_setting_ind_struct));
    ASSERT(data);
    data->spec_id = CCA_SPEC_OMA;
    transid++;
    if (transid > MAX_NODEID_ITTR)
    {
        transid = 1;
    }
    data->trans_id = transid;

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_new_setting_res_hdlr
 * DESCRIPTION
 *  handle MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_new_setting_res_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE i_ret = PROV_CCA_OK;
    mmi_cca_source_ui_new_setting_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg);
    PRINT_INFORMATION("Inside mmi_prov_cca_new_setting_res_hdlr");
    data = (mmi_cca_source_ui_new_setting_rsp_struct*) msg;
    if (data->response == CCA_STATUS_OK)
    {
    #ifdef __MMI_JATAAYU_WBXML_SUPPORT__
        i_ret = mmi_prov_handle_provisioning_setting();
    #else 
        i_ret = mmi_prov_cca_handle_ok();
    #endif 
    }
    if (g_prov_data_queue_size > 0) /* Delete entry from queue */
    {
        mmi_prov_cca_delete_queue_entry();
    }
    if (i_ret != PROV_CCA_OK)
    {
        mmi_prov_handle_error(i_ret);
    }
    if (g_prov_data_queue_size > 0)
    {
        mmi_prov_cca_new_setting_ind_req();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside mmi_prov_cca_new_setting_res_hdlr - ", i_ret);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_new_doc_ind_req
 * DESCRIPTION
 *  write MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND event to mmi task
 * PARAMETERS
 *  hdoc_config     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_new_doc_ind_req(S32 hdoc_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_new_doc_ind_struct *data;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_cca_new_doc_ind_req");
    data = (mmi_cca_source_new_doc_ind_struct*) OslConstructDataPtr(sizeof(mmi_cca_source_new_doc_ind_struct));
    ASSERT(data);
    data->spec_id = CCA_SPEC_OMA;
    data->hConfig = hdoc_config;

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_new_doc_res_hdlr
 * DESCRIPTION
 *  handle MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP events from mmi task
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_new_doc_res_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_cca_new_doc_res_hdlr");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_invalid_setting_ind_req
 * DESCRIPTION
 *  write MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND event to mmi task
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_cca_invalid_setting_ind_req(cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_invalid_setting_ind_struct *data;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_cca_invalid_setting_ind_req");
    data =
        (mmi_cca_source_ui_invalid_setting_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_cca_source_ui_invalid_setting_ind_struct));
    ASSERT(data);
    /* data->spec_id = CCA_SPEC_OMA; */
    data->status = status;

    Message.oslSrcId = MOD_WAP;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_provisioning_data_handler
 * DESCRIPTION
 *  It handles the prov. data buffer received
 * PARAMETERS
 *  prov_buffer_p       [IN]        
 *  prov_length         [IN]        
 *  content_type_p      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_provisioning_data_handler(S8 *prov_buffer_p, U32 prov_length, S8 *content_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE i_ret = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_provisioning_data_handler");
    mmi_prov_cca_add_to_queue(prov_buffer_p, prov_length);  /* check the error code */
    if (g_prov_data_queue_size == 1)
    {
        mmi_prov_cca_new_setting_ind_req();
    }

    return i_ret;

}

#ifdef __MMI_JATAAYU_WBXML_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_provisioning_setting
 * DESCRIPTION
 *  handle provisioning setting
 * PARAMETERS
 *  void
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_provisioning_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 root;
    S32 hdoc_config;
    S32 par_ret = 0;
    PROV_CCA_RETCODE ret_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_handle_provisioning_setting");
    root = mmi_cca_doc_new_rootnode();
    if (!root)
    {
        return PROV_CCA_ERR;
    }
    mmi_prov_context_initialize(root, 0);
    par_ret = mmi_prov_wbxml_parser_handler();
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "ERROR: WBXML_PARSER", par_ret);

    if (g_prov_cca_handler_ctx.valid_prov_tag && (g_prov_cca_handler_ctx.err_code == PROV_CCA_UNKNOWN_TAG))
    {
        g_prov_cca_handler_ctx.err_code = PROV_CCA_OK;
    }
    ret_code = mmi_prov_convert_wbxml_parser_error_code(par_ret);
    if (g_prov_cca_handler_ctx.err_code == PROV_CCA_OK && ret_code != PROV_CCA_OK)
    {
        g_prov_cca_handler_ctx.err_code = ret_code;
    }

    ret_code = mmi_prov_root_end_tag_hdlr(g_prov_cca_handler_ctx.err_code);
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
    if (ret_code == PROV_CCA_OK)
    {
        ret_code = mmi_prov_ne_post_parsing_operation(root);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "ERROR: NE_Post_Parsing", ret_code);
    }
#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ 
    ret_code = mmi_prov_fix_cca_doc(root, ret_code);
    ret_code = mmi_prov_create_dependency_relationship(root, ret_code);

    if (ret_code != PROV_CCA_OK)
    {
        mmi_cca_docroot_release(root);
        goto error;
    }
    mmi_cca_oma_sort_new_doc(root);
    hdoc_config = mmi_cca_doc_new(root);
    if (!hdoc_config)
    {
        mmi_cca_docroot_release(root);
        ret_code = PROV_CCA_MEM_FULL;
        goto error;
    }
    mmi_prov_cca_new_doc_ind_req(hdoc_config);
  error:
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "ERROR: Jataayu CCA", ret_code);
    mmi_prov_free_memory();
    return ret_code;

    return g_prov_cca_handler_ctx.err_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_malloc_buffer
 * DESCRIPTION
 *  Allocate memory for wbxml parser
 * PARAMETERS
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_prov_wbxml_malloc_buffer(kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdd_MemAlloc(1, len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_free_buffer
 * DESCRIPTION
 *  Free memory for wbxml parser
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_wbxml_free_buffer(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ptr);
    jdd_MemFree(ptr);
    ptr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_get_attrname_by_token
 * DESCRIPTION
 *  get attrname by oken
 * PARAMETERS
 *  ptr             [OUT]       
 *  attrprefix      [OUT]       
 *  attrcp          [IN]        
 *  token           [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mmi_prov_wbxml_get_attrname_by_token(
            kal_char *ptr,
            kal_char *attrprefix,
            kal_uint32 attrcp,
            kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *temp = NULL;
    kal_int32 len = 0;
    JC_INT32 more_attribute_value = 0;
    JC_INT32 quote_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_prov_cca_handler_ctx.prov_type)
    {
        case PROV_OTA_TYPE_OMA:
        {
            if (MMI_PROV_WAP_SWITCH_PAGE == attrcp)
            {
                if (token >= MMI_PROV_SATTR_MIN && token <= MMI_PROV_SATTR_MAX)
                {
                    temp = (kal_char*) MMI_PROV_SATTR_DESC(token);
                }
                else if (token >= MMI_PROV_VATTR_MIN && token <= MMI_PROV_VATTR_MAX)
                {
                    temp = (kal_char*) MMI_PROV_VATTR_DESC(token);
                }
                else
                {
                    return 0;   /* No string found for the corresponding token */
                    /* ASSERT(0); */
                }

            }
            else if (MMI_PROV_OMA_SWITCH_PAGE == attrcp)
            {
                if (token >= MMI_PROV_OMA_SATTR_MIN && token <= MMI_PROV_OMA_SATTR_MAX)
                {
                    temp = (kal_char*) MMI_PROV_OMA_SATTR_DESC(token);
                }
                else if (token >= MMI_PROV_VATTR_MIN && token <= MMI_PROV_VATTR_MAX)
                {
                    temp = (kal_char*) MMI_PROV_OMA_VATTR_DESC(token);
                }
                else
                {
                    return 0;   /* No string found for the corresponding token */
                    /* ASSERT(0); */
                }
            }
            else
            {
                ASSERT(0);
            }
            break;
        }

        case PROV_OTA_TYPE_WAP:
        {
            if (token >= MMI_PROV_NOKIA_SATTR_MIN && token <= MMI_PROV_NOKIA_SATTR_MAX)
            {
                temp = (kal_char*) MMI_PROV_NOKIA_SATTR_DESC(token);
            }
        #ifdef JATAAYU_CCA_NOT_REQUIRED
            else if (token >= MMI_PROV_NOKIA_VATTR_MIN && token <= MMI_PROV_NOKIA_VATTR_MAX)
            {
                temp = (kal_char*) MMI_PROV_NOKIA_VATTR_DESC(token);
                ASSERT(0);  /* Later removed */
            }
        #endif /* JATAAYU_CCA_NOT_REQUIRED */ 
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
        }
            break;
        default:
            ASSERT(0);

    }
    if (temp)
    {
        len = strlen(temp);
        if (len < MAX_WBXML_PARSER_BUFFER)
        {
            /* more_attribute_value = jdi_UtilsGetCharOccurence(temp, '\"', 0); */
            more_attribute_value = mmi_prov_get_char_occurence(temp, '\"', 0);
            if (more_attribute_value == ATTRIBUTE_VALUE_NUMBER)
            {
                /* quote_index = jdi_UtilsIndexOf('\"', temp, 0); */
                quote_index = mmi_prov_index_of_char('\"', temp, 0);
                memset(ptr, 0, quote_index);
                strncpy(ptr, temp, quote_index - 1);
                temp += quote_index + 1;
                memset(attrprefix, 0, strlen(temp));
                strncpy(attrprefix, temp, strlen(temp) - 1);
            }
            else if (more_attribute_value == 0)
            {
                memset(ptr, 0, strlen(temp) + 1);
                strcpy(ptr, temp);
            }
        }
        else
        {
            len = -1;
        }
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_get_tagname_by_token
 * DESCRIPTION
 *  get tagname by token
 * PARAMETERS
 *  ptr         [OUT]       
 *  tagcp       [IN]        
 *  token       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mmi_prov_wbxml_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *temp = NULL;
    kal_int32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_prov_cca_handler_ctx.prov_type)
    {
        case PROV_OTA_TYPE_OMA:
            if (token >= MMI_PROV_TAGS_MIN && token <= MMI_PROV_TAGS_MAX)
            {
                temp = (kal_char*) MMI_PROV_TAG_DESC(token);
            }
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
            break;
        case PROV_OTA_TYPE_WAP:
            if (token >= MMI_PROV_NOKIA_TAGS_MIN && token <= MMI_PROV_NOKIA_TAGS_MAX)
            {
                temp = (kal_char*) MMI_PROV_NOKIA_TAG_DESC(token);
            }
            else
            {
                return 0;   /* No string found for the corresponding token */
                /* ASSERT(0); */
            }
            break;
        default:
            ASSERT(0);
    }
    if (temp)
    {
        len = strlen(temp);
        if (len < MAX_WBXML_PARSER_BUFFER)
        {
            strcpy(ptr, temp);
        }
        else
        {
            len = -1;
        }
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_header_hdlr
 * DESCRIPTION
 *  wbxml header hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  publicid        [IN]        
 *  charset         [IN]        
 *  mainver         [IN]        
 *  subver          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_wbxml_header_hdlr(
        void *resv,
        kal_char *publicid,
        kal_uint32 charset,
        kal_uint8 mainver,
        kal_uint8 subver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(publicid);
    if (mmi_prov_check_if_substring(publicid, PROV_OMA_PUBLIC_ID) == 0)
    {
        g_prov_cca_handler_ctx.prov_type = PROV_OTA_TYPE_OMA;
    }
    else if (mmi_prov_check_if_substring(publicid, PROV_WAP_PUBLIC_ID) == 0)
    {
        g_prov_cca_handler_ctx.prov_type = PROV_OTA_TYPE_WAP;
    }
    else
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_data_hdlr
 * DESCRIPTION
 *  wbxml start tag hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  tagname         [IN]        
 *  data            [IN]        
 *  len             [IN]        
 *  datatype        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_wbxml_data_hdlr(
        void *resv,
        const kal_char *tagname,
        const kal_char *data,
        kal_uint32 len,
        kal_uint8 datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently Data not required */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_start_hdlr
 * DESCRIPTION
 *  wbxml start tag hdlr
 * PARAMETERS
 *  resv            [IN]        
 *  tagname         [IN]        
 *  attrlist        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_wbxml_start_hdlr(void *resv, const kal_char *tagname, const kal_char **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(tagname);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%s)", "[JCCA] Tagname - ", tagname);
    if (strcmp(tagname, PROV_CHARACTERISTIC) == 0)
    {
        if (!g_prov_cca_handler_ctx.unnkown_tag_count)
        {
            g_prov_cca_handler_ctx.err_code = mmi_prov_handle_characteristic_tag(attrlist);
        }
        if (g_prov_cca_handler_ctx.err_code == PROV_CCA_UNKNOWN_TAG)
        {
            g_prov_cca_handler_ctx.unnkown_tag_count++;
        }
    }
    /* In case of unknown tag don't add its parametere */
    else if ((strcmp(tagname, "parm") == 0) && (g_prov_cca_handler_ctx.err_code != PROV_CCA_UNKNOWN_TAG))
    {
        g_prov_cca_handler_ctx.err_code = mmi_prov_handle_param_tag(attrlist);

    }

    if ((g_prov_cca_handler_ctx.err_code != PROV_CCA_OK) && (g_prov_cca_handler_ctx.err_code != PROV_CCA_UNKNOWN_TAG))
    {
	    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside mmi_prov_wbxml_start_hdlr - ", g_prov_cca_handler_ctx.err_code);
        wbxml_stop_parser(g_prov_cca_handler_ctx.wbxml_handle);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_end_hdlr
 * DESCRIPTION
 *  wbxml end tag hdlr
 * PARAMETERS
 *  resv        [IN]        
 *  tagname     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_wbxml_end_hdlr(void *resv, const kal_char *tagname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(tagname);
    if (strcmp(tagname, PROV_CHARACTERISTIC) == 0)
    {
        if (!g_prov_cca_handler_ctx.unnkown_tag_count)
        {
            /* Assert here if g_prov_cca_handler_ctx.cur_node_level<0 */
            retcode = mmi_prov_characteristic_end_tag_hdlr(g_prov_cca_handler_ctx.cur_node_level);
            g_prov_cca_handler_ctx.cur_node_level--;
        }
        else if (g_prov_cca_handler_ctx.err_code == PROV_CCA_UNKNOWN_TAG)
        {
            ASSERT((g_prov_cca_handler_ctx.unnkown_tag_count != 0));
            g_prov_cca_handler_ctx.unnkown_tag_count--;
        }
    }
    ASSERT(retcode == PROV_CCA_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_wbxml_parser_handler
 * DESCRIPTION
 *  wbxml parser handler
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_wbxml_parser_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    prov_cca_queue_data_struct *prov_data_p;

    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prov_data_p = prov_data_queue[g_prov_data_queue_current_item];
    if (!prov_data_p->plength)
    {
        return WBXML_E_NO_MEMORY;
    }
    g_prov_cca_handler_ctx.wbxml_handle = wbxml_new_parser();
    wbxml_configure_memory(
        g_prov_cca_handler_ctx.wbxml_handle,
        mmi_prov_wbxml_malloc_buffer,
        mmi_prov_wbxml_free_buffer);

    wbxml_register_header_handler(g_prov_cca_handler_ctx.wbxml_handle, mmi_prov_wbxml_header_hdlr);
    wbxml_register_data_handler(g_prov_cca_handler_ctx.wbxml_handle, mmi_prov_wbxml_data_hdlr);
    wbxml_register_element_handler(
        g_prov_cca_handler_ctx.wbxml_handle,
        mmi_prov_wbxml_start_hdlr,
        mmi_prov_wbxml_end_hdlr);
    wbxml_register_get_name_handler(
        g_prov_cca_handler_ctx.wbxml_handle,
        mmi_prov_wbxml_get_tagname_by_token,
        mmi_prov_wbxml_get_attrname_by_token);
    ret = wbxml_parse(g_prov_cca_handler_ctx.wbxml_handle, prov_data_p->pbuffer, prov_data_p->plength);
    wbxml_close_parser(g_prov_cca_handler_ctx.wbxml_handle);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_convert_wbxml_parser_error_code
 * DESCRIPTION
 *  convert wbxml parser error code
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_convert_wbxml_parser_error_code(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE ret_code = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err_code)
    {
        case WBXML_RESULT_OK:
            ret_code = PROV_CCA_OK;
            break;
        case WBXML_E_NO_MEMORY:
            ret_code = PROV_CCA_MEM_FULL;
            break;
        case WBXML_RESULT_FAIL:
        case WBXML_E_UNKNOWN_CHARSET:
        case WBXML_E_UNKNOWN_TAG:
        case WBXML_E_MISMATCH_TAG:
            ret_code = PROV_CCA_ERR;
            break;
        default:
            ASSERT(0);
    }

    return ret_code;

}
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ /* #ifdef __MMI_JATAAYU_WBXML_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_characteristic_tag
 * DESCRIPTION
 *  handle characteristic tag
 * PARAMETERS
 *  attrlist        [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_characteristic_tag(const S8 **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE ret_code = PROV_CCA_OK;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attrlist[0])
    {
        tag_str = (S8*) attrlist[1];
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%s)", "[JCCA] Charname - ", tag_str);
    }
    if (attrlist[2])
    {
        tag_str_val = (S8*) attrlist[3];
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%s)", "[JCCA] Charvalue - ", tag_str_val);
    }
    ret_code = mmi_prov_add_cca_characteristic_node(tag_str, tag_str_val, 0);
    PRINT_INFORMATION("Exit mmi_prov_handle_characteristic_tag");

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_param_tag
 * DESCRIPTION
 *  handle param ag
 * PARAMETERS
 *  attrlist        [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_param_tag(const S8 **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE ret_code = PROV_CCA_OK;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attrlist[0])
    {
        tag_str = (S8*) attrlist[1];
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%s)", "[JCCA] Param Name - ", tag_str);
    }
    if (attrlist[2])
    {
        tag_str_val = (S8*) attrlist[3];
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%s)", "[JCCA] Param Value - ", tag_str_val);
    }
    ret_code = mmi_prov_add_cca_param_value(tag_str, tag_str_val);
    PRINT_INFORMATION("Exit mmi_prov_handle_param_tag");

    return ret_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_context_initialize
 * DESCRIPTION
 *  Initializes prov context
 * PARAMETERS
 *  cca_root_hdl        [IN]        
 *  xml_root_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_context_initialize(S32 cca_root_hdl, S32 xml_root_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prov_cca_handler_ctx.err_code = PROV_CCA_OK;
    g_prov_cca_handler_ctx.cur_node_level = 0;
    g_prov_cca_handler_ctx.unnkown_tag_count = 0;
    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].xml_node_id = xml_root_id;
    g_prov_cca_handler_ctx.valid_prov_tag = MMI_FALSE;
    g_prov_cca_handler_ctx.parent_parent_id = 0x00;
    g_prov_cca_handler_ctx.node_parent_id = PROV_ROOT_NODE_VAL;
    memset(g_cur_cca_node_char_taghdlr, 0, sizeof(g_cur_cca_node_char_taghdlr));
    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].par_cca_node_h = 0;
    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h = cca_root_hdl;
    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].characteristic_tag_hdlr =
        mmi_prov_characteristic_root_tag_hdlr;
    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr =
        prov_root_param_tag_hdlr_mapping_table;

#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
    memset(g_prov_cca_handler_ctx.first_proxy_id, 0, sizeof(g_prov_cca_handler_ctx.first_proxy_id));
#endif 
}

#ifndef __MMI_JATAAYU_WBXML_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_cca_handle_ok
 * DESCRIPTION
 *  This deals with the sequences that happen when a user accepts the setings to be installed
 *  in this the wbxml prov. doc is decoded and information is extracted from it
 * PARAMETERS
 *  void
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_cca_handle_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE i_ret = PROV_CCA_OK;
    prov_cca_queue_data_struct *prov_data_p;
    struct xml XMLInfo = {0, };
    WBXML_HANDLE WBXMLHandle;
    JC_RETCODE ret = JC_OK;

    /* XML_HANDLE xml_handle; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_cca_handle_ok");
    prov_data_p = prov_data_queue[g_prov_data_queue_current_item];
    if (!prov_data_p->plength)
    {
        return PROV_CCA_MEM_FULL;
    }
    ret = jdi_WBXMLDecode((U8*) prov_data_p->pbuffer, prov_data_p->plength, &XMLInfo, NULL, 0, 0, &WBXMLHandle);

    if (ret == JC_OK)
    {
        i_ret = PROV_CCA_OK;
    }
    else if (ret == JC_ERR_MEMORY_ALLOCATION)
    {
        i_ret = PROV_CCA_MEM_FULL;
    }
    else
    {
        i_ret = PROV_CCA_ERR;
    }

    if (i_ret == PROV_CCA_OK)
    {
        PRINT_INFORMATION("Inside mmi_prov_cca_handle_ok - Construct CCA doc");

        if (mmi_prov_check_if_substring(XMLInfo.root->name, "wap-provisioningdoc") == 0)
        {
            g_prov_cca_handler_ctx.prov_type = PROV_OTA_TYPE_OMA;
        }
        else if (mmi_prov_check_if_substring(XMLInfo.root->name, "characteristic-list") == 0)
        {
            g_prov_cca_handler_ctx.prov_type = PROV_OTA_TYPE_WAP;
        }
        else
        {
            ASSERT(0);
        }
        i_ret = mmi_prov_oma_construct_cca_doc(XMLInfo.root);
    }
    /* check else part */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside mmi_prov_cca_handle_ok - ", i_ret);
    jdi_XMLFreeTree(&XMLInfo);

    PRINT_INFORMATION("Exit mmi_prov_cca_handle_ok");
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_construct_cca_doc
 * DESCRIPTION
 *  It calls the respective handler for the various OMA provisioning  characteristics supported & the One not supported
 *  all the needed information is extracted
 * PARAMETERS
 *  root_p      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_oma_construct_cca_doc(TAG *root_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE i_ret = PROV_CCA_OK;
    ATTRIBUTE *attr_p = NULL;
    S32 root;
    S32 hdoc_config;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct root node */

    PRINT_INFORMATION("Inside mmi_prov_oma_construct_cca_doc");
    root = mmi_cca_doc_new_rootnode();
    if (!root)
    {
        return PROV_CCA_ERR;
    }
    mmi_prov_context_initialize(root, root_p->id);
    root_p = root_p->next;

    while (root_p != NULL)
    {

        attr_p = root_p->attribute_list;

        if (root_p->parent_id->id != g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].xml_node_id)
        {
            i_ret = mmi_prov_jparser_characteristic_end_tag_hdlr(root_p->parent_id->id);
        }

        if (strcmp(root_p->name, PROV_CHARACTERISTIC) == 0)
        {
            i_ret = mmi_prov_handle_jparser_characteristic_tag(&root_p);
        }
        /* In case of unknown tag don't add its parametere */
        else if ((strcmp(root_p->name, "parm") == 0) && (i_ret != PROV_CCA_UNKNOWN_TAG))
        {
            i_ret = mmi_prov_handle_jparser_param_tag(&root_p);

        }

        if ((i_ret != PROV_CCA_OK) && (i_ret != PROV_CCA_UNKNOWN_TAG))
        {
            break;
        }
        root_p = root_p->next;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside while loop - ", root_p);

    }

    if (g_prov_cca_handler_ctx.valid_prov_tag && (i_ret == PROV_CCA_UNKNOWN_TAG))
    {
        i_ret = PROV_CCA_OK;
    }

    PRINT_INFORMATION("Out of While loop");
    i_ret = mmi_prov_root_end_tag_hdlr(i_ret);
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
    if (i_ret == PROV_CCA_OK)
    {
        i_ret = mmi_prov_ne_post_parsing_operation(root);
    }
#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */
    i_ret = mmi_prov_fix_cca_doc(root, i_ret);
    i_ret = mmi_prov_create_dependency_relationship(root, i_ret);

    if (i_ret != PROV_CCA_OK)
    {
        mmi_cca_docroot_release(root);
        goto error;
    }
    mmi_cca_oma_sort_new_doc(root);
    hdoc_config = mmi_cca_doc_new(root);
    if (!hdoc_config)
    {
        mmi_cca_docroot_release(root);
        i_ret = PROV_CCA_MEM_FULL;
        goto error;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "ERROR: Jataayu CCA", i_ret);
    mmi_prov_cca_new_doc_ind_req(hdoc_config);
  error:
    mmi_prov_free_memory();
    return i_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_jparser_characteristic_end_tag_hdlr
 * DESCRIPTION
 *  Handles the end tag of the characteristic tag.
 * PARAMETERS
 *  parentNodeId        [IN]        IN\OUT
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_jparser_characteristic_end_tag_hdlr(U32 parentNodeId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 loop_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_jparser_characteristic_end_tag_hdlr");
    for (loop_count = 0; loop_count <= g_prov_cca_handler_ctx.cur_node_level; loop_count++)
    {
        if (g_cur_cca_node_char_taghdlr[loop_count].xml_node_id == parentNodeId)
        {
            break;
        }
    }
    if (loop_count == g_prov_cca_handler_ctx.cur_node_level)
    {
        return PROV_CCA_OK; /* Last Unknown tag end */

    }
    else if (loop_count > g_prov_cca_handler_ctx.cur_node_level)
    {
        return PROV_CCA_UNKNOWN_TAG;    /* Unknown tag end */

    }
    while (g_prov_cca_handler_ctx.cur_node_level > loop_count)
    {
        retcode = mmi_prov_characteristic_end_tag_hdlr(g_prov_cca_handler_ctx.cur_node_level);
        g_prov_cca_handler_ctx.cur_node_level--;
    }
    PRINT_INFORMATION("Exit mmi_prov_jparser_characteristic_end_tag_hdlr");
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_jparser_characteristic_tag
 * DESCRIPTION
 *  Handles characteristic tags in case of jataayu parser
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_jparser_characteristic_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_handle_jparser_characteristic_tag");
    root_p = *nextroot_p;
    attr_p = root_p->attribute_list;
    ASSERT(attr_p);
    tag_str = (S8*) attr_p->value;
    attr_p = attr_p->next;
    if (attr_p)
    {
        tag_str_val = (S8*) attr_p->value;
    }
    retcode = mmi_prov_add_cca_characteristic_node(tag_str, tag_str_val, root_p->id);
    PRINT_INFORMATION("Exit mmi_prov_handle_jparser_characteristic_tag");

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_jparser_param_tag
 * DESCRIPTION
 *  Hnadles parameter tags.
 * PARAMETERS
 *  nextroot_p      [IN]        IN\OUT
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_jparser_param_tag(TAG **nextroot_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    ATTRIBUTE *attr_p = NULL;
    TAG *root_p;
    S8 *tag_str = NULL;
    S8 *tag_str_val = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_handle_jparser_param_tag");
    root_p = *nextroot_p;
    attr_p = root_p->attribute_list;
    ASSERT(attr_p);
    tag_str = (S8*) attr_p->value;
    attr_p = attr_p->next;
    if (attr_p)
    {
        tag_str_val = (S8*) attr_p->value;
    }
    retcode = mmi_prov_add_cca_param_value(tag_str, tag_str_val);
    PRINT_INFORMATION("Exit mmi_prov_handle_jparser_param_tag");

    return retcode;
}

#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ /* #ifndef __MMI_JATAAYU_WBXML_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_root_end_tag_hdlr
 * DESCRIPTION
 *  Handles the end tag of the root.
 * PARAMETERS
 *  retcode     [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_root_end_tag_hdlr(PROV_CCA_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_root_end_tag_hdlr");
    if (retcode != PROV_CCA_OK)
    {
        return retcode;
    }
    while (g_prov_cca_handler_ctx.cur_node_level > 0)
    {
        retcode = mmi_prov_characteristic_end_tag_hdlr(g_prov_cca_handler_ctx.cur_node_level);
        g_prov_cca_handler_ctx.cur_node_level--;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Exit mmi_prov_root_end_tag_hdlr", retcode);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_end_tag_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cur_node_level      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_end_tag_hdlr(U8 cur_node_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_characteristic_end_tag_hdlr");

    retcode =
        g_cur_cca_node_char_taghdlr[cur_node_level].
        characteristic_tag_hdlr(&g_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h, PROV_CHARACTERISTIC_END);
    /* retcode return error if any must present field is absent from the node */
    mmi_prov_release_sibling_node_from_node_list(&g_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h, retcode);

    if (retcode == PROV_CCA_OK)
    {
        retcode = mmi_prov_attach_node_to_sibling_node_list(
                    g_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h,
                    g_cur_cca_node_char_taghdlr[cur_node_level].par_cca_node_h);
    }
    else
    {
        /* Release the node and its child node froom cca node tree if it is not released */
        if (g_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h)
        {
            mmi_cca_doc_node_release_all(g_cur_cca_node_char_taghdlr[cur_node_level].crt_cca_node_h);
        }
    }
    memset(&g_cur_cca_node_char_taghdlr[cur_node_level], 0, sizeof(g_cur_cca_node_char_taghdlr[cur_node_level]));

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_oma_get_cca_nodeid
 * DESCRIPTION
 *  Creates the unique node id for CCA node.
 * PARAMETERS
 *  nodeid      [IN]        IN\OUT
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *mmi_prov_oma_get_cca_nodeid(S8 *nodeid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 cca_nodeid = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeid[0] = cca_nodeid;
    nodeid[1] = 0;

    cca_nodeid++;
    if (cca_nodeid > MAX_NODEID_ITTR)
    {
        cca_nodeid = 1;
    }
    return nodeid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_cca_nodeid
 * DESCRIPTION
 *  Add nodeid to CCA nodes.
 * PARAMETERS
 *  crtnode_h       [IN]        
 *  charTagName     [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_cca_nodeid(S32 crtnode_h, U16 *charTagName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S8 nodeid[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_prov_compare_str((S8*) PROV_PXPHYSICAL, charTagName) == 0) ||
        (mmi_prov_compare_str((S8*) PROV_APPLICATION, charTagName) == 0) ||
        (mmi_prov_compare_str((S8*) PROV_NAPDEF, charTagName) == 0)
#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
#endif /* #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
        || (mmi_prov_compare_str((S8*) PROV_NE_ADDRESS, charTagName) == 0)
        || (mmi_prov_compare_str((S8*) PROV_NE_MMSURL, charTagName) == 0)
#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ 
        )
    {
        if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_NODEID, mmi_prov_oma_get_cca_nodeid(nodeid)) ==
            CCA_STATUS_MEMFULL)
        {
            /* retcode = PROV_CCA_MEM_FULL; */
            return PROV_CCA_MEM_FULL;
        }
    }
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_characteristic_end_tag_value
 * DESCRIPTION
 *  handle unknown characteristic tag
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_h          [IN]        
 * RETURNS
 *  PROV_CCA_OK
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_characteristic_end_tag_value(const S8 *tag_str, const S8 *tag_str_val, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
    if (mmi_prov_compare_str((S8*) PROV_NE_MMSURL, (U16*) tag_str) == 0)
    {
        retcode = mmi_prov_add_nodedata_str_to_cca_node(node_h, CCA_NS_OMA_ADDR, (U16*) tag_str_val);
    }
#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ 
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_unknown_characteristic_tag
 * DESCRIPTION
 *  handle unknown characteristic tag
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_id         [IN]        
 *  retcode         [IN]        
 * RETURNS
 *  PROV_CCA_OK
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_handle_unknown_characteristic_tag(
                    const S8 *tag_str,
                    const S8 *tag_str_val,
                    S32 node_id,
                    PROV_CCA_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (retcode != PROV_CCA_OK)
    {
        return retcode;
    }
    else
    {
        ASSERT(tag_str);
        retcode = PROV_CCA_UNKNOWN_TAG;

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
    #endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */ 
    #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__
        /* Only first url to be considered */
        if ((mmi_prov_compare_str((S8*) PROV_NE_URL, (U16*) tag_str) == 0) && (!g_prov_cca_handler_ctx.app_url))
        {
            if (mmi_prov_copy_utf8_str((U8 **) & g_prov_cca_handler_ctx.app_url, (U8*) tag_str_val) ==
                PROV_CCA_MEM_FULL)
            {
                return PROV_CCA_MEM_FULL;
            }
        }
    #endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ 

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_cca_characteristic_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 *  node_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_cca_characteristic_node(const S8 *tag_str, const S8 *tag_str_val, S32 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 crtnode_h;
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 count = 0;
    MMI_BOOL unknowntag = MMI_TRUE;
    const prov_characteristic_tag_hdlr_struct *prov_characteristic_tag_hdlr_mapping_table = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(tag_str); */
    if (tag_str == NULL)
    {
        return PROV_CCA_UNKNOWN_TAG;
    }
    if (g_prov_cca_handler_ctx.prov_type == PROV_OTA_TYPE_OMA)
    {
        prov_characteristic_tag_hdlr_mapping_table = prov_oma_characteristic_tag_hdlr_mapping_table;
    }
    else if (g_prov_cca_handler_ctx.prov_type == PROV_OTA_TYPE_WAP)
    {
        prov_characteristic_tag_hdlr_mapping_table = prov_non_oma_characteristic_tag_hdlr_mapping_table;
    }
    ASSERT(prov_characteristic_tag_hdlr_mapping_table);
    while (prov_characteristic_tag_hdlr_mapping_table[count].characterestic != NULL)
    {
        if (mmi_prov_compare_str
            ((S8*) prov_characteristic_tag_hdlr_mapping_table[count].characterestic, (U16*) tag_str) == 0)
        {
            if ((g_prov_cca_handler_ctx.node_parent_id & (~g_prov_cca_handler_ctx.parent_parent_id))
                & prov_characteristic_tag_hdlr_mapping_table[count].src_parent_node_id)
                /* if (((g_prov_cca_handler_ctx.node_parent_id)&(~(g_prov_cca_handler_ctx.node_parent_id & 
                   (~prov_characteristic_tag_hdlr_mapping_table[count].src_parent_node_id))))&
                   (prov_characteristic_tag_hdlr_mapping_table[count].src_parent_node_id)) */

            {
                retcode = prov_characteristic_tag_hdlr_mapping_table[count].
                    characteristic_tag_hdlr(
                        &g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                        PROV_CHARACTERISTIC_START);
                if (retcode == PROV_CCA_MEM_FULL)
                {
                    return retcode;
                }
                else if (retcode != PROV_CCA_DUP_NODE_CREATED)
                {
                    crtnode_h = mmi_cca_doc_new_node_and_attach(
                                    prov_characteristic_tag_hdlr_mapping_table[count].cca_node_id,
                                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h);
                    if (!crtnode_h)
                    {
                        return PROV_CCA_MEM_FULL;
                    }

                    g_prov_cca_handler_ctx.cur_node_level++;
                    if (g_prov_cca_handler_ctx.cur_node_level >= MAX_NODE_LEVEL)
                    {
                        ASSERT(0);
                    }
                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].par_cca_node_h =
                        g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level - 1].crt_cca_node_h;
                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h = crtnode_h;
                }
                g_prov_cca_handler_ctx.parent_parent_id = g_prov_cca_handler_ctx.node_parent_id;
                g_prov_cca_handler_ctx.node_parent_id |= prov_characteristic_tag_hdlr_mapping_table[count].src_node_id;

                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].xml_node_id = node_id;       /* For jparser */
                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].characteristic_tag_hdlr =
                    prov_characteristic_tag_hdlr_mapping_table[count].characteristic_tag_hdlr;
                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr =
                    prov_characteristic_tag_hdlr_mapping_table[count].char_param_tag_map_hdlr;
                retcode = mmi_prov_add_cca_nodeid(
                            g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                            (U16*) tag_str);
                unknowntag = MMI_FALSE;
                g_prov_cca_handler_ctx.valid_prov_tag = MMI_TRUE;
                if (retcode == PROV_CCA_OK)
                {
                    retcode = mmi_prov_handle_characteristic_end_tag_value(
                                tag_str,
                                tag_str_val,
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h);
                }
                break;
            }
        }
        count++;
        PRINT_INFORMATION("Inside mmi_prov_handle_jparser_characteristic_tag");
    }
    if (unknowntag)
    {
        retcode = mmi_prov_handle_unknown_characteristic_tag(tag_str, tag_str_val, node_id, retcode);
    }
    PRINT_INFORMATION("Exit mmi_prov_handle_jparser_characteristic_tag");
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_cca_param_value
 * DESCRIPTION
 *  Adds the provising parameter value to CCA nodes.
 * PARAMETERS
 *  tag_str         [IN]        
 *  tag_str_val     [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_cca_param_value(const S8 *tag_str, const S8 *tag_str_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 count = 0;
    U16 ret_value = 0;  /* it stores the enum value return by the function */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(tag_str); */
    if (tag_str == NULL)
    {
        return retcode;
    }
    while (g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].param !=
           NULL)
    {
        if (mmi_prov_compare_str
            ((S8*) g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].
             param, (U16*) tag_str) == 0)
        {

            if (g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].
                param_tag_hdlr /* && tag_str_val */ )
            {
                retcode =
                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].
                    param_tag_hdlr(
                        (U16*) tag_str_val,
                        &g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                        (U16*) & ret_value);
                if (retcode != PROV_CCA_OK)
                {
                    return retcode;
                }
            }

            switch (g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].
                    convtype)
            {
                case PROV_CCA_CONV_STR:
                {
                    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                (U16*) tag_str_val);
                    break;
                }
                case PROV_CCA_CONV_ENUM_FROM_STR:
                {
                    retcode = mmi_prov_add_nodedata_enum_to_cca_node(
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                ret_value);
                    break;
                }
                case PROV_CCA_CONV_INT:
                {
                    retcode = mmi_prov_add_nodedata_int_to_cca_node(
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h,
                                g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].char_param_tag_map_hdlr[count].cca_symbol,
                                (U16*) tag_str_val);

                    break;
                }
                default:

                    break;
            }
            break;
        }
        count++;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_appauth_param_authlevel_tag_hdlr
 * DESCRIPTION
 *  Handles authlevele param of appauth characteristic.
 * PARAMETERS
 *  attr_value      [IN]        
 *  root            [IN]        
 *  ret_value       [IN\OUT]
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_appauth_param_authlevel_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_authlevel_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_application_param_tonapid_tag_hdlr
 * DESCRIPTION
 *  Handles tonapid param of application characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_application_param_tonapid_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S8 nodeid[2];
    U8 *out_buffer = NULL;
    S8 **out_new_pxy_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_JATAAYU_WBXML_SUPPORT__
    out_buffer = (U8*) attr_value;
#else /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    {
        S32 buf_size = 0;

        buf_size = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) attr_value);
        out_buffer = jdd_MemAlloc(1, buf_size + 1);

        if (NULL == out_buffer)
        {
            retcode = PROV_CCA_MEM_FULL;
            return retcode;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) out_buffer, buf_size + 1, (U8*) attr_value);
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 

    /* If value already exist then don't add virtual proxy */
    retcode = mmi_prov_check_dup_application_param_tonapid_value(out_buffer);
    if (retcode == PROV_CCA_OK)
    {
        if (!mmi_cca_oma_generate_virtual_proxy_node(
                (const S8*)(out_buffer),
                mmi_prov_oma_get_cca_nodeid(nodeid),
                out_new_pxy_id))
        {
            retcode = PROV_CCA_MEM_FULL;
        }
    }
    else if (retcode == PROV_CCA_ERR)
    {
        retcode = PROV_CCA_OK;
    }

#ifndef __MMI_JATAAYU_WBXML_SUPPORT__
    if (out_buffer != NULL)
    {
        jdd_MemFree(out_buffer);
        out_buffer = NULL;
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_napauthinfo_param_authentity_tag_hdlr
 * DESCRIPTION
 *  Handles authentity param of napauthinfo characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_napauthinfo_param_authentity_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_authentity_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_napdef_param_bearer_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_napdef_param_bearer_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_napdef_param_bearer_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_napdef_param_calltype_tag_hdlr
 * DESCRIPTION
 *  Handles calltype param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_napdef_param_calltype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_napdef_param_calltype_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_port_param_service_tag_hdlr
 * DESCRIPTION
 *  Handles service param of port characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_port_param_service_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_port_param_service_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_param_authtype_tag_hdlr
 * DESCRIPTION
 *  Handles authtype param of characteristics.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_param_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_authtype_str_enum_table);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_proxy_param_pushpullenabled_tag_hdlr
 * DESCRIPTION
 *  Handles pushpullenabled param of proxy characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_proxy_param_pushpullenabled_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_pushpullenabled_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_param_addrtype_tag_hdlr
 * DESCRIPTION
 *  Handles addrtype param of characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_param_addrtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_addrtype_str_enum_table);
    return retcode;
}

#if 0   /* currently not in use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_root_tag_hdlr
 * DESCRIPTION
 *  Handles root characteristic tag.
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_root_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:

            g_prov_cca_handler_ctx.parent_parent_id &= ~0x00;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_ROOT_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_pxphysical_tag_hdlr
 * DESCRIPTION
 *  Handles pxphysical characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_pxphysical_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If status is PROV_CHARACTERISTIC_START then the input node is parent node otherwise current node */
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:

            crtnode_h = mmi_doc_duplicate_node(g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].
                                               crt_cca_node_h);
            if (crtnode_h)
            {
                if (mmi_cca_doc_attach_node_to_parent
                    (crtnode_h,
                     g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level - 1].crt_cca_node_h) ==
                    CCA_STATUS_OK)
                {
                    g_prov_cca_handler_ctx.cur_node_level++;
                    if (g_prov_cca_handler_ctx.cur_node_level >= MAX_NODE_LEVEL)
                    {
                        ASSERT(0);
                    }
                    /* the parent node will be the same as that of the sibling node */
                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].par_cca_node_h =
                        g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level - 1].par_cca_node_h;
                    g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h = crtnode_h;
                    retcode = mmi_prov_add_sibling_node_to_node_list(crtnode_h, *root);
                    if (retcode == PROV_CCA_OK)
                    {
                        retcode = PROV_CCA_DUP_NODE_CREATED;
                    }
                }
                else
                {
                    ASSERT(0);
                }
            }
            else
            {
                retcode = PROV_CCA_MEM_FULL;
            }
            break;

        case PROV_CHARACTERISTIC_END:

            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_PXLOGICAL_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_PXPHYSICAL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_pxlogical_tag_hdlr
 * DESCRIPTION
 *  Handles pxlogical characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_pxlogical_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /* S8 loop_count; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_PXLOGICAL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_port_tag_hdlr
 * DESCRIPTION
 *  Handles port characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_port_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:

            if (g_prov_cca_handler_ctx.node_parent_id & PROV_APPADDR_NODE_VAL)
            {
                crtnode_h = mmi_doc_duplicate_node(g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].
                                                   crt_cca_node_h);
                if (crtnode_h)
                {
                    if (mmi_cca_doc_attach_node_to_parent(
                            crtnode_h,
                            g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level - 1].crt_cca_node_h) ==
                        CCA_STATUS_OK)
                    {
                        g_prov_cca_handler_ctx.cur_node_level++;
                        if (g_prov_cca_handler_ctx.cur_node_level >= MAX_NODE_LEVEL)
                        {
                            ASSERT(0);
                        }
                        /* the parent node will be the same as that of the sibling node */
                        g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].par_cca_node_h =
                            g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level - 1].par_cca_node_h;
                        g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h = crtnode_h;
                        retcode = mmi_prov_add_sibling_node_to_node_list(crtnode_h, *root);
                        if (retcode == PROV_CCA_OK)
                        {
                            retcode = PROV_CCA_DUP_NODE_CREATED;
                        }

                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    retcode = PROV_CCA_MEM_FULL;
                }
            }
            break;

            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &=
                ~(PROV_PXLOGICAL_NODE_VAL | PROV_PXPHYSICAL_NODE_VAL | PROV_APPADDR_NODE_VAL);
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_PORT_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_pxauthinfo_tag_hdlr
 * DESCRIPTION
 *  Handles pxauthinfo characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_pxauthinfo_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_PXLOGICAL_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_PXAUTHINFO_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_application_tag_hdlr
 * DESCRIPTION
 *  Handles application characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_application_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:

            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_APPLICATION_NODE_VAL;
            /* mmi_prov_check_dup_application_param_tonapid_value(NULL); */
            mmi_prov_free_application_param_tonapid_value();
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_resource_tag_hdlr
 * DESCRIPTION
 *  Handles resource characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_resource_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_APPLICATION_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_RESOURCE_NODE_VAL;

            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_appaddr_tag_hdlr
 * DESCRIPTION
 *  Handles appaddr characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_appaddr_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_APPLICATION_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_APPADDR_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_appauth_tag_hdlr
 * DESCRIPTION
 *  Handles appauth characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_appauth_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_APPLICATION_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_APPAUTH_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_bootstrap_tag_hdlr
 * DESCRIPTION
 *  Handles bootstrap characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_bootstrap_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_BOOTSTRAP_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_napdef_tag_hdlr
 * DESCRIPTION
 *  Handles napdef characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_napdef_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NAPDEF_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_napauthinfo_tag_hdlr
 * DESCRIPTION
 *  Handles napauthinfo characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_napauthinfo_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_NAPDEF_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NAPAUTHINFO_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_validity_tag_hdlr
 * DESCRIPTION
 *  Handles validity characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_validity_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_NAPDEF_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_VALIDITY_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_access_tag_hdlr
 * DESCRIPTION
 *  Handles access characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_access_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_ACCESS_NODE_VAL;
            break;

    }
    return retcode;
}

#ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_address_tag_hdlr
 * DESCRIPTION
 *  Handles NE Address characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_address_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S32 crtnode_h;
    S8 nodeid[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
        {
            g_prov_cca_handler_ctx.proxy_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, *root);
            if (!g_prov_cca_handler_ctx.proxy_node)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str
                (g_prov_cca_handler_ctx.proxy_node, CCA_NS_NODEID,
                 mmi_prov_oma_get_cca_nodeid(nodeid)) == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            crtnode_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, *root);
            if (!crtnode_h)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_NODEID, mmi_prov_oma_get_cca_nodeid(nodeid)) ==
                CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_OMA_APPID, "w2") == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str
                (g_prov_cca_handler_ctx.proxy_node, CCA_NS_OMA_PROXY_ID,
                 mmi_prov_oma_get_cca_nodeid(nodeid)) == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (!strlen((S8*) g_prov_cca_handler_ctx.first_proxy_id))
            {
                strcpy((S8*) g_prov_cca_handler_ctx.first_proxy_id, nodeid);
            }
            if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_OMA_TO_PROXY, nodeid) == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_prov_create_node_list(&g_prov_cca_handler_ctx.cca_brw_app_node_list_p, crtnode_h) ==
                PROV_CCA_MEM_FULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (mmi_prov_create_node_list
                (&g_prov_cca_handler_ctx.cca_proxy_node_list_p, g_prov_cca_handler_ctx.proxy_node) == PROV_CCA_MEM_FULL)
            {
                return PROV_CCA_MEM_FULL;
            }
        }
            break;

        case PROV_CHARACTERISTIC_END:
        {

            if (mmi_cca_doc_add_nodedata_str(*root, CCA_NS_OMA_NAPID, mmi_prov_oma_get_cca_nodeid(nodeid)) ==
                CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str(g_prov_cca_handler_ctx.proxy_node, CCA_NS_OMA_TO_NAPID, nodeid) ==
                CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            g_prov_cca_handler_ctx.napauthinfo_node = 0;
            g_prov_cca_handler_ctx.pxauthinfo_node = 0;
            g_prov_cca_handler_ctx.proxy_node = 0;
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_ADRESS_NODE_VAL;
        }
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_url_tag_hdlr
 * DESCRIPTION
 *  Handles NE URL characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_url_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_URL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_mmsurl_tag_hdlr
 * DESCRIPTION
 *  Handles NE MMSURL characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_mmsurl_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            if (mmi_cca_doc_add_nodedata_str(*root, CCA_NS_OMA_APPID, "w4") == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (mmi_prov_create_node_list(&g_prov_cca_handler_ctx.cca_mms_app_node_list_p, *root) == PROV_CCA_MEM_FULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_MMSURL_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_bookmark_tag_hdlr
 * DESCRIPTION
 *  Handles NE bookmark characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_bookmark_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S32 crtnode_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
        {
            crtnode_h = mmi_cca_doc_new_node(CCA_NS_OMA_RESOURCE);

            if (!crtnode_h)
            {
                return PROV_CCA_MEM_FULL;
            }

            g_prov_cca_handler_ctx.cur_node_level++;
            if (g_prov_cca_handler_ctx.cur_node_level >= MAX_NODE_LEVEL)
            {
                ASSERT(0);
            }
            g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].par_cca_node_h = 0;
            g_cur_cca_node_char_taghdlr[g_prov_cca_handler_ctx.cur_node_level].crt_cca_node_h = crtnode_h;

            if (mmi_prov_create_node_list(&g_prov_cca_handler_ctx.cca_resorce_node_list_p, crtnode_h) ==
                PROV_CCA_MEM_FULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (retcode == PROV_CCA_OK)
            {
                retcode = PROV_CCA_DUP_NODE_CREATED;
            }

        }
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_BOOKMARK_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_id_tag_hdlr
 * DESCRIPTION
 *  Handles NE ID characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_id_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_ID_NODE_VAL;
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_characteristic_ne_name_tag_hdlr
 * DESCRIPTION
 *  Handles NE name characteristic tag
 * PARAMETERS
 *  root                [IN]        IN\OUT
 *  charac_status       [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_characteristic_ne_name_tag_hdlr(S32 *root, prov_characteristic_status_enum charac_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charac_status)
    {
        case PROV_CHARACTERISTIC_START:
            break;

        case PROV_CHARACTERISTIC_END:
            g_prov_cca_handler_ctx.parent_parent_id &= ~PROV_ROOT_NODE_VAL;
            g_prov_cca_handler_ctx.node_parent_id &= ~PROV_NE_NAME_NODE_VAL;
            mmi_cca_doc_node_release_all(*root);
            break;

    }
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_sms_smsc_tag_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_sms_smsc_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(*root, CCA_NS_OMA_NAP_ADDRTYPE, CCA_NS_VAL_E164);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_ussd_sevice_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_ussd_sevice_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(*root, CCA_NS_OMA_NAP_ADDRTYPE, CCA_NS_VAL_SCODE);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_gprs_accesspoint_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_gprs_accesspoint_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(*root, CCA_NS_OMA_NAP_ADDRTYPE, CCA_NS_VAL_APN);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_ppp_authtype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_ppp_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_prov_cca_handler_ctx.napauthinfo_node)
    {
        g_prov_cca_handler_ctx.napauthinfo_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_prov_cca_handler_ctx.napauthinfo_node)
        {
            return PROV_CCA_MEM_FULL;
        }

    }
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(
                g_prov_cca_handler_ctx.napauthinfo_node,
                CCA_NS_OMA_AUTHTYPE,
                mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_authtype_str_enum_table));
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_ppp_logintype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_ppp_logintype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_ne_logintype_str_enum_table);
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_proxy_logintype_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_proxy_logintype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_prov_ne_address_param_ppp_logintype_tag_hdlr(attr_value, root, ret_value);
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(g_prov_cca_handler_ctx.proxy_node, CCA_NS_OMA_LOGINTYPE, *ret_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_ppp_authname_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_ppp_authname_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_prov_cca_handler_ctx.napauthinfo_node)
    {
        g_prov_cca_handler_ctx.napauthinfo_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_prov_cca_handler_ctx.napauthinfo_node)
        {
            return PROV_CCA_MEM_FULL;
        }

    }
    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                g_prov_cca_handler_ctx.napauthinfo_node,
                CCA_NS_OMA_AUTHNAME,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_ppp_authsecret_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_ppp_authsecret_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_prov_cca_handler_ctx.napauthinfo_node)
    {
        g_prov_cca_handler_ctx.napauthinfo_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_NAPAUTHINFO, *root);
        if (!g_prov_cca_handler_ctx.napauthinfo_node)
        {
            return PROV_CCA_MEM_FULL;
        }

    }
    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                g_prov_cca_handler_ctx.napauthinfo_node,
                CCA_NS_OMA_AUTHSECRET,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_proxy_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_proxy_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                g_prov_cca_handler_ctx.proxy_node,
                CCA_NS_OMA_PXADDR,
                (U16*) attr_value);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_proxy_type_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_proxy_type_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_value = mmi_prov_get_enum_from_str_enum_table(attr_value, prov_param_ne_addrtype_str_enum_table);
    retcode = mmi_prov_add_nodedata_enum_to_cca_node(g_prov_cca_handler_ctx.proxy_node, CCA_NS_OMA_PXADDRTYPE, *ret_value);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_proxy_authname_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_proxy_authname_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_prov_cca_handler_ctx.proxy_node);
    if (!g_prov_cca_handler_ctx.pxauthinfo_node)
    {
        g_prov_cca_handler_ctx.pxauthinfo_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, g_prov_cca_handler_ctx.proxy_node);
        if (!g_prov_cca_handler_ctx.pxauthinfo_node)
        {
            return PROV_CCA_MEM_FULL;
        }

    }

    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                g_prov_cca_handler_ctx.pxauthinfo_node,
                CCA_NS_OMA_PXAUTH_ID,
                (U16*) attr_value);

    if (retcode != PROV_CCA_MEM_FULL)
    {
        retcode = mmi_prov_add_nodedata_enum_to_cca_node(
                    g_prov_cca_handler_ctx.pxauthinfo_node,
                    CCA_NS_OMA_PXAUTH_TYPE,
                    CCA_NS_VAL_HTTP_BASIC);
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_proxy_authsecret_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_proxy_authsecret_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_prov_cca_handler_ctx.proxy_node);
    if (!g_prov_cca_handler_ctx.pxauthinfo_node)
    {
        g_prov_cca_handler_ctx.pxauthinfo_node = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, g_prov_cca_handler_ctx.proxy_node);
        if (!g_prov_cca_handler_ctx.pxauthinfo_node)
        {
            return PROV_CCA_MEM_FULL;
        }

    }

    retcode = mmi_prov_add_nodedata_str_to_cca_node(
                g_prov_cca_handler_ctx.pxauthinfo_node,
                CCA_NS_OMA_PXAUTH_PW,
                (U16*) attr_value);
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_address_param_port_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_address_param_port_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U16 cca_enum_value;
    S32 value = 0;
    S32 node_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_prov_cca_handler_ctx.proxy_node);
    node_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, g_prov_cca_handler_ctx.proxy_node);
    if (!node_h)
    {
        return PROV_CCA_MEM_FULL;
    }
    if (mmi_prov_covert_str_to_int(attr_value, &value) == PROV_CCA_MEM_FULL)
    {
        return PROV_CCA_MEM_FULL;
    }
    if (mmi_prov_add_nodedata_str_to_cca_node(node_h, CCA_NS_OMA_PORTNBR, attr_value) == CCA_STATUS_MEMFULL)
    {
        return PROV_CCA_MEM_FULL;
    }
    switch (value)
    {
        case PROV_NE_PORT_9200:
            cca_enum_value = CCA_NS_VAL_CL_WSP;
            break;
        case PROV_NE_PORT_9201:
            cca_enum_value = CCA_NS_VAL_CO_WSP;
            break;
        case PROV_NE_PORT_9202:
            cca_enum_value = CCA_NS_VAL_CL_SEC_WSP;
            break;
        case PROV_NE_PORT_9203:
            cca_enum_value = CCA_NS_VAL_CO_SEC_WSP;
            break;
        default:
            cca_enum_value = CCA_NS_VAL_OTA_HTTP_TO;
    }

    if (mmi_cca_doc_add_nodedata_int(node_h, CCA_NS_OMA_SERVICE, cca_enum_value) == CCA_STATUS_MEMFULL)
    {
        return PROV_CCA_MEM_FULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_name_param_name_tag_hdlr
 * DESCRIPTION
 *  Handles bearer param of napdef characteristic.
 * PARAMETERS
 *  attr_value      [IN]            
 *  root            [IN]            
 *  ret_value       [IN/OUT]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_name_param_name_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_prov_copy_utf8_str((U8 **) & g_prov_cca_handler_ctx.setting_name, (U8*) attr_value) == PROV_CCA_MEM_FULL)
    {
        return PROV_CCA_MEM_FULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_node_list
 * DESCRIPTION
 *  Creare link list.
 * PARAMETERS
 *  head        [IN]        
 *  node_h      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_create_node_list(prov_cca_node_list_struct **head, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_list_struct *temp_node = NULL;
    prov_cca_node_list_struct *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node = jdd_MemAlloc(1, sizeof(prov_cca_node_list_struct));
    if (NULL == new_node)
    {
        retcode = PROV_CCA_MEM_FULL;
        return retcode;
    }
    new_node->node_h = node_h;
    new_node->node_next = NULL;

    if (*head)
    {
        temp_node = *head;
        while (temp_node->node_next != NULL)
        {
            temp_node = (prov_cca_node_list_struct*) temp_node->node_next;
        }

        temp_node->node_next = new_node;
    }
    else    /* In case of first node */
    {
        *head = new_node;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_ne_post_parsing_operation
 * DESCRIPTION
 *  Perform post parsing operation.
 * PARAMETERS
 *  root_h      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_ne_post_parsing_operation(S32 root_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_list_struct *temp_node = NULL;

    /* prov_cca_node_list_struct *new_node = NULL; */
    S32 res_node_h = 0;
    S32 crtnode_h = 0;
    S8 nodeid[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Fill TO_PROXY and NAME param for mms applications */
    if (g_prov_cca_handler_ctx.cca_mms_app_node_list_p)
    {
        temp_node = g_prov_cca_handler_ctx.cca_mms_app_node_list_p;
        while (temp_node != NULL)
        {
            if (strlen((S8*) g_prov_cca_handler_ctx.first_proxy_id))
            {
                if (mmi_cca_doc_add_nodedata_str
                    (temp_node->node_h, CCA_NS_OMA_TO_PROXY,
                     (const S8*)g_prov_cca_handler_ctx.first_proxy_id) == CCA_STATUS_MEMFULL)
                {
                    return PROV_CCA_MEM_FULL;
                }
            }
            if (g_prov_cca_handler_ctx.setting_name)
            {
                if (mmi_cca_doc_add_nodedata_str
                    (temp_node->node_h, CCA_NS_OMA_NAME,
                     (const S8*)g_prov_cca_handler_ctx.setting_name) == CCA_STATUS_MEMFULL)
                {
                    return PROV_CCA_MEM_FULL;
                }
            }
            temp_node = (prov_cca_node_list_struct*) temp_node->node_next;
        }
    }
    /* Attach all the resource nodes to first application noew */
    if (g_prov_cca_handler_ctx.cca_resorce_node_list_p)
    {
        temp_node = g_prov_cca_handler_ctx.cca_resorce_node_list_p;
        if (g_prov_cca_handler_ctx.cca_brw_app_node_list_p)
        {
            crtnode_h = g_prov_cca_handler_ctx.cca_brw_app_node_list_p->node_h;
        }
        else    /* In case of no application node */
        {
            crtnode_h = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_APPLICATION, root_h);
            if (!crtnode_h)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_NODEID, mmi_prov_oma_get_cca_nodeid(nodeid)) ==
                CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

            if (mmi_cca_doc_add_nodedata_str(crtnode_h, CCA_NS_OMA_APPID, "w2") == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }

        }
        while (temp_node != NULL)
        {
            if (mmi_cca_doc_attach_node_to_parent(temp_node->node_h, crtnode_h) != CCA_STATUS_OK)
            {
                ASSERT(0);
            }
            temp_node = (prov_cca_node_list_struct*) temp_node->node_next;
        }
    }

    if (g_prov_cca_handler_ctx.cca_brw_app_node_list_p)
    {
        /* Create a resource node for a homepage */
        if (g_prov_cca_handler_ctx.app_url)
        {
            res_node_h = mmi_cca_doc_new_node(CCA_NS_OMA_RESOURCE);
            if (!res_node_h)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (mmi_cca_doc_add_nodedata_str(res_node_h, CCA_NS_OMA_URI, (const S8*)g_prov_cca_handler_ctx.app_url) ==
                CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }
            if (mmi_cca_doc_add_nodedata_str(res_node_h, CCA_NS_OMA_STARTPAGE, (const S8*)"") == CCA_STATUS_MEMFULL)
            {
                return PROV_CCA_MEM_FULL;
            }
        }

        temp_node = g_prov_cca_handler_ctx.cca_brw_app_node_list_p;
        while (temp_node != NULL)
        {
            /* Add setting name to all App nodes */
            if (g_prov_cca_handler_ctx.setting_name)
            {
                if (mmi_cca_doc_add_nodedata_str
                    (temp_node->node_h, CCA_NS_OMA_NAME,
                     (const S8*)g_prov_cca_handler_ctx.setting_name) == CCA_STATUS_MEMFULL)
                {
                    return PROV_CCA_MEM_FULL;
                }
            }
            if (res_node_h)
            {
                crtnode_h = mmi_doc_duplicate_node(res_node_h);
                if (crtnode_h)
                {
                    if (mmi_cca_doc_attach_node_to_parent(crtnode_h, temp_node->node_h) != CCA_STATUS_OK)
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    return PROV_CCA_MEM_FULL;
                }
            }
            temp_node = (prov_cca_node_list_struct*) temp_node->node_next;
        }
        if (res_node_h)
        {
            mmi_cca_doc_node_release_all(res_node_h);
        }

    }
    /* Add setting name to all proxy nodes */
    if (g_prov_cca_handler_ctx.cca_proxy_node_list_p)
    {
        if (g_prov_cca_handler_ctx.setting_name)
        {
            temp_node = g_prov_cca_handler_ctx.cca_proxy_node_list_p;
            while (temp_node != NULL)
            {
                if (mmi_cca_doc_add_nodedata_str
                    (temp_node->node_h, CCA_NS_OMA_NAME,
                     (const S8*)g_prov_cca_handler_ctx.setting_name) == CCA_STATUS_MEMFULL)
                {
                    return PROV_CCA_MEM_FULL;
                }
                temp_node = (prov_cca_node_list_struct*) temp_node->node_next;
            }
        }
    }

    return retcode;
}
#endif /* __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */ /* #ifdef __JATAAYU_CCA_NOKIA_OTA_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_sibling_node_to_node_list
 * DESCRIPTION
 *  Adds parameter values to all sibling node of the given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  node_h          [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_sibling_node_to_node_list(S32 cur_node_h, S32 node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_hdlr_st *temp_node = NULL;
    prov_cca_node_hdlr_st *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node = jdd_MemAlloc(1, sizeof(prov_cca_node_hdlr_st));
    if (NULL == new_node)
    {
        retcode = PROV_CCA_MEM_FULL;
        return retcode;
    }
    new_node->node_h = node_h;
    new_node->cur_node_h = cur_node_h;
    new_node->node_hdlr_next = NULL;

    if (g_prov_cca_handler_ctx.sibling_node_list_p)
    {
        temp_node = g_prov_cca_handler_ctx.sibling_node_list_p;
        while (temp_node->node_hdlr_next != NULL)
        {
            temp_node = (prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
        }

        temp_node->node_hdlr_next = new_node;
    }
    else    /* In case of first node */
    {
        g_prov_cca_handler_ctx.sibling_node_list_p = new_node;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_release_sibling_node_from_node_list
 * DESCRIPTION
 *  Release all sibling node from node list of the given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  retcode         [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_release_sibling_node_from_node_list(S32 *cur_node_h, PROV_CCA_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 releaseFlag = 0;
    prov_cca_node_hdlr_st *curNodePtr = NULL;
    prov_cca_node_hdlr_st *prevNodeptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Inside mmi_prov_release_sibling_node_from_node_list - ",
                         g_prov_cca_handler_ctx.sibling_node_list_p);
    prevNodeptr = curNodePtr = g_prov_cca_handler_ctx.sibling_node_list_p;
    while (curNodePtr != NULL)
    {
        if (*cur_node_h == curNodePtr->node_h)
        {
            releaseFlag = 1;
            if (retcode != PROV_CCA_OK)
            {
                /* Release the node and its child node from cca node tree 
                   the node from which it is duplicated has an error */
                mmi_cca_doc_node_release_all(curNodePtr->cur_node_h);
            }
            if (curNodePtr == g_prov_cca_handler_ctx.sibling_node_list_p)       /* in case of first node */
            {
                g_prov_cca_handler_ctx.sibling_node_list_p = (prov_cca_node_hdlr_st*) curNodePtr->node_hdlr_next;
                prevNodeptr = (prov_cca_node_hdlr_st*) curNodePtr->node_hdlr_next;
                jdd_MemFree(curNodePtr);
                curNodePtr = NULL;
                curNodePtr = g_prov_cca_handler_ctx.sibling_node_list_p;
            }
            else
            {
                prevNodeptr->node_hdlr_next = curNodePtr->node_hdlr_next;
                jdd_MemFree(curNodePtr);
                curNodePtr = NULL;
                curNodePtr = (prov_cca_node_hdlr_st*) prevNodeptr->node_hdlr_next;
            }

        }
        else
        {
            prevNodeptr = curNodePtr;
            curNodePtr = (prov_cca_node_hdlr_st*) curNodePtr->node_hdlr_next;
        }
    }
    if (releaseFlag)
    {
        /* Release the node and its child node froom cca node tree */
        mmi_cca_doc_node_release_all(*cur_node_h);
        *cur_node_h = 0;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_nodedata_int_to_sibling_node_list
 * DESCRIPTION
 *  Add ineger param data to all sibling nodes of given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  cca_symbol      [IN]        
 *  value           [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_nodedata_int_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_prov_cca_handler_ctx.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (cur_node_h == temp_node->node_h)
        {
            if (mmi_cca_doc_add_nodedata_int(cur_node_h, cca_symbol, value) == CCA_STATUS_MEMFULL)
            {
                retcode = PROV_CCA_MEM_FULL;
                break;
            }
        }
        temp_node = (prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_nodedata_str_to_sibling_node_list
 * DESCRIPTION
 *  Add string param data to all sibling nodes of given node.
 * PARAMETERS
 *  cur_node_h      [IN]        
 *  cca_symbol      [IN]        
 *  valuPtr         [IN\OUT]
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_nodedata_str_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S8 *valuPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_node = g_prov_cca_handler_ctx.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (cur_node_h == temp_node->node_h)
        {
            if (mmi_cca_doc_add_nodedata_str(cur_node_h, cca_symbol, (const S8*)valuPtr) == CCA_STATUS_MEMFULL)
            {
                retcode = PROV_CCA_MEM_FULL;
                break;
            }
        }
        temp_node = (prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_attach_node_to_sibling_node_list
 * DESCRIPTION
 *  Attach sibling node  to given node's parrent node.
 * PARAMETERS
 *  cur_node_h          [IN]        
 *  par_cca_node_h      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_attach_node_to_sibling_node_list(S32 cur_node_h, S32 par_cca_node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    prov_cca_node_hdlr_st *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!par_cca_node_h)
    {
        return retcode;
    }
    temp_node = g_prov_cca_handler_ctx.sibling_node_list_p;
    while (temp_node != NULL)
    {
        if (par_cca_node_h == temp_node->node_h)
        {
            if (mmi_cca_doc_add_node_to_parent(cur_node_h, temp_node->cur_node_h) == CCA_STATUS_MEMFULL)
            {
                retcode = PROV_CCA_MEM_FULL;
                break;
            }
        }
        temp_node = (prov_cca_node_hdlr_st*) temp_node->node_hdlr_next;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_remove_deprel_nodes
 * DESCRIPTION
 *  Deattach dependency relation ship nodes from its parent nodes.
 * PARAMETERS
 *  cur_node_h      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_remove_deprel_nodes(S32 cur_node_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* S8 loop_count; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently not in used */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_fix_cca_doc
 * DESCRIPTION
 *  Wraper for mmi_cca_oma_fix_doc.
 * PARAMETERS
 *  hroot       [IN]        
 *  retcode     [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_fix_cca_doc(S32 hroot, PROV_CCA_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_fix_cca_doc");
    if (retcode != PROV_CCA_OK)
    {
        return retcode;
    }
    mmi_cca_oma_fix_doc(hroot);
    PRINT_INFORMATION("Exit mmi_prov_fix_cca_doc");

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_create_dependency_relationship
 * DESCRIPTION
 *  Create dependency relationship nodes between proxy and napdef and
 *  proxy and application.
 * PARAMETERS
 *  hroot       [IN]        
 *  retcode     [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_create_dependency_relationship(S32 hroot, PROV_CCA_RETCODE retcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 deprel_node_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside mmi_prov_create_dependency_relationship");
    if (retcode != PROV_CCA_OK)
    {
        return retcode;
    }
    deprel_node_h = mmi_cca_oma_generate_deprel_node(hroot);

    if (!deprel_node_h)
    {
        retcode = PROV_CCA_MEM_FULL;
    }
    else
    {
        if (mmi_cca_doc_attach_node_to_parent(deprel_node_h, hroot) != CCA_STATUS_OK)
        {
            ASSERT(0);
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "Exit mmi_prov_create_dependency_relationship", retcode);

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_enum_from_str_enum_table
 * DESCRIPTION
 *  Converts given string values to corresponding enumerated value.
 * PARAMETERS
 *  attrValue           [IN]        
 *  strEnumTable        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_prov_get_enum_from_str_enum_table(U16 *attrValue, const prov_convert_str_to_enum_struct strEnumTable[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == attrValue)
    {
        return CCA_NS_VAL__EMPTY;
    }
#ifdef __MMI_JATAAYU_WBXML_SUPPORT__
    if (!strlen((S8*) attrValue))
    {
        return CCA_NS_VAL__EMPTY;
    }
#else /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    if (!mmi_ucs2strlen((S8*) attrValue))
    {
        return CCA_NS_VAL__EMPTY;
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    while (strEnumTable[loop_count].src_str != NULL)
    {
        if (mmi_prov_compare_str((S8*) strEnumTable[loop_count].src_str, (U16*) attrValue) == 0)
        {
            return strEnumTable[loop_count].cca_enum_value;
        }
        loop_count++;
    }
    return CCA_NS_VAL__INVALID; /* strEnumTable[loop_count].cca_enum_value; */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_compare_ansi_unicode_str
 * DESCRIPTION
 *  Compares ansi and unicode strings.
 * PARAMETERS
 *  firstStr        [IN]        
 *  secondStr       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_compare_ansi_unicode_str(S8 *firstStr, U16 *secondStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *tempStr1;
    S8 *tempStr2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (firstStr == NULL || secondStr == NULL)
    {
        return -1;
    }
    tempStr1 = (JC_CHAR*) secondStr;
    tempStr2 = (JC_INT8*) firstStr;

    while (*tempStr1 != '\0' && *tempStr2 != '\0')
    {
        if (*tempStr1 > *tempStr2)
        {
            return 1;
        }
        else if (*tempStr1 < *tempStr2)
        {
            return -1;
        }
        else
        {
            tempStr1++;
            tempStr2++;
        }
    }
    if (*tempStr1 == '\0' && *tempStr2 == '\0')
    {
        return 0;
    }
    else if (*tempStr1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_compare_str
 * DESCRIPTION
 *  Compares strings.
 * PARAMETERS
 *  firstStr        [IN]        
 *  secondStr       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_compare_str(S8 *firstStr, U16 *secondStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(firstStr && secondStr);
#ifdef __MMI_JATAAYU_WBXML_SUPPORT__
    return strcmp(firstStr, (S8*) secondStr);
#else 
    return mmi_prov_compare_ansi_unicode_str(firstStr, secondStr);      /* For jparser 2nd string will be ucs2 */
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_if_substring
 * DESCRIPTION
 *  This function checks whether the sub-string starts with the given string.
 *  on an error it returns -1 else returns 0.
 * PARAMETERS
 *  string_p            [IN]        The main string
 *  sub_string_p        [IN]        The sub string to be checked
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_check_if_substring(const S8 *string_p, const S8 *sub_string_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_len;
    S32 start_len;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string_p == NULL)
    {
        return -1;
    }
    if (sub_string_p == NULL)
    {
        return -1;
    }

    buf_len = strlen(string_p);
    start_len = strlen(sub_string_p);

    if (start_len > buf_len)
    {
        return -1;
    }
    for (i = 0; i < start_len; i++)
    {
        if (sub_string_p[i] != string_p[i])
        {
            return -1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_copy_utf8_str
 * DESCRIPTION
 *  Copy strings.
 * PARAMETERS
 *  dest_str        [IN]        
 *  src_str         [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_copy_utf8_str(U8 **dest_str, U8 *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_str == NULL)
    {
        return retcode;
    }
    ASSERT(*dest_str == NULL);
#ifdef __MMI_JATAAYU_WBXML_SUPPORT__
    *dest_str = jdd_MemAlloc(1, strlen((S8*) src_str) + 1);
    if (NULL == *dest_str)
    {
        retcode = PROV_CCA_MEM_FULL;
        return retcode;
    }
    strcpy((S8*) * dest_str, (S8*) src_str);

#else /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    {
        S32 buf_size;

        buf_size = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) src_str);
        *dest_str = jdd_MemAlloc(1, buf_size + 1);
        if (NULL == *dest_str)
        {
            retcode = PROV_CCA_MEM_FULL;
            return retcode;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) * dest_str, buf_size + 1, (U8*) src_str);
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_covert_str_to_int
 * DESCRIPTION
 *  Convert str to int.
 * PARAMETERS
 *  valuPtr     [?]     [?]
 *  value       [?]     [?]
 *  secondStr(?)        [IN](?)
 *  firstStr(?)         [IN](?)
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_covert_str_to_int(U16 *valuPtr, S32 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 *out_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (valuPtr)
    {
    #ifdef __MMI_JATAAYU_WBXML_SUPPORT__
        *value = atoi((S8*) valuPtr);
    #else /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
        {
            U16 strlen;

            strlen = mmi_ucs2strlen((S8*) valuPtr);
            out_buffer = jdd_MemAlloc(1, strlen + 1);
            if (NULL == out_buffer)
            {
                retcode = PROV_CCA_MEM_FULL;
                return retcode;
            }

            mmi_ucs2_to_asc((S8*) out_buffer, (S8*) valuPtr);
            *value = atoi((S8*) out_buffer);
        }
    #endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 
    }
    if (out_buffer != NULL)
    {
        jdd_MemFree(out_buffer);
        out_buffer = NULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_get_char_occurence
 * DESCRIPTION
 *  It gives the count of the character ch in the buffer.
 * PARAMETERS
 *  buffer      [IN]        
 *  ch          [IN]        
 *  index       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_get_char_occurence(const S8 *buffer, S32 ch, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;
    S8 *p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return -1;
    }
    p = (S8*) buffer;
    count = 0;
    i = 0;
    while (*p != '\0')
    {
        if (*p == ch && i >= index)
        {
            count++;
        }
        i++;
        p++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_index_of_char
 * DESCRIPTION
 *  It returns the index number of a charcter in a buffer.
 * PARAMETERS
 *  ch          [IN]        
 *  buffer      [IN]        
 *  start       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_prov_index_of_char(S8 ch, const S8 *buffer, S32 start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S8 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return -1;
    }
    p = (S8*) buffer;
    i = 0;
    while (*p != '\0')
    {
        if (*p == ch && i >= start)
        {
            return i;
        }
        i++;
        p++;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_nodedata_str_to_cca_node
 * DESCRIPTION
 *  Adds string param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  valuPtr             [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_nodedata_str_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *valuPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 *out_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_buffer = (U8*) valuPtr;
#ifndef __MMI_JATAAYU_WBXML_SUPPORT__
    if (valuPtr)
    {
        S32 buf_size = 0;

        buf_size = mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) valuPtr);
        out_buffer = jdd_MemAlloc(1, buf_size + 1);
        if (NULL == out_buffer)
        {
            retcode = PROV_CCA_MEM_FULL;
            return retcode;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) out_buffer, buf_size + 1, (U8*) valuPtr);
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 

    if (mmi_cca_doc_add_nodedata_str(curccanode_h, cca_symbol, (const S8*)(out_buffer)) != CCA_STATUS_MEMFULL)
    {
        retcode = mmi_prov_add_nodedata_str_to_sibling_node_list(curccanode_h, cca_symbol, (S8*) out_buffer);
    }
    else
    {
        retcode = PROV_CCA_MEM_FULL;
    }

#ifndef __MMI_JATAAYU_WBXML_SUPPORT__
    if (out_buffer != NULL)
    {
        jdd_MemFree(out_buffer);
        out_buffer = NULL;
    }
#endif /* __MMI_JATAAYU_WBXML_SUPPORT__ */ 

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_nodedata_int_to_cca_node
 * DESCRIPTION
 *  Adds integer param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  valuPtr             [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_nodedata_int_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *valuPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_prov_covert_str_to_int(valuPtr, &value) == PROV_CCA_MEM_FULL)
    {
        return PROV_CCA_MEM_FULL;
    }
    if (mmi_cca_doc_add_nodedata_int(curccanode_h, cca_symbol, value) != CCA_STATUS_MEMFULL)
    {
        retcode = mmi_prov_add_nodedata_int_to_sibling_node_list(curccanode_h, cca_symbol, value);

    }
    else
    {
        retcode = PROV_CCA_MEM_FULL;
    }

    return retcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_add_nodedata_enum_to_cca_node
 * DESCRIPTION
 *  Adds enumerated param value to CCA node.
 * PARAMETERS
 *  curccanode_h        [IN]        
 *  cca_symbol          [IN]        
 *  value               [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_add_nodedata_enum_to_cca_node(S32 curccanode_h, U16 cca_symbol, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value == 0xffff)
    {
        ASSERT(0);  /* to be removed later */
        /* return retcode; */
    }

    if (mmi_cca_doc_add_nodedata_int(curccanode_h, cca_symbol, value) != CCA_STATUS_MEMFULL)
    {
        retcode = mmi_prov_add_nodedata_int_to_sibling_node_list(curccanode_h, cca_symbol, value);
    }
    else
    {
        retcode = PROV_CCA_MEM_FULL;
    }

    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_check_dup_application_param_tonapid_value
 * DESCRIPTION
 *  check the duplicate tonapid value in an application tag.
 * PARAMETERS
 *  out_buffer      [IN]        
 * RETURNS
 *  PROV_CCA_RETCODE
 *****************************************************************************/
PROV_CCA_RETCODE mmi_prov_check_dup_application_param_tonapid_value(U8 *out_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PROV_CCA_RETCODE retcode = PROV_CCA_OK;
    U8 loop_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (out_buffer)
    {
        for (loop_count = 0; loop_count < MAX_TONAPID_SUPPORT; loop_count++)
        {
            if (g_prov_cca_handler_ctx.tonapid[loop_count] &&
                (!strcmp((S8*) g_prov_cca_handler_ctx.tonapid[loop_count], (S8*) out_buffer)))
            {
                return PROV_CCA_ERR;
            }
            else if (g_prov_cca_handler_ctx.tonapid[loop_count] == NULL)
            {
                g_prov_cca_handler_ctx.tonapid[loop_count] = jdd_MemAlloc(1, strlen((S8*) out_buffer) + 1);

                if (NULL == g_prov_cca_handler_ctx.tonapid[loop_count])
                {
                    return PROV_CCA_MEM_FULL;
                }
                strcpy((S8*) g_prov_cca_handler_ctx.tonapid[loop_count], (S8*) out_buffer);
                break;
            }
        }
    }
    return retcode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_free_application_param_tonapid_value
 * DESCRIPTION
 *  free tonapid value in an application tag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_free_application_param_tonapid_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 loop_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_prov_cca_handler_ctx.tonapid[loop_count] && loop_count < MAX_TONAPID_SUPPORT)
    {
        jdd_MemFree(g_prov_cca_handler_ctx.tonapid[loop_count]);
        g_prov_cca_handler_ctx.tonapid[loop_count] = NULL;
        loop_count++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_prov_handle_error
 * DESCRIPTION
 *  error handler.
 * PARAMETERS
 *  i_ret       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prov_handle_error(PROV_CCA_RETCODE i_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status = CCA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (i_ret)
    {
        case PROV_CCA_ERR:
        case PROV_CCA_UNKNOWN_TAG:
            status = CCA_STATUS_FAIL;
            break;
        case PROV_CCA_MEM_FULL:
            status = CCA_STATUS_MEMFULL;

            break;
        default:
            ASSERT(0);
    }
    mmi_prov_cca_invalid_setting_ind_req(status);

}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */ /* #if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__) */
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* _JPROVCCAHANDLER_C */ /* _JPROVOMA_C */

