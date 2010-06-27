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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  wgui_categories_IMPS.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  IMPS related categories. 
 *
 *  [Category420]       About Me Screen
 *  [Category425]       Contact List Screen
 *  [Category435]       Chat Screen with Popup Editor
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_IMPS_H__
#define __WGUI_CATEGORIES_IMPS_H__

#include "wgui_categories_inputs.h"
#include "wgui_tab_bars.h"
#include "wgui_categories.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* Category 420 */
extern void ShowCategory420Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type name,
                S8 *photo_filename,
                U16 alternative_photo,
                U16 mood_caption,
                UI_string_type mood_string,
                PU8 mood_icon,
                U16 status_caption,
                UI_string_type status_string,
                PU8 status_icon,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);

/* Category 425 */
extern void ShowCategory425Screen(
                UI_string_type title,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                PU8 sample_icon,
                PU8 sample_icon2,
                S32 highlighted_item,
                U8 *history_buffer,
                BOOL *list_is_ready_p);

extern void RefreshCategory425Screen(S32 number_of_items, S32 highlighted_item);

extern void UpdateCategory425TabBar(UI_string_type title, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items);
extern void SetCategory425TabSelectCallback(void (*select_callback) (int index));
extern void Category425BlinkTab(S8 tab);
extern void Category425UnBlinkTab(S8 tab);


#ifndef __MMI_MAINLCD_128X128__
/* Category 426: PictBridge image selection */

/* Item callback to get data in category 426 */
typedef void (*wgui_cat426_thumbnail_callback_type)(
                S32 index,                  /* [IN] menu item index */
                U8 *image_filename,         /* [OUT] thumbnail image */                
                S32 max_filename_size,      /* [IN] buffer size of 'image_filename' in bytes */
                U16 *default_image_id       /* [OUT] default_image_id */
                );

extern void ShowCategory426Screen(
                U16 title,
                U16 title_icon,                
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                MMI_ID_TYPE checkbox_on_icon,
                MMI_ID_TYPE checkbox_off_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_callback,
                wgui_cat426_thumbnail_callback_type get_thumbnail_callback,
                U8 checkbox_values[],                
                U8* cache_buffer,
                S32 cache_buffer_size,
                S32 highlighted_item,
                U8 *history_buffer);

extern void RefreshCategory426Screen(void);
#endif

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
extern void ShowCategoryNSM2Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type name,
                S8 *photo_filename,
                U16 alternative_photo,
                U16 mood_caption,
                UI_string_type mood_string,
                PU8 mood_icon,
                U16 status_caption,
                UI_string_type status_string,
                PU8 status_icon,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);

extern void RedrawCategoryNSM2Screen(void);
extern void ExitCategoryNSM2Screen(void);
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 

/* Category 430 */
extern void ShowCategory430Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *log_buffer1,
                S16 log_buffer_size1,
                U8 *log_buffer2,
                S16 log_buffer_size2,
                MMI_BOOL show_sending_buffer,
                S16 max_sending_buffer_size,
                U8 *sending_buffer,
                S16 sent_count,
                U8 *name1,
                U8 *name2,
                U8 *history_buffer);

extern void UpdateCategory430LSK(U16 left_softkey, U16 left_softkey_icon);
extern void UpdateCategory430RSK(U16 right_softkey, U16 right_softkey_icon);

extern void UpdateCategory430LogBox(MMI_BOOL update_log1, MMI_BOOL update_log2);

extern void ConfigureCategory430SendingBox(MMI_BOOL show_sending_buffer, S16 sent_count);
extern void SetCategory430SendingBoxCharacterCount(S16 sent_count);

/* Category 435 */
extern void ShowCategory435Screen(
                UI_string_type title,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 editor_left_softkey,
                U16 editor_left_softkey_icon,
                U16 editor_right_softkey,
                U16 editor_right_softkey_icon,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                BOOL show_popup,
                UI_string_type popup_title,
                S16 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *log_buffer,
                S32 log_buffer_size,
                multi_line_input_box_icon_hdlr icon_callback,
                PU8 sample_icon,
                U8 *history_buffer);

void SetCategory435EditorRSKFunction(void (*f) (void));
void SetCategory435EditorLSKFunction(void (*f) (void));
void SetCategory435RSKFunction(void (*f) (void));
void SetCategory435LSKFunction(void (*f) (void));

extern void UpdateCategory435LogText(U8 *log_buffer, S32 log_buffer_size);
extern void UpdateCategory435LogAndEditorText(U8 *buffer, S32 buffer_size, U8 *log_buffer, S32 log_buffer_size);
extern void Category435ShowPopup(BOOL update_screen);
extern void Category435HidePopup(BOOL update_screen);

extern BOOL Category435IsPopupDisplayed(void);
extern void Category435DirectInsertString(UI_string_type s, BOOL redraw_screen);

extern void UpdateCategory435TabBar(UI_string_type title, S8 n_tabs, S8 highlighted_tab, tab_bar_item_type *tab_items);
void SetCategory435TabSelectCallback(void (*select_callback) (int index));
extern void Category435BlinkTab(S8 tab);
extern void Category435UnBlinkTab(S8 tab);

#endif /* __WGUI_CATEGORIES_IMPS_H__ */ 

