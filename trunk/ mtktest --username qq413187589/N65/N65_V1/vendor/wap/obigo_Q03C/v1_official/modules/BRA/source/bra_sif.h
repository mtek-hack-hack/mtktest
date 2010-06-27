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
 * bra_sif.c
 *
 * This file contain the BRA Services Interface, E.g. the functionality
 * needed to handle signals from BRS is ipmlemented here
 * internal signal receive funtion.
 *
 */
#ifndef _bra_sif_h
#define _bra_sif_h

#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif

#ifndef _brs_if_h
#include "brs_if.h"
#endif


/******************************************************************************
 * BRS States
 ******************************************************************************/

#define BRA_SIF_BRS_NOT_ACTIVE 1
#define BRA_SIF_BRS_ACTIVATED  2
#define BRA_SIF_BRS_ACTIVE     3
#define BRA_SIF_BRS_CREATING   4
#define BRA_SIF_BRS_CREATED    5


/******************************************************************************
 * PROFILE FALLBACK STATE
 ******************************************************************************/
#define BRA_SIF_FBSTATE_NONE            1
#define BRA_SIF_FBSTATE_CONNECTING      2
#define BRA_SIF_FBSTATE_WAITUSER        3
#define BRA_SIF_FBSTATE_SWITCHING       4

/******************************************************************************
 * BEARER AVAILABILITY
 ******************************************************************************/
#define BRA_SIF_BR_STATE_UNKNOWN        0
#define BRA_SIF_BR_STATE_AVAILABLE      1
#define BRA_SIF_BR_STATE_NOT_AVAILABLE  2

/******************************************************************************
 * Exported Functions
 *****************************************************************************/
/*
 * Initializes the variables used in this file.
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void
bra_sif_init (void);

/*
 * This function returns the Socket id used for the current request 
 *
 * PARAMETERS
 *
 * RETURN    : Socket id
 */
int 
bra_sif_get_socket_id (void);

#ifdef BRA_CONFIG_SECURITY
/*
 * This function is called in response to a previous request to the Security 
 * package to return the currently used security class
 *
 * PARAMETERS
 *
 * sec_class : The currently used security class
 * info_available: Indicates if session info is available.
 * cert_available: Indicates if certificate for session is available.
 *
 * RETURN    : void
 */
void
bra_sif_set_security_class (int sec_class, int info_available,
                            int cert_available);

int
bra_sif_sec_info_available (void);

int
bra_sif_sec_cert_available (void);

int
bra_sif_get_security_id (void);
#endif

/*
 * This function will call the MSF macros to try and start the BRS module
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_start_brs (void);

/*
 * This function must be called when BRA receives the signal that BRS is 
 * active. a reequest to create an istance of the BRS is made.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_active (void);

/*
 * This function must be called when a request to instantiate the BRS has
 * returned. If there is a pending request this will be isued now.
 *
 * PARAMETERS
 *
 * p         : Pointer to signal structure
 *
 * RETURN    : void
 */ 
void
bra_sif_brs_create_responce (void *p);

/*
 * This function should be called when the BRS has terminated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_terminated (void);

/*
 * This function is used to set the assumed state of the BRS
 *
 * PARAMETERS
 *
 * status    : Current state as defined above
 *
 * RETURN    : void
 */
void
bra_sif_set_brs_status (int status);

/*
 * Returns the currently assumed BRS state
 *
 * PARAMETERS
 *
 * RETURN    : BRS state
 */
int
bra_sif_get_brs_status (void);

/*
 * This function is used to get the object Id previosly returned in
 * a request to instantiate the BRS
 *
 * PARAMETERS
 *
 * RETURN    :
 */
int
bra_sif_get_brs_id (void);

/*
 * This function is called when the BRA receives a status notificatoin from 
 * the BRS. This information is used to update the status bar.
 *
 * PARAMETERS
 *
 * p         : Pointer to status structure (brs_status_t)
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_status (void *p);

/*
 * This function is called when an error has occured in the BRS (or other module 
 * used by BRS) after a request has been made. A error dialog is raised to the 
 * user.
 *
 * PARAMETERS
 *
 * id        : object id
 * error     : Error code as defined in BRS_if.h
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_error (int id, int error);

/*
 * When a request is compleated the BRS send information about the loaded request.
 * this function handles such information e.g. Title and url. This function also
 * remove any prevois Do-Elements which now are obsolete
 *
 * PARAMETERS
 *
 * p         : Pointer to document info structure (brs_document_info_t)
 *
 * RETURN    :
 */
void
bra_sif_handle_brs_doc_info (brs_document_info_t *p);

/*
 * If the loaded documet contains Do-elements this function will receive a structure
 * with all such elements. this function will pass them on to the bra_opt_set_do_elements
 * fuction which will display them in the options menu. 
 * Note the p parameter MUST NOT be freed when this function returns.
 *
 * PARAMETERS
 *
 * p         : Do-Element structure
 *
 * RETURN    : void
 */
void
bra_sif_handle_brs_do_element (void* p);

/*
 * This function is called from the BRS (via Signals) when an content element is selected 
 *
 * PARAMETERS
 *
 * p         : Information about the selected element
 *
 * RETURN    : void
 */
void 
brs_sif_element_focused (void *p);

#ifdef BRA_CFG_OFFLINE_PAGES
/*
 * This function is called from the BRS (via Signals) when the offline page not found 
 *
 * PARAMETERS
 *
 * p         : Information about the selected element
 *
 * RETURN    : void
 */
void 
brs_sif_page_not_found_offline (void *p);
#endif/*BRA_CFG_OFFLINE_PAGES*/

#ifdef BRA_CFG_PROF_FALLBACK
/*
 * This function is used for continuing the fallback process.
 * purpose of this func is to ensure BRS has completed update its new net-id
 * so that BRA can proceed refresh prev loading page.
 *
 * RETURN    : void
 */
void
bra_sif_fallback_continue (int net_id);

/*
 * This function is used to indicate whether profile fallback currently in switching bearer status
 * this is so that delete_status can be postponed until user has decided whetehr bearer should be switched
 *
 * RETURN    : void
 */
int
bra_sif_is_pending_bearer_switch(void);
#endif

/*
 * This function is used for handling bearer statuses for level 3 profile fallback
 *
 * RETURN    : void
 */
void
bra_sif_handle_bearer_status(int bearer_type, int status);


/*
 * This function handles the notification from BearerInfo primitive
 *
 * RETURN    : void
 */
void
bra_sif_handle_notify_bearer_info(int bearer, int status);


#ifdef BRA_CFG_SELECT_MODE
/*
 * This function calls a function to create either an "option" or a "select mode" menu,
 * depending on the current navigation mode.
 *
 * PARAMETERS
 *
 *
 * RETURN    : void
 */
void
bra_sif_select_menu (void);

/*
 * This function sets the navigation mode.
 *
 * PARAMETERS
 *
 * set       : 0: select mode off, 1: select mode on
 *
 * RETURN    : void
 */
void
bra_sif_set_select_mode (int set);
#endif /*BRA_CFG_SELECT_MODE*/

#endif


