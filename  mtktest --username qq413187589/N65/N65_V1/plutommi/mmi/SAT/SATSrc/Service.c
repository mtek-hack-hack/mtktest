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
 * Service.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#include "SATDefs.h"
#include "SATStruct.h"
#include "SATGProts.h"
#include "DataAccountGProt.h"
#include "InfoNum.h"
#include "CommonScreens.h"
#include "WapProt.h"
#include "WapType.h"
#include "ServiceDefs.h"
#include "Service.h"
#include "SettingProfile.h"

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif /* __MMI_POC__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_resource.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern void goto_mobile_suite_screen(void);

#ifdef __SAT__
extern SATSETUPMENU gSATMainMenu;
#endif


/*****************************************************************************
 * FUNCTION
 *  GoToServicesMenu
 * DESCRIPTION
 *  Displays Services Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToServicesMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nIconItemList[MAX_SUB_MENUS];

    U8 *Strings[MAX_SUB_MENUS];
    U16 Icons[MAX_SUB_MENUS];
    U16 nNumofItem;

    U8 i = 0, j;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_Status() != MTPNP_AD_CARD1) &&
        (MTPNP_AD_Get_Status() != MTPNP_AD_CARD2) &&
        (MTPNP_AD_Get_Status() != MTPNP_AD_DUALCARD))
    {
        DisplayPopup(
            (PU8) GetString(SERVICES_NOT_PROVIDED_STRING_ID),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MAIN_MENU_SERVICES_MENUID);

    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MAIN_MENU_SERVICES_MENUID, nStrItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_SERVICES_MENUID, nIconItemList);

#ifdef __SAT__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if ((IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_CARD1) ||
        (IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD))
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (IsSATPresent())
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    {
        Strings[0] = (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId;
        Icons[0] = SAT_TITLE_IMAGE_ID;
        i++;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (IsSAT2Present() && IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD)
    {
        Strings[1] = (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId_2) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId_2;
        Icons[1] = SAT_TITLE_IMAGE_ID_2;
        i++;
    }
    else if ((IsSAT2Present() && MTPNP_AD_Get_Status() == MTPNP_AD_CARD2) ||
             (IsSAT2Present() && !IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD))
    {
        Strings[0] = (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId_2) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId_2;
        Icons[0] = SAT_TITLE_IMAGE_ID_2;
        i++;
    }
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
#endif /* __SAT__ */

    for (j = 0; j < nNumofItem; j++)
    {
        if (isInfoNumPresent == 0 && nStrItemList[j] == SERVICES_INFO_NUM_STRING_ID)
        {
            continue;
        }
        Strings[i] = (PU8) GetString(nStrItemList[j]);
        Icons[i] = nIconItemList[j];
        i++;
    }

    nNumofItem = i;

#ifdef __MMI_MERGE_SAT_TO_MAINMENU__
    if (nNumofItem == 0)
    {
        DisplayPopup((PU8) GetString(SERVICES_NOT_PROVIDED_STRING_ID), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }
    else if (nNumofItem == 1 && IsSATPresent())
    {
        GoToSATMainMenu();
        return;
    }
#endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

#ifdef __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__
    EntryNewScreen(SERVICES_MAIN_MENU_SCREEN_ID, wgui_restore_list_menu_slim_style, GoToServicesMenu, NULL);
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#else /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 
    EntryNewScreen(SERVICES_MAIN_MENU_SCREEN_ID, NULL, GoToServicesMenu, NULL);
#endif /* __MMI_SERVICE_MENU_NUMERIC_LIST_ICON__ */ 

    SetParentHandler(MAIN_MENU_SERVICES_MENUID);
    guiBuffer = GetCurrGuiBuffer(SERVICES_MAIN_MENU_SCREEN_ID);
    RegisterHighlightHandler(ServicesMenuIndex);

#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_SERVICES_MENUID);
#endif 

    ShowCategory84Screen(
        SERVICES_TITLE_STRING_ID,
        GetRootTitleIcon(MAIN_MENU_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        Strings,
        Icons,
        LIST_MENU,
        0,
        guiBuffer);

    if (nNumofItem == 0)
    {
        /* No menu item and no SAT in GSM only project */
        ChangeLeftSoftkey(0, 0);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ServicesMenuIndex
 * DESCRIPTION
 *  Hilite Handler for Services Menu
 * PARAMETERS
 *  index       [IN]        Of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void ServicesMenuIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (IsSATPresent() && IsSAT2Present() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD)
    {
        if (index == 0)
        {
            SATHiliteHandler();
        }
        else if (index == 1)
        {
            SATHiliteHandler_2();
        }
        else
        {
            ExecuteCurrHiliteHandler(index - 2);
        }
    }
    else if ((IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_CARD1) ||
             (IsSATPresent() && !IsSAT2Present() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD))
    {
        if (index == 0)
        {
            SATHiliteHandler();
        }
        else
        {
            ExecuteCurrHiliteHandler(index - 1);
        }
    }
    else if ((IsSAT2Present() && MTPNP_AD_Get_Status() == MTPNP_AD_CARD2) ||
             (IsSAT2Present() && !IsSATPresent() && MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD))
    {
        if (index == 0)
        {
            SATHiliteHandler_2();
        }
        else
        {
            ExecuteCurrHiliteHandler(index - 1);
        }
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (IsSATPresent())
    {
        if (index == 0)
        {
            SATHiliteHandler();
        }
        else
        {
            ExecuteCurrHiliteHandler(index - 1);
        }
    }
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    else
    {
        ExecuteCurrHiliteHandler(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATHiliteHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    SetLeftSoftkeyFunction(GoToSATMainMenu, KEY_EVENT_UP);
    SetKeyHandler(GoToSATMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __SAT__ */
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATHiliteHandler_2
 * DESCRIPTION
 *  Hilite Handler for SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATHiliteHandler_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    SetLeftSoftkeyFunction(GoToSATMainMenu_2, KEY_EVENT_UP);
    SetKeyHandler(GoToSATMainMenu_2, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __SAT__ */
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  WapHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for WAP Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WapHiliteHandler(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(goto_mobile_suite_screen, KEY_EVENT_UP);
    SetKeyHandler(goto_mobile_suite_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  DataConnectHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for Data Connect Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataConnectHiliteHandler(void)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EntryDTCNTMain, KEY_EVENT_UP);
    SetKeyHandler(EntryDTCNTMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __TCPIP__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  InfoNumHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for Information Number Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InfoNumHiliteHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EnterScrInfoNumber, KEY_EVENT_UP);
    SetKeyHandler(EnterScrInfoNumber, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  InitService
 * DESCRIPTION
 *  Initialises variables & Protocol Handlers for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitService(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SERVICES_WAP_MENU_ID use different highlight handler in Operator Version  */
#ifndef __MMI_OP01_MENU_9MATRIX__
#ifdef WAP_SUPPORT
    SetHiliteHandler(SERVICES_WAP_MENU_ID, WapHiliteHandler);
#endif
#endif /* __MMI_OP01_MENU_9MATRIX__ */
    SetHiliteHandler(SERVICES_INFO_NUM_MENU_ID, InfoNumHiliteHandler);

    SetHiliteHandler(SERVICES_DATA_CONNECT_MAIN_MENU_ID, DataConnectHiliteHandler);

    SetHiliteHandler(SERVICES_DATA_CONNECT_MENU_ID, DataConnectGSMHiliteHandler);

#ifdef __MMI_GPRS_FEATURES__
    SetHiliteHandler(SERVICES_DATA_CONNECT_GPRS_MENU_ID, DataConnectGPRSHiliteHandler);
#endif /* __MMI_GPRS_FEATURES__ */ 

#ifdef __MMI_POC__
    SetHiliteHandler(MENU_ID_POC_MAIN, mmi_poc_highlight_main);
#endif 

#ifdef __SAT__
    InitSimAppToolkit();
#endif

#ifdef __MMI_WLAN_FEATURES__
    mmi_wlan_init_highlight_hdlr();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  DataConnectGSMHiliteHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataConnectGSMHiliteHandler(void)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(InitializeDataAccountRecords, KEY_EVENT_UP);
    SetKeyHandler(InitializeDataAccountRecords, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __TCPIP__ */ 
}


#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  DataConnectGPRSHiliteHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DataConnectGPRSHiliteHandler(void)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(InitializeGPRSDataAccountRecords, KEY_EVENT_UP);
    SetKeyHandler(InitializeGPRSDataAccountRecords, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __TCPIP__ */ 
}

#endif /* __MMI_GPRS_FEATURES__ */ 

