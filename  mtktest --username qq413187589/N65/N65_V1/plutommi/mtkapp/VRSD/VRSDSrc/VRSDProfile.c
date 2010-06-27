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
 * VoiceProfile.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Profile Command
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
#ifndef _MMI_VRSDPROFILE_C
#define _MMI_VRSDPROFILE_C

#if defined(__MMI_VRSD__) && defined(__MMI_VRSD_PROFILE__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "MessagesExDcl.h"
#include "SettingProfile.h"
#include "Profiles_prot.h"
#include "ProfileGprots.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDProfile.h"

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
static U8 g_vrsdprf_status = 0; /* Each Bit Represent One Profile */
static U8 g_vrsdprf_curr = 0;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U8 gprofileId;

/* 
 * Global Function
 */

#define MMI_VRSD_PROFILE_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_init
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdprf_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsd_register_rcg_callback(MMI_VRSD_APP_PROFILE, mmi_vrsdprf_rcg_callback);

    mmi_vrsdprf_init_highlight_handler();

    /* Check if voice tag exists. */
    for (i = 0; i < MMI_VRSD_PROFILE_MAX_NUM; i++)
        if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_PROFILE, i) != 0xffff)
        {
            g_vrsdprf_status |= (1 << i);
        }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_init_highlight_handler
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsdprf_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_PROFILE, mmi_vrsdprf_highlight_app);

    /* Set Hint Handler for each menuitem. */
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE1, mmi_vrsdprf_hint_profile);
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE2, mmi_vrsdprf_hint_profile);
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE3, mmi_vrsdprf_hint_profile);
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE4, mmi_vrsdprf_hint_profile);
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE5, mmi_vrsdprf_hint_profile);
    SetHintHandler(MENU_ID_VRSD_PROFILE_MODE6, mmi_vrsdprf_hint_profile);
}

#define MMI_VRSD_PROFILE_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_highlight_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsdprf_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsdprf_entry_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_entry_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 nNumofItem;
    U8 *hintList[10];   /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_PROFILE_MAIN_MENU, mmi_vrsdprf_exit_main_menu, mmi_vrsdprf_entry_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_PROFILE_MAIN_MENU);        /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_VRSD_PROFILE);
    GetSequenceStringIds(MENU_ID_VRSD_PROFILE, nStrItemList);
    SetParentHandler(MENU_ID_VRSD_PROFILE);

    RegisterHighlightHandler(mmi_vrsdprf_highlight_profile);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_VRSD_PROFILE, hintList);

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_VRSD_PROFILE,
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
 *  mmi_vrsdprf_exit_main_menu
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_exit_main_menu(void)
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
 *  mmi_vrsdprf_highlight_profile
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  nIndex      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_highlight_profile(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsdprf_curr = (U8) nIndex;

    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);

    if (g_vrsdprf_status & (1 << g_vrsdprf_curr))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vrsdprf_del_tag_confirm, KEY_EVENT_UP);

        /* Playback when highlighted */
        StartTimer(VRSD_DIAL_PLAYBACK_TIMER, MMI_VRSD_PLAY_TAG_DELAY, mmi_vrsdprf_list_playback_tag);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vrsdprf_trn_tag, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_hint_profile
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_hint_profile(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsdprf_status & (1 << index))
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
 *  mmi_vrsdprf_list_playback_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_list_playback_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_PROFILE, g_vrsdprf_curr);
    if (tag_id != 0xffff)
    {
        mmi_vrsd_playback_req(tag_id, NULL);
    }
}

#define MMI_VRSD_PROFILE_FUNC


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_trn_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_trn_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_NONE, 0xffff)) != 0xffff) /* Use 0xffff as parameter to get "empty tag id" */
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_PROFILE, g_vrsdprf_curr, mmi_vrsdprf_trn_result_callback);
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
 *  mmi_vrsdprf_trn_result_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_trn_result_callback(U8 result)
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
        g_vrsdprf_status |= (1 << g_vrsdprf_curr);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        g_vrsdprf_status &= ~(1 << g_vrsdprf_curr); /* Set bit to zero */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_del_tag_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_del_tag_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_vrsdprf_del_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_del_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_del_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_PROFILE, g_vrsdprf_curr)) != 0xffff)
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

    g_vrsdprf_status &= ~(1 << g_vrsdprf_curr); /* Set bit to zero */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_del_tag_reset_flag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_del_tag_reset_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsdprf_status = 0;
}

#define MMI_VRSD_PROFILE_RCG


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsdprf_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  appref_id       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsdprf_rcg_callback(U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(appref_id < 5);

    /* playback */
    mmi_vrsd_playback_req(g_vrsd_cntx.vrtag_id, NULL);

    if (IsHeadsetModeActivated())
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_VRSD_PROFILE_CANNOT_SWITCH),
            IMG_GLOBAL_WARNING,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    else
    {
        if (appref_id == 4) /* silent mode */
        {
            ActivateSilentProfile();
        }
        else
        {
            mmi_profiles_entry_activate_profile_by_id((U8) appref_id);   /* appref_id = 0, or 1, or 2, or 3 */
        }
    }
}
#endif /* defined(__MMI_VRSD__) && defined(__MMI_VRSD_PROFILE__) */ /* #if defined(__MMI_VRSD__) && defined(__MMI_VRSD_PROFILE__) */
#endif /* _MMI_VRSDPROFILE_C */ /* #ifndef _MMI_VRSDPROFILE_C */

