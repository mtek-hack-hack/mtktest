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
#include "msf_wid.h"
#include "msf_lib.h"

#include "bra_cfg.h"
#include "bra_dlg.h"
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_str.h"
#include "bra_view.h"

#ifdef BRA_CONFIG_PROVISIONING 
#include "bra_prs.h"
#endif

#include "msf_core.h"
#include "stk_dlg.h"

#include "widget_extension.h"


/************************************************************
 * Local Defines
 ************************************************************/

/*Defines for title-url input dialog*/
#define BRA_CMN_TITLE_URL_X_MARGIN      5
#define BRA_CMN_TITLE_URL_Y_MARGIN      5/*10*/
#define BRA_CMN_TITLE_URL_LINESPACING   5/*10*/
#define BRA_CMN_TITLE_URL_LINE_HEIGHT   20

#define BRA_DLG_INPUT_FIELD_MARGIN 5
#define BRA_DLG_INPUT_FIELD_HEIGHT 18/*20*/

/************************************************************
 * Local Types
 ************************************************************/
#ifdef BRA_USE_CTK_INLINE
typedef enum
{
  EDIT_HOMEPAGE_TITLE_CAP,
  EDIT_HOMEPAGE_TITLE,
  EDIT_HOMEPAGE_URL_CAP,
  EDIT_HOMEPAGE_URL,
  EDIT_HOMEPAGE_NUM
} bra_dlg_edit_homepage_item_enum;

typedef enum
{
  BRA_DLG_AUTH_FORM_USERNAME_CAPTION,
  BRA_DLG_AUTH_FORM_USERNAME,
  BRA_DLG_AUTH_FORM_PASSWORD_CAPTION,
  BRA_DLG_AUTH_FORM_PASSWORD,
  BRA_DLG_AUTH_FORM_TOTAL  
} bra_dlg_auth_form_enum;

#endif

typedef struct
{
    MsfWindowHandle windowHandle;
    MSF_UINT8 module;
    int requestId;
    int authType;
    char *username;
    char *password;
    char *realm;
    int warnings;
} bra_dlg_auth_form_t;

typedef struct {
    /* Main form */
    MsfWindowHandle windowHandle;
    /* Title */
    MsfStringHandle titleHandle;
    /* Title */
    MsfGadgetHandle titleGadgetHandle;
	/* URL */
    MsfGadgetHandle urlGadgetHandle;
    /* Navigation */
    MsfActionHandle okActionHandle;
    MsfActionHandle backActionHandle;
  
    bra_dlg_title_url_response_t callback;
    int close_to_id;
    
}bra_dlg_title_url_form_t;

typedef struct {
    MsfWindowHandle dialogHandle;
    MsfActionHandle okAction;
    MsfActionHandle cancelAction;
    bra_action_handle_t pCallback;
    MsfStringHandle text;
} bra_dlg_dialog_t;

typedef struct {
    MsfWindowHandle window;
    MsfActionHandle ok;
    MsfActionHandle cancel;
    MsfGadgetHandle input;
    bra_dlg_input_response_t callback;

} bra_dlg_input_dialog_t;

typedef struct {
    MsfWindowHandle windowHandle;
    MsfActionHandle okAction;
    MsfActionHandle cancelAction;    
} bra_dlg_status_dialog_t;

typedef struct {
    MsfWindowHandle window;
    MsfActionHandle ok;
    MsfActionHandle cancel;
    bra_dlg_opt_response_t callback;
    int    n_options;
} bra_dlg_opt_menu_t;

#ifdef BRA_USE_CTK_INLINE
static bra_dlg_title_url_form_t *ctk_dlg_title_url_win = NULL;
static bra_dlg_auth_form_t *bra_dlg_auth_form = NULL;
#endif

/********************************************************************************
 * Title and URL input dialog.
 *
 * Below the functions needed to disply a dialog that can be used 
 * to input a title and URL.
 * 
 * bra_add_normal_string_textinput
 * bra_dlg_create_title_url_form
 * bra_dlg_delete_title_url_form
 * bra_dlg_widget_action_titleUrl_form
 *
 ********************************************************************************/
static void 
bra_add_normal_string_textinput(MsfWindowHandle  handle,
                                MsfGadgetHandle *gadget_textinput,
                                MsfGadgetHandle  default_str,
														    MsfStringHandle  initial_str, 
                                MsfPosition		 *pos,
                                MsfSize			   *str_size,
                                MsfSize         *input_size,
                                int			        max_n_chars,
								                MsfTextType	    input_type)
{
	MsfGadgetHandle gadget_string;

  if (default_str !=  0)
  {
	  gadget_string = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_BRA, default_str, str_size, 1, 0x8000, 0);
	  MSF_WIDGET_WINDOW_ADD_GADGET(handle, gadget_string, pos, 0);
	  MSF_WIDGET_GADGET_SET_PROPERTIES(gadget_string, 0);
    MSF_WIDGET_RELEASE (gadget_string);
	  pos->y = (MSF_INT16)(pos->y + str_size->height);
  }
  
	*gadget_textinput = MSF_WIDGET_TEXT_INPUT_CREATE(MSF_MODID_BRA,
                                                   0,           /*This is initial string*/
                                                   initial_str, /*And this is input string. change names*/
													                         input_type, 
													                         max_n_chars,
                                                   TRUE,
													                         input_size,
                                                   0x8000,
                                                   0);
  
	MSF_WIDGET_GADGET_SET_PROPERTIES(*gadget_textinput, MSF_GADGET_PROPERTY_BORDER | MSF_GADGET_PROPERTY_FOCUS);
	MSF_WIDGET_WINDOW_ADD_GADGET(handle, *gadget_textinput, pos, 0);  
  pos->y = (MSF_INT16)(pos->y + input_size->height);

}


static void 
bra_dlg_delete_title_url_form (bra_win_t *win)
{
  bra_dlg_title_url_form_t *p;

  p = (bra_dlg_title_url_form_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->okActionHandle);
	MSF_WIDGET_RELEASE (p->backActionHandle);
	MSF_WIDGET_RELEASE (p->titleGadgetHandle);
	MSF_WIDGET_RELEASE (p->urlGadgetHandle);

  BRA_FREE (win);
}

static void
bra_dlg_widget_action_title_url(bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_dlg_title_url_form_t *p;
	char *title; 
	char *url;   
  MsfStringHandle msfStr;

  p = (bra_dlg_title_url_form_t *)(win);

	if (bra_action == p->okActionHandle)
	{
    msfStr = MSF_WIDGET_STRING_CREATE_TEXT(MSF_MODID_BRA, p->titleGadgetHandle, 0);
    title = BRA_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(msfStr, 1, MsfUtf8) + 1);
    MSF_WIDGET_STRING_GET_DATA(msfStr, title, MsfUtf8);
    MSF_WIDGET_RELEASE(msfStr); 

    msfStr = MSF_WIDGET_STRING_CREATE_TEXT(MSF_MODID_BRA, p->urlGadgetHandle, 0);
    url = BRA_ALLOC(MSF_WIDGET_STRING_GET_LENGTH(msfStr, 1, MsfUtf8) + 1);
    MSF_WIDGET_STRING_GET_DATA(msfStr, url, MsfUtf8);
    MSF_WIDGET_RELEASE(msfStr); 

    /*Call response function. If it return 0 the do not dismiss the dialog*/
    if (p->callback(title, url) == 0)
    { 
      bra_dlg_create_dlg (MsfError,
        BRA_STR_ERR_TITLE_URL_INVALID, 
        BRA_STR_OK, 
        0,
        0, 
        NULL);

      return;
    }  
    
    BRA_FREE (title);
    BRA_FREE (url);
	}
  
  bra_win_close_window (BRA_WIN_CLOSE_TO_ID, p->close_to_id);

}

/*
 * This function is called to dispay a dialog that handles input 
 * of a title and url. The response i returned in a call to a 
 * callback function. the responce will be destroyed when the 
 * callback returnes successfully. It is also the responsibility 
 * of the callback to validate the response. If the response is  
 * valid the callback should return 1. If for some reason the 
 * response is invalid the callback might raise a error dialog 
 * and then return 0.
 *
 * PARAMETERS
 *
 * title      : Handle to dialog title
 * input_title: Handle to default text to be put IN the title input field 
 * input_url  : Pointer to default text to be put IN the url input field 
 * callback   : Pointer to callback where the response should be handled
 * close_to_id: Window id to the window to be displayed when this dialog
 *              ends.
 *
 * RETURN     : void
 */
void 
bra_dlg_create_title_url_form (MsfStringHandle title, 
						                   MsfStringHandle input_title,
						                   char * input_url,
                               bra_dlg_title_url_response_t callback,
                               int close_to_id)
{
  bra_dlg_title_url_form_t *win;
  MsfPosition   win_pos = {0,0};
  MsfPosition   pos;
	MsfSize				size;
  MsfStringHandle ms;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);


  win = BRA_ALLOCTYPE (bra_dlg_title_url_form_t);

	pos.x = BRA_CMN_TITLE_URL_X_MARGIN;
  pos.y = BRA_CMN_TITLE_URL_Y_MARGIN;

	/* Window */
	win->windowHandle = MSF_WIDGET_FORM_CREATE(MSF_MODID_BRA, &prop.displaySize, 0x8000, 0);
	win->callback = callback;
  win->close_to_id = close_to_id;

	/* Title */
	MSF_WIDGET_SET_TITLE(win->windowHandle, title);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

  /*Initialize height and width. Use same size for both label and input field*/
  size.height = BRA_CMN_TITLE_URL_LINE_HEIGHT;
	size.width  = (MSF_INT16)(prop.displaySize.width - (2 * BRA_CMN_TITLE_URL_X_MARGIN));

	/* Title Gadget */

	bra_add_normal_string_textinput(win->windowHandle,
							                    &(win->titleGadgetHandle),
                                  BRA_STR_TITLE,
							                    0,
                                  &pos,
                                  &size,
                                  &size, 
							                    BRA_CFG_MAX_NBR_CHARS_TITLE,
							                    MsfText);
	/* URL Gadget */
	pos.y = (MSF_INT16)(pos.y + BRA_CMN_TITLE_URL_LINESPACING);
	bra_add_normal_string_textinput(win->windowHandle,
							                    &(win->urlGadgetHandle),
                                  BRA_STR_ADDRESS,
							                    0,
                                  &pos,
                                  &size,
                                  &size, 
							                    BRA_CFG_MAX_NBR_CHARS_URL,
							                    MsfText);

	MSF_WIDGET_TEXT_SET_TEXT(win->titleGadgetHandle, 0, MsfText, BRA_CFG_MAX_NBR_CHARS_TITLE, input_title, 1);

  if (!strcmp(input_url, ""))
    ms = BRA_STRCONV ("http://");
  else
    ms = BRA_STRCONV (input_url);/*OK*/

	MSF_WIDGET_TEXT_SET_TEXT(win->urlGadgetHandle,   0, MsfText, BRA_CFG_MAX_NBR_CHARS_URL,   ms,   1);
  MSF_WIDGET_RELEASE (ms);


	/* Action OK */
	win->okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
	MSF_WIDGET_ADD_ACTION(win->windowHandle, 
								 win->okActionHandle);
	/* Action back */
	win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_CANCEL, MsfBack, 3, 0x8000);
	MSF_WIDGET_ADD_ACTION(win->windowHandle, 
								 win->backActionHandle);

	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG_TITLE_URL_FORM, 
                    (bra_win_t*)win, 
                    &win_pos, 
                    bra_dlg_delete_title_url_form, 
                    NULL,
                    bra_dlg_widget_action_title_url);

}

#ifdef BRA_USE_CTK_INLINE
static void 
bra_dlg_delete_title_url_form_ctk (bra_win_t *win)
{
  bra_dlg_title_url_form_t *p;
  p = (bra_dlg_title_url_form_t*)win;
  if(ctk_dlg_title_url_win)
  {
    MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 
    MSF_WIDGET_RELEASE (p->windowHandle);
    ctk_dlg_title_url_win = NULL;
  }
  BRA_FREE(p);
}

static void 
bra_dlg_ctk_delete_title_url_form (ctk_screen_handle scrid)
{
  int close_to_id;

  MSF_WIDGET_REMOVE (bra_win_get_screen (), ctk_dlg_title_url_win->windowHandle); 
  MSF_WIDGET_RELEASE (ctk_dlg_title_url_win->windowHandle);
  close_to_id = ctk_dlg_title_url_win->close_to_id;
  ctk_dlg_title_url_win = NULL;
  bra_win_close_window(BRA_WIN_CLOSE_TO_ID, close_to_id); 
}

static void 
bra_dlg_ctk_title_url_confirmation(MsfActionType response)
{
  ctk_screen_handle scrid;
  ctk_layout_handle layoutid;
  char *title = NULL, *url = NULL;

  scrid = HDIa_widgetCtkGetScreenHandle(ctk_dlg_title_url_win->windowHandle);

  if(response == MsfOk)
  {    
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVING, MsfInfo, 5000);   
    layoutid =ctk_screen_get_layout(scrid);      
    // get title
    title = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_TITLE);  
    // get url
    url = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_URL);  
    ctk_dlg_title_url_win->callback(title, url);
    BRA_FREE(title);
    BRA_FREE(url);
  }

  bra_dlg_ctk_delete_title_url_form(scrid);
}

static void 
bra_dlg_ctk_invalid_url_confirmation(MsfActionType response)
{
  ctk_screen_handle scrid;
  scrid = HDIa_widgetCtkGetScreenHandle(ctk_dlg_title_url_win->windowHandle);
  bra_dlg_ctk_delete_title_url_form(scrid);
}

static void
bra_dlg_ctk_widget_action_title_url(ctk_screen_handle scrid)
{
  ctk_layout_handle			layoutid =ctk_screen_get_layout(scrid);
  char *title = NULL, *url = NULL;
    
  // get title
  title = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_TITLE);
  
  // get url
  url = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_URL);  

  if(*url == '\0' && *title == '\0')
  {
    BRA_FREE (title);
    BRA_FREE (url);
    bra_dlg_ctk_delete_title_url_form(scrid);    
    
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_ERR_TITLE_URL_INVALID, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);
    

    return;
  }

  if(!bra_cmn_url_is_valid(url))
  {
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_INVALID_URL, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        bra_dlg_ctk_invalid_url_confirmation);
    BRA_FREE (title);
    BRA_FREE (url);       
    return;
  }  

  BRA_FREE (title);
  BRA_FREE (url);

  bra_dlg_create_dlg (MsfConfirmation,
                      BRA_STR_SAVE_ASK, 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_dlg_ctk_title_url_confirmation);
}

void 
bra_dlg_ctk_create_title_url_form (MSF_UINT16 title, 
                                   MsfStringHandle input_title,
                                   char * input_url,
                                   bra_dlg_title_url_response_t callback,
                                   int close_to_id,
                                   MSF_BOOL modified,
                                   MSF_BOOL msg_icon)
{
  MsfPosition   win_pos = {0,0};
  ctk_screen_handle				scrid;
  ctk_layout_handle				layoutid;
  ctk_inline_create_struct		layout_create;
  MSF_UINT32 l;
  char *title_str, *url_str;
  const char http_str[] = "http://";
  int i = 0;

  ASSERT(ctk_dlg_title_url_win == NULL)

  ctk_dlg_title_url_win = BRA_ALLOCTYPE(bra_dlg_title_url_form_t);

  if (msg_icon == TRUE)
  {
      layoutid = bra_cmn_ctk_init_layout(&layout_create, EDIT_HOMEPAGE_NUM, MEA_IMG_TITLE_NORMAL, 
                                         title,bra_dlg_ctk_delete_title_url_form, KAL_FALSE);
  }
  else
  {
      layoutid = bra_cmn_ctk_init_layout(&layout_create, EDIT_HOMEPAGE_NUM, widget_get_title_icon(0), 
                                         title,bra_dlg_ctk_delete_title_url_form, KAL_FALSE);
  }
  
  // title caption
  bra_cmn_ctk_add_caption(layoutid, EDIT_HOMEPAGE_TITLE_CAP, BRA_STR_ID_TITLE, bra_cmn_get_list_num_image_enum(i++));
  
  // title editor
  l = MSF_WIDGET_STRING_GET_LENGTH(input_title, 1, MsfUtf8);
  title_str = BRA_ALLOC (l + 1); 
  MSF_WIDGET_STRING_GET_DATA (input_title, title_str, MsfUtf8);
  if (msg_icon == TRUE)
  {
      bra_cmn_ctk_add_editor(layoutid, EDIT_HOMEPAGE_TITLE, CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
          BRA_CFG_MAX_NBR_CHARS_TITLE, title_str, BRA_STR_ID_TITLE, MEA_IMG_TITLE_NORMAL);
  }
  else
  {
      bra_cmn_ctk_add_editor(layoutid, EDIT_HOMEPAGE_TITLE, CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                             BRA_CFG_MAX_NBR_CHARS_TITLE, title_str, BRA_STR_ID_TITLE, widget_get_title_icon(0));
  }
  BRA_FREE(title_str);

  // url caption
  bra_cmn_ctk_add_caption(layoutid, EDIT_HOMEPAGE_URL_CAP, BRA_STR_ID_ADDRESS, bra_cmn_get_list_num_image_enum(i++)); 

  // url editor
  if (!input_url || !strcmp(input_url, ""))
  {
    url_str = (char*)http_str;
    modified = FALSE;
  }
  else
  {
    url_str = input_url;
  }
  
  if (msg_icon == TRUE)
  {
      bra_cmn_ctk_add_editor(layoutid, EDIT_HOMEPAGE_URL, CTK_INPUT_TYPE_ALPHA|CTK_INPUT_TYPE_OVERRIDE,
          BRA_CFG_MAX_NBR_CHARS_URL, url_str, BRA_STR_ID_ADDRESS, MEA_IMG_TITLE_NORMAL);
  }
  else
  {
      bra_cmn_ctk_add_editor(layoutid, EDIT_HOMEPAGE_URL, CTK_INPUT_TYPE_ALPHA|CTK_INPUT_TYPE_OVERRIDE,
                             BRA_CFG_MAX_NBR_CHARS_URL, url_str, BRA_STR_ID_ADDRESS, widget_get_title_icon(0));
  }

  if(modified)
    ctk_inline_set_modified(layoutid);

  // create form
  scrid = bra_cmn_ctk_screen_create(layoutid, bra_dlg_ctk_widget_action_title_url); 
  ctk_dlg_title_url_win->windowHandle = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);
  ctk_dlg_title_url_win->callback = callback;
  ctk_dlg_title_url_win->close_to_id = close_to_id;
  
	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG_TITLE_URL_FORM, 
                       (bra_win_t*)ctk_dlg_title_url_win, 
                       &win_pos, 
                       bra_dlg_delete_title_url_form_ctk, 
                       NULL,
                       NULL);
}

static void 
bra_dlg_delete_auth_form (bra_win_t *win)
{
  bra_dlg_auth_form_t *p;
  p = (bra_dlg_auth_form_t *)win;
  
  ASSERT(p == bra_dlg_auth_form);

  bra_view_enable();
  MSF_WIDGET_REMOVE (bra_win_get_screen(), p->windowHandle); 
  MSF_WIDGET_RELEASE (p->windowHandle);
  BRA_FREE(p);
  bra_dlg_auth_form = NULL;
}

static void 
bra_dlg_auth_form_confirm(MsfActionType response)
{
  extern void widget_send_update_event_to_wps(void);
  ctk_screen_handle scrid;
  ctk_layout_handle layoutid;
  char *username, *password;

  scrid = HDIa_widgetCtkGetScreenHandle(bra_dlg_auth_form->windowHandle);

  if(response == MsfOk)
  {    
    layoutid =ctk_screen_get_layout(scrid);      

    username = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_TITLE);  
    password = bra_cmn_ctk_get_input_result(layoutid, CTK_INLINE_ITEM_TYPE_EDITOR, EDIT_HOMEPAGE_URL);  
    stk_dlg_auth_credentials (bra_dlg_auth_form->module, bra_dlg_auth_form->requestId, 
                            username, password, STK_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD);
    BRA_FREE(username);
    BRA_FREE(password);
  }
  else
  {
    stk_dlg_auth_credentials (bra_dlg_auth_form->module, bra_dlg_auth_form->requestId, 
                            NULL, NULL, 0);
  }
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0); 

  widget_send_update_event_to_wps();
}

static void
bra_dlg_action_auth_form(ctk_screen_handle scrid)
{
  bra_dlg_create_dlg (MsfConfirmation,
                      MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SUBMIT_ASK), 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_dlg_auth_form_confirm);
}

static void bra_dlg_cancel_auth_form(ctk_screen_handle scrid)
{
  extern void widget_send_update_event_to_wps(void);

  stk_dlg_auth_credentials (bra_dlg_auth_form->module, bra_dlg_auth_form->requestId, 
                            NULL, NULL, 0);

  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0); 

  widget_send_update_event_to_wps();
}

void 
bra_dlg_create_auth_form (MSF_UINT8 module, int requestId, int authType, 
                      const char *realm, const char* username, int warnings)
{
  MsfPosition   win_pos = {0,0};
  ctk_screen_handle				scrid;
  ctk_layout_handle				layoutid;
  ctk_inline_create_struct		layout_create;

  ASSERT(bra_dlg_auth_form == NULL);

  bra_view_disable();
  bra_dlg_auth_form = BRA_ALLOCTYPE(bra_dlg_auth_form_t);

  layoutid = bra_cmn_ctk_init_layout(&layout_create, BRA_DLG_AUTH_FORM_TOTAL, widget_get_title_icon(0), 
                                     STK_STR_ID_TITLE_SERVER, bra_dlg_cancel_auth_form, KAL_FALSE);
  
 /*
  if (authType == STK_AUTH_SERVER)
	layout_create.in_str_title = (ctk_string_id)STK_STR_ID_TITLE_SERVER;
  else
	layout_create.in_str_title = (ctk_string_id)STK_STR_ID_TITLE_PROXY;
 */
  layout_create.in_str_title = (ctk_string_id)BRA_STR_ID_AUTHENTICATION;

  /* Username caption */
  bra_cmn_ctk_add_caption(layoutid, BRA_DLG_AUTH_FORM_USERNAME_CAPTION, BRA_STR_ID_PRX_UID, WAP_IMAGE_SW_USERNAME);
  
  /* Username editor */
  bra_cmn_ctk_add_editor(layoutid, BRA_DLG_AUTH_FORM_USERNAME, CTK_INPUT_TYPE_ALPHA,
                         40, (char *)username, BRA_STR_ID_PRX_UID, widget_get_title_icon(0));

  /* Password caption */
  bra_cmn_ctk_add_caption(layoutid, BRA_DLG_AUTH_FORM_PASSWORD_CAPTION, BRA_STR_ID_PRX_PWD, WAP_IMAGE_SW_PASSWORD); 

  /* Password editor */
  bra_cmn_ctk_add_editor(layoutid, BRA_DLG_AUTH_FORM_PASSWORD, CTK_INPUT_TYPE_PASSWORD_ALPHA,
                         40, NULL, BRA_STR_ID_PRX_PWD, widget_get_title_icon(0));

  scrid = bra_cmn_ctk_screen_create(layoutid, bra_dlg_action_auth_form); 
  bra_dlg_auth_form->windowHandle = HDIa_widgetCtkCreate(MSF_MODID_BRA, scrid);
  bra_dlg_auth_form->requestId = requestId;
  bra_dlg_auth_form->module = module;

  bra_win_show_window (BRA_WIN_ID_AUTH_DLG, 
                       (bra_win_t*)bra_dlg_auth_form, 
                       &win_pos, 
                       bra_dlg_delete_auth_form, 
                       NULL,
                       NULL);
}

#endif

/********************************************************************************
 * Dialog
 * 
 * bra_dlg_create_dlg
 * bra_dlg_dialog_delete
 * bra_dlg_dialog_action
 *
 ********************************************************************************/

static void 
bra_dlg_dialog_action (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_dlg_dialog_t *dlg;
  bra_action_handle_t callback;
  MsfActionType action;
  dlg = (bra_dlg_dialog_t *)(win);
  
  /*Once the dialog is closed the callback is destroyed so therefor remember address*/
  callback = dlg->pCallback;

  if (bra_action == dlg->okAction)
  {
    action = MsfOk;
  }
  else 
  {
    action = MsfCancel;
  }

  /*Close dialog first*/
  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  
  if(callback == NULL)
    return;

  callback(action);

}

static void 
bra_dlg_dialog_delete (bra_win_t *win)
{
  bra_dlg_dialog_t *dlg;
  
  dlg = (bra_dlg_dialog_t *)(win);
  
  MSF_WIDGET_REMOVE (bra_win_get_screen (), dlg->dialogHandle); 

  MSF_WIDGET_RELEASE (dlg->dialogHandle);
  if (dlg->okAction != 0)
    MSF_WIDGET_RELEASE (dlg->okAction);
  if (dlg->cancelAction != 0)
    MSF_WIDGET_RELEASE (dlg->cancelAction);

  BRA_FREE (win);
}


/*
 * This function creates and handles the events of an MSF Dialog. The 
 * response is returend in the callback function. This function is 
 * typically used to create a Confirmation or Error dialog
 *
 * PARAMETERS
 *
 * type        : Type of Dialog to create, (MsfDialogType)
 * text        : Message to be displayed in the Dialog
 * left_action : Label of the left softkey
 * right_action: Label of the Right softkey
 * timeout     : The amount of time after which the dialog should be closed.
 *               Setting the timeout value to 0 will create a dialog which the 
 *               user must terminate manualy
 * callback    : fFunction pointer to response function
 *
 * RETURN      : void
 */
void 
bra_dlg_create_dlg(MsfDialogType   type,
                   MsfStringHandle text, 
                   MsfStringHandle left_action, 
                   MsfStringHandle right_action, 
                   MSF_UINT32 timeout, 
                   bra_action_handle_t callback)
{
  bra_dlg_dialog_t *dlg;
  MsfPosition dialogPos = {10,10};

  
  if (bra_win_current_window() == BRA_WIN_ID_VIEWPORT && bra_view_is_enabled())
     HDIa_widgetExtPaintDirectly();

  /*remove menu key action from screen*/
  bra_view_disable ();

  dlg = BRA_ALLOCTYPE (bra_dlg_dialog_t);

  dlg->dialogHandle = MSF_WIDGET_DIALOG_CREATE (MSF_MODID_BRA, text, type, timeout, 0x8000, 0);
  
  if (dlg->dialogHandle == 0)
   return;

  if (left_action != 0)
  {  
    dlg->okAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, left_action, MsfOk , 1, 0x8000);
    MSF_WIDGET_ADD_ACTION (dlg->dialogHandle, dlg->okAction);
  }
  else
  {
    dlg->okAction = 0;
  }

  if (right_action != 0)
  {
    dlg->cancelAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, right_action, MsfCancel ,1, 0x8000);
    MSF_WIDGET_ADD_ACTION (dlg->dialogHandle, dlg->cancelAction);
  }
  else
  {
    dlg->cancelAction = 0;
  }

  dlg->pCallback = callback;
  dlg->text = text;
  
#ifdef BRA_CONFIG_PROVISIONING 
  if(bra_prs_is_insall_new_setting_string(text))
  {
    HDIa_widgetExtDialogDisableTone(dlg->dialogHandle);
    MSF_WIDGET_WINDOW_SET_PROPERTIES(dlg->dialogHandle, MSF_WINDOW_PROPERTY_EXT_STATUS_ICON);
  }
#endif /* BRA_CONFIG_PROVISIONING */

  if (text == BRA_STR_NEW_PUSH_MSG)
  {
    HDIa_widgetExtDialogDisableTone(dlg->dialogHandle);
    MSF_WIDGET_WINDOW_SET_PROPERTIES(dlg->dialogHandle, MSF_WINDOW_PROPERTY_EXT_STATUS_ICON);
  }
 /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG, 
                    (bra_win_t*)dlg, 
                    &dialogPos, 
                    bra_dlg_dialog_delete, 
                    NULL,
                    bra_dlg_dialog_action);

  return;
}
/********************************************************************************
 * Status dialog
 * 
 * bra_dlg_create_status_dlg
 * bra_dlg_status_dialog_delete
 * bra_dlg_status_dialog_close
 *
 ********************************************************************************/

static void 
bra_dlg_status_dialog_delete(bra_win_t *win)
{
  bra_dlg_status_dialog_t *p;
  
  p = (bra_dlg_status_dialog_t *)(win);
  
 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

  MSF_WIDGET_RELEASE (p->windowHandle);

  BRA_FREE (win);
}

/*
 * Displays a modal status message that can not be dismised by the user.
 * The dialog is closed by calling the bra_dlg_notificationDialogClose function
 * This dialog is typically used to display a status message while saving or 
 * processing some time consuming event.
 *
 * PARAMETERS
 *
 * text      : The text to be displayed in the dialog
 * in_focus  : A pointer to a function which will be called each time the dialog
 *             gets focus.
 *
 * RETURN    : void
 */
void 
bra_dlg_create_status_dlg (MsfStringHandle text, bra_win_in_focus_t in_focus)
{
  bra_dlg_status_dialog_t *dlg;
  MsfGadgetHandle gadget;
  MsfSize         dlgSize;
  MsfSize         strSize;
  MsfPosition     dlgPos;
  MsfPosition     strPos;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  dlgSize.width = (MSF_INT16)(prop.displaySize.width - (2*10));
  dlgSize.height = (MSF_INT16)(prop.displaySize.height - 60);

  strSize.width = (MSF_INT16)(dlgSize.width - (2*10));
  strSize.height = (MSF_INT16)(dlgSize.height - (2*10));

  dlg = BRA_ALLOCTYPE (bra_dlg_status_dialog_t);

	dlg->windowHandle = MSF_WIDGET_FORM_CREATE (MSF_MODID_BRA, &dlgSize, 0x8000, 0);

	gadget = MSF_WIDGET_STRING_GADGET_CREATE (MSF_MODID_BRA, text, &strSize, 0, 0x8000, 0);

  /*Calculate dlg position and text position*/
  dlgPos.x = (MSF_INT16)((prop.displaySize.width / 2) - (dlgSize.width / 2));
  dlgPos.y = (MSF_INT16)((prop.displaySize.height / 2) - (dlgSize.height / 2));

  strPos.x = (MSF_INT16)((dlgSize.width / 2) - (strSize.width / 2));
  strPos.y = (MSF_INT16)((dlgSize.height / 2) - (strSize.height / 2));


	MSF_WIDGET_WINDOW_ADD_GADGET (dlg->windowHandle, gadget, &strPos, 0);
	MSF_WIDGET_GADGET_SET_PROPERTIES (gadget, 0);

  MSF_WIDGET_RELEASE (gadget);
	/*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG_STATUS_DLG, 
                    (bra_win_t*)dlg, 
                    &dlgPos, 
                    bra_dlg_status_dialog_delete, 
                    in_focus,
                    bra_dlg_widget_action_title_url);
}

/*
 * This function closes the above described dialog
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_dlg_status_dialog_close (void)
{

  bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);

}

/********************************************************************************
 * Input dialog..
 * 
 * bra_dlg_create_input_form
 * bra_dlg_input_form_in_focus
 * bra_dlg_delete_input_form
 * bra_dlg_action_input_form
 *
 ********************************************************************************/

static void
bra_dlg_action_input_form (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_dlg_input_dialog_t *dlg;
  MsfStringHandle msfStr;
  char *str;
  int   length;  
  
  dlg = (bra_dlg_input_dialog_t *)(win);

  if (bra_action == dlg->ok)
  {
    if (dlg->callback == NULL)
      return;

    msfStr = MSF_WIDGET_STRING_CREATE_TEXT (MSF_MODID_BRA, dlg->input, 0);

    length = MSF_WIDGET_STRING_GET_LENGTH (msfStr, 1, MsfUtf8);
    
    str = (char *)BRA_ALLOC (length + 1);
    
    MSF_WIDGET_STRING_GET_DATA(msfStr, str, MsfUtf8);

    str[length] = '\0';

    MSF_WIDGET_RELEASE(msfStr); 

    /*The callback is presponsible for deallocating the memory if valid*/
    if ((dlg->callback)(str) == 0)
    {   
      BRA_FREE (str);
      return;
    }
  }
      
  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
}

static void
bra_dlg_delete_input_form (bra_win_t *win)
{
  bra_dlg_input_dialog_t *dlg;
  
  dlg = (bra_dlg_input_dialog_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), dlg->window); 

	MSF_WIDGET_RELEASE (dlg->window); 
	MSF_WIDGET_RELEASE (dlg->cancel);
	MSF_WIDGET_RELEASE (dlg->ok);
	MSF_WIDGET_RELEASE (dlg->input);

  BRA_FREE (win);
}


static void
bra_dlg_input_form_in_focus (bra_win_t *win)
{
  bra_dlg_input_dialog_t *dlg;
  
  dlg = (bra_dlg_input_dialog_t *)(win);

  MSF_WIDGET_SET_IN_FOCUS (dlg->input, 1);
}


/*
 * This function create a input dialog with one input field. The Callback
 * is responsible for validating the input. If the callback returns 1 the 
 * dialog will be dismised. If for some reason the input is determined to 
 * be invalid the callback might raise a error dialog and return 0.
 * 
 * NOTE! It is the callers responsibility to free the response if, and only if,
 * the callback returns 1
 *
 * PARAMETERS
 *
 * title       : Dialog title
 * text_type   : Input field text type (MsfTextType)
 * detault_text: Default text in the input field
 * max_n_chars : Max number of character the user are allowed to enter
 * callback    : Function which will handle the responce
 *
 * RETURN      : void
 */
void
bra_dlg_create_input_form (MsfStringHandle title, MsfTextType text_type, MsfStringHandle detault_text, int max_n_chars, bra_dlg_input_response_t callback)
{
  bra_dlg_input_dialog_t *dlg;
	const MsfPosition win_pos = BRA_CFG_MENU_POS;
	MsfPosition	pos =  {5, 15};
	MsfSize			      size;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  dlg = BRA_ALLOCTYPE (bra_dlg_input_dialog_t);

  size.width  = (MSF_INT16)(prop.displaySize.width - (2 * BRA_DLG_INPUT_FIELD_MARGIN));
  size.height = BRA_DLG_INPUT_FIELD_HEIGHT;
  
  /*Create Form*/
	dlg->window = MSF_WIDGET_FORM_CREATE (MSF_MODID_BRA, &prop.displaySize, 0x8000, 0);
	MSF_WIDGET_SET_TITLE (dlg->window, title);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (dlg->window,
                                   MSF_WINDOW_PROPERTY_TITLE);

	/* Action OK */
	dlg->ok = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
	MSF_WIDGET_ADD_ACTION(dlg->window, dlg->ok);
	/* Action back */
	dlg->cancel = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_CANCEL, MsfBack, 3, 0x8000);
	MSF_WIDGET_ADD_ACTION(dlg->window, dlg->cancel);

  /*Add URL Input field*/
  dlg->input = MSF_WIDGET_TEXT_INPUT_CREATE(MSF_MODID_BRA,
                                            0, /*No initial string*/
                                            0, /*No default string*/
													                  text_type, 
													                  max_n_chars,
                                            TRUE,
													                  &size,
                                            0x8000,
                                            0);

	MSF_WIDGET_GADGET_SET_PROPERTIES(dlg->input, 
                                   MSF_GADGET_PROPERTY_BORDER | MSF_GADGET_PROPERTY_FOCUS);
	MSF_WIDGET_WINDOW_ADD_GADGET(dlg->window, 
                               dlg->input, 
                               (MsfPosition*)&pos, 
                               0);
  MSF_WIDGET_TEXT_SET_TEXT (dlg->input,
                            0,
                            text_type,
                            max_n_chars,
                            detault_text,
                            1/*Single line*/);


  dlg->callback = callback;  

  bra_win_show_window (BRA_WIN_ID_DLG_INPUT_DLG, 
                      (bra_win_t*)dlg, 
                      (MsfPosition*)&win_pos, 
                      bra_dlg_delete_input_form, 
                      bra_dlg_input_form_in_focus,
                      bra_dlg_action_input_form);


}

/********************************************************************************
 * Options dialog
 * 
 * bra_dlg_create_opt_menu
 * bra_dlg_delete_opt_menu
 * bra_dlg_action_opt_menu
 *
 ********************************************************************************/
static void
bra_dlg_delete_opt_menu (bra_win_t *win)
{
  bra_dlg_opt_menu_t *dlg;
  
  dlg = (bra_dlg_opt_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), dlg->window); 

	MSF_WIDGET_RELEASE (dlg->window); 
	MSF_WIDGET_RELEASE (dlg->ok);
	MSF_WIDGET_RELEASE (dlg->cancel);

  BRA_FREE (win);
}

static void 
bra_dlg_action_opt_menu (bra_win_t *win, MsfActionHandle bra_action)
{
  bra_dlg_opt_menu_t *dlg;
  int i = -1;
  int j = 0;
  
  dlg = (bra_dlg_opt_menu_t *)(win);
  
	if (bra_action == dlg->ok){

    while (j < dlg->n_options)
    {
		  if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (dlg->window, j) & MSF_CHOICE_ELEMENT_SELECTED)
        i = j;
      j++;
    }
  }

  if (dlg->callback != NULL)
    (dlg->callback)(i);

  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
}


/*
 * This function creates an option group from where the user can select one item.
 * The index of the selected item is returned in the callback. If no item where 
 * selected the callback return -1.
 *
 * PARAMETERS
 *
 * title     : Dialog title
 * n_options : Number of options in the group
 * opt_list  : Array of item string index 
 * selected  : Index of the pre-selected item.
 * callback  : Functin which will handle the response
 *
 * RETURN    :
 */
void 
bra_dlg_create_opt_menu (MsfStringHandle title, 
                         int n_options, 
                         const int opt_list[],
                         int selected,
                         bra_dlg_opt_response_t callback)
{
  bra_dlg_opt_menu_t *dlg;
	MsfPosition pos = BRA_CFG_MENU_POS;
  int i;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  dlg = BRA_ALLOCTYPE (bra_dlg_opt_menu_t);

  dlg->callback = callback;

  dlg->ok = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfOk, 3, 0x8000);
  dlg->cancel = MSF_WIDGET_ACTION_CREATE (MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 3, 0x8000);
  dlg->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA, 
                                       MsfExclusiveChoice,
												               &prop.displaySize,
												               dlg->ok,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

	MSF_WIDGET_SET_TITLE (dlg->window, title);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (dlg->window,MSF_WINDOW_PROPERTY_TITLE);

  dlg->n_options = n_options;
  for (i = 0; i < n_options; i++)
  { 
	  MSF_WIDGET_CHOICE_SET_ELEMENT (dlg->window, i, 
									                 BRA_STR_GET (opt_list[i]), 0, 0, 0, TRUE); 
  }

  MSF_WIDGET_CHOICE_SET_ELEM_STATE (dlg->window, selected, MSF_CHOICE_ELEMENT_SELECTED);
  
	MSF_WIDGET_ADD_ACTION (dlg->window, 
								 dlg->ok);
	MSF_WIDGET_ADD_ACTION (dlg->window, 
								 dlg->cancel);

  /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_DLG_OPT_MENU, 
                    (bra_win_t*)dlg, 
                    &pos, 
                    bra_dlg_delete_opt_menu, 
                    NULL,
                    bra_dlg_action_opt_menu);
}

MsfStringHandle
bra_dlg_top_dialog_text(void)
{
  bra_dlg_dialog_t *dlg;
  dlg = (bra_dlg_dialog_t *)(bra_win_get_window(BRA_WIN_ID_DLG));
  if(dlg)
    return dlg->text;
  else
    return 0;
}

void 
bra_dlg_set_dialog_callback(bra_action_handle_t callback)
{
  bra_dlg_dialog_t *dlg;
  dlg = (bra_dlg_dialog_t *)(bra_win_get_window(BRA_WIN_ID_DLG));
  if(dlg)
    dlg->pCallback = callback;
} 

bra_action_handle_t
bra_dlg_get_dialog_callback(void)
{
  bra_dlg_dialog_t *dlg;
  dlg = (bra_dlg_dialog_t *)(bra_win_get_window(BRA_WIN_ID_DLG));
  if(dlg)
    return dlg->pCallback;
  return 0;
}
