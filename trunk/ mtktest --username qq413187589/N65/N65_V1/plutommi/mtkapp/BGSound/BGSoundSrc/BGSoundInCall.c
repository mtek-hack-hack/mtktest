 /*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
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
 *******************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BGSoundInCall.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef _MMI_BGSOUNDINCALL_C
#define _MMI_BGSOUNDINCALL_C


#ifdef __MMI_BG_SOUND_EFFECT__

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "nvram_user_defs.h"
#include "CallManagementGprot.h"
#include "IncomingCallManagementProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "wgui_status_icons.h"
#include "SettingDefs.h"
#include "FileManagerGProt.h"
#include "IdleAppDef.h"
/* ... Add More MMI header */
#include "SimDetectionGprot.h"

#include "BGSoundDef.h"
#include "BGSoundType.h"
#include "BGSoundProt.h"
#include "BGSoundGProt.h"
#ifdef __CTM_SUPPORT__ 
#include "TextPhoneProt.h"
#endif

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#include "drm_def.h"
#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 

#include "UCMGProt.h"

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
#ifndef __UCM_SUPPORT__
static S8 bgsnd_call_buffer[MAX_DIGITS_USSD * ENCODING_LENGTH];

static U16 bgsnd_mo_highlight;
static U16 bgsnd_mt_highlight;
static BOOL is_emergency_call;
#endif
static U16 bgsnd_cm_highlight;

#ifdef __UCM_SUPPORT__
static U16 bgsnd_common_hilight;
static MMI_BOOL bgsnd_common_select;
static MMI_BOOL bgsnd_cm_state;
static MMI_BOOL bgsnd_common_default;
#endif


static S32 bgsnd_cm_repeat;
static UI_character_type bgsnd_cm_interval_buf[BGSND_INTERVAL_LEN];
static UI_character_type bgsnd_cm_volume_buf[BGSND_VOLUME_LEN];

extern S8 *bgsnd_repeat_str[];

/* 
 * Local Function
 */

/* 
 * Global Variable
 */

/* 
 * Global Function
 */
extern void MakeCallEx(PS8 strNumber, BOOL pre_check);


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_call_init
 * DESCRIPTION
 *  This function is to initialize background sound effect for call management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_call_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UCM_SUPPORT__
    bgsnd_common_hilight = 0;
    bgsnd_common_select = MMI_FALSE;
    bgsnd_cm_state = MMI_FALSE;
    bgsnd_common_default = MMI_FALSE;
#else /* __UCM_SUPPORT__ */
    g_bgsnd_cntx.is_mt_call_select = FALSE;
    g_bgsnd_cntx.is_mo_call_select = FALSE;
    g_bgsnd_cntx.is_speech_on = MMI_FALSE;
    g_bgsnd_cntx.is_request_play = MMI_FALSE;
    bgsnd_mo_highlight = 0;

    /* MT Call Effect */
    SetHiliteHandler(MENU_ID_BGSND_INC_OPT_EFFECT, mmi_bgsnd_highlight_mt_call_effect);

    /* Call Management Screen. (In Call) */
    SetHiliteHandler(MENU_ID_BGSND_CM_OPT_EFFECT, mmi_bgsnd_highlight_call_manage);
#endif /* __UCM_SUPPORT__ */

    SetHiliteHandler(MENU_ID_BGSND_CM_OPT_STATUS, mmi_bgsnd_highlight_cm_status);
    SetHiliteHandler(MENU_ID_BGSND_CM_OPT_SETTING, mmi_bgsnd_highlight_cm_setting);
    SetHiliteHandler(MENU_ID_BGSND_CM_OPT_LIST, mmi_bgsnd_highlight_cm_effect_list);

    SetHintHandler(MENU_ID_BGSND_CM_OPT_STATUS, mmi_bgsnd_hint_cm_status);
}

#ifndef __UCM_SUPPORT__


#define MMI_BGSND_MO_CALL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_call_check_last_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_num             [?]         
 *  char_to_search      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bgsnd_mo_call_check_last_char(S8 *str_num, S8 char_to_search)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (str_num[pos] != '\0')
    {
        pos = pos + 2;
    }

    if (str_num[pos - 2] == char_to_search)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_call_use_effect
 * DESCRIPTION
 *  This function is to check if dial out with sound effect.
 * PARAMETERS
 *  str_number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_mo_call_use_effect(S8 *str_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_mo_highlight = 0;
    is_emergency_call = FALSE;

    mmi_ucs2ncpy(bgsnd_call_buffer, str_number, MAX_DIGITS_USSD);

    /* status is on and the first time connect call. */
    if ((g_bgsnd_cntx.set.status != 0)
        && (GetTotalCallCount() == 0)
    #ifdef __CTM_SUPPORT__        
        && (mmi_ctm_get_mode() == FALSE)
    #endif        
       )
    {
        if (CheckValidEmergencyNo1(bgsnd_call_buffer))
        {
            MakeCallEx(bgsnd_call_buffer, FALSE);
        }
        else
        {
            mmi_bgsnd_entry_mo_call_list();
        }
        return TRUE;
    }
    if (CheckValidEmergencyNo1(bgsnd_call_buffer))
    {
        mmi_bgsnd_util_stop_play_sound();
        memset(bgsnd_call_buffer, 0, sizeof(bgsnd_call_buffer));
        is_emergency_call = TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_call_list_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for mo call sound effect list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mo_call_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_mo_highlight = (U16) index;

    if ((bgsnd_mo_highlight > BGSND_MAX_EFFECT) && ((bgsnd_mo_highlight < BGSND_TOTAL_EFFECT + 1)))
    {
        if (!mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_mo_highlight - BGSND_MAX_EFFECT - 1)))
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
            ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
            return;
        }
    }
    
#ifdef __DRM_SUPPORT__
    mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_mo_highlight, TRUE);
#endif

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_bgsnd_mo_call_make_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_mo_call_make_call, KEY_SEND, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_mo_call_list
 * DESCRIPTION
 *  This function is the entry funtcion for mo call sound effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_mo_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 title_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BGSND_MO_CALL_LIST, NULL, mmi_bgsnd_entry_mo_call_list, NULL);

    RegisterHighlightHandler(mmi_bgsnd_mo_call_list_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BGSND_MO_CALL_LIST);

    if ((gui_buffer == NULL) && (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT))
    {
        bgsnd_mo_highlight = g_bgsnd_cntx.set.curr_effect + 1;
    }

    /* fill effect list data */
    mmi_bgsnd_util_prepare_effect_list(TRUE);

    /* Get title icon from root menu. If enter this list before main screen, use default icon */
    title_icon = GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT);
    if(title_icon == 0)
    {
        title_icon = IMG_SCR_SETTING_CAPTION;
    }
    
    ShowCategory89Screen(
        STR_ID_BGSND_BG_SOUND,
        title_icon,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        (S32) (BGSND_TOTAL_EFFECT + 1), /* First item is no effect */
        subMenuDataPtrs,
        NULL,
        0,
        bgsnd_mo_highlight,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_bgsnd_mo_call_make_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_mo_call_make_call, KEY_SEND, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_call_make_call
 * DESCRIPTION
 *  This function is to make mo call after select a sound effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mo_call_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_CALL_MAKE_CALL, bgsnd_mo_highlight);

    if ((bgsnd_mo_highlight >= BGSND_MAX_EFFECT + 1) && ((bgsnd_mo_highlight < BGSND_TOTAL_EFFECT + 1)))
    {
        if (!mmi_bgsnd_util_check_ext_file_format((U16) (bgsnd_mo_highlight - BGSND_MAX_EFFECT - 1)))
        {
            return;
        }
    }

    g_bgsnd_cntx.is_mo_call_select = TRUE;
    // for CR MAUI_00510693
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL); /* To call exit function */
    DeleteScreenIfPresent(SCR_ID_BGSND_MO_CALL_LIST);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
    
    MakeCallEx(bgsnd_call_buffer, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_play_sound
 * DESCRIPTION
 *  This function is to play background sound effect when after mo call connected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mo_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_PLAY_SOUND);

    /* Set the background sound for the fisrt call only */
    if (GetTotalCallCount() <= 1)
    {
        /* Get default play type for in call usage */
        g_bgsnd_cntx.cm.play_type = g_bgsnd_cntx.set.play_type;
        g_bgsnd_cntx.cm.interval_sec = g_bgsnd_cntx.set.interval_sec;
        g_bgsnd_cntx.cm.volume = g_bgsnd_cntx.set.volume;

        g_bgsnd_cntx.cm.status = 0;

        if ((bgsnd_mo_highlight > 0) && g_bgsnd_cntx.is_mo_call_select)
        {
            g_bgsnd_cntx.cm.curr_effect = bgsnd_mo_highlight - 1;
            mmi_bgsnd_util_play_sound_in_call();
        }
        else    /* No effect selected */
        {
            g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;
        }
    }
}

#define MMI_BGSND_MT_CALL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_mt_call_effect
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_mt_call_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_bgsnd_pre_entry_mt_call_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_pre_entry_mt_call_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mt_call_list_highlight_hdlr
 * DESCRIPTION
 *  This function is the mt call effect list highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mt_call_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_mt_highlight = (U16) index;

    if ((bgsnd_mt_highlight > BGSND_MAX_EFFECT) && ((bgsnd_mt_highlight < BGSND_TOTAL_EFFECT + 1)))
    {
        if (!mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_mt_highlight - BGSND_MAX_EFFECT - 1)))
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
            ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
            return;
        }
    }

#ifdef __DRM_SUPPORT__
    mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_mt_highlight, TRUE);
#endif

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_bgsnd_mt_call_answer, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_mt_call_answer, KEY_SEND, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_pre_entry_mt_call_list
 * DESCRIPTION
 *  This function is the pre entry function for mt call effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_pre_entry_mt_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CTM_SUPPORT__
    if(mmi_ctm_get_mode() == TRUE)
    {
        DisplayPopup(
        (U8*) GetString(STR_ID_BGSND_CTM_MODE_ON),
        IMG_GLOBAL_WARNING,
        1,
        UI_POPUP_NOTIFYDURATION_TIME_2000,
        (U8) WARNING_TONE);
    }
    else
#endif /* #ifdef __CTM_SUPPORT__ */
    {
        mmi_bgsnd_entry_mt_call_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_mt_call_list
 * DESCRIPTION
 *  This function is the entry function for mt call effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_mt_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BGSND_MT_CALL_LIST, mmi_bgsnd_exit_mt_call_list, NULL, NULL);

    RegisterHighlightHandler(mmi_bgsnd_mt_call_list_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BGSND_MT_CALL_LIST);

    if ((gui_buffer == NULL) && (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT))
    {
        bgsnd_mt_highlight = g_bgsnd_cntx.set.curr_effect + 1;
    }

    /* fill effect list data */
    mmi_bgsnd_util_prepare_effect_list(TRUE);

    ShowCategory89Screen(
        STR_ID_BGSND_BG_SOUND,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        (S32) (BGSND_TOTAL_EFFECT + 1),
        subMenuDataPtrs,
        NULL,
        0,
        bgsnd_mt_highlight,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_bgsnd_mt_call_answer, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_mt_call_answer, KEY_SEND, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_mt_call_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_mt_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetTotalCallCount() > 0)
    {
        h.scrnID = SCR_ID_BGSND_MT_CALL_LIST;
        h.entryFuncPtr = mmi_bgsnd_entry_mt_call_list;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mt_call_answer
 * DESCRIPTION
 *  This function is to check if can play an external file sound effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mt_call_answer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((bgsnd_mt_highlight >= BGSND_MAX_EFFECT + 1) && ((bgsnd_mt_highlight < BGSND_TOTAL_EFFECT + 1)))
    {
        if (!mmi_bgsnd_util_check_ext_file_format((U16) (bgsnd_mt_highlight - BGSND_MAX_EFFECT - 1)))
        {
            return;
        }
    }

    /* Stop background sound first and replay after call connected if there only one call. */
    if (g_bgsnd_cntx.cm.status && (GetTotalCallCount() <= 1))
    {
        mmi_bgsnd_util_stop_play_sound_in_call();
    }

    g_bgsnd_cntx.is_mt_call_select = TRUE;
    KbCBackCallIncomingAccepted();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mt_play_sound
 * DESCRIPTION
 *  This function is to play background sound after mt call connected.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_mt_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MT_PLAY_SOUND);

    DeleteScreenIfPresent(SCR_ID_BGSND_MT_CALL_LIST);

    /* Anser call with background sound, change the state for the first call only */
    if (GetTotalCallCount() <= 1)
    {
        /* Background sound if off, turn on it and play */
        if (g_bgsnd_cntx.cm.status == 0)
        {
            /* Get default play type for in call usage */
            g_bgsnd_cntx.cm.play_type = g_bgsnd_cntx.set.play_type;
            g_bgsnd_cntx.cm.interval_sec = g_bgsnd_cntx.set.interval_sec;
            g_bgsnd_cntx.cm.volume = g_bgsnd_cntx.set.volume;

            /* User has select an effect */
            if (g_bgsnd_cntx.is_mt_call_select && (bgsnd_mt_highlight > 0))
            {
                g_bgsnd_cntx.cm.curr_effect = (U8) bgsnd_mt_highlight - 1;
                mmi_bgsnd_util_play_sound_in_call();
            }
            else
            {
                g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;
            }
        }
        /* Background sound is on, check if change to another effect or close it */
        else
        {
            if (g_bgsnd_cntx.is_mt_call_select)
            {
                mmi_bgsnd_util_stop_play_sound_in_call();

                if (bgsnd_mt_highlight > 0)
                {
                    g_bgsnd_cntx.cm.curr_effect = (U8) bgsnd_mt_highlight;
                    mmi_bgsnd_util_play_sound_in_call();
                }
                else
                {
                    g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;
                }
            }
        }
    }
}

#endif /*  __UCM_SUPPORT__ */


#define MMI_BGSND_CALL_MANAGE


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_call_manage
 * DESCRIPTION
 *  This function is the highlight function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_bgsnd_pre_entry_call_manage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_pre_entry_call_manage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_pre_entry_call_manage
 * DESCRIPTION
 *  This function is the pre entry function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_pre_entry_call_manage(void)
{
#ifdef __CTM_SUPPORT__
    if(mmi_ctm_get_mode() == TRUE)
    {
        DisplayPopup(
        (U8*) GetString(STR_ID_BGSND_CTM_MODE_ON),
        IMG_GLOBAL_WARNING,
        1,
        UI_POPUP_NOTIFYDURATION_TIME_2000,
        (U8) WARNING_TONE);
    }
    else
#endif /* #ifdef __CTM_SUPPORT__ */
    {
        mmi_bgsnd_entry_call_manage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_call_manage
 * DESCRIPTION
 *  This function is the entry function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *hintList[MAX_SUB_MENUS];    /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BGSND_CALL_MANAGE, mmi_bgsnd_exit_call_manage, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BGSND_CALL_MANAGE);
    nNumofItem = GetNumOfChild(MENU_ID_BGSND_CM_OPT_EFFECT);
    GetSequenceStringIds(MENU_ID_BGSND_CM_OPT_EFFECT, nStrItemList);
    SetParentHandler(MENU_ID_BGSND_CM_OPT_EFFECT);

    /* Fill external effect list data */
    mmi_bgsnd_util_prepare_ext_file_index();

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_BGSND_CM_OPT_EFFECT, hintList);

    /* Screen with hint, if no hint needed, can change to Screen 15 */
    ShowCategory52Screen(
        STR_ID_BGSND_BG_SOUND,
        #ifdef __UCM_SUPPORT__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        #endif
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
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
 *  mmi_bgsnd_exit_call_manage
 * DESCRIPTION
 *  This function is the exit function for sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_call_manage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
    #ifdef __MMI_UCM__
         mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
        h.scrnID = SCR_ID_BGSND_CALL_MANAGE;
        h.entryFuncPtr = mmi_bgsnd_entry_call_manage;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
}


#define MMI_BGSND_CALL_MANAGE_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cm_status
 * DESCRIPTION
 *  This function is the highlight function of sound effect status during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cm_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.cm.status != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    SetLeftSoftkeyFunction(mmi_bgsnd_cm_status_toggle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //SetKeyHandler(mmi_bgsnd_cm_status_toggle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_hint_cm_status
 * DESCRIPTION
 *  This function is the hint function of sound effect status during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_hint_cm_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

    if (g_bgsnd_cntx.cm.status != 0)
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
 *  mmi_bgsnd_cm_status_toggle
 * DESCRIPTION
 *  This function is to toggle sound effect status during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_status_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif
    
    if (g_bgsnd_cntx.cm.status != 0)
    {
    #ifdef __UCM_SUPPORT__
        bgsnd_common_select = MMI_FALSE;
        mmi_bgsnd_common_cm_stop_play_sound();
    #else
        mmi_bgsnd_util_stop_play_sound_in_call();
    #endif
    }
    else
    {
        /* Check the correctness of external file content */
        if ((g_bgsnd_cntx.cm.curr_effect >= BGSND_MAX_EFFECT) && (g_bgsnd_cntx.cm.curr_effect < BGSND_TOTAL_EFFECT))
        {
            if (!mmi_bgsnd_util_check_ext_file_format((U16) (g_bgsnd_cntx.cm.curr_effect - BGSND_MAX_EFFECT)))
            {
                return;
            }
        }

    #ifdef __UCM_SUPPORT__
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
        
        bgsnd_common_select = MMI_TRUE;
        mmi_bgsnd_common_mtmo_play_sound();
    #else
        mmi_bgsnd_util_play_sound_in_call();
    #endif
    }

    /* Change menu item */
    index = GetIndexOfStringId(MENU_ID_BGSND_CALL_SETUP, STR_ID_BGSND_STATUS);

    if (g_bgsnd_cntx.cm.status != 0)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    RedrawCategoryFunction();

}

#define MMI_BGSND_CALL_MANAGE_SETTING


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cm_setting
 * DESCRIPTION
 *  This function is the highlight function of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_bgsnd_cm_setting_prepare_inline_data, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cm_setting_prepare_inline_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_prepare_inline_data
 * DESCRIPTION
 *  This function is to prepare data for sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_prepare_inline_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* repeat type */
    if (g_bgsnd_cntx.cm.play_type < BGSND_REPEAT_NUM)
    {
        bgsnd_cm_repeat = g_bgsnd_cntx.cm.play_type;
    }
    else
    {
        bgsnd_cm_repeat = 0;
    }

    /* Interval */
    if (g_bgsnd_cntx.cm.interval_sec <= BGSND_MAX_INTERVAL)
    {
        kal_wsprintf(bgsnd_cm_interval_buf, "%d", g_bgsnd_cntx.cm.interval_sec);
    }
    else
    {
        memset(bgsnd_cm_interval_buf, 0, 2);
    }

    /* volume */
    if (g_bgsnd_cntx.cm.volume <= BGSND_MAX_VOLUME)
    {
        kal_wsprintf(bgsnd_cm_volume_buf, "%d", g_bgsnd_cntx.cm.volume);
    }
    else
    {
        memset(bgsnd_cm_volume_buf, 0, 2);
    }

    /* Enter inline editor screen */
    mmi_bgsnd_entry_cm_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_playback_setup_done
 * DESCRIPTION
 *  This function is the entry function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(mmi_ucs2strlen((S8*)bgsnd_cm_volume_buf) == 0 ||
      ((bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)&& (mmi_ucs2strlen((S8*)bgsnd_cm_interval_buf) == 0)))
    {
        DisplayPopup(
        (U8*) GetString(STR_GLOBAL_EMPTY),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME_2000,
        (U8) ERROR_TONE);    
    }
    else
    {
        mmi_bgsnd_cm_setting_apply_change();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cm_setting
 * DESCRIPTION
 *  This function is the entry function of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 inline_icon_list[BGSND_SETUP_NUM] = {IMG_GLOBAL_L1, 0, IMG_GLOBAL_L2, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BGSND_CM_SETTING, mmi_bgsnd_exit_cm_setting, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BGSND_CM_SETTING);
    InitializeCategory57Screen();

    /* RegisterHighlightHandler(xxx); */

    /* Fill each inline editor item */
    mmi_bgsnd_cm_setting_fill_inline_item();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BGSND_CM_SETTING, &inputBufferSize);       /* added for inline edit history */

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, BGSND_SETUP_NUM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_BGSND_PLAYBACK_SETUP,
        #ifdef __UCM_SUPPORT__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        #endif
        STR_GLOBAL_DONE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        BGSND_SETUP_NUM,
        inline_icon_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_bgsnd_cm_setting_done, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cm_setting
 * DESCRIPTION
 *  This function is the exit function of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cm_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    
    if (
    #ifdef __MMI_UCM__
         mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
        Scr.scrnID = SCR_ID_BGSND_CM_SETTING;
        Scr.entryFuncPtr = mmi_bgsnd_entry_cm_setting;
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
        GetCategory57History(Scr.guiBuffer);
        inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
        GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
        AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */
    }
    else
    {
        /* Also delete previous screen if not in GSM call */
        DeleteScreenIfPresent(SCR_ID_BGSND_CALL_MANAGE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_repeat_hdlr
 * DESCRIPTION
 *  This function is the repeat inline selection for playback setting during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_repeat_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == BGSND_REPEAT_INTERVAL)
    {
        EnableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
    else
    {
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_fill_inline_item
 * DESCRIPTION
 *  This function is to fill the inline item of sound effect playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_fill_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get string each time because the language may change */
    bgsnd_repeat_str[BGSND_REPEAT_ONCE] = GetString(STR_ID_BGSND_ONCE);
    bgsnd_repeat_str[BGSND_REPEAT_INTERVAL] = GetString(STR_ID_BGSND_INTERVAL);
    bgsnd_repeat_str[BGSND_REPEAT_CONTINUE] = GetString(STR_ID_BGSND_CONTINUE);

   /*-- Volume Caption --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
//#if defined(__MMI_MAINLCD_128X128__)
    SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_ID_BGSND_VOLUME_CAP_SHORT));
//#else 
    //SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_ID_BGSND_VOLUME_CAP));
//#endif 

   /*-- Volume --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_VOLUME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_VOLUME],
        (U8*) bgsnd_cm_volume_buf,
        BGSND_VOLUME_LEN,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_VOLUME]);

   /*-- Repeat Type --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_REPEAT]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[BGSND_SETUP_REPEAT]),
        BGSND_REPEAT_NUM,
        (U8 **) bgsnd_repeat_str,
        &bgsnd_cm_repeat);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[BGSND_SETUP_REPEAT], mmi_bgsnd_cm_setting_repeat_hdlr);

   /*-- Interval Caption --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_INTERVAL_CAP]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
//#if defined(__MMI_MAINLCD_128X128__)
    SetInlineItemCaption(
        &(wgui_inline_items[BGSND_SETUP_INTERVAL_CAP]),
        (U8*) GetString(STR_ID_BGSND_INTERVAL_CAP_SHORT));
//#else /* defined(__MMI_MAINLCD_128X128__) */ 
    //SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_INTERVAL_CAP]), (U8*) GetString(STR_ID_BGSND_INTERVAL_CAP));
//#endif /* defined(__MMI_MAINLCD_128X128__) */ 

   /*-- Interval --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_INTERVAL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_INTERVAL],
        (U8*) bgsnd_cm_interval_buf,
        BGSND_INTERVAL_LEN,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_INTERVAL]);

    if (bgsnd_cm_repeat != BGSND_REPEAT_INTERVAL)   /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_setting_apply_change
 * DESCRIPTION
 *  This function is to apply the change right away for the playback setting during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_setting_apply_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_interval[BGSND_INTERVAL_LEN];
    S8 ascii_volume[BGSND_VOLUME_LEN];
    U16 interval_value = 0;
    U16 volume_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check volume */
    mmi_ucs2_to_asc(ascii_volume, (S8*) bgsnd_cm_volume_buf);
    volume_value = atoi(ascii_volume);

    if (volume_value > BGSND_MAX_VOLUME)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BGSND_INVALID_VOLUME),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) ERROR_TONE);
        return;
    }

    /* check interval */
    if (bgsnd_cm_repeat == BGSND_REPEAT_INTERVAL)
    {
        mmi_ucs2_to_asc(ascii_interval, (S8*) bgsnd_cm_interval_buf);
        interval_value = (U16) atoi(ascii_interval);

        if ((interval_value < BGSND_MIN_INTERVAL) || (interval_value > BGSND_MAX_INTERVAL))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_BGSND_INVALID_INTERVAL),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME_2000,
                (U8) ERROR_TONE);
            return;
        }
    }

    /* Assign vaule and save */
    g_bgsnd_cntx.cm.play_type = (U8) bgsnd_cm_repeat;
    g_bgsnd_cntx.cm.interval_sec = interval_value;
    g_bgsnd_cntx.cm.volume = (U8) volume_value;

#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif

    /* Apply change and play */
    if (g_bgsnd_cntx.cm.status)
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
        mmi_bgsnd_util_play_sound_in_call();
    #else
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
    
        mmi_bgsnd_common_cm_stop_play_sound();
        mmi_bgsnd_common_mtmo_play_sound();
    #endif
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_SETTING);
}

#define MMI_BGSND_CALL_MANAGE_EFFECT_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cm_effect_list
 * DESCRIPTION
 *  This function is the highlight function of sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cm_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_bgsnd_entry_cm_effect_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_entry_cm_effect_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of sound effect list during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_effect_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_cm_highlight = index;

    if ((bgsnd_cm_highlight >= BGSND_MAX_EFFECT) && ((bgsnd_cm_highlight < BGSND_TOTAL_EFFECT)))
    {
        if (!mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_cm_highlight - BGSND_MAX_EFFECT)))
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
            return;
        }
    }

#ifdef __DRM_SUPPORT__
    mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_cm_highlight, FALSE);
#endif


    ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
    SetLeftSoftkeyFunction(mmi_bgsnd_cm_effect_apply_change, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cm_effect_list
 * DESCRIPTION
 *  This function is the entry function of sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cm_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BGSND_CM_EFFECT, mmi_bgsnd_exit_cm_effect_list, NULL, NULL);

    RegisterHighlightHandler(mmi_bgsnd_cm_effect_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BGSND_CM_EFFECT);

    if ((gui_buffer == NULL) && (g_bgsnd_cntx.cm.curr_effect < BGSND_TOTAL_EFFECT))
    {
        bgsnd_cm_highlight = g_bgsnd_cntx.cm.curr_effect;
    }

    /* Fill effect list data */
    mmi_bgsnd_util_prepare_effect_list(FALSE);

    ShowCategory89Screen(
        STR_ID_BGSND_EFFECT_LIST,
        #ifdef __UCM_SUPPORT__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        #endif
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK,
        0,
        BGSND_TOTAL_EFFECT,
        subMenuDataPtrs,
        NULL,
        0,
        bgsnd_cm_highlight,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cm_effect_list
 * DESCRIPTION
 *  This function is the exit function of sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cm_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
    #ifdef __MMI_UCM__
         mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_VOIP_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE) > 0
    #else
        GetTotalCallCount() > 0
    #endif
    )
    {
        h.scrnID = SCR_ID_BGSND_CM_EFFECT;
        h.entryFuncPtr = mmi_bgsnd_entry_cm_effect_list;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
        AddHistory(h);
    }
    else
    {
        /* Also delete previous screen if not in GSM call */
        DeleteScreenIfPresent(SCR_ID_BGSND_CALL_MANAGE);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cm_effect_apply_change
 * DESCRIPTION
 *  This function is to apply the change right away for sound effect list during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cm_effect_apply_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the correctness of external file content */
    if ((bgsnd_cm_highlight >= BGSND_MAX_EFFECT) && (bgsnd_cm_highlight < BGSND_TOTAL_EFFECT))
    {
        if (!mmi_bgsnd_util_check_ext_file_format((U16) (bgsnd_cm_highlight - BGSND_MAX_EFFECT)))
        {
            bgsnd_cm_highlight = g_bgsnd_cntx.cm.curr_effect;
            return;
        }
    }

    /* Check file OK, begin to assign and playback */
    g_bgsnd_cntx.cm.curr_effect = (U8) bgsnd_cm_highlight;

#ifdef __UCM_SUPPORT__
    bgsnd_cm_state = MMI_TRUE;
#endif

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_EFFECT);

    /* Play new music */
    if (g_bgsnd_cntx.cm.status)
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
        mmi_bgsnd_util_play_sound_in_call();
    #else
        /*for the common play api running correctly,now it is just  a flag*/
        bgsnd_common_hilight = 1;
    
        mmi_bgsnd_common_cm_stop_play_sound();
        mmi_bgsnd_common_mtmo_play_sound();
    #endif
    }
}

#define MMI_BGSND_CALLING_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_sound
 * DESCRIPTION
 *  This function is to play sound effect
 * PARAMETERS
 *  highlight_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_sound(U16 highlight_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_PLAY_SOUND, highlight_index);

    if (highlight_index < BGSND_MAX_EFFECT)
    {
        mmi_bgsnd_util_play_by_highlight_index_in_call(highlight_index);
    }
    /* external file */
    else if (highlight_index >= BGSND_MAX_EFFECT && highlight_index < BGSND_TOTAL_EFFECT)
    {
        index = highlight_index - BGSND_MAX_EFFECT + 1;
        ReadRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)read_buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
            mmi_bgsnd_util_play_file_in_call((U16*) read_buff);
        }
    }
}

#ifndef __UCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_sound_in_call
 * DESCRIPTION
 *  This function is to play sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_sound_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_PLAY_SOUND_IN_CALL, g_bgsnd_cntx.cm.status, g_bgsnd_cntx.is_speech_on);

    /* Play background sound when speech on and not played before. */
    if (GetTotalCallCount() >= 1)
    {
        g_bgsnd_cntx.is_request_play = MMI_TRUE;

        if ((g_bgsnd_cntx.cm.status == 0) && (g_bgsnd_cntx.is_speech_on == MMI_TRUE))
        {
            mmi_bgsnd_util_play_sound(g_bgsnd_cntx.cm.curr_effect);
        }
    }
}
#endif /* __UCM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_in_call_callback
 * DESCRIPTION
 *  This function is the callback function when play backgrund sound during call
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_in_call_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 play_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_PLAY_IN_CALL_CALLBACK, result);

    mmi_bgsnd_util_calling_change_state(FALSE);

    /* Play finish */
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        /* Play again after an interval */
        if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_INTERVAL && g_bgsnd_cntx.cm.interval_sec > 0)
        {
            play_time = g_bgsnd_cntx.cm.interval_sec * 1000;
        #ifndef __UCM_SUPPORT__
            StartTimer(BGSND_INTERVAL_TIMER, play_time, mmi_bgsnd_util_play_sound_in_call);
        #else
            StartTimer(BGSND_INTERVAL_TIMER, play_time, mmi_bgsnd_common_mtmo_play_sound);
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_by_highlight_index_in_call
 * DESCRIPTION
 *  This function is to play sound string data according to the highlight during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_by_highlight_index_in_call(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 repeat = 1; /* Play once */
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_CONTINUE)
    {
        repeat = 0; /* Play infinite */
    }

    audio_data = get_audio((U16) (AUD_ID_BGSND_EFFECT1 + index), &audio_type, &audio_len);

    if (audio_data != NULL)
    {
        result = mdi_audio_snd_play_string_with_vol_path(
                    (void*)audio_data,
                    audio_len,
                    repeat,
                    NULL,
                    mmi_bgsnd_util_play_in_call_callback,
                    g_bgsnd_cntx.cm.volume,
                    MDI_DEVICE_SPEAKER2);

        if (result == MDI_AUDIO_SUCCESS)
        {
            mmi_bgsnd_util_calling_change_state(TRUE);
        }
        else
        {
            mmi_bgsnd_util_calling_change_state(FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_file_in_call
 * DESCRIPTION
 *  This function is to play sound file during call
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_file_in_call(U16 *full_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 repeat = 1; /* Play once */
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.cm.play_type == BGSND_REPEAT_CONTINUE)
    {
        repeat = 0; /* Play infinite */
    }

    result = mdi_audio_snd_play_file_with_vol_path(
                (void*)full_path,
                repeat,
                NULL,
                mmi_bgsnd_util_play_in_call_callback,
                g_bgsnd_cntx.cm.volume,
                MDI_DEVICE_SPEAKER2);

    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_bgsnd_util_calling_change_state(TRUE);
    }
    else
    {
        mmi_bgsnd_util_calling_change_state(FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_play_sound
 * DESCRIPTION
 *  This function is to stop play sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_STOP_PLAY_SOUND, g_bgsnd_cntx.cm.status);

    mmi_bgsnd_common_cm_stop_play_sound();

#ifdef __UCM_SUPPORT__
    mmi_bgsnd_util_delete_cm_setting_screen();
#endif
}

#ifndef __UCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_play_sound_in_call
 * DESCRIPTION
 *  This function is to stop play sound effect during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_play_sound_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_STOP_PLAY_SOUND_IN_CALL);

    g_bgsnd_cntx.is_mt_call_select = FALSE;
    g_bgsnd_cntx.is_mo_call_select = FALSE;

    g_bgsnd_cntx.is_request_play = MMI_FALSE;

    mmi_bgsnd_util_stop_play_sound();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_play_sound_end_call
 * DESCRIPTION
 *  This function is to stop play sound effect when call finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_play_sound_end_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_STOP_PLAY_SOUND_END_CALL);

    if (GetTotalCallCount() == 0)
    {
        /*
         * Clear highlight at the END call. 
         * Always keep this highlight as 0 to prevent MO call which not through MakeCall() function
         */
        bgsnd_mo_highlight = 0;

        mmi_bgsnd_util_stop_play_sound_in_call();
    }
}
#endif /* __UCM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_delete_cm_setting_screen
 * DESCRIPTION
 *  This function is to delete the setting screen during call when need.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_delete_cm_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_BGSND_CALL_MANAGE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_SETTING);
    DeleteScreenIfPresent(SCR_ID_BGSND_CM_EFFECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_delete_end_call_screen
 * DESCRIPTION
 *  This function is to stop play sound effect when call finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_delete_end_call_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UCM_SUPPORT__
    bgsnd_common_select = MMI_FALSE;
    bgsnd_common_default = MMI_FALSE;
    
    /*call management has not to change setting*/
    bgsnd_cm_state = MMI_FALSE;
    mmi_bgsnd_util_stop_play_sound();
#else
    mmi_bgsnd_util_delete_cm_setting_screen();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_check_ext_file_format
 * DESCRIPTION
 *  This function is to check if the external file valid for playing.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_check_ext_file_format(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 str_id = 0;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* File not exists */
    if (!mmi_bgsnd_util_get_ext_effect_status(index))
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BGSND_NO_EFFECT),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return FALSE;
    }
    else    /* File exists, check its format */
    {
        if (mmi_bgsnd_check_usb_mode())
        {
            return FALSE;
        }
    #ifdef __DRM_SUPPORT__
        if (!g_bgsnd_cntx.drm_permission_state)
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            return FALSE;
        }
        else
    #endif
        {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);
        result = mdi_audio_snd_check_file_format((void*)read_buff);
        }
    }

    /* Check file success */
    if (result == MDI_AUDIO_SUCCESS)
    {
        return TRUE;
    }
    else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
    {
        str_id = STR_ID_BGSND_OPEN_FILE_FAIL;
    }
    else if (result == MDI_AUDIO_BAD_FORMAT)
    {
        str_id = STR_ID_BGSND_INVALID_FILE;
    }
    else
    {
        str_id = STR_ID_BGSND_PLAY_FAIL;
    }

    DisplayPopup((U8*) GetString(str_id), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_calling_change_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_calling_change_state(BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 str_id = STR_GLOBAL_OFF;
    U16 lsk_id = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_on)
    {
        ShowStatusIcon(STATUS_ICON_BG_SOUND);
        UpdateStatusIcons();
        g_bgsnd_cntx.cm.status = 1;

        str_id = STR_GLOBAL_ON;
        lsk_id = STR_GLOBAL_OFF;
    }
    else
    {
        HideStatusIcon(STATUS_ICON_BG_SOUND);
        UpdateStatusIcons();
        g_bgsnd_cntx.cm.status = 0;
    }

    /* Chage play state if in the setting menu */
    if (GetActiveScreenId() == SCR_ID_BGSND_CALL_MANAGE)
    {
        index = GetIndexOfStringId(MENU_ID_BGSND_CALL_SETUP, STR_ID_BGSND_STATUS);

        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(str_id));
        Category52ChangeItemDescription(index, (U8*) GetString(str_id));

        if(index == GetHighlightedItem())
        {
            ChangeLeftSoftkey(lsk_id, 0);
            RedrawCategoryFunction();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_calling_sd_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_calling_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Playing during the call */
    if ((g_bgsnd_cntx.cm.status == 1) && (g_bgsnd_cntx.cm.curr_effect >= BGSND_MAX_EFFECT))
    {
    #ifndef __UCM_SUPPORT__
        mmi_bgsnd_util_stop_play_sound_in_call();
    #else
        mmi_bgsnd_util_stop_play_sound();
    #endif
    }
}

#ifndef __UCM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_switch_speech
 * DESCRIPTION
 *  Turn on/off background according to speech mode.
 * PARAMETERS
 *  speech_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_switch_speech(MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_SWITCH_SPEECH, speech_on, g_bgsnd_cntx.is_request_play);

    if (speech_on)
    {
        g_bgsnd_cntx.is_speech_on = MMI_TRUE;

        if (g_bgsnd_cntx.is_request_play)
        {
            if ((!CheckValidEmergencyNo1(bgsnd_call_buffer)) && (!is_emergency_call))
            {
                mmi_bgsnd_util_play_sound(g_bgsnd_cntx.cm.curr_effect);
            }
            else
            {
                memset(bgsnd_call_buffer, 0, sizeof(bgsnd_call_buffer));
                is_emergency_call = FALSE;
            }
        }
    }
    else
    {
        is_emergency_call = FALSE;
        g_bgsnd_cntx.is_speech_on = MMI_FALSE;
        mmi_bgsnd_util_stop_play_sound();
    }
}
#endif /* __UCM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_cm_stop_play_sound
 * DESCRIPTION
 *  This function is to stop play sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_cm_stop_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_UTIL_STOP_PLAY_SOUND, g_bgsnd_cntx.cm.status);
    
    StopTimer(BGSND_INTERVAL_TIMER);

    if (g_bgsnd_cntx.cm.status)
    {
        mdi_audio_snd_stop();

        /* Hide Title Indication Icon */
        HideStatusIcon(STATUS_ICON_BG_SOUND);
        UpdateStatusIcons();
        g_bgsnd_cntx.cm.status = 0;
    }
}


#ifdef __UCM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_set_open_bgs_permit_state
 * DESCRIPTION
 *  This function is to set the background sound control state and default value
 *  before the first call (include MO and MT).
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_set_open_bgs_permit_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get default play type for in call usage, if this function is invoked, it must be the first call */
    g_bgsnd_cntx.cm.play_type = g_bgsnd_cntx.set.play_type;
    g_bgsnd_cntx.cm.interval_sec = g_bgsnd_cntx.set.interval_sec;
    g_bgsnd_cntx.cm.volume = g_bgsnd_cntx.set.volume;
    
    g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;


    g_bgsnd_cntx.cm.status = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_get_mo_bgs_permit_state
 * DESCRIPTION
 *  This function is to get the background sound mo control state when make call.
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  BOOL
 *  Return true when background sound is permitted in mo call. or return false.
 *****************************************************************************/
BOOL mmi_bgsnd_common_get_mo_bgs_permit_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.set.status == 1)
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
 *  mmi_bgsnd_common_get_mtmo_bgs_curr_effect
 * DESCRIPTION
 *  This function is to get default selected effect index.
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  U8
 *  Return default selected effect index.
 *****************************************************************************/
U8 mmi_bgsnd_common_get_mtmo_bgs_curr_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*provide the default selected effect in the first call*/
    if (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT)
    {
        return g_bgsnd_cntx.set.curr_effect + 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_set_highlight_index
 * DESCRIPTION
 *  This function notifies the background sound which sound effect is selected to be played.
 * PARAMETERS
 *  U16  [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_bgsnd_common_mtmo_set_highlight_index(U16 highlight_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlight_index > BGSND_TOTAL_EFFECT)
    {
        return FALSE;
    }
    else
    {
        bgsnd_common_hilight = highlight_index;
        
        /*call management has not to change setting*/
        bgsnd_cm_state = MMI_FALSE;

        //mmi_bgsnd_common_set_open_bgs_permit_state();
        //bgsnd_common_default = MMI_TRUE;
    #ifdef __DRM_SUPPORT__
        mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_common_hilight, TRUE);
    #endif
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_effect_list
 * DESCRIPTION
 *  This function is to prepare the effect list. (Including default and external)
 * PARAMETERS
 *  PS8       [IN] ==> Pointer array to store the effects names in effect list
 *  S32       [IN] ==> Numbers of pointers in array, it is 21
 *  S32       [IN] ==> The buffer size of per pointer in array, it is 41*ENCODING_LENGTH + ENCODING_LENGTH, This is MAX_SUB_MENU_SIZE
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bgsnd_common_mtmo_prepare_effect_list(PS8 subMenuListDataPtrs[], S32 numofptrs, S32 one_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    S8 *file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((numofptrs >= 21) && (one_buffer_size >= MAX_SUB_MENU_SIZE));
    mmi_ucs2ncpy(subMenuListDataPtrs[0], GetString(STR_ID_BGSND_NO_EFFECT), MAX_SUBMENU_CHARACTERS);

    /* default effect */
    for (index = 0; index < BGSND_MAX_EFFECT; index++)
    {
        mmi_ucs2ncpy(
            subMenuListDataPtrs[index + 1],
            GetString((U16) (STR_ID_BGSND_EFFECT_1 + index)),
            MAX_SUBMENU_CHARACTERS);
    }

    /* external effect */
    for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (read_buff[0] == '\0' && read_buff[1] == '\0')
        {
            mmi_ucs2cpy((PS8) subMenuListDataPtrs[index + BGSND_MAX_EFFECT + 1], GetString(STR_GLOBAL_EMPTY_LIST));
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else    /* Truncate file name */
        {
            file_name = mmi_fmgr_extract_file_name((S8*) read_buff);
            mmi_ucs2ncpy(
                (S8*) subMenuListDataPtrs[index + BGSND_MAX_EFFECT + 1],
                (S8*) file_name,
                MAX_SUBMENU_CHARACTERS);
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }
    return BGSND_TOTAL_EFFECT + 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_check_ext_file_format
 * DESCRIPTION
 *  This function is to check if the file format is right.
 * PARAMETERS
 *  void  [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bgsnd_common_mtmo_check_ext_file_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    mdi_result result;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_CALL_MAKE_CALL, bgsnd_mo_highlight);
    MMI_ASSERT(bgsnd_common_hilight < (BGSND_TOTAL_EFFECT + 1));
    if ((bgsnd_common_hilight >= (BGSND_MAX_EFFECT + 1)) && (bgsnd_common_hilight < (BGSND_TOTAL_EFFECT + 1)))
    {
        index = bgsnd_common_hilight - BGSND_MAX_EFFECT - 1;
        /* File not exists */
        if (!mmi_bgsnd_util_get_ext_effect_status(index))
        {
            return BGSND_NO_EFFECT;//no effect
        }
        else    /* File exists, check its format */
        {
        #ifdef __USB_IN_NORMAL_MODE__
        /* check is in mass storage mode */
            if (mmi_usb_is_in_mass_storage_mode())
            { 
                 return BGSND_USB_NOT_ALLOWED;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */
            
        #ifdef __DRM_SUPPORT__////// it will cause error
            if (!g_bgsnd_cntx.drm_permission_state)
            {
                return BGSND_DRM_PROHIBIT;//drm prohibit
            }
            else
        #endif
            {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (index + 1),
                (void*)read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);
            result = mdi_audio_snd_check_file_format((void*)read_buff);
          }
        }

        /* Check file success */
        if (result == MDI_AUDIO_SUCCESS)
        {
            bgsnd_common_select = MMI_TRUE;
            return BGSND_AUDIO_SUCCESS;//format is right
        }
        else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
        {
            return BGSND_AUDIO_OPEN_FILE_FAIL;// open fail
        }
        else if (result == MDI_AUDIO_BAD_FORMAT)
        {
            return BGSND_AUDIO_BAD_FORMAT;//bad format
        }
        else
        {
            return BGSND_PLAY_FAIL;//other fail
        }
    }
    else
    {
        bgsnd_common_select = MMI_TRUE;
        return BGSND_AUDIO_SUCCESS;
     }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_get_uniform_popup_string_id
 * DESCRIPTION
 *  This function is used to get the corresponding string id.
 * PARAMETERS
 *  U8        error codename value
 * RETURNS
 *  U16      the corresponding string id.
 *****************************************************************************/
U16 mmi_bgsnd_common_get_uniform_popup_string_id(U8 error_index)//invoked when the call change into activing state
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_index == BGSND_NO_EFFECT)
    {
        return STR_ID_BGSND_NO_EFFECT;
    }
    else if (error_index == BGSND_DRM_PROHIBIT)
    {
        return STR_GLOBAL_DRM_PROHIBITED;
    }
    else if (error_index == BGSND_AUDIO_OPEN_FILE_FAIL)
    {
        return STR_ID_BGSND_OPEN_FILE_FAIL;
    }
    else if (error_index == BGSND_AUDIO_BAD_FORMAT)
    {
        return STR_ID_BGSND_INVALID_FILE;
    }
    else// if(error_index == BGSND_PLAY_FAIL)
    {
        return STR_ID_BGSND_PLAY_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_mo_play_sound
 * DESCRIPTION
 *  This function is to play background sound effect when after mo call connected.
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
void mmi_bgsnd_common_mtmo_play_sound(void)//invoked when the call change into activing state
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G5_CM, MMI_BGSND_MO_PLAY_SOUND);
    if (!bgsnd_common_default)
    {
        mmi_bgsnd_common_set_open_bgs_permit_state();
        bgsnd_common_default = MMI_TRUE;
    }
    
    if ((bgsnd_common_hilight > 0) && bgsnd_common_select)
    {
        if (!bgsnd_cm_state)
        {
            g_bgsnd_cntx.cm.curr_effect = bgsnd_common_hilight - 1;
        }
        mmi_bgsnd_util_play_sound(g_bgsnd_cntx.cm.curr_effect);
    }
    else    /* No effect selected */
    {
        /*set the default setting value if not change the setting state during call*/
        if (!bgsnd_cm_state)
        {
            g_bgsnd_cntx.cm.curr_effect = g_bgsnd_cntx.set.curr_effect;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_common_mtmo_reset_state
 * DESCRIPTION
 *  This function is to reset state that if to play background sound effect when call connected.
 * PARAMETERS
 *  MMI_BOOL   allow_play
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_common_mtmo_reset_state(MMI_BOOL allow_play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*allow_play is the flag deciding if to play BGS*/
    if (allow_play)
    {
        bgsnd_common_select = MMI_TRUE;
    }
    else
    {
        bgsnd_common_select = MMI_FALSE;
    }
}


#endif /* __UCM_SUPPORT__*/

#endif /* __MMI_BG_SOUND_EFFECT__ */ /* _MMI_BGSOUNDINCALL_C */
#endif /* _MMI_BGSOUNDINCALL_C */ /* _MMI_BGSOUNDSETTING_C */

