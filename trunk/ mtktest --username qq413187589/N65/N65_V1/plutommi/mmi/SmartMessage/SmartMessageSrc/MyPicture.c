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
 * MyPicture.c
 *
 * Project:
 * --------
 * PDG-1
 *
 * Description:
 * ------------
 * This file implements procedures to save and retreive ringtones.
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

   FILENAME : MyPicture.c

   PURPOSE     : Main function to save and retreive pictures

   REMARKS     : nil

   AUTHOR      : JaiPrakash S.

   DATE     : Oct-11-2004

**************************************************************/
#include "MMI_include.h"
#ifdef __MOD_SMSAL__
/*  Include: MMI header file */

/* ... Add More MMI header */
#include "CommonScreens.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "mmi_msg_context.h"
#include "CellBroadcastType.h"
#ifdef __MMI_MESSAGES_CHAT__
#include "ChatAppGprot.h"
#include "ChatAppResDef.h"
#include "ChatGtype.h"
#include "ChatAppGexdcl.h"
#endif /* __MMI_MESSAGES_CHAT__ */ 
#include "DownloadProtos.h"
#include "DownloadDefs.h"
#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
#include "ProtocolEvents.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
/*  */
#include "smsal_l4c_enum.h"
/*  */
/*  */
#include "CSP.h"
#include "MainMenuDef.h"
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "CallhistoryEnum.h"
#include "MiscFunctions.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "IdleAppProt.h"
#include "AlarmFrameworkProt.h"
#include "CallsDefs.h"
#include "wgui_status_icons.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "PicMsgApiToOthers.h"
#include "MyPicture.h"
#include "MyTone.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif 
#include "FileMgr.h"
#include "FileManagerDef.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */


#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
extern S32 mmi_nsm_send_pic_msg(U8 *bmpDataPtr, U8 *PicTextPtr);
extern U32 mmi_smrt_midi_file_size(U8 *midifile);
S8 PictureMessageDir[NSM_FILE_NAME_BUFF];
U8 gNSMBuffer[1024];    /* Global buffer for NSM picture and ringtone message */
U8 gaddtext_buffer[MAX_PICMSG_DEFAULT_DCS_TEXT_LEN];
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if defined(__MMI_MYPICTURE__)
U8 gaddtext_buffer[320];
U8 gfilecount = 0;
void display_nsm_mypicture_list(void);
extern U16 gSelected_Item;
extern U8 gfilecount;
extern PendingSaveSendDataStruct PendingSaveSendData;


/*****************************************************************************
 * FUNCTION
 *  highlight_mypic_handler
 * DESCRIPTION
 *  Highlight handler for My Picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mypic_handler(void)
{
    
#if defined(__MMI_FILE_MANAGER__)
    SetLeftSoftkeyFunction(mmi_mypic_pre_entry_mypic_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_mypic_pre_entry_mypic_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_FILE_MANAGER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_pre_entry_mypic_list
 * DESCRIPTION
 *  Pre Entry function to display list of pictures in My Picture
 * CALLS
 *  mmi_nsm_get_list        To get picture list in My Picture
 *  mmi_mypic_entry_mypic_list To display picture list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_pre_entry_mypic_list(void)
{
#if defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 DirPath[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gNSMBuffer, '\0', 1024);
    memset(gaddtext_buffer, '\0', 320);

    memset(DirPath, '\0', sizeof(DirPath));
    display_nsm_mypicture_list();

#endif /* defined(__MMI_FILE_MANAGER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  display_nsm_mypicture_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void display_nsm_mypicture_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 DirPath[64];
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(PictureMessageDir, 0x00, NSM_FILE_NAME_BUFF);
    /* Get directory path for My Picture */
    sprintf(DirPath, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) "Images\\");

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    /* mmi_ucs2cat((S8*)DirPath, ( S8*)FMGR_DEFAULT_FOLDER_IMAGES); */
    mmi_asc_to_ucs2((S8*) PictureMessageDir, (S8*) DirPath);     // DirPath/*.*

    mmi_fmgr_select_path_and_enter(
        APP_MESSAGES,
        FMGR_SELECT_FILE,
        filter,
        (PS8) PictureMessageDir,
        (PsExtFuncPtr) mmi_mypic_pre_entry_display_pic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_pre_entry_display_pic
 * DESCRIPTION
 *  Entry function to display selected pictures in My Picture
 * CALLS
 *  mmi_get_file_data    To get file data in global buffer gNSMBuffer
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_pre_entry_display_pic(PU16 filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    INT wByte = 0;
    S16 Result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackHistory();
        return;
    }

    file_handle = FS_Open(filePath, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_Read( file_handle, (void*)gNSMBuffer, 1024, &wByte);
        FS_Close(file_handle);
    }
    Result = mmi_pmsg_add_bmp_header_info(gNSMBuffer);
    if (Result != 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    mmi_mypic_entry_display_pic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_entry_display_pic
 * DESCRIPTION
 *  Display a picture message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_entry_display_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MYPIC_DISPLAY, mmi_msg_exit_generic, mmi_mypic_entry_display_pic, NULL);
    DeleteScreenIfPresent(SCR_FMGR_EXPLORER);

    mmi_nsm_set_msg_type(PICTURE_MESSAGE);
    SetMessagesCurrScrnID(SCR_ID_MYPIC_DISPLAY);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MYPIC_DISPLAY);

    ShowCategory620Screen(
        STR_ID_NSM_PICTURE,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        gaddtext_buffer,
        NULL,
        gNSMBuffer,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_mypic_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_mypic_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_entry_options
 * DESCRIPTION
 *  Entry function to display My Picture options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MYPIC_OPTION, mmi_msg_exit_generic, mmi_mypic_entry_options, NULL);
    SetMessagesCurrScrnID(SCR_ID_MYPIC_OPTION);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MYPIC_OPTION);
    numItems = GetNumOfChild(MENU_ID_MY_PICTURE);
    GetSequenceStringIds(MENU_ID_MY_PICTURE, nStrItemList);
    SetParentHandler(MENU_ID_MY_PICTURE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

#endif /* defined(__MMI_MYPICTURE__) */ 

#if defined(__MMI_MYPICTURE__) || defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_create_dir
 * DESCRIPTION
 *  Create a directory at the given path
 * PARAMETERS
 *  DirnameInAnsii      [?]         
 *  DirPath(?)          [IN]        DirPath in Ansii
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_create_dir(S8 *DirnameInAnsii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE file_handle;
    S8 DirnameInUnicode[96];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) DirnameInUnicode, (S8*) DirnameInAnsii);

    file_handle = FS_Open((PU16) DirnameInUnicode, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle < 0)
    {
        FS_CreateDir((U16*)DirnameInUnicode);

    }
    FS_Close(file_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_save_buffer_in_file
 * DESCRIPTION
 *  Create a file and save buffer in that file
 * PARAMETERS
 *  fullfilenameInUnicode       [IN]        Absolute file name in Unicode
 * RETURNS
 * BOOL
 *****************************************************************************/
U16 mmi_nsm_save_buffer_in_file(S8 *fullfilenameInUnicode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    INT file_handle;

    // S8 fullfilenameInUnicode[128];   /* JP to fix MTK Chinese file name */
    U32 wByte = 0;
    U16 BufferSize = 0;
    S32 result;
    S8 temp[NSM_DIRECTORY_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // memset(fullfilenameInUnicode,0x00,128);  /* JP to fix MTK Chinese file name */

    memset(temp, '\0', NSM_DIRECTORY_BUFF);

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        sprintf(temp, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) MYPICTURE_DIR_PATH);
    }
    if (mmi_nsm_get_msg_type() == RINGTONE_MESSAGE)
    {
        sprintf(temp, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) MY_TONE_PATH);
    }

    mmi_nsm_create_dir(temp);

    if (mmi_nsm_is_file_exist(fullfilenameInUnicode))
    {
        return NSM_DUPLICATE_FILE_4;
    }

    file_handle = FS_Open((const U16*)fullfilenameInUnicode, (FS_CREATE_ALWAYS | FS_READ_WRITE));

    if (file_handle == FS_DISK_FULL)
    {
        return NSM_SPACE_FULL_3;
    }
    else if (file_handle == FS_INVALID_FILENAME)
    {
        return NSM_FILE_ERROR_5;
    }
    else if (file_handle < 0)
    {
        return NSM_COMMOM_ERROR_6;
    }

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        BufferSize = mmi_pmsg_get_size_bmp_data((U8*) gNSMBuffer);     /* /-6;: JP for Operator Logo */
        /* pfwrite((gNSMBuffer+6),      1, BufferSize, file_handle, &wByte); */
        result = FS_Write(file_handle, (void*)(gNSMBuffer + 6), BufferSize, &wByte);
    }
    else
    {
        BufferSize = mmi_smrt_midi_file_size((U8*) gNSMBuffer);
        /* write(gNSMBuffer,    1, BufferSize, file_handle, &wByte); */
        result = FS_Write(file_handle, (void*)(gNSMBuffer), BufferSize, &wByte);
    }

    /* JP for Disk full File Manager issue */
    if (result < 0)
    {
        if (result == FS_DISK_FULL)
        {   /* Disk full */

            FS_Close(file_handle);
            FS_Delete((const U16*)fullfilenameInUnicode);
            return NSM_SPACE_FULL_3;
        }

        FS_Close(file_handle);
        return NSM_COMMOM_ERROR_6;
    }

    FS_Close(file_handle);
    return NSM_SUCCESS_0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_is_file_exist
 * DESCRIPTION
 *  Checks for duplicate file
 * PARAMETERS
 *  fullfilenameInUnicode       [IN]        Absolute file name in Unicode
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_nsm_is_file_exist(S8 *fullfilenameInUnicode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h = FS_Open((U16*)fullfilenameInUnicode, FS_READ_ONLY);
    if (h > 0)
    {
        FS_Close(h);
        return TRUE;
    }
    return FALSE;
}

#endif /* defined(__MMI_MYPICTURE__) || defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__)
extern S8 g_pmsg_TextInMessage[];


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_entry_done_option
 * DESCRIPTION
 *  Display send options for picture message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_entry_done_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SEND_OPTION, mmi_msg_exit_generic, mmi_mypic_entry_done_option, NULL);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset : JAI 27-11-2004 */
    numItems = GetNumOfChild(MENU_ID_MYPIC_DONE);
    GetSequenceStringIds(MENU_ID_MYPIC_DONE, nStrItemList);
    SetParentHandler(MENU_ID_MYPIC_DONE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_OPTION);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_OPTION);

    ShowCategory52Screen(
        STR_SEND_OPTIONS_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mypic_send_handler
 * DESCRIPTION
 *  Highlight handler for My Picture - Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mypic_send_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_mypic_send_picmsg_to_only_entry,
        GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_send_picmsg_to_only_entry
 * DESCRIPTION
 *  Send picture message to single destination
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_send_picmsg_to_only_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;

    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);

    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        mmi_ucs2cpy(g_msg_cntx.smsPhoneNumber, (S8*) PendingSaveSendData.number);
    }
    mmi_mypic_send_picmsg_to_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_send_picmsg_to_entry
 * DESCRIPTION
 *  Send picutre message to entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_send_picmsg_to_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_MYPIC_DISPLAY))  /* JAI 06-12-2004 for My Pic */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MYPIC_DISPLAY);
    }
    else if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_WRITE))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_WRITE);
    }
    else if (IsScreenPresent(SCR_ID_MSG_NUMBER))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_NUMBER);
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SENDING);
    }

}

/* PMT JAI 24-11-2004 */


/*****************************************************************************
 * FUNCTION
 *  highlight_mypic_addtext_handler
 * DESCRIPTION
 *  Highlight handler for My Picture - Add Text option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mypic_addtext_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mypic_entry_addtext, KEY_EVENT_UP);
    SetKeyHandler(mmi_mypic_entry_addtext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_entry_addtext
 * DESCRIPTION
 *  Entry function for Add Text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_entry_addtext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 StrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NSM_EDITOR, NULL, mmi_mypic_entry_addtext, NULL);
    SetMessagesCurrScrnID(SCR_ID_NSM_EDITOR);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM_EDITOR);

    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        StrID = STR_ID_PICMSG_EDIT_TEXT;
    }
    else
    {
        StrID = STR_ID_MYPIC_ADDTEXT;
    }

    ShowCategory5Screen(
        StrID,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) gaddtext_buffer,
        129,
        guiBuffer);

    /* SetLeftSoftkeyFunction( mmi_mypic_entry_done,        KEY_EVENT_UP); //PMT JAI : 23122004 */
    SetLeftSoftkeyFunction(mmi_mypic_insert_text_options, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_mypic_entry_done_option, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_insert_text_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_insert_text_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 NumOfItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemsList[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EDIT_OPTIONS, mmi_msg_exit_generic, mmi_mypic_insert_text_options, NULL);

    SetParentHandler(MENU_ID_MYPIC_INSERT_TEXT_OPTION);
    SetMessagesCurrScrnID(SCR_ID_EDIT_OPTIONS);
    NumOfItems = GetNumOfChild(MENU_ID_MYPIC_INSERT_TEXT_OPTION);
    GetSequenceStringIds(MENU_ID_MYPIC_INSERT_TEXT_OPTION, nStrItemsList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EDIT_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NumOfItems,
        nStrItemsList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_mypic_insert_text_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mypic_insert_text_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mypic_entry_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mypic_entry_done
 * DESCRIPTION
 *  Takes user back to MyPicture List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mypic_entry_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Jai 1-12-2004 */
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        mmi_ucs2_to_asc((S8*) g_pmsg_TextInMessage, (S8*) gaddtext_buffer);
    }

    GoBacknHistory(2);
}
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__) */ 

#endif /* __MOD_SMSAL__ */ 

