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
 * BGSoundSetting.C
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_BGSOUNDSETTING_C
#define _MMI_BGSOUNDSETTING_C


#ifdef __MMI_BG_SOUND_EFFECT__

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "nvram_user_defs.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgr.h"
/* ... Add More MMI header */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "BGSoundDef.h"
#include "BGSoundType.h"
#include "BGSoundProt.h"
#include "ProfileGProts.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#include "drm_def.h"
#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 

#if defined(__MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif
#ifdef __CTM_SUPPORT__ 
#include "TextPhoneProt.h"
#endif

#include "USBDeviceGprot.h"//usb

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
bgsnd_context_struct g_bgsnd_cntx;

/* 
 * Local Function
 */
static S32 bgsnd_repeat;
S8 *bgsnd_repeat_str[BGSND_REPEAT_NUM];

static UI_character_type bgsnd_interval_buf[BGSND_INTERVAL_LEN];
static UI_character_type bgsnd_volume_buf[BGSND_VOLUME_LEN];

static U16 bgsnd_curr_highlight;
static U16 bgsnd_open_fail_index;   /* The index is to keep the open/play fail file index */

static U8 bgsnd_ext_effect[BGSND_MAX_EXT_EFFECT / 8 + 1];

static U8 bgsnd_previous_index;
static BOOL is_curr_popup;
/* 
 * Global Variable
 */

/* 
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_init
 * DESCRIPTION
 *  This function is to initialize MMI background sound related variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_previous_index = 0xFF;
    is_curr_popup = FALSE;
    
    mmi_bgsnd_call_setup_init();

    /* Read NVRAM data */
    if (!g_bgsnd_cntx.is_init)
    {
        mmi_bgsnd_util_read_setup_data();
        g_bgsnd_cntx.is_init = TRUE;
    }

    g_bgsnd_cntx.setup_playing = FALSE;
    bgsnd_open_fail_index = BGSND_TOTAL_EFFECT;

#ifdef __DRM_SUPPORT__
    g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_NONE;
    g_bgsnd_cntx.drm_permission_state = TRUE;
#endif

    mmi_bgsnd_call_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_call_setup_init
 * DESCRIPTION
 *  This function is to initialize background sound in call setup part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_call_setup_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __UCM_SUPPORT__
    SetHiliteHandler(MENU_ID_BGSND_CALL_SETUP, mmi_bgsnd_highlight_call_setup);
#endif /* __UCM_SUPPORT__ */

    SetHiliteHandler(MENU_ID_BGSND_CALL_SETUP_STATUS, mmi_bgsnd_highlight_cs_status);
    SetHiliteHandler(MENU_ID_BGSND_CALL_SETUP_SETTING, mmi_bgsnd_highlight_cs_playback_setup);
    SetHiliteHandler(MENU_ID_BGSND_CALL_SETUP_LIST, mmi_bgsnd_highlight_cs_effect_list);

    SetHintHandler(MENU_ID_BGSND_CALL_SETUP_STATUS, mmi_bgsnd_hint_cs_status);

    SetHiliteHandler(MENU_ID_BGSND_EXT_EFFECT_SELECT, mmi_bgsnd_highlight_cs_ext_effect_select);
    SetHiliteHandler(MENU_ID_BGSND_EXT_EFFECT_EDIT, mmi_bgsnd_highlight_cs_ext_effect_edit);
    SetHiliteHandler(MENU_ID_BGSND_EXT_EFFECT_DELETE, mmi_bgsnd_highlight_cs_ext_effect_delete);
    SetHiliteHandler(MENU_ID_BGSND_EXT_EFFECT_ADD, mmi_bgsnd_highlight_cs_ext_effect_add);
}

#define MMI_BGSND_CS_MAIN


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_call_setup
 * DESCRIPTION
 *  This function is the highlight function of background sound setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_call_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_bgsnd_pre_entry_call_setup, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_pre_entry_call_setup, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_pre_entry_call_setup
 * DESCRIPTION
 *  This function is the pre entry function for sound effect setup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_pre_entry_call_setup(void)
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
        mmi_bgsnd_entry_call_setup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_call_setup
 * DESCRIPTION
 *  This function is the entry function of background ground sound setting main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_call_setup(void)
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
    EntryNewScreen(SCR_ID_BGSND_CALL_SETUP, NULL, mmi_bgsnd_entry_call_setup, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BGSND_CALL_SETUP);
    nNumofItem = GetNumOfChild(MENU_ID_BGSND_CALL_SETUP);
    GetSequenceStringIds(MENU_ID_BGSND_CALL_SETUP, nStrItemList);
    SetParentHandler(MENU_ID_BGSND_CALL_SETUP);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_BGSND_CALL_SETUP, hintList);

    /* Screen with hint, if no hint needed, can change to Screen 15 */
    ShowCategory52Screen(
        STR_ID_BGSND_BG_SOUND,
        #ifdef __UCM_SUPPORT__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        #endif
        STR_GLOBAL_EDIT,
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

#define MMI_BGSND_CS_STATUS


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_status
 * DESCRIPTION
 *  This function is the highlight function for status setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.set.status != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    SetLeftSoftkeyFunction(mmi_bgsnd_cs_status_toggle, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //SetKeyHandler(mmi_bgsnd_cs_status_toggle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_hint_cs_status
 * DESCRIPTION
 *  This function is the hint function for status setting
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_hint_cs_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

    if (g_bgsnd_cntx.set.status != 0)
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
 *  mmi_bgsnd_cs_status_toggle
 * DESCRIPTION
 *  This function is to toggle the on/off status of background sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_status_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bgsnd_cntx.set.status != 0)
    {
        g_bgsnd_cntx.set.status = 0;
    }
    else
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

            return;
        }
    #endif /* #ifdef __CTM_SUPPORT__ */
        g_bgsnd_cntx.set.status = 1;
    }

    /* Change menu item */
    index = GetIndexOfStringId(MENU_ID_BGSND_CALL_SETUP, STR_ID_BGSND_MO_STATUS);

    if (g_bgsnd_cntx.set.status != 0)
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

    /* Write result to NVRAM */
    mmi_bgsnd_util_write_setup_data();
}

#define MMI_BGSND_CS_PLAYBACK_SETUP


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_playback_setup
 * DESCRIPTION
 *  This function is the highlight function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_playback_setup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_bgsnd_cs_playback_prepare_inline_data, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cs_playback_prepare_inline_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_prepare_inline_data
 * DESCRIPTION
 *  This function is to prepare the inline data for playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_prepare_inline_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* repeat type */
    if (g_bgsnd_cntx.set.play_type < BGSND_REPEAT_NUM)
    {
        bgsnd_repeat = g_bgsnd_cntx.set.play_type;
    }
    else
    {
        bgsnd_repeat = 0;
    }

    /* Interval */
    if (g_bgsnd_cntx.set.interval_sec <= BGSND_MAX_INTERVAL)
    {
        kal_wsprintf(bgsnd_interval_buf, "%d", g_bgsnd_cntx.set.interval_sec);
    }
    else
    {
        memset(bgsnd_interval_buf, 0, 2);
    }

    /* volume */
    if (g_bgsnd_cntx.set.volume <= BGSND_MAX_VOLUME)
    {
        kal_wsprintf(bgsnd_volume_buf, "%d", g_bgsnd_cntx.set.volume);
    }
    else
    {
        memset(bgsnd_volume_buf, 0, 2);
    }

    /* Enter inline editor screen */
    mmi_bgsnd_entry_cs_playback_setup();
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
void mmi_bgsnd_cs_playback_setup_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(mmi_ucs2strlen((S8*)bgsnd_volume_buf) == 0 ||
      ((bgsnd_repeat == BGSND_REPEAT_INTERVAL)&& (mmi_ucs2strlen((S8*)bgsnd_interval_buf) == 0)))
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
        mmi_bgsnd_cs_playback_save_confirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_playback_setup
 * DESCRIPTION
 *  This function is the entry function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_playback_setup(void)
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
    EntryNewScreen(SCR_ID_BGSND_CS_PLAYBACK, mmi_bgsnd_exit_cs_playback_setup, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BGSND_CS_PLAYBACK);
    InitializeCategory57Screen();

    /* RegisterHighlightHandler(mmi_bgsnd_cs_playback_highlight_hdlr); */

    /* Fill each inline editor item */
    mmi_bgsnd_cs_playback_fill_inline_item();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BGSND_CS_PLAYBACK, &inputBufferSize);      /* added for inline edit history */

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

    SetCategory57RightSoftkeyFunctions(mmi_bgsnd_cs_playback_setup_done, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_playback_setup
 * DESCRIPTION
 *  This function is the exit function of playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_playback_setup(void)
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
    Scr.scrnID = SCR_ID_BGSND_CS_PLAYBACK;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_bgsnd_entry_cs_playback_setup;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_repeat_hdlr
 * DESCRIPTION
 *  This function is the inline selection handler for repeat type
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_repeat_hdlr(S32 index)
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
 *  mmi_bgsnd_cs_playback_fill_inline_item
 * DESCRIPTION
 *  This function is to fill the inline item for the playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_fill_inline_item(void)
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
   // SetInlineItemCaption(&(wgui_inline_items[BGSND_SETUP_VOLUME_CAP]), (U8*) GetString(STR_ID_BGSND_VOLUME_CAP));
//#endif 

   /*-- Volume --*/
    SetInlineItemActivation(&wgui_inline_items[BGSND_SETUP_VOLUME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[BGSND_SETUP_VOLUME],
        (U8*) bgsnd_volume_buf,
        BGSND_VOLUME_LEN,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_VOLUME]);

   /*-- Repeat Type --*/
    SetInlineItemActivation(&(wgui_inline_items[BGSND_SETUP_REPEAT]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &(wgui_inline_items[BGSND_SETUP_REPEAT]),
        BGSND_REPEAT_NUM,
        (U8 **) bgsnd_repeat_str,
        &bgsnd_repeat);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[BGSND_SETUP_REPEAT], mmi_bgsnd_cs_playback_repeat_hdlr);

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
        (U8*) bgsnd_interval_buf,
        BGSND_INTERVAL_LEN,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[BGSND_SETUP_INTERVAL]);

    if (bgsnd_repeat != BGSND_REPEAT_INTERVAL)  /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[BGSND_SETUP_INTERVAL], BGSND_SETUP_INTERVAL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_save_confirm
 * DESCRIPTION
 *  This function is to confirm save before saving playback setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_save_confirm(void)
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
        get_string(STR_ID_BGSND_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_bgsnd_cs_playback_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_bgsnd_cs_playback_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_save
 * DESCRIPTION
 *  This function is to save the playback setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_save(void)
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
    mmi_ucs2_to_asc(ascii_volume, (S8*) bgsnd_volume_buf);
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
    if (bgsnd_repeat == BGSND_REPEAT_INTERVAL)
    {
        mmi_ucs2_to_asc(ascii_interval, (S8*) bgsnd_interval_buf);
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
    g_bgsnd_cntx.set.play_type = (U8) bgsnd_repeat;
    g_bgsnd_cntx.set.interval_sec = interval_value;
    g_bgsnd_cntx.set.volume = (U8) volume_value;

    mmi_bgsnd_util_write_setup_data();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CS_PLAYBACK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_playback_abort
 * DESCRIPTION
 *  This function is to abort setting and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_playback_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_go_back_2_history();
}

#define MMI_BGSND_CS_EFFECT_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_effect_list
 * DESCRIPTION
 *  This function is the highlight function for the effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_bgsnd_entry_cs_effect_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_entry_cs_effect_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_highlight_callback
 * DESCRIPTION
 *  This function is the time out callback function for playing sound in effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_highlight_callback(void)
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
    if (bgsnd_curr_highlight < BGSND_MAX_EFFECT)
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsSilentModeActivated() && !IsMeetingModeActivated())
    #else 
        if (!IsSilentModeActivated())
    #endif 
        {
            mmi_bgsnd_util_play_by_highlight_index(bgsnd_curr_highlight);
        }
    }
    /* external file */
    else if (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT)
    {
        index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;
        ReadRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)read_buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
        #ifdef __MMI_SILENT_MEETING_PROFILE__
            if (!IsSilentModeActivated() && !IsMeetingModeActivated())
        #else 
            if (!IsSilentModeActivated())
        #endif 
            {
                if (mmi_bgsnd_check_usb_mode())
                {
                    is_curr_popup = TRUE;
                    return;
                }
                mmi_bgsnd_util_play_file((U16*) read_buff);
            }
        }
        else
        {
            bgsnd_open_fail_index = BGSND_TOTAL_EFFECT;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for effect list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_curr_highlight = index;
    mmi_bgsnd_util_stop_setup_play_sound();

    if (index < BGSND_MAX_EFFECT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_bgsnd_cs_effect_select_item, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    }
    else    /* External File */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_pre_entry_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_bgsnd_cs_ext_pre_entry_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

#ifdef __DRM_SUPPORT__
    mmi_bgsnd_util_ext_effect_check_forward_rule(bgsnd_curr_highlight, FALSE);
#else
    if ((bgsnd_previous_index != bgsnd_curr_highlight) || (!is_curr_popup))
    {
    if (bgsnd_previous_index != bgsnd_curr_highlight)
    {
        bgsnd_previous_index = bgsnd_curr_highlight;
            is_curr_popup = FALSE;
        }
        StartTimer(BGSND_HIGHLIGHT_TIMER, BGSND_HIGHLIGHT_TIMER_DUR, mmi_bgsnd_cs_effect_highlight_callback);
    }
#endif/*__DRM_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_effect_list
 * DESCRIPTION
 *  This function is the entry function for the effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Pause background play */
    if (!is_curr_popup)
    {
        bgsnd_previous_index = 0xFF;
    }

    mdi_audio_suspend_background_play();

    /* it is effect list under setting at present */
#ifdef __DRM_SUPPORT__
    g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_SETTING;
#endif /*  __DRM_SUPPORT__ */

    EntryNewScreen(SCR_ID_BGSND_CS_EFFECT, mmi_bgsnd_exit_cs_effect_list, mmi_bgsnd_entry_cs_effect_list, NULL);

    RegisterHighlightHandler(mmi_bgsnd_cs_effect_highlight_hdlr);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BGSND_CS_EFFECT);

    if ((gui_buffer == NULL) && (g_bgsnd_cntx.set.curr_effect < BGSND_TOTAL_EFFECT))
    {
        bgsnd_curr_highlight = g_bgsnd_cntx.set.curr_effect;
        bgsnd_open_fail_index = BGSND_TOTAL_EFFECT;
    }

    /* fill effect list data */
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
        bgsnd_curr_highlight,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_bgsnd_cs_effect_stop_and_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cs_effect_stop_and_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_effect_list
 * DESCRIPTION
 *  This function is the exit function of effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_curr_popup = FALSE;
    mmi_bgsnd_util_stop_setup_play_sound();

    /* it is out of effect list under setting */
#ifdef __DRM_SUPPORT__
    g_bgsnd_cntx.current_function_status = BGSND_FUNCTION_NONE;
#endif /* __DRM_SUPPORT__ */

    /* resume background play */
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_stop_and_back
 * DESCRIPTION
 *  This function is to stop playing background sound and go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_stop_and_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_util_stop_setup_play_sound();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_effect_select_item
 * DESCRIPTION
 *  This function is to save the effect list selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_effect_select_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.set.curr_effect = (U8) bgsnd_curr_highlight;
    mmi_bgsnd_util_write_setup_data();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CS_EFFECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_ext_effect_select
 * DESCRIPTION
 *  This function is the highlight function for select the external file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_ext_effect_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_effect_select_item, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cs_ext_effect_select_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_ext_effect_edit
 * DESCRIPTION
 *  This function is the highlight function for edit the external file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_ext_effect_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_effect_select_from_fmgr, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cs_ext_effect_select_from_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_ext_effect_delete
 * DESCRIPTION
 *  This function is the highlight function for delete the external file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_ext_effect_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_effect_delete_confirm, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_highlight_cs_ext_effect_add
 * DESCRIPTION
 *  This function is the highlight function for add the external file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_highlight_cs_ext_effect_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_effect_select_from_fmgr, KEY_EVENT_UP);
    SetKeyHandler(mmi_bgsnd_cs_ext_effect_select_from_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_pre_entry_option
 * DESCRIPTION
 *  This function is check the external file state before operate on external sound effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_pre_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 str_id = 0;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    U16 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = bgsnd_curr_highlight - BGSND_MAX_EFFECT;
    g_bgsnd_cntx.file_exist = TRUE;

    if (mmi_bgsnd_check_usb_mode())
    {
        is_curr_popup = TRUE;
        return;
    }

    /* If external file exists, check its correctness. */
    if (mmi_bgsnd_util_get_ext_effect_status(curr_index))
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (curr_index + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);
    #ifdef __DRM_SUPPORT__
        if (!g_bgsnd_cntx.drm_permission_state)
        {
            DisplayConfirm(
                STR_GLOBAL_OK,
                0, 0, 0,
                get_string(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                WARNING_TONE);
            SetLeftSoftkeyFunction(mmi_bgsnd_entry_cs_ext_effect_option, KEY_EVENT_UP);
            return;
        }
        else
    #endif
        {
        result = mdi_audio_snd_check_file_format((void*)read_buff);
    }
    }
    else    /* Not select yet. */
    {
        result = MDI_AUDIO_SUCCESS;
    }

    /* Check file success */
    if (result == MDI_AUDIO_SUCCESS)
    {
        mmi_bgsnd_entry_cs_ext_effect_option();
        return;
    }
    else if (result == MDI_AUDIO_OPEN_FILE_FAIL)
    {
        str_id = STR_ID_BGSND_OPEN_FILE_FAIL;
        g_bgsnd_cntx.file_exist = FALSE;
    }
    else if (result == MDI_AUDIO_BAD_FORMAT)
    {
        str_id = STR_ID_BGSND_INVALID_FILE;
        g_bgsnd_cntx.file_exist = FALSE;
    }
    else
    {
        str_id = STR_ID_BGSND_PLAY_FAIL;
        g_bgsnd_cntx.file_exist = FALSE;
    }

    /* Check file fail, prompt user */
    DisplayConfirm(STR_GLOBAL_OK, 0, 0, 0, get_string(str_id), IMG_GLOBAL_INFO, WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_bgsnd_entry_cs_ext_effect_option, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_exit_cs_ext_effect_option
 * DESCRIPTION
 *  This function is the exit function for the external file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_exit_cs_ext_effect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__
    if (!g_bgsnd_cntx.drm_permission_state)
    {
        mmi_frm_unhide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
    #endif
    if (!g_bgsnd_cntx.file_exist)
    {
        mmi_frm_unhide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_entry_cs_ext_effect_option
 * DESCRIPTION
 *  This function is the entry function for the external file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_entry_cs_ext_effect_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U16 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_bgsnd_cntx.file_exist)
    {
        mmi_frm_hide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
#ifdef __DRM_SUPPORT__
    if (!g_bgsnd_cntx.drm_permission_state)
    {
        mmi_frm_hide_menu_item(MENU_ID_BGSND_EXT_EFFECT_SELECT);
    }
#endif
    EntryNewScreen(SCR_ID_BGSND_CS_EXT_EFFECT_OPT, mmi_bgsnd_exit_cs_ext_effect_option, mmi_bgsnd_entry_cs_ext_effect_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BGSND_CS_EXT_EFFECT_OPT);

    /* Check if file already selected */
    if (mmi_bgsnd_util_get_ext_effect_status((U16) (bgsnd_curr_highlight - BGSND_MAX_EFFECT)))
    {
        menu_id = MENU_ID_BGSND_EXT_EFFECT_OPTION;
    }
    else
    {
        menu_id = MENU_ID_BGSND_EXT_EFFECT_OPTION_ADD;
    }

    nNumofItem = GetNumOfChild_Ext(menu_id);/*considering the maked item*/
    GetSequenceStringIds_Ext(menu_id, nStrItemList);/*considering the maked item*/
    SetParentHandler(menu_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        #ifdef __UCM_SUPPORT__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        #endif
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_item
 * DESCRIPTION
 *  This function is to save the external effect list selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.set.curr_effect = (U8) bgsnd_curr_highlight;
    mmi_bgsnd_util_write_setup_data();

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CS_EXT_EFFECT_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_from_fmgr
 * DESCRIPTION
 *  This function is to enter file manager to select an external file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* UI_character_type path[MAX_FMSR_PATH_LEN]; */
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_fmsr_util_get_storage_path((UI_string_type)path, (U8)g_fmsr_cntx.setting.storage); */

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    /* FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR); */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_BGSOUND,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root" /* (S8*)path */ ,
        mmi_bgsnd_cs_ext_effect_select_file_done);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_select_file_done
 * DESCRIPTION
 *  This function is the callback function when select from file manager done.
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_select_file_done(void *fullname, int is_short)
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
    if (fullname == NULL)
    {
        GoBackToHistory(SCR_ID_BGSND_CS_EXT_EFFECT_OPT);
    }
    else if (!mmi_bgsnd_util_check_file_format(fullname))
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BGSND_INVALID_FILE),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) ERROR_TONE);
    }
    else
    {
        /* Check if file name duplicated */
        for (index = 0; index < BGSND_MAX_EXT_EFFECT; index++)
        {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (index + 1),
                (void*)read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);

            if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
            {
                if (mmi_ucs2cmp((S8*) fullname, (S8*) read_buff) == 0)
                {
                    DisplayPopup(
                        (U8*) GetString(STR_ID_BGSND_FILE_DUPLICATED),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME_2000,
                        (U8) WARNING_TONE);
                    return;
                }
            }
        }

        /* Update filepath data */
        if ((bgsnd_curr_highlight >= BGSND_MAX_EFFECT) && (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT))
        {
            index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;
            WriteRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)fullname, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);
        }

        fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_BGSND_CS_EXT_EFFECT_OPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_delete_confirm
 * DESCRIPTION
 *  This function is to confirm deleting external file link
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_delete_confirm(void)
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
        get_string(STR_ID_BGSND_DEL_FILE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_bgsnd_cs_ext_effect_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_cs_ext_effect_delete
 * DESCRIPTION
 *  This function is to delete external file link
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_cs_ext_effect_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index;
    S8 buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((bgsnd_curr_highlight >= BGSND_MAX_EFFECT) && (bgsnd_curr_highlight < BGSND_TOTAL_EFFECT))
    {
        index = bgsnd_curr_highlight - BGSND_MAX_EFFECT + 1;

        memset(buff, 0, 2);
        WriteRecord(NVRAM_EF_BGSND_FILEPATH_LID, index, (void*)buff, NVRAM_EF_BGSND_FILEPATH_SIZE, &pError);

        /* Set highlight to first effect */
        if (g_bgsnd_cntx.set.curr_effect == (U8) bgsnd_curr_highlight)
        {
            g_bgsnd_cntx.set.curr_effect = 0;
            mmi_bgsnd_util_write_setup_data();
        }
    }

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_BGSND_CS_EXT_EFFECT_OPT);
}

#define MMI_BGSND_FROM_FMGR


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_fmgr_from_file_mgr
 * DESCRIPTION
 *  This function is to save file path forward from file manager
 * PARAMETERS
 *  path            [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_fmgr_from_file_mgr(S8 *path, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0xFFFF, i;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            ERROR_TONE);
        return;
    }
    else if (!mmi_bgsnd_util_check_file_format(path))
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BGSND_INVALID_FILE),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            (U8) ERROR_TONE);
        return;
    }

    /* Check if file name duplicated */
    for (i = 0; i < BGSND_MAX_EXT_EFFECT; i++)
    {
        ReadRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (i + 1),
            (void*)read_buff,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);

        if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
        {
            if (mmi_ucs2cmp((S8*) path, (S8*) read_buff) == 0)
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_BGSND_FILE_DUPLICATED),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME_2000,
                    (U8) WARNING_TONE);
                return;
            }
        }
    }

    /* Find First Empty slot */
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
            break;
        }
    }

    if (index < BGSND_MAX_EXT_EFFECT)
    {
        WriteRecord(
            NVRAM_EF_BGSND_FILEPATH_LID,
            (U16) (index + 1),
            (void*)path,
            NVRAM_EF_BGSND_FILEPATH_SIZE,
            &pError);
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BGSND_LIST_FULL),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            ERROR_TONE);
    }
}

#define MMI_BGSND_CS_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_effect_list
 * DESCRIPTION
 *  This function is to prepare the effect list. (Including default and external)
 * PARAMETERS
 *  add_no_effect       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_prepare_effect_list(BOOL add_no_effect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 index, base = 0;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    S8 *file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_no_effect)
    {
        mmi_ucs2ncpy((PS8) subMenuDataPtrs[0], GetString(STR_ID_BGSND_NO_EFFECT), MAX_SUBMENU_CHARACTERS);
        base = 1;
    }

    /* default effect */
    for (index = 0; index < BGSND_MAX_EFFECT; index++)
    {
        mmi_ucs2ncpy(
            (PS8) subMenuDataPtrs[index + base],
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
            mmi_ucs2cpy((PS8) subMenuDataPtrs[index + BGSND_MAX_EFFECT + base], GetString(STR_GLOBAL_EMPTY_LIST));
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else    /* Truncate file name */
        {
            file_name = mmi_fmgr_extract_file_name((S8*) read_buff);
            mmi_ucs2ncpy(
                (S8*) subMenuDataPtrs[index + BGSND_MAX_EFFECT + base],
                (S8*) file_name,
                MAX_SUBMENU_CHARACTERS);
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_prepare_ext_file_index
 * DESCRIPTION
 *  This function is to prepare external file index. This is to check
 *  if external file exists for later usage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_prepare_ext_file_index(void)
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
            mmi_bgsnd_util_set_ext_effect_status(index, FALSE);
        }
        else
        {
            mmi_bgsnd_util_set_ext_effect_status(index, TRUE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_callback
 * DESCRIPTION
 *  This function is the callback function when play finish
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_bgsnd_cntx.setup_playing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_by_highlight_index
 * DESCRIPTION
 *  This function is to play a audio string as background sound
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_by_highlight_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 audio_len;
    U8 *audio_data;
    U8 audio_type;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_data = get_audio((U16) (AUD_ID_BGSND_EFFECT1 + index), &audio_type, &audio_len);

    if (audio_data != NULL)
    {
        result = mdi_audio_snd_play_string_with_vol_path(
                    (void*)audio_data,
                    audio_len,
                    0,
                    NULL,
                    mmi_bgsnd_util_play_callback,
                    /*g_bgsnd_cntx.set.volume*/ 5, /* Use constant volume*/
                    MDI_DEVICE_SPEAKER2);

        if (result == MDI_AUDIO_SUCCESS)
        {
            g_bgsnd_cntx.setup_playing = TRUE;
        }
    }

    bgsnd_open_fail_index = BGSND_TOTAL_EFFECT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_play_file
 * DESCRIPTION
 *  This function is to play an external file as background sound
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_play_file(U16 *full_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_open_fail_index = bgsnd_curr_highlight;
#ifdef __DRM_SUPPORT__
    if (!g_bgsnd_cntx.drm_permission_state)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
            is_curr_popup = TRUE;
        return;
    }
#endif /* __DRM_SUPPORT__ */
    result = mdi_audio_snd_play_file_with_vol_path(
                (void*)full_path,
                0,
                NULL,
                mmi_bgsnd_util_play_callback,
                g_bgsnd_cntx.set.volume,
                MDI_DEVICE_SPEAKER2);

    if (result == MDI_AUDIO_SUCCESS)
    {
        g_bgsnd_cntx.setup_playing = TRUE;
        bgsnd_open_fail_index = BGSND_TOTAL_EFFECT;
        return;
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
    is_curr_popup = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_read_setup_data
 * DESCRIPTION
 *  This function is to read setup data in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_read_setup_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 read_buff[NVRAM_EF_BGSND_SETTING_SIZE];
    bgsnd_cs_nvram_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_BGSND_SETTING_LID, 1, (void*)read_buff, NVRAM_EF_BGSND_SETTING_SIZE, &pError);

    read_ptr = (bgsnd_cs_nvram_struct*) read_buff;

    /* Set default NVRAM 0xff value to default system value. */
    if (read_ptr->status == 255)
    {
        read_ptr->status = 0;
        read_ptr->play_type = BGSND_REPEAT_CONTINUE;
        read_ptr->interval_sec = 0;
        read_ptr->volume = BGSND_DEFAULT_VOLUME;
        read_ptr->curr_effect = 0;
    }

    memcpy(&g_bgsnd_cntx.set, read_buff, sizeof(bgsnd_cs_nvram_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_write_setup_data
 * DESCRIPTION
 *  This function is to write setup data back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_write_setup_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 write_buff[NVRAM_EF_BGSND_SETTING_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(write_buff, &g_bgsnd_cntx.set, sizeof(bgsnd_cs_nvram_struct));

    WriteRecord(NVRAM_EF_BGSND_SETTING_LID, 1, (void*)write_buff, NVRAM_EF_BGSND_SETTING_SIZE, &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_check_file_format
 * DESCRIPTION
 *  This function is to check the data format for audio file
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_check_file_format(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_snd_check_file_format(file_name) == MDI_AUDIO_SUCCESS)
    {
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_set_ext_effect_status
 * DESCRIPTION
 *  This function is to store the external file exist/not-exist state in a bit-wise array
 * PARAMETERS
 *  index       [IN]        
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_set_ext_effect_status(U16 index, BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 arr_id;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arr_id = index / 8;
    pos = index - arr_id * 8;

    if (state)
    {
        bgsnd_ext_effect[arr_id] |= 1 << pos;
    }
    else
    {
        bgsnd_ext_effect[arr_id] &= (~(1 << pos));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_get_ext_effect_status
 * DESCRIPTION
 *  This function is to get the external file exist/not-exist state in a bit-wise array
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_util_get_ext_effect_status(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 arr_id;
    U8 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arr_id = index / 8;
    pos = index - arr_id * 8;

    return bgsnd_ext_effect[arr_id] & (1 << pos);
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_ext_effect_check_forward_rule
 * DESCRIPTION
 *  This function is to check the external file can be forwarded or not
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_ext_effect_check_forward_rule(U16 index, BOOL add_no_effect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL drm_ret = TRUE;
    FS_HANDLE fh;
    S16 pError;
    S8 read_buff[NVRAM_EF_BGSND_FILEPATH_SIZE];
    U16 curr_index;
    U16 base;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (add_no_effect)
    {
        base = 1;
    }
    else
    {
        base = 0;
    }
    g_bgsnd_cntx.drm_permission_state = TRUE;
    if ((index >= (BGSND_MAX_EFFECT + base))
        && (index < (BGSND_TOTAL_EFFECT + base)))
    {
        curr_index = index - BGSND_MAX_EFFECT - base;
        
        if ( mmi_bgsnd_util_get_ext_effect_status(curr_index))
        {
            ReadRecord(
                NVRAM_EF_BGSND_FILEPATH_LID,
                (U16) (curr_index + 1),
                (void*) read_buff,
                NVRAM_EF_BGSND_FILEPATH_SIZE,
                &pError);
            if (!(read_buff[0] == '\0' && read_buff[1] == '\0'))
            {
                fh = DRM_open_file((kal_wchar *)read_buff, FS_READ_ONLY, DRM_PERMISSION_PLAY);

                if (fh >= FS_NO_ERROR)
                {
                    if (DRM_get_object_method(fh, NULL) != DRM_METHOD_NONE)
                    {
                        drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_PLAY);
                    }
                    else
                    {
                        drm_ret = TRUE;
                    }
                    DRM_close_file(fh);
                }
                /* if file not opened, it is processed in play api,
                important: in highlight handler api, in general not allowed popup, 
                otherwise will be traped in infinite loop */
            }
            if (drm_ret == FALSE)
            {
                g_bgsnd_cntx.drm_permission_state = FALSE;
            }
            else
            {
                g_bgsnd_cntx.drm_permission_state = TRUE;
            }
        }
    }
    if (g_bgsnd_cntx.current_function_status == BGSND_FUNCTION_SETTING)
    {
       if ((bgsnd_previous_index != bgsnd_curr_highlight) || (!is_curr_popup))
       {
        if (bgsnd_previous_index != bgsnd_curr_highlight)
        {
            bgsnd_previous_index = bgsnd_curr_highlight;
	       is_curr_popup = FALSE;
	    }
            StartTimer(BGSND_HIGHLIGHT_TIMER, BGSND_HIGHLIGHT_TIMER_DUR, mmi_bgsnd_cs_effect_highlight_callback);
        }
    }
}
#endif/* __DRM_SUPPORT__  */


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_stop_setup_play_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_stop_setup_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BGSND_HIGHLIGHT_TIMER);
    mdi_audio_snd_stop();
    g_bgsnd_cntx.setup_playing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_util_setup_sd_plug_out_hdlr
 * DESCRIPTION
 *  handle CARD plug-out event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_util_setup_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Playing in the setup menu */
    if (g_bgsnd_cntx.setup_playing && (bgsnd_curr_highlight >= BGSND_MAX_EFFECT))
    {
        mmi_bgsnd_util_stop_setup_play_sound();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bgsnd_go_back_2_history
 * DESCRIPTION
 *  This function is to go back 2 level of history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bgsnd_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_bgsnd_check_usb_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return TRUE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    return FALSE;
}

#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#endif /* _MMI_BGSOUNDSETTING_C */ 

