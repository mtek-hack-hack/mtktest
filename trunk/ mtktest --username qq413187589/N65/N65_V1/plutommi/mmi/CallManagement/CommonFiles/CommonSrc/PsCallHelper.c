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
 *   PsCallHelper.c
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
 * Consider "Waiting call -> Incoming call" situation, speech must be turned off.
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : PsCallHelper.c

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG

   DATE     : Nov 12,02

**************************************************************/
#include "MMI_include.h"

#ifndef __MMI_UCM__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "Wgui_status_icons.h"
#include "GSM7BitDefaultAlphabet.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#include "SettingsGexdcl.h"
#include "CallSetup.h"
#include "ManageCallMain.h"
#include "Mdi_datatype.h"
#include "Mdi_audio.h"
#ifdef __MMI_SOUND_RECORDER__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "SoundRecorderDef.h"
#include "SoundRecorderProt.h"
#endif /* __MMI_SOUND_RECORDER__ */ 

#include "CallmanagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CallManagementGprot.h"
#include "CommonStubsProt.h"
#include "CmErrorTypes.h"
#include "CmErrorHandlersProt.h"
#include "PsCallHelperDef.h"
#include "mmiapi_struct.h"
#include "IncomingCallManagementProt.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"

#include "PsCallHelperGprot.h"

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 

#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundGProt.h"
#endif 

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "ddl.h"
#include "jcerror.h"
#include "jdd_tapi.h"
#endif


S8 gUSSDbuf[MAX_DIGITS_USSD * ENCODING_LENGTH];

extern U16 gSSEvent;
extern MMI_BOOL gSSEventNotifyPresent;
extern U16 gSSEventNotify;


/*****************************************************************************
 * FUNCTION
 *  MakePsInitiateCall
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request outgoing call
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  callBack        [?]         
 *  This(?)         [IN]        Contains Telephone number of the outgoing call)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsInitiateCall(U8 *MsgStruct, void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length;
    U8 IPNum[MAX_IP_NUMBER_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MsgStruct)
    {
        ClearKeyEvents();
        SetDialIndication(FALSE);
        memset((PS8) IPNum, 0, MAX_IP_NUMBER_LEN + 1);

    #ifdef __IP_NUMBER__
        if (GetTempUseIPNumber())
        {
            GetCurrIPNumber(IPNum);
        }
    #endif /* __IP_NUMBER__ */ 

    HangupCSDIfPresent();

#ifdef __MMI_USSD_REPLY_UCS2__
        {
            OUTGOING_CALL * p = (OUTGOING_CALL *)MsgStruct;
            if ( p->bIsUcs2 ) {
                length = mmi_ucs2strlen((PS8)p->Number);
                length *= ENCODING_LENGTH;
            } else {
                length = strlen((PS8)p->Number);
            }
        }
#else
        length = strlen((PS8) MsgStruct);
#endif
        MakePsSSVUSSDReq(MsgStruct, (PU8) IPNum, length, (void*)PsCBackSetCallFeatures);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSSVUSSDReq
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request outgoing call
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  IPNum           [?]         
 *  length          [IN]        
 *  callBack        [?]         
 *  This(?)         [IN]        Contains Telephone number of the outgoing call)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSSVUSSDReq(U8 *MsgStruct, U8 *IPNum, U16 length, void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_PARSE_STR *strParse;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    /* PARSE_SS_REQ */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_USSDVSS_REQ;
    Message.oslPeerBuffPtr = NULL;

    if (MsgStruct)
    {
        strParse = (MMI_PARSE_STR*) OslConstructDataPtr(sizeof(MMI_PARSE_STR));
        strParse->length = (U8) length;
        memcpy(strParse->input, MsgStruct, strParse->length);
#ifdef __MMI_USSD_REPLY_UCS2__
        if ( ((OUTGOING_CALL *)MsgStruct)->bIsUcs2 ) 
        {
            int i;
            kal_uint8 c;
            /* convert to big endian*/
            for(i = 0; i < length; i += 2) {
                c = strParse->input[i];
                strParse->input[i] = strParse->input[i+1];
                strParse->input[i+1]  = c;
            }
            strParse->dcs = 0x48;
        } else {
        strParse->dcs = 0x0f;
        }
#else
        strParse->dcs = 0x0f;
#endif
        memset(strParse->ip_string, 0, sizeof(strParse->ip_string));
        memcpy(strParse->ip_string, IPNum, (MAX_IP_NUMBER_LEN + 1));

        Message.oslDataPtr = (oslParaType*) strParse;
    }
    else
    {
        Message.oslDataPtr = NULL;
    }

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_USSDVSS_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  HangupCSDIfPresent
 * DESCRIPTION
 * Drop CSD call before making a GSM call
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void HangupCSDIfPresent()
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
        if (cm_p->state_info.AllCalls[count].call_type == CM_CSD_CALL)
        {
			MakePsEndSelectiveCall((void*)HangupReqSucess, cm_p->state_info.AllCalls[count].call_handle);
        	MakePsReleaseCompleteRequest(cm_p->state_info.AllCalls[count].call_handle);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  MakePsCallAcceptIncoming
 * DESCRIPTION
 *  Makes call to Protcol Stack to Accept Incoming Call
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsCallAcceptIncoming(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    FuncPtr fptrKeyEnd, fptrKeyRsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ATA_REQ */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_INCOMINGCALL_ACCEPT_EVENT;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    /* preserve END and RSK key handler */
    fptrKeyEnd = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    fptrKeyRsk = GetKeyHandler(KEY_RSK, KEY_EVENT_UP);
    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    SetKeyHandler(fptrKeyEnd, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(fptrKeyRsk, KEY_RSK, KEY_EVENT_UP);

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_INCOMINGCALL_ACCEPT_SUCCESS);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsAthRequest
 * DESCRIPTION
 *  Sends ECT request to Protocol stack
 * PARAMETERS
 *  callBack        [?]         
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsAthRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_ATH_REQ *athReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if auto-rejected, the flag will be false and it should not clear key handler */
    if (GetClearKeyFlag() == TRUE)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_clear_pen_handlers();
    #endif 

    }
    else
    {
        SetClearKeyFlag(TRUE);
    }

    /* ATH_REQ */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ATH_REQ;
    Message.oslPeerBuffPtr = NULL;
    athReq = (MMI_ATH_REQ*) OslConstructDataPtr(sizeof(MMI_ATH_REQ));
    Message.oslDataPtr = (oslParaType*) athReq;

    if (GetCallAbortReqSentFlag())
    {
        /* set abort MO flag */
        athReq->op_code = L4C_DISCONNECT_MO;
    }
    else
    {
        athReq->op_code = L4C_DISCONNECT_NONE;
    }

    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        SetAllCallsHangupFlag();
    }
    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_ATH_REQ_SUCCESS);
    OslMsgSendExtQueue(&Message);
    return;
}

/* Start by Julia: Drop call refinement */


/*****************************************************************************
 * FUNCTION
 *  MakePsReleaseCompleteRequest
 * DESCRIPTION
 *  Send relese complete message to L4C to strictly releasae the disconnecting call
 *  
 *  It is for drop call refinement
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsReleaseCompleteRequest(CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_RELCOMP_REQ *relcompReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_RELCOMP_EVENT;
    relcompReq = (MMI_RELCOMP_REQ*) OslConstructDataPtr(sizeof(MMI_RELCOMP_REQ));
    Message.oslDataPtr = (oslParaType*) relcompReq;
    relcompReq->call_id = (U8) handle;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}

/* End by Julia */


/*****************************************************************************
 * FUNCTION
 *  MakePsSendUDUB
 * DESCRIPTION
 *  Makes call to Protcol Stack to Send User Determined User Busy
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSendUDUB(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *udubReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSendUDUB);
    /* if auto-rejected, the flag will be false and it should not clear key handler */
    if (GetClearKeyFlag() == TRUE)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_clear_pen_handlers();
    #endif 
    }
    else
    {
        SetClearKeyFlag(TRUE);
    }
    
    SetChldReqSent(CM_UDUB_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_UDUB_REQ;

    udubReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    udubReq->opcode = CSMCC_REL_HELD_OR_UDUB;

    Message.oslDataPtr = (oslParaType*) udubReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_UDUB_RES_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CheckFailureChld, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsHangupallActiveAcceptOtherRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Hangup of all Active calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]         
 *  request(?)      [IN]        To drop all Active calls)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsHangupallActiveAcceptOtherRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *hangUp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsHangupallActiveAcceptOtherRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    SetChldReqSent(CM_HANGUPALLACTIVE_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ENDALLACTIVE_EVENT;

    hangUp = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    hangUp->opcode = CSMCC_REL_ACTIVE_AND_ACCEPT;

    Message.oslDataPtr = (oslParaType*) hangUp;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_ENDALLACTIVEREQ_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CBackHangupAllActiveAcceptOther, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsEndSelectiveCall
 * DESCRIPTION
 *  Makes call to Protcol Stack to end a Selective Active Call
 *  
 *  The call back registers a handler with the event dynamically
 *  The handle describes the call to end
 * PARAMETERS
 *  callBack        [?]         
 *  handle          [IN]        
 *  U16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsEndSelectiveCall(void *callBack, CM_CALL_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *hangupReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsEndSelectiveCall, handle);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    SetChldReqSent(CM_ENDSELECTIVE_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_CALLENDSPECIFIC_EVENT;

    /* if (GetCurrentState () == CM_OUTGOING_STATE)
       {
       SetKeyHandler(DropRequest,KEY_LSK, KEY_EVENT_UP);
       SetKeyHandler(DropRequest,KEY_END, KEY_EVENT_DOWN);
       } */
    hangupReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    if (GetCurrentState() != CM_OUTGOING_STATE && GetCallState(handle) == CM_ACTIVE_STATE)
    {
        hangupReq->opcode = CSMCC_REL_SPECIFIC_ACTIVE_CALL;
    }
    else
    {
        hangupReq->opcode = CSMCC_REL_SPECIFIC_CALL;
    }
    hangupReq->call_id = (U8) handle;

    Message.oslDataPtr = (oslParaType*) hangupReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_CALLENDSPECIFIC_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CheckFailureChld, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsActiveHold
 * DESCRIPTION
 *  Makes call to Protcol Stack to Retrieve Held Call
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsActiveHold(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *retrReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsActiveHold);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_RETRIEVECALL_EVENT;

    retrReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    retrReq->opcode = CSMCC_HOLD_ACTIVE_AND_ACCEPT;
    Message.oslDataPtr = (oslParaType*) retrReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSplitRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the split of particular call in a group of active calls.
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  nCallHandle     [IN]        
 *  request(?)      [IN]        Is made by sending a particular call's call handle)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSplitRequest(CM_CALL_HANDLE nCallHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *splitReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSplitRequest, nCallHandle);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SPLITCALL_EVENT;

    splitReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    splitReq->opcode = CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL;
    splitReq->call_id = (U8) nCallHandle;

    Message.oslDataPtr = (oslParaType*) splitReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(SplitReqSucess, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsConfCallRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Conference of the calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  void
 *  void(?)     [IN]        (request to Conference i.e all the calls become active)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsConfCallRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *confReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsConfCallRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_CONFCALL_EVENT;

    confReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    confReq->opcode = CSMCC_ADD_HELD_CALL;

    Message.oslDataPtr = (oslParaType*) confReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(ConfReqSucess, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsEctRequest
 * DESCRIPTION
 *  Sends ECT request to Protocol stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsEctRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *ectReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsEctRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ECT_REQ;

    ectReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    ectReq->opcode = CSMCC_EXPLICIT_CALL_TRANSFER;

    Message.oslDataPtr = (oslParaType*) ectReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(EctReqSucess, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsActivateCCBS
 * DESCRIPTION
 *  Makes call to Protcol Stack to Activate CCBS
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsActivateCCBS(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *ccbsReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsActivateCCBS);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_CCBS_ACTIVATE_REQ;

    ccbsReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    ccbsReq->opcode = CSMCC_ACTIVATE_CCBS_CALL;

    Message.oslDataPtr = (oslParaType*) ccbsReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsHangupallRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Hangup of all calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]         
 *  request(?)      [IN]        To drop all the calls)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsHangupallRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *hangUp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsHangupallRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 
    SetChldReqSent(CM_HANGUPALL_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ENDALLCALL_EVENT;

    hangUp = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    hangUp->opcode = CSMCC_REL_ALL_EXCEPT_WAITING_CALL;

    Message.oslDataPtr = (oslParaType*) hangUp;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_ENDALLCALLREQ_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CheckFailureChld, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSwapCallRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Swap of the calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSwapCallRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *swapReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSwapCallRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SWAPCALL_EVENT;

    swapReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    swapReq->opcode = CSMCC_SWAP_CALL;

    Message.oslDataPtr = (oslParaType*) swapReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSendRelHeld
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Release of the held calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSendRelHeld(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *relHeldReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSendRelHeld);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 
    SetChldReqSent(CM_UDUB_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_UDUB_REQ;

    relHeldReq = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    relHeldReq->opcode = CSMCC_REL_HELD;

    Message.oslDataPtr = (oslParaType*) relHeldReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_UDUB_RES_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CheckFailureChld, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsHangupallActiveRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Hangup of all Active calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]         
 *  request(?)      [IN]        To drop all Active calls)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsHangupallActiveRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *hangUp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsHangupallActiveRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 
    SetChldReqSent(CM_HANGUPALLACTIVE_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ENDALLACTIVE_EVENT;

    hangUp = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    hangUp->opcode = CSMCC_REL_ACTIVE;

    Message.oslDataPtr = (oslParaType*) hangUp;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_ENDALLACTIVEREQ_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CBackHangupAllActive, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsHangupallCallsRequest
 * DESCRIPTION
 *  Helper function to Invoke Stack function or pass
 *  the msg structure that can be understandable to Protocol stack.
 *  This is the stack function call to request the Hangup of all calls
 *  
 *  We are currently assuming our own msg structure and passing to NSW Task Queue.
 * PARAMETERS
 *  callBack        [?]         
 *  request(?)      [IN]        To drop all the calls)
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsHangupallCallsRequest(void *callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CC_CHLD_REQ *hangUp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsHangupallCallsRequest);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 
    SetChldReqSent(CM_HANGUPALL_REQ_SENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_ENDALLCALL_EVENT;

    hangUp = (MMI_CC_CHLD_REQ*) OslConstructDataPtr(sizeof(MMI_CC_CHLD_REQ));
    hangUp->opcode = CSMCC_REL_ALL;

    Message.oslDataPtr = (oslParaType*) hangUp;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_ENDALLCALLREQ_SUCCESS);
    SetProtocolEventHandler((PsFuncPtr) CheckFailureChld, PRT_END_CHLD_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsCallDeflect
 * DESCRIPTION
 *  Makes call to Protcol Stack to deflect incoming Call
 *  
 *  The call back registers a handler with the event dynamically
 * PARAMETERS
 *  callBack                [?]         
 *  CallDeflectNumber       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsCallDeflect(void *callBack, PU8 CallDeflectNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CALL_DEFLECT_REQ *calldeflect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsCallDeflect);

    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_clear_pen_handlers();
#endif 

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_CALL_DEFLECT_REQ;

    calldeflect = (MMI_CALL_DEFLECT_REQ*) OslConstructDataPtr(sizeof(MMI_CALL_DEFLECT_REQ));

    if (CallDeflectNumber[0] == '+')
    {
        calldeflect->dest.type = CSMCC_INTERNATIONAL_ADDR;
        strcpy((S8*) calldeflect->dest.number, (S8*) CallDeflectNumber + 1);
    }
    else
    {
        calldeflect->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
        strcpy((S8*) calldeflect->dest.number, (S8*) CallDeflectNumber);
    }

    calldeflect->dest.length = strlen((PS8) calldeflect->dest.number);
    calldeflect->sub_addr_flag = KAL_FALSE;
    memset((void*)&(calldeflect->sub_dest), 0, sizeof(calldeflect->sub_dest));

    Message.oslDataPtr = (oslParaType*) calldeflect;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PRT_CALL_DEFLECT_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsGetCallList
 * DESCRIPTION
 *  Makes call to Protcol Stack to get call list
 * PARAMETERS
 *  callBack        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsGetCallList(void *callBack)
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
    Message.oslMsgId = PTR_GET_CALL_LIST_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler((PsFuncPtr) callBack, PTR_GET_CALL_LIST_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsDropUSSDReq
 * DESCRIPTION
 *  Aborts SS string request
 * PARAMETERS
 *  callBack        [IN]        
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsDropUSSDReq(PsFuncPtr callBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsDropUSSDReq);
    ResetCFCondStage();

    /* Amanda, background abort should not clear key handler */
    if (callBack != NULL)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_clear_pen_handlers();
    #endif 
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SS_STRING_ABORT_REQ;
    Message.oslPeerBuffPtr = NULL;
    Message.oslDataPtr = NULL;

    SetProtocolEventHandler(callBack, PRT_SS_STRING_ABORT_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSendDTMFTone
 * DESCRIPTION
 *  Helper function to start sending a dtmf tone
 * PARAMETERS
 *  MsgStruct       [?]         
 *  U8(?)           [IN]        * This contains digit to send to pstack
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSendDTMFTone(U16 *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MsgStruct)
    {
        MYQUEUE Message;
        MMI_DTMF_DIGIT *dtmf;

        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSendDTMFTone);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_DTMF_START_REQ;

        dtmf = (MMI_DTMF_DIGIT*) OslConstructDataPtr(sizeof(MMI_DTMF_DIGIT));
        dtmf->digit = MapDtmfEnum2Ascii(*MsgStruct);    /* the actuall digit */

        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_MakePsSendDTMFTone, dtmf->digit);

        Message.oslDataPtr = (oslParaType*) dtmf;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsStopDTMFTone
 * DESCRIPTION
 *  Helper function to stop dtmf tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsStopDTMFTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsStopDTMFTone);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_DTMF_STOP_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSendDTMFString
 * DESCRIPTION
 *  Helper function to start sending a dtmf tone
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains digit to send to pstack
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSendDTMFString(U8 *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_DTMF_CONFIRM_REQ *dtmf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsSendDTMFString);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_DTMF_CONFIRM_REQ;

    dtmf = (MMI_DTMF_CONFIRM_REQ*) OslConstructDataPtr(sizeof(MMI_DTMF_CONFIRM_REQ));
    strcpy((void*)dtmf->digit, (void*)MsgStruct);

    Message.oslDataPtr = (oslParaType*) dtmf;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  MakePsReverseSpeechStatusAux
 * DESCRIPTION
 *  Makes call to Protcol Stack to send USSD data to n/w
 *  
 *  The call back registers a handler with the event dynamically
 *  info describes the data to transparently send to n/w
 * PARAMETERS
 *  status      [IN]        
 *  void(?)     [IN]        *, void*
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsReverseSpeechStatusAux(pBOOL speechOn, U8 type)
{
    if (speechOn == KAL_TRUE)
    {
        if (type == MDI_AUDIO_SPEECH_APP_ID_GSM && mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_GSM)
        {
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_GSM);
        }
        else if (type == MDI_AUDIO_SPEECH_APP_ID_WCDMA && mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_WCDMA)
        {
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
        }
        mdi_audio_speech_codec_start(); 
    }
    else
    {
        if ((type == MDI_AUDIO_SPEECH_APP_ID_GSM && 
        	mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_GSM) ||
            (type == MDI_AUDIO_SPEECH_APP_ID_WCDMA && 
            mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_WCDMA))
        {
            mdi_audio_speech_codec_stop(); 
        
            //if ((GetTotalCallCount() == 0 ||(GetTotalCallCount() == 1 && GetCurrentState() == CM_INCOMING_STATE)) && type == MDI_AUDIO_SPEECH_APP_ID_GSM)
            if(type == MDI_AUDIO_SPEECH_APP_ID_GSM)
            {
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
            } 
            //else if ((GetTotalCallCount() == 0 ||(GetTotalCallCount() == 1 && GetCurrentState() == CM_INCOMING_STATE)) && type == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
            else if (type == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
            {
                mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  MakePsReverseSpeechStatus
 * DESCRIPTION
 *  Makes call to Protcol Stack to send USSD data to n/w
 *  
 *  The call back registers a handler with the event dynamically
 *  info describes the data to transparently send to n/w
 * PARAMETERS
 *  status      [IN]        
 *  void(?)     [IN]        *, void*
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsReverseSpeechStatus(pBOOL status, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speechOn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status == TRUE)
    {
        if (GetInternalAlert() == TRUE)
        {
            StopInternalOutgoingTone();
        }
        speechOn = KAL_TRUE;
    }
    else
    {
        speechOn = KAL_FALSE;

    #ifdef __MMI_SOUND_RECORDER__
        mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_GSM, MMI_FALSE);
    #endif
    
        /* Stop background sound effect before speech off */
    #if defined(__MMI_BG_SOUND_EFFECT__)
        mmi_bgsnd_util_switch_speech(MMI_FALSE);
    #endif 
        if (IsPhoneInMute())
        {
            UnMutethePhone();
        }
    }

#if defined(__MMI_BT_SUPPORT__) && !defined(__MMI_BT_PROFILE__)
    /* Turn on/off BT speech channel */
    if (KAL_TRUE == speechOn)
    {
        if (mmi_bt_is_aud2hf() == MMI_TRUE)
        {
            mmi_bt_turn_on_speech_req(KAL_TRUE);
        }

        //mdi_audio_set_speech_mode(KAL_TRUE);
        MakePsReverseSpeechStatusAux(speechOn, type);
    }
    else
    {
        //mdi_audio_set_speech_mode(KAL_FALSE);
        MakePsReverseSpeechStatusAux(speechOn, type);

        if (mmi_bt_is_aud2hf() == MMI_TRUE || mmi_bt_is_incall_aud_swap2bt() == MMI_TRUE)
        {
            mmi_bt_turn_on_speech_req(MMI_FALSE);
        }
    }
#else 
    MakePsReverseSpeechStatusAux(speechOn, type);
    //mdi_audio_set_speech_mode(speechOn);
#endif 

    /* Start background sound effect after speech on */
#if defined(__MMI_BG_SOUND_EFFECT__)
    if (KAL_TRUE == speechOn)
    {
        mmi_bgsnd_util_switch_speech(MMI_TRUE);
    }
#endif /* defined(__MMI_BG_SOUND_EFFECT__) */ 

#ifdef __MMI_SOUND_RECORDER__
    if(KAL_TRUE == speechOn)
    {
        mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_GSM, MMI_TRUE);
    }
#endif /* __MMI_SOUND_RECORDER__ */
}


/*****************************************************************************
 * FUNCTION
 *  MakePsStartVoiceRecord
 * DESCRIPTION
 *  Sends start voice record request to Protocol stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsStartVoiceRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SOUND_RECORDER__
    U8 file_name[60];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_new_file_name((UI_string_type) file_name);
    mdi_audio_start_record((void*)file_name, MDI_FORMAT_GSM_EFR, 0, NULL, (mdi_callback) StartVoiceRecordReqSucess);
    return;
#endif /* __MMI_SOUND_RECORDER__ */ 

#ifdef __MMI_VOICE_MEMO__
    {
        MYQUEUE Message;

        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsStartVoiceRecord);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_START_VOICERECORD_REQ;
        Message.oslPeerBuffPtr = NULL;
        Message.oslDataPtr = NULL;

        SetProtocolEventHandler(StartVoiceRecordReqSucess, PRT_START_VOICERECORD_RSP);
        SetProtocolEventHandler(VoiceRecordFinishHandler, PRT_VOICERECORD_FINISH_IND);
        OslMsgSendExtQueue(&Message);
    }
#endif /* __MMI_VOICE_MEMO__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  MakePsStopVoiceRecord
 * DESCRIPTION
 *  Sends stop voice record request to Protocol stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsStopVoiceRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SOUND_RECORDER__
    mdi_audio_stop_record();
    return;
#endif /* __MMI_SOUND_RECORDER__ */ 

#ifdef __MMI_VOICE_MEMO__
    {
        MYQUEUE Message;

        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_MakePsStopVoiceRecord);

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_STOP_VOICERECORD_REQ;
        Message.oslPeerBuffPtr = NULL;
        Message.oslDataPtr = NULL;

        /* SetProtocolEventHandler (StopVoiceRecordReqSucess,
           PRT_STOP_VOICERECORD_RSP); */
        SetProtocolEventHandler(NULL, PRT_VOICERECORD_FINISH_IND);
        OslMsgSendExtQueue(&Message);
    }
#endif /* __MMI_VOICE_MEMO__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  StartVoiceRecordReqSucess
 * DESCRIPTION
 *  gets the response of Start Voice Record
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Conference request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void StartVoiceRecordReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_StartVoiceRecordReqSucess);

    result = (S32) MsgStruct;

#ifdef __MMI_SOUND_RECORDER__
    if (result == MDI_AUDIO_SUCCESS)
    {
        SetVoiceRecordingFlag(TRUE);
        ShowStatusIcon(STATUS_ICON_VOICE_RECORD);
        UpdateStatusIcons();
    }
    else if (result == MDI_AUDIO_TERMINATED)
    {
        /* do nothing */
    }
    else if (result == MDI_AUDIO_DISC_FULL)
    {
        VoiceRecordFinishHandler(NULL);
        DisplayPopup(
            (U8*) GetString((U16) mmi_sndrec_get_res_string((U8) result)),
            IMG_GLOBAL_UNFINISHED,
            0,
            2000,
            ERROR_TONE_IN_CALL);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString((U16) mmi_sndrec_get_res_string((U8) result)),
            IMG_GLOBAL_UNFINISHED,
            0,
            2000,
            ERROR_TONE_IN_CALL);
    }
    return;
#else /* __MMI_SOUND_RECORDER__ */ 
    {
        mmi_vm_record_rsp_struct *rsp = (mmi_vm_record_rsp_struct*) MsgStruct;

        if (rsp->result)
        {
            SetVoiceRecordingFlag(TRUE);
            ShowStatusIcon(STATUS_ICON_VOICE_RECORD);
            UpdateStatusIcons();
        }
    }
#endif /* __MMI_SOUND_RECORDER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceRecordFinishHandler
 * DESCRIPTION
 *  gets the indication of Voice Record has completed
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Conference request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceRecordFinishHandler(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetVoiceRecordingFlag(FALSE);
    HideStatusIcon(STATUS_ICON_VOICE_RECORD);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  DeriveAndSetCallFeatures
 * DESCRIPTION
 *  Function derives call features such as CUG, CLIP etc.
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL DeriveAndSetCallFeatures(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PARSE_STR_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (MMI_PARSE_STR_RSP*) info;

    SetCCFlag(TRUE);
    //chepi for time being.. dependent on pluto
    //if(L4C_OK==rsp->result.flag)
    if (1 == rsp->result.flag)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveAndSetCallFeatures, rsp->info.opcode);

        if (CC_OPERATION == rsp->info.opcode || SS_OPERATION == rsp->info.opcode || SIM_OPERATION == rsp->info.opcode)
        {
            if (CC_OPERATION != rsp->info.opcode)
            {
                SetCCFlag(FALSE);
            }
            return TRUE;
        }
    }

    SetCCFlag(FALSE);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveOutgoingCallIdRsp
 * DESCRIPTION
 *  Derives call ID for Outgoing call
 * PARAMETERS
 *  info        [?]         
 *  cause       [?]         
 *  Call(?)     [OUT]       ID
 * RETURNS
 *  U8
 *****************************************************************************/
S16 DeriveOutgoingCallIdRsp(void *info, U16 *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DIAL_IND *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (MMI_DIAL_IND*) info;
    if (rsp->result.flag == L4C_OK)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveOutgoingCallIdRsp1, rsp->call_id);
        return rsp->call_id;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveOutgoingCallIdRsp2);
        *cause = rsp->result.cause;
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
		mmi_jdd_tapi_make_call_result(mmi_jdd_tapi_get_makecall_error_code(*cause));
#endif
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeriveCallHandle
 * DESCRIPTION
 *  Derives call ID for End  call
 * PARAMETERS
 *  info        [?]         
 *  Call(?)     [OUT]       ID
 * RETURNS
 *  U8
 *****************************************************************************/
CM_CALL_HANDLE DeriveCallHandle(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (CM_CALL_HANDLE) ((MMI_RELEASE_IND*) info)->call_id;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveCallInfo
 * DESCRIPTION
 *  Makes mapping between L4 strucutre to our strucutre
 * PARAMETERS
 *  info        [?]     
 *  incmg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveCallInfo(void *info, IncomingCall *incmg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_INCOMING *inc;
    U8 flag = 0x10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inc = (MMI_INCOMING*) info;
    memset(incmg, '\0', sizeof(IncomingCall));

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveCallInfo, inc->call_id);

    incmg->callHandle = inc->call_id;
    incmg->callType = inc->call_type;

    if (inc->num.number[0] != '\0')
    {
        if ((flag) & (inc->num.type))
        {
            strcpy((PS8) incmg->Number, "+");
        }
        strcat((PS8) incmg->Number, (PS8) (inc->num.number));
    }

    if ((inc->sub_addr.number[0] != '\0') &&
        (strlen((PS8) inc->sub_addr.number) + strlen((PS8) incmg->Number) < MAX_NUMBER / ENCODING_LENGTH - 1))
    {
        strcat((PS8) incmg->Number, "-");
        strcat((PS8) incmg->Number, (PS8) inc->sub_addr.number);
    }

    if (inc->auto_answer == KAL_TRUE)
    {
        SetPriorityCall(TRUE);
    }
    else
    {
        SetPriorityCall(FALSE);
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  DeriveCcbsCallInfo
 * DESCRIPTION
 *  Makes mapping between L4 strucutre to our strucutre
 * PARAMETERS
 *  info        [?]     
 *  incmg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveCcbsCallInfo(void *info, IncomingCall *incmg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CCBS_IND *inc;
    U8 flag = 0x10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inc = (MMI_CCBS_IND*) info;
    memset(incmg, '\0', sizeof(IncomingCall));

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveCallInfo, inc->call_id);

    incmg->callHandle = inc->call_id;
    incmg->callType = CM_VOICE_CALL;

    if (inc->number_present)
    {
        if ((flag) & (inc->addr.type))
        {
            strcpy((PS8) incmg->Number, "+");
        }
        strcat((PS8) incmg->Number, (PS8) (inc->addr.number));
    }

    if ((inc->sub_addr_present) &&
        (strlen((PS8) inc->sub_addr.number) + strlen((PS8) incmg->Number) < MAX_NUMBER / ENCODING_LENGTH - 1))
    {
        strcat((PS8) incmg->Number, "-");
        strcat((PS8) incmg->Number, (PS8) inc->sub_addr.number);
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  DeriveCallInfoFromWait
 * DESCRIPTION
 *  Makes mapping between L4 strucutre to our strucutre
 * PARAMETERS
 *  info        [?]     
 *  incmg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveCallInfoFromWait(void *info, IncomingCall *incmg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CALL_WAIT *wait;
    U8 flag = 0x10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(incmg, '\0', sizeof(IncomingCall));
    wait = (MMI_CALL_WAIT*) info;

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveCallInfoFromWait, wait->call_id);

    incmg->callType = wait->call_mode;
    incmg->callHandle = wait->call_id;

    if (wait->num.number[0] != '\0')
    {
        if ((flag) & (wait->num.type))
        {
            strcpy((PS8) incmg->Number, "+");
        }
        strcat((PS8) incmg->Number, (PS8) (wait->num.number));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveSSEvent
 * DESCRIPTION
 *  Function derives call features such as CUG, CLIP etc.
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveSSEvent(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_NOTIFY_SS *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (MMI_NOTIFY_SS*) info;
    gSSEvent = rsp->type;
	gSSEventNotifyPresent = rsp->notification_present;
	gSSEventNotify = rsp->notification;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetStrDisplayForId
 * DESCRIPTION
 *  Function derives call features such as CUG, CLIP etc.
 * PARAMETERS
 *  event           [IN]        
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetStrDisplayForId(U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case CSMCC_NOTIFY_CFC:
            return STR_NFY_CALL_FWDNG_CONDITIONAL;
        case CSMCC_NOTIFY_CFU:
            return STR_NFY_CALL_FWDNG_UNCONDITIONAL;
        case CSMCC_NOTIFY_CF_CFU:
            return STR_NFY_CALL_FWDED_UNCONDITIONAL;
        case CSMCC_NOTIFY_CF_CFC:
            return STR_NFY_CALL_FWDED_CONDITIONAL;
        case CSMCC_NOTIFY_CF_CFB:
            return STR_NFY_CALL_BUSY_FORWARDED;
        case CSMCC_NOTIFY_CF_CFNRY:
            return STR_NFY_CALL_FWDED_NOREPLY;
        case CSMCC_NOTIFY_CF_CFNRC:
            return STR_NFY_CALL_FWDED_NOT_REACHABLE;
        case CSMCC_NOTIFY_CF:
            return STR_NFY_CALL_FWDED;

        case CSMCC_NOTIFY_BAC:
            return STR_NFY_CALL_ALL_BARRED;
        case CSMCC_NOTIFY_BAOC:
            return STR_NFY_CALL_ALL_OUTGOING_BARRED;
        case CSMCC_NOTIFY_BAIC:
            return STR_NFY_CALL_ALL_INCOMING_BARRED;
        case CSMCC_NOTIFY_CW:
            return STR_NFY_CALL_WTG;

        case CSMCC_NOTIFY_CALL_HELD:
            return STR_NFY_CALL_HLD;

        case CSMCC_NOTIFY_CALL_RETRIEVED:
            return STR_NFY_CALL_RTVD;

        case CSMCC_NOTIFY_MPTY:
            return STR_NFY_CALL_CONF;

        case CSMCC_NOTIFY_CUG:
            return STR_NFY_CALL_CUG;

        case CSMCC_NOTIFY_ECT_ACTIVE:
            return STR_NFY_CALL_CTFAC;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeriveCcmValue
 * DESCRIPTION
 *  Derives ACM value from the PS value
 * PARAMETERS
 *  info        [?]         
 *  ACM(?)      [IN]        Value struct
 *  U16(?)      [OUT]       
 * RETURNS
 *  U8
 *****************************************************************************/
U32 DeriveCcmValue(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CCM_STRUCT *ccmStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ccmStruct = (MMI_CCM_STRUCT*) info;
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveCcmValue, ccmStruct->ccm);

    if (ccmStruct->warning)
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_DeriveCcmWarning);
    }

    return ccmStruct->ccm;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveInternalAlrtIndVal
 * DESCRIPTION
 *  Derives value of internal Alert indication message
 * PARAMETERS
 *  info            [?]         
 *  Internal(?)     [IN]        Alert Indication structure
 *  Value(?)        [OUT]       (BOOL) of msg
 * RETURNS
 *  U8
 *****************************************************************************/
U8 DeriveInternalAlrtIndVal(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MMI_CC_INTERNAL_ALERT_IND*) info)->alert;
}


/*****************************************************************************
 * FUNCTION
 *  CheckStatusOfSpeech
 * DESCRIPTION
 *  Helper to check is speech is set or not
 *  
 *  The call back registers a handler with the event dynamically
 *  info describes the data to transparently send to n/w
 * PARAMETERS
 *  info                [?]         
 *  Indication(?)       [IN]        Structure
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL CheckStatusOfSpeech(void *info, U8* type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__GSM_RAT__) || defined(__WCDMA_RAT__)
    U8 temp;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *type = MDI_AUDIO_SPEECH_APP_ID_GSM;
#if defined(__GSM_RAT__) || defined(__WCDMA_RAT__) 
    temp = ((MMI_SPEECH_IND*) info)->rat;
    switch (temp)
    {
        case RAT_UMTS:
        	*type = MDI_AUDIO_SPEECH_APP_ID_WCDMA;
        	break;
        default:
        	*type = MDI_AUDIO_SPEECH_APP_ID_GSM;
        	break;
    }
#endif
    return ((MMI_SPEECH_IND*) info)->on_off;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveUSSDData
 * DESCRIPTION
 *  Function derives data in USSN, USSR, and USSD messages
 * PARAMETERS
 *  dcs             [IN]        
 *  ussd_string     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveUSSDData(U8 dcs, U8 length, U8 *ussd_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ussrLen = 0;
    U8 *tempStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    if (dcs == MMI_UCS2_DCS)
    {
        ussrLen = (U16) mmi_ucs2strlen((PS8) ussd_string);
        ussrLen = ussrLen * 2;
    }
    else
    {
        ussrLen = strlen((PS8) ussd_string);
    }
*/
	
	ussrLen = length;

    if (ussrLen >= MAX_DIGITS_USSD)
    {
		if(dcs == MMI_UCS2_DCS)
		{
			ussrLen = MAX_DIGITS_USSD - 2;
		}
		else
		{
			ussrLen = MAX_DIGITS_USSD - 1;
		}
    }

    if (dcs == MMI_8BIT_DCS)
    {
		tempStr = CovertStringForPlatform(ussd_string, ussrLen, dcs, &ussrLen);
    }
    else
    {
        tempStr = OslMalloc(MAX_DIGITS_USSD * ENCODING_LENGTH);
		memset(tempStr, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
		ussd_string[ussrLen] = 0; /*InputboxConvertGSMToDeviceEncoding requirement*/
		ussd_string[ussrLen+1] = 0;
  		InputboxConvertGSMToDeviceEncoding(ussd_string, tempStr, ussrLen, (MAX_DIGITS_USSD * ENCODING_LENGTH), dcs, 0, 1);
    }
  	 
    memset((void*)gUSSDbuf, 0, MAX_DIGITS_USSD * ENCODING_LENGTH);

    if (tempStr != NULL)
    {
        mmi_ucs2ncpy((PS8) gUSSDbuf, (PS8) tempStr, (MAX_DIGITS_USSD * ENCODING_LENGTH));
        OslMfree(tempStr);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveUSSNbuf
 * DESCRIPTION
 *  Function derives USSN
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveUSSNbuf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveUSSDData(((MMI_SS_USSN_IND_STRUCT*) info)->dcs, ((MMI_SS_USSN_IND_STRUCT*) info)->length, ((MMI_SS_USSN_IND_STRUCT*) info)->ussd_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeriveUSSRbuf
 * DESCRIPTION
 *  Function derives USSR
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveUSSRbuf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveUSSDData(((MMI_SS_USSR_IND_STRUCT*) info)->dcs, ((MMI_SS_USSR_IND_STRUCT*) info)->length, ((MMI_SS_USSR_IND_STRUCT*) info)->ussd_string);
}


/*****************************************************************************
 * FUNCTION
 *  DeriveUSSDbuf
 * DESCRIPTION
 *  Function derives USSN
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
void DeriveUSSDbuf(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeriveUSSDData(((MMI_SS_USSD_RSP*) info)->dcs, ((MMI_SS_USSD_RSP*) info)->length, ((MMI_SS_USSD_RSP*) info)->ussd_str);
}


/*****************************************************************************
 * FUNCTION
 *  CheckChldRequestSuccess
 * DESCRIPTION
 *  checks for failure of CHLD from PS
 * PARAMETERS
 *  info        [?]         
 *  cause       [?]         
 *  true(?)     [OUT]       For success false for failure
 *  CHLD(?)     [IN]        Rsp structure
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL CheckChldRequestSuccess(void *info, U16 *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CHLD_RSP *chldRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chldRsp = (MMI_CHLD_RSP*) info;
    if (chldRsp->result == KAL_TRUE)
    {
        *cause = 0;
        return TRUE;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CheckChldRequestSuccess);
        *cause = chldRsp->cause;
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckFailureChld
 * DESCRIPTION
 *  function detemines if CHLD request for end calls has failed
 * PARAMETERS
 *  info            [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
void CheckFailureChld(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckChldRequestSuccess(info, &result))
    {
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        SetChldReqSent(CM_ACTION_NONE);
        return;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_CheckFailureChld, result);

        switch (GetChldReqSent())
        {
            case CM_HANGUPALLHLD_REQ_SENT:
            case CM_HANGUPALLACTIVE_REQ_SENT:
            case CM_HANGUPALL_REQ_SENT:
            case CM_ENDSELECTIVE_REQ_SENT:
                ResetAllHangupFlag();
                break;
            default:
                return;
        }

        SetChldReqSent(CM_ACTION_NONE);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ShowCallManagementErrorMessage(result);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CheckCallDeflectSuccess
 * DESCRIPTION
 *  Function checks to see if the Call Deflect rsp was successful
 * PARAMETERS
 *  info            [?]         
 *  cause           [?]         
 *  Response(?)     [IN]        Structure
 * RETURNS
 *  void
 *****************************************************************************/
U16 CheckCallDeflectSuccess(void *info, U16 *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CALL_DEFLECT_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (MMI_CALL_DEFLECT_RSP*) info;

    if (rsp->result == TRUE)
    {
        *cause = 0;
        return TRUE;
    }
    else
    {
        if (rsp->cause == ERR_NORMAL_CALL_CLR)
        	   *cause = ERR_L4C_GEN_CAUSE;
        else
        *cause = rsp->cause;
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckAtaSuccess
 * DESCRIPTION
 *  Function checks to see if the ATA rsp was successful
 * PARAMETERS
 *  info            [?]         
 *  cause           [?]         
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
U16 CheckAtaSuccess(void *info, U16 *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ATA_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (MMI_ATA_RSP*) info;

    if (rsp->result.flag == L4C_OK)
    {
        *cause = 0;
        return TRUE;
    }
    else
    {
        /* can not answer MT data call thru MMI */
        if (rsp->result.cause == CM_L4C_GEN_CAUSE && rsp->call_mode == SINGLE_DATA_CALL)
        {
            *cause = ERR_CM_MT_DATA_CALL;
        }
        else
        {
            *cause = rsp->result.cause;
        }
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckRspCcbsFlag
 * DESCRIPTION
 *  checks for CCBS Flag in Disconnect Response from PS
 * PARAMETERS
 *  info        [?]         
 *  true(?)     [OUT]       For success false for failure
 *  CHLD(?)     [IN]        Rsp structure
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL CheckRspCcbsFlag(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MMI_CC_CALL_DISCONNECT_IND*) info)->ccbs;
}


/*****************************************************************************
 * FUNCTION
 *  CBackDropUSSDReq
 * DESCRIPTION
 *  Aborts SS string request
 * PARAMETERS
 *  info            [?]         
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void CBackDropUSSDReq(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((MMI_SS_ABORT_RSP*) (info))->result == TRUE)
    {
        SetDelScrnIDCallbackHandler(ITEM_SCR_USSN_MSG, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(ITEM_SCR_USSN_MSG);
        GoBackHistory();
    }
    else
    {
        ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CBackDropUSSDReqEND
 * DESCRIPTION
 *  Aborts SS string request on END Key
 * PARAMETERS
 *  info            [?]         
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void CBackDropUSSDReqEND(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((MMI_SS_ABORT_RSP*) (info))->result == TRUE)
    {
        if (isInCall())
        {
            GoBackHistory();
        }
        else
        {
            DisplayIdleScreen();
        }
    }
    else
    {
        ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  MapDtmfEnum2Ascii
 * DESCRIPTION
 *  Function maps keycode from enum value to ascii equiv.
 * PARAMETERS
 *  digit           [IN]        
 *  Ascii(?)        [OUT]       Equivalent
 *  DTMF(?)         [IN]        Keycode digit
 * RETURNS
 *  U8
 *****************************************************************************/
U8 MapDtmfEnum2Ascii(U16 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (digit)
    {
        case KEY_0:
            return '0';
        case KEY_1:
            return '1';
        case KEY_2:
            return '2';
        case KEY_3:
            return '3';
        case KEY_4:
            return '4';
        case KEY_5:
            return '5';
        case KEY_6:
            return '6';
        case KEY_7:
            return '7';
        case KEY_8:
            return '8';
        case KEY_9:
            return '9';
        case KEY_STAR:
            return '*';
        case KEY_POUND:
            return '#';
        default:
            return KEY_INVALID;
    }
}

#endif /* __MMI_UCM__ */