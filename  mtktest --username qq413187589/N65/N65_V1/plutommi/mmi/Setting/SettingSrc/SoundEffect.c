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
* SoundEffect.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends to setup sound effect.
*
* Author:
* -------
* Tim Chen
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_include.h"

#include "wgui_status_icons.h"
#include "SettingDefs.h"
#include "SettingResDef.h"
#include "SettingsGdcl.h"
#include "settingstructs.h"
#include "settinggprots.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProt.h"
#include "SettingProfile.h"
#include "SoundEffect.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_AUDIO_EQUALIZER__)
#include "UserProfilesResDef.h"
#endif

#ifdef __MMI_SOUND_EFFECT__

#if defined(__MMI_AUDIO_EQUALIZER__) ||  defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
S32 g_settings_selected_audio_effect; /* indicate which audio effect to apply */
S32 g_settings_current_audio_effect; /* when user choose back option, the _current_ variables can be used to reset */
S32 g_settings_current_audio_effect_prev;
S32 g_settings_current_effect_index;
UI_string_type g_settings_audio_effects_inline1[NO_OF_SETTINGS_SOUND_EFFECTS];
UI_string_type g_settings_audio_effects_inline2[MAX_EQUALIZER_NUM]; /*use MAX_EQUALIZER_NUM since currently it is the largest one*/
#endif

#if defined(__MMI_AUDIO_EQUALIZER__)

audio_equalizer_struct g_settings_audio_equalizer;
U16 current_audio_equalizer_index;

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__

#include "nvram_default_audio.h"

extern equalizer_setting_info g_audio_equalizer_current_setting_info;
extern float one_pixel_represents;
void mmi_settings_audio_equalizer_adjust_values_for_editor(audio_equalizer_struct *);
static UI_character_type name_text_editor_buffer[SETTING_NAME_MAX_LEN];
U16 setting_name_edit_option_highlighted_item_text;
BOOL g_audio_equalizer_setting_modified = FALSE;
extern U16 g_audio_equalizer_scrollable_ht, g_audio_equalizer_unit_scroll;
extern void mmi_aud_eq_init_image_specific_vals(void);
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER__ */ 

#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
audio_3d_effect_struct g_mmi_aud_3d_cntx;

#ifdef __MMI_AUDIO_REVERB_EFFECT__
U16 current_audio_reverb_index;
extern const S16 *audio_Reverb_effect_table[];
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
U16 current_audio_surround_index;
#endif

#endif /* __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

#endif /* __MMI_SOUND_EFFECT__ */ 

audio_mic_volume_struct g_settings_audio_mic_volume;


/*****************************************************************************
 * FUNCTION
 *  InitSoundEffect
 * DESCRIPTION
 *  This function is for initializing the Sound efeects application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSoundEffect(void)
{
#ifdef __MMI_SOUND_EFFECT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_SETTING_SOUND_EFFECT, mmi_settings_sound_effect_highlight_hdlr);

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    SetHiliteHandler(MENU_SETTING_AUDIO_EFFECT, mmi_settings_audio_effect_highlight_hdlr);
#endif

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    SetHiliteHandler(
        MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_SELECT,
        mmi_settings_audio_equalizer_opt_select_highlight_hdlr);
    SetHiliteHandler(MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_EDIT, mmi_settings_audio_equalizer_opt_edit_highlight_hdlr);
    SetHiliteHandler(
        MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RENAME,
        mmi_settings_audio_equalizer_opt_rename_highlight_hdlr);
    SetHiliteHandler(
        MENU_SETTING_AUDIO_EQUALIZER_SET_OPT_RESET,
        mmi_settings_audio_equalizer_opt_reset_highlight_hdlr);
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */


#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)
    /* Init Audio EQ Effect */
#ifdef __MMI_AUDIO_EQUALIZER__
    mmi_settings_audio_eq_init();
#endif

    /* Init Audio Reverb Effect */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    mmi_settings_audio_reverb_init();
#endif 

    /* Init Audio Surround Effect */
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    mmi_settings_audio_surround_init();
#endif

    /* Init Audio Effect */
    mmi_settings_audio_effect_init();
#endif /*__MMI_AUDIO_EQUALIZER__ || __MMI_AUDIO_REVERB_EFFECT__ || __MMI_AUDIO_SURROUND_EFFECT__*/

#endif /* __MMI_SOUND_EFFECT__ */ 
    mmi_settings_read_audio_mic_volume_from_nvram(&g_settings_audio_mic_volume);

}

#ifdef __MMI_SOUND_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_sound_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the sound effect menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_sound_effect_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_settings_entry_sound_effect_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_settings_entry_sound_effect_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_sound_effect_list
 * DESCRIPTION
 *  This function is entry function for the sound effect list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_sound_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n_items;
    U8 *guiBuffer;
    U16 item_strs[10];
    U16 item_icons[10];
    U8 *item_hints[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SETTING_SOUND_EFFECT, NULL, mmi_settings_entry_sound_effect_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_SOUND_EFFECT);
    n_items = GetNumOfChild(MENU_SETTING_SOUND_EFFECT);

    GetSequenceStringIds(MENU_SETTING_SOUND_EFFECT, item_strs);
    GetSequenceImageIds(MENU_SETTING_SOUND_EFFECT, item_icons);

    SetParentHandler(MENU_SETTING_SOUND_EFFECT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_SETTING_SOUND_EFFECT, (U8 **) item_hints);

    ShowCategory52Screen(
        STR_ID_SETTING_SOUND_EFFECT,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        item_strs,
        item_icons,
        (U8 **) item_hints,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for audio effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(mmi_settings_entry_audio_effect, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_settings_entry_audio_effect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_screen_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_screen_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    BOOL editable_EQ = FALSE ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    {
        editable_EQ = TRUE;
    }

    if(editable_EQ)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetCategory57LeftSoftkeyFunction(mmi_settings_entry_audio_equalizer_setting_options);
    }
    else
#endif        
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(mmi_settings_audio_effect_settings_done);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settnigs_audio_effect_inlineitem_highlight_hdlr_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settnigs_audio_effect_inlineitem_highlight_hdlr_1(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("aud effect: inlineitem_highlight_hdlr_1(), index = %d",index);

    if(g_settings_current_audio_effect_prev == index)
        return ;

    switch(index)
    {
        case SETTINGS_SOUND_EFFECTS_NONE:
            g_settings_current_audio_effect = index;            
            break;
            
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ:
            g_settings_current_effect_index = current_audio_equalizer_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif
    
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB:
            g_settings_current_effect_index = current_audio_reverb_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif

    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND:
            g_settings_current_effect_index = current_audio_surround_index ;
            g_settings_current_audio_effect = index;
            break;
    #endif
    
        default:
            MMI_ASSERT(FALSE); /*shall not happen*/
            break;
    }

    EntryNewScreen(SETTINGS_BASE,NULL,NULL,NULL);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_inlineitem_highlight_hdlr_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_inlineitem_highlight_hdlr_2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("aud effect: inlineitem_highlight_hdlr_2(), audio_effect = %d ,index = %d",g_settings_current_audio_effect,index);

#ifdef __MMI_AUDIO_EQUALIZER__
    if (g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    { 
        current_audio_equalizer_index = index; 
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        current_audio_reverb_index = index ;
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        current_audio_surround_index = index ;
    }
    else
#endif
    {
        MMI_ASSERT(FALSE); /*shall not happen*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error ;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ReadValue(NVRAM_BYTE_AUDIO_EFFECT_INDEX, &g_settings_selected_audio_effect, DS_BYTE, &error);
    if(g_settings_selected_audio_effect >= NO_OF_SETTINGS_SOUND_EFFECTS)
    {
       g_settings_selected_audio_effect = 0 ; 
       write_value = g_settings_selected_audio_effect ;
       WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
    }

#ifdef __MMI_AUDIO_EQUALIZER__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    {
        mdi_audio_eq_set_magnitude((S8*)g_settings_audio_equalizer.magnitude[g_settings_audio_equalizer.index]);
        mdi_audio_eq_turn_on();
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        mmi_settings_audio_reverb_effect_init(g_mmi_aud_3d_cntx.reverb_index);
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        mmi_settings_audio_surround_effect_init(g_mmi_aud_3d_cntx.surround_index);
    }
    else
#endif
    {
        /* shall not get in this option*/
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_turn_off_audio_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_turn_off_audio_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_EQUALIZER__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ)
    {
        PRINT_INFORMATION("aud effect: mdi_audio_eq_turn_off()");
        mdi_audio_eq_turn_off();
    }
    else
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
    {
        PRINT_INFORMATION("aud effect: mdi_audio_reverb_turn_off()");
        mdi_audio_reverb_turn_off();

        HideStatusIcon(STATUS_ICON_REVERB_SOUND);
        UpdateStatusIcons();
    }
    else
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_SURROUND)
    {
        PRINT_INFORMATION("aud effect: mdi_audio_surround_turn_off()");
        mdi_audio_surround_turn_off();

        HideStatusIcon(STATUS_ICON_AUD_SURROUND);
        UpdateStatusIcons();        
    }
    else
#endif
    {
        /* shall not get in this option*/
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_write_nvram
 * DESCRIPTION
 *  This function is to write effect index back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_settings_selected_audio_effect < NO_OF_SETTINGS_SOUND_EFFECTS)
    {
        write_value = (U8) g_settings_selected_audio_effect;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_EFFECT_INDEX, &write_value, DS_BYTE, &error);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL result = MDI_AUDIO_SUCCESS;
    BOOL need_popup = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if(g_settings_selected_audio_effect != g_settings_current_audio_effect || 
       g_settings_current_audio_effect == SETTINGS_SOUND_EFFECTS_NONE)

    {
        mmi_settings_turn_off_audio_effect();
    }

    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            result = mmi_settings_audio_eq_apply((S16) current_audio_equalizer_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :
            result = mmi_settings_audio_reverb_apply(current_audio_reverb_index);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :
            mmi_settings_audio_surround_apply_check(current_audio_surround_index);
            need_popup = FALSE;
            break;
    #endif
        default :
            break;
    }

    g_settings_selected_audio_effect = g_settings_current_audio_effect;
    mmi_settings_audio_effect_write_nvram();

    if(!need_popup)
    {
        return;
    }
    
    if(result == MDI_AUDIO_SUCCESS )
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
    }
    
    DeleteUptoScrID(SCR_ID_SETTING_SOUND_EFFECT);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_effect_settings_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_effect_settings_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_exit_audio_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_exit_audio_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_SETTING_AUDIO_EFFECT;
    currHistory.entryFuncPtr = mmi_settings_entry_audio_effect;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_effect
 * DESCRIPTION
 *  This function is entry function for the audio effect main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 n_items = 0;
    U16 inputBufferSize;
    U16 i;
    U16 count = 0;
    S32 inline_num = 0;
#ifdef __MMI_AUDIO_EQUALIZER__
    BOOL editable_EQ = FALSE ;
#endif

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_SETTING_AUDIO_EQUALIZER,
        0
    };

#if defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
    MMI_ID_TYPE audio_equalizer_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_1,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_2,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_3,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_4,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_5,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_6,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_7,
        STR_ID_SETTING_AUDIO_EQUALIZER_SET_8
    };
#endif /* defined(__MMI_AUDIO_EQUALIZER__) && !defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    MMI_ID_TYPE audio_reverb_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
    };
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    MMI_ID_TYPE audio_surround_list_strings[] = 
    {
        STR_ID_SETTING_AUDIO_SURROUND_MODE1,
        STR_ID_SETTING_AUDIO_SURROUND_MODE2,
    };
#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SETTING_AUDIO_EFFECT, mmi_settings_exit_audio_effect, NULL, NULL);

    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_settings_audio_effect_screen_highlight_hdlr);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_AUDIO_EFFECT);
    if(!guiBuffer)
    {
        g_settings_current_audio_effect = g_settings_selected_audio_effect;
    #ifdef __MMI_AUDIO_EQUALIZER__
        current_audio_equalizer_index = g_settings_audio_equalizer.index;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        current_audio_reverb_index = g_mmi_aud_3d_cntx.reverb_index;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        current_audio_surround_index = g_mmi_aud_3d_cntx.surround_index;
    #endif
    }
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SETTING_AUDIO_EFFECT, &inputBufferSize);


    switch(g_settings_current_audio_effect)
    {
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SETTINGS_SOUND_EFFECTS_EQ :
            for (i = 0; i < g_settings_audio_equalizer.count; i++)
            {
        #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
                g_settings_audio_effects_inline2[i] = (UI_string_type) g_settings_audio_equalizer.setting_name[i];
        #else 
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_equalizer_list_strings[i]);
        #endif
            }
            inline_num = g_settings_audio_equalizer.count;
            g_settings_current_effect_index = current_audio_equalizer_index ;
            editable_EQ = TRUE ;            
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SETTINGS_SOUND_EFFECTS_REVERB :            
            for (i = 0; i <= MAX_AUDIO_REVERB_EFFECT_NUM; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_reverb_list_strings[i]);
            }
            inline_num = MAX_AUDIO_REVERB_EFFECT_NUM ;
            g_settings_current_effect_index = current_audio_reverb_index ;
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SETTINGS_SOUND_EFFECTS_SURROUND :            
            for(i = 0 ; i < AUD_SURROUND_TOTAL ; i++)
            {
                g_settings_audio_effects_inline2[i] = (UI_string_type) GetString(audio_surround_list_strings[i]);
            }
            inline_num = AUD_SURROUND_TOTAL ;
            g_settings_current_effect_index = current_audio_surround_index ;
            break;
    #endif
        default :
            break;
    }


    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_GLOBAL_OFF));
#ifdef __MMI_AUDIO_EQUALIZER__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_EQUALIZER));
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_settings_audio_effects_inline1[count++] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_REVERB_EFFECT));
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    g_settings_audio_effects_inline1[count] = (UI_string_type) GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_EFFECT));        
#endif
    
    SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_settings_current_audio_effect_prev = g_settings_current_audio_effect;
    SetInlineItemSelect(
        &wgui_inline_items[n_items],
        NO_OF_SETTINGS_SOUND_EFFECTS,
        (U8 **) g_settings_audio_effects_inline1,
        &g_settings_current_audio_effect);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_settnigs_audio_effect_inlineitem_highlight_hdlr_1);
    n_items++;

    if(g_settings_current_audio_effect != SETTINGS_SOUND_EFFECTS_NONE)
    {
        SetInlineItemActivation(&wgui_inline_items[n_items], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[n_items],
            inline_num,
            (U8 **) g_settings_audio_effects_inline2,
            &g_settings_current_effect_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_settings_audio_effect_inlineitem_highlight_hdlr_2);
        n_items++;
    }
    else
    {
        SetInlineItemCaption(&wgui_inline_items[n_items++], (PU8)GetString((U16)(STR_GLOBAL_EMPTY)));
    }

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_SETTING_AUDIO_EFFECT,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        n_items,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    if(editable_EQ)
    {
        SetCategory57LeftSoftkeyFunction(mmi_settings_entry_audio_equalizer_setting_options);        
    }
    else
#endif
    {
        SetCategory57LeftSoftkeyFunction(mmi_settings_audio_effect_settings_done);
    }

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(mmi_settings_audio_effect_settings_back, mmi_settings_audio_effect_settings_back);
}
#endif /*#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */

#ifdef __MMI_AUDIO_EQUALIZER__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_read_from_nvram
 * DESCRIPTION
 *  This function is for reading the NVRAM data for audio equalizer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_eq_read_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_AUDIO_EQUALIZER_LID, 1, (void*)&g_settings_audio_equalizer, NVRAM_EF_AUDIO_EQUALIZER_SIZE, &error);
    if(g_settings_audio_equalizer.index >= MAX_EQUALIZER_NUM)
    {
        g_settings_audio_equalizer.index = 0;
    }

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    mmi_settings_audio_equalizer_adjust_values_for_editor(&g_settings_audio_equalizer);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_write_to_nvram
 * DESCRIPTION
 *  This function is for writing to NVRAM the audio equalizer values.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_eq_write_to_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_AUDIO_EQUALIZER_LID, 1, (void*)&g_settings_audio_equalizer, NVRAM_EF_AUDIO_EQUALIZER_SIZE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_init
 * DESCRIPTION
 *  This function is to init audio eq
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_eq_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    mmi_aud_eq_init_image_specific_vals();
#endif
    mmi_settings_audio_eq_read_from_nvram();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_eq_apply
 * DESCRIPTION
 *  This function is for selecting a particular setting.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_settings_audio_eq_apply(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL result = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_settings_audio_equalizer.index = index;
    mdi_audio_eq_set_magnitude((S8*)g_settings_audio_equalizer.magnitude[index]);
    result = mdi_audio_eq_turn_on();
    mmi_settings_audio_eq_write_to_nvram();

    PRINT_INFORMATION("aud effect: mmi_settings_audio_eq_apply(), result = %d",result);

    return result;
}

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_adjust_values_for_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_equalizer_p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_adjust_values_for_editor(audio_equalizer_struct *audio_equalizer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index, index1;
    signed char temp[100];
    S16 number_of_steps_in_bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_audio_equalizer_scrollable_ht / g_audio_equalizer_unit_scroll <= 100);
    MMI_ASSERT(audio_equalizer_p->count <= MAX_EQUALIZER_NUM);
    MMI_ASSERT(audio_equalizer_p->index >= 0 && audio_equalizer_p->index < MAX_EQUALIZER_NUM);

    /*modifcation of values to make the equalizer user friendly and more meaningful.
    calculation of intervals for each bar:*/
    number_of_steps_in_bar = g_audio_equalizer_scrollable_ht / g_audio_equalizer_unit_scroll;
    for (index = 0; index < number_of_steps_in_bar; index++)
    {
        temp[index] = LOWER_LIMIT_SOUND_LEVEL / 10 + (index * (256 / number_of_steps_in_bar));
    }

    /* applying binary search algorithm for manipulation of values: */
    for (index = 0; index < audio_equalizer_p->count; index++)
    {
        for (index1 = 0; index1 < NUM_OF_BARS_IN_A_SETTING; index1++)
        {
            signed char num_to_be_modified = audio_equalizer_p->magnitude[index][index1];

            /* find the number closest to it in the temp array: */
            int mid, left, right;
            BOOL found = FALSE;

            left = 0;
            right = number_of_steps_in_bar - 1;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (num_to_be_modified == temp[mid])
                {
                    found = TRUE;
                    break;
                }
                else if (num_to_be_modified < temp[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            if (!found)
            {
                if (left == right)  /* in this case the num_to_be_modified lies between left and left - 1 */
                {
                    if (num_to_be_modified < temp[left])
                    {
                        /* her left will always be more than zero ....assuming that the value from NVRAM is with in range */
                        if (num_to_be_modified - temp[left - 1] > temp[left] - num_to_be_modified)
                        {
                            audio_equalizer_p->magnitude[index][index1] = temp[left];
                        }
                        else
                        {
                            audio_equalizer_p->magnitude[index][index1] = temp[left - 1];
                        }
                    }
                    else
                    {
                        if (left == number_of_steps_in_bar - 1)
                        {
                            if (num_to_be_modified - temp[left] > 127 - num_to_be_modified)
                            {
                                audio_equalizer_p->magnitude[index][index1] = 127;
                            }
                            else
                            {
                                audio_equalizer_p->magnitude[index][index1] = temp[left];
                            }
                        }
                        else
                        {
                            if (num_to_be_modified - temp[left] > temp[left + 1] - num_to_be_modified)
                            {
                                audio_equalizer_p->magnitude[index][index1] = temp[left + 1];
                            }
                            else
                            {
                                audio_equalizer_p->magnitude[index][index1] = temp[left];
                            }
                        }
                    }
                }
                else if (right < left)  /* in this case the num_to_be_modified lies between right and left */
                {
                    if (num_to_be_modified - temp[right] > temp[left] - num_to_be_modified)
                    {
                        audio_equalizer_p->magnitude[index][index1] = temp[left];
                    }
                    else
                    {
                        audio_equalizer_p->magnitude[index][index1] = temp[right];
                    }
                }

            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_restore_factory_default
 * DESCRIPTION
 *  This function is for restoring the settings to default values.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_restore_factory_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 index ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    index = g_settings_audio_equalizer.index;
    
    memcpy(
        (void*)&g_settings_audio_equalizer,
        (void*)&NVRAM_EF_AUDIO_EQUALIZER_DEFAULT,
        NVRAM_EF_AUDIO_EQUALIZER_SIZE);

    g_settings_audio_equalizer.index = index ;

    mmi_settings_audio_equalizer_adjust_values_for_editor(&g_settings_audio_equalizer);

    if (g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ )
    {
        mdi_audio_eq_set_magnitude((S8*)g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]);
    }

    mmi_settings_audio_eq_write_to_nvram();
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_options
 * DESCRIPTION
 *  This function is for entering the audio equalizer settings options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */

    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2, IMG_GLOBAL_L3, IMG_GLOBAL_L3};
    U8 *item_popups[] = {NULL, NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS,
        NULL,
        mmi_settings_entry_audio_equalizer_setting_options,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS);

    /*  Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_SETTING_AUDIO_EQUALIZER_SET_OPT);

    /*  Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_SETTING_AUDIO_EQUALIZER_SET_OPT, nStrItemList);

    /*  Set current parent id */
    SetParentHandler(MENU_SETTING_AUDIO_EQUALIZER_SET_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        item_icons,
        item_popups,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_opt_select_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the select menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_opt_select_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_settings_audio_effect_settings_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_opt_edit_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the edit menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_opt_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_settings_entry_audio_equalizer_setting_edit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_entry_audio_equalizer_setting_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_opt_rename_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the rename option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_opt_rename_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_settings_entry_audio_equalizer_setting_rename, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_entry_audio_equalizer_setting_rename, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_opt_reset_highlight_hdlr
 * DESCRIPTION
 *  This function is highlight handler for the reset to default option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_opt_reset_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_restore_factory_default, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_restore_factory_default, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_edit
 * DESCRIPTION
 *  This function is for entering the editing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT,
        NULL,
        mmi_settings_entry_audio_equalizer_setting_edit,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT);
    if (!guiBuffer)
    {
        g_audio_equalizer_current_setting_info.active_bar = 0;  /* initially the first bar is to be activated. */
        ShowCategory334Screen(
            STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION,
            GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_settings_audio_equalizer.magnitude[current_audio_equalizer_index],
            guiBuffer);
    }
    else
    {
        if (g_audio_equalizer_setting_modified)
        {
            U8 index;
            signed char changed_magnitude[NUM_OF_BARS_IN_A_SETTING];

            for (index = 0; index < NUM_OF_BARS_IN_A_SETTING; index++)
            {
                changed_magnitude[index] = g_audio_equalizer_current_setting_info.sound_level[index] / 10;
            }
            ShowCategory334Screen(
                STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION,
                GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
                STR_GLOBAL_SAVE,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                changed_magnitude,
                guiBuffer);
            SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
        }
        else
        {
            ShowCategory334Screen(
                STR_ID_SETTING_AUDIO_EQUALIZER_CAPTION,
                GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_settings_audio_equalizer.magnitude[current_audio_equalizer_index],
                guiBuffer);
        }
    }
    SetKeyHandler(mmi_settings_audio_equalizer_activate_previous_bar, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_activate_next_bar, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_increment_sound_level, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_decrement_sound_level, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_settings_audio_equalizer_setting_edit_RSK_hdlr, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT, (HistoryDelCBPtr) mmi_settings_audio_equalizer_delete_history_hdlr);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_settings_audio_equalizer_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audio_equalizer_setting_modified = FALSE;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_setting_edit_RSK_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_setting_edit_RSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset the modification flag */
    g_audio_equalizer_setting_modified = FALSE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_activate_previous_bar
 * DESCRIPTION
 *  This function is for activating the previous bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_activate_previous_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_audio_equalizer_activate_bar((U8) ((NUM_OF_BARS_IN_A_SETTING +
                                             (g_audio_equalizer_current_setting_info.active_bar -
                                              1)) % NUM_OF_BARS_IN_A_SETTING));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_activate_next_bar
 * DESCRIPTION
 *  This function is for activating the next bar in the editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_activate_next_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_audio_equalizer_activate_bar((U8) ((g_audio_equalizer_current_setting_info.active_bar
                                             + 1) % NUM_OF_BARS_IN_A_SETTING));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_increment_sound_level
 * DESCRIPTION
 *  This function is to increase the sound level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_increment_sound_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sound_level = g_audio_equalizer_current_setting_info.sound_level[
        g_audio_equalizer_current_setting_info.active_bar];
    S16 delta = (S16) (g_audio_equalizer_unit_scroll * one_pixel_represents);
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [g_audio_equalizer_current_setting_info.active_bar];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_level += delta;

    if (sound_level > UPPER_LIMIT_SOUND_LEVEL)
    {
        sound_level = UPPER_LIMIT_SOUND_LEVEL;
    }

    g_audio_equalizer_current_setting_info.sound_level[
         g_audio_equalizer_current_setting_info.active_bar] = sound_level;

    if (!g_audio_equalizer_setting_modified && sound_level/10 != magnitude)
    {
        g_audio_equalizer_setting_modified = TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }
    wgui_audio_equalizer_change_sound_level();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_decrement_sound_level
 * DESCRIPTION
 *  This function is for decreasing the sound level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_decrement_sound_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sound_level = g_audio_equalizer_current_setting_info.sound_level[
        g_audio_equalizer_current_setting_info.active_bar];
    S16 delta = (S16) (g_audio_equalizer_unit_scroll * one_pixel_represents);
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [g_audio_equalizer_current_setting_info.active_bar];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_level -= delta;

    if ( sound_level < LOWER_LIMIT_SOUND_LEVEL)
    {
        sound_level = LOWER_LIMIT_SOUND_LEVEL;
    }

    g_audio_equalizer_current_setting_info.sound_level[
        g_audio_equalizer_current_setting_info.active_bar] = sound_level;

    if (!g_audio_equalizer_setting_modified && sound_level/10 != magnitude)
    {
        g_audio_equalizer_setting_modified = TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }
    wgui_audio_equalizer_change_sound_level();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_change_sound_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  change      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_change_sound_level(S16 change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sound_level = g_audio_equalizer_current_setting_info.sound_level[
        g_audio_equalizer_current_setting_info.active_bar];
    S16 magnitude = (S16) g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]
        [g_audio_equalizer_current_setting_info.active_bar];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_level += change;

    /* since the scrollable height for the +ve side and -ve side is same and the absolute val of the max and min
       limits (1270 and -1280)is different so we need to modify the +ve value when it to becomes 1280. */
    if (sound_level > UPPER_LIMIT_SOUND_LEVEL)
    {
        sound_level = UPPER_LIMIT_SOUND_LEVEL;
    }
    else if(sound_level < LOWER_LIMIT_SOUND_LEVEL)
    {
        sound_level = LOWER_LIMIT_SOUND_LEVEL;
    }

    g_audio_equalizer_current_setting_info.sound_level[
        g_audio_equalizer_current_setting_info.active_bar] = sound_level;

    if (!g_audio_equalizer_setting_modified && sound_level/10 != magnitude)
    {
        g_audio_equalizer_setting_modified = TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_SAVE, 0);
        SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_save_values, KEY_EVENT_UP);
    }
    wgui_audio_equalizer_change_sound_level();
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_save_values
 * DESCRIPTION
 *  This function is for saving the values of the edited setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_save_values(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. copy the values to the global audio equalizer setting structure */
    for (index = 0; index < NUM_OF_BARS_IN_A_SETTING; index++)
    {
        g_settings_audio_equalizer.magnitude[current_audio_equalizer_index][index] =
            g_audio_equalizer_current_setting_info.sound_level[index] / 10;
    }
    /* reset the modification flag */
    g_audio_equalizer_setting_modified = FALSE;
    if (g_settings_audio_equalizer.index == current_audio_equalizer_index && g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_EQ )
    {
        mdi_audio_eq_set_magnitude((S8*)g_settings_audio_equalizer.magnitude[current_audio_equalizer_index]);
    }
    mmi_settings_audio_eq_write_to_nvram();
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_ID_SETTING_AUDIO_EQUALIZER_OPTIONS_EDIT);
}

/* renaming related functions */


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT,
        NULL,
        mmi_settings_entry_audio_equalizer_setting_rename,
        NULL);

    if ((gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT)) == NULL)
    {
        mmi_ucs2cpy(
            (S8*) name_text_editor_buffer,
            (S8*) g_settings_audio_equalizer.setting_name[current_audio_equalizer_index]);
    }

    ShowCategory5Screen(
        STR_ID_SETTING_AUDIO_EQUALIZER_SETTIN_NAME_EDIT_TITLE,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) name_text_editor_buffer,
        SETTING_NAME_MAX_LEN,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_settings_entry_audio_equalizer_setting_name_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_entry_audio_equalizer_setting_name_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_entry_audio_equalizer_setting_name_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION,
        NULL,
        mmi_settings_entry_audio_equalizer_setting_name_edit_option,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION);

    RegisterHighlightHandler(mmi_settings_audio_equalizer_setting_name_edit_option_highlight_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        NULL,
        0,
        0,
        guiBuffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_settings_audio_equalizer_setting_name_edit_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK handlers */
    SetLeftSoftkeyFunction(mmi_settings_audio_equalizer_setting_name_edit_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_setting_name_edit_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_setting_name_edit_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_name_edit_option_highlighted_item_text = item_texts[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_equalizer_setting_name_edit_back_from_input_method
 * DESCRIPTION
 *  Go back History
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_setting_name_edit_back_from_input_method(void)
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
 *  mmi_settings_audio_equalizer_setting_name_edit_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_equalizer_setting_name_edit_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (setting_name_edit_option_highlighted_item_text)
    {
        case STR_GLOBAL_DONE:

            if (mmi_ucs2strlen((S8*) name_text_editor_buffer) != 0)
            {
                mmi_ucs2cpy(
                    (S8*) g_settings_audio_equalizer.setting_name[current_audio_equalizer_index],
                    (S8*) name_text_editor_buffer);
                mmi_settings_audio_eq_write_to_nvram();
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                DeleteScreenIfPresent(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION);
                DeleteScreenIfPresent(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_SETTING_AUDIO_EQUALIZER_SETTING_INVALID_NAME),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION);
            }
            break;
        case STR_GLOBAL_INPUT_METHOD:
            EntryInputMethodScreen();
            RegisterInputMethodScreenCloseFunction(mmi_settings_audio_equalizer_setting_name_edit_back_from_input_method);
            //DeleteScreenIfPresent(SCR_ID_AUDIO_EQUALIZER_SETTING_NAME_EDIT_OPTION);
            break;
    }
}
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 
#endif /* __MMI_AUDIO_EQUALIZER */

#ifdef __MMI_AUDIO_REVERB_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_init
 * DESCRIPTION
 *  This function is to init reverb effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_reverb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Read value from NVRAM and set reverb effect if turned on */
    mmi_settings_audio_reverb_read_nvram();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_apply
 * DESCRIPTION
 *  This function is to apply reverb effect
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_settings_audio_reverb_apply(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_aud_3d_cntx.reverb_index = index;

    mdi_audio_reverb_set_coeff((S16*) audio_Reverb_effect_table[index]);
    result = mdi_audio_reverb_turn_on();

    if (result != MDI_AUDIO_SUCCESS)
    {
        g_mmi_aud_3d_cntx.reverb_index = 0;
        HideStatusIcon(STATUS_ICON_REVERB_SOUND);
    }
    else
    {
        ShowStatusIcon(STATUS_ICON_REVERB_SOUND);
    }

    UpdateStatusIcons();

    /* Write result back to NVRAM */
    mmi_settings_audio_reverb_write_nvram();

    PRINT_INFORMATION("aud effect: mmi_settings_audio_reverb_apply(), result = %d",result);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_effect_init
 * DESCRIPTION
 *  This function is to set reverb effect at the initialize time
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_reverb_effect_init(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set and turn on audio reverb effect */
    if (index <= MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        mdi_audio_reverb_set_coeff((S16*) audio_Reverb_effect_table[index]);
        result = mdi_audio_reverb_turn_on();

        if (result == MDI_AUDIO_SUCCESS)
        {
            ShowStatusIcon(STATUS_ICON_REVERB_SOUND);
            UpdateStatusIcons();            
            return;
        }
    }

    HideStatusIcon(STATUS_ICON_REVERB_SOUND);
    UpdateStatusIcons();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_read_nvram
 * DESCRIPTION
 *  This function is to read reverb setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_reverb_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &read_value, DS_BYTE, &error);

    if (read_value < MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        g_mmi_aud_3d_cntx.reverb_index = read_value;
        return;
    }

    g_mmi_aud_3d_cntx.reverb_index = 0;
    write_value = g_mmi_aud_3d_cntx.reverb_index ;
    WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_write_nvram
 * DESCRIPTION
 *  This function is to write reverb settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_reverb_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_aud_3d_cntx.reverb_index <= MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        write_value = (U8) g_mmi_aud_3d_cntx.reverb_index;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &write_value, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_get_status
 * DESCRIPTION
 *  This function is to get reverb effect on/off setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: on
 *  MMI_FALSE: off
 *****************************************************************************/
MMI_BOOL mmi_settings_audio_reverb_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_settings_selected_audio_effect == SETTINGS_SOUND_EFFECTS_REVERB)
	{
		return MMI_TRUE;
	}

	return MMI_FALSE;
}

#endif /*__MMI_AUDIO_REVERB_EFFECT__*/


#ifdef __MMI_AUDIO_SURROUND_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_init
 * DESCRIPTION
 *  This function is to init audio surround effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Read value from NVRAM and set surround effect if turned on */
    mmi_settings_audio_surround_read_nvram();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_effect_init
 * DESCRIPTION
 *  This function is to set surround effect at the initialize time
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_effect_init(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   if (index < AUD_SURROUND_TOTAL)
   {
        mdi_audio_surround_turn_on((U8)(index));
        ShowStatusIcon(STATUS_ICON_AUD_SURROUND);
        UpdateStatusIcons();
        g_mmi_aud_3d_cntx.surround_index = index;

        return;
    }
    HideStatusIcon(STATUS_ICON_AUD_SURROUND);
    UpdateStatusIcons();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_bind_earphone_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_bind_earphone_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_settings_audio_surround_apply(current_audio_surround_index);

    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_SETTING_AUDIO_EFFECT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_apply_check
 * DESCRIPTION
 *  This function is to confirm surround effect before apply
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_apply_check(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    DisplayConfirm(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        get_string(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE),
        0,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_settings_audio_surround_bind_earphone_confirm, KEY_EVENT_UP);
#else
    mmi_settings_audio_surround_bind_earphone_confirm();

#endif /* __MMI_AUDIO_SURROUND_BIND_EARPHONE__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_apply(U16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 write_value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mode < AUD_SURROUND_TOTAL)
    {
        mdi_audio_surround_turn_on((U8) (mode));
        ShowStatusIcon(STATUS_ICON_AUD_SURROUND);
    }

    write_value = mode;
    g_mmi_aud_3d_cntx.surround_index = mode;
    UpdateStatusIcons();
    
    mmi_settings_audio_surround_write_nvram();

    PRINT_INFORMATION("aud effect: mmi_settings_audio_surround_apply()");

    return ;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_reverb_read_nvram
 * DESCRIPTION
 *  This function is to read surround setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;
    U8 write_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &read_value, DS_BYTE, &error);

    if (read_value < AUD_SURROUND_TOTAL)
    {
        g_mmi_aud_3d_cntx.reverb_index = read_value;
        return;
    }

    g_mmi_aud_3d_cntx.reverb_index = 0;
    write_value = g_mmi_aud_3d_cntx.reverb_index;
    WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_settings_audio_surround_write_nvram
 * DESCRIPTION
 *  This function is to write surround settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_audio_surround_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_aud_3d_cntx.surround_index <= AUD_SURROUND_TOTAL)
    {
        write_value = (U8) g_mmi_aud_3d_cntx.surround_index;
    }
    else
    {
        MMI_ASSERT(FALSE);
    }

    WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
}


#endif /* __MMI_AUDIO_SURROUND_EFFECT__ */


#endif /* __MMI_SOUND_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_read_audio_mic_volume_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mic_volume_p      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_read_audio_mic_volume_from_nvram(audio_mic_volume_struct *audio_mic_volume_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 mic_volume_set;
    U8 set_index;
    unsigned char *ptr = (unsigned char*)&mic_volume_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_AUDIO_MIC_VOLUME_SET, &mic_volume_set, DS_SHORT, &error);

    for (set_index = 0; set_index < AUDIO_MIC_SET_NUM; set_index++)
    {
        /* check if the value from NVRAM an invalid data */
        if (*ptr == 0xFF)
        {
            ptr = (unsigned char*)&mic_volume_set;
            /* reset in call mic volume level to 3 */
            audio_mic_volume_p->levels[AUDIO_MIC_IN_CALL] = *ptr++ = 3;
            /* reset app mic volume level to 4 */
            audio_mic_volume_p->levels[AUDIO_MIC_APP] = *ptr++ = 4;
            WriteValue(NVRAM_AUDIO_MIC_VOLUME_SET, &mic_volume_set, DS_SHORT, &error);
            break;
        }
        else
        {
            audio_mic_volume_p->levels[set_index] = *ptr++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_settings_write_audio_mic_volume_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mic_volume_p      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_write_audio_mic_volume_to_nvram(audio_mic_volume_struct *audio_mic_volume_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 mic_volume_set;
    U8 set_index;
    unsigned char *ptr = (unsigned char*)&mic_volume_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (set_index = 0; set_index < AUDIO_MIC_SET_NUM; set_index++)
    {
        *ptr++ = audio_mic_volume_p->levels[set_index];
    }
    WriteValue(NVRAM_AUDIO_MIC_VOLUME_SET, &mic_volume_set, DS_SHORT, &error);
}

