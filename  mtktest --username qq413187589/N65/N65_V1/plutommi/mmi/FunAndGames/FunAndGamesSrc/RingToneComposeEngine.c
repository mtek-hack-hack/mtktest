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
 * RingToneComposeEngine.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements the tone editor screen related functionalities of Ring Tone Composer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
**/

/**************************************************************

   FILENAME : RingToneComposerEngine.c

   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Vikram

   DATE     : 

**************************************************************/
#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#include "GlobalConstants.h"
#include "GlobalDefs.h"
#include "gui.h"
#include "HistoryGprot.h"
#include "Ucs2prot.h"
#include "ComposeRingToneEngineProts.h"
#include "wgui_categories.h"
#include "gui_data_types.h"
#include "Asciiprot.h"
#include "ComposeRingToneDefs.h"
#include "TimerEvents.h"
#include "SettingProfile.h"
#include "DownloadDefs.h"
#include "CustDataProts.h"
#include "ComposeRingToneProts.h"
#include "gpioInc.h"
#include "ProfileGprots.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "FileManagerDef.h"
#include "FileManagerGprot.h"
#include "CommonScreens.h"
#include "KeyBrd.h"
#include "fs_type.h"
#include "FS_Func.h"
#include "fs_errcode.h"

#ifdef __MMI_TOUCH_RING_COMPOSER__
#include "MMIDataType.h"
#include "TouchScreenGprot.h"
#include "gui_buttons.h"
#include "wgui_softkeys.h"
#include "ScrMemMgrGprot.h"     /* screen memeory manager */
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#include "DebugInitDef.h"
 
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__ */

/* 
 * Define
 */
#define  MULTITAP_TIME           1000

   /* iMelody header/tailer */
#define  MELODY_HEADER           "BEGIN:IMELODY\r\nVERSION:1.2\r\nFORMAT:CLASS1.0\r\n"
#define  MELODY_END              "\r\nEND:IMELODY\r\n"

   /* mask for musical note */
#define  NOTE_MASK               0x0000000F     /* symbol of musical note */
#define  CLEAR_NOTE_MASK         0xFFFFFFF0
#define  DURATION_MASK           0x00001E00     /* beat length */
#define  CLEAR_DURATION_MASK     0xFFFFE1FF
#define  CLEAR_NOTETYPE_MASK     0xFFFFFFCF
#define  NOTETYPE_MASK           0x00000030     /* sharp, normal, flat */
#define  OCTAVE_MASK             0x000001C0     /* octave */
 
/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
MMI_BOOL CurrentNodePlaying = MMI_FALSE;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
rngc_engine_context_struct *g_rngc_eng_cntx;
rngc_skin_layout_struct g_rngc_skin_layout;

/* MTK Elvis for R2L characters */
extern BOOL r2lMMIFlag;

/* MTk end */

/* 
 * Global Function
 */

const UI_filled_area lightblue_color_dialog_background = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {108, 182, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {50, 50, 50, 100},
    0
};


#ifdef RNGC_HAS_INST_RECTANGLE

const UI_filled_area rngc_instrument_select_background = {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
#if defined(__MMI_MAINLCD_320X240__)
    {56, 70, 82, 100},
#else
    //{215, 215, 215, 100},  //Huyanwei Modify It 
    {128, 128, 128, 100}, 
#endif
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

#endif /* RNGC_HAS_INST_RECTANGLE*/ 

#if defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_RING_COMPOSER__)
const U8 gnYCoords[] = 
{
    45 + RNGC_NOTE_OFFSET,
    54 + RNGC_NOTE_OFFSET,
    51 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    45 + RNGC_NOTE_OFFSET,
    42 + RNGC_NOTE_OFFSET,
    39 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    3 + RNGC_NOTE_OFFSET,
    0 + RNGC_NOTE_OFFSET,
    RNGC_NOTE_OFFSET - 3,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
static const rngc_custom_key_layout_struct normal_toolbar_custom_layout[] = 
{
    {1, 185, 34, 14, IMG_TOUCH_RING_EDIT, GUI_RNGC_KEY_EDIT},
    {36, 185, 45, 14, IMG_TOUCH_RING_INSERT, GUI_RNGC_KEY_INSERT},
    {82, 185, 45, 14, IMG_TOUCH_RING_PLAY, GUI_RNGC_KEY_PLAY},
    {128, 185, 23, 14, IMG_TOUCH_RING_PREV, GUI_RNGC_KEY_NEXT},
    {152, 185, 23, 14, IMG_TOUCH_RING_NEXT, GUI_RNGC_KEY_PREV}
};

static rngc_custom_key_layout_struct note_selection_custom_layout[] = 
{
    {134, 151, 18, 23, IMG_RING_EVENTBL_ON, NOTE_BACKLIGHT_ON},
    {153, 151, 22, 23, IMG_RING_EVENTLED_ON, NOTE_LED_ON},
    {134, 175, 41, 23, IMG_TOUCH_RING_DOWN, GUI_RNGC_KEY_OK},
};

#elif defined( __MMI_MAINLCD_176X220__)
const U8 gnYCoords[] = 
{
    59 + RNGC_NOTE_OFFSET,
    68 + RNGC_NOTE_OFFSET,
    65 + RNGC_NOTE_OFFSET,
    62 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    38 + RNGC_NOTE_OFFSET,
    35 + RNGC_NOTE_OFFSET,
    32 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#elif defined(__MMI_MAINLCD_240X320__)
const U8 gnYCoords[] = 
{
    49 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    47 + RNGC_NOTE_OFFSET,
    44 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    5 + RNGC_NOTE_OFFSET,
    2 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#ifdef __MMI_TOUCH_RING_COMPOSER__
static const rngc_custom_key_layout_struct normal_toolbar_custom_layout[] = 
{
    {1, NORMAL_TOOLBAR_IMAGE_Y + 1, 57, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_EDIT, GUI_RNGC_KEY_EDIT},
    {59, NORMAL_TOOLBAR_IMAGE_Y + 1, 52, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_INSERT, GUI_RNGC_KEY_INSERT},
    {112, NORMAL_TOOLBAR_IMAGE_Y + 1, 59, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_PLAY, GUI_RNGC_KEY_PLAY},
    {172, NORMAL_TOOLBAR_IMAGE_Y + 1, 33, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_PREV, GUI_RNGC_KEY_NEXT},
    {206, NORMAL_TOOLBAR_IMAGE_Y + 1, 33, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_NEXT, GUI_RNGC_KEY_PREV}
};
/* Notice: If you want to change the button size, please remember to modify the memory size defined in ScrMemMgr.h */
static rngc_custom_key_layout_struct note_selection_custom_layout[] = 
{
    {176, NOTE_SELECTION_IMAGE_Y + 1, 24, 31, IMG_RING_EVENTLED_ON, NOTE_LED_ON},
    {201, NOTE_SELECTION_IMAGE_Y + 1, 38, 31, IMG_RING_EVENTBL_ON, NOTE_BACKLIGHT_ON},
    {176, NOTE_SELECTION_IMAGE_Y + 34, 63, 31, IMG_TOUCH_RING_DOWN, GUI_RNGC_KEY_OK},
};
#endif /*__MMI_TOUCH_RING_COMPOSER__*/

#elif defined(__MMI_MAINLCD_320X240__)
const U8 gnYCoords[] = 
{
    56 + RNGC_NOTE_OFFSET,
    65 + RNGC_NOTE_OFFSET,
    62 + RNGC_NOTE_OFFSET,
    59 + RNGC_NOTE_OFFSET,
    56 + RNGC_NOTE_OFFSET,
    53 + RNGC_NOTE_OFFSET,
    50 + RNGC_NOTE_OFFSET,
    35 + RNGC_NOTE_OFFSET,
    32 + RNGC_NOTE_OFFSET,
    29 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    26 + RNGC_NOTE_OFFSET,
    23 + RNGC_NOTE_OFFSET,
    20 + RNGC_NOTE_OFFSET,
    17 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    11 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    28 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#ifdef __MMI_TOUCH_RING_COMPOSER__
static const rngc_custom_key_layout_struct normal_toolbar_custom_layout[] = 
{
    {19, NORMAL_TOOLBAR_IMAGE_Y + 1, 65, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_EDIT, GUI_RNGC_KEY_EDIT},
    {84, NORMAL_TOOLBAR_IMAGE_Y + 1, 65, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_INSERT, GUI_RNGC_KEY_INSERT},
    {149, NORMAL_TOOLBAR_IMAGE_Y + 1, 65, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_PLAY, GUI_RNGC_KEY_PLAY},
    {216, NORMAL_TOOLBAR_IMAGE_Y + 1, 41, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_PREV, GUI_RNGC_KEY_NEXT},
    {257, NORMAL_TOOLBAR_IMAGE_Y + 1, 41, NORMAL_TOOLBAR_HEIGHT - 2, IMG_TOUCH_RING_NEXT, GUI_RNGC_KEY_PREV}
};

static rngc_custom_key_layout_struct note_selection_custom_layout[] = 
{
    {236, NOTE_SELECTION_IMAGE_Y + 1, 31, 24, IMG_RING_EVENTLED_ON, NOTE_LED_ON},
    {265, NOTE_SELECTION_IMAGE_Y + 1, 31, 24, IMG_RING_EVENTBL_ON, NOTE_BACKLIGHT_ON},
    {236, NOTE_SELECTION_IMAGE_Y + 24, 62, 24, IMG_TOUCH_RING_DOWN, GUI_RNGC_KEY_OK},
};
#endif /*__MMI_TOUCH_RING_COMPOSER__*/

#else 
const U8 gnYCoords[] = 
{
    54 + RNGC_NOTE_OFFSET,
    51 + RNGC_NOTE_OFFSET,
    48 + RNGC_NOTE_OFFSET,
    45 + RNGC_NOTE_OFFSET,
    42 + RNGC_NOTE_OFFSET,
    39 + RNGC_NOTE_OFFSET,
    36 + RNGC_NOTE_OFFSET,
    33 + RNGC_NOTE_OFFSET,
    30 + RNGC_NOTE_OFFSET,
    27 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    15 + RNGC_NOTE_OFFSET,
    24 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    18 + RNGC_NOTE_OFFSET,
    14 + RNGC_NOTE_OFFSET,
    12 + RNGC_NOTE_OFFSET,
    9 + RNGC_NOTE_OFFSET,
    6 + RNGC_NOTE_OFFSET,
    21 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    22 + RNGC_NOTE_OFFSET,
    8 + RNGC_NOTE_OFFSET
};
#ifdef __MMI_TOUCH_RING_COMPOSER__
static const rngc_custom_key_layout_struct normal_toolbar_custom_layout[] = 
{
    {1, 185, 34, 14, IMG_TOUCH_RING_EDIT, GUI_RNGC_KEY_EDIT},
    {36, 185, 45, 14, IMG_TOUCH_RING_INSERT, GUI_RNGC_KEY_INSERT},
    {82, 185, 45, 14, IMG_TOUCH_RING_PLAY, GUI_RNGC_KEY_PLAY},
    {128, 185, 23, 14, IMG_TOUCH_RING_PREV, GUI_RNGC_KEY_NEXT},
    {152, 185, 23, 14, IMG_TOUCH_RING_NEXT, GUI_RNGC_KEY_PREV}
};

static rngc_custom_key_layout_struct note_selection_custom_layout[] = 
{
    {134, 152, 18, 23, IMG_RING_EVENTLED_ON, NOTE_LED_ON},
    {153, 152, 22, 23, IMG_RING_EVENTBL_ON, NOTE_BACKLIGHT_ON},
    {134, 176, 41, 23, IMG_TOUCH_RING_DOWN, GUI_RNGC_KEY_OK},
};
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
#endif /*defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_RING_COMPOSER__)*/

#ifdef __MMI_TOUCH_RING_COMPOSER__
static const rngc_matrix_key_layout_struct normal_toolbar_matrix_layout = 
{
    RNGC_TOOL_BAR_LEFT_OFFSET,1,
    2, 7,
    RNGC_NOTE_SELECT_MATRIX_WIDTH, RNGC_NOTE_SELECT_MATRIX_HEIGHT,
    RNGC_MATRIX_KEY_WIDTH, RNGC_MATRIX_KEY_HEIGHT,
    {
     {IMG_TOUCH_RING_UP, TOUCH_IMG_1_OCT_L_M_N, TOUCH_IMG_1BY2_OCT_L_M_N, TOUCH_IMG_1BY4_OCT_L_M_N,
      TOUCH_IMG_1BY8_OCT_L_M_N, TOUCH_IMG_1BY16_OCT_L_M_N, IMG_RING_EVENTVIB_ON},
     {IMG_TOUCH_RING_DOWN, TOUCH_IMG_1BY4_OCT_L_M, TOUCH_IMG_1BY8_OCT_L_M, TOUCH_IMG_1BY16_OCT_L_M, IMG_TOUCH_RNGC_HASH,
      IMG_TOUCH_RING_P, IMG_TOUCH_RING_DOT},
     },
    {
     {GUI_RNGC_OCTAVE_UP, GUI_RNGC_KEY_NOTE1, GUI_RNGC_KEY_NOTE2, GUI_RNGC_KEY_NOTE3, GUI_RNGC_KEY_NOTE4,
      GUI_RNGC_KEY_NOTE5, NOTE_VIBRATION_ON},
     {GUI_RNGC_OCTAVE_DOWN, GUI_RNGC_KEY_NOTE6, GUI_RNGC_KEY_NOTE7, GUI_RNGC_KEY_NOTE8, GUI_RNGC_KEY_SHARP,
      GUI_RNGC_KEY_FLAT, GUI_RNGC_KEY_DOT},
     }
};

const static rngc_selection_area_layout_struct normal_toolbar_layout = 
{
    0,
    5,
    NORMAL_TOOLBAR_IMAGE_X,
    NORMAL_TOOLBAR_IMAGE_Y,
    (rngc_matrix_key_layout_struct *) & normal_toolbar_matrix_layout,
    (rngc_custom_key_layout_struct *) normal_toolbar_custom_layout,
    1,
    0,
    IMG_TOUCH_RING_NORMAL
};

const static rngc_matrix_key_layout_struct note_selection_matrix_layout = 
{
    RNGC_TOOL_BAR_LEFT_OFFSET,1,
    2, 7,
    RNGC_NOTE_SELECT_MATRIX_WIDTH, RNGC_NOTE_SELECT_MATRIX_HEIGHT,
    RNGC_MATRIX_KEY_WIDTH, RNGC_MATRIX_KEY_HEIGHT,
    {
     {IMG_TOUCH_RING_UP, TOUCH_IMG_1_OCT_L_M_N, TOUCH_IMG_1BY2_OCT_L_M_N, TOUCH_IMG_1BY4_OCT_L_M_N,
      TOUCH_IMG_1BY8_OCT_L_M_N, TOUCH_IMG_1BY16_OCT_L_M_N, IMG_RING_EVENTVIB_ON},
     {IMG_TOUCH_RING_DOWN, TOUCH_IMG_1BY4_OCT_L_M, TOUCH_IMG_1BY8_OCT_L_M, TOUCH_IMG_1BY16_OCT_L_M, IMG_TOUCH_RNGC_HASH,
      IMG_TOUCH_RING_P, IMG_TOUCH_RING_DOT},
     },
    {
     {GUI_RNGC_OCTAVE_UP, GUI_RNGC_KEY_NOTE1, GUI_RNGC_KEY_NOTE2, GUI_RNGC_KEY_NOTE3, GUI_RNGC_KEY_NOTE4,
      GUI_RNGC_KEY_NOTE5, NOTE_VIBRATION_ON},
     {GUI_RNGC_OCTAVE_DOWN, GUI_RNGC_KEY_NOTE6, GUI_RNGC_KEY_NOTE7, GUI_RNGC_KEY_NOTE8, GUI_RNGC_KEY_SHARP,
      GUI_RNGC_KEY_FLAT, GUI_RNGC_KEY_DOT},
     }
};

static const rngc_selection_area_layout_struct note_selection_layout = 
{
    14,
    3,
    NOTE_SELECTION_IMAGE_X,
    NOTE_SELECTION_IMAGE_Y,
    (rngc_matrix_key_layout_struct *) & note_selection_matrix_layout,
    (rngc_custom_key_layout_struct *) note_selection_custom_layout,
    1,  
    RNGC_NOTE_SELECTION_VERTICAL_GAP,
    IMG_TOUCH_RING_SELECTION
};


touch_rngc_struct touch_rngc_context;
rngc_selection_area_layout_struct const *selection_area_context;
S32 rngc_pen_event_on_object = RNGC_PEN_NONE;

const UI_filled_area touch_rngc_color_key_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SHADOW,
    UI_NULL_IMAGE,
    NULL,
    {128, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {50, 50, 50, 100},
    0
};

#endif /* __MMI_TOUCH_RING_COMPOSER__ */


#define        SetVibrationOff()    {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_VIBRATION_OFF;}

#define        SetVibrationOn()     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_VIBRATION_ON;}

#define        SetLEDOff()          {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_LED_OFF;}

#define        SetLEDOn()           {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_LED_ON;}

#define        SetBackLightOff()    {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_BACKLIGHT_OFF;}

#define        SetBackLightOn()     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_BACKLIGHT_ON;}

#define        SetNoteType(nType)      {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTETYPE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nType;}

#define        SetOctave(nType)     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=~OCTAVE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nType;}

#define        IncrementNoteBeat()        {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal >= DURATION_1BY16)                                                    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_3BY2;     \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>9;                                                          \
                                    ++nTempVal;                                                                    \
                                    nTempVal=nTempVal<<9;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define     TouchRngcDecrementNoteBeat()  {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal <= DURATION_3BY2)                                                     \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_1BY16;    \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>9;                                                          \
                                    --nTempVal;                                                                    \
                                    nTempVal=nTempVal<<9;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#define        IncrementRestBeat()        {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal >= DURATION_1BY16)                                                    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_3BY8;     \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>9;                                                          \
                                    ++nTempVal;                                                                    \
                                    nTempVal=nTempVal<<9;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }


 

const NoteInfo gNotesList[] = 
{
    {DURATION_3BY2 | OCTAVE_3 | NORMAL, IMG_3BY2_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_3 | FLAT, IMG_3BY2_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_3 | SHARP, IMG_3BY2_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY2 | OCTAVE_5 | NORMAL, IMG_3BY2_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_5 | FLAT, IMG_3BY2_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY2 | OCTAVE_5 | SHARP, IMG_3BY2_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1 | OCTAVE_3 | NORMAL, IMG_1_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_3 | FLAT, IMG_1_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_3 | SHARP, IMG_1_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1 | OCTAVE_5 | NORMAL, IMG_1_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_5 | FLAT, IMG_1_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1 | OCTAVE_5 | SHARP, IMG_1_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY4 | OCTAVE_3 | NORMAL, IMG_3BY4_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_3 | FLAT, IMG_3BY4_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_3 | SHARP, IMG_3BY4_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY4 | OCTAVE_5 | NORMAL, IMG_3BY4_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_5 | FLAT, IMG_3BY4_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY4 | OCTAVE_5 | SHARP, IMG_3BY4_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY2 | OCTAVE_3 | NORMAL, IMG_1BY2_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_3 | FLAT, IMG_1BY2_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_3 | SHARP, IMG_1BY2_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY2 | OCTAVE_5 | NORMAL, IMG_1BY2_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_5 | FLAT, IMG_1BY2_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY2 | OCTAVE_5 | SHARP, IMG_1BY2_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY8 | OCTAVE_3 | NORMAL, IMG_3BY8_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_3 | FLAT, IMG_3BY8_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_3 | SHARP, IMG_3BY8_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY8 | OCTAVE_5 | NORMAL, IMG_3BY8_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_5 | FLAT, IMG_3BY8_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY8 | OCTAVE_5 | SHARP, IMG_3BY8_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_3 | NORMAL, IMG_1BY4_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_3 | FLAT, IMG_1BY4_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_3 | SHARP, IMG_1BY4_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_5 | NORMAL, IMG_1BY4_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_5 | FLAT, IMG_1BY4_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY4 | OCTAVE_5 | SHARP, IMG_1BY4_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_3 | NORMAL, IMG_3BY16_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_3 | FLAT, IMG_3BY16_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_3 | SHARP, IMG_3BY16_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_5 | NORMAL, IMG_3BY16_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_5 | FLAT, IMG_3BY16_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY16 | OCTAVE_5 | SHARP, IMG_3BY16_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_3 | NORMAL, IMG_1BY8_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_3 | FLAT, IMG_1BY8_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_3 | SHARP, IMG_1BY8_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_5 | NORMAL, IMG_1BY8_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_5 | FLAT, IMG_1BY8_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY8 | OCTAVE_5 | SHARP, IMG_1BY8_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_3 | NORMAL, IMG_3BY32_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_3 | FLAT, IMG_3BY32_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_3 | SHARP, IMG_3BY32_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_5 | NORMAL, IMG_3BY32_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_5 | FLAT, IMG_3BY32_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_3BY32 | OCTAVE_5 | SHARP, IMG_3BY32_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_3 | NORMAL, IMG_1BY16_OCT_L_M_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_3 | FLAT, IMG_1BY16_OCT_L_M_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_3 | SHARP, IMG_1BY16_OCT_L_M_S - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_5 | NORMAL, IMG_1BY16_OCT_U_N - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_5 | FLAT, IMG_1BY16_OCT_U_F - COMPOSE_RING_TONE_ENGINE_BASE},
    {DURATION_1BY16 | OCTAVE_5 | SHARP, IMG_1BY16_OCT_U_S - COMPOSE_RING_TONE_ENGINE_BASE},

/********************Rest Notes********/
    {DURATION_3BY8 | OCTAVE_3, IMG_3BY8_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY4 | OCTAVE_3, IMG_1BY4_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY16 | OCTAVE_3, IMG_3BY16_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY8 | OCTAVE_3, IMG_1BY8_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_3BY32 | OCTAVE_3, IMG_3BY32_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},

    {DURATION_1BY16 | OCTAVE_3, IMG_1BY16_OCT_L_M - COMPOSE_RING_TONE_ENGINE_BASE},
/*********************************Rest Notes End***************/

};

const PS8 gRngcMusicalNote[] = 
{
    "c", "d", "e", "f", "g", "a", "b", "r", "vibeon", "vibeoff", "ledon", "ledoff", "backon", "backoff"
};
const PS8 gRngcDuration[] = 
{
    "0.", "0", "1.", "1", "2.", "2", "3.", "3", "4.", "4"
};

const U8 CurrentInstrument[] = 
{
    INSTR_PIANO,
    INSTR_GUITAR,
    INSTR_VIOLIN,
    INSTR_SPHONE,
    INSTR_SDRUMS,
    INSTR_FLUTE,
    INSTR_HARMONICA,
    INSTR_TRUMPET,
    INSTR_MUSICBOX,
    INSTR_XYLOPHONE
};

extern void mmi_rngc_HandleKey_LEFT_down_hdlr(void);
extern void mmi_rngc_HandleKey_LEFT_up_hdlr(void);

#if defined(__MMI_TOUCH_RING_COMPOSER__)
extern void mmi_rngc_finish_insert_editing(void);
#endif 

extern void InitializeComposerSkinLayout(void);

/*****************************************************************************
 * FUNCTION
 *  EntryRngcComposerEngine
 * DESCRIPTION
 *  Entry function of editor screen in ring tone composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcComposerEngine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    InitializeComposerSkinLayout();

    /* first time of entering */
    if (g_rngc_eng_cntx == NULL)
    {
        g_rngc_eng_cntx = OslMalloc(sizeof(rngc_engine_context_struct));

        if (g_rngc_eng_cntx == NULL)
        {
            return;
        }

        EntryNewScreen(SCR_COMPOSER_ENGINE, ExitRngcComposerEngine, NULL, NULL);
        InitializeComposer();
        SetRingComposer(
            STR_RING_COMPOSE_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_rngc_cntx.CurrInstr,
            MAX_NOTES,
            guiBuffer);
        g_rngc_eng_cntx->CurrUIPos = 0;
        redraw_ringcomposer();
    }
    else
    {
        EntryNewScreen(SCR_COMPOSER_ENGINE, ExitRngcComposerEngine, NULL, NULL);
        SetRingComposer(
            STR_RING_COMPOSE_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_rngc_cntx.CurrInstr,
            (MAX_NOTES - g_rngc_eng_cntx->TotalNotes),
            guiBuffer);
        if (g_rngc_eng_cntx->TotalNotes)
        {
            RedrawNotes();
            ChangeRightSoftkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_CLEAR);
        }
        else
        {
            g_rngc_eng_cntx->CurrUIPos = 0;
            redraw_ringcomposer();
        }
    }

    mdi_audio_suspend_background_play();
    g_rngc_eng_cntx->IsSefLeftKeyDown = FALSE;
    
    SetKeyHandler(HandleKey_0, KEY_0, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_1, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_2, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_3, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_4, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_5, KEY_5, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_6, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_7, KEY_7, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_8, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_9, KEY_9, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_STAR, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_POUND, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_UP, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_DOWN, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_rngc_HandleKey_LEFT_down_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_rngc_HandleKey_LEFT_up_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_RIGHT, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(HandleKey_END, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(HandleKey_CLEARLONG, KEY_RSK, KEY_LONG_PRESS);

    SetRightSoftkeyFunction(RngcComposerRSKUpHandler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(RngcComposerRSKDownHandler, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(EntryRngcCompToneOptList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitRngcComposerEngine
 * DESCRIPTION
 *  Exit function of editor screen in ring tone composer
 *  1. Stop playing tone
 *  2. Reset IsKeyPadAudioDisable;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitRngcComposerEngine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history ScrComposer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef RNGC_HAS_INST_RECTANGLE
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/
#endif /*RNGC_HAS_INST_RECTANGLE*/

    StopTimer(NOTE_MULTITAP_TIMER);

    mdi_audio_stop_string();
    mdi_audio_resume_background_play();

    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    ScrComposer.scrnID = SCR_COMPOSER_ENGINE;
    ScrComposer.entryFuncPtr = EntryRngcComposerEngine;
    mmi_ucs2cpy((S8*) ScrComposer.inputBuffer, (S8*) L"");

#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (selection_area_context == &note_selection_layout)
    {
        selection_area_context->custom_keys[2].key_image = IMG_TOUCH_RING_DOWN;
    }
    selection_area_context = &normal_toolbar_layout;
    touch_rngc_context.area_type = GUI_RNGC_NORMAL_TOOLBAR;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

    /* stop instrument horizontal select scrolling */
    wgui_text_menuitem_reset_scrolling();
    
    AddHistory(ScrComposer);
    RedrawCategoryFunction = MMI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  RngcClearStave
 * DESCRIPTION
 *  Clear all notes in stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcClearStave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->TotalNotes = 0;
    g_rngc_eng_cntx->CurrNoteIndex = 0;
    g_rngc_eng_cntx->CurrUIPos = 0;
    g_rngc_eng_cntx->IsRskLP = 0;
    memset(g_rngc_eng_cntx->NotesList, 0xFF, sizeof(g_rngc_eng_cntx->NotesList));
}


/*****************************************************************************
 * FUNCTION
 *  RngcInitCursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcInitCursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 width, height;
    PU8 img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the maximum size of cursor */
    g_rngc_eng_cntx->CursorWidth = 0;
    for (i = IMG_3BY2_OCT_L_M_N; i <= IMG_RING_EVENTVIB_OFF; i++)
    {
        img = (PU8) GetImage(i);
        gui_measure_image(img, &width, &height);
        if (g_rngc_eng_cntx->CursorWidth < width)
        {
            g_rngc_eng_cntx->CursorWidth = (U8) width;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitializeComposerSkinLayout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeComposerSkinLayout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 title_bar_y1, title_bar_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifdef GUI_COMMON_USE_THICK_TITLE
    title_bar_y1 = 0;
    title_bar_height = MMI_THICK_TITLE_HEIGHT;
#else /*GUI_COMMON_USE_THICK_TITLE*/
    title_bar_y1 = MMI_title_y;
    title_bar_height = MMI_title_height;
#endif /*GUI_COMMON_USE_THICK_TITLE*/

#if  defined(__MMI_MAINLCD_240X320__)
    /*main background image*/
    g_rngc_skin_layout.main_bg_img_id = IMG_RING_COMPOSER_BACKGROUND;
    g_rngc_skin_layout.main_bg_img_area_y1 = title_bar_y1 + title_bar_height;
    g_rngc_skin_layout.main_bg_img_area_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT;

    /*the retangle around stave coordinate*/
    g_rngc_skin_layout.stave_rectangle_y1 = title_bar_y1 + title_bar_height + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT + RNGC_INSTR_SELECT_MARGIN * 2 + NOTE_BAR_HEIGHT + 5;
    g_rngc_skin_layout.stave_rectangle_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT;

    /*if draw backgourd rectangle for indicating remaining notes number*/
    g_rngc_skin_layout.is_draw_notes_rect_bg_color = MMI_FALSE;
    g_rngc_skin_layout.remain_notes_rect_y1 = title_bar_y1 + title_bar_height + RNGC_INSTR_SELECT_MARGIN * 2 + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT;
    g_rngc_skin_layout.remain_notes_rect_height = NOTE_BAR_HEIGHT;

    /*if draw instrument select rectangle */
    g_rngc_skin_layout.instr_sel_rect_y1 = title_bar_y1 + title_bar_height + 2;
    g_rngc_skin_layout.instr_sel_rect_y2 = g_rngc_skin_layout.instr_sel_rect_y1 + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT;
    g_rngc_skin_layout.instr_img_x1 = RNGC_INSTR_SELECT_X_OFFSET*2;

    g_rngc_skin_layout.title_rect_y1 = title_bar_y1;
    g_rngc_skin_layout.title_rect_height = title_bar_height;
    
#elif defined(__MMI_MAINLCD_320X240__)
    title_bar_height = 31;
    /*main background image*/
    g_rngc_skin_layout.main_bg_img_id = IMG_RING_COMPOSER_BACKGROUND;
    g_rngc_skin_layout.main_bg_img_area_y1 = 0;
    /*TRICK: y2 add 2 is because in redraw_ringcompser had decrease 2 in other LCD*/
    g_rngc_skin_layout.main_bg_img_area_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT + 2;
 
    /*if draw backgourd rectangle for indicating remaining notes number*/
    g_rngc_skin_layout.is_draw_notes_rect_bg_color = MMI_FALSE;
    g_rngc_skin_layout.remain_notes_rect_y1 =  title_bar_height + RNGC_INSTR_SELECT_MARGIN * 2 + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT + 5;
    g_rngc_skin_layout.remain_notes_rect_height = NOTE_BAR_HEIGHT;

     /*the retangle around stave coordinate*/
    //g_rngc_skin_layout.stave_rectangle_y1 = title_bar_height + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT + NOTE_BAR_HEIGHT + 5;
    g_rngc_skin_layout.stave_rectangle_y1 = g_rngc_skin_layout.remain_notes_rect_y1 + NOTE_BAR_HEIGHT - 1;
    g_rngc_skin_layout.stave_rectangle_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT;

    /*if draw instrument select rectangle */
    g_rngc_skin_layout.instr_sel_rect_y1 = title_bar_height + RNGC_INSTR_SELECT_MARGIN;
    g_rngc_skin_layout.instr_sel_rect_y2 = g_rngc_skin_layout.instr_sel_rect_y1 + MMI_RNGC_INSTRUMENT_SELECT_HEIGHT;
    g_rngc_skin_layout.instr_img_x1 = RNGC_INSTR_SELECT_X_OFFSET*2;

    g_rngc_skin_layout.title_rect_y1 = 0;
    g_rngc_skin_layout.title_rect_height = title_bar_height;
    
#else /*defined(__MMI_MAINLCD_320X240__) */
    /*main background image*/
#if defined ( __MMI_TOUCH_RING_COMPOSER__) && defined (__MMI_MAINLCD_176X220__) 
    g_rngc_skin_layout.main_bg_img_id = IMG_TOUCH_RING_COMPOSER_BACKGROUND,
#else /*defined ( __MMI_TOUCH_RING_COMPOSER__) && defined (__MMI_MAINLCD_176X220__)*/
    g_rngc_skin_layout.main_bg_img_id = IMG_RING_COMPOSER_BACKGROUND, 
#endif /*defined ( __MMI_TOUCH_RING_COMPOSER__) && defined (__MMI_MAINLCD_176X220__)*/
    g_rngc_skin_layout.main_bg_img_area_y1 = BKG_IMG_Y1;
    g_rngc_skin_layout.main_bg_img_area_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT;

    /*the retangle around stave coordinate*/
    g_rngc_skin_layout.stave_rectangle_y1 = (title_bar_y1 + title_bar_height) + NOTE_BAR_HEIGHT + 4;
    g_rngc_skin_layout.stave_rectangle_y2 = UI_device_height - MMI_BUTTON_BAR_HEIGHT;
    
    /*if draw backgourd rectangle for indicating remaining notes number*/
    g_rngc_skin_layout.is_draw_notes_rect_bg_color = MMI_TRUE;
    g_rngc_skin_layout.remain_notes_rect_y1 = title_bar_y1 + title_bar_height;
    g_rngc_skin_layout.remain_notes_rect_height = NOTE_BAR_HEIGHT;
    
    /*if draw instrument select rectangle */
    g_rngc_skin_layout.instr_sel_rect_y1 = 0;
    g_rngc_skin_layout.instr_sel_rect_y2 = 0;
    g_rngc_skin_layout.instr_img_x1 = 0;

    g_rngc_skin_layout.title_rect_y1 = title_bar_y1;
    g_rngc_skin_layout.title_rect_height = title_bar_height;
#endif /*defined(__MMI_MAINLCD_240X320__) */

}


/*****************************************************************************
 * FUNCTION
 *  InitializeComposer
 * DESCRIPTION
 *  This function is to reset state and global variables used in composed engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeComposer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcInitCursor();
    RngcClearStave();
    g_rngc_cntx.CurrSpeed = NORMAL_SPEED;
    g_rngc_cntx.CurrInstr = INSTR_PIANO;

}

#ifdef __MMI_TOUCH_RING_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_touch_rngc_setup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touch_rngc_setup(touch_rngc_struct *touch_rngc_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_rngc_context->flag = 0;
    touch_rngc_context->flag |= RNGC_SELECTION_AREA_REDRAW;
    touch_rngc_context->mode = GUI_RNGC_VIEW;
    if (touch_rngc_context->play_mode != RNGC_PAUSE)
    {
        selection_area_context = &normal_toolbar_layout;
        touch_rngc_context->area_type = GUI_RNGC_NORMAL_TOOLBAR;
    }
    touch_rngc_context->play_mode = RNGC_PLAY;
}
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  HandleKey_CLEARLONG
 * DESCRIPTION
 *  Handler of long-pressed RSK.
 *  1. clear all notes and reset all state varilables.
 *  2. redraw screen and set RSK to Back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_CLEARLONG(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes != 0)   /* not cleared yet */
    {
        RngcClearStave();
        g_rngc_eng_cntx->CurrUIPos = 0;

        RedrawNotes();
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        g_rngc_eng_cntx->IsRskLP = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  FreeMemory
 * DESCRIPTION
 *  Free allocated memory to stored composed information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeMemory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx)
    {
        OslMfree(g_rngc_eng_cntx);
        g_rngc_eng_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcComposerRSKUpHandler
 * DESCRIPTION
 *  Event handler of RSK up when composing ring tone
 *  If there is no musical note and RSK is not long pressed, go back to previous screen
 *  otherwise, reset state flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerRSKUpHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes == 0 && g_rngc_eng_cntx->IsRskLP == 0)
    {
        FreeMemory();
        StopTimer(NOTE_MULTITAP_TIMER);

        if (g_rngc_cntx.CurrEditState == ENUM_COMP_ADD)
        {
            GoBackToHistory(SCR_FMGR_EXPLORER);
        }
        else
        {
            GoBackHistory();
        }
    }
    else if (g_rngc_eng_cntx->IsRskLP == 1)
    {
        g_rngc_eng_cntx->IsRskLP = 0;
    }

#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        touch_rngc_context.mode = GUI_RNGC_INSERT;
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  RngcComposerRSKDownHandler
 * DESCRIPTION
 *  Event handler of RSK down when composing ring tone
 *  Delete one musical note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerRSKDownHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes)
    {
        DeleteCurNote();

        /* change RSK to "Back" if there is no note */
        if (!g_rngc_eng_cntx->TotalNotes)
        {
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            g_rngc_eng_cntx->IsRskLP = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeleteCurNote
 * DESCRIPTION
 *  Event handler of RSK down when composing ring tone
 *  Delete one musical note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteCurNote(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes)
    {
        /* highlight on the last one */
        if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
        {
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = 0xFFFF;
        }
        else    /* internal note */
        {
            memcpy(
                (g_rngc_eng_cntx->NotesList + g_rngc_eng_cntx->CurrNoteIndex),
                (g_rngc_eng_cntx->NotesList + (g_rngc_eng_cntx->CurrNoteIndex + 1)),
                (g_rngc_eng_cntx->TotalNotes - g_rngc_eng_cntx->CurrNoteIndex) * sizeof(U16));
        }
        --g_rngc_eng_cntx->TotalNotes;
    }
    else if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes)
    {
#if 0
    #ifdef __MMI_TOUCH_RING_COMPOSER__
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
#else
        g_rngc_eng_cntx->NotesList[--g_rngc_eng_cntx->CurrNoteIndex] = 0xFFFF;
#endif
        --g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->TotalNotes < g_rngc_eng_cntx->CurrUIPos)
        {
            --g_rngc_eng_cntx->CurrUIPos;
        }
    }
    GDI_LOCK;
    RedrawNotes();
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
        touch_rngc_context.mode == GUI_RNGC_INSERT ||
        touch_rngc_context.mode == GUI_RNGC_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  RngcPlayCurrentNodeCallBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RngcPlayCurrentNodeCallBack(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CurrentNodePlaying = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PlayCurrentNode
 * DESCRIPTION
 *  Play iMelody stream of current input note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PlayCurrentNode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 pCurrentNode[512];    /* because audio interface does not make a copy, we have to prepare a buffer */
    U8 pNoteString[10];
    U8 *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (IsMeetingModeActivated() || IsSilentModeActivated())
        if ((g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK) < NOTE_REST)
        {
            return;
        }
#endif /* __MMI_SILENT_MEETING_PROFILE__ */ 

    memset(pNoteString, 0, 10);

    temp = GetStringForNode(pNoteString, g_rngc_eng_cntx->CurrNoteIndex);
    *temp = 0;
    /* generate iMelody string */
    sprintf(
        (S8*) pCurrentNode,
        "%sCOMPOSER:MTK(%d)\r\nBEAT:%d\r\nMELODY:",
        MELODY_HEADER,
        g_rngc_cntx.CurrInstr,
        g_rngc_cntx.CurrSpeed);
    if(0 == strcmp((S8*)pNoteString, (S8*)"vibeon"))
    {
       strcat((S8*)pNoteString, (S8*)"r2");
    }
    strcat((S8*) & pCurrentNode, (S8*) pNoteString);
    strcat((S8*) pCurrentNode, (S8*) MELODY_END);

    if (mdi_audio_play_string
        ((void*)pCurrentNode, strlen((S8*) pCurrentNode), MDI_FORMAT_IMELODY, DEVICE_AUDIO_PLAY_ONCE, NULL,
         RngcPlayCurrentNodeCallBack) == MDI_AUDIO_SUCCESS)
    {
        CurrentNodePlaying = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  InsertNote
 * DESCRIPTION
 *  Insert a note to screen accroding to current position
 * PARAMETERS
 *  nNote       [IN]        Musical note symbol
 * RETURNS
 *  void
 *****************************************************************************/
void InsertNote(U16 nNote)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(NOTE_MULTITAP_TIMER);
    if (g_rngc_eng_cntx->TotalNotes >= MAX_NOTES)
    {
        return;
    }

    /* internal note */
    if (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes)
    {
        /* shift one note right */
        for (nCount = g_rngc_eng_cntx->TotalNotes; nCount > g_rngc_eng_cntx->CurrNoteIndex; --nCount)
        {
            g_rngc_eng_cntx->NotesList[nCount] = g_rngc_eng_cntx->NotesList[nCount - 1];
        }
        
#ifdef __MMI_RNGC_INSERT_AFTER_CURSOR__
   
        /* insert note */
        ++g_rngc_eng_cntx->CurrNoteIndex;
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;
        PlayCurrentNode();
        
        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrUIPos;
        }
#else
        /* insert note */
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;        
        PlayCurrentNode();       
        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

    #ifdef __MMI_TOUCH_RING_COMPOSER__
        if(touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            /* only move cursor for inputs from keypad */
            ++g_rngc_eng_cntx->CurrNoteIndex;
            if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
            {
                ++g_rngc_eng_cntx->CurrUIPos;
            } 
        }
    #else/* __MMI_TOUCH_RING_COMPOSER__ */
    
        /* move cursor */
        ++g_rngc_eng_cntx->CurrNoteIndex;
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrUIPos;
        }    
    #endif /*__MMI_TOUCH_RING_COMPOSER__ */    
#endif /* __MMI_RNGC_INSERT_AFTER_CURSOR__ */

        RedrawNotes();
    }
    else    /* last note */
    {
        /* insert note */
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = nNote;

        /* increase total number of notes */
        ++g_rngc_eng_cntx->TotalNotes;

        if (g_rngc_eng_cntx->TotalNotes == 1)
        {
            change_right_softkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_CLEAR);
        }

        PlayCurrentNode();
        
#ifdef __MMI_RNGC_INSERT_AFTER_CURSOR__

        ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);

#else /* __MMI_RNGC_INSERT_AFTER_CURSOR__ */
    #ifdef __MMI_TOUCH_RING_COMPOSER__
    
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1 && touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
            ++g_rngc_eng_cntx->CurrUIPos;
        }
        else if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1 &&
                 g_rngc_eng_cntx->CurrNoteIndex < MAX_NOTES - 1 &&
                 touch_rngc_context.mode != GUI_RNGC_INSERT_EDIT)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
        }
    #else /* __MMI_TOUCH_RING_COMPOSER__ */
    
        if (g_rngc_eng_cntx->CurrUIPos < NUM_NOTES_IN_STAVE - 1)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
            ++g_rngc_eng_cntx->CurrUIPos;
        }
        else if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1 &&
                 g_rngc_eng_cntx->CurrNoteIndex < MAX_NOTES - 1)
        {
            ++g_rngc_eng_cntx->CurrNoteIndex;
        }
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */
    
        RedrawNotes();
    
#endif /* __MMI_RNGC_INSERT_AFTER_CURSOR__*/
        
    }

#if !defined (__MMI_TOUCH_RING_COMPOSER__) && !defined (__MMI_RNGC_INSERT_AFTER_CURSOR__)
    /* auto shift cursor if a note is insert at the end */
    if ((g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1 ||
        g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes) && 
        g_rngc_eng_cntx->TotalNotes < MAX_NOTES)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT);
    }
#endif /* !defined (__MMI_TOUCH_RING_COMPOSER__) && !defined (__MMI_RNGC_INSERT_AFTER_CURSOR__)*/ 
}


/*****************************************************************************
 * FUNCTION
 *  RedrawNotes
 * DESCRIPTION
 *  This function is to redraw the stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawNotes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirstNoteIndex;
    S16 nEndNote;
    U16 nTemp;
    U16 nImageId = 0;
    U16 nCount = 0;
    U8 nYVal = 0;
    DisplayInfo sDisplayInfo[NUM_NOTES_IN_STAVE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the first note to be drawed */
    nFirstNoteIndex = g_rngc_eng_cntx->CurrNoteIndex - g_rngc_eng_cntx->CurrUIPos;
    if (nFirstNoteIndex < 0)
    {
        nFirstNoteIndex = 0;
    }

    /* get the last note to be drawed */
    if (nFirstNoteIndex + NUM_NOTES_IN_STAVE >= g_rngc_eng_cntx->TotalNotes)    /* tail */
    {
        nEndNote = g_rngc_eng_cntx->TotalNotes - 1;
    }
    else
    {
        nEndNote = (nFirstNoteIndex + NUM_NOTES_IN_STAVE) - 1;
    }

    for (nTemp = nFirstNoteIndex; nTemp <= nEndNote; ++nTemp)
    {
        GetIndexInList(g_rngc_eng_cntx->NotesList[nTemp], &nImageId, &nYVal);
        sDisplayInfo[nCount].nImageId = nImageId;
        sDisplayInfo[nCount].nXPos = (U8) nTemp;
        sDisplayInfo[nCount].nYPos = nYVal;
        ++nCount;
    }

    RefreshNotesList(nCount, (DisplayInfo*) sDisplayInfo);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_0
 * DESCRIPTION
 *  Key event handler of number keys
 *  Insert corresponding musical note to stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_0(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_REST | DURATION_1BY4 | OCTAVE_4);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_1(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_C | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_2(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_D | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_3(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_E | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_4(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_F | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_5(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_G | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_6(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_A | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_7(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_B | DURATION_1BY4 | OCTAVE_4 | NORMAL);
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_8(void)
{
#ifndef __MMI_RING_COMPOSER_NO_VIB__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    InsertNote(NOTE_VIBRATION_ON);
#endif /* __MMI_RING_COMPOSER_NO_VIB__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_9
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_9(void)
{
#ifdef __MMI_TOUCH_RING_COMPOSER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        mmi_rngc_finish_insert_editing();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
    InsertNote(NOTE_LED_ON);
#else
    InsertNote(NOTE_BACKLIGHT_ON);
#endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_END
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_END(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeMemory();
    StopTimer(NOTE_MULTITAP_TIMER);
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_STAR
 * DESCRIPTION
 *  Start key handler
 *  Change note duration/type according to highlighted note.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_STAR(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }

    /* highlighted on empty position */
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    switch (nValue)
    {
        case NOTE_LED_ON:
            SetBackLightOn();
            break;
        case NOTE_LED_OFF:
            SetBackLightOff();
            break;
    
        case NOTE_BACKLIGHT_ON:
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
            SetLEDOn();
    #endif /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
            break;
        case NOTE_BACKLIGHT_OFF:
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
            SetLEDOff();
    #endif /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
            break;

        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
            IncrementNoteBeat()break;
        case NOTE_REST:
            IncrementRestBeat()break;
        default:
            return; /* vib/led/backlight, return. */
    }

    PlayCurrentNode();

    ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_POUND
 * DESCRIPTION
 *  Pound key handler
 *  change flag/sharp/normal state of a musical note
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_POUND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;
    U32 nNoteType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }

    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);
    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteType = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;

    switch (nValue)
    {
        case NOTE_C:
        case NOTE_F:
            if (nNoteType == NORMAL)
                SetNoteType(SHARP)
                else
                SetNoteType(NORMAL) break;
        case NOTE_D:
        case NOTE_G:
        case NOTE_A:
            if (nNoteType == NORMAL)
                SetNoteType(FLAT)
                else
            if (nNoteType == FLAT)
                SetNoteType(SHARP)
                else
                SetNoteType(NORMAL) break;
        case NOTE_B:
        case NOTE_E:
            if (nNoteType == NORMAL)
                SetNoteType(FLAT)
                else
                SetNoteType(NORMAL) break;
        default:    /* other notes, pound key does not effect */
#if 0
/* under construction !*/
#else   
            return; /* vib/led/backlight, return. */
#endif
    }

    PlayCurrentNode();

    ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_UP
 * DESCRIPTION
 *  Up key handler
 *  Change on/off for vibration/backlight/led notes
 *  Change octave for musical notes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_UP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }
    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;

    switch (nValue)
    {
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
        case NOTE_LED_OFF:
            SetLEDOn();
            break;
    #endif /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
            
        case NOTE_BACKLIGHT_OFF:
            SetBackLightOn();
            break;
        case NOTE_VIBRATION_OFF:
            SetVibrationOn();
            break;
        case NOTE_REST:
            break;
        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
            if (nNoteOctave == OCTAVE_3)
            {
                SetOctave(OCTAVE_4)
            }
            else if (nNoteOctave == OCTAVE_4)
            {
                SetOctave(OCTAVE_5)
            }
            else if (nNoteOctave == OCTAVE_5)
            {
                SetOctave(OCTAVE_3)
            }   
            break;
        default:
            break;
    }

    PlayCurrentNode();
    ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    /* after pressing up key should not move the cursor */
#ifndef __MMI_TOUCH_RING_COMPOSER__
    if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT);
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_DOWN
 * DESCRIPTION
 *  Up key handler
 *  Change on/off for vibration/backlight/led notes
 *  Change octave for musical notes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_DOWN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }

    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }
    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;

    switch (nValue)
    {
    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
        case NOTE_LED_ON:
            SetLEDOff();
            break;
    #endif /* #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__ */

        case NOTE_BACKLIGHT_ON:
            SetBackLightOff();
            break;
        case NOTE_VIBRATION_ON:
            SetVibrationOff();
            break;
        case NOTE_REST:
            break;
        case NOTE_C:
        case NOTE_D:
        case NOTE_E:
        case NOTE_F:
        case NOTE_G:
        case NOTE_A:
        case NOTE_B:
        {
            if (nNoteOctave == OCTAVE_3)
                SetOctave(OCTAVE_5)
                else
            if (nNoteOctave == OCTAVE_4)
                SetOctave(OCTAVE_3)
                else
            if (nNoteOctave == OCTAVE_5)
                SetOctave(OCTAVE_4) break;
        }
        default:
            break;
    }

    PlayCurrentNode();
    ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    /* after pressing down key should not move the cursor */
#ifndef __MMI_TOUCH_RING_COMPOSER__
    if (g_rngc_eng_cntx->CurrNoteIndex == g_rngc_eng_cntx->TotalNotes - 1)
    {
        StartTimer(NOTE_MULTITAP_TIMER, MULTITAP_TIME, (FuncPtr) HandleKey_RIGHT);
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_HandleKey_LEFT_down_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_HandleKey_LEFT_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->IsSefLeftKeyDown = TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_HandleKey_LEFT_up_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_HandleKey_LEFT_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Add check whether self key down event*/
    if(TRUE == g_rngc_eng_cntx->IsSefLeftKeyDown)
    {
        g_rngc_eng_cntx->IsSefLeftKeyDown = FALSE;
        HandleKey_LEFT();
    }
    /*End:check*/
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_LEFT
 * DESCRIPTION
 *  Left key handler
 *  Move cursor left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_LEFT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DisplayInfo sDisplayInfo[NUM_NOTES_IN_STAVE];
    U16 nTemp;
    U16 nEnd;
    U16 nImageId = 0;
    U8 nYVal = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(NOTE_MULTITAP_TIMER);

    if (g_rngc_eng_cntx->CurrNoteIndex > 0)
    {
        --g_rngc_eng_cntx->CurrNoteIndex;

        if (g_rngc_eng_cntx->CurrUIPos == 0)
        {
            nTemp = g_rngc_eng_cntx->TotalNotes - g_rngc_eng_cntx->CurrNoteIndex;
            if (nTemp >= NUM_NOTES_IN_STAVE)
            {
                nEnd = NUM_NOTES_IN_STAVE;
            }
            else
            {
                nEnd = nTemp;
            }

            for (nTemp = 0; nTemp < nEnd; ++nTemp)
            {
                GetIndexInList(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex + nTemp], &nImageId, &nYVal);
                sDisplayInfo[nTemp].nImageId = nImageId;
                sDisplayInfo[nTemp].nXPos = (U8) nTemp;
                sDisplayInfo[nTemp].nYPos = nYVal;

            }
            RefreshNotesList(nEnd, (DisplayInfo*) & sDisplayInfo);
        }
        else
        {
            --g_rngc_eng_cntx->CurrUIPos;
            redraw_ringcomposer();
        }
    #ifdef __MMI_TOUCH_RING_COMPOSER__
        if ( /* touch_rngc_context.mode == GUI_RNGC_EDIT || */ touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
            touch_rngc_context.mode == GUI_RNGC_INSERT)
        {
            mmi_rngc_finish_insert_editing();
        }
    #endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleKey_RIGHT
 * DESCRIPTION
 *  Right key handler
 *  Move cursor right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleKey_RIGHT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* already in right boundary */
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF ||
        g_rngc_eng_cntx->CurrNoteIndex + 1 >= MAX_NOTES)
    {
        return;
    }

    StopTimer(NOTE_MULTITAP_TIMER);

    if (g_rngc_eng_cntx->CurrNoteIndex < (g_rngc_eng_cntx->TotalNotes))
    {
        ++g_rngc_eng_cntx->CurrNoteIndex;

        if (g_rngc_eng_cntx->CurrUIPos == NUM_NOTES_IN_STAVE - 1)
        {
            /* handle the right movement */
            RedrawNotes();
        }
        else
        {
            ++g_rngc_eng_cntx->CurrUIPos;
            redraw_ringcomposer();
        }
    }
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if ( /* touch_rngc_context.mode == GUI_RNGC_EDIT || */ touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
        touch_rngc_context.mode == GUI_RNGC_INSERT)
    {
        mmi_rngc_finish_insert_editing();
    }
    if ((touch_rngc_context.mode == GUI_RNGC_EDIT)
        && (g_rngc_eng_cntx->CurrNoteIndex >= g_rngc_eng_cntx->TotalNotes))
    {
        touch_rngc_context.area_type = GUI_RNGC_NORMAL_TOOLBAR;
        selection_area_context = &normal_toolbar_layout;
        touch_rngc_context.mode = GUI_RNGC_VIEW;
        touch_rngc_context.play_mode = RNGC_PLAY;
        touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
        redraw_ringcomposer();
    }    
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GenerateMelodyFile
 * DESCRIPTION
 *  Generate and write iMelody file to file system
 * PARAMETERS
 *  pFileName       [IN]        Filename
 * RETURNS
 *  enum value of result
 *****************************************************************************/
S32 GenerateMelodyFile(PS8 pFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMelody = NULL;
    S32 err = 0;
    U16 nSize = 0;
    U32 wByte = 0;
    S8 tmpBuff[100];
    S8 FileNameBuff[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* generate filename */

    GenerateCompleteComposeFileName((PS8) pFileName, (PS8) FileNameBuff);
    if ((err = RngcCreateDir()) != FS_NO_ERROR)
    {
        return err;
    }

    fileHandle = FS_Open((U16*) FileNameBuff, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (fileHandle > FS_NO_ERROR)
    {
        /* write header */
        err = FS_Write(fileHandle, MELODY_HEADER, AsciiStrlen((const S8*)MELODY_HEADER), &wByte);
        if (err == 0)
        {
            sprintf(
                (PS8) tmpBuff,
                "COMPOSER:MTK(%d)\r\nBEAT:%d\r\nMELODY:",
                g_rngc_cntx.CurrInstr,
                g_rngc_cntx.CurrSpeed);
            FS_Write(fileHandle, tmpBuff, AsciiStrlen((const S8*)tmpBuff), &wByte);
        }

        /* generate iMelody string */
        if (err == 0)
        {
            pMelody = OslMalloc(g_rngc_eng_cntx->TotalNotes * 7);
            nSize = GetMelodyFromStruct((PU8) pMelody, (U16) (g_rngc_eng_cntx->TotalNotes * 7));

            err = FS_Write(fileHandle, pMelody, nSize, &wByte);
            OslMfree(pMelody);
        }

        /* write tail */
        if (err == 0)
        {
            err = FS_Write(fileHandle, MELODY_END, AsciiStrlen((const S8*)MELODY_END), &wByte);
        }

        FS_Close(fileHandle);

        if (err < 0)
        {
            FS_Delete((U16*) FileNameBuff);
        }
    }
    else
    {
        err = (S32) fileHandle;
    }

    return err;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateCompleteComposeFileName
 * DESCRIPTION
 *  Generate complete file path+name
 * PARAMETERS
 *  pFileName           [IN]            Filename
 *  pCompletePath       [IN/OUT]        Comple filename+path
 * RETURNS
 *  void
 *****************************************************************************/
void GenerateCompleteComposeFileName(PS8 pFileName, PS8 pCompletePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) pCompletePath, (S8*) RINGCOMPOSER_PATH);
    mmi_ucs2cat((S8*) pCompletePath, (S8*) pFileName);
}


/*****************************************************************************
 * FUNCTION
 *  EditMelody
 * DESCRIPTION
 *  Read an iMelody file and convert to the structure used in program
 *  Display ring tone composer stave
 * PARAMETERS
 *  pFileName       [IN]        Filename
 * RETURNS
 *  void
 *****************************************************************************/
void EditMelody(U8 *pFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMelody = NULL;
    FS_HANDLE fileHandle;
    S32 nFileSize;
    U32 nEror = 0;
    S8 FilleNameBuff[MAX_IMAGE_NAME_PATH_WIDTH + RNGC_FILE_LEN];        /* padding for filepath */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenerateCompleteComposeFileName((PS8) pFileName, (PS8) FilleNameBuff);
#ifdef __DRM_SUPPORT__
    if (DRM_METHOD_NONE != DRM_get_object_method(0, (PU16)FilleNameBuff))
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    fileHandle = FS_Open((U16*) FilleNameBuff, FS_READ_ONLY);
    if (fileHandle > FS_NO_ERROR)
    {
        FS_GetFileSize(fileHandle, (UINT *)&nFileSize);
        if (nFileSize >= RNGC_MAX_FILE_LEN)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_INVALID_FORMAT),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            FS_Close(fileHandle);
            return;
        }

        pMelody = OslMalloc(nFileSize + 1);

        if (g_rngc_eng_cntx == NULL)
        {
            g_rngc_eng_cntx = OslMalloc(sizeof(rngc_engine_context_struct));
        }
        FS_Read(fileHandle, pMelody, nFileSize, &nEror);
        pMelody[nFileSize] = 0;
        FS_Close(fileHandle);
        g_rngc_eng_cntx->TotalNotes = 0;
        g_rngc_eng_cntx->CurrNoteIndex = 0;
        g_rngc_eng_cntx->CurrUIPos = 0;
        g_rngc_eng_cntx->IsRskLP = 0;
        RngcInitCursor();
        memset(g_rngc_eng_cntx->NotesList, 0, sizeof(g_rngc_eng_cntx->NotesList));
        g_rngc_cntx.CurrInstr = INSTR_FLUTE;    /* to sync with media task */
        if (GetComposerStructFromMelody((PU8) pMelody))
        {
            memset(
                (void*)(g_rngc_eng_cntx->NotesList + g_rngc_eng_cntx->TotalNotes),
                0xFF,
                sizeof(g_rngc_eng_cntx->NotesList) - (sizeof(U16) * (g_rngc_eng_cntx->TotalNotes)));

            if (g_rngc_eng_cntx->CurrNoteIndex >= NUM_NOTES_IN_STAVE)
            {
                g_rngc_eng_cntx->CurrUIPos = NUM_NOTES_IN_STAVE - 1;
            }
            else
            {
                g_rngc_eng_cntx->CurrUIPos = g_rngc_eng_cntx->CurrNoteIndex;
            }

            EntryRngcComposerEngine();
        }
        else
        {
            OslMfree(g_rngc_eng_cntx);
            g_rngc_eng_cntx = NULL;
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_INVALID_FORMAT),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }

        OslMfree(pMelody);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(fileHandle)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexInList
 * DESCRIPTION
 *  This function is to retreive duration/note symbol/octave/type of a musical node
 * PARAMETERS
 *  nNote           [IN]            The value of the musical note
 *  pImageId        [IN/OUT]        Image id to be display for the musical note
 *  pYVal           [IN/OUT]        The y-coordinate of the musical note
 * RETURNS
 *  void
 *****************************************************************************/
void GetIndexInList(U16 nNote, U16 *pImageId, U8 *pYVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nListCount = 0;
    U32 nNoteOctave;
    U32 nValue;
    U32 nDuration;
    U32 nNoteType;
    U32 nIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nDuration = nNote & DURATION_MASK;
    nValue = nNote & NOTE_MASK;
    nNoteOctave = nNote & OCTAVE_MASK;
    nNoteType = nNote & NOTETYPE_MASK;

    /* vibe, backlight, led */
    if (nValue >= NOTE_VIBRATION_ON)
    {
        switch (nValue)
        {
            case NOTE_VIBRATION_ON:
                *pImageId = IMG_RING_EVENTVIB_ON;
                break;
            case NOTE_VIBRATION_OFF:
                *pImageId = IMG_RING_EVENTVIB_OFF;
                break;
            case NOTE_LED_ON:
                *pImageId = IMG_RING_EVENTLED_ON;
                break;
            case NOTE_LED_OFF:
                *pImageId = IMG_RING_EVENTLED_OFF;
                break;
            case NOTE_BACKLIGHT_ON:
                *pImageId = IMG_RING_EVENTBL_ON;
                break;
            case NOTE_BACKLIGHT_OFF:
                *pImageId = IMG_RING_EVENTBL_OFF;
                break;
            default:
                break;
        }

        *pYVal = RNGC_EFFECT_NOTE_OFFSET;
        return;
    }

    /* OCTAVE_4 and OCTAVE_3 use the same symbol */
#ifdef  RNGC_NOTE_STYLE_STANDARD
    if (nNoteOctave == OCTAVE_4)    /* only octave 4 use the normal musical note */
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else if (nValue == 1 && nNoteOctave == OCTAVE_3)
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else
    {
        nIndex = nNoteType | OCTAVE_5 | nDuration;
    }
#else /*RNGC_NOTE_STYLE_STANDARD*/
    if (nNoteOctave == OCTAVE_4)
    {
        nIndex = nNoteType | OCTAVE_3 | nDuration;
    }
    else
    {
        nIndex = nNoteType | nNoteOctave | nDuration;
    }
#endif  /*RNGC_NOTE_STYLE_STANDARD*/

    for (nListCount = 0; nListCount < sizeof(gNotesList); nListCount++)
    {
        if (gNotesList[nListCount].nNote == nIndex)
        {
            nNoteOctave = nNoteOctave >> 6;
            if (nValue == NOTE_REST)
            {
                if (nDuration == DURATION_3BY8 || nDuration == DURATION_1BY4)
                {
                    *pYVal = gnYCoords[21];
                }
                else if (nDuration == DURATION_3BY16 || nDuration == DURATION_1BY8)
                {
                    *pYVal = gnYCoords[22];
                }
                else
                {
                    *pYVal = gnYCoords[23];
                }
            }
            else
            {
                *pYVal = gnYCoords[((nNoteOctave - 1) * 7 + nValue) - 1];
            }

            *pImageId = gNotesList[nListCount].nImageId + COMPOSE_RING_TONE_ENGINE_BASE;
            return;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetMelodyFromStruct
 * DESCRIPTION
 *  This function is to generate iMelody string for a given node
 * PARAMETERS
 *  pList           [IN/OUT]        Strating address to write the iMelody string
 *  nListSize       [IN]            Musical note
 * RETURNS
 *  address of current write cursor
 *****************************************************************************/
U16 GetMelodyFromStruct(U8 *pList, U16 nListSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount = 0;
    U8 *pNoteString = pList;
    U8 *pTemp;
    U16 nCurrentNode = g_rngc_eng_cntx->CurrNoteIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_eng_cntx->CurrNoteIndex = 0;
    while (nCount < g_rngc_eng_cntx->TotalNotes)
    {
        /* insert string of musical note to pNoteString */
        pTemp = GetStringForNode(pNoteString, g_rngc_eng_cntx->NotesList[nCount]);

        /* adjust location of string pointer */
        pNoteString += (pTemp - pNoteString);
        ++g_rngc_eng_cntx->CurrNoteIndex;
        ++nCount;
    }

    *pNoteString = 0;
    g_rngc_eng_cntx->CurrNoteIndex = nCurrentNode;

    return pNoteString - pList;
}


/*****************************************************************************
 * FUNCTION
 *  GetStringForNode
 * DESCRIPTION
 *  This function is to generate iMelody string for a given node
 * PARAMETERS
 *  pStr        [IN/OUT]        Strating address to write the iMelody string
 *  nNote       [IN]            Musical note
 * RETURNS
 *  address of current write cursor
 *****************************************************************************/
U8 *GetStringForNode(U8 *pStr, U32 nNote)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nNoteOctave;
    U32 nValue;
    U32 nDuration;
    U32 nNoteType;
    U8 *pNote = pStr;
    U16 len, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the current note shoulden be "0" */
    MMI_DBG_ASSERT(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] != 0);
    
    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nDuration = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & DURATION_MASK;
    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;
    nNoteType = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;

    /* octave */
    if (nNoteOctave == OCTAVE_3)
    {
        memcpy(pNote, "*3", 2);
        pNote += 2;
    }
    else if (nNoteOctave == OCTAVE_5)
    {
        memcpy(pNote, "*5", 2);
        pNote += 2;
    }

    /* note type */
    if (nNoteType == SHARP)
    {
        memcpy(pNote, "#", 1);
        pNote += 1;
    }
    else if (nNoteType == FLAT)
    {
        memcpy(pNote, "&", 1);
        pNote += 1;
    }

    index = (U16) (nValue - 1);
    len = strlen((PS8) gRngcMusicalNote[index]);
    memcpy(pNote, gRngcMusicalNote[index], len);
    pNote += len;

    if (nDuration > 0)
    {
        index = (U16) (nDuration / DURATION_3BY2 - 1);
        len = strlen((PS8) gRngcDuration[index]);
        memcpy(pNote, gRngcDuration[index], len);
        pNote += len;
    }
    return pNote;
}


/*****************************************************************************
 * FUNCTION
 *  GetComposerStructFromMelody
 * DESCRIPTION
 *  Parsing header of iMelody string, and convert to the structure used in this application
 * PARAMETERS
 *  pMelody     [IN]        IMelody string, including header
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 GetComposerStructFromMelody(U8 *pMelody)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = pMelody;
    U8 instrument;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!CompareMelody(&ptr, "BEGIN:"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "IMELODY"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "VERSION:"))
    {
        return FALSE;
    }

    if (!CompareMelody(&ptr, "1.0") && !CompareMelody(&ptr, "1.1") && !CompareMelody(&ptr, "1.2"))
    {
        return FALSE;
    }

    if (!CompareMelody(&ptr, "FORMAT:"))
    {
        return FALSE;
    }
    if (!CompareMelody(&ptr, "CLASS1.0") && !CompareMelody(&ptr, "CLASS2.0"))
    {
        return FALSE;
    }

    while (*ptr != 0)
    {
        if (CompareMelody(&ptr, "NAME:"))   /* ignore song name */
        {
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "COMPOSER:"))
        {   /* ignore composer name */
            g_rngc_cntx.CurrInstr = GetInstrument(&ptr);
            /* check instrument */
            for (instrument = 0; instrument < ENUM_TOTAL_INSTR; instrument++)
            {
                if ((U8) g_rngc_cntx.CurrInstr == CurrentInstrument[instrument])
                {
                    break;
                }
            }
            if( instrument == ENUM_TOTAL_INSTR)
            {
                return FALSE;
            }
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "BEAT:"))
        {
            g_rngc_cntx.CurrSpeed = (U8) GetBeat(&ptr);
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "STYLE:"))
        {
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "VOLUME:"))
        {
            ClearToEnd(&ptr);
        }
        else if (CompareMelody(&ptr, "MELODY:"))
        {
            if (GetMelody(&ptr) == FALSE)
            {
                return FALSE;
            }

            if (!CompareMelody(&ptr, "END:IMELODY"))
            {
                return FALSE;
            }
            break;
        }
        else
        {
            return FALSE;
        }
    }
    
    /* boundary check, CurrNoteIndex => [0,149]*/
    if (g_rngc_eng_cntx->CurrNoteIndex == MAX_NOTES)
    {
        g_rngc_eng_cntx->CurrNoteIndex--;
    }
    
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  GetMelody
 * DESCRIPTION
 *  Retrieve musical note according to the melody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 GetMelody(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 **ptr = pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (**ptr)
    {
        if (g_rngc_eng_cntx->TotalNotes == MAX_NOTES)
        {
            if (**ptr == 10 || **ptr == 13)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
        {
            return FALSE;
        }

        switch (**ptr)
        {
            case '*':
            {
                if (SetOctaveFromStream(pptr))
                {
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
            case 'b':
            {
                if (SetBackLight(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    if (SetNote(pptr))
                    {
                        ++g_rngc_eng_cntx->CurrNoteIndex;
                        ++g_rngc_eng_cntx->TotalNotes;
                        break;
                    }
                    else
                    {
                        return FALSE;
                    }
                }
            }
            case '&':
            case '#':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'a':
            case 'r':
            {
                if (SetNote(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
        #ifndef __MMI_RING_COMPOSER_NO_LED__
            case 'l':
            {
                if (SetLED(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
        #endif /* __MMI_RING_COMPOSER_NO_LED__ */ 
        #ifndef __MMI_RING_COMPOSER_NO_VIB__
            case 'v':
            {
                if (SetVibration(pptr))
                {
                    ++g_rngc_eng_cntx->CurrNoteIndex;
                    ++g_rngc_eng_cntx->TotalNotes;
                    break;
                }
                else
                {
                    return FALSE;
                }
            }
        #endif /* __MMI_RING_COMPOSER_NO_VIB__ */ 
            case 10:    /* 0x0A */
            case 13:    /* 0x0D */
                return TRUE;
            default:
                return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetBackLight
 * DESCRIPTION
 *  Insert a backlight node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetBackLight(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "backon", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_BACKLIGHT_ON;
        (*pptr) += 6;
    }
    else if (!StrnCmp((PS8) * pptr, "backoff", 7))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_BACKLIGHT_OFF;
        (*pptr) += 7;
    }
    else
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  SetVibration
 * DESCRIPTION
 *  Insert a vibration node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetVibration(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "vibeon", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_VIBRATION_ON;
        (*pptr) += 6;
    }
    else if (!StrnCmp((PS8) * pptr, "vibeoff", 7))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_VIBRATION_OFF;
        (*pptr) += 7;
    }
    else
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  SetLED
 * DESCRIPTION
 *  Insert an LED node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetLED(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "ledon", 5))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_LED_ON;
        (*pptr) += 5;
    }
    else if (!StrnCmp((PS8) * pptr, "ledoff", 6))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_LED_OFF;
        (*pptr) += 6;
    }
    else
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  SetNote
 * DESCRIPTION
 *  Insert a musical node to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetNote(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nDuration;
    U16 nNoteOctave;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return FALSE;
    }

    /* flag/normal/sharp */
    if (**pptr == '#')
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= SHARP;
        ++(*pptr);
    }
    else if (**pptr == '&')
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= FLAT;
        ++(*pptr);
    }
    else
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NORMAL;
    }

    /* musical notation */
    switch (**pptr)
    {
        case 'c':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] | NOTE_C;
            break;
        case 'd':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_D;
            break;
        case 'e':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_E;
            break;
        case 'f':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_F;
            break;
        case 'g':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_G;
            break;
        case 'a':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_A;
            break;
        case 'b':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_B;
            break;
        case 'r':
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_REST;
            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTETYPE_MASK;
            break;

        default:
            return FALSE;
    }

    /* duration */
    ++(*pptr);
    nDuration = GetInteger(pptr);

    switch (nDuration)
    {
        case 0:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY2;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1;
            }
            break;
        case 1:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY4;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY2;
            }
            break;
        case 2:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY8;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY4;
            }
            break;
        case 3:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY16;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY8;
            }
            break;
        case 4:
            if (**pptr == '.')
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_3BY32;
                ++(*pptr);
            }
            else
            {
                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= DURATION_1BY16;
            }
            break;
        default:
            return FALSE;
    }

    nNoteOctave = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;

    if (nNoteOctave != OCTAVE_3 && nNoteOctave != OCTAVE_5)
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_4;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetOctaveFromStream
 * DESCRIPTION
 *  Retrieve the octave of a musical node and save to gpComposer->NotesList
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  success or failed
 *****************************************************************************/
U8 SetOctaveFromStream(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!StrnCmp((PS8) * pptr, "*3", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_3;
    }
    else if (!StrnCmp((PS8) * pptr, "*4", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_4;
    }
    else if (!StrnCmp((PS8) * pptr, "*5", 2))
    {
        g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= OCTAVE_5;
    }
    else
    {
        return FALSE;
    }

    (*pptr) += 2;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  GetBeat
 * DESCRIPTION
 *  Retrieve beat length of the iMelody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  beat length
 *****************************************************************************/
U16 GetBeat(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    return (U16) GetInteger(pptr);
}


/*****************************************************************************
 * FUNCTION
 *  GetInstrument
 * DESCRIPTION
 *  Retrieve instrument of the iMelody string
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  index of instrument
 *****************************************************************************/
U8 GetInstrument(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SkipSpace(pptr);
    for (ptr = *pptr; *ptr != 0; ptr++)
    {
        if (*ptr == '(')
        {
            ptr++;
            return ((U8) GetInteger(&ptr));
        }
    }
    return INSTR_FLUTE;
}


/*****************************************************************************
 * FUNCTION
 *  GetInteger
 * DESCRIPTION
 *  Retrieve an integral value of an iMelody string, parsing unitl no integral character found
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 * RETURNS
 *  integral value
 *****************************************************************************/
S32 GetInteger(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;
    U8 ch;
    S32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = *ptr;
    if (!(ch >= '0' && ch <= '9'))
    {
        return -1;
    }
    val = ch - '0';
    ptr++;

    for (;;)
    {
        ch = *ptr;
        if (!(ch >= '0' && ch <= '9'))
        {
            break;
        }
        val = val * 10 + ch - '0';
        ptr++;
    }
    *pptr = ptr;
    return (S32) val;
}


/*****************************************************************************
 * FUNCTION
 *  CompareMelody
 * DESCRIPTION
 *  Compare iMelody and keywords.
 * PARAMETERS
 *  pptr        [IN]        Pointer of an iMelody string
 *  ps          [IN]        Pointer of keywords
 * RETURNS
 *  index of instrument
 *****************************************************************************/
U8 CompareMelody(U8 **pptr, void *ps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TrimStr(pptr);

    nLen = strlen(ps);
    if (StrnCmp((PS8) * pptr, ps, nLen))
    {
        return FALSE;
    }
    *pptr += nLen;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
U8 Tolower(U8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 'A' && ch <= 'Z')
    {
        return (U8) (ch + ('a' - 'A'));
    }
    return ch;
}


/*****************************************************************************
 * FUNCTION
 *  StrnCmp
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  s1          [IN]        String pointer to be compared
 *  s2          [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
S8 StrnCmp(S8 *s1, S8 *s2, int maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (maxlen-- > 0)
    {
        ch1 = Tolower(*s1++);
        ch2 = Tolower(*s2++);
        if (ch1 > ch2)
        {
            return 1;
        }
        if (ch1 < ch2)
        {
            return (U8) - 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SkipSpace
 * DESCRIPTION
 *  Skip space and tab within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void SkipSpace(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ptr == ' ' || *ptr == '\t')
    {
        ptr++;
    }
    *pptr = ptr;

}


/*****************************************************************************
 * FUNCTION
 *  ClearToEnd
 * DESCRIPTION
 *  Skip \n, \r within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void ClearToEnd(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ptr != '\n' && *ptr != '\r')
    {
        ptr++;
    }
    *pptr = ptr;
}


/*****************************************************************************
 * FUNCTION
 *  TrimStr
 * DESCRIPTION
 *  Skip \n, \r, \t, and space within a string
 * PARAMETERS
 *  pptr        [IN]        String pointer
 * RETURNS
 *  void
 *****************************************************************************/
void TrimStr(U8 **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr = *pptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ptr && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r'))
    {
        ptr++;
    }
    *pptr = ptr;
}


/*****************************************************************************
 * FUNCTION
 *  ShowNote
 * DESCRIPTION
 *  Display current modified note
 * PARAMETERS
 *  nNote       [IN]        Musical note
 * RETURNS
 *  void
 *****************************************************************************/
void ShowNote(U16 nNote)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nImageId = 0;
    U8 nYPos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetIndexInList(nNote, &nImageId, &nYPos);

    g_rngc_eng_cntx->YPos[g_rngc_eng_cntx->CurrUIPos] = nYPos;
    /* flag_shown[g_rngc_eng_cntx->CurrUIPos] = SHOW_IMG; */
    g_rngc_eng_cntx->ImageList[g_rngc_eng_cntx->CurrUIPos] = (PU8) GetImage(nImageId);
    redraw_ringcomposer();
}


#ifdef RNGC_HAS_INST_RECTANGLE
fixed_text_menuitem MMI_rngc_instrument_select_item_common_data;
fixed_text_menuitem_type MMI_rngc_instrument_select_items[ENUM_TOTAL_INSTR];
void *MMI_rngc_instrument_select_items_p[ENUM_TOTAL_INSTR];
horizontal_select MMI_rngc_instrument_select_menu;

extern UI_horizontal_select_theme temp_inline_select_menu_theme;

/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_instrument_menu_clear_background_callback
 * DESCRIPTION
 *  used by horizontal select to clear the background.
 * PARAMETERS
 *  x1  [IN]    the leftmost x coordinate
 *  y1  [IN]    the topmost y coordinate
 *  x2  [IN]    the rightmost x coordinate
 *  y2  [IN]    the bottom y coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_instrument_menu_clear_background_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(
        x1,
        y1,
        x2,
        y2,
        (UI_filled_area*)&rngc_instrument_select_background);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  initialize_rngc_instrument_select_menu_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 *  list_of_items           [IN]        
 *  highlighted_item        [?]         
 *  f                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_rngc_instrument_select_menu_items(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 **list_of_items,
        S32 *highlighted_item,
        void (*f) (S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_text_menuitem(&MMI_rngc_instrument_select_item_common_data, width, height);
    gui_fixed_text_menuitem_set_text_position(&MMI_rngc_instrument_select_item_common_data, 2, 0);
    MMI_rngc_instrument_select_item_common_data.flags |= UI_MENUITEM_CENTER_TEXT_Y;
#if(UI_TEXT_MENUITEM_SCROLL_TYPE == UI_TEXT_MENUITEM_SCROLL_TYPE_MARQUEE)
    MMI_rngc_instrument_select_item_common_data.flags |= UI_MENUITEM_MARQUEE_SCROLL;
#elif(UI_TEXT_MENUITEM_SCROLL_TYPE==UI_TEXT_MENUITEM_SCROLL_TYPE_TWO_DIRECTION)
    MMI_rngc_instrument_select_item_common_data.flags |= UI_MENUITEM_TWO_DIRECTION_SCROLL;
#endif 
    wgui_text_menuitem_reset_scrolling = gui_fixed_text_menuitem_stop_scroll;
    wgui_text_menuitem_restart_scrolling = gui_fixed_text_menuitem_start_scroll;
    for (i = 0; i < ENUM_TOTAL_INSTR; i++)
    {
        MMI_rngc_instrument_select_items[i].flags = UI_MENUITEM_CENTER_TEXT_X;
        MMI_rngc_instrument_select_items[i].item_text = (UI_string_type) list_of_items[i];
        MMI_rngc_instrument_select_items_p[i] = (void*)&MMI_rngc_instrument_select_items[i];
    }
    MMI_rngc_instrument_select_item_common_data.focussed_filler = (UI_filled_area*)&rngc_instrument_select_background;
    current_horizontal_select_theme = &temp_inline_select_menu_theme;
    gui_create_horizontal_select(&MMI_rngc_instrument_select_menu, x, y, width, height);
    MMI_rngc_instrument_select_menu.flags |= UI_LIST_MENU_LOOP;
    gui_set_horizontal_select_common_item_data(
        &MMI_rngc_instrument_select_menu,
        (void*)&MMI_rngc_instrument_select_item_common_data);
    gui_set_horizontal_select_item_functions(
        &MMI_rngc_instrument_select_menu,
        gui_show_fixed_text_menuitem,
        gui_measure_fixed_text_menuitem,
        gui_highlight_fixed_text_menuitem,
        gui_remove_highlight_fixed_text_menuitem,
        UI_fixed_menuitem_dummy_hide_function);
#ifdef __MMI_TOUCH_SCREEN__
    gui_set_horizontal_select_images(
        &MMI_rngc_instrument_select_menu,
        (U8*) GetImage(IMG_RING_INSTRU_LEFT_ARROW_UP),
        (U8*) GetImage(IMG_RING_INSTRU_RIGHT_ARROW_UP));
#endif /* __MMI_TOUCH_SCREEN__ */
    if (f != NULL)
    {
        MMI_rngc_instrument_select_menu.item_highlighted = f;
    }
    width = MMI_rngc_instrument_select_menu.ix2 - MMI_rngc_instrument_select_menu.ix1;
    height = MMI_rngc_instrument_select_menu.iy2 - MMI_rngc_instrument_select_menu.iy1;
    gui_resize_fixed_text_menuitem(&MMI_rngc_instrument_select_item_common_data, width, height);
    MMI_rngc_instrument_select_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND;
    MMI_rngc_instrument_select_menu.n_items = ENUM_TOTAL_INSTR;
    if (highlighted_item == NULL)
    {
        MMI_rngc_instrument_select_menu.highlighted_item = 0;
    }
    else
    {
        MMI_rngc_instrument_select_menu.highlighted_item = *highlighted_item;
    }

    if (MMI_rngc_instrument_select_menu.highlighted_item > (MMI_rngc_instrument_select_menu.n_items - 1))
    {
        MMI_rngc_instrument_select_menu.highlighted_item = MMI_rngc_instrument_select_menu.n_items - 1;
    }
    if (MMI_rngc_instrument_select_menu.highlighted_item < 0)
    {
        MMI_rngc_instrument_select_menu.highlighted_item = 0;
    }

    MMI_rngc_instrument_select_menu.items = (void **)MMI_rngc_instrument_select_items_p;
    MMI_rngc_instrument_select_menu.item_highlight_function(
                                        MMI_rngc_instrument_select_menu. items[MMI_rngc_instrument_select_menu.highlighted_item],
                                        MMI_rngc_instrument_select_menu.common_item_data);
    gui_set_horizontal_select_clear_background_function(
        &MMI_rngc_instrument_select_menu, 
        mmi_rngc_instrument_menu_clear_background_callback);
}


/*****************************************************************************
 * FUNCTION
 *  rngc_select_previous_instrument
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void rngc_select_previous_instrument(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_goto_previous_item(&MMI_rngc_instrument_select_menu);
    mmi_rngc_change_instrument(RNGC_PREVIOUS_INSTR);
    gui_show_horizontal_select(&MMI_rngc_instrument_select_menu);
    gui_BLT_double_buffer(
        MMI_rngc_instrument_select_menu.x,
        MMI_rngc_instrument_select_menu.y,
        MMI_rngc_instrument_select_menu.x + MMI_rngc_instrument_select_menu.width - 1,
        MMI_rngc_instrument_select_menu.y + MMI_rngc_instrument_select_menu.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  rngc_select_next_instrument
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void rngc_select_next_instrument(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_select_goto_next_item(&MMI_rngc_instrument_select_menu);
    mmi_rngc_change_instrument(RNGC_NEXT_INSTR);
    gui_show_horizontal_select(&MMI_rngc_instrument_select_menu);
    gui_BLT_double_buffer(
        MMI_rngc_instrument_select_menu.x,
        MMI_rngc_instrument_select_menu.y,
        MMI_rngc_instrument_select_menu.x + MMI_rngc_instrument_select_menu.width - 1,
        MMI_rngc_instrument_select_menu.y + MMI_rngc_instrument_select_menu.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  register_rngc_instrument_select_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_rngc_instrument_select_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(rngc_select_previous_instrument, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(rngc_select_next_instrument, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

#endif /*RNGC_HAS_INST_RECTANGLE */ 


/*****************************************************************************
 * FUNCTION
 *  redraw_ringcomposer
 * DESCRIPTION
 *  redraw ring tone composer stave
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void show_status_icons(void);
void redraw_ringcomposer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 temp_height = 0, temp_width = 0;
    S32 width = 0, index = 0;
    S32 width_title, height_title;  /* PMT MANISH   20050617 */
    S32 img_width, img_height;
    UI_character_type string_conv[6];
    PU8 MMI_title_icon_ring_comp = NULL;
    S32 y1 = 0, y2 = 0;

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_reset_clip();
    
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if ((touch_rngc_context.flag & RNGC_SELECTION_AREA_REDRAW) == RNGC_SELECTION_AREA_REDRAW)
    {
        clear_screen();
    }
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
    clear_screen();
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    
    gui_reset_clip();
    gui_reset_text_clip();

    /*if show title status area*/
#ifdef GUI_COMMON_SHOW_STATUS_ICON
    show_title_status_icon();
    show_status_icons();
#endif  /*GUI_COMMON_SHOW_STATUS_ICON*/
    
    /*Begin: draw main background image*/   
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.area_type == GUI_RNGC_NORMAL_TOOLBAR)
    {
        y2 = g_rngc_skin_layout.main_bg_img_area_y2 - NORMAL_TOOLBAR_HEIGHT - 2;
    }
    else if (touch_rngc_context.area_type == GUI_RNGC_NOTE_SELECTION)
    {
        y2 = g_rngc_skin_layout.main_bg_img_area_y2 - NOTE_SELECTION_HEIGHT - 2;
    }
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
    y2 = g_rngc_skin_layout.main_bg_img_area_y2 - 2;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    gui_set_clip(0, g_rngc_skin_layout.main_bg_img_area_y1, UI_device_width, y2);
    gui_show_image(0, g_rngc_skin_layout.main_bg_img_area_y1, (PU8)GetImage(g_rngc_skin_layout.main_bg_img_id));
    /*End: draw main background image*/

    /*draw the current stave list*/
    width = g_rngc_eng_cntx->CursorWidth;
    /* Ring Tone Staves */
    for (index = 0; index < NUM_NOTES_IN_STAVE; index++)
    {
        if ((g_rngc_eng_cntx->ImageList[index] != NULL))
        {
            gui_measure_image(g_rngc_eng_cntx->ImageList[index], (S32*) & img_width, (S32*) & img_height);
            gui_show_transparent_image(
                (RNGC_X_POS_BASED + index * RNGC_X_POS_OFFSET + ((width - img_width) >> 1)),
                g_rngc_eng_cntx->YPos[index],
                g_rngc_eng_cntx->ImageList[index],
                gui_transparent_color(255, 255, 255));
        }
    }
    
    /*Begin: draw retangle around the stave */
    c = gui_color(0, 0, 240);
    width = g_rngc_eng_cntx->CursorWidth;
    
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.mode == GUI_RNGC_EDIT || touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
    {
        c = gui_color(255, 0, 0);
    }
    y2 = g_rngc_skin_layout.stave_rectangle_y2 - NOTE_SELECTION_HEIGHT - 4;
    
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
    y2 = g_rngc_skin_layout.stave_rectangle_y2 - 4;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    gui_draw_rectangle(
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET),
        g_rngc_skin_layout.stave_rectangle_y1,
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET + width + 1),
        y2,
        c);
    /*End: draw retangle around stave*/   
    
    /*Begin: draw remaing notes number rectangle*/
    y1 = g_rngc_skin_layout.remain_notes_rect_y1;
    y2 = g_rngc_skin_layout.remain_notes_rect_y1 + g_rngc_skin_layout.remain_notes_rect_height;
    gui_set_clip(0, y1, UI_device_width, y2);
    
    /*in some LCD size, need draw background rectangle color*/
    /*in some other LCD size, draw text on main background image directly*/
    /*draw background rectangle color*/
    if(g_rngc_skin_layout.is_draw_notes_rect_bg_color)
    {
        gui_draw_filled_area(0, y1, UI_device_width, y2, (UI_filled_area*)&lightblue_color_dialog_background);     
    }
    
    /* remaining number of notes */
    c = gui_color(0, 0, 0);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(c);
    
    gui_itoa((S32) (MAX_NOTES - g_rngc_eng_cntx->TotalNotes), string_conv, 10);
    gui_measure_string((UI_string_type) string_conv, &temp_width, &temp_height);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(UI_device_width - RNGC_NUM_RIGHT_ALIGN_OFFSET, y1 + ((NOTE_BAR_HEIGHT - temp_height) >> 1));
    }
    else
    {
        gui_move_text_cursor(UI_device_width - temp_width - RNGC_NUM_RIGHT_ALIGN_OFFSET, y1 + ((NOTE_BAR_HEIGHT - temp_height) >> 1));
    }

    gui_print_text((UI_string_type) string_conv);
    gui_set_font(&MMI_default_font);
    /*End : drawing remaing notes number retangle*/

    /*Begin: drawing about instrument*/
    /*in some LCD size, has a rectangle for instument select and implemented by gui interfaces*/
    /*in some other LCD size, do not has instrument select rectangle but show instrument image on 
    title area right side*/
    gui_set_text_color(*((current_MMI_theme)->title_text_color));  
    gui_set_text_border_color(*((current_MMI_theme)->title_text_border_color));
    MMI_title_icon_ring_comp = (PU8) get_image(GetInstrumentImage(g_rngc_cntx.CurrInstr));
    gui_measure_image(MMI_title_icon_ring_comp, (S32*) & img_width, (S32*) & img_height);
    
    gui_reset_clip();
    /*clear the title area background before draw title bar*/
    c = gui_color(255, 255, 255);
#if !defined(__MMI_MAINLCD_320X240__)
    gui_fill_rectangle(
        0,
        g_rngc_skin_layout.title_rect_y1,
        UI_device_width - 1,
        ((g_rngc_skin_layout.title_rect_y1 + g_rngc_skin_layout.title_rect_height)),
        c);
#endif /*!defined(__MMI_MAINLCD_320X240__)*/
    gui_draw_filled_area(0, g_rngc_skin_layout.title_rect_y1,
        UI_device_width - 1, ((g_rngc_skin_layout.title_rect_y1 + g_rngc_skin_layout.title_rect_height)),
#ifdef GUI_COMMON_USE_THICK_TITLE
        current_UI_theme->thick_title_theme->active_filler);
#else /*GUI_COMMON_USE_THICK_TITLE*/
        current_UI_theme->window_title_theme->active_filler);
#endif /*GUI_COMMON_USE_THICK_TITLE*/

    /*if show instrument horizontal select rectangle */
#ifdef RNGC_HAS_INST_RECTANGLE
    gui_set_clip(0, g_rngc_skin_layout.instr_sel_rect_y1, UI_device_width, g_rngc_skin_layout.instr_sel_rect_y2);
    
    gui_draw_filled_area(0, g_rngc_skin_layout.instr_sel_rect_y1,
        UI_device_width, g_rngc_skin_layout.instr_sel_rect_y2, (UI_filled_area*)&rngc_instrument_select_background);
    
    gui_set_clip(
        g_rngc_skin_layout.instr_img_x1, g_rngc_skin_layout.instr_sel_rect_y1,
        g_rngc_skin_layout.instr_img_x1 + img_width,
        g_rngc_skin_layout.instr_sel_rect_y2);
    gui_show_image(
        g_rngc_skin_layout.instr_img_x1,
        g_rngc_skin_layout.instr_sel_rect_y1 + ((g_rngc_skin_layout.instr_sel_rect_y2 -  g_rngc_skin_layout.instr_sel_rect_y1 - img_height) >> 1),
        MMI_title_icon_ring_comp);
    
    gui_show_horizontal_select(&MMI_rngc_instrument_select_menu);
#else /*RNGC_HAS_INST_RECTANGLE*/
    gui_set_clip((UI_device_width - 1 - img_width), 
        g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - img_height) >> 1),
        UI_device_width, 
        (g_rngc_skin_layout.title_rect_y1 + g_rngc_skin_layout.title_rect_height));
    gui_show_image((UI_device_width - 1 - img_width), 
        g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - img_height) >> 1), 
        MMI_title_icon_ring_comp);
#endif /*RNGC_HAS_INST_RECTANGLE*/
    
    gui_reset_clip();

    gui_set_text_color(*((current_MMI_theme)->title_text_color));  
    gui_set_text_border_color(*((current_MMI_theme)->title_text_border_color));
    gui_measure_string((UI_string_type) get_string(STR_RING_COMPOSE_TITLE), &width_title, &height_title);
    /*instrument image is not show on title bar*/
#ifdef RNGC_HAS_INST_RECTANGLE   
    img_width = 0;   
#endif /*RNGC_HAS_INST_RECTANGLE*/
    
    if (r2lMMIFlag)
    {
        gui_move_text_cursor((((UI_device_width - 1 - img_width) >> 1) - (width_title >> 1)) + width_title,
            g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - height_title) >> 1));
    }
    else
    {
        gui_move_text_cursor((((UI_device_width - 1 - img_width) >> 1) - (width_title >> 1)),
            g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - height_title) >> 1));
    }
    
    gui_print_bordered_text((UI_string_type) get_string(STR_RING_COMPOSE_TITLE));
    /*End: drawing about instrument*/

#ifdef __MMI_TOUCH_RING_COMPOSER__
    if ((touch_rngc_context.flag & RNGC_SELECTION_AREA_REDRAW) == RNGC_SELECTION_AREA_REDRAW)
    {
        show_touch_rngc_selection_area();
    }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    
    show_softkey_background();
#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (touch_rngc_context.area_type != GUI_RNGC_NOTE_SELECTION)
    {
        show_left_softkey();
    }
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
    show_left_softkey();
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    show_right_softkey();
	
    gui_reset_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


#ifdef RNGC_CHANGE_INSTURMENT_SP
/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_change_instrument
 * DESCRIPTION
 *  
 * PARAMETERS
 *  selected_instrument     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_change_instrument(S32 selected_instrument)    /* PMT MANISH   20050616 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width, img_height;
    PU8 MMI_title_icon_ring_comp = NULL;

    /* static U8 current_instrument;//110805 ringtonecomposer Calvin modified */
    U8 current_instrument = GetCurrIndexCompRingToneInst();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT((RNGC_PREVIOUS_INSTR == selected_instrument) || (RNGC_PREVIOUS_INSTR == selected_instrument));

    if (RNGC_PREVIOUS_INSTR == selected_instrument)
    {
        if (INSTR_PIANO == CurrentInstrument[current_instrument])
        {
            current_instrument = ENUM_TOTAL_INSTR - 1;
        }
        else
        {
            current_instrument--;
        }
    }
    else if (RNGC_NEXT_INSTR == selected_instrument)
    {
        if ((ENUM_TOTAL_INSTR - 1) == current_instrument)
        {
            current_instrument = 0;
        }
        else
        {
            current_instrument++;
        }
    }
    g_rngc_cntx.CurrInstr = CurrentInstrument[current_instrument];

    MMI_title_icon_ring_comp = (PU8) get_image(GetInstrumentImage(g_rngc_cntx.CurrInstr));
    gui_measure_image(MMI_title_icon_ring_comp, (S32*) & img_width, (S32*) & img_height);

    gui_lock_double_buffer();
    gui_push_clip();
#ifdef RNGC_HAS_INST_RECTANGLE
    gui_set_clip(
        g_rngc_skin_layout.instr_img_x1, g_rngc_skin_layout.instr_sel_rect_y1,
        g_rngc_skin_layout.instr_img_x1 + img_width,
        g_rngc_skin_layout.instr_sel_rect_y2);
    gui_show_image(
        g_rngc_skin_layout.instr_img_x1,
        g_rngc_skin_layout.instr_sel_rect_y1 + ((g_rngc_skin_layout.instr_sel_rect_y2 -  g_rngc_skin_layout.instr_sel_rect_y1 - img_height) >> 1),
        MMI_title_icon_ring_comp);
#else /*RNGC_HAS_INST_RECTANGLE*/
    gui_set_clip((UI_device_width - 1 - img_width), 
        g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - img_height) >> 1),
        UI_device_width, 
        (g_rngc_skin_layout.title_rect_y1 + g_rngc_skin_layout.title_rect_height));
    gui_show_image((UI_device_width - 1 - img_width), 
        g_rngc_skin_layout.title_rect_y1 + ((g_rngc_skin_layout.title_rect_height - img_height) >> 1), 
        MMI_title_icon_ring_comp);


#endif /*RNGC_HAS_INST_RECTANGLE*/
    
    gui_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}
#endif /* RNGC_CHANGE_INSTURMENT_SP*/ 


/*****************************************************************************
 * FUNCTION
 *  SetRingComposer
 * DESCRIPTION
 *  Initialize defalut UI variables of stave
 * PARAMETERS
 *  title_id                [IN]        String id of title
 *  left_softkey            [IN]        String id if LSK
 *  left_softkey_icon       [IN]        Image id of LSK
 *  right_softkey           [IN]        String id of RSK
 *  right_softkey_icon      [IN]        Image id of RSK
 *  instru_type             [IN]        Instrument index
 *  value                   [IN]        Number of remaining notes
 *  history_buffer          [IN]        Pointer of history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void SetRingComposer(
        U16 title_id,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 instru_type,
        S32 value,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_category_screen_key_handlers();

    for (i = 0; i < NUM_NOTES_IN_STAVE; i++)
    {
        g_rngc_eng_cntx->YPos[i] = 0;
        g_rngc_eng_cntx->ImageList[i] = NULL;
    }

#ifdef __MMI_TOUCH_RING_COMPOSER__
    if (g_rngc_eng_cntx->TotalNotes == 0)   /* start vijay 20050707...new change */
    {
        memset(g_rngc_eng_cntx->NotesList, 0xFFFF, MAX_NOTES * sizeof(g_rngc_eng_cntx->NotesList[0]));
    }
    mmi_touch_rngc_setup(&touch_rngc_context);
    mmi_pen_register_down_handler(mmi_rngc_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_rngc_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_rngc_pen_move_hdlr);
    mmi_pen_register_repeat_handler(mmi_rngc_pen_repeat_hdlr);
    /* Backlight is turned off by some note, which generates Pen Abort when pen events turn on backlight again. */
    mmi_pen_register_abort_handler(mmi_rngc_pen_up_hdlr);
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#ifdef RNGC_HAS_INST_RECTANGLE
    {
        U8 *ItemList[ENUM_TOTAL_INSTR];     /* 071305 Calvin modified */
        U16 StringList[ENUM_TOTAL_INSTR];   /* 071305 Calvin modified */
        S32 img_height, img_width, instrument;
        PU8 ring_comp_icon;
        
        register_rngc_instrument_select_keys();
        GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_SEL_INST, StringList);
        for (i = 0; i < ENUM_TOTAL_INSTR; i++)
        {
            ItemList[i] = (U8*) GetString(StringList[i]);   /* 071305 Calvin modified */
        }
        
        /* 110805 ringtonecomposer Calvin Start */
        for (instrument = 0; instrument < ENUM_TOTAL_INSTR; instrument++)
        {
            if ((U8) g_rngc_cntx.CurrInstr == CurrentInstrument[instrument])
            {
                break;
            }
        }
        MMI_DBG_ASSERT(instrument < ENUM_TOTAL_INSTR);
        /* 110805 ringtonecomposer Calvin End */
        
        /* get image size */
        ring_comp_icon = (PU8) get_image(GetInstrumentImage(g_rngc_cntx.CurrInstr));
        gui_measure_image(ring_comp_icon, (S32*) & img_width, (S32*) & img_height);
        initialize_rngc_instrument_select_menu_items(
            RNGC_INSTR_SELECT_X_OFFSET * 3 + img_width,
            g_rngc_skin_layout.instr_sel_rect_y1,
            (UI_device_width - 2 * img_width - RNGC_INSTR_SELECT_X_OFFSET),
            MMI_RNGC_INSTRUMENT_SELECT_HEIGHT,
            ItemList,
            &instrument,
            UI_dummy_function_s32);
        
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        gui_block_list_effect();
#endif 
    }
#endif /*RNGC_HAS_INST_RECTANGLE*/

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

    RedrawCategoryFunction = redraw_ringcomposer;
}


/*****************************************************************************
 * FUNCTION
 *  GetInstrumentImage
 * DESCRIPTION
 *  Retrieve the image id of instrument
 * PARAMETERS
 *  instru_type     [IN]        Index of currrent instrument
 * RETURNS
 *  image id of the instrument
 *****************************************************************************/
U16 GetInstrumentImage(U8 instru_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (instru_type)
    {
        case INSTR_PIANO:
            return IMG_RING_INSTRU6;
        case INSTR_MUSICBOX:
            return IMG_RING_INSTRU5;
        case INSTR_XYLOPHONE:
            return IMG_RING_INSTRU10;
        case INSTR_HARMONICA:
            return IMG_RING_INSTRU4;
        case INSTR_GUITAR:
            return IMG_RING_INSTRU3;
        case INSTR_VIOLIN:
            return IMG_RING_INSTRU8;
        case INSTR_SPHONE:
            return IMG_RING_INSTRU7;
        case INSTR_FLUTE:
            return IMG_RING_INSTRU2;
        case INSTR_TRUMPET:
            return IMG_RING_INSTRU9;
        case INSTR_SDRUMS:
            return IMG_RING_INSTRU1;
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RefreshNotesList
 * DESCRIPTION
 *  Update position and image of note list to be displayed
 * PARAMETERS
 *  TotalNotes          [IN]        Total number of notes to be displyed
 *  psDisplayInfo       [IN]        List of display information
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshNotesList(U16 TotalNotes, DisplayInfo *psDisplayInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DisplayInfo *ptmpDisplayInfo = NULL;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!psDisplayInfo)
    {
        return;
    }

    for (index = 0; index < NUM_NOTES_IN_STAVE; index++)
    {
        g_rngc_eng_cntx->ImageList[index] = NULL;
    }

    ptmpDisplayInfo = psDisplayInfo;

    for (index = 0; index < TotalNotes; index++)
    {
        g_rngc_eng_cntx->YPos[index] = ptmpDisplayInfo->nYPos;
        g_rngc_eng_cntx->ImageList[index] = (PU8) GetImage(ptmpDisplayInfo->nImageId);
        ptmpDisplayInfo++;
    }

    redraw_ringcomposer();
}

#ifdef __MMI_TOUCH_RING_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_finish_insert_editing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_finish_insert_editing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0, index = 0, y1 = 0, y2 = 0, imgw = 0;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_rngc_context.mode = GUI_RNGC_INSERT;
    selection_area_context->custom_keys[2].key_image = IMG_TOUCH_RING_DOWN;
    show_touch_rngc_selection_area();
    
    width = g_rngc_eng_cntx->CursorWidth;
    /* Ring Tone Staves */
    for (index = 0; index < NUM_NOTES_IN_STAVE; index++)
    {
        if ((g_rngc_eng_cntx->ImageList[index] != NULL))
        {
            gui_measure_image(g_rngc_eng_cntx->ImageList[index], (S32*) & imgw, (S32*) & y1);
            gui_show_transparent_image(
                (RNGC_X_POS_BASED + index * RNGC_X_POS_OFFSET + ((width - imgw) >> 1)),
                g_rngc_eng_cntx->YPos[index],
                g_rngc_eng_cntx->ImageList[index],
                gui_transparent_color(255, 255, 255));
        }
    }

    c = gui_color(0, 0, 240);
    width = g_rngc_eng_cntx->CursorWidth;
    
#ifdef __MMI_TOUCH_RING_COMPOSER__
    y2 = g_rngc_skin_layout.stave_rectangle_y2 - NOTE_SELECTION_HEIGHT - 4; 
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
    y2 = g_rngc_skin_layout.stave_rectangle_y2 - 4;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
    gui_draw_rectangle(
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET),
        g_rngc_skin_layout.stave_rectangle_y1,
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET + width + 1),
        y2,
        c);

    gdi_layer_blt_previous(
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET),
         g_rngc_skin_layout.stave_rectangle_y1,
        (RNGC_X_POS_BASED + g_rngc_eng_cntx->CurrUIPos * RNGC_X_POS_OFFSET + width + 1),
        y2);
    /*End: draw retangle around stave*/

}


/*****************************************************************************
 * FUNCTION
 *  show_touch_rngc_selection_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_touch_rngc_selection_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_matrix_keys, n_custom_keys;
    S32 matrix_key_width, matrix_key_height;
    S32 n_matrix_rows, n_matrix_columns;
    S32 width, height;
    S32 horizontal_gap, vertical_gap;
    S32 x1, y1, x2, y2;
    S32 i, j;
    S32 key_x, key_y;
    S32 current_key_x, current_key_y, temp_x, temp_y;   /* [~PMT  MANISH   20050616 */
    S32 custom_key_x, custom_key_y;
    S32 custom_key_width, custom_key_height;
    MMI_ID_TYPE image_id;
    MMI_ID_TYPE *key_image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    touch_rngc_context.flag &= ~RNGC_SELECTION_AREA_REDRAW;
    n_matrix_keys = selection_area_context->n_matrix_keys;
    n_custom_keys = selection_area_context->n_custom_keys;
    n_matrix_rows = selection_area_context->matrix_layout->n_matrix_rows;
    n_matrix_columns = selection_area_context->matrix_layout->n_matrix_columns;
    matrix_key_width = selection_area_context->matrix_layout->key_width;
    matrix_key_height = selection_area_context->matrix_layout->key_height;
    horizontal_gap = selection_area_context->horizontal_gap;
    vertical_gap = selection_area_context->vertical_gap;
    image_id = selection_area_context->imageid;
    gui_measure_image(get_image(image_id), &width, &height);
    x1 = selection_area_context->image_x;
    y1 = selection_area_context->image_y;
    x2 = x1 + width - 1;
    y2 = y1 + height - 1;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, get_image(image_id));
    if (n_matrix_keys)
    {
        key_x = selection_area_context->image_x + selection_area_context->matrix_layout->matrix_x;
        key_y = selection_area_context->image_y + selection_area_context->matrix_layout->matrix_y;
        current_key_x = key_x;
        current_key_y = key_y;
        for (i = 0; i < n_matrix_rows; i++)
        {
            key_image = selection_area_context->matrix_layout->key_image[i];
            for (j = 0; j < n_matrix_columns; j++)
            {
                image_id = key_image[j];
                gui_measure_image(get_image(image_id), &width, &height);
                /* current_key_x = current_key_x + ((matrix_key_width - width)>>1); */
                temp_x = current_key_x + ((matrix_key_width - width) >> 1);     /* PMT MANISH   20050614 */
                temp_y = current_key_y + ((matrix_key_height - height) >> 1);   /* PMT MANISH   20050614 */
                /* current_key_y = current_key_y + ((matrix_key_height - height)>>1); */
                gui_show_image(temp_x, temp_y, get_image(image_id));    /* PMT MANISH   20050614 */
                /* gui_show_image(current_key_x,current_key_y,get_image(image_id)); */
                current_key_x = current_key_x + matrix_key_width + horizontal_gap;
            }
            current_key_x = key_x;
            current_key_y = key_y + matrix_key_height + vertical_gap;
        }
    }
    for (i = 0; i < n_custom_keys; i++)
    {
        custom_key_x = selection_area_context->custom_keys[i].x;
        custom_key_y = selection_area_context->custom_keys[i].y;
        custom_key_width = selection_area_context->custom_keys[i].key_width;
        custom_key_height = selection_area_context->custom_keys[i].key_height;

        image_id = selection_area_context->custom_keys[i].key_image;

    #ifndef __MMI_RNGC_ENABLE_INS_LED_NOTE__
        if (IMG_RING_EVENTLED_ON == image_id || IMG_RING_EVENTLED_OFF == image_id)
        {
            continue;
        }
    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
        gui_measure_image(get_image(image_id), &width, &height);
        custom_key_x = custom_key_x + ((custom_key_width >> 1) - (width >> 1));
        custom_key_y = custom_key_y + ((custom_key_height >> 1) - (height >> 1));
        gui_show_image(custom_key_x, custom_key_y, get_image(image_id));
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        selection_area_context->image_x,
        selection_area_context->image_y,
        UI_device_width - 1,
        UI_device_height - 1);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_down_selection_area
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]         
 *  pos                     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_rngc_pen_down_selection_area(touch_rngc_struct *touch_rngc_context, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_matrix_keys, n_custom_keys;
    S32 matrix_layout_x, matrix_layout_y;
    S32 matrix_width, matrix_height;
    S32 matrix_key_width, matrix_key_height;
    S32 n_matrix_rows, n_matrix_cloumns;
    S32 vertical_gap, horizontal_gap;
    S32 total_matrix_width = 0, total_matrix_height = 0;
    S32 current_key_x, current_key_y;
    S32 current_key_width, current_key_height;
    S32 i, j;
    MMI_BOOL ret = FALSE;   /* new */
    S32 pos_x, pos_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos_x = pos.x;
    pos_y = pos.y;

    n_matrix_keys = selection_area_context->n_matrix_keys;
    n_custom_keys = selection_area_context->n_custom_keys;

    if (n_matrix_keys)
    {
        matrix_layout_x = selection_area_context->image_x + selection_area_context->matrix_layout->matrix_x;
        matrix_layout_y = selection_area_context->image_y + selection_area_context->matrix_layout->matrix_y;
        matrix_width = selection_area_context->matrix_layout->matrix_width;
        matrix_height = selection_area_context->matrix_layout->matrix_height;
        n_matrix_rows = selection_area_context->matrix_layout->n_matrix_rows;
        n_matrix_cloumns = selection_area_context->matrix_layout->n_matrix_columns;
        matrix_key_width = selection_area_context->matrix_layout->key_width;
        matrix_key_height = selection_area_context->matrix_layout->key_height;
        horizontal_gap = selection_area_context->horizontal_gap;
        vertical_gap = selection_area_context->vertical_gap;
        total_matrix_height = matrix_layout_y;
        total_matrix_width = matrix_layout_x;
        if (pos_x >= matrix_layout_x && pos_x <= (matrix_layout_x + matrix_width - 1) && pos_y >= matrix_layout_y &&
            pos_y <= (matrix_layout_y + matrix_height - 1))
        {
            for (i = 0; i < n_matrix_rows; i++)
            {
                total_matrix_height += matrix_key_height;
                if (total_matrix_height > pos_y)
                {
                    total_matrix_width = matrix_layout_x;
                    for (j = 0; j < n_matrix_cloumns; j++)
                    {
                        total_matrix_width += matrix_key_width;
                        if (total_matrix_width > pos_x)
                        {
                            touch_rngc_context->key_note_type = selection_area_context->matrix_layout->key_note[i][j];
                            touch_rngc_context->selected_key_x =
                                matrix_layout_x + j * (matrix_key_width + horizontal_gap);
                            touch_rngc_context->selected_key_y =
                                matrix_layout_y + i * (matrix_key_height + vertical_gap);
                            touch_rngc_context->key_width = selection_area_context->matrix_layout->key_width;
                            touch_rngc_context->key_height = selection_area_context->matrix_layout->key_height;
                            touch_rngc_context->selected_key_image =
                                selection_area_context->matrix_layout->key_image[i][j];
                            ret = TRUE;
                            break;
                        }
                        else
                        {
                            total_matrix_width += horizontal_gap;
                            if (total_matrix_width > pos_x)
                            {
                                ret = FALSE;
                                return ret;
                            }
                        }
                    }
                    break;
                }
                else
                {
                    total_matrix_height += vertical_gap;
                    if (total_matrix_height > pos_y)
                    {
                        ret = FALSE;
                        return ret;
                    }
                }
            }
        }
    }
    for (i = 0; i < n_custom_keys; i++)
    {
        current_key_x = selection_area_context->custom_keys[i].x;
        current_key_y = selection_area_context->custom_keys[i].y;
        current_key_width = selection_area_context->custom_keys[i].key_width;
        current_key_height = selection_area_context->custom_keys[i].key_height;
        if (pos_x >= current_key_x && pos_x <= (current_key_x + current_key_width - 1) && pos_y >= current_key_y &&
            pos_y <= (current_key_y + current_key_height - 1))
        {
        #ifndef __MMI_RNGC_ENABLE_INS_LED_NOTE__
            if (selection_area_context->custom_keys[i].key_note == NOTE_LED_ON)
            {
                ret = FALSE;
                return ret;
            }
        #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ 
            touch_rngc_context->key_note_type = selection_area_context->custom_keys[i].key_note;
            touch_rngc_context->selected_key_x = current_key_x;
            touch_rngc_context->selected_key_y = current_key_y;
            touch_rngc_context->key_width = current_key_width;
            touch_rngc_context->key_height = current_key_height;
            touch_rngc_context->selected_key_image = selection_area_context->custom_keys[i].key_image;
            ret = TRUE;
            break;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_down_on_stave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos             [IN]        
 *  item_index      [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_rngc_pen_down_on_stave(mmi_pen_point_struct pos, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 i;
    S32 total_width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *item_index = 0;
    x1 = RNGC_X_POS_BASED;
    y1 = BKG_IMG_Y1 + 1;
    x2 = x1 + NUM_NOTES_IN_STAVE * RNGC_X_POS_OFFSET;
    y2 = UI_device_height - (MMI_BUTTON_BAR_HEIGHT + NOTE_SELECTION_HEIGHT) - 4;
    if (pos.x >= x1 && pos.x <= x2 && pos.y >= y1 && pos.y <= y2)
    {
        total_width = x1;
        for (i = 0; i < NUM_NOTES_IN_STAVE; i++)
        {
            total_width += RNGC_X_POS_OFFSET;
            if (total_width >= pos.x)
            {
                *item_index = i;
                break;
            }
        }
        return TRUE;
    }
    else if (pos.x > x2 && pos.y >= y1 && pos.y <= y2 && *item_index <= NUM_NOTES_IN_STAVE)
    {
        *item_index = g_rngc_eng_cntx->CurrUIPos + 1;
    }
    else if (pos.x < x1 && pos.y >= y1 && pos.y <= y2)
    {
        *item_index = -1;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_down_instrument
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_rngc_pen_down_instrument(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos_x, pos_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos_x = pos.x;
    pos_y = pos.y;
    if (PEN_CHECK_BOUND
        (pos_x, pos_y, RNGC_INSTRUMENT_X, RNGC_INSTRUMENT_Y, RNGC_INSTRUMENT_WIDTH, RNGC_INSTRUMENT_HEIGHT))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* handling of note type */


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_set_note_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  note_type_to_set        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_set_note_type(S32 note_type_to_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;
    U32 nNoteType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }

    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }
    StopTimer(NOTE_MULTITAP_TIMER);
    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    nNoteType = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;

    switch (nValue)
    {
        case NOTE_C:
        case NOTE_F:
            if (nNoteType == NORMAL && note_type_to_set == SHARP)
                SetNoteType(SHARP)
                else
            if (nNoteType == SHARP && note_type_to_set == SHARP)
                SetNoteType(NORMAL) break;
        case NOTE_D:
        case NOTE_G:
        case NOTE_A:
            if (nNoteType == NORMAL)
                SetNoteType(note_type_to_set)
                else
            if (nNoteType == FLAT && note_type_to_set == FLAT)
                SetNoteType(NORMAL)
                else
            if (nNoteType == SHARP && note_type_to_set == SHARP)
                SetNoteType(NORMAL) break;
        case NOTE_B:
        case NOTE_E:
            if (nNoteType == NORMAL && note_type_to_set == FLAT)
                SetNoteType(FLAT)
                else
            if (note_type_to_set == FLAT)
                SetNoteType(NORMAL) break;

        case NOTE_VIBRATION_ON:
        case NOTE_VIBRATION_OFF:
        case NOTE_LED_ON:
        case NOTE_LED_OFF:
        case NOTE_BACKLIGHT_ON:
        case NOTE_BACKLIGHT_OFF:
            /* don't vib/led/backlight if adjusting sharp/flat on a vibration note */            
            if (note_type_to_set == FLAT || note_type_to_set == SHARP)
            {
                return;
            }        
            
        default:    /* other notes, pound key does not effect */
            break;
    }
    if (nValue |= 0 && nNoteType != 0)
    {
        PlayCurrentNode();
        ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_set_note_beat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_set_note_beat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nValue;
    S32 nDuration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->TotalNotes > MAX_NOTES)
    {
        return;
    }
    /* highlighted on empty position */
    if (g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] == 0xFFFF)
    {
        return;
    }
    StopTimer(NOTE_MULTITAP_TIMER);

    nValue = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    if (nValue >= NOTE_VIBRATION_ON && nValue <= NOTE_BACKLIGHT_OFF)
	{
	    return;     /* don't vib/led/backlight if it's a vib/led/backlight note */
	}	    
    nDuration = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & DURATION_MASK;
    switch (nDuration)
    {
        case DURATION_3BY2:
            IncrementNoteBeat();
            break;
        case DURATION_1:
            TouchRngcDecrementNoteBeat();
            break;
        case DURATION_3BY4:
            IncrementNoteBeat();
            break;
        case DURATION_1BY2:
            TouchRngcDecrementNoteBeat();
            break;
        case DURATION_3BY8:
            IncrementNoteBeat();
            break;
        case DURATION_1BY4:
            TouchRngcDecrementNoteBeat();
            break;
        case DURATION_3BY16:
            IncrementNoteBeat();
            break;
        case DURATION_1BY8:
            TouchRngcDecrementNoteBeat();
            break;
        case DURATION_3BY32:
            IncrementNoteBeat();
            break;
        case DURATION_1BY16:
            TouchRngcDecrementNoteBeat();
            break;
        default:
            break;
    }

    if (nValue |= 0 && nDuration != 0)
    {
        PlayCurrentNode();
        ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
    }
}

#ifndef WIN32
extern S32 touch_ring_comp_mem;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_key_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
 
void mmi_rngc_key_select(touch_rngc_struct *touch_rngc_context)
{
#ifndef WIN32
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width, height;
    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    touch_rngc_context->flag &= ~RNGC_PEN_EVENT_UP;
    gui_lock_double_buffer();
    x1 = touch_rngc_context->selected_key_x;
    y1 = touch_rngc_context->selected_key_y;

    x2 = x1 + touch_rngc_context->key_width - 1;
    y2 = y1 + touch_rngc_context->key_height - 1;
    touch_rngc_context->selected_key_bitmap.buf_ptr = (U8*) mmi_frm_scrmem_alloc(touch_ring_comp_mem);
    memset(
        touch_rngc_context->selected_key_bitmap.buf_ptr,
        0,
        (touch_rngc_context->key_width) * (touch_rngc_context->key_height) * 2);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &touch_rngc_context->selected_key_bitmap);
    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2 - 1, y2 - 1);
    {
        gui_draw_filled_area(x1 + 1, y1 + 1, x2 - 1, y2 - 1, (UI_filled_area*)&touch_rngc_color_key_filler);
        image_id = touch_rngc_context->selected_key_image;
    }
    gui_measure_image(get_image(image_id), &width, &height);
    x1 = x1 + ((touch_rngc_context->key_width >> 1) - (width >> 1));
    y1 = y1 + ((touch_rngc_context->key_height >> 1) - (height >> 1));
    gui_show_image(x1, y1, get_image(image_id));
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_key_unselect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_key_unselect(touch_rngc_struct *touch_rngc_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context->flag & RNGC_PEN_EVENT_UP)
    {
        return;
    }

    gui_lock_double_buffer();
    x1 = touch_rngc_context->selected_key_x;
    y1 = touch_rngc_context->selected_key_y;
    x2 = x1 + touch_rngc_context->key_width - 1;
    y2 = y1 + touch_rngc_context->key_height - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (touch_rngc_context->selected_key_bitmap.buf_ptr)
    {
        gdi_image_cache_bmp_draw(x1, y1, &touch_rngc_context->selected_key_bitmap);
        mmi_frm_scrmem_free((void*)touch_rngc_context->selected_key_bitmap.buf_ptr);
        touch_rngc_context->selected_key_bitmap.buf_ptr = NULL;
    }
    gdi_layer_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    touch_rngc_context->selected_key_x = 0;
    touch_rngc_context->selected_key_y = 0;
    touch_rngc_context->key_width = 0;
    touch_rngc_context->key_height = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_change_stave_notes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]         
 *  item_index              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_change_stave_notes(touch_rngc_struct *touch_rngc_context, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 current_notes_in_stave = 100;
    U16 nImageId = 0;
    U8 nYPos = 0;
    U16 original_UI_pos = 0;
    U16 original_note_index = 0;
    S16 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_eng_cntx->CurrUIPos == item_index)
    {
        return;
    }
    if (item_index <= current_notes_in_stave /* || item_index<=g_rngc_eng_cntx->TotalNotes */ )
    {
        original_note_index = g_rngc_eng_cntx->CurrNoteIndex;
        original_UI_pos = g_rngc_eng_cntx->CurrUIPos;
        touch_rngc_context->original_key_note = g_rngc_eng_cntx->NotesList[original_note_index];
        offset = original_UI_pos - item_index;
        g_rngc_eng_cntx->CurrUIPos = item_index;
        g_rngc_eng_cntx->CurrNoteIndex = original_note_index - offset;  /* g_rngc_eng_cntx->TotalNotes-(current_notes_in_stave-item_index); */
        if (g_rngc_eng_cntx->CurrNoteIndex >= g_rngc_eng_cntx->TotalNotes)
        {
            g_rngc_eng_cntx->CurrUIPos -= (g_rngc_eng_cntx->CurrNoteIndex - g_rngc_eng_cntx->TotalNotes);
            g_rngc_eng_cntx->CurrNoteIndex = g_rngc_eng_cntx->TotalNotes;
        }
        GetIndexInList(touch_rngc_context->original_key_note, &nImageId, &nYPos);
        g_rngc_eng_cntx->NotesList[original_note_index] = touch_rngc_context->original_key_note;
        g_rngc_eng_cntx->ImageList[original_UI_pos] = (PU8) GetImage(nImageId);
        if ((touch_rngc_context->mode == GUI_RNGC_EDIT)
            && (g_rngc_eng_cntx->CurrNoteIndex >= g_rngc_eng_cntx->TotalNotes)
            && (item_index >= g_rngc_eng_cntx->CurrUIPos))
        {
            touch_rngc_context->area_type = GUI_RNGC_NORMAL_TOOLBAR;
            selection_area_context = &normal_toolbar_layout;
            touch_rngc_context->mode = GUI_RNGC_VIEW;
            touch_rngc_context->play_mode = RNGC_PLAY;
            touch_rngc_context->flag |= RNGC_SELECTION_AREA_REDRAW;
        }
        else
        {
            if ((touch_rngc_context->mode == GUI_RNGC_INSERT_EDIT) &&
                (original_note_index != g_rngc_eng_cntx->CurrNoteIndex))
            {
                touch_rngc_context->mode = GUI_RNGC_INSERT;
            }

        }
        redraw_ringcomposer();
    }
    /* start vijay 20050617..changes done to vanish the note selection area on cliking outside note are */
    else
    {
        HandleKey_RIGHT();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_normal_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_normal_toolbar(touch_rngc_struct *touch_rngc_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (touch_rngc_context->key_note_type == GUI_RNGC_KEY_EDIT
        || touch_rngc_context->key_note_type == GUI_RNGC_KEY_PLAY
        || touch_rngc_context->key_note_type == GUI_RNGC_KEY_NEXT
        || touch_rngc_context->key_note_type == GUI_RNGC_KEY_PREV)
    {
        if (g_rngc_eng_cntx->TotalNotes > 0)
        {
            mmi_rngc_key_select(touch_rngc_context);
            rngc_pen_event_on_object = RNGC_PEN_NORMAL_TOOLBAR;
        }
        else
        {
            rngc_pen_event_on_object = RNGC_PEN_NONE;
        }
    }
    else
    {
        mmi_rngc_key_select(touch_rngc_context);
        rngc_pen_event_on_object = RNGC_PEN_NORMAL_TOOLBAR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_note_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_rngc_context      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_note_selection(touch_rngc_struct *touch_rngc_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_note_val = 0, current_octave_val = 0, prev_note_val = 0;
    U16 current_note_duration = 0, current_note = 0, current_note_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_RNGC_ENABLE_INS_LED_NOTE__
    if (touch_rngc_context->key_note_type == NOTE_LED_ON)
    {
        return;
    }
#endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */ 
    current_note_val = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
    current_octave_val = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & OCTAVE_MASK;
    current_note = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex];

    mmi_rngc_key_select(touch_rngc_context);
    switch (touch_rngc_context->key_note_type)
    {
        case GUI_RNGC_KEY_SHARP:
            if (touch_rngc_context->mode != GUI_RNGC_INSERT)
            {
                mmi_rngc_set_note_type(GUI_RNGC_KEY_SHARP);
            }
            break;

        case GUI_RNGC_KEY_FLAT:
            if (touch_rngc_context->mode != GUI_RNGC_INSERT)
            {
                mmi_rngc_set_note_type(GUI_RNGC_KEY_FLAT);
            }
            break;

        case GUI_RNGC_KEY_DOT:
            if (touch_rngc_context->mode != GUI_RNGC_INSERT)
            {
                mmi_rngc_set_note_beat();
            }
            break;

        case GUI_RNGC_OCTAVE_UP:
            if ((touch_rngc_context->mode != GUI_RNGC_INSERT)
                && (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes))
            {
                if (current_note_val > NOTE_B)
                {
                    return;
                }
                else if (current_note_val == NOTE_B)
                {
                    switch (current_note_val)
                    {
                        case NOTE_B:
                            if (current_octave_val == OCTAVE_3)
                            {
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_C;
                                SetOctave(OCTAVE_4);
                            }
                            else if (current_octave_val == OCTAVE_4)
                            {
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_C;
                                SetOctave(OCTAVE_5);
                            }
                            else if (current_octave_val == OCTAVE_5)
                            {
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_C;;
                                SetOctave(OCTAVE_3);
                            }
                            break;
                    }
                }
                else
                {
                    ++current_note_val;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= current_note_val;
                }
                if (current_note_val != 0)
                {
                    current_note_type = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;
                    SetNoteType(NORMAL) mmi_rngc_set_note_type(current_note_type);
                    //                                      PlayCurrentNode();
                    //                                      ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex ]);
                }
            }
            break;

        case GUI_RNGC_OCTAVE_DOWN:
            if ((touch_rngc_context->mode != GUI_RNGC_INSERT)
                && (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes))
            {
                if (current_note_val > NOTE_B)
                {
                    return;
                }
                else if (current_note_val == NOTE_C || current_note_val > NOTE_B)       /* last note */
                {
                    switch (current_note_val)
                    {
                        case NOTE_C:
                        {
                            if (current_octave_val == OCTAVE_3)
                            {
                                SetOctave(OCTAVE_5)
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_B;
                            }
                            else if (current_octave_val == OCTAVE_4)
                            {
                                SetOctave(OCTAVE_3)
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_B;
                            }
                            else if (current_octave_val == OCTAVE_5)
                            {
                                SetOctave(OCTAVE_4)
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                                g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= NOTE_B;
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
                else if (current_note_val != 0)
                {
                    --current_note_val;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= current_note_val;
                }

                if (current_note_val != 0)
                {
                    current_note_type = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTETYPE_MASK;
                    SetNoteType(NORMAL) mmi_rngc_set_note_type(current_note_type);
                    //                                      PlayCurrentNode();
                    //                                      ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex ]);
                }
            }
            break;
        case GUI_RNGC_KEY_OK:
            break;

        default:
            if ((current_note != 0xFFFF) &&
                (touch_rngc_context->mode == GUI_RNGC_EDIT || touch_rngc_context->mode == GUI_RNGC_INSERT_EDIT))
            {
                if (current_note_val == NOTE_REST || current_note == 0 ||
                    (touch_rngc_context->key_note_type & NOTE_MASK) == NOTE_REST)
                {
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] = touch_rngc_context->key_note_type;
                }
                else
                {
                    current_note_duration = touch_rngc_context->key_note_type & DURATION_MASK;
                    current_note_type = touch_rngc_context->key_note_type & NOTETYPE_MASK;
                    prev_note_val = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & NOTE_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_DURATION_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTE_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_NOTETYPE_MASK;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= current_note_duration;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= current_note_type;
                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] |= prev_note_val;
                    if (current_octave_val)
                    {
                        SetOctave(current_octave_val);
                    }
                }
                switch (current_note)
                {
                    case NOTE_LED_OFF:
                    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
                        if (touch_rngc_context->key_note_type == NOTE_LED_ON)
                        {
                            SetLEDOn();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
                        break;
                    case NOTE_BACKLIGHT_OFF:
                        if (touch_rngc_context->key_note_type == NOTE_BACKLIGHT_ON)
                        {
                            SetBackLightOn();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                        break;
                    case NOTE_VIBRATION_OFF:
                        if (touch_rngc_context->key_note_type == NOTE_VIBRATION_ON)
                        {
                            SetVibrationOn();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                        break;
                    case NOTE_LED_ON:
                    #ifdef __MMI_RNGC_ENABLE_INS_LED_NOTE__
                        if (touch_rngc_context->key_note_type == NOTE_LED_ON)
                        {
                            SetLEDOff();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                    #endif /* __MMI_RNGC_ENABLE_INS_LED_NOTE__ */
                        break;
                    case NOTE_BACKLIGHT_ON:
                        if (touch_rngc_context->key_note_type == NOTE_BACKLIGHT_ON)
                        {
                            SetBackLightOff();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                        break;
                    case NOTE_VIBRATION_ON:
                        if (touch_rngc_context->key_note_type == NOTE_VIBRATION_ON)
                        {
                            SetVibrationOff();
                        }
                        else
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                        break;
                    case 0xFFFF:
                        break;
                    default:
                        if (touch_rngc_context->key_note_type == NOTE_VIBRATION_ON ||
                            touch_rngc_context->key_note_type == NOTE_BACKLIGHT_ON ||
                            touch_rngc_context->key_note_type == NOTE_LED_ON)
                        {
                            g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] =
                                touch_rngc_context->key_note_type;
                        }
                        break;
                }
                PlayCurrentNode();
                ShowNote(g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]);
            }
            else if (touch_rngc_context->mode == GUI_RNGC_INSERT)
            {
                if (g_rngc_eng_cntx->TotalNotes < MAX_NOTES)
                {
                    touch_rngc_context->mode = GUI_RNGC_INSERT_EDIT;
                    InsertNote(touch_rngc_context->key_note_type);
                    selection_area_context->custom_keys[2].key_image = IMG_TOUCH_RING_OK;
                    show_touch_rngc_selection_area();
                }
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_index;
    gui_button_pen_enum button_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#ifdef RNGC_HAS_INST_RECTANGLE
    {
        gui_horizontal_select_pen_enum select_event; 
        ret = gui_horizontal_select_translate_pen_event(
            &MMI_rngc_instrument_select_menu,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &select_event);
        if (ret)
        {
            rngc_pen_event_on_object = RNGC_PEN_INSTRUMENT;
            return;
        }
    }    
#else /*RNGC_HAS_INST_RECTANGLE*/
    ret = mmi_rngc_pen_down_instrument(pos);
    if (ret)
    {
        rngc_pen_event_on_object = RNGC_PEN_INSTRUMENT;
        //if (touch_rngc_context.area_type == GUI_RNGC_NORMAL_TOOLBAR && touch_rngc_context.play_mode != RNGC_PAUSE)
        {
            mmi_rngc_change_instrument(RNGC_NEXT_INSTR);
        }
        return;
    }
#endif /*RNGC_HAS_INST_RECTANGLE*/

    ret = mmi_rngc_pen_down_on_stave(pos, &item_index);
    if (ret)    /* start vijay change 20050706 */
    {
        rngc_pen_event_on_object = RNGC_PEN_STAVE;
        if (g_rngc_eng_cntx->CurrUIPos != item_index)
        {
            mmi_rngc_change_stave_notes(&touch_rngc_context, item_index);
            if (selection_area_context->custom_keys[2].key_image == IMG_TOUCH_RING_OK)
            {
                selection_area_context->custom_keys[2].key_image = IMG_TOUCH_RING_DOWN;
                show_touch_rngc_selection_area();
            }
        }
        return;
    }
    ret = mmi_rngc_pen_down_selection_area(&touch_rngc_context, pos);
    if (ret)
    {
        switch (touch_rngc_context.area_type)
        {
            case GUI_RNGC_NORMAL_TOOLBAR:
                /* rngc_pen_event_on_object = RNGC_PEN_NORMAL_TOOLBAR; */
                mmi_rngc_normal_toolbar(&touch_rngc_context);
                break;
            case GUI_RNGC_NOTE_SELECTION:
                rngc_pen_event_on_object = RNGC_PEN_NOTE_SELECTION;
                mmi_rngc_note_selection(&touch_rngc_context);
                break;
            default:
                break;
        }
        return;
    }
    /* vijay....changes done for disabling LSK...20050623 */
    if (touch_rngc_context.area_type != GUI_RNGC_NOTE_SELECTION)
    {
        ret = translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_DOWN, pos.x, pos.y, &button_event);
        if (ret)
        {
            rngc_pen_event_on_object = TOUCH_RNGC_PEN_LSK;
            if (button_event == GUI_BUTTON_PEN_DOWN && touch_rngc_context.area_type == GUI_RNGC_NORMAL_TOOLBAR)
            {
                execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
            }
            return;
        }
    }
    ret = translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_DOWN, pos.x, pos.y, &button_event);
    if (ret)
    {
        rngc_pen_event_on_object = TOUCH_RNGC_PEN_RSK;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        }
        return;
    }

    switch (touch_rngc_context.area_type)
    {
        case GUI_RNGC_NORMAL_TOOLBAR:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, NORMAL_TOOLBAR_IMAGE_X, NORMAL_TOOLBAR_IMAGE_Y, NORMAL_TOOLBAR_WIDTH,
                 NORMAL_TOOLBAR_HEIGHT))
            {
                return;
            }
            break;
        case GUI_RNGC_NOTE_SELECTION:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, NOTE_SELECTION_IMAGE_X, NOTE_SELECTION_IMAGE_Y, NOTE_SELECTION_WIDTH,
                 NOTE_SELECTION_HEIGHT))
            {
                return;
            }
            break;
    }
    if (touch_rngc_context.mode == GUI_RNGC_INSERT || touch_rngc_context.mode == GUI_RNGC_EDIT)
    {
        touch_rngc_context.area_type = GUI_RNGC_NORMAL_TOOLBAR;
        selection_area_context = &normal_toolbar_layout;
        touch_rngc_context.mode = GUI_RNGC_VIEW;
        touch_rngc_context.play_mode = RNGC_PLAY;
        touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
        redraw_ringcomposer();
        rngc_pen_event_on_object = RNGC_PEN_NONE;
        SetLeftSoftkeyFunction(EntryRngcCompToneOptList, KEY_EVENT_UP);        
    }
}

/* start vijay 20050613.....long press of clear key */


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    MMI_BOOL ret = MMI_FALSE;
    S32 item_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rngc_pen_event_on_object == RNGC_PEN_STAVE)
    {
        mmi_rngc_pen_down_on_stave(pos, &item_index);
        if (item_index > g_rngc_eng_cntx->CurrUIPos)
        {
            HandleKey_RIGHT();
        }
        else if (item_index == -1)
        {
            if (g_rngc_eng_cntx->CurrNoteIndex > 0)
            {
                HandleKey_LEFT();
            }
        }
    }
    ret = translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_REPEAT, pos.x, pos.y, &button_event);

    if (ret)
    {
        if (button_event == GUI_BUTTON_PEN_REPEAT)
        {
            HandleKey_CLEARLONG();
            rngc_pen_event_on_object = TOUCH_RNGC_PEN_RSK;
            if (touch_rngc_context.area_type == GUI_RNGC_NOTE_SELECTION)
            {
                touch_rngc_context.flag |= RNGC_NOTE_SELECTION_FINAL;
                touch_rngc_context.area_type = GUI_RNGC_NORMAL_TOOLBAR;
                selection_area_context = (rngc_selection_area_layout_struct*) & normal_toolbar_layout;
                touch_rngc_context.mode = GUI_RNGC_VIEW;
                touch_rngc_context.play_mode = RNGC_PLAY;
                touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
                redraw_ringcomposer();
            }
        }
        return;
    }
}

/* end vijay */


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rngc_pen_event_on_object)
    {
        case TOUCH_RNGC_PEN_LSK:
            ret = translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_UP, pos.x, pos.y, &button_event);
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE && touch_rngc_context.area_type == GUI_RNGC_NORMAL_TOOLBAR)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
                touch_rngc_context.play_mode = RNGC_PAUSE;
            }
            break;
        case TOUCH_RNGC_PEN_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_UP, pos.x, pos.y, &button_event);
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
                if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
                {
                    touch_rngc_context.mode = GUI_RNGC_INSERT;
                }
            }
            break;
        case RNGC_PEN_INSTRUMENT:
#ifdef RNGC_HAS_INST_RECTANGLE
            {
                gui_horizontal_select_pen_enum select_event;
                
                ret = gui_horizontal_select_translate_pen_event(
                    &MMI_rngc_instrument_select_menu,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &select_event);
                if (ret)
                {
                    //if (touch_rngc_context.area_type == GUI_RNGC_NORMAL_TOOLBAR &&
                    //    touch_rngc_context.play_mode != RNGC_PAUSE)
                    {
                        switch (select_event)
                        {
                        case GUI_HORIZONTAL_SELECT_PEN_NONE:
                            /* Do nothing */
                            break;
                        case GUI_HORIZONTAL_SELECT_PEN_PREV:
                            rngc_select_previous_instrument();
                            break;
                        case GUI_HORIZONTAL_SELECT_PEN_NEXT:
                            rngc_select_next_instrument();
                            break;
                        default:
                            MMI_DBG_ASSERT(0);
                        }
                    }
                }
            }
#endif /*RNGC_HAS_INST_RECTANGLE*/
            break;
        case RNGC_PEN_STAVE:
            break;
        case RNGC_PEN_NORMAL_TOOLBAR:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, touch_rngc_context.selected_key_x, touch_rngc_context.selected_key_y,
                 touch_rngc_context.key_width, touch_rngc_context.key_height))
                switch (touch_rngc_context.key_note_type)
                {
                    case GUI_RNGC_KEY_EDIT:
                        if (g_rngc_eng_cntx->TotalNotes > 0)
                        {
                            if (touch_rngc_context.play_mode != RNGC_PAUSE)
                            {
                                mmi_rngc_key_unselect(&touch_rngc_context);
                                touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                                if (g_rngc_eng_cntx->CurrNoteIndex < g_rngc_eng_cntx->TotalNotes)
                                {
                                    touch_rngc_context.area_type = GUI_RNGC_NOTE_SELECTION;
                                    selection_area_context =
                                        (rngc_selection_area_layout_struct*) & note_selection_layout;
                                    touch_rngc_context.mode = GUI_RNGC_EDIT;
                                    touch_rngc_context.play_mode = RNGC_PAUSE;
                                    touch_rngc_context.flag &= ~RNGC_NOTE_SELECTION_FINAL;
                                    touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
                                    redraw_ringcomposer();
									clear_softkey_handler(MMI_LEFT_SOFTKEY);
                                }
                            }
                        }
                        break;
                    case GUI_RNGC_KEY_INSERT:
                        if (touch_rngc_context.play_mode != RNGC_PAUSE && g_rngc_eng_cntx->TotalNotes <= MAX_NOTES)
                        {
                            mmi_rngc_key_unselect(&touch_rngc_context);
                            touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                            touch_rngc_context.area_type = GUI_RNGC_NOTE_SELECTION;
                            selection_area_context = (rngc_selection_area_layout_struct*) & note_selection_layout;
                            touch_rngc_context.mode = GUI_RNGC_INSERT;
                            touch_rngc_context.play_mode = RNGC_PAUSE;
                            touch_rngc_context.flag &= ~RNGC_NOTE_SELECTION_FINAL;
                            touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
                            redraw_ringcomposer();
                            clear_softkey_handler(MMI_LEFT_SOFTKEY);
                        }
                        break;
                    case GUI_RNGC_KEY_PLAY:
                        if (g_rngc_eng_cntx->TotalNotes > 0)
                        {
                            if (touch_rngc_context.play_mode == RNGC_PLAY)
                            {
                                g_rngc_cntx.CurrHiliteItem = ENUM_ADD_TONE_OPT_PLAY;
                                mmi_rngc_key_unselect(&touch_rngc_context);
                                RngcGotoSelectedCompToneOpt();
                                touch_rngc_context.play_mode = RNGC_PAUSE;
                            }
                            else if (touch_rngc_context.play_mode == RNGC_PAUSE)
                            {
                                ExitRngcPlayTone();
                                /* stop the playin melody */
                                touch_rngc_context.play_mode = RNGC_PLAY;
                            }
                        }
                        break;
                    case GUI_RNGC_KEY_NEXT:
                        if (g_rngc_eng_cntx->TotalNotes > 0)
                        {
                            if (touch_rngc_context.play_mode != RNGC_PAUSE)
                            {
                                mmi_rngc_key_unselect(&touch_rngc_context);
                                touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                                HandleKey_RIGHT();
                            }
                        }
                        break;
                    case GUI_RNGC_KEY_PREV:
                        if (g_rngc_eng_cntx->TotalNotes > 0)
                        {
                            if (touch_rngc_context.play_mode != RNGC_PAUSE)
                            {
                                mmi_rngc_key_unselect(&touch_rngc_context);
                                touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                                HandleKey_LEFT();
                            }
                        }
                        break;
                }
            break;
        case RNGC_PEN_NOTE_SELECTION:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, touch_rngc_context.selected_key_x, touch_rngc_context.selected_key_y,
                 touch_rngc_context.key_width, touch_rngc_context.key_height))
            {
                mmi_rngc_key_unselect(&touch_rngc_context);
                touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                if (touch_rngc_context.key_note_type == GUI_RNGC_KEY_OK)
                {
                    if (selection_area_context->custom_keys[2].key_image == IMG_TOUCH_RING_DOWN)
                    {
                        if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT ||
                            touch_rngc_context.mode == GUI_RNGC_INSERT || touch_rngc_context.mode == GUI_RNGC_EDIT)
                        {
                            touch_rngc_context.area_type = GUI_RNGC_NORMAL_TOOLBAR;
                            selection_area_context = &normal_toolbar_layout;
                            touch_rngc_context.mode = GUI_RNGC_VIEW;
                            touch_rngc_context.play_mode = RNGC_PLAY;
                            touch_rngc_context.flag |= RNGC_SELECTION_AREA_REDRAW;
                            redraw_ringcomposer();
                            rngc_pen_event_on_object = RNGC_PEN_NONE;
                            register_left_softkey_handler();
                        }
                        return;
                    }

                    if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT)
                    {
                        mmi_rngc_finish_insert_editing();
                    }
                }
            }
            break;
    }
    rngc_pen_event_on_object = RNGC_PEN_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    S32 item_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rngc_pen_event_on_object)
    {
        case RNGC_PEN_INSTRUMENT:
#ifdef RNGC_HAS_INST_RECTANGLE
            {
                gui_horizontal_select_pen_enum select_event;
                
                gui_horizontal_select_translate_pen_event(
                    &MMI_rngc_instrument_select_menu,
                    MMI_PEN_EVENT_MOVE,
                    pos.x,
                    pos.y,
                    &select_event);
            }
#endif /*RNGC_HAS_INST_RECTANGLE*/
            break;
        case RNGC_PEN_STAVE:
            if (mmi_rngc_pen_down_on_stave(pos, &item_index))
            {
                if (item_index > g_rngc_eng_cntx->CurrUIPos)
                {
                    HandleKey_RIGHT();
                }
                else if (item_index == -1)
                {
                    if (g_rngc_eng_cntx->CurrNoteIndex > 0)
                    {
                        HandleKey_LEFT();
                    }
                }
                else if (item_index < g_rngc_eng_cntx->CurrUIPos)
                {
                    /* mmi_rngc_change_stave_notes(&touch_rngc_context, item_index);*/
                    HandleKey_LEFT();
                }
                if (touch_rngc_context.mode == GUI_RNGC_INSERT_EDIT && item_index != g_rngc_eng_cntx->CurrUIPos)
                {
                    mmi_rngc_finish_insert_editing();
                }
            }
            break;

        case RNGC_PEN_NORMAL_TOOLBAR:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, selection_area_context->image_x + selection_area_context->matrix_layout->matrix_x,
                 selection_area_context->image_y + selection_area_context->matrix_layout->matrix_y,
                 NORMAL_TOOLBAR_WIDTH, NORMAL_TOOLBAR_HEIGHT))
            {
                if ((!PEN_CHECK_BOUND
                     (pos.x, pos.y, touch_rngc_context.selected_key_x, touch_rngc_context.selected_key_y,
                      touch_rngc_context.key_width - 1, touch_rngc_context.key_height - 1)))
                {
                    if (touch_rngc_context.key_note_type == GUI_RNGC_KEY_PLAY)
                    {
                        if (g_rngc_eng_cntx->TotalNotes > 0)
                        {
                            mmi_rngc_key_unselect(&touch_rngc_context);
                        }
                    }
                    else
                    {
                        mmi_rngc_key_unselect(&touch_rngc_context);
                    }
                    touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                }
            }
            /* START VIJAY PMT 20050719 */
            else    /* move outside note selection bar */
            {
                mmi_rngc_key_unselect(&touch_rngc_context);
            }
            /* END VIJAY */
            break;
        case RNGC_PEN_NOTE_SELECTION:
            if (PEN_CHECK_BOUND
                (pos.x, pos.y, selection_area_context->image_x + selection_area_context->matrix_layout->matrix_x,
                 selection_area_context->image_y + selection_area_context->matrix_layout->matrix_y,
                 NOTE_SELECTION_WIDTH, NOTE_SELECTION_HEIGHT))
            {
                if ((!PEN_CHECK_BOUND
                     (pos.x, pos.y, touch_rngc_context.selected_key_x, touch_rngc_context.selected_key_y,
                      touch_rngc_context.key_width, touch_rngc_context.key_height)))
                {
                    mmi_rngc_key_unselect(&touch_rngc_context);
                    touch_rngc_context.flag |= RNGC_PEN_EVENT_UP;
                }
            }
            else    /* move outside note selection bar */
            {
                mmi_rngc_key_unselect(&touch_rngc_context);
            }
            break;
        case TOUCH_RNGC_PEN_LSK:
            translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_MOVE, pos.x, pos.y, &button_event);
            break;
        case TOUCH_RNGC_PEN_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_MOVE, pos.x, pos.y, &button_event);
            break;
    }
}
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ // #ifdef __MMI_TOUCH_RING_COMPOSER__

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)

