/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#ifndef _stk_dlg_h
#define _stk_dlg_h

/* Authorization Type */
#define STK_AUTH_SERVER                                       1
#define STK_AUTH_PROXY                                        2

/* Authorization Warnings*/
#define STK_AUTH_WARNING_NON_SECURE                           1

/* Authorization Options */
#define STK_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD           1
#define STK_AUTH_OPTIONS_SAVE_USERNAME                        2


/* Called during intialisation of the STK module */
void
stk_dlg_init(void);

/* Called during termination of the STK module */
void
stk_dlg_terminate(void);



/* Prompt the user with a password dialog 
 *   modid     : identifier to be passed back in stk_dlg_auth_credentials 
 *   requestId : identifier to be passed back in stk_dlg_auth_credentials 
 *   authType  : authorization type 
 *   realm     : string containing the realm
 *   username  : string containing the username if available.
 *   warnings  : warnings associated with this operation
 */
void
stk_dlg_request_auth (MSF_UINT8 modId, int requestId, int authType, 
                      const char *realm, const char* username, int warnings);


/* The stack has received a widget signal 
 *  widget_action : the widget action
 */
void
stk_dlg_widget_action (msf_widget_action_t *widget_action);


/* Respond with auth credentials
 *   modid     : passed back identifier
 *   requestId : passed back identifier
 *   username  : string containing the username, NULL if no username was received
 *   password  : string containing the password, NULL if no password was received
 *   options   : authorization options
 */
void
stk_dlg_auth_credentials (MSF_UINT8 modId, int requestId, const char *username, 
                          const char *password, int options);

#endif
