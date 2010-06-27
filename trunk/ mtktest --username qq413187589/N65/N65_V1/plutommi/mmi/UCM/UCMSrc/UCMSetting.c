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
 *  UCMSetting.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template source file
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "CallHistoryMain.h"
#include "CallHistoryEnum.h"
#include "CSP.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_history
 * DESCRIPTION
 *  Funtion is called when call history menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(EntryCHISTMainMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryCHISTMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_general_call_setting
 * DESCRIPTION
 *  Funtion is called when general call setting menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_general_call_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(mmi_ucm_entry_call_general_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_ucm_entry_call_general_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_general_call_setting_more
 * DESCRIPTION
 *  Funtion is called when general call setting more menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_general_call_setting_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(mmi_ucm_entry_call_general_setting_more, KEY_EVENT_UP);
    SetKeyHandler(mmi_ucm_entry_call_general_setting_more, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_general_call_setting_sim1
 * DESCRIPTION
 *  Funtion is called when general call setting sim1 menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_general_call_setting_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(mmi_ucm_entry_call_general_setting_sim1, KEY_EVENT_UP);
    SetKeyHandler(mmi_ucm_entry_call_general_setting_sim1, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_center
 * DESCRIPTION
 *  call center screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 itemIcons[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_UCM_CALL_CENTER, NULL, mmi_ucm_entry_call_center, NULL);
    PRINT_INFORMATION("\n[mmi_ucm_entry_call_center] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UCM_CALL_CENTER);

    numItems = GetNumOfChild_Ext(MAIN_MENU_CALL_CENTER);
    GetSequenceStringIds_Ext(MAIN_MENU_CALL_CENTER, nStrItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_CALL_CENTER, itemIcons);
    SetParentHandler(MAIN_MENU_CALL_CENTER);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UCM_CALL_CENTER,
        IMG_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) itemIcons,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_general_setting
 * DESCRIPTION
 *  call setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_general_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_UCM_GENERAL_CALL_SETTING, NULL, mmi_ucm_entry_call_general_setting, NULL);
    PRINT_INFORMATION("\n[mmi_ucm_entry_call_general_setting] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UCM_GENERAL_CALL_SETTING);

    numItems = GetNumOfChild_Ext(MENU_ID_UCM_CALL_SETTING);
    GetSequenceStringIds_Ext(MENU_ID_UCM_CALL_SETTING, nStrItemList);    
    SetParentHandler(MENU_ID_UCM_CALL_SETTING);

    ConstructHintsList(MENU_ID_UCM_CALL_SETTING, popUpList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UCM_GENERAL_CALL_SETTING,
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_general_setting_more
 * DESCRIPTION
 *  call setting more screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_general_setting_more(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_UCM_GENERAL_CALL_SETTING_MORE, NULL, mmi_ucm_entry_call_general_setting_more, NULL);
    PRINT_INFORMATION("\n[mmi_ucm_entry_call_general_setting_more] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UCM_GENERAL_CALL_SETTING_MORE);

    numItems = GetNumOfChild_Ext(MENU_ID_UCM_CALL_SETTING_MORE);
    GetSequenceStringIds_Ext(MENU_ID_UCM_CALL_SETTING_MORE, nStrItemList);    
    SetParentHandler(MENU_ID_UCM_CALL_SETTING_MORE);

    ConstructHintsList(MENU_ID_UCM_CALL_SETTING_MORE, popUpList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UCM_GENERAL_CALL_SETTING,
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}    

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_general_setting_sim1
 * DESCRIPTION
 *  call setting sim1 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_general_setting_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_cphs_rearrange_call_main(SIM1);

    EntryNewScreen(SCR_ID_UCM_GENERAL_CALL_SETTING_SIM1, NULL, mmi_ucm_entry_call_general_setting_sim1, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UCM_GENERAL_CALL_SETTING_SIM1);

    numItems = GetNumOfChild_Ext(MENU_ID_UCM_CALL_SETTING_SIM1);
    GetSequenceStringIds_Ext(MENU_ID_UCM_CALL_SETTING_SIM1, nStrItemList);    
    SetParentHandler(MENU_ID_UCM_CALL_SETTING_SIM1);

    ConstructHintsList(MENU_ID_UCM_CALL_SETTING_SIM1, popUpList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STRING_MTPNP_CARD1_CALL_SETTING,
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}   
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MMI_UCM__ */

