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
#include "msf_cfg.h"
 
#ifdef __MMI_KLG__
#include "bra_cfg.h"
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "bra_sif.h"
#include "bra_prof.h"

#include "msf_int.h"
#include "msf_wid.h"
#include "msf_lib.h"

#include "stk_if.h"

/************************************************************
 * Local Types 
 ************************************************************/

/* menu type*/
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_cch_menu_t;

/************************************************************
 *  Functions
 ************************************************************/
static void
bra_cch_delete_confirmation (MsfActionType response)
{
  if(response == MsfOk)
  {
    STKif_clear (MSF_MODID_BRA, STK_CLEAR_CACHE_ALL, NULL);
    bra_cmn_save_done_dialog();    
  }
}

static void 
bra_cch_enable_cache_response (MsfActionType response)
{
  if(response == MsfOk)
  {
	 bra_prof_change_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_CACHEON, 1, NULL);
    bra_cmn_save_done_dialog();    
	 bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void 
bra_cch_disable_cache_response (MsfActionType response)
{
  if(response == MsfOk)
  {
	 bra_prof_change_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_CACHEON, 0, NULL);
    bra_cmn_save_done_dialog();    
	 bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
  }
}

static void 
bra_cch_enable_cache_confirmation (int selected)
{
	if(selected == bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_CACHEON))
		return;

	if(selected == 0)
	{
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_DISABLE_CACHE_CONF, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_cch_disable_cache_response);
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_EMPTY, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          NULL);
	}
	else if (selected == 1)
	{
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_ENABLE_CACHE_CONF, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          bra_cch_enable_cache_response);
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_EMPTY, 
                          BRA_STR_YES, 
                          BRA_STR_NO,
                          0, 
                          NULL);
	}
}

#ifdef BRA_CONFIG_TEST
static int
bra_cch_cache_size_response (char* response)
{
  int size;

   if (response == NULL)
    return 0;

   size = atoi (response);
   if ((size < 0) || (size > BRA_CFG_MAX_CACHE_SIZE))
     return 0;
   
     bra_prof_change_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_CASHSIZE, size, NULL);

  BRA_FREE (response);

  return 1;

}
#endif

static void
bra_cch_delete_cch_menu (bra_win_t *win)
{
  bra_cch_menu_t *p;
  p = (bra_cch_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

}

static void
bra_cch_action_cch_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_cch_menu_t *p;
  int on_off_list[2] = {BRA_STR_ID_OFF, BRA_STR_ID_ON};
#ifdef BRA_CONFIG_TEST
  char *s;
  MsfStringHandle ms;
#endif
  p = (bra_cch_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 0) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      bra_dlg_create_opt_menu (BRA_STR_CACHE_MODE, 
                               2, 
                               on_off_list,
                               bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_CACHEON),
                               bra_cch_enable_cache_confirmation);

    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 1) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Confirmation dialog*/
      bra_dlg_create_dlg (MsfConfirmation,
                          BRA_STR_CLEAR_CACHE, 
                          BRA_STR_OK, 
                          BRA_STR_CANCEL,
                          0, 
                          bra_cch_delete_confirmation);

    }
#ifdef BRA_CONFIG_TEST
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, 2) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      s = bra_cmn_int_to_str (bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_CASHSIZE));
      
      ms = BRA_STRCONV (s);
      bra_dlg_create_input_form(BRA_STR_CACHE_SIZE, 
                                MsfNumber, 
                                ms,
                                7, 
                                bra_cch_cache_size_response);
      MSF_WIDGET_RELEASE (ms);
      BRA_FREE (s);
      
    }
#endif
  }  
}

/*
 * This function create and display the Cache options menu.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_cch_create_menu (void)
{
  bra_cch_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_cch_menu_t);

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

  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 0, BRA_STR_CACHE_MODE, 0, bra_cmn_get_list_num_image(0), 0, TRUE);
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 1, BRA_STR_CLEAR_CACHE, 0, bra_cmn_get_list_num_image(1), 0, TRUE);
  HDIa_widgetExtChoiceSetElemFlag(win->window, 1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
#ifdef BRA_CONFIG_TEST
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, 2, BRA_STR_CACHE_SIZE, 0, 0, 0, TRUE);
#endif
	MSF_WIDGET_SET_TITLE (win->window,BRA_STR_CACHE);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_CACHE, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_cch_delete_cch_menu, 
                    NULL,
                    bra_cch_action_cch_menu);
}
#endif /* __KLG_MMI__ */

