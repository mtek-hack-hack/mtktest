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
 * bra_win.h
 *
 * Created by Tomas Mandorf	20020912	13:18
 * 
 * Description:
 *		This file contains code to handle windows in the bra 
 *    module. All windows are stored on a stack. When a new 
 *    window is opened a call to bra_win_show_window is made.
 *    This function then call the create function enclosed as 
 *    a parameter. To close a window (one or many) the 
 *    bra_win_close_window is called. this function closes 
 *    all windows until the close method specified in the
 *    function parameter is fulfiled.
 *     
 *    The four different close methods described below
 *    
 *    BRA_WIN_CLOSE_CURRENT:
 *        Closes the current window and sets previous in focus.
 *   
 *    BRA_WIN_CLOSE_ID:
 *        Closes the window with the specific ID but keeps all other
 *        windows.
 *   
 *    BRA_WIN_CLOSE_TO_ID
 *       Closes all windows until the top window matches the 
 *        ID parameter. Only the window with matching ID is set
 *        in focus. 
 *   
 *    BRA_WIN_CLOSE_ALL
 *        Closes all windows and do not set a new window in focus
 *    
 *    
 *    NOTE! Dialogs is not handled by this functionality
 */

#ifndef _bra_win_h
#define _bra_win_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif


/******************************************************************************
 * Definitions
 *****************************************************************************/

/*Window ID*/
enum{
BRA_WIN_ID_INSE,
BRA_WIN_ID_BKM_MAIN,
BRA_WIN_ID_BKM_SELECT,
BRA_WIN_ID_BKM_MANAGE,
BRA_WIN_ID_DLG_TITLE_URL_FORM,
BRA_WIN_ID_DLG_STATUS_DLG,
BRA_WIN_ID_DLG,
BRA_WIN_ID_SET_SETTINGS_DLG,
BRA_WIN_ID_SET_CONNECTION_DLG,
BRA_WIN_ID_SET_CONN_TYPE_DLG,
BRA_WIN_ID_OPT,
BRA_WIN_ID_VIEWPORT,
BRA_WIN_ID_URL_FORM,
BRA_WIN_ID_DLG_INPUT_DLG,
BRA_WIN_ID_SET_DISPLAY_OPT_DLG,
BRA_WIN_ID_DLG_OPT_MENU,
BRA_WIN_ID_SEC_MENU,
BRA_WIN_ID_STATUS_DLG,
BRA_WIN_ID_CKS_MENU,
BRA_WIN_ID_PUSH_MENU,
BRA_WIN_ID_CACHE,
BRA_WIN_ID_PROFILE_MENU,
BRA_WIN_ID_SET_NET_ID_DLG,
BRA_WIN_ID_PROFILE_SELECT_MENU,
BRA_WIN_ID_RPL_MAIN,
BRA_WIN_ID_RPL_OPT,
BRA_WIN_ID_AUTH_DLG,
BRA_WIN_ID_OFLN_MAIN,
BRA_WIN_ID_OFLN_MANAGE

/* This comment is part of an example to add a File Browser option to 
 * the BRA Options menu.
 * The full example is described in the BRA Reference Manual 
 *
 * Ex: 3.1
 *
 * 1. Add a new window ID here.
 *
 * BRA_WIN_ID_FILE_BROWSER 
 */

/*Add new windows here*/
,BRA_WIN_ID_PROFILE_EDIT_MENU
,BRA_WIN_ID_PUSH_MSG_LIST_DLG
,BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG
,BRA_WIN_ID_PUSH_MSG_OPT_DLG
,BRA_WIN_ID_PUSH_MSG_DLG
,BRA_WIN_ID_SELECT_URL_MENU
,BRA_WIN_ID_NET_BEARER_MENU
,BRA_WIN_ID_STK_AUTH_DLG
,BRA_WIN_ID_SEC_DLG
,BRA_WIN_ID_SEC_CERT_OPT_DLG
,BRA_WIN_ID_BRS_DLG
,BRA_WIN_ID_PROFILE_CUSTOM_MENU
,BRA_WIN_ID_NET_ID_SELECT_MENU
,BRA_WIN_ID_SLCT_MENU
,BRA_WIN_ID_SELECT_URL_OPT_MENU
,BRA_WIN_ID_BKM_SEND_MENU
,BRA_WIN_ID_RPL_VIEW_URL
,BRA_WIN_ID_VIEW_URL
,BRA_WIN_ID_VIEW_URL_SEND
,BRA_WIN_ID_PUSH_SETTING
,BRA_WIN_ID_PUSH_TRUSTLIST
,BRA_WIN_ID_PUSH_TRUSTLIST_ADD
,BRA_WIN_ID_PUSH_TRUSTLIST_EDIT
,BRA_WIN_ID_PUSH_TRUSTLIST_INPUT

#ifdef BRA_CFG_CCA
,BRA_WIN_ID_CCA_PROF_INFO_MENU
,BRA_WIN_ID_CCA_PROF_SELECT_MENU
#endif /* BRA_CFG_CCA */

#ifdef BRA_CFG_DUAL_SIM
, BRA_WIN_ID_SELECT_SIM_MENU
, BRA_WIN_ID_EDIT_SIM_MENU
#endif /* BRA_CFG_DUAL_SIM */

,BRA_WIN_ID_MAX_ITEM

};

/*Close methods*/
#define BRA_WIN_CLOSE_CURRENT     0x0001
#define BRA_WIN_CLOSE_ID          0x0002
#define BRA_WIN_CLOSE_TO_ID       0x0003
#define BRA_WIN_CLOSE_ALL         0x0004
#define BRA_WIN_CLOSE_TO_ID_FORCE 0x0005

/******************************************************************************
 * Types
 *****************************************************************************/
/*Base type for a window*/
typedef struct win 
{
  MsfWindowHandle win_hdl;
} bra_win_t;

typedef void (*bra_win_destroy_window_t)(bra_win_t *win);
typedef void (*bra_win_in_focus_t)(bra_win_t *win);
typedef void (*bra_win_action_handle_t)(bra_win_t *win, MSF_UINT32 action);

typedef void (*bra_screen_action_handle_t)(void);
typedef void (*bra_win_widget_notify_handle_t)(bra_win_t* win, MsfNotificationType type);

/******************************************************************************
 * Functions
 *****************************************************************************/

/*
 * Function initializes the window stack.
 *
 * PARAMETERS
 *
 * screen    : The screen handle to add all windows to
 *
 * RETURN    : void
 */
void
bra_win_init (MsfScreenHandle screen);

/*
 * Function destroy the window stack and forces all open windows to close.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_win_destroy (void);

/*
 * This function returns the currently used screen handle
 *
 * PARAMETERS
 *
 * RETURN    : Handle to screen
 */
MsfScreenHandle
bra_win_get_screen (void);

/*
 * Function adds the window to screen and puts it on top of the stack.
 * after the window is created and displayed the "in focus" function 
 * is called. Every time the window gains foucus this functionis called.
 *
 * PARAMETERS
 *
 * id        : Uniqe id for the window
 * win       : Window structure. (Must be derived from bra_win_t)
 * pos       : The position of the window
 * destroy   : Pointer to destroy function
 * in_focus  : Pointer to function to call when the functions gets focus
 *
 * RETURN    : Return 1 if success else 0
 */
int
bra_win_show_window (int id, 
                    bra_win_t *win, 
                    MsfPosition *pos, 
                    bra_win_destroy_window_t destroy, 
                    bra_win_in_focus_t in_focus,
                    bra_win_action_handle_t action_hdl);

/*
 * Function closes window(s) as specified by method and removes window(s) from stack
 * The in_focus function of the new current window is caled
 *
 * PARAMETERS
 *
 * method    : Close method as described above
 * id        : Used if method BRA_WIN_CLOSE_TO_ID or BRA_WIN_CLOSE_ID, else ignored
 *
 * RETURN    : 1 if successful else 0
 */
int
bra_win_close_window (int method, int id);

/*
 * This function returnes a pointer to the window stuct currently on top of the stack.
 * If no matching window exists NULL is returned;
 *
 * PARAMETERS
 *
 * id        : Window Id
 *
 * RETURN    : Pointer to a window structure
 */
bra_win_t *
bra_win_get_window (int id);

/*  
 *  This function handles actions by sending them to the window specified by window 
 *  
 *  PARAMETERS:
 *
 *  action   : Action to be handled
 *  window   : Window to send the action to
 *
 *  RETURN   : 1 if handled else 0
 */
int
bra_win_handle_action (MSF_UINT32 action, MSF_UINT32 window);

/*
 * Handles and dispatches actions that have been atached to the screen using the 
 * below functions
 *
 * PARAMETERS
 *
 * action    : MsfActionType
 * screen    : Screen handle
 *
 * RETURN    : 1 if dispatched else 0
 */
int
bra_win_screen_handle_action(MSF_UINT32 action, MSF_UINT32 screen);

/*
 * This fuction adds a action to the screen and calles the callback if this action occurs.
 * Note that only one action of each type can be assigned to the screen at once. If an
 * action already have been added this call will be ignored
 * 
 * PARAMETERS
 *
 * label     : Label to be used with the action (used if possible)
 * type      : The msfActionType
 * callback  : fuction to be called when this action occure
 *
 * RETURN    : void
 */
void
bra_win_add_screen_action (MsfStringHandle label, int type, bra_screen_action_handle_t callback);

/*
 * This function removes the action with type type from the screen.
 *
 * PARAMETERS
 *
 * type      : MsfActionType to remove
 *
 * RETURN    : void
 */
void
bra_win_delete_screen_action (int type);

/*
 * This function disables the window handler to set new windows in focus.
 * 
 * PARAMETERS
 *
 * type      : MsfActionType to remove
 *
 * RETURN    : void
 */
void
bra_win_disable_focus (void);

/*
 * This function enables the window handler to set new windows in focus
 * after this has been disabled. The window currently on top is set in
 * focus.
 * 
 * PARAMETERS
 *
 * type      : MsfActionType to remove
 *
 * RETURN    : void
 */
void
bra_win_enable_focus (void);

MSF_BOOL
bra_win_any_win_exists(void);

int 
bra_win_current_window(void);

/*
 * This function registers a menu item highlight callback routine
 * 
 * PARAMETERS
 *
 * whdl      : MsfWindowHandle window (should be of type MsfMenu or option groups)
 * callback  : menu item highlight callback routine
 *
 * RETURN    : void
 */
void
bra_win_register_notify (MsfWindowHandle whdl, bra_win_widget_notify_handle_t callback);

/*
 * This function deregisters the menu item highlight callback
 *  * 
 * PARAMETERS
 *
 * whdl      : MsfWindowHandle window (should be of type MsfMenu or option groups)
 *
 * RETURN    : void
 */
void
bra_win_deregister_notify (MsfWindowHandle whdl);

/*
 * This function process the MSF_SIG_WIDGET_NOTIFY signal and exec pre-registered callback routine
 * 
 * PARAMETERS
 *
 * whdl      : MsfWindowHandle window (should be of type MsfMenu or option groups)
 *
 * RETURN    : void
 */
void
bra_win_handle_notify (MsfWindowHandle whdl, MsfNotificationType type);


/*
 * This function maps the MsfWindowHandle to BRA Window object
 * 
 * PARAMETERS
 *
 * whdl      : MsfWindowHandle window
 *
 * RETURN    : void
 */
bra_win_t*
bra_win_find_win (MsfWindowHandle whdl);


/*
 * This function finds if bra_win_stack contains any windows apart from viewport
 *
 * RETURN    : int
 */
int
bra_win_non_viewport_win_exists(void);


#endif


