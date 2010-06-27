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
 * IrdaMMIScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI irda service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_IRDA_SUPPORT__

/*  Include: MMI header file */
#include "CommonScreens.h"      /* DisplayPopup */
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* for tone ID */
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "wgui_status_icons.h"  /* for STATUS_ICON_IR */
#include "IdleAppDef.h" /* g_idle_context */
#include "IdleAppProt.h"        /* EntryIdleScreen() */
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "gpioInc.h"    /* TurnOnBacklight */
/* Leo add for DLT */
/* Leo end */
#include "CallManagementGprot.h"

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
#include "FileManagerGProt.h"
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

/* External Device Header Files */
#include "FileMgr.h"
#include "IrdaMMIGprots.h"
/* Leo add for DLT */
#include "FileManagerDef.h"
/* Leo end */
#include "IrdaMMI.h"
#include "IrdaMMIScr.h"
#include "ExtDeviceDefs.h"

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#include "FunAndGamesDefs.h"
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 


static U8 g_mmi_irda_selection = MMIR_SCR_IRCLOSE;
MMI_IRDA_SCR_CONTEX mmi_irda_scr_cntx;
MMI_IRDA_SCR_CONTEX *mmi_irda_scr_cntx_p = &mmi_irda_scr_cntx;

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
S8 gIrdaStorageLocation;

/* Priyesh - Issue# 678 */
U8 gPhoneFileCnt = 0;
U8 gCardFileCnt = 0;

/* Priyesh - Issue# 678 */

const U16 nIrdaStrList[] = 
{
    STR_IRDA_STORAGE_PHONE,
    STR_IRDA_STORAGE_CARD
};

const U16 nIrdaActList[] = 
{
    STR_IRDA_MENU_OPEN,
    STR_IRDA_MENU_CLOSE,
    STR_IRDA_MENU_PERIOD
};
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)        /* Shantanu - Downloadable themes support */
#define ERROR_SUCCESS_FSMOVE 0L
typedef enum
{
    PHONE_MEMORY,
    CARD_MEMORY
} storage_type_enum;
U8 g_theme_file_name[FMGR_MAX_FILE_LEN];
irda_file_recv_enum gIrdaThemeFileRecvCnt;  /* to set it to 1 on recv of a theme file from IRDA else 0 */
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ // __MMI_DOWNLOADABLE_THEMES_SUPPORT__  /* Shantanu - Downloadable themes support */

/***************************************************************************** 
 * External Variable
 *****************************************************************************/
extern S8 nPrintableStr[];  /* for file name buffer */


/***************************************************************************** 
* Marco
*****************************************************************************/
#define GENERIC_HIGHLIGHT_HDLR()                                \
   {                                                            \
      /* Change soft key icon and label */                      \
   ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);             \
   ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);        \
   /* Register go back function key handler */                   \
   SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);         \
   SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW,KEY_EVENT_DOWN); \
   }


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_init_menu_hdlr
 * DESCRIPTION
 *  This function is to initialize the mmi irda context.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_init_menu_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IRCLOSE;
    SetHiliteHandler(MENU_CONN_IRDA_MAIN, mmi_irda_setup_highlight_handler);
    //SetHiliteHandler(MENU_CONN_IRDA_OPEN, mmi_irda_setup_selection_highlight_handler );
    //SetHiliteHandler(MENU_CONN_IRDA_CLOSE, mmi_irda_setup_selection_highlight_handler );
    //SetHiliteHandler(MENU_CONN_IRDA_PERIOD, mmi_irda_setup_selection_highlight_handler );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_setup_highlight_handler
 * DESCRIPTION
 *  This function is to highlight handler of Extra->Infrared.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_setup_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GENERIC_HIGHLIGHT_HDLR();

    /* Register entry function key handler */
    SetLeftSoftkeyFunction(mmi_irda_entry_setup_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_irda_entry_setup_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_setup_selection_highlight_handler
 * DESCRIPTION
 *  This function is to highlight handler for Extra - >Infrared -> Period
 * PARAMETERS
 *  idx         [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_setup_selection_highlight_handler(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < MMIR_SCR_IRLAST)
    {
        g_mmi_irda_selection = (U8) idx;
    }
    else
    {
        g_mmi_irda_selection = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_setup_exec
 * DESCRIPTION
 *  This function is to left soft key handler for Extra - >Infrared -> Period
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : None(?)
 *****************************************************************************/
void mmi_irda_setup_exec(void)
{
#if 1   /* Suddenly close protect */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_finish = MMI_TRUE;
    MMI_IRDA_MAJOR_ACT_TYPE cur_act = mmi_irda_get_cur_action();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_irda_selection)
    {
        case MMIR_SCR_IROPEN:
            if (cur_act == MMI_IRDA_ACT_CLOSE)
            {
                mmi_irda_exec_open_menu();
            }
            else if (cur_act == MMI_IRDA_ACT_IDLE && mmi_irda_is_ircomm_active() != MMI_TRUE)
            {
                mmi_irda_exec_open_menu();
            }
            else
            {
                is_finish = KAL_FALSE;
            }

            break;
        case MMIR_SCR_IRCLOSE:
            if (cur_act == MMI_IRDA_ACT_IDLE && mmi_irda_is_ircomm_active() == MMI_FALSE)
            {
                mmi_irda_exec_close_menu();
            }
            else if (cur_act != MMI_IRDA_ACT_CLOSE || mmi_irda_is_ircomm_active() == MMI_TRUE)
            {
                is_finish = KAL_FALSE;
            }
            break;
        case MMIR_SCR_IRPERIOD:
            if (cur_act == MMI_IRDA_ACT_CLOSE)
            {
                mmi_irda_exec_period_menu();
            }
            else if (cur_act == MMI_IRDA_ACT_IDLE && mmi_irda_is_ircomm_active() != MMI_TRUE)
            {
                mmi_irda_exec_period_menu();
            }
            else
            {
                is_finish = KAL_FALSE;
            }

            break;
        default:
            break;
    }

    if (is_finish == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_IRDA_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }

#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
    DeleteScreenIfPresent(SCR_DEV_IRDA_SETTING);
#else /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    DeleteScreenIfPresent(SCR_DEV_IRDA_ACTIVATION);
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#else /* 1 */ /* Allow close IRDA  at anytime */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 1 */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_setup_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Infrared
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_entry_setup_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    U8 *HintList[MAX_SUB_MENUS];
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to hide IRDA function in PC simulator */
#ifndef __MTK_TARGET__
    PopupNoSupport();
    return;
#endif /* __MTK_TARGET__ */ 

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_DEV_IRDA_SETTING, NULL, mmi_irda_entry_setup_menu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_DEV_IRDA_SETTING);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CONN_IRDA_MAIN);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_CONN_IRDA_MAIN);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CONN_IRDA_MAIN, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_CONN_IRDA_MAIN);

    /* 7 Register highlight handler to be called in menu screen */
#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#else /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    RegisterHighlightHandler(mmi_irda_setup_selection_highlight_handler);
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /* 8 Construct the Hints List */
    /* ConstructHintsList(MENU_SETTING_DEF_ENCODING_TYPE, HintList); */
#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    SetHintHandler(MENU_CONN_IRDA_STORAGE, HintIrdaStorageLocation);
    SetHintHandler(MENU_CONN_IRDA_ACTIVATION, HintIrdaActivation);

    ConstructHintsList(MENU_CONN_IRDA_MAIN, HintList);
    mmi_msg_set_Irda_menu_highlight_handler();
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /* 9. Display Category screen */
#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
    ShowCategory11Screen(
        STR_IRDA_MENU_TITLE,
        MAIN_MENU_TITLE_EXTRA_APP_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) MMI_IRDASCR_CNTX(irda_state),
        guiBuffer);
#else /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    ShowCategory52Screen(
        STR_IRDA_MENU_TITLE,
        MAIN_MENU_TITLE_EXTRA_APP_ICON,
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
#endif /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /* 10.Register function with softkey */
#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
    SetLeftSoftkeyFunction(mmi_irda_setup_exec, KEY_EVENT_UP);
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    //PMT PANKAJ commented for working of the right arrow key on 2005/05/11
    //   SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    //PMT PANKAJ END
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* 11. Register Exit handler */
    /* SetGenericExitHandler( SCR_DEV_IRDA_SETTING, NULL, mmi_irda_entry_setup_menu); */

}

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */


/*****************************************************************************
 * FUNCTION
 *  HintIrdaActivation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintIrdaActivation(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(nIrdaActList[(U16) MMI_IRDASCR_CNTX(irda_state)]));
}


/*****************************************************************************
 * FUNCTION
 *  HintIrdaStorageLocation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintIrdaStorageLocation(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_name[(FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_get_drive_name( gIrdaStorageLocation, drv_name, sizeof(drv_name));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) drv_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_Irda_menu_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_Irda_menu_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CONN_IRDA_ACTIVATION, HighlightIrdaActivationHandler);
    SetHiliteHandler(MENU_CONN_IRDA_STORAGE, HighlightIrdaStorageHandler);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIrdaActivationHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIrdaActivationHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_irda_entry_activation_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_irda_entry_activation_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIrdaStorageHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIrdaStorageHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_irda_entry_storage_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_irda_entry_storage_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_activation_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_entry_activation_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 *HintList[MAX_SUB_MENUS]; */

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_DEV_IRDA_ACTIVATION, NULL, mmi_irda_entry_activation_menu, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_DEV_IRDA_ACTIVATION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CONN_IRDA_ACTIVATION);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_CONN_IRDA_ACTIVATION);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CONN_IRDA_ACTIVATION, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_CONN_IRDA_ACTIVATION);

    /* 7 Register highlight handler to be called in menu screen */
    /* RegisterHighlightHandler(ExecuteCurrHiliteHandler); */
    RegisterHighlightHandler(mmi_irda_setup_selection_highlight_handler);

    /* 8 Construct the Hints List */
    /* ConstructHintsList(MENU_SETTING_DEF_ENCODING_TYPE, HintList); */

    /* 9. Display Category screen */
    ShowCategory11Screen(
        STR_IRDA_MENU_TITLE,
        MAIN_MENU_TITLE_EXTRA_APP_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) MMI_IRDASCR_CNTX(irda_state),
        guiBuffer);

    /* 10.Register function with softkey */
    SetLeftSoftkeyFunction(mmi_irda_setup_exec, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* 11. Register Exit handler */
    /* SetGenericExitHandler( SCR_DEV_IRDA_SETTING, NULL, mmi_irda_entry_setup_menu); */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_storage_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_entry_storage_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(drv_letter != 0)
    {
        gIrdaStorageLocation = drv_letter;
        WriteValue(NVRAM_IRDA_STORAGE, &gIrdaStorageLocation, DS_BYTE, &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_storage_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_entry_storage_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_sel_drv_and_enter( APP_EXTDEVICE, mmi_irda_entry_storage_callback, gIrdaStorageLocation);
}

#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_exec_open_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Infrared -> Open
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_exec_open_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_ir_open(MMI_IRDA_OPEN_ALWAYS);
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IROPEN;
    ShowStatusIcon(STATUS_ICON_IR);
    UpdateStatusIcons();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_exec_close_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Infrared -> Close
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_exec_close_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_ir_close();
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IRCLOSE;
    HideStatusIcon(STATUS_ICON_IR);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_exec_period_menu
 * DESCRIPTION
 *  This function is to Entry function for Extra->Infrared -> Period
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_exec_period_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_ir_open(MMI_IRDA_OPEN_PERIOD);
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IRPERIOD;
    ShowStatusIcon(STATUS_ICON_IR);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_scr_data_passing_ind
 * DESCRIPTION
 *  This function is to notify user that irda is working
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_scr_data_passing_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AnimateStatusIcon(STATUS_ICON_IR);
    UpdateStatusIcons();
    /* BlinkStatusIcon(STATUS_ICON_IR); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_scr_data_stop_ind
 * DESCRIPTION
 *  This function is to notify user that no data running through irda
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_scr_data_stop_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDASCR_CNTX(irda_state) != MMIR_SCR_IRCLOSE)
    {
        HideStatusIcon(STATUS_ICON_IR);
        ShowStatusIcon(STATUS_ICON_IR);
        UpdateStatusIcons();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_scr_irda_close_ind
 * DESCRIPTION
 *  This function is to notify user that irda h/w is closed
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_scr_irda_close_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IRCLOSE;

    HideStatusIcon(STATUS_ICON_IR);
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obj_receive_ind
 * DESCRIPTION
 *  This function is to notify user that irda received a unrecognized object
 *  
 *  PARAMETERS : void
 *  path_src        [?]     
 *  filename        [?]     
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
MMI_IRDA_NFY_TYPE mmi_irda_obj_receive_ind(void *path_src, void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 fcnt = 0;
    U8 *path_buf;
    FS_HANDLE h;
    U8 recv_cnt = 0;
    int accept_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IRDA_RECEIVED_NOTIFY_IN_IDLE__
    /* Get total pending objects */
    recv_cnt = mmi_irda_get_recv_files_cnt();
    if (recv_cnt == 0xFF)
    {
        mmi_irda_set_recv_files_cnt(0xFF);
    }
    else
    {
        mmi_irda_set_recv_files_cnt((U8) (recv_cnt + 1));
    }
#endif /* __MMI_IRDA_RECEIVED_NOTIFY_IN_IDLE__ */ 

    /* Get file path buffer */
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_irda_assert(path_buf != NULL);

    /* Build actually file name */
    MMI_IRDA_MAKE_RECV_PATH(path_buf);
    kal_wstrcat((kal_uint16*) path_buf, L"\\");
    kal_wstrcat((kal_uint16*) path_buf, (kal_uint16*) filename);

    /* Rename temp file name to actually object name as file name */
    h = FS_Rename((kal_uint16*) path_src, (kal_uint16*) path_buf);
    /* Check if file exist */
    if (h < FS_NO_ERROR)
    {
        fcnt++;
        while (fcnt < 0xFF)
        {
            MMI_IRDA_MAKE_RECV_PATH(path_buf);
            kal_wstrcat((kal_uint16*) path_buf, L"\\");
            kal_wsprintf((kal_uint16*) nPrintableStr, "Dup(%d)", fcnt);
            accept_len = sizeof(MMI_IRDA_CTX(obj_name)) - mmi_ucs2strlen(nPrintableStr) * 2 - 2;
            if (mmi_ucs2strlen(filename) * 2 > accept_len)
            {
                kal_wstrcat((kal_uint16*) nPrintableStr, L"~");
                accept_len -= 2;
                memcpy(
                    nPrintableStr + (mmi_ucs2strlen(nPrintableStr) * 2),
                    (kal_uint8*) filename + (mmi_ucs2strlen(filename) * 2) - accept_len,
                    accept_len);
                nPrintableStr[sizeof(MMI_IRDA_CTX(obj_name)) - 2] = 0;
                nPrintableStr[sizeof(MMI_IRDA_CTX(obj_name)) - 1] = 0;
            }
            else
            {
                kal_wstrcat((kal_uint16*) nPrintableStr, (kal_uint16*) filename);
            }
            kal_wstrcat((kal_uint16*) path_buf, (kal_uint16*) nPrintableStr);

            h = FS_Rename((kal_uint16*) path_src, (kal_uint16*) path_buf);
            if (h < FS_NO_ERROR)
            {
                fcnt++;
            }
            else
            {
                break;
            }
        }
    }

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    if ( (gIrdaStorageLocation == MMI_PUBLIC_DRV) || (!fmgr_is_msdc_present()))
    {
        if (gPhoneFileCnt < 255)
        {
            gPhoneFileCnt++;
        }
    }
    else
    {
        if (gCardFileCnt < 255)
        {
            gCardFileCnt++;
        }
    }
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /* free path buffer */
    OslMfree(path_buf);

#ifdef __MMI_IRDA_RECEIVED_NOTIFY_POPUP__
    /* Play warning tone to notify file saved */
    if ((isInCall() == MMI_FALSE) || (IsWapCallPresent())) 
    {
        DisplayPopup((PU8) GetString(STR_IRDA_RECV_FILE_IND), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    }
#endif /* __MMI_IRDA_RECEIVED_NOTIFY_POPUP__ */ 

    if (g_idle_context.IsOnIdleScreen || GetActiveScreenId() == SCR_DEV_IRDA_NOTY_FILE_RECV)
    {
        EntryIdleScreen();
    }

    TurnOnBacklight(1);

    return MMI_IRDA_NFY_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_recv_err
 * DESCRIPTION
 *  This function is to display popup sceren when receiving error
 *  
 *  PARAMETERS : void
 *  cause       [IN]        
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_notify_recv_err(MMI_IRDA_NFY_TYPE cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cause == MMI_IRDA_NFY_DISK_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_IRDA_RECV_DISK_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_IRDA_NFY_ROOT_DIR_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_IRDA_RECV_ROOT_DIR_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_IRDA_NFY_WRITE_FILE_FAIL)
    {
        DisplayPopup(
            (PU8) GetString(STR_IRDA_WRITE_FILE_FAIL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_idle_notify_scr
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
U16 mmi_irda_idle_notify_str[32];
#else /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
U16 mmi_irda_idle_phone_str[32];
U16 mmi_irda_idle_card_str[32];
#endif /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */

#define MMI_IRDA_BUILD_NOTY_STR()                                                                 \
{                                                                                                 \
   U16 cnt[8];                                                                                    \
                                                                                                  \
   kal_wstrcpy( (U16 *)mmi_irda_idle_notify_str, (U16 *)GetString(STR_IRDA_NOTY_RECV_FILE_HED) ); \
   kal_wsprintf( (U16 *)cnt, " %d ", mmi_irda_get_recv_files_cnt() );                             \
   kal_wstrcat( (U16 *)mmi_irda_idle_notify_str,  (U16*) cnt);                                    \
   kal_wstrcat( (U16 *)mmi_irda_idle_notify_str,  (U16*) GetString(STR_IRDA_NOTY_RECV_FILE_TIL)); \
                                                                                                  \
}

#else /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
#define MMI_IRDA_BUILD_NOTY_STR()                                                                \
{                                                                                                \
   U16 cnt[8];                                                                                   \
                                                                                                 \
if(gPhoneFileCnt){                                                                               \
   kal_wstrcpy( (U16 *)mmi_irda_idle_phone_str, (U16 *)GetString(STR_IRDA_STORAGE_PHONE) );      \
   kal_wsprintf( (U16 *)cnt, ": %d ", gPhoneFileCnt );                                           \
   kal_wstrcat( (U16 *)mmi_irda_idle_phone_str,  (U16*) cnt);                                    \
   kal_wstrcat( (U16 *)mmi_irda_idle_phone_str,  (U16*) GetString(STR_IRDA_NOTY_RECV_FILE_TIL)); \
}                                                                                                \
else mmi_irda_idle_phone_str[0] = '\0';                                                          \
if(gCardFileCnt){                                                                                \
   kal_wstrcpy( (U16 *)mmi_irda_idle_card_str, (U16 *)GetString(STR_IRDA_STORAGE_CARD) );        \
   kal_wsprintf( (U16 *)cnt, ": %d ", gCardFileCnt );                                            \
   kal_wstrcat( (U16 *)mmi_irda_idle_card_str,  (U16*) cnt);                                     \
   kal_wstrcat( (U16 *)mmi_irda_idle_card_str,  (U16*) GetString(STR_IRDA_NOTY_RECV_FILE_TIL));  \
}                                                                                                \
else mmi_irda_idle_card_str[0] = '\0';                                                           \
}
#endif /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

void mmi_irda_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IRDA_BUILD_NOTY_STR();

    if (mmi_irda_get_recv_files_cnt() == 0)
    {
        EntryIdleScreen();
        return;
    }

    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        EntryNewScreen(SCR_DEV_IRDA_NOTY_FILE_RECV, NULL, mmi_irda_entry_idle_notify_scr, NULL);
    #if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
        ShowCategory154Screen(
            0,
            0,
            STR_IRDA_NOTY_RECV_FILE_BROWSE,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*) mmi_irda_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    #else /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
        ShowCategory154Screen(
            STR_IRDA_FILE_RECEIVED,
            0,
            STR_IRDA_NOTY_RECV_FILE_BROWSE,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*) mmi_irda_idle_phone_str,
            (U8*) mmi_irda_idle_card_str,
            IMG_GLOBAL_INFO,
            NULL);
    #endif /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
        SetLeftSoftkeyFunction(mmi_irda_notify_scr_browse, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_irda_notify_scr_goback_func, KEY_EVENT_UP);
        SetKeyHandler(mmi_irda_notify_scr_endkey_func, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
    #if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) mmi_irda_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    #else /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
        ShowCategory154Screen(
            STR_IRDA_FILE_RECEIVED,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) mmi_irda_idle_phone_str,
            (U8*) mmi_irda_idle_card_str,
            IMG_GLOBAL_INFO,
            NULL);
    #endif /* !defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    }
}

#if 0   /* defined(__MMI_IRDA_NOTIFY__) //Priyesh - IRDA Notification */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card Support
/* under construction !*/
/* under construction !*/
#else //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
/* under construction !*/
/* under construction !*/
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ /* __MMI_IRDA_NOTIFY__ //Priyesh - IRDA Notification */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_scr_browse
 * DESCRIPTION
 *  This function is to broswe received folder
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 *path_tmpbuf;
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);

    path_tmpbuf = (S8*) OslMalloc(FMGR_PATH_BUFFER_SIZE);
    ASSERT(path_tmpbuf != NULL);

    MMI_IRDA_MAKE_RECV_PATH(path_tmpbuf);

    mmi_fmgr_select_path_and_enter(
        APP_EXTDEVICE,
        FMGR_SELECT_BROWSE,
        filter,
        path_tmpbuf,    /* (PS8)L"D:\\Received", */
        mmi_irda_notify_scr_browse_cb);
    OslMfree(path_tmpbuf);

    /* Priyesh - Issue# 678 */
#if !defined(__MMI_IRDA_CARD_SUPPORT__) /* Priyesh - Memory Card Support */
    mmi_irda_set_recv_files_cnt(0); /* After take action */
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    /* Priyesh - Issue# 678 */

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    if (gPhoneFileCnt)
    {
        gPhoneFileCnt = 0;
        if (gCardFileCnt == 0)
        {
            mmi_irda_set_recv_files_cnt(0);
        }
    }
    else
    {
        gPhoneFileCnt = 0;
        gCardFileCnt = 0;
        /* Priyesh - Issue# 678 */
        mmi_irda_set_recv_files_cnt(0); /* After take action */
        /* Priyesh - Issue# 678 */
    }
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_scr_browse_cb
 * DESCRIPTION
 *  This function is to broswe received folder callback func
 *  
 *  PARAMETERS : void
 *  filename        [?]         
 *  isShort         [IN]        
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_notify_scr_browse_cb(void *filename, int isShort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GoBackHistory(); */
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_scr_goback_func
 * DESCRIPTION
 *  This function is to go back history
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_notify_scr_goback_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_set_recv_files_cnt(0); /* After take action */

    /* Priyesh - Issue# 678 */
#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    gPhoneFileCnt = 0;
    gCardFileCnt = 0;
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    /* Priyesh - Issue# 678 */

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_scr_endkey_func
 * DESCRIPTION
 *  This function is to back to idle screen
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_notify_scr_endkey_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_set_recv_files_cnt(0); /* After take action */

    /* Priyesh - Issue# 678 */
#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    gPhoneFileCnt = 0;
    gCardFileCnt = 0;
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */
    /* Priyesh - Issue# 678 */

    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_scr_open_func
 * DESCRIPTION
 *  This function is to open irda and sync with screen status
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_scr_open_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_irda_selection = MMIR_SCR_IRPERIOD;
    MMI_IRDASCR_CNTX(irda_state) = MMIR_SCR_IRPERIOD;
    if (mmi_irda_get_cur_action() == MMI_IRDA_ACT_CLOSE)
    {
        mmi_irda_exec_period_menu();
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/* PMT PANKAJ START- Moved the IRDA code from FileMgr.c to IRDAMMIScr.c */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_entry_fmgr_fwd
 * DESCRIPTION
 *  This function is to send an object through IRDA when it has been forwared from File Manager
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
#define IRDA_PROG_UPD_DUR  2000
static U16 irda_fmgr_send_str_buf[64];

#define IRDA_UDPADE_STR() {                                                                                                                           \
       U16 fmgr_irda_send_per_str_buf[32];                                                                                                            \
       if( (mmi_ucs2strlen( (S8*)  GetString(STR_GLOBAL_SEND) )+1) > ((sizeof(irda_fmgr_send_str_buf)/2) -(sizeof(fmgr_irda_send_per_str_buf)/2)) ) \
         ASSERT(MMI_FALSE);                                                                                                                           \
   kal_wsprintf( (U16*)fmgr_irda_send_per_str_buf, "(%d%c) ", mmi_irda_retrieve_put_prog_percentage(),'%' );                                          \
      mmi_ucs2cpy((S8*)irda_fmgr_send_str_buf, GetString(STR_GLOBAL_SEND) );                                                                     \
      mmi_ucs2cat((S8*)irda_fmgr_send_str_buf, (S8*)fmgr_irda_send_per_str_buf);                                                                 \
}

void mmi_irda_entry_fmgr_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_DEV_IRDA_SEND, mmi_irda_exit_fmgr_fwd, mmi_irda_entry_fmgr_fwd, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show Sending screen */
    /* mmi_ucs2cpy((S8*)irda_fmgr_send_str_buf, GetString(STR_GLOBAL_SEND) ); */
    IRDA_UDPADE_STR();
    ShowCategory66Screen(
        STR_IRDA_SEND,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) irda_fmgr_send_str_buf,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set Right softkey function to abort sending */
    SetRightSoftkeyFunction(mmi_irda_obex_snd_abort, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_DEV_IRDA_SEND, (HistoryDelCBPtr) mmi_irda_sending_screen_del_cb);

    StartTimer(FMGR_PROG_UPDATE_TIMER, IRDA_PROG_UPD_DUR, mmi_irda_update_prog_tohdlr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_exit_fmgr_fwd
 * DESCRIPTION
 *  This function is the exit function for the send through file manager screen
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_exit_fmgr_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_sending_screen_del_cb
 * DESCRIPTION
 *  This function is
 *  
 *  PARAMETERS : void
 *  p       [?]     
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
U8 mmi_irda_sending_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_irda_is_sending())
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
 *  mmi_irda_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IRDA_UDPADE_STR();
    cat66_update_progress_string();
    /* RedrawCategory66Screen(); */
    StartTimer(FMGR_PROG_UPDATE_TIMER, IRDA_PROG_UPD_DUR, mmi_irda_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_fmgr_forward_to_irda_callback
 * DESCRIPTION
 *  This function is the call back used when the transfer gets completed
 *  
 *  PARAMETERS : void
 *  buf_p       [?]         
 *  result      [IN]        
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : void(?)
 *****************************************************************************/
void mmi_irda_fmgr_forward_to_irda_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf_p)
    {
        OslMfree(buf_p);
    }

    if (result == MMI_IRDA_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    DeleteScreenIfPresent(SCR_DEV_IRDA_SEND);

    StopTimer(FMGR_PROG_UPDATE_TIMER);
}

/* PMT PANKAJ END */

/* Added for theme support -shantanu */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_theme_idle_notify_scr
 * DESCRIPTION
 *  This function is to show popup when a theme file is received from IRDA
 *  
 *  PARAMETERS : path of file which was stored in Received folder and original filename
 *  path_src        [?]     
 *  filename        [?]     
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : gIrdaThemeFileRecvCnt,gIrdaStoragePath,g_theme_file_name(?)
 *****************************************************************************/
void mmi_irda_theme_idle_notify_scr(void *path_src, void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) g_theme_file_name, (S8*) filename);

    result = SetIrdaThmDownloadStroageType(path_src);

    if (result == ERROR_SUCCESS_FSMOVE)
    {
        gIrdaThemeFileRecvCnt = FILE_RECV;
    #ifdef __MMI_IRDA_RECEIVED_NOTIFY_POPUP__
        DisplayPopup((U8*) GetString(STR_IRDA_THEME_FILE_RECV), IMG_GLOBAL_INFO, 1, UI_POPUP_NOTIFYDURATION_TIME, 0);
        if (isInCall() == MMI_FALSE)
        {
            playRequestedTone(MESSAGE_TONE);
        }
        else
        {
            playRequestedTone(SMS_IN_CALL_TONE);
        }

    #endif /* __MMI_IRDA_RECEIVED_NOTIFY_POPUP__ */ 

        if (IsScreenPresent(SCR_DEV_IRDA_NOTY_THM_FILE_RECV) == TRUE)
        {
            gIrdaThemeFileRecvCnt = NO_FILE_RECV;
            TurnOnBacklight(1);
            return;
        }
        if (g_idle_context.IsOnIdleScreen)
        {
            EntryIdleScreen();
        }
    }
    else
    {
        FS_Delete((WCHAR*) path_src);
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_theme_show_idle_notify_scr
 * DESCRIPTION
 *  This function is called from EntryIdleScreen function to show the theme activation screen
 *  
 *  PARAMETERS : void
 *  void
 *  RETURNS : void(?)
 *  GLOBALS AFFECTED : gIrdaThemeFileRecvCnt(?)
 *****************************************************************************/
void mmi_irda_theme_show_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        gIrdaThemeFileRecvCnt = NO_FILE_RECV;
        irda_theme_activate_function();
    }
    else
    {
        ShowCategory154Screen(
            STR_IRDA_FILE_RECEIVED,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) GetString(STR_IRDA_THEME_FILE_RECV),
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetIrdaThmDownloadStroageType
 * DESCRIPTION
 *  This function saves the file received inside the preferred location
 * PARAMETERS
 *  path_src        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
int SetIrdaThmDownloadStroageType(void *path_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __MMI_IRDA_CARD_SUPPORT__
    S32 fs_RetDrv;
#endif
    FS_HANDLE file_handle;
    S32 fs_ret;
    S8 buf[6];
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For checking if preferred storage is card and if card is not available then store in Phone */
#if defined(__MMI_IRDA_CARD_SUPPORT__)
    sprintf(buf, "%c:\\", (U8) gIrdaStorageLocation);
#else
    fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    sprintf(buf, "%c:\\", (U8) fs_RetDrv);
#endif
    memset(subMenuData[0], 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) subMenuData[0], (S8*) buf);

    mmi_ucs2cat((PS8) subMenuData[0], (PS8) FMGR_DEFAULT_FOLDER_THEMES);
    file_handle = FS_Open((kal_uint16*) subMenuData[0], FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        create_result = FS_NO_ERROR;
    }
    else
    {
        create_result = FS_CreateDir((PU16) subMenuData[0]);
    }

    if (create_result == FS_NO_ERROR)
    {
        mmi_ta_check_if_file_alrdy_exist_in_fm((PS8) subMenuData[0], (PS8) g_theme_file_name);
        mmi_ucs2cat((PS8) subMenuData[0], (PS8) g_theme_file_name);
        fs_ret = FS_Move((WCHAR*) path_src, (WCHAR*) subMenuData[0], FS_MOVE_KILL, NULL, NULL, 0);
        return fs_ret;
    }
    else
    {
        return create_result;
    }

}   /* end of SetIrdaThmDownloadStroageType() function */


/*****************************************************************************
 * FUNCTION
 *  irda_theme_activate_function
 * DESCRIPTION
 *  This function show the theme activation screen on entering the idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void irda_theme_activate_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DEV_IRDA_NOTY_THM_FILE_RECV, NULL, irda_theme_activate_function, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_DEV_IRDA_NOTY_THM_FILE_RECV);

    ShowCategory8Screen(
        STR_IRDA_FILE_RECEIVED,
        0,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        STR_ID_DLT_DO_YOU_WANT_TO_ACTIVATE,
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    SetLeftSoftkeyFunction(ActivateThemeDownloadedFromIRDA, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ActivateThemeDownloadedFromIRDA
 * DESCRIPTION
 *  This function activates the downloaded theme from IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateThemeDownloadedFromIRDA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    tm_theme_type_enum gMemoryType;
    int status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IRDA_CARD_SUPPORT__)
    if((gIrdaStorageLocation == MMI_PUBLIC_DRV) || (!fmgr_is_msdc_present()))
#else
    if(1)
#endif
    {
        gMemoryType = THEME_TYPE_DOWNLOADED_PHONE;
    }
    else
    {
        gMemoryType = THEME_TYPE_DOWNLOADED_CARD;
    }

    status = mmi_tm_activate_theme_from_fmgr(gMemoryType, (PU8) g_theme_file_name, MMI_FALSE);
    GoBackHistory();
    mmi_tm_handle_theme_activation_error_status((U16) status);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_is_any_theme_file_rcv
 * DESCRIPTION
 *  This function returns the number of theme files received through IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  irda_file_recv_enum :  NO_FILE_RCV  OR   FILE_RECV
 *****************************************************************************/
//PMT DLT_FIXES - TK 20060225 START
//modified by tk change return type from irda_file_recv_enum to U8
U8 mmi_irda_is_any_theme_file_rcv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8) gIrdaThemeFileRecvCnt;
}

/* PMT DLT_FIXES - TK 20060225 END */

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#endif /* __MMI_IRDA_SUPPORT__ */ 

