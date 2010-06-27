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
 * Unitconvertor.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Unit Convertor application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**********************************************************************************
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Unitconvertor.c
   Author:        Vandana M
   Date Created:  June-14-2003
   Contains:      Unit Convertor
**********************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_UNITCONVERTOR_C
#define _MMI_UNITCONVERTOR_C

/*  Include: MMI header file */
#if defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__)
#include "unitconvertor.h"
#if defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
#include "CurrencyConvertorE.h"
#elif defined (__MMI_CURRENCY_CONVERTER__)
#include "currencyconvertor.h"
#endif 
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#if defined(__MMI_TOUCH_SCREEN__)
#endif 
/*  Include: PS header file */

/* 
 * Define
 */

#define  UCONV_MAX_RESULT     12        /* 12 digits */
#define  UCONV_MAX_INPUT         8
#if defined (__MMI_UNIT_CONVERTER__)
#define  UCONV_NUM_UNITS         4

#define  KM2MILE              0.62137
#define  M2YARD               1.09361
#define  M2FOOT               3.28084
#define  CM2INCH              0.3937
#define  KG2POUND          2.20462
#define  KG2OUNCE          35.274
#elif defined (__MMI_EXTENDED_UNIT_CONVERTER__)
#define UCONV_NUM_UNITS2      11
#define UCONV_VOLUME_UNIT_NUM    11
#define UCONV_TEMPERATURE_UNIT_NUM  2
#define UCONV_VELOCITY_UNIT_NUM     4
#define UCONV_LENGTH_UNIT_NUM    8
#define UCONV_WEIGHT_UNIT_NUM    6
#define UCONV_SHOES_UNIT_NUM     3
#define UCONV_CLOTHES_UNIT_NUM      6
#define UCONV_SURFACE_UNIT_NUM      10
#endif 

#ifndef __MTK_TARGET__
#define UCONV_MAX_VALUE          999999999999l
#else 
#define UCONV_MAX_VALUE          999999999999ll
#endif 
#define UCONV_MIN_VALUE          0.0000000001

/* 
 * Typedef 
 */
typedef struct
{
    S32 CurrInlineSelectUnit;
    U8 CurrSelectedItem;
    U8 ClearResultFlag;
    U8 CurrHiliteUnitType;

#if defined (__MMI_UNIT_CONVERTER__)
    S8 *UnitList[UCONV_NUM_UNITS];
    UI_character_type MetricBuf[UCONV_MAX_RESULT + 2];
    UI_character_type EngBuf[UCONV_MAX_RESULT + 2];
#elif defined (__MMI_EXTENDED_UNIT_CONVERTER__)
    S32 CurrInlineSelectUnit1;
    S32 CurrInlineSelectUnit2;
    S8 *UnitListLg[UCONV_NUM_UNITS2];   /* inline selector items */
    UI_character_type InputBuf1[UCONV_MAX_RESULT + 2];
    UI_character_type InputBuf2[UCONV_MAX_RESULT + 2];
    S8 title[64];

    S8 *UnitListLg2[1]; /* inline selector items, only support two unit toggling (now only for Temperature application) */
    MMI_BOOL inputflag; /* flag to record the validation of input, only for shoes and clothes */
#endif 
} uconv_context_struct;

/* 
 * Global Variable
 */
uconv_context_struct *g_uconv_cntx = NULL;
extern wgui_inline_item wgui_inline_items[];

#ifdef __MMI_EXTENDED_UNIT_CONVERTER__
const DOUBLE g_volume_rate[UCONV_VOLUME_UNIT_NUM][UCONV_VOLUME_UNIT_NUM] =
    { {1, 0.001, 1000, 1, 1E-6, 0.06102, 2.2E-4, 0.00176, 0.0352, 0.0352, 6.29E-6},
{1000, 1, 1E+6, 1000, 0.001, 61.02376, 0.21996, 1.76, 35.195, 35.195, 0.00629},
{0.001, 1E-6, 1, 0.001, 1E-9, 6.102E-5, 2.2E-7, 1.76E-6, 3.52E-5, 3.52E-5, 6.29E-9},
{1, 0.001, 1000, 1, 1E-6, 0.06102, 2.2E-4, 0.00176, 0.0352, 0.0352, 6.29E-6},
{1E+6, 1000, 1E+9, 1E+6, 1, 6.1E+4, 219.969, 1759.754, 3.5195, 3.5195, 6.2898},
{16.387, 0.01639, 16387.1, 16.387, 1.639E-5, 1, 0.0036, 0.02884, 0.57674, 0.57674, 1.031E-4},
{4546.1, 4.5461, 4.546E+6, 4546.1, 0.00455, 277.42, 1, 8, 160, 160, 0.02859},
{568.26, 0.5683, 5.683E+5, 568.26, 5.683E-4, 34.677, 0.125, 1, 20, 20, 0.00357},
{28.413, 0.02841, 28413, 28.413, 2.841E-5, 1.7339, 0.00625, 0.05, 1, 1, 1.787E-4},
{28.413, 0.02841, 28413, 28.413, 2.841E-5, 1.7339, 0.00625, 0.05, 1, 1, 1.787E-4},
{1.59E+5, 158.99, 1.59E+8, 1.59E+5, 0.159, 9702, 34.972, 279.78, 5595.57, 5595.57, 1}
};
const DOUBLE g_velocity_rate[UCONV_VELOCITY_UNIT_NUM][UCONV_VELOCITY_UNIT_NUM] = { {1, 0.27778, 0.62137, 0.91134},
{3.6, 1, 2.237, 3.28083},
{1.60935, 0.44703, 1, 1.4667},
{1.09728, 0.30480, 0.68182, 1}
};
S8 g_unitlist2[32];
const DOUBLE g_length_rate[UCONV_LENGTH_UNIT_NUM][UCONV_LENGTH_UNIT_NUM] =
    { {1, 0.1, 0.001, 1E-6, 0.03937, 0.00328, 0.00109, 6.2137E-7},
{10, 1, 0.01, 1E-5, 0.3937, 0.0328, 0.0109, 6.2137E-6},
{1000, 100, 1, 0.001, 39.37, 3.28084, 1.09361, 0.00062},
{1E+6, 1E+5, 1E+3, 1, 39370, 3280.84, 1093.6, 0.62137},
{25.4, 2.54, 0.0254, 0.00003, 1, 0.08333, 0.02778, 0.00002},
{304.801, 30.4801, 0.3048, 0.00031, 12, 1, 0.33333, 0.00019},
{914.402, 91.4402, 0.9144, 0.00091, 36, 3, 1, 0.00057},
{1609350, 160935, 1609.35, 1.60935, 63360, 5280, 1760, 1}
};

const DOUBLE g_weight_rate[UCONV_WEIGHT_UNIT_NUM][UCONV_WEIGHT_UNIT_NUM] = { {1, 1E-3, 1E-6, 1E-9, 3.527E-5, 2.21E-6},
{1E+3, 1, 1E-3, 1E-6, 0.03527, 0.00221},
{1E+6, 1E+3, 1, 1E-3, 35.274, 2.20462},
{1E+9, 1E+6, 1E+3, 1, 35274, 2204.62},
{0.0283495, 28.3495, 0.02835, 0.00003, 1, 0.0625},
{0.453592, 453.592, 0.45359, 0.00045, 16, 1}
};

const DOUBLE g_shoes_rate_pluspara[UCONV_SHOES_UNIT_NUM][UCONV_SHOES_UNIT_NUM] = { {0, 30.5, 170},
{-30.5, 0, -135},
{17, 13.5, 0}
};

const DOUBLE g_shoes_rate_multipara[UCONV_SHOES_UNIT_NUM][UCONV_SHOES_UNIT_NUM] = { {1, 1, 10},
{1, 1, 10},
{0.1, 0.1, 1}
};

/* clothes unit converter formula : (x - subtractpara) / dividepara * multipara + pluspara */
const S32 g_clothes_rate_subtractpara[UCONV_CLOTHES_UNIT_NUM][UCONV_CLOTHES_UNIT_NUM] = { {0, 34, 34, 0, 0, 0},
{44, 0, 44, 44, 44, 44},
{85, 85, 0, 85, 85, 85},
{0, -1, -1, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 2, 2, 0, 0, 0}
};

const S32 g_clothes_rate_dividepara[UCONV_CLOTHES_UNIT_NUM][UCONV_CLOTHES_UNIT_NUM] = { {1, 4, 4, 1, 1, 1},
{11, 1, 11, 11, 11, 11},
{5, 5, 1, 5, 5, 5},
{1, 4, 4, 1, 1, 1},
{1, 4, 4, 1, 1, 1},
{1, 4, 4, 1, 1, 1}
};

const S32 g_clothes_rate_multipara[UCONV_CLOTHES_UNIT_NUM][UCONV_CLOTHES_UNIT_NUM] = { {1, 11, 5, 1, 1, 1},
{4, 1, 5, 4, 4, 4},
{4, 11, 1, 4, 4, 4},
{1, 11, 5, 1, 1, 1},
{1, 11, 5, 1, 1, 1},
{1, 11, 5, 1, 1, 1}
};

const S32 g_clothes_rate_pluspara[UCONV_CLOTHES_UNIT_NUM][UCONV_CLOTHES_UNIT_NUM] = { {0, 44, 85, -35, -34, -32},
{36, 0, 85, 1, 2, 4},
{36, 44, 0, 1, 2, 4},
{35, 44, 85, 0, 1, 3},
{34, 44, 85, -1, 0, 2},
{32, 44, 85, -3, -2, 0}
};
const DOUBLE g_surface_rate[2][UCONV_SURFACE_UNIT_NUM] = 
{
    {1, 0.40469, 4.046E+9, 4.046E+7, 4046.85, 4.046E-3, 6268570, 43537.631, 4840.0326, 1.5556E-3},
    {2.47106, 1, 1E+10, 1E+8, 1E+4, 1E-2, 1.549E+7, 1.07584E+5, 1.196E+4, 3.844E-3}
};
#endif /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 

/* 
 * Global Function
 */
extern DOUBLE gui_atof(UI_string_type s);
extern void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer);
extern void set_leading_zero(U8 u8type);
extern S32 CalcComputePrecision(DOUBLE result, S16 max_digits);
extern void CconvClearResult(void);

/* Local Function */

U8 mmi_uconv_del_scr_callback(void *p);

#ifdef __MMI_UNIT_CONVERTER__
void HighlightUConvLength(void);
void HighlightUConvWeight(void);
void ComputeLengthResult(void);
void ComputeWeightResult(void);
#else /* __MMI_UNIT_CONVERTER__ */ 
void mmi_uconv_highlight_volume(void);
void mmi_uconv_highlight_temperature(void);
void mmi_uconv_highlight_velocity(void);
void mmi_uconv_highlight_length(void);
void mmi_uconv_highlight_weight(void);
void mmi_uconv_highlight_shoes(void);
void mmi_uconv_highlight_clothes(void);
void mmi_uconv_highlight_surface(void);
extern void playRequestedTone(ALL_TONE_ENUM playtone);
#endif /* __MMI_UNIT_CONVERTER__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvMenu
 * DESCRIPTION
 *  Highlight handler of Unit Conveter menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EntryUConvMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryUConvMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  UConvRedrawResult
 * DESCRIPTION
 *  Redraw result after computing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UConvRedrawResult(void)
{
#ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RedrawCategoryFunction();
#else /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
    SetHighlightedItem(0);
#endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  UconvDeInit
 * DESCRIPTION
 *  Free memory and go back to previous screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UconvDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uconv_cntx)
    {
        OslMfree(g_uconv_cntx);
        g_uconv_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_del_scr_callback
 * DESCRIPTION
 *  Callback function of delete unit converter screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_uconv_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ScrID = (SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == ScrID)
    {
        CloseCategory57Screen();
    }
    UconvDeInit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryUConvMenu
 * DESCRIPTION
 *  Entry function of unit convertor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryUConvMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 UC_list_of_items[8];    /* Autumn {Bad!! Hardcode!!} */
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uconv_cntx == NULL)
    {
        g_uconv_cntx = OslMalloc(sizeof(uconv_context_struct));
    }

    g_uconv_cntx->ClearResultFlag = FALSE;

    EntryNewScreen(SCR_ID_UCONV_MENU, NULL, EntryUConvMenu, NULL);

    /* shoes and clothes are not supported temporary */
    mmi_frm_hide_menu_item(MENU_ID_EXTRA_UNITCONVERTOR_SHOEW);
    mmi_frm_hide_menu_item(MENU_ID_EXTRA_UNITCONVERTOR_CLOTHES);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UCONV_MENU);
    num_of_items = GetNumOfChild_Ext(EXTRA_UNITCONVERTOR_MENU);
    GetSequenceStringIds_Ext(EXTRA_UNITCONVERTOR_MENU, UC_list_of_items);
    SetParentHandler(EXTRA_UNITCONVERTOR_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext);

    ShowCategory15Screen(
        EXTRA_MENU_UNITSCONVERTOR_STRINGID,
        GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        UC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  UconvInit
 * DESCRIPTION
 *  Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UconvInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_UNITCONVERTOR_MENU, HighlightUConvMenu);
#ifndef __MMI_EXTENDED_UNIT_CONVERTER__
    SetHiliteHandler(EXTRA_UNITCONVERTOR_LENGTH, HighlightUConvLength);
    SetHiliteHandler(EXTRA_UNITCONVERTOR_WEIGHT, HighlightUConvWeight);
#else /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 
    SetHiliteHandler(EXTRA_UNITCONVERTOR_LENGTH, mmi_uconv_highlight_length);
    SetHiliteHandler(EXTRA_UNITCONVERTOR_WEIGHT, mmi_uconv_highlight_weight);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_VOLUME, mmi_uconv_highlight_volume);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_TEMPERATURE, mmi_uconv_highlight_temperature);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_VELOCITY, mmi_uconv_highlight_velocity);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_SHOEW, mmi_uconv_highlight_shoes);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_CLOTHES, mmi_uconv_highlight_clothes);
    SetHiliteHandler(MENU_ID_EXTRA_UNITCONVERTOR_SURFACE, mmi_uconv_highlight_surface);
#endif /* __MMI_EXTENDED_UNIT_CONVERTER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  UConvCustomInlineFunction
 * DESCRIPTION
 *  Set group key handlers of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UConvCustomInlineFunction(void)
{
#ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCodes[] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_POUND};
    U8 nKeyCodes = (U8) 11;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uconv_cntx->ClearResultFlag)
    {
        g_uconv_cntx->ClearResultFlag = FALSE;

        SetGroupKeyHandler(CconvClearResult, keyCodes, nKeyCodes, KEY_EVENT_DOWN);
    #if !defined(__MMI_WITH_C_KEY__)
        SetRightSoftkeyFunction(CconvClearResult, KEY_EVENT_UP);
        SetRightSoftkeyFunction(CconvClearResult, KEY_EVENT_LONG_PRESS);
        SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    #else /* !defined(__MMI_WITH_C_KEY__) */ 
        SetKeyHandler(CconvClearResult, KEY_CLEAR, KEY_EVENT_UP);
        SetKeyHandler(CconvClearResult, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
        SetKeyHandler(NULL, KEY_CLEAR, KEY_EVENT_DOWN);
    #endif /* !defined(__MMI_WITH_C_KEY__) */ 
    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_editor_disable_input(PEN_EDITOR_DISABLE_HANDWRITNG | PEN_EDITOR_DISABLE_VIRTUAL_KEYBOARD);
        ChangeRightSoftkey(STR_ID_UNITCONVERTOR_RESET, 0);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    }
#endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
}

#ifdef __MMI_UNIT_CONVERTER__


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvLength
 * DESCRIPTION
 *  Highlight handler of Length menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvLength(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_LENGTH;
    SetLeftSoftkeyFunction(UConvGoToComputeScreen, KEY_EVENT_UP);
    SetKeyHandler(UConvGoToComputeScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvWeight
 * DESCRIPTION
 *  Highlight handler of Weight menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvWeight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_WEIGHT;
    SetLeftSoftkeyFunction(UConvGoToComputeScreen, KEY_EVENT_UP);
    SetKeyHandler(UConvGoToComputeScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  UConvFillInlineStruct
 * DESCRIPTION
 *  Fill inline structure of inline items in Length convertor
 * PARAMETERS
 *  void
 *  UnitType(?)     [IN]        Type of unit   0 == length, 1 == weight
 * RETURNS
 *  void
 *****************************************************************************/
void UConvFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type *Caption1, *Caption2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisableInlineInputMethodHints();

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_LENGTH)   /* length */
    {
        g_uconv_cntx->UnitList[0] = GetString(STR_UNITCONVERTOR_KMMILE);
        g_uconv_cntx->UnitList[1] = GetString(STR_UNITCONVERTOR_MYARD);
        g_uconv_cntx->UnitList[2] = GetString(STR_UNITCONVERTOR_MFOOT);
        g_uconv_cntx->UnitList[3] = GetString(STR_UNITCONVERTOR_CMINCH);

        /* caption strings */
        Caption2 =
            (UI_character_type*) (GetString((U16) (STR_UNITCONVERTOR_MILE + g_uconv_cntx->CurrInlineSelectUnit)));
        switch (g_uconv_cntx->CurrInlineSelectUnit)
        {
            case 0:
                Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_KM));
                break;
            case 3:
                Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_CM));
                break;
            default:
                Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_METER));
                break;
        }

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT],
            4,
            (U8 **) g_uconv_cntx->UnitList,
            &g_uconv_cntx->CurrInlineSelectUnit);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT], HighlightUConvInlineLenghSelect);
    }
    else    /* weight */
    {
        g_uconv_cntx->UnitList[0] = GetString(STR_UNITCONVERTOR_KGPOUND);
        Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_KG));

        g_uconv_cntx->UnitList[1] = GetString(STR_UCONV_KGOUNCE);

        if (g_uconv_cntx->CurrInlineSelectUnit == 0)    /* kg <-> pound */
        {
            Caption2 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_POUND));
        }
        else    /* Kg <-> Ounce */
        {
            Caption2 = (UI_character_type*) (GetString(STR_UCONV_OUNCE));
        }

        /* unit */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT],
            2,
            (U8 **) g_uconv_cntx->UnitList,
            &g_uconv_cntx->CurrInlineSelectUnit);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT], HighlightUConvInlineWeightSelect);

    }

    SetInlineItemActivation(&wgui_inline_items[UCONV_UNIT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    /* metric caption */
    SetInlineItemActivation(&wgui_inline_items[UCONV_METRIC_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[UCONV_METRIC_CAP], (U8*) Caption1);

    /* metric unit */
    SetInlineItemActivation(&wgui_inline_items[UCONV_METIRC], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[UCONV_METIRC],
        (U8*) g_uconv_cntx->MetricBuf,
        (UCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[UCONV_METIRC]);
    RightJustifyInlineItem(&wgui_inline_items[UCONV_METIRC]);
    SetInlineTextEditCustomFunction(&wgui_inline_items[UCONV_METIRC], UConvCustomInlineFunction);

    /* English caption */
    SetInlineItemActivation(&wgui_inline_items[UCONV_ENG_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[UCONV_ENG_CAP], (U8*) Caption2);

    /* English unit */
    SetInlineItemActivation(&wgui_inline_items[UCONV_ENG], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[UCONV_ENG],
        (U8*) g_uconv_cntx->EngBuf,
        (UCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[UCONV_ENG]);
    RightJustifyInlineItem(&wgui_inline_items[UCONV_ENG]);
    SetInlineTextEditCustomFunction(&wgui_inline_items[UCONV_ENG], UConvCustomInlineFunction);
}


/*****************************************************************************
 * FUNCTION
 *  ComputeLengthResult
 * DESCRIPTION
 *  To calculate the result of length conversion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ComputeLengthResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE conversion_factor;
    S32 precision = 0;  /* ,temp_int = 0; */
    DOUBLE result;
    UI_character_type *ResultBuf = NULL, *SourceBuf = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* conversion rate */
    switch (g_uconv_cntx->CurrInlineSelectUnit)
    {
        case 0:
            conversion_factor = KM2MILE;    /* 0.62137 */
            break;
        case 1:
            conversion_factor = M2YARD;     /* 1.09361 */
            break;
        case 2:
            conversion_factor = M2FOOT;     /* 3.28084 */
            break;
        default:                            /* case 3: */
            conversion_factor = CM2INCH;    /* 0.3937 */
            break;
    }

    if (g_uconv_cntx->CurrSelectedItem == UCONV_METIRC)
    {
        SourceBuf = g_uconv_cntx->MetricBuf;
        ResultBuf = g_uconv_cntx->EngBuf;
    }
    else
    {
        SourceBuf = g_uconv_cntx->EngBuf;
        ResultBuf = g_uconv_cntx->MetricBuf;
        conversion_factor = 1 / conversion_factor;
    }

    len = gui_strlen((UI_string_type) SourceBuf);
    if ((len == 0) || ((len == 1) && (SourceBuf[0] == 46)))
    {
        DisplayPopup(
            (U8*) GetString(UC_ERROR_EMPTY_STRING),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    g_uconv_cntx->ClearResultFlag = TRUE;

    result = (DOUBLE) (conversion_factor * gui_atof(SourceBuf));

    precision = CalcComputePrecision(result, (S16) UCONV_MAX_RESULT);
    gui_float_string(result, precision, (S8*) ResultBuf);

    UConvRedrawResult();
    SetLeftSoftkeyFunction(ComputeLengthResult, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ComputeWeightResult
 * DESCRIPTION
 *  To calculate the result of weight conversion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ComputeWeightResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;
    S32 prec_val = 0;
    DOUBLE conversion_factor = 0;
    UI_character_type *ResultBuf = NULL, *SourceBuf = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* determine rate */
    if (g_uconv_cntx->CurrInlineSelectUnit == 0)    /* Kg to Pound */
    {
        conversion_factor = KG2POUND;
    }
    else
    {
        conversion_factor = KG2OUNCE;
    }

    /* determine conversion direction */
    if (g_uconv_cntx->CurrSelectedItem == UCONV_METIRC)
    {
        SourceBuf = g_uconv_cntx->MetricBuf;
        ResultBuf = g_uconv_cntx->EngBuf;
    }
    else    /* UCONV_ENGLISH */
    {
        SourceBuf = g_uconv_cntx->EngBuf;
        ResultBuf = g_uconv_cntx->MetricBuf;
        conversion_factor = 1 / conversion_factor;
    }

    len = gui_strlen((UI_string_type) SourceBuf);

    if ((len == 0) || ((len == 1) && (ResultBuf[0] == 46)))
    {
        DisplayPopup(
            (U8*) GetString(UC_ERROR_EMPTY_STRING),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    g_uconv_cntx->ClearResultFlag = TRUE;

    result = (DOUBLE) (conversion_factor * gui_atof(SourceBuf));

    prec_val = CalcComputePrecision(result, UCONV_MAX_RESULT);
    gui_float_string(result, prec_val, (S8*) ResultBuf);

    UConvRedrawResult();

    SetLeftSoftkeyFunction(ComputeWeightResult, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  UConvGoToComputeScreen
 * DESCRIPTION
 *  Intialize state variables and enter weight convertor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UConvGoToComputeScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit = 0;
    g_uconv_cntx->CurrSelectedItem = 0;
    memset(g_uconv_cntx->EngBuf, 0, 2);
    memset(g_uconv_cntx->MetricBuf, 0, 2);
    EntryUConvCompute();
}


/*****************************************************************************
 * FUNCTION
 *  ExitUConvCompute
 * DESCRIPTION
 *  Exit function of conterting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitUConvCompute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history HistoryUCWeight;
    U16 inputBufferSize;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_uconv_cntx)
    {
        CloseCategory57Screen();
        HistoryUCWeight.scrnID = SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType;
    }
    HistoryUCWeight.entryFuncPtr = EntryUConvCompute;
    GetCategory57History(HistoryUCWeight.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryUCWeight.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryUCWeight.inputBuffer);   /* added for inline edit history */
    AddNHistory(HistoryUCWeight, inputBufferSize);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  EntryUConvCompute
 * DESCRIPTION
 *  Entry function of conterting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryUConvCompute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 ScrID = (SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(ScrID, ExitUConvCompute, NULL, NULL);
    SetDelScrnIDCallbackHandler(ScrID, (HistoryDelCBPtr) mmi_uconv_del_scr_callback);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(ScrID);

    InitializeCategory57Screen();

    UConvFillInlineStruct();
    RegisterHighlightHandler(HighlightUConvInlineItem);

    inputBuffer = GetCurrNInputBuffer(ScrID, &inputBufferSize); /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, UCONV_INLINE_TOTAL, inputBuffer);  /* sets the data */
    }

    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_UNITCONVERTOR_CAPTION1,
        GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        UCONV_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        g_uconv_cntx->CurrSelectedItem,
        guiBuffer);

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
    {
        SetCategory57RightSoftkeyFunctions(ComputeWeightResult, GoBackHistory);
    }
    else
    {
        SetCategory57RightSoftkeyFunctions(ComputeLengthResult, GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvInlineItem
 * DESCRIPTION
 *  Highlight handler of inline items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvInlineItem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0) /* inline selection */
    {
        ChangeLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
    #ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__

        if ((U8) index != g_uconv_cntx->CurrSelectedItem)
        {
            memset(g_uconv_cntx->MetricBuf, 0, 2);
            memset(g_uconv_cntx->EngBuf, 0, 2);
        }
        /* if re-entry screen because of displaying result */
		else if(!g_uconv_cntx->ClearResultFlag && *(g_uconv_cntx->EngBuf) != 0 && *(g_uconv_cntx->MetricBuf) != 0)
		{
            g_uconv_cntx->ClearResultFlag = TRUE;
        }

        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

        if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
        {
            SetLeftSoftkeyFunction(ComputeWeightResult, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(ComputeLengthResult, KEY_EVENT_UP);
        }

    #else /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
        if (index != g_uconv_cntx->CurrSelectedItem)
        {
            memset(g_uconv_cntx->MetricBuf, 0, 2);
            memset(g_uconv_cntx->EngBuf, 0, 2);
        }
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

        if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)
        {
            SetLeftSoftkeyFunction(ComputeWeightResult, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(ComputeLengthResult, KEY_EVENT_UP);
        }

    #endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
    }
    g_uconv_cntx->CurrSelectedItem = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvInlineWeightSelect
 * DESCRIPTION
 *  Highlight handler inline selection item in Weight convertor.
 *  Redraw caption according to select.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvInlineWeightSelect(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type *Caption1, *Caption2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit = (U8) index;

    Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_KG));
    if (index == 0) /* Kg <-> Pound */
    {
        Caption2 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_POUND));
    }
    else
    {
        Caption2 = (UI_character_type*) (GetString(STR_UCONV_OUNCE));
    }

    memset(g_uconv_cntx->MetricBuf, 0, 2);
    memset(g_uconv_cntx->EngBuf, 0, 2);

    Category57ChangeItemText(1, (U8*) Caption1);
    Category57ChangeItemText(3, (U8*) Caption2);
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightUConvInlineLenghSelect
 * DESCRIPTION
 *  Highlight handler inline selection item in Length convertor.
 *  Redraw caption according to select.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightUConvInlineLenghSelect(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type *Caption1, *Caption2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit = index;

    Caption2 = (UI_character_type*) (GetString((U16) (STR_UNITCONVERTOR_MILE + g_uconv_cntx->CurrInlineSelectUnit)));
    switch (g_uconv_cntx->CurrInlineSelectUnit)
    {
        case 0:
            Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_KM));
            break;
        case 3:
            Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_CM));
            break;
        default:
            Caption1 = (UI_character_type*) (GetString(STR_UNITCONVERTOR_METER));
            break;
    }

    memset(g_uconv_cntx->MetricBuf, 0, 2);
    memset(g_uconv_cntx->EngBuf, 0, 2);

    Category57ChangeItemText(1, (U8*) Caption1);
    Category57ChangeItemText(3, (U8*) Caption2);
    RedrawCategoryFunction();
}

#else /* __MMI_UNIT_CONVERTER__ */ /* else of ifdef __MMI_UNIT_CONVERTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_volume
 * DESCRIPTION
 *  Highlight handler of Volume menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_VOLUME;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_temperature
 * DESCRIPTION
 *  Highlight handler of Temperature menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_temperature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_TEMPERATURE;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_velocity
 * DESCRIPTION
 *  Highlight handler of Velocity menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_velocity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_VELOCITY;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_length
 * DESCRIPTION
 *  Highlight handler of Length menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_LENGTH;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_weight
 * DESCRIPTION
 *  Highlight handler of Weight menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_weight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_WEIGHT;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_shoes
 * DESCRIPTION
 *  Highlight handler of Shoes menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_shoes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_SHOES;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_clothes
 * DESCRIPTION
 *  Highlight handler of Clothes menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_clothes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_CLOTHES;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_surface
 * DESCRIPTION
 *  Highlight handler of Surface menu in Unit Convertor
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_surface(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrHiliteUnitType = UCONV_SURFACE;
    SetLeftSoftkeyFunction(mmi_uconv_goto_compute_screen_lg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uconv_goto_compute_screen_lg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_fill_inline_struct_lg
 * DESCRIPTION
 *  Fill inline structure of inline items in convertor with LG style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_fill_inline_struct_lg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str_i[32], unicode_str_o[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisableInlineInputMethodHints();

    /* Selectors */
    SetInlineItemActivation(&wgui_inline_items[UCONV_UNIT1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[UCONV_UNIT2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    /* unit1 input */
    SetInlineItemActivation(&wgui_inline_items[UCONV_INPUT1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[UCONV_INPUT1],
        (U8*) g_uconv_cntx->InputBuf1,
        (UCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[UCONV_INPUT1]);
    RightJustifyInlineItem(&wgui_inline_items[UCONV_INPUT1]);

    /* unit2 result */
    SetInlineItemActivation(&wgui_inline_items[UCONV_RESULT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[UCONV_RESULT],
        (U8*) g_uconv_cntx->InputBuf2,
        (UCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[UCONV_RESULT]);
    RightJustifyInlineItem(&wgui_inline_items[UCONV_RESULT]);
    DisableInlineItem(&wgui_inline_items[UCONV_RESULT], UCONV_RESULT);

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_LENGTH)   /* length */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_LENGTH_MM);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_LENGTH_CM);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_LENGTH_M);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_LENGTH_KM);
        g_uconv_cntx->UnitListLg[4] = GetString(STR_ID_UNITCONVERTOR_LENGTH_INCH);
        g_uconv_cntx->UnitListLg[5] = GetString(STR_ID_UNITCONVERTOR_LENGTH_FEET);
        g_uconv_cntx->UnitListLg[6] = GetString(STR_ID_UNITCONVERTOR_LENGTH_YARD);
        g_uconv_cntx->UnitListLg[7] = GetString(STR_ID_UNITCONVERTOR_LENGTH_MILES);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_LENGTH_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_LENGTH_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(&wgui_inline_items[UCONV_INPUT1], mmi_uconv_compute_result);

    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_WEIGHT)  /* weight */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_MG);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_G);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_KG);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_TON);
        g_uconv_cntx->UnitListLg[4] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_OUNCE);
        g_uconv_cntx->UnitListLg[5] = GetString(STR_ID_UNITCONVERTOR_WEIGHT_POUND);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_WEIGHT_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_WEIGHT_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(&wgui_inline_items[UCONV_INPUT1], mmi_uconv_compute_result);

    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_VOLUME)  /* volume */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_MILLILITER);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_LITER);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_CUBICMM);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_CUBICCM);
        g_uconv_cntx->UnitListLg[4] = GetString(STR_ID_UNITCONVERTOR_CUBICMETER);
        g_uconv_cntx->UnitListLg[5] = GetString(STR_ID_UNITCONVERTOR_CUBICINCH);
        g_uconv_cntx->UnitListLg[6] = GetString(STR_ID_UNITCONVERTOR_GALLON);
        g_uconv_cntx->UnitListLg[7] = GetString(STR_ID_UNITCONVERTOR_LIQPT);
        g_uconv_cntx->UnitListLg[8] = GetString(STR_ID_UNITCONVERTOR_LIQOZ);
        g_uconv_cntx->UnitListLg[9] = GetString(STR_ID_UNITCONVERTOR_FLOZ);
        g_uconv_cntx->UnitListLg[10] = GetString(STR_ID_UNITCONVERTOR_BARREL);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_VOLUME_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_VOLUME_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(&wgui_inline_items[UCONV_INPUT1], mmi_uconv_compute_result);
    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_TEMPERATURE)     /* Temperature */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_CELSIUS);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_FAHRENHEIT);

        g_uconv_cntx->UnitListLg2[0] = g_unitlist2;
        mmi_ucs2cpy(g_uconv_cntx->UnitListLg2[0], g_uconv_cntx->UnitListLg[1]);
        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_TEMPERATURE_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_TEMPERATURE_UNIT_NUM - 1,
            (U8 **) g_uconv_cntx->UnitListLg2,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(
            &wgui_inline_items[UCONV_INPUT1],
            mmi_uconv_compute_temperature_result);
    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_VELOCITY)        /* Velocity */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_KMH);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_METERSEC);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_MPH);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_FEETSEC);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_VELOCITY_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_VELOCITY_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(&wgui_inline_items[UCONV_INPUT1], mmi_uconv_compute_result);
    }   /* Sophie { */
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_SHOES)   /* SHOES */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_SHOES_USA);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_SHOES_EUROPE);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_SHOES_KOREA);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_SHOES_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_SHOES_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        SetInlineTextEditCustomFunction(&wgui_inline_items[UCONV_INPUT1], UConvCustomInlineFunction);

    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_CLOTHES) /* CLOTHES */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_EUROPE);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_KOREA1);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_KOREA2);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_JAPAN);
        g_uconv_cntx->UnitListLg[4] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_USA);
        g_uconv_cntx->UnitListLg[5] = GetString(STR_ID_UNITCONVERTOR_CLOTHES_UK);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_CLOTHES_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_CLOTHES_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        SetInlineTextEditCustomFunction(&wgui_inline_items[UCONV_INPUT1], UConvCustomInlineFunction);
    }
    else if (g_uconv_cntx->CurrHiliteUnitType == UCONV_SURFACE) /* surface */
    {
        g_uconv_cntx->UnitListLg[0] = GetString(STR_ID_UNITCONVERTOR_SURFACE_ACRE);
        g_uconv_cntx->UnitListLg[1] = GetString(STR_ID_UNITCONVERTOR_SURFACE_HECTARE);
        g_uconv_cntx->UnitListLg[2] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_MM);
        g_uconv_cntx->UnitListLg[3] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_CM);
        g_uconv_cntx->UnitListLg[4] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_M);
        g_uconv_cntx->UnitListLg[5] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_KM);
        g_uconv_cntx->UnitListLg[6] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_IN);
        g_uconv_cntx->UnitListLg[7] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_FEET);
        g_uconv_cntx->UnitListLg[8] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_YD);
        g_uconv_cntx->UnitListLg[9] = GetString(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_MILES);

        /* units */
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT1],
            UCONV_SURFACE_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit1);
        SetInlineItemSelect(
            &wgui_inline_items[UCONV_UNIT2],
            UCONV_SURFACE_UNIT_NUM,
            (U8 **) g_uconv_cntx->UnitListLg,
            &g_uconv_cntx->CurrInlineSelectUnit2);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT1], mmi_uconv_highlight_inline_select1);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[UCONV_UNIT2], mmi_uconv_highlight_inline_select2);
        RegisterInlineFullScreenEditValidationFunction(&wgui_inline_items[UCONV_INPUT1], mmi_uconv_compute_result);
    }

    memset(ansii_str_i, 0, 32);
    sprintf(ansii_str_i, " : ");
    mmi_asc_to_ucs2(unicode_str_o, ansii_str_i);
    mmi_ucs2cpy(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit1]);
    mmi_ucs2cat(g_uconv_cntx->title, unicode_str_o);
    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_TEMPERATURE)  /* Temperature */
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg2[g_uconv_cntx->CurrInlineSelectUnit2]);
    }
    else
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit2]);
    }

    /* caption */
    SetInlineItemActivation(&wgui_inline_items[UCONV_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[UCONV_CAPTION], (U8*) g_uconv_cntx->title);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_reset_current_input
 * DESCRIPTION
 *  To reset the input (and result)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_reset_current_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    memset(g_uconv_cntx->InputBuf1, 0, 2);
    ChangeLeftSoftkey(STR_ID_UNITCONVERTOR_RESET, IMG_ID_UNITCONVERTOR_RESET);
    RedrawCategoryFunction();
    SetLeftSoftkeyFunction(mmi_uconv_reset_current_input, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_compute_result
 * DESCRIPTION
 *  Handler to represent the calculated length/weight/velocity/volume result
 * PARAMETERS
 *  text            [?]         input
 *  cursor          [?]         not used
 *  text_length     [IN]        not used
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_compute_result(U8 *text, U8 *cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;
    S32 prec_val = 0;
    UI_character_type *ResultBuf = NULL;
    S32 sourceUnit = 0, resultUnit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*text))   /* input field is blank */
    {
        memset(g_uconv_cntx->InputBuf2, 0, 2);
    }
    else    /* input field is not blank */
    {
        ResultBuf = g_uconv_cntx->InputBuf2;
        sourceUnit = g_uconv_cntx->CurrInlineSelectUnit1;
        resultUnit = g_uconv_cntx->CurrInlineSelectUnit2;
        switch (g_uconv_cntx->CurrHiliteUnitType)
        {
            case UCONV_LENGTH:
                result = (DOUBLE) (g_length_rate[sourceUnit][resultUnit] * gui_atof((UI_string_type) text));
                break;
            case UCONV_WEIGHT:
                result = (DOUBLE) (g_weight_rate[sourceUnit][resultUnit] * gui_atof((UI_string_type) text));
                break;
            case UCONV_VELOCITY:
                result = (DOUBLE) (g_velocity_rate[sourceUnit][resultUnit] * gui_atof((UI_string_type) text));
                break;
            case UCONV_VOLUME:
                result = (DOUBLE) (g_volume_rate[sourceUnit][resultUnit] * gui_atof((UI_string_type) text));
                break;
            case UCONV_SURFACE:
                if (sourceUnit + STR_ID_UNITCONVERTOR_SURFACE_ACRE == STR_ID_UNITCONVERTOR_SURFACE_ACRE ||
                    sourceUnit + STR_ID_UNITCONVERTOR_SURFACE_ACRE == STR_ID_UNITCONVERTOR_SURFACE_HECTARE)
                {
                    result = (DOUBLE) (g_surface_rate[sourceUnit][resultUnit] * gui_atof((UI_string_type) text));
                }
                else
                {
                    /* 1 square m = g_length_rate[sourceUnit-2][2] * g_length_rate[sourceUnit-2][2] square (length_unit) */
                    if (resultUnit + STR_ID_UNITCONVERTOR_SURFACE_ACRE == STR_ID_UNITCONVERTOR_SURFACE_ACRE)
                    {
                        result =
                            (DOUBLE) (2.5E-4 * g_length_rate[sourceUnit - 2][2] * g_length_rate[sourceUnit - 2][2] *
                                      gui_atof((UI_string_type) text));
                    }
                    else if (resultUnit + STR_ID_UNITCONVERTOR_SURFACE_ACRE == STR_ID_UNITCONVERTOR_SURFACE_HECTARE)
                    {
                        result =
                            (DOUBLE) (1E-4 * g_length_rate[sourceUnit - 2][2] * g_length_rate[sourceUnit - 2][2] *
                                      gui_atof((UI_string_type) text));
                    }
                    else
                    {
                        result =
                            (DOUBLE) (g_length_rate[sourceUnit - 2][resultUnit - 2] *
                                      g_length_rate[sourceUnit - 2][resultUnit - 2] * gui_atof((UI_string_type) text));
                    }

                }
                break;
            default:
                break;
        }
        if (result > UCONV_MAX_VALUE)   /* boundary check: 12 digits */
        {
            int input_len;

            CloseCategory57Screen();
            input_len = mmi_ucs2strlen((S8*) g_uconv_cntx->InputBuf1);
            memset((g_uconv_cntx->InputBuf1 + input_len - 1), 0, 2);    /* Backspace */
            playRequestedTone(WARNING_TONE);
        }
        else
        {
            prec_val = CalcComputePrecision(result, UCONV_MAX_RESULT);
            gui_float_string(result, prec_val, (S8*) ResultBuf);
        }
    }

    UConvRedrawResult();
    ChangeLeftSoftkey(STR_ID_UNITCONVERTOR_RESET, IMG_ID_UNITCONVERTOR_RESET);
    SetLeftSoftkeyFunction(mmi_uconv_reset_current_input, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_compute_temperature_result
 * DESCRIPTION
 *  Handler to represent the calculated result
 * PARAMETERS
 *  text            [?]         input
 *  cursor          [?]         not used
 *  text_length     [IN]        not used
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_compute_temperature_result(U8 *text, U8 *cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;
    S32 prec_val = 0;
    UI_character_type *ResultBuf = NULL;
    S32 sourceUnit = 0, resultUnit = 0;
    DOUBLE inputValue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*text))   /* input field is blank */
    {
        memset(g_uconv_cntx->InputBuf2, 0, 2);
    }
    else    /* input field is not blank */
    {
        inputValue = gui_atof((UI_string_type) text);

        ResultBuf = g_uconv_cntx->InputBuf2;
        sourceUnit = g_uconv_cntx->CurrInlineSelectUnit1;
        resultUnit = g_uconv_cntx->CurrInlineSelectUnit2;

        if (sourceUnit == 0)    /* C->F */
        {
            result = (DOUBLE) (inputValue * 9.0 / 5.0 + 32.0);
        }
        else    /* F->C */
        {
            result = (DOUBLE) ((inputValue - 32.0) * 5.0 / 9.0);
        }

        if (result > 999999999999)  /* 12 digits */
        {
            int input_len;

            CloseCategory57Screen();
            input_len = mmi_ucs2strlen((S8*) g_uconv_cntx->InputBuf1);
            memset((g_uconv_cntx->InputBuf1 + input_len - 1), 0, 2);
            playRequestedTone(WARNING_TONE);
        }
        else
        {
            prec_val = CalcComputePrecision(result, UCONV_MAX_RESULT);
            gui_float_string(result, prec_val, (S8*) ResultBuf);
        }
    }

    ChangeLeftSoftkey(STR_ID_UNITCONVERTOR_RESET, IMG_ID_UNITCONVERTOR_RESET);
    UConvRedrawResult();
    SetLeftSoftkeyFunction(mmi_uconv_reset_current_input, KEY_EVENT_UP);
}

/* Autumn } */

/* Sophie { */


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_compute_sc_result
 * DESCRIPTION
 *  Handler to represent the calculated result
 * PARAMETERS
 *  void
 *  text: input(?)
 *  cursor: not used(?)
 *  text_length: not used(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_compute_sc_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE result = 0;
    S32 prec_val = 0;
    UI_character_type *ResultBuf = NULL;
    S32 sourceUnit = 0, resultUnit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->inputflag = MMI_FALSE;

    switch (g_uconv_cntx->CurrHiliteUnitType)
    {
        case UCONV_SHOES:
            mmi_uconv_verify_shoes_input((U16*) g_uconv_cntx->InputBuf1);
            break;
        case UCONV_CLOTHES:
            mmi_uconv_verify_clothes_input((U16*) g_uconv_cntx->InputBuf1);
            break;
        default:
            break;
    }
    if (g_uconv_cntx->inputflag == MMI_FALSE)
    {
        return;
    }

    ResultBuf = g_uconv_cntx->InputBuf2;
    sourceUnit = g_uconv_cntx->CurrInlineSelectUnit1;
    resultUnit = g_uconv_cntx->CurrInlineSelectUnit2;

    switch (g_uconv_cntx->CurrHiliteUnitType)
    {
        case UCONV_SHOES:
            result =
                (DOUBLE) (g_shoes_rate_multipara[sourceUnit][resultUnit] * gui_atof((U16*) g_uconv_cntx->InputBuf1) +
                          g_shoes_rate_pluspara[sourceUnit][resultUnit]);
            break;
        case UCONV_CLOTHES:
            result =
                ((S32) gui_atof((U16*) g_uconv_cntx->InputBuf1) -
                 g_clothes_rate_subtractpara[sourceUnit][resultUnit]) /
                g_clothes_rate_dividepara[sourceUnit][resultUnit] * g_clothes_rate_multipara[sourceUnit][resultUnit] +
                g_clothes_rate_pluspara[sourceUnit][resultUnit];
            break;
        default:
            break;
    }

    if (result > 999999999999)  /* 12 digits */
    {
        int input_len;

        CloseCategory57Screen();
        input_len = mmi_ucs2strlen((S8*) g_uconv_cntx->InputBuf1);
        memset((g_uconv_cntx->InputBuf1 + input_len - 1), 0, 2);
        playRequestedTone(WARNING_TONE);
    }
    else
    {
        prec_val = CalcComputePrecision(result, UCONV_MAX_RESULT);
        gui_float_string(result, prec_val, (S8*) ResultBuf);
    }

    g_uconv_cntx->ClearResultFlag = TRUE;

    UConvRedrawResult();
    SetLeftSoftkeyFunction(mmi_uconv_compute_sc_result, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_verify_shoes_input
 * DESCRIPTION
 *  Handler to verify the calculated input
 * PARAMETERS
 *  input       [?]     input
 *  inputflag: result flag(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_verify_shoes_input(U16 *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE verifier = gui_atof(input);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_uconv_cntx->CurrInlineSelectUnit1 + STR_ID_UNITCONVERTOR_SHOES_USA)
    {
        case STR_ID_UNITCONVERTOR_SHOES_USA:    /* 5.0, 5.5,...,10.5 */
            if ((S32) verifier * 10 % 5 == 0 && verifier >= 5.0 && verifier <= 10.5)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_SHOES_EUROPE: /* 35.5, 36.0,...,41.0 */
            if ((S32) verifier * 10 % 5 == 0 && verifier >= 35.5 && verifier / 5 <= 41)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_SHOES_KOREA:  /* 220,225,...,275 */
            if ((S32) verifier % 5 == 0 && verifier >= 220 && verifier / 5 <= 275)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        default:
            break;
    }
    if (g_uconv_cntx->inputflag == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(UC_ERROR_UNCORRECT_INPUT),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        /* mmi_uconv_reset_current_input2(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_verify_clothes_input
 * DESCRIPTION
 *  Handler to verify the calculated input
 * PARAMETERS
 *  input       [?]     input
 *  inputflag: result flag(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_verify_clothes_input(U16 *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 verifier = gui_atoi(input);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_uconv_cntx->CurrInlineSelectUnit1 + STR_ID_UNITCONVERTOR_CLOTHES_EUROPE)
    {
        case STR_ID_UNITCONVERTOR_CLOTHES_EUROPE:   /* 36, 38, ..., 52 */
            if (verifier % 2 == 0 && verifier >= 36 && verifier <= 52)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_CLOTHES_KOREA1:   /* 44, 55,..., 88 */
            if (verifier % 11 == 0 && verifier >= 44 && verifier <= 88)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_CLOTHES_KOREA2:   /* 85, 90, ...,105 */
            if (verifier % 5 == 0 && verifier >= 85 && verifier / 5 <= 105)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_CLOTHES_JAPAN:    /* 1, 3, 5, ...,17 */
            if ((verifier + 1) % 2 == 0 && verifier >= 1 && verifier <= 17)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_CLOTHES_USA:  /* 2, 4, 6, ..., 18 */
            if (verifier % 2 == 0 && verifier >= 2 && verifier <= 18)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        case STR_ID_UNITCONVERTOR_CLOTHES_UK:   /* 4, 6, 8,... , 20 */
            if (verifier % 2 == 0 && verifier >= 4 && verifier <= 20)
            {
                g_uconv_cntx->inputflag = MMI_TRUE;
            }
            break;
        default:
            break;
    }
    if (g_uconv_cntx->inputflag == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(UC_ERROR_UNCORRECT_INPUT),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        /* mmi_uconv_reset_current_input2(); */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_goto_compute_screen_lg
 * DESCRIPTION
 *  Intialize state variables and enter velocity/temperature/volume convertor with LG style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_goto_compute_screen_lg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit1 = 0;
    g_uconv_cntx->CurrInlineSelectUnit2 = 0;
    g_uconv_cntx->CurrSelectedItem = 0;
    memset(g_uconv_cntx->InputBuf1, 0, 2);
    memset(g_uconv_cntx->InputBuf2, 0, 2);

    mmi_uconv_entry_compute_lg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_exit_compute_lg
 * DESCRIPTION
 *  Exit function of converting screen with LG style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_exit_compute_lg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history HistoryUCWeight;
    U16 inputBufferSize;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_uconv_cntx)
    {
        CloseCategory57Screen();
        HistoryUCWeight.scrnID = SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType;
    }
    HistoryUCWeight.entryFuncPtr = mmi_uconv_entry_compute_lg;
    GetCategory57History(HistoryUCWeight.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryUCWeight.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryUCWeight.inputBuffer);   /* added for inline edit history */
    AddNHistory(HistoryUCWeight, inputBufferSize);          /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_entry_compute_lg
 * DESCRIPTION
 *  Entry function of converting screen with LG style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_entry_compute_lg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 UC_list_of_items[10]; */
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 ScrID = (SCR_ID_UCONV_WEIGHT + g_uconv_cntx->CurrHiliteUnitType);
    U16 titleID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(ScrID, mmi_uconv_exit_compute_lg, NULL, NULL);
    SetDelScrnIDCallbackHandler(ScrID, (HistoryDelCBPtr) mmi_uconv_del_scr_callback);

    set_leading_zero(FALSE);

    guiBuffer = GetCurrGuiBuffer(ScrID);

    InitializeCategory57Screen();

    mmi_uconv_fill_inline_struct_lg();
    RegisterHighlightHandler(mmi_uconv_highlight_inline_item_lg);

    inputBuffer = GetCurrNInputBuffer(ScrID, &inputBufferSize); /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, UCONV_INLINE_TOTAL2, inputBuffer); /* sets the data */
    }

    DisableCategory57ScreenDone();

    switch (g_uconv_cntx->CurrHiliteUnitType)
    {
        case UCONV_LENGTH:
            titleID = STR_UNITCONVERTOR_LENGTH;
            break;
        case UCONV_WEIGHT:
            titleID = STR_UNITCONVERTOR_WEIGHT;
            break;
        case UCONV_VOLUME:
            titleID = STR_ID_UNITCONVERTOR_VOLUME;
            break;
        case UCONV_TEMPERATURE:
            titleID = STR_ID_UNITCONVERTOR_TEMPERATURE;
            break;
        case UCONV_VELOCITY:
            titleID = STR_ID_UNITCONVERTOR_VELOCITY;
            break;
        case UCONV_SHOES:
            titleID = STR_ID_UNITCONVERTOR_SHOES;
            break;
        case UCONV_CLOTHES:
            titleID = STR_ID_UNITCONVERTOR_CLOTHES;
            break;
        case UCONV_SURFACE:
            titleID = STR_ID_UNITCONVERTOR_SURFACE;
            break;
        default:
            titleID = STR_UNITCONVERTOR_CAPTION1;
            break;
    }

    ShowCategory57Screen(
        titleID,
        GetRootTitleIcon(EXTRA_UNITCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        UCONV_INLINE_TOTAL2,
        NULL,
        wgui_inline_items,
        g_uconv_cntx->CurrSelectedItem,
        guiBuffer);

    switch (g_uconv_cntx->CurrHiliteUnitType)
    {
        case UCONV_SHOES:
        case UCONV_CLOTHES:
            SetCategory57RightSoftkeyFunctions(mmi_uconv_compute_sc_result, GoBackHistory);
            break;
        default:
            SetCategory57RightSoftkeyFunctions(mmi_uconv_reset_current_input, GoBackHistory);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_inline_item_lg
 * DESCRIPTION
 *  Highlight handler of inline items with LG style
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_inline_item_lg(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == UCONV_UNIT1 || index == UCONV_UNIT2)   /* inline selection */
    {
        memset(g_uconv_cntx->InputBuf1, 0, 2);
        memset(g_uconv_cntx->InputBuf2, 0, 2);

        ChangeLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
    #ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
        if ((U8) index != g_uconv_cntx->CurrSelectedItem)
        {
            memset(g_uconv_cntx->InputBuf1, 0, 2);
            memset(g_uconv_cntx->InputBuf2, 0, 2);
        }

    #if !defined(__MMI_WITH_C_KEY__)
        SetCategory57ScreenRSKClear();  /* Max: set RSK to "Clear" */
    #endif 

    #else /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
        if (index != g_uconv_cntx->CurrSelectedItem)
        {
            memset(g_uconv_cntx->InputBuf1, 0, 2);
            memset(g_uconv_cntx->InputBuf2, 0, 2);
        }
    #endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
    }

    g_uconv_cntx->CurrSelectedItem = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_inline_select1
 * DESCRIPTION
 *  Highlight handler for the 1st(upper) inline selection item in volume/velocity/temperature convertor.
 *  Redraw caption according to select.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_inline_select1(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str_i[32], unicode_str_o[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit1 = index;

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_TEMPERATURE)  /* Temperature */
    {
        mmi_ucs2cpy(g_uconv_cntx->UnitListLg2[0], g_uconv_cntx->UnitListLg[1 - index]);
    }

    memset(ansii_str_i, 0, 32);
    sprintf(ansii_str_i, " : ");
    mmi_asc_to_ucs2(unicode_str_o, ansii_str_i);
    mmi_ucs2cpy(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit1]);
    mmi_ucs2cat(g_uconv_cntx->title, unicode_str_o);

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_TEMPERATURE)  /* Temperature */
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg2[g_uconv_cntx->CurrInlineSelectUnit2]);
    }
    else
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit2]);
    }

    SetInlineItemCaption(&wgui_inline_items[UCONV_CAPTION], (U8*) g_uconv_cntx->title);
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uconv_highlight_inline_select2
 * DESCRIPTION
 *  Highlight handler for the 2nd(lower) inline selection item in volume/velocity/temperature convertor.
 *  Redraw caption according to select.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uconv_highlight_inline_select2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ansii_str_i[32], unicode_str_o[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uconv_cntx->CurrInlineSelectUnit2 = index;
    memset(ansii_str_i, 0, 32);
    sprintf(ansii_str_i, " : ");
    mmi_asc_to_ucs2(unicode_str_o, ansii_str_i);
    mmi_ucs2cpy(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit1]);
    mmi_ucs2cat(g_uconv_cntx->title, unicode_str_o);

    if (g_uconv_cntx->CurrHiliteUnitType == UCONV_TEMPERATURE)  /* Temperature */
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg2[g_uconv_cntx->CurrInlineSelectUnit2]);
    }
    else
    {
        mmi_ucs2cat(g_uconv_cntx->title, g_uconv_cntx->UnitListLg[g_uconv_cntx->CurrInlineSelectUnit2]);
    }

    SetInlineItemCaption(&wgui_inline_items[UCONV_CAPTION], (U8*) g_uconv_cntx->title);
    RedrawCategoryFunction();
}

#endif /* __MMI_UNIT_CONVERTER__ */ /* end of ifdef __MMI_UNIT_CONVERTER__ */

#endif /* defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__) */ 

#endif /* _MMI_UNITCONVERTOR_C */ // #ifndef _MMI_UNITCONVERTOR_C

