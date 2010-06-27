#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "GlobalDefs.h"
#include "wgui_categories_popup.h"
#include "custom_mmi_default_value.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_header.h"
#include "GlobalConstants.h"
#include "EventsGprot.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "wgui_categories.h"
#include "Wgui_categories_util.h"
#include "HistoryGprot.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "SettingDefs.h"
#include "SettingProfile.h"
#include "HistoryGprot.h"
#include "mainmenudef.h"
#include "CallsDefs.h"
#include "CommonScreens.h"
#include "PhoneBookProt.h"
#include "PhoneBookGProt.h"
#include "wgui_categories_inputsenum.h"
#include "wgui_categories_inputs.h"
#include "vObjectsResDef.h"
#include "ProtocolEvents.h"
#include "SimDetectionDef.h"
#include "NVRAMProt.h"
#include "SettingsGdcl.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_OSAL_common.h"
#if defined(__MMI_UCM__)
#include "UCMGProt.h"
#endif/*__MMI_UCM__*/

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_VCARD__)
#include "vCard.h"
extern vcard_context_struct g_vcard_cntx;
#endif

extern U16 TitleStrings[MAX_PB_FIELDS];
extern U16 PhoneBookEntryCount;

extern mmi_phb_context_struct g_phb_cntx;
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern MTPNP_UINT16 PhoneBookEntryCount;
extern U16 g_phb_name_index[MAX_PB_ENTRIES];    /* Sorting Order by Name Field. */
extern U8 g_phb_enter_from;     /* Identify Save number from idle screen */
extern S8 pbName[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
extern S8 pbNumber[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
extern wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
extern MMI_PHB_LOOKUP_NODE_STRUCT LookUpTable[MAX_LOOKUP_TABLE_COUNT];

static BOOL SlavecopyEntry = MTPNP_FALSE;
static BOOL SlavemoveEntry = MTPNP_FALSE;
static BOOL SlaveduplicateEntry = MTPNP_FALSE;
BOOL Slave_CopyAll = MTPNP_FALSE;       /* used to Copy all from Phone to Slave SIM */

static MTPNP_UINT8 Slave_g_phb_copy_all_from_sim2_to;
static MTPNP_UINT16 SlavemoveEntryStoreIndex;
static MTPNP_UINT8 SlavemoveModified = 0;
MTPNP_UINT16 Slave_g_phb_mass_op_index;
MTPNP_UINT16 Slave_g_phb_mass_op_count;
MTPNP_UINT16 Slave_g_phb_mass_op_lookup_count;
MTPNP_BOOL Slave_g_phb_mass_op_abort;
MTPNP_BOOL Slave_g_phb_mass_op_success = MTPNP_TRUE;
MTPNP_BOOL Slave_g_phb_mass_delall = MTPNP_FALSE;
MTPNP_BOOL	Slave_g_is_phb_init=MTPNP_FALSE;
MTPNP_BOOL Slave_g_phb_startup_before_sort = MTPNP_FALSE;
MTPNP_UINT16 Slave_g_phb_fdn_count = 0;

#if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
extern mmi_phb_save_entry_from_others_callback_type mmi_phb_add_new_entry_callback;
#endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */
extern void mmi_phb_refresh_phb_list(void);

void MTPNP_PFAL_ADN_Init(void)
{
    SetSlaveProtocolEventHandler(MTPNP_PFAL_ADN_phb_ind_update, PRT_PHB_UPDATE_IND);
    SetHiliteHandler(MENU_MTPNP_PB_ADD_SIM2, HighlightSlaveAddEntry);
    SetHintHandler(MENU_MTPNP_PB_ADD_SIM2, HintSlaveAddEntry);

#if defined(__MMI_PHB_MULTI_OPERATION__)
#else /* __MMI_PHB_MULTI_OPERATION__ */
    SetHiliteHandler(MENU_MTPNP_PB_DELALL_SIM2, HighlightSlaveDeleteAllEntry);
    SetHintHandler(MENU_MTPNP_PB_DELALL_SIM2, HintSlaveDeleteAllEntry);
#endif /* __MMI_PHB_MULTI_OPERATION__ */

    SetHiliteHandler(MENU_MTPNP_PB_COPY_SIM2TOPHONE, HighlightSlaveCopylEntrySIM2Phone);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_SIM2TOPHONE, HighlightSlaveMovelEntrySIM2Phone);
    SetHiliteHandler(MENU_MTPNP_PB_COPY_PHONETOSIM2, HighlightSlaveCopylEntrySIM2Phone);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_PHONETOSIM2, HighlightSlaveMovelEntrySIM2Phone);

    SetHiliteHandler(MENU_MTPNP_PB_COPY_SIM2TOSIM1, HighlightSlaveCopylEntrySIM2SIM);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_SIM2TOSIM1, HighlightSlaveMovelEntrySIM2SIM);
    SetHiliteHandler(MENU_MTPNP_PB_COPY_SIM1TOSIM2, HighlightSlaveCopylEntrySIM2SIM);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_SIM1TOSIM2, HighlightSlaveMovelEntrySIM2SIM);

    SetHiliteHandler(MENU_MTPNP_PB_COPY_SIM1TOPHONE, mmi_phb_highlight_op_copy_entry);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_SIM1TOPHONE, mmi_phb_highlight_op_move_entry);
    SetHiliteHandler(MENU_MTPNP_PB_COPY_PHONETOSIM1, mmi_phb_highlight_op_copy_entry);
    SetHiliteHandler(MENU_MTPNP_PB_MOVE_PHONETOSIM1, mmi_phb_highlight_op_move_entry);

    SetHiliteHandler(MENU_MTPNP_PB_COPYALL_SIM2TOPHONE, HighlightSlaveCopyAllSIM2toPhone);
    SetHiliteHandler(MENU_MTPNP_PB_COPYALL_PHONETOSIM2, HighlightSlaveCopyAllPhonetoSIM2);
    SetHintHandler(MENU_MTPNP_PB_COPYALL_SIM2TOPHONE, HintSlaveCopyAllSIM2toPhone);
    SetHintHandler(MENU_MTPNP_PB_COPYALL_PHONETOSIM2, HintSlaveCopyAllPhonetoSIM2);

    SetHiliteHandler(MENU_MTPNP_PB_COPYALL_SIM1TOSIM2, HighlightSlaveCopyAllSIM1toSIM2);
    SetHiliteHandler(MENU_MTPNP_PB_COPYALL_SIM2TOSIM1, HighlightSlaveCopyAllSIM2toSIM1);
    SetHintHandler(MENU_MTPNP_PB_COPYALL_SIM1TOSIM2, HintSlaveCopyAllSIM1toSIM2);
    SetHintHandler(MENU_MTPNP_PB_COPYALL_SIM2TOSIM1, HintSlaveCopyAllSIM2toSIM1);

    SetHiliteHandler(MENU_MTPNP_PB_PRE_STORAGE_SIM2, highlightPreferStoragLocationinSIM2);
    SetHintHandler(MENU_MTPNP_PB_PRE_STORAGE_SIM2, hintPreferStoragLocationinSIM2);
    if(!MTPNP_PFAL_ADN_Is_PHB_Init())
    {
        MTPNP_PFAL_ADN_Init_SIM2_PHB();
    }
}

void HighlightSlaveAddEntry(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_cntx.active_index = 0xFFFF;
    g_phb_cntx.selected_storage = MMI_SIM2;
    if (MTPNP_AD_ADN_SIM2GetCapacity() <= MTPNP_AD_ADN_SIM2GetUsedNumber())
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_op_add_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_op_add_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}

void HintSlaveAddEntry(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];
    MTPNP_CHAR ascii_status[20];
    memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    sprintf(ascii_status, "%d/%d", (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetUsedNumber(),
            (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetCapacity());
    mmi_asc_to_ucs2(simStatus, ascii_status);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);
}

#if defined(__MMI_PHB_MULTI_OPERATION__)

#else /* __MMI_PHB_MULTI_OPERATION__ */
void HighlightSlaveDeleteAllEntry(void)
{
    g_phb_cntx.selected_storage = MMI_SIM2;
    if (MTPNP_AD_ADN_SIM2GetUsedNumber() || MTPNP_AD_FDN_GetStatus())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_delete_all_confirm, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_delete_all_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifndef __MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif /* defined(__MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__)*/ 
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}
#endif /* __MMI_PHB_MULTI_OPERATION__ */

void HintSlaveDeleteAllEntry(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];
    MTPNP_CHAR ascii_status[20];

    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    sprintf(ascii_status, "%d/%d", (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetUsedNumber(),
            (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetCapacity());
    mmi_asc_to_ucs2(simStatus, ascii_status);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);
}

void HighlightSlaveCopylEntrySIM2Phone(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_SIM2Phone_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightSlaveMovelEntrySIM2Phone(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Move_SIM2Phone_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightSlaveCopylEntrySIM2SIM(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_SIM2SIM_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void HighlightSlaveMovelEntrySIM2SIM(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Move_SIM2SIM_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_Slave_PB_Copy_SIM2Phone_confirm(void)
{
    SlavecopyEntry = MTPNP_TRUE;
    SlavemoveEntry = MTPNP_FALSE;
    SlaveduplicateEntry = MTPNP_FALSE;

    if ((g_phb_name_index[g_phb_cntx.active_index] < mmi_phb_get_max_pb_phone_entries())
        && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);

    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= mmi_phb_get_max_pb_phone_entries())
             && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
    }
    else
    {
        DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                       STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_COPY_QUERY_MSG), IMG_GLOBAL_QUESTION, WARNING_TONE);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_Move_Dup_SIM2Phone_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
}

void MTPNP_Slave_PB_Move_SIM2Phone_confirm(void)
{
    SlavemoveEntry = MTPNP_TRUE;
    SlavecopyEntry = MTPNP_FALSE;
    SlaveduplicateEntry = MTPNP_FALSE;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_move_confirm.>\n", __FILE__,
                         __LINE__);

    if ((g_phb_name_index[g_phb_cntx.active_index] < mmi_phb_get_max_pb_phone_entries())
        && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= mmi_phb_get_max_pb_phone_entries())
             && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
    }
    else
    {
        DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                       STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_MOVE_QUERY_MSG), IMG_GLOBAL_QUESTION, WARNING_TONE);

        SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_Move_Dup_SIM2Phone_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void MTPNP_Slave_PB_Copy_SIM2SIM_confirm(void)
{
    SlavecopyEntry = MTPNP_TRUE;
    SlavemoveEntry = MTPNP_FALSE;
    SlaveduplicateEntry = MTPNP_FALSE;

    if ((g_phb_name_index[g_phb_cntx.active_index] < (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries()))
        && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);

    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries()))
             && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
    }
    else
    {
        DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                       STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_COPY_QUERY_MSG), IMG_GLOBAL_QUESTION, WARNING_TONE);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_Move_Dup_SIM2SIM_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
}

void MTPNP_Slave_PB_Move_SIM2SIM_confirm(void)
{
    SlavemoveEntry = MTPNP_TRUE;
    SlavecopyEntry = MTPNP_FALSE;
    SlaveduplicateEntry = MTPNP_FALSE;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_move_confirm.>\n", __FILE__,
                         __LINE__);

    if ((g_phb_name_index[g_phb_cntx.active_index] >= (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries()))
        && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= mmi_phb_get_max_pb_phone_entries() && g_phb_name_index[g_phb_cntx.active_index] < (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries()))
        && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
    }
    else
    {
        DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                       STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_MOVE_QUERY_MSG), IMG_GLOBAL_QUESTION, WARNING_TONE);

        SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_Move_Dup_SIM2SIM_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

void MTPNP_Slave_PB_Duplicate_confirm(void)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
        /*----------------------------------------------------------------*/
    MTPNP_UINT16 store_index;
    MTPNP_UINT16 str_id = 0;

    SlaveduplicateEntry = MTPNP_TRUE;
    SlavecopyEntry = MTPNP_FALSE;
    SlavemoveEntry = MTPNP_FALSE;
    store_index = g_phb_name_index[g_phb_cntx.active_index];

    if (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity())
    {
        str_id = STRING_MTPNP_SIM2_STORAGE_FULL;
    }
    if (str_id != 0)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(str_id), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                   STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_DUPLICATE_QUERY_MSG), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_Move_Dup_SIM2Phone_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_Slave_PB_Copy_Move_Dup_SIM2Phone_req(void)
{
    U16 store_index;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_req.>\n", __FILE__,
                         __LINE__);
    store_index = g_phb_name_index[g_phb_cntx.active_index];
    if ((store_index >= (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())) && (!SlaveduplicateEntry)) /*Slave SIM Copy OR Move to Phone */
    {                           /*Copy OR Move to PHONE */
        MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
        MYQUEUE Message;
        myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT *) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;
        myMsgPtr->list.index = 0xFFFF;
        myMsgPtr->list.record_index = 0xFFFF;
        if (SlavecopyEntry)
        {
            mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        }
        else if (SlavemoveEntry)
        {
            SlavemoveEntryStoreIndex = store_index;
            mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        }
        mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
        myMsgPtr->list.storage = MMI_NVRAM;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType *) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        SetProtocolEventHandler(MTPNP_Slave_PB_Copy_Move_Dup_rsp, PRT_PHB_SET_ENTRY_RSP);
        OslMsgSendExtQueue(&Message);
    }
    else
    {                           /*Copy or Move to Slave SIM */
        MTPNP_UINT8 ton_npi;
        E_MTPNP_CODING_SCHEME coding_scheme;

        MTPNP_CHAR *name_buff;
        MTPNP_CHAR *number_buff;
        name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
        MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);

        if (SlavecopyEntry)
        {
            mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        }
        else if (SlavemoveEntry)
        {
            SlavemoveEntryStoreIndex = store_index;
            mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        }
        else
            mmi_phb_show_in_progress(STR_PHB_DUPLICATING, IMG_ENTRY_DUPLICATED_MSG);

        if (GetUCS2Flag((PS8)PhoneBook[store_index].alpha_id.name))
        {
            coding_scheme = MTPNP_CODING_SCHEME_UCS2;
            MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) name_buff,
                                           (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                                           (MTPNP_INT) MTPNP_AD_ADN_SIM2GetUCS2LenSupport());

        }
        else
        {
            coding_scheme = MTPNP_CODING_SCHEME_ASCII;
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) name_buff, (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                            (MTPNP_INT) MTPNP_AD_ADN_SIM2GetTagSupport() << 1);

        }

        if (PhoneBook[store_index].tel.number[0] == '+')
        {
            ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }
        else
        {
            ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }


        MTPNP_AD_Add_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi);

        MTPNP_OSAL_memfree(name_buff);
        name_buff = MTPNP_NULL;
        MTPNP_OSAL_memfree(number_buff);
        number_buff = MTPNP_NULL;

    }
    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
    DeleteNScrId(SCR_CARD2_PHB_COPY);

}

void MTPNP_Slave_PB_Copy_Move_Dup_SIM2SIM_req(void)
{
    MTPNP_UINT16 store_index;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_req.>\n", __FILE__,
                         __LINE__);
    store_index = g_phb_name_index[g_phb_cntx.active_index];
    if ((store_index >= (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())) && (!SlaveduplicateEntry)) /*Slave SIM Copy OR Move to Phone */
    {                           /*Copy OR Move to PHONE */
        MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
        MYQUEUE Message;
        myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT *) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;
        myMsgPtr->list.index = 0xFFFF;
        myMsgPtr->list.record_index = 0xFFFF;
        if (SlavecopyEntry)
        {
            mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        }
        else if (SlavemoveEntry)
        {
            SlavemoveEntryStoreIndex = store_index;
            mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        }
        mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
        myMsgPtr->list.storage = MMI_SIM;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType *) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        SetProtocolEventHandler(MTPNP_Slave_PB_Copy_Move_Dup_rsp, PRT_PHB_SET_ENTRY_RSP);
        OslMsgSendExtQueue(&Message);
    }
    else
    {                           /*Copy or Move to Slave SIM */
        MTPNP_UINT8 ton_npi;
        E_MTPNP_CODING_SCHEME coding_scheme;

        MTPNP_CHAR *name_buff;
        MTPNP_CHAR *number_buff;
        name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
        MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);

        if (SlavecopyEntry)
        {
            mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        }
        else if (SlavemoveEntry)
        {
            SlavemoveEntryStoreIndex = store_index;
            mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        }
        else
        {
            mmi_phb_show_in_progress(STR_PHB_DUPLICATING, IMG_ENTRY_DUPLICATED_MSG);
        }

        if (GetUCS2Flag((PS8)PhoneBook[store_index].alpha_id.name))
        {
            coding_scheme = MTPNP_CODING_SCHEME_UCS2;
            MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) name_buff,
                                           (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                                           MTPNP_AD_ADN_SIM2GetUCS2LenSupport());
        }
        else
        {
            coding_scheme = MTPNP_CODING_SCHEME_ASCII;
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) name_buff, (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                            (MTPNP_INT) MTPNP_AD_ADN_SIM2GetTagSupport() << 1);
        }

        if (PhoneBook[store_index].tel.number[0] == '+')
        {
            ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number + ENCODING_LENGTH,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }
        else
        {
            ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }

        MTPNP_AD_Add_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi);

        MTPNP_OSAL_memfree(name_buff);
        name_buff = MTPNP_NULL;
        MTPNP_OSAL_memfree(number_buff);
        number_buff = MTPNP_NULL;
    }
    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
    DeleteNScrId(SCR_CARD2_PHB_COPY);
}

void MTPNP_Slave_PB_Copy_Move_Dup_rsp(void *info)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    MTPNP_UINT8 modified;
    MTPNP_UINT8 flag = 0;
    MTPNP_UINT8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    MTPNP_INT16 pError;
    MTPNP_UINT16 store_index, src_store_index;

    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT *) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0 /*OK*/)
    {

        src_store_index = g_phb_name_index[g_phb_cntx.active_index];

        store_index =
            mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);

        if (SlavecopyEntry || SlavemoveEntry)
        {
            if (localPtr->list[0].storage == MMI_NVRAM) /* From Slave SIM to NVRAM */
            {
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
                /*Optional Fields */
                memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
                WriteRecord(NVRAM_EF_PHB_FIELDS_LID, (U16) (localPtr->list[0].record_index),
                            (void *) &PhoneBookOptionalFields, OPTIONAL_FIELDS_RECORD_SIZE, &pError);
#endif
                /*Clear Optional Selection Fields */
                mmi_phb_clear_optional_ids(store_index);

                /*Clear video field. */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
                mmi_phb_video_delete_by_index(store_index);
#endif
                /*Clear birthday field */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                mmi_phb_bday_delete_field(store_index);
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
                mmi_phb_info_delete_field(store_index);
#endif

            }

#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
            mmi_phb_copy_optional_ids(store_index, g_phb_name_index[Slave_g_phb_mass_op_index]);

            if (localPtr->list[0].storage == MMI_SIM)
            {
                mmi_phb_clear_optional_ids_for_sim(store_index);
            }
#endif

        }
        modified = PhoneBook[src_store_index].alpha_id.name_length - localPtr->list[0].alpha_id.name_length;
        mmi_phb_convert_to_digit(num_ascii, PhoneBook[src_store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
        flag += mmi_phb_op_increase_lookup_table(store_index, (S8 *) num_ascii, NULL, NULL, NULL);
        if (flag)
            mmi_phb_lookup_table_sort();
        //mmi_phb_op_set_entry_rsp_name_number(info, store_index);
        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        mmi_phb_op_update_field_flag(store_index, (S8 *) localPtr->list[0].tel.number, NULL, NULL, NULL, NULL, TRUE);
#else
        mmi_phb_op_update_field_flag(store_index,
                                     (S8 *) localPtr->list[0].tel.number,
                                     (S8 *) PhoneBookOptionalFields.homeNumber,
                                     (S8 *) PhoneBookOptionalFields.officeNumber,
                                     (S8 *) PhoneBookOptionalFields.faxNumber,
                                     (S8 *) PhoneBookOptionalFields.emailAddress, MTPNP_TRUE);
#endif
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
#if defined(__MMI_PHB_PINYIN_SORT__)    /*Update Pinyin Cache for sort */
        mmi_phb_util_make_pinyin_cache(store_index);
#endif
        /*Insert name index to name sorting mapping table. */
        mmi_phb_sort_insert_name_index(store_index);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

        /*Insert email index to email sorting mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
        if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))      /* From SIM to NVRAM */
            mmi_phb_sort_email_insert_index(store_index);
#endif

        /*add central command for vrsi. */
#if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_add_single(store_index);
#endif
        if (SlavemoveEntry)
        {
            MTPNP_UINT16 delete_index = SlavemoveEntryStoreIndex - mmi_phb_get_max_pb_phone_entries() - mmi_phb_get_max_pb_sim_entries() + 1;
            SlavemoveModified = modified;
            SlavemoveEntryStoreIndex = store_index;
            MTPNP_AD_DELETE_ADN_Record((MTPNP_UINT16) (delete_index));
        }
        else
        {
            if (modified)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_COPIED_NAME_MODIFIED), IMG_GLOBAL_ACTIVATED, MTPNP_TRUE,
                             PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
            }
            else
            {
                if ((SlavecopyEntry || SlaveduplicateEntry) && localPtr->list[0].storage == MMI_NVRAM)
                {
                    DisplayPopup((MTPNP_UINT8 *) GetString(STR_COPIED_TO_PHONE_DONE), IMG_GLOBAL_ACTIVATED, MTPNP_TRUE,
                                 PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
                }
                else if ((SlavecopyEntry || SlaveduplicateEntry) && localPtr->list[0].storage == MMI_SIM)
                {
                    DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_PHB_COPY_TO_SIM1_DONE), IMG_GLOBAL_ACTIVATED, MTPNP_TRUE,
                                 PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
                }
            }
        }
    }
    else
    {
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
        {
            if (SlavecopyEntry)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_NOT_COPIED_NUMBER_TOO_LONG), IMG_GLOBAL_ERROR, MTPNP_FALSE,
                             PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
            else if (SlavemoveEntry)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_NOT_MOVED_NUMBER_TOO_LONG), IMG_GLOBAL_ERROR, MTPNP_FALSE,
                             PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
            else if (SlaveduplicateEntry)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_NOT_DUPLICATED_NUMBER_TOO_LONG), IMG_GLOBAL_ERROR, FALSE,
                             PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
        }
        else if (localPtr->list[0].storage != MMI_NVRAM && gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
        {
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            return;
        }
        else
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, TRUE,
                         PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        }
    }
    SlavecopyEntry = SlaveduplicateEntry = MTPNP_FALSE; //SlavemoveEntry = MTPNP_FALSE;
}

void Card2_ADN_entry_op_edit_entry(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT16 inputBufferSize;
    MTPNP_UINT8 item_index = 0;
    MTPNP_UINT16 DetailPbNameImageList[MAX_PB_FIELDS];
    MTPNP_UINT16 store_index;
    MTPNP_UINT16 image_id;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<Slave_mmi_phb_entry_op_edit_entry.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_SLAVE_INLINE_EDIT, CARD2_ADN_exit_op_edit_entry, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_SLAVE_INLINE_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_SLAVE_INLINE_EDIT, &inputBufferSize);

    /*Fill name and number field */
    if (0xFFFF == g_phb_cntx.active_index)      //for add
    {
        memset(pbNumber, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(pbName, 0, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
    }
    else
    {
        store_index = g_phb_name_index[g_phb_cntx.active_index];
        MTPNP_PFAL_Unicode_String_Copy(pbName, (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name);
        mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
    }
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif

    card2_mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NAME, item_index++, store_index, TitleStrings,
                                      DetailPbNameImageList);
    card2_mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NUMBER, item_index++, store_index, TitleStrings,
                                      DetailPbNameImageList);

    if (inputBuffer != MTPNP_NULL)
    {
        SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
    }
    image_id = IMG_ID_CARD2_PHB_STORAGE_SIM;

    ShowCategory57Screen(STR_SCR_INLINE_EDIT_CAPTION,
                         image_id,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, item_index, DetailPbNameImageList, wgui_inline_items, 0, guiBuffer);

    if (0xFFFF == g_phb_cntx.active_index)      //for add
        SetCategory57RightSoftkeyFunctions(CARD2_ADN_add_save_confirm, GoBackHistory);
    else
        SetCategory57RightSoftkeyFunctions(CARD2_ADN_edit_save_confirm, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }
}

void CARD2_ADN_exit_op_edit_entry(void)
{
    history h;
    MTPNP_UINT16 inputBufferSize;

    g_phb_cntx.end_scr_id = SCR_SLAVE_INLINE_EDIT;

    mmi_phb_stop_ring_tone_id();
    CloseCategory57Screen();
    h.scrnID = SCR_SLAVE_INLINE_EDIT;
    h.entryFuncPtr = Card2_ADN_entry_op_edit_entry;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (MTPNP_UINT16) GetCategory57DataSize();
    GetCategory57Data((MTPNP_UINT8 *) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}

void CARD2_ADN_add_save_confirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GLOBAL_SAVE), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SlavemoveEntry = MTPNP_FALSE;
    SlavecopyEntry = MTPNP_FALSE;
    SlaveduplicateEntry = MTPNP_FALSE;

    SetLeftSoftkeyFunction(CARD2_ADN_edit_pre_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_3_history_and_clear, KEY_EVENT_UP);
}

void CARD2_ADN_edit_save_confirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   get_string(STR_GLOBAL_SAVE_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(CARD2_ADN_edit_pre_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);
}

void CARD2_ADN_edit_pre_save(void)
{
    if (!mmi_phb_op_check_pre_save(MTPNP_TRUE))
    {
        return;
    }
    mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    if (0xFFFF == g_phb_cntx.active_index)      //add
    {
        MTPNP_PFAL_ADN_AddEntry();
    }
    else
    {
        MTPNP_PFAL_ADN_EDITEntry((MTPNP_UINT16)
                                 (g_phb_name_index[g_phb_cntx.active_index] + 1 - mmi_phb_get_max_pb_phone_entries() -
                                  mmi_phb_get_max_pb_sim_entries()));
    }
}

void MTPNP_PFAL_ADN_EDITEntry(MTPNP_UINT16 index)
{
    MTPNP_UINT8 ton_npi;
    E_MTPNP_CODING_SCHEME coding_scheme;
    MTPNP_CHAR *name_buff;
    MTPNP_CHAR *number_buff;
    name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
    MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
    number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
    MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
    if (GetUCS2Flag(pbName))
    {
        coding_scheme = MTPNP_CODING_SCHEME_UCS2;
        MTPNP_PFAL_Unicode_Memory_Copy(name_buff, pbName, MTPNP_AD_ADN_SIM2GetUCS2LenSupport());

    }
    else
    {
        coding_scheme = MTPNP_CODING_SCHEME_ASCII;
        MTPNP_PFAL_Unicode_To_Ansii_String(name_buff, pbName);
    }


    if (pbNumber[0] == '+')
    {
        ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, pbNumber + ENCODING_LENGTH);
    }
    else
    {
        ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, pbNumber);
    }


    MTPNP_AD_Edit_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi, index);
    MTPNP_OSAL_memfree(name_buff);
    name_buff = MTPNP_NULL;
    MTPNP_OSAL_memfree(number_buff);
    number_buff = MTPNP_NULL;

}

void MTPNP_PFAL_ADN_AddEntry(void)
{
    MTPNP_UINT8 ton_npi;
    E_MTPNP_CODING_SCHEME coding_scheme;
    MTPNP_CHAR *name_buff;
    MTPNP_CHAR *number_buff;

    name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
    MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
    number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
    MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);

    if (GetUCS2Flag(pbName))
    {
        coding_scheme = MTPNP_CODING_SCHEME_UCS2;
        MTPNP_PFAL_Unicode_Memory_Copy(name_buff, pbName, MTPNP_AD_ADN_SIM2GetUCS2LenSupport());

    }
    else
    {
        coding_scheme = MTPNP_CODING_SCHEME_ASCII;
        MTPNP_PFAL_Unicode_To_Ansii_String(name_buff, pbName);
    }

    if (pbNumber[0] == '+')
    {
        ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, pbNumber + ENCODING_LENGTH);
    }
    else
    {
        ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, pbNumber);
    }

    MTPNP_AD_Add_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi);

    MTPNP_OSAL_memfree(name_buff);
    name_buff = MTPNP_NULL;
    MTPNP_OSAL_memfree(number_buff);
    number_buff = MTPNP_NULL;

}

void MTPNP_PFAL_ADN_Slave_AddToSortIndex(U16 index)
{
    g_phb_name_index[PhoneBookEntryCount] = index;
    PhoneBookEntryCount++;
}

void MTPNP_PFAL_ADN_HandleReadSuccessEntry(ST_MTPNP_DATA_PB_RECORD_INFO * info)
{
    //on the UI layer name is UCS coding Number, is BCD coding
    MTPNP_UINT16 store_index;
    store_index = mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries() + info->index.idx - 1;

    if (store_index >= mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim2_entries())
    {
        return;
    }
   
    if (0 == info->name[0])
    {
        PhoneBook[store_index].alpha_id.name_length = 0;
    }
    else
    {
        PhoneBook[store_index].alpha_id.name_length = info->name_length;
        switch (info->coding_scheme)
        {
        case MTPNP_CODING_SCHEME_ASCII:
            PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_ASCII;
            MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                                               (MTPNP_CHAR *) info->name);

            break;
        case MTPNP_CODING_SCHEME_UCS2:
            PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
            MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                                           (MTPNP_CHAR *) info->name, PhoneBook[store_index].alpha_id.name_length);

            break;
        case MTPNP_CODING_SCHEME_DEFAULT:
        case MTPNP_CODING_SCHEME_GB2312:
        case MTPNP_CODING_SCHEME_BIG5:
        case MTPNP_CODING_SCHEME_UNKNOWN:
            return;
        }
    }

    /* zhangnan add */
    if (PhoneBook[store_index].alpha_id.name_length == 0 || (info->name[0] == 0xff && info->name[1] == 0xff))
    {
        MTPNP_OSAL_memset(PhoneBook[store_index].alpha_id.name, 0, 2);
    }
    else
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    /* add end */

    if (0 == info->number[0])
    {
        PhoneBook[store_index].tel.length = 0;
        PhoneBook[store_index].tel.number[0] = 0xff;
    }
    else
    {
        PhoneBook[store_index].tel.type = info->TON_NPI;
        PhoneBook[store_index].tel.length = strlen((S8 *) info->number);
        mmi_phb_convert_to_bcd(PhoneBook[store_index].tel.number, info->number, (MAX_PB_NUMBER_LENGTH + 1) / 2);
    }

    /* zhangnan add */
    if ((PhoneBook[store_index].tel.number[0] & 0x0f) != 0x0f)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }
    /* add end */

#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif

    MTPNP_PFAL_ADN_Slave_AddToSortIndex(store_index);
}

void MTPNP_PFAL_ADN_HandleAddSuccess(MTPNP_UINT16 index, MTPNP_UINT16 name_length)
{
    MTPNP_UINT16 store_index, src_store_index;
    MTPNP_UINT8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    MTPNP_UINT8 inputNumLen = 0;
    MTPNP_UINT8 flag = 0;
    MTPNP_UINT8 modified;
    MTPNP_CHAR *in_num = pbNumber;

    MTPNP_OSAL_memset(num_ascii, 0, MAX_PB_NUMBER_LENGTH + 1 + 1);
    store_index = index - 1 + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries();
    MTPNP_OSAL_memset(&PhoneBook[store_index], 0, sizeof(MMI_PHB_ENTRY_BCD_STRUCT));
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    if (SlavemoveEntry)
    {
    }
    else if (Slave_CopyAll)
    {
        Slave_g_phb_mass_op_count++;
    }
    else if (SlavecopyEntry)
    {
    }
    else if (SlaveduplicateEntry)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_PHB_COPY_TO_SIM2_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                     SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                     SUCCESS_TONE);
    }
    if (SlavemoveEntry || SlavecopyEntry)
    {
        src_store_index = g_phb_name_index[g_phb_cntx.active_index];

        if (PhoneBook[src_store_index].tel.length != 0)
        {
            PhoneBook[store_index].tel.type = PhoneBook[src_store_index].tel.type;
            PhoneBook[store_index].tel.length = PhoneBook[src_store_index].tel.length;
            MTPNP_OSAL_memcpy(PhoneBook[store_index].tel.number, PhoneBook[src_store_index].tel.number,
                              PhoneBook[src_store_index].tel.length);
        }
        else
        {
            //PhoneBook[store_index].tel.length=0;
            PhoneBook[store_index].tel.number[0] = 0xff;
        }
        if (PhoneBook[src_store_index].alpha_id.name_length != 0)
        {
            if (MMI_PHB_ASCII == PhoneBook[src_store_index].alpha_id.name_dcs)
            {
                U32 length =
                    PhoneBook[src_store_index].alpha_id.name_length >
                    MTPNP_AD_ADN_SIM2GetTagSupport()? MTPNP_AD_ADN_SIM2GetTagSupport() : PhoneBook[src_store_index].
                    alpha_id.name_length;
                PhoneBook[store_index].alpha_id.name_length = length;
                PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_ASCII;
                MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, PhoneBook[src_store_index].alpha_id.name,
                                  length << 1);
            }
            else
            {
                U32 length =
                    PhoneBook[src_store_index].alpha_id.name_length >
                    (MTPNP_AD_ADN_SIM2GetUCS2LenSupport() << 1) ? (MTPNP_AD_ADN_SIM2GetUCS2LenSupport() << 1) :
                    PhoneBook[src_store_index].alpha_id.name_length;
                PhoneBook[store_index].alpha_id.name_length = length;
                PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
                MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, PhoneBook[src_store_index].alpha_id.name,
                                  length);
            }
        }

        modified = PhoneBook[src_store_index].alpha_id.name_length - PhoneBook[store_index].alpha_id.name_length;
        if (SlavecopyEntry)
        {
            if (modified)
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STR_COPIED_NAME_MODIFIED), IMG_GLOBAL_ACTIVATED, TRUE,
                             PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
            }
            else
            {
                DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_PHB_COPY_TO_SIM2_DONE), IMG_GLOBAL_ACTIVATED, TRUE,
                             PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
            }
        }
        else
        {
            SlavemoveModified = modified;
            MTPNP_PFAL_phb_op_move_req();
        }

        SlavemoveEntry = SlavecopyEntry = FALSE;
    }
    else if (Slave_CopyAll)
    {
        src_store_index = g_phb_name_index[Slave_g_phb_mass_op_index];
        if (PhoneBook[src_store_index].tel.length != 0)
        {
            PhoneBook[store_index].tel.type = PhoneBook[src_store_index].tel.type;
            PhoneBook[store_index].tel.length = PhoneBook[src_store_index].tel.length;
            MTPNP_OSAL_memcpy(PhoneBook[store_index].tel.number, PhoneBook[src_store_index].tel.number,
                              PhoneBook[src_store_index].tel.length);
        }
        else
        {
            PhoneBook[store_index].tel.length = 0;
            PhoneBook[store_index].tel.number[0] = 0xff;
        }
        if (PhoneBook[src_store_index].alpha_id.name_length != 0)
        {
            if (MMI_PHB_ASCII == PhoneBook[src_store_index].alpha_id.name_dcs)
            {
                MTPNP_INT length =
                    PhoneBook[src_store_index].alpha_id.name_length >
                    MTPNP_AD_ADN_SIM2GetTagSupport()? MTPNP_AD_ADN_SIM2GetTagSupport() : PhoneBook[src_store_index].
                    alpha_id.name_length;
                PhoneBook[store_index].alpha_id.name_length = length;
                PhoneBook[store_index].alpha_id.name_dcs = PhoneBook[src_store_index].alpha_id.name_dcs;
                MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, PhoneBook[src_store_index].alpha_id.name,
                                  length << 1);
            }
            else
            {
                MTPNP_INT length =
                    PhoneBook[src_store_index].alpha_id.name_length >
                    (MTPNP_AD_ADN_SIM2GetUCS2LenSupport() << 1) ? (MTPNP_AD_ADN_SIM2GetUCS2LenSupport() << 1) :
                    PhoneBook[src_store_index].alpha_id.name_length;
                PhoneBook[store_index].alpha_id.name_length = length;
                PhoneBook[store_index].alpha_id.name_dcs = PhoneBook[src_store_index].alpha_id.name_dcs;
                MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, PhoneBook[src_store_index].alpha_id.name,
                                  length);
            }
        }
    }
    else if (SlaveduplicateEntry)
    {
        SlaveduplicateEntry = FALSE;
        MTPNP_OSAL_memcpy(&PhoneBook[store_index], &PhoneBook[g_phb_name_index[g_phb_cntx.active_index]],
                          sizeof(MMI_PHB_ENTRY_BCD_STRUCT));
        PhoneBook[store_index].alpha_id.name_dcs =
            PhoneBook[g_phb_name_index[g_phb_cntx.active_index]].alpha_id.name_dcs;
    }
    else
    {
        if (MTPNP_PFAL_Unicode_String_Length(in_num) != 0)
        {
            /*Prepate Number Data */
            if (in_num[0] == '+')
            {
                PhoneBook[store_index].tel.type = 0x91; /* INTERNATIONAL */
                PhoneBook[store_index].tel.length = (MTPNP_UINT8) MTPNP_PFAL_Unicode_String_Length(in_num + ENCODING_LENGTH);   /* Exclude "+" */
                MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *) num_ascii, in_num + ENCODING_LENGTH);
            }
            else
            {
                PhoneBook[store_index].tel.type = 0x81;
                /*DEFAULT*/ PhoneBook[store_index].tel.length = (MTPNP_UINT8) MTPNP_PFAL_Unicode_String_Length(in_num);
                MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *) num_ascii, in_num);
            }
        }
        mmi_phb_convert_to_bcd(PhoneBook[store_index].tel.number, num_ascii, (MAX_PB_NUMBER_LENGTH + 1) / 2);
        if (GetUCS2Flag(pbName))
        {
            PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
            inputNumLen = MTPNP_PFAL_Unicode_String_Length(pbName) * ENCODING_LENGTH;
        }
        else
        {
            PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_ASCII;
            inputNumLen = MTPNP_PFAL_Unicode_String_Length(pbName);
        }

        PhoneBook[store_index].alpha_id.name_length = name_length;
        if (MMI_PHB_UCS2 == PhoneBook[store_index].alpha_id.name_dcs)
        {
            MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, pbName,
                              PhoneBook[store_index].alpha_id.name_length);
        }
        else
        {
            MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, pbName,
                              PhoneBook[store_index].alpha_id.name_length << 1);
        }
    }

    if (PhoneBook[store_index].alpha_id.name_length == 0)
    {
        MTPNP_OSAL_memset(PhoneBook[store_index].alpha_id.name, 0, 2);
    }

    /* add end */
#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif

    /*Insert name to name mapping table. */
    if (!Slave_CopyAll)         //caution donot build sort when copy all
        mmi_phb_sort_insert_name_index(store_index);
    else
    {
        g_phb_name_index[PhoneBookEntryCount] = store_index;
        PhoneBookEntryCount++;
    }
    mmi_phb_convert_to_digit(num_ascii, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    flag += mmi_phb_op_increase_lookup_table(store_index, (S8 *) num_ascii, NULL, NULL, NULL);
    if (flag)
        mmi_phb_lookup_table_sort();
    mmi_phb_op_update_field_flag(store_index, (S8 *) (S8 *) num_ascii, NULL, NULL, NULL, NULL, TRUE);

    if (PhoneBook[store_index].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }

    if (Slave_CopyAll)
    {
        if (Slave_g_phb_mass_op_abort)
        {
            Slave_g_phb_mass_op_success = MTPNP_FALSE;
            MTPNP_Slave_PB_copy_all_done();
        }
        else
        {

            if ((g_phb_cntx.selected_storage == MMI_NVRAM) &&
                (Slave_g_phb_mass_op_count < g_phb_cntx.phone_used) &&
                (MTPNP_AD_ADN_SIM2GetUsedNumber() < MTPNP_AD_ADN_SIM2GetCapacity()))
            {
                Slave_g_phb_mass_op_index++;
                MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(MMI_NVRAM);
            }
            else if ((g_phb_cntx.selected_storage == MMI_SIM) && 
                (Slave_g_phb_mass_op_count < g_phb_cntx.sim_used) &&
                (MTPNP_AD_ADN_SIM2GetUsedNumber() < MTPNP_AD_ADN_SIM2GetCapacity()))
            {
                Slave_g_phb_mass_op_index++;
                MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(MMI_SIM);
            }
            else
            {
                if (((g_phb_cntx.selected_storage == MMI_NVRAM && Slave_g_phb_mass_op_count < g_phb_cntx.phone_used) ||
                    (g_phb_cntx.selected_storage == MMI_SIM && Slave_g_phb_mass_op_count < g_phb_cntx.sim_used)) && 
                    MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity())
                {
                    Slave_g_phb_mass_op_success = MTPNP_FALSE;
                }
                MTPNP_Slave_PB_copy_all_done();
            }
        }
    }

    DeleteScreenIfPresent(SCR_ADD_NEW_ENTRY);
    DeleteScreenIfPresent(SCR_STORAGE_LOCATION_MENU);   //storage location
    DeleteScreenIfPresent(SCR_ID_PHB_FMGR_SAVE_OPTION);
   // g_phb_cntx.processing = MTPNP_FALSE;
#if defined(__MMI_VCARD__)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
    {
        DeleteScreenIfPresent(SCR_ID_VCARD_RECV_VIEW_DETAIL);
        DeleteScreenIfPresent(SCR_ID_VCARD_RECV_OPT);
        DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);
        mmi_vobj_clear_one_file_buffer();
    }
#endif /* defined(__MMI_VCARD__) */
}

void MTPNP_PFAL_ADN_HandleUnload(void)
{
}

void MTPNP_PFAL_ADN_HandleDelSuccess(MTPNP_UINT16 index)
{
    MTPNP_UINT16 store_index;
    MTPNP_UINT16 deletedCnt = 0;

    store_index = index - 1 + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries();
    mmi_phb_op_delete_update_index(store_index);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    PhbUpdateSpeedDial(MMI_SIM2, index, MMI_PHB_PHONEBOOK, NULL, NULL);

    if (SlavemoveEntry)
    {
        SlavemoveEntry = MTPNP_FALSE;
        if (SlavemoveEntryStoreIndex >= mmi_phb_get_max_pb_phone_entries())
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_PHB_MOVE_TO_SIM1_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                         SUCCESS_TONE);
        }
        else
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_MOVED_TO_PHONE_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                         SUCCESS_TONE);
        }
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                     SUCCESS_TONE);
    }

    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);

    if (!PhoneBookEntryCount)
        DeleteNScrId(SCR_PBOOK_LIST);

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    /*Change highlight position. */
    if (g_phb_cntx.active_index == (PhoneBookEntryCount - 1))
    {
        g_phb_cntx.new_highlight_entry = 0;
    }

    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    if (deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    DeleteScreenIfPresent(SCR_DELETE_ENTRY_QUERY);
    DeleteScreenIfPresent(SCR_PBOOK_ENTRY_OPTIONS);
    DeleteScreenIfPresent(MITEM1012_PBOOK_DELETE);
}

void MTPNP_PFAL_ADN_HandleDelFail(MTPNP_UINT16 index)
{
    if (MTPNP_AD_FDN_GetStatus())
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, MTPNP_TRUE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}

void MTPNP_PFAL_ADN_HandleDelAllOneAfterOneSuccess(void *data)
{
    MTPNP_UINT16 store_index;
    MTPNP_UINT16 index;
    ST_MTPNP_DATA_ADN_IS_DELETE_ALL *info=(ST_MTPNP_DATA_ADN_IS_DELETE_ALL *)data;

    index = info->index;
    store_index = index - 1 + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries();

    PhbUpdateSpeedDial(MMI_SIM2, index, MMI_PHB_PHONEBOOK, NULL, NULL);
    Slave_g_phb_mass_op_lookup_count += mmi_phb_op_clear_lookup_table_by_index(store_index);

#if defined(__MMI_VRSD_DIAL__)
    /* remove voice dial tag if exists. */
    mmi_vrsddial_delete_tag_by_store_index(store_index);
#endif /* defined(__MMI_VRSD_DIAL__) */
    mmi_phb_op_delete_update_index(store_index);
    Slave_g_phb_mass_op_count++;

    if (Slave_g_phb_mass_op_abort)
    {
        MTPNP_PFAL_ADN_set_slave_mass_op_success_flag(MTPNP_FALSE);
        MTPNP_PFAL_ADN_HandleDelAllAbort();
    }
    else
    {
        index = MTPNP_AD_ADN_GetNextValidIndex(index);
        if (0xFFFF == index)
        {	 
            MTPNP_AD_ADN_DelAllFinish(MTPNP_NULL);
        }
        else
        {
            info->index = index;
            MTPNP_AD_ADN_DelAllOneAfterOneReq((void *)data);
        }
    }
}

void MTPNP_PFAL_ADN_HandleDelAllAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 outBuf[100], count[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.processing = FALSE;
    TurnOnBacklight(1); /* Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Sort lookup table */
    if (Slave_g_phb_mass_op_lookup_count)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= Slave_g_phb_mass_op_lookup_count;
    }

    /* No need to clear video id, because it will reset when set new entry */

    /* Display result */
    Slave_g_phb_mass_delall = MTPNP_FALSE;
    Slave_g_phb_mass_op_success = TRUE;
    sprintf(count, "%d ", Slave_g_phb_mass_op_count);
    mmi_asc_to_ucs2(outBuf, count);
    if (Slave_g_phb_mass_op_count <= 1)
    {
        mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRY_DELETED));
    }
    else
    {
        mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRIES_DELETED));
    }
    DisplayPopup((U8*) outBuf, IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

    /* Solve Copying Screen Hang Problem */
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);

    /* Re-add all central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();

    /* Also remove SD tag if entry is deleted. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_ndial_central_update_sd_mapping();
#endif 

    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}

void MTPNP_PFAL_ADN_HandleEditSuccess(MTPNP_UINT16 index, MTPNP_UINT16 name_length)
{
    MTPNP_UINT16 deletedCnt = 0;
    MTPNP_UINT8 flag = 0;
    MTPNP_UINT16 store_index;
    MTPNP_UINT8 storage;
    MTPNP_UINT8 inputNumLen;
    MTPNP_CHAR *in_num = pbNumber;
    MTPNP_UINT8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT,
                 SUCCESS_TONE);
    store_index = g_phb_name_index[g_phb_cntx.active_index];
    kal_mem_set(&PhoneBook[store_index], 0, sizeof(MMI_PHB_ENTRY_BCD_STRUCT));
    storage = MMI_SIM2;

    /* Clear lookup table first, add later if exists. */
    MTPNP_OSAL_memset(num_ascii, 0, MAX_PB_NUMBER_LENGTH + 1 + 1);
    if (MTPNP_PFAL_Unicode_String_Length(in_num) != 0)
    {
        /*Prepate Number Data */
        if (in_num[0] == '+')
        {
            PhoneBook[store_index].tel.type = 0x91;     /* INTERNATIONAL */
            PhoneBook[store_index].tel.length = (U8) MTPNP_PFAL_Unicode_String_Length(in_num + ENCODING_LENGTH);        /* Exclude "+" */
            MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *) num_ascii, in_num + ENCODING_LENGTH);
        }
        else
        {
            PhoneBook[store_index].tel.type = 0x81;
            /*DEFAULT*/ PhoneBook[store_index].tel.length = (U8) MTPNP_PFAL_Unicode_String_Length(in_num);
            MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *) num_ascii, in_num);
        }
    }
    mmi_phb_convert_to_bcd(PhoneBook[store_index].tel.number, num_ascii, (MAX_PB_NUMBER_LENGTH + 1) / 2);

    if (GetUCS2Flag(pbName))
    {
        PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_UCS2;
        inputNumLen = MTPNP_PFAL_Unicode_String_Length(pbName) * ENCODING_LENGTH;
    }
    else
    {
        PhoneBook[store_index].alpha_id.name_dcs = MMI_PHB_ASCII;
        inputNumLen = MTPNP_PFAL_Unicode_String_Length(pbName);
    }

    PhoneBook[store_index].alpha_id.name_length = name_length;
    if (MMI_PHB_UCS2 == PhoneBook[store_index].alpha_id.name_dcs)
    {
        MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, pbName, PhoneBook[store_index].alpha_id.name_length);
    }
    else
    {
        MTPNP_OSAL_memcpy(PhoneBook[store_index].alpha_id.name, pbName,
                          PhoneBook[store_index].alpha_id.name_length << 1);
    }

    PhbUpdateSpeedDial(MMI_SIM2, index, MMI_PHB_PHONEBOOK, (U8*) pbName, (U8*) pbNumber);

    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);
    /*Name sorting mapping table should Re-Sort HERE, and get the new highlight position!!! */
    mmi_phb_op_delete_update_index(store_index);

    flag += mmi_phb_op_increase_lookup_table(store_index, (S8 *) num_ascii, NULL, NULL, NULL);
    if (deletedCnt || flag)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

#if defined(__MMI_PHB_PINYIN_SORT__)    /*Update Pinyin Cache for sort */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif
    g_phb_cntx.new_highlight_entry = mmi_phb_sort_insert_name_index(store_index);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* zhangnan add */
    if (PhoneBook[store_index].alpha_id.name_length == 0)
    {
        MTPNP_OSAL_memset(PhoneBook[store_index].alpha_id.name, 0, 2);
    }
    else
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }

    if ((PhoneBook[store_index].tel.number[0] & 0x0f) != 0x0f)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }
    /* add end */

    DeleteScreenIfPresent(SCR_PBOOK_ENTRY_OPTIONS);
    DeleteScreenIfPresent(SCR_SLAVE_INLINE_EDIT);
}


void MTPNP_PFAL_ADN_HandleEditFail(MTPNP_UINT16 fail_cause)
{
    if(fail_cause == MMI_SIM_EF_RECORD_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteUptoScrID(SCR_INLINE_EDIT);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);

        mmi_phb_clear_old_edit_history();
    }
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;  
}

void MTPNP_PFAL_ADN_HandleAddFail(MTPNP_UINT16 fail_cause)
{
    if (Slave_CopyAll == MTPNP_TRUE)
    {
        Slave_g_phb_mass_op_success = FALSE;

        if ((fail_cause != MMI_PHB_CAUSE_CAPACITY_EXCEEDED) &&
            (g_phb_cntx.selected_storage == MMI_NVRAM) &&
            (Slave_g_phb_mass_op_count < g_phb_cntx.phone_used) &&
            (MTPNP_AD_ADN_SIM2GetUsedNumber() < MTPNP_AD_ADN_SIM2GetCapacity()))
        {
            Slave_g_phb_mass_op_index++;
            MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(MMI_NVRAM);
        }
        else if ((fail_cause != MMI_PHB_CAUSE_CAPACITY_EXCEEDED) &&
            (g_phb_cntx.selected_storage == MMI_SIM) && 
            (Slave_g_phb_mass_op_count < g_phb_cntx.sim_used) &&
            (MTPNP_AD_ADN_SIM2GetUsedNumber() < MTPNP_AD_ADN_SIM2GetCapacity()))
        {
            Slave_g_phb_mass_op_index++;
            MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(MMI_SIM);
        }
        else
        {
            MTPNP_Slave_PB_copy_all_done();
        }
        return;
    }

    #if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_OTHERS)
        {
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
            if (mmi_phb_add_new_entry_callback != NULL)
            {
                mmi_phb_add_new_entry_callback(MMI_PHB_OTHERS_ERROR, 0xFFFF);
            }
        }
    #endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */
        if (fail_cause == MMI_SIM_EF_RECORD_FULL)   /* Number To Long */
        {
            DisplayPopup(
                (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        #if defined(__MMI_VCARD__)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            else
        #endif /* defined(__MMI_VCARD__) */ 
                DeleteUptoScrID(SCR_ADD_NEW_ENTRY);
        }
        else if (MTPNP_AD_FDN_GetStatus())   /* For FDN on Message */
        {
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            return;
        }
        else    /* Unknown Error */
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            mmi_phb_clear_old_add_history();
        }
    #if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
		{
			extern void mmi_jdd_tapi_add_phonebook_result(JC_RETCODE ret_code);
			mmi_jdd_tapi_add_phonebook_result(JC_ERR_TAPI_PHONEBOOK_ENTRY);
		}
    #endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

}

MTPNP_BOOL MTPNP_PFAL_ADN_HandleNeedLoad(ST_MTPNP_DATA_PB_CAPACITY * info)      //to prepare Slave SIM PB
{
    MTPNP_BOOL result = MTPNP_FALSE;

    return result;
}

void MTPNP_PFAL_ADN_GetSpeedDialInfo(void)
{
    PhbGetSpeedDialInfo();      /* Retrieve Speed Dial List after retrieve FDN list, because they all use same message. */
}

MTPNP_BOOL MTPNP_PFAL_ADN_IsNeedHandlePBLoad(void)
{
    if (MTPNP_AD_SDK_Is_PowerOff())
    {
        return MTPNP_FALSE;
    }

    return MTPNP_TRUE;
}

U16 MTPNP_PFAL_ADN_GetMasterPhoneCount(void)
{
    return (U16) (g_phb_cntx.sim_used + g_phb_cntx.phone_used);
}

void MTPNP_PFAL_ADN_HandleLoadFinish(void)
{
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    PhoneBookEntryCount = MTPNP_PFAL_ADN_GetMasterPhoneCount() + MTPNP_AD_ADN_SIM2GetUsedNumber();
    //mmi_phb_sort_build_name_index();
    //mmi_phb_init_build_lookup_table();

    if (MTPNP_AD_ADN_SIM2GetTagLen() > MAX_PB_NAME_LENGTH)
    {
        MTPNP_AD_ADN_SIM2SetTagSupport(MAX_PB_NAME_LENGTH);
    }
    else
    {
        MTPNP_AD_ADN_SIM2SetTagSupport(MTPNP_AD_ADN_SIM2GetTagLen());
    }
    if (MTPNP_AD_ADN_SIM2GetNumLen() > MAX_PB_NUMBER_LENGTH)
    {
        MTPNP_AD_ADN_SIM2SetNumberSupport(MAX_PB_NUMBER_LENGTH);
    }
    else
    {
        MTPNP_AD_ADN_SIM2SetNumberSupport(MTPNP_AD_ADN_SIM2GetNumLen());
    }
    if (MTPNP_AD_FDN_GetStatus())
    {
        MTPNP_PFAL_ADN_fdn_get_list_to_ram();
    }
    else
    {
        MTPNP_PFAL_ADN_after_fdn_get_list_to_ram();
    }
//    g_phb_cntx.processing = FALSE;
}

void MTPNP_PFAL_ADN_DelAllPreReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Slave_g_phb_mass_op_index = 0;
    Slave_g_phb_mass_op_count = 0;
    Slave_g_phb_mass_op_lookup_count = 0;
    Slave_g_phb_mass_op_abort = MTPNP_FALSE;
    Slave_g_phb_mass_delall = MTPNP_TRUE;
    g_phb_cntx.processing = TRUE;

    mmi_phb_show_mass_processing(STR_GLOBAL_DELETING, IMG_GLOBAL_DELETED);
    DeleteNScrId(SCR_DELETE_ALL_MENU);

    if (MTPNP_AD_ADN_SIM2_PB_DeleteAll() != MTPNP_TRUE)
    {
        DisplayPopup((MTPNP_UINT8*)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR,  TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}

void MTPNP_PFAL_ADN_HandleDelAllDone(void)
{
    TurnOnBacklight(1); /* Turn On Back Light When done */
    /* Sort lookup table */
    if (Slave_g_phb_mass_op_lookup_count)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= Slave_g_phb_mass_op_lookup_count;
    }
    Slave_g_phb_mass_op_success = TRUE;
    Slave_g_phb_mass_delall = MTPNP_FALSE;
    g_phb_cntx.processing = FALSE;
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    DeleteScreenIfPresent(SCR_DELETE_ALL_MENU);
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT,
                 SUCCESS_TONE);

    /* Re-add all central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();
    /* Also remove SD tag if entry is deleted. */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_ndial_central_update_sd_mapping();
#endif 
    /* mmi_vrsi_init_central_add_all(); */
#endif /* defined(__MMI_VRSI__) */ 
}

void MTPNP_PFAL_ADN_HandleDelAllSuccess(void)
{
    Slave_g_phb_mass_op_success = MTPNP_TRUE;
    MTPNP_PFAL_ADN_HandleDelAllDone();
}

void MTPNP_PFAL_ADN_HandleDelAllFail(void)
{
    Slave_g_phb_mass_op_success = MTPNP_FALSE;
    MTPNP_PFAL_ADN_HandleDelAllDone();
}

void MTPNP_PFAL_ADN_Slave_Clean_Sort_index(MTPNP_UINT16 store_index)
{
    MTPNP_UINT16 pos, i;
    /*It is no need to clear entry here, because all entry display depends on name index */
    //memset(&PhoneBook[store_index], 0, sizeof(MMI_PHB_ENTRY_BCD_STRUCT));
    for (pos = 0; pos < PhoneBookEntryCount;)
    {
        if (g_phb_name_index[pos] == store_index)
        {
            for (i = pos; i < PhoneBookEntryCount - 1; i++)
            {
                g_phb_name_index[i] = g_phb_name_index[i + 1];
            }
            PhoneBookEntryCount--;
        }
        else
        {
            pos++;
        }
    }
}

void MTPNP_PFAL_ADN_HandleSlaveUnload(void)     /*to unload Slave SIM PB */
{
    MTPNP_UINT16 store_index;
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    MTPNP_OSAL_memset(&PhoneBook[mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries()], 0x00,
                      sizeof(MMI_PHB_ENTRY_BCD_STRUCT) * mmi_phb_get_max_pb_sim2_entries());
    /* zhangnan mark, the g_phb_name_pinyin_index is a static variable, if need operate it, you should operate in phonebooksearch.c */
#if 0
#if defined(__MMI_PHB_PINYIN_SORT__)
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    for (store_index = mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries(); store_index < MAX_PB_ENTRIES; store_index++)
    {
        MTPNP_PFAL_ADN_Slave_Clean_Sort_index(store_index);
    }

    /*sort Master PB, Must do. 
    if not ,when DG setting Dual mode->only master Slave PB was unload
    the Master PB wont be sorted.
    */
    g_phb_cntx.phb_ready = TRUE;
    PhoneBookEntryCount = MTPNP_PFAL_ADN_GetMasterPhoneCount();
    mmi_phb_sort_build_name_index();
    mmi_phb_init_build_lookup_table();
}

void MTPNP_PFAL_ADN_HandleAllFail(MTPNP_UINT16 DelTotal, MTPNP_UINT16 index)    //the index when an error occured
{
    MTPNP_UINT16 deletedCnt = 0;
    MTPNP_UINT16 store_index;
    MTPNP_UINT16 temp;
    MTPNP_CHAR outBuf[100], count[10];

       Slave_g_phb_mass_delall=MTPNP_FALSE;
#if 0
#if defined(__MMI_PHB_PINYIN_SORT__)
/* under construction !*/
/* under construction !*/
#endif
#endif

    MTPNP_OSAL_memset(&PhoneBook[mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries()], 0x00,
                      sizeof(MMI_PHB_ENTRY_BCD_STRUCT) *  index);

    temp = mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries() + index;
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    for (store_index = mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries(); store_index <= temp; store_index++)
    {
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);
    mmi_phb_op_delete_update_index(store_index);
    }

    if (deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }
    mmi_phb_sort_build_name_index();    //PB list sort
    g_phb_cntx.processing = MTPNP_FALSE;
    TurnOnBacklight(1);         /*Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    sprintf(count, "%d ", (MTPNP_UINT16) DelTotal);
    MTPNP_PFAL_Ansii_To_Unicode_String(outBuf, count);
    if (DelTotal <= 1)
    {
        mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRY_DELETED));
    }
    else
    {
        mmi_ucs2cat(outBuf, GetString(STR_ID_PHB_ENTRIES_DELETED));
    }
    DisplayPopup((MTPNP_UINT8 *) outBuf, IMG_GLOBAL_UNFINISHED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

}

void HighlightSlaveCopyAllSIM2toPhone(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    g_phb_cntx.selected_storage = MMI_SIM2;
    if (MTPNP_AD_ADN_SIM2GetUsedNumber() || MTPNP_AD_FDN_GetStatus())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_phone2sim_confirm, KEY_EVENT_UP);
    }
    else
        ChangeLeftSoftkey(0, 0);
}

void HighlightSlaveCopyAllPhonetoSIM2(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    g_phb_cntx.selected_storage = MMI_NVRAM;
    if (g_phb_cntx.phone_used)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_phone2sim_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}

void HighlightSlaveCopyAllSIM1toSIM2(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    g_phb_cntx.selected_storage = MMI_SIM;
    if (g_phb_cntx.sim_used || gSecuritySetupContext.FdlStatus)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_sim2sim_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}

void HighlightSlaveCopyAllSIM2toSIM1(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    g_phb_cntx.selected_storage = MMI_SIM2;
    if (MTPNP_AD_ADN_SIM2GetUsedNumber() || MTPNP_AD_FDN_GetStatus())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_sim2sim_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
    }
}

void HintSlaveCopyAllSIM2toPhone(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];
    MTPNP_CHAR ascii_status[20];
    memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    sprintf(ascii_status, "%d/%d", (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetUsedNumber(),
            (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetCapacity());
    mmi_asc_to_ucs2(simStatus, ascii_status);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);
}

void HintSlaveCopyAllPhonetoSIM2(MTPNP_UINT16 index)
{
    MTPNP_CHAR phoneStatus[40];

    memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_phone(phoneStatus);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], phoneStatus);
}

void HintSlaveCopyAllSIM2toSIM1(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];
    MTPNP_CHAR ascii_status[20];

    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    sprintf(ascii_status, "%d/%d",
            (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetUsedNumber(), (MTPNP_UINT16) MTPNP_AD_ADN_SIM2GetCapacity());
    mmi_asc_to_ucs2(simStatus, ascii_status);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);
}

void HintSlaveCopyAllSIM1toSIM2(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];

    MTPNP_OSAL_memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_sim(simStatus);
    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);
}

void MTPNP_Slave_PB_copy_all_phone2sim_confirm(void)
{
    UI_string_type message;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_confirm.>\n", __FILE__,
                         __LINE__);

    if (MTPNP_AD_FDN_GetStatus())   /* For FDN on Message */
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }
    if (g_phb_cntx.selected_storage == MMI_SIM2)
    {
        message = get_string(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM2);
        Slave_g_phb_copy_all_from_sim2_to = MMI_NVRAM;
    }
    else
    {
        message = get_string(STR_COPY_ALL_PHONE_QUERY);
    }

    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   message, IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_phone2sim_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_Slave_PB_copy_all_sim2sim_confirm(void)
{
    UI_string_type message;

    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_all_confirm.>\n", __FILE__,
                         __LINE__);

    if (gSecuritySetupContext.FdlStatus || MTPNP_AD_FDN_GetStatus())   /* For FDN on Message */
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }
    if (g_phb_cntx.selected_storage == MMI_SIM2)
    {
        message = get_string(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM2);
        Slave_g_phb_copy_all_from_sim2_to = MMI_SIM;
    }
    else
    {
        message = get_string(STRING_MTPNP_PHB_COPY_ALL_FROM_SIM1);
    }
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   message, IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_Slave_PB_copy_all_sim2sim_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_Slave_PB_copy_all_phone2sim_req(void)
{
    if ((g_phb_cntx.selected_storage == MMI_NVRAM)
        && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else if ((g_phb_cntx.selected_storage == MMI_SIM2) && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, MTPNP_FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else                        /*Have free space, begin to copy all */
    {
        Slave_CopyAll = MTPNP_TRUE;
        Slave_g_phb_mass_op_index = 0;
        Slave_g_phb_mass_op_count = 0;
        Slave_g_phb_mass_op_lookup_count = 0;
        Slave_g_phb_mass_op_abort = MTPNP_FALSE;
        g_phb_cntx.processing = TRUE;

        mmi_phb_show_mass_processing(STR_GLOBAL_COPYING, IMG_COPIED);
        DeleteNScrId(SCR_COPY_ALL_MENU);

        //MTPNP_Slave_PB_copy_all_one_after_one_req(g_phb_cntx.selected_storage);
        MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(g_phb_cntx.selected_storage);
    }
}

void MTPNP_Slave_PB_copy_all_sim2sim_req(void)
{
    if ((g_phb_cntx.selected_storage == MMI_SIM) && (MTPNP_AD_ADN_SIM2GetUsedNumber() == MTPNP_AD_ADN_SIM2GetCapacity()))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM2_STORAGE_FULL), IMG_GLOBAL_ERROR, MTPNP_FALSE,
                     PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else if ((g_phb_cntx.selected_storage == MMI_SIM2) && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, MTPNP_FALSE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
        DeleteNScrId(SCR_COPY_ALL_MENU);
    }
    else                        /*Have free space, begin to copy all */
    {
        Slave_CopyAll = MTPNP_TRUE;
        Slave_g_phb_mass_op_index = 0;
        Slave_g_phb_mass_op_count = 0;
        Slave_g_phb_mass_op_lookup_count = 0;
        Slave_g_phb_mass_op_abort = MTPNP_FALSE;
        g_phb_cntx.processing = TRUE;

        mmi_phb_show_mass_processing(STR_GLOBAL_COPYING, IMG_COPIED);
        DeleteNScrId(SCR_COPY_ALL_MENU);

        //MTPNP_Slave_PB_copy_all_one_after_one_req(g_phb_cntx.selected_storage);
        MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(g_phb_cntx.selected_storage);
    }
}

void MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(MTPNP_UINT8 from_storage)
{
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    MTPNP_UINT16 store_index;

    if (from_storage == MMI_NVRAM)
    {
        while ((g_phb_name_index[Slave_g_phb_mass_op_index] >= mmi_phb_get_max_pb_phone_entries()) && (Slave_g_phb_mass_op_index < PhoneBookEntryCount))      /*Not In NVRAM */
        {
            Slave_g_phb_mass_op_index++;
        }
    }
    else
    {
        while ((g_phb_name_index[Slave_g_phb_mass_op_index] < (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())) && (Slave_g_phb_mass_op_index < PhoneBookEntryCount))        /*Not in Slave SIM */
        {
            Slave_g_phb_mass_op_index++;
        }
    }
    if (Slave_g_phb_mass_op_index >= PhoneBookEntryCount)
    {
        MTPNP_Slave_PB_copy_all_done();
        return;
    }

    store_index = g_phb_name_index[Slave_g_phb_mass_op_index];

#if defined(__MMI_PHB_PINYIN_SORT__)    /*Make Pinyin cache for later sorting. */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif

    if (from_storage == MMI_SIM2)
    {
        myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT *) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;
        myMsgPtr->list.storage = MMI_NVRAM;
        myMsgPtr->list.index = 0xFFFF;
        myMsgPtr->list.record_index = 0xFFFF;
        mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType *) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        SetProtocolEventHandler(MTPNP_Slave_PB_copy_all_one_after_one_rsp, PRT_PHB_SET_ENTRY_RSP);
    }
    else
    {
        MTPNP_UINT8 ton_npi;
        E_MTPNP_CODING_SCHEME coding_scheme;

        MTPNP_CHAR *name_buff;
        MTPNP_CHAR *number_buff;

        name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
        MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);

        if (GetUCS2Flag((PS8)PhoneBook[store_index].alpha_id.name))
        {
            coding_scheme = MTPNP_CODING_SCHEME_UCS2;
            MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) name_buff,
                                           (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                                           MTPNP_AD_ADN_SIM2GetUCS2LenSupport());

        }
        else
        {
            coding_scheme = MTPNP_CODING_SCHEME_ASCII;
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) name_buff, (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                            (MTPNP_INT) MTPNP_AD_ADN_SIM2GetTagSupport() << 1);
        }

        if (PhoneBook[store_index].tel.number[0] == '+')
        {
            ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number + ENCODING_LENGTH,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }
        else
        {
            ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }

        MTPNP_AD_Add_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi);

        MTPNP_OSAL_memfree(name_buff);
        name_buff = MTPNP_NULL;
        MTPNP_OSAL_memfree(number_buff);
        number_buff = MTPNP_NULL;
    }
}

void MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(MTPNP_UINT8 from_storage)
{
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    MTPNP_UINT16 store_index;

    Slave_CopyAll = MTPNP_TRUE;

    if (from_storage == MMI_SIM)
    {
        while ((g_phb_name_index[Slave_g_phb_mass_op_index] >= (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries()) || (g_phb_name_index[Slave_g_phb_mass_op_index] < mmi_phb_get_max_pb_phone_entries())) && (Slave_g_phb_mass_op_index < PhoneBookEntryCount))       /*Not In NVRAM */
        {
            Slave_g_phb_mass_op_index++;
        }
    }
    else
    {
        while ((g_phb_name_index[Slave_g_phb_mass_op_index] < (mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())) && (Slave_g_phb_mass_op_index < PhoneBookEntryCount))        /*Not in Slave SIM */
        {
            Slave_g_phb_mass_op_index++;
        }
    }
    if (Slave_g_phb_mass_op_index >= PhoneBookEntryCount)
    {
        MTPNP_Slave_PB_copy_all_done();
        return;
    }

    store_index = g_phb_name_index[Slave_g_phb_mass_op_index];

#if defined(__MMI_PHB_PINYIN_SORT__)    /*Make Pinyin cache for later sorting. */
    mmi_phb_util_make_pinyin_cache(store_index);
#endif

    if (from_storage == MMI_SIM2)
    {
        myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT *) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

        myMsgPtr->type = MMI_PHB_PHONEBOOK;
        myMsgPtr->no_data = 1;
        myMsgPtr->list.storage = MMI_SIM;
        myMsgPtr->list.index = 0xFFFF;
        myMsgPtr->list.record_index = 0xFFFF;
        mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
        Message.oslDataPtr = (oslParaType *) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        SetProtocolEventHandler(MTPNP_Slave_PB_copy_all_one_after_one_rsp, PRT_PHB_SET_ENTRY_RSP);
    }
    else
    {
        MTPNP_UINT8 ton_npi;
        E_MTPNP_CODING_SCHEME coding_scheme;

        MTPNP_CHAR *name_buff;
        MTPNP_CHAR *number_buff;

        name_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc((MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        MTPNP_OSAL_memset(name_buff, 0, (MTPNP_AD_ADN_SIM2GetTagSupport() + 1) * 2);
        number_buff = (MTPNP_CHAR *) MTPNP_OSAL_malloc(MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);
        MTPNP_OSAL_memset(number_buff, 0, MTPNP_AD_ADN_SIM2GetNumberSupport() + 1);

        Slave_CopyAll = MTPNP_TRUE;

        if (GetUCS2Flag((PS8)PhoneBook[store_index].alpha_id.name))
        {
            coding_scheme = MTPNP_CODING_SCHEME_UCS2;
            MTPNP_PFAL_Unicode_Memory_Copy(name_buff, (MTPNP_CHAR *)PhoneBook[store_index].alpha_id.name, MTPNP_AD_ADN_SIM2GetUCS2LenSupport());
        }
        else
        {
            coding_scheme = MTPNP_CODING_SCHEME_ASCII;
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) name_buff, (MTPNP_CHAR *) PhoneBook[store_index].alpha_id.name,
                            (MTPNP_INT) MTPNP_AD_ADN_SIM2GetTagSupport() << 1);
        }

        if (PhoneBook[store_index].tel.number[0] == '+')
        {
            ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number + ENCODING_LENGTH,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }
        else
        {
            ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
            mmi_phb_convert_to_digit((MTPNP_UINT8 *) number_buff, PhoneBook[store_index].tel.number,
                                     (MTPNP_UINT8) MTPNP_AD_ADN_SIM2GetNumberSupport());
        }

        MTPNP_AD_Add_ADN_Record(coding_scheme, name_buff, number_buff, ton_npi);

        MTPNP_OSAL_memfree(name_buff);
        name_buff = MTPNP_NULL;
        MTPNP_OSAL_memfree(number_buff);
        number_buff = MTPNP_NULL;
    }
}

void MTPNP_Slave_PB_copy_all_one_after_one_rsp(void *info)
{
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    MTPNP_INT16 pError;
    MTPNP_UINT8 copy_from, copy_to = MMI_NVRAM;
    MTPNP_UINT16 store_index;
    MTPNP_UINT temp;
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT *) info;

    copy_from = MMI_SIM2;
    copy_to = Slave_g_phb_copy_all_from_sim2_to;

    if (localPtr->result.flag == 0 /*OK*/)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        if (localPtr->list[0].storage == MMI_SIM)
        {
            g_phb_cntx.sim_used++;
            store_index = localPtr->list[0].record_index + mmi_phb_get_max_pb_phone_entries() - 1;    /*Storage Location in array. */
            ASSERT(copy_to == MMI_SIM);
        }
        else
        {
            g_phb_cntx.phone_used++;
            store_index = localPtr->list[0].record_index - 1;   /*Storage Location in array. */
            ASSERT(copy_to == MMI_NVRAM);
        }
#endif
        if (copy_to == MMI_NVRAM)
        {
            /*Clear Optional Field */
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            MTPNP_OSAL_memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
            WriteRecord(NVRAM_EF_PHB_FIELDS_LID, (U16) (store_index + 1), (void *) &PhoneBookOptionalFields,
                        OPTIONAL_FIELDS_RECORD_SIZE, &pError);
#endif
            /*Clear Optional Id */
            mmi_phb_clear_optional_ids(store_index);

            /*Clear video field. */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
#endif
            /*Clear birthday field */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            mmi_phb_bday_delete_field(store_index);
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
            mmi_phb_info_delete_field(store_index);
#endif
        }

#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_copy_optional_ids(store_index, g_phb_name_index[Slave_g_phb_mass_op_index]);

        if (copy_to == MMI_SIM)
        {
            mmi_phb_clear_optional_ids_for_sim(store_index);
        }
#endif

        /*Populate Number Field */
        temp = mmi_phb_util_convert_number_to_int(localPtr->list[0].tel.number);
        if (temp < INVALID_NUMBER)
        {
            LookUpTable[g_phb_cntx.lookup_table_count].store_index = store_index;
            LookUpTable[g_phb_cntx.lookup_table_count++].number = temp;
        }

        /* Add result to Phonebook Storage */
        //mmi_phb_op_set_entry_rsp_name_number(info, store_index);
        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);
        /*Update field flag */
        mmi_phb_op_update_field_flag(store_index, (S8 *) localPtr->list[0].tel.number, NULL, NULL, NULL, NULL, TRUE);
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }

#if defined(__MMI_PHB_PINYIN_SORT__)    /*Make Pinyin cache for later sorting. */
        mmi_phb_util_make_pinyin_cache(store_index);
#endif
        /*Append new entry in the end of sorted list. Sorting when copy all done. */
        g_phb_name_index[PhoneBookEntryCount] = store_index;
        PhoneBookEntryCount++;
        Slave_g_phb_mass_op_count++;

        /*Insert email to email mapping table, not like name field, it should sort here. */
#if defined(__MMI_PHB_EMAIL_SORT__)
        if (((copy_to == MMI_NVRAM) && (g_phb_email_sorted == 1))
            || ((copy_to == MMI_SIM) && (g_phb_email_sorted == 1)))
            mmi_phb_sort_email_insert_index(store_index);
#endif
        if (Slave_g_phb_mass_op_abort)
        {
            Slave_g_phb_mass_op_success = MTPNP_FALSE;
            MTPNP_Slave_PB_copy_all_done();
        }
        else
        {
            if (Slave_g_phb_mass_op_count < MTPNP_AD_ADN_SIM2GetUsedNumber())
            {
                ++Slave_g_phb_mass_op_index;
                if (copy_to == MMI_NVRAM)
                {
                    //MTPNP_Slave_PB_copy_all_one_after_one_req(copy_from);
                    MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(copy_from);
                }
                else if (copy_to == MMI_SIM)
                {
                    MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(copy_from);
                }

            }
            else
                MTPNP_Slave_PB_copy_all_done();
        }
    }
    else
    {
        Slave_g_phb_mass_op_success = MTPNP_FALSE;
        /*Not copy fail due to capacity full. */
        if ((localPtr->result.cause != MMI_PHB_CAUSE_CAPACITY_EXCEEDED) &&
            (copy_from == MMI_SIM2 && Slave_g_phb_mass_op_count < MTPNP_AD_ADN_SIM2GetUsedNumber()))
        {
            Slave_g_phb_mass_op_index++;
            if (copy_to == MMI_NVRAM)
            {
                MTPNP_Slave_PB_copy_all_phone2sim_one_after_one_req(copy_from);
            }
            else if (copy_to == MMI_SIM)
            {
                MTPNP_Slave_PB_copy_all_sim2sim_one_after_one_req(copy_from);
            }
            //MTPNP_Slave_PB_copy_all_one_after_one_req(copy_from);
        }
        else
        {
            MTPNP_Slave_PB_copy_all_done();
        }
    }
}

void MTPNP_Slave_PB_copy_all_done(void)
{
    MTPNP_CHAR outBuf[100], count[10];
    TurnOnBacklight(1);         /*Turn On Back Light When done */
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    /*Sort name index */
    mmi_phb_sort_build_name_index();

    /*Sort Number index */
    mmi_phb_lookup_table_sort();
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    Slave_CopyAll = MTPNP_FALSE;
    g_phb_cntx.processing = MTPNP_FALSE;

    if (Slave_g_phb_mass_op_success)
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_ID_PHB_COPIED), IMG_GLOBAL_ACTIVATED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT,
                     SUCCESS_TONE);
    else if (1 == MTPNP_AD_FDN_GetStatus())   /*For FDN on Message */
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT,
                     ERROR_TONE);
        Slave_g_phb_mass_op_success = TRUE;
    }
    else                        /*!Slave_g_phb_mass_op_success */
    {
        Slave_g_phb_mass_op_success = MTPNP_TRUE;
        sprintf(count, "%d ", Slave_g_phb_mass_op_count);
        mmi_asc_to_ucs2(outBuf, count);
        if (Slave_g_phb_mass_op_count <= 1)
        {
            mmi_ucs2cat(outBuf, GetString(STR_ENTRY_COPIED));
        }
        else
        {
            mmi_ucs2cat(outBuf, GetString(STR_ENTRIES_COPIED));
        }
        DisplayPopup((MTPNP_UINT8 *) outBuf, IMG_GLOBAL_UNFINISHED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    DeleteScreenIfPresent(SCR_COPY_ALL_MENU);

    /*add central command for vrsi. */
#if defined(__MMI_VRSI__)
    mmi_vrsi_init_central_abort();
#endif
}

void hintPreferStoragLocationinSIM2(MTPNP_UINT16 index)
{
    MTPNP_CHAR simStatus[40];
    MTPNP_CHAR ascii_status[20];
    memset((MTPNP_CHAR *) hintData[index], 0, sizeof(hintData[index]));
    if (mmi_bootup_is_sim2_valid())
    {
        sprintf(ascii_status, "%d/%d", MTPNP_AD_ADN_SIM2GetUsedNumber(), MTPNP_AD_ADN_SIM2GetCapacity());
    }
    else
    {
        sprintf(ascii_status, "%d/%d", 0, 0);
    }
    mmi_asc_to_ucs2(simStatus, ascii_status);

    mmi_ucs2cpy((MTPNP_CHAR *) hintData[index], simStatus);

}

void card2_mmi_phb_op_fill_inline_item(U8 field_index, U8 item_index, U16 store_index, U16 * string_list,
                                       U16 * image_list)
{
    MTPNP_UINT8 nameLength;
    MTPNP_UINT8 numLength;

    switch (field_index)
    {
        /*--- Name Field ---*/
    case MMI_PHB_FIELD_NAME:
        nameLength =
            MTPNP_AD_ADN_SIM2GetTagLen() > MAX_PB_NAME_LENGTH ? MAX_PB_NAME_LENGTH : MTPNP_AD_ADN_SIM2GetTagLen();
        SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemFullScreenEdit(&wgui_inline_items[item_index],
                                    STR_ID_PHB_NAME,
                                    IMG_SCR_PBOOK_CAPTION,
                                    (MTPNP_UINT8 *) pbName,
                                    nameLength + 1,
                                    (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH |
                                     INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING));
        SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
        string_list[item_index] = STR_ID_PHB_NAME;
        image_list[item_index] = IMG_NAME;
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
#endif
        break;

        /*--- Mobile Number Field ---*/
    case MMI_PHB_FIELD_NUMBER:
        numLength =
            MTPNP_AD_ADN_SIM2GetNumLen() > MAX_PB_NUMBER_LENGTH ? MAX_PB_NUMBER_LENGTH : MTPNP_AD_ADN_SIM2GetNumLen();
        SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(&wgui_inline_items[item_index],
                              (MTPNP_UINT8 *) pbNumber,
                              numLength + 1, INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
        DisableInlineItemHighlight(&wgui_inline_items[item_index]);
        string_list[item_index] = STR_ID_PHB_MOBILE_NUMBER;
        image_list[item_index] = IMG_MOBILE_NUMBER;
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
#endif
        break;
    }
}

MTPNP_BOOL MTPNP_PFAL_Phb_IsReady(void)
{
    MTPNP_BOOL SlaveEffect;

    if (MTPNP_PFAL_Is_Card2Absent() ||
        MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_INVALID ||
        MTPNP_AD_Get_Card2Status() > MTPNP_AD_SIMCARD_VALID)
    {
        SlaveEffect = MTPNP_TRUE;
    }
    else
    {
        SlaveEffect = MTPNP_AD_ADN_SIM2_Is_LoadFinished();
    }

    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing && SlaveEffect)
    {
        return MTPNP_TRUE;
    }
    else
    {
        return MTPNP_FALSE;
    }
}

void MTPNP_PFAL_PB_CopyAll_Menu_Handle(void)
{
    MTPNP_UINT16 store_index;
    E_MTPNP_AD_SIMCARD_STATUS sim1_status, sim2_status;

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    sim1_status = MTPNP_AD_Get_Card1Status();
    sim2_status = MTPNP_AD_Get_Card2Status();


    mmi_frm_hide_menu_item(MITEM_PBOOK_COPY_ALL_SIM);
    mmi_frm_hide_menu_item(MITEM_PBOOK_COPY_ALL_PHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPYALL_SIM2TOPHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPYALL_PHONETOSIM2);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPYALL_SIM1TOSIM2);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPYALL_SIM2TOSIM1);
    if ((sim1_status & sim2_status) >= MTPNP_AD_SIMCARD_VALID)
    {
        /* dual SIM valid */
        mmi_frm_unhide_menu_item(MITEM_PBOOK_COPY_ALL_SIM);
        mmi_frm_unhide_menu_item(MITEM_PBOOK_COPY_ALL_PHONE);
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_SIM2TOPHONE);
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_PHONETOSIM2);
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_SIM1TOSIM2);
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_SIM2TOSIM1);
    }
    else
    {
        if (sim1_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card1 invalid */
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_SIM2TOPHONE);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPYALL_PHONETOSIM2);
        }
        if (sim2_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card2 invalid */
            mmi_frm_unhide_menu_item(MITEM_PBOOK_COPY_ALL_SIM);
            mmi_frm_unhide_menu_item(MITEM_PBOOK_COPY_ALL_PHONE);
        }
    }

}
void MTPNP_PFAL_PB_Option_Menu_Handle(void)
{
    MTPNP_UINT16 store_index;
    E_MTPNP_AD_SIMCARD_STATUS sim1_status, sim2_status;

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    sim1_status = MTPNP_AD_Get_Card1Status();
    sim2_status = MTPNP_AD_Get_Card2Status();

    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_SIM2TOPHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_SIM2TOSIM1);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_SIM1TOSIM2);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_SIM1TOPHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM1);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM2);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_SIM2TOPHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_SIM2TOSIM1);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_SIM1TOSIM2);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_SIM1TOPHONE);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM1);
    mmi_frm_hide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM2);

    if ((sim1_status & sim2_status) >= MTPNP_AD_SIMCARD_VALID)
    {
        /* dual SIM valid */
        if (store_index < mmi_phb_get_max_pb_phone_entries())
        {
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM1);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM2);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM1);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM2);
        }
        else if (store_index >= mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())
        {
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM2TOPHONE);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM2TOSIM1);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM2TOPHONE);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM2TOSIM1);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM1TOSIM2);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM1TOPHONE);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM1TOSIM2);
            mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM1TOPHONE);
        }
    }
    else
    {
        if (sim1_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card1 invalid */
            if (store_index < mmi_phb_get_max_pb_phone_entries())
            {
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM2);
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM2);
            }
            else if (store_index >= mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries())
            {
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM2TOPHONE);
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM2TOPHONE);
            }
        }
        if (sim2_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card2 invalid */
            if (store_index < mmi_phb_get_max_pb_phone_entries())
            {
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_PHONETOSIM1);
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_PHONETOSIM1);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_COPY_SIM1TOPHONE);
                mmi_frm_unhide_menu_item(MENU_MTPNP_PB_MOVE_SIM1TOPHONE);
            }
        }
    }

}


void MTPNP_PFAL_PHB_op_copy_menu(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Copy_MainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_PHB_op_move_menu(void)
{
    SetLeftSoftkeyFunction(MTPNP_Slave_PB_Move_MainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_Slave_PB_Copy_Exit_MainMenu(void)
{
    g_phb_cntx.end_scr_id = SCR_CARD2_PHB_COPY;
}

void MTPNP_Slave_PB_Move_Exit_MainMenu(void)
{
    g_phb_cntx.end_scr_id = SCR_CARD2_PHB_MOVE;
}

void MTPNP_Slave_PB_Copy_MainMenu(void)
{
    MTPNP_UINT16 nStrItemList[6];
    MTPNP_UINT16 nNumofItem;
    MTPNP_UINT8 *guiBuffer;
    EntryNewScreen(SCR_CARD2_PHB_COPY, MTPNP_Slave_PB_Copy_Exit_MainMenu, MTPNP_Slave_PB_Copy_MainMenu, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_PHB_COPY);

    nNumofItem = GetNumOfChild_Ext(MITEM1013_PBOOK_COPY_ENTRY);
    GetSequenceStringIds_Ext(MITEM1013_PBOOK_COPY_ENTRY, nStrItemList);
    SetParentHandler(MITEM1013_PBOOK_COPY_ENTRY);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_MITEM1013, GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, 1, 0, guiBuffer);


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_Slave_PB_Move_MainMenu(void)
{
    MTPNP_UINT16 nStrItemList[6];
    MTPNP_UINT16 nNumofItem;
    MTPNP_UINT8 *guiBuffer;

    EntryNewScreen(SCR_CARD2_PHB_MOVE, MTPNP_Slave_PB_Move_Exit_MainMenu, MTPNP_Slave_PB_Move_MainMenu, MTPNP_NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_PHB_MOVE);

    nNumofItem = GetNumOfChild_Ext(MITEM1014_PBOOK_MOVE);
    GetSequenceStringIds_Ext(MITEM1014_PBOOK_MOVE, nStrItemList);
    SetParentHandler(MITEM1014_PBOOK_MOVE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(STR_MITEM1014, GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, 1, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* IP Dial */
void MTPNP_PFAL_PHB_entry_list_choose_number_ip_dial(void)
{
#if defined(__IP_NUMBER__)      /* Set IP Dial option to TRUE */
    SetTempUseIPNumber(TRUE);
#endif

    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    mmi_phb_list_pre_choose_number();
}

void MTPNP_PFAL_PHB_op_SIM2_ip_number(void)
{
    SetLeftSoftkeyFunction(MTPNP_PFAL_PHB_entry_list_choose_number_ip_dial, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
void MTPNP_PFAL_phb_op_move_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_move_req.>\n", __FILE__, __LINE__);

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT *) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    storage = (SlavemoveEntryStoreIndex >= mmi_phb_get_max_pb_phone_entries()) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr->storage = storage;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    myMsgPtr->index =
        (storage == MMI_SIM) ? (SlavemoveEntryStoreIndex + 1 - mmi_phb_get_max_pb_phone_entries()) : (SlavemoveEntryStoreIndex + 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType *) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(MTPNP_PFAL_phb_op_move_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_move_rsp
 * DESCRIPTION
 *  Response handler for mmi_phb_op_move_req().
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_phb_op_move_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;
    U16 deletedCnt = 0;

    //U8 grpIndex;
    //S16 pError;
    U8 storage;
    U16 record_index;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB_CALLER_GROUP_STRUCT* callerGroups; */

    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT *) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_move_rsp.>\n", __FILE__, __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {

        storage = (SlavemoveEntryStoreIndex >= mmi_phb_get_max_pb_phone_entries()) ? MMI_SIM : MMI_NVRAM;
        record_index =
            (storage ==
             MMI_SIM) ? (SlavemoveEntryStoreIndex + 1) - mmi_phb_get_max_pb_phone_entries() : (SlavemoveEntryStoreIndex + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

        if (SlavemoveEntryStoreIndex >= mmi_phb_get_max_pb_phone_entries())   /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
#if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(SlavemoveEntryStoreIndex);
            }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */
        }
        else
        {
            g_phb_cntx.phone_used--;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            mmi_phb_read_optional_ids(SlavemoveEntryStoreIndex);
            opt_ids = (PHB_OPTIONAL_IDS_STRUCT *) g_phb_cntx.optional_ids;

            /* Delete image file in file folder */
            if (opt_ids->pictureTagID == 1)
            {
                mmi_phb_image_delete_by_index((U16) (SlavemoveEntryStoreIndex + 1));
            }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */

#if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(SlavemoveEntryStoreIndex);    /* Clear video field. */
#endif
            /* Clear birthday field */
#if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
            mmi_phb_bday_delete_field(SlavemoveEntryStoreIndex);
#endif

            /* Remove email entry from email sort mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(SlavemoveEntryStoreIndex);
            }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */
#ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, SlavemoveEntryStoreIndex);
#endif
        }

        /* Remove lookup table entry */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(SlavemoveEntryStoreIndex);

        if (deletedCnt)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

#if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(SlavemoveEntryStoreIndex);
#endif /* defined(__MMI_VRSD_DIAL__) */

#if defined(__MMI_VRSI__)
        /* remove voice dial tag if exists. */
        mmi_vrsi_ndial_central_delete_single(SlavemoveEntryStoreIndex);
#endif /* defined(__MMI_VRSI__) */

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(SlavemoveEntryStoreIndex);

        if (SlavemoveModified)
        {
            SlavemoveModified = 0;
            DisplayPopup((PU8) GetString(STR_MOVED_NAME_MODIFIED),
                         IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        }
        else
        {
                DisplayPopup((PU8) GetString(STRING_MTPNP_PHB_MOVE_TO_SIM2_DONE),
                             IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED),
                     IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}

void MTPNP_PFAL_ADN_SAT_Handler(MTPNP_BOOL adn_reset)
{
    MTPNP_AD_ADN_SetLoadFinish(MTPNP_FALSE);
    mmi_phb_sat_handler_end_current_op();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_edit
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is edited through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_ADN_phb_at_cmd_edit(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U8 flag = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    store_index = localPtr->list[0].record_index + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries() - 1;        /* Storage Location in array. */

    /* Clear lookup table first, add later if exists. */
    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    flag = mmi_phb_op_increase_lookup_table(store_index, (S8*) localPtr->list[0].tel.number, NULL, NULL, NULL);

    if (flag || deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    PhoneBook[store_index].alpha_id.name_length = localPtr->list[0].alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = localPtr->list[0].alpha_id.name_dcs;
    InputboxConvertGSMToDeviceEncoding(
        localPtr->list[0].alpha_id.name,
        PhoneBook[store_index].alpha_id.name,
        localPtr->list[0].alpha_id.name_length,
        (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
        localPtr->list[0].alpha_id.name_dcs,
        0,
        1);

    PhoneBook[store_index].tel.type = localPtr->list[0].tel.type;
    PhoneBook[store_index].tel.length = localPtr->list[0].tel.length;
    mmi_phb_convert_to_bcd(
        PhoneBook[store_index].tel.number,
        localPtr->list[0].tel.number,
        (MAX_PB_NUMBER_LENGTH + 1) / 2);

    /* Update is column exists flag. */
    PhoneBook[store_index].field = 0;
    if (localPtr->list[0].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    if (strlen((S8*) localPtr->list[0].tel.number))
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }

    /* Update Pinyin Cache for sort */
#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    /* Name sorting mapping table should Re-Sort HERE, and get the new highlight position!!! */
    mmi_phb_op_delete_update_index(store_index);
    mmi_phb_sort_insert_name_index(store_index);
    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    /* Update email sorting mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_email_sorted == 1)
#endif 
    {
        mmi_phb_sort_email_delete_index(store_index);
        mmi_phb_sort_email_insert_index(store_index);
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_add
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is added through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_ADN_phb_at_cmd_add(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
    U16 store_index;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    store_index = localPtr->list[0].record_index - 1 + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries();

    // add bitmap and used num
    MTPNP_AD_ADN_SIMIncreaseUsedNumber();
    MTPNP_AD_ADN_SetBitMapValid(localPtr->list[0].record_index);
    flag = mmi_phb_op_increase_lookup_table(store_index, (S8*) localPtr->list[0].tel.number, NULL, NULL, NULL);
    if (flag)
    {
        mmi_phb_lookup_table_sort();
    }

    PhoneBook[store_index].alpha_id.name_length = localPtr->list[0].alpha_id.name_length;
    PhoneBook[store_index].alpha_id.name_dcs = localPtr->list[0].alpha_id.name_dcs;
    InputboxConvertGSMToDeviceEncoding(
        localPtr->list[0].alpha_id.name,
        PhoneBook[store_index].alpha_id.name,
        localPtr->list[0].alpha_id.name_length,
        (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
        localPtr->list[0].alpha_id.name_dcs,
        0,
        1);

    PhoneBook[store_index].tel.type = localPtr->list[0].tel.type;
    PhoneBook[store_index].tel.length = localPtr->list[0].tel.length;
    mmi_phb_convert_to_bcd(
        PhoneBook[store_index].tel.number,
        localPtr->list[0].tel.number,
        (MAX_PB_NUMBER_LENGTH + 1) / 2);

    /* Update is column exists flag. */
    PhoneBook[store_index].field = 0;
    if (localPtr->list[0].alpha_id.name_length)
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
    }
    if (strlen((S8*) localPtr->list[0].tel.number))
    {
        PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NUMBER;
    }

    /* Update Pinyin Cache for sort */
#if defined(__MMI_PHB_PINYIN_SORT__)
    mmi_phb_util_make_pinyin_cache(store_index);
#endif 

    /* Insert name to name mapping table. */
    mmi_phb_sort_insert_name_index(store_index);

    /* Insert email to email mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_email_sorted == 1)
#endif 
        mmi_phb_sort_email_insert_index(store_index);
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_delete
 * DESCRIPTION
 *  Handles the phonebook update indication after an entry is deleted through AT command.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_ADN_phb_at_cmd_delete(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    store_index = localPtr->list[0].record_index + mmi_phb_get_max_pb_sim_entries() + mmi_phb_get_max_pb_phone_entries() - 1;        /* Storage Location in array. */
// delete bitmap and used num
    if (mmi_phb_util_check_entry_exist(store_index))
    {
        MTPNP_AD_ADN_SIMDecreaseUsedNumber();
        MTPNP_AD_ADN_SetBitMapInvalid(localPtr->list[0].record_index);
    }

    PhbUpdateSpeedDial(MMI_SIM2, localPtr->list[0].record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

    /* Remove lookup table entry */
    deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

    if (deletedCnt)
    {
        mmi_phb_lookup_table_sort();
        g_phb_cntx.lookup_table_count -= deletedCnt;
    }

    /* clear phonebook entry and remove from index */
    mmi_phb_op_delete_update_index(store_index);

    g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    mmi_phb_refresh_phb_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_at_cmd_delete_all
 * DESCRIPTION
 *  Handles the phonebook update indication after an all the entries of one storage
 *  location is deleted through AT command
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_ADN_phb_at_cmd_delete_all(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage;
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;

    if (localPtr->nvram_used == 0 && g_phb_cntx.phone_used != 0)
    {
        storage = MMI_NVRAM;
        mmi_phb_op_delete_all_update_optioal_id();
    }
    else
    {
        storage = MMI_SIM;
    }

    /* Clear all storage and clear up name index. */
    mmi_phb_op_delete_all_update_index(storage);
    mmi_phb_op_delete_all_update_lookup_table(storage);

    /* Remove email entry from email sort mapping table */
#if defined(__MMI_PHB_EMAIL_SORT__)
    if ((storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
    {
        mmi_phb_sort_email_delete_all_index();
    }
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
    mmi_phb_refresh_phb_list();
}

void MTPNP_PFAL_ADN_phb_ind_update_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_at_general_res_req_struct *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    myMsgPtr->result = TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = MSG_ID_MMI_AT_GENERAL_RES_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_ADN_phb_ind_update(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_UPDATE_IND_STRUCT *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_ind_update.>\n", __FILE__, __LINE__);
    localPtr = (MSG_PHB_UPDATE_IND_STRUCT*) info;
    switch (localPtr->action)
    {
        case MMI_PHB_UPDATE:
            if (localPtr->list[0].storage == MMI_NVRAM)
            {
                ASSERT(0);
            }
            if ((MTPNP_AD_ADN_SIM2GetUsedNumber() == localPtr->sim_used))
            {
                MTPNP_PFAL_ADN_phb_at_cmd_edit(info);
            }
            else
            {
                MTPNP_PFAL_ADN_phb_at_cmd_add(info);
            }
            break;
        case MMI_PHB_DELETE:
            MTPNP_PFAL_ADN_phb_at_cmd_delete(info);
            break;
        case MMI_PHB_DELETE_ALL:
            /* currently, AT didn't have DELETE ALL cmd */
            MTPNP_PFAL_ADN_phb_at_cmd_delete_all(info);
            break;
        case MMI_WRITE_LND:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (MTPNP_AD_Get_CallHistory_Dialedcall() < TOT_SIZE_OF_DIALED_LIST)
            {
                MTPNP_AD_Set_CallHistory_Dialedcall(MTPNP_AD_Get_CallHistory_Dialedcall() + 1);
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            MTPNP_AD_Set_CallHistory_Dialedcall((MTPNP_UINT8) localPtr->no_list);
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            break;
        case MMI_WRITE_LNM:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (MTPNP_AD_Get_CallHistory_Missedcall() < TOT_SIZE_OF_DIALED_LIST)
            {
                MTPNP_AD_Set_CallHistory_Missedcall(MTPNP_AD_Get_CallHistory_Missedcall() + 1);
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            MTPNP_AD_Set_CallHistory_Missedcall((MTPNP_UINT8) localPtr->no_list);
        #endif /* (MAX_PHB_LN_ENTRY > 20) */ 
            break;
        case MMI_WRITE_LNR:
        #if (MAX_PHB_LN_ENTRY > 20)
            if (MTPNP_AD_Get_CallHistory_Recvdcall() < TOT_SIZE_OF_DIALED_LIST)
            {
                MTPNP_AD_Set_CallHistory_Recvdcall(MTPNP_AD_Get_CallHistory_Recvdcall() + 1);
            }
        #else /* (MAX_PHB_LN_ENTRY > 20) */ 
            MTPNP_AD_Set_CallHistory_Recvdcall((MTPNP_UINT8) localPtr->no_list);
        #endif /* (MAX_PHB_LN_ENTRY > 20) */  
            break;
        case MMI_DELETE_LND:
            if (localPtr->old_index < MTPNP_AD_Get_CallHistory_Dialedcall())
            {
                MTPNP_AD_Set_CallHistory_Dialedcall(MTPNP_AD_Get_CallHistory_Dialedcall() - 1);
            }
            break;
        case MMI_DELETE_LNM:
            if (localPtr->old_index < MTPNP_AD_Get_CallHistory_Missedcall())
            {
                MTPNP_AD_Set_CallHistory_Missedcall(MTPNP_AD_Get_CallHistory_Missedcall() - 1);
            }
            break;
        case MMI_DELETE_LNR:
            if (localPtr->old_index < MTPNP_AD_Get_CallHistory_Recvdcall())
            {
                MTPNP_AD_Set_CallHistory_Recvdcall(MTPNP_AD_Get_CallHistory_Recvdcall() - 1);
            }
            break;
    }

    MTPNP_PFAL_ADN_phb_ind_update_confirm();
}

MTPNP_BOOL MTPNP_PFAL_ADN_get_slave_is_copy_all(void)
{
    return Slave_CopyAll;
}

void MTPNP_PFAL_ADN_set_slave_is_copy_all(MTPNP_BOOL is_copy_all)
{
    Slave_CopyAll = is_copy_all;
}

MTPNP_BOOL MTPNP_PFAL_ADN_get_slave_is_delete_all(void)
{
    return Slave_g_phb_mass_delall;
}

void MTPNP_PFAL_ADN_set_slave_is_delete_all(MTPNP_BOOL is_delete_all)
{
    Slave_g_phb_mass_delall = is_delete_all;
}

void MTPNP_PFAL_ADN_set_slave_mass_op_success_flag(MTPNP_BOOL is_success)
{
    Slave_g_phb_mass_op_success = is_success;
}

MTPNP_UINT16 MTPNP_PFAL_ADN_get_slave_mass_op_count(void)
{
    return Slave_g_phb_mass_op_count;
}

void MTPNP_PFAL_FDN_ON_DisplayPopup(void)
{
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT,
                 ERROR_TONE);
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_COPY_ALL_PROGRESS);
    DeleteScreenIfPresent(SCR_ADD_NEW_ENTRY);
    DeleteScreenIfPresent(SCR_STORAGE_LOCATION_MENU);   //storage location
    DeleteScreenIfPresent(SCR_ID_PHB_FMGR_SAVE_OPTION);
    g_phb_cntx.processing = FALSE;

}

void MTPNP_PFAL_ADN_Init_SIM2_PHB(void)
{
    PhoneBookEntryCount = 0;
    Slave_g_is_phb_init=MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_ADN_Is_PHB_Init(void)
{
    return Slave_g_is_phb_init;
}

BOOL MTPNP_PFAL_ADN_Is_PHB_Before_Sort(void)
{
    return Slave_g_phb_startup_before_sort;
}

void MTPNP_PFAL_ADN_Set_Is_PHB_Before_Sort(MTPNP_BOOL is_before_sort)
{
    Slave_g_phb_startup_before_sort = is_before_sort;
}

void MTPNP_PFAL_ADN_fdn_get_list_to_ram(void)
{
    if (MTPNP_AD_ADN_SIM2GetUsedNumber() == 0)
    {
        Slave_g_phb_fdn_count = 0;
        MTPNP_PFAL_ADN_fdn_get_list_to_ram_req();
    }
    else
    {
        MTPNP_PFAL_ADN_after_fdn_get_list_to_ram();
    }
}

void MTPNP_PFAL_ADN_after_fdn_get_list_to_ram(void)
{
    MTPNP_PFAL_ADN_Set_Is_PHB_Before_Sort(MTPNP_TRUE);
    mmi_phb_startup_finish_final_step();
}

void MTPNP_PFAL_ADN_fdn_get_list_to_ram_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *pMsgIndexReq = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    pMsgIndexReq =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    pMsgIndexReq->index = Slave_g_phb_fdn_count + 1;
    pMsgIndexReq->record_index = 0xFFFF;
    pMsgIndexReq->storage = MMI_SIM;
    pMsgIndexReq->type = MMI_PHB_FDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    SetSlaveProtocolEventHandler(MTPNP_PFAL_ADN_fdn_get_list_to_ram_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    MTPNP_PFAL_send_message(MOD_MMI, MOD_L4C_2, 0, MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT, (oslParaType *) pMsgIndexReq, MTPNP_NULL);
*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pMsgIndexReq =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    pMsgIndexReq->index = Slave_g_phb_fdn_count + 1;
    pMsgIndexReq->record_index = 0xFFFF;
    pMsgIndexReq->storage = MMI_SIM;
    pMsgIndexReq->type = MMI_PHB_FDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;

    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    SetSlaveProtocolEventHandler(MTPNP_PFAL_ADN_fdn_get_list_to_ram_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    OslMsgSendExtQueue(&Message);
}


void MTPNP_PFAL_ADN_fdn_get_list_to_ram_rsp(void *info)
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
            if (Slave_g_phb_fdn_count < MAX_SIM_ENTRIES)
            {
                store_index = Slave_g_phb_fdn_count + mmi_phb_get_max_pb_phone_entries() + mmi_phb_get_max_pb_sim_entries();
                Slave_g_phb_fdn_count++;
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
            MTPNP_PFAL_ADN_fdn_get_list_to_ram_req();
            return;
        }
    }
    ClearSlaveProtocolEventHandler(PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    /* Retrieve Speed Dial List after retrieve FDN list, because they all use same message. */
    //PhbGetSpeedDialInfo();
    MTPNP_PFAL_ADN_after_fdn_get_list_to_ram();
}

MTPNP_UINT16 MTPNP_PFAL_ADN_phb_fdn_search_by_number(S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 i;
    MTPNP_UINT16 store_index;
    MTPNP_UINT8 tempNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MTPNP_AD_ADN_GetUsedNum() > 0)    /* ADN is read out from SIM card, so there is no storing FDN entry data. */
    {
        return 0xffff;
    }

    for (i = 0; i < Slave_g_phb_fdn_count; i++)
    {
        store_index = i + MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES;
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

#if defined(__MMI_VCARD__)
void HighlightVcardRecvSaveToSim(void)
{
    SetLeftSoftkeyFunction(mmi_vcard_recv_view_detail_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_vcard_recv_view_detail_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    g_vcard_cntx.StorageLoc = MMI_SIM2;
}
#endif /* defined(__MMI_VCARD__) */

#endif /* __MMI_DUAL_SIM_MASTER__ */
