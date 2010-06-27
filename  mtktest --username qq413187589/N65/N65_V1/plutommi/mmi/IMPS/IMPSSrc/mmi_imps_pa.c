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
 * mmi_imps_pa.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements presence related functions for IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_IMPS__
/*  Include: MMI header file */
#include "Stdlib.h"
#include "ProtocolEvents.h"

#include "CommonScreens.h"
#include "SimDetectionGprot.h"


#include "wgui_inline_edit.h"

#include "PhoneSetupGprots.h"
#include "Conversions.h"

#include "IMPSResDef.h"
#include "mmi_imps_prot.h"

#include "FileManagerGProt.h"
#include "Fmt_struct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif

/*  Include: PS header file */
/* ... Add More PS header */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern wgui_inline_item wgui_inline_items[];
extern const U16 g_imps_inline_icons[];
extern const S8 g_imps_wv[];

/***************************************************************************** 
* Global Function
*****************************************************************************/


#ifdef IMPS_TEST_CODE

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_test_get_watch_list_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_test_get_watch_list_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_pre_entry_watch_list(NULL);
    mmi_imps_entry_watch_list();
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_pa_hilite_hdlr
 * DESCRIPTION
 *  Initialize all presence highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_pa_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* about me */
    SetHiliteHandler(MENU_ID_IMPS_CONT_ABOUT_ME, mmi_imps_hilite_about_me);
    SetHiliteHandler(MENU_ID_IMPS_CONT_PRESENCE, mmi_imps_hilite_presence);
    SetHiliteHandler(MENU_ID_IMPS_CONT_PUBLIC_PROFILE_1, mmi_imps_hilite_public_profile_1); 
    SetHiliteHandler(MENU_ID_IMPS_CONT_PUBLIC_PROFILE_2, mmi_imps_hilite_public_profile_2);    
    SetHiliteHandler(MENU_ID_IMPS_PRESENCE_FILE_OPT_SEL, mmi_imps_hilite_presence_pic_sel);
    SetHiliteHandler(MENU_ID_IMPS_PRESENCE_FILE_OPT_VIEW, mmi_imps_hilite_presence_pic_view);
    SetHiliteHandler(MENU_ID_IMPS_PRESENCE_FILE_OPT_DEL, mmi_imps_hilite_presence_pic_del);
    SetHiliteHandler(MENU_ID_IMPS_CONT_WATCHER_LIST, mmi_imps_hilite_get_watch_list);
    
    /* about friend */
    SetHiliteHandler(MENU_ID_IMPS_CONT_ABOUT_FRIEND, mmi_imps_hilite_about_friend);
    SetHiliteHandler(MENU_ID_IMPS_ABOUT_FRIEND_EDIT, mmi_imps_hilite_about_friend_edit);
    SetHiliteHandler(MENU_ID_IMPS_ABOUT_FRIEND_REFRESH, mmi_imps_hilite_about_friend_refresh);
}


#define ABOUT_ME_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_about_me
 * DESCRIPTION
 *  Hilite handler of Contact List -> About Me option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_about_me(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_about_me, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_about_me
 * DESCRIPTION
 *  Entry About Me.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_about_me(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prevent the user from entering when contact list not ready */
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }    

    /* Check version of current server */
    if (imps_p->gen_info.imps_version >= IMPS_CSP_VERSION_13)
    {
        U8 *guiBuffer;
        U16 itemList[3];
        U16 nItems;

        EntryNewScreen(SCR_ID_IMPS_ABOUT_ME, NULL, mmi_imps_entry_about_me, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ABOUT_ME);
        SetParentHandler(MENU_ID_IMPS_CONT_ABOUT_ME);        
        nItems = GetNumOfChild(MENU_ID_IMPS_CONT_ABOUT_ME);
        GetSequenceStringIds(MENU_ID_IMPS_CONT_ABOUT_ME, itemList);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ShowCategory52Screen(
            STR_ID_IMPS_ABOUT_ME,
            GetRootTitleIcon(MENU_ID_IMPS_MAIN),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            itemList,
            (PU16) gIndexIconsImageList,
            0,
            0,
            0,
            guiBuffer);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);        
    }
    else
    {
        mmi_imps_pre_entry_presence();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_presence
 * DESCRIPTION
 *  Hilite handler of Presence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_presence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_presence, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_presence
 * DESCRIPTION
 *  Pre-Entry function of inline editor screen for About Me->Presence.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_presence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *nvram_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

    /* read data from NVRAM */
    if (imps_p->about_info == NULL)
    {
        imps_p->about_info = OslMalloc(sizeof(mmi_imps_presence_struct));
        memset(imps_p->about_info, 0, sizeof(mmi_imps_presence_struct));
    }

    /* retrieve data from NVRAM */
    mmi_imps_util_read_nvram((void*)nvram_buff);

    /* status */
    imps_p->about_info->status = (S32) nvram_buff->about_me.status;
    imps_p->about_info->mood = (S32) nvram_buff->about_me.mood;

    /* my profile */
    mmi_ucs2cpy((S8*) imps_p->about_info->my_prof, (S8*) nvram_buff->about_me.my_prof);

    /* keneng : alias */
    mmi_ucs2cpy((S8*) imps_p->about_info->alias, (S8*) nvram_buff->about_me.alias);

    /* my picture */
    imps_p->about_info->is_pic = (S32) nvram_buff->about_me.is_pic;
    if (imps_p->about_info->is_pic)
    {
        mmi_imps_util_get_img_path((S8*) imps_p->about_info->my_pic);
        mmi_ucs2cat((S8*) imps_p->about_info->my_pic, (S8*) IMPS_ABOUT_PIC_PREFIX);
        mmi_ucs2cat(
            (S8*) imps_p->about_info->my_pic,
            (S8*) mmi_fmgr_extract_ext_file_name((S8*) nvram_buff->about_me.pic_name));
        mmi_ucs2cpy((S8*) imps_p->about_info->file_buff, (S8*) imps_p->about_info->my_pic);
        mmi_ucs2cpy((S8*) imps_p->about_info->pic_name, (S8*) nvram_buff->about_me.pic_name);
    }

    OslMfree(nvram_buff);
    mmi_imps_entry_presence();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence
 * DESCRIPTION
 *  Entry inline editor screen for About Me->Presence.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PRESENCE_INLINE, mmi_imps_exit_presence, NULL, NULL);

    InitializeCategory57Screen();
    mmi_imps_presence_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PRESENCE_INLINE);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_PRESENCE_INLINE, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_PRESENCE, inputBuffer);
    }

    if (imps_p->about_info->is_pic_changed && GetInlineDoneFlag(guiBuffer) == 0)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_PRESENCE,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_PRESENCE,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_presence_save, mmi_imps_presence_free_mem_and_back);
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_PRESENCE_INLINE, (HistoryDelCBPtr) mmi_imps_presence_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_free_mem_and_back
 * DESCRIPTION
 *  Free memory and go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_free_mem_and_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_presence_buff();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_del_callback
 * DESCRIPTION
 *  Callback function when About Me inline editor screen is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_presence_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param != (void*)MMI_TRUE)
    {
        mmi_imps_free_presence_buff();
    }
    else if (imps_p->gen_info.curr_action == 0)
    {
        /* if it's not saving presence, free the buffer */
        mmi_imps_free_presence_buff();
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_presence_buff
 * DESCRIPTION
 *  Free memory of presence screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_presence_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* about me buffer is not empty and currently is not updating */
    if (imps_p->about_info != NULL && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_UPDATE_PA_REQ)
    {
        OslMfree(imps_p->about_info);
        imps_p->about_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_presence
 * DESCRIPTION
 *  Exit function for About Me->Presence inline editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_presence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_IMPS_PRESENCE_INLINE, mmi_imps_entry_presence);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of About Me screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* status */
    imps_p->about_info->status_list[0] = (U8*) GetString(STR_ID_IMPS_ONLINE);
    imps_p->about_info->status_list[1] = (U8*) GetString(STR_ID_IMPS_AWAY);
    imps_p->about_info->status_list[2] = (U8*) GetString(STR_ID_IMPS_OFFLINE);

    /* mood */
    for (i = 0; i < IMPS_NUM_MOOD; i++)
    {
        imps_p->about_info->mood_list[i] = (U8*) GetString((U16) (STR_ID_IMPS_HAPPY + i));
    }

    /* file */
    imps_p->about_info->file_sel_list[0] = (U8*) GetString(STR_GLOBAL_NONE);
    if (mmi_ucs2strlen((S8*) imps_p->about_info->pic_name) == 0)
    {
        imps_p->about_info->file_sel_list[1] = (U8*) GetString(STR_ID_IMPS_SEL_FROM_FILE);
    }
    else
    {
        imps_p->about_info->file_sel_list[1] = (U8*) imps_p->about_info->pic_name;
    }

    /* keneng : alias */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_ALIAS));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_ALIAS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->about_info->alias,
        IMPS_MAX_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);

    /* My Profile */
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_MY_PROFILE));
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_MY_PROFILE,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) imps_p->about_info->my_prof,
        IMPS_MAX_PA_STATUS_TEXT_LEN,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);

    /* Status */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_STATUS));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 3, imps_p->about_info->status_list, &imps_p->about_info->status);

    /* Mood */
    SetInlineItemActivation(&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_MOOD));
    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[7], 11, imps_p->about_info->mood_list, &imps_p->about_info->mood);

    /* My Picture */
    SetInlineItemActivation(&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_MY_PICTURE));

    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[9], 2, imps_p->about_info->file_sel_list, &imps_p->about_info->is_pic);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[9], mmi_imps_hilite_presence_inline_sel);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_presence_inline_sel
 * DESCRIPTION
 *  Highlight handler of My Picture in Presence menu
 * PARAMETERS
 *  index       [IN]        Index of inline seletion item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_presence_inline_sel(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    if (index != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetCategory57LeftSoftkeyFunction(mmi_imps_entry_presence_sel_file);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence_sel_file
 * DESCRIPTION
 *  Entry About Me -> Select From File screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence_sel_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* only 3 options */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PRESENCE_SEL_FILE, NULL, mmi_imps_entry_presence_sel_file, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PRESENCE_SEL_FILE);
    SetParentHandler(MENU_ID_IMPS_PRESENCE_FILE_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_PRESENCE_FILE_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_PRESENCE_FILE_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (mmi_ucs2strlen((S8*) imps_p->about_info->file_buff) == 0)    /* no file selected */
    {
        numItems = 1;
    }

    ShowCategory52Screen(
        STR_ID_IMPS_SEL_FILE,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_presence_pic_sel
 * DESCRIPTION
 *  Highlight handler of About Me -> Presence -> Select From File -> Select File
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_presence_pic_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_presence_pic_sel, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_presence_pic_sel, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_presence_pic_view
 * DESCRIPTION
 *  Highlight handler of About Me -> Presence -> Select From File -> View
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_presence_pic_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_presence_pic_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_entry_presence_pic_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_presence_pic_del
 * DESCRIPTION
 *  Highlight handler of About Me -> Presence -> Select From File -> Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_presence_pic_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_entry_presence_pic_del, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence_pic_sel
 * DESCRIPTION
 *  Entry function of About Me -> Presence -> Select From File -> Select File
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence_pic_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
	FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
	FMGR_FILTER_SET(&filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(APP_IMPS, FMGR_SELECT_FILE | FMGR_SELECT_REPEAT, filter, (S8*) L"root", mmi_imps_presence_sel_pic_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_sel_pic_callback
 * DESCRIPTION
 *  Callback function for selected image from File Manager
 * PARAMETERS
 *  filePath        [IN]        File path+name from File Manager
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_sel_pic_callback(void *filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_IMPS_PRESENCE_SEL_FILE);
    }
    else
    {
        S32 fileLen;
        S32 f_result;
        mmi_imps_presence_struct *about_info;
        
    #ifdef __DRM_SUPPORT__
		if (DRM_get_object_method(NULL, (U16*) filePath) !=  DRM_METHOD_NONE)
		{
			mmi_imps_util_disp_warning_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
		}
    #endif /* __DRM_SUPPORT__ */

		if ((f_result = mmi_imps_util_get_file_size(filePath, &fileLen)) == FS_NO_ERROR)
        {
            if (fileLen > IMPS_MAX_PIC_SIZE)
            {
                mmi_imps_util_disp_err_popup(STR_ID_IMPS_SIZE_TOO_LARGE);
                return;
            }
			if (fileLen == 0)
            {
                mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_FILE);                
                return;
            }
        }
        else
        {
            mmi_imps_util_disp_err_popup(GetFileSystemErrorString(f_result));
            return;
        }

        /* store file in buffer */
        about_info = imps_p->about_info;
        if (is_short)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (kal_uint8*) about_info->pic_name,
                (FMGR_MAX_FILE_LEN + 1) * 2,
                (kal_uint8*) mmi_fmgr_extract_file_name((S8*) filePath),
                PhnsetGetDefEncodingType());
            mmi_ucs2cpy((S8*) about_info->file_buff, (S8*) filePath);
        }
        else
        {
            mmi_ucs2cpy((S8*) about_info->file_buff, (S8*) filePath);
            mmi_ucs2cpy((S8*) about_info->pic_name, (S8*) mmi_fmgr_extract_file_name((S8*) filePath));
        }

        /* change RSK of signature secreen to Done */
        about_info->is_pic_changed = TRUE;
        about_info->is_pic = (S32) TRUE;

        GoBackToHistory(SCR_ID_IMPS_PRESENCE_SEL_FILE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence_pic_view
 * DESCRIPTION
 *  Entry function of About Me -> Presence -> Select From File -> Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence_pic_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PRESENCE_VIEW_PIC, NULL, mmi_imps_entry_presence_pic_view, NULL);
    ShowCategory222Screen(
        STR_GLOBAL_VIEW,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_WHITE,
        NULL,
        (S8*) imps_p->about_info->file_buff,
        FALSE,
        NULL,
        GDI_IMAGE_SRC_FROM_FILE);
        
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence_pic_del
 * DESCRIPTION
 *  Entry function of About Me -> Presence -> Select From File -> Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence_pic_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_imps_entry_confirm(STR_GLOBAL_DELETE, mmi_imps_entry_presence_pic_del_yes, GoBackHistory);
}


/*****************************************************************************
* FUNCTION
*  mmi_imps_entry_presence_pic_del_yes
* DESCRIPTION
*  Entry function of About Me -> Presence -> Select From File -> Delete -> Yes
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_imps_entry_presence_pic_del_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->about_info->is_pic = FALSE;
    imps_p->about_info->is_pic_changed = TRUE;
    imps_p->about_info->file_buff[0] = 0;
    imps_p->about_info->file_buff[1] = 0;
    imps_p->about_info->pic_name[0] = 0;
    imps_p->about_info->pic_name[1] = 0;
    mmi_imps_util_disp_popup_done();
    DeleteUptoScrID(SCR_ID_IMPS_PRESENCE_SEL_FILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_save
 * DESCRIPTION
 *  LSK handler for presence editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_SAVE, mmi_imps_presence_save_yes, mmi_imps_presence_save_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_save_no
 * DESCRIPTION
 *  Give up saving Presence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_IMPS_CONT_OPT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_save_yes
 * DESCRIPTION
 *  Proceed saving Presence
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_presence_struct *about_info = imps_p->about_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_display_progressing();

    /* check picture state */
    if (about_info->is_pic && mmi_ucs2strlen((S8*) about_info->file_buff) > 0)
    {
        about_info->is_pic_changed = TRUE;
        if (mmi_ucs2cmp((S8*) about_info->my_pic, (S8*) about_info->file_buff))
        {
            if (mmi_ucs2strlen((S8*) about_info->my_pic)) /* remove previous file if exists */
            {
                FS_Delete((U16*) about_info->my_pic);
            }

            mmi_imps_util_get_img_path((S8*) about_info->my_pic);
            mmi_ucs2cat((S8*) about_info->my_pic, (S8*) IMPS_ABOUT_PIC_PREFIX);

            mmi_ucs2cat(
                (S8*) about_info->my_pic,
                (S8*) mmi_fmgr_extract_ext_file_name((S8*) about_info->file_buff));

            FS_Delete((U16*) about_info->my_pic);

            /* special case for file copy, if the user press END key before copy finished, the state will become mismatch, 
               that cause us to free about_info buffer when screen is deleted */
            imps_p->gen_info.curr_action = MSG_ID_MMI_IMPS_UPDATE_PA_REQ;

            mmi_fmgr_send_copy_req(
                FMGR_ACTION_COPY,
                (U8*) about_info->file_buff,
                (U8*) about_info->my_pic,
                mmi_imps_presence_save_pic_callback);
            return;
        }
        about_info->is_pic_changed = FALSE;
    }
    else
    {
        if (mmi_ucs2strlen((S8*) about_info->my_pic)) /* remove previous file if exists */
        {
            FS_Delete((U16*) about_info->my_pic);
            about_info->my_pic[0] = 0;
        }

        about_info->is_pic = FALSE;
        about_info->is_pic_changed = TRUE;
    }
#ifdef IMPS_TEST_CODE
    mmi_imps_presence_save_done(0);
#else 
    mmi_imps_ps_update_pa_req();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_save_pic_callback
 * DESCRIPTION
 *  Callback function for copying picture of Presence
 * PARAMETERS
 *  info        [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_save_pic_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    mmi_imps_presence_struct *about_info = imps_p->about_info;
    S32 attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (msgPtr->result >= 0)
    {
        attr = FS_GetAttributes((const WCHAR *) about_info->my_pic);
        if (attr & FS_ATTR_READ_ONLY != 0)
        {
            FS_SetAttributes((const WCHAR *)about_info->my_pic, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
        }
#ifdef IMPS_TEST_CODE
		mmi_imps_presence_save_done(0);
#else 
		mmi_imps_ps_update_pa_req();
#endif
    }
    else
    {
        imps_p->gen_info.curr_action = 0;
        mmi_imps_util_disp_err_popup(GetFileSystemErrorString(msgPtr->result));
        DeleteUptoScrID(SCR_ID_IMPS_PRESENCE_INLINE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_write_to_nvram
 * DESCRIPTION
 *  Write About Me info to NVRAM and send request to protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_write_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_nvram_struct *nvram_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read data from NVRAM to sync */
    mmi_imps_util_read_nvram((void*)nvram_buff);

    /* picture */
    if (imps_p->about_info->is_pic_changed)
    {
        nvram_buff->about_me.is_pic = (U8) imps_p->about_info->is_pic;

        if (imps_p->about_info->is_pic) /* extract file extension */
        {
            mmi_ucs2cpy(
                (S8*) nvram_buff->about_me.pic_name,
                (S8*) imps_p->about_info->pic_name /* mmi_fmgr_extract_file_name((S8*) imps_p->about_info->file_buff) */ );
        }
    }

    /* status */
    nvram_buff->about_me.status = (U8) imps_p->about_info->status;
    nvram_buff->about_me.mood = (U8) imps_p->about_info->mood;

    /* my profile */
    mmi_ucs2cpy((S8*) nvram_buff->about_me.my_prof, (S8*) imps_p->about_info->my_prof);

    /* keneng : alias */
    mmi_ucs2cpy((S8*) nvram_buff->about_me.alias, (S8*) imps_p->about_info->alias);

    mmi_imps_util_write_nvram((void*)nvram_buff);

    OslMfree(nvram_buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_save_done
 * DESCRIPTION
 *  Callback function when update presence response comes.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_presence_save_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == 0)
    {
        mmi_imps_util_disp_popup_done();
        /* update contact list of myself */
        imps_p->cont_info.cont_list[0].availability = (U8) imps_p->about_info->status;
        mmi_ucs2cpy((S8*) imps_p->cont_info.cont_list[0].alias, (S8*) imps_p->about_info->alias);
		mmi_imps_presence_write_to_nvram();
    }
    else
    {
        /* display popup with error message */
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
		
		/* remove previous file */
		if (mmi_ucs2strlen((S8*) imps_p->about_info->pic_name) > 0 && imps_p->about_info->is_pic_changed)
		{
			
			if (mmi_ucs2strlen((S8*) imps_p->about_info->my_pic))
            {
                FS_Delete((U16*) imps_p->about_info->my_pic);
            }
			imps_p->about_info-> is_pic_changed = FALSE;
			imps_p->about_info->is_pic = FALSE;
			imps_p->about_info->file_buff[0] = 0;
            imps_p->about_info->file_buff[1] = 0;
			imps_p->about_info->pic_name[0] = 0;
            imps_p->about_info->pic_name[1] = 0;
		}
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
        /* free presence buffer */
        mmi_imps_free_presence_buff();
    }
    else
    {
        if (result == 0)
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
        }
        else
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_PRESENCE_INLINE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_public_profile_1
 * DESCRIPTION
 *  Hilite handler of Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_public_profile_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_public_profile_1, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_public_profile_1
 * DESCRIPTION
 *  Pre-Entry Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_public_profile_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->pp_info = (mmi_imps_public_profile_inline_struct*) OslMalloc(sizeof(mmi_imps_public_profile_inline_struct));     
    memset(imps_p->pp_info, 0, sizeof(mmi_imps_public_profile_inline_struct));
    
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) IMPS_PUBLIC_PROFILE);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY | FS_CREATE);
    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        U32 len;

        FS_Read(
            fileHandle,
            (void*)&imps_p->pp_info->public_profile,
            sizeof(mmi_imps_public_profile_struct),
            (U32*) & len);
        FS_Close(fileHandle);

        /* entry public profile inline screen */
        mmi_imps_entry_public_profile_1();
    }
    else
    {
        OslMfree(imps_p->pp_info);
        mmi_imps_util_disp_err_popup(GetFileSystemErrorString(fileHandle));
        return;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_public_profile_1
 * DESCRIPTION
 *  Entry Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_public_profile_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, mmi_imps_exit_public_profile_1, NULL, NULL);

    InitializeCategory57Screen();
    mmi_imps_public_profile_1_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_PUBLIC_PROFILE_1, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_PUBLIC_PROFILE_1,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_PUBLIC_PROFILE_1,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_public_profile_save, mmi_imps_public_profile_free_mem_and_back);
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, (HistoryDelCBPtr) mmi_imps_public_profile_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_free_mem_and_back
 * DESCRIPTION
 *  Free memory and go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_free_mem_and_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_free_public_profile_buff();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_del_callback
 * DESCRIPTION
 *  Callback function when About Me inline editor screen is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_public_profile_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param != (void*)MMI_TRUE)
    {
        mmi_imps_free_public_profile_buff();
    }
    else if (imps_p->gen_info.curr_action == 0)
    {
        /* if it's not saving presence, free the buffer */
        mmi_imps_free_public_profile_buff();
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_public_profile_buff
 * DESCRIPTION
 *  Free memory of Public profile screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_free_public_profile_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* public profile buffer is not empty and currently is not updating */
    if (imps_p->pp_info != NULL && imps_p->gen_info.curr_action != MSG_ID_MMI_IMPS_UPDATE_PP_REQ)
    {
        OslMfree(imps_p->pp_info);
        imps_p->pp_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_public_profile_1
 * DESCRIPTION
 *  Exit function for About Me->Public profile inline editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_public_profile_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_exit_inline_editor(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, mmi_imps_entry_public_profile_1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_allocate_history_buffer
 * DESCRIPTION
 *  mmi_imps_allocate_history_buffer
 * PARAMETERS
 *  param1    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void* mmi_imps_allocate_history_buffer(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->history_buffer = (U8*)OslMalloc(1500);
    
    return (void*)imps_p->history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_free_history_buffer
 * DESCRIPTION
 *  mmi_imps_free_history_buffer
 * PARAMETERS
 *  param1    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imps_free_history_buffer(void* param1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(imps_p->history_buffer)
    {
        OslMfree(imps_p->history_buffer);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_inline_editor
 * DESCRIPTION
 *  Exit function for inline editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_imps_exit_inline_editor(U16 scrnID, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    AddHistoryEx(
        scrnID,
        entryFuncPtr,
        GetCategoryHistory,
        GetCategory57DataSize,
        GetCategory57Data,
        mmi_imps_allocate_history_buffer,
        mmi_imps_free_history_buffer);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_imps_exit_public_profile_2
 * DESCRIPTION
 *  Exit function for About Me->Public profile inline editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_exit_public_profile_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_exit_inline_editor(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, mmi_imps_entry_public_profile_2);
}


/*****************************************************************************
 * FUNCTION
 *  ImpsDateEditorCallback
 * DESCRIPTION
 *  This function is to fills the Data to set the time in case Set Time is called from AT.
 *  Functionality:
 * PARAMETERS
 *  par1        [IN]        
 *  par2        [IN]        
 *  par3        [IN]        
 *  par4        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ImpsDateEditorCallback(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) DateStr, (S8*) year);
    mmi_ucs2cat((S8*) DateStr, (S8*) "/");
    mmi_ucs2cat((S8*) DateStr, (S8*) month);
    mmi_ucs2cat((S8*) DateStr, (S8*) "/");
    mmi_ucs2cat((S8*) DateStr, (S8*) day);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_1_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of Public profile screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_1_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_public_profile_inline_struct *pp_info = imps_p->pp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Prepare */
    /* for (i = 0; i < STR_ID_IMPS_CC_END - STR_ID_IMPS_CC_END; i++)
    {
        pp_info->country_list[i]= (U8*) GetString((U16) (STR_ID_IMPS_CC_BEGIN + i));
    }*/

    pp_info->gender_list[0] = (U8*) GetString(STR_ID_IMPS_NO_DISCLOSE);
    pp_info->gender_list[1] = (U8*) GetString(STR_ID_IMPS_FEMALE);
    pp_info->gender_list[2] = (U8*) GetString(STR_ID_IMPS_MALE);
    pp_info->gender_list[3] = (U8*) GetString(STR_ID_IMPS_UNSPECIFIED);

    for (i = 0; i < 8; i++)
    {
        pp_info->marital_status_list[i] = (U8*) GetString((U16) (STR_ID_IMPS_NO_DISCLOSE + i));
    }
    
    /* Age */
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_AGE));
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, KEY_EVENT_UP);
    SetInlineItemDate(
        &wgui_inline_items[1],
        (U8*) &pp_info->public_profile.day_buff[0],
        (U8*) &pp_info->public_profile.month_buff[0],
        (U8*) &pp_info->public_profile.year_buff[0],
        ImpsDateEditorCallback);
    SetInlineItemFullWidth(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    RightJustifyInlineItem(&wgui_inline_items[1]);
    set_inline_date_boundary(2030, 1930, 12, 1);    

    /* Country */

    /* Friendly Name */
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_FRIENDLY_NAME));
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_FRIENDLY_NAME,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) pp_info->public_profile.fname,
        IMPS_MAX_FRIENDLY_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);     

    /* Gender */
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_GENDER));
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[5], 4, pp_info->gender_list, &pp_info->public_profile.gender);    

    /* Marital Status */
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString(STR_ID_IMPS_MARITAL_STATUS));
    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[7], 8, pp_info->marital_status_list, &pp_info->public_profile.marital_status);    

    /* Free Text */
    SetInlineItemCaption(&wgui_inline_items[8], (U8*) GetString(STR_ID_IMPS_FREE_TEXT));
    SetInlineItemActivation(&wgui_inline_items[9], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[9],
        STR_ID_IMPS_FREE_TEXT,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) pp_info->public_profile.free_text,
        IMPS_MAX_FREE_TEXT_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[9], mmi_imps_hilite_prof_full_edit);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_save
 * DESCRIPTION
 *  LSK handler for presence editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_confirm(STR_GLOBAL_SAVE, mmi_imps_public_profile_save_yes, mmi_imps_public_profile_save_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_save_no
 * DESCRIPTION
 *  Give up saving Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_IMPS_CONT_OPT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_save_yes
 * DESCRIPTION
 *  Proceed saving Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 *buff = OslMalloc(IMPS_MAX_ID_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) imps_p->pp_info->public_profile.fname) == 0)   
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_FRIENDLY_NAME);
		OslMfree(buff);
        return;
    }
    else 
	{
		mmi_ucs2_to_asc((S8*) buff, (S8*) imps_p->pp_info->public_profile.fname);
		if (buff[0] == ' ')
		{
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_INVALID_FRIENDLY_NAME);
			OslMfree(buff);
			return;
		}
		else
		{
			OslMfree(buff);
		}
	}

    mmi_imps_display_progressing();

    /* mmi_imps_public_profile_write_to_file(); */

    /* send request to protocol */
#ifdef IMPS_TEST_CODE
    mmi_imps_public_profile_save_done(0);
#else 
    mmi_imps_ps_update_pp_req();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_write_to_file
 * DESCRIPTION
 *  Write Public profile to file and send request to protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_write_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) IMPS_PUBLIC_PROFILE);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);

    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        U32 len;

        FS_Write(
                fileHandle,
                (void*)&imps_p->pp_info->public_profile,
                sizeof(mmi_imps_public_profile_struct),
                (U32*) & len);

        FS_Close(fileHandle);
    }
    else
    {
        /* Fail to save to file */
        /* mmi_imps_util_disp_warning_popup(GetFileSystemErrorString(fileHandle)); */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_save_done
 * DESCRIPTION
 *  Callback function when update public profile response comes.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_save_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK)
    {
        mmi_imps_public_profile_write_to_file();
        mmi_imps_util_disp_popup_done();
    }
    else
    {
        /* display popup with error message */
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
        /* free presence buffer */
        mmi_imps_free_public_profile_buff();
    }
    else
    {
        if (result == IMPS_OK)
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT);
        }
        else
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_public_profile_2_fill_inline_struct
 * DESCRIPTION
 *  Fill inline editor structure of Public profile screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_public_profile_2_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_public_profile_inline_struct *pp_info = imps_p->pp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /* City */
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_IMPS_CITY));
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_IMPS_CITY,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) pp_info->public_profile.city,
        IMPS_MAX_CITY_NAME_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_imps_hilite_prof_full_edit);           

    /* Intention */
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_ID_IMPS_INTENTION));
    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_ID_IMPS_INTENTION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) pp_info->public_profile.intention,
        IMPS_MAX_INTENTION_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_imps_hilite_prof_full_edit);    

    /* Hobbies */
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString(STR_ID_IMPS_HOBBIES));
    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_ID_IMPS_HOBBIES,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        (U8*) pp_info->public_profile.hobbies,
        IMPS_MAX_HOBBY_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_imps_hilite_prof_full_edit);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_public_profile_2
 * DESCRIPTION
 *  Hilite handler of Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_public_profile_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_public_profile_2, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_public_profile_2
 * DESCRIPTION
 *  Pre-Entry Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_public_profile_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    imps_p->pp_info = (mmi_imps_public_profile_inline_struct*) OslMalloc(sizeof(mmi_imps_public_profile_inline_struct));    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(imps_p->pp_info, 0, sizeof(mmi_imps_public_profile_inline_struct));
    
    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) IMPS_PUBLIC_PROFILE);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY | FS_CREATE);
    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        U32 len;

        FS_Read(
            fileHandle,
            (void*)&imps_p->pp_info->public_profile,
            sizeof(mmi_imps_public_profile_struct),
            (U32*) & len);
        FS_Close(fileHandle);

        /* entry public profile inline screen */
		if (mmi_ucs2strlen((S8*) imps_p->pp_info->public_profile.fname) == 0)   
		{
			mmi_imps_util_disp_err_popup(STR_ID_IMPS_EMPTY_FRIENDLY_NAME);
			OslMfree(imps_p->pp_info);
			return;
		}
        mmi_imps_entry_public_profile_2();
    }
    else
    {
        OslMfree(imps_p->pp_info);
        mmi_imps_util_disp_err_popup(GetFileSystemErrorString(fileHandle));
        return;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_public_profile_2
 * DESCRIPTION
 *  Entry Public profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_public_profile_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, mmi_imps_exit_public_profile_2, NULL, NULL);

    InitializeCategory57Screen();
    mmi_imps_public_profile_2_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, IMPS_INLINE_PUBLIC_PROFILE_2, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_IMPS_PUBLIC_PROFILE_2,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        IMPS_INLINE_PUBLIC_PROFILE_2,
        (U16*) g_imps_inline_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_imps_public_profile_save, mmi_imps_public_profile_free_mem_and_back);
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_PUBLIC_PROFILE_INLINE, (HistoryDelCBPtr) mmi_imps_public_profile_del_callback);
}


#define _ABOUT_FRIEND_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_about_friend
 * DESCRIPTION
 *  Highlight handler of Contact List -> About
 *  Me (Friends)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_about_friend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_about_friend, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_about_friend, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_about_friend
 * DESCRIPTION
 *  Pre-Entry function of Contact List -> About Me (Friends)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_about_friend(void)
{
    if (imps_p->friend_info.profile_text == NULL)
    {
        imps_p->friend_info.profile_text = OslMalloc(IMPS_PUBLIC_PROFILE_DISP_BUFF * ENCODING_LENGTH);
        imps_p->friend_info.profile_text[0] = 0;
    }
    mmi_imps_entry_about_friend();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_about_friend
 * DESCRIPTION
 *  Entry function of Contact List -> About Me (Friends)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_about_friend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *img = NULL;
    U8 tmp_availability = IMPS_PA_USER_NOT_AVAILABLE;

    mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }   

    /* different contact, reset data */
    if (mmi_imps_util_is_id_same((S8*) imps_p->friend_info.id, (S8*) cont->id) == FALSE)
    {
        imps_p->friend_info.file_name[0] = 0;
        strcpy((S8*) imps_p->friend_info.id, (S8*) cont->id);
        mmi_ucs2cpy((S8*)imps_p->friend_info.profile_text, (S8*) cont->prof_text);
        imps_p->cont_info.clear_gui_buff = TRUE;
    }
    else
    {
        if (mmi_ucs2strlen((S8*) imps_p->friend_info.file_name))
        {
            U8 tempbuff[20];
            
            sprintf((S8*)tempbuff, "%s%s", (U8*) imps_directory, IMPS_USER_CONTENT_FOLDER);
            mmi_asc_to_ucs2((S8*) imps_p->path_buff, (S8*) tempbuff);            
            mmi_ucs2cat((S8*) imps_p->path_buff, (S8*) imps_p->friend_info.file_name);
            img = (S8*) imps_p->path_buff;
        }
    }

    /* set to un-available when status unknown */
    if (cont->availability != IMPS_PA_USER_UNKNOWN)
    {
        tmp_availability = cont->availability;
    }

    if (mmi_ucs2strlen((S8*) cont->nick_name) != 0)
    {
        mmi_imps_util_copy_with_dot((S8*) cont->nick_name, (S8*) imps_p->file_buff, IMPS_MAX_NAME_LEN);        
    }
    else if (mmi_ucs2strlen((S8*) cont->alias) != 0)
    {
        mmi_imps_util_copy_with_dot((S8*) cont->alias, (S8*) imps_p->file_buff, IMPS_MAX_NAME_LEN);   
    }
    else
    {
        S8 *id_buff = OslMalloc(IMPS_MAX_ID_LEN * ENCODING_LENGTH);

        mmi_asc_to_ucs2((S8*) id_buff, (S8*) cont->id);
        mmi_imps_util_copy_with_dot((S8*) id_buff, (S8*) imps_p->file_buff, IMPS_MAX_NAME_LEN);

        OslMfree(id_buff);
    }    

    EntryNewScreen(SCR_ID_IMPS_ABOUT_FRIEND, NULL, mmi_imps_entry_about_friend, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ABOUT_FRIEND);

    if (imps_p->cont_info.clear_gui_buff)
    {
        guiBuffer = NULL;
    }

    ShowCategory420Screen(
        STR_ID_IMPS_VIEW_CONT_DETAIL,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        imps_p->file_buff,
        img,
        IMG_ID_IMPS_ABOUT_DEFAULT,
        STR_ID_IMPS_MOOD,
        (UI_string_type) GetString((U16) (cont->mood + STR_ID_IMPS_HAPPY)),
        (PU8) GetImage((U16) (cont->mood + IMG_ID_IMPS_HAPPY)),
        STR_ID_IMPS_STATUS,
        (UI_string_type) GetString((U16) (tmp_availability + STR_ID_IMPS_ONLINE)),
        (PU8) GetImage((U16) (tmp_availability + IMG_ID_IMPS_ABOUT_ONLINE)),
        (U8*) imps_p->friend_info.profile_text,   /* cont->prof_text */
        (S32) mmi_ucs2strlen((S8*) imps_p->friend_info.profile_text),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_about_friend_opt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_IMPS_ABOUT_FRIEND, (HistoryDelCBPtr) mmi_imps_about_friend_del_callback);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_del_callback
 * DESCRIPTION
 *  Callback function when About Friend screen is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imps_about_friend_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param != (void*)MMI_TRUE)
    {
        /* Free about friend buffer */
        if (imps_p->friend_info.profile_text != NULL)
        {
            OslMfree(imps_p->friend_info.profile_text);
            imps_p->friend_info.profile_text = NULL;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_about_friend_opt
 * DESCRIPTION
 *  Entry optino screen of Friend's Detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_about_friend_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_ABOUT_FRIEND_OPT, NULL, mmi_imps_entry_about_friend_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_ABOUT_FRIEND_OPT);

    SetParentHandler(MENU_ID_IMPS_ABOUT_FRIEND_OPT);
    numItems = GetNumOfChild(MENU_ID_IMPS_ABOUT_FRIEND_OPT);
    GetSequenceStringIds(MENU_ID_IMPS_ABOUT_FRIEND_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_about_friend_edit
 * DESCRIPTION
 *  Highlight handler of Friend's Detail -> Option -> Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_about_friend_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_pre_entry_about_friend_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_imps_pre_entry_about_friend_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_about_friend_refresh
 * DESCRIPTION
 *  Highlight handler of Friend's Detail -> Option -> Refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_about_friend_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_about_friend_refersh, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_about_friend_edit
 * DESCRIPTION
 *  Pre-Entry fnuction of Friend's Detail -> Option -> Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pre_entry_about_friend_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) imps_p->file_buff, (S8*) cont->nick_name);

    /* re-use input name screen */
    mmi_imps_entry_cont_input_name();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_edit_done
 * DESCRIPTION
 *  Proceed editing friend's name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_about_friend_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) cont->nick_name, (S8*) imps_p->file_buff);

    /* should save after response back */
    /* mmi_imps_util_write_cont(); */

    mmi_imps_display_progressing();

    mmi_imps_edit_cont_req((U8*) cont->group_id, (U8*) cont->id, (S8*) cont->nick_name);

    /* force to redraw contact list */
    imps_p->cont_info.clear_gui_buff = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_edit_finish
 * DESCRIPTION
 *  Result of Edit
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_about_friend_edit_finish(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * partial success, subscribe error (server not support)
     * regard it as success
     */
    if (result == IMPS_OK || result == IMPS_ERROR_SUBSCRIPTION_NOT_SUPPORT)
    {
        mmi_imps_util_write_cont();
        mmi_imps_util_disp_popup_done();
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(result));
    }

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        if (active_scr == SCR_ID_IMPS_PROGRESS)
        {
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ABOUT_FRIEND);
        }
    }

    /* force to redraw contact list */
    imps_p->cont_info.clear_gui_buff = TRUE;
    imps_p->gen_info.is_reentry = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_refersh
 * DESCRIPTION
 *  Refresh status of friend
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_about_friend_refersh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_about_friend_abort,
        mmi_imps_about_friend_abort);

#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_about_friend_refresh_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_ps_get_single_pa_req((U8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_abort
 * DESCRIPTION
 *  About refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_about_friend_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();
#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_about_friend_refresh_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_abort_get_pa_req();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_about_friend_refresh_finish
 * DESCRIPTION
 *  Finish refreshing status of friend
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_about_friend_refresh_finish( /* S32 result */ void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
    {
        GoBackToHistory(SCR_ID_IMPS_ABOUT_FRIEND);
    }
    else
    {
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ABOUT_FRIEND);
    }

    /* force to redraw contact list */
    imps_p->cont_info.clear_gui_buff = TRUE;
}


#define WATCH_LIST_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_get_watch_list
 * DESCRIPTION
 *  Highlight handler of Get Watcher List option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_get_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imps_get_watch_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_watch_list
 * DESCRIPTION
 *  Handler of Get Watcher List option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall not function before auto-update finished */
    if (!imps_p->gen_info.auto_update_done)
    {
        mmi_imps_util_disp_warning_popup(STR_ID_IMPS_ERR_CONT_NOT_READY);
        return;
    }

    /* display progressing screen */
    mmi_imps_pre_entry_progressing(
        STR_ID_IMPS,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_ID_IMPS_PROGRESSING),
        NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        mmi_imps_get_watch_list_abort,
        mmi_imps_get_watch_list_abort);

    /* reset context of search */
    imps_p->search_result.count = 0;

#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_test_get_watch_list_complete, KEY_SEND, KEY_EVENT_DOWN);
#else /* IMPS_TEST_CODE */ 
    imps_p->search_result.search_cause = IMPS_SEARCH_WATCHER;
    mmi_imps_ps_get_watch_list_req();
#endif /* IMPS_TEST_CODE */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_watch_list_abort
 * DESCRIPTION
 *  Abort getting watch list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_watch_list_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_entry_abort();
#ifdef IMPS_TEST_CODE
    SetKeyHandler(mmi_imps_get_watch_list_abort_finish, KEY_SEND, KEY_EVENT_DOWN);
#else 
    mmi_imps_ps_abort_get_watch_list_req();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_get_watch_list_abort_finish
 * DESCRIPTION
 *  Aborting getting watch list finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_get_watch_list_abort_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->search_result.count)    /* some result already came back */
    {
        mmi_imps_entry_search_result();
        DeleteUptoScrID(SCR_ID_IMPS_CONT_OPT);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            GoBackToHistory(SCR_ID_IMPS_CONT_OPT);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_IMPS_CONT_OPT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pre_entry_watch_list
 * DESCRIPTION
 *  Pre-Entry function of watch list. Retrieve data from file.
 * PARAMETERS
 *  filename        [?]     [?]     [?]     [?]
 *  file_path(?)        [IN]        File_path of search result(?)(?)(?)
 * RETURNS
 *  result of open file
 *****************************************************************************/
S32 mmi_imps_pre_entry_watch_list(S16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    FS_HANDLE fileHandle = 0;

    imps_watcher_entity_struct *buff = (imps_watcher_entity_struct*) OslMalloc(sizeof(imps_watcher_entity_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = (S32) imps_p->search_result.count;

    if (count)
    {
        U32 len;
        S32 result;

        fileHandle = FS_Open((U16*) filename, FS_READ_ONLY);

        if (fileHandle > 0)
        {
            for (i = 0; i < count; i++)
            {
                result = FS_Read(fileHandle, (void*)buff, sizeof(imps_watcher_entity_struct), &len);

                if (result == FS_NO_ERROR)
                {
                    strcpy((S8*) imps_p->search_result.entity[i].id, (S8*) buff->watcher_user_id);
                    memset(&imps_p->search_result.entity[i].sname[0], 0, sizeof(imps_p->search_result.entity[i].sname));
                }
            }
            FS_Close(fileHandle);
        }
    }

    OslMfree(buff);
    return (S32) fileHandle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_watch_list
 * DESCRIPTION
 *  Display watcher list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_watch_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_items = (S32) imps_p->search_result.count;

    if (num_of_items == 0)
    {
        mmi_imps_util_disp_empty_popup();
        return;
    }

    EntryNewScreen(SCR_ID_IMPS_WATCHER_LIST, NULL, mmi_imps_entry_watch_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_WATCHER_LIST);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_imps_hilite_watch_list);

    num_of_items = (S32) imps_p->search_result.count;

    for (i = 0; i < num_of_items; i++)
    {
        mmi_imps_util_ansi_2_ucs2_menu(
            (S8*) imps_p->search_result.entity[i].id,
            (S8*) subMenuData[i],
            MAX_SUBMENU_CHARACTERS);
        mmi_imps_util_generate_name_hint((S8*) imps_p->search_result.entity[i].sname, i, MAX_SUBMENU_CHARACTERS);
        subMenuDataPtrs[i] = subMenuData[i];
    }

    ShowCategory53Screen(
        STR_ID_IMPS_WATCHER_LIST,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_GLOBAL_ADD,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    if (imps_p->cont_info.no_cont == IMPS_MAX_NO_CONT || imps_p->group_info.no_group == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_imps_pre_entry_sel_group, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_hilite_watch_list
 * DESCRIPTION
 *  Highlight handler of watch list item
 * PARAMETERS
 *  index       [IN]        Index of highlighting item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_hilite_watch_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->search_result.curr_item = (U8) index;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_presence_authentication
 * DESCRIPTION
 *  Entry presence authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_presence_authentication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    UI_character_type temp_buff[IMPS_MAX_CONTENT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMPS_PRESENCE_AUTHENTICATION, NULL, mmi_imps_entry_presence_authentication, NULL);

    mmi_imps_util_play_tone(IMPS_MSG_TONE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMPS_PRESENCE_AUTHENTICATION);

    SetParentHandler(0);

    mmi_imps_pa_auth_string((S8*) temp_buff);

    ShowCategory78Screen(
        STR_ID_IMPS_PRESENCE_AUTHENTICATION,
        GetRootTitleIcon(MENU_ID_IMPS_MAIN),
        STR_ID_IMPS_ACCEPT,
        0,
        STR_ID_IMPS_REJECT,
        0,
        NULL,
        (U8*) temp_buff,
        mmi_ucs2strlen((S8*) temp_buff),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_imps_entry_pa_auth_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_imps_entry_pa_auth_reject, KEY_EVENT_UP);  
    SetKeyHandler(mmi_imps_entry_pa_auth_reject, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_pa_auth_string
 * DESCRIPTION
 *  mmi_imps_pa_auth_string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_pa_auth_string(S8 *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->pa_auth->auth_user.entity_type == IMPS_ENTITY_TYPE_USER_SCREEN_NAME)
    {
        mmi_ucs2cpy((S8*) buff, (S8*) imps_p->pa_auth->auth_user.sname);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) buff, (S8*) imps_p->pa_auth->auth_user.id);
    }

    mmi_ucs2cat((S8*) buff, (S8*) L"\n\n");
    mmi_ucs2cat((S8*) buff, (S8*) GetString(STR_ID_IMPS_PA_AUTH_NOTE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_pa_auth_accept
 * DESCRIPTION
 *  Accept presence authentication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_pa_auth_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        mmi_imps_presence_auth_user_req(TRUE);
    }
    else
    {
        imps_entity_list_struct *id_list = (imps_entity_list_struct*) OslMalloc(sizeof(imps_entity_list_struct));
        memset(id_list, 0, sizeof(imps_entity_list_struct));
        id_list->entity_count = 1;
        memcpy((void*) &id_list->entity[0], (void*) &imps_p->pa_auth->auth_user, sizeof(imps_entity_struct));
        
        mmi_imps_ps_create_attributelist_req((void*) id_list, imps_p->pa_auth->attr_list);
        
        OslMfree(id_list);
    }
    GoBackHistory();
    mmi_imps_check_pa_auth();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_entry_pa_auth_reject
 * DESCRIPTION
 *  Reject presence authentication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_entry_pa_auth_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        mmi_imps_presence_auth_user_req(FALSE);    
    }
    GoBackHistory();    

    mmi_imps_check_pa_auth();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_pa_auth
 * DESCRIPTION
 *  Check if there is any unprocess presence authentication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_check_pa_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 *ucs2_folder = NULL;
    FS_HANDLE fileHandle;
    U32 len;
    mmi_imps_presence_auth_ind_struct pa_auth_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->pa_auth != NULL)
    {
        if (imps_p->pa_auth->curr_index == imps_p->pa_auth->total)
        {
            ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

            mmi_imps_util_file_path((S8*) ucs2_folder, (S8*) IMPS_PA_AUTH, 0);

            FS_Delete((const WCHAR *) ucs2_folder);

            OslMfree(ucs2_folder);

            /* free pa_auth */
            OslMfree(imps_p->pa_auth);
            imps_p->pa_auth = NULL;

            DeleteScreenIfPresent(SCR_ID_IMPS_PRESENCE_AUTHENTICATION);
        }
        else
        {
            if (mmi_imps_util_is_in_imps() && !IsScreenPresent(SCR_ID_IMPS_PRESENCE_AUTHENTICATION))
            {
                ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

                mmi_imps_util_file_path((S8*) ucs2_folder, (S8*) IMPS_PA_AUTH, 0);

                fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
                OslMfree(ucs2_folder);  
                if (fileHandle > 0)
                {
                    FS_Seek(fileHandle, sizeof(mmi_imps_presence_auth_ind_struct) * imps_p->pa_auth->curr_index, FS_FILE_BEGIN);
                    FS_Read(fileHandle, (void*) &pa_auth_ind, sizeof(mmi_imps_presence_auth_ind_struct), &len);

                    memcpy(&imps_p->pa_auth->auth_user, &pa_auth_ind.auth_user, sizeof(imps_entity_struct));
                    imps_p->pa_auth->attr_list = pa_auth_ind.attr_list;
                    imps_p->pa_auth->curr_index++;

                    mmi_imps_entry_presence_authentication();
                }
                FS_Close(fileHandle);  
            }
            else
            {
                mmi_imps_util_disp_warning_popup(STR_ID_IMPS_NEW_PA_AUTH);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_create_attributelist_finished
 * DESCRIPTION
 *  Handler create attribute list finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_create_attributelist_finished(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == IMPS_OK)
    {
        mmi_imps_util_disp_popup_done();
    }
    else
    {
        mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_NETWORK_BUSY);
    }    
}

#endif