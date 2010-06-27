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
 * Bmi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements BMI application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * Bmi.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements BMI application.
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************/
 /*  Include: MMI header file */
#include "MMI_include.h"
#ifndef _MMI_BMI_C
#define _MMI_BMI_C
#ifdef __MMI_BMI__

#include "BMI.h"
#include "settingprofile.h"
#include "Organizerdef.h"
#include "CommonScreens.h"
#include "Calculator.h"

/*  Include: PS header file */

/* 
 * Define
 */
#define  BMI_MALE_LB             20     /* Lower bound of standard BMI index of a man */
#define  BMI_MALE_UB             25     /* Upper bound of standard BMI index of a man */
#define  BMI_FEMALE_LB           18     /* Lower bound of standard BMI index of a woman */
#define  BMI_FEMALE_UB           23     /* Upper bound of standard BMI index of a woman */
#define  BMI_MAX_INPUT           8
#define  BMI_DIGIT_LEN           9*ENCODING_LENGTH
#define  BMI_LB_UB_LEN           4*ENCODING_LENGTH      /* buffer length to store lower and upper bound */
#define  BMI_RESULT_LEN          7*ENCODING_LENGTH      /* buffer length to store resut xxx.xx */
#define  BMI_MAX_HEIGHT          300
#define  BMI_MIN_HEIGHT          55
#define  BMI_MAX_WEIGHT          300
#define  BMI_MIN_WEIGHT          1
/* 
 * Typedef 
 */
typedef struct
{
    DOUBLE Height;
    DOUBLE Weight;
    S32 Gender;
    U8 *GenderList[2];
    S8 UBBuf[BMI_LB_UB_LEN];
    S8 LBBuf[BMI_LB_UB_LEN];
    S8 ResultBuf[BMI_RESULT_LEN];
    S8 HeightBuf[BMI_DIGIT_LEN];
    S8 WeightBuf[BMI_DIGIT_LEN];
    U8 CurrHilite;
} bmi_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
U8 BMIDelScrCB(void *p);

/* 
 * Global Variable
 */

bmi_context_struct *g_bmi_cntx = NULL;
extern wgui_inline_item wgui_inline_items[];

/* 
 * Global Function
 */
extern void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer);
extern void set_leading_zero(U8 u8type);


/*****************************************************************************
 * FUNCTION
 *  HighlightBMIMenu
 * DESCRIPTION
 *  Highlight handler of BMI menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBMIMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryBMIWelcomeScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryBMIWelcomeScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  BmiDeInit
 * DESCRIPTION
 *  Free allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BmiDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bmi_cntx)
    {
        OslMfree(g_bmi_cntx);
        g_bmi_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  BMIDelScrCB
 * DESCRIPTION
 *  Callback function of delete bmi screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 BMIDelScrCB(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_BMI_INPUT)
    {
        CloseCategory57Screen();
    }
    BmiDeInit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryBMIWelcomeScreen
 * DESCRIPTION
 *  Display welcome screen of BMI application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryBMIWelcomeScreen(void)
{
#ifndef __MMI_MAINLCD_240X320__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_BMI_WELCOME);
    EntryNewScreen(SCR_BMI_WELCOME, NULL, EntryBMIWelcomeScreen, NULL);
    ShowCategory129Screen(
        (U8*) get_string(STR_BMI_WELCOME_CAPTION),
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_BMI_WELCOME_SCREEN,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryBMIInputScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#else /* __MMI_MAINLCD_240X320__ */ 
    EntryBMIInputScreen();
#endif /* __MMI_MAINLCD_240X320__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryBMIInputScreen
 * DESCRIPTION
 *  Display inline editor screen for entering gender, height, and weight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryBMIInputScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 BMIImageList[6] = {0, 0, 0, 0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bmi_cntx == NULL)
    {
        g_bmi_cntx = OslMalloc(sizeof(bmi_context_struct));
        memset(g_bmi_cntx, 0, sizeof(bmi_context_struct));
    }

    EntryNewScreen(SCR_BMI_INPUT, ExitBMIInputScreen, NULL, NULL);
    SetDelScrnIDCallbackHandler(SCR_BMI_INPUT, (HistoryDelCBPtr) BMIDelScrCB);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_BMI_INPUT);

    BMIFillInlineStruct();

    RegisterHighlightHandler(HighlightBMIInlineEditor);

    if (g_bmi_cntx->Gender == 0)
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_BLUE_FLOWER;
    }
    else
    {
        BMIImageList[ENUM_GENDER] = IMG_BMI_RED_FLOWER;
    }

    inputBuffer = GetCurrNInputBuffer(SCR_BMI_INPUT, &inputBufferSize); /* added for inline edit history */

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, ENUM_INLINE_TOTAL, inputBuffer);   /* sets the data */
    }

    DisableCategory57ScreenDone();

#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
#endif 

    /* 041205 Calvin added : Add an image on top of category57 */
    /* Category57AppendTopImage(IMG_BMI_WELCOME_SCREEN, TRUE); */
    /* Calvin end */
#ifndef __MMI_MAINLCD_240X320__
    ShowCategory57Screen(
        STR_BMI_INPUT_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ENUM_INLINE_TOTAL,
        BMIImageList,
        wgui_inline_items,
        g_bmi_cntx->CurrHilite,
        guiBuffer);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory357Screen(
        STR_BMI_INPUT_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_BMI_WELCOME_SCREEN,
        ENUM_INLINE_TOTAL,
        BMIImageList,
        wgui_inline_items,
        g_bmi_cntx->CurrHilite,
        guiBuffer);
#endif /* __MMI_MAINLCD_240X320__ */ 

    SetCategory57RightSoftkeyFunctions(BmiComputeResult, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  ExitBMIInputScreen
 * DESCRIPTION
 *  Exit handler of EntryBMIInputScreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitBMIInputScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;    /* added for inline edit history */
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_bmi_cntx)
    {
        CloseCategory57Screen();
    }
    h.scrnID = SCR_BMI_INPUT;
    h.entryFuncPtr = EntryBMIInputScreen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);

    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */

#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    wgui_restore_list_menu_slim_style();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  BMIFillInlineStruct
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BMIFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(FALSE);

    g_bmi_cntx->GenderList[0] = (U8*) GetString(STR_BMI_MALE_TEXT);
    g_bmi_cntx->GenderList[1] = (U8*) GetString(STR_BMI_FEMALE_TEXT);

    /* gender */
    SetInlineItemActivation(&wgui_inline_items[ENUM_GENDER], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[ENUM_GENDER], 2, (U8 **) g_bmi_cntx->GenderList, &g_bmi_cntx->Gender);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[ENUM_GENDER], HighlightBMIGender);

    /* height caption */
    SetInlineItemActivation(&wgui_inline_items[ENUM_HEIGHT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[ENUM_HEIGHT_CAPTION], (U8*) GetString(STR_BMI_HEIGHT_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_HEIGHT_CAPTION]);

    /* height */
    SetInlineItemActivation(&wgui_inline_items[ENUM_HEIGHT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[ENUM_HEIGHT],
        (U8*) g_bmi_cntx->HeightBuf,
        (BMI_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[ENUM_HEIGHT]);
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_HEIGHT]);
    EnableInlineItemBoundary(&wgui_inline_items[ENUM_HEIGHT]);

    /* weight caption */
    SetInlineItemActivation(&wgui_inline_items[ENUM_WEIGHT_CAPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[ENUM_WEIGHT_CAPTION], (U8*) GetString(STR_BMI_WEIGHT_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_WEIGHT_CAPTION]);

    /* weight */
    SetInlineItemActivation(&wgui_inline_items[ENUM_WEIGHT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[ENUM_WEIGHT],
        (U8*) g_bmi_cntx->WeightBuf,
        (BMI_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[ENUM_WEIGHT]);
    SetInlineItemFullWidth(&wgui_inline_items[ENUM_WEIGHT]);
    EnableInlineItemBoundary(&wgui_inline_items[ENUM_WEIGHT]);
}


/*****************************************************************************
 * FUNCTION
 *  EntryBMIResultScreen
 * DESCRIPTION
 *  Display result screen of calculation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryBMIResultScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    DOUBLE bmiValue;
    U8 *bmiBuf;
    U8 percentageValue;
    U16 FolwerIndex;
    U8 LB, UB, prec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_bmi_cntx->ResultBuf, 0, sizeof(g_bmi_cntx->ResultBuf));

    guiBuffer = GetCurrGuiBuffer(SCR_BMI_RESULT);

    EntryNewScreen(SCR_BMI_RESULT, NULL, EntryBMIResultScreen, NULL);

    bmiValue = g_bmi_cntx->Weight / (g_bmi_cntx->Height * g_bmi_cntx->Height) * 10000;

    prec = CalcComputePrecision(bmiValue, BMI_MAX_DIGITS);
    gui_float_string(bmiValue, prec, g_bmi_cntx->ResultBuf);

    if (g_bmi_cntx->Gender == 0)
    {
        LB = BMI_MALE_LB;
        UB = BMI_MALE_UB;
        FolwerIndex = IMG_BMI_BLUE_FLOWER;
    }
    else
    {
        LB = BMI_FEMALE_LB;
        UB = BMI_FEMALE_UB;
        FolwerIndex = IMG_BMI_RED_FLOWER;
    }

    gui_itoa(LB, (U16*) g_bmi_cntx->LBBuf, 10);
    gui_itoa(UB, (U16*) g_bmi_cntx->UBBuf, 10);

    if (bmiValue > UB)
    {
        bmiBuf = (U8*) GetString(STR_BMI_FAT);
        percentageValue = 2;
    }
    else if (bmiValue < LB)
    {
        bmiBuf = (U8*) GetString(STR_BMI_THIN);
        percentageValue = 0;
    }
    else
    {
        bmiBuf = (U8*) GetString(STR_BMI_NORMAL);
        percentageValue = 1;
    }

    ShowCategory122Screen(
        STR_BMI_RESULT_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_BMI_BMI_TEXT,
        percentageValue,
        guiBuffer,
        g_bmi_cntx->ResultBuf,
        bmiBuf,
        FolwerIndex,
        (U8*) g_bmi_cntx->LBBuf,
        (U8*) g_bmi_cntx->UBBuf);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBMIInlineEditor
 * DESCRIPTION
 *  Highlight handler of inline editor in input screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBMIInlineEditor(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bmi_cntx->CurrHilite = (U8) index;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(BmiComputeResult, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBMIGender
 * DESCRIPTION
 *  Highlight handler of Gender item in input screen.
 *  Change display folwer when gender changed.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBMIGender(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bmi_cntx->Gender == 0)
    {
        Category57ChangeItemIcon(0, IMG_BMI_BLUE_FLOWER);
    }
    else
    {
        Category57ChangeItemIcon(0, IMG_BMI_RED_FLOWER);
    }

    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  BmiComputeResult
 * DESCRIPTION
 *  Validate correctness of input data and calcalute result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BmiComputeResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_buf[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    mmi_ucs2_to_asc(temp_buf, (S8*) g_bmi_cntx->HeightBuf);
    g_bmi_cntx->Height = atof(temp_buf);

    mmi_ucs2_to_asc(temp_buf, (S8*) g_bmi_cntx->WeightBuf);
    g_bmi_cntx->Weight = atof(temp_buf);

    if (((g_bmi_cntx->Height < BMI_MIN_HEIGHT) || (g_bmi_cntx->Height > BMI_MAX_HEIGHT)) &&
        ((g_bmi_cntx->Weight < BMI_MIN_WEIGHT) || (g_bmi_cntx->Weight > BMI_MAX_WEIGHT)))
    {
        DisplayPopup(
            (U8*) GetString(STR_BMI_HEIGHT_WEIGHT_ERROR),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        g_bmi_cntx->CurrHilite = 2;
        return;
    }
    else if ((g_bmi_cntx->Height < BMI_MIN_HEIGHT) || (g_bmi_cntx->Height > BMI_MAX_HEIGHT))
    {
        DisplayPopup(
            (U8*) GetString(STR_BMI_HEIGHT_ERROR_TEXT),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        g_bmi_cntx->CurrHilite = 2;
        return;
    }
    else if ((g_bmi_cntx->Weight < BMI_MIN_WEIGHT) || (g_bmi_cntx->Weight > BMI_MAX_WEIGHT))
    {
        DisplayPopup(
            (U8*) GetString(STR_BMI_WEIGHT_ERROR_TEXT),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        g_bmi_cntx->CurrHilite = 4;
        return;
    }

    g_bmi_cntx->CurrHilite = 0;
    EntryBMIResultScreen();
}

#endif /* __MMI_BMI__ */ // #ifdef __MMI_BMI__
#endif /* _MMI_BMI_C */ // #ifndef _MMI_BMI_C

