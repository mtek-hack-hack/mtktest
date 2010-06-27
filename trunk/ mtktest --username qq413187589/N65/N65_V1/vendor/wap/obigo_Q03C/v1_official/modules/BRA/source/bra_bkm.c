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
 * bra_bkm.c
 *
 * Created by Tomas Mandorf	20020826	09:31
 *
 * Revision  20020826:
 *			20020826	Tomas Mandorf	Created
 * 
 * Description:
 *		This file contains code to make the Bookmarks menu-
 *
 */

#include "bra_cfg.h"
#include "bra_win.h"
#include "bra_cmn.h"
#include "bra_dlg.h"
#include "bra_bkm.h"
#include "bra_main.h"
#include "bra_req.h"
#include "bra_sig.h"
#include "bra_inse.h"
#include "bra_prof.h"
#include "bra_str.h"
#include "bra_file.h"
#include "bra_if.h"

#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif


#include "msf_int.h"
#include "msf_lib.h" 
#include "msf_file.h"
#include "msf_core.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#include "widget.h"
#endif
#include "wapadp.h"
#include "msf_chrs.h"
#include "msf_log.h"

/*****************************************************************************
 * Local Defines
 *****************************************************************************/
#define BRA_BKM_MAX_FILE_SIZE   31000 
#define BRA_BKM_INITIAL_SIZE    BRA_CFG_BKM_INITIAL_SIZE/*1000*/
#define BRA_BKM_DEFRAG_LIMIT    5000
#define BRA_BKM_SIZE_INCREMENT  2000/*1000*/

#define BRA_BKM_HEADERS_LENGTH   7   /*5 = 1 byte title length + 2 bytes url 
                                           length + 4 bytes sort index*/

/*This define is used to generate a compile error if the total bookmark size is to large.*/
//#if (((BRA_CFG_MAX_NBR_CHARS_URL + BRA_CFG_MAX_NBR_CHARS_TITLE + BRA_BKM_HEADERS_LENGTH + BRA_FILE_BLOCK_HEADER_SIZE) * BRA_CFG_MAX_NBR_BOOKMARKS) > BRA_BKM_MAX_FILE_SIZE)
//  #error "Error: Bookmark file size is to small. The configured number of bookmarks might not fit within the maximum file size."
//#endif

#if ((BRA_CFG_MAX_NBR_CHARS_URL + BRA_CFG_MAX_NBR_CHARS_TITLE) > BRA_BKM_SIZE_INCREMENT)
#error "Error: The total size of one bookmark is larger than the file increment size."
#endif

/*****************************************************************************
 * Local Types
 *****************************************************************************/
typedef enum
{
  BRA_BKM_STATE_NULL,
  BRA_BKM_STATE_LOAD_REQUEST,
  BRA_BKM_STATE_EDIT_GET_REQUEST,
  BRA_BKM_STATE_SELECT_REQUEST,
  BRA_BKM_STATE_SEND_REQUEST
}bra_bkm_state_t;

typedef struct bra_bkm_item{
  int   sort_idx;   /*Index when displayed*/
  int   idx;        /*Index in file*/
  MSF_INT32 title;
  struct bra_bkm_item *next;
}bra_bkm_item_t;

typedef struct {
  MSF_UINT32   sort_idx;   /*Created time to be used as sorting value*/
  char *title;
  char *url;
}bra_bkm_file_item_t;

/*Bookmarks main menu*/
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;  
} bra_bkm_menu_t;


/*****************************************************************************
 * Function prototypes
 *****************************************************************************/
static void
bra_bkm_update_menu_items (bra_bkm_menu_t *win);

static int 
bra_bkm_title_url_manage_response(char* title, char* url);

/*Main Menu*/
static void
bra_bkm_delete_bkm_menu(bra_win_t *win);

static void
bra_bkm_in_focus(bra_win_t *win);

static void
bra_bkm_widget_action_bkm_menu(bra_win_t *win, MSF_UINT32 bra_action);

static int
bra_bkm_calc_num_send_apps(void);

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
#endif

/*Manage Bookmarks Menu*/
static void 
bra_bkm_create_manage_bookmarks_menu(void);

static void
bra_bkm_widget_action_manage_bkm_menu(bra_win_t *win, MSF_UINT32 bra_action);

static void
bra_bkm_delete_manage_bkm_menu(bra_win_t *win);

static void
bra_bkm_create_send_menu(void);

static void
bra_bkm_select_bookmark_reply(MSF_UINT8 result, MSF_UINT8 *title, MSF_UINT8 *url);

extern void wap_enter_sms_editor_handler(void *p);
extern void wap_enter_mms_editor_handler(void *p);
#ifdef __MMI_EMAIL__
extern void wap_enter_email_editor_handler(void *p);
#endif

extern pBOOL mmi_bootup_is_sim_valid(void);

extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
/*****************************************************************************
 * Variables
 *****************************************************************************/

static bra_bkm_state_t     bra_bkm_state;
static int                 bra_bkm_selected_bookmark;
static bra_bkm_item_t     *bra_bkm_list;              /*-List of bookmark titles*/ 
static int                 bra_bkm_n_items;           /*-Number of bookmarks    */                
static void               *bra_bkm_file_handle = NULL;
static int                 bra_bkm_is_select_and_reply = 0; /* select a bookmark and return info to caller module */
static int                 bra_bkm_reply_module = -1;
static bra_bkm_file_item_t bra_bkm_send_data;

/*
 * The following variables are used to identify the "add bokmark" and 
 * "manage bookmark" menu items when an item in the menu have been selected
 */
                 
/*****************************************************************************
 * Functions
 *****************************************************************************/

/*
 *  Adds a bookmark item to list
 *
 *  Retruns 1 if ok, else 0
 *
 */
static int 
bra_bkm_add_bookmark_item (MSF_UINT32 sort_idx, int idx, MSF_INT32 title)
{
  bra_bkm_item_t *bkm_item;
  bra_bkm_item_t *p;
  bra_bkm_item_t *prev;

  bkm_item = BRA_ALLOCTYPE(bra_bkm_item_t);

  if(bkm_item == NULL)
    return 0;

  bkm_item->sort_idx = sort_idx;
  bkm_item->idx = idx;
  bkm_item->title = title;
  bkm_item->next = NULL;

  /*Increase number of bookmarks*/
  bra_bkm_n_items++;

  p = bra_bkm_list;
  prev = bra_bkm_list;

  if(p != NULL)
  {
    while (p != NULL)
    {
      if(p->sort_idx < bkm_item->sort_idx)
      {
        prev = p;
        p = p->next;
        continue;
      }

      if (p == bra_bkm_list)
      {
        bkm_item->next = bra_bkm_list;
        bra_bkm_list  = bkm_item;
      }
      else
      {
        prev->next = bkm_item;
        bkm_item->next = p;
      }
      return 1;
    }
    prev->next = bkm_item;
  }
  else
  {
    bra_bkm_list = bkm_item;
  }

  return 1;
}

static bra_bkm_item_t *
bra_bkm_remove_item(int idx)
{
  bra_bkm_item_t *remove;
  bra_bkm_item_t *previous;
  int i = 0;

  if(bra_bkm_list == NULL)
    return NULL; 
  
  /*Decrease number of bookmarks*/
  bra_bkm_n_items--;

  remove   = bra_bkm_list;
  previous = bra_bkm_list;
 
  while (remove != NULL)
  {
    if (i++ == idx)
    {
      if (remove == bra_bkm_list)
        bra_bkm_list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }

  return NULL;
}

static bra_bkm_item_t *
bra_bkm_get_item (int idx)
{  
  int i = 0;
  bra_bkm_item_t *bkm_item;

  bkm_item = bra_bkm_list;
  
  while ((i++ < idx) && (bkm_item != NULL))
  {
    bkm_item = bkm_item->next;
  }

  return bkm_item;
}

static void
bra_bkm_destroy_list()
{
  bra_bkm_item_t *remove;

  remove = bra_bkm_list;
  
  while (remove != NULL)
  {
    bra_bkm_list = remove->next;
    MSF_WIDGET_RELEASE  (remove->title);
    BRA_FREE (remove);
    remove = bra_bkm_list;
  }

  bra_bkm_n_items = 0;

}
/* Bookmarks file format
 *
 * All bookmarks are saved in one file. The file name is as defined by BRA_BKM_FILE_NAME. 
 * The bookmarks are saved as a sequence of bytes were each bookmark is saved as follows:
 *
 * Field                Bytes       Comment
 *
 * Sort Index           4           Time of creation to be used as sort index
 * Length of title      1           BYTE (unsigned char)
 * Title                0 - 0xFF    Lenth as specified by the above element 
 * Length of url        2           INT16 (short). Most significant byte first
 * Url                  0 - 0x7FFF  Lenth as specified by the above element
 *
 * Note: Title and url is not null terminated in the file.
 *
 * At start-up, BRA_BKM_BUFFER_SIZE bytes are read from file and all titles + the possition 
 * of the corresponding url is read into a list. This is repeated untill all bookmarks have
 * been read. The bra module will not call MSF_MODULE_IS_ACTIVE untill this is complete.
 *
 * 
 */
static unsigned char*
bra_bkm_create_buffer(MSF_UINT32 sort_idx, char *title, char* url, int *buf_len)
{
  unsigned char* buffer;
  int   l_title;
  int   l_url;

  l_title = strlen (title);
  l_url   = strlen (url);
  
  *buf_len = l_title + l_url + BRA_BKM_HEADERS_LENGTH;

  buffer = BRA_ALLOC (*buf_len); 

  buffer[0] = (unsigned char)(sort_idx >> 24);
  buffer[1] = (unsigned char)((sort_idx & 0x00FF0000) >> 16);
  buffer[2] = (unsigned char)((sort_idx & 0x0000FF00) >> 8);
  buffer[3] = (unsigned char)(sort_idx  & 0x000000FF);

  buffer[4] = (unsigned char)l_title;

  memcpy (&buffer[5], title, l_title);

  buffer[l_title + 5] = (unsigned char)(l_url >> 8);     /*Most significant byte first*/
  buffer[l_title + 6] = (unsigned char)(l_url & 0xFF);

  memcpy (&buffer[l_title + 7], url, l_url);

  return buffer;

}

static int 
bra_bkm_parse_bookmark_item (unsigned char *buffer, int size, bra_bkm_file_item_t* p)
{
  int   idx = 0;
  int   title_len;
  int   url_len;
 
  if (size < BRA_BKM_HEADERS_LENGTH)
    return -1;

  p->sort_idx =  (buffer[idx] << 24);
  idx++;
  p->sort_idx += (buffer[idx] << 16);
  idx++;
  p->sort_idx += (buffer[idx] << 8);
  idx++;
  p->sort_idx += (buffer[idx]);
  idx++;

  /*Get Title length*/
  title_len =  buffer[idx++];
  
  /*Check that title length is not longer than buffer*/
  if((title_len < 0) || (title_len > (size - idx)))
    return -1;
  
  /*Copy title*/
  p->title = BRA_ALLOC(title_len + 1);    
  memcpy(p->title, &buffer[idx], title_len);   
  p->title[title_len] = '\0'; 
  
  /*Step idx*/
  idx = idx + title_len;
  
  /*Get URL length*/
  url_len  = (buffer[idx++] << 8);
  url_len +=  buffer[idx++];
  
  /*Check that title length is not longer than buffer*/
  if((url_len < 0) || (url_len > (size - idx)))
  {
    BRA_FREE(p->title);
    return -1; /*tile length, title, and url length*/
  }
  
  /*Copy url*/
  p->url = BRA_ALLOC(url_len + 1);    
  memcpy(p->url, &buffer[idx], url_len);   
  p->url[url_len] = '\0'; 
  
  idx += url_len;
  
  return idx;

}

static void
bra_bkm_delete_response (int i)
{
  bra_bkm_menu_t *win;  

  win = (bra_bkm_menu_t *)(bra_win_get_window (BRA_WIN_ID_BKM_MAIN));
  
  if(win)
  {
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
    bra_bkm_update_menu_items(win);
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_BKM_MAIN);
  }

  bra_cmn_deleted_dialog();
}

static void 
bra_bkm_delete_all_response (int i)
{
  bra_bkm_menu_t *win;  

  win = (bra_bkm_menu_t *)(bra_win_get_window (BRA_WIN_ID_BKM_MAIN));
  
  if(win)
  {
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
    if(bra_bkm_n_items == 0)
    {
      bra_bkm_update_menu_items(win);
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_BKM_MAIN);
    }
  }

  if(bra_bkm_n_items == 0)
    bra_cmn_deleted_dialog();
}

static void 
bra_bkm_delete_bkm (int idx, bra_file_op_callback_t callback)
{
  bra_bkm_menu_t *win;
  bra_bkm_item_t *item;

  win = (bra_bkm_menu_t *)(bra_win_get_window (BRA_WIN_ID_BKM_MAIN));

  item = bra_bkm_remove_item (idx);

  if(item == NULL)
    return;

  bra_file_delete_block (bra_bkm_file_handle, item->idx , callback);

  MSF_WIDGET_RELEASE (item->title);
  BRA_FREE (item);

}

/*
 * Inserts list of bookmarks
 *
 * Parameters:
 *
 * window_hdl     :  handle to menu window
 * start_idx      :  Start index variable
 *
 * Returns the number of bookmarks added.
 */
static int 
bra_add_bookmarks_to_menu(MsfWindowHandle window_hdl, MSF_UINT16 start_idx)
{
  int        i;
  bra_bkm_item_t *bkm_list;
    
  i = start_idx;
  bkm_list = bra_bkm_list;

  while (bkm_list != NULL)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT(window_hdl, i, bkm_list->title, 0, bra_cmn_get_list_num_image(i), 0, 0);
    i++;
    bkm_list = bkm_list->next;
  }

  return i - start_idx;
}

static void
bra_bkm_update_menu (MSF_INT32 label)
{    
  bra_bkm_menu_t *win;
  
  win = (bra_bkm_menu_t *)(bra_win_get_window (BRA_WIN_ID_BKM_MAIN));

  if (win == NULL)
    return;

  if(bra_bkm_selected_bookmark >= 0)
    MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, 
                                  bra_bkm_selected_bookmark, 
                                  label, 
                                  0, 
                                  bra_cmn_get_list_num_image(bra_bkm_selected_bookmark), 
                                  0, 
                                  0);
  
  MSF_WIDGET_SET_IN_FOCUS (win->window, 1);
}

static void 
bra_bkm_load_bkm_response (void *handle, unsigned char* block, int size)
{
  MsfStringHandle ms;
  bra_bkm_file_item_t p;

  handle = handle;
  
  bra_bkm_parse_bookmark_item (block, size, &p);
  
  if (bra_bkm_state == BRA_BKM_STATE_LOAD_REQUEST)
  {
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
    bra_send_request(p.url);
  }
  else if (bra_bkm_state == BRA_BKM_STATE_EDIT_GET_REQUEST)
  {
    ms = BRA_STRCONV (p.title);
#ifdef BRA_USE_CTK_INLINE      
    bra_dlg_ctk_create_title_url_form (BRA_STR_ID_EDIT_BOOKMARK, 
                                       ms,
                                       p.url,
                                       bra_bkm_title_url_manage_response,
                                       BRA_WIN_ID_BKM_MAIN,
                                       FALSE,
                                       FALSE);
#else
    bra_dlg_create_title_url_form(BRA_STR_EDIT_BOOKMARK, 
                                  ms,
                                  p.url,
                                  bra_bkm_title_url_manage_response,
                                  BRA_WIN_ID_BKM_MAIN);
#endif
    MSF_WIDGET_RELEASE (ms);
  }
  else if (bra_bkm_state == BRA_BKM_STATE_SELECT_REQUEST)
  {
    bra_bkm_select_bookmark_reply(1, (MSF_UINT8*)(p.title), (MSF_UINT8*)(p.url));
    bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_bkm_state == BRA_BKM_STATE_SEND_REQUEST)
  {
    if (bra_bkm_send_data.title)
    {
      BRA_FREE(bra_bkm_send_data.title);
      bra_bkm_send_data.title = 0;
    }
    if (bra_bkm_send_data.url)
    {
      BRA_FREE(bra_bkm_send_data.url);
      bra_bkm_send_data.url = 0;
    }
    bra_bkm_send_data.title = msf_cmmn_strdup(MSF_MODID_BRA, p.title);
    bra_bkm_send_data.url = msf_cmmn_strdup(MSF_MODID_BRA, p.url);

    bra_bkm_create_send_menu();
  }

  BRA_FREE (p.url);
  BRA_FREE (p.title);

  BRA_FREE (block);
}

static void 
bra_bkm_load_selected_bkm(int idx, bra_bkm_state_t state)
{
  bra_bkm_item_t *bkm_item;

  bkm_item = bra_bkm_get_item(idx);

  if (bkm_item == NULL)
    return;

  bra_bkm_state = state;

  bra_file_read_block (bra_bkm_file_handle, bkm_item->idx, bra_bkm_load_bkm_response);
}

static void
bra_bkm_update_menu_items (bra_bkm_menu_t *win)
{
  if(bra_add_bookmarks_to_menu(win->window, 0) == 0)
  {
     /* Empty */
     MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, 0, BRA_STR_EMPTY_LIST, 0, bra_cmn_get_list_num_image(0), 0, 0);
  }

}

/*
 * This function initializes the bookmark list stored in ram.
 * 
 *
 * Parameters:
 *
 * file_handle    : handle to file opened for reading
 *
 * Return a positive value when finished.
 */

void 
bra_bkm_initialize_bookmarks (int idx, int eof, void* block, int size)
{
  bra_bkm_file_item_t p;
  MsfStringHandle title;

  if (eof == 0)
  {
    if (bra_bkm_parse_bookmark_item ((unsigned char *)block, size, &p) < 0)
      return;

    if ((p.title != NULL) && (*p.title != '\0'))
    {
      title = BRA_STRCONV (p.title);
    }
    else
    {
      title = BRA_STRCONV (p.url);
    }

    bra_bkm_add_bookmark_item (p.sort_idx, idx, title);

    BRA_FREE (p.title);
    BRA_FREE (p.url);
  }
  else
  {
    /*Finished*/
    bra_main_remove_module_state(BRA_BKM_INITIALIZING);
    bra_init_done ();
  }
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/

/*
 * This function initializes the bookmarks manager and reads the 
 * saved bookmarks from file.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_init (void)
{

  bra_bkm_list = NULL;
  bra_bkm_state = BRA_BKM_STATE_NULL;
  bra_bkm_n_items = 0;
    
  bra_main_set_module_state(BRA_BKM_INITIALIZING); 
    
  bra_file_init (BRA_CFG_BOOKMARK_FILE_PATH, 
                 &bra_bkm_file_handle, 
                 BRA_BKM_MAX_FILE_SIZE, 
                 BRA_BKM_INITIAL_SIZE, 
                 BRA_BKM_DEFRAG_LIMIT, 
                 BRA_BKM_SIZE_INCREMENT,
                 bra_bkm_initialize_bookmarks);

}

/*
 * Thsi function terminates the bookmark manager and releases all 
 * resources allocated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_destroy(void)
{
  bra_bkm_destroy_list();
  bra_file_close (bra_bkm_file_handle);
  bra_bkm_file_handle = NULL;

}


/******** BOOKMARK MAIN MENU FUNCTIONS ********/

/*
 * Creates the bookmarks menu.
 */

/*
 * This function creates and display the man bookmarks menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_bkm_create_bkm_menu(void)
{
  bra_bkm_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  /* It is not allowed to create bkm menu twice */
  if(bra_bkm_file_handle)
    return;

  /*Init bkm whenever create bkm menu*/
  bra_bkm_init();

  if (!bra_bkm_n_items && bra_bkm_is_select_and_reply) {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
    bra_bkm_select_bookmark_reply(0, 0, 0);
    bra_bkm_destroy();
    bra_bkm_selected_bookmark = -1;
    bra_bkm_is_select_and_reply = 0;
    bra_bkm_reply_module = -1;
    return;
  }

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_bkm_menu_t);

    if (bra_bkm_is_select_and_reply)
      win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfSelect,1, 0x8000);
    else
	  win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OPTIONS, MsfSelect,1, 0x8000);

	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
                                       &prop.displaySize ,
                                       win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

	MSF_WIDGET_SET_TITLE(win->window,BRA_STR_BOOKMARKS);
    if (bra_bkm_is_select_and_reply && bra_bkm_reply_module == -1)
    {
      MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,MSF_WINDOW_PROPERTY_TITLE|MSF_WINDOW_PROPERTY_EXT_IS_MESSAGE_APPLICATION);
    }
    else
    {
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,MSF_WINDOW_PROPERTY_TITLE);
    }

	MSF_WIDGET_ADD_ACTION(win->window, win->back);

  /*Add menu items*/
  bra_bkm_update_menu_items(win);

  bra_win_show_window (BRA_WIN_ID_BKM_MAIN, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_bkm_delete_bkm_menu, 
                      bra_bkm_in_focus,
                      bra_bkm_widget_action_bkm_menu);

  MSF_WIDGET_SET_IN_FOCUS (bra_win_get_screen(), 1);
}

/*
 * Handels the user input response
 *
 * NOTE This function must not open any new windows
 */
static void
bra_bkm_save_response (int i)
{
  i = i;
#ifdef BRA_USE_CTK_INLINE
  bra_cmn_saved_dialog();
#endif
}

/*
 * This function adds a new Bookmark to the list of bookmarks.
 *
 * PARAMETERS
 *
 * title     : Title of new Bookmark
 * url       : Url of new Bookmark
 *
 * RETURN    : 1 if successful, else 0
 */
int 
bra_bkm_add_new_bookmark(char* title, char* url)
{
  unsigned char *buffer;
  char *label;
  int   buf_len;
  MSF_UINT32 sort_idx;
  int  idx;
  MsfStringHandle str;
  bra_bkm_menu_t *win;

  if((title == NULL) || (url == NULL))
    return 0;

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;

  sort_idx = MSF_TIME_GET_CURRENT();
  buffer = bra_bkm_create_buffer(sort_idx, title, url, &buf_len);
   
  /*Update menu*/
  if (*title != '\0')
  {
    label = title;
  }
  else
  {
    label = url;
  }

  str = BRA_STRCONV (label);/*This handle is stored in list and removed later*/

  bra_bkm_update_menu (str);
 
  /*save bookmark*/
  idx = bra_file_write_block (bra_bkm_file_handle, 
                              buffer, 
                              buf_len, 
                              bra_bkm_save_response);
  BRA_FREE (buffer);
  
  /*Add to ram list*/
  bra_bkm_add_bookmark_item (sort_idx, idx, str);
    
  win = (bra_bkm_menu_t *)(bra_win_get_window (BRA_WIN_ID_BKM_MAIN));
  if(win)
  {
    bra_bkm_update_menu_items(win);
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (bra_bkm_n_items - 1), MSF_CHOICE_ELEMENT_SELECTED);
  }

  return 1;
}

int 
bra_bkm_offline_add_new_bookmark(char* title, char* url)
{
  unsigned char *buffer;
  int   buf_len;
  MSF_UINT32 sort_idx;
  int  idx;

  if((title == NULL) || (url == NULL))
    return 0;

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;

  if (strlen(url)>BRA_CFG_MAX_NBR_CHARS_URL)
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ERR_TITLE_URL_TOOLONG, MsfError, 0);
    return 0;
  }

  sort_idx = MSF_TIME_GET_CURRENT();
  buffer = bra_bkm_create_buffer(sort_idx, title, url, &buf_len);
   
  bra_file_init (BRA_CFG_BOOKMARK_FILE_PATH, 
                 &bra_bkm_file_handle, 
                 BRA_BKM_MAX_FILE_SIZE, 
                 BRA_BKM_INITIAL_SIZE, 
                 BRA_BKM_DEFRAG_LIMIT, 
                 BRA_BKM_SIZE_INCREMENT,
                 bra_bkm_initialize_bookmarks);

  /*save bookmark*/
  idx = bra_file_write_block (bra_bkm_file_handle, 
                              buffer, 
                              buf_len, 
                              bra_bkm_save_response);
  BRA_FREE (buffer);
  bra_file_close (bra_bkm_file_handle);
  bra_bkm_file_handle = NULL;
  
  return 1;
}


int 
bra_bkm_offline_add_new_bookmark_to_file(char* title, char* url)
{
  int             idx;
  int             buf_len;
  unsigned char   *buffer;
  MSF_UINT32      sort_idx;
    
    
  if((title == NULL) || (url == NULL))
    return 0;
    
  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;
    
  if (strlen(url) > BRA_CFG_MAX_NBR_CHARS_URL)
    return 0;
    
  if (!check_url(url) || !bra_cmn_url_is_valid(url))
    return 0;

  bra_file_init (BRA_CFG_BOOKMARK_FILE_PATH, 
                 &bra_bkm_file_handle, 
                 BRA_BKM_MAX_FILE_SIZE, 
                 BRA_BKM_INITIAL_SIZE, 
                 BRA_BKM_DEFRAG_LIMIT, 
                 BRA_BKM_SIZE_INCREMENT,
                 bra_bkm_initialize_bookmarks);

  if (TRUE == bra_bkm_is_full()) /*discard if bookmarks is full*/
  {
    bra_bkm_destroy();
    return 0;
  }

  sort_idx = MSF_TIME_GET_CURRENT();
  buffer = bra_bkm_create_buffer(sort_idx, title, url, &buf_len);
    
  /*save bookmark*/
  idx = bra_file_write_block (bra_bkm_file_handle, buffer, buf_len, NULL);  /*show nothing*/

  BRA_FREE (buffer);
  bra_bkm_destroy();
  return 1;
}



/*
 * Handles bookmark main menu events
 */
static void
bra_bkm_widget_action_bkm_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_bkm_menu_t *p;
  int i = 0; 

  p = (bra_bkm_menu_t *)(win);

  if (bra_action == p->back)
	{
        if (bra_bkm_is_select_and_reply)
          bra_bkm_select_bookmark_reply(0, 0, 0);
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
	}
  else if (bra_action == p->accept)
  {
    int opt_item = (bra_bkm_n_items == 0)?1:bra_bkm_n_items;
    while(i < opt_item && !(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i) & MSF_CHOICE_ELEMENT_SELECTED))
      i++;
    if(i == opt_item)
      return;
    bra_bkm_selected_bookmark = i;

    if (bra_bkm_is_select_and_reply)
      bra_bkm_load_selected_bkm(bra_bkm_selected_bookmark, BRA_BKM_STATE_SELECT_REQUEST);
    else
      bra_bkm_create_manage_bookmarks_menu ();
  }
}

/*
 * Destoys the bookmark main menu
 */
static void
bra_bkm_delete_bkm_menu (bra_win_t *win)
{
  bra_bkm_menu_t *p;
  p = (bra_bkm_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

  bra_bkm_destroy();
  bra_bkm_selected_bookmark = -1;
  bra_bkm_is_select_and_reply = 0;
  bra_bkm_reply_module = -1;
}

/*
 * Focus the bookmark main menu
 */
static void
bra_bkm_in_focus(bra_win_t *win)
{
  if(bra_bkm_selected_bookmark >= 0)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->win_hdl, bra_bkm_selected_bookmark, MSF_CHOICE_ELEMENT_SELECTED);
}

/******** END BOOKMARK MAIN MENU FUNCTIONS ********/


/******** SELECT BOOKMARK MENU FUNCTIONS ********/

/*
 * Creates the select bookmark for editing menu.
 */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/******** END BOOKMARK SELECT MENU FUNCTIONS ********/


/******** SELECT BOOKMARK MANAGE MENU FUNCTIONS ********/

/*
 * Creates the Manage menu for the selected bookmark.
 */

static void 
bra_bkm_create_manage_bookmarks_menu(void)
{
  bra_bkm_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_bkm_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,
                                                              MsfSelect,1, 0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,
                                                            MsfBack,1, 0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
                                       &prop.displaySize,
                                       win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

  /*Add menu items*/
   if(bra_bkm_n_items > 0)
   {
     int i = 0;
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_GOTO,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;                                   
     HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_EDIT,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;                                   
     HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
     if (bra_bkm_calc_num_send_apps() > 0) {
	   MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_SEND,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
       i++;                                   
       HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
     }
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_DELETE,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
     HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_DELETE_ALL,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;
     HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_ADD_BOOKMARK,  
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
     i++;                                   
     HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   }
   else
   {
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   0, 
                                   BRA_STR_ADD_BOOKMARK,  
                                   0, bra_cmn_get_list_num_image(0), 0, TRUE);
   }

	MSF_WIDGET_SET_TITLE(win->window,BRA_STR_MANAGE_BKM);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,(int) /*MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW |*/ MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->window, win->back);

  bra_win_show_window (BRA_WIN_ID_BKM_MANAGE, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_bkm_delete_manage_bkm_menu, 
                      NULL,
                      bra_bkm_widget_action_manage_bkm_menu);

}


/*
 * Handels the user edit bookmark response
 *
 * NOTE This function must not open any new windows
 */
void
bra_bkm_save_edit_response (int i)
{
  i = i;
#ifdef BRA_USE_CTK_INLINE
  bra_cmn_saved_dialog();
#endif
}

static int 
bra_bkm_title_url_manage_response(char* title, char* url)
{
  MsfStringHandle str;
  unsigned char *buffer;
  char *label;
  int size;
  MSF_UINT32 sort_idx;
  int  idx;

  
  if((title == NULL) || (url == NULL))
    return 0;

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;

  sort_idx = bra_bkm_get_item(bra_bkm_selected_bookmark)->sort_idx;
  buffer = bra_bkm_create_buffer(sort_idx, 
                                 title, 
                                 url, 
                                 &size);
  /*Update menu*/
  if (*(title) != '\0')
  {
    label = title;
  }
  else
  {
    label = url;
  }

  str = BRA_STRCONV (label);/*This handle is stored in list and removed later*/

  bra_bkm_update_menu (str);

  /*Remove old bookmark*/
  bra_bkm_delete_bkm (bra_bkm_selected_bookmark, NULL);  

 /*Save new bookmark*/
  idx = bra_file_write_block (bra_bkm_file_handle, buffer, size, bra_bkm_save_edit_response);
  BRA_FREE (buffer);
  
  /*Add new bookmark to ram list*/
  bra_bkm_add_bookmark_item (sort_idx, idx, str);

  return 1;
}  

static void 
bra_bkm_delete_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_bkm_delete_bkm(bra_bkm_selected_bookmark, bra_bkm_delete_response);
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_BKM_MAIN);
  }

}

static void 
bra_bkm_delete_all_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    MSF_INT8 i, total = bra_bkm_n_items;
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DELETING, MsfInfo, 5000);
    for(i = total - 1; i >= 0 ; i--)
    {
      if(i > 0)
        bra_bkm_delete_bkm(i, bra_bkm_delete_all_response);
      else
        bra_bkm_delete_bkm(i, bra_bkm_delete_all_response);
    }
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_BKM_MAIN);
  }
}

/*
 * Handles manage bookmarks menu events
 */
static void
bra_bkm_widget_action_manage_bkm_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_bkm_menu_t *p;
  int i = 0;
  p = (bra_bkm_menu_t *)(win);

  if (bra_action == p->back)
  {
      bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    if(bra_bkm_n_items > 0)
    {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Load*/
      bra_bkm_load_selected_bkm(bra_bkm_selected_bookmark, BRA_BKM_STATE_LOAD_REQUEST);
    }
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Edit*/
      bra_bkm_load_selected_bkm(bra_bkm_selected_bookmark, BRA_BKM_STATE_EDIT_GET_REQUEST);
    }
    else if (bra_bkm_calc_num_send_apps()>0 && MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Send*/
      bra_bkm_load_selected_bkm(bra_bkm_selected_bookmark, BRA_BKM_STATE_SEND_REQUEST);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Delete*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_bkm_delete_confirmation);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Delete All*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DELETE_ALL_ASK, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_bkm_delete_all_confirmation);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      bra_cmn_addr_t* addr;

      /*Add Bookmark*/
      if (bra_bkm_n_items >= BRA_CFG_MAX_NBR_BOOKMARKS)
      {
        bra_dlg_create_dlg (MsfError,
                            BRA_STR_ERR_BKM_FULL, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
 
        return;
      }

      /* reset selected bookmark */
      bra_bkm_selected_bookmark = -1;

      addr = bra_cmn_get_current_page ();
#ifdef BRA_USE_CTK_INLINE      
      bra_dlg_ctk_create_title_url_form (BRA_STR_ID_ADD_BOOKMARK, 
                                    addr->title,
                                    addr->url,
                                    bra_bkm_add_new_bookmark,
                                    BRA_WIN_ID_BKM_MAIN,
                                    TRUE,
                                    FALSE);
#else
      bra_dlg_create_title_url_form(BRA_STR_ADD_BOOKMARK, 
                                    addr->title,
                                    addr->url,
                                    bra_bkm_add_new_bookmark,
                                    BRA_WIN_ID_BKM_MAIN);
#endif
    }
    }
    else
    {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 0) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      bra_cmn_addr_t* addr;

      /* reset selected bookmark */
      bra_bkm_selected_bookmark = -1;

      /*Add bookmark*/
      addr = bra_cmn_get_current_page ();
#ifdef BRA_USE_CTK_INLINE
      bra_dlg_ctk_create_title_url_form(BRA_STR_ID_ADD_BOOKMARK, 
                                    addr->title,
                                    addr->url,
                                    bra_bkm_add_new_bookmark,
                                    BRA_WIN_ID_BKM_MAIN,
                                    TRUE,
                                    FALSE);            
#else
      bra_dlg_create_title_url_form(BRA_STR_ADD_BOOKMARK, 
                                    addr->title,
                                    addr->url,
                                    bra_bkm_add_new_bookmark,
                                    BRA_WIN_ID_BKM_MAIN);            
#endif
    }
    }
  }
}

/*
 * Destoys the manage bookmarks menu
 */
void
bra_bkm_delete_manage_bkm_menu (bra_win_t *win)
{
  bra_bkm_menu_t *p;
  p = (bra_bkm_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

  MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  if (bra_bkm_send_data.title)
  {
    BRA_FREE(bra_bkm_send_data.title);
    bra_bkm_send_data.title = 0;
  }
  if (bra_bkm_send_data.url)
  {
    BRA_FREE(bra_bkm_send_data.url);
    bra_bkm_send_data.url = 0;
  }

  BRA_FREE (p);
}


/******** END BOOKMARK BOOKMARK MANAGE MENU FUNCTIONS ********/

static bra_bkm_file_item_t temp_bkm;

static void 
bra_bkm_get_bkm_response(void *handle, unsigned char* block, int size)
{
  bra_bkm_parse_bookmark_item (block, size, &temp_bkm);
}

int bra_bkm_get_bkm(int idx, char *title, char *url)
{
  bra_bkm_item_t *bkm_item;

  bkm_item = bra_bkm_get_item(idx);

  if (bkm_item == NULL)
    return 0;

  bra_file_read_block (bra_bkm_file_handle, bkm_item->idx, bra_bkm_get_bkm_response);
  
  strcpy(title, (const char*)temp_bkm.title);
  strcpy(url, (const char*)temp_bkm.url); 

  return 1;
}

int bra_bkm_get_bkm_total_num(void)
{
  int        i = 0;
  bra_bkm_item_t *bkm_list;
    
  bkm_list = bra_bkm_list;

  while (bkm_list != NULL)
  {
    i++;
    bkm_list = bkm_list->next;
  }

  return i;
}

void
bra_bkm_create_offline_add_bookmark_form(char* url)
{
  MsfStringHandle title = BRA_STRCONV (BRA_CMN_HNV (NULL));
  bra_bkm_create_offline_add_bookmark_form_with_title(title, url, -1);
  MSF_WIDGET_RELEASE(title);
}

void
bra_bkm_create_offline_add_bookmark_form_with_title(MsfStringHandle title, char *url, int close_to_id)
{
  bra_bkm_init();

  if (bra_bkm_n_items >= BRA_CFG_MAX_NBR_BOOKMARKS)
  {
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_ERR_BKM_FULL, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);

    bra_bkm_destroy();
    return;
  }
  
  bra_bkm_destroy();
  
#ifdef BRA_USE_CTK_INLINE
  bra_dlg_ctk_create_title_url_form(BRA_STR_ID_ADD_BOOKMARK, 
                                    title,
                                    url,
                                    bra_bkm_offline_add_new_bookmark,
                                    close_to_id,
                                    TRUE,
                                    bra_win_get_window(BRA_WIN_ID_OPT) == NULL? TRUE : FALSE);            
#else
  bra_dlg_create_title_url_form(BRA_STR_ADD_BOOKMARK, 
                                    title,
                                    url,
                                    bra_bkm_offline_add_new_bookmark,
                                    close_to_id);            
#endif

}

int
bra_bkm_is_full(void)
{
  int isFull;

  if (bra_bkm_file_handle)
    return bra_bkm_n_items >= BRA_CFG_MAX_NBR_BOOKMARKS;

  bra_bkm_init();
  isFull = (bra_bkm_n_items >= BRA_CFG_MAX_NBR_BOOKMARKS);
  bra_bkm_destroy();

  return isFull;    
}

void
bra_bkm_create_select_bookmark(void *sig)
{
  bra_select_bookmark_t *param;
  param = (bra_select_bookmark_t*)sig;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_BKM_199D786145741C5DD8D956D23111DEDC, "bra_bkm_create_select_bookmark: srcModID = %d\n", param->srcModId));

  bra_bkm_is_select_and_reply = 1;
  if (param->srcModId == 0xFF)
    bra_bkm_reply_module = -1;
  else
    bra_bkm_reply_module = (int)(param->srcModId);

#ifdef BRA_CFG_DUAL_SIM
  bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif

  bra_bkm_create_bkm_menu();
}

static void
bra_bkm_send_select_bookmark_rsp_internal(MSF_UINT8 modid, MSF_UINT8 result, MSF_UINT8 *title, MSF_UINT8 *url)
{
  bra_select_bookmark_reply_t  param;
  msf_dcvt_t             cvt_obj;
  MSF_UINT16             length;
  void                  *signal_buffer, *user_data;

  param.result = result;
  param.title = (char*)title;
  param.url = (char*)url;

  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  msf_dcvt_uint8(&cvt_obj, &(param.result));
  msf_dcvt_string(&cvt_obj, &(param.title));
  msf_dcvt_string(&cvt_obj, &(param.url));
  length = (MSF_UINT16)cvt_obj.pos;

  signal_buffer = MSF_SIGNAL_CREATE (BRA_SIG_SELECT_BOOKMARK_REPLY, MSF_MODID_BRA,
                                     modid, length);

  if (signal_buffer != NULL) {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    msf_dcvt_uint8(&cvt_obj, &(param.result));
    msf_dcvt_string(&cvt_obj, &(param.title));
    msf_dcvt_string(&cvt_obj, &(param.url));
    MSF_SIGNAL_SEND (signal_buffer);
  }
}

static void
bra_bkm_select_bookmark_reply(MSF_UINT8 result, MSF_UINT8 *title, MSF_UINT8 *url)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_BKM_B7FAEC7898E54F0E881A2C49147B62AE, "bra_bkm_select_bookmark_reply: title=%s, url=%s\n", title, url));

  if (bra_bkm_is_select_and_reply)
  {
    if (bra_bkm_reply_module == -1)
    {
      extern void bra_send_select_bookmark_rsp_to_mmi(MSF_UINT8 result, MSF_UINT8 *title, MSF_UINT8 *url);
      bra_send_select_bookmark_rsp_to_mmi(result, title, url);
    }
    else
    {
      /* send reply to other modules within Obigo scope */
      bra_bkm_send_select_bookmark_rsp_internal((MSF_UINT8)bra_bkm_reply_module, result, title, url);
    }
  }  
}

static void
bra_bkm_delete_send_menu(bra_win_t *win)
{
  bra_bkm_menu_t *p;
  p = (bra_bkm_menu_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

  MSF_WIDGET_RELEASE (p->window); 
  MSF_WIDGET_RELEASE (p->accept);
  MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

static void
bra_bkm_action_send_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_bkm_menu_t *p;
  int i = 0;
  p = (bra_bkm_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
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
      smsdata->content = msf_cmmn_strdup(MSF_MODID_WIDGET, bra_bkm_send_data.url);

      bra_destroy_ui();
      widget_execute_MMI_p(wap_enter_sms_editor_handler, (void*)smsdata, FALSE);
    }
#ifdef BRA_CONFIG_MMS
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /* MMS */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
      wap_message_editor_t *mmsdata;

      mmsdata = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, wap_message_editor_t);
      memset((S8*)mmsdata, 0, sizeof(wap_message_editor_t));
      mmsdata->content = msf_cmmn_strdup(MSF_MODID_WIDGET, bra_bkm_send_data.url);

      bra_destroy_ui();
      widget_execute_MMI_p(wap_enter_mms_editor_handler, (void*)mmsdata, FALSE);
#else
      extern void MEAc_startWithTextInserted(char *subject, char *text, MSF_BOOL isTruncated);
      char *url;
      long srcLen, dstLen;

      srcLen = msf_cmmn_utf8_strlen(bra_bkm_send_data.url);
      dstLen = (srcLen + 1) * 2;
      url = BRA_ALLOC(dstLen);

      memset(url, 0, dstLen);
      msf_charset_utf8_to_ucs2le(bra_bkm_send_data.url, &srcLen, url, &dstLen);

      bra_destroy_ui();
      MEAc_startWithTextInserted(0, url, 0);
      BRA_FREE(url);
#endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
    }
#endif  /* BRA_CONFIG_MMS */

#ifdef __MMI_EMAIL__
    else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
        /* EMail*/
        wap_message_editor_t *emaildata;

        emaildata = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, wap_message_editor_t);
        memset((S8*)emaildata, 0, sizeof(wap_message_editor_t));
        emaildata->content = msf_cmmn_strdup(MSF_MODID_WIDGET, bra_bkm_send_data.url);

        bra_destroy_ui();
        widget_execute_MMI_p(wap_enter_email_editor_handler, (void*)emaildata, FALSE);
    }
#endif
    //else if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 1) & MSF_CHOICE_ELEMENT_SELECTED)
    //{
      /* Email */
      //bra_bkm_load_selected_bkm(bra_bkm_selected_bookmark, BRA_BKM_STATE_EDIT_GET_REQUEST);
    //}
  }
}

static void
bra_bkm_create_send_menu(void)
{
  bra_bkm_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  int i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_bkm_menu_t);

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
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                   i, 
                                   BRA_STR_VIA_SMS,
                                   0, bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
#ifdef BRA_CONFIG_MMS
  //HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                 i, 
                                 BRA_STR_VIA_MMS,
                                 0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
#endif  /* BRA_CONFIG_MMS */
  /*HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                 i, 
                                 BRA_STR_VIA_EMAIL,
                                 0, bra_cmn_get_list_num_image(i), 0, TRUE);*/
#ifdef __MMI_EMAIL__
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                 i, 
                                 BRA_STR_VIA_EMAIL,
                                 0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
#endif

  MSF_WIDGET_SET_TITLE(win->window,BRA_STR_MANAGE_BKM);
  MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,(int) /*MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW |*/ MSF_WINDOW_PROPERTY_TITLE);

  MSF_WIDGET_ADD_ACTION(win->window, win->back);

  bra_win_show_window(BRA_WIN_ID_BKM_SEND_MENU, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_bkm_delete_send_menu, 
                      NULL,
                      bra_bkm_action_send_menu);
}

static int
bra_bkm_calc_num_send_apps(void)
{
  int numSendApps = 0;

/*  if (!mmi_bootup_is_sim_valid())
    return 0;
*/

  /* SIM inserted means SMS enabled */
  numSendApps++;

  /* check has MMS */
#ifdef BRA_CONFIG_MMS
  numSendApps++;
#endif

  return numSendApps;
}
