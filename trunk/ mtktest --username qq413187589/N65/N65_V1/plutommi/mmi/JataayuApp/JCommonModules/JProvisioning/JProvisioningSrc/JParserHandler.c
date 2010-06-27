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
 * JParserHandler.c
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
#include "MMI_include.h"
#ifndef _JPARSERHANDLER_C
#define _JPARSERHANDLER_C

#include "ddl.h"
#ifdef __MMI_JATAAYU_CCA_SUPPORT__
#ifndef JATAAYU_SUPPORT
#include "JParserHandler.h"

const JC_INT8 *ch_tags[(CH_TAGS_MAX - CH_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "channel",
    /* 0x06 */ "title",
    /* 0x07 */ "abstract",
    /* 0x08 */ "resource"
};

const JC_INT8 *ch_start_attributes[(CH_SATTR_MAX - CH_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "maxspace",
    /* 0x06 */ "base",
    /* 0x07 */ "href",
    /* 0x08 */ "href=\"http://",
    /* 0x09 */ "href=\"https://",
    /* 0x0A */ "lastmod",
    /* 0x0B */ "etag",
    /* 0x0C */ "md5",
    /* 0x0D */ "success",
    /* 0x0E */ "success=\"http://",
    /* 0x0F */ "success=\"https://",
    /* 0x10 */ "failure",
    /* 0x11 */ "failure=\"http://",
    /* 0x12 */ "failure=\"https://",
    /* 0x13 */ "eventid",
    /* 0x14 */ "eventid=\"wtaev-",
    /* 0x15 */ "channelid",
    /* 0x16 */ "useraccessible",
};

const JC_INT8 *co_tags[(CO_TAGS_MAX - CO_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "co",
    /* 0x06 */ "invalidate-object",
    /* 0x07 */ "invalidate-service",
};

const JC_INT8 *co_start_attributes[(CO_SATTR_MAX - CO_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "uri",
    /* 0x06 */ "uri=\"http://",
    /* 0x07 */ "uri=\"http://www.",
    /* 0x08 */ "uri=\"https://",
    /* 0x09 */ "uri=\"https://www.",
};

const JC_INT8 *prov_tags[(MMI_PROV_TAGS_MAX - MMI_PROV_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "wap-provisioningdoc",
    /* 0x06 */ "characteristic",
    /* 0x07 */ "parm"
};

const JC_INT8 *prov_start_attributes[(MMI_PROV_SATTR_MAX - MMI_PROV_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "name",
    /* 0x06 */ "value",
    /* 0x07 */ "name=\"NAME\"",
    /* 0x08 */ "name=\"NAP-ADDRESS\"",
    /* 0x09 */ "name=\"NAP-ADDRTYPE\"",
    /* 0x0A */ "name=\"CALLTYPE\"",
    /* 0x0B */ "name=\"VALIDUNTIL\"",
    /* 0x0C */ "name=\"AUTHTYPE\"",
    /* 0x0D */ "name=\"AUTHNAME\"",
    /* 0x0E */ "name=\"AUTHSECRET\"",
    /* 0x0F */ "name=\"LINGER\"",
    /* 0x10 */ "name=\"BEARER\"",
    /* 0x11 */ "name=\"NAPID\"",
    /* 0x12 */ "name=\"COUNTRY\"",
    /* 0x13 */ "name=\"NETWORK\"",
    /* 0x14 */ "name=\"INTERNET\"",
    /* 0x15 */ "name=\"PROXY-ID\"",
    /* 0x16 */ "name=\"PROXY-PROVIDER-ID\"",
    /* 0x17 */ "name=\"DOMAIN\"",
    /* 0x18 */ "name=\"PROVURL\"",
    /* 0x19 */ "name=\"PXAUTH-TYPE\"",
    /* 0x1A */ "name=\"PXAUTH-ID\"",
    /* 0x1B */ "name=\"PXAUTH-PW\"",
    /* 0x1C */ "name=\"STARTPAGE\"",
    /* 0x1D */ "name=\"BASAUTH-ID\"",
    /* 0x1E */ "name=\"BASAUTH-PW\"",
    /* 0x1F */ "name=\"PUSHENABLED\"",
    /* 0x20 */ "name=\"PXADDR\"",
    /* 0x21 */ "name=\"PXADDRTYPE\"",
    /* 0x22 */ "name=\"TO-NAPID\"",
    /* 0x23 */ "name=\"PORTNBR\"",
    /* 0x24 */ "name=\"SERVICE\"",
    /* 0x25 */ "name=\"LINKSPEED\"",
    /* 0x26 */ "name=\"DNLINKSPEED\"",
    /* 0x27 */ "name=\"LOCAL-ADDR\"",
    /* 0x28 */ "name=\"LOCAL-ADDRTYPE\"",
    /* 0x29 */ "name=\"CONTEXT-ALLOW\"",
    /* 0x2A */ "name=\"TRUST\"",
    /* 0x2B */ "name=\"MASTER\"",
    /* 0x2C */ "name=\"SID\"",
    /* 0x2D */ "name=\"SOC\"",
    /* 0x2E */ "name=\"WSP-VERSION\"",
    /* 0x2F */ "name=\"PHYSICAL-PROXY-ID\"",
    /* 0x30 */ "name=\"CLIENT-ID\"",
    /* 0x31 */ "name=\"DELIVERY-ERR-SDU\"",
    /* 0x32 */ "name=\"DELIVERY-ORDER\"",
    /* 0x33 */ "name=\"TRAFFIC-CLASS\"",
    /* 0x34 */ "name=\"MAX-SDU-SIZE\"",
    /* 0x35 */ "name=\"MAX-BITRATE-UPLINK\"",
    /* 0x36 */ "name=\"MAX-BITRATE-DNLINK\"",
    /* 0x37 */ "name=\"RESIDUAL-BER\"",
    /* 0x38 */ "name=\"SDU-ERROR-RATIO\"",
    /* 0x39 */ "name=\"TRAFFIC-HANDL-PRIO\"",
    /* 0x3A */ "name=\"TRANSFER-DELAY\"",
    /* 0x3B */ "name=\"GUARANTEED-BITRATE-UPLINK\"",
    /* 0x3C */ "name=\"GUARANTEED-BITRATE-DNLINK\"",
    /* 0x3D */ "name=\"PXADDR-FQDN\"",
    /* 0x3E */ "name=\"PROXY-PW\"",
    /* 0x3F */ "name=\"PPGAUTH-TYPE\"",
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ "version",
    /* 0x46 */ "version=\"1.0\"",
    /* 0x47 */ "name=\"PULLENABLED\"",
    /* 0x48 */ "name=\"DNS-ADDR\"",
    /* 0x49 */ "name=\"MAX-NUM-RETRY\"",
    /* 0x4A */ "name=\"FIRST-RETRY-TIMEOUT\"",
    /* 0x4B */ "name=\"REREG-THRESHOLD\"",
    /* 0x4C */ "name=\"T-BIT\"",
    /* 0x4D */ NULL,
    /* 0x4E */ "name=\"AUTH-ENTITY\"",
    /* 0x4F */ "name=\"SPI\"",
    /* 0x50 */ "type",
    /* 0x51 */ "type=\"PXLOGICAL\"",
    /* 0x52 */ "type=\"PXPHYSICAL\"",
    /* 0x53 */ "type=\"PORT\"",
    /* 0x54 */ "type=\"VALIDITY\"",
    /* 0x55 */ "type=\"NAPDEF\"",
    /* 0x56 */ "type=\"BOOTSTRAP\"",
    /* 0x57 */ "type=\"VENDORCONFIG\"",
    /* 0x58 */ "type=\"CLIENTIDENTITY\"",
    /* 0x59 */ "type=\"PXAUTHINFO\"",
    /* 0x5A */ "type=\"NAPAUTHINFO\"",
    /* 0x5B */ "type=\"ACCESS\"",
};

const JC_INT8 *prov_value_attributes[(MMI_PROV_VATTR_MAX - MMI_PROV_VATTR_MIN) + 1] = 
{
    /* 0x85 */ "IPV4",
    /* 0x86 */ "IPV6",
    /* 0x87 */ "E164",
    /* 0x88 */ "ALPHA",
    /* 0x89 */ "APN",
    /* 0x8A */ "SCODE",
    /* 0x8B */ "TETRA-ITSI",
    /* 0x8C */ "MAN",
    /* 0x8D */ NULL,
    /* 0x8E */ NULL,
    /* 0x8F */ NULL,
    /* 0x90 */ "ANALOG-MODEM",
    /* 0x91 */ "V.120",
    /* 0x92 */ "V.110",
    /* 0x93 */ "X.31",
    /* 0x94 */ "BIT-TRANSPARENT",
    /* 0x95 */ "DIRECT-ASYNCHRONOUS-DATA-SERVICE",
    /* 0x96 */ NULL,
    /* 0x97 */ NULL,
    /* 0x98 */ NULL,
    /* 0x99 */ NULL,
    /* 0x9A */ "PAP",
    /* 0x9B */ "CHAP",
    /* 0x9C */ "HTTP-BASIC",
    /* 0x9D */ "HTTP-DIGEST",
    /* 0x9E */ "WTLS-SS",
    /* 0x9F */ "MD5",
    /* 0xA0 */ NULL,
    /* 0xA1 */ NULL,
    /* 0xA2 */ "GSM-USSD",
    /* 0xA3 */ "GSM-SMS",
    /* 0xA4 */ "ANSI-136-GUTS",
    /* 0xA5 */ "IS-95-CDMA-SMS",
    /* 0xA6 */ "IS-95-CDMA-CSD",
    /* 0xA7 */ "IS-95-CDMA-PACKET",
    /* 0xA8 */ "ANSI-136-CSD",
    /* 0xA9 */ "ANSI-136-GPRS",
    /* 0xAA */ "GSM-CSD",
    /* 0xAB */ "GSM-GPRS",
    /* 0xAC */ "AMPS-CDPD",
    /* 0xAD */ "PDC-CSD",
    /* 0xAE */ "PDC-PACKET",
    /* 0xAF */ "IDEN-SMS",
    /* 0xB0 */ "IDEN-CSD",
    /* 0xB1 */ "IDEN-PACKET",
    /* 0xB2 */ "FLEX/REFLEX",
    /* 0xB3 */ "PHS-SMS",
    /* 0xB4 */ "PHS-CSD",
    /* 0xB5 */ "TETRA-SDS",
    /* 0xB6 */ "TETRA-PACKET",
    /* 0xB7 */ "ANSI-136-GHOST",
    /* 0xB8 */ "MOBITEX-MPAK",
    /* 0xB9 */ NULL,
    /* 0xBA */ NULL,
    /* 0xBB */ NULL,
    /* 0xBC */ NULL,
    /* 0xBD */ NULL,
    /* 0xBE */ NULL,
    /* 0xBF */ NULL,
    /* 0xC0 */ NULL,
    /* 0xC1 */ NULL,
    /* 0xC2 */ NULL,
    /* 0xC3 */ NULL,
    /* 0xC4 */ NULL,
    /* 0xC5 */ "AUTOBAUDING",
    /* 0xC6 */ NULL,
    /* 0xC7 */ NULL,
    /* 0xC8 */ NULL,
    /* 0xC9 */ NULL,
    /* 0xCA */ "CL-WSP",
    /* 0xCB */ "CO-WSP",
    /* 0xCC */ "CL-SEC-WSP",
    /* 0xCD */ "CO-SEC-WSP",
    /* 0xCE */ "CL-SEC-WTA",
    /* 0xCF */ "CO-SEC-WTA",
    /* 0xD0 */ "OTA-HTTP-TO",
    /* 0xD1 */ "OTA-HTTP-TLS-TO",
    /* 0xD2 */ "OTA-HTTP-PO",
    /* 0xD3 */ "OTA-HTTP-TLS-PO",
};

const JC_INT8 *si_tags[(SI_TAGS_MAX - SI_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "si",
    /* 0x06 */ "indication",
    /* 0x07 */ "info",
    /* 0x08 */ "item",
};

const JC_INT8 *si_start_attributes[(SI_SATTR_MAX - SI_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "action=\"signal-none\"",
    /* 0x06 */ "action=\"signal-low\"",
    /* 0x07 */ "action=\"signal-medium\"",
    /* 0x08 */ "action=\"signal-high\"",
    /* 0x09 */ "action=\"delete\"",
    /* 0x0A */ "created",
    /* 0x0B */ "href",
    /* 0x0C */ "href=\"http://",
    /* 0x0D */ "href=\"http://www.",
    /* 0x0E */ "href=\"https://",
    /* 0x0F */ "href=\"https://www.",
    /* 0x10 */ "si-expires",
    /* 0x11 */ "si-id",
    /* 0x12 */ "class",
};

const JC_INT8 *sl_tags[(SL_TAGS_MAX - SL_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "sl"
};

const JC_INT8 *sl_start_attributes[(SL_SATTR_MAX - SL_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "action=\"execute-low\"",
    /* 0x06 */ "action=\"execute-high\"",
    /* 0x07 */ "action=\"cache\"",
    /* 0x08 */ "href",
    /* 0x09 */ "href=\"http://",
    /* 0x0A */ "href=\"http://www.",
    /* 0x0B */ "href=\"https://",
    /* 0x0C */ "href=\"https://www."
};

const JC_INT8 *wbxml_value_attributes[(WBXML_VATTR_MAX - WBXML_VATTR_MIN) + 1] = 
{
    /* 0x85 */ ".com/",
    /* 0x86 */ ".edu/",
    /* 0x87 */ ".net/",
    /* 0x88 */ ".org/",
    /* 0x89 */ "accept",
    /* 0x8A */ "bottom",
    /* 0x8B */ "clear",
    /* 0x8C */ "delete",
    /* 0x8D */ "help",
    /* 0x8E */ "http://",
    /* 0x8F */ "http://www.",
    /* 0x90 */ "https://",
    /* 0x91 */ "https://www.",
    /* 0x92 */ NULL,
    /* 0x93 */ "middle",
    /* 0x94 */ "nowrap",
    /* 0x95 */ "onpick",
    /* 0x96 */ "onenterbackward",
    /* 0x97 */ "onenterforward",
    /* 0x98 */ "ontimer",
    /* 0x99 */ "options",
    /* 0x9A */ "password",
    /* 0x9B */ "reset",
    /* 0x9C */ NULL,
    /* 0x9D */ "text",
    /* 0x9E */ "top",
    /* 0x9F */ "unknown",
    /* 0xA0 */ "wrap",
    /* 0xA1 */ "www.",
};

const JC_INT8 *wml_tags[(WML_TAGS_MAX - WML_TAGS_MIN) + 1] = 
{
    /* 0x1B */ "pre",
    /* 0x1C */ "a",
    /* 0x1D */ "td",
    /* 0x1E */ "tr",
    /* 0x1F */ "table",
    /* 0x20 */ "p",
    /* 0x21 */ "postfield",
    /* 0x22 */ "anchor",
    /* 0x23 */ "access",
    /* 0x24 */ "b",
    /* 0x25 */ "big",
    /* 0x26 */ "br",
    /* 0x27 */ "card",
    /* 0x28 */ "do",
    /* 0x29 */ "em",
    /* 0x2A */ "fieldset",
    /* 0x2B */ "go",
    /* 0x2C */ "head",
    /* 0x2D */ "i",
    /* 0x2E */ "img",
    /* 0x2F */ "input",
    /* 0x30 */ "meta",
    /* 0x31 */ "noop",
    /* 0x32 */ "prev",
    /* 0x33 */ "onevent",
    /* 0x34 */ "optgroup",
    /* 0x35 */ "option",
    /* 0x36 */ "refresh",
    /* 0x37 */ "select",
    /* 0x38 */ "small",
    /* 0x39 */ "strong",
    /* 0x3A */ NULL,
    /* 0x3B */ "template",
    /* 0x3C */ "timer",
    /* 0x3D */ "u",
    /* 0x3E */ "setvar",
    /* 0x3F */ "wml",
};

const JC_INT8 *wml_start_attributes[(WML_SATTR_MAX - WML_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "accept-charset",
    /* 0x06 */ "align=\"bottom\"",
    /* 0x07 */ "align=\"center\"",
    /* 0x08 */ "align=\"left\"",
    /* 0x09 */ "align=\"middle\"",
    /* 0x0A */ "align=\"right\"",
    /* 0x0B */ "align=\"top\"",
    /* 0x0C */ "alt",
    /* 0x0D */ "content",
    /* 0x0E */ NULL,
    /* 0x0F */ "domain",
    /* 0x10 */ "emptyok=\"false\"",
    /* 0x11 */ "emptyok-\"true\"",
    /* 0x12 */ "format",
    /* 0x13 */ "height",
    /* 0x14 */ "hspace",
    /* 0x15 */ "ivalue",
    /* 0x16 */ "iname",
    /* 0x17 */ NULL,
    /* 0x18 */ "label",
    /* 0x19 */ "localsrc",
    /* 0x1A */ "maxlength",
    /* 0x1B */ "method=\"get\"",
    /* 0x1C */ "method=\"post\"",
    /* 0x1D */ "mode=\"nowrap\"",
    /* 0x1E */ "mode=\"wrap\"",
    /* 0x1F */ "multiple=\"false\"",
    /* 0x20 */ "multiple=\"true\"",
    /* 0x21 */ "name",
    /* 0x22 */ "newcontext=\"false\"",
    /* 0x23 */ "newcontext=\"true\"",
    /* 0x24 */ "onpick",
    /* 0x25 */ "onenterbackward",
    /* 0x26 */ "onenterforward",
    /* 0x27 */ "ontimer",
    /* 0x28 */ "optional=\"false\"",
    /* 0x29 */ "optional=\"true\"",
    /* 0x2A */ "path",
    /* 0x2B */ NULL,
    /* 0x2C */ NULL,
    /* 0x2D */ NULL,
    /* 0x2E */ "scheme",
    /* 0x2F */ "sendreferer=\"false\"",
    /* 0x30 */ "sendreferer=\"true\"",
    /* 0x31 */ "size",
    /* 0x32 */ "src",
    /* 0x33 */ "ordered=\"true\"",
    /* 0x34 */ "ordered=\"false\"",
    /* 0x35 */ "tabindex",
    /* 0x36 */ "title",
    /* 0x37 */ "type",
    /* 0x38 */ "type=\"accept\"",
    /* 0x39 */ "type=\"delete\"",
    /* 0x3A */ "type=\"help\"",
    /* 0x3B */ "type=\"password\"",
    /* 0x3C */ "type=\"onpick\"",
    /* 0x3D */ "type=\"onenterbackward\"",
    /* 0x3E */ "type=\"onenterforward\"",
    /* 0x3F */ "type=\"ontimer\"",
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ "type=\"options\"",
    /* 0x46 */ "type=\"prev\"",
    /* 0x47 */ "type=\"reset\"",
    /* 0x48 */ "type=\"text\"",
    /* 0x49 */ "type=\"vnd\"",
    /* 0x4A */ "href",
    /* 0x4B */ "href=\"http://",
    /* 0x4C */ "href=\"https://",
    /* 0x4D */ "value",
    /* 0x4E */ "vspace",
    /* 0x4F */ "width",
    /* 0x50 */ "xml:lang",
    /* 0x51 */ NULL,
    /* 0x52 */ "align",
    /* 0x53 */ "columns",
    /* 0x54 */ "class",
    /* 0x55 */ "id",
    /* 0x56 */ "forua=\"false\"",
    /* 0x57 */ "forua=\"true\"",
    /* 0x58 */ "src=\"http://",
    /* 0x59 */ "src=\"https://",
    /* 0x5A */ "http-equiv",
    /* 0x5B */ "http-equiv=\"Content-Type\"",
    /* 0x5C */ "content=\"application/vnd.wap.wmlc;charset=",
    /* 0x5D */ "http-equiv=\"Expires\"",
    /* 0x5E */ "accesskey",
    /* 0x5F */ "enctype",
    /* 0x60 */ "enctype=\"application/x-www-form-urlencoded\"",
    /* 0x61 */ "enctype=\"multipart/form-data\"",
    /* 0x62 */ "xml:space=\"preserve\"",
    /* 0x63 */ "xml:space=\"default\"",
    /* 0x64 */ "cache-control=\"no-cache\""
};

// #ifdef WML_NO_CLOSURES
/* No closure tags */
JC_INT32 wml_no_closure_tags[] = 
{
    WMLT_BR, WMLT_INPUT, WMLT_POSTFIELD, WMLT_NOOP, WMLT_PREV, WMLT_IMG, WMLT_GO, WMLT_META, WMLT_TIMER, -1
};

// #endif /* WML_NO_CLOSURES */

const JC_INT8 *WML_VAR_CONVERSION[] = { "escape", "ESCAPE", "e", "E", "unesc", "UNESC",
    "u", "U", "noesc", "NOESC", "n", "N",
};

const JC_INT8 *wta_wml_tags[(WTA_WML_TAGS_MAX - WTA_WML_TAGS_MIN) + 1] = 
{
    /* 0x3F */ "wta-wml"
};

// #ifdef PROPRIETARY_PROVISIONING_WBXML_EXT

const JC_INT8 *nokia_prov_tags[(MMI_PROV_NOKIA_TAGS_MAX - MMI_PROV_NOKIA_TAGS_MIN) + 1] = 
{
    /* 0x05 */ "characteristic-list",
    /* 0x06 */ "characteristic",
    /* 0x07 */ "parm"
};

const JC_INT8 *nokia_prov_start_attributes[(MMI_PROV_NOKIA_SATTR_MAX - MMI_PROV_NOKIA_SATTR_MIN) + 1] = 
{
    /* 0x06 */ "type=\"ADDRESS\"",
    /* 0x07 */ "type=\"URL\"",
    /* 0x08 */ "type=\"NAME\"",
    /* 0x09 */ NULL,
    /* 0x0A */ NULL,
    /* 0x0B */ NULL,
    /* 0x0C */ NULL,
    /* 0x0D */ NULL,
    /* 0x0E */ NULL,
    /* 0x0F */ NULL,
    /* 0x10 */ "name",
    /* 0x11 */ "value",
    /* 0x12 */ "name=\"BEARER\"",
    /* 0x13 */ "name=\"PROXY\"",
    /* 0x14 */ "name=\"PORT\"",
    /* 0x15 */ "name=\"NAME\"",
    /* 0x16 */ "name=\"PROXY_TYPE\"",
    /* 0x17 */ "name=\"URL\"",
    /* 0x18 */ "name=\"PROXY_AUTHNAME\"",
    /* 0x19 */ "name=\"PROXY_AUTHSECRET\"",
    /* 0x1A */ "name=\"SMS_SMSC_ADDRESS\"",
    /* 0x1B */ "name=\"USSD_SERVICECODE\"",
    /* 0x1C */ "name=\"GPRS_ACCESSPOINTNAME\"",
    /* 0x1D */ "name=\"PPP_LOGINTYPE\"",
    /* 0x1E */ "name=\"PROXY_LOGINTYPE\"",
    /* 0x1F */ NULL,
    /* 0x20 */ NULL,
    /* 0x21 */ "name=\"CSD_DIALSTRING\"",
    /* 0x22 */ "name=\"PPP_AUTHTYPE\"",
    /* 0x23 */ "name=\"PPP_AUTHNAME\"",
    /* 0x24 */ "name=\"PPP_AUTHSECRET\"",
    /* 0x25 */ NULL,
    /* 0x26 */ NULL,
    /* 0x27 */ NULL,
    /* 0x28 */ "name=\"CSD_CALLTYPE\"",
    /* 0x29 */ "name=\"CSD_CALLSPEED\"",
    /* 0x2A */ NULL,
    /* 0x2B */ NULL,
    /* 0x2C */ NULL,
    /* 0x2D */ NULL,
    /* 0x2E */ NULL,
    /* 0x2F */ NULL,
    /* 0x30 */ NULL,
    /* 0x31 */ NULL,
    /* 0x32 */ NULL,
    /* 0x33 */ NULL,
    /* 0x34 */ NULL,
    /* 0x35 */ NULL,
    /* 0x36 */ NULL,
    /* 0x37 */ NULL,
    /* 0x38 */ NULL,
    /* 0x39 */ NULL,
    /* 0x3A */ NULL,
    /* 0x3B */ NULL,
    /* 0x3C */ NULL,
    /* 0x3D */ NULL,
    /* 0x3E */ NULL,
    /* 0x3F */ NULL,
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ "value=\"GSM/CSD\"",
    /* 0x46 */ "value=\"GSM/SMS\"",
    /* 0x47 */ "value=\"GSM/USSD\"",
    /* 0x48 */ "value=\"IS-136/USSD\"",
    /* 0x49 */ "value=\"GPRS\"",
    /* 0x4A */ NULL,
    /* 0x4B */ NULL,
    /* 0x4C */ NULL,
    /* 0x4D */ NULL,
    /* 0x4E */ NULL,
    /* 0x4F */ NULL,
    /* 0x50 */ NULL,
    /* 0x51 */ NULL,
    /* 0x52 */ NULL,
    /* 0x53 */ NULL,
    /* 0x54 */ NULL,
    /* 0x55 */ NULL,
    /* 0x56 */ NULL,
    /* 0x57 */ NULL,
    /* 0x58 */ NULL,
    /* 0x59 */ NULL,
    /* 0x5A */ NULL,
    /* 0x5B */ NULL,
    /* 0x5C */ NULL,
    /* 0x5D */ NULL,
    /* 0x5E */ NULL,
    /* 0x5F */ NULL,
    /* 0x60 */ "value=\"9200\"",
    /* 0x61 */ "value=\"9201\"",
    /* 0x62 */ "value=\"9202\"",
    /* 0x63 */ "value=\"9203\"",
    /* 0x64 */ "value=\"AUTOMATIC\"",
    /* 0x65 */ "value=\"MANUAL\"",
    /* 0x66 */ NULL,
    /* 0x67 */ NULL,
    /* 0x68 */ NULL,
    /* 0x69 */ NULL,
    /* 0x6A */ "value=\"AUTO\"",
    /* 0x6B */ "value=\"9600\"",
    /* 0x6C */ "value=\"14400\"",
    /* 0x6D */ "value=\"19200\"",
    /* 0x6E */ "value=\"28800\"",
    /* 0x6F */ "value=\"38400\"",
    /* 0x70 */ "value=\"PAP\"",
    /* 0x71 */ "value=\"CHAP\"",
    /* 0x72 */ "value=\"ANALOGUE\"",
    /* 0x73 */ "value=\"ISDN\"",
    /* 0x74 */ "value=\"43200\"",
    /* 0x75 */ "value=\"57600\"",
    /* 0x76 */ "value=\"MSISDN_NO\"",
    /* 0x77 */ "value=\"IPV4\"",
    /* 0x78 */ "value=\"MS_CHAP\"",
    /* 0x79 */ NULL,
    /* 0x7A */ NULL,
    /* 0x7B */ NULL,
    /* 0x7C */ "type=\"MMSURL\"",
    /* 0x7D */ "type=\"ID\"",
    /* 0x7E */ "type=\"ISP_NAME\"",
    /* 0x7F */ "type=\"BOOKMARK\""
};

#ifdef JATAAYU_CCA_NOT_REQUIRED

const JC_INT8 *nokia_prov_value_attributes[(MMI_PROV_NOKIA_VATTR_MAX - MMI_PROV_NOKIA_VATTR_MIN) + 1] = 
{
    /* 0x45 */ "GSM/CSD",
    /* 0x46 */ "GSM/SMS",
    /* 0x47 */ "GSM/USSD",
    /* 0x48 */ "IS-136/USSD",
    /* 0x49 */ "GPRS",
    /* 0x4A */ NULL,
    /* 0x4B */ NULL,
    /* 0x4C */ NULL,
    /* 0x4D */ NULL,
    /* 0x4E */ NULL,
    /* 0x4F */ NULL,
    /* 0x50 */ NULL,
    /* 0x51 */ NULL,
    /* 0x52 */ NULL,
    /* 0x53 */ NULL,
    /* 0x54 */ NULL,
    /* 0x55 */ NULL,
    /* 0x56 */ NULL,
    /* 0x57 */ NULL,
    /* 0x58 */ NULL,
    /* 0x59 */ NULL,
    /* 0x5A */ NULL,
    /* 0x5B */ NULL,
    /* 0x5C */ NULL,
    /* 0x5D */ NULL,
    /* 0x5E */ NULL,
    /* 0x5F */ NULL,
    /* 0x60 */ "9200",
    /* 0x61 */ "9201",
    /* 0x62 */ "9202",
    /* 0x63 */ "9203",
    /* 0x64 */ "AUTOMATIC",
    /* 0x65 */ "MANUAL",
    /* 0x66 */ NULL,
    /* 0x67 */ NULL,
    /* 0x68 */ NULL,
    /* 0x69 */ NULL,
    /* 0x6A */ "AUTO",
    /* 0x6B */ "9600",
    /* 0x6C */ "14400",
    /* 0x6D */ "19200",
    /* 0x6E */ "28800",
    /* 0x6F */ "38400",
    /* 0x70 */ "PAP",
    /* 0x71 */ "CHAP",
    /* 0x72 */ "ANALOGUE",
    /* 0x73 */ "ISDN",
    /* 0x74 */ "43200",
    /* 0x75 */ "57600",
    /* 0x76 */ "MSISDN_NO",
    /* 0x77 */ "IPV4",
    /* 0x78 */ "MS_CHAP"
};

#endif /* JATAAYU_CCA_NOT_REQUIRED */ 
// #endif /* PROPRIETARY_PROVISIONING_WBXML_EXT */

const JC_INT8 *pacOmaProvStartAttributes[(MMI_PROV_OMA_SATTR_MAX - MMI_PROV_OMA_SATTR_MIN) + 1] = 
{
    /* 0x05 */ "name",
    /* 0x06 */ "value",
    /* 0x07 */ "name=\"NAME\"",
    /* 0x08 */ NULL,
    /* 0x09 */ NULL,
    /* 0x0A */ NULL,
    /* 0x0B */ NULL,
    /* 0x0C */ NULL,
    /* 0x0D */ NULL,
    /* 0x0E */ NULL,
    /* 0x0F */ NULL,
    /* 0x10 */ NULL,
    /* 0x11 */ NULL,
    /* 0x12 */ NULL,
    /* 0x13 */ NULL,
    /* 0x14 */ "name=\"INTERNET\"",
    /* 0x15 */ NULL,
    /* 0x16 */ NULL,
    /* 0x17 */ NULL,
    /* 0x18 */ NULL,
    /* 0x19 */ NULL,
    /* 0x1A */ NULL,
    /* 0x1B */ NULL,
    /* 0x1C */ "name=\"STARTPAGE\"",
    /* 0x1D */ NULL,
    /* 0x1E */ NULL,
    /* 0x1F */ NULL,
    /* 0x20 */ NULL,
    /* 0x21 */ NULL,
    /* 0x22 */ "name=\"TO-NAPID\"",
    /* 0x23 */ "name=\"PORTNBR\"",
    /* 0x24 */ "name=\"SERVICE\"",
    /* 0x25 */ NULL,
    /* 0x26 */ NULL,
    /* 0x27 */ NULL,
    /* 0x28 */ NULL,
    /* 0x29 */ NULL,
    /* 0x2A */ NULL,
    /* 0x2B */ NULL,
    /* 0x2C */ NULL,
    /* 0x2D */ NULL,
    /* 0x2E */ "name=\"AACCEPT\"",
    /* 0x2F */ "name=\"AAUTHDATA\"",
    /* 0x30 */ "name=\"AAUTHLEVEL\"",
    /* 0x31 */ "name=\"AAUTHNAME\"",
    /* 0x32 */ "name=\"AAUTHSECRET\"",
    /* 0x33 */ "name=\"AAUTHTYPE\"",
    /* 0x34 */ "name=\"ADDR\"",
    /* 0x35 */ "name=\"ADDRTYPE\"",
    /* 0x36 */ "name=\"APPID\"",
    /* 0x37 */ "name=\"APROTOCOL\"",
    /* 0x38 */ "name=\"PROVIDER-ID\"",
    /* 0x39 */ "name=\"TO-PROXY\"",
    /* 0x3A */ "name=\"URI\"",
    /* 0x3B */ "name=\"RULE\"",
    /* 0x3C */ NULL,
    /* 0x3D */ NULL,
    /* 0x3E */ NULL,
    /* 0x3F */ NULL,
    /* 0x40 */ NULL,
    /* 0x41 */ NULL,
    /* 0x42 */ NULL,
    /* 0x43 */ NULL,
    /* 0x44 */ NULL,
    /* 0x45 */ NULL,
    /* 0x46 */ NULL,
    /* 0x47 */ NULL,
    /* 0x48 */ NULL,
    /* 0x49 */ NULL,
    /* 0x4A */ NULL,
    /* 0x4B */ NULL,
    /* 0x4C */ NULL,
    /* 0x4D */ NULL,
    /* 0x4E */ NULL,
    /* 0x4F */ NULL,
    /* 0x50 */ "type",
    /* 0x51 */ NULL,
    /* 0x52 */ NULL,
    /* 0x53 */ "type=\"PORT\"",
    /* 0x54 */ NULL,
    /* 0x55 */ "type=\"APPLICATION\"",
    /* 0x56 */ "type=\"APPADDR\"",
    /* 0x57 */ "type=\"APPAUTH\"",
    /* 0x58 */ "type=\"CLIENTIDENTITY\"",
    /* 0x59 */ "type=\"RESOURCE\""
};

const JC_INT8 *pacOmaProvValueAttributes[(OMA_PROV_VATTR_MAX - OMA_PROV_VATTR_MIN) + 1] = 
{
    /* 0x80 */ ",",
    /* 0x81 */ "HTTP-",
    /* 0x82 */ "BASIC",
    /* 0x83 */ "DIGEST",
    /* 0x84 */ NULL,
    /* 0x85 */ NULL,
    /* 0x86 */ "IPV6",
    /* 0x87 */ "E164",
    /* 0x88 */ "ALPHA",
    /* 0x89 */ NULL,
    /* 0x8A */ NULL,
    /* 0x8B */ NULL,
    /* 0x8C */ NULL,
    /* 0x8D */ "APPSRV",
    /* 0x8E */ "OBEX",
    /* 0x8F */ NULL,
    /* 0x90 */ NULL,
    /* 0x91 */ NULL,
    /* 0x92 */ NULL,
    /* 0x93 */ NULL,
    /* 0x94 */ NULL,
    /* 0x95 */ NULL,
    /* 0x96 */ NULL,
    /* 0x97 */ NULL,
    /* 0x98 */ NULL,
    /* 0x99 */ NULL,
    /* 0x9A */ NULL,
    /* 0x9B */ NULL,
    /* 0x9C */ NULL,
    /* 0x9D */ NULL,
    /* 0x9E */ NULL,
    /* 0x9F */ NULL,
    /* 0xA0 */ NULL,
    /* 0xA1 */ NULL,
    /* 0xA2 */ NULL,
    /* 0xA3 */ NULL,
    /* 0xA4 */ NULL,
    /* 0xA5 */ NULL,
    /* 0xA6 */ NULL,
    /* 0xA7 */ NULL,
    /* 0xA8 */ NULL,
    /* 0xA9 */ NULL,
    /* 0xAA */ NULL,
    /* 0xAB */ NULL,
    /* 0xAC */ NULL,
    /* 0xAD */ NULL,
    /* 0xAE */ NULL,
    /* 0xAF */ NULL,
    /* 0xB0 */ NULL,
    /* 0xB1 */ NULL,
    /* 0xB2 */ NULL,
    /* 0xB3 */ NULL,
    /* 0xB4 */ NULL,
    /* 0xB5 */ NULL,
    /* 0xB6 */ NULL,
    /* 0xB7 */ NULL,
    /* 0xB8 */ NULL,
    /* 0xB9 */ NULL,
    /* 0xBA */ NULL,
    /* 0xBC */ NULL,
    /* 0xBD */ NULL,
    /* 0xBE */ NULL,
    /* 0xBF */ NULL,
    /* 0xC0 */ NULL,
    /* 0xC1 */ NULL,
    /* 0xC2 */ NULL,
    /* 0xC3 */ NULL,
    /* 0xC4 */ NULL,
    /* 0xC5 */ NULL,
    /* 0xC6 */ NULL,
    /* 0xC7 */ NULL,
    /* 0xC8 */ NULL,
    /* 0xC9 */ NULL,
    /* 0xCA */ "CL-WSP",
    /* 0xCB */ "CO-WSP",
    /* 0xCC */ "CL-SEC-WSP",
    /* 0xCD */ "CO-SEC-WSP",
    /* 0xCE */ "CL-SEC-WTA",
    /* 0xCF */ "CO-SEC-WTA"
};

#endif /* JATAAYU_SUPPORT */ 
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* _JPARSERHANDLER_C */ /* _JPROVOMA_C */

