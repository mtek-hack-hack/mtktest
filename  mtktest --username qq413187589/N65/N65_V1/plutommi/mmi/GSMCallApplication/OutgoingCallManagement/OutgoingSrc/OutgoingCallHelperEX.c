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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   OutgoingCallHelper.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  .......
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Register callback function fop dialing icon
 *
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : OutgoingCallHelper.c

   PURPOSE     : Call Management application

   REMARKS     : nil

   AUTHOR      : Subramanya BG

   DATE     : Nov 12,02

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "wgui.h"
#include "Wgui_status_icons.h"

#include "BootUp.h"
#include "PowerOnChargerProt.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "CallSetUpEnum.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "AlarmFrameworkProt.h"
#include "DateTimeGprot.h"

#include "CallmanagementIdDefEX.h"
#include "CallManagementStructEX.h"
#include "CallStructureManagementProtEX.h"
#include "CmErrorTypesEX.h"
#include "CmErrorHandlersProtEX.h"
#include "CommonStubsProtEX.h"
#include "HistoryHelperProtEX.h"
#include "PsCallHelperDefEX.h"
#include "mmiapi_struct.h"
#include "PsCallHelperGprotEX.h"
#include "RedialHelperGProtEX.h"
#include "CallManagementGprotEX.h"
#include "IncomingCallManagementProtEX.h"
#include "OutgoingCallManagementProtEX.h"

#include "CallsGProts.h"

#include "OutgoingCallHelperGProtEX.h"
#include "OutgoingCallHelperProtEX.h"
#include "gpioInc.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"

#include "VolumeHandler.h"

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#endif

#if defined(__MMI_BG_SOUND_EFFECT__)
#include "BGSoundGProt.h"
#endif 

#ifdef __MMI_BT_PROFILE__
#include "mdi_datatype.h"
#include "mdi_audio.h"
void mmi_profiles_bt_call_start_callback(void);
#endif /* __MMI_BT_PROFILE__ */ 

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "ddl.h"
#include "jcutils.h"
#include "jcerror.h"
#include "jdd_tapi.h"
#endif

#include "SettingGprots.h"
#include "SATGProts.h"
#include "app_usedetails.h"
#include "SSCStringHandle.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC_UCM.h"
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

static CM_CALL_HANDLE gMyhandle;

/* static U16 curKeyCode, curKeyType; */
static pBOOL gCheckDialIndEndOutgoing = FALSE;

S8 DTMFPadCallBuffer[MAX_DIGITS_USSD];
#ifdef __MTK_TARGET__
__align(2)
#endif /* __MTK_TARGET__ */ 
S8 UnicodeDTMFPadCallBuffer[MAX_DIGITS_USSD * ENCODING_LENGTH];
PU8 gCallDeflectNumber;

extern U16 gtmpOutgoingIndex;
extern void SSCHandleIMEI(void);

const U16 CMIdleScreenDigits[MAX_CM_SCREEN_DIGITS] = 
{
    KEY_0, KEY_1, KEY_2, KEY_3,
    KEY_4, KEY_5, KEY_6, KEY_7,
    KEY_8, KEY_9, KEY_STAR,
    KEY_POUND
};


/*****************************************************************************
 * FUNCTION
 *  MakeCallEx
 * DESCRIPTION
 *  Wrapper which checks to see if the call to be made is
 *  O/G or USSD
 *  
 *  This function is exported to others applications
 * PARAMETERS
 *  strNumber       [IN]        
 *  pre_check       [IN]        
 *  Number(?)       [IN]        Which needs to be sent to network
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCallEx(PS8 strNumber, BOOL pre_check, U8 call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    ClearDtmfBuf();
    FillDtmfBuff((PU8) strNumber);

    if (!pre_check)
    {
        if ((NULL == strNumber) || (0 == *strNumber) ||(mmi_gsm_check_number_validation(strNumber) == MMI_FALSE))
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
             if(MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE ||
                MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
             {
                  MTPNP_PFAL_CC_UCMShowCallErrorMessage(ERR_INVALID_NUMBER_FORMAT, MMI_GSM_UCM_DIAL);
                  return;
             }
             else
        #endif  /* __MMI_DUAL_SIM_MASTER__ */
             {
                 ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
		    return;
             }
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
       if (!CheckValidEmergencyNo1(strNumber, SIM1))
    #else /* __MMI_DUAL_SIM_MASTER__ */
       if (!CheckValidEmergencyNo1(strNumber))
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            if ((UCS2StrFirstPositionSearch(strNumber) == FALSE) ||
                (UCS2StrNoFirstPositionSearch(strNumber, 'p') == FALSE) ||
                (UCS2StrNoFirstPositionSearch(strNumber, 'w') == FALSE))
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                if(MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_SLAVE ||
                    MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL) == MTPNP_AD_CHANNEL_DEFAULT_SLAVE)
                {
                    MTPNP_PFAL_CC_UCMShowCallErrorMessage(ERR_INVALID_NUMBER_FORMAT, MMI_GSM_UCM_DIAL);
                    return;
                }
                else
            #endif  /* __MMI_DUAL_SIM_MASTER__ */
                {
                    ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
                    return;
                }
            }
        }
    }

    CheckShortCutOrCall(call_type);
}


/*****************************************************************************
 * FUNCTION
 *  MakeCall
 * DESCRIPTION
 *  Check if the background sound is turn on
 *  
 *  This function is exported to others applications
 * PARAMETERS
 *  strNumber       [IN]        
 *  Number(?)       [IN]        Which needs to be sent to network
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCall(PS8 strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_DUAL_SIM_MASTER__
	kal_prompt_trace(MOD_CC,"MakeCall MTPNP_AD_Get_Channel:%x",MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL));
    switch (MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL))
	{
	case MTPNP_AD_CHANNEL_SLAVE:
	case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		if(MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_IDLE)
	       {
			mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE_SIM2, (U8*)strNumber);
			return ;
	       }
		break;
	case MTPNP_AD_CHANNEL_MASTER:
	case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		if(cm_p->ucm_operation == MMI_GSM_UCM_IDLE)
		{
			mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*)strNumber);
	        	return;
		}
		break;
	default:
		ASSERT(0);
		break;
	}
#else  /* __MMI_DUAL_SIM_MASTER__ */
    if(cm_p->ucm_operation == MMI_GSM_UCM_IDLE)
    {
        mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*)strNumber);
        return;
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    /*stop USSD session before making emergency call*/

#ifdef __MMI_DUAL_SIM_MASTER__
       if ( CheckValidEmergencyNo1(strNumber, SIM1) &&
#else /* __MMI_DUAL_SIM_MASTER__ */
       if ( CheckValidEmergencyNo1(strNumber) &&
#endif /* __MMI_DUAL_SIM_MASTER__ */
        (IsScreenPresent(ITEM_SCR_USSN_MSG) || 
         GetExitScrnID() == ITEM_SCR_USSN_MSG ||
         IsMyTimerExist(USSD_UCM_DISPLAY_TIMER)))
    {
    #ifdef __MMI_USSR_TIMER__  
        USSRTimeout();
    #endif /* __MMI_USSR_TIMER__ */
    }
    
    if ((strNumber != NULL) &&
        (*strNumber != 0) &&
        (mmi_gsm_check_number_validation(strNumber) == MMI_TRUE) &&
#ifdef __MMI_DUAL_SIM_MASTER__
           (( CheckValidEmergencyNo1(strNumber, SIM1) ) ||
#else /* __MMI_DUAL_SIM_MASTER__ */
           (( CheckValidEmergencyNo1(strNumber) ) ||
#endif /* __MMI_DUAL_SIM_MASTER__ */
        (UCS2StrFirstPositionSearch(strNumber) == TRUE) &&
        (UCS2StrNoFirstPositionSearch(strNumber, 'p') == TRUE) &&
        (UCS2StrNoFirstPositionSearch(strNumber, 'w') == TRUE) ))
    {
        /* Already check the number correctness, no need to check in MakeCallEx() again */
        MakeCallEx(strNumber, TRUE, CSMCC_VOICE_CALL); /* add by Tony for VT */
        return;
    }
    MakeCallEx(strNumber, FALSE, CSMCC_VOICE_CALL); /* add by Tony for VT */
}

#ifdef __SAT__
/*****************************************************************************
 * FUNCTION
 *  MakeSATCall
 * DESCRIPTION
 *  Shows only outgoing call screen and takes control
 * PARAMETERS
 *  number          [IN]        
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
void MakeSATCall(PU8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for SAT MO only  */

    SetPreviousState((CALL_STATE) GetCurrentState());
    SetCurrentState(CM_OUTGOING_STATE);

    gtmpOutgoingIndex = GetFirstFreeIndex();
    AddNewCallInfo(
        number,
        (CALL_STATE) GetCurrentState(),
        CM_IDLE_STATE,
        CM_CALL_MO_STK,
        (CM_CALL_HANDLE) (255),
        CSMCC_VOICE_CALL);

    mmi_sat_call_setup_dial_from_ucm();

    if(cm_p->ucm_operation == MMI_GSM_UCM_DIAL)
    {
        mmi_gsm_dial_rsp(TRUE, CC_OPERATION, NULL);
    }
    else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_DIAL)
    {
        mmi_gsm_hold_and_dial_rsp(TRUE, CC_OPERATION, NULL);
    }
    else
    {
        ASSERT(0);
    }
}
#endif /* __SAT__ */

/*****************************************************************************
 * FUNCTION
 *  CheckShortCutOrCall
 * DESCRIPTION
 *  Helper function to check if the key is shortcut or not
 *  if not it makes a call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CheckShortCutOrCall(U8 call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 dtmfBuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtmfBuf = GetDtmfBuffer();

    /*Move to UCM*/
    /*if (IsStandardGsmSS(dtmfBuf))
    {
        return;
    }*/
    if (isHashString(dtmfBuf))
    {
        MakeMyCall((PS8) dtmfBuf,call_type);
    }
    else if (isShortString(dtmfBuf))
    {
        MakeMyCall((PS8) dtmfBuf,call_type);
    }
    else    /* if (AllowMoreCalls()) */
    {
        MakeMyCall((PS8) dtmfBuf,call_type);
    }
    ClearDtmfBuf();
}


/*****************************************************************************
 * FUNCTION
 *  MakeMyCall
 * DESCRIPTION
 *  Helper function to make a outgoingcall of a given number.
 *  
 *  This converts the number to OUTGOING_CALL structure which is necessary for State m/c.
 * PARAMETERS
 *  strNumber       [IN]        
 *  Number(?)       [IN]        Which needs to make the outgoing call.
 * RETURNS
 *  void
 *****************************************************************************/
void MakeMyCall(PS8 strNumber, U8 call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    OUTGOING_CALL outCall;
#ifdef __MMI_DUAL_SIM_MASTER__
    S8 IpStr[MTPNP_MAX_IP_NUMBER_LEN+1];
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    switch (MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL))
    {
        case MTPNP_AD_CHANNEL_SLAVE:
        case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
            if(cm_p->slave_reply_ussr == MMI_TRUE)
            {
                /*Any input will be treated as the reply from user for USSR*/
                mmi_gsm_set_slave_reply_ussr_flag(MMI_FALSE);
                break;
            }
            else if (SS_OPERATION == applib_ss_string_parsing((kal_uint8 *)strNumber, (kal_uint8)strlen(strNumber)) &&
                        MTPNP_AD_CC_GetSourceId() == LMMI_SRC)
            {
                mmi_gsm_set_slave_ss_falg(TRUE);
                break;
            }
            else if(GetTempUseIPNumber())
            {
                 GetCurrCard2IPNumber(IpStr);
                 MTPNP_AD_CC_MakeACall(strNumber,IpStr);
            }
            else
            {
                MTPNP_AD_CC_MakeACall(strNumber,MTPNP_NULL);
            }
            return ;
        case MTPNP_AD_CHANNEL_MASTER:
        case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
        default:
            break;
	}
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    memset(&outCall, 0, sizeof(OUTGOING_CALL));
    if ((strlen((void*)strNumber) * ENCODING_LENGTH) > MAX_CM_NUMBER)
    {
        PRINT_INFORMATION("XXX Number too long XXX \n");
        ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
        return;
    }
#ifdef __MMI_USSD_REPLY_UCS2__
    strcpy((void*)outCall.Number, (void*)DTMFPadCallBuffer);
#else /*__MMI_USSD_REPLY_UCS2__*/
    mmi_ucs2cpy((void*)outCall.Number, (void*)UnicodeDTMFPadCallBuffer);
#endif /*__MMI_USSD_REPLY_UCS2__*/
    outCall.call_type = call_type;
    MakeOutgoingcall(outCall);
}

#ifdef __MMI_USSD_REPLY_UCS2__
/*****************************************************************************
 * FUNCTION
 *  MakeReplyUSSRCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 * 
 *****************************************************************************/
void MakeReplyUSSRCall(PS8 strNumber, U8 call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    OUTGOING_CALL outCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&outCall, 0, sizeof(OUTGOING_CALL));
    if ((strlen((void*)strNumber) * ENCODING_LENGTH) > MAX_CM_NUMBER)
    {
        PRINT_INFORMATION("XXX Number too long XXX \n");
        ShowCallManagementErrorMessage(ERR_INVALID_NUMBER_FORMAT, cm_p->ucm_operation);
        return;
    }
    mmi_ucs2cpy((void*)outCall.Number, (void*)UnicodeDTMFPadCallBuffer);
    outCall.bIsUcs2 = TRUE;
    outCall.call_type = call_type;
    MakeOutgoingcall(outCall);
}
#endif /*__MMI_USSD_REPLY_UCS2__*/

/*****************************************************************************
 * FUNCTION
 *  MakeOutgoingcall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_OUTGOINGCALL with the OUTGOING_CALL structure.
 *  
 *  This invokes the function to process the CM_KB_OUTGOINGCALL event in the state m/c.
 * PARAMETERS
 *  MsgStruct           [IN]        
 *  structure(?)        [IN]        Contains the calling number and name if present corresponding to that number.
 * RETURNS
 *  void
 *****************************************************************************/
void MakeOutgoingcall(OUTGOING_CALL MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_OUTGOINGCALL, &MsgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  IsStandardGsmSS
 * DESCRIPTION
 *  Helper function for interpreting user code
 * PARAMETERS
 *  dtmfBuf         [IN]        
 *  true(?)         [OUT]       Or false on the basis of interepretaion of SS
 *  buffer(?)       [IN]        For interpretation
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsStandardGsmSS(PU8 dtmfBuf)
{
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  isHashString
 * DESCRIPTION
 *  Helper function to check is this is a # string
 * PARAMETERS
 *  buf             [IN]        
 *  Buffer(?)       [IN]        Containing USSD string
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL isHashString(PU8 buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ('\0' != buf[count])
    {
        if ('#' == buf[count])
        {
            return TRUE;
        }
        if (count >= MAX_DIGIT)
        {
            return FALSE;
        }
        count++;

    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  isShortString
 * DESCRIPTION
 *  Helper function to check is this is a short string
 * PARAMETERS
 *  buf             [IN]        
 *  Buffer(?)       [IN]        Containing USSD string
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL isShortString(PU8 buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ('\0' != buf[count++])
        if (count > 2)
        {
            return FALSE;
        }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrNoFirstPositionSearch
 * DESCRIPTION
 *  Search for a character in string for only first position
 * PARAMETERS
 *  strNumber           [IN]        
 *  charToSearch        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL UCS2StrNoFirstPositionSearch(PS8 strNumber, S8 charToSearch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\nIn UCS2StrNoFirstPositionSearch\n");

    if (strNumber[0] == charToSearch)
    {
        return FALSE;
    }
    else
    {
        pos = 2;
        while (strNumber[pos] != '\0')
        {
            if (strNumber[pos] == charToSearch)
            {
		if (strNumber[pos+2] != '*' && strNumber[pos+2] != '#')
                    return TRUE;
		else
		    return FALSE;
            }
            pos = pos + 2;
        }
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UCS2StrFirstPositionSearch
 * DESCRIPTION
 *  Search for a '+' character in string for only first position
 * PARAMETERS
 *  strNumber       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL UCS2StrFirstPositionSearch(PS8 strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;
    pBOOL secondFlag = FALSE;
    S8 charToSearch = '+';
    U8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\nIn UCS2StrFirstPositionSearch\n");

    if ((mmi_ucs2ncmp((PS8) strNumber, (PS8) L"*31#", 4) == 0) ||
        (mmi_ucs2ncmp((PS8) strNumber, (PS8) L"#31#", 4) == 0))
    {
        length = mmi_ucs2strlen(strNumber) - 4;
        pos = 10;
    }
    else
    {
        length = mmi_ucs2strlen(strNumber);
        pos = 2;
    }

    while (strNumber[pos] != '\0')
    {
        if ((strNumber[pos] == charToSearch) && 
            ((strNumber[pos - 2] != '#' && strNumber[pos - 2] != '*') ||
             (strNumber[(length-1)<<1] != '#') ||
             (strNumber[0] == charToSearch)))
        {
            secondFlag = TRUE;
            break;
        }
        pos = pos + 2;
    }

    if (secondFlag == FALSE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowOutgoingIndicationScreen
 * DESCRIPTION
 *  Shows only outgoing call screen and takes control
 * PARAMETERS
 *  number          [IN]        
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowOutgoingIndicationScreen(PU8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for SAT MO only  */

    SetSATScrnSavedFlag(FALSE);

    SetPreviousState((CALL_STATE) GetCurrentState());
    SetCurrentState(CM_OUTGOING_STATE);

    gtmpOutgoingIndex = GetFirstFreeIndex();
    AddNewCallInfo(
        number,
        (CALL_STATE) GetCurrentState(),
        CM_IDLE_STATE,
        CM_CALL_MO_STK,
        (CM_CALL_HANDLE) (gtmpOutgoingIndex + 1),
        CSMCC_VOICE_CALL);

    OutgoingProcessCMEvent(CM_PS_SHOW_OUTGOING_CALL_SCREEN, NULL);
    SetSATScrnSavedFlag(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  RemoveOutgoingIndicationScreen
 * DESCRIPTION
 *  Removes outgoing call screen
 * PARAMETERS
 *  void
 *  Number(?)       [IN]        To show on screen
 * RETURNS
 *  void
 *****************************************************************************/
void RemoveOutgoingIndicationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0 ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* SAT MO fail case */
    PRINT_INFORMATION("Remove outgoing call screen\n");
    if(mmi_ucm_app_outgoing_call(MMI_UCM_SIM1_CALL_TYPE_ALL) > 0)
    {
        PRINT_INFORMATION("Remove SIM1 outgoing call screen\n");
  	    /*Store uid info for UCM release ind*/
   	    for (count = 0; count < MAX_CALLS; count++)
   	    {
    	    if(cm_p->state_info.AllCalls[count].call_handle == MMI_UCM_INVALID_ID)
      	    {
     		    cm_p->disc_call.ucm_current_uid.call_id = MMI_UCM_INVALID_ID;
         	    cm_p->disc_call.ucm_current_uid.group_id = MMI_UCM_INVALID_ID;
         	    cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);            
         	    cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */

         	    /*For mmi_gsm_release_ind, call list synchronization*/
          	    cm_p->state_info.AllCalls[count].group_id = MMI_UCM_INVALID_ID;
       	    }
  	    }

        SetCallState(MMI_UCM_INVALID_ID, CM_IDLE_STATE, TRUE);
        SetCurrentState(GetPreviousState());
        SetPreviousState(CM_OUTGOING_STATE);
  	    SetCallEndCause(ERR_L4C_GEN_CAUSE);
   	    mmi_gsm_release_ind(GetCallEndCause());
    }
    #if defined(__MMI_DUAL_SIM_MASTER__)
    else if(mmi_ucm_app_outgoing_call(MMI_UCM_SIM2_CALL_TYPE_ALL) > 0)
    {
        PRINT_INFORMATION("Remove SIM2 outgoing call screen\n");
        MTPNP_PFAL_MakeSATCallFail();
    }
    #endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  PsCBackSetCallFeatures
 * DESCRIPTION
 *  This Sets the features of the call as per
 * PARSING STR RSP
 *  
 *  
 *  PARSING_STRING_RSP from PS
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackSetCallFeatures(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PARSE_STR_RSP *rsp;
    CM_CALL_HANDLE handle = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX In PsCBackSetCallFeatures \n");

    rsp = (MMI_PARSE_STR_RSP*) info;

    if (TRUE == DeriveAndSetCallFeatures(info))
    {
        if (GetCCFlag() == TRUE)
        {
            PHB_CM_INTERFACE PhoneNumberStruct;

            /* auto redial and dial from list */
            if (cm_p->redial_info.DialFromPhb != MMI_PHB_NONE)
            {
                mmi_phb_call_set_dial_from_list(cm_p->redial_info.DialFromPhb);
            }

        #ifdef __MMI_DUAL_SIM_MASTER__
            PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(GetOutgoingNumber(), TRUE, SIM1);
        #else /* __MMI_DUAL_SIM_MASTER__ */
            PhoneNumberStruct = mmi_phb_call_get_data_for_call_mgnt(GetOutgoingNumber(), TRUE);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            SetCMPhoneBookStruct(&PhoneNumberStruct);
            /* PhoneNumberStruct = GetCMPhoneBookStruct(); */

            if (CHISTGetDialFromCallLogFlag() == 0)
            {
                /* not dial from call log => use phonebook data and name */
                PRINT_INFORMATION("GSM Call Application: PsCBackSetCallFeatures, Dial from PHB1");
                SetOutgoingNamefromPhonebook();
            }
            else if (mmi_ucs2cmp((PS8) PhoneNumberStruct.name, (PS8) GetOutgoingName()) != 0)
            {
                /* dial from call log but phonebook name not match => don't use phonebook data */
                PRINT_INFORMATION("GSM Call Application: PsCBackSetCallFeatures, Dial from call log, not match in PHB");
                memset(&PhoneNumberStruct, 0, sizeof(PHB_CM_INTERFACE));
                PhoneNumberStruct.pictureId = IMG_PHB_DEFAULT;
                SetCMPhoneBookStruct(&PhoneNumberStruct);
            }
            else
            {
                /* dial from call log but still use phonebook data */
                PRINT_INFORMATION("GSM Call Application: PsCBackSetCallFeatures, Dial from PHB2");
            }

            if(cm_p->ucm_operation == MMI_GSM_UCM_DIAL &&
                cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_dial_rsp(TRUE, CC_OPERATION, NULL);
			}
			else if (cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_DIAL &&
                    cm_p->ucm_action_type == MMI_GSM_UCM_NORMAL)
			{
				mmi_gsm_hold_and_dial_rsp(TRUE, CC_OPERATION, NULL);
			}
			
            CHISTSetDialFromCallLogFlag(0);
            
            return;
        }
        else if (rsp->info.opcode == SS_OPERATION)
        {
            /* SS string */
            if(mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0)
            {
                if (!IsScreenPresent(SCR_CM_REQUESTINGUSSD))
                {
                    insert_screen_before_call_marker(SCR_CM_REQUESTINGUSSD, EntryScrUSSDReq);
                }
            }
            else
            {
                OutgoingProcessCMEvent(CM_PS_SHOW_REQUESTING_CALL_SCREEN, NULL);
            }
        }
        else if(rsp->info.opcode == SIM_OPERATION)
        {
            mmi_ssc_sim_operation_handler(cm_p->state_info.AllCalls[GetOutgoingCallIndex()].number);
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        }
        else
        {
            /* must be SIM operation */
            /* OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, ERR_INVALID_NUMBER_FORMAT); */
        }
    }
    else if ((rsp->result.flag == 0) && (rsp->info.opcode == SIM_OPERATION))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if(cm_p->slave_ss_session)
        {
            if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_DIAL)
            {
                MTPNP_PFAL_dial_rsp(MTPNP_FALSE, MTPNP_AD_CC_CALLTYPE_SS, (U8 *)GetString(STR_GLOBAL_NOT_DONE));
            }
            else if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_DIAL)
            {
                MTPNP_PFAL_dial_rsp(MTPNP_FALSE, MTPNP_AD_CC_CALLTYPE_SS, (U8 *)GetString(STR_GLOBAL_NOT_DONE));
            }
            mmi_gsm_set_slave_ss_falg(FALSE);
        }
        else
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            if(cm_p->ucm_operation == MMI_GSM_UCM_DIAL)
            {
                mmi_gsm_dial_rsp(FALSE, NULL, (U8 *)GetString(STR_GLOBAL_NOT_DONE));
            }
            else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_DIAL)
            {
                mmi_gsm_hold_and_dial_rsp(FALSE, NULL, (U8 *)GetString(STR_GLOBAL_NOT_DONE));
            }
        }
    }
    else if ((rsp->result.flag == 0) && (rsp->info.opcode == INVALID_OPERATION))
    {
        if (rsp->result.cause == PHB_L4C_ERROR)
        {
            OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, ERR_L4C_FDN_FAIL);
        }
        else if (rsp->result.cause == L4C_CMD_CONFLICT)
        {
            OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, ERR_L4C_GEN_CAUSE);
        }
        else
        {
            OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, rsp->result.cause);
        }
    }
    else
    {
        OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, rsp->result.cause);
    }

    g_phb_cntx.dial_from_list = MMI_PHB_NONE;
    PurgeOutgoingCallsStructure();
    SetCallEndedBeforeConnFlag(FALSE);
    CHISTSetDialFromCallLogFlag(0);
    PRINT_INFORMATION("GSM Call Application: PsCBackSetCallFeatures, set CHISTSetDialFromCallLogFlag to 0");

    SetCurrentState(GetPreviousState());
    if (GetPreviousState() == CM_INCOMING_STATE)
    {
        if (GetTotalCallCount() == 1)
        {
            SetPreviousState(CM_IDLE_STATE);
        }
        else if (GetTotalActiveCallCount() == GetTotalCallCount() - 1)
        {
            SetPreviousState(CM_ACTIVE_STATE);
        }
        else if (GetTotalHoldCallCount() == GetTotalCallCount() - 1)
        {
            SetPreviousState(CM_HOLD_STATE);
        }
    }

    /* reset phb data */
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        handle = GetIncomingCallHandle();
    }
    else if (GetCurrentState() == CM_OUTGOING_STATE)
    {
        handle = GetOutgoingCallHandle();
    }
    if (handle != -1)
    {
        PHB_CM_INTERFACE phb_data;
    #ifdef __MMI_DUAL_SIM_MASTER__
        phb_data = mmi_phb_call_get_data_for_call_mgnt(GetCallNumber(handle), FALSE, SIM1);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        phb_data = mmi_phb_call_get_data_for_call_mgnt(GetCallNumber(handle), FALSE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */

    #ifdef __MMI_INCOMING_CALL_VIDEO__
        /* waiting call and ccbs invoke can't use video for display */
        if (GetTotalCallCount() > 0 || GetCCBSFlag() == TRUE)
        {
            phb_data.videoId = 0;
        }
    #endif /* __MMI_INCOMING_CALL_VIDEO__ */ 
        SetCMPhoneBookStruct(&phb_data);
    }

    if (rsp->info.opcode == SS_OPERATION || rsp->info.opcode == SIM_OPERATION)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if(cm_p->slave_ss_session)
        {
            if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_DIAL)
            {
                MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_SS, MTPNP_NULL);
            }
            else if (MTPNP_PFAL_GetUCMOPCodeState() == MMI_GSM_UCM_HOLD_AND_DIAL)
            {
                MTPNP_PFAL_dial_rsp(MTPNP_TRUE, MTPNP_AD_CC_CALLTYPE_SS, MTPNP_NULL);
            }
            
            if(rsp->info.opcode == SIM_OPERATION)
            {
                mmi_gsm_set_slave_ss_falg(FALSE);
            }
            return;
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    
        if(cm_p->ucm_operation == MMI_GSM_UCM_DIAL)
        {
            mmi_gsm_dial_rsp(TRUE, SS_OPERATION, NULL);
        }
        else if(cm_p->ucm_operation == MMI_GSM_UCM_HOLD_AND_DIAL)
        {
            mmi_gsm_hold_and_dial_rsp(TRUE, SS_OPERATION, NULL);
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  PsCbackOutgoingCallIdSync
 * DESCRIPTION
 *  Helper function to get call list from PS to sync with MMI
 *  
 *  DIAL_IND from PS.
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCbackOutgoingCallIdSync(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;
    U16 response;
    U16 count = 0 ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX - In PsCbackOutgoingCallIdSync XXX\n");
    
    if (GetTotalCallCount() > 1)
    {
        SyncCallList();
    }

    handle = DeriveOutgoingCallIdRsp(MsgStruct, &response);
    if (handle == -1 || handle > MAX_CALLS)
    {
        /*Store uid info for UCM release ind*/
        for (count = 0; count < MAX_CALLS; count++)
        {
            if(cm_p->state_info.AllCalls[count].call_handle == MMI_UCM_INVALID_ID)
            {
                cm_p->disc_call.ucm_current_uid.call_id = MMI_UCM_INVALID_ID;
                cm_p->disc_call.ucm_current_uid.group_id = MMI_UCM_INVALID_ID;
                cm_p->disc_call.ucm_current_uid.call_type = GetUCMCallType(cm_p->state_info.AllCalls[count].call_type);            
                cm_p->disc_call.state = cm_p->state_info.AllCalls[count].curr_state; /* add by Tony for VT */

                /*For mmi_gsm_release_ind, call list synchronization*/
                cm_p->state_info.AllCalls[count].group_id = MMI_UCM_INVALID_ID;
            }
        }

        SetCallEndCause(response);

        /*mmi_gsm_release_ind(GetCallEndCause());*/
    
        /*if (GetDialIndication() == TRUE)
        {
            SetCallEndCause(NO_ACTIVE_CALL);
            mmi_gsm_release_ind(GetCallEndCause());
            return;
        }*/

        PRINT_INFORMATION("Error in making outgoing call %d", response);
        /* keep MO fail cause for later display if notify ss is ongoing */

        if (IsRedialSet())
        {
            SetRedialNumber();
        }

        OutgoingProcessCMFailureEvent(CM_PS_CALLCONNECTED, response);
        
    }
    else
    {
        SetOutgoingCallHandle(handle);
        SetDialIndication(TRUE);
        mmi_gsm_sync_call_list_ind();
    }
}


/*****************************************************************************
 * FUNCTION
 *  OutgoingCallConnected
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_CALLCONNECTED
 *  with the Structure containing CM_CALL_HANDLE.
 *  
 *  We could have mapped void* to CM_CALL_HANDLE and passed it to the
 *  state m/c. CONNECT_IND from PS
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains CM_CALL_HANDLE passed by the stack when call is connected)
 * RETURNS
 *  void
 *****************************************************************************/
void OutgoingCallConnected(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CONNECT_IND *msg;
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (MMI_CONNECT_IND*) MsgStruct;

    PRINT_INFORMATION("XXX - In OutgoingCallConnected XXX\n");

    if (CM_CSD_CALL == (msg->call_type))
    {
        SetWapCallPresent(TRUE);
    }

    if (GetOutgoingCallOrigin() == CM_CALL_MO_STK)
    {
        /* STK call doesn't have DIAL_IND, so need to set call id in CONNECT_IND */
        SetOutgoingCallHandle(msg->call_id);
        mmi_gsm_sync_call_list_ind();
    }

    handle = GetOutgoingCallHandle();

    /* log MO call with original number and name */
    SetCalledNumWithTypeAux(GetMMIStructIndexof(handle), MsgStruct);
    
    /* set MO name for display in case number is changed by PS */
    SetCalledNumWithType(GetMMIStructIndexof(handle), MsgStruct);
    
    OutgoingProcessCMEvent(CM_PS_CALLCONNECTED, &handle);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackOutgoingCallEnded
 * DESCRIPTION
 *  Call Back function for ATH_SUCCESS to hangup outgoing call
 *  
 *  ATH_RSP from PS
 * PARAMETERS
 *  MsgStruct       [?]         
 *  expected(?)     [IN]        NULL
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackOutgoingCallEnded(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((handle = GetOutgoingCallHandle()) == -1)
    {
        PRINT_INFORMATION("PsCBackOutgoingCallEnded: The call is already dropped or connected\n");
        if(cm_p->ucm_operation == MMI_GSM_UCM_END_SINGLE)
        {
            SetCallAbortReqSentFlag(FALSE);
            mmi_gsm_end_single_rsp(TRUE, NULL);
        }
        else if(cm_p->ucm_operation == MMI_GSM_UCM_END_ALL)
        {
            SetCallAbortReqSentFlag(FALSE);
            mmi_gsm_end_all_rsp(TRUE, NULL);
        }
        else
        {   
            /*Auto reject*/
            SetCallAbortReqSentFlag(FALSE);
        }
        return;
    }

    OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  PsCBackUSSDResponse
 * DESCRIPTION
 *  This function is called back by the protocol stack when USSD data is recieved by n/w
 *  
 *  info is
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PsCBackUSSDResponse(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX - In PsCBackUSSDResponse XXX\n");
    OutgoingProcessCMEvent(CM_PS_USSD_RECVD, info);
    /* ProcessIncomingEvents (CM_PS_USSD_RECVD, info); */
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_slave_ussd_response
 * DESCRIPTION
 *  This function is called back by the protocol stack when USSD data is recieved by n/w
 *  
 *  info is
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gsm_slave_ussd_response(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION(("mmi_gsm_slave_ussd_response"));
    PsCBackUSSDResponse(info);
    mmi_gsm_set_slave_ss_falg(FALSE);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/* Start by Julia: Drop call refinement */
/*****************************************************************************
 * FUNCTION
 *  ReleaseCall
 * DESCRIPTION
 *  Invokes the helper function to make the disconnecting call released complete
 *  
 *  This is invoked whenever the user press END key in the disconnecting call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReleaseCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MAX_CALLS; count++)
    {
        if (cm_p->state_info.AllCalls[count].curr_state == CM_DISCONNECTING_STATE)
        {
            handle = cm_p->state_info.AllCalls[count].call_handle;
            MakePsReleaseCompleteRequest(handle);
            OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
            if (GetAutoReleaseFlag() == FALSE)
            {
                return;
            }
        }
    }
    SetAutoReleaseFlag(FALSE);
}

/* End by Julia */


/*****************************************************************************
 * FUNCTION
 *  DropRequest
 * DESCRIPTION
 *  Invokes the helper function to hangup or disconnect the call
 *  which is yet to connect.
 *  
 *  This is invoked whenever the User press LSK in the outgoingcallscreen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DropRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In Drop Request\n");

    if (GetNotifySSFlag())
    {
        StopTimer(CM_NOTIFYDURATION_TIMER);
    }

    if (FALSE == GetAbortCallRequestedFlag())
    {
        handle = GetOutgoingCallHandle();
        if ((GetCallflag(handle, TRUE) & CM_HANGUP_REQUESTED) == 0)
        {
            SetDropRequestFlag(TRUE);
            SetAbortCallRequestedFlag(TRUE);
            HangupCall(handle);
            if (GetExitScrnID() == SCR1001_CM_OUTGOINGCALLSCREEN)
            {
                MOMTHideAnimation();
            }
        }
    }
    else
    {
        PRINT_INFORMATION("*** In   DropRequest .. Not calling drop\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  HangupCall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_HANGUPREQ with the OUTGOING_CALL structure.
 *  
 *  This invokes the function to process the CM_KB_HANGUPREQ event in the state m/c.
 * PARAMETERS
 *  CallHandle      [IN]        
 *  contains(?)     [IN]        The call handle of the call that needs to be dropped.
 * RETURNS
 *  void
 *****************************************************************************/
void HangupCall(CM_CALL_HANDLE CallHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("*** In HangupCall\n");
    OutgoingProcessCMEvent(CM_KB_HANGUPREQ, &CallHandle);
}


/*****************************************************************************
 * FUNCTION
 *  HangupReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_HANGUPSUC
 *  with the Structure containing CM_CALL_HANDLE.
 *  
 *  We are assuming that the protocol stack sends the sucess response for the hangup request
 *  with the CM_CALL_HANDLE. CHLD RELEASE_SPECIFIC => RELEASE_IND from PS
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains CM_CALL_HANDLE passed by the stack when call drop is success)
 * RETURNS
 *  void
 *****************************************************************************/
void HangupReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CM_CALL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("XXX - In HangupReqSucess XXX\n");

    handle = DeriveCallHandle(MsgStruct);
    SetCallEndCause(((MMI_RELEASE_IND*) MsgStruct)->cause);

    OutgoingProcessCMEvent(CM_PS_HANGUPSUC, (void*)&handle);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  HangupAll
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_HANGUPALLREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_HANGUPALLREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HangupAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrId;
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = GetAllCallFlags();

#ifdef __MMI_CLAMSHELL__
    if (GetCurrentState() == CM_INCOMING_STATE && GetTotalCallCount() > 1)
    {
        KbCBackCallIncomingRejected();
        return;
    }
#endif /* __MMI_CLAMSHELL__ */ 

    if (GetTotalActiveCallCount() > 0 && GetTotalHoldCallCount() > 0 &&
        ((flag & CM_SWAP_REQUESTED) == 0) && ((flag & CM_CONF_REQUESTED) == 0) && ((flag & CM_ECT_REQUESTED) == 0))
    {
        /* swapping can't decide which call is active and held, 
           issue rel all req instead */

        /* rel active and accept */
        ProcessIncomingEvents(CM_KB_END_ALL_ACTIVE_RETRIEVE_HELD, NULL);
    }
    else
    {
        OutgoingProcessCMEvent(CM_KB_HANGUPALLREQ, (void*)NULL);
    }

    scrId = GetExitScrnID();
    if (scrId == SCR1001_CM_OUTGOINGCALLSCREEN || (scrId == SCR_CM_ACTIVECALLSCREEN && GetTotalCallCount() == 1))
    {
        MOMTHideAnimation();
    }
    /* else
       EntryScr1002ActiveCall(); */

}


/*****************************************************************************
 * FUNCTION
 *  HangupallReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_HANGUPALLSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Hangup all calls request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void HangupallReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMyhandle = DeriveCallHandle(MsgStruct);
    PRINT_INFORMATION("XXX - In HangupallReqSucess XXX\n");
    OutgoingProcessCMEvent(CM_PS_HANGUPALLSUC, (void*)&gMyhandle);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  HangupallActive
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_HANGUPALLACTREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_HANGUPALLACTREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HangupallActive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_HANGUPALLACTREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HangupallActReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_HANGUPALLACTSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Hangup all Active calls
 *  request without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void HangupallActReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMyhandle = DeriveCallHandle(MsgStruct);
    PRINT_INFORMATION("XXX - In HangupallActReqSucess XXX\n");
    OutgoingProcessCMEvent(CM_PS_HANGUPALLACTSUC, (void*)&gMyhandle);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  HangupallHeld
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_HANGUPALLHLDREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_HANGUPALLHLDREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HangupallHeld(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_HANGUPALLHLDREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HangupallHldReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_HANGUPALLHLDSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Hangup all Held calls
 *  request without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void HangupallHldReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gMyhandle = DeriveCallHandle(MsgStruct);
    PRINT_INFORMATION("XXX - In HangupallHldReqSucess XXX\n");
    OutgoingProcessCMEvent(CM_PS_HANGUPALLHLDSUC, (void*)&gMyhandle);
    SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
}


/*****************************************************************************
 * FUNCTION
 *  MakeActiveCallHold
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_HOLDREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_HOLDREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeActiveCallHold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_HOLDREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HoldReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_HOLDSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Hold request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void HoldReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In HoldReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_HOLDSUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in Making Hold call in protocol stack cause %d", result);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ResetHoldFlag();
        OutgoingProcessCMFailureEvent(CM_PS_HOLDSUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  RetrieveHeldCall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_RETRIEVEREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_RETRIEVEREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RetrieveHeldCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_RETRIEVEREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  RetrieveReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_RETRIEVESUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the retrieve request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void RetrieveReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    MMI_CHLD_RSP *chld_rsp = (MMI_CHLD_RSP*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(chld_rsp->opcode != CSMCC_HOLD_ACTIVE_AND_ACCEPT)
    {
        PRINT_INFORMATION("GSM call application:the chld op code:%d is not right",chld_rsp->opcode);
        return;
    }
    
    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In RetrieveReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_RETRIEVESUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in Retriving Hold Call in protocol stack cause %d", result);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ResetRetrieveFlag();
        OutgoingProcessCMFailureEvent(CM_PS_RETRIEVESUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SwapCall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_SWAPREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_SWAPREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SwapCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_SWAPREQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SwapReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_SWAPSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Swap request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void SwapReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    MMI_CHLD_RSP *chld_rsp = (MMI_CHLD_RSP*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(chld_rsp->opcode != CSMCC_SWAP_CALL)
    {
        PRINT_INFORMATION("GSM call application:the chld op code:%d is not right",chld_rsp->opcode);
        return;
    }
    
    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In SwapReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_SWAPSUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in swapping resuest in PS cause: %d\n", result);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ResetSwapFlag();
        OutgoingProcessCMFailureEvent(CM_PS_SWAPSUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ConferenceCall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_CONFREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_CONFREQ event in the state m/c.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConferenceCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetTotalActiveCallCount() < MAX_HOLD) &&
        (GetTotalHoldCallCount() < MAX_HOLD) && ((GetTotalActiveCallCount() > 0 && GetTotalHoldCallCount() > 0)))
    {
        OutgoingProcessCMEvent(CM_KB_CONFREQ, (void*)NULL);
    }
    else
    {
        ShowCallManagementErrorMessage(NO_ACTIVE_CALL, cm_p->ucm_operation);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ConfReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_CONFSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Conference request
 *  without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void ConfReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    MMI_CHLD_RSP *chld_rsp = (MMI_CHLD_RSP*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(chld_rsp->opcode != CSMCC_ADD_HELD_CALL)
    {
        PRINT_INFORMATION("GSM call application:the chld op code:%d is not right",chld_rsp->opcode);
        return;
    }
    
    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In ConfReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_CONFSUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in Conferencing resquest in PS cause: %d\n", result);
        ResetConfFlag();
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        OutgoingProcessCMFailureEvent(CM_PS_CONFSUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SplitCall
 * DESCRIPTION
 *  Helper function to generate Keybrd Event CM_KB_SPLITREQ with the NULL structure.
 *  
 *  This invokes the function to process the CM_KB_SPLITREQ event in the state m/c.
 * PARAMETERS
 *  CallHandle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SplitCall(CM_CALL_HANDLE CallHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_SPLITREQ, &CallHandle);
}


/*****************************************************************************
 * FUNCTION
 *  SplitReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_SPLITSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Split
 *  request without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void SplitReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    MMI_CHLD_RSP *chld_rsp = (MMI_CHLD_RSP*) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(chld_rsp->opcode != CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL)
    {
        PRINT_INFORMATION("GSM call application:the chld op code:%d is not right",chld_rsp->opcode);
        return;
    }

    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In SplitReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_SPLITSUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in Split in protocol stack cause %d", result);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ResetSplitFlag();
        OutgoingProcessCMFailureEvent(CM_PS_SPLITSUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  TransferCall
 * DESCRIPTION
 *  This function performs Explicit Call Transfer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TransferCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OutgoingProcessCMEvent(CM_KB_ECT_REQ, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EctReqSucess
 * DESCRIPTION
 *  Helper function to Generate CM known Stack Event CM_PS_SPLITSUC
 *  with the Structure containing NULL.
 *  
 *  We are assuming that the protocol stack sends the Sucess response for the Split
 *  request without any structure.
 * PARAMETERS
 *  MsgStruct       [?]         
 *  This(?)         [IN]        Contains Null)
 * RETURNS
 *  void
 *****************************************************************************/
void EctReqSucess(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckChldRequestSuccess(MsgStruct, &result))
    {
        PRINT_INFORMATION("XXX - In EctReqSucess XXX\n");
        OutgoingProcessCMEvent(CM_PS_ECT_SUC, (void*)MsgStruct);
    }
    else
    {
        PRINT_INFORMATION("Error in ECT in protocol stack cause %d", result);
        SetProtocolEventHandler(PsCBackNetworkCallDropped, PRT_NWRK_CALL_RELEASE);
        ResetEctFlag();
        OutgoingProcessCMFailureEvent(CM_PS_ECT_SUC, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EnterScreenAndHandleDigit
 * DESCRIPTION
 *  Helper function to initiate sending DTMF tone and
 *  display screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterScreenAndHandleDigit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDtmfBuf();
    SetCMScrnFlag(FALSE);

    if ((GetTotalActiveCallCount() > 0 || GetCurrentState() == CM_OUTGOING_STATE) && (GetDTMFFlag()))
    {
        EntryScrDisplayDialedDigits();
        HandleDTMFScreenDigits();
    }
    else
    {
        EntryScrDisplayDialedDigits();
        UpdateDialedDigitDisplay();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrDisplayDialedDigits
 * DESCRIPTION
 *  Shows the dialled digits in dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrDisplayDialedDigits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *historyBuffer;
    U16 lskStrShow = STR_GLOBAL_SAVE;
    U8 *tmp = GetCurrInputBuffer(DTMF_SCR_DISPLAY_ID);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(DTMF_SCR_DISPLAY_ID, ExitScrDisplayDialedDigits, NULL, NULL);

    cm_p->history_info.IsSave = TRUE;

    if (tmp)
    {
        mmi_ucs2cpy((S8*) UnicodeDTMFPadCallBuffer, (S8*) tmp);
    }
    else
    {
		  memset (UnicodeDTMFPadCallBuffer, 0, sizeof (UnicodeDTMFPadCallBuffer));
    }

    historyBuffer = GetCurrGuiBuffer(DTMF_SCR_DISPLAY_ID);

    /* delete any previous intance of screen if present */
    if (GetCurrScrnId() != DTMF_SCR_DISPLAY_ID)
    {
        DeleteScreenIfPresent(DTMF_SCR_DISPLAY_ID);
    }

    if ((GetCurrScrnId() == SCR1001_CM_OUTGOINGCALLSCREEN && GetTotalCallCount() == 1) || EmergencyCallPresent())
    {
        lskStrShow = 0;
        SetNoSave();
    }

    if (lskStrShow != 0)
    {
        RegisterInputBoxEmptyFunction(DialDigitScreenEmpty);
        RegisterInputBoxNotEmptyFunction(DialDigitScreenNotEmpty);
    }
    else
    {
        /* no icon, no center key */
    #if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
    #if defined  (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
        SetDialingKeypadCallHandler(UI_dummy_function);
        SetDialingKeypadPhonebookHandler(UI_dummy_function);
    #else /* defined  (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    	ResetCenterSoftkey();
    #endif /* defined  (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    #endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
    }

    ShowCategory16Screen(
        lskStrShow,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) UnicodeDTMFPadCallBuffer,
        MAX_DIGIT,
        historyBuffer);
    wgui_save_key_handlers();

    /* LSK, RSK */
    SetCategory16RightSoftkeyFunction(CheckBeforeGoBackHistory, KEY_EVENT_UP);

    if (lskStrShow != 0)
    {
        SetLeftSoftkeyFunction(CallMgmtSavePhoneBook, KEY_EVENT_UP);
    }

    /* SEND, END key */
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        if (GetTotalCallCount() == 1)
        {
            SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
        }
        else
        {
        #ifdef __MMI_CLAMSHELL__
            SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
        #else 
            SetKeyHandler(KbCBackEndAllCallsExceptIncoming, KEY_END, KEY_EVENT_DOWN);
        #endif 
        }

    }
    else if (CM_IDLE_STATE != GetCurrentState())
    {
        SetKeyHandler(HangupAll, KEY_END, KEY_EVENT_DOWN);
    }

    /* group key */
    if ((GetTotalActiveCallCount() > 0 || GetCurrentState() == CM_OUTGOING_STATE) && (GetDTMFFlag()))
    {
        SetGroupKeyHandler(HandleDTMFScreenDigits, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
        SetGroupKeyHandler(HandleDTMFScreenStopTone, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_UP);
        SetGroupKeyHandler(NULL, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_REPEAT);
    }
    else
    {
        SetGroupKeyHandler(
            UpdateDialedDigitDisplay,
            (PU16) CMIdleScreenDigits,
            MAX_CM_SCREEN_DIGITS - 1,
            KEY_EVENT_DOWN);
        SetGroupKeyHandler(NULL, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_REPEAT);
    }

    /* side key */
    SetSideVolumeKeysForCM();
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrDisplayDialedDigits
 * DESCRIPTION
 *  Shows the dialed digits in dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrDisplayDialedDigits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_p->history_info.IsSave)
    {
        history Scr1001;

        Scr1001.scrnID = DTMF_SCR_DISPLAY_ID;
        Scr1001.entryFuncPtr = EntryScrDisplayDialedDigits;
        mmi_ucs2cpy((S8*) Scr1001.inputBuffer, (S8*) UnicodeDTMFPadCallBuffer);
        GetCategoryHistory(Scr1001.guiBuffer);
        AddHistory(Scr1001);
    }
    else
    {
        cm_p->history_info.IsSave = TRUE;
    }

    if (GetDTMFKeyUpFlag() == TRUE)
    {
        HandleDTMFScreenStopTone();
    }

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined  (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(UI_dummy_function);
#else 
    ResetCenterSoftkey();
#endif 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 

}


/*****************************************************************************
 * FUNCTION
 *  DialDigitScreenEmpty
 * DESCRIPTION
 *  register function when screen is empty for call deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialDigitScreenEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    /* grey call, phb icon */
    SetDialingKeypadCallHandler(UI_dummy_function);
    SetDialingKeypadPhonebookHandler(mmi_phb_list_enter_first_from_active_call);
#else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    SetCenterSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
}


/*****************************************************************************
 * FUNCTION
 *  DialDigitScreenNotEmpty
 * DESCRIPTION
 *  register function when screen is not empty for call deflection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialDigitScreenNotEmpty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(MakeCallFromDTMFScr,KEY_EVENT_DOWN);
#else	/* __MERCURY_MASTER__ */
    SetKeyHandler(MakeCallFromDTMFScr, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */
#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(MakeCallFromDTMFScr);
    SetDialingKeypadPhonebookHandler(mmi_phb_list_enter_first_from_active_call);
#else /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 

#ifdef __MMI_DUAL_SIM_MASTER__
     MTPNP_PFAL_CC_SetCenterFunc(MakeCallFromDTMFScr);
     SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else  /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(MakeCallFromDTMFScr, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */ 
}

/**************************************************************

   FUNCTION NAME     : StoreAndKeepKeyCode

   PURPOSE           : Helper to store current key press

   INPUT PARAMETERS  : void

   OUTPUT PARAMETERS : nil

   RETURNS           : void

   REMARKS           : This is needed since the key repeat event rewrites it in the framework

**************************************************************/
/*
 * void StoreAndKeepKeyCode (U16 keycode, U16 keytype)
 * {
 * curKeyCode = keycode;
 * curKeyType = keytype;
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  InCallSSCParsing
 * DESCRIPTION
 *  Helper function to check if the string is IMEI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InCallSSCParsing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 stringIMEI[20];
    S8 newstringIMEI[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) stringIMEI, "*#06#");
    mmi_asc_to_ucs2((PS8) newstringIMEI, (PS8) stringIMEI);

    if (mmi_ucs2cmp((S8*) newstringIMEI, (S8*) UnicodeDTMFPadCallBuffer) == 0)
    {
        SSCHandleIMEI();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_valid_dtmf_key
 * DESCRIPTION
 *  Helper function to make an send dtmf tones over the network or
 *  dial a call in case of user clicking send
 * PARAMETERS
 *  keycode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL is_valid_dtmf_key(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_CM_SCREEN_DIGITS; i++)
    {
        if (keycode == CMIdleScreenDigits[i])
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HandleDTMFScreenDigits
 * DESCRIPTION
 *  Helper function to make an send dtmf tones over the network or
 *  dial a call in case of user clicking send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleDTMFScreenDigits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n **** HandleDTMFScreenDigits\n");
    PRINT_INFORMATION("\n **** Sending DTMF Tone\n");
    /* SetProtocolEventHandler(DtmfSendSuccess, PRT_DTMF_START_RES); */

    SetDTMFKeyUpFlag(TRUE);

    GetkeyInfo(&keycode, &keytype);
    /* StoreAndKeepKeyCode(keycode, keytype); */

    /* enter dial pad from New Call menu item */
    if (!IsScreenPresent(SCR1003_CM_ACTIVECALLOPTIONS) && is_valid_dtmf_key(keycode))
    {
        MuteOnMicrophone();
    #ifdef __MMI_WGUI_CSK_ENABLE__
        if (keycode != KEY_CSK)
    #endif 
            MakePsSendDTMFTone(&keycode);
    }
    wgui_execute_key_handler(keycode, keytype);
}


/*****************************************************************************
 * FUNCTION
 *  UpdateDialedDigitDisplay
 * DESCRIPTION
 *  Helper function to update dial screen with only digits
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateDialedDigitDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    /* StoreAndKeepKeyCode(keycode, keytype); */
    wgui_execute_key_handler(keycode, keytype);
    HandleDisplayDialedDigits();
    InCallSSCParsing();
}


/*****************************************************************************
 * FUNCTION
 *  HandleDTMFScreenStopTone
 * DESCRIPTION
 *  Helper function to make an send dtmf tones over the network or
 *  dial a call in case of user clicking send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleDTMFScreenStopTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n **** HandleDTMFScreenStopTone\n");

    MakePsStopDTMFTone();
    if (IsPhoneInMute() == MMI_FALSE)
    {
        MuteOffMicrophone();
    }
    HandleDisplayDialedDigits();
    SetDTMFKeyUpFlag(FALSE);

    GetkeyInfo(&keycode, &keytype);
    /* StoreAndKeepKeyCode(keycode, keytype); */
    wgui_execute_key_handler(keycode, keytype);
    InCallSSCParsing();
}


/*****************************************************************************
 * FUNCTION
 *  HandleDisplayDialedDigits
 * DESCRIPTION
 *  Handles drawing of category screen and display digits
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleDisplayDialedDigits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetTotalActiveCallCount() > 0 || GetCurrentState() == CM_OUTGOING_STATE) && (GetDTMFFlag()))
    {
        SetGroupKeyHandler(HandleDTMFScreenDigits, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
        SetGroupKeyHandler(HandleDTMFScreenStopTone, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_UP);
        SetGroupKeyHandler(MMI_dummy_function, (PU16) CMIdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_REPEAT);
    }
    else
    {
        /* wgui_execute_key_handler(curKeyCode, curKeyType); */
        SetGroupKeyHandler(
            UpdateDialedDigitDisplay,
            (PU16) CMIdleScreenDigits,
            MAX_CM_SCREEN_DIGITS - 1,
            KEY_EVENT_DOWN);
    }

	if (GetCurrentState() != CM_OUTGOING_STATE && !EmergencyCallPresent())
	{
    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_CC_HandleSendKeys(MakeCallFromDTMFScr,KEY_EVENT_DOWN);
    #else	/* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(MakeCallFromDTMFScr, KEY_SEND, KEY_EVENT_DOWN);
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
	}
    if (GetCurrentState() == CM_INCOMING_STATE)
    {
        if (GetTotalCallCount() == 1)
        {
            SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
        }
        else
        {
        #ifdef __MMI_CLAMSHELL__
            SetKeyHandler(KbCBackCallIncomingRejected, KEY_END, KEY_EVENT_DOWN);
        #else 
            SetKeyHandler(KbCBackEndAllCallsExceptIncoming, KEY_END, KEY_EVENT_DOWN);
        #endif 
        }

    }
    else if (CM_IDLE_STATE == GetCurrentState())
    {
        SetKeyHandler(CheckBeforeGoBackHistory, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        SetKeyHandler(HangupAll, KEY_END, KEY_EVENT_DOWN);
    }

    RegisterCategory16NavigationKeys();

    SetLeftSoftkeyFunction(CallMgmtSavePhoneBook, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(CheckBeforeGoBackHistory, KEY_EVENT_UP);

    SetSideVolumeKeysForCM();
}


/*****************************************************************************
 * FUNCTION
 *  MakeCallFromDTMFScr
 * DESCRIPTION
 *  Clear the DTMF buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCallFromDTMFScr(void)
{
#ifdef __MMI_TOUCH_DIAL_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no input */
    if (UnicodeDTMFPadCallBuffer[0] == 0 && UnicodeDTMFPadCallBuffer[1] == 0)
    {
        return;
    }
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 
    SetDialedDigitCalledFlag(TRUE);
    MakeCall(UnicodeDTMFPadCallBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  CallMgmtSavePhoneBook
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CallMgmtSavePhoneBook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCMScrnFlag(FALSE);
    SaveNumberFromIdleScrn(UnicodeDTMFPadCallBuffer, 0);
}


/*****************************************************************************
 * FUNCTION
 *  ClearDtmfBuf
 * DESCRIPTION
 *  Clear the DTMF buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearDtmfBuf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(UnicodeDTMFPadCallBuffer, 0, sizeof(UnicodeDTMFPadCallBuffer));
    memset(DTMFPadCallBuffer, 0, sizeof(DTMFPadCallBuffer));
}


/*****************************************************************************
 * FUNCTION
 *  FillDtmfBuff
 * DESCRIPTION
 *  Fills up DTMF Buffer for access later
 * PARAMETERS
 *  buf     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FillDtmfBuff(PU8 buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(UnicodeDTMFPadCallBuffer, (void*)buf);
}


/*****************************************************************************
 * FUNCTION
 *  GetDtmfBuffer
 * DESCRIPTION
 *  Return the DTMF buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
PU8 GetDtmfBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(DTMFPadCallBuffer, UnicodeDTMFPadCallBuffer);
    return (PU8) DTMFPadCallBuffer;
}


/*****************************************************************************
 * FUNCTION
 *  SetDialIndication
 * DESCRIPTION
 *  to set the dial indication flag as per argument
 * PARAMETERS
 *  truth       [IN]        
 *  TRUE(?)     [IN]        /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetDialIndication(pBOOL truth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCheckDialIndEndOutgoing = truth;
}


/*****************************************************************************
 * FUNCTION
 *  GetDialIndication
 * DESCRIPTION
 *  To Get the dial indication flag
 * PARAMETERS
 *  void
 *  TRUE(?)     [IN]        /FALSE
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetDialIndication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCheckDialIndEndOutgoing;
}

#ifdef MMI_ON_HARDWARE_P
/*****************************************************************************
 * FUNCTION
 *  MakeCallReqInd
 * DESCRIPTION
 *  Helper function to make call when PRT_MMI_MAKE_CALL_REQ_IND comes.
 * PARAMETERS
 * MsgStruct(?)       [IN]        Which needs to make the outgoing call.              
 * RETURNS
 *  void
 *****************************************************************************/
void MakeCallReqInd(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("XXX - In MakeCallReqInd XXX\n");

    MakeCall((PS8)((MMI_MAKE_CALL_REQ_IND*) MsgStruct)->strNumber);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gsm_check_number_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_gsm_check_number_validation(S8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (strNumber[pos] != '\0')
    {
        if((strNumber[pos] == '+') ||
           (strNumber[pos] == '*') ||
           (strNumber[pos] == '#') ||
           (strNumber[pos] == 'p') ||
           (strNumber[pos] == 'w') ||
           ((strNumber[pos] >= '0') && (strNumber[pos] <= '9')))
        {
            pos += 2;
        }
        else
        {
            return MMI_FALSE;
        }        
    }
	return MMI_TRUE;
}

#endif /* MMI_ON_HARDWARE_P */
#endif /* __MMI_UCM__ */
