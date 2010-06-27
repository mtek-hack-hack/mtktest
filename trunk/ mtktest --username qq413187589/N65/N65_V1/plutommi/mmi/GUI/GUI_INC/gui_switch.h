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
 *   gui_config_switch.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GUI Configuration
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#ifndef __GUI_SWITCH_H__
#define __GUI_SWITCH_H__

#include "MMI_features.h"


/* this configuration can apply specific style on submenu / common category screen,
 * if it is OFF, the screen will have default style (base_control_set),
 * if it is ON, the screen can apply a specific & custormized style, that is CFG_UI_SUBMENU_SHOW_STATUS_ICON, CFG_UI_SUBMENU_USE_THICK_TITLE */
#if defined(__MMI_MAINLCD_320X240__)
#define CFG_UI_SUBMENU_USE_SPECIFIC                     (__ON__)
#define CFG_UI_COMMON_USE_SPECIFIC                      (__ON__)
#else
#define CFG_UI_SUBMENU_USE_SPECIFIC                     (__OFF__)
#define CFG_UI_COMMON_USE_SPECIFIC                      (__OFF__)
#endif

/*
 * CFG_UI_MAINMENU_SHOW_STATUS_ICON - Show status icon above main menu
 *
 * CFG_UI_SUBMENU_SHOW_STATUS_ICON - Show status icon above submenu
 * 
 * CFG_UI_COMMON_SHOW_STATUS_ICON - Show status icon above common screen
 * 
 * CFG_UI_DEFAULT_SHOW_STATUS_ICON - show status icon above default screen(word clock, calendar etc.)
*/
#if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_MAINMENU_SHOW_STATUS_ICON            (__OFF__)
    #define CFG_UI_SUBMENU_SHOW_STATUS_ICON             (__OFF__)
    #define CFG_UI_COMMON_SHOW_STATUS_ICON              (__OFF__)
    #define CFG_UI_DEFAULT_SHOW_STATUS_ICON             (__OFF__)
#else
    #define CFG_UI_MAINMENU_SHOW_STATUS_ICON            (__ON__)
    #define CFG_UI_SUBMENU_SHOW_STATUS_ICON             (__ON__)
    #define CFG_UI_COMMON_SHOW_STATUS_ICON              (__ON__)
    #define CFG_UI_DEFAULT_SHOW_STATUS_ICON             (__ON__)
#endif

/* Editor title layout */
#if defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_EDITOR_SHOW_TITLE                    (__OFF__)
#else  
    #define CFG_UI_EDITOR_SHOW_TITLE                    (__ON__)
#endif

#if defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_SHOW_STATUS_ICON_IN_TITLE            (__ON__)
#else
    #define CFG_UI_SHOW_STATUS_ICON_IN_TITLE            (__OFF__)
#endif


/*
 * CFG_UI_MAINMENU_USE_THICK_TITLE - show thick title above main menu
 *
 * CFG_UI_SUBMENU_USE_THICK_TITLE - Show thick title above submenu
 * 
 * CFG_UI_COMMON_USE_THICK_TITLE - Show thick title above common screen
 * 
 * CFG_UI_DEFAULT_USE_THICK_TITLE - Show thick title above default screen(word clock, calendar etc.)
*/
#define CFG_UI_MAINMENU_USE_THICK_TITLE           (__OFF__)
#define CFG_UI_SUBMENU_USE_THICK_TITLE           (__OFF__)
#define CFG_UI_COMMON_USE_THICK_TITLE            (__OFF__)
#define CFG_UI_DEFAULT_USE_THICK_TITLE            (__OFF__)

/* status icons have been drawn from bottom baseline or from center baseline */
#if defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      (__OFF__)
#else
    #define CFG_UI_STATUS_ICONS_DRAW_FROM_BOTTOM_BASELINE      (__ON__)
#endif

/* Idle screen */
#if defined( __MMI_DUAL_SIM_MASTER__)
/******************************************************************************
 *This Area, is define of Dual SIM IDLE
 ******************************************************************************/
#if defined(__MMI_MAINLCD_128X128__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (22)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (94)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (22)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (40)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (22)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (94)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (58)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (76)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (98)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (24)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (24)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (120)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (44)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (44)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (184)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (104)
    #define CFG_UI_IDLE_EXTRA_Y                                     (104)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (160)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (0)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO             (142)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM   (64)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                         (64)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO           (164)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM (84)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                       (84)
#elif defined(__MMI_MAINLCD_240X320__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (108)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (108)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (138)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (138)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (65)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (228)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (228)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (125)
    #define CFG_UI_IDLE_EXTRA_Y                                     (125)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (220)
    #define CFG_UI_IDLE_SATICON_Y                                   (153)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (168)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (198)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (198)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (105)
#elif defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (64)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (130)
    #define CFG_UI_IDLE_EXTRA_Y                                     (90)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (155)
    #define CFG_UI_IDLE_SATICON_Y                                   (112)
    
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT    (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_TECHNO                 (151)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM       (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_NAME_Y                             (85)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT  (174)    
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_TECHNO               (174)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM     (105)
    #define CFG_UI_IDLE_SIM2_NETWORK_STATUS_Y                           (105)
#else
    #error "No UI Style is Specified!!"
#endif
/******************************************************************************/

#else /* defined( __MMI_DUAL_SIM_MASTER__) */
/******************************************************************************
 *This Area, is define of Singel SIM IDLE
 ******************************************************************************/
#if defined(__MMI_MAINLCD_128X128__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (22)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (40)
    #define CFG_UI_IDLE_EXTRA_Y                                     (58)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (28)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (49)
    #define CFG_UI_IDLE_EXTRA_Y                                     (69)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (98)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (24)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (24)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (120)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (42)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (44)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (142)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (60)
    #define CFG_UI_IDLE_EXTRA_Y                                     (60)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (160)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (0)
    #define CFG_UI_IDLE_SATICON_Y                                   (0)
#elif defined(__MMI_MAINLCD_240X320__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (138)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (168)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (65)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (198)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (85)
    #define CFG_UI_IDLE_EXTRA_Y                                     (85)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (220)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (220)
    #define CFG_UI_IDLE_SATICON_Y                                   (153)
#elif defined(__MMI_MAINLCD_320X240__)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO_AND_SHORTCUT     (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_TECHNO                  (105)
    #define CFG_UI_IDLE_NETWORK_NAME_Y_WITH_STATUS_AT_BOTTOM        (45)
    #define CFG_UI_IDLE_NETWORK_NAME_Y                              (45)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO_AND_SHORTCUT   (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_TECHNO                (128)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y_WITH_STATUS_AT_BOTTOM      (64)
    #define CFG_UI_IDLE_NETWORK_STATUS_Y                            (65)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO_AND_SHORTCUT            (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_TECHNO                         (154)
    #define CFG_UI_IDLE_EXTRA_Y_WITH_STATUS_AT_BOTTOM               (130)
    #define CFG_UI_IDLE_EXTRA_Y                                     (90)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO_AND_SHORTCUT          (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_TECHNO                       (180)
    #define CFG_UI_IDLE_SATICON_Y_WITH_STATUS_AT_BOTTOM             (155)
    #define CFG_UI_IDLE_SATICON_Y                                   (112)
#else
    #error "No UI Style is Specified!!"
#endif
/******************************************************************************/

#endif /* defined( __MMI_DUAL_SIM_MASTER__) */



/* 
 * MAIN MENU
 */
/* main menu matrix menuitem image width and height */
#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (80)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (60)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (80)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (60)   /* MAX normal image height */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (80)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (60)   /* MAX highlighted image height, affects the cache buffer size */
#else /* defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)  */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_WIDTH               (41)   /* equal to MAIN_MENU_NORMAL_IMAGE_WIDTH */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_CLIP_HEIGHT              (30)   /* equal to MAIN_MENU_NORMAL_IMAGE_HEIGHT */
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_WIDTH                    (42)   /* MAX normal image width */ 
    #define CFG_UI_MAIN_MENU_NORMAL_IMAGE_HEIGHT                   (31)   /* MAX normal image height */
    /* highligted image dimension: 176x220 -> 50x50, 128x160 -> 38x38, 128x128 -> 34x34 */
    // TODO: use different dimensions for each resolution to save memory
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH               (50)   /* MAX highlighted image width, affects the cache buffer size */
    #define CFG_UI_MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT              (50)   /* MAX highlighted image height, affects the cache buffer size */
#endif /* defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__)  */

#if defined (__MMI_MAINLCD_128X128__)

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (16)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                            (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (18)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (18)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (18)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (50)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (50)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (18)
    /* height of menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (18)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (108)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (86)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (10)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (21)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (101)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (15)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (15)

#elif defined __MMI_MAINLCD_128X160__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (20)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (38)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (20)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (50)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (28)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (19)
    /* height of menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (17)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (108)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (116)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (10)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (22)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (132)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (15)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (15)

#elif defined __MMI_MAINLCD_176X220__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                        (24)
    /* height of thick title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (42)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (20)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (70)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (30)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (20)
    /* height of menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (22)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (136)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (138)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (20)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (52)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (138)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)

#elif defined __MMI_MAINLCD_240X320__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (18)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (36)
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (50)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (24)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (84)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (70)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (24)
    /* height of menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (30)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (216)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (192)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (12)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (74)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (192)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (20)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (20)
    
#elif defined __MMI_MAINLCD_320X240__

    /* height of status icon bar */
    #define CFG_UI_STATUS_BAR_HEIGHT                       (36)
    /* y position of status icon bar in idle screen*/
    #define CFG_UI_STATUS_BAR_IDLE_Y                        (0)
    /* height of thin title */
    #define CFG_UI_THIN_TITLE_HEIGHT                       (36)
    /* height of thin title */
    #define CFG_UI_THICK_TITLE_HEIGHT                      (50)
    /* height of button bar*/
    #define CFG_UI_BUTTON_BAR_HEIGHT                       (28)
    /* width of left & right softkey */
    #define CFG_UI_SOFTKEY_WIDTH                           (135)
    /* width of center softkey */
    #define CFG_UI_CENTER_SOFTKEY_WIDTH                    (70)
    /* height of softkey */
    #define CFG_UI_SOFTKEY_HEIGHT                          (28)
    /* height of menu item */
    #define CFG_UI_MENUITEM_HEIGHT                         (29)
    /* width of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_WIDTH                     (240)
    /* height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_HEIGHT                    (178)
    /* x of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_X                         (40)
    /* y of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_Y                         (32)
    /* full height of pop up dialog */
    #define CFG_UI_POP_UP_DIALOG_FULL_HEIGHT               (178)
    /* margin x of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_X                  (10)
    /* margin y of pop up content */
    #define CFG_UI_POP_UP_CONTENT_MARGIN_Y                  (2)

#else
    #error "No UI Style is Specified!!"
#endif


#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
	#if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)
		#define CFG_UI_SCROLLBAR_WIDTH          13
    #elif defined(__MMI_TOUCH_SCREEN__)
        #define CFG_UI_SCROLLBAR_WIDTH          16
    #else
        #define CFG_UI_SCROLLBAR_WIDTH          10
    #endif
#elif defined(__MMI_MAINLCD_176X220__)
	#if defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__)
		#define CFG_UI_SCROLLBAR_WIDTH          8
    #elif defined(__MMI_TOUCH_SCREEN__)
        #define CFG_UI_SCROLLBAR_WIDTH          14
    #else
        #define CFG_UI_SCROLLBAR_WIDTH          8
    #endif
#elif (defined(__MMI_MAINLCD_128X160__) && defined(__MMI_TOUCH_SCREEN__))
    #define CFG_UI_SCROLLBAR_WIDTH              11
#else 
    #define CFG_UI_SCROLLBAR_WIDTH              6
#endif 



/* code added vandana to enable the 4 way navigation key on the softkey background */
/* ISSUE GPRS PPT 6 BOTTOM NAVIAGTION KEYS */
#define CFG_UI_ENABLE_BOTTOM_NAVIGATION_KEYS  (__ON__)

/* Support for two way or four way navigation            */
/* These values should not be changed                 */
#define UI_TWO_WAY_NAVIGATION_KEYS    1
#define UI_FOUR_WAY_NAVIGATION_KEYS    2

/* Support for two way or four way navigation            */
/* Valid values are one of the above navigation types    */
#define CFG_UI_NAVIGATION_KEYS_TYPE        UI_FOUR_WAY_NAVIGATION_KEYS


/* Used by UI_TEXT_MENUITEM_SCROLL_TYPE, don't modify    */
#define UI_TEXT_MENUITEM_SCROLL_TYPE_NONE       0
#define UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE    1
#define UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION 2

/* Type of scrolling to use in text menuitems            */
/* Valid values are one of the above symbols          */
#define CFG_UI_TEXT_MENUITEM_SCROLL_TYPE   UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE

/* Time for scrolling text in menu items              */
/* Value must be an integer (milliseconds)               */
/* Typical values: 100 to 500                      */
#define  CFG_UI_TEXT_MENUITEM_SCROLL_TIME  350

/* Number of pixels by which the text scrolls            */
/* in menu items.                               */
/* Value must be an integer (units are in pixels)        */
/* Typical values: 1 to 5                          */
#define CFG_UI_TEXT_MENUITEM_SCROLL_SIZE   3

/* For Marquee type text scrolling in menu items, this      */
/* specifies the blank gap that should appear at the end */
/* of the string.                                  */
/* Value must be an integer (units are in pixels)        */
/* Typical values: 16 to 64 (This depends on font size)  */
#define CFG_UI_TEXT_MENUITEM_SCROLL_GAP    32

/* This specifies the delay after which a highlighted item  */
/* will scroll. This is a multiple of                 */
/* UI_TEXT_MENUITEM_SCROLL_TIME                    */
/* Value must be an integer. Typically 1, 2 -- etc.      */
    /* Depends on the value of UI_TEXT_MENUITEM_SCROLL_TIME  */
#define CFG_UI_TEXT_MENUITEM_SCROLL_PAUSE  4

/* gap from the menu X1 to menuitem X1 */
#define CFG_UI_MENUITEM_X1_GAP 1
/* gap from the menu X2 to menuitem X2 */
#define CFG_UI_MENUITEM_X2_GAP 1

/* 
 * text right gap for text, icontext, and two-state menu items 
 *
 * This is ONLY VALID for image highlight enabled list menus because 
 * the right side of the highlight image may have borders or rounded edges.
 *
 * Note: Icontext list menu items should use this GAP to have a consistent behavior.
 *  _____________________
 * | **  THIS IS A TEXT  |
 *  ---------------------
 *                     <-> CFG_UI_MENUITEM_TEXT_RIGHT_GAP
 */
#define CFG_UI_MENUITEM_TEXT_RIGHT_GAP 3

/* 
 * menu item icon and text position
 *
 * Menu Item Type       Icon and Text Position
 * =================================================
 * Text                 CFG_UI_TEXT_MENUITEM_TEXT_X
 * Icontext             CFG_UI_ICONTEXT_MENUITEM_ICON_X, CFG_UI_ICONTEXT_MENUITEM_TEXT_X
 * Two-state            CFG_UI_ICONTEXT_MENUITEM_ICON_X, CFG_UI_ICONTEXT_MENUITEM_TEXT_X
 * Icontext List        NONE
 *
 * CAUTION: The coordinate value must be larger than 0.
 */
#define CFG_UI_TEXT_MENUITEM_TEXT_X        1   /* text only */
#define CFG_UI_ICONTEXT_MENUITEM_ICON_X    1   /* icon in icon-text */
#define CFG_UI_ICONTEXT_MENUITEM_TEXT_X    (CFG_UI_MENUITEM_HEIGHT + 2)  /* text in icon-text */

#define CFG_UI_ENABLE_POP_UP_DESCRIPTIONS (__ON__)

/* Used by UI_POP_UP_DESCRIPTION_SCROLL_TYPE, don't modify  */
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_NONE           0
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE        1
#define UI_POP_UP_DESCRIPTION_SCROLL_TYPE_TWO_DIRECTION     2

/* Type of scrolling to use in Pop up descriptions       */
/* Valid values are one of the above symbols          */
#define CFG_UI_POP_UP_DESCRIPTION_SCROLL_TYPE UI_POP_UP_DESCRIPTION_SCROLL_TYPE_MARQUEE

#define CFG_UI_CURSOR_WAIT_TIME            (1000)
#define CFG_UI_CURSOR_BLINK_TIME           (500)

/*----------------------------------------------------------------*/
/* Slider                                                         */
/*----------------------------------------------------------------*/ 
/*
 *                      UI_SLIDER_X1_GAP
 *                          <--> 
 *                              --
 *  Slider Background Image <--|##|--------------->
 *                              --
 *                         Slider Button 
 *                         at the LEFTEST position
 *
 *
 *                                          UI_SLIDER_X2_GAP
 *                                              <-> 
 *                                            -- 
 *  Slider Background Image <----------------|##|->
 *                                            -- 
 *                                       Slider Button 
 *                                       at the RIGHTEST position
 *
 */

/* 
 * the left gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#define CFG_UI_SLIDER_X1_GAP    2

/* 
 * the right gap from the slider button to the slider background image
 * This value depends on the background image style, e.g. round-rected or bordered.
 */
#define CFG_UI_SLIDER_X2_GAP    2

/*
 *  TEXT LABEL            
 *          ^ 
 *          | <- GUI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP (at least 1)
 *  ________v_____________    
 * |  __________________  | | <- GUI_SLIDE_CONTROL_FOCUS_GAP (the 1-pixel rectangle is included.)
 * | |     SLIDER       | |
 * | |__________________| |
 * |______________________|<- FOCUS Rectangle
 *
 */
#define CFG_UI_SLIDE_CONTROL_FOCUS_GAP     (2)
#define CFG_UI_SLIDE_CONTROL_TEXT_LABEL_TO_FOCUS_GAP   (2)

/* shortcut */
#define CFG_UI_SHORTCUT_WIDTH              (30)          /* default wdith of shortcut */
#define CFG_UI_SHORTCUT_GAP                (8)           /* default GAP of shortcut */

#if defined(__MMI_MAINLCD_240X320__)  || defined(__MMI_MAINLCD_320X240__) 
    #define CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP  (5)           /* gap of border text */
#else 
    #define CFG_UI_SHORTCUT_TEXT_BORDER_X_GAP  (2)           /* gap of border text */
#endif 

#define CFG_UI_SHORTCUT_INSERT_GAP         (3)           /* gap between normal mode and insert mode */     


/* title */
#define CFG_UI_TITLE_NON_ICON_GAP          (2)           /* gap between text area and title area */
#if defined(__MMI_MAINLCD_320X240__) 
    #define CFG_UI_TITLE_ICON_GAP          (3)           /* gap between text area and icon area */
#else
    #define CFG_UI_TITLE_ICON_GAP          (1)           /* gap between text area and icon area */
#endif
#define CFG_UI_TITLE_TEXT_GAP              (2)           /* gap between text width and text area */
#define CFG_UI_TITLE_SCROLLING_GAP         (4)           /* gap between scrolling area and title area */

#define CFG_UI_TITLE_SCROLLING_INIT_X      (-2)          /* init x of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_Y      (0)           /* init y of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_WIDTH  (0)           /* init width of scrolling */
#define CFG_UI_TITLE_SCROLLING_INIT_HEIGHT (0)           /* init height of scrolling */
#define CFG_UI_TITLE_SCROLLING_ICON_X      (1)           /* left position of icon*/

#define CFG_UI_SOFTKEY_GAP                  (2)			/* gap between softkey and edge */
#define CFG_UI_STATUSBAR_GAP                (1)			/* gap between status icon and edge */

#endif /* __GUI_SWITCH_H__ */
