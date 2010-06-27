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
* Audio3DEffect.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is to setup audio 3D sound effect
*
* Author:
* -------
* Wilson Lien (mtk00676)
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
 * Modify Reverb Naming and remove some of AGC and upsampling variables from custome folder
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
#ifndef _AUDIO_3D_EFFECT_C
#define _AUDIO_3D_EFFECT_C


#if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__)

#include "CommonScreens.h"

#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "settingStructs.h"
#include "settingGprots.h"
#include "SettingProt.h"
#include "SettingProfile.h"
#include "gpioInc.h"


#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "Audio3DEffect.h"
#include "wgui_status_icons.h"

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */
audio_3d_effect_struct g_mmi_aud_3d_cntx;

/* 
 * Local Function
 */

/* 
 * Global Variable
 */


/* 
 * Global Function
 */


#ifdef __MMI_AUDIO_REVERB_EFFECT__

/* 
 * Local Variable
 */
static U16 selected_audio_reverb_effect_index = 0;

/* 
 * Global Variable
 */
extern const S16 *audio_Reverb_effect_table[];

/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_effect_init
 * DESCRIPTION
 *  This function is to init 3D effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_SETTING_AUDIO_REVERB_EFFECT, mmi_aud_reverb_effect_highlight_hdlr);
    SetHintHandler(MENU_SETTING_AUDIO_REVERB_EFFECT, mmi_aud_reverb_effect_hint_hdlr);

    /* Read value from NVRAM and set 3D effect if turned on */
    mmi_aud_reverb_read_nvram();
    mmi_aud_reverb_init_effect(g_mmi_aud_3d_cntx.reverb_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of 3d effect item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_effect_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_entry_aud_reverb_effect_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_entry_aud_reverb_effect_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_effect_hint_hdlr
 * DESCRIPTION
 *  This function is the hint handler of 3d effect item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_effect_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_mmi_aud_3d_cntx.reverb_index > 0)
    {
        mmi_ucs2cpy(
            (S8*) hintData[(index)],
            GetString((U16) (STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1 + g_mmi_aud_3d_cntx.reverb_index - 1)));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[(index)], GetString(STR_GLOBAL_NONE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_effect_list_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of 3d effect list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_effect_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selected_audio_reverb_effect_index = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_effect_list_LSK_hdlr
 * DESCRIPTION
 *  This function is the LSK handler of 3d effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_effect_list_LSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    if((selected_audio_reverb_effect_index > 0) &&
       (g_mmi_aud_3d_cntx.surround_index != AUD_SURROUND_OFF))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_SETTING_AUDIO_EFFECT_NO_COEXIST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            WARNING_TONE);
            
        return;
    }
#endif

    if (mmi_aud_reverb_set_effect(selected_audio_reverb_effect_index))
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

    DeleteScreenIfPresent(SCR_ID_SETTING_AUDIO_REVERB_EFFECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_aud_reverb_effect_list
 * DESCRIPTION
 *  This function is the entry function of 3D effect list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_aud_reverb_effect_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 audio_reverb_list_strings[] = 
    {
        STR_GLOBAL_NONE,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET1,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET2,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET3,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET4,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET5,
        STR_ID_SETTING_AUDIO_REVERB_EFFECT_SET6
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SETTING_AUDIO_REVERB_EFFECT, NULL, mmi_entry_aud_reverb_effect_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_AUDIO_REVERB_EFFECT);
    SetParentHandler(MENU_SETTING_AUDIO_REVERB_EFFECT);

    RegisterHighlightHandler(mmi_aud_reverb_effect_list_highlight_hdlr);

    ShowCategory11Screen(
        STR_ID_SETTING_AUDIO_REVERB_EFFECT,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) (MAX_AUDIO_REVERB_EFFECT_NUM + 1),
        audio_reverb_list_strings,
        (U16) g_mmi_aud_3d_cntx.reverb_index,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_aud_reverb_effect_list_LSK_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_set_effect
 * DESCRIPTION
 *  This function is to set 3d effect by list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_aud_reverb_set_effect(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    BOOL set_result = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_aud_3d_cntx.reverb_index != index)
    {
        g_mmi_aud_3d_cntx.reverb_index = index;

        /*
         * Turn off 3D audio effect
         */
        if (index == 0)
        {
            mdi_audio_reverb_turn_off();
            HideStatusIcon(STATUS_ICON_REVERB_SOUND);
        }
        /*
         * Set and turn on audio 3D effect
         */
        else
        {
            mdi_audio_reverb_set_coeff((S16*) audio_Reverb_effect_table[index - 1]);
            result = mdi_audio_reverb_turn_on();

            if (result != MDI_AUDIO_SUCCESS)
            {
                g_mmi_aud_3d_cntx.reverb_index = 0;
                set_result = FALSE;
                HideStatusIcon(STATUS_ICON_REVERB_SOUND);
            }
            else
            {
                ShowStatusIcon(STATUS_ICON_REVERB_SOUND);
            }
        }

        UpdateStatusIcons();

        /* Write result back to NVRAM */
        mmi_aud_reverb_write_nvram();
    }

    return set_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_init_effect
 * DESCRIPTION
 *  This function is to set 3d effect at the initialize time
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_init_effect(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set and turn on audio 3D effect */
    if ((index > 0) && (index <= MAX_AUDIO_REVERB_EFFECT_NUM))
    {
        mdi_audio_reverb_set_coeff((S16*) audio_Reverb_effect_table[index - 1]);
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
 *  mmi_aud_reverb_read_nvram
 * DESCRIPTION
 *  This function is to read setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BYTE_AUDIO_REVERB_INDEX, &read_value, DS_BYTE, &error);

    if (read_value <= MAX_AUDIO_REVERB_EFFECT_NUM)
    {
        g_mmi_aud_3d_cntx.reverb_index = read_value;
        return;
    }

    g_mmi_aud_3d_cntx.reverb_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_reverb_write_nvram
 * DESCRIPTION
 *  This function is to write settings back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_reverb_write_nvram(void)
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
 *  mmi_aud_reverb_get_status
 * DESCRIPTION
 *  This function is to get 3D effect on/off setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: on
 *  MMI_FALSE: off
 *****************************************************************************/
MMI_BOOL mmi_aud_reverb_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((g_mmi_aud_3d_cntx.reverb_index > 0) && (g_mmi_aud_3d_cntx.reverb_index <= MAX_AUDIO_REVERB_EFFECT_NUM))
	{
		return MMI_TRUE;
	}

	return MMI_FALSE;
}
#endif /* #ifdef __MMI_AUDIO_REVERB_EFFECT__ */


#ifdef __MMI_AUDIO_SURROUND_EFFECT__
/* 
 * Local Variable
 */
static U16 selected_audio_surround_mode_index = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_init
 * DESCRIPTION
 *  This function is to init audio surround effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 read_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_SETTING_AUDIO_SURROUND_EFFECT, mmi_aud_surround_effect_highlight_hdlr);
    SetHintHandler(MENU_SETTING_AUDIO_SURROUND_EFFECT, mmi_aud_surround_effect_hint_hdlr);

    /* Read value from NVRAM and set 3D effect if turned on */
    ReadValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &read_value, DS_BYTE, &error);

    /* Default is off for the first time bootup after download */
#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(mmi_gpio_is_earphone_plug_in())
#endif    
    {
        if (read_value == AUD_SURROUND_MODE1 || read_value == AUD_SURROUND_MODE2)
        {
            mdi_audio_surround_turn_on((U8)(read_value - 1));
            ShowStatusIcon(STATUS_ICON_AUD_SURROUND);
            UpdateStatusIcons();
            g_mmi_aud_3d_cntx.surround_index = read_value;

            return;
        }
    }
    
    g_mmi_aud_3d_cntx.surround_index = AUD_SURROUND_OFF;

    if(read_value >= AUD_SURROUND_TOTAL)
    {
        read_value = AUD_SURROUND_OFF;
        WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &read_value, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of 3d effect item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_entry_aud_surround_mode_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_entry_aud_surround_mode_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_hint_hdlr
 * DESCRIPTION
 *  This function is the hint handler of 3d effect item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);

    if (g_mmi_aud_3d_cntx.surround_index == AUD_SURROUND_OFF)
    {
        mmi_ucs2cpy((S8*) hintData[(index)], GetString(STR_GLOBAL_OFF));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[(index)],
            GetString((U16)(STR_ID_SETTING_AUDIO_SURROUND_MODE1 + g_mmi_aud_3d_cntx.surround_index - 1)));
    }
}


#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_aud_surround_bind_earphone_confirm
 * DESCRIPTION
 *
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_list_earphone_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_aud_surround_effect_set_status(selected_audio_surround_mode_index);

    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_SETTING_AUDIO_SURROUND_EFFECT);
}
#endif /*#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_list_highlight_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selected_audio_surround_mode_index = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_list_LSK_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_list_LSK_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if((selected_audio_surround_mode_index != AUD_SURROUND_OFF) &&
       mmi_aud_reverb_get_status())
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_SETTING_AUDIO_EFFECT_NO_COEXIST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME_2000,
            WARNING_TONE);
        return;
    }
#endif


#ifdef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
    if(selected_audio_surround_mode_index != AUD_SURROUND_OFF)
    {
        DisplayConfirm(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            get_string(STR_ID_SETTING_AUDIO_SURROUND_PLUG_EAPHONE),
            0,
            WARNING_TONE);
        SetLeftSoftkeyFunction(mmi_aud_surround_effect_list_earphone_confirm, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_AUDIO_SURROUND_BIND_EARPHONE__ */
    {
        mmi_aud_surround_effect_set_status(selected_audio_surround_mode_index);

        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
            
        DeleteScreenIfPresent(SCR_ID_SETTING_AUDIO_SURROUND_EFFECT);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_aud_surround_mode_list
 * DESCRIPTION
 * 
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_aud_surround_mode_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 audio_surround_list_strings[] = 
    {
        STR_GLOBAL_OFF,
        STR_ID_SETTING_AUDIO_SURROUND_MODE1,
        STR_ID_SETTING_AUDIO_SURROUND_MODE2
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SETTING_AUDIO_SURROUND_EFFECT, NULL, mmi_entry_aud_surround_mode_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SETTING_AUDIO_SURROUND_EFFECT);
    SetParentHandler(MENU_SETTING_AUDIO_SURROUND_EFFECT);

    RegisterHighlightHandler(mmi_aud_surround_effect_list_highlight_hdlr);

    ShowCategory11Screen(
        STR_ID_SETTING_AUDIO_SURROUND_EFFECT,
        GetRootTitleIcon(MENU_SETTING_SOUND_EFFECT),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) AUD_SURROUND_TOTAL,
        audio_surround_list_strings,
        (U16) g_mmi_aud_3d_cntx.surround_index,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_aud_surround_effect_list_LSK_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_aud_surround_effect_set_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_aud_surround_effect_set_status(U16 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 write_value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mode != g_mmi_aud_3d_cntx.surround_index)
    {
        /* Turn Off*/
        if (mode == AUD_SURROUND_OFF)
        {
            mdi_audio_surround_turn_off();
            HideStatusIcon(STATUS_ICON_AUD_SURROUND);
        }
        /*Turn on*/
        else if(mode < AUD_SURROUND_TOTAL)
        {
            mdi_audio_surround_turn_on((U8) (mode - 1));
            ShowStatusIcon(STATUS_ICON_AUD_SURROUND);
        }
        
        write_value = mode;
        g_mmi_aud_3d_cntx.surround_index = mode;
        UpdateStatusIcons();
        WriteValue(NVRAM_BYTE_AUDIO_SURROUND_INDEX, &write_value, DS_BYTE, &error);
    }
}

#endif /* #ifdef __MMI_AUDIO_SURROUND_EFFECT__ */


#endif /* #if defined(__MMI_AUDIO_REVERB_EFFECT__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) */ 
#endif /* _AUDIO_3D_EFFECT_C */ 

