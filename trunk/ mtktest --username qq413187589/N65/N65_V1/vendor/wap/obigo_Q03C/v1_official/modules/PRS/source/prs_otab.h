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






#ifndef _prs_otab_h
#define _prs_otab_h

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _prs_cfg_h
#include "prs_cfg.h"
#endif









#define PRS_BR_ELEMENT_CHARCT_LIST           0x05
#define PRS_BR_ELEMENT_CHARCT                0x06
#define PRS_BR_ELEMENT_PARAM                 0x07



#define PRS_BR_ATTRIBUTE_TYPE                0x00
#define PRS_BR_ATTRIBUTE_NAME                0x01
#define PRS_BR_ATTRIBUTE_VALUE               0x02





#define PRS_BR_ATTRVAL_URL                   0x0000
#define PRS_BR_ATTRVAL_NAME                  0x0001
#define PRS_BR_ATTRVAL_ADDRESS               0x0102
#define PRS_BR_ATTRVAL_MMSURL                0x0103
#define PRS_BR_ATTRVAL_ID                    0x0104
#define PRS_BR_ATTRVAL_BOOKMARK              0x0105




#define PRS_BR_ATTRVAL_BEARER                0x0202
#define PRS_BR_ATTRVAL_PROXY                 0x0203
#define PRS_BR_ATTRVAL_PORT                  0x0204
#define PRS_BR_ATTRVAL_PROXY_TYPE            0x0205
#define PRS_BR_ATTRVAL_PROXY_AUTHNAME        0x0206
#define PRS_BR_ATTRVAL_PROXY_AUTHSECRET      0x0207
#define PRS_BR_ATTRVAL_SMS_SMSC_ADDRESS      0x0208
#define PRS_BR_ATTRVAL_USSD_SERVICE_CODE     0x0209
#define PRS_BR_ATTRVAL_GPRS_ACCESSPOINTNAME  0x020A
#define PRS_BR_ATTRVAL_PPP_LOGINTYPE         0x023B
#define PRS_BR_ATTRVAL_PROXY_LOGINTYPE       0x020C
#define PRS_BR_ATTRVAL_CSD_DIALSTRING        0x020D
#define PRS_BR_ATTRVAL_PPP_AUTHTYPE          0x020E
#define PRS_BR_ATTRVAL_PPP_AUTHNAME          0x020F
#define PRS_BR_ATTRVAL_PPP_AUTHSECRET        0x0210
#define PRS_BR_ATTRVAL_CSD_CALLTYPE          0x0211
#define PRS_BR_ATTRVAL_CSD_CALLSPEED         0x0212
#define PRS_BR_ATTRVAL_ISP_NAME              0x0213


#if defined PRS_CONFIG_OTA_BROWSER || defined PRS_CONFIG_OTA_BROWSER_WBXML
extern const msf_strtable_info_t prs_br_Elements;
extern const msf_strtable_info_t prs_br_Attributes;
extern const msf_strtable_info_t prs_br_Attrvals;
extern const unsigned char       prs_br_Element_table[];
extern const MSF_UINT16          prs_br_AttributeTypes[];

#ifdef PRS_CONFIG_OTA_BROWSER_WBXML
extern const MSF_UINT8           prs_br_AttrTransform[];
extern const msf_strtable_info_t prs_br_AttrStart;

#define PRS_BR_TRANSFORM_SIZE 128
#endif
#endif

#endif


