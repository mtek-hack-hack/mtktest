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
 * bra_dlg.h
 * 
 * Description:
 *		This file contains code to display and handle common types of dialogs.
 *
 *    
 */

#ifndef _bra_dlg_h
#define _bra_dlg_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _bra_win_h
#include "bra_win.h"
#endif

/************************************************************
 * Types
 ************************************************************/

typedef void (*bra_dlg_in_focus_t)(void);

typedef int (*bra_dlg_title_url_response_t)(char* title, char* url);

typedef int (*bra_dlg_input_response_t)(char* response);

typedef void (*bra_action_handle_t)(MsfActionType response);

typedef void (*bra_dlg_opt_response_t)(int selected);

/************************************************************
 * External Functions
 ************************************************************/
#ifdef BRA_USE_CTK_INLINE
void 
bra_dlg_ctk_create_title_url_form (MSF_UINT16 title, 
                                   MsfStringHandle input_title,
                                   char * input_url,
                                   bra_dlg_title_url_response_t callback,
                                   int close_to_id,
                                   MSF_BOOL modified,
                                   MSF_BOOL msg_icon);

void 
bra_dlg_create_auth_form (MSF_UINT8 module,
                          int requestId,
                          int authType, 
                          const char *realm,
                          const char* username,
                          int warnings);
#endif
/*
 * This function is called to dispay a dialog that handles input 
 * of a title and url. The response i returned in a call to a 
 * callback function. the responce will be destroyed when the 
 * callback returnes successfully. It is also the responsibility 
 * of the callback to validate the response. If the response is  
 * valid the callback should return 1. If for some reason the 
 * response is invalid the callback might raise a error dialog 
 * and then return 0.
 *
 * PARAMETERS
 *
 * title      : Handle to dialog title
 * input_title: Handle to default text to be put IN the title input field 
 * input_url  : Pointer to default text to be put IN the url input field 
 * callback   : Pointer to callback where the response should be handled
 * close_to_id: Window id to the window to be displayed when this dialog
 *              ends.
 *
 * RETURN     : void
 */
void 
bra_dlg_create_title_url_form (MsfStringHandle title, 
						       MsfStringHandle input_title,
						       char * input_url,
                               bra_dlg_title_url_response_t callback,
                               int close_to_id);


/*
 * This function creates and handles the events of an MSF Dialog. The 
 * response is returend in the callback function. This function is 
 * typically used to create a Confirmation or Error dialog
 *
 * PARAMETERS
 *
 * type        : Type of Dialog to create, (MsfDialogType)
 * text        : Message to be displayed in the Dialog
 * left_action : Label of the left softkey
 * right_action: Label of the Right softkey
 * timeout     : The amount of time after which the dialog should be closed.
 *               Setting the timeout value to 0 will create a dialog which the 
 *               user must terminate manualy
 * callback    : fFunction pointer to response function
 *
 * RETURN      : void
 */
void 
bra_dlg_create_dlg (MsfDialogType   type,
                    MsfStringHandle text, 
                    MsfStringHandle left_action, 
                    MsfStringHandle right_action, 
                    MSF_UINT32 timeout, 
                    bra_action_handle_t callback);

/*
 * Displays a modal status message that can not be dismised by the user.
 * The dialog is closed by calling the bra_dlg_notificationDialogClose function
 * This dialog is typically used to display a status message while saving or 
 * processing some time consuming event.
 *
 * PARAMETERS
 *
 * text      : The text to be displayed in the dialog
 * in_focus  : A pointer to a function which will be called each time the dialog
 *             gets focus.
 *
 * RETURN    : void
 */
void 
bra_dlg_create_status_dlg (MsfStringHandle text, bra_win_in_focus_t in_focus);

/*
 * This function closes the above described dialog
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_dlg_status_dialog_close (void);

/*
 * This function create a input dialog with one input field. The Callback
 * is responsible for validating the input. If the callback returns 1 the 
 * dialog will be dismised. If for some reason the input is determined to 
 * be invalid the callback might raise a error dialog and return 0.
 * 
 * NOTE! It is the callers responsibility to free the response if, and only if,
 * the callback returns 1
 *
 * PARAMETERS
 *
 * title       : Dialog title
 * text_type   : Input field text type (MsfTextType)
 * detault_text: Default text in the input field
 * max_n_chars : Max number of character the user are allowed to enter
 * callback    : Function which will handle the responce
 *
 * RETURN      : void
 */
void
bra_dlg_create_input_form(MsfStringHandle title, 
                          MsfTextType text_type, 
                          MsfStringHandle detault_text, 
                          int max_n_chars, 
                          bra_dlg_input_response_t callback);

/*
 * This function creates an option group from where the user can select one item.
 * The index of the selected item is returned in the callback. If no item where 
 * selected the callback return -1.
 *
 * PARAMETERS
 *
 * title     : Dialog title
 * n_options : Number of options in the group
 * opt_list  : Array of item string indexes 
 * selected  : Index of the pre-selected item.
 * callback  : Function which will handle the response
 *
 * RETURN    :
 */
void
bra_dlg_create_opt_menu (MsfStringHandle title, 
                         int n_options, 
                         const int opt_list[],
                         int selected,
                         bra_dlg_opt_response_t callback);

MsfStringHandle
bra_dlg_top_dialog_text(void);

void 
bra_dlg_set_dialog_callback(bra_action_handle_t callback);

bra_action_handle_t
bra_dlg_get_dialog_callback(void);

#endif


