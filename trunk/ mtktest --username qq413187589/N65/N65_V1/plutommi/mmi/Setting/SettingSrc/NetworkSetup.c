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
 * NetworkSetup.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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


#include "MMI_include.h"
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
/* micha0901 */
#include "CallManagementGprot.h"
/* micha_Man_sel */

#ifdef __MMI_ENGINEER_MODE__
#include "EngineerModeDef.h"    /* diamond, 2005/08/16 Sync band selection for engineering mode */
extern void EngineerModeSuccessRebootNotice(U16 stringId);
#endif /* __MMI_ENGINEER_MODE__ */


#ifdef __MMI_WLAN_FEATURES__
#include "FlightModeGProt.h"
#endif /* __MMI_WLAN_FEATURES__ */

#include "IdleAppProt.h"
#include "wgui_status_icons.h"

extern void RefreshNwProviderName(U8 *);

NetworkSetupContext gNetworkSetup;
NetworkSetupDisplay gNetworkSetupDisplay;
NetworkSetupMsgQueue gNetworkSetupMsgQueue;

/* micha1214, Remember to update ref_list.txt */

const U16 nBandStrList[] = 
{
#ifdef __GSM850__
    STR_ID_NETSET_BAND_850,
#endif 
#ifdef __EGSM900__
    STR_ID_NETSET_BAND_900,
#endif 
#ifdef __DCS1800__
    STR_ID_NETSET_BAND_1800,
#endif 
#ifdef __PCS1900__
    STR_ID_NETSET_BAND_1900,
#endif 
#ifdef __GSM850__
#ifdef __DCS1800__
    STR_ID_NETSET_BAND_850_1800,
#endif 
#endif /* __GSM850__ */ 
#ifdef __EGSM900__
#ifdef __DCS1800__
    STR_ID_NETSET_BAND_DUAL,
#endif 
#endif /* __EGSM900__ */ 
#ifdef __GSM850__
#ifdef __PCS1900__
    STR_ID_NETSET_BAND_850_1900,
#endif 
#endif /* __GSM850__ */ 

    //Lisen 06132005
    //#if defined(__AUTO_BAND_SWITCH__)
    STR_ID_NETSET_BAND_AUTO,
    // #endif
    0
};

const U16 nBandEnumList[] = 
{
#ifdef __GSM850__
    MMI_BAND_850,
#endif 
#ifdef __EGSM900__
    MMI_BAND_900,
#endif 
#ifdef __DCS1800__
    MMI_BAND_1800,
#endif 
#ifdef __PCS1900__
    MMI_BAND_1900,
#endif 
#ifdef __GSM850__
#ifdef __DCS1800__
    MMI_BAND_850_1800,
#endif 
#endif /* __GSM850__ */ 
#ifdef __EGSM900__
#ifdef __DCS1800__
    MMI_BAND_DUAL,
#endif 
#endif /* __EGSM900__ */ 
#ifdef __GSM850__
#ifdef __PCS1900__
    MMI_BAND_850_1900,
#endif 
#endif /* __GSM850__ */ 
    //Lisen 06132005
    //#if defined(__AUTO_BAND_SWITCH__)
    MMI_BAND_AUTO,
    // #endif

    0
};

/* micha1015 */
extern S8 gHomePLMNNum[];

/* micha1101 */
extern U8 gGPRSStatusModified;


static void mmi_netset_add_to_plmn_list(U8* plmn_id);
static void mmi_netset_remove_from_plmn_list(U8* plmn_id);
static U8 mmi_netset_find_in_plmn_list(U8* plmn_id);


/*****************************************************************************
 * FUNCTION
 *  InitNetworkSetupApp
 * DESCRIPTION
 *  Initialization function for network setup
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNetworkSetupApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU9185_NETWORK_SETUP, HighlightNETSETMain);
    SetHiliteHandler(MENU9186_SELECTION_MODE, HighlightNETSETSelectionMode);
    SetHiliteHandler(MENU9186_SELECTION_MODE_MANUAL, HighlightNETSETSelectionManual);
    SetHiliteHandler(MENU9186_SELECTION_MODE_AUTOMATIC, HighlightNETSETSelectionAuto);
    SetHiliteHandler(MENU9187_PREFERRED_NETWORKS, HighlightNETSETPreferredNetworks);
    /* diamond, 2006/05/06 remove band selection from 'network setup' menu */
    /* SetHiliteHandler(MENU9188_BAND_SELECTION, HighlightNETSETBandSelection); */

#ifdef __MMI_GPRS_FEATURES__
    SetHiliteHandler(MENU9189_GPRS_CONNECTION_MODE, HighlightNETSETGPRSConnectionMode);
    SetHintHandler(MENU9189_GPRS_CONNECTION_MODE, HintNETSETGPRSConnectionMode);
#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MANUAL_MODE_NW_SEL__
    SetHiliteHandler(MENU9186_SELECTION_MODE_CHOICE, HighlightNETSETSelectionModeChoice);
    SetHintHandler(MENU9186_SELECTION_MODE_CHOICE, HintNETSETSelectionMode);
#endif /* __MANUAL_MODE_NW_SEL__ */ 

#ifdef __MMI_WLAN_FEATURES__
    SetHiliteHandler(MENU_ID_NETSET_PREFERRED_MODE, mmi_netset_highlight_preferred_mode);
    SetHintHandler(MENU_ID_NETSET_PREFERRED_MODE, mmi_netset_hint_preferred_mode);
#ifdef __MMI_VOIP__
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_DIAL, mmi_netset_highlight_dialer_option_dial);
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_PHB_SAVE, mmi_netset_highlight_dialer_option_phonebook_save);
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_INPUT_METHOD, mmi_netset_highlight_dialer_option_input_method);
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE, mmi_netset_highlight_dialer_option_change_dial_mode);
#endif /* __MMI_VOIP__ */
#else /* __MMI_WLAN_FEATURES__ */
#ifndef __MTK_TARGET__
    SetHiliteHandler(MENU_ID_NETSET_PREFERRED_MODE, mmi_netset_highlight_menu_not_support);
#endif
#endif /* __MMI_WLAN_FEATURES__ */

    /* diamond, 2006/05/06 remove band selection from 'network setup' menu */
    /* SetHintHandler(MENU9188_BAND_SELECTION, HintNETSETBandSelection); */
    SetHintHandler(MENU9186_SELECTION_MODE, HintNETSETSelectionMode);
    InitPrefNwk();

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    SetHiliteHandler(MENU_ID_NETSET_USER_CTRL_PLMN, mmi_netset_highlight_user_ctrl_plmn);
#endif 

    gNetworkSetupDisplay.CurrSelectBand = 0;
    gNetworkSetupDisplay.CurrSelectNetwork = 0;
    /* micha_Man_sel */
    gNetworkSetupDisplay.TempCurrSelectNetwork = 0;
    gNetworkSetupDisplay.PLMNListIcons = NULL;

    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        gNetworkSetupDisplay.PLMNName[i] = NULL;
        gNetworkSetup.forbid_plmn[i] = 0;
        memset(gNetworkSetup.forbid_plmn_id[i], 0, MAX_PLMN_LEN + 1);
    }

    gNetworkSetup.BandType = 1;
    gNetworkSetup.NetworkSelectAbort = MMI_FALSE;
    gNetworkSetup.PlmnList = NULL;
#ifdef __MMI_GPRS_FEATURES__
    gNetworkSetup.GPRSConnType = L4C_ALWAYS;
#endif 
    gNetworkSetup.reg_fail_flag = 0;
    gNetworkSetupMsgQueue.Index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETMain
 * DESCRIPTION
 *  Hilite handler for network setup
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_netset_retrieve_current_modes, KEY_EVENT_UP); /* diamond, 2006/05/26 current setting */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_netset_retrieve_current_modes, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETMain
 * DESCRIPTION
 *  Entry function for network setup
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    /* micha1229 */
    U8 *guiBuffer;  /* Buffer holding history data */

    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */
    U8 *NwType[MAX_SUB_MENUS];

#if defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    U32 maskingByte = -1;
    U32 HideItemId = -1;
#endif /* defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_cphs_rearrange_network_selection_menu(SIM1);
#endif /* __MMI_DUAL_SIM_MASTER__ */ 

    EntryNewScreen(SCR_ID_NETSET_MAIN, NULL, EntryNETSETMain, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_MAIN);

#if defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    if (!is_test_sim(SIM1))
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU9185_NETWORK_SETUP, MENU9189_GPRS_CONNECTION_MODE);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }
#endif /* defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__) */

    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU9185_NETWORK_SETUP);
    GetSequenceStringIds_Ext(MENU9185_NETWORK_SETUP, nStrItemList);

    SetParentHandler(MENU9185_NETWORK_SETUP);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU9185_NETWORK_SETUP, NwType);

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#if defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    if (!is_test_sim(SIM1))
    {
        nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
    }
#endif /* defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_SINGLE_CALL__) */

    ShowCategory52Screen(
        STR_ID_NETSET_SCR9185_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NwType,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETSelectionMode
 * DESCRIPTION
 *  Hilite handler for selection mode
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETSelectionMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryNETSETSelectionMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryNETSETSelectionMode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETSelectionModeChoice
 * DESCRIPTION
 *  Hilite handler for selection mode
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETSelectionModeChoice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_NETSET_CHANGE, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryNETSETSelectionModeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(EntryNETSETSelectionModeReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETSelectionModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETSelectionModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_set_plmn_select_mode_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (mmi_nw_set_plmn_select_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_select_mode_req_struct));

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
    SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);

    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        myMsgPtr->mode = MANUAL_MODE;
    }
    else
    {
        myMsgPtr->mode = AUTOMATIC_MODE;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_PLMN_SELECT_MODE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    SetProtocolEventHandler(EntryNETSETSelectionModeRsp, PRT_NW_SET_PLMN_SELECT_MODE_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETSelectionModeRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETSelectionModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_select_mode_rsp_struct *msgRsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgRsp = (mmi_nw_set_plmn_select_mode_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_SET_PLMN_SELECT_MODE_RSP);

    if (msgRsp->result == KAL_TRUE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
        {
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_PLMNSEL_MODE;        /* 0x08: PLMN selection mode */
        }
        else
        {
            g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_PLMNSEL_MODE;       /* 0x08: PLMN selection mode */
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}

#endif /* __MANUAL_MODE_NW_SEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETSelectionMode
 * DESCRIPTION
 *  Entry function for selection mode
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETSelectionMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    /* micha1229 */
    U8 *guiBuffer;  /* Buffer holding history data */

    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    U8 *NwType[MAX_SUB_MENUS];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_nw_registration_ok() == MMI_TRUE)
    {

        EntryNewScreen(SCR_ID_NETSET_SELECTION_MODE, NULL, EntryNETSETSelectionMode, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_SELECTION_MODE);
        nNumofItem = GetNumOfChild(MENU9186_SELECTION_MODE);
        GetSequenceStringIds(MENU9186_SELECTION_MODE, nStrItemList);
        SetParentHandler(MENU9186_SELECTION_MODE);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        /* micha_Man_sel */
    #ifdef __MANUAL_MODE_NW_SEL__
        ConstructHintsList(MENU9186_SELECTION_MODE, NwType);
    #endif 

        /* micha_Man_sel */
    #ifdef __MANUAL_MODE_NW_SEL__
        ShowCategory52Screen(
            STR_ID_NETSET_SCR9186_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NwType,
            LIST_MENU,
            0,
            guiBuffer);
    #else /* __MANUAL_MODE_NW_SEL__ */ 
        ShowCategory15Screen(
            STR_ID_NETSET_SCR9186_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            LIST_MENU,
            0,
            guiBuffer);
    #endif /* __MANUAL_MODE_NW_SEL__ */ 
        SetKeyHandler(ExitNETSETSelectionMode, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
#ifdef __MMI_DUAL_SIM_MASTER__
        DisplayPopup(
            (PU8) GetString(STRING_MTPNP_NETSET_SIM1_INVALID),
            IMG_GLOBAL_UNFINISHED,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
#else   /* __MMI_DUAL_SIM_MASTER__ */
        DisplayPopup(
            (PU8) GetString(STR_SIM_INVALID_SIM_SELECT_NETWORK),
            IMG_GLOBAL_UNFINISHED,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitNETSETSelectionMode
 * DESCRIPTION
 *  Entry function for selection mode
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNETSETSelectionMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETCheckAndRestoreNetwork();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETSelectionManual
 * DESCRIPTION
 *  Hilite handler for selection mode manual
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETSelectionManual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETGetPLMNListCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETSelectionAuto
 * DESCRIPTION
 *  Hilite handler for selection mode Automatic
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETSelectionAuto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETAutoSelectNetworkCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPLMNListCheck
 * DESCRIPTION
 *  set the network selected from teh list to l4
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetPLMNListCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETMsgQueuePush(GET_PLMN_LIST, NETSETGetPLMNListReq, PRT_NW_GET_PLMN_LIST_RSP, NETSETGetPLMNListRsp);
    EntryNETSETManualSearchProgress();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPLMNListReq
 * DESCRIPTION
 *  Function to send req to l4 to get plmn list
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetPLMNListReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_GET_PLMN_LIST_REQ);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_GET_PLMN_LIST_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETManualSearchProgressDeleteHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 NETSETManualSearchProgressDeleteHandler(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETAbortPLMNListReq();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETManualSearchProgress
 * DESCRIPTION
 *  function to display progress screen for manual search
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETManualSearchProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS, NULL, EntryNETSETManualSearchProgress, NULL);

    ShowCategory66Screen(
        STR_ID_NETSET_MITEM9186,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_ID_NETSET_ABORT_LSK,
        (U8*) GetString(STR_ID_NETSET_SEARCHIN_NW),
        IMG_ID_NETSET_NW_SEARCH,
        NULL);
    SetRightSoftkeyFunction(NETSETAbortPLMNListReq, KEY_EVENT_UP);
    SetKeyHandler(AbortGetPLMNListToIdle, KEY_END, KEY_EVENT_DOWN);

    /* add delete screen callback if manual search progress screen is deleted */
    SetDelScrnIDCallbackHandler(
        SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS,
        (HistoryDelCBPtr) NETSETManualSearchProgressDeleteHandler);
}


/*****************************************************************************
 * FUNCTION
 *  AbortGetPLMNListToIdle
 * DESCRIPTION
 *  abort the get plmn list req and goes back to idle screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortGetPLMNListToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha0715 */
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_ABORT_PLMN_LIST_TO_IDLE);

    SetDelScrnIDCallbackHandler(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    if (NETSETMsgQueueCheckCurrOP() == GET_PLMN_LIST)
    {
        /* micha0726 */
        if (gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top)
        {
            NETSETMsgQueueTopMinusOne();
        }

        ClearProtocolEventHandler(PRT_NW_ABORT_PLMN_LIST_RSP);
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_NW_ABORT_PLMN_LIST_REQ;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        if (NETSETMsgQueueCheckLastOP() == GET_PLMN_LIST)
        {
            /* micha0726 */
            if (gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top)
            {
                NETSETMsgQueueTopMinusOne();
            }
        }
    }

    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPLMNListRsp
 * DESCRIPTION
 *  response handler for get plmn list req
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetPLMNListRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /* micha1015 */
    l4c_plmn_info_struct tempPLMNList;

    mmi_nw_get_plmn_list_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_get_plmn_list_rsp_struct*) info;

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_GET_PLMN_LIST_RSP);

    SetDelScrnIDCallbackHandler(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    if (gNetworkSetup.PlmnList != NULL)
    {
        OslMfree(gNetworkSetup.PlmnList);
        gNetworkSetup.PlmnList = NULL;
    }
    gNetworkSetup.PlmnList = OslMalloc(sizeof(mmi_nw_get_plmn_list_rsp_struct));
    memcpy(gNetworkSetup.PlmnList, localPtr, sizeof(mmi_nw_get_plmn_list_rsp_struct));

    /* micha1015 */
    if (memcmp(gHomePLMNNum, "46002", 5) == 0)
    {
        for (i = 0; i < gNetworkSetup.PlmnList->length; i++)
        {
            if (memcmp(gNetworkSetup.PlmnList->list[i].plmn_id, "46000", 5) == 0)
            {
                memcpy(&tempPLMNList, &(gNetworkSetup.PlmnList->list[0]), sizeof(l4c_plmn_info_struct));
                memcpy(
                    &(gNetworkSetup.PlmnList->list[0]),
                    &(gNetworkSetup.PlmnList->list[i]),
                    sizeof(l4c_plmn_info_struct));
                memcpy(&(gNetworkSetup.PlmnList->list[i]), &tempPLMNList, sizeof(l4c_plmn_info_struct));
            }
        }
    }

    if (gNetworkSetup.PlmnList->result.flag != L4C_OK || gNetworkSetup.PlmnList->length == 0 || isInCall())
    {
        if (gNetworkSetup.PlmnList != NULL)
        {
            OslMfree(gNetworkSetup.PlmnList);
            gNetworkSetup.PlmnList = NULL;
        }
        DisplayPopup((PU8) GetString(STR_ID_NETSET_NW_LIST_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS);
    }
    else
    {
        for (i = 0; i < gNetworkSetup.PlmnList->length; ++i)
        {
            if (gNetworkSetupDisplay.PLMNName[i] != NULL)
            {
                OslMfree(gNetworkSetupDisplay.PLMNName[i]);
                gNetworkSetupDisplay.PLMNName[i] = NULL;
            }
            gNetworkSetupDisplay.PLMNName[i] = OslMalloc(PLMN_NAME_LENGTH * ENCODING_LENGTH);
            memset((void*)gNetworkSetupDisplay.PLMNName[i], 0, PLMN_NAME_LENGTH * ENCODING_LENGTH);

            /* diamond, 2006/03/08 Get plmn string from PLMN list */
            mmi_netset_retrieve_opname_from_plmn(
                gNetworkSetup.PlmnList->list[i].plmn_id,
                gNetworkSetupDisplay.PLMNName[i]);

            if (mmi_netset_is_t_mobile_us_sim() == MMI_TRUE && memcmp(gNetworkSetup.PlmnList->list[i].plmn_id, "31017", 5) == 0)
            {
                mmi_ucs2cpy((PS8) gNetworkSetupDisplay.PLMNName[i], (PS8) L"T-Mobile");
            }
        }
        EntryNETSETShowPlmnList();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETShowPlmnList
 * DESCRIPTION
 *  entry function to show plmn list
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETShowPlmnList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1229 */
    U16 i;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_SHOW_PLMN_LIST);

    EntryNewScreen(SCR_ID_NETSET_SHOW_PLMN_LIST, ExitNETSETShowPLMNList, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_SHOW_PLMN_LIST);
    RegisterHighlightHandler(HiliteHandlerShowPLMNList);
    if (gNetworkSetupDisplay.PLMNListIcons != NULL)
    {
        OslMfree(gNetworkSetupDisplay.PLMNListIcons);
        gNetworkSetupDisplay.PLMNListIcons = NULL;
    }
    gNetworkSetupDisplay.PLMNListIcons = OslMalloc((gNetworkSetup.PlmnList->length * sizeof(U16)));

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

    for (i = 0; i < gNetworkSetup.PlmnList->length; i++)
    {
        /* diamond, 2006/06/05 forbidden PLMN icons */
        if (gNetworkSetup.PlmnList->list[i].status == 3)
        {
            gNetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
        }
        else
        {
            if (strcmp((PS8)gPLMN, (PS8)gNetworkSetup.PlmnList->list[i].plmn_id) == 0)
            {
                mmi_netset_remove_from_plmn_list(gNetworkSetup.PlmnList->list[i].plmn_id);
                gNetworkSetupDisplay.PLMNListIcons[i] = 0;
            }
            else if (gNetworkSetup.reg_fail_flag == 1 && gNetworkSetupDisplay.CurrSelectNetwork == i)
            {
                mmi_netset_add_to_plmn_list(gNetworkSetup.PlmnList->list[i].plmn_id);
                gNetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            else if (mmi_netset_find_in_plmn_list(gNetworkSetup.PlmnList->list[i].plmn_id) == 1)
            {
                gNetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_FORBIDDEN_PLMN;
            }
            else
            {
                gNetworkSetupDisplay.PLMNListIcons[i] = (U16) IMG_ID_NETSET_UNKNOWN_PLMN;
            }
        }

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
    #ifdef __MMI_DUAL_MODE_SELF_TEST__
/* under construction !*/
    #else /* __MMI_DUAL_MODE_SELF_TEST__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DUAL_MODE_SELF_TEST__ */ 
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
    }

    /* reset this flag after setting PLMNListIcons */
    gNetworkSetup.reg_fail_flag = 0;

    /* diamond, 2005/10/23 compare PLMN numbers instead of mapped strings because the string may be NULL if the PLMN cannot be found in the list */
    if (mmi_netset_plmn_matching_criteria((U8*) gHomePLMNNum, gNetworkSetup.PlmnList->list[0].plmn_id) ||
       ((memcmp(gHomePLMNNum, "46002", 5) == 0 && memcmp(gNetworkSetup.PlmnList->list[0]. plmn_id, "46000", 5) == 0)))
    {
        gNetworkSetupDisplay.PLMNListIcons[0] = (U16) IMG_ID_NETSET_PRF_HOME_PLMN;
    }

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 

    if (*gNetworkSetupDisplay.PLMNName[0] != '\0')
    {
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
    #else /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
        ShowCategory84Screen(
            STR_ID_NETSET_SCR_SELECT_NETWORK_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gNetworkSetup.PlmnList->length,
            gNetworkSetupDisplay.PLMNName,
            gNetworkSetupDisplay.PLMNListIcons,
            1,
            0,
            guiBuffer);
    #endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
    }
    else
    {
        ShowCategory84Screen(
            STR_ID_NETSET_SCR_SELECT_NETWORK_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            gNetworkSetupDisplay.PLMNName,
            gNetworkSetupDisplay.PLMNListIcons,
            1,
            0,
            guiBuffer);
        SetKeyHandler(0, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(0, KEY_DOWN_ARROW, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackNetSelection, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETManualSelectNetworkCheck, KEY_EVENT_UP);
    SetKeyHandler(GoBackNetSelection, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitNETSETShowPLMNList
 * DESCRIPTION
 *  exit function to show plmn list
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNETSETShowPLMNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_NETSET_SHOW_PLMN_LIST;
    currHistory.entryFuncPtr = (FuncPtr) EntryNETSETShowPlmnList;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
    if (gNetworkSetupDisplay.PLMNListIcons != NULL) /* diamond, 2006/02/13 Avoid sim access error in show plmn list screen */
    {
        OslMfree(gNetworkSetupDisplay.PLMNListIcons);
    }
    gNetworkSetupDisplay.PLMNListIcons = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GoBackNetSelection
 * DESCRIPTION
 *  clear buffers and go back to network selection
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackNetSelection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < gNetworkSetup.PlmnList->length; i++)
    {
        if (gNetworkSetupDisplay.PLMNName[i])
        {
            OslMfree(gNetworkSetupDisplay.PLMNName[i]);
            gNetworkSetupDisplay.PLMNName[i] = NULL;
        }
    }

    /* diamond, 2005/12/12 Need to check the top history then go back 1 history */
    if (GetCurrScrnId() == SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS)
    {
        GoBacknHistory(1);
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETManualSelectNetworkCheck
 * DESCRIPTION
 *  set the network selected from teh list to l4
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETManualSelectNetworkCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
    gNetworkSetupDisplay.CurrSelectNetwork = gNetworkSetupDisplay.TempCurrSelectNetwork;
    NETSETMsgQueuePush(
        NETWORK_SELECTION,
        NETSETManualSelectNetworkReq,
        PRT_NW_SET_PLMN_RSP,
        NETSETManuSelectNetworkRsp);
    EntryNETSETManualRegProgress();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETManualSelectNetworkReq
 * DESCRIPTION
 *  set the network selected from teh list to l4
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETManualSelectNetworkReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha1101 */
    gGPRSStatusModified = 1;

    myMsgPtr = (mmi_nw_set_plmn_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_req_struct));
    memset(gNWProviderName, 0, MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);
    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_SEARCHIN_NW), MAX_LENGTH_DISPLAY_NAME - 1);
    UpdateGPRSStatusIcon(L4C_NONE_GPRS);
    IdleResetStatusIcon(STATUS_ICON_ROAMING);
    myMsgPtr->opcode = MMI_MANUAL_SEL;
    memset(myMsgPtr->oper, 0, MAX_PLMN_LEN + 1);
    memcpy(
        (PS8) myMsgPtr->oper,
        (PS8) gNetworkSetup.PlmnList->list[gNetworkSetupDisplay.CurrSelectNetwork].plmn_id,
        MAX_PLMN_LEN + 1);
    strcpy(
        (PS8) gNetworkSetup.PLMNRequested,
        (PS8) gNetworkSetup.PlmnList->list[gNetworkSetupDisplay.CurrSelectNetwork].plmn_id);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif 
    gNetworkSetup.reg_fail_flag = 0;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_PLMN_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETManualRegProgress
 * DESCRIPTION
 *  entry function for progress screen in network selection from list
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETManualRegProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_MANUAL_REG_PROGRESS, NULL, EntryNETSETManualRegProgress, NULL);

    ShowCategory66Screen(
        STR_ID_NETSET_MITEM9186,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_ID_NETSET_ABORT_LSK,
        (U8*) GetString(STR_ID_NETSET_REGISTERING_NW),
        IMG_ID_NETSET_NW_SEARCH,
        NULL);
    SetRightSoftkeyFunction(AbortManualRegGoBack, KEY_EVENT_UP);
    SetKeyHandler(AbortManualRegToIdle, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  AbortManualRegGoBack
 * DESCRIPTION
 *  network setup abort and go back to network select
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortManualRegGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    GoBackToHistory(SCR_ID_NETSET_SELECTION_MODE);
    /* GoBackToHistory(SCR_ID_NETSET_SHOW_PLMN_LIST); */
}


/*****************************************************************************
 * FUNCTION
 *  AbortManualRegToIdle
 * DESCRIPTION
 *  selection mode setup abort and go back to idle screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortManualRegToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  AbortAutoSearchGoBack
 * DESCRIPTION
 *  selection mode abort and go back to selection mode
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortAutoSearchGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    if (g_pwr_context.CurrentServiceType == FULL_SERVICE && gPLMN[0] != 0)
    {
        ChangeRoamingState();
    }

    RefreshNwProviderName(gPLMN);   /* diamond, 2006/03/30 Temporarily restore gPLMN if user aborts the network search */
    GoBackToHistory(SCR_ID_NETSET_SELECTION_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  AbortAutoSearchToIdle
 * DESCRIPTION
 *  network setup abort and go back to idle screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AbortAutoSearchToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
    }
#else /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetup.NetworkSelectAbort = MMI_TRUE;
#endif /* __MANUAL_MODE_NW_SEL__ */ 
    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    if (g_pwr_context.CurrentServiceType == FULL_SERVICE && gPLMN[0] != 0)
    {
        ChangeRoamingState();
    }

    RefreshNwProviderName(gPLMN);   /* diamond, 2006/03/30 Temporarily restore gPLMN if user aborts the network search */
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETManualNetworkRestoreReq
 * DESCRIPTION
 *  network setup abort
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETManualNetworkRestoreReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_nw_set_plmn_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_req_struct));
    myMsgPtr->opcode = MMI_MANUAL_SEL;
    memset(myMsgPtr->oper, 0, MAX_PLMN_LEN + 1);
    /* micha1229 */
    memcpy((PS8) myMsgPtr->oper, (PS8) gPLMN, MAX_PLMN_LEN);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_PLMN_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  RestorePreviousNetwork
 * DESCRIPTION
 *  network setup abort
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RestorePreviousNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetup.NetworkSelectAbort = MMI_FALSE;
    if (gPLMN[0] == '\0')
    {
        NETSETMsgQueuePush(NETWORK_RESTORE, NETSETAutoNetworkSearchReq, PRT_NW_SET_PLMN_RSP, NULL);
    }
    else
    {
        NETSETMsgQueuePush(NETWORK_RESTORE, NETSETManualNetworkRestoreReq, PRT_NW_SET_PLMN_RSP, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETManuSelectNetworkRsp
 * DESCRIPTION
 *  response handler for select network
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETManuSelectNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_rsp_struct *localPtr;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_set_plmn_rsp_struct*) info;

    if (localPtr->result.flag == L4C_OK && localPtr->status == L4C_RAC_OK
        && !strcmp((PS8) gNetworkSetup.PLMNRequested, (PS8) localPtr->plmn)
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif 
        )
    {
        /* diamond, 2006/03/08 Get plmn string from the response of manually selected network */
        mmi_netset_retrieve_opname_from_plmn(localPtr->plmn, gNWProviderName);

        for (i = 0; i < gNetworkSetup.PlmnList->length; i++)
        {
            if (gNetworkSetupDisplay.PLMNName[i])
            {
                OslMfree(gNetworkSetupDisplay.PLMNName[i]);
                gNetworkSetupDisplay.PLMNName[i] = NULL;
            }
        }
        OslMfree(gNetworkSetup.PlmnList);
        gNetworkSetup.PlmnList = NULL;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PLMN_LIST);
        DeleteScreenIfPresent(SCR_ID_NETSET_MANUAL_REG_PROGRESS);
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
    #endif 
    }
    else
    {
        RefreshNwProviderName(gPLMN);   /* diamond, 2006/03/20 Restore plmn string from searching to original one */
        DisplayPopup((PU8) GetString(STD_ID_NETSET_NW_SELECT_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_MANUAL_REG_PROGRESS);

        if (localPtr->status == L4C_RAC_LIMITED_SERVICE || localPtr->status == L4C_RAC_ATTEMPT_TO_UPDATE)
        {
            gNetworkSetup.reg_fail_flag = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerShowPLMNList
 * DESCRIPTION
 *  function to update the current selected index
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHandlerShowPLMNList(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.TempCurrSelectNetwork = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAbortPLMNListReq
 * DESCRIPTION
 *  abort success req function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAbortPLMNListReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_ABORT_PLMN_LIST_REQ);

    SetDelScrnIDCallbackHandler(SCR_ID_NETSET_MANUAL_SEARCH_PROGRESS, NULL);

    if (NETSETMsgQueueCheckCurrOP() == GET_PLMN_LIST)
    {
        /* micha0726 */
        if (gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top)
        {
            NETSETMsgQueueTopMinusOne();
        }

        SetProtocolEventHandler(NETSETAbortPLMNListRsp, PRT_NW_ABORT_PLMN_LIST_RSP);
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_NW_ABORT_PLMN_LIST_REQ;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        if (NETSETMsgQueueCheckLastOP() == GET_PLMN_LIST)
        {
            /* micha0726 */
            if (gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top)
            {
                NETSETMsgQueueTopMinusOne();
            }
        }
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAbortPLMNListRsp
 * DESCRIPTION
 *  abort success response handler
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAbortPLMNListRsp(void *info)
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
 *  HighlightNETSETPreferredNetworks
 * DESCRIPTION
 *  highlite handler for preferred networks
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETPreferredNetworks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETGetPreferredNetworkReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(NETSETGetPreferredNetworkReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __MMI_ENGINEER_MODE__
/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETBandSelection
 * DESCRIPTION
 *  highlite handler for band selection menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETBandSelection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* diamond, 2005/08/16 Sync band selection for engineering mode */
    SetLeftSoftkeyFunction(NETSETGetBandSelectionReq, KEY_EVENT_UP);
    SetKeyHandler(NETSETGetBandSelectionReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETBandSelection
 * DESCRIPTION
 *  entry function for band selection menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETBandSelection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem;
    U8 *guiBuffer;
    U16 x;
    U16 *nStrItemList = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (nNumofItem = 0; nBandStrList[nNumofItem] != 0; nNumofItem++);

    nStrItemList = (U16*) OslMalloc(nNumofItem * sizeof(U16));

    for (x = 0; x < nNumofItem; x++)
    {
        nStrItemList[x] = nBandStrList[x];
    }

#ifdef __MMI_REMOVE_BAND_1900__ /* remove 1900 from main menu */
    {
        U8 i, j, count = nNumofItem;

        for (i = j = 0; i < nNumofItem; i++)
        {
            if (nStrItemList[i] != STR_ID_NETSET_BAND_1900)
            {
                nStrItemList[j] = nStrItemList[i];
                j++;
            }
            else
            {
                count--;
            }
        }
        nNumofItem = count;
    }
#endif /* __MMI_REMOVE_BAND_1900__ */ 

    EntryNewScreen(SCR_ID_NETSET_BAND_SELECTION, NULL, EntryNETSETBandSelection, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_BAND_SELECTION);
    RegisterHighlightHandler(HiliteHandlerBandSelection);
    ShowCategory11Screen(
        STR_ID_NETSET_SCR9188_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        gNetworkSetup.BandType,
        guiBuffer);
    SetLeftSoftkeyFunction(NETSETSetBandSelectionCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (nNumofItem == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (nStrItemList != NULL)
    {
        OslMfree(nStrItemList);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetBandSelectionCheck
 * DESCRIPTION
 *  function to make req for set band selection.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetBandSelectionCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETMsgQueuePush(BAND_SELECTION, NETSETSetBandSelectionReq, PRT_NW_SET_BAND_RSP, NETSETSetBandSelectionRsp);
    EntryNETSETBandSelectionProgress();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetBandSelectionReq
 * DESCRIPTION
 *  function to make req for set band selection.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetBandSelectionReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_set_preferred_band_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_SET_BAND_REQ);

    myMsgPtr =
        (mmi_nw_set_preferred_band_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_preferred_band_req_struct));
    myMsgPtr->band = (U8) nBandEnumList[gNetworkSetupDisplay.CurrSelectBand];
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_BAND_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETBandSelectionProgress
 * DESCRIPTION
 *  entry function for band selection in progress screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETBandSelectionProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_BAND_SELECTION_PROGRESS, NULL, EntryNETSETBandSelectionProgress, NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);

    ShowCategory66Screen(STR_ID_NETSET_SCR9188_CAPTION,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_ID_NETSET_SEARCHIN_NW),
        IMG_ID_NETSET_NW_SEARCH,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetBandSelectionRsp
 * DESCRIPTION
 *  response handler for set band selection req
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetBandSelectionRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_preferred_band_rsp_struct *localPtr;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_SET_BAND_RSP);

    localPtr = (mmi_nw_set_preferred_band_rsp_struct*) info;
    if (localPtr->result == MMI_TRUE)
    {
        gNetworkSetup.BandType = (U8) gNetworkSetupDisplay.CurrSelectBand;
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(nBandStrList[gNetworkSetup.BandType]));
        Category52ChangeItemDescription(2, hintData[index]);
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
    #else
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    #endif
        DeleteScreenIfPresent(SCR_ID_NETSET_BAND_SELECTION);
        DeleteScreenIfPresent(SCR_ID_NETSET_BAND_SELECTION_PROGRESS);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_NETSET_SET_BAND_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_BAND_SELECTION);
        DeleteScreenIfPresent(SCR_ID_NETSET_BAND_SELECTION_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerBandSelection
 * DESCRIPTION
 *  hightlight handler for getting curr index
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHandlerBandSelection(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gNetworkSetupDisplay.CurrSelectBand = (U8) index;
}
#endif /* __MMI_ENGINEER_MODE__ */


/*****************************************************************************
 * FUNCTION
 *  NETSETAutoSelectNetworkCheck
 * DESCRIPTION
 *  set the network selected from teh list to l4
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAutoSelectNetworkCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NETSETMsgQueuePush(NETWORK_SELECTION, NETSETAutoNetworkSearchReq, PRT_NW_SET_PLMN_RSP, NETSETAutoNetworkSearchRsp);
    EntryNETSETAutoSearchProgress();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAutoNetworkSearchReq
 * DESCRIPTION
 *  function to make req for new search
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAutoNetworkSearchReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_set_plmn_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha1101 */
    gGPRSStatusModified = 1;

    myMsgPtr = (mmi_nw_set_plmn_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_req_struct));
    memset(gNWProviderName, 0, MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);
    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_SEARCHIN_NW), MAX_LENGTH_DISPLAY_NAME - 1);
    UpdateGPRSStatusIcon(L4C_NONE_GPRS);
    IdleResetStatusIcon(STATUS_ICON_ROAMING);
    myMsgPtr->opcode = MMI_AUTO_SELECT;
    memset(myMsgPtr->oper, 0, MAX_PLMN_LEN + 1);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
#endif 
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_PLMN_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETAutoSearchProgress
 * DESCRIPTION
 *  entry function for progress screen in auto search
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETAutoSearchProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_AUTO_SEARCH_PROGRESS, NULL, EntryNETSETAutoSearchProgress, NULL);

    ShowCategory66Screen(
        STR_ID_NETSET_MITEM9186,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_ID_NETSET_ABORT_LSK,
        (U8*) GetString(STR_ID_NETSET_REGISTERING_NW),
        IMG_ID_NETSET_NW_SEARCH,
        NULL);
    SetRightSoftkeyFunction(AbortAutoSearchGoBack, KEY_EVENT_UP);
    SetKeyHandler(AbortAutoSearchToIdle, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  NETSETAutoNetworkSearchRsp
 * DESCRIPTION
 *  response handler for new network search
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAutoNetworkSearchRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_set_plmn_rsp_struct*) info;

    if ((localPtr->result.flag == L4C_OK) && (localPtr->status == L4C_RAC_OK))
    {
        /* diamond, 2006/03/08 Get plmn string from the response of automatic network search */
        mmi_netset_retrieve_opname_from_plmn(localPtr->plmn, gNWProviderName);

    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
    #endif 
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_AUTO_SEARCH_PROGRESS);
    }
    else
    {
        RefreshNwProviderName(gPLMN);   /* diamond, 2006/03/20 Restore plmn string from searching to original one */
        DisplayPopup((PU8) GetString(STD_ID_NETSET_NW_SELECT_FAIL), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_AUTO_SEARCH_PROGRESS);
    }
}


#ifdef __MMI_ENGINEER_MODE__
/*****************************************************************************
 * FUNCTION
 *  NETSETGetBandSelectionReq
 * DESCRIPTION
 *  function for making req to get band selection
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetBandSelectionReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_GET_BAND_REQ);

    SetProtocolEventHandler(NETSETGetBandSelectionRsp, PRT_NW_GET_BAND_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    /* micha1229 */
    msgStruct.oslMsgId = PRT_NW_GET_BAND_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetBandSelectionRsp
 * DESCRIPTION
 *  response handler req to get band selection
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetBandSelectionRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_band_rsp_struct *localPtr;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (nNumofItem = 0; nBandStrList[nNumofItem] != 0; nNumofItem++);

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_GET_BAND_RSP);

    localPtr = (mmi_nw_get_band_rsp_struct*) info;
    if (localPtr->result == 1)
    {
        for (gNetworkSetup.BandType = 0;
             ((localPtr->type != nBandEnumList[gNetworkSetup.BandType]) && (gNetworkSetup.BandType < nNumofItem));
             gNetworkSetup.BandType++);
    }
    else
    {
        gNetworkSetup.BandType = 1;
    }

    /* diamond, 2005/08/16 Sync band selection for engineering mode */
        EntryNETSETBandSelection();
}


/*****************************************************************************
 * FUNCTION
 *  HintNETSETBandSelection
 * DESCRIPTION
 *  hint handler for band selection
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintNETSETBandSelection(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(nBandStrList[gNetworkSetup.BandType]));
}
#endif /* __MMI_ENGINEER_MODE__ */


/*****************************************************************************
 * FUNCTION
 *  HintNETSETSelectionMode
 * DESCRIPTION
 *  hint handler for selection mode
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintNETSETSelectionMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha_Man_sel */
#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_MITEM9186_AUTOMATIC));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_MITEM9186_MANUAL));
    }

#else /* __MANUAL_MODE_NW_SEL__ */ 
    mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_MITEM9186_AUTOMATIC));
#endif /* __MANUAL_MODE_NW_SEL__ */ 
}

#ifdef __MMI_GPRS_FEATURES__


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETGPRSConnectionMode
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETGPRSConnectionMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_NETSET_CHANGE, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(NETSETSetGPRSConnModeReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintNETSETGPRSConnectionMode
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintNETSETGPRSConnectionMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (gNetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_GPRS_CONNECTION_MODE_ALWAYS));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_ID_NETSET_GPRS_CONNECTION_MODE_WHENNEEDED));
    }
}

/* micha1109 begin */

#if (0)
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
#endif /* (0) */ 


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETGPRSConnectionProgress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETGPRSConnectionProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_DUMMY_PROGRESS, NULL, EntryNETSETGPRSConnectionProgress, NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);

    ShowCategory66Screen(STR_ID_NETSET_MITEM9189,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetGPRSConnModeRspTimeoutHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void NETSETSetGPRSConnModeRspTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_NETSET_DUMMY_PROGRESS))  /* Any interrupt happens so don't display popup */
    {
        DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetGPRSConnModeRspFailure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void NETSETSetGPRSConnModeRspFailure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);

    if (gNetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        gNetworkSetup.GPRSConnType = L4C_WHEN_NEEDED;
    }
    else
    {
        gNetworkSetup.GPRSConnType = L4C_ALWAYS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetGPRSConnModeReq
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetGPRSConnModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //StopTimer(TIMER_SET_GPRS_MODE);
    //StartTimer(TIMER_SET_GPRS_MODE, SET_GPRS_MODE_DELAY, NETSETSetGPRSConnModeTimeOut);

    if (gNetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        gNetworkSetup.GPRSConnType = L4C_WHEN_NEEDED;
    }
    else
    {
        gNetworkSetup.GPRSConnType = L4C_ALWAYS;
    }
    /* DisplayPopup((PU8)GetString(STR_GLOBAL_DONE) ,IMG_GLOBAL_ACTIVATED, 1,ST_NOTIFYDURATION,SUCCESS_TONE); */

    /* diamond, 2005/08/02 Add progress screen after send */
    EntryNETSETGPRSConnectionProgress();
    NETSETSetGPRSConnModeTimeOut();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetGPRSConnModeTimeOut
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetGPRSConnModeTimeOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_set_gprs_connect_type_req_struct *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_nw_set_gprs_connect_type_req_struct*)
        OslConstructDataPtr(sizeof(mmi_nw_set_gprs_connect_type_req_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    if (gNetworkSetup.GPRSConnType == L4C_ALWAYS)
    {
        msg->type = L4C_ALWAYS;
    }
    else
    {
        msg->type = L4C_WHEN_NEEDED;
    }

    SetProtocolEventHandler(NETSETSetGPRSConnModeRsp, PRT_NW_SET_GPRS_CONNECT_TYPE_RSP);
    Message.oslMsgId = PRT_NW_SET_GPRS_CONNECT_TYPE_REQ;
    Message.oslDataPtr = (oslParaType*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETSetGPRSConnModeRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETSetGPRSConnModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* ignore the response */
    mmi_nw_set_gprs_connect_type_rsp_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmi_nw_set_gprs_connect_type_rsp_struct*) info;

    StopTimer(TIMER_SET_GPRS_MODE);

    if (local->result == MMI_TRUE)
    {
        StartTimer(TIMER_SET_GPRS_MODE, SET_GPRS_MODE_DELAY, NETSETSetGPRSConnModeRspTimeoutHdlr);
    }
    else
    {
        StartTimer(TIMER_SET_GPRS_MODE, SET_GPRS_MODE_DELAY, NETSETSetGPRSConnModeRspFailure);
    }
}

/* micha1109 end */


/*****************************************************************************
 * FUNCTION
 *  NETSETGetGPRSModeReq
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetGPRSModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    SetProtocolEventHandler(NETSETGetGPRSModeRsp, PRT_NW_GET_GPRS_CONNECT_TYPE_RSP);
    /* format the message to get band selection */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    /* micha1229 */
    msgStruct.oslMsgId = PRT_NW_GET_GPRS_CONNECT_TYPE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    /* send req to l4 to get band selection */
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetGPRSModeRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetGPRSModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_nw_get_gprs_connect_type_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_get_gprs_connect_type_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        gNetworkSetup.GPRSConnType = localPtr->type;
    }
    else
    {
        gNetworkSetup.GPRSConnType = L4C_ALWAYS;    /* else take the default values */
    }

    //EntryNETSETMain();
    mmi_netset_retrieve_current_modes();
}

#endif /* __MMI_GPRS_FEATURES__ */ 


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueIndexAddOne
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETMsgQueueIndexAddOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_IDX_ADD_ONE, gNetworkSetupMsgQueue.Index,
               gNetworkSetupMsgQueue.Top);

    ASSERT(gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top);

    if ((gNetworkSetupMsgQueue.Index + 1) < NETSETMSGQUEUESIZE)
    {
        gNetworkSetupMsgQueue.Index++;
    }
    else
    {
        gNetworkSetupMsgQueue.Index = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueTopAddOne
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETMsgQueueTopAddOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_TOP_ADD_ONE, gNetworkSetupMsgQueue.Index,
               gNetworkSetupMsgQueue.Top);

    if ((gNetworkSetupMsgQueue.Top + 1) < NETSETMSGQUEUESIZE)
    {
        gNetworkSetupMsgQueue.Top++;
    }
    else
    {
        gNetworkSetupMsgQueue.Top = 0;
    }

    ASSERT(gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueTopMinusOne
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETMsgQueueTopMinusOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_TOP_MINUS_ONE, gNetworkSetupMsgQueue.Index,
               gNetworkSetupMsgQueue.Top);

    ASSERT(gNetworkSetupMsgQueue.Index != gNetworkSetupMsgQueue.Top);
    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;

    if (gNetworkSetupMsgQueue.Top == 0)
    {
        gNetworkSetupMsgQueue.Top = NETSETMSGQUEUESIZE - 1;
    }
    else
    {
        gNetworkSetupMsgQueue.Top--;
    }

    gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueGetPreviousTop
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 NETSETMsgQueueGetPreviousTop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNetworkSetupMsgQueue.Top == 0)
    {
        return (NETSETMSGQUEUESIZE - 1);
    }
    else
    {
        return (gNetworkSetupMsgQueue.Top - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueGetPreviousIndex
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 NETSETMsgQueueGetPreviousIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNetworkSetupMsgQueue.Index == 0)
    {
        return (NETSETMSGQUEUESIZE - 1);
    }
    else
    {
        return (gNetworkSetupMsgQueue.Index - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueProtocolHandler
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETMsgQueueProtocolHandler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_PROT_HDLR, gNetworkSetupMsgQueue.Index, gNetworkSetupMsgQueue.Top);
    /* micha0720 */
    if (gNetworkSetupMsgQueue.Index == gNetworkSetupMsgQueue.Top)
    {
        return;
    }

    NETSETMsgQueueIndexAddOne();
    if (gNetworkSetupMsgQueue.Index == gNetworkSetupMsgQueue.Top)
    {
        if (gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousIndex()].CallBackRspHandler != NULL)
        {
            (*gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousIndex()].CallBackRspHandler) (info);
        }
    }
    else
    {
        (*gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Index].CallBackFunc) ();
        SetProtocolEventHandler(
            NETSETMsgQueueProtocolHandler,
            gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Index].MsgID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueuePush
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  ItemType                [IN]        
 *  CallBackFunc            [IN]        
 *  MsgID                   [IN]        
 *  CallBackRspHandler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETMsgQueuePush(U8 ItemType, FuncPtr CallBackFunc, U16 MsgID, PsFuncPtr CallBackRspHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNetworkSetupMsgQueue.Index == gNetworkSetupMsgQueue.Top)
    {
        (*CallBackFunc) ();
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].ItemType = ItemType;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].MsgID = MsgID;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETMsgQueueTopAddOne();
        SetProtocolEventHandler(NETSETMsgQueueProtocolHandler, MsgID);
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_PUSH_EXEC, ItemType);
    }
    else if (NETSETMsgQueueGetPreviousTop() == gNetworkSetupMsgQueue.Index)
    {
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].ItemType = ItemType;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].MsgID = MsgID;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETMsgQueueTopAddOne();
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_PUSH_ONLY_ONE_ADD, ItemType);
    }
    /* micha0715 */
    else if (gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].ItemType == NETWORK_RESTORE
             && ((ItemType == GET_PLMN_LIST) || (ItemType == BAND_SELECTION)))
    {
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].ItemType = ItemType;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackFunc = CallBackFunc;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].MsgID = MsgID;
        gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Top].CallBackRspHandler = CallBackRspHandler;
        NETSETMsgQueueTopAddOne();
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_PUSH_ADD_RESTORE, ItemType);
    }
    else
    {
        gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].ItemType = ItemType;
        gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackFunc = CallBackFunc;
        gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].MsgID = MsgID;
        gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].CallBackRspHandler = CallBackRspHandler;
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_NETSET_MSG_Q_PUSH_REPLACE_LAST, ItemType);
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueCheckCurrOP
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 NETSETMsgQueueCheckCurrOP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gNetworkSetupMsgQueue.Queue[gNetworkSetupMsgQueue.Index].ItemType);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETMsgQueueCheckLastOP
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 NETSETMsgQueueCheckLastOP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gNetworkSetupMsgQueue.Queue[NETSETMsgQueueGetPreviousTop()].ItemType);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETCheckAndRestoreNetwork
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* micha0901 */
void NETSETCheckAndRestoreNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gNetworkSetup.NetworkSelectAbort == MMI_TRUE)
    {
        RestorePreviousNetwork();
        gNetworkSetup.NetworkSelectAbort = MMI_FALSE;
    }
}


#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_menu_not_support
 * DESCRIPTION
 *  Preferred mode menu is present on MoDIS but no codes for it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_menu_not_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP); 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_add_to_plmn_list
 * DESCRIPTION
 *  Add the new plmn id to plmn list
 * PARAMETERS
 *  U8*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_add_to_plmn_list(U8* plmn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((PS8)gNetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0)
        {
            return;
        }

        if (gNetworkSetup.forbid_plmn_id[i][0] == 0)
        {
            memcpy((PS8)gNetworkSetup.forbid_plmn_id[i], (PS8)plmn_id, MAX_PLMN_LEN + 1);
            gNetworkSetup.forbid_plmn[i] = 1;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_remove_from_plmn_list
 * DESCRIPTION
 *  Remove the new plmn id from plmn list
 * PARAMETERS
 *  U8*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_remove_from_plmn_list(U8* plmn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (gNetworkSetup.forbid_plmn_id[i][0] == 0)
        {
            return;
        }

        if (strcmp((PS8)gNetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0)
        {
            memset(gNetworkSetup.forbid_plmn_id[i], 0, MAX_PLMN_LEN + 1);
            gNetworkSetup.forbid_plmn[i] = 0;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_find_in_plmn_list
 * DESCRIPTION
 *  Find the new plmn id in plmn list
 * PARAMETERS
 *  U8*
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_netset_find_in_plmn_list(U8* plmn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_PLMN_LIST_LEN; i++)
    {
        if (strcmp((PS8)gNetworkSetup.forbid_plmn_id[i], (PS8)plmn_id) == 0 &&
            gNetworkSetup.forbid_plmn[i] == 1)
        {
            return 1;
        }
    }

    return 0;
}


