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
 * Currencyconvertor.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Currency Convertor application.
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
   Filename:      Currencyconvertor.c
   Author:        Vandana M
   Date Created:  June-29-2003
   Contains:      Currency Convertor
**********************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_CURRENCYCONVRETOR_C
#define _MMI_CURRENCYCONVRETOR_C

/*  Include: MMI header file */

#include "wgui_inputs.h"
#if defined __MMI_CURRENCY_CONVERTER__
#include "WrapperGprot.h"
#include "CurrencyConvertor.h"
#include "UnitConvertor.h"
#include "SettingProfile.h"
#include "string.h"
#include "OrganizerDef.h"
#include "CustDataProts.h"
#include "CommonScreens.h"
#if defined(__MMI_TOUCH_SCREEN__)
#endif 
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Define
 */
#define  CCONV_MAX_RATE          5
#define  CCONV_MAX_INPUT            7
#define  CCONV_MAX_RESULT        12
#define  CCONV_SEL_BUF_LEN       10*ENCODING_LENGTH     /* length of inline selection string */
#define  CCONV_RESULT_BUF_LEN    (CCONV_MAX_RESULT+1)*ENCODING_LENGTH

/* 
 * Typedef 
 */
typedef struct
{
    DOUBLE Rate;
    S32 CurrSelRate;    /* current selecting rate */
    S8 *RateList[2];
    S8 LocalBuff[CCONV_RESULT_BUF_LEN];
    S8 ForeBuff[CCONV_RESULT_BUF_LEN];
    S8 RateBuff[CCONV_RESULT_BUF_LEN];
    S8 RateString[2][CCONV_SEL_BUF_LEN];
    U8 CurrHiliteItem;
    U8 ClearResultFlag;
    U8 IsFromHistory;
    /* U8   IsComputingResult; */
} cconv_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
U8 mmi_cconv_del_scr_callback(void *p);

/* 
 * Global Variable
 */
cconv_context_struct *g_cconv_cntx = NULL;
extern wgui_inline_item wgui_inline_items[];

#if defined(__MMI_TOUCH_SCREEN__)
extern void (*complete_inline_item_edit) (void);
#endif 

/* 
 * Global Function
 */
extern void set_leading_zero(U8 u8type);
extern DOUBLE gui_atof(UI_string_type s);
extern void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer);
extern S32 CalcComputePrecision(DOUBLE result, S16 max_digits);

extern void HighlightCConvMenu(void);
extern void EntryCconvApp(void);
extern void ExitCConvApp(void);
extern void CconvPreEntryExchange(void);
extern void EntryCConvExchange(void);
extern void ExitCConvExchange(void);
extern void HighlightCconvInlineItemHandler(S32 index);
extern void HighlightCconvInlineSelHandler(S32 index);
extern void CconvCustomInlineFunction(void);
extern void CconvClearResult(void);

#define UCONV_RATE_INPUT


/*****************************************************************************
 * FUNCTION
 *  CconvInit
 * DESCRIPTION
 *  Initialize currency converter application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_CURRENCYCONVERTOR_MENU, HighlightCConvMenu);
}


/*****************************************************************************
 * FUNCTION
 *  CconvDeInit
 * DESCRIPTION
 *  Free allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_cntx)
    {
        OslMfree(g_cconv_cntx);
        g_cconv_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_del_scr_callback
 * DESCRIPTION
 *  Callback function of delete currencty converter screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_cconv_del_scr_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_CCONV_RATE_INPUT || GetActiveScreenId() == SCR_ID_CCONV_COMPUTE)
    {
        CloseCategory57Screen();
    }
    CconvDeInit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CconvPreEntryApp
 * DESCRIPTION
 *  Application memory and entry application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvPreEntryApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_cntx)
    {
        OslMfree(g_cconv_cntx);
    }

    g_cconv_cntx = OslMalloc(sizeof(cconv_context_struct));
    memset(g_cconv_cntx, 0, sizeof(cconv_context_struct));

    EntryCconvApp();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCConvMenu
 * DESCRIPTION
 *  Highlight handler of Currency Converter menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCConvMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(CconvPreEntryApp, KEY_EVENT_UP);
    SetKeyHandler(CconvPreEntryApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCconvRateItem
 * DESCRIPTION
 *  Highlight handler of rate input inline item.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCconvRateItem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(CconvPreEntryExchange, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCconvApp
 * DESCRIPTION
 *  Display rate input screen of currency convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCconvApp()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 precision;
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S16 error;
    U16 RskImg = STR_GLOBAL_BACK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CCONV_RATE_INPUT, ExitCConvApp, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CCONV_RATE_INPUT);

    SetDelScrnIDCallbackHandler(SCR_ID_CCONV_RATE_INPUT, (HistoryDelCBPtr) mmi_cconv_del_scr_callback);

    InitializeCategory57Screen();


    inputBuffer = GetCurrNInputBuffer(SCR_ID_CCONV_COMPUTE, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);   /* sets the data */
    }

    if (g_cconv_cntx->IsFromHistory)
    {
        g_cconv_cntx->Rate = gui_atof((U16*) g_cconv_cntx->RateBuff);
        if (mmi_ucs2strlen(g_cconv_cntx->RateBuff))
        {
            RskImg = STR_GLOBAL_CLEAR;
        }
        else
        {
            RskImg = STR_GLOBAL_BACK;
        }
    }
    else
    {
        ReadValue(CURRENCY_CONVERTOR_EXCHANGE_RATE, &g_cconv_cntx->Rate, DS_DOUBLE, &error);
        g_cconv_cntx->IsFromHistory = TRUE;
        if (g_cconv_cntx->Rate <= 999999 && g_cconv_cntx->Rate > 0) /* o data has been written set the text to blank */
        {
            precision = CalcComputePrecision(g_cconv_cntx->Rate, CCONV_MAX_RATE);
            gui_float_string(g_cconv_cntx->Rate, precision, (S8*) g_cconv_cntx->RateBuff);
        }
        if (guiBuffer)
        {
            memset((void*)guiBuffer, 0, 2);
        }

    }

    SetInlineItemCaption(&wgui_inline_items[0], (U8*) get_string(STR_CURRENCYCONVERTOR_RATE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (U8*) g_cconv_cntx->RateBuff,
        (CCONV_MAX_RATE + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    RightJustifyInlineItem(&wgui_inline_items[1]);

    set_leading_zero(FALSE);
    RegisterHighlightHandler(HighlightCconvRateItem);

    ShowCategory257Screen(
        STR_CURRENCYCONVERTOR_RATEINPUT,
        GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        RskImg,
        IMG_GLOBAL_BACK,
        CURRENCY_CONVERTOR_IMAGE,
        2,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(CconvPreEntryExchange, GoBackHistory);
    SetLeftSoftkeyFunction(CconvPreEntryExchange, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCConvApp
 * DESCRIPTION
 *  Display rate input screen of currency convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCConvApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;    /* added for inline edit history */
    history HistoryCCComputeCurrency;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_cconv_cntx)
    {
        CloseCategory57Screen();
    }
    HistoryCCComputeCurrency.scrnID = SCR_ID_CCONV_RATE_INPUT;
    HistoryCCComputeCurrency.entryFuncPtr = EntryCconvApp;
    GetCategory57History(HistoryCCComputeCurrency.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryCCComputeCurrency.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryCCComputeCurrency.inputBuffer);     /* added for inline edit history */
    AddNHistory(HistoryCCComputeCurrency, inputBufferSize); /* added for inline edit history */
}

#define UCONV_CONVERTING


/*****************************************************************************
 * FUNCTION
 *  CconvComputeResult
 * DESCRIPTION
 *  Convert the result and display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvComputeResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 precision;
    DOUBLE result, conversion_factor;

#if 0
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    if ((gui_strlen((UI_string_type) g_cconv_cntx->LocalBuff) < 1) || (g_cconv_cntx->LocalBuff[0] == '.'))
    {
        memset(g_cconv_cntx->ForeBuff, 0, 15);
        DisplayPopup(
            (U8*) GetString(ERROR_CURRENCYCONVERTOR_RATE1),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    /* calculate result */
    if (g_cconv_cntx->CurrSelRate)  /* 1:R */
    {
        conversion_factor = g_cconv_cntx->Rate;
    }
    else
    {
        conversion_factor = (1 / g_cconv_cntx->Rate);
    }

    result = (DOUBLE) (conversion_factor * gui_atof((UI_string_type) g_cconv_cntx->LocalBuff));

    precision = CalcComputePrecision(result, CCONV_MAX_RESULT);

    gui_float_string(result, precision, (S8*) g_cconv_cntx->ForeBuff);

    g_cconv_cntx->ClearResultFlag = 1;

#ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
    RedrawCategoryFunction();
#if 0
/* under construction !*/
	#if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if defined(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
	#endif
#endif /* 0 */ 
#else /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 

    SetHighlightedItem(0);
#endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 

    SetLeftSoftkeyFunction(CconvComputeResult, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  CconvPreEntryExchange
 * DESCRIPTION
 *  Pre-entry function for exchange screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvPreEntryExchange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    g_cconv_cntx->Rate = gui_atof((U16*) g_cconv_cntx->RateBuff /* Currency_Convertor_rate.text */ );

	/* If the rate is ".xxx", it will be treated as wrong input. */
    if (gui_strlen((UI_string_type) g_cconv_cntx->RateBuff) < 1 || g_cconv_cntx->Rate == 0 || g_cconv_cntx->RateBuff[0] == '.')
    {
        DisplayPopup(
            (U8*) GetString(ERROR_CURRENCYCONVERTOR_RATE1),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }
    else
    {
        g_cconv_cntx->CurrSelRate = 0;
        g_cconv_cntx->CurrHiliteItem = 0;

        memset(g_cconv_cntx->LocalBuff, 0, ENCODING_LENGTH);
        memset(g_cconv_cntx->ForeBuff, 0, ENCODING_LENGTH);

        WriteValue(CURRENCY_CONVERTOR_EXCHANGE_RATE, &g_cconv_cntx->Rate, DS_DOUBLE, &error);
        g_cconv_cntx->IsFromHistory = FALSE;
        EntryCConvExchange();
    }
}


/*****************************************************************************
 * FUNCTION
 *  CConvFillInlineStruct
 * DESCRIPTION
 *  Fill inline structure of converting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CConvFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 precision;
    U8 strTemp[] = { ':', '\0', '1', '\0', '\0', '\0' };
    U8 strTemp2[] = { '1', '\0', ':', '\0', '\0', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    precision = CalcComputePrecision(g_cconv_cntx->Rate, 6);

    gui_float_string(g_cconv_cntx->Rate, precision, g_cconv_cntx->RateString[0]);

    mmi_ucs2cpy((S8*) g_cconv_cntx->RateString[1], (S8*) strTemp2);      /* 1:R */
    mmi_ucs2cat((S8*) g_cconv_cntx->RateString[1], (S8*) g_cconv_cntx->RateString[0]);   /* R:1 */
    mmi_ucs2cat((S8*) g_cconv_cntx->RateString[0], (S8*) strTemp);

    g_cconv_cntx->RateList[0] = g_cconv_cntx->RateString[0];
    g_cconv_cntx->RateList[1] = g_cconv_cntx->RateString[1];

    set_leading_zero(FALSE);
    DisableInlineInputMethodHints();

    SetInlineItemActivation(&wgui_inline_items[CCONV_INLINE_RATE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[CCONV_INLINE_RATE],
        2,
        (U8 **) g_cconv_cntx->RateList,
        &g_cconv_cntx->CurrSelRate);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[CCONV_INLINE_RATE], HighlightCconvInlineSelHandler);

    SetInlineItemActivation(&wgui_inline_items[CCONV_INLINE_LOCAL_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[CCONV_INLINE_LOCAL_CAP], (U8*) GetString(STR_CURRENCYCONVERTOR_LOCAL));

    SetInlineItemActivation(&wgui_inline_items[CCONV_INLINE_LOCAL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[CCONV_INLINE_LOCAL],
        (U8*) g_cconv_cntx->LocalBuff,
        (CCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    SetInlineTextEditCustomFunction(&wgui_inline_items[CCONV_INLINE_LOCAL], CconvCustomInlineFunction);
    EnableInlineItemBoundary(&wgui_inline_items[CCONV_INLINE_LOCAL]);
    RightJustifyInlineItem(&wgui_inline_items[CCONV_INLINE_LOCAL]);

    SetInlineItemActivation(&wgui_inline_items[CCONV_INLINE_FORE_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &wgui_inline_items[CCONV_INLINE_FORE_CAP],
        (U8*) (U8*) GetString(STR_CURRENCYCONVERTOR_FOREIGN));

    SetInlineItemActivation(&wgui_inline_items[CCONV_INLINE_FORE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[CCONV_INLINE_FORE],
        (U8*) g_cconv_cntx->ForeBuff,
        (CCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[CCONV_INLINE_FORE]);
    RightJustifyInlineItem(&wgui_inline_items[CCONV_INLINE_FORE]);
    DisableInlineItem(&wgui_inline_items[CCONV_INLINE_FORE], CCONV_INLINE_FORE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCConvExchange
 * DESCRIPTION
 *  Entry Function of Compute currency exchange
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCConvExchange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CCONV_COMPUTE, ExitCConvExchange, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CCONV_COMPUTE);

    InitializeCategory57Screen();

    CConvFillInlineStruct();

    RegisterHighlightHandler(HighlightCconvInlineItemHandler);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_CCONV_COMPUTE, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, CCONV_INLINE_TOTAL, inputBuffer);  /* sets the data */
    }
	DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_CURRENCYCONVERTOR_INPUT,
        GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        CCONV_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        g_cconv_cntx->CurrHiliteItem,
        guiBuffer);

    SetLeftSoftkeyFunction(CconvComputeResult, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(CconvComputeResult, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCConvExchange
 * DESCRIPTION
 *  Entry Function of Compute currency exchange
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCConvExchange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;    /* added for inline edit history */
    history HistoryCCComputeCurrency;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_cconv_cntx)
    {
        CloseCategory57Screen();
    }
    HistoryCCComputeCurrency.scrnID = SCR_ID_CCONV_COMPUTE;
    HistoryCCComputeCurrency.entryFuncPtr = EntryCConvExchange;
    GetCategory57History(HistoryCCComputeCurrency.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryCCComputeCurrency.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryCCComputeCurrency.inputBuffer);     /* added for inline edit history */
    AddNHistory(HistoryCCComputeCurrency, inputBufferSize); /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCconvInlineSelHandler
 * DESCRIPTION
 *  Highlight handler of inline selection.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCconvInlineSelHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_cconv_cntx->LocalBuff, 0, ENCODING_LENGTH);
    memset(g_cconv_cntx->ForeBuff, 0, ENCODING_LENGTH);
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCconvInlineItemHandler
 * DESCRIPTION
 *  Highlight handler of inline item in exchange screen.
 * PARAMETERS
 *  index       [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCconvInlineItemHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        //              if(!g_cconv_cntx->IsComputingResult)
        //              {
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ChangeLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        /* } */
    }
    else    /* 2 */
    {
    #ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
        if (g_cconv_cntx->CurrHiliteItem != index)
        {
            memset(g_cconv_cntx->LocalBuff, 0, 2);
            memset(g_cconv_cntx->ForeBuff, 0, 2);
        }
        else if (!g_cconv_cntx->ClearResultFlag && *(g_cconv_cntx->ForeBuff) != 0)
        {
            g_cconv_cntx->ClearResultFlag = 1;
        }

    #if !defined(__MMI_WITH_C_KEY__)
        SetCategory57ScreenRSKClear();  /* Max: set RSK to "Clear" */
    #endif 

        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(CconvComputeResult, KEY_EVENT_UP);
    #else /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
        if (g_cconv_cntx->CurrHiliteItem != index)
        {
            memset(g_cconv_cntx->LocalBuff, 0, 2);
            memset(g_cconv_cntx->ForeBuff, 0, 2);
        }
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(CconvComputeResult, KEY_EVENT_UP);
    #endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 

    }
    g_cconv_cntx->CurrHiliteItem = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  CconvCustomInlineFunction
 * DESCRIPTION
 *  Set group key handlers of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvCustomInlineFunction(void)
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
    if (g_cconv_cntx->ClearResultFlag)
    {
        g_cconv_cntx->ClearResultFlag = 0;
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
        ChangeRightSoftkey(STR_ID_CURRENCYCONVERTOR_RESET, 0);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    }
#endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
}

#endif /* defined __MMI_CURRENCY_CONVERTER__ */ 


/*****************************************************************************
 * FUNCTION
 *  CconvClearResult
 * DESCRIPTION
 *  Clear buffer and input a character.
 *  This function is used for new digits input after calculation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CconvClearResult(void)
{
#ifdef __MMI_CONVERTER_KEEP_INLINE_FOCUS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode, keyType;
    S32 hItem = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo((U16*) & keyCode, (U16*) & keyType);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
#if defined(__MMI_TOUCH_SCREEN__)
    complete_inline_item_edit();
#endif 
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, 0);
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, hItem);
    show_fixed_list();
    if (keyType == KEY_EVENT_LONG_PRESS)
    {
        SetRightSoftkeyFunction(mmi_conv_reset_rsk, KEY_EVENT_UP);
    }
    if (keyCode != KEY_CLEAR)
    {
        ExecuteCurrKeyHandler(keyCode, keyType);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif /* __MMI_CONVERTER_KEEP_INLINE_FOCUS__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_conv_reset_rsk
 * DESCRIPTION
 *  This function is used reset RSK.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_conv_reset_rsk(void)
{
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* _MMI_CURRENCYCONVRETOR_C */ // #ifndef _MMI_CURRENCYCONVRETOR_C

