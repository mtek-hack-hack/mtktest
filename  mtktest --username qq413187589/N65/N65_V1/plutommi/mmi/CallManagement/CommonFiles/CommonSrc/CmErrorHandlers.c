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
 *   CmErrorHandlers.c
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CmErrorHandlers.c

   PURPOSE     : Call Management error handlers

   REMARKS     : nil

   AUTHOR      : Gupta Ashish

   DATE     : Apr 07, 03

**************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__


#include "ProfileGprots.h"

#include "CallManagementIdDef.h"
#include "CmErrorTypes.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CommonStubsProt.h"
#include "HistoryHelperProt.h"
#include "RedialHelperGProt.h"
#include "CallManagementGprot.h"
#include "OutgoingCallManagementProt.h"

#include "CmErrorHandlersProt.h"
#include "CommonScreens.h"      /* for popup window timer. */

#include "gpioInc.h"

/*****************************************************************************
 * FUNCTION
 *  ProcessIncomingFailureEvents
 * DESCRIPTION
 *  This function handles all the failure conditions in call management.
 * PARAMETERS
 *  event           [IN]        
 *  cause           [IN]        
 *  Incoming(?)     [IN]        Event Type, Any information associated with the event
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessIncomingFailureEvents(CM_EVENT_TYPES event, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ProcessIncomingFailureEvents);

    switch (event)
    {
        case CM_PS_HELD_CALL_ACTIVE:
        case CM_PS_ACTIVE_CALL_HELD:
        case CM_PS_INCOMING_CALL_CONNECTED:
            /* fail to answer incoming call or waiting call */
            //No need to modify state machine in case of ERROR
            //ProcessIncomingFailureCallEvent(cause);
            ShowCallManagementErrorMessage(cause);
            break;

        case CM_PS_INCOMING_CALL_DEFLECT:
        case CM_PS_ACTIVATED_CCBS:
        case CM_PS_CCBS_INVOKE_DIAL:
            ShowCallManagementErrorMessage(cause);
            break;

        default:
            ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE);
            PRINT_INFORMATION("File: [%s]  Line: [%d] <<Not Valid State Machine event>>\n", __FILE__, __LINE__);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  OutgoingProcessCMFailureEvent
 * DESCRIPTION
 *  This is the Entry function for all the Events while the Call-Management application
 *  is Active.
 *  
 *  This function handles the events from both keyboard and protocol stack.
 *  The keyboard events have KB in there defination and Protocol has PS.
 * PARAMETERS
 *  inEvenType      [IN]        
 *  cause           [IN]        
 *  void(?)         [IN]        *(pointer to the event's associated structure)
 * RETURNS
 *  void
 *****************************************************************************/
void OutgoingProcessCMFailureEvent(CM_EVENT_TYPES inEvenType, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_OutgoingProcessCMFailureEvent);
    switch (inEvenType)
    {
        case CM_PS_CALLCONNECTED:
            /* fail in ss_parse_rsp, dial_ind, connect_ind or
               got release_ind before connect */
            ProcessPSCallConnectFailEvent(cause);
            break;

        case CM_PS_HOLDSUC:     /* hold fail */
        case CM_PS_RETRIEVESUC: /* retreive fail */
        case CM_PS_SWAPSUC:     /* swap fail */
        case CM_PS_CONFSUC:     /* conference fail */
        case CM_PS_SPLITSUC:    /* split fail */
        case CM_PS_ECT_SUC:     /* ECT fail */
            ShowCallManagementErrorMessage(cause);
            break;

        default:
            PRINT_INFORMATION("\n CM Event Handler does not exist \n");
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ProcessPSCallConnectFailEvent
 * DESCRIPTION
 *  This is the function to process Protocol(Response) failure Event.
 * PARAMETERS
 *  cause       [IN]        
 *  void(?)     [IN]        *(this points to CM_CALL_HANDLE of the call which requested CM_KB_OUTGOINGCALL)
 * RETURNS
 *  void
 *****************************************************************************/
void ProcessPSCallConnectFailEvent(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE callHandle;
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetCCFlag() == TRUE)
    {
        callHandle = GetOutgoingCallHandle();

        if (callHandle == -1)
        {
            PRINT_INFORMATION("\n ProcessPSCallConnectFailEvent Getting the Connected Handle has -1 \n");
            return;
        }

        switch (GetCurrentState())
        {
                /* amanda add 0326, MO MT collision */
            case CM_INCOMING_STATE:
                PurgeOutgoingCallsStructure();
                cause = 0;
                break;

            case CM_OUTGOING_STATE:
                type = GetOutgoingCallType();
                PurgeOutgoingCallsStructure();
                SetCurrentState(GetPreviousState());
                SetPreviousState(CM_OUTGOING_STATE);
                if (GetTotalCallCount() == 0)
                {
                    /* only voice call can redial */
                    if ((type != CM_VOICE_CALL) || (IsRedialNeeded(cause) == FALSE))
                    {
                        /* no need to redial, just show error and get out of CM */
                        ShowCallManagementErrorMessage(cause);
                        GetOutOfCMforAdjustHistory();
                        return;
                    }
                    else
                    {
                        /* need to redial, show error and redial */
                        if (IsRedialSet())
                        {
                            SetCallEndedBeforeConnFlag(FALSE);
                            CheckRedialOrShowError(cause);
        					/* abort SS if needed */
                            DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
                            return;
                        }
                    }
                }
                /* still have other call, can't redial, just show error */
                break;

            default:
                PRINT_INFORMATION("\n ProcessPSCallConnectFailEvent CM State m/c Corrupted \n");
                break;
        }
    }
    ShowCallManagementErrorMessage(cause);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCallManagementErrorMessage
 * DESCRIPTION
 *  This function shows the failure in case of call management
 *  
 *  This is a part of other hardware application.
 * PARAMETERS
 *  cause       [IN]        
 *  TRUE(?)     [OUT]       Or FALSE
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void ShowCallManagementErrorMessage(U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code, img_id = IMG_ERROR_NOTIFY;
    U16 tone_id = ERROR_TONE_IN_CALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ShowCallManagementErrorMessage);

    if (GetCallEndCause() == 0)
    {
        SetCallEndCause(cause);
    }
    SetCbackAfterSS(NULL);
    if (GetNotifySSFlag())
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ShowErrorAfterNotifySS);
        SetCbackAfterSS((FuncPtr) ShowCallManagementErrorMessage);
        return;
    }

    EntryNewScreen(CM_SCR_ERR_MSG, ExitScrCMErrMsg, NULL, NULL);

    switch (GetCallEndCause())
    {
        case ERR_UNASSIGNED_NUM:
        	tone_id = NUM_UNOBTAIN_TONE;
        case ERR_INVALID_NUMBER_FORMAT:
            error_code = ERROR_UNRECOGNIZED_NUMBER;
            break;

        case ERR_SWITCH_EQUIPMENT_CONGESTION:
			tone_id = CONGESTION_TONE;
        case ERR_CALL_REJECTED:
			tone_id= AUTH_FAIL_TONE;
        case ERR_NO_ROUTE_TO_DESTINATION:
        case ERR_DEST_OUT_OF_ORDER:
        case ERR_FACILITY_REJECT:
        case ERR_TEMPORARY_FAILURE:
        case ERR_SER_UNAVAILABLE:
        case ERR_BEARER_SER_UNIMPL:
        case ERR_INVALID_TI_VALUE:
        case ERR_USER_NOT_IN_CUG:
        case ERR_INCOMPATIBLE_DEST:
        case ERR_SEMANTIC_ERR:
        case ERR_INTER_WRK_UNSPECIFIED:
        case ERR_CSMCC_ILLEGAL_CALL_ID:
        case ERR_CSMCC_CALL_ALLOC_FAIL:
        case ERR_CSMCC_BC_FILL_FAIL:
        case ERR_CSMCC_ILLEGAL_BC:
        case ERR_CSMCC_MODIFY_ACTUAL_MODE:
        case ERR_CSMCC_DATA_ACT_FAIL:
        case ERR_MAC_FAILURE:
        case ERR_SYNC_FAILURE:
        case ERR_CONGESTION:
        case ERR_ILLEGAL_MS:
        case ERR_ILLEGAL_ME:
        case ERR_CM_MM_CM_ENQUEUE_FAIL:
        case ERR_CM_MM_NOT_UPDATED:
        case ERR_CM_MM_STATE_NOT_ALLOWED_CM:
            error_code = ERROR_FAIL;
            break;

        case ERR_CHANNEL_UN_ACCP:
        case ERR_NO_CIRCUIT_CHANNEL_AVAIL:
        case ERR_NETWORK_OUT_OF_ORDER:
        case ERR_QOS_UNAVAIL:
        case ERR_INVALID_TRANSIT_NW_SEL:
        case ERR_CSMCC_NO_RESPONSE_FROM_NW:
        case ERR_NETWORK_FAILURE:
        case ERR_CM_MM_RR_CONN_RELEASE:
        case ERR_CM_SS_SYSTEMFAILURE:
            error_code = ERROR_NETWORK_FAIL;
            break;

        case ERR_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case ERR_RESOURCE_UNAVAIL_UNSPECIFIED:
        case ERR_CM_MM_AUTH_FAILURE:
            error_code = ERROR_NETWORK_NOT_AVAILABLE;
            break;

        case ERR_OPR_DTR_BARRING:
        case ERR_CALL_BARRED:
        case ERR_IC_BAR_CUG:
        case ERR_BEARER_CAP_NOT_AVAIL:
        case ERR_CM_MM_ACCESS_BARRED:
            error_code = INCOMING_DEFAULT_ERROR;
            break;

        case ERR_USER_BUSY:
        {
            /* voice call shows user busy, csd call shows network busy */
            if (cm_p->state_info.CallStructureForCallLog.call_type == CM_VOICE_CALL)
            {
                error_code = ERROR_USER_BUSY;
            }
            else
            {
                error_code = ERROR_BUSY_NETWORK;
            }
        }
            break;

        case ERR_NO_USER_RESPONDING:
            error_code = ERROR_NOT_RESPONDING;
            break;

        case ERR_NO_ANSWER_ON_ALERT:
            error_code = ERROR_NO_ANSWER;
            break;

        case ERR_ACM_EXCEEDED:
            error_code = ERROR_ACM_EXCEEDED;
            break;

        case ERR_REQ_FACILITY_UNAVAIL:
        case ERR_IE_NOT_IMPLEMENTED:
        case ERR_CONDITIONAL_MM_IE_ERROR:
        case ERR_CM_MM_ASSIGNMENT_REJECT:
            error_code = ERROR_UNAVAILABLE;
            break;

        case ERR_CSMCC_ILLEGAL_DTMF_TONE:
        case ERR_CSMCC_CALL_ACCEPT_NOT_ALLOW:
        case ERR_MS_ID_NOT_DERIVED_BY_NW:
        case ERR_IMPLICIT_DETACH:
        case ERR_MSG_NOT_COMPAT_WITH_PROTO_STATE:
        case ERR_PROTO_ERROR_UNSPECIFIED:
            error_code = ERROR_UNEXPECTED_ERROR;
            break;

        case ERR_IMSI_UNKNOWN_IN_HLR:
        case ERR_IMSI_UNKNOWN_IN_VLR:
        case ERR_CM_MM_IMSI_DETACH:
            error_code = ERROR_IMSI_UNKNOWN;
            break;

        case ERR_IMEI_NOT_ACCEPTED:
            error_code = ERROR_IMEI_ERROR;
            break;

        case ERR_GPRS_NOT_ALLOWED:
        case ERR_GPRS_NON_GPRS_NOT_ALLOWED:
            error_code = ERROR_GPRS_NOT_ALLOWED;
            break;

        case ERR_CM_MT_DATA_CALL:
            error_code = ERROR_MT_DATA_CALL;
            break;

        case ERR_REQ_FAC_NOT_SUBS:
        case ERR_PLMN_NOT_ALLOWED:
        case ERR_LOCATION_AREA_NOT_ALLOWED:
        case ERR_ROAMING_AREA_NOT_ALLOWED:
        case ERR_GPRS_NOT_ALLOWED_IN_PLMN:
        case ERR_NO_SUITABLE_CELLS_IN_LA:
        case ERR_MSC_TEMP_NOT_REACHABLE:
        case ERR_CM_MM_ABORT_BY_NW:
            /* case ERR_CM_MM_STATE_NOT_ALLOWED_CM: */
        case ERR_BEARER_CAP_NOT_AUTHORISED:
            error_code = ERROR_NETWORK_NOT_ALLOWED;
            break;

        case ERR_CSMCC_CMD_NOT_ALLOW:
        case ERR_SERV_OPTION_NOT_SUPPORTED:
        case ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED:
        case ERR_SERV_OPTION_TEMP_OUT_OF_ORDER:
        case ERR_CALL_CANNOT_BE_IDENTIFIED:
            error_code = ERROR_COMMAND_NOT_SUPPORTED;
            break;

        case ERR_NO_PDP_CONTEXT_ACTIVATED:
        case ERR_SEMANTICALLY_INCORRECT_MSG:
        case ERR_INVALID_MM_MAND_INFO:
            error_code = ERROR_DATA_ERROR;
            break;

        case ERR_MSG_TYPE_NON_EXISTENT:
        case ERR_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE:
            error_code = ERROR_MESSAGE_TYPE_ERROR;
            break;

        case ERR_ACCESS_CLASS_BARRED:
        case ERR_CM_MM_RANDOM_ACCES_FAILURE:
            error_code = ERROR_ACCESS_FAIL;
            break;

        case ERR_CM_MM_CONN_TIMEOUT:
            error_code = ERROR_TIMER_EXPIRED;
            break;

        case ERR_NORMAL_CALL_CLR:
        case ERR_NORMAL_UNSPECIFIED:
            error_code = STR_CALL_ENDED;
            img_id = IMG_CM_STATE_ENDED;
            break;
        case ERR_L4C_USSD_ABORT:
            error_code = ERROR_USSD_ABORTED;
            break;
        case ERR_CM_MM_RR_NO_SERVICE:
        case ERR_CM_MM_NO_SERVICE:
        case ERR_RESERVED:
        case ERR_NUMBER_CHANGED:
        case ERR_PRE_EMPTION:
        case ERR_NON_SEL_USER_CLEAR:
        case ERR_RES_STATUS_ENQ:
        case ERR_ACCESS_INFO_DISCARDED:
        case ERR_RESTR_DIGITAL_INFO:
        case ERR_SER_OPT_UNIMPL:
        case ERR_INVALID_MANDATORY_INF:
        case ERR_MSG_TYPE_UNIMPL:
        case ERR_MSG_TYPE_NOT_COMPATIBLE:
        case ERR_IE_NON_EX:
        case ERR_COND_IE_ERR:
        case ERR_INCOMP_MESG_WITH_STATE:
        case ERR_RECOVERY_ON_TIMER_EXPIRY:
        case ERR_PROTOCOL_ERR_UNSPECIFIED:
        case ERR_CSMCC_CALL_RE_EST:
        case ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN:
        case ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX:
        case ERR_CM_MM_CAUSE_NONE:
        case ERR_L4C_GEN_CAUSE:
            error_code = INCOMING_DEFAULT_ERROR;
            break;

        case ERR_L4C_FDN_FAIL:
            error_code = ERROR_FDN_FAIL;
            break;

        case NO_ACTIVE_CALL:
            error_code = ERROR_INVALID_COMMAND;
            break;

        case ERR_CM_UNKNOWN:
            error_code = INCOMING_UNKNOWN_ERROR;
            break;

        default:
            error_code = INCOMING_DEFAULT_ERROR;
            break;
    }   /* End of Switch */

    ShowCategory62Screen(error_code, img_id, NULL);

    TurnOnBacklight(1);

    SetCallEndCause(0);

    if (GetTotalActiveCallCount() == 0 && GetTotalHoldCallCount() == 0)
    {
        /* only play error tone when not in-call */
        playRequestedTone(tone_id);
        SetErrorToneFlag(tone_id);
    }

    if (cm_p->redial_info.RedialTimer == TRUE)
    {
        /* cannot press key before pop up disappear,
           buy more time for call log writing */
        DeleteSubLCDScreen(SUB_LCD_SCR1001_CM_OUTGOINGCALLSCREEN);
        GoBackSubLCDHistory();
        if (IsScreenPresent(CM_SCR_MARKER))
        {
            DeleteUptoCmScreen();
        }
        DeleteScreenIfPresent(CM_SCR_MARKER);
        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetPOPUpFlag(TRUE);
        SetKeyHandler(ResetRedialAndGoBack, KEY_END, KEY_EVENT_DOWN);
        cm_p->redial_info.ErrRedialScreen = TRUE;
        StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, ShowRedialScreen);
    }
    else
    {
        /* cannot press key before pop up disappear,
           buy more time for call log writing */
        ClearInputEventHandler(MMI_DEVICE_ALL);
        SetKeyHandler((FuncPtr) GoBackfromNotifyScr, KEY_END, KEY_EVENT_DOWN);
        SetPOPUpFlag(TRUE);
        StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackfromNotifyScr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitScrCMErrMsg
 * DESCRIPTION
 *  Exit handler for the error pop up screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrCMErrMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_ExitScrCMErrMsg);

    if (GetErrorToneFlag() > 0)
    {
        stopRequestedTone(GetErrorToneFlag());
        SetErrorToneFlag(0);
    }
    StopTimer(CM_NOTIFYDURATION_TIMER);

    if (cm_p->redial_info.RedialTimer == TRUE)
    {
        /* in redial process */
        if (cm_p->redial_info.ErrRedialScreen == TRUE)
        {
            /* error msg got interrupted */
            history Scr1009;
            S16 nHistory = 0;

            MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_ExitScrCMErrMsgRedial);

            Scr1009.scrnID = CM_SCR_RDL_TIME;
            Scr1009.entryFuncPtr = EntryScrShowUserTimeToRedial;
            mmi_ucs2cpy((S8*) Scr1009.inputBuffer, (S8*) & nHistory);
            GetCategoryHistory(Scr1009.guiBuffer);
            AddHistory(Scr1009);
            cm_p->redial_info.ErrRedialScreen = FALSE;
            return;
        }
        else
        {
            /* error msg timer expire => going to Notify Redial Screen */
            return;
        }
    }

    /* SetRedialScreen(FALSE); */

    if (GetPOPUpFlag())
    {
        SetPOPUpFlag(FALSE);
        AdjustHistoryForCM();
    }
}
#endif /* __MMI_UCM__ */