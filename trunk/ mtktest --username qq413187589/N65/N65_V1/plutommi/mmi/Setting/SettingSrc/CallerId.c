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
 * CallerId.c
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

   FILENAME : CallerId.c


   PURPOSE     : Caller id application of call setup

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
#include "MMI_include.h"
#include "MainMenuDef.h"
#include "CallSetUp.h"
#include "PhoneBookTypes.h"
#include "protocolEvents.h"
#include "CSP.h"
#include "CallSetUpEnum.h"
#include "SettingGprots.h"
#include "CallerIdGprot.h"
#include "CommonScreens.h"
#include "CallmanagementIdDef.h"
/* micha0915 */
#include "CallManagementGProt.h"
#include "MessagesExDcl.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_slave_header.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */
/*****************************************************************************
 * FUNCTION
 *  InitCallerId
 * DESCRIPTION
 *  initialization function of the caller id application.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallerId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CALLER_ID, HighlightCALLSETCallerId);
    SetHiliteHandler(MENU_CID_SET_NWK, HiliteSetByNwk);
    SetHiliteHandler(MENU_CID_SHOW_ID, HiliteShowCid);
    SetHiliteHandler(MENU_CID_HIDE_ID, HiliteHideCid);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitNvramCallerId
 * DESCRIPTION
 *  Initialize NVRAM for callerid
 * NA
 *  
 * PARAMETERS
 *  void
 *  S16(?)      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
S16 InitNvramCallerId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read the current caller id value from nv ram */
    ReadValue(NVRAM_CALLERID, &g_callset_context.CallerIDInput, DS_BYTE, &error);
    /* if failure in read. set the default value */
    if (g_callset_context.CallerIDInput == 0xff)
    {
        g_callset_context.CallerIDInput = 2;
    }
    /* set the caller id value to L4 */

#ifdef __MMI_DUAL_SIM_MASTER__
    {
        E_MTPNP_LOCAL_NUMBER_STATUS status = MTPNP_LOCAL_NUMBER_SEND;

        switch (g_callset_context.CallerIDInput)
        {
            case CLIR_INVOKE:
                status = MTPNP_LOCAL_NUMBER_HIDE;
                break;
            case CLIR_SUPPRESS:
                status = MTPNP_LOCAL_NUMBER_SEND;
                break;
            case CLIR_AUTO:
                status = MTPNP_LOCAL_NUMBER_DETERMINED_BY_NETWORK;
                break;
            default:
                break;
        }

        MTPNP_PFAL_Update_Clir(g_callset_context.CallerIDInput);
        MTPNP_AD_Report_CallID_Status(status);
    }

#endif	/* __MMI_DUAL_SIM_MASTER__ */
    SetCallerIdReq();
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HiliteSetByNwk
 * DESCRIPTION
 *  hilite handler for set by network sub menu item
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteSetByNwk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.CallerIDInput = CLIR_AUTO;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(SetCallerIdReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallerId
 * DESCRIPTION
 *  hilite handler for the caller id option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallerId(void)
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
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EnterCALLSETCallerIDMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EnterCALLSETCallerIDMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HiliteShowCid
 * DESCRIPTION
 *  hilite handler for the show caller id.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteShowCid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.CallerIDInput = CLIR_SUPPRESS;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(SetCallerIdReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHideCid
 * DESCRIPTION
 *  hilite handler for the hide id.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHideCid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storing the menu item selected */
    g_callset_context.CallerIDInput = CLIR_INVOKE;
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(SetCallerIdReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EnterCALLSETCallerIDMain
 * DESCRIPTION
 *  Entry screen for the caller id menu items.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterCALLSETCallerIDMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;

    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */

    EntryNewScreen(SCR_ID_CALLSET_CALLER_ID_MAIN, NULL, EnterCALLSETCallerIDMain, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_CALLER_ID_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MENU_CALLER_ID);         /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_CALLER_ID); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_CALLER_ID, nStrItemList); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MENU_CALLER_ID);
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
#endif /* 0 */ 

    /* Display Category1 Screen */
    ShowCategory15Screen(
        STR_MENU_CALLER_ID,
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
        (g_callset_context.CallerID + 1) % 3,
        guiBuffer);
    /* Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetCallerIdReq
 * DESCRIPTION
 *  Sends caller id request to stack
 * PARAMETERS
 *  void
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void SetCallerIdReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_ss_set_clir_flag_req_struct *pMsgReq = NULL;

    static U8 firstTime = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (firstTime)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    firstTime = 1;

    PRINT_INFORMATION("*** In MakePsSendClir *** \n");
    pMsgReq = (mmi_ss_set_clir_flag_req_struct*) OslConstructDataPtr(sizeof(mmi_ss_set_clir_flag_req_struct));
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    pMsgReq->clir_flag = g_callset_context.CallerIDInput;
    SetProtocolEventHandler(CALLSETCallerIDRsp, PRT_MMI_SS_SET_CLIR_FLAG_RSP);
    Message.oslMsgId = PRT_MMI_SS_SET_CLIR_FLAG_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETCallerIDRsp
 * DESCRIPTION
 *  response handler for the set caller id request
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETCallerIDRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_set_clir_flag_rsp_struct *localPtr = NULL;
    static U8 firstTime = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In PsCBackClirSet *** \n");
    localPtr = (mmi_ss_set_clir_flag_rsp_struct*) info;
    if (localPtr->result == 1)
    {
        g_callset_context.CallerID = g_callset_context.CallerIDInput;
        if (firstTime)
        {
            if (WriteValue(NVRAM_CALLERID, &g_callset_context.CallerIDInput, DS_BYTE, &error) < DS_BYTE)
            {
                PRINT_INFORMATION("## ERROR: write caler id : WriteRecord " "to NVRAM failed (%d)\n", (int)error);
                return;
            }
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
            DeleteScreenIfPresent(SCR_ID_CALLSET_CALLER_ID_MAIN);
        }
    }
    else
    {
        if (firstTime)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_CALLSET_CALLER_ID_MAIN);
        }
    }
    firstTime = 1;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETClipRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETClipRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_clip_interrogate_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    local = (mmi_ss_clip_interrogate_ind_struct*) info;
    if (local->result.flag == L4C_OK)
    {
        if (local->status & SS_PBIT)
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CLIP_STATUS_ACT_TXT));
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CLIP_STATUS_NACT_TXT));

        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETClirRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETClirRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_clir_interrogate_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    local = (mmi_ss_clir_interrogate_ind_struct*) info;

    if (local->result.flag == L4C_OK)
    {
        if (local->status & SS_PBIT)
        {
            switch (local->clir_option)
            {
                case 0: /* permanently hide */
                    mmi_ucs2cpy(
                        (PS8) g_callset_context.SSDisplayBuffer,
                        (PS8) GetString(STR_CLIR_STATUS_ACT_PERMANENTLY_TXT));
                    break;
                case 1: /* temporary default restrict(hide) */
                    mmi_ucs2cpy(
                        (PS8) g_callset_context.SSDisplayBuffer,
                        (PS8) GetString(STR_CLIR_STATUS_ACT_DEFAULT_RESTRICT_TXT));
                    break;
                case 2: /* temporary default allow(show) */
                    mmi_ucs2cpy(
                        (PS8) g_callset_context.SSDisplayBuffer,
                        (PS8) GetString(STR_CLIR_STATUS_ACT_DEFAULT_ALLOW_TXT));
                    break;
                default:
                    mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CLIR_STATUS_ACT_TXT));
                    break;
            }
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CLIR_STATUS_NACT_TXT));
        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETColpRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETColpRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_colp_interrogate_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    local = (mmi_ss_colp_interrogate_ind_struct*) info;
    if (local->result.flag == L4C_OK)
    {
        if (local->status & SS_PBIT)
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_COLP_STATUS_ACT_TXT));
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_COLP_STATUS_NACT_TXT));

        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }
    
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETColrRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETColrRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_colr_interrogate_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    local = (mmi_ss_colr_interrogate_ind_struct*) info;
    if (local->result.flag == L4C_OK)
    {
        if (local->status & SS_PBIT)
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_COLR_STATUS_ACT_TXT));
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_COLR_STATUS_NACT_TXT));

        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETCnapRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETCnapRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_cnap_interrogate_ind_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    local = (mmi_ss_cnap_interrogate_ind_struct*) info;

    if (local->result.flag == L4C_OK)
    {
        if (local->status & SS_PBIT)
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CNAP_STATUS_ACT_TXT));
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CNAP_STATUS_NACT_TXT));
        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETCcbsQueryRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETCcbsQueryRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_ccbs_rsp_struct *local;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    local = (mmi_ss_ccbs_rsp_struct*) info;

    if (local->opcode == SS_OP_ERASECCENTRY)
    {
        if (local->result.flag == L4C_OK)
        {
            mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CCBS_STATUS_TITLE));
            mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEACTIVATED));
            DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
            EntryCALLSETGeneralSSResut();
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            RemoveSSReqScr();
        }
        return;
    }

    if (local->result.flag == L4C_OK)
    {
        if (local->list.ss_status & SS_PBIT)
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CCBS_STATUS_ACT_TXT));
        }
        else
        {
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_CCBS_STATUS_NACT_TXT));
        }
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }
    
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

}

/* micha1228 */


/*****************************************************************************
 * FUNCTION
 *  CALLSETEmlppQueryRsp
 * DESCRIPTION
 *  
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETEmlppQueryRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_emlpp_rsp_struct *local;
    S8 TempBuff[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    memset(TempBuff, 0, sizeof(TempBuff));
    local = (mmi_ss_emlpp_rsp_struct*) info;

    if (local->result.flag == L4C_OK)
    {

        sprintf(TempBuff, "Default: %d\nMax: %d", local->default_pri, local->max_pri);

        mmi_asc_to_ucs2((PS8) g_callset_context.SSDisplayBuffer, (PS8) TempBuff);
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(local->result.cause, g_callset_context.SSDisplayBuffer);
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

