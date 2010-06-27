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
 * VRSIRedial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for redial of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSIREDIAL_C
#define _MMI_VRSIREDIAL_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "gpioInc.h"

/* ... Add More MMI header */
#include "med_global.h"
#include "med_struct.h"
#include "med_main.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "VRSIResDef.h"
#include "MainMenuDef.h"

/* Call Related */
#include "PhoneBookTypes.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "CallHistoryEnum.h"
#include "CallManagementStruct.h"
#include "CallsLog.h"
#include "CallManagementGprot.h"
#include "AlarmFrameworkProt.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGProt.h"
#include "MTPNP_PFAL_CC.h"
#endif  /*__MMI_DUAL_SIM_MASTER__*/


/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_vrsi_redial_type;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_rcg_grammar1_result
 * DESCRIPTION
 *  This function get redial type by recognition result
 * PARAMETERS
 *  rcg_result      [IN]        Index of recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_rcg_grammar1_result(U16 rcg_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rcg_result == VRSI_CMD1_REDIAL_DIALED)
    {
        g_vrsi_redial_type = PHB_LND;
    }
    else if (rcg_result == VRSI_CMD1_REDIAL_MISSED)
    {
        g_vrsi_redial_type = PHB_LNM;
    }
    else if (rcg_result == VRSI_CMD1_REDIAL_RECEIVED)
    {
        g_vrsi_redial_type = PHB_LNR;
    }

    mmi_vrsi_redial_read_call_log_num_req(g_vrsi_redial_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_read_call_log_num_req
 * DESCRIPTION
 *  This function send request to get call log from L4
 * PARAMETERS
 *  type        [IN]        Call log type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_read_call_log_num_req(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    GET_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_CH_MIXED_CALL_LOG__)
    if (type == PHB_LND)
    {
        chis_p->dialedCalls = (LOG_CALL*) chis_p->callsLog;
    }
    else if (type == PHB_LNM)
    {
        chis_p->missedCalls = (LOG_CALL*) chis_p->callsLog;
    }
    else if (type == PHB_LNR)
    {
        chis_p->recvdCalls = (LOG_CALL*) chis_p->callsLog;
    }
#endif /* !defined(__MMI_CH_MIXED_CALL_LOG__) */ 

    dataPtr = (GET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(GET_LAST_NUMBER_REQ));
    dataPtr->type = type;
    dataPtr->seq_id = 1; /* Only need 1 record, so just get once */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_GET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    if (chis_p->isFirstTime == FALSE)
    {
        AlmDisableExpiryHandler();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    SetProtocolEventHandler(mmi_vrsi_redial_read_call_log_num_rsp, PRT_MMI_PHB_GET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);

    chis_p->isReqSent = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_read_call_log_num_rsp
 * DESCRIPTION
 *  This function get call log response from L4
 * PARAMETERS
 *  info        [IN]        Protocol message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_read_call_log_num_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GET_LAST_NUMBER_RSP *rsp;

    LOG_CALL *redial_call = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (GET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        /* Dialed Number */
        if (rsp->type == PHB_LND)
        {
            redial_call = &chis_p->dialedCalls[0];
        }
        /* Missed Call */
        else if (rsp->type == PHB_LNM)
        {
            redial_call = &chis_p->missedCalls[0];
        }
        /* Received Call */
        else if (rsp->type == PHB_LNR)
        {
            redial_call = &chis_p->recvdCalls[0];
        }

        /* Only handle the first record because we only use first record to redial */
        if ((rsp->no_list > 0) && (redial_call != NULL))
        {
            memset(redial_call, 0, sizeof(LOG_CALL));
            CHISTExtractPSCallLog(redial_call, &rsp->list[0]);

            if (redial_call->numLength > 0)
            {
                mmi_vrsi_entry_redial_dial_prompt();
            }
            else
            {
                mmi_vrsi_redial_no_number();
            }
        }
        else
        {
            mmi_vrsi_redial_no_entry();
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    chis_p->isReqSent = FALSE;

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_dial_prompt_message
 * DESCRIPTION
 *  This function prepare redial prompt message.
 * PARAMETERS
 *  str_prompt      [IN]        Prompt string buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_dial_prompt_message(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LOG_CALL *redial_call = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Append redial type, use first record only */
    if (g_vrsi_redial_type == PHB_LND)
    {
        redial_call = &chis_p->dialedCalls[0];
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == PHB_LNM)
    {
        redial_call = &chis_p->missedCalls[0];
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == PHB_LNR)
    {
        redial_call = &chis_p->recvdCalls[0];
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    mmi_ucs2cat(str_prompt, (S8*) L" ");

    /* Append Name or Number */
    if (mmi_ucs2strlen(redial_call->pbName))
    {
        mmi_ucs2cat(str_prompt, redial_call->pbName);
    }
    else
    {
        mmi_ucs2cat(str_prompt, (S8*) redial_call->number);
    }

    /* Append dialing string */
    mmi_ucs2cat(str_prompt, (S8*) L" ");
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_DIALING_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_redial_dial_prompt
 * DESCRIPTION
 *  This function is entry function of redial prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_redial_dial_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_redial_dial_prompt_message(str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_REDIAL_PROMPT, mmi_vrsi_exit_redial_dial_prompt, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message id */
        0,                  /* icon id */
        NULL);

    SetLeftSoftkeyFunction(mmi_vrsi_redial_dial_number, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_vrsi_redial_dial_number,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_vrsi_redial_dial_number, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_redial_dial_number);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_redial_dial_prompt
 * DESCRIPTION
 *  This function is exit function of redial prompt, it will close engine if leave VR session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_redial_dial_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_rcg_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_dial_number
 * DESCRIPTION
 *  Call call management function and dial out the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_dial_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LOG_CALL *redial_call = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_redial_type == PHB_LND)
    {
        redial_call = &chis_p->dialedCalls[0];
    }
    else if (g_vrsi_redial_type == PHB_LNM)
    {
        redial_call = &chis_p->missedCalls[0];
    }
    else if (g_vrsi_redial_type == PHB_LNR)
    {
        redial_call = &chis_p->recvdCalls[0];
    }

    if (redial_call->numLength)
    {
   	#ifdef __MMI_DUAL_SIM_MASTER__
		mmi_ucm_app_entry_dial_option((U8*)redial_call->number,NULL,NULL);
	#else 
        MakeCall((S8*) redial_call->number);
	#endif /*__MMI_DUAL_SIM_MASTER__*/         
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_no_number
 * DESCRIPTION
 *  no number to dial prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_no_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Append redial type */
    if (g_vrsi_redial_type == PHB_LND)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == PHB_LNM)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == PHB_LNR)
    {
        mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_redial_no_entry
 * DESCRIPTION
 *  Entry function for no redial entry prompt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_redial_no_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[MMI_VRSI_MAX_PROMPT_STR * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_RCG_NOT_FOUND));

    if (g_vrsi_redial_type == PHB_LND)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_DIALED));
    }
    else if (g_vrsi_redial_type == PHB_LNM)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_MISSED));
    }
    else if (g_vrsi_redial_type == PHB_LNR)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_REDIAL_RECEIVED));
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSIREDIAL_C */ /* #ifndef _MMI_VRSIREDIAL_C */

