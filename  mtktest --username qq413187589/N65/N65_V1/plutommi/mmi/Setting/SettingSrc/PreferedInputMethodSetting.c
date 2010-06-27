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
 *  PreferedInputMethodSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************** Settings Application implementation *********************/

/**************************************************************

    FILENAME    : PreferedInputMethodSetting.c

    PURPOSE     : PreferedInputMethod application

    REMARKS     : Elvis

    AUTHOR      : Elvis

    DATE        : 21 Oct 2003 (Taipei)

**************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PREFER_INPUT_METHOD__
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MainMenuDef.h"
#include "settinggprots.h"
#include "SettingsGexdcl.h"
#include "SettingProfile.h"
#include "SettingProt.h"
#include "SettingDefs.h"
#include "PreferedInputMethodProt.h"
#include "PhoneSetupGprots.h"
#include "CommonScreens.h"
/* __CUSTPACK_MULTIBIN     Terry   BEGIN */

extern const sIMEModeDetails *gIMEModeArray;
U16 MMI_all_prefered_input_mode_set[INPUT_MODE_MAX_NUM] = {0xffff};
U8 *inputMethodList[INPUT_MODE_MAX_NUM];

/* W05.34 Fix Compile Warning */
static U16 gnInputMethods = 0;
U16 currInputMethodIndex = 0;

extern S16 MMI_prefered_input_type;

/* __CUSTPACK_MULTIBIN     Terry   END */

//extern void DisplayPopup(U8 * string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);
// __CUSTPACK_MULTIBIN     Terry   BEGIN


/*****************************************************************************
 * FUNCTION
 *  InitPreferedInputMethod
 * DESCRIPTION
 *  initialization function for input method screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPreferedInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        if (((0xff) != gIMEModeArray[i].IME_Mode_ID) && (0 != gIMEModeArray[i].Prefered_IMEStringID))
        {
            inputMethodList[i] = (U8*) GetString(gIMEModeArray[i].Prefered_IMEStringID);
            i++;
        }
        else
        {
            break;
        }
    }
    gnInputMethods = i;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInputMehtodSetting
 * DESCRIPTION
 *  highlight handler for input method selection
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInputMehtodSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryScrPreferedInputMethodList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set the left/right arrow key function handlers */
    SetKeyHandler(EntryScrPreferedInputMethodList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrPreferedInputMethodList
 * DESCRIPTION
 *  Entry function for input method screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrPreferedInputMethodList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitPreferedInputMethod();
#if !defined(__MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__)
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != MMI_prefered_input_type)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    currInputMethodIndex = i;
#endif /* !defined(__MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__) */ 

    /* Call Exit Handler */
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_INPUT_METHOD_SELECTION, ExitInputMethodSelectScreen, NULL, NULL);
    /* Get current screen info into gui buffer  for history purposes */
    pGuiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_SELECTION);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(HighlightCurrentInputMethod);
    /* Display Screen */
    ShowCategory36Screen(
        STR_MENU_INPUT_METHOD,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        gnInputMethods,
        (U8 **) inputMethodList,
        currInputMethodIndex,
        pGuiBuffer);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(SelectInputMethodHandler, KEY_EVENT_UP);
    /* Register function with left/right arrow key */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register Exit handler */
    /* SetExitHandler(SCR_INPUT_METHOD_SELECTION, ExitInputMethodSelectScreen); */
    return;
}

/* __CUSTPACK_MULTIBIN     Terry   END */


/*****************************************************************************
 * FUNCTION
 *  HighlightCurrentInputMethod
 * DESCRIPTION
 *  upate selected index
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCurrentInputMethod(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* upate selected index */
    currInputMethodIndex = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SelectInputMethodHandler
 * DESCRIPTION
 *  Exit function for input method screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelectInputMethodHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data;
    S16 error;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    SetInputMethod(currInputMethodIndex);
    data = MMI_prefered_input_type;
    WriteValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &data, DS_SHORT, &error);
    mmi_ucs2cpy((PS8) hintData[index], (PS8) inputMethodList[currInputMethodIndex]);
    Category52ChangeItemDescription(index, hintData[index]);
#if defined(__MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__)
    if (mmi_phnset_2line_is_exist())
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
#endif /* defined(__MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__) */ 
    {
        RedrawCategoryFunction();
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        DeleteNHistory(1);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitInputMethodSelectScreen
 * DESCRIPTION
 *  Exit function for input method screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInputMethodSelectScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* getting details of the current screen (to be added to history) */
    Scr.scrnID = SCR_INPUT_METHOD_SELECTION;
    Scr.entryFuncPtr = EntryScrPreferedInputMethodList;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    /* add the screen to history */
    AddHistory(Scr);
    return;
}

/* __CUSTPACK_MULTIBIN     Terry   BEGIN */


/*****************************************************************************
 * FUNCTION
 *  SetInputMethod
 * DESCRIPTION
 *  Set input method
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetInputMethod(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < INPUT_MODE_MAX_NUM)
    {
        MMI_prefered_input_type = MMI_all_prefered_input_mode_set[index];
    }
    else
    {
        MMI_prefered_input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetInputMethodFromNVRAM
 * DESCRIPTION
 *  Retrive input method type from nvram and set.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetInputMethodFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 data = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive input method type from nvram */
    ReadValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &data, DS_SHORT, &error);
    if (data == 0xFF || error != NVRAM_READ_SUCCESS)
    {
        data = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
        WriteValue(NVRAM_SETTING_PREFER_INPUT_METHOD, &data, DS_SHORT, &error);
    }
    /* check the input type */
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != data)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    currInputMethodIndex = i;

    /* set input method with current input method */
    SetInputMethod(currInputMethodIndex);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetInputMethodType
 * DESCRIPTION
 *  Entry function for call barring result screen
 * NA
 *  
 * PARAMETERS
 *  inputType       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetInputMethodType(U16 inputType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != inputType)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    currInputMethodIndex = i;

    SetInputMethod(currInputMethodIndex);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetInputMethodIndex
 * DESCRIPTION
 *  function that return input method index
 * NA
 *  
 * PARAMETERS
 *  inputType       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetInputMethodIndex(U16 inputType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (MMI_all_prefered_input_mode_set[i] != inputType)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }

    }
    return i;
}

#ifdef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_current_preferr_input
 * DESCRIPTION
 *  This function returns the number of prefered input items
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_phnset_get_current_preferr_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currInputMethodIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_2line_prfr_input_get_total_items
 * DESCRIPTION
 *  This function returns the number of prefered input items
 * PARAMETERS
 *  set_default_value       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_phnset_2line_prfr_input_get_total_items(S32 set_default_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitPreferedInputMethod();
    while (MMI_all_prefered_input_mode_set[i] != MMI_prefered_input_type)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }
    }
    if (set_default_value)
    {
        currInputMethodIndex = i;
    }
    return gnInputMethods;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_2line_prfr_input_get_data
 * DESCRIPTION
 *  This function is called when prefered input menuitem is highlighted
 * PARAMETERS
 *  item_index      [IN]        Index of the inline item to be shown
 *  str_buff        [IN]        Preferred input type string to be shown
 *  img_buff_p      [IN]        Image to be shown with the inline item
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_phnset_2line_prfr_input_get_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currInputMethodIndex = (U8) item_index;
    mmi_ucs2cpy((PS8) str_buff, (PS8) inputMethodList[item_index]);
    if (item_index < IMG_GLOBAL_LEND - IMG_GLOBAL_LSTART - 1)
    {
        *img_buff_p = get_image((U16) (IMG_GLOBAL_LSTART + item_index + 1));
    }
    else
    {
        *img_buff_p = NULL;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_2line_prfr_input_complete_callback
 * DESCRIPTION
 *  This function is called when prefered input menuitem is unhighlighted
 * PARAMETERS
 *  item_index          [IN]        Menuitem index
 *  selected_index      [IN]        Inline item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_2line_prfr_input_complete_callback(S32 item_index, S32 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (MMI_all_prefered_input_mode_set[i] != MMI_prefered_input_type)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }
    }
    currInputMethodIndex = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_2line_prfr_input_get_default
 * DESCRIPTION
 *  This function is called to get the default value for prefered input menuitem
 * PARAMETERS
 *  item_index      [IN]        Menuitem index
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_phnset_2line_prfr_input_get_default(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return currInputMethodIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_2line_prfr_input_set_default
 * DESCRIPTION
 *  This function is called to set the value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_2line_prfr_input_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (MMI_all_prefered_input_mode_set[i] != MMI_prefered_input_type)
    {
        if (MMI_all_prefered_input_mode_set[i] == 0xffff)
        {
            i = 0;
            break;
        }
        else
        {
            i++;
        }
    }
    currInputMethodIndex = i;
}
#endif /* __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__ */ 
/* __CUSTPACK_MULTIBIN     Terry   END */
#endif /* __MMI_PREFER_INPUT_METHOD__ */ 
/*********************************************END OF FILE *************************************/

