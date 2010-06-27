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
 * bra_cmn.c
 *
 * Description:
 *		This file contains code for common functionlity
 *		
 */

#include "msf_cfg.h"

#include "bra_win.h"
#include "bra_req.h"
#include "bra_set.h"
#include "bra_cmn.h"
#include "bra_opt.h"
#include "bra_inse.h"
#include "bra_main.h"
#include "bra_str.h"
#include "bra_prof.h"
#include "bra_view.h"
#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif

#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_log.h"
#include "msf_core.h"
#include "msf_file.h"
#include "msf_int.h"
#include "msf_chrt.h"
#include "msf_url.h"
#include "msf_cmmn.h"

#include "wap.h"
#ifdef __SUPPORT_INFUSIO__
extern char support_ege_runtime;
#endif

/************************************************************
 * Local Defines
 ************************************************************/
 #define OBJ_ATTR_LEN 32
/************************************************************
 * Local Types
 ************************************************************/
/************************************************************
 * Global variables
 ************************************************************/

/*Hompage and current page variables*/
static bra_cmn_addr_t	  bra_cmn_homepage_addr;
static bra_cmn_addr_t	  bra_cmn_current_addr;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif




extern void msm_compute_checksum_critical_file_by_index(int idx);

/************************************************************
 * Function definitions
 ************************************************************/

/*
 * This function returns the string value of an integer .
 *
 * PARAMETERS
 *
 * value     : integer value to be converted
 *
 * RETURN    : pointer to a string with the value as a string. It is the 
 *             callers responsibility to free the string.
 */
char*
bra_cmn_int_to_str (int value)
{
  char c;
  char *s;
  char *r;
  char *q;
  int   i;

  r = BRA_ALLOC (11); /*Max int(32) + 1*/
  memset(r, 0, 11); /* zero out memory to avoid UMRs */

  q = s = r; /*Save pointer to string*/

  do
  {
    i = value % 10;
    value /= 10;

    *r++ = (char)(i + '0');
  }while (value > 0);
  
  *r-- = '\0';

  /**/
  while (q < r)
  {
    c  = *q;
    *q++ = *r;
    *r-- = c;
  }

  return s;
}


char*
bra_cmn_strdup_widget_string_data(MsfStringHandle str_handle)
{
    char  *str;
    int    len;
    
    if (str_handle == 0)
        return NULL;
    
    len = MSF_WIDGET_STRING_GET_LENGTH(str_handle, 1, MsfUtf8);
    str = BRA_ALLOC (len + 1);
    MSF_WIDGET_STRING_GET_DATA (str_handle, str, MsfUtf8);
    str[len - 1] = '\0';
    return str;
}

/*
 * This funtion initializes nvigational data such as current address, and hompage.
 * Strings are copied and can be removed when the function returns.
 *
 * PARAMETERS
 *
 * cur_title : pointer to current page title
 * cur_url   : pointer to current page url
 * home_title: MSF string handle to hopage title
 * home_url  : pointer to hopage url
 *
 * RETURN    : void
 */
void 
bra_cmn_init_navigation_items (char* cur_title, char *cur_url, MsfStringHandle	home_title, char *home_url)
{
  /*Current page*/
  bra_cmn_current_addr.title = BRA_STRCONV (cur_title);/*OK*/

  bra_cmn_current_addr.url   = BRA_ALLOC (strlen(BRA_CMN_HNV(cur_url)) + 1);
  strcpy(bra_cmn_current_addr.url, BRA_CMN_HNV(cur_url));

  /*Homepage*/
  if(home_title == 0)
    home_title = BRA_CFG_DEFAULT_HOMPAGE_TITLE;

  bra_cmn_homepage_addr.title = home_title;

  bra_cmn_homepage_addr.url = BRA_ALLOC(strlen(BRA_CMN_HNV (home_url)) + 1) ;
  strcpy(bra_cmn_homepage_addr.url, home_url);
}


/*
 * This function truncates an input UTF8 string to the number of desired characters
 *
 * PARAMETERS
 *
 * input_str       : pointer to zero-termianted UTF8 string
 * trunc_num_chars : max number of characters after truncation
 *
 * RETURN
 *
 * char*           : new pointer to a truncated zero-terminated UTF8 string
 */
char*
bra_cmn_trunc_utf8_str (char *input_str, int trunc_num_chars)
{
  kal_uint8 *trunc_str;
  kal_uint8 *tmp_ucs2_str;
  int num_utf8_bytes;
  int ucs2_len;

  if (widget_utf8_length((const kal_uint8 *)input_str) <= trunc_num_chars)
    return msf_cmmn_strdup(MSF_MODID_BRA, input_str);

  ucs2_len = trunc_num_chars*2;
  tmp_ucs2_str = BRA_ALLOC(ucs2_len+2);
  memset(tmp_ucs2_str, 0, ucs2_len+2);
  widget_utf8_to_ucs2_string(tmp_ucs2_str, ucs2_len+2, (const kal_uint8 *)input_str);
  //msf_charset_utf8_to_ucs2be(input_str, &utf8_len, tmp_ucs2_str, &ucs2_len)
  
  num_utf8_bytes = widget_ucs2_to_utf8_length_in_bytes(tmp_ucs2_str);
  trunc_str = BRA_ALLOC(num_utf8_bytes+1);
  memset(trunc_str, 0, num_utf8_bytes+1);
  widget_ucs2_to_utf8_string(trunc_str, num_utf8_bytes+1, tmp_ucs2_str);

  BRA_FREE(tmp_ucs2_str);
  return (char*)trunc_str;
}


/*
 * This function sets either title, url, or both (depending on the option flag) of 
 * the current page. Strings are copied and can be removed when the function returns.
 *
 * PARAMETERS
 *
 * title     : pointer to current page title
 * url       : pointer to current page url
 * options   : flag as defined above.
 *
 * RETURN    : void
 */
void 
bra_cmn_set_current_page (char* title, char *url, int options)
{
  void* set_handle;
  
  set_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
  MSF_REGISTRY_SET_PATH (set_handle, "/BRA");

#ifdef BRA_CFG_OFFLINE_PAGES	  
  if(bra_ofln_offline_mode() == 1)
    bra_cmn_current_addr.offline_page = TRUE;
  else
    bra_cmn_current_addr.offline_page = FALSE;
#endif

  if (options & BRA_INSE_SET_CURRENT_TITLE)
  {
    MSF_WIDGET_RELEASE (bra_cmn_current_addr.title);
    if (widget_utf8_length((const kal_uint8 *)title) <= BRA_CFG_MAX_NBR_CHARS_TITLE)
    {
        bra_cmn_current_addr.title = BRA_STRCONV (BRA_CMN_HNV (title));/*OK*/
    }
    else
    {
        char* tmp = bra_cmn_trunc_utf8_str(title, BRA_CFG_MAX_NBR_CHARS_TITLE);
        bra_cmn_current_addr.title = BRA_STRCONV (BRA_CMN_HNV (tmp));/*OK*/
        BRA_FREE(tmp);
    }
    MSF_REGISTRY_SET_ADD_KEY_STR (set_handle, BRA_INSE_REG_KEY_CURRENT_TITLE, (unsigned char*)BRA_CMN_HNV (title), (MSF_UINT16)(strlen(BRA_CMN_HNV (title))+1));
  }
  
  if (options & BRA_INSE_SET_CURRENT_URL)
  {
    BRA_FREE (bra_cmn_current_addr.url);
    bra_cmn_current_addr.url   = BRA_ALLOC (strlen(BRA_CMN_HNV(url)) + 1);
    strcpy(bra_cmn_current_addr.url, BRA_CMN_HNV(url));
    MSF_REGISTRY_SET_ADD_KEY_STR (set_handle, BRA_INSE_REG_KEY_CURRENT_URL  , (unsigned char*)BRA_CMN_HNV(url), (MSF_UINT16)(strlen(BRA_CMN_HNV(url))+1));
  }
  
  MSF_REGISTRY_SET_COMMIT (set_handle);

}

/*
 * Returns a pointer to a struct holding the current title and url
 *
 * PARAMETERS
 *
 * RETURN    : Pointer to title and url struct (bra_cmn_addr_t)
 */
bra_cmn_addr_t* 
bra_cmn_get_current_page (void)
{
  return &bra_cmn_current_addr;
}

/*
 * Releases the memory used to hold the current title and url.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_cmn_free_current_page (void)
{
  MSF_WIDGET_RELEASE (bra_cmn_current_addr.title);
  bra_cmn_current_addr.title = 0;

  BRA_FREE (bra_cmn_current_addr.url);
  bra_cmn_current_addr.url = NULL;
}

/*
 * Returns a pointer to a struct holding the homepage title and url 
 *
 * PARAMETERS
 *
 * RETURN    : Pointer to title and url struct (bra_cmn_addr_t)
 */
bra_cmn_addr_t*
bra_cmn_get_homepage (void)
{
	return &bra_cmn_homepage_addr;
}

/*
 * Function to store the current hompage title and url in the registry
 *
 * PARAMETERS
 *
 * title     : Pointer to new homepage title
 * url       : Pointer to new homepage url
 *
 * RETURN    : void
 */
void
bra_cmn_set_homepage(char* title, char* url)
{
  bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_TITLE, title, NULL);
  bra_prof_change_key_str_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_HOMEPAGE_URL, url, NULL);  
}

/*
 * Frees the memory used to hold a copy of the hopage title and url.
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void
bra_cmn_free_local_hompage (void)
{
  MSF_WIDGET_RELEASE (bra_cmn_homepage_addr.title);
  bra_cmn_homepage_addr.title = 0;
  
  BRA_FREE(bra_cmn_homepage_addr.url);
  bra_cmn_homepage_addr.url = NULL;
}

/*
 * This function stores a copy of the title String handle of the 
 * hopage title in RAM
 *
 * PARAMETERS
 *
 * title     : MsfStringHandle to homepage title
 *
 * RETURN    : void
 */
void
bra_cmn_set_local_hompage_title(MsfStringHandle	title)
{ 
  MSF_WIDGET_RELEASE (bra_cmn_homepage_addr.title);
 
  if(title == 0)
    title = BRA_CFG_DEFAULT_HOMPAGE_TITLE;

  bra_cmn_homepage_addr.title = title;

}

/*
 * This function stores a copy of the hopage url in RAM.
 * The string is copyed and can be destroyed when the function returns.
 *
 * PARAMETERS
 *
 * url       : Character pointer to hopage url
 *
 * RETURN    : void
 */
void
bra_cmn_set_local_hompage_url(char *url)
{ 
  BRA_FREE(bra_cmn_homepage_addr.url);
  
  bra_cmn_homepage_addr.url = BRA_ALLOC(strlen(BRA_CMN_HNV (url)) + 1) ;
  strcpy(bra_cmn_homepage_addr.url, url);

}

/*
 * This function create and initializes a MSF Screen, which the BRA uses to
 * display menues and content.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_widget_create_screen (void)
{
  MsfScreenHandle	screen;

	screen = MSF_WIDGET_SCREEN_CREATE (MSF_MODID_BRA, 0, 0);
	if (screen == 0)
	{
		MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_CMN_CDE0905A061AAEBF6E2339149A341159, "BRA: Create screen failed\n"));
	}
	else
	{
    bra_win_init (screen);
	}
}

/*
 * This function is called from external signal recieve function in bra_env.c
 * and dispaches the action to the right window or screen
 *
 * PARAMETERS
 *
 * bra_action: Msf Action handle of the trigered action
 * window    : Handle to the window or screen in which the action ocured
 *
 * RETURN    : void
 */
void
bra_widget_action (MSF_UINT32 bra_action,MSF_UINT32 window)
{
  if(bra_win_current_window() == BRA_WIN_ID_AUTH_DLG && bra_win_handle_action(bra_action , window) == 1)
    return;
   
  if(!bra_view_is_enabled() 
     && bra_win_handle_action(bra_action , window) == 1)
    return;

  bra_win_screen_handle_action(bra_action, window);

}

MsfImageHandle
bra_cmn_get_list_num_image(int i)
{
   i++;
   switch(i)
   {
   case 1:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB1,0);
   case 2:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB2,0);
   case 3:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB3,0);
   case 4:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB4,0);
   case 5:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB5,0);
   case 6:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB6,0);
   case 7:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB7,0);
   case 8:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB8,0);
   case 9:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB9,0);
   case 10:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB10,0);
   case 11:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB11,0);
   case 12:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB12,0);
   case 13:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB13,0);
   case 14:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB14,0);
   case 15:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB15,0);
   case 16:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB16,0);
   case 17:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB17,0);
   case 18:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB18,0);
   case 19:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB19,0);
   case 20:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB20,0);
   case 21:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB21,0);
   case 22:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB22,0);
   case 23:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB23,0);
   case 24:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB24,0);
   case 25:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB25,0);
   case 26:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB26,0);
   case 27:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB27,0);
   case 28:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB28,0);
   case 29:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB29,0);
   case 30:
     return HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_LIST_NB30,0);
   default:
     return 0;
   }
}

MSF_UINT16
bra_cmn_get_list_num_image_enum(int i)
{
   i++;
   switch(i)
   {
   case 1:
     return WAP_IMAGE_SW_LIST_NB1;
   case 2:
     return WAP_IMAGE_SW_LIST_NB2;
   case 3:
     return WAP_IMAGE_SW_LIST_NB3;
   case 4:
     return WAP_IMAGE_SW_LIST_NB4;
   case 5:
     return WAP_IMAGE_SW_LIST_NB5;
   case 6:
     return WAP_IMAGE_SW_LIST_NB6;
   case 7:
     return WAP_IMAGE_SW_LIST_NB7;
   case 8:
     return WAP_IMAGE_SW_LIST_NB8;
   case 9:
     return WAP_IMAGE_SW_LIST_NB9;
   case 10:
     return WAP_IMAGE_SW_LIST_NB10;
   case 11:
     return WAP_IMAGE_SW_LIST_NB11;
   case 12:
     return WAP_IMAGE_SW_LIST_NB12;
   case 13:
     return WAP_IMAGE_SW_LIST_NB13;
   case 14:
     return WAP_IMAGE_SW_LIST_NB14;
   case 15:
     return WAP_IMAGE_SW_LIST_NB15;
   case 16:
     return WAP_IMAGE_SW_LIST_NB16;
   case 17:
     return WAP_IMAGE_SW_LIST_NB17;
   case 18:
     return WAP_IMAGE_SW_LIST_NB18;
   case 19:
     return WAP_IMAGE_SW_LIST_NB19;
   case 20:
     return WAP_IMAGE_SW_LIST_NB20;
   case 21:
     return WAP_IMAGE_SW_LIST_NB21;
   case 22:
     return WAP_IMAGE_SW_LIST_NB22;
   case 23:
     return WAP_IMAGE_SW_LIST_NB23;
   case 24:
     return WAP_IMAGE_SW_LIST_NB24;
   case 25:
     return WAP_IMAGE_SW_LIST_NB25;
   case 26:
     return WAP_IMAGE_SW_LIST_NB26;
   case 27:
     return WAP_IMAGE_SW_LIST_NB27;
   case 28:
     return WAP_IMAGE_SW_LIST_NB28;
   case 29:
     return WAP_IMAGE_SW_LIST_NB29;
   case 30:
     return WAP_IMAGE_SW_LIST_NB30;
   default:
     return 0;
   }
}

#ifdef BRA_USE_CTK_INLINE
ctk_layout_handle bra_cmn_ctk_init_layout(ctk_inline_create_struct *layout_create,
                                          MSF_UINT8 in_num_items,
                                          ctk_image_id in_img_title,
                                          ctk_string_id in_str_title,                                          
                                          ctk_screen_callback_hdlr callback,
                                          kal_bool disable_done)
{
  CTK_INIT_STRUCT(*layout_create);
  layout_create->in_num_items = in_num_items;
  layout_create->in_img_title = in_img_title;
  layout_create->in_str_title = in_str_title;
  layout_create->in_cancel_fp = callback;  
  if(disable_done)
  {
    layout_create->in_set_LSK = KAL_TRUE;
    layout_create->in_disable_done = KAL_TRUE; /* Let RSK be Clear/Back */
  }
  return ctk_inline_create(HDIa_widgetCtkGetApp(), layout_create);
}

void bra_cmn_ctk_add_caption(ctk_layout_handle layoutid, 
                             int idx, 
                             MSF_UINT16 str_handle,
                             MSF_UINT16 img_handle) 
                             
{
  ctk_inline_item_caption_copy_struct		caption_create;

  CTK_INIT_STRUCT(caption_create);
  caption_create.title = (ctk_string_id)str_handle;
  ctk_inline_set_item_copy(layoutid, idx, img_handle, str_handle, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);
}

void bra_cmn_ctk_add_editor(ctk_layout_handle layoutid, 
                            int idx, 
                            ctk_input_type_enum input_type,
                            MSF_INT32 max_len,
                            char *default_text,
                            MSF_UINT16 str_handle,
                            MSF_UINT16 img_handle)                             
{
  ctk_inline_item_editor_copy_struct		editor_create;

  CTK_INIT_STRUCT(editor_create); 
  editor_create.input_type = input_type;
  editor_create.max_len = max_len;
  editor_create.default_text = (MSF_UINT8*)default_text;
  editor_create.is_UTF8 = KAL_TRUE;
  editor_create.str_title = str_handle;
  editor_create.img_title = img_handle;
  editor_create.use_input_method_menu = TRUE;
  ctk_inline_set_item_copy(layoutid, idx, 0, 0, CTK_INLINE_ITEM_TYPE_EDITOR, &editor_create);
}

void bra_cmn_ctk_add_display(ctk_layout_handle layoutid, 
                             int idx, 
                             char *text,
                             MSF_UINT16 title_handle,
                             MSF_UINT16 lsk_handle,
                             ctk_void_callback_hdlr callback)                             
{
  ctk_inline_item_display_only_copy_struct	display_create;

  CTK_INIT_STRUCT(display_create);
  display_create.is_UTF8 = KAL_TRUE;
  display_create.text = (MSF_UINT8*)text;
  display_create.edit_fp = callback;
  display_create.edit_strid = lsk_handle;
  ctk_inline_set_item_copy(layoutid, idx, 0, title_handle, CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY, &display_create);
}

void bra_cmn_ctk_add_select(ctk_layout_handle layoutid, 
                            int idx, 
                            MSF_INT32 num_options,
                            MSF_UINT16 *list_options_strid,
                            int highlighted) 
{
  ctk_inline_item_select_copy_struct		select_create;	

  CTK_INIT_STRUCT(select_create);
  select_create.highlighted = highlighted;
  select_create.num_options = num_options;
  select_create.list_options_strid = list_options_strid;
  ctk_inline_set_item_copy(layoutid, idx, 0, 0, CTK_INLINE_ITEM_TYPE_SELECT, &select_create);
}

void bra_cmn_ctk_add_single_line_editor(ctk_layout_handle layoutid, 
                                        int idx, 
                                        MSF_INT32 max_len,
                                        char *default_text)
{
  ctk_inline_item_single_line_copy_struct single_line_create;

  CTK_INIT_STRUCT(single_line_create);
  single_line_create.input_type = 0;
  single_line_create.max_len = max_len;
  single_line_create.default_text = (MSF_UINT8*)default_text;
  single_line_create.is_UTF8 = KAL_TRUE;
  single_line_create.activation = CTK_INLINE_ACTIVATION_AUTO;
  ctk_inline_set_item_copy(layoutid, idx, 0, 0, CTK_INLINE_ITEM_TYPE_SINGLE_LINE, &single_line_create);
}

void bra_cmn_ctk_add_ip_editor(ctk_layout_handle layoutid, 
                               int idx, 
                               unsigned char *ip)
{
  ctk_inline_item_IP4_copy_struct		ip_editor_create;

  CTK_INIT_STRUCT(ip_editor_create); 
  ip_editor_create.IP[0] = ip[0];
  ip_editor_create.IP[1] = ip[1];
  ip_editor_create.IP[2] = ip[2];
  ip_editor_create.IP[3] = ip[3];
  ctk_inline_set_item_copy(layoutid, idx, 0, 0, CTK_INLINE_ITEM_TYPE_IP4, &ip_editor_create);
}

ctk_screen_handle bra_cmn_ctk_screen_create(ctk_layout_handle layoutid, 
                                            ctk_screen_callback_hdlr softkey_hdlr)
{
  ctk_screen_handle scrid;

  // Create CTK screen
  scrid = widget_ctk_screen_create();
	
  // set key
  ctk_screen_add_inline_Done_UA(scrid, NULL, softkey_hdlr, KAL_TRUE);

  ctk_screen_attach_layout(scrid, layoutid);

  return scrid;
}

char* bra_cmn_ctk_get_input_result(ctk_layout_handle layoutid,                
                                   ctk_inline_item_type_enum type,
                                   int idx)
{
  ctk_inline_item_type_enum	item_type;
  ctk_inline_result_union     item_value;
  char *result;
  int len;

  ctk_inline_get_result(layoutid, idx, &item_type, &item_value);
  ASSERT(item_type == type);

  if (item_value.input_buffer && (item_value.input_buffer != '\0' || (item_value.input_buffer+1) != '\0'))
  {
    len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);
    result = BRA_ALLOC(len+1);
    widget_ucs2_to_utf8_string((kal_uint8 *) result, len+1, (kal_uint8 *)item_value.input_buffer);
    return result;
  }
  else
  {
    result = BRA_ALLOC(1);
    result[0] = '\0';
  }

  return result;
}

int bra_cmn_ctk_get_select_result(ctk_layout_handle layoutid,                
                                  ctk_inline_item_type_enum type,
                                  int idx)
{
  ctk_inline_item_type_enum	item_type;
  ctk_inline_result_union     item_value;

  ctk_inline_get_result(layoutid, idx, &item_type, &item_value);
  ASSERT(item_type == type && type == CTK_INLINE_ITEM_TYPE_SELECT);
  return item_value.select_highlight;
}

#endif

void bra_cmn_save_done_dialog(void)
{
  HDIa_widgetExtShowPopup(MSF_MODID_BRA, MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_DONE), MsfPromptSaveDone,0);
}

void bra_cmn_saved_dialog(void)
{
  HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_SAVED, MsfPromptSaveDone,0);
}

void bra_cmn_deleted_dialog(void)
{
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DELETED, MsfPromptSaveDone,0);
}

MSF_UINT8
bra_cmn_get_address (const char *s, unsigned char *addr)
{
  int         i, j, len;
  int         tmpaddr[4];
  char        tmp[8];
  const char *q;

  if (strlen (s) == 0) {
    return 0;
  }
  if (!ct_isdigit (s[0])) {
    return 0;
  }

  for (i = 0; i < 4; i++)
    tmpaddr[i] = 0;

  for (i = 0; i < 4; i++) {
    q = strchr (s, '.');
    if (q == NULL) {
      if (i != 3)
        return 0;
      len = strlen (s);
    }
    else
      len = q - s;
    if ((len == 0) || (len > 3))
      return 0;
    for (j = 0; j < len; j++) {
      if (!ct_isdigit (s[j]))
        return 0;
      tmp[j] = s[j];
    }
    tmp[len] = '\0';
    tmpaddr[i] = atoi (tmp);
    if (tmpaddr[i] > 255)
      return 0;
    if (q != NULL) {
      s = q + 1;
    }
  }

  for (i = 0; i < 4; i++) {
    addr[i] = (MSF_UINT8)tmpaddr[i];
  }

  return 4;
}

char*
bra_cmn_remove_string_blank(const char *str)
{
  int       len;
  char      *temp;


  if (!str)
    return 0;
  temp = msf_cmmn_skip_blanks((const char*)str);   
  len = msf_cmmn_skip_trailing_blanks(temp, strlen(temp));
  return msf_cmmn_strndup(MSF_MODID_BRA, temp, len);
}

int
bra_cmn_url_is_valid (char* url)
{
	char *host = 0;
    char *tmpurl = 0;
    char *trimmed_url = 0;
    char *schemestr = 0;
    char *portstr = 0;
    int ret = TRUE;

	if(url == NULL)
        return FALSE;

   trimmed_url = bra_cmn_remove_string_blank(url);  
   tmpurl = msf_url_make_complete (MSF_MODID_BRA, trimmed_url);

   schemestr = msf_url_get_scheme(MSF_MODID_BRA, tmpurl);
#ifdef __SUPPORT_INFUSIO__
   if (schemestr && strcmp(schemestr, "ege")==0 && support_ege_runtime)
   {
	 ret = TRUE;
     goto check_complete;
   }
#endif  /* __SUPPORT_INFUSIO__ */

   if(tmpurl == NULL || 
      !msf_url_is_valid(tmpurl) || 
      msf_url_get_scheme_type(tmpurl) == msf_scheme_empty)
	{
        ret = FALSE;
        goto check_complete;
	}

#ifdef BRA_CFG_ENABLE_FILE_SCHEME
   if (schemestr && strcmp(schemestr, "file")==0)
   {
     ret = TRUE;
     goto check_complete;
   }
#endif  /* BRA_CFG_ENABLE_FILE_SCHEME */

    portstr = msf_url_get_port(MSF_MODID_BRA, tmpurl);
    if (portstr && atoi(portstr)>65535)
    {
        ret = FALSE;
        goto check_complete;
    }

	if (msf_url_get_scheme_type(tmpurl) == msf_scheme_unknown)
    {
		//char *schemestr = msf_url_get_scheme(MSF_MODID_BRA, tmpurl);
		if (strcmp (schemestr, "rtsp") != FALSE)
		{		
            ret = FALSE;
            goto check_complete;
		}

		host = msf_url_get_host (MSF_MODID_BRA, tmpurl);
		if ((host == NULL))
		{
            ret = FALSE;
			goto check_complete;
		}
	}
	else
	{	
		host = msf_url_get_host (MSF_MODID_BRA, tmpurl);
		if ((host == NULL) || (*host == '\0'))
		{
            ret = FALSE;
			goto check_complete;
		}
	}

check_complete:
    if (schemestr)  BRA_FREE(schemestr);
    if (trimmed_url)  BRA_FREE(trimmed_url);
    if (tmpurl)  BRA_FREE(tmpurl);
    if (host)  BRA_FREE(host);
    if (portstr)  BRA_FREE(portstr);
	return ret;
}




MSF_BOOL  
bra_cmn_is_menu_item_selected(MsfWindowHandle window, int menu_index)
{
    return (MSF_WIDGET_CHOICE_GET_ELEM_STATE (window, menu_index) & MSF_CHOICE_ELEMENT_SELECTED);
}


void
bra_cmn_check_profile_checksum(void)
{
    msm_compute_checksum_critical_file_by_index(MSM_BACKUP_INDEX_BRA_PROFILE);
}











