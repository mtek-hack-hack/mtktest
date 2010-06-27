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
 * BTMMIBipScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BIP_SUPPORT__)

     /*  Include: MMI header file */
#include "CommonScreens.h"      /* DisplayPopup */
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* for tone ID */
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "Conversions.h"        /* char set conversion */
#include "wgui_status_icons.h"  /* for STATUS_ICON_IR */
#include "IdleAppDef.h" /* g_idle_context */
#include "IdleAppProt.h"        /* EntryIdleScreen() */
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "gpioInc.h"    /* TurnOnBacklight */
#include "med_api.h"
#include "FileManagerGProt.h"

#include "wgui_tab_bars.h"

     /* Leo add for DLT */
     /* Leo end */

     /* External Device Header Files */
#include "FileMgr.h"    /* max file path size. */
     /* Leo add for DLT */
#include "FileManagerDef.h"
     /* Leo end */
#include "CallManagementGprot.h"


#include "bluetooth_struct.h"
#include "btmmicm.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"

#include "BTMMIBipGprot.h"
#include "BTMMIBip.h"
#include "BTMMIBipScr.h"

#include "ExtDeviceDefs.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

/* Trace Header Files */


/* display thumbnail list in image browser */
//#define __MMI_BIP_LIST_THUMBNAIL__

#define MMI_BIP_CAT426_CACHE_SIZE 20*1024

#define BT_BIP_MAX_IMGHDLE_NUM  2048

 /***************************************************************************** 
 * CONTEXT
 *****************************************************************************/
mmi_bip_scr_cntx_struct g_mmi_bt_bip_scr_cntx;
mmi_bip_scr_cntx_struct *g_mmi_bt_bip_scr_cntx_p = &g_mmi_bt_bip_scr_cntx;

 /***************************************************************************** 
  * External Functions
  *****************************************************************************/

static void mmi_bt_bip_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte);

#define BIP_NOTY_STR_SIZE               (128)

U16 mmi_bip_notify_str[BIP_NOTY_STR_SIZE];

#define MMI_BIPI_BUILD_EXIT_NOTY_STR()                                               \
 {                                                                                   \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_CON_EXIT) );    \
 }
#define MMI_BIPI_BUILD_ABORTING_NOTY_STR()                                           \
 {                                                                                   \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_GLOBAL_ABORTING) ); \
 }

#define MMI_BIPI_BUILD_CONNECTING_NOTY_STR()                                               \
 {                                                                                         \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_CONNECTING) ); \
 }
#define MMI_BIPI_BUILD_DISCONNECTING_NOTY_STR()                                               \
 {                                                                                            \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_DISCONNECTING) ); \
 }
#define MMI_BIPI_BUILD_GETTING_IMGPROP_NOTY_STR()                                               \
{                                                                                               \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_GETTING_IMGPROP) ); \
}
#define MMI_BIPI_BUILD_GETTING_IMGTHM_NOTY_STR()                                               \
{                                                                                               \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_STATUS_GETTING_IMGTHM) ); \
}
#define MMI_BIPI_BUILD_REFRESH_IMGLIST_NOTY_STR()                                               \
{                                                                                               \
    kal_wstrcpy( (U16 *)mmi_bip_notify_str, (U16 *)GetString(STR_BIP_REFRESH_IMGLIST) );        \
}

#define BIP_SEND_UDPADE_STR() {                                                                                                                           \
        U16 fmgr_bip_send_per_str_buf[32];                                                                                                                \
        if( (mmi_ucs2strlen( (S8*)  GetString(STR_GLOBAL_SEND) )+1) > ((sizeof(mmi_bip_notify_str)/2) -(sizeof(fmgr_bip_send_per_str_buf)/2)) )               \
          ASSERT(MMI_FALSE);                                                                                                                              \
       kal_wsprintf( (U16*)fmgr_bip_send_per_str_buf, "(%d%c) ", mmi_bipi_push_prog_percentage(),'%' );                                                   \
       mmi_ucs2cpy((S8*)mmi_bip_notify_str, GetString(STR_GLOBAL_SEND) );                                                                                  \
       mmi_ucs2cat((S8*)mmi_bip_notify_str, (S8*)fmgr_bip_send_per_str_buf);                                                                               \
 }

#define BIP_BUILD_IMG_RECV_NOTY_STR() {                                                   \
    mmi_ucs2cpy((S8*)mmi_bip_notify_str, (S8*)GetString(STR_BIP_RECV_FILE_IND) );          \
    mmi_ucs2cat((S8*)mmi_bip_notify_str,  (S8*)L" '\\"); \
    mmi_ucs2cat((S8*)mmi_bip_notify_str, (S8*)BIP_RECV_FILEPATH); \
    mmi_ucs2cat((S8*)mmi_bip_notify_str,  (S8*) L"' "); \
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_start_blinking
 * DESCRIPTION
 *  This function is to indicate the user BIP data is transferring
 * PARAMETERS
 *  bip_role        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_start_blinking(MMI_BT_PROFILE_ROLE bip_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_START_BLINKING);
    mmi_bt_status_icon_start_blinking(MMI_BT_OBEX_IMAGING_UUID, bip_role);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_stop_blinking
 * DESCRIPTION
 *  This function is to indicate the user BIP data transferring  is stopped
 * PARAMETERS
 *  bip_role        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_stop_blinking(MMI_BT_PROFILE_ROLE bip_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_STOP_BLINKING);
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_IMAGING_UUID, bip_role);
}

#define BT_BIP_PUSH_INITIATOR_SCR_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_push_abort_by_user
 * DESCRIPTION
 *  This function process user abort pushing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_push_abort_by_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bip_context.bip_initiator_cntx.b_user_cancel = MMI_TRUE;
    
    mmi_bt_bipi_push_abort();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_entry_sending_scr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_entry_sending_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ENTRY_SENDING_SCR);
    /* Call Exit Handler */
    EntryNewScreen(SCR_BIP_SENDING, mmi_bipi_exit_sending_scr, mmi_bipi_entry_sending_scr, NULL);

    /* Show Sending screen */
    BIP_SEND_UDPADE_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_SENDING,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    mmi_bt_bip_store_endkey_hdlr();

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bt_bipi_push_abort_by_user, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_SENDING, (HistoryDelCBPtr) mmi_bipi_sending_screen_del_cb);

    SetKeyHandler(mmi_bt_bipi_sending_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BIP_PROG_UPD_DUR, mmi_bipi_push_update_prog_tohdlr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_exit_sending_scr
 * DESCRIPTION
 *  This function is the exit function for the send through file manager screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_exit_sending_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_EXIT_SENDING_SCR);
    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_entry_abort_scr
 * DESCRIPTION
 *  This function is the handler for showing the aborting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_entry_abort_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ENTRY_ABORT_SCR);
    EntryNewScreen(SCR_BIP_ABORTING, NULL, mmi_bipi_entry_abort_scr, NULL);

    MMI_BIPI_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_GLOBAL_ABORTING, 0, 0, 0, 0, 0, (U8*) mmi_bip_notify_str, IMG_GLOBAL_PROGRESS, NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, (HistoryDelCBPtr) mmi_bipi_aborting_screen_del_cb);

    SetKeyHandler(mmi_bt_bipi_abort_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_sending_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?] 
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bipi_sending_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SENDING_SCR_DEL_CB);
    
    if (MMI_TRUE == mmi_bt_bipi_push_is_sending())
        mmi_bt_bipi_push_abort();

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_aborting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting aborting screen
 * PARAMETERS
 *  p       [?]    
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bipi_aborting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ABORTING_SCR_DEL_CB);

    if (MMI_TRUE == mmi_bt_bipi_push_is_aborting())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_push_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bipi_push_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BIP_SEND_UDPADE_STR();

    cat66_update_progress_string();

    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BIP_PROG_UPD_DUR, mmi_bipi_push_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_sending_scr_EndKey_press_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_sending_scr_EndKey_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SENDING_SCR_ENDKEY_HANDLER);
    g_mmi_bt_bip_scr_cntx.endkey_pressed = MMI_TRUE;

    mmi_bt_bipi_push_abort();
}

#define MMI_BT_BIPR_SETTING_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_menu_hdlr_init
 * DESCRIPTION
 *  This function is to initialize the mmi menu hilite hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_menu_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CONN_BIP_SETTING, mmi_bt_bipr_setting_highlight_hdlr);
    SetHiliteHandler(MENU_CONN_BIP_SHARED_FOLDER, mmi_bt_bipr_shared_folder_highlight_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_setting_highlight_hdlr
 * DESCRIPTION
 *  This function is to entry bipr settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_bt_bipr_entry_bip_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bipr_entry_bip_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_entry_bip_setting
 * DESCRIPTION
 *  This function is to display the bipr server setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_entry_bip_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *HintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_BIP_SETTING, NULL, mmi_bt_bipr_entry_bip_setting, NULL);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    guiBuffer = GetCurrGuiBuffer(SCR_BIP_SETTING);
    nNumofItem = GetNumOfChild(MENU_CONN_BIP_SETTING);
    GetSequenceStringIds(MENU_CONN_BIP_SETTING, nStrItemList);
    SetParentHandler(MENU_CONN_BIP_SETTING);
    SetHintHandler(MENU_CONN_BIP_SHARED_FOLDER, mmi_bt_bipr_shared_folder_hint);

    ConstructHintsList(MENU_CONN_BIP_SETTING, HintList);

    ShowCategory52Screen(
        STR_BIP_SETTING,
        GetRootTitleIcon(MENU_CONN_BIP_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) HintList,
        0,
        0,
        guiBuffer);

    /* LSK/right arrow key is defined in highlight index */
    /* register RSK hanlders */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* register left arrow key handler */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define BIPR_SHARED_FOLDER


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_shared_folder_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_shared_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_bt_bipr_entry_shared_folder_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bipr_entry_shared_folder_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_shared_folder_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_shared_folder_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) g_bip_context.bip_responder_cntx.shared_folder) <= 41)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) g_bip_context.bip_responder_cntx.shared_folder);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) g_bip_context.bip_responder_cntx.shared_folder, 3);
        mmi_ucs2ncpy(
            (PS8) (hintData[index] + 6),
            (PS8) g_bip_context.bip_responder_cntx.shared_folder + (mmi_ucs2strlen((const S8*)g_bip_context.bip_responder_cntx.shared_folder) * 2) - (MAX_SUB_MENU_HINT_SIZE - 6 - ENCODING_LENGTH),
            (MAX_SUBMENU_CHARACTERS - 3 - 1));
        hintData[index][6] = 0x7E;
        hintData[index][7] = 0;
        hintData[index][MAX_SUB_MENU_HINT_SIZE - 2] = 0;
        hintData[index][MAX_SUB_MENU_HINT_SIZE - 1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_entry_shared_folder_menu
 * DESCRIPTION
 *  This function is to enter selecting shared folder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_entry_shared_folder_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bip_context.bip_responder_cntx.state >= MMI_BIPR_STATE_ACCEPTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_BIP_CONNECTING_CLIENT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);

        return;
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_BIP,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) L"root",
        mmi_bt_bipr_fmgr_select_path_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_fmgr_select_path_done
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_fmgr_select_path_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_path_buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        DeleteUptoScrID(SCR_BIP_SETTING);
        GoBackHistory();
        return;
    }

    if (g_bip_context.bip_responder_cntx.state >= MMI_BIPR_STATE_ACCEPTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_BIP_CONNECTING_CLIENT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);

        return;
    }

    if (path == NULL)
    {
        DeleteUptoScrID(SCR_BIP_SETTING);
        GoBackHistory();
        return;
    }
    mmi_ucs2cpy((S8*) tmp_path_buf, (S8*) path);

    /* set  folder and all connection's current folder */
    mmi_bt_bipr_set_shared_fodler(tmp_path_buf);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);

    DeleteUptoScrID(SCR_BIP_SETTING);
}

#define MMI_BT_BIP_PULL_INITIATOR_SCR_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_connect_scr
 * DESCRIPTION
 *  This function is to entry the connecting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_connect_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_CONNECT_SCR);
    EntryNewScreen(SCR_BIP_CONNECTING, NULL, mmi_bt_bipi_pull_entry_connect_scr, NULL);

    MMI_BIPI_BUILD_CONNECTING_NOTY_STR();

    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BIP_STATUS_CONNECTING,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    mmi_bt_bip_store_endkey_hdlr();

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_connect_cancel, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, mmi_bt_bipi_pull_connecting_screen_del_cb);

    SetKeyHandler(mmi_bt_bipi_connecting_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_connecting_scr_EndKey_press_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_connecting_scr_EndKey_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CONNECT_SCR_ENDKEY);
    g_mmi_bt_bip_scr_cntx.endkey_pressed = MMI_TRUE;

    mmi_bt_bipi_pull_connect_cancel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_canceling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_canceling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_CANCELING_SCR);
    EntryNewScreen(SCR_BIP_ABORTING, NULL, mmi_bt_bipi_pull_entry_canceling, NULL);

    MMI_BIPI_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_GLOBAL_ABORTING, 0, 0, 0, 0, 0, (U8*) mmi_bip_notify_str, IMG_GLOBAL_PROGRESS, NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, mmi_bt_bipi_pull_canceling_screen_del_cb);
    
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);

    SetKeyHandler(mmi_bt_bipi_abort_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_disconnecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_disconnecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_DISCONNECTING_SCR);
    EntryNewScreen(SCR_BIP_DISCONNECTING, NULL, mmi_bt_bipi_pull_entry_disconnecting, NULL);

    MMI_BIPI_BUILD_DISCONNECTING_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_DISCONNECTING,
        0,
        0,
        0,
        0,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_DISCONNECTING, mmi_bt_bipi_pull_disconnecting_screen_del_cb);

    SetKeyHandler(mmi_bt_bipi_abort_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_disconnecting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting disconnecting screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_disconnecting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_DISCONNECTING_SCR_DEL_CB);
    if (MMI_TRUE == mmi_bt_bipi_pull_is_canceling())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_connecting_screen_del_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_bt_bipi_pull_connecting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CONNECTING_SCR_DEL_CB);

    if (MMI_TRUE == mmi_bt_bipi_pull_is_connecting())
        mmi_bt_bipi_pull_connect_cancel();

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_recving_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting receiving screen
 * PARAMETERS
 *  p     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_recving_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_RECVING_SCR_DEL_CB);
    if (MMI_TRUE == mmi_bt_bipi_pull_is_recving())
        mmi_bt_bipi_pull_abort_getting_images_operation();

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_canceling_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting canceling screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_canceling_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CANCELING_SCR_DEL_CB);
    if (MMI_TRUE == mmi_bt_bipi_pull_is_canceling())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_imglist_browser_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting file_browser screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_imglist_browser_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_IMGBROWSER_SCR_DEL_CB);
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_IDLE)
    {
        mmi_bt_bipi_send_disconnect_req(MMI_BIP_OBEX_DISCONNECT);       /* MMI_BIP_TP_DISCONNECT); */
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_img_detail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_img_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;
    S8 tmp_str[32]; /* convert tmp_str to UCS2 ? */

#define IMG_DETAIL_INFO_PREFIX_SPACE L"    "

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_IMG_DETAIL);
    EntryNewScreen(SCR_BIP_IMG_DETAIL, NULL, mmi_bt_bipi_pull_entry_img_detail, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FMGR_DETAIL);

    info = (PU8) subMenuData;

    /* construct image detail info */

    /* name */
    mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_BIP_DETAIL_NAME));
    mmi_ucs2cat((PS8) info, (PS8) L":\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);
    mmi_ucs2cat((PS8) info, (PS8) g_mmi_bt_bip_scr_cntx_p->img_name);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* encoding */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_ENCODING));
    mmi_ucs2cat((PS8) info, (PS8) L":\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    switch (g_mmi_bt_bip_scr_cntx_p->img_encoding)
    {
        case BT_BIP_IMG_TYPE_JPEG:
            mmi_ucs2cat((PS8) info, (PS8) L"jpeg");
            break;
        case BT_BIP_IMG_TYPE_GIF:
            mmi_ucs2cat((PS8) info, (PS8) L"gif");
            break;
        case BT_BIP_IMG_TYPE_WBMP:
            mmi_ucs2cat((PS8) info, (PS8) L"wbmp");
            break;
        case BT_BIP_IMG_TYPE_BMP:
            mmi_ucs2cat((PS8) info, (PS8) L"bmp");
            break;
        case BT_BIP_IMG_TYPE_PNG:
            mmi_ucs2cat((PS8) info, (PS8) L"png");
            break;
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* pixel */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_PIXEL));
    mmi_ucs2cat((PS8) info, (PS8) L":\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    kal_wsprintf(
        (U16*) tmp_str,
        "%d%c%d",
        g_mmi_bt_bip_scr_cntx_p->img_width,
        L'*',
        g_mmi_bt_bip_scr_cntx_p->img_height);
    mmi_ucs2cat((PS8) info, (PS8) tmp_str);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    /* size */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_BIP_DETAIL_SIZE));
    mmi_ucs2cat((PS8) info, (PS8) L":\n");
    //mmi_ucs2cat((PS8) info, (PS8) IMG_DETAIL_INFO_PREFIX_SPACE);

    mmi_bt_bip_print_size(g_mmi_bt_bip_scr_cntx_p->img_size, (U16*) tmp_str, MMI_TRUE);

    mmi_ucs2cat((PS8) info, (PS8) tmp_str);
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    ShowCategory74Screen(
        STR_FMGR_DETAIL,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_exit_preview_scr
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exit_preview_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_EXIT_PREVIEW);

#ifndef __MMI_BIP_LIST_THUMBNAIL__
    /* delete current thm file */
    FS_Delete((U16*)g_mmi_bt_bip_scr_cntx_p->img_thm_path);
#endif

    /* go back history */
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_preview_thumbnail
 * DESCRIPTION
 *  This function is to display the detailed info about the selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_preview_thumbnail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_str[BT_BIP_IMG_HANDLE_LEN * ENCODING_LENGTH];
    U16 left_softkey = 0;
    U32 idx = g_mmi_bt_bip_scr_cntx_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_PREVIEW);
    EntryNewScreen(SCR_BIP_IMG_DETAIL, NULL, mmi_bt_bipi_pull_entry_preview_thumbnail, NULL);

    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx])
    {
        left_softkey = STR_BIP_REMOVEFROM_GETLIST;
    }
    else
    {
        left_softkey = STR_BIP_ADDTO_GETLIST;
    }
        
    ShowCategory222Screen(
            0,                           /* title */
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            left_softkey,
            IMG_GLOBAL_OPTIONS, 
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                                /* right soft key */
            GDI_COLOR_WHITE,                                /* content BG color */
            (PS8) NULL,                                     /* button bar string */
            (PS8) g_mmi_bt_bip_scr_cntx_p->img_thm_path,    /* image file name */
            FALSE,                     /* is_short */
            NULL,/* result callback */
            GDI_IMAGE_SRC_FROM_FILE);

    /* convert the string to UCS2 */
    mmi_asc_to_ucs2((S8*) title_str, (S8*) g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
    /* change title to image handle */
    ChangeTitleString((PU8) title_str);
    draw_title();

    SetLeftSoftkeyFunction(mmi_bt_bipi_refresh_download_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bipi_refresh_download_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_bt_bipi_pull_exit_preview_scr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_exit_preview_scr, KEY_EVENT_UP);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_getting_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_getting_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMG);
    EntryNewScreen(SCR_BIP_RECEIVING, mmi_bt_bipi_pull_exit_recv_img, mmi_bt_bipi_pull_entry_getting_img, NULL);

    mmi_bt_bipi_pull_update_prog_string();

    /* Show Receiving screen */
    ShowCategory66Screen(
        STR_BIP_STATUS_RECEIVING,
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_abort_getting_images_operation, KEY_EVENT_UP);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, mmi_bt_bipi_pull_recving_screen_del_cb);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMG_DETAIL, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);
    DeleteScreenIfPresent(SCR_BIP_IMG_DETAIL);

    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BIP_PROG_UPD_DUR, mmi_bt_bipi_pull_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_aborting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_ABORTING);
    EntryNewScreen(SCR_BIP_ABORTING, NULL, mmi_bt_bipi_pull_entry_aborting, NULL);

    MMI_BIPI_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_GLOBAL_ABORTING, 0, 0, 0, 0, 0, (U8*) mmi_bip_notify_str, IMG_GLOBAL_PROGRESS, NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, mmi_bt_bipi_pull_aborting_screen_del_cb);

    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);

    SetKeyHandler(mmi_bt_bipi_abort_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_EndKey_press_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_EndKey_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENDKEY);
    g_mmi_bt_bip_scr_cntx_p->endkey_pressed = MMI_TRUE;

    mmi_bt_bipi_pull_entry_exit_confirm_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_imglist_option
 * DESCRIPTION
 *  This function is to display the option menu of image browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_imglist_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[20];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_OPTION);
    EntryNewScreen(SCR_BIP_IMGLIST_OPTION, NULL, mmi_bt_bipi_pull_entry_imglist_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BIP_IMGLIST_OPTION);
    RegisterHighlightHandler(mmi_bt_bipi_pull_imglist_option_highlight_hdlr);

    nNumofItem = GetNumOfChild(MENU_CONN_BIP_IMGLIST_OPTION);
    GetSequenceStringIds(MENU_CONN_BIP_IMGLIST_OPTION, nStrItemList);

    /* if no selected images, disable menu item "Get Selected Images" */
    if (g_mmi_bt_bip_scr_cntx_p->selected_img_num == 0)
    {
        for (i = 0; i < nNumofItem; i++)
        {
            nStrItemList[i] = nStrItemList[i + 1];
        }
        nNumofItem -= 1;
    }

    SetParentHandler(MENU_CONN_BIP_IMGLIST_BROWSER);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_bt_bipi_pull_imglist_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_bt_bipi_pull_imglist_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_imglist_option_highlight_hdlr
 * DESCRIPTION
 *  This function is to save the highlight index for option menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_imglist_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if no selected images, disable menu item "Get Selected Images" */
    if (g_mmi_bt_bip_scr_cntx_p->selected_img_num == 0)
    {
        index++;
    }

    switch (index)
    {
        case 0:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET;
            break;
        case 1:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL;
            break;
        case 2:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET_THM;
            break;
        case 3:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_GET_ALL;
            break;
        case 4:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_REFRESH;
            break;
        case 5:
            g_mmi_bt_bip_scr_cntx_p->sel_opt_id = MMI_BIP_SCR_SELECT_OPT_DISCONNECT;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_exit_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_exit_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_EXIT_CONFIRM_SCR);
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_IDLE)
    {
        MMI_BIPI_BUILD_EXIT_NOTY_STR();

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            mmi_bip_notify_str,
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        if (SCR_BIP_RECEIVING == GetCurrScrnId())
        {
            SetLeftSoftkeyFunction(mmi_bt_bipi_pull_exit_recving, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_bt_bipi_pull_exit_image_browser, KEY_EVENT_UP);
        }

        SetRightSoftkeyFunction(mmi_bt_bipi_pull_entry_exit_confirm_scr_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_bt_bipi_pull_exit_cfm_scr_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_exit_cfm_scr_EndKey_press_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exit_cfm_scr_EndKey_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_EXIT_CONFIRM_SCR_ENDKEY);
    g_mmi_bt_bip_scr_cntx.endkey_pressed = MMI_TRUE;

    mmi_bt_bipi_pull_exit_image_browser();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_getting_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_getting_imgprop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMGPROP);
    EntryNewScreen(SCR_BIP_GETTING_IMGPROP, NULL, mmi_bt_bipi_pull_entry_getting_imgprop, NULL);

    MMI_BIPI_BUILD_GETTING_IMGPROP_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_GETTING,
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, mmi_bt_bipi_pull_getting_imgprop_screen_del_cb);
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_abort_simple_operation, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_getting_imgthm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_getting_imgthm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_GETTING_IMGTHM);
    EntryNewScreen(SCR_BIP_GETTING_IMGPROP, NULL, mmi_bt_bipi_pull_entry_getting_imgthm, NULL);

    MMI_BIPI_BUILD_GETTING_IMGTHM_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_STATUS_GETTING,
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, mmi_bt_bipi_pull_getting_imgprop_screen_del_cb);
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_abort_simple_operation, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_imglist_option_LSK
 * DESCRIPTION
 *  This function is to execute the selected action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_imglist_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_OPTION_LSK);
    switch (g_mmi_bt_bip_scr_cntx_p->sel_opt_id)
    {
        case MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL:
            mmi_bt_bipi_get_cur_imgprop();
            
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET:
            mmi_bt_bipi_get_selected_images();
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET_ALL:
            mmi_bt_bipi_get_all_images();
            break;

        case MMI_BIP_SCR_SELECT_OPT_GET_THM:
            mmi_bt_bipi_get_cur_imgthm();
            break;

        case MMI_BIP_SCR_SELECT_OPT_REFRESH:
            mmi_bt_bipi_pull_refresh_imglist();
            break;

        case MMI_BIP_SCR_SELECT_OPT_DISCONNECT:
            mmi_bt_bipi_pull_entry_exit_confirm_scr();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_bipi_pull_update_prog_string();

    cat66_update_progress_string();

    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BIP_PROG_UPD_DUR, mmi_bt_bipi_pull_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_exit_recv_img
 * DESCRIPTION
 *  This function is to exit recving obj screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exit_recv_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_EXIT_RECV_IMG);
    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_aborting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting disconnecting screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_aborting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ABORTING_SCR_DEL_CB);
    if (MMI_TRUE == mmi_bt_bipi_pull_is_aborting())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_exit_confirm_scr_RSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_exit_confirm_scr_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_EXIT_CONFIRM_SCR_RSK);
    g_mmi_bt_bip_scr_cntx_p->endkey_pressed = MMI_FALSE;

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);    

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_getting_imgprop_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_bipi_pull_getting_imgprop_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GETTING_PROP_SCR_DEL_CB);
    if (MMI_TRUE == mmi_bt_bipi_pull_is_recving())
        mmi_bt_bipi_pull_abort_simple_operation();

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_print_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sz                  [IN]        
 *  tmp_str             [?]         
 *  b_print_0byte       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_bip_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sz > 1024 * 1024)
    {
        sz = sz / 1024;
        kal_wsprintf(tmp_str, "%d.%dMB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 1024)
    {
        kal_wsprintf(tmp_str, "%d.%dKB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 0)    /* less than 1024 */
    {
        kal_wsprintf(tmp_str, "%dB", (U16) (sz));
    }
    else if (b_print_0byte)
    {
        kal_wsprintf(tmp_str, "%dB", 0);
    }
    else
    {
        tmp_str[0] = 0;
        tmp_str[1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_update_prog_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_update_prog_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_img_num_to_get;
    U32 recved_size;
    U32 total_size;
    U16 tmp_str[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_bip_scr_cntx_p->received_img_num == 0 
        && g_bip_context.bip_initiator_cntx.cur_img_gotten_size == 0)
    {
        mmi_ucs2cpy((S8*) mmi_bip_notify_str, GetString(STR_BIP_STATUS_RECEIVING));
		mmi_ucs2cat((S8*) mmi_bip_notify_str, "\n"); /* category limit */
        return;
    }

    if (g_mmi_bt_bip_scr_cntx_p->get_type == MMI_BIP_GET_ALL_IMG)
        total_img_num_to_get = g_mmi_bt_bip_scr_cntx_p->img_total;
    else if (g_mmi_bt_bip_scr_cntx_p->get_type == MMI_BIP_GET_SELECTED_IMG)
        total_img_num_to_get = g_mmi_bt_bip_scr_cntx_p->selected_img_num;
    else
        total_img_num_to_get = 1; /* current single image */

    recved_size = g_bip_context.bip_initiator_cntx.cur_img_gotten_size;
    total_size = g_bip_context.bip_initiator_cntx.cur_img_total_size;

    mmi_bt_bip_print_size(recved_size, (U16*) mmi_bip_notify_str, MMI_TRUE);

    mmi_bt_bip_print_size(total_size, (U16*) tmp_str, MMI_FALSE);

    if (mmi_ucs2strlen((S8*) tmp_str) > 0)
    {
        mmi_ucs2cat((S8*) mmi_bip_notify_str, (S8*) L"/");
        mmi_ucs2cat((S8*) mmi_bip_notify_str, (S8*) tmp_str);
    }

    if (total_img_num_to_get > 1)
    {
        U32 cur_idx = g_mmi_bt_bip_scr_cntx_p->received_img_num + 1;

        kal_wsprintf(tmp_str, "%c\n%d%c%d", ',', cur_idx, '/', total_img_num_to_get);

        mmi_ucs2cat((S8*) mmi_bip_notify_str, (S8*) tmp_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_notify_recv_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_notify_recv_err(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_NOTIFY_RECV_ERR, cause);

    switch (cause)
    {
        case MMI_BIP_SUCCESS:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            break;

        case MMI_BIP_ERR_DISK_FULL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_RECV_DISK_FULL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_ROOT_DIR_FULL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_RECV_ROOT_DIR_FULL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_OPEN_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_OPEN_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_WRITE_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_WRITE_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_READ_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_READ_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_XML_GEN_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_XML_GEN_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_DISCONNECTED:
            DisplayPopup(
                (PU8) GetString(STR_BIP_CON_DISCONNECTED),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
/*
        case MMI_BIP_ERR_TIMEOUT:
            DisplayPopup(
                (PU8) GetString(STR_BIP_REQ_TIMEOUT),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
*/
/*
		case MMI_BIP_ERR_RPDR_NOT_SUPPORT:
			{
            DisplayPopup(
                (PU8) GetString(),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
			}
            break;
*/
        case MMI_BIP_ERR_SCO_REJECT:
            /* support device busy case for MT6601 */
            goto CLEAR_SCRS;
            break;

        default:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;

    }

  CLEAR_SCRS:
    
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMG_DETAIL, NULL);

    DeleteScreenIfPresent(SCR_BIP_CONNECTING);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);
    DeleteScreenIfPresent(SCR_BIP_ABORTING);
    DeleteScreenIfPresent(SCR_BIP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);
    DeleteScreenIfPresent(SCR_BIP_IMG_DETAIL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_clear_abort_scr
 * DESCRIPTION
 *  This function is to clear aborting screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_clear_abort_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CLEAR_ABORT_SCR);

    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_ABORTING);
    DeleteScreenIfPresent(SCR_BIP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);

    if (GetActiveScreenId() == SCR_BIP_ABORTING)
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_clear_get_imgprop_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_clear_get_imgprop_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_CLEAR_GET_IMGPROP_SCR);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_option_refresh_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_option_refresh_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_REFRESH_SCR);
    EntryNewScreen(SCR_BIP_CONNECTING, NULL, mmi_bt_bipi_pull_entry_option_refresh_scr, NULL);

    MMI_BIPI_BUILD_REFRESH_IMGLIST_NOTY_STR();

    ShowCategory66Screen(
        STR_BIP_OPTION_REFRESH,
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) mmi_bip_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, mmi_bt_bipi_pull_getting_imgprop_screen_del_cb);
    SetRightSoftkeyFunction(mmi_bt_bipi_pull_abort_simple_operation, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_refresh_imglist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_refresh_imglist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_REFRESH_IMGLIST);
    mmi_bt_bipi_pull_entry_option_refresh_scr();

    g_bip_context.bip_initiator_cntx.start_index = 0;

    g_mmi_bt_bip_scr_cntx_p->b_refreshed = MMI_TRUE;
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;

    mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_REFRESH_IMGLIST);

}

#define MMI_BT_BIP_GET_IMAGES_SCR_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_cur_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_exec_operation(mmi_bipi_cur_user_operation_enum oper_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_EXEC_OPER, oper_type);

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    if (mmi_bt_bipi_pull_is_getting_thm())
    {
        g_mmi_bt_bip_scr_cntx_p->next_oper = oper_type;
        
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_ABORTING);
        mmi_bt_bipi_send_abort_req(g_bip_context.bip_initiator_cntx.cm_conn_id);

        return;
    }
#endif

    switch (oper_type)
    {
    case MMI_BIP_NEXT_OPER_GET_IMGPROP:
        mmi_bt_bipi_send_get_imgprop_req(g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
        break;

    case MMI_BIP_NEXT_OPER_GET_THM:
        mmi_bt_bipi_send_get_imgthm_req(g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
        break;

    case MMI_BIP_NEXT_OPER_GET_IMG:
        mmi_bt_bipi_get_next_image();
        break;

    case MMI_BIP_NEXT_OPER_REFRESH_IMGLIST:
        mmi_bt_bipi_send_get_imglist_req();
        break;

    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_cur_imgprop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_cur_imgprop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_CUR_IMGPROP);
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;

    /* get img_handle from cur_index */
    ret = mmi_bt_bipi_pull_get_img_handle_from_index(g_mmi_bt_bip_scr_cntx_p->cur_index, g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
    if (ret > 0)
    {
        mmi_bt_bipi_pull_entry_getting_imgprop();

		mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

        mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMGPROP);
    }
    else
    {
        /* pop up */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_cur_imgthm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_cur_imgthm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_index = g_mmi_bt_bip_scr_cntx_p->cur_index;
    U16 default_img_id;
    U8 * p_thm_path;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_CUR_IMGTHM);

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
#else
    
#endif

    /* thm has not been gotten, get it now */

    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;

    /* get img_handle from cur_index */
    ret = mmi_bt_bipi_pull_get_img_handle_from_index(cur_index, g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
    if (ret > 0)
    {
        g_mmi_bt_bip_scr_cntx_p->b_user_get_thm = MMI_TRUE;
        
        mmi_bt_bipi_pull_entry_getting_imgthm();

	    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

        mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_THM);
    }
    else
    {
        /* pop up */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_cur_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_cur_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_CUR_IMG);
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;

    g_mmi_bt_bip_scr_cntx_p->get_type = MMI_BIP_GET_CUR_IMG;

    g_mmi_bt_bip_scr_cntx_p->received_img_num = 0;
    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;
    g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img = g_mmi_bt_bip_scr_cntx_p->sel_obj_id;

    /* if the receive-folder not exist, create it now. */
    h = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_path, FS_READ_ONLY | FS_OPEN_DIR);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        int ret = FS_CreateDir((U16*) g_bip_context.bip_initiator_cntx.img_path);
    }
    
    mmi_bt_bipi_pull_entry_getting_img();

    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

    mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMG);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_refresh_download_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_refresh_download_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = g_mmi_bt_bip_scr_cntx_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_REFRESH_DOWNLOAD_LIST);

    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx])
    {
        g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx] = 0;
        g_mmi_bt_bip_scr_cntx_p->selected_img_num--;
        ChangeLeftSoftkey(STR_BIP_ADDTO_GETLIST, IMG_GLOBAL_OPTIONS);
    }
    else
    {
        g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx] = 1;
        g_mmi_bt_bip_scr_cntx_p->selected_img_num++;
        ChangeLeftSoftkey(STR_BIP_REMOVEFROM_GETLIST, IMG_GLOBAL_OPTIONS);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_selected_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_selected_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_GET_SELECTED_IMG, g_mmi_bt_bip_scr_cntx_p->selected_img_num);
    ASSERT(g_mmi_bt_bip_scr_cntx_p->selected_img_num > 0);

    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;

    g_mmi_bt_bip_scr_cntx_p->get_type = MMI_BIP_GET_SELECTED_IMG;

    while (g_mmi_bt_bip_scr_cntx_p->checkbox_values[i] == 0 && i < g_mmi_bt_bip_scr_cntx_p->img_total)
        i++;

    g_mmi_bt_bip_scr_cntx_p->received_img_num = 0;
    g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img = i;
    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;

    /* if the receive-folder not exist, create it now. */
    h = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_path, FS_READ_ONLY | FS_OPEN_DIR);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        int ret = FS_CreateDir((U16*) g_bip_context.bip_initiator_cntx.img_path);
    }

    mmi_bt_bipi_pull_entry_getting_img();

    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

    mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMG);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_all_images
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_all_images(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_ALL_IMG);
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_TRUE;
    g_mmi_bt_bip_scr_cntx_p->get_type = MMI_BIP_GET_ALL_IMG;
    g_mmi_bt_bip_scr_cntx_p->received_img_num = 0;
    g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img = 0;
    g_bip_context.bip_initiator_cntx.cur_img_gotten_size = 0;

    /* if the receive-folder not exist, create it now. */
    h = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_path, FS_READ_ONLY | FS_OPEN_DIR);
    if ((h >= FS_NO_ERROR) || (h == FS_FILE_EXISTS))
    {
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        int ret = FS_CreateDir((U16*) g_bip_context.bip_initiator_cntx.img_path);
    }

    mmi_bt_bipi_pull_entry_getting_img();

    mmi_bt_bip_start_blinking(MMI_BT_CLIENT_ROLE);

    mmi_bt_bipi_pull_exec_operation(MMI_BIP_NEXT_OPER_GET_IMG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_next_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_next_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx = g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img;
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_NEXT_IMG);
    mmi_bt_bipi_pull_get_img_handle_from_index(idx, cur_img_handle);

    mmi_bt_bipi_pull_get_image(cur_img_handle);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_scr_get_img_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_scr_get_img_cnf(U8 cnf_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_done = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SCR_GET_IMG_CNF, cnf_code);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        g_mmi_bt_bip_scr_cntx_p->received_img_num++;
        
        /* check */
        if (g_mmi_bt_bip_scr_cntx_p->get_type == MMI_BIP_GET_ALL_IMG)
        {
            if (g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img == g_mmi_bt_bip_scr_cntx_p->img_total - 1)
            {
                /* all selected images has been gotten */
                b_done = MMI_TRUE;
            }
            else
            {
                g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img++;
            }
        }
        else if (g_mmi_bt_bip_scr_cntx_p->get_type == MMI_BIP_GET_SELECTED_IMG)
        {
            if (g_mmi_bt_bip_scr_cntx_p->received_img_num == g_mmi_bt_bip_scr_cntx_p->selected_img_num)
            {
                /* all selected images has been gotten */
                b_done = MMI_TRUE;
            }
            else
            {
                int i = g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img + 1;
        
                while (g_mmi_bt_bip_scr_cntx_p->checkbox_values[i] == 0 && i < g_mmi_bt_bip_scr_cntx_p->img_total)
                    i++;
                g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_img = i;
            }
        }
        else /* get current image in preview */
        {
            b_done = MMI_TRUE;
        }
        
        if (b_done)
        {
		    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

            /* popup "done" and return to image browser screen */
            mmi_bt_bipi_pull_img_end(MMI_BIP_SUCCESS);
        }
        else
        {
            mmi_bt_bipi_get_next_image();
        }
    }
    else
    {
	    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

        /* get image failed */
        mmi_bt_bipi_pull_img_end(MMI_BIP_ERR_REJECT_BY_SERVER);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_img_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_img_end(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 CurScrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_IMG_END, result);

    if (g_mmi_bt_bip_scr_cntx_p->received_img_num > 0)
    {
        /* Play warning tone to notify file saved */
        if (isInCall() != MMI_TRUE)
        {
            playRequestedTone(WARNING_TONE);
            mmi_bt_bipi_pull_entry_idle_notify_scr();
        }
        else
        {
            HistoryReplace(SCR_BIP_RECEIVING, SCR_BIP_NOTY_FILE_RECV, mmi_bt_bipi_pull_entry_idle_notify_scr);
        }
        TurnOnBacklight(1);
    }
    else
    {
    	CurScrID = GetActiveScreenId();
        if (SCR_BIP_ABORTING == CurScrID)
        {
            GoBackHistory();
        }
		else if (SCR_BIP_RECEIVING == CurScrID)
		{
		    mmi_bt_bipi_notify_recv_err(result);
        
	        SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);        
	        DeleteScreenIfPresent(SCR_BIP_RECEIVING);            
		}
    }
#if 0 /* keep the selected items */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    RefreshCategory426Screen();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_imgprop_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_imgprop_end(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BT BIP]bipi_get_imgprop_end...");

    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

	if (result == BT_BIP_CNF_SUCCESS)
	{
        /* display info of cnf->native_img */
        if (mmi_bt_bip_isForegroundScreen(SCR_BIP_GETTING_IMGPROP))
        {
            mmi_bt_bipi_pull_entry_img_detail();
        }
        else
        {
            mmi_bt_bip_history_replace(SCR_BIP_GETTING_IMGPROP, SCR_BIP_IMG_DETAIL);
        }
    }
    else
    {
        /* failed */
        mmi_bt_bip_notify_user_error(result);
        mmi_bt_bipi_pull_clear_get_imgprop_scr();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_build_notify_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_build_notify_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cnt[8];
    U16 img_cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_cnt = g_mmi_bt_bip_scr_cntx_p->received_img_num;

    kal_wstrcpy((U16*) mmi_bip_notify_str, (U16*) GetString(STR_BIP_NOTY_RECV_FILE_HED));
    kal_wsprintf((U16*) cnt, " %d ", img_cnt);
    kal_wstrcat((U16*) mmi_bip_notify_str, (U16*) cnt);
    if (img_cnt > 1)
        kal_wstrcat((U16*) mmi_bip_notify_str, (U16*) GetString(STR_BIP_NOTY_RECV_FILE_TIL));
    else
        kal_wstrcat((U16*) mmi_bip_notify_str, (U16*) GetString(STR_BIP_NOTY_RECV_FILE_SINGLE_TIL));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_idle_notify_scr
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_IDLE_NOTIFY_SCR);
    mmi_bt_bipi_pull_build_notify_string();

    EntryNewScreen(SCR_BIP_NOTY_FILE_RECV, NULL, mmi_bt_bipi_pull_entry_idle_notify_scr, NULL);

    ShowCategory154Screen(
        STR_BIP_IMGLIST_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_BIP_NOTY_RECV_FILE_BROWSE,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) mmi_bip_notify_str,
        NULL,
        IMG_GLOBAL_INFO,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_bipi_pull_notify_scr_browse, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (g_bip_context.bip_initiator_cntx.state != MMI_BIPI_STATE_IDLE)
    {
        SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);
    }

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, NULL);
    
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_ABORTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_notify_scr_browse_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         
 *  isShort         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_notify_scr_browse_cb(void *filename, int isShort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_NOTIFY_SCR_DEL_CB);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_notify_scr_browse
 * DESCRIPTION
 *  This function is to browse the received images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_NOTIFY_SCR_BROWSE);
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported(g_bip_context.bip_responder_cntx.recv_path))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_fmgr_select_path_and_enter(
        APP_BIP,
        FMGR_SELECT_BROWSE,
        filter,
        g_bip_context.bip_responder_cntx.recv_path,
        mmi_bt_bipi_pull_notify_scr_browse_cb);

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_FILE_RECV, NULL);
    DeleteScreenIfPresent(SCR_BIP_NOTY_FILE_RECV);
}

#define MMI_BT_BIP_CATEGORY_426_FUNC

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_empty_imgbrowser_RSK
 * DESCRIPTION
 *  function for empty image list browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_empty_imgbrowser_RSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[BIP MMI]mmi_bt_bipi_pull_empty_imgbrowser_RSK...");
    
#if 1
    mmi_bt_bipi_pull_entry_exit_confirm_scr();
#else        
/* under construction !*/
/* under construction !*/
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_entry_imglist_browser
 * DESCRIPTION
 *  Entry function for image list browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_entry_imglist_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 left_softkey;
    U16 left_softkey_icon;
    U16 right_softkey;
    S32 highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_ENTRY_IMGLIST_BROWSER);

    if (g_mmi_bt_bip_scr_cntx_p->b_refreshed)
    {
        /* after refreshed, img number is larger. realloc memory */
        if (g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist > g_mmi_bt_bip_scr_cntx_p->img_total)
        {
            mmi_bt_bipi_pull_app_mem_free();
        }
        else if (g_mmi_bt_bip_scr_cntx_p->checkbox_values)
        {
            /* clear checkbox */
            memset(g_mmi_bt_bip_scr_cntx_p->checkbox_values, 0, g_mmi_bt_bip_scr_cntx_p->img_total);
        }
        g_mmi_bt_bip_scr_cntx_p->selected_img_num = 0;
        /* clear the flag */
        g_mmi_bt_bip_scr_cntx_p->b_refreshed = MMI_FALSE;
    }
    
    g_mmi_bt_bip_scr_cntx_p->img_total = g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist;
    if (g_mmi_bt_bip_scr_cntx_p->img_total > BT_BIP_MAX_IMGHDLE_NUM)
        g_mmi_bt_bip_scr_cntx_p->img_total = BT_BIP_MAX_IMGHDLE_NUM;

    if (g_mmi_bt_bip_scr_cntx_p->cache_buffer == NULL && g_mmi_bt_bip_scr_cntx_p->img_total > 0)
    {
        kal_prompt_trace(MOD_MMI,"[BIP MMI]applib_mem_ap_alloc...\n");

        g_mmi_bt_bip_scr_cntx_p->cache_size = MMI_BIP_CAT426_CACHE_SIZE;

		g_mmi_bt_bip_scr_cntx_p->cache_buffer = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BT_BIP, g_mmi_bt_bip_scr_cntx_p->cache_size);
        if (g_mmi_bt_bip_scr_cntx_p->cache_buffer == NULL)
        {
      	    kal_prompt_trace(MOD_MMI, "[BT BIP] applib_mem_ap_alloc FAILED!!!");

            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_BT_BIP,
                0,
                g_mmi_bt_bip_scr_cntx_p->cache_size,
                mmi_bt_bipi_pull_entry_imglist_browser);
            return;
        }
    }
    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values == NULL && g_mmi_bt_bip_scr_cntx_p->img_total > 0)
    {

        g_mmi_bt_bip_scr_cntx_p->checkbox_values = OslMalloc(g_mmi_bt_bip_scr_cntx_p->img_total);
        if (g_mmi_bt_bip_scr_cntx_p->checkbox_values == NULL)
        {
            ASSERT(0);
        }
        memset(g_mmi_bt_bip_scr_cntx_p->checkbox_values, 0, g_mmi_bt_bip_scr_cntx_p->img_total);
    }

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, NULL);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_BROWSER);

    EntryNewScreen(SCR_BIP_IMGLIST_BROWSER, NULL, mmi_bt_bipi_pull_entry_imglist_browser, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_BIP_IMGLIST_BROWSER);

    RegisterHighlightHandler(mmi_bt_bipi_pull_imglist_highlight_hdlr);

    //if (g_mmi_bt_bip_scr_cntx_p->sel_opt_id == MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL || g_mmi_bt_bip_scr_cntx_p->sel_opt_id == MMI_BIP_SCR_SELECT_OPT_GET_THM)
    {
        /* hilight the last item selected when re-enter img browser screen */
        highlighted_item = g_mmi_bt_bip_scr_cntx_p->sel_obj_id;
    }
/*    
    else
    {
        highlighted_item = 0;
    }
*/
    if (g_mmi_bt_bip_scr_cntx_p->img_total > 0)
    {
        left_softkey = STR_GLOBAL_OPTIONS;
        left_softkey_icon = IMG_GLOBAL_OPTIONS;
        right_softkey = STR_GLOBAL_ON;
    }
    else
    {
        left_softkey = STR_BIP_OPTION_REFRESH;
        left_softkey_icon = 0;                      
        right_softkey = STR_BIP_EXIT_IMGBROWSER;    /* STR_GLOBAL_BACK; */
    }

    ShowCategory426Screen(
        STR_BIP_IMGLIST_BROWSER,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        left_softkey,
        left_softkey_icon,
        right_softkey,
        IMG_GLOBAL_BACK,
        CHECKBOX_ON_IMAGE_ID,
        CHECKBOX_OFF_IMAGE_ID,
        g_mmi_bt_bip_scr_cntx_p->img_total,
        mmi_bt_bipi_pull_get_img_handle_for_display,
        mmi_bt_bipi_pull_get_img_thm_for_display,
        g_mmi_bt_bip_scr_cntx_p->checkbox_values,
        g_mmi_bt_bip_scr_cntx_p->cache_buffer,
        g_mmi_bt_bip_scr_cntx_p->cache_size,
        highlighted_item,
        guiBuffer);

    if (g_mmi_bt_bip_scr_cntx_p->img_total > 0)
    {
        SetLeftSoftkeyFunction(mmi_bt_bipi_pull_entry_imglist_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bt_bipi_pull_refresh_imglist_category, KEY_EVENT_UP);
	    SetKeyHandler(mmi_bt_bipi_pull_entry_imglist_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bt_bipi_pull_refresh_imglist, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_bt_bipi_pull_empty_imgbrowser_RSK, KEY_EVENT_UP);
	    SetKeyHandler(mmi_bt_bipi_pull_refresh_imglist, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    mmi_bt_bip_store_endkey_hdlr();

    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_OPTION, NULL);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);

    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, mmi_bt_bipi_pull_imglist_browser_del_cb);

    SetKeyHandler(mmi_bt_bipi_pull_EndKey_press_handler, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_imglist_highlight_hdlr
 * DESCRIPTION
 *  Multi-file selection catefory refresh handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_imglist_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_bip_scr_cntx_p->cur_index = index;
    g_mmi_bt_bip_scr_cntx_p->sel_obj_id = (U16) index;

    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values[index])
    {
        ChangeRightSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_app_mem_free
 * DESCRIPTION
 *  Free APP-shared memory allocated for file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_app_mem_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_APP_MEM_FREE);
    if (g_mmi_bt_bip_scr_cntx_p->cache_buffer)
    {
        applib_mem_ap_free(g_mmi_bt_bip_scr_cntx_p->cache_buffer);
        g_mmi_bt_bip_scr_cntx_p->cache_buffer = NULL;
    }

    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values)
    {
        OslMfree(g_mmi_bt_bip_scr_cntx_p->checkbox_values);
        g_mmi_bt_bip_scr_cntx_p->checkbox_values = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_app_mem_stop_callback
 * DESCRIPTION
 *  APP-shared memory delete callback for file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_bipi_pull_app_mem_free();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BT_BIP, KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_refresh_imglist_category
 * DESCRIPTION
 *  Left softkey handler to select/unselect the file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_refresh_imglist_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int idx = g_mmi_bt_bip_scr_cntx_p->cur_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx])
    {
        g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx] = 0;
        g_mmi_bt_bip_scr_cntx_p->selected_img_num--;
        ChangeRightSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    else
    {
        g_mmi_bt_bip_scr_cntx_p->checkbox_values[idx] = 1;
        g_mmi_bt_bip_scr_cntx_p->selected_img_num++;
        ChangeRightSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }

    RefreshCategory426Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_get_img_handle_for_display
 * DESCRIPTION
 *  Rerturn file description to category 426
 * PARAMETERS
 *  start_index     [IN]        
 *  menu_data       [OUT]       
 *  data_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_bt_bipi_pull_get_img_handle_for_display(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_iconlist_menu_item *menu_item = menu_data;
    U32 offset = start_index * sizeof(bt_bip_img_min_info_struct);
    FS_HANDLE hFile;
    bt_bip_img_min_info_struct item;
    int len, ret;
    S32 i, cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_GET_IMGHANDLE_FOR_DISPLAY);
    
    hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_list_path, FS_READ_ONLY);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);
	ASSERT(hFile >= 0); /* if return 0, category426 will ASSERT */
	
    if (hFile >= 0)
    {
        FS_Seek(hFile, offset, FS_FILE_BEGIN);
        ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
		ASSERT(ret == FS_NO_ERROR && len > 0); /* if failed, category426 will ASSERT */

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        for (i = start_index; i < start_index + data_size && ret == FS_NO_ERROR && len > 0; i++)
        {
            /* convert the string to UCS2 */
            mmi_asc_to_ucs2((S8*) menu_item->item_list[0], (S8*) item.img_handle);
            if (item.created[0] != 0)
            {
                mmi_asc_to_ucs2((S8*) menu_item->item_list[1], (S8*) item.created);
            }
            else
            {
                S8 *pstr = (S8*) menu_item->item_list[1];

                pstr[0] = 0;
                pstr[1] = 0;
            }

            menu_item++;
            cnt++;

            ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
        }
        FS_Close(hFile);
    }

	ASSERT(cnt > 0);
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_get_img_thm_for_display
 * DESCRIPTION
 *  Rerturn image file to category 426
 * PARAMETERS
 *  index                   [IN]        
 *  image_filename          [OUT]       
 *  max_size                [IN]        
 *  default_image_id        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_bt_bipi_pull_get_img_thm_for_display(S32 index, U8 *image_filename, S32 max_size, U16 *default_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BIP_LIST_THUMBNAIL__
    U32 offset = index * sizeof(mmi_bip_img_browser_item_struct);
    FS_HANDLE hFile;
    mmi_bip_img_browser_item_struct item;
    int len;
    int ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_THM_FOR_DISPLAY, index);
    *default_image_id = IMG_BIP_DEFAULT_THM;

#ifndef __MMI_BIP_LIST_THUMBNAIL__

    return;

#else

    hFile = FS_Open((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path, FS_READ_ONLY);
    kal_prompt_trace(MOD_MMI,"[BIP MMI]FS_Open(img_browser_content_path) return 0x%x\n", hFile);    
    if (hFile >= 0)
    {
        ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
        kal_prompt_trace(MOD_MMI,"[BIP MMI]FS_Seek(img_browser_content_path) return 0x%x\n", ret);    
		if (ret != offset)
		{
			FS_Close(hFile);
			return;
		}

        ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
        kal_prompt_trace(MOD_MMI,"[BIP MMI]FS_Read(img_browser_content_path) return 0x%x, read_len=%d\n", ret, len);    
        FS_Close(hFile);

        if (ret == FS_NO_ERROR && len > 0 && mmi_ucs2strlen(item.thm_name) > 0)
        {
            mmi_ucs2cpy((S8*) image_filename, (S8*) item.thm_name);

            kal_prompt_trace(MOD_MMI,"[BIP MMI]--- thm filename: ");    
            MMI_BIP_LOG_PATH(image_filename)
        }
        else
        {
        }
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_scr_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_scr_imglist_gotten(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_IMGLIST_GOTTEN);

    /* delete the old value */
    FS_Delete((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path); 

    /* create empty thm name list file */
    hFile = FS_Open((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (hFile >= 0)
        FS_Close(hFile);

    g_mmi_bt_bip_scr_cntx_p->sel_obj_id = 0;

    /* release previous memory */
    mmi_bt_bipi_pull_app_mem_free();

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    /* get the first thm */
    g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_thm = 0;
    if (g_bip_context.bip_initiator_cntx.img_handle_num_in_imglist > 0)
    {
        mmi_bt_bipi_get_next_thm(g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_thm);
    }

#endif /* __MMI_BIP_LIST_THUMBNAIL__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_scr_connect_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_scr_connect_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_SCR_CONNECT_TERMINATED);
    
    /* delete the thm name list file */
    ret = FS_Delete((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_DELETE_RETURN, ret);

    /* release malloced memory, if any */
    mmi_bt_bipi_pull_app_mem_free();

    g_mmi_bt_bip_scr_cntx_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    g_mmi_bt_bip_scr_cntx_p->b_refreshed = MMI_FALSE;
    g_mmi_bt_bip_scr_cntx_p->b_user_get_thm = MMI_FALSE;
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_abort_simple_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_abort_simple_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_ABORT_SIMPLE_OPER);

    g_mmi_bt_bip_scr_cntx_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    
    mmi_bt_bipi_pull_entry_aborting();

    mmi_bt_bipi_pull_simple_abort();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_abort_getting_images_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_pull_abort_getting_images_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_ABORT_GET_IMG);

    g_mmi_bt_bip_scr_cntx_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    
    mmi_bt_bipi_pull_entry_aborting();

    mmi_bt_bipi_pull_abort_getting_images();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_scr_aborted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bipi_pull_scr_aborted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL b_proc = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_PULL_SCR_ABORTED, g_mmi_bt_bip_scr_cntx_p->next_oper);

#ifdef __MMI_BIP_LIST_THUMBNAIL__
    switch(g_mmi_bt_bip_scr_cntx_p->next_oper)
    {
        case MMI_BIP_NEXT_OPER_GET_IMG:
            mmi_bt_bipi_get_next_image();
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_GET_THM:
            mmi_bt_bipi_send_get_imgthm_req(g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_GET_IMGPROP:
            mmi_bt_bipi_send_get_imgprop_req(g_mmi_bt_bip_scr_cntx_p->cur_img_handle);
            b_proc = MMI_TRUE;
            break;

        case MMI_BIP_NEXT_OPER_REFRESH_IMGLIST:
            mmi_bt_bipi_send_get_imglist_req();
            b_proc = MMI_TRUE;
            break;

        default:
            break;
    }
#endif
    g_mmi_bt_bip_scr_cntx_p->next_oper = MMI_BIP_NEXT_OPER_IDLE;
    return b_proc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_get_next_thm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_get_next_thm(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_PULL_GET_NEXT_THM);
    mmi_bt_bipi_pull_get_img_handle_from_index(index, cur_img_handle);
    mmi_bt_bipi_send_get_imgthm_req((S8*) cur_img_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_scr_get_thm_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  thm_path        [?]         [?]
 *  cnf_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_scr_get_thm_cnf(U8 cnf_code, U8 *thm_path, U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BIP_LIST_THUMBNAIL__
    mmi_bip_img_browser_item_struct item;
    int index;
    U32 offset;
    FS_HANDLE hFile;
    int len;
    int ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_SCR_GET_THM_CNF, cnf_code);

#ifdef __MMI_BIP_LIST_THUMBNAIL__

    if (!g_mmi_bt_bip_scr_cntx_p->b_user_get_thm)
    {
        index = g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_thm;
    }
    else
    {
        index = g_mmi_bt_bip_scr_cntx_p->cur_index;
    }

    offset = index * sizeof(mmi_bip_img_browser_item_struct);

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {        
        hFile = FS_Open((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path, FS_READ_WRITE);
        MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);
        
        if (hFile >= 0)
        {
            /* read out the old value */
            ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
            ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_READ_RETURN, ret);
            
            /* write the new value */
            mmi_ucs2cpy((S8*) item.thm_name, (S8*) thm_path);
            mmi_ucs2cat((S8*) item.thm_name, (S8*) name);

            kal_prompt_trace(MOD_MMI,"[BIP MMI]--- index=%d, thm_name: ", index);
            MMI_BIP_LOG_PATH(item.thm_name);
            
            ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
            ret = FS_Write(hFile, &item, sizeof(item), (UINT*) & len);
            MMI_BIP_LOG1(MMI_BT_BIP_FS_WRITE_RETURN, ret);
            
            FS_Close(hFile);

            if (!g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm)
            {
                kal_prompt_trace(MOD_MMI,"[BIP MMI]---RefreshCategory426Screen...\n");
                RefreshCategory426Screen();            
            }
        }

    }

    /* get next thm */
    if (index < g_mmi_bt_bip_scr_cntx_p->img_total - 1 && !g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm)
    {
        index++;
        mmi_bt_bipi_get_next_thm(index);
        g_mmi_bt_bip_scr_cntx_p->cur_idx_to_get_thm = index;
    }
    else
    {
        kal_prompt_trace(MOD_MMI,"[BIP MMI]---get_thm_END!...\n");
        mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);
    }
#endif    

    if (g_mmi_bt_bip_scr_cntx_p->b_user_get_thm)
    {
	    mmi_bt_bip_stop_blinking(MMI_BT_CLIENT_ROLE);

        if (cnf_code == BT_BIP_CNF_SUCCESS)
        {
            mmi_ucs2cpy((S8*)g_mmi_bt_bip_scr_cntx_p->img_thm_path, (S8*)thm_path);
            mmi_ucs2cat((S8*)g_mmi_bt_bip_scr_cntx_p->img_thm_path, (S8*)name);

            kal_prompt_trace(MOD_MMI,"[BIP MMI]---User get thm:...");
            MMI_BIP_LOG_PATH(g_mmi_bt_bip_scr_cntx_p->img_thm_path);

            if (mmi_bt_bip_isForegroundScreen(SCR_BIP_GETTING_IMGPROP))
            {
                /* Preview the thumbnail*/
                mmi_bt_bipi_pull_entry_preview_thumbnail();
            }
            else
            {
                /* place the imglist browser into history */
                mmi_bt_bip_history_replace(SCR_BIP_GETTING_IMGPROP, SCR_BIP_IMG_DETAIL);
            }
        }
        else
        {
            /* pop up */
            mmi_bt_bipi_notify_recv_err(MMI_BIP_ERR_REJECT_BY_SERVER);
        }
        
        SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);        
        DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);

        g_mmi_bt_bip_scr_cntx_p->b_user_get_thm = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_pull_get_img_handle_from_index
 * DESCRIPTION
 *  Rerturn img handle
 * PARAMETERS
 *  index           [IN]        
 *  img_handle      [?]         [?]
 *  data_size(?)        [IN](?)
 *  menu_data(?)        [OUT](?)
 *  start_index(?)      [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_bt_bipi_pull_get_img_handle_from_index(S32 index, S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_min_info_struct item;
    U32 offset = index * sizeof(bt_bip_img_min_info_struct);
    FS_HANDLE hFile;
    int len, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_GET_IMGHANDLE_FROM_INDEX, index);
    hFile = FS_Open((U16*) g_bip_context.bip_initiator_cntx.img_list_path, FS_READ_ONLY);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_OPEN_RETURN, hFile);
    if (hFile < 0)
    {
        return 0;
    }
    ret = FS_Seek(hFile, offset, FS_FILE_BEGIN);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_SEEK_RETURN, ret);
    ret = FS_Read(hFile, &item, sizeof(item), (UINT*) & len);
    MMI_BIP_LOG1(MMI_BT_BIP_FS_READ_RETURN, ret);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) img_handle, (S8*) item.img_handle);

    FS_Close(hFile);

    return 1;
}

#define MMI_BT_BIP_SCR_RESPONDER


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_entry_recv_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  U32(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_entry_recv_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dev_name_tmp[MMI_BT_SCR_BD_NAME_LEN];
    U8 cnf_str[140];    /* STR_BIP_CON_AUTH(48) + " "(2) + GOEP_MAX_DEV_NAME(80) = 130 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ENTRY_RECV_CONFIRM_SCR);

    memset(dev_name_tmp, 0, MMI_BT_SCR_BD_NAME_LEN);

    /* common notify string */
    kal_wstrcpy((U16*) cnf_str, (U16*) GetString(STR_BIP_CON_AUTH));

    /* build dev_name string */
    mmi_bt_bipr_get_dev_name(dev_name_tmp);
    kal_wstrcat((U16*) cnf_str, (U16*) L" ");
    kal_wstrcat((U16*) cnf_str, (U16*) dev_name_tmp);
    kal_wstrcat((U16*) cnf_str, (U16*) L"?");

    EntryNewScreen(SCR_BIP_NOTY_CONN_REQ, NULL, mmi_bt_bipr_entry_recv_confirm_scr, NULL);

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_CONN_REQ, NULL);
    DeleteScreenIfPresent(SCR_BIP_NOTY_CONN_REQ);

    ShowCategory7Screen(
        STR_BT_MENU_TITLE,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        IMG_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (U8*) cnf_str,
        NULL);

    SetLeftSoftkeyFunction(mmi_bt_bipr_accept_conn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bt_bipr_reject_conn, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_CONN_REQ, mmi_bt_bipr_authorize_confirm_del_cb);
    TurnOnBacklight(1);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_accept_conn
 * DESCRIPTION
 *  This function is to accept rfcomm channel.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_accept_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_R_ACCEPT_CONN);

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_CONN_REQ, (HistoryDelCBPtr) NULL);

    GoBackHistory();

    /* Send success connect response to OBEX task */
    mmi_bt_bipr_send_connect_rsp(BT_BIP_CNF_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_reject_conn
 * DESCRIPTION
 *  This function is to reject rfcomm channel.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_reject_conn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_R_REJECT_CONN);

    SetDelScrnIDCallbackHandler(SCR_BIP_NOTY_CONN_REQ, (HistoryDelCBPtr) NULL);
    GoBackHistory();

    /* Send failed connect response to OBEX task */
    mmi_bt_bipr_send_connect_rsp(BT_BIP_CNF_FAILED);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipr_notify_recv_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipr_notify_recv_err(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG1(MMI_BT_BIP_NOTIFY_RECV_ERR, cause);

    switch (cause)
    {
        case MMI_BIP_ERR_DISK_FULL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_RECV_DISK_FULL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_ROOT_DIR_FULL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_RECV_ROOT_DIR_FULL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_OPEN_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_OPEN_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_WRITE_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_WRITE_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_FILE_READ_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_READ_FILE_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_XML_GEN_FAIL:
            DisplayPopup(
                (PU8) GetString(STR_BIP_XML_GEN_FAIL),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        case MMI_BIP_ERR_DISCONNECTED:
            DisplayPopup(
                (PU8) GetString(STR_BIP_CON_DISCONNECTED),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;

        default:
            break;

    }
}



#define MMI_BT_BIP_SCR_UTIL_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_clear_scrs
 * DESCRIPTION
 *  This function is to clear BIP screens
 * PARAMETERS
 *  disc_reset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_clear_scrs(U8 disc_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_I_CLEAR_SCR);

    SetDelScrnIDCallbackHandler(SCR_BIP_SENDING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_CONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_ABORTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_RECEIVING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_DISCONNECTING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_GETTING_IMGPROP, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMG_DETAIL, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_SENDING, NULL);
    SetDelScrnIDCallbackHandler(SCR_BIP_IMGLIST_BROWSER, NULL);

    DeleteScreenIfPresent(SCR_BIP_DISCONNECTING);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_BROWSER);
    DeleteScreenIfPresent(SCR_BIP_CONNECTING);
    DeleteScreenIfPresent(SCR_BIP_RECEIVING);
    DeleteScreenIfPresent(SCR_BIP_ABORTING);
    DeleteScreenIfPresent(SCR_BIP_IMGLIST_OPTION);
    DeleteScreenIfPresent(SCR_BIP_GETTING_IMGPROP);
    DeleteScreenIfPresent(SCR_BIP_IMG_DETAIL);
    DeleteScreenIfPresent(SCR_BIP_SENDING);

    if (disc_reset == MMI_BIP_CLEAR_SCR_ON_DISCONNECT)
    {
        if (g_mmi_bt_bip_scr_cntx_p->endkey_pressed == MMI_TRUE)
        {
            mmi_bt_bip_exe_endkey_hdlr();
            g_mmi_bt_bip_scr_cntx_p->endkey_pressed = MMI_FALSE;
        }
    }

    /* reset variables; */
    FS_Delete((U16*) g_mmi_bt_bip_scr_cntx_p->img_browser_content_path);

    g_mmi_bt_bip_scr_cntx_p->selected_img_num = 0;
    g_mmi_bt_bip_scr_cntx_p->sel_obj_id = 0;
    g_mmi_bt_bip_scr_cntx_p->sel_opt_id = 0;
    g_mmi_bt_bip_scr_cntx_p->endkey_pressed = MMI_FALSE;
    g_mmi_bt_bip_scr_cntx_p->b_stop_bg_getting_thm = MMI_FALSE;

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_BIP_DISCONNECTING:
        case SCR_BIP_IMGLIST_BROWSER:
        case SCR_BIP_CONNECTING:
        case SCR_BIP_RECEIVING:
        case SCR_BIP_ABORTING:
        case SCR_BIP_IMGLIST_OPTION:
        case SCR_BIP_GETTING_IMGPROP:
        case SCR_BIP_IMG_DETAIL:
        case SCR_BIP_SENDING:
            GoBackHistory();
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bipi_abort_scr_EndKey_press_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bipi_abort_scr_EndKey_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ABORT_SCR_ENDKEY);
    
    g_mmi_bt_bip_scr_cntx.endkey_pressed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_history_replace
 * DESCRIPTION
 *  This function is a AddHistory wrapper function
 * PARAMETERS
 *  out_scr     [IN]        
 *  in_scr      [IN]        
 *  U16(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_history_replace(U16 out_scr, U16 in_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_HISTORY_REPLACE);
    switch (in_scr)
    {
        case SCR_BIP_IMGLIST_BROWSER:
            HistoryReplace(out_scr, in_scr, mmi_bt_bipi_pull_entry_imglist_browser);
            break;

        case SCR_BIP_IMG_DETAIL:
            HistoryReplace(out_scr, in_scr, mmi_bt_bipi_pull_entry_img_detail);
            break;

        default:
            ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_add_history_before_cm_marker
 * DESCRIPTION
 *  Add a screen to the history before CM_SCR_MARKER
 * PARAMETERS
 *  scrn_id         [IN]        
 *  func_ptr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_ADD_HISTORY_BEFORE_CM);
    Scr.scrnID = scrn_id;
    Scr.entryFuncPtr = func_ptr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) L"");

    InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_scr_recv_img_ind
 * DESCRIPTION
 *  notify user that an image has been received
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_scr_recv_img_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_SCR_RECV_IMG_IND);

    if ((isInCall() != MMI_TRUE) || (IsWapCallPresent()))
    {
        BIP_BUILD_IMG_RECV_NOTY_STR();

        /* Play warning tone to notify file saved */
	    DisplayPopup((PU8) mmi_bip_notify_str, IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    }

    if (g_idle_context.IsOnIdleScreen || GetActiveScreenId() == SCR_OPP_NOTY_FILE_RECV)
    {
        EntryIdleScreen();
    }

    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_store_endkey_hdlr
 * DESCRIPTION
 *  This function is to store the default end key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_store_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_mmi_bt_bip_scr_cntx_p->keyup_fp == NULL) && (g_mmi_bt_bip_scr_cntx_p->keydown_fp == NULL))
    {
        g_mmi_bt_bip_scr_cntx_p->keyup_fp = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
        g_mmi_bt_bip_scr_cntx_p->keydown_fp = GetKeyHandler(KEY_END, KEY_EVENT_UP);

        g_mmi_bt_bip_scr_cntx_p->endkey_pressed = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_clear_endkey_hdlr
 * DESCRIPTION
 *  This function is to store the default end key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_clear_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bt_bip_scr_cntx_p->keyup_fp = NULL;
    g_mmi_bt_bip_scr_cntx_p->keydown_fp = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_exe_endkey_hdlr
 * DESCRIPTION
 *  This function is to execute the default end key handler and reset it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bip_exe_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIP_LOG(MMI_BT_BIP_EXEC_ENDKEY_HDLR);

    if (g_mmi_bt_bip_scr_cntx_p->keyup_fp)
    {
        (g_mmi_bt_bip_scr_cntx_p->keyup_fp) ();
    }

    if (g_mmi_bt_bip_scr_cntx_p->keydown_fp)
    {
        (g_mmi_bt_bip_scr_cntx_p->keydown_fp) ();
    }

    mmi_bt_bip_clear_endkey_hdlr();
}

extern pBOOL isInCall(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_isForegroundScreen
 * DESCRIPTION
 *  This function is to check the specified scr_id is foreground screen or not.
 * PARAMETERS
 *  scrn_id     [IN]        to be checked
 * RETURNS
 *  MMI_TRUE: foreground
 *  MMI_FALSE: background
 *****************************************************************************/
MMI_BOOL mmi_bt_bip_isForegroundScreen(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall())
        return MMI_FALSE;
    else
        return MMI_TRUE;

}

#endif  /* __MMI_BIP_SUPPORT__ */
#endif  /* __MMI_BT_MTK_SUPPORT__ */
