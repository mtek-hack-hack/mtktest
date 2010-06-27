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
 * Calculator.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum value, structure, and function prototypes for calculator application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Calculator.h
   Author:        manju
   Date Created:  June-21-2003
   Contains:      Calculator
**********************************************************************************/
#ifndef _MMI_CALCULATOR_H
#define _MMI_CALCULATOR_H
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_CALCULATOR__

#include "CalculatorResDef.h"
#if defined(__MMI_TOUCH_CALCULATOR__)
#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 

/* 
 * Define
 */
#define SCR_ID_CALC_APP CALCULATOR_BASE+1

#if defined(__MMI_TOUCH_CALCULATOR__)
#if defined (__MMI_MAINLCD_240X400__)
#define  TOUCH_CALC_LSK_X_OFFSET    (17)
#define  TOUCH_CALC_LSK_Y_OFFSET    (5)
#define  TOUCH_CALC_SCREEN_X        (0)
#if defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE)
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#elif !defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE) 
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT)
#elif defined (GUI_COMMON_SHOW_STATUS_ICON) && !defined(GUI_COMMON_USE_THICK_TITLE) 
#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#else
#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT)
#endif
#define  TOUCH_CALC_SCREEN_WIDTH    (UI_DEVICE_WIDTH)
#define  TOUCH_CALC_SCREEN_HEIGHT   (UI_DEVICE_HEIGHT-MMI_STATUS_BAR_HEIGHT-MMI_TITLE_HEIGHT-MMI_BUTTON_BAR_HEIGHT)
#define  CALC_TOUCH_RESULT_AREA_X   (13)
#define  CALC_TOUCH_RESULT_AREA_Y   (10)
#define  CALC_TOUCH_KEYPAD_WIDTH    (213)
#define  CALC_TOUCH_KEYPAD_HEIGHT   (200)
#define  CALC_TOUCH_KEY_WIDTH    (50)
#define  CALC_TOUCH_KEY_HEIGHT      (37)
#define  CALC_TOUCH_RESULT_KEYPAD_GAP     (9)
#define  CALC_TOUCH_VERTICAL_GAP    (4)
#define  CALC_TOUCH_HORIZONTAL_GAP  (5)
#define  CALC_TOUCH_NCOLUMNS        (4)
#define  CALC_TOUCH_NROWS        (5)
#define  CALC_TOUCH_RESULT_AREA_WIDTH (214)
#define  CALC_TOUCH_RESULT_AREA_HEIGHT (79)
#define CALC_TOUCH_OPERAND1_Y    (26)
#define CALC_TOUCH_OPERAND2_Y    (50)
#define CALC_TOUCH_OPERATOR_X    (5)
#define CALC_TOUCH_OPERATOR_Y    (CALC_TOUCH_OPERAND2_Y)
#define TOUCH_CALC_MEM_Y1        (3)
#define TOUCH_CALC_MEM_X1        (CALC_TOUCH_RESULT_AREA_WIDTH - 3 )
#define  MMI_CALC_KEY_START      (0)
#define  MMI_CALC_KEY_END     (20)

#elif defined (__MMI_MAINLCD_320X240__)
#define  TOUCH_CALC_LSK_X_OFFSET    (17)
#define  TOUCH_CALC_LSK_Y_OFFSET    (5)
#define  TOUCH_CALC_SCREEN_X        (0)
#define  TOUCH_CALC_SCREEN_Y        (0)
#define  TOUCH_CALC_SCREEN_WIDTH    (320)
#define  TOUCH_CALC_SCREEN_HEIGHT   (240-MMI_BUTTON_BAR_HEIGHT)
#define  CALC_TOUCH_RESULT_AREA_X   (29)
#define  CALC_TOUCH_RESULT_AREA_Y   (2)
#define  CALC_TOUCH_KEYPAD_WIDTH    (260)
#define  CALC_TOUCH_KEYPAD_HEIGHT   (140)
#define  CALC_TOUCH_KEY_WIDTH    (62)
#define  CALC_TOUCH_KEY_HEIGHT      (25)
#define  CALC_TOUCH_RESULT_KEYPAD_GAP     (4)
#define  CALC_TOUCH_VERTICAL_GAP    (3)
#define  CALC_TOUCH_HORIZONTAL_GAP  (4)
#define  CALC_TOUCH_NCOLUMNS        (4)
#define  CALC_TOUCH_NROWS        (5)
#define  CALC_TOUCH_RESULT_AREA_WIDTH (260)
#define  CALC_TOUCH_RESULT_AREA_HEIGHT (65)
#define CALC_TOUCH_OPERAND1_Y    (22)
#define CALC_TOUCH_OPERAND2_Y    (44)
#define CALC_TOUCH_OPERATOR_X    (5)
#define CALC_TOUCH_OPERATOR_Y    (CALC_TOUCH_OPERAND2_Y)
#define TOUCH_CALC_MEM_Y1        (1)
#define TOUCH_CALC_MEM_X1        (CALC_TOUCH_RESULT_AREA_WIDTH - 21 )
#define  MMI_CALC_KEY_START      (0)
#define  MMI_CALC_KEY_END     (20)

#elif defined (__MMI_MAINLCD_240X320__)   /* 041205 Calvin added */
#define  TOUCH_CALC_LSK_X_OFFSET    (17)
#define  TOUCH_CALC_LSK_Y_OFFSET    (5)
#define  TOUCH_CALC_SCREEN_X        (0)
#if defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE)
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#elif !defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE) 
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT)
#elif defined (GUI_COMMON_SHOW_STATUS_ICON) && !defined(GUI_COMMON_USE_THICK_TITLE) 
/*shaokai modify it.start 090813*/
//#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#define  TOUCH_CALC_SCREEN_Y        (26)
/*shaokai modify it.end 090813*/

#else
#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT)
#endif
#define  TOUCH_CALC_SCREEN_WIDTH    (UI_DEVICE_WIDTH)
#define  TOUCH_CALC_SCREEN_HEIGHT  (270)/* (UI_DEVICE_HEIGHT-MMI_STATUS_BAR_HEIGHT-MMI_TITLE_HEIGHT-MMI_BUTTON_BAR_HEIGHT)*/
#define  CALC_TOUCH_RESULT_AREA_X   (8)
#define  CALC_TOUCH_RESULT_AREA_Y   (4)
#define  CALC_TOUCH_KEYPAD_WIDTH    (223)
#define  CALC_TOUCH_KEYPAD_HEIGHT   (197)/*(157)*/
#define  CALC_TOUCH_KEY_WIDTH       (57)/*(52)*/
#define  CALC_TOUCH_KEY_HEIGHT      (28)/*(29)*/
#define  CALC_TOUCH_RESULT_KEYPAD_GAP     (5)
#define  CALC_TOUCH_VERTICAL_GAP    (0)/*(3)*/
#define  CALC_TOUCH_HORIZONTAL_GAP   (0)/*(5)*/
#define  CALC_TOUCH_NCOLUMNS        (4)
#define  CALC_TOUCH_NROWS        (5)
#define  CALC_TOUCH_RESULT_AREA_WIDTH (223)
#define  CALC_TOUCH_RESULT_AREA_HEIGHT (72)
#define CALC_TOUCH_OPERAND1_Y    (22)
#define CALC_TOUCH_OPERAND2_Y    (44)
#define CALC_TOUCH_OPERATOR_X    (5)
#define CALC_TOUCH_OPERATOR_Y    (CALC_TOUCH_OPERAND2_Y)
#define TOUCH_CALC_MEM_Y1        (1)
#define TOUCH_CALC_MEM_X1        (CALC_TOUCH_RESULT_AREA_WIDTH - 2 )
#define  MMI_CALC_KEY_START      (0)
#define  MMI_CALC_KEY_END     (20)

#elif defined(__MMI_MAINLCD_176X220__) /* defined (__MMI_MAINLCD_176X220__) */ 
#define  TOUCH_CALC_LSK_X_OFFSET    (17)
#define  TOUCH_CALC_LSK_Y_OFFSET    (5)
#define  TOUCH_CALC_SCREEN_X        (0)
#if defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE)
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#elif !defined (GUI_COMMON_SHOW_STATUS_ICON) && defined(GUI_COMMON_USE_THICK_TITLE) 
#define  TOUCH_CALC_SCREEN_Y        (MMI_THICK_TITLE_HEIGHT)
#elif defined (GUI_COMMON_SHOW_STATUS_ICON) && !defined(GUI_COMMON_USE_THICK_TITLE) 
#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT+MMI_STATUS_BAR_HEIGHT)
#else
#define  TOUCH_CALC_SCREEN_Y        (MMI_THIN_TITLE_HEIGHT)
#endif
#define  TOUCH_CALC_SCREEN_WIDTH    (174)
#define  TOUCH_CALC_SCREEN_HEIGHT   (158)
#define  CALC_TOUCH_RESULT_AREA_X   (7)
#define  CALC_TOUCH_RESULT_AREA_Y   (2)
#define  CALC_TOUCH_KEYPAD_WIDTH    (161)
#define  CALC_TOUCH_KEYPAD_HEIGHT   (108)
#define  CALC_TOUCH_KEY_WIDTH    (38)
#define  CALC_TOUCH_KEY_HEIGHT      (20)
#define  CALC_TOUCH_RESULT_KEYPAD_GAP     (1)   /* 041205 Calvin added */
#define  CALC_TOUCH_VERTICAL_GAP    (2)
#define  CALC_TOUCH_HORIZONTAL_GAP  (3)
#define  CALC_TOUCH_NCOLUMNS        (4)
#define  CALC_TOUCH_NROWS        (5)
#define  CALC_TOUCH_RESULT_AREA_WIDTH (161)
#define  CALC_TOUCH_RESULT_AREA_HEIGHT (45)
#define CALC_TOUCH_OPERAND1_Y    (15)
#define CALC_TOUCH_OPERAND2_Y    (28)
#define CALC_TOUCH_OPERATOR_X    (5)
#define CALC_TOUCH_OPERATOR_Y    (CALC_TOUCH_OPERAND2_Y)
#define TOUCH_CALC_MEM_Y1        (1)
#define TOUCH_CALC_MEM_X1        (CALC_TOUCH_RESULT_AREA_WIDTH - 2 )
#define  MMI_CALC_KEY_START      (0)
#define  MMI_CALC_KEY_END     (20)

#else
#define  TOUCH_CALC_LSK_X_OFFSET    (17)
#define  TOUCH_CALC_LSK_Y_OFFSET    (5)
#define  TOUCH_CALC_SCREEN_X        (0)
#define  TOUCH_CALC_SCREEN_Y        (0)
#define  TOUCH_CALC_SCREEN_WIDTH    (UI_DEVICE_WIDTH)
#define  TOUCH_CALC_SCREEN_HEIGHT   (UI_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT)
#define  CALC_TOUCH_RESULT_AREA_X   (3)
#define  CALC_TOUCH_RESULT_AREA_Y   (3)
#define  CALC_TOUCH_KEYPAD_WIDTH    (123)
#define  CALC_TOUCH_KEYPAD_HEIGHT   (90)
#define  CALC_TOUCH_KEY_WIDTH    (28)
#define  CALC_TOUCH_KEY_HEIGHT      (17)
#define  CALC_TOUCH_RESULT_KEYPAD_GAP     (3)   /* 041205 Calvin added */
#define  CALC_TOUCH_VERTICAL_GAP    (1)
#define  CALC_TOUCH_HORIZONTAL_GAP  (3)
#define  CALC_TOUCH_NCOLUMNS        (4)
#define  CALC_TOUCH_NROWS        (5)
#define  CALC_TOUCH_RESULT_AREA_WIDTH (122)
#define  CALC_TOUCH_RESULT_AREA_HEIGHT (43)
#define CALC_TOUCH_OPERAND1_Y    (15)
#define CALC_TOUCH_OPERAND2_Y    (29)
#define CALC_TOUCH_OPERATOR_X    (5)
#define CALC_TOUCH_OPERATOR_Y    (CALC_TOUCH_OPERAND2_Y)
#define TOUCH_CALC_MEM_Y1        (2)
#define TOUCH_CALC_MEM_X1        (CALC_TOUCH_RESULT_AREA_WIDTH - 2 )
#define  MMI_CALC_KEY_START      (0)
#define  MMI_CALC_KEY_END     (20)

#endif /* defined (__MMI_MAINLCD_240X320__) */ 

typedef enum
{
    MMI_CALC_KEY_NONE,
    MMI_CALC_NUM_KEY,
    MMI_CALC_SYM_KEY
} MMI_CALC_KEY_TYPE;

typedef enum
{
    GUI_CALC_PEN_NONE,
    GUI_CALC_PEN_HIGHLIGHT_CHANGED
} gui_calc_pen_enum;

typedef struct _calculator_keypad_struct
{
    S32 result_area_x, result_area_y;
    S32 keypad_x, keypad_y;
    S32 keypad_width, keypad_height;
    S32 key_width, key_height;
    /*shaokai add it.start 090814*/
    S32 key_height1;
    /*shaokai add it.start 090814*/
    S32 horizontal_gap, vertical_gap;
    S32 selected_key_x, selected_key_y;
    S32 n_rows, n_column;
    S32 key_type;
    S32 operand1_y, operand2_y, operator_x, operator_y;
    S32 mem_x1, mem_y1;
    gdi_image_cache_bmp_struct selected_key_bitmap;
    U16 flag;
} calculator_keypad_struct;
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */
#ifdef __MMI_TOUCH_CALCULATOR__
extern calculator_keypad_struct calculator_keypad;
#endif 

extern void CalcInit(void);
extern void CalcDeInit(void);

extern void EntryCalcApp(void);
extern void ExitCalcApp(void);
extern void CalcPreEntryApp(void);
extern void HighlightCalcMenu(void);
extern void CalcHandleClearKey(void);
extern void CalcShowResultScreen(void);
extern void CalcComputeResult(void);
extern void CalcShowKeypad(void);
extern void CalcClearAll(void);
extern void CalcResetContext(void);
extern void CalcHandleRSKLongPress(void);
extern U8 mmi_calc_check_boundary(DOUBLE value);

#endif /* __MMI_CALCULATOR__ */ // #ifdef __MMI_CALCULATOR__
extern void CalcDouble2String(DOUBLE num, S8 *result, U8 digits);
extern void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer);
extern DOUBLE gui_atof(UI_string_type s);
extern S32 CalcComputePrecision(DOUBLE result, S16 max_digits);

#if defined(__MMI_TOUCH_CALCULATOR__)
extern void setup_calculator_keypad(calculator_keypad_struct *calculator_keypad, S16 x, S16 y);
extern void show_touch_calculator_screen(S32 x1, S32 y1, S32 width, S32 height);
extern void gui_calculator_translate_pen_position(
                calculator_keypad_struct *calculator_keypad,
                S32 x,
                S32 y,
                S32 *item_index,
                S32 *key_variable);
extern void gui_calculator_key_select(calculator_keypad_struct *calculator_keypad, S32 item_index);
extern void gui_calculator_key_unselect(calculator_keypad_struct *calculator_keypad);
extern BOOL gui_calculator_translate_pen_event(
                calculator_keypad_struct *calculator_keypad,
                S32 x,
                S32 y,
                gui_calc_pen_enum *menu_event,
                mmi_pen_event_type_enum pen_event);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 

#endif /* _MMI_CALCULATOR_H */ // #ifndef __CALCULATOR_H__

