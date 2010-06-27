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
 * CallBarring.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CallBarring.c

   PURPOSE     : Call Barring Application - call setup

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
#include "MMI_include.h"
#include "CSP.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "PhoneBookTypes.h"
#include "CallSetUp.h"
#include "CallBarrng.h"
#include "CallSetUpEnum.h"
#include "CommonScreens.h"
#include "CallmanagementIdDef.h"
#include "CallManagementGProt.h"
#include "MessagesExDcl.h"
#include "SettingDefs.h"


/*****************************************************************************
 * FUNCTION
 *  InitCallBarring
 * DESCRIPTION
 *  Initializes the call barring application
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallBarring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set hilite handlers for the individual menu items */
    SetHiliteHandler(MENU8237_SCR8093_MNGCALL_MENU_BARRING, HighlightCALLSETCallBarring);
    SetHiliteHandler(MENU_CALL_BARRING_OUTGOING, HighlightCALLSETCallBarringOutgoing);
    SetHiliteHandler(MENU_CALL_BARRING_INCOMING, HighlightCALLSETCallBarringIncoming);
    SetHiliteHandler(MENU_CALL_BARRING_CANCELALL, HighlightCALLSETCallBarringCancelAll);
    SetHiliteHandler(MENU_CALL_BARRING_CHANGEPASS, HighlightCALLSETCallBarringChangePwd);
    SetHiliteHandler(MENU_BARRING_OUTGOING_ALLCALLS, HighlightCALLSETCallBarringAllOutCalls);
    SetHiliteHandler(MENU_BARRING_OUTGOING_INTERCALL, HighlightCALLSETCallBarringAllOutInter);
    SetHiliteHandler(MENU_BARRING_OUTGOING_INTEREXCEPTHOME, HighlightCALLSETCallBarringAllOutInterExcHome);
    SetHiliteHandler(MENU_BARRING_INCOMING_ALLCALLS, HighlightCALLSETCallBarringAllInCalls);
    SetHiliteHandler(MENU_BARRING_INCOMING_ROAMING, HighlightCALLSETCallBarringAllInRoaming);
    SetHiliteHandler(MENU_BARRING_ACTIVATE, HighlightCALLSETCallBarringActive);
    SetHiliteHandler(MENU_BARRING_DEACTIVATE, HighlightCALLSETCallBarringDeactive);
    SetHiliteHandler(MENU_BARRING_QUERY, HighlightCALLSETCallBarringQuery);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarring
 * DESCRIPTION
 *  highlite handler for call barring menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left/right soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_DUAL_SIM_MASTER__
    /*set call channel*/
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringOutgoing
 * DESCRIPTION
 *  highlite handler for the call barring outgoing menu option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringOutgoing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOut, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOut, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringIncoming
 * DESCRIPTION
 *  highlight handler for call barring in case of incoming.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringIncoming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change right soft key icon and label */
    SetLeftSoftkeyFunction(EntryCALLSETBarringIn, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringIn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringCancelAll
 * DESCRIPTION
 *  highlight handler for call barring cancel all application
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringCancelAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarAction = BARRING_CANCEL_ALL;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringPass, KEY_EVENT_UP);
    /* micha0529 */
    SetKeyHandler(EntryCALLSETBarringPass, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringChangePwd
 * DESCRIPTION
 *  highlight handler for changing call barring passwd
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringChangePwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarAction = BARRING_CHANGE_PSW;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOldPass, KEY_EVENT_UP);
    /* micha0529 */
    SetKeyHandler(EntryCALLSETBarringOldPass, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringAllOutCalls
 * DESCRIPTION
 *  highlight handler for call barring all outgoing calls.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringAllOutCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarType = BARRING_OUTGOING_ALLCALLS;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringAllOutInter
 * DESCRIPTION
 *  high light handler for call barring outgoing international calls.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringAllOutInter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarType = BARRING_OUTGOING_INTERCALL;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringAllOutInterExcHome
 * DESCRIPTION
 *  highlight handler for call barring outgoing international
 *  calls except home.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringAllOutInterExcHome(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarType = BARRING_OUTGOING_INTEREXCEPTHOME;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringAllInCalls
 * DESCRIPTION
 *  highlight handler for call barring all international calls.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringAllInCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarType = BARRING_INCOMING_ALLCALLS;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringAllInRoaming
 * DESCRIPTION
 *  highlight handler for call barring incoming on roaming calls.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringAllInRoaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarType = BARRING_INCOMING_ROAMING;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringOption, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETBarringOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringActive
 * DESCRIPTION
 *  hightlight handler for call barring activate
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringActive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarAction = BARRING_ON;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringPass, KEY_EVENT_UP);
    /* micha0529 */
    SetKeyHandler(EntryCALLSETBarringPass, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringDeactive
 * DESCRIPTION
 *  hightlight handler for call barring deactivate
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringDeactive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSBarAction = BARRING_OFF;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETBarringPass, KEY_EVENT_UP);
    /* micha0529 */
    SetKeyHandler(EntryCALLSETBarringPass, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallBarringQuery
 * DESCRIPTION
 *  hightlight handler for call barring query status
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallBarringQuery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(SendBarrQuery, KEY_EVENT_UP);
    /* micha0529 */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringMain
 * DESCRIPTION
 *  entry function for call barring main menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 maskingByte=0xFF;
       U32 menuItemId=0xFFFFFFFF; */

    EntryNewScreen(SCR_ID_CALLSET_BARRING_MAIN, NULL, EntryCALLSETBarringMain, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU8237_SCR8093_MNGCALL_MENU_BARRING);      /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8237_SCR8093_MNGCALL_MENU_BARRING); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU8237_SCR8093_MNGCALL_MENU_BARRING, nStrItemList);      /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU8237_SCR8093_MNGCALL_MENU_BARRING);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

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
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /* Display Screen */
    ShowCategory15Screen(
        STR_MENU_CALL_BARRING,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register Exit handler */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringOut
 * DESCRIPTION
 *  entry function for out going call barring menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */

    EntryNewScreen(SCR_ID_CALLSET_BARRING_OUT, NULL, EntryCALLSETBarringOut, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_OUT);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_CALL_BARRING_OUTGOING); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_CALL_BARRING_OUTGOING); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_CALL_BARRING_OUTGOING, nStrItemList); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU_CALL_BARRING_OUTGOING);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

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
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /* Display Category Screen */
    ShowCategory15Screen(
        STR_BARRING_OUTGOING_CALL_CAPTION,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Register Exit handler */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringIn
 * DESCRIPTION
 *  entry function for incoimg call barring menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringIn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */

    EntryNewScreen(SCR_ID_CALLSET_BARRING_IN, NULL, EntryCALLSETBarringIn, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_IN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_CALL_BARRING_INCOMING); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8237_SCR8093_MNGCALL_MENU_BARRING); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_CALL_BARRING_INCOMING, nStrItemList); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU_CALL_BARRING_INCOMING);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /* Display Category Screen */
    ShowCategory15Screen(
        STR_MENU_BARRING_INCOMING_MAIN,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Register Exit handler */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringOption
 * DESCRIPTION
 *  entry function for call barring option menu
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_BARRING_OPTION, NULL, EntryCALLSETBarringOption, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_OPTION);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_BARRING_OPTION);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_BARRING_OPTION); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_BARRING_OPTION, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_BARRING_OPTION);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* Display Category Screen */
    ShowCategory15Screen(
        STR_MENU_BARRING_OPTION,
    #ifdef __MMI_UCM__
            GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register Exit handler */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ScrBarringPasswordaValidation
 * DESCRIPTION
 *  validating the call barring passwords
 * NA
 *  
 * PARAMETERS
 *  text        [?]         
 *  cursor      [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ScrBarringPasswordaValidation(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < BARR_SIM_PASS_LEN)
    {
        ChangeLeftSoftkey(0, 0);
        SetKeyHandler(NULL, KEY_POUND, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

        /* check the screen from which validation came */
        switch (g_callset_context.SSBarPassStep)
        {
                /* if the call barring options is selected */
            case 0:
            {
                SetLeftSoftkeyFunction(CallBarrOption, KEY_EVENT_UP);
                SetKeyHandler(CallBarrOption, KEY_POUND, KEY_EVENT_UP);
                break;
            }
                /* if the flow is from call barring new passwords screen */
            case 1:
            {
                SetLeftSoftkeyFunction(EntryCALLSETBarringNewPass, KEY_EVENT_UP);
                SetKeyHandler(EntryCALLSETBarringNewPass, KEY_POUND, KEY_EVENT_UP);
                break;
            }
                /* if the flow is from confirmation screen of call barring password screen */
            case 2:
            {
                SetLeftSoftkeyFunction(EntryCALLSETBarringCfrmPass, KEY_EVENT_UP);
                SetKeyHandler(EntryCALLSETBarringCfrmPass, KEY_POUND, KEY_EVENT_UP);
                break;
            }
                /* if the call barring options is selected */
            case 3:
            {
                SetLeftSoftkeyFunction(CallBarrOption, KEY_EVENT_UP);
                SetKeyHandler(CallBarrOption, KEY_POUND, KEY_EVENT_UP);
                break;
            }
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringPass
 * DESCRIPTION
 *  entry function for call barring passwd
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringPass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* inputBuffer; */

    EntryNewScreen(SCR_ID_CALLSET_BARRING_PASS, NULL, EntryCALLSETBarringPass, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_PASS);
    /* inputBuffer = GetCurrInputBuffer(SCR_ID_CALLSET_BARRING_PASS); */

    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSBarPassOld, 0, sizeof(g_callset_context.SSBarPassOld));
    }
    //      else
    //              mmi_ucs2cpy((S8*)g_callset_context.SSBarPassOld, ( S8*)inputBuffer);

    /* Register input validation function */
    RegisterInputBoxValidationFunction(ScrBarringPasswordaValidation);
    /* Display Category Screen */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_BARRING_PASSWORD_CAP,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (PU8) g_callset_context.SSBarPassOld,
        BARR_SIM_PASS_LEN + 1,
        NULL,
        guiBuffer);
    /* Register function with left/right softkey */
    SetLeftSoftkeyFunction(CallBarrOption, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    g_callset_context.SSBarPassStep = 0;
    /* Register Exit handler */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CallBarrOption
 * DESCRIPTION
 *  call barring options processing function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallBarrOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* menu option selected is call barring activate */
    if (g_callset_context.SSBarAction == BARRING_ON)
    {
        SendCallBarrActivate();
    }
    /* menu option selected is call barring deactivate */
    else if (g_callset_context.SSBarAction == BARRING_OFF)
    {
        SendCallBarrDeactivate();
    }
    /* menu option selected is call barring query status */
    else if (g_callset_context.SSBarAction == BARRING_QUERY)
    {
        SendBarrQuery();
    }
    /* menu option selected is call barring cancel all */
    else if (g_callset_context.SSBarAction == BARRING_CANCEL_ALL)
    {
        SendCancelAllReq();
    }
    /* menu option selected is call barring password change req */
    else if (g_callset_context.SSBarAction == BARRING_CHANGE_PSW)
    {
        SendChangePswdReq();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendCallBarrActivate
 * DESCRIPTION
 *  function to send req for call barring activate
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendCallBarrActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 input_string[(MAX_DIGITS_USSD * ENCODING_LENGTH)];
    PS8 hash_string = NULL;
    S8 string_out[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(string_out, 0, 20);
    /* format SS string for sending req to l4 */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    hash_string = (PS8) GetString(STR_HASH_VALUE);
    switch (g_callset_context.SSBarType)
    {
            /* incase of call barring all outgoing calls */
        case BARRING_OUTGOING_ALLCALLS:
            strcpy((S8*) string_out, "*33*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all outgoing international calls */
        case BARRING_OUTGOING_INTERCALL:
            strcpy((S8*) string_out, "*331*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all outgoing international calls expect home */
        case BARRING_OUTGOING_INTEREXCEPTHOME:
            strcpy((S8*) string_out, "*332*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all incoming calls */
        case BARRING_INCOMING_ALLCALLS:
            strcpy((S8*) string_out, "*35*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all incoming roaming calls */
        case BARRING_INCOMING_ROAMING:
            strcpy((S8*) string_out, "*351*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
    }
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSBarPassOld);
    mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
    /* set protocol event handler for the call barring response */
    SetProtocolEventHandler(CALLSETBarringRsp, PRT_MMI_SS_CALL_BARRING_RSP);
    /* make a corresponding ss string for call barring option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendCallBarrDeactivate
 * DESCRIPTION
 *  function to send req for call barring deactivate
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendCallBarrDeactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[(MAX_DIGITS_USSD * ENCODING_LENGTH)];
    PS8 hash_string = NULL;
    S8 string_out[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(string_out, 0, 20);
    /* format SS string for sending req to l4 */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    hash_string = (PS8) GetString(STR_HASH_VALUE);
    switch (g_callset_context.SSBarType)
    {
            /* incase of call barring all outgoing calls */
        case BARRING_OUTGOING_ALLCALLS:
            strcpy((S8*) string_out, "#33*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all outgoing international calls */
        case BARRING_OUTGOING_INTERCALL:
            strcpy((S8*) string_out, "#331*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all outgoing international calls expect home */
        case BARRING_OUTGOING_INTEREXCEPTHOME:
            strcpy((S8*) string_out, "#332*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all incoming calls */
        case BARRING_INCOMING_ALLCALLS:
            strcpy((S8*) string_out, "#35*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* incase of call barring all incoming roaming calls */
        case BARRING_INCOMING_ROAMING:
            strcpy((S8*) string_out, "#351*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
    }
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSBarPassOld);
    mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
    /* set protocol event handler for the call barring response */
    SetProtocolEventHandler(CALLSETBarringRsp, PRT_MMI_SS_CALL_BARRING_RSP);
    /* make a corresponding ss string for call barring option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendBarrQuery
 * DESCRIPTION
 *  function to send req for call barring query status.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendBarrQuery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[(MAX_DIGITS_USSD * ENCODING_LENGTH)];
    S8 string_type[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format SS string for sending req to l4 */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    memset(string_type, 0, 30);
    switch (g_callset_context.SSBarType)
    {
            /* incase of call barring all outgoing calls */
        case BARRING_OUTGOING_ALLCALLS:
            strcpy((S8*) string_type, "*#33#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
            break;
            /* incase of call barring all outgoing international calls */
        case BARRING_OUTGOING_INTERCALL:
            strcpy((S8*) string_type, "*#331#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
            break;
            /* incase of call barring all outgoing international calls expect home */
        case BARRING_OUTGOING_INTEREXCEPTHOME:
            strcpy((S8*) string_type, "*#332#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
            break;
            /* incase of call barring all incoming calls */
        case BARRING_INCOMING_ALLCALLS:
            strcpy((S8*) string_type, "*#35#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
            break;
            /* incase of call barring all incoming roaming calls */
        case BARRING_INCOMING_ROAMING:
            strcpy((S8*) string_type, "*#351#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
            break;
    }
    /* set protocol event handler for the call barring response */
    SetProtocolEventHandler(CALLSETBarringRsp, PRT_MMI_SS_CALL_BARRING_RSP);
    /* make a corresponding ss string for call barring option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETBarringRsp
 * DESCRIPTION
 *  function for handling response for call barring query req.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETBarringRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_ss_call_barring_rsp_struct *pMsgBarringRsp = (mmi_ss_call_barring_rsp_struct*) info;
    U8 bs_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);

    /* check the status of the response result */
    if (pMsgBarringRsp->result.flag == L4C_OK)
    {
        /* if the response is success check the type */
        switch (pMsgBarringRsp->type)
        {
                /* call barring all outgoing calls */
            case L4_BAOC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BAOC_A));
                break;
                /* call barring all outgoing international calls */
            case L4_BOIC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BOIC_A));
                break;
                /* call barring all outgoing international calls except home */
            case L4_BOICEXHC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BOICEXHC_A));
                break;
                /* call barring all incoming calls */
            case L4_BAIC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BAIC_A));
                break;
                /* call barring all incoming roaming calls */
            case L4_BAICROAM:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BAICROAM_A));
                break;
                /* call barring cancel all calls */
            case L4_BAC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BAC_A));
                break;
                /* call barring all outgoing calls */
            case L4_BOC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BOC_A));
                break;
                /* call barring all incoming calls */
            case L4_BIC:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_BIC_A));
                break;
            default:
                mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEFAULT_A));
                break;
        }
        /* format the result string with active/deactive tags. */
        if (pMsgBarringRsp->count == 0)
        {
            mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEACTIVATED));
        }
        for (bs_index = 0; bs_index < pMsgBarringRsp->count; bs_index++)
        {
            if ((mmi_ucs2strlen((PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                 + mmi_ucs2strlen((PS8) GetString(STR_DEACTIVATED))
                 + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer)) < MAX_DISP_UCS2 / ENCODING_LENGTH)
            {
                if (pMsgBarringRsp->list[bs_index].ss_status & SS_ABIT)
                {
                    mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_ACTIVATED));
                }
                else if (pMsgBarringRsp->list[bs_index].ss_status & SS_PBIT)
                {
                    mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEACTIVATED));
                }
                else
                {
                    mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_NOT_PROVIDED));
                }
                AppendBScodeString(pMsgBarringRsp->list[bs_index].bs_code, (PS8) g_callset_context.SSDisplayBuffer);
            }
        }
        /* call the result screen function to display the result string */
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
        /* in case of response failure */
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(pMsgBarringRsp->result.cause, (PS8) g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        /* display the not done popup */
        /* micha0616 */
        if (pMsgBarringRsp->result.cause == CM_SS_ERR_NEGATIVEPW_CHECK)
        {
            DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }
        else if (pMsgBarringRsp->result.cause == CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION)
        {
            DisplayPopup((PU8) GetString(STR_SETTING_BLOCK), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }

        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendCancelAllReq
 * DESCRIPTION
 *  function for sending req for cancel all (call barring) .
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendCancelAllReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_string[MAX_DIGITS_USSD];
    PS8 hash_string = NULL;
    U8 string_type[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format the string for the ss string handling */
    memset(input_string, 0, MAX_DIGITS_USSD);
    memset(string_type, 0, 20);
    hash_string = (PS8) GetString(STR_HASH_VALUE);
    strcpy((PS8) string_type, (PS8) "#330*");
    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
    mmi_ucs2cat((S8*) input_string, (S8*) g_callset_context.SSBarPassOld);
    mmi_ucs2cat((S8*) input_string, (S8*) hash_string);
    /* make a corresponding ss string for call fwd option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendChangePswdReq
 * DESCRIPTION
 *  function for sending req for call barring change passwd.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendChangePswdReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 input_string[MAX_DIGITS_USSD];
    U8 string_type[20];
    PS8 hash_string = NULL;
    U8 uni_string[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(uni_string, 0, 10);
    /* format the string for the ss string handling */
    memset(input_string, 0, MAX_DIGITS_USSD);
    memset(string_type, 0, 20);
    strcpy((PS8) string_type, (PS8) "*03**");
    hash_string = (PS8) GetString(STR_HASH_VALUE);
    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_type);
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSBarPassOld);
    strcpy((PS8) string_type, (PS8) "*");
    mmi_asc_to_ucs2((PS8) uni_string, (PS8) string_type);
    mmi_ucs2cat((PS8) input_string, (PS8) uni_string);
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSBarPassNew);
    mmi_ucs2cat((PS8) input_string, (PS8) uni_string);
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSBarPassCfrm);
    mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
    /* set protocol event handler for the call barring passwd change response */
    SetProtocolEventHandler(CALLSETBarringPassRsp, PRT_MMI_SS_CHANGE_PASSWORD_RSP);
    /* make a corresponding ss string for call barring passwd change response option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETBarringPassRsp
 * DESCRIPTION
 *  function for handling response for call barring change passwd req.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETBarringPassRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_call_barring_rsp_struct *pMsgBarringRsp = (mmi_ss_call_barring_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change passwd response handling */
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);

    if (pMsgBarringRsp->result.flag == 0)
    {
        mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CHANGE_PSW_SUCCESS_TEXT));
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {

        /* micha0616 */
        if (pMsgBarringRsp->result.cause == CM_SS_ERR_NEGATIVEPW_CHECK)
        {
            DisplayPopup((PU8) GetString(STR_SETTING_WRONG), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }
        else if (pMsgBarringRsp->result.cause == CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION)
        {
            DisplayPopup((PU8) GetString(STR_SETTING_BLOCK), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }

        /* micha0915 */
        RemoveSSReqScr();
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringOldPass
 * DESCRIPTION
 *  entry function for call barring old passwd screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringOldPass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.SSBarPassStep = 1;
    
    EntryNewScreen(SCR_ID_CALLSET_BARRING_OLD_PASS, NULL, EntryCALLSETBarringOldPass, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_OLD_PASS);
    /* inputBuffer = GetCurrInputBuffer(SCR_ID_CALLSET_BARRING_OLD_PASS); */
    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSBarPassOld, 0, sizeof(g_callset_context.SSBarPassOld));
    }
    /* Register input validation function */
    RegisterInputBoxValidationFunction(ScrBarringPasswordaValidation);
    /* display the corresponding screen */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_OLD_BARRINGPASS_CAP,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (PU8) g_callset_context.SSBarPassOld,
        BARR_SIM_PASS_LEN + 1,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringNewPass
 * DESCRIPTION
 *  entry function for call barring new passwd screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringNewPass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.SSBarPassStep = 2;
    
    EntryNewScreen(SCR_ID_CALLSET_BARRING_NEW_PASS, NULL, EntryCALLSETBarringNewPass, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_NEW_PASS);
    /* inputBuffer = GetCurrInputBuffer(SCR_ID_CALLSET_BARRING_NEW_PASS); */
    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSBarPassNew, 0, sizeof(g_callset_context.SSBarPassNew));
    }
    /* Register input validation function */
    RegisterInputBoxValidationFunction(ScrBarringPasswordaValidation);
    /* display the corresponding screen */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_NEW_BARRINGPASS_CAP,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (PU8) g_callset_context.SSBarPassNew,
        BARR_SIM_PASS_LEN + 1,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETBarringCfrmPass
 * DESCRIPTION
 *  entry function for call barring change passwd confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETBarringCfrmPass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.SSBarPassStep = 3;

    EntryNewScreen(SCR_ID_CALLSET_BARRING_CFRM_PASS, NULL, EntryCALLSETBarringCfrmPass, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_BARRING_CFRM_PASS);
    /* inputBuffer = GetCurrInputBuffer(SCR_ID_CALLSET_BARRING_CFRM_PASS); */
    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSBarPassCfrm, 0, sizeof(g_callset_context.SSBarPassCfrm));
    }

    /* Register input validation function */
    RegisterInputBoxValidationFunction(ScrBarringPasswordaValidation);
    /* display the corresponding screen */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_CONFIRM_BARRINGPASS_CAP,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (PU8) g_callset_context.SSBarPassCfrm,
        BARR_SIM_PASS_LEN + 1,
        NULL,
        guiBuffer);

    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

