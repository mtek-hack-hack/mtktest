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
 * Copyright (C) Teleca Mobile Technologies AB, 2002.
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
 * bra_rpl.c
 *
 * Description:
 *		This file contains code to make a Recent Page List menu.
 *    it displays the x last visited pages. It displays at most
 *    y items per page. Keys 1-9 can be used to select items.
 *
 */
#include "bra_cmn.h"
#include "bra_str.h"
#include "bra_sig.h"
#include "bra_win.h"
#include "bra_main.h"
#include "bra_req.h"
#include "bra_dlg.h"
#include "bra_rpl.h"
#include "bra_file.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#endif

/************************************************************
 * Local Types
 ************************************************************/

/* history menu */
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_rpl_menu_t;

typedef struct {
  MSF_UINT32     sort_idx;
  char          *url;
  char          *title;
  int            file_idx;
} bra_rpl_history_item_t;


/************************************************************
 * Local definitions
 ************************************************************/

#define BRA_MAX_RPL_ITEMS             BRA_CFG_MAX_RPL_ITEMS

#define BRA_RPL_ITEMS_PER_PAGE        10/*9*/

#define BRA_HISTORY_MAX_FILE_SIZE    10000
#define BRA_HISTORY_INITIAL_SIZE     BRA_CFG_RPL_INITIAL_SIZE/*10000*/
#define BRA_HISTORY_DEFRAG_LIMIT     10000
#define BRA_HISTORY_SIZE_INCREMENT   10000 


/************************************************************
 * Global Variables
 ************************************************************/
static bra_rpl_history_item_t bra_rpl_static_history_list[BRA_MAX_RPL_ITEMS];
static bra_rpl_history_item_t *bra_rpl_history_list[BRA_MAX_RPL_ITEMS];
static int                    bra_nbr_historyitems = 0;
static void                  *bra_rpl_history_file;
static int                    bra_rpl_n_pages_displayed;
static int                    bra_rpl_hilite_index;

/************************************************************
 * Function definitions
 ************************************************************/
static int  bra_rpl_remove_history_item(const char*url);
static int  bra_rpl_remove_history_item_idx(int idx);

static void bra_rpl_ceate_rpl_view(void);
static void bra_rpl_delete_rpl_view(bra_win_t *win);
static void bra_rpl_view_back(ctk_screen_handle scrid);

static void bra_rpl_action_menu(bra_win_t *win, MSF_UINT32 bra_action);
static void bra_rpl_delete_menu(bra_win_t *win);

static void msf_rpl_delete_selected (void);

static void bra_rpl_init_file_response (int idx, int eof, void* block, int size);

/**************************FILE HANDELING*********************/

static void
bra_rpl_create_file_block (bra_rpl_history_item_t *p, void **block, int *size)
{
  unsigned char *t;
  int url_len;
  int title_len;


  url_len = strlen (p->url);
  if (p->title == NULL)
  {
    title_len = 0;
  }
  else
  {
    title_len = strlen(p->title);
  }

  *size = 4 + url_len + title_len + 2;

  t = BRA_ALLOC (*size);

  t[0] = (unsigned char)(((p->sort_idx) & 0xFF000000) >> 24);
  t[1] = (unsigned char)(((p->sort_idx) & 0x00FF0000) >> 16);
  t[2] = (unsigned char)(((p->sort_idx) & 0x0000FF00) >> 8);
  t[3] = (unsigned char)(((p->sort_idx) & 0x000000FF));

  strcpy ((char *)&t[4], p->url);
  if (p->title == NULL)
  {
    t[5 + url_len] = '\0';
  }
  else
  {
    strcpy ((char *)&t[5 + url_len], p->title);
  }
  *block = (void*)t;
}

static int
bra_rpl_parse_file_block (void *block, int size, bra_rpl_history_item_t *p)
{
  MSF_UINT32 sort_idx;
  unsigned char *t;
  int url_len;

  if ((block == NULL) || (size < 5))
    return -1;

  t = (unsigned char*)block;

  sort_idx  = (((MSF_UINT32)t[0]) << 24);
  sort_idx += (((MSF_UINT32)t[1]) << 16);
  sort_idx += (((MSF_UINT32)t[2]) << 8);
  sort_idx += (((MSF_UINT32)t[3]));

  p->sort_idx = sort_idx;

  url_len = strlen((char*)&t[4]);
  if (size < (5 + url_len))
    return -1;

  p->url = msf_cmmn_strdup (MSF_MODID_BRA, (char*)&t[4]);
  p->title = msf_cmmn_strdup (MSF_MODID_BRA, (char*)&t[5 + url_len]);

  return 1;
}

static void bra_rpl_init_file_response (int idx, int eof, void* block, int size)
{
  bra_rpl_history_item_t *p;
  int i;
  int n;

  if (eof == 0 && bra_nbr_historyitems < BRA_MAX_RPL_ITEMS)
  {
    if (bra_rpl_parse_file_block (block, size, bra_rpl_history_list[bra_nbr_historyitems]) < 0)
      return;

    bra_rpl_history_list[bra_nbr_historyitems++]->file_idx = idx;
  }
  else
  {
    /*Sort*/
    for (n = bra_nbr_historyitems - 1; n > 0; n--)
    {
      for (i = 0; i < n; i++)
      {
        if (bra_rpl_history_list[i+1]->sort_idx < bra_rpl_history_list[i]->sort_idx)
        {
          /*Swap*/
          p = bra_rpl_history_list[i];
          bra_rpl_history_list[i]   = bra_rpl_history_list[i+1];
          bra_rpl_history_list[i+1] = p;
        }
      }
    }    
    /*Finished*/    
    bra_main_remove_module_state(BRA_READING_RECENT_PAGE_LIST);
    bra_init_done ();
  }
}


/************************END FILE HANDELING*******************/




/*
 * This function initializes the bookmarks manager and reads the 
 * saved bookmarks from file.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_rpl_init (void)
{
  int i;

  bra_main_set_module_state (BRA_READING_RECENT_PAGE_LIST);

  bra_nbr_historyitems = 0;
  bra_rpl_hilite_index = -1;

  for(i = 0; i < BRA_MAX_RPL_ITEMS; i++)
  {
    //bra_rpl_history_list[i] = BRA_ALLOCTYPE (bra_rpl_history_item_t);
    bra_rpl_history_list[i] = &bra_rpl_static_history_list[i];
    bra_rpl_history_list[i]->sort_idx  = 0;
    bra_rpl_history_list[i]->file_idx  = -1;
    bra_rpl_history_list[i]->url       = NULL;
    bra_rpl_history_list[i]->title     = NULL;
  }
  
  bra_file_init (BRA_CFG_RECENT_LIST_FILE_PATH, 
                 &bra_rpl_history_file, 
                 BRA_HISTORY_MAX_FILE_SIZE, 
                 BRA_HISTORY_INITIAL_SIZE, 
                 BRA_HISTORY_DEFRAG_LIMIT, 
                 BRA_HISTORY_SIZE_INCREMENT,
                 bra_rpl_init_file_response);
}

/*
 * This function terminates the bookmark manager and releases all 
 * resources allocated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_rpl_destroy (void)
{
  int i;

  bra_file_close (bra_rpl_history_file);

  for(i = 0; i < BRA_MAX_RPL_ITEMS; i++)
  {
    if (bra_rpl_history_list[i]->url != NULL)
      BRA_FREE (bra_rpl_history_list[i]->url);
    if (bra_rpl_history_list[i]->title != NULL)
      BRA_FREE (bra_rpl_history_list[i]->title);
    //BRA_FREE (bra_rpl_history_list[i]);
  }

  bra_nbr_historyitems = 0;
}

static void
bra_rpl_activate_key_events (int activate){ 

  MsfScreenHandle screen;
  int action;

  screen = bra_win_get_screen ( );

  if (screen == 0)
    return;

  if (activate == TRUE)
    action = 0;
  else 
    action = 1;


  MSF_WIDGET_HANDLE_MSF_EVT (screen, MsfKey_Clear,   TRUE, action);
  
}
/*
 * This function creates and display the man bookmarks menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_rpl_create_rpl_menu (int first)
{
  bra_rpl_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  bra_rpl_history_item_t *p;
  MsfStringHandle ms;
  int i;
  int start_item;
  int end_item;
  int idx = 0;

  if (bra_nbr_historyitems == 0)
  {
    /*No history items are saved*/
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
    /*bra_dlg_create_dlg (MsfPromptEmpty,
              BRA_STR_NO_HISTORY, 
              BRA_STR_OK, 
              0, 
              0, 
              NULL);*/

    return;
  }

  if (first == TRUE)
    bra_rpl_n_pages_displayed = 0;
  else 
    bra_rpl_n_pages_displayed += 1;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_rpl_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OPTIONS,MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
                                             &prop.displaySize,
                                             win->accept,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1|MSF_CHOICE_ELEMENT_INDEX, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

  start_item = bra_nbr_historyitems - (BRA_RPL_ITEMS_PER_PAGE * bra_rpl_n_pages_displayed);
  end_item   = MAX (start_item - BRA_RPL_ITEMS_PER_PAGE, 0);
  
  for (i=start_item; i>end_item; i--)
  {
    p = bra_rpl_history_list[i-1];
    if (p->title && *(p->title) != 0)
    {
      ms = BRA_STRCONV (BRA_CMN_HNV (p->title));
      MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, idx, ms,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);
      idx++;
      MSF_WIDGET_RELEASE (ms);
    }
    else
    {
      ms = BRA_STRCONV (BRA_CMN_HNV (p->url));
      MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, idx, ms,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);
      idx++;
      HDIa_widgetExtChoiceSetElemFlag(win->window, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
      MSF_WIDGET_RELEASE (ms);
    }
  }

  if ((start_item - BRA_RPL_ITEMS_PER_PAGE) > 0){
      ms = BRA_STRCONV ("More ...");
      MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, idx, ms,  0, bra_cmn_get_list_num_image(idx), 0, TRUE);
      idx++;
      HDIa_widgetExtChoiceSetElemFlag(win->window, idx-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
      MSF_WIDGET_RELEASE (ms);
  }

  if (bra_rpl_hilite_index >= 0)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, bra_rpl_hilite_index, MSF_CHOICE_ELEMENT_SELECTED);

  bra_rpl_hilite_index = -1;

	MSF_WIDGET_SET_TITLE(win->window,BRA_STR_RECENT_PAGES);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->window, win->back);

  /*remove menu key action from screen*/
  bra_win_delete_screen_action (MsfBack);
  bra_win_delete_screen_action (MsfMenu);
  
  bra_rpl_activate_key_events (TRUE);
  
  bra_win_delete_screen_action (MsfOk);


	bra_win_show_window (BRA_WIN_ID_RPL_MAIN, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_rpl_delete_menu, 
                      NULL,
                      bra_rpl_action_menu);
}

/*
 * Adds an history item to the list.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_rpl_add_history_item (const char *url, const char *title)
{
  bra_rpl_history_item_t *p;
  unsigned char *buffer;
  int   buf_len;

  if (url == NULL)
    return;

  /*Remove if an old version with the same URL exists,
    if no such item exist remove last item*/
  if (bra_rpl_remove_history_item(url) == FALSE)
    if (bra_nbr_historyitems == BRA_MAX_RPL_ITEMS){
     bra_rpl_remove_history_item_idx (0);
    }

  p = bra_rpl_history_list[bra_nbr_historyitems];
  p->url = BRA_ALLOC(strlen(url) + 1);
  strcpy (p->url, url);
  if (title != NULL)
  {
    p->title = BRA_ALLOC(strlen(title) + 1);
    strcpy (p->title, title);
  }
  else
  {
    p->title = NULL;
  }
  p->sort_idx = MSF_TIME_GET_CURRENT();

  bra_rpl_create_file_block(p, (void**)&buffer, &buf_len);

  p->file_idx = bra_file_write_block (bra_rpl_history_file, buffer, buf_len, NULL);
  BRA_FREE (buffer);

  bra_nbr_historyitems++;
}

/*
 * Clears the history list
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
void
bra_rpl_clear_history_list (void)
{
  bra_rpl_history_item_t *p;
  int i;
  /*Delete All*/

  for (i=bra_nbr_historyitems-1; i>=0; i--)
  {
    p = bra_rpl_history_list[i]; 
    bra_rpl_remove_history_item(p->url);
  }

  bra_nbr_historyitems = 0;
/*
  MSF_FILE_RMEOVE (file);
  for(i = 0; i < BRA_MAX_RPL_ITEMS; i++)
  {
    p = bra_rpl_history_list[i]; 

    if (p->title)
      BRA_FREE(p->title);
    if (p->url)
      BRA_FREE(p->url);
    
    p->sort_idx  = 0;
    p->file_idx  = -1;
    p->url       = NULL;
    p->title     = NULL;
  }

  bra_nbr_historyitems = 0;
  */
}

/*
 * Goes through the list and removes items with the
 * same url.
 *
 * PARAMETERS
 *
 * RETURN    True if removed else False: 
 */
static int
bra_rpl_remove_history_item(const char*url)
{
  bra_rpl_history_item_t *p;
  int i;
  int j;

  for (i=0; i<bra_nbr_historyitems; i++)
  {
    p = bra_rpl_history_list[i];
    if(p->url)/*kevin*/
    {
    if (strcmp(p->url, url) == 0 )
      goto found;
    }
  }

  return FALSE;

found:
  /*An item has been found and should be removed*/
  if (p->title)
    BRA_FREE(p->title);
  if (p->url)
    BRA_FREE(p->url);

  p->url   = NULL;
  p->title = NULL;

  bra_file_delete_block (bra_rpl_history_file, p->file_idx , NULL);

  if (i < (bra_nbr_historyitems-1) )
  {
    for (j=i; j < (bra_nbr_historyitems - 1); j++)
    {
      p = bra_rpl_history_list[j];
      bra_rpl_history_list[j] = bra_rpl_history_list[j+1];
      bra_rpl_history_list[j+1] = p;
    }
  }
  
  bra_nbr_historyitems--;

  return TRUE;
}

static int
bra_rpl_remove_history_item_idx(int idx)
{
  bra_rpl_history_item_t *p;
  int j;

  if ((idx < 0) || (idx >= bra_nbr_historyitems))
    return FALSE;

  p = bra_rpl_history_list[idx];

  if (p->title)
    BRA_FREE(p->title);
  if (p->url)
    BRA_FREE(p->url);

  p->url   = NULL;
  p->title = NULL;

  bra_file_delete_block (bra_rpl_history_file, p->file_idx , NULL);

  if (idx < (bra_nbr_historyitems-1) )
  {
    for (j=idx; j < (bra_nbr_historyitems - 1); j++)
    {
      p = bra_rpl_history_list[j];
      bra_rpl_history_list[j] = bra_rpl_history_list[j+1];
      bra_rpl_history_list[j+1] = p;
    }
  }
  
  bra_nbr_historyitems--;

  return TRUE;
}

static void
bra_rpl_delete_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    bra_cmn_deleted_dialog();
    msf_rpl_delete_selected();
  }
}

static void
bra_rpl_delete_all_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    bra_win_close_window (BRA_WIN_CLOSE_ID, BRA_WIN_ID_RPL_MAIN);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DELETING, MsfInfo, 5000);
    bra_rpl_clear_history_list();
    bra_rpl_create_rpl_menu(1);
  }
}


static void
bra_rpl_delete_opt_menu (bra_win_t *win)
{
  bra_rpl_menu_t *p;
  p = (bra_rpl_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

static void 
bra_rpl_action_opt_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  int i;
  bra_rpl_menu_t *p, *main;
  int items;
  int start_item;

  main = (bra_rpl_menu_t *)bra_win_get_window(BRA_WIN_ID_RPL_MAIN);
  p = (bra_rpl_menu_t *)win;

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 0) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Goto */
      start_item = (bra_nbr_historyitems - (BRA_RPL_ITEMS_PER_PAGE * bra_rpl_n_pages_displayed));
      items = MIN (BRA_RPL_ITEMS_PER_PAGE, start_item); 
      for (i=0; i<items; i++)
      {
        if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(main->window, i) & MSF_CHOICE_ELEMENT_SELECTED) 
        {
          bra_send_request(bra_rpl_history_list[start_item - i - 1]->url);

          bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
          return;
        }
      }
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 1) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* View */
      bra_rpl_ceate_rpl_view();
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 2) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete */
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_rpl_delete_confirmation);      
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 3) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* Delete All */
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ALL_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_rpl_delete_all_confirmation);      
    }
  }
}

static void
bra_rpl_create_opt_menu (void)
{
  bra_rpl_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_rpl_menu_t);

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

   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_GOTO,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_VIEW_URL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_DELETE_ALL,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->window, i, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   i++;

   //MSF_WIDGET_SET_TITLE(win->window,BRA_STR_RECENT_PAGES);
    MSF_WIDGET_SET_TITLE(win->window,BRA_STR_OPTIONS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
   bra_win_show_window (BRA_WIN_ID_RPL_OPT, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_rpl_delete_opt_menu, 
                    NULL,
                    bra_rpl_action_opt_menu);
}

/*
 * Create view rpl url dialog
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
static void bra_rpl_ceate_rpl_view(void)
{
  bra_win_t               *win;
  kal_uint8               *text = NULL;
  ctk_screen_handle	      scrid;
  MsfPosition	          pos =  {0, 0 /*20*/};
  int                     start_item;
  int                     items;
  int                     i;
  bra_rpl_menu_t          *rpl_main_win;

  rpl_main_win = (bra_rpl_menu_t *)(bra_win_get_window (BRA_WIN_ID_RPL_MAIN));

  if (rpl_main_win == NULL)
    return;

  win = BRA_ALLOCTYPE (bra_win_t);
  /*Set all members to 0*/
  memset (win, 0, sizeof (bra_win_t));

  /* Prepare text */
  start_item = (bra_nbr_historyitems - (BRA_RPL_ITEMS_PER_PAGE * bra_rpl_n_pages_displayed));
  items = MIN (BRA_RPL_ITEMS_PER_PAGE, start_item); 

  for (i = 0; i < items; i++)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(rpl_main_win->window, i) & MSF_CHOICE_ELEMENT_SELECTED) 
    {
      int text_size;
      text_size = strlen(bra_rpl_history_list[start_item - i - 1]->url);
      text_size = text_size * 2 + 2;
      text = BRA_ALLOC(text_size);
      widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) bra_rpl_history_list[start_item - i - 1]->url);
      break;
    }
  }

  /*Create Form*/
  if (i != items)
  {
    win->win_hdl = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, text, 
      									(MSF_UINT16)BRA_STR_ID_VIEW_URL, 0); 
    BRA_FREE(text); // release the text
  }
  else
  {
    win->win_hdl = HDIa_widgetExtCreateTextView(MSF_MODID_BRA, (kal_uint8*)"", 
      									(MSF_UINT16)BRA_STR_ID_VIEW_URL, 0); 
  }
  
  /* Set Key */
  scrid = HDIa_widgetCtkGetScreenHandle(win->win_hdl);

  ctk_screen_addLSK_UA(scrid, STR_GLOBAL_OK, IMG_GLOBAL_OK, NULL, bra_rpl_view_back, KAL_TRUE);

  bra_win_show_window (BRA_WIN_ID_RPL_VIEW_URL, 
                      (bra_win_t*)win, 
                      (MsfPosition*)&pos, 
                      bra_rpl_delete_rpl_view, 
                      NULL,
                      NULL);
}

/*
 * Cleans up rpl view
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
static void
bra_rpl_delete_rpl_view(bra_win_t *win)
{
  MSF_WIDGET_REMOVE (bra_win_get_screen (), win->win_hdl); 

  MSF_WIDGET_RELEASE (win->win_hdl); 

  BRA_FREE (win);
}

/*
 * Back to option menu from view dialog
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
static void
bra_rpl_view_back(ctk_screen_handle scrid)
{
  CTK_UNUSED(scrid);
  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
}

/*
 * Cleans up when selecting an item in the menu.
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
static void 
bra_rpl_action_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_rpl_menu_t *p;

  p = (bra_rpl_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    bra_rpl_create_opt_menu();
  }
}

/*
 * Cleans up after closing a menu.
 *
 * PARAMETERS
 *
 * RETURN    : 
 */
static void 
bra_rpl_delete_menu(bra_win_t *win)
{
  bra_rpl_menu_t *p;
    
  if (bra_rpl_n_pages_displayed == 0)
    bra_rpl_activate_key_events (FALSE);
  else
    bra_rpl_n_pages_displayed--;

  bra_rpl_hilite_index = -1;

  p = (bra_rpl_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

static void
msf_rpl_delete_selected (void)
{
  int start_item;
  int items;
  int i;
  int is_first_page;
  bra_rpl_menu_t *win;

  win = (bra_rpl_menu_t *)(bra_win_get_window (BRA_WIN_ID_RPL_MAIN));

  if (win == NULL)
    return;
  
  
  start_item = (bra_nbr_historyitems - (BRA_RPL_ITEMS_PER_PAGE * bra_rpl_n_pages_displayed));
  items = MIN (BRA_RPL_ITEMS_PER_PAGE, start_item); 
  
  for (i=0; i<items; i++)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(win->window, i) & MSF_CHOICE_ELEMENT_SELECTED) 
    {
      is_first_page = ((bra_rpl_n_pages_displayed == 0) ? TRUE : FALSE);
      bra_rpl_remove_history_item_idx (start_item - i - 1);
      bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

      if ((items - 1) < 1)
      {
        is_first_page = ((bra_rpl_n_pages_displayed == 0) ? TRUE : FALSE);

        if (bra_nbr_historyitems > 0)
        {
          bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        }
      }
     bra_rpl_hilite_index = (i>=items-1?i-1:i);
     bra_rpl_create_rpl_menu (is_first_page);
     return;
    }
  }
}

static void 
bra_rpl_clear_rpi_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    msf_rpl_delete_selected ();
  }
}

void
bra_rpl_handle_user_evt (MSF_UINT32 handle, MsfEvent evt)
{
  MsfScreenHandle screen;

  screen = bra_win_get_screen ( );

  if (screen == 0)
    return;
  
  if ((screen != handle) || evt.eventClass != MsfRelease)
    return;

  if (evt.eventType != MsfKey_Clear) 
    return;

  bra_dlg_create_dlg (MsfConfirmation,
        BRA_STR_DELETE_ASK, 
        BRA_STR_OK, 
        BRA_STR_CANCEL,
        0, 
        bra_rpl_clear_rpi_confirmation);

}



