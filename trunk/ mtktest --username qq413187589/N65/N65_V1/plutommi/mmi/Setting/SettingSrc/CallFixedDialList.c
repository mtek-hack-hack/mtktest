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
 * CallFixedDialList.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Fixed Dial List functions
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
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CallFixedDialList.c

   PURPOSE     : Call Setting Application

   REMARKS     : nil

   AUTHOR      : Deepali Gupta, Vanita Jain 

   DATE     : 

**************************************************************/

#include "MMI_include.h"
#include "MainMenuDef.h"
#include "ProtocolEvents.h"
#include "PhoneBookDef.h"
#include "SettingGprots.h"
#include "CallFixedDial.h"
#include "CommonScreens.h"
#include "CallManagementGprot.h"
#include "PhoneBookGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SettingDefs.h"
#include "SettingsGexdcl.h"
#include "SettingsGdcl.h"
#include "SecuritySetup.h"
#include "ProfileGprots.h"
#include "SimDetectionDef.h"
#include "SimDetectionGProt.h"
#include "PhoneBookProt.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

FDLBDLContext gFDLBDLContext;


/*****************************************************************************
 * FUNCTION
 *  InitFixedDialList
 * DESCRIPTION
 *  Initialize FDL.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitFixedDialList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU8234_FDL_VIEW_OPTIONS_ADD, HighlightAddFDL);
    SetHiliteHandler(MENU8234_FDL_VIEW_OPTIONS_EDIT, HighlightEditFDL);
    SetHiliteHandler(MENU8234_FDL_VIEW_OPTIONS_DELETE, HighlightDeleteFDL);

    gFDLBDLContext.FDNBDNCount = 0;
    gFDLBDLContext.FDNBDNEdit = 0;
    gFDLBDLContext.HighlightedFDN = 255;
    gFDLBDLContext.is_set_toggle = 0;
    gFDLBDLContext.small_screen = 0;
    gFDLBDLContext.is_fdn = 1;
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlEntriesReq
 * DESCRIPTION
 *  Getting all entries req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlEntriesReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pMsgIndexReq =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    pMsgIndexReq->index = gFDLBDLContext.FDNBDNCount + 1;
    pMsgIndexReq->record_index = 0xFFFF;
    pMsgIndexReq->storage = MMI_SIM;
    pMsgIndexReq->type = MMI_PHB_FDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(SECSETGetFdlEntriesRsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetFdlEntriesRsp
 * DESCRIPTION
 *  Getting all entries rsp
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetFdlEntriesRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U8 i = 0, j = 0;

    U8 TempBuff[(MAX_PB_NUMBER_LENGTH + 2) * ENCODING_LENGTH];
    U8 *tmpConvertBuf = NULL;
    U16 convertOutLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        i = gFDLBDLContext.FDNBDNCount;
        gFDLBDLContext.FDNBDNCount += localPtr->no_list;    /* Add number of new entries in current list length. */

        if (gFDLBDLContext.FDNBDNCount > MAX_SIM_ENTRIES)
        {
            gFDLBDLContext.FDNBDNCount = MAX_SIM_ENTRIES;
        }

        for (; i < gFDLBDLContext.FDNBDNCount; i++, j++)
        {
            gFDLBDLContext.FDLBDLEntries[i].storage = localPtr->list[j].storage;
            gFDLBDLContext.FDLBDLEntries[i].index = localPtr->list[j].index;
            gFDLBDLContext.FDLBDLEntries[i].record_index = localPtr->list[j].record_index;

            memset(gFDLBDLContext.FDLBDLEntries[i].alpha_id.name, 0, MAX_NAME_LEN_FSB_LIST * ENCODING_LENGTH);
            memset(gFDLBDLContext.FDLBDLEntries[i].tel.number, 0, MAX_NUMBER_LEN_FSB_LIST * ENCODING_LENGTH);
            gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_length = localPtr->list[j].alpha_id.name_length;
            gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_dcs = localPtr->list[j].alpha_id.name_dcs;
            tmpConvertBuf = CovertStringForPlatform(
                                localPtr->list[j].alpha_id.name,
                                gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_length,
                                gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_dcs,
                                &convertOutLen);
            gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_length = (U8) convertOutLen;

            if (GetUCS2Flag((PS8) tmpConvertBuf))
            {
                if (mmi_ucs2strlen((PS8) tmpConvertBuf) < MAX_PB_NAME_LENGTH / 2)
                {
                    mmi_ucs2cpy((PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name, (PS8) tmpConvertBuf);
                }
                else
                {
                    mmi_ucs2ncpy(
                        (PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name,
                        (PS8) tmpConvertBuf,
                        MAX_PB_NAME_LENGTH / 2 - 1);
                    gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_length = MAX_PB_NAME_LENGTH - 2;
                }
            }
            else
            {
                if (mmi_ucs2strlen((PS8) tmpConvertBuf) < MAX_PB_NAME_LENGTH)
                {
                    mmi_ucs2cpy((PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name, (PS8) tmpConvertBuf);
                }
                else
                {
                    mmi_ucs2ncpy(
                        (PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name,
                        (PS8) tmpConvertBuf,
                        MAX_PB_NAME_LENGTH);
                    gFDLBDLContext.FDLBDLEntries[i].alpha_id.name_length = 2 * MAX_PB_NAME_LENGTH;
                }
            }

            if (tmpConvertBuf != NULL)
            {
                OslMfree(tmpConvertBuf);
            }

            if (((localPtr->list[j].tel.type & 0x90) == 0x90) && (localPtr->list[j].tel.type != 0xFF))
            {
                gFDLBDLContext.FDLBDLEntries[i].tel.type = localPtr->list[j].tel.type;
                gFDLBDLContext.FDLBDLEntries[i].tel.number[0] = '+';    /* insert '+' before the number. */
                gFDLBDLContext.FDLBDLEntries[i].tel.length = localPtr->list[j].tel.length;
                mmi_asc_to_ucs2((PS8) TempBuff, (PS8) localPtr->list[j].tel.number);
                memcpy(
                    gFDLBDLContext.FDLBDLEntries[i].tel.number + ENCODING_LENGTH,
                    TempBuff,
                    (localPtr->list[j].tel.length) * ENCODING_LENGTH);
            }
            else
            {
                gFDLBDLContext.FDLBDLEntries[i].tel.type = localPtr->list[j].tel.type;
                gFDLBDLContext.FDLBDLEntries[i].tel.length = localPtr->list[j].tel.length;
                mmi_asc_to_ucs2((PS8) TempBuff, (PS8) localPtr->list[j].tel.number);
                memcpy(
                    gFDLBDLContext.FDLBDLEntries[i].tel.number,
                    (PS8) TempBuff,
                    (localPtr->list[j].tel.length) * ENCODING_LENGTH);
            }
        }
        if (localPtr->no_list == MAX_ENTRIES_IN_LIST)
        {
            SECSETGetFdlEntriesReq();
        }
        else
        {
            ViewFDList();

            /*
             *    Retrieve FDN list to ADN buffer when FDN is enable.
             *    Because ADN will not read when FDN is on, so use ADN's buffer to store FDN temporarily
             *    This is for call lookup FDN number usage.
             */
            if (gSecuritySetupContext.FdlStatus)
            {
                mmi_phb_fdn_get_list_to_ram();
            }
        }
    }
    else if (localPtr->result.flag == 1 && localPtr->result.cause == 5)
    {
        /* gFDLBDLContext.FDNBDNCount = 0; */
        ViewFDList();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_SECSET_FIX_DIAL);
    }
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  ViewFDList
 * DESCRIPTION
 *  View FDL List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ViewFDList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.HighlightedFDN = 0;

    if (mmi_secset_is_call_interrupt())
    {
        extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
        mmi_frm_add_history_before_cm_marker(SCR_ID_SECSET_FDN_LIST, EntrySECSETFDNList);
    }
    else
    {
        EntrySECSETFDNList();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETFDNList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETFDNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        ResetCenterSoftkey();
    }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNList
 * DESCRIPTION
 *  Entry screen to view FDl list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pstfdlist[MAX_SIM_ENTRIES], *fdlHint[MAX_SIM_ENTRIES];
    U16 index;
    U8 *guiBuffer;
    U16 fdlimagelist[MAX_SIM_ENTRIES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FDN_LIST, ExitSECSETFDNList, EntrySECSETFDNList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_FDN_LIST);   /* Getting the Index from history */

    for (index = 0; index < gFDLBDLContext.FDNBDNCount; index++)
    {
        if (gFDLBDLContext.FDLBDLEntries[index].alpha_id.name[0] != '\0')
        {
            pstfdlist[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].alpha_id.name;
            fdlHint[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].tel.number;
        }
        else
        {
            pstfdlist[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].tel.number;
            fdlHint[index] = NULL;
        }
        fdlimagelist[index] = IMG_STORAGE_SIM;
    }

    RegisterHighlightHandler(GetActiveIndex);

    if (guiBuffer != NULL)
    {
        memset((void*)guiBuffer, 0, 2);
    }

    if ((gFDLBDLContext.HighlightedFDN >= gFDLBDLContext.FDNBDNCount) && (gFDLBDLContext.FDNBDNCount > 0))
    {
        gFDLBDLContext.HighlightedFDN = gFDLBDLContext.FDNBDNCount - 1;
    }

    if (gFDLBDLContext.FDNBDNCount == 0)
    {
        pstfdlist[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        fdlimagelist[0] = 0;
        fdlHint[0] = NULL;
        ShowCategory6Screen(
            STR_SCR8054_CALL_FDL_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            pstfdlist,
            NULL,
            0,
            guiBuffer);
        gFDLBDLContext.FDNBDNEdit = FALSE;
        memset(gFDLBDLContext.FDLBDLName, 0, (MAX_NAME_LEN_FSB_LIST + 1) * ENCODING_LENGTH);
        memset(gFDLBDLContext.FDLBDLNumber, 0, (MAX_NUMBER_LEN_FSB_LIST + 1 + 1) * ENCODING_LENGTH);
        SetLeftSoftkeyFunction(EntrySECSETFDNDetails, KEY_EVENT_UP);
        SetKeyHandler(EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_SEND, KEY_EVENT_UP);
    }
    else
    {
    #if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
        if (mmi_bootup_get_active_flight_mode() == 0)
        {
            EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
        }
    #endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

        ShowCategory53Screen(
            STR_SCR8054_CALL_FDL_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gFDLBDLContext.FDNBDNCount,
            pstfdlist,
            fdlimagelist,
            fdlHint,
            0,
            gFDLBDLContext.HighlightedFDN,
            guiBuffer);

        SetLeftSoftkeyFunction(EntrySECSETFDNOption, KEY_EVENT_UP);
        SetKeyHandler(EntrySECSETFDNOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        if (mmi_bootup_get_active_flight_mode() == 0)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_PFAL_CC_HandleSendKeys(FdlMakeCall, KEY_EVENT_UP);
        #else /* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(FdlMakeCall, KEY_SEND, KEY_EVENT_UP);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_PFAL_CC_SetCenterFunc(FdlMakeCall);
            SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
        #else /* __MMI_DUAL_SIM_MASTER__ */
            SetCenterSoftkeyFunction(FdlMakeCall, KEY_EVENT_UP);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
        }
        else
        {
            SetKeyHandler(0, KEY_SEND, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETFDNListReload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETFDNListReload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_SECSET_FDN_LIST))
    {
        HistoryReplace(SCR_ID_SECSET_FDN_LIST, SCR_ID_SECSET_FDN_LIST, EntryFdlList);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNOption
 * DESCRIPTION
 *  Entry screen of FDL list Options, when list is not empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FDN_OPTION, NULL, EntrySECSETFDNOption, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_FDN_OPTION);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU8234_FDL_VIEW_OPTIONS_MAIN);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU8234_FDL_VIEW_OPTIONS_MAIN, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU8234_FDL_VIEW_OPTIONS_MAIN);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category15 Screen */
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

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAddFDL
 * DESCRIPTION
 *  Add option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAddFDL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySECSETFDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gFDLBDLContext.FDNBDNEdit = FALSE;
    memset(gFDLBDLContext.FDLBDLName, 0, (MAX_NAME_LEN_FSB_LIST + 1) * ENCODING_LENGTH);
    memset(gFDLBDLContext.FDLBDLNumber, 0, (MAX_NUMBER_LEN_FSB_LIST + 1 + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNDetails
 * DESCRIPTION
 *  Entry screen to add FDL entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNDetails(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem; /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 ItemIcons[2];
    U8 *inputBuffer;            /* added for inline edit history */
    U16 inputBufferSize;        /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gFDLBDLContext.FDNBDNCount == (U16) gFDLBDLContext.MaxFDL || gFDLBDLContext.FDNBDNCount == MAX_SIM_ENTRIES) &&
        (gFDLBDLContext.FDNBDNEdit == FALSE))
    {
        DisplayPopup(
            (U8*) GetString(STR_SETTING_STORAGE_FULL),
            IMG_GLOBAL_WARNING,
            0,
            ST_NOTIFYDURATION,
            (U8) WARNING_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_SECSET_FDN_DETAILS, ExitSECSETFDNDetails, NULL, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_FDN_DETAILS);
        inputBuffer = GetCurrNInputBuffer(SCR_ID_SECSET_FDN_DETAILS, &inputBufferSize); /* added for inline edit history */

        nNumofItem = GetNumOfChild(MENU8234_FDL_VIEW_OPTIONS_ADD);

        GetSequenceImageIds(MENU8234_FDL_VIEW_OPTIONS_ADD, ItemIcons);

        InitializeCategory57Screen();

        FillFdlInlineEditStruct();

        if (inputBuffer != NULL)    /* added for inline edit history */
        {
            SetCategory57Data(gFDLBDLContext.FDLBDLInlineDisplay, nNumofItem, inputBuffer);     /* sets the data */
        }

        RegisterHighlightHandler(GetEntryTitle);

        ShowCategory57Screen(
            STR_SETTING_FDL_EDIT_ENTRY,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_EDIT,
            IMG_GLOBAL_OK,
            STR_DONE,
            IMG_GLOBAL_BACK,
            nNumofItem,
            ItemIcons,
            gFDLBDLContext.FDLBDLInlineDisplay,
            0,
            guiBuffer);

        SetCategory57RightSoftkeyFunctions(EntrySECSETFDNSaveConfirm, GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETFDNDetails
 * DESCRIPTION
 *  Exit fn for FDL add screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETFDNDetails(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SECSET_FDN_DETAILS;
    Scr.entryFuncPtr = EntrySECSETFDNDetails;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    size = (U16) GetCategory57DataSize();       /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);   /* added for inline edit history */
    AddNHistory(Scr, size);
}


/*****************************************************************************
 * FUNCTION
 *  FillFdlInlineEditStruct
 * DESCRIPTION
 *  Fill Inline Edit structs.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillFdlInlineEditStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&gFDLBDLContext.FDLBDLInlineDisplay[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &gFDLBDLContext.FDLBDLInlineDisplay[0],
        STR_SETTING_FDL_NAME,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        (PU8) gFDLBDLContext.FDLBDLName,
        /* g_phb_cntx.fdn_name_len + 1, */
        ((g_phb_cntx.fdn_name_len > MAX_PB_NAME_LENGTH) ? (MAX_PB_NAME_LENGTH + 1) : (g_phb_cntx.fdn_name_len + 1)),
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&gFDLBDLContext.FDLBDLInlineDisplay[0], SettingInlineCustomFunction);
    SetInlineItemActivation(&gFDLBDLContext.FDLBDLInlineDisplay[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &gFDLBDLContext.FDLBDLInlineDisplay[1],
        (PU8) gFDLBDLContext.FDLBDLNumber,
        MAX_PB_NUMBER_LENGTH + 1,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&gFDLBDLContext.FDLBDLInlineDisplay[1]);
}


/*****************************************************************************
 * FUNCTION
 *  PreNewFdlEntryReq
 * DESCRIPTION
 *  Goto Confirm Save screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreNewFdlEntryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLNumber) && !mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLName))
    {
        GoBackHistory();
    }
    else
    {
        EntrySECSETFDNSaveConfirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNSaveConfirm
 * DESCRIPTION
 *  Show confirm Save Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNSaveConfirm(void)
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
        get_string(STR_ID_SECSET_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETSetFdlEntryReq;
    SetLeftSoftkeyFunction(PreSaveFdlBdlEntryReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToFDLList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetFdlEntryReq
 * DESCRIPTION
 *  Req to L4 to add new Entry in FDL.
 *  
 *  First Send req to verify Pin2, After PIN2 Verified,
 *  call this Fn to add new FDL entry in L4.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetFdlEntryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *pMsgNewEntry = NULL;
    MYQUEUE Message;

    /* U8 pbName_ASCII[MAX_PB_NAME_LENGTH]; */
    U8 pbNumber_ASCII[MAX_PB_NUMBER_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_fdn = 1;
    EntrySECSETFDNBDNSaving();
    pMsgNewEntry = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    /* diamond, 2005/07/22 memset length issue */
    //memset(pMsgNewEntry->list.alpha_id.name, 0, strlen((PS8)pbName_ASCII)+1);
    //memset(pMsgNewEntry->list.tel.number, 0, strlen((PS8)pbNumber_ASCII)+1);
    memset(pMsgNewEntry->list.alpha_id.name, 0, MAX_PB_NAME_LENGTH + 1);
    memset(pMsgNewEntry->list.tel.number, 0, MAX_PB_NAME_LENGTH + 1);
    /* end, diamond */

    pMsgNewEntry->type = MMI_PHB_FDN;
    pMsgNewEntry->no_data = 1;
    pMsgNewEntry->list.storage = MMI_SIM;
    pMsgNewEntry->list.index = 0xFFFF;          /* For New Entry It should Always be 0xFFFF; */
    pMsgNewEntry->list.record_index = 0xFFFF;   /* For New Entry It should be alaways 0xFFFF */

    if (gFDLBDLContext.FDNBDNEdit)  /* If entry is edited */
    {
        pMsgNewEntry->list.index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].index;
        pMsgNewEntry->list.record_index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].record_index;
    }
    if (gFDLBDLContext.FDLBDLNumber[0] == '+')  /* If Number is International */
    {
        pMsgNewEntry->list.tel.type = MMI_CSMCC_INTERNATIONAL_ADDR;     /* INTERNATIONAL */
        pMsgNewEntry->list.tel.length =
            (U8) mmi_ucs2strlen((const S8*)(gFDLBDLContext.FDLBDLNumber + ENCODING_LENGTH));
        mmi_ucs2_to_asc((PS8) pbNumber_ASCII, (PS8) (gFDLBDLContext.FDLBDLNumber + ENCODING_LENGTH));
        memcpy(pMsgNewEntry->list.tel.number, pbNumber_ASCII, strlen((PS8) pbNumber_ASCII) + 1);
    }
    else
    {
        pMsgNewEntry->list.tel.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;      /* DEFAULT */
        pMsgNewEntry->list.tel.length = (U8) mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLNumber);
        mmi_ucs2_to_asc((PS8) pbNumber_ASCII, (PS8) gFDLBDLContext.FDLBDLNumber);
        memcpy(pMsgNewEntry->list.tel.number, pbNumber_ASCII, strlen((PS8) pbNumber_ASCII) + 1);
    }
    if (GetUCS2Flag((PS8) gFDLBDLContext.FDLBDLName))
    {
        pMsgNewEntry->list.alpha_id.name_dcs = MMI_PHB_UCS2;
        pMsgNewEntry->list.alpha_id.name_length =
            ((U8) mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLName)) * ENCODING_LENGTH;
        BigEndianToLittleEndian((PS8) pMsgNewEntry->list.alpha_id.name, (PS8) gFDLBDLContext.FDLBDLName);
    }
    else
    {
        pMsgNewEntry->list.alpha_id.name_dcs = MMI_PHB_ASCII;
        /* pMsgNewEntry->list.alpha_id.name_length = (U8) mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLName);
        mmi_ucs2_to_asc((PS8) pMsgNewEntry->list.alpha_id.name, (PS8) gFDLBDLContext.FDLBDLName);
        PhbAsciiToGSM7Bit(pMsgNewEntry->list.alpha_id.name); */
        pMsgNewEntry->list.alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                gFDLBDLContext.FDLBDLName,
                                                pMsgNewEntry->list.alpha_id.name,
                                                MAX_PS_NAME_LENGTH,
                                                MMI_PHB_ASCII,
                                                0,
                                                1) - 1;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgNewEntry;
    Message.oslPeerBuffPtr = NULL;

    //DeleteUptoScrID(SCR_ID_SECSET_FDN_LIST);
    ExitSECSETFDNListReload();

    SetProtocolEventHandler(SECSETSetFdlEntryRsp, PRT_PHB_SET_ENTRY_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetFdlEntryRsp
 * DESCRIPTION
 *  Rsp fn for getting all FDL entries.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetFdlEntryRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }
    else if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
            IMG_GLOBAL_ERROR,
            1,
            ST_NOTIFYDURATION,
            ERROR_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }
    gFDLBDLContext.FDNBDNEdit = FALSE;
    //DeleteUptoScrID(SCR_ID_SECSET_FDN_LIST);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDN_OPTION);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDN_DETAILS);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_SAVING);
    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEditFDL
 * DESCRIPTION
 *  Highlight Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEditFDL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySECSETFDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLName,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].alpha_id.name);
    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLNumber,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].tel.number);
    gFDLBDLContext.FDNBDNEdit = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightDeleteFDL
 * DESCRIPTION
 *  Highlight Delete Option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightDeleteFDL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(EntrySECSETFDNDelConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNDelConfirm
 * DESCRIPTION
 *  Entry fn for Confirmation of Delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNDelConfirm(void)
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
        get_string(STR_ID_SECSET_DELETE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETDelFdlReq;
    SetLeftSoftkeyFunction(SECSETGetPIN2StatusReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToFDLList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETDelFdlReq
 * DESCRIPTION
 *  send req to L4 to Delete FDL List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETDelFdlReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *pMsgDelEntry = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_fdn = 1;
    EntrySECSETFDNBDNDeleting();
    pMsgDelEntry = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));
    pMsgDelEntry->no_data = 1;
    pMsgDelEntry->del_all = MMI_FALSE;  /* No */
    pMsgDelEntry->index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].index;

    pMsgDelEntry->type = MMI_PHB_FDN;   /* PHB_PHONEBOOK */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgDelEntry;
    Message.oslPeerBuffPtr = NULL;

    //DeleteUptoScrID(SCR_ID_SECSET_FDN_LIST);
    ExitSECSETFDNListReload();

    SetProtocolEventHandler(SECSETDelFdlRsp, PRT_PHB_DEL_ENTRY_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETDelFdlRsp
 * DESCRIPTION
 *  Rsp handler for Delete req.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETDelFdlRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }
    //DeleteUptoScrID(SCR_ID_SECSET_FDN_LIST);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDN_OPTION);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDN_DETAILS);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_DELETING);
    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2_CONFIRM_PIN2);
}


/*****************************************************************************
 * FUNCTION
 *  FdlMakeCall
 * DESCRIPTION
 *  make call from FDL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FdlMakeCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gFDLBDLContext.HighlightedFDN != 255)
    {
        g_phb_cntx.dial_from_list = MMI_PHB_FDN;
        MakeCall((PS8) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].tel.number);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetActiveIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetActiveIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.HighlightedFDN = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  GetEntryTitle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void GetEntryTitle(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        ChangeTitleString((PU8) GetString(STR_SETTING_FDL_NAME));
    }
    else if (index == 1)
    {
        ChangeTitleString((PU8) GetString(STR_SETTING_FDL_NUMBER));
    }
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  GoToFDLList
 * DESCRIPTION
 *  Goback to FDl List Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToFDLList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_SECSET_FDN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNBDNSaving
 * DESCRIPTION
 *  Show progress screen for Settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNBDNSaving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FDNBDN_SAVING, NULL, EntrySECSETFDNBDNSaving, NULL);

    ShowCategory66Screen(
        (U16)((gFDLBDLContext.is_fdn == 1) ? STR_SCR8054_CALL_FDL_CAPTION : STR_SCR8079_BDL_VIEW_LIST_CAPTION),
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_SAVING),
        IMG_GLOBAL_SAVE,
        NULL);
    ClearInputEventHandler(MMI_DEVICE_ALL); /* keep in saving screen and no input can be accepted */
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNBDNDeleting
 * DESCRIPTION
 *  Show progress screen for Settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNBDNDeleting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FDNBDN_DELETING, NULL, EntrySECSETFDNBDNDeleting, NULL);

    ShowCategory66Screen(
        (U16)((gFDLBDLContext.is_fdn == 1) ? STR_SCR8054_CALL_FDL_CAPTION : STR_SCR8079_BDL_VIEW_LIST_CAPTION),
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        IMG_GLOBAL_DELETED,
        NULL);
    ClearInputEventHandler(MMI_DEVICE_ALL); /* keep in deleting screen and no input can be accepted */
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETFDNBDNWaiting
 * DESCRIPTION
 *  Show progress screen for Settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETFDNBDNWaiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_FDNBDN_WAITING, NULL, EntrySECSETFDNBDNWaiting, NULL);

    ShowCategory66Screen(
        (U16)((gFDLBDLContext.is_fdn == 1) ? STR_SCR8054_CALL_FDL_CAPTION : STR_SCR8079_BDL_VIEW_LIST_CAPTION),
        MAIN_MENU_TITLE_SETTINGS_ICON,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);
    ClearInputEventHandler(MMI_DEVICE_ALL); /* keep in waiting screen and no input can be accepted */
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  PreSaveFdlBdlEntryReq
 * DESCRIPTION
 *  Show confirm Save Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreSaveFdlBdlEntryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLNumber) && !mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLName))
    {
        DisplayPopup((PU8) GetString(STR_ID_PHB_NAME_NUM_REQUIRE), IMG_GLOBAL_ERROR, FALSE, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }
    else if (!mmi_phb_op_check_valid_number((S8*)gFDLBDLContext.FDLBDLNumber))
    {
        DisplayPopup((PU8) GetString(STR_ID_PHB_NUM_INVALID), IMG_GLOBAL_ERROR, FALSE, ST_NOTIFYDURATION, ERROR_TONE);
        return;
    }
    else
    {
        SECSETGetPIN2StatusReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFdlList
 * DESCRIPTION
 *  Check if phonebook is ready, if yes then load FDL List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFdlList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.phb_ready)
    {
        gFDLBDLContext.FDNBDNCount = 0;
        EntrySECSETFDNBDNWaiting();
        SECSETGetFdlEntriesReq();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_FDL_NOT_READY), IMG_PROCESSING_PHONEBOOK, 1, ST_NOTIFYDURATION, 0);
    }
}

