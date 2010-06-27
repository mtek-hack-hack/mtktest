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

/*******************************************************************************
 * Filename:
 * ---------
 * ProfileHandlerResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This defines the String ,screen,& Image ID for profile handler module
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef PROFILEHANDLERDEFS_H
#define PROFILEHANDLERDEFS_H

#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__
#include "BrowserResDef.h"

typedef enum
{
    STR_ID_PROF_HDLR_SELECT_PROF_CAPTION = BROWSER_PROVISIONING_BASE + 1,
    STR_ID_PROF_HDLR_ACTIVATE_PROFILE,
    STR_ID_PROF_HDLR_EDIT_PROFILE,
    STR_ID_PROF_HDLR_VIEW_PROFILE,
    STR_ID_PROF_HDLR_DELETE_PROFILE,
    STR_ID_PROF_HDLR_RENAME_PROFILE,
    STR_ID_PROF_HDLR_HOMEPAGE,
    STR_ID_PROF_HDLR_DATA_ACCOUNT,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_PRIMARY,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_SECONDARY,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_GSM,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_GPRS,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_WIFI,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_BEARER_NONE,
    STR_ID_PROF_HDLR_CONN_TYPE,
    STR_ID_PROF_HDLR_USER_NAME,
    STR_ID_PROF_HDLR_PASSWORD,
  //  STR_ID_PROF_HDLR_SAVED,
    STR_ID_PROF_HDLR_CONN_TYPE_WAP,
    STR_ID_PROF_HDLR_CONN_TYPE_HTTP,
 //   STR_ID_PROF_HDLR_CONN_TYPE_WIFI,
    STR_ID_PROF_HDLR_IP_ADDRESS,
    STR_ID_PROF_HDLR_PROXY_ADDRESS,
    STR_ID_PROF_HDLR_SECURITY,
    STR_ID_PROF_HDLR_PORT,
    STR_ID_PROF_HDLR_OFF,
    STR_ID_PROF_HDLR_ON,
    STR_ID_PROF_HDLR_MMSC_URL,
    STR_ID_PROF_HDLR_PROFILE,
    STR_ID_PROF_HDLR_INVALID_INPUT,
    STR_ID_PROF_HDLR_INVALID_IP,
    STR_ID_PROF_HDLR_DATA_ACCOUNT_ERROR,
    STR_ID_PROF_HDLR_INVALID_URL_ERROR,
    STR_ID_PROV_HDLR_PERMISSION_DENIED,
	STR_ID_PROF_HDLR_ADD_NEW
} str_profile_handler_list_enum;

typedef enum
{
    SCR_ID_PROF_HDLR_PROF_LIST = BROWSER_PROVISIONING_BASE + 1,
    SCR_ID_PROF_HDLR_SELECTED_PROFILE,
    SCR_ID_PROF_HDLR_EDIT_PROFILE,
    SCR_ID_PROF_HDLR_VIEW_PROFILE,
    SCR_ID_PROF_HDLR_CONFIRMATION,
    SCR_ID_PROF_HDLR_CONN_TYPE,
    SCR_ID_PROF_HDLR_EDIT_CONN_TYPE,
    SCR_ID_PROF_HDLR_DATA_ACCOUNT,
    SCR_ID_PROF_HDLR_DATA_ACCOUNT_TYPE
} scr_profile_handler_list_enum;

typedef enum
{
    IMD_ID_PROF_HDLR_SELECT_PROF_CAPTION = BROWSER_PROVISIONING_BASE + 1,
    IMG_ID_PROF_HDLR_SET_ACTIVATED_PROFILE,
    IMG_ID_PROF_HDLR_INVALID_INPUT
} img_profile_handler_list_enum;

#endif /* __MMI_BROWSER_2__ */ 

#endif /* PROFILEHANDLERDEFS_H */ 

