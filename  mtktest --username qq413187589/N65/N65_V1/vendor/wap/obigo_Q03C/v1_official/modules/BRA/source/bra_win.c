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
 * bra_win.h
 *
 * Created by Tomas Mandorf	20020912	13:18
 * 
 * Description:
 *		This file contains code to handle windows in the bra 
 *    module. All windows are stored on a stack. When a new 
 *    window is opened a call to bra_win_show_window is made.
 *    To close a window (one or many) the 
 *    bra_win_close_window is called. this function closes 
 *    all windows until the close method specified in the
 *    function parameter is fulfiled.
 *     
 *    The four different close methods described below
 *    
 *    BRA_WIN_CLOSE_CURRENT:
 *        Closes the current window and sets previous in focus.
 *
 *    BRA_WIN_CLOSE_ID:
 *        Closes the window with the specific ID but keeps all other
 *        windows.
 *   
 *    BRA_WIN_CLOSE_TO_ID
 *       Closes all windows until the top window matches the 
 *        ID parameter. Only the window with matching ID is set
 *        in focus. 
 *   
 *    BRA_WIN_CLOSE_ALL
 *        Closes all windows and do not set a new window in focus
 *    
 *    
 *    NOTE! Dialogs is not handled by this functionality
 */

#include "bra_cfg.h"
#include "bra_win.h"
#include "bra_cmn.h"
#include "bra_opt.h"
#include "bra_view.h"

#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_log.h"


/******************************************************************************
 * Defines
 *****************************************************************************/

#define BRA_WIN_MAX_SCREEN_ACTIONS  5

/******************************************************************************
 * Types
 *****************************************************************************/
typedef struct win_item 
{
  int id;
  bra_win_t *win;
  MsfPosition *pos;
  bra_win_destroy_window_t destroy;
  bra_win_in_focus_t in_focus;
  bra_win_action_handle_t action_hdl;
    
  struct win_item *next;
} win_item_t;

typedef struct screen_action
{
  int type;
  MsfActionHandle hdl;
  bra_screen_action_handle_t callback;
}screen_action_t;

typedef struct win_notify_callbacks
{
  MsfWindowHandle whdl;
  bra_win_widget_notify_handle_t callback;

  struct win_notify_callbacks* next;
} win_notify_callbacks_t;

/******************************************************************************
 * Variables
 *****************************************************************************/

static win_item_t*      bra_win_stack;
static MsfScreenHandle	bra_win_screen;

static screen_action_t  bra_screen_action_list[BRA_WIN_MAX_SCREEN_ACTIONS];
static int              bra_screen_action_list_n_items;
static int              bra_win_focus_disabled;

static win_notify_callbacks_t* bra_win_notify_list;

/******************************************************************************
 * Local Functions
 *****************************************************************************/

static void 
bra_win_close_current (void)
{    
  win_item_t *remove;
  
  bra_win_stack->destroy(bra_win_stack->win);
  remove = bra_win_stack;
  bra_win_stack = bra_win_stack->next;

  BRA_FREE(remove);

}

void
bra_win_disable_focus (void)
{
  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_WIN_DISABLE_FOCUS, "BRA: bra_win_disable_focus()"));

  bra_win_focus_disabled = TRUE;
}

void
bra_win_enable_focus (void)
{

  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_WIN_ENABLE_FOCUS, "BRA: bra_win_enable_focus()"));

  bra_win_focus_disabled = FALSE;

  MSF_WIDGET_SET_IN_FOCUS(bra_win_screen, 1);
  MSF_WIDGET_SET_IN_FOCUS(bra_win_stack->win->win_hdl, 1);
  
  if (bra_win_stack->in_focus != NULL)
    bra_win_stack->in_focus(bra_win_stack->win);
  
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/

/*
 * Function initializes the window stack.
 *
 * PARAMETERS
 *
 * screen    : The screen handle to add all windows to
 *
 * RETURN    : void
 */
void
bra_win_init (MsfScreenHandle	screen)
{
  bra_win_stack = NULL;
  bra_win_screen = screen;
  bra_win_focus_disabled = FALSE;

  bra_screen_action_list_n_items = 0;

  bra_win_notify_list = NULL;

  MSF_WIDGET_SET_IN_FOCUS(screen, 1);

}

/*
 * Function destroy the window stack and forces all open windows to close.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_win_destroy (void)
{
  win_item_t *remove;

  if (bra_win_stack == NULL)
    return;

  while (bra_win_stack != NULL)
  {
    remove = bra_win_stack;
    /*Destroy window*/
    /*window notify callback should be deregistered within window's destroy handler*/
    bra_win_stack->destroy(bra_win_stack->win);
    bra_win_stack = bra_win_stack->next;
    BRA_FREE(remove);
  }

}


/*
 * This function returns the currently used screen handle
 *
 * PARAMETERS
 *
 * RETURN    : Handle to screen
 */
MsfScreenHandle
bra_win_get_screen (void)
{
  return bra_win_screen;
}


/*
 * Function adds the window to screen and puts it on top of the stack.
 * after the window is created and displayed the "in focus" function 
 * is called. Every time the window gains foucus this functionis called.
 *
 * PARAMETERS
 *
 * id        : Uniqe id for the window
 * win       : Window structure. (Must be derived from bra_win_t)
 * pos       : The position of the window
 * destroy   : Pointer to destroy function
 * in_focus  : Pointer to function to call when the functions gets focus
 *
 * RETURN    : Return 1 if success else 0
 */
int
bra_win_show_window (int id, 
                    bra_win_t *win, 
                    MsfPosition *pos, 
                    bra_win_destroy_window_t destroy, 
                    bra_win_in_focus_t in_focus,
                    bra_win_action_handle_t action_hdl)
{
    win_item_t *item;

  /*Create window stack item*/
  item = BRA_ALLOCTYPE(win_item_t);

  item->id = id;
  item->win = win;
  item->pos = pos;
  item->destroy = destroy;
  item->in_focus = in_focus;
  item->action_hdl = action_hdl;
  item->next = bra_win_stack;

  bra_win_stack = item;

  /*Add window to screen*/
  MSF_WIDGET_SCREEN_ADD_WINDOW (bra_win_screen, bra_win_stack->win->win_hdl, pos, 0, 0 );

  /*Set window in focus*/
  if (bra_win_focus_disabled == FALSE)
    MSF_WIDGET_SET_IN_FOCUS(bra_win_stack->win->win_hdl, 1);

  if (bra_win_stack->in_focus != NULL)
    bra_win_stack->in_focus(bra_win_stack->win);

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
    BRA_WIN_SHOW_WINDOW, "BRA: bra_win_show_window(): id=%d, disable_focus=%d",
    id, bra_win_focus_disabled));

 return 1;
}

/*
 * Function closes window(s) as specified by method and removes window(s) from stack
 * The in_focus function of the new current window is caled
 *
 * PARAMETERS
 *
 * method    : Close method as described above
 * id        : Used if method BRA_WIN_CLOSE_TO_ID or BRA_WIN_CLOSE_ID, else ignored
 *
 * RETURN    : 1 if successful else 0
 */
int
bra_win_close_window (int method, int id)
{
  win_item_t *item;
  win_item_t *remove;

  /* if it is to close to viewport but viewable page doesn't exist, 
     then just set viewport in focus */
  if(method == BRA_WIN_CLOSE_TO_ID
     && id == BRA_WIN_ID_VIEWPORT
     && !bra_view_if_has_viewable_page())
  {
    bra_view_enable();
    return 1;
  }

  method = ((method == BRA_WIN_CLOSE_TO_ID_FORCE)?BRA_WIN_CLOSE_TO_ID:method);

  switch(method)
  {
  case BRA_WIN_CLOSE_CURRENT:
    bra_win_close_current();
    break;
  case BRA_WIN_CLOSE_ID:
    remove = bra_win_stack;
    item = NULL;
    while(remove != NULL)
    {
      if(remove->id == id)
      {
        if (item == NULL)
          bra_win_stack = remove->next;
        else
          item->next = remove->next;

        remove->destroy(remove->win);
        BRA_FREE(remove);
        break;
      }
      item = remove;
      remove = remove->next;
    }
    break;
  case BRA_WIN_CLOSE_TO_ID:
    item = bra_win_stack;
    while(item != NULL)
    {
      if(item->id == id)
      {
        break;
      }   
      item = item->next;
      bra_win_close_current();
    }
    break;
  case BRA_WIN_CLOSE_ALL:
    item = bra_win_stack;
    while(item != NULL)
    {
      bra_win_close_current();
      item = item->next;
    }
    break;
  }
    
  if (bra_win_stack != NULL && /* kevin */
     bra_win_stack->in_focus != NULL)
    bra_win_stack->in_focus(bra_win_stack->win);

  return 1;
}

/*  
 *  This function handles actions by sending them to the window specified by window 
 *  
 *
 *  Parameters:
 *
 *  action    : Action to be handled
 *  window    : Window to send the action to
 *
 *  Return    : 1 if handled else 0
 */
int
bra_win_handle_action (MSF_UINT32 action, MSF_UINT32 window)
{
  win_item_t *item;

  item = bra_win_stack;

  while(item != NULL)
  {
    if (item->win->win_hdl == window)
    {
      item->action_hdl(item->win, action);
      return 1;
    }

    item = item->next;
  }

  return 0;
}

/*
 * This function returnes a pointer to the window stuct currently on top of the stack
 *
 * PARAMETERS
 *
 * id        : Window Id
 *
 * RETURN    : Pointer to a window structure
 */
bra_win_t *
bra_win_get_window (int id)
{
  win_item_t *item;

  item = bra_win_stack;

  while(item != NULL)
  {
    if (item->id == id)
    {
      return item->win;
    }

    item = item->next;
  }

  return NULL;

}

/*
 * Handles and dispatches actions that have been atached to the screen using the 
 * below functions
 *
 * PARAMETERS
 *
 * action    : MsfActionType
 * screen    : Screen handle
 *
 * RETURN    : 1 if dispatched else 0
 */
int
bra_win_screen_handle_action (MSF_UINT32 action, MSF_UINT32 screen)
{
  int i;

  if (screen == bra_win_screen)
  {
    for (i = 0;i < bra_screen_action_list_n_items; i++)
    {
      if (action == bra_screen_action_list[i].hdl)
      {
        if (bra_screen_action_list[i].callback != NULL)
          bra_screen_action_list[i].callback ();
        return 1;
      }
    }
  }
  return 0;
}

/*
 * This fuction adds a action to the screen and calles the callback if this action occurs.
 * Note that only one action of each type can be assigned to the screen at once. If an
 * action already have been added this call will be ignored
 * 
 * PARAMETERS
 *
 * label     : Label to be used with the action (used if possible)
 * type      : The msfActionType
 * callback  : fuction to be called when this action occure
 *
 * RETURN    : void
 */
void
bra_win_add_screen_action (MsfStringHandle label, int type, bra_screen_action_handle_t callback)
{
  int i = 0;
  
  if (bra_screen_action_list_n_items < BRA_WIN_MAX_SCREEN_ACTIONS)
  {
    while (i < bra_screen_action_list_n_items)
    {
      if (bra_screen_action_list[i].type == type)
      {
        /*If the action type allready exist, ignore this call*/
        return;
      }
      i++;
    }
    
    bra_screen_action_list[bra_screen_action_list_n_items].type = type;
    bra_screen_action_list[bra_screen_action_list_n_items].hdl = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, label, type, 3, 0x8000);   
    bra_screen_action_list[bra_screen_action_list_n_items].callback = callback;
    
    MSF_WIDGET_ADD_ACTION(bra_win_screen, bra_screen_action_list[bra_screen_action_list_n_items].hdl);
    MSF_WIDGET_RELEASE(bra_screen_action_list[bra_screen_action_list_n_items].hdl);
    bra_screen_action_list_n_items++;

    return;
  }
  else
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_WIN_EE25124E6A7BA4DF81A0017EE4BFC3C0, "BRA: Error. No Screen actions available\n"));
  }

  return;
}

/*
 * This function removes the action with type type from the screen.
 *
 * PARAMETERS
 *
 * type      : MsfActionType to remove
 *
 * RETURN    : void
 */
void
bra_win_delete_screen_action (int type)
{
  int i = 0;

  while (i < bra_screen_action_list_n_items)
  {
    if (bra_screen_action_list[i].type == type)
    {
      MSF_WIDGET_REMOVE (bra_win_screen, bra_screen_action_list[i].hdl);
      if (i == (bra_screen_action_list_n_items - 1))
      {
        /*Last Item*/
        bra_screen_action_list[i].type     = -1;
        bra_screen_action_list[i].hdl      = 0;
        bra_screen_action_list[i].callback = 0;
      }
      else
      {
        bra_screen_action_list[i].type     = bra_screen_action_list[bra_screen_action_list_n_items-1].type;
        bra_screen_action_list[i].hdl      = bra_screen_action_list[bra_screen_action_list_n_items-1].hdl;
        bra_screen_action_list[i].callback = bra_screen_action_list[bra_screen_action_list_n_items-1].callback;
      }
      bra_screen_action_list_n_items--;
      return;
    }
    i++;
  }
}

MSF_BOOL
bra_win_any_win_exists(void)
{
  return (bra_win_stack != NULL);
}

int
bra_win_current_window(void)
{
  if(bra_win_stack)
    return bra_win_stack->id;
  return -1;
}


static win_notify_callbacks_t* bra_win_notify_search(MsfWindowHandle whdl, int remove)
{
  win_notify_callbacks_t* crt;
  win_notify_callbacks_t* prev;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_WIN_3A3923A0061F3DC00BF466A284638E66, "BRA: bra_win_notify_search(%x, %d)\n", whdl, remove));

  crt = bra_win_notify_list;
  prev = NULL;
  while(crt!=NULL)
  {
    if (crt->whdl == whdl)
    {
      if (remove)
      {
        if (prev == NULL)
          bra_win_notify_list = bra_win_notify_list->next;
        else
          prev->next = crt->next;
      }
      break;
    }
    crt = crt->next;
    prev = crt;
  }
  return crt;
}

void
bra_win_register_notify (MsfWindowHandle whdl, bra_win_widget_notify_handle_t callback)
{
  win_notify_callbacks_t* newNotify;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_WIN_A7610D704EB5803DD1F300CE788FD81E, "BRA: bra_win_register_notify(%x)\n", whdl));

  newNotify = bra_win_notify_search(whdl, TRUE);
  if (!newNotify)
    newNotify = BRA_ALLOCTYPE(win_notify_callbacks_t);
  
  newNotify->whdl = whdl;
  newNotify->callback = callback;
  newNotify->next = bra_win_notify_list;

  bra_win_notify_list = newNotify;
}

void
bra_win_deregister_notify (MsfWindowHandle whdl) 
{
  win_notify_callbacks_t* deregNotify;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_WIN_C3537B1EA530B353B4D833D7BD9D4F9D, "BRA: bra_win_deregister_notify(%x)\n", whdl));

  deregNotify = bra_win_notify_search(whdl, TRUE);
  if (deregNotify)
    BRA_FREE(deregNotify);
}

void
bra_win_handle_notify (MsfWindowHandle whdl, MsfNotificationType type)
{
  win_notify_callbacks_t* targetNotify;

  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_WIN_1088A0C5517DDEA581936625A113276C, "BRA: bra_win_handle_notify(%x, %d)\n", whdl, type));

  if (bra_win_stack==NULL || bra_win_stack->win->win_hdl != whdl)
    return;

  targetNotify =  bra_win_notify_search(whdl, FALSE);
  if (targetNotify)
    targetNotify->callback(bra_win_stack->win, type);
}

bra_win_t*
bra_win_find_win (MsfWindowHandle whdl)
{
  win_item_t *crtMsfWin;

  crtMsfWin = bra_win_stack;
  while (crtMsfWin) {
    if (crtMsfWin->win->win_hdl == whdl)
      return crtMsfWin->win;
    crtMsfWin = crtMsfWin->next;
  }
  return 0;
}

int
bra_win_non_viewport_win_exists(void)
{
  win_item_t *item;

  item = bra_win_stack;
  while(item != NULL)
  {
    if (item->id != BRA_WIN_ID_VIEWPORT)
      return 1;
    item = item->next;
  }
  return 0;
}
