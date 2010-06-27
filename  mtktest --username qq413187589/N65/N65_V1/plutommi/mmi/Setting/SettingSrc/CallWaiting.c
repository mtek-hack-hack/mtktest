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
 * CallWaiting.c
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

   FILENAME : CallWaiting.c


   PURPOSE     : Call waiting application in call setup.

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 11/14/2003

**************************************************************/
#include "MMI_include.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "CallSetUp.h"
#include "SettingProfile.h"
#include "CallWaiting.h"
#include "CallSetUpEnum.h"
#include "CommonScreens.h"
#include "CallmanagementIdDef.h"
#include "CallManagementGprot.h"


/*****************************************************************************
 * FUNCTION
 *  InitCallWaiting
 * DESCRIPTION
 *  Initializes the call waiting application
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallWaiting()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set hilite handlers for the individual menu items */
    SetHiliteHandler(MENU8237_SCR8093_MNGCALL_MENU_WAIT, HighlightCALLSETCallWaiting);
    SetHiliteHandler(MENU8237_MNGCALL_CALWAIT_MENU_ON, HighlightCALLSETCallWaitingOn);
    SetHiliteHandler(MENU8237_MNGCALL_CALWAIT_MENU_OFF, HighlightCALLSETCallWaitingOff);
    SetHiliteHandler(MENU8237_MNGCALL_CALWAIT_MENU_QUERY, HighlightCALLSETCallWaitingQuery);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallWaiting
 * DESCRIPTION
 *  highlite handler for call waiting options
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallWaiting()
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
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryCALLSETWaitingMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryCALLSETWaitingMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallWaitingOn
 * DESCRIPTION
 *  highlite handler for callwaiting on option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallWaitingOn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryScrCallWaitingOnreq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallWaitingOff
 * DESCRIPTION
 *  highlight handler for call waiting off option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallWaitingOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryScrCallWaitingOffreq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallWaitingQuery
 * DESCRIPTION
 *  highlight handler for call waiting query status option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallWaitingQuery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the left/right soft key functions handlers */
    SetLeftSoftkeyFunction(EntryScrCallWaitingQueryreq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCallWaitingOnreq
 * DESCRIPTION
 *  function for call waiting on req.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCallWaitingOnreq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD];
    S8 uniinput_string[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format the ss string for the call waiting on req */
    memset(input_string, 0, MAX_DIGITS_USSD);
    strcpy((S8*) input_string, "*43#");
    memset(uniinput_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    mmi_asc_to_ucs2((PS8) uniinput_string, (PS8) input_string);
    /* make a corresponding ss string for call waiting option */
    MakeCall((PS8) uniinput_string);
    /* delete screens for maitaining hte history */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETWaitingMain
 * DESCRIPTION
 *  entry function for the call waiting menu option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETWaitingMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_WAITING_MAIN, NULL, EntryCALLSETWaitingMain, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_WAITING_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU8237_SCR8093_MNGCALL_MENU_WAIT);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8237_SCR8093_MNGCALL_MENU_WAIT); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU8237_SCR8093_MNGCALL_MENU_WAIT, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU8237_SCR8093_MNGCALL_MENU_WAIT);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* Display Category15 Screen */
    ShowCategory15Screen(
        STR_SCR8094_MNGCALL_CALWAIT_MENU_CAPTION,
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
 *  EntryScrCallWaitingOffreq
 * DESCRIPTION
 *  function for call waiting on req.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCallWaitingOffreq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD];
    S8 uniinput_string[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format ss string for call waiting off req */
    memset(input_string, 0, MAX_DIGITS_USSD);
    strcpy((S8*) input_string, "#43#");

    memset(uniinput_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    mmi_asc_to_ucs2((PS8) uniinput_string, (PS8) input_string);
    /* make a corresponding ss string for call waiting option */
    MakeCall((PS8) uniinput_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrCallWaitingQueryreq
 * DESCRIPTION
 *  function for call waiting on req.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrCallWaitingQueryreq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 input_string[MAX_DIGITS_USSD];
    S8 uniinput_string[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* format ss string for call waiting query req */
    memset(input_string, 0, MAX_DIGITS_USSD);
    strcpy((S8*) input_string, "*#43#");
    SetProtocolEventHandler(CALLSETWaitingRsp, PRT_MMI_SS_CALL_WAIT_RSP);
    memset(uniinput_string, 0, (MAX_DIGITS_USSD * ENCODING_LENGTH));
    mmi_asc_to_ucs2((PS8) uniinput_string, (PS8) input_string);
    /* make a corresponding ss string for call waiting option */
    MakeCall((PS8) uniinput_string);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETWaitingRsp
 * DESCRIPTION
 *  response handler for call waiting query response
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETWaitingRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bs_index;

    mmi_ss_call_wait_rsp_struct *pMsgCallWaitRsp = (mmi_ss_call_wait_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    DeleteScreenIfPresent(SCR_ID_CALLSET_WAITING_MAIN);

    /* check the status of the response result */
    if (pMsgCallWaitRsp->result.flag == L4C_OK)
    {
        /* if the response is success check the type */
        /* format the result string */
        if (pMsgCallWaitRsp->status & SS_ABIT)
        {
            /* format the result string with active/deactive tags. */
            mmi_ucs2cpy((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
            mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_ACTIVATED));
            for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
            {
                if ((mmi_ucs2strlen((PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                     + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer)) < MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    AppendBScodeString(pMsgCallWaitRsp->list[bs_index], (PS8) g_callset_context.SSDisplayBuffer);
                }
            }
        }
        else if (pMsgCallWaitRsp->opcode == SS_OP_INTERROGATESS)
        {
            if (pMsgCallWaitRsp->status & SS_PBIT)
            {
                /* format the result string with active/deactive tags. */
                mmi_ucs2cpy(
                    (S8*) g_callset_context.SSDisplayBuffer,
                    (PS8) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
                mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEACTIVATED));
                for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
                {
                    if ((mmi_ucs2strlen((PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                         + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer)) < MAX_DISP_UCS2 / ENCODING_LENGTH)
                    {
                        AppendBScodeString(pMsgCallWaitRsp->list[bs_index], (PS8) g_callset_context.SSDisplayBuffer);
                    }
                }
            }
            else
            {
                mmi_ucs2cpy(
                    (S8*) g_callset_context.SSDisplayBuffer,
                    (PS8) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
                mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_NOT_PROVIDED));
                for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
                {
                    if ((mmi_ucs2strlen((PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                         + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer)) < MAX_DISP_UCS2 / ENCODING_LENGTH)
                    {
                        AppendBScodeString(pMsgCallWaitRsp->list[bs_index], (PS8) g_callset_context.SSDisplayBuffer);
                    }
                }
            }
        }
        else
        {
            mmi_ucs2cpy(
                (S8*) g_callset_context.SSDisplayBuffer,
                (PS8) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
            mmi_ucs2cat((PS8) g_callset_context.SSDisplayBuffer, (PS8) GetString(STR_DEACTIVATED));
            for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
            {
                if ((mmi_ucs2strlen((PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                     + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer)) < MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    AppendBScodeString(pMsgCallWaitRsp->list[bs_index], (PS8) g_callset_context.SSDisplayBuffer);
                }
            }
        }
        /* call the result screen function to display the result string */
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    }
    else
    {
        /* in case of response failure */
    #ifdef __MMI_SS_SHOW_CAUSE__
        ShowCauseString(pMsgCallWaitRsp->result.cause, (PS8) g_callset_context.SSDisplayBuffer);
        /* micha0322 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        EntryCALLSETGeneralSSResut();
    #else /* __MMI_SS_SHOW_CAUSE__ */ 
        /* display the not done popup */
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        /* micha0915 */
        RemoveSSReqScr();
    #endif /* __MMI_SS_SHOW_CAUSE__ */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_gsm_set_slave_ss_falg(FALSE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    return;
}

