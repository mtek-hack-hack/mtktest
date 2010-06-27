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
 * SpeedDial.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Speed dial application
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

   FILENAME : SpeedDial.c

   PURPOSE     : Speed Dial Application 

   REMARKS     : nil

   AUTHOR      : Hariprasad, Vanita Jain

   DATE     : Dec 5,02

**************************************************************/

#include "MMI_include.h"
#ifndef _SPEEDDIAL_C
#define _SPEEDDIAL_C

/*  Include: MMI header file */
#include "ProtocolEvents.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookGprot.h"
#include "Phonebookprot.h"
#include "mainmenudef.h"
#include "CallManagementGprot.h"
#include "SettingDefs.h"
#include "SpeedDial.h"
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif/*__MMI_DUAL_SIM_MASTER__*/


/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
SpeedDialInfo speedDialTable[MAX_SPEED_DIAL_NUMBER];
static pBOOL CurrentSpeedTypeChange = FALSE;
U8 speedKeyIndex = 0, CurrentSpeedType = 0;
S16 currentKeyIndex = 0;
pBOOL readNVRAM = FALSE;

/* 
 * Global Variable
 */
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern U16 g_phb_name_index[];
extern U16 PhoneBookEntryCount;

/* 
 * Global Function
 */
extern void mmi_phb_init_build_lookup_table(void);


/*****************************************************************************
 * FUNCTION
 *  HintPhbSpeedDial
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> SpeedDial
 *  Functionality:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhbSpeedDial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhbGetSpeedDialStatus())
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhbSpeedDial
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> SpeedDial
 *  Follow functions: EntryPhbSpeedDial
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhbSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPhbSpeedDial, KEY_EVENT_UP);
    SetKeyHandler(EntryPhbSpeedDial, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhbSpeedDial
 * DESCRIPTION
 *  This function is Entry function for Phonesetup-> SpeedDial
 *  Following functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhbSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */

    U8 *SpeedDialType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_SETTING_SPEED_DIAL, ExitPhbSpeedDial, EntryPhbSpeedDial, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_SPEED_DIAL);

    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_SETTING_SPEED_DIAL);

    /* Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU9102_INITIAL_SETUP);

    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_SETTING_SPEED_DIAL, nStrItemList);

    /* Set current parent id */
    SetParentHandler(MENU_SETTING_SPEED_DIAL);

    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct the Hints List */
    ConstructHintsList(MENU_SETTING_SPEED_DIAL, SpeedDialType);

    /* Display Category1 Screen */
    ShowCategory52Screen(
        STR_MENU_SETTING_SPEED_DIAL,
        GetRootTitleIcon(MENU_SETTING_SPEED_DIAL) /* MAIN_MENU_TITLE_SETTINGS_ICON */ ,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        SpeedDialType,
        0,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhbSpeedDial
 * DESCRIPTION
 *  This function is Exit function for Phonesetup-> SpeedDial
 *  Functionality:  Save speed dial status
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhbSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Save To NVRAM if Value is Changed */
    if (CurrentSpeedTypeChange == TRUE)
    {
        WriteValue(NVRAM_SETTING_SPEED_DIAL, &CurrentSpeedType, DS_BYTE, &error);
        CurrentSpeedTypeChange = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhbSpeedDialStatus
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> SpeedDial -> Status
 *  Follow functions: EntryPhbSpeedDialStatus
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhbSpeedDialStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* If Speed Dial is On Change The LSK to OFF */
    if (CurrentSpeedType == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    /* Else Chnage it to ON */
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(EntryPhbSpeedDialStatus, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhbSpeedDialStatus
 * DESCRIPTION
 *  This function is Entry function for Phonesetup-> SpeedDial -> Enable Speed Dial
 *  Functionality: toggle on/off
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhbSpeedDialStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* If Speed Dial is On Then Turn It Off */
    if (CurrentSpeedType == 1)
    {
        CurrentSpeedType = 0;
    }
    /* Else Turn it On */
    else
    {
        CurrentSpeedType = 1;
    }

    /* Store the updated Value */
    CurrentSpeedTypeChange = TRUE;

    if (CurrentSpeedType)
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Redraw the Category Screen with Modified Values */
    RedrawCategoryFunction();
    /* Highlite Speed Dial Status Option */
    HighlightPhbSpeedDialStatus();
}


/*****************************************************************************
 * FUNCTION
 *  PhbInitSpeedDial
 * DESCRIPTION
 *  This function is to init highlight handler for speed dial
 *  Functionality:HighlightPhbSpeedDialSetNum
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbInitSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_SETTING_SPEED_DIAL, HighlightPhbSpeedDial);
    SetHiliteHandler(MITEM113_PBOOK_SPEED_DIAL, HighlightPhbSpeedDialSetNum);
    SetHiliteHandler(MENU_SETTING_SPEED_STATUS, HighlightPhbSpeedDialStatus);

    SetHintHandler(MENU_SETTING_SPEED_DIAL, HintPhbSpeedDial);
    SetHintHandler(MENU_SETTING_SPEED_STATUS, HintPhbSpeedDial);        /* SetHintHandler(MENU_SETTING_SPEED_STATUS,HintSpeedDialOn); */

    SetHiliteHandler(MENU_ID_SPEED_DIAL_OP_EDIT, HighlightPhbSpeedDialSetNumOptionEdit);
    SetHiliteHandler(MENU_ID_SPEED_DIAL_OP_DEL, HighlightPhbSpeedDialSetNumOptionDel);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhbSpeedDialSetNum
 * DESCRIPTION
 *  This function is Highlight handler for Phonebook-> Speeddial
 *  Follow functions: EntryPhbSpeedDial
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhbSpeedDialSetNum()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryPhbSpeedDialSetNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryPhbSpeedDialSetNum, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhbSpeedDialSetNum
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->IdleScreenDisplay
 *  Following functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhbSpeedDialSetNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, i;
    U8 *speedKeyName[MAX_SPEED_DIAL_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 *speedKeyNumber[MAX_SPEED_DIAL_NUMBER]; */

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        EntryNewScreen(SCR_SPEED_DIAL_LIST, wgui_restore_list_menu_slim_style, EntryPhbSpeedDialSetNum, NULL);

        for (i = 0; i < MAX_SPEED_DIAL_NUMBER; ++i)
        {
            if (mmi_ucs2strlen((PS8) speedDialTable[i].name) || mmi_ucs2strlen((PS8) speedDialTable[i].number))
            {
                if (mmi_ucs2strlen((PS8) speedDialTable[i].name))     /* An entry with name */
                {
                    speedKeyName[i] = speedDialTable[i].name;
                    if (mmi_ucs2strlen((PS8) speedDialTable[i].number))
                    {
                        subMenuDataPtrs[i] = speedDialTable[i].number;
                    }
                    else
                    {
                        subMenuDataPtrs[i] = NULL;
                    }
                }
                else    /* An entry with number only */
                {
                    speedKeyName[i] = speedDialTable[i].number;
                    subMenuDataPtrs[i] = NULL;
                }
            }
            else    /* Entry without name and number */
            {
                speedKeyName[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
                subMenuDataPtrs[i] = NULL;
            }
        }

        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

        guiBuffer = GetCurrGuiBuffer(SCR_SPEED_DIAL_LIST);
        RegisterHighlightHandler(PhbSpeedDailEntryHiliteHandler);

        ShowCategory53Screen(
            STR_SCR_SPEED_DIAL_LIST_CAPTION,
            GetRootTitleIcon(MENU_SETTING_SPEED_DIAL) /* MAIN_MENU_TITLE_SETTINGS_ICON */ ,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_SPEED_DIAL_NUMBER,
            speedKeyName,
            (U16*) (gIndexIconsImageList + 1),
            subMenuDataPtrs,
            0,
            0,
            guiBuffer);

        if (mmi_bootup_get_active_flight_mode() != 1)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_PFAL_CC_HandleSendKeys(PhbMakeCallFromSpeedDial,KEY_EVENT_UP);
        #else /* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(PhbMakeCallFromSpeedDial, KEY_SEND, KEY_EVENT_UP);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
        SetLeftSoftkeyFunction(EntryPhbSpeedDialSetNumOption, KEY_EVENT_UP);
        SetKeyHandler(EntryPhbSpeedDialSetNumOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}

/* MTK 20041011 Wilson, Add operation menu for speed dial */


/*****************************************************************************
 * FUNCTION
 *  HighlightPhbSpeedDialSetNumOptionEdit
 * DESCRIPTION
 *  This function is Highlight handler for Speeddial->Edit
 *  Follow functions: EntryPhbSpeedDial
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhbSpeedDialSetNumOptionEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_speed_dial_enter_phb, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_speed_dial_enter_phb, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhbSpeedDialSetNumOptionDel
 * DESCRIPTION
 *  This function is Highlight handler for Speeddial->Delete
 *  Follow functions: EntryPhbSpeedDial
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhbSpeedDialSetNumOptionDel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryPhbSpeedDialSetNumDelConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhbSpeedDialSetNumOption
 * DESCRIPTION
 *  This function is Entry function for Speed Dial Operation
 *  Following functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhbSpeedDialSetNumOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[3];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SPEED_DIAL_SET_NUM_OPTION, NULL, EntryPhbSpeedDialSetNumOption, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SPEED_DIAL_SET_NUM_OPTION);

    nNumofItem = GetNumOfChild(MENU_ID_SPEED_DIAL_OPERATION);
    GetSequenceStringIds(MENU_ID_SPEED_DIAL_OPERATION, nStrItemList);
    SetParentHandler(MENU_ID_SPEED_DIAL_OPERATION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Record Empty - Remove Delete Operation */
    if (!mmi_ucs2strlen((S8*) speedDialTable[currentKeyIndex].name) &&
        !mmi_ucs2strlen((S8*) speedDialTable[currentKeyIndex].number))
    {
        nNumofItem--;
    }

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_SETTING_SPEED_DIAL),
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
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhbSpeedDialSetNumDelConfirm
 * DESCRIPTION
 *  Delete confirmation screen.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhbSpeedDialSetNumDelConfirm(void)
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
        get_string(STR_DELETE_QUERY_MSG),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(PhbDelSpeedDialFromList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

/* END MTK 20041011 Wilson */


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialInfo
 * DESCRIPTION
 *  Start a timer to read speeddial from NVRAM after enter idle screen.
 *  (Avoid timeout callback to read NVRAM before enter idle screen.)
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbGetSpeedDialInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_READ_SPEED_DIAL_TIMER);
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((mmi_bootup_is_sim_valid() == FALSE) && (mmi_bootup_is_sim2_valid() == FALSE))
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid() == FALSE)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        g_phb_cntx.phb_ready = TRUE;
        mmi_phb_init_build_lookup_table();
        return;
    }

    if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
    {
        /* Start a timer to avoid extensive NVRAM access which may cause MMI hang shortly */
        StartTimer(PHB_READ_SPEED_DIAL_TIMER, 500, PhbGetSpeedDialInfo_Ext);
    }
    else
    {
        /* Retry again until enter idle screen. */
        StartTimer(PHB_READ_SPEED_DIAL_TIMER, 500, PhbGetSpeedDialInfo);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialInfo_Ext
 * DESCRIPTION
 *  This function is to get the first non-empty speed dial entry and send query to L4
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbGetSpeedDialInfo_Ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S16 error; */
    PhbReadSpeedDialNVRAM();
    for (speedKeyIndex = 0; speedKeyIndex < MAX_SPEED_DIAL_NUMBER; speedKeyIndex++)
    {
        if (speedDialTable[speedKeyIndex].record_index != 0)
        {
            U16 store_index;

            if (speedDialTable[speedKeyIndex].storage == MMI_SIM)
            {
                store_index = speedDialTable[speedKeyIndex].record_index + MAX_PB_PHONE_ENTRIES - 1;
            }
            else
            {
                store_index = speedDialTable[speedKeyIndex].record_index - 1;
            }
            PhbSetSpeedDialPhbIndex(store_index);
        }
    }
    g_phb_cntx.phb_ready = TRUE;
    mmi_phb_init_build_lookup_table();
}


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialPhbIndexReq
 * DESCRIPTION
 *  Gets the Phonebook entry from L4 based on index,
 *  storage & type
 *  
 *  Used by speed dial
 * PARAMETERS
 *  storage     [IN]        
 *  rIndex      [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhbGetSpeedDialPhbIndexReq(U8 storage, U16 rIndex, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If FDN in On, Don't Query Sim Entry */
    if (gSecuritySetupContext.FdlStatus && (storage == MMI_SIM))
    {
        PhbSetSpeedDialPhbIndex(0xffff);
    }
    else
    {

        MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *myMsgPtr;
        MYQUEUE Message;

        PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<PhbGetSpeedDialPhbIndexReq.>\n", __FILE__,
                             __LINE__);

        myMsgPtr =
            (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*)
            OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
        myMsgPtr->index = 0xFFFF;
        myMsgPtr->record_index = rIndex;
        myMsgPtr->storage = storage;
        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;

        SetProtocolEventHandler(PhbGetSpeedDialPhbIndexRsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
        OslMsgSendExtQueue(&Message);

    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialPhbIndexRsp
 * DESCRIPTION
 *  Response handler for PhbGetSpeedDialPhbIndexReq()
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PhbGetSpeedDialPhbIndexRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<PhbGetSpeedDialPhbIndexRsp.>\n", __FILE__,
                         __LINE__);
    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        if (localPtr->no_list)
        {
            if (localPtr->list[0].storage == MMI_SIM)
            {
                store_index = localPtr->list[0].record_index + MAX_PB_PHONE_ENTRIES - 1;
            }
            else
            {
                store_index = localPtr->list[0].record_index - 1;
            }
            PhbSetSpeedDialPhbIndex(store_index);
        }
        else
        {
            PhbSetSpeedDialPhbIndex(0xffff);
        }
    }
    else
    {
        PhbSetSpeedDialPhbIndex(0xffff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbSetSpeedDialPhbIndex
 * DESCRIPTION
 *  This function is to continue get speed dial entry and send query to L4
 *  Functionality:
 * PARAMETERS
 *  store_index     [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbSetSpeedDialPhbIndex(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index != 0xffff)
    {
        U16 pos;
        for (pos = 0; pos < PhoneBookEntryCount; pos++)
        {
            if (g_phb_name_index[pos] == store_index)
            {
                mmi_ucs2cpy((PS8) speedDialTable[speedKeyIndex].name, (PS8) PhoneBook[store_index].alpha_id.name);
                mmi_phb_convert_get_ucs2_number((S8*) speedDialTable[speedKeyIndex].number, store_index);
                break;
            }
        }
    }
    else if (!(gSecuritySetupContext.FdlStatus && (speedDialTable[speedKeyIndex].storage == MMI_SIM)))
    {
        memset(speedDialTable[speedKeyIndex].name, 0, ENCODING_LENGTH);
        memset(speedDialTable[speedKeyIndex].number, 0, ENCODING_LENGTH);
    }
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
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  PhbReadSpeedDialNVRAM
 * DESCRIPTION
 *  This function is to read speed dial record from nvram
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbReadSpeedDialNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  PhbSetSpeedDialFormList
 * DESCRIPTION
 *  This function is to set speed dial entry form phone book list
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbSetSpeedDialFormList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 tempNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    U16 store_index;
    U8 storage;
    U16 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_phb_name_index[g_phb_cntx.active_index_second];
    if (!(PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_NUMBER))
    {
        DisplayPopup(
            (PU8) GetString(STR_SPEEDDIAL_NO_NUM_TODIAL_TEXT),
            IMG_GLOBAL_ERROR,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }
    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        storage = MMI_NVRAM;
        record_index = store_index + 1;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (store_index >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
    {
        storage = MMI_SIM2;
        record_index = store_index - MAX_PB_PHONE_ENTRIES - MAX_PB_SIM_ENTRIES + 1;
    }
#endif
    else
    {
        storage = MMI_SIM;
        record_index = store_index - MAX_PB_PHONE_ENTRIES + 1;
    }

    /* Do not update if record is same */
    if ((speedDialTable[currentKeyIndex].storage == storage) &&
        (speedDialTable[currentKeyIndex].type == MMI_PHB_PHONEBOOK) &&
        (speedDialTable[currentKeyIndex].record_index == record_index) &&
        (mmi_ucs2cmp((PS8) speedDialTable[currentKeyIndex].name, (PS8) PhoneBook[store_index].alpha_id.name) == 0))
    {
        mmi_phb_convert_get_ucs2_number((S8*) tempNumber, store_index);

        if (mmi_ucs2cmp((PS8) speedDialTable[currentKeyIndex].number, (PS8) tempNumber) == 0)
        {
            GoBackHistory();
            return;
        }
    }

    speedDialTable[currentKeyIndex].storage = storage;
    speedDialTable[currentKeyIndex].type = MMI_PHB_PHONEBOOK;
    speedDialTable[currentKeyIndex].record_index = record_index;
    mmi_ucs2cpy((PS8) speedDialTable[currentKeyIndex].name, (PS8) PhoneBook[store_index].alpha_id.name);
    mmi_phb_convert_get_ucs2_number((S8*) speedDialTable[currentKeyIndex].number, store_index);

    WriteRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteUptoScrID(SCR_SPEED_DIAL_LIST);

}

/* Robin 0327: */

/* MTK 20041011 Wilson, Add operation menu for speed dial */


/*****************************************************************************
 * FUNCTION
 *  PhbDelSpeedDialFromList
 * DESCRIPTION
 *  This function is to remove speed dial entry
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbDelSpeedDialFromList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&speedDialTable[currentKeyIndex], 0, sizeof(SpeedDialInfo));

    WriteRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DELETED),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteUptoScrID(SCR_SPEED_DIAL_LIST);
}

/* END MTK 20041011 Wilson */


/*****************************************************************************
 * FUNCTION
 *  PhbSpeedDailEntryHiliteHandler
 * DESCRIPTION
 *  This function is Highlight handler for Phonebook->SpeedDial->Set Number
 *  Follow functions: EntryPhnsetMainMenuStyle
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbSpeedDailEntryHiliteHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentKeyIndex = (S16) index;
}


/*****************************************************************************
 * FUNCTION
 *  PhbMakeCallFromSpeedDial
 * DESCRIPTION
 *  This function is to make phone call by pressing SEND key from speed dial screen
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbMakeCallFromSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!speedDialTable[currentKeyIndex].record_index)
    {
        DisplayPopup(
            (PU8) GetString(STR_SPEEDDIAL_NO_NUM_TODIAL_TEXT),
            IMG_GLOBAL_ERROR,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }
    else
    {
        if (!mmi_ucs2strlen((PS8) speedDialTable[currentKeyIndex].number))
        {
            DisplayPopup(
                (PU8) GetString(STR_SPEEDDIAL_NO_NUM_TODIAL_TEXT),
                IMG_GLOBAL_ERROR,
                1,
                ST_NOTIFYDURATION,
                ERROR_TONE);
        }
        else
        {
            /* micha0420 */
            if (gSecuritySetupContext.FdlStatus && (speedDialTable[currentKeyIndex].storage == MMI_SIM))
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_NOT_DONE),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    ST_NOTIFYDURATION,
                    ERROR_TONE);
            }
            else
            {
                PhbSpeedDialLookupNumberFromList(currentKeyIndex);
                MakeCall((PS8) speedDialTable[currentKeyIndex].number);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialNum
 * DESCRIPTION
 *  This function is to get speed dail number by keyID (2~9) when LP digit number from idle screen
 *  Functionality:
 * PARAMETERS
 *  keyId       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
PS8 PhbGetSpeedDialNum(U16 keyId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyId < 2)
    {
        return NULL;
    }

    if (mmi_ucs2strlen((PS8) speedDialTable[keyId - 2].number))
    {
        PhbSpeedDialLookupNumberFromList((U16) (keyId - 2));
        number = (PS8) speedDialTable[keyId - 2].number;
        return number;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbUpdateSpeedDial
 * DESCRIPTION
 *  This function is an update function to modify certain speed dial entry when user change from phone book
 *  Functionality:
 * PARAMETERS
 *  storage             [IN]            
 *  record_index        [IN]            
 *  type                [IN]            
 *  name                [?]             
 *  number              [?]             
 *  a(?)                [IN/OUT]        
 *  b(?)                [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbUpdateSpeedDial(U8 storage, U16 record_index, U8 type, U8 *name, U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i, flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SPEED_DIAL_NUMBER; ++i)
    {
        if ((speedDialTable[i].storage == storage) && (speedDialTable[i].record_index == record_index))
        {
            if (name == NULL && number == NULL)
            {
                speedDialTable[i].storage = 0;
                speedDialTable[i].type = 0;
                speedDialTable[i].record_index = 0;
                memset(speedDialTable[i].name, 0, ENCODING_LENGTH);
                memset(speedDialTable[i].number, 0, ENCODING_LENGTH);
            }
            else
            {
                mmi_ucs2cpy((PS8) speedDialTable[i].name, (PS8) name);
                mmi_ucs2cpy((PS8) speedDialTable[i].number, (PS8) number);
            }
            flag = 1;
        }
    }

    if (flag)
    {
        WriteRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbDeleteAllSpeedDial
 * DESCRIPTION
 *  This function is an update function to delete all speed dial entry when delete all entry from phone book
 *  Functionality:
 * PARAMETERS
 *  storage     [IN]            
 *  type        [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhbDeleteAllSpeedDial(U8 storage, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, flag = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SPEED_DIAL_NUMBER; ++i)
    {
        if (speedDialTable[i].storage == storage)
        {
            memset(&speedDialTable[i], 0, sizeof(speedDialTable[i]));
            flag = 1;
        }
    }

    if (flag)
    {
        WriteRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhbRestoreSpeedDial
 * DESCRIPTION
 *  This function is to restore speed dail to default value (all empty)
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL PhbRestoreSpeedDial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(speedDialTable, 0, NVRAM_SPEEDDIAL_RECORD_SIZE);
    WriteRecord(NVRAM_EF_PHONEBOOK_SPEEDDIAL_LID, 1, speedDialTable, NVRAM_SPEEDDIAL_RECORD_SIZE, &error);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  PhbGetSpeedDialStatus
 * DESCRIPTION
 *  This function is to get speed dial on/off status
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL PhbGetSpeedDialStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_SPEED_DIAL, &data, DS_BYTE, &error);

    if (data == 1)
    {
        CurrentSpeedType = 1;
        return MMI_TRUE;
    }
    else
    {
        CurrentSpeedType = 0;
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  PhbSpeedDialLookupNumberFromList
 * DESCRIPTION
 *  Check if the entry exist in phonebook list, if Yes, dial out from list, do not lookup number again
 * PARAMETERS
 *  speed_index     [IN]        speed dial entry index
 * RETURNS
 *  void
 *****************************************************************************/
void PhbSpeedDialLookupNumberFromList(U16 speed_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check if the entry exist in phonebook list, if Yes, dial out from list, do not lookup number again
     */
    if (speedDialTable[speed_index].storage == MMI_SIM)
    {
        store_index = speedDialTable[speed_index].record_index + MAX_PB_PHONE_ENTRIES - 1;
    }
    else
    {
        store_index = speedDialTable[speed_index].record_index - 1;
    }

    for (i = 0; i < PhoneBookEntryCount; i++)
        if (g_phb_name_index[i] == store_index)
        {
            g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
            g_phb_cntx.active_index = i;
            break;
        }
}

#endif /* _SPEEDDIAL_C */ 

