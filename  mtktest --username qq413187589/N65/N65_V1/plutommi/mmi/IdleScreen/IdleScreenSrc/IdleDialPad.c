/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *  IdleDialPad.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for The Idle screen application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#include "MiscFunctions.h"
#include "CommonScreens.h"      /* DisplayPopup */

#include "IdleAppDef.h"
#include "IdleAppProt.h"

#ifdef __MMI_UCM__


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_init_dial_pad_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_init_dial_pad_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_DIAL, mmi_idle_highlight_dial_pad_option_dial);
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_PHB_SAVE, mmi_idle_highlight_dial_pad_option_save);
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_INPUT_METHOD, mmi_idle_highlight_dial_pad_option_input);
    SetHiliteHandler(MENU_ID_DIALER_SCREEN_OPTIONS_CHANGE_MODE, mmi_idle_highlight_dial_pad_option_mode);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_highlight_dial_pad_option_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_highlight_dial_pad_option_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(mmi_idle_entry_dial_voip_call, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(mmi_idle_entry_dial_selection, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        case P_GSM_ONLY:
        default:
            MMI_ASSERT(0);  /* shall not enter this in GSM only mode */
            break;
    }
#else /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_idle_entry_dial_selection, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_highlight_dial_pad_option_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_highlight_dial_pad_option_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change left and right soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* set left and right soft key handler */
    SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set key handler for left and right arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_highlight_dial_pad_option_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_highlight_dial_pad_option_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change left and right soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* set left and right soft key handler */
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_voip_go_back_2_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_highlight_dial_pad_option_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_highlight_dial_pad_option_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change left and right soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* set left and right soft key handler */
    SetLeftSoftkeyFunction(mmi_netset_entry_change_dial_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* set key handler for left and right arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_change_dial_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_change_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.DigitScreenDialMode = (g_idle_context.DigitScreenDialMode) ? 0 : 1;  /* 0: GSM, 1: WLAN */

    sprintf(g_idle_context.DialPadCallBuffer, "");
    g_idle_context.IdleScreenDigitKeyCode = -1;

    IdleScreenDigitHandler();

    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR);

    if (mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED || mmi_idle_get_dial_mode() == 0)
    {
        /* enter VoIP dialer screen first then change dialer mode to digit dialer */
        /* restore RSK/LSK handers because they are changed to disable long press */
        SetLeftSoftkeyFunction(mmi_idle_entry_dial_pad_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dial_voip_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dial_voip_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_DIAL_SCREEN__
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
#else 
    if (!SSCStringParsing2())
#endif 
        mmi_voip_app_make_call((U8*) g_idle_context.DialPadCallBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_dial_mode
 * DESCRIPTION
 *  Get dial mode
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_dial_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.DigitScreenDialMode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_dial_mode
 * DESCRIPTION
 *  Get dial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_idle_get_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_idle_context.DigitScreenDialMode;
}

#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_delete_dial_pad_screens
 * DESCRIPTION
 *  Callback function of UCM dial option
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_delete_dial_pad_screens(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    /* no need to delet VoIP dial pad screen because it will be deleted by VoIP application */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dial_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dial_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_app_entry_dial_option((U8*) g_idle_context.DialPadCallBuffer, mmi_idle_delete_dial_pad_screens, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dial_pad_option
 * DESCRIPTION
 *  Entry function of dial pad screen option menu (only available for __MMI_UCM__)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dial_pad_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U16 nNumofItem;

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    U16 nStrItemList[4];    /* dial, save, input method, and change dial mode */
#else 
    U16 nStrItemList[2];    /* dial and save */
#endif 

    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(IDLE_SCREEN_DIGIT_OPTIONS_ID, NULL, mmi_idle_entry_dial_pad_option, NULL);
    guiBuffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_OPTIONS_ID);

    nNumofItem = GetNumOfChild_Ext(MENU_ID_DIALER_SCREEN_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_DIALER_SCREEN_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_DIALER_SCREEN_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* reset the guiBuffer to enable long press after go back to the digit dialer screen */
    if (GetHistoryScrID(IDLE_SCREEN_DIGIT_HANDLER_ID, &History) == ST_SUCCESS)
    {
        if (History->guiBuffer != NULL)
        {
            OslMfree(History->guiBuffer);
            History->guiBuffer = NULL;
        }
    }
}

#endif /* __MMI_UCM__ */ 

