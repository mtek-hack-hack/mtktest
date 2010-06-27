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
 * Filename:
 * ---------
 *  VoiceMemoSrc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __MMI_VOICE_MEMO__

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CallmanagementIdDef.h"

#include "MainMenuDef.h"
#include "FunAndGamesDefs.h"
#include "VoiceMemoResDef.h"
#include "VoiceMemoType.h"
#include "VoiceMemoProt.h"
#include "CustomCfg.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "gpioinc.h"

#define MAX_VMS 20
#define MAX_VM_NAME 20
#define VM_EXT_LEN 3
#define MAX_VM_NAME_LEN (MAX_VM_NAME-VM_EXT_LEN)
#define USER_INPUT_NAME_LEN  13

U16 gNoOfVoiceMemo = 0;
UI_string_type gpRecordName[MAX_VMS];
UI_character_type gNameString[MAX_VMS][MAX_VM_NAME];
UI_string_type gpTimeDur[MAX_VMS];
UI_character_type gTimeString[MAX_VMS][MAX_VM_NAME];
U16 gVmImageId[MAX_VMS];
U8 gVmIndex[MAX_VMS];
static U16 currVmIndex;
BOOL gInCall;
BOOL gExitToStop;

UI_character_type gVmNameString[300];
UI_character_type gFileName[MAX_VM_NAME + 1];
UI_character_type gOldFileName[MAX_VM_NAME + 1];
BOOL gIsAppend;

U16 gDeleteToId;

#ifndef MAX_VM_FILE_NAME
#define MAX_VM_FILE_NAME 20
#endif 

FuncPtr KbCBackVoiceMemoPause = VoiceMemoDummyFunction;
FuncPtr KbCBackVoiceMemoResume = VoiceMemoDummyFunction;
FuncPtr KbCBackVoiceMemoStop = VoiceMemoDummyFunction;
FuncPtr KbCBackVoiceMemoAbort = VoiceMemoDummyFunction;

extern BOOL cmdProcessing;

#ifdef VOICE_RECOGNITION_TEST
/* external functions */
extern void tst_sys_trace(kal_uint8 *info);

/* external variables */
extern kal_bool g_VRQuasi;
extern kal_bool g_VRQuasiAutoGotFinishInd;
#endif /* VOICE_RECOGNITION_TEST */ 

static U8 vmVolLevel = 0;


/*****************************************************************************
 * FUNCTION
 *  InitVoiceMemoApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitVoiceMemoApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU3104_VOICE_MEMO, HighlightVoiceMemo);
    SetHiliteHandler(VM_RECORD_MENUID, HighlightVoiceMemoRecord);
    SetHiliteHandler(VM_PLAY_MENUID, HighlightVoiceMemoPlay);
    SetHiliteHandler(VM_APPEND_MENUID, HighlightVoiceMemoAppend);
    SetHiliteHandler(VM_DELETE_MENUID, HighlightVoiceMemoDelete);
    SetHiliteHandler(VM_DELETE_ALL_MENUID, HighlightVoiceMemoDeleteAll);
    SetHiliteHandler(VM_RENAME_MENUID, HighlightVoiceMemoRename);
    SetHiliteHandler(VM_RENAME_OPTION_SAVE_MENUID, HighlightVoiceMemoOptionSave);
    SetHiliteHandler(VM_RENAME_OPTION_INPUT_METHOD_MENUID, HighlightVoiceMemoOptionInputMethod);

#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoGetInfoRes, MSG_ID_VM_GET_INFO_RSP);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoDummyFunction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoDummyFunction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoResetEventHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoResetEventHandler(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_VM_RECORD_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_PLAY_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_STOP_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_DEL_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_ABORT_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_PAUSE_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_RESUME_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_APPEND_RSP);
    SetProtocolEventHandler(NULL, MSG_ID_VM_RECORD_FINISH_IND);
    SetProtocolEventHandler(NULL, MSG_ID_VM_PLAY_FINISH_IND);
#endif /* MMI_ON_HARDWARE_P */ 

    KbCBackVoiceMemoPause = VoiceMemoDummyFunction;
    KbCBackVoiceMemoResume = VoiceMemoDummyFunction;
    KbCBackVoiceMemoStop = VoiceMemoDummyFunction;
    KbCBackVoiceMemoAbort = VoiceMemoDummyFunction;
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoInCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gInCall = TRUE;
    currVmIndex = 0;
    SendVoiceMemoGetInfoReq();
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoIdle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gInCall = FALSE;
    currVmIndex = 0;
    SendVoiceMemoGetInfoReq();
}


/*****************************************************************************
 * FUNCTION
 *  ShowVoiceMemoOptionInCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVoiceMemoOptionInCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[10];
    U16 ItemIcons[10];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[10];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    ExecuteCurrExitHandler();

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (gNoOfVoiceMemo == 0)
    {
        guiBuffer = GetCurrGuiBuffer(VOICE_MEMO_NO_RECORD_MENUID);
        nItems = GetNumOfChild(VOICE_MEMO_NO_RECORD_MENUID);
        GetSequenceStringIds(VOICE_MEMO_NO_RECORD_MENUID, ItemList);
        SetParentHandler(VOICE_MEMO_NO_RECORD_MENUID);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetExitHandler(VOICE_MEMO_NO_RECORD_MENUID, NULL);
    }
    else if (gNoOfVoiceMemo < MAX_VMS)
    {
        guiBuffer = GetCurrGuiBuffer(MITEM2022_CM_VOICE_MEMO);
        nItems = GetNumOfChild(MITEM2022_CM_VOICE_MEMO);
        GetSequenceStringIds(MITEM2022_CM_VOICE_MEMO, ItemList);
        SetParentHandler(MITEM2022_CM_VOICE_MEMO);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        /* 10. Register Exit handler */
        SetExitHandler(MITEM2022_CM_VOICE_MEMO, NULL);
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(VOICE_MEMO_FULL_IN_CALL_MENUID);
        nItems = GetNumOfChild(VOICE_MEMO_FULL_IN_CALL_MENUID);
        GetSequenceStringIds(VOICE_MEMO_FULL_IN_CALL_MENUID, ItemList);
        SetParentHandler(VOICE_MEMO_FULL_IN_CALL_MENUID);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            0,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        /* 10. Register Exit handler */
        SetExitHandler(VOICE_MEMO_FULL_IN_CALL_MENUID, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ShowVoiceMemoOptionIdle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowVoiceMemoOptionIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[10];
    U16 ItemIcons[10];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[10];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    ExecuteCurrExitHandler();

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (gNoOfVoiceMemo == 0)
    {
        guiBuffer = GetCurrGuiBuffer(VOICE_MEMO_NO_RECORD_MENUID);
        nItems = GetNumOfChild(VOICE_MEMO_NO_RECORD_MENUID);
        GetSequenceStringIds(VOICE_MEMO_NO_RECORD_MENUID, ItemList);
        SetParentHandler(VOICE_MEMO_NO_RECORD_MENUID);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetExitHandler(VOICE_MEMO_NO_RECORD_MENUID, NULL);
    }
    else if (gNoOfVoiceMemo < MAX_VMS)
    {
        guiBuffer = GetCurrGuiBuffer(MENU3104_VOICE_MEMO);
        nItems = GetNumOfChild(MENU3104_VOICE_MEMO);
        GetSequenceStringIds(MENU3104_VOICE_MEMO, ItemList);
        SetParentHandler(MENU3104_VOICE_MEMO);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        /* 10. Register Exit handler */
        SetExitHandler(MENU3104_VOICE_MEMO, NULL);
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(VOICE_MEMO_FULL_MENUID);
        nItems = GetNumOfChild(VOICE_MEMO_FULL_MENUID);
        GetSequenceStringIds(VOICE_MEMO_FULL_MENUID, ItemList);
        SetParentHandler(VOICE_MEMO_FULL_MENUID);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < nItems; i++)
        {
            PopUpList[i] = NULL;
        }
        for (i = 0; i < nItems; i++)
        {
            ItemIcons[i] = IMG_GLOBAL_L1 + i;   /* ReturnRequiredNumberImageId(i); */
        }

        ShowCategory52Screen(
            VOICE_MEMO_TITLE_TEXT,
            0,
            VOICE_MEMO_LSK_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            nItems,
            ItemList,
            ItemIcons,
            (U8 **) PopUpList,
            0,
            0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        /* 10. Register Exit handler */
        SetExitHandler(VOICE_MEMO_FULL_MENUID, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gInCall)
    {
        ShowVoiceMemoOptionInCall();
    }
    else
    {
        ShowVoiceMemoOptionIdle();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VoiceMemoResetEventHandler();
    cmdProcessing = FALSE;
    if (gExitToStop)
    {
        VoiceMemoStopReq();
        cmdProcessing = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetVmIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetVmIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currVmIndex = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRecordMap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRecordMap(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNoOfVoiceMemo = 0;
    do
    {
        if (index & 0x0001 != 0x0000)
        {
            gVmIndex[gNoOfVoiceMemo++] = i;
        }
        i++;
        index = index >> 1;
    } while (index);

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoGetFileId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S16 VoiceMemoGetFileId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNoOfVoiceMemo > 0 && currVmIndex < gNoOfVoiceMemo)
    {
        return (S16) gVmIndex[currVmIndex];
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoPrepareList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  no_of_vm            [IN]        
 *  file_name_list      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoPrepareList(kal_uint16 no_of_vm, UI_string_type file_name_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNoOfVoiceMemo = no_of_vm;
    if (gNoOfVoiceMemo == 0)
    {
        gpRecordName[0] = get_string(VM_EMPTY_TEXT);
        return;
    }

    for (i = 0; i < gNoOfVoiceMemo; i++)
    {
        memcpy(gNameString[i], file_name_list, MAX_VM_FILE_NAME * ENCODE_BYTE);

        gpRecordName[i] = gNameString[i];
        file_name_list += MAX_VM_FILE_NAME;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  no_of_vm            [IN]        
 *  file_name_list      [IN]        
 *  more_entry          [IN]        
 *  free_space          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoList(U16 no_of_vm, UI_string_type file_name_list, BOOL more_entry, U32 free_space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    guiBuffer = GetCurrGuiBuffer(VOICE_MEMO_MENUID);
    RegisterHighlightHandler(GetVmIndex);

    VoiceMemoPrepareList(no_of_vm, file_name_list);

    if (gNoOfVoiceMemo < 1)
    {
        ShowCategory6Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_OPTION_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            1,
            (PU8*) gpRecordName,
            NULL,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory6Screen(
            VOICE_MEMO_TITLE_TEXT,
            IMG_MENU3104_VOICE_MEMO,
            VOICE_MEMO_OPTION_TEXT,
            0,
            VOICE_MEMO_RSK_TEXT,
            0,
            gNoOfVoiceMemo,
            (PU8*) gpRecordName,
            NULL,
            currVmIndex,
            guiBuffer);
    }
    SetLeftSoftkeyFunction(EntryVoiceMemoMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* SetKeyHandler(EntryVoiceMemoMenu,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);

    SetExitHandler(VOICE_MEMO_MENUID, ExitScrVoiceMemoList);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrVoiceMemoList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrVoiceMemoList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = VOICE_MEMO_MENUID;
    currHistory.entryFuncPtr = SendVoiceMemoGetInfoReq;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategory6History(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryVoiceMemoIdle, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(EntryVoiceMemoIdle, MMI_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoGetInfoReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoGetInfoReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VoiceMemoGetInfoReq();
#else /* MMI_ON_HARDWARE_P */ 
    EntryVoiceMemoList(gNoOfVoiceMemo, (UI_string_type) gVmNameString, 0, 1000);
#endif /* MMI_ON_HARDWARE_P */ 
}

/* record */
#define VOICE_MEMO_RECORD


/*****************************************************************************
 * FUNCTION
 *  VmSaveVolume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VmSaveVolume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SaveSpeechVolume((U8) vmVolLevel);
}


/*****************************************************************************
 * FUNCTION
 *  VmSpeechVolumeUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VmSpeechVolumeUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vmVolLevel < (MAX_VOL_LEVEL - 1))
    {
        vmVolLevel++;
        SetSpeechVolume(vmVolLevel);
        StartTimer(KEY_VOL_TIMER_ID, 2000, VmSaveVolume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VmSpeechVolumeDown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VmSpeechVolumeDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vmVolLevel > 0)
    {
        vmVolLevel--;
        SetSpeechVolume(vmVolLevel);
        StartTimer(KEY_VOL_TIMER_ID, 2000, VmSaveVolume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoSetSideKeyHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoSetSideKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vmVolLevel = GetModeSpeechVolume();
    SetKeyHandler(VmSpeechVolumeUp, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(VmSpeechVolumeDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAddRecord
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAddRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buff[40];
    U16 i;
    UI_string_type file_name_p = gVmNameString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < gNoOfVoiceMemo; i++)
    {
        memcpy(file_name_p, gNameString[i], MAX_VM_FILE_NAME * ENCODE_BYTE);
        file_name_p += MAX_VM_FILE_NAME;
    }

    if (gNoOfVoiceMemo < MAX_VMS)
    {
        sprintf((S8*) buff, "VM_%02d.vm", gNoOfVoiceMemo);
        mmi_asc_to_ucs2((S8*) file_name_p, (S8*) buff);

        currVmIndex = gNoOfVoiceMemo;
        gNoOfVoiceMemo++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackRecordResume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackRecordResume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_RECORD_MENUID);
    ShowCategory8Screen(
        VM_RECORD_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RECORD_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_RECORDING_TEXT,
        VM_RECORDING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_RECORD_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  KbCBackRecordPause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackRecordPause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_RECORD_MENUID);
    ShowCategory8Screen(
        VM_RECORD_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RESUME_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_PAUSED_TEXT,
        VM_RECORDING_PAUSED_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordResumeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_RECORD_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRecordDeleteMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRecordDeleteMsg(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(VoiceMemoDeleteRes, MSG_ID_VM_DEL_RSP);
    VoiceMemoDeleteReq(gOldFileName);
    SetVoiceMemoDeleteHistoryNodes(VM_RENAME_MENUID);
#else /* MMI_ON_HARDWARE_P */ 
    if (gNoOfVoiceMemo >= 1)
    {
        VoiceMemoDeleteRecord((U16) (gNoOfVoiceMemo - 1));
    }
    else
    {
        VoiceMemoDeleteRecord(0);
    }
    SetVoiceMemoDeleteHistoryNodes(VM_RENAME_MENUID);
    DisplayPopup(
        (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
        IMG_GLOBAL_ACTIVATED,
        1,
        VM_NOTIFYDURATION,
        (U8) SUCCESS_TONE);
    DeleteVoiceMemoHistoryNodesG();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoAbortQuery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoAbortQuery(void)
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
        get_string(VM_ABORT_QUERY_TEXT),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordDeleteMsg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoAbortQuery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoAbortQuery(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_VM_DEL_RSP);
    cmdProcessing = FALSE;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoRecordRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoRecordRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 rskStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    guiBuffer = GetCurrGuiBuffer(VM_RENAME_MENUID);

    if (!guiBuffer)
    {
        gFileName[mmi_ucs2strlen((S8*) gFileName) - 3] = 0;
    }

    //MTK Elvis 20040510 to set the default RSK string to be "Back" always
    //Editor will change the RSK to "Clear" while the input buffer is not empty
    //if(mmi_ucs2strlen((S8*)gFileName)>0)
    //   rskStr=STR_GLOBAL_CLEAR;
    //else
    //   rskStr=STR_GLOBAL_BACK;
    rskStr = STR_GLOBAL_BACK;
    /* MTK end */

    ShowCategory5Screen(
        VM_RENAME_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        STR_GLOBAL_OPTIONS,
        0,
        rskStr,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) gFileName,
        USER_INPUT_NAME_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryVoiceMemoRenameOption, KEY_EVENT_UP);
    /* SetKeyHandler(EntryVoiceMemoRenameOption, KEY_RIGHT_ARROW, KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(EntryVoiceMemoAbortQuery, KEY_EVENT_UP);
    SetExitHandler(VM_RENAME_MENUID, ExitVoiceMemoRecordRename);

    RegisterInputMethodScreenCloseFunction(GoBackHistory1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoRecordRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoRecordRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = VM_RENAME_MENUID;
    currHistory.entryFuncPtr = EntryVoiceMemoRecordRename;
    memset((S8*) currHistory.inputBuffer, 0, ENCODING_LENGTH);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);

}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoAppendRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoAppendRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 rskStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    guiBuffer = GetCurrGuiBuffer(VM_RENAME_MENUID);

    if (!guiBuffer)
    {
        gFileName[mmi_ucs2strlen((S8*) gFileName) - 3] = 0;
    }

    //MTK Elvis 20040510 to set the default RSK string to be "Back" always
    //Editor will change the RSK to "Clear" while the input buffer is not empty
    //if(mmi_ucs2strlen((S8*)gFileName)>0)
    //   rskStr=STR_GLOBAL_CLEAR;
    //else
    //   rskStr=STR_GLOBAL_BACK;
    rskStr = STR_GLOBAL_BACK;
    /* MTK end */

    ShowCategory5Screen(
        VM_RENAME_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        STR_GLOBAL_OPTIONS,
        0,
        rskStr,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) gFileName,
        USER_INPUT_NAME_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryVoiceMemoRenameOption, KEY_EVENT_UP);
    /* SetKeyHandler(EntryVoiceMemoRenameOption, KEY_RIGHT_ARROW, KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetExitHandler(VM_RENAME_MENUID, ExitVoiceMemoAppendRename);

    RegisterInputMethodScreenCloseFunction(GoBackHistory1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoAppendRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoAppendRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = VM_RENAME_MENUID;
    currHistory.entryFuncPtr = EntryVoiceMemoAppendRename;
    memset((S8*) currHistory.inputBuffer, 0, ENCODING_LENGTH);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);

}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoSaveFileName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoSaveFileName(UI_string_type file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(gFileName, file_name, MAX_VM_FILE_NAME * ENCODE_BYTE);
}


/*****************************************************************************
 * FUNCTION
 *  KbCBackRecordStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackRecordStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gExitToStop = FALSE;
    if (!gIsAppend)
    {
        memcpy(gOldFileName, gFileName, MAX_VM_FILE_NAME * ENCODE_BYTE);
        EntryVoiceMemoRecordRename();
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoRecord
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();

    ClearInputEventHandler(MMI_DEVICE_ALL);
    gExitToStop = TRUE;
    gIsAppend = FALSE;
    guiBuffer = GetCurrGuiBuffer(VM_RECORD_MENUID);
    ShowCategory8Screen(
        VM_RECORD_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RECORD_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_RECORDING_TEXT,
        VM_RECORDING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_RECORD_MENUID, ExitVoiceMemo);
    if (gInCall)
    {
        VoiceMemoSetSideKeyHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoRecord
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(SendVoiceMemoRecordReq, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(SendVoiceMemoRecordReq,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRecordReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRecordReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(VoiceMemoRecordRes, MSG_ID_VM_RECORD_RSP);
    SetProtocolEventHandler(VoiceMemoRecordFinishInd, MSG_ID_VM_RECORD_FINISH_IND);
    VoiceMemoRecordReq(2);
#else /* MMI_ON_HARDWARE_P */ 
    EntryVoiceMemoRecord();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRecordStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRecordStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoStop = KbCBackRecordStop;
#ifdef MMI_ON_HARDWARE_P
#ifdef VOICE_RECOGNITION_TEST
    if (KAL_FALSE == g_VRQuasi)
    {
        tst_sys_trace((kal_uint8*) "PHONE: set handler: VoiceMemoStopRes");
        SetProtocolEventHandler(VoiceMemoStopRes, MSG_ID_VM_STOP_RSP);
    }
    else
    {
        tst_sys_trace((kal_uint8*) "PHONE: set handler: VRSampleStopRes");
        SetProtocolEventHandler(VRSampleStopRes, MSG_ID_VM_STOP_RSP);
    }
#else /* VOICE_RECOGNITION_TEST */ 
    SetProtocolEventHandler(VoiceMemoStopRes, MSG_ID_VM_STOP_RSP);
#endif /* VOICE_RECOGNITION_TEST */ 

    VoiceMemoStopReq();
#else /* MMI_ON_HARDWARE_P */ 
    if (!gIsAppend)
    {
        VoiceMemoAddRecord();
    }
    {
        U8 buff[40];
        UI_character_type temp[40];

        sprintf((S8*) buff, "VM_%02d.vm", gNoOfVoiceMemo);
        mmi_asc_to_ucs2((S8*) temp, (S8*) buff);
        VoiceMemoSaveFileName(temp);
        KbCBackRecordStop();
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRecordPauseReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRecordPauseReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoPause = KbCBackRecordPause;
#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoPauseRes, MSG_ID_VM_PAUSE_RSP);
    VoiceMemoPauseReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackRecordPause();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRecordResumeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRecordResumeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoResume = KbCBackRecordResume;
#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoResumeRes, MSG_ID_VM_RESUME_RSP);
    VoiceMemoResumeReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackRecordResume();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoAbortReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoAbortReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VoiceMemoAbortReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackRecordStop();
#endif /* MMI_ON_HARDWARE_P */ 
}

/* play */
#define VOICE_MEMO_PLAY


/*****************************************************************************
 * FUNCTION
 *  KbCBackPlayResume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackPlayResume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_PLAY_MENUID);
    ShowCategory8Screen(
        VM_PLAY_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_PLAY_LSK_TEXT,
        0,
        VM_PLAY_RSK_TEXT,
        0,
        VM_PLAYING_TEXT,
        VM_PLAYING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoPlayPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoPlayStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_PLAY_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  KbCBackPlayPause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackPlayPause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_PLAY_MENUID);
    ShowCategory8Screen(
        VM_PLAY_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RESUME_LSK_TEXT,
        0,
        VM_PLAY_RSK_TEXT,
        0,
        VM_PAUSED_TEXT,
        VM_PLAYING_PAUSED_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoPlayResumeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoPlayStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_PLAY_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  KbCBackPlayStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackPlayStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gExitToStop = FALSE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoPlay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();

    ClearInputEventHandler(MMI_DEVICE_ALL);
    gExitToStop = TRUE;
    guiBuffer = GetCurrGuiBuffer(VM_PLAY_MENUID);
    ShowCategory8Screen(
        VM_PLAY_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_PLAY_LSK_TEXT,
        0,
        VM_PLAY_RSK_TEXT,
        0,
        VM_PLAYING_TEXT,
        VM_PLAYING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoPlayPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoPlayStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_PLAY_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoPlay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(SendVoiceMemoPlayReq, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(SendVoiceMemoPlayReq,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoPlayReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoPlayReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currVmIndex < gNoOfVoiceMemo)
    {
        SetProtocolEventHandler(VoiceMemoPlayRes, MSG_ID_VM_PLAY_RSP);
        SetProtocolEventHandler(VoiceMemoPlayFinishInd, MSG_ID_VM_PLAY_FINISH_IND);
        VoiceMemoPlayReq(gpRecordName[currVmIndex]);
    }
#else /* MMI_ON_HARDWARE_P */ 
    if (currVmIndex < gNoOfVoiceMemo)
    {
        EntryVoiceMemoPlay();
    }
#endif /* MMI_ON_HARDWARE_P */ 
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoPlayStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoPlayStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoStop = KbCBackPlayStop;
#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoStopRes, MSG_ID_VM_STOP_RSP);
    VoiceMemoStopReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackPlayStop();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoPlayPauseReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoPlayPauseReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoPause = KbCBackPlayPause;
#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoPauseRes, MSG_ID_VM_PAUSE_RSP);
    VoiceMemoPauseReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackPlayPause();
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoPlayResumeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoPlayResumeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    KbCBackVoiceMemoResume = KbCBackPlayResume;
#ifdef MMI_ON_HARDWARE_P
    SetProtocolEventHandler(VoiceMemoResumeRes, MSG_ID_VM_RESUME_RSP);
    VoiceMemoResumeReq();
#else /* MMI_ON_HARDWARE_P */ 
    KbCBackPlayResume();
#endif /* MMI_ON_HARDWARE_P */ 
}

/* append */
#define VOICE_MEMO_APPEND


/*****************************************************************************
 * FUNCTION
 *  KbCBackAppendResume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackAppendResume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_APPEND_MENUID);
    ShowCategory8Screen(
        VM_APPEND_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RECORD_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_RECORDING_TEXT,
        VM_RECORDING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_APPEND_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  KbCBackAppendPause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackAppendPause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(VM_APPEND_MENUID);
    ShowCategory8Screen(
        VM_APPEND_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RESUME_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_RECORD_TITLE_TEXT,
        VM_RECORDING_PAUSED_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordResumeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_APPEND_MENUID, ExitVoiceMemo);

}


/*****************************************************************************
 * FUNCTION
 *  KbCBackAppendStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void KbCBackAppendStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gExitToStop = FALSE;
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoAppend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoAppend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    gExitToStop = TRUE;
    gIsAppend = TRUE;
    guiBuffer = GetCurrGuiBuffer(VM_APPEND_MENUID);
    ShowCategory8Screen(
        VM_APPEND_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VM_RECORD_LSK_TEXT,
        0,
        VM_RECORD_RSK_TEXT,
        0,
        VM_RECORDING_TEXT,
        VM_RECORDING_IMG,
        guiBuffer);
    SetLeftSoftkeyFunction(SendVoiceMemoRecordPauseReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SendVoiceMemoRecordStopReq, KEY_EVENT_UP);
    SetExitHandler(VM_APPEND_MENUID, ExitVoiceMemo);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoAppend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoAppend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(SendVoiceMemoAppendReq, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(SendVoiceMemoAppendReq,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoAppendReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoAppendReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currVmIndex < gNoOfVoiceMemo)
    {
        SetProtocolEventHandler(VoiceMemoAppendRes, MSG_ID_VM_APPEND_RSP);
        SetProtocolEventHandler(VoiceMemoRecordFinishInd, MSG_ID_VM_RECORD_FINISH_IND);
        VoiceMemoAppendReq(gpRecordName[currVmIndex]);
    }
#else /* MMI_ON_HARDWARE_P */ 
    if (currVmIndex < gNoOfVoiceMemo)
    {
        EntryVoiceMemoAppend();
    }
#endif /* MMI_ON_HARDWARE_P */ 
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }
}

/* rename */
#define VOICE_MEMO_RENAME


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoReplaceRecord
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  file_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoReplaceRecord(U16 index, UI_string_type file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    UI_string_type file_name_p = gVmNameString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < gNoOfVoiceMemo)
    {
        for (i = 0; i < gNoOfVoiceMemo; i++)
        {
            if (i == index)
            {
                memcpy(file_name_p, file_name, MAX_VM_FILE_NAME * ENCODE_BYTE);
                file_name_p += MAX_VM_FILE_NAME;
            }
            else
            {
                memcpy(file_name_p, gNameString[i], MAX_VM_FILE_NAME * ENCODE_BYTE);
                file_name_p += MAX_VM_FILE_NAME;
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoRenameOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoRenameOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;
    U16 itemIcons[10];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    guiBuffer = GetCurrGuiBuffer(VM_RENAME_OPTION_MENUID);
    SetParentHandler(VM_RENAME_OPTION_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(VM_RENAME_OPTION_MENUID);
    GetSequenceStringIds(VM_RENAME_OPTION_MENUID, nStrItemList);
    for (i = 0; ((i < numItems) && (i < 10)); i++)
    {
        itemIcons[i] = IMG_GLOBAL_L1 + i;
    }
    ShowCategory52Screen(
        VM_RENAME_OPTION_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        VOICE_MEMO_OPTION_TEXT,
        VOICE_MEMO_OPTION_ICON,
        VOICE_MEMO_RSK_TEXT,
        VOICE_MEMO_RSK_ICON,
        numItems,
        nStrItemList,
        itemIcons,
        NULL,
        0,
        0,
        guiBuffer);

    SetExitHandler(VM_RENAME_OPTION_MENUID, ExitVoiceMemoRenameOption);
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoRenameOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoRenameOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = VM_RENAME_OPTION_MENUID;
    Scr.entryFuncPtr = EntryVoiceMemoRenameOption;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoRemoveExtension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoRemoveExtension(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(gFileName, gpRecordName[currVmIndex], MAX_VM_NAME * ENCODING_LENGTH);
    memcpy(gOldFileName, gpRecordName[currVmIndex], MAX_VM_NAME * ENCODING_LENGTH);
    gFileName[mmi_ucs2strlen((S8*) gFileName) - 3] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoAppendExtension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoAppendExtension(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((S8*) gFileName, (S8*) L".vm");
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 rskStr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    guiBuffer = GetCurrGuiBuffer(VM_RENAME_MENUID);

    if (!guiBuffer)
    {
        VoiceMemoRemoveExtension();
    }

    //MTK Elvis 20040510 to set the default RSK string to be "Back" always
    //Editor will change the RSK to "Clear" while the input buffer is not empty
    //if(mmi_ucs2strlen((S8*)gFileName)>0)
    //   rskStr=STR_GLOBAL_CLEAR;
    //else
    //   rskStr=STR_GLOBAL_BACK;
    rskStr = STR_GLOBAL_BACK;
    /* MTK end */

    ShowCategory5Screen(
        VM_RENAME_TITLE_TEXT,
        IMG_MENU3104_VOICE_MEMO,
        STR_GLOBAL_OPTIONS,
        0,
        rskStr,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) gFileName,
        USER_INPUT_NAME_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryVoiceMemoRenameOption, KEY_EVENT_UP);
    /* SetKeyHandler(EntryVoiceMemoRenameOption, KEY_RIGHT_ARROW, KEY_EVENT_UP); */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetExitHandler(VM_RENAME_MENUID, ExitVoiceMemoRename);

    RegisterInputMethodScreenCloseFunction(GoBackHistory1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = VM_RENAME_MENUID;
    currHistory.entryFuncPtr = EntryVoiceMemoRename;
    memset((S8*) currHistory.inputBuffer, 0, ENCODING_LENGTH);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoRename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryVoiceMemoRename, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(EntryVoiceMemoRename,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoOptionSave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoOptionSave(void)
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
        get_string(VM_SAVE_QUERY_TEXT),
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(SendVoiceMemoRenameMsg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoOptionSave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoOptionSave(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_VM_RENAME_RSP);
    cmdProcessing = FALSE;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoOptionSave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoOptionSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryVoiceMemoOptionSave, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(EntryVoiceMemoOptionSave,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoOptionInputMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoOptionInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(EntryInputMethodScreen,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoRenameMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoRenameMsg(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(VoiceMemoRenameRes, MSG_ID_VM_RENAME_RSP);
    VoiceMemoAppendExtension();
    VoiceMemoRenameReq(gOldFileName /* gpRecordName[currVmIndex] */ , gFileName);
    SetVoiceMemoDeleteHistoryNodes(VM_RENAME_MENUID);
#else /* MMI_ON_HARDWARE_P */ 
    VoiceMemoAppendExtension();
    VoiceMemoReplaceRecord(currVmIndex, gFileName);
    SetVoiceMemoDeleteHistoryNodes(VM_RENAME_MENUID);
    DisplayPopup(
        (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
        IMG_GLOBAL_ACTIVATED,
        1,
        VM_NOTIFYDURATION,
        (U8) SUCCESS_TONE);
    DeleteVoiceMemoHistoryNodesG();
#endif /* MMI_ON_HARDWARE_P */ 
}

/* delete */
#define VOICE_MEMO_DELETE


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoDeleteRecord
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoDeleteRecord(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    UI_string_type file_name_p = gVmNameString;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < gNoOfVoiceMemo)
    {
        for (i = 0; i < gNoOfVoiceMemo; i++)
        {
            if (i != index)
            {
                memcpy(file_name_p, gNameString[i], MAX_VM_FILE_NAME * ENCODE_BYTE);
                file_name_p += MAX_VM_FILE_NAME;
            }
        }
        gNoOfVoiceMemo--;
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNoOfVoiceMemo > 0)
    {

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(VM_DELETE_QUERY_TEXT),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(SendVoiceMemoDeleteMsg, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoDelete(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_VM_DEL_RSP);
    cmdProcessing = FALSE;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryVoiceMemoDelete, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(EntryVoiceMemoDelete,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryVoiceMemoDeleteAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryVoiceMemoDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNoOfVoiceMemo > 0)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(VM_DELETE_ALL_QUERY_TEXT),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(SendVoiceMemoDeleteAllMsg, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitVoiceMemoDeleteAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVoiceMemoDeleteAll(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_VM_DEL_RSP);
    cmdProcessing = FALSE;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMemoDeleteAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMemoDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(VOICE_MEMO_LSK_TEXT, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(VOICE_MEMO_RSK_TEXT, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryVoiceMemoDeleteAll, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    /* SetKeyHandler(EntryVoiceMemoDeleteAll,MMI_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, MMI_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoDeleteMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoDeleteMsg(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currVmIndex < gNoOfVoiceMemo)
    {
        SetProtocolEventHandler(VoiceMemoDeleteRes, MSG_ID_VM_DEL_RSP);
        VoiceMemoDeleteReq(gpRecordName[currVmIndex]);
        SetVoiceMemoDeleteHistoryNodes(VM_DELETE_MENUID);
    }
#else /* MMI_ON_HARDWARE_P */ 
    if (currVmIndex < gNoOfVoiceMemo)
    {
        VoiceMemoDeleteRecord(currVmIndex);
        SetVoiceMemoDeleteHistoryNodes(VM_DELETE_MENUID);
        DisplayPopup(
            (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
            IMG_GLOBAL_ACTIVATED,
            1,
            VM_NOTIFYDURATION,
            (U8) SUCCESS_TONE);
        DeleteVoiceMemoHistoryNodesG();
    }
#endif /* MMI_ON_HARDWARE_P */ 
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SendVoiceMemoDeleteAllMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVoiceMemoDeleteAllMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_ON_HARDWARE_P
    if (gNoOfVoiceMemo > 0)
    {
        SetProtocolEventHandler(VoiceMemoDeleteRes, MSG_ID_VM_DEL_RSP);
        VoiceMemoDeleteAllReq();
        SetVoiceMemoDeleteHistoryNodes(VM_DELETE_ALL_MENUID);
    }
#else /* MMI_ON_HARDWARE_P */ 
    if (gNoOfVoiceMemo > 0)
    {
        gNoOfVoiceMemo = 0;
        SetVoiceMemoDeleteHistoryNodes(VM_DELETE_ALL_MENUID);
        DisplayPopup(
            (PU8) GetString(VM_NOTICE_SUCCESS_TEXT),
            IMG_GLOBAL_ACTIVATED,
            1,
            VM_NOTIFYDURATION,
            (U8) SUCCESS_TONE);
        DeleteVoiceMemoHistoryNodesG();
    }
#endif /* MMI_ON_HARDWARE_P */ 
    else
    {
        DisplayPopup((PU8) GetString(VM_NO_RECORD_TEXT), IMG_GLOBAL_WARNING, 1, VM_NOTIFYDURATION, WARNING_TONE);
    }
}

/* Common handlers */


/*****************************************************************************
 * FUNCTION
 *  VoiceMemoExceptionHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void VoiceMemoExceptionHandler(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case VM_RES_OK:
            GoBackHistory();
            break;
        case VM_RES_FAIL:
            DisplayPopup(
                (PU8) GetString(VM_NOTICE_ERROR_TEXT),
                IMG_GLOBAL_UNFINISHED,
                1,
                VM_NOTIFYDURATION,
                ERROR_TONE);
            break;
        case VM_RES_BUSY:
            DisplayPopup((PU8) GetString(VM_DEVICE_BUSY_TEXT), IMG_GLOBAL_UNFINISHED, 1, VM_NOTIFYDURATION, ERROR_TONE);
            break;
        case VM_RES_DISC_FULL:
            DisplayPopup((PU8) GetString(VM_DISC_FULL_TEXT), IMG_GLOBAL_UNFINISHED, 1, VM_NOTIFYDURATION, ERROR_TONE);
            break;
        case VM_RES_OPEN_FILE_FAIL:
            DisplayPopup(
                (PU8) GetString(VM_OPEN_FILE_ERROR_TEXT),
                IMG_GLOBAL_UNFINISHED,
                1,
                VM_NOTIFYDURATION,
                ERROR_TONE);
            break;
        case VM_RES_END_OF_FILE:
            GoBackHistory();
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistory2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistory2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(2);

}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistory1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistory1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);

}


/*****************************************************************************
 * FUNCTION
 *  DeleteVoiceMemoHistoryNodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screenId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteVoiceMemoHistoryNodes(U16 screenId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(screenId) == TRUE)
    {
        DeleteNScrId(screenId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetVoiceMemoDeleteHistoryNodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screenId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetVoiceMemoDeleteHistoryNodes(U16 screenId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gDeleteToId = screenId;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteVoiceMemoHistoryNodesG
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteVoiceMemoHistoryNodesG(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(gDeleteToId) == TRUE)
    {
        DeleteNScrId(gDeleteToId);
    }
}

#ifdef VOICE_RECOGNITION_TEST


/*****************************************************************************
 * FUNCTION
 *  SendVRSampleRecordReq
 * DESCRIPTION
 *  This function is for TST to call in VR Test Quasi Automatic mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool    KAL_TRUE if no errors.
 *****************************************************************************/
kal_bool SendVRSampleRecordReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tst_sys_trace((kal_uint8*) "PHONE: call SendVRSampleRecordReq()");
    SetProtocolEventHandler(VRSampleRecordRes, MSG_ID_VM_RECORD_RSP);
    SetProtocolEventHandler(VRSampleRecordFinishInd, MSG_ID_VM_RECORD_FINISH_IND);
    return VRSampleRecordReq(2);
#endif /* MMI_ON_HARDWARE_P */ 
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SendVRSampleRecordStopReq
 * DESCRIPTION
 *  This function is for TST to call in VR Test Quasi Automatic mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVRSampleRecordStopReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KAL_TRUE == g_VRQuasiAutoGotFinishInd)
    {
        tst_sys_trace((kal_uint8*) "PHONE: SKIP calling SendVRSampleRecordStopReq() for FinishInd");
        return;
    }

    {
        tst_sys_trace((kal_uint8*) "PHONE: call SendVRSampleRecordStopReq()");
        SetProtocolEventHandler(VRSampleStopRes, MSG_ID_VM_STOP_RSP);
    }
    VoiceMemoStopReq();

#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVRSampleDeleteMsg
 * DESCRIPTION
 *  This function is for TST to call in VR Test Quasi mode.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SendVRSampleDeleteMsg(UI_string_type filename)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(VRSampleDeleteRes, MSG_ID_VM_DEL_RSP);
    VoiceMemoDeleteReq(filename);
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  SendVRSampleGetInfoReq
 * DESCRIPTION
 *  This function is for TST to call in VR Test Quasi mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendVRSampleGetInfoReq(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(VRSampleGetInfoRes, MSG_ID_VM_GET_INFO_RSP);
    VoiceMemoGetInfoReq();
#endif /* MMI_ON_HARDWARE_P */ 
}

#endif /* VOICE_RECOGNITION_TEST */ 

#endif /* __MMI_VOICE_MEMO__ */ /* VM_SUPPORT */

