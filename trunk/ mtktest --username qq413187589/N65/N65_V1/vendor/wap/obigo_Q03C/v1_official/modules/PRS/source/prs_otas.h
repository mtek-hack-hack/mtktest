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






#ifndef _prs_otas_h
#define _prs_otas_h

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _prs_cfg_h
#include "prs_cfg.h"
#endif









#define PRS_SYN_ELEMENT_ADDR                 0x05
#define PRS_SYN_ELEMENT_ADDRTYPE             0x06
#define PRS_SYN_ELEMENT_AUTH                 0x07
#define PRS_SYN_ELEMENT_AUTHLEVEL            0x08
#define PRS_SYN_ELEMENT_AUTHSCHEME           0x09
#define PRS_SYN_ELEMENT_BEARER               0x0A
#define PRS_SYN_ELEMENT_CONREF               0x0B
#define PRS_SYN_ELEMENT_CONTYPE              0x0C
#define PRS_SYN_ELEMENT_CRED                 0x0D
#define PRS_SYN_ELEMENT_CTTYPE               0x0E
#define PRS_SYN_ELEMENT_CTVER                0x0F
#define PRS_SYN_ELEMENT_HOSTADDR             0x10
#define PRS_SYN_ELEMENT_NAME                 0x11
#define PRS_SYN_ELEMENT_PORT                 0x12
#define PRS_SYN_ELEMENT_REFID                0x13
#define PRS_SYN_ELEMENT_REMOTEDB             0x14
#define PRS_SYN_ELEMENT_SYNCSETTINGS         0x15
#define PRS_SYN_ELEMENT_URI                  0x16
#define PRS_SYN_ELEMENT_USERNAME             0x17
#define PRS_SYN_ELEMENT_VERSION              0x18


#if defined PRS_CONFIG_OTA_SYNCML || defined PRS_CONFIG_OTA_SYNCML_WBXML
extern const msf_strtable_info_t prs_syn_Elements;
extern const msf_strtable_info_t prs_syn_Attributes;
extern const unsigned char       prs_syn_Element_table[];





#ifdef PRS_CONFIG_OTA_SYNCML_WBXML





#define PRS_SYN_TRANSFORM_SIZE 0
#endif
#endif


#endif


