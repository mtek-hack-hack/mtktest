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
 * bra_view.c
 *
 * This file contain the BRA viewport implementation.
 * The viewport is the window were content, status bar
 * and so on are displayed. 
 *
 */
#include "bra_cfg.h"
#include "bra_view.h"
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_opt.h"
#include "bra_str.h"
#include "bra_prof.h"
#include "bra_sif.h"
#include "bra_if.h"
#include "bra_dlg.h"
#include "bra_int.h"
#include "bra_act.h"
#include "bra_main.h"
#include "bra_ofln.h"  
#include "brs_if.h"
#include "bra_cbm.h"

#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_core.h"
#include "msf_log.h"

#include "kal_release.h"

#include "wap.h"
#include "widget.h"

/************************************************************
 * Local Types
 ************************************************************/

/* viewport */
typedef struct {
  MsfWindowHandle window;
} bra_view_viewport_t;


/************************************************************
 * Global variables
 ************************************************************/
static int bra_user_cancelled;
static int bra_back_enabled;
static int bra_loading_complete;
static int bra_has_viewable_page;
static int bra_view_property;
static int bra_view_select_mode;

static int bra_view_enabled;
static int bra_view_n_bytes;
static int bra_view_n_objects_total;
static int bra_view_n_objects_loaded;
static int bra_view_n_documents_loaded; 
static MsfWindowHandle bra_view_paintbox;

static int bra_view_status_visible;
static int bra_view_timer_enabled;
#ifdef BRA_CFG_USE_SPLASH
  static MsfImageHandle bra_view_splash_image;
  static MsfGadgetHandle bra_view_splash_gadget;

  static void bra_view_create_splash(void);
  static void bra_view_delete_splash(void);
#endif
       
#ifdef BRA_CFG_DISPLAY_TITLE
  static char *bra_view_current_title;
  static char *bra_view_current_url;
#endif


static int bra_view_if_has_save_as_object(void);

extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern void bra_destroy_ui(void);
extern void HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);
extern void HDIa_holdBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);
extern kal_bool HDIa_widgetExtIsCurrentFocusedPaintbox(void);

/************************************************************
 * Function definitions
 ************************************************************/
static void
bra_view_in_focus(bra_win_t *win);

static void
bra_view_set_paintbox_title(MsfStringHandle ms)
{
  if(bra_view_paintbox != 0 && MSF_moduleIsRunning(MSF_MODID_BRS))
    MSF_WIDGET_SET_TITLE(bra_view_paintbox, ms);
}

static void
bra_view_set_paintbox_property(int property)
{
  if(bra_view_paintbox != 0 && MSF_moduleIsRunning(MSF_MODID_BRS))
    MSF_WIDGET_WINDOW_SET_PROPERTIES(bra_view_paintbox, property);
}

static void
bra_view_set_paintbox_in_focus(int focus)
{
  MsfStringHandle ms;


  if (focus != 0)   
  {
    if (bra_view_current_title != NULL)
      ms = BRA_STRCONV (bra_view_current_title); 
    else
      ms = BRA_STR_START_TITLE;
    bra_view_set_paintbox_title(ms);
  }
  if(bra_view_paintbox != 0 && MSF_moduleIsRunning(MSF_MODID_BRS))
    MSF_WIDGET_SET_IN_FOCUS(bra_view_paintbox, focus);
}

void
bra_view_set_paintbox_handle(MsfWindowHandle paintbox)
{
  bra_view_paintbox = paintbox;
  if (bra_view_enabled == TRUE)
  {
    bra_view_set_paintbox_title(BRA_STR_START_TITLE);
    bra_view_set_paintbox_in_focus(1);
  }
}

void 
bra_view_enable (void)
{
  bra_win_t *win = bra_win_get_window(BRA_WIN_ID_VIEWPORT);
  bra_view_enabled = TRUE;  
  bra_view_set_paintbox_in_focus(1);
  if(win) bra_view_in_focus(win);  
}

void 
bra_view_disable (void)
{
  bra_view_enabled = FALSE;

  bra_view_set_paintbox_in_focus(0);
  bra_win_delete_screen_action (MsfBack);
  bra_win_delete_screen_action (MsfMenu);
  bra_win_delete_screen_action (MsfCancel);
}

void 
bra_view_reset_request_timer (void)
{       
  if(bra_view_timer_enabled == 1)
  {   
    MSF_TIMER_RESET (MSF_MODID_BRA, BRA_RQEUEST_TIMER_ID);
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_601C096492B32F623A577250957B6915, "BRA reset user request timer\n"));
    bra_view_timer_enabled = 0;
  }    
}

void 
bra_view_set_request_timer (void)
{
  int timeout;

  if(bra_view_timer_enabled == 1)
  {
    bra_view_reset_request_timer();
  }
    
  timeout = (bra_prof_get_key_int_value (BRA_PROF_ID_CMN, BRA_CMN_KEY_USER_TIMEOUT)) * 10;
      
  if(timeout > 0)  
  {
    bra_view_timer_enabled = 1;
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_3D9FD6677259157EC6D76B59FBE191DA, "BRA set user request timer:%d\n", timeout));
    MSF_TIMER_SET (MSF_MODID_BRA, BRA_RQEUEST_TIMER_ID, timeout);
  }    
}

#ifdef BRA_CFG_USE_SPLASH
void 
bra_view_set_splash_timer (void)
{
  bra_view_create_splash();

  MSF_TIMER_SET (MSF_MODID_BRA, BRA_SPLASH_TIMER_ID, BRA_CFG_SPLASH_TIME);
}

void 
bra_view_reset_splash_timer (void)
{
  MSF_TIMER_RESET (MSF_MODID_BRA, BRA_SPLASH_TIMER_ID);
  bra_view_delete_splash();
}

static void
bra_view_create_splash(void)
{
  MsfDeviceProperties dp;
  MsfSize szDev;
  MsfSize szImg;
  MsfPosition pos;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_14899D3DA128F8AB561D90318F5261E8, "BRA: bra_view_create_splash(), gadget=%x, image=%x, paintbox=%x\n", bra_view_splash_gadget, bra_view_splash_image,bra_view_paintbox));

  ASSERT(bra_view_paintbox);

  bra_view_delete_splash();

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&dp);
  szDev.height = dp.displaySize.height;
  szDev.width = dp.displaySize.width;

  bra_view_splash_image = MSF_WIDGET_IMAGE_GET_PREDEFINED(BRA_IMG_SPLASH_SCREEN, 0);
  if (!bra_view_splash_image)
  {
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_771A2D515FD536415620197E746ADE86, "BRA: bra_view_create_splash(): unable to create image!\n"));
    return;
  }

  MSF_WIDGET_GET_SIZE(bra_view_splash_image, &szImg);

  if (szImg.height > szDev.height)
  {
      szImg.width = (MSF_INT16)((szImg.width * szDev.height) / (szImg.height)); //shrink width
      szImg.height = szDev.height;
  }
  /* Check if the image can fit horizontally on the display  */
  if (szImg.width > szDev.width)
  {
      /* Scale using the same aspect */
      szImg.height = (MSF_INT16)((szImg.height * szDev.width) / szImg.width);
      szImg.width = szDev.width;
  }

  /* Image position */
  pos.x = (MSF_INT16)((MSF_UINT16)(szDev.width - szImg.width) >> 1);
  pos.y = (MSF_INT16)((MSF_UINT16)(szDev.height - szImg.height) >> 1);

  bra_view_splash_gadget = MSF_WIDGET_IMAGE_GADGET_CREATE(
                                MSF_MODID_BRA,
                                bra_view_splash_image,
                                &szImg,
                                MsfImageZoom100,
                                MSF_GADGET_PROPERTY_FOCUS,
                                0);

  if (!bra_view_splash_gadget)
  {
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_6342AE6A3EFB9DA167E00413CCAAC21B, "BRA: bra_view_create_splash(): unable to create gadget!\n"));
    MSF_WIDGET_RELEASE(bra_view_splash_image);
    bra_view_splash_image = 0;
    return;
  }

  MSF_WIDGET_WINDOW_ADD_GADGET(
                    bra_view_paintbox,
                    bra_view_splash_gadget,
                    &pos,
                    0);
  /* refresh window only if current focused window is paintbox */
  if (bra_view_enabled && HDIa_widgetExtIsCurrentFocusedPaintbox())
  {
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_DC4F0C346947E15B8682DDE765DFE517, "BRA: bra_view_create_splash(): paintbox set focus\n"));
    bra_view_set_paintbox_in_focus(1);
  }
}

static void
bra_view_delete_splash(void)
{
  //MsfSize sz;
  //MsfPosition pos;

  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_A63DB1DE15B13E2B09F7C9FB86ED269D, "BRA: bra_view_delete_splash(), gadget=%x, image=%x, paintbox=%x\n", bra_view_splash_gadget, bra_view_splash_image,bra_view_paintbox));

  //ASSERT(bra_view_paintbox);  

  if (bra_view_splash_gadget)
  {
    //MSF_WIDGET_GET_POSITION(bra_view_splash_gadget, &pos);
    //MSF_WIDGET_GET_SIZE(bra_view_splash_gadget, &sz);

    widget_stop_animate(1);
    
    if(bra_view_paintbox != 0 && MSF_moduleIsRunning(MSF_MODID_BRS))
      MSF_WIDGET_REMOVE(bra_view_paintbox, bra_view_splash_gadget);
   
    MSF_WIDGET_RELEASE(bra_view_splash_gadget);
    bra_view_splash_gadget = 0;

    /* refresh window only if current focused window is paintbox */
    if (bra_view_enabled) // && HDIa_widgetExtIsCurrentFocusedPaintbox())
    {
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_4386C070B80533E6F38DB0A2C41E94E3, "BRA: bra_view_delete_splash(): paintbox set focus\n"));
      bra_view_set_paintbox_in_focus(1);

      //MSF_WIDGET_DRAW_RECT(bra_view_paintbox, &pos, &sz, 1);
      //HDIa_widgetExtPaintDirectly();
    }
  }
  if (bra_view_splash_image)
  {
    MSF_WIDGET_RELEASE(bra_view_splash_image);
    bra_view_splash_image = 0;
  }
}
#endif

void 
bra_wiew_timer_expired (void *p)
{
  msf_timer_expired_t *data;
  
  if (p == NULL)
    return;

  data = (msf_timer_expired_t*)p;

  if(data->timerID == BRA_RQEUEST_TIMER_ID)
  {
    /* Stop loading */
    bra_view_timer_enabled = 0;
    BRSif_stop(MSF_MODID_BRA, bra_sif_get_brs_id ());    
    bra_sif_handle_brs_error(bra_sif_get_brs_id (), BRS_ERROR_REQUEST_TIMED_OUT);
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_81FB44EDC2501689CC1A30DE56A122EB, "BRA user request timeout\n"));
  }
#ifdef BRA_CFG_USE_SPLASH
  else if (data->timerID== BRA_SPLASH_TIMER_ID)
  {
    bra_view_delete_splash();
  }
#endif
}

#ifdef BRA_CFG_DISPLAY_TITLE
/*
 * This fuction sets the title of the view port window
 *
 * PARAMETERS
 *
 * title     : Title of the visited page
 * url       : URL of the visited page
 *
 * RETURN    : void
 */
void 
bra_view_set_title (char *title, char *url)
{
  bra_view_viewport_t *win;
  MsfStringHandle ms;

  if (bra_view_status_visible == 1)
  {
    if (bra_view_current_title != NULL)
      BRA_FREE (bra_view_current_title);
    
    if (bra_view_current_url != NULL)
      BRA_FREE (bra_view_current_url);
    
    bra_view_current_title = title;
    bra_view_current_url   = url;

    win = (bra_view_viewport_t *)(bra_win_get_window (BRA_WIN_ID_VIEWPORT));
    
    if (title != NULL)
    {
      ms = BRA_STRCONV (title); 
    }
    /*
    else if((url != NULL) && (*url != '\0'))
    {
      ms = BRA_STRCONV (url); 
    }
    */
    else
    {
      ms = BRA_STR_START_TITLE;
    }

    bra_view_set_paintbox_title(ms);
    
    MSF_WIDGET_RELEASE (ms);
  }
  else
  {    
    /*Always set title propertie to remove busy icon*/
    if(bra_view_paintbox != 0)
    {
      bra_view_property &= ~(MSF_WINDOW_PROPERTY_BUSY);
      bra_view_property |= MSF_WINDOW_PROPERTY_TITLE;
      bra_view_set_paintbox_property(bra_view_property);
    }
  }
}
#endif

/*
 * This function is called to enable the busy iconin the viewport window
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_view_set_busy_icon (void)
{
#ifdef BRA_CFG_DISPLAY_TITLE
  bra_view_property |= (MSF_WINDOW_PROPERTY_TITLE|MSF_WINDOW_PROPERTY_BUSY);
#else
  bra_view_property |= MSF_WINDOW_PROPERTY_BUSY;
#endif

  if(!BRAa_bearerInConn())
    BRAa_setBearerType(bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));

  if(bra_view_status_visible == 1)
    bra_view_set_paintbox_property(bra_view_property);
}

/*
 * Called to enable the secure icon in the viewport window
 * This function is only available if the MS security pagage is included.
 *
 * PARAMETERS
 *
 * sec_class : the current security class returned form SEC module
 *
 * RETURN    : void
 */
#ifdef BRA_CONFIG_SECURITY
void 
bra_view_set_secure_icon (int sec_class)
{
  bra_view_viewport_t *win;

  BRAa_setSecureIcon(sec_class);

  win = (bra_view_viewport_t *)(bra_win_get_window (BRA_WIN_ID_VIEWPORT));

  bra_view_set_paintbox_property(bra_view_property);
}
#endif

/*
 * This function changes the value of the left and right soft key.
 * if either value is 0 the label on that softkey is left unchanged
 *
 * PARAMETERS
 *
 * left      : MsfStringHandle of left softkey
 * right     : MsfStringHandle of right softkey
 *
 * RETURN    : void
 */
void
bra_view_set_soft_key (MsfStringHandle left, MsfStringHandle right)
{
  /*if (left > 0)*/
left = left;
  /*if (right > 0)*/
right = right;
}

/************************************************************
 *  Functions for creating the Viewport   
 ************************************************************/

static void
bra_action_view(bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_view_viewport_t *p;
    p = (bra_view_viewport_t *)(win);
    bra_action = bra_action;
}

static void 
bra_view_back_action (void)
{
  BRSif_move (MSF_MODID_BRA, bra_sif_get_brs_id(), BRS_MOVE_BACKWARD, 1);
}


void    
bra_view_cancel_loading(void)   
{
  bra_user_cancelled = 1;
  //BRAa_userCancel();

  /*Stop loading*/
  BRSif_stop (MSF_MODID_BRA, bra_sif_get_brs_id());
}


#ifdef BRA_CFG_SELECT_MODE
void
bra_view_enter_select_mode (void)
{
  bra_view_select_mode = TRUE;

  //if(bra_loading_complete && bra_has_viewable_page)
  //  bra_view_set_idle_softkey();

  bra_view_set_paintbox_title(BRA_STR_SELECT_PICTURE);
}

void 
bra_view_cancel_select_mode (void)
{
  MsfStringHandle ms;
  
  bra_sif_set_select_mode (FALSE);
  bra_view_select_mode = FALSE;
  bra_view_set_idle_softkey();
  
  if (bra_view_current_title != NULL)
    ms = BRA_STRCONV (bra_view_current_title); 
  //else if((bra_view_current_url != NULL) && (*bra_view_current_url != '\0'))
    //ms = BRA_STRCONV (bra_view_current_url); 
  else
    ms = BRA_STR_START_TITLE;

  bra_view_set_paintbox_title(ms);
    
  MSF_WIDGET_RELEASE (ms);
}
#endif

static void
bra_view_exit_download_confirmation (MsfActionType response)
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

static void bra_view_exit_ui(void)
{
    if (bra_get_da_download_active_job_count() > 0)
    {
        bra_dlg_create_dlg (MsfConfirmation,
                            BRA_STR_SUSPEND_DOWNLOAD, 
                            BRA_STR_YES,
                            BRA_STR_NO,
                            0, 
                            bra_view_exit_download_confirmation);
    }
    else
    {
        bra_destroy_ui();
    }
}
void
bra_view_set_idle_softkey(void)
{
  bra_win_delete_screen_action (MsfCancel);
  bra_win_delete_screen_action(MsfBack);
#ifdef BRA_CFG_SELECT_MODE
  if(!bra_view_select_mode || bra_act_get_num_actions() > 0)
	bra_win_add_screen_action (BRA_STR_OPTIONS, MsfMenu, bra_sif_select_menu);
  else
    bra_win_delete_screen_action(MsfMenu);
#else
  bra_win_add_screen_action (BRA_STR_OPTIONS, MsfMenu, bra_opt_create_menu);
#endif
  if(bra_back_enabled && !bra_view_select_mode)
    bra_win_add_screen_action (BRA_STR_BACK, MsfBack, bra_view_back_action);
#ifdef BRA_CFG_SELECT_MODE
  else if(bra_view_select_mode)
    bra_win_add_screen_action (BRA_STR_EXIT, MsfBack, bra_view_cancel_select_mode);
#endif
  else
    bra_win_add_screen_action(BRA_STR_EXIT, MsfBack, bra_view_exit_ui); 

}

static void
bra_view_set_busy_softkey(void)
{
  bra_user_cancelled = 0;
  bra_win_delete_screen_action (MsfBack);
  bra_win_delete_screen_action (MsfMenu);
  bra_win_add_screen_action (BRA_STR_CANCEL, MsfCancel, bra_view_cancel_loading);
}

void
bra_view_enable_back_action (MSF_BOOL enable)
{
  bra_back_enabled = enable;
  bra_win_delete_screen_action(MsfBack);    
  if(bra_back_enabled)
    bra_win_add_screen_action (BRA_STR_BACK, MsfBack, bra_view_back_action);
  else
    bra_win_add_screen_action(BRA_STR_EXIT, MsfBack, bra_view_exit_ui); 
}

void
bra_view_loading_complete (MSF_BOOL b)
{
  bra_loading_complete = b;

  if(bra_loading_complete)
  { 
    /* this is the first viewable page */
    if(!bra_has_viewable_page)
    {
      bra_has_viewable_page = 1;
      
      if(bra_view_enabled)
        /* close all window behind, go to idle softkey in bra_view_in_focus() */
        bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
    }
    else
      /* requested page back, go to idle softkey */
      bra_view_set_idle_softkey();

    /* if this is first page after bearer connected, set bearer type to activated */
    BRAa_loadingComplete();
  }
  else
  {
    /* begin fetch page, go to busy softkey */
    bra_view_set_busy_softkey();
  }
}

static void
bra_view_in_focus(bra_win_t *win)
{
  bra_view_viewport_t *p;
  p = (bra_view_viewport_t *)(win);

  bra_view_enabled = TRUE;
  
  bra_view_set_paintbox_in_focus(1);

  /* Whenever idle and viewable page exists, go to idle softkey */
  if(bra_loading_complete && bra_has_viewable_page)
    bra_view_set_idle_softkey();    
  if(!bra_loading_complete)
    bra_view_set_busy_softkey();
}

static void
bra_view_delete_view(bra_win_t *win)
{
  bra_view_viewport_t *p;
  p = (bra_view_viewport_t *)(win);
  
  // Stop request timer anyway when exiting WAP
  bra_view_reset_request_timer();  

#ifdef BRA_CONFIG_SECURITY
  bra_view_set_secure_icon(0);
#endif  
  bra_view_enabled = FALSE;
  bra_view_status_visible = 0;
  bra_has_viewable_page = 0; 

  bra_view_set_paintbox_handle(0);

#ifdef BRA_CFG_DISPLAY_TITLE
  if (bra_view_current_title != NULL)
    BRA_FREE (bra_view_current_title);
  
  if (bra_view_current_url != NULL)
    BRA_FREE (bra_view_current_url);
#endif

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 

  BRA_FREE (p);
}

/*
 * This function creates the viewport vindow and displays it.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_view_create_view(void)
{
  bra_view_viewport_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MsfStyleHandle sh;

#ifdef BRA_CFG_USE_SPLASH
  MsfColor c = {255,255,255};
#else
  MsfColor c = {255,255,255};
#endif


  if (bra_win_get_window(BRA_WIN_ID_VIEWPORT))
      return;

  bra_user_cancelled = 0;
  bra_back_enabled = 0;
  bra_view_select_mode = 0;
  bra_loading_complete = 0;
  bra_has_viewable_page = 0;
#ifdef BRA_CFG_USE_SPLASH
  bra_view_splash_image = 0;
  bra_view_splash_gadget = 0;
#endif

  bra_view_property = (MSF_WINDOW_PROPERTY_NOTIFY|MSF_WINDOW_PROPERTY_MOVERESIZE);

  bra_view_set_paintbox_handle( 0 );

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  win = BRA_ALLOCTYPE (bra_view_viewport_t);

  sh = HDIa_widgetStyleCreate(MSF_MODID_BRA, 0, 
                                      &c, 
                                      0, 
                                      0, 
                                      0, 
                                      0, 
                                      0);

  win->window = MSF_WIDGET_FORM_CREATE(MSF_MODID_BRA, &prop.displaySize, 0x8000, sh);

  MSF_WIDGET_RELEASE(sh);

#ifdef BRA_CFG_DISPLAY_TITLE
  MSF_WIDGET_SET_TITLE(win->window, BRA_STR_START_TITLE);
  bra_view_property |= MSF_WINDOW_PROPERTY_TITLE;
  MSF_WIDGET_WINDOW_SET_PROPERTIES(win->window, bra_view_property);

  bra_view_current_title = NULL;
  bra_view_current_url   = NULL;
#endif

  bra_win_show_window (BRA_WIN_ID_VIEWPORT, 
                      (bra_win_t*)win, 
                      &pos, 
                      bra_view_delete_view, 
                      bra_view_in_focus,
                      bra_action_view);

  BRAa_setStatusIcon();
}


/************************************************************
 *  Functions for managing a status bar   
 ************************************************************/

static void
bra_view_error_confirmation (MsfActionType response)
{
  bra_destroy_ui();
}

void
bra_view_delete_status (void)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_5E013A40D339D68FD7872C192396B922, "BRA: bra_view_delete_status(): view_page=%d, load_comp=%d, obj_load=%d\n", bra_has_viewable_page, bra_loading_complete, bra_view_n_objects_loaded));

  bra_view_status_visible = 0;

  /* Stop request timer anyway */
  bra_view_reset_request_timer();  
  
#ifdef BRA_CFG_USE_SPLASH
  /* Stop splash timer */
  bra_view_reset_splash_timer();
#endif

#ifdef BRA_CFG_DISPLAY_TITLE
  bra_view_set_title (bra_view_current_title, bra_view_current_url);
#endif

  /* destory security related dialog when browsing request finish */
  if(bra_win_get_window(BRA_WIN_ID_SEC_DLG))
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_SEC_DLG);         
   
  if(bra_win_get_window(BRA_WIN_ID_AUTH_DLG))
    bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_AUTH_DLG);         
  
  /* if viewable page exists */
  if(bra_has_viewable_page)
  {
    /* if idle status caused by user cancel, goto idle softkey */
    if(!bra_loading_complete)
      bra_view_set_idle_softkey();
  }
  /* control reaches here means that no page at all has loaded */
  else
  {
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_F013BC6A80245E24F14413D09CF73BCB, "BRA: bra_view_delete_status(): no viewing page\n"));
#ifdef BRA_CFG_PROF_FALLBACK
    if (bra_sif_is_pending_bearer_switch())
      return;
#endif

    /* if user cancel or no save as objects, to avoid screen delay between WAP and MMI's download agent screen */
    if (bra_user_cancelled || !bra_view_if_has_save_as_object())  
    {
      /* this is a trick to let widget put the view port back to the end of display */
      bra_view_set_paintbox_in_focus(1);
      bra_view_disable();
    }

#ifdef BRA_CFG_DUAL_SIM
    /* check if enter from push, if so, should reset the title icon on the push menus */
    if (!bra_win_get_window(BRA_WIN_ID_INSE) && 
        !bra_win_get_window(BRA_WIN_ID_OPT) &&
        bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG) &&
        bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
        bra_sim_destroy_ui();
    }
    
#endif /* BRA_CFG_DUAL_SIM */
    
    if(!bra_win_get_window(BRA_WIN_ID_INSE) 
       && !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_OPT_DLG)
       && !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG))
    {
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_BBC641F3F9067D7FAF31EAF5C6B60D1D, "BRA: bra_view_delete_status(): no INSE and no PUSH MSG dialog\n"));
      if(bra_win_get_window(BRA_WIN_ID_DLG) && !bra_check_dialog_is_extscheme())
      {
        MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_579AC2BE0A46C71B1C3AD541645FF1E2, "BRA: bra_view_delete_status(): has dialog\n"));
        bra_dlg_set_dialog_callback(bra_view_error_confirmation);
      }
      else if(bra_user_cancelled || !bra_view_if_has_save_as_object()) /* check if any save as object exists, if yes, destroy ui will be done after save as */
      {
        MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_BE2432705905E4457A7B96ADBD3FA3C3, "BRA: bra_view_delete_status(): calling destroy ui\n"));
        bra_destroy_ui();
      }
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_36C51C0B66AE3BFA29D7AF39D8908646, "BRA: bra_view_delete_status(): end of no INSE and no PUSH MSG OPT IF block\n"));
    }        
    /* basically the bearer should be terminated if loading of first page failed.
       here we enforce the bearer to terminate when some WAP menu still exists */
    else /* if(bra_win_get_window(BRA_WIN_ID_INSE)) */ {
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_0278031671E8E14382CFD7828CBA8510, "BRA: bra_view_delete_status(): releasing bearer\n"));
      HDIa_releaseBearer(MSF_MODID_BRA, BRAif_getNetAccId());
#ifdef BRA_CFG_PROF_FALLBACK
      if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL)) {
        MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_52BE4B13D62A779AC6E5A3A63A65548B, "BRA: bra_delete_status(): reset dual net-id to GPRS\n"));

        // release GPRS bearer if dual_id mode and currently using CSD connection..
        //if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID) == bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM))
        HDIa_releaseBearer(MSF_MODID_BRA, bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS));

        bra_prof_change_key_int_value(
            BRA_PROF_ID_BRA,
            BRA_PROF_KEY_NET_ID,
            bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS),
            NULL);
      }
      bra_sif_init();
#endif

      /* terminate BRS if back to Internet Service Menu by cancelling the security auth dialog page */
      if(bra_user_cancelled || !bra_view_if_has_save_as_object()) /* check if any save as object exists, if yes, destroy ui will be done after save as */
      {
        if(MSF_moduleIsRunning(MSF_MODID_BRS))
        {
          MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_831046E041579E09D2BD11A8A77DD831, "BRA: bra_view_delete_status(): delete+terminate BRS instance\n"));
          BRSif_deleteInstance (MSF_MODID_BRA, bra_sif_get_brs_id ());
          MSF_MODULE_TERMINATE(MSF_MODID_BRA, MSF_MODID_BRS);
        }
      }
    }
    bra_cmn_set_current_page ("", "", BRA_INSE_SET_CURRENT_TITLE | BRA_INSE_SET_CURRENT_URL);
  }

  /* now, back to idle status, reset to 1 anyway */
  bra_loading_complete = 1;
}

/*
 * This function creates and display a download status bar. below functions
 * are used to increment fields in the dialog
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_create_status_bar (void)
{
  MsfStringHandle ms;

  /* go to busy status */
  bra_view_n_bytes = 0;
  bra_view_n_objects_total = 0;
  bra_view_n_objects_loaded = 0;
  bra_view_n_documents_loaded = 0; 
  bra_view_status_visible = 1;
  
  bra_sif_set_select_mode (FALSE);
  bra_view_select_mode = FALSE;

  if (bra_view_enabled == FALSE)
    return;

  /* set busy icon and title if enable */
  bra_view_set_busy_icon();
 
  /* start the request guard timer */
#ifdef BRA_CFG_CONN_ALWAYS_ASK
  if (!bra_cbm_is_need_to_ask())
      bra_view_set_request_timer();
#else
  bra_view_set_request_timer();
#endif

#ifdef BRA_CFG_USE_SPLASH
  /* show splash screen */
  if (!bra_has_viewable_page)
    bra_view_set_splash_timer();
#endif

  /* set default title in case of resetting select picture mode */  
  if (bra_view_current_title != NULL)
    ms = BRA_STRCONV (bra_view_current_title); 
  else
    ms = BRA_STR_START_TITLE;
  bra_view_set_paintbox_title(ms);
  MSF_WIDGET_RELEASE (ms);

  /* set busy softkey */
  bra_view_set_busy_softkey();

  /* hold bearer on first time connection (browser up for first time) */
#ifdef BRA_CFG_OFFLINE_PAGES      
  if (0 == bra_ofln_offline_mode())
	HDIa_holdBearer(MSF_MODID_BRA, BRAif_getNetAccId());
#else
  if (!bra_has_viewable_page)
	HDIa_holdBearer(MSF_MODID_BRA, BRAif_getNetAccId());
#endif
}

/*
 * This function notifyies the Status bare that a new item is beeing loaded.
 *
 * PARAMETERS
 *
 * s         : Status string e.g. "Loading Document..."
 * url       : Url to the object that is beeing loaded
 *
 * RETURN    :
 */void
bra_view_new_object (MsfStringHandle s, char* url)
{
  if(s == BRA_STR_LOADING_DOC)
    bra_view_loading_complete(FALSE);

#ifdef BRA_CFG_PROF_FALLBACK
  bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_URL_FALLBACK, url, 0);
#endif

  if (bra_view_status_visible == 0)
    return;

  bra_view_n_objects_total++;  
}

/*
 * This function terminates an object and the status bar is updated
 *
 * PARAMETERS
 *
 * size      : The size of the loaded object
 *
 * RETURN    :
 */
void
bra_view_object_done (int size)
{
  if (bra_view_status_visible == 0)
    return;

#ifdef BRA_CFG_USE_SPLASH
  if (!bra_has_viewable_page)
    bra_view_reset_splash_timer();
#endif

  /* Stop request timer whenever first object back */
  if(bra_view_n_objects_loaded == 0)
    bra_view_reset_request_timer();
    
  bra_view_n_bytes += size;
  bra_view_n_objects_loaded++;            
}

MsfWindowHandle
bra_view_get_paintbox (void)
{
  return bra_view_paintbox;
}

char *
bra_view_get_title (void)
{
   return bra_view_current_title;
}

char *
bra_view_get_url (void)
{
   return bra_view_current_url;
}

int
bra_view_if_has_viewable_page(void)
{
  return bra_has_viewable_page;
}

int
bra_view_is_busy(void)
{
  return bra_view_status_visible;
}

int 
bra_view_is_enabled(void)
{
  return bra_view_enabled;
}

int
bra_view_is_user_cancelled(void)
{
    return bra_user_cancelled;
}


void
bra_view_download_complete(int status)
{
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_7156F2E22A7B6ACC78FBE3126186830F, "BRA: bra_view_download_complete(): viewable_page: %d\n", bra_has_viewable_page));

  /* first connecting page = object downloading */
  if(bra_win_get_window(BRA_WIN_ID_INSE) ||
     bra_win_get_window(BRA_WIN_ID_PUSH_MSG_DLG))
  {
    /* force release bearer */
    /* cant call HDIa_releaseBearer() again because bra_view_delete_status()
     * have already been triggered and may have reset the net_id in dual-mode scenario.
     * furthermore, BRS must be terminated in order to release the dangling socket in STK */
    MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_VIEW_C5968F3BD2B2F499251163AF26FF2A1E, "BRA: bra_view_download_complete(): delete+terminate BRS instance if still running\n"));

    /* this is a trick to let widget put the view port back to the end of display */
    bra_view_set_paintbox_in_focus(1);   
    bra_view_disable();

    if(MSF_moduleIsRunning(MSF_MODID_BRS))
    {
      BRSif_deleteInstance (MSF_MODID_BRA, bra_sif_get_brs_id ());
      MSF_MODULE_TERMINATE(MSF_MODID_BRA, MSF_MODID_BRS);
    }
    return;
  }

  /* at this point, both IntServ menu and PUSH Message window dont exist */
  if (!bra_has_viewable_page)
    bra_destroy_ui();
}


static int bra_view_if_has_save_as_object(void)
{
    /* we should accurately know whether there are any save as objects is downloaded here */
    return (bra_view_n_objects_loaded - bra_view_n_documents_loaded > 0);
}

void bra_view_document_done(int num)
{
    bra_view_n_documents_loaded += num;
}




