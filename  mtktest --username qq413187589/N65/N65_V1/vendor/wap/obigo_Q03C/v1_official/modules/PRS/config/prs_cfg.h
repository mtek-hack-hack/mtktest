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
 * prs_cfg.h
 *
 * Provisioning configuration.
 */

#ifndef _prs_cfg_h
#define _prs_cfg_h
#ifdef MTK_TMP_PATCH /* CR27923 */
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
#endif

/* Parser buffer size */
#define PRS_PRSR_BUF_SIZE       500

/* Number of concurrent output object needed */
#define PRS_MAX_OUTPUT_OBJECTS  3

/* Supported types */
#define PRS_CONFIG_WAP
#define PRS_CONFIG_WAP_WBXML

#define PRS_CONFIG_OTA_BROWSER
#define PRS_CONFIG_OTA_BROWSER_WBXML
/*
#define PRS_CONFIG_OTA_SYNCML 
#define PRS_CONFIG_OTA_SYNCML_WBXML 

#define PRS_CONFIG_IOTA
#define PRS_CONFIG_IOTA_WBXML
*/

#ifdef MTK_TMP_PATCH /* CR27923 */
#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
#endif
#endif
#endif


