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
 * CallsSMSCounter.C
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

   FILENAME : CallsSMSCounter.c

   PURPOSE     : To maintain sms counters in call history.

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALLS_SMS_COUNTER_C
#define _CALLS_SMS_COUNTER_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "CommonScreens.h"


#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookTypes.h"
#include "MessagesExDcl.h"

#include "CallHistoryEnum.h"
#include "CallsStruct.h"
#include "CallsDefs.h"
#include "CallsSMSCounter.h"


/*****************************************************************************
 * FUNCTION
 *  InitSMSCounter
 * DESCRIPTION
 *  Initialize the hilite/hint Handlers
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSMSCounter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the menu hilite handlers */
    SetHiliteHandler(MENU_CALL_HISTORY_SMSCOUNTER, HighlightCHISTSMSCount);
    SetHiliteHandler(MENU_CALL_HISTORY_SENT, HighlightCHISTSentSMS);
    SetHiliteHandler(MENU_CALL_HISTORY_RECEIVED, HighlightCHISTRecvdSMS);
    /* set the menu hint handlers */
    SetHintHandler(MENU_CALL_HISTORY_SENT, HintCHISTSentSMS);
    SetHintHandler(MENU_CALL_HISTORY_RECEIVED, HintCHISTRecvdSMS);
    /* initialize the sms counter values reading from nvram */
    InitNvramSMSCounters();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitNvramSMSCounters
 * DESCRIPTION
 *  Initialize NVRAM for SMS counters
 * PARAMETERS
 *  void
 *  S16(?)      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void InitNvramSMSCounters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Initialize the sendsms Counter by reading from NVRAM */
    ReadValue(NVRAM_SMSCOUNTERS_SENT_SHORT, &chis_p->nSendSMSCount, DS_SHORT, &error);
    /* NVRAM read failure then reset the send sms counter */
    if (chis_p->nSendSMSCount == 0xffff)
    {
        chis_p->nSendSMSCount = 0;
    }

    /* Initialize the receive sms Counter by reading from NVRAM */
    ReadValue(NVRAM_SMSCOUNTERS_RECD_SHORT, &chis_p->nRecvSMSCount, DS_SHORT, &error);
    /* NVRAM read failure then reset the receive sms counter */
    if (chis_p->nRecvSMSCount == 0xffff)
    {
        chis_p->nRecvSMSCount = 0;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSMSCount
 * DESCRIPTION
 *  To set key handlers for sms counter menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSMSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the left/right arrow key handler on sms count selected */
    SetKeyHandler(EntryCHISTSMSCount, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTSMSCount, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSentSMS
 * DESCRIPTION
 *  Funtion is called when sent sms menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSentSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the send sms counter is zero or not */
    if (chis_p->nSendSMSCount == 0)
    {
        /* Change left soft key icon and label if send sms counter is zero */
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_RESET, IMG_GLOBAL_OK);
        /* Set key handler if the send sms counter is not zero */
        SetLeftSoftkeyFunction(EntryCHISTResetSentSMSConfirm, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTRecvdSMS
 * DESCRIPTION
 *  Funtion is called when sent sms menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTRecvdSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the receive sms counter is zero or not */
    if (chis_p->nRecvSMSCount == 0)
    {
        /* Change left soft key icon and label if receive sms counter is zero */
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_RESET, IMG_GLOBAL_OK);
        /* Set key handler if the receive sms counter is not zero */
        SetLeftSoftkeyFunction(EntryCHISTResetRecvdSMSConfirm, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTSentSMS
 * DESCRIPTION
 *  To construct hint popup for sent sms counter
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTSentSMS(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    /* check send sms counter is zero or not */
    if (chis_p->nSendSMSCount == 0)
    {
        /* if zero then display No msg */
        mmi_ucs2ncpy((S8*) hintData[index], (S8*) GetString(STR_SMS_NO_NUMBER), MAX_GET_STRING_LEN);
    }
    else
    {
        /* if non zero; display the count with tag msg at the end */
        sprintf((S8*) value, "%d ", chis_p->nSendSMSCount);
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_SMS_STRING), MAX_GET_STRING_LEN);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTRecvdSMS
 * DESCRIPTION
 *  To construct hint popup for receive sms counter
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTRecvdSMS(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    /* check receive sms counter is zero or not */
    if (chis_p->nRecvSMSCount == 0)
    {
        /* if zero then display No msg */
        mmi_ucs2ncpy((S8*) hintData[index], (S8*) GetString(STR_SMS_NO_NUMBER), MAX_GET_STRING_LEN);
    }
    else
    {
        /* if non zero; display the count with tag msg at the end */
        sprintf((S8*) value, "%d ", chis_p->nRecvSMSCount);
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_SMS_STRING), MAX_GET_STRING_LEN);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTSMSCount
 * DESCRIPTION
 *  Entry function to display sms counter screen.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTSMSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    // U16                  nDispAttribute; /* Stores display attribue */
    U8 *u8SmsCount[MAX_SUB_MENUS];          /* sms counters for display hint popups */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR8004_SMS_COUNTER, ExitCHISTSMSCount, NULL, NULL);
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR8004_SMS_COUNTER);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CALL_HISTORY_SMSCOUNTER);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU_CALL_HISTORY_SMSCOUNTER ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CALL_HISTORY_SMSCOUNTER, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_CALL_HISTORY_SMSCOUNTER);
    /* Set current screen id */
    SetMessagesCurrScrnID(SCR8004_SMS_COUNTER);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    ConstructHintsList(MENU_CALL_HISTORY_SMSCOUNTER, u8SmsCount);
    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_SMS_CAPTION,
        IMG_SCR8056_CAPTION,
        STR_SMS_COUNTER_LSK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        u8SmsCount,
        0,
        0,
        guiBuffer);
    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTSMSCount
 * DESCRIPTION
 *  Exit funtion for sms counter screen.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTSMSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* getting details of the current screen (to be added to history) */
    Scr.scrnID = SCR8004_SMS_COUNTER;
    Scr.entryFuncPtr = EntryCHISTSMSCount;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    /* add the screen to history */
    AddHistory(Scr);
    SetMessagesCurrScrnID(0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTResetSentSMSConfirm
 * DESCRIPTION
 *  SMS sent counter reset confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetSentSMSConfirm(void)
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
        get_string(STR_GPRS_RESET_COUNTER_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* Set the left/right soft key funtions */
    SetLeftSoftkeyFunction(CHISTResetSentSMS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the exit handler for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTResetRecvdSMSConfirm
 * DESCRIPTION
 *  SMS receive counter reset confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetRecvdSMSConfirm(void)
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
        get_string(STR_GPRS_RESET_COUNTER_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* Set the left/right soft key funtions */
    SetLeftSoftkeyFunction(CHISTResetRecvdSMS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the exit handler for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTResetSentSMS
 * DESCRIPTION
 *  Reset the send sms counter value
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTResetSentSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the send sms counter value */
    chis_p->nSendSMSCount = 0;

    /* Update the send sms counter into NVRAM */
    WriteValue(NVRAM_SMSCOUNTERS_SENT_SHORT, &chis_p->nSendSMSCount, DS_SHORT, &error);

    /* display popup for the finish success case */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

    /* delete upto sms counter main screen to maintain screen flow */
    DeleteUptoScrID(SCR8004_SMS_COUNTER);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTResetRecvdSMS
 * DESCRIPTION
 *  Reset the receive sms counter value
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTResetRecvdSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the receive sms counter value */
    chis_p->nRecvSMSCount = 0;

    /* Update the receive sms counter into NVRAM */
    WriteValue(NVRAM_SMSCOUNTERS_RECD_SHORT, &chis_p->nRecvSMSCount, DS_SHORT, &error);

    /* display popup for the finish success case */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

    /* delete upto sms counter main screen to maintain screen flow */
    DeleteUptoScrID(SCR8004_SMS_COUNTER);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTIncSentSMS
 * DESCRIPTION
 *  Function to increment send sms counter
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTIncSentSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* increment send sms counter */
    chis_p->nSendSMSCount++;
    if (chis_p->nSendSMSCount == 0)
    {
        chis_p->nSendSMSCount = 1;
    }

    /* update the send sms counter into NVRAM */
    WriteValue(NVRAM_SMSCOUNTERS_SENT_SHORT, &chis_p->nSendSMSCount, DS_SHORT, &error);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTIncRecvdSMS
 * DESCRIPTION
 *  To Increment receive sms counter
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTIncRecvdSMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* increment send sms counter */
    chis_p->nRecvSMSCount++;
    if (chis_p->nRecvSMSCount == 0)
    {
        chis_p->nRecvSMSCount = 1;
    }

    /* update the send sms counter into NVRAM */
    WriteValue(NVRAM_SMSCOUNTERS_RECD_SHORT, &chis_p->nRecvSMSCount, DS_SHORT, &error);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTRefreshSMSCount
 * DESCRIPTION
 *  To Refresh sms counter
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTRefreshSMSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetMessagesCurrScrnID() == SCR8004_SMS_COUNTER)
    {
        S32 menuItemId = -1;
        U8 value[MAX_SUB_MENU_HINT_SIZE];

        menuItemId = GetChildMenuIDIndexByParentMenuID(MENU_CALL_HISTORY_SMSCOUNTER, MENU_CALL_HISTORY_RECEIVED);
        if (menuItemId != -1)
        {
            memset((PS8) hintData[(menuItemId)], 0, sizeof(hintData[(menuItemId)]));
            sprintf((S8*) value, "%d ", chis_p->nRecvSMSCount);
            mmi_asc_to_ucs2((PS8) hintData[(menuItemId)], (PS8) value);
            mmi_ucs2cat((PS8) hintData[(menuItemId)], (S8*) GetString(STR_SMS_STRING));
            Category52ChangeItemDescription(menuItemId, hintData[(menuItemId)]);
        }
        if (GetCurrHiliteID() == menuItemId)
        {
            ChangeLeftSoftkey(STR_SMS_COUNTER_LSK, IMG_GLOBAL_OK);
            SetLeftSoftkeyFunction(EntryCHISTResetRecvdSMSConfirm, KEY_EVENT_UP);
        }
        RedrawCategoryFunction();
    }
}

#endif /* _CALLS_SMS_COUNTER_C */ 

