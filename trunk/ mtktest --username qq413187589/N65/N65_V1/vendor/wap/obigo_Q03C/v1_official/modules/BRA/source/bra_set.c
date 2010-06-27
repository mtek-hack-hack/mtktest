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
 * bra_set.c
 *
 * Description:
 *		This file contains code to edit settings.
 *
 *
 * The structure of this file is the following:
 *
 * - Local Defines
 * - Local Types
 * - Global Variables
 * - Prototypes
 * - Network ID menu
 * - Connection Menu
 * - Browser Options menu
 * - Connection Type menu
 */

#include "bra_cfg.h"

#include "msf_core.h"
#include "bra_cmn.h"
#include "bra_str.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "bra_set.h"
#ifdef BRA_CONFIG_SECURITY
#include "bra_sec.h"
#endif
#ifdef BRA_CONFIG_PUSH
#include "bra_psl.h"
#endif
#include "bra_cch.h"
#include "bra_cks.h"
#include "bra_prof.h"
#include "bra_sif.h"
#include "bra_rpl.h"
#include "bra_view.h"
#include "bra_int.h"
#include "bra_req.h"
#include "bra_file.h"
#include "bra_if.h" 

#include "brs_if.h"

#include "msf_cfg.h"
#include "msf_chrt.h"
#include "msf_cmmn.h"
#include "msf_dcvt.h"
#include "msf_lib.h"
#include "msf_log.h" 

#include "stk_if.h"
#ifdef BRA_CONFIG_SECURITY
#include "sec_if.h"
#include "sec_cfg.h"
#endif

#include "kal_release.h"
#include "wap.h"
#include "mcd_l4_common.h"
#include "l4c2phb_enums.h"

#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN
#include "stack_msgs.h"
#include "DataAccountGprot.h"
#endif


#include "bra_cbm.h"


#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif

/************************************************************
 * Local Defines
 ************************************************************/

#define BRA_SET_MAX_PWD_SIZE              30
#define BRA_SET_MAX_UID_SIZE              30
#define BRA_SET_MAX_IP_SIZE               15 /*3 dots are included*/
#define BRA_SET_MAX_NAME_SIZE             40
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#define BRA_SET_MAX_PHONENO_SIZE          40
/* due to the restriction of PHS's key
for the "security" parameter, we wont use value of 1 anymore,
whenever push setting is enabled, we set security to 0
and when push setting is disabled, we set security to 2 as per usual.

  the trust setting will actually no affect the "security" parameter anymore..
  but when user disables trust setting,
  we'll simply removes all entries from the trust list address entries....
  and when user enables trust setting,
  we re-set all addresses back to PHS' registry...
  
  should user enable the trust setting but the trust list itself is empty,
BRA should set a predefined address to PHS' registry where no address should be 
matched to this address.
*/
#define BRA_SET_DEFAULT_TL_PHONENO        "0"
#define BRA_SET_DEFAULT_TL_IP             "0.0.0.0"
#endif

#define BRA_SET_MAX_PORT_SIZE             5
#define BRA_SET_MAX_HISTSIZE_SIZE         3
#define BRA_SET_MAX_TIMEOUT_SIZE          3
//#define BRA_SET_MAX_N_NET_IDS             16

#define BRA_SET_MAX_TIMEOUT_VAL           300
#define BRA_SET_MIN_TIMEOUT_VAL           30

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#define BRA_PUSH_MAX_TRUSTLIST_NO         (wap_custom_get_max_trustList_num())

#define BRA_TRUSTLIST_MAX_FILE_SIZE   10000 
#define BRA_TRUSTLIST_INITIAL_SIZE    1000
#define BRA_TRUSTLIST_DEFRAG_LIMIT    500
#define BRA_TRUSTLIST_SIZE_INCREMENT  1000
#endif
/************************************************************
 * Local Types
 ************************************************************/
#ifdef BRA_USE_CTK_INLINE
typedef enum
{
  BROWSER_OPTION_TIMEOUT_CAP,
  BROWSER_OPTION_TIMEOUT,
  BROWSER_OPTION_IMAGE_CAP,
  BROWSER_OPTION_IMAGE,
  BROWSER_OPTION_NUM
} bra_ctk_browser_option_menu_item_enum;

typedef enum
{
  PROF_CUSTOM_RENAME_CAP,
  PROF_CUSTOM_RENAME,
  PROF_CUSTOM_HOMEPAGE_CAP,
  PROF_CUSTOM_HOMEPAGE,
  PROF_CUSTOM_ACCOUNT_CAP,
  PROF_CUSTOM_ACCOUNT,
  PROF_CUSTOM_CONN_TYPE_CAP,
  PROF_CUSTOM_CONN_TYPE,
  PROF_CUSTOM_GATEWAY_CAP,
  PROF_CUSTOM_GATEWAY,
  PROF_CUSTOM_SECURITY_CAP,
  PROF_CUSTOM_SECURITY,
  PROF_CUSTOM_UID_CAP,
  PROF_CUSTOM_UID,
  PROF_CUSTOM_PWD_CAP,
  PROF_CUSTOM_PWD,
  PROF_CUSTOM_NUM
} bra_ctk_prof_custom_menu_item_enum;
#endif

/* settings menu */
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
  int net_id;
#ifdef BRA_CFG_PROF_FALLBACK
  char dual_net_id;
  int net_id_menu_state;
  int net_id_sec;
  char dual_net_id_tmp;
  int net_id_tmp;
  int net_id_sec_tmp;
#endif
  int conn_type;
  int select;
  int port;
  char *ip;
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  int  is_ask;
#endif
} bra_set_menu_t;

typedef struct
{
  int n_items;
  MSF_INT32 net_ids[BRA_CFG_ONE_BEARER_MAX_NET_ID_NUM];
}bra_set_net_id_t;

#ifdef BRA_CONFIG_PUSH_TRUSTLIST

typedef int (*bra_push_trustlist_edit_response_t)(char* text, MSF_UINT8 type);

typedef struct bra_push_trustList_item
{
    int         sort_idx;
    int         idx;
    MSF_UINT8   type;
    MSF_INT32   address;
    struct bra_push_trustList_item  *next;
} bra_push_trustList_item_t;

typedef struct
{
    MSF_UINT32         sort_idx;
    MSF_UINT8          type;
    char               *address;
} bra_push_trustList_file_item_t;

typedef struct {
    MsfWindowHandle windowHandle;
    MsfWindowHandle backWindowHandle;
    MsfActionHandle backActionHandle;
    MsfActionHandle okActionHandle;
  /*  MsfGadgetHandle InputString;*/
    bra_push_trustlist_edit_response_t      callback;
    MSF_UINT8                               type;
} bra_push_tl_input_form_t;

#endif

/************************************************************
 * Global Variables
 ************************************************************/
#ifndef BRA_CFG_USE_DTCNT_SELECT_SCREEN
static bra_set_net_id_t *bra_set_net_ids;
#endif
static int              bra_set_showProfile = 0;
#ifdef BRA_USE_CTK_INLINE
static bra_set_menu_t *ctk_set_menu = NULL;
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
static bra_set_menu_t *ctk_set_tl_ip_menu = NULL;
#endif
#ifdef BRA_CONFIG_HTTP_EXT
static bra_set_menu_t *ctk_set_aux_menu = NULL;
#endif
#ifdef __MMI_KLG__
static const int list_of_timeout_value[4] = {20, 30, 60, 120};
#endif
#endif
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
static void                         *bra_tl_file_handle = NULL;
static bra_set_trustlist_state_t    bra_tl_state = BRA_TRUSTLIST_STATE_NULL;
static int                          bra_tl_selected_trustList = 0; /*including "add new"*/
static int                          bra_tl_n_items;
static bra_push_trustList_item_t    *bra_tl_list;
static bra_push_trustList_item_t    bra_tl_input;
#endif
/************************************************************
 *  Function prototypes    
 ************************************************************/

#if defined(BRA_CONFIG_HTTP_EXT) || !defined(BRA_USE_CTK_INLINE)
static void 
bra_create_conn_type_menu (void);
#endif


static void
bra_create_net_bearer_menu(void);


#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN

static MSF_UINT16
bra_set_get_net_id_select_app_id(void);

static MSF_UINT32
bra_set_get_net_id_select_bearer_scope(void);

static void
bra_set_get_net_id_select_bearer_info(MSF_UINT32 *id_num, 
                                      MSF_UINT32 *bearer_type, MSF_UINT32 *net_id);


static MSF_UINT32
bra_set_get_dtcnt_bearer_type_by_net_id(int net_id);


static void
bra_set_send_net_id_select_request(MSF_UINT16 app_id, MSF_UINT16 menu_id, 
                                   MSF_UINT32 id_num, MSF_UINT32 bearer_scope,
                                   MSF_UINT32 *bearer_type, MSF_UINT32* net_id);

static void
bra_set_fill_ctk_set_menu_always_ask(MSF_UINT32 ext_net_id);

#else /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/

static void 
bra_create_net_id_menu (MSF_UINT8 type);

#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/



static bra_set_menu_t*
bra_set_alloc_bra_set_menu(void);

static void
bra_set_free_bra_set_menu(bra_set_menu_t *menu);





extern void msm_compute_checksum_critical_file_by_index(int idx);

#ifdef BRA_CONFIG_MMS
extern MSF_UINT32
meaCheckMmscSetting(char *str);
#endif









/************************************************************
 * Function definitions
 ************************************************************/
 static char* bra_get_current_profile_name(void)
 {
  char      *s;
  char      *prof_name_str;
  
  
  s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PROF_STR);
  prof_name_str = bra_prof_get_profile_name(bra_prof_get_relative_profile(), (const char*)s);
  return prof_name_str;
}

static char *bra_get_account_name(int net_id)
{
  char namebuf[128];
  char *result = NULL;
  
  memset(namebuf, 0, sizeof(namebuf));

  if (HDIa_networkAccountGetName(net_id , namebuf, sizeof(namebuf)) < 0)
    MSF_WIDGET_STRING_GET_DATA (BRA_STR_SET_DEF_NET_ID, namebuf, MsfUtf8);

  result = msf_cmmn_strdup(MSF_MODID_BRA, namebuf);

  return result;
}

#ifdef BRA_USE_CTK_INLINE

#if !(defined(BRA_CFG_USE_DTCNT_SELECT_SCREEN) && defined(BRA_CFG_PROF_FALLBACK))

static void bra_ctk_update_data_account_display(int net_id)
{
  ctk_screen_handle	scrid;
#ifndef BRA_CFG_PROF_FALLBACK
  char *name_str;
#endif


  scrid = HDIa_widgetCtkGetScreenHandle(ctk_set_menu->window);
  ASSERT(scrid);  

#ifdef BRA_CFG_CONN_ALWAYS_ASK
  if (ctk_set_menu->is_ask)
  {
    name_str = bra_cmn_strdup_widget_string_data(BRA_STR_ALWAYS_ASK);
    ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), 5, (U8*) name_str, KAL_TRUE);
    BRA_FREE(name_str);
    return;
  }
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

#ifdef BRA_CFG_PROF_FALLBACK
  if (ctk_set_menu->dual_net_id_tmp)
  {
    if (ctk_set_menu->net_id_menu_state == HDI_SOCKET_BEARER_GSM_GPRS)
      ctk_set_menu->net_id_tmp = net_id;
    else
      ctk_set_menu->net_id_sec_tmp = net_id;
  }
  else
  {
    ctk_set_menu->net_id_tmp = net_id;
  }
#else
  ctk_set_menu->net_id = net_id;
  name_str = bra_get_account_name(net_id);
  ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), 5, (U8*) name_str, KAL_TRUE);
  BRA_FREE(name_str);
#endif
}
#endif /*!(defined(BRA_CFG_USE_DTCNT_SELECT_SCREEN) && defined(BRA_CFG_PROF_FALLBACK))*/


#ifdef BRA_CONFIG_HTTP_EXT
static int bra_ctk_update_conn_type_display(int conn_type, int force)
{
  ctk_screen_handle	scrid;
  char *name_str;
  MSF_UINT16    conn_type_strid[3] = {BRA_STR_ID_HTTP, BRA_STR_ID_CONN_LESS,BRA_STR_ID_CONN_ORIENT};
  MsfStringHandle ms;
  MSF_UINT8 l;    
  
  scrid = HDIa_widgetCtkGetScreenHandle(ctk_set_menu->window);
  ASSERT(scrid);    

  if(force || ctk_set_menu->conn_type != conn_type)
  {
    ms = MSF_WIDGET_STRING_GET_PREDEFINED(conn_type_strid[conn_type-1]);
    l = MSF_WIDGET_STRING_GET_LENGTH(ms, 1, MsfUtf8);
    name_str = BRA_ALLOC (l + 1);
    MSF_WIDGET_STRING_GET_DATA (ms, name_str, MsfUtf8);
    name_str[l-1] = '\0';
    ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), 7, (U8*) name_str, KAL_TRUE);
    BRA_FREE(name_str);  
    ctk_set_menu->conn_type = conn_type;
    return 1;
  }

  return 0;
}
#endif

#endif

/*****************************************************************/
/*                                                               */
/*    Select Network ID menu                                     */
/*                                                               */
/*****************************************************************/

#ifdef BRA_USE_CTK_INLINE
#ifdef BRA_CFG_PROF_FALLBACK
static void
bra_update_profile_custom_net_id_text()
{
  ctk_screen_handle	scrid;
  char *tmp_str;
  char *tmp_str2;
  char *tmp_str3;

  scrid = HDIa_widgetCtkGetScreenHandle(ctk_set_menu->window);
  ASSERT(scrid);  

#ifdef BRA_CFG_CONN_ALWAYS_ASK
  if (ctk_set_menu->is_ask)
  {
    tmp_str = bra_cmn_strdup_widget_string_data(BRA_STR_ALWAYS_ASK);
    ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), 5, (U8*) tmp_str, KAL_TRUE);
    BRA_FREE(tmp_str);
    return;
  }
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

  tmp_str = bra_get_account_name(ctk_set_menu->net_id);  
  if (ctk_set_menu->dual_net_id)
  {
    tmp_str2 = bra_get_account_name(ctk_set_menu->net_id_sec);
    tmp_str3 = msf_cmmn_strcat (MSF_MODID_BRA, tmp_str, "/");
    BRA_FREE(tmp_str);
    tmp_str = msf_cmmn_strcat (MSF_MODID_BRA, tmp_str3, tmp_str2);
    BRA_FREE(tmp_str2);
    BRA_FREE(tmp_str3);
  }
  ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), 5, (U8*)tmp_str, KAL_TRUE);
  BRA_FREE(tmp_str);
}
#endif /* BRA_CFG_PROF_FALLBACK */
#endif /* BRA_USE_CTK_INLINE */


#ifndef BRA_CFG_USE_DTCNT_SELECT_SCREEN

static void
bra_delete_net_id_menu (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->accept);
    MSF_WIDGET_RELEASE (p->back);
    
    BRA_FREE (bra_set_net_ids);
    
    BRA_FREE (p);
}


static void 
bra_action_net_id_menu (bra_win_t *win, MsfActionHandle bra_action)
{
  bra_set_menu_t *p;
  int i = 0;

  p = (bra_set_menu_t *)(win);

	if (bra_action == p->accept){
    while (i < bra_set_net_ids->n_items)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
      {
#ifdef BRA_USE_CTK_INLINE
        bra_ctk_update_data_account_display (bra_set_net_ids->net_ids[i]);
#else
        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, bra_set_net_ids->net_ids[i], NULL);
#endif
      }
      i++;
    }
#ifdef BRA_USE_CTK_INLINE
#ifdef BRA_CFG_PROF_FALLBACK
    if (ctk_set_menu->dual_net_id_tmp)
    {
      if (ctk_set_menu->net_id_menu_state == HDI_SOCKET_BEARER_GSM_GPRS) {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

        ctk_set_menu->net_id_menu_state = HDI_SOCKET_BEARER_GSM_CSD;
        bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_CSD);
      } else {
        ctk_set_menu->dual_net_id = ctk_set_menu->dual_net_id_tmp;
        ctk_set_menu->net_id = ctk_set_menu->net_id_tmp;
        ctk_set_menu->net_id_sec = ctk_set_menu->net_id_sec_tmp;
        bra_update_profile_custom_net_id_text();
        bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_CUSTOM_MENU);
      }
    }
    else
    {
      ctk_set_menu->dual_net_id = ctk_set_menu->dual_net_id_tmp;
      ctk_set_menu->net_id = ctk_set_menu->net_id_tmp;
      bra_update_profile_custom_net_id_text();
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_CUSTOM_MENU);
    }
#else
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_CUSTOM_MENU);
#endif
#else
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_EDIT_MENU);
#endif
  }
  else if(bra_action == p->back)
  {
#ifdef BRA_CFG_PROF_FALLBACK
    if (ctk_set_menu->dual_net_id_tmp && ctk_set_menu->net_id_menu_state==HDI_SOCKET_BEARER_GSM_CSD)
    {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

        ctk_set_menu->net_id_menu_state = HDI_SOCKET_BEARER_GSM_GPRS;
        bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
    }
    else
#endif
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void 
bra_create_net_id_menu (MSF_UINT8 type)
{
  bra_set_menu_t *win;
	MsfPosition pos = BRA_CFG_MENU_POS;
  MSF_INT32 net_id;
  MSF_INT32 current_net_id;
  MsfStringHandle ms;
  char namebuf[128];
  int i = 0;
  MsfDeviceProperties prop;
  MSF_UINT8 selected = FALSE;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_set_menu_t);

  win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
  win->back = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 3, 0x8000);
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

   bra_set_net_ids = BRA_ALLOCTYPE(bra_set_net_id_t);
   bra_set_net_ids->n_items = 0;
   current_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);   
   
   while (net_id >= 0)
   {
     if(HDIa_networkAccountGetBearer(net_id) != type)
     {
       net_id = HDIa_networkAccountGetNext (net_id);
       continue;
     }

     if (bra_set_net_ids->n_items >= BRA_CFG_ONE_BEARER_MAX_NET_ID_NUM)
       break;

     bra_set_net_ids->n_items++;
     bra_set_net_ids->net_ids[i] = net_id;
     
     memset(namebuf, 0, sizeof(namebuf));
     if (HDIa_networkAccountGetName(net_id , namebuf, sizeof(namebuf)) >= 0)
       ms = BRA_STRCONV(namebuf);
     else
       ms = BRA_STR_SET_DEF_NET_ID;

    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, ms, 0, 0, 0, TRUE); 

#ifdef BRA_USE_CTK_INLINE
#ifdef BRA_CFG_PROF_FALLBACK
    if ((ctk_set_menu->dual_net_id_tmp &&
         ((ctk_set_menu->net_id_menu_state==HDI_SOCKET_BEARER_GSM_GPRS && net_id==ctk_set_menu->net_id_tmp) ||
          (ctk_set_menu->net_id_menu_state==HDI_SOCKET_BEARER_GSM_CSD && net_id==ctk_set_menu->net_id_sec_tmp)))
        ||
        (!ctk_set_menu->dual_net_id_tmp && net_id==ctk_set_menu->net_id_tmp))
#else
    if (net_id == ctk_set_menu->net_id)
#endif
#else
    if (net_id == current_net_id)
#endif
    {
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (i - 1), MSF_CHOICE_ELEMENT_SELECTED);
      selected = TRUE;
    }

    MSF_WIDGET_RELEASE (ms);
    net_id = HDIa_networkAccountGetNext (net_id);
   }

    if (selected == FALSE)
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 0, MSF_CHOICE_ELEMENT_SELECTED);

	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->accept);
	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->back);

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SET_NET_ID_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_net_id_menu, 
                    NULL,
                    bra_action_net_id_menu);

#ifdef BRA_CFG_PROF_FALLBACK
  if (ctk_set_menu->dual_net_id_tmp)
  {
    if (ctk_set_menu->net_id_menu_state == HDI_SOCKET_BEARER_GSM_GPRS)
      bra_dlg_create_dlg (MsfInfo, BRA_STR_SELECT_GPRS, BRA_STR_OK, 0, 0, 0);
    else
      bra_dlg_create_dlg (MsfInfo, BRA_STR_SELECT_GSM_CSD, BRA_STR_OK, 0, 0, 0);
  }
#endif
}


static void
bra_delete_net_bearer_menu (bra_win_t *win)
{
  bra_set_menu_t *p;
  p = (bra_set_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

static void
bra_action_net_bearer_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_set_menu_t *p;
  int i = 0;

  p = (bra_set_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {    
#ifdef BRA_CFG_PROF_FALLBACK
    ctk_set_menu->dual_net_id_tmp = 0;
    ctk_set_menu->net_id_tmp = ctk_set_menu->net_id;
#endif
    if (bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*GSM Data*/
        bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_CSD);
      }
#ifdef __PS_SERVICE__         
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*GPRS*/
        bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
      }    
#ifdef BRA_CFG_PROF_FALLBACK
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*GPRS/GSM*/
        ctk_set_menu->dual_net_id_tmp = 1;
        ctk_set_menu->net_id_menu_state = HDI_SOCKET_BEARER_GSM_GPRS;
        ctk_set_menu->net_id_tmp = ctk_set_menu->net_id;
        ctk_set_menu->net_id_sec_tmp = ctk_set_menu->net_id_sec;
        bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
      }
#endif
#endif      
#ifdef __WIFI_SUPPORT__         
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
        int net_id = HDIa_networkAccountGetId(HDI_SOCKET_BEARER_WIFI);
#ifdef BRA_USE_CTK_INLINE
        bra_ctk_update_data_account_display (net_id);
#ifdef BRA_CFG_PROF_FALLBACK
        ctk_set_menu->dual_net_id = ctk_set_menu->dual_net_id_tmp;
        ctk_set_menu->net_id = ctk_set_menu->net_id_tmp;
        bra_update_profile_custom_net_id_text();
#endif
        bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_CUSTOM_MENU);
#else
        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, net_id, NULL);
        bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PROFILE_EDIT_MENU);
#endif
      }    
#endif      
    }
    /* MMS */
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*GSM Data*/
      bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_CSD);
    }
#ifdef __PS_SERVICE__
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*GPRS*/
      bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
    }    
#ifdef MMS_CFG_FALLBACK_SUPPORT
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*GPRS/GSM*/
      ctk_set_menu->dual_net_id_tmp = 1;
      ctk_set_menu->net_id_menu_state = HDI_SOCKET_BEARER_GSM_GPRS;
      ctk_set_menu->net_id_tmp = ctk_set_menu->net_id;
      ctk_set_menu->net_id_sec_tmp = ctk_set_menu->net_id_sec;
      bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
    }
#endif
#endif
  }
}



static void 
bra_create_net_bearer_menu (void)
{
  bra_set_menu_t      *win;
  MsfPosition          pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties  prop;
  MSF_UINT8            i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
#ifdef BRA_CFG_PROF_FALLBACK
  ctk_set_menu->dual_net_id_tmp = 0;
  ctk_set_menu->net_id_tmp = ctk_set_menu->net_id;
#endif

  //if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  //{
    /* show GPRS prof selection straightaway*/
    //bra_create_net_id_menu(HDI_SOCKET_BEARER_GSM_GPRS);
    //return;
  //}

  win = BRA_ALLOCTYPE (bra_set_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                        MsfImplicitChoice,
                                        &prop.displaySize,
                                        win->accept,
                                        0, /*Element Position*/
                                        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                        0x8000, /*Property Mask*/
                                        0 /*Default Style*/);

   //if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
   //{
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_GSM_CSD,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
   //}     
#ifdef __PS_SERVICE__   
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_GPRS,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
   if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
   {
#ifdef BRA_CFG_PROF_FALLBACK
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_GPRS_GSM_DUAL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
#endif
   }
   /* MMS */
   else
   {
#ifdef MMS_CFG_FALLBACK_SUPPORT
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_GPRS_GSM_DUAL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
#endif
   }
#endif   
#ifdef __WIFI_SUPPORT__
   if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
   {
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_WIFI,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
   }
#endif   
   MSF_WIDGET_SET_TITLE (win->window,BRA_STR_SET_NET_ID);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_NET_BEARER_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_net_bearer_menu, 
                    NULL,
                    bra_action_net_bearer_menu);

}
#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/


/*****************************************************************/
/*                                                               */
/*    CONNECTIONS MENU                                           */
/*                                                               */
/*****************************************************************/
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
#endif

static int
bra_set_prx_uid_response (char *response)
{
  if (response == NULL)
    return 0;

  bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prx_uid", response, NULL);

  BRA_FREE (response);

  return 1;
}

#ifndef BRA_USE_CTK_INLINE
static int
bra_set_prx_pwd_response (char *response)
{
  if (response == NULL)
    return 0;

  bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prx_pwd", response, NULL);

  BRA_FREE (response);

  return 1;
}

static int
bra_set_prx_port_response (char *response)
{
  int portnum;
  if (!response || !(portnum=atoi(response)) || portnum < 1 || portnum > 65535)
  {
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_INVALID_INPUT, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);    
    return 0;
  }    

  bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "prx_port", atoi (response), NULL);

  BRA_FREE (response);

  return 1;
}
#endif

#ifndef __MMI_KLG__   
static void
bra_set_invalid_timeout_dialog(void)
{
  MsfStringHandle ms;
  MSF_UINT8 l;
  char *s;

  ms = BRA_STR_INVALID_INPUT;
  l = MSF_WIDGET_STRING_GET_LENGTH(ms, 1, MsfUtf8);
  s = BRA_ALLOC (l + 16); 
  MSF_WIDGET_STRING_GET_DATA (ms, s, MsfUtf8);
  sprintf(s+l-1, " (%d - %d)", BRA_SET_MIN_TIMEOUT_VAL, BRA_SET_MAX_TIMEOUT_VAL);   
  ms = BRA_STRCONV (s);

#if 1
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, ms, MsfError,0);   
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
  MSF_WIDGET_RELEASE(ms);
  BRA_FREE(s);

}
#endif

#ifndef BRA_USE_CTK_INLINE
static int
bra_set_timeout_response (char *response)
{
  int timeout;

  if( !response || !(timeout=atoi(response)) || timeout < BRA_SET_MIN_TIMEOUT_VAL || timeout > BRA_SET_MAX_TIMEOUT_VAL)
  {
    bra_set_invalid_timeout_dialog();
    return 0;
  }

  bra_prof_change_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT, atoi(response), NULL);

  BRA_FREE (response);

  return 1;
}
#endif

int check_ip(char *s)
{
   char *ip;
   char seps[] = ".";
   char *token;
   int ip_sec = 0;
         
   ip = BRA_ALLOC(strlen(s)+1);
   strcpy(ip, s);

   /* 1st char of ip or hostname can't be '.' */      
   if(ip[0] == '.' || ip[strlen(ip)-1] == '.')
      goto err;
      
   token = strtok(ip, seps);
   while(token)
   {
      unsigned short i;
      for(i=0;i<strlen(token);i++)
      {
         if( i >= 3)
            goto err;
            
         if(token[i] < '0' || token[i] > '9')
            goto err;
      }
      
      /* this segement is ip format */
      ip_sec++;

      token = strtok(NULL, seps);
   }
   
   if(ip_sec != 4)
      goto err;	
   
   BRA_FREE(ip);
   return 1;   

err:

   BRA_FREE(ip);
   return 0;
   
}

static int
bra_set_prx_addr_response (char *response)
{
  int   i = 0;
  int   j = 0;
  char *s;
  char addr[4][4];
  int conn_type;

  if (response == NULL)
    goto error;

  conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
  if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
  {
    if(!strlen(response) || !check_ip(response))
      goto error;
  }
  else
  {
  if(strlen(response) && !check_ip(response))
    goto error;
  }

  s = response;
  
  /*Check that there is 4 address parts and copy parts to array*/
  while (*s != '\0')
  {
    if (*s != '.')
    {
      if (j > 2)
        goto error; /*To many characters in part*/

      if(ct_isdigit(*s))
      {
        addr[i][j] = *s;
        j++;
      }
      else
        goto error; /*Ilegal character*/
    }
    else
    {
      if (j == 0)
        goto error;; /*No sub part between dots*/

      addr[i][j] = '\0';
     
      if (i < 3)
        i++;
      else
        goto error;; /*To many parts*/

      j = 0;
    }
    s++;
  }

  addr[i][j] = '\0';

  /*Check that sub parts are < 255*/
  if ((atoi ((const char *)&addr[0]) > 255) || (atoi ((const char *)&addr[1]) > 255) || 
      (atoi ((const char *)&addr[2]) > 255) || (atoi ((const char *)&addr[3]) > 255))
      goto error;;

  if ((atoi ((const char *)&addr[0]) == 0) && (atoi ((const char *)&addr[1]) == 0) &&
      (atoi ((const char *)&addr[2]) == 0) && (atoi ((const char *)&addr[3]) == 0))
    bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prx_addr", "", NULL);
  else      
    bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prx_addr", response, NULL);

  BRA_FREE (response);

  return 1;

error:
  /*Display error message*/
  bra_dlg_create_dlg (MsfError,
                      BRA_STR_ERR_INVALID_IP, 
                      BRA_STR_OK, 
                      0,
                      0, 
                      NULL);
  return 0;
}

#ifdef BRA_CONFIG_SECURITY
static void 
bra_conn_enable_sec_response (int selected)
{
  int conn_type;  

  conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);

  if (selected == 0)
  {
	 bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 0, NULL);
	 bra_view_set_secure_icon(0);
  }
  else if (selected == 1)
  {
    if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL)
	 {
	   bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 9202, NULL);
	 }
	 else if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
	 {
	   bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 9203, NULL);
	 }    
  }
}
#endif

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
#ifdef BRA_CONFIG_SECURITY
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
#ifdef BRA_CONFIG_SECURITY
/* under construction !*/
#endif
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

/*****************************************************************/
/*                                                               */
/*    Load objects menu item helper functions                    */
/*                                                               */
/*****************************************************************/

/*Remove string remove from string s, copy to new buffer, and retrun new buffer*/
static char*
bra_set_remove_str_str (char* s, char* remove)
{
  char *p;
  char *str;  
  int   l;
  int   rl;
  int   sp;
  int   ep;

  if ((s == NULL) || (remove == NULL))
  {
    return  msf_cmmn_strdup (MSF_MODID_BRA, s);
  }
  
  if ((p = strstr (s, remove)) == NULL)
  {
    /*String not in stirng*/
    return  msf_cmmn_strdup (MSF_MODID_BRA, s);
  }

  l  = strlen (s);
  rl = strlen (remove);

  str = BRA_ALLOC (l - rl + 1);

  if (l == rl)
  {
    str[0] = '\0';
    return str;
  }

  sp = (p - s);
  ep = sp + rl;

  if (s[ep] == ',')
    ep++;
  else if (sp != 0)
    sp--;
  
  memcpy (str, s, sp);
  memcpy (&str[sp], &s[ep], l - ep);
  str[l - rl - 1] = '\0';

  return str;
}

/*Add string add to string s, copy to new buffer, and retrun new buffer*/
static char*
bra_set_add_str_str (char* s, char* add)
{
  char *str;  
  int   l;
  int   al;
  int   ac = 0; /*add comma*/

  if (add == NULL)
  {
    return msf_cmmn_strdup (MSF_MODID_BRA, s);
  }
  

  if (s == NULL)
  {
    l = 0;
  }
  else
  {
    if (strstr (s, add) != NULL)
    {
      /*String already in stirng*/
      return msf_cmmn_strdup (MSF_MODID_BRA, s);
    }

    l  = strlen (s);
  }

  al = strlen (add);

  if (l > 0)
    ac = 1;;
  
  str = BRA_ALLOC (l + al + ac + 1);

  memcpy (str, s, l);
  memcpy (&str[l], ",", ac);
  memcpy (&str[l + ac], add, al);
  str[l + al + ac] = '\0';

  return str;
}

static int
bra_set_get_selected_obj_mode (char* s)
{
  char * ask;
  char * load;

  /*Fist get current value*/
  ask = bra_prof_get_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_ASK);
  if(ask && *ask == 0)
    ask = NULL;
  load = bra_prof_get_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_LOAD);
  if(load && *load == 0)
    load = NULL;

  if (load != NULL)
  {
    if (strstr (load, s) != NULL)
      return 1;
  }

  if (ask != NULL)
  {
    if (strstr (ask, s) != NULL)
      return 2;
  }

  return 0;
}

#ifdef __MMI_KLG__
static int
bra_set_get_selected_timeout(int timeout_value)
{
  MSF_UINT8 i, num_of_timeout_value;
  num_of_timeout_value = sizeof(list_of_timeout_value)/sizeof(int);
  for(i = 0; i < num_of_timeout_value; i++)
  {
    if(timeout_value <= list_of_timeout_value[i])
      return i;
  }   
  return (i-1);
}      
#endif

/*****************************************************************/
/*                                                               */
/*    Display Optons                                             */
/*                                                               */
/*****************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void
bra_set_enable_object (int selected, char* s)
{
  char * ask;
  char * load;
  char * n_ask;
  char * n_load;

  /*Fist get current value*/
  ask = bra_prof_get_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_ASK);
  if(ask && *ask == 0)
    ask = NULL;
  load = bra_prof_get_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_LOAD);
  if(load && *load == 0)
    load = NULL;

  if (selected == 0)
  {
    /*Never display images*/
    n_ask = bra_set_remove_str_str (ask , s);
    n_load = bra_set_remove_str_str (load, s);
  }
  else if (selected == 1)
  {
    /*Always display*/
    n_ask = bra_set_remove_str_str (ask, s);
    n_load = bra_set_add_str_str (load, s);
  }
  else
  {
    /*Ask before loading*/
    n_load = bra_set_remove_str_str (load, s);
    n_ask = bra_set_add_str_str (ask, s);
  }
  
  bra_prof_change_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_LOAD, n_load, NULL);
  bra_prof_change_key_str_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_OBJ_ASK, n_ask, NULL);

  BRA_FREE (n_load);
  BRA_FREE (n_ask);

}

static void
bra_set_enable_image_response (int selected)
{
  if (selected >= 0)
    bra_set_enable_object (selected, "image/*");
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
#endif

#ifdef BRA_CONFIG_TEST
static int
bra_set_resize_response (char* response)
{
  int x;
  int y;
  char *p;
  
  if (response == NULL)
    return 0;

  if (bra_sif_get_brs_status() != BRA_SIF_BRS_CREATED)
    return 1;
  
  p = response;

  while (*p++ != '*');

  *(p-1) = '\0';

  x = atoi (response);
  y = atoi (p);

  BRSif_resizeWindow (MSF_MODID_BRA, bra_sif_get_brs_id (),
                     0, 20,
                     y, x);


  BRA_FREE (response);

  return 1;
}
#endif

#ifndef BRA_USE_CTK_INLINE
static void
bra_delete_display_opt_menu (bra_win_t *win)
{
  bra_set_menu_t *p;
  p = (bra_set_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}


static void
bra_action_display_opt_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_set_menu_t *p;
  const int on_off_list[2] = { BRA_STR_ID_OFF,
                               BRA_STR_ID_ON};
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

  MSF_UINT8 i = 0;

  p = (bra_set_menu_t *)(win);
  
	if (bra_action == p->back)
	{
	  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
	}
	else if (bra_action == p->accept)
	{
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Timeout value*/
      char *s;
      MsfStringHandle ms;
      s = bra_cmn_int_to_str (bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT));
      ms = BRA_STRCONV(s);/*OK*/
      bra_dlg_create_input_form(BRA_STR_TIMEOUT, 
                                MsfInteger, 
                                ms, 
                                BRA_SET_MAX_TIMEOUT_SIZE, 
                                bra_set_timeout_response);
      MSF_WIDGET_RELEASE (ms);
      BRA_FREE (s);
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Show Images*/
      bra_dlg_create_opt_menu (BRA_STR_IMAGE_OPT, 
                               2, 
                               on_off_list,
                               bra_set_get_selected_obj_mode ("image/*"),
                               bra_set_enable_image_response);

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
#endif
	}
}

static void 
bra_create_display_opt_menu (void)
{
  bra_set_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_set_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
												                     &prop.displaySize,
												                     win->accept,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_TIMEOUT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
  	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_IMAGE_OPT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
#if 0
/* under construction !*/
#endif
	MSF_WIDGET_SET_TITLE (win->window, BRA_STR_BROWSER_OPTIONS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SET_DISPLAY_OPT_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_display_opt_menu, 
                    NULL,
                    bra_action_display_opt_menu);

}
#endif

#ifdef BRA_USE_CTK_INLINE
static void
bra_delete_display_opt_menu_ctk (bra_win_t *win)
{
  win = win;
  bra_set_free_bra_set_menu(ctk_set_menu);
  ctk_set_menu = NULL;
}

static void 
bra_ctk_delete_display_opt_menu (ctk_screen_handle scrid)
{
  scrid = scrid;
  bra_set_free_bra_set_menu(ctk_set_menu);
  ctk_set_menu = NULL;
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
}

static void 
bra_ctk_action_display_opt_confirmation(MsfActionType response)
{
  ctk_screen_handle scrid;
  ctk_layout_handle layoutid;
  int select;

  scrid = HDIa_widgetCtkGetScreenHandle(ctk_set_menu->window);

  if(response == MsfOk)
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVING, MsfInfo, 5000);   

    layoutid =ctk_screen_get_layout(scrid);      

    // get image on/off    
    select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, BROWSER_OPTION_IMAGE);
    bra_set_enable_image_response(select);
#ifdef __MMI_KLG__
    select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, BROWSER_OPTION_TIMEOUT);
    bra_prof_change_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT, list_of_timeout_value[select], bra_cmn_saved_dialog);
#else
    {
      char *timeout_str;
      // get timeout
      timeout_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, BROWSER_OPTION_TIMEOUT);
      bra_prof_change_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT, atoi(timeout_str), NULL);
      BRA_FREE (timeout_str);

      /* save + calc checksum */
      msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
      bra_cmn_saved_dialog();
    }      
#endif
  }
  
  bra_ctk_delete_display_opt_menu(scrid);
}

static void 
bra_ctk_action_display_opt_menu (ctk_screen_handle scrid)
{
#ifndef __MMI_KLG__   
  ctk_layout_handle			layoutid =ctk_screen_get_layout(scrid);
  char *timeout_str;
  int timeout;
    
  // get timeout
  timeout_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, BROWSER_OPTION_TIMEOUT);
  if(!timeout_str)
  {
    bra_set_invalid_timeout_dialog();
    BRA_FREE(timeout_str);
    return;      
  }
  timeout=atoi(timeout_str);
  if(!timeout || timeout < BRA_SET_MIN_TIMEOUT_VAL || timeout > BRA_SET_MAX_TIMEOUT_VAL)
  {
    bra_set_invalid_timeout_dialog();
    BRA_FREE(timeout_str);
    return;      
  }  

  BRA_FREE(timeout_str);
#endif

  bra_dlg_create_dlg (MsfConfirmation,
                      BRA_STR_SAVE_ASK, 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_ctk_action_display_opt_confirmation);
}

static void 
bra_ctk_create_display_opt_menu (void)
{
  MsfPosition   win_pos = {0,0};
  MSF_UINT16    list_of_strid[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};
#ifdef __MMI_KLG__
  MSF_UINT16    list_of_timeout_strid[4] = {BRA_STR_ID_20_SECS, BRA_STR_ID_30_SECS, BRA_STR_ID_60_SECS, BRA_STR_ID_2_MINS};
#endif

  ctk_screen_handle				scrid;
  ctk_layout_handle				layoutid;
  ctk_inline_create_struct		layout_create;

  int i = 0;


  bra_set_free_bra_set_menu(ctk_set_menu);
  ctk_set_menu = bra_set_alloc_bra_set_menu(); 

  layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                     BROWSER_OPTION_NUM,                                     
                                     widget_get_title_icon(0),
                                     BRA_STR_ID_BROWSER_OPTIONS,
                                     bra_ctk_delete_display_opt_menu,
                                     KAL_TRUE);

  // timeout caption
  bra_cmn_ctk_add_caption(layoutid, BROWSER_OPTION_TIMEOUT_CAP, BRA_STR_ID_TIMEOUT, bra_cmn_get_list_num_image_enum(i++));
  
  // timeout input
#ifdef __MMI_KLG__
  bra_cmn_ctk_add_select(layoutid, BROWSER_OPTION_TIMEOUT, 4, list_of_timeout_strid,
                         bra_set_get_selected_timeout (bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT)));
#else
  {
    char *timeout_str;
    timeout_str = bra_cmn_int_to_str (bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT));
    bra_cmn_ctk_add_single_line_editor(layoutid, BROWSER_OPTION_TIMEOUT, BRA_SET_MAX_TIMEOUT_SIZE, timeout_str);
    BRA_FREE(timeout_str);
  }    
#endif

  // image on/off caption
  bra_cmn_ctk_add_caption(layoutid, BROWSER_OPTION_IMAGE_CAP, BRA_STR_ID_IMAGE_OPT, bra_cmn_get_list_num_image_enum(i++));

  // select image on/off
  bra_cmn_ctk_add_select(layoutid, BROWSER_OPTION_IMAGE, 2, list_of_strid,
                         bra_set_get_selected_obj_mode ("image/*"));

  scrid = bra_cmn_ctk_screen_create(layoutid, bra_ctk_action_display_opt_menu);

  // create form
  ctk_set_menu->window = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);  

	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG_TITLE_URL_FORM, 
                       (bra_win_t*)ctk_set_menu, 
                       &win_pos, 
                       bra_delete_display_opt_menu_ctk, 
                       NULL,
                       NULL);				
}
#endif

/*****************************************************************/
/*                                                               */
/*    SETTINGS MENU                                              */
/*                                                               */
/*****************************************************************/
static int
bra_title_url_response (char *title, char *url)
{

  /*Not both the title and url can be null att the same time*/
  /*if((*title == '\0') && (*url == '\0'))
    return 0;*/

//  if(bra_prof_get_absolute_profile() == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID))
  if (bra_prof_is_bra_profile_in_active_use(BRA_PROF_ID_BRA, bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
  {
    bra_cmn_set_local_hompage_title(BRA_STRCONV (title));/*OK*/
    bra_cmn_set_local_hompage_url(url);
  }    
  
  bra_cmn_set_homepage (title, url);

  return 1;

}

#ifdef BRA_CONFIG_MMS
static int
bra_title_mmsc_response (char *title, char *url)
{

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;
  
  bra_prof_change_key_str_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_HOMEPAGE_TITLE, title, NULL);
  bra_prof_change_key_str_value(BRA_PROF_ID_MMS, BRA_PROF_KEY_HOMEPAGE_URL, url, NULL);  

  return 1;

}
#endif

static int
bra_set_rename_profile_response (char* response)
{
  if (response == NULL)
    return 0;

  bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prof_str", response, NULL);

  BRA_FREE (response);

  return 1;
}

static void
bra_delete_settings_menu (bra_win_t *win)
{
  bra_set_menu_t *p;
  extern void msm_compute_checksum_critical_file_by_index(int idx);
  
  p = (bra_set_menu_t *)(win);

  /* unload profile and save the checksum */
  msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);  

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}


static void
bra_cch_delete_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    STKif_clear (MSF_MODID_BRA, STK_CLEAR_CACHE_ALL, NULL);
    bra_cmn_save_done_dialog();
  }
}

#ifdef BRA_CONFIG_PUSH
static void 
bra_enable_push_response (int selected)
{
	int push_on_off;
	if(selected < 0)
		return;
	push_on_off = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON);
	if(selected != push_on_off)
    {
      void* reg_handle;
      
      bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON, selected, NULL);
      msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
      
      /*inform PHS*/
      reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
      MSF_REGISTRY_SET_PATH(reg_handle, (char*)"/PHS/");
      if (selected) /* on*/
      {
          MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "security", 0);
      }
      else /*off*/
      {
        MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "security", 2);
      }
      MSF_REGISTRY_SET_COMMIT (reg_handle);

      bra_cmn_save_done_dialog();    
    }
}
#endif

static void
bra_cks_clear_conf_response (MsfActionType response)
{
  if(response == MsfOk)
  {
    STKif_clear (MSF_MODID_BRA, STK_CLEAR_COOKIES_ALL, NULL);
    bra_cmn_save_done_dialog();
  }  
}
      

static void
bra_delete_push_settings_menu (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->accept);
    MSF_WIDGET_RELEASE (p->back);
    
    BRA_FREE (p);
}


#ifdef BRA_CONFIG_PUSH_TRUSTLIST

static void
bra_tl_setToPHS (MSF_UINT8 type)
{
    char                        *str = NULL;
    int                         len = 0;
    bra_push_trustList_item_t   *pList = bra_tl_list;
    void*                       reg_handle;
    int                         push_trust_setting;

    push_trust_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_TRUSTSETTING);
    
    if (push_trust_setting == 0) /*when not set trust setting*/
    {
        /* empty the key */
    }
    else        /*when set trust setting*/
    {
        while (pList)
        {
            if (pList->type == type)
            {
                len += MSF_WIDGET_STRING_GET_LENGTH(pList->address, 1, MsfUtf8);
            }
            pList = pList->next;
        }
        
        if (len != 0)
        {
            str = BRA_ALLOC(len);
            str[0] = '\0';
            
            pList = bra_tl_list;
            len = 0;
            while (pList)
            {
                if (pList->type == type)
                {
                    MSF_WIDGET_STRING_GET_DATA(pList->address, (char*) (str + len), MsfUtf8);
                    len = strlen(str);
                    str[len] = ';';
                    len++;
                }
                pList = pList->next;
            }
            str[len - 1] = '\0';
        }
        else /*no list item, set default value*/
        {
            switch(type)
            {
            case BRA_ADDRTYPE_PHONENO:
                len = strlen(BRA_SET_DEFAULT_TL_PHONENO) + 1;
                str = BRA_ALLOC(len);
                strcpy(str, BRA_SET_DEFAULT_TL_PHONENO);
                break;
            case BRA_ADDRTYPE_IPV4:
                len = strlen(BRA_SET_DEFAULT_TL_IP) + 1;
                str = BRA_ALLOC(len);
                strcpy(str, BRA_SET_DEFAULT_TL_IP);
                break;
            case BRA_ADDRTYPE_TEXT:
                break;
            default:
                return;
            }
        }
    }

    reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_BRA);

    MSF_REGISTRY_SET_PATH(reg_handle, (char*)"/PHS/wlist");

    switch(type)
    {
    case BRA_ADDRTYPE_PHONENO:
        MSF_REGISTRY_SET_ADD_KEY_STR(reg_handle, "wlstsmsc", (unsigned char*)((len == 0) ? "" : str), (MSF_UINT16)(len));
    	break;
    case BRA_ADDRTYPE_IPV4:
        MSF_REGISTRY_SET_ADD_KEY_STR(reg_handle, "wlstip", (unsigned char*)((len == 0) ? "" : str), (MSF_UINT16)(len));
    	break;
    case BRA_ADDRTYPE_TEXT:
        MSF_REGISTRY_SET_ADD_KEY_STR(reg_handle, "wlstname", (unsigned char*)((len == 0) ? "" : str), (MSF_UINT16)(len));
        break;
    default:
        return;
    }

    MSF_REGISTRY_SET_COMMIT (reg_handle);

    if (str);
    {
        BRA_FREE(str);
    }
}


static void 
bra_push_trustSetting_response (int selected)
{
    int push_trust_setting;
    if(selected < 0)
        return;
    push_trust_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_TRUSTSETTING);
    if(selected != push_trust_setting)
    {
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_TRUSTSETTING, selected, NULL);
        msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
        
        /*inform PHS*/
        bra_push_trustList_init(BRA_TRUSTLIST_STATE_SETTOPHS);

        bra_cmn_save_done_dialog();
    }
}

#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/

static void 
bra_push_SLSetting_response (int selected)
{
    int push_SL_setting;
    if(selected < 0)
        return;
    push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);
    if(selected != push_SL_setting)
    {
        void* reg_handle;
        
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING, selected, NULL);
        msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
        
        /*inform PHS*/
        reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
        MSF_REGISTRY_SET_PATH(reg_handle, (char*)"/PHS/");
        if (selected == 0)/* Never */
        {
            MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "supprtSL", 0);
        }
        else/* Confirm or Without Confirm*/
        {
            MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "supprtSL", 1);
        }
        MSF_REGISTRY_SET_COMMIT (reg_handle);
        bra_cmn_save_done_dialog();
    }
}

#ifdef BRA_CONFIG_PUSH_TRUSTLIST

static unsigned char*
bra_tl_create_trustlist_item(MSF_UINT32 sort_idx, int type, char *address, int *buf_len)
{
    unsigned char *t;

    *buf_len = 4 + 4 + strlen(address) + 1;
    t = BRA_ALLOC (*buf_len);

    t[0] = (unsigned char)((sort_idx & 0xFF000000) >> 24);
    t[1] = (unsigned char)((sort_idx & 0x00FF0000) >> 16);
    t[2] = (unsigned char)((sort_idx & 0x0000FF00) >> 8);
    t[3] = (unsigned char)((sort_idx & 0x000000FF));

    t[4] = (unsigned char)((type & 0xFF000000) >> 24);
    t[5] = (unsigned char)((type & 0x00FF0000) >> 16);
    t[6] = (unsigned char)((type & 0x0000FF00) >> 8);
    t[7] = (unsigned char)((type & 0x000000FF));

    strcpy ((char *)&t[8], address);
    return t;
}


static int
bra_tl_parse_trustlist_item(unsigned char *buffer, int size, bra_push_trustList_file_item_t* p)
{
    int   address_len;

    if ((buffer == NULL) || (size < 9))
        return -1;

    p->sort_idx =  (buffer[0] << 24);
    p->sort_idx += (buffer[1] << 16);
    p->sort_idx += (buffer[2] << 8);
    p->sort_idx += (buffer[3]);
    
    /*Get trust list type*/
    p->type =  (buffer[4] << 24);
    p->type += (buffer[5] << 16);
    p->type += (buffer[6] << 8);
    p->type += (buffer[7]);

    address_len = strlen((char*)&buffer[8]);
    if (size < (9 + address_len))
    {
        return -1;
    }

    /*Get trust list address*/
    p->address = msf_cmmn_strdup (MSF_MODID_BRA, (char*)&buffer[8]);

    return 1;
}


static int
bra_tl_add_trustlist_item (MSF_UINT32 sort_idx, int idx, MSF_UINT8 type, MSF_INT32 address)
{
    bra_push_trustList_item_t *tl_item;
    bra_push_trustList_item_t *p;
    bra_push_trustList_item_t *prev;
    
    tl_item = BRA_ALLOCTYPE(bra_push_trustList_item_t);
    
    if(tl_item == NULL)
        return 0;
    
    tl_item->sort_idx = sort_idx;
    tl_item->idx = idx;
    tl_item->type = type;
    tl_item->address = address;
    tl_item->next = NULL;
    
    /*Increase number of trust list*/
    bra_tl_n_items++;
    
    p = bra_tl_list;
    prev = bra_tl_list;
    
    if(p != NULL)
    {
        while (p != NULL)
        {
            if(p->sort_idx < tl_item->sort_idx)
            {
                prev = p;
                p = p->next;
                continue;
            }
            
            if (p == bra_tl_list)
            {
                tl_item->next = bra_tl_list;
                bra_tl_list  = tl_item;
            }
            else
            {
                prev->next = tl_item;
                tl_item->next = p;
            }
            return 1;
        }
        prev->next = tl_item;
    }
    else
    {
        bra_tl_list = tl_item;
    }
    
    return 1;
}


static bra_push_trustList_item_t
*bra_tl_remove_trustlist_item(int idx)
{
    bra_push_trustList_item_t *remove;
    bra_push_trustList_item_t *previous;
    int i = 0;
    
    if(bra_tl_list == NULL)
        return NULL; 
    
    /*Decrease number of trust list*/
    bra_tl_n_items--;
    
    remove   = bra_tl_list;
    previous = bra_tl_list;
    
    while (remove != NULL)
    {
        if (i++ == idx)
        {
            if (remove == bra_tl_list)
                bra_tl_list = remove->next;
            else
                previous->next = remove->next;
            
            return remove;
        }
        previous = remove;
        remove = remove->next;
    }
    
    return NULL;
}


static void
bra_tl_destroy_list()
{
    bra_push_trustList_item_t *remove;
    
    remove = bra_tl_list;
    
    while (remove != NULL)
    {
        bra_tl_list = remove->next;
        MSF_WIDGET_RELEASE (remove->address);
        BRA_FREE (remove);
        remove = bra_tl_list;
    }

    bra_tl_n_items = 0;
}


static void 
bra_push_trustlist_destroy(void)
{
    bra_tl_destroy_list();
    bra_file_close (bra_tl_file_handle);
    bra_tl_file_handle = NULL;
    bra_tl_state = BRA_TRUSTLIST_STATE_NULL;
    if (bra_tl_input.address)
    {
        MSF_WIDGET_RELEASE (bra_tl_input.address);
        bra_tl_input.address = NULL;
    }
}


static void
bra_tl_initialize_trustlists (int idx, int eof, void* block, int size)
{
    bra_push_trustList_file_item_t  p;
    MsfStringHandle                 address;
    
    if (eof == 0)
    {
        if (bra_tl_parse_trustlist_item ((unsigned char *)block, size, &p) < 0)
            return;

        address = BRA_STRCONV (p.address);

        bra_tl_add_trustlist_item (p.sort_idx, idx, p.type, address);
        
        BRA_FREE (p.address);
    }
    else
    {
        /*Finished*/
        if (bra_tl_state == BRA_TRUSTLIST_STATE_SETTOPHS)
        {
            /*inform PHS trust list*/
            bra_tl_setToPHS(BRA_ADDRTYPE_PHONENO);
            bra_tl_setToPHS(BRA_ADDRTYPE_IPV4);
            bra_tl_setToPHS(BRA_ADDRTYPE_TEXT);

            /*release trust list*/
            bra_push_trustlist_destroy();
        }
    }
}


void
bra_push_trustList_init(bra_set_trustlist_state_t state)
{
    int push_trust_setting;


    ASSERT (bra_prof_is_profile_loaded(0));

    bra_tl_state = state;
    bra_tl_list = NULL;
    bra_tl_n_items = 0;
    bra_tl_input.address = 0;

    if (state == BRA_TRUSTLIST_STATE_SETTOPHS)
    {
        push_trust_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_TRUSTSETTING);
        if (push_trust_setting == 0) /*when not set trust setting*/
        {
            bra_tl_setToPHS(BRA_ADDRTYPE_PHONENO);
            bra_tl_setToPHS(BRA_ADDRTYPE_IPV4);
            bra_tl_setToPHS(BRA_ADDRTYPE_TEXT);
            return;
        }
    }
    bra_file_init (BRA_CFG_TRUSTLIST_FILE_PATH, 
        &bra_tl_file_handle,
        BRA_TRUSTLIST_MAX_FILE_SIZE, 
        BRA_TRUSTLIST_INITIAL_SIZE, 
        BRA_TRUSTLIST_DEFRAG_LIMIT, 
        BRA_TRUSTLIST_SIZE_INCREMENT,
        bra_tl_initialize_trustlists);
}


static void
bra_tl_update_menu_items (bra_set_menu_t *win)
{
    int        i;
    bra_push_trustList_item_t *tl_list;
    
    i = 0;
    tl_list = bra_tl_list;
    
    MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, i, BRA_STR_ADD_NEW, 0, bra_cmn_get_list_num_image(i), 0, 0);
    i++;

    while (tl_list != NULL)
    {
        MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, i, tl_list->address, 0, bra_cmn_get_list_num_image(i), 0, 0);
        i++;
        tl_list = tl_list->next;
    }
}


/*
* Destroys the trust list main menu
*/
static void
bra_delete_push_TrustList_menu (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->accept);
    MSF_WIDGET_RELEASE (p->back);
    
    BRA_FREE (p);
    
    bra_push_trustlist_destroy();
    bra_tl_selected_trustList = -1;
}


/*
* Focus the trust list main menu
*/
static void
bra_trustlist_in_focus(bra_win_t *win)
{
    if(bra_tl_selected_trustList >= 0)
        MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->win_hdl, bra_tl_selected_trustList, MSF_CHOICE_ELEMENT_SELECTED);
}


static void
bra_delete_push_tl_addNew_menu (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->accept);
    MSF_WIDGET_RELEASE (p->back);
    
    BRA_FREE (p);
}


static void
bra_tl_save_response(int i)
{
    bra_cmn_saved_dialog();
}


static bra_push_trustList_item_t *
bra_tl_get_trustlist_item(int idx)
{
    int i = 0;
    bra_push_trustList_item_t *tl_item;
    
    tl_item = bra_tl_list;
    
    while ((i++ < idx) && (tl_item != NULL))
    {
        tl_item = tl_item->next;
    }
    
    return tl_item;
}


static void
bra_tl_update_trustlist_menu (MSF_INT32 label)
{
    bra_set_menu_t *win;
    
    win = (bra_set_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_TRUSTLIST));
    
    if (win == NULL)
        return;
    
    if(bra_tl_selected_trustList >= 0)
        MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, 
        bra_tl_selected_trustList, 
        label, 
        0, 
        bra_cmn_get_list_num_image(bra_tl_selected_trustList), 
        0, 
        0);
    
    MSF_WIDGET_SET_IN_FOCUS (win->window, 1);
}


static void
bra_tl_delete_trustlist_item (int idx, bra_file_op_callback_t callback)
{
    bra_push_trustList_item_t   *item;
    bra_set_menu_t              *win;
    
    win = (bra_set_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_TRUSTLIST));

    item = bra_tl_remove_trustlist_item (idx);
    
    if(item == NULL)
        return;
    
    bra_file_delete_block (bra_tl_file_handle, item->idx, callback);
    
    MSF_WIDGET_RELEASE (item->address);
    BRA_FREE (item);
}


static int
bra_push_tl_input_save_response(char* text, MSF_UINT8 type)
{
    MSF_UINT32                  sort_idx;
    int                         idx;
    unsigned char               *buffer;
    int                         buf_len;
    MsfStringHandle             str;
    bra_push_trustList_item_t   *tl_item;
    int                         i = 0;

    str = BRA_STRCONV(text);

    /* check for duplicate*/
    tl_item = bra_tl_list;
    
    while (tl_item != NULL)
    {
        if (MSF_WIDGET_STRING_COMPARE(str, tl_item->address) == 0)
        {
            /*select to edit the trust list item, but not modify*/
            if (i + 1 == bra_tl_selected_trustList)
            {
                bra_cmn_saved_dialog();
            }
            else
            {
                HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAME_ITEM_EXIT, MsfWarning,0);
            }
            MSF_WIDGET_RELEASE (str);
            return 0;
        }
        tl_item = tl_item->next;
        i++;
    }

    /* add */
    if (bra_tl_selected_trustList == 0) /*new item*/
    {
        sort_idx = MSF_TIME_GET_CURRENT();
    }
    else                                /*edit item*/
    {
        sort_idx = bra_tl_get_trustlist_item (bra_tl_selected_trustList - 1)->sort_idx;
    }
    buffer = bra_tl_create_trustlist_item (sort_idx, type, text, &buf_len);

    /*update menu*/
    bra_tl_update_trustlist_menu (str);

    if (bra_tl_selected_trustList > 0)  /*edit item*/
    {
        /*Remove old trust list item*/
        bra_tl_delete_trustlist_item (bra_tl_selected_trustList - 1, NULL);
    }
    
    /*save trust list item*/
    idx = bra_file_write_block (bra_tl_file_handle, 
        buffer, 
        buf_len, 
        bra_tl_save_response);
    BRA_FREE (buffer);

    /*Add to ram list*/
    bra_tl_add_trustlist_item (sort_idx, idx, type, str);

    if (bra_tl_selected_trustList == 0) /*new item*/
    {
        bra_set_menu_t *win;

        win = (bra_set_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_TRUSTLIST));
        if(win)
        {
            bra_tl_update_menu_items(win);
            MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, bra_tl_n_items, MSF_CHOICE_ELEMENT_SELECTED);
        }
    }

    bra_tl_setToPHS(type);
    return 1;
}


void
bra_push_trustList_addItem(char *address, MSF_UINT8 type)
{
    bra_push_trustList_init(BRA_TRUSTLIST_STATE_OUT_ADDITEM);
    
    if (bra_tl_n_items >= BRA_PUSH_MAX_TRUSTLIST_NO)
    {
        bra_dlg_create_dlg (MsfError,
            BRA_STR_ERR_TRUSTLIST_FULL, 
            BRA_STR_OK, 
            0,
            0, 
            NULL);
        
        bra_push_trustlist_destroy();
        return;
    }
    
    bra_tl_selected_trustList = 0;
    bra_push_tl_input_save_response(address, type);
    
    bra_push_trustlist_destroy();
}


static void
bra_delete_push_tl_input_form(bra_win_t *win)
{
    bra_push_tl_input_form_t *p;
    
    p = (bra_push_tl_input_form_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 
    
    MSF_WIDGET_RELEASE (p->windowHandle); 
    MSF_WIDGET_RELEASE (p->backActionHandle);
    MSF_WIDGET_RELEASE (p->okActionHandle);
    /*MSF_WIDGET_RELEASE (p->InputString);*/
    
    if(!bra_win_get_window(BRA_WIN_ID_PUSH_TRUSTLIST)
        && p->callback == bra_push_tl_input_save_response)
        bra_push_trustlist_destroy();
    
    BRA_FREE (p);
}


static void
bra_action_push_tl_input_save_confirmation(MsfActionType response)
{
    if (response == MsfOk)
    {
        char    *text;

        text = BRA_ALLOC (MSF_WIDGET_STRING_GET_LENGTH((MsfStringHandle)bra_tl_input.address, 1, MsfUtf8) + 1);
        MSF_WIDGET_STRING_GET_DATA ((MsfStringHandle)bra_tl_input.address, text, MsfUtf8);
        bra_push_tl_input_save_response(text, bra_tl_input.type);
        BRA_FREE (text);

        bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);
    }
    else
    {
        if (bra_tl_selected_trustList == 0)
        {
            bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST_ADD);
        }
        else
        {
            bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST_EDIT);
        }
    }
/*    if (bra_tl_input.address)
    {
        MSF_WIDGET_RELEASE(bra_tl_input.address);
        bra_tl_input.address = NULL;
    }*/
}


static void
bra_action_push_tl_input_form(bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_push_tl_input_form_t    *p;
    MsfStringHandle             msfStr; 
    
    p = (bra_push_tl_input_form_t *)(win);
    
    if (bra_action == p->okActionHandle)
    {
        int    len;
        char   *str;
        char   *pStr;

        msfStr = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_BRA, p->windowHandle, 0);
        len = MSF_WIDGET_STRING_GET_LENGTH(msfStr, 1, MsfUtf8) + 1;
        str = BRA_ALLOC(len);
        MSF_WIDGET_STRING_GET_DATA(msfStr, str, MsfUtf8);

        switch(p->type)
        {
        case BRA_ADDRTYPE_PHONENO:
            /*check input, phone number must be number*/
            pStr = str;
            while (*pStr <= '9' && *pStr >= '0' && *pStr != '\0')
            {
                pStr++;
            }

            if (*pStr != '\0')
            {
                MSF_WIDGET_RELEASE(msfStr); 
                BRA_FREE(str);
                bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);   
                bra_dlg_create_dlg (MsfError,
                    BRA_STR_ERR_INVALID_PHONENO, 
                    BRA_STR_OK, 
                    0,
                    0, 
                    NULL);
                return;
            }
            break;
#ifndef BRA_USE_CTK_INLINE
        case BRA_ADDRTYPE_IPV4:
            /*check input, ip can not be zero*/
            pStr = str;
            while ((*pStr == '0' || *pStr == '.') && *pStr != '\0')
            {
                pStr++;
            }

            if (*pStr == '\0')
            {
                MSF_WIDGET_RELEASE(msfStr); 
                BRA_FREE(str);
                bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);   
                bra_dlg_create_dlg (MsfError,
                    BRA_STR_ERR_INVALID_IP, 
                    BRA_STR_OK, 
                    0,
                    0, 
                    NULL);    
                return;
            }
            break;
#endif
        case BRA_ADDRTYPE_TEXT:
            /*check input*/
            /*if (!check_url(str) || !bra_cmn_url_is_valid(str))
            {
                MSF_WIDGET_RELEASE(msfStr); 
                BRA_FREE(str);
                bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);   
                bra_dlg_create_dlg (MsfError,
                    BRA_STR_ERR_INVALID_DOMAINNAME, 
                    BRA_STR_OK, 
                    0,
                    0, 
                    NULL);    
                return;
            }*/
            break;
        default:
            MSF_WIDGET_RELEASE(msfStr); 
            BRA_FREE(str);
            return;
        }
        BRA_FREE(str);

        if (bra_tl_input.address)
        {
            MSF_WIDGET_RELEASE(bra_tl_input.address);
        }
        bra_tl_input.address = msfStr;
        bra_tl_input.type = p->type;
        bra_tl_input.next = NULL;

        bra_dlg_create_dlg (MsfConfirmation,
            BRA_STR_SAVE_ASK, 
            BRA_STR_YES, 
            BRA_STR_NO,
            0, 
            bra_action_push_tl_input_save_confirmation);

    }
    else if (bra_action == p->backActionHandle)
    {
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    }
}


#ifdef BRA_USE_CTK_INLINE
static void
bra_ctk_delete_push_tl_input_form (ctk_screen_handle scrid)
{
    MSF_WIDGET_REMOVE (bra_win_get_screen (), ctk_set_tl_ip_menu->window); 
    MSF_WIDGET_RELEASE (ctk_set_tl_ip_menu->window);
    ctk_set_tl_ip_menu = NULL;
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0); 
}


static void
bra_delete_push_tl_input_form_ctk (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    if(ctk_set_tl_ip_menu)
    {
        MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
        MSF_WIDGET_RELEASE (p->window);
        ctk_set_tl_ip_menu = NULL; 
    }
    BRA_FREE(p);
}


static void
bra_ctk_action_push_tl_input_form (ctk_screen_handle scrid)
{
    ctk_layout_handle   layoutid =ctk_screen_get_layout(scrid);
    char                *gateway;
    
    // check gateway 
    gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, 1);

    if (gateway == NULL || strlen(gateway) == 0 || !check_ip(gateway)) 
    {
        BRA_FREE(gateway);
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);   
        bra_dlg_create_dlg (MsfError,
            BRA_STR_ERR_INVALID_IP, 
            BRA_STR_OK, 
            0,
            0, 
            NULL);    
        return;
    }
    if (bra_tl_input.address)
    {
        MSF_WIDGET_RELEASE(bra_tl_input.address);
    }
    bra_tl_input.address = BRA_STRCONV(gateway);
    bra_tl_input.type = BRA_ADDRTYPE_IPV4;
    bra_tl_input.next = NULL;
    
    bra_dlg_create_dlg (MsfConfirmation,
        BRA_STR_SAVE_ASK, 
        BRA_STR_YES, 
        BRA_STR_NO,
        0, 
        bra_action_push_tl_input_save_confirmation);

    BRA_FREE(gateway);
}
#endif


static void
bra_create_push_tl_input_form(MsfStringHandle defStr, bra_push_trustlist_edit_response_t callback, MSF_UINT8 type)
{
    bra_push_tl_input_form_t *win;
    const MsfPosition win_pos = BRA_CFG_MENU_POS;
    
#ifdef BRA_USE_CTK_INLINE
    if (type == BRA_ADDRTYPE_IPV4)
    {
        ctk_screen_handle				scrid;
        ctk_layout_handle				layoutid;
        ctk_inline_create_struct		layout_create;
        unsigned char                   ip[4];
        char                            gateway[16];
        MsfPosition                     winPos = {0,0};  

        ctk_set_tl_ip_menu = BRA_ALLOCTYPE (bra_set_menu_t);

        layoutid = bra_cmn_ctk_init_layout(&layout_create,
            2,
            widget_get_title_icon(0),
            BRA_STR_ID_GATEWAY,
            bra_ctk_delete_push_tl_input_form,
            KAL_FALSE);

        bra_cmn_ctk_add_caption(layoutid, 0, BRA_STR_ID_GATEWAY, (MSF_UINT16)bra_cmn_get_list_num_image_enum(0));

        MSF_WIDGET_STRING_GET_DATA(defStr, gateway, MsfUtf8);
        memset(ip, 0, 4);
        bra_cmn_get_address(gateway, ip);
        bra_cmn_ctk_add_ip_editor(layoutid, 1, ip);

        scrid = bra_cmn_ctk_screen_create(layoutid, bra_ctk_action_push_tl_input_form);

        // create form
        ctk_set_tl_ip_menu->window = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);    

        bra_win_show_window (BRA_WIN_ID_SET_CONN_TYPE_DLG, 
            (bra_win_t*)ctk_set_tl_ip_menu, 
            &winPos, 
            bra_delete_push_tl_input_form_ctk,
            NULL,
            NULL);				   

        return;
    }
#endif

    win = BRA_ALLOCTYPE (bra_push_tl_input_form_t);
    
    switch(type)
    {
    case BRA_ADDRTYPE_PHONENO:
        win->windowHandle = MSF_WIDGET_EDITOR_CREATE(MSF_MODID_BRA, 0, defStr, MsfPhoneNumber, 
            BRA_SET_MAX_PHONENO_SIZE, 1, NULL, 0, 0);
        break;
#ifndef BRA_USE_CTK_INLINE
    case BRA_ADDRTYPE_IPV4:
        win->windowHandle = MSF_WIDGET_EDITOR_CREATE(MSF_MODID_BRA, 0, defStr, MsfIpAddress, 
            BRA_SET_MAX_IP_SIZE, 1, NULL, 0, 0);
        break;
#endif
    case BRA_ADDRTYPE_TEXT:
        win->windowHandle = MSF_WIDGET_EDITOR_CREATE(MSF_MODID_BRA, 0, defStr, MsfUrl, 
            BRA_CFG_MAX_NBR_CHARS_URL, 1, NULL, 0, 0);
        break;
    default:
        BRA_FREE(win);
        return;
    }
    
    if(!win->windowHandle)
    {    
        BRA_FREE(win);    
        return;
    }
    
    /* Action OK */
    win->okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
    MSF_WIDGET_ADD_ACTION(win->windowHandle, win->okActionHandle);
    /* Action back */
    win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 3, 0x8000);
    MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);
    
/*    win->InputString = defStr;*/
    win->callback = callback;
    win->type = type;
    
    switch(type)
    {
    case BRA_ADDRTYPE_PHONENO:
        MSF_WIDGET_SET_TITLE(win->windowHandle, BRA_STR_PHONE_NO);
        break;
#ifndef BRA_USE_CTK_INLINE
    case BRA_ADDRTYPE_IPV4:
        MSF_WIDGET_SET_TITLE(win->windowHandle, BRA_STR_GATEWAY);
        break;
#endif
    case BRA_ADDRTYPE_TEXT:
        MSF_WIDGET_SET_TITLE(win->windowHandle, BRA_STR_DOMAIN_NAME);
        break;
    default:
        BRA_FREE(win);
        return;
    }
    MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle, MSF_WINDOW_PROPERTY_TITLE);
    
    bra_win_show_window (BRA_WIN_ID_PUSH_TRUSTLIST_INPUT, 
        (bra_win_t*)win, 
        (MsfPosition*)&win_pos, 
        bra_delete_push_tl_input_form,
        NULL,
        bra_action_push_tl_input_form);
}


static void
bra_action_push_tl_addNew_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_set_menu_t *p;
    int i = 0;
    
    p = (bra_set_menu_t *)(win);
    
    if (bra_action == p->back)
    {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->accept)
    {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*phone no*/
            bra_create_push_tl_input_form (MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, "", MsfUtf8, 1, 0),
                                           bra_push_tl_input_save_response, BRA_ADDRTYPE_PHONENO);
        }
        else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*IP Address*/
            bra_create_push_tl_input_form (MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, "", MsfUtf8, 1, 0), 
                                           bra_push_tl_input_save_response, BRA_ADDRTYPE_IPV4);
        }
        else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*Domain Name*/
            bra_create_push_tl_input_form (MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, "", MsfUtf8, 1, 0),
                                           bra_push_tl_input_save_response, BRA_ADDRTYPE_TEXT);
        }
    }
}

static void
bra_create_push_tl_addNew_menu(void)
{
    bra_set_menu_t      *win;
    MsfPosition          pos = BRA_CFG_MENU_POS;
    MsfDeviceProperties  prop;
    MSF_UINT8            i = 0;
    
    if (bra_tl_n_items >= BRA_PUSH_MAX_TRUSTLIST_NO)
    {
        bra_dlg_create_dlg (MsfError,
            BRA_STR_ERR_TRUSTLIST_FULL, 
            BRA_STR_OK, 
            0,
            0, 
            NULL);
        return;
    }

    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    
    win = BRA_ALLOCTYPE (bra_set_menu_t);
    
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
    win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
        MsfImplicitChoice,
        &prop.displaySize,
        win->accept,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);
    
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_PHONE_NO,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_GATEWAY,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DOMAIN_NAME,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_ADD_NEW);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
    
    MSF_WIDGET_ADD_ACTION (win->window, win->back);
    
    /*Show dialog*/
    bra_win_show_window (BRA_WIN_ID_PUSH_TRUSTLIST_ADD, 
        (bra_win_t*)win, 
        &pos,
        bra_delete_push_tl_addNew_menu,
        NULL,
        bra_action_push_tl_addNew_menu);
}


static void
bra_delete_push_tl_edit_menu (bra_win_t *win)
{
    bra_set_menu_t *p;
    p = (bra_set_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 
    
    MSF_WIDGET_RELEASE (p->window); 
    MSF_WIDGET_RELEASE (p->accept);
    MSF_WIDGET_RELEASE (p->back);
    
    BRA_FREE (p);
}


static void
bra_tl_delete_trustlist_response (int i)
{
    bra_set_menu_t *win;  

    win = (bra_set_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_TRUSTLIST));
    
    if(win)
    {
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
        bra_tl_update_menu_items(win);
        bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);
    }

    bra_cmn_deleted_dialog();
}


static void 
bra_tl_delete_all_trustlist_response (int i)
{
    bra_set_menu_t *win;  

    win = (bra_set_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_TRUSTLIST));
    
    if(win)
    {
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
        if(bra_tl_n_items == 0)
        {
            bra_tl_update_menu_items(win);
            bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);
        }
    }
    
    if(bra_tl_n_items == 0)
        bra_cmn_deleted_dialog();
}


static void 
bra_tl_delete_trustlist_confirmation(MsfActionType response)
{
    if(response == MsfOk)
    {
        BYTE type = bra_tl_get_trustlist_item(bra_tl_selected_trustList - 1)->type;
        bra_tl_delete_trustlist_item (bra_tl_selected_trustList - 1, bra_tl_delete_trustlist_response);
        bra_tl_setToPHS(type);
        bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);
    }
    
}


static void 
bra_tl_delete_all_trustlist_confirmation(MsfActionType response)
{
    if(response == MsfOk)
    {
        MSF_INT8 i;

        for(i = bra_tl_n_items - 1; i >= 0 ; i--)
        {
            bra_tl_delete_trustlist_item(i, bra_tl_delete_all_trustlist_response);
        }
        bra_tl_setToPHS(BRA_ADDRTYPE_PHONENO);
        bra_tl_setToPHS(BRA_ADDRTYPE_IPV4);
        bra_tl_setToPHS(BRA_ADDRTYPE_TEXT);
        
        bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);
    }
}


static void
bra_action_push_tl_edit_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_set_menu_t *p;
    int i = 0;
    
    p = (bra_set_menu_t *)(win);
    
    if (bra_action == p->back)
    {
        /*bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_TRUSTLIST);*/
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->accept)
    {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*edit*/
            char                      *text;
            bra_push_trustList_item_t *pItem;

            pItem = bra_tl_get_trustlist_item (bra_tl_selected_trustList - 1);
            text = BRA_ALLOC (MSF_WIDGET_STRING_GET_LENGTH((MsfStringHandle)pItem->address, 1, MsfUtf8) + 1);
            MSF_WIDGET_STRING_GET_DATA ((MsfStringHandle)pItem->address, text, MsfUtf8);

            bra_create_push_tl_input_form(BRA_STRCONV(text), bra_push_tl_input_save_response, pItem->type);
            BRA_FREE (text);
        }
        else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*delete*/
            bra_dlg_create_dlg (MsfConfirmation,
                BRA_STR_DELETE_ASK, 
                BRA_STR_YES, 
                BRA_STR_NO,
                0, 
                bra_tl_delete_trustlist_confirmation);
        }
        else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
        {
            /*delete all*/
            bra_dlg_create_dlg (MsfConfirmation,
                BRA_STR_DELETE_ALL_ASK, 
                BRA_STR_YES, 
                BRA_STR_NO,
                0,
                bra_tl_delete_all_trustlist_confirmation);
        }
    }
}


static void
bra_create_push_tl_edit_menu(void)
{
    bra_set_menu_t      *win;
    MsfPosition          pos = BRA_CFG_MENU_POS;
    MsfDeviceProperties  prop;
    MSF_UINT8            i = 0;
    
    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    
    win = BRA_ALLOCTYPE (bra_set_menu_t);
    
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
    win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
        MsfImplicitChoice,
        &prop.displaySize,
        win->accept,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);
    
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_EDIT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE_ALL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    
    MSF_WIDGET_SET_TITLE (win->window, BRA_STR_EDIT);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_TITLE);
    
    MSF_WIDGET_ADD_ACTION (win->window, win->back);
    
    /*Show dialog*/
    bra_win_show_window (BRA_WIN_ID_PUSH_TRUSTLIST_EDIT, 
        (bra_win_t*)win, 
        &pos,
        bra_delete_push_tl_edit_menu,
        NULL,
        bra_action_push_tl_edit_menu);
}

            
/*
* Handles trust list main menu events
*/
static void
bra_action_trustlist_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_set_menu_t *p;
    int i = 0; 
    
    p = (bra_set_menu_t *)(win);
    
    if (bra_action == p->back)
    {
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->accept)
    {
        while(i < bra_tl_n_items + 1 && !(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i) & MSF_CHOICE_ELEMENT_SELECTED))
            i++;
        if(i == bra_tl_n_items + 1)
            return;
        bra_tl_selected_trustList = i;

        if (i == 0) /*add new*/
        {
            bra_create_push_tl_addNew_menu();
        }
        else        /*edit*/
        {
            bra_create_push_tl_edit_menu();
        }
    }
}


static void
bra_create_push_TrustList_menu (void)
{
    bra_set_menu_t *win;
    MsfPosition pos = BRA_CFG_MENU_POS;
    MsfDeviceProperties prop;
    
    /* It is not allowed to create trust list menu twice */
    if(bra_tl_file_handle)
        return;

    /*Init trust list whenever create trust list menu*/
    bra_push_trustList_init(BRA_TRUSTLIST_STATE_USERSELECT);
    
    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    
    win = BRA_ALLOCTYPE (bra_set_menu_t);
    
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfSelect,1, 0x8000);
    win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack,1, 0x8000);

    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
        MsfImplicitChoice,
        &prop.displaySize,
        win->accept,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);
    
    MSF_WIDGET_SET_TITLE(win->window, BRA_STR_SET_PUSH_TRUSTLIST);
    MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window, MSF_WINDOW_PROPERTY_TITLE);
    
    MSF_WIDGET_ADD_ACTION(win->window, win->back);

    /*Add menu items*/
    bra_tl_update_menu_items(win);
    
    bra_win_show_window (BRA_WIN_ID_PUSH_TRUSTLIST, 
        (bra_win_t*)win, 
        &pos,
        bra_delete_push_TrustList_menu, 
        bra_trustlist_in_focus,
        bra_action_trustlist_menu);
    
    MSF_WIDGET_SET_IN_FOCUS (bra_win_get_screen(), 1);
}

#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/

static void
bra_action_push_settings_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_set_menu_t *p;
  int i = 0;

  p = (bra_set_menu_t *)(win);

	if (bra_action == p->back)
	{
	  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
	}
	else if (bra_action == p->accept)
	{
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
          /*Enable Push*/
          int on_off_list[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};
          int push_on_off;
          push_on_off = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON);

          bra_dlg_create_opt_menu (BRA_STR_SET_ENABLE_PUSH, 
              2, 
              on_off_list,
              push_on_off,
              bra_enable_push_response);
      }
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
          /*Trust Settings*/
          int trust_setting_list[2] = {BRA_STR_ID_DISABLE, BRA_STR_ID_ALWAYS};
          int push_trust_setting;
          push_trust_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_TRUSTSETTING);
          
          bra_dlg_create_opt_menu (BRA_STR_SET_PUSH_TRUSTSETTING, 
              2, 
              trust_setting_list,
              push_trust_setting,
              bra_push_trustSetting_response);
      }
#endif
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
          /*SL Settings*/
          int SL_setting_list[3] = {BRA_STR_ID_NEVER, BRA_STR_ID_CONFIRM, BRA_STR_ID_WITHOUT_CONFIRM};
          int push_SL_setting;
          push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);
          
          bra_dlg_create_opt_menu (BRA_STR_SET_PUSH_SLSETTING, 
              3,
              SL_setting_list,
              push_SL_setting,
              bra_push_SLSetting_response);
      }
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
      {
          /*Trust List*/
          bra_create_push_TrustList_menu();
      }
#endif
    }
}


static void 
bra_create_push_settings_menu(void)
{
    bra_set_menu_t      *win;
    MsfPosition          pos = BRA_CFG_MENU_POS;
    MsfDeviceProperties  prop;
    MSF_UINT8            i = 0;
    
    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    
    win = BRA_ALLOCTYPE (bra_set_menu_t);
    
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
    win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
        MsfImplicitChoice,
        &prop.displaySize,
        win->accept,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);

    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_ENABLE_PUSH,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_PUSH_TRUSTSETTING,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
#endif
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_PUSH_SLSETTING,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_PUSH_TRUSTLIST,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
#endif

    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_SETTINGS);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
    
    MSF_WIDGET_ADD_ACTION (win->window, win->back);

    /*Show dialog*/
    bra_win_show_window (BRA_WIN_ID_PUSH_SETTING, 
        (bra_win_t*)win, 
        &pos, 
        bra_delete_push_settings_menu, 
        NULL,
        bra_action_push_settings_menu);
}


static void
bra_action_settings_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_set_menu_t *p;
  int i = 0;

  p = (bra_set_menu_t *)(win);

	if (bra_action == p->back)
	{
	  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
	}
	else if (bra_action == p->accept)
	{
#ifdef BRA_CFG_DUAL_SIM
      if(!bra_win_get_window(BRA_WIN_ID_OPT) && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED))
      {
        bra_sim_create_profile_select_sim_menu();
      }
      else
#endif /* BRA_CFG_DUAL_SIM */
    if(bra_set_showProfile == 1 && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED))
		{
      /*Edit Profile*/
      bra_prof_create_profile_menu (BRA_PROF_ID_BRA);
		}
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Browser Option*/
#ifdef BRA_USE_CTK_INLINE
      bra_ctk_create_display_opt_menu ();  
#else
      bra_create_display_opt_menu ();  
#endif
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Push Settings*/
#ifdef BRA_CONFIG_PUSH
          bra_create_push_settings_menu();
#endif /*BRA_CONFIG_PUSH*/
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
#ifdef __MMI_KLG__
      bra_cch_create_menu();
#else		   
      /*Clear Cache*/      
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CLEAR_CACHE_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_cch_delete_confirmation);
#endif                          
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
#ifdef __MMI_KLG__
      bra_cks_create_menu();
#else		   		   
      /*Clear Cookies*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CLEAR_COOKIES_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_cks_clear_conf_response);
#endif                          
		}
#ifdef BRA_CONFIG_SECURITY
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Security Info*/
#ifdef BRA_CONFIG_TEST
      bra_sec_create_menu ();
#else
      /*View Certificates*/
      SECif_viewCertNames(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_GET_ROOT_CERT );      
#endif
		}
#endif

#ifdef __CBM_CM_FEATURE__
     else if(bra_win_get_window(BRA_WIN_ID_OPT) && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED))
     {
       bra_cbm_create_view_bearer_detail_info_menu();
     }
#endif /* __CBM_CM_FEATURE__ */
    }
}

/*
 * This function creates the main settings menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_settings_menu (void)
{
  bra_set_menu_t      *win;
  MsfPosition          pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties  prop;
  MSF_UINT8            i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_set_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
												                     &prop.displaySize,
												                     win->accept,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

   bra_set_showProfile = 0;
   if(!bra_win_get_window(BRA_WIN_ID_OPT))
   {
#ifdef BRA_CFG_DUAL_SIM
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SELECT_SIM,  0, bra_cmn_get_list_num_image(i), 0, TRUE);   
     i++;
#endif /* BRA_CFG_DUAL_SIM */

     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, /*BRA_STR_SELECT_PROFILE*/BRA_STR_EDIT_PROFILE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);   
     i++;
     bra_set_showProfile = 1;
   }     
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BROWSER_OPTIONS,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_PUSH_SETTINGS,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
#ifdef __MMI_KLG__
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CACHE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
#else   
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CLEAR_CACHE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
#endif   
   i++;
#ifdef __MMI_KLG__
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_COOKIES,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
#else   
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CLEAR_COOKIES,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
#endif   
   i++;
#ifdef BRA_CONFIG_SECURITY
#ifdef BRA_CONFIG_TEST
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, /*BRA_STR_SECURITY*/BRA_STR_SECURITY_INFO,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
#else
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, /*BRA_STR_SECURITY*/BRA_STR_TRUSTED_CERTIFICATES,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
#endif
#endif

#ifdef __CBM_CM_FEATURE__
   if(bra_win_get_window(BRA_WIN_ID_OPT))
   {
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_BEARER_DETAIL_INFO, 0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
   }
#endif /* __CBM_CM_FEATURE__ */

    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_SETTINGS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SET_SETTINGS_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_settings_menu, 
                    NULL,
                    bra_action_settings_menu);

}


static void
bra_set_active_selected_profile(void)
{
    bra_prof_restore_act_profile();
    BRAa_setBearerType(bra_prof_get_key_int_value(bra_prof_get_profile_id(), BRA_PROF_KEY_NET_ID));
    
    /* go back to profile menu */
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

    // save + calc checksum
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, 
        BRA_STR_ACTIVATED, 
        MsfPromptSaveDone,0);
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
#endif


#ifdef BRA_USE_CTK_INLINE

#ifdef BRA_CONFIG_HTTP_EXT
static void
bra_delete_conn_type_menu_ctk (bra_win_t *win)
{
  win = win;
  bra_set_free_bra_set_menu(ctk_set_aux_menu);
  ctk_set_aux_menu = NULL;
}

static void
bra_ctk_delete_conn_type_menu (ctk_screen_handle scrid)
{
  scrid = scrid;
  bra_set_free_bra_set_menu(ctk_set_aux_menu);
  ctk_set_aux_menu = NULL;
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0); 
}

static void
bra_ctk_action_conn_type_menu (ctk_screen_handle scrid)
{
  ctk_layout_handle			layoutid =ctk_screen_get_layout(scrid);
  char *tmp_str, *gateway;

  // check gateway 
  gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, 1);
  
  if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
  {
    if(gateway != NULL && strlen(gateway) > 0 && !check_ip(gateway)) 
    {
      BRA_FREE(gateway);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError,0);  
      return;
    }
  }
  else
  {
    if(gateway == NULL || strlen(gateway) == 0 || !check_ip(gateway))
    {
      BRA_FREE(gateway);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError, 0);  
      return;
    }
    {
      unsigned char ip[4];
      memset(ip, 0, 4);
      bra_cmn_get_address(gateway, ip);
      if(ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0)
      {
        BRA_FREE(gateway);
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError,0);  
        return;
      }      
    }
  }
  
  BRA_FREE(ctk_set_menu->ip);
  ctk_set_menu->ip = gateway;
       
  // check port
  if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
  {
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, 3);  
    if(tmp_str == NULL || strlen(tmp_str) == 0)
    {
      BRA_FREE(tmp_str);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_INPUT, MsfError,0);  
      return;
    }
    ctk_set_menu->port = atoi(tmp_str);
    if(ctk_set_menu->port < 0 || ctk_set_menu->port > 65535)
    {
      BRA_FREE(tmp_str);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_INPUT, MsfError,0);  
      return;
    }
    BRA_FREE (tmp_str);
  }
#ifdef BRA_CONFIG_SECURITY
  else if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
  {
    // get security
    int select;
    select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, 3);
    ctk_set_menu->select = select;
  }
#endif    
  bra_ctk_update_conn_type_display(ctk_set_menu->conn_type, 1);
  bra_ctk_delete_conn_type_menu(scrid);
}

static void
bra_ctk_create_conn_type_menu (int change)
{
  MsfPosition   win_pos = {0,0};  

  ctk_screen_handle				scrid;
  ctk_layout_handle				layoutid;
  ctk_inline_create_struct		layout_create;
  char *tmp_str;


  bra_set_free_bra_set_menu(ctk_set_aux_menu); 
  ctk_set_aux_menu = bra_set_alloc_bra_set_menu();

  if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
  {
    // ctk layout
    layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                       4,
                                       widget_get_title_icon(0),
                                       BRA_STR_ID_EDIT,
                                       bra_ctk_delete_conn_type_menu,
                                       KAL_FALSE);
  }
  else if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  {
    // ctk layout
    layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                       2,
                                       widget_get_title_icon(0),
                                       BRA_STR_ID_EDIT,
                                       bra_ctk_delete_conn_type_menu,
                                       KAL_FALSE);  
  }                                     
  else
  {
#ifdef BRA_CONFIG_SECURITY   
    // ctk layout
    layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                       4,
                                       widget_get_title_icon(0),
                                       BRA_STR_ID_EDIT,
                                       bra_ctk_delete_conn_type_menu,
                                       KAL_FALSE);   
#else
    // ctk layout
    layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                       2,
                                       widget_get_title_icon(0),
                                       BRA_STR_ID_EDIT,
                                       bra_ctk_delete_conn_type_menu,
                                       KAL_FALSE);   
#endif                                       
  }
                                         

  // gateway caption
  if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
    bra_cmn_ctk_add_caption(layoutid, 0, BRA_STR_ID_PRX_ADDR, (MSF_UINT16)bra_cmn_get_list_num_image_enum(0));
  else
    bra_cmn_ctk_add_caption(layoutid, 0, BRA_STR_ID_GATEWAY, (MSF_UINT16)bra_cmn_get_list_num_image_enum(0));

  // gateway editor
  {
    unsigned char ip[4];
    memset(ip, 0, 4);
    bra_cmn_get_address(ctk_set_menu->ip, ip);
    bra_cmn_ctk_add_ip_editor(layoutid, 1, ip);    
  }

  // port caption  
  if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
  {
    bra_cmn_ctk_add_caption(layoutid, 2, BRA_STR_ID_PRX_PORT, bra_cmn_get_list_num_image_enum(1));
    // port input
    tmp_str = bra_cmn_int_to_str (ctk_set_menu->port);  
    bra_cmn_ctk_add_single_line_editor(layoutid, 3, BRA_SET_MAX_PORT_SIZE, tmp_str);
    BRA_FREE(tmp_str);
  }
#ifdef BRA_CONFIG_SECURITY  
  else if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
  {
    MSF_UINT16    on_off_strid[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};  
    
    // security caption
    bra_cmn_ctk_add_caption(layoutid, 2, BRA_STR_ID_SECURITY, (MSF_UINT16)bra_cmn_get_list_num_image_enum(1));
  
    // security selector
    bra_cmn_ctk_add_select(layoutid, 3, 2, on_off_strid, 
                          ctk_set_menu->select) ;
  }  
#endif  
  
  scrid = bra_cmn_ctk_screen_create(layoutid, bra_ctk_action_conn_type_menu);

  // create form
  ctk_set_aux_menu->window = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);    
  if(change)
    ctk_inline_set_modified(layoutid);

	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SET_CONN_TYPE_DLG, 
                       (bra_win_t*)ctk_set_aux_menu, 
                       &win_pos, 
                       bra_delete_conn_type_menu_ctk, 
                       NULL,
                       NULL);				   
}

#endif /* BRA_CONFIG_HTTP_EXT */

static void
bra_delete_profile_custom_menu_ctk (bra_win_t *win)
{
  win = win;
  bra_set_free_bra_set_menu(ctk_set_menu);
  ctk_set_menu = NULL;
}

static void
bra_ctk_delete_profile_custom_menu (ctk_screen_handle scrid)
{
  scrid = scrid;
  bra_set_free_bra_set_menu(ctk_set_menu);
  ctk_set_menu = NULL;
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0); 
}


static bra_set_menu_t*
bra_set_alloc_bra_set_menu(void)
{
    bra_set_menu_t *menu;

    menu = BRA_ALLOCTYPE(bra_set_menu_t);
    menu->window = 0;
    menu->accept = 0;
    menu->back= 0;
    menu->ip = NULL;
    return menu;
}


static void
bra_set_free_bra_set_menu(bra_set_menu_t  *menu)
{
  if (menu)
  {
    MSF_WIDGET_REMOVE (bra_win_get_screen (), menu->window); 
    MSF_WIDGET_RELEASE (menu->window);
    MSF_WIDGET_RELEASE (menu->accept);
    MSF_WIDGET_RELEASE (menu->back);
    if (menu->ip)
      BRA_FREE(menu->ip);
    BRA_FREE(menu);
   }
}

static void
bra_ctk_action_profile_custom_confirmation (MsfActionType response)
{
  ctk_screen_handle scrid;
  ctk_layout_handle layoutid;
  char *tmp_str, *gateway;
  int shift = 0;
#if !defined(BRA_CONFIG_HTTP_EXT)  
  int select; 
#endif

  scrid = HDIa_widgetCtkGetScreenHandle(ctk_set_menu->window);

  if(response == MsfOk)
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVING, MsfInfo, 5000);          

    layoutid =ctk_screen_get_layout(scrid);      

    // get name
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_RENAME);
    bra_set_rename_profile_response(tmp_str);

    // get homepage
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_HOMEPAGE);
#ifdef BRA_CONFIG_MMS
    if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
      bra_title_mmsc_response(BRA_CMN_HNV(NULL), BRA_CMN_HNV(tmp_str));
    else
#endif
      bra_title_url_response(BRA_CMN_HNV(NULL), BRA_CMN_HNV(tmp_str));
    BRA_FREE(tmp_str);

#ifdef BRA_CFG_CONN_ALWAYS_ASK  
    bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_IS_ASK, ctk_set_menu->is_ask, NULL); //BRA type is ok, just not CMN
#endif

    // get data account
#ifdef BRA_CFG_PROF_FALLBACK
    if (ctk_set_menu->dual_net_id) {
      bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL, 1, NULL);
      bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, ctk_set_menu->net_id, NULL);
      bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS, ctk_set_menu->net_id, NULL);
      bra_prof_change_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM, ctk_set_menu->net_id_sec, NULL);
    } else {
      bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL, 0, NULL);
      bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, ctk_set_menu->net_id, NULL);
    }
#else
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, ctk_set_menu->net_id, NULL);
#endif


   // get connection type
#if defined(BRA_CONFIG_HTTP)    
    select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, PROF_CUSTOM_CONN_TYPE - shift);
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", select + 1, NULL);
#elif defined(BRA_CONFIG_HTTP_EXT)
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", ctk_set_menu->conn_type, NULL);
#else
    select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, PROF_CUSTOM_CONN_TYPE - shift);
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", select + 2, NULL);
#endif

    // get gateway
#if defined(BRA_CONFIG_HTTP)
    gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, PROF_CUSTOM_GATEWAY - shift);
#elif defined(BRA_CONFIG_HTTP_EXT)
    shift += 2;
    gateway = BRA_ALLOC(strlen(ctk_set_menu->ip)+1);
    strcpy(gateway, ctk_set_menu->ip);
#else
    gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, PROF_CUSTOM_GATEWAY - shift);
#endif

    bra_set_prx_addr_response(gateway);

    // get port
#if defined(BRA_CONFIG_HTTP)
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, PROF_CUSTOM_SECURITY - shift);
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, atoi(tmp_str), NULL);
    BRA_FREE (tmp_str);
#elif defined(BRA_CONFIG_HTTP_EXT)
    shift += 2;
    if(ctk_set_menu->conn_type == BRA_SET_CONNECTION_TYPE_HTTP)
      bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, ctk_set_menu->port, NULL);
#ifdef BRA_CONFIG_SECURITY      
    else
      bra_conn_enable_sec_response(ctk_set_menu->select);
#else
    else
      bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 0, NULL);
#endif      
#else
    if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
    {
      shift += 2;
    }
    else
    {
#ifdef BRA_CONFIG_SECURITY
      // get security
      select = bra_cmn_ctk_get_select_result(layoutid, CTK_INLINE_ITEM_TYPE_SELECT, PROF_CUSTOM_SECURITY - shift);
      bra_conn_enable_sec_response(select);
#else 
      shift += 2;     
#endif      
    }
#endif
  
    // get username
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_UID - shift);
    bra_set_prx_uid_response(tmp_str);

    // get password
    tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_PWD - shift);
    bra_prof_change_key_str_value (BRA_PROF_ID_BRA, "prx_pwd", tmp_str, NULL);
    BRA_FREE (tmp_str);

    // save + calc checksum
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);

    // change titlebar icon
    {
/*
      int act_id;
      if (bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
        act_id = bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_PROF_ID);
      else
      {
        act_id = bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
      }

      if (act_id == bra_prof_get_absolute_profile())
*/
      if (bra_prof_is_bra_profile_in_active_use(bra_prof_get_profile_id(), bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()) ||
          bra_prof_is_mms_profile_in_active_use(bra_prof_get_profile_id(), bra_prof_get_profile_sim_id(), bra_prof_get_absolute_profile()))
      {
        BRAa_setBearerType(bra_prof_get_key_int_value(bra_prof_get_profile_id(), BRA_PROF_KEY_NET_ID));
      }
    }
    bra_cmn_saved_dialog();
  }
  bra_ctk_delete_profile_custom_menu(scrid);
}

static void
bra_ctk_action_profile_custom_menu (ctk_screen_handle scrid)
{
  ctk_layout_handle			layoutid =ctk_screen_get_layout(scrid);
     
#if defined(BRA_CONFIG_HTTP_EXT)
  char *homepage;
#else
  char *gateway;
  int shift = 0;
#ifdef BRA_CONFIG_HTTP  
  char *tmp_str;  
#endif  
#endif    
#ifdef BRA_CONFIG_MMS
  char *buf;  
  MSF_UINT32 strid;
#endif    

#if defined(BRA_CONFIG_HTTP)  
  gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, PROF_CUSTOM_GATEWAY - shift);
  if(gateway != NULL && strlen(gateway) > 0 && !check_ip(gateway))
  {
    BRA_FREE(gateway);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError,0);  
    return;
  }
  BRA_FREE(gateway);
#elif defined(BRA_CONFIG_HTTP_EXT)
#ifdef BRA_CONFIG_MMS
  /* ensures MMS Server URL does exist */
  if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS) {
    homepage = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_HOMEPAGE);
    if(!check_url(homepage) || !bra_cmn_url_is_valid(homepage))
    {
      BRA_FREE(homepage);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_URL, MsfError,0);
      return;
    }
    BRA_FREE(homepage);
  }
#endif  /* BRA_CONFIG_MMS */
#else
  gateway = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_IP4, PROF_CUSTOM_GATEWAY - shift);
  if(gateway == NULL || strlen(gateway) == 0 || !check_ip(gateway))
  {
    BRA_FREE(gateway);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError,0);  
    return;
  }
  {
    unsigned char ip[4];
    memset(ip, 0, 4);
    bra_cmn_get_address(gateway, ip);
    if(ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0)
    {
      BRA_FREE(gateway);
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_INVALID_IP, MsfError,0);  
      return;
    }      
  }
  BRA_FREE(gateway);
#endif

#ifdef BRA_CONFIG_HTTP
  // check port
  tmp_str = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, PROF_CUSTOM_SECURITY - shift);  
  if(tmp_str == NULL || strlen(tmp_str) == 0)
  {
    BRA_FREE(tmp_str);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_INPUT, MsfError,0);  
    return;
  }
  BRA_FREE (tmp_str);
#endif

#ifdef BRA_CONFIG_MMS
	/* Validate the homepage setting against MMSC */
	if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS) {
	   buf = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, PROF_CUSTOM_HOMEPAGE);
		strid = meaCheckMmscSetting(buf);
		BRA_FREE(buf);
		if(strid != 0) {
			HDIa_widgetExtShowPopup(MSF_MODID_BRA, MSF_WIDGET_STRING_GET_PREDEFINED(strid), MsfError, 0);          
			return;
		}
	}
#endif

  bra_dlg_create_dlg (MsfConfirmation,
                      BRA_STR_SAVE_ASK, 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_ctk_action_profile_custom_confirmation);
}

void 
bra_ctk_create_profile_custom_menu (void)
{
  MsfPosition   win_pos = {0,0};
#if defined(BRA_CONFIG_HTTP) || defined(BRA_CONFIG_HTTP_EXT)
  MSF_UINT16    conn_type_strid[3] = {BRA_STR_ID_HTTP, BRA_STR_ID_CONN_LESS,BRA_STR_ID_CONN_ORIENT};
#else
  MSF_UINT16    conn_type_strid[2] = {BRA_STR_ID_CONN_LESS, BRA_STR_ID_CONN_ORIENT};
#endif  
  int           i = 0, shift = 0;  

  ctk_screen_handle				scrid;
  ctk_layout_handle				layoutid;
  ctk_inline_create_struct		layout_create;

  char *tmp_str;
#ifdef BRA_CFG_PROF_FALLBACK
  char *tmp_str2;
  char *tmp_str3;
#endif


  bra_set_free_bra_set_menu(ctk_set_menu); 
  ctk_set_menu = bra_set_alloc_bra_set_menu();

  if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  {
#if !defined(BRA_CONFIG_HTTP) && !defined(BRA_CONFIG_HTTP_EXT)
    shift += 2;
#elif defined(BRA_CONFIG_HTTP_EXT)
    shift += 4;
#endif
  }
    
  if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
  {
#ifdef BRA_CONFIG_HTTP_EXT
    shift += 4;
#elif !defined(BRA_CONFIG_SECURITY)
    shift += 2;    
#endif
  }

  // ctk layout
  layoutid = bra_cmn_ctk_init_layout(&layout_create,
                                     (MSF_UINT8)(PROF_CUSTOM_NUM - shift),
                                     widget_get_title_icon(0),
                                     BRA_STR_ID_EDIT,
                                     bra_ctk_delete_profile_custom_menu,
                                     KAL_FALSE);

  shift = 0;

  // rename caption
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_RENAME_CAP, BRA_STR_ID_RENAME, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));

  // rename editor
  tmp_str = bra_get_current_profile_name();
  bra_cmn_ctk_add_editor(layoutid, PROF_CUSTOM_RENAME, CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                         BRA_SET_MAX_NAME_SIZE, tmp_str, BRA_STR_ID_RENAME, widget_get_title_icon(0));
  BRA_FREE(tmp_str);

  // edit homeage caption
  if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  {
    bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_HOMEPAGE_CAP, BRA_STR_ID_HOMEPAGE, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));
  }
  else
  {
    bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_HOMEPAGE_CAP, BRA_STR_ID_HOMEPAGE, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));
  }
  
  // edit homepage editor
  tmp_str = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL);
  bra_cmn_ctk_add_editor(layoutid, PROF_CUSTOM_HOMEPAGE, CTK_INPUT_TYPE_ALPHA|CTK_INPUT_TYPE_OVERRIDE,
                         BRA_CFG_MAX_NBR_CHARS_URL, tmp_str, BRA_STR_ID_HOMEPAGE, widget_get_title_icon(0));

  // data account caption 
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_ACCOUNT_CAP, BRA_STR_ID_ACCOUNT, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));

  // data account selector
#ifdef BRA_CFG_PROF_FALLBACK
  ctk_set_menu->dual_net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL); 
  if (ctk_set_menu->dual_net_id)
  {
    ctk_set_menu->net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS);
    ctk_set_menu->net_id_sec = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM);
  }
  else
    ctk_set_menu->net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);

  tmp_str = bra_get_account_name(ctk_set_menu->net_id);  
  if (ctk_set_menu->dual_net_id)
  {
    tmp_str2 = bra_get_account_name(ctk_set_menu->net_id_sec);
    tmp_str3 = msf_cmmn_strcat (MSF_MODID_BRA, tmp_str, "/");
    BRA_FREE(tmp_str);
    tmp_str = msf_cmmn_strcat (MSF_MODID_BRA, tmp_str3, tmp_str2);
    BRA_FREE(tmp_str2);
    BRA_FREE(tmp_str3);
  }
#else
  ctk_set_menu->net_id = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID);
  tmp_str = bra_get_account_name(ctk_set_menu->net_id);  
#endif

#ifdef BRA_CFG_CONN_ALWAYS_ASK
  ctk_set_menu->is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_IS_ASK); //BRA type is ok, just not CMN 
  if (ctk_set_menu->is_ask)
  {
    BRA_FREE(tmp_str);
    tmp_str = bra_cmn_strdup_widget_string_data(BRA_STR_ALWAYS_ASK);       
  }
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
  bra_cmn_ctk_add_display(layoutid, PROF_CUSTOM_ACCOUNT, tmp_str, 0, MEA_STR_ID_SELECT, bra_create_net_bearer_menu);
  BRA_FREE(tmp_str);
  
  // connection type caption
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_CONN_TYPE_CAP - shift, BRA_STR_ID_CONN_TYPE, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));

  // connection type selector
  ctk_set_menu->conn_type = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, "con_type");
#if defined(BRA_CONFIG_HTTP)
  bra_cmn_ctk_add_select(layoutid, PROF_CUSTOM_CONN_TYPE - shift , 3, conn_type_strid, 
                         ctk_set_menu->conn_type - 1) ;

#elif defined(BRA_CONFIG_HTTP_EXT)
  {    
    MsfStringHandle ms;
    MSF_UINT8 l;    
    ms = MSF_WIDGET_STRING_GET_PREDEFINED(conn_type_strid[ctk_set_menu->conn_type-1]);
    l = MSF_WIDGET_STRING_GET_LENGTH(ms, 1, MsfUtf8);
    tmp_str = BRA_ALLOC (l + 1);
    MSF_WIDGET_STRING_GET_DATA (ms, tmp_str, MsfUtf8);
    tmp_str[l-1] = '\0';
    bra_cmn_ctk_add_display(layoutid, PROF_CUSTOM_CONN_TYPE - shift, tmp_str, 0, MEA_STR_ID_SELECT, bra_create_conn_type_menu);
    BRA_FREE(tmp_str);
  }
#else
  bra_cmn_ctk_add_select(layoutid, PROF_CUSTOM_CONN_TYPE - shift , 2, conn_type_strid, 
                         ctk_set_menu->conn_type - 2) ;
#endif

  // gateway caption
#if defined(BRA_CONFIG_HTTP)
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_GATEWAY_CAP - shift, BRA_STR_ID_PRX_ADDR, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));
#elif defined(BRA_CONFIG_HTTP_EXT)
  shift += 1;
#else
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_GATEWAY_CAP - shift, BRA_STR_ID_GATEWAY, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));
#endif

  // gateway editor  
  tmp_str = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_ADDR);
  if(strlen(tmp_str) == 0)
  {
    ctk_set_menu->ip = BRA_ALLOC(strlen("0.0.0.0")+1);
    sprintf(ctk_set_menu->ip, "0.0.0.0");
  }
  else
  {
    ctk_set_menu->ip = BRA_ALLOC(strlen(tmp_str)+1);
    strcpy(ctk_set_menu->ip, tmp_str);
  }
#if defined(BRA_CONFIG_HTTP)
  {
    unsigned char ip[4];
    memset(ip, 0, 4);
    bra_cmn_get_address(ctk_set_menu->ip, ip);
    bra_cmn_ctk_add_ip_editor(layoutid, PROF_CUSTOM_GATEWAY - shift, ip);    
  }
#elif defined(BRA_CONFIG_HTTP_EXT)
  shift += 1;
#else
  {
    unsigned char ip[4];
    memset(ip, 0, 4);
    bra_cmn_get_address(ctk_set_menu->ip, ip);
    bra_cmn_ctk_add_ip_editor(layoutid, PROF_CUSTOM_GATEWAY - shift, ip);    
  }
#endif

  ctk_set_menu->port = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, "prx_port"); 
  ctk_set_menu->select = ((ctk_set_menu->port == 9202 || ctk_set_menu->port == 9203)?1:0);
#if defined(BRA_CONFIG_HTTP)
  // port caption
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_SECURITY_CAP - shift, BRA_STR_ID_PRX_PORT, bra_cmn_get_list_num_image_enum(i++));
  tmp_str = bra_cmn_int_to_str (ctk_set_menu->port);  
  bra_cmn_ctk_add_single_line_editor(layoutid, PROF_CUSTOM_SECURITY - shift, BRA_SET_MAX_PORT_SIZE, tmp_str);
  BRA_FREE(tmp_str);
#elif defined(BRA_CONFIG_HTTP_EXT)
  if(ctk_set_menu->conn_type != BRA_SET_CONNECTION_TYPE_HTTP)
     ctk_set_menu->port = BRA_CFG_PROF_DEFAULT_PRX_PORT;
  shift += 2;
#else
  if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
  {
    shift += 2;
  }
  else
  {
#ifdef BRA_CONFIG_SECURITY  
    MSF_UINT16    on_off_strid[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};  

    // security caption
    bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_SECURITY_CAP - shift, BRA_STR_ID_SECURITY, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));
    
    // security selector
    bra_cmn_ctk_add_select(layoutid, PROF_CUSTOM_SECURITY - shift, 2, on_off_strid, 
                          ctk_set_menu->port) ;
#else
    shift += 2;
#endif
  }
#endif

  // username caption
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_UID_CAP - shift, BRA_STR_ID_PRX_UID, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));

  // username editor
  tmp_str = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_UID);
  bra_cmn_ctk_add_editor(layoutid, PROF_CUSTOM_UID - shift, CTK_INPUT_TYPE_ALPHA,
                         BRA_SET_MAX_UID_SIZE, tmp_str, BRA_STR_ID_PRX_UID, widget_get_title_icon(0));

  // password caption
  bra_cmn_ctk_add_caption(layoutid, PROF_CUSTOM_PWD_CAP - shift, BRA_STR_ID_PRX_PWD, (MSF_UINT16)bra_cmn_get_list_num_image_enum(i++));

  // password editor
  tmp_str = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PWD);
  bra_cmn_ctk_add_editor(layoutid, PROF_CUSTOM_PWD - shift, CTK_INPUT_TYPE_PASSWORD_ALPHA,
                         BRA_SET_MAX_PWD_SIZE, tmp_str, BRA_STR_ID_PRX_PWD, widget_get_title_icon(0));

  scrid = bra_cmn_ctk_screen_create(layoutid, bra_ctk_action_profile_custom_menu);

  // create form
  ctk_set_menu->window = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);  

	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_PROFILE_CUSTOM_MENU, 
                       (bra_win_t*)ctk_set_menu, 
                       &win_pos, 
                       bra_delete_profile_custom_menu_ctk, 
                       NULL,
                       NULL);				
}
#endif

static void
bra_delete_profile_edit_menu (bra_win_t *win)
{
  bra_set_menu_t *p;
  p = (bra_set_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

static void
bra_action_profile_edit_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_set_menu_t *p;
  int i = 0;
#ifndef BRA_USE_CTK_INLINE
  int conn_type;

  conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
#endif

  p = (bra_set_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
#ifdef BRA_USE_CTK_INLINE
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Active Profile*/
      bra_set_active_selected_profile();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Customize Profile*/
      bra_ctk_create_profile_custom_menu();
    }
#else
    MsfStringHandle ms;
    char            *s;


    if ((!BRAa_bearerInConn()) && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED))
    {
      /*Active Profile*/
      bra_set_active_selected_profile();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Rename Profile*/
      if (bra_prof_is_profile_loaded (1) == 0)
      {
        bra_dlg_create_dlg (MsfWarning,
          BRA_STR_ERR_SELECT_PROFILE, 
          BRA_STR_OK, 
          0,
          0, 
          NULL);
        return;
      }
      s = bra_get_current_profile_name();
      ms = BRA_STRCONV(s);
      BRA_FREE(s);
      
      bra_dlg_create_input_form(BRA_STR_RENAME, 
                                MsfText, 
                                ms, 
                                255, 
                                bra_set_rename_profile_response);
      MSF_WIDGET_RELEASE (ms);
    }
	 else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Edit Homepage*/
      MsfStringHandle ms;
      char *title = bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE);
      if(title && strlen(title) > 0)
        ms = BRA_STRCONV(title);        
      else
        ms = BRA_STR_HOMEPAGE;

#ifdef BRA_CONFIG_MMS
      if(bra_prof_get_profile_id() == BRA_PROF_ID_MMS)
      bra_dlg_create_title_url_form (BRA_STR_EDIT_HOMEPAGE, 
                                     ms,						                   
						                   bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL),
                                     bra_title_mmsc_response,
                                     BRA_WIN_ID_PROFILE_EDIT_MENU);
      else
#endif        
      bra_dlg_create_title_url_form (BRA_STR_EDIT_HOMEPAGE, 
                                     ms,						                   
						                   bra_prof_get_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL),
                                     bra_title_url_response,
                                     BRA_WIN_ID_PROFILE_EDIT_MENU);
      MSF_WIDGET_RELEASE (ms);
    }
    else if ((!BRAa_bearerInConn()) && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++)& MSF_CHOICE_ELEMENT_SELECTED))
    {
      /*Data Account*/
      bra_create_net_bearer_menu ();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Connectin Type*/
      bra_create_conn_type_menu ();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*WAP Gateway or Proxy Address*/
      s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_addr");
      ms = BRA_STRCONV(BRA_CMN_HNV(s));/*OK*/
		if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
      bra_dlg_create_input_form(BRA_STR_GATEWAY, 
                                MsfIpAddress, 
                                ms, 
                                BRA_SET_MAX_IP_SIZE, 
                                bra_set_prx_addr_response);
      else
      bra_dlg_create_input_form(BRA_STR_PRX_ADDR, 
                                MsfIpAddress, 
                                ms, 
                                BRA_SET_MAX_IP_SIZE, 
                                bra_set_prx_addr_response);

      MSF_WIDGET_RELEASE (ms);
    }

    if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
    {
#ifdef BRA_CONFIG_SECURITY
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {		
        int on_off_list[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};
		  int sec_on_off, port;
      
		  port = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT);
		  sec_on_off = (port==9202||port==9203)?1:0;

		  /* Security Mode*/
        bra_dlg_create_opt_menu (BRA_STR_SECURITY, 
                                 2, 
                                 on_off_list,
                                 sec_on_off,
                                 bra_conn_enable_sec_response);
      }
#endif
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Proxy Port*/
      s = bra_cmn_int_to_str (bra_prof_get_key_int_value (BRA_PROF_ID_BRA, "prx_port"));
      ms = BRA_STRCONV(s);/*OK*/
      bra_dlg_create_input_form(BRA_STR_PRX_PORT, 
                                MsfInteger, 
                                ms, 
                                BRA_SET_MAX_PORT_SIZE, 
                                bra_set_prx_port_response);
      MSF_WIDGET_RELEASE (ms);
      BRA_FREE (s);
    }

    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Proxy Username*/
      s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_uid");
      ms = BRA_STRCONV(BRA_CMN_HNV(s));/*OK*/
      bra_dlg_create_input_form(BRA_STR_PRX_UID, 
                                MsfText, 
                                ms, 
                                BRA_SET_MAX_UID_SIZE, 
                                bra_set_prx_uid_response);
      MSF_WIDGET_RELEASE (ms);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Proxy Password*/
      s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_pwd");
      ms = BRA_STRCONV(BRA_CMN_HNV(s));/*OK*/
      bra_dlg_create_input_form(BRA_STR_PRX_PWD, 
                                MsfPasswordText, 
                                ms, 
                                BRA_SET_MAX_PWD_SIZE, 
                                bra_set_prx_pwd_response);
      MSF_WIDGET_RELEASE (ms);
    }
#endif
  }
}

static void
bra_profile_edit_menu_in_focus(bra_win_t *win)
{
  char *s;
#ifdef BRA_USE_CTK_INLINE
  s = bra_get_current_profile_name();
  MSF_WIDGET_SET_TITLE (win->win_hdl, BRA_STRCONV(s));
  BRA_FREE(s);
#else
  MsfStringHandle ms;
  int conn_type, i = 5;

  if(BRAa_bearerInConn())
    i -= 2;

  conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
  if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)	
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->win_hdl, i++, BRA_STR_GATEWAY,  0, bra_cmn_get_list_num_image(i), 0, FALSE);
    /* if WSP_CL or WSP_CO, ask if use security */
#ifdef BRA_CONFIG_SECURITY
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->win_hdl, i++, BRA_STR_SECURITY,  0, bra_cmn_get_list_num_image(i), 0, FALSE);
#endif
  }
  else
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->win_hdl, i++, BRA_STR_PRX_ADDR,  0, bra_cmn_get_list_num_image(i), 0, FALSE);
    /* if HTTP, ask if proxy port*/
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->win_hdl, i++, BRA_STR_PRX_PORT,  0, bra_cmn_get_list_num_image(i), 0, FALSE);	
  }

  s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prof_str");
   if(!s || *s == 0)
     ms = BRA_STR_EDIT_PROFILE;
   else
     ms = BRA_STRCONV(s);
	MSF_WIDGET_SET_TITLE (win->win_hdl, ms);
   MSF_WIDGET_RELEASE(ms);
#endif
}

/*
 * This function creates the main profile edit menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_profile_edit_menu (void)
{
  bra_set_menu_t      *win;
  MsfPosition          pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties  prop;
  MSF_UINT8            i = 0;
#ifdef BRA_USE_CTK_INLINE
  char *prof_str;
#else
  int conn_type;
#endif

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_set_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                        MsfImplicitChoice,
                                        &prop.displaySize,
                                        win->accept,
                                        0, /*Element Position*/
                                        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                        0x8000, /*Property Mask*/
                                        0 /*Default Style*/);
#ifdef BRA_USE_CTK_INLINE
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, /*BRA_STR_SELECT_PROFILE*/BRA_STR_ACTIVATE_PROFILE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   i++;
   HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_EDIT_PROFILE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
  /* set title with profile name */
  prof_str = bra_get_current_profile_name();
  MSF_WIDGET_SET_TITLE (win->window, BRA_STRCONV(prof_str));
  BRA_FREE(prof_str);
#else
  if(!BRAa_bearerInConn())
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, /*BRA_STR_SELECT_PROFILE*/BRA_STR_ACTIVATE_PROFILE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_RENAME,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_EDIT_HOMEPAGE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   if(!BRAa_bearerInConn())
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_ACCOUNT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_CONN_TYPE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
   if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)	
	{
	   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_GATEWAY,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
	   /* if WSP_CL or WSP_CO, ask if use security */
#ifdef BRA_CONFIG_SECURITY
      MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_SECURITY,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
#endif
   }
	else
	{
	   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_PRX_ADDR,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
	   /* if HTTP, ask if proxy port*/
	   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_PRX_PORT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);	
	}
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_PRX_UID,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_PRX_PWD,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
#endif

	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_PROFILE_EDIT_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_profile_edit_menu, 
                    bra_profile_edit_menu_in_focus,
                    bra_action_profile_edit_menu);

}

/*****************************************************************/
/*                                                               */
/*    CONNECTION TYPE FORM                                       */
/*                                                               */
/*****************************************************************/
#if defined(BRA_CONFIG_HTTP_EXT) || !defined(BRA_USE_CTK_INLINE) 

static void
bra_delete_conn_type_menu (bra_win_t *win)
{
  bra_set_menu_t *p;
  p = (bra_set_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}


static void 
bra_action_conn_type_menu (bra_win_t *win, MsfActionHandle bra_action)
{
  bra_set_menu_t *p;
#ifdef BRA_CONFIG_HTTP_EXT
  int ok = 0;
#endif
  p = (bra_set_menu_t *)(win);

	if (bra_action == p->accept){
#ifdef BRA_CONFIG_HTTP_EXT
        ok = 1;
#endif
		if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 0)& MSF_CHOICE_ELEMENT_SELECTED)
		{
#ifdef BRA_CONFIG_HTTP_EXT
            ok += bra_ctk_update_conn_type_display(BRA_SET_CONNECTION_TYPE_WSP_CO, 0);
#else
            int port = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT);		  
            bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", BRA_SET_CONNECTION_TYPE_WSP_CO, NULL);
            if(port==9202 || port==9203)
                bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 9203, NULL);
            else
                bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 0, NULL);        
#endif
		}
/*		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 1)& MSF_CHOICE_ELEMENT_SELECTED)
		{
#ifdef BRA_CONFIG_HTTP_EXT
        ok+=bra_ctk_update_conn_type_display(BRA_SET_CONNECTION_TYPE_WSP_CL, 0);
#else
        int port = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT);		  
        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", BRA_SET_CONNECTION_TYPE_WSP_CL, NULL);
        if(port==9202 || port==9203)
           bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 9202, NULL);
        else
        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 0, NULL);
#endif
		}
*/
#ifdef WAP2
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 1) & MSF_CHOICE_ELEMENT_SELECTED)
		{
#ifdef BRA_CONFIG_HTTP_EXT
            ok += bra_ctk_update_conn_type_display(BRA_SET_CONNECTION_TYPE_HTTP, 0);
#else
            char *s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_addr");
            bra_prof_change_key_int_value (BRA_PROF_ID_BRA, "con_type", BRA_SET_CONNECTION_TYPE_HTTP, NULL);
		    if(s != NULL && strlen((const char*)s) > 0)
                bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 8080, NULL);
            else
		        bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_PORT, 0, NULL);  
#endif
		}
#endif
  }

  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
#ifdef BRA_CONFIG_HTTP_EXT
  if(ok > 0)
    bra_ctk_create_conn_type_menu(ok-1);
#endif
}


static void 
bra_create_conn_type_menu (void)
{
  bra_set_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_set_menu_t);

  win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
  win->back = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 3, 0x8000);
  win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfExclusiveChoice,
												                     &prop.displaySize,
												                     win->accept,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

  MSF_WIDGET_SET_TITLE (win->window,BRA_STR_CONN_TYPE);
  MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);

  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 0, BRA_STR_CONN_ORIENT, 0, 0, 0, TRUE);
  //MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_CONN_LESS, 0, 0, 0,TRUE);
#if defined(BRA_CONFIG_HTTP) || defined(BRA_CONFIG_HTTP_EXT)
  //if(bra_prof_get_profile_id() == BRA_PROF_ID_BRA)
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 1, BRA_STR_HTTP, 0, 0, 0, TRUE); 

  switch (ctk_set_menu->conn_type)
#else
  switch (bra_prof_get_key_int_value (BRA_PROF_ID_BRA, "con_type"))
#endif  
  {
    case BRA_SET_CONNECTION_TYPE_WSP_CO:
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 0, MSF_CHOICE_ELEMENT_SELECTED);
      break;
/*    case BRA_SET_CONNECTION_TYPE_WSP_CL:
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 1, MSF_CHOICE_ELEMENT_SELECTED);
      break;*/
#ifdef WAP2
    case BRA_SET_CONNECTION_TYPE_HTTP:
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, 1, MSF_CHOICE_ELEMENT_SELECTED);
      break;
#endif
    default:
      /*Error*/
      break;
  }
  
	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->accept);
	MSF_WIDGET_ADD_ACTION (win->window, 
								 win->back);

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SET_CONN_TYPE_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_delete_conn_type_menu, 
                    NULL,
                    bra_action_conn_type_menu);

}
#endif /*defined(BRA_CONFIG_HTTP_EXT) || !defined(BRA_USE_CTK_INLINE)*/ 





#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN


static void
bra_create_net_bearer_menu(void)
{
  MSF_UINT16      app_id;
  MSF_UINT32      id_num;
  MSF_UINT32      bearer_scope;
  MSF_UINT32      net_id[BRA_MULITI_NET_ID_MAX_NUM];
  MSF_UINT32      bearer_type[BRA_MULITI_NET_ID_MAX_NUM];


  app_id = bra_set_get_net_id_select_app_id();
  bearer_scope = bra_set_get_net_id_select_bearer_scope();
  bra_set_get_net_id_select_bearer_info(&id_num, (MSF_UINT32*)bearer_type, (MSF_UINT32*)net_id);

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_SET_18FFDDF968B941CFAA88FB28804750D5, "BRA: net id select ind: app_id=%d, id_num=%d, bearer_scope=%d\n", 
                app_id, id_num, bearer_scope));
    
  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_SET_2E050D90104D25EAE4AAABDC6B9A5FEE, "BRA: net id select ind: beare_type=%d-%d, net_id=%d-%d\n", 
                bearer_type[0], bearer_type[1], net_id[0], net_id[1]));

  bra_set_send_net_id_select_request(app_id, 0, id_num, bearer_scope, bearer_type, net_id);
}


static MSF_UINT16
bra_set_get_net_id_select_app_id(void)
{
  MSF_UINT16      app_id;
  int             prof_type; 


  prof_type = bra_prof_get_profile_id();
  if (prof_type == BRA_PROF_ID_BRA)
    app_id = DTCNT_LIST_BY_WAP;
  else if (prof_type == BRA_PROF_ID_MMS)
    app_id = DTCNT_LIST_BY_MMS;
  else
    app_id = DTCNT_LIST_BY_NULL;
  return app_id;
}


static MSF_UINT32
bra_set_get_net_id_select_bearer_scope(void)
{
  MSF_UINT32  bearer_scope = 0;


#if 0
/* under construction !*/
#ifdef BRA_CFG_CONN_ALWAYS_ASK
/* under construction !*/
/* under construction !*/
#endif /* BRA_CFG_CONN_ALWAYS_ASK */
#endif  

#ifdef __CS_SERVICE__
  bearer_scope |= DATA_ACCOUNT_BEARER_CSD;
#endif

#ifdef __PS_SERVICE__         
  bearer_scope |= DATA_ACCOUNT_BEARER_GPRS;

#ifdef BRA_CFG_PROF_FALLBACK
  if (BRA_PROF_ID_BRA == bra_prof_get_profile_id())
  {
    bearer_scope |= DATA_ACCOUNT_BEARER_GPRS_CSD;
  }
#endif /*BRA_CFG_PROF_FALLBACK*/

#ifdef MMS_CFG_FALLBACK_SUPPORT
  if (BRA_PROF_ID_MMS == bra_prof_get_profile_id())
  {
    bearer_scope |= DATA_ACCOUNT_BEARER_GPRS_CSD;
  }
#endif /*MMS_CFG_FALLBACK_SUPPORT*/

#endif /*__PS_SERVICE__*/         

#ifdef __WIFI_SUPPORT__         
  if (BRA_PROF_ID_BRA == bra_prof_get_profile_id())
  {
      bearer_scope |= DATA_ACCOUNT_BEARER_WIFI;
  }
#endif /*__WIFI_SUPPORT__*/

  return bearer_scope;
}


static void
bra_set_get_net_id_select_bearer_info(MSF_UINT32 *id_num, MSF_UINT32 *bearer_type, MSF_UINT32 *net_id)
{
#if defined(BRA_CFG_PROF_FALLBACK) || defined(MMS_CFG_FALLBACK_SUPPORT)
  int         is_dual_id = FALSE;
#endif

  
#ifdef BRA_CFG_PROF_FALLBACK
  if (BRA_PROF_ID_BRA == bra_prof_get_profile_id() && ctk_set_menu->dual_net_id != FALSE)
  {
    is_dual_id = TRUE;
  }    
#endif /*BRA_CFG_PROF_FALLBACK*/

#ifdef MMS_CFG_FALLBACK_SUPPORT
  if (BRA_PROF_ID_BRA == bra_prof_get_profile_id() && ctk_set_menu->dual_net_id != FALSE)
  {
    is_dual_id = TRUE;
  }    
#endif /*MMS_CFG_FALLBACK_SUPPORT*/

#if defined(BRA_CFG_PROF_FALLBACK) || defined(MMS_CFG_FALLBACK_SUPPORT)

  if (is_dual_id == TRUE)
  {
    *id_num = 2;
    net_id[0] = ctk_set_menu->net_id;
    bearer_type[0] = bra_set_get_dtcnt_bearer_type_by_net_id(net_id[0]);

    net_id[1] = ctk_set_menu->net_id_sec;
    bearer_type[1] = bra_set_get_dtcnt_bearer_type_by_net_id(net_id[1]);
  }
  else
  {
    *id_num = 1;
    net_id[0] = ctk_set_menu->net_id;
    bearer_type[0] = bra_set_get_dtcnt_bearer_type_by_net_id(net_id[0]);
    net_id[1] = 0;
    bearer_type[1] = 0;
  }

#else /*BRA_CFG_PROF_FALLBACK*/

  {
    *id_num = 1;
    net_id[0] = ctk_set_menu->net_id;
    bearer_type[0] = bra_set_get_dtcnt_bearer_type_by_net_id(net_id[0]);
    net_id[1] = 0;
    bearer_type[1] = 0;
  }    

#endif /*BRA_CFG_PROF_FALLBACK*/
}


static MSF_UINT32
bra_set_get_dtcnt_bearer_type_by_net_id(int net_id)
{
  int         hdi_bearer;
  MSF_UINT32  dtcnt_bearer = HDI_SOCKET_BEARER_GSM_GPRS;


#ifdef BRA_CFG_CONN_ALWAYS_ASK
  if (TRUE == always_ask_is_always_ask_data_account((kal_uint32)net_id))
  {      
      return DATA_ACCOUNT_BEARER_ALWAYS_ASK;
  }
#endif /* BRA_CFG_CONN_ALWAYS_ASK */

  hdi_bearer = HDIa_networkAccountGetBearer(net_id);
  switch (hdi_bearer)
  {
#ifdef __CS_SERVICE__
  case HDI_SOCKET_BEARER_GSM_CSD:
    dtcnt_bearer = DATA_ACCOUNT_BEARER_CSD;
    break;
#endif /*__CS_SERVICE__*/
        
#ifdef __PS_SERVICE__         
  case HDI_SOCKET_BEARER_GSM_GPRS:
    dtcnt_bearer = DATA_ACCOUNT_BEARER_GPRS;
    break;
#endif /*__PS_SERVICE__*/
        
#ifdef __WIFI_SUPPORT__         
  case HDI_SOCKET_BEARER_WIFI:
    dtcnt_bearer = DATA_ACCOUNT_BEARER_WIFI;
    break;
#endif /*__WIFI_SUPPORT__*/
        
  default:
    ASSERT(0);
  }
  return (MSF_UINT32)dtcnt_bearer; 
}


static void
bra_set_send_net_id_select_request(MSF_UINT16 app_id, MSF_UINT16 menu_id, 
                                   MSF_UINT32 id_num, MSF_UINT32 bearer_scope,
                                   MSF_UINT32 *bearer_type, MSF_UINT32* net_id)
{
  int                                 i;
  MYQUEUE                             message;
  mmi_ps_dtcnt_list_ind_struct        *data;
   
    
  data = (mmi_ps_dtcnt_list_ind_struct *)OslConstructDataPtr(sizeof(mmi_ps_dtcnt_list_ind_struct));
  data->app_id = (kal_uint16)app_id;
  data->menu_id = (kal_uint16)menu_id;
  data->bearer_scope = (kal_uint32)bearer_scope;
  data->num_id = id_num;

  for(i = 0; i < BRA_MULITI_NET_ID_MAX_NUM; i++)
  {
    if (net_id)
      data->net_id[i] = (kal_uint32)net_id[i];
    if (bearer_type)
      data->bearer_type[i] = (kal_uint32)bearer_type[i];
  }

  message.oslSrcId       = MOD_WAP;
  message.oslDestId      = MOD_MMI;
  message.oslMsgId       = MSG_ID_MMI_PS_DTCNT_LIST_IND;
  message.oslDataPtr     = (oslParaType *)data;
  message.oslPeerBuffPtr = NULL;
    
  OslMsgSendExtQueue(&message);
}


void
bra_set_handle_net_id_select_response(void *p)
{
  bra_net_id_select_rsp_t   *rsp;
   

  rsp = (bra_net_id_select_rsp_t*)p;
  
  if (rsp == NULL || ctk_set_menu == NULL)
    return;
  if (!bra_win_get_window(BRA_WIN_ID_PROFILE_CUSTOM_MENU))
    return;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_SET_9F3B2B866C7455B4E2EA22882586EA1A, "BRA: net id select rsp: app_id=%d, result=%d bearer_scope=%d\n", 
                rsp->app_id, rsp->result, rsp->bearer_scope));

  if (rsp->app_id != DTCNT_LIST_BY_MMS && rsp->app_id != DTCNT_LIST_BY_WAP)
    return;

  if (rsp->result == FALSE) /*user cancel the selection of net id, do not send ind again*/
    return;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
                BRA_SET_E1C36A99971D7A607714ABB6102BA1B6, "BRA: net id select rsp: id_num=%d, bearer type=%d-%d, net id=%d-%d\n", 
                rsp->id_num, rsp->bearer_type[0], rsp->bearer_type[1], 
                rsp->net_id[0], rsp->net_id[1]));

#ifndef BRA_CFG_PROF_FALLBACK
  if (BRA_PROF_ID_BRA == bra_prof_get_profile_id() &&
      (rsp->bearer_scope == DATA_ACCOUNT_BEARER_GPRS_CSD || rsp->id_num == 2))
  {
    return;
  }
#endif

#ifndef MMS_CFG_FALLBACK_SUPPORT
  if (BRA_PROF_ID_MMS == bra_prof_get_profile_id() && 
      (rsp->bearer_scope == DATA_ACCOUNT_BEARER_GPRS_CSD || rsp->id_num == 2))
  {
    return;
  }
#endif

  if (rsp->bearer_scope == DATA_ACCOUNT_BEARER_GPRS_CSD && rsp->id_num != 2 ||
      rsp->bearer_scope != DATA_ACCOUNT_BEARER_GPRS_CSD && rsp->id_num == 2)
  {
    return;
  }

#ifdef BRA_CFG_PROF_FALLBACK
  if (rsp->bearer_scope == DATA_ACCOUNT_BEARER_GPRS_CSD)
  {
    ctk_set_menu->dual_net_id = TRUE;
    if (rsp->bearer_type[0] == DATA_ACCOUNT_BEARER_GPRS)
    {
      ctk_set_menu->net_id = rsp->net_id[0];
      ctk_set_menu->net_id_sec = rsp->net_id[1];
    }
    else
    {
      ctk_set_menu->net_id = rsp->net_id[1];
      ctk_set_menu->net_id_sec = rsp->net_id[0];
    }
    bra_set_fill_ctk_set_menu_always_ask(0);
  }
  else
  {
    ctk_set_menu->dual_net_id = FALSE;
    ctk_set_menu->net_id = rsp->net_id[0];
    bra_set_fill_ctk_set_menu_always_ask(rsp->net_id[0]);
  } 
  /*update*/
  bra_update_profile_custom_net_id_text();

#else /*BRA_CFG_PROF_FALLBACK*/

  ctk_set_menu->net_id = rsp->net_id[0];
  bra_set_fill_ctk_set_menu_always_ask(rsp->net_id[0]);
  bra_ctk_update_data_account_display(rsp->net_id[0]);

#endif /*BRA_CFG_PROF_FALLBACK*/

  /*tell Data account to close the last screen*/
  bra_set_send_net_id_select_request(DTCNT_LIST_BY_APP_OK, 0, 0, 0, NULL, NULL);
}


static void
bra_set_fill_ctk_set_menu_always_ask(MSF_UINT32 ext_net_id)
{
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  ctk_set_menu->is_ask = (int)always_ask_is_always_ask_data_account((kal_uint32)ext_net_id);
#endif
}
#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/



