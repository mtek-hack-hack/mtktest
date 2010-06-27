/***********************************************
File name : MTPNP_PFAL_CC.c
Contents : MTPNP Call control platform 
History : Create by : Jing xiaoyong, April 9, 2007
************************************************/
#include "MMI_Features.h"

//#ifdef __MERCURY_MASTER__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "stdC.h"
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
#include "SSCStringHandle.h"

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
#include "wgui_status_icons.h"

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

#ifdef __MMI_BT_HP_SUPPORT__
#include "BTMMIHPGprots.h"
#endif

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#include "app_datetime.h"

#ifdef __MMI_UCM__
#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMProt.h"
#endif
#include "SettingGenum.h"
#include "SettingGprots.h"
#include "ProfilesDefs.h"
#include "MTPNP_AD_resdef.h"
#include "CallSetUpEnum.h"
#include "IdleAppProt.h"
#include "RedialHelperGProt.h"

/* MTPNP Header file */
#include "MTPNP_AD_master_header.h"
#include "CommonStubsProt.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_custom_hw.h"

#ifdef __MMI_UCM__
#include "MTPNP_PFAL_CC_UCM.h"
#else
#include "MTPNP_PFAL_CC_NOUCM.h"
#endif
/* MTPNP Header file */
#include "MTPNP_PFAL_custom_hw.h"

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
#include "MTPNP_PFAL_dualprof.h"
#endif

extern MYTIME gTimeStructForCallDuration;
static PHB_CM_INTERFACE mtpnp_phonenumstruct;   /*maintain mtpnp slave struct for cc phb match */
S8 MTPNP_PFAL_gUSSDbuf[MAX_DIGITS_USSD * ENCODING_LENGTH];
#ifdef __LSK_KEYSEND2_IN_ONE__
static MTPNP_BOOL mtpnpIsForCall = MTPNP_FALSE;
static MTPNP_BOOL mtpnpDialFromLSK = MTPNP_FALSE;
static mmi_key_types_enum mtpnpsendkeytype;     /*send key event type */
#endif /* __LSK_KEYSEND2_IN_ONE__ */
static PsFuncPtr USSD_ABORT_RSP = 0;


/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_CC_GetIsMultiIncomingSupport(void)
function: to determine if multi incoming call supported 
return  MTPNP_FALSE not support
	   MTPNP_TRUE support
Author: Dayo Eric Jing
*******************************************************************************************/

MTPNP_BOOL MTPNP_PFAL_CC_GetIsMultiIncomingSupport(void)
{
#ifdef __MMI_UCM__
    return MTPNP_FALSE;
#else
    return MTPNP_TRUE;
#endif
}

/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_CC_GetIsCftNotifySupport(void)
function: to determine if one is outgoing, another incoming call the outgoing should be hold?
       MTPNP_AD_CALL_ALTER_CFT_NOTIFY support?
return  MTPNP_FALSE   outgoing call should be hold
	   MTPNP_TRUE outgoing call should be canceled
Author: Dayo Eric Jing
*******************************************************************************************/

MTPNP_BOOL MTPNP_PFAL_CC_GetIsCftNotifySupport(void)
{
#ifdef __MMI_UCM__
    return MTPNP_FALSE;
#else
    return MTPNP_TRUE;
#endif
}

/******************************************************************************************
void  MTPNP_PFAL_CC_RegisterInitCB(void)
function: init the UCM or NOUCM callback functions
return  
Author: Dayo Eric Jing
*******************************************************************************************/
void MTPNP_PFAL_CC_RegisterInitCB(void)
{
#ifdef __MMI_UCM__
    MTPNP_PFAL_CC_UCMInitRegister();
#else
    MTPNP_PFAL_CC_NOUCMInitRegister();
#endif
}

/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_IsExistNonSlaveIncomingCall(void)
function: is exist non slave incoming call
return  MTPNP_FALSE   not exsit
	   MTPNP_TRUE exsit
Author: Dayo Eric Jing
*******************************************************************************************/

MTPNP_BOOL MTPNP_PFAL_IsExistNonSlaveIncomingCall(void)
{
#ifdef __MMI_VOIP__
    if ((GetIncomingCallHandle() != -1) || (mmi_voip_get_incoming_call_id() != -1))
#else
    if (GetIncomingCallHandle() != -1)
#endif
        return MTPNP_TRUE;

    return MTPNP_FALSE;
}

/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_IsExistNonMasterIncomingCall(void)
function: is exist non master incoming call
return  MTPNP_FALSE   not exsit
	   MTPNP_TRUE exsit
Author: Dayo Eric Jing
*******************************************************************************************/
MTPNP_BOOL MTPNP_PFAL_IsExistNonMasterIncomingCall(void)
{
#ifdef __MMI_VOIP__
    if ((MTPNP_AD_CC_IsSlaveCCInIncoming()) || (mmi_voip_get_incoming_call_id() != -1))
#else
    if (MTPNP_AD_CC_IsSlaveCCInIncoming())
#endif
        return MTPNP_TRUE;

    return MTPNP_FALSE;
}

/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_IsExistNonSlaveOutgoingCall(void)
function: is exist non slave outgoing call
return  MTPNP_FALSE   not exsit
	   MTPNP_TRUE exsit
Author: Dayo Eric Jing
*******************************************************************************************/

MTPNP_BOOL MTPNP_PFAL_IsExistNonSlaveOutgoingCall(void)
{
#ifdef __MMI_VOIP__
    if ((GetOutgoingCallHandle() != -1) || (mmi_voip_get_outgoing_call_id() != -1))
#else
    if (GetOutgoingCallHandle() != -1)
#endif
        return MTPNP_TRUE;

    return MTPNP_FALSE;

}

/******************************************************************************************
MTPNP_BOOL  MTPNP_PFAL_IsExistNonMasterOutgoingCall(void)
function: is exist non master outgoing call
return  MTPNP_FALSE   not exsit
	   MTPNP_TRUE exsit
Author: Dayo Eric Jing
*******************************************************************************************/

MTPNP_BOOL MTPNP_PFAL_IsExistNonMasterOutgoingCall(void)
{
#ifdef __MMI_VOIP__
    if ((MTPNP_AD_CC_IsSlaveCCInOutgoing()) || (mmi_voip_get_outgoing_call_id() != -1))
#else
    if (MTPNP_AD_CC_IsSlaveCCInOutgoing())
#endif
        return MTPNP_TRUE;

    return MTPNP_FALSE;

}

/******************************************************************************************
E_MTPNP_AD_CALL_ALTER  MTPNP_PFAL_CC_HandleSlaveIncomingCall(void)
function: to determine how to handle the incoming call  

master CC state                           function
	IDLE 				 	 MTPNP_AD_CALL_ALTER_CFT_SHOW
	OUTGOING                          MTPNP_AD_CALL_ALTER_CFT_NOTIFY/MTPNP_AD_CALL_ALTER_CFT_SHOW
	INCOMING                           SLAVE_CALL_ALTER_CFT_REJECT
	ACTIVE					 MTPNP_AD_CALL_ALTER_CFT_SHOW
	HOLD					 MTPNP_AD_CALL_ALTER_CFT_SHOW
*******************************************************************************************/
E_MTPNP_AD_CALL_ALTER MTPNP_PFAL_CC_HandleSlaveIncomingCall(void)
{
    if (MTPNP_TRUE == MTPNP_PFAL_CC_IsBlockSlaveIncoming())
    {
        return MTPNP_AD_CALL_ALTER_CFT_REJECT_BLACK;
    }
    else if (MTPNP_PFAL_IsExistNonSlaveIncomingCall())   //Master Call (GSM+VOIP and others)
    {
        if (MTPNP_TRUE == MTPNP_PFAL_CC_GetIsMultiIncomingSupport())
            return MTPNP_AD_CALL_ALTER_CFT_SHOW;
        else
            return MTPNP_AD_CALL_ALTER_CFT_REJECT_CFT;
    }
    else if (MTPNP_PFAL_IsExistNonSlaveOutgoingCall())   //Master Call (GSM+VOIP and others)
    {
        if (MTPNP_TRUE == MTPNP_PFAL_CC_GetIsCftNotifySupport())
            return MTPNP_AD_CALL_ALTER_CFT_NOTIFY;
        else
            return MTPNP_AD_CALL_ALTER_CFT_SHOW;
    }
    else
    {
        return MTPNP_AD_CALL_ALTER_CFT_SHOW;
    }
}


E_MTPNP_AD_CALL_ALTER MTPNP_PFAL_CC_HandleMasterIncomingCall(void)
{
    if (MTPNP_TRUE == MTPNP_PFAL_CC_IsBlockMasterIncoming())
    {
        return MTPNP_AD_CALL_ALTER_CFT_REJECT_BLACK;
    }
    else if (MTPNP_PFAL_IsExistNonMasterIncomingCall())  //Slave Call (GSM+VOIP and others)
    {
        if (MTPNP_TRUE == MTPNP_PFAL_CC_GetIsMultiIncomingSupport())
            return MTPNP_AD_CALL_ALTER_CFT_SHOW;
        else
            return MTPNP_AD_CALL_ALTER_CFT_REJECT_CFT;
    }
    else if (MTPNP_PFAL_IsExistNonMasterOutgoingCall())  //Slave Call (GSM+VOIP and others)
    {
        if (MTPNP_TRUE == MTPNP_PFAL_CC_GetIsCftNotifySupport())
            return MTPNP_AD_CALL_ALTER_CFT_NOTIFY;
        else
            return MTPNP_AD_CALL_ALTER_CFT_SHOW;
    }
    else
    {
        return MTPNP_AD_CALL_ALTER_CFT_SHOW;
    }

}

MTPNP_BOOL MTPNP_PFAL_CC_IsBlockSlaveIncoming(void)
{
    return MTPNP_FALSE;
}

MTPNP_BOOL MTPNP_PFAL_CC_IsBlockMasterIncoming(void)
{
    return MTPNP_FALSE;         //finish later
}

/*******************************************************************
**function MTPNP_PFAL_CC_GoBackfromNotifyScr()
**purpose: to handle the disconnect message of slave call
**there are lots of case to be handle. 

*********************************************************************/
void MTPNP_PFAL_CC_GoBackfromNotifyScr(void)
{
    StopTimer(MTPNP_NOTIFYDURATION_TIMER);
    GoBackfromNotifyScr();
}

void MTPNP_PFAL_CC_EntryScrMarkerError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* guiBuffer; */

    EntryNewScreen(CM_SCR_MARKER, NULL, NULL, NULL);

    // guiBuffer = GetCurrGuiBuffer(CM_SCR_MARKER); /* Getting the Index from history  */

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    StartTimer(MTPNP_NOTIFYDURATION_TIMER, 1, MTPNP_PFAL_CC_GoBackfromNotifyScr);
}
void MTPNP_PFAL_AddCCMarkerToHistory(void)
{
    if (IsScreenPresent(CM_SCR_MARKER) != TRUE)
    {
        EntryNewScreen(CM_SCR_MARKER, NULL, MTPNP_PFAL_CC_EntryScrMarkerError, NULL);
    }
}

void MTPNP_PFAL_CC_SetMOCallFunc(FuncPtr funcname)
{
    mmi_ucm_set_sendkey_hdlr(funcname);
}

FuncPtr MTPNP_PFAL_CC_GetMOCallFunc(void)
{
    return mmi_ucm_get_sendkey_hdlr();
}

void MTPNP_PFAL_CC_ExeMOCallFunc(void)
{
    mmi_ucm_exec_sendkey_hdlr();
}

/*****************************************************
**function MTPNP_PFAL_CC_EntryMOSelectionScreen
**to sendkey1&sendkey2 function is to make a GSM call
******************************************************/
void MTPNP_PFAL_CC_EntryMOSelectionScreen(void)
{
    U16 nStrItemList[2];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;             /* Stores no of children in the submenu */
    U8 *guiBuffer;              /* Buffer holding history data */
    MTPNP_BOOL isShowOption;
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_EntryMOSelectionScreen");

    EntryNewScreen(SLAVE_SCR_CC_MO_SELECT_NET, NULL, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SLAVE_SCR_CC_MO_SELECT_NET);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(SLAVE_MENU_CC_MO_SELETECT_NET);

    /* 4. Get attribute of menu to be displayed */
//      nDispAttribute = GetDispAttributeOfItem(MENU8234_FDL_VIEW_OPTIONS_MAIN  );
    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(SLAVE_MENU_CC_MO_SELETECT_NET, nStrItemList);
    //GetSequenceImageIds(SLAVE_MENU_CC_MO_SELETECT_NET     , nImageItemList);

    /* 6 Set current parent id */
    SetParentHandler(SLAVE_MENU_CC_MO_SELETECT_NET);
    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* 8 Display Category15 Screen */
    ShowCategory15Screen(SLAVE_STR_CC_MO_SELETECT_SELECT_NET, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

//LIJUNZHAO_ADD_080416:Begin
MTPNP_BOOL MTPNP_CC_GetDualSendKeySupport(void)
{
#ifdef __SENDKEY2_SUPPORT__
    return MTPNP_TRUE;
#else /* __SENDKEY2_SUPPORT__ */
    return MTPNP_FALSE;
#endif /* __SENDKEY2_SUPPORT__ */
}

MTPNP_BOOL MTPNP_CC_ISLSKSendInOne(void)
{
#ifdef __LSK_KEYSEND2_IN_ONE__
       return MTPNP_TRUE;
#else  /* __LSK_KEYSEND2_IN_ONE__ */
       return MTPNP_FALSE;
#endif  /* __LSK_KEYSEND2_IN_ONE__ */
}
//LIJUNZHAO_ADD_080416:End

/*****************************************************
**function MTPNP_PFAL_CC_Send1KeyHandler
**to handle sendkey1 when it's function is to make a GSM call
******************************************************/
void MTPNP_PFAL_CC_SendKey1Handler(void)
{

    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey1Handler MO_CALL_FUNCTION=%x", MTPNP_PFAL_CC_GetMOCallFunc());

    if (NULL == MTPNP_PFAL_CC_GetMOCallFunc())
    {
        kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey1Handler NO MO_CALL_FUNCTION ");
        return;
    }

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_bootup_get_active_flight_mode())
    {
        kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey1Handler Flight mode ");
        return;
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

    //to make GSM call through Master Net
    
    //if (MTPNP_TRUE == MTPNP_AD_GetDualSendKeySupport() ||MTPNP_TRUE == MTPNP_AD_ISLSKSendInOne())
    if (MTPNP_TRUE == MTPNP_CC_GetDualSendKeySupport() ||MTPNP_TRUE == MTPNP_CC_ISLSKSendInOne()) //LIJUNZHAO_MODIFIED_080416
    {
    #ifdef __LSK_KEYSEND2_IN_ONE__
        MTPNP_PFAL_CC_SetDialFromLSK(MTPNP_FALSE);
        if(!MTPNP_PFAL_CC_IsDialFromLSK())
    #endif  /* __LSK_KEYSEND2_IN_ONE__ */
        {
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
    	}
   #ifdef __LSK_KEYSEND2_IN_ONE__
        //MTPNP_PFAL_CC_SetDialFromLSK(MTPNP_FALSE);
   #endif  /* __LSK_KEYSEND2_IN_ONE__ */

        MTPNP_PFAL_CC_ExeMOCallFunc();
    }
    else
    {

    #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
	    switch (mmi_netset_get_active_preferred_mode())
	    {
	        case P_WLAN_ONLY:
            case P_WLAN_PREFERRED:
                MTPNP_PFAL_CC_ExeMOCallFunc();
                return;
                
            break;

            case P_GSM_PREFERRED:
            case P_GSM_ONLY:
            default: 
            {
                /* do nothing */
            }
            break;
        }
    #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
    
        if (MTPNP_AD_DUALSIM_USABLE == MTPNP_AD_Get_UsableSide())
        {                   
            if (GetExitScrnID()== IDLE_SCREEN_DIGIT_HANDLER_ID)
            {
                if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
                {
                    mmi_ucm_entry_dial_option_by_sendkey();
                }
            }
            else if (GetExitScrnID()== SCR_ID_UCM_DTMF_EDITOR)
            {
                S32 unicodeLen = 0;
                
                unicodeLen = (MMI_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((S8*)g_ucm_p->call_misc.disp_dtmf)) ? 
                                (mmi_ucs2strlen((S8*)g_ucm_p->call_misc.disp_dtmf)) : (MMI_UCM_MAX_NUM_URI_LEN - 1);
                
                memset(g_ucm_p->mo_info.dial_num.num_uri, 0, MMI_UCM_MAX_NUM_URI_LEN);
                mmi_ucs2_n_to_asc((S8*)g_ucm_p->mo_info.dial_num.num_uri, (S8*)g_ucm_p->call_misc.disp_dtmf, unicodeLen * ENCODING_LENGTH);
                    
                if (!mmi_ucm_is_crss(MMI_UCM_VOICE_CALL_TYPE_ALL, (U8*)g_ucm_p->mo_info.dial_num.num_uri))
                {
                    mmi_ucm_entry_dial_option_by_sendkey();
                }
            }
            else
            {
                mmi_ucm_entry_dial_option_by_sendkey();
            }
        }
        else if (MTPNP_AD_SIMCARD1_USABLE == MTPNP_AD_Get_UsableSide())
        {
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
            MTPNP_PFAL_CC_ExeMOCallFunc();
        }
        else if (MTPNP_AD_SIMCARD2_USABLE == MTPNP_AD_Get_UsableSide())
        {
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
            MTPNP_PFAL_CC_ExeMOCallFunc();
        }
        else
        {
            /* no SIM to dial */
            switch(MTPNP_AD_Get_Startup_Mode())
            {
                case MTPNP_AD_NVRAM_CARD1:
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                break;

                case MTPNP_AD_NVRAM_CARD2:
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
                break;

                case MTPNP_AD_NVRAM_DUALCARD:
                    if (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
                    {
                        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
                    }
                    else
                    {
                        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                    }
                break;

                /* UCM should do the error handling for flight mode */
                default:
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                break;
            }

            MTPNP_PFAL_CC_ExeMOCallFunc();

            kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey1Handler you can not makecall");
            return;
        }
    }

}

#if defined(__SENDKEY2_SUPPORT__)||defined(__MMI_KEY_ENTER_TO_KEY_SEND2__) || defined(__LSK_KEYSEND2_IN_ONE__)
/*****************************************************
**function MTPNP_PFAL_CC_SendKey2Handler
**to handle sendkey2 when it's function is to make a GSM call
******************************************************/
void MTPNP_PFAL_CC_SendKey2Handler(void)
{
    //to make GSM call through Slave Net    
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey2Handler MO_CALL_FUNCTION=%x", MTPNP_PFAL_CC_GetMOCallFunc());
    if (0 != MTPNP_PFAL_CC_GetMOCallFunc())
    {
        MTPNP_PFAL_CC_ExeMOCallFunc();
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_SendKey2Handler NO MO_CALL_FUNCTION ");
    }
}
#endif

/*maintain LSK and KEY_SEND2 in common*/
#ifdef __LSK_KEYSEND2_IN_ONE__
MTPNP_BOOL MTPNP_PFAL_CC_GetIsKeyForCall(void)
{
    return mtpnpIsForCall;
}

void MTPNP_PFAL_CC_SetIsKeyForCall(MTPNP_BOOL forcall)
{
    mtpnpIsForCall = forcall;
}

MTPNP_BOOL MTPNP_PFAL_CC_IsDialFromLSK(void)
{
    return mtpnpDialFromLSK;
}

void MTPNP_PFAL_CC_SetDialFromLSK(MTPNP_BOOL isTorF)
{
    mtpnpDialFromLSK = isTorF;
}

MTPNP_UINT16 MTPNP_PFAL_CC_GetSendEventType(void)
{
    return mtpnpsendkeytype;
}

/**************************************************************

	FUNCTION NAME		: MTPNP_PFAL_CC_RegShareKeyHandler(mmi_key_types_enum sendkeytype)
  	PURPOSE				: 
	INPUT PARAMETERS	: FuncPtr sendhandle,FuncPtr LSKhandle
	OUTPUT PARAMETERS	: nil
	RETURNS				: void
  	Author				: 
	REMARKS			:  

**************************************************************/
void MTPNP_PFAL_CC_RegShareKeyHandler(mmi_key_types_enum sendkeytype)
{
    MTPNP_PFAL_CC_SetIsKeyForCall(MTPNP_TRUE);
    mtpnpsendkeytype = sendkeytype;
}
#endif /*__LSK_KEYSEND2_IN_ONE__*/
/*maintain LSK and KEY_SEND2 in common*/

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
void MTPNP_PFAL_CC_SetCenterFunc(FuncPtr cenfunc)
{
    mmi_ucm_set_centerkey_hdlr(cenfunc);
}

FuncPtr MTPNP_PFAL_CC_GetCenterFunc(void)
{
    return mmi_ucm_get_centerkey_hdlr();
}

void MTPNP_PFAL_CC_ExeCenterFunc(void)
{
    mmi_ucm_exec_centerkey_hdlr();
}

void MTPNP_PFAL_CC_CSKHandler(void)
{
    if (MTPNP_AD_DUALSIM_USABLE == MTPNP_AD_Get_UsableSide())
    {
        mmi_ucm_entry_dial_option_by_centerkey();
    }
    else if (MTPNP_AD_SIMCARD1_USABLE == MTPNP_AD_Get_UsableSide())
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);

        if (MTPNP_PFAL_CC_GetCenterFunc() != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_ExeCenterFunc();
        }
    }
    else if (MTPNP_AD_SIMCARD2_USABLE == MTPNP_AD_Get_UsableSide())
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);

        if (MTPNP_PFAL_CC_GetCenterFunc() != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_ExeCenterFunc();
        }
    }
    /* UCM should do the error handling for flight mode */
    else
    {
         /* no SIM to dial */
        switch(MTPNP_AD_Get_Startup_Mode())
        {
            case MTPNP_AD_NVRAM_CARD1:
                MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            break;

            case MTPNP_AD_NVRAM_CARD2:
                MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
            break;

            case MTPNP_AD_NVRAM_DUALCARD:
                if (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
                {
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
                }
                else
                {
                    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
                }
            break;

            /* UCM should do the error handling for flight mode */
            default:
                MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            break;
        }
 
        if (MTPNP_PFAL_CC_GetCenterFunc() != MTPNP_NULL)
        {
            MTPNP_PFAL_CC_ExeCenterFunc();
        }
    }
}

void MTPNP_PFAL_CC_CSKSelectScreen(void)
{
    U16 nStrItemList[2];
    U16 nNumofItem;
    U8 *guiBuffer;
    MTPNP_BOOL isShowOption;
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_CSKSelectScreen");

    EntryNewScreen(SLAVE_SCR_CC_CSK_SELECT_NET, NULL, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SLAVE_SCR_CC_CSK_SELECT_NET);

    nNumofItem = GetNumOfChild(SLAVE_MENU_CC_CSK_SELETECT_CARD);

    GetSequenceStringIds(SLAVE_MENU_CC_CSK_SELETECT_CARD, nStrItemList);

    SetParentHandler(SLAVE_MENU_CC_CSK_SELETECT_CARD);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(SLAVE_STR_CC_CSK_SELECT_NET, 0,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (PU16) gIndexIconsImageList, LIST_MENU, 0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

/*****************************************************
**function MTPNP_PFAL_CC_HandleSendKeys
input:newCallFunc current key_send 
******************************************************/
void MTPNP_PFAL_CC_HandleSendKeys(FuncPtr newCallFunc, mmi_key_types_enum keyevent)
{
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_HandleSendKeys newCallFunc=%x", newCallFunc);
    MTPNP_PFAL_CC_SetMOCallFunc(newCallFunc);
    SetKeyHandler(MTPNP_PFAL_CC_SendKey1Handler, KEY_SEND, keyevent);
#ifdef __SENDKEY2_SUPPORT__
    SetKeyHandler(MTPNP_PFAL_CC_SendKey2Handler, KEY_SEND2, keyevent);
#endif /* __SENDKEY2_SUPPORT__ */
#ifdef __LSK_KEYSEND2_IN_ONE__
	/*Georgezhou 2008.8.15*/
		MTPNP_PFAL_CC_RegShareKeyHandler(KEY_EVENT_DOWN);
#endif/*__LSK_KEYSEND2_IN_ONE__*/
#ifdef __MMI_KEY_ENTER_TO_KEY_SEND2__
    SetKeyHandler(MTPNP_PFAL_CC_SendKey2Handler, KEY_ENTER, keyevent);
#endif
}

void MTPNP_PFAL_CC_HiliteNetSelectCard1(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_ExeMOCallFunc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CC_HiliteNetSelectCard2(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_ExeMOCallFunc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CC_InitEntrySelectSendkey(void)
{
    SetHiliteHandler(SLAVE_MENU_CC_MO_SELETECT_NET_CARD1, MTPNP_PFAL_CC_HiliteNetSelectCard1);
    SetHiliteHandler(SLAVE_MENU_CC_MO_SELETECT_NET_CARD2, MTPNP_PFAL_CC_HiliteNetSelectCard2);
}

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
void MTPNP_PFAL_CC_InitCSKSelectCard(void)
{
    SetHiliteHandler(SLAVE_MENU_CC_CSK_SELETECT_CARD1, MTPNP_PFAL_CSK_HiliteSelectCard1);
    SetHiliteHandler(SLAVE_MENU_CC_CSK_SELETECT_CARD2, MTPNP_PFAL_CSK_HiliteSelectCard2);
}

void MTPNP_PFAL_CSK_HiliteSelectCard1(void)
{
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_CSKDialCard1, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CSK_HiliteSelectCard2(void)
{
    SetLeftSoftkeyFunction(MTPNP_PFAL_CC_CSKDialCard2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void MTPNP_PFAL_CC_CSKDialCard1(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
    MTPNP_PFAL_CC_ExeCenterFunc();
}

void MTPNP_PFAL_CC_CSKDialCard2(void)
{
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    MTPNP_PFAL_CC_ExeCenterFunc();
}
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */

MTPNP_BOOL Slave_IsBlockSlaveIncoming(void)
{
    return MTPNP_FALSE;
}

/**************************************************************

	FUNCTION NAME		: MTPNP_PFAL_CC_IsMasterCCInIdle(void)

  	PURPOSE				: This function is called to return if the master in idle or not

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: MTPNP_TRUE/MTPNP_FALSE

	REMARKS				: nil

**************************************************************/
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInIdle(void)
{
    #ifdef __MMI_UCM__
        if(MTPNP_PFAL_CC_IsMasterCCInOutgoing())
            {
                return MTPNP_FALSE;
            }
        else if(MTPNP_PFAL_CC_IsMasterCCInIncoming())
            {
                return MTPNP_FALSE;
           }
        else if(MTPNP_PFAL_CC_IsMasterCCInAcitveOrHold())
            {
                return MTPNP_FALSE;
            }
        else 
            {
                return MTPNP_TRUE;
            }
    #else /* __MMI_UCM__ */
        if (cm_p->state_info.TotalCallCount == 0)
            return MTPNP_TRUE;
        else
            return MTPNP_FALSE;
    #endif /* __MMI_UCM__ */

}

/**************************************************************

	FUNCTION NAME		: MTPNP_PFAL_CC_IsMasterCCInOutgoing(void)

  	PURPOSE				: This function is called to return if the master in outgoing or not

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: MTPNP_TRUE/MTPNP_FALSE

	REMARKS				: nil

**************************************************************/
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInOutgoing(void)
{
    #ifdef __MMI_UCM__
        mmi_ucm_call_type_enum type=MMI_UCM_CALL_TYPE_NO_SIM2;
        if (mmi_ucm_get_outgoing_group(type, g_ucm_p->call_misc.index_list) > 0)
            {
                return MTPNP_TRUE;
            }
        else
                return MTPNP_FALSE;
    #else /* __MMI_UCM__ */
        MTPNP_UINT16 i;
        for (i = 0; i < MAX_CALLS; i++)
        {
            if (cm_p->state_info.AllCalls[i].curr_state == CM_OUTGOING_STATE ||
                (cm_p->state_info.AllCalls[i].prev_state == CM_OUTGOING_STATE &&
                 cm_p->state_info.AllCalls[i].curr_state == CM_DISCONNECTING_STATE))
                return MTPNP_TRUE;
        }
        return MTPNP_FALSE;
    #endif /* __MMI_UCM__ */
}

/**************************************************************

	FUNCTION NAME		: MTPNP_PFAL_CC_IsMasterCCInIncoming(void)

  	PURPOSE				: This function is called to return if the master in incoming or not

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: MTPNP_TRUE/MTPNP_FALSE

	REMARKS				: nil

**************************************************************/
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInIncoming(void)
{
    #ifdef __MMI_UCM__
        MTPNP_INT32 masterincallCount;
        masterincallCount =(MTPNP_INT32) (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_NO_SIM2, g_ucm_p->call_misc.index_list));
        if(masterincallCount>0)
            return MTPNP_TRUE;
        else
            return MTPNP_FALSE;
    #else /* __MMI_UCM__ */
        MTPNP_UINT16 i;
        for (i = 0; i < MAX_CALLS; i++)
        {
            if (cm_p->state_info.AllCalls[i].curr_state == CM_INCOMING_STATE ||
                (cm_p->state_info.AllCalls[i].prev_state == CM_INCOMING_STATE &&
                 cm_p->state_info.AllCalls[i].curr_state == CM_DISCONNECTING_STATE))
                return MTPNP_TRUE;
        }
        return MTPNP_FALSE;
    #endif /* __MMI_UCM__ */
}

/**************************************************************

	FUNCTION NAME		: MTPNP_PFAL_CC_IsMasterCCInAcitveOrHold(void)

  	PURPOSE				: This function is called to return if the master in AcitveOrHold or not

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: MTPNP_TRUE/MTPNP_FALSE

	REMARKS				: nil

**************************************************************/
MTPNP_BOOL MTPNP_PFAL_CC_IsMasterCCInAcitveOrHold(void)
{

    #ifdef __MMI_UCM__
        MTPNP_INT32 masterincallCount;
        masterincallCount =(MTPNP_INT32) (mmi_ucm_get_active_group(MMI_UCM_CALL_TYPE_NO_SIM2, FALSE, g_ucm_p->call_misc.index_list)+\
                    mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_NO_SIM2, FALSE, g_ucm_p->call_misc.index_list));
        if(masterincallCount>0)
            return MTPNP_TRUE;
        else
            return MTPNP_FALSE;
    #else /* __MMI_UCM__ */
        MTPNP_UINT16 i;
        for (i = 0; i < MAX_CALLS; i++)
        {
            if ((cm_p->state_info.AllCalls[i].curr_state == CM_ACTIVE_STATE) ||
                (cm_p->state_info.AllCalls[i].curr_state == CM_HOLD_STATE))
                return MTPNP_TRUE;
        }
        return MTPNP_FALSE;
    #endif /* __MMI_UCM__ */
}

//#if defined ( __MERCURY_MASTER__)&& !defined (__MERCURY_GEMINI__)
#if defined ( __MMI_DUAL_SIM_DUAL_CALL__)&& defined (__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */

void MTPNP_PFAL_SetCMPhoneBookStruct(PHB_CM_INTERFACE * pNumberStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&mtpnp_phonenumstruct, pNumberStruct, sizeof(PHB_CM_INTERFACE));
}

PHB_CM_INTERFACE *MTPNP_PFAL_GetCMPhoneBookStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &mtpnp_phonenumstruct;
}

void MTPNP_PFAL_CC_EntryScrNotifyCHLDSucess(U16 notify_string, pBOOL play_tone)
{
    EntryNewScreen(SCR1010_CM_DISPSPLITCALLSUCESS, NULL, NULL, NULL);
#ifndef __MMI_CM_SHOW_CHLD_DONE__
    ShowCategory62Screen(notify_string, IMG_GLOBAL_ACTIVATED, NULL);
#else
    ShowCategory62Screen(STR_ACTION_DONE, IMAGE_CCBS_ACTIVATED, NULL);
#endif
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeysForPOPUp();
    SetPOPUpFlag(TRUE);
    StartTimer(CM_NOTIFYDURATION_TIMER, CM_NOTIFY_TIMEOUT, GoBackHistory);
}
//#if defined ( __MERCURY_MASTER__)&& !defined (__MERCURY_GEMINI__)
#if defined ( __MMI_DUAL_SIM_DUAL_CALL__)&& defined (__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifdef __MMI_DUAL_SIM_MASTER__ */

void MTPNP_PFAL_CC_ShowScrError(void)
{
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);
    DeleteScreenIfPresent(SCR_CM_REQUESTINGUSSD);
    GoBackHistory();
    DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
}

void MTPNP_PFAL_DropCFTMOCall(void)
{
    CM_CALL_HANDLE callHandler;
    callHandler = GetOutgoingCallHandle();
    if (-1 != callHandler)      //has valid outgoing call ID
    {
#ifdef __MMI_UCM__

#else
        DropRequest();
#endif
    }
#ifdef __MMI_VOIP__
    callHandler = mmi_voip_get_outgoing_call_id();
    if (-1 != callHandler)      //has valid voip outgoing call ID
    {
#ifdef __MMI_UCM__

#else

#endif
    }
#endif
}

#if defined ( __MMI_DUAL_SIM_DUAL_CALL__)&& defined (__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UCM__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UCM__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_UCM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined ( __MMI_DUAL_SIM_DUAL_CALL__)&& defined (__MMI_DUAL_SIM_MASTER__) */

void MTPNP_PFAL_CC_DoPlayConnetTone(void)
{
    MTPNP_AD_CC_SlavePlayConnectTone(2);
}

void MTPNP_PFAL_CC_DoPlayCRTTone(void)
{
    MTPNP_AD_CC_SlavePlayConnectTone(25);
}

U16 MTPNP_PFAL_CC_GetDGTotalCallCount(void)
{
#ifdef __MMI_UCM__
    U16 totalCallcount = (U16) (mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE) + MTPNP_AD_CC_GetTotalCallCount());
#else /* __MMI_UCM__ */
    U16 totalCallcount = (U16) (GetTotalCallCount() + MTPNP_AD_CC_GetTotalCallCount());
#endif /* __MMI_UCM__ */

    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_GetDGTotalCallCount totalCallcount=%x", totalCallcount);

    return totalCallcount;
}

U16 MTPNP_PFAL_CC_GetDGTotalActiveAndHoldCallCount(void)
{
    return (U16) (cm_p->state_info.NumofActivecalls + cm_p->state_info.NumofHeldcalls
                  + MTPNP_AD_CC_GetTotalActiveAndHoldCallCount());
}

void MTPNP_PFAL_CC_ShowSwapSucess(void)
{
#ifndef __MMI_UCM__
    if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0 && MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_SWAP, FALSE);
    else if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0)
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_RTVD, FALSE);
    else if (MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
        EntryScrNotifyCHLDSucess(STR_NFY_CALL_HLD, TRUE);
#else
    void *msg = MTPNP_NULL;
    MTPNP_PFAL_CC_UCMShowSwapSucess(msg);
#endif
}

void MTPNP_PFAL_CC_ShowConfSucess(void)
{
#ifndef __MMI_UCM__
    EntryScrNotifyCHLDSucess(STR_NFY_CALL_CONF, FALSE);
#else
    void *msg = MTPNP_NULL;
    MTPNP_PFAL_CC_UCMShowConfSucess(msg);
#endif
}

void MTPNP_PFAL_CC_ShowSplitSucess(void)
{
#ifndef __MMI_UCM__
    EntryScrNotifyCHLDSucess(STR_NFY_CALL_SPLIT, FALSE);
#else
    void *msg = MTPNP_NULL;
    MTPNP_PFAL_CC_UCMShowSplitSucess(msg);
#endif
}

void MTPNP_PFAL_CC_RefreshCurWin(void)
{
    if (GetActiveScreenId() != SCR_CM_ACTIVECALLSCREEN)
        return;
    // to refresh SCR_CM_ACTIVECALLSCREEN screen
    EntryScr1002ActiveCall();
}

void MTPNP_PFAL_CC_USSD_Abort_Rsp(ST_MTPNP_AD_CC_RESULT * msgbuf)
{
    if (0 != USSD_ABORT_RSP)
    {
        USSD_ABORT_RSP(msgbuf);
    }
}

void MTPNP_PFAL_CC_USSN_IND(ST_MTPNP_AD_CC_USSN_IND * msgbuf)
{

    MTPNP_PFAL_DeriveUSSDData(msgbuf->dcs, msgbuf->ussd_string);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);

    if (IsScreenPresent(SCR_CARD2_CM_REQUESTINGUSSD))
    {
        HistoryReplace(SCR_CARD2_CM_REQUESTINGUSSD, SCR_CARD2_USSN_MSG, MTPNP_PFAL_EntryScrDisplayUSSNMsg);
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);
    }
    else
    {
        MTPNP_PFAL_EntryScrDisplayUSSNMsg();
#ifdef __MMI_RECEIVE_USSD_TONE__
        MuteOnMicrophone();
        playRequestedTone(WARNING_TONE);
        if (IsPhoneInMute() == MMI_FALSE)
        {
            MuteOffMicrophone();
        }
#endif
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryScrDisplayUSSNMsg
 * DESCRIPTION
 *  This function is the entry screen for displaying USSN info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_EntryScrDisplayUSSNMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history ss_scr;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);

    if (MTPNP_AD_CC_IsSlaveCCInIncoming() == MTPNP_TRUE || MTPNP_AD_CC_IsSlaveCCInOutgoing() == MTPNP_TRUE)
    {
        TurnOnBacklight(TRUE);
        EntryNewScreen(POPUP_SCREENID, ExitDisplayPopup, NULL, NULL);

        MTPNP_PFAL_RemoveSSReqScr();

        ss_scr.scrnID = SCR_CARD2_USSN_MSG;
        ss_scr.entryFuncPtr = MTPNP_PFAL_EntryScrDisplayUSSNMsg;
        mmi_ucs2cpy((S8 *) ss_scr.inputBuffer, (S8 *) & nHistory);
        InsertHistoryBeforeThisScrnReference(CM_SCR_MARKER, &ss_scr);

        ShowCategory74Screen(STR_TITLE_SCR_USSN_MSG,
                             0,
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);
        SetGroupKeyHandler(PopupTimerFlagEnable, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(PopupCloseByPressAnyKey, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
        StartTimer(POPUP_TIMER, 1000, PopupTimerOver);
    }
    else
    {
        EntryNewScreen(SCR_CARD2_USSN_MSG, NULL, MTPNP_PFAL_EntryScrDisplayUSSNMsg, NULL);

        if (isInCall())
        {
            SetCMScrnFlag(MMI_FALSE);
        }

        MTPNP_PFAL_RemoveSSReqScr();

        ShowCategory74Screen(STR_TITLE_SCR_USSN_MSG,
                             0,
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);

        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);

        TurnOnBacklight(1);
        SetLeftSoftkeyFunction(MTPNP_PFAL_MMIUSSNReceiveOK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(MTPNP_PFAL_MMIUSSNReceiveOK, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_MMIUSSNReceiveOK, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);
    }
}
void MTPNP_PFAL_MMIUSSNReceiveOK(void)
{
    ClearDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, NULL);
    if (isInCall())
    {
        SetCMScrnFlag(MMI_FALSE);
    }
    GoBackHistory();
}


void MTPNP_PFAL_CC_USSD_Rsp(ST_MTPNP_AD_CC_USSD_RSP * msgbuf)
{
            /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USSD_GOBACK_IDLE__
    if (((ST_MTPNP_AD_CC_USSD_RSP *) msgbuf)->op_code == SS_OP_UNSTRUCTUREDSS_REQUEST)
    {
        MTPNP_PFAL_RemoveSSReqScr();
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
        DeleteScreenIfPresent(SCR_CARD2_USSR_EDIT);
        GoBackHistory();
        return;
    }
#endif

    if (((ST_MTPNP_AD_CC_USSD_RSP *) msgbuf)->result.flag == L4C_OK)
    {
        MTPNP_PFAL_DeriveUSSDData(msgbuf->dcs, msgbuf->ussd_string);

        if (IsScreenPresent(SCR_CARD2_CM_REQUESTINGUSSD))
        {
            HistoryReplace(SCR_CARD2_CM_REQUESTINGUSSD, SCR_CARD2_USSN_MSG, MTPNP_PFAL_EntryScrDisplayUSSDRes);
            return;
        }
        else
        {
            MTPNP_PFAL_EntryScrDisplayUSSDRes();
#ifdef __MMI_RECEIVE_USSD_TONE__
            MuteOnMicrophone();
            playRequestedTone(WARNING_TONE);
            if (IsPhoneInMute() == MMI_FALSE)
            {
                MuteOffMicrophone();
            }
#endif
        }
    }
    else
    {
        if (((MTPNP_AD_CC_IsSlaveCCInIncoming() != MTPNP_TRUE) && (MTPNP_AD_CC_IsSlaveCCInOutgoing() != MTPNP_TRUE)) ||
            (GetActiveScreenId() == SCR_CARD2_CM_REQUESTINGUSSD))
        {
#ifdef __MMI_SS_SHOW_CAUSE__
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            MTPNP_PFAL_RemoveSSReqScr();
            ShowCauseString(((MMI_SS_USSD_RSP *) msgbuf)->result.cause, temp_string);
            ShowCategory74Screen(STR_TITLE_SCR_USSD_MSG,
                                 0,
                                 STR_GLOBAL_OK,
                                 IMG_GLOBAL_OK, 0, 0, (PU8) temp_string, mmi_ucs2strlen(temp_string), NULL);
            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#else /* __MMI_SS_SHOW_CAUSE__ */
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            MTPNP_PFAL_RemoveSSReqScr();
#endif /* __MMI_SS_SHOW_CAUSE__ */
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
            MTPNP_PFAL_RemoveSSReqScr();
        }

    }

    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
    DeleteScreenIfPresent(SCR_CARD2_USSR_EDIT);
    DeleteScreenIfPresent(SCR_SYMBOL_PICKER_SCREEN);
}



/*****************************************************************************
 * FUNCTION
 *  EntryScrDisplayUSSDRes
 * DESCRIPTION
 *  This function is the entry screen for displaying USSN info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_EntryScrDisplayUSSDRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history ss_scr;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);

    if ((MTPNP_AD_CC_IsSlaveCCInIncoming() == MTPNP_TRUE) || (MTPNP_AD_CC_IsSlaveCCInOutgoing() == MTPNP_TRUE))
    {
        TurnOnBacklight(TRUE);
        EntryNewScreen(POPUP_SCREENID, ExitDisplayPopup, NULL, NULL);

        MTPNP_PFAL_RemoveSSReqScr();

        ss_scr.scrnID = SCR_CARD2_USSN_MSG;
        ss_scr.entryFuncPtr = MTPNP_PFAL_EntryScrDisplayUSSDRes;
        mmi_ucs2cpy((S8 *) ss_scr.inputBuffer, (S8 *) & nHistory);
        InsertHistoryBeforeThisScrnReference(CM_SCR_MARKER, &ss_scr);

        ShowCategory74Screen(STR_TITLE_SCR_USSD_MSG,
                             0,
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             0, 0, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);

        SetGroupKeyHandler(PopupTimerFlagEnable, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(PopupCloseByPressAnyKey, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
        StartTimer(POPUP_TIMER, 1000, PopupTimerOver);
    }
    else
    {
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
        EntryNewScreen(SCR_CARD2_USSN_MSG, NULL, MTPNP_PFAL_EntryScrDisplayUSSDRes, NULL);

        MTPNP_PFAL_RemoveSSReqScr();

        ShowCategory74Screen(STR_TITLE_SCR_USSD_MSG,
                             0,
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             0, 0, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);

        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}

#ifdef __MMI_USSR_TIMER__
/*****************************************************************************
 * FUNCTION
 *  GSM2_USSRTimeout
 * DESCRIPTION
 *  This function is called when USSR is timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_USSRTimeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(USSR_SESSION_TIMER);
    if (IsScreenPresent(SCR_CARD2_USSN_MSG) || GetExitScrnID() == SCR_CARD2_USSN_MSG)
    {
        MTPNP_PFAL_DropUssd(NULL);
        if (!isInCall())
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION, ERROR_TONE);
        }
        MTPNP_PFAL_RemoveSSReqScr();
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
        DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
        DeleteScreenIfPresent(SCR_CARD2_USSR_EDIT);
    }
}
#endif

void MTPNP_PFAL_RemoveSSReqScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_CARD2_CM_REQUESTINGUSSD, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_CM_REQUESTINGUSSD);
}


void MTPNP_PFAL_DropUssd(PsFuncPtr callback)
{
    USSD_ABORT_RSP = callback;
    MTPNP_AD_CC_DropUSSDReq();

}
void MTPNP_PFAL_EntryScrDisplayUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history ss_scr;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);

    if ((MTPNP_AD_CC_IsSlaveCCInOutgoing() == MTPNP_TRUE) || (MTPNP_AD_CC_IsSlaveCCInIncoming() == MTPNP_TRUE))
    {
        TurnOnBacklight(TRUE);
        EntryNewScreen(POPUP_SCREENID, ExitDisplayPopup, NULL, NULL);

        MTPNP_PFAL_RemoveSSReqScr();

        ss_scr.scrnID = SCR_CARD2_USSN_MSG;
        ss_scr.entryFuncPtr = MTPNP_PFAL_EntryScrDisplayUSSRMsg;
        mmi_ucs2cpy((S8 *) ss_scr.inputBuffer, (S8 *) & nHistory);
        InsertHistoryBeforeThisScrnReference(CM_SCR_MARKER, &ss_scr);
        ShowCategory74Screen(STR_TITLE_SCR_USSR_MSG,
                             0,
                             STR_GLOBAL_REPLY,
                             0,
                             STR_GLOBAL_CANCEL,
                             0, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);
        SetGroupKeyHandler(PopupTimerFlagEnable, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(PopupCloseByPressAnyKey, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
        StartTimer(POPUP_TIMER, 1000, PopupTimerOver);
    }
    else
    {
        EntryNewScreen(SCR_CARD2_USSN_MSG, NULL, MTPNP_PFAL_EntryScrDisplayUSSRMsg, NULL);

        MTPNP_PFAL_RemoveSSReqScr();

        ShowCategory74Screen(STR_TITLE_SCR_USSR_MSG,
                             0,
                             STR_GLOBAL_REPLY,
                             0,
                             STR_GLOBAL_CANCEL,
                             0, (PU8) MTPNP_PFAL_gUSSDbuf, mmi_ucs2strlen(MTPNP_PFAL_gUSSDbuf), NULL);

        TurnOnBacklight(1);

        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);

        SetRightSoftkeyFunction(MTPNP_PFAL_AbortUSSDResultRequest, KEY_EVENT_UP);
        SetKeyHandler(MTPNP_PFAL_AbortUSSDResultRequestEND, KEY_END, KEY_EVENT_DOWN);

        SetLeftSoftkeyFunction(MTPNP_PFAL_EntryScrEditUSSRMsg, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);
    }
}

void MTPNP_PFAL_AbortUSSDResultRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    ClearExitHandler();
    MTPNP_PFAL_DropUssd(MTPNP_PFAL_CBackDropUSSDReq);
}



/*****************************************************************************
 * FUNCTION
 *  CBackDropUSSDReq
 * DESCRIPTION
 *  Aborts SS string request
 * PARAMETERS
 *  info            [?]         
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_CBackDropUSSDReq(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((ST_MTPNP_AD_CC_RESULT *) (info))->flag == TRUE)
    {
        GoBackHistory();
    }
    else
    {
#ifndef __MMI_UCM__
        ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE);
#else

#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  AbortUSSDResultRequestEND
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_AbortUSSDResultRequestEND(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall())
    {
        HangupAllCalls();
        return;
    }
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
    ClearExitHandler();
    MTPNP_PFAL_DropUssd(MTPNP_PFAL_CBackDropUSSDReqEND);
}


/*****************************************************************************
 * FUNCTION
 *  CBackDropUSSDReqEND
 * DESCRIPTION
 *  Aborts SS string request on END Key
 * PARAMETERS
 *  info            [?]         
 *  callback(?)     [IN]        To register with response
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_CBackDropUSSDReqEND(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((ST_MTPNP_AD_CC_RESULT *) (info))->flag == TRUE)
    {
        if (isInCall())
        {
            GoBackHistory();
        }
        else
        {
            DisplayIdleScreen();
        }
    }
    else
    {
#ifndef __MMI_UCM__
        ShowCallManagementErrorMessage(ERR_L4C_GEN_CAUSE);
#else

#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEditUSSRMsg
 * DESCRIPTION
 *  This function is the entry screen for Editing USSR info by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_EntryScrEditUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CARD2_USSR_EDIT, NULL, MTPNP_PFAL_EntryScrEditUSSRMsg, NULL);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);

    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
    guiBuffer = GetCurrGuiBuffer(SCR_CARD2_USSR_EDIT);

    if (guiBuffer == NULL)
    {
        memset(g_callset_context.SSCFNum, 0, (MAX_CC_ADDR_LEN * ENCODING_LENGTH) + 2);
    }
    RegisterInputBoxValidationFunction(RegisterUSSRMsgKeyFunction);
    ShowCategory5Screen(STR_TITLE_SCR_USSR_EDIT_MSG,
                        0,
                        STR_GLOBAL_OK,
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        (S16) (INPUT_TYPE_KEYPAD_NUMERIC | INPUT_TYPE_ALPHANUMERIC_UPPERCASE |
                               INPUT_TYPE_USE_ONLY_ENGLISH_MODES), (U8 *) g_callset_context.SSCFNum, MAX_CC_ADDR_LEN,
                        guiBuffer);

    SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);

    SetCategory5RightSoftkeyFunction(MTPNP_PFAL_EditUSSRGoBack, KEY_EVENT_UP);
    SetKeyHandler(MTPNP_PFAL_AbortUSSDResultRequestEND, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(MTPNP_PFAL_SendUSSRMsg, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_LONG_PRESS);

    if (mmi_ucs2strlen((S8 *) g_callset_context.SSCFNum) == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
}
void MTPNP_PFAL_EditUSSRGoBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  SendUSSRMsg
 * DESCRIPTION
 *  Sends USSR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_SendUSSRMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 Buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSR_EDIT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_CARD2_USSN_MSG);
    ClearExitHandler();
    ClearDtmfBuf();
    FillDtmfBuff((PU8) g_callset_context.SSCFNum);
    Buf = GetDtmfBuffer();
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
#ifdef __MMI_UCM__
    MakeMyCall((PS8) Buf, CSMCC_VOICE_CALL);
#else  /* __MMI_UCM__ */
    MakeMyCall((PS8) Buf);
#endif  /* __MMI_UCM__ */
}

/*****************************************************************************
 * FUNCTION
 *  DeriveUSSDData
 * DESCRIPTION
 *  Function derives data in USSN, USSR, and USSD messages
 * PARAMETERS
 *  dcs             [IN]        
 *  ussd_string     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void MTPNP_PFAL_DeriveUSSDData(U8 dcs, U8 * ussd_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ussrLen = 0;
    U8 *tempStr = NULL;
    switch (dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dcs = MMI_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dcs = MMI_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dcs = MMI_8BIT_DCS;
        break;
    default:
        kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_USSR_IND error msgbuf->dcs=%x", dcs);
        return;                 //error return
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dcs == MMI_UCS2_DCS)
    {
        ussrLen = (U16) mmi_ucs2strlen((PS8) ussd_string);
        ussrLen = ussrLen * 2;
    }
    else
    {
        ussrLen = strlen((PS8) ussd_string);
    }

    if (ussrLen >= MAX_DIGITS_USSD)
    {
        ussrLen = MAX_DIGITS_USSD - 1;
    }

    tempStr = CovertStringForPlatform(ussd_string, ussrLen, dcs, &ussrLen);

    memset((void *) MTPNP_PFAL_gUSSDbuf, 0, MAX_DIGITS_USSD * ENCODING_LENGTH);

    if (tempStr != NULL)
    {
        MTPNP_PFAL_Unicode_Memory_Copy((PS8) MTPNP_PFAL_gUSSDbuf, (PS8) tempStr, ussrLen);
        OslMfree(tempStr);
    }
    return;
}

void MTPNP_PFAL_CC_USSR_IND(ST_MTPNP_AD_CC_USSR_IND * msgbuf)
{
    MTPNP_PFAL_DeriveUSSDData(msgbuf->dcs, msgbuf->ussd_string);
    SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) NULL);
#ifdef __MMI_USSR_TIMER__
    StartTimer(USSR_SESSION_TIMER, 180000, MTPNP_PFAL_USSRTimeout);     /*Auto expire after 3 mins if network has no action */
#endif
    if (IsScreenPresent(SCR_CARD2_CM_REQUESTINGUSSD))
    {
        HistoryReplace(SCR_CARD2_CM_REQUESTINGUSSD, SCR_CARD2_USSN_MSG, MTPNP_PFAL_EntryScrDisplayUSSRMsg);
        SetDelScrnIDCallbackHandler(SCR_CARD2_USSN_MSG, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);
    }
    else
    {
        MTPNP_PFAL_EntryScrDisplayUSSRMsg();
#ifdef __MMI_RECEIVE_USSD_TONE__        /* for KLM only */
        MuteOnMicrophone();
        playRequestedTone(WARNING_TONE);
        if (IsPhoneInMute() == MMI_FALSE)
        {
            MuteOffMicrophone();
        }
#endif
    }


}
void MTPNP_PFAL_CC_Show_ScrUSSDReq(void)
{
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_Show_ScrUSSDReq");
    EntryNewScreen(SCR_CARD2_CM_REQUESTINGUSSD, NULL, MTPNP_PFAL_CC_Show_ScrUSSDReq, NULL);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NUMBER);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME);
    DeleteScreenIfPresent(SCR_ID_CALLSET_WAITING_MAIN);
    ShowCategory8Screen(STR_TITLE_SCR_USSR_EDIT_MSG_CARD2, IMG_CM_USSD_REQUEST,
                        0, 0, STR_GLOBAL_ABORT, IMG_SCR_USSD_REQ_LSK, STR_USSD_REQ_DISP_SCR, IMG_CM_SS_OUTGOING, NULL);
    SetDelScrnIDCallbackHandler(SCR_CARD2_CM_REQUESTINGUSSD, (HistoryDelCBPtr) MTPNP_PFAL_SSReqHistoryDelHdlr);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (IsScreenPresent(CM_SCR_MARKER) == FALSE)
        AddMarkerToHistory();
}

U8 MTPNP_PFAL_SSReqHistoryDelHdlr(void *in_param)
{
    MTPNP_PFAL_DropUssd(0);
    return FALSE;
}

void MTPNP_PFAL_CC_SetUnknownToNum(MTPNP_CHAR * number)
{
    MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) number, (MTPNP_CHAR *) GetString(STR_UNKNOWN_CALLER));
}

void MTPNP_PFAL_CC_DgRejectAllIncoming(void)
{

    if (MTPNP_AD_CC_IsSlaveCCInIncoming() == MTPNP_TRUE)
    {
        MTPNP_AD_CC_RejectIncomingCall();
    }
    if (MTPNP_PFAL_CC_IsMasterCCInIncoming() == MTPNP_TRUE)
    {
        KbCBackCallIncomingRejected();
    }
}

void MTPNP_PFAL_CC_DGAcceptAllIncoming(void)
{
    if (MTPNP_PFAL_CC_IsMasterCCInIncoming() == MTPNP_TRUE)
    {
        MTPNP_PFAL_CC_AcceptMasterIncomingCall();
    }
    if (MTPNP_AD_CC_IsSlaveCCInIncoming() == MTPNP_TRUE)
    {
        if (MTPNP_AD_CC_GetTotalActiveCallCount() > 0 && MTPNP_AD_CC_GetTotalHeldCallCount() > 0)
        {
#ifndef __MMI_UCM__
            MTPNP_PFAL_CC_NOUCMShowCallErrorMessage(NO_ACTIVE_CALL);
#else  /* __MMI_UCM__ */
            MTPNP_PFAL_CC_UCMShowCallErrorMessage(NO_ACTIVE_CALL, MMI_GSM_UCM_IDLE);
#endif  /* __MMI_UCM__ */
        }
        else
        {
            MTPNP_AD_CC_AcceptSlaveIncomingCall();
        }
    }
}

void MTPNP_PFAL_CC_AcceptMasterIncomingCall(void)
{
    KbCBackCallIncomingAccepted();
}

void MTPNP_PFAL_CC_CancelMasterMOCall(void)
{
    DropRequest();
}

void MTPNP_PFAL_CC_PHBSetdataforCall(MTPNP_UINT16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MTPNP_UINT8 length;
    ST_MTPNP_AD_TIME logtime;
    PHB_CM_INTERFACE *Slave_PhoneNumberStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Slave_PhoneNumberStruct = MTPNP_PFAL_GetCMPhoneBookStruct();

    length = (MTPNP_UINT8) (MTPNP_PFAL_Unicode_String_Length((S8 *) (Slave_PhoneNumberStruct->name)));

    MTPNP_AD_CC_SetCallCurrNameLen(index, length);

    MTPNP_AD_CC_SetCallCurrName(index, Slave_PhoneNumberStruct->name);

    DTGetRTCTime(&logtime);

    MTPNP_AD_CC_SetCallCurrTime(index, &logtime);

}

/*call control call wait begin*/
void MTPNP_PFAL_CC_ShowCallWaitingRsp(void *info)
{
    MTPNP_UINT8 bs_index;
    MTPNP_SS_CALL_WAIT_RSP *pMsgCallWaitRsp = (MTPNP_SS_CALL_WAIT_RSP *) info;
    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_ShowCallWaitingRsp");
    MTPNP_OSAL_memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    DeleteScreenIfPresent(SCR_ID_CALLSET_WAITING_MAIN);
    /* check the status of the response result */
    if (pMsgCallWaitRsp->result.flag == L4C_OK)
    {
        /* if the response is success check the type */
        /* format the result string */
        if (pMsgCallWaitRsp->status & SS_ABIT)
        {
            /* format the result string with active/deactive tags. */
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
            mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_ACTIVATED));
            for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
            {
                if ((mmi_ucs2strlen((MTPNP_CHAR *) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                     + mmi_ucs2strlen((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer)) <
                    MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    AppendBScodeString(pMsgCallWaitRsp->list[bs_index],
                                       (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
                }
            }
        }
        else
        {
            /* format the result string with active/deactive tags. */
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_SCR8096_MNGCALL_CALLWAIT_ON));
            mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_DEACTIVATED));
            for (bs_index = 0; bs_index < pMsgCallWaitRsp->count; bs_index++)
            {
                if ((mmi_ucs2strlen((MTPNP_CHAR *) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                     + mmi_ucs2strlen((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer)) <
                    MAX_DISP_UCS2 / ENCODING_LENGTH)
                {
                    AppendBScodeString(pMsgCallWaitRsp->list[bs_index],
                                       (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
                }
            }
        }
        /* call the result screen function to display the result string */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
    }
    else
    {
        /* in case of response failure */
#ifdef  __MMI_SS_SHOW_CAUSE__
        ShowCauseString(pMsgCallWaitRsp->result.cause, (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
#else
        /* display the not done popup */
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                     ERROR_TONE);
        MTPNP_PFAL_RemoveSSReqScr();
#endif
    }
    return;
}

void MTPNP_PFAL_CC_EntryCallsetGeneralSSResut(void)
{
    if ((MTPNP_AD_CC_IsSlaveCCInIncoming() ==
         MTPNP_FALSE) /*lst temp|| (GetActiveScreenId() == SLAVE_SCR_CM_REQUESTINGUSSD) */ )
    {
        MTPNP_PFAL_RemoveSSReqScr();
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResutScr();
    }
    else
    {
        HistoryReplace(SCR_CM_REQUESTINGUSSD, SCR_ID_CALLSET_GENERAL_SS_RESULT,
                       MTPNP_PFAL_CC_EntryCallsetGeneralSSResutScr);
    }
}

void MTPNP_PFAL_CC_EntryCallsetGeneralSSResutScr(void)
{

    EntryNewScreen(SCR_ID_CALLSET_GENERAL_SS_RESULT, NULL, MTPNP_PFAL_CC_EntryCallsetGeneralSSResutScr, NULL);
    MTPNP_PFAL_RemoveSSReqScr();

    ShowCategory74Screen(STR_GLOBAL_DONE,
                         0, STR_GLOBAL_OK, IMG_GLOBAL_OK, 0, 0,
                         g_callset_context.SSDisplayBuffer, mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer),
                         NULL);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*call control call wait end*/
/*call control call barring begin*/
void MTPNP_PFAL_CC_CallBarringRsp(void *info)
{
    MTPNP_SS_CALL_BARRING_RSP *pMsgBarringRsp = (MTPNP_SS_CALL_BARRING_RSP *) info;
    MTPNP_UINT8 bs_index;
    MTPNP_OSAL_memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);

    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);

    /* check the status of the response result */
    if (pMsgBarringRsp->result.flag == L4C_OK)
    {
        /* if the response is success check the type */
        switch (pMsgBarringRsp->type)
        {
            /* call barring all outgoing calls */
        case L4_BAOC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BAOC_A));
            break;
            /* call barring all outgoing international calls */
        case L4_BOIC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BOIC_A));
            break;
            /* call barring all outgoing international calls except home */
        case L4_BOICEXHC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_BOICEXHC_A));
            break;
            /* call barring all incoming calls */
        case L4_BAIC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BAIC_A));
            break;
            /* call barring all incoming roaming calls */
        case L4_BAICROAM:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_BAICROAM_A));
            break;
            /* call barring cancel all calls */
        case L4_BAC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BAC_A));
            break;
            /* call barring all outgoing calls */
        case L4_BOC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BOC_A));
            break;
            /* call barring all incoming calls */
        case L4_BIC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_BIC_A));
            break;
        default:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_DEFAULT_A));
            break;
        }
        /* format the result string with active/deactive tags. */
        if (pMsgBarringRsp->count == 0)
        {
            mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_DEACTIVATED));
        }
        for (bs_index = 0; bs_index < pMsgBarringRsp->count; bs_index++)
        {
            if ((mmi_ucs2strlen((MTPNP_CHAR *) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS))
                 + mmi_ucs2strlen((MTPNP_CHAR *) GetString(STR_DEACTIVATED))
                 + mmi_ucs2strlen((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer)) <
                MAX_DISP_UCS2 / ENCODING_LENGTH)
            {
                if (pMsgBarringRsp->list[bs_index].ss_status & SS_ABIT)
                {
                    mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                                     (MTPNP_CHAR *) GetString(STR_ACTIVATED));
                }
                else
                {
                    mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                                     (MTPNP_CHAR *) GetString(STR_DEACTIVATED));
                }
                AppendBScodeString(pMsgBarringRsp->list[bs_index].bs_code,
                                   (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
            }
        }
        /* call the result screen function to display the result string */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
    }
    else
    {
        /* in case of response failure */
#ifdef  __MMI_SS_SHOW_CAUSE__
        ShowCauseString(pMsgBarringRsp->result.cause, (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
#else
        /* display the not done popup */
        if (pMsgBarringRsp->result.cause == CM_SS_ERR_NEGATIVEPW_CHECK)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SETTING_WRONG), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        else if (pMsgBarringRsp->result.cause == CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SETTING_BLOCK), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        else
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        MTPNP_PFAL_RemoveSSReqScr();
#endif
    }
    return;
}

void MTPNP_PFAL_CC_DisplayCFUInd(void *info)
{
#ifdef __MMI_CFU_SEPARATE_LINE__        /* MTK 1111, Robin CFU regardless Line ID */
    static U8 StatusSIM2CFULine1 = 0;
    static U8 StatusSIM2CFULine2 = 0;
#endif /* __MMI_CFU_SEPARATE_LINE__ */ 

    ST_MTPNP_AD_CFU_IND *MsgCfuInd;
    MsgCfuInd = (ST_MTPNP_AD_CFU_IND *) info;

#ifdef __MMI_CFU_SEPARATE_LINE__        /* MTK 1111, Robin CFU regardless Line ID */
    if (MsgCfuInd != NULL)
    {
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L1);
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L2);
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD);

        if (MsgCfuInd->action == 1)
        {
            if (MsgCfuInd->line_num == 0)
            {
                StatusSIM2CFULine1 = 1;
            }
            else if (MsgCfuInd->line_num == 1)
            {
                StatusSIM2CFULine2 = 1;
            }
        }
        else
        {
            if (MsgCfuInd->line_num == 0)
            {
                StatusSIM2CFULine1 = 0;
            }
            else if (MsgCfuInd->line_num == 1)
            {
                StatusSIM2CFULine2 = 0;
            }
        }
    }

    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1)
    {
        /* only keep the status and not show category if the mode is not matched to SIM */
        return;
    }

    if ((StatusSIM2CFULine1) && (!StatusSIM2CFULine2))
    {
        ShowStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L1);
    }
    else if ((!StatusSIM2CFULine1) && (StatusSIM2CFULine2))
    {
        ShowStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L2);
    }
    else if ((StatusSIM2CFULine1) && (StatusSIM2CFULine2))
    {
        ShowStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD);
    }
    UpdateStatusIcons();

#else /* __MMI_CFU_SEPARATE_LINE__ */ 
    if (MsgCfuInd != NULL)
    {
        if (MsgCfuInd->action == 1)
        {
            ShowStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD);
        }
        else
        {
            HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD);
        }
        UpdateStatusIcons();
    }
#endif /* __MMI_CFU_SEPARATE_LINE__ */ 
}

void MTPNP_PFAL_CC_DisplaySpeechInd(void *info)
{
    ST_MTPNP_SPEECH_IND_INFO *MsgSpeechInd;
    MsgSpeechInd = (ST_MTPNP_SPEECH_IND_INFO *) info;
    if (MsgSpeechInd->on_off == 1)
    {
    #if (defined  __MMI_WGUI_CSK_ENABLE__) && (defined __MMI_TOUCH_SCREEN__) \
		&& (!(defined __MMI_TOUCH_IDLESCREEN_SHORTCUTS__) || defined(__DISPLAY_SK_WHEN_IDLE_SHORTCUTS_ENABLED__))
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
        SetCenterSoftkeyFunction(EnterScreenAndHandleDigit, KEY_EVENT_UP);
        redraw_center_softkey();
    #endif
    }
}

void MTPNP_PFAL_CC_CallChangePwdRsp(void *info)
{
    MTPNP_SS_CALL_BARRING_RSP *pMsgBarringRsp = (MTPNP_SS_CALL_BARRING_RSP *) info;
    /* change passwd response handling */
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OUT);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_IN);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OLD_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_OPTION);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_NEW_PASS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_BARRING_CFRM_PASS);

    if (pMsgBarringRsp->result.flag == 0)
    {
        mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                         (PS8) GetString(STR_CHANGE_PSW_SUCCESS_TEXT));
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
    }
    else
    {
        if (pMsgBarringRsp->result.cause == CM_SS_ERR_NEGATIVEPW_CHECK)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SETTING_WRONG), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        else if (pMsgBarringRsp->result.cause == CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION)
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_SETTING_BLOCK), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        else
        {
            DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                         ERROR_TONE);
        }
        MTPNP_PFAL_RemoveSSReqScr();
    }
}

/*call control call barring end*/

/*call control call forward begin*/
void MTPNP_PFAL_CC_ShowCallForwardRsp(ST_MTPNP_CALL_FORWARD_INFO * info)
{
    MTPNP_CHAR short_string[20], TempShortString[40];
    MTPNP_CHAR TempBuff[200];
    MTPNP_OSAL_memset(g_callset_context.SSDisplayBuffer, 0, MAX_DISP_UCS2);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NUMBER);
    DeleteScreenIfPresent(SCR_ID_CALLSET_FORWARD_NO_ANS_TIME);
    DeleteScreenIfPresent(SCR_ID_CALFWD_TO_OPTION);
    if (NULL == info)
    {
        DisplayPopup((MTPNP_UINT8 *) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 0, CS_NOTIFYDURATION,
                     ERROR_TONE);
        MTPNP_PFAL_RemoveSSReqScr();
    }
    /* check the status of the response result */
    else
    {
        switch (info->Type)
        {
            /* Call Forward Unconditional */
        case MTPNP_CFU:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFU));
            break;
            /* Call Forward When Busy */
        case MTPNP_CFB:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFB));
            break;
            /* Call Forward When Not Reply */
        case MTPNP_CFNRY:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFNRY));
            break;
            /* Call Forward When Not Reachable */
        case MTPNP_CFNRC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFNRC));
            break;
            /* All Call Forward */
        case MTPNP_CFA:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFA));
            break;
            /* All Conditional Call Forward  */
        case MTPNP_CFC:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_L4_CFC));
            break;
            /* Unknown Service Type */
        default:
            mmi_ucs2cpy((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_FWD_UNKNOWN_SERVICE));
            break;
        }
        /* format the result string with active/deactive tags. */
        if (1 == (info->Status & 0x01))
        {
            mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer, (MTPNP_CHAR *) GetString(STR_ACTIVATED));
            memset(TempBuff, 0, sizeof(TempBuff));
            if (info->nSeconds != 0)
            {
                sprintf(short_string, "%d ", (U8) info->nSeconds);
                mmi_asc_to_ucs2((MTPNP_CHAR *) TempShortString, (PS8) short_string);
                mmi_ucs2cat((S8 *) TempBuff, (S8 *) TempShortString);
                mmi_ucs2cat((MTPNP_CHAR *) TempBuff, (MTPNP_CHAR *) GetString(STR_SECONDS));
            }
            AppendBScodeString((info->Status>>1), (MTPNP_CHAR *) g_callset_context.SSDisplayBuffer);
            if (strlen((char *) info->Address) != 0)
            {
                strcpy((MTPNP_CHAR *) short_string, (PS8) info->Address);
                strcat((MTPNP_CHAR *) short_string, " ");
                mmi_asc_to_ucs2((MTPNP_CHAR *) TempShortString, (MTPNP_CHAR *) short_string);
                mmi_ucs2cat((S8 *) TempBuff, (S8 *) TempShortString);
            }
            if ((mmi_ucs2strlen((PS8) TempBuff) + mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer))
                < MAX_DISP_UCS2 / ENCODING_LENGTH)
            {
                mmi_ucs2cat((S8 *) g_callset_context.SSDisplayBuffer, (S8 *) TempBuff);
            }
        }
        else
        {
            mmi_ucs2cat((MTPNP_CHAR *) g_callset_context.SSDisplayBuffer,
                             (MTPNP_CHAR *) GetString(STR_DEACTIVATED));
        }
        /* call the result screen function to display the result string */
        DeleteScreenIfPresent(SCR_ID_CALLSET_GENERAL_SS_RESULT);
        MTPNP_PFAL_CC_EntryCallsetGeneralSSResut();
    }
}

/*call control call forward end*/

void MTPNP_PFAL_CC_ReportCCState(void *msgbuf)
{
    MMI_CALL_LIST_RSP *callRsp;
    MTPNP_CALL_LIST_STRUCT *callList;
    MTPNP_UINT8 count;
    MTPNP_UINT16 index;
    callRsp = (MMI_CALL_LIST_RSP *) msgbuf;

    kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_CC_ReportCCState");
    if (callRsp->result == MTPNP_TRUE)
    {
        callList = (MTPNP_CALL_LIST_STRUCT *) & callRsp->call_list;
        for (count = 0; (count < callList->length) && (callList->list[count].call_id != 0); count++)
        {
            if (MTPNP_AD_CC_GetCallIndexbyHandle((unsigned char) callList->list[count].call_id, &index) == MTPNP_TRUE)
            {

                kal_prompt_trace(MOD_CC, "MTPNP_PFAL_CC_ReportCCState callList->list[count].call_state=%x index=%x",
                                 callList->list[count].call_state, index);

                switch (callList->list[count].call_state)
                {
                case CLCC_CALL_ACTIVE:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_ACTIVE_STATE, index);
                        break;
                    }
                case CLCC_CALL_HELD:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_HOLD_STATE, index);
                        break;
                    }
                case CLCC_CALL_DIALING:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_OUTGOING_STATE, index);
                        break;
                    }
                case CLCC_CALL_ALERTING:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_OUTGOING_STATE, index);
                        break;
                    }
                case CLCC_CALL_INCOMING:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_INCOMING_STATE, index);
                        break;
                    }
                case CLCC_CALL_WAITING:
                    {
                        MTPNP_AD_CC_SetCallCurState(MTPNP_CM_INCOMING_STATE, index);
                        break;
                    }
                }               //End of Switch

            }                   //End of if
        }                       //End of for
        MTPNP_AD_CC_UpdateCallStateMachine();
        MTPNP_PFAL_sync_call_list_ind();
    }                           //End of if

    MTPNP_PFAL_CC_RefreshCurWin();
}

MTPNP_BOOL MTPNP_PFAL_CC_IsInCall(void)
{
    return isInCall();
}
MTPNP_UINT8 MTPNP_PFAL_ConvertKeycode2Ascii(MTPNP_UINT16 key)
{
    switch (key)
    {
    case KEY_0:
    case KEY_1:
    case KEY_2:
    case KEY_3:
    case KEY_4:
    case KEY_5:
    case KEY_6:
    case KEY_7:
    case KEY_8:
    case KEY_9:

        return (key + 0x30);
    case KEY_STAR:
        return 0x2A;
    case KEY_POUND:
        return 0x23;
    default:
        return 0;
    }
}

void MTPNP_PFAL_CC_SetQuickEndTime(void)
{
#ifdef __MMI_CH_QUICK_END__
    cm_p->alert_info.QuickEndTime = CHISTGetQuickEndTime();
#endif/*__MMI_CH_QUICK_END__*/
}

void MTPNP_PFAL_CC_NotifyRetrieveSuccess(void)
{
    EntryScr1006NotifyRetrieveSucess();
}

void MTPNP_PFAL_CC_StopAutoAnsTimer(void)
{
    StopTimer(MTPNP_AUTOANSWER_NOTIFYDURATION_TIMER);
}

void MTPNP_PFAL_CC_SetRedialNum(void)
{
    SetCard2RedialNumber();
}

void MTPNP_PFAL_CC_SetMissNotify(void)
{
    SetMissedCallFlag(TRUE);
}

void MTPNP_PFAL_CC_HideCard2MissIcon(void)
{
    HideStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
}

void MTPNP_PFAL_CC_ShowCard2MissIcon(void)
{
    ShowStatusIcon(STATUS_ICON_CARD2MISSED_CALL);
}

MTPNP_BOOL MTPNP_PFAL_Retrieve_CallDial_State(MTPNP_UINT8 * m_dial_enable,
                                                                                               MTPNP_UINT8 * s_dial_enable)
{
    if (m_dial_enable == MTPNP_NULL || s_dial_enable == MTPNP_NULL)
    {
        return MTPNP_FALSE;
    }
    switch (MTPNP_AD_Get_UsableSide())
    {
      case MTPNP_AD_DUALSIM_UNUSABLE:
         *m_dial_enable = 0;
         *s_dial_enable = 0;
      	break;
      case MTPNP_AD_SIMCARD1_NOSIM_USABLE:
         if (mmi_ucm_dial_option())
      	 {
               *m_dial_enable = 1;
         }
	     else
	     {
               *m_dial_enable = 0;
	     }
         *s_dial_enable = 0;
      	break;
      case MTPNP_AD_SIMCARD2_NOSIM_USABLE:
      	 *m_dial_enable = 0;
         if (mmi_ucm_dial_option())
      	 {
               *s_dial_enable = 1;
	     }
	     else
	     {
               *s_dial_enable = 0;
	     }
      	break;
      case MTPNP_AD_SIMCARD1_USABLE:
	     if (mmi_ucm_dial_option())
      	 {
               *m_dial_enable = 1;
         }
	     else
	     {
               *m_dial_enable = 0;
	     }
	     *s_dial_enable = 0;
      	break;
      case MTPNP_AD_SIMCARD2_USABLE:
      	     *m_dial_enable = 0;
	     if (mmi_ucm_dial_option())
      	 {
               *s_dial_enable = 1;
	     }
	     else
	     {
               *s_dial_enable = 0;
	     }
      	break;
      case MTPNP_AD_DUALSIM_USABLE:
      	 if (mmi_ucm_dial_option())
      	 {
               *m_dial_enable = 1;
	     }
	     else
	     {
               *m_dial_enable = 0;
	     }
         
	     if (mmi_ucm_dial_option())
      	 {
               *s_dial_enable = 1;
	     }
	     else
	     {
               *s_dial_enable = 0;
	     }
      	break;
      default:
	     *m_dial_enable = 0;
	     *s_dial_enable = 0;
      	break;
    }

    /* Press '*' key in PUK screen */
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) == 0)
    {
        if (mmi_bootup_is_in_security_check() ||
            mmi_bootup_is_in_sim2_security_check() ||
            mmi_secset_is_in_puk_check() ||
            mmi_secset_is_in_sim2_puk_check())
        {
            PRINT_INFORMATION("\n MTPNP_PFAL_Retrieve_CallDial_State: in security check \n");
            *m_dial_enable = 0;
            *s_dial_enable = 0;
        }
    }
    
    PRINT_INFORMATION("\n MTPNP_PFAL_Retrieve_CallDial_State:m_dial_enable = %d ,s_dial_enable = %d\n,",*m_dial_enable,*s_dial_enable);
    return MTPNP_TRUE;
}

void MTPNP_PFAL_CC_ShowNotAllow(void *msg)
{

      MTPNP_PFAL_CC_UCMShowCallErrorMessage(NO_ACTIVE_CALL, MMI_GSM_UCM_DIAL);
      
      /*DisplayPopup(
      (U8 *) GetString(ERROR_NETWORK_NOT_ALLOWED),
      IMG_GLOBAL_UNFINISHED,
      1,
      UI_POPUP_NOTIFYDURATION_TIME,
      ERROR_TONE_IN_CALL);*/
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
