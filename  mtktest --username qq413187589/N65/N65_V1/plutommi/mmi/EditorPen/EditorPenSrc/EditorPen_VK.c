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
 * EditorPen_VK.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is EditorPen's sub module which is related to Virtual Keyboard
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
#include "MMI_features.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "EditorPenGprot.h"
#include "EditorPenProt.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* To record the type of virtual keyboard for Symbol Keyboard switch (Need to revise) */
static gui_virtual_keyboard_language_enum gPenEditorPreviousVirtualKeyboardType = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

static MMI_BOOL g_pen_editor_resized_by_vk = MMI_FALSE;

static MMI_BOOL g_pen_editor_vk_show_at_start = MMI_FALSE;

/* To strore the content of the Virtual Keyboard Text in Display Area */
static mmi_pen_editor_vk_text_struct gPenEditorVKText;

/* The state of candidate above virtual keyboard */
static MMI_BOOL gPenEditorVKCandidate = MMI_FALSE;

#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
/* flag for checking if current VK status is tray when re-entry setup function */
static MMI_BOOL gPenEditorHideToTray = MMI_FALSE;
#endif

static MMI_BOOL g_pen_editor_disable_virtual_keyboard = MMI_FALSE;

/* To Store Virtual Keyboard Lang. Type in History */
static gui_virtual_keyboard_language_enum gPenEditorHistoryVirtualKeyboardType = GUI_VIRTUAL_KEYBOARD_MAX_LANG;

static mmi_pen_editor_vk_keys_set_struct g_pen_editor_vk_keys_set;

static UI_character_type g_pen_editor_vk_characters_disable_list[PEN_EDITOR_VK_MAX_DISABLE_KEYS + 1];

static gui_virtual_keyboard_pen_enum g_pen_editor_vk_event_keys_disable_list[PEN_EDITOR_VK_MAX_DISABLE_KEYS + 1];

/* The State of Virtual Keyboard */
static mmi_pen_editor_virtual_keyboard_state_enum gPenEditorVKState = PEN_EDITOR_VK_NONE;

/* The invalid characters array */
const UI_character_type gPenEditorPhoneNumberInvalidCharacters[] = { '(', ')', '-', ' ', '\0' };

const UI_character_type gPenEditorKeyPadNumbericInvalidCharacters[] = { '(', ')', 'p', 'w', '+', '-', ' ', '\0' };

const UI_character_type gPenEditorPhoneNumberSIMInvalidCharacters[] = { '(', ')', 'p', 'w', '-', ' ', '\0' };

/*  For INPUT_TYPE_SIGNED_NUMERIC and INPUT_TYPE_SIGNED_NUMERIC_PASSWORD */
const UI_character_type gPenEditorSignedNumbericInvalidCharacters[] = { '*', '/',  '+', '%', '$', '=', '.', '\0' };

/*  For   INPUT_TYPE_SIGNED_DECIMAL_NUMERIC, INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD  */
const UI_character_type gPenEditorSignedDecimalNumbericInvalidCharacters[] = { '*', '/',  '+', '%', '$', '=', '\0' };

const UI_character_type gPenEditorUCS2InvalidCharacters[] = {0x20ac, '\0' };

const UI_character_type gPenEditorEmptyInvalidCharacters[] = { '\0' };

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableSpace[] = {GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_NONE};

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableNewLine[] = {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_NONE};

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableNewLineCapsLock[] =
    {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_NONE};
    
const gui_virtual_keyboard_pen_enum gPenEditorVKDisableNewLineCapsSymLock[] =
    {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_CAPSLOCK, GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_NONE};

    
const gui_virtual_keyboard_pen_enum gPenEditorVKDisableEmpty[] = {GUI_VKBD_PEN_NONE};

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableHideSpace[] =
    {GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SPACE, GUI_VKBD_PEN_NONE};

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableCapsLock[] = {GUI_VKBD_PEN_CAPSLOCK};

const gui_virtual_keyboard_pen_enum gPenEditorVKDisableSymLock[] = {GUI_VKBD_PEN_SYMBPICKER, GUI_VKBD_PEN_NONE};


/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/




/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_append_disable_keys
 * DESCRIPTION
 *  To append the default disabled keys in the virtual keyboard 
 * PARAMETERS
 *  vk_keys_set             [OUT]         The struct to record the disabled and enabled keys in the virtual keyboard
 *  disable_characters      [IN]          The disabled characters keys
 *  disable_event_keys      [IN]          The disabled event keys
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_append_disable_keys(
        mmi_pen_editor_vk_keys_set_struct *vk_keys_set,
        const UI_character_type *disable_characters,
        const gui_virtual_keyboard_pen_enum *disable_event_keys)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (disable_characters)
    {
        S32 i = 0;

        while (disable_characters[i])
        {
            S32 j = 0;

            while (vk_keys_set->characters_list[j])
            {
                if (disable_characters[i] == vk_keys_set->characters_list[j])
                {
                    break;
                }
                j++;
            }
            if (!vk_keys_set->characters_list[j])
            {
                vk_keys_set->characters_list[j] = disable_characters[i];
                vk_keys_set->characters_list[j + 1] = '\0';
            }
            i++;
        }
    }

    if (disable_event_keys)
    {
        S32 i = 0;

        while (disable_event_keys[i])
        {
            S32 j = 0;

            while (vk_keys_set->event_keys_list[j])
            {
                if (disable_event_keys[i] == vk_keys_set->event_keys_list[j])
                {
                    break;
                }
                j++;
            }
            if (!vk_keys_set->event_keys_list[j])
            {
                vk_keys_set->event_keys_list[j] = disable_event_keys[i];
                vk_keys_set->event_keys_list[j + 1] = '\0';
            }
            i++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_disable_keys
 * DESCRIPTION
 *  Disable the keys on the virtual keyboard according to the input type and the situation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_disable_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* W06.11 Disable Hide Key in Phone Number Keyboard */
    const UI_character_type *DisableCharacters = gPenEditorEmptyInvalidCharacters;
    const gui_virtual_keyboard_pen_enum *DisableSymbols = gPenEditorVKDisableEmpty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_pen_editor_get_input_box_type() == PEN_EDITOR_INLINE_TEXT) ||
        (mmi_pen_editor_get_input_box_type() == PEN_EDITOR_SINGLE_LINE_INPU_BOX) ||
        (MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL))
    {
        DisableSymbols = gPenEditorVKDisableNewLine;
    }
    /* W06.06 Disable Caps Lock in Quick Search */
    if ((mmi_pen_editor_get_input_box_type() == PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX))
    {
        if ((MMI_current_input_type & INPUT_TYPE_MASK) == INPUT_TYPE_MMI_SM_STROKE ||
            (MMI_current_input_type & INPUT_TYPE_MASK) == INPUT_TYPE_MMI_TR_STROKE)
        {
            DisableSymbols = gPenEditorVKDisableNewLineCapsSymLock;
        }
        else
        {
            DisableSymbols = gPenEditorVKDisableNewLineCapsLock;
        }
    }

    if (INPUT_TYPE_PHONE_NUMBER == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        if (MMI_current_input_ext_type & INPUT_TYPE_EXT_SIM_NUMERIC)
        {
            DisableCharacters = gPenEditorPhoneNumberSIMInvalidCharacters;
            DisableSymbols = gPenEditorVKDisableHideSpace;
        }
        else
        {
            DisableCharacters = gPenEditorPhoneNumberInvalidCharacters;
            DisableSymbols = gPenEditorVKDisableHideSpace;
        }
    }
    else if (INPUT_TYPE_KEYPAD_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK)
             || INPUT_TYPE_SAT_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        DisableCharacters = gPenEditorKeyPadNumbericInvalidCharacters;
        DisableSymbols = gPenEditorVKDisableHideSpace;
    }
    else if (INPUT_TYPE_SIGNED_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK)
             || INPUT_TYPE_SIGNED_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        DisableCharacters = gPenEditorSignedNumbericInvalidCharacters;
        DisableSymbols = gPenEditorVKDisableHideSpace;
    }
    else if (INPUT_TYPE_SIGNED_DECIMAL_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK)
             || INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        DisableCharacters = gPenEditorSignedDecimalNumbericInvalidCharacters;
        DisableSymbols = gPenEditorVKDisableHideSpace;
    }
    else if (INPUT_MODE_SM_STROKE == MMI_current_input_mode ||
        INPUT_MODE_TR_STROKE == MMI_current_input_mode)
    {
        DisableSymbols = gPenEditorVKDisableSymLock;
    }
#ifdef __MMI_LANG_HEBREW__
    else if (INPUT_MODE_MMI_MULTITAP_HEBREW == MMI_current_input_mode
             || INPUT_MODE_MULTITAP_HEBREW == MMI_current_input_mode)
    {
        DisableSymbols = gPenEditorVKDisableCapsLock;
    }
#endif /*__MMI_LANG_HEBREW__*/
    else if (MMI_allow_only_english_input_modes)
    {
        DisableCharacters = gPenEditorUCS2InvalidCharacters;
    }

    if (g_pen_editor_disable_virtual_keyboard)
    {
        wgui_set_virtual_keyboard_allowed_characters(gPenEditorEmptyInvalidCharacters);
    }
    else if (g_pen_editor_vk_keys_set.is_changed)
    {
        if (g_pen_editor_vk_keys_set.is_allowed)
        {
            wgui_set_virtual_keyboard_allowed_characters((const UI_character_type*)g_pen_editor_vk_keys_set.
                                                         characters_list);
            wgui_set_virtual_keyboard_disabled_list(gPenEditorEmptyInvalidCharacters, DisableSymbols);
        }
        else
        {
            mmi_pen_editor_vk_append_disable_keys(&g_pen_editor_vk_keys_set, DisableCharacters, DisableSymbols);
            wgui_set_virtual_keyboard_disabled_list(
                (const UI_character_type*)g_pen_editor_vk_keys_set.characters_list,
                (const gui_virtual_keyboard_pen_enum*)g_pen_editor_vk_keys_set.event_keys_list);
        }
    }
    else
    {
        wgui_set_virtual_keyboard_disabled_list(DisableCharacters, DisableSymbols);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_vk_keys
 * DESCRIPTION
 *  To set the keys in the virtual keyboard
 * PARAMETERS
 *  is_allowed                  [IN]        MMI_TRUE : The enabled keys list MMI_FALSE : The Disabled keys list
 *  characters_lsit             [IN]        The character keys
 *  disable_event_keys_list     [IN]        The event keys
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_vk_keys(
        MMI_BOOL is_allowed,
        const UI_character_type *characters_lsit,
        const gui_virtual_keyboard_pen_enum *disable_event_keys_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_vk_keys_set.is_allowed = is_allowed;
    g_pen_editor_vk_keys_set.is_changed = MMI_TRUE;
    if (is_allowed)
    {
        g_pen_editor_vk_keys_set.characters_list = (UI_character_type*) characters_lsit;
        g_pen_editor_vk_keys_set.event_keys_list = NULL;
    }
    else
    {
        U32 num = 0;

        if (characters_lsit)
        {
            num = 0;

            for (;; num++)
            {
                if ('\0' == characters_lsit[num])
                {
                    break;
                }
                g_pen_editor_vk_characters_disable_list[num] = characters_lsit[num];
            }
        }
        if (disable_event_keys_list)
        {
            num = 0;

            for (;; num++)
            {
                if (GUI_VKBD_PEN_NONE == disable_event_keys_list[num])
                {
                    break;
                }
                g_pen_editor_vk_event_keys_disable_list[num] = disable_event_keys_list[num];
            }
        }
        g_pen_editor_vk_keys_set.characters_list = g_pen_editor_vk_characters_disable_list;
        g_pen_editor_vk_keys_set.event_keys_list = g_pen_editor_vk_event_keys_disable_list;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_caps_lock
 * DESCRIPTION
 *  Switch input method as Caps Lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_caps_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_virtual_keyboard_language_enum vk_language;
    U8 temp_input_mode, temp_vk_type;
    MMI_BOOL temp_has_candidate;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        return;
    }
    
    temp_input_mode = mmi_pen_editor_get_caps_lock_input_mode((MMI_current_input_mode));
#ifdef __MMI_LANG_THAI__
    if (temp_input_mode == INPUT_MODE_MULTITAP_THAI 
        || temp_input_mode == INPUT_MODE_MMI_MULTITAP_THAI
        || temp_input_mode == INPUT_MODE_SMART_THAI)
    {   
        /* Thai don't have upper case input method, but its vk use caps lock to 
         * switch its string case and symbol case */
        if (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_THAI)
        {
            vk_language = GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL;
        }
        else
        {
            vk_language = GUI_VIRTUAL_KEYBOARD_THAI;
        }
    }
    else
#endif /* __MMI_LANG_THAI__ */
    if (temp_input_mode == IME_HAN_WRITING_INVALID_INPUT_MODE)
    {
            vk_language = GUI_VIRTUAL_KEYBOARD_ENGLISH;
    }
    else
    {
        mmi_pen_editor_get_vk_type_by_input_mode(temp_input_mode, &temp_vk_type, &temp_has_candidate);
        if (temp_vk_type != 0xFF)
        {
            vk_language = temp_vk_type;
            MMI_current_input_mode = temp_input_mode;
        }
        else
        {
            vk_language = GUI_VIRTUAL_KEYBOARD_ENGLISH;
        }
    }
    wgui_setup_virtual_keyboard(vk_language);
    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    mmi_pen_editor_change_inputbox_mode(MMI_current_input_mode);
    /* W05.36 Fix Center Soft Key Sync Issue */
    set_MMI_current_input_type();
    mmi_pen_editor_set_CSK_content();
    /* W06.09 Touch Screen With Keypad V1 */
    /* mmi_pen_editor_clear_key_handler(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_insertcharacter
 * DESCRIPTION
 *  Insert the character to the input box or virtual keyboard text according to the situation
 * PARAMETERS
 *  vk_para     [IN]        The data returned by pen event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_insertcharacter(gui_pen_event_param_struct vk_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type)
        || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
    {
        if (INPUT_MODE_MMI_MULTITAP_BPMF == MMI_current_input_mode
            || INPUT_MODE_MMI_MULTITAP_PINYIN == MMI_current_input_mode
            || INPUT_MODE_MMI_SM_STROKE == MMI_current_input_mode
            || INPUT_MODE_MMI_TR_STROKE == MMI_current_input_mode)
        {
            mmi_pen_editor_input_character((UI_character_type) vk_para._u.i, MMI_FALSE);
        }
        else
        {
            if (!((vk_para._u.i > 0x60 && vk_para._u.i < 0x7b) || (vk_para._u.i > 0x3104 && vk_para._u.i < 0x3130)))
            {
                /* W05.36 Temp Solution Do nothing when there is candidates list */
                if (0 == gPenEditorVKText.TextLength && !mmi_pen_editor_is_candidate_in_selection())
                {
                    mmi_pen_editor_input_character((UI_character_type) vk_para._u.i, MMI_FALSE);
                }
            }
            else if (mmi_pen_editor_vk_insert_character(&gPenEditorVKText, (UI_character_type) vk_para._u.i))
            {
                /* Check the input is valid or not */
                if (mmi_pen_editor_get_candidates_by_vk(MMI_TRUE))
                {
                    switch (mmi_pen_editor_get_input_box_type())
                    {
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                            wgui_inputbox_RSK_label_clear = 1;
                            break;

                        case PEN_EDITOR_EMS_INPUT_BOX:
                            category28_RSK_label_clear = 1;
                            break;

                        default:
                            break;
                    }
                    /* Temp Solution for LSK Text Update */
                    /* W05.35 For LSK Text Issue */
                    if (gPenEditorVKText.TextLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
                    {
                        mmi_pen_editor_store_LSK_Text();
                    }
                    mmi_pen_editor_set_left_soft_key_select();
                    set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
                    set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
                    mmi_pen_editor_set_candidate_selection_status(MMI_TRUE);
                    mmi_pen_editor_register_arrow_keys();
                    mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_CLEAR);
                }
                else
                {
                    mmi_pen_editor_vk_delete_character(&gPenEditorVKText);
                    mmi_pen_editor_get_candidates_by_vk(MMI_TRUE);
                }
                wgui_set_virtual_keyboard_display_area((U8*) gPenEditorVKText.VKText, MMI_TRUE);
            }
            else if (!(vk_para._u.i > 0x60 && vk_para._u.i < 0x7b) &&
                     (GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type))
            {
                mmi_pen_editor_input_character((UI_character_type) vk_para._u.i, MMI_FALSE);
            }
        }
    }
    else
    {
        if (0 != vk_para._u.i)
        {
            mmi_pen_editor_input_character((UI_character_type) vk_para._u.i, MMI_FALSE);
        }
        else
        {
            /* Test for Multitap */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_hide
 * DESCRIPTION
 *  Set the virtual keyboard to the tray type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_hide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        /* W06.04 For Chinese Symbols Keyboard in Quick Search */
        if (mmi_pen_editor_is_valid_vk_type_for_quick_search(MMI_virtual_keyboard.lang_type)
            || GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)
        {
            changed_height = MMI_virtual_keyboard.height;
            mmi_pen_editor_hide_virtual_keyboard_area();
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
            changed_height -= mmi_pen_editor_get_candidate_box_height();
            mmi_pen_editor_resize_content_area(changed_height);
            RedrawCategoryControlledArea200Screen(NULL);
        }
        return;
    }
    if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type)
    {
        /* W05.32 INPUT_TYPE_PHONE_NUMBER won't use tray virtual keyboard */
        if (GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER == MMI_virtual_keyboard.lang_type)
        {
            return;
        }
        gdi_layer_lock_frame_buffer();
        changed_height = MMI_virtual_keyboard.height;
        if (GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
        {
            changed_height += (mmi_pen_editor_get_candidate_box_height());
            if (gPenEditorVKCandidate)
            {
                gPenEditorVKCandidate = MMI_FALSE;
            }
            mmi_pen_editor_reset_LSK_and_RSK_state();
        }
        /* mmi_pen_editor_reset_vk_text(&gPenEditorVKText); */
        mmi_pen_editor_hide_virtual_keyboard_area();
        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
        /* changed_height -= MMI_virtual_keyboard.height; */
        changed_height -= mmi_pen_editor_get_candidate_box_height();
        mmi_pen_editor_resize_content_area(changed_height);
        /* W05.36 Adjust the List height for In-line Multiline Input Box */
        if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
            || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            S32 temp_multiline_height = MMI_multiline_inputbox.height;
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            gPenEditorHideToTray = MMI_TRUE;
        #endif
            mmi_pen_editor_vk_list_menu_resize();
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            gPenEditorHideToTray = MMI_FALSE;
        #endif
            if (PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
            {
                gui_resize_multi_line_input_box(
                    &MMI_multiline_inputbox,
                    MMI_multiline_inputbox.width,
                    temp_multiline_height);
                redraw_fixed_list();
                redraw_current_inline_item();
            }
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
        }
		
        gui_move_single_line_input_box(
			mmi_pen_editor_get_candidate_box(),
			mmi_pen_editor_get_candidate_box_x(),
            PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM);
		
		gui_move_single_line_input_box(
			mmi_pen_editor_get_composition_box(), 
			mmi_pen_editor_get_composition_box_x(), 
			mmi_pen_editor_get_candidate_box_y() - mmi_pen_editor_get_composition_box_height() - 2);

        gdi_layer_unlock_frame_buffer();
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_show
 * DESCRIPTION
 *  Enlarge the virtual keyboard according to the input mothod
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    U8 vk_type;
    MMI_BOOL has_candidate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        changed_height = MMI_virtual_keyboard.height;
        if (changed_height < mmi_pen_editor_get_candidate_box_height())
        {
            changed_height = mmi_pen_editor_get_candidate_box_height();
        }
        mmi_pen_editor_set_virtual_keyboard_by_input_mode(MMI_current_input_mode);
        changed_height -= MMI_virtual_keyboard.height;
        mmi_pen_editor_resize_content_area(changed_height);
        RedrawCategoryControlledArea200Screen(NULL);
        return;
    }
    if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
    {
        /* changed_height = MMI_virtual_keyboard.height; */
        changed_height = mmi_pen_editor_get_candidate_box_height();
        
        mmi_pen_editor_get_vk_type_by_input_mode(MMI_current_input_mode, &vk_type, &has_candidate);

        if (vk_type != 0xFF)
        {
            if (!gPenEditorVKCandidate && has_candidate)
            {
                changed_height -= (mmi_pen_editor_get_candidate_box_height());
                gPenEditorVKCandidate = MMI_TRUE;
            }
            else if (gPenEditorVKCandidate && !has_candidate)
            {
                changed_height += mmi_pen_editor_get_candidate_box_height();
            }
            wgui_setup_virtual_keyboard(vk_type);
        }
        else
        {
            MMI_ASSERT(0);
            return;
        }
        
        changed_height -= MMI_virtual_keyboard.height;
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_resize_content_area(changed_height);
        /* W05.36 Adjust the List height for In-line Multiline Input Box */
        if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
            || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            S32 temp_multiline_height = MMI_multiline_inputbox.height;
            MMI_BOOL temp_VKCandidate = gPenEditorVKCandidate;
            gui_virtual_keyboard_language_enum keyboard_type = MMI_virtual_keyboard.lang_type;

            mmi_pen_editor_vk_list_menu_resize();
            if (PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
            {
                gui_resize_multi_line_input_box(
                    &MMI_multiline_inputbox,
                    MMI_multiline_inputbox.width,
                    temp_multiline_height);
                redraw_fixed_list();
                redraw_current_inline_item();
                gPenEditorVKCandidate = temp_VKCandidate;
            }
            wgui_setup_virtual_keyboard(keyboard_type);
        }
        gui_move_single_line_input_box(
            mmi_pen_editor_get_candidate_box(),
            mmi_pen_editor_get_candidate_box_x(),
            MMI_virtual_keyboard.y - mmi_pen_editor_get_candidate_box_height() - 2);
        if (gPenEditorVKCandidate)
        {
            mmi_pen_editor_hide_candidate_area();
        }
        gdi_layer_unlock_frame_buffer();
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_symbol_picker
 * DESCRIPTION
 *  Set the virtual keyboard to the symbol type
 * PARAMETERS
 *  is_european_symbol    [IN]   Whether it is european symbol keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_symbol_picker(MMI_BOOL is_european_symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    MMI_BOOL is_back_to_multi_block = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        changed_height = MMI_virtual_keyboard.height;
        if (changed_height < mmi_pen_editor_get_candidate_box_height())
        {
            changed_height = mmi_pen_editor_get_candidate_box_height();
        }
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_hide_virtual_keyboard_area();
        if (GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type
        #ifdef __MMI_LANG_PERSIAN__        
            || GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL == MMI_virtual_keyboard.lang_type
        #endif /*__MMI_LANG_PERSIAN__*/
        #ifdef __MMI_LANG_ARABIC__        
            || GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS == MMI_virtual_keyboard.lang_type
        #endif /*__MMI_LANG_ARABIC__*/
        #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            || GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS == MMI_virtual_keyboard.lang_type
        #endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/ 
            )
        {
            wgui_setup_virtual_keyboard(gPenEditorPreviousVirtualKeyboardType);
        }
        else
        {
            //W05.34 For Chinese Symbols Keyboard
            //W06.04 For Chinese Symbols Keyboard in Quick Search
            gPenEditorPreviousVirtualKeyboardType = MMI_virtual_keyboard.lang_type;
            if (INPUT_MODE_MMI_MULTITAP_BPMF == MMI_current_input_mode
                || INPUT_MODE_MMI_MULTITAP_PINYIN == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL);
            }
        #ifdef __MMI_LANG_PERSIAN__        
            else if (INPUT_MODE_MMI_MULTITAP_PERSIAN == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL);
            }
        #endif /*__MMI_LANG_PERSIAN__*/
        #ifdef __MMI_LANG_ARABIC__        
            else if (INPUT_MODE_MMI_MULTITAP_ARABIC == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS);
            }
        #endif /*__MMI_LANG_ARABIC__*/
        #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            else if (is_european_symbol == MMI_TRUE)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS);
            }
        #endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/
            else
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_SYMBOL);
            }
        }
        if (MMI_virtual_keyboard.height < mmi_pen_editor_get_candidate_box_height())
        {
            changed_height -= mmi_pen_editor_get_candidate_box_height();
        }
        else
        {
            changed_height -= MMI_virtual_keyboard.height;
        }
        mmi_pen_editor_resize_content_area(changed_height);
        gdi_layer_unlock_frame_buffer();
        RedrawCategoryControlledArea200Screen(NULL);
        return;
    }
    changed_height = MMI_virtual_keyboard.height;
    if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
    {
        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
        {
            changed_height = PEN_EDITOR_BLOCK_HEIGHT;
        }
        else
        {
            changed_height = mmi_pen_editor_get_candidate_box_height();
        }
    }
    gdi_layer_lock_frame_buffer();
    if (GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type ||
        GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type 
#ifdef __MMI_LANG_PERSIAN__        
        || GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL == MMI_virtual_keyboard.lang_type
#endif /*__MMI_LANG_PERSIAN__*/
#ifdef __MMI_LANG_ARABIC__        
        || GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS == MMI_virtual_keyboard.lang_type
#endif /*__MMI_LANG_ARABIC__*/    
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
        || GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS == MMI_virtual_keyboard.lang_type
#endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/
        )
    {
        mmi_pen_editor_hide_virtual_keyboard_area();
        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
        {
            if (gPenEditorPreviousVirtualKeyboardType != GUI_VIRTUAL_KEYBOARD_TRAY)
            {
                wgui_setup_virtual_keyboard(gPenEditorPreviousVirtualKeyboardType);
            }
            else
            {
                is_back_to_multi_block = MMI_TRUE;
            }
        }
        else
        {
            wgui_setup_virtual_keyboard(gPenEditorPreviousVirtualKeyboardType);
        }
        if (GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
        {
            changed_height -= (mmi_pen_editor_get_candidate_box_height() + 1);
            gPenEditorVKCandidate = MMI_TRUE;
            mmi_pen_editor_hide_candidate_area();
        }
    }
    else
    {
        gPenEditorPreviousVirtualKeyboardType = MMI_virtual_keyboard.lang_type;
        if (GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
        {
            //W05.35 VK Symbol Picker should reset gPenEditorVKText
            //W05.38 Consider gPenEditorSelectCandidate and gPenEditorVKText.TextLength
            //W05.48 Fix Right Soft Key Display Issue
            if (gPenEditorVKText.TextLength || mmi_pen_editor_is_candidate_in_selection())
            {
                mmi_pen_editor_set_candidate_selection_status(MMI_FALSE);
                /* Temp Solution for LSK Text Update */
                mmi_pen_editor_set_left_soft_key();
                switch (mmi_pen_editor_get_input_box_type())
                {
                    case PEN_EDITOR_EMS_INPUT_BOX:
                        register_EMS_inputbox_keys();
                        break;

                    case PEN_EDITOR_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                        register_multiline_inputbox_keys();
                        if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
                        {
                            cat201_register_key_func();
                        }
                        break;

                    default:
                        break;
                }
                mmi_pen_editor_reset_vk_text(&gPenEditorVKText);
                wgui_set_virtual_keyboard_display_area((U8*) gPenEditorVKText.VKText, MMI_FALSE);
                switch (mmi_pen_editor_get_input_box_type())
                {
                    case PEN_EDITOR_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                        /* W05.34 for RSK and LSK issue when gPenEditorVKText reset */
                        wgui_handle_inputbox_input();
                        wgui_set_RSK();
                        break;

                    case PEN_EDITOR_EMS_INPUT_BOX:
                        /* W05.34 for RSK and LSK issue when gPenEditorVKText reset */
                        handle_category28_input();
                        wgui_set_EMS_inputbox_RSK();
                        break;

                    default:
                        break;;
                }
            }
            mmi_pen_editor_hide_virtual_keyboard_area();
            changed_height += (mmi_pen_editor_get_candidate_box_height() + 1);
            gPenEditorVKCandidate = MMI_FALSE;
            mmi_pen_editor_set_candidate_selection_status(MMI_FALSE);
        }
        /* W05.34 For Chinese Symbols Keyboard */
        if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_STROKE == MMI_current_input_mode
            || INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode
            || INPUT_MODE_SM_PINYIN == MMI_current_input_mode || INPUT_MODE_SM_STROKE == MMI_current_input_mode)
        {
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL);
        }
    #ifdef __MMI_LANG_PERSIAN__        
        else if (INPUT_MODE_MULTITAP_PERSIAN == MMI_current_input_mode 
            || INPUT_MODE_MMI_MULTITAP_PERSIAN == MMI_current_input_mode
            || INPUT_MODE_SMART_PERSIAN == MMI_current_input_mode)
        {
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL);
        }
    #endif /*__MMI_LANG_PERSIAN__*/
    #ifdef __MMI_LANG_ARABIC__        
        else if (INPUT_MODE_MULTITAP_ARABIC == MMI_current_input_mode 
            || INPUT_MODE_MMI_MULTITAP_ARABIC == MMI_current_input_mode
            || INPUT_MODE_SMART_ARABIC == MMI_current_input_mode)
        {
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS);
        }
    #endif /*__MMI_LANG_ARABIC__*/    
    #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
        else if (is_european_symbol == MMI_TRUE)
        {
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS);
        }
    #endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/
        else
        {
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_SYMBOL);
        }
    }
    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
	    if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type && !is_back_to_multi_block)
        {
            changed_height -= MMI_virtual_keyboard.height;
            mmi_pen_editor_resize_content_area(changed_height);
        }
        else
        {
#if  !defined(LANG_TH_HANDWRITE_SUPPORT)
	  // Huyanwei Modify It 
         //mmi_pen_editor_enable_multi_block_handwriting();
            if(MMI_virtual_keyboard.lang_type <= GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL) //sc.wu remove handwriting for multilanguage
#else
            if(MMI_virtual_keyboard.lang_type <= GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL) 

#endif
                mmi_pen_editor_enable_multi_block_handwriting();
            else
                mmi_pen_editor_disable_multi_block_handwriting();            
        }
    }
    else
    {
        if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type)
        {
            changed_height -= MMI_virtual_keyboard.height;
        }
        else
        {
            changed_height -= mmi_pen_editor_get_candidate_box_height();
        }
        mmi_pen_editor_resize_content_area(changed_height);
    }
    /* W05.36 Adjust the List height for In-line Multiline Input Box */
    if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
        || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
    {
        MMI_BOOL symbol_keyboard;
        S32 temp_multiline_height = MMI_multiline_inputbox.height;
        gui_virtual_keyboard_language_enum tempVirtualKeyboardType = MMI_virtual_keyboard.lang_type;
        MMI_BOOL temp_VKCandidate = gPenEditorVKCandidate;

        if (GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type
            || GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type
#ifdef __MMI_LANG_PERSIAN__        
            || GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL == MMI_virtual_keyboard.lang_type
#endif /*__MMI_LANG_PERSIAN__*/
#ifdef __MMI_LANG_ARABIC__        
            || GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS == MMI_virtual_keyboard.lang_type
#endif /*__MMI_LANG_ARABIC__*/    
#ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            || GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS == MMI_virtual_keyboard.lang_type
#endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/
            )
        {
            symbol_keyboard = MMI_TRUE;
        }
        else
        {
            symbol_keyboard = MMI_FALSE;
        }
        mmi_pen_editor_set_vk_resize(MMI_TRUE);
        mmi_pen_editor_vk_list_menu_resize();
        mmi_pen_editor_set_vk_resize(MMI_FALSE);
        if (PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            gui_resize_multi_line_input_box(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.width,
                temp_multiline_height);
            redraw_fixed_list();
            redraw_current_inline_item();
            gPenEditorVKCandidate = temp_VKCandidate;
        }
        if (symbol_keyboard)
        {
            if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode
                || INPUT_MODE_TR_BOPOMO == MMI_current_input_mode
                || INPUT_MODE_TR_STROKE == MMI_current_input_mode
                || INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode
                || INPUT_MODE_SM_PINYIN == MMI_current_input_mode || INPUT_MODE_SM_STROKE == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL);
            }
         #ifdef __MMI_LANG_PERSIAN__        
            else if (INPUT_MODE_MULTITAP_PERSIAN == MMI_current_input_mode 
                     || INPUT_MODE_MMI_MULTITAP_PERSIAN == MMI_current_input_mode
                     || INPUT_MODE_SMART_PERSIAN == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_FARSI_SYMBOL);
            }
         #endif /*__MMI_LANG_PERSIAN__*/
         #ifdef __MMI_LANG_ARABIC__        
            else if (INPUT_MODE_MULTITAP_ARABIC == MMI_current_input_mode 
                || INPUT_MODE_MMI_MULTITAP_ARABIC == MMI_current_input_mode
                || INPUT_MODE_SMART_ARABIC == MMI_current_input_mode)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ARABIC_SYMBOLS);
            }
         #endif /*__MMI_LANG_ARABIC__*/    
         #ifdef __MMI_VKBD_EUROPEAN_SUPPORT__
            else if (is_european_symbol == MMI_TRUE)
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EUROPEAN_SYMBOLS);
            }
         #endif /*__MMI_VKBD_EUROPEAN_SUPPORT__*/
            else
            {
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_SYMBOL);
            }
        }
        else
        {
            if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
            {
                if (GUI_VIRTUAL_KEYBOARD_TRAY != tempVirtualKeyboardType)
                {
                    wgui_setup_virtual_keyboard(tempVirtualKeyboardType);
                }
            }
            else
            {
                wgui_setup_virtual_keyboard(tempVirtualKeyboardType);
            }
        }
    }
    if (gPenEditorVKCandidate)
    {
        gui_move_single_line_input_box(
            mmi_pen_editor_get_candidate_box(),
            mmi_pen_editor_get_candidate_box_x(),
            MMI_virtual_keyboard.y - mmi_pen_editor_get_candidate_box_height() - 2);
        mmi_pen_editor_hide_candidate_area();
    }
    gdi_layer_unlock_frame_buffer();
    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
        if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
        {
            mmi_pen_editor_set_multi_block_stroke_area(0, 3, MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_compute_candidate_input_box_height() + 4, (UI_device_width >> 1) - 2, MMI_content_y + MMI_content_height - 3);
            mmi_pen_editor_set_multi_block_stroke_area(1, (UI_device_width >> 1) + 1, MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_compute_candidate_input_box_height() + 4, UI_device_width - 3, MMI_content_y + MMI_content_height - 3);

		    mmi_pen_editor_set_handwriting_enabled_or_not(MMI_TRUE);
            mmi_pen_start_capture_strokes(
                PEN_EDITOR_STROKE_BUFFER_SIZE,
                mmi_pen_editor_get_stroke_buffer(),
                2,
                mmi_pen_editor_get_multi_block_stroke_area(),
                NULL);
            memcpy(
                mmi_pen_editor_get_original_handwriting_area(),
                mmi_pen_editor_get_multi_block_stroke_area(),
                sizeof(mmi_pen_handwriting_area_struct));
            mmi_pen_register_stroke_down_handler(mmi_pen_editor_multi_block_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(NULL, NULL, mmi_pen_editor_multi_block_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_pen_editor_multi_block_stroke_up_handler);

            mmi_pen_editor_hand_writing_initialize();
            mmi_pen_begin_strokes_of_character();
        }
        else
        {
            mmi_pen_stop_capture_strokes();
        }
    }
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_clear_and_show_virtual_keyboard_area
 * DESCRIPTION
 *  Clear the area of the virtual keyboard and draw it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_clear_and_show_virtual_keyboard_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;

    /* W06.02 Disable invalid keys in Virtual Keyboard */
    mmi_pen_editor_vk_disable_keys();
    gui_reset_clip();
    gdi_layer_lock_frame_buffer();
    if (MMI_virtual_keyboard.height < mmi_pen_editor_get_candidate_box_height())
    {
        changed_height = mmi_pen_editor_get_candidate_box_height() - MMI_virtual_keyboard.height;
    }
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(
            0,
            MMI_virtual_keyboard.y - changed_height - 2,
            UI_device_width,
            MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        /* To Display Background in the area of the virtual keyboard when list menu */
        if (((PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()) && (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)))
            || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            gui_show_list_menu_background_outside_area(&MMI_fixed_list_menu,
                0,
                MMI_virtual_keyboard.y - changed_height - 2,
                UI_device_width,
                MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1);
        }
        else
        {
            gui_fill_rectangle(
                0,
                MMI_virtual_keyboard.y - changed_height - 2,
                UI_device_width,
                MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1,
                c);
        }
    }

    gui_show_virtual_keyboard(&MMI_virtual_keyboard);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}   /* end of mmi_pen_editor_hide_candidate_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_hide_virtual_keyboard_area
 * DESCRIPTION
 *  Clear the area of the virtual keyboard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_hide_virtual_keyboard_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;

    gui_reset_clip();
    gdi_layer_lock_frame_buffer();
    if (MMI_virtual_keyboard.height < mmi_pen_editor_get_candidate_box_height())
    {
        changed_height = mmi_pen_editor_get_candidate_box_height() - MMI_virtual_keyboard.height;
    }
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(
            0,
            MMI_virtual_keyboard.y - changed_height - 2,
            UI_device_width,
            MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        /* To Display Background in the area of the virtual keyboard when list menu */
        if (((PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()) && (!(MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)))
            || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            gui_show_list_menu_background_outside_area(&MMI_fixed_list_menu,
                0,
                MMI_virtual_keyboard.y - changed_height - 2,
                UI_device_width,
                MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1);
        }
        else
        {
            gui_fill_rectangle(
                0,
                MMI_virtual_keyboard.y - changed_height - 2,
                UI_device_width,
                MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1,
                c);
        }
    }
    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(
        0,
        MMI_virtual_keyboard.y - changed_height - 2,
        UI_device_width - 1,
        MMI_virtual_keyboard.y + MMI_virtual_keyboard.height - 1);
}   /* end of mmi_pen_editor_hide_candidate_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_history_vk_lang_type
 * DESCRIPTION
 *  Get the type of the virtual keyboard when closing input box. This function is used when getting history data
 * PARAMETERS
 *  void
 * RETURNS
 *  The type of the virtual keyboard when closing input box
 *****************************************************************************/
gui_virtual_keyboard_language_enum mmi_pen_editor_history_vk_lang_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPenEditorHistoryVirtualKeyboardType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_vk_text
 * DESCRIPTION
 *  Reset the virtual keyboard text
 * PARAMETERS
 *  peneditorvktext     [OUT]     The text of virtual keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_vk_text(mmi_pen_editor_vk_text_struct *peneditorvktext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(peneditorvktext, 0, sizeof(mmi_pen_editor_vk_text_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_virtual_keyboard_by_input_mode
 * DESCRIPTION
 *  Set the type of virtual keyboard by input mode
 * PARAMETERS
 *  input_mode      [IN]        The input mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_virtual_keyboard_by_input_mode(S32 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 vk_type;
    MMI_BOOL has_candidate;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        mmi_pen_editor_get_vk_type_by_input_mode_for_quick_search(input_mode, &vk_type, &has_candidate) ;
    }
    else
        mmi_pen_editor_get_vk_type_by_input_mode(input_mode, &vk_type, &has_candidate) ;

    if (vk_type != 0xFF)
    {
        gPenEditorVKCandidate = has_candidate;
        wgui_setup_virtual_keyboard((gui_virtual_keyboard_language_enum)vk_type);
    }
    else
        MMI_ASSERT(0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_insert_character
 * DESCRIPTION
 *  Insert character into Virtual Keyboard Text
 * PARAMETERS
 *  vk_text     [OUT]       The virtual keyboard text control
 *  ch          [IN]        The character to insert
 * RETURNS
 *  MMI_TRUE  : Success to insert
 * 	MMI_FALSE : Failed to insert
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_vk_insert_character(mmi_pen_editor_vk_text_struct *vk_text, UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_virtual_keyboard.lang_type)
    {
        case GUI_VIRTUAL_KEYBOARD_BOPOMO:
            if (vk_text->TextLength < PEN_EDITOR_MAX_BOPOMOFO_SIZE - 1)
            {
                vk_text->VKText[vk_text->TextLength++] = ch;
                return MMI_TRUE;
            }
            return MMI_FALSE;

        case GUI_VIRTUAL_KEYBOARD_PINYIN:
            if ((vk_text->TextLength < PEN_EDITOR_MAX_PINYIN_SIZE - 1) && (ch > 0x60) && (ch < 0x7b))
            {
                vk_text->VKText[vk_text->TextLength++] = ch;
                return MMI_TRUE;
            }
            return MMI_FALSE;

        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_delete_character
 * DESCRIPTION
 *  Delete the last character in Virtual Keyboard Text
 * PARAMETERS
 *  vk_text     [OUT]     The virtual keyboard text control
 * RETURNS
 *  MMI_TRUE  : Success to delete
 * 	MMI_FALSE : Failed to delete
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_vk_delete_character(mmi_pen_editor_vk_text_struct *vk_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vk_text->TextLength > 0)
    {
        vk_text->VKText[--vk_text->TextLength] = '\0';
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_vk_to_show
 * DESCRIPTION
 *  Call mmi_pen_editor_vk_show at the beginning or not
 * PARAMETERS
 *  enable      [IN]        MMI_TRUE : yes
 *                          MMI_FALSE : no
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_vk_to_show(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_vk_show_at_start = enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_resize_multiline_input_box_for_vk
 * DESCRIPTION
 *  Resize the height of the input box according to the virtual keyboard. This function is used for Category28
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_resize_multiline_input_box_for_vk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    color c;
#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
    MMI_BOOL re_entry_flag = MMI_FALSE;
#endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
    gui_reset_clip();

#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
    if (g_pen_editor_resized_by_vk)
    {
        re_entry_flag = MMI_TRUE;
    }
#endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */

    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
        if (!g_pen_editor_resized_by_vk)
        {
	        changed_height = MMI_multitap_height - PEN_EDITOR_BLOCK_HEIGHT - 2;
            if ((GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER == MMI_virtual_keyboard.lang_type)
                 && (MMI_virtual_keyboard.height > mmi_pen_editor_get_candidate_box_height()))
            {
                changed_height -= (MMI_virtual_keyboard.height - mmi_pen_editor_get_candidate_box_height());
            }

	        mmi_pen_editor_resize_content_area(changed_height);
            g_pen_editor_resized_by_vk = MMI_TRUE;
        }
        mmi_pen_editor_draw_handwriting_block();
        if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type)
        {
            /* W06.09 Consider GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL */
            if (((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                 (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)) &&
                (!g_pen_editor_vk_show_at_start))
            {
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
                gui_virtual_keyboard_language_enum vk_lang_type = gPenEditorPreviousVirtualKeyboardType;
            #endif
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
                mmi_pen_editor_vk_symbol_picker(MMI_FALSE);
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
                gPenEditorPreviousVirtualKeyboardType = vk_lang_type;
            #endif
            }
            else if (!(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
                     || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                     || GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER == MMI_virtual_keyboard.lang_type))
            {

            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__    
                if (!re_entry_flag)
                {
            #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
                    mmi_pen_editor_disable_multi_block_handwriting();
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__           
                }
                else
                {
                    mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_TRUE);
                    mmi_pen_editor_resize_content_area(0);
                    mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_FALSE);
                }
            #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */

            }
        }
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
    else
    {
        if (!g_pen_editor_resized_by_vk)
        {
            changed_height = MMI_multitap_height - mmi_pen_editor_get_candidate_box_height() - 1;

            /* This is used to adjust input box height when virtual keyboard enabled */
            changed_height -= 1;

            
            if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
            {
                gdi_draw_solid_rect(
                    0,
                    mmi_pen_editor_get_candidate_box_y() - 2,
                    UI_device_width,
                    mmi_pen_editor_get_candidate_box_y() + mmi_pen_editor_get_candidate_box_height() - 1,
                    GDI_COLOR_TRANSPARENT);
            }
            else
            {
                gui_fill_rectangle(
                    0,
                    mmi_pen_editor_get_candidate_box_y() - 2,
                    UI_device_width,
                    mmi_pen_editor_get_candidate_box_y() + mmi_pen_editor_get_candidate_box_height() - 1,
                    c);
            }

            if (mmi_pen_editor_get_input_box_type() == PEN_EDITOR_DICT_MULTILINE_INPUT_BOX)
            { /* For special case of category 201 */
                U8 vk_type;
                MMI_BOOL has_candidate_box = MMI_FALSE;

                mmi_pen_editor_get_vk_type_by_input_mode(MMI_current_input_mode, &vk_type, &has_candidate_box);

                if (has_candidate_box == MMI_TRUE 
                    && !((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) 
                         ||(GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)))
                {
                    changed_height--;
                }    
            }
            
            mmi_pen_editor_resize_content_area(changed_height);
            g_pen_editor_resized_by_vk = MMI_TRUE;
        }

        if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type)
        {
            /* W06.09 Consider GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL */
            if (((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                 (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)) &&
                (!g_pen_editor_vk_show_at_start))
            {
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
                gui_virtual_keyboard_language_enum vk_lang_type = gPenEditorPreviousVirtualKeyboardType;
            #endif
                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
                mmi_pen_editor_vk_symbol_picker(MMI_FALSE);
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
                gPenEditorPreviousVirtualKeyboardType = vk_lang_type;
            #endif
            }
            else if (GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
                     || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                     || GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER == MMI_virtual_keyboard.lang_type)
            {
                gui_virtual_keyboard_language_enum temp_vk_lang_type = MMI_virtual_keyboard.lang_type;

                wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
                /* changed_height = MMI_virtual_keyboard.height; */
                changed_height = mmi_pen_editor_get_candidate_box_height();
                wgui_setup_virtual_keyboard(temp_vk_lang_type);
                if (MMI_virtual_keyboard.height < mmi_pen_editor_get_candidate_box_height())
                {
                    changed_height -= mmi_pen_editor_get_candidate_box_height();
                }
                else
                {
                   changed_height -= MMI_virtual_keyboard.height;
                }
                mmi_pen_editor_resize_content_area(changed_height);
            }
            else
            {
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__  
                if (!re_entry_flag)
                {
            #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
                    mmi_pen_editor_vk_show();
            #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__          
                }
                else
                {
                    mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_TRUE);
                    mmi_pen_editor_resize_content_area(0);
                    mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_FALSE);
                }
            #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
            }
        }
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_resized_by_vk_or_not
 * DESCRIPTION
 *  Set that whether it is resized by vk
 * PARAMETERS
 *  is_resized_by_vk        [IN]     Whether it is resized by vk
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_resized_by_vk_or_not(MMI_BOOL is_resized_by_vk)
{
    g_pen_editor_resized_by_vk = is_resized_by_vk;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_show_vk_at_start_or_not
 * DESCRIPTION
 *  Set that whether it should show vk at start
 * PARAMETERS
 *  show_at_start        [IN]     Whether it should show vk at start
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_show_vk_at_start_or_not(MMI_BOOL show_at_start)
{
    g_pen_editor_vk_show_at_start = show_at_start;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_text
 * DESCRIPTION
 *  Get vk text struct
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to vk text struct
 *****************************************************************************/
mmi_pen_editor_vk_text_struct * mmi_pen_editor_get_vk_text(void)
{
    return &gPenEditorVKText;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_text_string_length
 * DESCRIPTION
 *  Get vk text string length
 * PARAMETERS
 *  void
 * RETURNS
 *  The string length of vk text
 *****************************************************************************/
S8  mmi_pen_editor_get_vk_text_string_length(void)
{
    return gPenEditorVKText.TextLength;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_text_string
 * DESCRIPTION
 *  Get vk text string
 * PARAMETERS
 *  void
 * RETURNS
 *  The string of vk text
 *****************************************************************************/
UI_character_type * mmi_pen_editor_get_vk_text_string(void)
{
    return &(gPenEditorVKText.VKText[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_is_there_vk_candidate_box
 * DESCRIPTION
 *  Return that whether there is vk candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether there is vk candidate box
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_there_vk_candidate_box(void)
{
    return gPenEditorVKCandidate;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_it_has_vk_candidate_box_or_not
 * DESCRIPTION
 *  Set it has vk candidate box or not
 * PARAMETERS
 *  has_candidate_box_or_not    [IN]   Whether there is candidate box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_BOOL has_candidate_box_or_not)
{
    gPenEditorVKCandidate = has_candidate_box_or_not;
}


#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_need_to_hide_to_tray_or_not
 * DESCRIPTION
 *  Return whether vk should be hide to tray type
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether vk should be hide to tray type
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_need_to_hide_to_tray_or_not(void)
{
    return gPenEditorHideToTray;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_whether_vk_hide_to_tray
 * DESCRIPTION
 *  Set whether vk should be hide to tray type
 * PARAMETERS
 *  hide_or_not           [IN]      Whether vk should be hide to tray type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_whether_vk_hide_to_tray(MMI_BOOL hide_or_not)
{
    gPenEditorHideToTray = hide_or_not;
}
#endif/*__MMI_EDITOR_PEN_VK_UNFOLD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_vk_disabled_or_not
 * DESCRIPTION
 *  Set whether vk should be disabled
 * PARAMETERS
 *  disabled_or_not           [IN]      Whether vk should be disabled
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_vk_disabled_or_not(MMI_BOOL disabled_or_not)
{
    g_pen_editor_disable_virtual_keyboard = disabled_or_not;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_history_vk_type
 * DESCRIPTION
 *  Set historical virtual keyboard type
 * PARAMETERS
 *  vk_type           [IN]      The type of virtual keyboard
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_history_vk_type(gui_virtual_keyboard_language_enum vk_type)
{
    gPenEditorHistoryVirtualKeyboardType = vk_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_vk_key_set
 * DESCRIPTION
 *  Reset virtual keyboard key set
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_vk_key_set(void)
{
    memset(&g_pen_editor_vk_keys_set, 0, sizeof(g_pen_editor_vk_keys_set));
    memset(g_pen_editor_vk_characters_disable_list, 0, sizeof(g_pen_editor_vk_characters_disable_list));
    memset(g_pen_editor_vk_event_keys_disable_list, 0, sizeof(g_pen_editor_vk_event_keys_disable_list));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_vk_state
 * DESCRIPTION
 *  Set virtual keyboard state
 * PARAMETERS
 *  vk_state               [IN]       Virtual keyboard state    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_vk_state(mmi_pen_editor_virtual_keyboard_state_enum vk_state)
{
    gPenEditorVKState = vk_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_state
 * DESCRIPTION
 *  Get virtual keyboard state
 * PARAMETERS
 *  void
 * RETURNS
 *  Current virtual keyboard state
 *****************************************************************************/
mmi_pen_editor_virtual_keyboard_state_enum mmi_pen_editor_get_vk_state(void)
{
    return gPenEditorVKState;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 



