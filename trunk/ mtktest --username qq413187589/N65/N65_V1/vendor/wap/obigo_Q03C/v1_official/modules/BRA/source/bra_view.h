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
 * bra_view.c
 *
 * This file contain the BRA viewport implementation.
 * The viewport is the window were content, status bar
 * and so on are displayed. 
 *
 */
#ifndef _bra_view_h
#define _bra_view_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#define BRA_SPLASH_TIMER_ID 0x0001
#define BRA_RQEUEST_TIMER_ID 0x0002

void 
bra_view_enable (void);

void 
bra_view_disable (void);

void 
bra_wiew_timer_expired (void *p);

void
bra_view_set_paintbox_handle(MsfWindowHandle paintbox);

/*
 * This fuction sets the title of the view port window
 *
 * PARAMETERS
 *
 * title     : Title of the visited page
 * url       : URL of the visited page
 *
 * RETURN    : void
 */
#ifdef BRA_CFG_DISPLAY_TITLE

void 
bra_view_set_title(char *title, char *url);
#endif
/*
 * This function is called to enable the busy iconin the viewport window
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_view_set_busy_icon (void);


/*
 * Called to enable the secure icon in the viewport window
 * This function is only available if the MS security pagage is included.
 *
 * PARAMETERS
 *
 * sec_class : the current security class returned form SEC module
 *
 * RETURN    : void
 */
#ifdef BRA_CONFIG_SECURITY
void 
bra_view_set_secure_icon (int sec_class);
#endif

/*
 * This function changes the value of the left and right soft key.
 * if either value is 0 the label on that softkey is left unchanged
 *
 * PARAMETERS
 *
 * left      : MsfStringHandle of left softkey
 * right     : MsfStringHandle of right softkey
 *
 * RETURN    : void
 */
void
bra_view_set_soft_key (MsfStringHandle left, MsfStringHandle right);

/*
 * This function creates the viewport vindow and displays it.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_view_create_view(void);

/*
 * This function creates and display a download status bar. below functions
 * are used to increment fields in the dialog
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_status_bar (void);

/*
 * This function free resources allocated for the download status bar.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_view_delete_status (void);

/*
 * This function notifyies the Status bare that a new item is beeing loaded.
 *
 * PARAMETERS
 *
 * s         : Status string e.g. "Loading Document..."
 * url       : Url to the object that is beeing loaded
 *
 * RETURN    :
 */
void
bra_view_new_object (MsfStringHandle s, char* url);

/*
 * This function terminates an object and the status bar is updated
 *
 * PARAMETERS
 *
 * size      : The size of the loaded object
 *
 * RETURN    :
 */
void
bra_view_object_done (int size);

MsfWindowHandle 
bra_view_get_paintbox (void);

char* 
bra_view_get_title (void);

char*
bra_view_get_url (void);

void 
bra_view_enable_back_action (MSF_BOOL enable);

void
bra_view_loading_complete (MSF_BOOL b);

int
bra_view_if_has_viewable_page(void);

int
bra_view_is_busy(void);

int
bra_view_is_enabled(void);

int
bra_view_is_user_cancelled(void);

void
bra_view_set_idle_softkey(void);

void
bra_view_enter_select_mode (void);

void 
bra_view_cancel_select_mode (void);

#ifdef BRA_CFG_USE_SPLASH
void bra_view_set_splash_timer (void);
void bra_view_reset_splash_timer (void);
#endif

void 
bra_view_set_request_timer (void);

void 
bra_view_reset_request_timer (void);

void
bra_view_download_complete(int status);


void bra_view_document_done(int number);


void    
bra_view_cancel_loading(void);



#endif /* _bra_view_h */



