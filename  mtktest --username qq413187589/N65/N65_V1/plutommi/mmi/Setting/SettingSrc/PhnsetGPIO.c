/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * PhnsetGPIO.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for GPIO setting Menus
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
/* MMI standard headers */
#include "MMI_include.h"

/* Setting releative headers */ 
#include "SettingDefs.h"
#include "PhnsetGPIO.h"

/* Device headers */
#include "gpioinc.h"
#include "lcd_if.h"

/* UI */
#include "MainMenuDef.h"              
#include "CommonScreens.h"
#include "IdleAppDef.h"

/* nvram access */
#include "custom_mmi_default_value.h" 

/* Others */
#include "SimDetectionGexdcl.h"       /* power on mode */

#include "custom_equipment.h"

/***************************************************************************** 
* Local Functions
*****************************************************************************/
void PhnsetContrastLevelEndHdlr(void);
MMI_BOOL PhnsetRestoreToNvramContrast(void);
void PhnsetMainLCDContrast(U8 level);
void PhnsetSubLCDContrast(U8 level);


/***************************************************************************** 
* Local Varibles
*****************************************************************************/
static mmi_phnset_gpio_cntx_struct g_phnset_gpio_cntx;

static kal_uint8 PhnsetMainLCD_Contrast_Info[15];

#if defined(__MMI_SUBLCD__)
static kal_uint8 PhnsetSubLCD_Contrast_Info[15];
#endif 

/***************************************************************************** 
* Global Varibles
*****************************************************************************/
mmi_phnset_gpio_cntx_struct *g_phnset_gpio_cntx_p = &g_phnset_gpio_cntx;

/*****************************************************************************
 * FUNCTION
 *  InitPhoneSetupGPIO
 * DESCRIPTION
 *  This function is to register highlight handler for Phonesetup GPIO
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void InitPhoneSetupGPIO(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_NO_CONTRAST_LEVEL__)
    SetHiliteHandler(MENU_SETTING_CONTRAST_LEVEL, HighlightPhnsetContrastLevel);
#endif 

    SetHiliteHandler(MENU_ID_PHNSET_GPIO_SETTING, HighlightPhnsetGPIOSetting);

#if !defined(HARDWARE_LED_NOT_SUPPORT)
    SetHiliteHandler(MENU_ID_PHNSET_GPIO_LED, HighlightPhnsetGPIOLED);

    SetHintHandler(MENU_ID_PHNSET_GPIO_LED, HintPhnsetGPIOLED);
#endif

    SetHiliteHandler(MENU_ID_PHNSET_GPIO_BACKLITE, HighlightPhnsetGPIOBackLite);
#ifdef __MMI_COVER_SETTING__
    SetHiliteHandler(MENU_ID_PHNSET_GPIO_COVER_CLOSE, HighlightPhnsetGPIOCover);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReadGPIOSetting
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadGPIOSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOnMode != POWER_ON_USB)
    {
        ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
        if (g_phnset_gpio_cntx_p->bl_setting_level > 5)
        {
        #if !defined(__MTK_TARGET__)
            g_phnset_gpio_cntx_p->bl_setting_level = 5;
        #else 
            g_phnset_gpio_cntx_p->bl_setting_level = 3;
        #endif 
            WriteValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
        }

        ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_BYTE, &error);
        if (g_phnset_gpio_cntx_p->bl_setting_hftime < 5 || g_phnset_gpio_cntx_p->bl_setting_hftime > 60)
        {
            g_phnset_gpio_cntx_p->bl_setting_hftime = 45;
            WriteValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_BYTE, &error);
        }
        ReadValue(NVRAM_BYTE_LED_SETTING, &(g_phnset_gpio_cntx_p->led_setting), DS_BYTE, &error);
        if (g_phnset_gpio_cntx_p->led_setting != 0 && g_phnset_gpio_cntx_p->led_setting != 1)
        {
            /* default value = Off */
            g_phnset_gpio_cntx_p->led_setting = 0;
            WriteValue(NVRAM_BYTE_LED_SETTING, &(g_phnset_gpio_cntx_p->led_setting), DS_BYTE, &error);
        }
    #ifdef __MMI_PHNSET_GPIO_COVER__
        ReadValue(NVRAM_BYTE_COVER_CLOSE_BACK_TO_IDLE, &(g_phnset_gpio_cntx_p->cover_close_back_to_idle), DS_BYTE, &error);
        ReadValue(NVRAM_BYTE_COVER_CLOSE_REJECT_CALL, &(g_phnset_gpio_cntx_p->cover_close_reject_call), DS_BYTE, &error);
        ReadValue(NVRAM_BYTE_COVER_CLOSE_KEYPAD_LOCK, &(g_phnset_gpio_cntx_p->cover_close_keypad_lock), DS_BYTE, &error);
        g_phnset_gpio_cntx_p->cover_close_back_to_idle &= 0x01;
        g_phnset_gpio_cntx_p->cover_close_reject_call &= 0x01;
        g_phnset_gpio_cntx_p->cover_close_keypad_lock &= 0x01;
    #endif /* __MMI_PHNSET_GPIO_COVER__ */
    }
    else
    {
        g_phnset_gpio_cntx_p->bl_setting_level = 3;
        g_phnset_gpio_cntx_p->bl_setting_hftime = 45;
        g_phnset_gpio_cntx_p->led_setting = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetGPIOSetting
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetGPIOSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *ItemType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_PHNSET_GPIO_SETTING, NULL, EntryPhnsetGPIOSetting, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHNSET_GPIO_SETTING);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_PHNSET_GPIO_SETTING);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_PHNSET_GPIO_SETTING);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_PHNSET_GPIO_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_PHNSET_GPIO_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_ID_PHNSET_GPIO_SETTING, ItemType);

    ShowCategory52Screen(
        STR_ID_PHNSET_GPIO_SETTING,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        ItemType,
        0,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* 10. Register Exit handler */
    //SetExitHandler(SCR9003_INITIALSETUP, ExitPhnsetScr);
    //SetGenericExitHandler( SCR_DISP_SETUP, NULL, EntryDispSetup);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetBackLiteLevel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetBackLiteLevel(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (index > 0 && index <= 5)
    {
        g_phnset_gpio_cntx_p->bl_setting_level = index;
        SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetBackLiteHFTime
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> Contrast -> SubLCD
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetBackLiteHFTime(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 5 && index <= 60)
    {
        g_phnset_gpio_cntx_p->bl_setting_hftime = index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteEndHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOBackLiteEndHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);

    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_BYTE, &error);

    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteLSKHdlr
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOBackLiteLSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &data, DS_BYTE, &error);
    if (data != g_phnset_gpio_cntx_p->bl_setting_level)
    {
        WriteValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &data, DS_BYTE, &error);
    if (data != g_phnset_gpio_cntx_p->bl_setting_hftime)
    {
        WriteValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_BYTE, &error);
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_PHNSET_GPIO_BACKLITE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOBackLiteRSKHdlr
 * DESCRIPTION
 *  This function is Right softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOBackLiteRSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &g_phnset_gpio_cntx_p->bl_setting_level, DS_BYTE, &error);
    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &g_phnset_gpio_cntx_p->bl_setting_hftime, DS_BYTE, &error);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetGPIOBackLite
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetGPIOBackLite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_BL_SETTING_LEVEL, &(g_phnset_gpio_cntx_p->bl_setting_level), DS_BYTE, &error);
    SetGPIOLevelReq(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);

    ReadValue(NVRAM_BYTE_BL_SETTING_HFTIME, &(g_phnset_gpio_cntx_p->bl_setting_hftime), DS_BYTE, &error);

}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetGPIOBackLite
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetGPIOBackLite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *BLHFTime = NULL, *BLLevel = NULL;

#ifdef __MMI_GPIO_SUPPORT_BL_LEVEL__
    S32 lower_limit[1];
    S32 upper_limit[1];
    S32 *current_value[1];
    void (*cb_func[1]) (S32 value);
#else /* __MMI_GPIO_SUPPORT_BL_LEVEL__ */ 
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];
#endif /* __MMI_GPIO_SUPPORT_BL_LEVEL__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_ID_PHNSET_GPIO_BACKLITE, ExitPhnsetGPIOBackLite, EntryPhnsetGPIOBackLite, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHNSET_GPIO_BACKLITE);

    BLLevel = (U8*) GetString(STR_ID_PHNSET_GPIO_BACKLITE_LEVEL);
    BLHFTime = (U8*) GetString(STR_ID_PHNSET_GPIO_BACKLITE_HF_TIME);
    /* Set current parent id */
    SetParentHandler(MENU_ID_PHNSET_GPIO_BACKLITE);
#ifdef __MMI_GPIO_SUPPORT_BL_LEVEL__

    lower_limit[0] = 5;
    upper_limit[0] = 60;
    current_value[0] = & (g_phnset_gpio_cntx_p->bl_setting_hftime);
    cb_func[0] = HighlightPhnsetBackLiteHFTime;
    ShowCategory88Screen(
        STR_ID_PHNSET_GPIO_BACKLITE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        0,
        1,
        NULL,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);
#else /* __MMI_GPIO_SUPPORT_BL_LEVEL__ */ 

    lower_limit[0] = 1;
    upper_limit[0] = 5;
    current_value[0] = &(g_phnset_gpio_cntx_p->bl_setting_level);
    cb_func[0] = HighlightPhnsetBackLiteLevel;
    str_list[0] = BLLevel;

    lower_limit[1] = 5;
    upper_limit[1] = 60;
    current_value[1] = (S32 *)&(g_phnset_gpio_cntx_p->bl_setting_hftime);
    cb_func[1] = HighlightPhnsetBackLiteHFTime;
    str_list[1] = BLHFTime;

    ShowCategory88Screen(
        STR_ID_PHNSET_GPIO_BACKLITE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);
#endif /* __MMI_GPIO_SUPPORT_BL_LEVEL__ */ 

    /* Register function with right softkey */
    SetKeyHandler(PhnsetGPIOBackLiteEndHdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(PhnsetGPIOBackLiteLSKHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(PhnsetGPIOBackLiteRSKHdlr, KEY_EVENT_UP);

}


#ifdef __MMI_PHNSET_GPIO_COVER__


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverLSKHdlr
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOCoverLSKHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BYTE_COVER_CLOSE_BACK_TO_IDLE, &(g_phnset_gpio_cntx_p->cover_close_back_to_idle), DS_BYTE, &error);
    WriteValue(NVRAM_BYTE_COVER_CLOSE_REJECT_CALL, &(g_phnset_gpio_cntx_p->cover_close_reject_call), DS_BYTE, &error);
    WriteValue(NVRAM_BYTE_COVER_CLOSE_KEYPAD_LOCK, &(g_phnset_gpio_cntx_p->cover_close_keypad_lock), DS_BYTE, &error);
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_PHNSET_GPIO_COVER_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverFillInline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  InLineItems     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOCoverFillInline(InlineItem *InLineItems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&InLineItems[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&InLineItems[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&InLineItems[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_ON] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_OFF] = (PU8) GetString(STR_GLOBAL_ON);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_REJECT_CALL);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_YES] = (PU8) GetString(STR_GLOBAL_YES);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_NO] = (PU8) GetString(STR_GLOBAL_NO);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_TITLE] =
        (PU8) GetString(STR_ID_PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_ON] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_OFF] = (PU8) GetString(STR_GLOBAL_ON);

    SetInlineItemCaption(&InLineItems[0], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_TITLE]);
    SetInlineItemSelect(
        &InLineItems[1],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_BACK_TO_IDLE_ON],
        &(g_phnset_gpio_cntx_p->cover_close_back_to_idle));
    SetInlineItemCaption(&InLineItems[2], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_TITLE]);
    SetInlineItemSelect(
        &InLineItems[3],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_REJECT_CALL_YES],
        &(g_phnset_gpio_cntx_p->cover_close_reject_call));
    SetInlineItemCaption(&InLineItems[4], subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_TITLE]);
    SetInlineItemSelect(
        &InLineItems[5],
        2,
        &subMenuDataPtrs[PHNSET_GPIO_COVER_CLOSE_KEYPAD_LOCK_ON],
        &(g_phnset_gpio_cntx_p->cover_close_keypad_lock));
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGPIOCoverInlineHiliteHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetGPIOCoverInlineHiliteHdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(PhnsetGPIOCoverLSKHdlr);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetGPIOCover
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetGPIOCover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 icons[6] = {IMG_SETTING_GREET_TEXT, 0, IMG_SETTING_GREET_TEXT, 0, IMG_SETTING_GREET_TEXT, 0};
    InlineItem InLineItems[6];
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHNSET_GPIO_COVER_CLOSE, NULL, EntryPhnsetGPIOCover, NULL);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHNSET_GPIO_COVER_CLOSE);
    memset((void*)InLineItems, 0, sizeof(InlineItem) * 6);

    PhnsetGPIOCoverFillInline(InLineItems);

    SetLeftSoftkeyFunction(PhnsetGPIOCoverLSKHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterHighlightHandler(PhnsetGPIOCoverInlineHiliteHdlr);
    /* added for inline edit history */
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PHNSET_GPIO_COVER_CLOSE, &inputBufferSize);

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(InLineItems, 6, inputBuffer); /* sets the data */
    }

    ShowCategory57Screen(
        STR_ID_PHNSET_GPIO_COVER_CLOSE,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        icons,
        InLineItems,
        0,
        guiBuffer);
    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(PhnsetGPIOCoverLSKHdlr, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetGPIOCover
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetGPIOCover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryPhnsetGPIOCover, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetGPIOCover, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#endif /* __MMI_PHNSET_GPIO_COVER__ */


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetGPIOSetting
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetGPIOSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryPhnsetGPIOSetting, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetGPIOSetting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


#if !defined(HARDWARE_LED_NOT_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetGPIOLED
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetGPIOLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    index = GetCurrHiliteID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_gpio_cntx_p->led_setting == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryPhnsetGPIOLED, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetGPIOLED
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetGPIOLED(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_gpio_cntx_p->led_setting == 1)
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
 *  EntryPhnsetGPIOLED
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetGPIOLED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    index = GetCurrHiliteID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != POPUP_SCREENID)
    {
        S16 error;

        if (g_phnset_gpio_cntx_p->led_setting)
        {
            g_phnset_gpio_cntx_p->led_setting = 0;
            StopLEDPatternBackGround();
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_OFF),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            Category52ChangeItemDescription(index, hintData[index]);
        }
        else
        {
            g_phnset_gpio_cntx_p->led_setting = 1;
            StartLEDPatternBackGround();
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ON),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
            Category52ChangeItemDescription(index, hintData[index]);
        }
        WriteValue(NVRAM_BYTE_LED_SETTING, &(g_phnset_gpio_cntx_p->led_setting), DS_BYTE, &error);
    }

}
#endif /* HARDWARE_LED_NOT_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetGPIOBackLite
 * DESCRIPTION
 *  ...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetGPIOBackLite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryPhnsetGPIOBackLite, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetGPIOBackLite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#if !defined(__MMI_NO_CONTRAST_LEVEL__)


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetContrastLevel
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> Contrast
 *  Follow functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetContrastLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPhnsetContrastLevel, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetContrastLevel, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetContrastLevel
 * DESCRIPTION
 *  This function is Entry function for Phonesetup-> Contrast
 *  Following functions: PhnsetContrastLevelEndHdlr, PhnsetContrastLevelLskHdlr,
 *  HighlightPhnsetContrastLevelMain, HighlightPhnsetContrastLevelSub
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetContrastLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *MainLcd = NULL, *SubLcd = NULL; /* Buffer holding history data */

#ifdef __MMI_SUBLCD__
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];

#else /* __MMI_SUBLCD__ */ 
    S32 lower_limit[1];
    S32 upper_limit[1];
    S32 *current_value[1];
    void (*cb_func[1]) (S32 value);
#endif /* __MMI_SUBLCD__ */ 

    /* Call Exit Handler */
    EntryNewScreen(SCR_SETTING_CONTRAST_LEVEL, NULL, EntryPhnsetContrastLevel, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_CONTRAST_LEVEL);

    SubLcd = (U8*) GetString(STR_SETTING_SUB_LCD);
    MainLcd = (U8*) GetString(STR_SETTING_MAIN_LCD);

    /* Set current parent id */
    SetParentHandler(MENU_SETTING_CONTRAST_LEVEL);

#ifdef __MMI_SUBLCD__

    lower_limit[0] = 1;
    upper_limit[0] = 15;
    current_value[0] = &(g_phnset_gpio_cntx_p->MainCntrst);
    cb_func[0] = HighlightPhnsetContrastLevelMain;
    str_list[0] = MainLcd;

    lower_limit[1] = 1;
    upper_limit[1] = 15;
    current_value[1] = &(g_phnset_gpio_cntx_p->SubCntrst);
    cb_func[1] = HighlightPhnsetContrastLevelSub;
    str_list[1] = SubLcd;

    ShowCategory88Screen(
        STR_MENU_SETTING_CONTRAST_LEVEL,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);
#else /* __MMI_SUBLCD__ */ 
    lower_limit[0] = 1;
    upper_limit[0] = 15;
    if (g_phnset_gpio_cntx_p->MainCntrst == 255)
    {
        g_phnset_gpio_cntx_p->MainCntrst = 1;
    }
    current_value[0] = (S32*) & g_phnset_gpio_cntx_p->MainCntrst;
    cb_func[0] = HighlightPhnsetContrastLevelMain;
    ShowCategory88Screen(
        STR_MENU_SETTING_CONTRAST_LEVEL,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        0,
        IMG_CONTRAST_BACKGROUND,
        1,
        NULL,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);
#endif /* __MMI_SUBLCD__ */ 

    /* Register function with right softkey */
    SetKeyHandler(PhnsetContrastLevelEndHdlr, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(PhnsetContrastLevelLskHdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(PhnsetContrastLevelRskHdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetContrastLevelRskHdlr
 * DESCRIPTION
 *  This function is RSK key handler for Phonesetup-> Constract
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetContrastLevelRskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetRestoreToNvramContrast();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetContrastLevelEndHdlr
 * DESCRIPTION
 *  This function is END key handler for Phonesetup-> Constract
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetContrastLevelEndHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetRestoreToNvramContrast();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetContrastLevelMain
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> Contrast -> MainLCD
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetContrastLevelMain(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > 0 && index <= 15)
    {
        g_phnset_gpio_cntx_p->MainCntrst = index;
        PhnsetMainLCDContrast((U8) index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetContrastLevelSub
 * DESCRIPTION
 *  This function is highlight handler for Phonesetup-> Contrast -> SubLCD
 *  Follow functions:
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void HighlightPhnsetContrastLevelSub(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > 0 && index <= 15)
    {
        g_phnset_gpio_cntx_p->SubCntrst = index;
        PhnsetSubLCDContrast(index);
    }
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetContrastLevelLskHdlr
 * DESCRIPTION
 *  This function is Left softkey handler
 *  for Phonesetup->Constract -> Main/Sub LCD
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetContrastLevelLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_CONTRAST_LEVEL, &data, DS_BYTE, &error);
    if (data != g_phnset_gpio_cntx_p->MainCntrst)
    {
        WriteValue(NVRAM_SETTING_CONTRAST_LEVEL, &(g_phnset_gpio_cntx_p->MainCntrst), DS_BYTE, &error);
    }

#ifdef __MMI_SUBLCD__
    ReadValue(NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL, &data, DS_BYTE, &error);
    if (data != g_phnset_gpio_cntx_p->SubCntrst)
    {
        WriteValue(NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL, &(g_phnset_gpio_cntx_p->SubCntrst), DS_BYTE, &error);
    }
#endif /* __MMI_SUBLCD__ */ 

    GoBackHistory();
}
#endif /* !defined(__MMI_NO_CONTRAST_LEVEL__) */ /* #if !defined(__MMI_NO_CONTRAST_LEVEL__) */


/*****************************************************************************
 * FUNCTION
 *  PhnsetHWLCDContrastInfoRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Rsp_Msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHWLCDContrastInfoRsp(void *Rsp_Msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_eq_get_hw_level_rsp_struct *rsp_p = Rsp_Msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 15; i++)
    {
        PhnsetMainLCD_Contrast_Info[i] = rsp_p->hw_profile.MainLCD_Contrast_Level_Info[i];
    }

    PhnsetMainLCDContrast(g_phnset_gpio_cntx_p->MainCntrst);

#ifdef __MMI_SUBLCD__
    for (i = 0; i < 15; i++)
    {
        PhnsetSubLCD_Contrast_Info[i] = rsp_p->hw_profile.SubLCD_Contrast_Level_Info[i];
    }

    PhnsetSubLCDContrast(g_phnset_gpio_cntx_p->SubCntrst);
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetRestoreToNvramContrast
 * DESCRIPTION
 *  Set Contrast Level From Stored Values
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
MMI_BOOL PhnsetRestoreToNvramContrast(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data = 0;
    ilm_struct *ilm_ptr = NULL;
    l4c_hw_profile_struct *dst_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(PhnsetHWLCDContrastInfoRsp, MSG_ID_MMI_EQ_GET_HW_LEVEL_RSP);

    ReadValue(NVRAM_SETTING_CONTRAST_LEVEL, &data, DS_BYTE, &error);
    g_phnset_gpio_cntx_p->MainCntrst = data;

#ifdef __MMI_SUBLCD__
    data = 0;
    ReadValue(NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL, &data, DS_BYTE, &error);
    g_phnset_gpio_cntx_p->SubCntrst = data;
#endif /* __MMI_SUBLCD__ */ 

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_EQ_GET_HW_LEVEL_REQ;        /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;

    dst_data_ptr = (l4c_hw_profile_struct*) construct_local_para(sizeof(l4c_hw_profile_struct), TD_CTRL);

    ilm_ptr->local_para_ptr = (local_para_struct*) dst_data_ptr;

    msg_send_ext_queue(ilm_ptr);

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetChangeMainLCDContrastValue
 * DESCRIPTION
 *  This function is to set  main LCD contrast in phone setup context
 *  Functionality:
 * PARAMETERS
 *  level       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetChangeMainLCDContrastValue(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_gpio_cntx_p->MainCntrst = level;
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  PhnsetChangeSubLCDContrastValue
 * DESCRIPTION
 *  This function is to set  sub LCD contrast in phone setup context
 *  Functionality:
 * PARAMETERS
 *  level       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetChangeSubLCDContrastValue(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_gpio_cntx_p->SubCntrst = level;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetMainLCDContrast
 * DESCRIPTION
 *  This function is to set main LCD contrast
 *  Functionality:
 * PARAMETERS
 *  level       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetMainLCDContrast(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (level > 15 || level < 1)
    {
        return;
    }

#if !defined(__MMI_NO_CONTRAST_LEVEL__)
    lcd_bright_level(MAIN_LCD, PhnsetMainLCD_Contrast_Info[level - 1]);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSubLCDContrast
 * DESCRIPTION
 *  This function is to set sub LCD contrast
 *  Functionality:
 * PARAMETERS
 *  level       [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSubLCDContrast(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (level > 15 || level < 1)
    {
        return;
    }

#if defined(__MMI_SUBLCD__) 
    lcd_bright_level(SUB_LCD, PhnsetSubLCD_Contrast_Info[level - 1]);
#endif 
}

