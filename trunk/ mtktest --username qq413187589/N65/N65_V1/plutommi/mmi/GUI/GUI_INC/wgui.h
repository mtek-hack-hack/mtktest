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
 *   wgui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Common definitions for WGUI coordinates
 *                  gui_switch.h
 *                   /        \
 *           gui_config.h    wgui.h
 * There are three files containing configuration variables about gui components.
 * gui_switch.h is in the bottom layer.
 * All these configuration variable which can be modified by customers have been defined or switched in this file.
 * And all these configuration variable prefixed with CFG_
 * gui_config.h and wgui.h are in the topper layer
 * The macros and compile options used in gui components can be defined in these two files. 
 * Some of them based on the macros in gui_switch.h
 *
 *
 *  Author:
 * -------
 *   Ning Gu (MBJ06063)
 *
 *==============================================================================
 *              HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
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

#ifndef __WGUI_H__
#define __WGUI_H__

#include "MMI_features.h"
#include "gui_switch.h"

#ifndef __OPTR_NONE__
#include "operator_gui.h"
#endif

#include "EventsGprot.h"
#include "globalconstants.h"
#include "DateTimeType.h"
#include "gui.h"
#include "gui_setting.h"
#include "gui_buttons.h"
#include "gui_scrollbars.h"
#include "gui_inputs.h"
#include "gui_generic_menuitems.h"
#include "gui_fixed_menuitems.h"
#include "gui_generic_menus.h"
#include "gui_fixed_menus.h"
#include "gui_windows.h"
#include "gui_dynamic_menus.h"
#include "wgui_draw_manager.h"


/*
** Typedef
*/
typedef S32         MMI_key_code_type;
typedef S32         MMI_key_event_type;
typedef U16         UI_string_ID_type;
typedef U16         UI_image_ID_type;
typedef U16         UI_audio_ID_type;
typedef MYTIME      UI_time;

/*
** Define
*/
#define KEYBOARD_KEY_DOWN                                   256
#define KEYBOARD_KEY_UP                                     257
#define STRING_ID_NULL                                      0
#define IMAGE_ID_NULL                                       0
#define MMI_BG_GREYSCALE_VALUE                              (40)
#define MMI_BG_GREYSCALE_BLACK_VALUE                        (40)
#define MMI_EDITOR_BG_OPACITY                               (current_MMI_theme->bg_opacity_low)

/*  Settings    */
/*  Timeouts: All in milliseconds   */
#define MMI_MENU_SHORTCUT_TIMEOUT                           (600)   
#define MMI_MULTITAP_TIMEOUT                                (600)

/*  Dimensions and co-ordinates         */
/*  All values in pixels                */
#define MMI_SUBLCD_TITLE_HEIGHT                             15

/*******************
 * Layout Switches
 *******************/

#if defined(CFG_UI_SHOW_STATUS_ICON_IN_TITLE) && (CFG_UI_SHOW_STATUS_ICON_IN_TITLE == __ON__)
    #define MMI_SHOW_STATUS_ICON_IN_TITLE
#endif


/* Show status icon above main menu */
#if defined(CFG_UI_MAINMENU_SHOW_STATUS_ICON) && (CFG_UI_MAINMENU_SHOW_STATUS_ICON == __ON__)
    #define GUI_MAINMENU_SHOW_STATUS_ICON
#endif

/* Show status icon above submenu */
#if defined(CFG_UI_SUBMENU_SHOW_STATUS_ICON) && (CFG_UI_SUBMENU_SHOW_STATUS_ICON == __ON__)
    #define GUI_SUBMENU_SHOW_STATUS_ICON
#endif

/* Show status icon above common category screens */
#if defined(CFG_UI_COMMON_SHOW_STATUS_ICON) && (CFG_UI_COMMON_SHOW_STATUS_ICON == __ON__)
    #define GUI_COMMON_SHOW_STATUS_ICON
#endif

/* Show status icon in default screen */
#if defined(CFG_UI_DEFAULT_SHOW_STATUS_ICON) && (CFG_UI_DEFAULT_SHOW_STATUS_ICON == __ON__)
    #define GUI_DEFAULT_SHOW_STATUS_ICON
#endif



/* height of title in mainmenu screen*/
#if defined(CFG_UI_MAINMENU_USE_THICK_TITLE) && (CFG_UI_MAINMENU_USE_THICK_TITLE == __ON__)
    #define GUI_MAINMENU_USE_THICK_TITLE  
#endif

/* height of title in sub menu*/
#if defined(CFG_UI_SUBMENU_USE_THICK_TITLE) && (CFG_UI_SUBMENU_USE_THICK_TITLE == __ON__)
    #define GUI_SUBMENU_USE_THICK_TITLE
#endif

/* height of title in common screen*/
#if defined(CFG_UI_COMMON_USE_THICK_TITLE) && (CFG_UI_COMMON_USE_THICK_TITLE == __ON__)
    #define GUI_COMMON_USE_THICK_TITLE
#endif

/* height of title in default screen*/
#if defined(CFG_UI_DEFAULT_USE_THICK_TITLE) && (CFG_UI_DEFAULT_USE_THICK_TITLE == __ON__)
    #define GUI_DEFAULT_USE_THICK_TITLE  
#endif



/* Overriding common category screen layout */
#if defined(CFG_UI_COMMON_USE_SPECIFIC) && (CFG_UI_COMMON_USE_SPECIFIC == __ON__)
    #define GUI_COMMON_USE_SPECIFIC_STYLE
#endif 

/* Overriding sub-menu layout */
#if defined(CFG_UI_SUBMENU_USE_SPECIFIC) && (CFG_UI_SUBMENU_USE_SPECIFIC == __ON__)
    #define GUI_SUBMENU_USE_SPECIFIC_STYLE
#endif 

/* Editor title layout */
#if defined(CFG_UI_EDITOR_SHOW_TITLE) && (CFG_UI_EDITOR_SHOW_TITLE == __ON__)
    #define GUI_EDITOR_SHOW_TITLE
#endif 


/*******************
 * Status Icon
 *******************/

#if defined (CFG_UI_STATUS_BAR_HEIGHT)
    #define MMI_STATUS_BAR_HEIGHT                       CFG_UI_STATUS_BAR_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_STATUS_BAR_IDLE_Y)
#define MMI_STATUS_BAR_IDLE_Y                           CFG_UI_STATUS_BAR_IDLE_Y
#else 
#error "Wrong option"
#endif

/* gap between status icon and edge */
#if defined (CFG_UI_STATUSBAR_GAP)
    #define MMI_UI_STATUSBAR_GAP                        CFG_UI_STATUSBAR_GAP
#else 
    #error "Wrong option"
#endif


/*******************
 * Softkey
 *******************/

/* height of button bar */
#if defined(CFG_UI_BUTTON_BAR_HEIGHT)
    #define MMI_BUTTON_BAR_HEIGHT                       CFG_UI_BUTTON_BAR_HEIGHT
#else 
    #error "Wrong option"
#endif

/* width of softkey */
#if defined(CFG_UI_SOFTKEY_WIDTH)
    #define MMI_SOFTKEY_WIDTH                           CFG_UI_SOFTKEY_WIDTH
#else 
    #error "Wrong option"
#endif

/* width of center softkey */
#if defined(CFG_UI_CENTER_SOFTKEY_WIDTH)
    #define MMI_CENTER_SOFTKEY_WIDTH                    CFG_UI_CENTER_SOFTKEY_WIDTH
#else 
    #error "Wrong option"
#endif

/* height of softkey */
#if defined(CFG_UI_SOFTKEY_HEIGHT)
    #define MMI_SOFTKEY_HEIGHT                          CFG_UI_SOFTKEY_HEIGHT
#else 
    #error "Wrong option"
#endif

/* gap between softkey and edge */
#if defined (CFG_UI_SOFTKEY_GAP)
    #define MMI_UI_SOFTKEY_GAP                          CFG_UI_SOFTKEY_GAP
#else 
    #error "Wrong option"
#endif

/*******************
 * Spacing in menu item
 *******************/

/* height of menu item */
#if defined (CFG_UI_MENUITEM_HEIGHT)
    #define MMI_MENUITEM_HEIGHT                         CFG_UI_MENUITEM_HEIGHT
#else 
    #error "Wrong option"
#endif

#if defined (CFG_UI_TEXT_MENUITEM_TEXT_X)
    #define GUI_TEXT_MENUITEM_TEXT_X                    CFG_UI_TEXT_MENUITEM_TEXT_X
#else
    #error "Wrong option"
#endif

#if defined (CFG_UI_ICONTEXT_MENUITEM_ICON_X)
    #define GUI_ICONTEXT_MENUITEM_ICON_X                CFG_UI_ICONTEXT_MENUITEM_ICON_X
#else
    #error "Wrong option"
#endif

#if defined (CFG_UI_ICONTEXT_MENUITEM_TEXT_X)
    #define GUI_ICONTEXT_MENUITEM_TEXT_X                CFG_UI_ICONTEXT_MENUITEM_TEXT_X
#else 
    #error "Wrong option"
#endif

/*******************
 * Popup Dialog
 *******************/

/* width of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_WIDTH)
    #define MMI_POP_UP_DIALOG_WIDTH                     CFG_UI_POP_UP_DIALOG_WIDTH
#else 
    #error "Wrong option"
#endif

/* height of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_HEIGHT)
    #define MMI_POP_UP_DIALOG_HEIGHT                    CFG_UI_POP_UP_DIALOG_HEIGHT
#else 
    #error "Wrong option"
#endif

/* x of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_X)
    #define MMI_POP_UP_DIALOG_X                         CFG_UI_POP_UP_DIALOG_X
#else 
    #error "Wrong option"
#endif

/* y of popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_Y)
    #define MMI_POP_UP_DIALOG_Y                         CFG_UI_POP_UP_DIALOG_Y
#else 
    #error "Wrong option"
#endif

/* height of full popup dialog */
#if defined (CFG_UI_POP_UP_DIALOG_FULL_HEIGHT)  
    #define MMI_POP_UP_DIALOG_FULL_HEIGHT               CFG_UI_POP_UP_DIALOG_FULL_HEIGHT
#else 
    #error "Wrong option"
#endif

/* margin of popup content */
#if defined (CFG_UI_POP_UP_CONTENT_MARGIN_X)  
    #define MMI_POP_UP_CONTENT_MARGIN_X                 CFG_UI_POP_UP_CONTENT_MARGIN_X
#else 
    #error "Wrong option"
#endif

/* margin of popup content */
#if defined (CFG_UI_POP_UP_CONTENT_MARGIN_Y)  
    #define MMI_POP_UP_CONTENT_MARGIN_Y                 CFG_UI_POP_UP_CONTENT_MARGIN_Y
#else 
    #error "Wrong option"
#endif

/*******************
 * Thin/Thick Title
 *******************/

/* heifht of thin title*/
#if defined(CFG_UI_THIN_TITLE_HEIGHT)
    #define MMI_THIN_TITLE_HEIGHT                       CFG_UI_THIN_TITLE_HEIGHT
#else 
    #error "Wrong option"
#endif

/* heifht of thick title*/
#if defined(CFG_UI_THICK_TITLE_HEIGHT)
    #define MMI_THICK_TITLE_HEIGHT                      CFG_UI_THICK_TITLE_HEIGHT
#else 
    #error "Wrong option"
#endif

/*******************
 * Idlescreen
 *******************/

#if defined (__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)    
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT
    #endif    
#endif /*  __MMI_DUAL_SIM_MASTER__ */    
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT
    #endif
#elif defined (__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)      
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO
    #endif    
#endif /*  __MMI_DUAL_SIM_MASTER__ */    
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_TECHNO)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_TECHNO
    #endif
#elif defined (__MMI_UI_STATUS_BAR_AT_BOTTOM__)
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)       
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM
    #endif    
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined (CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM
    #endif
#else
    #if defined (CFG_UI_IDLE_NETWORK_NAME_Y)
        #define MMI_IDLE_NETWORK_NAME_Y     CFG_UI_IDLE_NETWORK_NAME_Y
    #endif
    #if defined (CFG_UI_IDLE_NETWORK_STATUS_Y)
        #define MMI_IDLE_NETWORK_STATUS_Y   CFG_UI_IDLE_NETWORK_STATUS_Y
    #endif
#if defined( __MMI_DUAL_SIM_MASTER__)        
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_NAME_Y)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y     CFG_UI_IDLE_SIM2_NETWORK_NAME_Y
    #endif
    #if defined (CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y)
        #define MMI_IDLE_SIM2_NETWORK_STATUS_Y   CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y
    #endif    
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined (CFG_UI_IDLE_EXTRA_Y)
        #define MMI_IDLE_EXTRA_Y            CFG_UI_IDLE_EXTRA_Y
    #endif
    #if defined (CFG_UI_IDLE_SATICON_Y)
        #define MMI_IDLE_SATICON_Y          CFG_UI_IDLE_SATICON_Y
    #endif
#endif

/* Idle screen error check */
#ifndef MMI_IDLE_NETWORK_NAME_Y
    #error "Please define MMI_IDLE_NETWORK_NAME_Y in wgui.h!!"
#endif

#ifndef MMI_IDLE_NETWORK_STATUS_Y
    #error "Please define MMI_IDLE_NETWORK_STATUS_Y in wgui.h!!"
#endif

#if defined( __MMI_DUAL_SIM_MASTER__)    
    #ifndef MMI_IDLE_NETWORK_NAME_Y
        #error "Please define MMI_IDLE_NETWORK_NAME_Y in wgui.h!!"
    #endif

    #ifndef MMI_IDLE_NETWORK_STATUS_Y
        #error "Please define MMI_IDLE_NETWORK_STATUS_Y in wgui.h!!"
    #endif
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef MMI_IDLE_EXTRA_Y
    #error "Please define MMI_IDLE_EXTRA_Y in wgui.h!!"
#endif

#ifndef MMI_IDLE_SATICON_Y
    #error "Please define MMI_IDLE_SATICON_Y in wgui.h!!"
#endif


/*******************
 * Matrix Main Menu Icon
 *******************/
 
/* main menu matrix menuitem image width and height */
/* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH)
    #define MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH
#else 
    #error "Wrong option"
#endif

/* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT)
    #define MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT
#else 
    #error "Wrong option"
#endif

/* MAX normal image width */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH)
    #define MAIN_MENU_NORMAL_IMAGE_WIDTH                    CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH
#else 
    #error "Wrong option"
#endif

/* MAX normal image height */
#if defined(CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT)
    #define MAIN_MENU_NORMAL_IMAGE_HEIGHT                   CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT
#else 
    #error "Wrong option"
#endif

/* MAX highlighted image width, affects the cache buffer size */
#if defined(CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH)
    #define MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH
#else 
    #error "Wrong option"
#endif

/* MAX highlighted image height, affects the cache buffer size */
#if defined(CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT)
    #define MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT
#else 
    #error "Wrong option"
#endif

/*******************
 * Default Layout
 *******************/

#ifdef GUI_DEFAULT_SHOW_STATUS_ICON
    #define MMI_TITLE_Y                                     (MMI_STATUS_BAR_HEIGHT)
#else
    #define MMI_TITLE_Y                                     (0)
#endif

/* heifht of title in common screen*/
#if defined(GUI_DEFAULT_USE_THICK_TITLE)
    #define MMI_TITLE_HEIGHT                                MMI_THICK_TITLE_HEIGHT
#else
    #define MMI_TITLE_HEIGHT                                MMI_THIN_TITLE_HEIGHT
#endif

#ifdef GUI_DEFAULT_SHOW_STATUS_ICON
    #define MMI_CONTENT_HEIGHT                              (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_TITLE_HEIGHT-MMI_STATUS_BAR_HEIGHT)
#else
    #define MMI_CONTENT_HEIGHT                              (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_TITLE_HEIGHT)
#endif

#ifdef __MMI_MAINLCD_128X128__
    #if defined( __MMI_UI_SMALL_SCREEN_SUPPORT__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (9)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (9)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)
    #endif  /* UI_SMALL_CATEGORY_EDITOR*/

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (19)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (0)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (15)

        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
        
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (18)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (18)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

#elif defined __MMI_MAINLCD_128X160__

    #if defined( __MMI_UI_SMALL_SCREEN_SUPPORT__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (9)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (11)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)
    #endif /* UI_SMALL_CATEGORY_EDITOR*/

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (22)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (0)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (15)

        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
        
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (17)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (17)
        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

#elif defined __MMI_MAINLCD_176X220__

    #if defined( __MMI_UI_SMALL_SCREEN_SUPPORT__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (12)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (15)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)
    #endif /* UI_SMALL_CATEGORY_EDITOR*/

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (60)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
    #ifdef __MMI_UI_TECHNO_STATUS_ICON__
        #define MMI_SIGNAL_WIDTH                            (12)
    #else
        #define MMI_SIGNAL_WIDTH                            (5)
    #endif
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (60)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (60)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (26)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (46)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (15)

        #define MMI_TITLE_PADDING                           (0)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)


        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (22)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (22)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (39)

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (155)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (155)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-MMI_MENUITEM_HEIGHT)

        #define MMI_ROTATED_TITLE_X                         (10)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (10)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 7)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 7)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)

#elif defined __MMI_MAINLCD_240X320__
    #if defined( __MMI_UI_SMALL_SCREEN_SUPPORT__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)
    #endif  /* UI_SMALL_CATEGORY_EDITOR*/

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (80)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
    #ifdef __MMI_UI_TECHNO_STATUS_ICON__
        #define MMI_SIGNAL_WIDTH                            (20)
    #else
        #define MMI_SIGNAL_WIDTH                            (5)
    #endif
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
        #define DIGITAL_BACKGROUND_X                        (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                        (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                    (88)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */

        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (65)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (20)

        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
    
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (30)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (48)

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      (50)
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (230)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))

        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)

#elif defined __MMI_MAINLCD_320X240__
    #if defined( __MMI_UI_SMALL_SCREEN_SUPPORT__)
        #define MMI_SMALL_SCREEN_X_OFFSET                   (16)
        #define MMI_SMALL_SCREEN_Y_OFFSET                   (22)
        #define MMI_SMALL_LIST_LEFT_OFFSET                  2
        #define MMI_SMALL_LIST_SCREEN_WIDTH                 ((MAIN_LCD_DEVICE_WIDTH*3)/4)
    #endif  /* UI_SMALL_CATEGORY_EDITOR*/

    #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
        #define MMI_IDLESCREEN_BAR_HEIGHT                   (65)
        #define MMI_SIGNAL_X                                (0)
        #define MMI_SIGNAL_Y                                (0)
    #ifdef __MMI_UI_TECHNO_STATUS_ICON__
        #define MMI_SIGNAL_WIDTH                            (20)
    #else
        #define MMI_SIGNAL_WIDTH                            (5)
    #endif
        #define ANALOG_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define ANALOG_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define ANALOG_BACKGROUND_WIDTH                     (80)
        #define DIGITAL_BACKGROUND_X                         (MMI_SIGNAL_X + MMI_SIGNAL_WIDTH)
        #define DIGITAL_BACKGROUND_Y                         (MMI_STATUS_BAR_HEIGHT)
        #define DIGITAL_BACKGROUND_WIDTH                     (90)
    #endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */
        
        #define MMI_IDLE_NETWORK_NAME_Y_WITH_CLOCK_BG       (45)
        #define MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG  (65)
        #define MMI_IDLE_STRING_MARGIN_GAP                  (40)

        #define MMI_TITLE_PADDING                           (4)
        #define MMI_TITLE_X                                 (0)
        #define MMI_TITLE_WIDTH                             (MAIN_LCD_DEVICE_WIDTH)
        #define MMI_CONTENT_X                               (0)
        #define MMI_CONTENT_Y                               (MMI_TITLE_Y+MMI_TITLE_HEIGHT)
        #define MMI_CONTENT_WIDTH                           (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ICONTEXT_MENUITEM_HEIGHT                (30)
        #define MMI_INLINE_EDIT_MENUITEM_HEIGHT             (30)

        #define MMI_MULTIROW_MENUITEM_HEIGHT                (44)

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        #define WGUI_TOUCH_IDLESCREEN_SHORTCUTS_HEIGHT      50
    #endif

        #define MMI_ROTATED_LCD_WIDTH                       (MAIN_LCD_DEVICE_HEIGHT)
        #define MMI_ROTATED_LCD_HEIGHT                      (MAIN_LCD_DEVICE_WIDTH)

        #define MMI_ROTATED_TITLE_WIDTH                     (230)
        #define MMI_ROTATED_TITLE_HEIGHT                    (MMI_TITLE_HEIGHT)

        #define MMI_ROTATED_CONTENT_WIDTH                   (230)
        #define MMI_ROTATED_CONTENT_HEIGHT                  (MMI_CONTENT_HEIGHT-(MMI_MENUITEM_HEIGHT << 1))

        #define MMI_ROTATED_TITLE_X                         (15)
        #define MMI_ROTATED_TITLE_Y                         ((MMI_ROTATED_LCD_HEIGHT -  MMI_ROTATED_CONTENT_HEIGHT - MMI_ROTATED_TITLE_HEIGHT)/2)

        #define MMI_ROTATED_CONTENT_X                       (15)
        #define MMI_ROTATED_CONTENT_Y                       (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT)

        #define MMI_ROTATED_POP_UP_DIALOG_X                 (MMI_ROTATED_CONTENT_X + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_Y                 (MMI_ROTATED_TITLE_Y + MMI_ROTATED_TITLE_HEIGHT + 10)
        #define MMI_ROTATED_POP_UP_DIALOG_WIDTH             (MMI_ROTATED_CONTENT_WIDTH - 15)
        #define MMI_ROTATED_POP_UP_DIALOG_HEIGHT            (MMI_ROTATED_LCD_HEIGHT - MMI_ROTATED_POP_UP_DIALOG_Y - 20)
        #define MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT       (MMI_ROTATED_POP_UP_DIALOG_HEIGHT)
        #define MMI_ROTATED_POP_UP_DIALOG_CENTERED_X        ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_POP_UP_DIALOG_WIDTH) >> 1)

        #define MMI_ROTATED_BUTTON_BAR_X                    (MMI_ROTATED_CONTENT_X + MMI_ROTATED_CONTENT_WIDTH + 3 /* leave space for border frame */)
        #define MMI_ROTATED_BUTTON_BAR_Y                    (0)
        #define MMI_ROTATED_BUTTON_BAR_WIDTH                (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_CONTENT_X - MMI_ROTATED_CONTENT_WIDTH - 3)
        #define MMI_ROTATED_BUTTON_BAR_HEIGHT               (MMI_ROTATED_LCD_HEIGHT)
        #define MMI_ROTATED_SOFTKEY_WIDTH                   (MMI_ROTATED_BUTTON_BAR_WIDTH)
        #define MMI_ROTATED_SOFTKEY_HEIGHT                  (MMI_SOFTKEY_HEIGHT)
#else
    #error "No UI Style is Specified!!"
#endif

/*******************
 * MainMenu Layout
 *******************/

#define MMI_MAINMENU_TITLE_X                                (MMI_TITLE_X)
#define MMI_MAINMENU_TITLE_WIDTH                            (MMI_TITLE_WIDTH)
#define MMI_MAINMENU_CONTENT_X                              (MMI_CONTENT_X)
#define MMI_MAINMENU_CONTENT_WIDTH                          (MMI_CONTENT_WIDTH)

#ifdef GUI_MAINMENU_SHOW_STATUS_ICON
#define MMI_MAINMENU_TITLE_Y                                (MMI_STATUS_BAR_HEIGHT)
#else 
    #define MMI_MAINMENU_TITLE_Y                            (0)
#endif

#ifdef GUI_MAINMENU_USE_THICK_TITLE
    #define MMI_MAINMENU_TITLE_HEIGHT                       (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_MAINMENU_TITLE_HEIGHT                       (MMI_THIN_TITLE_HEIGHT)
#endif

#define MMI_MAINMENU_CONTENT_Y                              (MMI_MAINMENU_TITLE_Y + MMI_MAINMENU_TITLE_HEIGHT)
#define MMI_MAINMENU_CONTENT_HEIGHT                         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MAINMENU_CONTENT_Y )

/*******************
 * SubMenu Layout
 *******************/

#define MMI_SUBMENU_TITLE_X                                 (MMI_TITLE_X)
#define MMI_SUBMENU_TITLE_WIDTH                             (MMI_TITLE_WIDTH)
#define MMI_SUBMENU_CONTENT_X                               (MMI_CONTENT_X)
#define MMI_SUBMENU_CONTENT_WIDTH                           (MMI_CONTENT_WIDTH)

#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
#define MMI_SUBMENU_TITLE_Y                                 (MMI_STATUS_BAR_HEIGHT)
#else 
    #define MMI_SUBMENU_TITLE_Y                             (0)
#endif

#ifdef GUI_SUBMENU_USE_THICK_TITLE
    #define MMI_SUBMENU_TITLE_HEIGHT                        (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_SUBMENU_TITLE_HEIGHT                        (MMI_THIN_TITLE_HEIGHT)
#endif

#define MMI_SUBMENU_CONTENT_Y                               (MMI_SUBMENU_TITLE_Y + MMI_SUBMENU_TITLE_HEIGHT)
#define MMI_SUBMENU_CONTENT_HEIGHT                          (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_SUBMENU_CONTENT_Y )

/*******************
 * Common Layout
 *******************/

#define MMI_COMMON_TITLE_X                                  (MMI_TITLE_X)
#define MMI_COMMON_TITLE_WIDTH                              (MMI_TITLE_WIDTH)
#define MMI_COMMON_CONTENT_X                                (MMI_CONTENT_X)
#define MMI_COMMON_CONTENT_WIDTH                            (MMI_CONTENT_WIDTH)

#ifdef GUI_COMMON_SHOW_STATUS_ICON
#define MMI_COMMON_TITLE_Y                                  (MMI_STATUS_BAR_HEIGHT)
#else 
#define MMI_COMMON_TITLE_Y                                  (0)
#endif

#ifdef GUI_COMMON_USE_THICK_TITLE
    #define MMI_COMMON_TITLE_HEIGHT                         (MMI_THICK_TITLE_HEIGHT)
#else
    #define MMI_COMMON_TITLE_HEIGHT                         (MMI_THIN_TITLE_HEIGHT)
#endif
    
#define MMI_COMMON_CONTENT_Y                                (MMI_COMMON_TITLE_Y + MMI_COMMON_TITLE_HEIGHT)
#define MMI_COMMON_CONTENT_HEIGHT                           (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_COMMON_CONTENT_Y )

/*******************
 * Others
 *******************/

#define MMI_MATRIX_BAR_WIDTH                                (MAIN_LCD_DEVICE_WIDTH)
#define MMI_MATRIX_BAR_HEIGHT                               (19)
#define MMI_MATRIX_BAR_X                                    (0)
#define MMI_MATRIX_BAR_Y                                    (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_MATRIX_BAR_HEIGHT+1)

#define MMI_MULTITAP_X                                      (2)
#define MMI_MULTITAP_WIDTH                                  (MAIN_LCD_DEVICE_WIDTH-4)

#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
   #define MMI_MULTITAP_HEIGHT                              (23)
#else
   #define MMI_MULTITAP_HEIGHT                              (17)
#endif

#define MMI_MULTITAP_Y                                      (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_MULTITAP_HEIGHT)


#define MMI_SINGLELINE_INPUTBOX_X                           (5)
#define MMI_SINGLELINE_INPUTBOX_Y                           (40)
#define MMI_SINGLELINE_INPUTBOX_WIDTH                       (MAIN_LCD_DEVICE_WIDTH-10)
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (26)
#else
    #define MMI_SINGLELINE_INPUTBOX_HEIGHT                  (20)
#endif

#define MMI_MULTILINE_INPUTBOX_X                            (0)
#define MMI_MULTILINE_INPUTBOX_Y                            (20)
#define MMI_MULTILINE_INPUTBOX_WIDTH                        (MAIN_LCD_DEVICE_WIDTH)
#define MMI_MULTILINE_INPUTBOX_HEIGHT                       (MAIN_LCD_DEVICE_HEIGHT-82)

#define MMI_GENERAL_INPUTBOX_X                              (0)
#define MMI_GENERAL_INPUTBOX_Y                              (20)
#define MMI_GENERAL_INPUTBOX_WIDTH                          (MAIN_LCD_DEVICE_WIDTH)
#define MMI_GENERAL_INPUTBOX_HEIGHT                         (MAIN_LCD_DEVICE_HEIGHT-82)

/* Tab bar */
#if defined(__MMI_MAINLCD_320X240__) 
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (60)
#elif defined( __MMI_MAINLCD_176X220__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (44)
#else
    #define MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH                (42)
#endif

#if defined(__MMI_MAINLCD_320X240__) 
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (60)
#else
    #define MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH        (44)
#endif

#define MMI_HORIZONTAL_TAB_BAR_X                            (MMI_TITLE_X)
#define MMI_HORIZONTAL_TAB_BAR_Y                            (MMI_TITLE_Y)
#define MMI_HORIZONTAL_TAB_BAR_WIDTH                        (MMI_TITLE_WIDTH)
#if defined(__MMI_MAINLCD_320X240__) 
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (36)
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (28)
#else
    #define MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT          (20)
#endif

#if defined(__MMI_MAINLCD_320X240__) 
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (26)
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (26)
#elif defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_128X160__)
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (20)
#else
    #define MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT         (0)
#endif

#define MMI_CONTENT_WIDTH_WITH_H_TAB                        (MMI_content_width)
#define MMI_CONTENT_HEIGHT_WITH_H_TAB                       (MMI_content_height + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#define MMI_CONTENT_X_WITH_H_TAB                            (MMI_content_x)
#define MMI_CONTENT_Y_WITH_H_TAB                            (MMI_content_y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_TITLE_HEIGHT)

#define MMI_DROPDOWN_MENUITEM_HEIGHT                        (18)
#if !defined(__MMI_TOUCH_SCREEN__)
    //W06.03 Adjust the height of the information bar for 240*320
    #if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
        #define INFORMATION_BAR_HEIGHT                      (22)
    #else
        #define INFORMATION_BAR_HEIGHT                      (12)
    #endif
#else
    #if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
        #define INFORMATION_BAR_HEIGHT                      (22)
    #else
        #define INFORMATION_BAR_HEIGHT                      (18)
    #endif
#endif

#define MMI_POP_UP_DIALOG_FULL_Y                            (((MAIN_LCD_DEVICE_HEIGHT-MMI_POP_UP_DIALOG_FULL_HEIGHT)>>1) + 6)

#ifndef __MMI_FULL_DIALSCREEN_FEATURE__
    #if defined (__MMI_MAINLCD_320X240__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)            
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_240X320__)
#if 0	
	//huyanwei Modify it
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (218)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (177)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (14)
        #define MMI_DIALING_KEYPAD_Y                            (5)
        #define MMI_DIALING_KEYPAD_WIDTH                        (218)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (177)
        #define MMI_DIALING_KEY_WIDTH                           (37)
        #define MMI_DIALING_KEY_HEIGHT                          (37)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (12)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (66)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (15)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (16)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif
#else
	 #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                            (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH              (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT             (220)
        #define MMI_DIALING_KEYPAD_LAYER_X                       ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                       (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT))-24)
        #define MMI_DIALING_KEYPAD_X                           	     (3)/*(13)*/
        #define MMI_DIALING_KEYPAD_Y                                   (2)/*(4)*/
        #define MMI_DIALING_KEYPAD_WIDTH                          (240)
        #define MMI_DIALING_KEYPAD_HEIGHT                         (220)
        #define MMI_DIALING_KEY_WIDTH                               (78)  /*(60)*/
        #define MMI_DIALING_KEY_HEIGHT                              (42) /* (49)*/
        #define MMI_DIALING_KEY_HORIZONTAL_GAP              (0)/* (16)*/
        #define MMI_DIALING_KEY_VERTICAL_GAP                  (2) /* (3)*/
        #define MMI_DIALING_BOX_HEIGHT                               (58)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (3)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (1)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (3)/*(165)*/
                #define MMI_DIALING_KEYPAD_FUNC_Y                 (176)  /*(15)*/
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (78)/*(37)*/
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (44)/*(37)*/
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (0)/*(16)*/
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif

#endif
    #elif defined (__MMI_MAINLCD_176X220__)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (50)
            #define MMI_DIALING_KEYPAD_X                           (6)// (7)
            #define MMI_DIALING_KEYPAD_Y                            (7)//(11)
            #define MMI_DIALING_KEYPAD_WIDTH                     (165)//   (126)
            #define MMI_DIALING_KEYPAD_HEIGHT                      (137)// (130)
            #define MMI_DIALING_KEY_WIDTH                           (39)//(40)
            #define MMI_DIALING_KEY_HEIGHT                          (31)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                 (6)// (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                   (5)// (3)
            #define MMI_DIALING_BOX_HEIGHT                          (33)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (139)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (12)
                #define MMI_DIALING_FUNC_KEY_WIDTH                 (33)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                (42)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
		   #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (139)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (15)
                #define MMI_DIALING_FUNC_KEY_WIDTH                 (33)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                (42)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
		#if 0		
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
		#endif		
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #else /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */        
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (50)
            #define MMI_DIALING_KEYPAD_X                          (6)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (145)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (137)
            #define MMI_DIALING_KEY_WIDTH                           (39)
            #define MMI_DIALING_KEY_HEIGHT                          (31)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (6)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
            #define MMI_DIALING_BOX_HEIGHT                          (33)

            #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
            #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
            #define MMI_DIALING_KEYPAD_FUNC_X                   (139)
            #define MMI_DIALING_KEYPAD_FUNC_Y                   (15)
            #define MMI_DIALING_FUNC_KEY_WIDTH                 (33)
            #define MMI_DIALING_FUNC_KEY_HEIGHT                (42)
            #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (0)
            #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (5)
        #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
    #else /* LCD szie */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (6)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (27)
            #define MMI_DIALING_KEY_HEIGHT                          (22)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
            /* For function key on idlescreen */
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (8)
            #define MMI_DIALING_KEYPAD_Y                            (0)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (31)
            #define MMI_DIALING_KEY_HEIGHT                          (25)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (9)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #endif  /* LCD szie */
#else   /* __MMI_FULL_DIALSCREEN_FEATURE__ */
    #if defined (__MMI_MAINLCD_320X240__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (265)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (141)
        #define MMI_DIALING_KEYPAD_LAYER_X                      ((MAIN_LCD_DEVICE_WIDTH-MMI_DIALING_KEYPAD_LAYER_WIDTH)>>1)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (((MAIN_LCD_DEVICE_HEIGHT-MMI_DIALING_KEYPAD_LAYER_HEIGHT)>>1)+20)
        #define MMI_DIALING_KEYPAD_X                            (13)
        #define MMI_DIALING_KEYPAD_Y                            (9)
        #define MMI_DIALING_KEYPAD_WIDTH                        (265)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (141)
        #define MMI_DIALING_KEY_WIDTH                           (59)
        #define MMI_DIALING_KEY_HEIGHT                          (26)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (4)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (47)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (218)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (8)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (8)
            #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (216)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (22)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (32)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (33)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (18)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (28)
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #elif defined (__MMI_MAINLCD_240X320__)
        #define MMI_DIALING_KEYPAD_COLOMNS                  (3)
        #define MMI_DIALING_KEYPAD_ROWS                     (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH              (240)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT             (212)
        #define MMI_DIALING_KEYPAD_LAYER_X                  (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                  (84)
        #define MMI_DIALING_KEYPAD_X                        (0)
        #define MMI_DIALING_KEYPAD_Y                        (0)
        #define MMI_DIALING_KEYPAD_WIDTH                    (240)
        #define MMI_DIALING_KEYPAD_HEIGHT                   (212)
        #define MMI_DIALING_KEY_WIDTH                       (61)
        #define MMI_DIALING_KEY_HEIGHT                      (53)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP              (0)
        #define MMI_DIALING_KEY_VERTICAL_GAP                (0)
        #define MMI_DIALING_BOX_HEIGHT                      (60)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
              #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                  #define   MMI_DIALING_KEYPAD_FUNC_COLOMNS     (1) 
                  #define   MMI_DIALING_KEYPAD_FUNC_ROWS        (3) 
                  #define   MMI_DIALING_KEYPAD_FUNC_X           (183)
                  #define   MMI_DIALING_KEYPAD_FUNC_Y           (0)
                  #define   MMI_DIALING_FUNC_KEY_WIDTH          (57)
                  #define   MMI_DIALING_FUNC_KEY_HEIGHT         (71)
                  #define   MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP (12)
                  #define   MMI_DIALING_FUNC_KEY_VERTICAL_GAP   (0)
              #else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                  #define   MMI_DIALING_KEYPAD_FUNC_COLOMNS     (1) 
                  #define   MMI_DIALING_KEYPAD_FUNC_ROWS        (2) 
                  #define   MMI_DIALING_KEYPAD_FUNC_X           (183)
                  #define   MMI_DIALING_KEYPAD_FUNC_Y           (0)
                  #define   MMI_DIALING_FUNC_KEY_WIDTH          (57)
                  #define   MMI_DIALING_FUNC_KEY_HEIGHT         (106)
                  #define   MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP (12)
                  #define   MMI_DIALING_FUNC_KEY_VERTICAL_GAP   (0)
              #endif    /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        #endif
    #elif defined (__MMI_MAINLCD_176X220__)
        #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
        #define MMI_DIALING_KEYPAD_ROWS                         (4)
        #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (176)
        #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (200)
        #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
        #define MMI_DIALING_KEYPAD_LAYER_Y                      (50)
        #define MMI_DIALING_KEYPAD_X                            (16)
        #define MMI_DIALING_KEYPAD_Y                            (7)
        #define MMI_DIALING_KEYPAD_WIDTH                        (145)
        #define MMI_DIALING_KEYPAD_HEIGHT                       (137)
        #define MMI_DIALING_KEY_WIDTH                           (39)
        #define MMI_DIALING_KEY_HEIGHT                          (31)
        #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (14)
        #define MMI_DIALING_KEY_VERTICAL_GAP                    (5)
        #define MMI_DIALING_BOX_HEIGHT                          (33)
        /* For function key on idlescreen */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (165)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (33)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (37)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (37)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (12)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (27)
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */            
        #endif
    #else /* LCD Size */
        #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (6)
            #define MMI_DIALING_KEYPAD_Y                            (7)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (27)
            #define MMI_DIALING_KEY_HEIGHT                          (22)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (3)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
            /* For function key on idlescreen */
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (3)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */        
                #define MMI_DIALING_KEYPAD_FUNC_COLOMNS             (1)
                #define MMI_DIALING_KEYPAD_FUNC_ROWS                (2)
                #define MMI_DIALING_KEYPAD_FUNC_X                   (98)
                #define MMI_DIALING_KEYPAD_FUNC_Y                   (14)
                #define MMI_DIALING_FUNC_KEY_WIDTH                  (25)
                #define MMI_DIALING_FUNC_KEY_HEIGHT                 (25)
                #define MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP         (4)
                #define MMI_DIALING_FUNC_KEY_VERTICAL_GAP           (4)
            #endif   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */    
        #else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
            #define MMI_DIALING_KEYPAD_COLOMNS                      (3)
            #define MMI_DIALING_KEYPAD_ROWS                         (4)
            #define MMI_DIALING_KEYPAD_LAYER_WIDTH                  (128)
            #define MMI_DIALING_KEYPAD_LAYER_HEIGHT                 (160)
            #define MMI_DIALING_KEYPAD_LAYER_X                      (0)
            #define MMI_DIALING_KEYPAD_LAYER_Y                      (MMI_DIALING_BOX_HEIGHT)
            #define MMI_DIALING_KEYPAD_X                            (8)
            #define MMI_DIALING_KEYPAD_Y                            (0)
            #define MMI_DIALING_KEYPAD_WIDTH                        (112)
            #define MMI_DIALING_KEYPAD_HEIGHT                       (110)
            #define MMI_DIALING_KEY_WIDTH                           (31)
            #define MMI_DIALING_KEY_HEIGHT                          (25)
            #define MMI_DIALING_KEY_HORIZONTAL_GAP                  (9)
            #define MMI_DIALING_KEY_VERTICAL_GAP                    (3)
            #define MMI_DIALING_BOX_HEIGHT                          (30)
        #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
    #endif /* LCD Size */
#endif  /* __MMI_FULL_DIALSCREEN_FEATURE__ */


/* 
 * MAIN MENU
 */

/* cache buffer size for the matrix main menu highlighted area */ 
#define MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE           (MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH * MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL / 8)


/* Upper bound of the number of menu items in one screen */
#define MMI_MAX_MENUITEMS_IN_CONTENT                        (MMI_CONTENT_HEIGHT/MMI_MENUITEM_HEIGHT + 2) /* the magic number 2 is for safety. At least 1. */

#ifdef __MMI_TOUCH_SCREEN__
    #define MMI_PASSWD_KEYBOARD_START_X                     (0)
    #define MMI_PASSWD_KEYBOARD_START_Y                     (138)
#endif

/* Macros defined for title bar buttons used in Touch Panel support */
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
    #define MMI_TITLEBAR_BUTTON_GAP                         (20)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (19)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (17)
#elif defined(__MMI_MAINLCD_176X220__)
    #define MMI_TITLEBAR_BUTTON_GAP                         (10)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (15)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (15)
#else
    #define MMI_TITLEBAR_BUTTON_GAP                         (1)
    #define MMI_TITLEBAR_BUTTON_WIDTH                       (15)
    #define MMI_TITLEBAR_BUTTON_HEIGHT                      (15)
#endif


/*
** Extern Global Variable
*/
extern U8 MMI_disable_title_shortcut_display;
extern S32 MMI_status_bar_height;
extern S32 MMI_content_x;
extern S32 MMI_content_y;
extern S32 MMI_content_width;
extern S32 MMI_content_height;
extern S32 MMI_pop_up_dialog_x;
extern S32 MMI_pop_up_dialog_y;
extern S32 MMI_pop_up_dialog_width;
extern S32 MMI_pop_up_dialog_height;
extern S32 MMI_pop_up_dialog_full_height;

/*
** Extern Global Function
*/

extern void wgui_init(void);
extern void MMI_dummy_function(void);
extern void register_keyboard_key_handler(void (*f)(S32 vkey_code,S32 key_state));
extern void register_keyboard_input_handler(void (*f)(S32 vkey_code));
extern void register_keyboard_global_key_handler(void (*f)(S32 vkey_code,S32 key_state));
extern void register_keyboard_global_input_handler(void (*f)(S32 vkey_code));
extern void clear_keyboard_key_handler(void);
extern void clear_keyboard_input_handler(void);
extern void clear_keyboard_global_key_handler(void);
extern void clear_keyboard_global_input_handler(void);

/*  key handling wrappers   */
extern void clear_key_handlers(void);
extern void clear_category_screen_key_handlers(void);

extern void register_key_input_handler(void (*f)(MMI_key_code_type key_code,MMI_key_event_type key_event));
extern void register_key_up_handler(void (*f)(MMI_key_code_type key_code));
extern void register_key_down_handler(void (*f)(MMI_key_code_type key_code));
extern void register_MMI_key_input_handler(void);
extern void register_MMI_stroke_key_input_handler(void);
#ifdef __MMI_MULTITAP_THAI__
extern void register_MMI_key_input_extend_handler(void);
#endif

extern void clear_key_input_handler(void);
extern void clear_key_down_handler(void);
extern void clear_key_up_handler(void);
extern void clear_MMI_key_input_handler(void);

extern void MMI_key_input_handler(MMI_key_code_type key_code,MMI_key_event_type key_event);

#endif /* __WGUI_H__ */

