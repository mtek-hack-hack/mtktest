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
#include "bra_cfg.h"
#include "bra_int.h" 
#include "bra_cmn.h"
#include "bra_prof.h"
#include "bra_file.h"
#include "bra_main.h"
#include "bra_str.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "brs_if.h"
#include "bra_set.h"
#include "bra_sig.h"

#include "msf_log.h"
#include "msf_core.h"
#include "msf_chrt.h"
#ifdef BRA_CONFIG_MMS
#include "mea_def.h"
#include "mea_cfg.h"
#include "mms_def.h"
#include "msf_url.h"
#include "mms_aApp.h"
#endif
#include "msm.h"
#include "kal_release.h"
#include "mmi_features.h" /* For the compile options of charsets */
#include "wapadp.h"
#include "wap_ps_struct.h"


#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif


#include "bra_cbm.h"




/*****************************************************************/
/*Profile block format                                           */
/*                                                               */
/* Profile id         1 bytes    0 .. 255         */
/* Profile sub id     1 bytes    0 .. BRA_CFG_N_PROFILES         */
/* Key id             1 bytes    0 .. BRA_PROF_N_PROFILE_KEYS    */
/* Key value length   2 bytes    0 .. MAX_INT16                  */
/* Key Value  n bytes n bytes                                    */
/*                                                               */
/* NOTE!: The profile id field is not used but is included for   */
/*        future use.                                            */
/*                                                               */
/*****************************************************************/


/**********************************************************************
 * Local Defines
 **********************************************************************/
#ifdef BRA_CFG_DUAL_SIM
#define BRA_PROF_MAX_FILE_SIZE      (5 * 1024 * BRA_CFG_MAX_SIM_NUM)
#else
#define BRA_PROF_MAX_FILE_SIZE      (5 * 1024) 
#endif /* BRA_CFG_DUAL_SIM */

#define BRA_PROF_INITIAL_SIZE       BRA_CFG_PROF_INITIAL_SIZE

#define BRA_PROF_DEFRAG_LIMIT       3000
#define BRA_PROF_SIZE_INCREMENT     1000 

#define BRA_PROF_BLOCK_HEADER_SIZE  5

#ifdef __DRM_SUPPORT__
#define DRM_CONTENT_TYPE   "application/vnd.oma.drm.rights+wbxml, application/vnd.oma.drm.rights+xml"
#define DRM_APPLICATION_ID "x-wap-application:drm.ua" 
#define DRM_APPLICATION_NO "8" 
#endif

#ifdef BRA_CONFIG_PROVISIONING
#define OTA_CONTENT_TYPE   "application/x-wap-prov.browser-settings,application/x-wap-prov.browser-bookmarks,application/vnd.wap.connectivity-wbxml"
#endif

/**********************************************************************
 * Local Types
 **********************************************************************/
 typedef enum
{
  BRA_PROF_ENUM_PROF_STR,
  BRA_PROF_ENUM_NET_ID,
  BRA_PROF_ENUM_CASHSIZE,
  BRA_PROF_ENUM_COOKIES,
  BRA_PROF_ENUM_CON_TYPE,
  BRA_PROF_ENUM_HISTSIZE,
  BRA_PROF_ENUM_LDNOMIME,
  BRA_PROF_ENUM_PRX_ADDR,
  BRA_PROF_ENUM_PRX_PWD,
  BRA_PROF_ENUM_PRX_PORT,
  BRA_PROF_ENUM_PRX_RLM,
  BRA_PROF_ENUM_PRX_SECP,
  BRA_PROF_ENUM_PRX_UID,
  BRA_PROF_ENUM_REFRESH,
  BRA_PROF_ENUM_USE_CAHCE,
  BRA_PROF_ENUM_USE_CSS,
  BRA_PROF_ENUM_UA_PROF,
  BRA_PROF_ENUM_INLINE_DO

#ifdef BRA_CONFIG_UIS_PUSH_SL
  ,BRA_PROF_ENUM_LOAD_SL
#endif

#ifdef BRA_CONFIG_PUSH
  ,BRA_PROF_ENUM_PUSH_SECURITY
  ,BRA_PROF_ENUM_PUSH_C_TYPE
  ,BRA_PROF_ENUM_SMS_NWA
  ,BRA_PROF_ENUM_UDP_NWA
#endif

 ,BRA_PROF_ENUM_HOMEPAGE_TITLE
 ,BRA_PROF_ENUM_HOMEPAGE_URL
 ,BRA_PROF_ENUM_CACHE_MODE

#ifdef BRA_CFG_PROF_FALLBACK
 ,BRA_PROF_ENUM_NET_ID_IS_DUAL
 ,BRA_PROF_ENUM_NET_ID_GPRS
 ,BRA_PROF_ENUM_NET_ID_GSM
 ,BRA_PROF_ENUM_URL_FALLBACK
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
 ,BRA_PROF_ENUM_NET_ID_IS_ASK
 ,BRA_PROF_ENUM_NET_ID_ASKED
#endif

 ,BRA_PROF_ENUM_MAX_NUM
} bra_prof_key_id_enum;


typedef enum
{
  BRA_PROF_SAVE_PROF_STR,
  BRA_PROF_SAVE_NET_ID,
  BRA_PROF_SAVE_CON_TYPE,
  BRA_PROF_SAVE_PRX_ADDR,
  BRA_PROF_SAVE_PRX_PWD,
  BRA_PROF_SAVE_PRX_PORT,
  BRA_PROF_SAVE_PRX_UID,
  BRA_PROF_SAVE_HOMEPAGE_TITLE,
  BRA_PROF_SAVE_HOMEPAGE_URL,

#ifdef BRA_CFG_PROF_FALLBACK
  BRA_PROF_SAVE_NET_ID_DUAL,
  BRA_PROF_SAVE_NET_ID_GPRS,
  BRA_PROF_SAVE_NET_ID_GSM,
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
  BRA_PROF_SAVE_NET_ID_IS_ASK,
  BRA_PROF_SAVE_NET_ID_ASKED,
#endif
  BRA_PROF_SAVE_KEY_NUM
}bra_prof_save_key_id_enum;

typedef union {
    int   i_value;
    char *s_value;
} bra_prof_item_t;

typedef struct {
  int   n_items; 
  bra_prof_item_t items[1]; 
}bra_prof_profile_t;

typedef struct {
  char      *profile_name;
  int       con_type;  
  MSF_INT16  index_list[BRA_PROF_SAVE_KEY_NUM];
} bra_prof_available_profiles_t;

typedef struct{
  int  id;
#ifdef BRA_CFG_DUAL_SIM
  int  sim_id;
#endif
  int  profile_id;
  int  profile_is_loaded;
  bra_prof_loaded_done_t callback;  
  void *file_handle;
  bra_prof_profile_t *profile;
  bra_prof_available_profiles_t *available_profiles;
  bra_prof_item_t cmn_items[BRA_PROF_N_CMN_KEYS]; 
  MSF_INT16  cmn_index_list[BRA_PROF_N_CMN_KEYS];
}bra_profiles_t;

typedef struct{
  int  id;
  int  profile_id;
  int  key_id;
  int  size;
  char*  value;
}bra_prof_block_t;


/* Select Profile menu */
typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_prof_profile_menu_t;

typedef struct{
  char* const key;
  int   type;  /*0 = Int; 1 = String*/
  int   path;  /*-1 specifies that the key should not be written to any register*/
  int   idx_id;
}bra_prof_key_t;

typedef struct{
  char* const key;
  int   type;  /*0 = Int; 1 = String*/
  int   path;  /*-1 specifies that the key should not be written to any register*/
  int   modId;
}bra_prof_cmn_key_t;

/**********************************************************************
 * const variables
 **********************************************************************/
static const char * const bra_prof_cmn_key_path_table[] =
{
  "/BRA",
  "/BRS/BRA",
  "/STK/cookie"
#ifdef BRA_CONFIG_MMS
  ,MMS_REG_PATH_IMMEDIATE_RETRIEVAL,
  MMS_REG_PATH_REPORT,
  MMS_REG_PATH_RETRIEVAL,
  MEA_REG_PATH_MMS,
  MMS_REG_PATH_COM_MMSC
#endif
};

static const bra_prof_cmn_key_t bra_prof_cmn_key_table[BRA_PROF_N_CMN_KEYS] = 
{
  {BRA_CMN_KEY_BRA_PROF_ID,   0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_MMS_PROF_ID,   0, -1,  BRA_PROF_ID_BRA},

  {BRA_CMN_KEY_OBJ_ASK,       1,  1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_OBJ_LOAD,      1,  1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_TIMEOUT,       0,  1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_USER_TIMEOUT,  0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_PUSH_ON,       0, -1,  BRA_PROF_ID_BRA},

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
  {BRA_CMN_KEY_PUSH_TRUSTSETTING,       0, -1,  BRA_PROF_ID_BRA},
#endif

  {BRA_CMN_KEY_PUSH_SLSETTING,0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_USER_AGT,      0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_ACCEPT_HEADER, 0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_OFFLINE_PAGE , 0, -1,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_COOKIES,       0,  2,  BRA_PROF_ID_BRA},
  {BRA_CMN_KEY_CACHEON ,      0,  1,  BRA_PROF_ID_BRA}       

#ifdef BRA_CONFIG_MMS
  ,{MMS_REG_KEY_IMMEDIATE_RETRIEVAL, 0, 3, BRA_PROF_ID_MMS},
  {MMS_REG_KEY_CLASS_ADVERTISEMENT, 0, 3 , BRA_PROF_ID_MMS},
  {MMS_REG_KEY_ANONYMOUS_SENDER,    0, 3 , BRA_PROF_ID_MMS},
  {MMS_REG_KEY_REPORT_ALLOWED,      0, 4 , BRA_PROF_ID_MMS},
  {MMS_REG_KEY_MAX_RETRIEVAL_SIZE,  0, 5 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_READ_REPORT,         0, 6 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_DELIVERY_REPORT,     0, 6 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_PRIORITY,            0, 6 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_EXP_TIME,            0, 6 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_SEND_READ_REPORT,    0, 6 , BRA_PROF_ID_MMS},
  {BRA_CMN_KEY_MMS_VER,             0, -1, BRA_PROF_ID_MMS},
  {MMS_REG_KEY_NOTIFY_RESP_MODE,    0, 7 , BRA_PROF_ID_MMS},
  {MMS_REG_KEY_RETRIEVAL_ROAM_MODE, 0, 5 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_SLIDE_DUR,           0, 6 , BRA_PROF_ID_MMS},
  {MEA_REG_KEY_DELIVERY_TIME,       0, 6 , BRA_PROF_ID_MMS}
#endif  

#ifdef BRA_CFG_DUAL_SIM
  ,{BRA_CMN_KEY_BRA_SIM_ID,           0, -1, BRA_PROF_ID_BRA}
  ,{BRA_CMN_KEY_BRA_SIM_ID_IS_ASK,    0, -1, BRA_PROF_ID_BRA}
  ,{BRA_CMN_KEY_BRA_PROF_ID_SLAVE,    0, -1, BRA_PROF_ID_BRA}
  ,{BRA_CMN_KEY_MMS_PROF_ID_SLAVE,    0, -1, BRA_PROF_ID_BRA}
#endif /* BRA_CFG_DUAL_SIM */
};

static const char * const bra_prof_key_path_table[] = 
{
  "/BRA",
  "/BRS/BRA",
  "/STK/cookie",
  "/STK/cache",
  "/PHS/Def_Conn",
  "/PHS",
  "/PHS/SIR",
  "/STK"
};

static const bra_prof_key_t bra_prof_key_table[BRA_PROF_N_PROFILE_KEYS] = 
{
  {BRA_PROF_KEY_PROF_STR,   1,  -1, BRA_PROF_SAVE_PROF_STR},
  {BRA_PROF_KEY_NET_ID,     0,  1,  BRA_PROF_SAVE_NET_ID},
  {BRA_PROF_KEY_CASHSIZE,   0,  3,  -1},       
  {BRA_PROF_KEY_COOKIES,    0,  -1, -1},        
  {BRA_PROF_KEY_CON_TYPE,   0,  1,  BRA_PROF_SAVE_CON_TYPE},
  {BRA_PROF_KEY_HISTSIZE,   0,  1,  -1},       
  {BRA_PROF_KEY_LDNOMIME,   0,  1,  -1},       
  {BRA_PROF_KEY_PRX_ADDR,   1,  1,  BRA_PROF_SAVE_PRX_ADDR},
  {BRA_PROF_KEY_PRX_PWD,    1,  1,  BRA_PROF_SAVE_PRX_PWD},   
  {BRA_PROF_KEY_PRX_PORT,   0,  1,  BRA_PROF_SAVE_PRX_PORT},
  {BRA_PROF_KEY_PRX_RLM,    1,  1,  -1},       
  {BRA_PROF_KEY_PRX_SECP,   0,  1,  -1},       
  {BRA_PROF_KEY_PRX_UID,    1,  1,  BRA_PROF_SAVE_PRX_UID},
  {BRA_PROF_KEY_REFRESH,    0,  1,  -1},        
  {BRA_PROF_KEY_USE_CAHCE,  0,  -1, -1},     
  {BRA_PROF_KEY_USE_CSS,    0,  1,  -1},      
  {BRA_PROF_KEY_UA_PROF,    1,  -1,  -1},
  {BRA_PROF_KEY_INLINE_DO,  0,  1,  -1}

#ifdef BRA_CONFIG_UIS_PUSH_SL
 ,{BRA_PROF_KEY_LOAD_SL,    0,  -1, -1}
#endif

#ifdef BRA_CONFIG_PUSH
 ,{BRA_PROF_KEY_PUSH_SECURITY,  0,  5, -1},
  {BRA_PROF_KEY_PUSH_C_TYPE,    0,  6, -1},
  {BRA_PROF_KEY_SMS_NWA,        0,  4, -1}
, {BRA_PROF_KEY_UDP_NWA,        0,  4, -1}
#endif

, {BRA_PROF_KEY_HOMEPAGE_TITLE, 1,  -1, BRA_PROF_SAVE_HOMEPAGE_TITLE},
  {BRA_PROF_KEY_HOMEPAGE_URL,   1,  0,  BRA_PROF_SAVE_HOMEPAGE_URL},
  {BRA_PROF_KEY_CACHE_MODE,   0,  3,  -1}

#ifdef BRA_CFG_PROF_FALLBACK
, {BRA_PROF_KEY_NET_ID_DUAL,  0,  0,  BRA_PROF_SAVE_NET_ID_DUAL}
, {BRA_PROF_KEY_NET_ID_GPRS,  0,  0,  BRA_PROF_SAVE_NET_ID_GPRS}
, {BRA_PROF_KEY_NET_ID_GSM,   0,  0,  BRA_PROF_SAVE_NET_ID_GSM}
, {BRA_PROF_KEY_URL_FALLBACK,   1,  0,  -1}
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
, {BRA_PROF_KEY_NET_ID_IS_ASK,   0,  -1,  BRA_PROF_SAVE_NET_ID_IS_ASK}
, {BRA_PROF_KEY_NET_ID_ASKED,    0,  -1,  BRA_PROF_SAVE_NET_ID_ASKED}
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
};                          

#ifdef BRA_CONFIG_MMS

#include "mms_def.h"

static const char* const bra_prof_mms_key_path_table[] = 
{
  MMS_REG_PATH_COM_MMSC,
  MMS_REG_PATH_COM_STK,
  MMS_REG_PATH_COM_GW
};

static const bra_prof_key_t bra_prof_mms_key_table[BRA_PROF_N_PROFILE_KEYS] = 
{
  {NULL,   1,  -1,                         BRA_PROF_SAVE_PROF_STR},
  {MMS_REG_KEY_NETWORK_ACCOUNT,     0,  1, BRA_PROF_SAVE_NET_ID},     
  {NULL,   0,  -1, -1},       
  {NULL,   0,  -1, -1},        
  {MMS_REG_KEY_STK_CONNECTION_TYPE, 0,  1, BRA_PROF_SAVE_CON_TYPE},       
  {NULL,   0,  -1, -1},       
  {NULL,   0,  -1, -1},       
  {MMS_REG_KEY_GW_ADDRESS,     1,  2, BRA_PROF_SAVE_PRX_ADDR},       
  {MMS_REG_KEY_GW_PASSWORD,    1,  2, BRA_PROF_SAVE_PRX_PWD},   
  {MMS_REG_KEY_GW_HTTP_PORT,   0,  2, BRA_PROF_SAVE_PRX_PORT},       
  {MMS_REG_KEY_GW_REALM,       1,  2, -1},       
  {MMS_REG_KEY_GW_SECURE_PORT, 0,  2, -1},
  {MMS_REG_KEY_GW_USERNAME,    1,  2, BRA_PROF_SAVE_PRX_UID},   
  {NULL,    0,  -1, -1},        
  {NULL,    0,  -1, -1},     
  {NULL,    0,  -1, -1},      
  {NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1}

#ifdef BRA_CONFIG_UIS_PUSH_SL
 ,{NULL,    0,  -1, -1}
#endif

#ifdef BRA_CONFIG_PUSH
 ,{NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1}       
, {NULL,    0,  -1, -1}
#endif

, {NULL,    1,  -1,               BRA_PROF_SAVE_HOMEPAGE_TITLE},
  {MMS_REG_KEY_PROXY_RELAY, 1, 0, BRA_PROF_SAVE_HOMEPAGE_URL},
  {NULL,    0,  -1, -1}

#ifdef BRA_CFG_PROF_FALLBACK
, {BRA_PROF_KEY_NET_ID_DUAL,  0,  0,  BRA_PROF_SAVE_NET_ID_DUAL}
, {BRA_PROF_KEY_NET_ID_GPRS,  0,  0,  BRA_PROF_SAVE_NET_ID_GPRS}
, {BRA_PROF_KEY_NET_ID_GSM,   0,  0,  BRA_PROF_SAVE_NET_ID_GSM}
, {BRA_PROF_KEY_URL_FALLBACK,   1,  0,  -1}
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
, {BRA_PROF_KEY_NET_ID_IS_ASK,   0,  -1,  BRA_PROF_SAVE_NET_ID_IS_ASK}
, {BRA_PROF_KEY_NET_ID_ASKED,    0,  -1,  BRA_PROF_SAVE_NET_ID_ASKED}
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
};                          


#ifdef BRA_CFG_DUAL_SIM_FOR_MMS

static const bra_prof_key_t bra_prof_mms_slave_key_table[BRA_PROF_N_PROFILE_KEYS] = 
{
  {NULL,   1,  -1,                                   BRA_PROF_SAVE_PROF_STR},
  {MMS_REG_KEY_SLAVE_SIM_NETWORK_ACCOUNT,     0,  1, BRA_PROF_SAVE_NET_ID},     
  {NULL,   0,  -1, -1},       
  {NULL,   0,  -1, -1},        
  {MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, 0,  1, BRA_PROF_SAVE_CON_TYPE},       
  {NULL,   0,  -1, -1},       
  {NULL,   0,  -1, -1},       
  {MMS_REG_KEY_SLAVE_SIM_GW_ADDRESS,     1,  2, BRA_PROF_SAVE_PRX_ADDR},       
  {MMS_REG_KEY_SLAVE_SIM_GW_PASSWORD,    1,  2, BRA_PROF_SAVE_PRX_PWD},   
  {MMS_REG_KEY_SLAVE_SIM_GW_HTTP_PORT,   0,  2, BRA_PROF_SAVE_PRX_PORT},       
  {MMS_REG_KEY_SLAVE_SIM_GW_REALM,       1,  2, -1},       
  {MMS_REG_KEY_SLAVE_SIM_GW_SECURE_PORT, 0,  2, -1},
  {MMS_REG_KEY_SLAVE_SIM_GW_USERNAME,    1,  2, BRA_PROF_SAVE_PRX_UID},   
  {NULL,    0,  -1, -1},        
  {NULL,    0,  -1, -1},     
  {NULL,    0,  -1, -1},      
  {NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1}
    
#ifdef BRA_CONFIG_UIS_PUSH_SL
 ,{NULL,    0,  -1, -1}
#endif
    
#ifdef BRA_CONFIG_PUSH
 ,{NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1},
  {NULL,    0,  -1, -1}       
 ,{NULL,    0,  -1, -1}
#endif
    
 ,{NULL,    1,  -1,                         BRA_PROF_SAVE_HOMEPAGE_TITLE},
  {MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY, 1, 0, BRA_PROF_SAVE_HOMEPAGE_URL},
  {NULL,    0,  -1, -1}
    
#ifdef BRA_CFG_PROF_FALLBACK
 ,{BRA_PROF_KEY_NET_ID_DUAL,  0,  0,  BRA_PROF_SAVE_NET_ID_DUAL}
 ,{BRA_PROF_KEY_NET_ID_GPRS,  0,  0,  BRA_PROF_SAVE_NET_ID_GPRS}
 ,{BRA_PROF_KEY_NET_ID_GSM,   0,  0,  BRA_PROF_SAVE_NET_ID_GSM}
 ,{BRA_PROF_KEY_URL_FALLBACK, 1,  0,  -1}
#endif
    
#ifdef BRA_CFG_CONN_ALWAYS_ASK
 ,{BRA_PROF_KEY_NET_ID_IS_ASK,   0,  -1,  BRA_PROF_SAVE_NET_ID_IS_ASK}
 ,{BRA_PROF_KEY_NET_ID_ASKED,    0,  -1,  BRA_PROF_SAVE_NET_ID_ASKED}
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
};                          

#endif /* BRA_CFG_DUAL_SIM_FOR_MMS */


#endif /* BRA_CONFIG_MMS */




/* UA Names */
#define BRS_CFG_USER_AGENT_NOKIA_N72 \
    "NokiaN72/2.0617.1.0.3 Series60/2.8 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_NOKIA_E70 \
    "NokiaE70-1/3.0 (1.0610.05.06) SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_NOKIA_N93 \
    "NokiaN93-1/20.0.041 SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_NOKIA_6680 \
    "Nokia6680/1.0 (4.04.07) SymbianOS/8.0 Series60/2.6 Profile/MIDP-2.0Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_NOKIA_6280 \
    "Nokia6280/2.0 (03.60) Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_NOKIA_3230 \
    "Nokia3230/2.0 (5.0614.0) SymbianOS/7.0s Series60/2.1 Profile/MIDP-2.0Configuration/CLDC-1.0"
#define BRS_CFG_USER_AGENT_NOKIA_6230 \
    "Nokia6230/2.0 (03.15) Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_SE_W900I \
    "SonyEricssonW900i/R1L Browser/NetFront/3.3 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_SE_W800I \
    "SonyEricssonW800i/R1L Browser/SEMC-Browser/4.2 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_SE_K700I \
    "SonyEricssonK700i/R2AG SEMC-Browser/4.0.3 Profile/MIDP-1.0 MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_SE_Z800 \
    "SonyEricssonZ800/R1X Browser/SEMC-Browser/4.1 Profile/MIDP-2.0 Configuration/CLDC-1.1"
#define BRS_CFG_USER_AGENT_SAMSUNG_D608 \
    "SAMSUNG-SGH-D608/1.0/WAP2.0 Profile/MIDP-2.0 Configuration/CL"
#define BRS_CFG_USER_AGENT_MOTO_E1070 \
    "MOT-E1070/85.83.50R MIB/BER2.2 Profile/MIDP-2.0 Configuration/CLDC-1.1"

/* UA Profile URLs */
#define BRS_CFG_USER_AGENT_NOKIA_N72_URL \
    "http://nds.nokia.com/uaprof/NN72r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_E70_URL \
    "http://nds.nokia.com/uaprof/NE70-1r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_N93_URL \
    "http://nds.nokia.com/uaprof/NN93r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_6680_URL \
    "http://nds.nokia.com/uaprof/N6680r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_6280_URL \
    "http://nds.nokia.com/uaprof/N6280r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_3230_URL \
    "http://nds.nokia.com/uaprof/N3230r100.xml"
#define BRS_CFG_USER_AGENT_NOKIA_6230_URL \
    "http://nds.nokia.com/uaprof/N6230r100.xml"
#define BRS_CFG_USER_AGENT_SE_W900I_URL \
    "http://wap.sonyericsson.com/UAprof/W900iR101-3G.xml"
#define BRS_CFG_USER_AGENT_SE_W800I_URL \
    "http://wap.sonyericsson.com/UAprof/W800iR101.xml"
#define BRS_CFG_USER_AGENT_SE_K700I_URL \
    "http://wap.sonyericsson.com/UAprof/K700iR201.xml"
#define BRS_CFG_USER_AGENT_SE_Z800_URL \
    "http://wap.sonyericsson.com/UAprof/Z800R101.xml"
#define BRS_CFG_USER_AGENT_SAMSUNG_D608_URL \
    "http://wap.samsungmobile.com/uaprof/SGH-D608.xml"
#define BRS_CFG_USER_AGENT_MOTO_E1070_URL \
    "http://motorola.handango.com/phoneconfig/E1070/Profile/E1070.rdf"

#define BRA_PROF_UA_TABLE_NAME_INDEX    0
#define BRA_PROF_UA_TABLE_URL_INDEX    1

const char *bra_prof_user_agent[EM_WAP_USERAGENT_MAX][2] = 
{
  {"", ""}, /* replace BRA_CFG_PROF_DEFAULT_UA_HEADER with wap_custom_get_ua_header() */
              /* replace BRA_CFG_PROF_DEFAULT_UA_PROF with wap_custom_get_ua_prof_url */
  {BRS_CFG_USER_AGENT_NOKIA_N72, BRS_CFG_USER_AGENT_NOKIA_N72_URL},
  {BRS_CFG_USER_AGENT_NOKIA_E70, BRS_CFG_USER_AGENT_NOKIA_E70_URL},
  {BRS_CFG_USER_AGENT_NOKIA_N93, BRS_CFG_USER_AGENT_NOKIA_N93_URL},
  {BRS_CFG_USER_AGENT_NOKIA_6680, BRS_CFG_USER_AGENT_NOKIA_6680_URL},
  {BRS_CFG_USER_AGENT_NOKIA_6280, BRS_CFG_USER_AGENT_NOKIA_6280_URL},
  {BRS_CFG_USER_AGENT_NOKIA_3230, BRS_CFG_USER_AGENT_NOKIA_3230_URL},
  {BRS_CFG_USER_AGENT_NOKIA_6230, BRS_CFG_USER_AGENT_NOKIA_6230_URL},
  {BRS_CFG_USER_AGENT_SE_W900I, BRS_CFG_USER_AGENT_SE_W900I_URL},
  {BRS_CFG_USER_AGENT_SE_W800I, BRS_CFG_USER_AGENT_SE_W800I_URL},
  {BRS_CFG_USER_AGENT_SE_K700I, BRS_CFG_USER_AGENT_SE_K700I_URL},
  {BRS_CFG_USER_AGENT_SE_Z800, BRS_CFG_USER_AGENT_SE_Z800_URL},
  {BRS_CFG_USER_AGENT_SAMSUNG_D608, BRS_CFG_USER_AGENT_SAMSUNG_D608_URL},
  {BRS_CFG_USER_AGENT_MOTO_E1070, BRS_CFG_USER_AGENT_MOTO_E1070_URL}
};

#ifdef GDI_USING_PNG

#define BRS_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "image/png, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#else

#define BRS_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#endif


#ifdef  __J2ME__

#define BRS_CFG_ACCEPT_HEADER_COMMON \
  "text/vnd.sun.j2me.app-descriptor, "\
  "application/java-archive, "\
  BRS_CFG_ACCEPT_HEADER_COMMON_1

#else

#define BRS_CFG_ACCEPT_HEADER_COMMON BRS_CFG_ACCEPT_HEADER_COMMON_1

#endif


#define BRS_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  "application/vnd.wap.wmlc, " \
  "application/vnd.wap.wmlscriptc, " \
  "text/vnd.wap.wml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_WAP_2_0 \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  BRS_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  ", text/html"
#define BRS_CFG_ACCEPT_HEADER_WML \
  "text/vnd.wap.wml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_XHTML \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_HTML \
  "text/html, " \
  BRS_CFG_ACCEPT_HEADER_COMMON

const char *bra_prof_accept_header[EM_WAP_ACCEPTHEADER_MAX] = 
{
  BRS_CFG_ACCEPT_HEADER_WAP_1_2_1,
  BRS_CFG_ACCEPT_HEADER_WAP_2_0,
  BRS_CFG_ACCEPT_HEADER_WML,
  BRS_CFG_ACCEPT_HEADER_XHTML,
  BRS_CFG_ACCEPT_HEADER_HTML
};

#ifdef GDI_USING_PNG

#define BRS_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, image/png, audio/amr, audio/imelody, audio/midi, audio/wav, */*"
  
#else

#define BRS_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, audio/amr, audio/imelody, audio/midi, audio/wav, */*"

#endif

/* 
 *  Defines the image types that can be directly shown in the browser.
 *  This feature can be disabled if BRS_CFG_SUPPORTED_IMAGE_MIME is defined 
 *  as the following:
 *
 *  #define BRA_CFG_SUPPORTED_IMAGE_MIME ""
 */
#ifdef GDI_USING_PNG
#define BRA_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/png," \
  "image/jpeg"
#else
#define BRA_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/jpeg"
#endif

/* 
 *  Defines the set of natural languages that are preferred by the browser.
 *  This information will be sent in HTTP ACCEPT-LANGUAGE header which is useful 
 *  to multilingual sites for deciding the best language to serve to the client.
 *
 *  If no Accept-Language header is present in the request, the server
 *  may assume that all languages are equally acceptable, e.g. 
 *
 *  #define BRA_CFG_ACCEPT_LANGUAGE_HEADER	NULL
 * 
 *  Reference: Section 14.4 Accept-Language in RFC2616
 */
#define BRA_CFG_ACCEPT_LANGUAGE_HEADER \
  "zh-tw," \
  "zh-cn," \
  "en"
 

/* 
 *  Default "Accept-Charset:" header, sent by browser when retrieving a document.
 *
 *  If no Accept-Charset header is present in the request, the server
 *  may assume that all languages are equally acceptable, e.g. 
 *
 *  The default charsets: UTF-8, UTF-16, ISO-8859-1, UCS2, ASCII
 *  Customer can add additional in BRA_CFG_ACCEPT_CHARSET.
 * 
 *  Reference: Section 14.2 Accept-Charset in RFC2616
 */
const char *BRA_CFG_ACCEPT_CHARSET = 
/******** Begin of BRA_CFG_ACCEPT_CHARSET ********/
  "utf-8,"
  "utf-16," 
  "iso-8859-1," 
  "iso-10646-ucs-2," 
#ifdef __MMI_CHSET_GB18030__
  "gb18030,"
#endif
#ifdef __MMI_CHSET_GB2312__ 
  "gb2312,"
#endif 
#ifdef __MMI_CHSET_BIG5__ 
  "Big5," 
#endif 
#ifdef __MMI_CHSET_CEURO_ISO__ 
  "iso-8859-2," 
#endif 
#ifdef __MMI_CHSET_SEURO_ISO__ 
  "iso-8859-3," 
#endif 
#ifdef __MMI_CHSET_BALTIC_ISO__ 
  "iso-8859-4," 
#endif 
#ifdef __MMI_CHSET_ARABIC_ISO__ 
  "iso-8859-6," 
#endif 
#ifdef __MMI_CHSET_GREEK_ISO__ 
  "iso-8859-7," 
#endif 
#ifdef __MMI_CHSET_HEBREW_ISO__ 
  "iso-8859-8," 
#endif 
#ifdef __MMI_CHSET_TURKISH_ISO__ 
  "iso-8859-9," 
#endif 
#ifdef __MMI_CHSET_NORDIC_ISO__ 
  "iso-8859-10," 
#endif 
#ifdef __MMI_CHSET_EUCKR_WIN__ 
  "EUC-KR," 
#endif 
#ifdef __MMI_CHSET_LATIN_ISO__ 
  "iso-8859-15," 
#endif 
#ifdef __MMI_CHSET_WESTERN_WIN__ 
  "windows-1252," 
#endif 
#ifdef __MMI_CHSET_GREEK_WIN__ 
  "windows-1253," 
#endif 
#ifdef __MMI_CHSET_TURKISH_WIN__ 
  "windows-1254," 
#endif 
#ifdef __MMI_CHSET_HEBREW_WIN__ 
  "windows-1255," 
#endif 
#ifdef __MMI_CHSET_ARABIC_WIN__ 
  "windows-1256," 
#endif 
#ifdef __MMI_CHSET_THAI_WINDOWS__ 
  "windows-874," 
#endif 
  /* Customer may add additional charset after this line */

  /* Customer may add additional charset before this line */
  "us-ascii";
/******** End of BRA_CFG_ACCEPT_CHARSET ********/


/*
 * Define the default CSS style sheet used in BRS.
 * 
 * Note: the syntax of the defined CSS style sheet MUST conform to W3C CSS.
 * 
 * This default CSS style sheet defines the behaviour of BRS layout engine for all mark-up content. 
 * The customer may change some of these CSS rules, such as the background color or font settings, 
 * when configuring the layout of a small screen device. 
 * 
 * Please also note that the CSS rules configured with '!important' in this default style sheet 
 * will override the CSS rules specified in the web pages, in case of conflict.
 * 
 */
#define BRA_CFG_BRS_CSS_DEFAULT_STYLE_SHEET \
  "BODY { width: auto !important; height: auto !important; margin-right: 0 !important} \n" \
  "OL UL, UL OL, UL UL, OL OL  { margin-top: 0; margin-bottom: 0 } \n" \
  "A:link, anchor:link { color: blue } \n" \
  "A:visited, anchor:visited { color: red } \n" \
  "A:focus, anchor:focus, A > *:focus { color: black !important; background-color: #9E7BFF !important } \n" \
  "area {color:blue} \n" \
  "area:focus {color:red} \n" \
  "do:focus, textarea:focus, input:focus, " \
  "object:focus, select:focus{border-color: black !important; border-style: dotted !important; border-width: 1px !important; padding: 0px !important} \n" \
  "img:focus {color: red !important; border-color: red !important; border-style: dotted !important; border-width: 1px !important;padding: 0px !important} \n" \
  "A > IMG { padding: 1px !important; border-width: 0px } \n" \
  "A:active, anchor:active, do:active, textarea:active, " \
  "img:active, object:active, input:active { color: red } \n" \
  "do, textarea, input, object, select {padding: 1px} \n" \
  "img { padding: 0px; border-width: 0px } \n" \
  "caption, th {text-align: center} \n" \
  "optgroup, address, q, dfn, i, cite, em, var {font-style: italic} \n" \
  "option {font-style: normal} \n" \
  "h1 {font-size: xx-large; font-style: normal; font-weight: 700} \n" \
  "h2 {font-size: x-large; font-style: normal; font-weight: 700} \n" \
  "h3 {font-size: large; font-style: italic; font-weight: 700} \n" \
  "h4 {font-size: large; font-style: italic; font-weight: 700} \n" \
  "h5 {font-size: large; font-style: normal; font-weight: 700} \n" \
  "h6 {font-size: medium; font-style: italic; font-weight: 700} \n" \
  "plaintext, pre {white-space: pre; font-family: monospace} \n" \
  "code, kbd, samp, tt {font-family: monospace} \n" \
  "big {font-size: large} \n" \
  "small {font-size: small} \n" \
  "b, strong {font-weight: 700} \n" \
  "th {font-weight: 700} \n" \
  "ol {list-style-type: decimal} \n" \
  "menu, dir, ul {list-style-type: disc} \n" \
  "u, a[href], anchor[href] {text-decoration: underline} \n" \
  "blink {text-decoration: blink} " \
  "input { font-family: sans-serif }" \
  "table { border-spacing: 2px; text-align: left; empty-cells: show }" \
  "tr {vertical-align: middle } " \
  "td, th { vertical-align: inherit; background-image: inherit; " \
  "         background-color: inherit }" \
  "center > * { margin-left: auto; margin-right: auto } " \
  "center { text-align: center }" \
  "td[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] { text-align: center }"\
  "div {height:auto !important} " \
  "pre {height:auto !important} " \
  "a * {background-color: inherit}"\
  "a img {vertical-align: top !important}" \
  /* "input, textarea {border-style: solid; border-width: 1px; border-color: black}" */ \
  "input[type='checkbox'], input[type='radio'], input[type='submit'], input[type='reset'], " \
  "input[type='image'], input[type='button'] {border-style: none; border-width: 0px}" \
  "input[type='checkbox']:focus, input[type='radio']:focus, input[type='submit']:focus, "\
  "input[type='reset']:focus, input[type='image']:focus, "\
  "input[type='button']:focus {border-style: dotted; border-width: 1px;padding: 0px}"


/* The WML standard says that the history stack must be cleared
 * when entering a card that has the "newcontext" attribute set,
 * or if a script calls the function Browser.newContext. Also,
 * calling the function BRSif_loadUrl sets the "newcontext" attribute
 * by default.
 * However, frequent emptying of the history stack usually implies
 * that the history becomes very shallow, and limits the usefulness
 * of the BACK and FWD buttons.
 * By default, BRS will let the history remain intact on "newcontext".
 * The following configurations are available:
 *   0: Never clear history on newcontext. (default)
 *   1: Always clear history on newcontext.
 *   2: Never clear history on newcontext, and don't set "newcontext" in BRSif_loadUrl. 
 *		(recommended, but violates WML spec)
 *   3: Always clear history on newcontext, but don't set "newcontext" in BRSif_loadUrl.
 *		(conforms to WML spec)
 */
#define BRA_CFG_BRS_CLEAR_HISTORY_ON_NEWCONTEXT	3


/*
 * How to handle redirections:
 *   1      Normal:   always automatic redirection, and POST is changed into GET
 *                      (this is what most browsers do)
 *   2      Cautious: responses with status codes 301 and 307 are always
 *                      shown to the user
 *   3      Special:  for responses with status codes 301, 302, 307:
 *                      if GET, do automatic redirection,
 *                      if POST, ask for user confirmation
 */
#define BRA_CFG_BRS_REDIRECT_HANDLING 3 


#ifdef MTK_TMP_PATCH /* CR34945 */
/** 
 * If BRA_CFG_BRS_IGNORE_EMPTYOK == 1, Browser will disable the checking of 
 *    (1) the attribute "emptyok" in web pages and
 *    (2) the property "-wap-input-required" in CSS,
 * so that Browser will not prompt any error dialog if the user input does not conform to the attribute "emptyok" or 
 * the property "-wap-input-required".   
 *
 * Default: BRA_CFG_BRS_IGNORE_EMPTYOK == 0
 */
#define BRA_CFG_BRS_IGNORE_EMPTYOK 0
#endif /* MTK_TMP_PATCH */

/* defines a table of file extensions and their corresponding mime-types
 * the mime-types defined here are used when a page is loaded via file:// scheme
 * by default, all file extensions will be mapped to text/plain
 * table must be terminated by {0, 0} entry
 */
#ifdef BRA_CFG_ENABLE_FILE_SCHEME
const char *bra_prof_mimeext[][2] = 
{
  {"htm", "text/html"},
  {"html", "text/html"},
  {0, 0}
};
#endif  /* BRA_CFG_ENABLE_FILE_SCHEME */

/**********************************************************************
 * Global variables
 **********************************************************************/
static bra_profiles_t      bra_prof_profile;
static int                 act_prof_id = -1;
#ifdef BRA_CFG_DUAL_SIM
static int                 act_sim_id = -1;   /* current SIM id in active use, for BRA, it's the using one, and for MMS, it's current edit one */
#endif


/**********************************************************************
 * Function prototypes
 **********************************************************************/

static int 
bra_prof_add_key (bra_prof_profile_t *profile, char *key, char *value);

static int 
bra_prof_add_int_key (bra_prof_profile_t *profile, char *key, int value);

static int 
bra_prof_add_str_key (bra_prof_profile_t *profile, char *key, char *value);


static void
bra_prof_load_cmn (void);

#ifdef BRA_CONFIG_MMS
static MSF_BOOL
bra_prof_commit_mmsc(int sim_id, char *str);
#endif

static void
em_wap_change_value (char *key, int val);

static void 
bra_prof_commit_default_channel(void *reg_handle, int i, bra_prof_profile_t *profile);



/*------------------------------------------------------------------*/
static void
bra_prof_continue_initialize(void);

static void
bra_prof_commit_sim_activated_profile(int id, int sim_id);

static void
bra_prof_init_bra_prof_profile(void);

static void
bra_prof_init_profile_cmn_part(bra_profiles_t *profile);

static bra_prof_available_profiles_t* 
bra_prof_alloc_available_profile(void);

static void
bra_prof_free_available_profiles(bra_prof_available_profiles_t *available_profiles);


static void
bra_prof_initialize_cmn_keys(void);


static void
bra_prof_init_cmn_response (int idx, int eof, void* block, int size);

static int
bra_prof_filter_int_key_to_generate_ext_net_id(int id, char *key, int value);

static int
bra_prof_filter_int_key_to_get_raw_net_id(int id, char *key, int value);

static int
bra_prof_loaded_profile_is_bra_profile_in_active_use(void);

#ifdef BRA_CONFIG_MMS
static int
bra_prof_loaded_profile_is_mms_profile_in_active_use(void);
#endif /* BRA_CONFIG_MMS */
/*------------------------------------------------------------------*/


extern void 
meaProfNetworkCallback(char *path, char *key, int type, int ival, char *sval);
/************************************************************
 *  Internal Functions
 ************************************************************/
static int
bra_prof_key_to_int (char *key)
{
  int   i;
  char *s;
  const char *t;

  for (i = 0; i < BRA_PROF_N_PROFILE_KEYS; i++)
  {
    s = key;
    t = bra_prof_key_table[i].key;
    while (*s == *t)
    {
      if ((*s =='\0') && (*t =='\0') )
        return i;
      s++;
      t++;
    }
  }
  return -1;
}

static int
bra_prof_cmn_key_to_int (char *key)
{
  int   i;
  char *s;
  const char *t;

  for (i = 0; i < BRA_PROF_N_CMN_KEYS; i++)
  {
    s = key;
    t = bra_prof_cmn_key_table[i].key;
    while (*s == *t)
    {
      if ((*s =='\0') && (*t =='\0') )
        return i;
      s++;
      t++;
    }
  }
  return -1;
}

static bra_prof_profile_t*
bra_prof_get_profile_by_id (int id)
{
  return bra_prof_profile.profile;
}

int
bra_prof_get_sim_absolute_profile(void)
{
  return bra_prof_profile.profile_id;
}

int
bra_prof_get_absolute_profile (void)
{
#ifdef BRA_CFG_DUAL_SIM
  if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
  {
    ASSERT(bra_prof_profile.profile_id >= BRA_CFG_N_PROFILES && 
        bra_prof_profile.profile_id < BRA_CFG_N_PROFILES * BRA_CFG_MAX_SIM_NUM);
    return bra_prof_profile.profile_id - BRA_CFG_N_PROFILES;
  }
#endif /* BRA_CFG_DUAL_SIM */

  return bra_prof_profile.profile_id;
}

int
bra_prof_get_relative_profile (void)
{
#ifdef BRA_CFG_DUAL_SIM
  if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
  {
    ASSERT(bra_prof_profile.profile_id >= BRA_CFG_N_PROFILES);
    if(bra_prof_profile.id == BRA_PROF_ID_BRA)
      return bra_prof_profile.profile_id - BRA_CFG_N_PROFILES;
    else
     return bra_prof_profile.profile_id - BRA_CFG_N_PROFILES - BRA_CFG_N_WAP_PROFILES;
  }
#endif /* BRA_CFG_DUAL_SIM */

  if(bra_prof_profile.id == BRA_PROF_ID_BRA)
    return bra_prof_profile.profile_id;
  else
    return bra_prof_profile.profile_id - BRA_CFG_N_WAP_PROFILES;
}


void 
bra_prof_restore_act_profile (void)
{
#ifdef BRA_CFG_DUAL_SIM
  
  if (act_sim_id == bra_prof_profile.sim_id && act_prof_id == bra_prof_get_absolute_profile())
    return;
  
  if (bra_prof_profile.id == BRA_PROF_ID_BRA)
  {
    if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
      bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID_SLAVE, bra_prof_get_absolute_profile(), NULL);
    else
      bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID, bra_prof_get_absolute_profile(), NULL);
  }
  
#ifdef BRA_CONFIG_MMS
  
  if (bra_prof_profile.id == BRA_PROF_ID_MMS)
  {
    if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
      bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID_SLAVE, bra_prof_get_absolute_profile(), NULL);
    else
      bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID, bra_prof_get_absolute_profile(), NULL);
  }
  
#endif /* BRA_CONFIG_MMS */
  
  /* if current activated profile belong to the activated SIM, should commit this profile to registry */
  if (act_sim_id == bra_prof_profile.sim_id && act_prof_id != bra_prof_get_absolute_profile())
  {
    act_prof_id = bra_prof_get_absolute_profile();
    bra_prof_commit_profile();
  }
  
#else /* BRA_CFG_DUAL_SIM */
  
  
  if (act_prof_id == bra_prof_profile.profile_id)
    return;
  act_prof_id = bra_prof_profile.profile_id; 
  
  if(bra_prof_profile.id == BRA_PROF_ID_BRA)
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID, bra_prof_get_absolute_profile(), NULL);
#ifdef BRA_CONFIG_MMS
  else if(bra_prof_profile.id == BRA_PROF_ID_MMS)
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID, bra_prof_get_absolute_profile(), NULL);
#endif
  
  bra_prof_commit_profile();
  
#endif /* BRA_CFG_DUAL_SIM */
}


void
bra_prof_activate_sim_profile(int id, int sim_id, int prof_id)
{
    int is_ask = 0;
    int cur_sim_id = sim_id;
    int cur_prof_id;


#ifdef BRA_CFG_DUAL_SIM
    if (id == BRA_PROF_ID_BRA)
    {
        is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);
        cur_sim_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
    }
#endif /* BRA_CFG_DUAL_SIM */

    cur_prof_id = bra_prof_get_sim_activated_profile_id(id, cur_sim_id);
    if (is_ask == 0 && sim_id == cur_sim_id && prof_id == cur_prof_id)
        return;

#ifdef BRA_CFG_DUAL_SIM
   if (is_ask)
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK, 0, NULL);
    
    if (sim_id != cur_sim_id)
    {
        if (id == BRA_PROF_ID_BRA)
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID, sim_id, NULL);
    }
#endif /* BRA_CFG_DUAL_SIM */

    cur_prof_id = bra_prof_get_sim_activated_profile_id(id, sim_id);
    if (prof_id != cur_prof_id)
    {
#ifdef BRA_CFG_DUAL_SIM
       if (sim_id == BRA_SIM_ID_SIM2)
        {
            if (id == BRA_PROF_ID_BRA)
                bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID_SLAVE, prof_id, NULL);
            else
                bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID_SLAVE, prof_id, NULL);
        }
        else
#endif /* BRA_CFG_DUAL_SIM */

        {
            if (id == BRA_PROF_ID_BRA)
                bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID, prof_id, NULL);
            else
                bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID, prof_id, NULL);
        }
    }
    bra_prof_commit_profile();
}


static void
bra_prof_initialize_profile (bra_prof_profile_t *profile)
{
  /*Initialize profile with default*/

  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID,   BRA_CFG_PROF_DEFAULT_NET_ID);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_HISTSIZE, BRA_CFG_PROF_DEFAULT_HISTSIZE);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_REFRESH,  BRA_CFG_PROF_DEFAULT_REFRESH);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_USE_CSS,  BRA_CFG_PROF_DEFAULT_USE_CSS);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_CON_TYPE, BRA_CFG_PROF_DEFAULT_CON_TYPE);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_CASHSIZE, BRA_CFG_PROF_DEFAULT_CACHESIZE);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_USE_CAHCE,BRA_CFG_PROF_DEFAULT_USE_CACHE);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_CACHE_MODE, 0);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_COOKIES,  BRA_CFG_PROF_DEFAULT_COOKIES);
  /*NOTE! For now use Stack default port# (attained by setting port# to zero)*/
  bra_prof_add_int_key (profile, BRA_PROF_KEY_PRX_PORT, BRA_CFG_PROF_DEFAULT_PRX_PORT);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_PRX_SECP, 0);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_INLINE_DO, BRA_CFG_PROF_DEFAULT_INLINE_DO);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_LDNOMIME,  BRA_CFG_PROF_DEFAULT_LDNOMIME);
#ifdef BRA_CONFIG_UIS_PUSH_SL
  bra_prof_add_int_key (profile, BRA_PROF_KEY_LOAD_SL ,  BRA_CFG_PROF_DEFAULT_LOAD_SL);  
#endif
#ifdef BRA_CONFIG_PUSH
  bra_prof_add_int_key (profile, BRA_PROF_KEY_PUSH_SECURITY, BRA_CFG_PROF_DEFAULT_PUSH_SECURITY);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_PUSH_C_TYPE,   BRA_CFG_PROF_DEFAULT_PUSH_C_TYPE);    
  //bra_prof_add_int_key (profile, BRA_PROF_KEY_PUSH_NET_ID,   BRA_CFG_PROF_DEFAULT_PUSH_NET_ID);   
#endif
  bra_prof_add_str_key (profile, BRA_PROF_KEY_PRX_ADDR, BRA_CFG_PROF_DEFAULT_PRX_ADDR);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_PRX_UID,  BRA_CFG_PROF_DEFAULT_PRX_UID);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_PRX_PWD,  BRA_CFG_PROF_DEFAULT_PRX_PWD);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_PRX_RLM,  BRA_CFG_PROF_DEFAULT_PRX_RLM);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_UA_PROF,  BRA_CFG_PROF_DEFAULT_UA_PROF);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_HOMEPAGE_URL, BRA_CFG_DEFAULT_HOMPAGE_URL);
#ifdef BRA_CFG_PROF_FALLBACK
  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID_DUAL,  BRA_CFG_PROF_DEFAULT_NET_ID_DUAL);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID_GPRS,  BRA_CFG_PROF_DEFAULT_NET_ID_GPRS);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID_GSM,   BRA_CFG_PROF_DEFAULT_NET_ID_GSM);
  bra_prof_add_str_key (profile, BRA_PROF_KEY_URL_FALLBACK,   NULL);
#endif
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID_IS_ASK, 0);
  bra_prof_add_int_key (profile, BRA_PROF_KEY_NET_ID_ASKED, BRA_CFG_PROF_DEFAULT_NET_ID);
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

}


void  
bra_prof_commit_profile (void)
{
  int                   i;
  int                   path;  
  int                   i_value = 0;
  bra_prof_profile_t    *profile;
  void                  *reg_handle;


  profile = bra_prof_profile.profile;

  if(bra_prof_profile.id == BRA_PROF_ID_BRA)
  {
    char *title = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE);
    char *url = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL);
    if(title)
      bra_cmn_set_local_hompage_title(BRA_STRCONV(title));
    if(url)
      bra_cmn_set_local_hompage_url(url);

    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);

    for (i = 0; i < profile->n_items; i++)
    {
      path = bra_prof_key_table[i].path;
      /*Do not save key if path = -1*/
      if (path < 0)
        continue;

      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_key_path_table[path]);
      if (bra_prof_key_table[i].type == 0)/*0 = int*/
      {
        i_value = bra_prof_filter_int_key_to_generate_ext_net_id(bra_prof_profile.id, 
            bra_prof_key_table[i].key,  profile->items[i].i_value);
        
        MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, bra_prof_key_table[i].key, i_value);

        /* change bearer type for status icon
        if(i == BRA_PROF_ENUM_NET_ID)
          BRAa_setBearerType(profile->items[i].i_value);
        */
      }
      else
      {
        MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                      bra_prof_key_table[i].key, 
                      (unsigned char*)BRA_CMN_HNV(profile->items[i].s_value) , 
                      (MSF_UINT16)(strlen (BRA_CMN_HNV (profile->items[i].s_value))+1));
      }
      /* Configure for STK default channel, which will be used in SL cache or SIA */
      bra_prof_commit_default_channel(reg_handle, i, profile);      
    }
    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
#ifdef BRA_CONFIG_MMS
  else if(bra_prof_profile.id == BRA_PROF_ID_MMS)
  {
    bra_prof_key_t   *key_table = (bra_prof_key_t*)bra_prof_mms_key_table;
     
#ifdef BRA_CFG_DUAL_SIM_FOR_MMS
    if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
      key_table = (bra_prof_key_t*)bra_prof_mms_slave_key_table;
#endif

  if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);

    for (i = 0; i < profile->n_items; i++)
    {
      path = key_table[i].path;
      /*Do not save key if path = -1*/
      if (path < 0 || i == BRA_PROF_ENUM_HOMEPAGE_URL)
        continue;

      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_mms_key_path_table[path]);
      if (key_table[i].type == 0)/*0 = int*/
      {
          i_value = bra_prof_filter_int_key_to_generate_ext_net_id(bra_prof_profile.id,
              bra_prof_key_table[i].key, profile->items[i].i_value);
          MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, key_table[i].key, i_value);
      }
      else
      {
       MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                      key_table[i].key, 
                      (unsigned char*)BRA_CMN_HNV(profile->items[i].s_value) , 
                      (MSF_UINT16)(strlen (BRA_CMN_HNV (profile->items[i].s_value))+1));
      }
    }
    MSF_REGISTRY_SET_COMMIT (reg_handle);

    /* commit proxy relay address */
    {
      int keyint = bra_prof_key_to_int(BRA_PROF_KEY_HOMEPAGE_URL);
      char *sval = bra_prof_get_key_str_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_HOMEPAGE_URL);
      if(keyint > 0 && sval && strlen(sval) > 0)
        bra_prof_commit_mmsc(bra_prof_get_profile_sim_id(), sval);
    }
  }
  else
  {
    for (i = 0; i < profile->n_items; i++)
    {
      path = key_table[i].path;
      /*Do not save key if path = -1*/
      if (path < 0)
        continue;

        if (key_table[i].type == 0)
        {
            i_value = bra_prof_filter_int_key_to_generate_ext_net_id(bra_prof_profile.id,
                bra_prof_key_table[i].key, profile->items[i].i_value);
        }
      meaProfNetworkCallback((char*)bra_prof_mms_key_path_table[path],
                             key_table[i].key,
                             key_table[i].type,
                             i_value,
                             (char*)BRA_CMN_HNV(profile->items[i].s_value));
    }
  }
  }
#endif  /* BRA_CONFIG_MMS */

}


/*
 *  This function writes the new profile name to the register.  
 *  It then destroys the old profile and load the new one.
 *
 */
void
bra_prof_set_selected_profile(int id, int prof_id, bra_prof_loaded_done_t callback)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_3150DB3B056FE79BAEA8F0E8828191DA, "BRA: bra_prof_set_selected_profile(%d,%d)\n", id, prof_id));
  bra_prof_set_sim_selected_profile(id, bra_prof_get_profile_sim_id(), prof_id, callback);
}

void 
bra_prof_set_sim_selected_profile (int id, int sim_id, int prof_id, bra_prof_loaded_done_t callback)
{
  bra_prof_profile_t *profile;


  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
      BRA_PROF_SET_SIM_SELECT_PROFILE, 
      "BRA: bra_prof_set_sim_selected_profile(): id=%d, sim_id=%d, prof_id=%d\n",
      id, sim_id, prof_id));


  ASSERT(prof_id < BRA_CFG_N_PROFILES);
#ifdef BRA_CFG_DUAL_SIM
  ASSERT(sim_id == BRA_SIM_ID_SIM1 || sim_id == BRA_SIM_ID_SIM2);
#endif
  
  if (bra_prof_is_profile_loaded (0) == 0)
    return;
  
  /*If a previous profile is loaded we need to remove it first*/
  profile = bra_prof_get_profile_by_id (0);
    
  if(profile)
  {
    /*If selected profile is same as old there is no need to do any thing here*/
    if(BRA_PROF_GET_SIM_IDX(sim_id, prof_id) == bra_prof_profile.profile_id)
    {
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_CF875B6098C11EB09A24002068862890, "BRA: id matched, do not load and return\n"));
      if (callback != NULL)
        callback ();
      return;
    }
    
    /*Remove old profile. only needed in this case were a previous profile is loaded*/
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_0DB4C30C5E1F155E7B25B598C143B43F, "BRA: unload old profile\n"));
    bra_prof_unload_profile ();
  }
  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_9668B4C19E76F2D31CDEFA51AB2FE9ED, "BRA: load profile\n"));
  bra_prof_load_sim_profile (id, sim_id, prof_id, callback);
}

/*
 * This function changes the value  of "key" to "value" in the current profile
 * It handles both strings and integer string key values, but NOTE! when using this function
 * the valu type must have been set previously (for instance in the initialization)
 *
 * Return index of key if success, else -1
 */
static int 
bra_prof_add_key (bra_prof_profile_t *profile, char *key, char *value)
{
  int i;

  i = bra_prof_key_to_int(key);

  if (i > profile->n_items)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_E4806F69FC572541FF0704E9F4FC2FB0, "BRA: Profile Error: Ilegal key (integer)'%s'\n", key));
    return -1;
  }
  if (bra_prof_key_table[i].type == 0) /*0 = int*/
  {
    profile->items[i].i_value = atoi (value);
    if(i == BRA_PROF_ENUM_CON_TYPE)
      bra_prof_profile.available_profiles[bra_prof_profile.profile_id].con_type = atoi (value);
  }
  else
  {
    BRA_FREE (profile->items[i].s_value);
    profile->items[i].s_value = msf_cmmn_strdup (MSF_MODID_BRA, value);

    if (i == BRA_PROF_ENUM_PROF_STR)
    {
      /*This is the profile name key*/
      BRA_FREE (bra_prof_profile.available_profiles[bra_prof_profile.profile_id].profile_name);
      bra_prof_profile.available_profiles[bra_prof_profile.profile_id].profile_name = msf_cmmn_strdup (MSF_MODID_BRA, value);
    }
  }
  
  return i;
}

/*
 * This function changes the value  of "key" to "value" in the current profile
 * It handles only integer key values
 *
 * Return index of key if success, else -1
 */
static int 
bra_prof_add_int_key (bra_prof_profile_t *profile, char *key, int value)
{
  int i;

  i = bra_prof_key_to_int(key);

  if (i > profile->n_items)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_E4806F69FC572541FF0704E9F4FC2FB0, "BRA: Profile Error: Ilegal key (integer)'%s'\n", key));
    return -1;
  }
  profile->items[i].i_value = value;
  if (i == BRA_PROF_ENUM_CON_TYPE)
    bra_prof_profile.available_profiles[bra_prof_profile.profile_id].con_type = profile->items[i].i_value;
  
  return i;
}

/*
 * This function changes the value  of "key" to "value" in the current profile
 * It handles both character and integer key values
 *
 * Return index of key if success, else -1
 */
static int 
bra_prof_add_str_key (bra_prof_profile_t *profile, char *key, char *value)
{
  int i;

  i = bra_prof_key_to_int(key);
  
  if (i > profile->n_items)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_0F8AFB070EB0E460D03316E70CB21867, "BRA: Profile Error: Ilegal key (String)'%s'\n", key));
    return -1;
  }
  profile->items[i].s_value = msf_cmmn_strdup (MSF_MODID_BRA, value);
  
  if (i == BRA_PROF_ENUM_PROF_STR)
  {
    /*This is the profile name key*/
    BRA_FREE (bra_prof_profile.available_profiles[bra_prof_profile.profile_id].profile_name);
    bra_prof_profile.available_profiles[bra_prof_profile.profile_id].profile_name = msf_cmmn_strdup (MSF_MODID_BRA, value);
  }

  return i;
}

/*
 * This function changes the value  of "key" to "value" in the current profile
 * It handles only integer key values
 *
 * Return index of key if success, else -1
 */
static int 
bra_prof_add_cmn_int_key (char *key, int value)
{
  int i;

  i = bra_prof_cmn_key_to_int(key);

  if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_E4806F69FC572541FF0704E9F4FC2FB0, "BRA: Profile Error: Ilegal key (integer)'%s'\n", key));
    return -1;
  }

  bra_prof_profile.cmn_items[i].i_value = value;
  
  return i;
}

/*
 * This function changes the value  of "key" to "value" in the current profile
 * It handles both character and integer key values
 *
 * Return index of key if success, else -1
 */
static int 
bra_prof_add_cmn_str_key (char *key, char *value)
{
  int i;

  i = bra_prof_cmn_key_to_int(key);
  
  if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_0F8AFB070EB0E460D03316E70CB21867, "BRA: Profile Error: Ilegal key (String)'%s'\n", key));
    return -1;
  }

  bra_prof_profile.cmn_items[i].s_value = msf_cmmn_strdup (MSF_MODID_BRA, value);
  
  return i;
}

static int
bra_prof_unpack_block (unsigned char * block, int size, bra_prof_block_t *p)
{
  if (size < BRA_PROF_BLOCK_HEADER_SIZE)
    return -1;

  p->id         =  block[0];
  p->profile_id =  block[1];
  p->key_id     =  block[2];
  p->size       = (block[3] << 8);
  p->size       += block[4];

  if ((p->size + BRA_PROF_BLOCK_HEADER_SIZE) > size)
    return -1;

  p->value         = BRA_ALLOC (p->size);
  memcpy (p->value, &block[5], p->size);

  return 1;

}

static unsigned char*
bra_prof_create_block (int id, int sim_id, int prof_id, int key_id, unsigned char* value, int *size)
{
  unsigned char* p;

  p = BRA_ALLOC (*size + BRA_PROF_BLOCK_HEADER_SIZE);
  
  p[0] = (unsigned char)id;
  p[1] = (unsigned char) BRA_PROF_GET_SIM_IDX(sim_id, prof_id); 
  p[2] = (unsigned char)key_id;
  p[3] = (unsigned char)(*size >> 8);
  p[4] = (unsigned char)(*size & 0x00FF);
  memcpy (&p[5], value, *size);

  *size += BRA_PROF_BLOCK_HEADER_SIZE;

  return p;
}

static void 
bra_prof_load_block_response (void *handle, unsigned char* block, int size)
{ 
  int id;
  int profile_id;
  int key_id;
   
  if (size < BRA_PROF_BLOCK_HEADER_SIZE)
    return;

  id = (int)block[0];
  profile_id = (int)block[1];
  key_id = (int)block[2];

  if(id == BRA_PROF_ID_CMN)
  {
    if(bra_prof_cmn_key_table[key_id].type == 0)
      bra_prof_profile.cmn_items[key_id].i_value = atoi((const char*)(&block[5]));
    else
    {
      BRA_FREE(bra_prof_profile.profile->items[key_id].s_value);
      bra_prof_profile.cmn_items[key_id].s_value = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)(&block[5]));
    }
  }
  else if (id == BRA_PROF_ID_BRA)
  {
    if (bra_prof_key_table[key_id].type == 0) /*0 = int*/
      bra_prof_profile.profile->items[key_id].i_value = atoi((const char*)(&block[5]));
    else
    {      
      BRA_FREE(bra_prof_profile.profile->items[key_id].s_value);
      bra_prof_profile.profile->items[key_id].s_value = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)(&block[5]));
    }
  }
#ifdef BRA_CONFIG_MMS
  else if (id == BRA_PROF_ID_MMS)
  {
    if (bra_prof_mms_key_table[key_id].type == 0) /*0 = int*/
      bra_prof_profile.profile->items[key_id].i_value = atoi((const char*)(&block[5]));
    else
    {
      BRA_FREE(bra_prof_profile.profile->items[key_id].s_value);
      bra_prof_profile.profile->items[key_id].s_value = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)(&block[5]));
    }
  }
#endif
   
  BRA_FREE (block);
}

static int
bra_prof_read_profile_key (int id, char *key, bra_prof_key_read_t callback)
{
  int key_id;
  int idx_id;

  if(!key)
    return -1;

  if (id == BRA_PROF_ID_CMN)
  {
    key_id = bra_prof_cmn_key_to_int (key);

    if (key_id < 0) 
      return -1;

    /*Check if value exist in profile*/
    if (bra_prof_profile.cmn_index_list[key_id] < 0)
      return -1;

    bra_file_read_block (bra_prof_profile.file_handle, 
                         bra_prof_profile.cmn_index_list[key_id], 
                         callback);

    return 1;
  }

  key_id = bra_prof_key_to_int (key);

  if (key_id < 0) 
    return -1;

  /*Check if value exist in profile*/
  if (bra_prof_key_table[key_id].idx_id < 0)
    return -1;
  else
    idx_id = bra_prof_key_table[key_id].idx_id;

  if (bra_prof_profile.available_profiles[bra_prof_profile.profile_id].index_list[idx_id] < 0)
    return -1;

  bra_file_read_block (bra_prof_profile.file_handle, 
                       bra_prof_profile.available_profiles[bra_prof_profile.profile_id].index_list[idx_id],
                       callback);

  return 1;
}

static int
bra_prof_save_profile_key (int id, char *key, char* value, bra_prof_key_saved_t callback)
{
  int key_id;
  int idx_id;
  unsigned char* p;
  int size;
  int i;

  if (id == BRA_PROF_ID_CMN)
  {
    key_id = bra_prof_cmn_key_to_int (key);

    if (key_id < 0) 
      return -1;

    /*Check if value exist in profile*/
    if (bra_prof_profile.cmn_index_list[key_id] >= 0)
    {
      /*Key is pressent. Remove old key first*/
      bra_file_delete_block (bra_prof_profile.file_handle, 
                             bra_prof_profile.cmn_index_list[key_id],
                             NULL);
    }

    if (!value)
      return 1;

    size = strlen (value) + 1;
    p = bra_prof_create_block (id, bra_prof_get_profile_sim_id(), 
        bra_prof_get_absolute_profile(), key_id, (unsigned char*)value, &size);

    i = bra_file_write_block (bra_prof_profile.file_handle, p, size, callback);

    bra_prof_profile.cmn_index_list[key_id] = (unsigned short)i;
  
    BRA_FREE (p);

    return 1;
  }

  key_id = bra_prof_key_to_int (key);

  if (key_id < 0) 
    return -1;

  /*Check if value exist in profile*/
  if (bra_prof_key_table[key_id].idx_id < 0)
    return -1;
  else
    idx_id = bra_prof_key_table[key_id].idx_id;

  if (bra_prof_profile.available_profiles[bra_prof_profile.profile_id].index_list[idx_id] >= 0)
  {
    /*Key is pressent. Remove old key first*/
    bra_file_delete_block (bra_prof_profile.file_handle, 
           bra_prof_profile.available_profiles[bra_prof_profile.profile_id].index_list[idx_id],
           NULL);
  }

  size = strlen (value) + 1;
  p = bra_prof_create_block (id, bra_prof_get_profile_sim_id(), 
      bra_prof_get_absolute_profile(), key_id, (unsigned char*)value, &size);

  i = bra_file_write_block (bra_prof_profile.file_handle, p, size, callback);

  bra_prof_profile.available_profiles[bra_prof_profile.profile_id].index_list[idx_id] = (unsigned short)i;
  
  BRA_FREE (p);

  return 1;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void
bra_prof_init_cmn_response (int idx, int eof, void* block, int size)
{
  bra_prof_block_t p;
  int idx_id;

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_08F82F5EEC1A41DD64D698548808427D, "BRA: bra_prof_get_prof_id: eof = %i, size = %i\n", eof, size));

  if (eof == 0)
  {
    if (bra_prof_unpack_block ((unsigned char *)block, size, &p) < 0)
      return;
      
    if (p.profile_id >= BRA_CFG_N_ALL_SIM_PROFILES)
      return;                  

    if (p.id != BRA_PROF_ID_CMN)
    {
      if (p.key_id == BRA_PROF_ENUM_PROF_STR)
      {
        /*Profile name sting*/
        bra_prof_profile.available_profiles[p.profile_id].profile_name = msf_cmmn_strdup (MSF_MODID_BRA, p.value);
      }
      else if(p.key_id == BRA_PROF_ENUM_CON_TYPE)
      {
        bra_prof_profile.available_profiles[p.profile_id].con_type = atoi (p.value);
      }

      idx_id = bra_prof_key_table[p.key_id].idx_id;
      if(idx_id >= 0)
        bra_prof_profile.available_profiles[p.profile_id].index_list[idx_id] = (unsigned short)idx;
      BRA_FREE (p.value);
      return;
    }

    bra_prof_profile.cmn_index_list[p.key_id] = (unsigned short)idx;

    /*This key should be added to current profile*/
    if (bra_prof_cmn_key_table[p.key_id].type == 0)
    {
      bra_prof_profile.cmn_items[p.key_id].i_value = atoi (p.value);
      BRA_FREE (p.value);
    }
    else
    {
      BRA_FREE (bra_prof_profile.cmn_items[p.key_id].s_value);
      bra_prof_profile.cmn_items[p.key_id].s_value = p.value;
    }        
  }
  else
    bra_prof_profile.profile_is_loaded = 1;
}

static void 
bra_prof_commit_cmn (void)
{
  void* reg_handle;
  int i;
  int path;

  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);

    for (i = 0; i < BRA_PROF_N_CMN_KEYS; i++)
    {
      path = bra_prof_cmn_key_table[i].path;
      /*Do not save key if path = -1*/
      if (path < 0 || bra_prof_cmn_key_table[i].modId != BRA_PROF_ID_BRA)
        continue;   

      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_cmn_key_path_table[path]);
      if (bra_prof_cmn_key_table[i].type == 0)/*0 = int*/
      {
        MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, 
                      bra_prof_cmn_key_table[i].key, 
                      bra_prof_profile.cmn_items[i].i_value);
      }
      else
      {
        MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                      bra_prof_cmn_key_table[i].key, 
                      (unsigned char*)BRA_CMN_HNV(bra_prof_profile.cmn_items[i].s_value) , 
                      (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_profile.cmn_items[i].s_value))+1));
      }    
    }  
//    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
  

#ifdef BRA_CONFIG_PROVISIONING
  /* for OTA provisioning content routing */
  {
//    reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_BRA);
    
    MSF_REGISTRY_SET_PATH( reg_handle, "/msm/rt_db/PRS");
    MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, "MimeType", 
        (unsigned char*)OTA_CONTENT_TYPE, 
        (MSF_UINT16)(strlen(OTA_CONTENT_TYPE) + 1));
//    MSF_REGISTRY_SET_COMMIT(reg_handle);  
  }
#endif /* BRA_CONFIG_PROVISIONING */

#ifdef BRA_CONFIG_MMS  
  {
//    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);

    for (i = 0; i < BRA_PROF_N_CMN_KEYS; i++)
    {
      path = bra_prof_cmn_key_table[i].path;

      /*Do not save key if path = -1*/
      if (path < 0 || bra_prof_cmn_key_table[i].modId != BRA_PROF_ID_MMS)
        continue; 

      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_cmn_key_path_table[path]);

      if (bra_prof_cmn_key_table[i].type == 0)/*0 = int*/
      {
        MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, 
                      bra_prof_cmn_key_table[i].key, 
                      bra_prof_profile.cmn_items[i].i_value);
      }
      else
      {
        MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                      bra_prof_cmn_key_table[i].key, 
                      (unsigned char*)BRA_CMN_HNV(bra_prof_profile.cmn_items[i].s_value) , 
                      (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_profile.cmn_items[i].s_value))+1));
      }    
    }
//    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
#endif /* BRA_CONFIG_MMS */

  /* for engineering mode setting */
  {
    int key_id, val;

//    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, "/BRS/BRA");

    key_id = bra_prof_cmn_key_to_int(BRA_CMN_KEY_USER_AGT);  
    val = bra_prof_profile.cmn_items[key_id].i_value;
    global_wap_user_agent = val;
    if(val == 0)
    {
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, BRS_REGISTRY_KEY_USER_AGENT_HEADER,
      (unsigned char*)BRA_CFG_PROF_DEFAULT_UA_HEADER , 
      (MSF_UINT16)(strlen (BRA_CFG_PROF_DEFAULT_UA_HEADER)+1));      
    }
    else          
    {
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, BRS_REGISTRY_KEY_USER_AGENT_HEADER,
      (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]) , 
      (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]))+1));
    }
    key_id = bra_prof_cmn_key_to_int(BRA_CMN_KEY_ACCEPT_HEADER);
    val = bra_prof_profile.cmn_items[key_id].i_value;
    global_wap_accept_header = val;
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, BRS_REGISTRY_KEY_ACCEPT_HEADER,
    (unsigned char*)BRA_CMN_HNV(bra_prof_accept_header[val]) , 
    (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_accept_header[val]))+1));
       
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, BRS_REGISTRY_KEY_ACCEPT_OBJECT_HEADER,
    (unsigned char*)BRA_CMN_HNV(BRS_CFG_ACCEPT_OBJECT_HEADER) , 
    (MSF_UINT16)(strlen (BRA_CMN_HNV (BRS_CFG_ACCEPT_OBJECT_HEADER))+1));    

#ifdef BRA_CONFIG_MMS
    key_id = bra_prof_cmn_key_to_int(BRA_CMN_KEY_MMS_VER);
    val = bra_prof_profile.cmn_items[key_id].i_value;
    global_mms_version = val;
    setMMSCVersionByEngineerMode(global_mms_version);
#endif /* BRA_CONFIG_MMS */

    key_id = bra_prof_cmn_key_to_int(BRA_CMN_KEY_OFFLINE_PAGE);
    val = bra_prof_profile.cmn_items[key_id].i_value;
    /*global_offline_page = val;*/
    global_offline_page = 1;

//    MSF_REGISTRY_SET_COMMIT (reg_handle);
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_A8801EFD5F8AD504A909EA403F1C81F2, "agent:%d, accpet:%d, mms:%d\n", global_wap_user_agent, global_wap_accept_header, global_mms_version));


    /* for UA profile URI */
//    reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH( reg_handle, "/STK");

    if (global_wap_user_agent == 0) {
      if(BRA_CFG_PROF_DEFAULT_UA_PROF != NULL && strlen((char*)BRA_CFG_PROF_DEFAULT_UA_PROF) > 0) {

        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, 
          (unsigned char*)BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_UA_PROF), 
          (MSF_UINT16)(strlen((char*)BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_UA_PROF)) + 1));
      } else {
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, (unsigned char*)NULL, 0);
      }
    } else {
      if(bra_prof_user_agent[global_wap_user_agent][BRA_PROF_UA_TABLE_URL_INDEX] != NULL &&
         strlen((char*)bra_prof_user_agent[global_wap_user_agent][BRA_PROF_UA_TABLE_URL_INDEX]) > 0) {

        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF,
          (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[global_wap_user_agent][BRA_PROF_UA_TABLE_URL_INDEX]),
          (MSF_UINT16)(strlen((char*)BRA_CMN_HNV(bra_prof_user_agent[global_wap_user_agent][BRA_PROF_UA_TABLE_URL_INDEX]))+1));
      } else {
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, (unsigned char*)NULL, 0);
      }
    }
//    MSF_REGISTRY_SET_COMMIT(reg_handle);  
    
  }
  
#ifdef BRA_CONFIG_MMS
  /* For MMS user agent */
  {
    int key_id, val;

//    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, "/MMS/client");

    key_id = bra_prof_cmn_key_to_int(BRA_CMN_KEY_USER_AGT);  
    val = bra_prof_profile.cmn_items[key_id].i_value;
    if(val == 0)
    {
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, "UsrAgent",
      (unsigned char*)BRA_CFG_PROF_DEFAULT_MMS_UA_HEADER , 
      (MSF_UINT16)(strlen (BRA_CFG_PROF_DEFAULT_MMS_UA_HEADER)+1));      
    }
    else          
    {
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, "UsrAgent",
      (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]) , 
      (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]))+1));
    }   
//    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }    
#endif  /* BRA_CONFIG_MMS */

#ifdef __DRM_SUPPORT__
  /* for DRM right object content routing */
  {
//    reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_BRA);
    
    MSF_REGISTRY_SET_PATH( reg_handle, "/msm/rt_db/BRA");
    MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, "MimeType", 
        (unsigned char*)DRM_CONTENT_TYPE, 
        (MSF_UINT16)(strlen(DRM_CONTENT_TYPE) + 1));
    MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, "PAppId_s", 
        (unsigned char*)DRM_APPLICATION_ID, 
        (MSF_UINT16)(strlen(DRM_APPLICATION_ID) + 1));
    MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, "PAppId_n", 
        (unsigned char*)DRM_APPLICATION_NO, 
        (MSF_UINT16)(strlen(DRM_APPLICATION_NO) + 1));
//    MSF_REGISTRY_SET_COMMIT(reg_handle);  
  }
#endif /* __DRM_SUPPORT__ */


  /* init mime types of predefined file extensions when loading page with file:// scheme */
#ifdef BRA_CFG_ENABLE_FILE_SCHEME
  {
      
      i = 0;
//    handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH (reg_handle, (char*)"/MSM/mimeext");
      while (bra_prof_mimeext[i][0]) {
          MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, (char*)bra_prof_mimeext[i][0],
              (unsigned char*)bra_prof_mimeext[i][1], (MSF_UINT16)(strlen(bra_prof_mimeext[i][1])+1));
          i++;
      }
      
 //   MSF_REGISTRY_SET_COMMIT (handle);
  }
#endif  /* BRA_CFG_ENABLE_FILE_SCHEME */

  MSF_REGISTRY_SET_COMMIT (reg_handle);
}

/**********************************************************************
 * Exported Functions
 **********************************************************************/
/*
 * This function initializes the common setting routines
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

static void
bra_prof_initialize_cmn_keys(void)
{
  /*Initialize common setting with default*/     
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_BRA_PROF_ID, 0);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_MMS_PROF_ID, BRA_CFG_N_WAP_PROFILES);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_TIMEOUT, BRA_CFG_DEFAULT_BRS_TIMEOUT);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_USER_TIMEOUT, BRA_CFG_DEFAULT_TIMEOUT);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_PUSH_ON, BRA_CFG_DEFAULT_PUSH_ON);
     
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_PUSH_TRUSTSETTING, BRA_CFG_DEFAULT_PUSH_TRUSTSETTING);
#endif
     
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_PUSH_SLSETTING, BRA_CFG_DEFAULT_PUSH_SLSETTING);
  bra_prof_add_cmn_str_key(BRA_CMN_KEY_OBJ_ASK, BRA_CFG_DEFAULT_OBJ_ASK);
  bra_prof_add_cmn_str_key(BRA_CMN_KEY_OBJ_LOAD, BRA_CFG_DEFAULT_OBJ_LOAD);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_USER_AGT, EM_WAP_USERAGENT_MAUI_E800);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_ACCEPT_HEADER, EM_WAP_ACCEPTHEADER_WAP20);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_OFFLINE_PAGE, 0);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_COOKIES, 1);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_CACHEON, 1);  
   
#ifdef BRA_CONFIG_MMS
  bra_prof_add_cmn_int_key(MMS_REG_KEY_IMMEDIATE_RETRIEVAL, MEA_CFG_RETRIEVAL_MODE);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_RETRIEVAL_ROAM_MODE, MMS_ROAM_DEFAULT);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_NOTIFY_RESP_MODE, MMS_NOTIFY_RESPONSE_NORMAL);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_CLASS_ADVERTISEMENT, MEA_CFG_ALLOW_ADVERT);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_ANONYMOUS_SENDER, MEA_CFG_ALLOW_ANONYM);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_REPORT_ALLOWED, MEA_CFG_DELIVERY_REPORT_ALLOWED);
  bra_prof_add_cmn_int_key(MMS_REG_KEY_MAX_RETRIEVAL_SIZE, MEA_CFG_MAX_RETR_SIZE);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_READ_REPORT, MEA_CFG_READ_REPORT);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_DELIVERY_REPORT, MEA_CFG_DELIVERY_REPORT);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_PRIORITY, MEA_CFG_PRIORITY);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_EXP_TIME, MEA_CFG_EXPIRY_TIME);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_SEND_READ_REPORT, MEA_CFG_SEND_READ_REPORT);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_MMS_VER, EM_MMS_VERSION_DEFAULT);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_SLIDE_DUR, MEA_CFG_DEFAULT_DURATION/1000);
  bra_prof_add_cmn_int_key(MEA_REG_KEY_DELIVERY_TIME, MEA_CFG_DELIVERY_TIME);
#endif
     
#ifdef BRA_CFG_DUAL_SIM
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_BRA_SIM_ID, BRA_SIM_ID_SIM1);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_BRA_SIM_ID_IS_ASK, 0);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_BRA_PROF_ID_SLAVE, 0);
  bra_prof_add_cmn_int_key(BRA_CMN_KEY_MMS_PROF_ID_SLAVE, BRA_CFG_N_WAP_PROFILES);
#endif
}


static void
bra_prof_load_cmn (void)
{
  bra_prof_initialize_cmn_keys();

  /* read common setting */
  bra_file_init (BRA_CFG_PROFILE_FILE_PATH, 
                 &bra_prof_profile.file_handle, 
                 BRA_PROF_MAX_FILE_SIZE, 
                 BRA_PROF_INITIAL_SIZE, 
                 BRA_PROF_DEFRAG_LIMIT, 
                 BRA_PROF_SIZE_INCREMENT,
                 bra_prof_init_cmn_response);
}

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
bra_prof_initialize (void)
{
  /* some profile has been initialized */
  if(bra_prof_profile.profile_is_loaded)
    return;
  
  bra_prof_init_bra_prof_profile();

  /* load common setting */
  bra_prof_load_cmn ();  

  bra_prof_continue_initialize();
}

static void
bra_prof_continue_initialize(void)
{
  int       sim_id = 0;
    
    
  /* commit common keys to registry */
  bra_prof_commit_cmn ();
    
    
  /* commit MMS keys to registry */
    
#ifdef BRA_CONFIG_MMS 
    
#ifdef BRA_CFG_DUAL_SIM
  bra_prof_commit_sim_activated_profile(BRA_PROF_ID_MMS, BRA_SIM_ID_SIM1);
#ifdef BRA_CFG_DUAL_SIM_FOR_MMS
  bra_prof_commit_sim_activated_profile(BRA_PROF_ID_MMS, BRA_SIM_ID_SIM2);
#endif
#else /* BRA_CFG_DUAL_SIM */
  bra_prof_commit_sim_activated_profile(BRA_PROF_ID_MMS, 0); /*sim_id is not use now */
#endif /* BRA_CFG_DUAL_SIM */
    
#endif /* BRA_CONFIG_MMS */
    
    
  /* commit WAP keys to registry */
    
#ifdef BRA_CFG_DUAL_SIM
  bra_sim_check_sim_number();
  sim_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
#endif
  bra_prof_commit_sim_activated_profile(BRA_PROF_ID_BRA, sim_id);
}

static void
bra_prof_commit_sim_activated_profile(int id, int sim_id)
{
  int   prof_id;
  
  
  prof_id = bra_prof_get_sim_activated_profile_id(id, sim_id);
  bra_prof_set_sim_selected_profile(id, sim_id, prof_id, NULL);
  bra_prof_commit_profile();
}


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
bra_prof_load_profile (int id, int prof_id, bra_prof_loaded_done_t callback)
{
  bra_prof_load_sim_profile(id, bra_prof_get_profile_sim_id(), prof_id, callback);
}

void
bra_prof_load_sim_profile (int id, int sim_id, int prof_id, bra_prof_loaded_done_t callback)
{
  bra_prof_profile_t *profile;
  int i;

  profile = BRA_ALLOC (sizeof (bra_prof_profile_t) + (sizeof (bra_prof_item_t)*(BRA_PROF_N_PROFILE_KEYS - 1)));

  profile->n_items = BRA_PROF_N_PROFILE_KEYS;

  for (i = 0; i < BRA_PROF_N_PROFILE_KEYS; i++)
  {
    if (bra_prof_key_table[i].type == 0) /*0 = int*/
      profile->items[i].i_value = 0;
    else
      profile->items[i].s_value = NULL;
  }
  
  bra_prof_initialize_profile (profile);
  
#ifdef BRA_CFG_DUAL_SIM
  bra_prof_profile.sim_id = sim_id;
#endif
  bra_prof_profile.id = id;
  bra_prof_profile.profile_id = BRA_PROF_GET_SIM_IDX(sim_id, prof_id);
  bra_prof_profile.profile = profile;    
  for (i = 0; i < BRA_PROF_N_PROFILE_KEYS; i++)
    bra_prof_read_profile_key(id, bra_prof_key_table[i].key, bra_prof_load_block_response);

  /* danger !! because we are not sure read is finished */
  if(callback)    
    callback();
} 

void 
bra_prof_unload_profile (void)
{
  int i;
  
  if (bra_prof_profile.profile == NULL)
    return;
  
  for (i = 0; i < bra_prof_profile.profile->n_items; i++)
  {
    if (bra_prof_key_table[i].type == 1)
    {
      /*String value*/
      BRA_FREE (bra_prof_profile.profile->items[i].s_value);
      bra_prof_profile.profile->items[i].s_value = NULL;
    }
  }

  BRA_FREE (bra_prof_profile.profile);
  bra_prof_profile.profile = NULL;
}

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
bra_prof_destroy (int id)
{
  if(!bra_prof_profile.profile_is_loaded)
    return;
  
#ifdef BRA_CFG_DUAL_SIM
  act_sim_id = -1;
#endif
  act_prof_id = -1;

  bra_prof_free_available_profiles(bra_prof_profile.available_profiles);
  bra_prof_profile.available_profiles = NULL;
  bra_prof_unload_profile ();
  bra_file_close(bra_prof_profile.file_handle);
  bra_prof_profile.file_handle = NULL;
  bra_prof_profile.profile_is_loaded = 0;
}

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
bra_prof_is_profile_loaded (int id)
{
  return bra_prof_profile.profile_is_loaded;
}


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
bra_prof_change_key_str_value (int id, char *key, char* value, bra_prof_key_saved_t callback)
{
  void* reg_handle;
  bra_prof_profile_t *profile;
  int i;
  int path;

  if (id == BRA_PROF_ID_CMN)
  {
    i = bra_prof_cmn_key_to_int (key);
    if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
      return -1;

    BRA_FREE (bra_prof_profile.cmn_items[i].s_value);
    bra_prof_profile.cmn_items[i].s_value = msf_cmmn_strdup (MSF_MODID_BRA, value);

    bra_prof_save_profile_key(BRA_PROF_ID_CMN, key, value, callback);

    path = bra_prof_cmn_key_table[i].path;
    /*Do not save key in registry if path = -1*/
    if (path >= 0 && bra_prof_cmn_key_table[i].modId == BRA_PROF_ID_BRA)
    {
      reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_cmn_key_path_table[path]);
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    key, 
                                    (unsigned char*)BRA_CMN_HNV(value) , 
                                    (MSF_UINT16)(strlen(BRA_CMN_HNV(value))+1));
      MSF_REGISTRY_SET_COMMIT (reg_handle);
    }
    
    /* MEA commit common setting by himself */

    return 1;
  }

  if (bra_prof_is_profile_loaded (0) == 0)
    return -1;

  profile = bra_prof_get_profile_by_id (0);

  if ((i = bra_prof_add_key (profile, key, value)) < 0)
    return -1;

  /*Store new value*/
  bra_prof_save_profile_key (id, key, BRA_CMN_HNV (value), callback);

  /* commit profile setting both on BRA and MEA registry */
  
//  if(bra_prof_profile.profile_id == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
  if (bra_prof_loaded_profile_is_bra_profile_in_active_use())
  {
  path = bra_prof_key_table[i].path;
  /*Do not save key in registry if path = -1*/
  if (path >= 0)
  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_key_path_table[path]);
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                  key, 
                                  (unsigned char*)BRA_CMN_HNV(value) , 
                                  (MSF_UINT16)(strlen(BRA_CMN_HNV(value))+1));
    /* Configure for STK default channel, which will be used in SL cache or SIA */
    bra_prof_commit_default_channel(reg_handle, i, profile);                                  
    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
  }

#ifdef BRA_CONFIG_MMS
//  if(bra_prof_profile.profile_id == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID))
  if (bra_prof_loaded_profile_is_mms_profile_in_active_use())
  {
    bra_prof_key_t   *key_table = (bra_prof_key_t*)bra_prof_mms_key_table;


#ifdef BRA_CFG_DUAL_SIM_FOR_MMS
    if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
        key_table = (bra_prof_key_t*)bra_prof_mms_slave_key_table;
#endif

  if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
  {
    path = key_table[i].path;    
    /*commit proxy replay address*/
    if (i == BRA_PROF_ENUM_HOMEPAGE_URL)
    {
      bra_prof_commit_mmsc(bra_prof_get_profile_sim_id(), value);
    }
    /*Do not save key in registry if path = -1*/
    else if (path >= 0)
    {
      /*Do not save key in registry if path = -1*/
      reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_mms_key_path_table[path]);
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    (char*)key_table[i].key, 
                                    (unsigned char*)BRA_CMN_HNV(value) , 
                                    (MSF_UINT16)(strlen(BRA_CMN_HNV(value))+1));
      MSF_REGISTRY_SET_COMMIT (reg_handle);
    }
  }
  else
  {
    path = key_table[i].path;
    /*Do not save key in registry if path = -1*/
    if (path >= 0)
    {      
      meaProfNetworkCallback((char*)bra_prof_mms_key_path_table[path],
                             key_table[i].key,
                             1,
                             0,
                             (char*)BRA_CMN_HNV(value));
    }
  }
  }
#endif    

  return 1;
}

static void
bra_prof_commit_bra_key_str_value(char *key, char *value)
{
  void* reg_handle;
  int i, path;


  if (!bra_prof_is_profile_loaded(0))
      return;
  if((i = bra_prof_key_to_int(key)) < 0)
    return;
 
  path = bra_prof_key_table[i].path;

  /*Do not save key if path = -1*/
  if (path >= 0)
  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_key_path_table[path]);
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                  key, 
                                  (unsigned char*)BRA_CMN_HNV(value),
                                  (MSF_UINT16)(strlen (BRA_CMN_HNV (value))+1));
    bra_prof_commit_default_channel(reg_handle, i, bra_prof_get_profile_by_id(0));                                  
    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
}

void
bra_prof_commit_key_str_value(int id, char *key, char *value)
{
  if (id == BRA_PROF_ID_BRA)
    bra_prof_commit_bra_key_str_value(key, value);
}


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
bra_prof_change_key_int_value (int id, char *key, int value, bra_prof_key_saved_t callback)
{
  void* reg_handle;
  bra_prof_profile_t *profile;
  char *s;
  int i;
  int path;
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  int is_asked_key = FALSE;
#endif


  if (id == BRA_PROF_ID_CMN)
  {
    i = bra_prof_cmn_key_to_int (key);
    if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
      return -1;
    
    bra_prof_profile.cmn_items[i].i_value = value;

    s = bra_cmn_int_to_str(value);
    bra_prof_save_profile_key(BRA_PROF_ID_CMN, key, s, callback);
    BRA_FREE (s);


    path = bra_prof_cmn_key_table[i].path;
    /*Do not save key in registry if path = -1*/
    if (path >= 0 && bra_prof_cmn_key_table[i].modId == BRA_PROF_ID_BRA)
    {
      reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_cmn_key_path_table[path]);
      MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, key, value);
      MSF_REGISTRY_SET_COMMIT (reg_handle);
    }

    /* for engineering mode setting */
    em_wap_change_value(bra_prof_cmn_key_table[i].key,
                        bra_prof_profile.cmn_items[i].i_value);
    
    /* MEA commit common setting by himself */
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_PROF_CHANGE_KEY_INT_VALUE, 
        "BRA: bra_prof_change_key_int_value(): id=%d, index=%d, value=%d",
        id, bra_prof_cmn_key_to_int(key), value));

    return 1;
  }

  if (bra_prof_is_profile_loaded (0) == 0)
    return -1;

  profile = bra_prof_get_profile_by_id (0);
  

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
      BRA_PROF_CHANGE_KEY_INT_VALUE, 
      "BRA: bra_prof_change_key_int_value(): id=%d, index=%d, value=%d",
      id, bra_prof_key_to_int(key), value));

#ifdef BRA_CFG_CONN_ALWAYS_ASK

  if (strcmp((const char*)key, (const char*)BRA_PROF_KEY_NET_ID) == 0)
  {
    /* to remove the dependency of net id and ask flag while committing net id key to registry */
    int    ask_flag;
    
    ask_flag = always_ask_is_always_ask_data_account((kal_uint32)value);
	if (ask_flag != bra_prof_get_key_int_value(id, BRA_PROF_KEY_NET_ID_IS_ASK))
      bra_prof_change_key_int_value(id, BRA_PROF_KEY_NET_ID_IS_ASK, ask_flag, NULL);
  }  
  
  /* just to avoid STK reset channel when the net id is change,
     we do not commit the net id asked to registry here */
  if (strcmp((const char*)key, (const char*)BRA_PROF_KEY_NET_ID_ASKED) == 0)
  {
    is_asked_key = TRUE;
    key = BRA_PROF_KEY_NET_ID;
  }
#endif /*BRA_CFG_CONN_ALWAYS_ASK */

  value = bra_prof_filter_int_key_to_get_raw_net_id(id, key, value);

  if ((i = bra_prof_add_int_key (profile, key, value)) < 0)
        return -1;
  
  /*Store new value*/
  s = bra_cmn_int_to_str(value);
  bra_prof_save_profile_key (id, key, s, callback);
  BRA_FREE (s);

#ifdef BRA_CFG_CONN_ALWAYS_ASK
  if (is_asked_key == TRUE) /* do not submit this key value to registry */
    return 1;
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

  /* commit profile setting both on BRA and MEA registry */

//  if(bra_prof_profile.profile_id == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
  if (bra_prof_loaded_profile_is_bra_profile_in_active_use())
  {
  path = bra_prof_key_table[i].path;
  /*Do not save key if path = -1*/
  if (path >= 0)
  {
#ifdef BRA_CFG_PROF_FALLBACK
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_D0E23BCC23B71FF978F9D989B3E1ABE2, "BRA: bra_prof_change_key_int_value(): in browser section: bra_prof_profile.profile_id:%d\n", bra_prof_profile.profile_id));
#endif  /* BRA_CFG_PROF_FALLBACK */

    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_key_path_table[path]);
    value = bra_prof_filter_int_key_to_generate_ext_net_id(id, key, value);
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, key, value);
    /* Configure for STK default channel, which will be used in SL cache or SIA */
    bra_prof_commit_default_channel(reg_handle, i, profile);    
    MSF_REGISTRY_SET_COMMIT (reg_handle);
    
    /* change bearer type for status icon
    if(i == BRA_PROF_ENUM_NET_ID)
      BRAa_setBearerType(value);
    */
  }
  }

#ifdef BRA_CONFIG_MMS
//  if(bra_prof_profile.profile_id == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID))
  if (bra_prof_loaded_profile_is_mms_profile_in_active_use())
  {
    bra_prof_key_t   *key_table = (bra_prof_key_t*)bra_prof_mms_key_table;
      
#ifdef BRA_CFG_DUAL_SIM_FOR_MMS
    if (bra_prof_profile.sim_id == BRA_SIM_ID_SIM2)
      key_table = (bra_prof_key_t*)bra_prof_mms_slave_key_table;
#endif

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_1555812F353150801640F4B35CA502BD, "BRA: bra_prof_change_key_int_value(): in mms section: bra_prof_profile.profile_id:%d, i:%d, value:%d\n", bra_prof_profile.profile_id, i, value));

  value = bra_prof_filter_int_key_to_generate_ext_net_id(id, (char*)bra_prof_key_table[i].key, value);

  if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
  {
    path = key_table[i].path;
    /*Do not save key if path = -1*/
    if (path >= 0)
    {
      reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_mms_key_path_table[path]);
      MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, (char*)key_table[i].key, value);
      MSF_REGISTRY_SET_COMMIT (reg_handle);
    }
  }
  else
  {
    path = key_table[i].path;
    /*Do not save key if path = -1*/
    if (path >= 0)
    {
      meaProfNetworkCallback((char*)bra_prof_mms_key_path_table[path],
                             key_table[i].key,
                             0,
                             value,
                             NULL);
    }
  }
  }
#endif

  return 1;
}

/*can only use for browser now */
static void
bra_prof_commit_bra_key_int_value(char *key, int value)
{
  void* reg_handle;
  int i, path;


  if (!bra_prof_is_profile_loaded(0))
    return;
  if((i = bra_prof_key_to_int(key)) < 0)
    return;
 
  path = bra_prof_key_table[i].path;

  /*Do not save key if path = -1*/
  if (path >= 0)
  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, (char*)bra_prof_key_path_table[path]);
    value = bra_prof_filter_int_key_to_generate_ext_net_id(BRA_PROF_ID_BRA, key, value);
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, key, value);
    /* Configure for STK default channel, which will be used in SL cache or SIA */
    bra_prof_commit_default_channel(reg_handle, i, bra_prof_get_profile_by_id(0));                                  
    MSF_REGISTRY_SET_COMMIT (reg_handle);
  }
}

void
bra_prof_commit_key_int_value(int id, char *key, int value)
{
    if (id == BRA_PROF_ID_BRA)
      bra_prof_commit_bra_key_int_value(key, value);
}

static void
em_wap_change_value (char *key, int val)
{
  void *reg_handle;
  
  reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);

  if(strcmp(key, BRA_CMN_KEY_USER_AGT) == 0)
  {
    global_wap_user_agent = val;

    if(val == 0)
    {
      /* for UA profile URI */
      if(BRA_CFG_PROF_DEFAULT_UA_PROF != NULL && strlen((char*)BRA_CFG_PROF_DEFAULT_UA_PROF) > 0) {
        MSF_REGISTRY_SET_PATH( reg_handle, "/STK");
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, 
          (unsigned char*)BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_UA_PROF), 
          (MSF_UINT16)(strlen((char*)BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_UA_PROF)) + 1));
      } else {
        MSF_REGISTRY_SET_PATH( reg_handle, "/STK");
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, (unsigned char*)NULL, 0);
      }

      /* for UA profile name */
      MSF_REGISTRY_SET_PATH (reg_handle, "/BRS/BRA");
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    BRS_REGISTRY_KEY_USER_AGENT_HEADER, 
                                    (unsigned char*)BRA_CFG_PROF_DEFAULT_UA_HEADER,
                                    (MSF_UINT16)(strlen (BRA_CFG_PROF_DEFAULT_UA_HEADER)+1));
    }
    else
    {
      /* for UA profile URI */
      if(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_URL_INDEX] != NULL &&
         strlen((char*)bra_prof_user_agent[val][BRA_PROF_UA_TABLE_URL_INDEX]) > 0) {

        MSF_REGISTRY_SET_PATH( reg_handle, "/STK");
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF,
          (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_URL_INDEX]),
          (MSF_UINT16)(strlen((char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_URL_INDEX]))+1));
      } else {
        MSF_REGISTRY_SET_PATH( reg_handle, "/STK");
        MSF_REGISTRY_SET_ADD_KEY_STR( reg_handle, BRA_PROF_KEY_UA_PROF, (unsigned char*)NULL, 0);
      }

      /* for UA profile name */
      MSF_REGISTRY_SET_PATH (reg_handle, "/BRS/BRA");
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    BRS_REGISTRY_KEY_USER_AGENT_HEADER, 
                                    (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]),
                                    (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]))+1));
    }                                                                                  
  }
  else if(strcmp(key, BRA_CMN_KEY_ACCEPT_HEADER) == 0)
  {
    global_wap_accept_header = val;   
    MSF_REGISTRY_SET_PATH (reg_handle, "/BRS/BRA");
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                  BRS_REGISTRY_KEY_ACCEPT_HEADER, 
                                  (unsigned char*)BRA_CMN_HNV(bra_prof_accept_header[val]),
                                  (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_accept_header[val]))+1));
  }
#ifdef BRA_CONFIG_MMS
  else if(strcmp(key, BRA_CMN_KEY_MMS_VER) == 0)
  {
    global_mms_version = val;
    setMMSCVersionByEngineerMode(global_mms_version);
  }
#endif  
  else if(strcmp(key, BRA_CMN_KEY_OFFLINE_PAGE) == 0)
  {
    /*global_offline_page = val;*/
    global_offline_page = 1;
  }    

  MSF_REGISTRY_SET_COMMIT (reg_handle);
  
#ifdef BRA_CONFIG_MMS  
  /* For MMS user agent */
  if(strcmp(key, BRA_CMN_KEY_USER_AGT) == 0)
  {
    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, "/MMS/Client");
    if(val == 0)
    {      
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    "UsrAgent", 
                                    (unsigned char*)BRA_CFG_PROF_DEFAULT_UA_HEADER,
                                    (MSF_UINT16)(strlen (BRA_CFG_PROF_DEFAULT_UA_HEADER)+1));
    }
    else
    {
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                    "UsrAgent", 
                                    (unsigned char*)BRA_CMN_HNV(bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]),
                                    (MSF_UINT16)(strlen (BRA_CMN_HNV (bra_prof_user_agent[val][BRA_PROF_UA_TABLE_NAME_INDEX]))+1));
    }
    MSF_REGISTRY_SET_COMMIT (reg_handle);                                                                                  
  }  
#endif  

}

void
bra_prof_change_em_setting (kal_uint8 opt, kal_uint8 val)
{
  if(!bra_prof_profile.profile_is_loaded)
    return;
    
  switch(opt)
  {
  case EM_WAP_USERAGENT_OPT:
    if(val >= EM_WAP_USERAGENT_MAX)
      return;
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_AGT, (int)val, NULL);
    break;
  case EM_WAP_ACCEPTHEADER_OPT:
    if(val >= EM_WAP_ACCEPTHEADER_MAX)
      return;
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_ACCEPT_HEADER, (int)val, NULL);
    break;
#ifdef BRA_CONFIG_MMS
  case EM_MMS_VERSION_OPT:
    if(val >= EM_MMS_VERSION_MAX)
      return;
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_VER, (int)val, NULL);
    break;
#endif
  case EM_WAP_OFFLINE_PAGE_OPT:
    bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OFFLINE_PAGE, (int)val, NULL);
    break;    
  default:
    break;
  }    
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_A8801EFD5F8AD504A909EA403F1C81F2, "agent:%d, accpet:%d, mms:%d\n", global_wap_user_agent, global_wap_accept_header, global_mms_version));
  
  /* update profile checksum */
  {
    extern void msm_compute_checksum_critical_file_by_index(int idx);
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
  }      
}

static void 
bra_prof_commit_default_channel(void *reg_handle, int i, bra_prof_profile_t *profile)
{
  if(i == BRA_PROF_ENUM_CON_TYPE)
  {
    MSF_REGISTRY_SET_PATH (reg_handle, "/STK/channel");
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, "conntype", profile->items[i].i_value);
  }
  else if(i == BRA_PROF_ENUM_NET_ID)
  {
    int  value;  

    MSF_REGISTRY_SET_PATH (reg_handle, "/STK/channel");
    value = bra_prof_filter_int_key_to_generate_ext_net_id(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, profile->items[i].i_value); 
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, "net_id", value);
  }      
  else if(i == BRA_PROF_ENUM_PRX_ADDR)
  {
    unsigned char addr[4];
    bra_cmn_get_address((const char*)(profile->items[i].s_value), (unsigned char*)addr);

    MSF_REGISTRY_SET_PATH (reg_handle, "/STK/channel");
    /*MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                  "proxy_ip", 
                  (unsigned char*)profile->items[i].s_value, 
                  (MSF_UINT16)strlen (BRA_CMN_HNV (profile->items[i].s_value)));
    */
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                  "proxy_ip", 
                  (unsigned char*)addr, 
                  4);
  }      
  else if(i == BRA_PROF_ENUM_PRX_PORT)
  {
    MSF_REGISTRY_SET_PATH (reg_handle, "/STK/channel");
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, "port", profile->items[i].i_value);
  }      
}

/*
 * This function returns the string value of key in the current profile. 
 *
 * id        : ID, Not used in current implementaion
 * key       : key to be changed
 *
 * RETURN    : The string value of key. If Key is undefined the return value is NULL.
 */
char*
bra_prof_get_key_str_value (int id, char *key)
{
  int i;
  bra_prof_profile_t *profile;

  if (id == BRA_PROF_ID_CMN)
  {
    i = bra_prof_cmn_key_to_int (key);
    if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
      return 0;
    return bra_prof_profile.cmn_items[i].s_value;    
  }
    
  if (bra_prof_is_profile_loaded (0) == 0)
    return NULL;
  
  profile = bra_prof_get_profile_by_id (0);

  if (profile == NULL)
    return NULL;

  i = bra_prof_key_to_int(key);
  
  if (i > profile->n_items)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_613B6ADDCE1DD359AC64870E86EFC21C, "BRA: Profile Error: Ilegal key (Get Sting)'%s'\n", key));
    return NULL;
  }

  return profile->items[i].s_value;
}

/*
 * This function returns the integer value of key in the current profile. 
 *
 * id        : ID, Not used in current implementation
 * key       : key to be changed
 *
 * RETURN: the integer value of key. If Key is undefined the return value is 0.
 */
int
bra_prof_get_key_int_value (int id, char *key)
{
  int                   i;
  int                   i_value;
  bra_prof_profile_t    *profile;


  if (id == BRA_PROF_ID_CMN)
  {
    i = bra_prof_cmn_key_to_int (key);
    if (i < 0 || i >= BRA_PROF_N_CMN_KEYS)
      return 0;
/*
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_PROF_GET_KEY_INT_VALUE, "BRA: bra_prof_get_key_int_value(): id=%d, index=%d, value=%d\n", 
        id, i, bra_prof_profile.cmn_items[i].i_value));
*/
    return bra_prof_profile.cmn_items[i].i_value;    
  }

  i = bra_prof_key_to_int(key);

/*
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_PROF_E21473D7F49571D8739C241C2EAED07A, "BRA: bra_prof_get_key_int_value(): id=MMS, i:%d\n", i));
*/
  if (bra_prof_is_profile_loaded (0) == 0)
    return 0;

  profile = bra_prof_get_profile_by_id (0);

  if (profile == NULL)
    return 0;


    
  if (i > profile->n_items)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PROF_CCEC1352939987A1800F6F63596649EB, "BRA: Profile Error: Ilegal key (Get integer)'%s'\n", key));
    return 0;
  }

  if (i == BRA_PROF_ENUM_NET_ID 
#ifdef BRA_CFG_PROF_FALLBACK
      || i == BRA_PROF_ENUM_NET_ID_GPRS || i == BRA_PROF_ENUM_NET_ID_GSM
#endif
      )
    i_value = bra_prof_filter_int_key_to_generate_ext_net_id(id, key, profile->items[i].i_value);
  else
    i_value = profile->items[i].i_value;

/*
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
      BRA_PROF_GET_KEY_INT_VALUE, "BRA: bra_prof_get_key_int_value(): id=%d, index=%d, value=%d\n", 
      id, i, i_value));
*/
  return i_value;
}

/*
 * This function returns a struct with all profile names associated with id.   
 * If no specific name have been added for the profile, the string specified by
 * BRA_STR_PROFILE + index is used
 *
 * NOTE! the msf strings returend  must  be released by the calling function.
 *
 * PARAMETERS
 *
 * id        : ID, Not used in current implementaion
 *
 * RETURN    : Pointer to struct holding all available profile names
 */
bra_prof_names_t*
bra_prof_get_sim_all_profile_names (int id, int sim_id)
{
  int               i;
  char             *s;
  bra_prof_names_t *p;
  int               idx;

  p = BRA_ALLOC (sizeof(bra_prof_names_t) + sizeof(MsfStringHandle)*(BRA_PROF_GET_PROF_NUM(id) - 1));
  p->n_items = BRA_PROF_GET_PROF_NUM(id);

  for (i = 0; i < p->n_items; i++)
  {
    idx = BRA_PROF_GET_SIM_IDX(sim_id, BRA_PROF_GET_PROF_IDX(id, i));
    s = bra_prof_get_profile_name(i, (const char*)bra_prof_profile.available_profiles[idx].profile_name);
    p->s[i] = BRA_STRCONV(s);
    BRA_FREE(s);
  }
  return p;
}


bra_prof_names_t*
bra_prof_get_all_profile_names (int id)
{
  return bra_prof_get_sim_all_profile_names(id, bra_prof_get_profile_sim_id());
}


char*
bra_prof_get_profile_name( int prof_index,  const char* prof_name)
{  
  char            *index;
  int             length;
  char            *new_name;
    
    
  if (prof_name != NULL && 0 != (length = strlen(prof_name)))
  {
    new_name = BRA_ALLOC(length + 1);
    strcpy(new_name, prof_name);
    return new_name;
  }
  else
  {
    length = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_DEFAULT_PROFILE_NAME, 1, MsfUtf8);
    new_name = BRA_ALLOC (length + 5); /*5 = SP + 3 seq. numbers + null*/
    MSF_WIDGET_STRING_GET_DATA (BRA_STR_DEFAULT_PROFILE_NAME, new_name, MsfUtf8);
    new_name[length]   = '\0';   
    index = bra_cmn_int_to_str (prof_index + 1);
    strcat(new_name, index);
      
    BRA_FREE (index);
    return new_name;
  }
}


int 
bra_prof_get_profile_sim_id(void)
{

#ifdef BRA_CFG_DUAL_SIM
    return bra_prof_profile.sim_id;
#else
    return 0;
#endif 
}


int
bra_prof_get_profile_id (void)
{
  return bra_prof_profile.id;
}

/*****************************************************************/
/*                                                               */
/*    PROFILES MENU                                              */
/*                                                               */
/*****************************************************************/
/* This comment is part of an Reference example to display Window functionallity.
 * The full reference example is described in the BRA Reference Manual 
 *
 * Ref: 2.4
 *
 * 4. The function below delete all widges and gadgets allocated for 
 *    this window. ic custom variables have been added to the structure
 *    these must be deallocated aswell.
 *    See comments in code below for further explanation.
 */
static void 
bra_delete_profile_list_menu (bra_win_t *win)
{
  bra_prof_profile_menu_t *p;

  /*First retrieve the window structure*/
  p = (bra_prof_profile_menu_t *)(win);

  /*Remove the window from the screen*/
 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

  /*Release all widgets*/
  MSF_WIDGET_RELEASE (p->windowHandle); 
  MSF_WIDGET_RELEASE (p->selectActionHandle);
  MSF_WIDGET_RELEASE (p->backActionHandle);

  /*Finally free the window structure*/
  BRA_FREE (p);

  #ifdef BRA_CONFIG_MMS
  if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  {
    extern void msm_compute_checksum_critical_file_by_index(int idx);
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
  }    
  #endif /* BRA_CONFIG_MMS */

  /* should restore the wap profile in active use when exit this profile list menu */
  bra_prof_restore_bra_active_profile(FALSE);
}


/* This comment is part of an Reference example to display Window functionality.
 * The full reference example is described in the BRA Reference Manual 
 *
 * Ref: 2.2
 *
 * 2. The function below handles the actions triggered in the Profiles menu.
 *
 */
static void
bra_action_profile_list_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_prof_profile_menu_t *p;
  int i;
  /*First retrieve the window structure*/  
  p = (bra_prof_profile_menu_t *)(win);

  /*Check this was the Accept action*/
	if (bra_action == p->selectActionHandle)
	{
    /*The Accept action was enabled. Now find out which menu item that was selected*/
    for(i = 0; i < BRA_PROF_GET_PROF_NUM(bra_prof_profile.id); i++)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->windowHandle, i) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        /* switch to the profile to be edit */        
        bra_prof_set_sim_selected_profile(bra_prof_profile.id, bra_prof_get_profile_sim_id(), BRA_PROF_GET_PROF_IDX(bra_prof_profile.id, i), NULL);
        bra_create_profile_edit_menu();
        return;
      }
    }
	}	  
  
  /*If Not the Accept action the menu should be closed*/
  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

}
/* This comment is part of an Reference example to display Window functionality.
 * The full reference example is described in the BRA Reference Manual 
 *
 * Ref: 2.3
 *
 * 3. The in_focus function is called when the window gains focus. For
 *    the current implementation this is not useful information and have
 *    therefore been excluded and instead NULL is past as argument.
 */

void
bra_prof_list_menu_in_focus (bra_win_t *win)
{
  int i;
  bra_prof_profile_menu_t *pwin = (bra_prof_profile_menu_t*)win;
  bra_prof_names_t *p;
  int  sel_prof_id = act_prof_id;


  /* just select the activated profile of current edited SIM */ 
  sel_prof_id = bra_prof_get_sim_activated_profile_id(bra_prof_profile.id, bra_prof_get_profile_sim_id());
  bra_prof_set_sim_selected_profile(bra_prof_profile.id, bra_prof_get_profile_sim_id(), act_prof_id, NULL);
  p = bra_prof_get_sim_all_profile_names (bra_prof_profile.id, bra_prof_get_profile_sim_id());

  for (i = 0; i < p->n_items; i++)
  {
	  MSF_WIDGET_CHOICE_SET_ELEMENT (pwin->windowHandle, i, p->s[i],  0, 0, 0, FALSE);
     MSF_WIDGET_RELEASE (p->s[i]);
  }
      
  for (i = 0; i < p->n_items; i++)
  {     
     if(BRA_PROF_GET_PROF_IDX(bra_prof_profile.id, i) == sel_prof_id)
        MSF_WIDGET_CHOICE_SET_ELEM_STATE (pwin->windowHandle, i, MSF_CHOICE_ELEMENT_SELECTED);
     else
        MSF_WIDGET_CHOICE_SET_ELEM_STATE (pwin->windowHandle, i, 0);
  } 

  BRA_FREE (p);
        
}


void
bra_prof_create_profile_menu(MSF_UINT8 id)
{
#ifdef BRA_CFG_DUAL_SIM
  if (id == BRA_PROF_ID_MMS)   
    bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);

#ifndef BRA_CFG_DUAL_SIM_FOR_MMS
  if (id == BRA_PROF_ID_MMS)
  {
    bra_prof_create_profile_list_menu(id, BRA_SIM_ID_SIM1);
    return;
  }
#endif /* BRA_CFG_DUAL_SIM_FOR_MMS */

  bra_sim_create_edit_sim_menu(id);

#else /*BRA_CFG_DUAL_SIM*/

  bra_prof_create_profile_list_menu(id, 0);

#endif /* BRA_CFG_DUAL_SIM */
}


/* This comment is part of an Reference example to display Window functionality.
 * The full reference example is described in the BRA Reference Manual 
 *
 * Ref: 2.1
 *
 * 1. The function below creates and displays the profiles select menu.
 *    See comments in code below for further explanation.
 *
 */

/*
 * This function create and display a menu where the user can select the   
 * active profile
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_prof_create_profile_list_menu (int id, int sim_id)
{
  bra_prof_profile_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  bra_prof_names_t *p;
  int i;
  MsfDeviceProperties prop;


  bra_prof_profile.id = id;

#ifdef BRA_CFG_DUAL_SIM
  if (id == BRA_PROF_ID_MMS)
      act_sim_id = sim_id;  /*both SIM is activated, use the edit one */
  else
      act_sim_id = bra_sim_get_bra_sim_id_in_active_use();
  act_prof_id = bra_prof_get_sim_activated_profile_id(id, act_sim_id);
  bra_prof_profile.sim_id = sim_id;
 /*
  if (id == BRA_PROF_ID_MMS)
      BRAa_setBearerType(0);
  else
      BRAa_setBearerType(bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));
*/
#else /* BRA_CFG_DUAL_SIM */

  if(id == BRA_PROF_ID_MMS) {
    act_prof_id = bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
    BRAa_setBearerType(0);
  } else {
    act_prof_id = bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID);
    BRAa_setBearerType(bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));
  }
#endif /* BRA_CFG_DUAL_SIM */
   
  /*Get Device properties. e.g. the screen size since this can be dynamicaly changed*/
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  /*Allocate memory for the structure to hold the window and action handles
    If other static variables are needed these can be added to the menu type.
    Note thoug that the first item must be the window handle*/
  win = BRA_ALLOCTYPE (bra_prof_profile_menu_t);
  /*Create the Back and Accept action handle*/
	win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                                     BRA_STR_OK,
                                                     MsfSelect,
                                                     1, 
                                                     0x8000);
	win->backActionHandle   = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                                     BRA_STR_BACK,
                                                     MsfBack,
                                                     1, 
                                                     0x8000);
  /*Now create the actual menu window*/  

   /* initialize temp profile id to current profile id */
	win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,MsfMultipleChoice,
												          &prop.displaySize,
												          win->selectActionHandle,
                                              0, /*Element Position*/
                                              MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
                                              0x8000, /*Property Mask*/
                                              0 /*Default Style*/);

  /* For sync PlutoMMI profile UI */                                            
  HDIa_widgetExtMenuProfileStyle(win->windowHandle);   
                                                
  /*Set window title*/
   MSF_WIDGET_SET_TITLE (win->windowHandle,BRA_STR_SELECT_PROFILE);

	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

  /*Add the available profile names to the menu*/
  p = bra_prof_get_sim_all_profile_names (id, sim_id);

  for (i = 0; i < p->n_items; i++)
  {
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i, p->s[i],  0, 0, 0, TRUE);
     MSF_WIDGET_RELEASE (p->s[i]);
  }

  BRA_FREE (p);

  /*Add the previously created actions to the window*/
	MSF_WIDGET_ADD_ACTION (win->windowHandle, win->backActionHandle);
	MSF_WIDGET_ADD_ACTION (win->windowHandle, win->selectActionHandle);

  /*Finally Show dialog. Note that the in focus parameter is NULL, i.e. this menu has no need
    to know if it is in focus or not.*/
  bra_win_show_window (BRA_WIN_ID_PROFILE_MENU, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_profile_list_menu, 
                      bra_prof_list_menu_in_focus,
                      bra_action_profile_list_menu);
}




/*------------------------------off line profile operation--------------------------*/

static char *_save_key;
static int _prof_id;
static char *_read_value;
static int _idx;
static bra_prof_profile_t *offline_profile;

#ifdef BRA_CFG_DUAL_SIM
static int  _bra_sim_id;
static int  _bra_sim_is_ask;
static char *_bra_sim2_read_value;
static int _bra_sim2_idx;
#endif /* BRA_CFG_DUAL_SIM */







static void
bra_prof_read_file_response (int idx, int eof, void* block, int size)
{
  int key_id;
  bra_prof_block_t p;

  key_id = bra_prof_key_to_int (_save_key);

  if (eof == 0 && bra_prof_unpack_block ((unsigned char *)block, size, &p) >= 0)
  {
#ifdef BRA_CFG_DUAL_SIM
    if (p.id == BRA_PROF_ID_CMN)
    {
      if (strcmp((const char*)bra_prof_cmn_key_table[p.key_id].key, 
        (const char*)BRA_CMN_KEY_BRA_SIM_ID_IS_ASK) == 0)
      {
        _bra_sim_is_ask = atoi((const char*)p.value);
      }
      else if (strcmp((const char*)bra_prof_cmn_key_table[p.key_id].key, 
        (const char*)BRA_CMN_KEY_BRA_SIM_ID) == 0)
      {
        _bra_sim_id = atoi((const char*)p.value);
      }
    }
    else
#endif /* BRA_CFG_DUAL_SIM */
    {
      if (_prof_id == p.profile_id && p.key_id == key_id)
      {
        /*Key is present. Remove old key first*/
        //	sprintf(_read_value, "%s", p.value);
        _read_value = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)p.value);
      }
#ifdef BRA_CFG_DUAL_SIM
      else if (BRA_PROF_GET_SIM_IDX(BRA_SIM_ID_SIM2, _prof_id) == p.profile_id && 
               p.key_id == key_id)
      {
        _bra_sim2_read_value = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)p.value);
      }
#endif /* BRA_CFG_DUAL_SIM */
    }
  }
}


int
bra_prof_off_line_read_profile_key(int prof_id, char *key, char *value)
{
  int  sim_id = 0;
  int  buf_len =  1024; //temp here, 1024 is enough
  int  id = BRA_PROF_ID_BRA;


#ifdef BRA_CFG_DUAL_SIM
  sim_id = BRA_SIM_ID_DEFAULT;
#endif

  if (prof_id >= BRA_CFG_N_WAP_PROFILES)
      id = BRA_PROF_ID_MMS;
  return bra_prof_off_line_read_sim_profile_key(id, sim_id, prof_id, key, value, &buf_len);
}

int
bra_prof_off_line_read_sim_profile_key (int id, int sim_id, int prof_id, 
                                        char *key, char *value, int *buf_len)
{
  int   str_len;
  int   key_id;
  char  *ret_value;
  void *file_handle;
  extern void* widget_string_content(MsfStringHandle str);


  if (id != BRA_PROF_ID_BRA && id != BRA_PROF_ID_MMS)
      return 0;

#ifdef BRA_CFG_DUAL_SIM
  if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2 && sim_id != BRA_SIM_ID_DEFAULT)
      return 0;
#endif
  
  if (prof_id < 0 || prof_id >= BRA_CFG_N_PROFILES)
      return 0;

  if (key == NULL || value == NULL || buf_len == NULL)
      return 0;

  MSF_MEM_INIT (MSF_MODID_BRA, NULL);

  key_id = bra_prof_key_to_int (key);

  if (key_id < 0) 
    return 0;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, 
      BRA_PROF_OFF_LINE_READ_SIM_PROFILE_KEY,
      "BRA: bra_prof_off_line_read_sim_profile_key(): sim_id=%d, prof_id=%d, key_id=%d\n",
      sim_id, prof_id, key_id));

  /*Check if value exist in profile*/

  _save_key = key;
  _read_value = NULL;
  _prof_id = prof_id;

#ifdef BRA_CFG_DUAL_SIM
  _bra_sim_id = BRA_SIM_ID_SIM1;
  _bra_sim_is_ask = 0;
  _bra_sim2_read_value = NULL; 
#endif

  bra_file_init (BRA_CFG_PROFILE_FILE_PATH, 
                 &file_handle, 
                 BRA_PROF_MAX_FILE_SIZE, 
                 BRA_PROF_INITIAL_SIZE, 
                 BRA_PROF_DEFRAG_LIMIT, 
                 BRA_PROF_SIZE_INCREMENT,
                 bra_prof_read_file_response);

  ret_value = _read_value;

#ifdef BRA_CFG_DUAL_SIM
  {
    int  sim_info;
    int  sel_sim_id = sim_id;


    if (sim_id == BRA_SIM_ID_DEFAULT) //get current SIM in active use
    {
      sim_info = bra_sim_get_sim_card_number();
      if (sim_info == BRA_SIM_ID_DUAL_SIM)
      {
        if( _bra_sim_is_ask != 0)
          sel_sim_id = BRA_SIM_ID_SIM1;
        else
          sel_sim_id = _bra_sim_id;
      }
      else if (sim_info == BRA_SIM_ID_SIM1 || sim_info == BRA_SIM_ID_SIM2)
      {
        sel_sim_id = sim_info;
      }
      else
      {
        sel_sim_id = BRA_SIM_ID_SIM1;
      }
    }
    if (sel_sim_id == BRA_SIM_ID_SIM2)
      ret_value = _bra_sim2_read_value;
  }
#endif /* BRA_CFG_DUAL_SIM */ 
  
  if (ret_value == NULL || (0 == (str_len = strlen(ret_value))))
  {
    value[0] = '\0';
  }
  else
  {
    if (str_len < *buf_len)
    {
      strcpy(value, (const char*)ret_value);
      *buf_len = str_len + 1;  //return buffer
    }
    else
    {
      strncpy(value, (const char*)ret_value, *buf_len - 1);
      value[*buf_len - 1] = '\0';
    }
  }

  MSF_MEM_FREE_ALL(MSF_MODID_BRA);

  if(value[0] == '\0')
  {
    switch(key_id)
	 {
    case BRA_PROF_ENUM_PRX_ADDR:
      sprintf(value, "%s", BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_PRX_ADDR));
      break;
    case BRA_PROF_ENUM_PRX_PORT:
      sprintf(value, "%s", BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_PRX_PORT));
      break;
    case BRA_PROF_ENUM_CON_TYPE:
      sprintf(value, "%d", BRA_CFG_PROF_DEFAULT_CON_TYPE);
      break;
    case BRA_PROF_ENUM_PROF_STR:
      sprintf(value, "%s%d", (char*)widget_string_content(BRA_STR_DEFAULT_PROFILE_NAME), act_prof_id+1);
      break;
    case BRA_PROF_ENUM_PRX_PWD:
      sprintf(value,  "%s", BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_PRX_PWD));
      break;
    case BRA_PROF_ENUM_PRX_UID:
      sprintf(value,  "%s", BRA_CMN_HNV(BRA_CFG_PROF_DEFAULT_PRX_UID));
		break;
    case BRA_PROF_ENUM_NET_ID:
	   sprintf(value, "%d", BRA_CFG_PROF_DEFAULT_NET_ID);
		break;
    case BRA_PROF_ENUM_HOMEPAGE_TITLE:
	   sprintf(value, "%s", (char*)widget_string_content(BRA_CFG_DEFAULT_HOMPAGE_TITLE));
		break;
    case BRA_PROF_ENUM_HOMEPAGE_URL:
	   sprintf(value, "%s", BRA_CMN_HNV(BRA_CFG_DEFAULT_HOMPAGE_URL));
		break;
#ifdef BRA_CFG_PROF_FALLBACK
    case BRA_PROF_ENUM_NET_ID_IS_DUAL:
	   sprintf(value, "%d", BRA_CFG_PROF_DEFAULT_NET_ID_DUAL);
		break;
    case BRA_PROF_ENUM_NET_ID_GPRS:
	   sprintf(value, "%d", BRA_CFG_PROF_DEFAULT_NET_ID_GPRS);
		break;
    case BRA_PROF_ENUM_NET_ID_GSM:
	   sprintf(value, "%d", BRA_CFG_PROF_DEFAULT_NET_ID_GSM);
		break;
#endif /* BRA_CFG_PROF_FALLBACK */
    
#ifdef BRA_CFG_CONN_ALWAYS_ASK
    case BRA_PROF_ENUM_NET_ID_IS_ASK:
      sprintf(value, "%d", 0);
      break;
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
    default:
        break;
	 }
  }

  return 1;
} 




static void
bra_prof_check_file_response (int idx, int eof, void* block, int size)
{
  int key_id;
  bra_prof_block_t p;
  
  
  key_id = bra_prof_key_to_int (_save_key);
  
  if (eof == 0 && bra_prof_unpack_block ((unsigned char *)block, size, &p) >= 0)
  {
#ifdef BRA_CFG_DUAL_SIM
    if (p.id == BRA_PROF_ID_CMN)
    {
      if (strcmp((const char*)bra_prof_cmn_key_table[p.key_id].key, 
        (const char*)BRA_CMN_KEY_BRA_SIM_ID_IS_ASK) == 0)
      {
        _bra_sim_is_ask = atoi((const char*)p.value);
      }
      else if (strcmp((const char*)bra_prof_cmn_key_table[p.key_id].key, 
        (const char*)BRA_CMN_KEY_BRA_SIM_ID) == 0)
      {
        _bra_sim_id = atoi((const char*)p.value);
      }
    }
    else
#endif /* BRA_CFG_DUAL_SIM */
    {
      if (_prof_id == p.profile_id && p.key_id == key_id)
      {
        /*Key is present. Remove old key first*/
        _idx = idx;      
      }
#ifdef BRA_CFG_DUAL_SIM
      else if (BRA_PROF_GET_SIM_IDX(BRA_SIM_ID_SIM2, _prof_id) == p.profile_id && 
               p.key_id == key_id)
      {
        _bra_sim2_idx = idx;      
      }
#endif /* BRA_CFG_DUAL_SIM */
    }
  }
}

int
bra_prof_off_line_save_profile_key (int prof_id, char *key, char *value)
{
  int  sim_id = 0;
  int  id = BRA_PROF_ID_BRA;


#ifdef BRA_CFG_DUAL_SIM
  sim_id = BRA_SIM_ID_DEFAULT;
#endif

  if (prof_id >= BRA_CFG_N_WAP_PROFILES)
      id = BRA_PROF_ID_MMS;
  return bra_prof_off_line_save_sim_profile_key(id, sim_id, prof_id, key, value);
}

int
bra_prof_off_line_save_sim_profile_key (int id, int sim_id, int prof_id, char *key, char *value)
{
  unsigned char     *p;
  int               size;
  int               key_id;
  int               sel_idx;
  int               sel_sim_id;
  void              *file_handle;
  

  if (id != BRA_PROF_ID_BRA && id != BRA_PROF_ID_MMS)
      return 0;

#ifdef BRA_CFG_DUAL_SIM
  if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2 && sim_id != BRA_SIM_ID_DEFAULT)
      return 0;
#endif
  
  if (prof_id < 0 || prof_id >= BRA_CFG_N_PROFILES)
      return 0;

  if (key == NULL || value == NULL)
      return 0;

  MSF_MEM_INIT (MSF_MODID_BRA, NULL);

  key_id = bra_prof_key_to_int (key);

  if (key_id < 0) 
    return 0;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, 
      BRA_PROF_OFF_LINE_SAVE_SIM_PROFILE_KEY,
      "BRA: bra_prof_off_line_save_sim_profile_key(): sim_id=%d, prof_id=%d, key_id=%d\n",
      sim_id, prof_id, key_id));

  /*Check if value exist in profile*/

  _save_key = key;
  _idx = -1;
  _prof_id = prof_id;

#ifdef BRA_CFG_DUAL_SIM
  _bra_sim_id = BRA_SIM_ID_SIM1;
  _bra_sim_is_ask = 0;
  _bra_sim2_idx = -1;
#endif

  bra_file_init (BRA_CFG_PROFILE_FILE_PATH, 
                 &file_handle, 
                 BRA_PROF_MAX_FILE_SIZE, 
                 BRA_PROF_INITIAL_SIZE, 
                 BRA_PROF_DEFRAG_LIMIT, 
                 BRA_PROF_SIZE_INCREMENT,
                 bra_prof_check_file_response);

  sel_idx = _idx;
  sel_sim_id = sim_id;

#ifdef BRA_CFG_DUAL_SIM
  {
    int sim_info;
    
    
    if (sim_id == BRA_SIM_ID_DEFAULT) //get current SIM in active use
    {
      sim_info = bra_sim_get_sim_card_number();
      if (sim_info == BRA_SIM_ID_DUAL_SIM)
      {
        if( _bra_sim_is_ask != 0)
          sel_sim_id = BRA_SIM_ID_SIM1;
        else
          sel_sim_id = _bra_sim_id;
      }
      else if (sim_info == BRA_SIM_ID_SIM1 || sim_info == BRA_SIM_ID_SIM2)
      {
        sel_sim_id = sim_info;
      }
      else
      {
        sel_sim_id = BRA_SIM_ID_SIM1;
      }
    }
    if (sel_sim_id == BRA_SIM_ID_SIM2)
      sel_idx = _bra_sim2_idx;
  }
#endif /* BRA_CFG_DUAL_SIM */ 

  if(sel_idx >= 0)
    bra_file_delete_block(file_handle, sel_idx, NULL);
  size = strlen (value) + 1;
  p = bra_prof_create_block(id, sel_sim_id, prof_id, key_id, (unsigned char*)value, &size);
  bra_file_write_block (file_handle, p, size, NULL);
  BRA_FREE (p);

  MSF_MEM_FREE_ALL(MSF_MODID_BRA);

  return 1;
}

MSF_UINT8
bra_prof_offline_get_prof_list(bra_prof_list_t  **prof_list_ptr)
{
  return bra_prof_offline_get_sim_prof_list(BRA_PROF_ID_BRA, 
      bra_prof_get_profile_sim_id(), prof_list_ptr);
}

MSF_UINT8
bra_prof_offline_get_sim_prof_list (int id, int sim_id, bra_prof_list_t **prof_list_ptr)
{
  int               i;
  bra_prof_list_t  *prof_list;

  
  /* check if profile is loaded complete */
  if(!bra_prof_profile.profile_is_loaded)
    return WAP_PROF_NOT_READY;
  
  if (id != BRA_PROF_ID_BRA && id != BRA_PROF_ID_MMS)
    return WAP_PROF_INVALID_ID;
  
#ifdef BRA_CFG_DUAL_SIM
  if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2 && sim_id != BRA_SIM_ID_DEFAULT)
    return WAP_PROF_INVALID_ID;
  
  if (sim_id == BRA_SIM_ID_DEFAULT)
  {
    if (id == BRA_PROF_ID_BRA)
      sim_id = bra_sim_get_bra_sim_id_in_active_use();
    else
    {
      sim_id = bra_sim_get_sim_card_number();
      if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2)
        sim_id = BRA_SIM_ID_SIM1;
    }
  }
#endif /* BRA_CFG_DUAL_SIM */

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, 
      BRA_PROF_OFFLINE_GET_SIM_PROF_LIST,
      "BRA: bra_prof_offline_get_sim_prof_list(): id=%d, sim_id=%d%d\n", id, sim_id));

  *prof_list_ptr = BRA_ALLOC(sizeof(bra_prof_list_t) + sizeof(bra_prof_list_entry_t) * (BRA_CFG_N_WAP_PROFILES-1));
  prof_list = *prof_list_ptr;
  prof_list->n_items =  BRA_PROF_GET_PROF_NUM(id);

  for (i = 0; i < prof_list->n_items; i++)
  {
    int               idx;


    idx = BRA_PROF_GET_SIM_IDX(sim_id, BRA_PROF_GET_PROF_IDX(id, i));
    prof_list->prof[i].prof_name = bra_prof_get_profile_name(i, 
        (const char*)bra_prof_profile.available_profiles[idx].profile_name);

    prof_list->prof[i].con_type = bra_prof_profile.available_profiles[idx].con_type;
  }
  return WAP_PROF_SUCCESS;
}





static void 
bra_prof_offline_load_block_response (void *handle, unsigned char* block, int size)
{ 
  int id;
  int profile_id;
  int key_id;
   
  if (size < BRA_PROF_BLOCK_HEADER_SIZE)
    return;

  id = (int)block[0];
  profile_id = (int)block[1];
  key_id = (int)block[2];

  if (id == BRA_PROF_ID_BRA)
  {
    if (bra_prof_key_table[key_id].type == 0) /*0 = int*/
      offline_profile->items[key_id].i_value = atoi((const char*)(&block[5]));
    else
    {
      if(key_id == BRA_PROF_ENUM_PROF_STR || key_id == BRA_PROF_ENUM_PRX_PWD|| 
          key_id == BRA_PROF_ENUM_PRX_UID || key_id == BRA_PROF_ENUM_PRX_ADDR)
      {
        offline_profile->items[key_id].s_value = msf_cmmn_strdup(MSF_MODID_BRA, 
            (const char*)(&block[5]));                  
      }
    }
  }
   
  BRA_FREE (block);
}


MSF_UINT8 
bra_prof_off_line_load_bra_active_profile(bra_prof_content_t  **prof_cont_ptr)
{
  int   sim_id;
  int   prof_id;
  
  
  bra_prof_get_bra_profile_id_in_active_use(&sim_id, &prof_id);
  return bra_prof_off_line_load_sim_profile(BRA_PROF_ID_BRA, 
      bra_prof_get_profile_sim_id(), prof_id, prof_cont_ptr);
}


MSF_UINT8
bra_prof_off_line_load_profile (int prof_id, bra_prof_content_t **prof_cont_ptr)
{
  return bra_prof_off_line_load_sim_profile(BRA_PROF_ID_BRA, bra_prof_get_profile_sim_id(), prof_id, prof_cont_ptr);
}

MSF_UINT8
bra_prof_off_line_load_sim_profile (int id, int sim_id, int prof_id, bra_prof_content_t **prof_cont_ptr)
{
  int                   i;
  int                   key_id;
  int                   temp_prof_id;
  bra_prof_content_t    *prof_cont;


  /* check if profile is loaded complete */
  if(!bra_prof_profile.profile_is_loaded)
    return WAP_PROF_NOT_READY;
  
  if (id != BRA_PROF_ID_BRA && id != BRA_PROF_ID_MMS)
    return WAP_PROF_INVALID_ID;
  
#ifdef BRA_CFG_DUAL_SIM
  if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2 && sim_id != BRA_SIM_ID_DEFAULT)
    return WAP_PROF_INVALID_ID;
  
  if (sim_id == BRA_SIM_ID_DEFAULT)
  {
    if (id == BRA_PROF_ID_BRA)
      sim_id = bra_sim_get_bra_sim_id_in_active_use();
    else
    {
      sim_id = bra_sim_get_sim_card_number();
      if (sim_id != BRA_SIM_ID_SIM1 && sim_id != BRA_SIM_ID_SIM2)
        sim_id = BRA_SIM_ID_SIM1;
    }
  }
#endif /* BRA_CFG_DUAL_SIM */
  
  /* check if the profile id parameter is valid */
  if(prof_id < 0 || prof_id >= BRA_CFG_N_PROFILES)
    return WAP_PROF_INVALID_ID;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, 
      BRA_PROF_OFF_LINE_LOAD_SIM_PROFILE,
      "BRA: bra_prof_off_line_load_sim_profile(): id=%d, sim_id=%d, prof_id=%d\n",
      id, sim_id, prof_id));


  *prof_cont_ptr = BRA_ALLOC(sizeof(bra_prof_content_t));
  prof_cont = *prof_cont_ptr;
  
  offline_profile = BRA_ALLOC (sizeof (bra_prof_profile_t) + (sizeof (bra_prof_item_t)*(BRA_PROF_N_PROFILE_KEYS - 1)));

  offline_profile->n_items = BRA_PROF_N_PROFILE_KEYS;

  for (i = 0; i < BRA_PROF_N_PROFILE_KEYS; i++)
  {
    if (bra_prof_key_table[i].type == 0) /*0 = int*/
      offline_profile->items[i].i_value = 0;
    else
      offline_profile->items[i].s_value = NULL;
  }
  bra_prof_initialize_profile(offline_profile);
  
  temp_prof_id = bra_prof_profile.profile_id;
  bra_prof_profile.profile_id =  BRA_PROF_GET_SIM_IDX(sim_id, prof_id);
  for (i = 0; i < BRA_PROF_N_PROFILE_KEYS; i++)
    bra_prof_read_profile_key(BRA_PROF_ID_BRA, bra_prof_key_table[i].key, bra_prof_offline_load_block_response);
  bra_prof_profile.profile_id = temp_prof_id;

  prof_cont->id = prof_id;

  key_id = BRA_PROF_ENUM_CON_TYPE;
  prof_cont->con_type = offline_profile->items[key_id].i_value; 
  
  key_id = BRA_PROF_ENUM_NET_ID;
  prof_cont->net_id = bra_prof_filter_int_key_to_generate_ext_net_id(BRA_PROF_ID_BRA, 
      BRA_PROF_KEY_NET_ID, offline_profile->items[key_id].i_value);
  prof_cont->net_id2 = 0xFF;


#ifdef BRA_CFG_PROF_FALLBACK
  key_id = BRA_PROF_ENUM_NET_ID_IS_DUAL;
  if (offline_profile->items[key_id].i_value == 1)
  {
    key_id = BRA_PROF_ENUM_NET_ID_GPRS;
    prof_cont->net_id = bra_prof_filter_int_key_to_generate_ext_net_id(BRA_PROF_ID_BRA, 
        BRA_PROF_KEY_NET_ID_GPRS, offline_profile->items[key_id].i_value);

    key_id = BRA_PROF_ENUM_NET_ID_GSM;
    prof_cont->net_id2 = bra_prof_filter_int_key_to_generate_ext_net_id(BRA_PROF_ID_BRA, 
        BRA_PROF_KEY_NET_ID_GSM, offline_profile->items[key_id].i_value);
  }
#endif /* BRA_CFG_PROF_FALLBACK */

  key_id = BRA_PROF_ENUM_PROF_STR;
  prof_cont->prof_name = offline_profile->items[key_id].s_value;
  key_id = BRA_PROF_ENUM_PRX_PWD;
  prof_cont->password = offline_profile->items[key_id].s_value;
  key_id = BRA_PROF_ENUM_PRX_UID;
  prof_cont->username = offline_profile->items[key_id].s_value;
  key_id = BRA_PROF_ENUM_PRX_PORT;
  prof_cont->prx_port = offline_profile->items[key_id].i_value;
  key_id = BRA_PROF_ENUM_PRX_ADDR;
  memset(prof_cont->prx_ip, 0, 4);
  bra_cmn_get_address((const char*)offline_profile->items[key_id].s_value, (unsigned char*)prof_cont->prx_ip);

  BRA_FREE(offline_profile->items[key_id].s_value);
  BRA_FREE(offline_profile);
  return WAP_PROF_SUCCESS;
} 


/*------------------------------End of off line profile operation--------------------------*/


#ifdef BRA_CONFIG_MMS
MSF_BOOL 
bra_prof_commit_mmsc(int sim_id, char *str)
{
    char *tmpScheme, *newScheme = NULL;
    char *tmpHost;
    char *tmpPath;
    char *tmpPort;
    void *reg_handle;

    if (!msf_url_is_valid(str))
    {
        return FALSE;
    }

    tmpPort = msf_url_get_port(MSF_MODID_BRA, str);    
    tmpScheme = msf_url_get_scheme(MSF_MODID_BRA, str);
    tmpHost = msf_url_get_host(MSF_MODID_BRA, str);
    tmpPath = (char *)msf_url_find_path((const char *)str);
    if (NULL != tmpScheme)
    {
        newScheme = BRA_ALLOC(strlen(tmpScheme) + 1 + 3);
        sprintf(newScheme, "%s://", tmpScheme);
        BRA_FREE(tmpScheme);
    }

    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
    MSF_REGISTRY_SET_PATH (reg_handle, (char *)MMS_REG_PATH_COM_MMSC);

#ifdef BRA_CFG_DUAL_SIM_FOR_MMS
  if (sim_id == BRA_SIM_ID_SIM2)
  {
      MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, 
          (char *)MMS_REG_KEY_SLAVE_SIM_PORT, 
          tmpPort != NULL ? atoi(tmpPort) : 0);
      
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
          (char *)MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY_SCHEME,
          (unsigned char*)BRA_CMN_HNV(newScheme), 
          (MSF_UINT16)(strlen (BRA_CMN_HNV (newScheme))+1));
      
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
          (char *)MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY,
          (unsigned char*)BRA_CMN_HNV(tmpHost), 
          (MSF_UINT16)(strlen (BRA_CMN_HNV (tmpHost))+1));
      
      MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
          (char *)MMS_REG_KEY_SLAVE_SIM_POST_URI,
          (unsigned char*)BRA_CMN_HNV(tmpPath), 
          (MSF_UINT16)(strlen(BRA_CMN_HNV (tmpPath))+1));
      MSF_REGISTRY_SET_COMMIT (reg_handle);
      
      if(tmpPort)
          BRA_FREE(tmpPort);
      if(newScheme)
          BRA_FREE(newScheme);
      if(tmpHost)
          BRA_FREE(tmpHost);
      return TRUE;
  }
#endif /* BRA_CFG_DUAL_SIM_FOR_MMS */
 
  MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, 
                                (char *)MMS_REG_KEY_PORT, 
                                tmpPort != NULL ? atoi(tmpPort) : 0);

  MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                (char *)MMS_REG_KEY_PROXY_RELAY_SCHEME,
                                (unsigned char*)BRA_CMN_HNV(newScheme), 
                                (MSF_UINT16)(strlen (BRA_CMN_HNV (newScheme))+1));
  
  MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                (char *)MMS_REG_KEY_PROXY_RELAY,
                                (unsigned char*)BRA_CMN_HNV(tmpHost), 
                                (MSF_UINT16)(strlen (BRA_CMN_HNV (tmpHost))+1));

  MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                (char *)MMS_REG_KEY_POST_URI,
                                (unsigned char*)BRA_CMN_HNV(tmpPath), 
                                (MSF_UINT16)(strlen(BRA_CMN_HNV (tmpPath))+1));

  MSF_REGISTRY_SET_COMMIT (reg_handle);

  if(tmpPort)
    BRA_FREE(tmpPort);
  if(newScheme)
     BRA_FREE(newScheme);
  if(tmpHost)
    BRA_FREE(tmpHost);
  return TRUE;
}
#endif

const char*
bra_prof_get_cur_user_agent (void)
{
  if(global_wap_user_agent == 0)
    return (const char*)BRA_CFG_PROF_DEFAULT_UA_HEADER;
  else    
    return bra_prof_user_agent[global_wap_user_agent][BRA_PROF_UA_TABLE_NAME_INDEX];
}


const char*
bra_cfg_default_accept_header (void)
{
  return bra_prof_accept_header[global_wap_accept_header];
}


const char*
bra_cfg_supported_image_mime (void)
{
  return BRA_CFG_SUPPORTED_IMAGE_MIME;
}

const char*
bra_cfg_default_accept_language_header (void)
{
  return BRA_CFG_ACCEPT_LANGUAGE_HEADER;
}


const char*
bra_cfg_default_charset_header (void)
{
  return (BRA_CFG_ACCEPT_CHARSET);
}

const char*
bra_cfg_brs_default_css (void)
{
  return BRA_CFG_BRS_CSS_DEFAULT_STYLE_SHEET;
}

unsigned int bra_cfg_brs_clear_history_on_newcontext(void)
{
  return (unsigned int) BRA_CFG_BRS_CLEAR_HISTORY_ON_NEWCONTEXT;
}

unsigned int bra_cfg_brs_redirect_handling(void)
{
  return (unsigned int) BRA_CFG_BRS_REDIRECT_HANDLING;
}

#ifdef MTK_TMP_PATCH /* CR34945 */
unsigned int bra_cfg_brs_ignore_emptyok(void)
{
  return (unsigned int) BRA_CFG_BRS_IGNORE_EMPTYOK;
}
#endif /* MTK_TMP_PATCH */






static void
bra_prof_init_bra_prof_profile(void)
{
#ifdef BRA_CFG_DUAL_SIM
  bra_prof_profile.sim_id = BRA_SIM_ID_SIM1;
#endif
  bra_prof_profile.id = BRA_PROF_ID_BRA;
  bra_prof_profile.profile_id = 0;
  bra_prof_profile.profile_is_loaded = 0;
  bra_prof_profile.callback = NULL;
  bra_prof_profile.file_handle = NULL;
  bra_prof_profile.profile = NULL;
  bra_prof_profile.available_profiles = bra_prof_alloc_available_profile();
  bra_prof_init_profile_cmn_part(&bra_prof_profile);
}


static void
bra_prof_init_profile_cmn_part(bra_profiles_t *profile)
{
  int     i;
  
  
  if (profile == NULL)
    return;
  for (i = 0; i < BRA_PROF_N_CMN_KEYS; i++)
  {
    if (bra_prof_cmn_key_table[i].type == 0) /*0 = int*/
      (profile->cmn_items[i]).i_value = 0;
    else
      (profile->cmn_items[i]).s_value = NULL;
    profile->cmn_index_list[i] = -1;
  }
}


static bra_prof_available_profiles_t*
bra_prof_alloc_available_profile(void)
{
  int     i;
  bra_prof_available_profiles_t  *available_profiles;
  
  
  available_profiles = BRA_ALLOC(sizeof(bra_prof_available_profiles_t) * BRA_CFG_N_ALL_SIM_PROFILES);    
  for (i = 0; i < BRA_CFG_N_ALL_SIM_PROFILES; i++)
  {
    available_profiles[i].profile_name = NULL;
    available_profiles[i].con_type = 0;
    memset (available_profiles[i].index_list, -1, 
      BRA_PROF_SAVE_KEY_NUM * sizeof(MSF_INT16));
  }
  return available_profiles;
}


static void
bra_prof_free_available_profiles(bra_prof_available_profiles_t *available_profiles)
{
  int     i;
  
  
  if (available_profiles == NULL)
    return;
  for (i = 0; i < BRA_CFG_N_ALL_SIM_PROFILES; i++)
  {
    BRA_FREE(available_profiles[i].profile_name);
    available_profiles[i].profile_name = NULL;
    available_profiles[i].con_type = 0;
  }
  BRA_FREE(available_profiles);
}


static int
bra_prof_filter_int_key_to_get_raw_net_id(int id, char *key, int value)
{
  int    key_id;
  int    raw_net_id = value;
  
  
  key_id = bra_prof_key_to_int(key);
  
  if (key_id == BRA_PROF_ENUM_NET_ID)
    raw_net_id = (int)always_ask_get_original_id_data_account((kal_uint32)value);
  
#ifdef BRA_CFG_PROF_FALLBACK
  if (key_id == BRA_PROF_ENUM_NET_ID_GPRS || key_id == BRA_PROF_ENUM_NET_ID_GSM)
    raw_net_id = (int)always_ask_get_original_id_data_account((kal_uint32)value);
#endif /* BRA_CFG_PROF_FALLBACK */
  
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_PROF_FILTER_INT_KEY_TO_GET_RAW_NET_ID, 
    "BRA: bra_prof_filter_int_key_to_get_raw_net_id(): id=%d, index=%d, value=%x, raw_value=%d",
    id, key_id, value, raw_net_id));
  
  return raw_net_id;
}


static int
bra_prof_filter_int_key_to_generate_ext_net_id(int id, char *key, int value)
{
  int    key_id;
  int    app_id;
  int    is_ask = 0;
  int    cbm_sim_id;
  int    ext_net_id = value;
  
  
  key_id = bra_prof_key_to_int(key);
  
  if (key_id != BRA_PROF_ENUM_NET_ID
#ifdef BRA_CFG_PROF_FALLBACK
    && key_id != BRA_PROF_SAVE_NET_ID_GPRS && key_id != BRA_PROF_SAVE_NET_ID_GSM
#endif
    )
    return value;  
  
  
  cbm_sim_id = bra_cbm_get_cbm_sim_id(bra_prof_get_profile_sim_id());
  app_id = bra_cbm_get_app_id(id);
  
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  is_ask = bra_prof_get_key_int_value(id, BRA_PROF_KEY_NET_ID_IS_ASK);
#endif
  
  if (key_id == BRA_PROF_ENUM_NET_ID)
  {
#ifdef BRA_CFG_CONN_ALWAYS_ASK
    if (bra_prof_loaded_profile_is_bra_profile_in_active_use() && 
      bra_cbm_is_bra_asked_ext_net_id_valid()) 
      is_ask = FALSE;
#endif /* BRA_CFG_CONN_ALWAYS_ASK */ 
    
    ext_net_id = (int)always_ask_encode_data_account_id((kal_uint32)value,
      (always_ask_sim_info_enum)cbm_sim_id, (kal_uint8)app_id, (kal_bool)is_ask);
/*    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
      BRA_PROF_FILTER_INT_KEY_TO_GENERATE_EXT_NET_ID, 
      "BRA: bra_prof_filter_int_key_to_generate_ext_net_id(): id=%d, index=%d, value=%d, ext_net_id=%x",
      id, key_id, value, ext_net_id));
*/    
    return ext_net_id;
  }
  
#ifdef BRA_CFG_PROF_FALLBACK
  if (key_id != BRA_PROF_ENUM_NET_ID_GSM || key_id != BRA_PROF_ENUM_NET_ID_GPRS)
  {
    ext_net_id = (int)always_ask_encode_data_account_id((kal_uint32)value,
      (always_ask_sim_info_enum)cbm_sim_id, (kal_uint8)app_id, (kal_bool)FALSE);
    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
      BRA_PROF_FILTER_INT_KEY_TO_GENERATE_EXT_NET_ID, 
      "BRA: bra_prof_filter_int_key_to_generate_ext_net_id(): id=%d, index=%d, value=%d, ext_net_id=%x",
      id, key_id, value, ext_net_id));
    
    return ext_net_id;
  }
#endif /* BRA_CFG_PROF_FALLBACK */
  
  return value;
}


int
bra_prof_get_sim_activated_profile_id(int id, int sim_id)
{
  int     prof_id;
  
  
#ifdef BRA_CFG_DUAL_SIM
  if (sim_id == BRA_SIM_ID_SIM2)
  {
    if (id == BRA_PROF_ID_BRA)
      prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID_SLAVE);
    else
      prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID_SLAVE);
    return prof_id;
  }
#endif /* BRA_CFG_DUAL_SIM */
  
  BRA_UNUSED(sim_id);
  if (id == BRA_PROF_ID_BRA)
    prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID);
  else
    prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  return prof_id;
}


int
bra_prof_get_sim_profile_id_in_active_use(int id, int mms_sim_id)
{
  int     prof_id;
  int     sim_id = mms_sim_id;
  
  
#ifdef BRA_CFG_DUAL_SIM  
  if (id == BRA_PROF_ID_BRA)
  {
    sim_id = bra_sim_get_bra_sim_id_in_active_use();
  }
#endif /* BRA_CFG_DUAL_SIM */
  
  prof_id = bra_prof_get_sim_activated_profile_id(id, sim_id);
  
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_PROF_GET_SIM_PROFILE_ID_IN_ACTIVE_USE, 
    "BRA: bra_prof_get_sim_profile_id_in_active_use(): id=%d, sim_id=%d, prof_id=%d",
    id, sim_id, prof_id));
  
  return prof_id;
}


int 
bra_prof_get_bra_profile_id_in_active_use(int *sim_id, int *prof_id)
{
  if (sim_id == NULL || prof_id == NULL)
    return 0;
  
  *sim_id = 0;
#ifdef BRA_CFG_DUAL_SIM  
  *sim_id = bra_sim_get_bra_sim_id_in_active_use();
#endif
  *prof_id = bra_prof_get_sim_activated_profile_id(BRA_PROF_ID_BRA, *sim_id);
  return 1;
}


void
bra_prof_restore_bra_active_profile(int is_commit)
{
  int  sim_id;
  int  prof_id;

  
  bra_prof_get_bra_profile_id_in_active_use(&sim_id, &prof_id);
  bra_prof_set_sim_selected_profile(BRA_PROF_ID_BRA, sim_id, prof_id, NULL);
  if (is_commit)
  {
      bra_prof_commit_profile();
  }
 
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_PROF_RESTORE_BRA_ACTIVE_PROFILE, 
    "BRA: bra_prof_restore_bra_active_profile(): sim_id=%d, prof_id=%d",
    sim_id, prof_id));
}


static int
bra_prof_loaded_profile_is_bra_profile_in_active_use(void)
{
  return bra_prof_is_bra_profile_in_active_use(bra_prof_get_profile_id(),
    bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile());
}


#ifdef BRA_CONFIG_MMS
static int
bra_prof_loaded_profile_is_mms_profile_in_active_use(void)
{
  return bra_prof_is_mms_profile_in_active_use(bra_prof_get_profile_id(),
    bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile());
}
#endif /* BRA_CONFIG_MMS */

int
bra_prof_is_bra_profile_in_active_use(int id, int sim_id, int prof_id)
{
/*
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_PROF_IS_BRA_PROFILE_IN_ACTIVE_USE, 
    "BRA: bra_prof_is_bra_profile_in_active_use(): id=%d, sim_id=%d, prof_id=%d",
    id, sim_id, prof_id));
*/

#ifdef BRA_CFG_DUAL_SIM
  
  if (id != BRA_PROF_ID_BRA)
    return FALSE;
  if (sim_id != bra_sim_get_bra_sim_id_in_active_use())
    return FALSE;
  return prof_id == bra_prof_get_sim_activated_profile_id(id, sim_id);
  
#else /* BRA_CFG_DUAL_SIM */
  
  BRA_UNUSED (id);
  BRA_UNUSED(sim_id);
  return prof_id == bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID);
  
#endif /* BRA_CFG_DUAL_SIM */
}


int
bra_prof_is_mms_profile_in_active_use(int id, int sim_id, int prof_id)
{
/*
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_PROF_IS_MMS_PROFILE_IN_ACTIVE_USE, 
    "BRA: bra_prof_is_mms_profile_in_active_use(): id=%d, sim_id=%d, prof_id=%d",
    id, sim_id, prof_id));
*/
  
#ifdef BRA_CFG_DUAL_SIM
  
  if (id != BRA_PROF_ID_MMS)
    return FALSE;

#ifndef BRA_CFG_DUAL_SIM_FOR_MMS
  if (sim_id == BRA_SIM_ID_SIM2)
    return FALSE;
#endif

  if (sim_id == BRA_SIM_ID_SIM2)
    return prof_id == bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID_SLAVE);
  else 
    return prof_id == bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  
#else /* BRA_CFG_DUAL_SIM */
  
  BRA_UNUSED(id);    
  BRA_UNUSED(sim_id);
  return prof_id == bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
  
#endif /* BRA_CFG_DUAL_SIM */
}









/*============================Unit Test===================================================*/

#ifdef BRA_CFG_UNIT_TEST_FOR_DUAL_SIM

void
bra_prof_offline_test(void)
{
    int             id = BRA_PROF_ID_BRA;
    int             prof_id = 10;
    int             sim_id  = BRA_SIM_ID_SIM2;
    bra_prof_content_t  *content = NULL;
    char            key[100];
    char            value[256];
    bra_prof_list_t  *list = NULL;
    int             buf_len = 256;


    bra_prof_off_line_load_bra_active_profile(&content);
    BRA_FREE(content);
    content = NULL;

    bra_prof_off_line_load_profile(2, &content);

    BRA_FREE(content);
    content = NULL;

    bra_prof_off_line_load_sim_profile(id, sim_id, prof_id,&content);

    BRA_FREE(content);
    content = NULL;

    strcpy(key, BRA_PROF_KEY_NET_ID);
    bra_prof_off_line_read_profile_key(prof_id, key, value);


    strcpy(key, BRA_PROF_KEY_HOMEPAGE_URL);
    bra_prof_off_line_read_sim_profile_key(id, sim_id, prof_id, key, value, &buf_len);


    strcpy(key, BRA_PROF_KEY_HOMEPAGE_URL);
    strcpy(value, "http://wap.sohu.com");
    bra_prof_off_line_save_profile_key(prof_id, key, value);

    strcpy(key, BRA_PROF_KEY_HOMEPAGE_URL);
    strcpy(value, "http://wap.sohu.com");
    bra_prof_off_line_save_sim_profile_key(id, sim_id, prof_id, key, value);


    bra_prof_offline_get_prof_list(&list);
    BRA_FREE(list);
    list = NULL;
    bra_prof_offline_get_sim_prof_list(id, sim_id,&list);
    BRA_FREE(list);
    list = NULL;
}


void
bra_sat_test(void)
{
    #include "bra_if.h"
    
    bra_sat_lauch_request_t  *lauch_p;
    
    lauch_p = BRA_ALLOCTYPE(bra_sat_lauch_request_t);
    lauch_p->browserMode = 0;
    lauch_p->browserIdentity = 0;
    lauch_p->noBearer = 0;
    lauch_p->bearer = NULL;
    lauch_p->sim_id = BRA_SIM_ID_DEFAULT;
    lauch_p->noUrl = strlen("http://wap.sohu.com/") + 1;
    lauch_p->url = BRA_ALLOC(lauch_p->noUrl);
    strcpy(lauch_p->url, "http://wap.sohu.com/");
    
    lauch_p->noGateway = 0;
    lauch_p->gateway = NULL; 
    bra_sat_lauch_request(lauch_p);
}



#endif /* BRA_CFG_UNIT_TEST_FOR_DUAL_SIM */






