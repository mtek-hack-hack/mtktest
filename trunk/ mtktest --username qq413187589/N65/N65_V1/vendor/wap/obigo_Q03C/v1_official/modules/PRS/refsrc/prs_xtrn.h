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
 * prs_xtrn.h
 *
 * External provisioning add-ons.
 */

#ifndef _prs_xtrn_h
#define _prs_xtrn_h

#ifndef _prs_cfg_h
#include "prs_cfg.h"
#endif

#ifndef _prs_type_h
#include "prs_type.h"
#endif

/*************************************
 * Type definitions
 *************************************/

typedef struct {
  int type;
  int isString;
  int strLen;

  union {
    const char* s;
    int         i;
  } value;
} prs_net_account_data_t;


typedef struct {
  int field;
  int number;
} prs_net_account_transform_t;

/**********************************************************************/
/*                            OTA Settings                            */
/*                Browser Settings & Browser Bookmarks                */
/**********************************************************************/

#if defined PRS_CONFIG_OTA_BROWSER || defined PRS_CONFIG_OTA_BROWSER_WBXML

/*************************************
 * Functions
 *************************************/

/*
 * Process node list. Post-processing step.
 */
int
prs_br_process_list_pre (prs_node_list_t* list);


/*
 * Process node list. Pre-processing step.
 */
int
prs_br_process_node (prs_node_t* node);


/*
 * Process node list. Pre-processing step.
 */
int
prs_br_process_list_post (prs_node_list_t* list);


#endif



/**********************************************************************/
/*                            OTA Settings                            */
/*                           SyncML settings                          */
/**********************************************************************/

#if defined PRS_CONFIG_OTA_SYNCML || defined PRS_CONFIG_OTA_SYNCML_WBXML
#endif



/**********************************************************************/
/*                          WAP Provisioning                          */
/**********************************************************************/

#if defined PRS_CONFIG_WAP || defined PRS_CONFIG_WAP_WBXML

/*************************************
 * Functions
 *************************************/

/*
 * Process node list. Post-processing step.
 */
int
prs_wap_process_list_pre (prs_node_list_t* list);


/*
 * Process node list. Pre-processing step.
 */
int
prs_wap_process_node (prs_node_t* node);


/*
 * Process node list. Pre-processing step.
 */
int
prs_wap_process_list_post (prs_node_list_t* list);
#endif


/**********************************************************************/
/*                          IOTA Provisioning                         */
/**********************************************************************/

#if defined PRS_CONFIG_IOTA || defined PRS_CONFIG_IOTA_WBXML
#endif



#endif


