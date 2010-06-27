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
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#ifdef __J2ME__

#include "CommonScreens.h"
#include "ProtocolEvents.h"

#include "ProfileGprots.h"      /* need MYQUEUE */
#include "MainMenuDef.h"        /* need MAIN_MENU_TITLE_FUNANDGAMES_ICON */

#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "jal.h"
#include "jvm_adaptor.h"
#include "jam_interface.h"
#include "jam_msg_handler.h"


extern java_context_struct g_java;


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_em_normal
 * DESCRIPTION
 *  Highlight handler routine for Normal Mode menu item in JAVA TCK menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_em_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    //SCR1251-Cannon+
    //      SetLeftSoftkeyFunction(mmi_java_send_set_mode_req,KEY_EVENT_UP);
    //      SetKeyHandler(mmi_java_send_set_mode_req,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_java_execute_set_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_execute_set_mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_java.tck_index = 0;   /* JAVA_NORMAL_MODE; */
    g_java.tck_execute = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_em_cldc_tck
 * DESCRIPTION
 *  Highlight handler routine for CLDC Mode menu item in JAVA TCK menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_em_cldc_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_java_execute_em_tck, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_execute_em_tck, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_java.tck_index = 1;   /* JAVA_CLDC_TCK_MODE; */
    g_java.tck_execute = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_em_midp_tck
 * DESCRIPTION
 *  Highlight handler routine for MIDP Mode menu item in JAVA TCK menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_em_midp_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_java_execute_em_tck, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_execute_em_tck, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_java.tck_index = 2;   /* JAVA_MIDP_TCK_MODE; */
    g_java.tck_execute = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_em_wma_tck
 * DESCRIPTION
 *  Highlight handler routine for WMAPI Mode menu item in JAVA TCK menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_em_wma_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_java_execute_em_tck, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_execute_em_tck, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_java.tck_index = 3;   /* JAVA_WMA_TCK_MODE; */
    g_java.tck_execute = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_em_mmapi_tck
 * DESCRIPTION
 *  Highlight handler routine for MMAPI Mode menu item in JAVA TCK menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_em_mmapi_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_java_execute_em_tck, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_execute_em_tck, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_java.tck_index = 4;   /* JAVA_MMAPI_TCK_MODE; */
    g_java.tck_execute = KAL_TRUE;
}

/* SCR1251-Cannon+ */


/*****************************************************************************
 * FUNCTION
 *  mmi_java_execute_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_execute_set_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();    /* this gobackhistory is called by key event */
    mmi_java_send_set_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_set_mode_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_SET_MODE_REQ to MOD_J2ME
 *  to send TCK mode and set protocol event handler of  MSG_ID_MMI_JAVA_SET_MODE_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_set_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_java_set_mode_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_SET_MODE_REQ);
    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_set_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_java_set_mode_req_struct));

    msg->java_mode = g_java.tck_index;
    msg->execute = g_java.tck_execute;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_SET_MODE_REQ;
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_set_mode_cnf, MSG_ID_MMI_JAVA_SET_MODE_CNF);
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_set_mode_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_SET_MODE_CNF from MOD_J2ME to
 *  go back to EM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_set_mode_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_SET_MODE_CNF);

    DisplayPopup((PU8) GetString(STR_JAVA_DOWNLOADED), IMG_GLOBAL_OK, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_terminate_tck_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_terminate_tck_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.tck_execute = KAL_FALSE;
    /* SCR1251-Cannon+ */
    mmi_java_execute_set_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_execute_em_tck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_execute_em_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_entry_java_em_tck();
    /* SCR1251-Cannon+ */
    mmi_java_execute_set_mode();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrJavaEM
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrJavaEM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nDispAttribute;                 /* Stores display attribue */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 i = 0, data;
    U16 gimagearray2[MAX_SUB_MENUS];    /* array for profilenames */

    U16 JavaEMMenuID[] = 
    {
        MENU_JAVA_EM_NORMAL,
        MENU_JAVA_EM_CLDC_TCK,
        MENU_JAVA_EM_MIDP_TCK,
        MENU_JAVA_EM_WMAPI_TCK,
        MENU_JAVA_EM_MMAPI_TCK
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef J2ME_SUPPORT_PAUSE
    if (jvm_is_pause_mode())
    {
        mmi_java_display_is_busy_for_pause_mode();
        return; /* drop the timealarm request */
    }
#endif /* J2ME_SUPPORT_PAUSE */ 

    EntryNewScreen(SCR_JAVA_EM, ExitScrJavaEM, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_EM);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_JAVA_EM);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_JAVA_EM);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_JAVA_EM, nStrItemList);
    GetSequenceImageIds(MENU_JAVA_EM, ItemIcons);

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_JAVA_EM);

    for (i = 0; i < nNumofItem; i++)
    {
        gimagearray2[i] = IMG_PROFILES_NO_IMAGE;
    }

    for (i = 0; i < nNumofItem; i++)
    {
        memset((S8*) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[i], GetString(nStrItemList[i]), MAX_SUBMENU_CHARACTERS);
    }
    data = GetIndexOfStringId(MENU_JAVA_EM, JavaEMMenuID[g_java.tck_index]);
    gimagearray2[data] = IMG_PROFILES_ACTIVATED;

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8. Display Category73 Screen */
    ShowCategory73Screen(
        STR_JAVA_EM,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        subMenuDataPtrs,
        (U16*) gimagearray2,
        ItemIcons,
        (U16) data,
        guiBuffer,
        1);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    mmi_java_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrJavaEM
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrJavaEM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_JAVA_EM;
    h.entryFuncPtr = EntryScrJavaEM;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_java_em_tck
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode->Tck Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_java_em_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem; /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_JAVA_EM_TCK, mmi_java_exit_java_em_tck, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_JAVA_EM_TCK);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_JAVA_EM_TCK);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* GetSequenceStringIds(MENU_JAVA_EM_TCK,nStrItemList); */

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_JAVA_EM_TCK);

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8. Display Category74 Screen */
    ShowCategory74Screen(
        STR_JAVA_EM,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        0,
        NULL);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(mmi_java_terminate_tck_mode, KEY_EVENT_UP);
    SetKeyHandler(mmi_java_terminate_tck_mode, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_java_terminate_tck_mode, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_exit_java_em_tck
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode->Tck Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_exit_java_em_tck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_JAVA_EM_TCK;
    h.entryFuncPtr = mmi_java_entry_java_em_tck;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_exit_java_em_tck
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->EngineerMode->Tck Exit Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_java_tck_is_execute(void)
{
    return g_java.tck_execute;
}
#endif /* __J2ME__ */ 

