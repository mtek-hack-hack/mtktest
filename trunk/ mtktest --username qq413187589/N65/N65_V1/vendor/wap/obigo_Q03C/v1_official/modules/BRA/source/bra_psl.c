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

#include "bra_sig.h"
#include "bra_main.h"
#include "bra_cmn.h"
#include "bra_prof.h"
#include "bra_req.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "bra_if.h"
#include "bra_view.h"
#include "bra_set.h"
#include "bra_int.h"
#include "bra_bkm.h"

#include "msf_int.h"
#include "msf_wid.h"
#include "msf_cmmn.h"
#include "msf_core.h"
#include "wap.h"
#include "kal_release.h"      	/* Basic data type */

#ifdef WAP_SUPPORT
#include "msf_log.h"
#include "widget_extension.h"
#include "widget.h"
#endif

#ifdef __UNIFIED_MSG_SUPPORT__
#include "wap_um.h"
#endif


#ifdef BRA_CONFIG_UIS_PUSH_SL
#include "uis_if.h"
#include "bra_psl.h" //Jo maximum size
#include "fat_fs.h"
#endif


#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif






#ifdef BRA_CONFIG_UIS_PUSH_SL
extern bra_psl_cancel_push_indicator(void); 
/************************************************************
 * Local Types 
 ************************************************************/
#ifdef WAP_SUPPORT

typedef struct {
  MSF_UINT8            uis_msg_type;
  uis_msg_handle_t     handle;
  uis_key_value_t      time;
  uis_key_value_t      text;
  uis_key_value_t      url;
  uis_key_value_t      address;
  void                *next;
  MSF_BOOL             read;
  MSF_BOOL             expired;
} bra_psl_list_item_t;

typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_psl_msg_list_menu_t;

typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_psl_msg_opt_menu_t;

typedef struct {
    MsfWindowHandle window;
    char            *url_str;
    MSF_UINT8       isExpired;
} bra_psl_x_t;

typedef struct bra_psl_deleted_notify_item_st {
    struct bra_psl_deleted_notify_item_st   *next;
    MSF_UINT16                      handleLen;
    unsigned char                   *handle;
} bra_psl_deleted_notify_item_t;

static bra_psl_x_t         *dlg;

static bra_psl_list_item_t *bra_msg_list        = NULL;
static bra_psl_list_item_t *bra_msg_new_hiSL_list   = NULL; /*newcomer is the last*/
static bra_psl_list_item_t *bra_msg_new_hiSI_list   = NULL; /*newcomer is the last*/
static bra_psl_list_item_t *selected_msg_item;
static bra_psl_list_item_t deleted_msg_item;
static uis_notify_new_msg_t new_msg_item;
static MSF_UINT32       new_msg_priority = -1;
static bra_psl_deleted_notify_item_t *bra_pending_deleted_notify_list;
static MSF_UINT8       selected_msg_idx = 0;
static MSF_BOOL  delete_all;      
static MSF_BOOL  read_from_idle;
static MSF_BOOL  show_accept;
//static MSF_UINT8 new_push_dlg = 0;

#endif

/************************************************************
 * Defines
 ************************************************************/

#define BRA_PUSH_METHOD_LOAD 0x01
#define BRA_PUSH_METHOD_SHOW 0x02

/************************************************************
 * Global variables
 ************************************************************/

static int                      bra_psl_uis_state = -1; /*-1 = power on initial state; 0 = not active; 1 = active*/
static int                      TotalNoOfPushMessages; //Jo maximum nbr of push =100
//static MSF_BOOL                 updateUI=FALSE;

#ifdef __UNIFIED_MSG_SUPPORT__
static int                      startFromMsg; // UM:start entry of unified message request
static int                      numberOfMsg;  // UM:message number of unified message get info request
static int                      msgIndex;     // UM:message index of unified message view message request
#endif

                                              
                                              

                                              
static void
bra_psl_goto_url(char *url);
                                              
/************************************************************
 * Function Prototypes
 ************************************************************/
extern MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time);
extern MSF_UINT32 HDIa_timeUTCToLocal(MSF_UINT32 utc_time);
extern pBOOL isInCall(void);
extern unsigned short GetWapCallPresent(void);
extern bra_psl_set_push_indicator(void);

/************************************************************
 * Internal Function
 ************************************************************/
static MSF_BOOL bra_psl_no_free_space(void)
{
#ifndef __MTK_TARGET__
	return 0;
#else
	WCHAR path[]={0x5a,0x3a,0x5c,0}; /* Z:\ */
	FS_DiskInfo diskinfo;
	U64 freebytes;
	
	FS_GetDiskInfo(path, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
	freebytes = (U64)diskinfo.FreeClusters * diskinfo.SectorsPerCluster *
		diskinfo.BytesPerSector;
	if (freebytes < 500)
		return 1;
	else
		return 0;
#endif
}

MSF_UINT32
bra_psl_str_2_uint32 (unsigned char *s){

  if (s == NULL)
    return 0;

  return (*(MSF_UINT32*)s);
}

char *
bra_psl_u_str_str (const unsigned char *s, MSF_UINT16 length){

  char *r;

  if (s == NULL)
    return NULL;

  r = BRA_ALLOC (length + 1);
  memcpy (r, s, length);
  r[length] = '\0';

  return r;
}

static int
msf_psl_extract_keys (uis_key_value_t *key_list, MSF_UINT16 n_keys, MSF_UINT32 *priority, char **url)
{
  int i;
  int priority_found = FALSE;
  int url_found      = FALSE;

  if (n_keys == 0)
    return FALSE;

  *url = NULL;

  for (i = 0; i < n_keys;i++)
  {
    if (key_list[i].key == UIS_MSG_KEY_PRIORITY){
      priority_found = TRUE;
      *priority = bra_psl_str_2_uint32 (key_list[i].value);
    }
    if (key_list[i].key == UIS_MSG_KEY_URL){
      url_found = TRUE;      
      *url = bra_psl_u_str_str(key_list[i].value, key_list[i].valueLen);
    }
    if (url_found && priority_found)
      return TRUE;
  }

  BRA_FREE (*url);
  *url = NULL;

  return FALSE;
}

static int
bra_psl_load (MSF_UINT32 priority, char *url)
{
  int              load_sl;
  bra_cmn_addr_t  *addr;

  
  if (priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH) {
    
    load_sl = bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_LOAD_SL);
    
    if (load_sl == 0)
      return FALSE;
    
    if (load_sl == 1)
    {
      addr = bra_cmn_get_current_page ( );
      
      if (addr == NULL)
        return FALSE;
      
      if ((addr->url == NULL) || (url == NULL))
        return FALSE;
      
      if(strcmp (addr->url, url) != 0)
        return FALSE;
    }    
    bra_psl_goto_url(url);
    return TRUE;
  }

  return FALSE;
}

static void bra_psl_pdn_push (const uis_msg_handle_t* hdl)
{
  bra_psl_deleted_notify_item_t *newItem;

  newItem = BRA_ALLOCTYPE(bra_psl_deleted_notify_item_t);

  newItem->handleLen = hdl->handleLen;
  newItem->handle = BRA_ALLOC(newItem->handleLen);
  memcpy(newItem->handle, hdl->handle, newItem->handleLen);

  newItem->next = bra_pending_deleted_notify_list;
  bra_pending_deleted_notify_list = newItem;
}

static void bra_psl_pdn_delete(const uis_msg_handle_t* hdl)
{
  bra_psl_deleted_notify_item_t *crtItem = bra_pending_deleted_notify_list;
  bra_psl_deleted_notify_item_t *prevItem = 0;
  bra_psl_deleted_notify_item_t *nextItem = 0;

  while (crtItem)
  {
    nextItem = crtItem->next;
    if (crtItem->handleLen == hdl->handleLen &&
        memcmp(crtItem->handle, hdl->handle, crtItem->handleLen) == 0)
    {
      if (prevItem)
      {
        prevItem->next = crtItem->next;
      }
      else
        bra_pending_deleted_notify_list = bra_pending_deleted_notify_list->next;

      if (crtItem->handle)
        BRA_FREE(crtItem->handle);
      BRA_FREE(crtItem);
      crtItem = nextItem;
    }
    if (crtItem != nextItem)
      prevItem = crtItem;
    crtItem = nextItem;
  }
}

static bra_psl_deleted_notify_item_t* bra_psl_pdn_pop(void)
{
  bra_psl_deleted_notify_item_t *popItem;
  popItem = bra_pending_deleted_notify_list;

  if (bra_pending_deleted_notify_list)
    bra_pending_deleted_notify_list = bra_pending_deleted_notify_list->next;

  return popItem;
}

static int
bra_psl_process_pdn_list(void)
{
  bra_psl_deleted_notify_item_t* pdn_item;
  bra_psl_list_item_t *msg_item;
  bra_psl_list_item_t *next_msg_item;
  bra_psl_msg_list_menu_t *win;
  int msgIndex;
  int hasDeleted = 0;
  extern MSF_BOOL bra_psl_list_delete_msg(MSF_UINT8 uisMsgType, uis_msg_handle_t *handle);

  win = (bra_psl_msg_list_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_MSG_LIST_DLG));
  msgIndex = 0;
  while ( 1 )
  {
    pdn_item=bra_psl_pdn_pop();
    if (!pdn_item)
      break;
    msg_item = bra_msg_list;
    while (msg_item)
    {
      next_msg_item = (bra_psl_list_item_t*)msg_item->next;
      if(msg_item->handle.handleLen == pdn_item->handleLen &&
         memcmp(msg_item->handle.handle, pdn_item->handle, pdn_item->handleLen) == 0)
      {
        bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, msgIndex);
        hasDeleted = 1;
      }
      msg_item = next_msg_item;
      msgIndex++;
    }
    if (pdn_item->handle)
      BRA_FREE(pdn_item->handle);
    BRA_FREE(pdn_item);
  }
  return hasDeleted;
}

static void
bra_psl_pdn_free(void)
{
  bra_psl_deleted_notify_item_t* pdn_item;
  while ( 1 )
  {
    pdn_item=bra_psl_pdn_pop();
    if (!pdn_item)
      break;
    if (pdn_item->handle)
      BRA_FREE(pdn_item->handle);
    BRA_FREE(pdn_item);
  }
}

/************************************************************
 * External Functions
 ************************************************************/

/*
 * Initializes the BRA Push SL functionality 
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_init (void)
{
  void* reg_handle;
  int selected;
  int   push_SL_setting;

  deleted_msg_item.handle.handle = NULL;
  new_msg_item.msg.handle.handle = NULL;
  new_msg_priority = -1;
  bra_pending_deleted_notify_list = 0;
  read_from_idle = 0;
  bra_msg_new_hiSL_list   = NULL;
  bra_msg_new_hiSI_list   = NULL;

  bra_main_set_module_state(BRA_STARTING_PSL);

  UISif_startInterface ();

  MSF_MODULE_START(MSF_MODID_BRA, MSF_MODID_UIS,"", NULL, NULL);

  /* inform PHS */
  selected = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON);
  reg_handle = MSF_REGISTRY_SET_INIT(MSF_MODID_BRA);
  
  MSF_REGISTRY_SET_PATH(reg_handle, (char*)"/PHS/");
  if (selected) /* on*/
  {
      MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "security", 0);
  }
  else /*off*/
  {
      MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "security", 2);
  }

  push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);
  if (push_SL_setting == 0)/* Never */
  {
      MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "supprtSL", 0);
  }
  else/* Confirm or Without Confirm*/
  {
      MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, "supprtSL", 1);
  }

  MSF_REGISTRY_SET_COMMIT (reg_handle);

#ifdef BRA_CONFIG_PUSH_TRUSTLIST
  bra_push_trustList_init(BRA_TRUSTLIST_STATE_SETTOPHS);
#endif
}

/*
 * This function is called when the UIS module is active
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_set_uis_state_active (void)
{
  UISif_register (MSF_MODID_BRA, UIS_MSG_TYPE_PUSH_SL);

  bra_main_remove_module_state (BRA_STARTING_PSL);

  bra_init_done ();

  if(bra_psl_uis_state == -1)
  {
    /* update push indication only when power on*/
    bra_psl_uis_state = 1;
  bra_psl_unread_check();
  }
  else
  {
  	 bra_psl_uis_state = 1;
  }  	       
}

/*
 * This function Must be called when the UIS module is terminated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_psl_uis_terminated (void)
{
  bra_psl_uis_state = 0;

#ifdef WAP_SUPPORT
  UISif_deregister(MSF_MODID_BRA, UIS_MSG_TYPE_PUSH_SI);  
  UISif_deregister(MSF_MODID_BRA, UIS_MSG_TYPE_PUSH_SL);
#endif

  bra_main_remove_module_state (BRA_TERMINATING_PSL);

  BRA_SIGNAL_SENDTO (W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_TERMINATE);
}


/*
 * This function releases all resources allocated for handling psl 
 * messages within the BRA.
 *
 * PARAMETERS
 *
 * RETURN    : 0 if the IBS is terminated; 1 if a request to terminate
 *             the IBS moudle is sent.
 */
int
bra_psl_uis_terminate (void)
{

  if (bra_psl_uis_state == 0 || bra_psl_uis_state == -1)
    return 0;

  UISif_deregister (MSF_MODID_BRA, UIS_MSG_TYPE_PUSH_SL);

  MSF_MODULE_TERMINATE(MSF_MODID_BRA, MSF_MODID_UIS);

  bra_main_set_module_state (BRA_TERMINATING_PSL);
  
  return 1;
}

void 
bra_psl_msg_reply (void *p)
{
  uis_reply_msg_t* msg;
  MSF_UINT32       priority;
  char            *url = NULL;


  if (p == NULL)
    return;

  msg = (uis_reply_msg_t*) p;

  if ((msg->result != UIS_RESULT_SUCCESS) || (msg->msgType != UIS_MSG_TYPE_PUSH_SL))
    goto done;
  
  if (msg->msg.propertyListSize > 0) {
    if (msf_psl_extract_keys (msg->msg.propertyList, 
                              msg->msg.propertyListSize, 
                              &priority, 
                              &url) == TRUE)
    {
      if (bra_psl_load (priority, url) == TRUE){
        UISif_deleteMsg (MSF_MODID_BRA,
                         0,
                         msg->msgType,
                         &msg->msg.handle);
      }
    }
  }

done:
  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, UIS_SIG_REPLY_MSG, p);
  BRA_FREE (url);
}

void 
bra_psl_new_sl_msg_notification (void *p)
{
  uis_notify_new_msg_t* msg;
  MSF_UINT32       priority;
  char            *url = NULL;


  if (p == NULL)
    return;

  msg = (uis_notify_new_msg_t*) p;

  if (msg->msgType != UIS_MSG_TYPE_PUSH_SL)
    goto done;
  
  if (msg->msg.titleListSize > 0) {
    if (msf_psl_extract_keys (msg->msg.titleList, 
                              msg->msg.titleListSize, 
                              &priority, 
                              &url) == TRUE)
    {
      if (bra_psl_load (priority, url) == TRUE){
        UISif_deleteMsg (MSF_MODID_BRA,
                         0,
                         msg->msgType,
                         &msg->msg.handle);
}
      goto done;
    }
  }
  
  /*All keys was not in the message. Request all keys.*/
  UISif_getMsg (MSF_MODID_BRA, 
                0,
                UIS_MSG_TYPE_PUSH_SL, 
                &msg->msg.handle);

done:
  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, UIS_SIG_NOTIFY_NEW_MSG, p);
  BRA_FREE (url);
}

#ifdef WAP_SUPPORT

void
bra_psl_list_delete_item(bra_psl_list_item_t *listItem)
{
  if (!listItem)
      return;

  if(listItem->text.value != NULL)
  {
    BRA_FREE(listItem->text.value);
    listItem->text.value = NULL;
  }
  if(listItem->time.value != NULL)
  {
    BRA_FREE(listItem->time.value);
    listItem->time.value = NULL;
  }
  if(listItem->url.value != NULL)
  {
    BRA_FREE(listItem->url.value);
    listItem->url.value = NULL;
  }
  if(listItem->address.value != NULL)
  {
    BRA_FREE(listItem->address.value);
    listItem->address.value = NULL;
  }
  if(listItem->handle.handle != NULL)
  {
    BRA_FREE(listItem->handle.handle);
    listItem->handle.handle = NULL;
  }
  
  BRA_FREE(listItem);
  listItem = NULL;
}

/* wrapped in compile option for purpose of removing compile warning */
#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
static MSF_BOOL bra_psl_is_new_msg(bra_psl_list_item_t *listItem)
{
 return (new_msg_item.msg.handle.handle && 0 == msf_cmmn_strncmp_nc(
		  	(const char*)listItem->handle.handle, 
		  	(const char*)new_msg_item.msg.handle.handle, 
			new_msg_item.msg.handle.handleLen));
}
#endif

static int
bra_psl_list_add_item(bra_psl_list_item_t *listItem)
{
 bra_psl_list_item_t *tmp_ptr, *prev_ptr;
 int i = 0;

  if (bra_msg_list == NULL) 
  {
    listItem->next = NULL;
    bra_msg_list = listItem;
  }
#ifdef __UNIFIED_MSG_SUPPORT__
  else 
  {
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
    if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) && bra_psl_is_new_msg(listItem))
    {
        listItem->next = bra_msg_list; //new msg is always the first
        bra_msg_list = listItem;
    }
    else
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
    {
      prev_ptr = NULL;
      tmp_ptr = bra_msg_list;
      while ((tmp_ptr != NULL) 
             && ((*((MSF_UINT32*)tmp_ptr->time.value) > *((MSF_UINT32*)listItem->time.value))))
      {
        prev_ptr = tmp_ptr;
        tmp_ptr = tmp_ptr->next;
        i++;
      }

      if (tmp_ptr == NULL) {
        prev_ptr->next = listItem;
        listItem->next = NULL;
      }
      else if (prev_ptr == NULL) {
        bra_msg_list   = listItem;
        listItem->next = tmp_ptr;
      }
      else {
        prev_ptr->next = listItem;
        listItem->next = tmp_ptr;
      }
    }
  }
#else  
  else if (bra_psl_is_new_msg(listItem))
  {
      listItem->next = bra_msg_list; //new msg is always the first
	  bra_msg_list = listItem;
  }
  else 
  {
    prev_ptr = NULL;
    tmp_ptr = bra_msg_list;
    while ((tmp_ptr != NULL) && 
		((*((MSF_UINT32*)tmp_ptr->time.value) > *((MSF_UINT32*)listItem->time.value)) ||
		bra_psl_is_new_msg(tmp_ptr) )) //new msg is always the first
	{
      prev_ptr = tmp_ptr;
      tmp_ptr = tmp_ptr->next;
      i++;
    }

    if (tmp_ptr == NULL) {
      prev_ptr->next = listItem;
      listItem->next = NULL;
    }
    else if (prev_ptr == NULL) {
      bra_msg_list   = listItem;
      listItem->next = tmp_ptr;
    }
    else {
      prev_ptr->next = listItem;
      listItem->next = tmp_ptr;
    }
  }
#endif  
  return i;
}

static int
bra_psl_list_add_new_item(bra_psl_list_item_t *listItem)
{
  if (bra_msg_list == NULL) {
    listItem->next = NULL;
    bra_msg_list = listItem;
  }
  else {
    listItem->next = bra_msg_list;
    bra_msg_list = listItem;
  }
  return 0;
}

static void
bra_psl_list_free(void)
{
  bra_psl_list_item_t *listItem;
    
  while(bra_msg_list != NULL) {
    listItem = bra_msg_list;
    bra_msg_list = bra_msg_list->next;
    
    if(listItem->text.value != NULL)
    {
      BRA_FREE(listItem->text.value);
      listItem->text.value = NULL;
    }
    if(listItem->time.value != NULL)
    {
      BRA_FREE(listItem->time.value);
      listItem->time.value = NULL;
    }
    if(listItem->url.value != NULL)
    {
      BRA_FREE(listItem->url.value);
      listItem->url.value = NULL;
    }
    if(listItem->address.value != NULL)
    {
      BRA_FREE(listItem->address.value);
      listItem->address.value = NULL;
    }
    if(listItem->handle.handle != NULL)
    {
      BRA_FREE(listItem->handle.handle);
      listItem->handle.handle = NULL;
    }
  
    BRA_FREE(listItem);
    listItem = NULL;
  }
}

//static bra_psl_list_item_t*
static int
bra_psl_list_add_msg(MSF_UINT8 uisMsgType, uis_msg_list_item_t *new_item)
{
  bra_psl_list_item_t *listItem;
  //int              i = 0;
  int              j = 0;
  //int              k = 0;

  /* create and initiate new item */
  listItem = BRA_ALLOCTYPE(bra_psl_list_item_t);
  listItem->text.value   = NULL;
  listItem->time.value   = NULL;
  listItem->url.value    = NULL;
  listItem->address.value   = NULL;
  listItem->uis_msg_type = uisMsgType;
  listItem->expired      = FALSE;

  /* copy handle struct and reuse handle value ptr */
  memcpy(&listItem->handle, &new_item->handle, sizeof(uis_msg_handle_t));
  new_item->handle.handle = NULL; /* avoid free of this ptr later */
     
  for (j=0; j < new_item->titleListSize; j++) {
    if(new_item->titleList[j].key == UIS_MSG_KEY_TIMESTAMP) {
      /* copy time struct and reuse time value ptr */
      memcpy(&listItem->time, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_URL) {
      /* copy url struct and reuse url value ptr */
      memcpy(&listItem->url, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_SUBJECT) {
      /* if value set free data en use SUBJECT instead */
      if (listItem->text.value != NULL)
        BRA_FREE(listItem->text.value);
      /* copy subject struct and reuse text value ptr */
      memcpy(&listItem->text, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_FROM) {
      /* if value set free data and use FROM instead */
      if (listItem->address.value != NULL)
      {
        BRA_FREE(listItem->address.value);
      }
        /* copy "from" struct and reuse text value ptr */
      memcpy(&listItem->address, &new_item->titleList[j], sizeof(uis_key_value_t));
        new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_READ) {
      if (new_item->titleList[j].value)
        listItem->read = *(new_item->titleList[j].value);
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_EXPIRES) {
      if (new_item->titleList[j].value && *(new_item->titleList[j].value) !=0)
      {
		  if (*((MSF_UINT32*)new_item->titleList[j].value)<=(MSF_UINT32)HDIa_timeLocalToUTC(MSF_TIME_GET_CURRENT()))
		      listItem->expired = TRUE;
	  }
    }
  }

  /* if time not set initiate a time key with 1970 as timestamp value */
  if(listItem->time.value == NULL) {
    listItem->time.value     = BRA_ALLOC(sizeof(MSF_UINT32));
    *((MSF_UINT32*)listItem->time.value)     = 0;
    listItem->time.key       = UIS_MSG_KEY_TIMESTAMP;
    listItem->time.valueLen  = sizeof(MSF_UINT32);
    listItem->time.valueType = UIS_VALUE_TYPE_UINT32;
  }

  /* add message to list*/
  //bra_psl_list_add_item(listItem);
  //return listItem;
  return bra_psl_list_add_item(listItem);
}

static int
bra_psl_list_add_new_msg(MSF_UINT8 uisMsgType, uis_msg_list_item_t *new_item)
{
  bra_psl_list_item_t *listItem;
  int                j = 0;

  listItem = BRA_ALLOCTYPE(bra_psl_list_item_t);
  listItem->text.value   = NULL;
  listItem->time.value   = NULL;
  listItem->url.value    = NULL;
  listItem->address.value   = NULL;
  listItem->uis_msg_type = uisMsgType;
  listItem->expired      = FALSE;

  memcpy(&listItem->handle, &new_item->handle, sizeof(uis_msg_handle_t));
  new_item->handle.handle = NULL; /* avoid free of this ptr later */
     
  for (j=0; j < new_item->titleListSize; j++) {
    if(new_item->titleList[j].key == UIS_MSG_KEY_TIMESTAMP) {
      memcpy(&listItem->time, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_URL) {
      memcpy(&listItem->url, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_SUBJECT) {
      if (listItem->text.value != NULL)
        BRA_FREE(listItem->text.value);
      memcpy(&listItem->text, &new_item->titleList[j], sizeof(uis_key_value_t));
      new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_FROM) {
      if (listItem->address.value != NULL)
      {
        BRA_FREE(listItem->address.value);
      }
        memcpy(&listItem->address, &new_item->titleList[j], sizeof(uis_key_value_t));
        new_item->titleList[j].value = NULL; /* avoid free of this ptr later */
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_READ) {
      if (new_item->titleList[j].value)
        listItem->read = *(new_item->titleList[j].value);
    }
    else if (new_item->titleList[j].key == UIS_MSG_KEY_EXPIRES) {
      if (new_item->titleList[j].value && *(new_item->titleList[j].value) !=0)
      {
		  if (*((MSF_UINT32*)new_item->titleList[j].value)<=(MSF_UINT32)HDIa_timeLocalToUTC(MSF_TIME_GET_CURRENT()))
		      listItem->expired = TRUE;
	  }
    }
  }
  if(listItem->time.value == NULL) {
    listItem->time.value     = BRA_ALLOC(sizeof(MSF_UINT32));
    *((MSF_UINT32*)listItem->time.value)     = 0;
    listItem->time.key       = UIS_MSG_KEY_TIMESTAMP;
    listItem->time.valueLen  = sizeof(MSF_UINT32);
    listItem->time.valueType = UIS_VALUE_TYPE_UINT32;
  }
  return bra_psl_list_add_new_item(listItem);
}

MSF_BOOL
bra_psl_list_delete_msg(MSF_UINT8 uisMsgType, uis_msg_handle_t *handle)
{
  //int i = 0;
  bra_psl_list_item_t *tmp_ptr = bra_msg_list;
  bra_psl_list_item_t *prev_ptr = NULL;
  
  if (tmp_ptr == NULL) {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PSL_6E6EDE091E6A89EC9943FE935B849410, "BRA: ERROR: NULL ptr received. (function: bra_psl_list_delete_msg)\n"));   
    return FALSE;
  }
   
  /* find correct message */
  while (tmp_ptr != NULL) {
    if((tmp_ptr->uis_msg_type == uisMsgType) &&
      (tmp_ptr->handle.handleLen == handle->handleLen)) {
      if(memcmp(tmp_ptr->handle.handle, handle->handle, handle->handleLen) == 0)
        break;
    }
    prev_ptr = tmp_ptr;
    tmp_ptr  = tmp_ptr->next;
    //i++;
  }

  /* if no message found - return */
  if(tmp_ptr == NULL)
    return FALSE;

  /* remove message from list */
  if (prev_ptr == NULL) {
    bra_msg_list   = tmp_ptr->next;
  }
  else {
    prev_ptr->next = tmp_ptr->next;
  }

  bra_psl_list_delete_item(tmp_ptr);

  return TRUE;
}

int
bra_psl_list_delete_duplicate_msg(int i)
{

  bra_psl_list_item_t *tmp_ptr = bra_msg_list;
  bra_psl_list_item_t *new_msg_ptr = NULL;
  bra_psl_list_item_t *prev_ptr = NULL;
  
  if (tmp_ptr == NULL) {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_PSL_FCCD4B16161E51BF364BA4679F167473, "BRA: ERROR: NULL ptr received. (function: bra_psl_list_delete_deplicate_msg)\n"));
    return FALSE;
  }
   
  while (i>-1) 
  {
    new_msg_ptr = tmp_ptr;
    prev_ptr = tmp_ptr;
    tmp_ptr  = tmp_ptr->next;
    i--;
  }
  // if no message found - return 
  if(tmp_ptr == NULL)
    return FALSE;

  i = 1;
  while (tmp_ptr)  //in case server send the same time stamp
  {
     if((tmp_ptr->uis_msg_type == new_msg_ptr->uis_msg_type) &&
         (tmp_ptr->handle.handleLen == new_msg_ptr->handle.handleLen)) 
     {
         if(memcmp(tmp_ptr->handle.handle, new_msg_ptr->handle.handle, tmp_ptr->handle.handleLen) == 0)
         {
      	   prev_ptr->next = tmp_ptr->next;
            if (tmp_ptr==selected_msg_item) //If selected msg will be removed 20031124
            {
               selected_msg_idx=0;
               selected_msg_item=NULL;
            }
           bra_psl_list_delete_item(tmp_ptr);
           return i;
         }
     }
    prev_ptr = tmp_ptr;
    tmp_ptr  = tmp_ptr->next;
    i++;
  }
  return -1;

}

static void 
bra_psl_view(MSF_UINT32 msgType, uis_msg_handle_t *handle)
{
  UISif_getFullMsg (MSF_MODID_BRA, 0, msgType, handle,
                    TRUE, FALSE, FALSE);
}

static void
bra_psl_msg_delete_confirmation (MsfActionType response)
{
  bra_psl_msg_list_menu_t *win;

  if(response == MsfOk)
  {
    delete_all = FALSE;
    BRA_FREE(deleted_msg_item.handle.handle);
    if (selected_msg_item != NULL)
    {
      UISif_deleteMsg(MSF_MODID_BRA, 0, selected_msg_item->uis_msg_type, &(selected_msg_item->handle));
	  if (bra_msg_list)
      {
        deleted_msg_item = *selected_msg_item;
        deleted_msg_item.handle.handle = BRA_ALLOC(selected_msg_item->handle.handleLen);
        memcpy(deleted_msg_item.handle.handle, selected_msg_item->handle.handle, selected_msg_item->handle.handleLen);
        bra_psl_list_delete_msg(selected_msg_item->uis_msg_type, &(selected_msg_item->handle));
        win = (bra_psl_msg_list_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_MSG_LIST_DLG));
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, selected_msg_idx);
      }
	  else
      {
        bra_psl_list_delete_item(selected_msg_item);
        selected_msg_item = NULL;
        bra_win_close_window (BRA_WIN_CLOSE_ID, BRA_WIN_ID_INSE);  
		if(!bra_win_get_window(BRA_WIN_ID_INSE) 
			  && !bra_win_get_window(BRA_WIN_ID_OPT)
			  && !bra_view_if_has_viewable_page())
		   bra_destroy_ui();
        bra_cmn_deleted_dialog();
	  }
      selected_msg_item = NULL;
    }
	else //for view directly and no selected_msg_item
	{
      UISif_deleteMsg(MSF_MODID_BRA, 0, new_msg_item.msgType, &(new_msg_item.msg.handle));
	}
    //selected_msg_idx = 0;
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_MSG_LIST_DLG);
  }
  /*First close all windows until push msg menu*/
  //don't need close if user don't want to delete
  //bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_MSG_LIST_DLG);
}

static void
bra_psl_delete_msg_opt_menu (bra_win_t *win)
{
  bra_psl_msg_opt_menu_t *p;
  p = (bra_psl_msg_opt_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

#ifdef __UNIFIED_MSG_SUPPORT__
// UM:for delete all confirmation when viewing a push by unified message */
static void
bra_psl_um_msg_delete_all_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
#if 1
    wap_um_del_all_inbox_ind();
#else  	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
  }
}
#endif


#ifdef __MMI_PUSH_ACCEPT_CONFIRM__

static void bra_psl_confirm_accept_url_resp (MsfActionType response)
{
    if(response == MsfOk)
    {
        bra_psl_goto_url(dlg->url_str);
    }
}

static void bra_psl_confirm_accept_url(char* url)
{
    if (!bra_cmn_url_is_valid(url))
    {
        bra_dlg_create_dlg (MsfWarning,
            BRA_STR_INVALID_URL, 
            BRA_STR_OK, 
            0,
            0, 
            NULL);
    }
    else
    {
        bra_dlg_create_dlg (MsfConfirmation,
            BRA_STR_ACCEPT_URL_CONF, 
            BRA_STR_YES, 
            BRA_STR_NO,
            0, 
            bra_psl_confirm_accept_url_resp);
    }
}

#endif /*__MMI_PUSH_ACCEPT_CONFIRM__*/

#ifndef __MMI_PUSH_ACCEPT_CONFIRM__
static void
bra_psl_accept_url (char* url)
{
  if (!bra_cmn_url_is_valid(url))
  {
    bra_dlg_create_dlg (MsfWarning,
                        BRA_STR_INVALID_URL, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);
  }
  else
  {
    bra_psl_goto_url(url);
  }
}
#endif /*__MMI_PUSH_ACCEPT_CONFIRM__*/

static void
bra_psl_confirm_load_expired_resp (MsfActionType response)
{
  if(response == MsfOk)
    {
#ifdef __MMI_PUSH_ACCEPT_CONFIRM__
        bra_psl_confirm_accept_url(dlg->url_str);
#else
    bra_psl_accept_url(dlg->url_str);
#endif
    }
}

static void
bra_psl_confirm_load_expired(void)
{
  bra_dlg_create_dlg (MsfConfirmation,
                        BRA_STR_LOAD_EXPIRED_MSG_CONF, 
                        BRA_STR_YES, 
                        BRA_STR_NO,
                        0, 
                        bra_psl_confirm_load_expired_resp);
}

#if !(defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
static void
bra_psl_msg_delete_all_confirmation (MsfActionType response);
#endif

static void
bra_psl_action_msg_opt_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_psl_msg_opt_menu_t *p;
  //char *url;
  MSF_UINT8 i = 0;
  
  p = (bra_psl_msg_opt_menu_t *)(win);

  if (bra_action == p->back)
  {
    /* back to the previous menu */
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    if (show_accept && (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED))
    {
      /* Accept */
      if (dlg->isExpired)
        bra_psl_confirm_load_expired();
      else
      {
#ifdef __MMI_PUSH_ACCEPT_CONFIRM__
        bra_psl_confirm_accept_url(dlg->url_str);
#else
        bra_psl_accept_url(dlg->url_str);
#endif
      }
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
        /* add bookmark */
        if(selected_msg_item && selected_msg_item->url.value)
        {
            bra_bkm_create_offline_add_bookmark_form_with_title(
                                                BRA_STRCONV (BRA_CMN_HNV (NULL)),
                                                (char *)selected_msg_item->url.value,
                                                BRA_WIN_ID_PUSH_MSG_OPT_DLG);
        }
        else
        {
            bra_bkm_create_offline_add_bookmark_form_with_title(
                                                BRA_STRCONV (BRA_CMN_HNV (NULL)),
                                                "",
                                                BRA_WIN_ID_PUSH_MSG_OPT_DLG);
        }
    }
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
        /*add to trust list*/
        if(selected_msg_item && selected_msg_item->address.value)
        {
            bra_push_trustList_addItem((char *)selected_msg_item->address.value + 1,
                (selected_msg_item->address.value[0]));
        }
    }
#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete */
      /*Confirmation dialog*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ASK, 
                          BRA_STR_YES, //BRA_STR_OK, 
                          BRA_STR_NO,
                          0, 
                          bra_psl_msg_delete_confirmation);

    }
#if defined(__UNIFIED_MSG_SUPPORT__) && !defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)
    /* UM:for delete all menu confirmation when viewing a push by unified message */
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete all*/
      /*Confirmation dialog*/
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
        if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
        {
            bra_dlg_create_dlg (MsfConfirmation,
                BRA_STR_DELETE_ALL_ASK, 
                BRA_STR_YES, //BRA_STR_OK, 
                BRA_STR_NO,
                0, 
                bra_psl_msg_delete_all_confirmation);
        }
        else
#endif
        {
          bra_dlg_create_dlg (MsfConfirmation,
                              BRA_STR_DELETE_ALL_ASK, 
                              BRA_STR_YES, //BRA_STR_OK, 
                              BRA_STR_NO,
                              0, 
                              bra_psl_um_msg_delete_all_confirmation);

        }
    }
#endif
  }
}

#ifndef __UNIFIED_MSG_SUPPORT__
static void
bra_psl_action_accept_url (ctk_screen_handle scrid)
{
  CTK_UNUSED(scrid);

  if (dlg->isExpired)
    bra_psl_confirm_load_expired();
  else
  {
    bra_psl_accept_url(dlg->url_str);
  }

  widget_send_update_event_to_wap();
}
#endif

static void
bra_psl_create_msg_opt_menu (ctk_screen_handle scrid)//(void)
{
  bra_psl_msg_opt_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;

  CTK_UNUSED(scrid);
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_psl_msg_opt_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                         BRA_STR_OK,//BRA_STR_ACCEPT,
                                         MsfSelect,
                                         1, 
                                         0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                       BRA_STR_BACK,
                                       MsfBack,
                                       1, 
                                       0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
												               &prop.displaySize,
												               win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

   show_accept = 0;
   if ((!isInCall() || GetWapCallPresent()) && dlg->url_str != NULL && strlen(dlg->url_str) != 0) 
   {
     /* Show ACCEPT if no call exists (except for CSD) */
     show_accept = 1;
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_ACCEPT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
     HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
     i++;
   }
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_ADD_BOOKMARK,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_PUSH_ADDTO_TRUSTLIST,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#if defined(__UNIFIED_MSG_SUPPORT__) && !defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)
   /* UM:for delete all menu option when viewing a push by unified message */
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE_ALL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#endif

#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_UM_INBOX);
#else
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_INBOX);
#endif
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
    MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
   bra_win_show_window (BRA_WIN_ID_PUSH_MSG_OPT_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_psl_delete_msg_opt_menu, 
                    NULL,
                    bra_psl_action_msg_opt_menu);
}

#if !(defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
static void
bra_psl_msg_delete_all_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_psl_list_item_t *msg_item = bra_msg_list;
    delete_all = TRUE;
    BRA_FREE(deleted_msg_item.handle.handle);
    deleted_msg_item = *msg_item;
    deleted_msg_item.handle.handle = BRA_ALLOC(msg_item->handle.handleLen);
    memcpy(deleted_msg_item.handle.handle, msg_item->handle.handle, msg_item->handle.handleLen);
    UISif_deleteMsg(MSF_MODID_BRA, 0, msg_item->uis_msg_type, &(msg_item->handle));
    bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_MSG_LIST_DLG);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DELETING, MsfInfo, 5000);
  }
}
#endif

static void
bra_psl_action_selected_msg_opt_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_psl_msg_list_menu_t *p;
  MSF_UINT8 i = 0;

  p = (bra_psl_msg_list_menu_t *)(win);

  if (bra_action == p->back)
  {
#if defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)
    /* UM: delete all push related UI after pressing back key */
    // scenario where this func is entered when UM defined without LIST_OPTION shouldnt exist!
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
    if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
    {
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    }
    else
    {
      bra_destroy_ui();
    }
#else
     bra_destroy_ui();
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
#else
    /* back to the previous menu */
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
#endif
  }
  else if (bra_action == p->accept)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Read*/
      if (selected_msg_item)
      {
        bra_psl_view(selected_msg_item->uis_msg_type, &(selected_msg_item->handle));
        /*if (!selected_msg_item->read)
        {
          bra_psl_list_item_t *msg_item = selected_msg_item;
          MSF_BOOL unread_found      = FALSE;

          //Jo unread icon
          while(msg_item)
          {   
	         if(!msg_item->read && (msg_item !=selected_msg_item))
            {
	      	   unread_found = TRUE;
	      	   break;      	
            }
	         msg_item = msg_item->next;
          }
	       if (!unread_found)
	         bra_psl_cancel_push_indicator();    	
        }*/
      }
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
        /* add bookmark */
        if(selected_msg_item && selected_msg_item->url.value)
        {
            bra_bkm_create_offline_add_bookmark_form_with_title(
                                                BRA_STRCONV (BRA_CMN_HNV (NULL)),
                                                (char *)selected_msg_item->url.value,
                                                BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG);
        }
        else
        {
            bra_bkm_create_offline_add_bookmark_form_with_title(
                                                BRA_STRCONV (BRA_CMN_HNV (NULL)),
                                                "",
                                                BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG);
        }
    }
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
        /*add to trust list*/
        if(selected_msg_item && selected_msg_item->address.value)
        {
            bra_push_trustList_addItem((char *)selected_msg_item->address.value + 1,
                (selected_msg_item->address.value[0]));
        }
    }
#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Delete*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_psl_msg_delete_confirmation);      
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Delete All*/
#if defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)
      // scenario where this func is entered when UM defined without LIST_OPTION shouldnt exist!
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
        if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
        {
            bra_dlg_create_dlg (MsfConfirmation,
                BRA_STR_DELETE_ALL_ASK, 
                BRA_STR_YES, //BRA_STR_OK, 
                BRA_STR_NO,
                0, 
                bra_psl_msg_delete_all_confirmation);
        }
        else
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
        {
          bra_dlg_create_dlg (MsfConfirmation,
                              BRA_STR_DELETE_ALL_ASK, 
                              BRA_STR_YES, //BRA_STR_OK, 
                              BRA_STR_NO,
                              0, 
                              bra_psl_um_msg_delete_all_confirmation);
        }
#else
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ALL_ASK, //BRA_STR_DELETE_ALL, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_psl_msg_delete_all_confirmation);
#endif
    }
  }
}

static void
bra_psl_delete_selected_msg_opt_menu (bra_win_t *win)
{
  bra_psl_msg_opt_menu_t *p;
  p = (bra_psl_msg_opt_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
#if defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)
  if (!bra_msg_list && selected_msg_item)
  {
    if (selected_msg_item->handle.handle)
    {
      bra_psl_list_delete_item(selected_msg_item);
    }
    selected_msg_item = NULL;
  }
#endif
}

static void
bra_psl_create_msg_list_opt_menu (void)
{
  bra_psl_msg_opt_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;


  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_psl_msg_opt_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                         BRA_STR_OK,
                                         MsfSelect,
                                         1, 
                                         0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                       BRA_STR_BACK,
                                       MsfBack,
                                       1, 
                                       0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
												               &prop.displaySize,
												               win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_READ,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_ADD_BOOKMARK,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SET_PUSH_ADDTO_TRUSTLIST,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
#endif /*BRA_CONFIG_PUSH_TRUSTLIST*/
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE_ALL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;

#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_UM_INBOX);
#else
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_INBOX);
#endif
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
    MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
   bra_win_show_window (BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_psl_delete_selected_msg_opt_menu, 
                    NULL,
                    bra_psl_action_selected_msg_opt_menu);
}

static void
bra_psl_construct_msg_list_item(bra_psl_list_item_t *msg_item, MsfStringHandle *ms, MSF_UINT32 *imgResID)
{
  int slen;
  char *s;

  /* construct msg menu item text */
  if(msg_item->text.value)
  {
    slen = widget_utf8_to_ucs2_length_in_bytes((const kal_uint8*)msg_item->text.value);
    if (slen > 80) /* if text length exceed 40, then append ... */
    {
      char *us = (char*)BRA_ALLOC(82);
      widget_utf8_to_ucs2_string((kal_uint8 *)us, 82, (const kal_uint8*)msg_item->text.value);
      slen = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)us);
      s = (char*)BRA_ALLOC(slen+4);
      widget_ucs2_to_utf8_string((kal_uint8 *)s, slen+4, (const kal_uint8*)us);
      strcat(s, "...");
      BRA_FREE(us);
    }
    else
    {
      char *us = (char*)BRA_ALLOC(82);
      widget_utf8_to_ucs2_string((kal_uint8 *)us, 82, (const kal_uint8*)msg_item->text.value);
      slen = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)us);
      s = (char*)BRA_ALLOC(slen+1);
      widget_ucs2_to_utf8_string((kal_uint8 *)s, slen+1, (const kal_uint8*)us);
      BRA_FREE(us);
    }
  }
  else if(msg_item->url.value)
  {
    s = (char*)BRA_ALLOC(80);
    if(strlen((const char*)msg_item->url.value) > 79)
    {
      strncpy(s, (char*)msg_item->url.value, 76);
      s[76] = '\0';
      strcat(s, "...");
    }
    else
    {
      strncpy(s, (char*)msg_item->url.value, 79);
      s[79] = '\0';
    }
  }
  else if(msg_item->uis_msg_type == UIS_MSG_TYPE_PUSH_SI)
  {
    s = (char*)BRA_ALLOC(80);
    strcpy(s, "Service Indication");
  }
  else
  {
    s = (char*)BRA_ALLOC(80);
    strcpy(s, "Service Loading");
  }
  *ms = BRA_STRCONV(s);
  BRA_FREE(s);

  /* construct msg menu item icon */
  if(msg_item->read)
  {
    if (msg_item->expired)
      *imgResID = WAP_IMAGE_SW_PUSH_EREAD;
    else
      *imgResID = WAP_IMAGE_SW_PUSH_READ;
  }
  else
  {
    if (msg_item->expired)
      *imgResID = WAP_IMAGE_SW_PUSH_EUREAD;
    else
      *imgResID = WAP_IMAGE_SW_PUSH_UREAD;
  }
}

static void
bra_psl_update_list_menu(void)
{
  bra_psl_msg_list_menu_t *win;
  bra_psl_list_item_t *msg_item;
  MsfStringHandle ms;
  MSF_UINT32 imgResID;
  MSF_UINT8 i = 0;

  win = (bra_psl_msg_list_menu_t*)bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG);
  msg_item = bra_msg_list;
  while(msg_item)
  {   
    bra_psl_construct_msg_list_item(msg_item, &ms, &imgResID);
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, ms,  0, HDIa_widgetImageGetPredefined(imgResID,0), 0, FALSE); 

    MSF_WIDGET_RELEASE(ms);
    msg_item = msg_item->next;   
  } 
  //if(selected_msg_item == msg_item) {
    //Jo Set focus-031021
    if (selected_msg_idx>=i)
      selected_msg_idx--;

    MSF_WIDGET_CHOICE_SET_ELEM_STATE(win->window, selected_msg_idx, MSF_CHOICE_ELEMENT_SELECTED);
    //selected_msg_idx = i;
   

   /* remove the left over msg item from menu (residue of delete operation) */ 
   //for ( ; i<=30; i++)
     //MSF_WIDGET_CHOICE_REMOVE_ELEMENT(win->window, i);

}

static int bra_psl_remove_high_msg_item(bra_psl_list_item_t **pMsgList, uis_msg_handle_t msgHandle);

#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
static void bra_psl_remove_all_high_msg_item(bra_psl_list_item_t *pMsgList);
#endif

static void
bra_psl_msg_list_in_focus(bra_win_t *win)
{  
   bra_psl_msg_list_menu_t *p;
   int                      push_SL_setting;

   p = (bra_psl_msg_list_menu_t *)(win);
   push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);

   /* clear new message handle */
   if (!(new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SI &&
         new_msg_priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH) &&
       !(new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SL &&
                 push_SL_setting == 2 && 
                 new_msg_priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH))
   {
     BRA_FREE(new_msg_item.msg.handle.handle);
     new_msg_item.msg.handle.handle = NULL;
     new_msg_priority = -1;
   }
   HDIa_widgetExtClearPush();

#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
   wap_um_cancel_new_push_msg_ind();
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */

#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
   HDIa_widgetExtClearUrgentServiceIndication();
   HDIa_widgetExtClearUrgentServiceLoading();
   if (bra_msg_new_hiSI_list)
     {
       bra_psl_remove_all_high_msg_item(bra_msg_new_hiSI_list);
       bra_msg_new_hiSI_list = NULL;
     }
   if (bra_msg_new_hiSL_list)
   {
       bra_psl_remove_all_high_msg_item(bra_msg_new_hiSL_list);
       bra_msg_new_hiSL_list = NULL;
   }
#endif

   if (delete_all || !bra_msg_list)
     return;

   /* process pending list: ie. remove deleted msg from bra_msg_list */
   if (bra_psl_process_pdn_list())
     bra_win_enable_focus();

   /* refresh entire menu if list not empty */
   if (!bra_msg_list)
   {
     bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_EMPTY, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
     bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PUSH_MSG_LIST_DLG);
     
     if (!bra_win_get_window(BRA_WIN_ID_INSE) &&
        !bra_win_get_window(BRA_WIN_ID_OPT) &&
        bra_win_get_window(BRA_WIN_ID_VIEWPORT) &&
        !bra_view_if_has_viewable_page())
       bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_VIEWPORT);
     
     return;
   }

   bra_psl_update_list_menu();
}

static void
bra_psl_delete_msg_list_menu (bra_win_t *win)
{
  bra_psl_msg_list_menu_t *p;
  p = (bra_psl_msg_list_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

  bra_psl_list_free();
  bra_psl_pdn_free();
  selected_msg_item = NULL;
  selected_msg_idx = 0;
  read_from_idle = 0;
}

static void
bra_psl_action_msg_list_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_psl_msg_list_menu_t *p;

  p = (bra_psl_msg_list_menu_t *)(win);

  if (bra_action == p->back)
  {
    /* back to the previous menu */
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
	//johnnie
	if(!bra_win_get_window(BRA_WIN_ID_INSE) 
	      && !bra_win_get_window(BRA_WIN_ID_OPT)
	      && !bra_view_if_has_viewable_page())
	   bra_destroy_ui();
	//johnnie
  }
  else if (bra_action == p->accept)
  {
    bra_psl_list_item_t *msg_item;
    MSF_UINT8 i = 0;

    msg_item = bra_msg_list;
    while(msg_item && (!(MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)))
    {
      i++;
      msg_item = msg_item->next;
    }

    selected_msg_item = msg_item;
    selected_msg_idx = i;
    read_from_idle = 0;

    /* Options for msg list */
    bra_psl_create_msg_list_opt_menu();
  }
}

static void
bra_psl_create_msg_list_menu (void)
{
  bra_psl_msg_list_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  
  if(!bra_win_get_window(BRA_WIN_ID_INSE) 
     && !bra_win_get_window(BRA_WIN_ID_OPT)
     && !bra_win_get_window(BRA_WIN_ID_VIEWPORT))
  {
#ifdef BRA_CFG_DUAL_SIM
      bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif
      bra_create_ui(BRA_UI_VIEWPORT);
  }
  
  bra_view_disable();
  delete_all = FALSE;
  
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_psl_msg_list_menu_t);

   win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                         BRA_STR_OPTIONS,
                                         MsfSelect,
                                         1, 
                                         0x8000);
   win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                       BRA_STR_BACK,
                                       MsfBack,
                                       1, 
                                       0x8000);
   win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
												   &prop.displaySize,
												   win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_UM_INBOX);
#else
    MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_INBOX);
#endif
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_EXT_DISBALE_SLIM_MENU_STYLE | MSF_WINDOW_PROPERTY_TITLE);
  
	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
   bra_win_show_window (BRA_WIN_ID_PUSH_MSG_LIST_DLG, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_psl_delete_msg_list_menu, 
                    bra_psl_msg_list_in_focus,
                    bra_psl_action_msg_list_menu);

   bra_psl_update_list_menu();
}

void
bra_psl_register_reply (void *p)
{
  uis_reply_register_t *reply_ptr = (uis_reply_register_t*)p;

  if(reply_ptr->result == UIS_RESULT_SUCCESS && reply_ptr->msgType == UIS_MSG_TYPE_PUSH_SL) {
    UISif_register(MSF_MODID_BRA, UIS_MSG_TYPE_PUSH_SI);
  }
  else {
    /* register completely */
#ifdef __UNIFIED_MSG_SUPPORT__
    /* UM:send push inbox ready indiation */
    wap_um_push_ready_ind();
#endif    
  }
}

static int bra_psl_remove_high_msg_item(bra_psl_list_item_t **pMsgList, uis_msg_handle_t msgHandle);

void
bra_psl_notify_msg_deleted(void* p)
{
  uis_notify_msg_deleted_t* del_notify = (uis_notify_msg_deleted_t*)p;
  uis_key_value_t          read;
  MSF_BOOL                 bool_read = FALSE;

  read.key       = UIS_MSG_KEY_READ;
  read.valueLen  = sizeof(MSF_BOOL);
  read.valueType = UIS_VALUE_TYPE_BOOL;
  read.value     = (unsigned char *)&bool_read;
 
  if (del_notify->msgType == UIS_MSG_TYPE_PUSH_SL || del_notify->msgType == UIS_MSG_TYPE_PUSH_SI)
  {
    bra_psl_unread_check();

    if (del_notify->msgType == UIS_MSG_TYPE_PUSH_SL)
    {
        bra_psl_remove_high_msg_item(&bra_msg_new_hiSL_list, del_notify->handle);
        if (!bra_msg_new_hiSL_list)
        {
            HDIa_widgetExtClearUrgentServiceLoading();
        }
    }
    else
    {
        bra_psl_remove_high_msg_item(&bra_msg_new_hiSI_list, del_notify->handle);
        if (!bra_msg_new_hiSI_list)
        {
            HDIa_widgetExtClearUrgentServiceIndication();            
        }
    }

//#ifdef __UNIFIED_MSG_SUPPORT__
    /* UM:send push inbox refresh indication */
//    wap_um_refresh_push_inbox_ind();
//#endif  
    if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
    {
      // add deleted msg handle to pending list
      bra_psl_pdn_push(&(del_notify->handle));
    }
    if (deleted_msg_item.handle.handle != NULL
        && del_notify->handle.handle != NULL
        && deleted_msg_item.handle.handleLen == del_notify->handle.handleLen    
        && memcmp(deleted_msg_item.handle.handle, del_notify->handle.handle, del_notify->handle.handleLen) == 0)
    {
      BRA_FREE(deleted_msg_item.handle.handle);
      deleted_msg_item.handle.handle = NULL;
    }
    else
    {
      // set timer expired in 500ms
      MSF_TIMER_SET (MSF_MODID_BRA, BRA_INBOX_REFRESH_TIMER_ID, 5);
    }

    //if (bra_win_current_window() == BRA_WIN_ID_PUSH_MSG_LIST_DLG)
      //bra_win_enable_focus();
  }
}

void bra_psl_list_msg_async_deleted(MsfActionType response)
{
  bra_win_enable_focus();
}

void
bra_psl_timer_expired(void *p)
{
  if (!bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON))
    return;

#ifdef __UNIFIED_MSG_SUPPORT__
  /* UM:send push inbox refresh indication */
  wap_um_refresh_push_inbox_ind();
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
  if (bra_win_current_window() == BRA_WIN_ID_PUSH_MSG_LIST_DLG)
  {
    bra_dlg_create_dlg (MsfWarning,
                          BRA_STR_MSG_DELETED, 
                          BRA_STR_OK, 
                          0,
                          0, 
                          bra_psl_list_msg_async_deleted);
  }
#endif
#else
  if (bra_win_current_window() == BRA_WIN_ID_PUSH_MSG_LIST_DLG)
  {
    bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_MSG_DELETED, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            bra_psl_list_msg_async_deleted);
  }
#endif  

}

void
bra_psl_unread_check(void)
{
  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,
    BRA_PSL_B2B1BD6BFE30B233D4927DF55911404E, "bra_psl_unread_check. state = %d\n",bra_psl_uis_state));
  if (bra_psl_uis_state==1)
  {
	uis_key_value_t read;
    MSF_BOOL        bool_read = FALSE; 
    read.key       = UIS_MSG_KEY_READ;
    read.valueLen  = sizeof(MSF_BOOL);
    read.valueType = UIS_VALUE_TYPE_BOOL;
    read.value     = (unsigned char *)&bool_read;

    UISif_getNbrOfMsgs(MSF_MODID_BRA,
			   0,
			   UIS_MSG_TYPE_PUSH_SL,
			   1,
			   &read);
  }

}
static void
bra_psl_list_free_msg(uis_msg_list_item_t *msg_item)
{
  int i;
  if (msg_item) 
  {
    if (msg_item->handle.handle) {
      BRA_FREE (msg_item->handle.handle);
    }
    if (msg_item->titleList)
    {
      for (i = 0; i < (msg_item->titleListSize); i++) {
        if(msg_item->titleList[i].value)
          BRA_FREE (msg_item->titleList[i].value);
      }
      BRA_FREE (msg_item->titleList);
    }
  }
}

void 
bra_psl_msg_list_reply (void *p)
{
  int i;
  uis_reply_msg_list_t *list_ptr = (uis_reply_msg_list_t*)p;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_PSL_E2101CC4EAD7DBCE88136A5F4D33BA43, "BRA: Reply Msg List from = %d, # = %d\n",
               list_ptr->msgType, list_ptr->msgListSize));

  for(i=0; i<list_ptr->msgListSize; i++)
  {
    if(list_ptr->msgType == UIS_MSG_TYPE_PUSH_SI || list_ptr->msgType == UIS_MSG_TYPE_PUSH_SL)
      bra_psl_list_add_msg(list_ptr->msgType, &list_ptr->msgList[i]);
    else
      /* No message type match found */
      MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
          BRA_PSL_15C46E78DD1BD014F48EB9D51D5E83A3, "BRA: ERROR: Unknown message received. (function: bra_psl_list_add_msg)\n"));   
    
    bra_psl_list_free_msg(&list_ptr->msgList[i]);
  }

  if(list_ptr->nextMsg != 0)
  {
    UISif_getMsgList(MSF_MODID_BRA, list_ptr->transactionId, list_ptr->msgType, 0, NULL, list_ptr->nextMsg);
  }
  else if(list_ptr->msgType == UIS_MSG_TYPE_PUSH_SL)
  {
    UISif_getMsgList(MSF_MODID_BRA, list_ptr->transactionId, UIS_MSG_TYPE_PUSH_SI, 0, NULL, 0);
  }
  else
  {
     //Jo max
     if(list_ptr->transactionId==1)
     {
        bra_psl_list_item_t *msg_item =bra_msg_list;
        while (msg_item->next)
          msg_item = msg_item->next;
              
        UISif_deleteMsg(MSF_MODID_BRA, 1, msg_item->uis_msg_type, &msg_item->handle);

        bra_psl_list_free();

        goto done;
     }
#ifdef __UNIFIED_MSG_SUPPORT__
     else if(list_ptr->transactionId == 2) /* UM: get push message number */
     {
        bra_psl_list_item_t *msg_item = bra_msg_list;
        int read = 0;
        int unread = 0;        
        
        while(msg_item != NULL) 
        {          
          if(msg_item->read)
            read++;
          else
            unread++;
          msg_item = msg_item->next;
        }
        
        wap_um_get_push_msg_num_rsp(read, unread);

        bra_psl_list_free();

        goto done;
     }
     else if(list_ptr->transactionId == 3) /* UM: get push message list */
     {
        bra_psl_list_item_t *msg_item =bra_msg_list;
        int msg_count = 0;
        unsigned int *time;

        time = (unsigned int *) BRA_ALLOC((sizeof(unsigned int) * PUSH_MAX_NO_OF_MSG));

        while(msg_item != NULL) 
        {
          time[msg_count++] = (unsigned int)((*((MSF_UINT32*)msg_item->time.value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/);
          msg_item = msg_item->next;
        }
                 
        wap_um_get_push_msg_list_rsp(startFromMsg, msg_count, time);
        BRA_FREE(time);

        bra_psl_list_free();

        goto done;
     }
     else if(list_ptr->transactionId == 4) /* UM: get push message info */
     {
        bra_psl_list_item_t *msg_item =bra_msg_list;
        int msg_count = 0;
        unsigned char **subject;
        unsigned char **address;
        unsigned int *time;
        unsigned int *icon_id;
        
        subject = (unsigned char**)BRA_ALLOC((sizeof(unsigned char*)*PUSH_MAX_NO_OF_MSG));
        address = (unsigned char**)BRA_ALLOC((sizeof(unsigned char*)*PUSH_MAX_NO_OF_MSG));
        time = (unsigned int *) BRA_ALLOC((sizeof(unsigned int)*PUSH_MAX_NO_OF_MSG));
        icon_id = (unsigned int *) BRA_ALLOC((sizeof(unsigned int)*PUSH_MAX_NO_OF_MSG));

        while(msg_item != NULL) 
        {
          if(msg_item->text.value != NULL)
          {            
            subject[msg_count] = msg_item->text.value;
          }
          else
          {
            subject[msg_count] = msg_item->url.value;
          }
#ifdef MSF_CFG_PUSH_ADDRESS_OPTION
          if (MSF_CFG_PUSH_ADDRESS_OPTION == 1)
          {
            address[msg_count] = msg_item->address.value;
          }
          else
          {
            address[msg_count] = NULL;
          }
#else
          address[msg_count] = NULL;
#endif /* MSF_CFG_PUSH_ADDRESS_OPTION */
          time[msg_count] = (unsigned int)((*((MSF_UINT32*)msg_item->time.value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/);
          if(msg_item->read)
          {
            if(msg_item->expired)
              icon_id[msg_count++] = (unsigned int)WAP_IMAGE_SW_PUSH_EREAD;
            else
              icon_id[msg_count++] = (unsigned int)WAP_IMAGE_SW_PUSH_READ;
          }
          else
          {
            if(msg_item->expired)
              icon_id[msg_count++] = (unsigned int)WAP_IMAGE_SW_PUSH_EUREAD;
            else
              icon_id[msg_count++] = (unsigned int)WAP_IMAGE_SW_PUSH_UREAD;
          }
          msg_item = msg_item->next;
        }
                 
        wap_um_get_push_msg_info_rsp(startFromMsg, numberOfMsg, msg_count, time, subject, address, icon_id);
        BRA_FREE(time);
        BRA_FREE(subject);
        BRA_FREE(address);
        bra_psl_list_free();

        goto done;
     }
     else if(list_ptr->transactionId == 5) /* UM: delete push inbox */
     {
        if(bra_msg_list)
        {
          bra_psl_list_item_t *msg_item = bra_msg_list;
          UISif_deleteMsg(MSF_MODID_BRA, 2, msg_item->uis_msg_type, &(msg_item->handle));
          bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
        }
        else
        {
          /* empty, so send response anyway */
          bra_psl_cancel_push_indicator();
          wap_um_del_push_msg_inbox_rsp();
        }        
        goto done;
     }
     else if(list_ptr->transactionId == 6) /* UM: view push message */
     {
        bra_psl_list_item_t *msg_item =bra_msg_list;
        int msg_count = 0;

        if (msg_item == NULL)
        {
            bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_EMPTY,
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
            wap_um_refresh_push_inbox_ind();
        }
        while(msg_item != NULL) 
        {
          if(msg_count == msgIndex)
          {
#ifdef BRA_CFG_DUAL_SIM
            bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif
            bra_create_ui(BRA_UI_VIEWPORT);  
            bra_view_disable();         
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            bra_psl_create_msg_list_opt_menu();
#else
            bra_psl_view (msg_item->uis_msg_type, &(msg_item->handle));
#endif
            /* create and initiate new item */
            selected_msg_item = BRA_ALLOCTYPE(bra_psl_list_item_t);
            selected_msg_item->text.value   = NULL;
            selected_msg_item->time.value   = NULL;
            selected_msg_item->url.value    = NULL;
            selected_msg_item->address.value    = NULL;
            selected_msg_item->uis_msg_type = msg_item->uis_msg_type;
            selected_msg_item->address      = msg_item->address;
            msg_item->address.value = NULL;
            selected_msg_item->url          = msg_item->url;
            msg_item->url.value             = NULL;
            /* copy handle*/
            memcpy(&selected_msg_item->handle, &(msg_item->handle), sizeof(uis_msg_handle_t));
            selected_msg_item->handle.handle = BRA_ALLOC(msg_item->handle.handleLen);
            memcpy(selected_msg_item->handle.handle, msg_item->handle.handle, msg_item->handle.handleLen);
            break;
          }
          msg_item = msg_item->next;
          msg_count++;
        }
                 
        bra_psl_list_free();

        goto done;
     }
     else if(list_ptr->transactionId == 7) /* UM: delete all push message while viewing push message */
     {
        if(bra_msg_list)
        {
          bra_psl_list_item_t *msg_item = bra_msg_list;
          UISif_deleteMsg(MSF_MODID_BRA, 3, msg_item->uis_msg_type, &(msg_item->handle));
          bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
        }
        goto done;
     }
     else if(list_ptr->transactionId == 8) // UM: send new push message notification to MMI
     {
        int push_SL_setting;
        bra_psl_list_item_t *msg_item =bra_msg_list;
        int msg_count = 0;
        unsigned int time = 0;

        while(msg_item != NULL) 
        {
          if(msg_item->handle.handleLen == new_msg_item.msg.handle.handleLen
             && memcmp(msg_item->handle.handle, new_msg_item.msg.handle.handle, msg_item->handle.handleLen) == 0) 
          {
          	time = (unsigned int)((*((MSF_UINT32*)msg_item->time.value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/);
            break;
          }
          msg_item = msg_item->next;
          msg_count++;
        }              

        push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);

        if (new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SI && 
            new_msg_priority == UIS_MSG_KEY_VALUE_PRIORITY_LOW)
        {
          wap_um_refresh_push_inbox_ind();
        }
        else if ((new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SL &&
                  push_SL_setting == 2 && 
                  new_msg_priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH) ||/*without confirm*/
                 (new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SI && 
                  new_msg_priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH))
        {
            if (new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SL)
            {
                HDIa_widgetExtRegisterUrgentServiceLoading(TRUE);
            }
            else
            {
                HDIa_widgetExtRegisterUrgentServiceIndication(TRUE);
            }
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
            if (bra_win_current_window() == BRA_WIN_ID_PUSH_MSG_LIST_DLG)
            {
                if (new_msg_item.msgType == UIS_MSG_TYPE_PUSH_SL)
                {
                    HDIa_widgetExtClearUrgentServiceLoading();
                }
                else
                {
                    HDIa_widgetExtClearUrgentServiceIndication();
                }
            }
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
            wap_um_refresh_push_inbox_ind();
        }
        else
        {
          HDIa_widgetExtRegisterNewPush();         
          wap_um_new_push_msg_ind(msg_count, time);
        }
        bra_psl_list_free();
        goto done;
     }     
#endif     
     /* MsgList get completely and at least one message exists, create MsgList menu */
     if(bra_msg_list)
        bra_psl_create_msg_list_menu();
     else
     {
        /* No msg exists, give a 3 second notification */
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
     }
  }

done:
  //Jo men leak 031011
  if (list_ptr->msgList)
     BRA_FREE(list_ptr->msgList);
}

void bra_psl_SLhigh_notification_handler(void);
void bra_psl_SIhigh_notification_handler(void);

static void
bra_psl_delete_push_msg_dlg(bra_win_t *win)
{
  bra_psl_x_t *p;
  p = (bra_psl_x_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

  MSF_WIDGET_RELEASE (p->window); 

  BRA_FREE (p->url_str);
  BRA_FREE (p);
#if !(defined(__UNIFIED_MSG_SUPPORT__) && defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__))
  if (!bra_msg_list && selected_msg_item)
  {
    if (selected_msg_item->handle.handle)
    {
      bra_psl_list_delete_item(selected_msg_item);
    }
	selected_msg_item = NULL;
  }
#endif

  if (read_from_idle && 
      !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) &&
      !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG) &&
      !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_OPT_DLG) &&
      !bra_win_get_window(BRA_WIN_ID_INSE) &&
      !bra_win_get_window(BRA_WIN_ID_OPT) &&
      bra_win_get_window(BRA_WIN_ID_VIEWPORT) &&
      selected_msg_item)
  {
    if (selected_msg_item->handle.handle)
    {
     bra_psl_list_delete_item(selected_msg_item);
    }
    selected_msg_item = NULL;
  }
}

static void
bra_psl_display_msg_back (ctk_screen_handle scrid)
{
  CTK_UNUSED(scrid);
    if (read_from_idle && 
        !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) &&
        !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG) &&
        !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_OPT_DLG) &&
        !bra_win_get_window(BRA_WIN_ID_INSE) &&
        !bra_win_get_window(BRA_WIN_ID_OPT) &&
        bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        bra_destroy_ui();
#ifndef __UNIFIED_MSG_SUPPORT__
        if(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) == NULL &&
           bra_msg_new_hiSL_list == NULL &&
           bra_msg_new_hiSI_list == NULL)
          bra_psl_create_push_inbox();  
#endif
    }
    else
    {
#ifdef __UNIFIED_MSG_SUPPORT__
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        /* UM: go back to message list option menu if defined */
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
#else
        /* UM: delete all push related UI after pressing back key */
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
        if (!bra_win_get_window(BRA_WIN_ID_INSE) && !bra_win_get_window(BRA_WIN_ID_OPT))
        {
          bra_destroy_ui();
        }
        else
        {
          bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        }
#else
        bra_destroy_ui();
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
#else  
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        if (!bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) &&
            !bra_win_get_window(BRA_WIN_ID_INSE) &&
            !bra_win_get_window(BRA_WIN_ID_OPT) &&
            bra_win_get_window(BRA_WIN_ID_VIEWPORT) &&
            !bra_view_if_has_viewable_page())
            bra_destroy_ui();
        if(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) == NULL)
            bra_psl_create_push_inbox();  
#endif /*__UNIFIED_MSG_SUPPORT__*/
    }
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
#endif 

static int
bra_psl_find_key(uis_key_value_t *propertyList, int listSize, MSF_UINT16 key)
{
  int i = 0;

  while ((i < listSize) && (propertyList[i].key != key))
    i++;

  if (i == listSize)
    i = -1;

  return i;
}

extern int HDIa_widgetGetSystemFontSize(void);

static void
bra_psl_display_msg(uis_reply_full_msg_t *p)
{
  extern char* bra_format_datetime_string(MSF_UINT32 dt_secs);
  uis_full_msg_t       *fullMsg;
  MsfPosition	          pos =  {0, 0 /*20*/};

  int                     idx; // property index
  //char                  created_str[30];
  //char                  expired_str[30];
  char *dt_str = 0;
    ctk_screen_handle	scrid;
    kal_uint8 			*text;
    int				text_size;

  if (p->msg.propertyList == NULL)
    return;

  fullMsg = &p->msg;

  dlg = BRA_ALLOCTYPE (bra_psl_x_t);
  /*Set all members to 0*/
  memset (dlg, 0, sizeof (bra_psl_x_t));
    	
    /* Prepare text */
    text_size = 150; /* The default size. widget_ucs2str_append_* will realloc the buffer on necessary */
    text = BRA_ALLOC(text_size);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

  /*Created Field*/
  //created_str[0] = 0;
  if ((idx = bra_psl_find_key(fullMsg->propertyList, fullMsg->propertyListSize, UIS_MSG_KEY_CREATED)) != -1) 
  {
    if(fullMsg->propertyList[idx].value != NULL /*&& *(fullMsg->propertyList[idx].value) != 0*/) 
    {
      //msf_cmmn_time2str (((*((MSF_UINT32*)fullMsg->propertyList[idx].value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/), created_str);
      /*msf_cmmn_time2str (HDIa_timeUTCToLocal((*((MSF_UINT32*)fullMsg->propertyList[idx].value))), created_str);
      bra_psl_date_transform (created_str);
      text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)created_str);
      text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");*/

      dt_str = bra_format_datetime_string(HDIa_timeUTCToLocal((*((MSF_UINT32*)fullMsg->propertyList[idx].value))));
      text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)dt_str);
      text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
      BRA_FREE(dt_str);
    }
  }

  /*From Field*/
#ifdef MSF_CFG_PUSH_ADDRESS_OPTION
  if ((idx = bra_psl_find_key(fullMsg->propertyList, fullMsg->propertyListSize, UIS_MSG_KEY_FROM)) != -1) 
  {
     if(fullMsg->propertyList[idx].value != NULL)
     {
       if (MSF_CFG_PUSH_ADDRESS_OPTION == 1)
       {
         text = widget_ucs2str_append_id(MSF_MODID_BRA, text, &text_size, 
             (MSF_UINT16)BRA_STR_ID_FROM);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)fullMsg->propertyList[idx].value);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
       }
       else if (MSF_CFG_PUSH_ADDRESS_OPTION == 2 &&
                selected_msg_item &&
                !selected_msg_item->address.value)
       {
           selected_msg_item->address.value = BRA_ALLOC(strlen((char*)fullMsg->propertyList[idx].value) + 1);
           strcpy((char*)selected_msg_item->address.value, (char*)fullMsg->propertyList[idx].value);
       }
     }
  }
#endif

  /*Expired Field*/
  dlg->isExpired = 0;
  //expired_str[0] = 0;
  if ((idx = bra_psl_find_key(fullMsg->propertyList, fullMsg->propertyListSize, UIS_MSG_KEY_EXPIRES)) != -1) 
  {
     if(fullMsg->propertyList[idx].value != NULL /*&& *(fullMsg->propertyList[idx].value) != 0*/) 
     {
         text = widget_ucs2str_append_id(MSF_MODID_BRA, text, &text_size, 
             (MSF_UINT16)BRA_STR_ID_EXPIRES);     
         //msf_cmmn_time2str (((*((MSF_UINT32*)fullMsg->propertyList[idx].value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/), expired_str);
         /*msf_cmmn_time2str (HDIa_timeUTCToLocal((*((MSF_UINT32*)fullMsg->propertyList[idx].value))), expired_str);
         bra_psl_date_transform (expired_str);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)expired_str);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");*/

         dt_str = bra_format_datetime_string(HDIa_timeUTCToLocal((*((MSF_UINT32*)fullMsg->propertyList[idx].value))));
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)dt_str);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         BRA_FREE(dt_str);

         if (*((MSF_UINT32*)fullMsg->propertyList[idx].value)<=(MSF_UINT32)HDIa_timeLocalToUTC(MSF_TIME_GET_CURRENT()))
           dlg->isExpired = 1;
     }
  }

  /*URL Field*/
  if ((idx = bra_psl_find_key(fullMsg->propertyList, fullMsg->propertyListSize, UIS_MSG_KEY_URL)) != -1) 
  {
     if(fullMsg->propertyList[idx].value != NULL) 
     {
         text = widget_ucs2str_append_id(MSF_MODID_BRA, text, &text_size, 
             (MSF_UINT16)BRA_STR_ID_URL);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)fullMsg->propertyList[idx].value);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");

         dlg->url_str = (char*)fullMsg->propertyList[idx].value;
         fullMsg->propertyList[idx].value = NULL;/* avoid free of this ptr later */
         if (selected_msg_item && !selected_msg_item->url.value)
         {
             selected_msg_item->url.value = BRA_ALLOC(strlen(dlg->url_str) + 1);
             strcpy((char*)selected_msg_item->url.value, (char*)dlg->url_str);
         }
     }
  }

  /*Subject Field*/
  if ((idx = bra_psl_find_key(fullMsg->propertyList, fullMsg->propertyListSize, UIS_MSG_KEY_SUBJECT)) != -1) 
  {
     if(fullMsg->propertyList[idx].value != NULL) 
     {
         text = widget_ucs2str_append_id(MSF_MODID_BRA, text, &text_size, 
             (MSF_UINT16)BRA_STR_ID_MESSAGE);
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)"\n");
         text = widget_ucs2str_append_utf8(MSF_MODID_BRA, text, &text_size, (kal_uint8*)fullMsg->propertyList[idx].value);
     }
  }

  /*Create Form*/
  dlg->window = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, text, 
    									(MSF_UINT16)BRA_STR_ID_MESSAGE_FORTITLE, 0); 
  BRA_FREE(text); // release the text
  /* Set Key */
  scrid = HDIa_widgetCtkGetScreenHandle(dlg->window);
#ifdef __UNIFIED_MSG_SUPPORT__
  ctk_screen_addLSK_UA(scrid, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK, NULL, bra_psl_create_msg_opt_menu, KAL_TRUE);
#else
  if (read_from_idle)
    ctk_screen_addLSK_UA(scrid, STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK, NULL, bra_psl_create_msg_opt_menu, KAL_TRUE);
  else
  {
    show_accept = 0;
    if ((!isInCall() || GetWapCallPresent()) && dlg->url_str != NULL && strlen(dlg->url_str) != 0)
    {
     /* Show ACCEPT if no call exists (except for CSD) */
     show_accept = 1;
     ctk_screen_addLSK_UA(scrid, BRA_STR_ID_ACCEPT, IMG_GLOBAL_OK, NULL, bra_psl_action_accept_url, KAL_TRUE);
    }
  }
#endif
  ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, bra_psl_display_msg_back, KAL_TRUE);

  bra_win_show_window (BRA_WIN_ID_PUSH_MSG_DLG, 
                      (bra_win_t*)dlg, 
                      (MsfPosition*)&pos, 
                      bra_psl_delete_push_msg_dlg, 
                      NULL,
                      NULL); //bra_psl_action_push_msg_dlg);

}

static void
bra_psl_free_full_msg (uis_full_msg_t *p)
{
  int i;

  if (p) 
  {
    if(p->handle.handle)
      BRA_FREE(p->handle.handle);

    if (p->propertyList)
    {
      for (i = 0; i < (p->propertyListSize); i++) {
        if(p->propertyList[i].value)
          BRA_FREE(p->propertyList[i].value);
      }
     BRA_FREE (p->propertyList);
    }
    if (p->hiddenPropertyList)
    {
      for (i = 0; i < (p->hiddenPropertyListSize); i++) {
        if(p->hiddenPropertyList[i].value)
          BRA_FREE(p->hiddenPropertyList[i].value);
      }
      BRA_FREE (p->hiddenPropertyList);
    }

    if (p->data) {
      BRA_FREE (p->data);
    }
  }
}

static int
bra_psl_find_msg_index(uis_msg_handle_t *hdl)
{
  bra_psl_list_item_t *crtMsg = bra_msg_list;
  int index = 0;
  
  while(crtMsg)
  {
    if (crtMsg->handle.handleLen == hdl->handleLen &&
        memcmp(crtMsg->handle.handle, hdl->handle, hdl->handleLen) == 0)
      return index;
    crtMsg = crtMsg->next;
    index++;
  }
  return -1;
}

void
bra_psl_reply_full_msg (void *p)
{
  uis_reply_full_msg_t *msg = (uis_reply_full_msg_t *)p;
  uis_full_msg_t        fullMsg;
  uis_key_value_t       key;
  MSF_BOOL              keyValue;
  int                   idx;
  MsfStringHandle ms;
  MSF_UINT32 imgResID;
  bra_psl_msg_list_menu_t *win;
  extern bra_psl_cancel_push_indicator(void);

  if (bra_psl_remove_high_msg_item(&bra_msg_new_hiSI_list, msg->msg.handle) && !bra_msg_new_hiSI_list)
  {
    HDIa_widgetExtClearUrgentServiceIndication();
  }
  if (bra_psl_remove_high_msg_item(&bra_msg_new_hiSL_list, msg->msg.handle) && !bra_msg_new_hiSL_list)
  {
    HDIa_widgetExtClearUrgentServiceLoading();
  }
  
  
  if(msg->result == UIS_RESULT_SUCCESS) {
    bra_psl_display_msg (msg);

    if ((idx = bra_psl_find_key(msg->msg.propertyList, msg->msg.propertyListSize, UIS_MSG_KEY_READ)) != -1) {
      if(*((MSF_BOOL*)msg->msg.propertyList[idx].value) != TRUE) {
        keyValue      = TRUE;
        key.key       = UIS_MSG_KEY_READ;
        key.valueLen  = sizeof(MSF_BOOL);
        key.valueType = UIS_VALUE_TYPE_BOOL;
        key.value     = (unsigned char *)&keyValue;
        memset(&fullMsg, 0, sizeof(uis_full_msg_t));
        fullMsg.handle = msg->msg.handle;
        fullMsg.propertyListSize = 1;
        fullMsg.propertyList = &key;

        UISif_changeMsg(MSF_MODID_BRA, 0, msg->msgType,
                        TRUE, FALSE, FALSE, &fullMsg);
        
        if(selected_msg_item)
          selected_msg_item->read = 1;
        
        win = (bra_psl_msg_list_menu_t *)(bra_win_get_window (BRA_WIN_ID_PUSH_MSG_LIST_DLG));
        if (win && (idx=bra_psl_find_msg_index(&(selected_msg_item->handle)))!=-1)
        {
          bra_psl_construct_msg_list_item(selected_msg_item, &ms, &imgResID);
          MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, idx, ms,  0, HDIa_widgetImageGetPredefined(imgResID,0), 0, FALSE); 
          MSF_WIDGET_RELEASE(ms);
        }

        bra_psl_unread_check();
      }
    }
  } else {
    bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_MSG_DELETED, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
    
    if (!bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG) &&
        !bra_win_get_window(BRA_WIN_ID_INSE) &&
        !bra_win_get_window(BRA_WIN_ID_OPT) &&
        bra_win_get_window(BRA_WIN_ID_VIEWPORT) &&
        !bra_view_if_has_viewable_page())
      bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_VIEWPORT);
    
    if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG))
      bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG);
  }

  bra_psl_free_full_msg(&((uis_reply_full_msg_t*)p)->msg);
}

static void
bra_psl_destroy_ui(MsfActionType response)
{
  if (response == MsfOk)
	   bra_destroy_ui();
}

void
bra_psl_reply_delete_msg (void *p)
{
  //extern void uis_msg_store_writeIndexFiles (void);
  uis_reply_delete_msg_t *msg;
  MSF_BOOL user_delete = FALSE;

  msg = (uis_reply_delete_msg_t*)p;

#ifdef __UNIFIED_MSG_SUPPORT__
  if(msg->transactionId == 1) /* delete oldest message completely, prepare to send new message indication to unified message MMI */
  {
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
      if (!bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
      {
        UISif_getMsgList(MSF_MODID_BRA, 8, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
      }
  }
  else if(msg->transactionId == 2) /* UM: delete push inbox */
  {
    if(msg->handle.handle)
      BRA_FREE(msg->handle.handle);

    if(bra_msg_list)
    {
      /* UM: continue to delete */
      bra_psl_list_item_t *msg_item = bra_msg_list;
      UISif_deleteMsg(MSF_MODID_BRA, 2, msg_item->uis_msg_type, &(msg_item->handle));
      bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
    }
    else
    {
      bra_psl_cancel_push_indicator();
      wap_um_del_push_msg_inbox_rsp();
    }
    return;
  }
  else if(msg->transactionId == 3) /* UM: delete all push message while viewing push message */
  {
    if(msg->handle.handle)
      BRA_FREE(msg->handle.handle);

    if(bra_msg_list)
    {
      /* UM: continue to delete */
      bra_psl_list_item_t *msg_item = bra_msg_list;
      UISif_deleteMsg(MSF_MODID_BRA, 3, msg_item->uis_msg_type, &(msg_item->handle));
      bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
    }
    else
    {
      bra_cmn_deleted_dialog();
    }
    return;    
  }
#endif  

  if(deleted_msg_item.handle.handle != NULL
     && msg->handle.handle != NULL
     && deleted_msg_item.handle.handleLen == msg->handle.handleLen    
     && memcmp(deleted_msg_item.handle.handle, msg->handle.handle, msg->handle.handleLen) == 0)
  {
    user_delete = TRUE;
    /*BRA_FREE(deleted_msg_item.handle.handle);
    deleted_msg_item.handle.handle = NULL;*/
  }

  /* commit delete to store */
  //uis_msg_store_writeIndexFiles();
  if(!bra_msg_list && bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG)) //Jo
  {
    /* close msg list window */
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    bra_psl_cancel_push_indicator();
    /* No msg exists, give a 3 second notification */
    if(!bra_win_get_window(BRA_WIN_ID_INSE) 
        && !bra_win_get_window(BRA_WIN_ID_OPT) 
        && !bra_view_if_has_viewable_page())
    {
      bra_psl_destroy_ui(MsfOk);
      //HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);      
      bra_cmn_deleted_dialog();
   }
	else
    {
      //HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
      bra_cmn_deleted_dialog();
    }
  }
  else if(delete_all == TRUE)
  {
    bra_psl_list_item_t *msg_item = bra_msg_list;
    BRA_FREE(deleted_msg_item.handle.handle);
    deleted_msg_item = *msg_item;
    deleted_msg_item.handle.handle = BRA_ALLOC(msg_item->handle.handleLen);
    memcpy(deleted_msg_item.handle.handle, msg_item->handle.handle, msg_item->handle.handleLen);
    UISif_deleteMsg(MSF_MODID_BRA, 0, msg_item->uis_msg_type, &(msg_item->handle));
    bra_psl_list_delete_msg(msg_item->uis_msg_type, &(msg_item->handle));
  }
  else if(user_delete == TRUE)
  {
    bra_cmn_deleted_dialog();
    bra_psl_cancel_push_indicator();
    bra_psl_unread_check();
  }
  
  if(msg->handle.handle)
    BRA_FREE(msg->handle.handle);
}

void
bra_psl_reply_change_msg (void *p)
{
  //extern void uis_msg_store_writeIndexFiles (void);
  uis_reply_change_msg_t *msg;

  msg = (uis_reply_change_msg_t*)p;

  /* commit delete to store */
  //uis_msg_store_writeIndexFiles();
  if(msg->handle.handle)
    BRA_FREE(msg->handle.handle);
}

void 
bra_psl_delete_oldest_msg(void)
{
    bra_psl_list_item_t *msg_item =bra_msg_list;
    if (msg_item)
    {
        bra_psl_msg_list_menu_t *win = (bra_psl_msg_list_menu_t *)(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG));

        while (msg_item->next)
            msg_item = msg_item->next;
              
        UISif_deleteMsg(MSF_MODID_BRA, 1, msg_item->uis_msg_type, &msg_item->handle);
        //Jo mem leak
        bra_psl_list_delete_msg(msg_item->uis_msg_type, &msg_item->handle);
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, PUSH_MAX_NO_OF_MSG);
     }
     else
        UISif_getMsgList(MSF_MODID_BRA, 1, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}


//Jo bootup push indicator
void
bra_psl_reply_nbr_of_msg (void *p)
{
  uis_reply_nbr_of_msgs_t* msgs;
  uis_key_value_t          read;
  MSF_BOOL                 bool_read = FALSE; 

  
  if (p == NULL)
	return;

  msgs = (uis_reply_nbr_of_msgs_t*) p;

  read.key       = UIS_MSG_KEY_READ;
  read.valueLen  = sizeof(MSF_BOOL);
  read.valueType = UIS_VALUE_TYPE_BOOL;
  read.value     = (unsigned char *)&bool_read;

  //Jo maximum nbr of push msgs
  if (msgs->transactionId==1)
  {
     if (msgs->msgType==UIS_MSG_TYPE_PUSH_SL)
     {
        TotalNoOfPushMessages=msgs->nbrOfMsgs;
        UISif_getNbrOfMsgs(MSF_MODID_BRA,
			   1,
			   UIS_MSG_TYPE_PUSH_SI,
			   0,
			   NULL);
     }
     else
     {
        TotalNoOfPushMessages+=msgs->nbrOfMsgs;
        if (TotalNoOfPushMessages > PUSH_MAX_NO_OF_MSG)
        {
        	bra_psl_delete_oldest_msg();
        }
#ifdef __UNIFIED_MSG_SUPPORT__
        else
        {
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
            if (!bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
            {
             UISif_getMsgList(MSF_MODID_BRA, 8, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
            }
        }
#endif
     }
     return;
  }

  if (msgs->nbrOfMsgs > 0)
  {
#ifdef BRA_CFG_DUAL_SIM
    if (bra_sim_get_sim_card_number() != BRA_SIM_ID_NO_SIM && 
        bra_sim_get_setting_mode() != BRA_SIM_ID_FLIGHT_MODE)
#endif /* BRA_CFG_DUAL_SIM */
     {
       bra_psl_set_push_indicator();
     }
  }
  else if (msgs->msgType==UIS_MSG_TYPE_PUSH_SL)
	UISif_getNbrOfMsgs(MSF_MODID_BRA,
			   0,
			   UIS_MSG_TYPE_PUSH_SI,
			   1,
			   &read);
  else if (msgs->msgType==UIS_MSG_TYPE_PUSH_SI)
    bra_psl_cancel_push_indicator();

  return;
}

void
bra_psl_create_push_inbox (void)
{
  /* get push SL MsgList first */
  if (bra_psl_uis_state == 1)
    UISif_getMsgList(MSF_MODID_BRA, 0, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
  //HDIa_widgetExtClearPush();
}

static void
bra_psl_read_new_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    if(!bra_win_get_window(BRA_WIN_ID_INSE) 
       && !bra_win_get_window(BRA_WIN_ID_OPT)
       && !bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
#ifdef BRA_CFG_DUAL_SIM
      bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif
      bra_create_ui(BRA_UI_VIEWPORT);  
    }
    bra_view_disable();         
    read_from_idle = 1;
    bra_psl_view (new_msg_item.msgType, &(new_msg_item.msg.handle));
    /* create and initiate new item */
    selected_msg_item = BRA_ALLOCTYPE(bra_psl_list_item_t);
    selected_msg_item->text.value   = NULL;
    selected_msg_item->time.value   = NULL;
    selected_msg_item->url.value    = NULL;
    selected_msg_item->address.value    = NULL;
    selected_msg_item->uis_msg_type = new_msg_item.msgType;
    /* copy handle*/
    memcpy(&selected_msg_item->handle, &(new_msg_item.msg.handle), sizeof(uis_msg_handle_t));
    selected_msg_item->handle.handle = BRA_ALLOC(new_msg_item.msg.handle.handleLen);
    memcpy(selected_msg_item->handle.handle, new_msg_item.msg.handle.handle, new_msg_item.msg.handle.handleLen);
  }
  BRA_FREE(new_msg_item.msg.handle.handle);
  new_msg_item.msg.handle.handle = NULL;
  new_msg_priority = -1;
}

/* return value: whether removed*/
static int bra_psl_remove_high_msg_item(bra_psl_list_item_t **pMsgList, uis_msg_handle_t msgHandle)
{
    bra_psl_list_item_t *pList = *pMsgList;
    bra_psl_list_item_t *pPrev = *pMsgList;
    
    while (pList)
    {
        if (msf_cmmn_strncmp_nc(
            (const char*)pList->handle.handle, 
            (const char*)msgHandle.handle, 
            msgHandle.handleLen) == 0)
        {
            if (pList == *pMsgList)
            {
                *pMsgList = (*pMsgList)->next;
            }
            else
            {
                pPrev->next = pList->next;
            }
            if (pList->url.value)
                BRA_FREE(pList->url.value);
            BRA_FREE(pList->handle.handle);
            pList->handle.handle = NULL;
            BRA_FREE(pList);
            pList = NULL;
            return 1;
        }
        pPrev = pList;
        pList = pList->next;
    }
    return 0;
}


#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
static void bra_psl_remove_all_high_msg_item(bra_psl_list_item_t *pMsgList)
{
    bra_psl_list_item_t *pList;

    while (pMsgList)
    {
        pList = pMsgList;
        pMsgList = pMsgList->next;

        if (pList->url.value)
            BRA_FREE(pList->url.value);
        BRA_FREE(pList->handle.handle);
        pList->handle.handle = NULL;
        BRA_FREE(pList);
        pList = NULL;
    }
}
#endif


void bra_psl_add_high_msg_item(bra_psl_list_item_t **pMsgList, uis_msg_handle_t msgHandle, MSF_UINT8 type, char *url)
{
    bra_psl_list_item_t *pList;
    bra_psl_list_item_t *pPrev;

    pList = BRA_ALLOCTYPE(bra_psl_list_item_t);
    pList->handle.handle = BRA_ALLOC(msgHandle.handleLen);
    memcpy(pList->handle.handle, msgHandle.handle, msgHandle.handleLen);
    pList->handle.handleLen = msgHandle.handleLen;
    if(url)
    {
      pList->url.value = BRA_ALLOC(strlen(url) + 1);
      strcpy((char *)pList->url.value, url);
    }
    else
    {
      pList->url.value = NULL;
    }
    pList->uis_msg_type = type;
    pList->next = NULL;
    
    pPrev = *pMsgList;
    if (pPrev)
    {
        while(pPrev->next != NULL)
        {
            pPrev = pPrev->next;
        }
        pPrev->next = pList;
    }
    else
    {
        *pMsgList = pList;
    }
}

void 
bra_psl_notification_handler(void)
{
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_NEW_PUSH_MSG, 
                          BRA_STR_READ, //BRA_STR_OK, 
                          BRA_STR_BACK,//BRA_STR_CANCEL,
                          0, 
                          bra_psl_read_new_confirmation);
}

void bra_psl_SLhigh_notification_handler(void)
{
    uis_full_msg_t        fullMsg;
    uis_key_value_t       key;
    MSF_BOOL              keyValue;

    HDIa_widgetExtClearUrgentServiceLoading();

    /* load the page */
    if (!bra_msg_new_hiSL_list)
        return;

    if (bra_msg_new_hiSL_list->url.value)
    {
        BRAif_createUI(BRA_UI_GOTO_URL, (char *)bra_msg_new_hiSL_list->url.value);
    }
    read_from_idle = 1;

    /* mark read */
    keyValue      = TRUE;
    key.key       = UIS_MSG_KEY_READ;
    key.valueLen  = sizeof(MSF_BOOL);
    key.valueType = UIS_VALUE_TYPE_BOOL;
    key.value     = (unsigned char *)&keyValue;
    memset(&fullMsg, 0, sizeof(uis_full_msg_t));
    fullMsg.handle = bra_msg_new_hiSL_list->handle;
    fullMsg.propertyListSize = 1;
    fullMsg.propertyList = &key;
    
    UISif_changeMsg(MSF_MODID_BRA, 0, bra_msg_new_hiSL_list->uis_msg_type,
        TRUE, FALSE, FALSE, &fullMsg);

    /* remove from list */
    bra_psl_remove_high_msg_item(&bra_msg_new_hiSL_list, bra_msg_new_hiSL_list->handle);

    /* check other SL high message */
    if (bra_msg_new_hiSL_list)
    {
        HDIa_widgetExtRegisterUrgentServiceLoading(FALSE);
    }
    else
    {
        HDIa_widgetExtClearUrgentServiceLoading();
    }

    /* check unread */
    bra_psl_unread_check();
}

void bra_psl_SIhigh_notification_handler(void)
{
    HDIa_widgetExtClearUrgentServiceIndication();

    if (!bra_msg_new_hiSI_list)
        return;

    selected_msg_item = BRA_ALLOCTYPE(bra_psl_list_item_t);
    selected_msg_item->text.value   = NULL;
    selected_msg_item->time.value   = NULL;
    selected_msg_item->url.value    = NULL;
    selected_msg_item->address.value    = NULL;
    selected_msg_item->uis_msg_type = bra_msg_new_hiSI_list->uis_msg_type;

    memcpy(&selected_msg_item->handle, &bra_msg_new_hiSI_list->handle, sizeof(uis_msg_handle_t));
    selected_msg_item->handle.handle = BRA_ALLOC(bra_msg_new_hiSI_list->handle.handleLen);
    memcpy(selected_msg_item->handle.handle, bra_msg_new_hiSI_list->handle.handle, bra_msg_new_hiSI_list->handle.handleLen);

    if(!bra_win_get_window(BRA_WIN_ID_INSE) 
        && !bra_win_get_window(BRA_WIN_ID_OPT)
        && !bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
#ifdef BRA_CFG_DUAL_SIM
        bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif
        bra_create_ui(BRA_UI_VIEWPORT);  
    }
    bra_view_disable();
    read_from_idle = 1;

    if (bra_msg_new_hiSI_list->next)
    {
        HDIa_widgetExtRegisterUrgentServiceIndication(FALSE);
    }

    bra_psl_view (bra_msg_new_hiSI_list->uis_msg_type, &(bra_msg_new_hiSI_list->handle));
}

void bra_psl_msg_replaced_dlg_resp(MsfActionType response)
{
  if (!read_from_idle)
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_PUSH_MSG_LIST_DLG);
  else
  {
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PUSH_MSG_DLG);
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PUSH_MSG_OPT_DLG);
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG);
    bra_psl_create_push_inbox();
  }
}

void 
bra_psl_new_msg_notification (void *p)
{
  uis_notify_new_msg_t* msg = (uis_notify_new_msg_t*) p;
  MSF_UINT32       priority;
  char            *url = NULL;
  bra_psl_msg_list_menu_t *win;
  MsfStringHandle ms;
  MSF_BOOL no_free_space = bra_psl_no_free_space();
  int                       push_SL_setting;
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
  unsigned int              time = 0;
#endif
  int                       IsHigh = 0;

  if (no_free_space)
  {
#ifdef __UNIFIED_MSG_SUPPORT__
    HDIa_widgetExtRegisterSystemMsg(MSF_MODID_BRA, BRA_STR_ID_PUSH_UM_INBOX, 
        MEA_STR_ID_STORAGE_FULL);
#else
    HDIa_widgetExtRegisterSystemMsg(MSF_MODID_BRA, BRA_STR_ID_PUSH_INBOX, 
        MEA_STR_ID_STORAGE_FULL);
#endif
    UISif_deleteMsg (MSF_MODID_BRA,
                         0,
                         msg->msgType,
                         &msg->msg.handle);
    goto done;
  }

  if (!bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_ON))
  {
    UISif_deleteMsg (MSF_MODID_BRA,
                         0,
                         msg->msgType,
                         &msg->msg.handle);
    goto done;
  }

  if (msg->msg.titleListSize > 0) {
    if (msf_psl_extract_keys (msg->msg.titleList, 
                              msg->msg.titleListSize, 
                              &priority, 
                              &url) == TRUE)
      {
        if (msg->msgType == UIS_MSG_TYPE_PUSH_SL)
        {  
          if (bra_psl_load (priority, url) == TRUE){
            UISif_deleteMsg (MSF_MODID_BRA,
                             0,
                             msg->msgType,
                             &msg->msg.handle);
            goto done;
        }
      }
        new_msg_priority = priority;
      }
  }

  //Jo maximum nbr of push msgs
  UISif_getNbrOfMsgs(MSF_MODID_BRA,
			   1,
			   UIS_MSG_TYPE_PUSH_SL,
			   0,
			   NULL);

  /* commit new push message to store */
  //uis_msg_store_writeIndexFiles();

  if (p == NULL)
    return;

  MSF_TIMER_RESET (MSF_MODID_BRA, BRA_INBOX_REFRESH_TIMER_ID);

#ifdef BRA_CFG_DUAL_SIM
  if (bra_sim_get_sim_card_number() != BRA_SIM_ID_NO_SIM && 
      bra_sim_get_setting_mode() != BRA_SIM_ID_FLIGHT_MODE)
#endif /* BRA_CFG_DUAL_SIM */
  {
    bra_psl_set_push_indicator(); //Jo push indicator
  }
  
  //MSF_WIDGET_SOUND_PLAY_PREDEFINED(MsfSound_1);

  //msg = (uis_notify_new_msg_t*) p;

  push_SL_setting = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_PUSH_SLSETTING);

  if (msg->msgType == UIS_MSG_TYPE_PUSH_SL)
  {
      /* replace duplicate */
      bra_psl_remove_high_msg_item(&bra_msg_new_hiSL_list, msg->msg.handle);
      if (!bra_msg_new_hiSL_list)
      {
          HDIa_widgetExtClearUrgentServiceLoading();
      }

      if (push_SL_setting == 2 && 
          priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH) /*without confirm*/
      {
          /* add new */
          bra_psl_add_high_msg_item(&bra_msg_new_hiSL_list, msg->msg.handle, msg->msgType, url);
          IsHigh = 1;
      }
  }
  if (msg->msgType == UIS_MSG_TYPE_PUSH_SI)
  {
      /* replace duplicate */
      bra_psl_remove_high_msg_item(&bra_msg_new_hiSI_list, msg->msg.handle);
      if (!bra_msg_new_hiSI_list)
      {
          HDIa_widgetExtClearUrgentServiceIndication();
      }

      if(priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH)
      {
          /* add new */
          bra_psl_add_high_msg_item(&bra_msg_new_hiSI_list, msg->msg.handle, msg->msgType, NULL);
          IsHigh = 1;
      }
  }

#ifdef __UNIFIED_MSG_SUPPORT__
  /* UM: prepare to send new push message notification to MMI */
  BRA_FREE(new_msg_item.msg.handle.handle);
  new_msg_item = *msg;
  new_msg_item.msg.handle.handle = BRA_ALLOC(msg->msg.handle.handleLen);
  memcpy(new_msg_item.msg.handle.handle, msg->msg.handle.handle, msg->msg.handle.handleLen);
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
  if (!bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG))
  {
          goto done;
  }
#else
          goto done;
#endif /* BRA_CONFIG_DOUBLE_PUSH_BOX */
#endif /* __UNIFIED_MSG_SUPPORT__ */

  ms = bra_dlg_top_dialog_text();
  if (IsHigh == 0 && (msg->msgType == UIS_MSG_TYPE_PUSH_SL || msg->msgType == UIS_MSG_TYPE_PUSH_SI))
  {
    //HDIa_widgetExtRegisterNewPush();
    if(!ms || ms != BRA_STR_NEW_PUSH_MSG)
    {      
      //if(bra_win_current_window() == BRA_WIN_ID_PUSH_MSG_LIST_DLG)
        //HDIa_widgetExtClearPush();
      //else
      if (bra_win_current_window() != BRA_WIN_ID_PUSH_MSG_LIST_DLG)
      {
        BRA_FREE(new_msg_item.msg.handle.handle);
        new_msg_item = *msg;
        new_msg_item.msg.handle.handle = BRA_ALLOC(msg->msg.handle.handleLen);
        memcpy(new_msg_item.msg.handle.handle, msg->msg.handle.handle, msg->msg.handle.handleLen);
      }
    }
    else 
    {
      //HDIa_widgetExtClearPush();    	
      BRA_FREE(new_msg_item.msg.handle.handle);
      new_msg_item = *msg;
      new_msg_item.msg.handle.handle = BRA_ALLOC(msg->msg.handle.handleLen);
      memcpy(new_msg_item.msg.handle.handle, msg->msg.handle.handle, msg->msg.handle.handleLen);
    }
  }

  /*Update */
  win = (bra_psl_msg_list_menu_t *)(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG));
  if (win != 0)
  {
    uis_msg_handle_t hdl;
    int add_msg_idx, dup_msg_idx;
    MsfStringHandle ms;
    MSF_UINT32 imgResID;

    bra_psl_process_pdn_list();/* to avoid send the same handle message deleted just now*/

    hdl.handleLen  = msg->msg.handle.handleLen;
    hdl.handle = BRA_ALLOC(msg->msg.handle.handleLen);
    memcpy(hdl.handle, msg->msg.handle.handle, hdl.handleLen);

    add_msg_idx = bra_psl_list_add_new_msg(msg->msgType, &msg->msg);
    bra_psl_construct_msg_list_item(bra_msg_list, &ms, &imgResID);
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 0, ms,  0, HDIa_widgetImageGetPredefined(imgResID,0), 0, TRUE); 
    MSF_WIDGET_RELEASE(ms);

    //int add_msg_idx = bra_psl_list_add_msg(msg->msgType, &msg->msg);
    //bra_psl_list_add_msg(msg->msgType, &msg->msg);

    //if (!allowInterrupt)
    //    updateUI = TRUE;

    if ((dup_msg_idx=bra_psl_list_delete_duplicate_msg(add_msg_idx)) != -1)
    {
        int crtWinID = bra_win_current_window();
    	//MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, add_msg_idx+2);
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, dup_msg_idx);

        bra_psl_pdn_delete(&hdl);
        if(!selected_msg_item &&
           (crtWinID == BRA_WIN_ID_PUSH_MSG_OPT_DLG ||
           crtWinID == BRA_WIN_ID_PUSH_MSG_DLG ||
           crtWinID == BRA_WIN_ID_PUSH_MSG_LIST_OPT_DLG))
        {
            bra_dlg_create_dlg (MsfWarning,
                                BRA_STR_MSG_REPLACED, 
                                BRA_STR_OK, 
                                0,
                                0, 
                                bra_psl_msg_replaced_dlg_resp);
            goto done;
        }
    }
    //bra_psl_update_list_menu();
    BRA_FREE(hdl.handle);
  }
  else if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG) &&
           IsHigh == 0 &&
           selected_msg_item->handle.handleLen == new_msg_item.msg.handle.handleLen &&
           memcmp(selected_msg_item->handle.handle, new_msg_item.msg.handle.handle, selected_msg_item->handle.handleLen)==0)
  {
    bra_dlg_create_dlg (MsfWarning,
                        BRA_STR_MSG_REPLACED, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        bra_psl_msg_replaced_dlg_resp);
    /*if (priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH)
    {
      bra_psl_remove_high_msg_item(&bra_msg_new_hiSI_list, msg->msg.handle);
    }*/
    goto done;
  }
  else if (bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG) &&
           IsHigh == 1 &&
           selected_msg_item->handle.handleLen == msg->msg.handle.handleLen &&
           memcmp(selected_msg_item->handle.handle, msg->msg.handle.handle, selected_msg_item->handle.handleLen)==0)
  {
    bra_dlg_create_dlg (MsfWarning,
                        BRA_STR_MSG_REPLACED, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        bra_psl_msg_replaced_dlg_resp);
    /*if (priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH)
    {
      bra_psl_remove_high_msg_item(&bra_msg_new_hiSI_list, msg->msg.handle);
    }*/
    goto done;
  }

  if (msg->msgType == UIS_MSG_TYPE_PUSH_SI && priority == UIS_MSG_KEY_VALUE_PRIORITY_LOW)
  {
    win = (bra_psl_msg_list_menu_t *)(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG));
    if (win != 0)
    {
        widget_paint();
/*        bra_win_enable_focus();*/
    }
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
    wap_um_refresh_push_inbox_ind();
#endif
  }
  else if ((msg->msgType == UIS_MSG_TYPE_PUSH_SL &&
            push_SL_setting == 2 && 
            priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH) || /*without confirm*/
           (msg->msgType == UIS_MSG_TYPE_PUSH_SI &&
            priority == UIS_MSG_KEY_VALUE_PRIORITY_HIGH))
  {
      if (msg->msgType == UIS_MSG_TYPE_PUSH_SL && bra_msg_new_hiSL_list)
      {
          HDIa_widgetExtRegisterUrgentServiceLoading(TRUE);
      }
      else if (bra_msg_new_hiSI_list)
      {
          HDIa_widgetExtRegisterUrgentServiceIndication(TRUE);
      }

      win = (bra_psl_msg_list_menu_t *)(bra_win_get_window(BRA_WIN_ID_PUSH_MSG_LIST_DLG));
      if (win != 0)
      {
          /*bra_win_enable_focus();*/
      }
      
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
      wap_um_refresh_push_inbox_ind();
#endif
  }
  else
  {
      HDIa_widgetExtRegisterNewPush();
      if (bra_win_current_window()==BRA_WIN_ID_PUSH_MSG_LIST_DLG || ms==BRA_STR_NEW_PUSH_MSG)
        HDIa_widgetExtClearPush();
#ifdef BRA_CONFIG_DOUBLE_PUSH_BOX
      if (bra_win_current_window() != BRA_WIN_ID_PUSH_MSG_LIST_DLG)
      {
          time = (unsigned int)((*((MSF_UINT32*)bra_msg_list->time.value))/*+(MSF_TIME_GET_TIME_ZONE()*60)*/);
          wap_um_new_push_msg_ind(0, time);
      }
#endif
  }

done:    
  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, UIS_SIG_NOTIFY_NEW_MSG, p);
  BRA_FREE (url);
}

#endif /* WAP_SUPPORT */

/************************************************************
 * Psl Menu Functions
 ************************************************************/
#endif /*BRA_CONFIG_UIS_PUSH_SL specific*/

#ifdef BRA_CONFIG_PUSH

typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_psl_menu_t;

static void
bra_psl_delete_menu (bra_win_t *win)
{
  bra_psl_menu_t *p;
  p = (bra_psl_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

}

#ifdef BRA_CONFIG_UIS_PUSH_SL
static void
bra_psl_sl_settings_response (int selected)
{
  if (selected >= 0)
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_LOAD_SL, selected, NULL);
}
#endif

static void
bra_psl_security_response (int selected)
{
  if (selected >= 0)
    bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PUSH_SECURITY, selected, NULL);
}

static void
bra_psl_action_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  int i = 0;
  bra_psl_menu_t *p;
#ifdef BRA_CONFIG_UIS_PUSH_SL                                                                  
  static const int psl_sl_choice_list[3]  =  {BRA_STR_ID_NEVER,         /* Never       */
                                              BRA_STR_ID_IF_SAME_HOST , /* If same host*/
                                              BRA_STR_ID_ALWAYS};       /* Always      */
#endif
  static const int psl_sec_choice_list[4] = { BRA_STR_ID_PUSH_LOAD_ALWAYS, /* Accept always*/
                                              BRA_STR_ID_PUSH_LOAD_AUTH,   /* Thrusted*/
                                              BRA_STR_ID_PUSH_LOAD_NON_WAP,/* Non wap*/
                                              BRA_STR_ID_PUSH_LOAD_NEVER}; /* never */

  p = (bra_psl_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
#ifdef BRA_CONFIG_UIS_PUSH_SL                                                                  
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      if (bra_prof_is_profile_loaded (0) == 0)
      {
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_ERR_SELECT_PROFILE, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;
      }

      bra_dlg_create_opt_menu (BRA_STR_PUSH_LOAD_SL, 
                               3, 
                               psl_sl_choice_list,
                               bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_LOAD_SL),
                               bra_psl_sl_settings_response);
    }
    else
#endif
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      if (bra_prof_is_profile_loaded (0) == 0)
      {
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_ERR_SELECT_PROFILE, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;
      }
      bra_dlg_create_opt_menu (BRA_STR_PUSH_SECURITY, 
                               4, 
                               psl_sec_choice_list,
                               bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PUSH_SECURITY),
                               bra_psl_security_response);

    }
  }
}

/*
 * Creates the Push Settings menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_psl_create_settings_menu (void)
{
  bra_psl_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  int i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_psl_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                         BRA_STR_ACCEPT,
                                         MsfSelect,
                                         1, 
                                         0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                       BRA_STR_BACK,
                                       MsfBack,
                                       1, 
                                       0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
												               &prop.displaySize,
												               win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);
#ifdef BRA_CONFIG_UIS_PUSH_SL                                                                  
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_PUSH_SL_SETTINGS, 0, 0, 0, TRUE);
#endif
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_PUSH_SECURITY, 0, 0, 0, TRUE);

	MSF_WIDGET_SET_TITLE (win->window,BRA_STR_PUSH_SETTINGS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_PUSH_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_psl_delete_menu, 
                    NULL,
                    bra_psl_action_menu);
}

#ifdef __UNIFIED_MSG_SUPPORT__
/* UM: get push message number */
void
bra_psl_get_push_msg_num (void)
{
    UISif_getMsgList(MSF_MODID_BRA, 2, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}

/* UM: get push message list */
void
bra_psl_get_push_msg_list (void *p)
{
    bra_get_push_msg_list_t *push_msg_list = (bra_get_push_msg_list_t*)p;       
    startFromMsg = push_msg_list->startFromMsg;
    UISif_getMsgList(MSF_MODID_BRA, 3, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}

/* UM: get push message info */
void
bra_psl_get_push_msg_info (void *p)
{
    bra_get_push_msg_info_t *push_msg_info = (bra_get_push_msg_info_t*)p;       
    startFromMsg = push_msg_info->startFromMsg;
    numberOfMsg = push_msg_info->numberOfMsg;
    UISif_getMsgList(MSF_MODID_BRA, 4, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}

/* UM: delete push inbox */
void
bra_psl_del_push_msg_inbox (void)
{
    UISif_getMsgList(MSF_MODID_BRA, 5, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}

/* UM: view push message */
void
bra_psl_view_push_msg (void *p)
{
    bra_view_push_msg_t *push_msg = (bra_view_push_msg_t*)p;       
    msgIndex = push_msg->msgIndex;
    UISif_getMsgList(MSF_MODID_BRA, 6, UIS_MSG_TYPE_PUSH_SL, 0, NULL, 0);
}
#endif

#endif



static void
bra_psl_goto_url(char *url)
{
#ifdef BRA_CFG_DUAL_SIM
  int   need_ask;


  need_ask = bra_sim_is_need_to_ask();

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_PSL_GOTO_URL, "BRA: bra_psl_goto_url: ask=%d", need_ask));

  /* if need to ask and already not ask  */
  if (need_ask)
  {
    BRAif_createUI(BRA_UI_GOTO_URL, (const char*)url);
    return;
  }
  bra_sim_set_widget_sim_icon(bra_sim_get_bra_sim_id_in_active_use());
#endif /* BRA_CFG_DUAL_SIM */

  bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
  bra_send_request (url);
}





