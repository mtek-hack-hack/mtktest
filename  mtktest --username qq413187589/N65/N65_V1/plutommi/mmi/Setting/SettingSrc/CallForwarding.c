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
 * CallForwarding.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CallForwarding.c

   PURPOSE     : Call Setting - Call forwarding Application

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
#include "MMI_include.h"
#include "CSP.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGProt.h"
#include "CallSetUp.h"
#include "CallForwarding.h"
#include "CallSetUpEnum.h"
#include "CommonScreens.h"
#include "CallmanagementIdDef.h"
#include "MessagesExDcl.h"
#include "CallManagementGprot.h"
#include "wgui_inputs.h"
#include "MessagesMiscell.h"
#include "SMSApi.h"
#include "SMSStruct.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_header.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_VoiceMail.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern S16 MMI_current_input_ext_type;
#if defined(__MMI_TOUCH_SCREEN__)
const UI_character_type mmi_call_divert_allowed[] = L"+0-9";
#endif
static void mmi_callfwd_entry_foward_to_option(void);
static void mmi_callfwd_highlight_foward_to_new_number(void);
static void mmi_callfwd_highlight_foward_to_vm(void);
static void mmi_callfwd_foward_to_new_number(void);
static void mmi_callfwd_foward_to_vm(void);
static void mmi_callfwd_get_vm_rsp(void *mailbox, module_type mod, U16 result);

/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdCancelAll
 * DESCRIPTION
 *  Highlight handler for cancel all menu option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdCancelAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_CANCEL_ALL;
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EnterScrCallFwdOffReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitCallForwarding
 * DESCRIPTION
 *  Initialize funtion for call fwding application.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallForwarding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set hilite handlers for the individual sub menu items of call forwarding */
    SetHiliteHandler(MENU8237_SCR8093_MNGCALL_MENU_FWD, HighlightCALLSETCallFwd);
    SetHiliteHandler(MENU8238_MNGCALL_CALFWD_VOICECALL, HighlightCALLSETCallFwdVoice);
    SetHiliteHandler(MENU8238_MNGCALL_CALFWD_DATACALL, HighlightCALLSETCallFwdData);
    SetHiliteHandler(MENU8239_CALFWD_VOICECALL_UNREACHABLE, HighlightCALLSETCallFwdUnreach);
    SetHiliteHandler(MENU8239_CALFWD_VOICECALL_NOANSWER, HighlightCALLSETCallFwdNoAns);
    SetHiliteHandler(MENU8239_CALFWD_VOICECALL_ALLCOND, HighlightCALLSETCallFwdAllCond);
    SetHiliteHandler(MENU8239_CALFWD_VOICECALL_BUSY, HighlightCALLSETCallFwdBusy);
    SetHiliteHandler(MENU8240_MNGCALL_CALLFWD_FWD_ON, HighlightCALLSETCallFwdOn);
    SetHiliteHandler(MENU8240_MNGCALL_CALLFWD_FWD_OFF, HighlightCALLSETCallFwdOff);
    SetHiliteHandler(MENU8240_MNGCALL_CALLFWD_FWD_QUERY, HighlightCALLSETCallFwdQuery);
    SetHiliteHandler(MENU_CALL_FWD_CANCELALL, HighlightCALLSETCallFwdCancelAll);
    ResetCFCondStage();

    SetHiliteHandler(MENU_ID_CALFWD_TO_NEW_NUMBER, mmi_callfwd_highlight_foward_to_new_number);
    SetHiliteHandler(MENU_ID_CALFWD_TO_VM, mmi_callfwd_highlight_foward_to_vm);

#ifdef __MMI_VIDEO_TELEPHONY__
    SetHiliteHandler(MENU_ID_CALFWD_VIDEO_ALL, HighlightCALLSETCallFwdVideo);
    SetHiliteHandler(MENU_ID_CALFWD_VIDEO_UNREACHABLE, HighlightCALLSETCallFwdVideoUnreach);
    SetHiliteHandler(MENU_ID_CALFWD_VIDEO_BUSY, HighlightCALLSETCallFwdVideoBusy);
    SetHiliteHandler(MENU_ID_CALFWD_VIDEO_NOANSWER, HighlightCALLSETCallFwdVideoNoAns);
    SetHiliteHandler(MENU_ID_CALFWD_VIDEO_ALL_COND, HighlightCALLSETCallFwdVideoAllCond);
#endif /* __MMI_VIDEO_TELEPHONY__ */
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwd
 * DESCRIPTION
 *  Highlight handler for the call fwding menu option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

#ifdef __MMI_DUAL_SIM_MASTER__
    /*set call channel*/
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    /* set the left/right arrow key function handlers */
    SetKeyHandler(EntryCALLSETForwardMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVoice
 * DESCRIPTION
 *  Hightlight handler for call fwd voice sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVoice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_ALLVOICE;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdData
 * DESCRIPTION
 *  highlight hander for call fwd data sub menu item.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_DATA;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key functions handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdUnreach
 * DESCRIPTION
 *  Highlight handler for voice unreach sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdUnreach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_UNREACHABLE;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdBusy
 * DESCRIPTION
 *  Highlight handler for when busy sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdBusy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_BUSY;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdNoAns
 * DESCRIPTION
 *  Highlight handler for call fwd when no answer
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdNoAns(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_NOANSWER;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVideo
 * DESCRIPTION
 *  Hightlight handler for video call fwd sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_ALLVIDEO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVideoUnreach
 * DESCRIPTION
 *  Highlight handler for video call unreach sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVideoUnreach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_UNREACHABLE_VIDEO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVideoBusy
 * DESCRIPTION
 *  Highlight handler for when video call busy sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVideoBusy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_BUSY_VIDEO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVideoNoAns
 * DESCRIPTION
 *  Highlight handler for when video call no answer sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVideoNoAns(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_NOANSWER_VIDEO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdVideoAllCond
 * DESCRIPTION
 *  Highlight handler for video call fwd when all conditional
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdVideoAllCond(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_ALLCOND_VIDEO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */

/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdAllCond
 * DESCRIPTION
 *  Highlight handler for call fwd when no answer
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdAllCond(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.SSCFType = FORWARD_ALLCOND;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETForwardOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETForwardOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdOn
 * DESCRIPTION
 *  Highlight handler for call fwd on submenu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    /* Start by Smallp */
//    SetLeftSoftkeyFunction(EntryCALLSETForwardNumber, KEY_EVENT_UP);
    /* micha0529 */
//    SetKeyHandler(EntryCALLSETForwardNumber, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_callfwd_entry_foward_to_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_callfwd_entry_foward_to_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* End by Smallp */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdOff
 * DESCRIPTION
 *  Highlight handler for call fwd off submenu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EnterScrCallFwdOffReq, KEY_EVENT_UP);
    /* micha0529 */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallFwdQuery
 * DESCRIPTION
 *  Highlight handler for call fwd on query sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallFwdQuery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EnterScrCallFwdQueryReq, KEY_EVENT_UP);
    /* micha0529 */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_callfwd_entry_foward_to_option
 * DESCRIPTION
 *  Entry function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_callfwd_entry_foward_to_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*can't divert data call to voice mail*/
	if(g_callset_context.SSCFType == FORWARD_DATA)
	{
		mmi_frm_hide_menu_item(MENU_ID_CALFWD_TO_VM);
	}
	else
	{	
		mmi_frm_unhide_menu_item(MENU_ID_CALFWD_TO_VM);
	}

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_CALFWD_TO_OPTION, NULL, mmi_callfwd_entry_foward_to_option, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALFWD_TO_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_CALFWD_TO_OPTION);

    /* 4. Get attribute of menu to be displayed */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_ID_CALFWD_TO_OPTION, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_CALFWD_TO_OPTION);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List - no need */

    ShowCategory52Screen(
        STR_ID_CALFWD_TO_OPTION,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0, 0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_callfwd_highlight_foward_to_new_number
 * DESCRIPTION
 *  Highlight function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_callfwd_highlight_foward_to_new_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_callfwd_foward_to_new_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_callfwd_foward_to_new_number, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_callfwd_highlight_foward_to_vm
 * DESCRIPTION
 *  Hightlight function
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_callfwd_highlight_foward_to_vm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_callfwd_foward_to_vm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_callfwd_foward_to_vm, KEY_EVENT_UP);
}


static void mmi_callfwd_foward_to_new_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryCALLSETForwardNumber();
}

static void mmi_callfwd_foward_to_vm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);

#if !defined(__MMI_DUAL_SIM_MASTER__)
    mmi_frm_sms_get_mailbox_info(mmi_callfwd_get_vm_rsp, MOD_MMI);
#else /* __MMI_DUAL_SIM_MASTER__ */
    if ((MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE) ||
        (MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE))
    {
        mmi_frm_sms_get_card2_mailbox_info(mmi_callfwd_get_vm_rsp, MOD_MMI);
    }
    else
    {
        mmi_frm_sms_get_mailbox_info(mmi_callfwd_get_vm_rsp, MOD_MMI);
    }
#endif /* __MERCURY_MASTER__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_mailbox_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mailbox     [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_callfwd_get_vm_rsp(void *mailbox, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isIncomingCall())
    {
        return;
    }
    if (result == MMI_FRM_SMS_OK)
    {
        mmi_frm_sms_mailbox_struct *mailboxlist = (mmi_frm_sms_mailbox_struct*) mailbox;

        for (count = 0; count < mailboxlist->mailboxNumber; count++)
        {
			if(*(mailboxlist->pMailBoxNumber[count]) != 0)
			{
				mmi_ucs2cpy((S8*) g_callset_context.SSCFNum, (S8*) mailboxlist->pMailBoxNumber[count]);
				EnterScrCallFwdOnReq();
				return;
			} 
		}

		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_EMPTY),
			IMG_GLOBAL_EMPTY,
			1,
			MESSAGES_POPUP_TIME_OUT,
			(U8) EMPTY_LIST_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETForwardMain
 * DESCRIPTION
 *  Entry function for call fwd main screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETForwardMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */

    EntryNewScreen(SCR_ID_CALLSET_FORWARD_MAIN, NULL, EntryCALLSETForwardMain, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_FORWARD_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU8237_SCR8093_MNGCALL_MENU_FWD);  /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8237_SCR8093_MNGCALL_MENU_FWD); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU8237_SCR8093_MNGCALL_MENU_FWD, nStrItemList);  /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU8237_SCR8093_MNGCALL_MENU_FWD);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
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
#endif /* 0 */ 

    /* Display Category15 Screen */
    ShowCategory15Screen(
        STR_MENU8238_MNGCALL_CALLFWD_CAPTION,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETForwardOptions
 * DESCRIPTION
 *  Entry function for call fwd options screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETForwardOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_FORWARD_OPTIONS, NULL, EntryCALLSETForwardOptions, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_FORWARD_OPTIONS);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU8240_MNGCALL_CALLFWD_FWD_OPTION);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8240_MNGCALL_CALLFWD_FWD_OPTION  ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU8240_MNGCALL_CALLFWD_FWD_OPTION, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU8240_MNGCALL_CALLFWD_FWD_OPTION);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* Display Category1 Screen */
    ShowCategory15Screen(
        STR_MENU8240_MNGCALL_CALLFWD_FWD_OPTION,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  StarKeyHandler
 * DESCRIPTION
 *  Key handler for the astrick key.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StarKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_direct_input('+');
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETForwardNumber
 * DESCRIPTION
 *  Entry function for the enter number for call fwd screen.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETForwardNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_FORWARD_NUMBER, ExitCALLSETForwardNumber, EntryCALLSETForwardNumber, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_FORWARD_NUMBER);
    /* Check the screen is from forward or backward traversal */
    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSCFNum, 0, (MAX_CC_ADDR_LEN * ENCODING_LENGTH) + 2);
    }
    if (g_callset_context.SSCFNumFromPHB)
    {
        guiBuffer = NULL;
    }
    g_callset_context.SSCFNumFromPHB = FALSE;
    MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;

    RegisterInputBoxEmptyFunction(CallForwardScreenEmpty);
    RegisterInputBoxNotEmptyFunction(CallForwardScreenNotEmpty);

#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_set_vk_keys(MMI_TRUE, mmi_call_divert_allowed, NULL);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    /* to display the screen for taking input for the callfwd number */
    ShowCategory5Screen(
        STR_CALL_FWD_ENTER_NUM_CAP,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_PHONE_NUMBER,
        (PU8) g_callset_context.SSCFNum,
        MAX_CC_ADDR_LEN,
        guiBuffer);
    /* clear key handler for the pound key */
    ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
    /* set key handler for the astrick key */
    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_REPEAT);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(StarKeyHandler, KEY_STAR, KEY_EVENT_DOWN);
    /* set the left and right soft key functionalities */
    SetLeftSoftkeyFunction(EnterScrCallFwdOnReq, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCALLSETForwardNumber
 * DESCRIPTION
 *  Exit function for the enter number for call fwd screen.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCALLSETForwardNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_input_ext_type &= ~INPUT_TYPE_EXT_SIM_NUMERIC;
}


/*****************************************************************************
 * FUNCTION
 *  EnterScrCallFwdOnReq
 * DESCRIPTION
 *  Entry function for call fwd screen when on req .
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterScrCallFwdOnReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];
    S8 string_code[50];
    PS8 hash_string = NULL;
    S8 uni_input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the buffer of the call fwding number */
    if (mmi_ucs2strlen((S8*) g_callset_context.SSCFNum) == 0)
    {
        mmi_phb_call_enter_from_divert();
        return;
    }

    for (i = 0; i < mmi_ucs2strlen((S8*) g_callset_context.SSCFNum); i++)
    {
        if ((g_callset_context.SSCFNum[i * 2] == 'p') || (g_callset_context.SSCFNum[i * 2] == 'w'))
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            return;
        }
    }

    /* format the string for the ss string handling */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    memset(string_code, 0, 50);
    hash_string = (PS8) GetString(STR_HASH_VALUE);

    switch (g_callset_context.SSCFType)
    {
            /* if the menu item is selected is voice call fwd when un reachable */
        case FORWARD_UNREACHABLE:
            strcpy((S8*) string_code, "**62*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_code, "*11");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_code, "*89");
            }
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
            /* if the menu item is selected is voice call fwd when no answer */
        case FORWARD_NOANSWER:
        case FORWARD_ALLCOND:
            EntryCALLSETForwardNoAnsTime();
            return;
            /* if the menu item is selected is voice call fwd when busy */
        case FORWARD_BUSY:
            strcpy((S8*) string_code, "**67*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_code, "*11");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_code, "*89");
            }
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
            /* if the menu item is selected all voice call fwd */
        case FORWARD_ALLVOICE:
            strcpy((S8*) string_code, "**21*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
        #ifdef __MMI_DUAL_SIM_MASTER__
             if(MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE ||
                MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
             {
                if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
                {
                     strcpy((S8*) string_code, "*11");
                }
                else if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_2)
                {
                     strcpy((S8*) string_code, "*89");
                }
             }
             else
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                if(g_callset_context.LineID == LINE1)
                {
                     strcpy((S8*) string_code, "*11");
                }
                else if(g_callset_context.LineID == LINE2)
                {
                     strcpy((S8*) string_code, "*89");
                }
            }
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
            /* if the menu item is selected is data call fwd */
        case FORWARD_DATA:
            strcpy((S8*) string_code, "**21*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);

        #ifdef __MMI_VIDEO_TELEPHONY__
            strcpy((S8*) string_code, "*25");
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_code, "*20");
        #endif /* __MMI_VIDEO_TELEPHONY__ */

            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;

    #ifdef __MMI_VIDEO_TELEPHONY__
                /* if the menu item is selected is video call fwd when un reachable */
        case FORWARD_UNREACHABLE_VIDEO:
            strcpy((S8*) string_code, "**62*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
            strcpy((S8*) string_code, "*24");
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
            /* if the menu item is selected is voice call fwd when no answer */
        case FORWARD_NOANSWER_VIDEO:
        case FORWARD_ALLCOND_VIDEO:
            EntryCALLSETForwardNoAnsTime();
            return;
            /* if the menu item is selected is voice call fwd when busy */
        case FORWARD_BUSY_VIDEO:
            strcpy((S8*) string_code, "**67*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
            strcpy((S8*) string_code, "*24");
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
            /* if the menu item is selected all voice call fwd */
        case FORWARD_ALLVIDEO:
            strcpy((S8*) string_code, "**21*");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
            strcpy((S8*) string_code, "*24");
            mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
            mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
            mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    /* set protocol event handler for the call fwd response */
    SetProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    /* make a corresponding ss string for call fwd option */
    MakeCall((PS8) input_string);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  ResetCFCondStage
 * DESCRIPTION
 *  Entry function for call fwd screen when off req .
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCFCondStage(void)
{
    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  EnterScrCallFwdOffReq
 * DESCRIPTION
 *  Entry function for call fwd screen when off req .
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterScrCallFwdOffReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];
    S8 string_out[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //micha1229
    //      PS8 hash_string = NULL ;
    /* format the string for the ss string handling */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    memset(string_out, 0, 20);
    /* hash_string = (PS8) GetString(STR_HASH_VALUE); */
    switch (g_callset_context.SSCFType)
    {
            /* if the menu item is selected is voice call fwd when un reachable */
        case FORWARD_UNREACHABLE:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "##62**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "##62**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "##62#");            
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is voice call fwd when no answer */
        case FORWARD_NOANSWER:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "##61**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "##61**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "##61#");            
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is voice call fwd when all conditional */
        case FORWARD_BUSY:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "##67**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "##67**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "##67#");            
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected all voice call fwd */
        case FORWARD_ALLCOND:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "##004**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "##004**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "##004#");            
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is voice call fwd when busy */
        case FORWARD_ALLVOICE:
        #ifdef __MMI_DUAL_SIM_MASTER__
             if(MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE ||
                MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
             {
                if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
                {
                     strcpy((S8*) string_out, "##21**11#");
                }
                else if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_2)
                {
                     strcpy((S8*) string_out, "##21**89#");
                }
             }
             else
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                if(g_callset_context.LineID == LINE1)
                {
                     strcpy((S8*) string_out, "##21**11#");
                }
                else if(g_callset_context.LineID == LINE2)
                {
                     strcpy((S8*) string_out, "##21**89#");
                }
            }
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is cancel all fwd */
        case FORWARD_CANCEL_ALL:
            strcpy((S8*) string_out, "##002#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is data call fwd */
        case FORWARD_DATA:
        #ifdef __MMI_VIDEO_TELEPHONY__
            strcpy((S8*) string_out, "##21**25#");
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "##21**20#");
        #endif /* __MMI_VIDEO_TELEPHONY__ */            
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
    #ifdef __MMI_VIDEO_TELEPHONY__
            /* if the menu item is selected is video call fwd when un reachable */
        case FORWARD_UNREACHABLE_VIDEO:
            strcpy((S8*) string_out, "##62**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is video call fwd when no answer */
        case FORWARD_NOANSWER_VIDEO:
            strcpy((S8*) string_out, "##61**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is video call fwd when busy */
        case FORWARD_BUSY_VIDEO:
            strcpy((S8*) string_out, "##67**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected all video call fwd */
        case FORWARD_ALLCOND_VIDEO:
            strcpy((S8*) string_out, "##004**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is video call fwd when busy */
        case FORWARD_ALLVIDEO:
            strcpy((S8*) string_out, "##21**24#");			
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    /* set protocol event handler for the call fwd response */
    SetProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    /* make a corresponding ss string for call fwd option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EnterScrCallFwdQueryReq
 * DESCRIPTION
 *  Entry function for call fwd screen qurey request.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterScrCallFwdQueryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];
    S8 string_out[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //micha1229
    //      PS8 hash_string = NULL ;

    /* format the string for the ss string handling */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    memset(string_out, 0, 20);
    /* hash_string = (PS8) GetString(STR_HASH_VALUE); */
    switch (g_callset_context.SSCFType)
    {
            /* if the menu item is selected is voice call fwd when un reachable */
        case FORWARD_UNREACHABLE:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "*#62**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "*#62**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "*#62#");
        #endif /* __MMI_VIDEO_TELEPHONY__ */            
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is voice call fwd when no answer */
        case FORWARD_NOANSWER:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "*#61**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "*#61**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "*#61#");
        #endif /* __MMI_VIDEO_TELEPHONY__ */            
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is voice call fwd when all conditional */
        case FORWARD_BUSY:
        #ifdef __MMI_VIDEO_TELEPHONY__
            if(g_callset_context.LineID == LINE1)
            {
                strcpy((S8*) string_out, "*#67**11#");
            }
            else if(g_callset_context.LineID == LINE2)
            {
                strcpy((S8*) string_out, "*#67**89#");
            }            
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "*#67#");
        #endif /* __MMI_VIDEO_TELEPHONY__ */            
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected all voice call fwd */
        case FORWARD_ALLCOND:
            switch (g_callset_context.SSCFCondQueryStage)
            {
                case CF_COND_STAGE_NONE:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_UNREACH;            
                    
                #ifdef __MMI_VIDEO_TELEPHONY__
                    if(g_callset_context.LineID == LINE1)
                    {
                        strcpy((S8*) string_out, "*#62**11#");
                    }
                    else if(g_callset_context.LineID == LINE2)
                    {
                        strcpy((S8*) string_out, "*#62**89#");
                    }            
                #else /* __MMI_VIDEO_TELEPHONY__ */
                    strcpy((S8*) string_out, "*#62#");                    
                #endif /* __MMI_VIDEO_TELEPHONY__ */            

                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                case CF_COND_STAGE_UNREACH:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_NOANS;
                #ifdef __MMI_VIDEO_TELEPHONY__
                    if(g_callset_context.LineID == LINE1)
                    {
                        strcpy((S8*) string_out, "*#61**11#");
                    }
                    else if(g_callset_context.LineID == LINE2)
                    {
                        strcpy((S8*) string_out, "*#61**89#");
                    }            
                #else /* __MMI_VIDEO_TELEPHONY__ */
                    strcpy((S8*) string_out, "*#61#");                    
                #endif /* __MMI_VIDEO_TELEPHONY__ */            
                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                case CF_COND_STAGE_NOANS:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_BUSY;            
                #ifdef __MMI_VIDEO_TELEPHONY__
                    if(g_callset_context.LineID == LINE1)
                    {
                        strcpy((S8*) string_out, "*#67**11#");
                    }
                    else if(g_callset_context.LineID == LINE2)
                    {
                        strcpy((S8*) string_out, "*#67**89#");
                    }            
                #else /* __MMI_VIDEO_TELEPHONY__ */
                    strcpy((S8*) string_out, "*#67#");                    
                #endif /* __MMI_VIDEO_TELEPHONY__ */            
                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            break;
            /* if the menu item is selected is voice call fwd when busy */
        case FORWARD_ALLVOICE:
        #ifdef __MMI_DUAL_SIM_MASTER__
             if(MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE ||
                MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
             {
                if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_1)
                {
                     strcpy((S8*) string_out, "*#21**11#");
                }
                else if(MTPNP_AD_Get_Card2CurrLineID() == MTPNP_AD_LINE_2)
                {
                     strcpy((S8*) string_out, "*#21**89#");
                }
             }
             else
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
            {
                if(g_callset_context.LineID == LINE1)
                {
                     strcpy((S8*) string_out, "*#21**11#");
                }
                else if(g_callset_context.LineID == LINE2)
                {
                     strcpy((S8*) string_out, "*#21**89#");
                }
            }
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is data call fwd */
        case FORWARD_DATA:
        #ifdef __MMI_VIDEO_TELEPHONY__
            strcpy((S8*) string_out, "*#21**25#");
        #else /* __MMI_VIDEO_TELEPHONY__ */
            strcpy((S8*) string_out, "*#21**20#");
        #endif /* __MMI_VIDEO_TELEPHONY__ */                        
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            
    #ifdef __MMI_VIDEO_TELEPHONY__
        /* if the menu item is selected is video call fwd when un reachable */
        case FORWARD_UNREACHABLE_VIDEO:
            strcpy((S8*) string_out, "*#62**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is video call fwd when no answer */
        case FORWARD_NOANSWER_VIDEO:
            strcpy((S8*) string_out, "*#61**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected is video call fwd when busy */
        case FORWARD_BUSY_VIDEO:
            strcpy((S8*) string_out, "*#67**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;
            /* if the menu item is selected all video call fwd */
        case FORWARD_ALLVIDEO:
            strcpy((S8*) string_out, "*#21**24#");
            mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
            break;            
            /* if the menu item is selected all video call fwd */
        case FORWARD_ALLCOND_VIDEO:
            switch (g_callset_context.SSCFCondQueryStage)
            {
                case CF_COND_STAGE_NONE:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_UNREACH;            
                    strcpy((S8*) string_out, "*#62**24#");
                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                case CF_COND_STAGE_UNREACH:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_NOANS;            
                    strcpy((S8*) string_out, "*#61**24#");
                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                case CF_COND_STAGE_NOANS:
                    g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_BUSY;            
                    strcpy((S8*) string_out, "*#67**24#");
                    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_out);
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    /* set protocol event handler for the call fwd response */
    SetProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    /* make a corresponding ss string for call fwd option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETForwardRsp
 * DESCRIPTION
 *  response handler for the call fwd query request.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETForwardRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 short_string[45], TempShortString[90];
    S8 TempBuff[250];
    S8 *TempBuff1;
    U8 bs_index;
    mmi_ss_call_forward_rsp_struct *pMsgFwdQueryrsp = (mmi_ss_call_forward_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NUMBER);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME);
    DeleteScreenIfPresent(SCR_ID_CALFWD_TO_OPTION);

    TempBuff1 = (S8*) OslMalloc(MAX_DISP_UCS2);
    memset(TempBuff1, 0, MAX_DISP_UCS2);                    

    if (pMsgFwdQueryrsp->result.flag == L4C_OK)
    {
        switch (pMsgFwdQueryrsp->type)
        {
            case L4_CFU:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFU));
                break;
            case L4_CFB:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFB));
                break;
            case L4_CFNRY:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFNRY));
                break;
            case L4_CFNRC:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFNRC));
                break;
            case L4_CFA:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFA));
                break;
            case L4_CFC:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_L4_CFC));
                break;
            default:
                mmi_ucs2cpy((PS8) TempBuff1, (PS8) GetString(STR_FWD_UNKNOWN_SERVICE));
                break;
        }
        if (pMsgFwdQueryrsp->count == 0)
        {
            mmi_ucs2cat((PS8) TempBuff1, (PS8) GetString(STR_DEACTIVATED));
        }
        for (bs_index = 0; bs_index < pMsgFwdQueryrsp->count; bs_index++)
        {
            memset(TempBuff, 0, sizeof(TempBuff));
            if (pMsgFwdQueryrsp->list[bs_index].ss_status & SS_ABIT)
            {
                mmi_ucs2cat((PS8) TempBuff, (PS8) GetString(STR_ACTIVATED));
            }
            else if (pMsgFwdQueryrsp->opcode == SS_OP_INTERROGATESS)
            {
                if (pMsgFwdQueryrsp->list[bs_index].ss_status & SS_PBIT)
                {
                    mmi_ucs2cat((PS8) TempBuff, (PS8) GetString(STR_DEACTIVATED));
                }
                else
                {
                    mmi_ucs2cat((PS8) TempBuff, (PS8) GetString(STR_NOT_PROVIDED));
                }
            }
            else
            {
                mmi_ucs2cat((PS8) TempBuff, (PS8) GetString(STR_DEACTIVATED));
            }

            if (pMsgFwdQueryrsp->list[bs_index].no_reply_timer != 0)
            {
                sprintf(short_string, "%d ", (U8) pMsgFwdQueryrsp->list[bs_index].no_reply_timer);
                mmi_asc_to_ucs2((PS8) TempShortString, (PS8) short_string);
                mmi_ucs2cat((S8*) TempBuff, (S8*) TempShortString);
                mmi_ucs2cat((PS8) TempBuff, (PS8) GetString(STR_SECONDS));
            }

            AppendBScodeString(pMsgFwdQueryrsp->list[bs_index].bs_code, TempBuff);
            mmi_ucs2cat((PS8) TempBuff, (PS8 )L" ");
            
            if (strlen(pMsgFwdQueryrsp->list[bs_index].address) != 0)
            {
                memset(short_string, 0, sizeof(short_string));
                memset(TempShortString, 0, sizeof(TempShortString));
                strncpy((PS8) short_string, (PS8) pMsgFwdQueryrsp->list[bs_index].address, sizeof(short_string) - 5);
                strcat((PS8) short_string, " ");
                mmi_asc_to_ucs2((PS8) TempShortString, (PS8) short_string);
                mmi_ucs2cat((S8*) TempBuff, (S8*) TempShortString);
            }

            if ((mmi_ucs2strlen((PS8) TempBuff) + mmi_ucs2strlen((PS8) TempBuff1))
                < MAX_DISP_UCS2 / ENCODING_LENGTH)
            {
                mmi_ucs2cat((S8*) TempBuff1, (S8*) TempBuff);
            }
        }

        sprintf(short_string, "\n");
        mmi_asc_to_ucs2((PS8) TempShortString, (PS8) short_string);
        mmi_ucs2cat((S8*) TempBuff1, (S8*) TempShortString);            

        switch (g_callset_context.SSCFCondQueryStage)
        {
            case CF_COND_STAGE_NONE:
                mmi_ucs2cpy((S8*) g_callset_context.SSDisplayBuffer, (S8*) TempBuff1);
                DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
                EntryCALLSETGeneralSSResut();
                break;
            case CF_COND_STAGE_UNREACH:
                mmi_ucs2cpy((S8*) g_callset_context.SSDisplayBuffer, (S8*) TempBuff1);
                g_callset_context.SSCFType = FORWARD_ALLCOND;
                EnterScrCallFwdQueryReq();
                break;
            case CF_COND_STAGE_NOANS:
                if ((mmi_ucs2strlen((PS8) TempBuff1) + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer))
                    < MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    mmi_ucs2cat((S8*) g_callset_context.SSDisplayBuffer, (S8*) TempBuff1);
                }
                g_callset_context.SSCFType = FORWARD_ALLCOND;
                EnterScrCallFwdQueryReq();
                break;
            case CF_COND_STAGE_BUSY:
                if ((mmi_ucs2strlen((PS8) TempBuff1) + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer))
                    < MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    mmi_ucs2cat((S8*) g_callset_context.SSDisplayBuffer, (S8*) TempBuff1);
                }
                g_callset_context.SSCFCondQueryStage = CF_COND_STAGE_NONE;
                DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
                EntryCALLSETGeneralSSResut();
                break;
            default:
                ASSERT(0);
                break;
        }
    }
    else
    {
        ResetCFCondStage();
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(pMsgFwdQueryrsp->result.cause, g_callset_context.SSDisplayBuffer);
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    OslMfree(TempBuff1);
}


/*****************************************************************************
 * FUNCTION
 *  ActivateVNoAnswer
 * DESCRIPTION
 *  Sending req for the call fwd when no answer case
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateVNoAnswer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];
    S8 string_code[50];
    PS8 hash_string = NULL;
    S8 uni_input_string[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format the string for the ss string handling */
    memset(input_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    memset(string_code, 0, 50);
    hash_string = (PS8) GetString(STR_HASH_VALUE);

    if (g_callset_context.SSCFType == FORWARD_NOANSWER ||
        g_callset_context.SSCFType == FORWARD_NOANSWER_VIDEO)
    {
        strcpy((S8*) string_code, "**61*");
    }
    else /* FORWARD_ALLCOND, FORWARD_ALLCOND_VIDEO */
    {
        strcpy((S8*) string_code, "**004*");
    }
    mmi_asc_to_ucs2((PS8) input_string, (PS8) string_code);
    mmi_ucs2cat((PS8) input_string, (PS8) g_callset_context.SSCFNum);
    
#ifdef __MMI_VIDEO_TELEPHONY__
    if (g_callset_context.SSCFType == FORWARD_NOANSWER ||
        g_callset_context.SSCFType == FORWARD_ALLCOND)
    {
        if(g_callset_context.LineID == LINE1)
		{
			strcpy((S8*) string_code, "*11*");
		}
		else if(g_callset_context.LineID == LINE2)
		{
			strcpy((S8*) string_code, "*89*");
		}
    }
    else /* FORWARD_NOANSWER_VIDEO, FORWARD_ALLCOND_VIDEO */
    {
        strcpy((S8*) string_code, "*24*");
    }
#else /* __MMI_VIDEO_TELEPHONY__ */
    strcpy((PS8) string_code, "**");
#endif /* __MMI_VIDEO_TELEPHONY__ */

    mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
    mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);

    sprintf((PS8) string_code, "%d", 5 * (g_callset_context.SSCFNoAnsTimeIndex + 1));
    mmi_asc_to_ucs2((PS8) uni_input_string, (PS8) string_code);
    mmi_ucs2cat((PS8) input_string, (PS8) uni_input_string);
    mmi_ucs2cat((PS8) input_string, (PS8) hash_string);
    /* set protocol event handler for the call fwd response */
    SetProtocolEventHandler(CALLSETForwardRsp, PRT_MMI_SS_CALL_FORWARD_RSP);
    /* make a corresponding ss string for call fwd option */
    MakeCall((PS8) input_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrHandler
 * DESCRIPTION
 *  Getting Current highlighted item
 * NA
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetCurrHandler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.SSCFNoAnsTimeIndex = (U8) item_index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETForwardNoAnsTime
 * DESCRIPTION
 *  entry function for no answer
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETForwardNoAnsTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME, NULL, EntryCALLSETForwardNoAnsTime, NULL);

    /* Get current screen info into gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU8239_CALFWD_VOICECALL_NOANSWER_OPTIONS);
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU8239_CALFWD_VOICECALL_NOANSWER_OPTIONS, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU8239_CALFWD_VOICECALL_NOANSWER_OPTIONS);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(GetCurrHandler);
    /* display the corresponding screen */
    ShowCategory15Screen(
        SCR_CALL_FWD_ENTER_NO_ANSWER_TIME_CAP,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ActivateVNoAnswer, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SendPhbEntryForDivert
 * DESCRIPTION
 *  send phone number for diverting to the number
 * NA
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SendPhbEntryForDivert(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.SSCFNumFromPHB = TRUE;
    mmi_ucs2cpy((PS8) g_callset_context.SSCFNum, (PS8) number);
    GoBackToHistory(SCR_ID_CALLSET_FORWARD_NUMBER);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  CallForwardScreenEmpty
 * DESCRIPTION
 *  register function when screen is empty for call forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallForwardScreenEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
}

/*****************************************************************************
 * FUNCTION
 *  CallForwardScreenNotEmpty
 * DESCRIPTION
 *  register function when screen is empty for call forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallForwardScreenNotEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
}