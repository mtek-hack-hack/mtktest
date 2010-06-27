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
 *   HistoryHelper.c
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
 * return new marker screen id in when UCM is on.
 *
 * removed!
 * removed!
 * add to source control recursely
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
 * Don't notify USB when CM is over.
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
 * Delete CTM editor screen after call ended.
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
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : HistoryHelper.c

   PURPOSE     : Call Structure Management API

   REMARKS     : nil

   AUTHOR      : Ashish

   DATE     : Nov 8,02

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__


#include "bootup.h"
#include "PowerOnChargerProt.h"
#include "USBDeviceGprot.h"
#include "SATGProts.h"
#include "SimDetectionGexdcl.h"
#include "AlarmFrameworkProt.h"
#include "AlarmDef.h"
#ifdef __MMI_TODOLIST__
#include "ToDoListEnum.h"
#endif
#include "MessagesMiscell.h"
#include "PhonebookDef.h"
#include "PhonebookGprot.h"
#include "gpioInc.h"
#include "ProfileGprots.h"
#include "CallhistoryEnum.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#ifdef WAP_SUPPORT
#include "wapadp.h"
#endif 
#include "Mdi_datatype.h"
#include "Mdi_audio.h"

#include "CallManagementIdDefEX.h"
#include "CallManagementStructEX.h"
#include "CallStructureManagementProtEX.h"
#include "CallsGprots.h"
#include "CommonStubsProtEX.h"
#include "RedialHelperGProtEX.h"
#include "CallManagementGprotEX.h"
#include "IncomingCallManagementProtEX.h"
#include "OutgoingCallHelperProtEX.h"
#include "OutgoingCallManagementProtEX.h"

#include "HistoryHelperProtEX.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

#if defined(__MMI_BG_SOUND_EFFECT__)
#include "BGSoundGProt.h"
#endif 

#if defined(__MMI_WEBCAM__)
#include "ExtDeviceDefs.h"
#endif 


//static pBOOL                  gPOPUpFlag=FALSE;
//static pBOOL                  gNotifySSFlag= FALSE;
//static FuncPtr                        gCbackAfterSS=NULL;

/* pBOOL noSave = TRUE; */
PU8 gdispnameForSubLCD = NULL;

#ifdef __MMI_CLAMCLOSE_BACK2IDLE__
extern BOOL IsClamClose(void);

//micha0601
//extern U8 gIsInSATCall;
#endif /* __MMI_CLAMCLOSE_BACK2IDLE__ */ 
extern void mmi_msg_reset_new_msg_ind_call_end(void);
extern U8 mmi_msg_need_new_msg_ind_call_end(void);


/*****************************************************************************
 * FUNCTION
 *  EntryScrMarkerError
 * DESCRIPTION
 *  This function is the error screen which should never be
 *  called.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrMarkerError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* guiBuffer; */

    EntryNewScreen(CM_SCR_MARKER, NULL, NULL, NULL);

    // guiBuffer = GetCurrGuiBuffer(CM_SCR_MARKER); /* Getting the Index from history  */

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    StartTimer(CM_NOTIFYDURATION_TIMER, 1, GoBackfromNotifyScr);
}


/*****************************************************************************
 * FUNCTION
 *  AddMarkerToHistory
 * DESCRIPTION
 *  This function inserts a marker screen to history
 * PARAMETERS
 *  void
 *  Screen(?)       [IN]        ID to add as marker screen
 * RETURNS
 *  void
 *****************************************************************************/
void AddMarkerToHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr101;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) scr101.inputBuffer, (PS8) & nHistory);
    scr101.scrnID = CM_SCR_MARKER;
    scr101.entryFuncPtr = EntryScrMarkerError;
    AddHistory(scr101);
}


/*****************************************************************************
 * FUNCTION
 *  DeleteUptoCmScreen
 * DESCRIPTION
 *  Helper to delete all screen upto marker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteUptoCmScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(CM_SCR_MARKER);
}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllCMSubLCDScreens
 * DESCRIPTION
 *  Deletes All Sub LCD Screens in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllCMSubLCDScreens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (IsSubLCDScreenPresent(SUB_LCD_SCR_CM_ACTIVECALLSCREEN))
    {
        DeleteSubLCDScreen(SUB_LCD_SCR_CM_ACTIVECALLSCREEN);
    }

    while (IsSubLCDScreenPresent(SUB_LCD_SCR1001_CM_OUTGOINGCALLSCREEN))
    {
        DeleteSubLCDScreen(SUB_LCD_SCR1001_CM_OUTGOINGCALLSCREEN);
    }

    while (IsSubLCDScreenPresent(SUB_LCD_ITEMSCR_INCOMING_CALL))
    {
        DeleteSubLCDScreen(SUB_LCD_ITEMSCR_INCOMING_CALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeleteIncomingCallOptionScreen
 * DESCRIPTION
 *  Deletes All incoming call option Screens in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteIncomingCallOptionScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetPreviousScrnIdOf(SCR1009_CM_CALLLISTSCREEN, &scrnId);
    if (scrnId == ITEM_SCR_INC_MACT_OPN)
    {
        DeleteScreenIfPresent(SCR1009_CM_CALLLISTSCREEN);
    }

    /* deflect need to delete dial pad and phb list if any */
    GetNextScrnIdOf (ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID, &scrnId);
    if (scrnId == SCR_PBOOK_LIST)
    {
        DeleteScreenIfPresent(SCR_PBOOK_LIST);
        DeleteScreenIfPresent(ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID);
    }

    DeleteScreenIfPresent(ITEM_SCR_INC_MACT_OPN);
    DeleteScreenIfPresent(ITEM_SCR_INCOMING_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  SetNotifySSFlag
 * DESCRIPTION
 *  Sets Notify SS Flag dpeneding on flag
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetNotifySSFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->history_info.IsNotifySS = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetNotifySSFlag
 * DESCRIPTION
 *  Returns Notify SS Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  flag
 *****************************************************************************/
pBOOL GetNotifySSFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->history_info.IsNotifySS;
}


/*****************************************************************************
 * FUNCTION
 *  SetCbackAfterSS
 * DESCRIPTION
 *  Sets Function to be called after SS
 * PARAMETERS
 *  fptr            [IN]        
 *  Function(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCbackAfterSS(FuncPtr fptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->history_info.CbackAfterNotifySS = fptr;
}


/*****************************************************************************
 * FUNCTION
 *  GetCbackAfterSS
 * DESCRIPTION
 *  Returns Function to be called after SS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr GetCbackAfterSS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->history_info.CbackAfterNotifySS;
}


/*****************************************************************************
 * FUNCTION
 *  SetPOPUpFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  TRUE(?)     [IN]        For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
void SetPOPUpFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->history_info.IsPopUp = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetPOPUpFlag
 * DESCRIPTION
 *  Gets the LoudSpFromOption Flag Status
 * PARAMETERS
 *  void
 *  TRUE(?)     [OUT]       For set, FALSE for not set
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetPOPUpFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cm_p->history_info.IsPopUp;
}


/*****************************************************************************
 * FUNCTION
 *  GetCmMarkerScrnID
 * DESCRIPTION
 *  This function checks marker screen id value.
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetCmMarkerScrnID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ucm_app_get_marker_scrn_id();
}


/*****************************************************************************
 * FUNCTION
 *  SetNoSave
 * DESCRIPTION
 *  Controls access to global history store buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetNoSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_p->history_info.IsSave = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  CMHistoryHandler
 * DESCRIPTION
 *  Helper to perform last rites and exit application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CMHistoryHandler(void)
{
#ifdef __MMI_CLAMCLOSE_BACK2IDLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    if (IsClamClose() && !IsInSATCall())
#else
    if (IsClamClose())
#endif
    {
        DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
        DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
        DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
        DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
        DeleteScreenIfPresent(SCR_ID_ALM_INDICATION);
#ifdef __MMI_TODOLIST__        
        DeleteScreenIfPresent(SCR_TDL_REMINDER);
#endif
    }
#endif /* __MMI_CLAMCLOSE_BACK2IDLE__ */ 

    GoBackHistory();

#ifdef __MMI_WEBCAM__
    if (GetExitScrnID() == SCR_ID_USB_WEBCAM)
    {
        /* if is in webcam screen, do not proess End key handler */
        return;
    }
#endif /* __MMI_WEBCAM__ */ 

#ifdef __MMI_CLAMCLOSE_BACK2IDLE__
    if (IsClamClose() &&
        cm_p->history_info.IsClamCloseEndCall == MMI_TRUE &&
    #ifdef __SAT__
        !IsInSATCall() &&
    #endif
        (GetExitScrnID() != ITEM_SCR_MISSED_CALL))
    {
    	cm_p->history_info.IsClamCloseEndCall = MMI_FALSE;
        ExecuteCurrKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
#endif /* __MMI_CLAMCLOSE_BACK2IDLE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetOutOfCMApplication
 * DESCRIPTION
 *  Helper to perform last rites and exit application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetOutOfCMApplication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // XXX CAUTION: If any changes are being done here,
    // corresponding changes have to be there in GetOutOfCMforAdjustHistory()

    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_GetOutOfCMApplication);

    /* low battery */
    if (g_charbat_context.LowBatteryTxProhibitFlag == 1)
    {
        SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_PROHIBIT);
    }
    else
    {
        SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_NORMAL);
    }

    if (GetCallDeflectFlag() == TRUE)
    {
        DeleteScreenIfPresent(ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID);
        SetCallDeflectFlag(FALSE);
    }

    /* reset redial data */
    if (IsRedialSet())
    {
        ResetRedialAttempts();
    }

    SetDialedDigitCalledFlag(FALSE);
    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);
    CHISTSetDialFromCallLogFlag(0);

	/* turn off speech if needed */
	type = mdi_audio_speech_get_app_id();
    if (type == MDI_AUDIO_SPEECH_APP_ID_GSM)
    {
       	mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
    }
    else if (type == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
    {
        mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
    }

    /* stop voice recording */
    if (GetVoiceRecordingFlag())
    {
        SetKeyPadStopVoiceRecordLongPress();
    }

    /* unmute phone */
    if (TRUE == IsPhoneInMute())
    {
        UnMutethePhone();
    }

    /* turn off loud speaker */
    if (GetHFreeHeld() == TRUE)
    {
        SetHFreeHeld(FALSE);
        DisbleHandsFree();
        SetLoudSpeaker(FALSE);
    }

#ifdef __MMI_BT_PROFILE__
#ifdef __MMI_VOIP__
    /* do not turn off sco link in case voip needs to turn on again */
    if (mmi_voip_app_total_call() == 0)
    {
        PRINT_INFORMATION("\n[GetOutOfCMApplication] SCO Ends\n");
        mmi_profiles_bt_call_end_callback();
    }
    else
    {
        PRINT_INFORMATION("\n[GetOutOfCMApplication] SCO Not Ends\n");
    }
#else
    /* notify bt profiles call end */
    mmi_profiles_bt_call_end_callback();
#endif /* __MMI_VOIP__ */
#endif /* __MMI_BT_PROFILE__ */ 

    /* resume audio */
#ifdef __MMI_CM_BLACK_LIST__
	if(GetBlackIncomingFlag() == FALSE)
    {
#endif /* __MMI_CM_BLACK_LIST__ */ 
    mdi_audio_resume_background_play();
#ifdef __MMI_CM_BLACK_LIST__
	}
    SetBlackIncomingFlag(FALSE);
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __SAT__
    /* micha0831 */
    SATCallTerminate();
#endif /* __SAT__ */
    /* reset DTMF flag */
    SetDTMFFlag(TRUE);

    /* reset state and exit */
    ReinitalizeCallManagement();
    SetCallAbortReqSentFlag(FALSE);

    if (GetAbortCallRequestedFlag() == TRUE || GetTotalCallCount() == 0)
    {
        DeleteAllCMSubLCDScreens();
        GoBackSubLCDHistory();
        SetAbortCallRequestedFlag(FALSE);
    }

/* Delete SCR_CTM_EDITOR  by Mick*/
#ifdef __CTM_SUPPORT__
	DeleteScreenIfPresent(SCR_CTM_EDITOR);
#endif /* __CTM_SUPPORT__ */ 

#ifdef __MMI_VOIP__
    if ((IsScreenPresent(CM_SCR_MARKER) && GetCMScrnFlag() == FALSE) || 
        (GetCMScrnFlag() == TRUE && mmi_voip_app_total_call() != 0))
#else
    if ((IsScreenPresent(CM_SCR_MARKER)) && (GetCMScrnFlag() == FALSE))
#endif
    {
        /* enter in-call option menu to go to other applications
           delete CM screens only and go back to that application */
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_GetOutOfCMApplication1);

        if (IsScreenPresent(SCR1003_CM_ACTIVECALLOPTIONS))
        {
            DeleteBetweenScreen(CM_SCR_MARKER, SCR1003_CM_ACTIVECALLOPTIONS);
            DeleteIncomingCallOptionScreen();
        }
        else
        {
            if (!DeleteBetweenScreen(CM_SCR_MARKER, SCR_CM_ACTIVECALLSCREEN))
            {
                DeleteScreenIfPresent(CM_SCR_MARKER);
            }
        }

        CMHistoryHandler();
        SetCMScrnFlag(TRUE);
    }
    else
    {
        /* all CM screens, delete all CM screen and go back */
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_GetOutOfCMApplication2);

        DeleteNScrId(CM_SCR_MARKER);
        CMHistoryHandler();
    }

    /* in case of USSD will have extra marker in history */
    DeleteScreenIfPresent(CM_SCR_MARKER);
/*
 *#ifdef __MMI_USB_SUPPORT__
 *    PendingUsbDetectionHdlr();
 *#endif
 */
    AlmEnableExpiryHandler();
    /* PendingAlarmReminder(); */
    if (mmi_msg_need_new_msg_ind_call_end())
    {
        mmi_msg_reset_new_msg_ind_call_end();
        /* PlayMessageArrivalTone(); */
    }

#ifdef OBIGO_Q03C    /* WAP_SUPPORT */
    /* Callback for WAP widget */
#ifndef WIN32
    widget_MMI_on_exit_CM();
#endif
#endif /* OBIGO_Q03C */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetOutOfCMforAdjustHistory
 * DESCRIPTION
 *  Helper to perform last rites and exit application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetOutOfCMforAdjustHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_FUNC_GetOutOfCMforAdjustHistory);

    /* low battery */
    if (g_charbat_context.LowBatteryTxProhibitFlag == 1)
    {
        SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_PROHIBIT);
    }
    else
    {
        SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_IDLE_DURCNT_NORMAL);
    }

    if (GetCallDeflectFlag() == TRUE)
    {
        DeleteScreenIfPresent(ITEM_SCR_CALL_DEFLECT_DIGIT_HANDLER_ID);
        SetCallDeflectFlag(FALSE);
    }

    /* reset redial data */
    if (IsRedialSet())
    {
        ResetRedialAttempts();
    }

    SetDialedDigitCalledFlag(FALSE);
    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);
    CHISTSetDialFromCallLogFlag(0);

	/* turn off speech if needed */
	type = mdi_audio_speech_get_app_id();
    if (type == MDI_AUDIO_SPEECH_APP_ID_GSM)
    {
       	mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
    }
    else if (type == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
    {
        mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
    }

    /* stop voice recording */
    if (GetVoiceRecordingFlag())
    {
        SetKeyPadStopVoiceRecordLongPress();
    }

    /* unmute phone */
    if (TRUE == IsPhoneInMute())
    {
        UnMutethePhone();
    }

    /* turn off loud speaker */
    if (GetHFreeHeld() == TRUE)
    {
        SetHFreeHeld(FALSE);
        DisbleHandsFree();
        SetLoudSpeaker(FALSE);
    }

#ifdef __MMI_BT_PROFILE__
#ifdef __MMI_VOIP__
    /* do not turn off sco link in case voip needs to turn on again */
    if (mmi_voip_app_total_call() == 0)
    {
        PRINT_INFORMATION("\n[GetOutOfCMforAdjustHistory] SCO Ends\n");
        mmi_profiles_bt_call_end_callback();
    }
    else
    {
        PRINT_INFORMATION("\n[GetOutOfCMforAdjustHistory] SCO Not Ends\n");
    }
#else
    /* notify bt profiles call end */
    mmi_profiles_bt_call_end_callback();
#endif /* __MMI_VOIP__ */
#endif /* __MMI_BT_PROFILE__ */ 

    /* resume audio */
#ifdef __MMI_CM_BLACK_LIST__
	if(GetBlackIncomingFlag() == FALSE)
    {
#endif /* __MMI_CM_BLACK_LIST__ */ 
    mdi_audio_resume_background_play();
#ifdef __MMI_CM_BLACK_LIST__
	}
    SetBlackIncomingFlag(FALSE);
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __SAT__
    /* micha0831 */
    SATCallTerminate();
#endif /* __SAT__ */

    /* reset DTMF flag */
    SetDTMFFlag(TRUE);

    /* reset state and exit */
    ReinitalizeCallManagement();
    SetCallAbortReqSentFlag(FALSE);

    if (GetAbortCallRequestedFlag() == TRUE || GetTotalCallCount() == 0)
    {
        DeleteAllCMSubLCDScreens();
        GoBackSubLCDHistory();
        SetAbortCallRequestedFlag(FALSE);
    }

/* Delete SCR_CTM_EDITOR  by Mick*/
#ifdef __CTM_SUPPORT__
	DeleteScreenIfPresent(SCR_CTM_EDITOR);
#endif /* __CTM_SUPPORT__ */ 

#ifdef __MMI_VOIP__
    if ((IsScreenPresent(CM_SCR_MARKER) && GetCMScrnFlag() == FALSE) || 
        (GetCMScrnFlag() == TRUE && mmi_voip_app_total_call() != 0))
#else
    if ((IsScreenPresent(CM_SCR_MARKER)) && (GetCMScrnFlag() == FALSE))
#endif
    {
        /* enter in-call option menu to go to other applications
           delete CM screens only */
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_GetOutOfCMforAdjustHistory1);

        if (IsScreenPresent(SCR1003_CM_ACTIVECALLOPTIONS))
        {
            DeleteBetweenScreen(CM_SCR_MARKER, SCR1003_CM_ACTIVECALLOPTIONS);
            DeleteIncomingCallOptionScreen();
        }
        else
        {
            if (!DeleteBetweenScreen(CM_SCR_MARKER, SCR_CM_ACTIVECALLSCREEN))
            {
                DeleteScreenIfPresent(CM_SCR_MARKER);
            }
        }

        SetCMScrnFlag(TRUE);
    }
    else
    {
        /* all CM screens, delete all CM screen */
        MMI_TRACE(MMI_TRACE_G5_CM, MMI_CM_INFO_GetOutOfCMforAdjustHistory2);

        DeleteNScrId(CM_SCR_MARKER);
    }

    /* in case of USSD will have extra marker in hostory */
    DeleteScreenIfPresent(CM_SCR_MARKER);

    /*
     * #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
     * if (IsClamClose())
     * ExecuteCurrKeyHandler( KEY_END, KEY_EVENT_DOWN );
     * #endif
     */
/*
 *#ifdef __MMI_USB_SUPPORT__
 *    PendingUsbDetectionHdlr();
 *#endif
 */
    AlmEnableExpiryHandler();
    /* PendingAlarmReminder(); */
    if (mmi_msg_need_new_msg_ind_call_end())
    {
        mmi_msg_reset_new_msg_ind_call_end();
        /* PlayMessageArrivalTone(); */
    }

#ifdef OBIGO_Q03C    /* WAP_SUPPORT */
    /* Callback for WAP widget */
#ifndef WIN32
    widget_MMI_on_exit_CM();
#endif
#endif /* OBIGO_Q03C */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GoBackfromNotifyScr
 * DESCRIPTION
 *  This is the function which is invoked when there is a timeout
 *  or user presses the LSK of the notification screen.
 *  
 *  This is the base function for all exit of the notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackfromNotifyScr(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  AdjustHistoryForCM
 * DESCRIPTION
 *  This is the function which is invoked when there is a timeout
 *  or user presses the LSK of the notification screen.
 *  
 *  This is the base function for all exit of the notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AdjustHistoryForCM(void)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  AdjustSubLcd
 * DESCRIPTION
 *  Adjusts sub-lcd scrn according to state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AdjustSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    if ((GetCurrentState() == CM_ACTIVE_STATE) || (GetCurrentState() == CM_HOLD_STATE))
    {
        ShowCategory304Screen(IMG_CM_STATE_CONNECTED, NULL);
        SetSubLCDExitHandler(ExitSubLcdScr1002ActiveCall);
        return;
    }

    if ((GetCurrentState() == CM_OUTGOING_STATE))
    {
        ShowCategory311Screen(gdispnameForSubLCD, IMG_CM_SUBLCD_CALLING, NULL);
        SetSubLCDExitHandler(ExitSubLcdScr1001OutgoingCall);
        return;
    }

    if ((GetCurrentState() == CM_INCOMING_STATE))
    {
        if (GetTotalCallCount() == 1)
        {
            DeleteSubLCDScreen(SUB_LCD_SCR_CM_ACTIVECALLSCREEN);
        }

        ShowCategory311Screen(gdispnameForSubLCD, IMG_CM_SUBLCD_CALLING, NULL);
        SetSubLCDExitHandler(ExitSubLcdScrIncomingCallEvent);
        return;
    }
}
#endif /* __MMI_UCM__ */