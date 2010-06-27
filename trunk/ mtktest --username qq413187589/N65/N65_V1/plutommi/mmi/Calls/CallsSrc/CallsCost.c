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
 * CallsCost.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
/**************************************************************

   FILENAME : CallsCost.c

   PURPOSE     : Call Setting Application

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru 

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALLS_COST_C
#define _CALLS_COST_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "IdleAppProt.h"
#include "wgui_status_icons.h"

#include "SettingDefs.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookTypes.h"
#include "AlarmFrameWorkProt.h"

#include "CallHistoryEnum.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "CallsCost.h"

/* micha0420 */
#include "SettingsGdcl.h"


U8 gCallCost = 0;
U16 SetTitleStrings[2];
extern InlineItem wgui_inline_items[];

/* micha0420 */
extern void SECSETGetPIN2StatusReq(void);


/*****************************************************************************
 * FUNCTION
 *  InitCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CALL_HISTORY_CALLCOST, HighlightCHISTCallCost);
    SetHiliteHandler(MENU_CALL_COST_LASTCALL, HighlightCHISTLastCost);
    SetHiliteHandler(MENU_CALL_COST_ALLCOST, HighlightCHISTAllCost);
    SetHiliteHandler(MENU_CALL_COST_PRICEUNIT, HighlightCHISTPriceAndUnit);
    SetHiliteHandler(MENU_CALL_COST_RESETCOUNTER, HighlightCHISTResetCost);
    SetHiliteHandler(MENU_CALL_COST_MAXCOUNT, HighlightCHISTMaxCost);

    SetHintHandler(MENU_CALL_COST_LASTCALL, HintCHISTLastCost);
    SetHintHandler(MENU_CALL_COST_ALLCOST, HintCHISTAllCost);
    SetHintHandler(MENU_CALL_COST_PRICEUNIT, HintCHISTPriceAndUnit);
    SetHintHandler(MENU_CALL_COST_MAXCOUNT, HintCHISTMaxCost);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallCostItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallCostItem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currCostIndex = index;

    ExecuteCurrHiliteHandler(index);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 0;
    chis_p->currCostIndex = 0;

    SetKeyHandler(CHISTGetCallCost, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(CHISTGetCallCost, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTLastCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTLastCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 0;
    chis_p->currCostIndex = (U8) GetCurrHiliteID();
    chis_p->currCostItem = MENU_CALL_COST_LASTCALL;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(0, 0);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTAllCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTAllCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 0;
    chis_p->currCostIndex = (U8) GetCurrHiliteID();
    chis_p->currCostItem = MENU_CALL_COST_ALLCOST;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(0, 0);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTResetCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTResetCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 1;
    chis_p->currCostIndex = (U8) GetCurrHiliteID();
    chis_p->currCostItem = MENU_CALL_COST_RESETCOUNTER;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    gSecuritySetupContext.VerifyPassSuccessCallBack = RspPin2ForCallCostSuccess;
    SetLeftSoftkeyFunction(SECSETGetPIN2StatusReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTMaxCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTMaxCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 1;
    chis_p->currCostIndex = (U8) GetCurrHiliteID();
    chis_p->currCostItem = MENU_CALL_COST_MAXCOUNT;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_CALL_COST_PRICEANDUNIT_VIEW_LSK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    gSecuritySetupContext.VerifyPassSuccessCallBack = RspPin2ForCallCostSuccess;
    SetLeftSoftkeyFunction(SECSETGetPIN2StatusReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTPriceAndUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTPriceAndUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallCost = 1;
    chis_p->currCostIndex = (U8) GetCurrHiliteID();
    chis_p->currCostItem = MENU_CALL_COST_PRICEUNIT;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_CALL_COST_PRICEANDUNIT_VIEW_LSK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    gSecuritySetupContext.VerifyPassSuccessCallBack = RspPin2ForCallCostSuccess;
    SetLeftSoftkeyFunction(SECSETGetPIN2StatusReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPriceAndUnitHandler
 * DESCRIPTION
 *  set inline editor LSK handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPriceAndUnitHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(SetTitleStrings[index]));
    draw_title();

    SetLeftSoftkeyFunction(CHISTValidatePriceUnit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTLastCost
 * DESCRIPTION
 *  hint handler to get last call cost
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTLastCost(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((chis_p->lastCallCost % 1000) != 0)
    {
        sprintf((S8*) value, "%u.%u", chis_p->lastCallCost / 1000, chis_p->lastCallCost % 1000);
    }
    else
    {
        sprintf((S8*) value, "%u", chis_p->lastCallCost / 1000);
    }

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTAllCost
 * DESCRIPTION
 *  hint handler to get all call cost
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTAllCost(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) value, "%u", chis_p->allCallCost);

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTMaxCost
 * DESCRIPTION
 *  hint handler to get max. call cost
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTMaxCost(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((S8*) value, "%u", chis_p->maxCallCost);

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTPriceAndUnit
 * DESCRIPTION
 *  hint handler to get price and unit
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTPriceAndUnit(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];
    U32 ppu = (U32) chis_p->ppu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->ppu - ppu == 0)
    {
        sprintf((S8*) value, "%u\0", (U32) chis_p->ppu);
    }
    else
    {
        sprintf((S8*) value, "%u.%03d\0", ppu, (U32) ((chis_p->ppu - ppu) * 1000));
    }

    if (chis_p->currencyStr[0] != 0)
    {
        strcat((S8*) value, " ");
        strcat((S8*) value, (S8*) chis_p->currencyStr);
    }

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTCallCost();
        return;
    }
    AlmDisableExpiryHandler();
    ReqGetAllCallCost();
    ReqGetLastCallCost();
    ReqGetPriceAndUnit();
    ReqGetMaxCallCost();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    // U16  nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *displayBuffer[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_CALL_COST_MAIN, NULL, CHISTGetCallCost, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALL_COST_MAIN);
    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CALL_HISTORY_CALLCOST);
    /* 4. Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU_CALL_HISTORY_CALLCOST ); */
    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CALL_HISTORY_CALLCOST, nStrItemList);
    /* 6 Set current parent id */
    SetParentHandler(MENU_CALL_HISTORY_CALLCOST);
    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(HighlightCHISTCallCostItem);
    /* 8 Display Category1 Screen */
    ConstructHintsList(MENU_CALL_HISTORY_CALLCOST, displayBuffer);

    ShowCategory52Screen(
        STR_MENU_CALL_COST_MAIN,
        IMG_SCR_CALL_COST_MAIN_CAP,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        displayBuffer,
        0,
        chis_p->currCostIndex,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* 10. Register Exit handler */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTResetCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_RESET_ACM_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("File: [%s]  Line: [%d] <<LoadAllFdlist.>\n", __FILE__, __LINE__);

    pMsgIndexReq = (MSG_MMI_CC_RESET_ACM_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_MMI_CC_RESET_ACM_REQ_STRUCT));

    memset((S8*) pMsgIndexReq->pin, 0, MAX_SIM_PASSWD_LEN);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_RESET_ACM_REQ;
    /* Message.oslSapId = 0; */
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspResetAllCallCost, PRT_MMI_CC_RESET_ACM_RES);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTSetMaxCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTSetMaxCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 maxCost[10 *ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("File: [%s]  Line: [%d] <<EntryScr104PbookNumberEdit.>\n", __FILE__, __LINE__);

    EntryNewScreen(SCR_MAX_COST_SET, ExitCHISTSetMaxCost, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MAX_COST_SET);

    ShowCategory5Screen(
        STR_MAX_COST_SET_CAPTION,
        IMG_SCR_MAX_COST_GET_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC,
        (PU8) chis_p->newMaxCostStr,
        8,
        guiBuffer);

    SetLeftSoftkeyFunction(CHISTValidateMaxCost, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTSetMaxCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTSetMaxCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_MAX_COST_SET;
    Scr.entryFuncPtr = EntryCHISTSetMaxCost;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTSetPriceUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTSetPriceUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 DetailPriceUnitImageList[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_CALL_COST_PRICEANDUNIT_SET, ExitCHISTSetPriceUnit, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALL_COST_PRICEANDUNIT_SET);

    mmi_asc_to_ucs2((S8*) chis_p->newCurrencyStr, (S8*) chis_p->currencyStr);
    mmi_asc_to_ucs2((S8*) chis_p->newPPUStr, (S8*) chis_p->PPUStr);

    /* 3 Set current parent id */
    InitializeCategory57Screen();
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[0], (PU8) chis_p->newPPUStr, 20, INPUT_TYPE_DECIMAL_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[0]);
    SetTitleStrings[0] = STR_MENU_CALL_COST_PRICEANDUNIT_SET_PRICE;
    DetailPriceUnitImageList[0] = IMG_GLOBAL_L1;
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) chis_p->newCurrencyStr,
        4,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    DisableInlineItemHighlight(&wgui_inline_items[1]);
    SetTitleStrings[1] = STR_MENU_CALL_COST_PRICEANDUNIT_SET_UNIT;
    DetailPriceUnitImageList[1] = IMG_GLOBAL_L2;

    /* added for inline edit history */
    inputBuffer = GetCurrNInputBuffer(SCR_CALL_COST_PRICEANDUNIT_SET, &inputBufferSize);

    RegisterHighlightHandler(HighlightPriceAndUnitHandler);

    /* added for inline edit history */
    if ((guiBuffer != NULL) && (guiBuffer[0] != 0))
    {
        /* sets the data */
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);
    }
    /* MTK Terry for Cannon_plus #2255 RSK */
    DisableCategory57ScreenDone();
    /* MTK end */

    ShowCategory57Screen(
        STR_MENU_SCR_CALL_COST_PRICEANDUNIT_SET,
        IMG_SCR_CALL_COST_PRICEANDUNIT_SET_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        DetailPriceUnitImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(CHISTValidatePriceUnit, CHISTGoBackCallCostHistory);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTSetPriceUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTSetPriceUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_CALL_COST_PRICEANDUNIT_SET;
    currHistory.entryFuncPtr = EntryCHISTSetPriceUnit;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);

    /* added for inline edit history */
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTSetMaxCostConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTSetMaxCostConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ReqSetMaxCallCost, KEY_EVENT_UP);
    SetRightSoftkeyFunction(CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTSetPriceUnitConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTSetPriceUnitConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ReqSetPriceAndUnit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(CHISTGoBackCallCostHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTValidateMaxCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTValidateMaxCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2strlen((S8*) chis_p->newMaxCostStr) > 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }

    EntryCHISTSetMaxCostConfirm();
}


/*****************************************************************************
 * FUNCTION
 *  CHISTValidatePriceUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTValidatePriceUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0, num = 0;
    U8 temp_ppu[40];
    BOOL is_valid_str = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    mmi_ucs2_to_asc((S8*) temp_ppu, (S8*) chis_p->newPPUStr);

    while (temp_ppu[count] != 0)
    {
        if (temp_ppu[count] <= '9' && temp_ppu[count] >= '0')
        {
            num++;
        }
        if (temp_ppu[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 9 && num > 9) || count == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }

    /* check price unit */
    for (count = 0; count < 3; count++)
    { 
        if (chis_p->newCurrencyStr[2 * count] == '\0')
        {
            break;
        }
        if((chis_p->newCurrencyStr[2*count] == '.') || (chis_p->newCurrencyStr[2*count] == ',') || 
            (chis_p->newCurrencyStr[2*count] == '-') || (chis_p->newCurrencyStr[2*count] == '?') ||
            (chis_p->newCurrencyStr[2*count] == '!') || (chis_p->newCurrencyStr[2*count] == '\'') ||
            (chis_p->newCurrencyStr[2*count] == '@') || (chis_p->newCurrencyStr[2*count] == ':') ||
            (chis_p->newCurrencyStr[2*count] == '#') || (chis_p->newCurrencyStr[2*count] == '/') ||
            (chis_p->newCurrencyStr[2*count] == '_') || 
            ((chis_p->newCurrencyStr[2*count] >= '0') && (chis_p->newCurrencyStr[2*count] <= '9')))
        {
            is_valid_str = FALSE;
            break;
        }
    }
    if (!is_valid_str)
    {
        DisplayPopup(
            (PU8) GetString(STR_ALL_CALL_COSTS_ERROR_MSG),
            IMG_GLOBAL_WARNING,
            0,
            CS_NOTIFYDURATION,
            WARNING_TONE);
    }
    else
    {
        EntryCHISTSetPriceUnitConfirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  RspPin2ForCallCostSuccess
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RspPin2ForCallCostSuccess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->currCostItem == MENU_CALL_COST_RESETCOUNTER)
    {
        EntryCHISTResetCost();
    }
    if (chis_p->currCostItem == MENU_CALL_COST_MAXCOUNT)
    {
        DisplayPopup(
            (PU8) GetString(STR_SETTING_CODE_VERIFIED),
            IMG_GLOBAL_ACTIVATED,
            1,
            CS_NOTIFYDURATION,
            SUCCESS_TONE);
        /* add screen to history, after pop up disappear will show the history screen  */
        {
            history Scr = {0};
            U8 maxCost[10 *ENCODING_LENGTH];

            Scr.scrnID = SCR_MAX_COST_SET;
            Scr.entryFuncPtr = EntryCHISTSetMaxCost;
            AddHistory(Scr);

            memset(chis_p->newMaxCostStr, 0, 10 * ENCODING_LENGTH);
            sprintf((S8*) maxCost, "%u", chis_p->maxCallCost);
            mmi_asc_to_ucs2((S8*) chis_p->newMaxCostStr, (S8*) maxCost);
        }
        DeleteUptoScrID(SCR_MAX_COST_SET);
    }
    if (chis_p->currCostItem == MENU_CALL_COST_PRICEUNIT)
    {
        DisplayPopup(
            (PU8) GetString(STR_SETTING_CODE_VERIFIED),
            IMG_GLOBAL_ACTIVATED,
            1,
            CS_NOTIFYDURATION,
            SUCCESS_TONE);
        {
            history currHistory;

            /* added for inline edit history */
            U16 inputBufferSize;
            S16 nHistory = 0;

            currHistory.scrnID = SCR_CALL_COST_PRICEANDUNIT_SET;
            currHistory.entryFuncPtr = EntryCHISTSetPriceUnit;
            mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
            mmi_ucs2cpy((S8*) currHistory.guiBuffer, (S8*) & nHistory);
            inputBufferSize = 0;    /* added for inline edit history */
            AddNHistory(currHistory, inputBufferSize);
        }
        DeleteUptoScrID(SCR_CALL_COST_PRICEANDUNIT_SET);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqGetLastCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqGetLastCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_CC_GET_CCM_REQ;
    /* msgStruct.oslSapId = 0; */
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspGetLastCallCost, PRT_MMI_CC_GET_CCM_RES);
    OslMsgSendExtQueue(&msgStruct);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspGetLastCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [?]         
 *  response(?)     [IN]        Of acm buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void RspGetLastCallCost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_GET_CCM_RSP_STRUCT *ccm_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ccm_rsp = (MSG_MMI_CC_GET_CCM_RSP_STRUCT*) info;

    if (ccm_rsp->result == TRUE)
    {
        if (ccm_rsp->ccm != 0xFFFFFF)
        {
            chis_p->lastCallCost = (U32) ccm_rsp->ccm;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqGetAllCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqGetAllCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_CC_GET_ACM_REQ;
    /* msgStruct.oslSapId = 0; */
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspGetAllCallCost, PRT_MMI_CC_GET_ACM_RES);
    OslMsgSendExtQueue(&msgStruct);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspGetAllCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info            [?]         
 *  response(?)     [IN]        Of acm buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void RspGetAllCallCost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_GET_ACM_RSP_STRUCT *acm_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acm_rsp = (MSG_MMI_CC_GET_ACM_RSP_STRUCT*) info;

    if (acm_rsp->result == TRUE)
    {
        chis_p->allCallCost = (U32) acm_rsp->acm;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqGetMaxCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqGetMaxCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_GET_MAX_ACM_REQ;
    /* Message.oslSapId = 0; */
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspGetMaxCallCost, PRT_MMI_CC_GET_MAX_ACM_RES);
    OslMsgSendExtQueue(&Message);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspGetMaxCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspGetMaxCallCost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_GET_MAX_ACM_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_MMI_CC_GET_MAX_ACM_RSP_STRUCT*) info;

    if (localPtr->result == TRUE)
    {
        chis_p->maxCallCost = localPtr->acm_max;
        EntryCHISTCallCost();
        AlmEnableExpiryHandler();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqGetPriceAndUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqGetPriceAndUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CALL_COST_PRICEUNIT_GET_REQ;
    /* Message.oslSapId = 0; */
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspGetPriceAndUnit, PRT_MMI_CALL_COST_PRICEUNIT_GET_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspGetPriceAndUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspGetPriceAndUnit(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_SMU_GET_PUC_RSP_STRUCT *localPtr;
    U32 temp_ppu;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_MMI_SMU_GET_PUC_RSP_STRUCT*) info;

    if (localPtr->result == TRUE)
    {
        chis_p->ppu = 0;
        memset(chis_p->currencyStr, 0, 4 * ENCODING_LENGTH);
        memset(chis_p->newCurrencyStr, 0, 4 * ENCODING_LENGTH);
        memset(chis_p->PPUStr, 0, 20 * ENCODING_LENGTH);
        memset(chis_p->newPPUStr, 0, 20 * ENCODING_LENGTH);

        for (i = 0; (i < 3) && (localPtr->currency[i] != 0xFF); i++)
        {
            chis_p->currencyStr[i] = localPtr->currency[i];
        }

        mmi_asc_to_ucs2((S8*) chis_p->newCurrencyStr, (S8*) chis_p->currencyStr);

        if ((localPtr->ppu[0] == '0') && (localPtr->ppu[1] == '0'))
        {
            memcpy((S8*) chis_p->PPUStr, (S8*) localPtr->ppu, 11);
            chis_p->ppu = atof((S8*) chis_p->PPUStr);
            localPtr->ppu[14] = 0;
            chis_p->ppu += atoi((S8*) localPtr->ppu + 11) / 1000.0;
        }

        temp_ppu = (U32) chis_p->ppu;
        if (chis_p->ppu - temp_ppu != 0)
        {
            /* non integer */
            sprintf((S8*) chis_p->PPUStr, "%u.%03d", temp_ppu, (U32) ((chis_p->ppu - (DOUBLE) temp_ppu) * 1000));
        }
        else
        {
            sprintf((S8*) chis_p->PPUStr, "%u\0", (U32) chis_p->ppu);
        }
        mmi_asc_to_ucs2((S8*) chis_p->newPPUStr, (S8*) chis_p->PPUStr);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspResetAllCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspResetAllCallCost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_RESET_ACM_RSP_STRUCT *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (MSG_MMI_CC_RESET_ACM_RSP_STRUCT*) info;

    if (resp->result == TRUE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }
    DeleteUptoScrID(SCR_CALL_COST_MAIN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqSetMaxCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqSetMaxCallCost(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_SET_MAX_ACM_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;
    U8 tempMaxCost[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("File: [%s]  Line: [%d] <<LoadAllFdlist.>\n", __FILE__, __LINE__);

    pMsgIndexReq = (MSG_MMI_CC_SET_MAX_ACM_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_MMI_CC_SET_MAX_ACM_REQ_STRUCT));

    memset((S8*) pMsgIndexReq->pin, 0, MAX_SIM_PASSWD_LEN);
    mmi_ucs2_to_asc((S8*) tempMaxCost, (S8*) chis_p->newMaxCostStr);
    pMsgIndexReq->val = atoi((S8*) tempMaxCost);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CC_SET_MAX_ACM_REQ;
    /* Message.oslSapId = 0; */
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(RspSetMaxCallCost, PRT_MMI_CC_SET_MAX_ACM_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspSetMaxCallCost
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspSetMaxCallCost(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_CC_SET_MAX_ACM_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_MMI_CC_SET_MAX_ACM_RSP_STRUCT*) info;

    if (localPtr->result == TRUE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }
    DeleteUptoScrID(SCR_CALL_COST_MAIN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqSetPriceAndUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqSetPriceAndUnit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_SMU_SET_PUC_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;
    U8 tempPPU[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("File: [%s]  Line: [%d] <<LoadAllFdlist.>\n", __FILE__, __LINE__);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    pMsgIndexReq = (MSG_MMI_SMU_SET_PUC_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_MMI_SMU_SET_PUC_REQ_STRUCT));

    memset((S8*) pMsgIndexReq->pin, 0, MAX_SIM_PASSWD_LEN);
    mmi_ucs2_to_asc((S8*) pMsgIndexReq->currency, (S8*) chis_p->newCurrencyStr);
    mmi_ucs2_to_asc((S8*) tempPPU, (S8*) chis_p->newPPUStr);
    CHISTConvertPPU((S8*) pMsgIndexReq->ppu, (S8*) tempPPU);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_CALL_COST_PRICEUNIT_SET_REQ;
    /* Message.oslSapId = 0; */
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(RspSetPriceAndUnit, PRT_MMI_CALL_COST_PRICEUNIT_SET_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspSetPriceAndUnit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspSetPriceAndUnit(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_MMI_SMU_SET_PUC_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_MMI_SMU_SET_PUC_RSP_STRUCT*) info;

    if (localPtr->result == TRUE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else if (localPtr->cause == 2561)   /* MMI_SIM_CMD_FAIL */
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_AVAILABLE), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }
    DeleteUptoScrID(SCR_CALL_COST_MAIN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTConvertPPU
 * DESCRIPTION
 *  convert user input price per unit to L4 format
 *  string for setting
 * PARAMETERS
 *  reqBuf          [?]     
 *  inputBuf        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTConvertPPU(S8 *reqBuf, S8 *inputBuf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0, i, num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(reqBuf, '0', 18);

    while (inputBuf[count] != 0)
    {
        if (inputBuf[count] <= '9' && inputBuf[count] >= '0')
        {
            num++;
        }
        if (inputBuf[count++] == '.')
        {
            break;
        }
    }
    /* overflow */
    if ((count > 11 && num > 11) || count == 0)
    {
        return;
    }

    if (count == num)   /* integer only */
    {
        for (i = 0; i < count; i++)
        {
            reqBuf[10 - i] = inputBuf[count - i - 1];
        }
        return;
    }

    /* save integer part */
    for (i = 0; i < count - 1; i++)
    {
        reqBuf[10 - i] = inputBuf[count - i - 2];
    }

    /* with decimal point */
    i = 0;
    while (inputBuf[count + i] != 0)
    {
        reqBuf[11 + i] = inputBuf[count + i];
        i++;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGoBackCallCostHistory
 * DESCRIPTION
 *  Getting Current Screen Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGoBackCallCostHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_CALL_COST_MAIN);
}

#endif /* _CALLS_COST_C */ 

