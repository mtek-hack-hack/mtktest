/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wgui_text_label.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  text label related funtions
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#ifndef __WGUI_TEXT_LABEL_H__
#define __WGUI_TEXT_LABEL_H__
 
#include "wgui.h"
#include "gui_text_label.h"

#define WGUI_TEXT_LABEL_MAX_MAIN_LCD    8
#ifdef __MMI_SUBLCD__
#define WGUI_TEXT_LABEL_MAX_SUB_LCD     4
#endif /*__MMI_SUBLCD__*/

#ifdef __MMI_SUBLCD__
#define WGUI_TEXT_LABEL_MAX (WGUI_TEXT_LABEL_MAX_MAIN_LCD + WGUI_TEXT_LABEL_MAX_SUB_LCD)
#else/*__MMI_SUBLCD__*/
#define WGUI_TEXT_LABEL_MAX WGUI_TEXT_LABEL_MAX_MAIN_LCD
#endif/*__MMI_SUBLCD__*/

extern void wgui_text_label_create(
                U32 text_label_id,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                U8 *title,
                UI_font_type text_font,
                color text_color,
                MMI_BOOL border_enable,
                color border_color,
                gui_util_painter_struct background,
                gui_text_label_align_enum text_h_align_type,
                gui_text_label_align_enum text_v_align_type,
                GDI_HANDLE target_layer,
                GDI_HANDLE target_lcd);
extern void wgui_text_label_close(U32 text_label_id);
extern void wgui_text_label_show(U32 text_label_id);
extern void wgui_text_label_move(U32 text_label_id, S32 x, S32 y);
extern void wgui_text_label_resize(U32 text_label_id, S32 width, S32 height);
extern void wgui_text_label_set_title(U32 text_label_id, U8 *new_title);
extern U8 * wgui_text_label_get_title(U32 text_label_id);
extern void wgui_text_label_set_text_font(U32 text_label_id, UI_font_type new_font);
extern MMI_BOOL wgui_text_label_get_text_font(U32 text_label_id, UI_font_type *text_font);
extern void wgui_text_label_set_text_color(U32 text_label_id, color new_color);
extern MMI_BOOL wgui_text_label_get_text_color(U32 text_label_id, color * text_color);
extern void wgui_text_label_set_border_enable(U32 text_label_id, MMI_BOOL border_enable);
extern MMI_BOOL wgui_text_label_get_border_enable(U32 text_label_id, MMI_BOOL *border_enable);
extern void wgui_text_label_set_border_color(U32 text_label_id, color new_color);
extern MMI_BOOL wgui_text_label_get_border_color(U32 text_label_id, color *border_color);
extern void wgui_text_label_set_background_filler(U32 text_label_id, gui_util_painter_struct new_background);
extern void wgui_text_label_set_text_attribute(
                U32 text_label_id,
                U8 *new_title,
                UI_font_type new_font,
                color new_text_color,
                gui_util_painter_struct new_background);
extern void wgui_text_label_set_border_attribute(U32 text_label_id, MMI_BOOL border_enable, color new_border_color);

#endif /*__WGUI_TEXT_LABEL_H__*/

