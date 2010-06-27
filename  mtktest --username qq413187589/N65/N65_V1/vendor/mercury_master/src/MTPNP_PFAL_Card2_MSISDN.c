#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "GlobalDefs.h"
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
#include "CommonScreens.h"
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "wgui_categories_inputsenum.h"
#include "wgui_categories_inputs.h"
#include "CallSetUp.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "NVRAMEnum.h"
#include "PhoneSetup.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "ProtocolEvents.h"
#include "SimDetectionDef.h"

/**************************LOCAL*FUNCTION*DECLARE*BEGIN***********************/
static void HighlightDMShowOwnerNumber(void);
static void EntryDMShowOwnerNumber(void);
static void ExitDMShowOwnerNumber(void);
static void HintCard2ShowOwnerNumber(U16 index);
/**************************LOCAL*FUNCTION*DECLARE*END*************************/

/* msisdn */
static ST_MTPNP_OWNER_NUMBER_RECORD g_owner_number_record[MAX_SIM_ENTRIES];
MTPNP_CHAR g_owner_name_edit_buff[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
MTPNP_CHAR g_owner_number_edit_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
static MTPNP_INT g_hilite_card2_owner_number_idx = 0;
extern const MTPNP_UINT16 gIndexIconsImageList[];
extern MTPNP_UINT8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
extern MTPNP_UINT8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern MTPNP_UINT8 *subMenuDataPtrs[MAX_SUB_MENUS];
extern CallSetupContext g_callset_context;

MTPNP_BOOL Slave_g_phb_edit_owner = MTPNP_FALSE;
static MTPNP_UINT16 g_card2_msisdn_scr_end_id;
/* msisdn */

/* sdn and sos */
static MMI_PHB_ENTRY_STRUCT g_slave_phb_sim_list[MAX_SIM_ENTRIES];    /* Maximum entry of MSISDN, SDL and SOS in SIM */
static U16 g_slave_phb_sim_list_count;
U16 g_slave_phb_read_index;
static U8 *g_slave_phb_sos_list[MAX_SIM_SOS_ENTRIES];
/* sdn and sos */

void MTPNP_PFAL_MSISDN_Init(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FINISHED_IND, MTPNP_PFAL_MSISDN_Load_Finished);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FAIL_IND, MTPNP_PFAL_MSISDN_Load_Failed);

    SetHiliteHandler(MENU_MTPNP_DM_SHOW_OWNER_NUMBER, HighlightDMShowOwnerNumber);
    SetHiliteHandler(MENU_MTPNP_CARD2_PHBEXTRA, HighlightCard2PhbExtra);
    SetHiliteHandler(MENU_MTPNP_SHOW_CARD2_OWNER_NUMBER, HighlightCard2ShowOwnerNumber);
    SetHintHandler(MENU_MTPNP_SHOW_CARD2_OWNER_NUMBER, HintCard2ShowOwnerNumber);

    /* phb extra number begin */
    SetHiliteHandler(MENU_MTPNP_CARD2_OWNER_NUMBER, HighlightCard2OwnerNumber);
    SetHiliteHandler(MENU_MTPNP_CARD2_SDL_NUMBER, HighlightCard2SDLNumber);    
    SetHiliteHandler(MENU_MTPNP_CARD2_SOS_NUMBER, HighlightCard2SOSNumber);

    SetHiliteHandler(MENU_MTPNP_CARD2_OWNER_NUMBER_ERASE, HighlightCard2OwnerNumberErase);
    SetHiliteHandler(MENU_MTPNP_CARD2_OWNER_NUMBER_EDIT, HighlightCard2OwnerNumberEdit);
    /* phb extra number end */
}

static void HighlightDMShowOwnerNumber(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(EntryDMShowOwnerNumber, KEY_EVENT_UP);
    SetKeyHandler(EntryDMShowOwnerNumber, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void EntryDMShowOwnerNumber(void)
{
    mmi_mtpnp_entry_menu(SCR_MTPNP_DM_SHOW_OWNER_NUMBER, ExitDMShowOwnerNumber, EntryDMShowOwnerNumber,
                         MENU_MTPNP_DM_SHOW_OWNER_NUMBER, STR_OWN_NO, MAIN_MENU_TITLE_SETTINGS_ICON);
    
}

static void ExitDMShowOwnerNumber(void)
{
    S16 error;

    if (g_phnset_cntx_p->ShowOwnNumDirtyFlag == TRUE)
    {
        WriteValue(NVRAM_SETTING_OWNER_NO, &(g_phnset_cntx_p->curShowOwnNumStatus), DS_BYTE, &error);
        g_phnset_cntx_p->ShowOwnNumDirtyFlag = FALSE;
    }    

    MTPNP_AD_Update_Show_Owner_Number_Flag();
}

/* card2 phone setting */
void HighlightCard2PhbExtra(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryCard2PhbExtra, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryCard2PhbExtra, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void EntryCard2PhbExtra(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
#if 0
/* under construction !*/
#endif
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_CARD2_PHB_EXTRA, ExitCard2PhbExtra, EntryCard2PhbExtra, MTPNP_NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_PHB_EXTRA);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_MTPNP_CARD2_PHBEXTRA);

    /* 4. Get attribute of menu to be displayed */
    /*nDispAttribute = GetDispAttributeOfItem(MENU_MTPNP_CALL_SETTING); */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MENU_MTPNP_CARD2_PHBEXTRA, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MTPNP_CARD2_PHBEXTRA);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_MTPNP_CARD2_PHBEXTRA, ItemType);

    ShowCategory52Screen(STRING_MTPNP_PHB_EXTRA, IMG_SCR_PBOOK_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void ExitCard2PhbExtra(void)
{
    /* Update the card2 owner number flag nvram */
    MTPNP_AD_Update_Show_Owner_Number_Flag();
}

/* card2 owner number */
static void MTPNP_PFAL_Update_Card2_MSISDN_Index(MTPNP_INT index)
{
    g_hilite_card2_owner_number_idx = index;
}

static MTPNP_UINT MTPNP_PFAL_Get_Card2_MSISDN_Index(void)
{
    return g_hilite_card2_owner_number_idx;
}

void HighlightCard2OwnerNumber(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    MTPNP_PFAL_Update_Card2_MSISDN_Index(0);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Owner_Number_Pre_Entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Owner_Number_Pre_Entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_Owner_Number_Pre_Entry(void)
{
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        MTPNP_PFAL_Owner_Number_Prepare();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


void MTPNP_PFAL_Owner_Number_Prepare(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FINISHED_IND, MTPNP_PFAL_MSISDN_Load_Finished);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FAIL_IND, MTPNP_PFAL_MSISDN_Load_Failed);
    MTPNP_AD_Prepare_Card2_Owner_Number();
}

void MTPNP_PFAL_MSISDN_Load_Finished(void *inMsg)
{
    MTPNP_UINT8 *ready_flag = (MTPNP_UINT8 *) inMsg;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FINISHED_IND);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FAIL_IND);

    if (!(*ready_flag))
    {
        MTPNP_PFAL_Refresh_Card2_Owner_Number();
    }
    else
    {
        if (GetActiveScreenId() == SCR_IN_PROGRESS_PHB)
        {
            MTPNP_PFAL_Entry_Owner_Number();
        }
    }
}


void MTPNP_PFAL_MSISDN_Load_Failed(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FINISHED_IND);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_LOAD_FAIL_IND);

    DisplayPopup(
        (PU8) GetString(STR_NO_OWNER_NUMBER_MESSAGE),
        IMG_GLOBAL_EMPTY,
        TRUE,
        PHB_NOTIFY_TIMEOUT,
        ERROR_TONE);
}


void MTPNP_PFAL_Entry_Owner_Number(void)
{
    MTPNP_PFAL_Refresh_Card2_Owner_Number();
    MTPNP_PFAL_Update_Card2_Owner_Number_Record();

    EntryCard2OwnerNumber();
}

void MTPNP_PFAL_Update_Card2_Owner_Number_Record(void)
{
    MTPNP_UINT8 i = 0;

    MTPNP_OSAL_memset(g_owner_number_record, 0x0, sizeof(ST_MTPNP_OWNER_NUMBER_RECORD) * MAX_SIM_ENTRIES);

    if (!MTPNP_AD_Card2_Owner_Number_Is_Ready())
        return;

    for (i = 0; i < MTPNP_AD_Get_Card2_Owner_Number_Count(); i++)
    {
        MTPNP_AD_Get_MSISDN_Name(i, (MTPNP_UINT8 *) g_owner_number_record[i].name);
        MTPNP_AD_Get_MSISDN_Number(i, (MTPNP_UINT8 *) g_owner_number_record[i].number);
    }
}

void EntryCard2OwnerNumber(void)
{
    MTPNP_UINT8 *names[MAX_PB_OWNER_NUMBERS];
    MTPNP_UINT16 i;
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 count = 0;

    EntryNewScreen(SCR_CARD2_OWNER_NUMBERS, mmi_phb_exit_owner_number, EntryCard2OwnerNumber, MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_OWNER_NUMBERS);

    count = MTPNP_AD_Get_Card2_Owner_Number_Count();

#if defined(__MMI_PHB_ALS_SUPPORT__)
    /* reset subMenuDataPtrs before use */
    subMenuDataPtrs[0] = subMenuData[0];
    MTPNP_OSAL_memset((MTPNP_CHAR *) subMenuDataPtrs[0], 0, MAX_SUB_MENU_SIZE);

    switch (MTPNP_AD_Get_Card2CurrLineID())
    {
    case MTPNP_AD_LINE_1:
        i = 0;
        break;
    case MTPNP_AD_LINE_2:
        i = 1;
        break;
    default:
        i = 0;
        break;
    }

    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].name))
    {
        names[0] = (MTPNP_UINT8 *) g_owner_number_record[i].name;
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].number))
        {
            subMenuDataPtrs[0] = (MTPNP_UINT8 *) g_owner_number_record[i].number;
        }
        else
        {
            subMenuDataPtrs[0] = (MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }
    else
    {
        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].number))
        {
            names[0] = (MTPNP_UINT8 *) g_owner_number_record[i].number;
            subMenuDataPtrs[0] = NULL;
        }
        else
        {
            names[0] = (MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY_LIST);
            subMenuDataPtrs[0] = NULL;
        }
    }
    g_phb_cntx.active_index = (MTPNP_UINT16) g_callset_context.LineID;
    count = 1;
#else /* defined(__MMI_PHB_ALS_SUPPORT__) */

#if defined(__MMI_PHB_DISPLAY_ONE_MSISDN__)
    count = 1;
#endif

    for (i = 0; i < count; i++)
    {
        /* reset subMenuDataPtrs before use */
        subMenuDataPtrs[i] = subMenuData[i];
        MTPNP_OSAL_memset((MTPNP_CHAR *) subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);

        if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].name))
        {
            names[i] = (MTPNP_UINT8 *) g_owner_number_record[i].name;
            if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].number))
            {
                subMenuDataPtrs[i] = (MTPNP_UINT8 *) g_owner_number_record[i].number;
            }
            else
            {
                subMenuDataPtrs[i] = (MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY_LIST);
            }
        }
        else
        {
            if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[i].number))
            {
                names[i] = (MTPNP_UINT8 *) g_owner_number_record[i].number;
                subMenuDataPtrs[i] = NULL;
            }
            else
            {
                names[i] = (MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY_LIST);
                subMenuDataPtrs[i] = NULL;
            }
        }
    }

    RegisterHighlightHandler(MTPNP_PFAL_Update_Card2_MSISDN_Index);
#endif /* defined(__MMI_PHB_ALS_SUPPORT__) */

    ShowCategory53Screen(STRING_MTPNP_OWNER_NUMBER,
                         IMG_SCR_PBOOK_CAPTION,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK, count, names, (U16 *) gIndexIconsImageList, subMenuDataPtrs, 0, 0, guiBuffer);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Entry_Card2_Owner_Number_Option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Entry_Card2_Owner_Number_Option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_Entry_Card2_Owner_Number_Option(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT16 nStrItemList[2];
    MTPNP_UINT16 nNumofItem;

    EntryNewScreen(SCR_CARD2_OWNER_NUMBER_OPTIONS,
                   MTPNP_PFAL_Exit_Card2_Owner_Number_Option, MTPNP_PFAL_Entry_Card2_Owner_Number_Option, MTPNP_NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_OWNER_NUMBER_OPTIONS);
    nNumofItem = GetNumOfChild(MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION);
    GetSequenceStringIds(MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION, nStrItemList);
    SetParentHandler(MENU_MTPNP_CARD2_OWNER_NUMBER_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
                         IMG_SCR_PBOOK_CAPTION,
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK,
                         IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);
}

void MTPNP_PFAL_Exit_Card2_Owner_Number_Option(void)
{
    g_card2_msisdn_scr_end_id = SCR_CARD2_OWNER_NUMBER_OPTIONS;
}

void HighlightCard2OwnerNumberErase(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Card2_Owner_Number_Erase_Prepare, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_Card2_Owner_Number_Erase_Prepare(void)
{
    if (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[g_hilite_card2_owner_number_idx].name) ||
        MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_owner_number_record[g_hilite_card2_owner_number_idx].number))
    {
        MTPNP_PFAL_Card2_Owner_Number_Erase_Confirm();
    }
    else
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_EMPTY),
                     IMG_GLOBAL_EMPTY, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, EMPTY_LIST_TONE);
    }
}

void MTPNP_PFAL_Card2_Owner_Number_Erase_Confirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES,
                   IMG_GLOBAL_YES,
                   STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_ERASE_QUERY), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Card2_Erase_MSISDN_Record, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MTPNP_PFAL_Goback_2_History, KEY_EVENT_UP);
}

void MTPNP_PFAL_Erase_Card2_MSISDN_Record_Succeed(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP);

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_ID_PHB_ERASED),
                 IMG_GLOBAL_ACTIVATED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_EDIT);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_OPTIONS);

    MTPNP_PFAL_Refresh_Card2_Owner_Number();
    MTPNP_PFAL_Update_Card2_Owner_Number_Record();
}

void MTPNP_PFAL_Erase_Card2_MSISDN_Record_Failed(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP);

    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED),
                 IMG_GLOBAL_UNFINISHED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_OPTIONS);
}

void MTPNP_PFAL_Card2_Erase_MSISDN_Record(void)
{
    if (Slave_g_phb_edit_owner == MTPNP_TRUE)
    {
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    }
    else
    {
        mmi_phb_show_in_progress(STR_PHB_ERASING, IMG_GLOBAL_ERASED);
    }

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP,
                                      MTPNP_PFAL_Erase_Card2_MSISDN_Record_Succeed);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP,
                                      MTPNP_PFAL_Erase_Card2_MSISDN_Record_Failed);

    MTPNP_AD_Update_MSISDN_Record(MTPNP_TRUE,
                                  MTPNP_CODING_SCHEME_DEFAULT,
                                  MTPNP_NULL, MTPNP_NULL, MTPNP_AD_CSMCC_DEFAULT_ADDR, g_hilite_card2_owner_number_idx);
}

void HighlightCard2OwnerNumberEdit(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Card2_Owner_Number_Edit_Prepare, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Card2_Owner_Number_Edit_Prepare, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_Card2_Owner_Number_Edit_Prepare(void)
{
    MTPNP_OSAL_memset(g_owner_name_edit_buff, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_owner_name_edit_buff,
                                   (MTPNP_CHAR *) g_owner_number_record[g_hilite_card2_owner_number_idx].name);
    MTPNP_OSAL_memset(g_owner_number_edit_buff, 0, (MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH);
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) g_owner_number_edit_buff,
                                   (MTPNP_CHAR *) g_owner_number_record[g_hilite_card2_owner_number_idx].number);
    EntryCard2OwnerNumberEdit();
}

void EntryCard2OwnerNumberEdit(void)
{
    MTPNP_UINT8 *guiBuffer;
    MTPNP_UINT8 *inputBuffer;
    MTPNP_UINT16 inputBufferSize;
    MTPNP_UINT16 DetailPbNameImageList[2];
    MTPNP_UINT8 item_index = 0;

    EntryNewScreen(SCR_CARD2_OWNER_NUMBER_EDIT, ExitCard2OwnerNumberEdit, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_OWNER_NUMBER_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_CARD2_OWNER_NUMBER_EDIT, &inputBufferSize);

    if (MTPNP_AD_MSISDN_GetNameLen() != 0)
    {
        SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemFullScreenEdit(
            &wgui_inline_items[item_index],
            STR_OWNER_NAME_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            (PU8) g_owner_name_edit_buff,
            (S32) (MTPNP_AD_MSISDN_GetNameLen() + 1),
            INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING);
        SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
        DetailPbNameImageList[item_index++] = IMG_NAME;
    }

    SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[item_index],
                          (MTPNP_UINT8 *) g_owner_number_edit_buff,
                          MAX_PB_NUMBER_LENGTH + 1, INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
    DisableInlineItemHighlight(&wgui_inline_items[item_index]);
    DetailPbNameImageList[item_index++] = IMG_MOBILE_NUMBER;

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
    }

    ShowCategory57Screen(STR_GLOBAL_EDIT,
                         IMG_SCR_PBOOK_CAPTION,
                         STR_GLOBAL_EDIT,
                         IMG_EDIT_LSK,
                         STR_GLOBAL_DONE, IMG_DONE_RSK, item_index, DetailPbNameImageList, wgui_inline_items, 0, guiBuffer);

    SetCategory57RightSoftkeyFunctions(MTPNP_PFAL_Card2_Owner_Number_Update_Confirm, GoBackHistory);
}

void ExitCard2OwnerNumberEdit(void)
{
    history h;
    MTPNP_UINT16 inputBufferSize;

    g_card2_msisdn_scr_end_id = SCR_CARD2_OWNER_NUMBER_EDIT;
    CloseCategory57Screen();
    h.scrnID = SCR_CARD2_OWNER_NUMBER_EDIT;
    h.entryFuncPtr = EntryCard2OwnerNumberEdit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8 *) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}

void MTPNP_PFAL_Card2_Owner_Number_Update_Confirm(void)
{
    DisplayConfirm(STR_GLOBAL_YES,
                   IMG_GLOBAL_YES,
                   STR_GLOBAL_NO, IMG_GLOBAL_NO, get_string(STR_GLOBAL_SAVE_ASK), IMG_GLOBAL_QUESTION, WARNING_TONE);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Card2_Update_MSISDN_Record_Prepare, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_3_history_and_clear, KEY_EVENT_UP);
}

void MTPNP_PFAL_Card2_Update_MSISDN_Record_Prepare(void)
{
    MTPNP_UINT16 str_id = 0;
    if (!mmi_phb_op_check_valid_number(g_owner_number_edit_buff))
    {
        str_id = STR_ID_PHB_NUM_INVALID;
        DisplayPopup((MTPNP_UINT8 *) GetString(str_id), IMG_GLOBAL_ERROR, MTPNP_FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }

    if (mmi_ucs2strlen((S8*) g_owner_number_record[g_hilite_card2_owner_number_idx].number) >= 20)
    {
        Slave_g_phb_edit_owner = MTPNP_TRUE;
        MTPNP_PFAL_Card2_Erase_MSISDN_Record();
    }
    else
    {
        MTPNP_PFAL_Card2_Update_MSISDN_Record();
    }
}

void MTPNP_PFAL_Card2_Update_MSISDN_Record(void)
{
    MTPNP_UINT8 ton_npi;
    E_MTPNP_CODING_SCHEME coding_scheme;
    MTPNP_CHAR name_buff[32];
    MTPNP_CHAR number_buff[41];

    if (Slave_g_phb_edit_owner != MTPNP_TRUE)
    {
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    }

    MTPNP_OSAL_memset(name_buff, 0, 32);

    if (GetUCS2Flag(g_owner_name_edit_buff))
    {
        coding_scheme = MTPNP_CODING_SCHEME_UCS2;
        MTPNP_PFAL_Unicode_Memory_Copy(name_buff,
                                       g_owner_name_edit_buff,
                                       MTPNP_PFAL_Unicode_String_Length(g_owner_name_edit_buff));
    }
    else
    {
        coding_scheme = MTPNP_CODING_SCHEME_ASCII;
        MTPNP_PFAL_Unicode_To_Ansii_String(name_buff, g_owner_name_edit_buff);
    }

    MTPNP_OSAL_memset(number_buff, 0, 41);

    if (g_owner_number_edit_buff[0] == '+')
    {
        ton_npi = MTPNP_AD_CSMCC_INTERNATIONAL_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, g_owner_number_edit_buff + ENCODING_LENGTH);
    }
    else
    {
        ton_npi = MTPNP_AD_CSMCC_DEFAULT_ADDR;
        MTPNP_PFAL_Unicode_To_Ansii_String(number_buff, g_owner_number_edit_buff);
    }

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP,
                                      MTPNP_PFAL_Update_Card2_MSISDN_Record_Succeed);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP,
                                      MTPNP_PFAL_Update_Card2_MSISDN_Record_Failed);

    MTPNP_AD_Update_MSISDN_Record(MTPNP_FALSE,
                                  coding_scheme, name_buff, number_buff, ton_npi, g_hilite_card2_owner_number_idx);
}

void MTPNP_PFAL_Update_Card2_MSISDN_Record_Succeed(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP);

    Slave_g_phb_edit_owner = MTPNP_FALSE;
    DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_SAVED),
                 IMG_GLOBAL_ACTIVATED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_EDIT);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_OPTIONS);

    MTPNP_PFAL_Refresh_Card2_Owner_Number();
    MTPNP_PFAL_Update_Card2_Owner_Number_Record();
}

void MTPNP_PFAL_Update_Card2_MSISDN_Record_Failed(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_SUCCEED_RSP);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_MSISDN_RECORD_UPDATE_FAILED_RSP);

    Slave_g_phb_edit_owner = MTPNP_FALSE;
 //   DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_UNFINISHED),
 //                IMG_GLOBAL_UNFINISHED, MTPNP_TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);

//    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_EDIT);
//    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_OPTIONS);
}

void MTPNP_PFAL_MSISDN_HandleUpdateFail(MTPNP_UINT16 fail_cause)
{
        if (fail_cause== MMI_SIM_EF_RECORD_FULL)
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
    //DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_EDIT);
    DeleteScreenIfPresent(SCR_CARD2_OWNER_NUMBER_OPTIONS);
}

void HighlightCard2SDLNumber(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_sim2_sdn_list_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_sim2_sdn_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
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
void mmi_phb_sim2_sdn_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        g_slave_phb_sim_list_count = 0;
        g_slave_phb_read_index = 1;
        mmi_phb_sim2_sdn_get_entry_req();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sdn_get_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to get the SDL numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sdn_get_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SDN_GET_ENTRY_REQ);

    myMsgPtr =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    myMsgPtr->index = g_slave_phb_read_index; /* Begin from 1 */
    myMsgPtr->record_index = 0xFFFF;
    myMsgPtr->storage = MMI_SIM;
    myMsgPtr->type = MMI_PHB_SDN;
    myMsgPtr->no_data = MAX_ENTRIES_IN_LIST;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetSlaveProtocolEventHandler(mmi_phb_sim2_sdn_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sdn_get_entry_rsp
 * DESCRIPTION
 *  Reads the SDL numbers back from L4
 * PARAMETERS
 *  info        [IN]        Return result from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sdn_get_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_SDN_GET_ENTRY_RSP);

    ClearSlaveProtocolEventHandler(PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        /* Begin to assign to list */
        for (i = 0; i < localPtr->no_list; i++)
        {
            /* No Space */
            if (g_slave_phb_sim_list_count >= MAX_SIM_ENTRIES)
            {
                continue;
            }

            /* Empty Entry */
            if ((localPtr->list[i].alpha_id.name_length == 0) && (localPtr->list[i].tel.length == 0))
            {
                continue;
            }

            g_slave_phb_sim_list[g_slave_phb_sim_list_count].storage = localPtr->list[i].storage;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].index = localPtr->list[i].index;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].record_index = localPtr->list[i].record_index;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].tel.type = localPtr->list[i].tel.type;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].tel.length = localPtr->list[i].tel.length;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].alpha_id.name_length = localPtr->list[i].alpha_id.name_length;
            g_slave_phb_sim_list[g_slave_phb_sim_list_count].alpha_id.name_dcs = localPtr->list[i].alpha_id.name_dcs;

            if (g_slave_phb_sim_list[g_slave_phb_sim_list_count].alpha_id.name_dcs == MMI_PHB_UCS2)
            {
                BigEndianToLittleEndian(
                    (PS8) g_slave_phb_sim_list[g_slave_phb_sim_list_count].alpha_id.name,
                    (PS8) localPtr->list[i].alpha_id.name);
            }
            else
            {
                mmi_asc_to_ucs2(
                    (PS8) g_slave_phb_sim_list[g_slave_phb_sim_list_count].alpha_id.name,
                    (PS8) localPtr->list[i].alpha_id.name);
            }

            if ((localPtr->list[i].tel.length > 0) && ((localPtr->list[i].tel.type & 0x10) != 0))
            {
                g_slave_phb_sim_list[g_slave_phb_sim_list_count].tel.number[0] = '+';

                mmi_asc_to_ucs2(
                    (PS8) (g_slave_phb_sim_list[g_slave_phb_sim_list_count].tel.number + ENCODING_LENGTH),
                    (PS8) localPtr->list[i].tel.number);
            }
            else
            {
                mmi_asc_to_ucs2(
                    (PS8) g_slave_phb_sim_list[g_slave_phb_sim_list_count].tel.number,
                    (PS8) localPtr->list[i].tel.number);
            }

            g_slave_phb_sim_list_count++;
        }

        /* Try to read more entry if exists. */
        if (localPtr->no_list == MAX_ENTRIES_IN_LIST)
        {
            g_slave_phb_read_index += MAX_ENTRIES_IN_LIST;
            mmi_phb_sim2_sdn_get_entry_req();
            return;
        }
    }
    else
    {
        /* TBD - what to do if result flag is false */
    }

    if (g_slave_phb_sim_list_count)
    {
        mmi_phb_sim2_entry_sdn_list();
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
 *  mmi_phb_sim2_entry_sdn_list
 * DESCRIPTION
 *  Displays the Service Dail Numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_entry_sdn_list(void)
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
    EntryNewScreen(SCR_MTPNP_SDN_LIST, mmi_phb_sim2_exit_sdn_list, mmi_phb_sim2_entry_sdn_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SDN_LIST);

    for (i = 0; i < g_slave_phb_sim_list_count; ++i)
    {
        /* reset subMenuDataPtrs before use */
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
               
        if (mmi_ucs2strlen((PS8) g_slave_phb_sim_list[i].alpha_id.name))
        {
            names[i] = g_slave_phb_sim_list[i].alpha_id.name;
            if (mmi_ucs2strlen((PS8) g_slave_phb_sim_list[i].tel.number))
            {
                subMenuDataPtrs[i] = g_slave_phb_sim_list[i].tel.number;
            }
            else
            {
                subMenuDataPtrs[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
            }
        }
        else
        {
            if (mmi_ucs2strlen((PS8) g_slave_phb_sim_list[i].tel.number))
            {
                names[i] = g_slave_phb_sim_list[i].tel.number;
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
        STRING_MTPNP_SDL_NUMBER,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_DIAL,
        IMG_SDL_CALL_LSK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_slave_phb_sim_list_count,
        names,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);

    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        SetLeftSoftkeyFunction(mmi_phb_sim2_sdn_list_make_call, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_sim2_sdn_list_make_call, KEY_SEND, KEY_EVENT_UP);    
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_exit_sdn_list
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_sdn_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_exit_sdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_MTPNP_SDN_LIST;
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
void mmi_phb_sim2_sdn_list_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) g_slave_phb_sim_list[g_phb_cntx.active_index].tel.number))
    {
        g_phb_cntx.dial_from_list = MMI_PHB_SDN;
        if (g_slave_phb_sim_list[g_phb_cntx.active_index].tel.number[0] == '+' &&
            g_slave_phb_sim_list[g_phb_cntx.active_index].tel.number[(mmi_ucs2strlen
                                                                ((const S8*)(g_slave_phb_sim_list[g_phb_cntx.active_index].
                                                                              tel.number)) - 1) * ENCODING_LENGTH] ==
            '#')
        {
            MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
            MakeCall((PS8) g_slave_phb_sim_list[g_phb_cntx.active_index].tel.number + 2);
        }
        else
        {
            MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);        
            MakeCall((PS8) g_slave_phb_sim_list[g_phb_cntx.active_index].tel.number);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_NO_NUMBER_TO_DIAL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}

/* sos number */
void HighlightCard2SOSNumber(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_sim2_sos_list_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_sim2_sos_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sos_list_pre_entry
 * DESCRIPTION
 *  Checks and calls the L4 reuest function to fetch SOS numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sos_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
    {
        mmi_phb_show_in_progress(STR_PROCESSING_PHONEBOOK, IMG_PROCESSING_PHONEBOOK);
        mmi_phb_sim2_sos_list_get_entry_req();
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sos_list_get_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to get the SOS numbers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sos_list_get_entry_req(void)
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
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetSlaveProtocolEventHandler(mmi_phb_sim2_sos_list_get_entry_rsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sos_list_get_entry_rsp
 * DESCRIPTION
 *  Reads SOS numbers from L4
 * PARAMETERS
 *  info        [IN]        Return from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sos_list_get_entry_rsp(void *info)
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
    ClearSlaveProtocolEventHandler(PRT_PHB_GET_ENTRY_BY_INDEX_RSP);
    localPtr = (MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        g_slave_phb_sim_list_count = (localPtr->no_list < MAX_SIM_ENTRIES) ? localPtr->no_list : MAX_SIM_ENTRIES;

        for (i = 0; i < g_slave_phb_sim_list_count && i < MAX_SIM_SOS_ENTRIES; ++i)
        {
            g_slave_phb_sim_list[i].storage = localPtr->list[i].storage;
            g_slave_phb_sim_list[i].index = localPtr->list[i].index;
            g_slave_phb_sim_list[i].record_index = localPtr->list[i].record_index;
            g_slave_phb_sim_list[i].tel.type = localPtr->list[i].tel.type;

            if ((g_slave_phb_sim_list[i].tel.length > 0) && ((g_slave_phb_sim_list[i].tel.type & 0x10) != 0))
            {
                number[0] = '+';
                memcpy((void*)&number[1], (void*)&localPtr->list[i].tel.number[0], MAX_PB_NUMBER_LENGTH - 1);
                mmi_asc_to_ucs2((PS8) & g_slave_phb_sim_list[i].tel.number, (PS8) number);

            }
            else
            {
                g_slave_phb_sim_list[i].tel.length = localPtr->list[i].tel.length;
                memcpy((void*)&number, (void*)&localPtr->list[i].tel.number, MAX_PB_NUMBER_LENGTH);
                mmi_asc_to_ucs2((PS8) & g_slave_phb_sim_list[i].tel.number, (PS8) number);
            }
        }
    }
    else    /* TBD - what to do if result flag is false */
    {
        g_slave_phb_sim_list_count = 0;
    }

    mmi_phb_sim2_entry_sos_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_entry_sos_list
 * DESCRIPTION
 *  Displays the SOS list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_entry_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 index = 0;
    S32 display_index = 0;
    S16 error = 0;
    U8 *sub_ptr[MAX_SIM_ENTRIES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Prepare list */
    for (index = 0; index < g_slave_phb_sim_list_count; ++index)
    {
        g_slave_phb_sos_list[display_index] = (U8*) g_slave_phb_sim_list[index].tel.number;
        sub_ptr[display_index++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM2);
    }

    if (display_index == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, TRUE, PHB_NOTIFY_TIMEOUT, EMPTY_LIST_TONE);
        return;
    }

    EntryNewScreen(SCR_MTPNP_SOS_LIST, mmi_phb_sim2_exit_sos_list, mmi_phb_sim2_entry_sos_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_SOS_LIST);
    RegisterHighlightHandler(mmi_phb_sim2_sos_list_get_index);

    for (index = 0; index < display_index; index++) /* subMenuDataPtrs[] will be clear in EntryNewScreen, so reassign here. */
    {
        subMenuDataPtrs[index] = sub_ptr[index];
    }

    ShowCategory53Screen(
        STRING_MTPNP_SOS_NUMBER,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_DIAL,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        display_index /* (MAX_NVRAM_SOS_ENTRIES + g_phb_sim_list_count ) */ ,
        g_slave_phb_sos_list,
        (U16*) gIndexIconsImageList,
        subMenuDataPtrs,
        0,
        0,
        guiBuffer);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        SetLeftSoftkeyFunction(mmi_phb_sim2_sos_list_pre_confirm_call, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_sim2_sos_list_pre_confirm_call, KEY_SEND, KEY_EVENT_UP);    
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_exit_sos_list
 * DESCRIPTION
 *  Exit function of mmi_phb_entry_sos_list()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_exit_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_MTPNP_SOS_LIST;
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
void mmi_phb_sim2_sos_list_get_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index = (S16) index;
}



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
void mmi_phb_sim2_sos_list_pre_confirm_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2cmp((PS8) g_slave_phb_sos_list[g_phb_cntx.active_index], (PS8) GetString(STR_GLOBAL_EMPTY_LIST)) == 0)
    {
        DisplayPopup((PU8) GetString(STR_NO_NUMBER_TO_DIAL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        mmi_phb_sim2_entry_sos_list_confirm_call();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_entry_sos_list_confirm_call
 * DESCRIPTION
 *  Confirm Make SOS Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_entry_sos_list_confirm_call(void)
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

    SetLeftSoftkeyFunction(mmi_phb_sim2_sos_list_make_call, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim2_sos_list_make_call
 * DESCRIPTION
 *  Makes call to the SOS number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sim2_sos_list_make_call(void)
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
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    MakeCall((S8*) g_slave_phb_sos_list[g_phb_cntx.active_index]);
}
/* sos number end */

/* get slave sim entry start */
MMI_PHB_ENTRY_STRUCT *mmi_phb_get_slave_sim_entry(void)
{
    return &g_slave_phb_sim_list[g_phb_cntx.active_index];
}
/* get slave sim entry end */

void HighlightCard2ShowOwnerNumber(void)
{
    MTPNP_UINT16 index;
    index = GetCurrHiliteID();

    if (MTPNP_AD_Is_Show_Card2_Owner_Number())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /*Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Toggle_Card2ShowOwnNo, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /*Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_Toggle_Card2ShowOwnNo(void)
{
    MTPNP_UINT16 index;

    index = GetCurrHiliteID();

    if (!MTPNP_AD_Is_Show_Card2_Owner_Number())
    {
        MTPNP_AD_Show_Card2_Owner_Number();
    }
    else
    {
        MTPNP_AD_Hide_Card2_Owner_Number();
    }

    if (MTPNP_AD_Is_Show_Card2_Owner_Number())
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    RedrawCategoryFunction();
    HighlightCard2ShowOwnerNumber();
}

static void HintCard2ShowOwnerNumber(U16 index)
{
    if (MTPNP_AD_Is_Show_Card2_Owner_Number())
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_GLOBAL_ON));
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) hintData[index], (MTPNP_CHAR *) GetString(STR_GLOBAL_OFF));
    }
}

MTPNP_UINT8 MTPNP_PFAL_Card2_Get_User_Defined_Max_Owner_Number_Length(void)
{
    return (MTPNP_UINT8) MTPNP_AD_MAX_OWNER_DISPLAY_LEN;
}


/* card2 owner number */

#endif /* __MMI_DUAL_SIM_MASTER__ */
