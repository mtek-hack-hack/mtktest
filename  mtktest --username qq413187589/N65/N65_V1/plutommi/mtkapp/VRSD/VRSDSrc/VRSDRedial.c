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
 * VoiceRedial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Redial.
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
 *------------------------------------------------------------------------------
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VOICEREDIAL_C
#define _MMI_VOICEREDIAL_C

#if defined(__MMI_VRSD__) && defined(__MMI_VRSD_REDIAL__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "MessagesExDcl.h"
#include "SettingProfile.h"
#include "ProtocolEvents.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

/* Call Related */
#include "PhoneBookTypes.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "CallHistoryEnum.h"
#include "CallManagementStruct.h"
#include "CallsLog.h"
#include "CallManagementGprot.h"
#include "AlarmFrameworkProt.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDRedial.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGProt.h"
#include "MTPNP_PFAL_CC.h"
#endif/*__MMI_DUAL_SIM_MASTER__*/
/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_vrsdredial_status = 0;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */

#define MMI_VRSD_REDIAL_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_init
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdredial_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsd_register_rcg_callback(MMI_VRSD_APP_REDIAL, mmi_vrsdredial_rcg_callback);

    mmi_vrsdredial_init_highlight_handler();

    /* Check if voice tag exists. */
    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_REDIAL, 1) != 0xffff)
    {
        g_vrsdredial_status = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_init_highlight_handler
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdredial_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_REDIAL, mmi_vrsdredial_highlight_app);
    SetHintHandler(MENU_ID_VRSD_REDIAL, mmi_vrsdredial_hint_app);

}

#define MMI_VRSD_REDIAL_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_list_playback_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_list_playback_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_REDIAL, 1);
    if (tag_id != 0xffff)
    {
        mmi_vrsd_playback_req(tag_id, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_highlight_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsdredial_status)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vrsdredial_del_tag_confirm, KEY_EVENT_UP);

        /* Play back voice tag */
        StartTimer(VRSD_DIAL_PLAYBACK_TIMER, MMI_VRSD_PLAY_TAG_DELAY, mmi_vrsdredial_list_playback_tag);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vrsdredial_trn_tag, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_hint_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_hint_app(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsdredial_status)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_trn_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_trn_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_NONE, 0xffff)) != 0xffff) /* Use 0xffff as parameter to get "empty tag id" */
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_REDIAL, 1, mmi_vrsdredial_trn_result_callback);
    }
    else    /* No empty tag available */
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSD_NO_EMPTY_TAG),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_trn_result_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_trn_result_callback(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_VRSD_TRN_SUCCESS)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        g_vrsdredial_status = 1;
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        g_vrsdredial_status = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_del_tag_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_del_tag_confirm(void)
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
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_vrsdredial_del_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_del_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_del_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_REDIAL, 1)) != 0xffff)
    {
        mmi_vrsd_del_tag_req(tag_id);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    g_vrsdredial_status = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_del_tag_rest_flag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_del_tag_rest_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsdredial_status = 0;
}

#define MMI_VRSD_REDIAL_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  appref_id       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_rcg_callback(U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* playback */
    mmi_vrsd_playback_req(g_vrsd_cntx.vrtag_id, NULL);

    mmi_vrsdredial_rcg_read_dialed_num_req();
    chis_p->isReqSent = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_rcg_read_dialed_num_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_rcg_read_dialed_num_req(void)
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
    chis_p->dialedCalls = (LOG_CALL*) chis_p->callsLog;
#endif 

    dataPtr = (GET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(GET_LAST_NUMBER_REQ));
    dataPtr->type = PHB_LND;

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

    SetProtocolEventHandler(mmi_vrsdredial_rcg_read_dialed_num_rsp, PRT_MMI_PHB_GET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_rcg_read_dialed_num_rsp
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  info        [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_rcg_read_dialed_num_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GET_LAST_NUMBER_RSP *rsp;
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (GET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        if (rsp->type != PHB_LND)
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        chis_p->nDialedCalls = 0;
        memset((PS8) chis_p->dialedCalls, 0, sizeof(LOG_CALL) * TOT_SIZE_OF_DIALED_LIST);

        for (index = 0; index < rsp->no_list; index++)
        {
            CHISTExtractPSCallLog(&chis_p->dialedCalls[chis_p->nDialedCalls], &rsp->list[index]);
            chis_p->nDialedCalls++;
        }
    }

    chis_p->isReqSent = FALSE;

    if (index != 0)
    {
        mmi_vrsdredial_entry_rcg_found();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_VRSD_REDIAL_CALLLOG_EMPTY),
            IMG_GLOBAL_WARNING,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

    AlmEnableExpiryHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_entry_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_entry_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 str_found[(MAX_PB_NAME_LENGTH + MAX_CC_ADDR_LEN + 30) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->nDialedCalls == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_VRSD_REDIAL_CALLLOG_EMPTY),
            IMG_GLOBAL_WARNING,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_VRSD_RCG_FOUND, mmi_vrsdredial_exit_rcg_found, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_RCG_FOUND);

    /* Print display text */
    mmi_ucs2cpy(str_found, GetString(STR_ID_VRSD_DIAL_FOUND));
    if (chis_p->dialedCalls[0].nameLength)
    {
        mmi_ucs2ncat(str_found, (S8*) chis_p->dialedCalls[0].pbName, chis_p->dialedCalls[0].nameLength);
    }
    mmi_ucs2cat(str_found, (S8*) L"\n");
    if (chis_p->dialedCalls[0].numLength)
    {
        mmi_ucs2ncat(str_found, (S8*) chis_p->dialedCalls[0].number, chis_p->dialedCalls[0].numLength);
    }
    mmi_ucs2cat(str_found, (S8*) L"\n");
    mmi_ucs2cat(str_found, GetString(STR_ID_VRSD_DIAL_AUTO_DIAL));

    ShowCategory66Screen(
        STR_ID_VRSD_REDIAL,
        IMG_ID_VRSD_APP,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_found,    /* message string */
        0,                  /* icon id */
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsdredial_rcg_auto_dial, KEY_EVENT_UP);

    if (guiBuffer == NULL)
    {
        /* Automatically Dial out */
        StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
        StartTimer(VRSD_DIAL_AUTO_DIAL_TIMER, MMI_VRSD_DIAL_OUT_TIME, mmi_vrsdredial_rcg_auto_dial);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_exit_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_exit_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdredial_rcg_auto_dial
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdredial_rcg_auto_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->dialedCalls[0].numLength)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
		mmi_ucm_app_entry_dial_option((U8*)(S8*) chis_p->dialedCalls[0].number,NULL,NULL);
	#else 
        MakeCall((S8*) chis_p->dialedCalls[0].number);
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

#endif /* defined(__MMI_VRSD__) && defined(__MMI_VRSD_REDIAL__) */ /* #if defined(__MMI_VRSD__) && defined(__MMI_VRSD_REDIAL__) */
#endif /* _MMI_VOICEREDIAL_C */ /* #ifndef _MMI_VOICEREDIAL_C */

