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
 * Calculator.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Calculator application.
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
  * Dec 11 2005 mtk01215
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
 */
/**********************************************************************************
   Filename:      Calculator.c
   Author:        manju
   Date Created:  June-21-2003
   Contains:      Calculator
**********************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_CALCULATOR_C
#define _MMI_CALCULATOR_C

#ifdef __MMI_TOUCH_CALCULATOR__
/* start vijay 20050301 foe calculator */
#include "wgui.h"
/* end vijay */
#endif /* __MMI_TOUCH_CALCULATOR__ */ 

#include "gui.h"
#include "Calculator.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"

#ifdef __MMI_CALCULATOR__
#include "gui_themes.h"
#include "wgui_softkeys.h"
#include "OrganizerDef.h"
#endif /* __MMI_CALCULATOR__ */ 

/* MTK Elvis for R2L characters */
extern BOOL r2lMMIFlag;

/* MTK end */

/* 
 * Define
 */
/* Images for the calculator: Currently hardcoded */
#define CALC_MAX_DIGITS          12
#define CALC_MAX_BUFF_LEN        30

#ifdef __MMI_CALCULATOR__
#define CALC_NUM_BUTTONS         9

#define CALC_SCR_X               0
#define CALC_SCR_WIDTH           UI_device_width
#define CALC_SCR_HEIGHT          (CALC_NUM_HEIGHT * 3 + 1)

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
	#if defined (__MMI_MAINLCD_128X128__)
	#define CALC_NUM_HEIGHT	13
	#define CALC_KEYPAD_Y				(CALC_NUM_HEIGHT * 3 + 2)
	#else
	#define CALC_NUM_HEIGHT	15
	#define CALC_KEYPAD_Y				(CALC_NUM_HEIGHT * 3 + 15)
	#endif	
	#ifdef __MMI_SLIM_CALCULATOR__
		#define CALC_KEYPAD_X            19
	#else 
		#define CALC_KEYPAD_X            21
	#endif 
	#define CALC_SCR_Y               0

#elif defined (__MMI_MAINLCD_176X220__)
#define CALC_NUM_HEIGHT 15
#define MAP_IMG_WIDTH 176
#define CALC_KEYPAD_X            ((CALC_SCR_WIDTH - MAP_IMG_WIDTH)/2)   
#define CALC_KEYPAD_Y            (CALC_SCR_Y + CALC_NUM_HEIGHT * 3 + 15)
#ifdef GUI_COMMON_SHOW_STATUS_ICON
#define CALC_SCR_Y               0 + MMI_status_bar_height + MMI_COMMON_TITLE_HEIGHT
#else /* GUI_COMMON_SHOW_STATUS_ICON */
#define CALC_SCR_Y               0 + MMI_COMMON_TITLE_HEIGHT
#endif /* GUI_COMMON_SHOW_STATUS_ICON */


#elif defined (__MMI_MAINLCD_320X240__)
#define CALC_NUM_HEIGHT 22
#define MAP_IMG_WIDTH   240
#define CALC_SCR_Y               0
#define CALC_KEYPAD_X            ((CALC_SCR_WIDTH - MAP_IMG_WIDTH)/2)   
#define CALC_KEYPAD_Y            (CALC_SCR_Y + CALC_NUM_HEIGHT * 3 + 13)


#elif defined (__MMI_MAINLCD_240X400__)
#define CALC_NUM_HEIGHT 22
#define MAP_IMG_WIDTH   240
#ifdef GUI_COMMON_SHOW_STATUS_ICON
#define CALC_SCR_Y               0 + MMI_status_bar_height + MMI_COMMON_TITLE_HEIGHT
#else /* GUI_COMMON_SHOW_STATUS_ICON */
#define CALC_SCR_Y               0 + MMI_COMMON_TITLE_HEIGHT
#endif /* GUI_COMMON_SHOW_STATUS_ICON */
#define CALC_KEYPAD_X            ((CALC_SCR_WIDTH - MAP_IMG_WIDTH)/2)   
#define CALC_KEYPAD_Y            198

#else // for __MMI_MAINLCD_240X320__ or other size
#define CALC_NUM_HEIGHT 22
#define MAP_IMG_WIDTH   240
#define CALC_KEYPAD_X            ((CALC_SCR_WIDTH - MAP_IMG_WIDTH)/2)  
#define CALC_KEYPAD_Y            (CALC_SCR_Y + CALC_NUM_HEIGHT * 3 + 15)
#ifdef GUI_COMMON_SHOW_STATUS_ICON
#define CALC_SCR_Y               0 + MMI_status_bar_height + MMI_COMMON_TITLE_HEIGHT
#else /* GUI_COMMON_SHOW_STATUS_ICON */
#define CALC_SCR_Y               0 + MMI_COMMON_TITLE_HEIGHT
#endif /* GUI_COMMON_SHOW_STATUS_ICON */

#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 

#define CALC_OPERAND1_Y          (CALC_SCR_Y + CALC_NUM_HEIGHT)
#define CALC_OPERAND2_Y          (CALC_SCR_Y + CALC_NUM_HEIGHT * 2)


#define CALC_OPERATOR_X          5
#define CALC_OPERATOR_Y          CALC_OPERAND2_Y
#define CALC_MEM_X1              2
#define CALC_MEM_Y1              CALC_SCR_Y+1
#define CALC_MEM_X2              CALC_SCR_WIDTH - 2
#define CALC_MEM_Y2              CALC_OPERAND1_Y - 1

#define RESULT_NOT_EXCEED        0
#define RESULT_EXCEED            1

#define CALC_RSK_BACK            0
#define CALC_RSK_CLEAR           1
#define CALC_ZEOR_LEN            1
#define CALC_ZEOR_DOT_LEN           3

#define CALC_SYM_ERROR     (UI_character_type)'E'
#define CALC_SYM_EQUAL     (UI_character_type)'='
#define CALC_SYM_PLUS      (UI_character_type)'+'
#define CALC_SYM_MINUS     (UI_character_type)'-'
#define CALC_SYM_MUL    (UI_character_type)'x'
#define CALC_SYM_DIV    (UI_character_type)'/'
#define CALC_SYM_DOT    (UI_character_type)'.'
#define CALC_SYM_ZERO      (UI_character_type)'0'
#define CALC_SYM_NULL      (UI_character_type)'\0'

#define CALC_RESERVED_SPACE_FOR_OPERATOR     10

/* 
 * Typedef 
 */
typedef struct
{
    S32 x;
    S32 y;
    PU8 image;
} calc_img_struct;

typedef struct
{
    DOUBLE Operand1;
    DOUBLE Operand2;
#ifndef __MMI_SLIM_CALCULATOR__
    DOUBLE MemValue;
#endif 
    calc_img_struct OperatorImg[CALC_NUM_BUTTONS];
    UI_character_type Operand1Buf[CALC_MAX_DIGITS + 2];
    UI_character_type Operand2Buf[CALC_MAX_DIGITS + 2];
    U8 Operand1Len;
    U8 Operand2Len;
    U8 Operator;
    U8 CurrHilite;
    U8 ResultState;
    U8 RSKState;
    U8 ExecFlag;    /* if just after execution */
    U8 OpToExecute; /* operator to execute */
    U8 IsRSKPress;
    U8 ComputeType;
} calc_context_struct;

typedef enum
{
    CALC_OP_PLUS = 0,
    CALC_OP_MINUS,
    CALC_OP_MULT,
    CALC_OP_DIV,
    CALC_OP_EQUAL,
#ifndef __MMI_SLIM_CALCULATOR__
    CALC_OP_MP,
    CALC_OP_MM,
    CALC_OP_MC,
    CALC_OP_MR,
#endif /* __MMI_SLIM_CALCULATOR__ */ 
    CALC_OP_NONE
} CALC_OPER_ENUM;

#ifdef __MMI_TOUCH_CALCULATOR__

typedef enum
{
    TOUCH_CALC_KEY0 = 0,
    TOUCH_CALC_KEY1,
    TOUCH_CALC_KEY2,
    TOUCH_CALC_KEY3,
    TOUCH_CALC_KEY4,
    TOUCH_CALC_KEY5,
    TOUCH_CALC_KEY6,
    TOUCH_CALC_KEY7,
    TOUCH_CALC_KEY8,
    TOUCH_CALC_KEY9,
    TOUCH_CALC_KEY_DOT = 20 /* pound key or hash key */
} TOUCH_CALC_NUM_KEY_ENUM;

typedef enum
{
    TOUCH_CALC_OP_PLUS = CALC_OP_PLUS,
    TOUCH_CALC_OP_MINUS = CALC_OP_MINUS,
    TOUCH_CALC_OP_MULT = CALC_OP_MULT,
    TOUCH_CALC_OP_DIV = CALC_OP_DIV,
    TOUCH_CALC_OP_MP = CALC_OP_MP,
    TOUCH_CALC_OP_MM = CALC_OP_MM,
    TOUCH_CALC_OP_MC = CALC_OP_MC,
    TOUCH_CALC_OP_MR = CALC_OP_MR,
    TOUCH_CALC_OP_EQUAL = CALC_OP_EQUAL
} TOUCH_CALC_SYM_KEY_ENUM;

typedef enum
{
    TOUCH_CALC_PEN_NONE,
    TOUCH_CALC_PEN_LSK,
    TOUCH_CALC_PEN_RSK,
    TOUCH_CALC_PEN_NUM_KEY
} touch_calc_pen_state_enum;

const S32 TouchCalcKeys[CALC_TOUCH_NROWS][CALC_TOUCH_NCOLUMNS] = 
{
    {TOUCH_CALC_OP_MP, TOUCH_CALC_OP_MM, TOUCH_CALC_OP_MR, TOUCH_CALC_OP_MC},
    {TOUCH_CALC_KEY7, TOUCH_CALC_KEY8, TOUCH_CALC_KEY9, TOUCH_CALC_OP_DIV},
    {TOUCH_CALC_KEY4, TOUCH_CALC_KEY5, TOUCH_CALC_KEY6, TOUCH_CALC_OP_MULT},
    {TOUCH_CALC_KEY1, TOUCH_CALC_KEY2, TOUCH_CALC_KEY3, TOUCH_CALC_OP_MINUS},
    {TOUCH_CALC_KEY0, TOUCH_CALC_KEY_DOT, TOUCH_CALC_OP_EQUAL, TOUCH_CALC_OP_PLUS}
};

const MMI_ID_TYPE calculator_key_image[] = 
{
    IMG_ID_TOUCH_CALC_MP,
    IMG_ID_TOUCH_CALC_MM,
    IMG_ID_TOUCH_CALC_MR,
    IMG_ID_TOUCH_CALC_MC,
    IMG_ID_TOUCH_CALC_KEY7,
    IMG_ID_TOUCH_CALC_KEY8,
    IMG_ID_TOUCH_CALC_KEY9,
    IMG_ID_TOUCH_CALC_DIVIDE,
    IMG_ID_TOUCH_CALC_KEY4,
    IMG_ID_TOUCH_CALC_KEY5,
    IMG_ID_TOUCH_CALC_KEY6,
    IMG_ID_TOUCH_CALC_MULTIPLY,
    IMG_ID_TOUCH_CALC_KEY1,
    IMG_ID_TOUCH_CALC_KEY2,
    IMG_ID_TOUCH_CALC_KEY3,
    IMG_ID_TOUCH_CALC_MINUS,
    IMG_ID_TOUCH_CALC_KEY0,
    IMG_ID_TOUCH_CALC_KEY_DOT,
    IMG_ID_TOUCH_CALC_KEY_EQUAL,
    IMG_ID_TOUCH_CALC_PLUS
};
#endif /* __MMI_TOUCH_CALCULATOR__ */ 

/* 
 * Local Variable
 */

const color gCalcResultScrColor = {255, 234, 182, 100};
const color gCalcResultBorderColor = {255, 186, 64, 100};
const color gCalcTextColor = {0, 0, 0, 100};

extern const U8 gCalcImgCoor[][2];


/* 
 * Local Function
 */
#ifdef __MMI_TOUCH_CALCULATOR__
void mmi_touchcalc_pen_down_hdlr(mmi_pen_point_struct point);
void mmi_touchcalc_pen_up_hdlr(mmi_pen_point_struct point);
void mmi_touchcalc_pen_move_hdlr(mmi_pen_point_struct point);
void mmi_touchcalc_pen_repeat_hdlr(mmi_pen_point_struct point);
void mmi_touchcalc_pen_long_tap_hdlr(mmi_pen_point_struct point);
#endif /* __MMI_TOUCH_CALCULATOR__ */ 
U8 mmi_calc_del_scr_callback(void *p);

/* 
 * Global Variable
 */
calc_context_struct *g_calc_cntx = NULL;

#ifdef __MMI_TOUCH_CALCULATOR__
calculator_keypad_struct calculator_keypad;
touch_calc_pen_state_enum calc_pen_on_object = TOUCH_CALC_PEN_NONE;

#define CALC_PEN_DOWN_ON_KEYPAD     0x0001
BOOL TOUCH_CALC_SELECT_KEY = TRUE;
#endif /* __MMI_TOUCH_CALCULATOR__ */ 

/* 
 * Global Function
 */

/* Button co-ordinates for the on screen calculator keypad */

#endif /* __MMI_CALCULATOR__ */ 
#define CALC_UTILITY


/*****************************************************************************
 * FUNCTION
 *  CalcDouble2String
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num         [IN]        
 *  result      [?]         
 *  digits      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CalcDouble2String(DOUBLE num, S8 *result, U8 digits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 precision;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    precision = CalcComputePrecision(num, digits);
    gui_float_string(num, precision, result);
}


/*****************************************************************************
 * FUNCTION
 *  gui_atof
 * DESCRIPTION
 *  Convert string to float
 * PARAMETERS
 *  s       [IN]        String to be converted
 * RETURNS
 *  float value of the string
 *****************************************************************************/
DOUBLE gui_atof(UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str[CALC_MAX_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ansii_str, (S8*) s);
    return atof(ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  gui_float_string
 * DESCRIPTION
 *  Convert float to string
 * PARAMETERS
 *  dob_val         [IN]            Value to be converted.
 *  prec_val        [IN]            Number of precision.
 *  out_buffer      [IN/OUT]        Pointer to the result string
 * RETURNS
 *  void
 *****************************************************************************/
void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str[CALC_MAX_BUFF_LEN];
    S8 fmt[8];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ansii_str, 0, CALC_MAX_BUFF_LEN);
    memset(fmt, 0, 8);

    sprintf(fmt, "%%.%df", prec_val);
    sprintf(ansii_str, fmt, dob_val);

    /* to prevent 123.250000 */
    if (prec_val > 0)
    {
        for (i = CALC_MAX_BUFF_LEN - 1; i != 0; i--)
        {
            if (ansii_str[i] == 0)
            {
                continue;
            }
            else if (ansii_str[i] == '0')
            {
                ansii_str[i] = 0;
            }
            else
            {
                break;
            }
        }
    }

    /* to prevent -0 */
    if (strlen(ansii_str) == 2 && ansii_str[0] == '-' && ansii_str[1] == '0')
    {
        ansii_str[0] = '0';
        ansii_str[1] = 0;
    }
    mmi_asc_to_ucs2(out_buffer, ansii_str);
}


/*****************************************************************************
 * FUNCTION
 *  CalcComputePrecision
 * DESCRIPTION
 *  To retrive the length of precision part of a given number.
 * PARAMETERS
 *  result          [IN]        The number to be computed.
 *  max_digits      [IN]        Maximum digits of the number
 * RETURNS
 *  void
 *****************************************************************************/
S32 CalcComputePrecision(DOUBLE result, S16 max_digits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prec_val = 0;
    U8 str[CALC_MAX_BUFF_LEN];
    S8 fmt[8];
    S8 decimal_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        result = -(result);
    }
    /*
     * str[]        = x.xxxxxxxxxxxe+/-xxx
     * ex: 0.0000000001 = 1.00000000000e-010
     * 646464646464 = 6.46464646464e+011
     */
    memset(fmt, 0, 8);
    sprintf(fmt, "%%%d.%de", max_digits, (max_digits - 2));

    memset(str, '\0', CALC_MAX_BUFF_LEN);
    sprintf((S8*) str, fmt, result);

    if (str[max_digits] == 'e')
    {
        S32 j;

        memset(fmt, 0, 8);
        memcpy(fmt, str + (max_digits + 2), 3);
        prec_val = atoi(fmt);

        /* Out of boundary */
        if (prec_val >= max_digits - 1)
        {
            return 0;
        }

        if (str[max_digits + 1] == '-')
        {
            j = (max_digits - 1) - prec_val;
        }
        else
        {
            j = max_digits - 1;
        }

        for (; j > 1; j--)
        {
            if (str[j] != '0')
            {
                decimal_length = (j - 1);
                break;
            }
        }
        /* |result| < 1 */
        if (str[max_digits + 1] == '-')
        {
            prec_val += decimal_length;
        }
        /* |result| >= 1 */
        else if (str[max_digits + 1] == '+')
        {
            if (decimal_length > prec_val)
            {
                prec_val = decimal_length - prec_val;
            }
            else
            {
                prec_val = 0;
            }
        }
    }

    return prec_val;

}

#ifdef __MMI_CALCULATOR__

#define CALC_INITIALIZE


/*****************************************************************************
 * FUNCTION
 *  HighlightCalcMenu
 * DESCRIPTION
 *  Highlight handler of Calculator menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCalcMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(CalcPreEntryApp, KEY_EVENT_UP);
    SetKeyHandler(CalcPreEntryApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  CalcInit
 * DESCRIPTION
 *  Initialize highlight handler and global vairables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_CALCULATOR_MENU, HighlightCalcMenu);
}


/*****************************************************************************
 * FUNCTION
 *  CalcDeInit
 * DESCRIPTION
 *  Free dynamic memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx)
    {
    #ifdef __MMI_TOUCH_CALCULATOR__
        if (calculator_keypad.selected_key_bitmap.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(calculator_keypad.selected_key_bitmap.buf_ptr);
            calculator_keypad.selected_key_bitmap.buf_ptr = NULL;
        }
    #endif    
        OslMfree(g_calc_cntx);
        g_calc_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_calc_del_scr_callback
 * DESCRIPTION
 *  Callback function of delete calculator screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_calc_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalcDeInit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CalcFreeMemAndBack
 * DESCRIPTION
 *  Free memory and exit calculator application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcFreeMemAndBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->IsRSKPress)
    {
        g_calc_cntx->IsRSKPress = FALSE;
        SetRightSoftkeyFunction(NULL, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        /* CalcDeInit(); */
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcSetRSKClear
 * DESCRIPTION
 *  Change RSK to "Clear"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcSetRSKClear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_CLEAR, IMG_GLOBAL_CLEAR);
    SetRightSoftkeyFunction(CalcHandleRSKLongPress, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(CalcHandleClearKey, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  CalcSetRSKBack
 * DESCRIPTION
 *  Change RSK to "Back"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcSetRSKBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_OK);
    SetRightSoftkeyFunction(CalcFreeMemAndBack, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  CalcResetResultValue
 * DESCRIPTION
 *  Reset memory related variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcResetResultValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
    g_calc_cntx->Operator = CALC_OP_NONE;
    g_calc_cntx->Operand1 = 0;

    g_calc_cntx->Operand2Buf[0] = CALC_SYM_NULL;
    g_calc_cntx->Operand1Buf[0] = CALC_SYM_NULL;

    memset(g_calc_cntx->Operand2Buf, 0, sizeof(g_calc_cntx->Operand2Buf));
    memset(g_calc_cntx->Operand1Buf, 0, sizeof(g_calc_cntx->Operand1Buf));

    g_calc_cntx->Operand2Len = 1;
    g_calc_cntx->Operand1Len = 1;

    g_calc_cntx->OpToExecute = CALC_OP_NONE;
    g_calc_cntx->RSKState = CALC_RSK_BACK;
    g_calc_cntx->ExecFlag = FALSE;

    g_calc_cntx->ResultState = RESULT_NOT_EXCEED;

}


/*****************************************************************************
 * FUNCTION
 *  CalcMoveTextCursor
 * DESCRIPTION
 *  move cursor to specified position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CalcMoveTextCursor(BOOL r21flag, S32 x, S32 y, S32 offset)
{
    if (r21flag)
    {
         gui_move_text_cursor(x + offset, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }	
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CalcResetMemValue
 * DESCRIPTION
 *  Reset memory related variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_SLIM_CALCULATOR__
void CalcResetMemValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_calc_cntx->ResultState = RESULT_NOT_EXCEED;
    g_calc_cntx->MemValue = 0;
}
#endif /* __MMI_SLIM_CALCULATOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  CalcResetContext
 * DESCRIPTION
 *  Reset all values to default.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcResetContext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalcResetResultValue();
#ifndef __MMI_SLIM_CALCULATOR__
    CalcResetMemValue();
#endif 
}

#define CALC_DRAW_FUNC


/*****************************************************************************
 * FUNCTION
 *  CalcShowKeypad
 * DESCRIPTION
 *  Draw keypad of calculator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcShowKeypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();

    gui_show_image(CALC_KEYPAD_X, CALC_KEYPAD_Y, (PU8) GetImage(IMG_ID_CALC_MAIN));

    gui_show_transparent_image(
        CALC_KEYPAD_X + g_calc_cntx->OperatorImg[g_calc_cntx->CurrHilite].x,
        CALC_KEYPAD_Y + g_calc_cntx->OperatorImg[g_calc_cntx->CurrHilite].y,
        (PU8) g_calc_cntx->OperatorImg[g_calc_cntx->CurrHilite].image,
        0);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(CALC_KEYPAD_X, CALC_KEYPAD_Y, UI_device_width - 1, UI_device_height - 1);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  CalcShowResultScreen
 * DESCRIPTION
 *  Draw result screen area.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcShowResultScreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type op = CALC_SYM_ERROR;
    S32 w;
    S8 uni_s[64];
    S32 temp_int;

    DOUBLE temp_res = 0;
    S8 ansii_str[CALC_MAX_BUFF_LEN];

#ifndef __MMI_SLIM_CALCULATOR__
    S8 uni_memory[64];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    gui_set_font(&MMI_medium_font);
#else
    gui_set_font(&MMI_large_font);
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#if defined (__MMI_MAINLCD_176X220__)
    gui_set_font(&MMI_medium_font);
#endif
#endif

    gui_set_text_color(gCalcTextColor);

#if defined(__MMI_TOUCH_CALCULATOR__)

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        calculator_keypad.result_area_x,
        calculator_keypad.result_area_y,
        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - 1,
        calculator_keypad.result_area_y + CALC_TOUCH_RESULT_AREA_HEIGHT - 1
		);
    gui_show_image(
        TOUCH_CALC_SCREEN_X,
        TOUCH_CALC_SCREEN_Y,
		(PU8) GetImage(IMG_ID_TOUCH_CALC_MAIN)
		);
    gdi_layer_pop_clip();
    gui_BLT_double_buffer(	
        calculator_keypad.result_area_x,
        calculator_keypad.result_area_y,
        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - 1,
        calculator_keypad.result_area_y + CALC_TOUCH_RESULT_AREA_HEIGHT - 1
		);

#else /* defined(__MMI_TOUCH_CALCULATOR__) */ 

    /* screen background */
    gui_reset_clip();
    gui_reset_text_clip();
    gui_fill_rectangle(
        CALC_SCR_X,
        CALC_SCR_Y,
        CALC_SCR_X + CALC_SCR_WIDTH - 1,
        CALC_SCR_Y + CALC_SCR_HEIGHT - 1,
        gCalcResultScrColor);
    gui_draw_rectangle(
        CALC_SCR_X,
        CALC_SCR_Y,
        CALC_SCR_X + CALC_SCR_WIDTH - 1,
        CALC_SCR_Y + CALC_SCR_HEIGHT - 1,
        gCalcResultBorderColor);
    gui_draw_rectangle(
        CALC_SCR_X + 1,
        CALC_SCR_Y + 1,
        CALC_SCR_X + CALC_SCR_WIDTH - 2,
        CALC_SCR_Y + CALC_SCR_HEIGHT - 2,
        gCalcResultBorderColor);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 

#if !defined(__MMI_TOUCH_CALCULATOR__) && !defined(__MMI_SLIM_CALCULATOR__)     /* 050905 Sophie modified */
    /* memory filed */
    w = gui_get_character_width((UI_character_type) '[');
    CalcMoveTextCursor(r2lMMIFlag, CALC_MEM_X1, CALC_MEM_Y1, w);
    gui_print_character((UI_character_type) '[');

    w = gui_get_character_width((UI_character_type) ']');
    CalcMoveTextCursor(r2lMMIFlag, CALC_MEM_X2 - 7, CALC_MEM_Y1, w);
    gui_print_character((UI_character_type) ']');
#endif /* !defined(__MMI_TOUCH_CALCULATOR__) && !defined(__MMI_SLIM_CALCULATOR__) */ 

    if (g_calc_cntx->ResultState == RESULT_EXCEED)
    {
        op = CALC_SYM_ERROR;

        w = gui_get_character_width(CALC_SYM_ZERO);
#if defined(__MMI_TOUCH_CALCULATOR__)
    CalcMoveTextCursor(
                r2lMMIFlag, 
                calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                calculator_keypad.operand2_y,
                w);    

#else /* defined(__MMI_TOUCH_CALCULATOR__) */ 
    CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH  - w - 4, CALC_OPERAND2_Y,  w);   
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
        gui_print_character(CALC_SYM_ZERO);
    }
    else
    {
        if (g_calc_cntx->Operator == CALC_OP_EQUAL)
        {
            op = CALC_SYM_EQUAL;

            temp_int = (S32) g_calc_cntx->Operand1;
            if (temp_int == g_calc_cntx->Operand1)
            {
                sprintf(ansii_str, "%d", temp_int);
                mmi_asc_to_ucs2((S8*) uni_s, (S8*) ansii_str);
            }
            else
            {
                CalcDouble2String(g_calc_cntx->Operand1, uni_s, CALC_MAX_DIGITS);
                g_calc_cntx->Operand1 = gui_atof((UI_string_type) uni_s);
            }
            w = gui_get_string_width((UI_string_type) uni_s);
 #if defined(__MMI_TOUCH_CALCULATOR__)
            CalcMoveTextCursor(
                    r2lMMIFlag,
                    calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                    calculator_keypad.operand2_y,
                    w);
#else /* defined(__MMI_TOUCH_CALCULATOR__) */ 
            CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
            gui_print_text((UI_string_type) uni_s);
        }
        else if (g_calc_cntx->Operator == CALC_OP_NONE)
        {
            if (g_calc_cntx->CurrHilite < CALC_OP_EQUAL)    /* +,-,*,/ */
            {
                switch (g_calc_cntx->CurrHilite)
                {
                    case CALC_OP_PLUS:
                        op = CALC_SYM_PLUS;
                        break;
                    case CALC_OP_MINUS:
                        op = CALC_SYM_MINUS;
                        break;
                    case CALC_OP_MULT:
                        op = CALC_SYM_MUL;
                        break;
                    case CALC_OP_DIV:
                        op = CALC_SYM_DIV;
                        break;
                    default:
                        break;
                }

                temp_res = gui_atof((UI_string_type) g_calc_cntx->Operand2Buf);
                CalcDouble2String(temp_res, uni_s, CALC_MAX_DIGITS);

                w = gui_get_string_width((UI_string_type) uni_s);
#if defined(__MMI_TOUCH_CALCULATOR__)
                CalcMoveTextCursor(
                        r2lMMIFlag, 
                        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                        calculator_keypad.operand2_y,
                        w);
 #else  
                CalcMoveTextCursor(r2lMMIFlag,  CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND1_Y, w);              
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
                gui_print_text((UI_string_type) uni_s);

                w = gui_get_character_width(CALC_SYM_ZERO);
#if defined(__MMI_TOUCH_CALCULATOR__)
                CalcMoveTextCursor(
                        r2lMMIFlag,
                        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                        calculator_keypad.operand2_y,
                        w);
#else  
                CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
                gui_print_character(CALC_SYM_ZERO);
            }
            else
            {
                op = CALC_SYM_NULL;
                if (g_calc_cntx->Operand2Buf[0] == CALC_SYM_NULL)
                {
                    w = gui_get_character_width(CALC_SYM_ZERO);
#if defined(__MMI_TOUCH_CALCULATOR__)
                    CalcMoveTextCursor(
                            r2lMMIFlag,
                            calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                            calculator_keypad.operand2_y,
                            w);
#else  
                    CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */
                    gui_print_character(CALC_SYM_ZERO);
                }
                else
                {
                    w = gui_get_string_width(g_calc_cntx->Operand2Buf);
#if defined(__MMI_TOUCH_CALCULATOR__)
                    CalcMoveTextCursor(
                            r2lMMIFlag,
                            calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                            calculator_keypad.operand2_y,
                            w);
#else  
                    CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
                    gui_print_text(g_calc_cntx->Operand2Buf);
                }
            }
        }
        else
        {
            switch (g_calc_cntx->Operator)
            {
                case CALC_OP_PLUS:
                    op = CALC_SYM_PLUS;
                    break;
                case CALC_OP_MINUS:
                    op = CALC_SYM_MINUS;
                    break;
                case CALC_OP_MULT:
                    op = CALC_SYM_MUL;
                    break;
                case CALC_OP_DIV:
                    op = CALC_SYM_DIV;
                    break;
                default:
                    break;
            }

            CalcDouble2String(g_calc_cntx->Operand1, uni_s, CALC_MAX_DIGITS);
            g_calc_cntx->Operand1 = gui_atof((UI_string_type) uni_s);

            w = gui_get_string_width((UI_string_type) uni_s);
#if defined(__MMI_TOUCH_CALCULATOR__)
            CalcMoveTextCursor(
                    r2lMMIFlag,
                     calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                    calculator_keypad.operand1_y,
                    w);
#else  
            CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND1_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
            gui_print_text((UI_string_type) uni_s);

            w = gui_get_string_width(g_calc_cntx->Operand2Buf);
            if (g_calc_cntx->Operand2Buf[0] == CALC_SYM_NULL)
            {
                w = gui_get_character_width(CALC_SYM_ZERO);
#if defined(__MMI_TOUCH_CALCULATOR__)
                CalcMoveTextCursor(
                        r2lMMIFlag, 
                        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                        calculator_keypad.operand2_y,
                        w);
#else 
                CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
                gui_print_character(CALC_SYM_ZERO);
            }
            else
            {
#if defined(__MMI_TOUCH_CALCULATOR__)
                CalcMoveTextCursor(
                        r2lMMIFlag, 
                        calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                        calculator_keypad.operand2_y,
                        w);
#else 
                CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_SCR_WIDTH - w - 4, CALC_OPERAND2_Y, w);
 #endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
                gui_print_text(g_calc_cntx->Operand2Buf);
            }
        }
#ifndef __MMI_SLIM_CALCULATOR__
        /* memory field */
        CalcDouble2String(g_calc_cntx->MemValue, uni_memory, CALC_MAX_DIGITS);
        g_calc_cntx->MemValue = gui_atof((UI_string_type) uni_memory);
#if !defined(__MMI_TOUCH_CALCULATOR__)
        mmi_ucs2cat((S8*) uni_memory, (S8*) (L" ")); /* for touch, no "]" in memory area */
#endif        
        w = gui_get_string_width((UI_string_type) uni_memory);
#if defined(__MMI_TOUCH_CALCULATOR__)
        CalcMoveTextCursor(
                r2lMMIFlag,
                calculator_keypad.result_area_x + CALC_TOUCH_RESULT_AREA_WIDTH - w - 4,
                calculator_keypad.mem_y1, 
                w);
#else 
        CalcMoveTextCursor(r2lMMIFlag, CALC_SCR_X + CALC_MEM_X2 - w - 4, CALC_MEM_Y1, w);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
        gui_print_text((UI_string_type) uni_memory);

#endif /* __MMI_SLIM_CALCULATOR__ */ 
    }   /* if(g_calc_cntx->ResultState == RESULT_EXCEED) */

    /* operator */
#if defined(__MMI_TOUCH_CALCULATOR__)        
    CalcMoveTextCursor(r2lMMIFlag, calculator_keypad.operator_x, calculator_keypad.operator_y, CALC_RESERVED_SPACE_FOR_OPERATOR);
#else 
    CalcMoveTextCursor(r2lMMIFlag, CALC_OPERATOR_X, CALC_OPERATOR_Y, CALC_RESERVED_SPACE_FOR_OPERATOR);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
    gui_print_character((UI_character_type) op);

    if (g_calc_cntx->RSKState == CALC_RSK_CLEAR)
    {
        CalcSetRSKClear();
    }
    else
    {
        CalcSetRSKBack();
    }

    show_softkey_background();
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
#if defined(__MMI_TOUCH_CALCULATOR__)
    gui_BLT_double_buffer(
        TOUCH_CALC_SCREEN_X,
        TOUCH_CALC_SCREEN_Y,
        TOUCH_CALC_SCREEN_X + TOUCH_CALC_SCREEN_WIDTH - 1,
        TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
#else /* defined(__MMI_TOUCH_CALCULATOR__) */ 
    gui_BLT_double_buffer(CALC_SCR_X, CALC_SCR_Y, CALC_SCR_X + CALC_SCR_WIDTH - 1, CALC_SCR_Y + CALC_SCR_HEIGHT - 1);
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
}

/* 041205 Calvin added */
#if defined(__MMI_TOUCH_CALCULATOR__) /* && defined(__MMI_MAINLCD_240X320__) */ /* 060105 Calvin modified */
extern MMI_ID_TYPE idle_screen_wallpaper_ID;
extern gdi_handle wgui_base_layer;
extern gdi_handle wgui_layer_1;
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 
/* Calvin end */


/*****************************************************************************
 * FUNCTION
 *  CalcRedraw
 * DESCRIPTION
 *  Redraw calculator screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcRedraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_reset_clip();

    clear_screen();
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
	
#if defined(__MMI_TOUCH_CALCULATOR__)
    setup_calculator_keypad(&calculator_keypad, TOUCH_CALC_SCREEN_X, TOUCH_CALC_SCREEN_Y);
    MMI_menu_shortcut_number = -1;
	
/*shaokai delete it.start	 090813
#if !defined (__MMI_MAINLCD_320X240__)
#ifndef GUI_COMMON_SHOW_STATUS_ICON
    move_title(0,0);
#else
    show_title_status_icon();
#endif
#ifdef GUI_COMMON_USE_THICK_TITLE
    wgui_title_set_thick(MMI_TRUE);
#else
    wgui_title_set_thick(MMI_FALSE);
#endif
    ChangeTitleString((U8*) get_string(STR_ID_CALC_MENU));
    ChangeTitleIcon(GetRootTitleIcon(EXTRA_CALCULATOR_MENU));
    draw_title();
#endif
shaokai delete it.end 090813*/
    /*shaokai add it.start 090814*/
    gdi_image_draw_id(0, 0, IMG_ID_TOUCH_CALC_TITLE);
    gui_move_text_cursor(85,3);
    gui_set_text_color(UI_COLOR_WHITE);
    gui_print_text(get_string(STR_ID_CALC_MENU));
    /*shaokai add it.end 090814*/
    show_touch_calculator_screen(
        TOUCH_CALC_SCREEN_X,
        TOUCH_CALC_SCREEN_Y,
        TOUCH_CALC_SCREEN_WIDTH,
        TOUCH_CALC_SCREEN_HEIGHT);
    CalcShowResultScreen();
	
#else /* defined(__MMI_TOUCH_CALCULATOR__) */ 

#if defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__)
    MMI_disable_title_shortcut_display = 1;
#ifndef GUI_COMMON_SHOW_STATUS_ICON
    move_title(0,0);
#else
    show_title_status_icon();    
#endif
#ifdef GUI_COMMON_USE_THICK_TITLE
    wgui_title_set_thick(MMI_TRUE);
#else
    wgui_title_set_thick(MMI_FALSE);
#endif
    ChangeTitleString((U8*) get_string(STR_ID_CALC_MENU));
    ChangeTitleIcon(GetRootTitleIcon(EXTRA_CALCULATOR_MENU));
    draw_title();
#endif /* defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

    CalcShowKeypad();
    CalcShowResultScreen();
#endif /* defined(__MMI_TOUCH_CALCULATOR__) */ 

    show_softkey_background();
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    show_left_softkey();
    show_right_softkey();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  CalcSearchDecimal
 * DESCRIPTION
 *  To search if there is a decimal point in current operand.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if decimal exists; otherwise, FALSE.
 *****************************************************************************/
U8 CalcSearchDecimal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Operand2Len > 1)
    {
        for (index = 0; index < g_calc_cntx->Operand2Len; index++)
        {
            if (g_calc_cntx->Operand2Buf[index] == CALC_SYM_DOT)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CalcInsertChar
 * DESCRIPTION
 *  Insert a character to result screen.
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CalcInsertChar(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_calc_cntx->ComputeType = CALC_OP_NONE;
    /* if operand2 = -(12 digit) || (12 digit) */
    if ((g_calc_cntx->Operand2Buf[0] == CALC_SYM_MINUS && g_calc_cntx->Operand2Len >= (CALC_MAX_DIGITS + 2)) ||
        (g_calc_cntx->Operand2Buf[0] != CALC_SYM_MINUS && g_calc_cntx->Operand2Len >= (CALC_MAX_DIGITS + 1)))
    {
        playRequestedTone(ERROR_TONE);
        return;
    }

    if ((g_calc_cntx->Operand2Buf[0] == CALC_SYM_ZERO) &&
        (g_calc_cntx->Operand2Len <=2) && (c == CALC_SYM_ZERO))
    {/* input 0 after 0, ignore this case */
        CalcShowResultScreen();
        return;
    }

    if ((g_calc_cntx->Operand2Buf[0] == CALC_SYM_ZERO) && 
        (c != CALC_SYM_ZERO) && (g_calc_cntx->Operand2Buf[1] != CALC_SYM_DOT))
    {/* input 9 after  0, replace 0 with 9*/
        g_calc_cntx->Operand2Buf[0] = CALC_SYM_NULL;
        g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
    }


    if (g_calc_cntx->Operator == CALC_OP_EQUAL)
    {
        g_calc_cntx->Operator = CALC_OP_NONE;
        g_calc_cntx->Operand1 = 0;
        g_calc_cntx->Operand2 = 0;
        g_calc_cntx->Operand2Len = 1;
        g_calc_cntx->Operand2Buf[0] = CALC_SYM_NULL;
        g_calc_cntx->OpToExecute = CALC_OP_NONE;
    }

    if (c == CALC_SYM_DOT && g_calc_cntx->Operand2Len == CALC_ZEOR_LEN) /* insert "." after zero */
    {
        g_calc_cntx->Operand2Buf[0] = CALC_SYM_ZERO;
        g_calc_cntx->Operand2Len++;
    }

    g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len - 1] = (UI_character_type) c;
    g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len] = CALC_SYM_NULL;
    g_calc_cntx->Operand2Len++;
    g_calc_cntx->RSKState = CALC_RSK_CLEAR;

    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcExecMR
 * DESCRIPTION
 *  Execute MR operator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_SLIM_CALCULATOR__
void CalcExecMR(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalcResetResultValue();

    CalcDouble2String(g_calc_cntx->MemValue, (S8*) g_calc_cntx->Operand2Buf, CALC_MAX_DIGITS);

    g_calc_cntx->Operand2Len = mmi_ucs2strlen((S8*) g_calc_cntx->Operand2Buf) + 1;
  
#ifndef __MMI_TOUCH_CALCULATOR__
    if (g_calc_cntx->Operand2Len > 1)
#else
    if ((g_calc_cntx->Operand2Len > 1)&&(g_calc_cntx->MemValue != 0)) /* if memvalue is 0, not set clear*/
#endif /* __MMI_TOUCH_CALCULATOR__ */ 
    {
        g_calc_cntx->RSKState = CALC_RSK_CLEAR;
    }
    else
    {
        g_calc_cntx->RSKState = CALC_RSK_BACK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcExecMP
 * DESCRIPTION
 *  Execute M+ operator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcExecMP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE temp_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Operand2Buf[0] != CALC_SYM_NULL)
    {
        temp_res = gui_atof((UI_string_type) g_calc_cntx->Operand2Buf);

        g_calc_cntx->MemValue += temp_res;

        if (!mmi_calc_check_boundary(g_calc_cntx->MemValue))
        {
            g_calc_cntx->ResultState = RESULT_EXCEED;
            playRequestedTone(ERROR_TONE);
            g_calc_cntx->MemValue = 0;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcExecMM
 * DESCRIPTION
 *  Execute M- operator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcExecMM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE temp_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Operand2Buf[0] != CALC_SYM_NULL)
    {
        temp_res = gui_atof((UI_string_type) g_calc_cntx->Operand2Buf);

        g_calc_cntx->MemValue -= temp_res;
        if (!mmi_calc_check_boundary(g_calc_cntx->MemValue))
        {
            g_calc_cntx->ResultState = RESULT_EXCEED;
            playRequestedTone(ERROR_TONE);
            g_calc_cntx->MemValue = 0;
        }
    }
}
#endif /* __MMI_SLIM_CALCULATOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  CalcGetCurrOperand
 * DESCRIPTION
 *  Convert the string of operand 1 to number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcGetCurrOperand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Operand2Buf[0] == CALC_SYM_NULL)
    {
        g_calc_cntx->Operand1 = 0;
    }
    else
    {
        g_calc_cntx->Operand1 = gui_atof((UI_string_type) g_calc_cntx->Operand2Buf);
        /* 06/01/11, for bug of displaying "-0" */
        if (g_calc_cntx->Operand1 == -0)
        {
            g_calc_cntx->Operand1 = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcGetPreOperand
 * DESCRIPTION
 *  Convert the string of operand 2 to number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcGetPreOperand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->Operand2Buf[0] == CALC_SYM_NULL)
    {
        g_calc_cntx->Operand2 = 0;
    }
    else
    {
        g_calc_cntx->Operand2 = gui_atof((UI_string_type) g_calc_cntx->Operand2Buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_calc_check_boundary
 * DESCRIPTION
 *  Check the boundary of the calculated result.
 * PARAMETERS
 *  value       [IN]        Value to be checked
 * RETURNS
 *  0  out of the boundary
 *  1  within the boundary
 *****************************************************************************/
U8 mmi_calc_check_boundary(DOUBLE value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 uni_s[64];
    S8 ansii_str[CALC_MAX_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(uni_s, 0, sizeof(uni_s));
    memset(ansii_str, 0, CALC_MAX_BUFF_LEN);
    if (value < 0)
    {
        value = -(value);
    }
    CalcDouble2String(value, uni_s, CALC_MAX_DIGITS);
    mmi_ucs2_to_asc((S8*) ansii_str, (S8*) uni_s);
    if (strlen(ansii_str) > CALC_MAX_DIGITS)
    {
        return RESULT_NOT_EXCEED;
    }
    else
    {
        return RESULT_EXCEED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcExecOperator
 * DESCRIPTION
 *  Execute current computation operation.
 * PARAMETERS
 *  op1     [IN]        
 *  op2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
DOUBLE CalcExecOperator(DOUBLE op1, DOUBLE op2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalcSetRSKClear();

    switch (g_calc_cntx->OpToExecute)
    {
        case CALC_OP_PLUS:
            result = op1 + op2;
            break;
        case CALC_OP_MINUS:
            result = op1 - op2;
            break;
        case CALC_OP_MULT:
            result = op1 * op2;
            break;
        case CALC_OP_DIV:
            if (op2 > 0)
            {
                result = (DOUBLE) op1 / op2;
            }
			else if (op2 == 0)
			{
				g_calc_cntx->ResultState = RESULT_EXCEED;
				playRequestedTone(ERROR_TONE);
				return 0;
			}
            break;
        default:
            return 0;
    }

    if (!mmi_calc_check_boundary(result))
    {
        g_calc_cntx->ResultState = RESULT_EXCEED;
        playRequestedTone(ERROR_TONE);
        return 0;
    }

    return (result);
}


/*****************************************************************************
 * FUNCTION
 *  CalcComputeResult
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcComputeResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        switch (g_calc_cntx->CurrHilite)
        {
        #ifndef __MMI_SLIM_CALCULATOR__
            case CALC_OP_MR:
            {
                CalcExecMR();
                g_calc_cntx->Operator = CALC_OP_NONE;
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                g_calc_cntx->ComputeType = CALC_OP_MR;

                break;
            }
            case CALC_OP_MC:
            {
                CalcResetMemValue();
                g_calc_cntx->Operator = CALC_OP_NONE;
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                g_calc_cntx->ComputeType = CALC_OP_MC;

                break;
            }
            case CALC_OP_MP:
            {
                CalcExecMP();

                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                g_calc_cntx->Operator = CALC_OP_NONE;
                g_calc_cntx->ComputeType = CALC_OP_MP;

                break;
            }
            case CALC_OP_MM:
            {
                CalcExecMM();

                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                g_calc_cntx->Operator = CALC_OP_NONE;
                g_calc_cntx->ComputeType = CALC_OP_MM;

                break;
            }
        #endif /* __MMI_SLIM_CALCULATOR__ */ 
            default:
            {
                if (g_calc_cntx->Operator != CALC_OP_NONE)
                {
                    g_calc_cntx->ComputeType = g_calc_cntx->Operator;
                    g_calc_cntx->Operator = CALC_OP_EQUAL;

                    CalcGetPreOperand();
                    if ((g_calc_cntx->Operand2 == 0) && (g_calc_cntx->OpToExecute == CALC_OP_DIV))
                    {
                        g_calc_cntx->ResultState = RESULT_EXCEED;
                        CalcSetRSKClear();
                        g_calc_cntx->Operator = CALC_OP_NONE;
                        playRequestedTone(ERROR_TONE);
                    }
                    else
                    {
                        if (g_calc_cntx->OpToExecute != CALC_OP_NONE)
                        {
                            g_calc_cntx->Operand1 = CalcExecOperator(g_calc_cntx->Operand1, g_calc_cntx->Operand2);
                            g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                            g_calc_cntx->OpToExecute = CALC_OP_NONE;
                        }
                    }
                }
                else
                {
                    g_calc_cntx->ComputeType = CALC_OP_EQUAL;
                    g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                }
                break;
            }
        }
        g_calc_cntx->ExecFlag = TRUE;
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }

#if !defined(__MMI_TOUCH_CALCULATOR__)
    CalcShowKeypad();
#endif 
    CalcShowResultScreen();

}

#define CALC_KEY_HILITE_HANDLER


/*****************************************************************************
 * FUNCTION
 *  CalcHandleHiliteMemoryButton
 * DESCRIPTION
 *  Highlight handler of memory button.
 *  Move operand to result filed and clear all others.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleHiliteMemoryButton(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CalcDouble2String(g_calc_cntx->Operand1, (S8*) g_calc_cntx->Operand2Buf, CALC_MAX_DIGITS);

    g_calc_cntx->Operator = CALC_OP_NONE;
    g_calc_cntx->ComputeType = CALC_OP_NONE;

    if (g_calc_cntx->Operand1 != 0)
    {
        g_calc_cntx->Operand2Len = mmi_ucs2strlen((S8*) g_calc_cntx->Operand2Buf) + 1;
    }
    else
    {
        g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
    }

}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleHiliteOperator
 * DESCRIPTION
 *  Execute correspoding operation when highlighting on opeartor.
 *  Dislpay operator, calculator reslut, and add new operand.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleHiliteOperator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PreOperator = g_calc_cntx->Operator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_calc_cntx->ExecFlag = FALSE;

    g_calc_cntx->Operator = g_calc_cntx->CurrHilite;
    g_calc_cntx->ComputeType = CALC_OP_NONE;
    /* start vijay 20050616.......RSK should not be changed to CLEAR key when pressed these buttons */
#ifdef __MMI_TOUCH_CALCULATOR__
    if (!(g_calc_cntx->Operator == CALC_OP_MP || g_calc_cntx->Operator == CALC_OP_MM ||
          g_calc_cntx->Operator == CALC_OP_MR || g_calc_cntx->Operator == CALC_OP_MC))
    {
        g_calc_cntx->RSKState = CALC_RSK_CLEAR;
    }
#else /* __MMI_TOUCH_CALCULATOR__ */ 
    g_calc_cntx->RSKState = CALC_RSK_CLEAR;
#endif /* __MMI_TOUCH_CALCULATOR__ */ 
    /* end vijay */
    switch (PreOperator)
    {
        case CALC_OP_PLUS:
        case CALC_OP_MINUS:
        case CALC_OP_MULT:
        case CALC_OP_DIV:
            if (g_calc_cntx->Operand2Buf[0] != CALC_SYM_NULL)
            {
                g_calc_cntx->OpToExecute = PreOperator;
                CalcGetPreOperand();
                g_calc_cntx->Operand1 = CalcExecOperator(g_calc_cntx->Operand1, g_calc_cntx->Operand2);
                /* g_calc_cntx->OpToExecute = g_calc_cntx->Operator; */
                break;
            }
            else
            {
                g_calc_cntx->OpToExecute = g_calc_cntx->Operator;
                return;
            }
        #ifndef __MMI_SLIM_CALCULATOR__
        case CALC_OP_MP:
        case CALC_OP_MM:
        case CALC_OP_MR:
        case CALC_OP_MC:
        #endif /* __MMI_SLIM_CALCULATOR__ */ 
        case CALC_OP_NONE:
            CalcGetCurrOperand();
        default:
            break;
    }

    g_calc_cntx->OpToExecute = g_calc_cntx->Operator;
    memcpy(g_calc_cntx->Operand1Buf, g_calc_cntx->Operand2Buf, sizeof(g_calc_cntx->Operand1Buf));
    g_calc_cntx->Operand1Len = g_calc_cntx->Operand2Len;

    g_calc_cntx->Operand2 = 0;
    g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
    g_calc_cntx->Operand2Buf[0] = CALC_SYM_NULL;
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleLeftKey
 * DESCRIPTION
 *  Left arrow key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleLeftKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        switch (g_calc_cntx->CurrHilite)
        {
                /* start Sophie 050904 */
        #ifdef __MMI_SLIM_CALCULATOR__
            case CALC_OP_MULT:
                return;
        #else /* __MMI_SLIM_CALCULATOR__ */ 
            case CALC_OP_MC:
                return;
            case CALC_OP_MR:
            {
                g_calc_cntx->CurrHilite = CALC_OP_DIV;
                CalcHandleHiliteOperator();
                break;
            }
            case CALC_OP_MULT:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MC;
                CalcHandleHiliteMemoryButton();
                break;
            }
            case CALC_OP_MP:
            case CALC_OP_MM:
        #endif /* __MMI_SLIM_CALCULATOR__ */ /* end of ifdef __MMI_SLIM_CALCULATOR__ */
                /* end Sophie */
            case CALC_OP_PLUS:
            case CALC_OP_MINUS:
            case CALC_OP_EQUAL:
            case CALC_OP_DIV:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MULT;
                CalcHandleHiliteOperator();
                break;
            }
            default:
            {
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                break;
            }
        }
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }

    CalcShowKeypad();
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleRightKey
 * DESCRIPTION
 *  Right arrow key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleRightKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        switch (g_calc_cntx->CurrHilite)
        {
                /* start Sophie 050904 */
        #ifdef __MMI_SLIM_CALCULATOR__
            case CALC_OP_DIV:
                return;
        #else /* __MMI_SLIM_CALCULATOR__ */ 
            case CALC_OP_MR:
                return;
            case CALC_OP_MC:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MULT;
                CalcHandleHiliteOperator();
                break;
            }
            case CALC_OP_DIV:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MR;
                CalcHandleHiliteMemoryButton();
                break;
            }
            case CALC_OP_MP:
            case CALC_OP_MM:
        #endif /* __MMI_SLIM_CALCULATOR__ */ /* end of ifdef __MMI_SLIM_CALCULATOR__ */
                /* end Sophie */
            case CALC_OP_PLUS:
            case CALC_OP_MINUS:
            case CALC_OP_MULT:
            case CALC_OP_EQUAL:
            {
                g_calc_cntx->CurrHilite = CALC_OP_DIV;
                CalcHandleHiliteOperator();
                break;
            }
            default:
            {
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                break;
            }
        }
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }

    CalcShowKeypad();
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleUpKey
 * DESCRIPTION
 *  Up arrow key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleUpKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        switch (g_calc_cntx->CurrHilite)
        {
                /* start Sophie 050904 */
        #ifdef __MMI_SLIM_CALCULATOR__
            case CALC_OP_PLUS:
                return;
        #else /* __MMI_SLIM_CALCULATOR__ */ 
            case CALC_OP_MP:
                return;
            case CALC_OP_MM:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MINUS;
                CalcHandleHiliteOperator();
                break;
            }
            case CALC_OP_PLUS:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MP;
                CalcHandleHiliteMemoryButton();
                break;
            }
            case CALC_OP_MR:
            case CALC_OP_MC:
        #endif /* __MMI_SLIM_CALCULATOR__ */ /* end of ifdef __MMI_SLIM_CALCULATOR__ */
                /* end Sophie */
            case CALC_OP_DIV:
            case CALC_OP_MULT:
            case CALC_OP_EQUAL:
            case CALC_OP_MINUS:
            {
                g_calc_cntx->CurrHilite = CALC_OP_PLUS;
                CalcHandleHiliteOperator();
                break;
            }
            default:
            {
                g_calc_cntx->CurrHilite = CALC_OP_PLUS;
                break;
            }
        }
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }

    CalcShowKeypad();
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleDownKey
 * DESCRIPTION
 *  Down arrow key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleDownKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        switch (g_calc_cntx->CurrHilite)
        {
                /* start Sophie 050904 */
        #ifdef __MMI_SLIM_CALCULATOR__
            case CALC_OP_MINUS:
                return;
        #else /* __MMI_SLIM_CALCULATOR__ */ 
            case CALC_OP_MM:
                return;
            case CALC_OP_MP:
            {
                g_calc_cntx->CurrHilite = CALC_OP_PLUS;
                CalcHandleHiliteOperator();
                break;
            }
            case CALC_OP_MINUS:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MM;
                CalcHandleHiliteMemoryButton();
                break;
            }
            case CALC_OP_MR:
            case CALC_OP_MC:
        #endif /* __MMI_SLIM_CALCULATOR__ */ 
                /* end Sophie */
            case CALC_OP_DIV:
            case CALC_OP_MULT:
            case CALC_OP_EQUAL:
            case CALC_OP_PLUS:
            {
                g_calc_cntx->CurrHilite = CALC_OP_MINUS;
                CalcHandleHiliteOperator();
                break;
            }
            default:
            {
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
                break;
            }
        }
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }

    CalcShowKeypad();
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleNumKey
 * DESCRIPTION
 *  Handle number key input
 * PARAMETERS
 *  key_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleNumKey(S32 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        if (g_calc_cntx->ExecFlag)
        {
            CalcResetResultValue();
        }

        if (g_calc_cntx->CurrHilite <= CALC_OP_EQUAL)   /* operators */
        {
            g_calc_cntx->CurrHilite = CALC_OP_EQUAL;
        #if !defined(__MMI_TOUCH_CALCULATOR__)
            CalcShowKeypad();
        #endif 
        }

        CalcInsertChar((UI_character_type) ('0' + key_code));
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandlePoundKey
 * DESCRIPTION
 *  Pound key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandlePoundKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_NOT_EXCEED)
    {
        if (g_calc_cntx->ExecFlag)
        {
            CalcResetResultValue();
        }

        if (g_calc_cntx->Operand2Len == 1)
        {
            CalcInsertChar(CALC_SYM_DOT);
        }
        else if (!CalcSearchDecimal())
        {
            CalcInsertChar(CALC_SYM_DOT);
        }
    }
    else
    {
        playRequestedTone(ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleEndKey
 * DESCRIPTION
 *  End key handler of calculator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CalcDeInit(); */
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleClearKey
 * DESCRIPTION
 *  Clear key handler of calculator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleClearKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx->ResultState == RESULT_EXCEED)
    {
        CalcResetContext();
    }
    else if (g_calc_cntx->Operator != CALC_OP_NONE)
    {
        if (g_calc_cntx->Operator != CALC_OP_EQUAL)
        {
            if ((g_calc_cntx->Operand2Buf[0] == CALC_SYM_ZERO) && (g_calc_cntx->Operand2Buf[1] == CALC_SYM_NULL))
            {/* when operand2 is 0,  do "clear" will go to the same operation with the case that operand2 is NULL */
                g_calc_cntx->Operand2Buf[0] = CALC_SYM_NULL;
                g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
            }
            if (g_calc_cntx->Operand2Len > CALC_ZEOR_LEN)
            {
                g_calc_cntx->Operand2Len--;
                /* '-x' */
                if(g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len - 2] == CALC_SYM_MINUS)
                {
                    g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
                }
                g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len - 1] = '\0';

            }
            else
            {
                g_calc_cntx->Operator = CALC_OP_NONE;
                g_calc_cntx->CurrHilite = CALC_OP_EQUAL;

                if (g_calc_cntx->Operand1 == 0)
                {
                    CalcResetResultValue();
                }
                else
                {
                    CalcDouble2String(g_calc_cntx->Operand1, (S8*) g_calc_cntx->Operand2Buf, CALC_MAX_DIGITS);
                    g_calc_cntx->Operand1 = 0;
                    g_calc_cntx->Operand2Len = mmi_ucs2strlen((S8*) g_calc_cntx->Operand2Buf) + 1;
                }
            }
        }
        else    /* display result after calculator, operator == equal */
        {
            CalcResetResultValue();
        }
    }
    else
    {
        if (g_calc_cntx->ComputeType >= CALC_OP_EQUAL && g_calc_cntx->ComputeType < CALC_OP_NONE)       /* Move to Mx and press LSK */
        {
            CalcResetResultValue();
        }
        else    /* Move to Mx */
        {
            g_calc_cntx->Operand2Len--;

            /* current operand ==  "-x" */
            if(g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len - 2] == CALC_SYM_MINUS)
            {
                g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
            }
            else
            {
                g_calc_cntx->Operand2Buf[g_calc_cntx->Operand2Len - 1] = '\0';
            }

            if (g_calc_cntx->Operand2Len <= 1)
            {
                CalcResetResultValue();
            }
        }

    }

    if (g_calc_cntx->Operand2Buf[0] == CALC_SYM_ZERO && g_calc_cntx->Operand2Buf[1] == CALC_SYM_NULL)
    {
        g_calc_cntx->Operand2Len = CALC_ZEOR_LEN;
    }
    /* start vijay 20050307 */
#if !defined(__MMI_TOUCH_CALCULATOR__)
    CalcShowKeypad();
#endif 
    /* end vijay */
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcHandleRSKLongPress
 * DESCRIPTION
 *  Reset calculator to defualt state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcHandleRSKLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_calc_cntx->IsRSKPress = TRUE;
    CalcResetResultValue();
#ifndef __MMI_TOUCH_CALCULATOR__
    CalcShowKeypad();
#endif 
    CalcShowResultScreen();
}


/*****************************************************************************
 * FUNCTION
 *  CalcRegisterKeyHandler
 * DESCRIPTION
 *  Register key handler of calculator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcRegisterKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifndef __MMI_TOUCH_CALCULATOR__ //sc.wu Register key handler of calculator . ARROW
    SetKeyHandler(CalcHandleLeftKey, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(CalcHandleRightKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(CalcHandleUpKey, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(CalcHandleDownKey, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(CalcComputeResult, KEY_EVENT_UP);
    SetKeyHandler(CalcHandleEndKey, KEY_END, KEY_EVENT_DOWN);
//#endif /* __MMI_TOUCH_CALCULATOR__ */ 
    SetKeyHandler(CalcHandlePoundKey, KEY_POUND, KEY_EVENT_UP);
    /* start vijay 20050603...moved outside the ifdefs for soft key's implementation */
    SetLeftSoftkeyFunction(CalcComputeResult, KEY_EVENT_UP);
    /* end vijay */
    if (g_calc_cntx->RSKState == CALC_RSK_BACK)
    {
        CalcSetRSKBack();
    }
    else
    {
        CalcSetRSKClear();
    }

    register_MMI_key_input_handler();
    register_key_down_handler(CalcHandleNumKey);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCalcApp
 * DESCRIPTION
 *  Exit function of calculator application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCalcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_disable_title_shortcut_display = 0;
#ifdef __MMI_TOUCH_CALCULATOR__
    if (calculator_keypad.selected_key_bitmap.buf_ptr != NULL)
    {
        mmi_frm_scrmem_free(calculator_keypad.selected_key_bitmap.buf_ptr);
        calculator_keypad.selected_key_bitmap.buf_ptr = NULL;
    }
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  EntryCalcApp
 * DESCRIPTION
 *  Entry function of calculator application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCalcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALC_APP, ExitCalcApp, EntryCalcApp, MMI_FULL_SCREEN);
    SetDelScrnIDCallbackHandler(SCR_ID_CALC_APP, (HistoryDelCBPtr) mmi_calc_del_scr_callback);
#ifndef __MMI_TOUCH_CALCULATOR__
#if !defined (__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__)
    entry_full_screen();
#endif 
#else /* __MMI_TOUCH_CALCULATOR__ */ 
#endif /* __MMI_TOUCH_CALCULATOR__ */ 
    CalcRedraw();
    CalcRegisterKeyHandler();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();
#ifdef __MMI_TOUCH_CALCULATOR__
    mmi_pen_register_down_handler(mmi_touchcalc_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_touchcalc_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_touchcalc_pen_move_hdlr);
    mmi_pen_register_repeat_handler(mmi_touchcalc_pen_repeat_hdlr);
    mmi_pen_register_long_tap_handler(mmi_touchcalc_pen_long_tap_hdlr);
#endif /* __MMI_TOUCH_CALCULATOR__ */ 

#if defined(__MMI_WITH_C_KEY__)
    SetKeyHandler(CalcHandleClearKey, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(CalcHandleRSKLongPress, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
#endif /* defined(__MMI_WITH_C_KEY__) */ 

    RedrawCategoryFunction = CalcRedraw;
}


/*****************************************************************************
 * FUNCTION
 *  CalcPreEntryApp
 * DESCRIPTION
 *  Initialize data before entry calculator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcPreEntryApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_calc_cntx == NULL)
    {
        g_calc_cntx = OslMalloc(sizeof(calc_context_struct));
    }

    memset(g_calc_cntx, 0, sizeof(calc_context_struct));

    /* initialize image */
    /* 050905 Sophie modified start */
#ifdef __MMI_SLIM_CALCULATOR__
    for (i = CALC_OP_PLUS; i <= CALC_OP_EQUAL; i++)
#else 
    for (i = CALC_OP_PLUS; i < CALC_OP_NONE; i++)
#endif 
        /* 050905 Sophie modified end  */
    {
        g_calc_cntx->OperatorImg[i].x = gCalcImgCoor[i][0];
        g_calc_cntx->OperatorImg[i].y = gCalcImgCoor[i][1];
        g_calc_cntx->OperatorImg[i].image = (PU8) GetImage((U16) (IMG_ID_CALC_PLUS + i));
    }

    /* initialize keys */
    CalcResetContext();
    EntryCalcApp();
}

#ifdef __MMI_TOUCH_CALCULATOR__


/*****************************************************************************
 * FUNCTION
 *  mmi_touchcalc_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touchcalc_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_calc_pen_enum calc_menu_event;
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_DOWN, point.x, point.y, &button_event);
    if (ret)
    {
        calc_pen_on_object = TOUCH_CALC_PEN_LSK;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        }
    }
    ret = translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_DOWN, point.x, point.y, &button_event);
    if (ret)
    {
        calc_pen_on_object = TOUCH_CALC_PEN_RSK;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        }
    }
    ret = gui_calculator_translate_pen_event(&calculator_keypad, point.x, point.y, &calc_menu_event, MMI_PEN_EVENT_DOWN);
    if (ret)
    {
        calc_pen_on_object = TOUCH_CALC_PEN_NUM_KEY;
        if (calc_menu_event == GUI_CALC_PEN_HIGHLIGHT_CHANGED)
        {
            gui_BLT_double_buffer(
                TOUCH_CALC_SCREEN_X,
                TOUCH_CALC_SCREEN_Y,
                UI_device_width - 1,
                TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_touchcalc_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touchcalc_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    gui_calc_pen_enum calc_menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (calc_pen_on_object)
    {
        case TOUCH_CALC_PEN_NUM_KEY:
            gui_calculator_translate_pen_event(
                &calculator_keypad,
                point.x,
                point.y,
                &calc_menu_event,
                MMI_PEN_EVENT_UP);
            if (calc_menu_event == GUI_CALC_PEN_HIGHLIGHT_CHANGED)
            {
                gui_BLT_double_buffer(
                    TOUCH_CALC_SCREEN_X,
                    TOUCH_CALC_SCREEN_Y,
                    UI_device_width - 1,
                    TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
            }
            break;
        case TOUCH_CALC_PEN_LSK:
            translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_UP, point.x, point.y, &button_event);
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
            break;
        case TOUCH_CALC_PEN_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_UP, point.x, point.y, &button_event);
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
            }
            break;
    }
    calc_pen_on_object = TOUCH_CALC_PEN_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_touchcalc_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touchcalc_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;
    gui_calc_pen_enum calc_menu_event;
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (calc_pen_on_object)
    {
        case TOUCH_CALC_PEN_NUM_KEY:
            gui_calculator_translate_pen_event(
                &calculator_keypad,
                point.x,
                point.y,
                &calc_menu_event,
                MMI_PEN_EVENT_MOVE);
            if (calc_menu_event == GUI_CALC_PEN_HIGHLIGHT_CHANGED)
            {
                TOUCH_CALC_SELECT_KEY = FALSE;
                x1 = calculator_keypad.selected_key_x;
                y1 = calculator_keypad.selected_key_y;
                x2 = x1 + calculator_keypad.key_width;
                y2 = y1 + calculator_keypad.key_height;
                gdi_layer_push_clip();
                gdi_layer_set_clip(x1, y1, x2, y2);
                gdi_image_cache_bmp_draw(x1, y1, &calculator_keypad.selected_key_bitmap);
                gdi_layer_pop_clip();
                gui_BLT_double_buffer(
                    TOUCH_CALC_SCREEN_X,
                    TOUCH_CALC_SCREEN_Y,
                    UI_device_width - 1,
                    TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
            }
            gui_BLT_double_buffer(
                TOUCH_CALC_SCREEN_X,
                TOUCH_CALC_SCREEN_Y,
                UI_device_width - 1,
                TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
            break;
        case TOUCH_CALC_PEN_LSK:
            translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_MOVE, point.x, point.y, &button_event);
            break;
        case TOUCH_CALC_PEN_RSK:
            translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_MOVE, point.x, point.y, &button_event);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_touchcalc_pen_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touchcalc_pen_repeat_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_calc_pen_enum calc_menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (calculator_keypad.flag == CALC_PEN_DOWN_ON_KEYPAD)
    {
        gui_calculator_translate_pen_event(
            &calculator_keypad,
            point.x,
            point.y,
            &calc_menu_event,
            MMI_PEN_EVENT_REPEAT);
        if (calc_menu_event == GUI_CALC_PEN_HIGHLIGHT_CHANGED)
        {
            gui_BLT_double_buffer(
                TOUCH_CALC_SCREEN_X,
                TOUCH_CALC_SCREEN_Y,
                UI_device_width - 1,
                TOUCH_CALC_SCREEN_Y + TOUCH_CALC_SCREEN_HEIGHT - 1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_touchcalc_pen_long_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_touchcalc_pen_long_tap_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (calc_pen_on_object == TOUCH_CALC_PEN_RSK)
    {
        translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_LONG_TAP, point.x, point.y, &button_event);
        if (button_event == GUI_BUTTON_PEN_LONGTAP)
        {
            execute_softkey_function(KEY_LONG_PRESS, MMI_RIGHT_SOFTKEY);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  setup_calculator_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calculator_keypad       [?]         
 *  x                       [IN]        
 *  y                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void setup_calculator_keypad(calculator_keypad_struct *calculator_keypad, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    calculator_keypad->result_area_x = x + CALC_TOUCH_RESULT_AREA_X;
    calculator_keypad->result_area_y = y + CALC_TOUCH_RESULT_AREA_Y;
    /*shaokai modify it.start 090814*/
    calculator_keypad->keypad_x =(5);/*calculator_keypad->result_area_x;*/
    calculator_keypad->keypad_y = (99);/*calculator_keypad->result_area_y + CALC_TOUCH_RESULT_AREA_HEIGHT + CALC_TOUCH_RESULT_KEYPAD_GAP; */     /* 041205 Calvin modified */
    /*shaokai modify it.start 090814*/
    calculator_keypad->keypad_width = CALC_TOUCH_KEYPAD_WIDTH;
    calculator_keypad->keypad_height = CALC_TOUCH_KEYPAD_HEIGHT;
    calculator_keypad->key_width = CALC_TOUCH_KEY_WIDTH;
    calculator_keypad->key_height = CALC_TOUCH_KEY_HEIGHT;
    /*shaokai add it.start 090814*/
    calculator_keypad->key_height1 = (42);
    /*shaokai add it.end 090814*/
    calculator_keypad->key_type = MMI_CALC_KEY_NONE;
    calculator_keypad->horizontal_gap = CALC_TOUCH_HORIZONTAL_GAP;
    calculator_keypad->vertical_gap = CALC_TOUCH_VERTICAL_GAP;
    calculator_keypad->n_column = CALC_TOUCH_NCOLUMNS;
    calculator_keypad->n_rows = CALC_TOUCH_NROWS;
    calculator_keypad->operand1_y = calculator_keypad->result_area_y + CALC_TOUCH_OPERAND1_Y;
    calculator_keypad->operand2_y = calculator_keypad->result_area_y + CALC_TOUCH_OPERAND2_Y;
    calculator_keypad->operator_x = calculator_keypad->result_area_x + CALC_TOUCH_OPERATOR_X;
    calculator_keypad->operator_y = calculator_keypad->operand2_y;
    calculator_keypad->mem_x1 = calculator_keypad->result_area_x + TOUCH_CALC_MEM_X1;
    calculator_keypad->mem_y1 = calculator_keypad->result_area_y + TOUCH_CALC_MEM_Y1;
    calculator_keypad->flag = 0;

}


/*****************************************************************************
 * FUNCTION
 *  show_touch_calculator_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_touch_calculator_screen(S32 x1, S32 y1, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = x1 + width - 1;
    y2 = y1 + height - 1;
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, (PU8) GetImage(IMG_ID_TOUCH_CALC_MAIN));
    gdi_layer_pop_clip();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_calculator_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calculator_keypad       [?]         
 *  x                       [IN]        
 *  y                       [IN]        
 *  item_index              [?]         
 *  key_variable            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calculator_translate_pen_position(
        calculator_keypad_struct *calculator_keypad,
        S32 x,
        S32 y,
        S32 *item_index,
        S32 *key_variable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, total_width = 0;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_height = 0;
    total_width = 0;

    x = x - calculator_keypad->keypad_x + 1;
    y = y - calculator_keypad->keypad_y + 1;

    for (i = 0; i < calculator_keypad->n_rows; i++)
    {
       /*shaokai add it.start 090814*/
        if (i > 0)
        	{
        	   calculator_keypad->key_height = calculator_keypad->key_height1;
        	}
        else
        	{
        	calculator_keypad->key_height = 28;
        	}
	/*shaokai add it.end 090814*/
        total_height += calculator_keypad->key_height;
        if (total_height >= y)
        {
            for (j = 0; j < calculator_keypad->n_column; j++)
            {
                total_width += calculator_keypad->key_width;
                if (total_width >= x)
                {
                    *item_index = i * calculator_keypad->n_column + j + 1;
                    *key_variable = TouchCalcKeys[i][j];
			/*shaokai modify it.start 090814*/
			if (i == 0)
				{
                    calculator_keypad->selected_key_x =
                        calculator_keypad->keypad_x + (calculator_keypad->key_width) * j +
                        (calculator_keypad->horizontal_gap) * j;
                    calculator_keypad->selected_key_y =
                        calculator_keypad->keypad_y + (calculator_keypad->key_height) * i +
                        (calculator_keypad->vertical_gap) * i;
				}
			else
				{
				calculator_keypad->selected_key_x =
                                  calculator_keypad->keypad_x + (calculator_keypad->key_width) * j +
                                  (calculator_keypad->horizontal_gap) * j;
                             calculator_keypad->selected_key_y =
                                  calculator_keypad->keypad_y + (calculator_keypad->key_height) * i +
                                  (calculator_keypad->vertical_gap) * i-(14);//14=42-28           
				}
			/*shaokai modify it.end 090814*/
                    if (i == 0 || j == (calculator_keypad->n_column - 1) ||
                        (*key_variable == TOUCH_CALC_OP_EQUAL && i == calculator_keypad->n_rows - 1))
                    {
                        calculator_keypad->key_type = MMI_CALC_SYM_KEY;
                    }
                    else
                    {
                        calculator_keypad->key_type = MMI_CALC_NUM_KEY;
                    }
                    break;
                }
                else
                {
                    total_width += calculator_keypad->horizontal_gap;
                    if (total_width >= x)
                    {
                        *item_index = -1;
                        return;
                    }
                }

            }
            break;
        }
        else
        {
            total_height += calculator_keypad->vertical_gap;
            if (total_height >= y)
            {
                *item_index = -1;
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_calculator_key_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calculator_keypad       [?]         
 *  item_index              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calculator_key_select(calculator_keypad_struct *calculator_keypad, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width, height;
    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = calculator_keypad->selected_key_x;
    y1 = calculator_keypad->selected_key_y;
    x2 = x1 + calculator_keypad->key_width - 1;
    y2 = y1 + calculator_keypad->key_height - 1;

    if (calculator_keypad->selected_key_bitmap.buf_ptr == NULL )
    {
        calculator_keypad->selected_key_bitmap.buf_ptr = (U8*) mmi_frm_scrmem_alloc(CALC_TOUCH_KEY_WIDTH * CALC_TOUCH_KEY_HEIGHT * (gdi_layer_get_bit_per_pixel()/3));
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &calculator_keypad->selected_key_bitmap);
    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    image_id = calculator_key_image[item_index - 1];
    gui_measure_image(get_image(image_id), &width, &height);
    x1 = x1 + ((calculator_keypad->key_width >> 1) - (width >> 1));
    y1 = y1 + ((calculator_keypad->key_height >> 1) - (height >> 1));
    gui_show_image(x1, y1, get_image(image_id));
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calculator_key_unselect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calculator_keypad       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_calculator_key_unselect(calculator_keypad_struct *calculator_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = calculator_keypad->selected_key_x;
    y1 = calculator_keypad->selected_key_y;
    x2 = x1 + calculator_keypad->key_width - 1;
    y2 = y1 + calculator_keypad->key_height - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_draw(x1, y1, &calculator_keypad->selected_key_bitmap);
    calculator_keypad->selected_key_x = 0;
    calculator_keypad->selected_key_y = 0;
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_calculator_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  calculator_keypad       [?]         
 *  x                       [IN]        
 *  y                       [IN]        
 *  menu_event              [?]         
 *  pen_event               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_calculator_translate_pen_event(
        calculator_keypad_struct *calculator_keypad,
        S32 x,
        S32 y,
        gui_calc_pen_enum *menu_event,
        mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1;
    BOOL ret;
    S32 item_index, key_variable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = calculator_keypad->keypad_x;
    y1 = calculator_keypad->keypad_y;

    ret = TRUE;
    *menu_event = GUI_CALC_PEN_NONE;
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, x1, y1, calculator_keypad->keypad_width, calculator_keypad->keypad_height))
            {
                gui_calculator_translate_pen_position(calculator_keypad, x, y, &item_index, &key_variable);
                if (item_index > MMI_CALC_KEY_START && item_index <= MMI_CALC_KEY_END)
                {
                    calculator_keypad->flag |= CALC_PEN_DOWN_ON_KEYPAD;
                    gui_calculator_key_select(calculator_keypad, item_index);
                    if (calculator_keypad->key_type == MMI_CALC_NUM_KEY)
                    {
                        *menu_event = GUI_CALC_PEN_HIGHLIGHT_CHANGED;
                        if (key_variable == TOUCH_CALC_KEY_DOT && g_calc_cntx->ResultState == RESULT_NOT_EXCEED)        /* should not be called if result is exceded..no change on pressing Dot */
                        {
                            CalcHandlePoundKey();
                        }
                        else
                        {
                            CalcHandleNumKey(key_variable);
                        }
                    }
                    else if (calculator_keypad->key_type == MMI_CALC_SYM_KEY)
                    {
                        *menu_event = GUI_CALC_PEN_HIGHLIGHT_CHANGED;
                        g_calc_cntx->CurrHilite = key_variable;
                        if (key_variable == TOUCH_CALC_OP_EQUAL)
                        {
                            CalcComputeResult();
                        }
                        else if (key_variable >= TOUCH_CALC_OP_MP && key_variable <= TOUCH_CALC_OP_MR && g_calc_cntx->ResultState == RESULT_NOT_EXCEED) /* should not be called if result is exceded..no change on pressing these buttons */
                        {
                            if (g_calc_cntx->OpToExecute < CALC_OP_EQUAL)
                            {
                                CalcGetPreOperand();
                                if ((g_calc_cntx->Operand2 == 0) && (g_calc_cntx->OpToExecute == CALC_OP_DIV))
                                {
                                    g_calc_cntx->ResultState = RESULT_EXCEED;
                                    CalcSetRSKClear();
                                    g_calc_cntx->Operator = CALC_OP_NONE;
                                    playRequestedTone(ERROR_TONE);
                                }
                                else
                                {
                                    g_calc_cntx->Operand1 = CalcExecOperator(g_calc_cntx->Operand1, g_calc_cntx->Operand2);
                                    g_calc_cntx->OpToExecute = CALC_OP_NONE;
                                }
                            }
                            else
                            {
                                CalcHandleHiliteOperator();
                            }

                            CalcHandleHiliteMemoryButton();
                            if (g_calc_cntx->ResultState == RESULT_EXCEED)
                            {
                                playRequestedTone(ERROR_TONE);
                            }
                            CalcComputeResult();
                        }
                        else
                        {
                            CalcHandleHiliteOperator();
                            if (g_calc_cntx->ResultState == RESULT_EXCEED)
                            {
                                playRequestedTone(ERROR_TONE);
                            }
                            CalcShowResultScreen();
                        }
                    }
                }
                else
                {
                    ret = FALSE;
                }
            }
            else
            {
                ret = FALSE;
            }
            break;

        case MMI_PEN_EVENT_UP:
            calculator_keypad->flag &= ~CALC_PEN_DOWN_ON_KEYPAD;
            TOUCH_CALC_SELECT_KEY = TRUE;
            if (PEN_CHECK_BOUND
                (x, y, calculator_keypad->selected_key_x, calculator_keypad->selected_key_y,
                 calculator_keypad->key_width, calculator_keypad->key_height))
            {
                *menu_event = GUI_CALC_PEN_HIGHLIGHT_CHANGED;
                gui_calculator_key_unselect(calculator_keypad);
            }
            else if (TOUCH_CALC_SELECT_KEY)
            {
                gui_calculator_key_unselect(calculator_keypad);
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            if ((!PEN_CHECK_BOUND
                 (x, y, calculator_keypad->selected_key_x, calculator_keypad->selected_key_y,
                  calculator_keypad->key_width, calculator_keypad->key_height)))
            {
                *menu_event = GUI_CALC_PEN_HIGHLIGHT_CHANGED;
                TOUCH_CALC_SELECT_KEY = FALSE;
            }
	     /*shaokai delete it.start 090814*/
            /*else if (PEN_CHECK_BOUND
                     (x, y, calculator_keypad->selected_key_x, calculator_keypad->selected_key_y,
                      calculator_keypad->key_width, calculator_keypad->key_height))
            {
                gui_calculator_translate_pen_position(calculator_keypad, x, y, &item_index, &key_variable);
                if (!TOUCH_CALC_SELECT_KEY)
                {
                    gui_calculator_key_select(calculator_keypad, item_index);
                }
                TOUCH_CALC_SELECT_KEY = TRUE;
            }*/
            /*shaokai delete it.end 090814*/
            break;
        case MMI_PEN_EVENT_LONG_TAP:
            break;
        case MMI_PEN_EVENT_REPEAT:
            if (PEN_CHECK_BOUND
                (x, y, calculator_keypad->selected_key_x, calculator_keypad->selected_key_y,
                 calculator_keypad->key_width, calculator_keypad->key_height))
            {
                gui_calculator_translate_pen_position(calculator_keypad, x, y, &item_index, &key_variable);
                if (calculator_keypad->key_type == MMI_CALC_NUM_KEY)
                {
                    *menu_event = GUI_CALC_PEN_HIGHLIGHT_CHANGED;
                    if (key_variable == TOUCH_CALC_KEY_DOT)
                    {
                        CalcHandlePoundKey();
                    }
                    else
                    {
                        CalcHandleNumKey(key_variable);
                    }
                }
            }
            break;
    }
    return ret;
}
#endif /* __MMI_TOUCH_CALCULATOR__ */ /* __MMI_TOUCH_SCREEN */
#endif /* __MMI_CALCULATOR__ */ 

#endif /* _MMI_CALCULATOR_C */ // #ifndef _MMI_CALCULATOR_C

