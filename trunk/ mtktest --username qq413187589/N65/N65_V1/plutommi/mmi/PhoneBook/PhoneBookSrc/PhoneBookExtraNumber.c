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
 * PhoneBookExtraNumber.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of feature "Owner Number", "Service Dial Number",
 *   and "SOS number"
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _PHONEBOOKEXTRANUMBER_C
#define _PHONEBOOKEXTRANUMBER_C

#include "GSM7BitDefaultAlphabet.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"
#include "PhoneBookGprot.h"
#include "ProtocolEvents.h"
#include "SimDetectionGexdcl.h"
#include "CommonScreens.h"
#include "CallSetUp.h"
#include "SettingDefs.h"        /* For FDN */
#include "SettingsGdcl.h"       /* For FDN */
#include "SpeedDial.h"
#include "CallManagementGProt.h"
#include "SimDetectionGProt.h"
#include "QuickAccessMenuItem_def.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#if defined(__MMI_UCM__)
#include "UCMGProt.h"
#endif /*__MMI_UCM__*/
#endif /*__MMI_DUAL_SIM_MASTER__*/

/* 
 * Local Variable
 */
static MMI_PHB_ENTRY_STRUCT g_phb_sim_list[MAX_SIM_ENTRIES];    /* Maximum entry of MSISDN, SDL and SOS in SIM */
static U16 g_phb_sim_list_count;
U16 g_phb_read_index;
static MMI_SOS_NUMBER_STRUCT g_phb_nvram_list[MAX_NVRAM_SOS_ENTRIES];   /* Emergency Number in NVRAM */
static U8 *g_phb_sos_list[MAX_SIM_SOS_ENTRIES + MAX_NVRAM_SOS_ENTRIES];
static BOOL g_phb_edit_owner = FALSE;
static BOOL g_phb_operate_owner = FALSE;
static U8 g_phb_sos_nvram_read = 0;
static U16 g_phb_fdn_count = 0;         /* For FDN Lookup List */
static U8 g_phb_is_get_entry_rsp = 1;   /* Check if already get response for previous request. */

/* 
 * Global Variable
 */
extern S8 pbName[];
extern S8 pbNumber[];
extern wgui_inline_item wgui_inline_items[];
extern MMI_OWNER_NUMBER_STRUCT gDispOwnerNumber[2]; /* Owner number associate with Line ID */
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern S8 gSimEccNumList[MAX_ECC_NUMBER_LIST_LENGTH][(EMERGENCY_NUMBER_LENGTH + 1)];
#ifdef __MMI_DUAL_SIM_MASTER__
extern S8 gSimEccNumList_2[MAX_ECC_NUMBER_LIST_LENGTH][(EMERGENCY_NUMBER_LENGTH + 1)];
#endif

/* 
 * Global Function
 */
extern void RefreshDisplayOwnerNumber(U8 lineid);   /* Owner number associate with Line ID */
extern void MakeCall(PS8);                          /* For Service Dial Number */

#define MMI_PHB_EXTRA_NUMBER


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_init
 * DESCRIPTION
 *  Initialization of Owner Number feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_extra_number_init.>\n", __FILE__,
                         __LINE__);

    SetHiliteHandler(MENU_ID_PHB_EXTRA_NUMBER, mmi_phb_highlight_extra_number);

    SetHiliteHandler(MITEM105_PBOOK_OWNER_NUMBER, mmi_phb_highlight_owner_number);
    SetHiliteHandler(MITEM1051_OWNER_NUMBER_ERASE, mmi_phb_highlight_owner_number_erase);
    SetHiliteHandler(MITEM1052_OWNER_NUMBER_EDIT, mmi_phb_highlight_owner_number_edit);

    SetHiliteHandler(MENU_PHONEBOOK_SERVICENUMBER, mmi_phb_highlight_sdn_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_extra_number
 * DESCRIPTION
 *  highlight function of extra number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_extra_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_extra_number, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_extra_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_extra_number
 * DESCRIPTION
 *  entry function of extra number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_extra_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[6];
    U8 *nHintList[6];
#else /* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[3];
    U8 *nHintList[3];
#endif /* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM_MASTER__ 
    if (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid())
#else
    if (mmi_bootup_is_sim_valid())
#endif
    {
        EntryNewScreen(SCR_ID_PHB_SPECIAL_NUMBER, mmi_phb_exit_extra_number, mmi_phb_entry_extra_number, NULL);

        mmi_frm_unhide_menu_item(MITEM105_PBOOK_OWNER_NUMBER);
        mmi_frm_unhide_menu_item(MENU_PHONEBOOK_SERVICENUMBER);
        mmi_frm_unhide_menu_item(MITEM116_PBOOK_SOS_NUMBER);        
    #ifdef __MMI_DUAL_SIM_MASTER__        
        mmi_frm_unhide_menu_item(MENU_MTPNP_CARD2_OWNER_NUMBER);
        mmi_frm_unhide_menu_item(MENU_MTPNP_CARD2_SDL_NUMBER);
        mmi_frm_unhide_menu_item(MENU_MTPNP_CARD2_SOS_NUMBER);        

        if (!mmi_bootup_is_sim_valid())
        {
            mmi_frm_hide_menu_item(MITEM105_PBOOK_OWNER_NUMBER);
            mmi_frm_hide_menu_item(MENU_PHONEBOOK_SERVICENUMBER);
            mmi_frm_hide_menu_item(MITEM116_PBOOK_SOS_NUMBER);        
        }
        if (!mmi_bootup_is_sim2_valid())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CARD2_OWNER_NUMBER);
            mmi_frm_hide_menu_item(MENU_MTPNP_CARD2_SDL_NUMBER);
            mmi_frm_hide_menu_item(MENU_MTPNP_CARD2_SOS_NUMBER);        
        }        
    #endif
        guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_SPECIAL_NUMBER);
        nNumofItem = GetNumOfChild_Ext(MENU_ID_PHB_EXTRA_NUMBER);
        GetSequenceStringIds_Ext(MENU_ID_PHB_EXTRA_NUMBER, nStrItemList);
        SetParentHandler(MENU_ID_PHB_EXTRA_NUMBER);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MENU_ID_PHB_EXTRA_NUMBER, nHintList);

        ShowCategory52Screen(
            STR_ID_PHB_EXTRA_NUMBER,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            nHintList,
            0,
            0,
            guiBuffer);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_extra_number
 * DESCRIPTION
 *  exit function of extra number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_extra_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_SPECIAL_NUMBER;
}

/* --------------------------------------  Begin of Phone Book Owner Number ------------------------------------------- */
#define MMI_PHB_OWNER_NUMBER


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_owner_number
 * DESCRIPTION
 *  Highlight handler for Owner Number in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_owner_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_owner_number.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_owner_number_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_owner_number_pre_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_owner_number_erase
 * DESCRIPTION
 *  Highlight handler for owner number's option "Erase"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_owner_number_erase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_owner_number_erase.>\n",
                         __FILE__, __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_owner_number_pre_erase, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_owner_number_edit
 * DESCRIPTION
 *  Highlight handler for owner number's option "Edit"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_owner_number_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_owner_number_edit.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_owner_number_pre_edit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_owner_number_pre_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_pre_req
 * DESCRIPTION
 *  Checks and calls the L4 request function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        mmi_phb_owner_number_get_entry_req();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_get_entry_req
 * DESCRIPTION
 *  Sends the L4 request to fetch the owner numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_get_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phb_is_get_entry_rsp)
    {
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_get_entry_req.>\n", __FILE__,
                         __LINE__);

    myMsgPtr =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    myMsgPtr->index = 1;
    myMsgPtr->record_index = 0xFFFF;
    myMsgPtr->storage = MMI_SIM;
    myMsgPtr->type = MMI_PHB_MSISDN;
    myMsgPtr->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_owner_number_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    OslMsgSendExtQueue(&Message);

    g_phb_is_get_entry_rsp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_get_entry_rsp
 * DESCRIPTION
 *  Reads the owner numbers back from PS
 * PARAMETERS
 *  info        [IN]        Return response from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_get_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_get_entry_rsp.>\n", __FILE__,
                         __LINE__);

    g_phb_is_get_entry_rsp = 1; /* Get Response From L4 */

    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;
    if (localPtr->result.flag == 0 /* OK */ )
    {
        g_phb_sim_list_count = (localPtr->no_list < MAX_SIM_ENTRIES) ? localPtr->no_list : MAX_SIM_ENTRIES;

        for (i = 0; i < g_phb_sim_list_count && i < MAX_PB_OWNER_NUMBERS; i++)
        {
            g_phb_sim_list[i].storage = localPtr->list[i].storage;
            g_phb_sim_list[i].index = localPtr->list[i].index;
            g_phb_sim_list[i].record_index = localPtr->list[i].record_index;
            g_phb_sim_list[i].tel.type = localPtr->list[i].tel.type;
            g_phb_sim_list[i].tel.length = localPtr->list[i].tel.length;
            g_phb_sim_list[i].alpha_id.name_length = localPtr->list[i].alpha_id.name_length;
            g_phb_sim_list[i].alpha_id.name_dcs = localPtr->list[i].alpha_id.name_dcs;

            InputboxConvertGSMToDeviceEncoding(
                localPtr->list[i].alpha_id.name,
                g_phb_sim_list[i].alpha_id.name,
                localPtr->list[i].alpha_id.name_length,
                (g_phb_cntx.owner_name_len + 1) * ENCODING_LENGTH,
                localPtr->list[i].alpha_id.name_dcs,
                0,
                1);

            if ((g_phb_sim_list[i].tel.length > 0) && ((g_phb_sim_list[i].tel.type & 0x10) != 0))
            {
                g_phb_sim_list[i].tel.number[0] = '+';
                mmi_asc_to_ucs2(
                    (PS8) (g_phb_sim_list[i].tel.number + ENCODING_LENGTH),
                    (PS8) localPtr->list[i].tel.number);
            }
            else
            {
                mmi_asc_to_ucs2((PS8) g_phb_sim_list[i].tel.number, (PS8) localPtr->list[i].tel.number);
            }
        }
    }
    else    /* TBD - what to do if result flag is false */
    {
        g_phb_sim_list_count = 0;
    }

    /* Owner number associate with Line ID */
    memset((void*)&gDispOwnerNumber, 0, sizeof(gDispOwnerNumber));

    for (i = 0; ((i < MAX_LINE_NUM) && (i < g_phb_sim_list_count)); ++i)
    {
        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].alpha_id.name))
        {
            mmi_ucs2ncpy(
                (PS8) gDispOwnerNumber[i].name,
                (PS8) g_phb_sim_list[i].alpha_id.name,
                MAX_PB_NAME_LENGTH + 1);
        }

        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
        {
            mmi_ucs2ncpy(
                (PS8) gDispOwnerNumber[i].number,
                (PS8) g_phb_sim_list[i].tel.number,
                MAX_PB_NUMBER_LENGTH + 1);
        }
    }

    RefreshDisplayOwnerNumber((U8) g_callset_context.LineID);

    if (g_phb_operate_owner)
    {
        g_phb_operate_owner = FALSE;
        if (g_phb_edit_owner == TRUE)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_ID_PHB_ERASED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        }
        DeleteScreenIfPresent(SCR_OWNER_NUMBER_EDIT);
        DeleteScreenIfPresent(SCR_OWNER_NUMBER_OPTIONS);
        g_phb_edit_owner = FALSE;
    }
    else if (g_phb_sim_list_count)
    {
        /* Display result screen only when processing screen is not interrupted. */
        if (GetActiveScreenId() != SCR_IN_PROGRESS_PHB)
        {
            return;
        }
#if defined(__MMI_PHB_ALS_SUPPORT__)
        if ((g_callset_context.LineID == LINE2) && (g_phb_sim_list_count == 1))
        {
            DisplayPopup(
                (PU8) GetString(STR_NO_OWNER_NUMBER_MESSAGE),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        else
#endif /* defined(__MMI_PHB_ALS_SUPPORT__) */
        {
            mmi_phb_entry_owner_number();
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_OWNER_NUMBER_MESSAGE),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number
 * DESCRIPTION
 *  Displays the owner numbers list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *names[MAX_PB_OWNER_NUMBERS];
    U16 i;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_owner_number.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_OWNER_NUMBERS, mmi_phb_exit_owner_number, mmi_phb_entry_owner_number, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_OWNER_NUMBERS);

#if defined(__MMI_PHB_ALS_SUPPORT__)
    /* reset subMenuDataPtrs before use */
    subMenuDataPtrs[0] = subMenuData[0];
    memset((S8*)subMenuDataPtrs[0], 0, MAX_SUB_MENU_SIZE);
    
    i = (U16) g_callset_context.LineID;
    if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].alpha_id.name))
    {
        names[0] = g_phb_sim_list[i].alpha_id.name;
        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
        {
            subMenuDataPtrs[0] = g_phb_sim_list[i].tel.number;
        }
        else
        {
            subMenuDataPtrs[0] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }
    else
    {
        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
        {
            names[0] = g_phb_sim_list[i].tel.number;
            subMenuDataPtrs[0] = NULL;         
        }
        else
        {
            names[0] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
            subMenuDataPtrs[0] = NULL;
        }     
    }
    g_phb_cntx.active_index = (U16) g_callset_context.LineID;
    g_phb_sim_list_count = 1;
#else /* defined(__MMI_PHB_ALS_SUPPORT__) */

#if defined(__MMI_PHB_DISPLAY_ONE_MSISDN__)
    g_phb_sim_list_count = 1;
#endif 

    for (i = 0; i < g_phb_sim_list_count; i++)
    {
        /* reset subMenuDataPtrs before use */
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        
        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].alpha_id.name))
        {
            names[i] = g_phb_sim_list[i].alpha_id.name;
            if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
            {
                subMenuDataPtrs[i] = g_phb_sim_list[i].tel.number;
            }
            else
            {
                subMenuDataPtrs[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
            }
        }
        else
        {
            if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
            {
                names[i] = g_phb_sim_list[i].tel.number;
                subMenuDataPtrs[i] = NULL;
            }
            else
            {
                names[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
                subMenuDataPtrs[i] = NULL;
            }
        }
    }

    RegisterHighlightHandler(mmi_phb_get_index);
#endif /* defined(__MMI_PHB_ALS_SUPPORT__) */

    ShowCategory53Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_SIM1_OWNER_NUMBER,
    #else /* __MMI_DUAL_SIM_MASTER__ */
        STR_MITEM105,
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_phb_sim_list_count,
        names,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_phb_entry_onwer_number_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_onwer_number_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_owner_number
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_owner_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_owner_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.start_scr_id == 0)
    {
        g_phb_cntx.start_scr_id = GetCurrScrnId();
    }
    g_phb_cntx.end_scr_id = SCR_OWNER_NUMBERS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_onwer_number_option
 * DESCRIPTION
 *  Draws the menu for Owner number options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_onwer_number_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 nStrItemList[2];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_onwer_number_option.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_OWNER_NUMBER_OPTIONS, mmi_phb_exit_onwer_number_option, mmi_phb_entry_onwer_number_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_OWNER_NUMBER_OPTIONS); /* Getting the Index from history  */
    nNumofItem = GetNumOfChild(MITEM105_OWNER_NUMBER_OPTIONS);
    GetSequenceStringIds(MITEM105_OWNER_NUMBER_OPTIONS, nStrItemList);
    SetParentHandler(MITEM105_OWNER_NUMBER_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_onwer_number_option
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_onwer_number_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_onwer_number_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_OWNER_NUMBER_OPTIONS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_pre_erase
 * DESCRIPTION
 *  Confirms before erasing the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_pre_erase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_phb_sim_list[g_phb_cntx.active_index].alpha_id.name) ||
        mmi_ucs2strlen((S8*) g_phb_sim_list[g_phb_cntx.active_index].tel.number))
    {
        mmi_phb_entry_owner_number_erase_confirm();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_erase_confirm
 * DESCRIPTION
 *  Confirms before erasing the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_erase_confirm(void)
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
        get_string(STR_ERASE_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_owner_number_erase_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_erase_req
 * DESCRIPTION
 *  Sends the L4 request to erase the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_erase_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
     * MYQUEUE Message;
     * 
     * g_phb_operate_owner = TRUE;
     * 
     * PRINT_INFORMATION_2(MMI_TRACE_G4_PHB,"File: [%s]  Line: [%d] <<mmi_phb_owner_number_erase_req.>\n",__FILE__,__LINE__);
     * mmi_phb_show_in_progress(STR_PHB_ERASING, IMG_GLOBAL_ERASED);
     * 
     * myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
     * myMsgPtr->type = MMI_PHB_MSISDN;
     * myMsgPtr->no_data = 0;
     * myMsgPtr->list.storage = MMI_SIM;
     * myMsgPtr->list.index = g_phb_sim_list[g_phb_cntx.active_index].index;
     * myMsgPtr->list.record_index = 0xFFFF;
     * memset(myMsgPtr->list.alpha_id.name, 0, ENCODING_LENGTH);
     * myMsgPtr->list.alpha_id.name_length = 0;
     * myMsgPtr->list.alpha_id.name_dcs = MMI_PHB_ASCII;
     * 
     * myMsgPtr->list.tel.type = MMI_CSMCC_DEFAULT_ADDR_TYPE; //DEFAULT
     * myMsgPtr->list.tel.length = 0;
     * memset(myMsgPtr->list.tel.number, 0, ENCODING_LENGTH);
     * 
     * Message.oslSrcId     = MOD_MMI;
     * Message.oslDestId    = MOD_L4C;
     * Message.oslMsgId     = PRT_PHB_SET_ENTRY_REQ;
     * Message.oslDataPtr      = (oslParaType *)myMsgPtr;
     * Message.oslPeerBuffPtr  = NULL;
     * 
     * SetProtocolEventHandler(mmi_phb_owner_number_erase_rsp   ,PRT_PHB_SET_ENTRY_RSP);
     * OslMsgSendExtQueue(&Message);
     * DeleteNScrId(SCR_OWNER_NUMBER_OPTIONS);
     */
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If not enter from edit request, that is enter from erase request, so enter processing screen. */
    if (!g_phb_edit_owner)
    {
        g_phb_operate_owner = TRUE;

        PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_erase_req.>\n", __FILE__,
                             __LINE__);
        mmi_phb_show_in_progress(STR_PHB_ERASING, IMG_GLOBAL_ERASED);
    }

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    myMsgPtr->storage = MMI_SIM;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_MSISDN;
    myMsgPtr->index = g_phb_sim_list[g_phb_cntx.active_index].index;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_owner_number_erase_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);

    /* If not enter from edit request, that is enter from erase request, so erase screen. */
    //if(!g_phb_edit_owner)
    //   DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_erase_rsp
 * DESCRIPTION
 *  Response handler for Owner number erase request
 * PARAMETERS
 *  info        [IN]        Return result from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_erase_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MSG_PHB_SET_ENRTY_RSP_STRUCT* localPtr;
    //localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT *)info;

    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_erase_rsp.>\n", __FILE__,
                         __LINE__);

    /* If this is erase response before save request,  continue to set entry. */
    if (g_phb_edit_owner)
    {
        mmi_phb_owner_number_edit_req();
        return;
    }

    if (localPtr->result.flag == 0 /* OK */ )
    {
        mmi_phb_owner_number_get_entry_req();
    }
    else
    {
        g_phb_operate_owner = FALSE;
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_OWNER_NUMBER_OPTIONS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_pre_edit
 * DESCRIPTION
 *  Sets the buffers before editing the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_pre_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbName, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((PS8) pbName, (PS8) g_phb_sim_list[g_phb_cntx.active_index].alpha_id.name);
    memset(pbNumber, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((PS8) pbNumber, (PS8) g_phb_sim_list[g_phb_cntx.active_index].tel.number);
    mmi_phb_entry_owner_number_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_edit
 * DESCRIPTION
 *  Inline edit screen to edit Owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 DetailPbNameImageList[2];
    U8 item_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<OwnerNumberEdit.>\n", __FILE__, __LINE__);
    EntryNewScreen(SCR_OWNER_NUMBER_EDIT, mmi_phb_exit_owner_number_edit, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_OWNER_NUMBER_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_OWNER_NUMBER_EDIT, &inputBufferSize);

    if (g_phb_cntx.owner_name_len != 0)
    {
        SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemFullScreenEdit(
            &wgui_inline_items[item_index],
            STR_OWNER_NAME_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            (PU8) pbName,
            g_phb_cntx.owner_name_len + 1,
            INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING);
        SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
        DetailPbNameImageList[item_index++] = IMG_NAME;
    }

    SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[item_index],
        (PU8) pbNumber,
        MAX_PB_NUMBER_LENGTH + 1,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[item_index]);
    DetailPbNameImageList[item_index++] = IMG_MOBILE_NUMBER;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
    }

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_EDIT_LSK,
        STR_GLOBAL_DONE,
        IMG_DONE_RSK,
        item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_owner_number_edit_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_owner_number_edit
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_owner_number_edit()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_owner_number_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_OWNER_NUMBER_EDIT;
    CloseCategory57Screen();
    h.scrnID = SCR_OWNER_NUMBER_EDIT;
    h.entryFuncPtr = mmi_phb_entry_owner_number_edit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_edit_confirm
 * DESCRIPTION
 *  Confirms before saving the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_edit_confirm(void)
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
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_owner_number_edit_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_3_history_and_clear, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_edit_pre_req
 * DESCRIPTION
 *  Check if number is invalid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_edit_pre_req(void)
{
    U16 str_id = 0;
    if (!mmi_phb_op_check_valid_number(pbNumber))
    {
        str_id = STR_ID_PHB_NUM_INVALID;
        DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }       
    mmi_phb_owner_number_edit_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_edit_req
 * DESCRIPTION
 *  Send the L4 request to save the owner number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_edit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

#if defined(__PHB_0x81_SUPPORT__)
    U8 length;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_edit_req.>\n", __FILE__,
                         __LINE__);

    g_phb_operate_owner = TRUE;

    if (g_phb_sim_list[g_phb_cntx.active_index].tel.length >= 20)       /* need erase first to release ext1 */
    {
        if (!g_phb_edit_owner)
        {
            g_phb_edit_owner = TRUE;
            mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
            /* Erase record before save */
            mmi_phb_owner_number_erase_req();
            return;
        }
    }
    else
    {
        g_phb_edit_owner = TRUE;
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    }

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_MSISDN;
    myMsgPtr->no_data = 0;
    myMsgPtr->list.storage = MMI_SIM;
    myMsgPtr->list.index = g_phb_sim_list[g_phb_cntx.active_index].index;
    myMsgPtr->list.record_index = 0xFFFF;

    if (GetUCS2Flag(pbName))
    {
        myMsgPtr->list.alpha_id.name_dcs = MMI_PHB_UCS2;
        myMsgPtr->list.alpha_id.name_length = ((U8) mmi_ucs2strlen(pbName)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM(
            (PU8) pbName,
            myMsgPtr->list.alpha_id.name,
            MAX_PS_NAME_LENGTH,
            MMI_PHB_UCS2,
            0,
            1);
    #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
        if ((length = mmi_phb_convert_to_0x81((S8*) myMsgPtr->list.alpha_id.name, TRUE)) > 0)
        {
            myMsgPtr->list.alpha_id.name_dcs = 0x09;
            myMsgPtr->list.alpha_id.name_length = length;
        }
    #endif /* defined(__PHB_0x81_SUPPORT__) */ 
    }
    else
    {
        myMsgPtr->list.alpha_id.name_dcs = MMI_PHB_ASCII;
        myMsgPtr->list.alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) pbName,
                                                myMsgPtr->list.alpha_id.name,
                                                MAX_PS_NAME_LENGTH,
                                                MMI_PHB_ASCII,
                                                0,
                                                1) - 1;
    }

    if (pbNumber[0] == '+')
    {
        myMsgPtr->list.tel.type = MMI_CSMCC_INTERNATIONAL_ADDR; /* INTERNATIONAL */
        myMsgPtr->list.tel.length = (U8) mmi_ucs2strlen(pbNumber + ENCODING_LENGTH);
        mmi_ucs2_to_asc((PS8) myMsgPtr->list.tel.number, pbNumber + ENCODING_LENGTH);
    }
    else
    {
        myMsgPtr->list.tel.type = MMI_CSMCC_DEFAULT_ADDR_TYPE;  /* DEFAULT */
        myMsgPtr->list.tel.length = (U8) mmi_ucs2strlen(pbNumber);
        mmi_ucs2_to_asc((PS8) myMsgPtr->list.tel.number, pbNumber);
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_owner_number_edit_rsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
    /* DeleteNScrId(SCR_OWNER_NUMBER_OPTIONS); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_edit_rsp
 * DESCRIPTION
 *  Response hanlder for owner number edit request
 * PARAMETERS
 *  info        [IN]        Return response from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_owner_number_edit_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_owner_number_edit_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {
        mmi_phb_owner_number_get_entry_req();
    }
    else
    {
        g_phb_operate_owner = FALSE;
        g_phb_edit_owner = FALSE;
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }

        DeleteScreenIfPresent(SCR_OWNER_NUMBER_EDIT);
        DeleteScreenIfPresent(SCR_OWNER_NUMBER_OPTIONS);
    }
}

/* --------------------------------------  END of Phone Book Owner Number ------------------------------------------- */

/* --------------------------------------  Begin of Phone Book Service Dial Number ------------------------------------------- */
#define MMI_PHB_SDN_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_sdn_list
 * DESCRIPTION
 *  Highlight handler for SDL in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_sdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_sdn_list_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_sdn_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdn_list_pre_entry
 * DESCRIPTION
 *  Checks and calls the L4 request function to fetch SDL numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sdn_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        g_phb_sim_list_count = 0;
        g_phb_read_index = 1;
        mmi_phb_sdn_get_entry_req();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdn_get_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to get the SDL numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sdn_get_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<LoadAllFdlist.>\n", __FILE__, __LINE__);

    myMsgPtr =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    myMsgPtr->index = g_phb_read_index; /* Begin from 1 */
    myMsgPtr->record_index = 0xFFFF;
    myMsgPtr->storage = MMI_SIM;
    myMsgPtr->type = MMI_PHB_SDN;
    myMsgPtr->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_sdn_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdn_get_entry_rsp
 * DESCRIPTION
 *  Reads the SDL numbers back from L4
 * PARAMETERS
 *  info        [IN]        Return result from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sdn_get_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<GetAllFdlEntries.>\n", __FILE__, __LINE__);

    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        /* Begin to assign to list */
        for (i = 0; i < localPtr->no_list; i++)
        {
            /* No Space */
            if (g_phb_sim_list_count >= MAX_SIM_ENTRIES)
            {
                continue;
            }

            /* Empty Entry */
            if ((localPtr->list[i].alpha_id.name_length == 0) && (localPtr->list[i].tel.length == 0))
            {
                continue;
            }

            g_phb_sim_list[g_phb_sim_list_count].storage = localPtr->list[i].storage;
            g_phb_sim_list[g_phb_sim_list_count].index = localPtr->list[i].index;
            g_phb_sim_list[g_phb_sim_list_count].record_index = localPtr->list[i].record_index;
            g_phb_sim_list[g_phb_sim_list_count].tel.type = localPtr->list[i].tel.type;
            g_phb_sim_list[g_phb_sim_list_count].tel.length = localPtr->list[i].tel.length;
            g_phb_sim_list[g_phb_sim_list_count].alpha_id.name_length = localPtr->list[i].alpha_id.name_length;
            g_phb_sim_list[g_phb_sim_list_count].alpha_id.name_dcs = localPtr->list[i].alpha_id.name_dcs;

            if (g_phb_sim_list[g_phb_sim_list_count].alpha_id.name_dcs == MMI_PHB_UCS2)
            {
                BigEndianToLittleEndian(
                    (PS8) g_phb_sim_list[g_phb_sim_list_count].alpha_id.name,
                    (PS8) localPtr->list[i].alpha_id.name);
            }
            else
            {
                mmi_asc_to_ucs2(
                    (PS8) g_phb_sim_list[g_phb_sim_list_count].alpha_id.name,
                    (PS8) localPtr->list[i].alpha_id.name);
            }

            if ((localPtr->list[i].tel.length > 0) && ((localPtr->list[i].tel.type & 0x10) != 0))
            {
                g_phb_sim_list[g_phb_sim_list_count].tel.number[0] = '+';

                mmi_asc_to_ucs2(
                    (PS8) (g_phb_sim_list[g_phb_sim_list_count].tel.number + ENCODING_LENGTH),
                    (PS8) localPtr->list[i].tel.number);
            }
            else
            {
                mmi_asc_to_ucs2(
                    (PS8) g_phb_sim_list[g_phb_sim_list_count].tel.number,
                    (PS8) localPtr->list[i].tel.number);
            }

            g_phb_sim_list_count++;
        }

        /* Try to read more entry if exists. */
        if (localPtr->no_list == MAX_ENTRIES_IN_LIST)
        {
            g_phb_read_index += MAX_ENTRIES_IN_LIST;
            mmi_phb_sdn_get_entry_req();
            return;
        }
    }
    else
    {
        /* TBD - what to do if result flag is false */
    }

    if (g_phb_sim_list_count)
    {
        mmi_phb_entry_sdn_list();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_SDL_NO_LIST_TEXT),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sdn_list
 * DESCRIPTION
 *  Displays the Service Dail Numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    U8 *names[MAX_SIM_ENTRIES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SDN_LIST, mmi_phb_exit_sdn_list, mmi_phb_entry_sdn_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_SDN_LIST);

    for (i = 0; i < g_phb_sim_list_count; ++i)
    {
        /* reset subMenuDataPtrs before use */
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
               
        if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].alpha_id.name))
        {
            names[i] = g_phb_sim_list[i].alpha_id.name;
            if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
            {
                subMenuDataPtrs[i] = g_phb_sim_list[i].tel.number;
            }
            else
            {
                subMenuDataPtrs[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
            }
        }
        else
        {
            if (mmi_ucs2strlen((PS8) g_phb_sim_list[i].tel.number))
            {
                names[i] = g_phb_sim_list[i].tel.number;
                subMenuDataPtrs[i] = NULL;
            }
            else
            {
                names[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
                subMenuDataPtrs[i] = NULL;
            }
        }
    }

    RegisterHighlightHandler(mmi_phb_get_index);
    ShowCategory53Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_SIM1_SDL_NUMBER,
    #else
        STR_SDL_MAIN_MENU,
    #endif
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_DIAL,
        IMG_SDL_CALL_LSK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_phb_sim_list_count,
        names,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        SetLeftSoftkeyFunction(mmi_phb_sdn_list_make_call, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_sdn_list_make_call, KEY_SEND, KEY_EVENT_UP);    
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetLeftSoftkeyFunction(mmi_phb_sdn_list_make_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_sdn_list_make_call, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_sdn_list
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_sdn_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_sdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_SDN_LIST;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sdn_list_make_call
 * DESCRIPTION
 *  Makes call to an SDL number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sdn_list_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) g_phb_sim_list[g_phb_cntx.active_index].tel.number))
    {
        g_phb_cntx.dial_from_list = MMI_PHB_SDN;
        if (g_phb_sim_list[g_phb_cntx.active_index].tel.number[0] == '+' &&
            g_phb_sim_list[g_phb_cntx.active_index].tel.number[(mmi_ucs2strlen
                                                                ((const S8*)(g_phb_sim_list[g_phb_cntx.active_index].
                                                                              tel.number)) - 1) * ENCODING_LENGTH] ==
            '#')
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
        #endif	/* __MMI_DUAL_SIM_MASTER__ */
            MakeCall((PS8) g_phb_sim_list[g_phb_cntx.active_index].tel.number + 2);
        }
        else
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
        #endif	/* __MMI_DUAL_SIM_MASTER__ */
            MakeCall((PS8) g_phb_sim_list[g_phb_cntx.active_index].tel.number);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_NO_NUMBER_TO_DIAL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}

/* --------------------------------------  END of Phone Book Service Dial Number ------------------------------------------- */

/* --------------------------------------  Begin of Phone Book SOS(Emergency) Number ------------------------------------------- */
#define MMI_PHB_SOS_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_init
 * DESCRIPTION
 *  Initialization of SOS numbers feature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MITEM116_PBOOK_SOS_NUMBER, mmi_phb_highlight_sos_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_sos_list
 * DESCRIPTION
 *  Highlight handler for SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_sos_list_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_sos_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_pre_entry
 * DESCRIPTION
 *  Checks and calls the L4 reuest function to fetch SOS numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        mmi_phb_sos_list_get_entry_req();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_get_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to get the SOS numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_get_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    myMsgPtr->index = 1;
    myMsgPtr->record_index = 0xFFFF;
    myMsgPtr->storage = MMI_SIM;
    myMsgPtr->type = MMI_PHB_ECC;
    myMsgPtr->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_sos_list_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_get_entry_rsp
 * DESCRIPTION
 *  Reads SOS numbers from L4
 * PARAMETERS
 *  info        [IN]        Return from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_get_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 i;
    U8 number[MAX_PB_NUMBER_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;
    if (localPtr->result.flag == 0 /* OK */ )
    {
        g_phb_sim_list_count = (localPtr->no_list < MAX_SIM_ENTRIES) ? localPtr->no_list : MAX_SIM_ENTRIES;

        for (i = 0; i < g_phb_sim_list_count && i < MAX_SIM_SOS_ENTRIES; ++i)
        {
            g_phb_sim_list[i].storage = localPtr->list[i].storage;
            g_phb_sim_list[i].index = localPtr->list[i].index;
            g_phb_sim_list[i].record_index = localPtr->list[i].record_index;
            g_phb_sim_list[i].tel.type = localPtr->list[i].tel.type;

            if ((g_phb_sim_list[i].tel.length > 0) && ((g_phb_sim_list[i].tel.type & 0x10) != 0))
            {
                number[0] = '+';
                memcpy((void*)&number[1], (void*)&localPtr->list[i].tel.number[0], MAX_PB_NUMBER_LENGTH - 1);
                mmi_asc_to_ucs2((PS8) & g_phb_sim_list[i].tel.number, (PS8) number);

            }
            else
            {
                g_phb_sim_list[i].tel.length = localPtr->list[i].tel.length;
                memcpy((void*)&number, (void*)&localPtr->list[i].tel.number, MAX_PB_NUMBER_LENGTH);
                mmi_asc_to_ucs2((PS8) & g_phb_sim_list[i].tel.number, (PS8) number);
            }
        }
    }
    else    /* TBD - what to do if result flag is false */
    {
        g_phb_sim_list_count = 0;
    }

    mmi_phb_entry_sos_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_list
 * DESCRIPTION
 *  Displays the SOS list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 index = 0;
    S32 display_index = 0;
    S16 error = 0;
    U8 *sub_ptr[MAX_NVRAM_SOS_ENTRIES + MAX_SIM_ENTRIES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read from NVRAM for one time */
    if (g_phb_sos_nvram_read == 0)
    {
        for (index = 0; index < MAX_NVRAM_SOS_ENTRIES; index++)
        {
            ReadRecord(
                NVRAM_EF_PHONEBOOK_SOS_LID,
                (U16) (index + 1),
                &g_phb_nvram_list[index],
                NVRAM_SOS_RECORD_SIZE,
                &error);
        }

        g_phb_sos_nvram_read = 1;
    }

    /* Prepare list */
    for (index = 0; index < g_phb_sim_list_count; ++index)
    {
        g_phb_sos_list[display_index] = (U8*) g_phb_sim_list[index].tel.number;
    #ifdef __MMI_DUAL_SIM_MASTER__
        sub_ptr[display_index++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM1);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        sub_ptr[display_index++] = (U8*) GetString(STR_ID_PHB_SOSLIST_INSIM);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    for (; index < (MAX_NVRAM_SOS_ENTRIES + g_phb_sim_list_count); ++index)
    {
        if (g_phb_nvram_list[index - g_phb_sim_list_count].length == 0xFF ||
            g_phb_nvram_list[index - g_phb_sim_list_count].length == 0)
        {
        #if defined(__MMI_PHB_SOS_NUM_EDIT__)
            g_phb_sos_list[display_index] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
            sub_ptr[display_index++] = (U8*) GetString(STR_SOSLIST_NVRAM);
        #endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */ 
        }
        else
        {
            g_phb_sos_list[display_index] = (U8*) g_phb_nvram_list[index - g_phb_sim_list_count].number;
            sub_ptr[display_index++] = (U8*) GetString(STR_SOSLIST_NVRAM);
        }
    }

#if !defined(__MMI_PHB_SOS_NUM_EDIT__)
    if (display_index == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, TRUE, PHB_NOTIFY_TIMEOUT, EMPTY_LIST_TONE);
        return;
    }
#endif /* !defined(__MMI_PHB_SOS_NUM_EDIT__) */ 

    EntryNewScreen(SCR_SOS_DISPLAY, mmi_phb_exit_sos_list, mmi_phb_entry_sos_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_SOS_DISPLAY);
    RegisterHighlightHandler(mmi_phb_sos_list_get_index);

    for (index = 0; index < display_index; index++) /* subMenuDataPtrs[] will be clear in EntryNewScreen, so reassign here. */
    {
        subMenuDataPtrs[index] = sub_ptr[index];
    }

#if defined(__MMI_PHB_SOS_NUM_EDIT__)
    ShowCategory53Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_SIM1_SOS_NUMBER,
    #else
        STR_DISPLAY_SOS_CAPTION,
    #endif
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        display_index /* (MAX_NVRAM_SOS_ENTRIES + g_phb_sim_list_count ) */ ,
        g_phb_sos_list,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);
#else /* defined(__MMI_PHB_SOS_NUM_EDIT__) */ 
    ShowCategory53Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_SIM1_SOS_NUMBER,
    #else
        STR_DISPLAY_SOS_CAPTION,
    #endif
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_DIAL,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        display_index /* (MAX_NVRAM_SOS_ENTRIES + g_phb_sim_list_count ) */ ,
        g_phb_sos_list,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        SetLeftSoftkeyFunction(mmi_phb_sos_list_pre_confirm_call, KEY_EVENT_UP);   
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetLeftSoftkeyFunction(mmi_phb_sos_list_pre_confirm_call, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        SetKeyHandler(mmi_phb_sos_list_pre_confirm_call, KEY_SEND, KEY_EVENT_UP); 
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_phb_sos_list_pre_confirm_call, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_sos_list
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_sos_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_SOS_DISPLAY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_get_index
 * DESCRIPTION
 *  (S32)
 *  Gets the index of currently highlighted SOS number.Also sets the LSK accordingly.
 * PARAMETERS
 *  index       [IN]        Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_get_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = (S16) index;

#if defined(__MMI_PHB_SOS_NUM_EDIT__)
    /* reset subMenuDataPtrs before use */
    subMenuDataPtrs[g_phb_cntx.active_index] = subMenuData[g_phb_cntx.active_index];
    memset((S8*)subMenuDataPtrs[g_phb_cntx.active_index], 0, MAX_SUB_MENU_SIZE);
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_ucs2cmp((PS8) subMenuDataPtrs[g_phb_cntx.active_index], (PS8) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM1)) == 0)
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_ucs2cmp((PS8) subMenuDataPtrs[g_phb_cntx.active_index], (PS8) GetString(STR_ID_PHB_SOSLIST_INSIM)) == 0)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_sos_list_pre_entry_number, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_sos_list_pre_entry_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */ 
}

#if defined(__MMI_PHB_SOS_NUM_EDIT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_pre_entry_number
 * DESCRIPTION
 *  Calls the function to edit the SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_pre_entry_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2cmp((PS8) g_phb_sos_list[g_phb_cntx.active_index], (PS8) GetString(STR_GLOBAL_EMPTY_LIST)))
    {
        memset(pbNumber, 0, ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((PS8) pbNumber, (PS8) g_phb_sos_list[g_phb_cntx.active_index]);
    }

    mmi_phb_entry_sos_list_enter_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_list_enter_number
 * DESCRIPTION
 *  Accpt user input for SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_list_enter_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_SOS_NUMBER, mmi_phb_exit_sos_list_enter_number, mmi_phb_entry_sos_list_enter_number, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ENTER_SOS_NUMBER);
    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_PHONE_NUMBER,
        (PU8) pbNumber,
        MAX_PB_NUMBER_LENGTH + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_phb_sos_list_update_entry, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_sos_list_enter_number
 * DESCRIPTION
 *  Exit function of mmi_phb_exit_sos_list_enter_number()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_sos_list_enter_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ENTER_SOS_NUMBER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_update_entry
 * DESCRIPTION
 *  Saves the SOS number on NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_update_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen((PS8) pbNumber);

    mmi_ucs2cpy((PS8) g_phb_nvram_list[g_phb_cntx.active_index - g_phb_sim_list_count].number, (PS8) pbNumber);
    g_phb_nvram_list[g_phb_cntx.active_index - g_phb_sim_list_count].length = (U8) str_len;
    g_phb_nvram_list[g_phb_cntx.active_index - g_phb_sim_list_count].type = 0;

    str_len = WriteRecord(
                NVRAM_EF_PHONEBOOK_SOS_LID,
                (U16) (g_phb_cntx.active_index - g_phb_sim_list_count + 1),
                &g_phb_nvram_list[g_phb_cntx.active_index - g_phb_sim_list_count],
                NVRAM_SOS_RECORD_SIZE,
                &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteNScrId(SCR_ENTER_SOS_NUMBER);
}
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_pre_confirm_call
 * DESCRIPTION
 *  Asks before calling to an SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_pre_confirm_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2cmp((PS8) g_phb_sos_list[g_phb_cntx.active_index], (PS8) GetString(STR_GLOBAL_EMPTY_LIST)) == 0)
    {
        DisplayPopup((PU8) GetString(STR_NO_NUMBER_TO_DIAL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        mmi_phb_entry_sos_list_confirm_call();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_list_confirm_call
 * DESCRIPTION
 *  Confirm Make SOS Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_list_confirm_call(void)
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
        get_string(STR_ID_PHB_SOSLIST_DIAL_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_sos_list_make_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_make_call
 * DESCRIPTION
 *  Makes call to the SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calling an exit function that does nothing */
    EntryNewScreen(SCR_CONFIRM_SOS_CALL, NULL, NULL, NULL);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    MakeCall((S8*) g_phb_sos_list[g_phb_cntx.active_index]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_valid_sos_number
 * DESCRIPTION
 *  (PS8)
 *  number  IN number for check
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  U8 number type
 *****************************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
U8 mmi_phb_check_valid_sos_number(PS8 number, U8 simInterface)
#else
U8 mmi_phb_check_valid_sos_number(PS8 number)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    S16 error = 0;
    S32 nNumLen;
    S32 nLen;

    U8 sim_list_count;
    S8 sim_ecc_number[(EMERGENCY_NUMBER_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_sos_nvram_read == 0)
    {
        for (index = 0; index < MAX_NVRAM_SOS_ENTRIES; index++)
        {
            ReadRecord(
                NVRAM_EF_PHONEBOOK_SOS_LID,
                (U16) (index + 1),
                &g_phb_nvram_list[index],
                NVRAM_SOS_RECORD_SIZE,
                &error);
        }

        g_phb_sos_nvram_read = 1;
    }

    nNumLen = mmi_ucs2strlen(number);

#ifdef __MMI_DUAL_SIM_MASTER__
    sim_list_count = (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid()) ? MAX_ECC_NUMBER_LIST_LENGTH : 0;
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_list_count = mmi_bootup_is_sim_valid() ? MAX_ECC_NUMBER_LIST_LENGTH : 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    for (index = 0; index < sim_list_count; index++)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (simInterface == SIM1)
        {
            mmi_asc_to_ucs2((S8*) sim_ecc_number, (S8*) (gSimEccNumList[index]));
        }
        else if (simInterface == SIM2)
        {
            mmi_asc_to_ucs2((S8*) sim_ecc_number, (S8*) (gSimEccNumList_2[index]));
        }
        else
        {
            MMI_ASSERT(0);
        }
    #else /* __MMI_DUAL_SIM_SINGLE_CALL__ */
        mmi_asc_to_ucs2((S8*) sim_ecc_number, (S8*) (gSimEccNumList[index]));
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
        nLen = mmi_ucs2strlen((S8*) sim_ecc_number);
        if (nLen == nNumLen)
        {
            if ((mmi_ucs2cmp((PS8) sim_ecc_number, (PS8) number) == 0))
            {
                return 2;
            }
        }
        else if (nLen > nNumLen)
        {
            if ((mmi_ucs2ncmp((PS8) sim_ecc_number, (PS8) number, nNumLen) == 0))
            {
                return 1;
            }
        }
    }

    for (index = 0; index < MAX_NVRAM_SOS_ENTRIES; index++)
    {
        nLen = mmi_ucs2strlen((S8*) g_phb_nvram_list[index].number);
        if (nLen == nNumLen)
        {
            if ((mmi_ucs2cmp((PS8) g_phb_nvram_list[index].number, (PS8) number) == 0))
            {
                return 2;
            }
        }
        else if (nLen > nNumLen)
        {
            if ((mmi_ucs2ncmp((PS8) g_phb_nvram_list[index].number, (PS8) number, nNumLen) == 0))
            {
                return 1;
            }
        }
    }

    return FALSE;
}

/* --------------------------------------  END of Phone Book SOS(Emergeny) Number ------------------------------------------- */

#define MMI_PHB_FDN_SEARCH_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fdn_get_list_to_ram
 * DESCRIPTION
 *  This function is to load FDN list into ADN storage. Because when FDN is enable
 *  ADN will not be read from SIM card. This FDN list is for number lookup in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fdn_get_list_to_ram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_fdn_get_list_to_ram.>\n", __FILE__,
                         __LINE__);

    if (g_phb_cntx.sim_used == 0)
    {
        g_phb_fdn_count = 0;
        mmi_phb_fdn_get_list_to_ram_req();
    }
    else
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        g_phb_cntx.startup_before_sort = TRUE;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        mmi_phb_startup_finish_final_step();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fdn_get_list_to_ram_req
 * DESCRIPTION
 *  This function is to retrieve FDN list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fdn_get_list_to_ram_req(void)
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
    pMsgIndexReq->index = g_phb_fdn_count + 1;
    pMsgIndexReq->record_index = 0xFFFF;
    pMsgIndexReq->storage = MMI_SIM;
    pMsgIndexReq->type = MMI_PHB_FDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_fdn_get_list_to_ram_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fdn_get_list_to_ram_rsp
 * DESCRIPTION
 *  This function is to convert FDN retrievie result to ADN storage.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_fdn_get_list_to_ram_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 i;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        for (i = 0; i < localPtr->no_list; i++)
        {
            if (g_phb_fdn_count < MAX_SIM_ENTRIES)
            {
                store_index = g_phb_fdn_count + MAX_PB_PHONE_ENTRIES;
                g_phb_fdn_count++;
            }
            else
            {
                continue;
            }

            /* Parse Name Field */
            PhoneBook[store_index].alpha_id.name_length = localPtr->list[i].alpha_id.name_length;
            PhoneBook[store_index].alpha_id.name_dcs = localPtr->list[i].alpha_id.name_dcs;

            InputboxConvertGSMToDeviceEncoding(
                localPtr->list[i].alpha_id.name,
                PhoneBook[store_index].alpha_id.name,
                localPtr->list[i].alpha_id.name_length,
                (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
                localPtr->list[i].alpha_id.name_dcs,
                0,
                1);

            /* Parse Tel Number */
            PhoneBook[store_index].tel.type = localPtr->list[i].tel.type;
            PhoneBook[store_index].tel.length = localPtr->list[i].tel.length;
            mmi_phb_convert_to_bcd(
                PhoneBook[store_index].tel.number,
                localPtr->list[i].tel.number,
                (MAX_PB_NUMBER_LENGTH + 1) / 2);

        }

        if (localPtr->no_list == MAX_ENTRIES_IN_LIST)
        {
            mmi_phb_fdn_get_list_to_ram_req();
            return;
        }
    }

    /* Retrieve Speed Dial List after retrieve FDN list, because they all use same message. */
    //PhbGetSpeedDialInfo();
#ifdef __MMI_DUAL_SIM_MASTER__
    g_phb_cntx.startup_before_sort = TRUE;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    mmi_phb_startup_finish_final_step();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fdn_search_by_number
 * DESCRIPTION
 *  This function is to match calling number with FDN list store in ADN storage
 *  Only match when FDN is enable
 * PARAMETERS
 *  number      [IN]        ASCII format number
 * RETURNS
 *  result index
 *****************************************************************************/
U16 mmi_phb_fdn_search_by_number(S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 store_index;
    U8 tempNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_fdn_search_by_number.>\n", __FILE__,
                         __LINE__);

    if (g_phb_cntx.sim_used > 0)    /* ADN is read out from SIM card, so there is no storing FDN entry data. */
    {
        return 0xffff;
    }

    for (i = 0; i < g_phb_fdn_count; i++)
    {
        store_index = i + MAX_PB_PHONE_ENTRIES;
        if (((PhoneBook[store_index].tel.type & 0x90) == 0x90) && (PhoneBook[store_index].tel.type != 0xFF))
        {
            tempNumber[0] = '+';
            mmi_phb_convert_to_digit(
                (U8*) (tempNumber + 1),
                PhoneBook[store_index].tel.number,
                MAX_PB_NUMBER_LENGTH + 1);
        }
        else
        {
            mmi_phb_convert_to_digit(tempNumber, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
        }

        if (!strcmp((S8*) tempNumber, number))
        {
            return store_index;
        }

    }

    return 0xffff;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_sim_entry
 * DESCRIPTION
 *  This function is to get sdn entry for mmi_phb_call_get_call_data_for_call_mgnt
 * PARAMETERS
 *  void
 * RETURNS
 *  result MMI_PHB_ENTRY_STRUCT*
 *****************************************************************************/
MMI_PHB_ENTRY_STRUCT *mmi_phb_get_sim_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_phb_sim_list[g_phb_cntx.active_index];
}

#endif /* _PHONEBOOKEXTRANUMBER_C */ 

