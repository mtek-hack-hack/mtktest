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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
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
 * bra_ofln.c
 *
 */

#include "bra_win.h"
#include "bra_cmn.h"
#include "bra_dlg.h"
#include "bra_main.h"
#include "bra_req.h"
#include "bra_sig.h"
#include "bra_inse.h"
#include "bra_prof.h"
#include "bra_str.h"
#include "bra_file.h"
#include "bra_ofln.h"
#include "bra_sif.h"
#include "bra_view.h"
#include "msf_int.h"
#include "msf_lib.h" 
#include "msf_file.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#endif

#ifdef BRA_CFG_OFFLINE_PAGES
/*****************************************************************************
 * Local Defines
 *****************************************************************************/
#define BRA_OFLN_MAX_FILE_SIZE   31000 
#define BRA_OFLN_INITIAL_SIZE    3000
#define BRA_OFLN_DEFRAG_LIMIT    5000
#define BRA_OFLN_SIZE_INCREMENT  2000
#define BRA_OFFLINE_PAGE_FILE_PATH   "/bra/offline.dat"
#define BRA_MAX_NBR_OFFLINE_PAGES 10

#define BRA_OFLN_HEADERS_LENGTH   7   /*5 = 1 byte title length + 2 bytes url 
                                           length + 4 bytes sort index*/

/*****************************************************************************
 * Local Types
 *****************************************************************************/
typedef enum
{
  BRA_OFLN_STATE_NULL,
  BRA_OFLN_STATE_LOAD_REQUEST,
  BRA_OFLN_STATE_DELETE_REQUEST,
  BRA_OFLN_STATE_SAVE_REQUEST,
  BRA_OFLN_STATE_UPDATE_REQUEST
}bra_ofln_state_t;

typedef struct bra_ofln_item{
  int   sort_idx;   /*Index when displayed*/
  int   idx;        /*Index in file*/
  MSF_INT32 title;
  char  *url;
  struct bra_ofln_item *next;
}bra_ofln_item_t;

typedef struct {
  MSF_UINT32   sort_idx;   /*Created time to be used as sorting value*/
  char *title;
  char *url;
}bra_ofln_file_item_t;

typedef struct bra_ofln_item_to_delete{
    char  *url;
    struct bra_ofln_item_to_delete *next;
}bra_ofln_item_to_delete_t;

/*offline page main menu*/
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;  
} bra_ofln_menu_t;


/*****************************************************************************
 * Function prototypes
 *****************************************************************************/
static void
bra_ofln_update_menu_items (bra_ofln_menu_t *win);

static void 
bra_ofln_load_ofln_response (void *handle, unsigned char* block, int size);

extern pBOOL mmi_usb_is_in_mass_storage_mode(void);

/*****************************************************************************
 * Variables
 *****************************************************************************/

static bra_ofln_state_t    bra_ofln_state;
static int                 bra_ofln_selected_ofln;
static bra_ofln_item_t     *bra_ofln_list;              /*-List of offline page titles*/ 
static bra_ofln_item_to_delete_t    *bra_ofln_list_toDelete;     /*-List of offline pages to be deleted*/ 
static int                 bra_ofln_n_items;           /*-Number of offlien pages    */                
static void                *bra_ofln_file_handle = NULL;
static int                 bra_ofln_mode = 0;
                                              
/*
 * The following variables are used to identify the "add offline page" and 
 * "manage offline page" menu items when an item in the menu have been selected
 */
                 
/*****************************************************************************
 * Functions
 *****************************************************************************/

/*
 *  Adds a offline page item to list
 *
 *  Retruns 1 if ok, else 0
 *
 */
static int 
bra_ofln_add_ofln_item (MSF_UINT32 sort_idx, int idx, MSF_INT32 title, char* url)
{
  bra_ofln_item_t *ofln_item;
  bra_ofln_item_t *p;
  bra_ofln_item_t *prev;

  ofln_item = BRA_ALLOCTYPE(bra_ofln_item_t);

  if(ofln_item == NULL)
    return 0;

  ofln_item->sort_idx = sort_idx;
  ofln_item->idx = idx;
  ofln_item->title = title;
  ofln_item->url = url;
  ofln_item->next = NULL;

  /*Increase number of offline pages*/
  bra_ofln_n_items++;

  p = bra_ofln_list;
  prev = bra_ofln_list;

  if(p != NULL)
  {
    while (p != NULL)
    {
      if(p->sort_idx < ofln_item->sort_idx)
      {
        prev = p;
        p = p->next;
        continue;
      }

      if (p == bra_ofln_list)
      {
        ofln_item->next = bra_ofln_list;
        bra_ofln_list  = ofln_item;
      }
      else
      {
        prev->next = ofln_item;
        ofln_item->next = p;
      }
      return 1;
    }
    prev->next = ofln_item;
  }
  else
  {
    bra_ofln_list = ofln_item;
  }

  return 1;
}

static bra_ofln_item_t *
bra_ofln_remove_item(int idx)
{
  bra_ofln_item_t *remove;
  bra_ofln_item_t *previous;
  int i = 0;

  if(bra_ofln_list == NULL)
    return NULL; 
  
  /*Decrease number of offline pages*/
  bra_ofln_n_items--;

  remove   = bra_ofln_list;
  previous = bra_ofln_list;
 
  while (remove != NULL)
  {
    if (i++ == idx)
    {
      if (remove == bra_ofln_list)
        bra_ofln_list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }

  return NULL;
}

static bra_ofln_item_t *
bra_ofln_get_item (int idx)
{  
  int i = 0;
  bra_ofln_item_t *ofln_item;

  ofln_item = bra_ofln_list;
  
  while ((i++ < idx) && (ofln_item != NULL))
  {
    ofln_item = ofln_item->next;
  }

  return ofln_item;
}

static bra_ofln_item_t *
bra_ofln_search_item_by_url (char* url)
{  
  bra_ofln_item_t *ofln_item;

  ofln_item = bra_ofln_list;
  
  while (ofln_item != NULL)
  {
    if(strcmp(ofln_item->url, url) == 0)
      return ofln_item;
    ofln_item = ofln_item->next;
  }

  return NULL;
}

static void
bra_ofln_destroy_list()
{
  bra_ofln_item_t *remove;

  remove = bra_ofln_list;
  
  while (remove != NULL)
  {
    bra_ofln_list = remove->next;
    MSF_WIDGET_RELEASE  (remove->title);
    BRA_FREE (remove->url);
    BRA_FREE (remove);
    remove = bra_ofln_list;
  }
  
  bra_ofln_n_items = 0;

}
/* offlien page url/title file format
 *
 * All offline pages are saved in one file. The file name is as defined by BRA_OFLN_FILE_NAME. 
 * The offlien pages are saved as a sequence of bytes were each offline page is saved as follows:
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
 * At start-up, BRA_OFLN_BUFFER_SIZE bytes are read from file and all titles + the possition 
 * of the corresponding url is read into a list. This is repeated untill all offline pages have
 * been read. The bra module will not call MSF_MODULE_IS_ACTIVE untill this is complete.
 *
 * 
 */
static unsigned char*
bra_ofln_create_buffer(MSF_UINT32 sort_idx, char *title, char* url, int *buf_len)
{
  unsigned char* buffer;
  int   l_title;
  int   l_url;

  l_title = strlen (title);
  l_url   = strlen (url);
  
  *buf_len = l_title + l_url + BRA_OFLN_HEADERS_LENGTH;

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
bra_ofln_parse_ofln_item (unsigned char *buffer, int size, bra_ofln_file_item_t* p)
{
  int   idx = 0;
  int   title_len;
  int   url_len;
 
  if (size < BRA_OFLN_HEADERS_LENGTH)
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
bra_ofln_delete_response (int i)
{
  bra_ofln_menu_t *win;  

  win = (bra_ofln_menu_t *)(bra_win_get_window (BRA_WIN_ID_OFLN_MAIN));
  
  if(win)
  {
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
    bra_ofln_update_menu_items(win);
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_OFLN_MAIN);
  }

  bra_cmn_deleted_dialog();
}

static void 
bra_ofln_delete_all_response(int i)
{
    bra_ofln_menu_t *win;  
    
    win = (bra_ofln_menu_t *)(bra_win_get_window (BRA_WIN_ID_OFLN_MAIN));
    
    if(win)
    {
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT (win->window, i);
        if(bra_ofln_n_items == 0)
        {
            bra_ofln_update_menu_items(win);
            bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_OFLN_MAIN);
        }
    }
    
    if(bra_ofln_n_items == 0)
        bra_cmn_deleted_dialog();
}

static void 
bra_ofln_delete_ofln (int idx, bra_file_op_callback_t callback)
{
  bra_ofln_menu_t *win;
  bra_ofln_item_t *item;

  win = (bra_ofln_menu_t *)(bra_win_get_window (BRA_WIN_ID_OFLN_MAIN));

  item = bra_ofln_remove_item (idx);

  if(item == NULL)
    return;

  bra_ofln_state = BRA_OFLN_STATE_DELETE_REQUEST;
  bra_file_read_block (bra_ofln_file_handle, item->idx, bra_ofln_load_ofln_response);

  bra_file_delete_block (bra_ofln_file_handle, item->idx , callback);

  MSF_WIDGET_RELEASE (item->title);
  BRA_FREE (item->url);
  BRA_FREE (item);

}

/*
 * Inserts list of offline page
 *
 * Parameters:
 *
 * window_hdl     :  handle to menu window
 * start_idx      :  Start index variable
 *
 * Returns the number of offline pages added.
 */
static int 
bra_add_ofln_to_menu(MsfWindowHandle window_hdl, MSF_UINT16 start_idx)
{
  int        i;
  bra_ofln_item_t *ofln_list;
    
  i = start_idx;
  ofln_list = bra_ofln_list;

  while (ofln_list != NULL)
  {
    MSF_WIDGET_CHOICE_SET_ELEMENT(window_hdl, i, ofln_list->title, 0, bra_cmn_get_list_num_image(i), 0, 0);
    i++;
    ofln_list = ofln_list->next;
  }

  return i - start_idx;
}

static void
bra_ofln_update_menu (MSF_INT32 label)
{    
  bra_ofln_menu_t *win;
  
  win = (bra_ofln_menu_t *)(bra_win_get_window (BRA_WIN_ID_OFLN_MAIN));

  if (win == NULL)
    return;

  if(bra_ofln_selected_ofln >= 0)
    MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, 
                                  bra_ofln_selected_ofln, 
                                  label, 
                                  0, 
                                  bra_cmn_get_list_num_image(bra_ofln_selected_ofln), 
                                  0, 
                                  0);
  
  MSF_WIDGET_SET_IN_FOCUS (win->window, 1);
}

static void 
bra_ofln_load_ofln_response (void *handle, unsigned char* block, int size)
{
  bra_ofln_file_item_t p;

  handle = handle;
  
  bra_ofln_parse_ofln_item (block, size, &p);
  
  if (bra_ofln_state == BRA_OFLN_STATE_LOAD_REQUEST)
  {
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);    
    bra_send_request(p.url);    
    /* reset bra_ofln_state to NULL until end of transaction */
  }
  else if(bra_ofln_state == BRA_OFLN_STATE_DELETE_REQUEST)
  {
    if (bra_sif_get_brs_status () != BRA_SIF_BRS_CREATED)
    {
        bra_ofln_item_to_delete_t *deleteItem;

        bra_sif_start_brs ();

        deleteItem = BRA_ALLOCTYPE(bra_ofln_item_to_delete_t);
        deleteItem->url = msf_cmmn_strdup(MSF_MODID_BRA, p.url);
        deleteItem->next = bra_ofln_list_toDelete;
        bra_ofln_list_toDelete = deleteItem;
        return;
    }
    BRSif_deleteOfflinePage(MSF_MODID_BRA, p.url);
    bra_ofln_state = BRA_OFLN_STATE_NULL;
  }  

  BRA_FREE (p.url);
  BRA_FREE (p.title);

  BRA_FREE (block);
}

static void 
bra_ofln_load_selected_ofln(int idx, bra_ofln_state_t state)
{
  bra_ofln_item_t *ofln_item;

  ofln_item = bra_ofln_get_item(idx);

  if (ofln_item == NULL)
    return;

  bra_ofln_state = state;

  bra_file_read_block (bra_ofln_file_handle, ofln_item->idx, bra_ofln_load_ofln_response);
}

static void
bra_ofln_update_menu_items (bra_ofln_menu_t *win)
{
  if(bra_add_ofln_to_menu(win->window, 0) == 0)
  {
     /* Empty */
     MSF_WIDGET_CHOICE_SET_ELEMENT(win->window, 0, BRA_STR_EMPTY_LIST, 0, bra_cmn_get_list_num_image(0), 0, 0);
  }

}

/*
 * This function initializes the offline page list stored in ram.
 * 
 *
 * Parameters:
 *
 * file_handle    : handle to file opened for reading
 *
 * Return a positive value when finished.
 */

static void 
bra_ofln_initialize_offline_pages (int idx, int eof, void* block, int size)
{
  bra_ofln_file_item_t p;
  MsfStringHandle title;

  if (eof == 0)
  {
    if (bra_ofln_parse_ofln_item ((unsigned char *)block, size, &p) < 0)
      return;

    if ((p.title != NULL) && (*p.title != '\0'))
    {
      title = BRA_STRCONV (p.title);
    }
    else
    {
      title = BRA_STRCONV (p.url);
    }

    bra_ofln_add_ofln_item (p.sort_idx, idx, title, p.url);

    BRA_FREE (p.title);
  }
}

/*
 * This function initializes the offline page manager and reads the 
 * saved offine pages url from file.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
static void 
bra_ofln_init (void)
{

  bra_ofln_list = NULL;
  bra_ofln_state = BRA_OFLN_STATE_NULL;
  bra_ofln_n_items = 0;  
  bra_ofln_list_toDelete = NULL;
        
  bra_file_init (BRA_OFFLINE_PAGE_FILE_PATH, 
                 &bra_ofln_file_handle, 
                 BRA_OFLN_MAX_FILE_SIZE, 
                 BRA_OFLN_INITIAL_SIZE, 
                 BRA_OFLN_DEFRAG_LIMIT, 
                 BRA_OFLN_SIZE_INCREMENT,
                 bra_ofln_initialize_offline_pages);

}

/*
 * Thsi function terminates the offline page manager and releases all 
 * resources allocated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
static void 
bra_ofln_destroy(void)
{
  bra_ofln_destroy_list();
  bra_file_close (bra_ofln_file_handle);
  bra_ofln_file_handle = NULL;

}

/*
 * Handels the user input response
 *
 * NOTE This function must not open any new windows
 */
static void
bra_ofln_save_response (int i)
{
  i = i;
#ifdef BRA_USE_CTK_INLINE
  bra_cmn_saved_dialog();
#endif
}

/*
 * This function adds a new offline page to the list of offline page.
 *
 * PARAMETERS
 *
 * title     : Title of new offline
 * url       : Url of new offline
 *
 * RETURN    : 1 if successful, else 0
 */
static int 
bra_ofln_add_new_ofln (char* title, char* url)
{
  unsigned char *buffer;
  char *label;
  int   buf_len;
  MSF_UINT32 sort_idx;
  int  idx;
  MsfStringHandle str;
  bra_ofln_menu_t *win;

  if((title == NULL) || (url == NULL))
    return 0;

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;  
      
  sort_idx = MSF_TIME_GET_CURRENT();
  buffer = bra_ofln_create_buffer(sort_idx, title, url, &buf_len);
   
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

  bra_ofln_update_menu (str);
 
  /*save offline page*/
  idx = bra_file_write_block (bra_ofln_file_handle, 
                              buffer, 
                              buf_len, 
                              bra_ofln_save_response);
  BRA_FREE (buffer);
  
  /*Add to ram list*/
  bra_ofln_add_ofln_item (sort_idx, idx, str, url);
    
  win = (bra_ofln_menu_t *)(bra_win_get_window (BRA_WIN_ID_OFLN_MAIN));
  if(win)
  {
    bra_ofln_update_menu_items(win);
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (bra_ofln_n_items - 1), MSF_CHOICE_ELEMENT_SELECTED);
  }

  return 1;
}

/******** SELECT OFFLINE MANAGE MENU FUNCTIONS ********/

static void 
bra_ofln_delete_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    bra_ofln_delete_ofln(bra_ofln_selected_ofln, bra_ofln_delete_response);
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_OFLN_MAIN);
    if(bra_ofln_n_items <= 0)
    {
      if(!bra_view_if_has_viewable_page() || bra_cmn_get_current_page()->offline_page == TRUE)
        bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
    }
  }
}

static void
bra_ofln_delete_all_confirmation(MsfActionType response)
{
    if(response == MsfOk)
    {
        MSF_INT8 i, total = bra_ofln_n_items;
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DELETING, MsfInfo, 300000);
        for(i = total - 1; i >= 0 ; i--)
        {
            if(i > 0)
                bra_ofln_delete_ofln(i, bra_ofln_delete_all_response);
            else
                bra_ofln_delete_ofln(i, bra_ofln_delete_all_response);
        }
        if(!bra_view_if_has_viewable_page() || bra_cmn_get_current_page()->offline_page == TRUE)
            bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
    }
}

static void 
bra_ofln_add_confirmation(MsfActionType response)
{     
  if(response == MsfOk)
  {
    bra_cmn_addr_t* addr;
    addr = bra_cmn_get_current_page ();  	
      	
    bra_ofln_state = BRA_OFLN_STATE_SAVE_REQUEST;
    BRSif_savePageOffline(MSF_MODID_BRA, bra_sif_get_brs_id(), addr->url, NULL);
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_OFLN_MAIN);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVING, MsfInfo, 1000000);
  }
}

static void 
bra_ofln_update_confirmation(MsfActionType response)
{     
  if(response == MsfOk)
  {
    bra_cmn_addr_t* addr;
    addr = bra_cmn_get_current_page ();  	
    
    bra_ofln_state = BRA_OFLN_STATE_UPDATE_REQUEST;
    BRSif_savePageOffline(MSF_MODID_BRA, bra_sif_get_brs_id(), addr->url, NULL);
    bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_OFLN_MAIN);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVING, MsfInfo, 1000000);
  }
}

/*
 * Handles manage offline page menu events
 */
static void
bra_ofln_widget_action_manage_ofln_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_ofln_menu_t *p;
  p = (bra_ofln_menu_t *)(win);

  if (bra_action == p->back)
  {
      bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
      /*When USB mass storge, can not access offline page*/
#ifdef __USB_IN_NORMAL_MODE__
      if (mmi_usb_is_in_mass_storage_mode())
      {
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_USB_MODE_EXP_WARNING, MsfWarning, 0);
        return;
      }
#endif
    if(bra_ofln_n_items > 0)
    {
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 0) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*Load*/
        bra_ofln_load_selected_ofln(bra_ofln_selected_ofln, BRA_OFLN_STATE_LOAD_REQUEST);
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 1) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*Delete*/
        bra_dlg_create_dlg (MsfConfirmation,
                            BRA_STR_DELETE_ASK, 
                            BRA_STR_YES, 
                            BRA_STR_NO,
                            0, 
                            bra_ofln_delete_confirmation);
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 2) & MSF_CHOICE_ELEMENT_SELECTED)
      {
          /*Delete All*/
          bra_dlg_create_dlg (MsfConfirmation,
              BRA_STR_DELETE_ALL_ASK, 
              BRA_STR_YES, 
              BRA_STR_NO,
              0, 
              bra_ofln_delete_all_confirmation);
      }
      else if (bra_view_if_has_viewable_page() && bra_cmn_get_current_page()->offline_page == FALSE && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 3) & MSF_CHOICE_ELEMENT_SELECTED))
      {
        bra_cmn_addr_t* addr;
        addr = bra_cmn_get_current_page ();

        if (bra_ofln_search_item_by_url(addr->url) != NULL)
        {
          bra_dlg_create_dlg (MsfConfirmation,
                              BRA_STR_UPDATE_OFFLINE_PAGE, 
                              BRA_STR_YES, 
                              BRA_STR_NO,
                              0, 
                              bra_ofln_update_confirmation);      
        }
        /*Add Offline Page*/
        else if (bra_ofln_n_items >= BRA_MAX_NBR_OFFLINE_PAGES)
        {
          bra_dlg_create_dlg (MsfError,
                              BRA_STR_OFFLINE_PAGE_FULL, 
                              BRA_STR_OK, 
                              0,
                              0, 
                              NULL);
 
          return;
        }
        else
        {
          /* reset selected offline page */
          bra_ofln_selected_ofln = -1;        
      
          bra_dlg_create_dlg (MsfConfirmation,
                              BRA_STR_SAVE_ASK, 
                              BRA_STR_YES, 
                              BRA_STR_NO,
                              0, 
                              bra_ofln_add_confirmation);      
        }
      }
    }
    else
    {
      if (bra_view_if_has_viewable_page() && bra_cmn_get_current_page()->offline_page == FALSE && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, 0) & MSF_CHOICE_ELEMENT_SELECTED))
      {
        /* reset selected offline page */
        bra_ofln_selected_ofln = -1;
        
        bra_dlg_create_dlg (MsfConfirmation,
                            BRA_STR_SAVE_ASK, 
                            BRA_STR_YES, 
                            BRA_STR_NO,
                            0, 
                            bra_ofln_add_confirmation);              
      }
    }
  }
}

/*
 * Destoys the manage offline page menu
 */
static void
bra_ofln_delete_manage_ofln_menu (bra_win_t *win)
{
  bra_ofln_menu_t *p;
  p = (bra_ofln_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

  MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);
}

/*
 * Creates the Manage menu for the selected offline page.
 */

static void 
bra_ofln_create_manage_ofln_menu(void)
{
  bra_ofln_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_ofln_menu_t);

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
   if(bra_ofln_n_items > 0)
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
     if(bra_view_if_has_viewable_page() && bra_cmn_get_current_page()->offline_page == FALSE)
     {
	    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                     i, 
                                     BRA_STR_SAVE_OFFLINE_PAGE,  
                                     0, bra_cmn_get_list_num_image(i), 0, TRUE);
       i++;                                     
       HDIa_widgetExtChoiceSetElemFlag(win->window, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
     }                                     
                                             
   }
   else
   {
     if(bra_view_if_has_viewable_page() && bra_cmn_get_current_page()->offline_page == FALSE)
	    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 
                                     0, 
                                     BRA_STR_SAVE_OFFLINE_PAGE,  
                                     0, bra_cmn_get_list_num_image(0), 0, TRUE);
     HDIa_widgetExtChoiceSetElemFlag(win->window, 0, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
   }

	MSF_WIDGET_SET_TITLE(win->window,BRA_STR_OPTIONS);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,(int) /*MSF_WINDOW_PROPERTY_EXT_DISABLE_RIGHT_ARROW |*/ MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->window, win->back);

  bra_win_show_window (BRA_WIN_ID_OFLN_MANAGE, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_ofln_delete_manage_ofln_menu, 
                      NULL,
                      bra_ofln_widget_action_manage_ofln_menu);

}

/******** END OFFLINE PAGE MANAGE MENU FUNCTIONS ********/

/******** OFFLINE MAIN MENU FUNCTIONS ********/

/*
 * Handles offline page main menu events
 */
static void
bra_ofln_widget_action_ofln_menu(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_ofln_menu_t *p;
  int i = 0; 

  p = (bra_ofln_menu_t *)(win);

  if (bra_action == p->back)
	{
		bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
	}
  else if (bra_action == p->accept)
  {
    int opt_item = (bra_ofln_n_items == 0)?1:bra_ofln_n_items;
    while(i < opt_item && !(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i) & MSF_CHOICE_ELEMENT_SELECTED))
      i++;
    if(i == opt_item)
      return;
    bra_ofln_selected_ofln = i;
    bra_ofln_create_manage_ofln_menu ();
  }
}

/*
 * Destoys the offline page main menu
 */
static void
bra_ofln_delete_ofln_menu (bra_win_t *win)
{
  bra_ofln_menu_t *p;
  p = (bra_ofln_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

  bra_ofln_destroy();
  bra_ofln_selected_ofln = -1;
}

/*
 * Focus the offline page main menu
 */
static void
bra_ofln_in_focus(bra_win_t *win)
{
  if(bra_ofln_selected_ofln >= 0)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->win_hdl, bra_ofln_selected_ofln, MSF_CHOICE_ELEMENT_SELECTED);
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/

/*
 * Creates the offline page menu.
 */

/*
 * This function creates and display the offline page menu
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_ofln_create_ofln_menu(void)
{
  bra_ofln_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  /* It is not allowed to create offline page menu twice */
  if(bra_ofln_file_handle)
    return;

  /*Init offline page whenever create offline page menu*/
  bra_ofln_init();

  if(bra_ofln_n_items <= 0 && (!bra_view_if_has_viewable_page() || bra_cmn_get_current_page()->offline_page == TRUE))
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_EMPTY, MsfPromptEmpty, 0);
    bra_ofln_destroy();
    return;
  }

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_ofln_menu_t);

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

	MSF_WIDGET_SET_TITLE(win->window,BRA_STR_OFFLINE_PAGES);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->window, win->back);

  /*Add menu items*/
  bra_ofln_update_menu_items(win);

  bra_win_show_window (BRA_WIN_ID_OFLN_MAIN, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_ofln_delete_ofln_menu, 
                      bra_ofln_in_focus,
                      bra_ofln_widget_action_ofln_menu);

}

/******** END OFFLINE PAGE MAIN MENU FUNCTIONS ********/

/*
 * This function is used to set the offile mode
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_set_offline_mode(MSF_BOOL b)
{
  if(b == TRUE)
  {
    BRSif_setOfflineMode(MSF_MODID_BRA, bra_sif_get_brs_id(), TRUE);
    bra_ofln_mode = 1;
  }
  else 
  {
    BRSif_setOfflineMode(MSF_MODID_BRA, bra_sif_get_brs_id(), FALSE);
    bra_ofln_mode = 0;
  }
}

/*
 * This function return if the offline mode is true or not
 *
 * PARAMETERS
 *
 * RETURN    : void
 */

int 
bra_ofln_offline_mode(void)
{
  return bra_ofln_mode;
}

/*
 * This function is used to reset the offile state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_ofln_reset_offline_state(void)
{
  bra_ofln_state = BRA_OFLN_STATE_NULL;
}

/*
 * This function return if it is in loading offline page state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bra_ofln_loading_offline_page(void)
{
  return (bra_ofln_state == BRA_OFLN_STATE_LOAD_REQUEST);
}

void
bra_ofln_saving_offline_done(MSF_BOOL success)
{
  if(success == TRUE && bra_ofln_state == BRA_OFLN_STATE_SAVE_REQUEST)
  {
    char *s, *t;
    int  len;
    bra_cmn_addr_t* addr;

    addr = bra_cmn_get_current_page ();
    len = MSF_WIDGET_STRING_GET_LENGTH(addr->title, 1, MsfUtf8);
    s = BRA_ALLOC(len+1);
    MSF_WIDGET_STRING_GET_DATA (addr->title, s, MsfUtf8);
    t = BRA_ALLOC(strlen(addr->url)+1);
    strcpy(t, addr->url);

    bra_ofln_add_new_ofln(s, t);    
    BRA_FREE(s);
  }
  else if(success == TRUE && bra_ofln_state == BRA_OFLN_STATE_UPDATE_REQUEST)
  {
    bra_ofln_save_response(0);
  }
  else
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVE_OFFLINE_PAGE_FAIL, MsfError,0);
  }
  
  bra_ofln_state = BRA_OFLN_STATE_NULL;
}

/*
 * This function called when brs not found the offline page
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bra_ofln_page_not_found(void *p)
{
  bra_dlg_create_dlg (MsfError,
                      BRA_STR_OFFLINE_PAGE_NOTFOUND, 
                      BRA_STR_OK, 
                      0,
                      0, 
                      NULL);
  return 1;
}

int
bra_ofln_page_has_page_to_delete(void)
{
    return (bra_ofln_list_toDelete != NULL);
}

void
bra_ofln_page_delete_pending_page(void)
{
    while (bra_ofln_list_toDelete)
    {
        BRSif_deleteOfflinePage(MSF_MODID_BRA, bra_ofln_list_toDelete->url);
        bra_ofln_list_toDelete = bra_ofln_list_toDelete->next;
    }
}

#endif /* BRA_CFG_OFFLINE_PAGES */


