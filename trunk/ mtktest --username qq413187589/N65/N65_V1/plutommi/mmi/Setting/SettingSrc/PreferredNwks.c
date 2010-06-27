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
 * PreferredNwks.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#include "MMI_include.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "SettingDefs.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"
#include "SettingProfile.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "SettingProfile.h"
#include "PreferredNwksStruct.h"
#include "PrefNwksGprot.h"
#include "CustResDef.h"
/* micha0901 */
#include "CommonScreens.h"
#include "CallManagementIdDef.h" /* CM_SCR_MARKER */
#include "CallManagementGprot.h" /* isInCall() */
/* MTK Leo add 20040608 */

extern pBOOL mmi_netset_get_preferred_networks_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern S32 mmi_netset_get_preferred_networks_hint(S32 item_index, UI_string_type *hint_array);

extern void mmi_netset_entry_sort_progress(void);

extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);

extern U8 *InLinePriorityUnchanged(void);

/* 2006/02/16 USIM preferred network implementation */
extern S8 *gServiceString[3];   /* inline selection between 'GSM/GPRS', 'WCDMA', or 'Dual Mode' */

PrefNetworkListContext gPrefList;
PrefNetworkListDisplay gPrefListDisplay;

static U8 gPrefListDelFlag;


/*****************************************************************************
 * FUNCTION
 *  InitPrefNwk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPrefNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MITEM_PRR_NWK_DELETE, HighlightNETSETDelPrefNwk);
    SetHiliteHandler(MITEM_PRR_NWK_EDIT, HighlightNETSETEditPrefNwk);
    SetHiliteHandler(MITEM_PRR_NWK_ADD, HighlightNETSETAddPrefNwk);
    SetHiliteHandler(MITEM_PRR_NWK_NEW, HighlightNETSETNewPrefNwk);

    /* diamond, 2006/03/08 New PLMN management */
    SetHiliteHandler(MENU_ID_ADD_FROM_LIST_DONE, mmi_netset_highlight_add_from_list_done);
    SetHiliteHandler(MENU_ID_ADD_FROM_LIST_SORT_BY_DEFAULT, mmi_netset_highlight_sort_by_default);
    SetHiliteHandler(MENU_ID_ADD_FROM_LIST_SORT_BY_ALPHABET, mmi_netset_highlight_sort_by_alphabet);

#if 1
    mmi_frm_hide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_DEFAULT);
    mmi_frm_hide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_ALPHABET);
#endif

    gPrefList.PrefListSize = 0;
    gPrefList.comp_flag = 0;
    gPrefListDisplay.CurrSelAddPLMN = 0;
    gPrefListDisplay.CurrSelPrefNetwork = 0;
    gPrefListDisplay.IsNewPrefNetwork = 0;
    gPrefListDisplay.PrefNwGotResponse = 0;
    gPrefListDisplay.PriorityVal = 0;
    gPrefListDisplay.SortingMethod = 0; /* diamond, 2006/03/08 New PLMN management */

    /* 2006/02/16 USIM preferred network implementation */
    gServiceString[0] = GetString(STR_ID_NETSET_ITEM_GSM);
    gServiceString[1] = GetString(STR_ID_NETSET_ITEM_WCDMA);
    gServiceString[2] = GetString(STR_ID_NETSET_ITEM_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETDelPrefNwk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETDelPrefNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryNETSETConfirmDeleteNetwork, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETEditPrefNwk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETEditPrefNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryNETSETEditNetwork, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* micha0529 */
    SetKeyHandler(EntryNETSETEditNetwork, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETEditNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETEditNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_EDIT_NETWORK, NULL, EntryNETSETEditNetwork, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_EDIT_NETWORK);
    gPrefListDisplay.PriorityVal = gPrefListDisplay.CurrSelPrefNetwork + 1;
    ShowCategory87Screen(
        STR_ID_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        1,
        (S32) (gPrefList.PrefListSize),
        &gPrefListDisplay.PriorityVal,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETEditNetworkDeletePhaseReq, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETEditNetworkDeletePhaseReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETEditNetworkDeletePhaseReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.PriorityVal == gPrefListDisplay.CurrSelPrefNetwork + 1)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);

        DeleteScreenIfPresent(SCR_ID_NETSET_EDIT_NETWORK);
        DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

        if (IsScreenPresent(SCR_ID_NETSET_MAIN))
        {
            GenericExitScreen(SCR_ID_NETSET_SHOW_PREFERRED_LIST, EntryNETSETShowPreferredList);
        }
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = SMU_REMOVE_PLMNSEL;
    myMsgPtr->index = (U8) gPrefListDisplay.CurrSelPrefNetwork;
    memcpy(myMsgPtr->oper, gPrefList.PrefPLMN[gPrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));
    myMsgPtr->rat = gPrefList.rat[gPrefListDisplay.CurrSelPrefNetwork];
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(NETSETEditNetworkDeletePhaseRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETEditNetworkDeletePhaseRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETEditNetworkDeletePhaseRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_smu_set_preferred_oper_list_rsp_struct*) info;
    if (myMsgPtr->result == MMI_FALSE || gPrefList.PrefListSize <= gPrefListDisplay.CurrSelPrefNetwork)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        /* DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST); */

        /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
        DeleteScreenIfPresent(SCR_ID_NETSET_EDIT_NETWORK);
        DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

        gPrefList.comp_flag = 0;
        ExitNETSETShowPreferredListReGet();
    }
    else
    {
        NETSETEditNetworkAddPhaseReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETEditNetworkAddPhaseReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETEditNetworkAddPhaseReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = SMU_ADD_PLMNSEL;
    myMsgPtr->index = gPrefListDisplay.PriorityVal - 1;
    memcpy(myMsgPtr->oper, gPrefList.PrefPLMN[gPrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));
    myMsgPtr->rat = (gPrefList.SimFileIdx == FILE_PLMNSEL_IDX) ? 0 : (U8) gPrefListDisplay.CurrSelectService + 1;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(NETSETEditNetworkAddPhaseRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETEditNetworkAddPhaseRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETEditNetworkAddPhaseRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_smu_set_preferred_oper_list_rsp_struct*) info;
    if (myMsgPtr->result == MMI_FALSE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        /* DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST); */
    }

    /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
    DeleteScreenIfPresent(SCR_ID_NETSET_EDIT_NETWORK);
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

    if (myMsgPtr->result == MMI_FALSE)
    {
        gPrefList.comp_flag = 0;
        ExitNETSETShowPreferredListReGet();
    }
    else
    {
        gPrefList.comp_flag = 1;
        NETSETGetPreferredNetworkReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETBeforeAddNetworkPLMNList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETBeforeAddNetworkPLMNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.SortingMethod == 1)
    {
        mmi_netset_entry_sort_progress();
    }

    for (index = 0;; index++)
    {
        if (bcdPlmnsToDisplayName[index].plmn_bcd == 0)
        {
            break;
        }
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    {
        mmi_netset_sort_plmn_list_by_default(index);
#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }

    EntryNETSETAddNetworkPLMNList();
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAddNetworkPLMNListDeleteCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 NETSETAddNetworkPLMNListDeleteCallback(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.SortingArray)
    {
        OslMfree(gPrefListDisplay.SortingArray);
        gPrefListDisplay.SortingArray = NULL;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETAddPrefNwk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETAddPrefNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryNETSETBeforeAddNetworkPLMNList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryNETSETBeforeAddNetworkPLMNList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPrefNetworkListItem
 * DESCRIPTION
 *  Return Item for dynamic category screen
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL NETSETGetPrefNetworkListItem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }

    mmi_ucs2cpy((S8*) str_buff, GetString((U16)(bcdPlmnsToDisplayName[gPrefListDisplay.SortingArray[item_index]].string_index + STR_PLMN_NAME_1))); /* sorting method */
    *img_buff_p = NULL;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPrefNetworkListHint
 * DESCRIPTION
 *  Return Hint for dynamic category screen
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 NETSETGetPrefNetworkListHint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 plmn_hint[MAX_PLMN_LEN_MMI + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_bcd_short_2_plmn_str(
        bcdPlmnsToDisplayName[gPrefListDisplay.SortingArray[item_index]].plmn_bcd,
        plmn_hint);
    mmi_asc_to_ucs2((S8*) * hint_array, (S8*) plmn_hint);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETAddNetworkPLMNList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  info(?)     [IN]        Struct from PS
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETAddNetworkPLMNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_ADD_NEW_NETWORK_PLMN_LIST, NULL, EntryNETSETAddNetworkPLMNList, NULL);

    for (index = 0;; index++)
    {
        if (bcdPlmnsToDisplayName[index].plmn_bcd == 0)
        {
            break;
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_ADD_NEW_NETWORK_PLMN_LIST);
    RegisterHighlightHandler(HiliteHandlerAddNetworkPLMNList);

#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

    ShowCategory284Screen(
        STR_ID_NETSET_PRF_ADD_SHW_NWK_TITLE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        NETSETGetPrefNetworkListItem,
        NETSETGetPrefNetworkListHint,
        0,
        guiBuffer);

    SetDelScrnIDCallbackHandler(SCR_ID_NETSET_ADD_NEW_NETWORK_PLMN_LIST, NETSETAddNetworkPLMNListDeleteCallback);

    /* diamond, 2006/03/08 New PLMN management */
    SetLeftSoftkeyFunction(mmi_netset_entry_add_from_list_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_entry_add_from_list_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETAddNetworkPriority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETAddNetworkPriority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY, NULL, EntryNETSETAddNetworkPriority, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY);
    gPrefListDisplay.PriorityVal = (S32) (gPrefList.PrefListSize + 1);
    ShowCategory87Screen(
        STR_ID_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        1,
        (S32) (gPrefList.PrefListSize + 1),
        &gPrefListDisplay.PriorityVal,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ChcekThenAddNetwork, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ChcekThenAddNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChcekThenAddNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 2006/02/16 USIM preferred network implementation */
    if (gPrefList.SimFileIdx != FILE_PLMNSEL_IDX)
    {
        CloseCategory57Screen();
    }

    if (IsNetworkDuplicated() == 1 || (gPrefListDisplay.PriorityVal > MAX_PREFFERED_PLMN) ||
        (gPrefListDisplay.PriorityVal > g_pwr_context.NoOfPLMNSupported))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_NETSET_PRF_NWK_ADDED_ERR),
            IMG_GLOBAL_UNFINISHED,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST);
    }
    else
    {
        NETSETAddPrefNetworkReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerPrefList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hiliteIdx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHandlerPrefList(S32 hiliteIdx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPrefListDisplay.CurrSelPrefNetwork = (U8) hiliteIdx;
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerAddNetworkPLMNList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hiliteIdx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHandlerAddNetworkPLMNList(S32 hiliteIdx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPrefListDisplay.CurrSelAddPLMN = (U16) hiliteIdx;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAddPrefNetworkReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAddPrefNetworkReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = SMU_ADD_PLMNSEL;
    memset(myMsgPtr->oper, 0, MAX_PLMN_LEN + 1);
    myMsgPtr->index = gPrefListDisplay.PriorityVal - 1;
    if (gPrefListDisplay.IsNewPrefNetwork)
    {
        /* create new */
        mmi_ucs2_to_asc((PS8) myMsgPtr->oper, (PS8) gPrefListDisplay.PlmnNew);
        gPrefListDisplay.IsNewPrefNetwork = 0;
    }
    else
    {
        /* add from list */
        U8 plmn[MAX_PLMN_LEN_MMI + 1];

        mmi_netset_bcd_short_2_plmn_str(
            bcdPlmnsToDisplayName [gPrefListDisplay.SortingArray[gPrefListDisplay.CurrSelAddPLMN]].plmn_bcd,
            plmn);
        memcpy(myMsgPtr->oper, plmn, (MAX_PLMN_LEN + 1));
    }
    myMsgPtr->rat = (gPrefList.SimFileIdx == FILE_PLMNSEL_IDX) ? 0 : (U8) gPrefListDisplay.CurrSelectService + 1;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(NETSETAddPrefNetworkRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETAddPrefNetworkRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETAddPrefNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_smu_set_preferred_oper_list_rsp_struct*) info;
    if (myMsgPtr->result == MMI_FALSE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        /* DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST); */
    }

    /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
    DeleteScreenIfPresent(SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY);
    DeleteScreenIfPresent(SCR_ID_ADD_FROM_LIST_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_ADD_NEW_NETWORK_PLMN_LIST);

    DeleteScreenIfPresent(SCR_ID_NETSET_NEW_NETWORK);
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

    if (myMsgPtr->result == MMI_FALSE)
    {
        gPrefList.comp_flag = 0;
        ExitNETSETShowPreferredListReGet();
    }
    else
    {
        gPrefList.comp_flag = 1;
        NETSETGetPreferredNetworkReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETConfirmDeleteNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETConfirmDeleteNetwork(void)
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
        get_string(STR_ID_SETTING_DELETE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NETSETDeletePrefNetworkReq, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitNETSETConfirmDeleteNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNETSETConfirmDeleteNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    /* micha0531 */
    GenericExitScreen(SCR_ID_NETSET_CONFIRM_DELETE_NETWORK, EntryNETSETConfirmDeleteNetwork);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETDeletePrefNetworkReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETDeletePrefNetworkReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set flag of list delete */
    gPrefListDelFlag = 1;

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = SMU_REMOVE_PLMNSEL;
    myMsgPtr->index = (U8) gPrefListDisplay.CurrSelPrefNetwork;
    memcpy(myMsgPtr->oper, gPrefList.PrefPLMN[gPrefListDisplay.CurrSelPrefNetwork], (MAX_PLMN_LEN + 1));
    myMsgPtr->rat = gPrefList.rat[gPrefListDisplay.CurrSelPrefNetwork];
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(NETSETDeletePrefNetworkRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  NETSETDeletePrefNetworkRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETDeletePrefNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_smu_set_preferred_oper_list_rsp_struct*) info;
    if (myMsgPtr->result == MMI_FALSE)
    {
        gPrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        /* DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST); */
    }

    /* diamond, 2006/05/25 Not use DeleteUptoScrID after set preferred network */
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

    if (myMsgPtr->result == MMI_FALSE)
    {
        gPrefList.comp_flag = 0;
        gPrefListDelFlag = 0;
        ExitNETSETShowPreferredListReGet();
    }
    else
    {
        gPrefList.comp_flag = 1;
        NETSETGetPreferredNetworkReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPreferredNetworkReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetPreferredNetworkReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    if (g_pwr_context.NoOfPLMNSupported == 0)
    {
        gPrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_NETSET_MAIN);
        return;
    }

    myMsgPtr =
        (mmi_smu_get_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_get_preferred_oper_list_req_struct));
    myMsgPtr->num = g_pwr_context.NoOfPLMNSupported;
    myMsgPtr->index = 0;
    myMsgPtr->file_idx_req = FILE_NONE; /* 2006/02/16 USIM preferred network implementation */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(NETSETGetPreferredNetworkRsp, PRT_PREFERRED_NETWORKS_REQ_SUCCESS);
    OslMsgSendExtQueue(&Message);
}

/* diamond, 2005/12/07 Support the records not in order */
typedef struct
{
    U8 op;
    U8 index;
    U8 plmn[MAX_PLMN_LEN + 1];
    U8 rat;
} NETQUEUE;

static NETQUEUE *net_queue;
static U8 queue_cnt = 0;
static U8 send_cnt = 0;

void NETSETModifyNetworkRsp(void *info);


/*****************************************************************************
 * FUNCTION
 *  NETSETModifyNetworkByIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETModifyNetworkByIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_set_preferred_oper_list_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (mmi_smu_set_preferred_oper_list_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_set_preferred_oper_list_req_struct));
    myMsgPtr->opcode = net_queue[send_cnt].op;
    myMsgPtr->index = net_queue[send_cnt].index;
    memcpy(myMsgPtr->oper, net_queue[send_cnt].plmn, (MAX_PLMN_LEN + 1));
    myMsgPtr->rat = net_queue[send_cnt].rat;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_SET_PREFERRED_NETWORKS_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(NETSETModifyNetworkRsp, PRT_SET_PREFERRED_NETWORKS_RSP);
    OslMsgSendExtQueue(&Message);
    send_cnt++;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETModifyNetworkRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETModifyNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (send_cnt == queue_cnt)
    {
        OslMfree(net_queue);
        send_cnt = 0;
        queue_cnt = 0;
    }
    else
    {
        NETSETModifyNetworkByIndex();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NETSETModifyNetworkToQueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op          [IN]        
 *  index       [IN]        
 *  plmn        [?]         
 *  rat         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETModifyNetworkToQueue(U8 op, U8 index, U8 *plmn, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    net_queue[queue_cnt].op = op;
    net_queue[queue_cnt].index = index;
    memcpy(net_queue[queue_cnt].plmn, plmn, MAX_PLMN_LEN + 1);
    net_queue[queue_cnt].rat = rat;
    queue_cnt++;
}


/*****************************************************************************
 * FUNCTION
 *  NETSETGetPreferredNetworkRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void NETSETGetPreferredNetworkRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    U8 index, done_flag;
    U8 *list_array;
    U16 pref_list_size, i;
    U8 *pref_list;
    mmi_smu_get_preferred_oper_list_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("@@@@@ In NETSETGetPreferredNetworkRsp @@@@@");
    myMsgPtr = (mmi_smu_get_preferred_oper_list_rsp_struct*) info;
    if (myMsgPtr->retnum == 0 ||
        myMsgPtr->result == MMI_FALSE ||
        (myMsgPtr->result == MMI_TRUE && myMsgPtr->file_idx_rsp == FILE_OPLMNWACT_IDX))
    {
        gPrefListDelFlag = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST);
    }
    else
    {
        /* 2006/02/16 USIM preferred network implementation */
        gPrefList.SimFileIdx = myMsgPtr->file_idx_rsp;

        list_array = OslMalloc(myMsgPtr->retnum);
        pref_list_size = gPrefList.PrefListSize;
        if (gPrefList.PrefListSize == 0 || gPrefList.comp_flag == 0)
        {
            pref_list = NULL;
        }
        else
        {
            pref_list = OslMalloc(gPrefList.PrefListSize * (MAX_PLMN_LEN + 1));
            memcpy(pref_list, gPrefList.PrefPLMN, gPrefList.PrefListSize * (MAX_PLMN_LEN + 1));
        }

        if (myMsgPtr->retnum > 100)
        {
            net_queue = NULL;
        }
        else
        {
            net_queue = OslMalloc(myMsgPtr->retnum * 2 * sizeof(NETQUEUE));
        }

        for (count = 0, gPrefList.PrefListSize = 0; count < myMsgPtr->retnum; count++)
        {
            if (gPrefList.PrefListSize >= MAX_PREFFERED_PLMN)
            {
                break;
            }

            if ((myMsgPtr->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X3F) &&
                (myMsgPtr->oper_list[count * (MAX_PLMN_LEN + 1)] != 0X00))
            {
                for (index = 0; index < (MAX_PLMN_LEN + 1); index++)
                {
                    /* gPrefList.PrefPLMN[count][index] = myMsgPtr->oper_list[index + count * (MAX_PLMN_LEN + 1)]; */
                    gPrefList.PrefPLMN[gPrefList.PrefListSize][index] =
                        myMsgPtr->oper_list[index + count * (MAX_PLMN_LEN + 1)];
                }
                gPrefList.PrefPLMN[gPrefList.PrefListSize][MAX_PLMN_LEN] = 0;

                if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x80 &&
                    (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x00)
                {
                    gPrefList.rat[gPrefList.PrefListSize] = L4C_RAT_UMTS;
                }
                else if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x00 &&
                         (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x80)
                {
                    gPrefList.rat[gPrefList.PrefListSize] = L4C_RAT_GSM;
                }
                else if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x80 &&
                         (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x80)
                {
                    gPrefList.rat[gPrefList.PrefListSize] = L4C_RAT_GSM_UMTS;
                }
                else
                {
                    gPrefList.rat[gPrefList.PrefListSize] = L4C_RAT_NONE;
                }

                if (gPrefList.SimFileIdx != FILE_PLMNSEL_IDX)
                {
                    if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x80 &&
                        (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x00)
                    {
                        gPrefListDisplay.PLMNListIcons[gPrefList.PrefListSize] = IMG_SI_3G;
                    }
                    else if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x00 &&
                             (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x80)
                    {
                        gPrefListDisplay.PLMNListIcons[gPrefList.PrefListSize] = IMG_SI_2G;
                    }
                    else if ((myMsgPtr->rat_list[count * 2] & 0x80) == 0x80 &&
                             (myMsgPtr->rat_list[count * 2 + 1] & 0x80) == 0x80)
                    {
                        gPrefListDisplay.PLMNListIcons[gPrefList.PrefListSize] = (U16) IMG_SI_GPRS_INDICATOR;
                    }
                    else
                    {
                        gPrefListDisplay.PLMNListIcons[gPrefList.PrefListSize] = (U16) IMG_GLOBAL_DEFAULT;
                    }
                }

                gPrefList.PrefListSize++;

                *(list_array + count) = MMI_TRUE;

                if (count == 0)
                {
                    continue;
                }

                if (*(list_array + count - 1) == MMI_FALSE && net_queue != NULL)
                {
                    /* There is a record not in order because its previous record is empty */
                    *(list_array + count) = MMI_FALSE;
                    /* delete it */
                    NETSETModifyNetworkToQueue(
                        SMU_REMOVE_PLMNSEL,
                        count,
                        gPrefList.PrefPLMN[gPrefList.PrefListSize - 1],
                        gPrefList.rat[gPrefList.PrefListSize - 1]);
                    /* add it */
                    for (index = 0; index < count; index++)
                    {
                        if (*(list_array + index) == MMI_FALSE)
                        {
                            break;
                        }
                    }
                    NETSETModifyNetworkToQueue(
                        SMU_ADD_PLMNSEL,
                        (U8) (gPrefList.PrefListSize - 1),
                        gPrefList.PrefPLMN[gPrefList.PrefListSize - 1],
                        gPrefList.rat[gPrefList.PrefListSize - 1]);
                    *(list_array + index) = MMI_TRUE;
                }
            }
            else
            {
                /* diamond, 2005/12/07 Support the records not in order */
                *(list_array + count) = MMI_FALSE;
                /* break; */
            }
        }

        if (net_queue != NULL)
        {
            if (queue_cnt > 0)
            {
                NETSETModifyNetworkByIndex();
            }
            else
            {
                OslMfree(net_queue);
            }
        }

        OslMfree(list_array);

        gPrefListDisplay.PrefNwGotResponse = MMI_TRUE;
        if (!IsScreenPresent(SCR_ID_NETSET_SHOW_PREFERRED_LIST) == ST_SUCCESS)
        {
            if (gPrefList.comp_flag == 0)
            {
                EntryNETSETShowPreferredList();
            }
            else
            {
                gPrefList.comp_flag = 0;

                if (pref_list_size != gPrefList.PrefListSize)
                {
                    /* done */
                    done_flag = 1;
                }
                else
                {
                    for (i = 0; i < pref_list_size; i++)
                    {
                        if (strncmp((PS8)gPrefList.PrefPLMN[i],
                            (PS8)(pref_list + i * (MAX_PLMN_LEN + 1)),
                            MAX_PLMN_LEN + 1) != 0)
                        {
                            break;
                        }
                    }

                    if (i == pref_list_size)
                    {
                        /* not change */
                        done_flag = 0;
                    }
                    else
                    {
                        /* done */
                        done_flag = 1;
                    }
                }

                if (done_flag == 1)
                {
                    if (gPrefListDelFlag)
                    {
                        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                    }
                    else
                    {
                        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
                    }
                }
                else
                {
                    DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
                }

                if ((isInCall() && !IsWapCallPresent()) || isOutgoingCall())
                {
                    {
                        PRINT_INFORMATION("isInCall return %d", isInCall());
                        PRINT_INFORMATION("IsWapCallPresent return %d", IsWapCallPresent());
                        PRINT_INFORMATION("isOutgoingCall return %d", isOutgoingCall());
                    }
                    mmi_frm_add_history_before_cm_marker(SCR_ID_NETSET_SHOW_PREFERRED_LIST, EntryNETSETShowPreferredList);
                }
                else
                {
                    if (IsScreenPresent(SCR_ID_NETSET_MAIN))
                    {
                        GenericExitScreen(SCR_ID_NETSET_SHOW_PREFERRED_LIST, EntryNETSETShowPreferredList);
                    }
                }
            }
        }

        if (pref_list != NULL)
        {
            OslMfree(pref_list);
        }
    }

    gPrefListDelFlag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  GoBackNetworkSetup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackNetworkSetup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    GoBackToHistory(SCR_ID_NETSET_SELECTION_MODE);
#else
    GoBackToHistory(SCR_ID_NETSET_MAIN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETShowPreferredList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETShowPreferredList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_SHOW_PREFERRED_LIST, NULL, EntryNETSETShowPreferredList, NULL);

    if (gPrefListDisplay.PrefNwGotResponse == MMI_TRUE)
    {
        guiBuffer = NULL;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_SHOW_PREFERRED_LIST);
    }

    gPrefListDisplay.PrefNwGotResponse = MMI_FALSE;
    GetPrefNwkNameFromPLMN();
    RegisterHighlightHandler(HiliteHandlerPrefList);
    if (!gPrefList.PrefListSize)
    {
        gPrefListDisplay.nStrItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        ShowCategory6Screen(
            STR_ID_NETSET_PRF_NWK_TITLE,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            gPrefListDisplay.nStrItemList,
            NULL,
            0,
            guiBuffer);
    }
    else
    {
        /* 2006/02/16 USIM preferred network implementation */
        if (gPrefList.SimFileIdx != FILE_PLMNSEL_IDX)
        {
            ShowCategory184Screen(
                STR_ID_NETSET_PRF_NWK_TITLE,
                MAIN_MENU_TITLE_SETTINGS_ICON,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gPrefList.PrefListSize,
                mmi_netset_get_preferred_networks_item,
                mmi_netset_get_preferred_networks_hint,
                0,
                guiBuffer);
        }
        else
        {
            ShowCategory284Screen(
                STR_ID_NETSET_PRF_NWK_TITLE,
                MAIN_MENU_TITLE_SETTINGS_ICON,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gPrefList.PrefListSize,
                mmi_netset_get_preferred_networks_item,
                mmi_netset_get_preferred_networks_hint,
                0,
                guiBuffer);
        }
    }
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryNETSETShowPrefNwkOptions, KEY_EVENT_UP);
    SetKeyHandler(EntryNETSETShowPrefNwkOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackNetworkSetup, KEY_EVENT_UP);
    SetKeyHandler(GoBackNetworkSetup, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  GetPrefNwkNameFromPLMN
 * DESCRIPTION
 *  This function fills up the array for preferred network name of numbers
 * PARAMETERS
 *  void
 *  Number(?)       [OUT]       Of elements in the array
 *  PU8(?)          [IN]        *Dispnames, // Array of names or numbers
 * RETURNS
 *  U16
 *****************************************************************************/
U16 GetPrefNwkNameFromPLMN()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefList.PrefListSize > MAX_PREFFERED_PLMN)
    {
        gPrefList.PrefListSize = MAX_PREFFERED_PLMN;
    }

    for (count = 0; count < MAX_PREFFERED_PLMN; count++)
    {
        gPrefListDisplay.nStrItemList[count] = NULL;
    }

    for (count = 0; count < gPrefList.PrefListSize; count++, index++)
    {
        /* diamond, 2006/03/08 Get plmn string from the list of preferred networks stored in sim */
        mmi_netset_retrieve_opname_from_plmn(gPrefList.PrefPLMN[count], (U8*)gPrefListDisplay.PrefNetworkListDislpay[count]);
        gPrefListDisplay.nStrItemList[count] = (PU8) gPrefListDisplay.PrefNetworkListDislpay[count];
    }
    return count;
}

/* micha0612 */


/*****************************************************************************
 * FUNCTION
 *  ExitNETSETShowPreferredListReGet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNETSETShowPreferredListReGet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    history Scr;
    U16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < gPrefList.PrefListSize; ++count)
    {
        gPrefListDisplay.nStrItemList[count] = NULL;
    }
    /* micha0531 */
    Scr.scrnID = SCR_ID_NETSET_SHOW_PREFERRED_LIST;
    Scr.entryFuncPtr = NETSETGetPreferredNetworkReq;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);

    /* not always add this history to the top of history nodes */
    if ((isInCall() && !IsWapCallPresent()) || isOutgoingCall())
    {
        {
            PRINT_INFORMATION("isInCall return %d", isInCall());
            PRINT_INFORMATION("IsWapCallPresent return %d", IsWapCallPresent());
            PRINT_INFORMATION("isOutgoingCall return %d", isOutgoingCall());
        }
        InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
    }
    else
    {
        AddHistory(Scr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerPrefNwkHideAddIfFull
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_KEEP_ORI_STYLE__
void HiliteHandlerPrefNwkHideAddIfFull(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gPrefList.PrefListSize >= MAX_PREFFERED_PLMN) || (gPrefList.PrefListSize >= g_pwr_context.NoOfPLMNSupported))
    {
        ExecuteCurrHiliteHandler(index + 2);
    }
    else
    {
        ExecuteCurrHiliteHandler(index);
    }
}
#endif /* __MMI_KEEP_ORI_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETShowPrefNwkOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETShowPrefNwkOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U16 nStrItemList[15];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 ItemIcons[15];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS, NULL, EntryNETSETShowPrefNwkOptions, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_SHOW_PREF_NWK_OPTIONS);
    nNumofItem = GetNumOfChild(MITEM_PRF_NWK_OPTIONS_PSEUDO);

    ItemIcons[0] = IMG_GLOBAL_L1;
    ItemIcons[1] = IMG_GLOBAL_L2;
    ItemIcons[2] = IMG_GLOBAL_L3;
    ItemIcons[3] = IMG_GLOBAL_L4;
    GetSequenceStringIds(MITEM_PRF_NWK_OPTIONS_PSEUDO, nStrItemList);
    SetParentHandler(MITEM_PRF_NWK_OPTIONS_PSEUDO);

#ifndef __MMI_KEEP_ORI_STYLE__
    RegisterHighlightHandler(HiliteHandlerPrefNwkHideAddIfFull);
#else 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif 

    if (gPrefList.PrefListSize == 0)
    {
        nNumofItem = 2;
    }

#ifndef __MMI_KEEP_ORI_STYLE__
    if ((gPrefList.PrefListSize >= MAX_PREFFERED_PLMN) || (gPrefList.PrefListSize >= g_pwr_context.NoOfPLMNSupported))
    {
        nNumofItem = 2;
        nStrItemList[0] = nStrItemList[2];
        nStrItemList[1] = nStrItemList[3];
    }
#endif /* __MMI_KEEP_ORI_STYLE__ */ 

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
    /* micha0612 */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  IsNetworkDuplicated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsNetworkDuplicated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S8 pOutBuffer1[ENCODING_LENGTH * (MAX_PLMN_LEN + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.IsNewPrefNetwork == 1)
    {
        /* create new */
        memset(pOutBuffer1, 0, ENCODING_LENGTH * (MAX_PLMN_LEN + 1));
        mmi_ucs2_to_asc((PS8) pOutBuffer1, (PS8) gPrefListDisplay.PlmnNew);
        for (index = 0; index < gPrefList.PrefListSize; index++)
        {
        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
        #else
            if ((strcmp(pOutBuffer1, (PS8) gPrefList.PrefPLMN[index]) == 0))
        #endif
            {
                return 1;
            }
        }
    }
    else
    {
        /* add from list */
        for (index = 0; index < gPrefList.PrefListSize; index++)
        {
        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
        #else
            if (bcdPlmnsToDisplayName[gPrefListDisplay.SortingArray[gPrefListDisplay.CurrSelAddPLMN]].plmn_bcd == mmi_netset_plmn_str_2_bcd_short(gPrefList.PrefPLMN[index]))
        #endif
            {
                return 1;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNETSETNewPrefNwk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNETSETNewPrefNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(EntryNETSETNewNetwork, KEY_EVENT_UP);
    /* micha0529 */
    SetKeyHandler(EntryNETSETNewNetwork, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNewEntryHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNewEntryHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.PlmnNew[0] == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    }

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(SendNewPrr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNETSETNewNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNETSETNewNetwork(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_NEW_NETWORK, ExitNETSETNewNetwork, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_NEW_NETWORK);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_NETSET_NEW_NETWORK, &inputBufferSize);     /* added for inline edit history */

    InitializeCategory57Screen();
    FillNewPrefNetworkInlineEditStruct();
    RegisterHighlightHandler(HighlightNewEntryHandler);

    DisableCategory57ScreenDone();

    /* 2006/02/16 USIM preferred network implementation */
    if (gPrefList.SimFileIdx != FILE_PLMNSEL_IDX)
    {
        if (inputBuffer != NULL)
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLinePriorityUnchanged,
                InLinePriorityMinusOne,
                InLinePriorityAddOne);
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#else   
            SetCategory57Data(wgui_inline_items, 4, inputBuffer);
#endif
        }
        else
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLinePriorityDefault,
                InLinePriorityMinusOne,
                InLinePriorityAddOne);
        }
        ShowCategory57Screen(
            STR_ID_NETSET_PRR_NWK_NEW,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#else   
            4,
#endif
            NULL,
            wgui_inline_items,
            1,
            guiBuffer);
    }
    else
    {
        if (inputBuffer != NULL)
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLinePriorityUnchanged,
                InLinePriorityMinusOne,
                InLinePriorityAddOne);
            SetCategory57Data(wgui_inline_items, 4, inputBuffer);
        }
        else
        {
            SetInlineItemUserDefinedSelect(
                &wgui_inline_items[3],
                InLinePriorityDefault,
                InLinePriorityMinusOne,
                InLinePriorityAddOne);
        }
        ShowCategory57Screen(
            STR_ID_NETSET_PRR_NWK_NEW,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            4,
            NULL,
            wgui_inline_items,
            1,
            guiBuffer);
    }

    /* micha0522 */
    SetCategory57RightSoftkeyFunctions(SendNewPrr, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitNETSETNewNetwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitNETSETNewNetwork(void)
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
    Scr.scrnID = SCR_ID_NETSET_NEW_NETWORK;
    Scr.entryFuncPtr = EntryNETSETNewNetwork;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  FillNewPrefNetworkInlineEditStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillNewPrefNetworkInlineEditStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gPrefListDisplay.PlmnNew, 0, (MAX_PLMN_LEN + 1) * ENCODING_LENGTH);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) (U8*) GetString(STR_ID_NETSET_PRR_MCC_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) (U8*) GetString(STR_ID_NETSET_PRR_PR_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    /* 2006/02/16 USIM preferred network implementation */
    if (gPrefList.SimFileIdx != FILE_PLMNSEL_IDX)
    {
    #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
    }

    SetInlineItemTextEdit(&wgui_inline_items[1], (PU8) gPrefListDisplay.PlmnNew, MAX_PLMN_LEN + 1, INPUT_TYPE_NUMERIC);
    SetInlineItemFullWidth(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
}


/*****************************************************************************
 * FUNCTION
 *  InLinePriorityUnchanged
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *InLinePriorityUnchanged(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(gPrefListDisplay.PriorityVal, (UI_string_type) gPrefListDisplay.NewNwPriorityDisplay, 10);
    return gPrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLinePriorityDefault
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *InLinePriorityDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPrefListDisplay.PriorityVal = gPrefList.PrefListSize + 1;
    gui_itoa(gPrefListDisplay.PriorityVal, (UI_string_type) gPrefListDisplay.NewNwPriorityDisplay, 10);
    return gPrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLinePriorityMinusOne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *InLinePriorityMinusOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPrefListDisplay.PriorityVal--;
    if (gPrefListDisplay.PriorityVal <= 0)
    {
        gPrefListDisplay.PriorityVal = gPrefList.PrefListSize + 1;
    }

    gui_itoa(gPrefListDisplay.PriorityVal, (UI_string_type) gPrefListDisplay.NewNwPriorityDisplay, 10);
    return gPrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  InLinePriorityAddOne
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *InLinePriorityAddOne(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.PriorityVal < gPrefList.PrefListSize + 1)
    {
        gPrefListDisplay.PriorityVal++;
        gui_itoa(gPrefListDisplay.PriorityVal, (UI_string_type) gPrefListDisplay.NewNwPriorityDisplay, 10);
    }
    else
    {
        gPrefListDisplay.PriorityVal = 1;
        gui_itoa(gPrefListDisplay.PriorityVal, (UI_string_type) gPrefListDisplay.NewNwPriorityDisplay, 10);
    }

    return gPrefListDisplay.NewNwPriorityDisplay;
}


/*****************************************************************************
 * FUNCTION
 *  SendNewPrr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendNewPrr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPrefListDisplay.IsNewPrefNetwork = 1;
    CloseCategory57Screen();
    if ((gPrefListDisplay.PriorityVal > g_pwr_context.NoOfPLMNSupported) ||
        (gPrefListDisplay.PriorityVal > MAX_PREFFERED_PLMN) || (IsNetworkDuplicated() == 1) ||
        (mmi_ucs2strlen((PS8) gPrefListDisplay.PlmnNew) < 5))
    {
        gPrefListDisplay.IsNewPrefNetwork = 0;
        DisplayPopup(
            (PU8) GetString(STR_ID_NETSET_PRF_NWK_ADDED_ERR),
            IMG_GLOBAL_UNFINISHED,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_NETSET_SHOW_PREFERRED_LIST);

    }
    else
    {
        if (gPrefListDisplay.PriorityVal > gPrefList.PrefListSize + 1)
        {
            gPrefListDisplay.PriorityVal = gPrefList.PrefListSize + 1;
        }
        NETSETAddPrefNetworkReq();
    }

}


/*****************************************************************************
 * FUNCTION
 *  GoBackPrefList
 * DESCRIPTION
 *  function to traverse history back by one
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPrefList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
    return;
}

