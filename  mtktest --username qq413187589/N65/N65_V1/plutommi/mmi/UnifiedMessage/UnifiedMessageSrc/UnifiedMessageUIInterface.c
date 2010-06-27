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
 * UnifiedMessageUIInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements UI interface of Unified Message application.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_UNIFIED_MESSAGE_UIINTERFACE_C
#define _MMI_UNIFIED_MESSAGE_UIINTERFACE_C

#ifdef __MMI_UNIFIED_MESSAGE__
#include "FileMgr.h"
#include "FileManagerGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"



#include "wgui_ems.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"

#include "PhoneBookGprot.h"
#include "PhoneBookDef.h"

#include "Conversions.h"

#include "MemPoolContainerProt.h"
#include "wgui_asyncdynamic_menuitems.h"

#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"

#include "CallManagementGprot.h"
#include "CommonScreens.h"
#include "fmt_struct.h"
#include "DateTimeGprot.h"
#include "MessagesMiscell.h"
#include "SmsGuiInterfaceProt.h"
#include "wapadp.h"

#include "IdleAppDef.h"
#include "IdleAppProt.h"


#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedMessageProt.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

static S8 *mmi_um_string = NULL;

/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_main_menu
 * DESCRIPTION
 *  Highlight handler of unified message menu in Mesaage screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_um_pre_entry_main, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

 


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_main
 * DESCRIPTION
 *  Pre-entry function of unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

    mmi_um_set_state(UM_STATE_ENTRY_MAIN_MENU);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (!mmi_um_check_ready())
    {
        if ( g_um_p->main.ready_type & UM_MSG_TYPE_MMS)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*mmi_um_pre_entry_main, MMS is OK");  
        
            mmi_um_set_processing_screen(STR_UM_MAIN_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            mmi_um_entry_processing_generic();
        }
        else  /*MMS terminate*/
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*mmi_um_pre_entry_main, MMS is NOT ready");  
#ifdef __USB_IN_NORMAL_MODE__
            if (mmi_usb_is_in_mass_storage_mode())
            {
                    mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                    return;
            }
#endif /* __USB_IN_NORMAL_MODE__ */
            mmi_um_set_processing_screen(STR_UM_MAIN_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            mmi_um_entry_processing_generic();               
        }
        return;
    }

    if (!CheckIsBackHistory())
    {
        if (!g_um_p->main.is_refresh)
        {
            g_um_p->main.main_index = 0;
        }
    }

    mmi_um_get_msg_num_req();

    /* Receive ready ind in processing screen */
    /* DeleteScreenIfPresent(SCR_ID_UM_PROCESSING); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_main
 * DESCRIPTION
 *  Entry function of unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageUIInterface.c] mmi_um_entry_main history replace *\n");
        
        HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_MAIN, mmi_um_pre_entry_main);
        return;
    }

    if (mmi_um_check_interrupt() == MMI_TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageUIInterface.c] mmi_um_entry_main discard response *\n");        
        return;
    }

    EntryNewScreen(SCR_ID_UM_MAIN, mmi_um_exit_generic, mmi_um_pre_entry_main, NULL);

    mmi_um_set_state(UM_STATE_ENTRY_MAIN_MENU);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UM_MAIN);
    SetParentHandler(MENU_ID_UM_MAIN);
    RegisterHighlightHandler(mmi_um_main_highlight_handler);

    numItems = GetNumOfChild_Ext(MENU_ID_UM_MAIN);
    GetSequenceStringIds_Ext(MENU_ID_UM_MAIN, nStrItemList);
    GetSequenceImageIds_Ext(MENU_ID_UM_MAIN, itemIcons);

    /* reset current msg index and msg box */
    g_um_p->folder.current_msg_index = 0;
    g_um_p->folder.current_msg_box = 0;

    mmi_um_set_main_menu_highlight_handler();
    ConstructHintsList(MENU_ID_UM_MAIN, popUpList);

    ShowCategory52Screen(
        STR_UM_MAIN_ID,
        IMG_UM_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) popUpList,
        0,
        g_um_p->main.main_index,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);

    /* refresh case */
    DeleteScreenIfPresent(SCR_ID_UM_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_main_highlight_handler
 * DESCRIPTION
 *  Set main menu highlight handler for um app.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_main_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.main_index = index;
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_main_menu_highlight_handler
 * DESCRIPTION
 *  Set main menu highlight handler for um app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_main_menu_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the menu hilite handlers */
    SetHiliteHandler(MENU_ID_UM_WRITE_MSG, mmi_um_highlight_write_msg);
    SetHiliteHandler(MENU_ID_UM_INBOX, mmi_um_highlight_inbox);
    SetHiliteHandler(MENU_ID_UM_UNSENT, mmi_um_highlight_unsent);
    SetHiliteHandler(MENU_ID_UM_SENT, mmi_um_highlight_sent);
    SetHiliteHandler(MENU_ID_UM_DRAFT, mmi_um_highlight_draft);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(MENU_ID_UM_ARCHIVE, mmi_um_highlight_archive);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SetHiliteHandler(MENU_ID_UM_SIM, mmi_um_highlight_simbox);
    SetHintHandler(MENU_ID_UM_SIM, mmi_um_hint_simbox);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    SetHiliteHandler(MENU_ID_UM_DELETE_FOLDER, mmi_um_highlight_delete_folder);
    SetHiliteHandler(MENU_ID_UM_TEMPLATE, mmi_um_highlight_template);
    SetHiliteHandler(MENU_ID_UM_SETTING, mmi_um_highlight_setting);
    /* set the menu hint handlers */
    SetHintHandler(MENU_ID_UM_INBOX, mmi_um_hint_inbox);
    SetHintHandler(MENU_ID_UM_UNSENT, mmi_um_hint_unsent);
    SetHintHandler(MENU_ID_UM_SENT, mmi_um_hint_sent);
    SetHintHandler(MENU_ID_UM_DRAFT, mmi_um_hint_draft);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHintHandler(MENU_ID_UM_ARCHIVE, mmi_um_hint_archive);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_write_msg
 * DESCRIPTION
 *  Funtion is called when write message menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__

    SetLeftSoftkeyFunction(mmi_uc_pre_entry_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_pre_entry_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
#else /* __MMI_UNIFIED_COMPOSER__ */

    SetLeftSoftkeyFunction(mmi_um_entry_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_entry_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
#endif /* __MMI_UNIFIED_COMPOSER__ */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_inbox
 * DESCRIPTION
 *  Funtion is called when inbox menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_inbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_inbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_unsent
 * DESCRIPTION
 *  Funtion is called when unsent menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_unsent, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_unsent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_sent
 * DESCRIPTION
 *  Funtion is called when sent menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_sent, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_sent, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_draft
 * DESCRIPTION
 *  Funtion is called when draft menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_draft, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_draft, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_archive
 * DESCRIPTION
 *  Funtion is called when archive menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_archive, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_archive, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_delete_folder
 * DESCRIPTION
 *  Funtion is called when delete folder menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_delete_folder, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_delete_folder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template
 * DESCRIPTION
 *  Funtion is called when template menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_entry_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_entry_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_setting
 * DESCRIPTION
 *  Funtion is called when setting menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_entry_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_inbox
 * DESCRIPTION
 *  To construct hint popup for inbox
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_inbox(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.inbox_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_unsent
 * DESCRIPTION
 *  To construct hint popup for unsent
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_unsent(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.unsent_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_sent
 * DESCRIPTION
 *  To construct hint popup for sent
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_sent(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.sent_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_draft
 * DESCRIPTION
 *  To construct hint popup for draft
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_draft(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.draft_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_archive
 * DESCRIPTION
 *  To construct hint popup for archive
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_archive(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.archive_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_write_msg
 * DESCRIPTION
 *  Entry function of write message for unified message.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* If not back from history, reset the flag. */
    if (!CheckIsBackHistory())
    {
        mmi_um_skip_write_menu(KAL_FALSE);
    }

    if (g_um_p->main.is_skip_write_menu)
    {
        mmi_um_skip_write_menu(KAL_FALSE);
        DeleteScreenIfPresent(SCR_ID_UM_WRITE_MSG);
        GoBackHistory();
        return;
    }

    EntryNewScreen(SCR_ID_UM_WRITE_MSG, mmi_um_exit_generic, mmi_um_entry_write_msg, NULL);

    mmi_um_set_state(UM_STATE_ENTRY_WRTIE_MSG);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UM_WRITE_MSG);
    SetParentHandler(MENU_ID_UM_WRITE_MSG);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    numItems = GetNumOfChild_Ext(MENU_ID_UM_WRITE_MSG);
    GetSequenceStringIds_Ext(MENU_ID_UM_WRITE_MSG, nStrItemList);
    GetSequenceImageIds_Ext(MENU_ID_UM_WRITE_MSG, itemIcons);

    SetHiliteHandler(MENU_ID_UM_WRITE_MSG_SMS, mmi_um_highlight_write_msg_sms);
    SetHiliteHandler(MENU_ID_UM_WRITE_MSG_MMS, mmi_um_highlight_write_msg_mms);
    ConstructHintsList(MENU_ID_UM_WRITE_MSG, popUpList);

    ShowCategory52Screen(
        STR_UM_WRITE_MSG_ID,
        IMG_UM_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_write_msg_sms
 * DESCRIPTION
 *  Funtion is called when write sms msg menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_write_msg_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_msg_um_entry_write, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_um_entry_write, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_write_msg_mms
 * DESCRIPTION
 *  Funtion is called when write mms msg menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_write_msg_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(wap_um_entry_write_mms, KEY_EVENT_UP);
    SetKeyHandler(wap_um_entry_write_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

 


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_delete_folder
 * DESCRIPTION
 *  Pre-entry function of delete folder for unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_set_state(UM_STATE_ENTRY_DELETE_FOLDER);

    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (!mmi_um_check_ready())
    {
        mmi_um_set_processing_screen(STR_UM_DELETE_FOLDER_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
        mmi_um_entry_processing_generic();
        return;
    }

    if (!CheckIsBackHistory())
    {
        if (!g_um_p->main.is_refresh)
        {
            g_um_p->delete_folder.folder_type = 0;
        }
    }

    mmi_um_get_msg_num_req();

    /* Receive ready ind in processing screen */
    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_delete_folder
 * DESCRIPTION
 *  Entry function of delete folder for unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UM_DELETE_FOLDER, mmi_um_exit_generic, mmi_um_pre_entry_delete_folder, NULL);

    mmi_um_set_state(UM_STATE_ENTRY_DELETE_FOLDER);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UM_DELETE_FOLDER);
    SetParentHandler(MENU_ID_UM_DELETE_FOLDER);
    RegisterHighlightHandler(mmi_um_delete_folder_highlight_handler);

    numItems = GetNumOfChild_Ext(MENU_ID_UM_DELETE_FOLDER);
    GetSequenceStringIds_Ext(MENU_ID_UM_DELETE_FOLDER, nStrItemList);
    GetSequenceImageIds_Ext(MENU_ID_UM_DELETE_FOLDER, itemIcons);

    mmi_um_set_delete_folder_highlight_handler();
    ConstructHintsList(MENU_ID_UM_DELETE_FOLDER, popUpList);

    ShowCategory52Screen(
        STR_UM_DELETE_FOLDER_ID,
        IMG_UM_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) popUpList,
        0,
        g_um_p->delete_folder.folder_type,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_um_pre_delete_folder, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_delete_folder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* refresh case */
    DeleteScreenIfPresent(SCR_ID_UM_DELETE_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_delete_folder_highlight_handler
 * DESCRIPTION
 *  delete folder menu highlight handler for um app.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_delete_folder_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->delete_folder.folder_type = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_delete_folder_highlight_handler
 * DESCRIPTION
 *  Set delete folder menu highlight handler for um app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_delete_folder_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the menu hint handlers */
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_INBOX, mmi_um_hint_inbox);
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_UNSENT, mmi_um_hint_unsent);
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_SENT, mmi_um_hint_sent);
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_DRAFT, mmi_um_hint_draft);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_ARCHIVE, mmi_um_hint_archive);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SetHintHandler(MENU_ID_UM_DELETE_FOLDER_SIM, mmi_um_hint_simbox);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    return;
}

 


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_delete_folder
 * DESCRIPTION
 *  Pre-delete function of delete folder for unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType folder_type = 0;
    U16 msg_number = 0;
    U16 popup_string = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_um_p->delete_folder.folder_type)
    {
        case UM_MSG_DELETE_FOLDER_INBOX:
        {
            folder_type = UM_MSG_BOX_TYPE_INBOX;
            msg_number = g_um_p->msg_number.inbox_msg_number;
            popup_string = STR_UM_DELETE_FOLDER_INBOX_ID;
            break;
        }

        case UM_MSG_DELETE_FOLDER_UNSENT:
        {
            folder_type = UM_MSG_BOX_TYPE_UNSENT;
            msg_number = g_um_p->msg_number.unsent_msg_number;
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) || defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
            popup_string = STR_UM_DELETE_FOLDER_UNSENT_WITHOUT_SENDING_ID;
#else      
            popup_string = STR_UM_DELETE_FOLDER_UNSENT_ID;
#endif
            break;
        }

        case UM_MSG_DELETE_FOLDER_SENT:
        {
            folder_type = UM_MSG_BOX_TYPE_SENT;
            msg_number = g_um_p->msg_number.sent_msg_number;
            popup_string = STR_UM_DELETE_FOLDER_SENT_ID;
            break;
        }

        case UM_MSG_DELETE_FOLDER_DRAFT:
        {
            folder_type = UM_MSG_BOX_TYPE_DRAFT;
            msg_number = g_um_p->msg_number.draft_msg_number;
            popup_string = STR_UM_DELETE_FOLDER_DRAFT_ID;
            break;
        }
        
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_DELETE_FOLDER_ARCHIVE:
        {
            folder_type = UM_MSG_BOX_TYPE_ARCHIVE;
            msg_number = g_um_p->msg_number.archive_msg_number;
            popup_string = STR_UM_DELETE_FOLDER_ARCHIVE_ID;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_DELETE_FOLDER_SIM:
        {
            folder_type = UM_MSG_BOX_TYPE_SIM;
            msg_number = g_um_p->msg_number.sim_msg_number;
            popup_string = STR_UM_DELETE_FOLDER_SIM_ID;
            break;            
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        case UM_MSG_DELETE_FOLDER_TOTAL_NUM:
        {
            folder_type = UM_MSG_BOX_TYPE_INBOX | UM_MSG_BOX_TYPE_UNSENT | UM_MSG_BOX_TYPE_SENT | UM_MSG_BOX_TYPE_DRAFT;
            msg_number = g_um_p->msg_number.inbox_msg_number + g_um_p->msg_number.unsent_msg_number +
                g_um_p->msg_number.sent_msg_number + g_um_p->msg_number.draft_msg_number;
            
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
            folder_type |= UM_MSG_BOX_TYPE_ARCHIVE;
            msg_number += g_um_p->msg_number.archive_msg_number;
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
            
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            folder_type |= UM_MSG_BOX_TYPE_SIM;
            msg_number += g_um_p->msg_number.sim_msg_number;
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 

#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) || defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
            popup_string = STR_UM_DELETE_FOLDER_ALL_WITHOUT_SENDING_ID;
#else
            popup_string = STR_UM_DELETE_FOLDER_ALL_ID;
#endif
            break;
        }
        
        default:
            MMI_ASSERT(0);
    }

    if (msg_number == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, (U8) EMPTY_LIST_TONE);
        return;
    }

    else
    {
        g_um_p->delete_folder.folders_to_delete = (U16)folder_type;

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(popup_string),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_um_process_delete_folder, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_process_delete_folder
 * DESCRIPTION
 *  Process screen function of delete folder for unified message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_process_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_set_processing_screen(STR_UM_DELETE_FOLDER_ID, STR_UM_DELETING_ID, IMG_GLOBAL_PROGRESS, 0);
    mmi_um_entry_processing_generic();
    mmi_um_delete_folder_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_template
 * DESCRIPTION
 *  Entry function of msg template for unified message.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_um_check_ready())
    {
        mmi_um_set_processing_screen(STR_UM_TEMPLATE_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
        mmi_um_entry_processing_generic();
        return;
    }


    EntryNewScreen(SCR_ID_UM_TEMPLATE, mmi_um_exit_generic, mmi_um_entry_template, NULL);

    mmi_um_set_state(UM_STATE_ENTRY_TEMPLATE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UM_TEMPLATE);
    SetParentHandler(MENU_ID_UM_TEMPLATE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    numItems = GetNumOfChild_Ext(MENU_ID_UM_TEMPLATE);
    GetSequenceStringIds_Ext(MENU_ID_UM_TEMPLATE, nStrItemList);
    GetSequenceImageIds_Ext(MENU_ID_UM_TEMPLATE, itemIcons);

    SetHiliteHandler(MENU_ID_UM_TEMPLATE_SMS, mmi_um_highlight_template_sms);
    SetHiliteHandler(MENU_ID_UM_TEMPLATE_MMS, mmi_um_highlight_template_mms);
    ConstructHintsList(MENU_ID_UM_TEMPLATE, popUpList);

    ShowCategory52Screen(
        STR_UM_TEMPLATE_ID,
        IMG_UM_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template_sms
 * DESCRIPTION
 *  Funtion is called when sms template menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_msg_um_entry_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_um_entry_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_template_mms
 * DESCRIPTION
 *  Funtion is called when mms template menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_template_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(wap_um_entry_template_mms, KEY_EVENT_UP);
    SetKeyHandler(wap_um_entry_template_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_setting
 * DESCRIPTION
 *  Entry function of msg setting for unified message.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_um_check_ready())
    {
        mmi_um_set_processing_screen(STR_UM_SETTING_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
        mmi_um_entry_processing_generic();
        return;
    }

    EntryNewScreen(SCR_ID_UM_SETTING, mmi_um_exit_generic, mmi_um_entry_setting, NULL);

    mmi_um_set_state(UM_STATE_ENTRY_SETTING);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UM_SETTING);
    SetParentHandler(MENU_ID_UM_SETTING);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    numItems = GetNumOfChild_Ext(MENU_ID_UM_SETTING);
    GetSequenceStringIds_Ext(MENU_ID_UM_SETTING, nStrItemList);
    GetSequenceImageIds_Ext(MENU_ID_UM_SETTING, itemIcons);

    SetHiliteHandler(MESSAGES_MENU_MSG_SETTINGS_MENUID, mmi_um_highlight_setting_sms);
    SetHiliteHandler(MENU_ID_UM_SETTING_MMS, mmi_um_highlight_setting_mms);
    ConstructHintsList(MENU_ID_UM_SETTING, popUpList);

    ShowCategory52Screen(
        STR_UM_SETTING_ID,
        IMG_UM_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_setting_sms
 * DESCRIPTION
 *  Funtion is called when sms setting menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_setting_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_msg_um_entry_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_um_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_setting_mms
 * DESCRIPTION
 *  Funtion is called when mms setting menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_setting_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(wap_um_entry_setting_mms, KEY_EVENT_UP);
    SetKeyHandler(wap_um_entry_setting_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_exit_generic
 * DESCRIPTION
 *  Exit generic function for um app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_exit_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_exit_folder
 * DESCRIPTION
 *  Exit generic function for um app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_exit_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.is_reset_folder_info = KAL_TRUE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_screen_for_ready_ind
 * DESCRIPTION
 *  Handle screen for ready indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_screen_for_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_um_check_ready())
    {
        if (g_um_p->main.state == UM_STATE_ENTRY_MAIN_MENU)
        {
            if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
            {
                mmi_um_pre_entry_main();
            }
            else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
            {
                HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_MAIN, mmi_um_pre_entry_main);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_processing_screen
 * DESCRIPTION
 *  Set string and image for UM MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->processing.caption_str_id = captionStrId;
    g_um_p->processing.body_str_id = bodyStrId;
    g_um_p->processing.animation_image_id = animationImageId;
    g_um_p->processing.RSK_str_id = rskStrId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_exit_processing_generic
 * DESCRIPTION
 *  Exit MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UM_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_time_out_processing_generic
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_time_out_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UM_INPROGRESS_TIMER_ID);
    if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_goBackHistory_with_check
 * DESCRIPTION
 *  check if need to delete um main screen before go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_um_goBackHistory_with_check(void)
{
    if (!mmi_um_check_ready()) 
    {
        DeleteScreenIfPresent(SCR_ID_UM_MAIN);
    }
        
    GoBackHistory();
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UM_PROCESSING, mmi_um_exit_processing_generic, mmi_um_entry_processing_generic, NULL);


    ShowCategory8Screen(
        g_um_p->processing.caption_str_id,
        IMG_UM_ENTRY_SCRN_CAPTION,
        0,
        0,
        g_um_p->processing.RSK_str_id,
        0,
        g_um_p->processing.body_str_id,
        g_um_p->processing.animation_image_id,
        NULL);

    if (g_um_p->processing.RSK_str_id == 0)
    {
        ClearAllKeyHandler();
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
        if (isInCall())
        {
            SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
        }

        StartTimer(UM_INPROGRESS_TIMER_ID, MMI_UM_INPROGRESS_TIME_OUT, mmi_um_time_out_processing_generic);
    }
    else
    {
        SetKeyHandler(mmi_um_goBackHistory_with_check, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_um_goBackHistory_with_check, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  pre-entry inbox list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_INBOX;

    mmi_um_set_state(UM_STATE_ENTRY_INBOX);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.inbox_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_INBOX_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_INBOX_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_unsent
 * DESCRIPTION
 *  pre-entry unsent list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */    

    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_UNSENT;

    mmi_um_set_state(UM_STATE_ENTRY_UNSENT);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.unsent_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_UNSENT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_UNSENT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_sent
 * DESCRIPTION
 *  pre-entry sent list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */  

    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_SENT;

    mmi_um_set_state(UM_STATE_ENTRY_SENT);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.sent_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_SENT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_SENT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_draft
 * DESCRIPTION
 *  pre-entry draft list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */  

    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_DRAFT;

    mmi_um_set_state(UM_STATE_ENTRY_DRAFT);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.draft_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_DRAFT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_DRAFT_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_archive
 * DESCRIPTION
 *  pre-entry archive list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_archive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_ARCHIVE;

    mmi_um_set_state(UM_STATE_ENTRY_ARCHIVE);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.archive_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
#ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */
            if (mmi_usb_check_path_exported((PS8) MMI_SMS_ARCH_FOLDER_DRV))
            {
                /* MMI public drive is exported, cannot use this app */
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                return;
            }
        }
#endif /* __USB_IN_NORMAL_MODE__ */
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_ARCHIVE_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_ARCHIVE_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_um_hilite_folder_item
 * DESCRIPTION
 *  Highlight handler of Sent list
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hilite_folder_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_msg_detail_struct *listMsgsStruct[MMI_UM_MAX_MSG_DETAIL_NUM];
    mmi_um_msg_detail_struct *temp;
    MYTIME time;
    UI_character_type str[MMI_UM_MAX_LEN_TIME_STR];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mem_get_values(
        &g_um_p->mem_pool_info.mem_container,
        (S16) index,
        (S16) index,
        (void **)listMsgsStruct,
        &g_um_p->mem_pool_info.not_avail_pool);

    temp = listMsgsStruct[0];
    g_um_p->folder.current_msg_index = index;

    if (temp->msg_detail.timestamp != 0)
    {
        U32 local_sec = 0;
        local_sec = applib_dt_sec_utc_to_local(temp->msg_detail.timestamp);
        mmi_dt_utc_sec_2_mytime(local_sec, &time, MMI_TRUE);
        date_string(&time, str, DT_IDLE_SCREEN);
        mmi_ucs2ncpy((S8*) g_um_p->folder.msg_time, (S8*) str, (MMI_UM_MAX_LEN_TIME_STR - 1));
        mmi_ucs2ncat((S8*) g_um_p->folder.msg_time, (S8*) " ", 1);

        time_string(&time, str, DT_IDLE_SCREEN);
        mmi_ucs2ncat((S8*) g_um_p->folder.msg_time, (S8*) str, (MMI_UM_MAX_LEN_TIME_STR - 1));
    }
    else
    {
        memset((S8*) g_um_p->folder.msg_time, 0, MMI_UM_MAX_LEN_TIME_STR * ENCODING_LENGTH);
    }

    RedrawCategory263InfoBox((U8*) temp->msg_detail.address, (U8*) g_um_p->folder.msg_time);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_folder
 * DESCRIPTION
 *  generic pre-entry folder function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    U16 screen_id = 0;
    S32 numItems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageUIInterface.c] mmi_um_entry_folder redraw due to Small Screen *\n");
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    switch (g_um_p->folder.current_msg_box)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            string_id = STR_UM_INBOX_ID;
            screen_id = SCR_ID_UM_INBOX;
            break;
        case UM_MSG_BOX_TYPE_UNSENT:
            string_id = STR_UM_UNSENT_ID;
            screen_id = SCR_ID_UM_UNSENT;
            break;
        case UM_MSG_BOX_TYPE_SENT:
            string_id = STR_UM_SENT_ID;
            screen_id = SCR_ID_UM_SENT;
            break;
        case UM_MSG_BOX_TYPE_DRAFT:
            string_id = STR_UM_DRAFT_ID;
            screen_id = SCR_ID_UM_DRAFT;
            break;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
            string_id = STR_UM_ARCHIVE_ID;
            screen_id = SCR_ID_UM_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */       
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_BOX_TYPE_SIM:
            string_id = STR_UM_SIM_ID;
            screen_id = SCR_ID_UM_SIM;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            MMI_ASSERT(0);
            break;
    }

    numItems = g_um_p->folder.msg_number_in_list;

    if (IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageUIInterface.c] mmi_um_entry_folder discard response *\n");
        g_um_p->main.is_reset_folder_info = KAL_TRUE;
        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
        return;
    }

    if (!mmi_um_check_ready())
    {
        mmi_um_set_processing_screen(string_id, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
        mmi_um_entry_processing_generic();
        return;
    }

    if (numItems)
    {
        U8 *guiBuffer;
        S32 list_not_ready;

        EntryNewScreen(screen_id, mmi_um_exit_folder, mmi_um_entry_folder, NULL);
        
        /* Back from history */
        if (g_um_p->main.is_reset_folder_info)
        {
            mmi_um_reset_folder_info();
            g_um_p->main.is_reset_folder_info = KAL_FALSE;
            mmi_um_reset_folder_history_guibuffer(screen_id);
        }
        else
        {
            /* Change the highlight by message applications request */
            if (g_um_p->folder.is_highlight_change_needed)
            {
                mmi_um_change_highlight();
                g_um_p->folder.is_highlight_change_needed = KAL_FALSE;
    
                mmi_um_reset_folder_info();
                g_um_p->main.is_reset_folder_info = KAL_FALSE;
                mmi_um_reset_folder_history_guibuffer(screen_id);
            }
                        
            /* to prevent the selected msg being deleted */
            if (g_um_p->folder.current_msg_index >= numItems)
            {
                g_um_p->folder.current_msg_index = numItems - 1;
            }
        }

        guiBuffer = GetCurrGuiBuffer(screen_id);
        
        RegisterHighlightHandler(mmi_um_hilite_folder_item);

        /* After entering inbox list, do not display full screen indication in idle screen */
        if (g_um_p->folder.current_msg_box == UM_MSG_BOX_TYPE_INBOX)
        {
            g_um_p->main.is_new_msg = KAL_FALSE;
        }
        /*the LSK should always be "option when support background sending--- based on discucssin result"*/
#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) || defined(__MMI_MMS_BGSR_SUPPORT__))

        if (UM_MSG_BOX_TYPE_UNSENT == g_um_p->folder.current_msg_box)
        {
            ShowCategory263Screen(
                (U8*) GetString(string_id),
                IMG_UM_ENTRY_SCRN_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                numItems,
                mmi_um_get_async_items,
                NULL,
                g_um_p->folder.current_msg_index,
                IMG_MESSAGE_READ /* list_icon */ ,
                guiBuffer,
                &list_not_ready);    
        }
        else                   
#endif 
        {
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__

        ShowCategory263Screen(
            (U8*) GetString(string_id),
            IMG_UM_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            mmi_um_get_async_items,
            NULL,
            g_um_p->folder.current_msg_index,
            IMG_MESSAGE_READ /* list_icon */ ,
            guiBuffer,
            &list_not_ready);

#else /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
        ShowCategory263Screen(
            (U8*) GetString(string_id),
            IMG_UM_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            mmi_um_get_async_items,
            NULL,
            g_um_p->folder.current_msg_index,
            IMG_MESSAGE_READ /* list_icon */ ,
            guiBuffer,
            &list_not_ready);

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
        }
        if (list_not_ready)
        {
            MMI_ASSERT(GetExitScrnID() == screen_id);
            mmi_um_entry_get_msg_info();
        }
        else
        {
            g_um_p->folder.is_list_displayed = KAL_TRUE;

            SetLeftSoftkeyFunction(mmi_um_entry_msg, KEY_EVENT_UP);
            SetKeyHandler(mmi_um_entry_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }

    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_msg
 * DESCRIPTION
 *  generic entry msg function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 msg_index = g_um_p->folder.msg_list[g_um_p->folder.current_msg_index].list_info.msg_index;
    UmMsgType type = g_um_p->folder.msg_list[g_um_p->folder.current_msg_index].msg_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case UM_MSG_TYPE_SMS:
            mmi_msg_um_entry_msg(g_um_p->folder.current_msg_box, msg_index);
            break;
        case UM_MSG_TYPE_MMS:
            wap_um_entry_msg_mms((kal_uint16) g_um_p->folder.current_msg_box, msg_index);
            break;
        case UM_MSG_TYPE_WAP_PUSH:
            wap_um_entry_msg_wap_push((kal_uint16) g_um_p->folder.current_msg_box, msg_index);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_async_items
 * DESCRIPTION
 *  Fill dynamic list items of each folder
 * PARAMETERS
 *  start_indx      [IN]            Start index of item to be retrieved.
 *  menuData        [IN/OUT]        UI structure to store the list data.
 *  num_item        [IN]            Number of items revrieved.
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_um_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_mem_pool_ret_enum ret_result;

    mmi_um_msg_detail_struct *listMsgsStruct[MMI_UM_MAX_MSG_DETAIL_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->mem_pool_info.start_index = start_indx;
    g_um_p->mem_pool_info.end_index = (start_indx + num_item) - 1;
    ret_result = mmi_mem_get_values(
                    &g_um_p->mem_pool_info.mem_container,
                    (S16) g_um_p->mem_pool_info.start_index,
                    (S16) g_um_p->mem_pool_info.end_index,
                    (void **)listMsgsStruct,
                    &g_um_p->mem_pool_info.not_avail_pool);

    if (ret_result != MEM_CT_SUCCESS)
    {
        if (g_um_p->folder.is_list_displayed)
        {
            mmi_um_entry_get_msg_info();
        }
        return 0;
    }

    /* fill data */
    for (i = 0; i < num_item; ++i)
    {
        U16 status_img;
        mmi_um_msg_detail_struct *temp = listMsgsStruct[i];

        /* subject */
        mmi_ucs2ncpy(
            (S8*) menuData[i].item_list[0],
            (S8*) temp->msg_detail.subject,
            temp->msg_detail.subject_length);

        /* status icon */
        status_img = temp->msg_detail.icon_id;
        menuData[i].image_list[0] = (PU8) GetImage(status_img);
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_get_msg_info
 * DESCRIPTION
 *  Entry progressing screen for get message info request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_get_msg_info()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_um_p->folder.current_msg_box)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            string_id = STR_UM_INBOX_ID;
            break;
        case UM_MSG_BOX_TYPE_UNSENT:
            string_id = STR_UM_UNSENT_ID;
            break;
        case UM_MSG_BOX_TYPE_SENT:
            string_id = STR_UM_SENT_ID;
            break;
        case UM_MSG_BOX_TYPE_DRAFT:
            string_id = STR_UM_DRAFT_ID;
            break;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
            string_id = STR_UM_ARCHIVE_ID;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_BOX_TYPE_SIM:
            string_id = STR_UM_SIM_ID;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            MMI_ASSERT(0);
            break;
    }

    if (GetExitScrnID() != SCR_ID_UM_PROCESSING)
    {
        mmi_um_set_processing_screen(string_id, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
        mmi_um_entry_processing_generic();
        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
        g_um_p->folder.is_list_displayed = KAL_FALSE;
    }

    mmi_um_get_list_info_req();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_enter_curr_folder
 * DESCRIPTION
 *  Enter current folder after list folder process complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_enter_curr_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folderScrnId = 0;
    FuncPtr entryFuncPtr = mmi_um_entry_folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrieve screen info */
    switch (g_um_p->folder.current_msg_box)
    {
        case UM_MSG_BOX_TYPE_INBOX:
            folderScrnId = SCR_ID_UM_INBOX;
            break;
        case UM_MSG_BOX_TYPE_UNSENT:
            folderScrnId = SCR_ID_UM_UNSENT;
            break;
        case UM_MSG_BOX_TYPE_SENT:
            folderScrnId = SCR_ID_UM_SENT;
            break;
        case UM_MSG_BOX_TYPE_DRAFT:
            folderScrnId = SCR_ID_UM_DRAFT;
            break;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
            folderScrnId = SCR_ID_UM_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_BOX_TYPE_SIM:
            folderScrnId = SCR_ID_UM_SIM;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
            MMI_ASSERT(0);
            break;
    }

    /* if it's in progressing screen */
    if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
    {
        if (IsScreenPresent(folderScrnId))
        {
            /* if folder is already exists */
            GoBackHistory();
        }
        else
        {   /* first time entry */
            (*entryFuncPtr) ();
            DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
        }
    }
    else
    {
        /* it's not in progressing screen, maybe in call or something else */
        DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_new_msg_ind
 * DESCRIPTION
 *  entry new msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_new_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_in_idle = (MMI_BOOL)g_idle_context.IsOnIdleScreen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedMessageMiscell.c] mmi_um_pre_entry_new_msg_ind in_idle: %d ready: %d comes_in_idle %d *\n",
                         is_in_idle, g_um_p->main.is_ready_for_new_msg, g_um_p->main.is_new_msg_comes_in_idle);

    /* This function is called again. The msg number should be ready. */
    if (g_um_p->main.is_ready_for_new_msg)
    {        
        mmi_um_entry_new_msg_ind(KAL_TRUE);
        return;
    }
    
    mmi_um_set_state(UM_STATE_ENTRY_NEW_MSG_IND);

    if (!mmi_um_check_ready())
    {
        mmi_um_entry_new_msg_ind(KAL_FALSE);
        return;
    }

    EntryNewScreen(SCR_ID_UM_NEW_MSG_DUMMY_IND, mmi_um_exit_generic, NULL, NULL);

    /* If current screen is idle screen, redraw idle screen to fix status bar refresh issue. */
    if (is_in_idle && g_um_p->main.is_new_msg_comes_in_idle)
    {
        RedrawIdleScreen();
    }

    g_um_p->main.is_new_msg_comes_in_idle = KAL_FALSE;

    mmi_um_get_msg_num_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_go_back_from_new_msg_ind
 * DESCRIPTION
 *  entry new msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_go_back_from_new_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.is_new_msg = KAL_FALSE;
    g_um_p->main.is_ready_for_new_msg = KAL_FALSE;

    if (mmi_um_string != NULL)
    {
        OslMfree(mmi_um_string);
        mmi_um_string = NULL;
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_entry_new_msg_ind
 * DESCRIPTION
 *  entry new msg
 * PARAMETERS
 *  ready       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_entry_new_msg_ind(kal_bool ready)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *new_msg_string_id = NULL;
    S8 *unread_msg_number = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UM_NEW_MSG_IND, mmi_um_exit_new_msg_ind, NULL, NULL);
    ForceSubLCDScreen(mmi_msg_start_msg_sub_anm);

    new_msg_string_id = GetString(STR_UM_NEW_MSG_ID);

    if (ready)
    {
        U8 *tempStr = NULL;
        U8 ascii_num[16];
        U16 num = g_um_p->msg_number.inbox_unread_msg_number;

        if (mmi_um_string != NULL)
        {
            OslMfree(mmi_um_string);
            mmi_um_string = NULL;
        }

        mmi_um_string = OslMalloc(64);

        memset(ascii_num, 0, 16);
        sprintf((S8*) ascii_num, "%d ", num);
        mmi_asc_to_ucs2((S8*) mmi_um_string, (S8*) ascii_num);

        tempStr = (U8*) GetString((U16) STR_UM_UNREAD_MSG_NUMBER_ID);

        mmi_ucs2cat((S8*) mmi_um_string, (S8*) tempStr);
        unread_msg_number = mmi_um_string;
    }

    if (IsKeyPadLockState() == 0)
    {
        ShowCategory154Screen(
            0,
            0,
            STR_GLOBAL_VIEW,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) new_msg_string_id,
            (PU8) unread_msg_number,
            IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
            NULL);

        SetRightSoftkeyFunction(mmi_um_go_back_from_new_msg_ind, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_um_pre_entry_inbox, KEY_EVENT_UP);
        SetKeyHandler(mmi_um_go_back_from_new_msg_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else    /* keypad is locked */
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) new_msg_string_id,
            (PU8) unread_msg_number,
            IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
            NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_exit_new_msg_ind
 * DESCRIPTION
 *  get sms msg number of each msg box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_exit_new_msg_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_stop_msg_sub_anm();
}

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_simMessage
 * DESCRIPTION
 *  Funtion is called when SIM Message menu item selected
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_um_pre_entry_simbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_um_pre_entry_simbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_pre_entry_inbox
 * DESCRIPTION
 *  pre-entry simbox list function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_pre_entry_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_UNIFIED_COMPOSER__
    if (mmi_uc_is_pending_action())
    {
        DisplayPopup(
            (PU8) GetString(STR_UM_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */    
    g_um_p->folder.current_msg_box = UM_MSG_BOX_TYPE_SIM;

    mmi_um_set_state(UM_STATE_ENTRY_SIM);

    if (GetExitScrnID() == SCR_ID_UM_MAIN)
    {
        if (g_um_p->msg_number.sim_msg_number == 0)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* if receive ready ind and this func is called, do not show progress screen again  */
    if (GetExitScrnID() != SCR_ID_UM_PROCESSING && !IsScreenPresent(SCR_ID_UM_PROCESSING))
    {
        if (!CheckIsBackHistory())
        {
            if (mmi_um_check_ready())
            {
                mmi_um_set_processing_screen(STR_UM_SIM_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, 0);
            }
            else
            {
                mmi_um_set_processing_screen(STR_UM_SIM_ID, STR_UM_LOADING_ID, IMG_GLOBAL_PROGRESS, STR_GLOBAL_BACK);
            }
            mmi_um_entry_processing_generic();
        }
    }

    if (!mmi_um_check_ready())
    {
        return;
    }

    if (g_um_p->main.is_reset_folder_info)
    {
        mmi_um_reset_folder_info();
        g_um_p->main.is_reset_folder_info = KAL_FALSE;
    }

    if (IsScreenPresent(SCR_ID_UM_MAIN) && (!g_um_p->main.is_refresh))
    {
        mmi_um_get_list_info_req();
    }
    else
    {
        mmi_um_get_msg_num_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_hint_simbox
 * DESCRIPTION
 *  To construct hint popup for sim
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_hint_simbox(U16 index)
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

    sprintf((S8*) value, "%d ", g_um_p->msg_number.sim_msg_number);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    mmi_ucs2ncat((PS8) hintData[index], (S8*) GetString(STR_UM_MSG_ID), MMI_UM_MAX_GET_STRING_LEN);
    return;
}


#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* _MMI_UNIFIED_MESSAGE_UIINTERFACE_C */ 

