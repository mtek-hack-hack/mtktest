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
 * Created by Tomas Mandorf	20021003	09:42
 * 
 * Description:
 *		This file contains code to edit Profiles.
 *
 */


#ifndef _bra_prof_h
#define _bra_prof_h

#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif
#ifndef _brs_if_h
#include "brs_if.h"
#endif

#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif




/************************************************************
 * Defines
 ************************************************************/
/* profile key type */
#define BRA_PROF_ID_CMN  0
#define BRA_PROF_ID_BRA  1
#define BRA_PROF_ID_MMS  2



/*---------------------------Number of common keys-----------------------------*/

#define BRA_PROF_N_CMN_KEYS_FOR_BASE_WAP            13


#ifdef BRA_CONFIG_MMS
#define BRA_PROF_N_CMN_KEYS_FOR_BASE_MMS            15
#else
#define BRA_PROF_N_CMN_KEYS_FOR_BASE_MMS            0
#endif /* BRA_CONFIG_MMS */


#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#define BRA_PROF_N_CMN_KEYS_FOR_WHITELIST           1
#else
#define BRA_PROF_N_CMN_KEYS_FOR_WHITELIST           0
#endif


#ifdef BRA_CFG_DUAL_SIM
#define BRA_PROF_N_CMN_KEYS_FOR_DUAL_SIM            4 //6?
#else
#define BRA_PROF_N_CMN_KEYS_FOR_DUAL_SIM            0
#endif



#define BRA_PROF_N_CMN_KEYS      (BRA_PROF_N_CMN_KEYS_FOR_BASE_WAP + \
                                  BRA_PROF_N_CMN_KEYS_FOR_BASE_MMS + \
                                  BRA_PROF_N_CMN_KEYS_FOR_WHITELIST + \
                                  BRA_PROF_N_CMN_KEYS_FOR_DUAL_SIM)




/*---------------------------Number of profile keys-----------------------------*/

#define BRA_PROF_N_PROFILE_KEYS_FOR_BASE            21


#ifdef BRA_CONFIG_UIS_PUSH_SL
#define BRA_PROF_N_PROFILE_KEYS_FOR_UIS_PUSH_SL     1
#else
#define BRA_PROF_N_PROFILE_KEYS_FOR_UIS_PUSH_SL     0
#endif

#ifdef BRA_CONFIG_PUSH
#define BRA_PROF_N_PROFILE_KEYS_FOR_PUSH            4  //only 4 is used
#else
#define BRA_PROF_N_PROFILE_KEYS_FOR_PUSH            0  
#endif


#ifdef BRA_CFG_PROF_FALLBACK
#define BRA_PROF_N_PROFILE_KEYS_FOR_FALLBACK        4
#else
#define BRA_PROF_N_PROFILE_KEYS_FOR_FALLBACK        0
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
#define BRA_PROF_N_PROFILE_KEYS_FOR_CONN_ASK        2
#else
#define BRA_PROF_N_PROFILE_KEYS_FOR_CONN_ASK        0
#endif



#define BRA_PROF_N_PROFILE_KEYS         (BRA_PROF_N_PROFILE_KEYS_FOR_BASE + \
                                         BRA_PROF_N_PROFILE_KEYS_FOR_UIS_PUSH_SL + \
                                         BRA_PROF_N_PROFILE_KEYS_FOR_PUSH + \
                                         BRA_PROF_N_PROFILE_KEYS_FOR_FALLBACK + \
                                         BRA_PROF_N_PROFILE_KEYS_FOR_CONN_ASK)



/*---------------------------common keys for WAP -------------------------------------*/

#define BRA_CMN_KEY_OBJ_ASK             BRS_REGISTRY_KEY_OBJECT_ASK
#define BRA_CMN_KEY_OBJ_LOAD            BRS_REGISTRY_KEY_OBJECT_LOAD
#define BRA_CMN_KEY_TIMEOUT             BRS_REGISTRY_KEY_REQUEST_TIMEOUT
#define BRA_CMN_KEY_CACHEON             BRS_REGISTRY_KEY_CACHE_ON
#define BRA_CMN_KEY_COOKIES             "enabled"
#define BRA_CMN_KEY_USER_TIMEOUT        "user_timeout"
#define BRA_CMN_KEY_PUSH_ON             "push_on"

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#define BRA_CMN_KEY_PUSH_TRUSTSETTING   "push_trustSetting"
#endif

#define BRA_CMN_KEY_PUSH_SLSETTING      "push_SLSetting"
#define BRA_CMN_KEY_USER_AGT            "user_agt"
#define BRA_CMN_KEY_ACCEPT_HEADER       "accept_header"
#define BRA_CMN_KEY_BRA_PROF_ID         "bra_prof_id"
#define BRA_CMN_KEY_OFFLINE_PAGE        "offline_page"
#define BRA_CMN_KEY_MMS_PROF_ID         "mms_prof_id"

#ifdef BRA_CONFIG_MMS
#define BRA_CMN_KEY_MMS_VER             "mms_ver"
#endif

#ifdef BRA_CFG_DUAL_SIM
#define BRA_CMN_KEY_BRA_SIM_ID          "bra_sim_id"            /* activated SIM card for WAP : SIM1, SIM2*/
#define BRA_CMN_KEY_BRA_SIM_ID_IS_ASK   "bra_sim_is_ask"        /* is select ask */   

#define BRA_CMN_KEY_BRA_PROF_ID_SLAVE   "bra_prof_id_sim2"         /* activated profile id for SIM2 */ 
#define BRA_CMN_KEY_MMS_PROF_ID_SLAVE   "mms_prof_id_sim2"        /* activated profile id for SIM2 */
#endif /* BRA_CFG_DUAL_SIM */




/*---------------------------profile keys-------------------------------------*/


#define BRA_PROF_KEY_PROF_STR           "prof_str" /*This itme must be the first key*/
#define BRA_PROF_KEY_PRX_NAME           "px_name"       //no use
#define BRA_PROF_KEY_NET_ID             BRS_REGISTRY_KEY_NETWORK_ACCOUNT_ID
#define BRA_PROF_KEY_CASHSIZE           "maxsize"
#define BRA_PROF_KEY_COOKIES            "enabled"
#define BRA_PROF_KEY_CON_TYPE           BRS_REGISTRY_KEY_CONNECTION_TYPE
#define BRA_PROF_KEY_HISTSIZE           BRS_REGISTRY_KEY_HISTORY_SIZE
#define BRA_PROF_KEY_LDNOMIME           BRS_REGISTRY_KEY_OBJECT_LOAD_NULL_MIME
#define BRA_PROF_KEY_PRX_ADDR           BRS_REGISTRY_KEY_PROXY_ADDRESS
#define BRA_PROF_KEY_PRX_PWD            BRS_REGISTRY_KEY_PROXY_PASSWORD
#define BRA_PROF_KEY_PRX_PORT           BRS_REGISTRY_KEY_PROXY_PORT
#define BRA_PROF_KEY_PRX_RLM            BRS_REGISTRY_KEY_PROXY_REALM
#define BRA_PROF_KEY_PRX_SECP           BRS_REGISTRY_KEY_PROXY_SECURE_PORT
#define BRA_PROF_KEY_PRX_UID            BRS_REGISTRY_KEY_PROXY_USERNAME
#define BRA_PROF_KEY_REFRESH            BRS_REGISTRY_KEY_REFRESH_ENABLED
#define BRA_PROF_KEY_USE_CAHCE          "usecache"
#define BRA_PROF_KEY_CACHE_MODE         "mode"    //use as latter
#define BRA_PROF_KEY_USE_CSS            BRS_REGISTRY_KEY_CSS_ENABLED
#define BRA_PROF_KEY_UA_HEADER          BRS_REGISTRY_KEY_USER_AGENT_HEADER  //no use
#define BRA_PROF_KEY_UA_PROF            "uaprof"
#define BRA_PROF_KEY_INLINE_DO          BRS_REGISTRY_KEY_WML_INLINE_DO

#ifdef BRA_CONFIG_UIS_PUSH_SL
#define BRA_PROF_KEY_LOAD_SL            "load_sl"
#endif

#ifdef BRA_CONFIG_PUSH
#define BRA_PROF_KEY_PUSH_SECURITY      "security"
#define BRA_PROF_KEY_PUSH_C_TYPE        "conntype"
#define BRA_PROF_KEY_PUSH_NET_ID        "net_id"        //no use
#define BRA_PROF_KEY_SMS_NWA            "sms_nwa"
#define BRA_PROF_KEY_UDP_NWA            "udp_nwa"
#endif

#define BRA_PROF_KEY_HOMEPAGE_TITLE     "homepage_title"
#define BRA_PROF_KEY_HOMEPAGE_URL       "homepage_url"

#ifdef BRA_CFG_PROF_FALLBACK
#define BRA_PROF_KEY_NET_ID_DUAL        "dual_acc_id"
#define BRA_PROF_KEY_NET_ID_GPRS        "acc_id_gprs"
#define BRA_PROF_KEY_NET_ID_GSM         "acc_id_gsm"
#define BRA_PROF_KEY_URL_FALLBACK       "url_fallback"
#endif /* BRA_CFG_PROF_FALLBACK */


#ifdef BRA_CFG_CONN_ALWAYS_ASK
#define BRA_PROF_KEY_NET_ID_IS_ASK       "net_id_is_ask"  // 0 not ask 1 ask not asked, 2 asked, net id is ok
#define BRA_PROF_KEY_NET_ID_ASKED        "net_id_asked"       
#endif




/*---------------------------registry keys--------------------------------*/

/*This key is not included in profiles*/
#define BRA_PROF_KEY_PROF_ID            "prof_id"
#define BRA_PROF_KEY_PROF_ID_PATH       "/BRA"




/*---------------------------common define-------------------------------*/

#define BRA_PROF_GET_PROF_IDX(id, i) \
   ((id == BRA_PROF_ID_BRA) ? i : i + BRA_CFG_N_WAP_PROFILES)

#define BRA_PROF_GET_PROF_NUM(id) \
   ((id == BRA_PROF_ID_BRA) ? BRA_CFG_N_WAP_PROFILES : BRA_CFG_N_MMS_PROFILES)


#ifdef BRA_CFG_DUAL_SIM
#define BRA_PROF_GET_SIM_IDX(sim_id, prof_id) \
    (((sim_id) == BRA_SIM_ID_SIM2) ? ((prof_id) + BRA_CFG_N_PROFILES) : (prof_id))
#else /* BRA_CFG_DUAL_SIM */
#define BRA_PROF_GET_SIM_IDX(sim_id, prof_id) (prof_id)
#endif

/**********************************************************************
 * Types
 **********************************************************************/
typedef struct{
  int             n_items;
  MsfStringHandle s[1];
}bra_prof_names_t;

typedef struct{
  char            *prof_name;
  int             con_type;
}bra_prof_list_entry_t;

typedef struct{
  int             n_items;
  bra_prof_list_entry_t prof[1];
}bra_prof_list_t;

typedef struct{
  char            *prof_name;
  MSF_UINT8       id;
  int             con_type;
  unsigned char   prx_ip[4];
  MSF_UINT16      prx_port;
  char            *username;
  char            *password;
  int              net_id;
  int              net_id2;
}bra_prof_content_t;

typedef void (*bra_prof_loaded_done_t)(void);
typedef void (*bra_prof_key_saved_t)(void);
typedef void (*bra_prof_key_read_t)();
typedef void (*bra_prof_commit_prof_t)(char *path, char *key, int type, int ival, char *sval);
/**********************************************************************
 * Exported Functions
 **********************************************************************/

/*
 * This function initializes the Profile variables 
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 *
 * RETURN    : void
 */
void 
bra_prof_initialize (void);

/*
 * This function initializes the profile routines and tries to load 
 * the profile specified by profile_name.
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 * profile_id: Profile ID
 * callback  : Pointer to a function the Profile manager should call when
 *             finished
 *
 * RETURN    : void
 */
void
bra_prof_load_profile (int id, int profile_id, bra_prof_loaded_done_t callback);


void 
bra_prof_commit_profile (void);




/*
 *  This function writes the new profile name to the register.  
 *  It then destroys the old profile and load the new one.
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 * profile_id: Profile ID
 * callback  : Pointer to a function the Profile manager should call when
 *             finished
 *
 * RETURN    : void
 */
void 
bra_prof_set_selected_profile (int id, int prof_id, bra_prof_loaded_done_t callback);


/*
 *  This function returns the id of the currently used profile
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 *
 * RETURN    : Profile ID
 */
int
bra_prof_get_absolute_profile (void);

int
bra_prof_get_relative_profile (void);

/*
 * This function Destroy all allocated memory in the profile management routines
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 *
 * RETURN    : void
 */
void 
bra_prof_destroy (int id);

/*
 * This function return 1 or 0 depending on if any profile is loaded. Note there 
 * is no check which profile is loaded.
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 *
 * RETURN    : 1 if a profile is loaded, else 0
 */
int
bra_prof_is_profile_loaded (int id);



/*
 * This function changes the value on a specific key in the active profile
 * the key must be configured to be of type string. The new profile value 
 * is stored on file and in register (if configured).A profile must be 
 * loaded before a request is made
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 * key       : key to be changed
 * value     : new string value
 *
 * RETURN    : 1 if success, , and -1 if error. 
 */
int
bra_prof_change_key_str_value (int id, char *key, char* value, bra_prof_key_saved_t callback);

/*
 * This function changes the value on a specific key in the active profile
 * the key must be configured to be of type integer. The new profile value 
 * is stored on file and in register (if configured).A profile must be 
 * loaded before a request is made
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 * key       : key to be changed
 * value     : new integer value
 *
 * RETURN    : 1 if success, , and -1 if error. 
 */
int
bra_prof_change_key_int_value (int id, char *key, int value, bra_prof_key_saved_t callback);

/*
 * This function returns the string value of key in the current profile. 
 *
 * id        : ID, Not used in current implementation
 * key       : key to be changed
 *
 * RETURN    : The string value of key. If Key is undefined the return value is NULL.
 */
char*
bra_prof_get_key_str_value (int id, char *key);

/*
 * This function returns the integer value of key in the current profile. 
 *
 * id        : ID, Not used in current implementation
 * key       : key to be changed
 *
 * RETURN: the integer value of key. If Key is undefined the return value is 0.
 */
int
bra_prof_get_key_int_value (int id, char *key);

/*
 * This function returns a struct with all profile names associated with id.   
 * If no specific name have been added for the profile, the string specified by
 * BRA_STR_PROFILE + index is used
 *
 * NOTE! the msf strings returned  must  be released by the calling function.
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementation
 *
 * RETURN    : Pointer to struct holding all available profile names
 */
bra_prof_names_t*
bra_prof_get_all_profile_names (int id);

char*
bra_prof_get_profile_name( int prof_index, const char* prof_name);

/*
 * This function create and display a menu where the user can select the   
 * active profile
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_prof_commit_key_int_value (int id, char *key, int value);

void
bra_prof_commit_key_str_value (int id, char *key, char* value);

void 
bra_prof_create_profile_menu (MSF_UINT8 id);

void 
bra_prof_create_profile_list_menu (int id, int sim_id);

void 
bra_prof_restore_act_profile (void);

void 
bra_prof_unload_profile (void);

int
bra_prof_get_profile_id (void);

const char *
bra_prof_get_cur_user_agent (void);

int 
bra_prof_off_line_read_profile_key (int prof_id, char *key, char *value);

int 
bra_prof_off_line_save_profile_key (int prof_id, char *key, char *value);

MSF_UINT8
bra_prof_offline_get_prof_list (bra_prof_list_t** prof_list_ptr);

MSF_UINT8
bra_prof_off_line_load_profile (int prof_id, bra_prof_content_t **prof_cont_ptr);




/*-----------------------------SIM profile------------------------------------------------------*/

void
bra_prof_load_sim_profile (int id, int sim_id, int prof_id, bra_prof_loaded_done_t callback);

void
bra_prof_set_sim_selected_profile(int id, int sim_id, int prof_id, bra_prof_loaded_done_t callback);

void
bra_prof_activate_sim_profile(int id, int sim_id, int prof_id);  

int
bra_prof_get_sim_absolute_profile(void);

bra_prof_names_t*
bra_prof_get_sim_all_profile_names (int id, int sim_id);

int 
bra_prof_get_profile_sim_id(void);

int
bra_prof_get_sim_activated_profile_id(int id, int sim_id);

void
bra_prof_restore_bra_active_profile(int is_commit);

int 
bra_prof_get_bra_profile_id_in_active_use(int *sim_id, int *prof_id);

int
bra_prof_get_sim_profile_id_in_active_use(int id, int mms_sim_id);

int
bra_prof_is_bra_profile_in_active_use(int id, int sim_id, int prof_id);

int
bra_prof_is_mms_profile_in_active_use(int id, int sim_id, int prof_id);


int
bra_prof_off_line_read_sim_profile_key(int id, int sim_id, int prof_id, char *key, char *value, int *buf_len);

int
bra_prof_off_line_save_sim_profile_key (int id, int sim_id, int prof_id, char *key, char *value);

MSF_UINT8
bra_prof_offline_get_sim_prof_list(int id, int sim_id, bra_prof_list_t  **prof_list_ptr);

MSF_UINT8
bra_prof_off_line_load_sim_profile (int id, int sim_id, int prof_id, bra_prof_content_t **prof_cont_ptr);

MSF_UINT8 
bra_prof_off_line_load_bra_active_profile(bra_prof_content_t  **prof_cont_ptr);

#endif /* _bra_prof_h */


