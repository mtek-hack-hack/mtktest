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
 * JParserHandler.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file helps in parsing
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JPARSERHANDLER_H
#define _JPARSERHANDLER_H

#include "MMI_features.h"
#include "ddl.h"
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include <jcal.h>
#include "dmemory.h"
#include "jdi_WBXML.h"

#include "xmlchunk.h"
#include "wbxmlchunk.h"
#include "wbxml_info.h"
#include "wbxml_info.h"

#ifdef NOT_REQUIRED
#define JATAAYU_CCA_NOT_REQUIRED
#endif 

#define MMI_PROV_TAGS_MIN                    PROV_TAGS_MIN
#define MMI_PROV_TAGS_MAX                    PROV_TAGS_MAX
#define MMI_PROV_TAG_DESC                    PROV_TAG_DESC

#define MMI_PROV_NOKIA_TAGS_MIN                 NOKIA_PROV_TAGS_MIN
#define MMI_PROV_NOKIA_TAGS_MAX                 NOKIA_PROV_TAGS_MAX
#define MMI_PROV_NOKIA_TAG_DESC                 NOKIA_PROV_TAG_DESC

#define MMI_PROV_SATTR_MIN                   PROV_SATTR_MIN
#define MMI_PROV_SATTR_MAX                   PROV_SATTR_MAX

#define MMI_PROV_OMA_SATTR_MIN                     OMA_PROV_SATTR_MIN
#define MMI_PROV_OMA_SATTR_MAX                     OMA_PROV_SATTR_MAX

#define MMI_PROV_WAP_SWITCH_PAGE             WAP_PROV_SWITCH_PAGE
#define MMI_PROV_SATTR_DESC                     PROV_SATTR_DESC
#define MMI_PROV_OMA_SWITCH_PAGE             OMA_PROV_SWITCH_PAGE
#define MMI_PROV_OMA_SATTR_DESC                 OMA_PROV_SATTR_DESC
#define MMI_PROV_VATTR_MIN                   PROV_VATTR_MIN
#define MMI_PROV_VATTR_MAX                   PROV_VATTR_MAX
#define MMI_PROV_VATTR_DESC                     PROV_VATTR_DESC
#define MMI_PROV_OMA_VATTR_DESC                 OMA_PROV_VATTR_DESC

#define MMI_PROV_NOKIA_SATTR_MIN             NOKIA_PROV_SATTR_MIN
#define MMI_PROV_NOKIA_SATTR_MAX             NOKIA_PROV_SATTR_MAX
#define MMI_PROV_NOKIA_SATTR_DESC               NOKIA_PROV_SATTR_DESC

#ifdef JATAAYU_CCA_NOT_REQUIRED

#define MMI_PROV_NOKIA_VATTR_MIN             NOKIA_PROV_VATTR_MIN
#define MMI_PROV_NOKIA_VATTR_MAX             NOKIA_PROV_VATTR_MAX
#define MMI_PROV_NOKIA_VATTR_DESC               NOKIA_PROV_VATTR_DESC

#endif /* JATAAYU_CCA_NOT_REQUIRED */ 

#else /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 

#define     INVALID_WBXML_VALUE              -1

extern const JC_INT8 *ch_tags[];
extern const JC_INT8 *ch_start_attributes[];
extern const JC_INT8 *co_tags[];
extern const JC_INT8 *co_start_attributes[];
extern const JC_INT8 *prov_tags[];
extern const JC_INT8 *prov_start_attributes[];
extern const JC_INT8 *prov_value_attributes[];
extern const JC_INT8 *si_tags[];
extern const JC_INT8 *si_start_attributes[];
extern const JC_INT8 *sl_tags[];
extern const JC_INT8 *sl_start_attributes[];
extern const JC_INT8 *wbxml_value_attributes[];
extern const JC_INT8 *wml_tags[];
extern const JC_INT8 *wml_start_attributes[];

#ifdef WML_NO_CLOSURES
/* No closure tags */
extern JC_INT32 wml_no_closure_tags[];
#endif /* WML_NO_CLOSURES */ 
extern const JC_INT8 *WML_VAR_CONVERSION[];
extern const JC_INT8 *wta_wml_tags[];

// #ifdef PROPRIETARY_PROVISIONING_WBXML_EXT

extern const JC_INT8 *nokia_prov_tags[];
extern const JC_INT8 *nokia_prov_start_attributes[];

#ifdef JATAAYU_CCA_NOT_REQUIRED
extern const JC_INT8 *nokia_prov_value_attributes[];
#endif 
// #endif /* PROPRIETARY_PROVISIONING_WBXML_EXT */

extern const JC_INT8 *pacOmaProvStartAttributes[];
extern const JC_INT8 *pacOmaProvValueAttributes[];

#define CHT_CHANNEL                 0x05
#define CHT_TITLE                 0x06
#define CHT_ABSTRACT              0x07
#define CHT_RESOURCE               0x08

/* Attribute start tokens */

#define CHS_MAXSPACE             0x05
#define CHS_BASE                 0x06
#define CHS_HREF                 0x07
#define CHS_HREF_HTTP               0x08
#define CHS_HREF_HTTPS              0x09
#define CHS_LASTMOD                 0x0A
#define CHS_ETAG                    0x0B
#define CHS_MDT                           0x0C
#define CHS_SUCCESS                    0x0D
#define CHS_SUCCESS_HTTP                  0x0E
#define CHS_SUCCESS_HTTPS              0x0F
#define CHS_FAILURE                 0x10
#define CHS_FAILURE_HTTP            0x11
#define CHS_FAILURE_HTTPS           0x12
#define CHS_EVENTID                 0x13
#define CHS_EVENTID_WTAEV           0x14
#define CHS_CHANNELID               0x15
#define CHS_USERACCESSIBLE          0x16

#define CH_TAGS_MIN CHT_CHANNEL
#define CH_TAGS_MAX CHT_RESOURCE

#define CH_TAG_DESC(a) (((a>=CH_TAGS_MIN)&&(a<=CH_TAGS_MAX))?ch_tags[(a-CH_TAGS_MIN)]:NULL)

#define CH_SATTR_MIN CHS_MAXSPACE
#define CH_SATTR_MAX CHS_USERACCESSIBLE

#define CH_SATTR_DESC(a) (((a>=CH_SATTR_MIN)&&(a<=CH_SATTR_MAX))?ch_start_attributes[(a-CH_SATTR_MIN)]:NULL)

/* Tag tokens */
#define MMI_PROV_WAP_SWITCH_PAGE              0x00
#define MMI_PROV_OMA_SWITCH_PAGE              0x01

#define PROVT_WAP_PROVISIONING_DOC           0x05
#define PROVT_CHARACTERISTIC              0x06
#define PROVT_PARM                        0x07

/* Attribute start tokens */

#define PROVS_NAME                        0x05
#define PROVS_VALUE                       0x06
#define PROVS_NAME_NAME                   0x07
#define PROVS_NAME_NAP_ADDRESS               0x08
#define PROVS_NAME_NAP_ADDRTYPE              0x09
#define PROVS_NAME_CALLTYPE                     0x0A
#define PROVS_NAME_VALIDUNTILE               0x0B
#define PROVS_NAME_AUTHTYPE                     0x0C
#define PROVS_NAME_AUTHNAME                     0x0D
#define PROVS_NAME_AUTHSECRET                   0x0E
#define PROVS_NAME_LINGER                    0x0F
#define PROVS_NAME_BEARER                 0x10
#define PROVS_NAME_NAPID                  0x11
#define PROVS_NAME_COUNTRY                0x12
#define PROVS_NAME_NETWORK                0x13
#define PROVS_NAME_INTERNET                  0x14
#define PROVS_NAME_PROXY_ID                  0x15
#define PROVS_NAME_PROXY_PROVIDER_ID         0x16
#define PROVS_NAME_DOMAIN                 0x17
#define PROVS_NAME_PROVURL                0x18
#define PROVS_NAME_PXAUTH_TYPE               0x19
#define PROVS_NAME_PXAUTH_ID              0x1A
#define PROVS_NAME_PXAUTH_PW              0x1B
#define PROVS_NAME_STARTPAGE              0x1C
#define PROVS_NAME_BASAUTH_ID             0x1D
#define PROVS_NAME_BASAUTH_PW             0x1E
#define  PROVS_NAME_PUSHENABLED              0x1F
#define PROVS_NAME_PXADDR                 0x20
#define PROVS_NAME_PXADDRTYPE             0x21
#define PROVS_NAME_TO_NAPID                  0x22
#define PROVS_NAME_PORTNBR                0x23
#define PROVS_NAME_SERVICE                0x24
#define PROVS_NAME_LINKSPEED              0x25
#define PROVS_NAME_DNLINKSPEED               0x26
#define PROVS_NAME_LOCAL_ADDR             0x27
#define PROVS_NAME_LOCAL_ADDR_TYPE           0x28
#define PROVS_NAME_CONTEXT_ALLOW          0x29
#define PROVS_NAME_TRUST                  0x2A
#define PROVS_NAME_MASTER                 0x2B
#define PROVS_NAME_SID                    0x2C
#define PROVS_NAME_SOC                    0x2D
#define PROVS_NAME_WSP_VERSION               0x2E
#define PROVS_NAME_PHYSICAL_PROXY_ID         0x2F
#define PROVS_NAME_CLIENT_ID              0x30
#define PROVS_NAME_DELIVERY_ERR_SDU          0x31
#define PROVS_NAME_DELIVERY_ORDER            0x32
#define PROVS_NAME_TRAFFIC_CLASS          0x33
#define PROVS_NAME_MAX_SDU_SIZE              0x34
#define PROVS_NAME_MAX_BITRATE_UPLINK        0x35
#define PROVS_NAME_MAX_BITRATE_DNLINK        0x36
#define PROVS_NAME_RESIDUAL_BER              0x37
#define PROVS_NAME_SDU_ERROR_RATIO           0x38
#define PROVS_NAME_TRAFFIC_HANDL_PRIO        0x39
#define PROVS_NAME_TRANSFER_DELAY            0x3A
#define PROVS_NAME_GUARANTEED_BITRATE_UPLINK 0x3B
#define PROVS_NAME_GUARANTEED_BITRATE_DNLINK 0x3C

#define PROVS_VERSION                     0x45
#define PROVS_VERSION_1_0                 0x46

#define PROVS_TYPE                        0x50
#define PROVS_TYPE_PXLOGICAL              0x51
#define PROVS_TYPE_PXPHYSICAL             0x52
#define PROVS_TYPE_PORT                   0x53
#define PROVS_TYPE_VALIDITY                  0x54
#define PROVS_TYPE_NAPDEF                 0x55
#define PROVS_TYPE_BOOTSTRAP              0x56
#define PROVS_TYPE_VENDORCONFIG              0x57
#define PROVS_TYPE_CLIENTIDENTITY            0x58
#define PROVS_TYPE_PXAUTHINFO             0x59
#define PROVS_TYPE_NAPAUTHINFO               0x5A
#define PROVS_TYPE_ACCESS                 0x5B

/******* Provisiong Parameter Token Values **************/

#define PROVA_IPV4                        0x85
#define PROVA_IPV6                        0x86
#define PROVA_E164                        0x87
#define PROVA_ALPHA                       0x88
#define PROVA_APN                      0x89
#define PROVA_SCODE                       0x8A
#define PROVA_TETRA_ITSI                  0x8B
#define PROVA_MAN                      0x8C

#define PROVA_ANALOG_MODEM                0x90
#define PROVA_V_120                       0x91
#define PROVA_V_110                       0x92
#define PROVA_X_31                        0x93
#define PROVA_BIT_TRANSPARENT             0x94
#define PROVA_DIRECT_ASYNCHRONOUS_DATA_SERVICE  0x95

#define PROVA_PAP                      0x9A
#define PROVA_CHAP                        0x9B
#define PROVA_HTTP_BASIC                  0x9C
#define PROVA_HTTP_DIGEST                 0x9D
#define PROVA_WTLS_SS                     0x9E

#define PROVA_GSM_USSD                    0xA2
#define PROVA_GSM_SMS                     0xA3
#define PROVA_ANSI_136_GUTS                  0xA4
#define PROVA_IS_95_CDMA_SMS              0xA5
#define PROVA_IS_95_CDMA_CSD              0xA6
#define PROVA_IS_95_CDMA_PACKET              0xA7
#define PROVA_ANSI_136_CSD                0xA8
#define PROVA_ANSI_136_GPRS                  0xA9
#define PROVA_GSM_CSD                     0xAA
#define PROVA_GSM_GPRS                    0xAB
#define PROVA_AMPS_CDPD                   0xAC
#define PROVA_PDC_CSD                     0xAD
#define PROVA_PDC_PACKET                  0xAE
#define PROVA_IDEN_SMS                    0xAF
#define PROVA_IDEN_CSD                    0xB0
#define PROVA_IDEN_PACKET                 0xB1
#define PROVA_FLEX_REFLEX                 0xB2
#define PROVA_PHS_SMS                     0xB3
#define PROVA_PHS_CSD                     0xB4
#define PROVA_TETRA_SDS                   0xB5
#define PROVA_TETRA_PACKET                0xB6
#define PROVA_ANSI_136_GHOST              0xB7
#define PROVA_MOBITEX_MPAK                0xB8

#define PROVA_AUTOBAUDING                 0xC5

#define PROVA_CL_WSP                   0xCA
#define PROVA_CO_WSP                   0xCB
#define PROVA_CL_SEC_WSP                  0xCC
#define PROVA_CO_SEC_WSP                  0xCD
#define PROVA_CL_SEC_WTA                  0xCE
#define PROVA_CO_SEC_WTA                  0xCF

#define PROVA_OTA_HTTP_TO                 0xD0
#define PROVA_OTA_HTTP_TLS_TO             0xD1
#define PROVA_OTA_HTTP_PO                 0xD2
#define PROVA_OTA_HTTP_TLS_PO             0xD3

#define MMI_PROV_TAGS_MIN      PROVT_WAP_PROVISIONING_DOC
#define MMI_PROV_TAGS_MAX      PROVT_PARM

#define MMI_PROV_TAG_DESC(a) (((a>=MMI_PROV_TAGS_MIN)&&(a<=MMI_PROV_TAGS_MAX))?prov_tags[(a-MMI_PROV_TAGS_MIN)]:NULL)

#define MMI_PROV_SATTR_MIN     PROVS_NAME
#define MMI_PROV_SATTR_MAX     PROVS_TYPE_ACCESS

#define MMI_PROV_SATTR_DESC(a) (((a>=MMI_PROV_SATTR_MIN)&&(a<=MMI_PROV_SATTR_MAX))?prov_start_attributes[(a-SL_SATTR_MIN)]:NULL)

#define MMI_PROV_VATTR_MIN     PROVA_IPV4
#define MMI_PROV_VATTR_MAX     PROVA_OTA_HTTP_TLS_PO

#define MMI_PROV_VATTR_DESC(a) (((a>=MMI_PROV_VATTR_MIN)&&(a<=MMI_PROV_VATTR_MAX))?prov_value_attributes[(a-MMI_PROV_VATTR_MIN)]:NULL)

/******* OMA Provisioning Parameter Token Values **************/

/* Tag tokens */

#define OMA_PROVT_CHARACTERISTIC          0x06
#define OMA_PROVT_PARM                    0x07

/* Attribute start tokens */

#define OMA_PROVS_NAME                    0x05
#define OMA_PROVS_VALUE                   0x06
#define OMA_PROVS_NAME_VALUE              0x07

#define OMA_PROVS_NAME_INTERNET              0x14

#define OMA_PROVS_NAME_STARTPAGE          0x1C

#define OMA_PROVS_NAME_TO_NAPID              0x22
#define OMA_PROVS_NAME_PORTNBR               0x23
#define OMA_PROVS_NAME_SERVICE               0x24

#define OMA_PROVS_NAME_AACCEPT               0x2E
#define OMA_PROVS_NAME_AAUTHDATA          0x2F
#define OMA_PROVS_NAME_AAUTHLEVEL            0x30
#define OMA_PROVS_NAME_AAUTHNAME          0x31
#define OMA_PROVS_NAME_AAUTHSECRET           0x32
#define OMA_PROVS_NAME_AAUTHTYPE          0x33
#define OMA_PROVS_NAME_ADDR                  0x34
#define OMA_PROVS_NAME_ADDRTYPE              0x35
#define OMA_PROVS_NAME_APPID              0x36
#define OMA_PROVS_NAME_APROTOCOL          0x37
#define OMA_PROVS_NAME_PROVIDER_ID           0x38
#define OMA_PROVS_NAME_TO_PROXY              0x39
#define OMA_PROVS_NAME_URI                0x3A
#define OMA_PROVS_NAME_RULE                  0x3B

#define OMA_PROVS_TYPE                    0x50

#define OMA_PROVS_TYPE_PORT                  0x53

#define OMA_PROVS_TYPE_APPLICATION           0x55
#define OMA_PROVS_TYPE_APPADDR               0x56
#define OMA_PROVS_TYPE_APPAUTH               0x57
#define OMA_PROVS_TYPE_CLIENTIDENTITY        0x58
#define OMA_PROVS_TYPE_RESOURCE              0x59

/* OMA Provisioning Parameter Token Values  */

#define OMA_PROVS_COMMA                   0x80
#define OMA_PROVS_HTTP_                   0x81
#define OMA_PROVS_BASIC                   0x82
#define OMA_PROVS_DIGEST                  0x83

#define OMA_PROVS_IPV6                    0x86
#define OMA_PROVS_E164                    0x87
#define OMA_PROVS_ALPHA                   0x88

#define OMA_PROVS_APPSRV                  0x8D
#define OMA_PROVS_OBEX                    0x8E

#define OMA_PROVS_CL_WSP                  0xCA
#define OMA_PROVS_CO_WSP                  0xCB
#define OMA_PROVS_CL_SEC_WSP              0xCC
#define OMA_PROVS_CO_SEC_WSP              0xCD
#define OMA_PROVS_CL_SEC_WTA              0xCE
#define OMA_PROVS_CO_SEC_WTA              0xCF

#define OMA_PROV_TAGS_MIN                 OMA_PROVT_CHARACTERISTIC
#define OMA_PROV_TAGS_MAX                 OMA_PROVT_PARM
#define MMI_PROV_OMA_SATTR_MIN                OMA_PROVS_NAME
#define MMI_PROV_OMA_SATTR_MAX                OMA_PROVS_TYPE_RESOURCE
#define OMA_PROV_VATTR_MIN                OMA_PROVS_COMMA
#define OMA_PROV_VATTR_MAX                OMA_PROVS_CO_SEC_WTA

#define MMI_PROV_OMA_SATTR_DESC(a) (((a>=MMI_PROV_OMA_SATTR_MIN)&&(a<=MMI_PROV_OMA_SATTR_MAX))?pacOmaProvStartAttributes[(a-MMI_PROV_OMA_SATTR_MIN)]:NULL)

#define MMI_PROV_OMA_VATTR_DESC(a) (((a>=OMA_PROV_VATTR_MIN)&&(a<=OMA_PROV_VATTR_MAX))?pacOmaProvValueAttributes[(a-OMA_PROV_VATTR_MIN)]:NULL)

/* Tag tokens */

#define COT_CO                   0x05
#define COT_INVALIDATE_OBJECT        0x06
#define COT_INVALIDATE_SERVICE          0x07

/* Attribute start tokens */

#define COS_URI                        0x05
#define COS_URI_HTTP                   0x06
#define COS_URI_HTTP_WWW               0x07
#define COS_URI_HTTPS                  0x08
#define COS_URI_HTTPS_WWW               0x09

#define CO_TAGS_MIN COT_CO
#define CO_TAGS_MAX COT_INVALIDATE_SERVICE

#define CO_TAG_DESC(a) (((a>=CO_TAGS_MIN)&&(a<=CO_TAGS_MAX))?co_tags[(a-CO_TAGS_MIN)]:NULL)

#define CO_SATTR_MIN COS_URI
#define CO_SATTR_MAX COS_URI_HTTPS_WWW

#define CO_SATTR_DESC(a) (((a>=CO_SATTR_MIN)&&(a<=CO_SATTR_MAX))?co_start_attributes[(a-CO_SATTR_MIN)]:NULL)

/* Tag tokens */

#define SIT_SI             0x05
#define SIT_INDICAITON      0x06
#define SIT_INFO         0x07
#define SIT_ITEM          0x08

/* Attribute start tokens */

#define SIS_ACTION_SIGNAL_NONE         0x05
#define SIS_ACTION_SIGNAL_LOW       0x06
#define SIS_ACTION_SIGNAL_MEDIUM    0x07
#define SIS_ACTION_SIGNAL_HIGH         0x08
#define SIS_ACTION_DELETE           0x09
#define SIS_CREATED                 0x0A
#define SIS_HREF                    0x0B
#define SIS_HREF_HTTP                  0x0C
#define SIS_HREF_HTTP_WWW                 0x0D
#define SIS_HREF_HTTPS                 0x0E
#define SIS_HREF_HTTPS_WWW              0x0F
#define SIS_SI_EXPIRES              0x10
#define SIS_SI_ID                0x11
#define SIS_CLASS                0x12

#define SI_TAGS_MIN SIT_SI
#define SI_TAGS_MAX SIT_ITEM

#define SI_TAG_DESC(a) (((a>=SI_TAGS_MIN)&&(a<=SI_TAGS_MAX))?si_tags[(a-SI_TAGS_MIN)]:NULL)

#define SI_SATTR_MIN SIS_ACTION_SIGNAL_NONE
#define SI_SATTR_MAX SIS_CLASS

#define SI_SATTR_DESC(a) (((a>=SI_SATTR_MIN)&&(a<=SI_SATTR_MAX))?si_start_attributes[(a-SI_SATTR_MIN)]:NULL)

/* Tag tokens */

#define SLT_SL             0x05

/* Attribute start tokens */

#define SLS_ACTION_EXECUTE_LOW         0x05
#define SLS_ACTION_EXECUTE_HIGH        0x06
#define SLS_ACTION_CACHE            0x07
#define SLS_HREF                    0x08
#define SLS_HREF_HTTP                  0x09
#define SLS_HREF_HTTP_WWW                 0x0A
#define SLS_HREF_HTTPS                 0x0B
#define SLS_HREF_HTTPS_WWW              0x0C

#define SL_TAGS_MIN SLT_SL
#define SL_TAGS_MAX SLT_SL

#define SL_TAG_DESC(a) (((a>=SL_TAGS_MIN)&&(a<=SL_TAGS_MAX))?sl_tags[(a-SL_TAGS_MIN)]:NULL)

#define SL_SATTR_MIN SLS_ACTION_EXECUTE_LOW
#define SL_SATTR_MAX SLS_HREF_HTTPS_WWW

#define SL_SATTR_DESC(a) (((a>=SL_SATTR_MIN)&&(a<=SL_SATTR_MAX))?sl_start_attributes[(a-SL_SATTR_MIN)]:NULL)

/* Tag tokens */

#define WTA_WMLT_WML                      0x3F

/* Attribute start tokens */

#define WTA_WMLS_HREF_WTAI                0x05
#define WTA_WMLS_HREF_WTAI_WP_MC          0x06
#define WTA_WMLS_HREF_WTAI_WP_SD          0x07
#define WTA_WMLS_HREF_WTAI_WP_AP          0x08
#define WTA_WMLS_HREF_WTAI_MS_EC          0x09

#define WTA_WMLS_WTAEV                    0x10
#define WTA_WMLS_WTAEV_CC                 0x11
#define WTA_WMLS_WTAEV_CC_IC              0x12
#define WTA_WMLS_WTAEV_CC_CL              0x13
#define WTA_WMLS_WTAEV_CC_CO              0x14
#define WTA_WMLS_WTAEV_CC_OC              0x15
#define WTA_WMLS_WTAEV_CC_CC              0x16
#define WTA_WMLS_WTAEV_CC_DTMF               0x17

#define WTA_WMLS_WTAEV_NT                 0x20
#define WTA_WMLS_WTAEV_NT_IT              0x21
#define WTA_WMLS_WTAEV_NT_ST              0x22

#define WTA_WMLS_WTAEV_PB                 0x30
#define WTA_WMLS_WTAEV_LG                 0x38
#define WTA_WMLS_WTAEV_MS                 0x50
#define WTA_WMLS_WTAEV_MS_NS              0x51
#define WTA_WMLS_WTAEV_GSM                0x58
#define WTA_WMLS_WTAEV_GSM_RU             0x59
#define WTA_WMLS_WTAEV_GSM_CH             0x5A
#define WTA_WMLS_WTAEV_GSM_CA             0x5B

#define WTA_WMLS_WTAEV_PDC                0x60
#define WTA_WMLS_WTAEV_ANSI136               0x68
#define WTA_WMLS_WTAEV_ANSI136_IA            0x69
#define WTA_WMLS_WTAEV_ANSI136_IF            0x6A

#define WTA_WMLS_WTAEV_CDMA                  0x70

#define WTA_WML_TAGS_MIN WTA_WMLT_WML
#define WTA_WML_TAGS_MAX WTA_WMLT_WML

#define WTA_WML_TAG_DESC(a) (((a>=WTA_WML_TAGS_MIN)&&(a<=WTA_WML_TAGS_MAX))?wta_wml_tags[(a-WTA_WML_TAGS_MIN)]:NULL)

#define WTA_WML_SATTR_MIN WTA_WMLS_HREF_WTAI
#define WTA_WML_SATTR_MAX WTA_WMLS_WTAEV_CDMA

#define WTA_WML_SATTR_DESC wta_wml_sattr_desc

/* Tag tokens */

#define WMLT_PRE     0x1B
#define WMLT_A          0x1C
#define WMLT_ANCHOR     0x22
#define WMLT_ACCESS     0x23
#define WMLT_B          0x24
#define WMLT_BIG        0x25
#define WMLT_BR         0x26
#define WMLT_CARD       0x27
#define WMLT_DO         0x28
#define WMLT_EM         0x29
#define WMLT_FIELDSET   0x2A
#define WMLT_GO         0x2B
#define WMLT_HEAD       0x2C
#define WMLT_I          0x2D
#define WMLT_IMG        0x2E
#define WMLT_INPUT      0x2F
#define WMLT_META       0x30
#define WMLT_NOOP       0x31
#define WMLT_P          0x20
#define WMLT_POSTFIELD  0x21
#define WMLT_PREV       0x32
#define WMLT_ONEVENT    0x33
#define WMLT_OPTGROUP   0x34
#define WMLT_OPTION     0x35
#define WMLT_REFRESH    0x36
#define WMLT_SELECT     0x37
#define WMLT_SETVAR     0x3E
#define WMLT_SMALL      0x38
#define WMLT_STRONG     0x39
#define WMLT_TABLE      0x1F
#define WMLT_TD         0x1D
#define WMLT_TEMPLATE   0x3B
#define WMLT_TIMER      0x3C
#define WMLT_TR         0x1E
#define WMLT_U          0x3D
#define WMLT_WML        0x3F

/* Attribute start tokens */

#define WMLS_ACCEPT_CHARSET          0x05
#define WMLS_ALIGN                   0x52
#define WMLS_ALIGN_BOTTOM            0x06
#define WMLS_ALIGN_CENTER            0x07
#define WMLS_ALIGN_MIDDLE            0x08
#define WMLS_ALIGN_RIGHT             0x0A
#define WMLS_ALIGN_TOP               0x0B
#define WMLS_ALT                     0x0C
#define WMLS_CLASS                   0x54
#define WMLS_COLUMNS                 0x53
#define WMLS_CONTENT                 0x0D
#define WMLS_CONTENT_WMLC            0x5C
#define WMLS_DOMAIN                  0x0F
#define WMLS_EMPTYOK_FALSE           0x10
#define WMLS_EMPTYOK_TRUE            0x11
#define WMLS_FORMAT                  0x12
#define WMLS_FORUA_FALSE             0x56
#define WMLS_FORUA_TRUE              0x57
#define WMLS_HEIGHT                  0x13
#define WMLS_HREF                    0x4A
#define WMLS_HREF_HTTP               0x4B
#define WMLS_HREF_HTTPS              0x4C
#define WMLS_HSPACE                  0x14
#define WMLS_HTTP_EQUIV              0x5A
#define WMLS_HTTP_EQUIV_CONTENT_TYPE 0x5B
#define WMLS_HTTP_EQUIV_EXPIRES      0x5D
#define WMLS_ID                      0x55
#define WMLS_IVALUE                  0x15
#define WMLS_INAME                   0x16
#define WMLS_LABEL                   0x18
#define WMLS_LOCALSRC                0x19
#define WMLS_MAXLENGTH               0x1A
#define WMLS_METHOD_GET              0x1B
#define WMLS_METHOD_POST             0x1C
#define WMLS_MODE_NOWRAP             0x1D
#define WMLS_MODE_WRAP               0x1E
#define WMLS_MULTIPLE_FALSE          0x1F
#define WMLS_MULTIPLE_TRUE           0x20
#define WMLS_NAME                    0x21
#define WMLS_NEWCONTEXT_FALSE        0x22
#define WMLS_NEWCONTEXT_TRUE         0x23
#define WMLS_ONENTERBACKWARD         0x25
#define WMLS_ONENTERFORWARD          0x26
#define WMLS_ONPICK                  0x24
#define WMLS_ONTIMER                 0x27
#define WMLS_OPTIONAL_FALSE          0x28
#define WMLS_OPTIONAL_TRUE           0x29
#define WMLS_PATH                    0x2A
#define WMLS_SCHEME                  0x2E
#define WMLS_SENDREFERER_FALSE       0x2F
#define WMLS_SENDREFERER_TRUE        0x30
#define WMLS_SIZE                    0x31
#define WMLS_SRC                     0x32
#define WMLS_SRC_HTTP                0x58
#define WMLS_SRC_HTTPS               0x59
#define WMLS_ORDERED_TRUE            0x33
#define WMLS_ORDERED_FALSE           0x34
#define WMLS_TABINDEX                0x35
#define WMLS_TITLE                   0x36
#define WMLS_TYPE                    0x37
#define WMLS_TYPE_ACCEPT             0x38
#define WMLS_TYPE_DELETE             0x39
#define WMLS_TYPE_HELP               0x3A
#define WMLS_TYPE_PASSWORD           0x3B
#define WMLS_TYPE_ONPICK             0x3C
#define WMLS_TYPE_ONENTERBACKWARD    0x3D
#define WMLS_TYPE_ONENTERFORWARD     0x3E
#define WMLS_TYPE_ONTIMER            0x3F
#define WMLS_TYPE_PREV               0x46
#define WMLS_TYPE_RESET              0x47
#define WMLS_TYPE_TEXT               0x48
#define WMLS_TYPE_VND                0x49
#define WMLS_VALUE                   0x4D
#define WMLS_VSPACE                  0x4E
#define WMLS_WIDTH                   0x4F
#define WMLS_XML_LANG                0x50
#define WMLS_ACCESS_KEY           0x5E
#define WMLS_ENCTYPE           0x5F
#define WMLS_ENCTYPE_URLENCODING  0x60
#define WMLS_ENCTYPE_FORM_DATA       0x61
#define WMLS_XML_SPACE_PRESERVE      0x62
#define WMLS_XML_SPACE_DEFAULT       0x63
#define WMLS_CACHE_CONTROL_NO_CACHE  0x64

// #define WML_TAGS_MIN WMLT_A
#define WML_TAGS_MIN WMLT_PRE
#define WML_TAGS_MAX WMLT_WML

#define WML_TAG_DESC(a) (((a>=WML_TAGS_MIN)&&(a<=WML_TAGS_MAX))?wml_tags[(a-WML_TAGS_MIN)]:NULL)

#define WML_SATTR_MIN WMLS_ACCEPT_CHARSET
#define WML_SATTR_MAX WMLS_CACHE_CONTROL_NO_CACHE

#define WML_SATTR_DESC(a) (((a>=WML_SATTR_MIN)&&(a<=WML_SATTR_MAX))?wml_start_attributes[(a-WML_SATTR_MIN)]:NULL)

#define  WBXML_SWITCH_PAGE          0x00
#define     WBXML_INLINE_STRING_END       0x00
#define     WBXML_END                  0x01
#define  WBXML_ENTITY               0x02
#define     WBXML_INLINE_STRING           0x03
#define  WBXML_LITERAL              0x04
#define     WBXML_EXT_I_0              0x40
#define     WBXML_EXT_I_1              0x41
#define     WBXML_EXT_I_2              0x42
#define     WBXML_PI                0x43
#define     WBXML_EXT_T_0              0x80
#define     WBXML_EXT_T_1              0x81
#define     WBXML_EXT_T_2              0x82
#define  WBXML_STR_T                0x83
#define     WBXML_OPAQUE               0xC3

#define     WBXML_CONTENT              0x40
#define  WBXML_ATTRIBUTES           0x80
#define     WBXML_TAG_VALUE               (~(WBXML_ATTRIBUTES | WBXML_CONTENT))

/*************************** DTD  *********************************/

#define     WML_1_0                    0x02
/**** WTA 1.0 has been deprecated by WAP Forum ******/
#define  WTA_1_0                    0x03
#define     WML_1_1                    0x04
#define     SI_1_0                     0x05
#define     SL_1_0                     0x06
#define     CO_1_0                     0x07
#define     CHANNEL_1_1                0x08
#define     WML_1_2                    0x09
#define     WML_1_3                    0x0A
#define     PROVISIONING_1_0           0x0B
#define     WTA_WML_1_2                0x0C
#define     CHANNEL_1_2                0x0D

#define  WML_SWITCH_PAGE               0x00
#define  WTA_SWITCH_PAGE               0x01

/* Charset */
#define     UTF_8                   0x6A

/* Attribute value tokens */

#define WBXMLA_COM              0x85
#define WBXMLA_EDU              0x86
#define WBXMLA_NET              0x87
#define WBXMLA_ORG              0x88
#define WBXMLA_ACCEPT           0x89
#define WBXMLA_BOTTOM           0x8A
#define WBXMLA_CLEAR            0x8B
#define WBXMLA_DELETE           0x8C
#define WBXMLA_HELP             0x8D
#define WBXMLA_HTTP             0x8E
#define WBXMLA_HTTP_WWW         0x8F
#define WBXMLA_HTTPS            0x90
#define WBXMLA_HTTPS_WWW        0x91
#define WBXMLA_MIDDLE           0x93
#define WBXMLA_NOWRAP           0x94
#define WBXMLA_ONENTERBACKWARD  0x96
#define WBXMLA_ONENTERFORWARD   0x97
#define WBXMLA_ONPICK           0x95
#define WBXMLA_ONTIMER          0x98
#define WBXMLA_OPTIONS          0x99
#define WBXMLA_PASSWORD         0x9A
#define WBXMLA_RESET            0x9B
#define WBXMLA_TEXT             0x9D
#define WBXMLA_TOP              0x9E
#define WBXMLA_UNKNOWN          0x9F
#define WBXMLA_WRAP             0xA0
#define WBXMLA_WWW              0xA1

#define WBXML_VATTR_MIN WBXMLA_COM
#define WBXML_VATTR_MAX WBXMLA_WWW

#define WBXML_VATTR_DESC(a) (((a>=WBXML_VATTR_MIN)&&(a<=WBXML_VATTR_MAX))?wbxml_value_attributes[(a-WBXML_VATTR_MIN)]:NULL)

#define MAX_ATTRIBUTE_VALUE            1024
#define INLINE_ATTRIB               "inline"

// #ifdef PROPRIETARY_PROVISIONING_WBXML_EXT

#define NOKIA_UNKNOWN_IDENTIFIER             0x01

#define NOKIA_PROVT_CHARACTERISTICLIST          0x05

/* NOKIA Tag tokens */
#define NOKIA_PROVT_CHARACTERISTIC              0x06
#define NOKIA_PROVT_PARM                     0x07

/* NOKIA Attribute start tokens */

#define NOKIA_PROVS_TYPE_ADDRESS             0x06
#define NOKIA_PROVS_TYPE_URL                 0x07
#define NOKIA_PROVS_TYPE_NAME                0x08
#define NOKIA_PROVS_TYPE_MMSURL                 0x7C
#define NOKIA_PROVS_TYPE_ID                     0x7D
#define NOKIA_PROVS_TYPE_BOOKMARK               0x7F

#define NOKIA_PROVS_NAME                     0x10
#define NOKIA_PROVS_NAME_VALUE                  0x11
#define NOKIA_PROVS_NAME_BEARER                 0X12
#define NOKIA_PROVS_NAME_PROXY                  0X13
#define NOKIA_PROVS_NAME_PORT                0X14
#define NOKIA_PROVS_NAME_NAME                0X15
#define NOKIA_PROVS_NAME_PROXY_TYPE             0X16
#define NOKIA_PROVS_NAME_URL                 0X17
#define NOKIA_PROVS_NAME_PROXY_AUTHNAME            0X18
#define NOKIA_PROVS_NAME_PROXY_AUTHSECRET       0X19
#define NOKIA_PROVS_NAME_SMS_SMSC_ADDRESS       0X1A
#define NOKIA_PROVS_NAME_USSD_SERVICE_CODE         0X1B
#define NOKIA_PROVS_NAME_GPRS_ACCESSPOINTNAME      0X1C
#define NOKIA_PROVS_NAME_PPP_LOGINTYPE          0x1D
#define NOKIA_PROVS_NAME_PROXY_LOGINTYPE        0x1E
#define NOKIA_PROVS_NAME_CSD_DIALSTRING            0x21
#define NOKIA_PROVS_NAME_CSD_CALLTYPE           0x28
#define NOKIA_PROVS_NAME_CSD_CALLSPEED          0X29
#define NOKIA_PROVS_NAME_PPP_AUTHTYPE           0x22
#define NOKIA_PROVS_NAME_PPP_AUTHNAME           0x23
#define NOKIA_PROVS_NAME_PPP_AUTHSECRET            0x24
#define NOKIA_PROVS_NAME_ISP_NAME               0x7E

/******* NOKIA Provisiong Parameter Token Values **************/
#define NOKIA_PROVA_GSM_CSD                     0x45
#define NOKIA_PROVA_GSM_SMS                     0x46
#define NOKIA_PROVA_GSM_USSD                 0x47
#define NOKIA_PROVA_IS_136_CSD                  0x48
#define NOKIA_PROVA_GPRS                     0x49
#define NOKIA_PROVA_9200                     0x60
#define NOKIA_PROVA_9201                     0x61
#define NOKIA_PROVA_9202                     0x62
#define NOKIA_PROVA_9203                     0x63
#define NOKIA_PROVA_AUTOMATIC                0x64
#define NOKIA_PROVA_MANUAL                   0x65
#define NOKIA_PROVA_AUTO                     0x6A
#define NOKIA_PROVA_9600                     0x6B
#define NOKIA_PROVA_14400                    0x6C
#define NOKIA_PROVA_19200                    0x6D
#define NOKIA_PROVA_28800                    0x6E
#define NOKIA_PROVA_38400                    0x6F
#define NOKIA_PROVA_PAP                      0x70
#define NOKIA_PROVA_CHAP                     0x71
#define NOKIA_PROVA_ANALOGUE                 0x72
#define NOKIA_PROVA_ISDN                     0x73
#define NOKIA_PROVA_43200                    0x74
#define NOKIA_PROVA_57600                    0x75
#define NOKIA_PROVA_MSISDN_NO                0x76
#define NOKIA_PROVA_IPV4                     0x77
#define NOKIA_PROVA_MS_CHAP                     0x78

#define MMI_PROV_NOKIA_TAGS_MIN      NOKIA_PROVT_CHARACTERISTICLIST
#define MMI_PROV_NOKIA_TAGS_MAX      NOKIA_PROVT_PARM

#define MMI_PROV_NOKIA_TAG_DESC(a) (((a>=MMI_PROV_NOKIA_TAGS_MIN)&&(a<=MMI_PROV_NOKIA_TAGS_MAX))?nokia_prov_tags[(a-MMI_PROV_NOKIA_TAGS_MIN)]:NULL)

#define MMI_PROV_NOKIA_SATTR_MIN  NOKIA_PROVS_TYPE_ADDRESS
#define MMI_PROV_NOKIA_SATTR_MAX  NOKIA_PROVS_TYPE_BOOKMARK

#define MMI_PROV_NOKIA_SATTR_DESC(a) (((a>=MMI_PROV_NOKIA_SATTR_MIN)&&(a<=MMI_PROV_NOKIA_SATTR_MAX))?nokia_prov_start_attributes[(a-MMI_PROV_NOKIA_SATTR_MIN)]:NULL)

#ifdef JATAAYU_CCA_NOT_REQUIRED
#define MMI_PROV_NOKIA_VATTR_MIN     NOKIA_PROVA_GSM_CSD
#define MMI_PROV_NOKIA_VATTR_MAX     NOKIA_PROVA_MS_CHAP

#define MMI_PROV_NOKIA_VATTR_DESC(a) (((a>=MMI_PROV_NOKIA_VATTR_MIN)&&(a<=MMI_PROV_NOKIA_VATTR_MAX))?nokia_prov_value_attributes[(a-MMI_PROV_NOKIA_VATTR_MIN)]:NULL)
#endif /* JATAAYU_CCA_NOT_REQUIRED */ 

#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* _JPARSERHANDLER_H */ /* _JPROVOMA_C */

