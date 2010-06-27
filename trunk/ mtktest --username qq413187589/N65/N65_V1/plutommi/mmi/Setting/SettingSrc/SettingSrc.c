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
 * SettingSrc.c
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
/***************** Settings Application implementation *********************/

/**************************************************************

   FILENAME : setting.c

   PURPOSE     : Settings application

   REMARKS     : nil

   AUTHOR      : Vanita Jain

   DATE     : 

**************************************************************/
#include "MMI_include.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "settingstructs.h"
#include "settinggprots.h"
#include "SimDetectionGprot.h"
#include "ProtocolEvents.h"
#include "CallFixedDial.h"
#include "BarredDialList.h"
#include "SettingProfile.h"
#include "PhoneBookDef.h"
#include "CommonScreens.h"
#include "CallSetUpEnum.h"
#include "SettingProt.h"
#include "CallmanagementIdDef.h"
#include "NetworkSetupGProt.h"
#include "OrganizerGProt.h"
#include "IdleAppDef.h"
#include "PhoneSetupGprots.h"

#if defined(__MMI_PREFER_INPUT_METHOD__)
extern void HighlightInputMehtodSetting(void);
extern void SetInputMethodFromNVRAM(void);
extern void InitPreferedInputMethod(void);
#endif /* defined(__MMI_PREFER_INPUT_METHOD__) */ 

#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 

S8 gHour[MAX_LENGTH * ENCODING_LENGTH];
S8 gMinute[MAX_LENGTH * ENCODING_LENGTH];
S8 gDate[MAX_LENGTH * ENCODING_LENGTH];
S8 gMonth[MAX_LENGTH * ENCODING_LENGTH];
S8 gYear[MAX_LENGTH_YEAR * ENCODING_LENGTH];

S32 gCurrentTimeFormat = 0;
S32 gCurrentDateFormat = 0;
U8 WelcomeText[(MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH];
U8 gCurrentOnOff;

U8 ssc_disable_flag = MMI_FALSE;    /* diamond, 2005/05/13 for SSC disable */


/*****************************************************************************
 * FUNCTION
 *  InitSettingApp
 * DESCRIPTION
 *  initialise Setting application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSettingApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU9102_INITIAL_SETUP, HighlightPhnsetScr);
    SetHiliteHandler(MENU9141_TIME_AND_DATE, HighlightPhnsetTimeAndDate);
#if defined(__MMI_PREFER_INPUT_METHOD__)
    SetHiliteHandler(MENU_SETTING_PREFERED_INPUT_METHOD, HighlightInputMehtodSetting);
#endif 

    SetHiliteHandler(MENU_SETTING_RESTORE, HighlightRstScr);

    memset(WelcomeText, 0, (MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);

    InitManageCalls();
    // InitPhoneSetupApp(); /* Robin 1013: Move to InitializeAll() for text encoding */
    InitNetworkSetupApp();
    InitSecuritySetupApp();
    PhnsetInitTimeNDate();
    InitFixedDialList();
    InitBarredDialList();
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif
#ifdef __MMI_PREFER_INPUT_METHOD__
    InitPreferedInputMethod();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  GoBack2TheHistory
 * DESCRIPTION
 *  going back to history by 1 level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBack2TheHistory(void)
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
 *  EntryScrSettingMenu
 * DESCRIPTION
 *  Entry screen for settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 gInsertSimAppFlag;

void EntryScrSettingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */

    /* micha0819 */
    U16 SettingsSubmenuImageList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      U16 SettingsSubmenuImageList[] = {IMG_SETTING_CALL_SETUP, IMG_SETTING_PHONE,
    //                                                       IMG_SETTING_NETWORK, IMG_SETTING_SECURITY,
    //                                                       IMG_SETTING_STORE};

    EntryNewScreen(SCR9000_SETTINGS, NULL, EntryScrSettingMenu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR9000_SETTINGS);

    /* diamond, 2005/12/23 Phone setup in option menu */
    if (gInsertSimAppFlag != 1 && mmi_bootup_get_active_flight_mode() != 1)
    {
        /* 3. Retrieve no of child of menu item to be displayed */
        nNumofItem = GetNumOfChild_Ext(MAIN_MENU_SETTINGS_MENUID);

        /* 4. Get attribute of menu to be displayed */
        /* nDispAttribute = GetDispAttributeOfItem(MAIN_MENU_SETTINGS_MENUID); */

        /* 5. Retrieve string ids in sequence of given menu item to be displayed */
        GetSequenceStringIds_Ext(MAIN_MENU_SETTINGS_MENUID, nStrItemList);

        /* micha0819 */
        GetSequenceImageIds_Ext(MAIN_MENU_SETTINGS_MENUID, SettingsSubmenuImageList);

        /* 6 Set current parent id */
        SetParentHandler(MAIN_MENU_SETTINGS_MENUID);
    }
    else
    {
        /* 3. Retrieve no of child of menu item to be displayed */
        nNumofItem = GetNumOfChild_Ext(MAIN_MENU_SETTINGS_NO_SIM_MENUID);

        /* 4. Get attribute of menu to be displayed */
        /* nDispAttribute = GetDispAttributeOfItem(MENU_ID_PHONE_SETTING_NO_SIM); */

        /* 5. Retrieve string ids in sequence of given menu item to be displayed */
        GetSequenceStringIds_Ext(MAIN_MENU_SETTINGS_NO_SIM_MENUID, nStrItemList);

        /* micha0819 */
        GetSequenceImageIds_Ext(MAIN_MENU_SETTINGS_NO_SIM_MENUID, SettingsSubmenuImageList);

        /* 6 Set current parent id */
        SetParentHandler(MAIN_MENU_SETTINGS_NO_SIM_MENUID);

    }

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category1 Screen */

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_SETTINGS_MENUID);
#endif 
    /* MTK Leo end */
    ShowCategory15Screen(
        STR_SCR9000_SETTINGS_CAPTION,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        SettingsSubmenuImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  IsShowWelcomeScr1
 * DESCRIPTION
 *  API to return the status of Welcome Text Feature.
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
MMI_BOOL IsShowWelcomeScr1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_WELCOME_TEXT, &data, DS_BYTE, &error);

    if (data == 0)
    {
        return MMI_FALSE;
    }
    else if (data == 0xff)
    {
        data = 0;
        WriteValue(NVRAM_SETTING_WELCOME_TEXT, &data, DS_BYTE, &error);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetWelcomeText
 * DESCRIPTION
 *  API to return the Welcome Text.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the welcome text string.
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
S8 *GetWelcomeText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[(MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH];
    S16 error;
    S8 *gWelcomeText = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(data, 0, (MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);
    ReadRecord(NVRAM_EF_SETTING_LID, 1, data, MAX_SETTING_WELCOME_TEXT * ENCODING_LENGTH, &error);
    gWelcomeText = OslMalloc((MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);

    if (gWelcomeText == NULL)
    {
        return NULL;
    }
    memset(gWelcomeText, 0, (MAX_SETTING_WELCOME_TEXT + 1) * ENCODING_LENGTH);
    if (data[0] != 0xff || data[1] != 0xff)
    {
        mmi_ucs2cpy((PS8) gWelcomeText, (PS8) data);
    }
    return gWelcomeText;

}

#if defined(__MMI_APHORISM__)
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
#endif /* defined(__MMI_APHORISM__) */ 


/*****************************************************************************
 * FUNCTION
 *  InitSettingBootup
 * DESCRIPTION
 *  Initialise seetings for Bootup
 *  
 *  This fn is used till NVRAM has been read.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSettingBootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Contrast level setting at bootup */
    PhnsetMainLCDContrast(7);
    PhnsetSubLCDContrast(7);
}


/*****************************************************************************
 * FUNCTION
 *  InitSettingNVRAM
 * DESCRIPTION
 *  Initialise Settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSettingNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Contrast level set to user value */
    PhnsetRestoreToNvramContrast();
    PhnsetSetLangByNvramValue();
#if defined(__MMI_PREFER_INPUT_METHOD__)
    SetInputMethodFromNVRAM();
#endif 

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    PhnsetReadNvramCalibrationData();
#endif 

    /* diamond, 2005/05/13 for SSC disable */
    ReadValue(NVRAM_SSC_DISABLE_FLAG, &data, DS_BYTE, &error);
    if (data == 0xff)
    {
        data = 0;
        WriteValue(NVRAM_SSC_DISABLE_FLAG, &data, DS_BYTE, &error);
    }
    ssc_disable_flag = data;
    /* diamond, end */

    ReadValue(NVRAM_SETTING_STATUS_DT_TIME, &data, DS_BYTE, &error);
    if (data == 0xff)
    {
        data = 1;
        WriteValue(NVRAM_SETTING_STATUS_DT_TIME, &data, DS_BYTE, &error);
    }
    /* CurrentDtType = data; */
    PhnsetSetShowDTStatus(data);
}


/*****************************************************************************
 * FUNCTION
 *  GetSettingOptionsStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetSettingOptionsStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SECSETGetPIN1StatusReq();
    SECSETGetFdlBdlModeReq();
}

