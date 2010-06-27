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
 * bra_req.h
 *
 * Description:
 *		This file contains code to enter and manage urls and to use 
 *    the BRS module to request those urls .
 */


#ifndef _bra_req_h
#define _bra_req_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

typedef int (*bra_req_url_response_t)(char* url);

int
bra_req_edit_url_response(char *url);

/*
 * This function creates a Url input field and a list of previously 
 * entered addresses. When the user presses accept the entered or
 * selected key is requested using send request. If the user presses
 * Cancel key the window is closed.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_create_url_form(char *defStr, bra_req_url_response_t callback, int close_to_id); 

/*
 * Initializes the history list (list of previously entered adresses)
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void 
bra_req_init_address_list (void);

/*
 * Free resources allocated for the above list
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_req_destroy_address_list (void);

/*
 * This function frees the memory used to hold a pending request
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_req_clear_pending_req_url (void);

/*
 * This function return the URL of a curently pending send request
 * If there are not pending requests the function return NULL
 *
 * PARAMETERS
 *
 * RETURN    :URL to pending request or NULL
 */
char *
bra_req_get_request_url (void);

/*
 * This function initializes the resources (e.g. start BRS module )  
 * needed to maka a request for the specific url and then make the 
 * request for that url.
 *
 * PARAMETERS
 *
 * URL       : Requested URL
 *
 * RETURN    : void
 */
void
bra_send_request(char* URL);

int
check_url(char *s);

char*
bra_req_get_address_item(int i);

void
bra_create_select_url_menu (void);


void
bra_req_init_request_url(void);

#endif

