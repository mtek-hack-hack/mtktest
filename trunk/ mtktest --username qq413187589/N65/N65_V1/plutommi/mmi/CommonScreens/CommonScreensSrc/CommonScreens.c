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
 *    commonscreens.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   for input method menu and symbol picker screen
 *
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
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CommonScreens.c

   PURPOSE     : Common screens used by applications

   REMARKS     :

   AUTHOR      : manju

   DATE     : Aug-06-2003

**************************************************************/

#include "MMI_include.h"
/* MTK Leo add */
/* MTK Leo end */
#include "CommonScreens.h"
#include "ProfileGprots.h"

/* START VIJAY PMT 20050725 */
#include "gui_ems.h"
/*PMT IRE START*/
#if defined (__MMI_INDIC_ALG__)
#include "IndicEngineGprot.h"
#endif
/*PMT IRE END*/
//END VIJAY PMT 20050725
// __CUSTPACK_MULTIBIN     Terry   BEGIN
extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;

/* __CUSTPACK_MULTIBIN     Terry   END */


extern void leave_full_screen(void);
extern BOOL IsMyTimerExist(U16 nTimerId);
void (*InputMethodScreenCloseFunction) (void) = UI_dummy_function;
void (*SavedInputMethodScreenCloseFunction) (void) = UI_dummy_function;
void (*InputMethodScreenEntryCallback) (void) = UI_dummy_function;
void (*InputMethodScreenExitCallback) (void) = UI_dummy_function;
void (*SymbolTableScreenEntryCallback) (void) = UI_dummy_function;
void (*SymbolTableScreenExitCallback) (void) = UI_dummy_function;
S16 saved_MMI_current_input_type = 0;
U16 gInputMethodAndDoneCaptionIcon = 0;
extern void goto_demo_under_construction(void);
extern S16 MMI_current_input_type;
static U8 is_popup_allow = POPUP_ALL_ON;    /* it can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON, or POPUP_ALL_ON */
extern U8 wgui_map_inputmode_to_inputtype(S32 input_mode, const sIMEModeDetails *IMEModeArray);
/*PMT IRE START*/
extern mmi_editor_inoutbox_enum MMI_current_input_box_type;
/*PMT IRE END*/
/* MTK elvis */
#ifdef __MMI_T9__
extern void T9SynT9WithInputBox(void);
#elif defined __MMI_ZI__
extern void ZiDisplay(void);
#elif defined __MMI_CSTAR__
extern void CstarDisplay(void);
#elif defined __MMI_KA__
extern void KonkaDisplay(void);
#elif defined __MMI_ITAP__
/* under construction !*/
#endif 

extern void TurnOnBacklight(U8 TimerFlag);  /* 042505 Calvin added */

/* MTK end */
U8 popupToneId = 0; /* 121605 popup tone Calvin */
#define NUMBER_OF_INPUT_METHODS  INPUT_MODE_MAX_NUM


// flag to record if the input box is INPUT_TYPE_ALPHANUMERIC_PASSWORD
extern MMI_BOOL mmi_is_alphanum_pass;

extern U8 wgui_singleline_inputbox_input_mode_changed;
extern U8 wgui_singleline_inputbox_input_type;

const U16 gIndexIconsImageList[] = 
{
    IMG_GLOBAL_L1,
    IMG_GLOBAL_L2,
    IMG_GLOBAL_L3,
    IMG_GLOBAL_L4,
    IMG_GLOBAL_L5,
    IMG_GLOBAL_L6,
    IMG_GLOBAL_L7,
    IMG_GLOBAL_L8,
    IMG_GLOBAL_L9,
    IMG_GLOBAL_L10,
    IMG_GLOBAL_L11,
    IMG_GLOBAL_L12,
    IMG_GLOBAL_L13,
    IMG_GLOBAL_L14,
    IMG_GLOBAL_L15,
    IMG_GLOBAL_L16,
    IMG_GLOBAL_L17,
    IMG_GLOBAL_L18,
    IMG_GLOBAL_L19,
    IMG_GLOBAL_L20,
    IMG_GLOBAL_L21,
    IMG_GLOBAL_L22,
    IMG_GLOBAL_L23,
    IMG_GLOBAL_L24,
    IMG_GLOBAL_L25,
    IMG_GLOBAL_L26,
    IMG_GLOBAL_L27,
    IMG_GLOBAL_L28,
    IMG_GLOBAL_L29,
    IMG_GLOBAL_L30
};

/* MTK Terry : Multitap for Star and Pound */


extern void (*wgui_inline_edit_DONE_function) (void);
void (*wgui_common_screen_inline_edit_DONE_function) (void);
void mmi_frm_go_back_2_history(void);
S32 InputMethodSetKeyHandler(const sIMEModeDetails *IMEModeArray, MMI_BOOL EnglishOnly, MMI_BOOL AP_required, S32 index);

/*****************************************************************************
 * FUNCTION
 *  HighlightInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInLineMultilineEditorOption(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nIndex)
    {
        case 0:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(wgui_common_screen_inline_edit_DONE_function, KEY_EVENT_UP);
            SetKeyHandler(wgui_common_screen_inline_edit_DONE_function, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        case 1:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
            SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            RegisterInputMethodScreenCloseFunction(mmi_frm_go_back_2_history);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInLineMultilineEditorOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[2];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_edit_DONE_function)
    {
        wgui_common_screen_inline_edit_DONE_function = wgui_inline_edit_DONE_function;
    }
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE, ExitInLineMultilineEditorOption, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(HighlightInLineMultilineEditorOption);

    /* 8 Display Category Screen */
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        gInputMethodAndDoneCaptionIcon,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* 10. Register Exit handler */
}


/*****************************************************************************
 * FUNCTION
 *  ExitInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInLineMultilineEditorOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE;
    currHistory.entryFuncPtr = EntryInLineMultilineEditorOption;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  QuickSearchInputMethodSetKeyHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  preFuncPtrs             [?]         
 *  postPtrs                [?]         
 *  IMEQSearchModeArray     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 QuickSearchInputMethodSetKeyHandler(
        FuncPtr *preFuncPtrs,
        FuncPtr *postPtrs,
        const sIMEModeDetails *IMEQSearchModeArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  QuickSearchInputMethodScreenHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void QuickSearchInputMethodScreenHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = 0;
    U8 input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis multitap phonetic input mode */
    input_mode = InputMethodSetKeyHandler(
            gIMEQSearchModeArray,
            MMI_FALSE,
            MMI_FALSE,
            index);
    if (input_mode == -1)
    {
        // index should be check
#if !defined(__MMI_TOUCH_SCREEN__)
        EntrySymbolPickerScreenFromMenuList();
        UI_dummy_function();
#endif
    }
    else
    {
        input_type = wgui_map_inputmode_to_inputtype(input_mode, gIMEQSearchModeArray);
        wgui_change_inputbox_type(input_type);
        InputMethodScreenCloseFunction();
    }

}


/*****************************************************************************
 * FUNCTION
 *  QuickSearchInputMethodScreenHandleRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void QuickSearchInputMethodScreenHandleRSK(void)
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
 *  EntryQuickSearchInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryQuickSearchInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    int nNumofItem = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*LSK_handler) (void);
    U16 nStrItemList[INPUT_MODE_MAX_NUM];

    for (;;)
    {
        if (((0xff) != gIMEQSearchModeArray[i].IME_Mode_ID) && (0 != gIMEQSearchModeArray[i].Common_Screen_StringID))
        {
            nStrItemList[nNumofItem] = gIMEQSearchModeArray[i].Common_Screen_StringID;
            nNumofItem++;
        }
        else
        {
            break;
        }
        i++;
    }

    EntryNewScreen(SCR_QUICK_SEARCH_INPUT_METHOD_LIST, ExitQuickSearchInputMethodScreen, NULL, NULL);
    LSK_handler = QuickSearchInputMethodScreenHandleLSK;
    saved_MMI_current_input_type = MMI_current_input_type;
    guiBuffer = GetCurrGuiBuffer(SCR_QUICK_SEARCH_INPUT_METHOD_LIST);
    if (guiBuffer != NULL)
    {
        InputMethodScreenCloseFunction = SavedInputMethodScreenCloseFunction;
    }
    ShowCategory15Screen(
        STR_GLOBAL_INPUT_METHOD,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(LSK_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(QuickSearchInputMethodScreenHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(LSK_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(QuickSearchInputMethodScreenHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitQuickSearchInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitQuickSearchInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SavedInputMethodScreenCloseFunction = InputMethodScreenCloseFunction;
    h.scrnID = SCR_QUICK_SEARCH_INPUT_METHOD_LIST;
    h.entryFuncPtr = EntryQuickSearchInputMethodScreen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/* __CUSTPACK_MULTIBIN     Terry   BEGIN */
extern S16 MMI_AP_required_input_mode_set[INPUT_MODE_MAX_NUM];


/*****************************************************************************
 * FUNCTION
 *  InputMethodSetKeyHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IMEModeArray         [IN]   array with supported input mode 
 *  EnglishOnly             [IN]    If EnglishOnly is set    
 *  AP_required            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 InputMethodSetKeyHandler(
        const sIMEModeDetails *IMEModeArray,
        MMI_BOOL EnglishOnly,
        MMI_BOOL AP_required,
        S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j = 0;
    int input_mode_id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AP_required)
    {
        for (i = 0; (0xff) != MMI_AP_required_input_mode_set[i]; i++)
        {
            j++;
            input_mode_id = MMI_AP_required_input_mode_set[i];
            if (j == index+1)
            {
                return input_mode_id;
            }
        }        
    }
    else if (EnglishOnly) 
    {
        for (;;)
        {
            if (((0xff) != IMEModeArray[i].IME_Mode_ID) && (0 != IMEModeArray[i].Common_Screen_StringID))
            {
                if (IME_IS_ENGLISH_ONLY(IMEModeArray[i].Lang_Special_Attrib))
                {
                    if (!(mmi_is_alphanum_pass && wgui_is_smart_input_mode(IMEModeArray[i].IME_Mode_ID, MMI_FALSE))) /* smart ABC, abc is not allowed in INPUT_TYPE_ALPHANUMERIC_PASSWORD */
                    {
                        input_mode_id = IMEModeArray[i].IME_Mode_ID;
                        j++;
                    }                    
                }
            }
            else
            {
                break;
            }
            if (j == index+1)
            {
                return input_mode_id;
            }
            i++;            
        }
    }
    else
    {
        for (;;)
        {
            if (((0xff) != IMEModeArray[i].IME_Mode_ID) && (0 != IMEModeArray[i].Common_Screen_StringID))
            {
                if (!(mmi_is_alphanum_pass && wgui_is_smart_input_mode(IMEModeArray[i].IME_Mode_ID, MMI_FALSE))) /* smart ABC, abc is not allowed in INPUT_TYPE_ALPHANUMERIC_PASSWORD */
                {
                    input_mode_id = IMEModeArray[i].IME_Mode_ID;
                    j++;
                }                    
            }
            else
            {
                break;
            }
            if (j == index+1)
            {
                return input_mode_id;
            }
            i++;
        }
    }    
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  APRequiredInputMethodScreenHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void APRequiredInputMethodScreenHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = 0;
    U8 input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis multitap phonetic input mode */
        input_mode = InputMethodSetKeyHandler(
                gIMEModeArray,
                MMI_FALSE,
                MMI_TRUE,
                index);
        if (input_mode == -1)
        {
            // index should be check
    #if !defined(__MMI_TOUCH_SCREEN__)
            EntrySymbolPickerScreenFromMenuList();
            UI_dummy_function();
    #endif
        }
        else
        {
            input_type = wgui_map_inputmode_to_inputtype(input_mode, gIMEModeArray);
            wgui_change_inputbox_type(input_type);
            InputMethodScreenCloseFunction();
        }

}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = -1;
    U8 input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis multitap phonetic input mode */
    input_mode = InputMethodSetKeyHandler(
            gIMEModeArray,
            MMI_FALSE,
            MMI_FALSE,
            index);
    if (input_mode == -1)
    {
        // index should be check
    #if !defined(__MMI_TOUCH_SCREEN__)
        EntrySymbolPickerScreenFromMenuList();
        //UI_dummy_function();
    #endif
    }
    else
    {
        input_type = wgui_map_inputmode_to_inputtype(input_mode, gIMEModeArray);
        wgui_change_inputbox_type(input_type);
        InputMethodScreenCloseFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenEnglishOnlyHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenEnglishOnlyHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = -1;
    U8 input_type = INPUT_TYPE_ALPHANUMERIC_UPPERCASE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis multitap phonetic input mode */
    input_mode = InputMethodSetKeyHandler(
            gIMEModeArray,
            MMI_TRUE,
            MMI_FALSE,
            index);
    if (input_mode == -1)
    {
        // index should be check
    #if !defined(__MMI_TOUCH_SCREEN__)
        EntrySymbolPickerScreenFromMenuList();
        UI_dummy_function();
    #endif
    }
    else
    {
        input_type = wgui_map_inputmode_to_inputtype(input_mode, gIMEModeArray);
        wgui_change_inputbox_type(input_type);
        InputMethodScreenCloseFunction();
    }

}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenCloseFunction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenCloseFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenCloseFunction = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterSymbolTableScreenEntryCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        SymbolTableScreenEntryCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterSymbolTableScreenExitCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        SymbolTableScreenExitCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenEntryCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenEntryCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenExitCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenExitCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetSymbolTableScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSymbolTableScreenEntryCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SymbolTableScreenEntryCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetSymbolTableScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSymbolTableScreenExitCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SymbolTableScreenExitCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInputMethodScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInputMethodScreenEntryCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InputMethodScreenEntryCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInputMethodScreenExitCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InputMethodScreenExitCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenHandleRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //SetSavedInputType();
    //MTK Elvis 20031217---it is not required to set them to UI_dummy_function
    //Issue:
    //if set them to UI_dummy_function, will cause following issue:
    //user cannot select desired input mode while entering input method menu list, pressing RSK-Back,
    //and entering input method menu again.
    //pressing RSK will reset following function pointers to be UI_dummy_function.
    //Solution:
    //The xxxchange_inputbox_modexxxx will be re-initialized in different editing screen, so it
    //not required to set them to UI_dummy_function while pressing RSK-Back
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #if defined(__MMI_T9__) || defined(__MMI_ZI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}

extern void handle_inline_full_screen_edit_complete(void);
extern void handle_inline_full_screen_edit_cancel(void);
extern wgui_inline_item *current_wgui_inline_item;
extern S32 wgui_n_inline_items;
extern S32 wgui_inline_item_highlighted_index;


/*****************************************************************************
 * FUNCTION
 *  ConfirmInlineFullScreenEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmInlineFullScreenEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if ((current_wgui_inline_item == NULL) || (wgui_n_inline_items <= 0))
    {
        GoBackHistory();
    }
    handle_inline_full_screen_edit_complete();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  CancelInlineFullScreenEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CancelInlineFullScreenEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if ((current_wgui_inline_item == NULL) || (wgui_n_inline_items <= 0))
    {
        GoBackHistory();
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
    handle_inline_full_screen_edit_cancel();
}


/*****************************************************************************
 * FUNCTION
 *  EntryAPRequiredInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAPRequiredInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0;
    U16 p = 0, q = 0;
    U16 nStrItemList[INPUT_MODE_MAX_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*LSK_handler) (void);

    // for request from Sao Tao start
    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
    // for request from Sao Tao end

    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_AP_REQUIRED_INPUT_METHOD_LIST, ExitAPRequiredInputMethodScreen, NULL, NULL);

    while (1)
    {
        if (MMI_AP_required_input_mode_set[p] == gIMEModeArray[q].IME_Mode_ID)
        {
            nStrItemList[nNumofItem] = gIMEModeArray[q].Common_Screen_StringID;
            nNumofItem++;
            if (MMI_AP_required_input_mode_set[p + 1] == -1)
            {
                break;
            }
            p++;
            q = 0;
        }
        else
        {
            q++;
            if (gIMEModeArray[q].IME_Mode_ID == (0xff))
            {
                p ++;
                q = 0;
            }
            else if (q > INPUT_MODE_MAX_NUM + 1)
            {
                if (MMI_AP_required_input_mode_set[p] == -1 || MMI_AP_required_input_mode_set[p + 1] == -1)
                {
                    break;
                }
                p++;
                q = 0;
            }
        }
    }

#if !defined(__MMI_TOUCH_SCREEN__)
    nStrItemList[nNumofItem] = STR_INPUT_METHOD_MENU_INSERT_SYMBOLS;
    nNumofItem++;
#endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
    LSK_handler = APRequiredInputMethodScreenHandleLSK;

    saved_MMI_current_input_type = MMI_current_input_type;
    guiBuffer = GetCurrGuiBuffer(SCR_AP_REQUIRED_INPUT_METHOD_LIST);
    if (guiBuffer != NULL)
    {
        InputMethodScreenCloseFunction = SavedInputMethodScreenCloseFunction;
    }
    ShowCategory15Screen(
        STR_GLOBAL_INPUT_METHOD,
        /* gInputMethodAndDoneCaptionIcon */ 0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(LSK_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(InputMethodScreenHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(LSK_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(InputMethodScreenHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetExitHandler(SCR_INPUT_METHOD_LIST, ExitInputMethodScreen); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitAPRequiredInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitAPRequiredInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SavedInputMethodScreenCloseFunction = InputMethodScreenCloseFunction;
    //MTK Elvis 20031217---it is not required to set them to UI_dummy_function
    //Issue:
    //if set them to UI_dummy_function, will cause following issue:
    //user cannot select desired input mode while entering input method menu list, pressing RSK-Back,
    //and entering input method menu again.
    //pressing RSK will reset following function pointers to be UI_dummy_function.
    //Solution:
    //The InputMethodScreenCloseFunction will be re-initialized in different editing screen, so it
    //not required to set them to UI_dummy_function while pressing RSK-Back
#if 0
/* under construction !*/
#endif /* 0 */ 

    // for request from Sao Tao start
    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();
    // for request from Sao Tao end

    h.scrnID = SCR_AP_REQUIRED_INPUT_METHOD_LIST;
    h.entryFuncPtr = EntryAPRequiredInputMethodScreen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  EntryInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0, i = 0;
    U16 nStrItemList[INPUT_MODE_MAX_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*LSK_handler) (void);

    // for request from Sao Tao start
    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
    // for request from Sao Tao end
    
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_INPUT_METHOD_LIST, ExitInputMethodScreen, NULL, NULL);

    if (MMI_english_input_mode_flag)    /* English only input methods menu     */
    {
        for (;;)
        {
            if (((0xff) != gIMEModeArray[i].IME_Mode_ID) && (0 != gIMEModeArray[i].Common_Screen_StringID))
            {
                if (IME_IS_ENGLISH_ONLY(gIMEModeArray[i].Lang_Special_Attrib))
                {
                    if (!(mmi_is_alphanum_pass && (wgui_is_smart_input_mode(gIMEModeArray[i].IME_Type_ID, MMI_TRUE)))) /* smart ABC, abc is not allowed in INPUT_TYPE_ALPHANUMERIC_PASSWORD */
                    {
                        nStrItemList[nNumofItem] = gIMEModeArray[i].Common_Screen_StringID;
                        nNumofItem++;
                    }
                    
                }
            }
            else
            {
                break;
            }
            i++;
        }
    #if !defined(__MMI_TOUCH_SCREEN__)
        nStrItemList[nNumofItem] = STR_INPUT_METHOD_MENU_INSERT_SYMBOLS;
        nNumofItem++;
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
        LSK_handler = InputMethodScreenEnglishOnlyHandleLSK;
    }
    else    /* English-Chinese input methods menu  */
    {
        for (;;)
        {
            if ((0xff) != gIMEModeArray[i].IME_Mode_ID && (0 != gIMEModeArray[i].Common_Screen_StringID))
            {
                if (!(mmi_is_alphanum_pass &&(wgui_is_smart_input_mode(gIMEModeArray[i].IME_Type_ID, MMI_TRUE)))) /* smart ABC, abc is not allowed in INPUT_TYPE_ALPHANUMERIC_PASSWORD */
                {
                    nStrItemList[nNumofItem] = gIMEModeArray[i].Common_Screen_StringID;
                    nNumofItem++;    
                }
            }
            else
            {
                break;
            }
             i++;
           
        }
    #if !defined(__MMI_TOUCH_SCREEN__)
        nStrItemList[nNumofItem] = STR_INPUT_METHOD_MENU_INSERT_SYMBOLS;
        nNumofItem++;
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
        LSK_handler = InputMethodScreenHandleLSK;
    }
    saved_MMI_current_input_type = MMI_current_input_type;
    guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_LIST);
    if (guiBuffer != NULL)
    {
        InputMethodScreenCloseFunction = SavedInputMethodScreenCloseFunction;
    }
    ShowCategory15Screen(
        STR_GLOBAL_INPUT_METHOD,
        /* gInputMethodAndDoneCaptionIcon */ 0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(LSK_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(InputMethodScreenHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(LSK_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(InputMethodScreenHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetExitHandler(SCR_INPUT_METHOD_LIST, ExitInputMethodScreen); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SavedInputMethodScreenCloseFunction = InputMethodScreenCloseFunction;
    //MTK Elvis 20031217---it is not required to set them to UI_dummy_function
    //Issue:
    //if set them to UI_dummy_function, will cause following issue:
    //user cannot select desired input mode while entering input method menu list, pressing RSK-Back,
    //and entering input method menu again.
    //pressing RSK will reset following function pointers to be UI_dummy_function.
    //Solution:
    //The InputMethodScreenCloseFunction will be re-initialized in different editing screen, so it
    //not required to set them to UI_dummy_function while pressing RSK-Back
#if 0
/* under construction !*/
#endif /* 0 */ 

    // for request from Sao Tao start
    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();
    // for request from Sao Tao end

    h.scrnID = SCR_INPUT_METHOD_LIST;
    h.entryFuncPtr = EntryInputMethodScreen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}

/* __CUSTPACK_MULTIBIN     Terry   END */

#define SYMBOL_PICKER_MAX_SYMBOLS            36
#define SYMBOL_PICKER_LF_INDEX               35
#define SYMBOL_PICKER_SPACE_INDEX            34

#define SYMBOL_PICKER_MAX_CHINESE_SYMBOLS    28
#define SYMBOL_PICKER_CHINESE_LF_INDEX       27
#define SYMBOL_PICKER_CHINESE_SPACE_INDEX    26

/* Begin AP Symbol table */
U8 MMI_AP_No_Show_Symbol_List_flag = 0;
U8 *MMI_AP_No_Show_Symbol_List[SYMBOL_PICKER_MAX_SYMBOLS];

/* End AP Symbol table */

const U8 *SymbolPickerSymbols[SYMBOL_PICKER_MAX_SYMBOLS] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    /* (U8*)"\xa2\0\0", */
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
    /* (U8*)" \0\0", */
};

#if defined(__MMI_LANG_ARABIC__)
const U8 *SymbolPickerArabicSymbols[SYMBOL_PICKER_MAX_SYMBOLS] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x0c\06\0\0", /* Arabic Comma */
    (U8 *) "\x1f\x06\0\0", /* Arabic Question Mark */
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) ")\0\0",
    (U8 *) "(\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) "\x1b\x06\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) ">\0\0",
    (U8 *) "<\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "]\0\0",
    (U8 *) "[\0\0",
    (U8 *) "}\0\0",
    (U8 *) "{\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
};

#endif 


//using full-width forms instead of CJK compatibility forms
//#if defined(__MMI_FULLWIDTH_FORMS__)
const U8 *SymbolPickerChineseSymbols[SYMBOL_PICKER_MAX_CHINESE_SYMBOLS] = 
{
    (U8 *) "\x0c\xff\0\0",
    (U8 *) "\x02\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x61\xff\0\0", */
    (U8 *) "\x01\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x64\xff\0\0", */
    (U8 *) "\x1a\xff\0\0",
    (U8 *) "\x1b\xff\0\0",
    (U8 *) "\x1f\xff\0\0",
    (U8 *) "\x26\x20\0\0",
    (U8 *) "\x01\xff\0\0",
    (U8 *) "\x0a\x30\0\0",
    (U8 *) "\x0b\x30\0\0",
    (U8 *) "\x0e\x30\0\0",
    (U8 *) "\x0f\x30\0\0",
    (U8 *) "\x1c\x20\0\0",
    (U8 *) "\x1d\x20\0\0",
    (U8 *) "\x08\xff\0\0",
    (U8 *) "\x09\xff\0\0",
    (U8 *) "\x0c\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x62\xff\0\0", */
    (U8 *) "\x0d\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x63\xff\0\0", */
    (U8 *) "\x18\x20\0\0",
    (U8 *) "\x19\x20\0\0",
    (U8 *) "\x0e\xff\0\0",
    (U8 *) "\x1c\xff\0\0",
    (U8 *) "\x1e\xff\0\0",
    (U8 *) "\x5e\xff\0\0",
    (U8 *) "\x3b\xff\0\0",
    (U8 *) "\x3d\xff\0\0",
    (U8 *) "\x20\x00\0\0",
    (U8 *) "\n\0\0",
};

// #else
#if 0   /* using full-width forms instead of CJK compatibility forms */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
// #endif

const U8 SymbolPickerLFString[] = {0x85, 0, '\0', 0};
const U8 SymbolPickerSpaceString[] = {0x86, 0, '\0', 0};
#define SPACE_SYMBOL (0x20)
#define NEWLINE_SYMBOL (0x0a)
#define EURO_SYMBOL (0x20ac)
const U8 *SymbolPickerDisplaySymbols[SYMBOL_PICKER_MAX_SYMBOLS];

const U8 *SymbolPickerDisplayChineseSymbols[SYMBOL_PICKER_MAX_CHINESE_SYMBOLS];

/* Begin AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  Transform_LF_SPACE_Symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  symbol      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type Transform_LF_SPACE_Symbol(UI_character_type symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (symbol == 0x0085)
    {
        return 0x000a;
    }
    else if (symbol == 0x0086)
    {
        return 0x0020;
    }
    else
    {
        return symbol;
    }
}

/* End AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type selected_symbol;
    S32 index = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {

        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
            /* Begin AP Symbol table */
            selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                          (((UI_character_type) SymbolPickerDisplayChineseSymbols[index][0]) |
                                           (((UI_character_type) SymbolPickerDisplayChineseSymbols[index][1]) << 8)));
            /* End AP Symbol table */
            break;
    #if defined(__MMI_LANG_ARABIC__)
        case INPUT_TYPE_ALPHANUMERIC_ARABIC:
        case INPUT_TYPE_SMART_ARABIC:
        case INPUT_TYPE_ARABIC_NUMERIC:
            selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                          (((UI_character_type) SymbolPickerDisplaySymbols[index][0]) |
                                           (((UI_character_type) SymbolPickerDisplaySymbols[index][1]) << 8)));
        break;
    #endif
        default:
            /* Begin AP Symbol table */
            selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                          (((UI_character_type) SymbolPickerDisplaySymbols[index][0]) |
                                           (((UI_character_type) SymbolPickerDisplaySymbols[index][1]) << 8)));
            /* End AP Symbol table */
            break;
    }
    mmi_fe_disable_proprietary_symbol_display();
    gdi_layer_lock_frame_buffer();
    GoBackHistory();
    wgui_inputbox_insert_symbol(selected_symbol);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);    

    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
        case INPUT_TYPE_SMART_UPPERCASE_ABC:
        case INPUT_TYPE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_T9_SPANISH__) || defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_SPANISH:
        case INPUT_TYPE_SMART_LOWERCASE_SPANISH:
    #endif /* defined(__MMI_T9_SPANISH__) || defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 
    #if defined(__MMI_T9_DANISH__) || defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_DANISH:
        case INPUT_TYPE_SMART_LOWERCASE_DANISH:
    #endif /* defined(__MMI_T9_DANISH__) || defined(__MMI_ZI_DANISH__) */ 
    #if defined(__MMI_T9_POLISH__) || defined(__MMI_ZI_POLISH__) || defined(__MMI_CSTAR_POLISH__)
        case INPUT_TYPE_SMART_UPPERCASE_POLISH:
        case INPUT_TYPE_SMART_LOWERCASE_POLISH:
    #endif /* defined(__MMI_T9_POLISH__) || defined(__MMI_ZI_POLISH__) */ 
    #if defined(__MMI_T9_FRENCH__) || defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__)
        case INPUT_TYPE_SMART_UPPERCASE_FRENCH:
        case INPUT_TYPE_SMART_LOWERCASE_FRENCH:
    #endif /* defined(__MMI_T9_FRENCH__) || defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 
    #if defined(__MMI_T9_GERMAN__) || defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
        case INPUT_TYPE_SMART_UPPERCASE_GERMAN:
        case INPUT_TYPE_SMART_LOWERCASE_GERMAN:
    #endif /* defined(__MMI_T9_GERMAN__) || defined(__MMI_ZI_GERMAN__) */ 
    #if defined(__MMI_T9_ITALIAN__) || defined(__MMI_ZI_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ITALIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ITALIAN:
    #endif /* defined(__MMI_T9_ITALIAN__) || defined(__MMI_ZI_ITALIAN__) */ 
    #if defined (__MMI_T9_RUSSIAN__) || defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_TYPE_SMART_LOWERCASE_RUSSIAN:
    #endif /* defined (__MMI_T9_RUSSIAN__) || defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) */ 
    #if defined (__MMI_T9_BULGARIAN__) || defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_TYPE_SMART_LOWERCASE_BULGARIAN:
    #endif /* defined (__MMI_T9_BULGARIAN__) || defined(__MMI_ZI_BULGARIAN__) */ 
    #if defined(__MMI_ZI_UKRAINIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_UKRAINIAN:
        case INPUT_TYPE_SMART_LOWERCASE_UKRAINIAN:
    #endif /* defined(__MMI_ZI_BULGARIAN__) */ 
    #if defined(__MMI_ZI_THAI__) || defined (__MMI_T9_THAI__) || defined(__MMI_CSTAR_THAI__)
        case INPUT_TYPE_SMART_THAI:
    #endif 
        case INPUT_TYPE_SMART_ARABIC:
    #ifdef __MMI_LANG_PERSIAN__
        case INPUT_TYPE_SMART_PERSIAN:
    #endif 
    #if (defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__))  
        case INPUT_TYPE_SMART_HINDI:
    #endif
        case INPUT_TYPE_SMART_HEBREW:
    #if defined(__MMI_ZI_TURKISH__) || defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
        case INPUT_TYPE_SMART_UPPERCASE_TURKISH:
        case INPUT_TYPE_SMART_LOWERCASE_TURKISH:
    #endif /* defined(__MMI_ZI_TURKISH__) || defined(__MMI_T9_TURKISH__) */ 
    #if defined(__MMI_T9_PORTUGUESE__) || defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__)
        case INPUT_TYPE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_TYPE_SMART_LOWERCASE_PORTUGUESE:
    #endif /* defined(__MMI_T9_PORTUGUESE__) || defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) */ 
    #if defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) || defined(__MMI_CSTAR_INDONESIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_TYPE_SMART_LOWERCASE_INDONESIAN:
    #endif /* defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) */ 
    #if defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__) || defined(__MMI_CSTAR_CZECH__)
        case INPUT_TYPE_SMART_UPPERCASE_CZECH:
        case INPUT_TYPE_SMART_LOWERCASE_CZECH:
    #endif /* defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__) */ 
    #if defined(__MMI_ZI_MALAY__) || defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
        case INPUT_TYPE_SMART_UPPERCASE_MALAY:
        case INPUT_TYPE_SMART_LOWERCASE_MALAY:
    #endif /* defined(__MMI_ZI_MALAY__) || defined(__MMI_T9_MALAY__) */ 
    #if defined(__MMI_ZI_VIETNAMESE__) || defined(__MMI_T9_VIETNAMESE__) || defined(__MMI_CSTAR_VIETNAMESE__)
        case INPUT_TYPE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_TYPE_SMART_LOWERCASE_VIETNAMESE:
    #endif /* defined(__MMI_ZI_VIETNAMESE__) || defined(__MMI_T9_VIETNAMESE__) */ 
    #if defined(__MMI_ZI_FINNISH__) || defined(__MMI_T9_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
        case INPUT_TYPE_SMART_UPPERCASE_FINNISH:
        case INPUT_TYPE_SMART_LOWERCASE_FINNISH:
    #endif /* defined(__MMI_ZI_FINNISH__) || defined(__MMI_T9_FINNISH__) */ 
    #if defined(__MMI_T9_HUNGARIAN__) || defined(__MMI_ZI_HUNGARIAN__) || defined(__MMI_CSTAR_HUNGARIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_TYPE_SMART_LOWERCASE_HUNGARIAN:
    #endif /* defined(__MMI_T9_HUNGARIAN__) || defined(__MMI_ZI_HUNGARIAN__) */ 
    #if defined(__MMI_ZI_SLOVAK__) || defined(__MMI_T9_SLOVAK__) || defined(__MMI_CSTAR_SLOVAK__)
        case INPUT_TYPE_SMART_UPPERCASE_SLOVAK:
        case INPUT_TYPE_SMART_LOWERCASE_SLOVAK:
    #endif /* defined(__MMI_ZI_SLOVAK__) || defined(__MMI_T9_SLOVAK__) */ 
    #if defined(__MMI_ZI_DUTCH__) || defined(__MMI_T9_DUTCH__) || defined(__MMI_CSTAR_DUTCH__)
        case INPUT_TYPE_SMART_UPPERCASE_DUTCH:
        case INPUT_TYPE_SMART_LOWERCASE_DUTCH:
    #endif /* defined(__MMI_ZI_DUTCH__) || defined(__MMI_T9_DUTCH__) */ 
    #if defined(__MMI_T9_NORWEGIAN__) || defined(__MMI_ZI_NORWEGIAN__) || defined(__MMI_CSTAR_NORWEGIAN__)
            /* PMT VIKAS GUPTA END PO_NO_ZI 20050930 */
        case INPUT_TYPE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_TYPE_SMART_LOWERCASE_NORWEGIAN:
    #endif /* defined(__MMI_T9_NORWEGIAN__) || defined(__MMI_ZI_NORWEGIAN__) */ 
    #if defined(__MMI_ZI_SWEDISH__) || defined(__MMI_T9_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
        case INPUT_TYPE_SMART_UPPERCASE_SWEDISH:
        case INPUT_TYPE_SMART_LOWERCASE_SWEDISH:
    #endif /* defined(__MMI_ZI_SWEDISH__) || defined(__MMI_T9_SWEDISH__) */ 
    #if defined(__MMI_ZI_CROATIAN__) || defined(__MMI_T9_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_CROATIAN:
        case INPUT_TYPE_SMART_LOWERCASE_CROATIAN:
    #endif /* defined(__MMI_ZI_CROATIAN__) || defined(__MMI_T9_CROATIAN__) */ 
    #if defined(__MMI_ZI_ROMANIAN__) || defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ROMANIAN:
    #endif /* defined(__MMI_ZI_ROMANIAN__) || defined(__MMI_T9_ROMANIAN__) */ 
    #if defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_T9_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_TYPE_SMART_LOWERCASE_SLOVENIAN:
    #endif /* defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_T9_SLOVENIAN__) */ 
    #if defined(__MMI_ZI_GREEK__) || defined(__MMI_T9_GREEK__) || defined(__MMI_CSTAR_GREEK__)
        case INPUT_TYPE_SMART_UPPERCASE_GREEK:
        case INPUT_TYPE_SMART_LOWERCASE_GREEK:
    #endif /* defined(__MMI_ZI_GREEK__) || defined(__MMI_T9_GREEK__) */ 
            //W05.34 Fix Screen will be clear after inserting symbols
    #if !defined(__MMI_TOUCH_SCREEN__)
    #ifdef __MMI_T9__
            T9SynT9WithInputBox();
    #elif defined __MMI_ZI__
            ZiDisplay();
    #elif defined __MMI_CSTAR__
            CstarDisplay();
    #elif defined __MMI_KA__
            KonkaDisplay();
    #elif defined __MMI_ITAP__
/* under construction !*/
    #endif 
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_disable_proprietary_symbol_display();
    GoBackHistory();
}

extern S16 MMI_current_input_ext_type;
static S16 SymbolFilterFlag = 0;
static U8 SymbolEnglishOnlyFlag = 0;
/* Begin AP Symbol table */
static U8 APSetNoShowSymbolFlag = 0;

/* End AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  EntrySymbolPickerScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySymbolPickerScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    // for request from Sao Tao start
    if (SymbolTableScreenEntryCallback != NULL)
        SymbolTableScreenEntryCallback();
    // for request from Sao Tao end
    
    EntryNewScreen(SCR_SYMBOL_PICKER_SCREEN, ExitSymbolPickerScreen, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SYMBOL_PICKER_SCREEN);
    /* Begin AP Symbol table */
    if (guiBuffer != NULL)
    {
        MMI_current_input_ext_type = SymbolFilterFlag;
        MMI_AP_No_Show_Symbol_List_flag = APSetNoShowSymbolFlag;
        MMI_english_input_mode_flag = SymbolEnglishOnlyFlag;
    }
    /* enable symbol table character display */
    mmi_fe_enable_proprietary_symbol_display();
    
    /* End AP Symbol table */
    PrepareSymbolTableAndShowCategory(guiBuffer);

    SetLeftSoftkeyFunction(SymbolPickerHandleLSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SymbolPickerHandleRSK, KEY_EVENT_UP);

}

/* Begin AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  Is_No_Need_Show_Symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  symbol      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Is_No_Need_Show_Symbol(const U8 *symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*MMI_AP_No_Show_Symbol_List[i] != (U8)(0x00))
    {
        if (*symbol == *MMI_AP_No_Show_Symbol_List[i])
        {
            return MMI_TRUE;
        }
        i++;
    }
    return MMI_FALSE;
}

/* End AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  PrepareSymbolTableAndShowCategory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PrepareSymbolTableAndShowCategory(U8 *guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /* Begin AP Symbol table */
    S32 num_of_no_show_symbols = 0;
    S32 j = 0;

    /* End AP Symbol table */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Begin AP Symbol table */
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
            j = 0;
            for (i = 0; i < SYMBOL_PICKER_MAX_CHINESE_SYMBOLS; i++)
            {

                if (((MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL) &&
                     ((*SymbolPickerChineseSymbols[i] | ((*(SymbolPickerChineseSymbols[i]+1))<<8)) == (U16)NEWLINE_SYMBOL)) ||
                    (MMI_AP_No_Show_Symbol_List_flag && Is_No_Need_Show_Symbol(SymbolPickerChineseSymbols[i])))
                {
                    num_of_no_show_symbols++;
                    continue;
                }
                else
                {
                    if ((*SymbolPickerChineseSymbols[i] | ((*(SymbolPickerChineseSymbols[i]+1))<<8)) == ((U16)SPACE_SYMBOL))
                    {
                        SymbolPickerDisplayChineseSymbols[j] = SymbolPickerSpaceString;
                    }
                    else if ((*SymbolPickerChineseSymbols[i] | ((*(SymbolPickerChineseSymbols[i]+1))<<8)) == ((U16)NEWLINE_SYMBOL))
                    {
                        SymbolPickerDisplayChineseSymbols[j] = SymbolPickerLFString;
                    }
                    else
                    {
                        SymbolPickerDisplayChineseSymbols[j] = SymbolPickerChineseSymbols[i];
                    }
                }
                j++;
            }

            ShowCategory22Screen(
                STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
                0,
                STR_GLOBAL_OK,
                0,
                STR_GLOBAL_BACK,
                0,
                SYMBOL_PICKER_MAX_CHINESE_SYMBOLS - num_of_no_show_symbols,
                (U8 **) SymbolPickerDisplayChineseSymbols,
                0,
                guiBuffer);
            break;
        #if defined(__MMI_LANG_ARABIC__) 
        case INPUT_TYPE_ALPHANUMERIC_ARABIC:
        case INPUT_TYPE_SMART_ARABIC:
        case INPUT_TYPE_ARABIC_NUMERIC:
            j = 0;
            for (i = 0; i < SYMBOL_PICKER_MAX_SYMBOLS; i++)
            {

                if (((MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL) &&
                     ((*SymbolPickerArabicSymbols[i] | ((*(SymbolPickerArabicSymbols[i]+1))<<8)) == (U16)NEWLINE_SYMBOL)) ||
                    (MMI_AP_No_Show_Symbol_List_flag && Is_No_Need_Show_Symbol(SymbolPickerArabicSymbols[i])))
                {
                    num_of_no_show_symbols++;
                    continue;
                }
                else
                {
                    if ((*SymbolPickerArabicSymbols[i] | ((*(SymbolPickerArabicSymbols[i]+1))<<8)) == ((U16)SPACE_SYMBOL))
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerSpaceString;
                    }
                    else if ((*SymbolPickerArabicSymbols[i] | ((*(SymbolPickerArabicSymbols[i]+1))<<8)) == ((U16)NEWLINE_SYMBOL))
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerLFString;
                    }
                    else
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerArabicSymbols[i];
                    }
                }
                j++;
            }                        
            ShowCategory22Screen(
                STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
                0,
                STR_GLOBAL_OK,
                0,
                STR_GLOBAL_BACK,
                0,
                SYMBOL_PICKER_MAX_SYMBOLS - num_of_no_show_symbols,
                (U8 **) SymbolPickerDisplaySymbols,
                0,
                guiBuffer);
            break;
        #endif /* defined(__MMI_LANG_ARABIC__) */
        
        default:
            j = 0;
            for (i = 0; i < SYMBOL_PICKER_MAX_SYMBOLS; i++)
            {

                if (((MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL) &&
                     ((*SymbolPickerSymbols[i] | ((*(SymbolPickerSymbols[i]+1))<<8)) == (U16)NEWLINE_SYMBOL)) ||
                    (MMI_english_input_mode_flag && ((*SymbolPickerSymbols[i] | ((*(SymbolPickerSymbols[i]+1))<<8)) == (U16)EURO_SYMBOL)) ||
                    (MMI_AP_No_Show_Symbol_List_flag && Is_No_Need_Show_Symbol(SymbolPickerSymbols[i])))
                {
                    num_of_no_show_symbols++;
                    continue;
                }
                else
                {
                    if ((*SymbolPickerSymbols[i] | ((*(SymbolPickerSymbols[i]+1))<<8)) == ((U16)SPACE_SYMBOL))
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerSpaceString;
                    }
                    else if ((*SymbolPickerSymbols[i] | ((*(SymbolPickerSymbols[i]+1))<<8)) == ((U16)NEWLINE_SYMBOL))
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerLFString;
                    }
                    else
                    {
                        SymbolPickerDisplaySymbols[j] = SymbolPickerSymbols[i];
                    }
                }
                j++;
            }
            ShowCategory22Screen(
                STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
                0,
                STR_GLOBAL_OK,
                0,
                STR_GLOBAL_BACK,
                0,
                SYMBOL_PICKER_MAX_SYMBOLS - num_of_no_show_symbols,
                (U8 **) SymbolPickerDisplaySymbols,
                0,
                guiBuffer);
            break;
    }
    /* End AP Symbol table */
}


/*****************************************************************************
 * FUNCTION
 *  ExitSymbolPickerScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSymbolPickerScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable proprietary symbol character display */
    mmi_fe_disable_proprietary_symbol_display();

    // or request from Sao Tao start
    if (SymbolTableScreenExitCallback != NULL)
        SymbolTableScreenExitCallback();
    // for request from Sao Tao end

    h.scrnID = SCR_SYMBOL_PICKER_SCREEN;
    h.entryFuncPtr = EntrySymbolPickerScreen;
    SymbolFilterFlag = MMI_current_input_ext_type;
    SymbolEnglishOnlyFlag = MMI_english_input_mode_flag;
    /* Begin AP Symbol table */
    APSetNoShowSymbolFlag = MMI_AP_No_Show_Symbol_List_flag;
    /* End AP Symbol table */
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleLSKFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleLSKFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type selected_symbol;
    S32 index = GetHighlightedItem();


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
            /* Begin AP Symbol table */
            selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                          (((UI_character_type) SymbolPickerDisplayChineseSymbols[index][0]) |
                                           (((UI_character_type) SymbolPickerDisplayChineseSymbols[index][1]) << 8)));
            /* End AP Symbol table */
            break;

        default:
            /* Begin AP Symbol table */
            selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                          (((UI_character_type) SymbolPickerDisplaySymbols[index][0]) |
                                           (((UI_character_type) SymbolPickerDisplaySymbols[index][1]) << 8)));
            /* End AP Symbol table */
    }

   mmi_fe_disable_proprietary_symbol_display();
    gdi_layer_lock_frame_buffer();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    GoBackHistory();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
    InputMethodScreenCloseFunction();
    wgui_inputbox_insert_symbol(selected_symbol);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);

    
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_TR_STROKE:
        case INPUT_TYPE_SM_STROKE:
        case INPUT_TYPE_SMART_UPPERCASE_ABC:
        case INPUT_TYPE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_T9_SPANISH__) || defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_SPANISH:
        case INPUT_TYPE_SMART_LOWERCASE_SPANISH:
    #endif /* defined(__MMI_T9_SPANISH__) || defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 
    #if defined(__MMI_T9_DANISH__) || defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__)
        case INPUT_TYPE_SMART_UPPERCASE_DANISH:
        case INPUT_TYPE_SMART_LOWERCASE_DANISH:
    #endif /* defined(__MMI_T9_DANISH__) || defined(__MMI_ZI_DANISH__) */ 
    #if defined(__MMI_T9_POLISH__) || defined(__MMI_ZI_POLISH__) || defined(__MMI_CSTAR_POLISH__)
        case INPUT_TYPE_SMART_UPPERCASE_POLISH:
        case INPUT_TYPE_SMART_LOWERCASE_POLISH:
    #endif /* defined(__MMI_T9_POLISH__) || defined(__MMI_ZI_POLISH__) */ 
    #if defined(__MMI_T9_FRENCH__) || defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__)
        case INPUT_TYPE_SMART_UPPERCASE_FRENCH:
        case INPUT_TYPE_SMART_LOWERCASE_FRENCH:
    #endif /* defined(__MMI_T9_FRENCH__) || defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 
    #if defined(__MMI_T9_GERMAN__) || defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
        case INPUT_TYPE_SMART_UPPERCASE_GERMAN:
        case INPUT_TYPE_SMART_LOWERCASE_GERMAN:
    #endif /* defined(__MMI_T9_GERMAN__) || defined(__MMI_ZI_GERMAN__) */ 
    #if defined(__MMI_T9_ITALIAN__) || defined(__MMI_ZI_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ITALIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ITALIAN:
    #endif /* defined(__MMI_T9_ITALIAN__) || defined(__MMI_ZI_ITALIAN__) */ 
    #if defined (__MMI_T9_RUSSIAN__) || defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_TYPE_SMART_LOWERCASE_RUSSIAN:
    #endif /* defined (__MMI_T9_RUSSIAN__) || defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) */ 
    #if defined (__MMI_T9_BULGARIAN__) || defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_TYPE_SMART_LOWERCASE_BULGARIAN:
    #endif /* defined (__MMI_T9_BULGARIAN__) || defined(__MMI_ZI_BULGARIAN__) */ 
    #if defined (__MMI_T9_UKRAINIAN__) || defined(__MMI_ZI_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_UKRAINIAN:
        case INPUT_TYPE_SMART_LOWERCASE_UKRAINIAN:
    #endif /* defined (__MMI_T9_UKRAINIAN__) || defined(__MMI_ZI_UKRAINIAN__) */ 
    #if defined(__MMI_ZI_THAI__) || defined (__MMI_T9_THAI__)
        case INPUT_TYPE_SMART_THAI:
    #endif 
        case INPUT_TYPE_SMART_ARABIC:
            /* PMT VIKAS GUPTA START 20051129 */
    #ifdef __MMI_ZI_PERSIAN__
        case INPUT_TYPE_SMART_PERSIAN:
    #endif 
    #if defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__) 
        case INPUT_TYPE_SMART_HINDI:
    #endif
    #if defined(__MMI_ZI_HEBREW__) || defined (__MMI_T9_HEBREW__)
        case INPUT_TYPE_SMART_HEBREW:
    #endif 
    #if defined(__MMI_ZI_TURKISH__) || defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
        case INPUT_TYPE_SMART_UPPERCASE_TURKISH:
        case INPUT_TYPE_SMART_LOWERCASE_TURKISH:
    #endif /* defined(__MMI_ZI_TURKISH__) || defined(__MMI_T9_TURKISH__) */ 
    #if defined(__MMI_T9_PORTUGUESE__) || defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__)
        case INPUT_TYPE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_TYPE_SMART_LOWERCASE_PORTUGUESE:
    #endif /* defined(__MMI_T9_PORTUGUESE__) || defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) */ 
    #if defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) || defined(__MMI_CSTAR_INDONESIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_TYPE_SMART_LOWERCASE_INDONESIAN:
    #endif /* defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) */ 
    #if defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__) || defined(__MMI_CSTAR_CZECH__)
        case INPUT_TYPE_SMART_UPPERCASE_CZECH:
        case INPUT_TYPE_SMART_LOWERCASE_CZECH:
    #endif /* defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__) */ 
    #if defined(__MMI_ZI_MALAY__) || defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
        case INPUT_TYPE_SMART_UPPERCASE_MALAY:
        case INPUT_TYPE_SMART_LOWERCASE_MALAY:
    #endif /* defined(__MMI_ZI_MALAY__) || defined(__MMI_T9_MALAY__) */ 
            /* PMT BHASKAR START 20052907 */
    #if defined(__MMI_ZI_VIETNAMESE__) || defined(__MMI_T9_VIETNAMESE__) || defined(__MMI_CSTAR_VIETNAMESE__)
        case INPUT_TYPE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_TYPE_SMART_LOWERCASE_VIETNAMESE:
    #endif /* defined(__MMI_ZI_VIETNAMESE__) || defined(__MMI_T9_VIETNAMESE__) */ 
    #if defined(__MMI_ZI_FINNISH__) || defined(__MMI_T9_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
        case INPUT_TYPE_SMART_UPPERCASE_FINNISH:
        case INPUT_TYPE_SMART_LOWERCASE_FINNISH:
    #endif /* defined(__MMI_ZI_FINNISH__) || defined(__MMI_T9_FINNISH__) */ 
    #if defined(__MMI_T9_HUNGARIAN__) || defined(__MMI_ZI_HUNGARIAN__) || defined(__MMI_CSTAR_HUNGARIAN__)
            /* PMT END GR_HE_CZ_FI_DA_HU 20051007 */
        case INPUT_TYPE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_TYPE_SMART_LOWERCASE_HUNGARIAN:
    #endif /* defined(__MMI_T9_HUNGARIAN__) || defined(__MMI_ZI_HUNGARIAN__) */ 
    #if defined(__MMI_ZI_SLOVAK__) || defined(__MMI_T9_SLOVAK__) || defined(__MMI_CSTAR_SLOVAK__)
        case INPUT_TYPE_SMART_UPPERCASE_SLOVAK:
        case INPUT_TYPE_SMART_LOWERCASE_SLOVAK:
    #endif /* defined(__MMI_ZI_SLOVAK__) || defined(__MMI_T9_SLOVAK__) */ 
    #if defined(__MMI_ZI_DUTCH__) || defined(__MMI_T9_DUTCH__) || defined(__MMI_CSTAR_DUTCH__)
        case INPUT_TYPE_SMART_UPPERCASE_DUTCH:
        case INPUT_TYPE_SMART_LOWERCASE_DUTCH:
    #endif /* defined(__MMI_ZI_DUTCH__) || defined(__MMI_T9_DUTCH__) */ 
    #if defined(__MMI_T9_NORWEGIAN__) || defined(__MMI_ZI_NORWEGIAN__) || defined(__MMI_CSTAR_NORWEGIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_TYPE_SMART_LOWERCASE_NORWEGIAN:
    #endif /* defined(__MMI_T9_NORWEGIAN__) || defined(__MMI_ZI_NORWEGIAN__) */ 
    #if defined(__MMI_ZI_SWEDISH__) || defined(__MMI_T9_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
        case INPUT_TYPE_SMART_UPPERCASE_SWEDISH:
        case INPUT_TYPE_SMART_LOWERCASE_SWEDISH:
    #endif /* defined(__MMI_ZI_SWEDISH__) || defined(__MMI_T9_SWEDISH__) */ 
    #if defined(__MMI_ZI_CROATIAN__) || defined(__MMI_T9_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_CROATIAN:
        case INPUT_TYPE_SMART_LOWERCASE_CROATIAN:
    #endif /* defined(__MMI_ZI_CROATIAN__) || defined(__MMI_T9_CROATIAN__) */ 
    #if defined(__MMI_ZI_ROMANIAN__) || defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_TYPE_SMART_LOWERCASE_ROMANIAN:
    #endif /* defined(__MMI_ZI_ROMANIAN__) || defined(__MMI_T9_ROMANIAN__) */ 
    #if defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_T9_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
        case INPUT_TYPE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_TYPE_SMART_LOWERCASE_SLOVENIAN:
    #endif /* defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_T9_SLOVENIAN__) */ 

    #if defined(__MMI_ZI_GREEK__) || defined(__MMI_T9_GREEK__) || defined(__MMI_CSTAR_GREEK__)
        case INPUT_TYPE_SMART_UPPERCASE_GREEK:
        case INPUT_TYPE_SMART_LOWERCASE_GREEK:
    #endif /* defined(__MMI_ZI_GREEK__) || defined(__MMI_T9_GREEK__) */ 
            //W05.34 Fix Screen will be clear after inserting symbols
    #if !defined(__MMI_TOUCH_SCREEN__)
    #ifdef __MMI_T9__
            T9SynT9WithInputBox();
    #elif defined __MMI_ZI__
            ZiDisplay();
    #elif defined __MMI_CSTAR__
            CstarDisplay();
    #elif defined __MMI_KA__
            KonkaDisplay();
    #elif defined __MMI_ITAP__
/* under construction !*/
/* under construction !*/
    #endif 
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleRSKFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleRSKFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_disable_proprietary_symbol_display();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySymbolPickerScreenFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySymbolPickerScreenFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SYMBOL_PICKER_SCREEN, ExitSymbolPickerScreenFromMenuList, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_SYMBOL_PICKER_SCREEN);
    if (guiBuffer != NULL)
    {
        MMI_current_input_ext_type = SymbolFilterFlag;
        MMI_AP_No_Show_Symbol_List_flag = APSetNoShowSymbolFlag;
        MMI_english_input_mode_flag = SymbolEnglishOnlyFlag;
    }
    /* enable symbol table character display */
    mmi_fe_enable_proprietary_symbol_display();


    PrepareSymbolTableAndShowCategory(guiBuffer);

    SetLeftSoftkeyFunction(SymbolPickerHandleLSKFromMenuList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SymbolPickerHandleRSKFromMenuList, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitSymbolPickerScreenFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSymbolPickerScreenFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable proprietary symbol character display */
    mmi_fe_disable_proprietary_symbol_display();

    h.scrnID = SCR_SYMBOL_PICKER_SCREEN;
    h.entryFuncPtr = EntrySymbolPickerScreenFromMenuList;
    SymbolFilterFlag = MMI_current_input_ext_type;
    SymbolEnglishOnlyFlag = MMI_english_input_mode_flag;
    /* Begin AP Symbol table */
    APSetNoShowSymbolFlag = MMI_AP_No_Show_Symbol_List_flag;
    /* End AP Symbol table */
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SetInputMethodAndDoneCaptionIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IconId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetInputMethodAndDoneCaptionIcon(U16 IconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gInputMethodAndDoneCaptionIcon = IconId;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrForInputMethodAndDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrForInputMethodAndDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler (); */
    EntryNewScreen(SCR_INPUT_METHOD_AND_DONE, ExitScrForInputMethodAndDone, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_AND_DONE);
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        gInputMethodAndDoneCaptionIcon,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    /* SetExitHandler (SCR_INPUT_METHOD_AND_DONE, ExitScrForInputMethodAndDone); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrForInputMethodAndDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrForInputMethodAndDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_INPUT_METHOD_AND_DONE;
    currHistory.entryFuncPtr = EntryScrForInputMethodAndDone;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
    /* gInputMethodAndDoneCaptionIcon = 0; */
}


/*****************************************************************************
 * Pop-up common screens
 *****************************************************************************/
FuncPtr PopupFunc = NULL;
BOOL popUpTimerFlag = FALSE;
extern void ShowCategory65Screen(U8 *message, U16 message_icon, U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  DisplayPopup
 * DESCRIPTION
 *  Displays the comon pop-up screen used across all applications.
 *  This pop-up screen will not be added into history.
 *  It will GoBackHistory only when user press any key or timer expired.
 * PARAMETERS
 *  string          [IN]    Char array of string
 *  imageId         [IN]    Image ID
 *  imageOnBottom   [IN]    Reserved
 *  popupDuration   [IN]    Duration of the pop-up
 *  toneId          [IN]    Tone ID
 *  rotation        [IN]    Rotation
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopupRotated(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId,
                         mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(TRUE);

    EntryNewScreen(POPUP_SCREENID, ExitDisplayPopup, NULL, NULL);

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(rotation);
#endif

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    /* Becasue DisplayPoup will not be added into history, it will not set small screen flag */
    force_no_small_screen();
#endif

    ShowCategory65Screen(string, imageId, NULL);

    SetGroupKeyHandler(PopupTimerFlagEnable, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(PopupCloseByPressAnyKey, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);

    StartTimer(POPUP_TIMER, popupDuration, PopupTimerOver);
    popupToneId = toneId;
    if (popupToneId)
    {
        playRequestedTone(popupToneId);
    }
}
BOOL g_PopupMsg=FALSE;

#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
{
      g_PopupMsg=TRUE;
	DisplayPopupRotated(string, imageId, imageOnBottom, popupDuration, toneId, MMI_FRM_SCREEN_ROTATE_0);
}
#endif /* __MMI_SCREEN_ROTATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayPopup
 * DESCRIPTION
 *  Exit function for DisplayPopup()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDisplayPopup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    popUpTimerFlag = FALSE;
    if (popupToneId)
    {
        stopRequestedTone(popupToneId);
        popupToneId = 0;
    }
    g_PopupMsg=FALSE; 	
}


/*****************************************************************************
 * FUNCTION
 *  DisplayPopupCallBack
 * DESCRIPTION
 *  Displays the comon pop-up screen used across all applications.
 *  This pop-up screen will not be added into history.
 *  It will call callback only when timer expired.
 *  This pop-up will not GoBackHistory, and applications have to handle the screen by themselves
 * PARAMETERS
 *  string              [IN]    Char array of string
 *  imageId             [IN]    Image ID
 *  imageOnBottom       [IN]    Reserved
 *  popupDuration       [IN]    Duration of the pop-up
 *  toneId              [IN]    Tone ID
 *  f                   [IN]    Callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayPopupCallBack(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId, FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(POPUP_SCREENID, ExitDisplayPopupCallBack, NULL, NULL);
    
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    /* Becasue DisplayPoup will not be added into history, it will not set small screen flag */
    force_no_small_screen();
#endif
    
    ShowCategory65Screen(string, imageId, NULL);
    
    StartTimer(POPUP_TIMER, popupDuration, PopupTimerOverCallBack);
    PopupFunc = f;
    popupToneId = toneId;
    if (popupToneId)
    {
        playRequestedTone(popupToneId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayPopupCallBack
 * DESCRIPTION
 *  Exit function for DisplayPopup()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDisplayPopupCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    if (popupToneId)
    {
        stopRequestedTone(popupToneId);
        popupToneId = 0;
    }
    PopupFunc = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  PopupTimerFlagEnable
 * DESCRIPTION
 *  turn on popup timer flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupTimerFlagEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popUpTimerFlag = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  PopupCloseByPressAnyKey
 * DESCRIPTION
 *  Stops the timer and goes back after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupCloseByPressAnyKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (popUpTimerFlag == TRUE)
    {
        popUpTimerFlag = FALSE;
        if (popupToneId)
        {
            stopRequestedTone(popupToneId);
            popupToneId = 0;
        }

    #ifdef __MMI_SUBLCD__
        if (IsMyTimerExist(POPUP_SUBLCD))
        {
            StopTimer(POPUP_SUBLCD);
            GoBackSubLCDHistory();
        }
    #endif /* __MMI_SUBLCD__ */ 

        StopTimer(POPUP_TIMER);
        GoBackHistory();
        if (PopupFunc != NULL)
        {
            PopupFunc();
        }
        PopupFunc = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PopupTimerOver
 * DESCRIPTION
 *  Stops the timer and goes back after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupTimerOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    if (popupToneId)
    {
        stopRequestedTone(popupToneId);
        popupToneId = 0;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  PopupTimerOverCallBack
 * DESCRIPTION
 *  Stops the timer and Call Callback function after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupTimerOverCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    if (popupToneId)
    {
        stopRequestedTone(popupToneId);
        popupToneId = 0;
    }
    if (PopupFunc != NULL)
    {
        PopupFunc();
    }
    PopupFunc = NULL;
}


#if !defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  PopupNoSupport
 * DESCRIPTION
 *  Display the pop-up screen for PC Simulator limitation scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupNoSupport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR),
        IMG_GLOBAL_WARNING,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        WARNING_TONE);
    return;
}
#endif /* !defined(__MTK_TARGET__) */ 


/*****************************************************************************
 * FUNCTION
 *  DisplayConfirmCountDown
 * DESCRIPTION
 *  Display Popup Confirm Screen
 * PARAMETERS
 *  LSK_str             [IN]        
 *  LSK_img             [IN]        
 *  RSK_str             [IN]        
 *  RSK_img             [IN]        
 *  message             [IN]        
 *  message_image       [IN]        
 *  toneId              [IN]        
 *  duration            [IN]        
 *  callback            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayConfirmCountDown(
        U16 LSK_str,
        U16 LSK_img,
        U16 RSK_str,
        U16 RSK_img,
        UI_string_type message,
        MMI_ID_TYPE message_image,
        U8 toneId,
        U32 duration,
        FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_CONFIRM_SCREEN);
    EntryNewScreen(SCR_CONFIRM_SCREEN, ExitDisplayPopupConfirm, NULL, NULL);
    ShowCategory165Screen_ext(LSK_str, LSK_img, RSK_str, RSK_img, message, (U16) message_image, duration, guiBuffer);
    SetCat165TimerExpireFunc(callback);
    popupToneId = toneId;
    if (popupToneId)
    {
        playRequestedTone(popupToneId);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayConfirm
 * DESCRIPTION
 *  Display Popup Confirm Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_ROTATE__
void DisplayConfirmRotated(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                           MMI_ID_TYPE message_image, U8 toneId, mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayConfirm(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    DisplayConfirmRotatedExt(LSK_str, LSK_img, RSK_str, RSK_img, 0, 0, message, message_image, toneId, rotation);
#else
    DisplayConfirmExt(LSK_str, LSK_img, RSK_str, RSK_img, 0, 0, message, message_image, toneId);
#endif
}

#ifdef __MMI_SCREEN_ROTATE__

void DisplayConfirm(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
{
    DisplayConfirmRotated(LSK_str, LSK_img, RSK_str, RSK_img, message, message_image, toneId, MMI_FRM_SCREEN_ROTATE_0);
}

#endif /* __MMI_SCREEN_ROTATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  DisplayConfirm_ext
 * DESCRIPTION
 *  Display Popup Confirm Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_ROTATE__
void DisplayConfirmRotatedExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                           MMI_ID_TYPE message_image, U8 toneId, mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayConfirmExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_CONFIRM_SCREEN);
    EntryNewScreen(SCR_CONFIRM_SCREEN, ExitDisplayPopupConfirm, NULL, NULL);
#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(rotation);
#endif 

#ifdef __MMI_WGUI_CSK_ENABLE__
    if ((CSK_str != 0) || (CSK_img != 0))
    {
        EnableCenterSoftkey(CSK_str, CSK_img);
    }
#endif

    ShowCategory165Screen(LSK_str, LSK_img, RSK_str, RSK_img, message, (U16) message_image, guiBuffer);
    popupToneId = toneId;
    if (popupToneId)
        playRequestedTone(popupToneId);
}

#ifdef __MMI_SCREEN_ROTATE__

void DisplayConfirmExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
{
    DisplayConfirmRotatedExt(LSK_str, LSK_img, RSK_str, RSK_img, CSK_str, CSK_img, message, message_image, toneId, MMI_FRM_SCREEN_ROTATE_0);
}

#endif /* __MMI_SCREEN_ROTATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayPopupConfirm
 * DESCRIPTION
 *  Exit function for DisplayPopupConfirm()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void ExitDisplayPopupConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
    leave_full_screen();
#endif 
#ifdef __MMI_WGUI_CSK_ENABLE__    
    ResetCenterSoftkey();
#endif
    /* 121605 popup tone Calvin Start */
    if (popupToneId)
    {
        stopRequestedTone(popupToneId);
        popupToneId = 0;
    }
    /* 121605 popup tone Calvin End */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_go_back_2_history
 * DESCRIPTION
 *  Go back 2 history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_go_back_2_history(void)
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
 *  mmi_frm_highlight_inline_generic_done
 * DESCRIPTION
 *  Highlight inline done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_inline_generic_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
    SetKeyHandler(ConfirmInlineFullScreenEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_input_method_generic
 * DESCRIPTION
 *  Highlight input method generic handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_input_method_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_frm_go_back_2_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_highlight_handler
 * DESCRIPTION
 *  Register highlight generic handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_DONE_OPTION_ID, mmi_frm_highlight_inline_generic_done);
    SetHiliteHandler(MENU_INPUT_METHOD_OPTION_ID, mmi_frm_highlight_input_method_generic);
}


/*****************************************************************************
 * FUNCTION
 *  PopupSubLcdTimerOver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopupSubLcdTimerOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_SUBLCD);
    GoBackSubLCDHistory();

}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDPopupScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitSubLCDPopupScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not to add into history */
    StopTimer(POPUP_SUBLCD);
}


/*****************************************************************************
 * FUNCTION
 *  DisplaySubLcdPopup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imageId     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DisplaySubLcdPopup(U16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(imageId /* IMG_SUBLCD_CHARGER_POWER_ON */ , 0);
    SetSubLCDExitHandler(ExitSubLCDPopupScr);

    StartTimer(POPUP_SUBLCD, UI_POPUP_NOTIFYDURATION_TIME, PopupSubLcdTimerOver);

}


/*****************************************************************************
 * FUNCTION
 *  SetInterruptPopupDisplay
 * DESCRIPTION
 *  Set Interrupt popup screen is allowed to display or not.
 * PARAMETERS
 *  flag        [IN]        can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON
 * RETURNS
 *  void
 *****************************************************************************/
void SetInterruptPopupDisplay(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The value can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON or POPUP_ALL_ON */
    is_popup_allow = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetInterruptPopupDisplay
 * DESCRIPTION
 *  Get if the interrupt popup screen is allowed to display or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON
 *****************************************************************************/
U8 GetInterruptPopupDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The value can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON, or POPUP_ALL_ON */
    return is_popup_allow;
}

#ifndef __MTK_TARGET__
/* 
 * Functionality for MoDIS direct input 
 */

/* check the symbol is needed in the category */


/*****************************************************************************
 * FUNCTION
 *  mmi_is_no_need_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_is_no_need_symbol(unsigned short c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_AP_No_Show_Symbol_List_flag)
    {
        if (Is_No_Need_Show_Symbol((U8*) c))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/* 
 * We want to check the symbol is valid in the category,
 * but we need to know the code set range of the symbols first.
 * It's not used now.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_is_vaild_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_is_vaild_symbol(unsigned short c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* English symbol table */
    for (i = 0; i < SYMBOL_PICKER_MAX_SYMBOLS; i++)
    {
        if (c == *(unsigned short*)SymbolPickerSymbols[i])
        {
            return MMI_TRUE;
        }
    }

    /* Chinese symbol table */
    for (i = 0; i < SYMBOL_PICKER_MAX_CHINESE_SYMBOLS; i++)
    {
        if (c == *(unsigned short*)SymbolPickerChineseSymbols[i])
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#endif /* __MTK_TARGET__ */ /* #ifndef __MTK_TARGET_ */

