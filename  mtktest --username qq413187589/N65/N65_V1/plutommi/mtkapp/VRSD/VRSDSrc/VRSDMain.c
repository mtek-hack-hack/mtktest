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
 * VRSDMain.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Command
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSDMAIN_C
#define _MMI_VRSDMAIN_C

#if defined(__MMI_VRSD__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "SettingProfile.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDRedial.h"
#include "VRSDProfile.h"
#include "VRSDAudplayer.h"

#include "USBDeviceGprot.h"

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
vrsd_context_struct g_vrsd_cntx;    /* Global Context */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern const U8 g_vrsd_recv_voice_prompt[];

/* 
 * Global Function
 */

#define MMI_VRSD_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clear Variables. */
    mmi_vrsd_clear_rcg_callback();
    g_vrsd_cntx.vrtag_sync = 0;

    ReadValue(NVRAM_VRSD_RCG_SETTING, &g_vrsd_cntx.rcg_enable, DS_BYTE, &pError);

    /* Register Highlight Handler */
    mmi_vrsd_init_highlight_handler();

#if defined(__MMI_VRSD_DIAL__)
    mmi_vrsddial_init();
#endif 

#if defined(__MMI_VRSD_REDIAL__)
    mmi_vrsdredial_init();
#endif 

#if defined(__MMI_VRSD_PROFILE__)
    mmi_vrsdprf_init();
#endif 

#if defined(__MMI_VRSD_AUDPLAYER__)
    mmi_vrsdaudp_init();
#endif 

#if defined(__MMI_VRSD_SHORTCUT__)
    mmi_vrsdscut_init();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_init_highlight_handler
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_APP, mmi_vrsd_highlight_main_menu);

    /* For Main Menu */
    SetHiliteHandler(MENU_ID_VRSD_RCG, mmi_vrsd_highlight_rcg_enable);
    SetHintHandler(MENU_ID_VRSD_RCG, mmi_vrsd_hint_rcg_enable);
    SetHiliteHandler(MENU_ID_VRSD_DELETE_ALL, mmi_vrsd_highlight_delete_all);
    SetHiliteHandler(MENU_ID_VRSD_STATUS, mmi_vrsd_highlight_status);
}

#define MMI_VRSD_MAIN_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_vrsd_main_menu_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_main_menu_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_main_menu_pre_entry
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_main_menu_pre_entry(void)
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

    /* Synchronize with file system for first time entry. */
    mmi_vrsd_sync_tag_with_db();
    mmi_vrsd_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MMI_VRSD_APP_TOTAL + 5];
    U16 nNumofItem;
    U8 *hintList[MMI_VRSD_APP_TOTAL + 5];   /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_MAIN_MENU, mmi_vrsd_exit_main_menu, mmi_vrsd_entry_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_MAIN_MENU);    /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSD_MAIN_MENU);
    GetSequenceStringIds(MENU_ID_VRSD_MAIN_MENU, nStrItemList);
    SetParentHandler(MENU_ID_VRSD_MAIN_MENU);

    RegisterHighlightHandler(mmi_vrsd_main_menu_highlight_hdlr);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_VRSD_MAIN_MENU, hintList);

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_VRSD_APP,
        IMG_ID_VRSD_APP,
        STR_GLOBAL_ON,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_exit_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_main_menu_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  hiliteid        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_main_menu_highlight_hdlr(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);

    ExecuteCurrHiliteHandler(hiliteid);
}

#define MMI_VRSD_RCG_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_rcg_enable
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_highlight_rcg_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.rcg_enable)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    SetLeftSoftkeyFunction(mmi_vrsd_rcg_enable_switch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_hint_rcg_enable
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_hint_rcg_enable(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.rcg_enable)
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
 *  mmi_vrsd_rcg_enable_switch
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_rcg_enable_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.rcg_enable)
    {
        g_vrsd_cntx.rcg_enable = 0;
        msg = STR_GLOBAL_OFF;
    }
    else
    {
        g_vrsd_cntx.rcg_enable = 1;
        msg = STR_GLOBAL_ON;
    }

    /* Write Back To NVRAM */
    WriteValue(NVRAM_VRSD_RCG_SETTING, &g_vrsd_cntx.rcg_enable, DS_BYTE, &pError);

    DisplayPopup((U8*) GetString(msg), IMG_GLOBAL_ACTIVATED, TRUE, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
}

#define MMI_VRSD_TRAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id              [IN]            
 *  appref_id           [IN]            
 *  trn_callback        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_train_init(U8 app_id, U16 appref_id, void (*trn_callback) (U8))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Suspend all background play during receiving voice */
    mdi_audio_suspend_background_play();

    /* Get session id and initial vr engine */
    g_vrsd_cntx.session_id = media_aud_vr_new_session_id();
    result = media_aud_vr_init_trn(
                MOD_MMI,
                g_vrsd_cntx.session_id,
                MED_VR_ISD_MODE,
                MED_VR_NO_CARE_LANG,
                MMI_VRSD_GROUP_ALL,
                g_vrsd_cntx.vrtag_id);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_TRAIN_INIT, app_id, appref_id, g_vrsd_cntx.session_id, result);

    if (result == MED_RES_OK)
    {
        g_vrsd_cntx.trn_callback = trn_callback;
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_TRN_VOICE_IN_FIRST;        /* For traing 1st time */
        g_vrsd_cntx.app_id = app_id;
        g_vrsd_cntx.appref_id = appref_id;
        mmi_vrsd_entry_recv_voice();
    }
    else    /* Init fail */
    {
        if (result == MED_RES_BUSY) /* To avoid server hang in busy state. */
        {
            mdi_audio_vr_abort();
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

        trn_callback(MMI_VRSD_TRN_FAIL);    /* Callback application init fail handling. */

        /* Resume all background after init fail */
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_result_ind
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_train_result_ind(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_TRAIN_RESULT_IND, result);

    /* Training stage 1 Success */
    if (result == MED_RES_TRAINING_CONTINUE && g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST)
    {
        /* Check session id consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_trn_session_id())
        {
            g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSD_WRONG_SESSION),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_TRN_VOICE_IN_SECOND;
        mmi_vrsd_entry_recv_voice();
    }
    /* Training success, Note that Cyberon train twice, other may train only once */
    else if (result == MED_RES_OK)
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

        /* Check session id consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_trn_session_id())
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSD_WRONG_SESSION),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        /* write back to NVRAM */
        mmi_vrsd_train_success();

        g_vrsd_cntx.trn_callback(MMI_VRSD_TRN_SUCCESS);
    }
    else if (result == MDI_AUDIO_TERMINATED)    /* Interrupt */
    {
        if (!g_vrsd_cntx.user_abort)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ABORT),
                IMG_GLOBAL_WARNING,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
    }
    else    /* Error */
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        mmi_vrsd_error_popup((U16) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_success
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_train_success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    tag_list[g_vrsd_cntx.vrtag_id].appref_id = g_vrsd_cntx.appref_id;
    tag_list[g_vrsd_cntx.vrtag_id].app_id = g_vrsd_cntx.app_id;

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);
}

#define MMI_VRSD_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_pre_entry
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_rcg_pre_entry(void)
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

    /* Synchronize with file system for first time login. */
    mmi_vrsd_sync_tag_with_db();

    /* Check if list empty. */
    if (g_vrsd_cntx.rcg_enable)
    {
        if (!mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_ALL))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSD_NO_TAG_EXIST),
                IMG_GLOBAL_WARNING,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            return;
        }

        mmi_vrsd_rcg_init();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_init
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_rcg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Suspend all background play during receiving voice */
    mdi_audio_suspend_background_play();

    /* Get session id and initial vr engine */
    g_vrsd_cntx.session_id = media_aud_vr_new_session_id();
    result = media_aud_vr_init_rcg(
                MOD_MMI,
                g_vrsd_cntx.session_id,
                MED_VR_ISD_MODE,
                MED_VR_NO_CARE_LANG,
                MMI_VRSD_GROUP_ALL);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_RCG_INIT, g_vrsd_cntx.session_id, result);

    if (result == MED_RES_OK)
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_RCG_VOICE_IN;  /* Only one stage for recognition */
        mmi_vrsd_entry_recv_voice();
    }
    else
    {
        if (result == MED_RES_BUSY)
        {
            mdi_audio_vr_abort();
        }

        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);

        /* Resume all background play during receiving voice */
        mdi_audio_resume_background_play();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_rcg_result_ind
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_rcg_result_ind(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *id_array;
    U16 appref_id;
    U8 app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_RCG_RESULT_IND_1, result);

    g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;

    if (result == MED_RES_OK)
    {
        /* Check Session Consistency */
        if (g_vrsd_cntx.session_id != mdi_audio_vr_rcg_session_id())
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSD_WRONG_SESSION),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }

        /* retrieve application ref id from tag id */
        id_array = mdi_audio_vr_rcg_result_id_array();

        g_vrsd_cntx.vrtag_id = id_array[0];
        mmi_vrsd_get_mapping_index(id_array[0], &appref_id, &app_id);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_RCG_RESULT_IND_2, g_vrsd_cntx.vrtag_id, app_id, appref_id);

        /* Match Voice Tag, Call Application registered callback function. */
        if ((appref_id != 0xffff) && (app_id < MMI_VRSD_APP_TOTAL))
            if (g_vrsd_cntx.rcg_callback[app_id] != NULL)
            {
                g_vrsd_cntx.rcg_callback[app_id] (appref_id);
                return;
            }

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else if (result == MDI_AUDIO_TERMINATED)    /* Interrupt */
    {
        if (!g_vrsd_cntx.user_abort)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_ABORT),
                IMG_GLOBAL_WARNING,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
    }
    else    /* Error */
    {
        mmi_vrsd_error_popup((U16) result);
    }
}

#define MMI_VRSD_RECEIVE_VOICE


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_recv_voice
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_entry_recv_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 message_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.user_abort = 0;

    if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST || g_vrsd_cntx.vrstage == MMI_VRSD_STATE_RCG_VOICE_IN)
    {
        message_id = STR_ID_VRSD_VOICE_IN;
    }
    else
    {
        message_id = STR_ID_VRSD_VOICE_IN_AGAIN;
    }

    EntryNewScreen(SCR_ID_VRSD_RECV_VOICE, mmi_vrsd_exit_recv_voice, NULL, NULL);

    ShowCategory8Screen(
        STR_ID_VRSD_APP,
        IMG_ID_VRSD_APP,
        0,                      /* LSK STR */
        0,                      /* LSK IMG */
        STR_GLOBAL_ABORT,       /* RSK STR */
        0,                      /* RSK IMG */
        message_id,             /* message id */
        IMG_ID_VRSD_RECORDING,  /* icon id */
        NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);
    //ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    //ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    //ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    //ClearKeyHandler(KEY_END, KEY_REPEAT);

    SetRightSoftkeyFunction(mmi_vrsd_recv_voice_abort, KEY_EVENT_UP);

    /* Start a timer to play prompt tone. */
    StartTimer(VRSD_PLAYTONE_TIMER, MMI_VRSD_PLAY_TONE_DELAY_TIME, mmi_vrsd_recv_voice_prompt_tone);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_exit_recv_voice
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_exit_recv_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_PLAYTONE_TIMER);

    /* Abort engine if next screen ID is not Voice Dial application. */
    scr_id = GetActiveScreenId();
    if (!((scr_id == SCR_ID_VRSD_RCG_FOUND) || (scr_id == SCR_ID_VRSD_RECV_VOICE)))
    {
        g_vrsd_cntx.vrstage = MMI_VRSD_STATE_IDLE;
        mdi_audio_vr_abort();
    }

    /* Resume background play after receiving voice done */
    if (scr_id != SCR_ID_VRSD_RECV_VOICE)
    {
        mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_abort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort engine in exit function. */
    g_vrsd_cntx.user_abort = 1;
    GoBackHistory();
    /* DisplayPopup((U8*)GetString(STR_GLOBAL_ABORT), IMG_GLOBAL_WARNING,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_prompt_tone
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_prompt_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Play Tone, and then record after play finish */

    mdi_audio_play_string(
        (void*)g_vrsd_recv_voice_prompt,
        mmi_vrsd_get_prompt_tone_size(),
        MDI_FORMAT_WAV,
        DEVICE_AUDIO_PLAY_ONCE,
        NULL,
        mmi_vrsd_recv_voice_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_recv_voice_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  event       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_recv_voice_req(mdi_result event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((event == MDI_AUDIO_END_OF_FILE) && (GetActiveScreenId() == SCR_ID_VRSD_RECV_VOICE))
    {
        /* Training 0 : first sampe; 1: second sample */
        if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_FIRST ||
            g_vrsd_cntx.vrstage == MMI_VRSD_STATE_TRN_VOICE_IN_SECOND)
        {
            result = mdi_audio_start_vr_voice_record(
                        g_vrsd_cntx.session_id,
                        (U8) (g_vrsd_cntx.vrstage - 1),
                        NULL,
                        mmi_vrsd_train_result_ind);
        }
        /* Recognition */
        else if (g_vrsd_cntx.vrstage == MMI_VRSD_STATE_RCG_VOICE_IN)
        {
            result = mdi_audio_start_vr_voice_record(g_vrsd_cntx.session_id, 0, NULL, mmi_vrsd_rcg_result_ind);
        }

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_RECV_VOICE_REQ, result);

        if (result != MED_RES_OK)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_VRSD_RECV_VOICE_FAIL),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
    //else
    //   DisplayPopup((U8*)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);

}

#define MMI_VRSD_DELETE_ALL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_delete_all
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsd_entry_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_entry_delete_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_delete_all
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_entry_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 nStrItemList[MMI_VRSD_APP_TOTAL + 1];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_DELETE_ALL, NULL, mmi_vrsd_entry_delete_all, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DELETE_ALL);   /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSD_DELETE_ALL);
    GetSequenceStringIds(MENU_ID_VRSD_DELETE_ALL, nStrItemList);
    SetParentHandler(MENU_ID_VRSD_DELETE_ALL);

    RegisterHighlightHandler(mmi_vrsd_delete_all_highlight_hdlr);

    ShowCategory15Screen(
        STR_ID_VRSD_APP,
        IMG_ID_VRSD_APP,
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

    SetLeftSoftkeyFunction(mmi_vrsd_delete_all_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_delete_all_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  hiliteid        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_delete_all_highlight_hdlr(S32 hiliteid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nMenuItemList[MMI_VRSD_APP_TOTAL + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(MENU_ID_VRSD_DELETE_ALL, nMenuItemList);

    g_vrsd_cntx.app_id = mmi_vrsd_get_appid_by_menuid(nMenuItemList[hiliteid]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_delete_all_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count_list[MMI_VRSD_APP_TOTAL];
    S8 str_cnf[120];
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(count_list, 0, sizeof(U16) * MMI_VRSD_APP_TOTAL);
    mmi_vrsd_get_each_tag_count(count_list);

    if (count_list[g_vrsd_cntx.app_id] != 0)
    {
        mmi_ucs2ncpy(str_cnf, GetString(STR_GLOBAL_DELETE_ALL), 100);
        mmi_ucs2cat(str_cnf, (S8*) L" ");

        str_id = mmi_vrsd_get_strid_by_appid(g_vrsd_cntx.app_id);

        if (str_id != 0)
        {
            mmi_ucs2cat(str_cnf, GetString(str_id));
        }

        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) str_cnf,
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_vrsd_del_all_tag_by_appid, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_WARNING,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

}

#define MMI_VRSD_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_highlight_status
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_highlight_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsd_entry_status, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsd_entry_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_entry_status
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_entry_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 tag_status[256];
    U16 count_list[MMI_VRSD_APP_TOTAL];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tag_status, 0, 256);
    memset(count_list, 0, sizeof(U16) * MMI_VRSD_APP_TOTAL);

    mmi_vrsd_get_each_tag_count(count_list);

    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_TAG_STATUS, count_list[MMI_VRSD_APP_ALL], tag_status);
#if defined(__MMI_VRSD_DIAL__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_DIAL, count_list[MMI_VRSD_APP_DIAL], tag_status);
#endif 
#if defined(__MMI_VRSD_REDIAL__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_REDIAL, count_list[MMI_VRSD_APP_REDIAL], tag_status);
#endif 
#if defined(__MMI_VRSD_PROFILE__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_PROFILE, count_list[MMI_VRSD_APP_PROFILE], tag_status);
#endif 
#if defined(__MMI_VRSD_AUDPLAYER__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_AUD_PLAYER, count_list[MMI_VRSD_APP_AUDPLAYER], tag_status);
#endif 
#if defined(__MMI_VRSD_SHORTCUT__)
    mmi_vrsd_tag_status_print_string(STR_ID_VRSD_SHORTCUT, count_list[MMI_VRSD_APP_SHORTCUT], tag_status);
#endif 

    EntryNewScreen(SCR_ID_VRSD_STATUS, NULL, mmi_vrsd_entry_status, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_STATUS);
    ShowCategory7Screen(
        STR_ID_VRSD_TAG_STATUS,
        IMG_ID_VRSD_APP,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) tag_status,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_tag_status_print_string
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  str_id          [IN]            
 *  count           [IN]            
 *  tag_status      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_tag_status_print_string(U16 str_id, U16 count, S8 *tag_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 tmpStr[20];
    S8 tmpStr_UCS2[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(tag_status, GetString(str_id));
    memset(tmpStr, 0, 20);

    if (str_id == STR_ID_VRSD_TAG_STATUS)
    {
        sprintf(tmpStr, ": %d/%d\n", count, MMI_VRSD_MAX_TAG);
    }
    else
    {
        sprintf(tmpStr, ": %d\n", count);
    }

    mmi_asc_to_ucs2(tmpStr_UCS2, tmpStr);
    mmi_ucs2cat(tag_status, tmpStr_UCS2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_each_tag_count
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  count_list      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_get_each_tag_count(U16 *count_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
    #if defined(__MMI_VRSD_DIAL__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_DIAL) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_DIAL]++;
        }
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_REDIAL) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_REDIAL]++;
        }
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_PROFILE) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_PROFILE]++;
        }
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_AUDPLAYER) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_AUDPLAYER]++;
        }
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        if (((tag_list[i].app_id == MMI_VRSD_APP_SHORTCUT) && (tag_list[i].appref_id != 0xffff)))
        {
            count_list[MMI_VRSD_APP_SHORTCUT]++;
        }
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
    }

    for (i = 1; i < MMI_VRSD_APP_TOTAL; i++)
    {
        count_list[MMI_VRSD_APP_ALL] += count_list[i];
    }

}

#define MMI_VRSD_UTILITY


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_sync_tag_with_db
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_sync_tag_with_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    U16 syn_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i, j;
    U16 syn_length = 0, org_length;
    S32 result;
    BOOL in_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsd_cntx.vrtag_sync != 2)
    {
        /* Retrieve data from NVRAM */
        ReadRecord(
            NVRAM_EF_VRSD_TAG_LID,
            MMI_VRSD_GROUP_ALL,
            (void*)tag_list,
            MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
            &pError);

        /* Build Sync List for MED */
        for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
            if ((tag_list[i].appref_id != 0xffff) && (tag_list[i].app_id != MMI_VRSD_APP_NONE))
            {
                syn_list[syn_length++] = i;
            }

        /* Sync with MED */
        org_length = syn_length;
        result = media_aud_vr_sync_db(
                    MOD_MMI,
                    MED_VR_ISD_MODE,
                    MED_VR_NO_CARE_LANG,
                    MMI_VRSD_GROUP_ALL,
                    &syn_length,
                    (U16*) syn_list);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSD_FUNC_SYNC_TAG_WITH_DB, result, org_length, syn_length);

        /* Sync result from MED if list has changed */
        if ((result == MED_RES_OK) && (org_length != syn_length))
        {
            for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
            {
                in_list = FALSE;
                for (j = 0; j < syn_length; j++)
                {
                    if (i == syn_list[j])
                    {
                        in_list = TRUE;
                        break;
                    }
                }
                if (!in_list)
                {
                    tag_list[i].appref_id = 0xffff;
                    tag_list[i].app_id = MMI_VRSD_APP_NONE;
                }
            }

            WriteRecord(
                NVRAM_EF_VRSD_TAG_LID,
                MMI_VRSD_GROUP_ALL,
                (void*)tag_list,
                MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
                &pError);
        }

        g_vrsd_cntx.vrtag_sync = 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_util_get_tag_id
 * DESCRIPTION
 *  This function is return the voice tag id using application id and application reference id.
 *  If user wants to find an enpty tag, just past MMI_VRSD_APP_NONE and 0xffff
 * PARAMETERS
 *  app_id          [IN]        Application ID of voice control application
 *  appref_id       [IN]        Application Reference ID which maintain by app itself
 * RETURNS
 *  voice tag ID
 *****************************************************************************/
U16 mmi_vrsd_util_get_tag_id(U8 app_id, U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].appref_id == appref_id))
        {
            return i;
        }
    }

    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_util_get_tag_id_in_list
 * DESCRIPTION
 *  This function is return the voice tag id using application id and application reference id.
 *  (Note 1) If user wants to find an enpty tag, just past MMI_VRSD_APP_NONE and 0xffff
 *  (Note 2) User should read the voice tag list before enter this function.
 * PARAMETERS
 *  app_id          [IN]        Application ID of voice control application
 *  appref_id       [IN]        Application Reference ID which maintain by app itself
 *  tag_list        [IN]        Voice Tag List Read outside this function.
 * RETURNS
 *  voice tag ID
 *****************************************************************************/
U16 mmi_vrsd_util_get_tag_id_in_list(U8 app_id, U16 appref_id, vrsd_tag_struct *tag_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if ((tag_list[i].app_id == app_id) && (tag_list[i].appref_id == appref_id))
        {
            return i;
        }
    }

    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_playback_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  tag_id          [IN]            
 *  callback        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_playback_req(U16 tag_id, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        g_vrsd_cntx.play_callback = callback;
        result = mdi_audio_play_voice_tag(
                    MED_VR_ISD_MODE,
                    MED_VR_NO_CARE_LANG,
                    MMI_VRSD_GROUP_ALL,
                    tag_id,
                    NULL,
                    mmi_vrsd_playback_finish);
    }
    else
    {
        result = mdi_audio_play_voice_tag(MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, tag_id, NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_playback_finish
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_playback_finish(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call back is not null and play finish */
    if ((g_vrsd_cntx.play_callback != NULL) && (result == MDI_AUDIO_END_OF_FILE))
    {
        g_vrsd_cntx.play_callback();
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

    g_vrsd_cntx.play_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_total_tag_count
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_total_tag_count(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    U16 i;
    U16 count = 0;
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
        if (((tag_list[i].app_id == app_id) && (tag_list[i].appref_id != 0xffff)) ||
            ((app_id == MMI_VRSD_APP_ALL) && (tag_list[i].appref_id != 0xffff)))
        {
            count++;
        }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_error_popup
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  error_id        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_error_popup(U16 error_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_id)
    {
        case MED_RES_NO_SOUND:
            error_id = STR_ID_VRSD_NO_SOUND;
            break;
        case MED_RES_NO_MATCH:
            error_id = STR_ID_VRSD_NO_MATCH;
            break;
        case MED_RES_TOO_SIMILAR:
            error_id = STR_ID_VRSD_TOO_SIMILAR;
            break;
        case MED_RES_TOO_DIFFERENT:
            error_id = STR_ID_VRSD_TOO_DIFFERENT;
            break;
        case MED_RES_DISC_FULL:
            error_id = STR_ID_VRSD_DISC_FULL;
            break;
        case MED_RES_SPEAK_TOO_LONG:
            error_id = STR_ID_VRSD_SPEAK_TOO_LONG;
            break;
        case MED_RES_SPEAK_TOO_SHORT:
            error_id = STR_ID_VRSD_SPEAK_TOO_SHORT;
            break;
        default:
            error_id = STR_ID_VRSD_RECV_VOICE_FAIL;
            break;
    }
    DisplayPopup((U8*) GetString(error_id), IMG_GLOBAL_ERROR, TRUE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_clear_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_clear_rcg_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VRSD_APP_TOTAL; i++)
    {
        g_vrsd_cntx.rcg_callback[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_register_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id              [IN]            
 *  rcg_callback        [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_register_rcg_callback(U8 app_id, void (*rcg_callback) (U16))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.rcg_callback[app_id] = rcg_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_mapping_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  tag_id          [IN]            
 *  appref_id       [?]             
 *  app_id          [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_get_mapping_index(U16 tag_id, U16 *appref_id, U8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

    if (tag_id < MMI_VRSD_MAX_TAG)
    {
        *appref_id = tag_list[tag_id].appref_id;
        *app_id = tag_list[tag_id].app_id;
    }
    else
    {
        *appref_id = 0xffff;
        *app_id = MMI_VRSD_APP_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_del_tag_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  vrtag_id        [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_del_tag_req(U16 vrtag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, vrtag_id);

    if (result == MED_RES_OK)
    {
        vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
        S16 pError;

        /* Retrieve data from NVRAM */
        ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

        tag_list[vrtag_id].appref_id = 0xffff;
        tag_list[vrtag_id].app_id = MMI_VRSD_APP_NONE;

        WriteRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DELETED),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
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
 *  mmi_vrsd_del_all_tag_by_appid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsd_del_all_tag_by_appid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    S32 result;
    BOOL error = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if (((g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL) && (tag_list[i].appref_id != 0xffff)) ||
            ((tag_list[i].app_id == g_vrsd_cntx.app_id) && (tag_list[i].appref_id != 0xffff)))
        {
            result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, i);

            if (result != MED_RES_OK)
            {
                error = TRUE;
                continue;
            }

            tag_list[i].appref_id = 0xffff;
            tag_list[i].app_id = MMI_VRSD_APP_NONE;
        }
    }

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    /* Reset status flag for some applications */
#if defined(__MMI_VRSD_REDIAL__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_REDIAL)
    {
        mmi_vrsdredial_del_tag_rest_flag();
    }
#endif /* defined(__MMI_VRSD_REDIAL__) */ 
#if defined(__MMI_VRSD_PROFILE__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_PROFILE)
    {
        mmi_vrsdprf_del_tag_reset_flag();
    }
#endif /* defined(__MMI_VRSD_PROFILE__) */ 
#if defined(__MMI_VRSD_AUDPLAYER__)
    if (g_vrsd_cntx.app_id == MMI_VRSD_APP_ALL || g_vrsd_cntx.app_id == MMI_VRSD_APP_AUDPLAYER)
    {
        mmi_vrsdaudp_del_tag_reset_flag();
    }
#endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 

    if (error)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DELETED),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_strid_by_appid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  app_id      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_strid_by_appid(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (app_id)
    {
    #if defined(__MMI_VRSD_DIAL__)
        case MMI_VRSD_APP_DIAL:
            return STR_ID_VRSD_DIAL;
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        case MMI_VRSD_APP_REDIAL:
            return STR_ID_VRSD_REDIAL;
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        case MMI_VRSD_APP_PROFILE:
            return STR_ID_VRSD_PROFILE;
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        case MMI_VRSD_APP_AUDPLAYER:
            return STR_ID_VRSD_AUD_PLAYER;
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        case MMI_VRSD_APP_SHORTCUT:
            return STR_ID_VRSD_SHORTCUT;
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_get_appid_by_menuid
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  menu_id     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_vrsd_get_appid_by_menuid(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
    #if defined(__MMI_VRSD_DIAL__)
        case MENU_ID_VRSD_DELETE_ALL_DIAL:
            return MMI_VRSD_APP_DIAL;
    #endif /* defined(__MMI_VRSD_DIAL__) */ 
    #if defined(__MMI_VRSD_REDIAL__)
        case MENU_ID_VRSD_DELETE_ALL_REDIAL:
            return MMI_VRSD_APP_REDIAL;
    #endif /* defined(__MMI_VRSD_REDIAL__) */ 
    #if defined(__MMI_VRSD_PROFILE__)
        case MENU_ID_VRSD_DELETE_ALL_PROFILE:
            return MMI_VRSD_APP_PROFILE;
    #endif /* defined(__MMI_VRSD_PROFILE__) */ 
    #if defined(__MMI_VRSD_AUDPLAYER__)
        case MENU_ID_VRSD_DELETE_ALL_AUDPLAYER:
            return MMI_VRSD_APP_AUDPLAYER;
    #endif /* defined(__MMI_VRSD_AUDPLAYER__) */ 
    #if defined(__MMI_VRSD_SHORTCUT__)
        case MENU_ID_VRSD_DELETE_ALL_SHORTCUT:
            return MMI_VRSD_APP_SHORTCUT;
    #endif /* defined(__MMI_VRSD_SHORTCUT__) */ 
        default:    /* MENU_ID_VRSD_DELETE_ALL_ALL */
            return MMI_VRSD_APP_ALL;
    }

}
#endif /* defined(__MMI_VRSD__) */ /* #if defined(__MMI_VRSD__) */
#endif /* _MMI_VRSDMAIN_C */ /* #ifndef _MMI_VRSDMAIN_C */

