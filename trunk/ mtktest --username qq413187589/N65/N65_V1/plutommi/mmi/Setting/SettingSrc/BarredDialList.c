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
 * BarredDialList.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Barred Dial List related functions
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

   FILENAME : CallBarredDialList.c

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
#include "BarredDialList.h"
#include "CommonScreens.h"
#include "PhoneBookGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SettingDefs.h"
#include "SettingsGexdcl.h"
#include "SettingsGdcl.h"
#include "SecuritySetup.h"
#include "ProfileGprots.h"
#include "SimDetectionDef.h"


/*****************************************************************************
 * FUNCTION
 *  InitBarredDialList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitBarredDialList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU8236_BDL_VIEW_OPTIONS_ADD, HighlightAddBDlist);
    SetHiliteHandler(MENU8236_BDL_VIEW_OPTIONS_EDIT, HighlightEditBDlist);
    SetHiliteHandler(MENU8236_BDL_VIEW_OPTIONS_DELETE, HighlightDeleteBDlist);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetBdlEntriesReq
 * DESCRIPTION
 *  Send req to L4 to Load BDL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetBdlEntriesReq(void)
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
    pMsgIndexReq->type = MMI_PHB_BDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(SECSETGetBdlEntriesRsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETGetBdlEntriesRsp
 * DESCRIPTION
 *  Rsp handler of req to load BDL list.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETGetBdlEntriesRsp(void *info)
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
        gFDLBDLContext.FDNBDNCount += localPtr->no_list;    /* Add New entries count to BDL list count */

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
            if (mmi_ucs2strlen((PS8) tmpConvertBuf) <= MAX_PB_NAME_LENGTH)
            {
                mmi_ucs2cpy((PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name, (PS8) tmpConvertBuf);
            }
            else
            {
                mmi_ucs2ncpy(
                    (PS8) gFDLBDLContext.FDLBDLEntries[i].alpha_id.name,
                    (PS8) tmpConvertBuf,
                    MAX_PB_NAME_LENGTH);
            }
            if (tmpConvertBuf != NULL)
            {
                OslMfree(tmpConvertBuf);
            }
            if (((localPtr->list[j].tel.type & 0x90) == 0x90) && (localPtr->list[j].tel.type != 0xFF))
            {
                gFDLBDLContext.FDLBDLEntries[i].tel.type = localPtr->list[j].tel.type;
                gFDLBDLContext.FDLBDLEntries[i].tel.number[0] = '+';
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
            SECSETGetBdlEntriesReq();
        }
        else
        {
            ViewBDList();
        }
    }
    else if (localPtr->result.flag == 1 /* Failure */  && localPtr->result.cause == 5)
    {
        /* gFDLBDLContext.FDNBDNCount =0; */
        ViewBDList();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_SECSET_BAR_DIAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ViewBDList
 * DESCRIPTION
 *  go to view BDL list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ViewBDList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.HighlightedBDN = 0;
    EntrySECSETBDNList();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBDNList
 * DESCRIPTION
 *  Entry fn to view BDL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBDNList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pstbdlist[MAX_SIM_ENTRIES], *bdlHint[MAX_SIM_ENTRIES];
    U16 index;
    U8 *guiBuffer;
    U16 bdlimagelist[MAX_SIM_ENTRIES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SECSET_BDN_LIST, NULL, EntrySECSETBDNList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_BDN_LIST);   /* Getting the Index from history */

    for (index = 0; index < gFDLBDLContext.FDNBDNCount; index++)
    {
        if (mmi_ucs2strlen((PS8) (gFDLBDLContext.FDLBDLEntries[index].alpha_id.name)) > 0)
        {
            pstbdlist[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].alpha_id.name;
            bdlHint[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].tel.number;
        }
        else
        {
            pstbdlist[index] = (U8*) gFDLBDLContext.FDLBDLEntries[index].tel.number;
            bdlHint[index] = NULL;
        }
        bdlimagelist[index] = IMG_STORAGE_SIM;
    }

    RegisterHighlightHandler(GetActiveBDLIndex);

    if (guiBuffer != NULL)
    {
        memset((void*)guiBuffer, 0, 2);
    }
    if ((gFDLBDLContext.HighlightedBDN >= gFDLBDLContext.FDNBDNCount) && (gFDLBDLContext.FDNBDNCount > 0))
    {
        gFDLBDLContext.HighlightedBDN = gFDLBDLContext.FDNBDNCount - 1;
    }

    if (gFDLBDLContext.FDNBDNCount == 0)    /* If list is empty */
    {
        pstbdlist[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        bdlimagelist[0] = 0;
        bdlHint[0] = NULL;

        ShowCategory6Screen(
            STR_SCR8079_BDL_VIEW_LIST_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            pstbdlist,
            NULL,
            0,
            guiBuffer);
        gFDLBDLContext.FDNBDNEdit = FALSE;

        memset(gFDLBDLContext.FDLBDLName, 0, (MAX_NAME_LEN_FSB_LIST + 1) * ENCODING_LENGTH);
        memset(gFDLBDLContext.FDLBDLNumber, 0, (MAX_NUMBER_LEN_FSB_LIST + 1 + 1) * ENCODING_LENGTH);

        SetLeftSoftkeyFunction(EntrySECSETBDNDetails, KEY_EVENT_UP);
        SetKeyHandler(EntrySECSETBDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_SEND, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory53Screen(
            STR_SCR8079_BDL_VIEW_LIST_CAPTION,
            MAIN_MENU_TITLE_SETTINGS_ICON,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gFDLBDLContext.FDNBDNCount,
            pstbdlist,
            bdlimagelist,
            bdlHint,
            0,
            gFDLBDLContext.HighlightedBDN,
            guiBuffer);

        SetLeftSoftkeyFunction(EntrySECSETBDNOption, KEY_EVENT_UP);
        SetKeyHandler(EntrySECSETBDNOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(0, KEY_SEND, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETBDNListReload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETBDNListReload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_SECSET_BDN_LIST))
    {
        HistoryReplace(SCR_ID_SECSET_BDN_LIST, SCR_ID_SECSET_BDN_LIST, EntryBdlList);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBDNOption
 * DESCRIPTION
 *  Entry fn to view Options of BDL list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBDNOption(void)
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
    EntryNewScreen(SCR_ID_SECSET_BDN_OPTION, NULL, EntrySECSETBDNOption, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_BDN_OPTION);

    nNumofItem = GetNumOfChild(MENU8236_BDL_VIEW_OPTIONS_MAIN);

    GetSequenceStringIds(MENU8236_BDL_VIEW_OPTIONS_MAIN, nStrItemList);
    SetParentHandler(MENU8236_BDL_VIEW_OPTIONS_MAIN);

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
}


/*****************************************************************************
 * FUNCTION
 *  GetActiveBDLIndex
 * DESCRIPTION
 *  Get index of currently highlighted BDL entry.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetActiveBDLIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.HighlightedBDN = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAddBDlist
 * DESCRIPTION
 *  Highlight handler of Add option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAddBDlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(EntrySECSETBDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySECSETBDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gFDLBDLContext.FDNBDNEdit = FALSE;
    memset(gFDLBDLContext.FDLBDLName, 0, (MAX_NAME_LEN_FSB_LIST + 1) * ENCODING_LENGTH);
    memset(gFDLBDLContext.FDLBDLNumber, 0, (MAX_NUMBER_LEN_FSB_LIST + 1 + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBDNDetails
 * DESCRIPTION
 *  Main Inline edit entry sceen fn to add and edit a BDL entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBDNDetails(void)
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
    if ((gFDLBDLContext.FDNBDNCount == (U16) gFDLBDLContext.MaxBDL || gFDLBDLContext.FDNBDNCount == MAX_SIM_ENTRIES) &&
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
        EntryNewScreen(SCR_ID_SECSET_BDN_DETAILS, ExitSECSETBDNDetails, NULL, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_SECSET_BDN_DETAILS);
        inputBuffer = GetCurrNInputBuffer(SCR_ID_SECSET_BDN_DETAILS, &inputBufferSize); /* added for inline edit history */

        nNumofItem = GetNumOfChild(MENU8236_BDL_VIEW_OPTIONS_ADD);

        GetSequenceImageIds(MENU8236_BDL_VIEW_OPTIONS_ADD, ItemIcons);

        InitializeCategory57Screen();

        FillBdlInlineEditStruct();

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

        SetCategory57RightSoftkeyFunctions(EntrySECSETBDNSaveConfirm, GoBackHistory);

    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSECSETBDNDetails
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSECSETBDNDetails(void)
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
    Scr.scrnID = SCR_ID_SECSET_BDN_DETAILS;
    Scr.entryFuncPtr = EntrySECSETBDNDetails;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    size = (U16) GetCategory57DataSize();       /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);   /* added for inline edit history */
    AddNHistory(Scr, size);
}


/*****************************************************************************
 * FUNCTION
 *  FillBdlInlineEditStruct
 * DESCRIPTION
 *  Fill Inline Edit structs.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillBdlInlineEditStruct(void)
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
        /* g_phb_cntx.bdn_name_len + 1, */
        ((g_phb_cntx.bdn_name_len > MAX_PB_NAME_LENGTH) ? (MAX_PB_NAME_LENGTH + 1) : (g_phb_cntx.bdn_name_len + 1)),
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
 *  PreNewBdlEntryReq
 * DESCRIPTION
 *  Funtion to be called after press of button save.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreNewBdlEntryReq(void)
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
        EntrySECSETBDNSaveConfirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBDNSaveConfirm
 * DESCRIPTION
 *  Entry fn to confirm Entry save.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBDNSaveConfirm(void)
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

    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETSetBdlEntryReq;
    SetLeftSoftkeyFunction(PreSaveFdlBdlEntryReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToBDLList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetBdlEntryReq
 * DESCRIPTION
 *  Fn to to called to send req to L4 to add entry
 *  in Bdl list after confirmation of PIN2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetBdlEntryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *pMsgNewEntry = NULL;
    MYQUEUE Message;
    U8 pbNumber_ASCII[MAX_PB_NUMBER_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_fdn = 0;
    EntrySECSETFDNBDNSaving();

    pMsgNewEntry = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    pMsgNewEntry->type = MMI_PHB_BDN;
    pMsgNewEntry->no_data = 1;
    pMsgNewEntry->list.storage = MMI_SIM;
    pMsgNewEntry->list.index = 0xFFFF;          /* For New Entry It should Always be 0xFFFF; */
    pMsgNewEntry->list.record_index = 0xFFFF;   /* For New Entry It should be alaways 0xFFFF */

    if (gFDLBDLContext.FDNBDNEdit)  /* If entry is edited */
    {
        pMsgNewEntry->list.index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedBDN].index;
        pMsgNewEntry->list.record_index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedBDN].record_index;
    }

    if (gFDLBDLContext.FDLBDLNumber[0] == '+')  /* if number is international */
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

    DeleteUptoScrID(SCR_ID_SECSET_BDN_LIST);
    ExitSECSETBDNListReload();

    SetProtocolEventHandler(SECSETSetBdlEntryRsp, PRT_PHB_SET_ENTRY_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETSetBdlEntryRsp
 * DESCRIPTION
 *  Rsp handler to add new entry in BDL.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETSetBdlEntryRsp(void *info)
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
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
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
    DeleteUptoScrID(SCR_ID_SECSET_BDN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEditBDlist
 * DESCRIPTION
 *  Highlight handler of Edit option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEditBDlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(EntrySECSETBDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntrySECSETBDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLName,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedBDN].alpha_id.name);
    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLNumber,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedBDN].tel.number);
    gFDLBDLContext.FDNBDNEdit = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightDeleteBDlist
 * DESCRIPTION
 *  Highlight handler Of dlete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightDeleteBDlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(EntrySECSETBDNDelConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySECSETBDNDelConfirm
 * DESCRIPTION
 *  Entry screen to confirm delete operation from user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySECSETBDNDelConfirm(void)
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
        get_string(STR_DELETE_QUERY_MSG),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    gSecuritySetupContext.VerifyPassSuccessCallBack = SECSETDelBdlReq;
    SetLeftSoftkeyFunction(SECSETGetPIN2StatusReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToBDLList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETDelBdlReq
 * DESCRIPTION
 *  After PIN2 verification, send req to l4 to delete selected BDL entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETDelBdlReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *pMsgDelEntry = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gFDLBDLContext.is_fdn = 0;
    EntrySECSETFDNBDNDeleting();
    pMsgDelEntry = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    pMsgDelEntry->no_data = 1;
    pMsgDelEntry->del_all = MMI_FALSE;  /* No */
    pMsgDelEntry->index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedBDN].index;

    pMsgDelEntry->type = MMI_PHB_BDN;   /* PHB_PHONEBOOK */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgDelEntry;
    Message.oslPeerBuffPtr = NULL;

    DeleteUptoScrID(SCR_ID_SECSET_BDN_LIST);
    ExitSECSETBDNListReload();

    SetProtocolEventHandler(SECSETDelBdlRsp, PRT_PHB_DEL_ENTRY_RSP);

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  SECSETDelBdlRsp
 * DESCRIPTION
 *  Rsp handler L4 req to delete entry in BDL.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SECSETDelBdlRsp(void *info)
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
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }
    DeleteUptoScrID(SCR_ID_SECSET_BDN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  GoToBDLList
 * DESCRIPTION
 *  Go to view BDL list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToBDLList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_SECSET_BDN_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  EntryBdlList
 * DESCRIPTION
 *  Check if Phone Book is ready, if yes then Enter in BDL List screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryBdlList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL); /* need to reload the FDL list screen and no input can be accepted */
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        gFDLBDLContext.FDNBDNCount = 0;
        SECSETGetBdlEntriesReq();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_BDL_NOT_READY), IMG_PROCESSING_PHONEBOOK, 1, ST_NOTIFYDURATION, 0);
    }
}

