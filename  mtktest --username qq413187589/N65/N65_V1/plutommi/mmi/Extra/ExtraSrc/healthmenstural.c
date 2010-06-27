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
 * HalethMenstrual.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Menstrual application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_HEALTHMENSTRUAL_C
#define _MMI_HEALTHMENSTRUAL_C
#ifdef __MMI_MENSTRUAL__
#include "healthmenstural.h"
#include "gui_data_types.h"
#include "DateTimeGprot.h"
#include "OrganizerDef.h"
#include "wgui_calendar.h"
#include "gui.h"
#include "CalendarDef.h"
#include "CommonScreens.h"
#ifdef __MMI_CALENDAR_V2__
#include "app_datetime.h"
#include "CalendarProt.h"
#endif 

/* 
 * Define
 */
#define  MENS_ZERO_PROB_PERIOD      3
#define  MENS_OVULATION_DAYS        2
#define  MENS_PERIOD             5

#define  MENS_DAY_LEN         3*ENCODING_LENGTH
#define  MENS_MON_LEN         3*ENCODING_LENGTH
#define  MENS_YEAR_LEN        5*ENCODING_LENGTH
#define  MENS_PERIOD_LEN         3*ENCODING_LENGTH
#define  MENS_TITLE_LEN       9*ENCODING_LENGTH
#define  MENS_HORIZON_SEL_LEN       7*ENCODING_LENGTH /* "Menses" */

#define  MENS_MAX_PERIOD         99
#define  MENS_MIN_PERIOD         14
#define  MENS_NUM_PREV_MON    3 /* maximal prediction month */
#define  MENS_MAX_NAVI_MON    6 /* maximal navigation month */

/* 
 * Typedef 
 */
typedef struct
{
    MYTIME InputDate;
    S8 DayBuf[MENS_DAY_LEN];
    S8 MonBuf[MENS_MON_LEN];
    S8 YearBuf[MENS_YEAR_LEN];
    S8 PeriodBuf[MENS_PERIOD_LEN];
    S8 TitleString[MENS_TITLE_LEN];
    U16 CurrYear;
    U8 CurrMonth;
    U8 CurrDay;
    U8 NumOfMon;
    U8 AvgPeriod;
    U8 IsAddToHistory;
    U8 DayOnFirst;
    U8 DayOfMon;
#ifdef __MMI_CALENDAR_V2__
    MYTIME MensTime;
    U8 *Title;
    U8 *HorizonList[CLNDR_COLUMN];
    U8 *VerticalList[CLNDR_ROW];
    gui_calendar_cell_struct *MenstrulCell;
    /* U8 RowNumber; */
    U8 horizon_select1[MENS_HORIZON_SEL_LEN];
    U8 horizon_select2[MENS_HORIZON_SEL_LEN];
#endif /* __MMI_CALENDAR_V2__ */ 
} mens_context_struct;

/* 
 * Local Variable
 */

/* 
 * Local Function
 */
U8 MensDelScrCB(void *p);

/* 
 * Global Variable
 */
mens_context_struct *g_mens_cntx = NULL;
extern wgui_inline_item wgui_inline_items[];


/* 
 * Global Function
 */
extern void ClndrDateEditorCallBack(U8 *DateStr, U8 *day, U8 *month, U8 *year);

#define MENS_INITIALIZE


/*****************************************************************************
 * FUNCTION
 *  MensInit
 * DESCRIPTION
 *  Initialize mens app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_HEALTH_MENU_MENSTRUAL, HighlightMensApp);
}


/*****************************************************************************
 * FUNCTION
 *  MensDeInit
 * DESCRIPTION
 *  Free allocated memory for global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx)
    {
    #ifdef __MMI_CALENDAR_V2__
		if (g_mens_cntx->HorizonList[0] != NULL)
		{
			mmi_frm_scrmem_free((void*)g_mens_cntx->HorizonList[0]);
			mmi_frm_scrmem_free((void*)g_mens_cntx->VerticalList[0]);
			mmi_frm_scrmem_free((void*)g_mens_cntx->MenstrulCell);
		}
    #endif /* __MMI_CALENDAR_V2__ */ 
        OslMfree(g_mens_cntx);
        g_mens_cntx = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MensDelScrCB
 * DESCRIPTION
 *  Callback function of delete menstural screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 MensDelScrCB(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_MENS_INPUT)
    {
        CloseCategory57Screen();
    }
    MensDeInit();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightMensApp
 * DESCRIPTION
 *  Highlight handler of Menstrual menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightMensApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryMensWelcome, KEY_EVENT_UP);
    SetKeyHandler(EntryMensWelcome, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryMensWelcome
 * DESCRIPTION
 *  Display welcome screen of mens application.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMensWelcome(void)
{
#ifndef __MMI_MAINLCD_240X320__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MENS_WELCOME);

    EntryNewScreen(SCR_ID_MENS_WELCOME, NULL, EntryMensWelcome, NULL);
    ShowCategory129Screen(
        (U8*) get_string(STR_SCR_HEALTH_MENSIS_CAPTION),
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_SCR_HEALTH_MENSIS,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(MensPreEntryInput, KEY_EVENT_UP);
#else /* __MMI_MAINLCD_240X320__ */ 
    MensPreEntryInput();
#endif /* __MMI_MAINLCD_240X320__ */ 
}

#define MENS_INPUT_SCREEN


/*****************************************************************************
 * FUNCTION
 *  MensFillInlineStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[MENS_INLINE_DATE_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MENS_INLINE_DATE_CAP], (U8*) GetString(STR_LAST_DATE));

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_DATE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDate(
        &wgui_inline_items[MEMS_INLINE_DATE],
        (U8*) g_mens_cntx->DayBuf,
        (U8*) g_mens_cntx->MonBuf,
        (U8*) g_mens_cntx->YearBuf,
        ClndrDateEditorCallBack);
    RightJustifyInlineItem(&wgui_inline_items[MEMS_INLINE_DATE]);
    EnableInlineItemBoundary(&wgui_inline_items[MEMS_INLINE_DATE]);
    set_inline_date_boundary(2030, 1970, 12, 1);

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_PERIOD_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MEMS_INLINE_PERIOD_CAP], (U8*) GetString(STR_AVERAGE_DAYS_HEALTH_MENSIS));

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_PERIOD], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[MEMS_INLINE_PERIOD], (U8*) g_mens_cntx->PeriodBuf, 3, INPUT_TYPE_NUMERIC);

    RightJustifyInlineItem(&wgui_inline_items[MEMS_INLINE_PERIOD]);
    EnableInlineItemBoundary(&wgui_inline_items[MEMS_INLINE_PERIOD]);

    SetInlineItemActivation(&wgui_inline_items[MEMS_INLINE_NUM_DAYS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[MEMS_INLINE_NUM_DAYS], (U8*) GetString(STR_DATE_FORMAT_HEALTH_MENSIS));

}


/*****************************************************************************
 * FUNCTION
 *  MensPreEntryInput
 * DESCRIPTION
 *  Initialize variables for input screen and then go to input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensPreEntryInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    S8 tmpMon[MENS_MON_LEN];
    S8 tmpDay[MENS_MON_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx == NULL)
    {
        g_mens_cntx = OslMalloc(sizeof(mens_context_struct));
    }

    memset(g_mens_cntx, 0, sizeof(mens_context_struct));

    GetDateTime(&currTime);

    gui_itoa((S32) currTime.nYear, (U16*) g_mens_cntx->YearBuf, 10);

    sprintf(tmpMon, "%02d", currTime.nMonth);
    mmi_asc_to_ucs2(g_mens_cntx->MonBuf, tmpMon);

    sprintf(tmpDay, "%02d", currTime.nDay);
    mmi_asc_to_ucs2(g_mens_cntx->DayBuf, tmpDay);

    EntryMensInput();
}


/*****************************************************************************
 * FUNCTION
 *  EntryMensInput
 * DESCRIPTION
 *  Display screen to input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMensInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    U8 *inputBuffer;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MENS_INPUT, ExitMensInput, NULL, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_MENS_INPUT, (HistoryDelCBPtr) MensDelScrCB);

    InitializeCategory57Screen();

    MensFillInlineStruct();
    RegisterHighlightHandler(HighlightMensInputItem);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MENS_INPUT);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_MENS_INPUT, &inputBufferSize);

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, MEMS_INLINE_TOTAL, inputBuffer);   /* sets the data */
    }

    DisableCategory57ScreenDone();

#ifndef __MMI_MAINLCD_240X320__
    ShowCategory57Screen(
        STR_HEALTH_MENSIS_DATE_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MEMS_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory357Screen(
        STR_HEALTH_MENSIS_DATE_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_SCR_HEALTH_MENSIS,
        MEMS_INLINE_TOTAL,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);
#endif /* __MMI_MAINLCD_240X320__ */ 

    SetKeyHandler(MensDisplayResult, KEY_LSK, KEY_EVENT_UP);

    SetCategory57RightSoftkeyFunctions(MensDisplayResult, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitMensInput
 * DESCRIPTION
 *  Exit function of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMensInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    U16 inputBufferSize;    /* added for inline edit history */

    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_MENS_INPUT;
    if (g_mens_cntx)
    {
        CloseCategory57Screen();
    }
    Scr.entryFuncPtr = EntryMensInput;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */

}


/*****************************************************************************
 * FUNCTION
 *  HighlightMensInputItem
 * DESCRIPTION
 *  Highlight handler of inline item in input screen.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightMensInputItem(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(MensDisplayResult);
}

#define MENS_RESULT_SCREEN


/*****************************************************************************
 * FUNCTION
 *  MensDisplayResult
 * DESCRIPTION
 *  Display corresponding screen according to computation result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensDisplayResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    error = MensValidateInput();

    switch (error)
    {
        case MENS_ERR_DATE:
            DisplayPopup(
                (U8*) GetString(STR_HEALTH_WRONG_DATE_MSG),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            break;
        case MENS_ERR_PERIOD:
            DisplayPopup(
                (U8*) GetString(STR_INVALID_AVERAGE_DAY_MESSAGE),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            break;
        default:    /* correct */
            MensPreEntryResult();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MensValidateInput
 * DESCRIPTION
 *  Validate the correctness of user input.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 MensValidateInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmpMon[MENS_MON_LEN];
    S8 tmpDay[MENS_DAY_LEN];
    S8 tmpYear[MENS_YEAR_LEN];
    S8 AvgDays[MENS_PERIOD_LEN];
    MYTIME currTime, incTime, finalTime;
    U8 tmpPeriod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* validate period */
    mmi_ucs2_to_asc(AvgDays, g_mens_cntx->PeriodBuf);
    g_mens_cntx->AvgPeriod = tmpPeriod = (U8) atoi(AvgDays);
    if (tmpPeriod < MENS_MIN_PERIOD || tmpPeriod > MENS_MAX_PERIOD)
    {
        return MENS_ERR_PERIOD;
    }

    /* validate day */
    mmi_ucs2_to_asc(tmpDay, g_mens_cntx->DayBuf);
    mmi_ucs2_to_asc(tmpMon, g_mens_cntx->MonBuf);
    mmi_ucs2_to_asc(tmpYear, g_mens_cntx->YearBuf);

    memset(&g_mens_cntx->InputDate, 0, sizeof(MYTIME));
    g_mens_cntx->InputDate.nDay = atoi(tmpDay);
    g_mens_cntx->InputDate.nMonth = atoi(tmpMon);
    g_mens_cntx->InputDate.nYear = atoi(tmpYear);

    /* daty out of boundary */
    g_mens_cntx->DayOfMon = LastDayOfMonth(g_mens_cntx->InputDate.nMonth, g_mens_cntx->InputDate.nYear);
    if (g_mens_cntx->InputDate.nDay > g_mens_cntx->DayOfMon)
    {
        return MENS_ERR_DATE;
    }

    /* date too large */
    GetDateTime(&currTime);
    if (CompareTime(currTime, g_mens_cntx->InputDate, NULL) == TIME_LESS)
    {
        return MENS_ERR_DATE;
    }

    /* date too small */
    memset(&incTime, 0, sizeof(MYTIME));
    incTime.nMonth = MENS_NUM_PREV_MON;
    DecrementTime(currTime, incTime, &finalTime);
    if (CompareTime(g_mens_cntx->InputDate, finalTime, NULL) == TIME_LESS)
    {
        return MENS_ERR_DATE;
    }

    return MENS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  ExitMensResult
 * DESCRIPTION
 *  Exit function of calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMensResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx != NULL && g_mens_cntx->IsAddToHistory)
    {
        history Scr;    /* Variable to hold the history data */
        S16 nHistory = 0;

        Scr.scrnID = SCR_ID_MENS_RESULT;
        Scr.entryFuncPtr = EntryMensResult;
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
        if (g_mens_cntx->CurrDay > 0)
        {
            g_mens_cntx->CurrDay = g_mens_cntx->CurrDay;
        }
        AddHistory(Scr);
    }

#ifdef __MMI_CALENDAR_V2__
    /* Deinit has not been executed */
    if (g_mens_cntx != NULL)
    {
        mmi_frm_scrmem_free((void*)g_mens_cntx->HorizonList[0]);
        mmi_frm_scrmem_free((void*)g_mens_cntx->VerticalList[0]);
        mmi_frm_scrmem_free((void*)g_mens_cntx->MenstrulCell);

        g_mens_cntx->HorizonList[0] = NULL;
        g_mens_cntx->VerticalList[0] = NULL;
        g_mens_cntx->MenstrulCell = NULL;
    }
#endif /* __MMI_CALENDAR_V2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryMensResult
 * DESCRIPTION
 *  Display result calendar of computation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMensResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    S32 j;

#ifdef __MMI_CALENDAR_V2__
    S32 highlightCell;
    U8 *rsk, *lsk;
#else /* __MMI_CALENDAR_V2__ */ 
    S16 Color[31];
    S16 DiffDays;    
#endif /* __MMI_CALENDAR_V2__ */ 
    S8 tmpString[MENS_TITLE_LEN];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MENS_RESULT, ExitMensResult, NULL, NULL);

    g_mens_cntx->IsAddToHistory = TRUE;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MENS_RESULT);

    /* back ground initialize */
    g_mens_cntx->DayOnFirst = DOW((U16) g_mens_cntx->CurrYear, (U8) g_mens_cntx->CurrMonth, 1);
    g_mens_cntx->DayOfMon = LastDayOfMonth((U8) g_mens_cntx->CurrMonth, (U16) g_mens_cntx->CurrYear);
#ifdef __MMI_CALENDAR_V2__

    g_mens_cntx->HorizonList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    g_mens_cntx->VerticalList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    g_mens_cntx->MenstrulCell =
        (gui_calendar_cell_struct*) mmi_frm_scrmem_alloc((CLNDR_ROW * CLNDR_COLUMN) * CLNDR_CELL_SIZE);

    for (j = 1; j < CLNDR_COLUMN; j++)
    {
        g_mens_cntx->HorizonList[j] = g_mens_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
    }
    for (j = 1; j < CLNDR_ROW; j++)
    {
        g_mens_cntx->VerticalList[j] =
            g_mens_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
    }

    /* reset memory */
    memset(g_mens_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    memset(g_mens_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    memset(g_mens_cntx->MenstrulCell, 0, CLNDR_ROW * CLNDR_COLUMN * CLNDR_CELL_SIZE);

    /* Set Calendar info */
    g_mens_cntx->MensTime.nYear = g_mens_cntx->CurrYear;
    g_mens_cntx->MensTime.nMonth = g_mens_cntx->CurrMonth;
    g_mens_cntx->MensTime.nDay = g_mens_cntx->CurrDay;

    /* GetDateTime(&currTime); */

    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

    mmi_clndr_get_weekday(g_mens_cntx->HorizonList);

	mmi_clndr_get_week_numbers(
            g_mens_cntx->CurrYear,
            g_mens_cntx->CurrMonth,
            g_mens_cntx->VerticalList);

    mmi_mens_construct_cell_info();

    wgui_calendar_set_horizontal_string(g_mens_cntx->HorizonList, -1);
	wgui_calendar_set_select_vertical(
        NULL,
        NULL,
        NULL,
        NULL,
        g_mens_cntx->VerticalList,
        GUI_CALENDAR_SELECT_ALIGN_CELL);

    highlightCell = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;

    wgui_calendar_register_cell_highlight_handler(mmi_mens_highlight);
    wgui_calendar_register_left_arrow_key_handler(mmi_mens_left_out_of_boundary);
    wgui_calendar_register_right_arrow_key_handler(mmi_mens_right_out_of_boundary);
    wgui_calendar_register_up_arrow_key_handler(mmi_mens_up_out_of_boundary);
    wgui_calendar_register_down_arrow_key_handler(mmi_mens_down_out_of_boundary);
    wgui_calendar_register_up_side_key_handler(mmi_mens_up_side_key);
    wgui_calendar_register_down_side_key_handler(mmi_mens_down_side_key);

    mmi_mens_set_content();

    rsk = (U8*)GetString(STR_GLOBAL_BACK);
    lsk = (U8*)GetString(STR_GLOBAL_OPTIONS);
    ShowCategory83Screen(
        IMG_CALENDAR_JAN,
        (U8 **) g_mens_cntx->HorizonList,
        (gui_calendar_cell_struct*) g_mens_cntx->MenstrulCell,
        CLNDR_ROW,
        CLNDR_COLUMN,
        -1,
        -1,
        highlightCell / CLNDR_COLUMN,
        highlightCell % CLNDR_COLUMN,
        GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL,
        GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
        GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP,
        MMI_TRUE,
        lsk,
        rsk);    
    

#else /* __MMI_CALENDAR_V2__ */ 

    memset(&currTime, 0, sizeof(MYTIME));

    currTime.nMonth = (U8) g_mens_cntx->CurrMonth;
    currTime.nYear = (U16) g_mens_cntx->CurrYear;
    currTime.nDay = 1;

    InitializeCategory81Screen(
        g_mens_cntx->DayOnFirst,
        g_mens_cntx->DayOfMon,
        g_mens_cntx->CurrDay,
        g_mens_cntx->CurrMonth,
        g_mens_cntx->CurrYear);
#ifdef __MMI_SLIM_CALENDAR__
    SetCalendarBackground((U16) IMG_CALENDAR_JAN);
#else 
    SetCalendarBackground((U16) (IMG_CALENDAR_JAN + g_mens_cntx->CurrMonth - 1));
#endif 

    /* title string */
    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

    /* get/set color of days */
    DiffDays = MensGetDaysDifference(&currTime, &g_mens_cntx->InputDate);
    for (i = 1; i <= g_mens_cntx->DayOfMon; i++, DiffDays++)
    {
        Color[i] = (MensGetDisplayColor(DiffDays, g_mens_cntx->AvgPeriod));

        if (Color[i] != COLOR_NONE)
        {
            SetCalendarDay(i, (U8) (CALENDAR_SPECIAL_DAY1 + Color[i] - 1));
        }
    }

    ShowCategory81Screen(
        (U8*) g_mens_cntx->TitleString,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_CALENDER_MESSAAGE1_PP),
        (U8*) GetString(STR_CALENDER_MESSAAGE2_MENS),
        guiBuffer);

    SetCalendarMonthFunctions(MensGoToPreviousDay, MensGoToNextDay, MensGoToPreviousWeek, MensGoToNextWeek);

#ifdef __MMI_TOUCH_SCREEN__
    SetCalendarMonthChangeFunctions(MensGoToPreviousMonth, MensGoToNextMonth);
#endif 

    SetKeyHandler(MensGoToNextMonth, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(MensGoToPreviousMonth, KEY_VOL_UP, KEY_EVENT_DOWN);
#endif /* __MMI_CALENDAR_V2__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryMensProbability, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  MensPreEntryResult
 * DESCRIPTION
 *  Initialize variables and go to result screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensPreEntryResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&currTime);

    g_mens_cntx->NumOfMon = 0;
    g_mens_cntx->CurrMonth = currTime.nMonth;
    g_mens_cntx->CurrYear = currTime.nYear;
    g_mens_cntx->CurrDay = currTime.nDay;

    EntryMensResult();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightMensNevigeteDate
 * DESCRIPTION
 *  Highlight handler of calendar screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightMensNevigeteDate(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mens_cntx->CurrDay = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToPreviousDay
 * DESCRIPTION
 *  Handle left arrow key when highlighting on 1st day of month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToPreviousDay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        /* do not have to prevent 1970/01/01 because can not nevigate previous month */
        memset(&myTime, 0, sizeof(MYTIME));
        myTime.nDay = 1;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nDay = 1;
        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->NumOfMon--;
        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;
        g_mens_cntx->IsAddToHistory = FALSE;

        EntryMensResult();
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        MensDisplayBoundaryPopup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToNextDay
 * DESCRIPTION
 *  Handle right arrow key when highlighting on last day of month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToNextDay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = 1;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nMonth = 1;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->NumOfMon++;
            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->IsAddToHistory = FALSE;
            EntryMensResult();
            return;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    MensDisplayBoundaryPopup();
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToPreviousWeek
 * DESCRIPTION
 *  Handle up arrow key when highlighting on first week of the month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToPreviousWeek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        memset(&myTime, 0, sizeof(MYTIME));

        myTime.nDay = (U8) g_mens_cntx->CurrDay;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nDay = 7;

        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;

        g_mens_cntx->NumOfMon--;
        g_mens_cntx->IsAddToHistory = FALSE;

        EntryMensResult();
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        MensDisplayBoundaryPopup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToNextWeek
 * DESCRIPTION
 *  Handle down arrow key when highlighting on last week of the month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToNextWeek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = (U8) g_mens_cntx->CurrDay;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nDay = 7;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->NumOfMon++;
            g_mens_cntx->IsAddToHistory = FALSE;
            EntryMensResult();
            return;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    MensDisplayBoundaryPopup();
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToPreviousMonth
 * DESCRIPTION
 *  Side up key handler, go to the first day of previois month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToPreviousMonth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon > 0)
    {
        MYTIME myTime, incTime, finaltime;

        memset(&myTime, 0, sizeof(MYTIME));

        myTime.nDay = 1;
        myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
        myTime.nYear = (U16) g_mens_cntx->CurrYear;

        memset(&incTime, 0, sizeof(MYTIME));
        incTime.nMonth = 1;

        DecrementTime(myTime, incTime, &finaltime);

        g_mens_cntx->CurrYear = finaltime.nYear;
        g_mens_cntx->CurrMonth = finaltime.nMonth;
        g_mens_cntx->CurrDay = finaltime.nDay;
        g_mens_cntx->NumOfMon--;
        g_mens_cntx->IsAddToHistory = FALSE;

        EntryMensResult();
    }
    else
    {
        g_mens_cntx->IsAddToHistory = TRUE;
        MensDisplayBoundaryPopup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  MensGoToNextMonth
 * DESCRIPTION
 *  Side down key handler, go to the first day of next month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensGoToNextMonth()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mens_cntx->NumOfMon < MENS_MAX_NAVI_MON)
    {
        if (g_mens_cntx->CurrYear != 2030 || g_mens_cntx->CurrMonth != 12)
        {
            MYTIME myTime, incTime, finaltime;

            memset(&myTime, 0, sizeof(MYTIME));

            myTime.nDay = 1;
            myTime.nMonth = (U8) g_mens_cntx->CurrMonth;
            myTime.nYear = (U16) g_mens_cntx->CurrYear;

            memset(&incTime, 0, sizeof(MYTIME));
            incTime.nMonth = 1;
            IncrementTime(myTime, incTime, &finaltime);

            g_mens_cntx->NumOfMon++;
            g_mens_cntx->CurrYear = finaltime.nYear;
            g_mens_cntx->CurrMonth = finaltime.nMonth;
            g_mens_cntx->CurrDay = finaltime.nDay;
            g_mens_cntx->IsAddToHistory = FALSE;
            EntryMensResult();
            return;
        }
    }

    g_mens_cntx->IsAddToHistory = TRUE;
    MensDisplayBoundaryPopup();

}


/*****************************************************************************
 * FUNCTION
 *  MensDisplayBoundaryPopup
 * DESCRIPTION
 *  Display popup screen for out of boundary.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MensDisplayBoundaryPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_CANNOT_NAVIGATE_FURTHER_MESSAGE),
        IMG_GLOBAL_WARNING,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
}

#define MENS_PROBABILITY


/*****************************************************************************
 * FUNCTION
 *  MensCalcProbability
 * DESCRIPTION
 *  To calculate the probablity of ovulation.
 * PARAMETERS
 *  void
 * RETURNS
 *  probablity value
 *****************************************************************************/
S32 MensCalcProbability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT prob;
    S16 DiffDays;
    MYTIME tmpDate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&tmpDate, 0, sizeof(MYTIME));
    tmpDate.nDay = (U8) g_mens_cntx->CurrDay;
    tmpDate.nMonth = (U8) g_mens_cntx->CurrMonth;
    tmpDate.nYear = (U16) g_mens_cntx->CurrYear;

    DiffDays = MensGetDaysDifference(&tmpDate, &g_mens_cntx->InputDate);
    prob = (MensGetPregancyProb((S16) DiffDays, (S16) g_mens_cntx->AvgPeriod));

    return (S32) (prob * 100);
}


/*****************************************************************************
 * FUNCTION
 *  EntryMensProbability
 * DESCRIPTION
 *  Display probability screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMensProbability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    S32 Prob;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MENS_PROB, NULL, EntryMensProbability, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MENS_PROB);

    Prob = MensCalcProbability();

    ShowCategory72Screen(
        STR_SCR_HEALTH_MENSIS_PROBABILITY_CAPTION,
        GetRootTitleIcon(EXTRA_HEALTH_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (U8*) GetString(STR_SCR_HEALTH_MENSIS_PROBABILITY_MESSAGE),
        Prob,
        guiBuffer);

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#define MENS_UTILITY


/*****************************************************************************
 * FUNCTION
 *  MensGetPregancyProb
 * DESCRIPTION
 *  This function is to calculate probability of pregnancy.
 * PARAMETERS
 *  DiffDay         [IN]        The number of diffenent dates between given date and menstrual date
 *  AvgPeriod       [IN]        Average perviods
 * RETURNS
 *  FLOAT    the probability of pregnancy
 *****************************************************************************/
FLOAT MensGetPregancyProb(S16 DiffDay, S16 AvgPeriod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 Nth;    /* the Nth day from menstrual date */
    S16 OD;     /* the estimated ovulated date */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; DiffDay < 0; i++)
    {
        DiffDay += AvgPeriod * i;
    }

    Nth = DiffDay % AvgPeriod;

    OD = AvgPeriod / 2;

    if (Nth < MENS_ZERO_PROB_PERIOD)
    {
        return (FLOAT) 0.01;
    }
    else if (Nth <= (OD + MENS_OVULATION_DAYS) && Nth >= (OD - MENS_OVULATION_DAYS))
    {
        return (FLOAT) 0.99;
    }
    else if (Nth < AvgPeriod / 2)
    {
        return (FLOAT) Nth *2 / AvgPeriod;
    }

    else
    {
        return (2 - (FLOAT) 2 * Nth / (AvgPeriod));
    }

}


/*****************************************************************************
 * FUNCTION
 *  MensGetDisplayColor
 * DESCRIPTION
 *  This function is to calculate which color to display of a given date.
 * PARAMETERS
 *  DiffDay         [IN]        The number of diffenent dates between given date and menstrual date
 *  AvgPeriod       [IN]        Average perviods
 * RETURNS
 *  enum MENS_COLOR_EMUM the color to be display
 *****************************************************************************/
MENS_COLOR_EMUM MensGetDisplayColor(S16 DiffDay, U8 AvgPeriod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 Nth;    /* the Nth day from menstrual date */
    S16 OD;     /* the estimated ovulated date */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; DiffDay < 0; i++)
    {
        DiffDay += AvgPeriod * i;
    }

    Nth = DiffDay % AvgPeriod;

    OD = AvgPeriod / 2;

    if (Nth < MENS_PERIOD)
    {
        return RED_COLOR;
    }
    else if (Nth == OD)
    {
        return ORANGE_COLOR;
    }
    else if (Nth <= (OD + MENS_OVULATION_DAYS) && Nth >= (OD - MENS_OVULATION_DAYS))
    {
        return YELLOW_COLOR;
    }
    else
    {
        return COLOR_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  MensGetDaysDifference
 * DESCRIPTION
 *  This function is to calculate number difference days between two date.
 * PARAMETERS
 *  t1      [IN]        Date to be computed
 *  t2      [IN]        Date to be computed
 * RETURNS
 *  Difference between t1 and t2 (t1 - t2).
 *****************************************************************************/
S16 MensGetDaysDifference(MYTIME *t1, MYTIME *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Result;
    MYTIME startTime, endTime, incTime;
    U8 SignFlag;

    TIME_EQUALITY eq = CompareTime(*t1, *t2, NULL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    if (eq == TIME_LESS)    /* t1 < t2 */
    {
        startTime = *t1;
        endTime = *t2;
        SignFlag = 0;
    }
    else if (eq == TIME_GREATER)    /* t1 > t2 */
    {
        startTime = *t2;
        endTime = *t1;
        SignFlag = 1;
    }
    else    /* no difference */
    {
        return 0;
    }

    /* day */
    if (endTime.nMonth > startTime.nMonth || endTime.nYear > startTime.nYear)
    {
        Result = endTime.nDay + LastDayOfMonth(startTime.nMonth, startTime.nYear) - startTime.nDay;
        incTime.nMonth = 1;
	        
		/* Increase one month with IncrementTime() may make 3/31 to become 5/1 */
		startTime.nMonth += 1;
		if (startTime.nMonth > NUM_MONTHS)
		{
			startTime.nYear ++;	
			startTime.nMonth = 1;
		}		

        startTime.nDay = 1; /* to prevent day out of boundary */

        /* month */
        while (!(endTime.nMonth == startTime.nMonth && endTime.nYear == startTime.nYear))
        {
            Result += LastDayOfMonth(startTime.nMonth, startTime.nYear);
            IncrementTime(startTime, incTime, &startTime);
        }
    }
    else
    {
        Result = endTime.nDay - startTime.nDay;
    }

    if (SignFlag == 1)
    {
        return Result;
    }
    else
    {
        return Result * (-1);
    }
}

#ifdef __MMI_CALENDAR_V2__


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_construct_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mens_construct_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, nextMonthBoundary;
    gui_calendar_cell_struct *cell;
    MYTIME preMonth, incTime, currTime;
    U8 lastDayofPreMonth;
    S16 DiffDays;
    S16 Color[31];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preMonth, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&currTime, 0, sizeof(MYTIME));
    /* GetDateTime(&currTime); */
    currTime.nMonth = (U8) g_mens_cntx->CurrMonth;
    currTime.nYear = (U16) g_mens_cntx->CurrYear;
    currTime.nDay = 1;

    incTime.nMonth = 1;
    applib_dt_decrease_time(
        (applib_time_struct*) & currTime,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & preMonth);
    lastDayofPreMonth = applib_dt_last_day_of_mon(preMonth.nMonth, preMonth.nYear);

    cell = g_mens_cntx->MenstrulCell + (g_mens_cntx->DayOnFirst);

    /* last month */
    for (i = g_mens_cntx->DayOnFirst - 1; i >= 0; i--)
    {
        cell--;
        mmi_clndr_util_num_to_unicode(lastDayofPreMonth, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->valid = MMI_FALSE;
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        lastDayofPreMonth--;
    }

    /* this month */
    cell = g_mens_cntx->MenstrulCell + g_mens_cntx->DayOnFirst;

    DiffDays = MensGetDaysDifference(&currTime, &g_mens_cntx->InputDate);
    for (i = 1; i <= g_mens_cntx->DayOfMon; i++)
    {
        /* get/set color of days */
        Color[i] = (MensGetDisplayColor(DiffDays, g_mens_cntx->AvgPeriod));

        if (Color[i] != COLOR_NONE)
        {
            cell->bg_index = GUI_CALENDAR_COLOR_MENSTRUAL + Color[i] - 1;
        }
        else
        {
            cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        }
        mmi_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->valid = MMI_TRUE;
        cell++;
        DiffDays++;

    }

    /* next month */
    nextMonthBoundary = CLNDR_ROW * CLNDR_COLUMN - (g_mens_cntx->DayOnFirst + g_mens_cntx->DayOfMon);
    for (i = 1; i <= nextMonthBoundary; i++)
    {
        mmi_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        cell->valid = MMI_FALSE;
        cell++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_highlight(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 totaldays;
    S8 tmpString[MENS_TITLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totaldays = (row * CLNDR_COLUMN) + column + 1;
    g_mens_cntx->CurrDay = totaldays - g_mens_cntx->DayOnFirst;
    /* g_mens_cntx->CalTime.DayIndex = DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nDay); */

    sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);
    mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);

    wgui_calendar_set_normal_title((U8*) g_mens_cntx->TitleString);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_left_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_left_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME nextDate, incTime;
    S8 tmpString[MENS_TITLE_LEN];
    U32 highlightDays, highlightX, highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nextDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    nextDate.nYear = g_mens_cntx->CurrYear;
    nextDate.nMonth = g_mens_cntx->CurrMonth;
    nextDate.nDay = g_mens_cntx->CurrDay;

    incTime.nDay = 1;

    applib_dt_decrease_time(
        (applib_time_struct*) & nextDate,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & nextDate);

    if (g_mens_cntx->CurrYear == nextDate.nYear && g_mens_cntx->CurrMonth == nextDate.nMonth)
    {
        g_mens_cntx->CurrDay--;
        sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);

        highlightDays = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
        highlightX = highlightDays % CLNDR_TOTAL_WEEKDAY;
        highlightY = highlightDays / CLNDR_TOTAL_WEEKDAY;
        wgui_calendar_set_highlight(highlightY, highlightX);

        mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);
        wgui_calendar_set_normal_title((U8*) g_mens_cntx->TitleString);
    }
    else
    {
        MensGoToPreviousDay();

        /* Check if out of boundary and have a popup */
        if (g_mens_cntx->IsAddToHistory == TRUE)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_right_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_right_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME nextDate, incTime;
    S8 tmpString[MENS_TITLE_LEN];
    U32 highlightDays, highlightX, highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&nextDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    nextDate.nYear = g_mens_cntx->CurrYear;
    nextDate.nMonth = g_mens_cntx->CurrMonth;
    nextDate.nDay = g_mens_cntx->CurrDay;

    incTime.nDay = 1;

    applib_dt_increase_time(
        (applib_time_struct*) & nextDate,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & nextDate);

    if (g_mens_cntx->CurrYear == nextDate.nYear && g_mens_cntx->CurrMonth == nextDate.nMonth)
    {
        g_mens_cntx->CurrDay++;
        sprintf(tmpString, "%d %02d", (U16) g_mens_cntx->CurrYear, g_mens_cntx->CurrMonth);

        highlightDays = g_mens_cntx->DayOnFirst + g_mens_cntx->CurrDay - 1;
        highlightX = highlightDays % CLNDR_TOTAL_WEEKDAY;
        highlightY = highlightDays / CLNDR_TOTAL_WEEKDAY;
        wgui_calendar_set_highlight(highlightY, highlightX);

        mmi_asc_to_ucs2(g_mens_cntx->TitleString, tmpString);
        wgui_calendar_set_normal_title((U8*) g_mens_cntx->TitleString);
    }
    else
    {
        MensGoToNextDay();

        /* Check if out of boundary and have a popup */
        if (g_mens_cntx->IsAddToHistory == TRUE)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_up_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_up_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MensGoToPreviousWeek();
    /* Check if out of boundary and have a popup */
    if (g_mens_cntx->IsAddToHistory == TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_down_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_down_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MensGoToNextWeek();
    /* Check if out of boundary and have a popup */
    if (g_mens_cntx->IsAddToHistory == TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_up_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_up_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MensGoToPreviousMonth();
    /* Check if out of boundary and have a popup */
    if (g_mens_cntx->IsAddToHistory == TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_down_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_mens_down_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MensGoToNextMonth();
    /* Check if out of boundary and have a popup */
    if (g_mens_cntx->IsAddToHistory == TRUE)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_set_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mens_set_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mens_cntx->horizon_select1, 0, MENS_HORIZON_SEL_LEN);
    memset(g_mens_cntx->horizon_select2, 0, MENS_HORIZON_SEL_LEN);

    mmi_ucs2cpy((S8*) g_mens_cntx->horizon_select1, GetString(STR_CALENDER_MESSAAGE1_PP));
#ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__    
    mmi_ucs2cpy((S8*) g_mens_cntx->horizon_select2, GetString(STR_CALENDER_MESSAAGE2_MENS));
#else
    mmi_ucs2cpy((S8*) g_mens_cntx->horizon_select2, GetString(STR_CALENDER_MESSAAGE2_SHORT_MENS));
#endif

    wgui_calendar_set_select_horizontal1(
        IMG_HEALTH_MENSIS_PP,
        IMG_HEALTH_MENSIS_PP,
        0,
        0,
        g_mens_cntx->horizon_select1,
        GUI_CALENDAR_SELECT_ALIGN_LEFT);
    wgui_calendar_set_select_horizontal2(
        IMG_HEALTH_MENSIS_MENSES,
        IMG_HEALTH_MENSIS_MENSES,
        0,
        0,
        g_mens_cntx->horizon_select2,
        GUI_CALENDAR_SELECT_ALIGN_LEFT);
    wgui_calendar_set_normal_title((U8*) g_mens_cntx->TitleString);
    wgui_calendar_set_cell_array(
        g_mens_cntx->MenstrulCell,
        GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL,
        GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
        GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP);
}

#endif /* __MMI_CALENDAR_V2__ */ 

#endif /* __MMI_MENSTRUAL__ */ // #ifdef __MMI_MENSTRUAL__
#endif /* _MMI_HEALTHMENSTRUAL_C */ 

