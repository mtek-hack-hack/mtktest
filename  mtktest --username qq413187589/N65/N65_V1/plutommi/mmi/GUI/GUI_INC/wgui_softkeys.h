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
 *   wgui_softkeys.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  softkey related funtions
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *  
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * rebase maintrunk.MAUI_MBJ on 2007-3-17 23:21:53.
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 */

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

/**********************************************************************************
   Filename:      wgui_softkeys.h
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines header for softkeys
**********************************************************************************/

#ifndef __WGUI_SOFTKEYS_H__
#define __WGUI_SOFTKEYS_H__
#include "wgui_softkeys_pre_oem.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "ScreenRotationGprot.h"
#include "wgui_categories_defs.h"
#include "wgui_categories_util.h"
#include "wgui_softkeys_post_oem.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "wgui.h"

/* Softkey wrappers        */
extern icontext_button MMI_softkeys[WGUI_MAX_SOFTKEYS];

#define  MMI_left_softkey  MMI_softkeys[MMI_LEFT_SOFTKEY]
#define MMI_right_softkey  MMI_softkeys[MMI_RIGHT_SOFTKEY]

#ifdef __MMI_WGUI_CSK_ENABLE__
#define  MMI_center_softkey   MMI_softkeys[MMI_CENTER_SOFTKEY]
#endif 
#define WGUI_SOFTKEY_STRING_GAP  4
   
extern MMI_BOOL MMI_softkey_filler_disabled;

    extern S32 MMI_softkey_width;
    extern S32 MMI_softkey_height;

    extern U8 left_softkey_keyboard_handler_active;
    extern U8 right_softkey_keyboard_handler_active;
#ifdef __MMI_GUI_CSK_ENABLE__
    extern U8 center_softkey_keyboard_handler_active;
#endif 

#define resize_left_softkey_by_string_length( S )  resize_softkey_by_string_length(S,MMI_LEFT_SOFTKEY)
#define resize_right_softkey_by_string_length( S ) resize_softkey_by_string_length(S,MMI_RIGHT_SOFTKEY)
#define resize_left_softkey(WIDTH, HEIGHT )     resize_softkey(WIDTH, HEIGHT,MMI_LEFT_SOFTKEY)
#define resize_right_softkey( WIDTH, HEIGHT )      resize_softkey(WIDTH, HEIGHT,MMI_RIGHT_SOFTKEY)
#define set_left_softkey_label( S )             set_softkey_label(S,MMI_LEFT_SOFTKEY)
#define set_left_softkey_label_for_IME( S )     set_softkey_label_for_IME(S,MMI_LEFT_SOFTKEY)
#define set_right_softkey_label( S )            set_softkey_label(S,MMI_RIGHT_SOFTKEY)
#define get_left_softkey_label()                get_softkey_label(MMI_LEFT_SOFTKEY)
#define get_right_softkey_label()               get_softkey_label(MMI_RIGHT_SOFTKEY)
#define set_left_softkey_icon( ICON )           set_softkey_icon(ICON,MMI_LEFT_SOFTKEY)
#define set_right_softkey_icon( ICON )          set_softkey_icon(ICON,MMI_RIGHT_SOFTKEY)
#define change_left_softkey(S,I)             change_softkey(S,I,MMI_LEFT_SOFTKEY)
#define change_right_softkey(S,I)               change_softkey(S,I,MMI_RIGHT_SOFTKEY)
#define set_left_softkey_function(FUNC, KEY_TYPE)  set_softkey_function(FUNC,KEY_TYPE,MMI_LEFT_SOFTKEY)
#define set_right_softkey_function(FUNC, KEY_TYPE) set_softkey_function(FUNC,KEY_TYPE,MMI_RIGHT_SOFTKEY)
#define get_left_softkey_function(KEY_TYPE)     get_softkey_function(KEY_TYPE,MMI_LEFT_SOFTKEY)
#define get_right_softkey_function(KEY_TYPE)    get_softkey_function(KEY_TYPE,MMI_RIGHT_SOFTKEY)
#define execute_left_softkey_function(KEY_TYPE) execute_softkey_function(KEY_TYPE,MMI_LEFT_SOFTKEY)
#define execute_right_softkey_function(KEY_TYPE)   execute_softkey_function(KEY_TYPE,MMI_RIGHT_SOFTKEY)
#define set_left_softkey(S, FUNC, KEY_TYPE)     set_softkey(S, FUNC, KEY_TYPE, MMI_LEFT_SOFTKEY)
#define set_right_softkey(S, FUNC, KEY_TYPE)    set_softkey(S, FUNC, KEY_TYPE, MMI_RIGHT_SOFTKEY)
#define clear_left_softkey()                 clear_softkey_display_functions(MMI_LEFT_SOFTKEY)
#define clear_right_softkey()                clear_softkey_display_functions(MMI_RIGHT_SOFTKEY)
#define show_left_softkey()                  show_softkey(MMI_LEFT_SOFTKEY)
#define show_right_softkey()                 show_softkey(MMI_RIGHT_SOFTKEY)
#define redraw_left_softkey()                redraw_softkey(MMI_LEFT_SOFTKEY)
#define redraw_right_softkey()               redraw_softkey(MMI_RIGHT_SOFTKEY)
#ifdef __MMI_WGUI_CSK_ENABLE__ //082106 redraw ceter key
#define redraw_center_softkey()               redraw_softkey(MMI_CENTER_SOFTKEY)
#endif
#define register_hide_left_softkey(FUNC)        register_hide_softkey(FUNC, MMI_LEFT_SOFTKEY)
#define register_hide_right_softkey(FUNC)       register_hide_softkey(FUNC, MMI_RIGHT_SOFTKEY)
#define register_left_softkey_handler()         register_softkey_handler(MMI_LEFT_SOFTKEY)
#define register_right_softkey_handler()        register_softkey_handler(MMI_RIGHT_SOFTKEY)
#define clear_left_softkey_handler()            clear_softkey_handler(MMI_LEFT_SOFTKEY)
#define clear_right_softkey_handler()           clear_softkey_handler(MMI_RIGHT_SOFTKEY)
#define reset_left_softkey()                 reset_softkey(MMI_LEFT_SOFTKEY)
#define reset_right_softkey()                reset_softkey(MMI_RIGHT_SOFTKEY)

    extern void create_softkeys(void);
    extern void register_softkey_handler(WGUI_SOFTKEY_ENUM key);
    extern void register_center_softkey_to_enter_key(void);

    extern void set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key);
    extern UI_string_type get_softkey_label(WGUI_SOFTKEY_ENUM key);
    extern void set_softkey_icon(PU8 i, WGUI_SOFTKEY_ENUM key);
    extern void change_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key);
    extern void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
    extern void execute_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
    extern FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
    extern void show_softkey(WGUI_SOFTKEY_ENUM key);
    extern void redraw_softkey(WGUI_SOFTKEY_ENUM key);
    void register_hide_softkey(void (*f) (void), WGUI_SOFTKEY_ENUM key);
    extern void clear_softkey_display_functions(WGUI_SOFTKEY_ENUM key);
    extern void resize_softkey_by_string_length(UI_string_type s, WGUI_SOFTKEY_ENUM key);
    extern void left_softkey_down(void);
    extern void left_softkey_up(void);
    extern void right_softkey_down(void);
    extern void right_softkey_up(void);
    extern void update_softkey_state_no_redraw( U16 KeyCode, U16 KeyType);
    extern void reset_softkeys(void);
    extern void reset_softkey(WGUI_SOFTKEY_ENUM key);
    extern void clear_softkey_handler(WGUI_SOFTKEY_ENUM key);
    extern void enable_softkey_background(void);
    extern void disable_softkey_background(void);
    extern void wgui_softkey_set_filler_disabled(MMI_BOOL filler_disabled);

    /* For Draw Manager  */
    extern void move_softkey(S32 x, S32 y, WGUI_SOFTKEY_ENUM key);
    extern void resize_softkey(S32 width, S32 height, WGUI_SOFTKEY_ENUM key);

    extern void restore_softkeys(void);
    extern void set_softkey_flags_on(S32 flag, WGUI_SOFTKEY_ENUM key);
    extern void set_softkey_flags_off(S32 flag, WGUI_SOFTKEY_ENUM key);

/* Only for input method, Application can not invoke this function*/
	extern void set_softkey_label_for_IME(UI_string_type s, WGUI_SOFTKEY_ENUM key);   

extern void wgui_softkey_get_offset(UI_string_type sk_str_p, S32 *offset_x, S32 *offset_y, WGUI_SOFTKEY_ENUM key);
extern void wgui_softkey_get_offset_ex(UI_string_type sk_str_p, S32 *offset_x, S32 *offset_y, WGUI_SOFTKEY_ENUM key, mmi_frm_screen_rotate_enum rotate_degree);


#ifdef __MMI_TOUCH_SCREEN__
    extern BOOL translate_softkey_pen_event(
                    WGUI_SOFTKEY_ENUM key,
                    mmi_pen_event_type_enum pen_event,
                    S16 x,
                    S16 y,
                    gui_button_pen_enum *button_event);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    extern void wgui_softkey_get_dimension(WGUI_SOFTKEY_ENUM key, S32 *width, S32 *height);
    extern void wgui_softkey_get_position(WGUI_SOFTKEY_ENUM key, S32 *x, S32 *y);

    extern void show_softkey_background(void);
    extern void register_default_hide_softkeys(void);
    extern void register_default_hide_softkeys_to_transparent(void);
    extern void ChangeLeftSoftkey(U16 s, U16 i);
    extern void ChangeRightSoftkey(U16 s, U16 i);
    extern void EnableLeftSoftkey(U16 s, U16 i);
    extern void DisableLeftSoftkey(U16 s, U16 i);
    extern void EnableRightSoftkey(U16 s, U16 i);
    extern void DisableRightSoftkey(U16 s, U16 i);
    extern void SetLeftSoftkeyAlwaysKeyUpByPen(void);
    extern void SetRightSoftkeyAlwaysKeyUpByPen(void);
    extern void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

    #ifdef __MMI_WGUI_CSK_ENABLE__
    extern void ChangeCenterSoftkey(U16 s, U16 i);
    extern void EnableCenterSoftkey(U16 s, U16 i);
    extern void ResetCenterSoftkey(void);
    extern void SetCenterSoftkeyAlwaysKeyUpByPen(void);
    extern void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    
    /* 030705 Calvin added */
    extern void ChangeLeftSoftkeyByStringLength(UI_string_type s, PU8 i);
    extern void ChangeRightSoftkeyByStringLength(UI_string_type s, PU8 i);
    
    extern void ChangeLeftSoftkeyByString(UI_string_type s, PU8 i);
    extern void ChangeRightSoftkeyByString(UI_string_type s, PU8 i);

#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_SOFTKEYS_H__ */ 

