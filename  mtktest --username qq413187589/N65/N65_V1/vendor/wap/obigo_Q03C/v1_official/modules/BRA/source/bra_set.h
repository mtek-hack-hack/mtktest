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
 * bra_set.h
 *
 * Description:
 *		This file contains code to handle all BRA settings.
 *
 */


#ifndef _bra_set_h
#define _bra_set_h

#ifndef _stk_if_h
#include "stk_if.h"
#endif

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#include "bra_int.h"
#endif

#define BRA_SET_CONNECTION_TYPE_HTTP      STK_CONNECTION_TYPE_HTTP 
#define BRA_SET_CONNECTION_TYPE_WSP_CL    STK_CONNECTION_TYPE_WSP_CL 
#define BRA_SET_CONNECTION_TYPE_WSP_CO    STK_CONNECTION_TYPE_WSP_CO

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
typedef enum
{
    BRA_TRUSTLIST_STATE_NULL,
    BRA_TRUSTLIST_STATE_SETTOPHS,
    BRA_TRUSTLIST_STATE_USERSELECT,
    BRA_TRUSTLIST_STATE_OUT_ADDITEM
} bra_set_trustlist_state_t;
#endif


/*
 * This function creates the main settings menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_settings_menu (void);

/*
 * This function creates the main profile edit menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_profile_edit_menu (void);

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
/*
 * This function for other module add new trust list item and set the lists to PHS
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_push_trustList_addItem(char *address, MSF_UINT8 type);

/*
 * This function init trust list and set the lists to PHS
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_push_trustList_init(bra_set_trustlist_state_t state);


#endif

int
check_ip(char *s);

#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN
void
bra_set_handle_net_id_select_response(void *rsp);
#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/



#endif /*_bra_set_h*/

