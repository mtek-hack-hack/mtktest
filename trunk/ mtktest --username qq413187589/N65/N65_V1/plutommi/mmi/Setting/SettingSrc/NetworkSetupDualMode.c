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
 * NetworkSetupDualMode.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is intends for WCDMA/GSM network setup.
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
#include "PrefNwksGprot.h"
#include "CommonScreens.h"
#include "MessagesExDcl.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "MessagesResourceData.h"
#include "PreferredNwksStruct.h"
#include "PrefNwksGprot.h"
#include "CustResDef.h"
#include "wgui_status_icons.h"


/* Referred from NetworkSetup.c */
extern NetworkSetupContext gNetworkSetup;
extern NetworkSetupDisplay gNetworkSetupDisplay;
extern NetworkSetupMsgQueue gNetworkSetupMsgQueue;

/* Referred from PreferredNwks.c */
extern PrefNetworkListContext gPrefList;
extern PrefNetworkListDisplay gPrefListDisplay;

#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
extern UserCtrlPlmnListContext gUserCtrlPlmnList;
#endif

extern S8 gHomePLMNNum[];
extern U8 gPLMN[];

S8 *gServiceString[3];  /* inline selection between 'WCDMA' and 'GSM/GPRS' */

#if 0
#if defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#endif /* defined(__MMI_GPRS_FEATURES__) && defined(__MMI_DUAL_SIM_MASTER__) */
#endif /* 0 */

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_MODE_SELF_TEST__
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
#endif /* __MMI_DUAL_MODE_SELF_TEST__ */ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MANUAL_MODE_NW_SEL__
/* under construction !*/
#endif 
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
#ifdef __MANUAL_MODE_NW_SEL__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
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
#ifdef __MMI_DUAL_MODE_SELF_TEST__
/* under construction !*/
#endif 
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
    #ifdef __MMI_SUBLCD__
/* under construction !*/
    #endif
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
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_fill_add_prr_netwrok_inline_editor
 * DESCRIPTION
 *  Initialize inline editor for preferred networks, add from list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_fill_add_prr_netwrok_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_NETSET_PRR_PR_CAPTION));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemUserDefinedSelect(
        &wgui_inline_items[1],
        InLinePriorityDefault,
        InLinePriorityMinusOne,
        InLinePriorityAddOne);

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
 *  mmi_netset_highlight_add_network_priority_and_service
 * DESCRIPTION
 *  Highlight handler for preferred networks, add from list
 * PARAMETERS
 *  index       [IN]        Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_add_network_priority_and_service(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(ChcekThenAddNetwork);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_add_network_priority_and_service
 * DESCRIPTION
 *  Entry function to fill priority and service for preferred networks, add netwrok from list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_add_network_priority_and_service(void)
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
    EntryNewScreen(
        SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY,
        NULL,
        mmi_netset_entry_add_network_priority_and_service,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_NETSET_ADD_NEW_NETWORK_PRIORITY, &inputBufferSize);        /* added for inline edit history */

    InitializeCategory57Screen();
    mmi_netset_fill_add_prr_netwrok_inline_editor();
    RegisterHighlightHandler(mmi_netset_highlight_add_network_priority_and_service);

    if (inputBuffer != NULL)
    {
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)    
/* under construction !*/
#else
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);
#endif
    }
    ShowCategory57Screen(
        STR_ID_NETSET_PRF_ADD_SHW_NWK_PRIORITY_TITLE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) 
/* under construction !*/
#else
        2,
#endif
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_preferred_networks_item
 * DESCRIPTION
 *  Dynamically get preferred networks items
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_netset_get_preferred_networks_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      if((item_index < 0) || (item_index > MAX_PLMN_NO_LIST_LENGTH))
    //              return MMI_FALSE;

    mmi_ucs2cpy((S8*) str_buff, (S8*) gPrefListDisplay.nStrItemList[item_index]);
    *img_buff_p = get_image(gPrefListDisplay.PLMNListIcons[item_index]);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_get_preferred_networks_hint
 * DESCRIPTION
 *  Dynamically get preferred networks items
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 *  UI_string_type str_buff(?)
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_netset_get_preferred_networks_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempDislpay[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((PS8) tempDislpay, (S8*) gPrefList.PrefPLMN[item_index]);

    /* Skip the hint if the item data and hint data are the same as plmn number */
    if (mmi_ucs2cmp((S8*) gPrefListDisplay.nStrItemList[item_index], (PS8) tempDislpay) == 0)
    {
        return MMI_FALSE;
    }

    mmi_ucs2cpy((PS8) * hint_array, (PS8) tempDislpay);
    return MMI_TRUE;
}

/* diamond, 2006/03/08 New PLMN management */


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_plmn_str_2_bcd_short
 * DESCRIPTION
 *  
 * PARAMETERS
 *  plmn        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_netset_plmn_str_2_bcd_short(U8 *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 b1 = 0, b2 = 0, b3 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b1 = (*plmn - 0x30) + ((*(plmn + 1) - 0x30) << 4);
    b2 = (*(plmn + 2) - 0x30) + (*(plmn + 5) == 0 ? 0xF0 : ((*(plmn + 5) - 0x30) << 4));
    b3 = (*(plmn + 3) - 0x30) + ((*(plmn + 4) - 0x30) << 4);
    return b1 + (b2 << 8) + (b3 << 16);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_bcd_short_2_plmn_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bcd         [IN]        
 *  plmn        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_bcd_short_2_plmn_str(U32 bcd, U8 *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *plmn = (U8) (0x30 + (bcd & 0x0000000F));
    *(plmn + 1) = (U8) (0x30 + ((bcd & 0x000000F0) >> 4));
    *(plmn + 2) = (U8) (0x30 + ((bcd & 0x00000F00) >> 8));
    *(plmn + 3) = (U8) (0x30 + ((bcd & 0x000F0000) >> 16));
    *(plmn + 4) = (U8) (0x30 + ((bcd & 0x00F00000) >> 20));
    *(plmn + 5) = (bcd & 0x0000F000) == 0x0000F000 ? 0 : (U8) (0x30 + ((bcd & 0x0000F000) >> 12));
    *(plmn + 6) = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_retrieve_opname_from_plmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  plmn        [?]     
 *  opname      [?]     
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_netset_retrieve_opname_from_plmn(U8 *plmn, U8 *opname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* plmn: null-terminated plmn string in octet */
    /* opname: unicode string for display */
    U16 count;  /* Where is the matched plmn */
    U16 index;  /* The string index of the plmn */

    U8 search_plmn[7];

    /* find the user defined PLMNs first */
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    U32 plmn_usr;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    for (count = 0; count < gUserCtrlPlmnList.PlmnListSize; count++)
    {
        memcpy((char*)(&plmn_usr), gUserCtrlPlmnList.PrefPLMN[count], sizeof(U32));
        if (plmn_bcd == plmn_usr)
        {
            if (opname)
            {
                mmi_asc_to_ucs2((S8*) opname, (S8*) (gUserCtrlPlmnList.PrefPLMN[count] + sizeof(U32)));
            }
            return count;
        }
    }
#endif /* __MMI_USER_CTRL_PLMN_SUPPORT__ */ 

    for (count = 0; bcdPlmnsToDisplayName[count].plmn_bcd != 0; count++)
    {
        mmi_netset_bcd_short_2_plmn_str(bcdPlmnsToDisplayName[count].plmn_bcd, search_plmn);
        if (mmi_netset_plmn_matching_criteria(search_plmn, plmn))
        {
            if (opname)
            {
                index = bcdPlmnsToDisplayName[count].string_index + STR_PLMN_NAME_1;
                if (mmi_ucs2strlen(GetString(index)) >= MAX_LENGTH_DISPLAY_NAME)
                {
                    mmi_asc_to_ucs2((S8*) opname, (S8*) plmn);   /* if string length is larger than max supported display, it will casue memory corruption if make strcpy */
                }
                else
                {
                    mmi_ucs2cpy((S8*) opname, GetString(index));
                }
            }
            return count;
        }
    }

    if (opname)
    {
        mmi_asc_to_ucs2((S8*) opname, (S8*) plmn);
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_equivalent_plmn_check
 * DESCRIPTION
 *  Check if VPLMN and HPLMN is mapping to the same operator name string
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_netset_equivalent_plmn_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* gHomePLMNNum (Home PLMN) and gPLMN (camp on PLMN) are equivalent */
    U8 plmn_str_1[MAX_PLMN_LEN_MMI], plmn_str_2[MAX_PLMN_LEN_MMI + 1];
    S16 plmn_idx_1, plmn_idx_2, g_plmn_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(plmn_str_1, gHomePLMNNum, 5);    /* assumed that Home PLMN is 5-digit */
    plmn_str_1[5] = 0;
    memcpy(plmn_str_2, gHomePLMNNum, 6);    /* assumed that Home PLMN is 6-digit */
    plmn_str_2[6] = 0;

    plmn_idx_1 = mmi_netset_retrieve_opname_from_plmn(plmn_str_1, NULL);
    plmn_idx_2 = mmi_netset_retrieve_opname_from_plmn(plmn_str_2, NULL);

    if ((g_plmn_idx = mmi_netset_retrieve_opname_from_plmn(gPLMN, NULL)) == -1)
    {
        return MMI_FALSE;
    }

    if (plmn_idx_1 != -1 && bcdPlmnsToDisplayName[plmn_idx_1].string_index == bcdPlmnsToDisplayName[g_plmn_idx].string_index)
    {
        return MMI_TRUE;
    }
    else if (plmn_idx_2 != -1 && bcdPlmnsToDisplayName[plmn_idx_2].string_index == bcdPlmnsToDisplayName[g_plmn_idx].string_index)
    {
        return MMI_TRUE;
    }
/*
    if (bcdPlmnsToDisplayName[plmn_idx_1].string_index == bcdPlmnsToDisplayName[g_plmn_idx].string_index
        || bcdPlmnsToDisplayName[plmn_idx_2].string_index == bcdPlmnsToDisplayName[g_plmn_idx].string_index)
    {
        return MMI_TRUE;
    }
*/
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_is_t_mobile_us_sim
 * DESCRIPTION
 *  Check if the inserted SIM is T-Mobile
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_netset_is_t_mobile_us_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 plmn_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(gHomePLMNNum, "310", 3) != 0)
    {
        return MMI_FALSE; /* not in United States */
    }

    plmn_idx = mmi_netset_retrieve_opname_from_plmn((PU8) gHomePLMNNum, NULL);

    if (mmi_ucs2cmp(GetString((U16)(STR_PLMN_NAME_1 + bcdPlmnsToDisplayName[plmn_idx].string_index)), (PS8) L"T-Mobile") == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE; /* not T-Mobile SIM */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sort_2_entry_comapre
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bcd_a       [IN]        
 *  bcd_b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S16 mmi_netset_sort_2_entry_comapre(U16 bcd_a, U16 bcd_b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* compare a with b */
    U8 i = 0, strlen_a, strlen_b;
    S8 *str_a = GetString((U16)(STR_PLMN_NAME_1 + bcdPlmnsToDisplayName[bcd_a].string_index));
    S8 *str_b = GetString((U16)(STR_PLMN_NAME_1 + bcdPlmnsToDisplayName[bcd_b].string_index));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen_a = mmi_ucs2strlen(str_a);
    strlen_b = mmi_ucs2strlen(str_b);

    do
    {
        if (*(U16*) (str_a + i) > *(U16*) (str_b + i))
        {
            return 1;
        }
        else if (*(U16*) (str_a + i) < *(U16*) (str_b + i))
        {
            return -1;
        }
        else
        {
            i += ENCODING_LENGTH;
        }
    } while (i < strlen_a && i < strlen_b);

    if (strlen_a > strlen_b)
    {
        return 1;
    }
    else if (strlen_a < strlen_b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sort_insert_new_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  reference       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_sort_insert_new_entry(U16 index, U16 reference)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* index = target, reference = place */
    /* index always <= reference */
    /* index=i, reference=j, reference<index */
    U16 i, tmp1, tmp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == reference) /* insert to the latest one */
    {
        gPrefListDisplay.SortingArray[index] = index;
    }
    else
    {
        tmp2 = index;
        for (i = reference; i <= index; i++)
        {
            tmp1 = gPrefListDisplay.SortingArray[i];
            gPrefListDisplay.SortingArray[i] = tmp2;
            tmp2 = tmp1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sort_plmn_list_by_alphabet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_record        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_sort_plmn_list_by_alphabet(U16 total_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    S16 cmp1, cmp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.SortingArray)
    {
        OslMfree(gPrefListDisplay.SortingArray);
    }
    gPrefListDisplay.SortingArray = OslMalloc(total_record * 2);

    //PRINT_INFORMATION("@@@@@ PLMN list sorted by alphabet @@@@@");

    /* sorting array index 0 */
    gPrefListDisplay.SortingArray[0] = 0;

    /* sorting array index 1 */
    if (mmi_netset_sort_2_entry_comapre(1, gPrefListDisplay.SortingArray[0]) < 0)
    {
        mmi_netset_sort_insert_new_entry(1, 0);
    }
    else
    {
        mmi_netset_sort_insert_new_entry(1, 1);
    }

    /* sorting array index 2 to max */
    for (i = 2; i < total_record; i++)
    {
        cmp1 = mmi_netset_sort_2_entry_comapre(i, gPrefListDisplay.SortingArray[0]);
        if (cmp1 < 0)
        {
            mmi_netset_sort_insert_new_entry(i, 0);
        }
        else
        {
            for (j = 1; j < i; j++)
            {
                cmp2 = mmi_netset_sort_2_entry_comapre(i, gPrefListDisplay.SortingArray[j]);
                if (cmp2 < 0)
                {
                    break;
                }
                cmp1 = cmp2;
            }
            mmi_netset_sort_insert_new_entry(i, j);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_sort_plmn_list_by_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_record        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_sort_plmn_list_by_default(U16 total_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPrefListDisplay.SortingArray)
    {
        OslMfree(gPrefListDisplay.SortingArray);
    }
    gPrefListDisplay.SortingArray = OslMalloc(total_record * 2);

    //PRINT_INFORMATION("@@@@@ PLMN list sorted by defauly @@@@@");

    for (i = 0; i < total_record; i++)
    {
        gPrefListDisplay.SortingArray[i] = i;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_add_from_list_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_add_from_list_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ADD_FROM_LIST_OPTIONS, NULL, mmi_netset_entry_add_from_list_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_ADD_FROM_LIST_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_ADD_FROM_LIST_OPTIONS);

    GetSequenceStringIds_Ext(MENU_ID_ADD_FROM_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_ADD_FROM_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_SETTINGS_ICON,
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_add_from_list_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_add_from_list_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#else
    EntryNETSETAddNetworkPriority();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_sort_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_sort_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NETSET_DUMMY_PROGRESS, NULL, mmi_netset_entry_sort_progress, NULL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    ShowCategory66Screen(STR_ID_NETSET_MITEM9187, 0, 0, 0, 0, 0, (U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_sort_by_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_sort_by_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_entry_sort_progress();

    for (index = 0;; index++)
    {
        if (bcdPlmnsToDisplayName[index].plmn_bcd == 0)
        {
            break;
        }
    }

    gPrefListDisplay.SortingMethod = 0;
    mmi_netset_sort_plmn_list_by_default(index);
    mmi_frm_unhide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_ALPHABET);
    mmi_frm_hide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_DEFAULT);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_ADD_FROM_LIST_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_sort_by_alphabet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_sort_by_alphabet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_netset_entry_sort_progress();

    for (index = 0;; index++)
    {
        if (bcdPlmnsToDisplayName[index].plmn_bcd == 0)
        {
            break;
        }
    }

    gPrefListDisplay.SortingMethod = 1;
    mmi_netset_sort_plmn_list_by_alphabet(index);
    mmi_frm_unhide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_DEFAULT);
    mmi_frm_hide_menu_item(MENU_ID_ADD_FROM_LIST_SORT_BY_ALPHABET);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_ADD_FROM_LIST_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_NETSET_DUMMY_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_add_from_list_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_add_from_list_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_netset_entry_add_from_list_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_netset_entry_add_from_list_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_sort_by_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_sort_by_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_netset_entry_sort_by_default, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_netset_entry_sort_by_default, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_highlight_sort_by_alphabet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_highlight_sort_by_alphabet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_netset_entry_sort_by_alphabet, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_netset_entry_sort_by_alphabet, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_plmn_matching_criteria
 * DESCRIPTION
 *  Implementation of 23.122 for PLMN match criteria
 * PARAMETERS
 *  sim_plmn        [IN]
 *  bcch_plmn       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_netset_plmn_matching_criteria(const U8 *sim_plmn, const U8 *bcch_plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL rtn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.CurrentCampOnBand == MMI_BAND_1900)
    {
        if (memcmp(sim_plmn, bcch_plmn, 3) == 0)
        {
            if (strlen((S8*) bcch_plmn) == 5)
            {
                if (*(bcch_plmn) == 0x33 && *(bcch_plmn + 1) == 0x31 && (*(bcch_plmn + 2) >= 0x30 && *(bcch_plmn + 2) <= 0x36))
                {
                    if (strlen((S8*) sim_plmn) == 5 || *(sim_plmn + 5) == 0x30)
                    {
                        rtn = (memcmp(sim_plmn + 3, bcch_plmn + 3, 2) == 0) ? 1 : 0;
                    }
                    else
                    {
                        rtn = 0;
                    }
                }
                else
                {
                    rtn = (memcmp(sim_plmn + 3, bcch_plmn + 3, 2) == 0) ? 1 : 0;
                }
            }
            else
            {
                rtn = (memcmp(sim_plmn + 3, bcch_plmn + 3, 3) == 0) ? 1 : 0;
            }
        }
        else
        {
            rtn = 0;
        }
    }
    else
    {
        if (memcmp(sim_plmn, bcch_plmn, 3) == 0)
        {
            if (strlen((S8*) bcch_plmn) == 5)
            {
                rtn = (memcmp(sim_plmn + 3, bcch_plmn + 3, 2) == 0) ? 1 : 0;
            }
            else
            {
                rtn = (memcmp(sim_plmn + 3, bcch_plmn + 3, 3) == 0) ? 1 : 0;
            }
        }
        else
        {
            rtn = 0;
        }
    }

    return (MMI_BOOL) rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_retrieve_current_modes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef struct _netset_callback_info
{
    FuncPtr netset_callback_func;
    U8 state;
} NETSETCALLBACKINFO;

static NETSETCALLBACKINFO mmi_netset_callbacks[] = 
{
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#endif
#ifdef __MMI_GPRS_FEATURES__
    {NETSETGetGPRSModeReq, 1},
#if 0
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */    
#endif /* 0 */    
#endif /* __MMI_GPRS_FEATURES__ */
    {NULL, 0}                                            /* dummy one, please add callbacks before this entity */
};

void mmi_netset_retrieve_current_modes(void)
{
    U8 i;

    for (i = 0; mmi_netset_callbacks[i].netset_callback_func != NULL; i++)
    {
        if (mmi_netset_callbacks[i].state)
        {
            (*mmi_netset_callbacks[i].netset_callback_func)();
            mmi_netset_callbacks[i].state = 0;
            return;
        }
    }

    EntryNETSETMain();

    for (i = 0; mmi_netset_callbacks[i].netset_callback_func != NULL; i++)
    {
	mmi_netset_callbacks[i].state = 1;
    }
}
