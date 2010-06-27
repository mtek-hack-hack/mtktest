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
 *  RightsMgrWhiteList.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  White list screen of Rights Manager  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include 
 */
#include "MMI_include.h"

#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"

#include "CommonScreens.h"
#include "SettingProfile.h"
#include "app_str.h"

#include "FileManagerGProt.h"
/*
 * Local Functions
 */
static void mmi_rmgr_whitelist_select(S32 menu_idx);
static void mmi_rmgr_whitelist_set_execute_key_hdlr(FuncPtr key_hdlr);
static void mmi_rmgr_whitelist_entry_option(void);
static void mmi_rmgr_whitelist_go_back_to_main(void);
static void mmi_rmgr_whitelist_select(S32 menu_idx);
static void mmi_rmgr_whitelist_set_execute_key_hdlr(FuncPtr key_hdlr);
static void mmi_rmgr_whitelist_edit_option_done(void);
static void mmi_rmgr_whitelist_edit_option_entry_cancel(void);
static void mmi_rmgr_whitelist_edit_option_input_method_go_back_2(void);
static void mmi_rmgr_whitelist_edit_option_highlight_hdlr(S32 menu_idx);
static void mmi_rmgr_whitelist_entry_edit(void);
static void mmi_rmgr_whitelist_clean_done(void);
static void mmi_rmgr_whitelist_entry_clean(void);
static void mmi_rmgr_whitelist_option_highlight_hdlr(S32 menu_idx);
static void mmi_rmgr_whitelist_entry_option(void);

/*
 * Global Variable
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_select
 * DESCRIPTION
 *  Highlight handler of the white list main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_select(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->url_sel_idx = menu_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_set_execute_key_hdlr
 * DESCRIPTION
 *  Set the execution key handler
 * PARAMETERS
 *  key_hdlr        [IN]        Key handler function pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_set_execute_key_hdlr(FuncPtr key_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(key_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_done
 * DESCRIPTION
 *  Entry function of the white list edit option done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;
    kal_int8 tmp[(MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1) *ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (DRM_get_whitelist((kal_char *)tmp, mmi_rmgr_p->url_sel_idx) && 
        app_ucs2_strcmp((kal_int8 *)mmi_rmgr_p->input_buffer, (kal_int8 *)tmp) != 0)
    {
        error = DRM_del_whitelist((kal_char *)tmp);
    }
    
    error = DRM_add_whitelist((kal_char *)mmi_rmgr_p->input_buffer);

    if (error == DRM_RESULT_OK)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE),
                     IMG_GLOBAL_ACTIVATED,
                     0,
                     UI_POPUP_NOTIFYDURATION_TIME,
                     SUCCESS_TONE);

        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT);
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
    else
    {
        DRM_add_whitelist((kal_char *)tmp);
        
        DisplayPopup((U8*) GetString(GetFileSystemErrorString(error)),
                     IMG_GLOBAL_ERROR,
                     0,
                     UI_POPUP_NOTIFYDURATION_TIME,
                     ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_entry_cancel
 * DESCRIPTION
 *  Entry function of the white list edit option cancel screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_entry_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_RMGR_WHITE_LIST_OPTION))
    {
        GoBackToHistory(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the white list edit option
 * PARAMETERS
 *  menu_idx        [IN]        Highlight menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    if (menu_idx == 0)  /* done */
    {
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_edit_option_done);
    }
    else if (menu_idx == 1) /* cancel */
    {
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_edit_option_entry_cancel);
    }
    else    /* input method */
    {
        SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        mmi_rmgr_whitelist_set_execute_key_hdlr(EntryAPRequiredInputMethodScreen);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option
 * DESCRIPTION
 *  Entry function of the white list edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_whitelist_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    const U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, STR_GLOBAL_INPUT_METHOD};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION, NULL, mmi_rmgr_whitelist_edit_option, NULL);

    RegisterHighlightHandler(mmi_rmgr_whitelist_edit_option_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        3,
        (U16*) item_texts,
        (U16*) g_mmi_rmgr_number_icons,
        NULL,
        0,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_edit_option_input_method_go_back_2
 * DESCRIPTION
 *  go back history twice
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_edit_option_input_method_go_back_2(void)
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
 *  mmi_rmgr_whitelist_entry_edit
 * DESCRIPTION
 *  Entry function of the white list edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S16 required_input_mode[] = 
    {
            INPUT_MODE_MULTITAP_LOWERCASE_ABC,
            INPUT_MODE_MULTITAP_UPPERCASE_ABC,
            INPUT_MODE_123,
        -1
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_EDIT, NULL, mmi_rmgr_whitelist_entry_edit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_EDIT);

    wgui_fill_AP_required_input_mode_set(required_input_mode);
    wgui_set_AP_required_input_mode_set_flag();

    /* full screen edit */
    ShowCategory5Screen(
        STR_ID_RMGR_WHITE_LIST_EDIT_ENTER_ADDRESS,
        0,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (INPUT_TYPE_ALPHANUMERIC_LOWERCASE),
        (U8*)mmi_rmgr_p->input_buffer,
        MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_rmgr_whitelist_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_rmgr_whitelist_edit_option_input_method_go_back_2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_go_back_to_main
 * DESCRIPTION
 *  Go back to the white list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_go_back_to_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_RMGR_WHITE_LIST_MAIN))
    {
        GoBackToHistory(SCR_ID_RMGR_WHITE_LIST_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_clean_done
 * DESCRIPTION
 *  Entry function of the white list clean done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_clean_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_del_whitelist((kal_char *)mmi_rmgr_p->input_buffer))
    {
        DisplayPopupCallBack(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE,
            mmi_rmgr_whitelist_go_back_to_main);

        DeleteScreenIfPresent(SCR_ID_RMGR_WHITE_LIST_OPTION);
    }
    else
    {
        DisplayPopupCallBack(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE,
            mmi_rmgr_whitelist_go_back_to_main);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_clean
 * DESCRIPTION
 *  Entry function of the white list clean screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_clean(void)
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
        get_string(STR_GLOBAL_CLEAR),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_rmgr_whitelist_clean_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the white list option screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_option_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_idx == 0)
    {
        /* edit */
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_edit);
    }
    else
    {
        /* clear */
        mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_clean);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_option
 * DESCRIPTION
 *  Entry function of the white list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_whitelist_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    const kal_uint16 item_text[] = {STR_GLOBAL_EDIT, STR_GLOBAL_CLEAR};
    kal_int32 num_of_item;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_OPTION, NULL, mmi_rmgr_whitelist_entry_option, NULL);

    if (DRM_get_whitelist((kal_char *)mmi_rmgr_p->input_buffer, mmi_rmgr_p->url_sel_idx))
    {
        num_of_item = 2;
    }
    else
    {
        app_ucs2_strcpy((kal_int8 *)mmi_rmgr_p->input_buffer, (kal_int8 *)L"http://");
        num_of_item = 1;
    }

        
    RegisterHighlightHandler(mmi_rmgr_whitelist_option_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_OPTION);

    ShowCategory52Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_item,
        (U16*) item_text,
        (U16*) g_mmi_rmgr_number_icons,
        NULL,
        0,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_whitelist_entry_main
 * DESCRIPTION
 *  Entry function of the white list main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_whitelist_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    kal_int32 i = 0;
    kal_bool ret = KAL_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_WHITE_LIST_MAIN, NULL, mmi_rmgr_whitelist_entry_main, NULL);

    /* fill empty white list urls with "<empty>" */
    
    for (i = 0; i < MMI_RMGR_WHITE_LIST_NUM; i++)
    {
        if (ret)
        {
            ret = DRM_get_whitelist((kal_char *)subMenuDataPtrs[i], i);
        }
        
        if (!ret)
        {
            app_ucs2_strcpy((kal_int8 *)subMenuDataPtrs[i], (kal_int8 *)"");
        }
    }

    DRM_free_whitelist();
    
    RegisterHighlightHandler(mmi_rmgr_whitelist_select);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_WHITE_LIST_MAIN);

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_RMGR),
        mmi_rmgr_get_root_icon(),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        subMenuDataPtrs,
        (U16*)g_mmi_rmgr_number_icons,
        NULL,
        0,
        mmi_rmgr_p->url_sel_idx,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    mmi_rmgr_whitelist_set_execute_key_hdlr(mmi_rmgr_whitelist_entry_option);
}

#endif /* __MMI_RMGR__ */ 

