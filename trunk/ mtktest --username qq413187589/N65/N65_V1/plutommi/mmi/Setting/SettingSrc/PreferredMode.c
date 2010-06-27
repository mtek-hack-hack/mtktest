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
 *  PreferredMode.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for GSM/WLAN preferred mode application
 *
 * Author:
 * -------
 * -------
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

#ifdef __MMI_WLAN_FEATURES__
#include "CSP.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "PrefNwksGprot.h"
#include "CommonScreens.h"
#include "MessagesExDcl.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "CallManagementGprot.h"
#include "SSCStringHandle.h"
#include "PhoneBookDef.h"

#include "FlightModeGProt.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"

#ifdef __MMI_VOIP__
#include "VoIPResDef.h"
#include "VoIPGProt.h"
#endif /* __MMI_VOIP__ */

#include "SmsGuiInterfaceProt.h"
#include "DataAccountGProt.h"

#include "wgui_status_icons.h"
#include "wgui_categories_util.h"

#include "WallpaperDefs.h"
#include "DownloadDefs.h"
#include "PhoneSetup.h"

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif
#ifdef __MMI_DUAL_SIM_MASTER__ 
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */


extern void mmi_voip_go_back_2_history(void);
extern void UI_set_font(UI_font_type f);


/*
 * Local Variable
 */
typedef struct _netset_p_mode_req
{
    FuncPtr netset_preferred_mode_req;
    U8 state;
} NETSETPMODEREQ;

static NETSETPMODEREQ mmi_netset_p_mode_req[] = 
{
    {mmi_phnset_enter_gsm_flight_mode, 0},
    {mmi_phnset_exit_gsm_flight_mode, 0},
    {mmi_netset_enter_wlan_flight_mode, 0},
    {mmi_netset_exit_wlan_flight_mode, 0},
    {NULL, 0} /* dummy one, please add callbacks before this entity */
};


/*
 * External Variable
 */
extern NetworkSetupDisplay gNetworkSetupDisplay;
extern PHNSET_CNTX g_phnset_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_preferred_mode
 * DESCRIPTION
 *  Highlight handler for MENU_ID_NETSET_PREFERRED_MODE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_netset_entry_preferred_mode, KEY_EVENT_UP); 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_netset_entry_preferred_mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_preferred_mode
 * DESCRIPTION
 *  Entry function for MENU_ID_NETSET_PREFERRED_MODE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 4;
    U8 *guiBuffer;
    U16 nStrItemList[4] = {
                STR_ID_NETSET_PREFERRED_MODE_GSM_ONLY,
                STR_ID_NETSET_PREFERRED_MODE_WLAN_ONLY,
                STR_ID_NETSET_PREFERRED_MODE_GSM_PREFERRED,
                STR_ID_NETSET_PREFERRED_MODE_WLAN_PREFERRED};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_PREFERRED_MODE, NULL, mmi_netset_entry_preferred_mode, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_PREFERRED_MODE);
    RegisterHighlightHandler(mmi_netset_preferred_mode_highlight_hdlr);
    ShowCategory11Screen(
        STR_ID_NETSET_PREFERRED_MODE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        gNetworkSetupDisplay.PreferredModeCurrentIndex,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_netset_pre_check_preferred_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_hint_preferred_mode
 * DESCRIPTION
 *  Hint handler for MENU_ID_NETSET_PREFERRED_MODE
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_hint_preferred_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = mmi_netset_get_active_preferred_mode();

     switch (data)
    {
        case P_GSM_ONLY:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_PREFERRED_MODE_GSM_ONLY));
            break;
        case P_WLAN_ONLY:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_PREFERRED_MODE_WLAN_ONLY));
            break;
        case P_GSM_PREFERRED:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_PREFERRED_MODE_GSM_PREFERRED));
            break;
        case P_WLAN_PREFERRED:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_PREFERRED_MODE_WLAN_PREFERRED));
            break;
        default:
            mmi_ucs2cpy((PS8) hintData[index], (PS8) "");
            break;
    }

    gNetworkSetupDisplay.PreferredModeCurrentIndex = data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_preferred_mode_highlight_hdlr
 * DESCRIPTION
 *  Hint handler for preferred mode items
 * PARAMETERS
 *  index         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_preferred_mode_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.PreferredModeCurrentIndex = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETPreferredModeSelectionOK
 * DESCRIPTION
 *  Process of preferred mode user selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_preferred_mode_switch_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    U8 current_mode = 0;
    U8 selected_mode = gNetworkSetupDisplay.PreferredModeCurrentIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_mode = mmi_netset_get_active_preferred_mode();

    WriteValue(NVRAM_NETSET_PREFERRED_MODE, &selected_mode, DS_BYTE, &error);
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_NETSET_PREFERRED_MODE);

    /* show status icons after switch mode */
    if (current_mode == P_WLAN_ONLY && selected_mode != P_WLAN_ONLY)
    {
        PhnsetFlightModeRestoreStatusIconFlags(MMI_FALSE);
        UpdateStatusIcons();
    }

    /* hide status icons before switch mode */
    if (current_mode != P_WLAN_ONLY && selected_mode == P_WLAN_ONLY)
    {
        PhnsetFlightModeSaveStatusIconFlags(MMI_FALSE);
        UpdateStatusIcons();
    }

    mmi_netset_update_preferred_mode_menu(); 

    /* register WLAN callback for status change */
    if (current_mode == P_GSM_ONLY && selected_mode != P_GSM_ONLY)
    {
        mmi_asc_to_ucs2((S8 *) gWLANProviderName, (S8 *) "WLAN OFF");
        mmi_wlan_add_event_notify_hdlr(mmi_netset_register_wlan_stauts_cb);
    }

    if (current_mode != P_GSM_ONLY && selected_mode == P_GSM_ONLY)
    {
        mmi_asc_to_ucs2((S8 *) gWLANProviderName, (S8 *) "");
        mmi_wlan_remove_event_notify_hdlr(mmi_netset_register_wlan_stauts_cb);
    }

    /* determine if need to display root screen after mode switch */
    if (!mmi_bootup_is_sim_valid())
    {
        if ((current_mode == P_GSM_ONLY && selected_mode != P_GSM_ONLY) ||
            (current_mode != P_GSM_ONLY && selected_mode == P_GSM_ONLY))
        {
            if (IsScreenPresent(SCR_SIM_INSERTION))
            {
                DeleteUptoScrID(SCR_SIM_INSERTION);
            }
            else if (IsScreenPresent(SCR_SIM_INSERTION))
            {
                DeleteUptoScrID(SCR_SIM_BLOCK);
            }
            else
            {
                DeleteUptoScrID(IDLE_SCREEN_ID);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_switch_preferred_mode
 * DESCRIPTION
 *  Switch preferred mode beginning and callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_switch_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; mmi_netset_p_mode_req[i].netset_preferred_mode_req != NULL; i++)
    {
        if (mmi_netset_p_mode_req[i].state)
        {
            mmi_netset_p_mode_req[i].state = 0;
            (*mmi_netset_p_mode_req[i].netset_preferred_mode_req)();
            return;
        }
    }

    mmi_netset_preferred_mode_switch_done();

    for (i = 0; mmi_netset_p_mode_req[i].netset_preferred_mode_req != NULL; i++)
    {
	mmi_netset_p_mode_req[i].state = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_pre_check_preferred_mode
 * DESCRIPTION
 *  Pre-check function to enter flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_pre_check_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 current_mode = 0;
    U8 selected_mode = gNetworkSetupDisplay.PreferredModeCurrentIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_mode = mmi_netset_get_active_preferred_mode();
    PRINT_INFORMATION("@@@@@ Preferred mode: change from %d to %d @@@@@", current_mode, selected_mode);

    switch (current_mode)
    {
        case P_GSM_ONLY:
            switch (selected_mode)
            {
                case P_WLAN_ONLY:
                    mmi_netset_p_mode_req[0].state = 1; /* enter GSM flight mode */
                    mmi_netset_p_mode_req[3].state = 1; /* leave WLAN flight mode */
                    break;

                case P_GSM_PREFERRED:
                case P_WLAN_PREFERRED:
                    mmi_netset_p_mode_req[3].state = 1; /* leave WLAN flight mode */ 
                    break;

                case P_GSM_ONLY:
                default:
                    break;
            }
            break;

        case P_WLAN_ONLY:
            switch (selected_mode)
            {
                case P_GSM_ONLY:
                    mmi_netset_p_mode_req[1].state = 1; /* leave GSM flight mode */ 
                    mmi_netset_p_mode_req[2].state = 1; /* enter WLAN flight mode */
                    break;

                case P_GSM_PREFERRED:
                case P_WLAN_PREFERRED:
                    mmi_netset_p_mode_req[1].state = 1; /* leave GSM flight mode */ 
                    break;

                case P_WLAN_ONLY:
                default:
                    break;
            }
            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            switch (selected_mode)
            {
                case P_GSM_ONLY:
                    mmi_netset_p_mode_req[2].state = 1; /* enter WLAN flight mode */
                    break;

                case P_WLAN_ONLY:
                    mmi_netset_p_mode_req[0].state = 1; /* enter GSM flight mode */
                    break;

                case P_GSM_PREFERRED:
                case P_WLAN_PREFERRED:
                default:
                    break;
            }
            break;

        default:
            break;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_netset_switch_preferred_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_active_preferred_mode
 * DESCRIPTION
 *  Get active preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_netset_get_active_preferred_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 current_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_NETSET_PREFERRED_MODE, &current_mode, DS_BYTE, &error);

    if (current_mode >= P_MODE_END)
    {
        current_mode = P_GSM_PREFERRED;
        WriteValue(NVRAM_NETSET_PREFERRED_MODE, &current_mode, DS_BYTE, &error);
    }

    return current_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_preferred_mode_service_area
 * DESCRIPTION
 *  Update idle service area based on preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_update_preferred_mode_service_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern UI_string_type idle_screen_network_name;
    extern UI_string_type idle_screen_network_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            SetIdleScreenNetworkName(gWLANProviderName); /* Line1: WLAN */
            SetIdleScreenNetworkStatus(NULL);
            break;

        case P_GSM_PREFERRED:
            SetIdleScreenNetworkStatus(gWLANProviderName); /* Line2: WLAN */
            break;

        case P_WLAN_PREFERRED:
            idle_screen_network_status = idle_screen_network_name;
            SetIdleScreenNetworkName(gWLANProviderName); /* Line1: WLAN */
            break;

        case P_GSM_ONLY:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_register_wlan_stauts_cb
 * DESCRIPTION
 *  Registration function for WLAN status change
 * PARAMETERS
 *  wlan_state         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_register_wlan_stauts_cb(U16 wlan_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 iCnt = 0;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    extern S32 MAIN_LCD_device_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Preferred mode: WLAN status update to %d@@@@@", wlan_state);

    if (wlan_state == DTCNT_BEARER_STATE_INACTIVE)
    {
        mmi_asc_to_ucs2((S8 *) gWLANProviderName, (S8 *) "WLAN OFF");
    }
    else if (wlan_state == DTCNT_BEARER_STATE_INITIALIZED)
    {
        mmi_asc_to_ucs2((S8 *) gWLANProviderName, (S8 *) "WLAN ON");
    }
    else
    {
        mmi_wlan_get_connected_ap_ssid((S8 *) gWLANProviderName, MAX_LENGTH_DISPLAY_NAME - 1);

        memcpy(&prev_f, UI_font, sizeof(stFontAttribute));
        UI_set_font(&UI_DEFAULT_FONT);
        for (iCnt = (U8) mmi_ucs2strlen((PS8) gWLANProviderName); iCnt > 0; iCnt--)
        {
            Get_StringWidthHeight((U8*) gWLANProviderName, &StringWidth, &StringHeight);
            /* Add one pixel for border text */
            if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
            {
                gWLANProviderName[iCnt * ENCODING_LENGTH] = 0x0;
                gWLANProviderName[iCnt * ENCODING_LENGTH + 1] = 0x0;
            }
            else
            {
                break;
            }
        }
        UI_set_font(&prev_f);

    #ifdef __MMI_POC__
        mmi_poc_poweron_reg_wifi(); /* PoC auto login on WLAN */
    #endif
    }

    if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
    {
        IdleRefreshServiceIndicationArea();
        idle_screen_show_network_details(); /* EntryIdleScreen(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_init_wlan_setting
 * DESCRIPTION
 *  Initialize WLAN settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_init_wlan_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8 *) gWLANProviderName, (S8 *) "WLAN OFF");

    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        mmi_wlan_add_event_notify_hdlr(mmi_netset_register_wlan_stauts_cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_enter_wlan_flight_mode
 * DESCRIPTION
 *  Enter WLAN flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_enter_wlan_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Preferred mode: turn off WLAN @@@@@");
    mmi_wlan_reset_hw_off(mmi_netset_switch_preferred_mode);
    g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_exit_wlan_flight_mode
 * DESCRIPTION
 *  Exit WLAN flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_exit_wlan_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Preferred mode: turn on WLAN @@@@@");
    mmi_wlan_reset_hw_on(mmi_netset_switch_preferred_mode);
    g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_preferred_mode_menu
 * DESCRIPTION
 *  Dial mode selection menu update function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_update_preferred_mode_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_GSM_ONLY:
            mmi_frm_hide_menu_item(MENU_ID_WLAN_MAIN);
        #ifdef __MMI_VOIP__
            mmi_frm_hide_menu_item(MENU_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE);
//          mmi_frm_hide_menu_item(MENU_ID_VOIP_MAIN);
        #endif /* __MMI_VOIP__ */
            if (mmi_bootup_is_sim_valid())
            {
                mmi_frm_unhide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
                mmi_frm_unhide_menu_item(MENU_CHATAPP_ID);               /* Chat */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
                mmi_frm_unhide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

                mmi_frm_unhide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */

                mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_MAIN);
                mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_SETTING);
                mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
                mmi_frm_unhide_menu_item(MENU9189_GPRS_CONNECTION_MODE);

                mmi_frm_unhide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);
                
                {
                    U8 *guiBuffer;
                    list_menu_category_history *listBuffer;

                    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_MAIN);
                    listBuffer = (list_menu_category_history *)guiBuffer;

                    if (listBuffer != NULL)
                        listBuffer->highlighted_item = GetChildMenuIDIndexByParentMenuID(MENU9185_NETWORK_SETUP, MENU_ID_NETSET_PREFERRED_MODE);
                }
            }
            else
            {
                mmi_frm_hide_menu_item(MENU_IDLE_SCR_DISP);
            #ifdef __MMI_VRSD__
                mmi_frm_hide_menu_item(MENU_ID_VRSD_APP);
            #endif
            #ifdef __MMI_VRSI__
                mmi_frm_hide_menu_item(MENU_ID_VRSI_SETTING);
            #endif
            }
            break;

        case P_WLAN_ONLY:
            mmi_frm_unhide_menu_item(MENU_ID_WLAN_MAIN);
        #ifdef __MMI_VOIP__
            mmi_frm_hide_menu_item(MENU_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE);
//          mmi_frm_unhide_menu_item(MENU_ID_VOIP_MAIN);
        #endif /* __MMI_VOIP__ */
            if (mmi_bootup_is_sim_valid())
            {
                mmi_frm_hide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
                mmi_frm_hide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
                mmi_frm_hide_menu_item(MENU_CHATAPP_ID);               /* Chat */
                mmi_frm_hide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
                mmi_frm_hide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
                mmi_frm_hide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

                mmi_frm_hide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
                mmi_frm_hide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
                mmi_frm_hide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
                mmi_frm_hide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */

                mmi_frm_hide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_MAIN);
                mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_SETTING);
                mmi_frm_hide_menu_item(MENU9186_SELECTION_MODE);
                mmi_frm_hide_menu_item(MENU9189_GPRS_CONNECTION_MODE);

                mmi_frm_hide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_IDLE_SCR_DISP);
            #ifdef __MMI_VRSD__
                mmi_frm_unhide_menu_item(MENU_ID_VRSD_APP);
            #endif
            #ifdef __MMI_VRSI__
                mmi_frm_unhide_menu_item(MENU_ID_VRSI_SETTING);
            #endif
            }
            break;

        default:
            mmi_frm_unhide_menu_item(MENU_ID_WLAN_MAIN);
        #ifdef __MMI_VOIP__
            mmi_frm_unhide_menu_item(MENU_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE);
//          mmi_frm_unhide_menu_item(MENU_ID_VOIP_MAIN);
        #endif /* __MMI_VOIP__ */
            if (mmi_bootup_is_sim_valid())
            {
                mmi_frm_unhide_menu_item(MESSAGES_MENU_SMS_MENUID);      /* SMS */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_MMS_MENUID);      /* MMS */
                mmi_frm_unhide_menu_item(MENU_CHATAPP_ID);               /* Chat */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_VMAIL_MENUID);    /* Voice Mail */
                mmi_frm_unhide_menu_item(MESSAGES_MENU_CB_MENUID);       /* Cell Broadcast */
                mmi_frm_unhide_menu_item(MENU_ID_UM_MAIN);               /* Unified Message */

                mmi_frm_unhide_menu_item(MENU_CALL_TIME_SETUP);          /* Call Time */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_CALLCOST);    /* Call Cost */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_SMSCOUNTER);  /* SMS Counter */
                mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_GPRSCOUNTER); /* GPRS Counter */

                mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_MAIN);
                mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_SETTING);
                mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
                mmi_frm_unhide_menu_item(MENU9189_GPRS_CONNECTION_MODE);

                mmi_frm_hide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);
                
                {
                    U8 *guiBuffer;
                    list_menu_category_history *listBuffer;
                    
                    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_MAIN);
                    listBuffer = (list_menu_category_history *)guiBuffer;
                    
                    if (listBuffer != NULL)
                        listBuffer->highlighted_item = GetChildMenuIDIndexByParentMenuID(MENU9185_NETWORK_SETUP, MENU_ID_NETSET_PREFERRED_MODE);
                }
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_IDLE_SCR_DISP);
            #ifdef __MMI_VRSD__
                mmi_frm_unhide_menu_item(MENU_ID_VRSD_APP);
            #endif
            #ifdef __MMI_VRSI__
                mmi_frm_unhide_menu_item(MENU_ID_VRSI_SETTING);
            #endif
            }
            break;
    }
}


#ifdef __MMI_VOIP__
#ifndef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_dial_by_gsm
 * DESCRIPTION
 *  Highlight handler for 'Dial by GSM'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_dialer_option_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(mmi_netset_entry_dialpad_call_by_wlan, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(mmi_netset_entry_dial_mode_selection, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* register call function */
            if (mmi_bootup_is_sim_valid())
            {
                mmi_netset_register_call_entry_func(IdleDialPadCall, mmi_netset_entry_dialpad_call_by_wlan);
            }
            else
            {
                mmi_netset_register_call_entry_func(EntryScrEmergencyCallDialing, mmi_netset_entry_dialpad_call_by_wlan);
            }
            break;

       case P_GSM_ONLY:
       default:
           MMI_ASSERT(0); /* shall not enter this in GSM only mode */
           break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_phonebook_save
 * DESCRIPTION
 *  Highlight handler for 'Save to Phonebook'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_dialer_option_phonebook_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change left and right soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* set left and right soft key handler */
    SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set key handler for left and right arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_dialer_option_input_method
 * DESCRIPTION
 *  Highlight handler for 'Input Method'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_dialer_option_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_voip_go_back_2_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_change_dial_mode
 * DESCRIPTION
 *  Highlight handler for 'Change Dial Mode'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_dialer_option_change_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change left and right soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* set left and right soft key handler */
    SetLeftSoftkeyFunction(mmi_netset_entry_change_dial_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set key handler for left and right arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_dialpad_call_by_wlan
 * DESCRIPTION
 *  WLAN make call from dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_dialpad_call_by_wlan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_DIAL_SCREEN__
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
#else 
    if (!SSCStringParsing2())
#endif 
        mmi_voip_app_make_call((U8*) g_idle_context.DialPadCallBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_change_dial_mode
 * DESCRIPTION
 *  Dial mode change entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_change_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.DigitScreenDialMode = (gNetworkSetupDisplay.DigitScreenDialMode) ? 0 : 1; /* 0: GSM, 1: WLAN */

    sprintf(g_idle_context.DialPadCallBuffer, "");
    g_idle_context.IdleScreenDigitKeyCode = -1;

    IdleScreenDigitHandler();

    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);

    if (mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED || mmi_netset_get_dial_mode() == 0)
    {
        /* enter VoIP dialer screen first then change dialer mode to digit dialer */
        /* restore RSK/LSK handers because they are changed to disable long press */
        SetLeftSoftkeyFunction(mmi_netset_enter_wlan_dialer_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_dial_mode
 * DESCRIPTION
 *  Get dial mode
 * PARAMETERS
 *  mode               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_set_dial_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.DigitScreenDialMode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_dial_mode
 * DESCRIPTION
 *  Get dial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_netset_get_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gNetworkSetupDisplay.DigitScreenDialMode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_enter_wlan_dialer_option
 * DESCRIPTION
 *  WLAN dialer option screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_enter_wlan_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U16 nStrItemList[4];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */

    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(IDLE_SCREEN_DIGIT_OPTIONS_ID, NULL, mmi_netset_enter_wlan_dialer_option, NULL);
    guiBuffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_OPTIONS_ID);

    nNumofItem = GetNumOfChild_Ext(MENU_ID_DIALER_SCREEN_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_DIALER_SCREEN_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_DIALER_SCREEN_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* reset the guiBuffer to enable long press after go back to the digit dialer screen */
    if (GetHistoryScrID(IDLE_SCREEN_DIGIT_HANDLER_ID, &History) == ST_SUCCESS)
    {
        if (History->guiBuffer != NULL)
        {
            OslMfree(History->guiBuffer);
            History->guiBuffer = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_register_call_entry_func
 * DESCRIPTION
 *  Dial mode selection callback function for dialing
 * PARAMETERS
 *  gsm_call_ptr       [IN]
 *  wlan_call_ptr      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_register_call_entry_func(FuncPtr gsm_call_ptr, FuncPtr wlan_call_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.GSMCallEntryPtr = gsm_call_ptr;
    gNetworkSetupDisplay.WLANCallEntryPtr = wlan_call_ptr;

    gNetworkSetupDisplay.DialModeCurrentIndex = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_check_gsm_number_before_dial
 * DESCRIPTION
 *  Validation check before dial GSM call
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_netset_check_gsm_number_before_dial(PS8 strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (strNumber[pos] != '\0')
    {
        if((strNumber[pos] != '+') &&
           (strNumber[pos] != '*') &&
           (strNumber[pos] != '#') &&
           (strNumber[pos] != 'p') &&
           (strNumber[pos] != 'w') &&
           (strNumber[pos] != '0') &&
           (strNumber[pos] != '1') &&
           (strNumber[pos] != '2') &&
           (strNumber[pos] != '3') &&
           (strNumber[pos] != '4') &&
           (strNumber[pos] != '5') &&
           (strNumber[pos] != '6') &&
           (strNumber[pos] != '7') &&
           (strNumber[pos] != '8') &&
           (strNumber[pos] != '9'))
        {
            return MMI_FALSE;
        }
        pos += 2;
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_confirm_dial_mode_selection
 * DESCRIPTION
 *  Dial mode selection confirmation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_confirm_dial_mode_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL); /* to delete dial mode selection screen */

    switch (gNetworkSetupDisplay.DialModeCurrentIndex)
    {
        case 0:
            if (gNetworkSetupDisplay.GSMCallEntryPtr != NULL)
            {
                if (mmi_netset_check_gsm_number_before_dial(g_idle_context.DialPadCallBuffer))
                {
                    (*gNetworkSetupDisplay.GSMCallEntryPtr) ();
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                }
            }
            break;

        case 1:
            if (gNetworkSetupDisplay.WLANCallEntryPtr != NULL)
            {
                (*gNetworkSetupDisplay.WLANCallEntryPtr) ();
            }
            break;

        default:
            break;
    }

    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID);
    DeleteScreenIfPresent(SCR_ID_NETSET_DIAL_MODE_SELECTION);

    if (gNetworkSetupDisplay.DialModeCurrentIndex == 0)
    {
        /* Delete dialer screen in GSM call */
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);
    }

    if (gNetworkSetupDisplay.DialModeCurrentIndex == 1 && mmi_voip_app_get_register_state() == MMI_VOIP_REG_STATE)
    {
        /* Delete dialer screen in VoIP call */
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_dial_mode_selection
 * DESCRIPTION
 *  Dial mode selection highlight handler
 * PARAMETERS
 *  index              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_dial_mode_selection_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.DialModeCurrentIndex = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_dial_mode_selection
 * DESCRIPTION
 *  Dial mode selection entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_dial_mode_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 2;
    U8 *guiBuffer;
    U16 nStrItemList[] = {STR_ID_DIALER_SCREEN_OPTIONS_GSM_DIAL, STR_ID_DIALER_SCREEN_OPTIONS_WLAN_DIAL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_DIAL_MODE_SELECTION, NULL, mmi_netset_entry_dial_mode_selection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_DIAL_MODE_SELECTION);
    RegisterHighlightHandler(mmi_netset_dial_mode_selection_highlight_hdlr);
    ShowCategory15Screen(
        STR_ID_NETSET_PREFERRED_MODE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
       (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_netset_confirm_dial_mode_selection, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_UCM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_enter_wlan_dialer_screen
 * DESCRIPTION
 *  WLAN dialer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_enter_wlan_dialer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    extern S16 MMI_prefered_input_type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_CALL_EDITOR, NULL, mmi_netset_enter_wlan_dialer_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_CALL_EDITOR);

    ShowCategory404Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_VOIP_CALL_EDITOR,
        (U8*) g_idle_context.DialPadCallBuffer,
        VOIP_URI_LEN, //MAX_DIAL_PAD,
        guiBuffer);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_UCM__
    SetLeftSoftkeyFunction(mmi_idle_entry_dial_pad_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_idle_entry_dial_voip_call, KEY_SEND, KEY_EVENT_DOWN);
#else
    SetLeftSoftkeyFunction(mmi_netset_enter_wlan_dialer_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_entry_dialpad_call_by_wlan, KEY_SEND, KEY_EVENT_DOWN);
#endif

#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    if (MMI_prefered_input_type == INPUT_TYPE_NUMERIC_CHANGEABLE &&
        g_idle_context.IdleScreenDigitKeyCode >= 0 &&
        g_idle_context.IdleScreenDigitKeyCode != KEY_STAR &&
        g_idle_context.IdleScreenDigitKeyCode != KEY_POUND)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
        g_idle_context.IdleScreenDigitKeyCode = -1;
    }
#endif /* defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
}


#endif /* __MMI_VOIP__ */

#endif /* __MMI_WLAN_FEATURES__ */

