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
 * bra_opt.c
 *
 * Description:
 *		This file contains code to make requests and receive replies.
 *
 */
#include "bra_cfg.h"
#include "bra_cmn.h"
#include "bra_view.h"
#include "bra_str.h"
#include "bra_sig.h"
#include "bra_win.h"
#include "bra_opt.h"
#include "bra_main.h"
#include "bra_req.h"
#include "bra_set.h"
#ifdef BRA_CONFIG_SECURITY
#include "bra_sec.h"
#include "bra_inse.h"
#include "msf_env.h"
#endif
#include "bra_bkm.h"
#include "bra_dlg.h"
#include "bra_sif.h"
#include "bra_rpl.h"
#include "bra_act.h"
#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif

#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif

#include "brs_if.h"

#include "msf_int.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#include "msf_file.h"
/*#include "msf_chrt.h"*/
#include "msf_url.h"
#include "wapadp.h"
#include "widget.h"

#include "sec_if.h"

#include "GlobalConstants.h"

#include "DLAgentResDef.h"

/************************************************************
 * Local Types
 ************************************************************/

/* options menu */
typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_opt_menu_t;

typedef struct {
  int enabled;
#ifdef BRA_CONFIG_MMS
  int send_content;
#endif
  char *url;
  msf_content_data_t cd;

}bra_opt_save_as_t;

/*****************************************************************************
* Function prototypes
*****************************************************************************/

extern void wap_enter_sms_editor_handler(void *p);
extern pBOOL mmi_bootup_is_sim_valid(void);
/*extern void widget_execute_MMI_p(func_ptr func, void *arg, kal_bool is_blocking);*/

/************************************************************
 * Global Variables
 ************************************************************/

static brs_do_elements_t *bra_opt_do_elements;
static bra_opt_save_as_t bra_opt_save_as; 

static MSF_UINT8         bra_opt_link;
static MSF_UINT8         bra_opt_edit;
static MSF_UINT8         bra_opt_reset;
static MSF_UINT8         bra_opt_choose;
static MSF_UINT8         bra_goto;
static MSF_UINT8         bra_is_busy = 0;
static int               n_do_element = 0;
// tmp workaround, prevent futher BRSif_saveAs because it won't  close file
int					bra_save_as_persistent_error_msgid = 0; 

static MSF_BOOL          show_download;

/************************************************************
 * Function definitions
 ************************************************************/
/*
 * Initalizes variables used in this file
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_opt_init (void)
{
  bra_opt_do_elements = NULL;
  
  bra_opt_save_as.enabled = 0;
  bra_opt_save_as.url     = NULL;
#ifdef BRA_CONFIG_MMS
  bra_opt_save_as.send_content  = FALSE;
#endif
  
  bra_opt_link = FALSE;  
  bra_opt_edit = FALSE;
  bra_opt_reset = FALSE;
  bra_opt_choose = FALSE;
}

/*
 * Called from external signal receive function with the current
 * Do-Element as argument. the pointer is saved as is and must not
 * be destroyed when the function returns.
 *
 * PARAMETERS
 *
 * p         : void pinter to Do-Element struct (brs_do_elements_t) 
 *
 * RETURN    : void
 */
void
bra_opt_set_do_elements (void *p)
{
  if (bra_opt_do_elements != NULL)
    MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, BRS_SIG_DO_ELEMENTS, bra_opt_do_elements);

  bra_opt_do_elements = (brs_do_elements_t *)p;

  if(bra_win_get_window(BRA_WIN_ID_OPT))
    bra_win_close_window (BRA_WIN_CLOSE_ID, BRA_WIN_ID_OPT);
}

/*
 * Free currently set Do-Elements struct 
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_opt_remove_do_elements (void)
{
  if (bra_opt_do_elements == NULL)
    return;

  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, BRS_SIG_DO_ELEMENTS, bra_opt_do_elements);

  bra_opt_do_elements = NULL;
}

void
bra_opt_disable_link (void)
{
   bra_opt_link = FALSE;
}

void
bra_opt_enable_link (void)
{
   bra_opt_link = TRUE;
}

void
bra_opt_disable_edit (void)
{
   bra_opt_edit = FALSE;
}

void
bra_opt_enable_edit (void)
{
   bra_opt_edit = TRUE;
}

void
bra_opt_disable_reset (void)
{
   bra_opt_reset = FALSE;
}

void
bra_opt_enable_reset (void)
{
   bra_opt_reset = TRUE;
}

void
bra_opt_disable_choose (void)
{
   bra_opt_choose = FALSE;
}

void
bra_opt_enable_choose (void)
{
   bra_opt_choose = TRUE;
}

static void bra_opt_update_items(bra_opt_menu_t *win);

void
bra_opt_remove_download_item(void)
{
    if (show_download == 1 && bra_get_da_download_job_count() == 0)
    {
        while (MSF_WIDGET_CHOICE_REMOVE_ELEMENT(((bra_opt_menu_t*)bra_win_get_window(BRA_WIN_ID_OPT))->windowHandle, 0) == 1)
            ;

        bra_opt_update_items((bra_opt_menu_t*)bra_win_get_window(BRA_WIN_ID_OPT));
    }
}
/************************************************************
 * Options menu Functions 
 ************************************************************/
#ifdef BRA_USE_CTK_INLINE

static int
bra_opt_url_response (char *url)
{
  extern void msm_compute_checksum_critical_file_by_index(int idx);
  
  /*Not both the title and url can be null att the same time*/
  if(url == NULL || (*url == '\0'))
    return 0;

  bra_cmn_set_local_hompage_url (url); 
  
  bra_cmn_set_homepage ("", url);

  /* unload profile and save the checksum */
  msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);

  bra_cmn_saved_dialog();

  return 1;
}

#else

static int
bra_opt_title_url_response (char *title, char *url)
{

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;

  if (*title != '\0')
    bra_cmn_set_local_hompage_title (BRA_STRCONV (title));/*OK*/
  else
    bra_cmn_set_local_hompage_title (BRA_STRCONV (url));/*OK*/

  bra_cmn_set_local_hompage_url (url); 
  
  bra_cmn_set_homepage (title, url);

  return 1;
}

#endif

static void bra_opt_delete_current_url_view(bra_win_t *win)
{
  MSF_WIDGET_REMOVE (bra_win_get_screen (), win->win_hdl); 

  MSF_WIDGET_RELEASE (win->win_hdl); 

  BRA_FREE (win);
}


static void bra_opt_current_url_view_back(ctk_screen_handle scrid)
{
  CTK_UNUSED(scrid);
  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
}


static void
bra_opt_current_url_view_delete_send_url (bra_win_t *win)
{
    bra_opt_menu_t *p;
    p = (bra_opt_menu_t *)(win);
    
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 
    
    MSF_WIDGET_RELEASE (p->windowHandle); 
    MSF_WIDGET_RELEASE (p->selectActionHandle);
    MSF_WIDGET_RELEASE (p->backActionHandle);
    
    BRA_FREE (p);
}


static void
bra_opt_current_url_view_action_send_url(bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_opt_menu_t  *p;
    bra_cmn_addr_t  *addr;

    p = (bra_opt_menu_t *)(win);
    addr = bra_cmn_get_current_page ();

    if (bra_action == p->backActionHandle)
    {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->selectActionHandle)
    {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 0) & MSF_CHOICE_ELEMENT_SELECTED)
        {
            wap_message_editor_t *smsdata;

#ifdef BRA_CFG_DUAL_SIM
            if (bra_sim_get_sim_card_number() == BRA_SIM_ID_NO_SIM)
#else
            if (!mmi_bootup_is_sim_valid())
#endif /* BRA_CFG_DUAL_SIM */
            {
                HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_NO_SIMCARD_WARNING, MsfWarning, 0);
                return;
            }
            /* SMS */
            smsdata = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, wap_message_editor_t);
            memset((S8*)smsdata, 0, sizeof(wap_message_editor_t));
            smsdata->content = msf_cmmn_strdup(MSF_MODID_WIDGET, addr->url);
            
            bra_destroy_ui();
            widget_execute_MMI_p(wap_enter_sms_editor_handler, (void*)smsdata, FALSE);
        }
    }
}

static void
bra_opt_current_url_view_create_send_url (ctk_screen_handle scrid)//(void)
{
    bra_opt_menu_t      *win;
    MsfPosition         pos = BRA_CFG_MENU_POS;
    MsfDeviceProperties prop;
    
    CTK_UNUSED(scrid);

    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    
    win = BRA_ALLOCTYPE (bra_opt_menu_t);
    
    win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfSelect,1, 0x8000);
    win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack,1, 0x8000);
    win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
        MsfImplicitChoice,
        &prop.displaySize,
        win->selectActionHandle,
        0, /*Element Position*/
        MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
        0x8000, /*Property Mask*/
        0 /*Default Style*/);
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, 
        0, 
        BRA_STR_VIA_SMS,
        0, bra_cmn_get_list_num_image(0), 0, TRUE);

    MSF_WIDGET_SET_TITLE(win->windowHandle, BRA_STR_SEND);
    MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,(int) /*MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW |*/ MSF_WINDOW_PROPERTY_TITLE);
    
    MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);

    bra_win_show_window(BRA_WIN_ID_VIEW_URL_SEND, 
        (bra_win_t*)win, 
        &pos, 
        bra_opt_current_url_view_delete_send_url, 
        NULL,
        bra_opt_current_url_view_action_send_url);
}

static void bra_opt_ceate_current_url_view(void)
{
  bra_win_t               *win;
  kal_uint8               *text = NULL;
  ctk_screen_handle	      scrid;
  MsfPosition	          pos =  {0, 0 /*20*/};
  bra_cmn_addr_t*         addr;

  win = BRA_ALLOCTYPE (bra_win_t);
  /*Set all members to 0*/
  memset (win, 0, sizeof (bra_win_t));

  /* Prepare text */
  addr = bra_cmn_get_current_page ();
        
  /*Create Form*/
  if (addr->url != NULL)
  {
    int text_size;
    text_size = strlen(addr->url);
    text_size = text_size * 2 + 2;
    text = BRA_ALLOC(text_size);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*)addr->url);
    win->win_hdl = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, text, 
      									(MSF_UINT16)BRA_STR_ID_VIEW_CURRENT_URL, 0); 
    BRA_FREE(text); // release the text
  }
  else
  {
    win->win_hdl = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, (kal_uint8*)"", 
      									(MSF_UINT16)BRA_STR_ID_VIEW_CURRENT_URL, 0); 
  }
  
  /* Set Key */
  scrid = HDIa_widgetCtkGetScreenHandle(win->win_hdl);

  ctk_screen_addLSK_UA(scrid, BRA_STR_ID_SEND, IMG_GLOBAL_OK, NULL, bra_opt_current_url_view_create_send_url, KAL_TRUE);
  ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, bra_opt_current_url_view_back, KAL_TRUE);

  bra_win_show_window (BRA_WIN_ID_VIEW_URL, 
                      (bra_win_t*)win, 
                      (MsfPosition*)&pos, 
                      bra_opt_delete_current_url_view, 
                      NULL,
                      NULL);
}


static void
bra_opt_enter_select_mode(MsfActionType response)
{
  bra_sif_set_select_mode (TRUE);
  bra_view_enter_select_mode ();
  bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
}

static void
bra_opt_exit_download_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_destroy_ui();
  }
  else
  {
    bra_da_wap_notify_display_list();
  }
}


static void
bra_opt_action_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_opt_menu_t *p;
  int n_action= 0;
  int i, j;
  int idx = 0;
#ifdef BRA_CFG_OFFLINE_PAGES
  extern kal_bool  global_offline_page;
#endif
  
  p = (bra_opt_menu_t *)(win);

  if (bra_action == p->backActionHandle)
  {
    if (bra_view_is_busy())
      bra_view_set_busy_icon();
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
  }
  else if (bra_action == p->selectActionHandle)
  {
    if (show_download && MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, idx++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*download*/
      bra_da_wap_notify_display_list();
      return;
    }
    if (bra_goto && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, idx++) & MSF_CHOICE_ELEMENT_SELECTED))
    {
      extern kal_bool widget_key_ind_handler(kal_uint16 keycode,kal_uint16 keytype);
      /*Open Hyperlink*/      
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
      widget_key_ind_handler(KEY_SEND, KEY_EVENT_UP);
      return;
    }
    if (n_do_element > 0 && bra_opt_do_elements != NULL)
    {
      for (i = 0; i < n_do_element; i++)
      {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, idx+i) & MSF_CHOICE_ELEMENT_SELECTED)
        {
          bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
          BRSif_activateDoElement (MSF_MODID_BRA, bra_sif_get_brs_id (), bra_opt_do_elements->elements[(bra_opt_do_elements->numElements-1)-i].elementId);
          return;
        }
      }
    }

    if(!bra_is_busy)
      n_action = bra_act_get_num_actions();

/* This comment is part of an example to add a File Browser option to 
 * the BRA Options menu.
 * The full example is described in the BRA Reference Manual 
 *
 * Ex: 3.5
 *
 * 3.5 Now an menu item have been selected. 
 *     Add code to determine if it was the "File Browser" option.
 *		
 * (else) if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, X + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
 * {
 *	 bra_search_dialog ();
 * }
 * 
 */
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Home*/
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
      bra_send_request((bra_cmn_get_homepage())->url);
      return;
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Refresh*/
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
      BRSif_reload (MSF_MODID_BRA, bra_sif_get_brs_id());
      return;
    }

    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Bookmarks*/
      bra_bkm_create_bkm_menu();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Recent pages list*/
      bra_rpl_create_rpl_menu (TRUE);
    }
#ifdef BRA_CFG_OFFLINE_PAGES
    else if (global_offline_page && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED))
    {
      /*Offline page*/
      bra_ofln_create_ofln_menu();
    }
#endif
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      bra_req_init_address_list();
      /*Enter Address*/
      for (j = 0; j < BRA_CFG_N_ADDRESS_ITEMS; j++)
      {
        if (bra_req_get_address_item(j) != NULL)
          break;
      }
      if(j < BRA_CFG_N_ADDRESS_ITEMS)
        bra_create_select_url_menu();
      else
        bra_create_url_form(NULL, bra_req_edit_url_response, BRA_WIN_ID_VIEWPORT);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*View current page Url*/
      bra_opt_ceate_current_url_view();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
		/*Save As Homepage*/
#ifdef BRA_USE_CTK_INLINE      
      bra_create_url_form(bra_cmn_get_current_page()->url,
                          bra_opt_url_response,
                          BRA_WIN_ID_OPT);                          
#else
      bra_dlg_create_title_url_form (BRA_STR_SAVE_AS_HOMEP, 
                                     bra_cmn_get_current_page()->title,
                                     bra_cmn_get_current_page()->url,
                                     bra_opt_title_url_response,
                                     BRA_WIN_ID_OPT);
#endif
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
		/*Save Bookmark*/
      bra_bkm_create_offline_add_bookmark_form_with_title(bra_cmn_get_current_page()->title,
                                    bra_cmn_get_current_page()->url,
                                    BRA_WIN_ID_VIEWPORT);
    }
#ifdef BRA_CFG_SELECT_MODE
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Select Mode*/
      bra_dlg_create_dlg (MsfInfo,
                        BRA_STR_ENTERING_SELECT_MODE,
                        BRA_STR_OK, 
                        0,
                        0, 
                        bra_opt_enter_select_mode);
      return;
    }
#else
    if(n_action > 0)
    {
      for(i = 0; i < n_action; i++)
      {
        if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, idx + n_do_element + i) & MSF_CHOICE_ELEMENT_SELECTED)
        {
          /* save as */
          bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
          bra_act_execute_object_action(i);
          return;
        }
      }
      idx += n_action;
    }
#endif
#ifdef BRA_CONFIG_SECURITY
   /*if (bra_sif_sec_cert_available () > 0)
   {
     if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
     {
        SECif_viewCurrentCert(MSF_MODID_BRA, bra_sif_get_brs_id (), bra_sif_get_security_id ());
     }
   }*/
#endif
#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
	if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Push Inbox*/
      extern void bra_psl_create_push_inbox(void);
      bra_psl_create_push_inbox();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
#else
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
#endif		
    {
      /*Settings*/
      bra_create_settings_menu();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Exit UI*/
      if (bra_get_da_download_active_job_count() > 0)
      {
          bra_dlg_create_dlg (MsfConfirmation,
                              BRA_STR_SUSPEND_DOWNLOAD, 
                              BRA_STR_YES,
                              BRA_STR_NO,
                              0, 
                              bra_opt_exit_download_confirmation);
      }
      else
      {
      bra_destroy_ui();
      }
    }
#ifdef WAP_MEM_DEBUG
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* memory logging option*/
      bra_create_mem_logging_menu();
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* max. memory logging option*/
      bra_create_mem_status_menu(1);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, (idx++) + n_do_element) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* cur memory logging option*/
      bra_create_mem_status_menu(0);
    }
#endif
  }
}

static void
bra_opt_delete_menu(bra_win_t *win)
{
  bra_opt_menu_t *p;

  p = (bra_opt_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->selectActionHandle);
	MSF_WIDGET_RELEASE (p->backActionHandle);

  BRA_FREE (p);
}

static void
bra_opt_in_focus(bra_win_t *win)
{
  bra_opt_menu_t *p;

  p = (bra_opt_menu_t *)(win);
}

static void bra_opt_update_items(bra_opt_menu_t *win)
{
  MsfStringHandle ms;
  int idx = 0;
  int i;

  bra_is_busy = bra_view_is_busy();
  
  if (bra_get_da_download_job_count() > 0)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx, BRA_STR_DOWNLOAD, 0, bra_cmn_get_list_num_image(idx), 0, TRUE);
    idx++;
    show_download = 1;
  }
  else
  {
    show_download = 0;
  }
  if(bra_opt_link)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx, BRA_STR_GOTO,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);  
    idx++;
    HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
    bra_goto = TRUE;
  }
  else if(bra_opt_edit) {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx, BRA_STR_EDIT,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);  
    idx++;
    HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
    bra_goto = TRUE;
  }
  else if(bra_opt_reset) {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx, BRA_STR_RESET,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);  
    idx++;
    HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
    bra_goto = TRUE;
  }
  else if(bra_opt_choose) {
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx, BRA_STR_CHOOSE,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);  
    idx++;
    HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
    bra_goto = TRUE;
  }
  else
    bra_goto = FALSE;

  if (bra_opt_do_elements != NULL)
  {
    for (i = bra_opt_do_elements->numElements-1; i >= 0 ; i--)
    {
      if (bra_opt_do_elements->elements[i].label != NULL)
      {
		  if(strcmp(bra_opt_do_elements->elements[i].label, "accept") == 0) {
		    ms = BRA_STR_DO_TYPE_ACCEPT;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "delete") == 0) {
		    ms = BRA_STR_DO_TYPE_DELETE;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "help") == 0) {
		    ms = BRA_STR_DO_TYPE_HELP;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "options") == 0) {
		    ms = BRA_STR_DO_TYPE_OPTIONS;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "prev") == 0) {
		    ms = BRA_STR_DO_TYPE_PREV;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "reset") == 0) {
		    ms = BRA_STR_DO_TYPE_RESET;
		  } else if(strcmp(bra_opt_do_elements->elements[i].label, "unknown") == 0) {
		    ms = BRA_STR_DO_TYPE_UNKNOWN;
		  } else {
			ms = BRA_STRCONV (bra_opt_do_elements->elements[i].label);
		  }
        MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx+(bra_opt_do_elements->numElements-1)-i, ms,  0, bra_cmn_get_list_num_image(idx+(bra_opt_do_elements->numElements-1)-i), 0, TRUE);
        HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx+(bra_opt_do_elements->numElements-1)-i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
        MSF_WIDGET_RELEASE (ms);
      }
      else if (bra_opt_do_elements->elements[i].eventType != NULL)
      {
		  if(strcmp(bra_opt_do_elements->elements[i].eventType, "accept") == 0) {
		    ms = BRA_STR_DO_TYPE_ACCEPT;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "delete") == 0) {
		    ms = BRA_STR_DO_TYPE_DELETE;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "help") == 0) {
		    ms = BRA_STR_DO_TYPE_HELP;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "options") == 0) {
		    ms = BRA_STR_DO_TYPE_OPTIONS;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "prev") == 0) {
		    ms = BRA_STR_DO_TYPE_PREV;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "reset") == 0) {
		    ms = BRA_STR_DO_TYPE_RESET;
		  } else if(strcmp(bra_opt_do_elements->elements[i].eventType, "unknown") == 0) {
		    ms = BRA_STR_DO_TYPE_UNKNOWN;
		  } else {
		    ms = BRA_STRCONV (bra_opt_do_elements->elements[i].eventType);
		  }
        MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, idx+(bra_opt_do_elements->numElements-1)-i, ms,  0, bra_cmn_get_list_num_image(idx+(bra_opt_do_elements->numElements-1)-i), 0, TRUE);
        HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, idx+(bra_opt_do_elements->numElements-1)-i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
        MSF_WIDGET_RELEASE (ms);
      }
      else
        ;
    }
    n_do_element = bra_opt_do_elements->numElements;
  }
  else
    n_do_element = 0;
  
  /* This comment is part of an example to add a File Browser option to 
  * the BRA Options menu.
  * The full example is described in the BRA Reference Manual 
  *
  * Ex: 3.4
  *
  * 4. Add a new menu option in the prefered location below.
  *    Note that it is necessary to update the index of the following items
  *
  * 	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, X + n_do_element, BRA_STR_FILE_BROWSER,  0, 0, 0, TRUE);
  */
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_HOMEPAGE,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
   HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, (idx) + n_do_element - 1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_REFRESH,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
   HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, (idx) + n_do_element - 1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_BOOKMARKS,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_RECENT_PAGES,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
#ifdef BRA_CFG_OFFLINE_PAGES
   if(global_offline_page)
   {
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_OFFLINE_PAGES,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);   
     idx++;
   }     
#endif   
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_ENTER_ADDRESS,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);   
   idx++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_VIEW_CURRENT_URL,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_SAVE_AS_HOMEP,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_ADD_BOOKMARK,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
#ifdef BRA_CFG_SELECT_MODE
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_ENTER_SELECT_MODE,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
#else
   if(!bra_is_busy)
     idx += bra_act_add_actions (win->windowHandle, idx + n_do_element); //Q03C1
#endif  
#ifdef BRA_CONFIG_SECURITY
   /*if (bra_sif_sec_cert_available () > 0)
   {
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_CURENT_CERT,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
     idx++;
   }*/
#endif
#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_PUSH_INBOX, 0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
   idx++;
#endif   
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_SETTINGS,  0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);
	idx++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx) + n_do_element, BRA_STR_EXIT, 0, bra_cmn_get_list_num_image(idx+n_do_element), 0, TRUE);   
   idx++;
   HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, (idx) + n_do_element - 1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
#ifdef WAP_MEM_DEBUG
   {
   MsfStringHandle ms;
   /* memory logging option */
   ms = BRA_STRCONV("Memory Logging");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx++) + n_do_element, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   /* max memory status option */
   ms = BRA_STRCONV("Max Mem Status");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx++) + n_do_element, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   /* cur memory status option */
   ms = BRA_STRCONV("Cur Mem Status");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, (idx++) + n_do_element, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   }
#endif
}

/* This comment is part of an example to add a File Browser option to 
 * the BRA Options menu.
 * The full example is described in the BRA Reference Manual 
 *
 * Ex: 3.3
 *
 * 3.3 This function creates the Options menu were we whant to add the 
 *     File Brower menu item
 */

/*
 * This funtion creates the Options menu.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_opt_create_menu(void)
{
  bra_opt_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
#ifdef BRA_CFG_OFFLINE_PAGES
  extern kal_bool  global_offline_page;
#endif  

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_opt_menu_t);
  
	win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
                                             &prop.displaySize,
                                             win->selectActionHandle,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);


    bra_opt_update_items(win);

	MSF_WIDGET_SET_TITLE(win->windowHandle,BRA_STR_OPTIONS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);

  /*remove menu key action from screen*/
  bra_view_disable ();

	bra_win_show_window (BRA_WIN_ID_OPT, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_opt_delete_menu, 
                      bra_opt_in_focus,
                      bra_opt_action_menu);

}



