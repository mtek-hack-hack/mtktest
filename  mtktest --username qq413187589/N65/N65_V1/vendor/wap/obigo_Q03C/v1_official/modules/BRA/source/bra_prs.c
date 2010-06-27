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
 * bra_prs.c
 *
 * Created by Tomas Mandorf	20021120	15:42
 *
 * 
 * Description:
 *		This file contains code to handle provisioning data.
 *
 */

#include "bra_cfg.h"

#ifdef BRA_CONFIG_PROVISIONING
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#include "msf_chrs.h"
#include "msf_url.h"

#include "bra_prof.h"
#include "bra_sig.h"
#include "bra_prs.h"
#include "bra_main.h"
#include "bra_cmn.h"
#include "bra_dlg.h"
#include "bra_bkm.h"
#include "bra_view.h"
#include "bra_if.h"
#include "bra_req.h" 

#include "bra_cbm.h"

#include "prs_if.h"
#include "bra_set.h"

#include "prs_def.h"
#include "prs_cnst.h"

#ifdef __TCPIP__
#include "kal_release.h"      	/* Basic data type */

#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "custom_config.h"

#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */

#include "event_shed.h"       	/* Event scheduler */

#include "stack_timer.h"      	/* Stack timer */

#include "app_buff_alloc.h"

#include "nvram_data_items.h"

#include "l3_inc_enums.h"
#include "l4a.h"
#include "custom_data_account.h"
#include "custom_mmi_default_value.h"

#endif /*__TCPIP__ */

#include "widget_extension.h"

#ifdef WAP_SUPPORT
void bra_prs_show_prov_dialog(void);
void bra_prs_install_prov(void);
#endif
/* added by Kevin ---- end */


extern void TurnOnBacklight(kal_uint8 TimerFlag);

/******************************************************************************
 * Types
 *****************************************************************************/

typedef struct
{
  char *prs_key;
  char *bra_key;
}bra_prs_key_mapping_t;

/*Table of supported provisioning keys*/
static const bra_prs_key_mapping_t bra_prs_key_mapping_table[] = 
{
  {"profile_name"   , BRA_PROF_KEY_PROF_STR},
  {"px_name"        , BRA_PROF_KEY_PRX_NAME},
  {"px_address"     , BRA_PROF_KEY_PRX_ADDR},
  {"px_port"        , BRA_PROF_KEY_PRX_PORT},
  {"px_service"     , BRA_PROF_KEY_CON_TYPE},
  //{"px_type"        , BRA_PROF_KEY_CON_TYPE},
  {"px_auth_name"   , BRA_PROF_KEY_PRX_UID},
  {"px_auth_secret" , BRA_PROF_KEY_PRX_PWD},
  {0                , 0}
};

/* Select Profile menu */
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle select;
  MsfActionHandle back;
} bra_prs_profile_select_menu_t;

typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_prs_set_menu_t;

typedef struct
{
  int n_items;
  MSF_INT32 net_ids[BRA_CFG_ONE_BEARER_MAX_NET_ID_NUM];
}bra_prs_set_net_id_t;

#ifdef __TCPIP__

typedef struct {
   LOCAL_PARA_HDR
} ps_dummy_local_para_header_struct;

typedef enum
{
   BRA_PRS_NULL=0,
   BRA_PRS_WAIT_FREE_ID_RSP,
   BRA_PRS_WAIT_SEND_SET_REQ,
   BRA_PRS_WAIT_SET_RSP
} bra_prs_state_enum;

typedef enum
{
   BRA_PRS_GSM_BEARER,
   BRA_PRS_GPRS_BEARER,
#ifdef BRA_CFG_PROV_MULTI_BEARER
   BRA_PRS_MULTI_BEARER,
#endif
   BRA_PRS_INVALID_BEARER
} bra_prs_bearer_enum;

typedef enum
{
   BRA_PRS_WAP_SETTING,
   BRA_PRS_MMS_SETTING,
   BRA_PRS_BOOKMARK_SETTING,
   BRA_PRS_INVALID_SETTING
} bra_prs_setting_type_enum;

static int bra_prs_bearer = BRA_PRS_INVALID_BEARER;
static int bra_prs_setting_type = BRA_PRS_WAP_SETTING;

#ifndef BRA_CFG_PROV_MULTI_BEARER
static int data_acct_id;
#endif

#ifdef __CS_SERVICE__

static bra_prs_state_enum bra_prs_gsm_state = BRA_PRS_NULL;
static mmi_cc_set_csd_profile_req_struct *set_csd_req = NULL;
#endif /* __CS_SERVICE__ */

#ifdef __PS_SERVICE__
static bra_prs_state_enum bra_prs_gprs_state = BRA_PRS_NULL;
static mmi_ps_set_gprs_data_account_req_struct *set_gprs_req = NULL;
#endif /* __PS_SERVICE__ */

#endif /* __TCPIP__ */

/******************************************************************************
 * Defines
 *****************************************************************************/
#define BRA_PRS_MAX_NBR_DOCUMENTS  5

#ifdef BRA_CFG_PROV_MULTI_BEARER
#define BRA_PRS_MAX_NBR_BEARERS    2
#endif

/******************************************************************************
 * Variables
 *****************************************************************************/

static int bra_prs_handled_items_cnt;
static bra_prs_set_net_id_t *bra_prs_set_net_ids;

static void* bra_prs_data_queue[BRA_PRS_MAX_NBR_DOCUMENTS];
static int   bra_prs_data_queue_last_item;
static int   bra_prs_data_queue_current_item;
static int   bra_prs_data_queue_size;

static bra_prs_pinned_prov_t bra_prs_pinned_prov;
static int   bra_prs_num_bearers;
static int   bra_prs_num_proxies;

#ifdef BRA_CFG_CANCEL_PROV_CONF
static int bra_prs_current_window_type;  /* 1:dialog, 2:prof selection, 3:from PRS' PIN input */
#endif

#ifdef BRA_CFG_PROV_MULTI_BEARER
static int bra_prs_bearers_list[BRA_PRS_MAX_NBR_BEARERS];
static int bra_prs_crt_netid_menu_type;
static int data_acct_id[BRA_PRS_MAX_NBR_BEARERS];
#endif

#ifdef BRA_CFG_DUAL_SIM
static int bra_prs_sim_id = 0;
#endif


/******************************************************************************
 * Function Prototypes
 *****************************************************************************/
static void 
bra_prs_instal_dialog (void);

static void 
bra_prs_create_prof_sel_menu (void);

static void 
bra_prs_delete_and_continue (void);

static void
bra_prs_instal_profile_done (void);/* kevin */

void
bra_prs_handle_destroy_ui(void);

static void 
bra_prs_create_net_id_menu (void);

#ifdef BRA_CFG_CANCEL_PROV_CONF
static void
bra_prs_cancel_prov_response(MsfActionType response);
#endif

extern void
HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

static int
bra_prs_parse_sim_id(void *data);

static int
bra_prs_get_parsed_sim_id(void);

static void
bra_prs_set_parsed_sim_id(int bra_sim_id);

static int
bra_prs_get_widget_sim_id(int bra_sim_id);


/******************************************************************************
 * Local Functions
 *****************************************************************************/

static void
bra_prs_increase_items_cnt (void)
{
  bra_prs_handled_items_cnt++;
}

static void
bra_prs_decrease_items_cnt (void)
{
#ifndef __PRODUCTION_RELEASE__
   ASSERT(bra_prs_handled_items_cnt > 0);
#endif

   if(bra_prs_handled_items_cnt > 0) 
      bra_prs_handled_items_cnt--;
}

static const char*
bra_prs_cvt_key (char* prs_key)
{
  char *s;
  char *p;
  int   i = 0;

  while ((s = bra_prs_key_mapping_table[i].prs_key) != NULL)
  {
    p = prs_key;
    while ((*p == *s))
    {
      if (*p == '\0')
        return bra_prs_key_mapping_table[i].bra_key;
      p++;s++;
    }
    i++;
  }
  
  return NULL;
}

#ifndef BRA_CFG_PROV_MULTI_BEARER
static int
bra_prs_get_setting_bearer (void *data)
{
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  int temp = BRA_PRS_INVALID_BEARER;
  
  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BEARER]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_ADR_BEARER]) == 0)
      {
        if(p.value_i == PRS_VAL_BR_GSM_CSD)        
          temp = BRA_PRS_GSM_BEARER;
        else if(p.value_i == PRS_VAL_BR_GPRS)
          temp = BRA_PRS_GPRS_BEARER;
        break;
      }
    }
#ifdef __PS_SERVICE__
    else if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_BEARER]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_ADR_BEARER]) == 0)
      {
        if(p.value_i == PRS_VAL_WAP_GSM_CSD)        
          temp = BRA_PRS_GSM_BEARER;
        else if(p.value_i == PRS_VAL_WAP_GSM_GPRS)
          temp = BRA_PRS_GPRS_BEARER;
        break;
      }
    }
#endif                    
  }
  return temp;
}
#endif

#ifdef BRA_CFG_PROV_MULTI_BEARER
static int
bra_prs_get_firstN_setting_bearers(void *data, int *bearers_list, int *num_bearers, int list_max_size)
{
  /* 0=invalid, 1=bearer --> invalid
   * 0=bearer, 1=invalid/none --> bearer
   * 0=GPRS, 1=GPRS --> multi
   * 0=GSM, 1=GSM --> multi
   * 0=GPRS/GSM, 1=GSM/GPRS --> multi
   */

  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  int i = 0;
  int first_bearer;
  int has_invalid;
  
  first_bearer = BRA_PRS_INVALID_BEARER;
  has_invalid = 0;
  if (num_bearers)
    *num_bearers = 0;
  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p) && i<list_max_size)
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BEARER]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_ADR_BEARER]) == 0)
      {
        if(p.value_i == PRS_VAL_BR_GSM_CSD)
          first_bearer = BRA_PRS_GSM_BEARER;
        else if(p.value_i == PRS_VAL_BR_GPRS)
          first_bearer = BRA_PRS_GPRS_BEARER;
        else
          has_invalid = 1;
        
        if (bearers_list)
          bearers_list[i++] = first_bearer;
        break;
      }
    }
//#ifdef __PS_SERVICE__
    else if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_BEARER]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_ADR_BEARER]) == 0)
      {
        if(p.value_i == PRS_VAL_WAP_GSM_CSD) {
          if (i == 0)
            first_bearer = BRA_PRS_GSM_BEARER;
          if (bearers_list)
            bearers_list[i++] = BRA_PRS_GSM_BEARER;

        } else if(p.value_i == PRS_VAL_WAP_GSM_GPRS) {
          if (i == 0)
            first_bearer = BRA_PRS_GPRS_BEARER;
          if (bearers_list)
            bearers_list[i++] = BRA_PRS_GPRS_BEARER;

        } else {
          has_invalid = 1;
          if (bearers_list)
            bearers_list[i++] = BRA_PRS_INVALID_BEARER;
        }
      }
    }
//#endif
  }
  if (num_bearers)
    *num_bearers = i;

  if (first_bearer==BRA_PRS_INVALID_BEARER)
    return BRA_PRS_INVALID_BEARER;

  /* if first is good and remainings are bad */
  if (has_invalid)
    return first_bearer;

  if (i<=0)
    return BRA_PRS_INVALID_BEARER;
  else if (i==1)
    return first_bearer;
  else
    return BRA_PRS_MULTI_BEARER;
}
#endif

static int
bra_prs_is_bookmark_setting (void *data)
{
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;

  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)
      continue;
    /* should skip the SIM info */
    if (!strcmp(p.path, prs_Str_resources[PRS_PATH_MTK_INFO]))
        continue; 

    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BOOKMARK]))
      return 0;
  }
  return 1;
}

static int
bra_prs_get_setting_type (void *data)
{
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  int temp = BRA_PRS_WAP_SETTING;
  
  if (bra_prs_is_bookmark_setting(data))
    return BRA_PRS_BOOKMARK_SETTING;

  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_PROXY]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_MMSURL]) == 0)
      {
        temp = BRA_PRS_MMS_SETTING;
        break;
      }

      if (strcmp(p.key, prs_Str_resources[PRS_STR_PROFILE_NAME]) == 0)
      {
        char *pname = (char*)BRA_ALLOC(p.value_bv_length+1);
        msf_cmmn_strncpy_lc(pname, (const char*)p.value_bv, p.value_bv_length);
        pname[p.value_bv_length] = '\0';

        if (strstr(pname, "mms"))
        {
          temp = BRA_PRS_MMS_SETTING;
          BRA_FREE(pname);
          break;
        }
        BRA_FREE(pname);
      } 
    }

    if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_PROXY]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_PROFILE_NAME]) == 0)
      {
        char *pname = (char*)BRA_ALLOC(p.value_bv_length+1);
        msf_cmmn_strncpy_lc(pname, (const char*)p.value_bv, p.value_bv_length);
        pname[p.value_bv_length] = '\0';

        if (strstr(pname, "mms"))
        {
          temp = BRA_PRS_MMS_SETTING;
          BRA_FREE(pname);
          break;
        }
        BRA_FREE(pname);
      } 
    }
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_APP]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_WAP_APP_APPID]) == 0)
      {
        if (strstr((const char*)p.value_bv, "w4"))
        {
          temp = BRA_PRS_MMS_SETTING;
          break;
        }
		else if(strstr((const char*)p.value_bv, "w2"))
		{
          temp = BRA_PRS_WAP_SETTING;
          break;
		}
      } 
    }
  }

  return temp;
}

static void
bra_prs_handle_ota_bookmark_item (msf_registry_response_t* data_hdl, msf_registry_param_t *p)
{
  int len;
  char *url = NULL;
  char *title = NULL;

  if (strcmp (p->key, "url") == 0)
  {
    if (p->value_bv)
    {
      len = (p->value_bv_length>BRA_MAXCHAR_STR_URL?BRA_MAXCHAR_STR_URL:p->value_bv_length);
      url = BRA_ALLOC (len + 1); 
      memcpy (url, p->value_bv, len);
      url[len] = '\0';
    }
    else
    {
      url = BRA_ALLOC(1); 
      *url = 0;
    }
  }
  else
  {
    /*Ilegal value in this path*/
    goto free;
  }

  if (!MSF_REGISTRY_RESPONSE_GET_NEXT (data_hdl, p))
  {
    /*Error*/
    goto free;
  }

  if (strcmp (p->key, "name") == 0)
  {
    if (p->value_bv)
    {
      char c;
      c = (char)p->value_bv[p->value_bv_length];
      p->value_bv[p->value_bv_length] = '\0';
      title = (char*)bra_cmn_trunc_utf8_str((char*)p->value_bv, BRA_MAXCHAR_STR_TITLE);
      p->value_bv[p->value_bv_length] = (unsigned char)c;
    }
    else
    {
      title = BRA_ALLOC(1); 
      *title = 0;
    }
  }
  else
  {
    /*Ilegal value in this path*/
    goto free;
  }
    

  if ((title == NULL) && (url == NULL))
    return;
  
  if (!check_url(url) || !bra_cmn_url_is_valid(url))
    goto free;

  bra_bkm_offline_add_new_bookmark_to_file(title, url);

free:
  BRA_FREE (url);
  BRA_FREE (title);

}

static void
bra_prs_handle_homepage_item (msf_registry_param_t *p)
{
  int len;
  char *url = NULL;
  char *title = NULL;

  if (strcmp (p->key, prs_Str_resources[PRS_STR_HOMEURL]) == 0
      || strcmp (p->key, prs_Str_resources[PRS_STR_MMSURL]) == 0
		|| strcmp (p->key, prs_Str_resources[PRS_STR_URL]) == 0)
  {
    len = (p->value_bv_length>BRA_MAXCHAR_STR_URL?BRA_MAXCHAR_STR_URL:p->value_bv_length);
    url = BRA_ALLOC (len + 1); 
    memcpy (url, p->value_bv, len);
    url[len] = '\0';

    if (!check_url(url) || !bra_cmn_url_is_valid(url))
    {
      BRA_FREE(url);
      url = NULL;
    }
  }
  else if (strcmp(p->key, prs_Str_resources[PRS_STR_PROFILE_NAME]) == 0
	  || strcmp (p->key, prs_Str_resources[PRS_STR_NAME]) == 0)
  {
    if (p->value_bv)
    {
      char c;
      c = (char)p->value_bv[p->value_bv_length];
      p->value_bv[p->value_bv_length] = '\0';
      title = (char*)bra_cmn_trunc_utf8_str((char*)p->value_bv, BRA_MAXCHAR_STR_TITLE);
      p->value_bv[p->value_bv_length] = (unsigned char)c;
    }
  }
  else
    return;

  /* 
   * Kevin: the following two bra_prof_change_key_str_value()
   * shall refer to bra_cmn_set_homepage ()
   */

  if(url)
  {
//    if(bra_prof_get_absolute_profile() == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
    if (bra_prof_is_bra_profile_in_active_use(BRA_PROF_ID_BRA, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
      bra_cmn_set_local_hompage_url (url);  
    bra_prs_increase_items_cnt();  
    bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL, url, bra_prs_decrease_items_cnt);
    BRA_FREE (url);
  }  

  if(title)
  {
//    if(bra_prof_get_absolute_profile() == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
    if (bra_prof_is_bra_profile_in_active_use(BRA_PROF_ID_BRA, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
      bra_cmn_set_local_hompage_title (BRA_STRCONV(title));  
    bra_prs_increase_items_cnt();  
    bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE, title, bra_prs_decrease_items_cnt);
    BRA_FREE (title);
  }  
}

static void
bra_prs_handle_application_item (msf_registry_param_t *p)
{
  int len;
  char *url = NULL;
  msf_scheme_t scheme_type;


  if(strcmp (p->key, prs_Str_resources[PRS_STR_WAP_APP_ADDR]) == 0 && bra_prs_setting_type == BRA_PRS_MMS_SETTING)
  {
    len = (p->value_bv_length>BRA_MAXCHAR_STR_URL?BRA_MAXCHAR_STR_URL:p->value_bv_length);
    url = BRA_ALLOC (len + 1); 
    memcpy (url, p->value_bv, len);
    url[len] = '\0';
   
    if (!check_url(url) || !bra_cmn_url_is_valid(url))
    {
        BRA_FREE(url);
        return;
    }
    scheme_type = msf_url_get_scheme_type(url);
    if (scheme_type != msf_scheme_http && scheme_type != msf_scheme_https)
    {
        BRA_FREE(url);
        return;
    }
  }
  else if(strcmp (p->key, prs_Str_resources[PRS_STR_WAP_APP_RES_URI]) == 0 && bra_prs_setting_type == BRA_PRS_WAP_SETTING)
  {
    len = (p->value_bv_length>BRA_MAXCHAR_STR_URL?BRA_MAXCHAR_STR_URL:p->value_bv_length);
    url = BRA_ALLOC (len + 1); 
    memcpy (url, p->value_bv, len);
    url[len] = '\0';

    if (!check_url(url) || !bra_cmn_url_is_valid(url))
    {
        BRA_FREE(url);
        return;
    }
  }
  else
    return;

  if(url)
  {
//    if(bra_prof_get_absolute_profile() == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
    if (bra_prof_is_bra_profile_in_active_use(BRA_PROF_ID_BRA, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
      bra_cmn_set_local_hompage_url (url);  
    bra_prs_increase_items_cnt();  
    bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL, url, bra_prs_decrease_items_cnt);
    BRA_FREE (url);
  }  
}

static void
bra_prs_handle_proxy_item (msf_registry_param_t *p)
{
  char *bra_key = NULL;
  char *value_bv = NULL; 
  int value_i = 0;
  int type = 0;
  int len;

  if (strcmp (p->key, prs_Str_resources[PRS_STR_PX_NAME]) == 0)
    bra_prs_num_proxies++;
  if (bra_prs_num_proxies > 1)
    return;

  /* handle HOMEPAGE or MMSC if possible */
  bra_prs_handle_homepage_item(p);

  bra_key = (char *)bra_prs_cvt_key (p->key);
  
  if (bra_key == NULL)
    return;

  if (strcmp(bra_key, BRA_PROF_KEY_PRX_NAME)==0)
  {
    char *str_profname = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR);
    if (str_profname==NULL || *str_profname==0)
      bra_key = (char *)bra_prs_cvt_key((char*)prs_Str_resources[PRS_STR_PROFILE_NAME]);
    else
      return;
  }

  if (p->type == 1)
  {      
    if (strcmp(bra_key, BRA_PROF_KEY_PRX_UID) == 0)
      len = (p->value_bv_length>BRA_MAXCHAR_STR_PX_AUTH_NAME?BRA_MAXCHAR_STR_PX_AUTH_NAME:p->value_bv_length);
    else if (strcmp(bra_key, BRA_PROF_KEY_PRX_PWD) == 0)
      len = (p->value_bv_length>BRA_MAXCHAR_STR_PX_AUTH_SECRET?BRA_MAXCHAR_STR_PX_AUTH_SECRET:p->value_bv_length);
    else
      len = p->value_bv_length;

    value_bv = BRA_ALLOC (len + 1);
    memcpy (value_bv, p->value_bv, len);
    value_bv[len] = '\0';   
    
    if (strcmp(p->key, prs_Str_resources[PRS_STR_PX_PORT]) == 0)
    {
      type = 0;
      value_i = atoi(value_bv);
      BRA_FREE(value_bv);
    }
    else
      type = 1;

    if (strcmp(bra_key, BRA_PROF_KEY_PROF_STR)==0 && p->value_bv)
    {
        char c;
        BRA_FREE(value_bv);
        c = (char)p->value_bv[p->value_bv_length];
        p->value_bv[p->value_bv_length] = '\0';
        value_bv = (char*)bra_cmn_trunc_utf8_str((char*)p->value_bv, BRA_MAXCHAR_STR_PROFILE_NAME);
        p->value_bv[p->value_bv_length] = (unsigned char)c;
    }

    if (strcmp(bra_key, BRA_PROF_KEY_PRX_ADDR) == 0)
    {
      unsigned char ip[4];
      memset(ip, 0, 4);
      bra_cmn_get_address(value_bv, ip);
      if (ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0) {
        value_bv[0] = '\0';
        len = 1;
      }
    }
  }
  else if (p->type == 0)
  {
    type = p->type;
    value_i = p->value_i;
  }

  if (type == 1)
  {
    bra_prs_increase_items_cnt();
    bra_prof_change_key_str_value (BRA_PROF_ID_BRA, bra_key, value_bv, bra_prs_decrease_items_cnt);
    BRA_FREE (value_bv);
  }
  else if(type == 0)
  {   
#ifdef WAP_SUPPORT 
    if(strcmp(p->key, prs_Str_resources[PRS_STR_PX_SERVICE]) == 0)
	{
		switch(value_i)
		{
         /* WAP connectionless */                  
         case PRS_VAL_WAP_CL_WSP:
         case PRS_VAL_WAP_CL_SEC_WSP:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_WSP_CL, 
                                             bra_prs_decrease_items_cnt);              
              break;
              
         /* WAP connection-oriented */              
         case PRS_VAL_WAP_CO_WSP:
         case PRS_VAL_WAP_CO_SEC_WSP:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_WSP_CO, 
                                             bra_prs_decrease_items_cnt);
              break;              
                       
         case PRS_VAL_WAP_OTA_HTTP_TO:
         case PRS_VAL_WAP_OTA_HTTP_TLS_TO:
         case PRS_VAL_WAP_OTA_HTTP_PO:
         case PRS_VAL_WAP_OTA_HTTP_TLS_PO:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_HTTP, 
                                             bra_prs_decrease_items_cnt);
              break;              

		 default:
              break;

		}
		return;
	}
	else if(strcmp(p->key, prs_Str_resources[PRS_STR_PX_PORT]) == 0)
    {      
      switch(value_i)
      {
         /* WAP connectionless */                  
         case 9200:
         case 9202:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_WSP_CL, 
                                             bra_prs_decrease_items_cnt);              
              break;
              
         /* WAP connection-oriented */              
         case 9201:
         case 9203:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_WSP_CO, 
                                             bra_prs_decrease_items_cnt);
              break;              
                       
         default:
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_CON_TYPE, 
                                             BRA_SET_CONNECTION_TYPE_HTTP, 
                                             bra_prs_decrease_items_cnt);
              bra_prs_increase_items_cnt();
              bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                             BRA_PROF_KEY_PRX_PORT, 
                                             value_i, 
                                             bra_prs_decrease_items_cnt);
              break;
      }/*switch*/
    }
#endif /* WAP_SUPPORT */   

    bra_prs_increase_items_cnt();
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, bra_key, value_i, bra_prs_decrease_items_cnt);
  }
}

#ifdef __TCPIP__

void
bra_prs_send_msg_to_l4(kal_uint16 msg_id,
                       local_para_struct *local_para_ptr,
                       peer_buff_struct  *peer_buff_ptr)
{
   ilm_struct *ilm = allocate_ilm( MOD_WAP ) ;

   ASSERT( ilm != NULL );
     
   ilm->dest_mod_id = MOD_L4C;
   ilm->local_para_ptr = local_para_ptr;
   ilm->peer_buff_ptr  = peer_buff_ptr;
   ilm->sap_id         = MMI_L4C_SAP;
   ilm->msg_id         = msg_id;
   SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm);
} /* end of bra_prs_send_msg_to_l4 */

void bra_prs_set_account_name(int bearer, msf_registry_param_t *p)
{
   kal_uint8 len = (p->value_bv_length>BRA_MAXCHAR_STR_ISP_NAME?BRA_MAXCHAR_STR_ISP_NAME:(kal_uint8)p->value_bv_length);
   kal_uint8 isUTFStr;
   kal_uint8 *tmp;
   kal_int32 destLen;
   kal_int32 srcLen;

   tmp = BRA_ALLOC(len+1);
   kal_mem_cpy(tmp, p->value_bv, len);
   tmp[len] = '\0';

   isUTFStr = (widget_utf8_length((const kal_uint8 *)tmp)!=strlen((char*)tmp));

#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GSM_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GSM_BEARER))
#else
   if(bearer == BRA_PRS_GSM_BEARER)
#endif
   {
      if(len > 31)
         len = 31;
      
      if(set_csd_req)
      {
         memset(set_csd_req->name.name, 0, 32);
         if (!isUTFStr)
         {
            kal_mem_cpy(set_csd_req->name.name, p->value_bv, len);     
            //set_csd_req->name.name[len] = '\0';
            set_csd_req->name.name_length = len;
            set_csd_req->name.name_dcs = PHB_ASCII;
         }
         else
         {
            srcLen = strlen((char*)tmp);
            destLen = 30;
            msf_charset_utf8_to_ucs2be((const char *)tmp, (long *)&srcLen, (char *)set_csd_req->name.name, (long *)&destLen);
            set_csd_req->name.name_length = destLen; //widget_ucs2_length(set_csd_req->name.name)*2;
            set_csd_req->name.name_dcs = PHB_UCS2;
         }
      }
   }
#ifdef __PS_SERVICE__   
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GPRS_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GPRS_BEARER))
#else
   else if(bearer == BRA_PRS_GPRS_BEARER)
#endif
   {
      if(set_gprs_req)
      {
         memset(set_gprs_req->gprs_account.name, 0, 32);
         if (!isUTFStr)
         {
            kal_mem_cpy(set_gprs_req->gprs_account.name, p->value_bv, len);     
            //set_gprs_req->gprs_account.name[len] = '\0';
            set_gprs_req->gprs_account.name_length = len;
            set_gprs_req->gprs_account.name_dcs = PHB_ASCII;
         }
         else
         {
            srcLen = strlen((char*)tmp);
            destLen = 30;
            msf_charset_utf8_to_ucs2be ((const char *)tmp, (long *)&srcLen, (char *)set_gprs_req->gprs_account.name, (long *)&destLen);
            set_gprs_req->gprs_account.name_length = destLen; //widget_ucs2_length(set_gprs_req->gprs_account.name)*2;
            set_gprs_req->gprs_account.name_dcs = PHB_UCS2;
         }
      }
   }
#endif   
   BRA_FREE(tmp);
}

void bra_prs_set_ppp_authtype(int bearer, msf_registry_param_t *p)
{
  unsigned char *strType;

  if (p->type==1 && p->value_bv_length>0) {
    strType = (unsigned char*)BRA_ALLOC(p->value_bv_length+1);
    kal_mem_cpy(strType, p->value_bv, p->value_bv_length);
    strType[p->value_bv_length] = 0;
  } else {
    strType = 0;
  }

  // 0 = PAP = NORMAL
  // 1 = CHAP = SECURE
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GSM_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GSM_BEARER))
#else
   if(bearer == BRA_PRS_GSM_BEARER)
#endif
   {
      if ((strType && msf_cmmn_strcmp_nc((char*)strType, "PAP")==0) || (!strType && p->value_i == PRS_VAL_BR_PAP))
        set_csd_req->auth_type = 0;
      else if ((strType && msf_cmmn_strcmp_nc((char*)strType, "CHAP")==0) || (!strType && p->value_i == PRS_VAL_BR_CHAP))
        set_csd_req->auth_type = 1;
      else
        set_csd_req->auth_type = 0;
   }
#ifdef __PS_SERVICE__
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GPRS_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GPRS_BEARER))
#else
   else if(bearer == BRA_PRS_GPRS_BEARER)
#endif
   {
      if ((strType && msf_cmmn_strcmp_nc((char*)strType, "PAP")==0) || (!strType && p->value_i == PRS_VAL_BR_PAP))
        set_gprs_req->gprs_account.authentication_type = 0;
      else if ((strType && msf_cmmn_strcmp_nc((char*)strType, "CHAP")==0) || (!strType && p->value_i == PRS_VAL_BR_CHAP))
        set_gprs_req->gprs_account.authentication_type = 1;
      else
        set_gprs_req->gprs_account.authentication_type = 0;
   }
#endif
   BRA_FREE(strType);
} /* end of bra_prs_set_ppp_authtype */


void bra_prs_set_ppp_authname(int bearer, msf_registry_param_t *p)
{
   kal_uint8 len = (p->value_bv_length>BRA_MAXCHAR_STR_PPP_AUTHNAME?BRA_MAXCHAR_STR_PPP_AUTHNAME:(kal_uint8)p->value_bv_length);
 
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GSM_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GSM_BEARER))
#else
   if(bearer == BRA_PRS_GSM_BEARER)
#endif
   {
      if(len > 31)
         len = 31;
      
      if(set_csd_req)
      {
         kal_mem_cpy(set_csd_req->user_id, p->value_bv, len);
      
         set_csd_req->user_id[len] = '\0';
      }
   }
#ifdef __PS_SERVICE__   
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GPRS_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GPRS_BEARER))
#else
   else if(bearer == BRA_PRS_GPRS_BEARER)
#endif
   {
      if(len > MAX_GPRS_USER_NAME_LEN)
         len = MAX_GPRS_USER_NAME_LEN;
      
      if(set_gprs_req)
      {
         kal_mem_cpy(set_gprs_req->gprs_account.user_name, p->value_bv, len);      
         set_gprs_req->gprs_account.user_name[len] = '\0';
      }
   }
#endif

} /* end of bra_prs_set_ppp_authname */

void bra_prs_set_ppp_authpw(int bearer, msf_registry_param_t *p)
{
   kal_uint8 len = (p->value_bv_length>BRA_MAXCHAR_STR_PPP_AUTHPW?BRA_MAXCHAR_STR_PPP_AUTHPW:(kal_uint8)p->value_bv_length);
     
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GSM_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GSM_BEARER))
#else
   if(bearer == BRA_PRS_GSM_BEARER)
#endif
   {
      if(len > 31)
         len = 31;

      if(set_csd_req)
      {
         kal_mem_cpy(set_csd_req->passwd, p->value_bv, len);

         set_csd_req->passwd[len] = '\0';
      }
   }
#ifdef __PS_SERVICE__   
#ifdef BRA_CFG_PROV_MULTI_BEARER
   if(bearer==BRA_PRS_GPRS_BEARER ||
      (bearer==BRA_PRS_MULTI_BEARER &&
       bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GPRS_BEARER))
#else
   else if(bearer == BRA_PRS_GPRS_BEARER)
#endif
   {
      if(len > MAX_GPRS_PASSWORD_LEN)
         len = MAX_GPRS_PASSWORD_LEN;
      
      if(set_gprs_req)
      {
         kal_mem_cpy(set_gprs_req->gprs_account.password, p->value_bv, len);      
         set_gprs_req->gprs_account.password[len] = '\0';
      }
   }
#endif

} /* end of bra_prs_set_ppp_authpw */

#ifdef __CS_SERVICE__

void bra_prs_set_gsm_addr(msf_registry_param_t *p)
{
   kal_uint8 i=0; /* reset */
   kal_uint8 len;
   
   if(set_csd_req)
   {
      if(*(p->value_bv) == '+')
      {
         i=1;
         set_csd_req->dest.type = CSMCC_INTERNATIONAL_ADDR;
      }
      else
         set_csd_req->dest.type = CSMCC_DEFAULT_ADDR_TYPE;

      len = (p->value_bv_length-i>BRA_MAXCHAR_STR_CSD_DAILSTRING?BRA_MAXCHAR_STR_CSD_DAILSTRING:(kal_uint8)(p->value_bv_length-i));
      kal_mem_cpy(set_csd_req->dest.number, 
                  p->value_bv+i,
                  len);

      set_csd_req->dest.number[len] = '\0';
   }
} /* end of bra_prs_set_gsm_addr */

/* 
 * Receive Set GSM profile response 
 */
void bra_prs_set_gsm_profile_rsp(local_para_struct *local_para_ptr)
{
   mmi_cc_set_csd_profile_rsp_struct *rsp;
   
   if(bra_prs_data_queue_size <= 0) /* in case of WAP reset */
      return;
      
   ASSERT( local_para_ptr != NULL );

   rsp = (mmi_cc_set_csd_profile_rsp_struct*) local_para_ptr;

   if(bra_prs_gsm_state == BRA_PRS_WAIT_SET_RSP)
   {
      bra_prs_gsm_state = BRA_PRS_NULL;          
#ifdef __PS_SERVICE__
      if (bra_prs_gprs_state == BRA_PRS_NULL)
#endif
        bra_prs_delete_and_continue ();
   }

} /* end of bra_prs_set_gsm_profile_rsp */

void bra_prs_get_free_gsm_profile_req(void)
{
   /* get a free CSD profile slot */
   bra_prs_gsm_state = BRA_PRS_WAIT_FREE_ID_RSP;
         
   bra_prs_send_msg_to_l4(MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_REQ,
                                NULL,
                                NULL);     
         
} /* end of bra_prs_get_free_gsm_profile_req */

/* 
 * Receive Get GSM free profile response 
 */
void bra_prs_get_free_gsm_profile_rsp(local_para_struct *local_para_ptr)
{
   mmi_cc_get_free_csd_profile_num_rsp_struct *rsp;

   if(bra_prs_data_queue_size <= 0) /* in case of WAP reset */
      return;
      
   ASSERT(local_para_ptr != NULL);
            
   rsp = (mmi_cc_get_free_csd_profile_num_rsp_struct*) local_para_ptr;
   
   if(bra_prs_gsm_state == BRA_PRS_WAIT_FREE_ID_RSP)
   {
      //data_acct_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
#ifdef BRA_CFG_PROV_MULTI_BEARER
      if(data_acct_id[0] >= MAX_CSD_PROFILE_NUM)
         data_acct_id[0] -= MAX_CSD_PROFILE_NUM;
#else
      if(data_acct_id >= MAX_CSD_PROFILE_NUM)
         data_acct_id -= MAX_CSD_PROFILE_NUM;
#endif
      /*if(rsp->result == KAL_TRUE)
         data_acct_id = rsp->no_entry;
      else
         data_acct_id = 0; // replace 1st profile
      */

      bra_prs_gsm_state = BRA_PRS_WAIT_SEND_SET_REQ;

      /* initialize selected profile */
      bra_cmn_set_local_hompage_title (BRA_STRCONV(""));  
      bra_prs_increase_items_cnt();  
      bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_UID, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PWD, "", bra_prs_decrease_items_cnt);
      bra_prs_continue(bra_prs_data_queue[bra_prs_data_queue_current_item]);
               
   }

} /* end of bra_prs_get_free_gsm_profile_rsp */

void bra_prs_set_gsm_profile_req(void)
{
   if(bra_prs_gsm_state == BRA_PRS_WAIT_SEND_SET_REQ)
   {
      if(set_csd_req != NULL)
      {
#ifdef BRA_CFG_PROV_MULTI_BEARER
         if(bra_prs_bearer != BRA_PRS_MULTI_BEARER)
            set_csd_req->prof_id = data_acct_id[0];
         else {
            if (bra_prs_bearers_list[0] == BRA_PRS_GSM_BEARER)
              set_csd_req->prof_id = data_acct_id[0];
            else
              set_csd_req->prof_id = data_acct_id[1];
         }
#else
         set_csd_req->prof_id = data_acct_id;
#endif
         if(set_csd_req->name.name_dcs == 0xff)
         {
           char *s = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR);
           kal_mem_cpy(set_csd_req->name.name, s, strlen(s));     
           set_csd_req->name.name[strlen(s)] = '\0';
           set_csd_req->name.name_length = strlen(s);
           set_csd_req->name.name_dcs = PHB_ASCII;
         }

         bra_prs_gsm_state = BRA_PRS_WAIT_SET_RSP;
                  
         bra_prs_send_msg_to_l4(MSG_ID_MMI_CC_SET_CSD_PROFILE_REQ,
                                (local_para_struct*)set_csd_req,
                                NULL);     
                                
         set_csd_req = NULL; /* avoid double free */
      }
   }
}

void bra_prs_gsm_setting_init(void)
{
   if(set_csd_req == NULL)
   {
      set_csd_req = (mmi_cc_set_csd_profile_req_struct *)
         construct_local_para(sizeof(mmi_cc_set_csd_profile_req_struct),TD_CTRL);
      
      set_csd_req->prof_id = 0; /* 1st entry */
      set_csd_req->dest.type  = 0xff;
      set_csd_req->type       = 0xff; 
      set_csd_req->rate       = CSD_PROF_RATE_9600;
      set_csd_req->auth_type  = 0xff;
      set_csd_req->name.name_dcs = 0xff;
      set_csd_req->user_id[0] = 0x0;
      set_csd_req->passwd[0]  = 0x0;      
      set_csd_req->dns_addr_present = KAL_FALSE;
      set_csd_req->csd_module = KAL_FALSE; /* non-transparent */
   }  

} /* end of bra_prs_gsm_setting_init */

#endif /* __CS_SERVICE__ */

#ifdef __PS_SERVICE__

void bra_prs_set_gprs_addr(msf_registry_param_t *p)
{
   kal_uint8 len = (p->value_bv_length>BRA_MAXCHAR_STR_GPRS_APN?BRA_MAXCHAR_STR_GPRS_APN:(kal_uint8)p->value_bv_length);

   if(set_gprs_req)
   {
     set_gprs_req->gprs_account.apn_length = len;
     kal_mem_cpy(set_gprs_req->gprs_account.apn, 
                 p->value_bv,
                 len); 
   }

} /* end of bra_prs_set_gprs_addr */

/* 
 * Receive Set GPRS profile response 
 */
void bra_prs_set_gprs_profile_rsp(local_para_struct *local_para_ptr)
{
   mmi_ps_set_gprs_data_account_rsp_struct *rsp;

   if(bra_prs_data_queue_size <= 0) /* in case of WAP reset */
      return;
   
   ASSERT( local_para_ptr != NULL );

   rsp = (mmi_ps_set_gprs_data_account_rsp_struct*) local_para_ptr;

   if(bra_prs_gprs_state == BRA_PRS_WAIT_SET_RSP)
   {
      bra_prs_gprs_state = BRA_PRS_NULL;
#ifdef __CS_SERVICE__
      if (bra_prs_gsm_state == BRA_PRS_NULL)
#endif
        bra_prs_delete_and_continue ();

   }

} /* end of bra_prs_set_gprs_profile_rsp */

void bra_prs_get_free_gprs_profile_req(void)
{
   /* get a free CSD profile slot */
   bra_prs_gprs_state = BRA_PRS_WAIT_FREE_ID_RSP;
   bra_prs_send_msg_to_l4(MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_REQ,
                                NULL,
                                NULL);        
   
} /* end of bra_prs_get_free_gprs_profile_req */

/* 
 * Receive Get GPRS free profile response 
 */
void bra_prs_get_free_gprs_profile_rsp(local_para_struct *local_para_ptr)
{
   mmi_ps_get_gprs_empty_profile_rsp_struct *rsp;

   if(bra_prs_data_queue_size <= 0) /* in case of WAP reset */
      return;
   
   ASSERT ( local_para_ptr != NULL ) ;   

   rsp = (mmi_ps_get_gprs_empty_profile_rsp_struct*) local_para_ptr;
   
   if(bra_prs_gprs_state == BRA_PRS_WAIT_FREE_ID_RSP)
   {
      //data_acct_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
#ifdef BRA_CFG_PROV_MULTI_BEARER
      if(data_acct_id[0] < MAX_CSD_PROFILE_NUM)
        data_acct_id[0] = data_acct_id[0] + MAX_CSD_PROFILE_NUM;
#else
      if(data_acct_id < MAX_CSD_PROFILE_NUM)
        data_acct_id = data_acct_id + MAX_CSD_PROFILE_NUM;
#endif
      /*if(rsp->result == KAL_TRUE)
         data_acct_id = rsp->entry_num + MAX_CSD_PROFILE_NUM - 1;
      else
         data_acct_id = MAX_CSD_PROFILE_NUM; // replace 1st profile 
      */

      bra_prs_gprs_state = BRA_PRS_WAIT_SEND_SET_REQ;

      /* initialize selected profile */
      bra_cmn_set_local_hompage_title (BRA_STRCONV(""));  
      bra_prs_increase_items_cnt();  
      bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_UID, "", bra_prs_decrease_items_cnt);
      bra_prs_increase_items_cnt();
      bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PWD, "", bra_prs_decrease_items_cnt);
      bra_prs_continue(bra_prs_data_queue[bra_prs_data_queue_current_item]);
   }

} /* end of bra_prs_get_free_gprs_profile_rsp */

void bra_prs_set_gprs_profile_req(void)
{
   if(bra_prs_gprs_state == BRA_PRS_WAIT_SEND_SET_REQ)
   {
      if(set_gprs_req != NULL)
      {
#ifdef BRA_CFG_PROV_MULTI_BEARER
         if(bra_prs_bearer != BRA_PRS_MULTI_BEARER)
            set_gprs_req->gprs_account.context_id = data_acct_id[0] + 1 - MAX_CSD_PROFILE_NUM;
         else {
            if (bra_prs_bearers_list[0] == BRA_PRS_GPRS_BEARER)
              set_gprs_req->gprs_account.context_id = data_acct_id[0] + 1 - MAX_CSD_PROFILE_NUM;
            else
              set_gprs_req->gprs_account.context_id = data_acct_id[1] + 1 - MAX_CSD_PROFILE_NUM;
         }
#else
         set_gprs_req->gprs_account.context_id = data_acct_id + 1 - MAX_CSD_PROFILE_NUM;
#endif
         if(set_gprs_req->gprs_account.name_dcs == 0xff)
         {
           char *s = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR);
           kal_mem_cpy(set_gprs_req->gprs_account.name, s, strlen(s));     
           set_gprs_req->gprs_account.name[strlen(s)] = '\0';
           set_gprs_req->gprs_account.name_length = strlen(s);
           set_gprs_req->gprs_account.name_dcs = PHB_ASCII;
         }

         bra_prs_gprs_state = BRA_PRS_WAIT_SET_RSP;
         
         bra_prs_send_msg_to_l4(MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ,
                               (local_para_struct*)set_gprs_req,
                               NULL);     
                                
         set_gprs_req = NULL; /* avoid double free */
      }
   }
}

void bra_prs_gprs_setting_init(void)
{
   if(set_gprs_req == NULL)
   {
      set_gprs_req = (mmi_ps_set_gprs_data_account_req_struct *)
         construct_local_para(sizeof(mmi_ps_set_gprs_data_account_req_struct), TD_CTRL);

      memset((kal_uint8*)set_gprs_req+sizeof(ps_dummy_local_para_header_struct),
             0, sizeof(mmi_ps_set_gprs_data_account_req_struct) - sizeof(ps_dummy_local_para_header_struct));
      set_gprs_req->gprs_account.context_id = 1; /* 1st entry */     
      set_gprs_req->gprs_account.apn_length = 0xff;
      set_gprs_req->gprs_account.name_dcs = 0xff;
  }  

} /* end of bra_prs_gprs_setting_init */

#endif /* __PS_SERVICE__ */

static void
bra_prs_handle_ota_bearer_item (msf_registry_response_t* data_hdl, msf_registry_param_t *p)
{
#ifdef __CS_SERVICE__

  if(bra_prs_bearer == BRA_PRS_GSM_BEARER)      
  {  
  bra_prs_gsm_setting_init();  

  if (strcmp (p->key, prs_Str_resources[PRS_STR_ISP_NAME]) == 0)
  {
     /* Account name */
     bra_prs_set_account_name(bra_prs_bearer, p);
  }    
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHTYPE]) == 0)
  {
     /* PPP auth. type */
     bra_prs_set_ppp_authtype(bra_prs_bearer, p);
  }  
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHNAME]) == 0)
  {
     /* PPP auth. name */
     bra_prs_set_ppp_authname(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHPW]) == 0)
  {
     /* PPP auth. password */
     bra_prs_set_ppp_authpw(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_CSD_CALLTYPE]) == 0)
  {
     /* CSD call type */
     if(p->value_i == PRS_VAL_BR_ANALOGUE)
        set_csd_req->type = CSMCC_ITC_3_1_K_AUDIO;
     else
        set_csd_req->type = CSMCC_ITC_UDI;     
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_CSD_CALLSPEED]) == 0)
  {
     /* CSD call speed */
     switch(p->value_i)
     {
        case PRS_VAL_BR_AUTO:
           /* because MMI doesn't distiguish the AUTO type */
           set_csd_req->rate = CSD_PROF_RATE_9600;
           break;
        case PRS_VAL_BR_9600:
           set_csd_req->rate = CSD_PROF_RATE_9600;
           break;            
        case PRS_VAL_BR_14400:
        case PRS_VAL_BR_19200:
        case PRS_VAL_BR_28800:
        case PRS_VAL_BR_38400:
        case PRS_VAL_BR_43200:
        case PRS_VAL_BR_57600:
           set_csd_req->rate = CSD_PROF_RATE_14400;
           break;
        default:
           break;           
     }/* switch */
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_CSD_DAILSTRING]) == 0)
  {
     /* CSD dial string */
     bra_prs_set_gsm_addr(p);
  }
  }
#endif /* __CS_SERVICE__ */

#ifdef __PS_SERVICE__

  if(bra_prs_bearer == BRA_PRS_GPRS_BEARER)
  {
  bra_prs_gprs_setting_init();

  if (strcmp (p->key, prs_Str_resources[PRS_STR_ISP_NAME]) == 0)
  {
     /* Account name */
     bra_prs_set_account_name(bra_prs_bearer, p);
  }    
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHTYPE]) == 0)
  {
     /* PPP auth. type */
     bra_prs_set_ppp_authtype(bra_prs_bearer, p);
  }  
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHNAME]) == 0)
  {
     /* PPP auth. name */
     bra_prs_set_ppp_authname(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHPW]) == 0)
  {
     /* PPP auth. password */
     bra_prs_set_ppp_authpw(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_GPRS_APN]) == 0)
  {
     /* GPRS APN */
     bra_prs_set_gprs_addr(p);
  }
  }

#endif /* __PS_SERVICE__ */

} /* end of bra_prs_handle_ota_bearer_item */

static void
bra_prs_handle_wap_bearer_item (msf_registry_response_t* data_hdl, msf_registry_param_t *p)
{    
  if (strcmp (p->key, prs_Str_resources[PRS_STR_ADR_BEARER]) == 0)
    bra_prs_num_bearers++;
#ifdef BRA_CFG_PROV_MULTI_BEARER
  if (bra_prs_num_bearers>BRA_PRS_MAX_NBR_BEARERS || (bra_prs_bearer!=BRA_PRS_MULTI_BEARER && bra_prs_num_bearers>1))
#else
  if (bra_prs_num_bearers > 1)
#endif
    return;

#ifdef __CS_SERVICE__  
#ifdef BRA_CFG_PROV_MULTI_BEARER
  if(bra_prs_bearer == BRA_PRS_GSM_BEARER ||
     (bra_prs_bearer==BRA_PRS_MULTI_BEARER &&
     bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GSM_BEARER))
#else
  if(bra_prs_bearer == BRA_PRS_GSM_BEARER)
#endif
  {  
  bra_prs_gsm_setting_init();  

  if (strcmp (p->key, prs_Str_resources[PRS_STR_ISP_NAME]) == 0)
  {
     /* Account name */
     bra_prs_set_account_name(bra_prs_bearer, p);
  }    
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHTYPE]) == 0)
  {
     /* PPP auth. type */
     bra_prs_set_ppp_authtype(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHNAME]) == 0)
  {
     /* PPP auth. name */
     bra_prs_set_ppp_authname(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHPW]) == 0)
  {
     /* PPP auth. password */
     bra_prs_set_ppp_authpw(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_CSD_CALLTYPE]) == 0)
  {
     /* CSD call type */
     switch(p->value_i)
     {
        case PRS_VAL_WAP_ANALOG_MODEM: 
             set_csd_req->type = CSMCC_ITC_3_1_K_AUDIO;
             break;
        case PRS_VAL_WAP_V120:
        case PRS_VAL_WAP_V110:
        case PRS_VAL_WAP_X31:
             set_csd_req->type = CSMCC_ITC_UDI;
             break;		
        case PRS_VAL_WAP_BIT_TRANSP:
             set_csd_req->csd_module = KAL_TRUE;
             break;                      
     }
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_CSD_CALLSPEED]) == 0)
  {
     /* CSD call speed */
     switch(p->value_i)
     {
        case PRS_VAL_WAP_AUTOBAUDING:
             /* because MMI doesn't distiguish the AUTO type */
             set_csd_req->rate = CSD_PROF_RATE_9600;
             break;
        case 2400:
             set_csd_req->rate = CSD_PROF_RATE_2400;
             break;
        case 4800:
             set_csd_req->rate = CSD_PROF_RATE_4800;
             break;         
        case 9600:
             set_csd_req->rate = CSD_PROF_RATE_9600;
             break;        
        case 14400:
             set_csd_req->rate = CSD_PROF_RATE_14400;
             break;
     } /* switch */       
  }  
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_WAP_NAP_ADDR]) == 0)
  {
      msf_registry_param_t p1;
            
      if (!MSF_REGISTRY_RESPONSE_GET_NEXT (data_hdl, &p1)
          || strcmp (p1.key, prs_Str_resources[PRS_STR_WAP_NAP_ADDRTYPE]) != 0
          || p1.value_i != PRS_VAL_WAP_E164)
      {
         /*Error*/
         goto error;
      }

      bra_prs_set_gsm_addr(p);
  }
  }
#endif /* __ GSM_MODE__ */

#ifdef __PS_SERVICE__   
#ifdef BRA_CFG_PROV_MULTI_BEARER
  if(bra_prs_bearer == BRA_PRS_GPRS_BEARER ||
     (bra_prs_bearer==BRA_PRS_MULTI_BEARER &&
     bra_prs_bearers_list[bra_prs_num_bearers-1]==BRA_PRS_GPRS_BEARER))
#else
  if(bra_prs_bearer == BRA_PRS_GPRS_BEARER)
#endif
  {  
  bra_prs_gprs_setting_init(); 

  if (strcmp (p->key, prs_Str_resources[PRS_STR_ISP_NAME]) == 0)
  {
     /* Account name */
     bra_prs_set_account_name(bra_prs_bearer, p);
  }       
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHTYPE]) == 0)
  {
     /* PPP auth. type */
     bra_prs_set_ppp_authtype(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHNAME]) == 0)
  {
     /* PPP auth. name */
     bra_prs_set_ppp_authname(bra_prs_bearer, p);
  }
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_PPP_AUTHPW]) == 0)
  {
     /* PPP auth. password */
     bra_prs_set_ppp_authpw(bra_prs_bearer, p);
  }  
  else if (strcmp (p->key, prs_Str_resources[PRS_STR_WAP_NAP_ADDR]) == 0)
  {
      msf_registry_param_t p1;
            
      if (!MSF_REGISTRY_RESPONSE_GET_NEXT (data_hdl, &p1)
          || strcmp (p1.key, prs_Str_resources[PRS_STR_WAP_NAP_ADDRTYPE]) != 0
          || p1.value_i != PRS_VAL_WAP_APN)
      {
         /*Error*/
         goto error;
      }

      bra_prs_set_gprs_addr(p);
  }
  }
#endif /* __PS_SERVICE__ */
    
error: 

   return;

} /* end of bra_prs_handle_wap_bearer_item */

#endif /* __TCPIP__ */

static void
bra_prs_instal_response (MsfActionType response)
{
  if (response == MsfOk)
  {
    bra_prs_num_bearers = 0;
    bra_prs_num_proxies = 0;

    /* check bearer type for MMS setting */
#ifdef BRA_CFG_PROV_MULTI_BEARER
    bra_prs_crt_netid_menu_type = BRA_PRS_GPRS_BEARER;
#ifdef MMS_CFG_FALLBACK_SUPPORT
    if (0)
#else
    //if (bra_prs_setting_type == BRA_PRS_MMS_SETTING && (bra_prs_bearer==BRA_PRS_GSM_BEARER || bra_prs_bearer==BRA_PRS_MULTI_BEARER))
    if (bra_prs_setting_type == BRA_PRS_MMS_SETTING && bra_prs_bearer == BRA_PRS_MULTI_BEARER)
#endif  /* MMS_CFG_FALLBACK_SUPPORT */

#else
    //if (bra_prs_setting_type == BRA_PRS_MMS_SETTING && bra_prs_bearer == BRA_PRS_GSM_BEARER)
    if (0)
#endif
    {
      bra_dlg_create_dlg (MsfError,
                          BRA_STR_PARSER_ERROR, 
                          BRA_STR_OK, 
                          0,
                          0, 
                          NULL);
    }
    else
    {
      bra_prs_create_prof_sel_menu ();
      return;
    }
  }
#ifdef BRA_CFG_CANCEL_PROV_CONF
  else
  {
    bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
    return;
  }
#endif

  bra_prs_delete_and_continue ();

}

static void
bra_prs_instal_response_pinned_prov(MsfActionType response) {
    if (response==MsfOk) {
        HDIc_widgetAction(MSF_MODID_PRS, bra_prs_pinned_prov.dlgHandle, bra_prs_pinned_prov.yesHandle);
        bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF;

    } else {
#ifdef BRA_CFG_CANCEL_PROV_CONF
        bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
#else
        HDIc_widgetAction(MSF_MODID_PRS, bra_prs_pinned_prov.dlgHandle, bra_prs_pinned_prov.noHandle);
        bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
#endif
    }
}

static void
bra_prs_instal_response_bookmark(MsfActionType response) {
  msf_registry_param_t p;
  msf_registry_response_t* data_hdl = (msf_registry_response_t*)bra_prs_data_queue[bra_prs_data_queue_current_item];

  if (response==MsfOk) {
    if (bra_bkm_is_full()) {
      bra_dlg_create_dlg (MsfError,
                            BRA_STR_ERR_BKM_FULL, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
    } else {
      while (MSF_REGISTRY_RESPONSE_GET_NEXT(data_hdl, &p)) {
        if (p.path == NULL)    
          continue;

        if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BOOKMARK]) == 0)
          bra_prs_handle_ota_bookmark_item (data_hdl, &p);
      }
      bra_cmn_saved_dialog();
    }
  }
#ifdef BRA_CFG_CANCEL_PROV_CONF
  else {
    bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
    return;
  }
#endif
  bra_prs_delete_and_continue();
}

#ifdef BRA_CFG_CANCEL_PROV_CONF
static void bra_prs_cancel_prov_response(MsfActionType response)
{
  
  if (response==MsfOk)
  {
    if (bra_prs_current_window_type == 2)
    {
      bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PROFILE_SELECT_MENU);
      bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_NET_ID_SELECT_MENU);
    }

    bra_prs_handle_destroy_ui();
  }
  else
  {
    if (bra_prs_current_window_type == 1)
      bra_prs_instal_dialog();
  }
}
#endif

static void 
bra_prs_instal_dialog (void)
{
  void *data = bra_prs_data_queue[bra_prs_data_queue_current_item];
  MsfStringHandle ms;


  /* get SIM id before to show the install new setting dialog */

#ifdef BRA_CFG_CANCEL_PROV_CONF
  bra_prs_current_window_type = 1;
#endif
  switch (bra_prs_pinned_prov.stage) {
    case BRA_PRS_NEW_PINNED_PROV_STAGE_NULL:

        bra_prs_set_parsed_sim_id(bra_prs_parse_sim_id(data));   

        bra_prs_handled_items_cnt = 0;
        bra_prs_setting_type = bra_prs_get_setting_type(data);
#ifdef BRA_CFG_PROV_MULTI_BEARER
        bra_prs_bearer = bra_prs_get_firstN_setting_bearers(data, bra_prs_bearers_list, 0, BRA_PRS_MAX_NBR_BEARERS);
        if (bra_prs_bearer==BRA_PRS_MULTI_BEARER && bra_prs_bearers_list[0]==bra_prs_bearers_list[1])
          bra_prs_bearer = bra_prs_bearers_list[0];
#else
        bra_prs_bearer = bra_prs_get_setting_bearer(data);
#endif
        if (bra_prs_setting_type == BRA_PRS_MMS_SETTING)
        {
#ifdef BRA_CFG_DUAL_SIM
          if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM1)
            ms = BRA_STR_PRS_SIM1_MMS_INSTALL;
          else if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM2)
              ms = BRA_STR_PRS_SIM2_MMS_INSTALL;
          else
#endif /* BRA_CFG_DUAL_SIM */
            ms = BRA_STR_PRS_MMS_INSTAL;
        }
        else if (bra_prs_setting_type == BRA_PRS_BOOKMARK_SETTING)
        {
            ms = BRA_STR_PRS_BOOKMARK_INSTAL;
        }
        else
        {
#ifdef BRA_CFG_DUAL_SIM
          if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM1)
            ms = BRA_STR_PRS_SIM1_WAP_INSTALL;
          else if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM2)
            ms = BRA_STR_PRS_SIM2_WAP_INSTALL;
          else
#endif /* BRA_CFG_DUAL_SIM */
            ms = BRA_STR_PRS_WAP_INSTAL;
        }
        if (bra_prs_setting_type == BRA_PRS_BOOKMARK_SETTING)
        {
          bra_dlg_create_dlg (MsfConfirmation,
                              ms, 
                              BRA_STR_OK, 
                              BRA_STR_CANCEL,
                              0, 
                              bra_prs_instal_response_bookmark);
        }
        else
        {
          bra_dlg_create_dlg (MsfConfirmation,
                              ms, 
                              BRA_STR_OK, 
                              BRA_STR_CANCEL,
                              0, 
                              bra_prs_instal_response);
        }
        break;

    case BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT:
    
        bra_prs_set_parsed_sim_id(bra_prs_pinned_prov.sim_id);
            
#ifdef BRA_CFG_DUAL_SIM
        if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM1)
            ms = BRA_STR_PRS_SIM1_INSTALL;
        else if (bra_prs_get_parsed_sim_id() == BRA_SIM_ID_SIM2)
            ms = BRA_STR_PRS_SIM2_INSTALL;
        else
#endif /* BRA_CFG_DUAL_SIM */
          ms = BRA_STR_PRS_INSTAL;
        bra_dlg_create_dlg (MsfConfirmation,
                            ms, 
                            BRA_STR_OK, 
                            BRA_STR_CANCEL,
                            0, 
                            bra_prs_instal_response_pinned_prov);
  }
}

static void
bra_prof_select_profile_done (void)
{
   if (bra_prs_bearer==BRA_PRS_GSM_BEARER || bra_prs_bearer==BRA_PRS_GPRS_BEARER) {
#ifdef __CS_SERVICE__
   if(bra_prs_bearer == BRA_PRS_GSM_BEARER
      && bra_prs_gsm_state == BRA_PRS_NULL)
   {  
      bra_prs_get_free_gsm_profile_req();    
      return;
   }
#endif

#ifdef __PS_SERVICE__
   if(bra_prs_bearer == BRA_PRS_GPRS_BEARER
      && bra_prs_gprs_state == BRA_PRS_NULL)  
   {      
      bra_prs_get_free_gprs_profile_req();    
      return;
   }
#endif
   }    /* end if(bra_prs_bearer==BRA_PRS_GSM_BEARER || bra_prs_bearer==BRA_PRS_GPRS_BEARER) */
#ifdef BRA_CFG_PROV_MULTI_BEARER
   else /* BRA_PRS_MULTI_BEARER */
   {
      if(bra_prs_data_queue_size <= 0) /* in case of WAP reset */
        return;
      /* both __PS_SERVICE__ and __CS_SERVICE__ must be on if BRA_CFG_PROV_MULTI_BEARER is on */
      //if(bra_prs_gsm_state==BRA_PRS_WAIT_FREE_ID_RSP && bra_prs_gprs_state==BRA_PRS_WAIT_FREE_ID_RSP)
      //{
        bra_prs_gprs_state = BRA_PRS_WAIT_SEND_SET_REQ;
        bra_prs_gsm_state = BRA_PRS_WAIT_SEND_SET_REQ;

        /* initialize selected profile */
        bra_cmn_set_local_hompage_title (BRA_STRCONV(""));  
        bra_prs_increase_items_cnt();  
        bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE, "", bra_prs_decrease_items_cnt);
        bra_prs_increase_items_cnt();
        bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, "", bra_prs_decrease_items_cnt);
        bra_prs_increase_items_cnt();
        bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_UID, "", bra_prs_decrease_items_cnt);
        bra_prs_increase_items_cnt();
        bra_prof_change_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PWD, "", bra_prs_decrease_items_cnt);
        bra_prs_continue(bra_prs_data_queue[bra_prs_data_queue_current_item]);
        return;
      //}
   }
#endif /* BRA_CFG_PROV_MULTI_BEARER */

   bra_prs_delete_and_continue();
}

static void
bra_prs_delete_net_id_menu (bra_win_t *win)
{
  bra_prs_set_menu_t *p;
  p = (bra_prs_set_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (bra_prs_set_net_ids);

  BRA_FREE (p);
}

static void 
bra_prs_action_net_id_menu (bra_win_t *win, MsfActionHandle bra_action)
{
  bra_prs_set_menu_t *p;
  int i = 0;

  p = (bra_prs_set_menu_t *)(win);

	if (bra_action == p->accept){
    while (i < bra_prs_set_net_ids->n_items)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
      {
#ifdef BRA_CFG_PROV_MULTI_BEARER
        if (bra_prs_bearer == BRA_PRS_MULTI_BEARER)
        {
          if (bra_prs_bearers_list[0] == bra_prs_crt_netid_menu_type) {
            data_acct_id[0] = bra_prs_set_net_ids->net_ids[i];

            if (bra_prs_crt_netid_menu_type == BRA_PRS_GSM_BEARER) {
              if(data_acct_id[0] >= MAX_CSD_PROFILE_NUM)
                data_acct_id[0] -= MAX_CSD_PROFILE_NUM;
            } else if (bra_prs_crt_netid_menu_type == BRA_PRS_GPRS_BEARER) {
              if(data_acct_id[0] < MAX_CSD_PROFILE_NUM)
                data_acct_id[0] += MAX_CSD_PROFILE_NUM;
            }
          } else {
            data_acct_id[1] = bra_prs_set_net_ids->net_ids[i];

            if (bra_prs_crt_netid_menu_type == BRA_PRS_GSM_BEARER) {
              if(data_acct_id[1] >= MAX_CSD_PROFILE_NUM)
                data_acct_id[1] -= MAX_CSD_PROFILE_NUM;
            } else if (bra_prs_crt_netid_menu_type == BRA_PRS_GPRS_BEARER) {
              if(data_acct_id[1] < MAX_CSD_PROFILE_NUM)
                data_acct_id[1] += MAX_CSD_PROFILE_NUM;
            }
          }
        }
        else
          data_acct_id[0] = bra_prs_set_net_ids->net_ids[i];
#else
        data_acct_id = bra_prs_set_net_ids->net_ids[i];
#endif
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
#ifdef BRA_CFG_PROV_MULTI_BEARER
        if (bra_prs_bearer!=BRA_PRS_MULTI_BEARER || bra_prs_crt_netid_menu_type==BRA_PRS_GSM_BEARER)
          bra_prof_select_profile_done();
        else
        {
          bra_prs_crt_netid_menu_type = BRA_PRS_GSM_BEARER;
          bra_prs_create_net_id_menu();
        }
#else
        bra_prof_select_profile_done();
#endif
        return;
      }
      i++;
    }
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if(bra_action == p->back)
  {
#ifdef BRA_CFG_CANCEL_PROV_CONF
    bra_prs_current_window_type = 2;
    bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
#else
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);    
    bra_prs_delete_and_continue();
#endif
  }
}

static void 
bra_prs_create_net_id_menu (void)
{
  bra_prs_set_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MSF_INT32 net_id;
  MSF_INT32 current_net_id;
  MsfStringHandle ms;
  char namebuf[128];
  int i = 0;
  MsfDeviceProperties prop;
  MSF_UINT8 selected = FALSE;
  MSF_UINT8 type;

#ifdef BRA_CFG_PROV_MULTI_BEARER
  if(bra_prs_bearer == BRA_PRS_GPRS_BEARER ||
     (bra_prs_bearer==BRA_PRS_MULTI_BEARER &&
      bra_prs_crt_netid_menu_type==BRA_PRS_GPRS_BEARER))
#else
  if(bra_prs_bearer == BRA_PRS_GPRS_BEARER)
#endif
    type = HDI_SOCKET_BEARER_GSM_GPRS;
  else
    type = HDI_SOCKET_BEARER_GSM_CSD;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_prs_set_menu_t);

  win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
  win->back = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_CANCEL, MsfBack, 3, 0x8000);
  win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfExclusiveChoice,
                                       &prop.displaySize,
                                       win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

	MSF_WIDGET_SET_TITLE (win->window,BRA_STR_SET_NET_ID);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);


   net_id = HDIa_networkAccountGetFirst();

   if (net_id < 0)
   {
      bra_dlg_create_dlg (MsfError,
                          BRA_STR_SET_NO_NET_IDS, 
                          BRA_STR_OK, 
                          0,
                          0, 
                          NULL);
      return;
   }

   bra_prs_set_net_ids = BRA_ALLOCTYPE(bra_prs_set_net_id_t);
   bra_prs_set_net_ids->n_items = 0;
#if defined(BRA_CFG_PROV_MULTI_BEARER) && defined(BRA_CFG_PROF_FALLBACK)
   if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL) == 1)
   {
     if (type == HDI_SOCKET_BEARER_GSM_GPRS)
       current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS);
     else
       current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM);
   }
   else
     current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
#else
   current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);   
#endif

   current_net_id = (MSF_UINT32)always_ask_get_original_id_data_account((kal_uint32)current_net_id);

   while (net_id >= 0)
   {
     if(HDIa_networkAccountGetBearer(net_id) != type)
     {
       net_id = HDIa_networkAccountGetNext (net_id);
       continue;
     }
     
     if (bra_prs_set_net_ids->n_items >= BRA_CFG_ONE_BEARER_MAX_NET_ID_NUM)
       break;

     bra_prs_set_net_ids->n_items++;
     bra_prs_set_net_ids->net_ids[i] = net_id;

     memset(namebuf, 0, sizeof(namebuf));
     if (HDIa_networkAccountGetName(net_id , namebuf, sizeof(namebuf)) >= 0)
       ms = BRA_STRCONV(namebuf);
     else
       ms = BRA_STR_SET_DEF_NET_ID;

     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, ms, 0, 0, 0, TRUE); 

     if (current_net_id == (MSF_UINT32)always_ask_get_original_id_data_account((kal_uint32)net_id))
     {
       MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (i - 1), MSF_CHOICE_ELEMENT_SELECTED);
       selected = TRUE;
     }

     MSF_WIDGET_RELEASE (ms);
     net_id = HDIa_networkAccountGetNext (net_id);
   }

    /*if (selected == FALSE)
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 0, MSF_CHOICE_ELEMENT_SELECTED);*/

	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->accept);
	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->back);

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_NET_ID_SELECT_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_prs_delete_net_id_menu, 
                    NULL,
                    bra_prs_action_net_id_menu);

#ifdef BRA_CFG_PROV_MULTI_BEARER
  if (bra_prs_bearer==BRA_PRS_MULTI_BEARER)
  {
    if (bra_prs_crt_netid_menu_type==BRA_PRS_GPRS_BEARER)
      bra_dlg_create_dlg (MsfInfo, BRA_STR_SELECT_GPRS, BRA_STR_OK, 0, 0, 0);
    else
      bra_dlg_create_dlg (MsfInfo, BRA_STR_SELECT_GSM_CSD, BRA_STR_OK, 0, 0, 0);
  }
#endif

}

/*Select profile menu*/
static void 
bra_delete_profile_menu (bra_win_t *win)
{
  bra_prs_profile_select_menu_t *p;
  /*First retrieve the window structure*/
  p = (bra_prs_profile_select_menu_t *)(win);

  /*Remove the window from the screen*/
 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

  /*Release all widgets*/
  MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->select);
	MSF_WIDGET_RELEASE (p->back);

  /*Finally dealloc the window structure*/
  BRA_FREE (p);
}

static void
bra_action_profile_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_prs_profile_select_menu_t *p;
  int i;
  int profile_no;

  /*First retreive the window structure*/  
  p = (bra_prs_profile_select_menu_t *)(win);

  /*Check this was the Accept action*/
	if (bra_action == p->select)
	{
     if(bra_prs_setting_type == BRA_PRS_WAP_SETTING)
       profile_no = BRA_PROF_GET_PROF_NUM(BRA_PROF_ID_BRA);
     else
       profile_no = BRA_PROF_GET_PROF_NUM(BRA_PROF_ID_MMS);

    /*The Accept action was enabled. Now findout which menu item that was selected*/
    for (i = 0; i < profile_no; i++)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        if(bra_prs_setting_type == BRA_PRS_WAP_SETTING)
          bra_prof_set_sim_selected_profile (BRA_PROF_ID_BRA, bra_prs_get_parsed_sim_id(), BRA_PROF_GET_PROF_IDX(BRA_PROF_ID_BRA, i), bra_prs_create_net_id_menu);
        else
          bra_prof_set_sim_selected_profile (BRA_PROF_ID_MMS, bra_prs_get_parsed_sim_id(), BRA_PROF_GET_PROF_IDX(BRA_PROF_ID_MMS, i), bra_prs_create_net_id_menu);        
        return;
      }
    }
	}	  
  else if (bra_action == p->back)
  {
    /*Abort Instalation?*/
    
    //by kevin
    //bra_dlg_status_dialog_close();
#ifdef BRA_CFG_CANCEL_PROV_CONF
    bra_prs_current_window_type = 2;
    bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
#else
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    bra_prs_delete_and_continue();
#endif
    return;
  }

  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

}

/*
 * This function create and display a menu where the user can select the   
 * active profile
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
static void 
bra_prs_create_prof_sel_menu (void)
{
  bra_prs_profile_select_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  bra_prof_names_t *p;
  int i;
  MsfDeviceProperties prop;  

  /*remove menu key action from screen*/
  bra_view_disable ();  

  /*Get Device properties. e.g. the screen size since this can be dynamicaly changed*/
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  /*Allocate memory for the structure to hold the window and action handles
    If other static variables are needed these can be added to the menu type.
    Note thoug that the first item must be the window handle*/
  win = BRA_ALLOCTYPE (bra_prs_profile_select_menu_t);
  /*Create the Back and Accept action handle*/
	win->select = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                                     BRA_STR_ACCEPT,
                                                     MsfSelect,
                                                     1, 
                                                     0x8000);
	win->back   = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                                     BRA_STR_CANCEL,
                                                     MsfBack,
                                                     1, 
                                                     0x8000);
  /*Now create the actual menu window*/
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,MsfExclusiveChoice,
												                     &prop.displaySize,
												                     win->select,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);
  /*Set window title*/
	MSF_WIDGET_SET_TITLE (win->window,BRA_STR_SELECT_PROFILE);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_TITLE);

  /*Add the available profile names to the menu*/
  if(bra_prs_setting_type == BRA_PRS_WAP_SETTING)
    p = bra_prof_get_sim_all_profile_names (BRA_PROF_ID_BRA, bra_prs_get_parsed_sim_id());
  else
    p = bra_prof_get_sim_all_profile_names (BRA_PROF_ID_MMS, bra_prs_get_parsed_sim_id());

  for (i = 0; i < p->n_items; i++)
  {
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, p->s[i],  0, 0, 0, TRUE);
    MSF_WIDGET_RELEASE (p->s[i]);
  }

  BRA_FREE (p);
  /*Set Preselected menu item*/
  MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 0, MSF_CHOICE_ELEMENT_SELECTED);

  /*Add the previously created actions to the window*/
	MSF_WIDGET_ADD_ACTION (win->window, win->back);
	MSF_WIDGET_ADD_ACTION (win->window, win->select);

  /*Finally Show dialog. Note that the in focus parameter is NULL, i.e. this menu has no need
    to know if it is in focus or not.*/
  bra_win_show_window (BRA_WIN_ID_PROFILE_SELECT_MENU, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_profile_menu, 
                      NULL,
                      bra_action_profile_menu);
}


/******************************************************************************
 * Exported Functions
 *****************************************************************************/
void
bra_prs_init (void)
{
  bra_prs_data_queue_last_item    = 0; 
  bra_prs_data_queue_current_item = 0;
  bra_prs_data_queue_size         = 0;
  bra_prs_handled_items_cnt       = 0;
  
  memset(&bra_prs_pinned_prov, 0, sizeof(bra_prs_pinned_prov_t));
}

void 
bra_prs_terminate (void)
{
  while (bra_prs_data_queue_size > 0)
  {
    MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, bra_prs_data_queue[bra_prs_data_queue_current_item]);

    bra_prs_data_queue_size--;
    bra_prs_data_queue_current_item++;
    if (bra_prs_data_queue_current_item >= BRA_PRS_MAX_NBR_DOCUMENTS)
      bra_prs_data_queue_current_item = 0;
  }

  bra_prs_bearer = BRA_PRS_INVALID_BEARER;
  bra_prs_setting_type = BRA_PRS_WAP_SETTING;
  
#ifdef __CS_SERVICE__  
  if(set_csd_req)
  {         
     free_local_para((local_para_struct*)set_csd_req);
     set_csd_req = NULL;
  }
  bra_prs_gsm_state = BRA_PRS_NULL;
#endif


#ifdef __PS_SERVICE__  
  if(set_gprs_req)
  {         
     free_local_para((local_para_struct*)set_gprs_req);
     set_gprs_req = NULL;
  }
  bra_prs_gprs_state = BRA_PRS_NULL;
#endif

}

static void 
bra_prs_delete_and_continue (void)
{
  if(bra_prs_data_queue_size <= 0)
    return;

  MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, bra_prs_data_queue[bra_prs_data_queue_current_item]);
  bra_prs_bearer = BRA_PRS_INVALID_BEARER;
  bra_prs_setting_type = BRA_PRS_WAP_SETTING;
  bra_prs_data_queue_size--;
  bra_prs_data_queue_current_item++;
  if (bra_prs_data_queue_current_item >= BRA_PRS_MAX_NBR_DOCUMENTS)
    bra_prs_data_queue_current_item = 0;

  if (bra_prs_data_queue_size > 0)
  {
#ifdef WAP_SUPPORT
    // bra_prs_show_prov_dialog(); // 2004.05 deprecated by Justin 
    //bra_prs_install_prov();
    {
      if (bra_prs_is_bookmark_setting((void*)bra_prs_data_queue[bra_prs_data_queue_current_item]))
        HDIa_widgetExtRegisterNewProvision(WAP_SERVICE_ON_UNKNOWN_SIM);
      else
      {
        int sim_id = bra_prs_parse_sim_id((void*)bra_prs_data_queue[bra_prs_data_queue_current_item]);

        HDIa_widgetExtRegisterNewProvision(bra_prs_get_widget_sim_id(sim_id));
      }
    }
#else    
    TurnOnBacklight(1);	
    bra_prs_instal_dialog ();
#endif    
  }
  else
  {
//  bra_prof_set_selected_profile(BRA_PROF_ID_BRA, bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID), NULL);
    bra_prof_restore_bra_active_profile(TRUE);
  }
}

static void
bra_prs_instal_profile_done (void)
{
  //by kevin
  //bra_dlg_status_dialog_close ();

#ifdef __TCPIP__

   kal_bool wait_rsp = KAL_FALSE;

  /* send request to PS */

#ifdef __CS_SERVICE__

  if(set_csd_req != NULL      
     && bra_prs_gsm_state == BRA_PRS_WAIT_SEND_SET_REQ)  
  {
     if(set_csd_req->dest.type != 0xff)
     {
       wait_rsp = KAL_TRUE;
       bra_prs_set_gsm_profile_req();            
     }
     else
     {
       bra_prs_gsm_state = BRA_PRS_NULL;
       free_local_para((local_para_struct*)set_csd_req);
     }
  }

#endif /* __CS_SERVICE__ */

#ifdef __PS_SERVICE__

  if(set_gprs_req != NULL 
     && bra_prs_gprs_state == BRA_PRS_WAIT_SEND_SET_REQ)
  {
     if(set_gprs_req->gprs_account.apn_length != 0xff)
     {
       wait_rsp = KAL_TRUE;
       bra_prs_set_gprs_profile_req();      
     }
     else
     {
       bra_prs_gprs_state = BRA_PRS_NULL;
       free_local_para((local_para_struct*)set_gprs_req);
     }
  }

#endif /* __PS_SERVICE__ */

  if(wait_rsp == KAL_TRUE)
     return;

#endif /* __TCPIP__ */
 
  bra_prs_delete_and_continue ();

}

/*
 * This function continues the installation of provisioning data
 *
 * PARAMETERS
 *
 * data      : Provisioning data (msf_registry_response_t)
 *
 * RETURN    : void
 */
void 
bra_prs_continue (void *data)
{
  msf_registry_param_t p;
  msf_registry_response_t* data_hdl = (msf_registry_response_t*)data;
  char *s;

  if (MSF_REGISTRY_RESPONSE_GET_NEXT (data_hdl, &p))
  {
    if (p.path == NULL)
      return;

    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BOOKMARK]) == 0)
    {
      if (!bra_bkm_is_full())
        bra_prs_handle_ota_bookmark_item (data_hdl, &p);
    }    
    else if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_PROXY]) == 0
             || strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_PROXY]) == 0)
    {
      bra_prs_handle_proxy_item (&p);
    }
	else if (strcmp(p.path, prs_Str_resources[PRS_PATH_HOMEPAGE]) == 0)
	{
	  bra_prs_handle_homepage_item(&p);
	}
	else if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_APP]) == 0)
	{
	  bra_prs_handle_application_item(&p);
	}
#ifdef __TCPIP__
    /* setting for PS, eg, CSD/GPRS , added by Kevin */
    else if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BEARER]) == 0)
    {
      bra_prs_handle_ota_bearer_item (data_hdl, &p);
    }
    else if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_BEARER]) == 0)
    {
      bra_prs_handle_wap_bearer_item (data_hdl, &p);
    }
#endif /* __TCPIP__ */    

    BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_PRS_CONTINUE, data_hdl);
    return;
  }

  /* check if profile name exists, if no, use account name */
  s = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR);  
  if(!s || *s == 0)
  {
#ifdef __CS_SERVICE__
     if(set_csd_req)
     {
        if(set_csd_req->name.name_dcs == PHB_ASCII)
        {
           bra_prs_increase_items_cnt();
           bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, (char*)(set_csd_req->name.name), bra_prs_decrease_items_cnt); 
        }
        else if (set_csd_req->name.name_dcs == PHB_UCS2)
        {
           char *tmp;
           kal_int32 srcLen;
           kal_int32 destLen;

           srcLen = set_csd_req->name.name_length;
           destLen = widget_ucs2_length(set_csd_req->name.name)*3;
           tmp = BRA_ALLOC(destLen+1);
           kal_mem_set(tmp, 0, destLen+1);

           msf_charset_ucs2be_to_utf8 ((const char*)set_csd_req->name.name, (long *)&srcLen, (char *)tmp, (long *)&destLen);
           bra_prs_increase_items_cnt();
           bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, tmp, bra_prs_decrease_items_cnt); 

           BRA_FREE(tmp);
        }
     }
#endif

#ifdef __PS_SERVICE__
     if(set_gprs_req)
     {
        if(set_gprs_req->gprs_account.name_dcs == PHB_ASCII)
        {
           bra_prs_increase_items_cnt();
           bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, (char*)(set_gprs_req->gprs_account.name), bra_prs_decrease_items_cnt); 
        }
        else if (set_gprs_req->gprs_account.name_dcs == PHB_UCS2)
        {
           char *tmp;
           kal_int32 srcLen;
           kal_int32 destLen;

           srcLen = set_gprs_req->gprs_account.name_length;
           destLen = widget_ucs2_length(set_gprs_req->gprs_account.name)*3;
           tmp = BRA_ALLOC(destLen+1);
           kal_mem_set(tmp, 0, destLen+1);

           msf_charset_ucs2be_to_utf8 ((const char*)set_gprs_req->gprs_account.name, (long *)&srcLen, (char *)tmp, (long *)&destLen);
           bra_prs_increase_items_cnt();
           bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR, tmp, bra_prs_decrease_items_cnt); 

           BRA_FREE(tmp);
        }
     }
#endif
  }

  /*Make sure that all items have been added to the profile before terminating*/
  if (bra_prs_handled_items_cnt <= 0)//kevin
  {
#ifndef __PRODUCTION_RELEASE__
     ASSERT(bra_prs_handled_items_cnt == 0);
#endif

     /* save data account id */
     //bra_prs_increase_items_cnt();
#ifdef BRA_CFG_PROF_FALLBACK
     bra_prs_increase_items_cnt();
     bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL, 0, bra_prs_decrease_items_cnt);
#endif  /* BRA_CFG_PROF_FALLBACK */

     /* In dual SIM mode, the net id to changed should be the extend net id, 
      * because the bra_prof_change_key_int_value() need to abstract the ask flag and 
      * here we just regard the data_acct_id is in extend net id mode and the ask flag is FALSE
      * it' ok for us to do this.
     */
#ifdef BRA_CFG_PROV_MULTI_BEARER    /* multi_bearer defined means prof_fallback also defined! */
     if (bra_prs_bearer == BRA_PRS_MULTI_BEARER)
     {
        if (bra_prs_bearers_list[0] == BRA_PRS_GSM_BEARER) {
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA,
                                         BRA_PROF_KEY_NET_ID_GSM,
                                         data_acct_id[0], 0);
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA,
                                         BRA_PROF_KEY_NET_ID_GPRS,
                                         data_acct_id[1], 0);
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                         BRA_PROF_KEY_NET_ID, 
                                         data_acct_id[1], 0);
        } else {
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA,
                                         BRA_PROF_KEY_NET_ID_GSM,
                                         data_acct_id[1], 0);
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA,
                                         BRA_PROF_KEY_NET_ID_GPRS,
                                         data_acct_id[0], 0);
          bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                         BRA_PROF_KEY_NET_ID, 
                                         data_acct_id[0], 0);
        }
        bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL, 1, bra_cmn_save_done_dialog);
     }
     else
        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                       BRA_PROF_KEY_NET_ID, 
                                       data_acct_id[0], bra_cmn_save_done_dialog/*bra_prs_decrease_items_cnt*/);
#else
     bra_prof_change_key_int_value (BRA_PROF_ID_BRA, 
                                    BRA_PROF_KEY_NET_ID, 
                                    data_acct_id, bra_cmn_save_done_dialog/*bra_prs_decrease_items_cnt*/);                
#endif
     bra_prs_instal_profile_done ();
  }
  else
  {    
    BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_PRS_CONTINUE, data_hdl);
  }
}

void
bra_prs_send_msg_to_mmi(kal_uint16 msg_id,
                       local_para_struct *local_para_ptr,
                       peer_buff_struct  *peer_buff_ptr)
{
   ilm_struct *ilm = allocate_ilm( MOD_WAP ) ;

   ASSERT( ilm != NULL );
     
   ilm->dest_mod_id = MOD_MMI;
   ilm->local_para_ptr = local_para_ptr;
   ilm->peer_buff_ptr  = peer_buff_ptr;
   ilm->sap_id         = WAP_MMI_SAP;
   ilm->msg_id         = msg_id;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm);
} /* end of bra_prs_send_msg_to_mmi */

#ifdef WAP_SUPPORT  
      
void bra_prs_show_prov_dialog(void)
{ 
   /* in case of some scenarios (eg, in-call), MMI doesn't like to be disturbed,
    * thus we register an action to MMI, once MMI allows to be interrupted (eg, call ends),
    * MMI will notify WAP, then we propmt a dialog to ask user to install or not 
    */	   
#if 0 // 2004.05.10 Removed by Justin
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
#else
   if (bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_NULL || 
       bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT)
   {
     if (bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT)
       HDIa_widgetExtRegisterNewProvision(bra_prs_get_widget_sim_id(bra_prs_pinned_prov.sim_id));   
     else
     {
       if (bra_prs_is_bookmark_setting((void*)bra_prs_data_queue[bra_prs_data_queue_current_item]))
         HDIa_widgetExtRegisterNewProvision(WAP_SERVICE_ON_UNKNOWN_SIM);
       else
       {
         int sim_id = bra_prs_parse_sim_id((void*)bra_prs_data_queue[bra_prs_data_queue_current_item]);
       
         HDIa_widgetExtRegisterNewProvision(bra_prs_get_widget_sim_id(sim_id));   
       }
     }
   }
   else
   {
       void *data = bra_prs_data_queue[bra_prs_data_queue_current_item];
       bra_prs_handled_items_cnt = 0;
       bra_prs_setting_type = bra_prs_get_setting_type(data);
#ifdef BRA_CFG_PROV_MULTI_BEARER
       bra_prs_bearer = bra_prs_get_firstN_setting_bearers(data, bra_prs_bearers_list, 0, BRA_PRS_MAX_NBR_BEARERS);
       if (bra_prs_bearer==BRA_PRS_MULTI_BEARER && bra_prs_bearers_list[0]==bra_prs_bearers_list[1])
         bra_prs_bearer = bra_prs_bearers_list[0];
#else
       bra_prs_bearer = bra_prs_get_setting_bearer(data);
#endif

       bra_prs_set_parsed_sim_id(bra_prs_parse_sim_id(data));   

       bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
       bra_prs_instal_response(MsfOk);  // PRS completed pin input + doc parsing,
                                        // continuing prov install process
   }

#endif
} /* end of bra_prs_show_prov_dialog */

void bra_prs_install_prov(void)
{
   if (bra_prs_data_queue_size > 0 || bra_prs_pinned_prov.stage == BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT)
   {      
      // bra_prs_show_prov_dialog();   
      bra_prs_instal_dialog();
   }
}

static int
bra_prs_validate_proxy_addr (void *data)
{
  int i, j;
  char ipaddr[128] = "";
  char ch;

  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  
  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_PROXY]) == 0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_PX_ADDRESS]) == 0)
      {
        /* discard unwanted trailing */
        for(i = 0, j = 0; i < strlen((char *)p.value_bv); i++)
		{
          ch = (char)*(p.value_bv + i);
          if((ch >= '0' && ch <= '9') || ch == '.')
            ipaddr[j++] = ch;
          else
            break;
        }

        ipaddr[j] = '\0';
        return check_ip(ipaddr);
      }
    }
  }
  return 1;
}

static int
bra_prs_get_setting_conntype (void *data)
{
  int conntype = -1;
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  
  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.key, prs_Str_resources[PRS_STR_PX_SERVICE]) == 0)
    {
      switch (p.value_i)
      {
          case PRS_VAL_WAP_CL_WSP:
          case PRS_VAL_WAP_CL_SEC_WSP:
              return BRA_SET_CONNECTION_TYPE_WSP_CL;

          case PRS_VAL_WAP_CO_WSP:
          case PRS_VAL_WAP_CO_SEC_WSP:
              return BRA_SET_CONNECTION_TYPE_WSP_CO;

          case PRS_VAL_WAP_OTA_HTTP_TO:
          case PRS_VAL_WAP_OTA_HTTP_PO:
          case PRS_VAL_WAP_OTA_HTTP_TLS_TO:
          case PRS_VAL_WAP_OTA_HTTP_TLS_PO:
              return BRA_SET_CONNECTION_TYPE_HTTP;
      }
    } 
    else if (strcmp(p.key, prs_Str_resources[PRS_STR_PX_PORT]) == 0)
    {
      switch ( (p.type==MSF_REGISTRY_TYPE_STR?atoi((char*)p.value_bv):p.value_i) )
      {
          case 9200:  /* WSP_CL */
              conntype = BRA_SET_CONNECTION_TYPE_WSP_CL;
              break;

          case 9202:  /* WSP_CL_SEC */
              conntype = BRA_SET_CONNECTION_TYPE_WSP_CL;
              break;

          case 9201:  /* WSP_CO */
              conntype = BRA_SET_CONNECTION_TYPE_WSP_CO;
              break;

          case 9203:  /* WSP_CO_SEC */
              conntype = BRA_SET_CONNECTION_TYPE_WSP_CO;
      }
    }
  }
  return conntype<0?BRA_SET_CONNECTION_TYPE_HTTP:conntype;
}

static int
bra_prs_validate_auth_type (void *data)
{
  unsigned char *strType;
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;

  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_BEARER])==0 || strcmp(p.path, prs_Str_resources[PRS_PATH_OTA_BEARER])==0)
    {
      if (strcmp(p.key, prs_Str_resources[PRS_STR_PPP_AUTHTYPE]) == 0)
      {
        if (p.type==1 && p.value_bv_length>0) {
          strType = (unsigned char*)BRA_ALLOC(p.value_bv_length+1);
          kal_mem_cpy(strType, p.value_bv, p.value_bv_length);
          strType[p.value_bv_length] = 0;
        } else {
          strType = 0;
        }

        if (!((strType && msf_cmmn_strcmp_nc((char*)strType, "PAP")==0) ||
            (!strType && p.value_i == PRS_VAL_BR_PAP) ||
            (strType && msf_cmmn_strcmp_nc((char*)strType, "CHAP")==0) ||
            (!strType && p.value_i == PRS_VAL_BR_CHAP)))
        {
          BRA_FREE(strType);
          return 0;
        }
      }
    }
  }
  return 1;
}

static int
bra_prs_validate_appid (void *data)
{
  /* 0=unsupported, 1=browser, 2=mms */
  int hasInvalidID;
  msf_registry_response_t data_hdl = *((msf_registry_response_t*)data);
  msf_registry_param_t p;
  
  hasInvalidID = 0;
  while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
  {
    if (p.path == NULL)    
      continue;        
    
    if (strcmp(p.path, prs_Str_resources[PRS_PATH_WAP_APP])==0 && strcmp(p.key, prs_Str_resources[PRS_STR_WAP_APP_APPID])==0)
    {
        if (strstr((const char*)p.value_bv, "w4"))
            return 2;
		else if(strstr((const char*)p.value_bv, "w2"))
            return 1;
        else
            hasInvalidID = 1;
    } 
  }
  return !hasInvalidID;
}

static int
bra_prs_validate_bearer (void *data)
{
#ifdef BRA_CFG_PROV_MULTI_BEARER
  /* 0=invalid, 1=bearer --> invalid --> 0
   * 0=bearer, 1=invalid/none --> bearer --> 1
   * 0=GPRS, 1=GPRS --> multi --> 1
   * 0=GSM, 1=GSM --> multi --> 1
   * 0=GPRS/GSM, 1=GSM/GPRS --> multi --> 2
   */

  int bearer;
  int bearers_list[2];

  bearer = bra_prs_get_firstN_setting_bearers(data, bearers_list, 0, 2);

  /* only 1GSM + 1GPRS bearer is supported currently */
  /* we still allow 2 equal bearers, but only first one will be used */
  if (bearer!=BRA_PRS_MULTI_BEARER || bearers_list[0]==bearers_list[1])
    return bearer!=BRA_PRS_INVALID_BEARER;
  return 2;

#else
  return (bra_prs_get_setting_bearer(data)!=BRA_PRS_INVALID_BEARER);

#endif
}

#endif /* WAP_SUPPORT */

/*
 * This functin is called when the BRA module receives provisioining data.
 * This function will display a sequence of dialogs asking the user to 
 * confirm the installation of the provisioning data and to select a profile
 * to install the data in. When this is finished the handling of the data will
 * begin. After an item have been processed a signal to continue will be sent
 * and received in the above function. If the user cancels the installation 
 * process the data will be destroyed
 *
 * PARAMETERS
 *
 * data      : Provisioning data (msf_registry_response_t)
 *
 * RETURN    : void
 */
void
bra_prs_handle_provisining_data (void *data)
{  
  int conntype;
  int contentSupported;
  int validContent;
  int num_bearers;
  int appid;
  
  contentSupported = 1;
  validContent = 1;
  num_bearers = 0;
  
  if (!bra_prs_is_bookmark_setting(data))
  {
    if((num_bearers=bra_prs_validate_bearer(data)) == 0)
    {
      /* non-support setting */
      MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
      contentSupported = 0;
    }
        
#ifdef WAP_SUPPORT
    else if(bra_prs_validate_proxy_addr(data) == 0)
    {
      /* Invalid Proxy address */
      MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
      validContent = 0;
    }
    else if((conntype = bra_prs_get_setting_conntype(data)) < 0 || conntype == BRA_SET_CONNECTION_TYPE_WSP_CL)
    {
      /* unsupported connection type */
      MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
      contentSupported = 0;
    }
    else if(bra_prs_validate_auth_type(data) == 0)
    {
      /* unsupported NAP authentication type */
      MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
      contentSupported = 0;
    }
    else if((appid=bra_prs_validate_appid(data)) == 0 || (appid==2 && num_bearers>1))
    {
      /* unsupported application ID or MMS with multiple bearers*/
      MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
      contentSupported = 0;
    }

    if (!contentSupported) {
      /* if OMA Provisioning */
      //if (bra_prs_pinned_prov.stage == BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF)
      //{
          bra_prs_handle_invalid_prov(0);
      //}
      return;
    } else if (!validContent) {
        bra_prs_handle_invalid_prov(1);
        return;
    }
#endif
  }

  if (bra_prs_data_queue_size == BRA_PRS_MAX_NBR_DOCUMENTS)
  {
    /*Queue is full*/
    MSF_REGISTRY_RESPONSE_FREE (MSF_MODID_BRA, data);
    return;
  }

  if (bra_prs_data_queue_last_item >= BRA_PRS_MAX_NBR_DOCUMENTS)
  {
    bra_prs_data_queue_last_item = 0;
  }

  bra_prs_data_queue[bra_prs_data_queue_last_item] = data;
  bra_prs_data_queue_last_item++;
  bra_prs_data_queue_size++;

  if (bra_prs_data_queue_size ==  1)
  {
#ifdef WAP_SUPPORT  

     bra_prs_show_prov_dialog();

#else
             	
    /*If there is only one element in the queue then install.
      if there are more elements wait for previous to finish.*/
    bra_prs_instal_dialog ();
    
#endif /* WAP_SUPPORT */
  }
}

int bra_prs_if_instal_dialog_exist(void)
{
   return (bra_prs_is_insall_new_setting_string(bra_dlg_top_dialog_text())
           || bra_dlg_top_dialog_text() == BRA_STR_CANCEL_PROV
           || bra_win_get_window(BRA_WIN_ID_PROFILE_SELECT_MENU)
           || bra_win_get_window(BRA_WIN_ID_NET_ID_SELECT_MENU)
           || bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF);
}

void bra_prs_handle_destroy_ui(void)
{
  if (bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT)
  {
#ifdef BRA_CFG_CANCEL_PROV_CONF
    HDIc_widgetAction(MSF_MODID_PRS, bra_prs_pinned_prov.dlgHandle, bra_prs_pinned_prov.noHandle);
    bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
#else
    bra_prs_instal_response_pinned_prov(MsfCancel);
#endif
    return;
  }

  if (bra_prs_pinned_prov.stage==BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF)
  {
    bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
    HDIc_widgetAction(MSF_MODID_PRS, bra_prs_pinned_prov.dlgHandle, bra_prs_pinned_prov.noHandle);
    return;
  }

  bra_prs_delete_and_continue();
}


void bra_prs_notify_pinned_prov(void *sig) {
    bra_prs_pinned_prov_t *param;
    param = (bra_prs_pinned_prov_t*)sig;

    bra_prs_pinned_prov.dlgHandle = param->dlgHandle;
    bra_prs_pinned_prov.yesHandle = param->yesHandle;
    bra_prs_pinned_prov.noHandle = param->noHandle;
    bra_prs_pinned_prov.stage = param->stage;
    bra_prs_pinned_prov.sim_id = param->sim_id;

    switch (bra_prs_pinned_prov.stage) {
      case BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT:
        bra_prs_show_prov_dialog();     // show New Setting popup + Install Setting Confirmation
        break;

      case BRA_PRS_NEW_PINNED_PROV_STAGE_ABORT:
        bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
        break;
    }
}

void bra_prs_handle_invalid_prov(int type) {
    MsfStringHandle hStr;

    switch (type) {
      case 0:   // unsupported content
        hStr = BRA_STR_UNSUPPORT_PROV;
        break;
      case 1:   // invalid setting
        hStr = BRA_STR_INVALID_PROV;
        break;
      case 2:   // auth failed
        hStr = BRA_STR_AUTH_FAILED;
        break;
      default:
        hStr = BRA_STR_INVALID_PROV;
    }

    //if (bra_prs_pinned_prov.stage != BRA_PRS_NEW_PINNED_PROV_STAGE_NULL) {
        HDIa_widgetExtForcePopup(hStr, MsfError, 0);
        bra_prs_pinned_prov.stage = BRA_PRS_NEW_PINNED_PROV_STAGE_NULL;
    //}
}

void
bra_prs_register_prov_auth(void *sig) {
    bra_prs_pinned_prov_t *param;
    param = (bra_prs_pinned_prov_t*)sig;

    if (bra_prs_pinned_prov.stage == BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF) {
        bra_prs_pinned_prov.dlgHandle = param->dlgHandle;
        bra_prs_pinned_prov.noHandle = param->noHandle;
    }
}

void
bra_prs_cancel_prov_conf(void) {
#ifdef BRA_CFG_CANCEL_PROV_CONF
    bra_prs_current_window_type = 3;
    MSF_WIDGET_SET_IN_FOCUS(bra_win_get_screen(), 1);

    bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CANCEL_PROV, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_prs_cancel_prov_response);
#endif
}


int
bra_prs_get_bra_sim_id(int prs_sim_id)
{
    int bra_sim_id = 0;
 
#ifdef BRA_CFG_DUAL_SIM
    
    if (prs_sim_id == PRS_VAL_SIM_1)
        bra_sim_id = BRA_SIM_ID_SIM1;
    else if (prs_sim_id == PRS_VAL_SIM_2)
        bra_sim_id = BRA_SIM_ID_SIM2;
    else
        bra_sim_id = BRA_SIM_ID_SIM1;
#endif

    return bra_sim_id;
}


static int
bra_prs_parse_sim_id(void *data)
{
    msf_registry_param_t    p;
    msf_registry_response_t data_hdl;
    int                     sim_id = PRS_VAL_SIM_1;


    data_hdl = *((msf_registry_response_t*)data);
    while (MSF_REGISTRY_RESPONSE_GET_NEXT (&data_hdl, &p))
    {
        if (p.path == NULL)    
            continue;        

        if (strcmp(p.path, prs_Str_resources[PRS_PATH_MTK_INFO]) == 0)
        {
            if (strcmp(p.key, prs_Str_resources[PRS_STR_MTK_SIM_ID]) == 0)
            {
                sim_id = p.value_i;
                break;
            }
        }
    }
    return bra_prs_get_bra_sim_id(sim_id);
}


static int
bra_prs_get_parsed_sim_id(void)
{
#ifdef BRA_CFG_DUAL_SIM
  return bra_prs_sim_id;
#else
  return 0;
#endif
}


static void
bra_prs_set_parsed_sim_id(int bra_sim_id)
{
#ifdef BRA_CFG_DUAL_SIM
  bra_prs_sim_id = bra_sim_id;
#endif
}


int
bra_prs_is_insall_new_setting_string(MsfStringHandle text)
{
  if (text == BRA_STR_PRS_MMS_INSTAL ||
      text == BRA_STR_PRS_WAP_INSTAL ||
      text == BRA_STR_PRS_BOOKMARK_INSTAL ||
      text == BRA_STR_PRS_INSTAL)
  {
    return TRUE;
  }
  
#ifdef BRA_CFG_DUAL_SIM
  if (text == BRA_STR_PRS_SIM1_INSTALL ||
      text == BRA_STR_PRS_SIM2_INSTALL ||
      text == BRA_STR_PRS_SIM1_WAP_INSTALL ||
      text == BRA_STR_PRS_SIM2_WAP_INSTALL ||
      text == BRA_STR_PRS_SIM1_MMS_INSTALL ||
      text == BRA_STR_PRS_SIM2_MMS_INSTALL)
  {
     return TRUE;    
  }
#endif /* BRA_CFG_DUAL_SIM */

  return FALSE;
}


static int
bra_prs_get_widget_sim_id(int bra_sim_id)
{
#ifdef BRA_CFG_DUAL_SIM
    
  return bra_sim_get_widget_sim_id(bra_sim_id);

#else

  return WAP_SERVICE_ON_UNKNOWN_SIM;

#endif
}



#endif /*BRA_CONFIG_PROVISIONING*/

