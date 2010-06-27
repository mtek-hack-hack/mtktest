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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   AutoRedialAttempt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
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
 * created by clearfsimport
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
 * 
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * set new maximun attempt value everytime there comes new cause. 
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
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : AutoRedialAttempt.c

   PURPOSE     : Redial attempts api

   REMARKS     : nil

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__


#include "SATGProts.h"
#include "SettingGprots.h"
#include "PhonebookTypes.h"

#include "CallmanagementIdDef.h"
#include "HistoryHelperProt.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CommonStubsProt.h"
#include "CmErrorTypes.h"
#include "CmErrorHandlersProt.h"
#include "PsCallHelperGprot.h"
#include "CallManagementGProt.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#include "CallsGProts.h"

#include "RedialHelperGprot.h"

static U8 gRedialMsgTemp[100];  /* temp array for display redial string */


/*****************************************************************************
 * FUNCTION
 *  EntryScrShowUserTimeToRedial
 * DESCRIPTION
 *  Entry Screen for user notification on time left to redial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrShowUserTimeToRedial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(CM_SCR_RDL_TIME, ExitScrShowUserTimeToRedial, NULL, NULL);

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_EntryScrShowUserTimeToRedial);

    if (GetCurrScrnId() != CM_SCR_RDL_TIME)
    {
        DeleteScreenIfPresent(CM_SCR_RDL_TIME);
    }

    ShowCategory141Screen(0, 0, 0, 0, STR_GLOBAL_ABORT, 0, gRedialMsgTemp, 0, NULL);

    SetRightSoftkeyFunction(ResetRedialAndGoBack, KEY_EVENT_UP);
    SetKeyHandler(ResetRedialAndGoBack, KEY_END, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrShowUserTimeToRedial
 * DESCRIPTION
 *  Exit Screen for blacklist full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrShowUserTimeToRedial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        return;
    }

    if (cm_p->redial_info.RedialTimer == TRUE)
    {
        history Scr1009;
        S16 nHistory = 0;

        Scr1009.scrnID = CM_SCR_RDL_TIME;
        Scr1009.entryFuncPtr = EntryScrShowUserTimeToRedial;
        mmi_ucs2cpy((S8*) Scr1009.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(Scr1009.guiBuffer);
        AddHistory(Scr1009);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetRedialAndGoBack
 * DESCRIPTION
 *  Entry Screen for user notification on time left to redial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetRedialAndGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetRedialAttempts();
    GoBackfromNotifyScr();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetRedialAttempts
 * DESCRIPTION
 *  This function resets redial counter for call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetRedialAttempts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->redial_info.MaxAttempts = 0;
    cm_p->redial_info.CurrentAttempt = 0;
    cm_p->redial_info.RedialTimer = FALSE;
    cm_p->redial_info.ErrRedialScreen = FALSE;
    cm_p->redial_info.DialFromPhb = MMI_PHB_NONE;
    memset(cm_p->redial_info.RedialNum, 0, MAX_NUMBER);
    StopTimer(CM_REDIAL_TIMER);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetMaxAttempts
 * DESCRIPTION
 *  Sets the maximum number of attempts for this call
 * PARAMETERS
 *  attempts        [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
void SetMaxAttempts(U8 attempts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cm_p->redial_info.MaxAttempts = attempts;
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetRedialNumber
 * DESCRIPTION
 *  To store number to redial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRedialNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) cm_p->redial_info.RedialNum, 0, MAX_NUMBER);
    mmi_ucs2cpy((PS8) cm_p->redial_info.RedialNum, (PS8) GetOutgoingNumber());
}


/*****************************************************************************
 * FUNCTION
 *  IsRedialSet
 * DESCRIPTION
 *  This function checks if the redial flag is set
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsRedialSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    if (GetOutgoingCallOrigin() == CM_CALL_MO_STK)
    {
        return SATCallRedialStatus();
    }
#endif /* __SAT__ */

    return AutoRedialOnOffStatus();
}


/*****************************************************************************
 * FUNCTION
 *  IsRedialNeeded
 * DESCRIPTION
 *  This function checks if the error cause needs
 *  to redial
 * PARAMETERS
 *  response        [IN]        
 *  TRUE(?)         [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsRedialNeeded(U16 response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_IsRedialNeeded);

    if ((GetTotalCallCount() == 0) || ((GetTotalCallCount() == 1) && (GetCurrentState() == CM_OUTGOING_STATE)))
    {
        switch (response)
        {
            case ERR_USER_BUSY:
            case ERR_NO_USER_RESPONDING:
            case ERR_DEST_OUT_OF_ORDER:
            case ERR_NO_ANSWER_ON_ALERT:
            case ERR_NO_CIRCUIT_CHANNEL_AVAIL:
            case ERR_TEMPORARY_FAILURE:
            case ERR_SWITCH_EQUIPMENT_CONGESTION:
            case ERR_REQUESTED_CKT_CHANEL_NOT_AVIL:
            case ERR_RESOURCE_UNAVAIL_UNSPECIFIED:
                SetMaxAttempts(10);
                result = TRUE;
                break;

            case ERR_UNASSIGNED_NUM:
            case ERR_NO_ROUTE_TO_DESTINATION:
            case ERR_NUMBER_CHANGED:
            case ERR_INVALID_NUMBER_FORMAT:
            case ERR_NETWORK_OUT_OF_ORDER:
                SetMaxAttempts(1);
                result = TRUE;
                break;

            default:
                break;
        }
    }
    if (result == FALSE)
    {
        ResetRedialAttempts();
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  CheckRedialOrShowError
 * DESCRIPTION
 *  Checks if number must be redialed or error
 *  must be shown
 * PARAMETERS
 *  response        [IN]        
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
void CheckRedialOrShowError(U16 response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_CheckRedialOrShowError);

    result = CalculateSetBackOff();
    ShowCallManagementErrorMessage(response);
    if (result == TRUE)
    SetCurrentState(GetPreviousState());
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ShowRedialScreen
 * DESCRIPTION
 *  Timer callback after notification time expires
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowRedialScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_NOTIFYDURATION_TIMER);
    cm_p->redial_info.ErrRedialScreen = FALSE;
    EntryScrShowUserTimeToRedial();
}


/*****************************************************************************
 * FUNCTION
 *  CalculateSetBackOff
 * DESCRIPTION
 *  Calculates attempt value and resets timer for redial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL CalculateSetBackOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL minFlag = FALSE;
    U8 timer, dispTimer;
    S8 temp[10], temp2[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_CalculateSetBackOff);

    cm_p->redial_info.CurrentAttempt++;

    /* exceed redial attempt */
    if (cm_p->redial_info.CurrentAttempt > cm_p->redial_info.MaxAttempts)
    {
        ResetRedialAttempts();
        return FALSE;
    }
    switch (cm_p->redial_info.CurrentAttempt)
    {
        case 1:
            timer = 7;
            dispTimer = 5;
            break;

        case 2:
        case 3:
        case 4:
            timer = 65;
            dispTimer = 1;
            minFlag = TRUE;
            break;
        default:
            timer = 190;
            dispTimer = 3;
            minFlag = TRUE;
            break;
    }

    memset(gRedialMsgTemp, 0, sizeof(gRedialMsgTemp));
    mmi_ucs2cpy((PS8) gRedialMsgTemp, GetString(STR_CM_REDIAL));

    sprintf((PS8) temp, "\n%d \0", cm_p->redial_info.CurrentAttempt);
    mmi_asc_to_ucs2((PS8) temp2, (PS8) temp);
    mmi_ucs2cat((PS8) gRedialMsgTemp, (PS8) temp2);

    mmi_ucs2cat((PS8) gRedialMsgTemp, GetString(STR_CM_REDIAL_TIMES));
    mmi_ucs2cat((PS8) gRedialMsgTemp, GetString(STR_CM_REDIAL_NEXT_ATTEMPT));

    sprintf((PS8) temp, "\n%d \0", dispTimer);
    mmi_asc_to_ucs2((PS8) temp2, (PS8) temp);
    mmi_ucs2cat((PS8) gRedialMsgTemp, (PS8) temp2);

    if (minFlag == FALSE)
    {
        mmi_ucs2cat((PS8) gRedialMsgTemp, GetString(STR_CM_REDIAL_SEC));
    }
    else
    {
        mmi_ucs2cat((PS8) gRedialMsgTemp, GetString(STR_CM_REDIAL_MIN));
    }

    cm_p->redial_info.RedialTimer = TRUE;
    StartTimer(CM_REDIAL_TIMER, (timer * 1000), (FuncPtr) RedailAttemptNoArg);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  RedailAttemptNoArg
 * DESCRIPTION
 *  Call back handler for timer expiry
 * PARAMETERS
 *  info        [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RedailAttemptNoArg(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
#ifndef __MMI_USSD_REPLY_UCS2__
    S8 TempMsgStruct[MAX_NUMBER];
#endif /* __MMI_USSD_REPLY_UCS2__ */
    PHB_CM_INTERFACE *temp;
    OUTGOING_CALL outCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_REDIAL_TIMER);
    cm_p->redial_info.RedialTimer = FALSE;

    if (IsScreenPresent(SCR1001_CM_OUTGOINGCALLSCREEN) == TRUE)
    {
        DeleteNScrId(SCR1001_CM_OUTGOINGCALLSCREEN);
    }
    DeleteScreenIfPresent(CM_SCR_RDL_TIME);
    if (IsScreenPresent(CM_SCR_MARKER) == FALSE)
    {
        AddMarkerToHistory();
    }

    SetPreviousState(CM_IDLE_STATE);
    SetCurrentState(CM_OUTGOING_STATE);

    temp = GetCMPhoneBookStruct();
    if (temp->dialInList != MMI_PHB_NONE)
    {
        cm_p->redial_info.DialFromPhb = temp->dialInList;
    }
    else if(mmi_ucs2strlen((PS8)temp->number) == 0)
    {
        PRINT_INFORMATION("Dial from CallLog");
        CHISTSetDialFromCallLogFlag(1);
    }

    index = GetFirstFreeIndex();

    AddNewCallInfo(
        (U8*) cm_p->redial_info.RedialNum,
        (CALL_STATE) GetCurrentState(),
        CM_IDLE_STATE,
        CM_CALL_MO,
        (CM_CALL_HANDLE) (index + 1),
        CM_VOICE_CALL);

#ifdef __MMI_USSD_REPLY_UCS2__
        {
            outCall.bIsUcs2 = FALSE;
            mmi_ucs2_to_asc((S8 *)outCall.Number, (PS8) cm_p->redial_info.RedialNum);
            MakePsInitiateCall((U8 *)&outCall, (void*)OutgoingCallConnected);
        }
#else
    mmi_ucs2_to_asc(TempMsgStruct, (PS8) cm_p->redial_info.RedialNum);
    MakePsInitiateCall((PU8) TempMsgStruct, (void*)OutgoingCallConnected);
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrentAttempt
 * DESCRIPTION
 *  To get flag to show redial screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetCurrentAttempt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->redial_info.CurrentAttempt;
}

#endif /* __MMI_UCM__ */