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
 * bra_cmn.h
 *
 * Description:
 *		This file contains code for common functionlity
 *
 */


#ifndef _bra_cmn_h
#define _bra_cmn_h

#ifndef _bra_cfg_h
#include "bra_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_int_h                    
#include "msf_int.h"
#endif
#ifndef _msf_wid_h
#include "msf_wid.h"
#endif

#ifndef _widget_extension_h
#include "widget_extension.h"
#endif

/******************************************************************************
 * Definitions
 *****************************************************************************/

#define  BRA_CFG_MENU_POS {0,0}

#define	BRA_STRCONV(a)			MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, a, MsfUtf8, strlen(a)+1, 0)

#define BRA_STR_GET(a)      MSF_WIDGET_STRING_GET_PREDEFINED(a)

#define BRA_INSE_REG_KEY_HOMEPAGE_TITLE      "h_title"
#define BRA_INSE_REG_KEY_HOMEPAGE_URL        "h_url"

#define BRA_INSE_REG_KEY_CURRENT_TITLE       "c_title"
#define BRA_INSE_REG_KEY_CURRENT_URL         "c_url"

#define BRA_INSE_SET_CURRENT_TITLE            0x01
#define BRA_INSE_SET_CURRENT_URL              0x02


/******************************************************************************
 * Helper Macros
 *****************************************************************************/

/*This macro converts a null pointer to const string "". HNV = Handle Null Value*/
#define BRA_CMN_HNV(p) ((p != NULL) ? p : "")


/******************************************************************************
 * Types
 *****************************************************************************/


typedef struct {
	MsfStringHandle	title;
	char	*url;
#ifdef BRA_CFG_OFFLINE_PAGES	
   MSF_BOOL offline_page;
#endif   
} bra_cmn_addr_t;


typedef void (*bra_cmn_select_callback_t)(int handle);


/******************************************************************************
 * Functions
 *****************************************************************************/
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
bra_cmn_int_to_str (int value);

char*
bra_cmn_strdup_widget_string_data(MsfStringHandle str_handle);


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
bra_cmn_trunc_utf8_str (char *input_str, int trunc_num_chars);

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
bra_cmn_init_navigation_items (char* cur_title, char *cur_url, MsfStringHandle home_title, char *home_url);

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
bra_cmn_set_current_page(char* title, char *url, int options);

/*
 * Returns a pointer to a struct holding the current title and url
 *
 * PARAMETERS
 *
 * RETURN    : Pointer to title and url struct (bra_cmn_addr_t)
 */
bra_cmn_addr_t* 
bra_cmn_get_current_page(void);

/*
 * Releases the memory used to hold the current title and url.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_cmn_free_current_page (void);

/*
 * Returns a pointer to a struct holding the homepage title and url 
 *
 * PARAMETERS
 *
 * RETURN    : Pointer to title and url struct (bra_cmn_addr_t)
 */
bra_cmn_addr_t*
bra_cmn_get_homepage (void);

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
bra_cmn_set_homepage(char* title, char* url);

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
bra_cmn_set_local_hompage_title (MsfStringHandle title);

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
bra_cmn_set_local_hompage_url (char *url);

/*
 * Frees the memory used to hold a copy of the hopage title and url.
 *
 * PARAMETERS
 * 
 * RETURN    : void
 */
void
bra_cmn_free_local_hompage (void);

/*
 * This function create and initializes a MSF Screen, which the BRA uses to
 * display menues and content.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_widget_create_screen (void);

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
bra_widget_action (MSF_UINT32 bra_action,MSF_UINT32 window);

MsfImageHandle
bra_cmn_get_list_num_image(int i);

MSF_UINT16
bra_cmn_get_list_num_image_enum(int i);

#ifdef BRA_USE_CTK_INLINE
ctk_layout_handle bra_cmn_ctk_init_layout(ctk_inline_create_struct *layout_create,
                                          MSF_UINT8 in_num_items,                                          
                                          ctk_image_id in_img_title,
                                          ctk_string_id in_str_title,
                                          ctk_screen_callback_hdlr callback,
                                          kal_bool disable_done);

void bra_cmn_ctk_add_caption(ctk_layout_handle layoutid, 
                             int idx, 
                             MSF_UINT16 str_handle,
                             MSF_UINT16 img_handle);

void bra_cmn_ctk_add_editor(ctk_layout_handle layoutid, 
                            int idx, 
                            ctk_input_type_enum input_type,
                            MSF_INT32 max_len,
                            char *default_text,
                            MSF_UINT16 str_handle,
                            MSF_UINT16 img_handle);

void bra_cmn_ctk_add_display(ctk_layout_handle layoutid, 
                             int idx, 
                             char *text,
                             MSF_UINT16 str_handle,
                             MSF_UINT16 lsk_handle,
                             ctk_void_callback_hdlr callback);

void bra_cmn_ctk_add_select(ctk_layout_handle layoutid, 
                            int idx, 
                            MSF_INT32 num_options,
                            MSF_UINT16 *list_options_strid,
                            int highlighted);

void bra_cmn_ctk_add_single_line_editor(ctk_layout_handle layoutid, 
                                        int idx, 
                                        MSF_INT32 max_len,
                                        char *default_text);

void bra_cmn_ctk_add_ip_editor(ctk_layout_handle layoutid, 
                               int idx, 
                               unsigned char *ip);

ctk_screen_handle bra_cmn_ctk_screen_create(ctk_layout_handle layoutid, 
                                            ctk_screen_callback_hdlr softkey_hdlr);

char* bra_cmn_ctk_get_input_result(ctk_layout_handle layoutid,
                                   ctk_inline_item_type_enum type,
                                   int idx);


int bra_cmn_ctk_get_select_result(ctk_layout_handle layoutid,                
                                  ctk_inline_item_type_enum type,
                                  int idx);                                
#endif /*BRA_USE_CTK_INLINE*/

void bra_cmn_save_done_dialog(void);

void bra_cmn_saved_dialog(void);

void bra_cmn_deleted_dialog(void);

MSF_UINT8 bra_cmn_get_address (const char *s, unsigned char *addr);


/*
 * This function check the validity of a URL
 *
 * PARAMETERS
 *
 * url       : Character pointer to a url
 *
 * RETURN    : TRUE if the URL is valid, FALSE otherwise.
 */
int
bra_cmn_url_is_valid (char* url);

/*
 * This function remove the blank at the frond and at the end of the specified string.
 *
 * PARAMETERS
 *
 * str       : string to remove blank
 *
 * RETURN    : a new string without frontal blank and trailed blank.
 */
char*
bra_cmn_remove_string_blank(const char *str);


MSF_BOOL  bra_cmn_is_menu_item_selected(MsfWindowHandle window, int menu_index);


void
bra_cmn_check_profile_checksum(void);

#endif /*_bra_cmn_h*/





