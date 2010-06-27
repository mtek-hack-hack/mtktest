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
/*
 * stk_rc.h
 *
 * Description: This file implement the recources needed by the 
 *              STK module.
 */
#ifndef _stk_rc_h
#define _stk_rc_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif


#define STK_NUMBER_OF_STRINGS 0x0A

extern const char * const stk_strings[][STK_NUMBER_OF_STRINGS+1];


#ifndef WAP_SUPPORT
#define STK_STR_ID_OK             (MSF_MODID_STK +  + 0x0100) /*"Ok"*/
#define STK_STR_ID_EXIT           (MSF_MODID_STK +  + 0x0200) /*"Exit"*/
#define STK_STR_ID_TITLE_SERVER   (MSF_MODID_STK +  + 0x0300) /*"Enter Server Password"*/
#define STK_STR_ID_TITLE_PROXY    (MSF_MODID_STK +  + 0x0400) /*"Enter Proxy Password"*/
#define STK_STR_ID_USERNAME       (MSF_MODID_STK +  + 0x0500) /*"UserName:"*/
#define STK_STR_ID_PASSWORD       (MSF_MODID_STK +  + 0x0600) /*"Password:"*/
#define STK_STR_ID_REALM_LABEL    (MSF_MODID_STK +  + 0x0700) /*"Realm:"*/
#define STK_STR_ID_NON_SECURE     (MSF_MODID_STK +  + 0x0800) /*"Warning: Non-Secure"*/
#define STK_STR_ID_SAVE_PASSWORD  (MSF_MODID_STK +  + 0x0900) /*"Save Username and Password"*/
#define STK_STR_ID_SAVE_USERNAME  (MSF_MODID_STK +  + 0x0A00) /*"Save Username"*/
#endif
#include "wap.h"

#endif
