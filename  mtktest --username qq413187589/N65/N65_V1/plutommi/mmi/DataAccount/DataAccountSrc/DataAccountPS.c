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
 * DataAccountUtils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Utility functions for Data Account.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "DataAccountCommon.h"
#include "CallManagementGProt.h"
#include "gpioInc.h"

#ifdef __MMI_WLAN_FEATURES__

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_wlan_send_event_notify(dtcnt_bearer_state_enum state);

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

extern mmi_wlan_profile_struct *g_always_ask_conn_profile_p;
extern U8 g_always_ask_connect_flag;
extern U8 g_always_ask_before_connect_flag;
extern U8 g_always_ask_send_cnf_flag;
extern void mmi_dtcnt_wlan_connect_result(U8 wifi_connect_result);
/*****************************************************************************
 * FUNCTION
 *  free_all_actions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  action_to_remove        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void delete_all_actions(wlan_action_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *action_to_remove;
    wlan_action_struct *iterator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iterator = *handle;

    while (iterator != NULL)
    {
        action_to_remove = iterator;
        iterator = iterator->next;
        ASSERT(action_to_remove != NULL);
        OslMfree(action_to_remove);
    }
    
    *handle = NULL;
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  free_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  action_to_remove        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void free_action(wlan_action_struct **handle, wlan_action_struct *action_to_remove)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *temp_action = *handle;
    wlan_action_struct *prev_action = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action_to_remove == NULL)
    {
        return;
    }

    while (temp_action != action_to_remove)
    {
        prev_action = temp_action;
        temp_action = temp_action->next;
        ASSERT(temp_action != NULL);
    }

    if(prev_action)
    {
        prev_action->next = temp_action->next;
    }
    else
    {
        ASSERT(action_to_remove == *handle);
        
        *handle = action_to_remove->next;
    }
    
    OslMfree(action_to_remove);
    action_to_remove = NULL;
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  find_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]         
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wlan_action_struct *find_action(wlan_action_struct *handle, wlan_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *temp_action = handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp_action == NULL)
    {
        return NULL;
    }

    do
    {
        if (temp_action->action == action)
        {
            return temp_action;
        }
        temp_action = temp_action->next;
    }
    while (temp_action != NULL);
    return NULL;    /* Not found */
}


/*****************************************************************************
 * FUNCTION
 *  delete_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void delete_action(wlan_action_struct **handle, wlan_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *temp_action = find_action(*handle, action);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_action(handle, temp_action);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  do_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static BOOL do_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *todo = g_wlan_display_context.actions;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (todo == NULL)
    {
        return FALSE;   /* Nothing to do */
    }

    switch (todo->action)
    {
        case WLAN_ACTION_INIT:
            mmi_wlan_abm_wifi_init_req_hdlr();
            break;
        case WLAN_ACTION_DEINIT:
            mmi_wlan_abm_wifi_deinit_req_hdlr();
            break;
        case WLAN_ACTION_CONNECT:
            mmi_wlan_abm_wifi_connect_req_hdlr(todo->data);
            break;
        case WLAN_ACTION_DISCONNECT:
            mmi_wlan_abm_wifi_disconnect_req_hdlr();
            break;
        case WLAN_ACTION_SCAN:
            mmi_wlan_abm_wifi_ap_list_req_hdlr();
            break;
        default:
            ASSERT(0);
    }

    free_action(&g_wlan_display_context.actions, todo);
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  add_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  action      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void add_action(wlan_action_struct **handle, wlan_action_enum action, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wlan_action_struct *prev_action;
    wlan_action_struct *temp_action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case WLAN_ACTION_INIT:
            if (find_action(*handle, WLAN_ACTION_DEINIT) != NULL)
            {
                delete_action(handle, WLAN_ACTION_DEINIT);
                return;
            }
            break;
        case WLAN_ACTION_CONNECT:
            break;
        case WLAN_ACTION_DISCONNECT:
            if (find_action(*handle, WLAN_ACTION_CONNECT) != NULL)
            {
                delete_action(handle, WLAN_ACTION_CONNECT);
                return;
            }
            else
            {
                delete_all_actions(handle);
                mmi_wlan_abm_wifi_disconnect_req_hdlr();
                return;
            }
            break;
        case WLAN_ACTION_DEINIT:
            if (find_action(*handle, WLAN_ACTION_INIT) != NULL)
            {
                delete_action(handle, WLAN_ACTION_INIT);
                return;
            }
            break;
        case WLAN_ACTION_SCAN:
            break;
    }

    /* Avoid duplicate actions */
    delete_action(handle, action);

    temp_action = OslMalloc(sizeof(wlan_action_struct));
    temp_action->action = action;
    temp_action->data = data;
    temp_action->next = NULL;
    
    if (*handle == NULL)
    {
        *handle = temp_action;
    }
    else
    {
        prev_action = *handle;
        while (prev_action->next != NULL)
        {
            prev_action = prev_action->next;
        }
        prev_action->next = temp_action;
    }
    /* Execute next action if we are not in waiting state. */
    switch (g_wlan_display_context.state)
    {
        case WLAN_STATE_NULL:
        case WLAN_STATE_INIT:
        case WLAN_STATE_CONNECTED:
            if(g_wlan_display_context.scan_state == WLAN_SCAN_STATE_NULL)
            {
                do_action();
            }
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  bssinfo_to_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof            [?]         
 *  bssinfo         [?]         
 *  passphrase      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bssinfo_to_profile(mmi_wlan_profile_struct *prof, supc_abm_bss_info_struct *bssinfo, const char *passphrase, int keylen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_init_profile(prof);

    prof->ssid_len = bssinfo->ssid_len;
    strncpy((char*)prof->ssid, (const char*)bssinfo->ssid, bssinfo->ssid_len);

    mmi_asc_n_to_ucs2((PS8) prof->name, (PS8) bssinfo->ssid, bssinfo->ssid_len);

    prof->use_dhcp = TRUE;

    switch (bssinfo->network_type)
    {
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            /*prof->network_type = WLAN_NETWORK_TYPE_AUTO;*/
            prof->network_type = WLAN_NETWORK_TYPE_INFRA;
            break;
        case WNDRV_SUPC_NETWORK_IBSS:
            prof->network_type = WLAN_NETWORK_TYPE_ADHOC;
            prof->channel = bssinfo->channel_number;
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            prof->network_type = WLAN_NETWORK_TYPE_INFRA;
            break;
    }

    if (bssinfo->rsn_ie_info_p == TRUE)
    {
        if (bssinfo->rsn_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bssinfo->rsn_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            prof->encrypt_mode = WLAN_ENCRYPT_MODE_TKIP;
        }

        if (bssinfo->rsn_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bssinfo->rsn_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            prof->encrypt_mode = WLAN_ENCRYPT_MODE_AES;
        }

        if(bssinfo->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bssinfo->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                prof->auth_mode = WLAN_AUTH_MODE_WPAPSK;
            }
            else
            {
                prof->auth_mode = WLAN_AUTH_MODE_WPA;
            }
        }
        else if(bssinfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bssinfo->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            prof->auth_mode = WLAN_AUTH_MODE_WPAPSK;
        }
        else
        {
            prof->auth_mode = WLAN_AUTH_MODE_WPA;
        }
        }
        if (passphrase != NULL)
        {
            if(keylen == 64)
            {
                hex_to_string(prof->psk, (U8 *)passphrase, 64);
            }
            else
            {
                strcpy((char*)prof->passphrase, passphrase);
            }
        }
    }
    else if (bssinfo->wpa_ie_info_p == TRUE)
    {
        if (bssinfo->wpa_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bssinfo->wpa_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            prof->encrypt_mode = WLAN_ENCRYPT_MODE_TKIP;
        }

        if (bssinfo->wpa_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bssinfo->wpa_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            prof->encrypt_mode = WLAN_ENCRYPT_MODE_AES;
        }

        if(bssinfo->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bssinfo->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                prof->auth_mode = WLAN_AUTH_MODE_WPAPSK;
            }
            else
            {
                prof->auth_mode = WLAN_AUTH_MODE_WPA;
            }
        }
        else if(bssinfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
        if (bssinfo->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            prof->auth_mode = WLAN_AUTH_MODE_WPAPSK;
        }
        else
        {
            prof->auth_mode = WLAN_AUTH_MODE_WPA;
        }
        }
        if (passphrase != NULL)
        {
            if(keylen == 64)
            {
                hex_to_string(prof->psk, (U8 *)passphrase, 64);
            }
            else
            {
                strcpy((char*)prof->passphrase, passphrase);
            }
        }
    }
    else if (bssinfo->privacy > 0)
    {
        prof->auth_mode = WLAN_AUTH_MODE_SHARED;
        prof->encrypt_mode = WLAN_ENCRYPT_MODE_WEP;
        if (passphrase == NULL)
        {
            return;
        }

        switch (keylen)
        {
            case 5:
                prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
                prof->wep_key_format = WLAN_WEP_KEY_FORMAT_ASCII;
                memcpy(prof->wep_key, passphrase, 5);
                break;
            case 13:
                prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_128;
                prof->wep_key_format = WLAN_WEP_KEY_FORMAT_ASCII;
                memcpy(prof->wep_key, passphrase, 13);
                break;
            default:
                ASSERT(0);
                break;
        }
    }
    else
    {
        prof->auth_mode = WLAN_AUTH_MODE_OPEN;
        prof->encrypt_mode = WLAN_ENCRYPT_MODE_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  encode_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool encode_profile(wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(prof, 0, sizeof(wifi_data_account_profile_struct));

    prof->ssid_len = profile->ssid_len;
    memcpy(prof->ssid, profile->ssid, profile->ssid_len);

    switch (profile->network_type)
    {
        /*case WLAN_NETWORK_TYPE_AUTO:
            prof->network_type = WNDRV_SUPC_NETWORK_AUTO_UNKNOWN;
            break;*/
        case WLAN_NETWORK_TYPE_ADHOC:
            prof->network_type = WNDRV_SUPC_NETWORK_IBSS;
            prof->channel_number = profile->channel;
            break;
        case WLAN_NETWORK_TYPE_INFRA:
            prof->network_type = WNDRV_SUPC_NETWORK_INFRASTRUCTURE;
            break;
        default:
          ASSERT(0);
    }

    prof->priority = profile->priority;
    prof->profile_id = profile->profile_id;

    switch (profile->auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
            prof->key_mgmt = WPA_KEY_MGMT_NONE;
            break;
        case WLAN_AUTH_MODE_SHARED:
            prof->proto = WPA_PROTO_RSN;
            prof->key_mgmt = WPA_KEY_MGMT_NONE;
            prof->auth_alg = WPA_AUTH_ALG_SHARED;
            break;
        case WLAN_AUTH_MODE_IEEE8021X:
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X_NO_WPA;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            if (encode_eap_profile(prof, profile) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            break;
        case WLAN_AUTH_MODE_WPAPSK:
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN;
            prof->psk_p = KAL_TRUE;
            /* prof->auth_alg = WPA_AUTH_ALG_OPEN; */
            if(prof->network_type == WNDRV_SUPC_NETWORK_IBSS)
            {
                prof->key_mgmt = WPA_KEY_MGMT_WPA_NONE;
            }
            else
            {            
                prof->key_mgmt = WPA_KEY_MGMT_PSK;
            }

            /* For OTA provisioning. Directly specify the 256-bits PSK, without
               any passphrase. */
            if (strlen((const char*)profile->passphrase) == 0)
            {
                memcpy(prof->psk, profile->psk, 32);
            }
            else
            {
                if (profile->psk[0] == 0)
                {
                    /* Regenerate psk if it is not pre-generated. */
                #ifdef __MTK_TARGET__
                    pbkdf2_sha1(
                        (const char*)profile->passphrase,
                        (const char*)prof->ssid,
                        prof->ssid_len,
                        4096,
                        prof->psk,
                        32);
                #else /* __MTK_TARGET__ */ 
                    strcpy((char*)prof->psk, (const char*)profile->passphrase);
                #endif /* __MTK_TARGET__ */ 
                }
                else
                {
                    memcpy(prof->psk, profile->psk, 32);
                }
            }
            break;
        case WLAN_AUTH_MODE_WPA:
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN;
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            if (encode_eap_profile(prof, profile) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            break;
    }

    switch (profile->encrypt_mode)
    {
        case WLAN_ENCRYPT_MODE_NONE:
            prof->pairwise = WPA_CIPHER_NONE;
            prof->group = WPA_CIPHER_NONE;
            break;
        case WLAN_ENCRYPT_MODE_WEP:
            switch (profile->wep_key_len)
            {
                case WLAN_WEP_KEY_ENCRYPT_64:
                    prof->group = WPA_CIPHER_WEP40;
                    prof->pairwise = WPA_CIPHER_WEP40;
                    break;
                case WLAN_WEP_KEY_ENCRYPT_128:
                    prof->group = WPA_CIPHER_WEP104;
                    prof->pairwise = WPA_CIPHER_WEP104;
                    break;
                default:    /* Invalid key len */
                    prof->pairwise = WPA_CIPHER_NONE;
                    prof->group = WPA_CIPHER_NONE;
                    break;
            }
            break;
        case WLAN_ENCRYPT_MODE_TKIP:
            prof->pairwise = WPA_CIPHER_TKIP;
            prof->group = WPA_CIPHER_TKIP;
            break;
        case WLAN_ENCRYPT_MODE_AES:
            prof->pairwise = WPA_CIPHER_CCMP;
            prof->group = WPA_CIPHER_CCMP;
            break;
    }

    /* WEP key information */
    if (profile->auth_mode == WLAN_AUTH_MODE_SHARED || profile->encrypt_mode == WLAN_ENCRYPT_MODE_WEP)
    {
        U8 i;

        prof->wep_info_p = KAL_TRUE;
        prof->wep_keys.wep_tx_keyidx = profile->wep_key_index;

        for (i = 0; i < MAX_WEP_KEY_NUM; i++)
        {
            switch (profile->wep_key_len)
            {
                case WLAN_WEP_KEY_ENCRYPT_64:
                    prof->wep_keys.wep_key_len[i] = 5;
                    if (profile->wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                    {
                        if (hex_to_string(prof->wep_keys.wep_key[i], profile->wep_key, 10) == FALSE)
                        {
                            prof->wep_keys.wep_key_len[i] = 0;
                        }
                    }
                    else
                    {
                        memcpy(&prof->wep_keys.wep_key[i], profile->wep_key, 5);
                    }
                    break;
                case WLAN_WEP_KEY_ENCRYPT_128:
                    prof->wep_keys.wep_key_len[i] = 13;
                    if (profile->wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
                    {
                        if (hex_to_string(prof->wep_keys.wep_key[i], profile->wep_key, 26) == FALSE)
                        {
                            prof->wep_keys.wep_key_len[i] = 0;
                        }
                    }
                    else
                    {
                        memcpy(prof->wep_keys.wep_key[i], profile->wep_key, 13);
                    }
                    break;
                default:
                    prof->wep_keys.wep_key_len[i] = 0;
                    break;
            }
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_init_req
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  void
 *  info(?)     [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_wlan_send_init_req() called. prev_state=%s, state=%s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));
    
    switch (g_wlan_display_context.prev_state)
    {
        case WLAN_STATE_NULL:
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_INIT, NULL);
            break;
        default:
            ASSERT(0);  /* Invalid state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_deinit_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_deinit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_wlan_send_deinit_req() called. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));
    
    switch (g_wlan_display_context.prev_state)
    {
        case WLAN_STATE_INIT:
        case WLAN_STATE_CONNECTED:
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            break;
        case WLAN_STATE_NULL:
            if(g_wlan_display_context.state != WLAN_STATE_NULL)
            {
                if (find_action(g_wlan_display_context.actions, WLAN_ACTION_CONNECT) != NULL)
                {
                    add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
                }
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            }
            break;
        default:
            ASSERT(0);  /* Invalid state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_connect_req(mmi_wlan_profile_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_wlan_send_connect_req() called. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));
    
    switch (g_wlan_display_context.prev_state)
    {
        case WLAN_STATE_NULL:
            if (g_wlan_display_context.state == WLAN_STATE_INIT_WAIT)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            }
            else if (g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DEINIT, NULL);
            }
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_INIT, NULL);
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_CONNECT, (void*)data);
            break;
        case WLAN_STATE_INIT:
            if (g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
            }
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_CONNECT, (void*)data);
            break;
        case WLAN_STATE_CONNECTED:
            if (g_wlan_display_context.state == WLAN_STATE_DISCONNECT_WAIT)
            {
                if (find_action(g_wlan_display_context.actions, WLAN_ACTION_DEINIT) != NULL)
                {
                    add_action(&g_wlan_display_context.actions, WLAN_ACTION_INIT, NULL);
                }
            }
            else if(g_wlan_display_context.state == WLAN_STATE_DEINIT_WAIT)
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_INIT, NULL);
            }
            else
            {
                add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
            }
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_CONNECT, (void*)data);
            break;
        default:
            ASSERT(0);  /* Invalid state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_wlan_send_disconnect_req() called. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    if(g_wlan_display_context.prev_state == WLAN_STATE_CONNECTED ||
       g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
    {
        add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
    }
    else
    {
        ASSERT(0);  /* Invalid state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_ap_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_ap_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_wlan_send_ap_list_req() called. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    switch (g_wlan_display_context.scan_state)
    {
        case WLAN_SCAN_STATE_ABORTING:
            g_wlan_display_context.scan_state = WLAN_SCAN_STATE_WAITING;
            break;
        case WLAN_SCAN_STATE_WAITING:
            return; /* Do not send request if we are waiting for the search result */
    }

    if (g_wlan_display_context.prev_state == WLAN_STATE_NULL && 
        g_wlan_display_context.state != WLAN_STATE_CONNECT_WAIT)
    {
        add_action(&g_wlan_display_context.actions, WLAN_ACTION_INIT, NULL);
        add_action(&g_wlan_display_context.actions, WLAN_ACTION_SCAN, NULL);
    }
    else
    {
        if (g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
        {
            add_action(&g_wlan_display_context.actions, WLAN_ACTION_DISCONNECT, NULL);
        }
        add_action(&g_wlan_display_context.actions, WLAN_ACTION_SCAN, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_init_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_init_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.state == WLAN_STATE_INIT_WAIT)
    {
        return;
    }
    SetProtocolEventHandler(mmi_wlan_abm_wifi_init_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_INIT_CNF);
    g_wlan_display_context.state = WLAN_STATE_INIT_WAIT;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_INIT_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_init_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_init_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_abm_wifi_init_cnf_struct *cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_INIT_CNF received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    cnf = (mmi_abm_wifi_init_cnf_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_INIT_CNF);
    SetProtocolEventHandler(mmi_wlan_supc_mmi_wifi_curr_ap_info_ind_hdlr, MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND);
    SetProtocolEventHandler(mmi_wlan_abm_wifi_connect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_IND);
    SetProtocolEventHandler(mmi_wlan_abm_ipaddr_update_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_UPDATE_IND);

    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);

    g_wlan_display_context.state = WLAN_STATE_INIT;
    memcpy(g_wlan_display_context.mac_addr, cnf->mac_addr, MAX_MAC_ADDR_LEN);

    if(g_wlan_display_context.app_callback != NULL)
    {
        g_wlan_display_context.app_callback();
        g_wlan_display_context.app_callback = NULL;
    }
    mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_INITIALIZED);

    if (do_action() == TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_wlan_display_context.prev_state = WLAN_STATE_INIT;
    if(g_wlan_setting_context.start_on_bootup == FALSE)
    {
        g_wlan_setting_context.start_on_bootup = TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_deinit_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_deinit_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.state == WLAN_STATE_DEINIT_WAIT)
    {
        return;
    }
    SetProtocolEventHandler(mmi_wlan_abm_wifi_deinit_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_DEINIT_CNF);
    g_wlan_display_context.state = WLAN_STATE_DEINIT_WAIT;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_DEINIT_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_deinit_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_deinit_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_abm_wifi_init_cnf_struct *cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_DEINIT_CNF received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    cnf = (mmi_abm_wifi_init_cnf_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DEINIT_CNF);
    ClearProtocolEventHandler(MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_UPDATE_IND);

    mmi_wlan_update_status_icon(0, FALSE);

    g_wlan_display_context.state = WLAN_STATE_NULL;
    mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_INACTIVE);

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountPS.c] deinit do_action!");

    if (do_action() == TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_wlan_display_context.prev_state = WLAN_STATE_NULL;
    if(g_wlan_display_context.app_callback == NULL)
    {
        g_wlan_setting_context.start_on_bootup = FALSE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountPS.c] deinit delete process screen!");

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        GoBackHistory();
    }
    else if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
    }

    if(g_wlan_display_context.app_callback != NULL)
    {
        g_wlan_display_context.app_callback();
        g_wlan_display_context.app_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_connect_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_connect_req_hdlr(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MYQUEUE Message;
    mmi_abm_wifi_connect_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        U8 i, j, profile_num;

        for (i = 0, profile_num = 0; i < g_wlan_display_context.prof_num;)
        {
            p = (mmi_abm_wifi_connect_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_connect_req_struct));

            for (j = 0; (i < g_wlan_display_context.prof_num) && (j < 2); i++, j++)
            {
                memset(&p->profile_header_ptr[j], 0, sizeof(wifi_data_account_profile_struct));
                
                if (encode_profile(&p->profile_header_ptr[j], g_wlan_profile[i]) == KAL_FALSE)
                {
                    continue;
                }
            }

            profile_num += j;

            if(profile_num > 0)
            {                
                p->selection_mode = AP_AUTOMATIC_SELECT;
                p->num_of_profile = j;
                p->more_flag = (i < g_wlan_display_context.prof_num) ? 1 : 0;
                p->connect_type = 0; /* enable connect */

                Message.oslSrcId = MOD_MMI;
                Message.oslDestId = MOD_ABM;
                Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_CONNECT_REQ;
                Message.oslDataPtr = (oslParaType*) p;
                Message.oslPeerBuffPtr = NULL;
                OslMsgSendExtQueue(&Message);
            }
            else
            {
                OslFreeDataPtr(p);
                return;
            }
        }

        if (profile_num > 0)
        {
            SetProtocolEventHandler(mmi_wlan_abm_wifi_connect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
            g_wlan_display_context.state = WLAN_STATE_CONNECT_WAIT;
        }
        else
        {
            /* If we failed on generating profiles, set the state to be initialized */
    		g_wlan_display_context.prev_state = g_wlan_display_context.state;
            if(g_wlan_setting_context.start_on_bootup == FALSE)
            {
                g_wlan_setting_context.start_on_bootup = TRUE;
                if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
                    NVRAM_MAX_WLAN_SETTING_SIZE)
                {
                    ASSERT(0);
                }
            }
            return;
        }
    }
    else
    {
        p = (mmi_abm_wifi_connect_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_connect_req_struct));
        if (encode_profile(&p->profile_header_ptr[0], (mmi_wlan_profile_struct*) data) == KAL_FALSE)
        {
            g_wlan_display_context.prev_state = g_wlan_display_context.state;
            OslFreeDataPtr(p);
            if(IsScreenPresent(SCR_ID_DTCNT_WLAN_PROCESSING))
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_DTCNT_WLAN_ERROR_FILE_OPEN_FAILED),
                    IMG_GLOBAL_ERROR,
                    1,
                    DATA_ACCOUNT_NOTIFY_TIMEOUT,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
            }
            return;
        }
        p->num_of_profile = 1;
        p->selection_mode = AP_AUTOMATIC_SELECT;
        p->more_flag = 0;
        p->connect_type = 1;
        
        /*PRINT_INFORMATION(("$$$$$ WIFI MMI connect req  always_ask_connect_flag = %d, always_ask_before_connect_type = %d $$$$$", 
            g_always_ask_connect_flag, g_always_ask_before_connect_flag));*/

        MMI_TRACE(TRACE_GROUP_6, MMI_DTCNT_WIFI_ALWAYS_ASK_CONNECT_REQ, g_always_ask_connect_flag, g_always_ask_before_connect_flag);

        if(g_always_ask_connect_flag)
        {
            p->always_ask_connect_flag = TRUE; /* always ask connect */
        }
        else
        {
            p->always_ask_connect_flag = FALSE; 
        }

        if(g_always_ask_before_connect_flag)
        {
            p->always_ask_before_connect_flag = TRUE; /* always ask connect */
        }
        else
        {
            p->always_ask_before_connect_flag = FALSE; 
        }

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_ABM;
        Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_CONNECT_REQ;
        Message.oslDataPtr = (oslParaType*) p;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);

        SetProtocolEventHandler(mmi_wlan_abm_wifi_connect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
        g_wlan_display_context.state = WLAN_STATE_CONNECT_WAIT;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_connect_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_connect_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 string_id;
    mmi_abm_wifi_connect_cnf_struct *cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_CONNECT_CNF received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    cnf = (mmi_abm_wifi_connect_cnf_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
    SetProtocolEventHandler(mmi_wlan_abm_wifi_disconnect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    SetProtocolEventHandler(mmi_wlan_abm_ipaddr_conflict_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);
    if (cnf->result == KAL_TRUE)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);

        g_wlan_display_context.state = WLAN_STATE_CONNECTED;
        
        g_wlan_display_context.connected_wlan_profile = mmi_wlan_find_profile(cnf->profile_id);
        g_wlan_display_context.ssid_len = cnf->ssid_len;
        memcpy(g_wlan_display_context.ssid, cnf->ssid, cnf->ssid_len);
        memcpy(g_wlan_display_context.bssid, cnf->bssid, MAX_MAC_ADDR_LEN);
        g_wlan_display_context.curr_channel_number = cnf->channel_number;
        mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_CONNECTED);
    }
    else
    {
        g_wlan_display_context.state = WLAN_STATE_INIT;
    }
    
    if (do_action() == TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_wlan_display_context.prev_state = g_wlan_display_context.state;
    if(g_wlan_setting_context.start_on_bootup == FALSE)
    {
        g_wlan_setting_context.start_on_bootup = TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }
    
    mmi_wlan_abm_ipaddr_change_req_hdlr();

    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT);

    if(!g_always_ask_connect_flag)
    {
        if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
        {
            if(cnf->result == KAL_FALSE)
            {
                switch(cnf->cause)
                {
                case SUPC_ABM_AUTH_FAIL:
                    string_id = STR_ID_DTCNT_WLAN_ERROR_AUTH_FAIL;
                    break;
                default:
                    string_id = STR_ID_DTCNT_WLAN_ERROR_CONNECT_FAIL;
                    break;                
                }
            
                DisplayPopup(
                    (PU8) GetString(string_id),
                    IMG_GLOBAL_ERROR,
                    1,
                    DATA_ACCOUNT_NOTIFY_TIMEOUT,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
            }
            else
            {
                GoBackHistory();
            }

        }
        else if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
        {
            mmi_wlan_redraw_conn_status_screen();
        }
        else if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
        {
            mmi_wlan_redraw_network_settings_screen();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
        }
    }
    g_always_ask_connect_flag = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_connect_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_connect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_connect_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_CONNECT_IND received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    ind = (mmi_abm_wifi_connect_ind_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
    SetProtocolEventHandler(mmi_wlan_abm_ipaddr_conflict_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);
    SetProtocolEventHandler(mmi_wlan_abm_wifi_disconnect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);

    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
    
    g_wlan_display_context.prev_state = g_wlan_display_context.state = WLAN_STATE_CONNECTED;
    
    g_wlan_display_context.connected_wlan_profile = mmi_wlan_find_profile(ind->profile_id);
    g_wlan_display_context.ssid_len = ind->ssid_len;
    memcpy(g_wlan_display_context.ssid, ind->ssid, ind->ssid_len);
    memcpy(g_wlan_display_context.bssid, ind->bssid, MAX_MAC_ADDR_LEN);
    g_wlan_display_context.curr_channel_number = ind->channel_number;

    mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_CONNECTED);
    mmi_wlan_abm_ipaddr_change_req_hdlr();

    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_FIND_NETWORK_OPT);

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        GoBackHistory();
    }
    else if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    else if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        mmi_wlan_redraw_network_settings_screen();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_disconnect_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_disconnect_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.state == WLAN_STATE_DISCONNECT_WAIT)
    {
        return;
    }

    ASSERT(g_wlan_display_context.state == WLAN_STATE_INIT || g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT || g_wlan_display_context.state == WLAN_STATE_CONNECTED);

    if(g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
    {
        ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
    }
    
    SetProtocolEventHandler(mmi_wlan_abm_wifi_disconnect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    g_wlan_display_context.state = WLAN_STATE_DISCONNECT_WAIT;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_DISCONNECT_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_disconnect_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_disconnect_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);

    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);

    g_wlan_display_context.state = WLAN_STATE_INIT;
    
    g_wlan_display_context.connected_wlan_profile = NULL;
    g_wlan_display_context.ssid_len = 0;
    memset(g_wlan_display_context.ssid, 0, MAX_SSID_LEN);
    memset(g_wlan_display_context.bssid, 0, MAX_MAC_ADDR_LEN);
    mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_INITIALIZED);

    if(g_always_ask_connect_flag && g_always_ask_send_cnf_flag)
    {
        mmi_dtcnt_wlan_connect_result(TRUE);
    }
    
    if (do_action() == TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_wlan_display_context.prev_state = g_wlan_display_context.state;
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[DataAccountPS.c] disconnect delete process screen!");

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_PROCESSING)
    {
        GoBackHistory();
    }
    else if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    else if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        mmi_wlan_redraw_network_settings_screen();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_PROCESSING);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_disconnect_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_disconnect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);

    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);

    g_wlan_display_context.prev_state = g_wlan_display_context.state = WLAN_STATE_INIT;
    
    g_wlan_display_context.connected_wlan_profile = NULL;
    g_wlan_display_context.ssid_len = 0;
    memcpy(g_wlan_display_context.ssid, 0, MAX_SSID_LEN);
    memcpy(g_wlan_display_context.bssid, 0, MAX_MAC_ADDR_LEN);
    mmi_wlan_send_event_notify(DTCNT_BEARER_STATE_INITIALIZED);

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    else if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        mmi_wlan_redraw_network_settings_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_ap_list_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_ap_list_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_wlan_abm_wifi_ap_list_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF);
    g_wlan_display_context.scan_state = WLAN_SCAN_STATE_WAITING;
    mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, TRUE);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_AP_LIST_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_ap_list_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_ap_list_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i, ap_list_num;
    mmi_abm_wifi_ap_list_cnf_struct *cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF received. prev_state=%s, state %s,",
                         state2str(g_wlan_display_context.prev_state), state2str(g_wlan_display_context.state));

    cnf = (mmi_abm_wifi_ap_list_cnf_struct*) info;

    if (g_wlan_display_context.scan_state == WLAN_SCAN_STATE_WAITING)
    {
        if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_SCAN_PROCESSING ||
            IsScreenPresent(SCR_ID_DTCNT_WLAN_SCAN_PROCESSING) == MMI_TRUE)
        {
            ap_list_num = g_wlan_display_context.ap_list_num;

            for (i = 0; i < cnf->num && ap_list_num < WNDRV_MAX_SCAN_RESULTS_NUM; i++)
            {
                if (cnf->ap_list[i].ssid_len == 0 || cnf->ap_list[i].ssid[0] == 0)
                {
                    continue;   /* Discard hidden AP */
                }

                memcpy(
                    &g_wlan_display_context.ap_list[ap_list_num++],
                    &cnf->ap_list[i],
                    sizeof(supc_abm_bss_info_struct));
            }

            g_wlan_display_context.ap_list_num = ap_list_num;

            if (cnf->more_flag == 0)
            {
                ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF);

                if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_SCAN_PROCESSING)
                {
                    mmi_wlan_entry_scan_result();
                    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);
                }
                else
                {
                    HistoryReplace(
                        SCR_ID_DTCNT_WLAN_SCAN_PROCESSING,
                        SCR_ID_DTCNT_WLAN_SCAN_RESULT,
                        mmi_wlan_entry_scan_result);
                }
            }
            else
            {
                return;
            }
        }

    }
    else if (g_wlan_display_context.scan_state == WLAN_SCAN_STATE_ABORTING)
    {
        if (cnf->more_flag != 0)
        {
            /* Discard the result */
            return;
        }
    }

    mmi_wlan_update_status_icon(g_wlan_display_context.prev_status_icon, FALSE);
    g_wlan_display_context.scan_state = WLAN_SCAN_STATE_NULL;
    
    if (do_action() == TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_wlan_display_context.prev_state = g_wlan_display_context.state;
    if(g_wlan_setting_context.start_on_bootup == FALSE)
    {
        g_wlan_setting_context.start_on_bootup = TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_ipaddr_update_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_ipaddr_update_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_ipaddr_update_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_abm_ipaddr_update_ind_struct*) info;

    memcpy(g_wlan_display_context.curr_ip_addr, ind->ip_addr, 4);
    memcpy(g_wlan_display_context.curr_netmask, ind->netmask, 4);
    memcpy(g_wlan_display_context.curr_gateway, ind->gateway, 4);
    memcpy(g_wlan_display_context.curr_dns1, ind->pri_dns_addr, 4);
    memcpy(g_wlan_display_context.curr_dns2, ind->sec_dns_addr, 4);

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    g_wlan_display_context.notification_pending = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_supc_mmi_wifi_curr_ap_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_supc_mmi_wifi_curr_ap_info_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supc_mmi_wifi_curr_ap_info_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (supc_mmi_wifi_curr_ap_info_ind_struct*) info;

    g_wlan_display_context.rssi = (S32) ind->rssi;
    g_wlan_display_context.current_data_rate = ind->current_data_rate;

    if (GetActiveScreenId() == SCR_ID_DTCNT_WLAN_CONN_STATUS)
    {
        mmi_wlan_redraw_conn_status_screen();
    }
    else if(GetActiveScreenId() == SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS)
    {
        mmi_wlan_redraw_network_settings_screen();
    }
    mmi_wlan_update_signal_level_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_activate_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_activate_req_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_abm_wifi_activate_req_rej_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not allowed when flight mode switching is in progress */
    if (g_wlan_display_context.app_callback != NULL || mmi_bootup_get_active_flight_mode() != 0 ||
        mmi_netset_get_active_preferred_mode() == 0 || g_wlan_display_context.prof_num < 1)
    {
        p = (mmi_abm_wifi_activate_req_rej_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_activate_req_rej_struct));
        p->cause = WLAN_NOT_AVAILABLE;
        
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_ABM;
        Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ;
        Message.oslDataPtr = (oslParaType*) p;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        return;
    }
    else if (g_wlan_display_context.state == WLAN_STATE_CONNECT_WAIT)
    {
        p = (mmi_abm_wifi_activate_req_rej_struct*) OslConstructDataPtr(sizeof(mmi_abm_wifi_activate_req_rej_struct));
        p->cause = WLAN_CONNECTING;

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_ABM;
        Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ;
        Message.oslDataPtr = (oslParaType*) p;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        return;
    }
    if(g_wlan_display_context.prev_state == WLAN_STATE_NULL)
    {
        g_wlan_display_context.init_by_soc = TRUE;
    }
    else
    {
        g_wlan_display_context.init_by_soc = FALSE;
    }
    mmi_wlan_send_connect_req(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_wifi_deactivate_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_wifi_deactivate_req_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not allowed when flight mode switching is in progress */
    if (g_wlan_display_context.app_callback != NULL || mmi_bootup_get_active_flight_mode() != 0 ||
        mmi_netset_get_active_preferred_mode() == 0)
    {
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_ABM;
        Message.oslMsgId = MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_REJ;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        return;
    }
    mmi_wlan_send_disconnect_req();
    if(g_wlan_display_context.init_by_soc)
    {
        mmi_wlan_send_deinit_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reset_hw_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_reset_hw_on(FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_setting_context.start_on_bootup == TRUE)
    {
        if (g_wlan_display_context.prof_num > 0)
        {
            mmi_wlan_send_connect_req(NULL);
        }
        else
        {
            mmi_wlan_send_init_req();
        }
        
        ASSERT(g_wlan_display_context.app_callback == NULL);
        if(callback != NULL)
        {
            g_wlan_display_context.app_callback = callback;
        }
        return;
    }
    if(callback != NULL)
    {
        callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reset_hw_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_reset_hw_off(FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.state != WLAN_STATE_NULL)
    {
        switch (g_wlan_display_context.prev_state)
        {
            case WLAN_STATE_INIT:
                mmi_wlan_send_deinit_req();
                break;
            case WLAN_STATE_CONNECTED:
                mmi_wlan_send_disconnect_req();
                mmi_wlan_send_deinit_req();
                break;
        }
        ASSERT(g_wlan_display_context.app_callback == NULL);
        if(callback != NULL)
        {
            g_wlan_display_context.app_callback = callback;
        }
        return;
    }
    if(callback != NULL)
    {
        callback();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_ipaddr_change_req_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_ipaddr_change_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_abm_ipaddr_change_req_struct *p;
    mmi_wlan_profile_struct *profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.state != WLAN_STATE_CONNECTED)
    {
        return;
    }

    if (g_wlan_display_context.connected_wlan_profile == NULL)
    {
        profile = &g_wlan_display_context.temp_profile;
    }
    else
    {
        profile = g_wlan_display_context.connected_wlan_profile;
    }

    g_wlan_display_context.notification_pending = FALSE;

    p = (mmi_abm_ipaddr_change_req_struct*) OslConstructDataPtr(sizeof(mmi_abm_ipaddr_change_req_struct));

    /* SetProtocolEventHandler(mmi_wlan_abm_ipaddr_change_cnf_hdlr, MSG_ID_MMI_ABM_IPADDR_CHANGE_CNF); */

    p->use_dhcp = profile->use_dhcp;
    memcpy(p->ip_addr, profile->ip_addr, MAX_IPADDRES_LEN);
    memcpy(p->netmask, profile->netmask, MAX_IPADDRES_LEN);
    memcpy(p->gateway, profile->gateway, MAX_IPADDRES_LEN);
    memcpy(p->pri_dns_addr, profile->dns1, MAX_IPADDRES_LEN);
    memcpy(p->sec_dns_addr, profile->dns2, MAX_IPADDRES_LEN);
    /* g_wlan_display_context.use_dhcp = profile->use_dhcp; */

    /* Do not update display IP information if DHCP is TRUE */
    if(!profile->use_dhcp)
    {
        memcpy(g_wlan_display_context.curr_ip_addr, profile->ip_addr, 4);
        memcpy(g_wlan_display_context.curr_netmask, profile->netmask, 4);
        memcpy(g_wlan_display_context.curr_gateway, profile->gateway, 4);
        memcpy(g_wlan_display_context.curr_dns1, profile->dns1, 4);
        memcpy(g_wlan_display_context.curr_dns2, profile->dns2, 4);
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = MSG_ID_MMI_ABM_IPADDR_CHANGE_REQ;
    Message.oslDataPtr = (oslParaType*) p;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abm_ipaddr_conflict_ind_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_abm_ipaddr_conflict_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.notification_pending == TRUE ||
        IsScreenPresent(SCR_ID_DTCNT_WLAN_IPADDR_CONFILICT_IND) == TRUE ||
        GetActiveScreenId() == SCR_ID_DTCNT_WLAN_IPADDR_CONFILICT_IND)
    {
        return;
    }

    TurnOnBacklight(1);

    /* Display it in idle screen or display popup otherwise */
    if (isInCall())
    {
        playRequestedTone(WARNING_TONE);
        g_wlan_display_context.notification_pending = TRUE;
    }
    else
    {
        g_wlan_display_context.play_tone_flag = TRUE;
        mmi_dtcnt_entry_ipaddr_conflict_ind();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_add_event_notify_hdlr
 * DESCRIPTION
 *  add event notify callback handler.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_wlan_add_event_notify_hdlr(FuncPtrShort event_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MAX_WLAN_EVENT_REGISTRAR_NUM; i++)
    {
        if(g_wlan_display_context.event_callback[i] == NULL)
        {
            g_wlan_display_context.event_callback[i] = event_callback;
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_remove_event_notify_hdlr
 * DESCRIPTION
 *  remove event notify callback handler.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_wlan_remove_event_notify_hdlr(FuncPtrShort event_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MAX_WLAN_EVENT_REGISTRAR_NUM; i++)
    {
        if(g_wlan_display_context.event_callback[i] == event_callback)
        {
            g_wlan_display_context.event_callback[i] = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_event_notify
 * DESCRIPTION
 *  dispatch event notofication to callback handler.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_send_event_notify(dtcnt_bearer_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MAX_WLAN_EVENT_REGISTRAR_NUM; i++)
    {
        if(g_wlan_display_context.event_callback[i] != NULL)
        {
            g_wlan_display_context.event_callback[i]((U16)state);
        }
    }
}


#endif /* __MMI_WLAN_FEATURES__ */ 

