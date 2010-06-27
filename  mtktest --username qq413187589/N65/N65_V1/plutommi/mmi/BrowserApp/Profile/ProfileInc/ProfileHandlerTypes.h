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
 * ProfileHandlerTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the structures ,enum,varaibles etc used by the profile handler module
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PROFILEHANDLERTYPES_H
#define _PROFILEHANDLERTYPES_H

#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_nvram_editor_data_item.h"
#include "SettingProfile.h"

#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__

#define MAX_INLINE_ITEM_EDIT_PROFILE_LIST       (12)
// #define  MAX_BYTE_NEEDED                                                     (129)
#define MAX_CONN_TYPE                        (3)
#define MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST        (4)

#define MAX_IP_ADDRES_LEN                    (4)
#define PROF_MAX_DATAACCOUNT_NAME               (31)

#define BRW_PROF_DCS_ASCII                   (0x00)
#define BRW_PROF_DCS_UCS                     (0x01)
#define BRW_PROF_USHORT_MAX                     (65536)

#define BRW_NO_PROVISIONING                     (0x00)
#define BRW_PROV_BROWSER_ONLY                (0x01)
#define BRW_PROV_MMS_ONLY                    (0x02)

#define PROF_GSM_SUPPORT
#define PROF_GPRS_SUPPORT
#define PROF_NONE_SUPPORT

typedef enum
{
#ifdef PROF_GSM_SUPPORT
    bearer_gsm,
#endif 
#ifdef PROF_GPRS_SUPPORT
    bearer_gprs,
#endif 
#ifdef __WIFI_SUPPORT__
    bearer_wifi,
#endif 
#ifdef PROF_NONE_SUPPORT
    bearer_none
#endif 
} prof_bearer_enum;

typedef enum
{
    BRW_PROF_NAME_STR = 0,
    BRW_PROF_NAME,
    BRW_PROF_HOMEPAGE_STR,
    BRW_PROF_HOMEPAGE,
    BRW_PROF_DATA_ACCOUNT_STR,
    BRW_PROF_DATA_ACCOUNT,
    BRW_PROF_CONN_TYPE_STR,
    BRW_PROF_CONN_TYPE,
    BRW_PROF_USER_NAME_STR,
    BRW_PROF_USER_NAME,
    BRW_PROF_USER_PASSWORD_STR,
    BRW_PROF_USER_PASSWORD
} prof_inline_item_enum;

typedef enum
{
    BRW_PROF_CONN_TYPE_IP_ADDRESS_STR = 0,
    BRW_PROF_CONN_TYPE_IP_ADDRESS,
    BRW_PROF_CONN_TYPE_SECURITY_STR,
    BRW_PROF_CONN_TYPE_SECURITY
} prof_conn_type_edit_enum;

typedef enum
{
    BRW_PROF_CONN_TYPE_HTTP = 1,
    BRW_PROF_CONN_TYPE_CONNECTION_OREINTED,
    BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE
} prof_conn_type_enum;

typedef enum
{
    BRW_PROF_MENU_CONNECTION_OREINTED = 0,
    BRW_PROF_MENU_HTTP,
    BRW_PROF_MENU_WIFI
} prof_higl_conn_type_enum;

typedef enum
{
    BRW_PROF_BROWSER_PROFILE = 0,
    BRW_PROF_MMS_PROFILE = 1,
    BRW_PROF_BROWSER_PROV_PROFILE,
    BRW_PROF_MMS_PROV_PROFILE,
    BRW_PROF_PROFILE_MAX
} prof_profile_enum;

typedef enum
{
    BRW_PROF_DATA_ACCOUNT_CSD = 0,
    BRW_PROF_DATA_ACCOUNT_GPRS,
    BRW_PROF_DATA_ACCOUNT_WIFI,
    BRW_PROF_DATA_ACCOUNT_NONE,
    BRW_PROF_DATA_ACCOUNT_INVALID = 0xFF
} prof_data_account_enum;

typedef enum
{
    BRW_PROF_PROFILE_SUCCESS,
    BRW_PROF_PROFILE_NOT_READY,
    BRW_PROF_PROFILE_BUSY,
    BRW_PROF_PROFILE_INVALID_ID
} prof_error_enum;

typedef struct
{
    U8 proxy_port[(5 + 1) *ENCODING_LENGTH];
    U8 profile_name[(NVRAM_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 url[(NVRAM_PROFILE_URL_LEN + 1) *ENCODING_LENGTH];
    U8 IP1[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP2[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP3[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP4[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 username[(NVRAM_PROFILE_USERNAME_LEN + 1) *ENCODING_LENGTH];
    U8 password[(NVRAM_PROFILE_PASSWORD_LEN + 1) *ENCODING_LENGTH];
    U8 *security_option[2];
    S32 security_opt_index;
    U8 data_account_name[(PROF_MAX_DATAACCOUNT_NAME + 1) *ENCODING_LENGTH];
    U8 data_account_name_primary[(PROF_MAX_DATAACCOUNT_NAME + 1) *ENCODING_LENGTH];
    U8 data_account_name_secondary[(PROF_MAX_DATAACCOUNT_NAME + 1) *ENCODING_LENGTH];
    U8 data_account;
} profile_content_struct;

typedef struct
{
    profile_content_struct *profile_display_p;
    U8 profile_module;
    U8 profile_index;
    U8 profile_count1;
    U8 prov_flag;
    U8 prov_activate_profile_flag;
    U8 setting_installed;
    U8 actived_profile_content_index[2];
    U8 actived_profile_name_index[2];
    U8 content_index_array[NVRAM_PROFILE_MAX];
	 pBOOL active_profile_modified;
	pBOOL active_profile_deleted;
} profile_context_struct;

extern profile_context_struct g_prof_cntx;

extern nvram_profile_content_struct *g_prof_profile_content_p[2];
extern nvram_profile_content_struct *g_prof_activated_profile_content[2];
extern nvram_profile_name_array_struct *g_prof_name_arr_p[2];

#define BRW_PROF_DEFAULT_CONN_TYPE                 BRW_PROF_CONN_TYPE_HTTP
#define BRW_PROF_DEFAULT_DATA_ACCOUNT_PRIMARY_ID      0
#define BRW_PROF_DEFAULT_DATA_ACCOUNT_SECONDARY_ID    -1

#define BRW_PROF_DEFAULT_WAP_PROFILE_NAME          "Profile1"
#define BRW_PROF_DEFAULT_MMS_PROFILE_NAME          "Profile1"
#define BRW_PROF_DEFAULT_URL_NAME                  "http://"
#define BRW_PROF_DEFAULT_URL_SIZE				   strlen(BRW_PROF_DEFAULT_URL_NAME)
#define BRW_PROF_DEFAULT_USERNAME                  ""
#define BRW_PROF_DEFAULT_PASSWORD                  ""
#define  BRW_PROF_DEFAULT_IP1                   0
#define  BRW_PROF_DEFAULT_IP2                   0
#define  BRW_PROF_DEFAULT_IP3                   0
#define  BRW_PROF_DEFAULT_IP4                   0

#define BRW_PROF_DEFAULT_PROXY_PORT                0

#define MAX_DEFAULT_PROFILE                        5
#define BRW_PROF_READ_ONLY                      1
#define BRW_PROF_READ_WRITE                        2

#define MMI_DM_PROF_DEFAULT_PORTNBR				80     
#define MMI_DM_PROF_DEFAULT_CONN_TYPE			BRW_PROF_CONN_TYPE_HTTP
#define MMI_DM_PROF_DEFAULT_PRIMARY_ID			10
#define MMI_DM_PROF_DEFAULT_SECONDARY_ID		BRW_PROF_DEFAULT_DATA_ACCOUNT_SECONDARY_ID


#endif /* __MMI_BROWSER_2__ */ 

#endif /* _PROFILEHANDLERTYPES_H */ 

