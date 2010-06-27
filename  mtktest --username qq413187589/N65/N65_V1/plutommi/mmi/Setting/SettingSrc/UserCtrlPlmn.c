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
 * UserCtrlPlmn.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for user control PLMN management.
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


#include "MMI_include.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "PrefNwksGprot.h"
#include "CommonScreens.h"
#include "MessagesExDcl.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "MessagesResourceData.h"
#include "PreferredNwksStruct.h"
#include "PrefNwksGprot.h"
#include "CustResDef.h"
#include "IdleAppDef.h"


/**************************************************************************
   Pre-definition
**************************************************************************/
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__

/**************************************************************************
   Global variables
**************************************************************************/
extern U8 gPLMN[];
UserCtrlPlmnListContext gUserCtrlPlmnList;

/**************************************************************************
   Function Prototypes
**************************************************************************/
extern void mmi_phb_op_email_custom_function(void);
extern void RefreshNwProviderName(U8 *);
void mmi_netset_entry_user_ctrl_plmn_add_data(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_access_user_ctrl_plmn_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  write_flag      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_access_user_ctrl_plmn_nvram(U8 write_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (write_flag)
    {
        WriteRecord(
            NVRAM_EF_USER_CTRL_PLMN_LID,
            1,
            (void*)(&gUserCtrlPlmnList.PrefPLMN[0][0]),
            NVRAM_EF_USER_CTRL_PLMN_SIZE,
            &error);
    }
    else
    {
        ReadRecord(
            NVRAM_EF_USER_CTRL_PLMN_LID,
            1,
            (void*)(&gUserCtrlPlmnList.PrefPLMN[0][0]),
            NVRAM_EF_USER_CTRL_PLMN_SIZE,
            &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_user_ctrl_plmn_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_get_user_ctrl_plmn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 plmn_num;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_access_user_ctrl_plmn_nvram(0);

    gUserCtrlPlmnList.PlmnListSize = 0;

    for (i = 0; i < MAX_USER_CTRL_PLMN; i++)
    {
        memcpy((char*)(&plmn_num), gUserCtrlPlmnList.PrefPLMN[i], sizeof(U32));
        if (plmn_num != 0)
        {
            gUserCtrlPlmnList.PlmnListSize++;
        }
        else
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_construct_user_ctrl_plmn_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hintArray       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_construct_user_ctrl_plmn_hint(U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U32 plmn_num;
    U8 plmn_tmp[MAX_PLMN_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < gUserCtrlPlmnList.PlmnListSize; i++)
    {
        memset((S8*) hintData[i], 0, MAX_SUB_MENU_SIZE);
        memcpy((char*)(&plmn_num), gUserCtrlPlmnList.PrefPLMN[i], sizeof(U32));

        mmi_netset_bcd_short_2_plmn_str(plmn_num, plmn_tmp);

        mmi_asc_to_ucs2((S8*) hintData[i], (S8*) plmn_tmp);
        hintArray[i] = hintData[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_user_ctrl_plmn_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_user_ctrl_plmn_list_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gUserCtrlPlmnList.CurrSelPlmn = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_exec_options_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_exec_options_highlight_handler(S32 index)
{
    if (gUserCtrlPlmnList.PlmnListSize == MAX_USER_CTRL_PLMN)
    {
        ExecuteCurrHiliteHandler(index + 1);
    }
    else
    {
        ExecuteCurrHiliteHandler(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_user_ctrl_plmn_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_user_ctrl_plmn_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U16 nStrItemList[2];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 ItemIcons[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS, NULL, mmi_netset_entry_user_ctrl_plmn_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
    nNumofItem = GetNumOfChild(MENU_ID_NETSET_USER_CTRL_PLMN_OPTIONS);

    ItemIcons[0] = IMG_GLOBAL_L1;
    ItemIcons[1] = IMG_GLOBAL_L2;

    GetSequenceStringIds(MENU_ID_NETSET_USER_CTRL_PLMN_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
    RegisterHighlightHandler(mmi_netset_exec_options_highlight_handler);

    if (gUserCtrlPlmnList.PlmnListSize == 0)
    {
        nNumofItem = 1;
    }
    else if (gUserCtrlPlmnList.PlmnListSize == MAX_USER_CTRL_PLMN)
    {
        nNumofItem = 1;
        nStrItemList[0] = nStrItemList[1];
    }
    else
    {
        /* keep 2 items */
    }

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        ItemIcons,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_show_user_ctrl_plmn_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_show_user_ctrl_plmn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U8 *PlmnListHint[MAX_SUB_MENUS];
    PU8 nStrItemList[MAX_USER_CTRL_PLMN];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_USER_CTRL_PLMN_LIST, NULL, mmi_netset_show_user_ctrl_plmn_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_USER_CTRL_PLMN_LIST);

    RegisterHighlightHandler(mmi_netset_highlight_user_ctrl_plmn_list_hdlr);
    if (!gUserCtrlPlmnList.PlmnListSize)
    {
        /* no record */
        nStrItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_NETSET_USER_CTRL_PLMN,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            (U8 **) nStrItemList,
            NULL,
            0,
            guiBuffer);
    }
    else
    {
        for (i = 0; i < MAX_USER_CTRL_PLMN; i++)
        {
            nStrItemList[i] = NULL;
        }

        for (i = 0; i < gUserCtrlPlmnList.PlmnListSize; i++)
        {
            mmi_asc_to_ucs2(
                (S8*) gUserCtrlPlmnList.tmpPlmnListData[i],
                (S8*) gUserCtrlPlmnList.PrefPLMN[i] + sizeof(U32));
            nStrItemList[i] = gUserCtrlPlmnList.tmpPlmnListData[i];
        }

        mmi_netset_construct_user_ctrl_plmn_hint(PlmnListHint);
        ShowCategory6Screen(
            STR_ID_NETSET_USER_CTRL_PLMN,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gUserCtrlPlmnList.PlmnListSize,
            (U8 **) nStrItemList,
            PlmnListHint,
            0,
            guiBuffer);
    }

    SetLeftSoftkeyFunction(mmi_netset_entry_user_ctrl_plmn_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_entry_user_ctrl_plmn_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_user_ctrl_plmn_add_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_user_ctrl_plmn_add_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 plmn_ansii[MAX_PLMN_LEN + 1], opname_asnii[MAX_LENGTH_DISPLAY_NAME];
    U32 plmn_usr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gUserCtrlPlmnList.PlmnAddNumber) < MAX_PLMN_LEN - 1 ||
        mmi_ucs2cmp((S8*) gUserCtrlPlmnList.PlmnAddString, (S8*) L"") == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_ADD);
        return;
    }

    mmi_ucs2_to_asc((S8*) plmn_ansii, (S8*) gUserCtrlPlmnList.PlmnAddNumber);
    mmi_ucs2_to_asc((S8*) opname_asnii, (S8*) gUserCtrlPlmnList.PlmnAddString);

    CloseCategory57Screen();

    if (mmi_netset_retrieve_opname_from_plmn(plmn_ansii, NULL) >= 0)
    {
        /* duplicated */
        DisplayPopup(
            (PU8) GetString(STR_ID_NETSET_DUPLICATED_PLMN),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_ADD);
        return;
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_ADD);

    /* write data to nvram */
    plmn_usr = mmi_netset_plmn_str_2_bcd_short(plmn_ansii);
    memset(gUserCtrlPlmnList.PrefPLMN[gUserCtrlPlmnList.PlmnListSize], 0, 24);
    memcpy(gUserCtrlPlmnList.PrefPLMN[gUserCtrlPlmnList.PlmnListSize], (char*)(&plmn_usr), sizeof(U32));
    memcpy(
        gUserCtrlPlmnList.PrefPLMN[gUserCtrlPlmnList.PlmnListSize] + sizeof(U32),
        opname_asnii,
        strlen((S8*) opname_asnii));
    gUserCtrlPlmnList.PlmnListSize++;

    mmi_netset_access_user_ctrl_plmn_nvram(1);

    RefreshNwProviderName(gPLMN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_user_ctrl_plmn_add_inline_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_set_user_ctrl_plmn_add_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gUserCtrlPlmnList.PlmnAddNumber, 0, (MAX_PLMN_LEN + 1) * ENCODING_LENGTH);
    memset(gUserCtrlPlmnList.PlmnAddString, 0, MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);

    if (!IsScreenPresent(SCR_ID_NETSET_USER_CTRL_PLMN_LIST))
    {
        mmi_asc_to_ucs2((S8*) gUserCtrlPlmnList.PlmnAddNumber, (S8*) gPLMN);
    }

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_NETSET_PRR_MCC_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) gUserCtrlPlmnList.PlmnAddNumber,
        MAX_PLMN_LEN + 1,
        INPUT_TYPE_NUMERIC);
    //SetInlineItemFullWidth(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    DisableInlineItemHighlight(&wgui_inline_items[1]);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_ID_NETSET_OP_NAME_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[3],
        (PU8) gUserCtrlPlmnList.PlmnAddString,
        MAX_LENGTH_DISPLAY_NAME,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
#if defined(__MMI_TOUCH_SCREEN__)
    SetInlineTextEditCustomFunction(&wgui_inline_items[3], mmi_phb_op_email_custom_function);
#endif
    //SetInlineItemFullWidth(&wgui_inline_items[3]);
    EnableInlineItemBoundary(&wgui_inline_items[3]);
    DisableInlineItemHighlight(&wgui_inline_items[3]);

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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_save_user_ctrl_plmn_cancel
 * DESCRIPTION
 *  Cancellation of save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_save_user_ctrl_plmn_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_ADD);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_save_user_ctrl_plmn_confirm
 * DESCRIPTION
 *  Confirmation to save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_save_user_ctrl_plmn_confirm(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(mmi_netset_save_user_ctrl_plmn_cancel, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_netset_entry_user_ctrl_plmn_add_one, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_netset_exit_user_ctrl_plmn_add_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_exit_user_ctrl_plmn_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;            /* Variable to hold the history data */
    S16 nHistory = 0;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_NETSET_USER_CTRL_PLMN_ADD;
    Scr.entryFuncPtr = mmi_netset_entry_user_ctrl_plmn_add_data;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_user_ctrl_plmn_add_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_user_ctrl_plmn_add_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_USER_CTRL_PLMN_ADD, mmi_netset_exit_user_ctrl_plmn_add_data, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_USER_CTRL_PLMN_ADD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_NETSET_USER_CTRL_PLMN_ADD, &inputBufferSize);      /* added for inline edit history */

    InitializeCategory57Screen();
    mmi_netset_set_user_ctrl_plmn_add_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    ClearHighlightHandler();

    if (IsScreenPresent(SCR_ID_NETSET_USER_CTRL_PLMN_LIST))
    {
        ShowCategory57Screen(
            STR_GLOBAL_ADD,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            4,
            IconList,
            wgui_inline_items,
            1,
            guiBuffer);
    }
    else
    {
        ShowCategory57Screen(
            STR_GLOBAL_ADD,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            4,
            IconList,
            wgui_inline_items,
            3,
            guiBuffer);
    }

    SetCategory57RightSoftkeyFunctions(mmi_netset_save_user_ctrl_plmn_confirm, GoBackHistory);

    DeleteScreenIfPresent(SCR_ID_NETSET_UNKNOWN_PLMN_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_user_ctrl_plmn_del_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_user_ctrl_plmn_del_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_NETSET_USER_CTRL_PLMN_OPTIONS);

    /* write data to nvram */
    for (i = gUserCtrlPlmnList.CurrSelPlmn + 1; i < gUserCtrlPlmnList.PlmnListSize; i++)
    {
        memcpy(gUserCtrlPlmnList.PrefPLMN[i - 1], gUserCtrlPlmnList.PrefPLMN[i], 24);
    }

    memset(gUserCtrlPlmnList.PrefPLMN[gUserCtrlPlmnList.PlmnListSize - 1], 0, 24);
    gUserCtrlPlmnList.PlmnListSize--;

    mmi_netset_access_user_ctrl_plmn_nvram(1);

    RefreshNwProviderName(gPLMN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_confirm_user_ctrl_plmn_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_confirm_user_ctrl_plmn_del(void)
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
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_netset_entry_user_ctrl_plmn_del_one, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_user_ctrl_plmn_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_user_ctrl_plmn_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_netset_entry_user_ctrl_plmn_add_data, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_entry_user_ctrl_plmn_add_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_user_ctrl_plmn_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_user_ctrl_plmn_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_netset_confirm_user_ctrl_plmn_del, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_confirm_user_ctrl_plmn_del, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_init_user_ctrl_plmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_init_user_ctrl_plmn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_NETSET_USER_CTRL_PLMN_ADD, mmi_netset_highlight_user_ctrl_plmn_add);
    SetHiliteHandler(MENU_ID_NETSET_USER_CTRL_PLMN_DEL, mmi_netset_highlight_user_ctrl_plmn_del);

    gUserCtrlPlmnList.UnknownOpCheck = MMI_TRUE;

    mmi_netset_get_user_ctrl_plmn_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_user_ctrl_plmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_user_ctrl_plmn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_netset_show_user_ctrl_plmn_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_show_user_ctrl_plmn_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_unknown_operator_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_netset_unknown_operator_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gUserCtrlPlmnList.UnknownOpCheck == MMI_FALSE || g_pwr_context.CurrentServiceType != FULL_SERVICE)
    {
        return 0;
    }

    if (mmi_bootup_is_roaming())
    {
        if (gUserCtrlPlmnList.UnknownOpCheck == MMI_TRUE &&
            gUserCtrlPlmnList.PlmnListSize < MAX_USER_CTRL_PLMN &&
            mmi_netset_retrieve_opname_from_plmn(gPLMN, NULL) == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (gUserCtrlPlmnList.UnknownOpCheck == MMI_TRUE &&
            gUserCtrlPlmnList.PlmnListSize < MAX_USER_CTRL_PLMN &&
            gOpNameValid == MMI_FALSE && mmi_netset_retrieve_opname_from_plmn(gPLMN, NULL) == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_unknown_operator_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_unknown_operator_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_UNKNOWN_PLMN_MSG, NULL, mmi_netset_unknown_operator_query, NULL);

    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ShowCategory2Screen(
            STR_ID_NETSET_USER_CTRL_PLMN,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            STR_ID_NETSET_UNKNOWN_PLMN_MSG,
            NULL);

        gUserCtrlPlmnList.UnknownOpCheck = MMI_FALSE;

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_netset_entry_user_ctrl_plmn_add_data, KEY_EVENT_UP);
    }
    else
    {    
        ShowCategory2Screen(
            STR_ID_NETSET_USER_CTRL_PLMN,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            STR_ID_NETSET_UNKNOWN_PLMN_MSG,
            NULL);
    }
}

/**************************************************************************
   Pre-definition
**************************************************************************/
#endif /* __MMI_USER_CTRL_PLMN_SUPPORT__ */ 

