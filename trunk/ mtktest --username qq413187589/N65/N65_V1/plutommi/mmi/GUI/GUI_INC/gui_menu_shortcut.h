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
 *  gui_menu_shortcut.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  This file is intends for shortcut
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __GUI_MENU_SHORTCUTS_H__
#define __GUI_MENU_SHORTCUTS_H__

#include "wgui.h"
#include "gui_theme_struct.h"
#include "gui_themes.h"
#include "gui_config.h"

#define GUI_SHORTCUT_MAX_INPUT_LENGTH   4
#define GUI_SHORTCUT_MAX_SIZE  ((GUI_SHORTCUT_MAX_INPUT_LENGTH + 1) * ENCODING_LENGTH)

typedef struct
{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    MMI_BOOL display;                                       /* display or not */
    MMI_BOOL display_enabled;                               /* enable display or not */
    void (*hide_callback) (S32 x1, S32 y1, S32 x2, S32 y2); /* call back function of hide */
    void (*timer_callback) (void);                          /* call back function of timer */
    color normal_text_color;                                /* text color of normal mode */
    color normal_text_border_color;                         /* text border color of normal mode */
    UI_font_type normal_font;                               /* font of normal mode */
    UI_font_type active_font;                               /* font of active mode */
    S32 number;                                             /* number of shortcut */
    S8 use_border;                                          /* draw border or not */
    U8 input_length;                                        /* current length of input */
    UI_character_type input_buffer[GUI_SHORTCUT_MAX_INPUT_LENGTH + 1];  /* buffer of input */
} gui_shortcut_struct;

    /* Menu shortcut wrappers              */

extern U8 menu_shortcut_handler_display;
extern U8 disable_menu_shortcut_box_display;
extern UI_shortcut_box_theme *current_shortcut_box_theme;

extern void gui_shortcut_create(gui_shortcut_struct *sc, S32 x, S32 y, S32 w, S32 h);
extern void gui_shortcut_register_callback(gui_shortcut_struct *sc, void (*timer_callback) (void),
                                           void (*hide_funcptr) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_shortcut_move(gui_shortcut_struct *sc, S32 x, S32 y);
extern S32 gui_shortcut_auto_resize(gui_shortcut_struct *sc, S32 h);
extern void gui_shortcut_close(gui_shortcut_struct *sc);
extern void gui_shortcut_set_item_count(gui_shortcut_struct *sc, S32 n_items);
extern void gui_shortcut_set_theme(gui_shortcut_struct *sc, UI_shortcut_box_theme *th);
extern void gui_shortcut_handler_keyinput(gui_shortcut_struct *sc, UI_character_type c);
extern void gui_shortcut_show(gui_shortcut_struct *sc);
extern void gui_shortcut_set_current_theme(gui_shortcut_struct *sc);
extern S32 gui_shortcut_get_width(gui_shortcut_struct *sc);
extern void gui_shortcut_set_index(gui_shortcut_struct *sc, S32 index);
extern S32 gui_shortcut_get_index(gui_shortcut_struct *sc);
extern MMI_BOOL gui_shortcut_is_show(gui_shortcut_struct *sc);
extern void gui_shortcut_set_show(gui_shortcut_struct *sc, MMI_BOOL show);

#endif /* __GUI_MENU_SHORTCUTS_H__ */ 

