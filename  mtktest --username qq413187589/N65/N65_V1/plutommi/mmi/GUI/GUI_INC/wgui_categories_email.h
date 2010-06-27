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

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_categories_email.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef WGUI_CATEGORIES_EMAIL_H
#define  WGUI_CATEGORIES_EMAIL_H
/********** EMAIL SCREEN START **********/
extern void ShowCategory251Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 screen_look);
extern void DrawCategory251InfoBox(U8 *, U8 *);
extern void RedrawCategory251InfoBox(U8 *, U8 *);

extern void ShowCategory252Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U16 *list_of_icons1,
                S32 highlighted_item,
                U8 *history_buffer,
                U8 screen_look);
extern void DrawCategory252InfoBox(U16, U8 *, U8 *);
extern void RedrawCategory252InfoBox(U16, U8 *, U8 *);

extern void ShowCategory253Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items1,
                U8 **list_of_items2,
                U16 *list_of_icons1,
                U16 *list_of_icons2,
                U16 *list_of_icons3,
                U16 *list_of_icons4,
                U8 *n_of_icons2,
                S32 highlighted_item,
                U8 *history_buffer);

extern UI_string_type get_asyncdynamic_item_text(S32 index);
extern void asyncdynamic_list_highlight_handler(S32 item_index);
extern void set_asyncdynamic_pop_up_descriptions(S32 highlighted_item);
extern void ShowCategory261Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U16 attach_icon,
                U8 *history_buffer,
                S32 no_of_string,
                S32 no_of_icons,
                S32 *category_error_flag);
extern void ExitCategory261Screen(void);

extern void ShowCategory262Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

extern void RedrawCategory263InfoBox(U8 *infoText1, U8 *infoText2);
extern void ShowCategory263Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);

#endif /* WGUI_CATEGORIES_EMAIL_H */ 
/********** EMAIL SCREEN END **********/

