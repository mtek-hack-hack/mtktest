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
 *  wgui_categories_fmgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  File Manager related categories.
 *
 *  [Category212]       Info Style Dynamic List Menu 
 *  [Category213]       Thick Style Dynamic List Menu 
 *  [Category214]       Matrix Style Dynamic Image Menu 
 *
 * Author:
 * -------
 * -------
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
#ifndef __WGUI_CATEGORIES_FMGR_H__
#define __WGUI_CATEGORIES_FMGR_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#define CAT213_ARROW_UP    0x1
#define CAT213_ARROW_DOWN  0x2
#define CAT213_ARROW_LEFT  0x4
#define CAT213_ARROW_RIGHT 0x8
#define CAT213_ARROW_ALL   0xf

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef void (*Cat212DrawInfoFuncPtr) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat212HideInfoFuncPtr) (void);

typedef void (*Cat213DrawMenuItemFuncPtr) (S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat213HideMenuItemFuncPtr) (void);

typedef void (*Cat214DrawImageFuncPtr) (S32 idx, S32 page_star_idx, S32 page_end_idx, BOOL is_hilighted,
                                        BOOL is_need_update, BOOL is_new_page, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat214HideImageFuncPtr) (S32 idx);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern S32 MMI_thick_menuitem_height;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void ShowCategory211Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                S32 info_box_height,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

/* Info style dynamic list category */
extern void ShowCategory212Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

extern void Cat212ShortCutHdlr(S32 item_index);
extern void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2);
extern void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2);

/* Thick style dynamic list category */
extern void ShowCategory213Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
                Cat213HideMenuItemFuncPtr hide_menuitem_callback,
                S32 highlighted_item,
                U8 arrow_flag,
                U8 *history_buffer);

/* Matrix style dynamic image category */
extern void ShowCategory214Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 num_of_items,
                Cat214DrawImageFuncPtr draw_image_callback,
                Cat214HideImageFuncPtr hide_image_callback,
                U8 num_per_row,
                U8 num_per_col,
                S32 highlighted_item,
                U8 *history_buffer);

extern void GetCategory214BoxSize(S32 num_per_row, S32 num_per_col, S32 *box_width_ptr, S32 *box_height_ptr);

#endif /* __WGUI_CATEGORIES_FMGR_H__ */ 

