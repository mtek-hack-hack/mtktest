/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
*
* Filename:
* ---------
*  CurrencyConvertorE.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements Cur Convertor application.
*
* Author:
* -------
*  Cecil Wei
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 * Update foreign rate immediately when local rate has been changed.
 *
 * removed!
 * removed!
 * Redraw the single text line after updating its position.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add screen check when executing closecategory57.
 *
 * removed!
 * removed!
 * Execute closeCategory57 in delete callback function.
 *
 * removed!
 * removed!
 * Move CconvClearResult out of __MMI_CURRENCY_CONVERTER__ and __MMI_EXTENDED_CURRENCY_CONVERTER__
 * 
 *
 * removed!
 * removed!
 * Skip CloseCategory57Screen() if global context has already been freed by delete callback function.
 *
 * removed!
 * removed!
 * Save the gui buffer to history when exiting screen.
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
 * Remove CconvClearResult function
 *
 * removed!
 * removed!
 * 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================*/

#include "MMI_include.h"
#ifndef _MMI_CURRENCYCONVERTORE_C
#define _MMI_CURRENCYCONVERTORE_C
/*  Include: MMI header file */
#ifdef __MMI_EXTENDED_CURRENCY_CONVERTER__
#include "WrapperGprot.h"
#include "currencyconvertorE.h"
#include "CurrencyConvertor.h"
#include "SettingProfile.h"
#include "wgui_inputs.h"
#include "string.h"
#include "ExtraDef.h"
#include "CustDataProts.h"
#include "CommonScreens.h"
/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Define
 */
#define  CCONV_MAX_CURRENCY      9      /* total number of currencies */
#define  CCONV_NAMED_CURRENCY    6      /* number of named currencies */
#define  CCONV_MAX_RATE          10
#define  CCONV_MAX_INPUT         8
#define  CCONV_MAX_RESULT        12
#define  CCONV_SEL_BUF_LEN       12*ENCODING_LENGTH     /* length of inline selection string */
#define  CCONV_RESULT_BUF_LEN    (12+1)*ENCODING_LENGTH
#define  CCONV_MAX_RATEENTRIES   5      /* number of exchange rate entries */
#define  ITEM_BASE               CCONV_RATE_INLINE_FORE_SELECT1
/* 
 * Typedef 
 */
typedef struct
{
    DOUBLE selectedRate;    /* active exchange rate */
    DOUBLE rate[CCONV_MAX_RATEENTRIES];

    S32 localCurID;     /* selected local cur */
    S32 foreignCurID;   /* selected foreign cur */

    S32 localCurIndex;      /* selected local cur */
    S32 foreignCurIndex;    /* selected foreign cur */

    S32 curID[CCONV_MAX_RATEENTRIES];       /* Setting selected foreign cur */
    S32 curIndex[CCONV_MAX_RATEENTRIES];    /* Setting selected foreign cur */
    S32 selectedLocalCurID;                 /* selected local cur */
    S32 prevSelectedLocalCurID;             /* previous selected local cur */

    S8 LocalBuff[CCONV_RESULT_BUF_LEN];
    S8 ForeBuff[CCONV_RESULT_BUF_LEN];
    S8 strRate[CCONV_MAX_RATEENTRIES][CCONV_SEL_BUF_LEN];
    S32 hiliteItemIndex;
    /* U8   IsComputingResult; */
    S8 *curList1[CCONV_MAX_CURRENCY];
    S8 *curList2[CCONV_MAX_CURRENCY];
    S8 *curList[CCONV_MAX_RATEENTRIES][CCONV_MAX_CURRENCY];

    U8 reloadFromNVRAM;
    U8 isRedrawScreen;
    S8 bRateDefined;

} cconv_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
/* Utility functions */
S32 mmi_cconv_get_cur_id(S32 index, S8 **list);
S32 mmi_cconv_get_cur_index(S32 id, S8 **list, S8 nItems);
DOUBLE mmi_cconv_get_exchange_rate(S32 cur1Idx, S32 cur2Idx);
void mmi_cconv_compute_result(U8 *buffer);
void mmi_cconv_return_to_menu(void);
void mmi_cconv_fill_inline(void);
U8 mmi_cconv_del_scr_callback(void *p);
S8 mmi_cconv_local_select_list();
S8 mmi_cconv_fore_select_list();

/* Highlight handlers */
void mmi_cconv_compute_item_highlight_hdlr(S32 index);
void mmi_cconv_compute_local_select_highlight_hdlr(S32 index);
void mmi_cconv_compute_fore_select_highlight_hdlr(S32 index);
void mmi_cconv_compute_inline_edit_highlight_hdlr(void);
void mmi_cconv_rate_item_highlight_hdlr(S32 index);
void mmi_cconv_rate_local_select_hdlr(S32 index);
void mmi_cconv_rate_inline_select_highlight_hdlr(S32 index);
void mmi_cconv_rate_inline_edit_highlight_hdlr(void);
void mmi_cconv_rate_inline_edit_key_hdlr(void);

/* Validation handler */
void mmi_cconv_compute_inline_edit_validation_hdlr(U8 *buffer, U8 *cursor, S32 text_length);
void mmi_cconv_rate_inline_edit_validation_hdlr(U8 *buffer, U8 *cursor, S32 text_length);

/* Key Handlers */
void mmi_cconv_rate_save_change(void);

/* 
 * Global Variable
 */
cconv_context_struct *g_cconv_ctx = NULL;
extern wgui_inline_item wgui_inline_items[];
extern single_line_input_box MMI_inline_singleline_inputbox;
S8 *curShortName[CCONV_MAX_CURRENCY];
S8 *curName[CCONV_MAX_CURRENCY];
S8 *strEmpty = "\0\0";

/* 
 * Global Function
 */
extern void set_leading_zero(U8 u8type);
extern DOUBLE gui_atof(UI_string_type s);
extern void gui_float_string(DOUBLE dob_val, S32 prec_val, S8 *out_buffer);
extern S32 CalcComputePrecision(DOUBLE result, S16 max_digits);
extern void inline_edit_singleline_inputbox_next_character(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_init
 * DESCRIPTION
 *  Initialize cur converter application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_CURRENCYCONVERTOR_MENU, mmi_cconv_menu_highlight_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_deinit
 * DESCRIPTION
 *  Free allocated memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_ctx)
    {
        OslMfree(g_cconv_ctx);
        g_cconv_ctx = NULL;
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
    mmi_cconv_deinit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_pre_entry_app
 * DESCRIPTION
 *  Init the Application memory and entry application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_pre_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_ctx)
    {
        OslMfree(g_cconv_ctx);
    }

    g_cconv_ctx = OslMalloc(sizeof(cconv_context_struct));
    memset(g_cconv_ctx, 0, sizeof(cconv_context_struct));

    /* Preload currency name */
    for (i = 0; i < CCONV_MAX_CURRENCY; i++)
    {
        curName[i] = GetString((U16) (STR_CURRENCYCONV_USD + i));
        if (i < CCONV_NAMED_CURRENCY)
        {
            curShortName[i] = GetString((U16) (STR_CURRENCYCONV_USD_ABBR + i));
        }
        else
        {
            curShortName[i] = strEmpty;
        }
    }

    g_cconv_ctx->reloadFromNVRAM = TRUE;
    g_cconv_ctx->isRedrawScreen = FALSE;

    if (g_cconv_ctx->reloadFromNVRAM)
    {

        ReadValue(NVRAM_CCONV_SELECTED_CURRENCY1, &g_cconv_ctx->localCurID, DS_BYTE, &error);
        if (error == NVRAM_READ_FAIL)
        {
            g_cconv_ctx->localCurID = 0;

        }
        ReadValue(NVRAM_CCONV_SELECTED_CURRENCY2, &g_cconv_ctx->foreignCurID, DS_BYTE, &error);
        if (error == NVRAM_READ_FAIL)
        {
            g_cconv_ctx->foreignCurID = 0;
        }

        for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
        {
            ReadValue((U8) (NVRAM_CCONV_SETTING_CURRENCY1 + i), &g_cconv_ctx->curID[i], DS_BYTE, &error);
            if (error == NVRAM_READ_FAIL)
            {
                g_cconv_ctx->curID[i] = 0;
            }

            ReadValue((U8) (NVRAM_CCONV_EXCHANGE_RATE1 + i), &g_cconv_ctx->rate[i], DS_DOUBLE, &error);
            if (error == NVRAM_READ_FAIL)
            {
                g_cconv_ctx->rate[i] = -1;
            }
            if (!g_cconv_ctx->bRateDefined && g_cconv_ctx->rate[i] > 0)
            {
                g_cconv_ctx->bRateDefined = TRUE;
            }
        }

        ReadValue(NVRAM_CCONV_SETTING_LOCALCURRENCY, &g_cconv_ctx->selectedLocalCurID, DS_BYTE, &error);
        if (error == NVRAM_READ_FAIL || g_cconv_ctx->selectedLocalCurID == 0xff)
        {
            g_cconv_ctx->selectedLocalCurID = 0;
        }
        g_cconv_ctx->prevSelectedLocalCurID = g_cconv_ctx->selectedLocalCurID;

        memset(g_cconv_ctx->LocalBuff, 0, ENCODING_LENGTH);
        memset(g_cconv_ctx->ForeBuff, 0, ENCODING_LENGTH);
        g_cconv_ctx->hiliteItemIndex = 0;
    }
    mmi_cconv_entry_app();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Cur Converter menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_cconv_pre_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_entry_app
 * DESCRIPTION
 *  Display rate input screen of cur convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_cconv_ctx->bRateDefined)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(ERROR_CURRENCYCONV_RATE2),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        if (IsScreenPresent(SCR_ID_CCONV_RATE_INPUT))
        {
            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_cconv_pre_entry_rate, KEY_EVENT_UP);
        }
        SetRightSoftkeyFunction(mmi_cconv_return_to_menu, KEY_EVENT_UP);
        return;
    }
    else
    {
        g_cconv_ctx->selectedRate = mmi_cconv_get_exchange_rate(g_cconv_ctx->localCurID, g_cconv_ctx->foreignCurID);
    }

    EntryNewScreen(SCR_ID_CCONV_COMPUTE, mmi_cconv_exit_app, NULL, NULL);

    RegisterHighlightHandler(mmi_cconv_compute_item_highlight_hdlr);

    SetDelScrnIDCallbackHandler(SCR_ID_CCONV_COMPUTE, (HistoryDelCBPtr) mmi_cconv_del_scr_callback);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CCONV_COMPUTE);

    InitializeCategory57Screen();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_CCONV_COMPUTE, &inputBufferSize);  /* added for inline edit history */

    if (inputBuffer && g_cconv_ctx->isRedrawScreen == FALSE)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, CCONV_CURRENCY_INLINE_TOTAL, inputBuffer); /* sets the data */
    }
    else
    {
        g_cconv_ctx->isRedrawScreen = FALSE;
    }

    set_leading_zero(FALSE);
    DisableInlineInputMethodHints();

    mmi_cconv_fill_inline();

    ShowCategory57Screen(
        STR_CURRENCYCONV_INPUT,
        GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU),
        STR_CURRENCYCONV_RATE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        CCONV_CURRENCY_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        g_cconv_ctx->hiliteItemIndex,
        guiBuffer);

    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(mmi_cconv_return_to_menu, mmi_cconv_return_to_menu);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_rate, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_fill_inline
 * DESCRIPTION
 *  Fill inline editor structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_fill_inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 nItems1 = 0, nItems2 = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nItems1 = mmi_cconv_local_select_list(&nItems1);
    nItems2 = mmi_cconv_fore_select_list(&nItems2);

    SetInlineItemActivation(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL_SELECT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL_SELECT],
        nItems1,
        (U8 **) g_cconv_ctx->curList1,
        &g_cconv_ctx->localCurIndex);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL_SELECT],
        mmi_cconv_compute_local_select_highlight_hdlr);
    if (nItems1 == 0)
    {
        DisableInlineItem(&wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL_SELECT], 0);
    }

    SetInlineItemActivation(&wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL],
        (U8*) g_cconv_ctx->LocalBuff,
        (CCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    SetInlineTextEditCustomFunction(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL],
        mmi_cconv_compute_inline_edit_highlight_hdlr);
    RegisterInlineFullScreenEditValidationFunction(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL],
        mmi_cconv_compute_inline_edit_validation_hdlr);
    EnableInlineItemBoundary(&wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL]);
    RightJustifyInlineItem(&wgui_inline_items[CCONV_CURRENCY_INLINE_LOCAL]);

    SetInlineItemActivation(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_FORE_SELECT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_FORE_SELECT],
        nItems2,
        (U8 **) g_cconv_ctx->curList2,
        &g_cconv_ctx->foreignCurIndex);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_FORE_SELECT],
        mmi_cconv_compute_fore_select_highlight_hdlr);
    if (nItems2 == 0)
    {
        DisableInlineItem(&wgui_inline_items[CCONV_CURRENCY_INLINE_FORE_SELECT], 2);
    }

    SetInlineItemActivation(&wgui_inline_items[CCONV_CURRENCY_INLINE_FORE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[CCONV_CURRENCY_INLINE_FORE],
        (U8*) g_cconv_ctx->ForeBuff,
        (CCONV_MAX_INPUT + 1),
        INPUT_TYPE_DECIMAL_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[CCONV_CURRENCY_INLINE_FORE]);
    RightJustifyInlineItem(&wgui_inline_items[CCONV_CURRENCY_INLINE_FORE]);
    DisableInlineItem(&wgui_inline_items[CCONV_CURRENCY_INLINE_FORE], 3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_exit_app
 * DESCRIPTION
 *  Display rate input screen of cur convertor application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;    /* added for inline edit history */
    history HistoryCCComputeCurrency;
    S16 nHistory = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_cconv_ctx)
    {
        g_cconv_ctx->localCurID = mmi_cconv_get_cur_id(g_cconv_ctx->localCurIndex, g_cconv_ctx->curList1);
        g_cconv_ctx->foreignCurID = mmi_cconv_get_cur_id(g_cconv_ctx->foreignCurIndex, g_cconv_ctx->curList2);

        WriteValue(NVRAM_CCONV_SELECTED_CURRENCY1, &g_cconv_ctx->localCurID, DS_BYTE, &error);
        WriteValue(NVRAM_CCONV_SELECTED_CURRENCY2, &g_cconv_ctx->foreignCurID, DS_BYTE, &error);
        CloseCategory57Screen();
    }

    HistoryCCComputeCurrency.scrnID = SCR_ID_CCONV_COMPUTE;
    HistoryCCComputeCurrency.entryFuncPtr = mmi_cconv_entry_app;
    GetCategory57History(HistoryCCComputeCurrency.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryCCComputeCurrency.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryCCComputeCurrency.inputBuffer);     /* added for inline edit history */
    AddNHistory(HistoryCCComputeCurrency, inputBufferSize); /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_pre_entry_rate
 * DESCRIPTION
 *  Pre-entry function for exchange screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_pre_entry_rate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cconv_ctx->hiliteItemIndex = 0;

    CloseCategory57Screen();

    mmi_cconv_entry_rate();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_select_list
 * DESCRIPTION
 *  create rate selection list for rate setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_select_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 listCount[CCONV_MAX_RATEENTRIES];
    S8 strTemp[] = { ' ', '\0', '\0', '\0' };
    S32 precision;
    S8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Exchange rate Input Setting */
    for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (i == 0)
        {
            for (j = 0, listCount[i] = 0; j < CCONV_MAX_CURRENCY; j++)
            {
                if (curName[j] == curName[g_cconv_ctx->selectedLocalCurID])
                {
                    continue;
                }
                g_cconv_ctx->curList[0][listCount[0]++] = curName[j];
            }
        }
        else
        {
            for (j = 0, listCount[i] = 0; j < listCount[i - 1]; j++)
            {
                if (g_cconv_ctx->curList[i - 1][j] == curName[g_cconv_ctx->curID[i - 1]])
                {
                    continue;
                }
                g_cconv_ctx->curList[i][listCount[i]++] = g_cconv_ctx->curList[i - 1][j];
            }
        }

        g_cconv_ctx->curIndex[i] = mmi_cconv_get_cur_index(g_cconv_ctx->curID[i], g_cconv_ctx->curList[i], listCount[i]);
        g_cconv_ctx->curID[i] = mmi_cconv_get_cur_id(g_cconv_ctx->curIndex[i], g_cconv_ctx->curList[i]);

        SetInlineItemActivation(&wgui_inline_items[ITEM_BASE + i * 2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[ITEM_BASE + i * 2],
            listCount[i],
            (U8 **) g_cconv_ctx->curList[i],
            &g_cconv_ctx->curIndex[i]);
        RegisterInlineSelectHighlightHandler(
            &wgui_inline_items[ITEM_BASE + i * 2],
            mmi_cconv_rate_inline_select_highlight_hdlr);

        memset(g_cconv_ctx->strRate[i], 0, CCONV_SEL_BUF_LEN);
        if (g_cconv_ctx->rate[i] > 0)
        {
            precision = CalcComputePrecision(g_cconv_ctx->rate[i], CCONV_MAX_RESULT);
            gui_float_string(g_cconv_ctx->rate[i], precision, (S8*) g_cconv_ctx->strRate[i]);
        }
        if (g_cconv_ctx->selectedLocalCurID < CCONV_NAMED_CURRENCY)
        {
            mmi_ucs2cat((S8*) g_cconv_ctx->strRate[i], (S8*) strTemp);   /* concatenate white space */
            mmi_ucs2cat((S8*) g_cconv_ctx->strRate[i], (S8*) curShortName[g_cconv_ctx->selectedLocalCurID]);
        }
        SetInlineItemActivation(&wgui_inline_items[ITEM_BASE + i * 2 + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(
            &wgui_inline_items[ITEM_BASE + i * 2 + 1],
            (U8*) g_cconv_ctx->strRate[i],
            (CCONV_MAX_RATE + 1),
            INPUT_TYPE_DECIMAL_NUMERIC);
        SetInlineTextEditCustomFunction(
            &wgui_inline_items[ITEM_BASE + i * 2 + 1],
            mmi_cconv_rate_inline_edit_highlight_hdlr);
        RegisterInlineFullScreenEditValidationFunction(
            &wgui_inline_items[ITEM_BASE + i * 2 + 1],
            mmi_cconv_rate_inline_edit_validation_hdlr);
        EnableInlineItemBoundary(&wgui_inline_items[ITEM_BASE + i * 2 + 1]);
        RightJustifyInlineItem(&wgui_inline_items[ITEM_BASE + i * 2 + 1]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_layout_inline_items
 * DESCRIPTION
 *  Layout inline items in rate screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_layout_inline_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(FALSE);
    DisableInlineInputMethodHints();

    /* Local Currency Selection */
    SetInlineItemActivation(&wgui_inline_items[CCONV_RATE_INLINE_LOCAL_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[CCONV_RATE_INLINE_LOCAL_CAP], (U8*) GetString(STR_CURRENCYCONV_LOCAL));

    SetInlineItemActivation(
        &wgui_inline_items[CCONV_RATE_INLINE_LOCAL_SELECT],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &wgui_inline_items[CCONV_RATE_INLINE_LOCAL_SELECT],
        CCONV_MAX_CURRENCY,
        (U8 **) curName,
        &g_cconv_ctx->selectedLocalCurID);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[CCONV_RATE_INLINE_LOCAL_SELECT],
        mmi_cconv_rate_local_select_hdlr);

    SetInlineItemActivation(&wgui_inline_items[CCONV_RATE_INLINE_FORE_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[CCONV_RATE_INLINE_FORE_CAP], (U8*) GetString(STR_CURRENCYCONV_FOREIGN));

    mmi_cconv_rate_select_list();

    g_cconv_ctx->prevSelectedLocalCurID = g_cconv_ctx->selectedLocalCurID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_entry_rate
 * DESCRIPTION
 *  Entry Function of Compute cur exchange
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_entry_rate(void)
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
    EntryNewScreen(SCR_ID_CCONV_RATE_INPUT, mmi_cconv_exit_rate, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CCONV_RATE_INPUT);

    InitializeCategory57Screen();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_CCONV_RATE_INPUT, &inputBufferSize);       /* added for inline edit history */

    if (inputBuffer && g_cconv_ctx->isRedrawScreen == FALSE)
    {
        SetCategory57Data(wgui_inline_items, CCONV_RATE_INLINE_TOTAL, inputBuffer);     /* sets the data */
    }
    else
    {
        g_cconv_ctx->isRedrawScreen = FALSE;
    }

    mmi_cconv_rate_layout_inline_items();
    RegisterHighlightHandler(mmi_cconv_rate_item_highlight_hdlr);

    ShowCategory57Screen(
        STR_CURRENCYCONV_RATEINPUT,
        GetRootTitleIcon(EXTRA_CURRENCYCONVERTOR_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        CCONV_RATE_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        g_cconv_ctx->hiliteItemIndex,
        guiBuffer);

    DisableCategory57ScreenDone();
    SetLeftSoftkeyFunction(mmi_cconv_rate_save_change, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(mmi_cconv_rate_save_change, GoBackHistory);

    SetHighlightedItem(g_cconv_ctx->hiliteItemIndex);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_exit_rate
 * DESCRIPTION
 *  Entry Function of Compute cur exchange
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_exit_rate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;    /* added for inline edit history */
    history HistoryCCComputeCurrency;
    S16 nHistory = 0;
    S8 i;
    S8 strTemp[CCONV_SEL_BUF_LEN];
    S8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    if (g_cconv_ctx)
    {
        CloseCategory57Screen();
        if (!g_cconv_ctx->isRedrawScreen)
        {
            for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
            {
                /* Extract rate value from strings */
                if (g_cconv_ctx->selectedLocalCurID < CCONV_NAMED_CURRENCY)
                {
                    length = gui_strlen((UI_string_type) g_cconv_ctx->strRate[i]) -
                        gui_strlen((UI_string_type) curShortName[g_cconv_ctx->selectedLocalCurID]) - 1;

                    if (length < 1)
                    {
                        g_cconv_ctx->rate[i] = -1;
                    }
                    else
                    {
                        mmi_ucs2ncpy(strTemp, (S8*) g_cconv_ctx->strRate[i], length);
                        g_cconv_ctx->rate[i] = gui_atof((U16*) strTemp);
                    }
                }
                else
                {
                    if (gui_strlen((UI_string_type) g_cconv_ctx->strRate[i]) < 1)
                    {
                        g_cconv_ctx->rate[i] = -1;
                    }
                    else
                    {
                        g_cconv_ctx->rate[i] = gui_atof((U16*) g_cconv_ctx->strRate[i]);
                    }
                }
                // Remap currency selections into IDs.
                //g_cconv_ctx->curID[i] = mmi_cconv_get_cur_id(g_cconv_ctx->curIndex[i], g_cconv_ctx->curList[i]);
            }
        }
        g_cconv_ctx->reloadFromNVRAM = TRUE;
    }

    HistoryCCComputeCurrency.scrnID = SCR_ID_CCONV_RATE_INPUT;
    HistoryCCComputeCurrency.entryFuncPtr = mmi_cconv_entry_rate;
    GetCategory57History(HistoryCCComputeCurrency.guiBuffer);
    mmi_ucs2cpy((S8*) HistoryCCComputeCurrency.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();        /* added for inline edit history */
    GetCategory57Data((U8*) HistoryCCComputeCurrency.inputBuffer);     /* added for inline edit history */
    AddNHistory(HistoryCCComputeCurrency, inputBufferSize); /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_save_change
 * DESCRIPTION
 *  Save rate setting changes into NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_save_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 strTemp[CCONV_SEL_BUF_LEN];
    S8 length;
    S16 error;
    S8 i;
    U8 rateflag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        /* Extract rate value from strings */
        if (g_cconv_ctx->selectedLocalCurID < CCONV_NAMED_CURRENCY)
        {
            length = gui_strlen((UI_string_type) g_cconv_ctx->strRate[i]) -
                gui_strlen((UI_string_type) curShortName[g_cconv_ctx->selectedLocalCurID]) - 1;

            if (length < 1)
            {
                g_cconv_ctx->rate[i] = -1;
            }
            else
            {
                mmi_ucs2ncpy(strTemp, (S8*) g_cconv_ctx->strRate[i], length);
                g_cconv_ctx->rate[i] = gui_atof((U16*) strTemp);
                rateflag = 1;
            }
        }
        else
        {
            if (gui_strlen((UI_string_type) g_cconv_ctx->strRate[i]) < 1)
            {
                g_cconv_ctx->rate[i] = -1;
            }
            else
            {
                g_cconv_ctx->rate[i] = gui_atof((U16*) g_cconv_ctx->strRate[i]);
                rateflag = 1;
            }
        }
        if (!g_cconv_ctx->bRateDefined && g_cconv_ctx->rate[i] > 0)
        {
            g_cconv_ctx->bRateDefined = TRUE;
        }

        WriteValue((U8) (NVRAM_CCONV_EXCHANGE_RATE1 + i), &g_cconv_ctx->rate[i], DS_DOUBLE, &error);

        /* Remap currency selections into IDs. */
        g_cconv_ctx->curID[i] = mmi_cconv_get_cur_id(g_cconv_ctx->curIndex[i], g_cconv_ctx->curList[i]);
        WriteValue((U8) (NVRAM_CCONV_SETTING_CURRENCY1 + i), &g_cconv_ctx->curID[i], DS_BYTE, &error);
    }

    if (rateflag == 0)
    {
        g_cconv_ctx->bRateDefined = FALSE;
    }

    g_cconv_ctx->prevSelectedLocalCurID = g_cconv_ctx->selectedLocalCurID;

    WriteValue(NVRAM_CCONV_SETTING_LOCALCURRENCY, &g_cconv_ctx->selectedLocalCurID, DS_BYTE, &error);

    if (IsScreenPresent(SCR_ID_CCONV_COMPUTE))
    {
        GoBackHistory();
    }
    else
    {
        mmi_cconv_entry_app();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_item_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline items in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of highlight item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_item_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cconv_ctx->hiliteItemIndex = index;
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(mmi_cconv_return_to_menu, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_CURRENCYCONV_RATE, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_rate, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_fore_select_list
 * DESCRIPTION
 *  create selection list for foreign currency.
 * PARAMETERS
 *  void
 *  index  index of selected item.(?)
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_cconv_fore_select_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i, nItems2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, nItems2 = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (g_cconv_ctx->rate[i] > 0)
        {   /* if the rate is defined, add the correspoding cur into curList */
            if (g_cconv_ctx->curID[i] == g_cconv_ctx->localCurID)
            {
                continue;   /* skip the one selected in list 1 */
            }

            g_cconv_ctx->curList2[nItems2++] = curName[g_cconv_ctx->curID[i]];
        }
    }
    if (g_cconv_ctx->bRateDefined && g_cconv_ctx->selectedLocalCurID != g_cconv_ctx->localCurID)
    {
        g_cconv_ctx->curList2[nItems2++] = curName[g_cconv_ctx->selectedLocalCurID];
    }
    g_cconv_ctx->foreignCurIndex = mmi_cconv_get_cur_index(g_cconv_ctx->foreignCurID, g_cconv_ctx->curList2, nItems2);
    g_cconv_ctx->foreignCurID = mmi_cconv_get_cur_id(g_cconv_ctx->foreignCurIndex, g_cconv_ctx->curList2);

    return nItems2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_local_select_list
 * DESCRIPTION
 *  create selection list for local currency.
 * PARAMETERS
 *  void
 *  index  index of selected item.(?)
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_cconv_local_select_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i, nItems1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, nItems1 = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (g_cconv_ctx->rate[i] > 0)
        {                                       /* if the rate is defined, add the correspoding cur into curList */
            g_cconv_ctx->curList1[nItems1++] = curName[g_cconv_ctx->curID[i]];
            g_cconv_ctx->bRateDefined = TRUE;   /* at least one exchange rate is defined for conversion. */
        }
    }
    /* add the local cur into list as well */
    if (g_cconv_ctx->bRateDefined)
    {
        g_cconv_ctx->curList1[nItems1++] = curName[g_cconv_ctx->selectedLocalCurID];
    }
    g_cconv_ctx->localCurIndex = mmi_cconv_get_cur_index(g_cconv_ctx->localCurID, g_cconv_ctx->curList1, nItems1);
    g_cconv_ctx->localCurID = mmi_cconv_get_cur_id(g_cconv_ctx->localCurIndex, g_cconv_ctx->curList1);

    return nItems1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_local_select_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_local_select_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 nItems2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_ctx->localCurID != mmi_cconv_get_cur_id(index, g_cconv_ctx->curList1))
    {
        g_cconv_ctx->localCurID = mmi_cconv_get_cur_id(index, g_cconv_ctx->curList1);

        memset(g_cconv_ctx->LocalBuff, 0, ENCODING_LENGTH);
        memset(g_cconv_ctx->ForeBuff, 0, ENCODING_LENGTH);

		nItems2 = mmi_cconv_fore_select_list();
		change_fixed_icontext_item(
			CCONV_CURRENCY_INLINE_FORE_SELECT,
			(UI_string_type) g_cconv_ctx->curList2[g_cconv_ctx->foreignCurIndex],
			0);
		redraw_fixed_list();

    }

    g_cconv_ctx->selectedRate = mmi_cconv_get_exchange_rate(g_cconv_ctx->localCurID, g_cconv_ctx->foreignCurID);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_fore_select_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of foreign currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_fore_select_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cconv_ctx->foreignCurID = mmi_cconv_get_cur_id(index, g_cconv_ctx->curList2);
    g_cconv_ctx->selectedRate = mmi_cconv_get_exchange_rate(g_cconv_ctx->localCurID, g_cconv_ctx->foreignCurID);

    mmi_cconv_compute_result((U8*) g_cconv_ctx->LocalBuff);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_inline_edit_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline edit in compute screen. (To correct LSK function)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_inline_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(mmi_cconv_pre_entry_rate, mmi_cconv_return_to_menu);
    ChangeLeftSoftkey(STR_CURRENCYCONV_RATE, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_cconv_pre_entry_rate, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_inline_edit_validation_hdlr
 * DESCRIPTION
 *  Perform currency conversion while user is typing.
 * PARAMETERS
 *  buffer          [?]         Content of inline edit.
 *  cursor          [?]         Content after the cursor position
 *  text_length     [IN]        Content length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_inline_edit_validation_hdlr(U8 *buffer, U8 *cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2cmp((S8*) buffer, g_cconv_ctx->LocalBuff) == 0)
    {
        if (text_length == 0 && (gui_strlen((UI_string_type) g_cconv_ctx->ForeBuff) > 0))
        {
            memset(g_cconv_ctx->ForeBuff, 0, 15);
            RedrawCategoryFunction();
        }
        return;
    }
    mmi_cconv_compute_result(buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_item_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline item in exchange screen.
 * PARAMETERS
 *  index       [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_item_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cconv_ctx->hiliteItemIndex = index;
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_cconv_rate_save_change, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_local_select_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in rate screen.
 *  reset all rates and redraw the screen
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_local_select_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_ctx->prevSelectedLocalCurID != index)
    {
        for (i = 0; i < CCONV_MAX_CURRENCY; i++)
        {
            g_cconv_ctx->rate[i] = -1;
        }
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_inline_select_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of foreign currency inline selection in rate screen.
 *  update the currency id and redraw the screen
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_inline_select_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (g_cconv_ctx->curID[i] != mmi_cconv_get_cur_id(g_cconv_ctx->curIndex[i], g_cconv_ctx->curList[i]))
        {
            g_cconv_ctx->curID[i] = mmi_cconv_get_cur_id(g_cconv_ctx->curIndex[i], g_cconv_ctx->curList[i]);
            CloseCategory57Screen();
            /* mmi_cconv_rate_layout_inline_items(); */
            mmi_cconv_rate_select_list();
            RedrawCategoryFunction();
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_inline_edit_highlight_hdlr
 * DESCRIPTION
 *  Set group key handlers of inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_inline_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_cconv_rate_inline_edit_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    DisableCategory57ScreenDone();
    SetLeftSoftkeyFunction(mmi_cconv_rate_save_change, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(mmi_cconv_rate_save_change, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_inline_edit_validation_hdlr
 * DESCRIPTION
 *  Correct the cursor posiition of inline edit
 * PARAMETERS
 *  buffer          [?]         Content of inline edit.
 *  cursor          [?]         Content after the cursor position
 *  text_length     [IN]        Content length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_inline_edit_validation_hdlr(U8 *buffer, U8 *cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_cconv_ctx->selectedLocalCurID < CCONV_NAMED_CURRENCY))
    {
        return;
    }

    diff = gui_strlen((UI_string_type) curShortName[g_cconv_ctx->selectedLocalCurID]) -
        gui_strlen((UI_string_type) cursor) + 1;

    if (diff > 0)
    {
        gui_single_line_input_box_previous_steps(&MMI_inline_singleline_inputbox, diff);
    }
    else if (diff < 0)
    {
        gui_single_line_input_box_next_steps(&MMI_inline_singleline_inputbox, diff);
    }
	redraw_inline_singleline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_rate_inline_edit_key_hdlr
 * DESCRIPTION
 *  Correct the cursor posiition of inline edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_rate_inline_edit_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cconv_ctx->selectedLocalCurID < CCONV_NAMED_CURRENCY)
    {

        diff = gui_strlen((UI_string_type) curShortName[g_cconv_ctx->selectedLocalCurID]) -
            gui_strlen((UI_string_type) MMI_inline_singleline_inputbox.current_text_p) + 1;

        if (diff > 0)
        {
            gui_single_line_input_box_previous_steps(&MMI_inline_singleline_inputbox, diff);
        }
        else if (diff < 0)
        {
            inline_edit_singleline_inputbox_next_character();
            /* gui_single_line_input_box_next_steps(&MMI_inline_singleline_inputbox, diff); */
        }
    }
    else
    {
        inline_edit_singleline_inputbox_next_character();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_get_cur_id
 * DESCRIPTION
 *  Returns the id of a currency given the index in the list provided.
 * PARAMETERS
 *  index       [IN]        Index of the currency in the list.
 *  list        [IN]        A list that contains the currency.
 * RETURNS
 *  currency id.
 *****************************************************************************/
S32 mmi_cconv_get_cur_id(S32 index, S8 **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CCONV_MAX_CURRENCY; i++)
    {
        if (list[index] == curName[i])
        {
            return i;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_get_cur_index
 * DESCRIPTION
 *  Returns the index of a currency in the list provided.
 * PARAMETERS
 *  id          [IN]        Id of the currency.
 *  list        [IN]        A list that contains the currency.
 *  nItems      [IN]        Number of items in the list.
 * RETURNS
 *  currency index in the list.
 *****************************************************************************/
S32 mmi_cconv_get_cur_index(S32 id, S8 **list, S8 nItems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < nItems; i++)
    {
        if (list[i] == curName[id])
        {
            return i;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_get_exchange_rate
 * DESCRIPTION
 *  Returns predefined exchange rate by given currency id.
 * PARAMETERS
 *  currencyID1     [IN]        Id of currency 1.
 *  currencyID2     [IN]        Id of currency 2.
 * RETURNS
 *  Predefined exchange rate.
 *****************************************************************************/
DOUBLE mmi_cconv_get_exchange_rate(S32 currencyID1, S32 currencyID2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 i;
    DOUBLE rate1 = 0, rate2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (g_cconv_ctx->curID[i] == currencyID1)
        {
            rate1 = g_cconv_ctx->rate[i];
            break;
        }
    }

    for (i = 0; i < CCONV_MAX_RATEENTRIES; i++)
    {
        if (g_cconv_ctx->curID[i] == currencyID2)
        {
            rate2 = g_cconv_ctx->rate[i];
            break;
        }
    }

    if (rate2 == 0)
    {
        rate2 = 1;  /* get around with divide zero case. */
    }

    if (currencyID1 == g_cconv_ctx->selectedLocalCurID)
    {
        return 1 / rate2;
    }
    else if (currencyID2 == g_cconv_ctx->selectedLocalCurID)
    {
        return rate1;
    }
    else
    {
        return rate1 / rate2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_compute_result
 * DESCRIPTION
 *  Convert the result and display.
 * PARAMETERS
 *  buffer      [?]     A string of number for conversion.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_compute_result(U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 precision;
    DOUBLE result, conversion_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CloseCategory57Screen(); */

    if ((gui_strlen((UI_string_type) buffer) < 1))
    {
        memset(g_cconv_ctx->ForeBuff, 0, 15);
    }
    else
    {
        /* calculate result */
        conversion_factor = g_cconv_ctx->selectedRate;

        result = (DOUBLE) (conversion_factor * gui_atof((UI_string_type) buffer));

        precision = CalcComputePrecision(result, CCONV_MAX_RESULT);

        gui_float_string(result, precision, (S8*) g_cconv_ctx->ForeBuff);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cconv_return_to_menu
 * DESCRIPTION
 *  Exit application and return to menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cconv_return_to_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_EXTRA);
    /* GoBackHistory(); */
}
#endif /* __MMI_EXTENDED_CURRENCY_CONVERTER__ */ // #ifdef __MMI_EXTENDED_CURRENCY_CONVERTER__
#endif /* _MMI_CURRENCYCONVERTORE_C */ // #ifndef _MMI_CURRENCYCONVERTORE_C

