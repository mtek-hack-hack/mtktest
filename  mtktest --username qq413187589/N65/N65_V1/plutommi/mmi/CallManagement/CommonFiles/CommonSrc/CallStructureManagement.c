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
 *   CallStructureManagement.c
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
 * Don't resume audio when the incoming call is in black list.
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
 * hide *31#, #31# prefix string
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
 * check length instead of check first char, in order to handle unicode character which begins with zero.
 *
 * removed!
 * removed!
 * set CallEndedBeforeConnectflag true in call back to avoid asynchronize situation
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
 * Replace isIdleScreenReached by new API
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

   FILENAME : CallStructureManagement.c

   PURPOSE     : Call Structure Management API

   REMARKS     : nil

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__


#include "WrapperGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "DateTimeGProt.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGProt.h"
#include "IdleAppDef.h"
#include "SettingGprots.h"
#include "SATGProts.h"
#include "ManageCallMain.h"
#include "SimDetectionGProt.h"
#include "ProfileGprots.h"
#include "CSP.h"

#ifdef __CTM_SUPPORT__
#include "TextPhoneDef.h"
#include "TextPhoneProt.h"
#endif /* __CTM_SUPPORT__ */ 

#include "GSM7BitDefaultAlphabet.h"

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#include "CallmanagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CallManagementGprot.h"
#include "CommonStubsProt.h"
#include "RedialHelperGProt.h"
#include "PsCallHelperDef.h"
#include "mmiapi_struct.h"
#include "PsCallHelperGprot.h"
#include "IncomingCallManagementProt.h"
#include "OutgoingCallManagementProt.h"
#include "CallsGProts.h"
#if defined(__MMI_BG_SOUND_EFFECT__)
#include "BGSoundGProt.h"
#endif


static cm_context_struct g_CallManagement_cntxt;
cm_context_struct *cm_p = &g_CallManagement_cntxt;

//static CALL_STATE gCurrentState = CM_IDLE_STATE; //to manage the current state
//static CALL_STATE gPrevState = CM_IDLE_STATE; //to manage the previous state
//static CALL_INFO gAllCalls[MAX_CALLS];
//static CALL_INFO gCallStructureForCallLog;

static CM_CALL_HANDLE gCallHandleForStartTimeUpdate;
static MYTIME gTimeStructForEndedCallStartTime;
MYTIME gTimeStructForCallDuration;

static MMI_ANSWERING_MODE gCMAnsMode;
static PHB_CM_INTERFACE gPhoneNumberStruct;
static CHLD_REQ_ACTION gChldReqSent;

//static U16 gNumofActivecalls=0;               //to store the num of active calls.
//static U16 gNumOfHoldCalls=0;         //to store the num of hold calls.
//static U16 gTotalCallCount=0;         //to store the total calls.

static U16 gCallEndCause = 0;
static U32 gCtrTime;
U32 gSumACMValue = 0;

#ifdef __MMI_CM_BLACK_LIST__
static pBOOL gBlackIncomingFlag = FALSE; /* If the incoming call is in black list*/
#endif
static pBOOL gClearKeyFlag = TRUE;
static pBOOL gIsCCCall = TRUE;
static pBOOL gCallAbortRequested = FALSE;   /* To determine whether abort call has been called once */
static pBOOL gDropRequestFlag = FALSE;
static pBOOL gCallAbortReqSentFlag = FALSE;
static pBOOL gCallEndedBeforeConnFlag = FALSE;
static pBOOL gIncomingCallDroppedFlag = FALSE;
static pBOOL gMissedCallFlag = FALSE;
static pBOOL gCallWaitFlag = FALSE;
static pBOOL gCcbsFlag = FALSE;
static pBOOL gCcbsFlagActivated = FALSE;
static pBOOL gWait2RingCallFlag = FALSE;
static pBOOL gNoTwiceRingFlag = FALSE;
static U8 gErrorToneFlag = 0;
static pBOOL gAutoAnswerFlag = FALSE;

#ifdef __MMI_CM_CCBS_SUPPORT__
CM_CALL_HANDLE gCcbsHandle = -1;
static pBOOL gDropCCBSAnswerMTFlag = FALSE;
#endif /*__MMI_CM_CCBS_SUPPORT__*/

/* Start by Julia: Drop call refinement */
static pBOOL gAutoReleaseFlag = FALSE;

/* End by Julia */
static pBOOL gCallDeflectFlag = FALSE;
static pBOOL gShowAOC = FALSE;
static pBOOL gDTMFKeyUpFlag = TRUE;
static pBOOL gCMScrnFlag = TRUE;
static pBOOL gGetTimeBeforeActive = FALSE;

static pBOOL gWapCallPresent = FALSE;
static pBOOL gPreviousWapCall = FALSE;

static pBOOL gPriority = FALSE;
static pBOOL gDialedDigitCalledFlag = FALSE;
static pBOOL gSATScrnSavedFlag = FALSE;

static pBOOL gSyncFromAT = FALSE;

#ifdef __IP_NUMBER__
static pBOOL gTempUseIPNum = FALSE;
#endif 

extern U16 gtmpOutgoingIndex;
extern U8 isCSPPresent;

/* extern U8 isIdleScreenReached; */


/*****************************************************************************
 * FUNCTION
 *  InitCallManagement
 * DESCRIPTION
 *  To Initialize the Call Management Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallManagement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitIncomingCall();
    InitOutGoingCall();
    memset (cm_p, 0, sizeof(cm_context_struct));
    ResetGlobalValues();

#ifdef __CTM_SUPPORT__
    mmi_init_ctm_call();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ReinitalizeCallManagement
 * DESCRIPTION
 *  To Re-Initialize the Call Management Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReinitalizeCallManagement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->alert_info.IsCTRStart == TRUE);
    StopTimer(CM_CTR_TIMER);

    ResetGlobalValues();
    ReinitalizeIncomingCall();
    ReinitializeOutgoingCall();
    SetCurrentState(CM_IDLE_STATE);
    SetPreviousState(CM_IDLE_STATE);
}


/*****************************************************************************
 * FUNCTION
 *  ResetGlobalValues
 * DESCRIPTION
 *  This function resets the state of all the internal
 *  call variables. This is to be called at time of exit
 *  from CM application
 * PARAMETERS
 *  void
 *  Index(?)        [OUT]       To the location where the call can be stored
 * RETURNS
 *  Index(?)
 *****************************************************************************/
void ResetGlobalValues(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CALL_INFO temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&cm_p->alert_info, 0, sizeof(cm_alert_struct));
    memset(&cm_p->redial_info, 0, sizeof(cm_redial_struct));

    /* do not reset history info, notify SS might not finish when get out of CM */

    /* keep call info for call log */
    memcpy(&temp, &cm_p->state_info.CallStructureForCallLog, sizeof(CALL_INFO));
    memset(&cm_p->state_info, 0, sizeof(cm_state_struct));
    memcpy(&cm_p->state_info.CallStructureForCallLog, &temp, sizeof(CALL_INFO));

    cm_p->alert_info.DTMF = TRUE;
    cm_p->history_info.IsSave = FALSE;
    //gNumofActivecalls=0;
    //gNumOfHoldCalls=0;
    //gTotalCallCount=0;
    //gCurrentState = CM_IDLE_STATE;
    //gPrevState = CM_IDLE_STATE;
    gSumACMValue = 0;
    InitCallInfo();
    SetShowAOC(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  DeInitCM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitCM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall())
    {
        HangupAllCalls();
    }
    if (GetCurrentAttempt() > 0)
    {
        ResetRedialAndGoBack();
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitCallInfo
 * DESCRIPTION
 *  Initializes the Call structres array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_CALLS; index++)
    {
        memset(&cm_p->state_info.AllCalls[index], 0, sizeof(CALL_INFO));
        cm_p->state_info.AllCalls[index].call_handle = -1;
    }

    cm_p->state_info.NumofActivecalls = 0;
    cm_p->state_info.NumofHeldcalls = 0;
    cm_p->state_info.TotalCallCount = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ResetCallInfo
 * DESCRIPTION
 *  Helper function to reset a particular call structure
 * PARAMETERS
 *  nCallHandle     [IN]        // Handle for call structure to reset
 *  bIsHandle       [IN]        // If the n/w has supplied a handle
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCallInfo(CM_CALL_HANDLE nCallHandle, pBOOL bIsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bIsHandle)
    {
        index = GetMMIStructIndexof(nCallHandle);
    }
    else
    {
        index = nCallHandle;
    }

    memset(&cm_p->state_info.AllCalls[index], 0, sizeof(CALL_INFO));
    cm_p->state_info.AllCalls[index].call_handle = -1;
}


/*****************************************************************************
 * FUNCTION
 *  PurgeOutgoingCallsStructure
 * DESCRIPTION
 *  Wrapper to reinitialize all outgoing calls structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PurgeOutgoingCallsStructure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_OUTGOING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            SetCallState((CM_CALL_HANDLE) count, CM_IDLE_STATE, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PurgeIncomingCallStructure
 * DESCRIPTION
 *  Wrapper to reinitialize incoming call structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PurgeIncomingCallStructure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_INCOMING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            #ifdef __MMI_CM_CCBS_SUPPORT__
                if(cm_p->state_info.AllCalls[count].call_handle != GetCCBSHandle())
            #endif /*__MMI_CM_CCBS_SUPPORT__*/
            SetCallState((CM_CALL_HANDLE) count, CM_IDLE_STATE, FALSE);
        }
    }
}

#ifdef __MMI_CM_CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  PurgeIncomingCallStructureForCCBS
 * DESCRIPTION
 *  Wrapper to reinitialize incoming call structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PurgeIncomingCallStructureForCCBS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_INCOMING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
        	if(GetCCBSHandle() == cm_p->state_info.AllCalls[count].call_handle)
        	{
	        	SetCCBSHandle(-1);
            	SetCallState((CM_CALL_HANDLE) count, CM_IDLE_STATE, FALSE);			
			}
        }
    }
}
#endif /*__MMI_CM_CCBS_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  PurgeAllCalls
 * DESCRIPTION
 *  Wrapper to reinitialize all non Idle calls structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PurgeAllCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search all non-idle calls and reset them */
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state != CM_IDLE_STATE)
        {
            SetCallState((CM_CALL_HANDLE) count, CM_IDLE_STATE, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetIncomingCallStateActive
 * DESCRIPTION
 *  Function sets the state of incoming call to active
 * PARAMETERS
 *  void
 *  MYTIME(?)       [IN]        *time time strucutre to initialize
 * RETURNS
 *  void
 *****************************************************************************/
void SetIncomingCallStateActive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* handle race condition:  
           when user answer incoming call and drop call very fast, it's possible that the answer 
           response comes later than the drop request and the call state will become 
           disconnecting, not incoming */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE &&
             cm_p->state_info.AllCalls[count].prev_state == CM_INCOMING_STATE))
        {
            #ifdef __MMI_CM_CCBS_SUPPORT__
                if(cm_p->state_info.AllCalls[count].call_handle != GetCCBSHandle())
            #endif /*__MMI_CM_CCBS_SUPPORT__*/
            SetCallState((CM_CALL_HANDLE) cm_p->state_info.AllCalls[count].call_handle, CM_ACTIVE_STATE, TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AddNewCallInfo
 * DESCRIPTION
 *  Each New Incoming or outging call is stored
 *  In the calls array with this function
 * PARAMETERS
 *  Number                  [IN]        Of the call
 *  currentstate            [IN]        Current state of call wether incoming/outgoing
 *  prevstate               [IN]        Previous state of the call
 *  MOflag                  [IN]        Whether call is coming or outgoing
 *  currentCallHandle       [IN]        Call handle of the call
 *  callType                [IN]        
 *  pBname(?)               [IN]        Name of the caller
 * RETURNS
 *  void
 *****************************************************************************/
void AddNewCallInfo(
        PU8 Number,
        CALL_STATE currentstate,
        CALL_STATE prevstate,
        CALL_DIR MOflag,
        CM_CALL_HANDLE currentCallHandle,
        U8 callType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    PHB_CM_INTERFACE phb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetFirstFreeIndex();
    PRINT_INFORMATION("*** AddNewCallInfo index=%d\n", index);

    memset(&gPhoneNumberStruct, 0, sizeof(gPhoneNumberStruct));
    memset(&cm_p->state_info.AllCalls[index], 0, sizeof(CALL_INFO));
    gPhoneNumberStruct.pictureId = IMG_PHB_DEFAULT;

    SetPreviousCallWAP(FALSE);

    cm_p->state_info.AllCalls[index].call_handle = currentCallHandle;
    cm_p->state_info.AllCalls[index].curr_state = currentstate;
    cm_p->state_info.AllCalls[index].prev_state = prevstate;
    cm_p->state_info.AllCalls[index].status_flag = 0;
    cm_p->state_info.AllCalls[index].orgination_flag = MOflag;
    cm_p->state_info.AllCalls[index].call_type = callType;

#ifdef __MMI_CH_QUICK_END__
    /* init quick end time */
    cm_p->alert_info.QuickEndTime = CHISTGetQuickEndTime();
#endif /* __MMI_CH_QUICK_END__ */ 

    if (Number[0] != '\0')
    {
        /* number existed, search phonebook if necessary */
        mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) Number);
        mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].num, (PS8) Number);

        if (CM_CALL_MT == MOflag)
        {
            /* MO call needs to wait till dial_ind to search phonebook for name
               because number might be changed by SAT */
            phb_data = mmi_phb_call_get_data_for_call_mgnt(Number, FALSE);
            mmi_ucs2cpy((PS8)phb_data.number, (PS8)Number);
            SetCMPhoneBookStruct(&phb_data);
            cm_p->state_info.AllCalls[index].name_dcs = gPhoneNumberStruct.name_dcs;
            mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, (PS8) gPhoneNumberStruct.name);
            if (!(gPhoneNumberStruct.number[0] == 0 && gPhoneNumberStruct.number[1] == 0))
            {
                mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) gPhoneNumberStruct.number);
            }

            if (MOflag == CM_CALL_MT)
            {
                CMSetupAlertForMT();
            }
        #ifdef __MMI_INCOMING_CALL_VIDEO__
            /* waiting call and ccbs invoke can't use video for display */
        #ifdef __MMI_VOIP__
            if (GetTotalCallCount() > 0 || GetCCBSFlag() == TRUE || GetCallWaitFlag() == TRUE || mmi_voip_app_total_call() != 0)
        #else
            if (GetTotalCallCount() > 0 || GetCCBSFlag() == TRUE || GetCallWaitFlag() == TRUE)
        #endif
            {
                gPhoneNumberStruct.videoId = 0;
            }
        #endif /* __MMI_INCOMING_CALL_VIDEO__ */ 

        #ifdef __MMI_CM_BLACK_LIST__
            if (IsBlackListNum(Number) == TRUE)
            {
                cm_p->state_info.AllCalls[index].block_flag = TRUE;
            }
            else
            {
                cm_p->state_info.AllCalls[index].block_flag = FALSE;
            }
        #endif /* __MMI_CM_BLACK_LIST__ */ 
            /* memcpy((PS8)cm_p->state_info.AllCalls[index].pbNumber,(PS8)gPhoneNumberStruct.number,sizeof(cm_p->state_info.AllCalls[index].pbNumber)); */
        }
    #ifdef __SAT__
        else if (MOflag == CM_CALL_MO_STK)
        {
            PS8 tmpName;
            U8 dcs;

            tmpName = (PS8) SATGetCallDisplay(&dcs);
            if (tmpName != NULL)
            {
                cm_p->state_info.AllCalls[index].name_dcs = dcs;
                mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, tmpName);
            }
            else
            {
                /* if SAT didn't provide name, search phonebook name for SAT call */
                phb_data = mmi_phb_call_get_data_for_call_mgnt(Number, FALSE);
                SetCMPhoneBookStruct(&phb_data);
                cm_p->state_info.AllCalls[index].name_dcs = gPhoneNumberStruct.name_dcs;
                mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, (PS8) gPhoneNumberStruct.name);
                if (!(gPhoneNumberStruct.number[0] == 0 && gPhoneNumberStruct.number[1] == 0))
                {
                    mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) gPhoneNumberStruct.number);
                }
            }
        }
    #endif /* __SAT__ */
        else if (CHISTGetDialFromCallLogFlag() != 0)
        {
            LOG_CALL hilite_item;

            /* dial from call log should directly use name in call log,
               no need to search phonebook */
            CHISTGetCallLogName(&hilite_item);

            cm_p->state_info.AllCalls[index].name_dcs = hilite_item.nameDCS;
            mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, (PS8) hilite_item.pbName);
            /* memcpy((PS8)cm_p->state_info.AllCalls[index].pbNumber,(PS8)cm_p->state_info.AllCalls[index].number,sizeof(cm_p->state_info.AllCalls[index].pbNumber)); */
        }
    }
    else
    {
        mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, (PS8) GetString(STR_UNKNOWN_CALLER));
        cm_p->state_info.AllCalls[index].name_dcs = MMI_PHB_UCS2;
    }

    cm_p->state_info.TotalCallCount++;
    mmi_frm_kbd_set_tone_state(MMI_KEY_VOL_TONE_DISABLED);

}


/*****************************************************************************
 * FUNCTION
 *  SetCallState
 * DESCRIPTION
 *  Sets the call state of a particular call
 *  
 *  This function updates all those variables which are
 *  required for managing the calls like number of hold calls
 *  number of active calls etc.
 * PARAMETERS
 *  nCallHandle     [IN]        // Handle for call structure for which flag is to be set
 *  state           [IN]        // State to set
 *  bIsHandle       [IN]        // If the n/w has supplied a handle
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallState(CM_CALL_HANDLE nCallHandle, CALL_STATE state, pBOOL bIsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bIsHandle)
    {
        index = GetMMIStructIndexof(nCallHandle);
    }
    else
    {
        index = nCallHandle;
    }
    /* Start by Julia: Drop call refinement */
    if (cm_p->state_info.AllCalls[index].curr_state != CM_DISCONNECTING_STATE)
        /* End by Julia */
    {
        cm_p->state_info.AllCalls[index].prev_state = cm_p->state_info.AllCalls[index].curr_state;
    }
    cm_p->state_info.AllCalls[index].curr_state = state;

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_SetCallState, state, cm_p->state_info.AllCalls[index].call_handle);

    if (cm_p->state_info.AllCalls[index].curr_state == CM_ACTIVE_STATE)
    {
        /* one call becomes active: incoming, outoing, hold -> active */
        cm_p->state_info.NumofActivecalls++;
        if (cm_p->state_info.AllCalls[index].prev_state == CM_INCOMING_STATE)
        {
            DeleteScreenIfPresent(ITEMSCR_INCOMING_CALL);
        #if defined(__MMI_BG_SOUND_EFFECT__)
            mmi_bgsnd_mt_play_sound();
        #endif 
        }
        if (cm_p->state_info.AllCalls[index].prev_state == CM_HOLD_STATE)
        {
            cm_p->state_info.NumofHeldcalls--;
        }
    #if defined(__MMI_BG_SOUND_EFFECT__)
        if (cm_p->state_info.AllCalls[index].prev_state == CM_OUTGOING_STATE &&
            (cm_p->state_info.AllCalls[index].call_type == CSMCC_VOICE_CALL ||
             cm_p->state_info.AllCalls[index].call_type == CSMCC_AUX_VOICE_CALL))
        {
            mmi_bgsnd_mo_play_sound();
        }
    #endif /* defined(__MMI_BG_SOUND_EFFECT__) */ 
    }

    if (cm_p->state_info.AllCalls[index].curr_state == CM_HOLD_STATE)
    {
        /* one call becomes hold: active -> hold */
        cm_p->state_info.NumofHeldcalls++;
        if (cm_p->state_info.AllCalls[index].prev_state == CM_ACTIVE_STATE)
        {
            cm_p->state_info.NumofActivecalls--;
        }
    }

    if (cm_p->state_info.AllCalls[index].curr_state == CM_IDLE_STATE)
    {
        if (cm_p->state_info.AllCalls[index].prev_state == CM_ACTIVE_STATE)
        {
            /* one active call ends */
            cm_p->state_info.NumofActivecalls--;
            if (GetWapCallPresent())
            {
                /* there can be only one active call when wap call present,
                   => the active call is wap call */
                SetWapCallPresent(FALSE);
                SetPreviousCallWAP(TRUE);
            }
        }
        if (cm_p->state_info.AllCalls[index].prev_state == CM_HOLD_STATE)
        {
            /* one hold call ends */
            cm_p->state_info.NumofHeldcalls--;
        }

        if (cm_p->state_info.AllCalls[index].prev_state == CM_OUTGOING_STATE)
        {
            if (GetTotalCallCount() > 1)
            {
                SyncCallList();
            }
            SetSpeechFlag(FALSE);
            /* one outgoing call ends */
            SetCallEndedBeforeConnFlag(TRUE);
            /* where to log call? */
            DeleteScreenIfPresent(SCR1001_CM_OUTGOINGCALLSCREEN);
        }
        if (cm_p->state_info.AllCalls[index].prev_state == CM_INCOMING_STATE)
        {
            /* MT call drop when WAP call present, can resume audio */
            if (GetWapCallPresent())
            {
        #ifdef __MMI_CM_BLACK_LIST__
            	if(GetBlackIncomingFlag() == FALSE)
            	{
        #endif /* __MMI_CM_BLACK_LIST__ */ 
                mdi_audio_resume_background_play();
        #ifdef __MMI_CM_BLACK_LIST__
                }
        #endif /* __MMI_CM_BLACK_LIST__ */
            }
            if (GetTotalCallCount() > 1)
            {
                SyncCallList();
            }
        #ifdef __MMI_CM_BLACK_LIST__
            /* do not log the number that has been blocked */
            if (GetBlackListMode() == TRUE && cm_p->state_info.AllCalls[index].block_flag == TRUE)
            {
				if (GetTotalCallCount() > 1)  /*Now, it is able to resume audio.   by Mick*/
				{
					SetBlackIncomingFlag(FALSE);
				}
                ResetCallInfo(index, FALSE);
                cm_p->state_info.TotalCallCount--;
                AdjustHistoryForCM();
                return;
            }
            else
        #endif /* __MMI_CM_BLACK_LIST__ */ 
            {
                /* one incoming call ends */
                GetEndTimeAndNotifyCallMissed();
                DeleteScreenIfPresent(ITEMSCR_INCOMING_CALL);
            }
        }
        /* incoming call exist after call end => it was a waiting call */
        if (GetIncomingCallHandle() != -1 && 
        	cm_p->state_info.AllCalls[index].prev_state != CM_OUTGOING_STATE)
        {
            SetCallWaitFlag(TRUE);
        }

        ResetCallInfo(index, FALSE);
        cm_p->state_info.TotalCallCount--;

    #ifdef __MMI_BT_PROFILE__
    #ifdef __MMI_VOIP__
        /* no gsm and no voip call, or only data call exists */
        if (((GetTotalCallCount() == 0) && (mmi_voip_app_total_call() == 0)) ||
            ((GetTotalCallCount() > 0) && (GetActiveCallType() != CSMCC_VOICE_CALL) && (GetActiveCallType() != CSMCC_AUX_VOICE_CALL)))
        {
            PRINT_INFORMATION("\n[SetCallState] SCO Ends\n");
            mmi_profiles_bt_call_end_callback();
        }
    #else
        /* following cases shall callback API for bluetooth outband ring, mmi_profiles_bt_call_end_callback. */
        /* 1. only one incoming call */
        if ((GetTotalCallCount() == 1 && GetCurrentState() == CM_INCOMING_STATE))
        {
            mmi_profiles_bt_call_end_callback();
        }
        /* 2. no any voice call */
        else if ((GetTotalCallCount() == 0) ||
                 (GetTotalCallCount() > 0 &&
                  (GetActiveCallType() != CSMCC_VOICE_CALL && GetActiveCallType() != CSMCC_AUX_VOICE_CALL)))
        {
            mmi_profiles_bt_call_end_callback();
        }
    #endif /* __MMI_VOIP__ */
    #endif /* __MMI_BT_PROFILE__ */ 

    }

}

/* Start by Julia: Drop call refinement */


/*****************************************************************************
 * FUNCTION
 *  SetAllCallState
 * DESCRIPTION
 *  Sets the call state of all calls
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  state       [IN]        // State to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllCallState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE))
        {
            cm_p->state_info.AllCalls[count].prev_state = cm_p->state_info.AllCalls[count].curr_state;
            cm_p->state_info.AllCalls[count].curr_state = state;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllExceptWaitingCallState
 * DESCRIPTION
 *  Sets the call state of all calls
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  state       [IN]        // State to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllExceptWaitingCallState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE))
        {
            cm_p->state_info.AllCalls[count].prev_state = cm_p->state_info.AllCalls[count].curr_state;
            cm_p->state_info.AllCalls[count].curr_state = state;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllActiveCallState
 * DESCRIPTION
 *  Sets the call state of all active calls
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  state       [IN]        // State to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllActiveCallState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            cm_p->state_info.AllCalls[count].prev_state = CM_ACTIVE_STATE;
            cm_p->state_info.AllCalls[count].curr_state = state;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllHeldCallState
 * DESCRIPTION
 *  Sets the call state of all held calls
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  state       [IN]        // State to set
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllHeldCallState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
        {
            cm_p->state_info.AllCalls[count].prev_state = CM_HOLD_STATE;
            cm_p->state_info.AllCalls[count].curr_state = state;
        }
    }
}

/* End by Julia */


/*****************************************************************************
 * FUNCTION
 *  GetCallState
 * DESCRIPTION
 *  Gets state for a particular call handle
 * PARAMETERS
 *  handle          [IN]        
 *  state(?)        [OUT]       Of call
 * RETURNS
 *  CM_CALL_STATE
 *****************************************************************************/
CALL_STATE GetCallState(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_handle == handle)
        {
            /* Start by Julia: Drop call refinement */
            if (cm_p->state_info.AllCalls[count].curr_state != CM_DISCONNECTING_STATE)
            {
                return cm_p->state_info.AllCalls[count].curr_state;
            }
            else
            {
                return cm_p->state_info.AllCalls[count].prev_state;
            }
            /* End by Julia */
        }
    }
    return CM_STATE_UNKNOWN;
}

/*****************************************************************************
 * FUNCTION
 *  RestoreCallState
 * DESCRIPTION
 *  Gets state for a particular call handle
 * PARAMETERS
 *  handle          [IN]        
 *  state(?)        [OUT]       Of call
 * RETURNS
 *  CM_CALL_STATE
 *****************************************************************************/
void RestoreCallState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE)
        {
            cm_p->state_info.AllCalls[count].curr_state = cm_p->state_info.AllCalls[count].prev_state;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SyncCallList
 * DESCRIPTION
 *  Syncs Call List with L4
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SyncCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MakePsGetCallList((void*)PsCbackSyncCallList);
}


/*****************************************************************************
 * FUNCTION
 *  PsCbackSyncCallList
 * DESCRIPTION
 *  Call back Called after Call List synced
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCbackSyncCallList(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CALL_LIST_RSP *callRsp;
    MMI_CALL_LIST *callList;
    U8 count;
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callRsp = (MMI_CALL_LIST_RSP*) MsgStruct;

    if (callRsp->result == KAL_TRUE)
    {
        callList = (MMI_CALL_LIST*) & callRsp->call_list;

        for (count = 0; (count < callList->length) && (callList->list[count].call_id != 0); count++)
        {
            index = GetMMIStructIndexof(callList->list[count].call_id);

            if (index != -1)
            {
                switch (callList->list[count].call_state)
                {
                    case CLCC_CALL_ACTIVE:
                    {
                        if (GetSyncCallFromATFlag() == TRUE &&
                            cm_p->state_info.AllCalls[index].curr_state == CM_INCOMING_STATE)
                        {
                            SetCallHandleForStartTimeUpdate(GetIncomingCallHandle());
                        }
                        cm_p->state_info.AllCalls[index].curr_state = CM_ACTIVE_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListActive);
                        break;
                    }
                    case CLCC_CALL_HELD:
                    {
                        cm_p->state_info.AllCalls[index].curr_state = CM_HOLD_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListHeld);
                        break;
                    }
                    case CLCC_CALL_DIALING:
                    {
                        cm_p->state_info.AllCalls[index].curr_state = CM_OUTGOING_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListOutgoing);
                        break;
                    }
                    case CLCC_CALL_ALERTING:
                    {
                        cm_p->state_info.AllCalls[index].curr_state = CM_OUTGOING_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListOutgoing);
                        break;
                    }
                    case CLCC_CALL_INCOMING:
                    {
                        cm_p->state_info.AllCalls[index].curr_state = CM_INCOMING_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListIncoming);
                        break;
                    }
                    case CLCC_CALL_WAITING:
                    {
                        cm_p->state_info.AllCalls[index].curr_state = CM_INCOMING_STATE;
                        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListIncoming);
                        break;
                    }
                }   /* End of Switch */

            }   /* End of if */
            else
            {
                MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_ERROR_CallList);
                SetSyncCallFromATFlag(FALSE);
                return;
            }
        }   /* End of for */

        if ((0 == (callList->length))&&(GetCCBSFlag()==FALSE)) /*Mick: CCBS should remain there*/
        {
            PurgeAllCalls();
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CallListEmpty);
        }
    }   /* End of if */
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_ERROR_CallListFail);
        SetSyncCallFromATFlag(FALSE);
        return;
    }

    UpdateStateMachine();
    UpdateActiveCallScrnIfPresent();
}


/*****************************************************************************
 * FUNCTION
 *  UpdateStateMachine
 * DESCRIPTION
 *  Updates State Machine of CM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateStateMachine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NumofActivecalls = 0;
    U16 NumOfHoldCalls = 0;
    U16 TotalCallCount = 0;
    U16 count;
    U8 OutgoingFlag = 0;
    U8 IncomingFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_UpdateStateMachine);

    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_handle == -1)
        {
            continue;
        }
        switch (cm_p->state_info.AllCalls[count].curr_state)
        {
            case CM_OUTGOING_STATE:
            {
                OutgoingFlag = 1;
                TotalCallCount++;
                break;
            }
            case CM_INCOMING_STATE:
            {
                IncomingFlag = 1;
                TotalCallCount++;
                break;
            }
            case CM_ACTIVE_STATE:
            {
                NumofActivecalls++;
                TotalCallCount++;
                break;
            }
            case CM_HOLD_STATE:
            {
                NumOfHoldCalls++;
                TotalCallCount++;
                break;
            }
        }

    }
    cm_p->state_info.NumofActivecalls = (U8) NumofActivecalls;
    cm_p->state_info.NumofHeldcalls = (U8) NumOfHoldCalls;
    cm_p->state_info.TotalCallCount = (U8) TotalCallCount;
    if (OutgoingFlag)
    {
        if (GetCurrentState() != CM_OUTGOING_STATE)
        {
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_OUTGOING_STATE);
        }
        return;
    }
    if (IncomingFlag)
    {
        if (GetCurrentState() != CM_INCOMING_STATE)
        {
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_INCOMING_STATE);
        }
        return;
    }
    if ((cm_p->state_info.NumofHeldcalls == cm_p->state_info.TotalCallCount) && (cm_p->state_info.TotalCallCount != 0))
    {
        if (GetCurrentState() != CM_HOLD_STATE)
        {
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_HOLD_STATE);
        }
        return;
    }
    if (cm_p->state_info.NumofActivecalls > 0)
    {
        if (GetCurrentState() != CM_ACTIVE_STATE)
        {
            SetPreviousState(GetCurrentState());
            SetCurrentState(CM_ACTIVE_STATE);
        }
        return;
    }
    if (TotalCallCount == 0)
    {
        SetPreviousState(GetCurrentState());
        SetCurrentState(CM_IDLE_STATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetHoldFlag
 * DESCRIPTION
 *  This function is a wrapper to set state of the hold requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetHoldFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            SetCallflag(count, CM_HOLD_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetHoldFlag
 * DESCRIPTION
 *  This function is a wrapper to set state of the hold requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetHoldFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            ResetCallflag(count, CM_HOLD_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetRetrieveFlag
 * DESCRIPTION
 *  This function is a wrapper to set retrieve requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRetrieveFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
        {
            SetCallflag(count, CM_RETRIEVE_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetRetrieveFlag
 * DESCRIPTION
 *  This function is a wrapper to set retrieve requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetRetrieveFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
        {
            ResetCallflag(count, CM_RETRIEVE_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetAllCallFlags
 * DESCRIPTION
 *  This function is a wrapper to set swap requested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetAllCallFlags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count, flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_handle != -1)
        {
            flag |= cm_p->state_info.AllCalls[count].status_flag;
        }
    }
    PRINT_INFORMATION("GetAllCallFlags: %d\n", flag);
    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  SetSwapFlag
 * DESCRIPTION
 *  This function is a wrapper to set swap requested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetSwapFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE))
        {
            SetCallflag(count, CM_SWAP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetSwapFlag
 * DESCRIPTION
 *  This function is a wrapper to set swap requested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSwapFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE))
        {
            ResetCallflag(count, CM_SWAP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetConfFlag
 * DESCRIPTION
 *  This function is a wrapper to set conference requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetConfFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE))
        {
            SetCallflag(count, CM_CONF_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetConfFlag
 * DESCRIPTION
 *  This function is a wrapper to set conference requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetConfFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE))
        {
            ResetCallflag(count, CM_CONF_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetSplitFlag
 * DESCRIPTION
 *  This function is a wrapper to set split requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSplitFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].status_flag & CM_SPLIT_REQUESTED) != 0)
        {
            ResetCallflag(count, CM_SPLIT_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetEctFlag
 * DESCRIPTION
 *  This function is a wrapper to set split requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetEctFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].status_flag & CM_ECT_REQUESTED) != 0)
        {
            ResetCallflag(count, CM_ECT_REQUESTED, FALSE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetAllHangupFlag
 * DESCRIPTION
 *  This function is a wrapper to set hangup all requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllHangupFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release all except waiting */
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE) ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE))
        {
            SetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllCallsHangupFlag
 * DESCRIPTION
 *  This function is a wrapper to set hangup all requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllCallsHangupFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hang up all including waiting or incoming calls */
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state != CM_IDLE_STATE)
        {
            SetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllActHangupFlag
 * DESCRIPTION
 *  This function is a wrapper to set hangup request for all active call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllActHangupFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            SetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetAllHldHangupFlag
 * DESCRIPTION
 *  This function is a wrapper to set hangup request for all held calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetAllHldHangupFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
        {
            SetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetAllHangupFlag
 * DESCRIPTION
 *  This function is a wrapper to set hangup all requested flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetAllHangupFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].status_flag & CM_HANGUP_REQUESTED) != 0)
        {
            ResetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckAllCallflag
 * DESCRIPTION
 *  This function is a wrapper to check all call flags
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL CheckAllCallflag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = CM_HOLD_REQUESTED | CM_RETRIEVE_REQUESTED | CM_SPLIT_REQUESTED;

    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].status_flag & flag) != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetChldReqSent
 * DESCRIPTION
 *  Helper function to get the
 *  action for which CHLD req was sent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CHLD_REQ_ACTION GetChldReqSent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gChldReqSent;
}


/*****************************************************************************
 * FUNCTION
 *  SetChldReqSent
 * DESCRIPTION
 *  Helper function to set the action for which
 *  CHLD req has been sent
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetChldReqSent(CHLD_REQ_ACTION action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("SetChldReqSent: %d\n", action);
    gChldReqSent = action;
}


/*****************************************************************************
 * FUNCTION
 *  MakeHold
 * DESCRIPTION
 *  This function is a wrapper to hold all active calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeHold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, totalHeld = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakeHold);
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            ResetCallflag(count, CM_HOLD_REQUESTED, FALSE);
            SetCallState(count, CM_HOLD_STATE, FALSE);
            totalHeld++;
        }
    }

    if (totalHeld > 0 && GetTotalCallCount() == totalHeld)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_MakeHoldSet);
        SetPreviousState(GetCurrentState());
        SetCurrentState(CM_HOLD_STATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeRetrieve
 * DESCRIPTION
 *  This function is a wrapper to retrieve all held calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeRetrieve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, totalActive = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakeRetrieve);
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
        {
            ResetCallflag(count, CM_RETRIEVE_REQUESTED, FALSE);
            SetCallState(count, CM_ACTIVE_STATE, FALSE);
        }
    }

    if (totalActive > 0 && GetTotalCallCount() == totalActive)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_MakeRetrieveSet);
        SetPreviousState(GetCurrentState());
        SetCurrentState(CM_ACTIVE_STATE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeSwap
 * DESCRIPTION
 *  This function is a wrapper to swap  all held and active calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeSwap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count, totalHeld = 0, totalActive = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakeSwap);
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].status_flag & CM_SWAP_REQUESTED)
        {
            if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
            {
                ResetCallflag(count, CM_SWAP_REQUESTED, FALSE);
                SetCallState(count, CM_ACTIVE_STATE, FALSE);
                totalActive++;
            }
            else if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
            {
                ResetCallflag(count, CM_SWAP_REQUESTED, FALSE);
                SetCallState(count, CM_HOLD_STATE, FALSE);
                totalHeld++;
            }
        }
    }
    if (totalHeld > 0 && GetTotalCallCount() == totalHeld)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_MakeSwapSetHeld);
        SetPreviousState(GetCurrentState());
        SetCurrentState(CM_HOLD_STATE);
    }
    else if (totalActive > 0 && GetTotalCallCount() == totalActive)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_MakeSwapSetActive);
        SetPreviousState(GetCurrentState());
        SetCurrentState(CM_ACTIVE_STATE);
    }
    else if (GetCurrentState() == CM_INCOMING_STATE)
    {
        if (totalActive == 0 && totalHeld > 0)
        {
            SetPreviousState(CM_HOLD_STATE);
        }
        else if (totalHeld == 0 && totalActive > 0)
        {
            SetPreviousState(CM_ACTIVE_STATE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeConf
 * DESCRIPTION
 *  This function is a wrapper to conference all held and active calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeConf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakeConf);
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].status_flag & CM_CONF_REQUESTED)
        {
            ResetCallflag(count, CM_CONF_REQUESTED, FALSE);
            if (cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE)
            {
                /* conference makes held -> active, active remains active */
                SetCallState(count, CM_ACTIVE_STATE, FALSE);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeAllActHangup
 * DESCRIPTION
 *  This function is a wrapper to hangup all active calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeAllActHangup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].status_flag & CM_HANGUP_REQUESTED)
        {
            ResetCallflag(count, CM_HANGUP_REQUESTED, FALSE);
            SetCallState(count, CM_IDLE_STATE, FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  MakeSplitSucess
 * DESCRIPTION
 *  This function is a wrapper to split conference call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeSplitSucess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* only active mpty can be split */
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            if (cm_p->state_info.AllCalls[count].status_flag & CM_SPLIT_REQUESTED)
            {
                ResetCallflag(count, CM_SPLIT_REQUESTED, FALSE);
            }
            else
            {
                SetCallState(count, CM_HOLD_STATE, FALSE);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  AllowMoreCalls
 * DESCRIPTION
 *  Function to decide if more incoming calls can be made
 * PARAMETERS
 *  void
 *  Call(?)     [OUT]       Handle
 *  U16(?)      [IN]        Idx index to the active call
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
pBOOL AllowMoreCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = cm_p->state_info.TotalCallCount;
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        /* incoming call won't affect max call count */
        temp--;
    }
    if (temp >= MAX_CALLS - 1)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_AllowMoreCalls1);
        return FALSE;
    }
    else if (EmergencyCallPresent())
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_AllowMoreCalls2);
        return FALSE;
    }
    else if (GetCallAbortReqSentFlag())
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_AllowMoreCalls3);
        return FALSE;
    }
    else if (GetCallWaitFlag() == TRUE && IsScreenPresent(ITEM_SCR_USSN_MSG)) /*only allow CRSS, no CISS or CC now.*/
    {
        PRINT_INFORMATION("Wating call during USSR session.");
        return FALSE;
    }
	else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrentState
 * DESCRIPTION
 *  Helper function to get current state
 * PARAMETERS
 *  void
 *  current(?)      [OUT]       State
 * RETURNS
 *  CALL_STATE
 *****************************************************************************/
CALL_STATE GetCurrentState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.CurrentState;
}


/*****************************************************************************
 * FUNCTION
 *  GetPreviousState
 * DESCRIPTION
 *  Helper function to get previous state
 * PARAMETERS
 *  void
 *  current(?)      [OUT]       State
 * RETURNS
 *  CALL_STATE
 *****************************************************************************/
CALL_STATE GetPreviousState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.PrevState;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentState
 * DESCRIPTION
 *  Helper function to set current state
 * PARAMETERS
 *  state       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_SetCurrentState, state);
    cm_p->state_info.CurrentState = state;
}


/*****************************************************************************
 * FUNCTION
 *  SetPreviousState
 * DESCRIPTION
 *  Helper function to set previous state
 * PARAMETERS
 *  state       [IN]        // state to set as previous
 * RETURNS
 *  void
 *****************************************************************************/
void SetPreviousState(CALL_STATE state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_SetPreviousState, state);
    cm_p->state_info.PrevState = state;
}


/*****************************************************************************
 * FUNCTION
 *  isInCall
 * DESCRIPTION
 *  For other application to check if it is in-call, 
 *  regardless of gsm call or voip call. 
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in call, no matter it is in gsm call or voip call;
 *  FALSE means it is not in call, both for gsm call and voip call.
 *****************************************************************************/
pBOOL isInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if ((GetCurrentState() != CM_IDLE_STATE) || (mmi_voip_app_total_call()))
#else
    if (GetCurrentState() != CM_IDLE_STATE)
#endif
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  isOutgoingCall
 * DESCRIPTION
 *  For other application to check if outgoing call exists, 
 *  regardless of gsm call or voip call. 
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means outgoing call exists, no matter it is in gsm call or voip call;
 *  FALSE means outgoing call not exists, both for gsm call and voip call.
 *****************************************************************************/
pBOOL isOutgoingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if ((GetOutgoingCallHandle() != -1) || (mmi_voip_get_outgoing_call_id() != -1))
#else
    if (GetOutgoingCallHandle() != -1)
#endif
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  isIncomingCall
 * DESCRIPTION
 *  For other application to check if incoming call exists, 
 *  regardless of gsm call or voip call. 
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means incoming call exists, no matter it is in gsm call or voip call;
 *  FALSE means incoming call not exists, both for gsm call and voip call.
 *****************************************************************************/
pBOOL isIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if ((GetIncomingCallHandle() != -1) || (mmi_voip_get_incoming_call_id() != -1))
#else
    if (GetIncomingCallHandle() != -1)
#endif
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetTotalCallCount
 * DESCRIPTION
 *  Helper function to get total call count
 *  
 *  inclusive of incoming, outgoing, active and hold
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Call count
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetTotalCallCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_CCBS_SUPPORT__
	if(!GetCCBSFlag())
	{
#endif /*__MMI_CM_CCBS_SUPPORT__*/
    return cm_p->state_info.TotalCallCount;
#ifdef __MMI_CM_CCBS_SUPPORT__
        }
	else
	{
		return cm_p->state_info.TotalCallCount - 1;
	}
#endif /*__MMI_CM_CCBS_SUPPORT__*/
}

#ifdef __MMI_CM_CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetTotalCallCountIncCCBS
 * DESCRIPTION
 *  Helper function to get total call count
 *  
 *  inclusive of incoming, outgoing, active and hold
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Call count
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetTotalCallCountIncCCBS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.TotalCallCount;
}

/*****************************************************************************
 * FUNCTION
 *  SetDropCCBSAnswerMTFlag
 * DESCRIPTION
 *  Sets Drop CCBS recall and answer MT call Flag
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetDropCCBSAnswerMTFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gDropCCBSAnswerMTFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetDropCCBSAnswerMTFlag
 * DESCRIPTION
 *  Returns gDropCCBSAnswerMTFlag Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetDropCCBSAnswerMTFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gDropCCBSAnswerMTFlag;
}

#endif /*__MMI_CM_CCBS_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  GetTotalActiveCallCount
 * DESCRIPTION
 *  Helper function to get total active call count
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Active call count
 * RETURNS
 *  U16
 *****************************************************************************/
S16 GetTotalActiveCallCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.NumofActivecalls;
}


/*****************************************************************************
 * FUNCTION
 *  GetTotalHoldCallCount
 * DESCRIPTION
 *  Helper function to get total hold call count
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Hold call count
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetTotalHoldCallCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.NumofHeldcalls;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallflag
 * DESCRIPTION
 *  Sets a particular call flag
 * PARAMETERS
 *  nCallHandle     [IN]        // Handle for call structure for which flag is to be set
 *  flag            [IN]        // Flag to set
 *  bIsHandle       [IN]        // If the n/w has supplied a handle
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallflag(CM_CALL_HANDLE nCallHandle, U8 flag, pBOOL bIsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bIsHandle)
    {
        index = GetMMIStructIndexof(nCallHandle);
    }
    else
    {
        index = nCallHandle;
    }

    if (index >= 0)
    {
        cm_p->state_info.AllCalls[index].status_flag |= flag;
        PRINT_INFORMATION("SetCallflag: call index = %d, flag = %d\n", index, flag);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCallflag
 * DESCRIPTION
 *  Gets call flag
 * PARAMETERS
 *  nCallHandle     [IN]        // Handle for call structure for which flag is to be set
 *  bIsHandle       [IN]        // If the n/w has supplied a handle
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetCallflag(CM_CALL_HANDLE nCallHandle, pBOOL bIsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bIsHandle)
    {
        index = GetMMIStructIndexof(nCallHandle);
    }
    else
    {
        index = nCallHandle;
    }

    if (index == -1)
    {
        PRINT_INFORMATION("Get Call Flag-- bad Index>>\n");
        return 0;
    }
    return cm_p->state_info.AllCalls[index].status_flag;
}


/*****************************************************************************
 * FUNCTION
 *  ResetCallflag
 * DESCRIPTION
 *  Sets a particular call flag
 * PARAMETERS
 *  nCallHandle     [IN]        // Handle for call structure for which flag is to be set
 *  flag            [IN]        // Flag to set
 *  bIsHandle       [IN]        // If the n/w has supplied a handle
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCallflag(CM_CALL_HANDLE nCallHandle, U8 flag, pBOOL bIsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bIsHandle)
    {
        index = GetMMIStructIndexof(nCallHandle);
    }
    else
    {
        index = nCallHandle;
    }

    if (index == -1)
    {
        PRINT_INFORMATION("Reset Call Flag-- bad Index>>\n");
        return;
    }
    cm_p->state_info.AllCalls[index].status_flag &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallDirFlag
 * DESCRIPTION
 *  Gets the call direction flag
 * PARAMETERS
 *  handle      [IN]        
 *  Call(?)     [OUT]       Direction
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetCallDirFlag(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetMMIStructIndexof(handle);
    return cm_p->state_info.AllCalls[index].orgination_flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetMMIStructIndexof
 * DESCRIPTION
 *  Gets the call index in the array for a specified index
 * PARAMETERS
 *  nCallIndex      [IN]        // Call handle
 *  Index(?)        [OUT]       
 * RETURNS
 *  U16
 *****************************************************************************/
S16 GetMMIStructIndexof(CM_CALL_HANDLE nCallIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_CALLS; index++)
    {
        if (cm_p->state_info.AllCalls[index].call_handle == nCallIndex)
        {
            return index;
        }
    }
    PRINT_INFORMATION("\n Call Structure Corrupted @ GetMMIStructIndexof \n");
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  MapItemId2CallHandle
 * DESCRIPTION
 *  Function item Id to the call handle
 * PARAMETERS
 *  idx         [IN]        Index to the active call
 *  Call(?)     [OUT]       Handle
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE MapItemId2CallHandle(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    U8 activeCalls = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            if (idx == activeCalls)
            {
                return cm_p->state_info.AllCalls[count].call_handle;
            }
            activeCalls++;
        }
    }
    return (CM_CALL_HANDLE) - 1;
}


/*****************************************************************************
 * FUNCTION
 *  GetFirstFreeIndex
 * DESCRIPTION
 *  This function iterates over the calls strcutre to locate
 *  an index to a location where call info can be stored
 * PARAMETERS
 *  void
 *  Index(?)        [OUT]       To the location where the call can be stored
 * RETURNS
 *  Index
 *****************************************************************************/
S16 GetFirstFreeIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* must make change here to retrieve call index from PS */
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_handle == -1)
        {
            return count;
        }
    }
    return -1;
}

/* Start by Julia: Drop call refinement */


/*****************************************************************************
 * FUNCTION
 *  GetDisconnectingCallHandle
 * DESCRIPTION
 *  Helper function to check if there is any disconnecting call existed
 * PARAMETERS
 *  void
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE GetDisconnectingCallHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (CM_DISCONNECTING_STATE == cm_p->state_info.AllCalls[count].curr_state)
        {
            return cm_p->state_info.AllCalls[count].call_handle;
        }
    }
    PRINT_INFORMATION("No Disconnecting Call ");
    return -1;
}

/* End by Julia */


/*****************************************************************************
 * FUNCTION
 *  GetIncomingCallHandle
 * DESCRIPTION
 *  Helper function to get handle of incoming calll
 * PARAMETERS
 *  void
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE GetIncomingCallHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_INCOMING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            #ifdef __MMI_CM_CCBS_SUPPORT__
            if(cm_p->state_info.AllCalls[count].call_handle != GetCCBSHandle())
            #endif /*__MMI_CM_CCBS_SUPPORT__*/            
            return cm_p->state_info.AllCalls[count].call_handle;
        }
    }

    PRINT_INFORMATION("\n Incoming call not present @ GetIncomingCallHandle\n");
    return -1;
}

#ifdef __MMI_CM_CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetCCBSIncomingCallHandle
 * DESCRIPTION
 *  Helper function to get handle of incoming calll
 * PARAMETERS
 *  void
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE GetCCBSIncomingCallHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_INCOMING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
			return cm_p->state_info.AllCalls[count].call_handle;
		}
    }

    PRINT_INFORMATION("\n Incoming call not present @ GetIncomingCallHandle\n");
    return -1;
}
#endif /*__MMI_CM_CCBS_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  SetOutgoingCallHandle
 * DESCRIPTION
 *  Sets the call handle for the outgoing call
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetOutgoingCallHandle(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE)
        {
            cm_p->state_info.AllCalls[count].call_handle = handle;
            return;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingCallHandle
 * DESCRIPTION
 *  Helper function to get handle of outgoing call
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Hold call count
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE GetOutgoingCallHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_OUTGOING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            return cm_p->state_info.AllCalls[count].call_handle;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingCallIndex
 * DESCRIPTION
 *  Helper function to get index of outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
S16 GetOutgoingCallIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_OUTGOING_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            return count;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingCallOrigin
 * DESCRIPTION
 *  Helper function to get origin of outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  CALL_DIR
 *****************************************************************************/
CALL_DIR GetOutgoingCallOrigin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE)
        {
            return cm_p->state_info.AllCalls[count].orgination_flag;
        }
    }
    return CM_CALL_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallHandle
 * DESCRIPTION
 *  This function is a helper to get handle of by seraching on the name or number
 * PARAMETERS
 *  Dispname        [IN]        Name or number
 *  call(?)         [OUT]       Handle
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
CM_CALL_HANDLE GetCallHandle(PU8 Dispname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_handle != -1)
        {
            if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[count].num) == 0 && 
	       mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[count].CNAPname) > 0)
	    {
                if (cm_p->state_info.AllCalls[count].CNAPname == Dispname)
                {
                    return cm_p->state_info.AllCalls[count].call_handle;
                }
	    }
            else if (mmi_ucs2strlen((PS8)cm_p->state_info.AllCalls[count].pBname) > 0)
            {
                if (cm_p->state_info.AllCalls[count].pBname == Dispname)
                {
                    return cm_p->state_info.AllCalls[count].call_handle;
                }
            }
            else if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[count].CNAPname) > 0)
	        {
                if (cm_p->state_info.AllCalls[count].CNAPname == Dispname)
                {
                    return cm_p->state_info.AllCalls[count].call_handle;
                }
	        }
            else
            {
                if (cm_p->state_info.AllCalls[count].number == Dispname)
                {
                    return cm_p->state_info.AllCalls[count].call_handle;
                }
            }

        }
    }

    PRINT_INFORMATION("\n Call Structure Corrupted @ GetCallHandle \n");
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetAllDispNameorNum
 * DESCRIPTION
 *  This function fills up the array for the respective calls
 * PARAMETERS
 *  Dispnames           [IN]        // Array of names or numbers
 *  DispStrids          [IN]        // Array of image ids
 *  HighlightIndex      [?]         
 *  Number(?)           [OUT]       Of elements in the array
 * RETURNS
 *  U8
 *****************************************************************************/
U8 GetAllDispNameorNum(PU8 *Dispnames, U16 *DispStrids, U16 *Iconids, S16 *HighlightIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    U8 count = 0, count1 = 0, j = 0, i = 0;
    TIMEANDINDEX tmpTimeBuf;
    TIMEANDINDEX tmpArr[MAX_CALLS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_CALLS; index++)
    {
        if ((cm_p->state_info.AllCalls[index].call_handle != -1) &&
            (cm_p->state_info.AllCalls[index].curr_state != CM_IDLE_STATE) &&
            (cm_p->state_info.AllCalls[index].curr_state != CM_INCOMING_STATE))
        {
            if (CM_ACTIVE_STATE == cm_p->state_info.AllCalls[index].curr_state)
            {
                /* Stores the Start Time of the Active Call in tmpArr */
                memcpy(&tmpArr[i].time, &cm_p->state_info.AllCalls[count].start_time, sizeof(MYTIME));
                tmpArr[i].index = count;
                i++;    /* Inrease the Active Call Count by 1 */
            }

            if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].num) == 0 && 
	       mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
	    {
	        Dispnames[count] = cm_p->state_info.AllCalls[index].CNAPname;
	    }
            else if (mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].pBname) != 0)
            {
                Dispnames[count] = cm_p->state_info.AllCalls[index].pBname;
            }
            else if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
	        {
		        Dispnames[count] = cm_p->state_info.AllCalls[index].CNAPname;
	        }
            else
            {
		/* no name, show number */
                /* hide *31#, #31# prefix string  */
                if ((mmi_ucs2ncmp((PS8) cm_p->state_info.AllCalls[index].number, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) cm_p->state_info.AllCalls[index].number, (PS8) L"#31#", 4) == 0))
                {
                    Dispnames[count] = (U8 *)&cm_p->state_info.AllCalls[index].number[8];
                }
                else
                {
                    Dispnames[count] = (U8 *)&cm_p->state_info.AllCalls[index].number;
                }
            }
            if (CM_DISCONNECTING_STATE == cm_p->state_info.AllCalls[index].curr_state)
            {
                DispStrids[count] = GetImgIdofState(cm_p->state_info.AllCalls[index].prev_state);
            }
            else
            {
                DispStrids[count] = GetImgIdofState(cm_p->state_info.AllCalls[index].curr_state);
            }
            if (Iconids != NULL && isCSPPresent == 1 &&
				!IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
            {
            	if (cm_p->state_info.AllCalls[index].call_type == CM_AUX_VOICE_CALL)
            	{
            		if (GetTotalActiveCallCount() + GetTotalHoldCallCount() > 1)
            		{
            			Iconids[count] = IMG_CM_ICON_MULTI_LINE2;
            		}
            		else
            		{
            			Iconids[count] = IMG_CM_ICON_LINE2;
            		}
            	}
            	else
            	{
            		if (GetTotalActiveCallCount() + GetTotalHoldCallCount() > 1)
            		{
            			Iconids[count] = IMG_CM_ICON_MULTI_LINE1;
            		}
            		else
            		{
            			Iconids[count] = IMG_CM_ICON_LINE1;
            		}
            	}
            }
            count++;
        }
    }

    /* This loop sorts the Array tmpArr in such a way that
       the oldest call appears at top */
    for (count1 = 0; count1 < i - 1; count1++)
    {
        for (j = 0; j < i - 1 - count1; j++)
        {
            if (FindMaxTime(&tmpArr[j + 1].time, &tmpArr[j].time))
            {
                memcpy(&tmpTimeBuf, &tmpArr[j], sizeof(tmpTimeBuf));
                memcpy(&tmpArr[j], &tmpArr[j + 1], sizeof(tmpTimeBuf));
                memcpy(&tmpArr[j + 1], &tmpTimeBuf, sizeof(tmpTimeBuf));
            }
        }
    }

    /* highlight the latest active call */
    if (i == 0)
    {
        *HighlightIndex = 0;
    }
    else
    {
        *HighlightIndex = tmpArr[i - 1].index;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  GetAllActDispNameorNum
 * DESCRIPTION
 *  This function fills up the array for all active calls
 * PARAMETERS
 *  Dispnames       [IN]        // Array of names or numbers
 *  Number(?)       [OUT]       Of elements in the array
 * RETURNS
 *  U8
 *****************************************************************************/
U8 GetAllActDispNameorNum(PU8 *Dispnames)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_CALLS; index++)
    {
        if ((cm_p->state_info.AllCalls[index].call_handle != -1) &&
            (cm_p->state_info.AllCalls[index].curr_state == CM_ACTIVE_STATE))
        {
            if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].num) == 0 && 
	       mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
	    {
	        Dispnames[count] = cm_p->state_info.AllCalls[index].CNAPname;
	    }
            else if (mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].pBname) != 0)
            {
                Dispnames[count] = cm_p->state_info.AllCalls[index].pBname;
            }
            else if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
	        {
		        Dispnames[count] = cm_p->state_info.AllCalls[index].CNAPname;
	        }
            else
            {
                Dispnames[count] = cm_p->state_info.AllCalls[index].number;
            }
            count++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  GetImgIdofState
 * DESCRIPTION
 *  This function returns the respective image id as per the call state
 * PARAMETERS
 *  tmpState        [IN]        // Call state
 *  Image(?)        [OUT]       Id
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetImgIdofState(CALL_STATE tmpState)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tmpState)
    {
        case CM_OUTGOING_STATE:
            strId = IMG_CM_STATE_OUTGOING;
            break;

        case CM_INCOMING_STATE:
            strId = IMG_CM_STATE_INCOMING;
            break;

        case CM_ACTIVE_STATE:
            strId = IMG_CM_STATE_ACTIVE;
            break;

        case CM_HOLD_STATE:
            strId = IMG_CM_STATE_HOLD;
            break;
            /* Start by Julia: Drop call refinement */
        case CM_DISCONNECTING_STATE:
            strId = IMG_CM_STATE_DISCONNECTING;
            break;
            /* End by Julia */
        default:
            PRINT_INFORMATION("\n CM Event State m/c corrupted \n");
            break;
    }
    return strId;
}


/*****************************************************************************
 * FUNCTION
 *  SetCalledNumber
 * DESCRIPTION
 *  Sets Call Abort Flag dpeneding on flag
 * PARAMETERS
 *  index       [IN]        
 *  msg         [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCalledNumber(S16 index, U8 *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        cm_p->state_info.AllCalls[index].num,
        cm_p->state_info.AllCalls[index].number,
        sizeof(cm_p->state_info.AllCalls[index].num));
    memset(cm_p->state_info.AllCalls[index].number, 0, sizeof(cm_p->state_info.AllCalls[index].number));

    if (*msg)
    {
        mmi_ucs2cpy((S8*) cm_p->state_info.AllCalls[index].number, (S8*) msg);
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetCNAPName
 * DESCRIPTION
 *  Sets CNAP number
 * PARAMETERS
 *  call handle        
 *  msg    
 * RETURNS
 *  void
 *****************************************************************************/
void SetCNAPName(CM_CALL_HANDLE call_handle, U8 dcs, U8 length, U8 *CNAP_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nameLen = 0;
    U8 *tempStr = NULL;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for(count = 0; count < MAX_CALLS; count++)
    {
        if(cm_p->state_info.AllCalls[count].call_handle == call_handle)
        {
            memset(cm_p->state_info.AllCalls[count].CNAPname, 0, sizeof(cm_p->state_info.AllCalls[count].CNAPname));
            nameLen = length;

            if (nameLen >= MAX_NAME)
            {
                if(dcs == MMI_UCS2_DCS)
                {
                    nameLen = MAX_NAME - 2;
                }
                else
                {
                    nameLen = MAX_NAME - 1;
                }
            }

            if (dcs == MMI_8BIT_DCS)
            {
                tempStr = CovertStringForPlatform(CNAP_name, length, dcs, &nameLen);
            }
            else
            {
                tempStr = OslMalloc(MAX_NAME);
                memset(tempStr, 0, (MAX_NAME));
                CNAP_name[nameLen] = 0; /*InputboxConvertGSMToDeviceEncoding requirement*/
                CNAP_name[nameLen+1] = 0;
                InputboxConvertGSMToDeviceEncoding(CNAP_name, tempStr, nameLen, (MAX_NAME), dcs, 0, 1);
            }
            if (tempStr != NULL)
            {
                mmi_ucs2ncpy((PS8) cm_p->state_info.AllCalls[count].CNAPname, (PS8) tempStr, (MAX_NAME));
                OslMfree(tempStr);
            }
            return;
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  SetCalledNumWithType
 * DESCRIPTION
 *  Sets called number alongwith type field
 * PARAMETERS
 *  index       [IN]        
 *  msg         [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCalledNumWithTypeAux(S16 index, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CONNECT_IND *msgBuf = (MMI_CONNECT_IND*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* number changed once, no need to change again */
    if (mmi_ucs2cmp ((PS8)cm_p->state_info.AllCalls[index].num, 
        						  (PS8)cm_p->state_info.AllCalls[index].number) != 0)
    {
		return;
	}

	/* old number -> num
	   new number -> number */
    memcpy(
        cm_p->state_info.AllCalls[index].num,
        cm_p->state_info.AllCalls[index].number,
        sizeof(cm_p->state_info.AllCalls[index].num));
    memset(cm_p->state_info.AllCalls[index].number, 0, sizeof(cm_p->state_info.AllCalls[index].number));

    cm_p->state_info.AllCalls[index].call_type = msgBuf->call_type;

    if (*(msgBuf->num.number))
    {
        if ((msgBuf->num.type) & 0x10)
        {
            mmi_asc_to_ucs2((S8*) cm_p->state_info.AllCalls[index].number, "+");
            mmi_asc_to_ucs2((S8*) (cm_p->state_info.AllCalls[index].number + 2), (S8*) msgBuf->num.number);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) cm_p->state_info.AllCalls[index].number, (S8*) msgBuf->num.number);
        }
    }
    else
    {
        mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) GetString(STR_UNKNOWN_CALLER));
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCalledNumWithType
 * DESCRIPTION
 *  Sets called number alongwith type field
 * PARAMETERS
 *  index       [IN]        
 *  msg         [?]         
 *  flag(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCalledNumWithType(S16 index, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CONNECT_IND *msgBuf = (MMI_CONNECT_IND*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*(msgBuf->num.number))
    {
    #ifdef __IP_NUMBER__
        if (GetTempUseIPNumber() == FALSE)
    #endif 
        {
        	/* number changed, look up again */
        	if (mmi_ucs2cmp ((PS8)cm_p->state_info.AllCalls[index].num, 
        						  (PS8)cm_p->state_info.AllCalls[index].number) != 0)
        	{
            PHB_CM_INTERFACE phb_data;

            /* IP dial connected number don't search PHB */

            if (gPhoneNumberStruct.dialInList != MMI_PHB_NONE)
            {
                mmi_phb_call_set_dial_from_list(gPhoneNumberStruct.dialInList);
            }

            if (cm_p->redial_info.DialFromPhb != MMI_PHB_NONE)
            {
                mmi_phb_call_set_dial_from_list(cm_p->redial_info.DialFromPhb);
            }

            phb_data = mmi_phb_call_get_data_for_call_mgnt(cm_p->state_info.AllCalls[index].number, TRUE);
            SetCMPhoneBookStruct(&phb_data);
            	
            	/* use phb name + number */
            cm_p->state_info.AllCalls[index].name_dcs = gPhoneNumberStruct.name_dcs;
            mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].pBname, (PS8) gPhoneNumberStruct.name);
            if (!(gPhoneNumberStruct.number[0] == 0 && gPhoneNumberStruct.number[1] == 0))
            {
                mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) gPhoneNumberStruct.number);
            }
        }
    }

    }
}


/*****************************************************************************
 * FUNCTION
 *  SetOutgoingNamefromPhonebook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetOutgoingNamefromPhonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetOutgoingCallIndex();
    if (index == -1)
    {
        return;
    }

    memset((PS8) cm_p->state_info.AllCalls[index].pBname, 0, sizeof(cm_p->state_info.AllCalls[index].pBname));

    /* memcpy((PS8)cm_p->state_info.AllCalls[index].pbNumber,(PS8)&gPhoneNumberStruct.number,
       sizeof(cm_p->state_info.AllCalls[index].pbNumber)); */
    memcpy(
        (PS8) cm_p->state_info.AllCalls[index].pBname,
        (PS8) gPhoneNumberStruct.name,
        sizeof(cm_p->state_info.AllCalls[index].pBname));
    cm_p->state_info.AllCalls[index].name_dcs = gPhoneNumberStruct.name_dcs;

    /* if (!(gPhoneNumberStruct.number[0] == 0 && gPhoneNumberStruct.number[1] == 0))
       mmi_ucs2cpy((PS8)cm_p->state_info.AllCalls[index].number,(PS8)gPhoneNumberStruct.number); */
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingNumber
 * DESCRIPTION
 *  Returns number for outgoing call
 * PARAMETERS
 *  void
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
PU8 GetOutgoingNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE ||
            (cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE &&
             cm_p->state_info.AllCalls[count].prev_state == CM_OUTGOING_STATE))
        {
            return cm_p->state_info.AllCalls[count].number;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingName
 * DESCRIPTION
 *  Returns name for outgoing call
 * PARAMETERS
 *  void
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
PU8 GetOutgoingName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE && cm_p->state_info.AllCalls[count].pBname)
        {
            return cm_p->state_info.AllCalls[count].pBname;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetOutgoingCallType
 * DESCRIPTION
 *  Returns the type of outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  Call type
 *****************************************************************************/
U8 GetOutgoingCallType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_OUTGOING_STATE)
        {
            return cm_p->state_info.AllCalls[count].call_type;
        }
    }
    return CSMCC_VOICE_CALL;
}

/*****************************************************************************
 * FUNCTION
 *  GetIncomingCallType
 * DESCRIPTION
 *  Returns the type of outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  Call type
 *****************************************************************************/
U8 GetIncomingCallType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_INCOMING_STATE)
        {
            return cm_p->state_info.AllCalls[count].call_type;
        }
    }
    return CSMCC_VOICE_CALL;
}

/*****************************************************************************
 * FUNCTION
 *  GetActiveCallIndex
 * DESCRIPTION
 *  Helper function to get index of outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  CM_CALL_HANDLE
 *****************************************************************************/
S16 GetActiveCallIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE ||
            (cm_p->state_info.AllCalls[count].prev_state == CM_ACTIVE_STATE &&
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            return count;
        }
    }
    return -1;
}

#ifdef __MMI_CM_BLACK_LIST__


/*****************************************************************************
 * FUNCTION
 *  BlockedHandle
 * DESCRIPTION
 *  Function to check if the call is in black list
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  True means the number is blocked, False means it is not
 *****************************************************************************/
pBOOL BlockedHandle(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetBlackListMode() == TRUE && cm_p->state_info.AllCalls[index].block_flag == TRUE)
    {
        SetClearKeyFlag(FALSE);
        return TRUE;
    }
    else
    {
        SetClearKeyFlag(TRUE);
        return FALSE;
    }
}
#endif /* __MMI_CM_BLACK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCallName
 * DESCRIPTION
 *  Function gets the name or number of incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Pointer(?)      [OUT]       To buffer containing name or number
 * RETURNS
 *  PS8
 *****************************************************************************/
PU8 GetCallName(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if(mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].num) == 0 && 
       mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
    {
	return cm_p->state_info.AllCalls[index].CNAPname;
    }

    if (mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].pBname) != 0)
    {
        return cm_p->state_info.AllCalls[index].pBname;
    }

    if (mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].CNAPname) != 0)
    {
        return cm_p->state_info.AllCalls[index].CNAPname;
    }

    if (!cm_p->state_info.AllCalls[index].number)
    {
        /* unknown number */
        mmi_ucs2cpy((PS8) cm_p->state_info.AllCalls[index].number, (PS8) GetString(STR_UNKNOWN_CALLER));
    }
    return cm_p->state_info.AllCalls[index].number;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallNumber
 * DESCRIPTION
 *  Returns number for outgoing call
 * PARAMETERS
 *  handle          [IN]        
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
PU8 GetCallNumber(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index != -1)
    {
        return cm_p->state_info.AllCalls[index].number;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetCallType
 * DESCRIPTION
 *  Function gets the type of incoming call
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  Call Type
 *****************************************************************************/
U8 GetCallType(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->state_info.AllCalls[index].call_type;
}

/*****************************************************************************
 * FUNCTION
 *  GetCallStartTime
 * DESCRIPTION
 *  Function gets the image id for an incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Image(?)        [OUT]       Id
 * RETURNS
 *  U16
 *****************************************************************************/
MYTIME * GetCallStartTime (CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0)
	    return &cm_p->state_info.AllCalls[index].start_time;
    else
    	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  GetCallImgId
 * DESCRIPTION
 *  Function gets the image id for an incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Image(?)        [OUT]       Id
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetCallImgId(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INCOMING_CALL_VIDEO__
    /* incoming call with video set */
    if (cm_p->state_info.AllCalls[index].number && gPhoneNumberStruct.videoId != 0)
    {
        if (gPhoneNumberStruct.videoId & 0x8000)
        {
            /* check file presence before use it */
            S8 *path;
            FS_HANDLE fh;

            path = GetCallVideoPath(handle);
            if (path != NULL)
            {
            #ifdef __MMI_AVATAR__
			    if (gPhoneNumberStruct.videoId & 0x1000)
                {
                    return gPhoneNumberStruct.videoId;
                }
		    #endif /* __MMI_AVATAR__ */
            
                fh = FS_Open((PU16) path, FS_READ_ONLY);
                if (fh > FS_NO_ERROR)
                {
                    FS_Close(fh);
                    /* use phonebook video if matched */
                    return gPhoneNumberStruct.videoId;
                }
            }
        }
        else
        {
            return gPhoneNumberStruct.videoId;
        }
    }
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
    if (cm_p->state_info.AllCalls[index].number && gPhoneNumberStruct.pictureId != 0)
    {
        /* use phonebook image if matched */
        return gPhoneNumberStruct.pictureId;
    }
    else
    {
        /* use default image */
        return IMG_PHB_DEFAULT;
    }
}

#ifdef __MMI_PHB_CALL_SHOW_PICTURE_FROM_FILE__


/*****************************************************************************
 * FUNCTION
 *  GetCallImgPath
 * DESCRIPTION
 *  Function gets the image path for an incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Image(?)        [OUT]       Path
 * RETURNS
 *  S8 *
 *****************************************************************************/
extern S8 *mmi_phb_image_get_path_from_id(U16 index);

S8 *GetCallImgPath(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 RecordIndex;
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->state_info.AllCalls[index].number)
    {
        RecordIndex = gPhoneNumberStruct.record_index;
        if (RecordIndex == 0)
        {
            return NULL;
        }
        else
        {
            return mmi_phb_image_get_path_from_id(RecordIndex);
        }
    }
    else if (mmi_ucs2cmp((PS8) cm_p->state_info.AllCalls[index].number, GetString(STR_UNKNOWN_CALLER)))
    {
        return NULL;
    }
    return NULL;
}
#endif /* __MMI_PHB_CALL_SHOW_PICTURE_FROM_FILE__ */ 

#ifdef __MMI_INCOMING_CALL_VIDEO__


/*****************************************************************************
 * FUNCTION
 *  GetCallVideoPath
 * DESCRIPTION
 *  Function gets the video path for an incoming call
 * PARAMETERS
 *  handle          [IN]        
 *  Video(?)        [OUT]       Path
 * RETURNS
 *  S8 *
 *****************************************************************************/
extern S8 *mmi_phb_video_get_path_from_id(U16 record_index);

S8 *GetCallVideoPath(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 RecordIndex;
    S16 index = GetMMIStructIndexof(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->state_info.AllCalls[index].number)
    {
        RecordIndex = gPhoneNumberStruct.video_record_index;
        if (RecordIndex == 0)
        {
            return NULL;
        }
        else
        {
            return mmi_phb_video_get_path_from_id(RecordIndex);
        }
    }
    else if (mmi_ucs2cmp((PS8) cm_p->state_info.AllCalls[index].number, GetString(STR_UNKNOWN_CALLER)))
    {
        return NULL;
    }
    return NULL;
}
#endif /* __MMI_INCOMING_CALL_VIDEO__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetActiveCallType
 * DESCRIPTION
 *  Function gets the call type for an active call
 * PARAMETERS
 *  void
 *  call(?)     [OUT]       Type
 * RETURNS
 *  U16
 *****************************************************************************/
U8 GetActiveCallType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE)
        {
            return cm_p->state_info.AllCalls[count].call_type;
        }
    }
    return CSMCC_VOICE_CALL;
}


/*****************************************************************************
 * FUNCTION
 *  GetDispNameorNum
 * DESCRIPTION
 *  Gets the name or number for a particular call handle
 * PARAMETERS
 *  void
 *  Pointer(?)              [OUT]       To the name or number buffer
 *  CM_CALL_HANDLE(?)       [IN]        NCallIndex, // Call handle
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 GetDispNameorNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_CALLS; index++)
    {
        /* Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition */
        if (cm_p->state_info.AllCalls[index].curr_state == CM_OUTGOING_STATE ||
            cm_p->state_info.AllCalls[index].curr_state == CM_DISCONNECTING_STATE)
            /* End by Julia */
        {

            if ((mmi_ucs2strlen((PS8) cm_p->state_info.AllCalls[index].pBname) == 0)
        #ifdef __IP_NUMBER__
                || GetTempUseIPNumber()
        #endif 
                )
            {
            	/* no name, show number */
                /* hide *31#, #31# prefix string  */
                if ((mmi_ucs2ncmp((PS8) cm_p->state_info.AllCalls[index].number, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) cm_p->state_info.AllCalls[index].number, (PS8) L"#31#", 4) == 0))
                {
                    return &cm_p->state_info.AllCalls[index].number[8];
                }
                else
                {
                    return cm_p->state_info.AllCalls[index].number;
                }
            }
            else
            {
                return cm_p->state_info.AllCalls[index].pBname;
            }
        }
    }
    return NULL;
}


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  SetBlackIncomingFlag
 * DESCRIPTION
 *  Sets flag if the incoming call is in black list
 * PARAMETERS
 *  value       [IN]        
 *  TRUE(?)     [IN]        /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetBlackIncomingFlag(pBOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gBlackIncomingFlag = value;
}


/*****************************************************************************
 * FUNCTION
 *  GetBlackIncomingFlag
 * DESCRIPTION
 *  Returns true if this incoming call is in black list
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetBlackIncomingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gBlackIncomingFlag;
}
#endif /* __MMI_CM_BLACK_LIST__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetClearKeyFlag
 * DESCRIPTION
 *  it is the derivative function for auto-rejected black list incoming call to determine
 *  if the clear key handler should be called before rejecting a call
 * PARAMETERS
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetClearKeyFlag(pBOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gClearKeyFlag = value;
}


/*****************************************************************************
 * FUNCTION
 *  GetClearKeyFlag
 * DESCRIPTION
 *  it is the derivative function for auto-rejected black list incoming call to determine
 *  if the clear key handler should be called before rejecting a call
 * PARAMETERS
 *  void
 * RETURNS
 *  True means the clear key handler should be called, False means it should not
 *****************************************************************************/
pBOOL GetClearKeyFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gClearKeyFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetCCFlag
 * DESCRIPTION
 *  Sets flag is this is normal voice call
 * PARAMETERS
 *  value       [IN]        
 *  TRUE(?)     [IN]        /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetCCFlag(pBOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsCCCall = value;
}


/*****************************************************************************
 * FUNCTION
 *  GetCCFlag
 * DESCRIPTION
 *  Returns true if this is voice call
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetCCFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIsCCCall;
}


/*****************************************************************************
 * FUNCTION
 *  SetTransitionToActiveFlag
 * DESCRIPTION
 *  Sets flag for get time before enter active call
 *  screen
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetTransitionToActiveFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gGetTimeBeforeActive = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetTransitionToActiveFlag
 * DESCRIPTION
 *  Returns flag for get time before enter active call
 *  screen
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL GetTransitionToActiveFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gGetTimeBeforeActive;
}


/*****************************************************************************
 * FUNCTION
 *  SetAnswerMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetAnswerMode(void *mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == NULL)
    {
        memset(&gCMAnsMode, 0, sizeof(MMI_ANSWERING_MODE));
    }
    else
    {
        memcpy(&gCMAnsMode, mode, sizeof(MMI_ANSWERING_MODE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetAnswerMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *GetAnswerMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &gCMAnsMode;
}


/*****************************************************************************
 * FUNCTION
 *  SetAutoAnswerFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetAutoAnswerFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAutoAnswerFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetAutoAnswerFlag
 * DESCRIPTION
 *  Gets the AutoAnswerFlag Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetAutoAnswerFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gAutoAnswerFlag;
}

/* Start by Julia: Drop call refinement */


/*****************************************************************************
 * FUNCTION
 *  SetAutoReleaseFlag
 * DESCRIPTION
 *  Set AutoReleaseFlag to determine if auto release is needed
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For auto release all disconnecting calls, FALSE otherwise
 * RETURNS
 *  void
 *****************************************************************************/
void SetAutoReleaseFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gAutoReleaseFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetAutoReleaseFlag
 * DESCRIPTION
 *  Gets the AutoReleaseFlag Status
 *  
 *  It if for drop call refinement
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For auto release all disconnecting calls, FALSE otherwise
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetAutoReleaseFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gAutoReleaseFlag;
}

/* End by Julia */


/*****************************************************************************
 * FUNCTION
 *  GetHungUpHandle
 * DESCRIPTION
 *  Helper function to get handle of hungup call
 * PARAMETERS
 *  void
 *  total(?)        [OUT]       Hold call count
 * RETURNS
 *  U16
 *****************************************************************************/
CM_CALL_HANDLE GetHungUpHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if ((cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE ||
             cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE ||
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE) &&
            (cm_p->state_info.AllCalls[count].status_flag & CM_HANGUP_REQUESTED))
        {
            return cm_p->state_info.AllCalls[count].call_handle;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  SetAbortCallRequestedFlag
 * DESCRIPTION
 *  Sets Call Abort Flag dpeneding on flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetAbortCallRequestedFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallAbortRequested = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetAbortCallRequestedFlag
 * DESCRIPTION
 *  Returns Call Abort Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  flag
 *****************************************************************************/
pBOOL GetAbortCallRequestedFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallAbortRequested;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallAbortReqSentFlag
 * DESCRIPTION
 *  Sets Call Abort sent Flag dpeneding on flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallAbortReqSentFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallAbortReqSentFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallAbortReqSentFlag
 * DESCRIPTION
 *  Returns Call Abort sent Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  flag
 *****************************************************************************/
pBOOL GetCallAbortReqSentFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallAbortReqSentFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetDropRequestFlag
 * DESCRIPTION
 *  Sets the DropRequest Flag
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetDropRequestFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gDropRequestFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetDropRequestFlag
 * DESCRIPTION
 *  Gets the DropRequest Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetDropRequestFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gDropRequestFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetIncomingCallDroppedFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetIncomingCallDroppedFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gIncomingCallDroppedFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetIncomingCallDroppedFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetIncomingCallDroppedFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remote side of MT call drops */
    gIncomingCallDroppedFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  SetMissedCallFlag
 * DESCRIPTION
 *  Sets the MissedCall Flag
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetMissedCallFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMissedCallFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetMissedCallFlag
 * DESCRIPTION
 *  Gets the MissedCall Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetMissedCallFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMissedCallFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallWaitFlag
 * DESCRIPTION
 *  Sets Call Wait Flag dpeneding on flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallWaitFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallWaitFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallWaitFlag
 * DESCRIPTION
 *  Returns Call Wait Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  flag
 *****************************************************************************/
pBOOL GetCallWaitFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallWaitFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetNoTwiceRingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetNoTwiceRingFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNoTwiceRingFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetNoTwiceRingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetNoTwiceRingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gNoTwiceRingFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetWait2RingCallFlag
 * DESCRIPTION
 *  Sets Wait To Ring Flag dpeneding on flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetWait2RingCallFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gWait2RingCallFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetWait2RingCallFlag
 * DESCRIPTION
 *  Gets Wait To Ring Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  flag
 *****************************************************************************/
pBOOL GetWait2RingCallFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gWait2RingCallFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallEndedBeforeConnFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallEndedBeforeConnFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallEndedBeforeConnFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallEndedBeforeConnFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetCallEndedBeforeConnFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallEndedBeforeConnFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetErrorToneFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetErrorToneFlag(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gErrorToneFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetErrorToneFlag
 * DESCRIPTION
 *  Gets the ErrorToneFlag Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetErrorToneFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gErrorToneFlag;
}

extern void reset_call_cost_UI(void);
/*****************************************************************************
 * FUNCTION
 *  SetShowAOC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetShowAOC(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gShowAOC = flag;
    if (!flag)
    {
         reset_call_cost_UI();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetShowAOC
 * DESCRIPTION
 *  Gets the ActiveToHold Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetShowAOC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gShowAOC;
}


/*****************************************************************************
 * FUNCTION
 *  SetDTMFKeyUpFlag
 * DESCRIPTION
 *  Set DTMF Key Up Flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetDTMFKeyUpFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gDTMFKeyUpFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetDTMFKeyUpFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetDTMFKeyUpFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gDTMFKeyUpFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetCMScrnFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCMScrnFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCMScrnFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCMScrnFlag
 * DESCRIPTION
 *  Gets the CMScrnFlag Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetCMScrnFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCMScrnFlag;
}


/*****************************************************************************
 * FUNCTION
 *  UpdateActiveCallScrnIfPresent
 * DESCRIPTION
 *  Redraws Active Call Screen if Present
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateActiveCallScrnIfPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_CM_ACTIVECALLSCREEN && GetTotalCallCount() > 0)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_UpdateActiveCallScrnIfPresent);
        EntryScr1002ActiveCall();
    }
    else if ((GetCurrentState() == CM_ACTIVE_STATE || GetCurrentState() == CM_HOLD_STATE)
             && (GetSyncCallFromATFlag() == TRUE))
    {
        GoBackToHistory(SCR_CM_ACTIVECALLSCREEN);
    }
    SetSyncCallFromATFlag(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  EmergencyCallPresent
 * DESCRIPTION
 *  Check if emergency call is Present
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL EmergencyCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (CheckValidEmergencyNo1((PS8) cm_p->state_info.AllCalls[count].number))
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SetWapCallPresent
 * DESCRIPTION
 *  Sets wap call present flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetWapCallPresent(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gWapCallPresent = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetWapCallPresent
 * DESCRIPTION
 *  Returns wap call present flag
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetWapCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gWapCallPresent;
}


/*****************************************************************************
 * FUNCTION
 *  SetPreviousCallWAP
 * DESCRIPTION
 *  Sets previous call is wap flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPreviousCallWAP(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPreviousWapCall = flag;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetPreviousCallWAP
 * DESCRIPTION
 *  Returns previous call is wap flag
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetPreviousCallWAP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPreviousWapCall;
}


/*****************************************************************************
 * FUNCTION
 *  IsWapCallPresent
 * DESCRIPTION
 *  check if wap call present
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL IsWapCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_type == CSMCC_CSD_CALL)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  IsFaxCallPresent
 * DESCRIPTION
 *  check if fax call present
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL IsFaxCallPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].call_type == CSMCC_FAX_CALL)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  SetCallEndCause
 * DESCRIPTION
 *  Keep call end cause for error display after get time
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallEndCause(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallEndCause = cause;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallEndCause
 * DESCRIPTION
 *  Gets previously saved call end cause for display error
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 GetCallEndCause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallEndCause;
}

#ifdef __IP_NUMBER__


/*****************************************************************************
 * FUNCTION
 *  SetTempUseIPNumber
 * DESCRIPTION
 *  Enable/disable temporary IP dialing
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetTempUseIPNumber(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gTempUseIPNum = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetTempUseIPNumber
 * DESCRIPTION
 *  Check if temporary IP dialing is enabled
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetTempUseIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gTempUseIPNum;
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetCMPhoneBookStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pNumberStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetCMPhoneBookStruct(PHB_CM_INTERFACE *pNumberStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp1[50];
    S8 temp2[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((PS8) temp1, (PS8) pNumberStruct->name);
    mmi_ucs2_to_asc((PS8) temp2, (PS8) pNumberStruct->number);
    PRINT_INFORMATION("*** SetCMPhoneBookStruct name=%s, number=%s\n", temp1, temp2);

    memcpy(&gPhoneNumberStruct, pNumberStruct, sizeof(PHB_CM_INTERFACE));
}


/*****************************************************************************
 * FUNCTION
 *  GetCMPhoneBookStruct
 * DESCRIPTION
 *  Gets the CMScrnFlag Flag Status
 * PARAMETERS
 *  void
 *  PHB_CM_INTERFACE(?)     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
PHB_CM_INTERFACE *GetCMPhoneBookStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &gPhoneNumberStruct;
}


/*****************************************************************************
 * FUNCTION
 *  SetSyncCallFromATFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetSyncCallFromATFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSyncFromAT = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetSyncCallFromATFlag
 * DESCRIPTION
 *  Gets the CallDeflectFlag Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetSyncCallFromATFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gSyncFromAT;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallDeflectFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallDeflectFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallDeflectFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallDeflectFlag
 * DESCRIPTION
 *  Gets the CallDeflectFlag Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetCallDeflectFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallDeflectFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetActivatedCcbsFlag
 * DESCRIPTION
 *  Sets the CCBS Activated Flag
 * PARAMETERS
 *  ccbsFlag        [IN]        
 *  TRUE(?)         [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetActivatedCcbsFlag(pBOOL ccbsFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* activate ccbs */
    gCcbsFlagActivated = ccbsFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetActivatedCcbsFlag
 * DESCRIPTION
 *  Gets the CCBS activated Flag
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetActivatedCcbsFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCcbsFlagActivated;
}


/*****************************************************************************
 * FUNCTION
 *  SetCCBSFlag
 * DESCRIPTION
 *  Sets the CCBS Flag
 * PARAMETERS
 *  ccbsFlag        [IN]        
 *  TRUE(?)         [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCCBSFlag(pBOOL ccbsFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CCBS invoke came */
    gCcbsFlag = ccbsFlag;
}


/*****************************************************************************
 * FUNCTION
 *  GetCCBSFlag
 * DESCRIPTION
 *  Gets the CCBS Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetCCBSFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCcbsFlag;
}

#ifdef __MMI_CM_CCBS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *   SetCCBSHandle
 * DESCRIPTION
 *  Sets the CCBS Handle
 * PARAMETERS
 *  ccbsFlag        [IN]        
 *  TRUE(?)         [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetCCBSHandle(CM_CALL_HANDLE ccbsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* CCBS invoke came */
    gCcbsHandle = ccbsHandle;
}

/*****************************************************************************
 * FUNCTION
 *  GetCCBSFlag
 * DESCRIPTION
 *  Gets the CCBS Handle
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
CM_CALL_HANDLE GetCCBSHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCcbsHandle;
}
#endif /*__MMI_CM_CCBS_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  CCBSUpdateCallInfo
 * DESCRIPTION
 *  Updates CCBS Call Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CCBSUpdateCallInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE tmp;
    S16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_CM_CCBS_SUPPORT__
    tmp = GetCCBSHandle();
    #else
    tmp = GetIncomingCallHandle();
    #endif /*__MMI_CM_CCBS_SUPPORT__*/
    index = GetMMIStructIndexof(tmp);
    gtmpOutgoingIndex = index;

    cm_p->state_info.AllCalls[index].orgination_flag = CM_CALL_MO;
    SetCurrentState(CM_OUTGOING_STATE);
    SetCallState(index, CM_OUTGOING_STATE, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  CMAllowInterrupt
 * DESCRIPTION
 *  Check if call management is in interruptable
 *  state for WAP to display screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 CMAllowInterrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = (U8) GetTotalCallCount();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* idle screen not in history means it's in idle screen */
    if ((mmi_bootup_is_idle_screen_reached() == MMI_TRUE) && (IsScreenPresent(IDLE_SCREEN_ID) == FALSE))
    {
        /* idle screen allows WAP to show screen */
        return TRUE;
    }
    else if (count == 1 && GetWapCallPresent())
    {
        /* in WAP call allows WAP to show screen */
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  LogCallInfoForCallHistory
 * DESCRIPTION
 *  Keep call info for call log before get time
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void LogCallInfoForCallHistory(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetMMIStructIndexof(handle);
    PRINT_INFORMATION("*** LogCallInfoForCallHistory call handle=%d, index=%d\n", handle, index);

    memcpy(&cm_p->state_info.CallStructureForCallLog, &cm_p->state_info.AllCalls[index], sizeof(CALL_INFO));
}


/*****************************************************************************
 * FUNCTION
 *  UpdateCallStartTimeAndLogCall
 * DESCRIPTION
 *  Helper function to get the call handle of the
 *  recent incoming/outgoing or active call
 * PARAMETERS
 *  handle      [IN]        
 *  t           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateCallStartTimeAndLogCall(CM_CALL_HANDLE handle, MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetMMIStructIndexof(handle);

    /* start call time reminder once call is connected */
    gCtrTime = GetCtrTime();

    memcpy(&cm_p->state_info.AllCalls[index].start_time, t, sizeof(MYTIME));

    /*memcpy(&cm_p->state_info.AllCalls[index].num,
            &cm_p->state_info.AllCalls[index].number,
            sizeof(cm_p->state_info.AllCalls[index].num));*/

    LogCallWithStartTime(&cm_p->state_info.AllCalls[index]);
}


/*****************************************************************************
 * FUNCTION
 *  UpdateCallStartTimeforWapCall
 * DESCRIPTION
 *  CallBack Called after Start Time For Wap Call Recieved from L4
 * PARAMETERS
 *  t       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateCallStartTimeforWapCall(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCallHandleForStartTimeUpdate())
    {
        UpdateCallStartTimeAndLogCall(GetCallHandleForStartTimeUpdate(), t);
        SetCallHandleForStartTimeUpdate(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCallHandleForStartTimeUpdate
 * DESCRIPTION
 *  Saves the Call Handler for which start time is
 *  to be updated
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallHandleForStartTimeUpdate(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCallHandleForStartTimeUpdate = handle;
}


/*****************************************************************************
 * FUNCTION
 *  GetCallHandleForStartTimeUpdate
 * DESCRIPTION
 *  Returns the Call Handler for which start time is
 *  to be updated
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CM_CALL_HANDLE GetCallHandleForStartTimeUpdate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCallHandleForStartTimeUpdate;
}


/*****************************************************************************
 * FUNCTION
 *  LogCall
 * DESCRIPTION
 *  Logs Call Duration for Current Call
 * PARAMETERS
 *  void
 *  CM_CALL_HANDLE(?)       [IN]        Of call
 * RETURNS
 *  void
 *****************************************************************************/
void LogCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // drop call refine
    // abort MO call state will be disconnecting, but also need to be logged
    if ((cm_p->state_info.CallStructureForCallLog.curr_state == CM_OUTGOING_STATE) ||
        (cm_p->state_info.CallStructureForCallLog.curr_state == CM_INCOMING_STATE) ||
        ((cm_p->state_info.CallStructureForCallLog.curr_state == CM_DISCONNECTING_STATE) &&
         (cm_p->state_info.CallStructureForCallLog.prev_state == CM_OUTGOING_STATE)))
    {
        /*memcpy(
            &cm_p->state_info.CallStructureForCallLog.num,
            &cm_p->state_info.CallStructureForCallLog.number,
            sizeof(cm_p->state_info.CallStructureForCallLog.num));*/
        LogCallWithStartTime(&cm_p->state_info.CallStructureForCallLog);
    }
}


/*****************************************************************************
 * FUNCTION
 *  LogCallWithStartTime
 * DESCRIPTION
 *  Logs Call with Start Time
 * PARAMETERS
 *  log     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void LogCallWithStartTime(CALL_INFO *log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CM_CALL_MO == log->orgination_flag)
    {
        CHISTLogDialedCall(log);
    }
    else if (CM_CALL_MT == log->orgination_flag)
    {
        CHISTLogRecvdCall(log);
    }
    else
    {
        PRINT_INFORMATION(" XXX In LogCallWithStartTime, no need to log\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEndTimeAndNotifyCallAborted
 * DESCRIPTION
 *  Sets Call Back for Call Aborted Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetEndTimeAndNotifyCallAborted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CMGetExactTime(GetDateTimeAndNotifyCallAbortedCBack);
}


/*****************************************************************************
 * FUNCTION
 *  GetDateTimeAndNotifyCallAbortedCBack
 * DESCRIPTION
 *  Call Back Called after End Time For Call Aborted Retrieved
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetDateTimeAndNotifyCallAbortedCBack(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, t, sizeof(MYTIME));
    memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, t, sizeof(MYTIME));

    LogCall();
#ifdef __MMI_CM_CCBS_SUPPORT__ /*Mick 2007/02/26*/
#else
    if (GetActivatedCcbsFlag() != TRUE)
#endif /*__MMI_CM_CCBS_SUPPORT__*/
        EntryScrNotifyCallAborted();
}


/*****************************************************************************
 * FUNCTION
 *  GetEndTimeAndNotifyCallMissed
 * DESCRIPTION
 *  Sets Call Back for Call Missed Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetEndTimeAndNotifyCallMissed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* don't log ccbs call */
#ifdef __MMI_CM_CCBS_SUPPORT__
    if(GetCCBSFlag() == FALSE || GetCCBSHandle()!= -1)
#else
    if (GetCCBSFlag() == FALSE)
#endif /*__MMI_CM_CCBS_SUPPORT__*/
    {
    	MYTIME t;

        DTGetRTCTime(&t);
        memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, &t, sizeof(MYTIME));
        memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, &t, sizeof(MYTIME));

        CHISTLogMissedCall(&cm_p->state_info.CallStructureForCallLog);
    }
    CMGetExactTime(GetDateTimeAndNotifyCallMissedCBack);
}


/*****************************************************************************
 * FUNCTION
 *  GetDateTimeAndNotifyCallMissedCBack
 * DESCRIPTION
 *  Call Back Called after End Time For Call Missed Retrieved
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetDateTimeAndNotifyCallMissedCBack(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCallEndedBeforeConnFlag(TRUE);
    memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, t, sizeof(MYTIME));
    memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, t, sizeof(MYTIME));
    SetMissedCallFlag(TRUE);
#ifdef __MMI_CM_CCBS_SUPPORT__
#else
    if (GetActivatedCcbsFlag() != TRUE)
#endif /*__MMI_CM_CCBS_SUPPORT__*/
        EntryScr1004NotifyEndCallDuration();

    /* CHISTLogMissedCall(&cm_p->state_info.CallStructureForCallLog); */
}


/*****************************************************************************
 * FUNCTION
 *  GetEndTimeAndLogUnconnectedMOCall
 * DESCRIPTION
 *  Sets Call Back for MO Unconnected Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetEndTimeAndLogUnconnectedMOCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CMGetExactTime(GetDateTimeAndLogUnconnectedMOCallCBack);
}


/*****************************************************************************
 * FUNCTION
 *  GetDateTimeAndLogUnconnectedMOCallCBack
 * DESCRIPTION
 *  Call Back Called after End Time For Unconnected MO Call Retrieved
 * PARAMETERS
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetDateTimeAndLogUnconnectedMOCallCBack(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, t, sizeof(MYTIME));
    memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, t, sizeof(MYTIME));
    LogCall();
}


/*****************************************************************************
 * FUNCTION
 *  GetEndTimeAndNotifyEndCallDuration
 * DESCRIPTION
 *  Sets Call Back for End Time Notify Screen
 * PARAMETERS
 *  handle      [IN]        
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void GetEndTimeAndNotifyEndCallDuration(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        &gTimeStructForEndedCallStartTime,
        &(cm_p->state_info.AllCalls[GetMMIStructIndexof(handle)].start_time),
        sizeof(MYTIME));

    memset(&temp, 0, sizeof(MYTIME));
    /* call end too fast before the call start time is recorded */
    if (!(memcmp(&gTimeStructForEndedCallStartTime, &temp, sizeof(MYTIME)) == 0))
    {
        DTGetRTCTime(&(cm_p->state_info.CallStructureForCallLog.end_time));
        if (CM_CALL_MO == cm_p->state_info.CallStructureForCallLog.orgination_flag)
        {
            CHISTLogDialedCallDuration(&cm_p->state_info.CallStructureForCallLog);
        }
    #ifdef __SAT__
        else if (CM_CALL_MO_STK == cm_p->state_info.CallStructureForCallLog.orgination_flag)
        {
            CHISTLogDialedCallDuration(&cm_p->state_info.CallStructureForCallLog);
        }
    #endif /* __SAT__ */
        else if (CM_CALL_MT == cm_p->state_info.CallStructureForCallLog.orgination_flag)
        {
            CHISTLogRecvdCallDuration(&cm_p->state_info.CallStructureForCallLog);
        }
    }
    
    CMGetExactTime(GetDateTimeAndNotifyEndCallDurationCBack);
}


/*****************************************************************************
 * FUNCTION
 *  GetDateTimeAndNotifyEndCallDurationCBack
 * DESCRIPTION
 *  Call Back Called after End Time For Call Retrieved
 * PARAMETERS
 *  t           [?]         
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void GetDateTimeAndNotifyEndCallDurationCBack(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&temp, 0, sizeof(MYTIME));

    /* call end too fast before the call start time is recorded */
    if (memcmp(&gTimeStructForEndedCallStartTime, &temp, sizeof(MYTIME)) == 0)
    {
        memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, t, sizeof(MYTIME));
        memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, t, sizeof(MYTIME));
        memset(&gTimeStructForCallDuration, 0, sizeof(MYTIME));
        memcpy(
            &cm_p->state_info.CallStructureForCallLog.num,
            &cm_p->state_info.CallStructureForCallLog.number,
            sizeof(cm_p->state_info.CallStructureForCallLog.num));
        LogCallWithStartTime(&cm_p->state_info.CallStructureForCallLog);
    }
    else
    {
        /* overflow 2030/12/31/23:59:59 */
        if (gTimeStructForEndedCallStartTime.nYear == 2030 && 
            t->nYear < gTimeStructForEndedCallStartTime.nYear)
        {
            t->nYear = gTimeStructForEndedCallStartTime.nYear;
            t->nMonth = gTimeStructForEndedCallStartTime.nMonth;
            t->nDay = gTimeStructForEndedCallStartTime.nDay+1;
        }
        if (NULL == GetTimeDifference(t, &gTimeStructForEndedCallStartTime, &gTimeStructForCallDuration))
        {
            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_ERROR_CallEnd);
            PRINT_INFORMATION("\nCall Handle: %d", cm_p->state_info.CallStructureForCallLog.call_handle);
            PRINT_INFORMATION("\nCall Current State: %d", cm_p->state_info.CallStructureForCallLog.curr_state);
            PRINT_INFORMATION("\nCall Previous State: %d", cm_p->state_info.CallStructureForCallLog.prev_state);
            PRINT_INFORMATION("\nCall Origin: %d", cm_p->state_info.CallStructureForCallLog.orgination_flag);
            PRINT_INFORMATION("\nStart Time : Hour:%d ,Min:%d ,Sec:%d ", gTimeStructForEndedCallStartTime.nHour,
                               gTimeStructForEndedCallStartTime.nMin, gTimeStructForEndedCallStartTime.nSec);
            PRINT_INFORMATION("\nEnd Time : Hour:%d ,Min:%d ,Sec:%d ", t->nHour, t->nMin, t->nSec);
        }

        memcpy(&cm_p->state_info.CallStructureForCallLog.start_time, &gTimeStructForEndedCallStartTime, sizeof(MYTIME));
        //memcpy(&cm_p->state_info.CallStructureForCallLog.end_time, t, sizeof(MYTIME));
        //LogCall();        
    }

    EntryScr1004NotifyEndCallDuration();
    memset(&cm_p->state_info.CallStructureForCallLog, 0, sizeof(CALL_INFO));
}


/*****************************************************************************
 * FUNCTION
 *  CheckCtrExpiry
 * DESCRIPTION
 *  Checks if call-time reminder tone is
 *  to be played
 * PARAMETERS
 *  void
 *  Time(?)     [IN]        Structure t
 * RETURNS
 *  void
 *****************************************************************************/
void CheckCtrExpiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, *start_time, duration;
    U32 duration1, duration2;
    U8 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(CM_CTR_TIMER, 1000, CheckCtrExpiry);

    DTGetRTCTime(&curr_time);
    start_time = GetStartCallTime();
    if (start_time == NULL)
    {
        return;
    }
    GetTimeDifference(&curr_time, start_time, &duration);

    duration1 =
        cm_p->alert_info.LastCTRTime.nHour * 60 * 60 + cm_p->alert_info.LastCTRTime.nMin * 60 +
        cm_p->alert_info.LastCTRTime.nSec;
    duration2 = duration.nHour * 60 * 60 + duration.nMin * 60 + duration.nSec;

#ifdef __MMI_CH_QUICK_END__
    if (cm_p->alert_info.QuickEndTime > 0 &&
        cm_p->alert_info.QuickEndTime != 0xffff && cm_p->alert_info.QuickEndTime <= duration2)
    {
        StopTimer(CM_CTR_TIMER);
        if (!(GetTotalCallCount() == 1 &&
              (GetCurrentState() == CM_INCOMING_STATE || GetCurrentState() == CM_OUTGOING_STATE)) &&
              !EmergencyCallPresent())
        {
            KbCBackEndAllCallsExceptIncoming();
        }
        return;
    }
#endif /* __MMI_CH_QUICK_END__ */ 

    status = GetCtrStatus();
    if ((status != CTR_OFF) && (duration1 <= duration2))
    {
        if (status == CTR_PERIODIC)
        {
            if ((cm_p->alert_info.LastCTRTime.nSec < gCtrTime) &&
                ((gCtrTime <= duration.nSec) || (cm_p->alert_info.LastCTRTime.nSec > duration.nSec)))
            {
                playRequestedTone(CALL_REMINDER_TONE);
            }
        }
        else
        {
            if (duration1 < gCtrTime && gCtrTime <= duration2)
            {
                if (cm_p->alert_info.QuickEndTime == 0)
                {
                    StopTimer(CM_CTR_TIMER);
                }
                playRequestedTone(CALL_REMINDER_TONE);
            }
        }
    }
    memcpy(&cm_p->alert_info.LastCTRTime, &duration, sizeof(MYTIME));
}


/*****************************************************************************
 * FUNCTION
 *  InitializeTimeStructure
 * DESCRIPTION
 *  Function gets the initialize the time structure before displaying the call
 * PARAMETERS
 *  time        [IN]        Time strucutre to initialize
 *  t           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeTimeStructure(TIMEANDINDEX *time, MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME tmpTime;
    TIMEANDINDEX tmpTimeBuf;
    TIMEANDINDEX tmpArr[MAX_CALLS];
    U8 validTimes = 0;
    U8 count;
    U8 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmpArr, 0, (sizeof(TIMEANDINDEX) * MAX_CALLS));
    memcpy(&tmpTime, t, sizeof(tmpTime));

    for (count = 0; count != MAX_CALLS; count++)
    {
        // Start by Julia: Drop call refinement - add CM_DISCONNECTING_STATE condition
        // first get diff of all times
        if (cm_p->state_info.AllCalls[count].call_handle != -1 &&
            (cm_p->state_info.AllCalls[count].curr_state == CM_ACTIVE_STATE ||
             cm_p->state_info.AllCalls[count].curr_state == CM_HOLD_STATE ||
             cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE))
            /* End by Julia */
        {
            if (GetTimeDifference(&tmpTime, &cm_p->state_info.AllCalls[count].start_time, &(tmpArr[validTimes].time)) !=
                NULL)
            {
                tmpArr[validTimes].index = count;
                validTimes++;
            }
        }
    }

    for (count = 0; count < validTimes - 1; count++)
    {
        for (j = 0; j < validTimes - 1 - count; j++)
        {
            if (FindMaxTime(&tmpArr[j].time, &tmpArr[j + 1].time))
            {
                memcpy(&tmpTimeBuf, &tmpArr[j], sizeof(tmpTimeBuf));
                memcpy(&tmpArr[j], &tmpArr[j + 1], sizeof(tmpTimeBuf));
                memcpy(&tmpArr[j + 1], &tmpTimeBuf, sizeof(tmpTimeBuf));
            }
        }
    }
    memcpy(time, &tmpArr[validTimes - 1], sizeof(tmpArr[validTimes - 1]));
    cm_p->state_info.OldestCallIndex = time->index;

    if ((GetCtrStatus() != CTR_OFF && cm_p->alert_info.IsCTRStart == FALSE)
#ifdef __MMI_CH_QUICK_END__
        || cm_p->alert_info.QuickEndTime > 0
#endif 
        )
    {
        /* start call time reminder timer */
        cm_p->alert_info.IsCTRStart = TRUE;
        if (IsMyTimerExist(CM_CTR_TIMER) == MMI_FALSE)
        {
            StartTimer(CM_CTR_TIMER, 1000, CheckCtrExpiry);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetStartCallTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MYTIME *GetStartCallTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->state_info.AllCalls[cm_p->state_info.OldestCallIndex].call_handle == -1)
    {
        TIMEANDINDEX timeStruct;
        MYTIME t;

        DTGetRTCTime(&t);
        InitializeTimeStructure(&timeStruct, &t);
        if (GetTotalCallCount() == 0)
        {
            return NULL;
        }
    }
    return &(cm_p->state_info.AllCalls[cm_p->state_info.OldestCallIndex].start_time);
}


/*****************************************************************************
 * FUNCTION
 *  SetPriorityCall
 * DESCRIPTION
 *  Sets the Priority Call Option
 * PARAMETERS
 *  priority        [IN]        
 *  True(?)         [IN]        If the call is a priority call
 * RETURNS
 *  void
 *****************************************************************************/
void SetPriorityCall(pBOOL priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPriority = priority;
}


/*****************************************************************************
 * FUNCTION
 *  GetPriorityCall
 * DESCRIPTION
 *  Gets the current priority status
 * PARAMETERS
 *  void
 *  TRUE(?)     [IN]        For set FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetPriorityCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPriority;
}


/*****************************************************************************
 * FUNCTION
 *  SetDialedDigitCalledFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetDialedDigitCalledFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gDialedDigitCalledFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetDialedDigitCalledFlag
 * DESCRIPTION
 *  Gets the ActiveToHold Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetDialedDigitCalledFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gDialedDigitCalledFlag;
}


/*****************************************************************************
 * FUNCTION
 *  SetSATScrnSavedFlag
 * DESCRIPTION
 *  Sets SAT Screen Saved Flag
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetSATScrnSavedFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATScrnSavedFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetSATScrnSavedFlag
 * DESCRIPTION
 *  Returns SAT Screen Saved Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetSATScrnSavedFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gSATScrnSavedFlag;
}

#endif /* __MMI_UCM__ */