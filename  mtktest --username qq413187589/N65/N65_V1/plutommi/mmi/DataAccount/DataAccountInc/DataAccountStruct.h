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
 * DataAccountStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _PIXTEL_DATA_ACCOUNT_STRUCT_H
#define _PIXTEL_DATA_ACCOUNT_STRUCT_H

#include "DataAccountGprot.h"

typedef struct _service_data_account_node
{
    U8 Present;                                             /* If this item is presented */
    U8 DataAccountName[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];      /* Name of a Data Account */
    U8 DialNumber[(MAX_DIAL_NUM_LEN + 1) *ENCODING_LENGTH]; /* Dial Number of a Data Account */
    U8 UserName[MAX_USER_LEN + 1];                          /* User of a Data Account */
    U8 Passwd[MAX_PASSWD_LEN + 1];                          /* Password for a Data Account */
    U8 DialType;                                            /* Boolean : 0.Analoue or 1. SDN */
    U8 DataRate;                                            /* Boolean : 0.9.6 kbit/s or 1. 14.4 Kbit/s */
    U8 DnsAddress[MAX_PART_IP_ADDRESS];                     /* DNS IP Address */
    U8 iFdcs;                                               /* DCS indicator for account name. ascii:0, ucs2:length */
} DataAccountNode;

typedef struct _service_data_account_node_display
{
    S32 DialType;
    S32 DataRate;
#ifdef __MMI_GPRS_FEATURES__
    S32 AuthType;   /* pdp_auth_enum */
    U8 APN[(MAX_GPRS_MMI_APN_LEN + 1) *ENCODING_LENGTH];
    U8 *AuthTypeOption[GPRS_DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION];
    U8 GPRSCurrGetIndex;
    U8 GPRSCurrSelectItem;
    /* micha0112 */
    U8 GPRSCurrAppSelectItem;
    FuncPtrShort GPRSAppCallBack;
#endif /* __MMI_GPRS_FEATURES__ */ 
    U8 DataAccountName[(MAX_DATA_ACCOUNT_NAME_LEN + 1) *ENCODING_LENGTH];
    U8 DialNumber[(MAX_DIAL_NUM_LEN + 1) *ENCODING_LENGTH];
#ifdef MAX_GPRS_USERNAME
#if ( MAX_USER_LEN > MAX_GPRS_USERNAME)
    U8 UserName[(MAX_USER_LEN + 1) *ENCODING_LENGTH];
#else 
    U8 UserName[(MAX_GPRS_USERNAME + 1) *ENCODING_LENGTH];
#endif 
#else /* MAX_GPRS_USERNAME */ 
    U8 UserName[(MAX_USER_LEN + 1) *ENCODING_LENGTH];
#endif /* MAX_GPRS_USERNAME */ 

#ifdef MAX_GPRS_USERNAME
#if (MAX_PASSWD_LEN > MAX_GPRS_USERNAME)
    U8 Passwd[(MAX_PASSWD_LEN + 1) *ENCODING_LENGTH];
#else 
    U8 Passwd[(MAX_GPRS_USERNAME + 1) *ENCODING_LENGTH];
#endif 
#else /* MAX_GPRS_USERNAME */ 
    U8 Passwd[(MAX_PASSWD_LEN + 1) *ENCODING_LENGTH];
#endif /* MAX_GPRS_USERNAME */ 

    U8 IP1[MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 IP2[MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 IP3[MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 IP4[MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U16 IconList[MAX_INLINE_ITEM_DATA_ACCOUNT_LIST];
    U8 *DialTypeOption[DATA_ACCOUNT_INLINE_DIAL_TYPE_OPTION];
    U8 *DialRateOption[DATA_ACCOUNT_INLINE_DATA_RATE_OPTION];
    U8 CurrGetIndex;
    U8 CurrSelectItem;
    /* micha0112 */
    U8 CurrAppMainSelectItem;
    U8 CurrAppSelectItem;
    U8 sim_info;
    U8 always_ask;
    U8 app_call;
    U16 app_str_id;
    FuncPtrShort AppCallBack;
    U16 AppMenuID;
    FuncPtrU32 app_callback;
    FuncPtrU32Ext app_callback_ext;
    FuncPtr bearer_callbacks[MAX_SUB_MENUS];
    U8 bearers;
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
    U8 check_status;
#endif /* defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */
} DataAccountNodeDisplay;

#ifdef __MMI_GPRS_FEATURES__

typedef struct _gprs_service_data_account_node
{
    U8 Present;                                             /* If this item is presented */
    U8 DataAccountName[(MAX_GPRS_DATAACCOUNT_NAME + 1) *ENCODING_LENGTH];      /* Name of a Data Account */
    U8 APN[(MAX_GPRS_MMI_APN_LEN + 1) *ENCODING_LENGTH];    /* GPRS APN */
    U8 AuthType;                                            /* Authentication Type */
    U8 UserName[MAX_GPRS_USERNAME + 1];                     /* User of a Data Account */
    U8 Passwd[MAX_GPRS_USERPASSWD + 1];                     /* Password for a Data Account */
    U8 DnsAddress[MAX_PART_IP_ADDRESS];                     /* DNS IP Address */
    U8 iFdcs;                                               /* DCS indicator for account name. ascii:0, ucs2:length */
} GPRSDataAccountNode;

#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_WLAN_FEATURES__

typedef struct wlan_action_st
{
    struct wlan_action_st *next;
    wlan_action_enum action;
    void *data;
} wlan_action_struct;

typedef struct
{
    U8 index;
    U8 ssid[MAX_SSID_LEN]; /* 32 + 1 */
    #ifdef __CERTMAN_SUPPORT__
    U32 root_ca_id;
    U32 client_ca_id;
    #else
    kal_wchar root_ca_path[FMGR_MAX_PATH_LEN + 1];
    kal_wchar client_ca_path[FMGR_MAX_PATH_LEN + 1];
    kal_wchar private_key_path[FMGR_MAX_PATH_LEN + 1];
    #endif /* __CERTMAN_SUPPORT__ */
    U8 name[MAX_WLAN_PROF_NAME_LEN * 2];
    U8 priority;
    U32 profile_id;
    U8 ssid_len;
    U32 channel;
    U8 passphrase[MAX_PASSPHRASE_LEN]; /* 63 + 1 */
    U8 wep_key[MAX_WEP_KEYSTR_LEN]; /* 26 + 1 */
    U8 peap_version;
    U8 username[MAX_USERNAME_LEN]; /* 32 + 1 */
    U8 network_type;
    U8 password[MAX_PASSWORD_LEN]; /* 32 + 1 */
    U8 auth_mode;
    U8 private_key_passwd[MAX_PASSWORD_LEN]; /* 32 + 1 */
    U8 encrypt_mode;
    U8 psk[34];
    U32 auth_type1;
    U32 eap_peap_auth_type;
    U32 eap_ttls_auth_type;
    U8 wep_key_index;
    U8 wep_key_len;
    U8 wep_key_format;
    U8 ip_addr[MAX_IPADDRES_LEN];   /* IP address */
    U8 netmask[MAX_IPADDRES_LEN];   /* Netmask */
    U8 gateway[MAX_IPADDRES_LEN];   /* Gateway */
    U8 dns1[MAX_IPADDRES_LEN];      /* Primary DNS */
    U8 dns2[MAX_IPADDRES_LEN];      /* Secondary DNS */
    BOOL use_dhcp;
    BOOL use_anonymous;
} mmi_wlan_profile_struct;

typedef struct
{
    U8 dummy;
    BOOL start_on_bootup;
    U32 profile_id_count;
} mmi_wlan_setting_struct;

typedef struct
{
    U16 top_screen;
    BOOL insert_mode;
    BOOL modified;
    BOOL modified2;
    BOOL notification_pending;
    BOOL play_tone_flag;
    BOOL init_by_soc;
    
    U8 prof_num;    /* Defined profile number */
    U8 infra_prof_num;
    U8 adhoc_prof_num;

    wlan_action_struct *actions;
    wlan_state_enum prev_state;
    wlan_state_enum state;
    wlan_scan_state_enum scan_state;
    U8 mac_addr[MAX_MAC_ADDR_LEN];
    S32 rssi;
    S32 channel_number;
    U8 current_data_rate;

    S32 curr_channel_number;
    U8 curr_ip_addr[MAX_IPADDRES_LEN];                       /* IP address */
    U8 curr_netmask[MAX_IPADDRES_LEN];                       /* Netmask */
    U8 curr_gateway[MAX_IPADDRES_LEN];                       /* Gateway */
    U8 curr_dns1[MAX_IPADDRES_LEN];                          /* Primary DNS */
    U8 curr_dns2[MAX_IPADDRES_LEN];                          /* Secondary DNS */

    mmi_wlan_profile_struct temp_profile;

    mmi_wlan_profile_struct *connected_wlan_profile;
    mmi_wlan_profile_struct *active_wlan_profile_p;
    U8 active_wlan_profile_index;

    U8 bssid[MAX_MAC_ADDR_LEN];
    U8 ssid_len;
    U8 ssid[MAX_SSID_LEN];
    U8 name[MAX_WLAN_PROF_NAME_LEN *ENCODING_LENGTH];

    supc_abm_bss_info_struct *active_ap;
    supc_abm_bss_info_struct ap_list[WNDRV_MAX_SCAN_RESULTS_NUM];
    U8 ap_list_num;

    U16 icon_list[MAX_INLINE_ITEM_DATA_ACCOUNT_LIST];

    U8 *yes_no_opt[2];                              /* Inline selection list for "Yes" and "No" */
    U8 *network_type_opt[WLAN_NETWORK_TYPE_TOTAL];  /* Inline selection list for "Yes" and "No" */
    U8 *wep_key_index_opt[4];
    U8 *wep_key_len_opt[WLAN_WEP_KEY_ENCRYPT_TOTAL];
    U8 *wep_key_format_opt[WLAN_WEP_KEY_FORMAT_TOTAL];

    U16 prev_status_icon;
    U16 status_icon;

    U8 new_priority;

    S32 use_anonymous;
    S32 use_dhcp;
    S32 use_dhcp_dummy;                                 /* Associate with inline select only */
    UI_character_type ip_addr_str[4][MAX_IPADDRES_LEN]; /* IP address */
    UI_character_type netmask_str[4][MAX_IPADDRES_LEN]; /* Netmask */
    UI_character_type gateway_str[4][MAX_IPADDRES_LEN]; /* Gateway */
    UI_character_type dns1_str[4][MAX_IPADDRES_LEN];    /* Primary DNS */
    UI_character_type dns2_str[4][MAX_IPADDRES_LEN];    /* Secondary DNS */
    U8 ip_addr[MAX_IPADDRES_LEN];                       /* IP address */
    U8 netmask[MAX_IPADDRES_LEN];                       /* Netmask */
    U8 gateway[MAX_IPADDRES_LEN];                       /* Gateway */
    U8 dns1[MAX_IPADDRES_LEN];                          /* Primary DNS */
    U8 dns2[MAX_IPADDRES_LEN];                          /* Secondary DNS */

    S32 network_type;
    S32 network_type_dummy;
    U8 auth_mode;
    U8 encrypt_mode;
    U8 ssid_str[MAX_SSID_LEN * ENCODING_LENGTH];

    U32 auth_type1;
    U8 sel_auth_type1;

    U32 eap_peap_auth_type;
    U8 sel_eap_peap_auth_type;

    U32 eap_ttls_auth_type;
    U8 sel_eap_ttls_auth_type;

    U8 sel_auth_mode;
    U8 sel_encrypt_mode;
    S32 sel_wep_key_index;
    S32 sel_wep_key_len;
    S32 sel_wep_key_format;
    U8 wep_key_str[MAX_WEP_KEYSTR_LEN *ENCODING_LENGTH];
    U8 passphrase_str[(MAX_PASSPHRASE_LEN + 1) *ENCODING_LENGTH];

    S32 wep_key_index;
    S32 wep_key_len;
    S32 wep_key_format;
#ifdef __CERTMAN_SUPPORT__
    U32 root_ca_id;
    U32 root_trans_id;
    U32 client_ca_id;
    U32 client_ca_trans_id;
    S8 private_key_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
    S8 root_ca_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
    S8 client_user_name[(MAX_USERNAME_LEN + 1) *ENCODING_LENGTH];
#else
    S8 private_key_path[FMGR_PATH_BUFFER_SIZE];
    S8 root_ca_path[FMGR_PATH_BUFFER_SIZE];
    S8 client_ca_path[FMGR_PATH_BUFFER_SIZE];
#endif /* __CERTMAN_SUPPORT__ */
    S8 private_key_passwd_str[MAX_PASSWORD_LEN *ENCODING_LENGTH];
    U8 username_str[MAX_USERNAME_LEN *ENCODING_LENGTH];
    U8 password_str[MAX_PASSWORD_LEN *ENCODING_LENGTH];
    U8 passphrase[MAX_PASSPHRASE_LEN];

    S32 allow_peap0;
    S32 allow_peap1;

    FuncPtr app_callback;
    FuncPtrShort event_callback[MAX_WLAN_EVENT_REGISTRAR_NUM];
} mmi_wlan_display_struct;

typedef kal_bool(*EncodeFunc) (wifi_data_account_profile_struct *prof, mmi_wlan_profile_struct *profile, int phase);

typedef struct auth_plugin_st
{
    U32 val;
    U16 name_string_id;
    FuncPtr entry_func;
    EncodeFunc encode_func;
} auth_plugin_struct;


#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/*
 * Slim WLAN profile used during OTA provisioning to save memory space. It will
 * be allocated from 512-bytes control buffer pool.
 */
typedef struct
{
    U8 node_id[MAX_NODE_ID_LEN];                        /* UTF-8, 0-ended   */
    U8 name[MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH];  /* UCS2, 0-ended    */
    U8 ssid[MAX_SSID_LEN];                              /* ASCII, 0-ended   */
    U8 ssid_len;
    U8 network_type;
    U8 encrypt_mode;
    U8 auth_mode;
    U32 auth_type1;
    U8 username[MAX_USERNAME_LEN];
    U8 password[MAX_PASSWORD_LEN];
    U8 wep_key_index;
    U8 wep_key_len;
    U8 wep_key_format;
    U8 wep_key[MAX_WEP_KEYSTR_LEN];
    U8 passphrase[MAX_PASSPHRASE_LEN];
    U8 psk[32 + 1];                         /* Last byte: whether PSK is set */
} mmi_wlan_slim_profile_struct;

/*
 * Control block for WLAN OTA provisioning. It will be allocated from 256-
 * bytes control buffer pool. 
 */
typedef struct
{
    /* conf_id and doc_hdl are indicated by CCA. And we need to pass these two
       variable back to CCA when we send the response message. */
    U16 conf_id;        /* Configuration ID                                 */
    S32 doc_hdl;        /* Configuration document handle                    */
    
    /* node_id stores the id of a NAPDEF node. It is used to inform CCA that 
       this NAPDEF node has been installed. name is the profile name of a 
       NAPDEF node. It is possible there are multiple WLAN nodes in a NAPDEF 
       node such that we need to remember the name that will become the prefix
       of all such WLAN profiles. */
    U8 node_id[MAX_NODE_ID_LEN];                        /* UTF-8, 0-ended   */
    U8 name[MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH];  /* UCS2, 0-ended    */

    MMI_BOOL is_active; /* Enable to process node/param                     */
    U8 num_profiles;    /* Num of processed profiles                        */
    U8 iter;            /* Used to traverse profiles                        */
    S16 in_use;         /* The index of the profile that is used currently  */
    S16 choice;         /* The index of the profile that is to be replaced  */

    /* The variables 'src_idx' and 'dst_idx' provide linkage between 
       this->profile[] and g_wlan_prof_list[]. */
    S16 src_idx[MAX_WLAN_DATA_ACCOUNT_NUM];
    S16 dst_idx[MAX_WLAN_OTA_PROF_NUM];
    S16 sel_dst_idx[MAX_WLAN_DATA_ACCOUNT_NUM];

    /* Storage for incoming profiles. */
    mmi_wlan_slim_profile_struct *profile[MAX_WLAN_OTA_PROF_NUM];
} mmi_wlan_otap_struct;

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* _PIXTEL_DATA_ACCOUNT_STRUCT_H */ 

