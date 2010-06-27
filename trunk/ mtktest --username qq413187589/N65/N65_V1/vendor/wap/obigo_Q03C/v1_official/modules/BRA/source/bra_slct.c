/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#include "bra_cfg.h"
#ifdef BRA_CFG_SELECT_MODE
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_sif.h"
#include "bra_act.h"
#include "bra_view.h"

#include "msf_int.h"
#include "msf_wid.h"

#include "msf_act.h"
#include "bra_main.h"

/************************************************************
 * Local Types
 ************************************************************/

/* menu type*/
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_slct_menu_t;

/************************************************************
 * Function definitions
 ************************************************************/

static void
bra_slct_delete_menu (bra_win_t *win)
{
  bra_slct_menu_t *p;
  p = (bra_slct_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

}

static void
bra_slct_action_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_slct_menu_t *p;
  int i = 0;
  int n_action= 0;

  p = (bra_slct_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
  }
  else if (bra_action == p->accept)
  {
    n_action = bra_act_get_num_actions();
    if(n_action > 0)
    {
      for(i = 0; i < n_action; i++)
      {
        if(MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
        {
          /* save as */
          bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
          bra_act_execute_object_action(i);
          return;
        }
      }
    }
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Exit Select Mode*/
      bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
	  bra_view_cancel_select_mode();
    }
  }    
}

/*
 * This function creates the select mode menu.
 *
 * Note! This function is only availabe when BRA_CFG_SELECT_MODE is defined.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_slct_create_menu (void)
{
  bra_slct_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  int i = 0;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_slct_menu_t);

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



  i += bra_act_add_actions (win->window, i);

  /*Exit Select Mode*/
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_EXIT, 0, bra_cmn_get_list_num_image(i), 0, TRUE);

  MSF_WIDGET_SET_TITLE (win->window,BRA_STR_OPTIONS);
  MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
  MSF_WIDGET_ADD_ACTION (win->window, win->back);

  /*remove menu key action from screen*/
  bra_view_disable ();

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SLCT_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_slct_delete_menu, 
                    NULL,
                    bra_slct_action_menu);
}

#endif /*BRA_CFG_SELECT_MODE */
