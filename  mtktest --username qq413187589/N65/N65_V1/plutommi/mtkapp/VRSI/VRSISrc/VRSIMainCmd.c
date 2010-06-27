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
 * VRSIMainCmd.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the main recognition handling and error handling of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSIMAINCMD_C
#define _MMI_VRSIMAINCMD_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "SettingProfile.h"
#include "IdleAppDef.h"
#include "worldclock.h"
#include "PhonebookDef.h"
#include "CallManagementGProt.h"
#include "SSCStringHandle.h"
#include "ProfileGProts.h"
#include "gpioInc.h"

#if defined(__FLIGHT_MODE_SUPPORT__)
#include "SimDetectionGprot.h"
#endif 

#if defined(__MMI_BT_SUPPORT__)
#include "BTMMIScrGProts.h"
#endif 

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

#include "USBDeviceGprot.h"

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
vrsi_context_struct g_vrsi_cntx;    /* Global Context */

#if defined(__MMI_BT_SUPPORT__)
static BOOL g_vrsi_init_by_bt;
static void (*g_vrsi_bt_tts_callback) (void);
static U16 g_vrsi_bt_tts_string_id;
#endif /* defined(__MMI_BT_SUPPORT__) */ 

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

/* 
 * Global Function
 */

#define MMI_VRSI_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init
 * DESCRIPTION
 *  This function init VRSI related settings at bootup time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_grammar_init();
    mmi_vrsi_setting_init();

    /* Init global context */
    g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_CMD_NOT_READY;
    g_vrsi_cntx.sdtag_sync = 0;

#if defined(__MMI_BT_SUPPORT__)
    SetProtocolEventHandler(mmi_vrsi_bt_set_ind_hdlr, PRT_MMI_L4_BT_SET_VR_REQ_IND);
    SetProtocolEventHandler(mmi_vrsi_bt_set_rsp_hdlr, PRT_MMI_L4_BT_SET_VR_RSP);
    g_vrsi_init_by_bt = FALSE;
#endif /* defined(__MMI_BT_SUPPORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_add_all
 * DESCRIPTION
 *  This function begin to add dynamic central at bootup time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_add_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_ADD_ALL, g_vrsi_cntx.vrsi_state);

#if defined(__MMI_VRSI_TRAIN_TAG__)
    /* Check if SIM card changed for SD tags. */
    if (mmi_vrsi_ndial_central_check_sim_change())
    {
        return;
    }
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_CMD_NOT_READY || g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_PAUSE)
    {
        /* Check if all phonebook entry read and ready to add. */
        if (!mmi_vrsi_ndial_central_phb_ready())
        {
            return;
        }

        /* Show Processing Screen */
        mmi_vrsi_entry_init_processing();

        /* Init SI engine */
        result = mdi_audio_vrsi_init(mmi_vrsi_mdi_callback_hdlr);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_MDI_INIT_RESULT, result);

        if (result != MED_RES_OK)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSI_INIT_FAIL),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        /*
         *  Add dynamic tags for grammar 1
         */

        /* Resume from Pause */
        if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_PAUSE)
        {
            g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_ADDING_CMD;
            mmi_vrsi_init_central_add_req();
        }
        /* Add all central command */
        else
        {

            /* Reset all central command for Grammar 1 before add. */
        #if defined(__MMI_VRSI_TRAIN_TAG__)
            mmi_vrsi_init_central_sync_tag();
        #else 
            media_aud_vrsi_reset_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1]);
        #endif 

            /* Reset flag and protocol handler and add all. */
            g_vrsi_cntx.central_count = 0;
            g_vrsi_cntx.central_fail = 0;   /* Use this flag to check if there are any central command not added. */
            g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_ADDING_CMD;
            SetProtocolEventHandler(mmi_vrsi_ndial_central_add_all, PRT_MMI_VRSI_ADD_CENTRAL_REQ);
            mmi_vrsi_init_central_add_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_add_req
 * DESCRIPTION
 *  Send out message to VRSI itself then add central command.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_add_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = PRT_MMI_VRSI_ADD_CENTRAL_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_abort
 * DESCRIPTION
 *  This function abort add dynamic central command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_ABORT, g_vrsi_cntx.vrsi_state);

    /* Stop adding central command because of change */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_CMD || g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
        mdi_audio_vrsi_close();
    }

    g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_CMD_NOT_READY;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_reset
 * DESCRIPTION
 *  This function abort add dynamic central command and reset some flags.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_RESET, g_vrsi_cntx.vrsi_state);

    mmi_vrsi_init_central_abort();
    g_vrsi_cntx.sdtag_sync = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_change_language_reset
 * DESCRIPTION
 *  This function re-add central command when change language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_change_language_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_CHANGE_LANG_RESET, g_vrsi_cntx.vrsi_state);

    /* Not init yet, wait phonebook ready to add central command */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_CMD_NOT_READY)
    {
        return;
    }

    mmi_vrsi_init_central_abort();
    /* mmi_vrsi_init_central_add_all(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_done
 * DESCRIPTION
 *  Add dynamic central command finish.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_ADD_DONE, g_vrsi_cntx.central_fail);

    ClearProtocolEventHandler(PRT_MMI_VRSI_ADD_CENTRAL_REQ);

    /* Callback function that will do something after init, so don't close SI engine yet. */
    if (g_vrsi_cntx.init_callback != NULL)
    {
        g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_RUNNING;
        g_vrsi_cntx.init_callback();
        g_vrsi_cntx.init_callback = NULL;

        return;
    }

    /* Close SI engine */
    g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_IDLE;
    mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    mdi_audio_vrsi_close();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_count_fail
 * DESCRIPTION
 *  Count number of add failed central command and print the trace.
 * PARAMETERS
 *  tag_num         [IN]        Number of total tag
 *  id_list         [IN]        Add id result
 *  long_list       [IN]        Original command id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_count_fail(U16 tag_num, U16 *id_list, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < tag_num; i++)
    {
        if (id_list[i] == 0xffff)
        {
            g_vrsi_cntx.central_fail++;
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_CMD_FAIL, long_list[i], g_vrsi_cntx.central_fail);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_init_central_sync_tag
 * DESCRIPTION
 *  This function keep SD tags and reset all SI tags at bootup time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_init_central_sync_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id_list[MMI_VRSI_MAX_SD_TAG];
    U8 sync_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i, j, tag_num = 0;
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read out mapping table and build ID list */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if (tag_list[i].tag_id != 0xffff)
        {
            id_list[tag_num] = tag_list[i].tag_id;
            tag_num++;
        }
    }

    /* keep SD tags and remove SI tags */
    if (tag_num > 0)
    {
        result = media_aud_vrsi_sync_db(
                    MOD_MMI,
                    (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                    tag_num,
                    id_list,
                    NULL,
                    sync_list);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_CENTRAL_SYNC_TAG, result);

        /* Remove tag_id mapping that does not in engine */
        for (i = 0; i < tag_num; i++)
        {
            if (!sync_list[i])
                for (j = 0; j < MMI_VRSI_MAX_SD_TAG; j++)
                {
                    if (tag_list[j].tag_id == id_list[i])
                    {
                        memset(&tag_list[j], 0xff, sizeof(vrsi_sd_tag_struct));
                        break;
                    }
                }
        }

        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }
    else    /* Reset All Tags */
    {
        media_aud_vrsi_reset_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_init_processing
 * DESCRIPTION
 *  Entry vrsi init processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_init_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_VRSI_INIT_PROCESSING, mmi_vrsi_exit_init_processing, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        STR_ID_VRSI_INIT_PROCESSING,
        IMG_PROCESSING_PHONEBOOK,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);

    g_vrsi_cntx.is_abort = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_init_processing
 * DESCRIPTION
 *  Exit vrsi processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_init_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.is_abort)
    {
        mmi_vrsi_rcg_close();
        return;
    }

    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_RCG_MAIN ||
        scr_id == SCR_ID_VRSI_TRAIN_OPTION_MAIN ||
        scr_id == SCR_ID_VRSI_TRAIN_OPTION_ADD_PROMPT || scr_id == SCR_ID_VRSI_DIGIT_ADAPT)
    {
        return;
    }

    mmi_vrsi_rcg_close();
}

#define MMI_VRSI_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_pre_entry
 * DESCRIPTION
 *  Check if voice recognition turn on before init engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    if (g_vrsi_cntx.rcg_enable)
    {
        /* Inform bluetooth that VR is activated by phone */
    #if defined(__MMI_BT_SUPPORT__)
        mmi_vrsi_bt_set_req(TRUE);
    #endif 

        /* just in order to exit previous screen */
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        ShowCategoryDummyScreen();
        
        /* Init VR procedure */
        mmi_vrsi_rcg_init(mmi_vrsi_entry_rcg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_init
 * DESCRIPTION
 *  Init VRSI engine.
 * PARAMETERS
 *  entry_func      [IN]        Callback function after initialize engine.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_init(void (*entry_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.init_callback = NULL;

    /* Get the current language for this VR session. */
    mmi_vrsi_util_get_curr_language();

    if (g_vrsi_cntx.vrsi_state < MMI_VRSI_STATE_IDLE)
    {
        /* Init VRSI at first time usage, callback function after init. */
        g_vrsi_cntx.init_callback = entry_func;
        mmi_vrsi_init_central_add_all();
    }
    else if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_IDLE)
    {
        /* Init SI engine */
        result = mdi_audio_vrsi_init(mmi_vrsi_mdi_callback_hdlr);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_MDI_INIT_RESULT, result);

        if (result == MED_RES_OK)
        {
            g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_RUNNING;
            if (entry_func != NULL)
            {
                entry_func();
            }
        }
        else    /* VR Init fail */
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSI_INIT_FAIL),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
    else if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        /* Engine still running, no need to init again. */
        if (entry_func != NULL)
        {
            entry_func();
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_rcg
 * DESCRIPTION
 *  Entry voice recognition main screen. It will also pause backgroupd play here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Suspend all background play during vrsi session */
    mdi_audio_suspend_background_play();
    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_RCG_MAIN, mmi_vrsi_exit_rcg, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_ID_VRSI_HELP,               /* LSK STR */
        0,                              /* LSK IMG */
        STR_GLOBAL_ABORT,               /* RSK STR */
        0,                              /* RSK IMG */
        STR_ID_VRSI_GRAMMAR1_PROMPT,    /* message id */
        IMG_ID_VRSI_RECORDING,          /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_entry_help, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_1;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NONE;
    g_vrsi_cntx.post_cmd = 0;                       /* No Post cmd */

#if defined(__MMI_BT_SUPPORT__)
    /* Connect sco link before playing TTS */
    if (mmi_profiles_bt_connect_sco(mmi_vrsi_bt_connect_sco_hdlr))
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_profiles_bt_disable_sco_timeout();
    #endif
        g_vrsi_bt_tts_callback = mmi_vrsi_rcg_start_command;
        g_vrsi_bt_tts_string_id = STR_ID_VRSI_GRAMMAR1_PROMPT;
    }
    else
#endif /* defined(__MMI_BT_SUPPORT__) */ 
    {
        mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_GRAMMAR1_PROMPT), mmi_vrsi_rcg_start_command);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_rcg
 * DESCRIPTION
 *  Exit voice recognition main screen. It will close engine if next screen is not in VR scenario.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If next screen is not VRSI grammar 1 result screen, abort and leave VR-Session */
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) ||
        (scr_id == SCR_ID_VRSI_DIGIT_DIAL_MAIN) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD) ||
        (scr_id == SCR_ID_VRSI_NAME_QUERY_LIST1) ||
        (scr_id == SCR_ID_VRSI_REDIAL_PROMPT) ||
        (scr_id == SCR_ID_VRSI_SWITCH_PROFILE_PROMPT) ||
        (scr_id == SCR_ID_VRSI_OPEN_SCUT_PROMPT) || (scr_id == SCR_ID_WC_BROWSE_CITY))
    {
        return;
    }

    mmi_vrsi_rcg_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_abort
 * DESCRIPTION
 *  Abort VR session. Just go back to previous screen. The Exit function will close engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.is_abort = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_close
 * DESCRIPTION
 *  Close VRSI engine. It will also try to resume back ground play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_CLOSE, g_vrsi_cntx.vrsi_state, g_vrsi_cntx.session_id);

    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_IDLE;
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
        mdi_audio_vrsi_close();

        /* Inform bluetooth that VR is deactivated by phone */
    #if defined(__MMI_BT_SUPPORT__)
        mmi_vrsi_bt_set_req(FALSE);
    #endif 

    }
    else if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_CMD)
    {
        g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_ADDING_PAUSE;
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
        mdi_audio_vrsi_close();

        /* Inform bluetooth that VR is deactivated by phone */
    #if defined(__MMI_BT_SUPPORT__)
        mmi_vrsi_bt_set_req(FALSE);
    #endif 
    }

#if defined(__MMI_BT_SUPPORT__)
#ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_profiles_bt_enable_sco_timeout();
#else
        mmi_profiles_bt_disconnect_sco();
#endif
#endif /* defined(__MMI_BT_SUPPORT__) */ 

    /* Resume background play when vrsi finish */
    if (!isInCall())
    {
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_start_command
 * DESCRIPTION
 *  Start voice recognition session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_start_command(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        result = media_aud_vrsi_start_cmd_rcg(
                    MOD_MMI,
                    g_vrsi_cntx.session_id,
                    (U8*) g_vrsi_grammar[g_vrsi_cntx.curr_grammar]);

        if (result == MED_RES_OK)
        {
            return;
        }
    }

    DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_play_prompt_tone
 * DESCRIPTION
 *  Play prompt tone. After the tone, user can begin to speak command.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_play_prompt_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_string(
        (void*)g_vrsi_prompt_tone,
        mmi_vrsi_get_prompt_tone_size(),
        MDI_FORMAT_WAV,
        DEVICE_AUDIO_PLAY_ONCE,
        NULL,
        mmi_vrsi_rcg_play_prompt_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_play_prompt_callback
 * DESCRIPTION
 *  After play prompt tone, send confirm message to engine to receive voice.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_play_prompt_callback(mdi_result event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event == MDI_AUDIO_END_OF_FILE)
    {
        media_aud_vrsi_prompt_cnf(MOD_MMI, g_vrsi_cntx.session_id);
    }
    else    /* Prompt tone does not end properly */
    {
        /* pop-up error message, engine will close in exit screen after popup */
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_result
 * DESCRIPTION
 *  Read the voice recognition result and pass to different grammar to handle the result.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_vrsi_cntx.curr_grammar)
    {
        case MMI_VRSI_GRAMMAR_DIGIT:
            mmi_vrsi_ddial_read_result();
            break;
        case MMI_VRSI_GRAMMAR_1:
            mmi_vrsi_rcg_read_grammar1_result();
            break;
        case MMI_VRSI_GRAMMAR_2:
            mmi_vrsi_rcg_read_grammar2_result();
            break;
        case MMI_VRSI_GRAMMAR_3:
            mmi_vrsi_rcg_read_grammar3_result();
            break;
        case MMI_VRSI_GRAMMAR_4:
            mmi_vrsi_rcg_read_grammar4_result();
            break;
        case MMI_VRSI_GRAMMAR_5:
            mmi_vrsi_rcg_read_grammar5_result();
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_check_vaild_mode
 * DESCRIPTION
 *  Check if the command is vaild in the flight mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_rcg_check_vaild_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dial  command  is not support in flight mode */
#if defined(__FLIGHT_MODE_SUPPORT__)
    if (mmi_bootup_get_active_flight_mode())
    {
        mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_TTS_INVALID_CMD), GoBackHistory);
        return FALSE;
    }
#endif /* defined(__FLIGHT_MODE_SUPPORT__) */ 
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_grammar1_result
 * DESCRIPTION
 *  Handle the voice recognition result of grammar 1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_grammar1_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_cmd_rcg_result_struct rcg_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_cmd_rcg_result(&rcg_result);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_GRAMMAR1_RESULT, rcg_result.res_type, rcg_result.pre_cmd,
               rcg_result.post_cmd, rcg_result.tag_num);

    /* remove illegal central commands */
    mmi_vrsi_util_check_legal_central_cmd(&rcg_result);

    /* Single Command */
    if (rcg_result.res_type == 1)
    {
        switch (rcg_result.pre_cmd)
        {
            case VRSI_CMD1_EXIT:
                GoBackHistory();
                return;
            case VRSI_CMD1_DIGIT_DIAL:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                g_vrsi_cntx.retry = 0;
                mmi_vrsi_rcg_init(mmi_vrsi_entry_ddial_rcg);
                return;
            case VRSI_CMD1_HELP:
                mmi_vrsi_entry_help();
                return;
            case VRSI_CMD1_REDIAL_RECEIVED:
            case VRSI_CMD1_REDIAL_MISSED:
            case VRSI_CMD1_REDIAL_DIALED:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                mmi_vrsi_redial_rcg_grammar1_result(rcg_result.pre_cmd);
                return;

            default:
                break;
        }
    }
    /* Pre-command + Central Command */
    if (rcg_result.res_type == 2)
    {
        switch (rcg_result.pre_cmd)
        {
            case VRSI_CMD1_NAME_DIAL:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                mmi_vrsi_ndial_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                return;
            case VRSI_CMD1_NAME_QUERY:
                mmi_vrsi_nquery_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                return;
            case VRSI_CMD1_OPEN:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                mmi_vrsi_scut_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                return;
            case VRSI_CMD1_SWITCH:
                mmi_vrsi_prf_rcg_grammar1_result((U16) rcg_result.long_list[0]);
                return;
            default:
                break;
        }
    }
    /* Pre-command + Central Command + Post Command */
    else if (rcg_result.res_type == 3)
    {
        switch (rcg_result.pre_cmd)
        {
            case VRSI_CMD1_NAME_DIAL:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                if ((rcg_result.post_cmd >= VRSI_CMD1_MOBILE) && (rcg_result.post_cmd <= VRSI_CMD1_FAX))
                {
                    g_vrsi_cntx.post_cmd = rcg_result.post_cmd - VRSI_CMD1_MOBILE + VRSI_CMD2_MOBILE;
                    mmi_vrsi_ndial_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                    return;
                }
                else    /* Other post command */
                {
                    /* Play prompt TTS for not found */
                    mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_RCG_NOT_FOUND), mmi_vrsi_entry_rcg);
                    return;
                }
                break;
            case VRSI_CMD1_NAME_QUERY:
                if (rcg_result.post_cmd == VRSI_CMD1_TIME)
                {
                    mmi_vrsi_city_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                }
                else
                {
                    mmi_vrsi_nquery_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                }
                return;
            case VRSI_CMD1_OPEN:    /* Treat "Open" as type 2, ignore post command */
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                mmi_vrsi_scut_rcg_grammar1_result(rcg_result.tag_num, rcg_result.long_list);
                return;
            case VRSI_CMD1_SWITCH:    /* Treat "Switch" as type 2, ignore post command */
                mmi_vrsi_prf_rcg_grammar1_result((U16) rcg_result.long_list[0]);
                return;

            default:
                break;
        }
    }

    DisplayPopup(
        (U8*) GetString(STR_ID_VRSI_RCG_NOT_FOUND),
        IMG_GLOBAL_ERROR,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_grammar2_result
 * DESCRIPTION
 *  Handle the voice recognition result of grammar 2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_grammar2_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_cmd_rcg_result_struct rcg_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_cmd_rcg_result(&rcg_result);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_GRAMMAR2_RESULT, rcg_result.res_type, rcg_result.pre_cmd,
               rcg_result.post_cmd, rcg_result.tag_num);

    /* Single Command */
    if (rcg_result.res_type == 1)
    {
        if (rcg_result.pre_cmd == VRSI_CMD2_EXIT)
        {
            GoBackHistory();
        }
        else if (rcg_result.pre_cmd < VRSI_CMD2_MAX)
        {
            if (g_vrsi_cntx.loc_num[rcg_result.pre_cmd - VRSI_CMD2_MOBILE])
            {
                g_vrsi_cntx.post_cmd = rcg_result.pre_cmd;
                g_vrsi_cntx.retry = 0;
                mmi_vrsi_entry_ndial_confirm_dial();
            }
            else
            {
                S8 str_prompt[60 * ENCODING_LENGTH];

                if (rcg_result.pre_cmd == VRSI_CMD2_MOBILE)
                {
                    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
                }
                else if (rcg_result.pre_cmd == VRSI_CMD2_HOME)
                {
                    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
                }
                else if (rcg_result.pre_cmd == VRSI_CMD2_BUSINESS)
                {
                    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
                }
                else if (rcg_result.pre_cmd == VRSI_CMD2_FAX)
                {
                    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
                }

                mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_TTS_NUMBER_NO_DATA));

                /* Play prompt TTS */
                mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_ndial_multiple_number);

                g_vrsi_cntx.retry = 0;
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_grammar3_result
 * DESCRIPTION
 *  Handle the voice recognition result of grammar 3.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_grammar3_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_cmd_rcg_result_struct rcg_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_cmd_rcg_result(&rcg_result);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_GRAMMAR3_RESULT, rcg_result.res_type, rcg_result.pre_cmd,
               rcg_result.post_cmd, rcg_result.tag_num);

    /* Single Command */
    if (rcg_result.res_type == 1)
    {
        if (rcg_result.pre_cmd == VRSI_CMD3_EXIT)
        {
            GoBackHistory();
        }
        else if (rcg_result.pre_cmd < VRSI_CMD3_MAX)
        {
            S32 long_list[1];
            U8 num = rcg_result.pre_cmd - VRSI_CMD3_1ST + 1;

            if (num <= g_vrsi_cntx.long_list_num)
            {
                long_list[0] = (S32) g_vrsi_cntx.long_list[num - 1];
                mmi_vrsi_ndial_rcg_grammar1_result(1, long_list);
            }
            else    /* No record, speak again */
            {
                S8 str_prompt[60 * ENCODING_LENGTH];
                S8 ascii_num[2];
                S8 ucs2_num[4];

                sprintf(ascii_num, "%d", num);
                mmi_asc_to_ucs2(ucs2_num, ascii_num);

                mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_TTS_RECORD));
                mmi_ucs2cat(str_prompt, ucs2_num);
                mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_TTS_RECORD_NO_DATA));

                /* Play prompt TTS */
                mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_ndial_multiple_record);

                g_vrsi_cntx.retry = 0;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_grammar4_result
 * DESCRIPTION
 *  Handle the voice recognition result of grammar 4.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_grammar4_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_cmd_rcg_result_struct rcg_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_cmd_rcg_result(&rcg_result);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_GRAMMAR4_RESULT, rcg_result.res_type, rcg_result.pre_cmd,
               rcg_result.post_cmd, rcg_result.tag_num);

    /* Single Command */
    if (rcg_result.res_type == 1)
    {
        switch (rcg_result.pre_cmd)
        {
            case VRSI_CMD4_EXIT:
                GoBackHistory();
                return;
            case VRSI_CMD4_CONFIRM:
                if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_DIGIT_DIAL)
                {
                    mmi_vrsi_ddial_dial_number();
                }
                else if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_NAME_DIAL)
                {
                    mmi_vrsi_ndial_dial_entry();
                }
                return;
            case VRSI_CMD4_REENTRY:
                if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_DIGIT_DIAL)
                {
                    g_vrsi_cntx.retry = 0;
                    mmi_vrsi_rcg_init(mmi_vrsi_entry_ddial_rcg);
                }
                else if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_NAME_DIAL)
                {
                    mmi_vrsi_rcg_init(mmi_vrsi_entry_rcg);
                }
                return;
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_read_grammar5_result
 * DESCRIPTION
 *  Handle the voice recognition result of grammar 5.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_read_grammar5_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_cmd_rcg_result_struct rcg_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vrsi_read_cmd_rcg_result(&rcg_result);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RCG_GRAMMAR5_RESULT, rcg_result.res_type, rcg_result.pre_cmd,
               rcg_result.post_cmd, rcg_result.tag_num);

    /* Single Command */
    if (rcg_result.res_type == 1)
    {
        switch (rcg_result.pre_cmd)
        {
            case VRSI_CMD5_EXIT:
                GoBackHistory();
                break;
            case VRSI_CMD5_SELECT:
                mmi_vrsi_nquery_pre_entry_option();
                break;
            case VRSI_CMD5_REENTRY:
                g_vrsi_cntx.retry = 0;
                mmi_vrsi_rcg_init(mmi_vrsi_entry_rcg);
                break;
            case VRSI_CMD5_PREVIOUS:
                mmi_vrsi_nquery_goto_previous();
                break;
            case VRSI_CMD5_NEXT:
                mmi_vrsi_nquery_goto_next();
                break;
            case VRSI_CMD5_DIAL:
                if (!mmi_vrsi_rcg_check_vaild_mode())
                {
                    return;
                }

                mmi_vrsi_nquery_pre_dial();
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_help
 * DESCRIPTION
 *  Entry help screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buffer;
    S32 bufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = GetString(STR_ID_VRSI_HELP_PROMPT);
    bufferSize = mmi_ucs2strlen(buffer);

    EntryNewScreen(SCR_ID_VRSI_HELP, NULL, mmi_vrsi_entry_help, NULL);

    ShowCategory74Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,                  /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_BACK,    /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) buffer,       /* message id */
        bufferSize,         /* icon id */
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define MMI_VRSI_CALLBACK_RESULT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_mdi_callback_hdlr
 * DESCRIPTION
 *  This function handle the engine call back for different function
 * PARAMETERS
 *  result      [IN]        engine callback result enum.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_mdi_callback_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_MDI_CALLBACK_HDLR, result, g_vrsi_cntx.vrsi_state);

    /* Do not handle any callback result after MMI close engine. */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_IDLE)
    {
        return;
    }

    switch (result)
    {
        case MED_VRSI_RECOG_MPR:
        case MED_VRSI_DIGIT_RECOG_MPR:
            mmi_vrsi_rcg_play_prompt_tone();
            break;
        case MED_VRSI_RECOG_OK:
        case MED_VRSI_DIGIT_RECOG_OK:
            mmi_vrsi_rcg_read_result();
            break;
    #if defined(__MMI_VRSI_DIGIT_ADAPT__)
        case MED_VRSI_DIGIT_ADAPT_MPR:
            mmi_vrsi_entry_digit_adapt_prompt();
            break;
        case MED_VRSI_DIGIT_ADAPT_OK:
            mmi_vrsi_digit_adapt_result();
            break;
    #endif /* defined(__MMI_VRSI_DIGIT_ADAPT__) */ 
    #if defined(__MMI_VRSI_TRAIN_TAG__)
        case MED_VRSI_TRAIN_TAG_1ST_MPR:
            mmi_vrsi_entry_train_option_add_prompt(1);
            break;
        case MED_VRSI_TRAIN_TAG_2ND_MPR:
            mmi_vrsi_entry_train_option_add_prompt(2);
            break;
        case MED_VRSI_TRAIN_TAG_OK:
            mmi_vrsi_train_option_add_result();
            break;
    #endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 
        case MED_VRSI_TTS_OK:
        case MED_VRSI_PLAY_TAG_OK:
            if (g_vrsi_cntx.tts_callback != NULL)
            {
                g_vrsi_cntx.tts_callback();
            }
            break;

        case MED_VRSI_ERROR:
            mmi_vrsi_result_error_hdlr();
            break;
        default:    /* other error */
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ERROR),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_result_error_hdlr
 * DESCRIPTION
 *  This function handle the engine call back for error handling.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_result_error_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_vrsi_get_error_msg();

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_RESULT_ERROR_HDLR, result, g_vrsi_cntx.curr_scenario,
               g_vrsi_cntx.curr_grammar);

    /*
     *  Recognition Fial
     */
    if (result == MED_RES_VRSI_ERR_CMD_RCG_FAIL)
    {

        if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_NONE)
        {
            g_vrsi_cntx.curr_scenario = VRSI_CMD1_EXIT;

            /* Play prompt TTS */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_TTS_INVALID_CMD), GoBackHistory);

            return;
        }
        else if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_DIGIT_DIAL)
        {
            mmi_vrsi_rcg_fail_retry(mmi_vrsi_entry_ddial_dial_confirm, mmi_vrsi_entry_ddial_dial_confirm_in_history);
            return;
        }
        else if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_NAME_DIAL)
        {
            if (g_vrsi_cntx.curr_grammar == MMI_VRSI_GRAMMAR_3)
            {
                mmi_vrsi_rcg_fail_retry(
                    mmi_vrsi_entry_ndial_multiple_record,
                    mmi_vrsi_entry_ndial_multiple_record_in_history);
                return;
            }
            else if (g_vrsi_cntx.curr_grammar == MMI_VRSI_GRAMMAR_2)
            {
                mmi_vrsi_rcg_fail_retry(
                    mmi_vrsi_entry_ndial_multiple_number,
                    mmi_vrsi_entry_ndial_multiple_number_in_history);
                return;
            }
            else if (g_vrsi_cntx.curr_grammar == MMI_VRSI_GRAMMAR_4)
            {
                mmi_vrsi_rcg_fail_retry(
                    mmi_vrsi_entry_ndial_confirm_dial,
                    mmi_vrsi_entry_ndial_confirm_dial_in_history);
                return;
            }
        }
        else if (g_vrsi_cntx.curr_scenario == VRSI_CMD1_NAME_QUERY)
        {
            mmi_vrsi_rcg_fail_retry(mmi_vrsi_pre_entry_nquery_list, mmi_vrsi_entry_nquery_list1_in_history);
            return;
        }

        GoBackHistory();
    }
    /*
     *  Train tag fail, Digit adapt Fail
     */
    if (result == MED_RES_VRSI_ERR_CMD_TRN_FAIL || result == MED_RES_VRSI_ERR_DGT_ADP_FAIL || result == MED_RES_VRSI_ERR_UNKNOWN)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    /*
     *   Unknown error
     */
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    /*
     * MED_RES_VRSI_OK, 
     * MED_RES_VRSI_ERR_UNINITIALIZED,
     * MED_RES_VRSI_ERR_BUSY,
     * MED_RES_VRSI_ERR_MEM_INSUFFICIENT,
     * MED_RES_VRSI_ERR_DATA_ERROR,   
     * MED_RES_VRSI_ERR_LIBRARY_CORRUPT,
     * MED_RES_VRSI_ERR_BAD_GRAMMAR,
     * MED_RES_VRSI_ERR_LANG_NOT_SUPPORT,
     * MED_RES_VRSI_ERR_NO_MATCH_TAG,
     * MED_RES_VRSI_ERR_TTS_TOO_LONG,
     * MED_RES_VRSI_ERR_SESSION,
     * MED_RES_VRSI_ERR_NO_SOUND,
     * MED_RES_VRSI_ERR_CMD_TRN_FAIL,
     * MED_RES_VRSI_ERR_CMD_RCG_FAIL,
     * MED_RES_VRSI_ERR_DGT_RCG_FAIL,
     * MED_RES_VRSI_ERR_DGT_ADP_FAIL,
     * MED_RES_VRSI_ERR_UNKNOWN, 
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_rcg_fail_retry
 * DESCRIPTION
 *  This function will execute retry function if retry times less than the limitation.
 *  Or it will execute timeout function.
 * PARAMETERS
 *  retry_func          [IN]        retry function
 *  timeout_func        [IN]        timeout function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_rcg_fail_retry(void (*retry_func) (void), void (*timeout_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.retry <= MMI_VRSI_MAX_RETRY)
    {
        mmi_vrsi_rcg_init(retry_func);
    }
    else
    {
        g_vrsi_cntx.curr_scenario = VRSI_CMD1_EXIT;

        /* Play prompt TTS and entry screen again */
        mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_TTS_OPERATE_BY_KEY), timeout_func);
    }
}

#define MMI_VRSI_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_util_play_tts
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  tts_string          [?]             
 *  tts_callback        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsi_util_play_tts(U16 *tts_string, void (*tts_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.tts_callback = tts_callback;

    /* Use english as default language */
    if (g_vrsi_cntx.lang == MED_VRSI_INVALID_LANG)
    {
        g_vrsi_cntx.lang = MED_VRSI_AMERICAN_LANG;
    }

    g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

    mdi_audio_vrsi_play_TTS(
        g_vrsi_cntx.session_id,
        tts_string,
        (U8) GetRingVolumeLevel(),
        MDI_DEVICE_SPEAKER2 /* MDI_DEVICE_SPEAKER_BOTH */ ,
        g_vrsi_cntx.lang);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_util_play_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  grammar_id          [IN]            
 *  app_id              [IN]            
 *  tag_long            [IN]            
 *  tts_callback        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
S32 mmi_vrsi_util_play_tag(U8 grammar_id, U8 app_id, U16 tag_long, void (*tts_callback) (void))
{
#if defined(__MMI_VRSI_TRAIN_TAG__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vrsi_train_util_get_id_and_loc(app_id, tag_long, &tag_id) != 0xff) 
    {
        g_vrsi_cntx.tts_callback = tts_callback;
        g_vrsi_cntx.session_id = media_aud_vrsi_new_session_id();
        result = mdi_audio_vrsi_play_tag(
                    g_vrsi_cntx.session_id,
                    (U8*)g_vrsi_grammar[grammar_id],
                    tag_id,
                    (U8) GetRingVolumeLevel(),
                    MDI_DEVICE_SPEAKER2 /* MDI_DEVICE_SPEAKER_BOTH */ );
        return result;
    }
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_util_play_name_tag
 * DESCRIPTION
 *  This function is used to play the tag of name in phonebook.
 * PARAMETERS
 *  grammar_id          [IN]            
 *  app_id              [IN]            
 *  tag_long            [IN]            
 *  tts_callback        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
S32 mmi_vrsi_util_play_name_tag(U8 grammar_id, U8 app_id, U16 tag_long, void (*tts_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id == MMI_VRSI_APP_DIAL)
    {
#if defined (__MMI_VRSI_TRAIN_TAG__)
        if (mmi_vrsi_train_util_get_id_and_loc(app_id, tag_long, &tag_id) == 0xff)
#endif
        {
            media_aud_vrsi_query_tag_id((U8*)g_vrsi_grammar[grammar_id], (U32)tag_long, &tag_id);
            while (tag_id >= MMI_VRSI_MAX_TAG_ID)
            {
                if (media_aud_vrsi_query_next_tag_id((U8*)g_vrsi_grammar[grammar_id], &tag_id) !=
                    MED_RES_VRSI_OK)
                {
                    return -1;
                }
            }
        }
        
        g_vrsi_cntx.tts_callback = tts_callback;
        g_vrsi_cntx.session_id = media_aud_vrsi_new_session_id();
        result = mdi_audio_vrsi_play_tag(
                    g_vrsi_cntx.session_id,
                    (U8*)g_vrsi_grammar[grammar_id],
                    tag_id,
                    (U8) GetRingVolumeLevel(),
                    MDI_DEVICE_SPEAKER2 /* MDI_DEVICE_SPEAKER_BOTH */ );
        
        return result;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_util_check_legal_central_cmd
 * DESCRIPTION
 *  Filter illegal central command.
 * PARAMETERS
 *  rcg_result_p		[IN/OUT]		recognition result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_util_check_legal_central_cmd(media_aud_vrsi_cmd_rcg_result_struct* rcg_result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int id_counter = 0;

    U16 *name_list[MMI_VRSI_MAX_RCG_RESULT];
    U16 id_list[MMI_VRSI_MAX_RCG_RESULT];

    S32 long_list[MMI_VRSI_MAX_RCG_RESULT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((rcg_result_p->res_type==2) || (rcg_result_p->res_type==3))
    {
        if (rcg_result_p->pre_cmd == VRSI_CMD1_NAME_DIAL)
        {
            for (i=0; i<rcg_result_p->tag_num; i++)
            {
                if ((rcg_result_p->long_list[i]<MMI_VRSI_CMD_PROFILE_BASE) &&
                    (rcg_result_p->long_list[i]>=0))
                {
                    id_list[id_counter] = rcg_result_p->id_list[i];
                    long_list[id_counter] = rcg_result_p->long_list[i];
                    name_list[id_counter] = rcg_result_p->name_list[i];
                    id_counter++;
                }
            }
        }
        else if (rcg_result_p->pre_cmd == VRSI_CMD1_NAME_QUERY)
        {
            for (i=0; i<rcg_result_p->tag_num; i++)
            {
                if (((rcg_result_p->long_list[i]<MMI_VRSI_CMD_PROFILE_BASE) && (rcg_result_p->long_list[i]>=0)) || 
                    (rcg_result_p->long_list[i]>=MMI_VRSI_CMD_CITY_BASE))
                {
                    id_list[id_counter] = rcg_result_p->id_list[i];
                    long_list[id_counter] = rcg_result_p->long_list[i];
                    name_list[id_counter] = rcg_result_p->name_list[i];
                    id_counter++;
                }
            }
        }
        else if (rcg_result_p->pre_cmd == VRSI_CMD1_OPEN)
        {
            for (i=0; i<rcg_result_p->tag_num; i++)
            {
                if ((rcg_result_p->long_list[i]>=MMI_VRSI_CMD_SCUT_BASE) &&
                    (rcg_result_p->long_list[i]<MMI_VRSI_CMD_CITY_BASE))
                {
                    id_list[id_counter] = rcg_result_p->id_list[i];
                    long_list[id_counter] = rcg_result_p->long_list[i];
                    name_list[id_counter] = rcg_result_p->name_list[i];
                    id_counter++;
                }
            }
        }
        else if (rcg_result_p->pre_cmd == VRSI_CMD1_SWITCH)
        {
            for (i=0; i<rcg_result_p->tag_num; i++)
            {
                if ((rcg_result_p->long_list[i]>=MMI_VRSI_CMD_PROFILE_BASE) &&
                    (rcg_result_p->long_list[i]<MMI_VRSI_CMD_SCUT_BASE))
                {
                    id_list[id_counter] = rcg_result_p->id_list[i];
                    long_list[id_counter] = rcg_result_p->long_list[i];
                    name_list[id_counter] = rcg_result_p->name_list[i];
                    id_counter++;
                }
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    
    if ((rcg_result_p->tag_num==id_counter) || (id_counter== 0))
    {
        if (id_counter== 0)
        {
            rcg_result_p->tag_num = 1;
        }
        return;
    }

    for (i=0; i<id_counter; i++)
    {
        rcg_result_p->id_list[i] = id_list[i];
        rcg_result_p->long_list[i] = long_list[i];
        rcg_result_p->name_list[i] = name_list[i];
    }

    rcg_result_p->tag_num = id_counter;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_util_get_curr_language
 * DESCRIPTION
 *  Get the current language of system.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_util_get_curr_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get Current Language Mode */
    if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE))
    {
        g_vrsi_cntx.lang = MED_VRSI_TAIWAN_LANG;
    }
    else if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE))
    {
        g_vrsi_cntx.lang = MED_VRSI_CHINA_LANG;
    }
    else if (!strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH))
    {
        g_vrsi_cntx.lang = MED_VRSI_AMERICAN_LANG;
    }
    else
    {
        g_vrsi_cntx.lang = MED_VRSI_INVALID_LANG;
    }
}

#define MMI_VRSI_BLUETOOTH_AT
#if defined(__MMI_BT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_bt_set_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_bt_set_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_req_ind_struct *local_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_p = (mmi_l4_bt_set_vr_req_ind_struct*) msg;

    /* Activate VR */
    if (local_p->on_off)
    {
        /* Check if in USB mode before enter VR */
    #if defined(__USB_IN_NORMAL_MODE__)
        if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);

            mmi_vrsi_bt_set_ind_cnf(FALSE);
            g_vrsi_init_by_bt = FALSE;
            return;
        }
    #endif /* defined(__USB_IN_NORMAL_MODE__) */

        /* If VR is turned on and not in call, init VR procedure */
        if (g_vrsi_cntx.rcg_enable &&
            (isInCall() == 0) &&
            (GetActiveScreenId() == IDLE_SCREEN_ID) &&
            (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_IDLE || g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_CMD_NOT_READY))
        {
            mmi_vrsi_bt_set_ind_cnf(TRUE);
            g_vrsi_init_by_bt = TRUE;

            mmi_vrsi_rcg_init(mmi_vrsi_entry_rcg);
        }
        else
        {
            mmi_vrsi_bt_set_ind_cnf(FALSE);
            g_vrsi_init_by_bt = FALSE;
        }
    }
    /* Deactivate VR */
    else
    {
        g_vrsi_init_by_bt = FALSE;

        if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING || g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_CMD)
        {
            mmi_vrsi_bt_set_ind_cnf(TRUE);

            g_vrsi_cntx.is_abort = TRUE;
            GoBackHistory();
        }
        else
        {
            mmi_vrsi_bt_set_ind_cnf(TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_bt_set_ind_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_bt_set_ind_cnf(BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *msg_p;
    MYQUEUE message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    if (success)
    {
        msg_p->result = KAL_TRUE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
    }

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_L4C;
    message.oslMsgId = MSG_ID_MMI_AT_GENERAL_RES_REQ;
    message.oslDataPtr = (oslParaType*) msg_p;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_bt_set_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_activate     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_bt_set_req(BOOL is_activate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_req_struct *msg_p;
    MYQUEUE message;
    BOOL vr_on_off = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Activate VR */
    if (is_activate)
    {
        /* Inform bluetooth */
        if (mmi_bt_is_hs_connected())
        {
            vr_on_off = TRUE;
            g_vrsi_init_by_bt = TRUE;
        }
        /* Bluetooth is not connected, no need to inform it */
        else
        {
            g_vrsi_init_by_bt = FALSE;
            return;
        }
    }
    /* Deactivate VR */
    else
    {
        /* Bluetooth exists and VR informed Bluetooth at activate phase */
        if (mmi_bt_is_hs_connected() && g_vrsi_init_by_bt)
        {
            vr_on_off = FALSE;
            g_vrsi_init_by_bt = FALSE;
        }
        else
        {
            return;
        }
    }

    msg_p = (mmi_l4_bt_set_vr_req_struct*) OslConstructDataPtr(sizeof(mmi_l4_bt_set_vr_req_struct));

    if (vr_on_off)
    {
        msg_p->on_off = KAL_TRUE;
    }
    else
    {
        msg_p->on_off = KAL_FALSE;
    }

    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_L4C;
    message.oslMsgId = PRT_MMI_L4_BT_SET_VR_REQ;
    message.oslDataPtr = (oslParaType*) msg_p;
    message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_bt_set_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_bt_set_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4_bt_set_vr_rsp_struct *local_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_p = (mmi_l4_bt_set_vr_rsp_struct*) msg;

    /* Do nothing currently. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_bt_connect_sco_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_bt_connect_sco_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_RUNNING)
    {
        mmi_vrsi_util_play_tts((U16*) GetString(g_vrsi_bt_tts_string_id), g_vrsi_bt_tts_callback);
    }
    g_vrsi_bt_tts_callback = NULL;
    g_vrsi_bt_tts_string_id = 0;
}

#endif /* defined(__MMI_BT_SUPPORT__) */ /* #if defined(__MMI_BT_SUPPORT__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSIMAINCMD_C */ /* #ifndef _MMI_VRSIMAINCMD_C */

