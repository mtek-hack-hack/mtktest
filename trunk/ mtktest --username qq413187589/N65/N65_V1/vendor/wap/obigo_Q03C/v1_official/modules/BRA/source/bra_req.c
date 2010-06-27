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
 * bra_req.c
 *
 * Description:
 *		This file contains code to enter and manage urls and to use 
 *    the BRS module to request those urls .
 */

#include "bra_cmn.h"
#include "bra_str.h"
#include "bra_main.h"
#include "bra_win.h"
#include "bra_req.h"
#include "bra_opt.h"
#include "bra_sif.h"
#include "bra_view.h"
#include "bra_prof.h"
#include "bra_file.h"
#include "bra_dlg.h"
#include "bra_inse.h"
#include "bra_set.h"
#include "bra_bkm.h"

#include "msf_lib.h"
#include "msf_log.h"
#include "msf_core.h"
#include "msf_url.h"

#include "widget.h"
#include "widget_extension.h"

#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif
/************************************************************
 * Local Types
 ************************************************************/
/* urlForm */
typedef struct {
  MsfWindowHandle windowHandle;
  MsfWindowHandle backWindowHandle;
  MsfActionHandle backActionHandle;
  MsfActionHandle okActionHandle;
  MsfGadgetHandle urlInputString;
  MsfGadgetHandle address_list;
  bra_req_url_response_t callback;
  int close_to_id;
} bra_req_url_form_t;

typedef struct
{
  MSF_UINT32 s_idx;
  int        file_idx;
  char*      url;
}bra_req_address_item_t;

typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_select_url_menu_t;

typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_select_url_opt_menu_t;

/************************************************************
 * Global variables
 ************************************************************/

static char                   *bra_req_request_url;
static unsigned int            bra_req_current_item;
static bra_req_address_item_t *bra_req_address_list[BRA_CFG_N_ADDRESS_ITEMS];
static void                   *bra_req_history_file;
static int                     bra_req_selected_url_scr_index = -1;

/************************************************************
 * Defines
 ************************************************************/

#define BRA_HISTORY_MAX_FILE_SIZE    5000 /*2500*/
#define BRA_HISTORY_INITIAL_SIZE     BRA_CFG_HIST_INITIAL_SIZE/*2500*/
#define BRA_HISTORY_DEFRAG_LIMIT     4000 /*2500*/
#define BRA_HISTORY_SIZE_INCREMENT   1000 /*2500*/

#define BRA_REQ_INPUT_FIELD_MARGIN   5
#define BRA_REQ_INPUT_FIELD_HEIGHT   20
#define BRA_REQ_ADDRESS_FIELD_HEIGHT 120

/******************************************************************************
 * Local Functions
 *****************************************************************************/

void bra_req_delete_address_item(int sel_index, int index_ref_array, int promptDone);

static void
bra_req_history_create_file_block (bra_req_address_item_t *p, void **block, int *size)
{
  unsigned char *t;

  *size = 4 + strlen (p->url) + 1;

  t = BRA_ALLOC (*size);

  t[0] = (unsigned char)(((p->s_idx) & 0xFF000000) >> 24);
  t[1] = (unsigned char)(((p->s_idx) & 0x00FF0000) >> 16);
  t[2] = (unsigned char)(((p->s_idx) & 0x0000FF00) >> 8);
  t[3] = (unsigned char)(((p->s_idx) & 0x000000FF));

  strcpy ((char *)&t[4], p->url);

  *block = (void*)t;
}

static int
bra_req_history_parse_file_block (void *block, int size, bra_req_address_item_t *p)
{
  MSF_UINT32 s_idx;
  unsigned char *t;

  if ((block == NULL) || (size < 5))
    return -1;

  t = (unsigned char*)block;

  s_idx  = (((MSF_UINT32)t[0]) << 24);
  s_idx += (((MSF_UINT32)t[1]) << 16);
  s_idx += (((MSF_UINT32)t[2]) << 8);
  s_idx += (((MSF_UINT32)t[3]));

  p->s_idx = s_idx;
  p->url = msf_cmmn_strdup (MSF_MODID_BRA, (char*)&t[4]);

  return 1;
}

static void
bra_req_init_file_response (int idx, int eof, void* block, int size)
{
  bra_req_address_item_t *p;
  int i;
  int n;

  if (eof == 0)
  {
    if (bra_req_history_parse_file_block (block, size, bra_req_address_list[bra_req_current_item]) < 0)
    {
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,BRA_REQ_21F66BB7D2148FC156AF8C31B00DC70B, "BRA: Error. Corrupt History file (1)\n"));
      return;
    }

    if (bra_req_current_item < BRA_CFG_N_ADDRESS_ITEMS)
    {
      bra_req_address_list[bra_req_current_item++]->file_idx = idx;
    }    
    else
    {
     /*  
      *Ignore. The file is corrupt, probably due to incorrect shutdown.
      */
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,BRA_REQ_6129F6A47EE3C7DE9C1AE29344B7E850, "BRA: Error. Corrupt History file (2)\n"));

    }
  }
  else
  {
    /*Sort*/
    for (n = bra_req_current_item - 1; n > 0; n--)
    {
      for (i = 0; i < n; i++)
      {
        if (bra_req_address_list[i+1]->s_idx < bra_req_address_list[i]->s_idx)
        {
          /*Swap*/
          p = bra_req_address_list[i];
          bra_req_address_list[i]   = bra_req_address_list[i+1];
          bra_req_address_list[i+1] = p;
        }
      }
    }    
    /*Finished*/    
    bra_main_remove_module_state(BRA_READING_HISTORY);
    bra_init_done ();
  }
}

static void
bra_req_remove_duplication_address_item (char* url)
{
  int i;

  for (i=0; i<BRA_CFG_N_ADDRESS_ITEMS; i++)
    if (bra_req_address_list[i]->file_idx>=0 && bra_req_address_list[i]->url && msf_url_equal(url, bra_req_address_list[i]->url, MSF_URL_ALL_COMP))
    {
      bra_req_delete_address_item(i, TRUE, FALSE);
      /* restart loop as index might be shifted after delete operation */
      i = -1;
    }
}

static void 
bra_req_add_address_item (char *url)
{
  void *block;
  int   size;

  bra_req_remove_duplication_address_item(url);

  if (bra_req_current_item >= BRA_CFG_N_ADDRESS_ITEMS)
    bra_req_current_item = 0;
  
  BRA_FREE(bra_req_address_list[bra_req_current_item]->url);
 
  if (bra_req_address_list[bra_req_current_item]->file_idx >= 0)
  {
    bra_file_delete_block (bra_req_history_file, 
                           bra_req_address_list[bra_req_current_item]->file_idx, 
                           NULL);
  }

  bra_req_address_list[bra_req_current_item]->s_idx = MSF_TIME_GET_CURRENT();
  bra_req_address_list[bra_req_current_item]->url = (char*)BRA_ALLOC (strlen(url) + 1);
  strcpy(bra_req_address_list[bra_req_current_item]->url, url);
 
  bra_req_history_create_file_block (bra_req_address_list[bra_req_current_item], 
                                     &block, 
                                     &size);

  bra_req_address_list[bra_req_current_item]->file_idx = 
         bra_file_write_block (bra_req_history_file, block, size, NULL);

  BRA_FREE (block);
  
  bra_req_current_item++;
  bra_req_selected_url_scr_index = 0;
}

/*  
 *  Function returns i:th url in the stack.
 *
 *  Parameters:
 *  i         : integer value in the range 0 - (BRA_CFG_N_ADDRESS_ITEMS - 1)
 * 
 *  Return    : screen handle
 */
char*
bra_req_get_address_item(int i)
{
  int idx;
  
  idx = bra_req_current_item - i - 1;

  if(idx < 0)
    idx += BRA_CFG_N_ADDRESS_ITEMS;

  return bra_req_address_list[idx]->url;
}

/********************************************************/
/*  Url Form Functions                                  */                     
/********************************************************/

int check_url(char *s)
{
   char *host, *temp, *url = NULL;
   char seps[] = ".";
   char *token;
   int ip_sec = 0;        
   MSF_UINT32 hostlen;
   
   temp = strstr(s, "://");
   if(temp)
   {
      if ((strncmp (s, "ege", strlen("ege")) == FALSE) && (s + strlen("ege")) == temp)
      {
         return 1;
      }
      url = temp+3;
   }
   else
      url = s;

   temp = strchr(url,'/');      
   if(temp)
      hostlen = ((MSF_UINT32)temp - (MSF_UINT32)url);
   else
      hostlen = strlen(url);

   host = BRA_ALLOC(hostlen+1);
   strncpy(host, url, hostlen);
   host[hostlen] = '\0';

   /* 1st char of ip or hostname can't be '.' */      
   if(host[0] == '.')
   {
      BRA_FREE(host);
      return 0;
   }
      
   token = strtok(host, seps);
   while(token)
   {
      unsigned short i;
      for(i=0;i<strlen(token);i++)
      {
         if( i >= 3)
         {
            BRA_FREE(host);
            return 1;
         }
            
         if(token[i] < '0' || token[i] > '9')
         {
            BRA_FREE(host);
            return 1;
         }
      }
      
      /* this segement is ip format */
      ip_sec++;

      token = strtok(NULL, seps);
   }
   
   if(ip_sec != 4)
   {
      BRA_FREE(host);
      return 0;
   }

   BRA_FREE(host);	   
   return 1;   
}

static int
bra_req_add_to_bookmark_editor_response(char* title, char* url)
{
  bra_bkm_add_new_bookmark(title, url);
  return 1;
}

static void
bra_req_delete_response (void)
{
    bra_cmn_deleted_dialog();
}

/*  
 *  Function delete item at index specified
 *
 *  Parameters:
 *  sel_index       : integer value in the range 0 - (BRA_CFG_N_ADDRESS_ITEMS - 1)
 *  index_ref_array : TRUE if specified index can be used to reference bra_req_address_lis[ ]
 *                    FALSE means index is from screen's address highlight index, this func will perform conversion
 * 
 */
void
bra_req_delete_address_item(int sel_index, int index_ref_array, int promptDone)
{
  int last_item_index;
  int i;
  int valid_i;
  int current_item_index;  // next item index to write data to
  bra_req_address_item_t* tmp;


  /* convert to array index */
  if (!index_ref_array)
  {
    sel_index = bra_req_current_item - sel_index - 1;
    if(sel_index < 0)
      sel_index += BRA_CFG_N_ADDRESS_ITEMS;
  }

  current_item_index = bra_req_current_item % BRA_CFG_N_ADDRESS_ITEMS;

  last_item_index = current_item_index-1;
  if (last_item_index<0 || last_item_index<sel_index)
    last_item_index += BRA_CFG_N_ADDRESS_ITEMS;


  /* remove url from array + file */
  if (bra_req_address_list[sel_index]->url != NULL) {
    BRA_FREE (bra_req_address_list[sel_index]->url);
    if (bra_req_address_list[sel_index]->file_idx >= 0)
    {
      if (promptDone)
        bra_file_delete_block (bra_req_history_file, bra_req_address_list[sel_index]->file_idx, bra_req_delete_response);
      else
        bra_file_delete_block (bra_req_history_file, bra_req_address_list[sel_index]->file_idx, NULL);
    }
  }
  

  /* left shift urls */
  for (i=sel_index; i<last_item_index; i++) {
    valid_i = (i<BRA_CFG_N_ADDRESS_ITEMS?i:i-BRA_CFG_N_ADDRESS_ITEMS);

    tmp = bra_req_address_list[((valid_i+1)%BRA_CFG_N_ADDRESS_ITEMS)];
    bra_req_address_list[valid_i]->s_idx = tmp->s_idx;
    bra_req_address_list[valid_i]->file_idx = tmp->file_idx;
    bra_req_address_list[valid_i]->url = tmp->url;
  }

  bra_req_current_item--;

  if (bra_req_current_item == 0)
    bra_req_current_item += BRA_CFG_N_ADDRESS_ITEMS;

  bra_req_address_list[bra_req_current_item%BRA_CFG_N_ADDRESS_ITEMS]->url = NULL;
  bra_req_address_list[bra_req_current_item%BRA_CFG_N_ADDRESS_ITEMS]->s_idx = 0;
  bra_req_address_list[bra_req_current_item%BRA_CFG_N_ADDRESS_ITEMS]->file_idx = -1;

  for (i=0; i<BRA_CFG_N_ADDRESS_ITEMS; i++)
    if (bra_req_address_list[i]->url != NULL)
      return;
  bra_req_current_item = 0;
}

static void 
bra_req_delete_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_req_delete_address_item(bra_req_selected_url_scr_index, FALSE, TRUE);

    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_SELECT_URL_MENU);
    if (!bra_req_current_item)
      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void 
bra_req_delete_all_confirmation(MsfActionType response)
{
  int i;

  if(response == MsfOk)
  {
    for (i=0; i<BRA_CFG_N_ADDRESS_ITEMS; i++)
    {
      if (bra_req_address_list[i]->url != NULL) {
        BRA_FREE (bra_req_address_list[i]->url);
        if (bra_req_address_list[i]->file_idx >= 0)
          bra_file_delete_block (bra_req_history_file, bra_req_address_list[i]->file_idx, NULL);
      }

      bra_req_address_list[i]->url = NULL;
      bra_req_address_list[i]->s_idx = 0;
      bra_req_address_list[i]->file_idx = -1;
    }
    bra_req_current_item = 0;
    bra_cmn_deleted_dialog();
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_SELECT_URL_MENU);
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void
bra_delete_select_url_opt_menu (bra_win_t *win)
{
  bra_select_url_opt_menu_t *p;

  p = (bra_select_url_opt_menu_t *)(win);
  bra_bkm_destroy();

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

  MSF_WIDGET_RELEASE (p->windowHandle); 
  MSF_WIDGET_RELEASE (p->selectActionHandle);
  MSF_WIDGET_RELEASE (p->backActionHandle);

  BRA_FREE (p);
}

static void
bra_action_select_url_opt_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_select_url_opt_menu_t *p;
  char *url;
  MsfStringHandle title = BRA_STRCONV (BRA_CMN_HNV (NULL));;


  p = (bra_select_url_opt_menu_t *)(win);

  if (bra_action == p->backActionHandle)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->selectActionHandle)
  {
    url = bra_req_get_address_item(bra_req_selected_url_scr_index);
    if (url == NULL)
      return;

    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 0) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* GOTO */
      bra_send_request(url);
      bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 1) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* EDIT */
      bra_create_url_form(url, bra_req_edit_url_response, BRA_WIN_ID_VIEWPORT);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 2) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Add To Bookmark */
      if (bra_bkm_is_full())
      {
        bra_dlg_create_dlg (MsfError,
                            BRA_STR_ERR_BKM_FULL, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
      }
      else
      {

#ifdef BRA_USE_CTK_INLINE      
        bra_dlg_ctk_create_title_url_form (BRA_STR_ID_ADD_BOOKMARK, 
                                    title,
                                    url,
                                    bra_req_add_to_bookmark_editor_response,
                                    BRA_WIN_ID_SELECT_URL_OPT_MENU,
                                    TRUE,
                                    FALSE);
#else
        bra_dlg_create_title_url_form(BRA_STR_ADD_BOOKMARK, 
                                    title,
                                    url,
                                    bra_req_add_to_bookmark_editor_response,
                                    BRA_WIN_ID_SELECT_URL_OPT_MENU);
#endif
      }
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 3) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete */
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_req_delete_confirmation);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 4) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete All */
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ALL_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_req_delete_all_confirmation);
    }
  }
}

void
bra_create_select_url_opt_menu (void)
{
  bra_select_url_opt_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
	
  win = BRA_ALLOCTYPE (bra_select_url_opt_menu_t);
  
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

  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_GOTO,  0, bra_cmn_get_list_num_image(0), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_EDIT,  0, bra_cmn_get_list_num_image(1), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_ADD_BOOKMARK,  0, bra_cmn_get_list_num_image(2), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_DELETE,  0, bra_cmn_get_list_num_image(3), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_DELETE_ALL,  0, bra_cmn_get_list_num_image(4), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  

  MSF_WIDGET_SET_TITLE(win->windowHandle,BRA_STR_OPTIONS);
  MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

  MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);

  bra_bkm_init();
  bra_win_show_window (BRA_WIN_ID_SELECT_URL_OPT_MENU,  
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_select_url_opt_menu, 
                      NULL,
                      bra_action_select_url_opt_menu);
}

static void
bra_delete_select_url_menu (bra_win_t *win)
{
  bra_select_url_menu_t *p;

  p = (bra_select_url_menu_t *)(win);

  bra_win_deregister_notify(p->windowHandle);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

  MSF_WIDGET_RELEASE (p->windowHandle); 
  MSF_WIDGET_RELEASE (p->selectActionHandle);
  MSF_WIDGET_RELEASE (p->backActionHandle);

  bra_req_destroy_address_list();

  BRA_FREE (p);
}

static void
bra_action_select_url_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_select_url_menu_t *p;
  MSF_UINT8 i = 0;
  char *url;

  p = (bra_select_url_menu_t *)(win);

	if (bra_action == p->backActionHandle)
	{
     bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
   }
	else if (bra_action == p->selectActionHandle)
	{
     if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 0) & MSF_CHOICE_ELEMENT_SELECTED)
	  {
     /*New URL*/
       bra_create_url_form(NULL, bra_req_edit_url_response, BRA_WIN_ID_VIEWPORT);
       bra_req_selected_url_scr_index = -1;
     }
	  else
	  {
        for (i = 0; i < BRA_CFG_N_ADDRESS_ITEMS; i++)
        {
          if ((url=bra_req_get_address_item(i)) != NULL && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i+1) & MSF_CHOICE_ELEMENT_SELECTED))
            break;
        }

        if (i < BRA_CFG_N_ADDRESS_ITEMS)
        {
            bra_req_selected_url_scr_index = i;
            bra_create_select_url_opt_menu();
        }
        else
        {
            return;
        }
     }     
	}
}

void
bra_notify_select_url_menu(bra_win_t* win, MsfNotificationType type)
{
  /* update of LSK label using Widget Nodify mechanism will not be used anymore!
   * the hilite callback mechanism is used instead.
   */ 
  
  bra_select_url_menu_t *p = (bra_select_url_menu_t *)(win);

  if (type == MsfNotifyStateChange)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, 0) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* New URL highlighted */
      HDIa_widgetExtActionSetText(p->selectActionHandle, BRA_STR_OK);
    }
    else
    {
      /* URL item highlighted */
      HDIa_widgetExtActionSetText(p->selectActionHandle, BRA_STR_OPTIONS);
    }
    widget_paint();
  }
}

void
bra_enter_address_hilite_callback(MsfWindowHandle whdl, int index)
{
  bra_win_t *win = bra_win_find_win(whdl);
  bra_select_url_menu_t *p = (bra_select_url_menu_t *)(win);

  if (win)
  {
    if (index == 0)
      HDIa_widgetExtActionSetText(p->selectActionHandle, BRA_STR_OK);
    else
      HDIa_widgetExtActionSetText(p->selectActionHandle, BRA_STR_OPTIONS);
  }
}

static void
bra_select_url_menu_in_focus(bra_win_t *win)
{
  char *str;
  MsfStringHandle ms;
  int j;
  int numAdded;

  numAdded = 0;
  HDIa_widgetExtActionSetText(((bra_select_url_menu_t *)win)->selectActionHandle, BRA_STR_OK);
  for (j = 0; j < BRA_CFG_N_ADDRESS_ITEMS; j++)
  {
    if ((str = bra_req_get_address_item(j)) != NULL)
    {
      MSF_WIDGET_CHOICE_REMOVE_ELEMENT(win->win_hdl, j+1);

      ms = BRA_STRCONV(str);/*OK*/
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->win_hdl, j+1, ms, 0, bra_cmn_get_list_num_image(j+1), 0, FALSE);
      MSF_WIDGET_RELEASE (ms);
      numAdded++;
    }
  }
  if (!numAdded)
    return;

  /* if highlight index past end of available URLs (eg. deleted last URL in list previously) */
  if (numAdded==bra_req_selected_url_scr_index && bra_req_selected_url_scr_index>0)
    bra_req_selected_url_scr_index--;

  if (bra_req_selected_url_scr_index > -1)
  {
    MSF_WIDGET_CHOICE_SET_ELEM_STATE(win->win_hdl, bra_req_selected_url_scr_index+1, MSF_CHOICE_ELEMENT_SELECTED);
    HDIa_widgetExtActionSetText(((bra_select_url_menu_t *)win)->selectActionHandle, BRA_STR_OPTIONS);
  }

  for (j=numAdded; j<BRA_CFG_N_ADDRESS_ITEMS; j++)
  {
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT(win->win_hdl, j+1);
  }
}

void
bra_create_select_url_menu (void)
{
  bra_select_url_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
	
  win = BRA_ALLOCTYPE (bra_select_url_menu_t);
  
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

  MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i, BRA_STR_ENTER_ADDRESS,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
  MSF_WIDGET_SET_TITLE(win->windowHandle,BRA_STR_ENTER_ADDRESS);
  MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE|MSF_WINDOW_PROPERTY_NOTIFY);

  MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);
	
  bra_req_selected_url_scr_index = -1;
  bra_win_register_notify(win->windowHandle, bra_notify_select_url_menu);

  HDIa_widgetExtMenuRegisterHighlightHandle(
                win->windowHandle,
                (MsfMenuExtHighlightHandle)bra_enter_address_hilite_callback);
  
  bra_win_show_window (BRA_WIN_ID_SELECT_URL_MENU,  
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_select_url_menu, 
                      bra_select_url_menu_in_focus,
                      bra_action_select_url_menu);
}

int
bra_req_edit_url_response(char *url)
{
  bra_req_add_address_item (url);         
  bra_send_request (url);
  return 1;
}

static void
bra_action_url_editor(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_req_url_form_t *p;
  MsfStringHandle msfStr; 
  char *url;
  int   length;

  p = (bra_req_url_form_t *)(win);

  if (bra_action == p->okActionHandle)
  {
    msfStr = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_BRA, p->windowHandle, 0);
    
    if (MSF_WIDGET_STRING_COMPARE(BRA_STR_HTTP_URL, msfStr) == 0)
    {
      MSF_WIDGET_RELEASE(msfStr); 
      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);   
      bra_dlg_create_dlg (MsfError,
                          BRA_STR_INVALID_URL, 
                          BRA_STR_OK, 
                          0,
                          0, 
                          NULL);    
		return;     
    }
    else
    { 
      char *tmpurl;
      int close_to_id;

      length = MSF_WIDGET_STRING_GET_LENGTH (msfStr,  1, MsfUtf8);      
      url = BRA_ALLOC (length + 1);
      MSF_WIDGET_STRING_GET_DATA(msfStr, url, MsfUtf8);
      url[length] = '\0';

      tmpurl = msf_url_make_complete (MSF_MODID_BRA, url);

      if(tmpurl == NULL || !bra_cmn_url_is_valid(tmpurl))
      {
        MSF_WIDGET_RELEASE(msfStr); 
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
        bra_dlg_create_dlg (MsfError,
                            BRA_STR_INVALID_URL, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);    
        BRA_FREE(url);
        BRA_FREE(tmpurl);
        return;     
      }

      if(p->callback)
        p->callback(tmpurl);

      MSF_WIDGET_RELEASE(msfStr); 
      BRA_FREE (tmpurl);     
      BRA_FREE (url);
      close_to_id = p->close_to_id;
      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
      bra_win_close_window(BRA_WIN_CLOSE_TO_ID, close_to_id);
    }        
  }
  else if (bra_action == p->backActionHandle)
  {
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void
bra_delete_url_form(bra_win_t *win)
{
  bra_req_url_form_t *p;

  p = (bra_req_url_form_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->backActionHandle);
	MSF_WIDGET_RELEASE (p->okActionHandle);
	MSF_WIDGET_RELEASE (p->urlInputString);

  if(!bra_win_get_window(BRA_WIN_ID_SELECT_URL_MENU)
     && p->callback == bra_req_edit_url_response)
    bra_req_destroy_address_list();

  BRA_FREE (p);
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/
/*
 * Initializes the history list (list of previously entered adresses)
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void
bra_req_init_address_list (void)
{
  int i;

  bra_main_set_module_state (BRA_READING_HISTORY);

  bra_req_current_item = 0;

  for(i = 0; i < BRA_CFG_N_ADDRESS_ITEMS; i++)
  {
    bra_req_address_list[i] = BRA_ALLOCTYPE (bra_req_address_item_t);
    bra_req_address_list[i]->s_idx    = 0;
    bra_req_address_list[i]->file_idx = -1;
    bra_req_address_list[i]->url      = NULL;
  }
  
  bra_file_init (BRA_CFG_HISTORY_FILE_PATH, 
                 &bra_req_history_file, 
                 BRA_HISTORY_MAX_FILE_SIZE, 
                 BRA_HISTORY_INITIAL_SIZE, 
                 BRA_HISTORY_DEFRAG_LIMIT, 
                 BRA_HISTORY_SIZE_INCREMENT,
                 bra_req_init_file_response);
}

/*
 * Free resources allocated for the above list
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_req_destroy_address_list (void)
{
  int i;

  bra_req_current_item = 0;

  bra_file_close (bra_req_history_file);

  for(i = 0; i < BRA_CFG_N_ADDRESS_ITEMS; i++)
  {
    BRA_FREE (bra_req_address_list[i]->url);
    BRA_FREE (bra_req_address_list[i]);
  }
}

/*
 * This function creates a Url input field and a list of previously 
 * entered addresses. When the user presses accept the entered or
 * selected key is requested using send request. If the user presses
 * Cancel key the window is closed.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_create_url_form(char *defStr, bra_req_url_response_t callback, int close_to_id) 
{
  bra_req_url_form_t *win;
  MsfStringHandle urlInputString = 0;
  const MsfPosition win_pos = BRA_CFG_MENU_POS;

  win = BRA_ALLOCTYPE (bra_req_url_form_t);
  
  if(defStr)
    urlInputString = BRA_STRCONV(defStr);
  else
    urlInputString = MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, "http://", MsfUtf8, 1, 0);

  if(!urlInputString)
  {
    BRA_FREE(win);
    return;
  }
  
  win->windowHandle = MSF_WIDGET_EDITOR_CREATE(MSF_MODID_BRA, 0, urlInputString, MsfUrl, 
                           BRA_CFG_MAX_NBR_CHARS_URL, 1, NULL, 0, 0);
  
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

  win->urlInputString = urlInputString;
  win->callback = callback;
  win->close_to_id = close_to_id;

  MSF_WIDGET_SET_TITLE(win->windowHandle,BRA_STR_ENTER_ADDRESS);
  MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

  bra_win_show_window (BRA_WIN_ID_URL_FORM, 
                      (bra_win_t*)win, 
                      (MsfPosition*)&win_pos, 
                      bra_delete_url_form, 
                      NULL,
                      bra_action_url_editor);
}

static void
bra_req_set_request_url (char *url)
{
	bra_req_request_url = BRA_ALLOC(strlen(url) + 1);
		
  strcpy(bra_req_request_url, url);
}

/*
 * This function return the URL of a curently pending send request
 * If there are not pending requests the function return NULL
 *
 * PARAMETERS
 *
 * RETURN    :URL to pending request or NULL
 */
char *
bra_req_get_request_url (void)
{
  return bra_req_request_url;
}

void
bra_req_init_request_url(void)
{
  bra_req_request_url = NULL;
}


/*
 * This function frees the memory used to hold a pending request
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_req_clear_pending_req_url (void)
{
  BRA_FREE (bra_req_request_url);

  bra_req_request_url = NULL;
}

/*
 * This function initializes the resources (e.g. start BRS module )  
 * needed to maka a request for the specific url and then make the 
 * request for that url.
 *
 * PARAMETERS
 *
 * URL       : Requested URL
 *
 * RETURN    : void
 */
void
bra_send_request (char* url)
{  
  int options;
  int i;
  char *url_to_load;

  int conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
  if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
  {
    char *s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_addr");  
    if (s == NULL || strlen((const char*)s) == 0 || !check_ip(s))
    {
      extern void BRAif_showDialog (MSF_UINT8 dlg_type, MSF_UINT32 ms);
      extern void BRAif_destroyUI (void);
      extern int HDIa_widgetExtShowPopup(MSF_UINT8 modId, MsfStringHandle dialogText, MsfDialogType type, int timeout);

      if (!bra_win_get_window(BRA_WIN_ID_INSE) &&
          !bra_win_get_window(BRA_WIN_ID_OPT) &&
          !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG) &&
          bra_win_get_window(BRA_WIN_ID_VIEWPORT) &&
          !bra_view_if_has_viewable_page())
      {
        HDIa_widgetExtForcePopup(BRA_STR_INVALID_GATEWAY_IP, MsfError, 3000);
        /*HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_GATEWAY_IP, MsfError, 3000);*/
        BRAif_destroyUI();
      }
      else
      {
        BRAif_showDialog(MsfError, BRA_STR_INVALID_GATEWAY_IP);
      }

      return;
    }    
  }

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA,BRA_REQ_37936FACA6C28076284160046D2FC82E, "BRA: Send Request - url: %s\n", url));
  
  if(url == NULL)
    return;

  if(bra_req_get_request_url () == NULL)
    bra_req_set_request_url (url);

  if (bra_sif_get_brs_status () != BRA_SIF_BRS_CREATED)
  {
    bra_sif_start_brs ();
    return;
  }

  i = bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_CACHEON);

  if (i == 1)
    options = 0;
  else
    options = BRS_OPTION_NO_CACHE;
    
#ifdef BRA_CFG_OFFLINE_PAGES
  if(bra_ofln_loading_offline_page() == 1)
    bra_ofln_set_offline_mode(TRUE);
#endif    
    
#ifdef BRA_CFG_PROF_FALLBACK
  bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_URL_FALLBACK, bra_req_get_request_url(), 0);
#endif

  url_to_load = bra_cmn_remove_string_blank(bra_req_get_request_url()); 

  BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id ());
  BRSif_loadUrl (MSF_MODID_BRA, bra_sif_get_brs_id (), options, url_to_load);

  BRA_FREE(url_to_load);
  bra_req_clear_pending_req_url ();
}

