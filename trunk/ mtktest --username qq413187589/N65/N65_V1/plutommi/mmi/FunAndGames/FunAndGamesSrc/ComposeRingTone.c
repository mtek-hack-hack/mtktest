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
 * ComposeRingTone.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements screen flow of Ring Tone Composer application.
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

   FILENAME : ComposeRingTone.c

   PURPOSE     : Main functions of the Fun and Games, Compose Ring Tone application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : July-28-2003

**************************************************************/
#ifndef _MMI_COMPOSERINGTONE_C
#define _MMI_COMPOSERINGTONE_C

/*  Include: MMI header file */

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

#include "GlobalDefs.h" /* resources */
#include "CustDataRes.h"
#include "CustMenuRes.h"

#include "historyGprot.h"       /* display screen/ history */
#include "MainMenuDef.h"
#include "EventsGprot.h"
#include "wgui_categories_inputs.h"
#include "Wgui_categories_popup.h"
#include "CommonScreens.h"

#include "TimerEvents.h"        /* timer/message id definition */
#include "ProtocolEvents.h"

#include "DebugInitDef.h"       /* debug info */

#include "StdC.h"       /* app headers */
#include "Ucs2prot.h"
#include "FunAndGamesDefs.h"
#include "FunAndGamesProts.h"
#include "ComposeRingToneEngineProts.h"
#include "ComposeRingToneProts.h"
#include "ComposeRingToneDefs.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "gpioInc.h"
#include "Wgui_categories.h"
#include "FileManagerGProt.h"
#include "EventsGprot.h"
#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif 

#include "fs_type.h"
#include "FS_Func.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "AudioPlayerProt.h"

/* it is assumed that the filemanager will always on */
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"

#include "datetimetype.h"
#include "app_datetime.h"
#include "USBDeviceGprot.h"     /* USB MS mode */

#define  RNGC_MAX_ENG_CHAR    26
/* 
 * Global Variable
 */
rngc_context_struct g_rngc_cntx;

S16 RINGCOMPOSER_PATH[MAX_IMAGE_NAME_PATH_WIDTH];
#ifndef WIN32
extern const U8 CurrentInstrument[];    /* 110805 ringtonecomposer Calvin add */
#endif
/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  RngcCreateDir
 * DESCRIPTION
 *  Create directory for ring tone composer if not exists.
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result
 *****************************************************************************/
S32 RngcCreateDir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S8 fileBuf[MAX_IMAGE_NAME_PATH_WIDTH + RNGC_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(RINGCOMPOSER_PATH, 0, sizeof(RINGCOMPOSER_PATH));
    sprintf(fileBuf, "%c:\\", MMI_PUBLIC_DRV);

    /* create file directory if not exists */
    mmi_asc_to_ucs2((S8*) RINGCOMPOSER_PATH, (S8*) fileBuf);

    mmi_ucs2cat((S8*) RINGCOMPOSER_PATH, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);

    file_handle = FS_Open((U16*) RINGCOMPOSER_PATH, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        return FS_CreateDir((U16*) RINGCOMPOSER_PATH);
    }
    else
    {
        FS_Close(file_handle);
        return FS_NO_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcGetFileInfo
 * DESCRIPTION
 *  Get file info from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(?)
 *****************************************************************************/
void RngcGetFileInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(mmi_fmgr_kernel_get_cur_idx(), &file_info);
    mmi_ucs2cpy(g_rngc_cntx.FileName, (S8*) file_info.file_name);
    /* mmi_rngc_filename_callback((void*)file_info.file_name); */
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecPlay
 * DESCRIPTION
 *  Prepare temporary file and entry play screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcGetFileInfo();
    mmi_ucs2cpy((S8*) g_rngc_cntx.PrevFileName, (S8*) g_rngc_cntx.FileName);
    EntryRngcPlayTone();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcPlay
 * DESCRIPTION
 *  Highlight handler of play option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecPlay, KEY_EVENT_UP);
    SetKeyHandler(RngcExecPlay, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecEdit
 * DESCRIPTION
 *  Execute Edit command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcGetFileInfo();
    g_rngc_cntx.CurrEditState = ENUM_COMP_EDIT;
#ifndef WIN32
    EditMelody((U8*) g_rngc_cntx.FileName);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcEdit
 * DESCRIPTION
 *  Highlight handler of Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecEdit, KEY_EVENT_UP);
    SetKeyHandler(RngcExecEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecAdd
 * DESCRIPTION
 *  Execute Add command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecAdd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrEditState = ENUM_COMP_ADD;
#ifndef WIN32
    FreeMemory();
    EntryRngcComposerEngine();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcAdd
 * DESCRIPTION
 *  Highlight handler of Add option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcAdd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecAdd, KEY_EVENT_UP);
    SetKeyHandler(RngcExecAdd, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecRename
 * DESCRIPTION
 *  Execute rename command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcGetFileInfo();
    g_rngc_cntx.CurrEditState = ENUM_COMP_RENAME;
    SetRingToneFilenameBuf();
    EntryRngcEditFileName();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcRename
 * DESCRIPTION
 *  Highlight handler of Rename option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcRename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecRename, KEY_EVENT_UP);
    SetKeyHandler(RngcExecRename, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcDelete
 * DESCRIPTION
 *  Highlight handler of Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryRngcDeleteToneConfirm, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  InitRingToneComposer
 * DESCRIPTION
 *  1. initialize handler
 *  2. reset global variables
 *  3. read data from NVRAM
 *  4. Sync files and file indices
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(?)
 *****************************************************************************/
void InitRingToneComposer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* highlight handler */
    SetHiliteHandler(MENU3103_RINGTONE_COMPOSER, HighlightRngcMenu);
    SetHiliteHandler(MENU_COMP_RINGTONE_COMP_SELPLAY, HighlightRngcPlay);
    SetHiliteHandler(MENU_COMP_RINGTONE_COMP_SELEDIT, HighlightRngcEdit);
    SetHiliteHandler(MENU_COMP_RINGTONE_COMP_SELADD, HighlightRngcAdd);
    SetHiliteHandler(MENU_COMP_RINGTONE_COMP_SELRENAME, HighlightRngcRename);
    SetHiliteHandler(MENU_COMP_RINGTONE_COMP_SELDELETE, HighlightRngcDelete);
    /* reset global context */
    memset(&g_rngc_cntx, 0, sizeof(g_rngc_cntx));
    g_rngc_cntx.CurrInstr = INSTR_PIANO;
    g_rngc_cntx.CurrSpeed = NORMAL_SPEED;
    /*
     * sync file system,
     * create dir if not exists.
     */
    RngcCreateDir();

}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcMenu
 * DESCRIPTION
 *  Highlight handler for Ring Tone Composer menu in FunAndGame
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(?)
 *****************************************************************************/
void HighlightRngcMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryRngcApp, KEY_EVENT_UP);
    SetKeyHandler(EntryRngcApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_dummy_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_dummy_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcApp
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    FMGR_FILTER filter;
    S32 fs_result = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_IMY);
    
    fs_result = RngcCreateDir();
    if(fs_result != FS_NO_ERROR)
    {
        DisplayPopup(
            (U8*) GetString(GetFileSystemErrorString(fs_result)),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    mmi_fmgr_select_path_and_enter(
        APP_RINGTONECOMPOSER,
        FMGR_SELECT_BROWSE,
        filter,
        (S8*) RINGCOMPOSER_PATH,
        mmi_rngc_dummy_callback);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcCompTone
 * DESCRIPTION
 *  Highlight handler when selecting a composed tone
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcCompTone(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrTone = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcMainMenuOptList
 * DESCRIPTION
 *  Display available options for a composed tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcMainMenuOptList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 RingToneOptionList[ENUM_COMP_OPT_TOTAL];
    U16 noOfChildren;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_COMPOSE_RINGTONE_OPTION);

    EntryNewScreen(SCR_COMPOSE_RINGTONE_OPTION, NULL, EntryRngcMainMenuOptList, NULL);

    GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_SELMENU_1, RingToneOptionList);
    SetParentHandler(MENU_COMP_RINGTONE_COMP_SELMENU_1);
    noOfChildren = GetNumOfChild(MENU_COMP_RINGTONE_COMP_SELMENU_1);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noOfChildren,
        RingToneOptionList,
        (PU16) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SetRingToneFilenameBuf
 * DESCRIPTION
 *  Fill filename buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRingToneFilenameBuf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrEditState)
    {
        case ENUM_COMP_ADD: /* insert default filename */
        {
            MYTIME TodayDateTime;
            S8 dummyString[RNGC_FILE_LEN];  /* RMMDDHHMM */
            S8 fullName[RNGC_FILE_LEN];
            S8 extName[RNGC_FILE_LEN];
            S32 i;

            mmi_asc_to_ucs2(extName, MELODY_FILE_EXTENSION);
            GetDateTime(&TodayDateTime);
            sprintf(
                dummyString,
                "R%02d%02d%02d%02da",
                TodayDateTime.nMonth,
                TodayDateTime.nDay,
                TodayDateTime.nHour,
                TodayDateTime.nMin);

            for (i = 0; i < RNGC_MAX_ENG_CHAR; i++)
            {
                mmi_asc_to_ucs2(fullName, dummyString);
                mmi_ucs2cat(fullName, extName);

                if (!IsCompToneExisted(fullName))
                {
                    break;
                }

                dummyString[9] = 'a' + i + 1;
            }

            mmi_asc_to_ucs2(g_rngc_cntx.FileName, dummyString);
            break;
        }
        default:
            break;
    }
    mmi_ucs2cpy((S8*) g_rngc_cntx.PrevFileName, (S8*) g_rngc_cntx.FileName);
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcDeleteToneConfirm
 * DESCRIPTION
 *  Entry delete confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcDeleteToneConfirm(void)
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
        get_string(STR_CAP_COMP_RINGTONE_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DeleteCompRingTone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set exit handler to NULL because does have have to add to history */
}


/*****************************************************************************
 * FUNCTION
 *  DeleteCompRingTone
 * DESCRIPTION
 *  1. Delete file index
 *  2. Delete real file
 *  3. Display popup screen accoding to result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteCompRingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    S8 fileBuf[MAX_IMAGE_NAME_PATH_WIDTH + RNGC_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcGetFileInfo();
    mmi_ucs2cpy((S8*) fileBuf, (S8*) RINGCOMPOSER_PATH);
    mmi_ucs2cat((S8*) fileBuf, (S8*) g_rngc_cntx.FileName);

    if (FS_Delete((U16*) fileBuf) != 0)
    {
        result = FALSE;
    }
    else
    {
        result = TRUE;
    }

    if (result) /* successfully, display "Done" screen */
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else    /* unsucessfully, display "Unfinished" */
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteUptoScrID(SCR_FMGR_EXPLORER);

}


/*****************************************************************************
 * FUNCTION
 *  CompRingTonePlayFinishInd
 * DESCRIPTION
 *  Message handler of PRT_EQ_PLAY_AUDIO_FINISH_IND, go back to previous screen
 * PARAMETERS
 *  result      [IN]        
 *  info(?)     [IN]        Local paramater of PRT_EQ_PLAY_AUDIO_FINISH_IND message
 * RETURNS
 *  void
 *****************************************************************************/
void CompRingTonePlayFinishInd(mdi_result result)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_cntx.IsSelfStop == FALSE && result == MDI_AUDIO_TERMINATED)
    {
        g_rngc_cntx.IsTonePlaying = FALSE;
        GoBackHistory();
    }
    else if (result != MDI_AUDIO_SUCCESS && result != MDI_AUDIO_TERMINATED)
    {
        GoBackHistory();
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  RngcStopToneAndGoBackHistory
 * DESCRIPTION
 *  Stop iMelody and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcStopToneAndGoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.IsSelfStop = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  RngcStopToneAndGoToIdle
 * DESCRIPTION
 *  Stop iMelody and go to IDLE screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcStopToneAndGoToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.IsSelfStop = TRUE;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  RngcPlayToneCallBack
 * DESCRIPTION
 *  1. Call back function when play finished.
 *  2. delete temporary file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcPlayToneCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[RNGC_FILE_LEN + 80]; /* for path name */
    S8 fileName[RNGC_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_asc_to_ucs2(fileName, (S8*)RNGC_TEMP_FILE_NAME); */
    mmi_ucs2cpy((S8*) fileName, (S8*) FMGR_TEMP_FILE_MELODY);
#ifndef WIN32	
    GenerateCompleteComposeFileName((S8*) fileName, (S8*) fileBuf);
#endif
    FS_Delete((U16*) fileBuf);
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcPlayTone
 * DESCRIPTION
 *  1. Display playing screen.
 *  2. Stop LED pattern.
 *  3. Play iMedloy file by name and file id.
 *  4. Set playing flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcPlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileBuf = (S8*)OslMalloc(RNGC_FILE_LEN + 80); /* for path name */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) fileBuf, (S8*) RINGCOMPOSER_PATH);
    mmi_ucs2cat((S8*) fileBuf, (S8*) g_rngc_cntx.PrevFileName);
    mmi_audply_play_in_melody_composer((UI_string_type) fileBuf, RngcPlayToneCallBack);
    OslMfree(fileBuf);
}


/*****************************************************************************
 * FUNCTION
 *  ExitRngcPlayTone
 * DESCRIPTION
 *  Exit handler of EntryRngcPlayTone
 *  1. Stop playing file.
 *  2. Reset IsTonePlaying flag.
 *  3. Restore LED pattern.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitRngcPlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[RNGC_FILE_LEN];  /* for path name */
    S8 fileName[RNGC_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_EQ_PLAY_AUDIO_FINISH_IND);

    /* stop playing file */
    if (g_rngc_cntx.IsTonePlaying == TRUE)
    {
        mdi_audio_stop_file();
    }

    /* reset flag */
    g_rngc_cntx.IsTonePlaying = FALSE;

    /* mmi_asc_to_ucs2(fileName, (S8*)RNGC_TEMP_FILE_NAME); */
    mmi_ucs2cpy((S8*) fileName, (S8*) FMGR_TEMP_FILE_MELODY);
#ifndef WIN32	
    GenerateCompleteComposeFileName((S8*) fileName, (S8*) fileBuf);
#endif
    FS_Delete((U16*) fileBuf);

    /* restore LED pattern */
    StartLEDPatternBackGround();
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcCompToneOptList
 * DESCRIPTION
 *  Display available options when composing a rnig tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcCompToneOptList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[ENUM_ADD_TONE_OPT_TOTAL];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop multitap timer of tone editor screen */
    StopTimer(NOTE_MULTITAP_TIMER);

    EntryNewScreen(SCR_COMP_RINGTONE_ADD_OPT, NULL, EntryRngcCompToneOptList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_COMP_RINGTONE_ADD_OPT);

    SetParentHandler(MENU_COMP_RINGTONE_COMP_ADDOPT);

    nItems = GetNumOfChild(MENU_COMP_RINGTONE_COMP_ADDOPT);
    GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_ADDOPT, ItemList);
    RegisterHighlightHandler(HighlightRngcCompToneOpt);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(RngcGotoSelectedCompToneOpt, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcCompToneOpt
 * DESCRIPTION
 *  Highlight handler of EntryRngcCompToneOptList
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcCompToneOpt(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrHiliteItem = (U8) nIndex;

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register right key handler if current highlight is on "Play speed" or "Instrument" */
    if (nIndex != ENUM_ADD_TONE_OPT_SAVE)   /* play speed and select instrument */
    {
        SetKeyHandler(RngcGotoSelectedCompToneOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcGotoSelectedCompToneOpt
 * DESCRIPTION
 *  Entry selected option when adding a tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcGotoSelectedCompToneOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrHiliteItem)
    {
        case ENUM_ADD_TONE_OPT_PLAY:    /* Play */
			#ifndef WIN32
            if (g_rngc_eng_cntx->TotalNotes > 0)
            {
                S32 err;

                //                              if(g_rngc_cntx.CurrEditState == ENUM_COMP_ADD)
                //                              mmi_asc_to_ucs2((S8*)g_rngc_cntx.PrevFileName,(S8*)RNGC_TEMP_FILE_NAME);
                mmi_ucs2cpy((S8*) g_rngc_cntx.PrevFileName, (S8*) FMGR_TEMP_FILE_MELODY);
				
                err = GenerateMelodyFile((S8*) g_rngc_cntx.PrevFileName);
	
                if (err == 0)
                {
                    EntryRngcPlayTone();
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(GetFileSystemErrorString(err)),
                        IMG_GLOBAL_ERROR,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        ERROR_TONE);
                }
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_COMP_RINGTONE_EMPTYRINGTONE),
                    IMG_GLOBAL_WARNING,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
            }
		#endif		
            break;
        case ENUM_ADD_TONE_OPT_SPEED:   /* Play Speed */
            EntryRngcPlaySpeed();
            break;
        case ENUM_ADD_TONE_OPT_INSTR:   /* Select Instrument */
            EntryRngcInstrument();
            break;
        case ENUM_ADD_TONE_OPT_SAVE:    /* Save File */
		#ifndef 	WIN32
            if (g_rngc_eng_cntx->TotalNotes > 0)
            {
                SetRingToneFilenameBuf();
                EntryRngcEditFileName();
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_COMP_RINGTONE_EMPTYRINGTONE),
                    IMG_GLOBAL_WARNING,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
            }
			#endif
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcPlaySpeed
 * DESCRIPTION
 *  Entry function of "Play Speed" item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcPlaySpeed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[ENUM_SPEED_TOTAL]; /* Stores the strings id of submenus returned */
    U16 nItems;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_COMP_RINGTONE_SPEED, NULL, EntryRngcPlaySpeed, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_COMP_RINGTONE_SPEED);
    SetParentHandler(MENU_COMP_RINGTONE_COMP_PLAY_SPEED);

    nItems = GetNumOfChild(MENU_COMP_RINGTONE_COMP_PLAY_SPEED);
    GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_PLAY_SPEED, ItemList);

    RegisterHighlightHandler(HighlightRngcGenericOptHdlr);

    ShowCategory11Screen(
        STR_COMP_RINGTONE_PLAY_SPEED,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (U16) GetIndexCurrCompRingToneSpeed(),
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SetCurrCompRingToneSpeed, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcGenericOptHdlr
 * DESCRIPTION
 *  Generic highlight handler of each screen
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcGenericOptHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrHiliteItem = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrCompRingToneSpeed
 * DESCRIPTION
 *  Set ring tone speed to selected one.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrCompRingToneSpeed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrHiliteItem)
    {
        case 0: /* fast */
            g_rngc_cntx.CurrSpeed = FAST_SPEED;
            break;
        case 1: /* normal */
            g_rngc_cntx.CurrSpeed = NORMAL_SPEED;
            break;
        case 2: /* slow */
            g_rngc_cntx.CurrSpeed = SLOW_SPEED;
            break;
        default:
            break;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexCurrCompRingToneSpeed
 * DESCRIPTION
 *  Retrieve the item index of selected speed.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : index of selected speed
 *****************************************************************************/
U8 GetIndexCurrCompRingToneSpeed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrSpeed)
    {
        case FAST_SPEED:
            return ENUM_SPEED_FAST;     /* GetIndexOfStringId(MENU_COMP_RINGTONE_COMP_PLAY_SPEED,MENU_COMP_RINGTONE_FAST); */
        case NORMAL_SPEED:
            return ENUM_SPEED_NORMAL;   /* /GetIndexOfStringId(MENU_COMP_RINGTONE_COMP_PLAY_SPEED,MENU_COMP_RINGTONE_NORMAL); */
        case SLOW_SPEED:
            return ENUM_SPEED_SLOW;     /* GetIndexOfStringId(MENU_COMP_RINGTONE_COMP_PLAY_SPEED,MENU_COMP_RINGTONE_SLOW); */
        default:
            return (U8) 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcInstrument
 * DESCRIPTION
 *  Entry function of "Select Instrument" item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcInstrument(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[10];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_COMP_RINGTONE_INSTRUMENT, NULL, EntryRngcInstrument, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_COMP_RINGTONE_INSTRUMENT);
    SetParentHandler(MENU_COMP_RINGTONE_COMP_SEL_INST);

    nItems = GetNumOfChild(MENU_COMP_RINGTONE_COMP_SEL_INST);
    GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_SEL_INST, ItemList);

    RegisterHighlightHandler(HighlightRngcGenericOptHdlr);

    ShowCategory52Screen(
        STR_COMP_RINGTONE_SEL_INST,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        (U32) GetCurrIndexCompRingToneInst(),
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(SetCurrCompRingToneInstrument, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrIndexCompRingToneInst
 * DESCRIPTION
 *  Retrieve the index of instrument for highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : the item index of selected instrument
 *****************************************************************************/
U8 GetCurrIndexCompRingToneInst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 110805 ringtonecomposer Calvin Start */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 

    S32 i;
#ifndef WIN32
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ENUM_TOTAL_INSTR; i++)
    {
        if ((U8) g_rngc_cntx.CurrInstr == CurrentInstrument[i])
        {
            return i;
        }
    }
    return (U8) 0;
#endif
#endif /* 0 */ 
    /* 110805 ringtonecomposer Calvin End */
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrCompRingToneInstrument
 * DESCRIPTION
 *  Save the instrument according to selection
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : the item index of selected instrument(?)
 *****************************************************************************/
void SetCurrCompRingToneInstrument(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 110805 ringtonecomposer Calvin Start */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef WIN32
    g_rngc_cntx.CurrInstr = CurrentInstrument[g_rngc_cntx.CurrHiliteItem];
#endif
#endif /* 0 */ 
    /* 110805 ringtonecomposer Calvin End */

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  RngcGoBackFromEditor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcGoBackFromEditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__)
    mmi_ucs2cpy((S8*) g_rngc_cntx.FileName, (S8*) g_rngc_cntx.PrevFileName);
#endif 
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcEditFileName
 * DESCRIPTION
 *  Display full screen editor for editing filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcEditFileName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 filenameExt[16];
    U8 FileLen = 0;
    U8 ExtLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_COMP_RINGTONE_SAVEFILE, NULL, EntryRngcEditFileName, NULL);

    /* remove file extension */
    FileLen = (U8) mmi_ucs2strlen((S8*) g_rngc_cntx.FileName);
    ExtLen = strlen((S8*) MELODY_FILE_EXTENSION);

    mmi_ucs2_to_asc((S8*) filenameExt, (S8*) & g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH]);
#ifndef WIN32
    if (!StrnCmp((S8*) filenameExt, (S8*) MELODY_FILE_EXTENSION, ExtLen))
    {
        g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH] = '\0';
    }
#endif
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_COMP_RINGTONE_SAVEFILE);

    /* Set current parent id */
    /* SetParentHandler(0); */

    ShowCategory5Screen(
        STR_COMP_RINGTONE_FILENAME,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_rngc_cntx.FileName,
        RNGC_INPUT_FILE_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryRngcEditFilenameOptList, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(RngcGoBackFromEditor /* GoBackHistory */ , KEY_EVENT_UP);
    GetCurrEndKeyDownHandler();
    SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcEditFilenameOptList
 * DESCRIPTION
 *  Display list of options when editing filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcEditFilenameOptList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_COMP_RINGTONE_SAVE_OPT, NULL, EntryRngcEditFilenameOptList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_COMP_RINGTONE_SAVE_OPT);
    SetParentHandler(MENU_COMP_RINGTONE_SAVE_TONE);

    nItems = GetNumOfChild(MENU_COMP_RINGTONE_SAVE_TONE);
    GetSequenceStringIds(MENU_COMP_RINGTONE_SAVE_TONE, ItemList);

    RegisterHighlightHandler(GetCompRingToneSaveOpt);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(RngcGotoEditFinenameOpt, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  GetCompRingToneSaveOpt
 * DESCRIPTION
 *  Retrive the option index when editing filename
 * PARAMETERS
 *  nIndex      [IN]        Index of selected item
 * RETURNS
 *  void
 *****************************************************************************/
void GetCompRingToneSaveOpt(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrHiliteItem = (U8) nIndex;
    switch (g_rngc_cntx.CurrHiliteItem)
    {
        case 0: /* Done */
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
            break;
        case 1: /* Input Methods */
            SetKeyHandler(RngcGotoEditFinenameOpt, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcGotoEditFinenameOpt
 * DESCRIPTION
 *  Entry selected option when editing filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcGotoEditFinenameOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrHiliteItem)
    {
        case 0: /* Done */
            RngcDisplayPopupAfterSave();
            break;
        case 1: /* Input Methods */
            EntryInputMethodScreen();
            RegisterInputMethodScreenCloseFunction(GoBacknHistoryFromInputMethod);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBacknHistoryFromInputMethod
 * DESCRIPTION
 *  Go back 1 history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBacknHistoryFromInputMethod(void)
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
 *  RngcDisplayPopupAfterSave
 * DESCRIPTION
 *  Save composed tone and display corresponding popup screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcDisplayPopupAfterSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err = SetSaveCompRingTone();
    /*add for orignal file name buffer*/
    if(err != 0)
    {
        mmi_ucs2cpy((S8*)g_rngc_cntx.FileName, (S8*)g_rngc_cntx.EditFileNameBuffer);
    }
    
    if (err == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SAVE_TONE);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
    }
    else if (err == RC_DUP_FILENAME)
    {
        DisplayPopup(
            (U8*) GetString(STR_COMP_RINGTONE_DUPLICATE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_COMP_RINGTONE_SAVEFILE);
    }
    else if (err == RC_EMPTY_FILENAME)
    {
        DisplayPopup(
            (U8*) GetString(STR_COMP_RINGTONE_EMPTYFILENAME),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_COMP_RINGTONE_SAVEFILE);
    }
    else if (err == RC_FILENAME_ERR)
    {
        DisplayPopup(
            (U8*) GetString(FMGR_FS_INVALID_FILENAME_TEXT),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_COMP_RINGTONE_SAVEFILE);        
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(err)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_COMP_RINGTONE_SAVEFILE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetSaveCompRingTone
 * DESCRIPTION
 *  Save composed tone
 *  1. Generate file and save to file system.
 *  2. Insert entry into info table and save to NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  Error codes
 *****************************************************************************/
S32 SetSaveCompRingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 err = 0;
    PS8 p_skip_space;
    S8 filenameExt[16];
    S32 fname_len;
    S8 sFileBuf[RNGC_FILE_LEN + MAX_IMAGE_NAME_PATH_WIDTH];
    S8 sFileNewBuf[RNGC_FILE_LEN + MAX_IMAGE_NAME_PATH_WIDTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* skip the spaces before filename if any. */
    /*add for orignal file name buffer*/
    mmi_ucs2cpy((S8*)g_rngc_cntx.EditFileNameBuffer, (S8*)g_rngc_cntx.FileName);
    p_skip_space = mmi_fmgr_skip_space((S8*) g_rngc_cntx.FileName);

    /* if user's input is empty */
    if (!mmi_ucs2strlen((S8*) p_skip_space))
    {
        return RC_EMPTY_FILENAME;
    }
    
    /* check if the filename is valid */
    if (!mmi_fmgr_is_filename_valid((PS8) g_rngc_cntx.FileName))
    {
        return RC_FILENAME_ERR;
    }

    if (p_skip_space != g_rngc_cntx.FileName)
    {
        mmi_ucs2cpy((PS8)sFileBuf, (PS8)p_skip_space);
        mmi_ucs2cpy((PS8)g_rngc_cntx.FileName,(PS8)sFileBuf);
    }

    /* add file extension */
    fname_len = mmi_ucs2strlen((S8*) g_rngc_cntx.FileName) - strlen((S8*) MELODY_FILE_EXTENSION);
    
    if ( (fname_len <= 0)  || mmi_ucs2cmp((S8*) &g_rngc_cntx.FileName[fname_len * ENCODING_LENGTH], (S8*) filenameExt))
    {
        mmi_asc_to_ucs2((S8*) filenameExt, (S8*) MELODY_FILE_EXTENSION);
        mmi_ucs2cat((S8*) g_rngc_cntx.FileName, (S8*) filenameExt);
    }

    /* to check if there is some duplicated file name exits */
    if (g_rngc_cntx.CurrEditState)  /* rename or edit */
    {
        /* if the new filename is different from previous file name */
        if (mmi_ucs2cmp((S8*) g_rngc_cntx.FileName, (S8*) g_rngc_cntx.PrevFileName))
            if (IsCompToneExisted((S8*) g_rngc_cntx.FileName))
            {
                return RC_DUP_FILENAME;
            }
    }
    else    /* add new file */
    {
        if (IsCompToneExisted((S8*) g_rngc_cntx.FileName))
        {
            return RC_DUP_FILENAME;
        }
    }

    switch (g_rngc_cntx.CurrEditState)
    {
        case ENUM_COMP_ADD:
        {
			#ifndef WIN32
            err = GenerateMelodyFile((S8*) g_rngc_cntx.FileName);

            if (err != RC_SUCCESS)
            {
                return err;
            }
            else
            {          
                FreeMemory();	    
            }
		#endif	
            break;
        }
        case ENUM_COMP_EDIT:
        {
			 #ifndef WIN32
            err = GenerateMelodyFile((S8*) g_rngc_cntx.FileName);

            if (err != RC_SUCCESS)
            {
                return err;
            }
            else
            {           
                FreeMemory();

                /* filename changed, delete previous file */
                if (mmi_ucs2cmp((S8*) g_rngc_cntx.FileName, (S8*) g_rngc_cntx.PrevFileName))
                {	
                    GenerateCompleteComposeFileName((S8*) g_rngc_cntx.PrevFileName, (S8*) sFileBuf);	
                    FS_Delete((U16*) sFileBuf); /* do not have to handle error case because there exits file sync mechanism */
                }
            }
	            #endif		
            break;
        }
        case ENUM_COMP_RENAME:
            mmi_ucs2cpy((S8*) sFileNewBuf, (S8*) RINGCOMPOSER_PATH);
            mmi_ucs2cpy((S8*) sFileBuf, (S8*) sFileNewBuf);
            mmi_ucs2cat((S8*) sFileBuf, (S8*) g_rngc_cntx.PrevFileName);
            mmi_ucs2cat((S8*) sFileNewBuf, (S8*) g_rngc_cntx.FileName);
            if (mmi_ucs2cmp(sFileBuf, sFileNewBuf))
            {
                if ((err = FS_Rename((U16 *)sFileBuf, (U16 *)sFileNewBuf)) < 0)
                {
                    return err;
                }
            }

            break;

        default:
            break;
    }

    err = RC_SUCCESS;
    return err;
}


/*****************************************************************************
 * FUNCTION
 *  GetComposedIMelodyInfo
 * DESCRIPTION
 *  Retrieve file info and total number of composed tones
 * PARAMETERS
 *  downloadAudioInfo       [IN/OUT]        Pointer to get file info
 * RETURNS
 *  total number of composed tones
 *****************************************************************************/
U8 GetComposedIMelodyInfo(DYNAUDIOINFO **downloadAudioInfo)
{
#if !defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *downloadAudioInfo = g_rngc_cntx.RingToneInfo;
    return g_rngc_cntx.TotalTone;
#else /* !defined(__MMI_FILE_MANAGER__) */ 
    return 0;
#endif /* !defined(__MMI_FILE_MANAGER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetComposedIMelodyNameInFileSystem
 * DESCRIPTION
 *  Retrieve filename from id
 * PARAMETERS
 *  AudioId     [IN]        File index
 * RETURNS
 *  pointer of filename
 *****************************************************************************/
S8 *GetComposedIMelodyNameInFileSystem(U16 AudioId)
{
#if !defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AudioId >= COMPOSED_RINGTONE_BASE && AudioId <= COMPOSED_RINGTONE_BASE_END)
    {
        for (i = 0; i < g_rngc_cntx.TotalTone; i++)
        {
            if (g_rngc_cntx.RingToneInfo[i].AudioId == AudioId)
            {
                return (S8*) g_rngc_cntx.RingToneInfo[i].AudioName;
            }
        }
    }
#endif /* !defined(__MMI_FILE_MANAGER__) */ 
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  IsCompToneExisted
 * DESCRIPTION
 *  To check if file already exists
 * PARAMETERS
 *  filename        [IN]        Filename without path
 * RETURNS
 *  1 == true, 0 == false
 *****************************************************************************/
U8 IsCompToneExisted(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 sFileBuf[RNGC_FILE_LEN + MAX_IMAGE_NAME_PATH_WIDTH];
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef WIN32	
    GenerateCompleteComposeFileName((S8*) filename, (S8*) sFileBuf);
	#endif

    h = FS_Open((U16*) sFileBuf, FS_READ_ONLY);
    if (h > 0)
    {
        FS_Close(h);
        return 1;
    }

    return 0;
}

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)

#endif /* _MMI_COMPOSERINGTONE_C */ // #ifndef _MMI_COMPOSERINGTONE_C

