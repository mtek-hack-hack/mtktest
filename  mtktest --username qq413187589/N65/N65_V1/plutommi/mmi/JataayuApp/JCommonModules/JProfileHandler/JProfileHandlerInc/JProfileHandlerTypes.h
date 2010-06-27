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
 * JProfileHandlerTypes.h
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

#ifndef _JPROFILEHANDLERTYPES_H
#define _JPROFILEHANDLERTYPES_H

#include "MMI_features.h"
#include "MMIDataType.h"

#if defined (JATAAYU_SUPPORT)

#define MAX_INLINE_ITEM_EDIT_PROFILE_LIST          (12) /* dara fix the size ....just added */
#define MAX_SUB_MENUS_REQUIRED                     (2)
#define MAX_CONN_TYPE                           (3)
#define MAX_INLINE_ITEM_EDIT_CONN_TYPE_LIST           (4)

#define MAX_IP_ADDRES_LEN                       (4)
#define PH_MAX_DATAACCOUNT_NAME                    (31)

#define PH_DCS_ASCII                         (0x00)
#define PH_DCS_UCS                              (0x01)
#define PH_DCS_ASCII_UCS                              (0x02)
#define PH_USHORT_MAX                           (65536)
/* Itishree Adds */
#define PH_MAX_PROXY_PORT_LENGTH            6

typedef enum
{
    PH_PROFILE_NAME_STR = 0,
    PH_PROFILE_NAME,
    PH_PROFILE_HOMEPAGE_STR,
    PH_PROFILE_HOMEPAGE,
    PH_PROFILE_DATA_ACCOUNT_STR,
    PH_PROFILE_DATA_ACCOUNT,
    PH_PROFILE_CONN_TYPE_STR,
    PH_PROFILE_CONN_TYPE,
    PH_PROFILE_USER_NAME_STR,
    PH_PROFILE_USER_NAME,
    PH_PROFILE_USER_PASSWORD_STR,
    PH_PROFILE_USER_PASSWORD
} ph_inline_item_enum;

typedef enum
{
    PH_CONN_TYPE_IP_ADDRESS_STR = 0,
    PH_CONN_TYPE_IP_ADDRESS,
    PH_CONN_TYPE_SECURITY_STR,
    PH_CONN_TYPE_SECURITY
} ph_conn_type_edit_enum;

typedef enum
{
    PH_CONN_TYPE_HTTP = 1,
    PH_CONN_TYPE_CONNECTION_OREINTED,
    PH_CONN_TYPE_CONNECTION_OREINTED_SECURE
} ph_conn_type_enum;

typedef enum
{
    PH_MENU_CONNECTION_OREINTED = 0,
    PH_MENU_HTTP
} ph_higl_conn_type_enum;

typedef enum
{
    PH_PROFILE_NULL = 0,
    PH_BROWSER_PROFILE,
    PH_MMS_PROFILE,
    PH_BROWSER_PROV_PROFILE,
    PH_MMS_PROV_PROFILE
} ph_profile_enum;

typedef enum
{
    PH_DATA_ACCOUNT_CSD = 0,
    PH_DATA_ACCOUNT_GPRS,
    PH_DATA_ACCOUNT_INVALID = 0xFF
} ph_data_account_enum;

typedef enum
{
    PH_PROFILE_SUCCESS
} ph_profile_error_enum;

typedef struct
{
    U8 proxy_port[PH_MAX_PROXY_PORT_LENGTH *ENCODING_LENGTH];
    U8 profile_name[(NVRAM_WAP_PROFILE_NAME_LEN) *ENCODING_LENGTH];
    U8 homepage_url[(NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN) *ENCODING_LENGTH];
    U8 ip1[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 ip2[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 ip3[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 ip4[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 username[(NVRAM_WAP_PROFILE_USERNAME_LEN) *ENCODING_LENGTH];
    U8 password[(NVRAM_WAP_PROFILE_PASSWORD_LEN) *ENCODING_LENGTH];
    U8 *security_option[2];
    S32 security_opt_index;
    U8 data_account_name[(PH_MAX_DATAACCOUNT_NAME) *ENCODING_LENGTH];
    U8 data_account;
} ph_show_editable_profile_struct;

typedef struct
{
    ph_show_editable_profile_struct *profile_display_p;
    U8 profile_module;
    U8 profile_index;
    U8 wap_actived_profile_index;
    U8 mms_actived_profile_index;
    U8 ph_data_account;
    U8 ph_dataaccount_index;
    U8 data_account_type;
    U16 ph_title_img_id;
    MMI_BOOL ph_initialised;
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    nvram_wap_profile_content_struct *ph_wap_profile_p;
    nvram_wap_profile_content_struct *ph_activated_wap_profile;
    nvram_wap_profile_name_array_struct *ph_wap_prof_name_arr_p;
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
    nvram_mms_profile_content_struct *ph_mms_profile_p;
    nvram_mms_profile_content_struct *ph_activated_mms_profile;
    nvram_mms_profile_name_array_struct *ph_mms_prof_name_arr_p;
} ph_context_struct;

extern ph_context_struct g_ph_cntx;

#endif /* defined (JATAAYU_SUPPORT) */ // #if defined (JATAAYU_SUPPORT)
#endif /* _JPROFILEHANDLERTYPES_H */ 

