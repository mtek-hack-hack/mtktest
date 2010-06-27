#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "PhoneBookTypes.h"
#include "PhoneBookDef.h"
#include "GlobalDefs.h"
#include "wgui_categories_popup.h"
#include "custom_mmi_default_value.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_header.h"
#include "MMI_features.h"
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
#include "SettingsGdcl.h"
#include "SettingProfile.h"
#include "HistoryGprot.h"
#include "mainmenudef.h"
#include "CallsDefs.h"
#include "CommonScreens.h"
#include "PhoneBookProt.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "wgui_categories_inputsenum.h"
#include "wgui_categories_inputs.h"
#include "ProtocolEvents.h"
#include "SimDetectionDef.h"
#include "NVRAMProt.h"
#include "SettingGenum.h"
#include "SecuritySetup.h"
#include "CallFixedDial.h"
#include "PhoneBookGprot.h"
#include "CallManagementGprot.h"
#include "SimDetectionGprot.h"

#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_FDN.h"
#include "MTPNP_PFAL_DM_Setup.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_category_screen.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_OSAL_common.h"

extern void SettingInlineCustomFunction(void);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
/* under construction !*/
    #endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
/* under construction !*/
/* under construction !*/
        #endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#include "SettingStructs.h"

void MTPNP_PFAL_EntrySECSETFixDial(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;
    U8 *FdlType[MAX_SUB_MENUS];

    EntryNewScreen(SCR_CARD2_SECSET_FIX_DIAL, NULL, MTPNP_PFAL_EntrySECSETFixDial, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_FIX_DIAL);

    nNumofItem = GetNumOfChild(MENU_MTPNP_FDN_MAIN);

    GetSequenceStringIds(MENU_MTPNP_FDN_MAIN, nStrItemList);

    SetParentHandler(MENU_MTPNP_FDN_MAIN);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ConstructHintsList(MENU_MTPNP_FDN_MAIN, FdlType);

    ShowCategory52Screen(
        STR_MENU9167_FIXED_DIAL,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (MTPNP_UINT16*) gIndexIconsImageList,
        FdlType,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_SECSETGetFdlStatusRsp(void *info)
{
    mmi_smu_read_file_info_rsp_struct *resp;

    resp = (mmi_smu_read_file_info_rsp_struct*) (info);

    if (resp->result.flag == 0  /* ok */
    #ifdef __GEMINI__
        && (sim_service_table_query(SERVICE_FDN, 1) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_FDN, 0) == SERVICE_ALLOCATE)
    #else
        && (sim_service_table_query(SERVICE_FDN) == SERVICE_SUPPORT || sim_service_table_query(SERVICE_FDN) == SERVICE_ALLOCATE)
    #endif
        )                       /* diamond, 2006/01/26 Need to check both FDN file and SIM service table */
    {
        gFDLBDLContext.MaxFDL = resp->num_of_rec;
        MTPNP_PFAL_EntrySECSETFixDial();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_NO_FDL), IMG_GLOBAL_WARNING, 0, ST_NOTIFYDURATION, WARNING_TONE);
    }
}

void MTPNP_PFAL_SECSETGetFdlStatusReq(void)
{
    MYQUEUE msgStruct;
    mmi_smu_read_file_info_req_struct *fdlstatus;

    ClearInputEventHandler(MMI_DEVICE_ALL);

    fdlstatus = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    fdlstatus->file_idx = FILE_FDN_IDX;

    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETGetFdlStatusRsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C_2;
    msgStruct.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) fdlstatus;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}

void MTPNP_PFAL_SECSETSetFdlModeRsp(void *info)
{
    mmi_smu_set_dial_mode_rsp_struct *resp;
    U16 index;
    
    index = GetCurrHiliteID();
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    
    resp = (mmi_smu_set_dial_mode_rsp_struct*) (info);
    
    if (resp->result == 1)
    {
        gSecuritySetupContext.FdlStatus_2 = !gSecuritySetupContext.FdlStatus_2;
        MTPNP_AD_ADN_SetLoadFinish(MTPNP_FALSE);
        if (gSecuritySetupContext.FdlStatus_2)
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_OFF, 0);
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
        else
        {
            mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
            Category52ChangeItemDescription(0, hintData[index]);
            change_left_softkey(STR_GLOBAL_ON, 0);
            DisplayPopup((PU8) GetString(STR_FDL_IS_OFF), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 0, ST_NOTIFYDURATION, ERROR_TONE);
    }
    
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);
}

void MTPNP_PFAL_SECSETSetFdlModeReq(void)
{
    MYQUEUE msgStruct;
    MMISMUDIALMODEREQSTRUCT *dailStruct;

    dailStruct = OslConstructDataPtr(sizeof(MMISMUDIALMODEREQSTRUCT));

    if (gSecuritySetupContext.FdlStatus_2)
    {
        dailStruct->on_off = (U8) MMI_OFF_OPTION;
    }
    else
    {
        dailStruct->on_off = (U8) MMI_ON_OPTION;
    }

    dailStruct->type = MMI_TYPE_FDN;
    memset(dailStruct->pin, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));

    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETSetFdlModeRsp, PRT_MMI_SMU_SET_DIAL_MODE_RSP);

    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C_2;
    msgStruct.oslMsgId = PRT_MMI_SMU_SET_DIAL_MODE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) dailStruct;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}

void MTPNP_PFAL_SECSETGetFdlBdlModeRsp(void *info)
{
    DIALMODESTATUSRSPSTRUCT *resp;

    resp = (DIALMODESTATUSRSPSTRUCT*) (info);

    switch (resp->dial_mode)
    {
        case MMI_TYPE_ADN:
            gSecuritySetupContext.FdlStatus_2 = 0;
            break;
        case MMI_TYPE_FDN:
            gSecuritySetupContext.FdlStatus_2 = 1;
            break;
        case MMI_TYPE_BDN:
            gSecuritySetupContext.FdlStatus_2 = 0;
            break;
        case MMI_TYPE_FDN_BDN:
            gSecuritySetupContext.FdlStatus_2 = 1;
            break;
        default:
            break;
    }
}

void MTPNP_PFAL_SECSETGetFdlBdlModeReq(void)
{
    MYQUEUE msgStruct;
    
    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETGetFdlBdlModeRsp, PRT_MMI_SMU_GET_DIAL_MODE_RSP);
    
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C_2;
    msgStruct.oslMsgId = PRT_MMI_SMU_GET_DIAL_MODE_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}

void MTPNP_AD_Card2_FDN_CB_Init_Register(void)
{
}

MTPNP_UINT8 MTPNP_AD_FDN_GetStatus(void)
{
    return gSecuritySetupContext.FdlStatus_2;
}

MTPNP_BOOL MTPNP_AD_FDN_Get_STATE(void)
{
    MTPNP_PFAL_SECSETGetFdlBdlModeReq();
    return MTPNP_TRUE;
}

static MTPNP_UINT8 fdn_name_len;

void MTPNP_AD_FDN_SetNameLen(MTPNP_UINT8 len)
{
    fdn_name_len = len;
}

MTPNP_UINT8 MTPNP_AD_FDN_GetNameLen(void)
{
    return fdn_name_len;
}

MTPNP_BOOL MTPNP_AD_FDN_Return_STATE_Succeed(MTPNP_UINT8 Status)
{
    return MTPNP_FALSE;
}

void MTPNP_PFAL_InitFixedDialList(void)
{
    SetHiliteHandler(MENU_MTPNP_FDN_MAIN, MTPNP_PFAL_HighlightFixedDial);
    SetHintHandler(MENU_MTPNP_FDN_MAIN, MTPNP_PFAL_HintFdl);
    SetHiliteHandler(MENU_MTPNP_MENU_FDN_MODE, MTPNP_PFAL_HighlightFdlMode);
    SetHintHandler(MENU_MTPNP_MENU_FDN_MODE, MTPNP_PFAL_HintFdlMode);
    SetHiliteHandler(MENU_MTPNP_MENU_FDN_LIST, MTPNP_PFAL_HighlightFdlList);

    SetHiliteHandler(MENU_MTPNP_FDN_VIEW_OPTIONS_ADD, MTPNP_PFAL_HighlightAddFDL);
    SetHiliteHandler(MENU_MTPNP_FDN_VIEW_OPTIONS_EDIT, MTPNP_PFAL_HighlightEditFDL);
    SetHiliteHandler(MENU_MTPNP_FDN_VIEW_OPTIONS_DELETE, MTPNP_PFAL_HighlightDeleteFDL);
}

void MTPNP_PFAL_Set_FDN_Mode(void)
{
    gFDLBDLContext.is_set_toggle = 1;
    MTPNP_AD_Set_CHV_Pass_CB(MTPNP_PFAL_SECSETSetFdlModeReq);
    MTPNP_AD_Get_SIM_Status_For_CHV2();
}

void MTPNP_PFAL_HighlightFixedDial(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_PFAL_SECSETGetFdlStatusReq, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_SECSETGetFdlStatusReq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_HighlightFdlMode(void)
{
    if (MTPNP_AD_FDN_GetStatus())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(MTPNP_PFAL_Set_FDN_Mode, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_Set_FDN_Mode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_HighlightFdlList(void)
{
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    SetLeftSoftkeyFunction(MTPNP_PFAL_EntryFdlList, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_EntryFdlList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_HintFdl(U16 index)
{
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (MTPNP_AD_FDN_GetStatus())
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}

void MTPNP_PFAL_HintFdlMode(U16 index)
{
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (MTPNP_AD_FDN_GetStatus())
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF), MAX_SUBMENU_CHARACTERS);
    }
}

void MTPNP_PFAL_SECSETGetFdlEntriesReq(void)
{
    MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT *pMsgIndexReq = NULL;
    MYQUEUE Message;

    pMsgIndexReq =
        (MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT));
    pMsgIndexReq->index = gFDLBDLContext.FDNBDNCount + 1;
    pMsgIndexReq->record_index = 0xFFFF;
    pMsgIndexReq->storage = MMI_SIM;
    pMsgIndexReq->type = MMI_PHB_FDN;
    pMsgIndexReq->no_data = MAX_ENTRIES_IN_LIST;

    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETGetFdlEntriesRsp, PRT_PHB_GET_ENTRY_BY_INDEX_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_PHB_GET_ENTRY_BY_INDEX_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgIndexReq;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_SECSETGetFdlEntriesRsp(void *info)
{
    MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT *localPtr;
    U8 i = 0, j = 0;

    U8 TempBuff[(MAX_PB_NUMBER_LENGTH + 2) * ENCODING_LENGTH];
    U8 *tmpConvertBuf = NULL;
    U16 convertOutLen = 0;

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
            MTPNP_PFAL_SECSETGetFdlEntriesReq();
        }
        else
        {
            MTPNP_PFAL_ViewFDList();

            /*
             *    Retrieve FDN list to ADN buffer when FDN is enable.
             *    Because ADN will not read when FDN is on, so use ADN's buffer to store FDN temporarily
             *    This is for call lookup FDN number usage.
             */
            if (MTPNP_AD_FDN_GetStatus())
            {
                MTPNP_PFAL_ADN_fdn_get_list_to_ram();
            }
        }
    }
    else if (localPtr->result.flag == 1 && localPtr->result.cause == 5)
    {
        /* gFDLBDLContext.FDNBDNCount = 0; */
        MTPNP_PFAL_ViewFDList();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
        DeleteUptoScrID(SCR_CARD2_SECSET_FIX_DIAL);
    }
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_WAITING);
}

void MTPNP_PFAL_ViewFDList(void)
{
    gFDLBDLContext.HighlightedFDN = 0;

    if (mmi_secset_is_call_interrupt())
    {
        extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
        mmi_frm_add_history_before_cm_marker(SCR_CARD2_SECSET_FDN_LIST, MTPNP_PFAL_EntrySECSETFDNList);
    }
    else
    {
        MTPNP_PFAL_EntrySECSETFDNList();
    }
}

void MTPNP_PFAL_ExitSECSETFDNList(void)
{
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        ResetCenterSoftkey();
    }
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */
}

void MTPNP_PFAL_EntrySECSETFDNList(void)
{
    U8 *pstfdlist[MAX_SIM_ENTRIES], *fdlHint[MAX_SIM_ENTRIES];
    U16 index;
    U8 *guiBuffer;
    U16 fdlimagelist[MAX_SIM_ENTRIES];

    EntryNewScreen(SCR_CARD2_SECSET_FDN_LIST, MTPNP_PFAL_ExitSECSETFDNList, MTPNP_PFAL_EntrySECSETFDNList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_FDN_LIST);   /* Getting the Index from history */

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

    RegisterHighlightHandler(MTPNP_PFAL_GetActiveIndex);

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
        SetLeftSoftkeyFunction(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
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

        SetLeftSoftkeyFunction(MTPNP_PFAL_EntrySECSETFDNOption, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_EntrySECSETFDNOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        if (mmi_bootup_get_active_flight_mode() == 0)
        {
            MTPNP_PFAL_CC_HandleSendKeys(MTPNP_PFAL_FdlMakeCall, KEY_EVENT_UP);
        #if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
            MTPNP_PFAL_CC_SetCenterFunc(MTPNP_PFAL_FdlMakeCall);
            SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
        #endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
        }
        else
        {
            SetKeyHandler(0, KEY_SEND, KEY_EVENT_UP);
        }
    }
}

void MTPNP_PFAL_ExitSECSETFDNListReload(void)
{
    if (IsScreenPresent(SCR_CARD2_SECSET_FDN_LIST))
    {
        HistoryReplace(SCR_CARD2_SECSET_FDN_LIST, SCR_CARD2_SECSET_FDN_LIST, MTPNP_PFAL_EntryFdlList);
    }
}

void MTPNP_PFAL_EntrySECSETFDNOption(void)
{
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */

    EntryNewScreen(SCR_CARD2_SECSET_FDN_OPTION, NULL, MTPNP_PFAL_EntrySECSETFDNOption, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_FDN_OPTION);

    nNumofItem = GetNumOfChild(MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN);

    GetSequenceStringIds(MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN, nStrItemList);

    SetParentHandler(MENU_MTPNP_FDN_VIEW_OPTIONS_MAIN);

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

void MTPNP_PFAL_HighlightAddFDL(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    gFDLBDLContext.FDNBDNEdit = FALSE;
    memset(gFDLBDLContext.FDLBDLName, 0, (MAX_NAME_LEN_FSB_LIST + 1) * ENCODING_LENGTH);
    memset(gFDLBDLContext.FDLBDLNumber, 0, (MAX_NUMBER_LEN_FSB_LIST + 1 + 1) * ENCODING_LENGTH);
}

void MTPNP_PFAL_EntrySECSETFDNDetails(void)
{
    U16 nNumofItem; /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    U16 ItemIcons[2];
    U8 *inputBuffer;            /* added for inline edit history */
    U16 inputBufferSize;        /* added for inline edit history */

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
        EntryNewScreen(SCR_CARD2_SECSET_FDN_DETAILS, MTPNP_PFAL_ExitSECSETFDNDetails, NULL, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_CARD2_SECSET_FDN_DETAILS);
        inputBuffer = GetCurrNInputBuffer(SCR_CARD2_SECSET_FDN_DETAILS, &inputBufferSize); /* added for inline edit history */

        nNumofItem = GetNumOfChild(MENU8234_FDL_VIEW_OPTIONS_ADD);

        GetSequenceImageIds(MENU8234_FDL_VIEW_OPTIONS_ADD, ItemIcons);

        InitializeCategory57Screen();

        MTPNP_PFAL_FillFdlInlineEditStruct();

        if (inputBuffer != NULL)    /* added for inline edit history */
        {
            SetCategory57Data(gFDLBDLContext.FDLBDLInlineDisplay, nNumofItem, inputBuffer);     /* sets the data */
        }

        RegisterHighlightHandler(MTPNP_PFAL_GetEntryTitle);

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

        SetCategory57RightSoftkeyFunctions(MTPNP_PFAL_EntrySECSETFDNSaveConfirm, GoBackHistory);
    }
}

void MTPNP_PFAL_ExitSECSETFDNDetails(void)
{
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;
    U16 size;

    CloseCategory57Screen();
    Scr.scrnID = SCR_CARD2_SECSET_FDN_DETAILS;
    Scr.entryFuncPtr = MTPNP_PFAL_EntrySECSETFDNDetails;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    size = (U16) GetCategory57DataSize();       /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);   /* added for inline edit history */
    AddNHistory(Scr, size);
}

void MTPNP_PFAL_FillFdlInlineEditStruct(void)
{
    SetInlineItemActivation(&gFDLBDLContext.FDLBDLInlineDisplay[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &gFDLBDLContext.FDLBDLInlineDisplay[0],
        STR_SETTING_FDL_NAME,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        (PU8) gFDLBDLContext.FDLBDLName,
        /* g_phb_cntx.fdn_name_len + 1, */
        ((MTPNP_AD_FDN_GetNameLen() > MAX_PB_NAME_LENGTH) ? (MAX_PB_NAME_LENGTH + 1) : (MTPNP_AD_FDN_GetNameLen() + 1)),
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

void MTPNP_PFAL_PreNewFdlEntryReq(void)
{
    if (!mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLNumber) && !mmi_ucs2strlen((PS8) gFDLBDLContext.FDLBDLName))
    {
        GoBackHistory();
    }
    else
    {
        MTPNP_PFAL_EntrySECSETFDNSaveConfirm();
    }
}

void MTPNP_PFAL_EntrySECSETFDNSaveConfirm(void)
{
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SECSET_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    MTPNP_AD_Set_CHV_Pass_CB(MTPNP_PFAL_SECSETSetFdlEntryReq);

    SetLeftSoftkeyFunction(MTPNP_PFAL_PreSaveFdlBdlEntryReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MTPNP_PFAL_GoToFDLList, KEY_EVENT_UP);
}

void MTPNP_PFAL_SECSETSetFdlEntryReq(void)
{
    MSG_PHB_SET_ENRTY_REQ_STRUCT *pMsgNewEntry = NULL;
    MYQUEUE Message;

    /* U8 pbName_ASCII[MAX_PB_NAME_LENGTH]; */
    U8 pbNumber_ASCII[MAX_PB_NUMBER_LENGTH + 1];

    gFDLBDLContext.is_fdn = 1;
    EntrySECSETFDNBDNSaving();
    pMsgNewEntry = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));

    memset(pMsgNewEntry->list.alpha_id.name, 0, MAX_PB_NAME_LENGTH + 1);
    memset(pMsgNewEntry->list.tel.number, 0, MAX_PB_NAME_LENGTH + 1);

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

    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETSetFdlEntryRsp, PRT_PHB_SET_ENTRY_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgNewEntry;
    Message.oslPeerBuffPtr = NULL;

    //DeleteUptoScrID(SCR_CARD2_SECSET_FDN_LIST);
    MTPNP_PFAL_ExitSECSETFDNListReload();

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_SECSETSetFdlEntryRsp(void *info)
{
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;

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
    //DeleteUptoScrID(SCR_CARD2_SECSET_FDN_LIST);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_FDN_OPTION);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_FDN_DETAILS);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_SAVING);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);
}

void MTPNP_PFAL_HighlightEditFDL(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetKeyHandler(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(MTPNP_PFAL_EntrySECSETFDNDetails, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLName,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].alpha_id.name);
    mmi_ucs2cpy(
        (S8*) gFDLBDLContext.FDLBDLNumber,
        (S8*) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].tel.number);
    gFDLBDLContext.FDNBDNEdit = TRUE;
}

void MTPNP_PFAL_HighlightDeleteFDL(void)
{
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(MTPNP_PFAL_EntrySECSETFDNDelConfirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_EntrySECSETFDNDelConfirm(void)
{
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SECSET_DELETE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    MTPNP_AD_Set_CHV_Pass_CB(MTPNP_PFAL_SECSETDelFdlReq);

    SetLeftSoftkeyFunction(MTPNP_AD_Get_SIM_Status_For_CHV2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(MTPNP_PFAL_GoToFDLList, KEY_EVENT_UP);
}

void MTPNP_PFAL_SECSETDelFdlReq(void)
{
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *pMsgDelEntry = NULL;
    MYQUEUE Message;

    gFDLBDLContext.is_fdn = 1;
    EntrySECSETFDNBDNDeleting();
    pMsgDelEntry = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    pMsgDelEntry->no_data = 1;
    pMsgDelEntry->del_all = MMI_FALSE;  /* No */
    pMsgDelEntry->index = gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].index;
    pMsgDelEntry->type = MMI_PHB_FDN;   /* PHB_PHONEBOOK */

    SetSlaveProtocolEventHandler(MTPNP_PFAL_SECSETDelFdlRsp, PRT_PHB_DEL_ENTRY_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) pMsgDelEntry;
    Message.oslPeerBuffPtr = NULL;

    //DeleteUptoScrID(SCR_CARD2_SECSET_FDN_LIST);
    MTPNP_PFAL_ExitSECSETFDNListReload();

    OslMsgSendExtQueue(&Message);
}

void MTPNP_PFAL_SECSETDelFdlRsp(void *info)
{
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;

    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;

    if (localPtr->result.flag == 0 /* OK */ )
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, ST_NOTIFYDURATION, ERROR_TONE);
    }
    //DeleteUptoScrID(SCR_CARD2_SECSET_FDN_LIST);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_FDN_OPTION);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_FDN_DETAILS);
    DeleteScreenIfPresent(SCR_ID_SECSET_FDNBDN_DELETING);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_NEW_PIN2);
    DeleteScreenIfPresent(SCR_CARD2_SECSET_PUK2_CONFIRM_PIN2);
}

void MTPNP_PFAL_FdlMakeCall(void)
{
    if (gFDLBDLContext.HighlightedFDN != 255)
    {
        g_phb_cntx.dial_from_list = MMI_PHB_FDN;
        MakeCall((PS8) gFDLBDLContext.FDLBDLEntries[gFDLBDLContext.HighlightedFDN].tel.number);
    }
}

void MTPNP_PFAL_GetActiveIndex(S32 index)
{
    gFDLBDLContext.HighlightedFDN = (U8) index;
}

void MTPNP_PFAL_GetEntryTitle(S32 index)
{
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

void MTPNP_PFAL_GoToFDLList(void)
{
    GoBackToHistory(SCR_CARD2_SECSET_FDN_LIST);
}

void MTPNP_PFAL_PreSaveFdlBdlEntryReq(void)
{
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
        MTPNP_AD_Get_SIM_Status_For_CHV2();
    }
}

void MTPNP_PFAL_EntryFdlList(void)
{
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
    {
        gFDLBDLContext.FDNBDNCount = 0;
        EntrySECSETFDNBDNWaiting();
        MTPNP_PFAL_SECSETGetFdlEntriesReq();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_FDL_NOT_READY), IMG_PROCESSING_PHONEBOOK, 1, ST_NOTIFYDURATION, 0);
    }
}

#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */ 

