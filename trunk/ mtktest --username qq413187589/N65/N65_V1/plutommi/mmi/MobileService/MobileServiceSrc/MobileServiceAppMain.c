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
 * MobileServiceApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements menu screen of mobile service applications.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_MOBILE_SERVICE__

#include "wapadp.h"
#include "Ucs2prot.h"
#include "MobileServiceResDef.h"
#include "MobileServiceGProt.h"
#include "MobileServiceProt.h"
#include "SATGProts.h"
#include "PhonebookGprot.h"
#include "PhonebookProt.h"
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGprot.h"
#include "SyncMLCustomizedSettings.h"
#endif /* __SYNCML_SUPPORT__ */ 

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef WAP_SUPPORT

static const mmi_optrser_url_struct mmi_optrser_url[] = 
{
    {
     MENU_ID_OPTRSER_MUSIC,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22wxyy"},
    {
     MENU_ID_OPTRSER_GAME,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22yxsq"},
    {
     MENU_ID_OPTRSER_WEATHER,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22xwtq"},
    {
     MENU_ID_OPTRSER_FETION,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22fx"},
    {
     MENU_ID_OPTRSER_VIDEO,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22sjsp"},
    {
     MENU_ID_OPTRSER_NEW,
     (const U8 *)L"http://wap.monternet.com/?cp22=v22ywtj"},
    {
     MENU_ID_OPTRSER_MYMONWAP,
     (const U8 *)L"http://wap.monternet.com/portal/wap/menu.do?menuid=200003"},
    {
     MENU_ID_OPTRSER_MONWAP,
     (const U8 *)L"http://wap.monternet.com"}
 #ifdef __SYNCML_SUPPORT__
    ,
    {
     MENU_ID_OPTRSER_PIM,
     (const U8 *)L"http://pim1.monternet.com/zf.html"},
    {
     MENU_ID_OPTRSER_PIM_ORDER,
     (const U8 *)L"http://pim1.monternet.com/kt.html"},
    {
     MENU_ID_OPTRSER_PIM_CHECK,
     (const U8 *)L"http://pim1.monternet.com/cx.html"}
 #endif /* __SYNCML_SUPPORT__ */ 
    ,
    {
     0,
     NULL}

};
#endif /* WAP_SUPPORT */ 

static void mmi_optrser_menu_index(S32 index);

#ifdef __SYNCML_SUPPORT__
static void mmi_optrser_highlight_pim(void);
static void mmi_optrser_entry_pim_intro(void);
static void mmi_optrser_pim_intro_callback(S32 selected_idx);
static void mmi_optrser_pim_intro_forward_app(void);
static void mmi_optr_entry_pim_list(void);
static void mmi_optrser_pim_menu_index(S32 index);
static void mmi_optrser_highlight_pim_sync(void);
static void mmi_optrser_highlight_pim_setting(void);
static void mmi_optrser_highlight_pim_pb(void);
#endif /* __SYNCML_SUPPORT__ */ 

#ifdef WAP_SUPPORT
static void mmi_optrser_highlight_url(void);
static const U8 *mmi_optrser_get_url(U32 hiliteItemID);
static void mmi_optrser_enter_url(void);
#endif /* WAP_SUPPORT */ 

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_optrser_context_struct g_optrser_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_init
 * DESCRIPTION
 *  Initialize each menu item hilite handler in mobile service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_optrser_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SYNCML_SUPPORT__
    SetHiliteHandler(MENU_ID_OPTRSER_PIM, mmi_optrser_highlight_pim);
    SetHiliteHandler(MENU_ID_OPTRSER_PIM_SYNC, mmi_optrser_highlight_pim_sync);
    SetHiliteHandler(MENU_ID_OPTRSER_PIM_SETTING, mmi_optrser_highlight_pim_setting);
    SetHiliteHandler(MENU_ID_OPTRSER_PIM_PB, mmi_optrser_highlight_pim_pb);
#ifdef WAP_SUPPORT
    SetHiliteHandler(MENU_ID_OPTRSER_PIM_ORDER, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_PIM_CHECK, mmi_optrser_highlight_url);
#endif /* WAP_SUPPORT */ 
#endif /* __SYNCML_SUPPORT__ */ 
#ifdef WAP_SUPPORT
    SetHiliteHandler(MENU_ID_OPTRSER_MUSIC, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_GAME, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_WEATHER, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_FETION, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_VIDEO, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_NEW, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_MYMONWAP, mmi_optrser_highlight_url);
    SetHiliteHandler(MENU_ID_OPTRSER_MONWAP, mmi_optrser_highlight_url);

#endif /* WAP_SUPPORT */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_entry_main_menu
 * DESCRIPTION
 *  mobile service entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_optrser_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_OPTRSER_LIST, NULL, mmi_optrser_entry_main_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_OPTRSER_LIST);
    nItems = GetNumOfChild(MAIN_MENU_OP_SERVICES_MENUID);
    GetSequenceStringIds(MAIN_MENU_OP_SERVICES_MENUID, ItemList);
    GetSequenceImageIds(MAIN_MENU_OP_SERVICES_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_OP_SERVICES_MENUID);
    RegisterHighlightHandler(mmi_optrser_menu_index);

    if (IsSATPresent())
    {
        ItemList[nItems] = STR_ID_OPTRSER_STK;
        ItemIcons[nItems] = IMG_ID_OPTRSER_STK;
        nItems++;
    }

    ShowCategory52Screen(
        STR_ID_OPTRSER_TITLE,
        GetRootTitleIcon(MAIN_MENU_OP_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_menu_index
 * DESCRIPTION
 *  get the mainmenu item index,if STK exists, add one STK item to the menu list.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_menu_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_optrser_context.item_idx = (U8) index;

    nItems = GetNumOfChild(MAIN_MENU_OP_SERVICES_MENUID);

    if (IsSATPresent() && (index == nItems))
    {
        SetLeftSoftkeyFunction(GoToSATMainMenu, KEY_EVENT_UP);
        SetKeyHandler(GoToSATMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ExecuteCurrHiliteHandler(index);
    }

}

#ifdef WAP_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_highlight_url
 * DESCRIPTION
 *  highlight handler for all menu item which will launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_highlight_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_optrser_enter_url, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_optrser_enter_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_enter_url
 * DESCRIPTION
 *  get the url index from the menu id and launch wap browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_enter_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nParentMenuId;
    U16 hiliteItemID;
    const U8 *p_url = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nParentMenuId = GetParentHandler();
    hiliteItemID = GetSeqItemId_Ext((U16) nParentMenuId, (U16) g_optrser_context.item_idx);
    p_url = mmi_optrser_get_url(hiliteItemID);
    wap_start_browser(WAP_BROWSER_GOTO_URL, p_url);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_get_url
 * DESCRIPTION
 *  get the url index from the menu id
 * PARAMETERS
 *  hiliteItemID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static const U8 *mmi_optrser_get_url(U32 hiliteItemID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (mmi_optrser_url[i].p_url != NULL)
    {
        if (mmi_optrser_url[i].url_index == hiliteItemID)
        {
            return mmi_optrser_url[i].p_url;
        }
        i++;
    }

    /* shall not enter here */

    MMI_ASSERT(0);
    return NULL;

}
#endif /* WAP_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_highlight_pim
 * DESCRIPTION
 *  phonebook manager menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __SYNCML_SUPPORT__
static void mmi_optrser_highlight_pim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_optrser_entry_pim_intro, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_optrser_entry_pim_intro, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_highlight_pim_sync
 * DESCRIPTION
 *  phonebook manager menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_highlight_pim_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_pre_check, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_sync_pre_check, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_highlight_pim_pb
 * DESCRIPTION
 *  phonebook manager menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_highlight_pim_pb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_phb_list_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#if defined(__MMI_PHB_QUICK_SEARCH__)
    SetLeftSoftkeyFunction(mmi_phb_quick_search_list_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_quick_search_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(__MMI_PHB_QUICK_SEARCH__) */ 
    SetLeftSoftkeyFunction(mmi_phb_list_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_highlight_pim_setting
 * DESCRIPTION
 *  phonebook manager menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_highlight_pim_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_syncml_pre_entry_customized_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_pre_entry_customized_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_entry_pim_intro
 * DESCRIPTION
 *  entry the phonebook manager introduction screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_entry_pim_intro(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 str_buf;
    S32 text_size;
    U8 *guiBuffer;
    S8 *text_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_OPTRSER_PIM_INTRO, NULL, mmi_optrser_entry_pim_intro, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_OPTRSER_PIM_INTRO);
    if (guiBuffer == NULL)
    {
        g_optrser_context.pim_intro_data.selected_hilight_idx = 0;
    }

    text_buf = GetString(STR_ID_OPTRSER_PIM_INTRO);
    text_size = mmi_ucs2strlen(text_buf);
#ifdef WAP_SUPPORT
    str_buf = GetString(STR_ID_OPTRSER_PIM_FEE);
    g_optrser_context.pim_intro_data.hilite_item[0].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf);
    g_optrser_context.pim_intro_data.hilite_item[0].length = mmi_ucs2strlen(str_buf);
    str_buf = GetString(STR_ID_OPTRSER_PIM_ENTER);
    g_optrser_context.pim_intro_data.hilite_item[1].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf);
    g_optrser_context.pim_intro_data.hilite_item[1].length = mmi_ucs2strlen(str_buf);

#else /* WAP_SUPPORT */ 
    str_buf = GetString(STR_ID_OPTRSER_PIM_ENTER);
    g_optrser_context.pim_intro_data.hilite_item[0].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf);
    g_optrser_context.pim_intro_data.hilite_item[0].length = mmi_ucs2strlen(str_buf);
#endif /* WAP_SUPPORT */ 

    ShowCategory228Screen(
        STR_ID_OPTRSER_PIM,
        GetRootTitleIcon(MAIN_MENU_OP_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) text_buf,
        text_size,
        g_optrser_context.pim_intro_data.hilite_item,
        MMI_OPTRSER_PIM_INTOR_TOTAL,
        mmi_optrser_pim_intro_callback,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_optrser_pim_intro_forward_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_pim_intro_callback
 * DESCRIPTION
 *  store the highlighted string item index
 * PARAMETERS
 *  selected_idx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_pim_intro_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_optrser_context.pim_intro_data.selected_hilight_idx = selected_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_pim_intro_forward_app
 * DESCRIPTION
 *  callback function when select the highlighted string item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_pim_intro_forward_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_optrser_context.pim_intro_data.selected_hilight_idx)
    {
    #ifdef WAP_SUPPORT
        case MMI_OPTRSER_PIM_INTRO_EXPENSE:
        {
            const U8 *p_url;

            p_url = mmi_optrser_get_url(MENU_ID_OPTRSER_PIM);
            wap_start_browser(WAP_BROWSER_GOTO_URL, p_url);

        }
            break;
    #endif /* WAP_SUPPORT */ 
        case MMI_OPTRSER_PIM_INTRO_ENTER:
            mmi_optr_entry_pim_list();
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optr_entry_pim_list
 * DESCRIPTION
 *  pim menu list entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optr_entry_pim_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_OPTRSER_PIM_LIST, NULL, mmi_optr_entry_pim_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_OPTRSER_PIM_LIST);
    nItems = GetNumOfChild(MENU_ID_OPTRSER_PIM_ENTER);
    GetSequenceStringIds(MENU_ID_OPTRSER_PIM_ENTER, ItemList);
    GetSequenceImageIds(MENU_ID_OPTRSER_PIM_ENTER, ItemIcons);
    SetParentHandler(MENU_ID_OPTRSER_PIM_ENTER);
    RegisterHighlightHandler(mmi_optrser_pim_menu_index);

    ShowCategory52Screen(
        STR_ID_OPTRSER_PIM,
        GetRootTitleIcon(MAIN_MENU_OP_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_optrser_pim_menu_index
 * DESCRIPTION
 *  get the phonebook manager menu item index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_optrser_pim_menu_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_optrser_context.item_idx = (U8) index;
    ExecuteCurrHiliteHandler(index);

}

#endif /* __SYNCML_SUPPORT__ */ /* __SYNCML_SUPPORT */

#endif /* __MMI_MOBILE_SERVICE__ */ 

