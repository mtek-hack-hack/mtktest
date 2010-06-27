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
 * VRSISettings.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for settings of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSISETTINGS_C
#define _MMI_VRSISETTINGS_C

#ifdef __MTK_TARGET__

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "messagesEXDcl.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "IdleAppProt.h"

/* ... Add More MMI header */
#include "med_global.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "VRSIResDef.h"
#include "MainMenuDef.h"

#include "SSCStringHandle.h"
#include "gpioInc.h"

#include "USBDeviceGprot.h"

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
#if defined (__MMI_VRSI_TRAIN_TAG__) 
static BOOL g_vrsi_change_highlight;    /* Check if highlight changed during SD tag playing */
#endif
/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */

#define MMI_VRSI_SETTING_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_init
 * DESCRIPTION
 *  init function for VRSI setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSI_SETTING, mmi_vrsi_highlight_setting_menu);

    /* Recognition Enable */
    SetHiliteHandler(MENU_ID_VRSI_SETTING_RCG, mmi_vrsi_highlight_rcg_enable);
    SetHintHandler(MENU_ID_VRSI_SETTING_RCG, mmi_vrsi_hint_rcg_enable);

    /* Train Tag */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    SetHiliteHandler(MENU_ID_VRSI_SETTING_TRAIN_TAG, mmi_vrsi_highlight_train_tag);

    /* Train Tag Menu */
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_NAME_LIST, mmi_vrsi_highlight_train_name_list);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_SHORTCUT_LIST, mmi_vrsi_highlight_train_shortcut_list);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_CITY_LIST, mmi_vrsi_highlight_train_city_list);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_DELETE_ALL, mmi_vrsi_highlight_train_delete_all);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_TAG_STATUS, mmi_vrsi_highlight_train_tag_status);
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

    /* Digit Adapt */
#if defined(__MMI_VRSI_DIGIT_ADAPT__)
    SetHiliteHandler(MENU_ID_VRSI_SETTING_DIGIT_ADAPT, mmi_vrsi_highlight_digit_adapt);
#endif 

    /* Read VRSI recognition value from NVRAM */
    ReadValue(NVRAM_VRSI_RCG_SETTING, &g_vrsi_cntx.rcg_enable, DS_BYTE, &pError);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_setting_menu
 * DESCRIPTION
 *  Highlight function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_vrsi_entry_setting_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_entry_setting_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_menu_callback
 * DESCRIPTION
 *  Entry function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vrsi_setting_menu_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 nNumofItem;
    U8 *hintList[10];   /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Callback by init function, so close engine */
    mmi_vrsi_rcg_close();

    EntryNewScreen(SCR_ID_VRSI_SETTING_MENU, NULL, mmi_vrsi_entry_setting_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSI_SETTING_MENU); /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSI_SETTING_MAIN);
    GetSequenceStringIds(MENU_ID_VRSI_SETTING_MAIN, nStrItemList);
    SetParentHandler(MENU_ID_VRSI_SETTING_MAIN);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_VRSI_SETTING_MAIN, hintList);

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_ON,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_setting_menu
 * DESCRIPTION
 *  Entry function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /*Call init function to sync tag for first time use. */
    mmi_vrsi_rcg_init(mmi_vrsi_setting_menu_callback);

}

#define MMI_VRSI_SETTING_RCG_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_rcg_enable
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.rcg_enable)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    SetLeftSoftkeyFunction(mmi_vrsi_rcg_enable_toggle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_hint_rcg_enable
 * DESCRIPTION
 *  Hint function for VRSI setting menu option
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_hint_rcg_enable(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.rcg_enable)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_enable_toggle
 * DESCRIPTION
 *  toggle VRSI recognition enable/disable settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_enable_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    U16 str_LSK = STR_GLOBAL_OFF, str_hint = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (g_vrsi_cntx.rcg_enable)
    {
        g_vrsi_cntx.rcg_enable = 0;
        str_LSK = STR_GLOBAL_ON;
        str_hint = STR_GLOBAL_OFF;
    }
    else
    {
        g_vrsi_cntx.rcg_enable = 1;
    }

    ChangeLeftSoftkey(str_LSK, IMG_GLOBAL_OK);
    mmi_ucs2cpy((S8*) hintData[index], GetString(str_hint));
    Category52ChangeItemDescription(index, hintData[index]);

    /* Redraw the Category Screen As Hint Handler and LSK are going to Chnage */
    RedrawCategoryFunction();

    /* Write Back To NVRAM */
    WriteValue(NVRAM_VRSI_RCG_SETTING, &g_vrsi_cntx.rcg_enable, DS_BYTE, &pError);

    /* DisplayPopup((U8*)GetString(str_hint), IMG_GLOBAL_ACTIVATED,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
}

#define MMI_VRSI_TRAIN_TAG
#if defined(__MMI_VRSI_TRAIN_TAG__)
#define MMI_VRSI_TRAIN_TAG_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsi_entry_train_tag_main, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_entry_train_tag_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_name_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_train_list_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_ndial_train_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_shortcut_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_shortcut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_entry_scut_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_entry_scut_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_city_list
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_city_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_entry_city_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_entry_city_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_delete_all
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_entry_train_delele_all_confirm, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_tag_status
 * DESCRIPTION
 *  Highlight function for VRSI train SD tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_tag_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsi_entry_train_status, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_entry_train_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_tag_main
 * DESCRIPTION
 *  Entry train SD tag main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_tag_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MMI_VRSI_APP_TOTAL + 4];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSI_TRAIN_TAG_MAIN, NULL, mmi_vrsi_entry_train_tag_main, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSI_TRAIN_TAG_MAIN);   /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSI_SETTING_TRAIN_TAG);
    GetSequenceStringIds(MENU_ID_VRSI_SETTING_TRAIN_TAG, nStrItemList);
    SetParentHandler(MENU_ID_VRSI_SETTING_TRAIN_TAG);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_VRSI_TRAIN_TAG,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define MMI_VRSI_TRAIN_TAG_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_add
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_change_highlight = TRUE;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_vrsi_train_option_pre_add, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_del
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_change_highlight = TRUE;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_vrsi_train_option_delete_confirm, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_train_option_playback
 * DESCRIPTION
 *  Highlight function for VRSI train tag option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_train_option_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_change_highlight = TRUE;

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_vrsi_train_option_pre_playback, KEY_EVENT_UP);
    SetKeyHandler(mmi_vrsi_train_option_pre_playback, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_add
 * DESCRIPTION
 *  Pre entry function for VRSI train tag option, it will display add option only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_entry_train_option(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_del
 * DESCRIPTION
 *  Pre entry function for VRSI train tag option, it will display delete ad playback option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_entry_train_option(2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option
 * DESCRIPTION
 *  This is the option list for train VRSI tag
 * PARAMETERS
 *  type        [IN]        1: add 2: delete/playback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[4];
    U16 nNumofItem;

    U32 HideItemId = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == 1)
    {
        EntryNewScreen(
            SCR_ID_VRSI_TRAIN_OPTION_MAIN,
            mmi_vrsi_exit_train_option,
            mmi_vrsi_entry_train_option_add,
            NULL);
    }
    else
    {
        EntryNewScreen(
            SCR_ID_VRSI_TRAIN_OPTION_MAIN,
            mmi_vrsi_exit_train_option,
            mmi_vrsi_entry_train_option_del,
            NULL);
    }

    nNumofItem = GetNumOfChild(MENU_ID_VRSI_TRAIN_OPTION_MAIN);
    GetSequenceStringIds(MENU_ID_VRSI_TRAIN_OPTION_MAIN, nStrItemList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSI_TRAIN_OPTION_MAIN);
    SetParentHandler(MENU_ID_VRSI_TRAIN_OPTION_MAIN);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /*
     * Register all highlight handler again, because RsetBit() may change the highlight handler when hide menu.
     * Note that add handler has registered before enter this function.
     */
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_OPTION_ADD, mmi_vrsi_highlight_train_option_add);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_OPTION_DEL, mmi_vrsi_highlight_train_option_del);
    SetHiliteHandler(MENU_ID_VRSI_TRAIN_OPTION_PLAY, mmi_vrsi_highlight_train_option_playback);

    /* Display menu option accordingly, hide unsupport menu here. */
    if (type == 1)
    {
        nNumofItem = 1; /* Display first option only */
    }
    else
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_VRSI_TRAIN_OPTION_MAIN, MENU_ID_VRSI_TRAIN_OPTION_ADD);
        ResetBit(maskingByte, HideItemId);  /* 0:Add */

        MaskHiliteItems(MENU_ID_VRSI_TRAIN_OPTION_MAIN, maskingByte);
        nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
    }

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_train_option
 * DESCRIPTION
 *  This is the exit function for option list for train VRSI tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_train_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT)
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_add
 * DESCRIPTION
 *  Get free SD tag mapping slot before training
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get free Tag */
    tag_pos = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_NONE, 0xffff, NULL);

    if (tag_pos != 0xff)
    {
        g_vrsi_cntx.curr_tag = tag_pos;
        mmi_vrsi_rcg_init(mmi_vrsi_train_option_add_start);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_SD_TAG_FULL),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_add_start
 * DESCRIPTION
 *  Start traing tag function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_add_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Start Digit Adaptation */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_cmd_trn(
                    MOD_MMI,
                    g_vrsi_cntx.session_id,
                    (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                    g_vrsi_cntx.long_name_ptr,
                    g_vrsi_cntx.long_list[0]);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_TRAIN_ADD_START, result, g_vrsi_cntx.session_id,
                   g_vrsi_cntx.long_list[0]);

        if (result == MED_RES_OK)
        {
            return;
        }
        else
        {
            mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
            mdi_audio_vrsi_close();
            g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_IDLE;
        }
    }

    DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_option_add_prompt
 * DESCRIPTION
 *  Entry train SD tag prompt message screen.
 * PARAMETERS
 *  prompt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_option_add_prompt(U8 prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    if (prompt == 1)
    {
        str_id = STR_ID_VRSI_TRAIN_TAG_PROMPT1;
    }
    else    /* prompt == 2 */
    {
        str_id = STR_ID_VRSI_TRAIN_TAG_PROMPT2;
    }

    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT, mmi_vrsi_exit_train_option_add_prompt, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                  /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        str_id,             /* message id */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    /* Play Prompt Tone and send confirm after prompt */
    mmi_vrsi_rcg_play_prompt_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_train_option_add_prompt
 * DESCRIPTION
 *  Exit train SD tag prompt message screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_train_option_add_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT)
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_add_result
 * DESCRIPTION
 *  Train success, write result to mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_add_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    tag_list[g_vrsi_cntx.curr_tag].tag_long = g_vrsi_cntx.long_list[0];
    tag_list[g_vrsi_cntx.curr_tag].tag_id = media_aud_vrsi_read_cmd_trn_result();
    tag_list[g_vrsi_cntx.curr_tag].app_id = g_vrsi_cntx.curr_app;

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_TRAIN_ADD_RESULT, g_vrsi_cntx.curr_tag,
               tag_list[g_vrsi_cntx.curr_tag].app_id, tag_list[g_vrsi_cntx.curr_tag].tag_long,
               tag_list[g_vrsi_cntx.curr_tag].tag_id);

    /* Save result to NVRAM */
    WriteRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteNScrId(SCR_ID_VRSI_TRAIN_OPTION_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_delete_confirm
 * DESCRIPTION
 *  Delete SD tag confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_delete_confirm(void)
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
        (UI_string_type) GetString(STR_ID_VRSI_DELETE_QUESTION),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_vrsi_train_option_pre_delete_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_delete_tag
 * DESCRIPTION
 *  Delete SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_delete_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System busy */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_BUSY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Init VR engine for delete sd tag */
    mmi_vrsi_rcg_init(mmi_vrsi_train_option_delete_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_delete_tag
 * DESCRIPTION
 *  Delete SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_delete_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    /* get SD tag id mapping. */
    mmi_vrsi_train_util_get_id_and_loc(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0], &tag_id[0]);

    media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], 1, tag_id);

    mmi_vrsi_rcg_close();

    /* Delete tag in mapping table */
    mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DELETED),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteNScrId(SCR_ID_VRSI_TRAIN_OPTION_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_pre_playback
 * DESCRIPTION
 *  Pre-check state for playback SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_pre_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System busy */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_BUSY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Init VR engine for playback */
    mmi_vrsi_rcg_init(mmi_vrsi_train_option_playback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_playback
 * DESCRIPTION
 *  Playback SD tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    /* If it is in first time initialize screen, go back to option menu */
    if (GetActiveScreenId() == SCR_ID_VRSI_INIT_PROCESSING)
    {
        GoBackHistory();
    }

    /* get SD tag id mapping and playback. */
    result = mmi_vrsi_util_play_tag(
                MMI_VRSI_GRAMMAR_1,
                g_vrsi_cntx.curr_app,
                g_vrsi_cntx.long_list[0],
                mmi_vrsi_train_option_playback_finish);

    if (result == MED_RES_OK)
    {
        /* avoid user continue pressing */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        g_vrsi_change_highlight = FALSE;
        return;
    }
    else if (result == MED_RES_VRSI_ERR_NO_MATCH_TAG)   /* Tag not in engine, delete tag mapping */
    {
        mmi_vrsi_train_util_del_tag(g_vrsi_cntx.curr_app, g_vrsi_cntx.long_list[0]);

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteNScrId(SCR_ID_VRSI_TRAIN_OPTION_MAIN);
    }

    mmi_vrsi_rcg_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_option_playback_finish
 * DESCRIPTION
 *  Call back function when play SD tag finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_option_playback_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vrsi_change_highlight)
    {
        mmi_vrsi_highlight_train_option_playback();
    }

    mmi_vrsi_rcg_close();
}

#define MMI_VRSI_TRAIN_TAG_DELETE_ALL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_delele_all_confirm
 * DESCRIPTION
 *  Confirm delete all screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_delele_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count_list[MMI_VRSI_APP_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_train_util_get_tag_count(count_list);

    if (count_list[MMI_VRSI_APP_ALL] > 0)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) GetString(STR_ID_VRSI_DELETE_ALL_QUESTION),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_vrsi_train_pre_del_all_tag, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_pre_del_all_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_pre_del_all_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* System busy */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_BUSY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Init VR engine for playback */
    mmi_vrsi_rcg_init(mmi_vrsi_train_del_all_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_del_all_tag
 * DESCRIPTION
 *  Delete all SD tag in mapping table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_del_all_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i, tag_num = 0;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* VR should already in running state. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_RUNNING)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    /* Read out mapping table and build ID list */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if (tag_list[i].tag_id != 0xffff)
        {
            tag_id[tag_num] = tag_list[i].tag_id;
            tag_num++;
        }
    }

    if (tag_num > 0)
    {
        /* Delete tag in engine */
        media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);

        /* Delete mapping in NVRAM */
        memset(tag_list, 0xff, sizeof(vrsi_sd_tag_struct) * MMI_VRSI_MAX_SD_TAG);
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DELETED),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

    /* Close engine */
    mmi_vrsi_rcg_close();
}

#define MMI_VRSI_TRAIN_TAG_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_train_status
 * DESCRIPTION
 *  Entry SD tag status screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_train_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 tag_status[256];
    U16 count_list[MMI_VRSI_APP_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_train_util_get_tag_count(count_list);

    memset(tag_status, 0, 2);
    /* mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_TRAIN_TAG_STATUS, count_list[MMI_VRSI_APP_ALL],tag_status); */
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_NAME_LIST, count_list[MMI_VRSI_APP_DIAL], tag_status);
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_SHORTCUT_LIST, count_list[MMI_VRSI_APP_SHORTCUT], tag_status);
    mmi_vrsi_train_tag_status_print_string(STR_ID_VRSI_CITY_LIST, count_list[MMI_VRSI_APP_CITY], tag_status);

    EntryNewScreen(SCR_ID_VRSI_TRAIN_TAG_STATUS, NULL, mmi_vrsi_entry_train_status, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSI_TRAIN_TAG_STATUS);
    ShowCategory7Screen(
        STR_ID_VRSI_TRAIN_TAG_STATUS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) tag_status,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_tag_status_print_string
 * DESCRIPTION
 *  print tag status string.
 * PARAMETERS
 *  str_id          [IN]        
 *  count           [IN]        
 *  tag_status      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 tmpStr[20];
    S8 tmpStr_UCS2[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(tag_status, GetString(str_id));
    memset(tmpStr, 0, 20);

    if (str_id == STR_ID_VRSI_TRAIN_TAG_STATUS)
    {
        sprintf(tmpStr, ": %d/%d\n", count, MMI_VRSI_MAX_SD_TAG);
    }
    else
    {
        sprintf(tmpStr, ": %d\n", count);
    }

    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(tag_status, tmpStr_UCS2);
}

#define MMI_VRSI_TRAIN_TAG_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_id_and_loc
 * DESCRIPTION
 *  Get mapping table data
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 *  tag_id          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_train_util_get_id_and_loc(U8 app_id, U16 tag_long, U16 *tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_TRAIN_GET_ID_LOC, app_id, tag_long, *tag_id);

    if (tag_id != NULL)
    {
        *tag_id = 0xffff;
    }

    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            if (tag_id != NULL)
            {
                *tag_id = tag_list[i].tag_id;
            }

            return i;
        }
    }

    return 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_loc_in_list
 * DESCRIPTION
 *  Get mapping table data
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 *  tag_list        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_train_util_get_loc_in_list(U8 app_id, U16 tag_long, vrsi_sd_tag_struct *tag_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            return i;
        }
    }

    return 0xff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_del_tag
 * DESCRIPTION
 *  Delete SD tag in mapping table
 * PARAMETERS
 *  app_id          [IN]        
 *  tag_long        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_util_del_tag(U8 app_id, U16 tag_long)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U8 has_mapping = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].tag_long == tag_long))
        {
            memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
            has_mapping = 1;
        }
    }

    if (has_mapping)
    {
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_train_util_get_tag_count
 * DESCRIPTION
 *  Get SD tag count
 * PARAMETERS
 *  count_list      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_train_util_get_tag_count(U16 *count_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(count_list, 0, sizeof(U16) * MMI_VRSI_APP_TOTAL);

    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_DIAL]++;
        }
        else if ((tag_list[i].app_id == MMI_VRSI_APP_SHORTCUT) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_SHORTCUT]++;
        }
        else if ((tag_list[i].app_id == MMI_VRSI_APP_CITY) && (tag_list[i].tag_long != 0xffff))
        {
            count_list[MMI_VRSI_APP_CITY]++;
        }
    }

    for (i = 1; i < MMI_VRSI_APP_TOTAL; i++)
    {
        count_list[MMI_VRSI_APP_ALL] += count_list[i];
    }
}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#define MMI_VRSI_DIGIT_ADAPT
#if defined(__MMI_VRSI_DIGIT_ADAPT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_digit_adapt
 * DESCRIPTION
 *  Highlight function for VRSI setting menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsi_digit_adapt_init, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_digit_adapt_init, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_init
 * DESCRIPTION
 *  Init engine for digit adaptation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_init(mmi_vrsi_entry_digit_adapt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_digit_adapt
 * DESCRIPTION
 *  Entry function for digil adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);

    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_VRSI_DIGIT_ADAPT, mmi_vrsi_exit_digit_adapt, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSI_DIGIT_ADAPT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                              /* LSK STR */
        0,                              /* LSK IMG */
        STR_GLOBAL_ABORT,               /* RSK STR */
        0,                              /* RSK IMG */
        STR_ID_VRSI_DIGIT_ADAPT_PROMPT, /* message id */
        0,                              /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_TOTAL;  /* No use here */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NONE;         /* No use here */

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_DIGIT_ADAPT_PROMPT), mmi_vrsi_digit_adapt_start);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_digit_adapt
 * DESCRIPTION
 *  Exit function for digil adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_digit_adapt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_DIGIT_ADAPT_PROMPT)
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_start
 * DESCRIPTION
 *  Start digit adapt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.lang == MED_VRSI_INVALID_LANG)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSI_LANG_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    /* Start Digit Adaptation */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_digit_adapt(MOD_MMI, g_vrsi_cntx.session_id, g_vrsi_cntx.lang);

        if (result == MED_RES_OK)
        {
            return;
        }
    }

    DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_digit_adapt_prompt
 * DESCRIPTION
 *  Entry digit adapt prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_digit_adapt_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length;
    const U16 *str_prompt;  /* pointer to a const U16 string */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_dgt_adp_prompt(&length, &str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_DIGIT_ADAPT_PROMPT, mmi_vrsi_exit_digit_adapt_prompt, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_DIGIT_ADAPT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                  /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    /* Play Prompt Tone and send confirm after prompt */
    mmi_vrsi_rcg_play_prompt_tone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_digit_adapt_prompt
 * DESCRIPTION
 *  Exit digit adapt prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_digit_adapt_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_DIGIT_ADAPT_PROMPT)
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_digit_adapt_result
 * DESCRIPTION
 *  Get digit adapt result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_digit_adapt_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
}
#endif /* defined(__MMI_VRSI_DIGIT_ADAPT__) */ /* #if defined(__MMI_VRSI_DIGIT_ADAPT__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */

#else  /* __MTK_TARGET__ */
#include "CommonScreens.h"
#include "MainMenuDef.h"

void mmi_vrsi_highlight_setting_menu_simulator(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_setting_init
 * DESCRIPTION
 *  init function for VRSI setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_setting_init_simulator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSI_SETTING, mmi_vrsi_highlight_setting_menu_simulator);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_highlight_setting_menu_simulator
 * DESCRIPTION
 *  Highlight function for VRSI setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_highlight_setting_menu_simulator(void)
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

    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#endif /* __MTK_TARGET__ */
#endif /* _MMI_VRSISETTINGS_C */ /* #ifndef _MMI_VRSISETTINGS_C */

