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

#ifndef _bra_psl_h
#define _bra_psl_h
/************************************************************
 * Local Types 
 ************************************************************/


/************************************************************
 * Defines
 ************************************************************/
#define PUSH_MAX_NO_OF_MSG    (wap_custom_get_max_push_msg_num())/*15*/
#define BRA_INBOX_REFRESH_TIMER_ID 0x0011

/************************************************************
 * Global variables
 ************************************************************/

 /************************************************************
 * Function Prototypes
 ************************************************************/

/************************************************************
 * Internal Function
 ************************************************************/




/************************************************************
 * External Functions
 ************************************************************/

/*
 * Initializes the BRA Push SL functionality 
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_init (void);

/*
 * This function is called when the UIS module is active
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_set_uis_state_active (void);

/*
 * This function Must be called when the UIS module is terminated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_uis_terminated (void);

/*
 * This function releases all resources allocated for handling push 
 * messages within the BRA.
 *
 * PARAMETERS
 *
 * RETURN    : 0 if the IBS is terminated; 1 if a request to terminate
 *             the IBS moudle is sent.
 */
int
bra_psl_uis_terminate (void);


void 
bra_psl_msg_reply (void *p);


void 
bra_psl_new_sl_msg_notification (void *p);

#ifdef WAP_SUPPORT
void
bra_psl_register_reply (void *p);

void 
bra_psl_msg_list_reply (void *p);

void
bra_psl_create_push_inbox (void);

void
bra_psl_reply_full_msg (void *p);

void
bra_psl_new_msg_notification (void *p);

void
bra_psl_reply_delete_msg (void *p);

void
bra_psl_reply_change_msg (void *p);

void 
bra_psl_reply_nbr_of_msg (void *p);

void
bra_psl_unread_check(void);

void
bra_psl_notify_msg_deleted(void* p);

void
bra_psl_timer_expired(void *p);

#endif

/*
 * Creates the Push Settings menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_psl_create_settings_menu (void);

#ifdef __UNIFIED_MSG_SUPPORT__

/* UM: get push message number */
void
bra_psl_get_push_msg_num (void);

/* UM: get push message list */
void
bra_psl_get_push_msg_list (void *p);

/* UM: get push message info */
void
bra_psl_get_push_msg_info (void *p);

/* UM: delete push inbox */
void
bra_psl_del_push_msg_inbox (void);

/* UM: view push message */
void
bra_psl_view_push_msg (void *p);

#endif

#endif /*_bra_psl_h*/


