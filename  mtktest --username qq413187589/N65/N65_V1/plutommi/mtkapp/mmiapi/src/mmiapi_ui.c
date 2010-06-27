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
 * mmiapi_ui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
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
 *============================================================================== *******************************************************************************/

#include "MMI_include.h"

// #define MMIAPI_USING_SMS
#define MMIAPI_USING_UI
#define MMIAPI_USING_BLOCKING
#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "mmiapi_func.h"
#include "mmiapi_res.h"

#include "ems.h"
// #include "SmsCoreTypes.h"
#include "Ucs2Prot.h"
#include "WrapperGprot.h"

// #include "wgui.h"
#include "Wgui_softkeys.h"
#include "gui_generic_menuitems.h"
#include "gui_generic_menus.h"
#include "LcdDr.h"
// #include "gui_config.h"
#include "gui_bytestream.h"
#include "CommonScreens.h"
#include "PhonebookTypes.h"
#include "PhoneBookGprot.h"

extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);
extern void ClearKeyEvents(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fullscreen Editor 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FULLSCREEN_EDITOR_RETURN_NONE  0
#define FULLSCREEN_EDITOR_RETURN_DONE  1
#define FULLSCREEN_EDITOR_RETURN_CANCEL   2

extern const U16 gIndexIconsImageList[];

/* function */
static void mmiapi_goto_fullscreen_editor_option(void);
static void mmiapi_exit_fullscreen_editor_with_done(void);
static void mmiapi_exit_fullscreen_editor_with_cancel(void);
static void mmiapi_enter_resume_fullscreen_editor(void);
void mmiapi_ui_enter_fullscreen_editor_rsp(module_type mod_dest);

#define STR_AT(RAW,n) (void*)(((kal_uint8*)RAW)+((n)<<1))
#define CHR_AT(RAW,n) (*(kal_uint16*)STR_AT(RAW,n))
#define CHR(x)      ((kal_uint16)x)

/////////////////////////////////////////////////////////////////////////////////////
// variables related to fullscreen editor
/////////////////////////////////////////////////////////////////////////////////////
static kal_uint8 *mmiapi_fullscreen_editor_input_buffer;
static int mmiapi_fullscreen_editor_input_buffer_max_len;

/* remember current mmiapi_fullscreen_editor type */
static int mmiapi_fullscreen_editor_texttype;
static kal_bool mmiapi_fullscreen_editor_input_required;
static S16 mmiapi_fullscreen_editor_input_type;

/* disable switching input method */
static kal_bool mmiapi_fullscreen_editor_disable_switch_IM;
static int mmiapi_fullscreen_editor_return_value;


/*****************************************************************************
 * FUNCTION
 *  mmiapi_two_goback_history
 * DESCRIPTION
 *  this function will go back two history
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_two_goback_history(void)
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
 *  mmiapi_exit_fullscreen_editor_option
 * DESCRIPTION
 *  this function exit the fullscreen editor option menu
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_exit_fullscreen_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history current;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current.scrnID = MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION;
    current.entryFuncPtr = mmiapi_goto_fullscreen_editor_option;
    CHR_AT(current.inputBuffer, 0) = CHR(0);
    GetCategoryHistory(current.guiBuffer);
    AddHistory(current);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_editor_highlight_done
 * DESCRIPTION
 *  this function exit the fullscreen editor with success return cause.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_fullscreen_editor_highlight_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmiapi_exit_fullscreen_editor_with_done, KEY_EVENT_UP);
    SetKeyHandler(mmiapi_exit_fullscreen_editor_with_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_editor_highlight_input_method
 * DESCRIPTION
 *  this function will be called when user highlight input method menu item.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_fullscreen_editor_highlight_input_method(void)
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
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_goto_fullscreen_editor_option
 * DESCRIPTION
 *  this function will goto edit option menu.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_goto_fullscreen_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 nStrItemList[3];
    U16 nNumofItem;
    S32 menuItemId = -1;
    S32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION, mmiapi_exit_fullscreen_editor_option, NULL, NULL);

    guiBuffer = (U8*) GetCurrGuiBuffer(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION);

    nNumofItem = GetNumOfChild(J2ME_MENU_FULLSCREEN_EDITOR_OPTION);
    GetSequenceStringIds(J2ME_MENU_FULLSCREEN_EDITOR_OPTION, nStrItemList);
    /* set parent id */
    SetParentHandler(J2ME_MENU_FULLSCREEN_EDITOR_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    SetHiliteHandler(J2ME_MENU_FULLSCREEN_EDITOR_OPTION_DONE, mmiapi_fullscreen_editor_highlight_done);
    SetHiliteHandler(J2ME_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD, mmiapi_fullscreen_editor_highlight_input_method);

    menuItemId = GetChildMenuIDIndexByParentMenuID(
                    J2ME_MENU_FULLSCREEN_EDITOR_OPTION,
                    J2ME_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD);
    if (menuItemId != -1)
    {
        if (mmiapi_fullscreen_editor_disable_switch_IM)
        {
            ResetBit(maskingByte, menuItemId);
        }
    }

    MaskHiliteItems(J2ME_MENU_FULLSCREEN_EDITOR_OPTION, maskingByte);
    nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);

    ShowCategory15Screen(
        MMIAPI_STR_ID_OPTION,
        (U16) NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        //MTK added by JL 031021 for image list 
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* after input method selection is done, it should go back twice to the editor screen */
    RegisterInputMethodScreenCloseFunction(mmiapi_two_goback_history);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

}

/*****************************************************************************
 * FUNCTION
 *  mmiapi_goto_fullscreen_editor_option
 * DESCRIPTION
 *  this function will goto edit option menu.
 * CALLS
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_goto_fullscreen_search_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmiapi_fullscreen_editor_set_number);

}
/* /////////////////////////////////////////////////////////////////////// */


/*****************************************************************************
 * FUNCTION
 *  mmiapi_init_fullscreen_editor
 * DESCRIPTION
 *  this function will initialize some global variables local to this file.
 * CALLS
 *  
 * PARAMETERS
 *  src                 [?]         
 *  maxlen              [IN]        
 *  type                [IN]        
 *  input_required      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_init_fullscreen_editor(kal_uint8 *src, int maxlen, int type, kal_bool input_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_NONE;

    mmiapi_fullscreen_editor_input_buffer = src;
    mmiapi_fullscreen_editor_input_buffer_max_len = maxlen;
    mmiapi_fullscreen_editor_texttype = type;
    mmiapi_fullscreen_editor_input_required = input_required;
    mmiapi_fullscreen_editor_input_type = type;

    type &= ~INPUT_TYPE_OVERRIDE_DEFAULT;
    switch (type)
    {
        case INPUT_TYPE_ALPHANUMERIC_LOWERCASE:
        case INPUT_TYPE_ALPHANUMERIC_UPPERCASE:
        case INPUT_TYPE_ALPHANUMERIC_PASSWORD:
        case INPUT_TYPE_PHONE_NUMBER:
        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
            mmiapi_fullscreen_editor_disable_switch_IM = KAL_FALSE;
            break;
        default:
            mmiapi_fullscreen_editor_disable_switch_IM = KAL_TRUE;
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_check_fullscreen_editor_input_value
 * DESCRIPTION
 *  check the validity of the input value, and prompt error message
 *  It _must_ be called from mmiapi_exit_fullscreen_editor_with_done()
 * PARAMETERS
 *  void
 * RETURNS
 *  1: ok 0: fail
 *****************************************************************************/
/* 1: ok 0: fail */
static int mmiapi_check_fullscreen_editor_input_value()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_pause_fullscreen_editor
 * DESCRIPTION
 *  this function will be called when another window want popup and use screen.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_pause_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = MMIAPI_SCREEN_FULLSCREEN_EDITOR;
    currHistory.entryFuncPtr = mmiapi_enter_resume_fullscreen_editor;
    GetCategory5History(currHistory.guiBuffer);
    CHR_AT(currHistory.inputBuffer, 0) = CHR(0);
    AddHistory(currHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_exit_fullscreen_editor_with_done
 * DESCRIPTION
 *  Check the validity of input value
 *  For some cases, we also check input values in mmiapi_set_current_focus()
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_exit_fullscreen_editor_with_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check the validity of input value
     * * For some cases, we also check input values in mmiapi_set_current_focus()
     */
    if (!mmiapi_check_fullscreen_editor_input_value())
    {
        return;
    }

    /* mmiapi_discard_editor_buffer(); */
    mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_DONE;
    mmiapi_ui_enter_fullscreen_editor_rsp(MOD_JASYN);
    if (GetActiveScreenId() == MMIAPI_SCREEN_FULLSCREEN_EDITOR)
    {
        GoBackHistory();
    }
    else
    {
        GoBacknHistory(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_exit_fullscreen_editor_with_cancel
 * DESCRIPTION
 *  This function will exit the fullscreen editor and return cancel error code.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_exit_fullscreen_editor_with_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_CANCEL;
    GoBackHistory();
    mmiapi_ui_enter_fullscreen_editor_rsp(MOD_JASYN);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_editor_customize_key
 * DESCRIPTION
 *  This function will remap keypad
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_fullscreen_editor_customize_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_fullscreen_editor_disable_switch_IM)
    {
        ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_number_not_emtry
 * DESCRIPTION
 *  LSK handle when number input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_fullscreen_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SEARCH, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmiapi_goto_fullscreen_search_number, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_number_not_empty
 * DESCRIPTION
 *  LSK handle when number input is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_fullscreen_number_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmiapi_exit_fullscreen_editor_with_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_enter_resume_fullscreen_editor
 * DESCRIPTION
 *  This function will resum last paused fullscreen editor
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_enter_resume_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(MMIAPI_SCREEN_FULLSCREEN_EDITOR, mmiapi_pause_fullscreen_editor, NULL, NULL);

/*    clear_left_softkey();
    clear_right_softkey();
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();*/

    guiBuffer = (U8*) GetCurrGuiBuffer(MMIAPI_SCREEN_FULLSCREEN_EDITOR);

    if ( (mmiapi_fullscreen_editor_texttype & (~INPUT_TYPE_OVERRIDE_DEFAULT))
            == INPUT_TYPE_PHONE_NUMBER )
    {
        RegisterInputBoxEmptyFunction(mmiapi_fullscreen_number_empty);
        RegisterInputBoxNotEmptyFunction(mmiapi_fullscreen_number_not_empty);
        ShowCategory5Screen(
            MMIAPI_STR_ID_INPUT_TITLE,  /* title */
            (U16) NULL,                 /* image */
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmiapi_fullscreen_editor_input_type,
            (U8*) mmiapi_fullscreen_editor_input_buffer,
            mmiapi_fullscreen_editor_input_buffer_max_len,
            guiBuffer);
    }
    else if ( ((mmiapi_fullscreen_editor_texttype & (~INPUT_TYPE_OVERRIDE_DEFAULT))
            == INPUT_TYPE_SIGNED_NUMERIC ) || 
         ((mmiapi_fullscreen_editor_texttype & (~INPUT_TYPE_OVERRIDE_DEFAULT))
            == INPUT_TYPE_SIGNED_NUMERIC_PASSWORD ) ||
         ((mmiapi_fullscreen_editor_texttype & (~INPUT_TYPE_OVERRIDE_DEFAULT))
            == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC ) ||
         ((mmiapi_fullscreen_editor_texttype & (~INPUT_TYPE_OVERRIDE_DEFAULT))
            == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD ) )
    {
        ShowCategory5Screen(
            MMIAPI_STR_ID_INPUT_TITLE,  /* title */
            (U16) NULL,                 /* image */
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmiapi_fullscreen_editor_input_type,
            (U8*) mmiapi_fullscreen_editor_input_buffer,
            mmiapi_fullscreen_editor_input_buffer_max_len,
            guiBuffer);
        SetLeftSoftkeyFunction(mmiapi_exit_fullscreen_editor_with_done, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory5Screen(
            MMIAPI_STR_ID_INPUT_TITLE,  /* title */
            (U16) NULL,                 /* image */
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmiapi_fullscreen_editor_input_type,
            (U8*) mmiapi_fullscreen_editor_input_buffer,
            mmiapi_fullscreen_editor_input_buffer_max_len,
            guiBuffer);
        SetLeftSoftkeyFunction(mmiapi_goto_fullscreen_editor_option, KEY_EVENT_UP);
    }

    SetCategory5RightSoftkeyFunction(mmiapi_exit_fullscreen_editor_with_cancel, KEY_EVENT_UP);

    /* customize key */
    mmiapi_fullscreen_editor_customize_key();
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_enter_fullscreen_editor
 * DESCRIPTION
 *  enter full screen editor and put mmiapi screen into history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_enter_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we only backup the buffer for the first time */
    /* mmiapi_backup_editor_buffer(mmiapi_fullscreen_editor_input_buffer,mmiapi_fullscreen_editor_input_buffer_max_len); */
    mmiapi_enter_resume_fullscreen_editor();
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_ui_enter_fullscreen_editor_req
 * DESCRIPTION
 *  enter fullscreen editor
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_ui_enter_fullscreen_editor_req(mmiapi_ui_enter_fullscreen_editor_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    mmiapi_init_fullscreen_editor(msg->editor_buffer, msg->maxlen, msg->type, msg->is_must_input);
    ClearKeyEvents();   /* clear all keypad buffer */
    mmiapi_enter_fullscreen_editor();
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_ui_enter_fullscreen_editor_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_ui_enter_fullscreen_editor_rsp(module_type mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmiapi_ui_enter_fullscreen_editor_rsp_struct *msg = NEW_LOCAL_PTR(mmiapi_ui_enter_fullscreen_editor_rsp_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_fullscreen_editor_return_value == FULLSCREEN_EDITOR_RETURN_DONE)
    {
        msg->result = KAL_TRUE;
    }
    else
    {
        msg->result = KAL_FALSE;
    }
    msg->text_length = mmiapi_fullscreen_editor_input_buffer_max_len;

    SEND_MESSAGE(MOD_MMI, mod_dest, MMI_J2ME_SAP, MSG_ID_MMIAPI_UI_ENTER_FULLSCREEN_EDITOR_RSP, msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_ui_enter_idle_screen_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_ui_enter_idle_screen_rsp(module_type mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SEND_MESSAGE(MOD_MMI, mod_dest, 0, MSG_ID_MMIAPI_UI_ENTER_IDLE_SCREEN_RSP, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_ui_enter_idle_screen_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_ui_enter_idle_screen_req(mmiapi_ui_enter_idle_screen_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    DisplayIdleScreen();

    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_ui_enter_idle_screen_rsp(mod_src);
    }
    BLOCKING_FINISH(mod_src);
}

/*****************************************************************************
 * FUNCTION
 *  mmiapi_fullscreen_editor_set_number
 * DESCRIPTION
 *  set the phone number into edior buffer
 * PARAMETERS
 *  name         [IN] entry's name
 *  number       [IN] entry's phonenumber
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_fullscreen_editor_set_number(S8* name, S8* number)
{
    if(number)
    {
        mmi_ucs2ncpy((S8*) mmiapi_fullscreen_editor_input_buffer, (PS8) number, mmiapi_fullscreen_editor_input_buffer_max_len-1);
    }
    HistoryReplace(MMIAPI_SCREEN_FULLSCREEN_EDITOR, MMIAPI_SCREEN_FULLSCREEN_EDITOR, mmiapi_enter_resume_fullscreen_editor);
    GoBackToHistory(MMIAPI_SCREEN_FULLSCREEN_EDITOR);
}
