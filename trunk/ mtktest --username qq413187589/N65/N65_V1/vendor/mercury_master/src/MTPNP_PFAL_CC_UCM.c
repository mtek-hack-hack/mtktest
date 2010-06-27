/***********************************************
File name : MTPNP_PFAL_CC.c
Contents : MTPNP Call control platform 
History : Create by : Jing xiaoyong, April 9, 2007
************************************************/
#include "MMI_features.h"

//#ifdef __MERCURY_MASTER__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "stdC.h"
#include "MMI_Features.h"
#include "L4Dr.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "DebugInitDef.h"
#include "MMI_trc.h"
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "HistoryGprot.h"
#include "SubLCDHistoryGprot.h"
#include "GlobalDefs.h"
#include "GlobalStruct.h"
#include "GlobalScrEnum.h"
#include "WrapperGprot.h"
#include "KeyBrd.h"
#include "TimerEvents.h"
#include "wgui.h"
#include "Wgui_categories_popup.h"
#include "wgui_categories_CM.h"
#include "wgui_categories_util.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_multimedia.h"
#include "CSP.h"
#include "gdi_include.h"        /* for GDI's color define */
#include "ProfileGprots.h"
#include "BootUp.h"
#include "PowerOnChargerProt.h"
#include "MessagesExDcl.h"
#include "SmsPsHandler.h"
#include "MessagesResourceData.h"
#include "SMSApi.h"

#include "AlarmFrameworkProt.h"
#include "SATDefs.h"
#include "SATGProts.h"
#include "SimDetectionGexdcl.h"
#include "gpioInc.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "CallSetUp.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "AudioInc.h"
#include "SettingDefs.h"

#ifdef __CTM_SUPPORT__
#include "TextPhoneDef.h"
#include "TextPhoneProt.h"
#endif /* __CTM_SUPPORT__ */
#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#include "CallManagementIdDef.h"
#include "CallManagementStruct.h"
#include "CallStructureManagementProt.h"
#include "CmErrorTypes.h"
#include "CmErrorHandlersProt.h"
#include "HistoryHelperProt.h"
#include "RedialHelperGProt.h"
#include "CommonStubsProt.h"
#include "PsCallHelperDef.h"
#include "mmiapi_struct.h"
#include "PsCallHelperGprot.h"
#include "CallManagementGprot.h"
#include "OutgoingCallHelperProt.h"
#include "OutgoingCallManagementProt.h"
#include "MessagesResourceData.h"
#include "IncomingCallManagementProt.h"
#include "PhonebookDef.h"       /* For enum IMG_PHB_DEFAULT */
#include "CommonScreens.h"      /* for popup window timer. */

#ifdef CS_NOTIFYDURATION
#undef CS_NOTIFYDURATION
#endif 
#include "CallsGProts.h"

#ifdef __MMI_BT_HP_SUPPORT__
#include "BTMMIHPGprots.h"
#endif

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#include "app_datetime.h"
#include "SettingGenum.h"
#include "ProfilesDefs.h"
#include "CallSetUpEnum.h"
#include "CommonStubsProt.h"

#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "wndrv_api.h"
#include "supc_abm_msgs.h"
#endif /* __WIFI_SUPPORT__ */
#include "mmi2abm_struct.h"

/* MTPNP Header file */
#include "MTPNP_AD_master_header.h"
#include "CommonStubsProt.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_custom_hw.h"
/* MTPNP Header file */
#ifdef __MMI_UCM__
#include "UCMProt.h"
#include "UCMResDef.h"
#include "MTPNP_PFAL_CC_UCM.h"
#include "MTPNP_PFAL_dualprof.h"

mmi_gsm_ucm_act_type_enum mtpnp_ucm_act_enum;
mmi_gsm_ucm_act_opcode_enum mtpnp_ucm_act_opcode_enum;

/*maintain the slave conf group information begin*/
static CM_CALL_HANDLE mtpnp_ucm_conf_group_id;

static CM_CALL_HANDLE mtpnp_auto_dtmf_call_id;
static MTPNP_UINT8 gMtpnpDTMFConfirmBuf[MAX_DTMFBUF_DIGITS];

static MTPNP_UINT8 gMtpnpCashSign[8];
MTPNP_UINT32 gMtpnpSumACMValue = 0;
static MTPNP_UINT32 gMtpnpAocBuffer[10];

#ifdef __SUPPORT_PITCHSHIFT__     //LIJUNZHAO_PITCHSHIFT_ERR_080425
extern void Stop_CallingPitchShift(void);
extern  U8 gPtichShiftOpen;
#endif


void MTPNP_PFAL_SetConfGroupID(CM_CALL_HANDLE groupid)
{
    mtpnp_ucm_conf_group_id = groupid;
}

CM_CALL_HANDLE MTPNP_PFAL_GetConfGroupID(void)
{
    return mtpnp_ucm_conf_group_id;
}

/*maintain the slave conf group information end*/

/*maintain the slave group information begin*/
static MTPNP_UINT8 mtpnp_call_group[MTPNP_AD_MAX_CALLS];

void MTPNP_PFAL_SetCallGroup(MTPNP_UINT8 call_group, MTPNP_UINT16 index)
{
    mtpnp_call_group[index] = call_group;
}

MTPNP_UINT8 MTPNP_PFAL_GetCallGroup(MTPNP_UINT16 index)
{
    return mtpnp_call_group[index];
}

void MTPNP_PFAL_InitCallGroup(void)
{
    MTPNP_UINT16 index;
    for (index = 0; index < MTPNP_AD_MAX_CALLS; index++)
    {
        MTPNP_PFAL_SetCallGroup(MMI_INVALID_CALL_GROUP, index);
    }
}

MTPNP_UINT8 MTPNP_PFAL_GetUnUsedGroupID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U16 count = 0;
    U16 group_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_id = 8; group_id < (MTPNP_AD_MAX_CALLS + 8); group_id++)
    {
        for (index = 0; index < MTPNP_AD_MAX_CALLS; index++)
        {
            if (MTPNP_PFAL_GetCallGroup(index) != group_id)
            {
                count++;
            }
        }
        if (count == MTPNP_AD_MAX_CALLS)
        {
            return group_id;
        }
        count = 0;
    }
    return 0;
}

/*maintain the slave group information end*/

void MTPNP_PFAL_SetUCMOperationState(mmi_gsm_ucm_act_type_enum op_type, mmi_gsm_ucm_act_opcode_enum op_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_SetUCMOperationState:%d", op_code);
    mtpnp_ucm_act_enum = op_type;
    mtpnp_ucm_act_opcode_enum = op_code;
}

void MTPNP_PFAL_InitOperationState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_InitOperationState");
    mtpnp_ucm_act_enum = MMI_GSM_UCM_NO_ACTION;
    mtpnp_ucm_act_opcode_enum = MMI_GSM_UCM_IDLE;
}

mmi_gsm_ucm_act_opcode_enum MTPNP_PFAL_GetUCMOPCodeState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_GetUCMOPCodeState:%d",mtpnp_ucm_act_opcode_enum);
    return mtpnp_ucm_act_opcode_enum;
}

void MTPNP_PFAL_ucm_act_req(MTPNP_UINT8 op_code, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_ucm_act_req op_code = %d", op_code);
    switch (op_code)
    {
    case MMI_UCM_DIAL:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_DIAL);
        MTPNP_PFAL_dial(act_struct);
        break;

    case MMI_UCM_HOLD_AND_DIAL:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_HOLD_AND_DIAL);
        MTPNP_PFAL_hold_and_dial(act_struct);
        break;

    case MMI_UCM_ACCEPT:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_ACCEPT);
        MTPNP_PFAL_accept(act_struct);
        break;

    case MMI_UCM_HOLD_AND_ACCEPT:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_HOLD_AND_ACCEPT);
        MTPNP_PFAL_hold_and_accept(act_struct);
        break;

    case MMI_UCM_HOLD:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_HOLD);
        MTPNP_PFAL_hold(act_struct);
        break;

    case MMI_UCM_RETRIEVE:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_RETRIEVE);
        MTPNP_PFAL_retrieve(act_struct);
        break;

    case MMI_UCM_SWAP:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_SWAP);
        MTPNP_PFAL_swap(act_struct);
        break;

    case MMI_UCM_CONFERENCE:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_CONFERENCE);
        MTPNP_PFAL_conference(act_struct);
        break;

    case MMI_UCM_SPLIT:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_SPLIT);
        MTPNP_PFAL_split(act_struct);
        break;

    case MMI_UCM_DEFLECT:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_DEFLECT);
        MTPNP_PFAL_deflect(act_struct);
        break;

    case MMI_UCM_END_SINGLE:

#ifdef __SUPPORT_PITCHSHIFT__ //LIJUNZHAO_PITCHSHIFT_ERR_080425
	if(gPtichShiftOpen)  
	{
		Stop_CallingPitchShift();
		gPtichShiftOpen = 0;
	}
#endif

        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_SINGLE);
        MTPNP_PFAL_end_single(act_struct);
        break;

    case MMI_UCM_END_CONFERENCE:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_CONFERENCE);
        MTPNP_PFAL_end_conference(act_struct);
        break;

    case MMI_UCM_END_ALL:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_ALL);
        MTPNP_PFAL_end_all(act_struct);
        break;

    case MMI_UCM_FORCE_RELEASE:
        //MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_FORCE_RELEASE);
        MTPNP_PFAL_force_release(act_struct);
        break;

    case MMI_UCM_AUTO_REJECT:
        //MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_AUTO_REJECT);
        MTPNP_PFAL_auto_reject(act_struct);
        break;

    case MMI_UCM_EXPLICT_CALL_TRANSFER:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_EXPLICT_CALL_TRANSFER);
        MTPNP_PFAL_explicit_call_transfer(act_struct);
        break;

    case MMI_UCM_END_ACTIVE_AND_RETRIEVE:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE);
        MTPNP_PFAL_end_active_and_retrieve(act_struct);
        break;

    case MMI_UCM_END_ACTIVE_AND_ACCEPT:
        MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT);
        MTPNP_PFAL_end_active_and_accept(act_struct);
        break;

    case MMI_UCM_START_DTMF:
        //MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_SENDING_DTMF);
        MTPNP_PFAL_start_dtmf(act_struct);
        break;

    case MMI_UCM_STOP_DTMF:
        //MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_IDLE);
        MTPNP_PFAL_stop_dtmf(act_struct);
        break;

    default:
        break;
    }
}

void MTPNP_PFAL_get_call_list(mmi_ucm_sync_call_list_struct * callList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 count;
    E_MTPNP_AD_CALL_STATE callState;
    MTPNP_CHAR * log_name = MTPNP_NULL;
    MTPNP_CHAR * log_num = MTPNP_NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_get_call_list");
    MTPNP_OSAL_memset(callList, 0, sizeof(mmi_ucm_sync_call_list_struct));

    //callList->call_type = MTPNP_PFAL_GetCallTypeSim2();
    callList->call_type = (MMI_UCM_VOICE_CALL_TYPE_SIM2 | MMI_UCM_DATA_CALL_TYPE_SIM2 | MMI_UCM_CSD_CALL_TYPE_SIM2);

    for (count = 0; count < MTPNP_AD_MAX_CALLS; count++)
    {
        callState = MTPNP_AD_CC_GetCallCurState(count);
        switch (callState)
        {
        case MTPNP_CM_OUTGOING_STATE:

            /*UCM has already atuo rejected the call, so don't let her know. Auto reject MO call*/
            if(MTPNP_AD_GetAutoRejectCallID() == MTPNP_AD_CC_GetCallHandle(count))
            {
                PRINT_INFORMATION("salve call management: Ignore auto rejected call (MO)");
                break;
            }

            /*REMOTE INFO */
            log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count);
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.num_uri,
                            (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

            /*display name*/
        #ifdef __IP_NUMBER__
            if (log_name != MTPNP_NULL && GetTempUseIPNumber() == FALSE)
        #else /* __IP_NUMBER__ */
            if (log_name != MTPNP_NULL)
        #endif /* __IP_NUMBER__ */
            {
                mmi_ucs2cpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_name);
            }
            else
            {
                log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num+8, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
                else
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
            }

            /*call log name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
            }

            callList->call_info[callList->total_num].remote_info.active_icon = 0;
            if (!IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
            {
                if (MTPNP_AD_CC_GetTotalActiveCallCount() + MTPNP_AD_CC_GetTotalHeldCallCount() > 1)
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_MULTI_LINE1;
                }
                else
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_LINE1;
                }
            }
            /*UID info */
            callList->call_info[callList->total_num].uid_info.call_id = MTPNP_AD_CC_GetCallHandle(count);
            callList->call_info[callList->total_num].uid_info.group_id = MTPNP_PFAL_GetCallGroup(count);
            //callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2();
            callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(count));
            

            /*STATE info */
            callList->call_info[callList->total_num].call_state = MMI_UCM_OUTGOING_STATE;

            /*print info */
            PRINT_INFORMATION("[%d]:group_id:%d, call_id:%d, call_state:%d, call_type:%d",
                               callList->total_num,
                               callList->call_info[callList->total_num].uid_info.group_id,
                               callList->call_info[callList->total_num].uid_info.call_id,
                               callList->call_info[callList->total_num].call_state,
                               callList->call_info[callList->total_num].uid_info.call_type);

            callList->total_num++;
            break;

        case MTPNP_CM_INCOMING_STATE:

            /*UCM has already atuo rejected the call, so don't let her know. Auto reject MT call*/
            if(MTPNP_AD_GetAutoRejectCallID() == MTPNP_AD_CC_GetCallHandle(count))
            {
                PRINT_INFORMATION("salve call management: Ignore auto rejected call (MT)");
                break;
            }

            /*REMOTE INFO */
            log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count);
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.num_uri,
                            (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

            /*display name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2cpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_name);
            }
            else
            {
                log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num+8, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
                else
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
            }

            /*call log name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
            }
            else if (mmi_ucs2cmp((PS8) MTPNP_AD_CC_GetCurrCallNum(count), GetString(STR_UNKNOWN_CALLER)) == 0)
            {
                mmi_ucs2cpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.log_name, GetString(STR_UNKNOWN_CALLER));
            }

            /*UID info */
            callList->call_info[callList->total_num].uid_info.call_id = MTPNP_AD_CC_GetCallHandle(count);
            callList->call_info[callList->total_num].uid_info.group_id = MTPNP_PFAL_GetCallGroup(count);
            //callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(); 
            callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(count));

            /*STATE info */
            callList->call_info[callList->total_num].call_state = MMI_UCM_INCOMING_STATE;

            /*print info */
            PRINT_INFORMATION("[%d]:group_id:%d, call_id:%d, call_state:%d, call_type:%d",
                               callList->total_num,
                               callList->call_info[callList->total_num].uid_info.group_id,
                               callList->call_info[callList->total_num].uid_info.call_id,
                               callList->call_info[callList->total_num].call_state,
                               callList->call_info[callList->total_num].uid_info.call_type);

            callList->total_num++;
            break;

        case MTPNP_CM_ACTIVE_STATE:
            /*REMOTE INFO */
            log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count);
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.num_uri,
                            (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

            /*display name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2cpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_name);
            }
            else
            {
                log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num+8, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
                else
                {
                     mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
            }
               /*call log name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
            }

            callList->call_info[callList->total_num].remote_info.active_icon = 0;
            if (!IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
            {
                if (MTPNP_AD_CC_GetTotalActiveCallCount() + MTPNP_AD_CC_GetTotalHeldCallCount() > 1)
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_MULTI_LINE1;
                }
                else
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_LINE1;
                }
            }
            /*UID info */
            callList->call_info[callList->total_num].uid_info.call_id = MTPNP_AD_CC_GetCallHandle(count);
            callList->call_info[callList->total_num].uid_info.group_id = MTPNP_PFAL_GetCallGroup(count);
            //callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(); 
            callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(count));

            /*STATE info */
            callList->call_info[callList->total_num].call_state = MMI_UCM_ACTIVE_STATE;

            /*print info */
            PRINT_INFORMATION("[%d]:group_id:%d, call_id:%d, call_state:%d, call_type:%d",
                               callList->total_num,
                               callList->call_info[callList->total_num].uid_info.group_id,
                               callList->call_info[callList->total_num].uid_info.call_id,
                               callList->call_info[callList->total_num].call_state,
                               callList->call_info[callList->total_num].uid_info.call_type);

            callList->total_num++;
            break;

        case MTPNP_CM_HOLD_STATE:
            /*REMOTE INFO */
            log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count); 
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.num_uri,
                            (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

            /*display name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2cpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_name);
            }
            else
            {
                log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                {
                    mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num+8, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
                else
                {
                     mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.disp_name, log_num, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                }
            }
               /*call log name*/
            if (log_name != MTPNP_NULL)
            {
                mmi_ucs2ncpy((MTPNP_CHAR *) callList->call_info[callList->total_num].remote_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
            }

            callList->call_info[callList->total_num].remote_info.active_icon = 0;
            if (!IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
            {
                if (MTPNP_AD_CC_GetTotalActiveCallCount() + MTPNP_AD_CC_GetTotalHeldCallCount() > 1)
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_MULTI_LINE1;
                }
                else
                {
                    callList->call_info[callList->total_num].remote_info.active_icon = IMG_CM_ICON_LINE1;
                }
            }
            /*UID info */
            callList->call_info[callList->total_num].uid_info.call_id = MTPNP_AD_CC_GetCallHandle(count);
            callList->call_info[callList->total_num].uid_info.group_id = MTPNP_PFAL_GetCallGroup(count);
            //callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2();
            callList->call_info[callList->total_num].uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(count));

            /*STATE info */
            callList->call_info[callList->total_num].call_state = MMI_UCM_HOLD_STATE;

            /*print info */
            PRINT_INFORMATION("[%d]:group_id:%d, call_id:%d, call_state:%d, call_type:%d",
                               callList->total_num,
                               callList->call_info[callList->total_num].uid_info.group_id,
                               callList->call_info[callList->total_num].uid_info.call_id,
                               callList->call_info[callList->total_num].call_state,
                               callList->call_info[callList->total_num].uid_info.call_type);

            callList->total_num++;
            break;

        default:
            if (MTPNP_AD_CC_GetCallHandle(count) != 0)
            {
                //ASSERT HERE
            }
            break;
        }
    }
    return;
}

void MTPNP_PFAL_CC_UCMInitRegister(void)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_OUTGOINGSRC_IND, MTPNP_PFAL_CC_UCMShowOutgoingSrc);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_CLOSE_OUTGOINGSRC_IND, MTPNP_PFAL_CC_UCMCloseOutgoingSrc);
    //MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_INCOMINGSRC_IND, MTPNP_PFAL_CC_UCMShowIncomingSrc);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_CLOSE_INCOMINGSRC_IND, MTPNP_PFAL_CC_UCMCloseIncomingSrc);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_MAKECALLERR_IND, MTPNP_PFAL_CC_ShowNotAllow);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_ACTIVESRC_IND, MTPNP_PFAL_CC_UCMShowActiveSrc);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_CLOSE_ACTIVESRC_IND, MTPNP_PFAL_CC_UCMCloseActiveSrc);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_USSDSRC_IND, MTPNP_PFAL_CC_UCMShowScrUSSDReq);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_USSDNOTSUPPORTSRC_IND, MTPNP_NULL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_AOCSRC_IND, MTPNP_NULL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_LOG_MISSED_IND, MTPNP_NULL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_LOG_DIALED_IND, MTPNP_NULL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_LOG_RECED_IND, MTPNP_NULL);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_SWAPSUCCESS_IND, MTPNP_PFAL_CC_UCMShowSwapSucess);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CONFSUCCESS_IND, MTPNP_PFAL_CC_UCMShowConfSucess);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_SPLITSUCCESS_IND, MTPNP_PFAL_CC_UCMShowSplitSucess);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_ERRMESSAGE_IND, MTPNP_PFAL_CC_UCMCBShowCallErrorMessage);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CFU_STATUS, MTPNP_PFAL_CC_DisplayCFUInd);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CALLFORWARD_RSP, MTPNP_PFAL_CC_UCMShowCallForwardRsp);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CALLWAITING_RSP, MTPNP_PFAL_CC_UCMShowCallWaitingRsp);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CALLBARRING_RSP, MTPNP_PFAL_CC_UCMCallBarringRsp);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_CALLCHANGEPWD_RSP, MTPNP_PFAL_CC_UCMCallChangePwdRsp);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_OUTGOINGCALL_ALTER_IND, MTPNP_PFAL_CC_UCMOutgoingCallAlterRsp);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_SHOW_SPEECH_STATUS, MTPNP_PFAL_CC_UCMSpeechInd);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_CALLINCOMING_IND,MTPNP_PFAL_CC_UCMCallIncomingInd);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_CC_MO_FIALED_IND, MTPNP_PFAL_CC_MO_FAILED);
}

void MTPNP_PFAL_CC_UCMShowActiveSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 Slave_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowActiveSrc");
    Slave_index = MTPNP_AD_CC_GetCurIndex();
    MTPNP_PFAL_CC_SetQuickEndTime();
    if (MTPNP_AD_CC_GetCallPrevState(Slave_index) == MTPNP_CM_INCOMING_STATE)
    {
        if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_ACCEPT)
        {
            MTPNP_PFAL_accept_rsp(MTPNP_TRUE, MTPNP_NULL);
        }
        else if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_ACCEPT)
        {
            MTPNP_PFAL_hold_and_accept_rsp(MTPNP_TRUE, MTPNP_NULL);
        }
    }
    else if (MTPNP_AD_CC_GetCallPrevState(Slave_index) == MTPNP_CM_OUTGOING_STATE)
    {
        MTPNP_PFAL_connect_ind();
    }
}

void MTPNP_PFAL_CC_UCMCloseActiveSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 Slave_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SUPPORT_PITCHSHIFT__ //LIJUNZHAO_PITCHSHIFT_ERR_080425
	if(gPtichShiftOpen)  
	{
		Stop_CallingPitchShift();
		gPtichShiftOpen = 0;
	}
#endif

    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCloseActiveSrc");
    Slave_index = MTPNP_AD_CC_GetCurIndex();
    MTPNP_PFAL_release_ind(0);
}
#if defined(__PAOMA_LIGHT_SUPPORT__)
extern kal_uint8 gCallPaomaLightStatus; /*wangyulin, 20071212*/
extern void StartPAOMALight(void);
extern void StopPAOMALight(void);
#endif
#if defined (__MUSIC_LIGHT_SUPPORT__) //kuanghanli D12 20080415
extern kal_uint8 gCallPaomaLightStatus; /*wangyulin, 20071212*/
extern void music_light_start(void);
extern void music_light_stop(void);
#endif //end

void MTPNP_PFAL_CC_UCMShowIncomingSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 sIncoming;
    MTPNP_UINT8 *number = MTPNP_NULL;
    PHB_CM_INTERFACE Slave_PhoneNumberStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__PAOMA_LIGHT_SUPPORT__)
		{
		kal_prompt_trace(MOD_SMS," gCallPaomaLightStatus77 = %d", gCallPaomaLightStatus);
			if(1 == gCallPaomaLightStatus) 
				StartPAOMALight(); /*wangyulin, 20071212*/
		}
#endif
#if defined (__MUSIC_LIGHT_SUPPORT__) //kuanghanli D12 20080415
	if(1 == gCallPaomaLightStatus)
		music_light_start();
#endif //end

    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowIncomingSrc");
    if (MTPNP_AD_GetIncomingCallIndex(&sIncoming) == MTPNP_FALSE)
    {
        kal_prompt_trace(MOD_CC, "MTPNP_PFAL_CC_UCMShowIncomingSrc Error sIncoming=%x ", sIncoming);
        return;
    }
//    MTPNP_PFAL_SendSampleADCMsg(MTPNP_AD_AUX_CALL_SETUP);
    ResetRedialAttempts();
    MTPNP_AD_CC_SetCurIndex(sIncoming);
    //SetAnswerMode(GetAnsweringMode());

    number = MTPNP_AD_CC_GetCurrCallNum(sIncoming);

    Slave_PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(number, MTPNP_FALSE, SIM2);
    MTPNP_PFAL_SetCMPhoneBookStruct(&Slave_PhoneNumberStruct);

    MTPNP_PFAL_CC_PHBSetdataforCall(sIncoming);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    /*set slave mo call groupid */
    MTPNP_PFAL_SetCallGroup(MTPNP_PFAL_GetUnUsedGroupID(), sIncoming);
    /*set slave mo call groupid */
    MTPNP_PFAL_ring_ind();
}

void MTPNP_PFAL_CC_UCMCallIncomingInd(void *msg)
{
    MTPNP_PFAL_CC_UCMShowIncomingSrc(MTPNP_NULL);
}

void MTPNP_PFAL_CC_MO_FAILED(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 *info = MTPNP_NULL;
    MTPNP_BOOL voice_mo_call = MTPNP_FALSE;
#ifdef __IP_NUMBER__
    MTPNP_BOOL ip_dial = MTPNP_FALSE;
#endif /* __IP_NUMBER__ */
    PHB_CM_INTERFACE *Slave_PhoneNumberStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_MO_FAILED");
    info = (MTPNP_UINT16 *) msg;

    if(mmi_ucm_app_outgoing_call(MMI_UCM_VOICE_CALL_TYPE_SIM2) > 0)
    {
        voice_mo_call = MTPNP_TRUE;
    }

#ifdef __IP_NUMBER__
    ip_dial = GetTempUseIPNumber();
#endif /* __IP_NUMBER__ */

    MTPNP_PFAL_CC_UCMShowCallErrorMessage(*info,MMI_GSM_UCM_END_SINGLE);
    if (CheakCard2AutoRedial(*info) && voice_mo_call == MTPNP_TRUE)
    {
        Slave_PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();
        if (Slave_PhoneNumberStruct->dialInList != MMI_PHB_NONE)
        {
            PRINT_INFORMATION("Auto redial from phb, dialInList:%d", Slave_PhoneNumberStruct->dialInList);
            SetCard2RedialPHBIndex(Slave_PhoneNumberStruct->dialInList);
        }
        else if(mmi_ucs2strlen((PS8)Slave_PhoneNumberStruct->number) == 0)
        {
            PRINT_INFORMATION("Auto redial from CallLog");
            CHISTSetDialFromCallLogFlag(GetCard2RedialFromCallLog());
        }
        
        MTPNP_PFAL_auto_redial_ind();
    #ifdef __IP_NUMBER__
        SetTempUseIPNumber(ip_dial);
    #endif /* __IP_NUMBER__ */
    }
    else
    {
        ResetRedialAttempts();
    }
}

void MTPNP_PFAL_CC_UCMCloseIncomingSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCloseIncomingSrc");
    index = MTPNP_AD_CC_GetCurIndex();
    MTPNP_PFAL_release_ind(0);
//    MTPNP_PFAL_end_single_rsp(MTPNP_TRUE, MTPNP_NULL);
//    MTPNP_PFAL_SendSampleADCMsg(MTPNP_AD_AUX_CALL_DISCONNECT);
}

void MTPNP_PFAL_CC_UCMShowOutgoingSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MTPNP_UINT16 index;         /*set slave mo call groupid */
    MTPNP_UINT8 *number = MTPNP_NULL;
    PHB_CM_INTERFACE Slave_PhoneNumberStruct;
    LOG_CALL hilite_item;
    MTPNP_UINT8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowOutgoingSrc");
    index = MTPNP_AD_CC_GetCurIndex();

    number = MTPNP_AD_CC_GetCurrCallNum(index);

    if(GetCard2RedialPHBIndex() != MMI_PHB_NONE)
    {
        mmi_phb_call_set_dial_from_list(GetCard2RedialPHBIndex());
    }

    Slave_PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(number, MTPNP_TRUE, SIM2);

    MTPNP_PFAL_SetCMPhoneBookStruct(&Slave_PhoneNumberStruct);

    MTPNP_PFAL_CC_PHBSetdataforCall(index);

    MTPNP_PFAL_SetCallGroup(MTPNP_AD_INVALID_CALL_HANDLE, index);

    if (CHISTGetDialFromCallLogFlag() != 0)
    {
        CHISTGetCallLogName(&hilite_item);
        length = (MTPNP_UINT8) (MTPNP_PFAL_Unicode_String_Length((S8 *) (hilite_item.pbName)));

        /*Dial from call log, but no match in PHB*/
        if (MTPNP_AD_CC_GetCurrCallName(index) != MTPNP_NULL &&
            mmi_ucs2cmp((PS8) hilite_item.pbName, (PS8) MTPNP_AD_CC_GetCurrCallName(index)) != 0)
        {
                MTPNP_OSAL_memset(&Slave_PhoneNumberStruct, 0, sizeof(PHB_CM_INTERFACE));
                Slave_PhoneNumberStruct.pictureId = IMG_PHB_DEFAULT;
                MTPNP_PFAL_SetCMPhoneBookStruct(&Slave_PhoneNumberStruct);
        }
        
        MTPNP_AD_CC_SetCallCurrNameLen(index, length);
        MTPNP_AD_CC_SetCallCurrName(index, (MTPNP_UINT8*)hilite_item.pbName);
    }

    /*set slave mo call groupid */
    if (MTPNP_AD_CC_GetSlaveCallType() == MTPNP_AD_CC_CALLTYPE_VOICE)
    {

        if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_DIAL)
        {
            MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_VOICE, MTPNP_NULL);
        }
        else if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_DIAL)
        {
            MTPNP_PFAL_hold_and_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_VOICE, MTPNP_NULL);
        }
    }
    else if (MTPNP_AD_CC_GetSlaveCallType() == MTPNP_AD_CC_CALLTYPE_SS)
        MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_SS, MTPNP_NULL);
    else
    {                           /*some error occur */
    }
}

void MTPNP_PFAL_CC_UCMCloseOutgoingSrc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT16 index;
    MTPNP_UINT16 *info = MTPNP_NULL;
    MTPNP_BOOL voice_mo_call = MTPNP_FALSE;
#ifdef __IP_NUMBER__
    MTPNP_BOOL ip_dial = MTPNP_FALSE;
#endif /* __IP_NUMBER__ */
    PHB_CM_INTERFACE *Slave_PhoneNumberStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCloseOutgoingSrc");
    info = (MTPNP_UINT16 *) msg;
    index = MTPNP_AD_CC_GetCurIndex();

    if(mmi_ucm_app_outgoing_call(MMI_UCM_VOICE_CALL_TYPE_SIM2) > 0)
    {
        voice_mo_call = MTPNP_TRUE;
    }

#ifdef __IP_NUMBER__
    ip_dial = GetTempUseIPNumber();
#endif /* __IP_NUMBER__ */

    if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_DIAL || MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_DIAL)
    {
        MTPNP_PFAL_CC_UCMShowCallErrorMessage(*info, MMI_GSM_UCM_IDLE);
        return;
    }
    else
    {
        MTPNP_PFAL_release_ind(*info);
    }
    
    if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_IDLE && CheakCard2AutoRedial(*info) && voice_mo_call == MTPNP_TRUE)
    {

        Slave_PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();
        if (GetCard2RedialFromCallLog() == 0)
        {
            PRINT_INFORMATION("Auto redial from phb, dialInList:%d", Slave_PhoneNumberStruct->dialInList);
            SetCard2RedialPHBIndex(Slave_PhoneNumberStruct->dialInList);
        }
        else
        {
            PRINT_INFORMATION("Auto redial from CallLog");
            CHISTSetDialFromCallLogFlag(GetCard2RedialFromCallLog());
        }
        
        MTPNP_PFAL_auto_redial_ind();
    #ifdef __IP_NUMBER__
        SetTempUseIPNumber(ip_dial);
    #endif /* __IP_NUMBER__ */
    }
    else
    {
        ResetRedialAttempts();
    }
}

void MTPNP_PFAL_CC_UCMShowSwapSucess(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowSwapSucess");
    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0 && MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
        MTPNP_PFAL_swap_rsp(MTPNP_TRUE, MTPNP_NULL);
    else if (MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
        MTPNP_PFAL_hold_rsp(MTPNP_TRUE, MTPNP_NULL);
    else if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0)        
        MTPNP_PFAL_retrieve_rsp(MTPNP_TRUE, MTPNP_NULL);
}

void MTPNP_PFAL_CC_UCMShowConfSucess(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowConfSucess");
    MTPNP_PFAL_conference_rsp(MTPNP_TRUE, MTPNP_NULL);
}

void MTPNP_PFAL_CC_UCMShowSplitSucess(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowSplitSucess");
    MTPNP_PFAL_split_rsp(MTPNP_TRUE, MTPNP_NULL);
}

void MTPNP_PFAL_CC_UCMCBShowCallErrorMessage(void *msg)
{
    MTPNP_UINT16 *cause = (MTPNP_UINT16 *) msg;
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCBShowCallErrorMessage");
    MTPNP_PFAL_CC_UCMShowCallErrorMessage(*cause, MMI_GSM_UCM_IDLE);
}

void MTPNP_PFAL_CC_UCMShowScrUSSDReq(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowScrUSSDReq");
    if (MTPNP_AD_CC_GetSlaveCallType() == MTPNP_AD_CC_CALLTYPE_SS)
    {
        MTPNP_PFAL_CC_Show_ScrUSSDReq();
        MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_SS, MTPNP_NULL);
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowScrUSSDReq:ERROR");
    }
}

void MTPNP_PFAL_CC_UCMShowCallForwardRsp(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowCallForwardRsp");
    MTPNP_PFAL_CC_ShowCallForwardRsp(msg);
}

void MTPNP_PFAL_CC_UCMShowCallWaitingRsp(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowCallWaitingRsp");
    MTPNP_PFAL_CC_ShowCallWaitingRsp(msg);
}

void MTPNP_PFAL_CC_UCMCallBarringRsp(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCallBarringRsp");
    MTPNP_PFAL_CC_CallBarringRsp(msg);
}

void MTPNP_PFAL_CC_UCMCallChangePwdRsp(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMCallChangePwdRsp");
    MTPNP_PFAL_CC_CallChangePwdRsp(msg);
}
void MTPNP_PFAL_CC_UCMOutgoingCallAlterRsp(void *msg)
{
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMOutgoingCallAlterRsp");
    MTPNP_PFAL_alert_ind(MTPNP_AD_CC_GetCallHandle(MTPNP_AD_CC_GetCurIndex()), ((MMI_CC_INTERNAL_ALERT_IND*) msg)->alert);
}

void MTPNP_PFAL_CC_UCMSpeechInd(void *msg)
{
    ST_MTPNP_SPEECH_IND_INFO *MsgSpeechInd;
    BOOL speechOn;
    MsgSpeechInd = (ST_MTPNP_SPEECH_IND_INFO *) msg;
    MsgSpeechInd->rat=MDI_AUDIO_SPEECH_APP_ID_SIM2;
    speechOn=(MsgSpeechInd->on_off==MTPNP_TRUE?TRUE:FALSE);
        PRINT_INFORMATION("MTPNP_PFAL_CC_UCMSpeechInd speechOn=%d",speechOn);

    if (TRUE==speechOn)
    {
        if (MsgSpeechInd->rat == MDI_AUDIO_SPEECH_APP_ID_SIM2 && mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_SIM2)
        {
            MTPNP_PFAL_speech_ind(speechOn, MDI_AUDIO_SPEECH_APP_ID_SIM2);
        }
    }
    else
    {
        if ((MsgSpeechInd->rat == MDI_AUDIO_SPEECH_APP_ID_SIM2 && 
        	mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_SIM2))
        {
            MTPNP_PFAL_speech_ind(speechOn, MDI_AUDIO_SPEECH_APP_ID_SIM2);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_speech_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void MTPNP_PFAL_speech_ind(BOOL speech, U8 rat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_ucm_speech_ind_struct speech_ind;
    mmi_ucm_session_ind_struct session_ind;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&speech_ind, 0, sizeof(mmi_ucm_speech_ind_struct));
    memset(&session_ind, 0, sizeof(mmi_ucm_session_ind_struct));

    /*call type*/
    speech_ind.call_type = MMI_UCM_VOICE_CALL_TYPE_SIM2;

    /*session type*/
    speech_ind.session_type = rat;
    session_ind.session_type = rat;
    
    /*switch*/
    speech_ind.local_switch = speech;
    speech_ind.remote_switch = speech;
    session_ind.session_switch = speech;

    /*call list*/
    speech_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
	MTPNP_PFAL_get_call_list(speech_ind.call_list);
    session_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
	MTPNP_PFAL_get_call_list(session_ind.call_list);

    if(speech == TRUE)
    {  
        /*start session*/
        mmi_ucm_dispatch_ind(MMI_UCM_SESSION_IND, (void *)&session_ind);
        OslMfree(session_ind.call_list);
        
        /*turn on codec*/
        mmi_ucm_dispatch_ind(MMI_UCM_SPEECH_IND, (void *)&speech_ind);
        OslMfree(speech_ind.call_list);

        /*start auto sound recorder*/
    #ifdef __MMI_SOUND_RECORDER__
        mmi_sndrec_auto_record_switch_sim2(MDI_AUDIO_SPEECH_APP_ID_GSM, MMI_TRUE);
    #endif
    }
    else
    {
        /*stop auto sound recorder*/
    #ifdef __MMI_SOUND_RECORDER__
        mmi_sndrec_auto_record_switch_sim2(MDI_AUDIO_SPEECH_APP_ID_GSM, MMI_FALSE);
    #endif
    	
        /*turn off codec*/
        mmi_ucm_dispatch_ind(MMI_UCM_SPEECH_IND, (void *)&speech_ind);
        OslMfree(speech_ind.call_list);
        
        /*stop session*/
        mmi_ucm_dispatch_ind(MMI_UCM_SESSION_IND, (void *)&session_ind);
        OslMfree(session_ind.call_list);
    }
    
}

void MTPNP_PFAL_CC_UCMShowCallErrorMessage(MTPNP_UINT16 cause, MTPNP_UINT8 opcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code, img_id = IMG_ERROR_NOTIFY;
    U16 tone_id = ERROR_TONE_IN_CALL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_CC_UCMShowCallErrorMessage cause = %d", cause);
    switch (cause)
    {
        case ERR_UNASSIGNED_NUM:
            tone_id = NUM_UNOBTAIN_TONE;
        case ERR_INVALID_NUMBER_FORMAT:
            error_code = ERROR_UNRECOGNIZED_NUMBER;
            break;

        case ERR_SWITCH_EQUIPMENT_CONGESTION:
            tone_id = CONGESTION_TONE;
        case ERR_CALL_REJECTED:
            tone_id= AUTH_FAIL_TONE;
        case ERR_NO_ROUTE_TO_DESTINATION:
        case ERR_DEST_OUT_OF_ORDER:
        case ERR_FACILITY_REJECT:
        case ERR_TEMPORARY_FAILURE:
        case ERR_SER_UNAVAILABLE:
        case ERR_BEARER_SER_UNIMPL:
        case ERR_INVALID_TI_VALUE:
        case ERR_USER_NOT_IN_CUG:
        case ERR_INCOMPATIBLE_DEST:
        case ERR_SEMANTIC_ERR:
        case ERR_INTER_WRK_UNSPECIFIED:
        case ERR_CSMCC_ILLEGAL_CALL_ID:
        case ERR_CSMCC_CALL_ALLOC_FAIL:
        case ERR_CSMCC_BC_FILL_FAIL:
        case ERR_CSMCC_ILLEGAL_BC:
        case ERR_CSMCC_MODIFY_ACTUAL_MODE:
        case ERR_CSMCC_DATA_ACT_FAIL:
        case ERR_MAC_FAILURE:
        case ERR_SYNC_FAILURE:
        case ERR_CONGESTION:
        case ERR_ILLEGAL_MS:
        case ERR_ILLEGAL_ME:
        case ERR_CM_MM_CM_ENQUEUE_FAIL:
        case ERR_CM_MM_NOT_UPDATED:
        case ERR_CM_MM_STATE_NOT_ALLOWED_CM:
        case ERR_IMSI_UNKNOWN_IN_HLR:
        case ERR_CM_MM_IMSI_DETACH:
        case ERR_CM_MM_AUTH_FAILURE:
            error_code = ERROR_FAIL;
            break;

        case ERR_CHANNEL_UN_ACCP:
        case ERR_NETWORK_OUT_OF_ORDER:
        case ERR_QOS_UNAVAIL:
        case ERR_INVALID_TRANSIT_NW_SEL:
        case ERR_CSMCC_NO_RESPONSE_FROM_NW:
        case ERR_NETWORK_FAILURE:
        case ERR_CM_MM_RR_CONN_RELEASE:
        case ERR_CM_SS_SYSTEMFAILURE:
            error_code = ERROR_NETWORK_FAIL;
            break;

        case ERR_OPR_DTR_BARRING:
        case ERR_CALL_BARRED:
        case ERR_IC_BAR_CUG:
        case ERR_BEARER_CAP_NOT_AVAIL:
        case ERR_CM_MM_ACCESS_BARRED:
            error_code = INCOMING_DEFAULT_ERROR;
            break;

        case ERR_USER_BUSY:
            error_code = ERROR_BUSY_NETWORK;
            tone_id = TONE_BUSY_CALL_GSM;
            break;

        case ERR_NO_CIRCUIT_CHANNEL_AVAIL:
        case ERR_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case ERR_RESOURCE_UNAVAIL_UNSPECIFIED:
            error_code = ERROR_BUSY_NETWORK;
            break;
              
        case ERR_NO_USER_RESPONDING:
            error_code = ERROR_NOT_RESPONDING;
            break;

        case ERR_NO_ANSWER_ON_ALERT:
            error_code = ERROR_NO_ANSWER;
            break;

        case ERR_ACM_EXCEEDED:
            error_code = ERROR_ACM_EXCEEDED;
            break;

        case ERR_REQ_FACILITY_UNAVAIL:
        case ERR_IE_NOT_IMPLEMENTED:
        case ERR_CONDITIONAL_MM_IE_ERROR:
        case ERR_CM_MM_ASSIGNMENT_REJECT:
            error_code = ERROR_UNAVAILABLE;
            break;

        case ERR_CSMCC_ILLEGAL_DTMF_TONE:
        case ERR_CSMCC_CALL_ACCEPT_NOT_ALLOW:
        case ERR_MS_ID_NOT_DERIVED_BY_NW:
        case ERR_IMPLICIT_DETACH:
        case ERR_MSG_NOT_COMPAT_WITH_PROTO_STATE:
        case ERR_PROTO_ERROR_UNSPECIFIED:
            error_code = ERROR_UNEXPECTED_ERROR;
            break;

        case ERR_IMEI_NOT_ACCEPTED:
            error_code = ERROR_IMEI_ERROR;
            break;

        case ERR_GPRS_NOT_ALLOWED:
        case ERR_GPRS_NON_GPRS_NOT_ALLOWED:
            error_code = ERROR_GPRS_NOT_ALLOWED;
            break;

        case ERR_CM_MT_DATA_CALL:
            error_code = ERROR_MT_DATA_CALL;
            break;

        case ERR_REQ_FAC_NOT_SUBS:
        case ERR_PLMN_NOT_ALLOWED:
        case ERR_LOCATION_AREA_NOT_ALLOWED:
        case ERR_ROAMING_AREA_NOT_ALLOWED:
        case ERR_GPRS_NOT_ALLOWED_IN_PLMN:
        case ERR_NO_SUITABLE_CELLS_IN_LA:
        case ERR_MSC_TEMP_NOT_REACHABLE:
        case ERR_CM_MM_ABORT_BY_NW:
        /* case ERR_CM_MM_STATE_NOT_ALLOWED_CM: */
        case ERR_BEARER_CAP_NOT_AUTHORISED:
        case ERR_SERV_OPTION_TEMP_OUT_OF_ORDER:
            error_code = ERROR_NETWORK_NOT_ALLOWED;
            break;

        case ERR_CSMCC_CMD_NOT_ALLOW:
        case ERR_SERV_OPTION_NOT_SUPPORTED:
        case ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED:
        case ERR_CALL_CANNOT_BE_IDENTIFIED:
            error_code = ERROR_COMMAND_NOT_SUPPORTED;
            break;

        case ERR_NO_PDP_CONTEXT_ACTIVATED:
        case ERR_SEMANTICALLY_INCORRECT_MSG:
        case ERR_INVALID_MM_MAND_INFO:
            error_code = ERROR_DATA_ERROR;
            break;

        case ERR_MSG_TYPE_NON_EXISTENT:
        case ERR_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE:
            error_code = ERROR_MESSAGE_TYPE_ERROR;
            break;

        case ERR_ACCESS_CLASS_BARRED:
        case ERR_CM_MM_RANDOM_ACCES_FAILURE:
            error_code = ERROR_ACCESS_FAIL;
            break;

        case ERR_CM_MM_CONN_TIMEOUT:
            error_code = ERROR_TIMER_EXPIRED;
            break;

        /* user may get confused if the error cause is call ended
        case ERR_NORMAL_CALL_CLR:
        case ERR_NORMAL_UNSPECIFIED:
            error_code = STR_CALL_ENDED;
            img_id = IMG_CM_STATE_ENDED;
            break;*/
            
        case ERR_L4C_USSD_ABORT:
            error_code = ERROR_USSD_ABORTED;
            break;
        case ERR_CM_MM_RR_NO_SERVICE:
        case ERR_CM_MM_NO_SERVICE:
        case ERR_RESERVED:
        case ERR_NUMBER_CHANGED:
        case ERR_PRE_EMPTION:
        case ERR_NON_SEL_USER_CLEAR:
        case ERR_RES_STATUS_ENQ:
        case ERR_ACCESS_INFO_DISCARDED:
        case ERR_RESTR_DIGITAL_INFO:
        case ERR_SER_OPT_UNIMPL:
        case ERR_INVALID_MANDATORY_INF:
        case ERR_MSG_TYPE_UNIMPL:
        case ERR_MSG_TYPE_NOT_COMPATIBLE:
        case ERR_IE_NON_EX:
        case ERR_COND_IE_ERR:
        case ERR_INCOMP_MESG_WITH_STATE:
        case ERR_RECOVERY_ON_TIMER_EXPIRY:
        case ERR_PROTOCOL_ERR_UNSPECIFIED:
        case ERR_CSMCC_CALL_RE_EST:
        case ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN:
        case ERR_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX:
        case ERR_CM_MM_CAUSE_NONE:
        case ERR_L4C_GEN_CAUSE:
            error_code = INCOMING_DEFAULT_ERROR;
            break;

        case ERR_L4C_FDN_FAIL:
            error_code = ERROR_FDN_FAIL;
            break;

        case NO_ACTIVE_CALL:
            error_code = ERROR_INVALID_COMMAND;
            break;

        case ERR_CM_UNKNOWN:
            error_code = INCOMING_UNKNOWN_ERROR;
            break;

        default:
            error_code = INCOMING_DEFAULT_ERROR;
            break;
    }                           /* End of Switch */
	
    if(opcode == MMI_GSM_UCM_IDLE)
    {
       opcode = MTPNP_PFAL_GetUCMOPCodeState();
    }
    switch (opcode)
    {
    case MMI_GSM_UCM_DIAL:
        MTPNP_PFAL_dial_rsp(FALSE, NULL, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_HOLD_AND_DIAL:
        MTPNP_PFAL_hold_and_dial_rsp(FALSE, CC_OPERATION, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_ACCEPT:
        MTPNP_PFAL_accept_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_HOLD_AND_ACCEPT:
        MTPNP_PFAL_hold_and_accept_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_HOLD:
        MTPNP_PFAL_hold_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_RETRIEVE:
        MTPNP_PFAL_retrieve_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_SWAP:
        MTPNP_PFAL_swap_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_CONFERENCE:
        MTPNP_PFAL_conference_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_SPLIT:
        MTPNP_PFAL_split_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_DEFLECT:
        MTPNP_PFAL_deflect_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_END_SINGLE:
        MTPNP_PFAL_end_single_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_END_CONFERENCE:
        MTPNP_PFAL_end_conference_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_END_ALL:
        MTPNP_PFAL_end_all_rsp(FALSE, (U8 *) get_string(error_code));
        break;
		
    case MMI_GSM_UCM_FORCE_RELEASE:
        MTPNP_PFAL_force_release_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_AUTO_REJECT:
        MTPNP_PFAL_dial_rsp(FALSE, NULL, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_EXPLICT_CALL_TRANSFER:
        MTPNP_PFAL_explicit_call_transfer_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_END_ACTIVE_AND_RETRIEVE:
        MTPNP_PFAL_end_active_and_retrieve_rsp(FALSE, (U8 *) get_string(error_code));
        break;

    case MMI_GSM_UCM_END_ACTIVE_AND_ACCEPT:
        MTPNP_PFAL_end_active_and_accept_rsp(FALSE, (U8 *) get_string(error_code));
        break;

        /*GSM only operation */
    case MMI_GSM_UCM_END_ALL_HELD_CALL:
    case MMI_GSM_UCM_END_ALL_ACTIVE_CALL:
    case MMI_GSM_UCM_ACTIVATE_CCBS:
    case MMI_GSM_UCM_AUTO_QUICK_END:
        break;

    default:
        break;
    }

    SetErrorToneFlag(tone_id);

}

void MTPNP_PFAL_dial(void *act_struct)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_CHAR dial_number[MAX_NUMBER];
#ifdef __SAT__
    MTPNP_INT8 ansii_number[MTPNP_AD_MAX_CC_ADDR_LEN];
#endif /* __SAT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_dial");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_dial_req_struct*) act_struct)->source_id); 
    
    if ((strlen((void *)((mmi_ucm_dial_req_struct*) act_struct)->num_uri) * ENCODING_LENGTH) >= MAX_NUMBER)
    {
        PRINT_INFORMATION("MTPNP_PFAL_dial: number is too long");
        MTPNP_PFAL_CC_UCMShowCallErrorMessage(ERR_INVALID_NUMBER_FORMAT, MMI_GSM_UCM_IDLE);
        return;
    }
    
    MTPNP_OSAL_memset(dial_number, 0, MAX_NUMBER);
    mmi_asc_to_ucs2((MTPNP_CHAR *) dial_number, (MTPNP_CHAR *) ((mmi_ucm_dial_req_struct *) act_struct)->num_uri);

#ifdef __SAT__
    if(((mmi_ucm_dial_req_struct*) act_struct)->module_id == MMI_UCM_FROM_SAT)
    {
        MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *)ansii_number, (MTPNP_CHAR *)dial_number);
        MTPNP_PFAL_MakeSATCall((MTPNP_CHAR *)ansii_number);
    }
    else
#endif /* __SAT__ */
    if(((mmi_ucm_dial_req_struct*) act_struct)->module_id == MMI_UCM_FROM_ABM)
    {
        MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *)ansii_number, (MTPNP_CHAR *)dial_number);
        MTPNP_PFAL_MakeCSDCall((MTPNP_CHAR *)ansii_number);
    }
    else
    {
        MakeCall((MTPNP_CHAR *) dial_number);
    }
}

void MTPNP_PFAL_dial_rsp(MTPNP_BOOL result, MTPNP_UINT8 opcode, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_dial_act_rsp_struct dial_rsp;
    MTPNP_UINT16 count;
    E_MTPNP_AD_CALL_STATE callState;
    MTPNP_CHAR * log_name = MTPNP_NULL;
    MTPNP_CHAR * log_num = MTPNP_NULL;
    PHB_CM_INTERFACE *PhoneNumberStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_dial_rsp resust = %d", result);
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);
    MTPNP_OSAL_memset(&dial_rsp, 0, sizeof(mmi_ucm_dial_act_rsp_struct));
    dial_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(dial_rsp.call_list);
    if (result == FALSE)
    {
        dial_rsp.result_info.result = FALSE;
        dial_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &dial_rsp);
    #ifdef __IP_NUMBER__
        SetTempUseIPNumber(FALSE);
    #endif 
    }
    else
    {
        if (opcode == MTPNP_AD_CC_CALLTYPE_VOICE)
        {
            dial_rsp.result_info.result = TRUE;

            /*remote info */
            for (count = 0; count < MTPNP_AD_MAX_CALLS; count++)
            {
                callState = MTPNP_AD_CC_GetCallCurState(count);
                if (callState == MTPNP_CM_OUTGOING_STATE)
                {
                    log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count);
                    mmi_ucs2_n_to_asc((MTPNP_CHAR *) dial_rsp.remote_info.num_uri,
                                    (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

                    /*display name*/
                #ifdef __IP_NUMBER__
                    if (log_name != MTPNP_NULL && GetTempUseIPNumber() == FALSE)
                #else /* __IP_NUMBER__ */
                    if (log_name != MTPNP_NULL)
                #endif /* __IP_NUMBER__ */
                    {
                        mmi_ucs2cpy((MTPNP_CHAR *) dial_rsp.remote_info.disp_name, log_name);
                    }
                    else
                    {
                        log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                        if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                            (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                        {
                            mmi_ucs2ncpy((MTPNP_CHAR *) dial_rsp.remote_info.disp_name, log_num+8, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                        }
                        else
                        {
                            mmi_ucs2ncpy((MTPNP_CHAR *) dial_rsp.remote_info.disp_name, log_num, MMI_UCM_MAX_DISP_NAME_LEN - 1);
                        }
                    }

                    /*call log name*/
                    if (log_name != MTPNP_NULL)
                    {
                        mmi_ucs2ncpy((MTPNP_CHAR *) dial_rsp.remote_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
                    }
                    
                }
            }
	 #ifdef __IP_NUMBER__
            if (GetTempUseIPNumber() == TRUE && GetCurrCard2IPNumberUCS2() != NULL)
            {
                mmi_ucs2ncpy((S8 *)dial_rsp.alert_info.ip_num, (S8 *)GetCurrCard2IPNumberUCS2(), MMI_UCM_MAX_IP_NUMBER_LEN);
            }
        #endif /* __IP_NUMBER__ */ 

            /*alert info*/
            PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();    
            if (PhoneNumberStruct->pictureId == IMG_PHB_DEFAULT)
            {
                dial_rsp.alert_info.image_info.image_id = IMG_CM_STATE_OUTGOING;    
            }
            else
            {
                dial_rsp.alert_info.image_info.image_id = PhoneNumberStruct->pictureId;
            }
            dial_rsp.alert_info.image_info.record_index = PhoneNumberStruct->record_index;

            mmi_ucm_dispatch_rsp(MMI_UCM_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &dial_rsp);
        }
        else if (opcode == MTPNP_AD_CC_CALLTYPE_SS)
        {
            dial_rsp.result_info.result = FALSE;
            dial_rsp.result_info.error_msg = NULL;
            mmi_ucm_dispatch_rsp(MMI_UCM_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &dial_rsp);

        #ifdef __IP_NUMBER__
            SetTempUseIPNumber(FALSE);
        #endif 
        }
    }
    OslMfree(dial_rsp.call_list);
}

void MTPNP_PFAL_hold_and_dial(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_CHAR dial_number[MAX_NUMBER];
#ifdef __SAT__
    MTPNP_INT8 ansii_number[MTPNP_AD_MAX_CC_ADDR_LEN];
#endif /* __SAT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold_and_dial");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_hold_n_dial_req_struct*) act_struct)->source_id); 
    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0)
    {
        MTPNP_OSAL_memset(dial_number, 0, MAX_NUMBER);
        mmi_asc_to_ucs2((MTPNP_CHAR *) dial_number,
                             (MTPNP_CHAR *) ((mmi_ucm_hold_n_dial_req_struct *) act_struct)->num_uri);
    #ifdef __SAT__
        if(((mmi_ucm_dial_req_struct*) act_struct)->module_id == MMI_UCM_FROM_SAT)
        {
            MTPNP_PFAL_Unicode_To_Ansii_String((MTPNP_CHAR *)ansii_number, (MTPNP_CHAR *)dial_number);
            MTPNP_PFAL_MakeSATCall((MTPNP_CHAR *)ansii_number);
        }
        else
    #endif /* __SAT__ */
        MakeCall((MTPNP_CHAR *) dial_number);
        return;
    }
    /*ASSERT HERE */
}

void MTPNP_PFAL_hold_and_dial_rsp(MTPNP_BOOL result, MTPNP_UINT8 opcode, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_dial_act_rsp_struct hold_and_dial_rsp;
    PHB_CM_INTERFACE *PhoneNumberStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold_and_dial_rsp result = %d", result);
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&hold_and_dial_rsp, 0, sizeof(mmi_ucm_dial_act_rsp_struct));

    hold_and_dial_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(hold_and_dial_rsp.call_list);

    if (result == FALSE)
    {
        PRINT_INFORMATION("GSM call application: mmi_gsm_hold_and_dial_rsp: FALSE");

        hold_and_dial_rsp.result_info.result = FALSE;
        hold_and_dial_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD_AND_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_and_dial_rsp);

    #ifdef __IP_NUMBER__
        SetTempUseIPNumber(FALSE);
    #endif 
    }
    else if (opcode == MTPNP_AD_CC_CALLTYPE_VOICE)
    {
        PRINT_INFORMATION("GSM call application: mmi_gsm_hold_and_dial_rsp: TRUE");

        hold_and_dial_rsp.result_info.result = TRUE;

        /*alert info*/
        PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();    
        if (PhoneNumberStruct->pictureId == IMG_PHB_DEFAULT)
        {
            hold_and_dial_rsp.alert_info.image_info.image_id = IMG_CM_STATE_OUTGOING;    
        }
        else
        {
            hold_and_dial_rsp.alert_info.image_info.image_id = PhoneNumberStruct->pictureId;
        }
        hold_and_dial_rsp.alert_info.image_info.record_index = PhoneNumberStruct->record_index;

    #ifdef __IP_NUMBER__
        if (GetTempUseIPNumber() == TRUE && GetCurrCard2IPNumberUCS2() != NULL)
        {
            mmi_ucs2ncpy((S8 *)hold_and_dial_rsp.alert_info.ip_num, (S8 *)GetCurrCard2IPNumberUCS2(), MMI_UCM_MAX_IP_NUMBER_LEN);
        }
    #endif /* __IP_NUMBER__ */ 
   
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD_AND_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_and_dial_rsp);
    }
    else if (opcode == MTPNP_AD_CC_CALLTYPE_SS)
    {
        PRINT_INFORMATION("GSM call application: mmi_gsm_hold_and_dial_rsp: TRUE");

        hold_and_dial_rsp.result_info.result = FALSE;
        hold_and_dial_rsp.result_info.error_msg = NULL;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD_AND_DIAL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_and_dial_rsp);

    #ifdef __IP_NUMBER__
        SetTempUseIPNumber(FALSE);
    #endif 
    }
    OslMfree(hold_and_dial_rsp.call_list);
}

void MTPNP_PFAL_accept(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT8 callID;
    MTPNP_UINT16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_accept");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_single_call_struct*) act_struct)->source_id); 
    MTPNP_PFAL_CC_StopAutoAnsTimer();
    if (MTPNP_AD_GetIncomingCallIndex(&index) != MTPNP_TRUE)
        return;
    if (MTPNP_AD_CC_GetTotalActiveCallCount() + MTPNP_AD_CC_GetTotalHeldCallCount() == 0)
    {
        callID = MTPNP_AD_CC_GetCallHandle(index);
    }
    else
    {
        callID = MTPNP_AD_CC_HANDLE_2ND_INCOMING;       //accept wait call
    }
    if (MTPNP_AD_CC_Accept_Call(callID))
    {
        PRINT_INFORMATION("MTPNP_PFAL_accept SUCCESS");
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_accept FAILED");
    }
}

void MTPNP_PFAL_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct accept_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_accept_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&accept_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    accept_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(accept_rsp.call_list);

    if (result == FALSE)
    {
        accept_rsp.result_info.result = FALSE;
        accept_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &accept_rsp);
    }
    else
    {
        accept_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &accept_rsp);
    }

    OslMfree(accept_rsp.call_list);
}

void MTPNP_PFAL_accept_req_ind(MTPNP_UINT8 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_answer_req_ind_struct accept_req_ind;
    U16 count;
    MTPNP_UINT16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MTPNP_OSAL_memset(&accept_req_ind, 0, sizeof(mmi_ucm_answer_req_ind_struct));
    accept_req_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(accept_req_ind.call_list);

    /* UID info*/
    MTPNP_AD_CC_GetCallIndexbyHandle((unsigned char) handle, &index);
    accept_req_ind.uid_info.call_id = MTPNP_AD_CC_GetCallHandle(index);
    accept_req_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(index);
    accept_req_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(index));
	
    mmi_ucm_dispatch_ind(MMI_UCM_ANSWER_REQ_IND, (void *)&accept_req_ind);
    OslMfree(accept_req_ind.call_list);
}

void MTPNP_PFAL_hold_and_accept(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT8 callID;
    MTPNP_UINT16 index;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold_and_accept");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_multiple_call_struct*) act_struct)->source_id); 
    MTPNP_PFAL_CC_StopAutoAnsTimer();
    if (MTPNP_AD_GetIncomingCallIndex(&index) != MTPNP_TRUE)
        return;
    if (MTPNP_AD_CC_GetTotalActiveCallCount() + MTPNP_AD_CC_GetTotalHeldCallCount() == 0)
    {
        callID = MTPNP_AD_CC_GetCallHandle(index);
    }
    else
    {
        callID = MTPNP_AD_CC_HANDLE_2ND_INCOMING;       //accept wait call
    }
    if (MTPNP_AD_CC_Accept_Call(callID))
    {
        PRINT_INFORMATION("MTPNP_PFAL_hold_and_accept SUCCESS");
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_hold_and_accept FAILED");
    }
}

void MTPNP_PFAL_hold_and_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct hold_and_accept_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold_and_accept_rsp result = %d", result);
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&hold_and_accept_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    hold_and_accept_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(hold_and_accept_rsp.call_list);

    if (result == FALSE)
    {
        hold_and_accept_rsp.result_info.result = FALSE;
        hold_and_accept_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD_AND_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_and_accept_rsp);
    }
    else
    {
        hold_and_accept_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD_AND_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_and_accept_rsp);
    }
    OslMfree(hold_and_accept_rsp.call_list);
}

void MTPNP_PFAL_hold(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_single_call_struct*) act_struct)->source_id); 

    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0)
    {
        if (MTPNP_AD_CC_Hold_Call())
        {
            kal_prompt_trace(MOD_CC, "MTPNP_PFAL_hold suc!");
        }
        else
        {
            kal_prompt_trace(MOD_CC, "MTPNP_PFAL_hold failed!");
        }
        return;
    }
    /*ASSERT HERE */
}

void MTPNP_PFAL_hold_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct hold_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_hold_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&hold_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    hold_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(hold_rsp.call_list);

    if (result == FALSE)
    {
        hold_rsp.result_info.result = FALSE;
        hold_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_rsp);
    }
    else
    {
        hold_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_HOLD, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &hold_rsp);
    }
    OslMfree(hold_rsp.call_list);
}

void MTPNP_PFAL_retrieve(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_retrieve");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_single_call_struct*) act_struct)->source_id); 
    if (MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
    {
        if (MTPNP_AD_CC_Retrieve_Call())
        {
            kal_prompt_trace(MOD_CC, "MTPNP_PFAL_retrieve suc!");
        }
        else
        {
            kal_prompt_trace(MOD_CC, "MTPNP_PFAL_retrieve failed!");
        }
        return;
    }
    /*ASSERT HERE */
}

void MTPNP_PFAL_retrieve_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct retrieve_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_retrieve_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&retrieve_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    retrieve_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(retrieve_rsp.call_list);

    if (result == FALSE)
    {
        PRINT_INFORMATION("MTPNP_PFAL_retrieve_rsp :result FALSE");
        retrieve_rsp.result_info.result = FALSE;
        retrieve_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_RETRIEVE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &retrieve_rsp);
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_retrieve_rsp :result TRUE");
        retrieve_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_RETRIEVE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &retrieve_rsp);
    }
    OslMfree(retrieve_rsp.call_list);
}

void MTPNP_PFAL_swap(void *act_struct)
{
    /*----------------------------------------------------------------*/
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_swap");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_multiple_call_struct*) act_struct)->source_id); 
    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0 && MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
    {
        if (MTPNP_AD_CC_Hold_Call())
        {
            PRINT_INFORMATION("MTPNP_PFAL_swap:TRUE");
        }
        else
        {
            PRINT_INFORMATION("MTPNP_PFAL_swap:FALSE");
        }
        return;
    }
    /*ASSERT HERE */
}

void MTPNP_PFAL_swap_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct swap_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_swap_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&swap_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    swap_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(swap_rsp.call_list);

    if (result == FALSE)
    {
        swap_rsp.result_info.result = FALSE;
        swap_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_SWAP, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &swap_rsp);
    }
    else
    {
        swap_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_SWAP, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &swap_rsp);
    }
    OslMfree(swap_rsp.call_list);
}

void MTPNP_PFAL_conference(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_conference");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_conf_req_struct*) act_struct)->source_id); 

    MTPNP_PFAL_SetConfGroupID((CM_CALL_HANDLE) ((mmi_ucm_conf_req_struct *) act_struct)->active_group);
    MTPNP_AD_CC_CallConference();
    return;
}

void MTPNP_PFAL_conference_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct conference_rsp;
    MTPNP_UINT16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_conference_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&conference_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    if (result == FALSE)
    {
        PRINT_INFORMATION("MTPNP_PFAL_conference_rsp RSP: FALSE");

        conference_rsp.result_info.result = FALSE;
        conference_rsp.result_info.error_msg = error_msg;
        conference_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
        MTPNP_PFAL_get_call_list(conference_rsp.call_list);
        mmi_ucm_dispatch_rsp(MMI_UCM_CONFERENCE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &conference_rsp);
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_conference_rsp RSP: TRUE");
        /*assign new group id to all calls held->active */
        for (count = 0; count < MTPNP_AD_MAX_CALLS; count++)
        {
            if ((MTPNP_AD_CC_GetCallCurState(count) == MTPNP_CM_ACTIVE_STATE))
            {
                MTPNP_PFAL_SetCallGroup(MTPNP_PFAL_GetConfGroupID(), count);
            }
        }
        conference_rsp.result_info.result = TRUE;

        conference_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
        
        MTPNP_PFAL_get_call_list(conference_rsp.call_list);

        mmi_ucm_dispatch_rsp(MMI_UCM_CONFERENCE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &conference_rsp);
    }
    MTPNP_PFAL_SetConfGroupID(0);
    OslMfree(conference_rsp.call_list);
}

void MTPNP_PFAL_split(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_split");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_split_req_struct*) act_struct)->source_id); 
    MTPNP_AD_CC_SplitCall((MTPNP_UINT8) ((mmi_ucm_split_req_struct *) act_struct)->split_call);
}

void MTPNP_PFAL_split_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct split_rsp;
    MTPNP_UINT16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_split_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);
    MTPNP_OSAL_memset(&split_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));
    split_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(split_rsp.call_list);

    if (result == FALSE)
    {
        PRINT_INFORMATION(" MTPNP_PFAL_split_rsp: FALSE");
        split_rsp.result_info.result = FALSE;
        split_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_SPLIT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &split_rsp);
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_split_rsp: TRUE");

        /*reset group id */
        for (count = 0; count < MTPNP_AD_MAX_CALLS; count++)
        {
            if ((MTPNP_AD_CC_GetCallCurState(count) == MTPNP_CM_ACTIVE_STATE))
            {
                MTPNP_PFAL_SetCallGroup(MTPNP_PFAL_GetUnUsedGroupID(), count);
            }
        }
        split_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_SPLIT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &split_rsp);
    }
    OslMfree(split_rsp.call_list);
}

void MTPNP_PFAL_deflect(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_deflect");

    if (MTPNP_AD_CC_Deflect( (PU8)((mmi_ucm_cd_or_ct_req_struct*) act_struct)->num_uri))
    {
        PRINT_INFORMATION("MTPNP_PFAL_deflect:TRUE");
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_deflect:FALSE");
    }
    return;
}

void MTPNP_PFAL_deflect_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct deflect_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_deflect_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&deflect_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    deflect_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(deflect_rsp.call_list);

    if (result == FALSE)
    {
        deflect_rsp.result_info.result = FALSE;
        deflect_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_DEFLECT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &deflect_rsp);
    }
    else
    {
        deflect_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_DEFLECT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &deflect_rsp);
    }
    OslMfree(deflect_rsp.call_list);

}

void MTPNP_PFAL_end_single(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT8 callId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_single");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_single_call_struct*) act_struct)->source_id); 
    callId = (MTPNP_UINT8) ((mmi_ucm_single_call_struct *) act_struct)->action_uid.call_id;

    MTPNP_AD_CC_EndSingleCall(callId);
}

void MTPNP_PFAL_end_single_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct end_single_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_single_rsp result = %d", result);
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    if(MTPNP_AD_GetAutoRejectCallID() != 0)
    {
        MTPNP_AD_SetAutoRejectCallID(0);
    }

    MTPNP_OSAL_memset(&end_single_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    end_single_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(end_single_rsp.call_list);

    if (result == FALSE)
    {
        end_single_rsp.result_info.result = FALSE;
        end_single_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_SINGLE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_single_rsp);
    }
    else
    {
        ResetRedialAttempts();
        end_single_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_SINGLE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_single_rsp);
    }
    OslMfree(end_single_rsp.call_list);
}

void MTPNP_PFAL_end_conference(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_conference");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_end_conf_req_struct*) act_struct)->source_id); 
    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 1)
    {
        MTPNP_AD_CC_EndAllActiveCall();
        return;
    }
    else if (MTPNP_AD_CC_GetTotalHeldCallCount() > 1)
    {
        MTPNP_AD_CC_EndAllHoldCall();
        return;
    }
    /*ASSERT HERE */
}

void MTPNP_PFAL_end_conference_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct end_conference_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_conference_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&end_conference_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    end_conference_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(end_conference_rsp.call_list);

    if (result == FALSE)
    {
        end_conference_rsp.result_info.result = FALSE;
        end_conference_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_CONFERENCE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_conference_rsp);
    }
    else
    {
        end_conference_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_CONFERENCE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_conference_rsp);
    }
    OslMfree(end_conference_rsp.call_list);
}
void MTPNP_PFAL_end_all(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_all");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_end_all_req_struct*) act_struct)->source_id); 
    if (MTPNP_AD_CC_GetTotalCallCount() > 0)
    {
        MTPNP_AD_CC_HangUpAllCall();
        return;
    }
}

void MTPNP_PFAL_end_all_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct end_all_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_all_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    if(MTPNP_AD_GetAutoRejectCallID() != 0)
    {
        MTPNP_AD_SetAutoRejectCallID(0);
    }

    MTPNP_OSAL_memset(&end_all_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    end_all_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(end_all_rsp.call_list);

    if (result == FALSE)
    {
        end_all_rsp.result_info.result = FALSE;
        end_all_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ALL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_all_rsp);
    }
    else
    {
        ResetRedialAttempts();
        end_all_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ALL, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &end_all_rsp);
    }
    OslMfree(end_all_rsp.call_list);
}

void MTPNP_PFAL_force_release(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_RELCOMP_REQ *relcompReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslMsgId = PRT_RELCOMP_EVENT;
    relcompReq = (MMI_RELCOMP_REQ*) OslConstructDataPtr(sizeof(MMI_RELCOMP_REQ));
    Message.oslDataPtr = (oslParaType*) relcompReq;
    relcompReq->call_id = (U8) ((mmi_ucm_single_call_struct*) act_struct)->action_uid.call_id;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}

void MTPNP_PFAL_force_release_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*ucm not dispatch MMI_UCM_FORCE_RELEASE message temporary
       finish this routine later */
}

void MTPNP_PFAL_auto_reject(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT8 call_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_auto_reject");
    MTPNP_AD_SetAutoRejectCallID((MTPNP_UINT8) ((mmi_ucm_single_call_struct *) act_struct)->action_uid.call_id);
    call_state = MTPNP_AD_CC_GetCurStatebyHandle((MTPNP_UINT8) ((mmi_ucm_single_call_struct *) act_struct)->action_uid.call_id);

    if (call_state == MTPNP_CM_INCOMING_STATE)
    {
        MTPNP_PFAL_end_single(act_struct);
    }
    else if (call_state == MTPNP_CM_OUTGOING_STATE)
    {
        MTPNP_PFAL_CancleMOBeforeDialInd();
    }
    else
    {
        ASSERT(0);
    }
    
}

void MTPNP_PFAL_auto_reject_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*No action rsp for force release */

}

void MTPNP_PFAL_explicit_call_transfer(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_explicit_call_transfer");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_multiple_call_struct*) act_struct)->source_id); 

    if (MTPNP_AD_CC_ECT())
    {
        PRINT_INFORMATION("MTPNP_PFAL_explicit_call_transfer:TRUE");
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_explicit_call_transfer:FALSE");
    }
    return;
}

void MTPNP_PFAL_explicit_call_transfer_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct ect_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_ect_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&ect_rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    ect_rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(ect_rsp.call_list);

    if (result == FALSE)
    {
        ect_rsp.result_info.result = FALSE;
        ect_rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_EXPLICT_CALL_TRANSFER, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &ect_rsp);
    }
    else
    {
        ect_rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_EXPLICT_CALL_TRANSFER, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &ect_rsp);
    }
    OslMfree(ect_rsp.call_list);
}

void MTPNP_PFAL_end_active_and_retrieve(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_end_active_and_retrieve");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_multiple_call_struct*) act_struct)->source_id);

    if (MTPNP_AD_CC_End_Active_and_Retrieve_Held())
    {
        kal_prompt_trace(MOD_CC, "MTPNP_PFAL_end_active_and_retrieve suc!");
    }
    else
    {
        kal_prompt_trace(MOD_CC, "MTPNP_PFAL_end_active_and_retrieve failed!");
    }
    return;
}

void MTPNP_PFAL_end_active_and_retrieve_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_active_and_retrieve_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(rsp.call_list);

    if (result == FALSE)
    {
        rsp.result_info.result = FALSE;
        rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ACTIVE_AND_RETRIEVE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &rsp);
    }
    else
    {
        rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ACTIVE_AND_RETRIEVE, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &rsp);
    }
    OslMfree(rsp.call_list);
}

void MTPNP_PFAL_end_active_and_accept(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_end_active_and_accept");
    MTPNP_AD_CC_SetSourceId(((mmi_ucm_multiple_call_struct*) act_struct)->source_id);

    if (MTPNP_AD_CC_End_Active_and_Accept_Call(MTPNP_AD_CC_HANDLE_2ND_INCOMING))
    {
        PRINT_INFORMATION("MTPNP_PFAL_end_active_and_accept SUCCESS");
    }
    else
    {
        PRINT_INFORMATION("MTPNP_PFAL_end_active_and_accept FAILED");
    }
}

void MTPNP_PFAL_end_active_and_accept_rsp(MTPNP_BOOL result, MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_act_rsp_struct rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_end_active_and_accept_rsp");
    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);

    MTPNP_OSAL_memset(&rsp, 0, sizeof(mmi_ucm_act_rsp_struct));

    rsp.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(rsp.call_list);

    if (result == FALSE)
    {
        rsp.result_info.result = FALSE;
        rsp.result_info.error_msg = error_msg;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ACTIVE_AND_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &rsp);
    }
    else
    {
        rsp.result_info.result = TRUE;
        mmi_ucm_dispatch_rsp(MMI_UCM_END_ACTIVE_AND_ACCEPT, MMI_UCM_VOICE_CALL_TYPE_SIM2, (void *) &rsp);
    }
    OslMfree(rsp.call_list);
}

void MTPNP_PFAL_start_dtmf(void *act_struct)
{
    MTPNP_UINT16 *keycode = (MTPNP_UINT16 *) act_struct;
    PRINT_INFORMATION("MTPNP_PFAL_start_dtmf");
    MTPNP_PFAL_UCMDTMFHandle(*keycode);
}

void MTPNP_PFAL_stop_dtmf(void *act_struct)
{
    PRINT_INFORMATION("MTPNP_PFAL_stop_dtmf");
    MTPNP_PFAL_UCMDTMFStop();
}

void MTPNP_PFAL_sync_call_list_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_sync_call_list_struct *call_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_sync_call_list_ind");
    /*call list */
    call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_SYNC_CALL_LIST, (void *) call_list);
    OslMfree(call_list);
}

void MTPNP_PFAL_alert_ind(CM_CALL_HANDLE call_handle, MTPNP_UINT8 gen_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_alert_ind_struct alert_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_alert_ind");
    memset(&alert_ind, 0, sizeof(mmi_ucm_alert_ind_struct));

    /*generate tone or not */
    alert_ind.local_gen = gen_tone;

    /*call list */
    alert_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(alert_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_ALERT_IND, (void *) &alert_ind);
    OslMfree(alert_ind.call_list);
}

void MTPNP_PFAL_connect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_connect_ind_struct connect_ind;
    MTPNP_CHAR * displayName = MTPNP_NULL;
    MTPNP_UINT8 *logName = NULL;
    MTPNP_UINT8 *number = NULL;
    MTPNP_UINT16 Slave_index = MTPNP_AD_CC_GetCurIndex();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_connect_ind");
    MTPNP_OSAL_memset(&connect_ind, 0, sizeof(mmi_ucm_connect_ind_struct));

    /*uid info */
    connect_ind.uid_info.call_id = MTPNP_AD_CC_GetCallHandle(Slave_index);
    connect_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(Slave_index);
    //connect_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2();
    connect_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(Slave_index));

    /*remote info */
    
    displayName = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(Slave_index);

    /*display name*/
#ifdef __IP_NUMBER__
    if (displayName != MTPNP_NULL && GetTempUseIPNumber() == FALSE)
#else /* __IP_NUMBER__ */
    if (displayName != MTPNP_NULL)
#endif /* __IP_NUMBER__ */
    {
        mmi_ucs2cpy((MTPNP_CHAR *) connect_ind.remote_info.disp_name, displayName);
    }
    else
    {
        displayName = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(Slave_index);
        if ((mmi_ucs2ncmp((PS8) displayName, (PS8) L"*31#", 4) == 0) ||
            (mmi_ucs2ncmp((PS8) displayName, (PS8) L"#31#", 4) == 0))
        {
            mmi_ucs2cpy((MTPNP_CHAR *) connect_ind.remote_info.disp_name, displayName+8);
        }
        else
        {
            mmi_ucs2cpy((MTPNP_CHAR *) connect_ind.remote_info.disp_name, displayName);
        }
    }

    /*call log name*/
    if (displayName != MTPNP_NULL)
    {
        mmi_ucs2ncpy((MTPNP_CHAR *)  connect_ind.remote_info.log_name, displayName, MMI_UCM_MAX_DISP_NAME_LEN);
    }

    number = MTPNP_AD_CC_GetCurrCallNum(Slave_index);
    mmi_ucs2_n_to_asc((S8 *) connect_ind.remote_info.num_uri, (S8 *) number, MMI_UCM_MAX_NUM_URI_LEN);

    /*call list */
    connect_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(connect_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_CONNECT_IND, (void *) &connect_ind);
    OslMfree(connect_ind.call_list);

    ResetRedialAttempts();

#if defined(__IP_NUMBER__)
    SetTempUseIPNumber(FALSE);
#endif  /* __IP_NUMBER__ */
    
}

void MTPNP_PFAL_notify_ind(MTPNP_UINT8 * error_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_notify_ind_struct notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_notify_ind");
    MTPNP_OSAL_memset(&notify_ind, 0, sizeof(mmi_ucm_notify_ind_struct));

    /*display */
    notify_ind.disp_msg = error_msg;

    /*call list */
    notify_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(notify_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_NOTIFY_IND, (void *) &notify_ind);
    OslMfree(notify_ind.call_list);
}

void MTPNP_PFAL_sat_info_ind(MTPNP_UINT8 * newNumber, MTPNP_UINT8 * msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_notify_ind_struct notify_ind;
    MTPNP_UINT16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_sat_info_ind");
    MTPNP_OSAL_memset(&notify_ind, 0, sizeof(mmi_ucm_notify_ind_struct));

    /*modify the number*/
    index = MTPNP_AD_CC_GetCurIndex();
    MTPNP_AD_CC_SetCallCurrNum(index, newNumber);

    /*display */
    notify_ind.disp_msg = msg;

    /*call list */
    notify_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(notify_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_NOTIFY_IND, (void *) &notify_ind);
    OslMfree(notify_ind.call_list);

    MTPNP_PFAL_sync_call_list_ind();
}


void MTPNP_PFAL_dial_req_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_ring_ind_struct dial_req_ind;
    E_MTPNP_AD_CALL_STATE callState;
    MTPNP_CHAR * log_name = MTPNP_NULL;
    MTPNP_CHAR * log_num = MTPNP_NULL;
    PHB_CM_INTERFACE PhoneNumberStruct;
    PHB_CM_INTERFACE *sPhoneNumberStruct;
    MTPNP_UINT8 *number = MTPNP_NULL;
    U16 count;
    MTPNP_UINT16 index; 
    MTPNP_UINT16 sInIndex;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("GSM salve call application: mmi_gsm_dial_req_ind");

    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    index = MTPNP_AD_CC_GetCurIndex();

    number = MTPNP_AD_CC_GetCurrCallNum(index);

    PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(number, MTPNP_TRUE, SIM2);

    MTPNP_PFAL_SetCMPhoneBookStruct(&PhoneNumberStruct);

    MTPNP_PFAL_CC_PHBSetdataforCall(index);

    MTPNP_PFAL_SetCallGroup(MTPNP_PFAL_GetUnUsedGroupID(), index);
    
    memset(&dial_req_ind, 0, sizeof(mmi_ucm_ring_ind_struct));
    
    dial_req_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    
    MTPNP_PFAL_get_call_list(dial_req_ind.call_list);
    
    /*remote info*/
    for (count = 0; count < MTPNP_AD_MAX_CALLS; count++)
    {
        callState = MTPNP_AD_CC_GetCallCurState(count);
        if (callState == MTPNP_CM_OUTGOING_STATE)
        {
            log_name = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallName(count);
            mmi_ucs2_n_to_asc((MTPNP_CHAR *) dial_req_ind.display_info.num_uri,
                            (MTPNP_CHAR *) MTPNP_AD_CC_GetCurrCallNum(count), MMI_UCM_MAX_NUM_URI_LEN);

            /*display name*/
        #ifdef __IP_NUMBER__
            if (log_name != MTPNP_NULL && GetTempUseIPNumber() == FALSE)
        #else /* __IP_NUMBER__ */
            if (log_name != MTPNP_NULL)
        #endif /* __IP_NUMBER__ */
            {
                mmi_ucs2cpy((MTPNP_CHAR *) dial_req_ind.display_info.disp_name, log_name);
            }
            else
            {
                log_num = (MTPNP_CHAR *)MTPNP_AD_CC_GetCurrCallNum(count);
                if ((mmi_ucs2ncmp((PS8) log_num, (PS8) L"*31#", 4) == 0) ||
                    (mmi_ucs2ncmp((PS8) log_num, (PS8) L"#31#", 4) == 0))
                {
                    mmi_ucs2cpy((MTPNP_CHAR *) dial_req_ind.display_info.disp_name, log_num+8);
                }
                else
                {
                    mmi_ucs2cpy((MTPNP_CHAR *) dial_req_ind.display_info.disp_name, log_num);
                }
            }

            /*call log name*/
            if (log_name != MTPNP_NULL)
            {
                 mmi_ucs2ncpy((MTPNP_CHAR *) dial_req_ind.display_info.log_name, log_name, MMI_UCM_MAX_DISP_NAME_LEN);
            }
        }
    }

    /*uid info*/
    MMI_ASSERT(MTPNP_AD_GetOutgoingCallIndex(&sInIndex));
    dial_req_ind.uid_info.call_id = MTPNP_AD_CC_GetCallHandle(sInIndex);
    dial_req_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(sInIndex);
    dial_req_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(sInIndex));

    /*alert info*/
    sPhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();    
    if (sPhoneNumberStruct->alertType == MMI_ALERT_NONE)
    {
        dial_req_ind.alert_info.alert_type = GetMtCallAlertTypeEnum();
    }
    else
    {
        dial_req_ind.alert_info.alert_type = sPhoneNumberStruct->alertType;
    }
    dial_req_ind.alert_info.image_info.image_id = sPhoneNumberStruct->pictureId;
    dial_req_ind.alert_info.image_info.record_index = sPhoneNumberStruct->record_index;
    /*dial_req_ind.alert_info.image_info.video_id = PhoneNumberStruct->videoId;
    dial_req_ind.alert_info.image_info.video_record_index = PhoneNumberStruct->video_record_index;*/

    mmi_ucm_dispatch_ind(MMI_UCM_DIAL_REQ_IND, (void *)&dial_req_ind);

    OslMfree(dial_req_ind.call_list);	
}

#ifdef __SAT__
void MTPNP_PFAL_MakeSATCall(MTPNP_CHAR* InNumber)
{

	PHB_CM_INTERFACE PhoneNumberStruct;
	MTPNP_UINT8 *number = MTPNP_NULL;
	MTPNP_UINT16 index;
	MTPNP_UINT8 *SATDisplayName;
	MTPNP_UINT8 dcs;
	MTPNP_UINT8 length;

	PRINT_INFORMATION("MTPNP_PFAL_MakeSATCall");

    	if( MTPNP_AD_CC_GetFirstFreeCallIndex(&index)!=MTPNP_TRUE)
	{
		PRINT_INFORMATION("MTPNP_PFAL_MakeSATCall: FAIL");
		return ;
	}

	MTPNP_AD_CC_SetCurIndex(index);

	MTPNP_AD_CC_MakeSATCall(InNumber);
    
	number = MTPNP_AD_CC_GetCurrCallNum(index);

	PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(number, MTPNP_TRUE, SIM2);

	MTPNP_PFAL_SetCMPhoneBookStruct(&PhoneNumberStruct);

	MTPNP_PFAL_CC_PHBSetdataforCall(index);

	SATDisplayName = (MTPNP_UINT8 *) SATGetCallDisplay(&dcs);

	if (SATDisplayName != NULL)
	{
		PRINT_INFORMATION("MTPNP_PFAL_MakeSATCall, show name from SAT:%d", SATDisplayName);
		length = (MTPNP_UINT8) (MTPNP_PFAL_Unicode_String_Length((S8 *) (SATDisplayName)));
		MTPNP_AD_CC_SetCallCurrNameLen(index, length);
		MTPNP_AD_CC_SetCallCurrName(index, SATDisplayName);        
	}

	MTPNP_PFAL_SetCallGroup(MTPNP_PFAL_GetUnUsedGroupID(), index);

	mmi_sat_call_setup_dial_from_ucm();
	
	if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_DIAL)
	{
		MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_VOICE, MTPNP_NULL);
  	}
  	else if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_DIAL)
  	{
		MTPNP_PFAL_hold_and_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_VOICE, MTPNP_NULL);
  	}
}

void MTPNP_PFAL_MakeSATCallFail()
{
      MTPNP_UINT16 index;
      
      PRINT_INFORMATION("MTPNP_PFAL_MakeSATCallFail");
      MTPNP_AD_GetOutgoingCallIndex(&index);
      MTPNP_AD_CC_SetCurIndex(index);
      MTPNP_AD_CC_ModifyContext(MTPNP_CM_OUTGOING_FAILD);
      MTPNP_PFAL_release_ind(ERR_L4C_GEN_CAUSE);
}

#endif /* __SAT__ */

void MTPNP_PFAL_MakeCSDCall(MTPNP_CHAR* InNumber)
{

        PHB_CM_INTERFACE PhoneNumberStruct;
        MTPNP_UINT8 *number = MTPNP_NULL;
        MTPNP_UINT16 index;

        PRINT_INFORMATION("MTPNP_PFAL_MakeCSDCall");

        if( MTPNP_AD_CC_GetFirstFreeCallIndex(&index)!=MTPNP_TRUE)
        {
            PRINT_INFORMATION("MTPNP_PFAL_MakeCSDCall: FAIL");
            return ;
        }

        MTPNP_AD_CC_SetCurIndex(index);

        MTPNP_AD_CC_MakeCSDCall(InNumber);
    
        number = MTPNP_AD_CC_GetCurrCallNum(index);

        PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(number, MTPNP_TRUE, SIM2);

        MTPNP_PFAL_SetCMPhoneBookStruct(&PhoneNumberStruct);

        MTPNP_PFAL_CC_PHBSetdataforCall(index);

        MTPNP_PFAL_SetCallGroup(MTPNP_AD_INVALID_CALL_HANDLE, index);

        MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_VOICE, MTPNP_NULL);

}

void MTPNP_PFAL_ring_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_ring_ind_struct ring_ind;
    PHB_CM_INTERFACE *PhoneNumberStruct;
    MTPNP_UINT8 *displayName = NULL;
    MTPNP_UINT8 *logName = NULL;
    MTPNP_UINT8 *number = NULL;
    MTPNP_UINT16 sInIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_ring_ind");
    
    memset(&ring_ind, 0, sizeof(mmi_ucm_ring_ind_struct));

    PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();

    /*alert info */
    if (PhoneNumberStruct->alertType == MMI_ALERT_NONE)
    {
        ring_ind.alert_info.alert_type = GetMtCallAlertTypeEnum();
    }
    else
    {
        ring_ind.alert_info.alert_type = PhoneNumberStruct->alertType;
    }
    ring_ind.alert_info.image_info.image_id = PhoneNumberStruct->pictureId;
    ring_ind.alert_info.image_info.record_index = PhoneNumberStruct->record_index;
    ring_ind.alert_info.image_info.video_id = PhoneNumberStruct->videoId;
    ring_ind.alert_info.image_info.video_record_index = PhoneNumberStruct->video_record_index;

    if(PhoneNumberStruct->backlightId == 0)
    {
        ring_ind.alert_info.light_id = GetLightStatus();
    }
    else
    {
        ring_ind.alert_info.light_id = PhoneNumberStruct->backlightId;
    }
    PRINT_INFORMATION("MTPNP_PFAL_ring_ind, light id:%d", ring_ind.alert_info.light_id);

    ring_ind.alert_info.line_icon = IMG_CM_ICON_LINE1;

    if (IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
    {
        ring_ind.alert_info.line_icon = 0;
    }
    else
    {
        if (MTPNP_AD_CC_GetCallType(MTPNP_AD_CC_GetCurIndex()) == CM_AUX_VOICE_CALL)
        {
            ring_ind.alert_info.line_icon = IMG_CM_ICON_LINE2;
        }
    }

    if (PhoneNumberStruct->ringtoneId == 0)
    {
    #ifdef __MMI_DUAL_PROFILE_SUPPORT__
        ring_ind.alert_info.tone_id = GetCard2RingToneID();
    #endif /* __MMI_DUAL_PROFILE_SUPPORT__ */
    }
    else
    {
        ring_ind.alert_info.tone_id = PhoneNumberStruct->ringtoneId;
    }

    /* Assert when AD think no incoming call */
    MMI_ASSERT(MTPNP_AD_GetIncomingCallIndex(&sInIndex));

    displayName = PhoneNumberStruct->name;
    mmi_ucs2ncpy((S8 *) ring_ind.display_info.disp_name, (S8 *) displayName, MMI_UCM_MAX_DISP_NAME_LEN);
    logName = PhoneNumberStruct->name;
    mmi_ucs2ncpy((S8 *) ring_ind.display_info.log_name, (S8 *) logName, MAX_PB_NAME_LENGTH+1);
    number = PhoneNumberStruct->number;
    mmi_ucs2_n_to_asc((S8 *) ring_ind.display_info.num_uri, (S8 *) number, MMI_UCM_MAX_NUM_URI_LEN);
    /*uid info */
    ring_ind.uid_info.call_id = MTPNP_AD_CC_GetCallHandle(sInIndex);
    ring_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(sInIndex);
    //ring_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(); 
    ring_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(sInIndex));

    /*L4C information*/
    ring_ind.l4c_info.l4c_type = MTPNP_AD_CC_GetCallType(sInIndex);
    MTPNP_AD_CC_GetL4cInfo((ST_MTPNP_L4C_NUMBER_STRUCT *)&ring_ind.l4c_info.l4c_number, sInIndex);
    
    /*call list */
    ring_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(ring_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_RING_IND, (void *) &ring_ind);
    OslMfree(ring_ind.call_list);
}

void MTPNP_PFAL_release_ind(MTPNP_UINT16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_release_ind_struct release_ind;
    MTPNP_UINT16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_release_ind error_cause = %d", error_cause);
    MTPNP_OSAL_memset(&release_ind, 0, sizeof(mmi_ucm_release_ind_struct));

    if(MTPNP_AD_GetAutoRejectCallID() == MTPNP_AD_CC_GetRelHandle())
    {
        MTPNP_AD_SetAutoRejectCallID(0);
    }

    /*uid info */
    index = MTPNP_AD_CC_GetCurIndex();
    release_ind.uid_info.call_id = MTPNP_AD_CC_GetRelHandle();
    release_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(index);
    //release_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2();
    release_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(index));

    /*display info */
    release_ind.image_id = IMG_ERROR_NOTIFY;
    release_ind.tone_id = CALL_DROP_TONE;

    switch (error_cause)
    {
        case ERR_UNASSIGNED_NUM:
            release_ind.tone_id = NUM_UNOBTAIN_TONE;
        case ERR_INVALID_NUMBER_FORMAT:
            release_ind.disp_msg = (U8 *)GetString(ERROR_UNRECOGNIZED_NUMBER);
            break;

        case ERR_SWITCH_EQUIPMENT_CONGESTION:
            release_ind.tone_id = CONGESTION_TONE;
        case ERR_CALL_REJECTED:
            release_ind.tone_id= AUTH_FAIL_TONE;
        case ERR_CHANNEL_UN_ACCP:
        case ERR_NETWORK_OUT_OF_ORDER:
        case ERR_QOS_UNAVAIL:
        case ERR_INVALID_TRANSIT_NW_SEL:
        case ERR_CSMCC_NO_RESPONSE_FROM_NW:
        case ERR_NETWORK_FAILURE:
        case ERR_CM_MM_RR_CONN_RELEASE:
        case ERR_IMSI_UNKNOWN_IN_VLR:
            release_ind.disp_msg = (U8 *)GetString(ERROR_NETWORK_FAIL);
            break;
            
        case ERR_NO_CIRCUIT_CHANNEL_AVAIL:
        case ERR_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case ERR_RESOURCE_UNAVAIL_UNSPECIFIED:
            release_ind.disp_msg = (U8 *)GetString(ERROR_BUSY_NETWORK);
            break;

        case ERR_OPR_DTR_BARRING:
        case ERR_CALL_BARRED:
        case ERR_IC_BAR_CUG:
        case ERR_BEARER_CAP_NOT_AVAIL:
        case ERR_CM_MM_ACCESS_BARRED:
            release_ind.disp_msg = (U8 *)GetString(ERROR_BARRED_CALL);
            break;
        
        case ERR_NO_USER_RESPONDING:
            release_ind.disp_msg = (U8 *)GetString(ERROR_NOT_RESPONDING);
            break;
        
        case ERR_NO_ANSWER_ON_ALERT:
            release_ind.disp_msg = (U8 *)GetString(ERROR_NO_ANSWER);
            break;
        
        case ERR_REQ_FACILITY_UNAVAIL:
        case ERR_IE_NOT_IMPLEMENTED:
        case ERR_CONDITIONAL_MM_IE_ERROR:
        case ERR_CM_MM_ASSIGNMENT_REJECT:
            release_ind.disp_msg = (U8 *)GetString(ERROR_UNAVAILABLE);
            break;
        
        case ERR_IMSI_UNKNOWN_IN_HLR:
        case ERR_CM_MM_IMSI_DETACH:
        case ERR_CM_MM_AUTH_FAILURE:
        case ERR_CM_MM_STATE_NOT_ALLOWED_CM:
            release_ind.disp_msg = (U8 *)GetString(ERROR_FAIL);
            break;
        
        case ERR_IMEI_NOT_ACCEPTED:
            release_ind.disp_msg = (U8 *)GetString(ERROR_IMEI_ERROR);
            break;
        
        case ERR_REQ_FAC_NOT_SUBS:
        case ERR_PLMN_NOT_ALLOWED:
        case ERR_LOCATION_AREA_NOT_ALLOWED:
        case ERR_ROAMING_AREA_NOT_ALLOWED:
        case ERR_GPRS_NOT_ALLOWED_IN_PLMN:
        case ERR_NO_SUITABLE_CELLS_IN_LA:
        case ERR_MSC_TEMP_NOT_REACHABLE:
        case ERR_CM_MM_ABORT_BY_NW:
        case ERR_BEARER_CAP_NOT_AUTHORISED:
        case ERR_SERV_OPTION_TEMP_OUT_OF_ORDER: 
            release_ind.disp_msg = (U8 *)GetString(ERROR_NETWORK_NOT_ALLOWED);
            break;
        
        case ERR_SERV_OPTION_NOT_SUPPORTED:
        case ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED:
        case ERR_CALL_CANNOT_BE_IDENTIFIED:
            release_ind.disp_msg = (U8 *)GetString(ERROR_COMMAND_NOT_SUPPORTED);
            break;
        
        case ERR_ACM_EXCEEDED:
            release_ind.disp_msg = (U8 *)GetString(ERROR_ACM_EXCEEDED);
            break;
        
        case ERR_USER_BUSY:
            release_ind.disp_msg = (U8 *)GetString(ERROR_USER_BUSY);
            release_ind.tone_id = TONE_BUSY_CALL_GSM;
            break;

        case ERR_L4C_FDN_FAIL:
            release_ind.disp_msg = (U8 *)GetString(ERROR_FDN_FAIL);
            break;

        default:
             /*drop mo call*/
            if ((MTPNP_AD_CC_IsSlaveCCInOutgoing() == MTPNP_FALSE  &&
                 mmi_ucm_app_outgoing_call(MMI_UCM_SIM2_CALL_TYPE_ALL) > 0) && 
                (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_END_SINGLE ||
                MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_END_ALL))
            {
                release_ind.disp_msg = (U8 *) GetString(STR_CALL_ABORTED);
            }
            /*Dial indication fial, not call release*/
            else if(release_ind.uid_info.call_id == MMI_UCM_INVALID_ID)
            {
                release_ind.disp_msg = (U8 *)GetString(INCOMING_DEFAULT_ERROR);
            }
            /*normal call end*/
            else
            {
                release_ind.disp_msg = (U8 *) GetString(STR_CALL_ENDED);

	#ifdef __SUPPORT_PITCHSHIFT__ //LIJUNZHAO_PITCHSHIFT_ERR_080425
		if(gPtichShiftOpen)  
		{
			Stop_CallingPitchShift();
			gPtichShiftOpen = 0;
		}
	#endif


				
            }
            release_ind.image_id = IMG_CM_STATE_ENDED;
            break;
    }

#if defined(__IP_NUMBER__)
    if(MTPNP_AD_CC_IsSlaveCCInOutgoing() == MTPNP_FALSE  && mmi_ucm_app_outgoing_call(MMI_UCM_SIM2_CALL_TYPE_ALL) > 0)
    {
        SetTempUseIPNumber(FALSE);
    }
#endif  /* __IP_NUMBER__ */

    if(release_ind.uid_info.call_id == mtpnp_auto_dtmf_call_id)
    {
        MTPNP_PFAL_auto_dtmf_conf_cancel();
        mtpnp_auto_dtmf_call_id = 0;
    }

    if (MTPNP_AD_CC_GetTotalCallCount() > 0)
    {
        release_ind.tone_id = 0;
    }

    /*call list */
    release_ind.call_list = OslMalloc(sizeof(mmi_ucm_sync_call_list_struct));
    MTPNP_PFAL_get_call_list(release_ind.call_list);
    mmi_ucm_dispatch_ind(MMI_UCM_RELEASE_IND, (void *) &release_ind);
    OslMfree(release_ind.call_list);

    if(release_ind.uid_info.call_id == mtpnp_auto_dtmf_call_id)
    {
        MTPNP_PFAL_auto_dtmf_conf_cancel();
        mtpnp_auto_dtmf_call_id = 0;
    }

    if(MTPNP_AD_CC_GetTotalCallCount() == 0)
    {
        MTPNP_OSAL_memset(gMtpnpSumACMValue, 0x0, sizeof(gMtpnpSumACMValue));
    }
}

void MTPNP_PFAL_call_cost_ind(CM_CALL_HANDLE call_handle, MTPNP_UINT8 * symbol, MTPNP_UINT8 * value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_call_cost_struct call_cost_ind;
    U16 count;
    MTPNP_UINT16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&call_cost_ind, 0, sizeof(mmi_ucm_call_cost_struct));

    call_cost_ind.symbol = symbol;
    call_cost_ind.cost = value;

    /*UID info*/
    MTPNP_AD_CC_GetCallIndexbyHandle((unsigned char) call_handle, &index);
    call_cost_ind.uid_info.call_id = MTPNP_AD_CC_GetCallHandle(index);
    call_cost_ind.uid_info.group_id = MTPNP_PFAL_GetCallGroup(index);
    call_cost_ind.uid_info.call_type = MTPNP_PFAL_GetCallTypeSim2(MTPNP_AD_CC_GetCallType(index));

    mmi_ucm_dispatch_ind(MMI_UCM_CALL_COST_IND, (void *)&call_cost_ind);
}

extern U8 gRedialMsgTemp[100];
void MTPNP_PFAL_auto_redial_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_auto_redial_struct auto_redial_ind;
    S8 mtpnpredialnum[MAX_NUMBER];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_auto_redial_ind");
    GetCard2RedialNumber(mtpnpredialnum);
    memset(&auto_redial_ind, 0, sizeof(mmi_ucm_auto_redial_struct));
    memcpy((S8 *) auto_redial_ind.display_msg, (S8 *) & gRedialMsgTemp, MMI_UCM_MAX_AUTO_REDIAL_MSG_LEN);
    auto_redial_ind.abort_hdlr = (FuncPtr) ResetRedialAttempts;

    mmi_ucs2_n_to_asc((S8 *) auto_redial_ind.num_uri, (S8 *) mtpnpredialnum, MMI_UCM_MAX_NUM_URI_LEN);

    //auto_redial_ind.call_type = MTPNP_PFAL_GetCallTypeSim2();
    auto_redial_ind.call_type = MTPNP_PFAL_GetCallTypeSim2(CSMCC_VOICE_CALL);
    auto_redial_ind.attempt = GetCurrRedialAttp();
    auto_redial_ind.time = cm_p->redial_info.Timer;

    mmi_ucm_dispatch_ind(MMI_UCM_AUTO_REDIAL_IND, (void *) &auto_redial_ind);

#ifdef __IP_NUMBER__
    while(GetTempUseIPNumber())
    {
        SetTempUseIPNumber(FALSE);
    }
#endif /* __IP_NUMBER__ */
}

void MTPNP_PFAL_csd_call_approve(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CSD_APPROVE_REQ *msg;
    PU8 start;
    U8 number[MAX_DIGIT];
    S8 uniinput_string[MAX_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("MTPNP_PFAL_csd_call_approve");

    msg = (MMI_CSD_APPROVE_REQ*) MsgStruct;
    memset((PS8) number, 0, MAX_DIGIT);
    start = number;

    if (msg->call_num_type & 0x10)
    {
        number[0] = '+';
        start++;
    }

    if (msg->call_num_len < MAX_DIGIT)
    {
        strncpy((PS8) start, (PS8) msg->call_num, msg->call_num_len);
    }
    else
    {
        strcpy((PS8) start, (PS8) msg->call_num);
    }

    memset(uniinput_string, 0, MAX_NUMBER);
    mmi_asc_to_ucs2((PS8) uniinput_string, (PS8) number);

    if(mmi_ucm_app_make_call_with_source(MMI_UCM_FROM_ABM, MMI_UCM_CSD_CALL_TYPE_SIM2, (U8 *)uniinput_string))
    {
        MTPNP_PFAL_csd_call_confirm(MTPNP_TRUE, msg);
    }
    else
    {
        MTPNP_PFAL_csd_call_confirm(MTPNP_FALSE, msg);
    }
}

void MTPNP_PFAL_csd_call_confirm(MTPNP_BOOL result, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_CSD_APPROVE_CNF *csd_cnf;
    MMI_CSD_APPROVE_REQ *info = (MMI_CSD_APPROVE_REQ*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_csd_call_confirm");

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_ABM;
    Message.oslMsgId = PRT_CSD_CALL_APPROVE_CNF;

    csd_cnf = (MMI_CSD_APPROVE_CNF*) OslConstructDataPtr(sizeof(MMI_CSD_APPROVE_CNF));

    csd_cnf->prof_id = info->prof_id;
    csd_cnf->sim_info = info->sim_info;
    csd_cnf->result = result;

    Message.oslDataPtr = (oslParaType*) csd_cnf;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
    return;
}

void MTPNP_PFAL_start_processing_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_start_processing_struct start_processing_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_start_processing_ind");
    MTPNP_OSAL_memset(&start_processing_ind, 0, sizeof(mmi_ucm_start_processing_struct));

    start_processing_ind.content = (U8 *) GetString(STR_ID_UCM_PROCESSING);

    mmi_ucm_dispatch_ind(MMI_UCM_START_PROCESSING_IND, (void *) &start_processing_ind);
}

void MTPNP_PFAL_stop_processing_ind(MTPNP_UINT8 * disp_msg, MTPNP_UINT16 image_id, MTPNP_UINT16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_processing_struct stop_processing_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_stop_processing_ind");
    MTPNP_OSAL_memset(&stop_processing_ind, 0, sizeof(mmi_ucm_stop_processing_struct));

    stop_processing_ind.disp_msg = disp_msg;
    stop_processing_ind.image_id = image_id;
    stop_processing_ind.tone_id = tone_id;

    mmi_ucm_dispatch_ind(MMI_UCM_STOP_PROCESSING_IND, (void *) &stop_processing_ind);

    MTPNP_PFAL_SetUCMOperationState(MMI_GSM_UCM_NO_ACTION, MMI_GSM_UCM_IDLE);
}

/*****************************************************************************
 * FUNCTION
 *  MTPNP_PFAL_ConfirmDTMFString
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_ConfirmDTMFString()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTPNP_AD_CC_ConfirmDTMFString((void *)gMtpnpDTMFConfirmBuf);
}

/*****************************************************************************
 * FUNCTION
 *  MTPNP_PFAL_PsCBackConfirmDTMFString
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_PsCBackConfirmDTMFString(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DTMF_CONFIRM_IND *msg = (MMI_DTMF_CONFIRM_IND*) info;
    U8 tempBuf[MAX_DTMFBUF_DIGITS * ENCODING_LENGTH + 40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempBuf, 0, sizeof(tempBuf));
    memset(gMtpnpDTMFConfirmBuf, 0, MAX_DTMFBUF_DIGITS);
    strcpy((PS8) gMtpnpDTMFConfirmBuf, (PS8) msg->digits);

    if (MTPNP_AD_CC_GetTotalActiveCallCount() < 1)
    {
        return;
    }

    mmi_ucs2cpy((S8*) tempBuf, (S8*) GetString(STR_DTMF_CONFIRMATION));
    mmi_asc_to_ucs2((S8*) tempBuf + (mmi_ucs2strlen((S8*) tempBuf) * ENCODING_LENGTH), (S8*) gMtpnpDTMFConfirmBuf);
    mtpnp_auto_dtmf_call_id = msg->call_id;
    PRINT_INFORMATION("auto dtmf call id: %d", mtpnp_auto_dtmf_call_id);
    MTPNP_PFAL_auto_dtmf_conf_display((U8*) tempBuf);    
}

/*****************************************************************************
 * FUNCTION
 *  MTPNP_PFAL_PsCBackCallCostInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_PsCBackCallCostInd(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acmIndValue;
    U8 temp[8];
    MMI_CCM_STRUCT *tmp_ccm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MTPNP_PFAL_PsCBackCallCostInd");

    tmp_ccm = (MMI_CCM_STRUCT*) info;    
    
    SetShowAOC(TRUE);

    MTPNP_OSAL_memset(gMtpnpCashSign, 0x0, sizeof(gMtpnpCashSign));
    gMtpnpCashSign[0] = '$';
    
    gMtpnpSumACMValue += tmp_ccm->ccm;

    MTPNP_OSAL_memset(temp, 0x0, sizeof(temp));
    sprintf((S8*) temp, "%d", (U32) gMtpnpSumACMValue);
    MTPNP_PFAL_Ansii_To_Unicode_String((MTPNP_CHAR *)&gMtpnpAocBuffer, (MTPNP_CHAR *)temp);
    MTPNP_PFAL_call_cost_ind(tmp_ccm->call_id , (PU8) gMtpnpCashSign, (PU8) gMtpnpAocBuffer);
}

void MTPNP_PFAL_auto_dtmf_conf_display(MTPNP_UINT8 * disp_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_display_cnf_struct auto_dtmf_conf;
    MTPNP_UINT16 call_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("MTPNP_PFAL_auto_dtmf_conf_display");

    memset(&auto_dtmf_conf, 0, sizeof(mmi_ucm_display_cnf_struct));

    auto_dtmf_conf.content = disp_msg;
    auto_dtmf_conf.end_hdlr = NULL;
    auto_dtmf_conf.rsk_hdlr = NULL;
    auto_dtmf_conf.rsk_str = STR_GLOBAL_NO;
    auto_dtmf_conf.send_hdlr = NULL;
    auto_dtmf_conf.lsk_hdlr =(FuncPtr)MTPNP_PFAL_ConfirmDTMFString;
    auto_dtmf_conf.lsk_str = STR_GLOBAL_YES;
    auto_dtmf_conf.cancel_hdlr = NULL;

    mmi_ucm_dispatch_cnf(MMI_UCM_DISPLAY_CNF, (void *)&auto_dtmf_conf);

}

void MTPNP_PFAL_auto_dtmf_conf_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_display_cnf_struct auto_dtmf_conf;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("MTPNP_PFAL_auto_dtmf_conf_cancel");
    
    memset(&auto_dtmf_conf, 0, sizeof(mmi_ucm_display_cnf_struct));
    
    mmi_ucm_dispatch_cnf(MMI_UCM_CANCEL_CNF, (void *)&auto_dtmf_conf);

}

void MTPNP_PFAL_UCMDTMFHandle(MTPNP_UINT16 keycode)
{
    MTPNP_UINT8 dtmf_trans;
    PRINT_INFORMATION("MTPNP_PFAL_UCMDTMFHandle");
    dtmf_trans = MTPNP_PFAL_ConvertKeycode2Ascii(keycode);
    MTPNP_AD_CC_SendDTMF(dtmf_trans);
}

void MTPNP_PFAL_UCMDTMFStop(void)
{
    PRINT_INFORMATION("MTPNP_PFAL_UCMDTMFStop");
    MTPNP_AD_CC_SendDTMF(0);
}

/*
mmi_ucm_call_type_enum MTPNP_PFAL_GetCallTypeSim2(void)
{
   return MMI_UCM_VOICE_CALL_TYPE_SIM2;
}*/

mmi_ucm_call_type_enum MTPNP_PFAL_GetCallTypeSim2(csmcc_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(call_type)
    {
        case CSMCC_VOICE_CALL:
             return MMI_UCM_VOICE_CALL_TYPE_SIM2;
             
        case CSMCC_AUX_VOICE_CALL:
             return MMI_UCM_VOICE_CALL_TYPE_SIM2;
             
        case CSMCC_DATA_CALL:
             return MMI_UCM_DATA_CALL_TYPE_SIM2;
             
        case CSMCC_FAX_CALL:
             return MMI_UCM_DATA_CALL_TYPE_SIM2;
             
        case CSMCC_CSD_CALL:
             return MMI_UCM_CSD_CALL_TYPE_SIM2;
             
        case CSMCC_SAT_DATA_CALL:
             return MMI_UCM_DATA_CALL_TYPE_SIM2;
    }
    PRINT_INFORMATION("It is not correct call type");
    //ASSERT HERE
    return 0;
}

#endif    /*__MMI_UCM__*/

#endif   /* __MMI_DUAL_SIM_MASTER__*/
