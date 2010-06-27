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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * DataAccountEAP.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EAP modules implementations for Data Account WLAN authentication.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "DataAccountCommon.h"
#include "FileManagerGprot.h"
#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif
#ifdef __MMI_WLAN_FEATURES__

extern U8 wgui_inline_list_menu_changed;

static kal_bool user_info_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);
static void mmi_wlan_entry_user_cert_list_callback(void *filePath, int is_short);
static void mmi_wlan_entry_ca_cert_list_callback(void *filePath, int is_short);
static void mmi_wlan_entry_user_cert_list(void);
static void mmi_wlan_entry_ca_cert_list(void);
static void mmi_wlan_entry_private_key_list(void);
static void mmi_wlan_entry_private_key_list_callback(void *, int);
static void mmi_wlan_user_info_save(void);
static void mmi_wlan_user_info_fill_inline_struct(void);
static void mmi_wlan_entry_user_info(void);
static void mmi_wlan_eap_type_highlight_hdlr(S32 nIndex);

#ifdef WLAN_EAP_TTLS_SUPPORT
static void mmi_wlan_eap_ttls_settings_auth_type_ok(void);
static void mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr(S32 nIndex);
static void mmi_wlan_entry_eap_ttls_settings_auth_type(void);
static void mmi_wlan_eap_ttls_settings_save(void);
static void mmi_wlan_eap_ttls_settings_highlight_hdlr(S32 nIndex);
static void mmi_wlan_eap_ttls_settings_fill_inline_struct(void);
static void mmi_wlan_entry_eap_ttls_settings(void);
static kal_bool eap_ttls_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);
#endif /* WLAN_EAP_TTLS_SUPPORT */ 

#ifdef WLAN_EAP_PEAP_SUPPORT
static void mmi_wlan_eap_peap_settings_eap_type_ok(void);
static void mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr(S32 nIndex);
static void mmi_wlan_entry_eap_peap_settings_eap_type(void);
static void mmi_wlan_eap_peap_settings_save(void);
static void mmi_wlan_eap_peap_settings_highlight_hdlr(S32 nIndex);
static void mmi_wlan_eap_peap_settings_fill_inline_struct(void);
static void mmi_wlan_entry_eap_peap_settings(void);
static kal_bool eap_peap_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);
#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TLS_SUPPORT
static void mmi_wlan_eap_tls_settings_save(void);
static void mmi_wlan_eap_tls_settings_highlight_hdlr(S32 nIndex);
static void mmi_wlan_eap_tls_settings_fill_inline_struct(void);
static void mmi_wlan_entry_eap_tls_settings(void);
static kal_bool eap_tls_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);
#endif /* WLAN_EAP_TLS_SUPPORT */ 

static auth_plugin_struct g_wlan_auth_module[] = 
{
#ifdef WLAN_EAP_TLS_SUPPORT
    {WLAN_EAP_TLS, STR_ID_DTCNT_WLAN_EAP_TLS, mmi_wlan_entry_eap_tls_settings, eap_tls_profile_encoder},
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    {WLAN_EAP_MD5, STR_ID_DTCNT_WLAN_EAP_MD5, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    {WLAN_EAP_PEAP, STR_ID_DTCNT_WLAN_EAP_PEAP, mmi_wlan_entry_eap_peap_settings, eap_peap_profile_encoder},
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    {WLAN_EAP_TTLS, STR_ID_DTCNT_WLAN_EAP_TTLS, mmi_wlan_entry_eap_ttls_settings, eap_ttls_profile_encoder},
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    {WLAN_EAP_SIM, STR_ID_DTCNT_WLAN_EAP_SIM, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    {0, STR_ID_DTCNT_WLAN_EAP_FAST, NULL, NULL},
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    {WLAN_EAP_MSCHAV2, STR_ID_DTCNT_WLAN_EAP_MSCHAP2, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    {WLAN_EAP_GTC, STR_ID_DTCNT_WLAN_EAP_GTC, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_PAP_SUPPORT
    {WLAN_PAP, STR_ID_DTCNT_WLAN_PAP, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_CHAP_SUPPORT
    {WLAN_CHAP, STR_ID_DTCNT_WLAN_CHAP, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    {WLAN_MSCHAP, STR_ID_DTCNT_WLAN_MSCHAP, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    {WLAN_MSCHAPV2, STR_ID_DTCNT_WLAN_MSCHAP2, mmi_wlan_entry_user_info, user_info_profile_encoder},
#endif 
    {0, 0, NULL, NULL},
};

static U8 g_wlan_eap_types[] = 
{
#ifdef WLAN_EAP_TLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    WLAN_AUTH_TYPE_EAP_PEAP,
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TTLS,
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    WLAN_AUTH_TYPE_EAP_FAST,
#endif 
    WLAN_AUTH_TYPE_END
};

#define WLAN_EAP_TYPES_TOTAL sizeof(g_wlan_eap_types) - 1

#ifdef WLAN_EAP_PEAP_SUPPORT
static U8 g_wlan_eap_peap_types[] = 
{
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_TLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    WLAN_AUTH_TYPE_EAP_MD5,
#endif 
    WLAN_AUTH_TYPE_END
};

#define WLAN_EAP_PEAP_TYPES_TOTAL sizeof(g_wlan_eap_peap_types) - 1

#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TTLS_SUPPORT
static U8 g_wlan_eap_ttls_types[] = 
{
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_TLS_SUPPORT
    WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    WLAN_AUTH_TYPE_EAP_MD5,
#endif 
#ifdef WLAN_PAP_SUPPORT
    WLAN_AUTH_TYPE_PAP,
#endif 
#ifdef WLAN_CHAP_SUPPORT
    WLAN_AUTH_TYPE_CHAP,
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    WLAN_AUTH_TYPE_MSCHAP,
#endif 
    WLAN_AUTH_TYPE_END
};

#define WLAN_EAP_TTLS_TYPES_TOTAL sizeof(g_wlan_eap_ttls_types) - 1

#endif /* WLAN_EAP_TTLS_SUPPORT */ 

#define MMI_DTCNT_WIFI_FILE_LIMIT 100*1024

#ifdef __CERTMAN_SUPPORT__
void mmi_wlan_select_cert_rsp(void *rsp);
void mmi_wlan_select_user_cert_rsp(void *rsp);


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_select_user_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_select_user_cert_rsp(void *rsp)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    if(cert_rsp->result)
    {
        g_wlan_display_context.client_ca_id = cert_rsp->cert_ids[0];
        mmi_certman_get_cert_label(g_wlan_display_context.client_ca_id, (U8*)g_wlan_display_context.client_user_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);

        g_wlan_display_context.modified2 = TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_select_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]       
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_select_cert_rsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    if(cert_rsp->result)
    {
        g_wlan_display_context.root_ca_id = cert_rsp->cert_ids[0];
        mmi_certman_get_cert_label(g_wlan_display_context.root_ca_id, (U8*)g_wlan_display_context.root_ca_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
        g_wlan_display_context.modified2 = TRUE;
    }  
}

#endif /*__CERTMAN_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_auth_type_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  auth_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S8 *mmi_wlan_get_auth_type_name(U8 auth_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString(g_wlan_auth_module[auth_type].name_string_id);
}


/*****************************************************************************
 * FUNCTION
 *  export_private_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [?]         
 *  src                 [?]         
 *  len                 [IN]        
 *  profile_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool export_private_key(S8 *dest, S8 *src, int len, int profile_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filename[16];
    int ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(src) < 1)
    {
        memset(dest, 0, len);
        return KAL_TRUE;
    }

    sprintf(filename, "%c:\\%i%c", MMI_PUBLIC_DRV, profile_index, 'k');
    mmi_asc_to_ucs2((S8*) dest, filename);
    
    ret = FS_Move((const WCHAR *)src, (const WCHAR *)dest, FS_MOVE_COPY | FS_MOVE_OVERWRITE, 0, NULL, 0);
    
    if (ret != FS_NO_ERROR)
    {
        memset(dest, 0, len);
        return KAL_TRUE;
    }

    FS_SetAttributes((const WCHAR*)dest, FS_ATTR_HIDDEN);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  export_client_ca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [?]         
 *  src                 [?]         
 *  len                 [IN]        
 *  profile_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool export_client_ca(S8 *dest, S8 *src, int len, int profile_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filename[16];
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(src) > 0)
    {
        sprintf(filename, "%c:\\%i%c", MMI_PUBLIC_DRV, profile_index, 'c');
        mmi_asc_to_ucs2((S8*) dest, filename);

        ret = FS_Move((const WCHAR *)src, (const WCHAR *)dest, FS_MOVE_COPY | FS_MOVE_OVERWRITE, 0, NULL, 0);
        if (ret != FS_NO_ERROR)
        {
            memset(dest, 0, len);
            return KAL_TRUE;
        }
        FS_SetAttributes((const WCHAR*)dest, FS_ATTR_HIDDEN);
    }
    else
    {
        memset(dest, 0, len);
        return KAL_TRUE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  export_root_ca
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [?]         
 *  src                 [?]         
 *  len                 [IN]        
 *  profile_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool export_root_ca(S8 *dest, S8 *src, int len, int profile_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filename[16];
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(src) > 0)
    {
        sprintf(filename, "%c:\\%i%c", MMI_PUBLIC_DRV, profile_index, 'u');
        mmi_asc_to_ucs2((S8*) dest, filename);

        ret = FS_Move((const WCHAR *)src, (const WCHAR *)dest, FS_MOVE_COPY | FS_MOVE_OVERWRITE, 0, NULL, 0);
        if (ret != FS_NO_ERROR)
        {
            memset(dest, 0, len);
            return KAL_TRUE;
        }
        FS_SetAttributes((const WCHAR*)dest, FS_ATTR_HIDDEN);
    }
    else
    {
        memset(dest, 0, len);
        return KAL_TRUE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  encode_eap_profile
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool encode_eap_profile(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    prof->eap = profile->auth_type1;
    
    for (i = 0; i < WLAN_EAP_TYPES_TOTAL; i++)
    {
        if (profile->auth_type1 & (g_wlan_auth_module[g_wlan_eap_types[i]].val))
        {
            if (g_wlan_auth_module[g_wlan_eap_types[i]].encode_func != NULL)
            {
                if(g_wlan_auth_module[g_wlan_eap_types[i]].encode_func(prof, profile, 1) == KAL_FALSE)
                {
                    return KAL_FALSE;
                }
            }
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  user_info_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool user_info_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }

    if (prof->password_len == 0)
    {
        len = strlen((char*)profile->password);
        if (len > 0)
        {
            prof->password_len = len;
            memcpy(prof->password, profile->password, prof->password_len);
        }
        else
        {
            prof->password_len = 0;
        }
    }
    if (prof->anonymous_identity_len == 0 && profile->use_anonymous == KAL_TRUE)
    {
        prof->anonymous_identity_len = strlen(DEFAULT_ANONYMOUS_IDENTITY);
        strcpy((char *)prof->anonymous_identity, DEFAULT_ANONYMOUS_IDENTITY);
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_private_key_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_private_key_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.top_screen = GetActiveScreenId();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (S8*) L"root",
        mmi_wlan_entry_private_key_list_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_private_key_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_private_key_list_callback(void *filePath, int is_short)
{
#ifndef __CERTMAN_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_handle = 0;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle < 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
        
        FS_Close(file_handle);
        
        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy(g_wlan_display_context.private_key_path, (S8*) filePath);
        g_wlan_display_context.modified2 = TRUE;
    }

    GoBackToHistory(g_wlan_display_context.top_screen);
#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_cert_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    FMGR_FILTER filter;
#endif /* __CERTMAN_SUPPORT__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CERTMAN_SUPPORT__
    SetProtocolEventHandler(mmi_wlan_select_user_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    mmi_certman_select_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, FALSE, 0, MMI_CERTMAN_CERT_GROUP_PERSONAL);
#else
    g_wlan_display_context.top_screen = GetActiveScreenId();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (S8*) L"root",
        mmi_wlan_entry_user_cert_list_callback);

#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_cert_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_cert_list_callback(void *filePath, int is_short)
{
#ifndef __CERTMAN_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_handle = 0;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle < 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
        
        FS_Close(file_handle);
        
        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy(g_wlan_display_context.client_ca_path, (S8*) filePath);
        g_wlan_display_context.modified2 = TRUE;
    }

    GoBackToHistory(g_wlan_display_context.top_screen);
#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_ca_cert_list
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_ca_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    FMGR_FILTER filter;
#endif /* __CERTMAN_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CERTMAN_SUPPORT__

    SetProtocolEventHandler(mmi_wlan_select_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    mmi_certman_select_certificates_ind(MOD_MMI, MMI_CERTMAN_OPEN, FALSE, 0, MMI_CERTMAN_CERT_GROUP_ROOT_CA);
#else

    g_wlan_display_context.top_screen = GetActiveScreenId();
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_DATAACCOUNT,
        FMGR_SELECT_FILE,
        filter,
        (S8*) L"root",
        mmi_wlan_entry_ca_cert_list_callback);
    
#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_ca_cert_list_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_ca_cert_list_callback(void *filePath, int is_short)
{
#ifndef __CERTMAN_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 file_handle = 0;
     U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath != NULL)
    {
        file_handle = FS_Open(filePath,  FS_READ_ONLY);
        
        if(file_handle < 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_OPEN_FAIL),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
            return ;
        }
        
        FS_GetFileSize( file_handle, &file_size );
 
        FS_Close(file_handle);

        if(file_size >= MMI_DTCNT_WIFI_FILE_LIMIT)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_WLAN_ERROR_FILE_TOO_BIG),
                IMG_GLOBAL_ERROR,
                1,
                DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
            return;
        }
        /* copy source file path+name */
        mmi_ucs2cpy((S8*) g_wlan_display_context.root_ca_path, (S8*) filePath);
        g_wlan_display_context.modified2 = TRUE;
    }

    GoBackToHistory(g_wlan_display_context.top_screen);
#endif /* __CERTMAN_SUPPORT__ */
}

#ifdef WLAN_EAP_TTLS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_ttls_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_ttls_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_ttls_settings_auth_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_ttls_settings_auth_type_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_ttls_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_ttls_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    auth_settings_hdlr =
        g_wlan_auth_module[g_wlan_eap_ttls_types[g_wlan_display_context.sel_eap_ttls_auth_type]].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  eap_ttls_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool eap_ttls_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    if (export_root_ca((S8*) prof->ca_cert, (S8*) profile->root_ca_path, FILE_PATH_LEN, profile->priority) == KAL_FALSE)
    {
        return KAL_FALSE;
    }
#else
    prof->ca_cert = profile->root_ca_id;
#endif /* __CERTMAN_SUPPORT__ */

    prof->phase2 |= profile->eap_ttls_auth_type;

    for (i = 0; i < WLAN_EAP_TTLS_TYPES_TOTAL; i++)
    {
        if (profile->eap_ttls_auth_type & (g_wlan_auth_module[g_wlan_eap_ttls_types[i]].val))
        {
            if (g_wlan_auth_module[g_wlan_eap_ttls_types[i]].encode_func != NULL)
            {
                if(g_wlan_auth_module[g_wlan_eap_ttls_types[i]].encode_func(prof, profile, 2) == KAL_FALSE)
                {
                    return KAL_FALSE;
                }
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }

    if (prof->anonymous_identity_len == 0 && profile->use_anonymous == KAL_TRUE)
    {
        prof->anonymous_identity_len = strlen(DEFAULT_ANONYMOUS_IDENTITY);
        strcpy((char *)prof->anonymous_identity, DEFAULT_ANONYMOUS_IDENTITY);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_auth_type_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_auth_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = g_wlan_auth_module[g_wlan_eap_ttls_types[g_wlan_display_context.sel_eap_ttls_auth_type]].val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.eap_ttls_auth_type & val)
    {
        g_wlan_display_context.eap_ttls_auth_type &= ~val;
    }
    else
    {
        g_wlan_display_context.eap_ttls_auth_type |= val;
    }

    g_wlan_display_context.modified2 = TRUE;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_eap_ttls_auth_type = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings_auth_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL_OPT,
        NULL,
        mmi_wlan_entry_eap_ttls_settings_auth_type_opt,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL_OPT);

    if (g_wlan_auth_module[g_wlan_eap_ttls_types[g_wlan_display_context.sel_eap_ttls_auth_type]].entry_func == NULL)
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT);
    }
    if (g_wlan_display_context.eap_ttls_auth_type & g_wlan_auth_module[g_wlan_eap_ttls_types[g_wlan_display_context.sel_eap_ttls_auth_type]].val)
    {
        nStrItemList[0] = STR_GLOBAL_DEACTIVATE;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type_ok(void)
{
    if (g_wlan_display_context.eap_ttls_auth_type == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings_auth_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings_auth_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[WLAN_EAP_TTLS_TYPES_TOTAL];
    U16 iconStates[WLAN_EAP_TTLS_TYPES_TOTAL];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL,
        NULL,
        mmi_wlan_entry_eap_ttls_settings_auth_type,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL);
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_ttls_settings_auth_type_highlight_hdlr);

    for (i = 0; i < WLAN_EAP_TTLS_TYPES_TOTAL; i++)
    {
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(g_wlan_eap_ttls_types[i]);
        if (g_wlan_display_context.eap_ttls_auth_type & g_wlan_auth_module[g_wlan_eap_ttls_types[i]].val)
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_TUNNELED_AUTH_PROTOCOL,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_TTLS_TYPES_TOTAL,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        0,
        guiBuffer,
        ICON_TEXT_ICON);

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_ttls_settings_auth_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_ttls_settings_auth_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_EAP_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex == WLAN_EAP_TTLS_SETTINGS_CA_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_ttls_settings_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_ttls_settings_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_CA_CERT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT],
        (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_name);
    }

#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_path);
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_CA_CERT],
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

/*    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USERNAME_STR], (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USERNAME],
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.username_str),
        MAX_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USERNAME], DataAccountFullLineEditScreen);
*/
/*    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USE_ANONYMOUS_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_USE_ANONYMOUS));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USE_ANONYMOUS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_USE_ANONYMOUS],
        2,
        g_wlan_display_context.yes_no_opt,
        &g_wlan_display_context.use_anonymous);
*/
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL],
        (U8*) GetString(STR_ID_DTCNT_WLAN_EAP_TYPES));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_eap_ttls_settings
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_eap_ttls_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS;
    h.entryFuncPtr = mmi_wlan_entry_eap_ttls_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_ttls_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_ttls_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    U16 inline_icon_list[WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL] = 
        {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS, mmi_wlan_exit_eap_ttls_settings, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS);

    InitializeCategory57Screen();

    if (guiBuffer == NULL)
    {
        g_wlan_display_context.modified2 = FALSE;
        ASSERT(g_wlan_display_context.eap_ttls_auth_type > 0);
    }

    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS, &inputBufferSize);    /* added for inline edit history */

    SetParentHandler(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS);
    mmi_wlan_eap_ttls_settings_fill_inline_struct();

    RegisterHighlightHandler(mmi_wlan_eap_ttls_settings_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL, inputBuffer);
    }

    if (GetInlineDoneFlag(guiBuffer) == 0 && g_wlan_display_context.modified2 == TRUE)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_SELECT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_TTLS_SETTINGS_INLINE_TOTAL,
        inline_icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_eap_ttls_settings_save, GoBackHistory);

}

#endif /* WLAN_EAP_TTLS_SUPPORT */ 

#ifdef WLAN_EAP_PEAP_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_peap_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_peap_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_peap_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_peap_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    auth_settings_hdlr =
        g_wlan_auth_module[g_wlan_eap_peap_types[g_wlan_display_context.sel_eap_peap_auth_type]].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  eap_peap_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool eap_peap_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __CERTMAN_SUPPORT__
    if (prof->ca_cert[0] == 0)
    {
        if (export_root_ca((S8*) prof->ca_cert, (S8*) profile->root_ca_path, FILE_PATH_LEN, profile->priority) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
    }
#else
    prof->ca_cert = profile->root_ca_id;
#endif /* __CERTMAN_SUPPORT__*/
    prof->phase1 = profile->peap_version | DEFAULT_PEAP_PHASE1_PARAM;

    prof->phase2 |= profile->eap_peap_auth_type;
    
    for (i = 0; i < WLAN_EAP_PEAP_TYPES_TOTAL; i++)
    {
        if (profile->eap_peap_auth_type & (g_wlan_auth_module[g_wlan_eap_peap_types[i]].val))
        {
            if (g_wlan_auth_module[g_wlan_eap_peap_types[i]].encode_func != NULL)
            {
                if(g_wlan_auth_module[g_wlan_eap_peap_types[i]].encode_func(prof, profile, 2) == KAL_FALSE)
                {
                    return KAL_FALSE;
                }
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }

    if (prof->anonymous_identity_len == 0 && profile->use_anonymous == KAL_TRUE)
    {
        prof->anonymous_identity_len = strlen(DEFAULT_ANONYMOUS_IDENTITY);
        strcpy((char *)prof->anonymous_identity, DEFAULT_ANONYMOUS_IDENTITY);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_eap_type_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_eap_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = g_wlan_auth_module[g_wlan_eap_peap_types[g_wlan_display_context.sel_eap_peap_auth_type]].val;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.eap_peap_auth_type & val)
    {
        g_wlan_display_context.eap_peap_auth_type &= ~val;
    }
    else
    {
        g_wlan_display_context.eap_peap_auth_type |= val;
    }

    g_wlan_display_context.modified2 = TRUE;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_eap_peap_auth_type = nIndex;
    /*
     * FuncPtr auth_settings_hdlr;
     * 
     * g_wlan_display_context.sel_auth_type2 = g_wlan_eap_peap_types[nIndex];
     * auth_settings_hdlr = g_wlan_auth_module[g_wlan_display_context.sel_auth_type2].entry_func;
     * 
     * if(auth_settings_hdlr == NULL)
     * {
     * ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
     * SetLeftSoftkeyFunction(mmi_wlan_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
     * }
     * else
     * {
     * ChangeLeftSoftkey(STR_ID_DTCNT_WLAN_CONFIGURE, 0);
     * SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE_OPT,
        NULL,
        mmi_wlan_entry_eap_peap_settings_eap_type_opt,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE_OPT);

    if (g_wlan_auth_module[g_wlan_eap_peap_types[g_wlan_display_context.sel_eap_peap_auth_type]].entry_func == NULL)
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT);
    }
    if (g_wlan_display_context.eap_peap_auth_type & g_wlan_auth_module[g_wlan_eap_peap_types[g_wlan_display_context.sel_eap_peap_auth_type]].val)
    {
        nStrItemList[0] = STR_GLOBAL_DEACTIVATE;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type_ok(void)
{
    if (g_wlan_display_context.eap_peap_auth_type == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings_eap_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[WLAN_EAP_PEAP_TYPES_TOTAL];
    U16 iconStates[WLAN_EAP_PEAP_TYPES_TOTAL];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE, NULL, mmi_wlan_entry_eap_peap_settings_eap_type, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE);
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_peap_settings_eap_type_highlight_hdlr);

    for (i = 0; i < WLAN_EAP_PEAP_TYPES_TOTAL; i++)
    {
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(g_wlan_eap_peap_types[i]);
        if (g_wlan_display_context.eap_peap_auth_type & g_wlan_auth_module[g_wlan_eap_peap_types[i]].val)
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_EAP_TYPES,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_PEAP_TYPES_TOTAL,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        0,
        guiBuffer,
        ICON_TEXT_ICON);

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_peap_settings_eap_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_peap_settings_eap_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    GoBackToHistory(SCR_ID_DTCNT_WLAN_EAP_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex == WLAN_EAP_PEAP_SETTINGS_CA_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_peap_settings_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_peap_settings_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.yes_no_opt[0] = (U8*) GetString(STR_GLOBAL_NO);
    g_wlan_display_context.yes_no_opt[1] = (U8*) GetString(STR_GLOBAL_YES);

    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_CA_CERT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT],
        (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_name);
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_path);
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_CA_CERT],
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

/*    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USERNAME_STR], (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USERNAME],
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.username_str),
        MAX_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USERNAME], DataAccountFullLineEditScreen);
*/
/*    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USE_ANONYMOUS_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_USE_ANONYMOUS));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USE_ANONYMOUS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_USE_ANONYMOUS],
        2,
        g_wlan_display_context.yes_no_opt,
        &g_wlan_display_context.use_anonymous);
    
    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_0_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_ALLOW_PEAP_0));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_0],
        2,
        g_wlan_display_context.yes_no_opt,
        &g_wlan_display_context.allow_peap0);

    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_1_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_ALLOW_PEAP_1));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[WLAN_EAP_PEAP_ALLOW_PEAP_1],
        2,
        g_wlan_display_context.yes_no_opt,
        &g_wlan_display_context.allow_peap1);
*/
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL],
        (U8*) GetString(STR_ID_DTCNT_WLAN_EAP_TYPES));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_eap_peap_settings
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_eap_peap_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS;
    h.entryFuncPtr = mmi_wlan_entry_eap_peap_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_peap_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_peap_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    U16 inline_icon_list[WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL] = 
    {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS, mmi_wlan_exit_eap_peap_settings, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS);

    InitializeCategory57Screen();

    if (guiBuffer == NULL)
    {
        g_wlan_display_context.modified2 = FALSE;
        ASSERT(g_wlan_display_context.eap_peap_auth_type > 0);
    }

    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS, &inputBufferSize);    /* added for inline edit history */
    SetParentHandler(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS);
    mmi_wlan_eap_peap_settings_fill_inline_struct();

    RegisterHighlightHandler(mmi_wlan_eap_peap_settings_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL, inputBuffer);
    }

    if (GetInlineDoneFlag(guiBuffer) == 0 && g_wlan_display_context.modified2 == TRUE)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_SELECT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_PEAP_SETTINGS_INLINE_TOTAL,
        inline_icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_eap_peap_settings_save, GoBackHistory);

}

#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TLS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  eap_tls_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool eap_tls_profile_encoder(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(phase == 1)
    {
#ifndef __CERTMAN_SUPPORT__
        if (prof->client_cert[0] == 0)
        {
            if (export_client_ca((S8*) prof->client_cert, (S8*) profile->client_ca_path, FILE_PATH_LEN, profile->priority) ==
                KAL_FALSE)
            {
                //return KAL_FALSE;
            }
        }

        if (prof->ca_cert[0] == 0)
        {
            if (export_root_ca((S8*) prof->ca_cert, (S8*) profile->root_ca_path, FILE_PATH_LEN, profile->priority) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
        }

        if (prof->private_key[0] == 0)
        {
            if (export_private_key((S8*) prof->private_key, (S8*) profile->private_key_path, FILE_PATH_LEN, profile->priority) ==
                KAL_FALSE)
            {
                //return KAL_FALSE;
            }
        }
#else
        prof->ca_cert = profile->root_ca_id;
        if(profile->auth_type1 & (g_wlan_auth_module[g_wlan_eap_types[0]].val))
        {
        prof->client_cert = profile->client_ca_id;
        }
        else
        {
            prof->client_cert = 0;
        }
        prof->private_key = 0;
#endif /* __CERTMAN_SUPPORT__ */

        if (prof->private_key_passwd_len == 0)
        {
            len = strlen((char*)profile->private_key_passwd);
            if (len > 0)
            {
                prof->private_key_passwd_len = len;
                memcpy(prof->private_key_passwd, profile->private_key_passwd, prof->private_key_passwd_len);
            }
            else
            {
                prof->private_key_passwd_len = 0;
            }
        }
    }
    else if(phase == 2)
    {
#ifndef __CERTMAN_SUPPORT__
        if (prof->client_cert2[0] == 0)
        {
            if (export_client_ca((S8*) prof->client_cert2, (S8*) profile->client_ca_path, FILE_PATH_LEN, profile->priority) ==
                KAL_FALSE)
            {
                //return KAL_FALSE;
            }
        }

        if (prof->ca_cert2[0] == 0)
        {
            if (export_root_ca((S8*) prof->ca_cert2, (S8*) profile->root_ca_path, FILE_PATH_LEN, profile->priority) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
        }

        if (prof->private_key2[0] == 0)
        {
            if (export_private_key((S8*) prof->private_key2, (S8*) profile->private_key_path, FILE_PATH_LEN, profile->priority) ==
                KAL_FALSE)
            {
                //return KAL_FALSE;
            }
        }
#else
        prof->ca_cert2 = profile->root_ca_id;
        prof->client_cert2 = profile->client_ca_id;
        prof->private_key2 = 0;

#endif /* __CERTMAN_SUPPORT__ */
        if (prof->private_key2_passwd_len == 0)
        {
            len = strlen((char*)profile->private_key_passwd);
            if (len > 0)
            {
                prof->private_key2_passwd_len = len;
                memcpy(prof->private_key2_passwd, profile->private_key_passwd, prof->private_key2_passwd_len);
            }
            else
            {
                prof->private_key2_passwd_len = 0;
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }

    if (prof->anonymous_identity_len == 0 && profile->use_anonymous == KAL_TRUE)
    {
        prof->anonymous_identity_len = strlen(DEFAULT_ANONYMOUS_IDENTITY);
        strcpy((char *)prof->anonymous_identity, DEFAULT_ANONYMOUS_IDENTITY);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_tls_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_tls_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified = TRUE;
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_tls_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_tls_settings_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex == WLAN_EAP_TLS_SETTINGS_USER_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_user_cert_list, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_EAP_TLS_SETTINGS_CA_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
    }
#ifndef __CERTMAN_SUPPORT__
    else if (nIndex == WLAN_EAP_TLS_SETTINGS_PRIV_KEY)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_entry_private_key_list, KEY_EVENT_UP);
    }
#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_tls_settings_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_tls_settings_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_CA_CERT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_CA_CERT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_CA_CERT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
#ifdef __CERTMAN_SUPPORT__
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_name);
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_CA_CERT],
            (U8*) g_wlan_display_context.root_ca_path);
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_CA_CERT],
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USER_CERT_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_USER_CERT));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USER_CERT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    
#ifdef __CERTMAN_SUPPORT__   
    if (mmi_ucs2strlen(g_wlan_display_context.client_user_name) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USER_CERT],
            (U8*) g_wlan_display_context.client_user_name);
    }
#else
    if (mmi_ucs2strlen(g_wlan_display_context.client_ca_path) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USER_CERT],
            (U8*) g_wlan_display_context.client_ca_path);
    }
#endif /* __CERTMAN_SUPPORT__ */
    else
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USER_CERT],
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

#ifndef __CERTMAN_SUPPORT__
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_PRIV_KEY));
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_STR],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    if (mmi_ucs2strlen(g_wlan_display_context.private_key_path) > 0)
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY],
            (U8*) g_wlan_display_context.private_key_path);
    }
    else
    {
        SetInlineItemDisplayOnly(
            &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY],
            (U8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
#endif /* __CERTMAN_SUPPORT__ */

    SetInlineItemCaption(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_PRIV_KEY_PASSWD));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD],
        STR_ID_DTCNT_WLAN_PRIV_KEY_PASSWD,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.private_key_passwd_str),
        MAX_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD],
        DataAccountFullLineEditScreen);

    SetInlineItemCaption(&wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USERNAME_STR], (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemActivation(&wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USERNAME],
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.username_str),
        MAX_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_EAP_TLS_SETTINGS_USERNAME], DataAccountFullLineEditScreen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_eap_tls_settings
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_eap_tls_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS;
    h.entryFuncPtr = mmi_wlan_entry_eap_tls_settings;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_tls_settings
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_tls_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS, mmi_wlan_exit_eap_tls_settings, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS);

    InitializeCategory57Screen();

    if (guiBuffer == NULL)
    {
        g_wlan_display_context.modified2 = FALSE;
    }
    
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS, &inputBufferSize);    /* added for inline edit history */

    SetParentHandler(SCR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS);
    mmi_wlan_eap_tls_settings_fill_inline_struct();

    RegisterHighlightHandler(mmi_wlan_eap_tls_settings_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL, inputBuffer);
    }

    if (GetInlineDoneFlag(guiBuffer) == 0 && g_wlan_display_context.modified2 == TRUE)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_EAP_TLS_SETTINGS,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_SELECT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_TLS_SETTINGS_INLINE_TOTAL,
        g_wlan_display_context.icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_eap_tls_settings_save, GoBackHistory);

}

#endif /* WLAN_EAP_TLS_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_user_info_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_user_info_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_DTCNT_WLAN_EAP_PEAP_SETTINGS_EAP_TYPE))
    {
        g_wlan_display_context.modified2 = TRUE;
    }
    else if (IsScreenPresent(SCR_ID_DTCNT_WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL))
    {
        g_wlan_display_context.modified2 = TRUE;
    }
    else
    {
        g_wlan_display_context.modified = TRUE;
    }
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_user_info_fill_inline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_user_info_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemCaption(&wgui_inline_items[WLAN_USER_INFO_USERNAME_STR], (U8*) GetString(STR_ID_DTCNT_USER_NAME));
    SetInlineItemActivation(&wgui_inline_items[WLAN_USER_INFO_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_USER_INFO_USERNAME],
        STR_ID_DTCNT_USER_NAME,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.username_str),
        MAX_USERNAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_USER_INFO_USERNAME], DataAccountFullLineEditScreen);

    SetInlineItemCaption(&wgui_inline_items[WLAN_USER_INFO_PASSWORD_STR], (U8*) GetString(STR_ID_DTCNT_PASSWD));
    SetInlineItemActivation(&wgui_inline_items[WLAN_USER_INFO_PASSWORD], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[WLAN_USER_INFO_PASSWORD],
        STR_ID_DTCNT_PASSWD,
        GetRootTitleIcon(SERVICES_DATA_CONNECT_MAIN_MENU_ID),
        (U8*) (g_wlan_display_context.password_str),
        MAX_PASSWORD_LEN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_USER_INFO_PASSWORD], DataAccountFullLineEditScreen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_exit_user_info
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_exit_user_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_DTCNT_WLAN_USER_INFO;
    h.entryFuncPtr = mmi_wlan_entry_user_info;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_user_info
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_user_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    BOOL modified = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_USER_INFO, mmi_wlan_exit_user_info, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_USER_INFO);

    InitializeCategory57Screen();

    if (guiBuffer == NULL)
    {
        modified = FALSE;
    }
    inputBuffer = GetCurrNInputBuffer(SCR_ID_DTCNT_WLAN_USER_INFO, &inputBufferSize);   /* added for inline edit history */

    SetParentHandler(SCR_ID_DTCNT_WLAN_USER_INFO);
    mmi_wlan_user_info_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, WLAN_USER_INFO_INLINE_TOTAL, inputBuffer);
    }

    if (modified == TRUE)
    {
        wgui_inline_list_menu_changed = 1;
    }

    ShowCategory57Screen(
        STR_ID_DTCNT_WLAN_USER_INFO,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_EDIT,
        IMG_ID_DTCNT_LSK_EDIT,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_USER_INFO_INLINE_TOTAL,
        g_wlan_display_context.icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_wlan_user_info_save, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_type_activate
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_type_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = g_wlan_auth_module[g_wlan_eap_types[g_wlan_display_context.sel_auth_type1]].val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.auth_type1 & val)
    {
        g_wlan_display_context.auth_type1 &= ~val;
    }
    else
    {
        g_wlan_display_context.auth_type1 |= val;
    }

    g_wlan_display_context.modified = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_type_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_auth_type1 = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_TYPE_OPT, NULL, mmi_wlan_entry_eap_type_opt, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TYPE_OPT);

    if (g_wlan_auth_module[g_wlan_eap_types[g_wlan_display_context.sel_auth_type1]].entry_func == NULL)
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_TYPES_OPT2);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_TYPES_OPT2, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_TYPES_OPT2);
    }
    else
    {
        nNumofItem = GetNumOfChild(MENU_ID_WLAN_EAP_TYPES_OPT);

        GetSequenceStringIds(MENU_ID_WLAN_EAP_TYPES_OPT, nStrItemList);

        SetParentHandler(MENU_ID_WLAN_EAP_TYPES_OPT);
    }

    if (g_wlan_display_context.auth_type1 & (g_wlan_auth_module[g_wlan_eap_types[g_wlan_display_context.sel_auth_type1]].val))
    {
        nStrItemList[0] = STR_GLOBAL_DEACTIVATE;
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type_ok(void)
{
    if (g_wlan_display_context.auth_type1 == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_ONE_EAP_NEEDED),
            IMG_GLOBAL_ERROR,
            1,
            DATA_ACCOUNT_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return;
    }
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_eap_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_eap_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[WLAN_EAP_TYPES_TOTAL];
    U16 iconStates[WLAN_EAP_TYPES_TOTAL];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DTCNT_WLAN_EAP_TYPE, NULL, mmi_wlan_entry_eap_type, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_EAP_TYPE);

    if (guiBuffer == NULL)
    {
        g_wlan_display_context.sel_auth_type1 = 0;
        ASSERT(g_wlan_display_context.auth_type1 > 0);
    }

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_eap_type_highlight_hdlr);

    for (i = 0; i < WLAN_EAP_TYPES_TOTAL; i++)
    {
        nStrList[i] = (PU8) mmi_wlan_get_auth_type_name(g_wlan_eap_types[i]);
        if (g_wlan_display_context.auth_type1 & (g_wlan_auth_module[g_wlan_eap_types[i]].val))
        {
            iconStates[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            iconStates[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_EAP_TYPES,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        WLAN_EAP_TYPES_TOTAL,
        nStrList,
        (U16*) gIndexIconsImageList,
        iconStates,
        0,
        guiBuffer,
        ICON_TEXT_ICON);

    SetLeftSoftkeyFunction(mmi_wlan_entry_eap_type_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_type_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_wlan_entry_eap_type_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_eap_type_ok, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_eap_types_opt_activate
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_eap_types_opt_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_wlan_eap_type_activate, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_eap_type_activate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_highlight_eap_types_opt_edit
 * DESCRIPTION
 *  Highlight handler of PoC menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_highlight_eap_types_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr auth_settings_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    auth_settings_hdlr = g_wlan_auth_module[g_wlan_eap_types[g_wlan_display_context.sel_auth_type1]].entry_func;

    ASSERT(auth_settings_hdlr != NULL);

    SetLeftSoftkeyFunction(auth_settings_hdlr, KEY_EVENT_UP);
    SetKeyHandler(auth_settings_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_init_highlight_hdlr
 * DESCRIPTION
 *  Initialize all highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_eap_init_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE, mmi_wlan_highlight_eap_types_opt_activate);
    SetHiliteHandler(MENU_ID_WLAN_EAP_TYPES_OPT_EDIT, mmi_wlan_highlight_eap_types_opt_edit);
#ifdef WLAN_EAP_PEAP_SUPPORT
    SetHiliteHandler(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE, mmi_wlan_highlight_peap_types_opt_activate);
    SetHiliteHandler(MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT, mmi_wlan_highlight_peap_types_opt_edit);
#endif /* WLAN_EAP_PEAP_SUPPORT */ 
#ifdef WLAN_EAP_TTLS_SUPPORT
    SetHiliteHandler(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE, mmi_wlan_highlight_ttls_types_opt_activate);
    SetHiliteHandler(MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT, mmi_wlan_highlight_ttls_types_opt_edit);
#endif /* WLAN_EAP_TTLS_SUPPORT */ 
}

#endif /* __MMI_WLAN_FEATURES__ */ 

