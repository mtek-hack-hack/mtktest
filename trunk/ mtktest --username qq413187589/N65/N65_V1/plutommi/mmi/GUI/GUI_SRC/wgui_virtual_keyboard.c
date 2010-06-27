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
 *   wgui_virtual_keyboard.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Virtual keyboard - WGUI integration
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
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#include "MMIDataType.h"
#include "MMI_features.h"
#include "gui_data_types.h"
#include "gui.h"
#include "gdi_include.h"
#include "wgui.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_categories_defs.h"
#include "DebugInitDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/* Dead keys (also as normal symbol) */
#define  GRAVE_ACCENT            0x60   /* ` */
#define  ACCUTE_ACCENT           0xB4
#define  CIRCUMFLEX_ACCENT       0x5E   /* ^ */
#define  DIAERESIS               0xA8
#define  TILDE                   0x7E   /* ~ */
//Liu Jun add 20070319
#define  HACEK              0x02C7 
#define  DIALYTIKA          0x0385
#define  GREEK_ACUTE        0x0384
#define  CEDILLA            0x00B8
#define  OGONEK             0x02DB
//Liu Jun add end

/* Common european symbols */
#define  EURO                    0x20AC

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

virtual_keyboard MMI_virtual_keyboard;

/* Maximum required size of key image cache. */
S32 MMI_virtual_keyboard_bitmap_cache_size;

/****************************
 * Standard layout
 ****************************/

static const gui_matrix_key_layout_struct gui_standard_matrix_layout = 
{
    MMI_VKBD_STANDARD_MATRIX_X, MMI_VKBD_STANDARD_MATRIX_Y,
    MMI_VKBD_STANDARD_MATRIX_COLUMN, MMI_VKBD_STANDARD_MATRIX_ROW,
    MMI_VKBD_STANDARD_MATRIX_WIDTH, MMI_VKBD_STANDARD_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_standard_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    {141, 42, 19, 19},
    {161, 42, 39, 19},
    {201, 42, 38, 19}
};

#elif defined (__MMI_MAINLCD_320X240__) 

static const gui_custom_key_layout_struct gui_standard_custom_key_layout[] = 
{
    {183, 2, 25, 19},
    {209, 2, 25, 19},
    {235, 2, 25, 19},
    {261, 2, 58, 19},
    {183, 22, 25, 19},
    {209, 22, 25, 19},
    {235, 22, 25, 19},
    {261, 22, 58, 19},
    {183, 42, 25, 19},
    {209, 42, 52, 19},
    {261, 42, 58, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_standard_custom_key_layout[] = 
{
    {106, 1, 14, 14},
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14},
    {106, 16, 14, 14},
    {121, 16, 14, 14},
    {136, 16, 14, 14},
    {151, 16, 24, 14},
    {106, 31, 14, 14},
    {121, 31, 29, 14},
    {151, 31, 24, 14}
};

#else /* (__MMI_MAINLCD_128X160__) */

static const gui_custom_key_layout_struct gui_standard_custom_key_layout[] = 
{
    {78, 1, 10, 10},
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 18, 10},
    {78, 12, 10, 10},
    {89, 12, 10, 10},
    {100, 12, 10, 10},
    {111, 12, 17, 10},
    {78, 23, 10, 10},
    {89, 23, 21, 10},
    {111, 23, 17, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_standard_layout = 
{
    MMI_VKBD_STANDARD_WIDTH,
    MMI_VKBD_STANDARD_HEIGHT,
    1,
    11,
    &gui_standard_matrix_layout,
    gui_standard_custom_key_layout,
    IMG_VKBD_STANDARD
};

/* English lowercase */
//Liu Jun add 20070319
/*English vk is equal to Dutch vk, if add compile option for English vk, it should
 *modify the code of Dutch vk*/
//Liu Jun add end
static const gui_keyboard_language_struct gui_keyboard_english_lowercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'q', 'w', 'e', 'r', 't', 'y', 'u', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', '\0'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', '\0'}
     },
    {'i', 'o', 'p', '\0', 'k', 'l', '.', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE,
     GUI_VKBD_PEN_SYMBPICKER}
};

/* English uppercase */
static const gui_keyboard_language_struct gui_keyboard_english_uppercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', '\0'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', '\0'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M', '\0'}
     },
    {'I', 'O', 'P', '\0', 'K', 'L', '.', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE,
     GUI_VKBD_PEN_SYMBPICKER}
};

// #if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__)

static const gui_keyboard_language_struct gui_keyboard_chinese_symbol_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {0x3002, 0xFF0C, 0xFF0E, 0x3001, 0xFF1B, 0xFF1A, 0xFF1F, '\0'},
     {0x3010, 0x3011, 0x300A, 0x300B, 0x3008, 0x3009, 0x300C, '\0'},
     {0x2018, 0x2019, 0x201C, 0x201D, 0x2190, 0x2192, 0x2193, '\0'}
     },
    {0xFF01, 0xFF08, 0xFF09, '\0', 0x300D, 0x300E, 0x300F, '\0', 0x2191, '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE,
     GUI_VKBD_PEN_SYMBPICKER}
};

// #endif /* __MMI_LANG_TR_CHINESE__ || __MMI_LANG_SM_CHINESE__ */

/****************************
 * Extended layout
 ****************************/

static const gui_matrix_key_layout_struct gui_extended_matrix_layout = 
{
    MMI_VKBD_EXTENDED_MATRIX_X, MMI_VKBD_EXTENDED_MATRIX_Y,
    MMI_VKBD_EXTENDED_MATRIX_COLUMN, MMI_VKBD_EXTENDED_MATRIX_ROW,
    MMI_VKBD_EXTENDED_MATRIX_WIDTH, MMI_VKBD_EXTENDED_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_extended_custom_key_layout[] = 
{
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19},
    {161, 62, 39, 19},
    {201, 62, 38, 19}
};
#elif defined (__MMI_MAINLCD_320X240__) 

static const gui_custom_key_layout_struct gui_extended_custom_key_layout[] = 
{
    {209, 2, 25, 19},
    {235, 2, 25, 19},
    {261, 2, 58, 19},
    {209, 22, 25, 19},
    {235, 22, 25, 19},
    {261, 22, 58, 19},
    {209, 42, 25, 19},
    {235, 42, 25, 19},
    {261, 42, 58, 19},
    {209, 62, 51, 19},
    {261, 62, 58, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_extended_custom_key_layout[] = 
{
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14},
    {121, 16, 14, 14},
    {136, 16, 14, 14},
    {151, 16, 24, 14},
    {121, 31, 14, 14},
    {136, 31, 14, 14},
    {151, 31, 24, 14},
    {121, 46, 29, 14},
    {151, 46, 24, 14}
};

#else /* (__MMI_MAINLCD_128X160__) */

static const gui_custom_key_layout_struct gui_extended_custom_key_layout[] = 
{
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 17, 10},
    {89, 12, 10, 10},
    {100, 12, 10, 10},
    {111, 12, 17, 10},
    {89, 23, 10, 10},
    {100, 23, 10, 10},
    {111, 23, 17, 10},
    {89, 34, 21, 10},
    {111, 34, 17, 10}
};


#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_extended_layout = 
{
    MMI_VKBD_EXTENDED_WIDTH,
    MMI_VKBD_EXTENDED_HEIGHT,
    1,
    11,
    &gui_extended_matrix_layout,
    gui_extended_custom_key_layout,
    IMG_VKBD_EXTENDED
};

/* Standard symbols */
static const gui_keyboard_language_struct gui_keyboard_symbol_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'\x2e', '\x2c', '?', '!', '^', '"', '(', ')', '\0'},
     {'_', ':', ';', '+', '-', '*', '/', '=', '\0'},
     {'<', '>', 0xA3, 0x24, 0xA5, 0xA7, 0x20AC, 0xA4, '\0'},
     {'{', '}', '~', '#', '`', '\'', 0xA9, '|'} /* Note that 0xA9 is not standard GSM 7-bit character */
     },
    {'@', '\\', '\0', '%', '&', '\0', '[', ']', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, IMG_VKBD_CUSTOM_ENTER,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_NEWLINE,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#ifdef __MMI_LANG_SPANISH__

static const gui_keyboard_language_struct gui_keyboard_spanish_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {GRAVE_ACCENT, ACCUTE_ACCENT, CIRCUMFLEX_ACCENT, DIAERESIS, TILDE,
      '.', 0xBA, 0xA1},
     {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '\0'},
     },
    {0xF1, 0xE7, '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_spanish_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {GRAVE_ACCENT, ACCUTE_ACCENT, CIRCUMFLEX_ACCENT, DIAERESIS, TILDE,
      '.', 0xAA, 0xBF},
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', '\0'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', '\0'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '\0'},
     },
    {0xD1, 0xC7, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /* __MMI_LANG_SPANISH__ */ 

#ifdef __MMI_LANG_FRENCH__

static const gui_keyboard_language_struct gui_keyboard_french_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, DIAERESIS, TILDE, GRAVE_ACCENT,
      '.', 0xE0, 0xE7, 0xE9},
     {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', '\0'},
     {'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'},
     {'w', 'x', 'c', 'v', 'b', 'n', 0xF9, ',', '\0'},
     },
    {0xE8, 'm', '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_french_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, DIAERESIS, TILDE, GRAVE_ACCENT,
      '.', 0xB0, EURO, 0xA7},
     {'A', 'Z', 'E', 'R', 'T', 'Y', 'U', 'I', '\0'},
     {'Q', 'S', 'D', 'F', 'G', 'H', 'J', 'K', '\0'},
     {'W', 'X', 'C', 'V', 'B', 'N', 0xB5, ',', '\0'},
     },
    {0xA3, 'M', '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_FRENCH__ */ 

#ifdef __MMI_LANG_PORTUGUESE__

static const gui_keyboard_language_struct gui_keyboard_portuguese_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, DIAERESIS, TILDE, GRAVE_ACCENT, ACCUTE_ACCENT,
      '.', 0xBA, 0xA3},
     {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '\0'},
     },
    {0xA7, 0xE7, '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_portuguese_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, DIAERESIS, TILDE, GRAVE_ACCENT, ACCUTE_ACCENT,
      0xBA, 0xAA, 0xAB},
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', '\0'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', '\0'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '\0'},
     },
    {0xBB, 0xC7, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_PORTUGUESE__ */ 

#ifdef __MMI_LANG_GERMAN__

static const gui_keyboard_language_struct gui_keyboard_german_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, ACCUTE_ACCENT, GRAVE_ACCENT, '.', 0xB0, 0xB5, 0xDF, 0xE4},
     {'q', 'w', 'e', 'r', 't', 'z', 'u', 'i', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm', ',', '\0'},
     },
    {0xFC, 0xF6, '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_german_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, ACCUTE_ACCENT, GRAVE_ACCENT, '.', 0xA7, 0xB2, 0xB3, 0xC4},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', '\0'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', '\0'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M', ',', '\0'},
     },
    {0xDC, 0xD6, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_GERMAN__ */ 

#ifdef __MMI_LANG_ITALIAN__

static const gui_keyboard_language_struct gui_keyboard_italian_lowercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'.', CIRCUMFLEX_ACCENT, 0xA3, 0xE9, 0xE8, 0xE0, 0xF9, 0xEC},
     {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '\0'},
     },
    {0xF2, 0xE7, '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_italian_uppercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'.', 0xA7, 0xA3, 0xE9, 0xE8, 0xE0, 0xF9, 0xEC},
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', '\0'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', '\0'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '\0'},
     },
    {0xF2, 0xE7, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_ITALIAN__ */ 

#ifdef __MMI_LANG_RUSSIAN__

static const gui_keyboard_language_struct gui_keyboard_russian_lowercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {0x451, '.', DIAERESIS, '!', 0x445, 0x44A, 0x44D, 0x431},
     {0x439, 0x446, 0x443, 0x43A, 0x435, 0x43D, 0x433, 0x448, '\0'},
     {0x444, 0x44B, 0x432, 0x430, 0x43F, 0x440, 0x43E, 0x43B, '\0'},
     {0x44F, 0x447, 0x441, 0x43C, 0x438, 0x442, 0x44C, ',', '\0'},
     },
    {0x44E, 0x2116, '\0', 0x449, 0x437, '\0', 0x434, 0x436, '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_russian_uppercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {0x401, '.', DIAERESIS, '!', 0x425, 0x42A, 0x42D, 0x411},
     {0x419, 0x426, 0x423, 0x41A, 0x415, 0x41D, 0x413, 0x428, '\0'},
     {0x424, 0x42B, 0x412, 0x410, 0x41F, 0x420, 0x41E, 0x41B, '\0'},
     {0x42F, 0x427, 0x421, 0x41C, 0x418, 0x422, 0x42C, ',', '\0'},
     },
    {0x42E, 0x2116, '\0', 0x429, 0x417, '\0', 0x414, 0x416, '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_RUSSIAN__ */ 

#ifdef __MMI_LANG_TURKISH__

static const gui_keyboard_language_struct gui_keyboard_turkish_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, ACCUTE_ACCENT, GRAVE_ACCENT, DIAERESIS, TILDE, 0x15F, 0x62, 0x78},
     {0x66, 0x67, 0x11F, 0x131, 0x6F, 0x64, 0x72, 0x6E, '\0'},
     {0x75, 0x69, 0x65, 0x61, 0x74, 0x6B, 0x6D, 0x6C, '\0'},
     {0x6A, 0xF6, 0x76, 0x63, 0xE7, 0x7A, 0x73, ',', '\0'},
     },
    {0x71, 0x77, '\0', 0x68, 0x70, '\0', 0x79, '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_turkish_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {CIRCUMFLEX_ACCENT, ACCUTE_ACCENT, GRAVE_ACCENT, DIAERESIS, TILDE, 0x15E, 0x42, 0x58},
     {0x46, 0x47, 0x11E, 0x49, 0x4F, 0x44, 0x52, 0x4E, '\0'},
     {0x55, 0x130, 0x45, 0x41, 0x54, 0x4B, 0x4D, 0x4C, '\0'},
     {0x4A, 0xD6, 0x56, 0x43, 0xC7, 0x5A, 0x53, ',', '\0'},
     },
    {0x51, 0x57, '\0', 0x48, 0x50, '\0', 0x59, '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_LANG_TURKISH__ */ 

#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__

static const gui_keyboard_language_struct gui_keyboard_european_symbols_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {0x40, 0xA1, 0xA2, 0xA3, 0xA4, 0xA7, 0xA9, 0xAA, '\0'},
     {0xAE, 0xB0, 0xB9, 0xBA, 0xB2, 0xB3, 0xB5, 0xB6, '\0'},
     {0xBD, 0xBE, 0xBF, 0xC6, 0xC7, 0xD8, 0xDF, 0xE6, '\0'},
     {0x11E, 0x11F, 0x130, 0x131, 0x15E, 0x15F, 0x20AC, ',', '\0'},
     },
    {0xAB, 0xAC, '\0', 0xBB, 0xBC, '\0', 0xE7, 0xF8, '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, IMG_VKBD_CUSTOM_ENTER,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_NEWLINE,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /* __MMI_VKBD_EUROPEAN_SUPPORT__ */ 

/****************************
 * Number layout
 ****************************/

static const gui_matrix_key_layout_struct gui_number_matrix_layout = 
{
    MMI_VKBD_NUMBER_MATRIX_X, MMI_VKBD_NUMBER_MATRIX_Y,
    MMI_VKBD_NUMBER_MATRIX_COLUMN, MMI_VKBD_NUMBER_MATRIX_ROW,
    MMI_VKBD_NUMBER_MATRIX_WIDTH, MMI_VKBD_NUMBER_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_number_custom_key_layout[] = 
{
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    {161, 22, 39, 19},
    {201, 22, 38, 19}
};
#elif defined(__MMI_MAINLCD_320X240__)

static const gui_custom_key_layout_struct gui_number_custom_key_layout[] = 
{
    {209, 2, 25, 19},
    {235, 2, 25, 19},
    {261, 2, 58, 19},
    {209, 22, 51, 19},
    {261, 22, 58, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_number_custom_key_layout[] = 
{
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14},
    {121, 16, 29, 14},
    {151, 16, 24, 14}
};


#else /* (__MMI_MAINLCD_128X160__) */

static const gui_custom_key_layout_struct gui_number_custom_key_layout[] = 
{
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 17, 10},
    {89, 12, 21, 10},
    {111, 12, 17, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_number_layout = 
{
    MMI_VKBD_NUMBER_WIDTH,
    MMI_VKBD_NUMBER_HEIGHT,
    1,
    5,
    &gui_number_matrix_layout,
    gui_number_custom_key_layout,
    IMG_VKBD_NUMBER
};

static const gui_keyboard_language_struct gui_keyboard_number_string = 
{
    MMI_FALSE,
    1,
    5,
    {
     {'0', '1', '2', '3', '4', '5', '6', '7', '\0'},
     {'*', '/', '+', '-', '.', '%', '$', '=', '\0'}
     },
    {'8', '9', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_BACKSPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_BAKSPACE}
};

static const gui_keyboard_language_struct gui_keyboard_phone_number_string = 
{
    MMI_FALSE,
    1,
    5,
    {
     {'0', '1', '2', '3', '4', '5', '6', '7', '\0'},
     {'*', '#', '+', '-', 'p', 'w', '(', ')', '\0'}
     },
    {'8', '9', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_BACKSPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_BAKSPACE}
};

/****************************
 * Tray layout
 ****************************/

static const gui_matrix_key_layout_struct gui_tray_matrix_layout = 
{
    MMI_VKBD_TRAY_MATRIX_X, MMI_VKBD_TRAY_MATRIX_Y,
    MMI_VKBD_TRAY_MATRIX_COLUMN, MMI_VKBD_TRAY_MATRIX_ROW,
    MMI_VKBD_TRAY_MATRIX_WIDTH, MMI_VKBD_TRAY_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_tray_custom_key_layout[] = 
{
    {101, 2, 19, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19}
};

#elif defined (__MMI_MAINLCD_320X240__)

static const gui_custom_key_layout_struct gui_tray_custom_key_layout[] = 
{
    {131, 2, 25, 19},
    {157, 2, 25, 19},
    {183, 2, 25, 19},
    {209, 2, 25, 19},
    {235, 2, 25, 19},
    {261, 2, 58, 19},
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_tray_custom_key_layout[] = 
{
    {76, 1, 14, 14},
    {91, 1, 14, 14},
    {106, 1, 14, 14},
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14}
};

#else /* (__MMI_MAINLCD_128X160__) */
static const gui_custom_key_layout_struct gui_tray_custom_key_layout[] = 
{
    {56, 1, 10, 10},
    {67, 1, 10, 10},
    {78, 1, 10, 10},
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 17, 10}
};



#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_tray_layout = 
{
    MMI_VKBD_TRAY_WIDTH,
    MMI_VKBD_TRAY_HEIGHT,
    1,
    6,
    &gui_tray_matrix_layout,
    gui_tray_custom_key_layout,
    IMG_VKBD_TRAY
};

static const gui_keyboard_language_struct gui_keyboard_tray_string = 
{
    MMI_FALSE,
    1,
    6,
    {'?', ',', ':', '.', ';'},
    {'\0', '\0', '\0', '\0', '\0', '\0'},
    {IMG_VKBD_CUSTOM_BRACKET, IMG_VKBD_CUSTOM_ENTER, IMG_VKBD_CUSTOM_SPACE,
     IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_SYMBPICKER, IMG_VKBD_CUSTOM_SHOW},
    {GUI_VKBD_PEN_BRACKET, GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_SPACE,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_SHOW}
};

/* Used in inline editor */
static const gui_keyboard_language_struct gui_keyboard_empty_tray_string = 
{
    MMI_FALSE,
    1,
    6,
    {'\0', '\0', '\0', '\0', '\0'},
    {'\0', '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, 0, 0, 0},
    {GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE,
     GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE, GUI_VKBD_PEN_NONE}
};

/* Used in inline editor */
static const gui_keyboard_language_struct gui_keyboard_number_tray_string = 
{
    MMI_FALSE,
    1,
    6,
    {'0', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE}
};

/* Used in inline editor for 0~9 and dot(.) */
static const gui_keyboard_language_struct gui_keyboard_number_dot_tray_string = 
{
    MMI_FALSE,
    1,
    6,
    {'0', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9', '.'},
    {0, 0, 0, 0, 0, 0},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I}
};

/****************************
 * Pinyin layout
 ****************************/

// #ifdef __MMI_LANG_SM_CHINESE__

static const gui_matrix_key_layout_struct gui_pinyin_matrix_layout = 
{
    MMI_VKBD_PINYIN_MATRIX_X, MMI_VKBD_PINYIN_MATRIX_Y,
    MMI_VKBD_PINYIN_MATRIX_COLUMN, MMI_VKBD_PINYIN_MATRIX_ROW,
    MMI_VKBD_PINYIN_MATRIX_WIDTH, MMI_VKBD_PINYIN_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_pinyin_custom_key_layout[] = 
{
    {1, 2, 19, 19},
    {21, 2, 19, 19},
    {41, 2, 159, 19},
    {201, 2, 38, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19},
    {181, 62, 58, 19}
};

#elif defined(__MMI_MAINLCD_320X240__)

static const gui_custom_key_layout_struct gui_pinyin_custom_key_layout[] = 
{
    {1, 2, 25, 19},
    {27, 2, 25, 19},
    {53, 2, 207, 19},
    {261, 2, 58, 19},
    {235, 22, 25, 19},
    {261, 22, 58, 19},
    {235, 42, 25, 19},
    {261, 42, 58, 19},
    {235, 62, 84, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_pinyin_custom_key_layout[] = 
{
    {1, 1, 14, 14},
    {16, 1, 14, 14},
    {31, 1, 119, 14},
    {151, 1, 24, 14},
    {136, 16, 14, 14},
    {151, 16, 24, 14},
    {136, 31, 14, 14},
    {151, 31, 24, 14},
    {136, 46, 39, 14}
};


#else /* (__MMI_MAINLCD_128X160__) */

static const gui_custom_key_layout_struct gui_pinyin_custom_key_layout[] = 
{
    {1, 1, 10, 10},
    {12, 1, 10, 10},
    {23, 1, 87, 10},
    {111, 1, 17, 10},
    {100, 12, 10, 10},
    {111, 12, 17, 10},
    {100, 23, 10, 10},
    {111, 23, 17, 10},
    {100, 34, 28, 10}
};



#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_pinyin_layout = 
{
    MMI_VKBD_PINYIN_WIDTH,
    MMI_VKBD_PINYIN_HEIGHT,
    1,
    9,
    &gui_pinyin_matrix_layout,
    gui_pinyin_custom_key_layout,
    IMG_VKBD_PINYIN
};

static const gui_keyboard_language_struct gui_keyboard_pinyin_string = 
{
    MMI_FALSE,
    1,
    9,
    {
     {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', '\0'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '\0'}
     },
    {':', '\0', '\0', '\0', 'p', '\0', '?', '\0', '\0'},
    {0, IMG_VKBD_CUSTOM_BRACKET, IMG_VKBD_PINYIN_DISPAREA, IMG_VKBD_CUSTOM_HIDE,
     0, IMG_VKBD_CUSTOM_BACKSPACE, 0, IMG_VKBD_CUSTOM_SYMBPICKER, IMG_VKBD_CUSTOM_SPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BRACKET, GUI_VKBD_PEN_DISPLAY_AREA, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_SPACE}
};

// #endif /* __MMI_LANG_SM_CHINESE__ */

/****************************
 * Bopomo layout
 ****************************/

// #ifdef __MMI_LANG_TR_CHINESE__

static const gui_matrix_key_layout_struct gui_bopomo_matrix_layout = 
{
    MMI_VKBD_BOPOMO_MATRIX_X, MMI_VKBD_BOPOMO_MATRIX_Y,
    MMI_VKBD_BOPOMO_MATRIX_COLUMN, MMI_VKBD_BOPOMO_MATRIX_ROW,
    MMI_VKBD_BOPOMO_MATRIX_WIDTH, MMI_VKBD_BOPOMO_MATRIX_HEIGHT,
    MMI_VKBD_MATRIX_KEY_WIDTH, MMI_VKBD_MATRIX_KEY_HEIGHT,
    MMI_VKBD_MATRIX_KEY_H_GAP, MMI_VKBD_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_bopomo_custom_key_layout[] = 
{
    {1, 2, 19, 19},
    {21, 2, 19, 19},
    {41, 2, 19, 19},
    {61, 2, 59, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    {201, 22, 38, 19},
    {201, 42, 38, 19},
    {201, 62, 38, 19}
};

#elif defined (__MMI_MAINLCD_320X240__)

static const gui_custom_key_layout_struct gui_bopomo_custom_key_layout[] = 
{
    {1, 2, 25, 19},
    {27, 2, 25, 19},
    {53, 2, 25, 19},
    {79, 2, 76, 19},
    {157, 2, 25, 19},
    {183, 2, 25, 19},
    {209, 2, 25, 19},
    {235, 2, 25, 19},
    {261, 2, 58, 19},
    {261, 22, 58, 19},
    {261, 42, 58, 19},
    {261, 62, 58, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_bopomo_custom_key_layout[] = 
{
    {1, 1, 14, 14},
    {16, 1, 14, 14},
    {31, 1, 14, 14},
    {46, 1, 44, 14},
    {91, 1, 14, 14},
    {106, 1, 14, 14},
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14},
    {151, 16, 24, 14},
    {151, 31, 24, 14},
    {151, 46, 24, 14}
};


#else /* (__MMI_MAINLCD_128X160__) */

static const gui_custom_key_layout_struct gui_bopomo_custom_key_layout[] = 
{
    {1, 1, 10, 10},
    {12, 1, 10, 10},
    {23, 1, 10, 10},
    {34, 1, 32, 10},
    {67, 1, 10, 10},
    {78, 1, 10, 10},
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 17, 10},
    {111, 12, 17, 10},
    {111, 23, 17, 10},
    {111, 34, 17, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_bopomo_layout = 
{
    MMI_VKBD_BOPOMO_WIDTH,
    MMI_VKBD_BOPOMO_HEIGHT,
    1,
    12,
    &gui_bopomo_matrix_layout,
    gui_bopomo_custom_key_layout,
    IMG_VKBD_BOPOMO
};

static const gui_keyboard_language_struct gui_keyboard_bopomo_string = 
{
    MMI_FALSE,
    1,
    12,
    {
     {0x3106, 0x310a, 0x3114, 0x310d, 0x3110, 0x3117, 0x3127, 0x311b, 0x311f, 0x3123},
     {0x3107, 0x310b, 0x3115, 0x310e, 0x3111, 0x3118, 0x3128, 0x311c, 0x3120, 0x3124},
     {0x3108, 0x310c, 0x3116, 0x310f, 0x3112, 0x3119, 0x3129, 0x311d, 0x3121, 0x3125},
     },
    {0x3105, 0x3109, 0x3113, '\0', 0x3126, 0x311a, 0x311e, 0x3122, '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_BOPOMO_DISPAREA, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE, IMG_VKBD_CUSTOM_BACKSPACE,
     IMG_VKBD_CUSTOM_SYMBPICKER, IMG_VKBD_CUSTOM_SPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_DISPLAY_AREA, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_SPACE}
};

// #endif /* __MMI_LANG_TR_CHINESE__ */

//Liu Jun add 20070319
/****************************
 * Czech layout
 ****************************/
#if (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__))
/*Czech layout is equal to Slovak layout*/
static const gui_matrix_key_layout_struct gui_czech_matrix_layout = 
{
    MMI_VKBD_CZECH_MATRIX_X, MMI_VKBD_CZECH_MATRIX_Y,
    MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_ROW,
    MMI_VKBD_CZECH_MATRIX_WIDTH, MMI_VKBD_CZECH_MATRIX_HEIGHT,
    MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT,
    MMI_VKBD_CZECH_MATRIX_KEY_H_GAP, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_czech_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},
    
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},
    
    {141, 62, 19, 19},
    {161, 62, 39, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_czech_custom_key_layout[] = 
{
    {102, 1, 14, 14},
    {116, 1, 14, 14},
    {130, 1, 14, 14},
    {144, 1, 28, 14},
    
    {102, 16, 14, 14},
    {116, 16, 14, 14},
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},
    
    {102, 31, 14, 14},
    {116, 31, 14, 14},
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {102, 46, 14, 14},
    {116, 46, 28, 14},
    {144, 46, 28, 14}
};

#else /* __MMI_MAINLCD_128x160__ */ 

static const gui_custom_key_layout_struct gui_czech_custom_key_layout[] = 
{
    {71, 1, 10, 10},
    {82, 1, 10, 10},
    {93, 1, 10, 10},
    {104, 1, 23, 10},
    
    {71, 12, 10, 10},
    {82, 12, 10, 10},
    {93, 12, 10, 10},
    {104, 12, 11, 10},
    {116, 12, 11, 10},
    
    {71, 23, 10, 10},
    {82, 23, 10, 10},
    {93, 23, 10, 10},
    {104, 23, 11, 10},
    {116, 23, 11, 10},
    
    {71, 34, 10, 10},
    {82, 34, 21, 10},
    {104, 34, 23, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_czech_layout = 
{
    MMI_VKBD_CZECH_WIDTH,
    MMI_VKBD_CZECH_HEIGHT,
    1,
    17,
    &gui_czech_matrix_layout,
    gui_czech_custom_key_layout,
    IMG_VKBD_CZECH
};
#endif /*(defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__))*/

#ifdef __MMI_LANG_CZECH__
static const gui_keyboard_language_struct gui_keyboard_czech_lowercase_string = 
{
    MMI_TRUE,
    1,
    17,
    {
     {HACEK, 0x011B, 0x0161, 0x010D, 0x0159, 0x017E, 0x00FD},
     {'q', 'w', 'e', 'r', 't', 'z', 'u'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm'}
    },
    {0x00E1, 0x00ED, 0x00E9, '\0', 'i', 'o', 'p', ACCUTE_ACCENT, '\0', 'k', 'l', 0x016F, 0x00FA,
     '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_czech_uppercase_string = 
{
    MMI_TRUE,
    1,
    17,
    {
     {HACEK, 0x011A, 0x0160, 0x010C, 0x0158, 0x017D, 0x00DD},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M'}
    },
    {0x00C1, 0x00CD, 0x00C9, '\0', 'I', 'O', 'P', ACCUTE_ACCENT, '\0', 'K', 'L', 0x016E, 0x00DA,
     '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /*__MMI_LANG_CZECH__*/

#ifdef __MMI_LANG_SLOVAK__
static const gui_keyboard_language_struct gui_keyboard_slovak_lowercase_string = 
{
    MMI_TRUE,
    1,
    17,
    {
     {ACCUTE_ACCENT, HACEK, 0x010D, 0x0165, 0x017E, 0x00FD, 0x00E1},
     {'q', 'w', 'e', 'r', 't', 'z', 'u'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm'}
    },
    {0x00ED, 0x00E9, 0x00FA, '\0', 'i', 'o', 'p', 0x00E4, '\0', 'k', 'l', 0x00F4, 0x00A7,
     '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_slovak_uppercase_string = 
{
    MMI_TRUE,
    1,
    17,
    {
     {ACCUTE_ACCENT, HACEK, 0x010D, 0x0165, 0x017E, 0x00FD, 0x00E1},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M'}
    },
    {0x00ED, 0x00E9, 0x00FA, '\0', 'I', 'O', 'P', 0x00E4, '\0', 'K', 'L', 0x00F4, 0x00A7,
     '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /*__MMI_LANG_SLOVAK__*/


#ifdef __MMI_LANG_HEBREW__

static const gui_matrix_key_layout_struct gui_hebrew_matrix_layout = 
{
    MMI_VKBD_HEBREW_MATRIX_X, MMI_VKBD_HEBREW_MATRIX_Y,
    MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_ROW,
    MMI_VKBD_HEBREW_MATRIX_WIDTH, MMI_VKBD_HEBREW_MATRIX_HEIGHT,
    MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT,
    MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_hebrew_custom_key_layout[] = 
{
    {161, 2, 39, 19},
    {201, 2, 38, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    
    {201, 22, 38, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_hebrew_custom_key_layout[] = 
{
    {121, 1, 29, 14},
    {151, 1, 24, 14},
    
    {121, 16, 14, 14},
    {136, 16, 14, 14},
    {151, 16, 24, 14},
    
    {121, 31, 14, 14},
    {136, 31, 14, 14},
    {151, 31, 24, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_hebrew_custom_key_layout[] = 
{
    {81, 1, 23, 10},
    {105, 1, 22, 10},
    
    {81, 12, 11, 10},
    {93, 12, 11, 10},
    {105, 12, 22, 10},
    
    {81, 23, 11, 10},
    {93, 23, 11, 10},
    {105, 23, 22, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_hebrew_layout = 
{
    MMI_VKBD_HEBREW_WIDTH,
    MMI_VKBD_HEBREW_HEIGHT,
    1,
    8,
    &gui_hebrew_matrix_layout,
    gui_hebrew_custom_key_layout,
    IMG_VKBD_HEBREW
};

static const gui_keyboard_language_struct gui_keyboard_hebrew_string = 
{
    MMI_FALSE,
    1,
    8,
    {
     {0x05E7, 0x05E8, 0x05D0, 0x05D8, 0x05D5, 0x05DF, 0x05DD, 0x05E4},
     {0x05E9, 0x05D3, 0x05D2, 0x05DB, 0x05E2, 0x05D9, 0x05D7, 0x05DC},
     {0x05D6, 0x05E1, 0x05D1, 0x05D4, 0x05E0, 0x05DE, 0x05E6, 0x05EA}
    },
    {'\0', '\0', 0x05DA, 0x05E3, '\0', 0x05E5, '\0', '\0'},
    {IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_HEBREW__*/

#ifdef __MMI_LANG_PERSIAN__

/*Farsi layout is equal to Hungrian*/
static const gui_matrix_key_layout_struct gui_farsi_matrix_layout = 
{
    MMI_VKBD_FARSI_MATRIX_X, MMI_VKBD_FARSI_MATRIX_Y,
    MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_ROW,
    MMI_VKBD_FARSI_MATRIX_WIDTH, MMI_VKBD_FARSI_MATRIX_HEIGHT,
    MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT,
    MMI_VKBD_FARSI_MATRIX_KEY_H_GAP, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_farsi_custom_key_layout[] = 
{
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 19, 19},
    
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 19, 19},
    
    {181, 62, 18, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_farsi_custom_key_layout[] = 
{
    {130, 1, 14, 14},
    {144, 1, 28, 14},
    
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},
    
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {130, 46, 14, 14},
    {144, 46, 28, 14}
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_farsi_custom_key_layout[] = 
{
    {56, 1, 9, 10},
    {144, 1, 28, 14},
    
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},
    
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {130, 46, 14, 14},
    {144, 46, 28, 14}
};


#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_farsi_layout = 
{
    MMI_VKBD_FARSI_WIDTH,
    MMI_VKBD_FARSI_HEIGHT,
    1,
    10,
    &gui_farsi_matrix_layout,
    gui_farsi_custom_key_layout,
    IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL
};

static const gui_keyboard_language_struct gui_keyboard_farsi_string = 
{
    MMI_FALSE,
    1,
    10,
    {
     {0x06F1, 0x06F2, 0x06F3, 0x06F4, 0x06F5, 0x06F6, 0x06F7, 0x06F8, 0x06F9},
     {0x0636, 0x0635, 0x062B, 0x0642, 0x0641, 0x063A, 0x0639, 0x0647, 0x062E},
     {0x0634, 0x0633, 0x06CC, 0x0628, 0x0644, 0x0627, 0x062A, 0x0646, 0x0645},
     {0x0638, 0x0637, 0x0632, 0x0631, 0x0630, 0x062F, 0x067E, 0x0648, 0x0686}
    },
    {0x06F0, '\0', 0x062D, 0x062C, '\0', 0x06A9, 0x06AF, 0x0698, '\0', '\0'},
    {0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_matrix_key_layout_struct gui_farsi_symbol_matrix_layout = 
{
    MMI_VKBD_FARSI_SYMBOL_MATRIX_X, MMI_VKBD_FARSI_SYMBOL_MATRIX_Y,
    MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW,
    MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT,
    MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT,
    MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_farsi_symbol_custom_key_layout[] = 
{
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},
    
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},

    {181, 62, 19, 19},
    {201, 62, 19, 19},
    {221, 62, 18, 19},
    
    {181, 82, 19, 19},
    {201, 82, 38, 19}
};

#else /* __MMI_MAINLCD_240X320__ */ 

static const gui_custom_key_layout_struct gui_farsi_symbol_custom_key_layout[] = 
{
    {130, 1, 14, 14},
    {144, 1, 28, 14},
    
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},
    
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},

    {130, 46, 14, 14},
    {144, 46, 14, 14},
    {158, 46, 14, 14},
    
    {130, 61, 14, 14},
    {144, 61, 28, 14}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_farsi_symbol_layout = 
{
    MMI_VKBD_FARSI_SYMBOL_WIDTH,
    MMI_VKBD_FARSI_SYMBOL_HEIGHT,
    1,
    13,
    &gui_farsi_symbol_matrix_layout,
    gui_farsi_symbol_custom_key_layout,
    IMG_VKBD_FARSI_SYMBOL
};

static const gui_keyboard_language_struct gui_keyboard_farsi_symbol_string = 
{
    MMI_FALSE,
    1,
    13,
    {
     {'@', '$', '#', 0x00F7, 0x061B, '&', '^', '_', '='},
     {'!', ',', 0x066A, 0x00D7, 0x060C, '*', '(', ')', '-'},
     {0x0652, 0x064C, 0x064D, 0x064B, 0x064F, 0x0650, 0x064E, 0x0651, '['},
     {0x0624, 0x0626, 0x064A, 0x0625, 0x0623, 0x0622, 0x0629, 0x00AB, 0x00BB},
     {0x0643, 0x0698, 0x0621, '<', '>', 0x061F, 0x066B, '.', ':'}
    },
    {'\\', '\0', '+', '|', '\0', ']', '{', '}', '"', '/', '\0', '\0', '\0'},
    {0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_ENTER, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_PERSIAN__*/

#ifdef __MMI_LANG_HUNGARIAN__
static const gui_matrix_key_layout_struct gui_hungarian_matrix_layout = 
{
    MMI_VKBD_HUNGARIAN_MATRIX_X, MMI_VKBD_HUNGARIAN_MATRIX_Y,
    MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_ROW,
    MMI_VKBD_HUNGARIAN_MATRIX_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT,
    MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT,
    MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_hungarian_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},

    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},

    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},
    
    {141, 62, 19, 19},
    {161, 62, 19, 19},
    {181, 62, 19, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_hungarian_custom_key_layout[] = 
{
    {102, 1, 14, 14},
    {116, 1, 14, 14},
    {130, 1, 14, 14},
    {144, 1, 28, 14},

    {102, 16, 14, 14},
    {116, 16, 14, 14},
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},

    {102, 31, 14, 14},
    {116, 31, 14, 14},
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {102, 46, 14, 14},
    {116, 46, 14, 14},
    {130, 46, 14, 14},
    {144, 46, 28, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_hungarian_custom_key_layout[] = 
{
    {71, 1, 9, 10},
    {81, 1, 9, 10},
    {91, 1, 10, 10},
    {102, 1, 25, 10},

    {71, 12, 9, 10},
    {81, 12, 9, 10},
    {91, 12, 10, 10},
    {102, 12, 12, 10},
    {115, 12, 12, 10},

    {71, 23, 9, 10},
    {81, 23, 9, 10},
    {91, 23, 10, 10},
    {102, 23, 12, 10},
    {115, 23, 12, 10},

    {71, 34, 9, 10},
    {81, 34, 9, 10},
    {91, 34, 10, 10},
    {102, 34, 25, 10}

};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_hungarian_layout = 
{
    MMI_VKBD_HUNGARIAN_WIDTH,
    MMI_VKBD_HUNGARIAN_HEIGHT,
    1,
    18,
    &gui_hungarian_matrix_layout,
    gui_hungarian_custom_key_layout,
    IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL
};

static const gui_keyboard_language_struct gui_keyboard_hungarian_lowercase_string = 
{
    MMI_FALSE,
    1,
    18,
    {
     {',', '.', '-', '!', '\'', ';', 0x00F6},
     {'q', 'w', 'e', 'r', 't', 'z', 'u'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm'}
    },
    {0x00FC, 0x00F3, 0x0171, '\0', 'i', 'o', 'p', 0x0151, 0x00FA, 
     'k', 'l', 0x00E9, 0x00E1, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_hungarian_uppercase_string = 
{
    MMI_FALSE,
    1,
    18,
    {
     {',', '.', '-', '!', '\'', ';', 0x00D6},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M'}
    },
    {0x00DC, 0x00D3, 0x0170, '\0', 'I', 'O', 'P', 0x0150, 0x00DA, 
     'K', 'L', 0x00C9, 0x00C1, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_HUNGARIAN__*/

#ifdef __MMI_LANG_GREEK__

static const gui_matrix_key_layout_struct gui_greek_matrix_layout = 
{
    MMI_VKBD_GREEK_MATRIX_X, MMI_VKBD_GREEK_MATRIX_Y,
    MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_ROW,
    MMI_VKBD_GREEK_MATRIX_WIDTH, MMI_VKBD_GREEK_MATRIX_HEIGHT,
    MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT,
    MMI_VKBD_GREEK_MATRIX_KEY_H_GAP, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_greek_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},

    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_greek_custom_key_layout[] = 
{
    {99, 1, 14, 14},
    {113, 1, 14, 14},
    {127, 1, 14, 14},
    {141, 1, 34, 14},
    
    {99, 16, 14, 14},
    {113, 16, 14, 14},
    {127, 16, 14, 14},
    {141, 16, 14, 14},
    {155, 16, 20, 14},

    {99, 31, 14, 14},
    {113, 31, 14, 14},
    {127, 31, 14, 14},
    {141, 31, 34, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_greek_custom_key_layout[] = 
{
    {71, 1, 10, 10},
    {82, 1, 10, 10},
    {93, 1, 10, 10},
    {104, 1, 25, 10},
    
    {71, 12, 10, 10},
    {82, 12, 10, 10},
    {93, 12, 10, 10},
    {104, 12, 11, 10},
    {116, 12, 11, 10},

    {71, 23, 10, 10},
    {82, 23, 10, 10},
    {93, 23, 10, 10},
    {104, 23, 25, 10}

};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_greek_layout = 
{
    MMI_VKBD_GREEK_WIDTH,
    MMI_VKBD_GREEK_HEIGHT,
    1,
    13,
    &gui_greek_matrix_layout,
    gui_greek_custom_key_layout,
    IMG_VKBD_GREEK
};

static const gui_keyboard_language_struct gui_keyboard_greek_lowercase_string = 
{
    MMI_TRUE,
    1,
    13,
    {
     {DIALYTIKA, 0x03C2, 0x03B5, 0x03C1, 0x03C4, 0x03C5, 0x03B8},
     {0x03B1, 0x03C3, 0x03B4, 0x03C6, 0x03B3, 0x03B7, 0x03BE},
     {0x03B6, 0x03C7, 0x03C8, 0x03C9, 0x03B2, 0x03BD, 0x03BC}
    },
    {0x03B9, 0x03BF, 0x03C0, '\0', 0x03BA, 0x03BB, GREEK_ACUTE, DIAERESIS, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_EUROSYMB, 
     IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_greek_uppercase_string = 
{
    MMI_TRUE,
    1,
    13,
    {
     {DIALYTIKA, 0x03C2, 0x0395, 0x03A1, 0x03A4, 0x03A5, 0x0398},
     {0x0391, 0x03A3, 0x0394, 0x03A6, 0x0393, 0x0397, 0x039E},
     {0x0396, 0x03A7, 0x03A8, 0x03A9, 0x0392, 0x039D, 0x039C}
    },
    {0x0399, 0x039F, 0x03C0, '\0', 0x039A, 0x039B, GREEK_ACUTE, DIAERESIS, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_EUROSYMB, 
     IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_GREEK__*/

#ifdef __MMI_LANG_BULGARIAN__

static const gui_matrix_key_layout_struct gui_bulgarian_matrix_layout = 
{
    MMI_VKBD_BULGARIAN_MATRIX_X, MMI_VKBD_BULGARIAN_MATRIX_Y,
    MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_ROW,
    MMI_VKBD_BULGARIAN_MATRIX_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_HEIGHT,
    MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT,
    MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_bulgarian_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 39, 19},
    {201, 2, 38, 19},
    
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},

    {141, 62, 19, 19},
    {161, 62, 19, 19},
    {181, 62, 19, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_bulgarian_custom_key_layout[] = 
{
    {98, 1, 14, 14},
    {112, 1, 28, 14},
    {140, 1, 36, 14},
    
    {98, 16, 14, 14},
    {112, 16, 14, 14},
    {126, 16, 14, 14},
    {140, 16, 36, 14},
    
    {98, 31, 14, 14},
    {112, 31, 14, 14},
    {126, 31, 14, 14},
    {140, 31, 14, 14},
    {154, 31, 22, 14},

    {98, 46, 14, 14},
    {112, 46, 14, 14},
    {126, 46, 14, 14},
    {140, 46, 36, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_bulgarian_custom_key_layout[] = 
{
    {71, 1, 10, 10},
    {82, 1, 22, 10},
    {105, 1, 22, 10},
    
    {71, 12, 10, 10},
    {82, 12, 11, 10},
    {94, 12, 10, 10},
    {105, 12, 22, 10},
    
    {71, 23, 10, 10},
    {82, 23, 11, 10},
    {94, 23, 10, 10},
    {105, 23, 11, 10},
    {117, 23, 10, 10},

    {71, 34, 10, 10},
    {82, 34, 11, 10},
    {94, 34, 10, 10},
    {105, 34, 22, 10}

};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_bulgarian_layout = 
{
    MMI_VKBD_BULGARIAN_WIDTH,
    MMI_VKBD_BULGARIAN_HEIGHT,
    1,
    16,
    &gui_bulgarian_matrix_layout,
    gui_bulgarian_custom_key_layout,
    IMG_VKBD_BULGARIAN
};

static const gui_keyboard_language_struct gui_keyboard_bulgarian_lowercase_string = 
{
    MMI_FALSE,
    1,
    16,
    {
     {',', ';', 0x044B, 0x00A7, 0x2116, 0x0406, 0x0056},
     {0x0443, 0x0435, 0x0438, 0x0448, 0x0449, 0x043A, 0x0441},
     {0x044C, 0x044F, 0x0430, 0x043E, 0x0436, 0x0433, 0x0442},
     {0x044E, 0x0439, 0x044A, 0x044D, 0x0444, 0x0445, 0x043F}
    },
    {'\0', '\0', '\0', 0x0434, 0x0437, 0x0446, '\0', 0x043D, 0x0432, 0x043C, 0x0447, '\0', 0x0440, 0x043B, 0x0431, '\0'},
    {IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_SYMBPICKER, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE},
    {GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_SPACE}
};

static const gui_keyboard_language_struct gui_keyboard_bulgarian_uppercase_string = 
{
    MMI_FALSE,
    1,
    16,
    {
     {',', ';', 0x044B, 0x00A7, 0x2116, 0x0406, 0x0056},
     {0x0423, 0x0415, 0x0418, 0x0428, 0x0429, 0x041A, 0x0421},
     {0x042C, 0x042F, 0x0410, 0x041E, 0x0416, 0x0413, 0x0422},
     {0x042E, 0x0419, 0x042A, 0x042D, 0x0424, 0x0425, 0x041F}
    },
    {'\0', '\0', '\0', 0x0414, 0x0417, 0x0426, '\0', 0x041D, 0x0412, 0x041C, 0x0427, '\0', 0x0420, 0x041B, 0x0411, '\0'},
    {IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_BACKSPACE, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_SYMBPICKER, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE},
    {GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I,
     GUI_VKBD_PEN_SPACE}
};

#endif /*__MMI_LANG_BULGARIAN__*/

#if (defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__))

/*Danish vk is equal to Norwegian vk*/
static const gui_matrix_key_layout_struct gui_danish_matrix_layout = 
{
    MMI_VKBD_DANISH_MATRIX_X, MMI_VKBD_DANISH_MATRIX_Y,
    MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_ROW,
    MMI_VKBD_DANISH_MATRIX_WIDTH, MMI_VKBD_DANISH_MATRIX_HEIGHT,
    MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT,
    MMI_VKBD_DANISH_MATRIX_KEY_H_GAP, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_danish_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 19, 19},
    {221, 2, 18, 19},

    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},

    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_danish_custom_key_layout[] = 
{
    {99, 1, 14, 14},
    {113, 1, 14, 14},
    {127, 1, 14, 14},
    {141, 1, 14, 14},
    {155, 1, 20, 14},

    {99, 16, 14, 14},
    {113, 16, 14, 14},
    {127, 16, 14, 14},
    {141, 16, 14, 14},
    {155, 16, 20, 14},
    
    {99, 31, 14, 14},
    {113, 31, 14, 14},
    {127, 31, 14, 14},
    {141, 31, 34, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_danish_custom_key_layout[] = 
{
    {71, 1, 10, 10},
    {82, 1, 10, 10},
    {93, 1, 10, 10},
    {104, 1, 11, 10},
    {116, 1, 11, 10},

    {71, 12, 10, 10},
    {82, 12, 10, 10},
    {93, 12, 10, 10},
    {104, 12, 11, 10},
    {116, 12, 11, 10},

    {71, 23, 10, 10},
    {82, 23, 10, 10},
    {93, 23, 10, 10},
    {104, 23, 23, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_danish_layout = 
{
    MMI_VKBD_DANISH_WIDTH,
    MMI_VKBD_DANISH_HEIGHT,
    1,
    14,
    &gui_danish_matrix_layout,
    gui_danish_custom_key_layout,
    IMG_VKBD_DANISH_NORWEGIAN
};

static const gui_keyboard_language_struct gui_keyboard_danish_lowercase_string = 
{
    MMI_FALSE,
    1,
    14,
    {
     {'q', 'w', 'e', 'r', 't', 'y', 'u'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
    },
    {'i', 'o', 'p', 0x00E5, '\0', 'k', 'l', 0x00E6, 0x00F8, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE_SMALL, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_danish_uppercase_string = 
{
    MMI_FALSE,
    1,
    14,
    {
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
    },
    {'I', 'O', 'P', 0x00C5, '\0', 'K', 'L', 0x00C6, 0x00D8, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE_SMALL, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*(defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__))*/

#if (defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SWEDISH__))

/*Finnish vk is equal to Swedish vk*/
static const gui_matrix_key_layout_struct gui_finnish_matrix_layout = 
{
    MMI_VKBD_FINNISH_MATRIX_X, MMI_VKBD_FINNISH_MATRIX_Y,
    MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_ROW,
    MMI_VKBD_FINNISH_MATRIX_WIDTH, MMI_VKBD_FINNISH_MATRIX_HEIGHT,
    MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT,
    MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_finnish_custom_key_layout[] = 
{
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},

    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},

    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_finnish_custom_key_layout[] = 
{
    {113, 1, 14, 14},
    {127, 1, 14, 14},
    {141, 1, 34, 14},

    {113, 16, 14, 14},
    {127, 16, 14, 14},
    {141, 16, 14, 14},
    {155, 16, 20, 14},
    
    {113, 31, 14, 14},
    {127, 31, 14, 14},
    {141, 31, 14, 14},
    {155, 31, 20, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_finnish_custom_key_layout[] = 
{
    {81, 1, 10, 10},
    {92, 1, 10, 10},
    {103, 1, 24, 10},

    {81, 12, 10, 10},
    {92, 12, 10, 10},
    {103, 12, 11, 10},
    {115, 12, 12, 10},
    
    {81, 23, 10, 10},
    {92, 23, 10, 10},
    {103, 23, 11, 10},
    {115, 23, 12, 10}

};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_finnish_layout = 
{
    MMI_VKBD_FINNISH_WIDTH,
    MMI_VKBD_FINNISH_HEIGHT,
    1,
    11,
    &gui_finnish_matrix_layout,
    gui_finnish_custom_key_layout,
    IMG_VKBD_FINNISH_SWEDISH
};

static const gui_keyboard_language_struct gui_keyboard_finnish_lowercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k'},
     {'z', 'x', 'c', 'v', 'b', 'n', 'm', 0x00E5}
    },
    {'o', 'p', '\0', 'l', 0x00F6, 0x00E4, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_finnish_uppercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K'},
     {'Z', 'X', 'C', 'V', 'B', 'N', 'M', 0x00C5}
    },
    {'O', 'P', '\0', 'L', 0x00D6, 0x00C4, '\0', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*(defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SWEDISH__))*/

#if (defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__))
/*Croatian vk is equal to Slovenian*/
static const gui_keyboard_language_struct gui_keyboard_croatian_lowercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {'!', ':', '.', CEDILLA, DIAERESIS, 0x010D, 0x0107, 0x0161},
     {'q', 'w', 'e', 'r', 't', 'z', 'u', 'i'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm', ','}
    },
    {0x0111, 0x017E, '\0', 'o', 'p', '\0', 'l', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_croatian_uppercase_string = 
{
    MMI_TRUE,
    1,
    11,
    {
     {'!', ':', '.', CEDILLA, DIAERESIS, 0x010C, 0x0106, 0x0160},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M', ','}
    },
    {0x0110, 0x017D, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0'},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*(defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__))*/

#ifdef __MMI_LANG_POLISH__

static const gui_matrix_key_layout_struct gui_polish_matrix_layout = 
{
    MMI_VKBD_POLISH_MATRIX_X, MMI_VKBD_POLISH_MATRIX_Y,
    MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_ROW,
    MMI_VKBD_POLISH_MATRIX_WIDTH, MMI_VKBD_POLISH_MATRIX_HEIGHT,
    MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT,
    MMI_VKBD_POLISH_MATRIX_KEY_H_GAP, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_polish_custom_key_layout[] = 
{
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19},
    {141, 62, 19, 19},
    {161, 62, 39, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) /* __MMI_MAINLCD_176X220__ */

static const gui_custom_key_layout_struct gui_polish_custom_key_layout[] = 
{
    {106, 1, 14, 14},
    {121, 1, 14, 14},
    {136, 1, 14, 14},
    {151, 1, 24, 14},
    {106, 16, 14, 14},
    {121, 16, 14, 14},
    {136, 16, 14, 14},
    {151, 16, 24, 14},
    {106, 31, 14, 14},
    {121, 31, 14, 14},
    {136, 31, 14, 14},
    {151, 31, 24, 14},
    {106, 46, 14, 14},
    {121, 46, 29, 14},
    {151, 46, 24, 14}
};

#else /* __MMI_MAINLCD_128X160__ */ 

static const gui_custom_key_layout_struct gui_polish_custom_key_layout[] = 
{
    {78, 1, 10, 10},
    {89, 1, 10, 10},
    {100, 1, 10, 10},
    {111, 1, 16, 10},
        
    {78, 12, 10, 10},
    {89, 12, 10, 10},
    {100, 12, 10, 10},
    {111, 12, 16, 10},

    {78, 23, 10, 10},
    {89, 23, 10, 10},
    {100, 23, 10, 10},
    {111, 23, 16, 10},

    {78, 34, 10, 10},
    {89, 34, 21, 10},
    {111, 34, 16, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 


static const gui_keyboard_layout_struct gui_virtual_keyboard_polish_layout = 
{
    MMI_VKBD_POLISH_WIDTH,
    MMI_VKBD_POLISH_HEIGHT,
    1,
    15,
    &gui_polish_matrix_layout,
    gui_polish_custom_key_layout,
    IMG_VKBD_EXTENDED
};

static const gui_keyboard_language_struct gui_keyboard_polish_lowercase_string = 
{
    MMI_TRUE,
    1,
    15,
    {
     {OGONEK, 0x017B, 0x0105, 0x0119, 0x0144, 0x0107, 0x017A},
     {'q', 'w', 'e', 'r', 't', 'z', 'u'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm'}
    },
    {0x00F3, 0x017C, 0x015B, '\0', 'i', 'o', 'p', '\0', 'k', 'l', 0x0142, '\0', '\0', '\0', '\0',},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_EUROSYMB, 
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_polish_uppercase_string = 
{
    MMI_TRUE,
    1,
    15,
    {
     {OGONEK, 0x017B, 0x0105, 0x0119, 0x0144, 0x0107, 0x017A},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M'}
    },
    {0x00F3, 0x017C, 0x015B, '\0', 'I', 'O', 'P', '\0', 'K', 'L', 0x0141, '\0', '\0', '\0', '\0',},
    {0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_EUROSYMB, 
     IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK,
     GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_POLISH__*/

#ifdef __MMI_LANG_ROMANIAN__

static const gui_keyboard_language_struct gui_keyboard_romanian_lowercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {':', '%', '&', '!', '.', 0x0103, 0x00EE, 0x00E2},
     {'q', 'w', 'e', 'r', 't', 'z', 'u', 'i'},
     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k'},
     {'y', 'x', 'c', 'v', 'b', 'n', 'm', ','}
    },
    {0x015F, 0x0163,  '\0', 'o', 'p', '\0',  'l', '\0', '\0', '\0', '\0',},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
      0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
      IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
      GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
      GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
      GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_romanian_uppercase_string = 
{
    MMI_FALSE,
    1,
    11,
    {
     {':', '%', '&', '!', '.', 0x0102, 0x00CE, 0x00C2},
     {'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I'},
     {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K'},
     {'Y', 'X', 'C', 'V', 'B', 'N', 'M', ','}
    },
    {0x015E, 0x0162, '\0', 'O', 'P', '\0', 'L', '\0', '\0', '\0', '\0',},
    {0, 0, IMG_VKBD_CUSTOM_HIDE, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
      0, IMG_VKBD_CUSTOM_EUROSYMB, IMG_VKBD_CUSTOM_CAPSLOCK,
      IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE,
      GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
      GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_EUROSYMB, GUI_VKBD_PEN_CAPSLOCK,
      GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};
#endif /*__MMI_LANG_ROMANIAN__*/
//Liu Jun add end

#ifdef __MMI_LANG_VIETNAMESE__

static const gui_matrix_key_layout_struct gui_vietnamese_matrix_layout = 
{
    MMI_VKBD_VIETNAMESE_MATRIX_X, MMI_VKBD_VIETNAMESE_MATRIX_Y,
    MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_ROW,
    MMI_VKBD_VIETNAMESE_MATRIX_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT,
    MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT,
    MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_vietnamese_custom_key_layout[] = 
{
    {101, 2, 19, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {101, 22, 19, 19},
    {121, 22, 19, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    
    {101, 42, 19, 19},
    {121, 42, 19, 19},
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 38, 19},
    
    {101, 62, 19, 19},
    {121, 62, 19, 19},
    {141, 62, 19, 19},
    {161, 62, 19, 19},
    {181, 62, 19, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_vietnamese_custom_key_layout[] = 
{
    {70, 1, 14, 14},
    {84, 1, 14, 14},
    {98, 1, 14, 14},
    {112, 1, 14, 14},
    {126, 1, 14, 14},
    {140, 1, 36, 14},
    
    {70, 16, 14, 14},
    {84, 16, 14, 14},
    {98, 16, 14, 14},
    {112, 16, 14, 14},
    {126, 16, 14, 14},
    {140, 16, 36, 14},
    
    {70, 31, 14, 14},
    {84, 31, 14, 14},
    {98, 31, 14, 14},
    {112, 31, 14, 14},
    {126, 31, 14, 14},
    {140, 31, 36, 14},
    
    {70, 46, 14, 14},
    {84, 46, 14, 14},
    {98, 46, 14, 14},
    {112, 46, 14, 14},
    {126, 46, 14, 14},
    {140, 46, 36, 14}
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_vietnamese_custom_key_layout[] = 
{
    {56, 1, 9, 10},
    {66, 1, 9, 10},
    {76, 1, 9, 10},
    {86, 1, 9, 10},
    {96, 1, 9, 10},
    {106, 1, 21, 10},
    
    {56, 12, 9, 10},
    {66, 12, 9, 10},
    {76, 12, 9, 10},
    {86, 12, 9, 10},
    {96, 12, 9, 10},
    {106, 12, 21, 10},
    
    {56, 23, 9, 10},
    {66, 23, 9, 10},
    {76, 23, 9, 10},
    {86, 23, 9, 10},
    {96, 23, 9, 10},
    {106, 23, 21, 10},
    
    {56, 34, 9, 10},
    {66, 34, 9, 10},
    {76, 34, 9, 10},
    {86, 34, 9, 10},
    {96, 34, 9, 10},
    {106, 34, 21, 10}
};


#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_vietnamese_layout = 
{
    MMI_VKBD_VIETNAMESE_WIDTH,
    MMI_VKBD_VIETNAMESE_HEIGHT,
    1,
    24,
    &gui_vietnamese_matrix_layout,
    gui_vietnamese_custom_key_layout,
    IMG_VKBD_VIETNAMESE
};

static const gui_keyboard_language_struct gui_keyboard_vietnamese_lowercase_string = 
{
    MMI_FALSE,
    1,
    24,
    {
     {0x0300, 0x0301, 0x0309, 0x0303, 0x0323}, 
     {'q', 'd', 'e', 'r', 't'}, 
     {'a', 's', 0x0111, 'f', 'g'}, 
     {'o', 'x', 'c', 'v', 'b'} 
    },
    {'-', 0x00E2, 0x0103, 0x00EA, 0x00F4, '\0', 
     'y', 'u', 'k', 0x01B0, 'z', '\0', 
     'h', 'j', 'l', 0x01A1, 'w', '\0', 
     'm', 'i', 'p', 'n', '\0', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_vietnamese_uppercase_string = 
{
    MMI_FALSE,
    1,
    24,
    {
     {0x0300, 0x0301, 0x0309, 0x0303, 0x0323}, 
     {'Q', 'D', 'E', 'R', 'T'}, 
     {'A', 'S', 0x0110, 'F', 'G'}, 
     {'O', 'X', 'C', 'V', 'B'}, 
    },
    {'-', 0x00C2, 0x0102, 0x00CA, 0x00D4, '\0', 
     'Y', 'U', 'K', 0x01AF, 'Z', '\0', 
     'H', 'J', 'L', 0x01A0, 'W', '\0', 
     'M', 'I', 'P', 'N', '\0', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_VIETNAMESE__*/

#ifdef __MMI_LANG_ARABIC__

static const gui_matrix_key_layout_struct gui_arabic_matrix_layout = 
{
    MMI_VKBD_ARABIC_MATRIX_X, MMI_VKBD_ARABIC_MATRIX_Y,
    MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_ROW,
    MMI_VKBD_ARABIC_MATRIX_WIDTH, MMI_VKBD_ARABIC_MATRIX_HEIGHT,
    MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT,
    MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__


static const gui_custom_key_layout_struct gui_arabic_custom_key_layout[] = 
{
    {101, 2, 19, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {101, 22, 19, 19},
    {121, 22, 19, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 18, 19},
    
    {101, 42, 19, 19},
    {121, 42, 19, 19},
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},
    
    {101, 62, 19, 19},
    {121, 62, 19, 19},
    {141, 62, 19, 19},
    {161, 62, 19, 19},
    {181, 62, 19, 19},
    {201, 62, 19, 19},
    {221, 62, 18, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) 

static const gui_custom_key_layout_struct gui_arabic_custom_key_layout[] = 
{
    {71, 1, 14, 14},
    {85, 1, 14, 14},
    {99, 1, 14, 14},
    {113, 1, 14, 14},
    {127, 1, 14, 14},
    {141, 1, 34, 14},
    
    {71, 16, 14, 14},
    {85, 16, 14, 14},
    {99, 16, 14, 14},
    {113, 16, 14, 14},
    {127, 16, 14, 14},
    {141, 16, 14, 14},
    {155, 16, 20, 14},
    
    {71, 31, 14, 14},
    {85, 31, 14, 14},
    {99, 31, 14, 14},
    {113, 31, 14, 14},
    {127, 31, 14, 14},
    {141, 31, 14, 14},
    {155, 31, 20, 14},
    
    {71, 46, 14, 14},
    {85, 46, 14, 14},
    {99, 46, 14, 14},
    {113, 46, 14, 14},
    {127, 46, 14, 14},
    {141, 46, 14, 14},
    {155, 46, 20, 14}
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_arabic_custom_key_layout[] = 
{
    {56, 1, 9, 10},
    {66, 1, 9, 10},
    {76, 1, 9, 10},
    {86, 1, 9, 10},
    {96, 1, 9, 10},
    {106, 1, 21, 10},

    {56, 12, 9, 10},
    {66, 12, 9, 10},
    {76, 12, 9, 10},
    {86, 12, 9, 10},
    {96, 12, 9, 10},
    {106, 12, 10, 10},
    {117, 12, 10, 10},
    
    {56, 23, 9, 10},
    {66, 23, 9, 10},
    {76, 23, 9, 10},
    {86, 23, 9, 10},
    {96, 23, 9, 10},
    {106, 23, 10, 10},
    {117, 23, 10, 10},
    
    {56, 34, 9, 10},
    {66, 34, 9, 10},
    {76, 34, 9, 10},
    {86, 34, 9, 10},
    {96, 34, 9, 10},
    {106, 34, 10, 10},
    {117, 34, 10, 10}
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_arabic_layout = 
{
    MMI_VKBD_ARABIC_WIDTH,
    MMI_VKBD_ARABIC_HEIGHT,
    1,
    27,
    &gui_arabic_matrix_layout,
    gui_arabic_custom_key_layout,
    IMG_VKBD_ARABIC
};

#if 0
static const gui_keyboard_language_struct gui_keyboard_arabic_string = 
{
    MMI_FALSE,
    1,
    27,
    {
     {0x0661, 0x0662, 0x0663, 0x0664, 0x0665}, 
     {0x0636, 0x0635, 0x062B, 0x0642, 0x0641}, 
     {0x0634, 0x0633, 0x064A, 0x0628, 0x0644}, 
     {0x0626, 0x0621, 0x0624, 0x0631, 0x0649}
    },
    {0x0666, 0x0667, 0x0668, 0x0669, 0x0660, '\0', 
     0x063A, 0x0639, 0x0647, 0x062E, 0x062D, 0x062C, '\0', 
     0x0627, 0x062A, 0x0646, 0x0645, 0x0643, 0x0637, '\0', 
     0x0629, 0x0648, 0x0632, 0x0630, 0x062F, 0x0638, '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_SYMBPICKER, 
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SYMBPICKER, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE}
};
#else
static const gui_keyboard_language_struct gui_keyboard_arabic_string =
{
	MMI_FALSE,
	1,
	11,
	{
		{0x636, 0x635, 0x62B, 0x642, 0x641, 0x63A, 0x639, 0x647 ,'\0' },
		{0x634, 0x633, 0x64A, 0x628, 0x644, 0x627, 0x62A, 0x646 ,'\0' },
		{0x626, 0x621, 0x624, 0x631, 0x649, 0x629, 0x648, 0x632 ,'\0' },
		{0x62C, 0x62F, 0x630, 0x60C, 0x61F, 0x61B, 0x622, '.'       ,'\0' },
	},
	{0x62E,0x62D,'\0',0x645,0x643,'\0',0x637,0x638,'\0', '\0', '\0'},
	{0,0,IMG_VKBD_CUSTOM_HIDE,0,0,IMG_VKBD_CUSTOM_BACKSPACE,
	 0, 0, IMG_VKBD_CUSTOM_ENTER, 
	 IMG_VKBD_CUSTOM_SPACE,IMG_VKBD_CUSTOM_SYMBPICKER},
	{GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_HIDE, 
	 GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_BAKSPACE,
	 GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_CHAR_I,GUI_VKBD_PEN_NEWLINE,
	 GUI_VKBD_PEN_SPACE,GUI_VKBD_PEN_SYMBPICKER}
};
#endif

static const gui_matrix_key_layout_struct gui_arabic_symbol_matrix_layout = 
{
    MMI_VKBD_ARABIC_SYMBOL_MATRIX_X, MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y,
    MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW,
    MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT,
    MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT,
    MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__

static const gui_custom_key_layout_struct gui_arabic_symbol_custom_key_layout[] = 
{
    {101, 2, 19, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {101, 22, 19, 19},
    {121, 22, 19, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 19, 19},
    {221, 22, 19, 19},
    
    {101, 42, 19, 19},
    {121, 42, 19, 19},
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 19, 19},
    
    {101, 62, 18, 19},
    {121, 62, 18, 19},
    {141, 62, 18, 19},
    {161, 62, 18, 19},
    {181, 62, 18, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__) 

static const gui_custom_key_layout_struct gui_arabic_symbol_custom_key_layout[] = 
{
    {74, 1, 14, 14},
    {88, 1, 14, 14},
    {102, 1, 14, 14},
    {116, 1, 14, 14},
    {130, 1, 14, 14},
    {144, 1, 28, 14},
    
    {74, 16, 14, 14},
    {88, 16, 14, 14},
    {102, 16, 14, 14},
    {116, 16, 14, 14},
    {130, 16, 14, 14},
    {144, 16, 14, 14},
    {158, 16, 14, 14},
    
    {74, 31, 14, 14},
    {88, 31, 14, 14},
    {102, 31, 14, 14},
    {116, 31, 14, 14},
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {74, 46, 14, 14},
    {88, 46, 14, 14},
    {102, 46, 14, 14},
    {116, 46, 14, 14},
    {130, 46, 14, 14},
    {144, 46, 28, 14}
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_arabic_symbol_custom_key_layout[] = 
{
    {56, 1, 9, 10},
    {66, 1, 9, 10},
    {76, 1, 9, 10},
    {86, 1, 9, 10},
    {96, 1, 9, 10},
    {106, 1, 21, 10},
    
    {56, 12, 9, 10},
    {66, 12, 9, 10},
    {76, 12, 9, 10},
    {86, 12, 9, 10},
    {96, 12, 9, 10},
    {106, 12, 10, 10},
    {117, 12, 10, 10},
    
    {56, 23, 9, 10},
    {66, 23, 9, 10},
    {76, 23, 9, 10},
    {86, 23, 9, 10},
    {96, 23, 9, 10},
    {106, 23, 10, 10},
    {117, 23, 10, 10},
    
    {56, 34, 9, 10},
    {66, 34, 9, 10},
    {76, 34, 9, 10},
    {86, 34, 9, 10},
    {96, 34, 9, 10},
    {106, 34, 21, 10}
};


#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_arabic_symbol_layout = 
{
    MMI_VKBD_ARABIC_SYMBOL_WIDTH,
    MMI_VKBD_ARABIC_SYMBOL_HEIGHT,
    1,
    26,
    &gui_arabic_symbol_matrix_layout,
    gui_arabic_symbol_custom_key_layout,
    IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL
};

static const gui_keyboard_language_struct gui_keyboard_arabic_symbol_string = 
{
    MMI_FALSE,
    1,
    26,
    {
     {'.', 0x060C, 0x061F, '!', ';'}, 
     {'+', '-', '=', '%', '_'}, 
     {'(', ')', '[', ']', '{'}, 
     {0x00A3, 0x20AC, '$', 0x00A5, 0x00A4}, 
    },
    {':', '"', '\'', '?', '@', '\0', 
     '*', '#', '~', '^', 0x0A1, 0x00BF, '\0', 
     '}', '\\', '/', '<', '>', '|', '\0', 
     '&', 0x00A7, 0x0622, 0x0625, '\0', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE, 
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE, 
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_ENTER, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_NEWLINE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_ARABIC__*/

#ifdef __MMI_LANG_THAI__

static const gui_matrix_key_layout_struct gui_thai_matrix_layout = 
{
    MMI_VKBD_THAI_MATRIX_X, MMI_VKBD_THAI_MATRIX_Y,
    MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_ROW,
    MMI_VKBD_THAI_MATRIX_WIDTH, MMI_VKBD_THAI_MATRIX_HEIGHT,
    MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT,
    MMI_VKBD_THAI_MATRIX_KEY_H_GAP, MMI_VKBD_THAI_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__


static const gui_custom_key_layout_struct gui_thai_custom_key_layout[] = 
{
    {201, 2, 19, 19},
    {221, 2, 18, 19},
    
    {201, 22, 19, 19},
    {221, 22, 18, 19},
    
    {201, 42, 19, 19},
    {221, 42, 18, 19},
    
    {201, 62, 19, 19},
    {221, 62, 18, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_thai_custom_key_layout[] = 
{
    {141, 1, 14, 14},
    {154, 1, 22, 14},
    
    {141, 16, 14, 14},
    {154, 16, 22, 14},
    
    {141, 31, 14, 14},
    {154, 31, 22, 14},
    
    {141, 46, 14, 14},
    {154, 46, 22, 14}
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_thai_custom_key_layout[] = 
{
    {101, 1, 9, 10},
    {111, 1, 16, 10},
    
    {101, 12, 9, 10},
    {111, 12, 16, 10},
    
    {101, 23, 9, 10},
    {111, 23, 16, 10},
    
    {101, 34, 9, 10},
    {111, 34, 16, 10},
};


#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_thai_layout = 
{
    MMI_VKBD_THAI_WIDTH,
    MMI_VKBD_THAI_HEIGHT,
    1,
    8,
    &gui_thai_matrix_layout,
    gui_thai_custom_key_layout,
    IMG_VKBD_THAI
};

static const gui_keyboard_language_struct gui_keyboard_thai_string = 
{
    MMI_FALSE,
    1,
    8,
    {
     {0x0E45, 0x0E0A, 0x0E25, 0x0E20, 0x0E16, 0x0E38, 0x0E36, 0x0E04, 0x0E15, 0x0E08},
     {0x0E46, 0x0E44, 0x0E33, 0x0E1E, 0x0E30, 0x0E31, 0x0E35, 0x0E23, 0x0E19, 0x0E22},
     {0x0E1F, 0x0E2B, 0x0E01, 0x0E14, 0x0E40, 0x0E49, 0x0E48, 0x0E32, 0x0E2A, 0x0E27},
     {0x0E1C, 0x0E1B, 0x0E41, 0x0E2D, 0x0E34, 0x0E37, 0x0E17, 0x0E21, 0x0E43, 0x0E1D}
    },
    {0x0E02, '\0', 0x0E1A, '\0', 0x0E07, '\0', '\0', '\0'},
    {0, IMG_VKBD_CUSTOM_HIDE_SMALL, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_thai_symbol_string = 
{
    MMI_FALSE,
    1,
    8,
    {
     {0x0E59, 0x0E51, 0x0E52, 0x0E53, 0x0E54, 0x0E39, ',', 0x0E55, 0x0E56, 0x0E57},
     {0x0E50, 0x0E03, 0x0E0E, 0x0E11, 0x0E18, 0x0E4D, 0x0E4A, 0x0E13, 0x0E2F, 0x0E0D},
     {0x0E24, 0x0E06, 0x0E0F, 0x0E42, 0x0E0C, 0x0E47, 0x0E4B, 0x0E29, 0x0E28, 0x0E0B},
     {'(', ')', 0x0E09, 0x0E2E, 0x0E3A, 0x0E4C, 0x0E05, 0x0E12, 0x0E2C, 0x0E26}
    },
    {0x0E58, '\0', 0x0E10, '\0', '.', '\0', '\0', '\0'},
    {0, IMG_VKBD_CUSTOM_HIDE_SMALL, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, IMG_VKBD_CUSTOM_CAPSLOCK, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};


#endif /*__MMI_LANG_THAI__*/

#ifdef __MMI_LANG_UKRAINIAN__

static const gui_matrix_key_layout_struct gui_ukrainian_matrix_layout = 
{
    MMI_VKBD_UKRAINIAN_MATRIX_X, MMI_VKBD_UKRAINIAN_MATRIX_Y,
    MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_ROW,
    MMI_VKBD_UKRAINIAN_MATRIX_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT,
    MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT,
    MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP
};

#ifdef __MMI_MAINLCD_240X320__


static const gui_custom_key_layout_struct gui_ukrainian_custom_key_layout[] = 
{
    {101, 2, 19, 19},
    {121, 2, 19, 19},
    {141, 2, 19, 19},
    {161, 2, 19, 19},
    {181, 2, 19, 19},
    {201, 2, 38, 19},
    
    {101, 22, 19, 19},
    {121, 22, 19, 19},
    {141, 22, 19, 19},
    {161, 22, 19, 19},
    {181, 22, 19, 19},
    {201, 22, 38, 19},
    
    {101, 42, 19, 19},
    {121, 42, 19, 19},
    {141, 42, 19, 19},
    {161, 42, 19, 19},
    {181, 42, 19, 19},
    {201, 42, 19, 19},
    {221, 42, 18, 19},
    
    {101, 62, 19, 19},
    {121, 62, 19, 19},
    {141, 62, 19, 19},
    {161, 62, 19, 19},
    {181, 62, 19, 19},
    {201, 62, 38, 19}
};

#elif defined(__MMI_MAINLCD_176X220__)

static const gui_custom_key_layout_struct gui_ukrainian_custom_key_layout[] = 
{
    {74, 1, 14, 14},
    {88, 1, 14, 14},
    {102, 1, 14, 14},
    {116, 1, 14, 14},
    {130, 1, 14, 14},
    {144, 1, 28, 14},
    
    {74, 16, 14, 14},
    {88, 16, 14, 14},
    {102, 16, 14, 14},
    {116, 16, 14, 14},
    {130, 16, 14, 14},
    {144, 16, 28, 14},
    
    {74, 31, 14, 14},
    {88, 31, 14, 14},
    {102, 31, 14, 14},
    {116, 31, 14, 14},
    {130, 31, 14, 14},
    {144, 31, 14, 14},
    {158, 31, 14, 14},
    
    {74, 46, 14, 14},
    {88, 46, 14, 14},
    {102, 46, 14, 14},
    {116, 46, 14, 14},
    {130, 46, 14, 14},
    {144, 46, 28, 14},
};

#else /* __MMI_MAINLCD_128X160__ */

static const gui_custom_key_layout_struct gui_ukrainian_custom_key_layout[] = 
{
    {56, 1, 9, 10},
    {66, 1, 9, 10},
    {76, 1, 9, 10},
    {86, 1, 9, 10},
    {96, 1, 9, 10},
    {106, 1, 21, 10},
    
    {56, 12, 9, 10},
    {66, 12, 9, 10},
    {76, 12, 9, 10},
    {86, 12, 9, 10},
    {96, 12, 9, 10},
    {106, 12, 21, 10},
    
    {56, 23, 9, 10},
    {66, 23, 9, 10},
    {76, 23, 9, 10},
    {86, 23, 9, 10},
    {96, 23, 9, 10},
    {106, 23, 10, 10},
    {117, 23, 10, 10},
    
    {56, 34, 9, 10},
    {66, 34, 9, 10},
    {76, 34, 9, 10},
    {86, 34, 9, 10},
    {96, 34, 9, 10},
    {106, 34, 21, 10},
};

#endif /* __MMI_MAINLCD_240X320__ */ 

static const gui_keyboard_layout_struct gui_virtual_keyboard_ukrainian_layout = 
{
    MMI_VKBD_UKRAINIAN_WIDTH,
    MMI_VKBD_UKRAINIAN_HEIGHT,
    1,
    25,
    &gui_ukrainian_matrix_layout,
    gui_ukrainian_custom_key_layout,
    IMG_VKBD_UKRAINIAN
};

static const gui_keyboard_language_struct gui_keyboard_ukrainian_lowercase_string = 
{
    MMI_FALSE,
    1,
    25,
    {
     {0x0451, ',', '.', '!', 0x2116},
     {0x0439, 0x0446, 0x0443, 0x043A, 0x435},
     {0x0444, 0x0456, 0x0432, 0x0430, 0x43F},
     {0x044F, 0x0447, 0x0441, 0x043C, 0x438}
    },
    {';', ':', '?', 0x0445, 0x0457, '\0', 
     0x043D, 0x0433, 0x0448, 0x0449, 0x0437, '\0',
     0x0440, 0x043E, 0x043B, 0x0434, 0x0436, 0x0454, '\0',
     0x0442, 0x044C, 0x0431, 0x044E, '\0', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE_SMALL, 
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

static const gui_keyboard_language_struct gui_keyboard_ukrainian_uppercase_string = 
{
    MMI_FALSE,
    1,
    8,
    {
     {0x0401, ',', '.', '!', 0x2116},
     {0x0419, 0x0426, 0x0423, 0x041A, 0x415},
     {0x0424, 0x0406, 0x0412, 0x0410, 0x41F},
     {0x042F, 0x0427, 0x0421, 0x041C, 0x418}
    },
    {';', ':', '?', 0x0425, 0x0407, '\0', 
     0x041D, 0x0413, 0x0428, 0x0429, 0x0417, '\0',
     0x0420, 0x041E, 0x041B, 0x0414, 0x0416, 0x0404, '\0',
     0x0422, 0x042C, 0x0411, 0x042E, '\0', '\0'},
    {0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_HIDE_SMALL, 
     0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_BACKSPACE,
     0, 0, 0, 0, 0, 0, IMG_VKBD_CUSTOM_CAPSLOCK, 
     0, 0, 0, 0, IMG_VKBD_CUSTOM_SPACE, IMG_VKBD_CUSTOM_SYMBPICKER},
    {GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_HIDE, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_BAKSPACE,
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CAPSLOCK, 
     GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_CHAR_I, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_SYMBPICKER}
};

#endif /*__MMI_LANG_UKRAINIAN__*/

/****************************
 * Language table
 ****************************/

/* The order should be the same as gui_virtual_keyboard_language_enum */
const gui_keyboard_lang_map_struct MMI_virtual_keyboard_language_map[GUI_VIRTUAL_KEYBOARD_MAX_LANG] = 
{
    {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_lowercase_string},
    {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_uppercase_string},
    {&gui_virtual_keyboard_extended_layout, &gui_keyboard_symbol_string},
    {&gui_virtual_keyboard_tray_layout, &gui_keyboard_tray_string},
    {&gui_virtual_keyboard_number_layout, &gui_keyboard_number_string},
    {&gui_virtual_keyboard_number_layout, &gui_keyboard_phone_number_string},
    {&gui_virtual_keyboard_tray_layout, &gui_keyboard_empty_tray_string},
    {&gui_virtual_keyboard_tray_layout, &gui_keyboard_number_tray_string},
    {&gui_virtual_keyboard_tray_layout, &gui_keyboard_number_dot_tray_string}
    /* MTK Terry Temp Solution for Custom Release */
    // #ifdef __MMI_LANG_SM_CHINESE__
    , {&gui_virtual_keyboard_pinyin_layout, &gui_keyboard_pinyin_string}
    //#endif
    //#ifdef __MMI_LANG_TR_CHINESE__
    , {&gui_virtual_keyboard_bopomo_layout, &gui_keyboard_bopomo_string}
    //#endif
    //#if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__)
    , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_chinese_symbol_string}
    // #endif
    /* Asia-pacific */
#ifdef __MMI_LANG_THAI__
#if 1
    //Huyanwei Modify it //defined(LANG_TH_SUPPORT)
    , {&gui_virtual_keyboard_thai_layout, &gui_keyboard_thai_string}
    , {&gui_virtual_keyboard_thai_layout, &gui_keyboard_thai_symbol_string}
#else
    ,{&gui_virtual_keyboard_number_layout, &gui_keyboard_number_string}
    ,{&gui_virtual_keyboard_extended_layout, &gui_keyboard_symbol_string}
#endif
#endif 
#ifdef __MMI_LANG_INDONESIAN__
    , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_lowercase_string}
    , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_uppercase_string}
#endif 
#ifdef __MMI_LANG_MALAY__
    , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_lowercase_string}
    , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_uppercase_string}
#endif 
#ifdef __MMI_LANG_VIETNAMESE__
    , {&gui_virtual_keyboard_vietnamese_layout, &gui_keyboard_vietnamese_lowercase_string}
    , {&gui_virtual_keyboard_vietnamese_layout, &gui_keyboard_vietnamese_uppercase_string}
#endif 
    /* Hindi */
#ifdef __MMI_LANG_HINDI__
#endif 
    /* Arabic */
#ifdef __MMI_LANG_ARABIC__
    //, {&gui_virtual_keyboard_arabic_layout, &gui_keyboard_arabic_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_arabic_string}
    , {&gui_virtual_keyboard_arabic_symbol_layout, &gui_keyboard_arabic_symbol_string}
#endif 
    /* Europe */
#ifdef __MMI_LANG_SPANISH__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_spanish_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_spanish_uppercase_string}
#endif /* __MMI_LANG_SPANISH__ */ 
#ifdef __MMI_LANG_FRENCH__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_french_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_french_uppercase_string}
#endif /* __MMI_LANG_FRENCH__ */ 
#ifdef __MMI_LANG_GERMAN__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_german_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_german_uppercase_string}
#endif /* __MMI_LANG_GERMAN__ */ 
#ifdef __MMI_LANG_ITALIAN__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_italian_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_italian_uppercase_string}
#endif /* __MMI_LANG_ITALIAN__ */ 
#ifdef __MMI_LANG_RUSSIAN__
    //, {&gui_virtual_keyboard_extended_layout, &gui_keyboard_russian_lowercase_string}
    //, {&gui_virtual_keyboard_extended_layout, &gui_keyboard_russian_uppercase_string}
     ,{&gui_virtual_keyboard_extended_layout, &gui_keyboard_symbol_string}
     ,{&gui_virtual_keyboard_extended_layout, &gui_keyboard_symbol_string}
#endif /* __MMI_LANG_RUSSIAN__ */ 
#ifdef __MMI_LANG_TURKISH__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_turkish_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_turkish_uppercase_string}
#endif /* __MMI_LANG_TURKISH__ */ 
#ifdef __MMI_LANG_PORTUGUESE__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_portuguese_lowercase_string}
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_portuguese_uppercase_string}
#endif /* __MMI_LANG_PORTUGUESE__ */ 
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
    , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_european_symbols_string}
#endif 
//Liu Jun add 20070319
#ifdef __MMI_LANG_CZECH__
    , {&gui_virtual_keyboard_czech_layout, &gui_keyboard_czech_lowercase_string}
    , {&gui_virtual_keyboard_czech_layout, &gui_keyboard_czech_uppercase_string}
#endif /* __MMI_LANG_CZECH__ */

#ifdef __MMI_LANG_HEBREW__
    , {&gui_virtual_keyboard_hebrew_layout, &gui_keyboard_hebrew_string}
#endif /* __MMI_LANG_HEBREW__ */

#ifdef __MMI_LANG_PERSIAN__
//     , {&gui_virtual_keyboard_farsi_layout, &gui_keyboard_farsi_string}
 //    , {&gui_virtual_keyboard_farsi_symbol_layout, &gui_keyboard_farsi_symbol_string}
     ,{&gui_virtual_keyboard_tray_layout, &gui_keyboard_tray_string}
     ,{&gui_virtual_keyboard_extended_layout, &gui_keyboard_symbol_string}
#endif /*__MMI_LANG_PERSIAN__*/

#ifdef __MMI_LANG_GREEK__
     , {&gui_virtual_keyboard_greek_layout, &gui_keyboard_greek_lowercase_string}
     , {&gui_virtual_keyboard_greek_layout, &gui_keyboard_greek_uppercase_string}
#endif /*__MMI_LANG_GREEK__*/

#ifdef __MMI_LANG_BULGARIAN__
     , {&gui_virtual_keyboard_bulgarian_layout, &gui_keyboard_bulgarian_lowercase_string}
     , {&gui_virtual_keyboard_bulgarian_layout, &gui_keyboard_bulgarian_uppercase_string}
#endif /*__MMI_LANG_BULGARIAN__*/

#ifdef __MMI_LANG_DANISH__
     , {&gui_virtual_keyboard_danish_layout, &gui_keyboard_danish_lowercase_string}
     , {&gui_virtual_keyboard_danish_layout, &gui_keyboard_danish_uppercase_string}
#endif /*__MMI_LANG_DANISH__*/

#ifdef __MMI_LANG_NORWEGIAN__
     , {&gui_virtual_keyboard_danish_layout, &gui_keyboard_danish_lowercase_string}
     , {&gui_virtual_keyboard_danish_layout, &gui_keyboard_danish_uppercase_string}
#endif /*__MMI_LANG_NORWEGIAN__*/

#ifdef __MMI_LANG_SLOVAK__
     , {&gui_virtual_keyboard_czech_layout, &gui_keyboard_slovak_lowercase_string}
     , {&gui_virtual_keyboard_czech_layout, &gui_keyboard_slovak_uppercase_string}
#endif /*__MMI_LANG_SLOVAK__*/

#ifdef __MMI_LANG_HUNGARIAN__
     , {&gui_virtual_keyboard_hungarian_layout, &gui_keyboard_hungarian_lowercase_string}
     , {&gui_virtual_keyboard_hungarian_layout, &gui_keyboard_hungarian_uppercase_string}
#endif /*__MMI_LANG_HUNGARIAN__*/

#ifdef __MMI_LANG_FINNISH__
     , {&gui_virtual_keyboard_finnish_layout, &gui_keyboard_finnish_lowercase_string}
     , {&gui_virtual_keyboard_finnish_layout, &gui_keyboard_finnish_uppercase_string}
#endif /*__MMI_LANG_FINNISH__*/

#ifdef __MMI_LANG_SWEDISH__
     , {&gui_virtual_keyboard_finnish_layout, &gui_keyboard_finnish_lowercase_string}
     , {&gui_virtual_keyboard_finnish_layout, &gui_keyboard_finnish_uppercase_string}
#endif /*__MMI_LANG_SWEDISH__*/

#ifdef __MMI_LANG_CROATIAN__
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_croatian_lowercase_string}
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_croatian_uppercase_string}
#endif /*__MMI_LANG_CROATIAN__*/

#ifdef __MMI_LANG_SLOVENIAN__
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_croatian_lowercase_string}
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_croatian_uppercase_string}
#endif /*__MMI_LANG_SLOVENIAN__*/

#ifdef __MMI_LANG_DUTCH__
     , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_lowercase_string}
     , {&gui_virtual_keyboard_standard_layout, &gui_keyboard_english_uppercase_string}
#endif /*__MMI_LANG_DUTCH__*/

#ifdef __MMI_LANG_POLISH__
     , {&gui_virtual_keyboard_polish_layout, &gui_keyboard_polish_lowercase_string}
     , {&gui_virtual_keyboard_polish_layout, &gui_keyboard_polish_uppercase_string}
#endif /*__MMI_LANG_POLISH__*/

#ifdef __MMI_LANG_ROMANIAN__
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_romanian_lowercase_string}
     , {&gui_virtual_keyboard_extended_layout, &gui_keyboard_romanian_uppercase_string}
 #endif /*__MMI_LANG_ROMANIAN__*/
 
#ifdef __MMI_LANG_UKRAINIAN__
     , {&gui_virtual_keyboard_ukrainian_layout, &gui_keyboard_ukrainian_lowercase_string}
     , {&gui_virtual_keyboard_ukrainian_layout, &gui_keyboard_ukrainian_uppercase_string}
#endif /*__MMI_LANG_ROMANIAN__*/

 
//Liu Jun add end

};

#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
static const gui_dead_key_symbol_struct gui_european_symbols[] = 
{
   /****Grave Accent***/
    {2, {0x60, 0x61}, 0xE0},
    {2, {0x60, 0x65}, 0xE8},
    {2, {0x60, 0x69}, 0xEC},
    {2, {0x60, 0x6F}, 0xF2},
    {2, {0x60, 0x75}, 0xF9},

    {2, {0x60, 0x41}, 0xC0},
    {2, {0x60, 0x45}, 0xC8},
    {2, {0x60, 0x49}, 0xCC},
    {2, {0x60, 0x4F}, 0xD2},
    {2, {0x60, 0x55}, 0xD9},

   /***Acute Accent***/
    {2, {0xB4, 0x61}, 0xE1},
    {2, {0xB4, 0x65}, 0xE9},
    {2, {0xB4, 0x69}, 0xED},
    {2, {0xB4, 0x6F}, 0xF3},
    {2, {0xB4, 0x75}, 0xFA},
    {2, {0xB4, 0x79}, 0xFD},

    {2, {0xB4, 0x41}, 0xC1},
    {2, {0xB4, 0x45}, 0xC9},
    {2, {0xB4, 0x49}, 0xCD},
    {2, {0xB4, 0x4F}, 0xD3},
    {2, {0xB4, 0x55}, 0xDA},
    {2, {0xB4, 0x59}, 0xDD},
//Liu Jun add 20070319
    {2, {0xB4, 0x4c}, 0x0139}, 
    {2, {0xB4, 0x6c}, 0x013A}, 
    {2, {0xB4, 0x52}, 0x0154}, 
    {2, {0xB4, 0x72}, 0x0155}, 
//Liu Jun add end

   /***circumflex accent***/
    {2, {0x5E, 0x61}, 0xE2},
    {2, {0x5E, 0x65}, 0xEA},
    {2, {0x5E, 0x69}, 0xEE},
    {2, {0x5E, 0x6F}, 0xF4},
    {2, {0x5E, 0x75}, 0xFB},

    {2, {0x5E, 0x41}, 0xC2},
    {2, {0x5E, 0x45}, 0xCA},
    {2, {0x5E, 0x49}, 0xCE},
    {2, {0x5E, 0x4F}, 0xD4},
    {2, {0x5E, 0x55}, 0xDB},

   /***Diaeresis***/
    {2, {0xA8, 0x61}, 0xE4},
    {2, {0xA8, 0x65}, 0xEB},
    {2, {0xA8, 0x69}, 0xEF},
    {2, {0xA8, 0x6F}, 0xF6},
    {2, {0xA8, 0x75}, 0xFC},
    {2, {0xA8, 0x79}, 0xFF},

    {2, {0xA8, 0x41}, 0xC4},
    {2, {0xA8, 0x45}, 0xCB},
    {2, {0xA8, 0x49}, 0xCF},
    {2, {0xA8, 0x4F}, 0xD6},
    {2, {0xA8, 0x55}, 0xDC},

   /***Tilde***/
    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},
    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1},
    
//Liu Jun add 20070319
   /***Hacek***/
    {2, {0x02C7, 0x63}, 0x10D},     
    {2, {0x02C7, 0x64}, 0x10F},
    {2, {0x02C7, 0x43}, 0x10C},     
    {2, {0x02C7, 0x44}, 0x10E},
    {2, {0x02C7, 0x45}, 0x11A},     
    {2, {0x02C7, 0x65}, 0x11B},
    {2, {0x02C7, 0x4E}, 0x147},     
    {2, {0x02C7, 0x6E}, 0x148},
    {2, {0x02C7, 0x52}, 0x158},
    {2, {0x02C7, 0x72}, 0x159},     
    {2, {0x02C7, 0x53}, 0x160},
    {2, {0x02C7, 0x73}, 0x161},
    {2, {0x02C7, 0x54}, 0x164},     
    {2, {0x02C7, 0x74}, 0x165},
    {2, {0x02C7, 0x5A}, 0x17D},
    {2, {0x02C7, 0x7A}, 0x17E},
    {2, {0x02C7, 0x6C}, 0x13E},
    {2, {0x02C7, 0x4C}, 0x13D},
    
    /***Cedilla***/
    {2, {0x00B8, 0x53}, 0x15E},
    {2, {0x00B8, 0x73}, 0x15F},
    {2, {0x00B8, 0x43}, 0xC7},
    {2, {0x00B8, 0x63}, 0xE7},
    
    /***Ogonek***/
    {2, {0x02DB, 0x41}, 0x0104},
    {2, {0x02DB, 0x45}, 0x0118},
    {2, {0x02DB, 0x61}, 0x0105},
    {2, {0x02DB, 0x65}, 0x0119}
    
//Liu Jun add end

};

static const gui_dead_key_symbol_struct gui_turkish_symbols[] = 
{
   /****Grave Accent***/
    {2, {0x60, 0x61}, 0xE0},
    {2, {0x60, 0x65}, 0xE8},
    {2, {0x60, 0x69}, 0xEC},
    {2, {0x60, 0x131}, 0xEC},
    {2, {0x60, 0x6F}, 0xF2},
    {2, {0x60, 0x75}, 0xF9},

    {2, {0x60, 0x41}, 0xC0},
    {2, {0x60, 0x45}, 0xC8},
    {2, {0x60, 0x49}, 0xCC},
    {2, {0x60, 0x130}, 0xCC},
    {2, {0x60, 0x4F}, 0xD2},
    {2, {0x60, 0x55}, 0xD9},

   /***Acute Accent***/
    {2, {0xB4, 0x61}, 0xE1},
    {2, {0xB4, 0x65}, 0xE9},
    {2, {0xB4, 0x69}, 0xED},
    {2, {0xB4, 0x131}, 0xED},
    {2, {0xB4, 0x6F}, 0xF3},
    {2, {0xB4, 0x75}, 0xFA},

    {2, {0xB4, 0x41}, 0xC1},
    {2, {0xB4, 0x45}, 0xC9},
    {2, {0xB4, 0x49}, 0xCD},
    {2, {0xB4, 0x130}, 0xCD},
    {2, {0xB4, 0x4F}, 0xD3},
    {2, {0xB4, 0x55}, 0xDA},

   /***circumflex accent***/
    {2, {0x5E, 0x61}, 0xE2},
    {2, {0x5E, 0x65}, 0xEA},
    {2, {0x5E, 0x69}, 0xEE},
    {2, {0x5E, 0x131}, 0xEE},
    {2, {0x5E, 0x6F}, 0xF4},
    {2, {0x5E, 0x75}, 0xFB},

    {2, {0x5E, 0x41}, 0xC2},
    {2, {0x5E, 0x45}, 0xCA},
    {2, {0x5E, 0x49}, 0xCE},
    {2, {0x5E, 0x130}, 0xCE},
    {2, {0x5E, 0x4F}, 0xD4},
    {2, {0x5E, 0x55}, 0xDB},

   /***Diaeresis***/
    {2, {0xA8, 0x61}, 0xE4},
    {2, {0xA8, 0x65}, 0xEB},
    {2, {0xA8, 0x69}, 0xEF},
    {2, {0xA8, 0x131}, 0xEF},
    {2, {0xA8, 0x6F}, 0xF6},
    {2, {0xA8, 0x75}, 0xFC},
    {2, {0xA8, 0x79}, 0xFF},

    {2, {0xA8, 0x41}, 0xC4},
    {2, {0xA8, 0x45}, 0xCB},
    {2, {0xA8, 0x49}, 0xCF},
    {2, {0xA8, 0x130}, 0xCF},
    {2, {0xA8, 0x4F}, 0xD6},
    {2, {0xA8, 0x55}, 0xDC},

   /***Tilde***/
    {2, {0x7E, 0x61}, 0xE3},
    {2, {0x7E, 0x6F}, 0xF5},
    {2, {0x7E, 0x6E}, 0xF1},

    {2, {0x7E, 0x41}, 0xC3},
    {2, {0x7E, 0x4F}, 0xD5},
    {2, {0x7E, 0x4E}, 0xD1}
};
#endif /* __MMI_VKBD_EUROPEAN_SUPPORT__ */ 

#ifdef __MMI_LANG_GREEK__
static const gui_dead_key_symbol_struct gui_greek_symbols[] = 
{
   /*Dialytika*/
   {2, {0x0385, 0x03B9}, 0x0390},
   {2, {0x0385, 0x03C5}, 0x03B0},
   /*Greek_acute*/
   {2, {0x0384, 0x0391}, 0x0386},
   {2, {0x0384, 0x0395}, 0x0388},
   {2, {0x0384, 0x0397}, 0x0389},
   {2, {0x0384, 0x0399}, 0x038A},
   {2, {0x0384, 0x039F}, 0x038C},
   {2, {0x0384, 0x03A5}, 0x038E},
   {2, {0x0384, 0x03A9}, 0x038F},
   {2, {0x0384, 0x03B1}, 0x03AC},
   {2, {0x0384, 0x03B5}, 0x03AD},
   {2, {0x0384, 0x03B7}, 0x03AE},
   {2, {0x0384, 0x03B9}, 0x03AF},
   {2, {0x0384, 0x03BF}, 0x03CC},
   {2, {0x0384, 0x03C5}, 0x03CD},
   {2, {0x0384, 0x03C9}, 0x03CE},
   /*Diaeresis*/
   {2, {0x00A8, 0x0399}, 0x03AA},
   {2, {0x00A8, 0x03A5}, 0x03AB},
   {2, {0x00A8, 0x03B9}, 0x03CA},
   {2, {0x00A8, 0x03C5}, 0x03CB}
};


#endif /*__MMI_LANG_GREEK__*/

/* The order should be the same as gui_virtual_keyboard_language_enum */
const gui_dead_key_map_struct gui_dead_key_symbol_table[] = 
{
    /* English */
    {NULL, 0},
    {NULL, 0},
    /* Symbol */
    {NULL, 0},
    /* Tray */
    {NULL, 0},
    /* Number */
    {NULL, 0},
    /* Phone Number */
    {NULL, 0},
    /* Empty Tray */
    {NULL, 0},
    /* Number Tray */
    {NULL, 0},
    /* Number Dot Tray */
    {NULL, 0}
    /* MTK Terry Temp Solution for Custom Release */
    // #ifdef __MMI_LANG_SM_CHINESE__
    , {NULL, 0}
    //#endif
    //#ifdef __MMI_LANG_TR_CHINESE__
    , {NULL, 0}
    //#endif
    //#if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__)
    , {NULL, 0}
    // #endif
    /* Asia-pacific */
#ifdef __MMI_LANG_THAI__
    , {NULL, 0}
    , {NULL, 0}
#endif 
#ifdef __MMI_LANG_INDONESIAN__
    , {NULL, 0}
    , {NULL, 0}
#endif 
#ifdef __MMI_LANG_MALAY__
    , {NULL, 0}
    , {NULL, 0}
#endif 
#ifdef __MMI_LANG_VIETNAMESE__
    , {NULL, 0}
    , {NULL, 0}
#endif 
    /* Hindi */
#ifdef __MMI_LANG_HINDI__
#endif 
    /* Arabic */
#ifdef __MMI_LANG_ARABIC__
    , {NULL, 0}
    , {NULL, 0}
#endif 
    /* Europe */
#ifdef __MMI_LANG_SPANISH__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_SPANISH__ */ 
#ifdef __MMI_LANG_FRENCH__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_FRENCH__ */ 
#ifdef __MMI_LANG_GERMAN__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_GERMAN__ */ 
#ifdef __MMI_LANG_ITALIAN__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_ITALIAN__ */ 
#ifdef __MMI_LANG_RUSSIAN__
    , {NULL, 0}
    , {NULL, 0}
#endif /* __MMI_LANG_RUSSIAN__ */ 
#ifdef __MMI_LANG_TURKISH__
    , {gui_turkish_symbols, sizeof(gui_turkish_symbols) / sizeof(gui_turkish_symbols[0])}
    , {gui_turkish_symbols, sizeof(gui_turkish_symbols) / sizeof(gui_turkish_symbols[0])}
#endif /* __MMI_LANG_TURKISH__ */ 
#ifdef __MMI_LANG_PORTUGUESE__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_PORTUGUESE__ */ 
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
    , {NULL, 0}
#endif 
//Liu Jun add 20070319
#ifdef __MMI_LANG_CZECH__
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
    , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /* __MMI_LANG_CZECH__ */

#ifdef __MMI_LANG_HEBREW__
    , {NULL, 0}
#endif /* __MMI_LANG_HEBREW__ */

#ifdef __MMI_LANG_PERSIAN__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_PERSIAN__*/

#ifdef __MMI_LANG_GREEK__
     , {gui_greek_symbols, sizeof(gui_greek_symbols) / sizeof(gui_greek_symbols[0])}
     , {gui_greek_symbols, sizeof(gui_greek_symbols) / sizeof(gui_greek_symbols[0])}
#endif /*__MMI_LANG_GREEK__*/

#ifdef __MMI_LANG_BULGARIAN__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_BULGARIAN__*/

#ifdef __MMI_LANG_DANISH__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_DANISH__*/

#ifdef __MMI_LANG_NORWEGIAN__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_NORWEGIAN__*/

#ifdef __MMI_LANG_SLOVAK__
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /*__MMI_LANG_SLOVAK__*/

#ifdef __MMI_LANG_HUNGARIAN__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_HUNGARIAN__*/

#ifdef __MMI_LANG_FINNISH__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_FINNISH__*/

#ifdef __MMI_LANG_SWEDISH__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_SWEDISH__*/

#ifdef __MMI_LANG_CROATIAN__
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /*__MMI_LANG_CROATIAN__*/

#ifdef __MMI_LANG_SLOVENIAN__
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /*__MMI_LANG_SLOVENIAN__*/

#ifdef __MMI_LANG_DUTCH__
     , {NULL, 0}
     , {NULL, 0}
#endif /*__MMI_LANG_DUTCH__*/

#ifdef __MMI_LANG_POLISH__
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
     , {gui_european_symbols, sizeof(gui_european_symbols) / sizeof(gui_european_symbols[0])}
#endif /*__MMI_LANG_POLISH__*/

#ifdef __MMI_LANG_ROMANIAN__
    , {NULL, 0}
     , {NULL, 0}
 #endif /*__MMI_LANG_ROMANIAN__*/
 
#ifdef __MMI_LANG_UKRAINIAN__
      , {NULL, 0}
      , {NULL, 0}
#endif /*__MMI_LANG_UKRAINIAN__*/

 
//Liu Jun add end

};

/***************************************************************************** 
 * Local variable 
 *****************************************************************************/
static MMI_BOOL g_wgui_virtual_keyboard_multi_block_mode = MMI_FALSE;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  create_virtual_keyboard
 * DESCRIPTION
 *  Create virtual keyboard object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  The function is dummy because the keyboard object is statically allocated.
 *****************************************************************************/
void create_virtual_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 map_index, key_index;
    S32 max_value = 0, tmp;
    const gui_keyboard_layout_struct *layout;
    const gui_keyboard_language_struct *lang;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(sizeof(MMI_virtual_keyboard_language_map) / sizeof(gui_keyboard_lang_map_struct) ==
                   GUI_VIRTUAL_KEYBOARD_MAX_LANG);
    MMI_DBG_ASSERT(sizeof(gui_dead_key_symbol_table) / sizeof(gui_dead_key_map_struct) ==
                   GUI_VIRTUAL_KEYBOARD_MAX_LANG);

    /* Compute the cache size of key */
    for (map_index = 0; map_index < GUI_VIRTUAL_KEYBOARD_MAX_LANG; map_index++)
    {
        layout = MMI_virtual_keyboard_language_map[map_index].virtual_keyboard_layout;
        lang = MMI_virtual_keyboard_language_map[map_index].virtual_keyboard_language;

        for (key_index = 0; key_index < layout->n_custom_keys; key_index++)
        {
            if (lang->custom_key_type[key_index] == GUI_VKBD_PEN_DISPLAY_AREA)
            {
                /* Display area is not cached due to its size */
                continue;
            }
            tmp = layout->custom_keys[key_index].key_height * layout->custom_keys[key_index].key_width;
            if (tmp > max_value)
            {
                max_value = tmp;
            }
        }
    }

    MMI_virtual_keyboard_bitmap_cache_size = ((max_value * gdi_layer_get_bit_per_pixel()) + 7) >> 3;

    /* GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY is the default value */
    gui_create_virtual_keyboard(
        &MMI_virtual_keyboard,
        (S16) MMI_content_x,
        (S16) MMI_content_y,
        GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_set_global_multi_block_mode
 * DESCRIPTION
 *  Set global flag of multi-block handwriting mode 
 *
 *  In multi-block handwriting mode, some keyboard icons are displayed differently.
 * PARAMETERS
 *  enabled        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_virtual_keyboard_set_global_multi_block_mode(MMI_BOOL enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_virtual_keyboard_multi_block_mode = enabled;
    gui_set_virtual_keyboard_multi_block_mode(&MMI_virtual_keyboard, enabled);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_virtual_keyboard
 * DESCRIPTION
 *  Setup the language of virtual keyboard object
 * PARAMETERS
 *  lang_type       [IN]        Language
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_virtual_keyboard(gui_virtual_keyboard_language_enum lang_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 vkbd_height = MMI_virtual_keyboard_language_map[lang_type].virtual_keyboard_layout->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_virtual_keyboard(
        &MMI_virtual_keyboard,
        (S16) MMI_content_x,
        (S16) (MMI_content_y + MMI_content_height - vkbd_height),
        lang_type);
        
    gui_set_virtual_keyboard_multi_block_mode(&MMI_virtual_keyboard, g_wgui_virtual_keyboard_multi_block_mode);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_close_virtual_keyboard
 * DESCRIPTION
 *  Release the resource used by virtual keyboard object
 * PARAMETERS
 *  void
 *  lang_type(?)        [IN]        Language
 * RETURNS
 *  void
 * REMARKS
 *  Used in exit function or exit category function
 *****************************************************************************/
void wgui_close_virtual_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DUMMY */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_display_area
 * DESCRIPTION
 *  Update text displayed on display area
 * PARAMETERS
 *  string      [IN]        String to be displayed in display area
 *  redraw      [IN]        Whether to redraw the keyboard
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void wgui_set_virtual_keyboard_display_area(const U8 *string, BOOL redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_virtual_keyboard_display_area(&MMI_virtual_keyboard, string, redraw);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_virtual_keyboard_size
 * DESCRIPTION
 *  Get the current size of virtual keyboard
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  void
 * REMARKS
 *  Keyboards of different languages have different size
 *****************************************************************************/
void wgui_get_virtual_keyboard_size(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_virtual_keyboard.width;
    *height = MMI_virtual_keyboard.height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_allowed_characters
 * DESCRIPTION
 *  Only the allowd characters can be input on keyboard.
 *  This function and wgui_set_virtual_keyboard_disabled_list() are mutually-exclusive.
 *  
 *  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
 *  they are not related to character insertion.
 *  
 *  `allowed_characters' may contain '-' for consecutive characters
 *  (Ex. 'a-z' for characters from a to z.)
 *  If we want to accept "-", please write it as '\-'.
 *  For example, '\-0-9.' represents "-0123456789."
 *  
 *  Example of valid characters in email addresss:
 *  wgui_set_virtual_keyboard_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
 *  (it is not a complete list of all characters allowed in RFC, but it satisfies almost all cases)
 * PARAMETERS
 *  allowed_chars       [IN]        Allowed characters
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_virtual_keyboard_allowed_characters(const UI_character_type *allowed_chars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_virtual_keyboard_allowed_characters(&MMI_virtual_keyboard, allowed_chars);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_disabled_list
 * DESCRIPTION
 *  Set disabled characters in virtual keyboard
 * PARAMETERS
 *  disabled_chars          [IN]        Ended by '\0'
 *  disabled_symbols        [IN]        Ended by GUI_VKBD_PEN_NONE
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void wgui_set_virtual_keyboard_disabled_list(
        const UI_character_type *disabled_chars,
        const gui_virtual_keyboard_pen_enum *disabled_symbols)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_virtual_board_disable_list(&MMI_virtual_keyboard, disabled_chars, disabled_symbols);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_virtual_keyboard
 * DESCRIPTION
 *  Move the position of virtual keyboard
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void wgui_move_virtual_keyboard(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_virtual_keyboard(&MMI_virtual_keyboard, (S16) x, (S16) y);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_virtual_keyboard
 * DESCRIPTION
 *  Display virtual keyboard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void wgui_show_virtual_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_virtual_keyboard(&MMI_virtual_keyboard);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_virtual_keyboard.x,
        MMI_virtual_keyboard.y,
        MMI_virtual_keyboard.x + MMI_virtual_keyboard.width - 1,
        MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_greyscale_virtual_keyboard
 * DESCRIPTION
 *  Make the 'displayed' virtual keyboard as greyed (disabled)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
void wgui_greyscale_virtual_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_greyscale_rectangle(MMI_virtual_keyboard.x, MMI_virtual_keyboard.y, MMI_virtual_keyboard.x + MMI_virtual_keyboard.width - 1, MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1, MMI_VKBD_GRAYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE); /* 102605 greyscale Calvin modified */
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_virtual_keyboard.x,
        MMI_virtual_keyboard.y,
        MMI_virtual_keyboard.x + MMI_virtual_keyboard.width - 1,
        MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1);
}

