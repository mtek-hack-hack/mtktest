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
 * EditorPen_IM.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is EditorPen's sub module which is related to InputMethod Engine 
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
 * add cstar input method
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * rebase maintrunk.MAUI_MBJ on 2007-4-9 0:35:56.
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
static UI_character_type g_pen_editor_syllable_table[PEN_EDITOR_MAX_SYLLABLE_CANDIDATE_SIZE+1][PEN_EDITOR_MAX_PINYIN_SIZE+ 1];

/* W06.09 Touch Screen With Keypad V1 */
static multitap_input g_pen_editor_bpmf_pinyin_active_multitap[MAX_MULTITAPS];

static UI_character_type g_pen_editor_bpmf_pinyin_previous_valid_character = 0;

static U32 g_pen_editor_smart_latin_pre_candidate_length = 0;

static S32 g_pen_editor_smart_latin_candidate_index = 0;

static mmi_pen_editor_key_sequence_struct g_pen_editor_key_sequence;

static U32 g_pen_editor_composition_index = 0;

static U32 g_pen_editor_composition_page = 0;

static S32 g_pen_editor_active_multitap_index = -1;

/* The Page NO. of the candidates (In Chinese Input Method) */
static S32 gPenEditorCandidatePage = 0;

/* The Index NO. of the Selected Candidate */
static S32 gPenEditorCandidateIndex = 0;

static MMI_BOOL g_pen_editor_smart_bmpf_pinyin_syllable_confirmed = MMI_FALSE;
/***************************************************************************** 
* Local Function
*****************************************************************************/
static S32 mmi_pen_editor_get_the_max_syllable_number(void);
#ifdef __MMI_T9_THAI__
static void mmi_pen_editor_smart_thai_pound_key_down_handler(void);
static void mmi_pen_editor_smart_thai_pound_key_up_handler(void);
static void mmi_pen_editor_smart_thai_star_key_down_handler(void);
static void mmi_pen_editor_smart_thai_star_key_up_handler(void);

#endif /*__MMI_T9_THAI__*/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

#if !defined(__MMI_T9__) && !defined(__MMI_ZI__) && !defined(__MMI_CSTAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_phrase
 * DESCRIPTION
 *      Get the Chinese candidates as phrase
 * PARAMETERS
 *  phrase              [IN]        The last character of the phrase
 *  candidatebuffer     [OUT]       Buffer to store candidates
 * RETURNS
 *  Number of the Candidates
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_phrase(UI_character_type phrase, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_composition
 * DESCRIPTION
 *      Get the Chinese candidates from BPMF/PinYin composition
 * PARAMETERS
 *  composition         [IN]     The BPMF/PinYin composition
 *  candidatebuffer     [OUT]    Buffer to store candidates
 * RETURNS
 *      Number of the Candidates
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_composition(UI_character_type *composition, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_page
 * DESCRIPTION
 *      Get the candidates according to the page index
 * PARAMETERS
 *  page                [IN]        The page index
 *  candidatebuffer     [OUT]       Buffer to store candidates
 * RETURNS
 *  Number of the candidates
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_page(S32 page, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_latin_get_candidates_by_key_sequence
 * DESCRIPTION
 *      Get the latin candidate by key sequence
 * PARAMETERS
 *  key_sequence            [IN]        The key sequence
 *  key_sequence_length     [IN]        The length of the key sequence
 *  candidatebuffer         [OUT]       Buffer to store candidates
 * RETURNS
 *  The length of the candidate
 *****************************************************************************/
S32 mmi_ime_smart_latin_get_candidates_by_key_sequence(
        mmi_keypads_enum *key_sequence,
        S32 key_sequence_length,
        UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_latin_get_candidates_by_index
 * DESCRIPTION
 *      Get the candidate according to the index
 * PARAMETERS
 *  index               [IN/OUT]     The index of the candidate
 *  candidatebuffer     [OUT]        Buffer to store candidates
 * RETURNS
 *  The length of the candidate
 *****************************************************************************/
S32 mmi_ime_smart_latin_get_candidates_by_index(S32 *index, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_chinese_stroke_get_candidates_by_key_sequence
 * DESCRIPTION
 *      Get the candidates and strokes from  the stroke key sequence
 * PARAMETERS
 *  key_sequence            [IN]          The stroke key sequence
 *  key_sequence_length     [IN]          The length of the stroke key sequence
 *  candidatebuffer         [OUT]         Buffer to store candidates
 *  strokebuffer            [OUT]         Buffer to store stroke sequence
 * RETURNS
 *  Number of the candidates
 *****************************************************************************/
S32 mmi_ime_chinese_stroke_get_candidates_by_key_sequence(
        mmi_keypads_enum *key_sequence,
        S32 key_sequence_length,
        UI_character_type *candidatebuffer,
        UI_character_type *strokebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence
 * DESCRIPTION
 *      Get the syllables from  the key sequence
 * PARAMETERS
 *  key_sequence            [IN]          The key sequence
 *  key_sequence_length     [IN]          The length of the key sequence
 *  syllable_buffer         [OUT]         Buffer to store syllables
 *  start_index             [IN]          The first index of the syllables
 *  end_index               [IN]          The last index of the syllables
 * RETURNS
 *  Number of the syllables
 *****************************************************************************/
S32 mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence(
        mmi_keypads_enum *key_sequence,
        S32 key_sequence_length,
        UI_character_type *syllable_buffer,
        S32 start_index,
        S32 end_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

#endif /* !defined(__MMI_T9__) && !defined(__MMI_ZI__) && !defined(__MMI_CSTAR__)*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_add_key_sequence
 * DESCRIPTION
 *  Insert the key into key sequence
 * PARAMETERS
 *  key_sequence        [OUT]         The key sequence control
 *  key                 [IN]          The key to insert
 * RETURNS
 *  MMI_TRUE  : Success to insert
 * 	MMI_FALSE : Failed to insert
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_add_key_sequence(mmi_pen_editor_key_sequence_struct *key_sequence, mmi_keypads_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_sequence->KeyLength < PEN_EDITOR_MAX_KEY_BUFFER_SIZE - 1)
    {
        key_sequence->KeySequence[key_sequence->KeyLength++] = key;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_del_key_sequence
 * DESCRIPTION
 *  Delete the last key in key sequence
 * PARAMETERS
 *  key_sequence        [OUT]     The key sequence control
 * RETURNS
 *  MMI_TRUE  : Success to delete
 * 	MMI_FALSE : Failed to delete
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_del_key_sequence(mmi_pen_editor_key_sequence_struct *key_sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_sequence->KeyLength > 0)
    {
        key_sequence->KeySequence[--key_sequence->KeyLength] = '\0';
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_key_sequence
 * DESCRIPTION
 *  Reset the key sequence
 * PARAMETERS
 *  peneditorkeysequence        [OUT]     The key sequence
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_key_sequence(mmi_pen_editor_key_sequence_struct *peneditorkeysequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(peneditorkeysequence, 0, sizeof(mmi_pen_editor_key_sequence_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_remaining_length
 * DESCRIPTION
 *  To know how many characters could be inserted in current state
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of the characters could be inserted
 *****************************************************************************/
S32 mmi_pen_editor_get_remaining_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            return (gui_multi_line_input_box_get_remaining_length(&MMI_multiline_inputbox));

        case PEN_EDITOR_EMS_INPUT_BOX:
            if (MMI_EMS_inputbox.UCS2_count > 0)
            {
                return (EMS_get_remaining_length(MMI_EMS_inputbox.data) >> 1);
            }
            else
            {
                return  EMS_get_remaining_length(MMI_EMS_inputbox.data);
                
            }

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            return (gui_single_line_input_box_get_remaining_length(&MMI_singleline_inputbox));

        case PEN_EDITOR_INLINE_TEXT:
            return (gui_single_line_input_box_get_remaining_length(&MMI_inline_singleline_inputbox));

        case PEN_EDITOR_DATE:
        case PEN_EDITOR_IP4:
        case PEN_EDITOR_TIME:
        case PEN_EDITOR_TIME_PERIOD:
            return 0;

        default:
            MMI_ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_register_arrow_keys
 * DESCRIPTION
 *  Register functions of the arrow keys when there is smart latin candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_register_arrow_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_pen_editor_smart_latin_confirm_candidate_left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_latin_confirm_candidate_right, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_latin_get_candidates_prev, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_latin_get_candidates_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_confirm_candidate_left
 * DESCRIPTION
 *  Confirm and move the cursor to the left of the smart latin candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_confirm_candidate_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < g_pen_editor_smart_latin_pre_candidate_length; i++)
    {
        switch (mmi_pen_editor_get_input_box_type())
        {
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_MULTILINE_INPUT_BOX:
                gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                break;

            case PEN_EDITOR_EMS_INPUT_BOX:
                gui_EMS_input_box_previous(&MMI_EMS_inputbox);
                break;

            default:
                break;
        }
    }
    mmi_pen_editor_left_soft_key_handler();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_confirm_candidate_right
 * DESCRIPTION
 *  Confirm and move the cursor to the right of the smart latin candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_confirm_candidate_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_left_soft_key_handler();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_get_candidates_prev
 * DESCRIPTION
 *  Get the previous smart latin candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_get_candidates_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_KEY_BUFFER_SIZE];
    U32 candidatelength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_smart_latin_candidate_index--;
    candidatelength = mmi_ime_smart_latin_get_candidates_by_index(&g_pen_editor_smart_latin_candidate_index, candidate_buffer);
    if (candidatelength)
    {
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_smart_latin_replace_candidate(candidate_buffer, candidatelength);
        if (g_pen_editor_key_sequence.KeyLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
        {
            mmi_pen_editor_store_LSK_Text();
        }
        mmi_pen_editor_set_left_soft_key_select();
        set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
        mmi_pen_editor_smart_latin_register_arrow_keys();
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_get_candidates_next
 * DESCRIPTION
 *  Get the next smart latin candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_get_candidates_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_KEY_BUFFER_SIZE];
    U32 candidatelength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_smart_latin_candidate_index++;
    candidatelength = mmi_ime_smart_latin_get_candidates_by_index(&g_pen_editor_smart_latin_candidate_index, candidate_buffer);
    if (candidatelength)
    {
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_smart_latin_replace_candidate(candidate_buffer, candidatelength);
        if (g_pen_editor_key_sequence.KeyLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
        {
            mmi_pen_editor_store_LSK_Text();
        }
        mmi_pen_editor_set_left_soft_key_select();
        set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
        mmi_pen_editor_smart_latin_register_arrow_keys();
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_register_arrow_keys
 * DESCRIPTION
 *  Register functions of the arrow keys when the input mode is smart BPMF/PinYin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_register_arrow_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_pen_editor_smart_bpmf_pinyin_get_syllable_prev, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_bpmf_pinyin_get_syllable_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_get_syllable_prev
 * DESCRIPTION
 *  Get the previous smart BPMF/PinYin syllable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_get_syllable_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_composition_index)
    {
        g_pen_editor_composition_index--;
    }
    else
    {
        if (g_pen_editor_composition_page)
        {
            g_pen_editor_composition_index = mmi_pen_editor_get_the_max_syllable_number() - 1;
            g_pen_editor_composition_page--;
            if (!mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE, MMI_TRUE))
            {
                g_pen_editor_composition_index = 0;
                g_pen_editor_composition_page++;
            }
        }
        else
        {
            return;
        }
    }
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(g_pen_editor_composition_index);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_get_syllable_next
 * DESCRIPTION
 *  Get the next smart BPMF/PinYin syllable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_get_syllable_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_syllble_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_syllble_num = mmi_pen_editor_get_the_max_syllable_number();
    if ((g_pen_editor_composition_index < max_syllble_num - 1) &&
        g_pen_editor_syllable_table[g_pen_editor_composition_index + 1][0] != '\0')
    {
        g_pen_editor_composition_index++;
    }
    else if (g_pen_editor_composition_index == max_syllble_num - 1)
    {
        g_pen_editor_composition_index = 0;
        g_pen_editor_composition_page++;
        if (!mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE, MMI_TRUE))
        {
            g_pen_editor_composition_index = max_syllble_num - 1;
            g_pen_editor_composition_page--;
        }
        mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE, MMI_TRUE);
    }
    else
    {
        return;
    }
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(g_pen_editor_composition_index);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable
 * DESCRIPTION
 *  Confirm the selected syllable and do the related action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int num = 0;
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_ON_AND_FOCUS)
    {
        mmi_pen_editor_set_candaidate_state(mmi_pen_editor_get_composition_state(), PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
    }
	mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_composition_box(), 
		                               g_pen_editor_syllable_table[g_pen_editor_composition_index], 
									   -1,
									   MMI_FALSE);
    mmi_pen_editor_show_composition_area(MMI_FALSE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
    num = mmi_ime_get_candidates_by_composition(
            g_pen_editor_syllable_table[g_pen_editor_composition_index],
            candidate_buffer);
	mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(),
		                               candidate_buffer,
									   num,
									   MMI_TRUE);

    mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    g_pen_editor_smart_bmpf_pinyin_syllable_confirmed = MMI_TRUE;
    mmi_pen_editor_register_arrow_keys();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index
 * DESCRIPTION
 *  Set the smart BPMF/PinYin syllable by index
 * PARAMETERS
 *  index       [IN]        The index of the syllable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, num = 0;
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_hide_composition_area();
    gui_single_line_input_box_goto_first_character(mmi_pen_editor_get_composition_box());
    for (i = 0;;)
    {
        UI_character_type ch, ch1, ch2;

        ch1 = *(mmi_pen_editor_get_composition_box_current_text() - 2);
        ch2 = *(mmi_pen_editor_get_composition_box_current_text() - 1);
        ch = ch1 | (ch2 << 8);
        if (ch == 0x20)
        {
            i++;
        }
        if (i == g_pen_editor_composition_index)
        {
            for (i = 0; i < g_pen_editor_key_sequence.KeyLength + 1; i++)
            {
                gui_single_line_input_box_next(mmi_pen_editor_get_composition_box());
            }
            break;
        }
        gui_single_line_input_box_next(mmi_pen_editor_get_composition_box());
    }
    gui_single_line_input_box_previous(mmi_pen_editor_get_composition_box());
    gui_single_line_input_box_highlight_cursor_number(
        mmi_pen_editor_get_composition_box(),
        g_pen_editor_key_sequence.KeyLength);
    mmi_pen_editor_show_composition_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    num = mmi_ime_get_candidates_by_composition(g_pen_editor_syllable_table[index], candidate_buffer);
    gPenEditorCandidatePage = 0;
    gPenEditorCandidateIndex = 0;
	mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);
    mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position
 * DESCRIPTION
 *  Get the syllable index by cursor position (Pen Down)
 * PARAMETERS
 *  void
 * RETURNS
 *  The syllable index
 *****************************************************************************/
S32 mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    UI_buffer_type position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (position = mmi_pen_editor_get_composition_box_text();;)
    {
        UI_character_type ch, ch1, ch2;

        ch1 = *(position);
        ch2 = *(position + 1);
        ch = ch1 | (ch2 << 8);
        if (ch == 0x20)
        {
            i++;
        }
        if (position == mmi_pen_editor_get_composition_box_current_text())
        {
            if (0 == ch || 0x20 == ch)
            {
                i--;
            }
            return i;
        }
        position += 2;
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence
 * DESCRIPTION
 *  Get the candidates from the key sequence for Chinese Stroke
 * PARAMETERS
 *  key_sequence        [IN]     The key sequence of Chinese Stroke
 *  refresh_candidate   [IN]     Whether to refresh candidate area
 * RETURNS
 *  The number of the candidates
 *****************************************************************************/
S32 mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence(mmi_pen_editor_key_sequence_struct *key_sequence, MMI_BOOL refresh_candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    UI_character_type stroke_buffer[PEN_EDITOR_MAX_KEY_BUFFER_SIZE];
    U32 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = mmi_ime_chinese_stroke_get_candidates_by_key_sequence(
            key_sequence->KeySequence,
            key_sequence->KeyLength,
            candidate_buffer,
            stroke_buffer);
    if (num && refresh_candidate)
    {
        mmi_pen_editor_reset_candidate_index();
        if ((mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_OFF))
        {
            int change_height = 0;
        #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__
            gui_virtual_keyboard_language_enum temp_vk_type;
        #endif

            if (PEN_EDITOR_VK_ON == mmi_pen_editor_get_vk_state() && (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type))
            {
                if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
		 {
		      mmi_pen_editor_enable_multi_block_handwriting();
		 }
		 else
            {
                #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__   
                    temp_vk_type = MMI_virtual_keyboard.lang_type;
                #endif
                mmi_pen_editor_vk_hide();
                #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__   
                    wgui_setup_virtual_keyboard(temp_vk_type);
                    if (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_PINYIN || MMI_virtual_keyboard.lang_type ==GUI_VIRTUAL_KEYBOARD_BOPOMO)
                    {
                        mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_TRUE);
                    }
                #endif
            }
            }
            mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
            change_height -= mmi_pen_editor_get_composition_box_height();
            mmi_pen_editor_resize_content_area(change_height);
            mmi_pen_editor_set_candaidate_state(mmi_pen_editor_get_composition_state(), PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
        }
		mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_composition_box(), stroke_buffer, g_pen_editor_key_sequence.KeyLength, MMI_FALSE);

        mmi_pen_editor_show_composition_area(MMI_FALSE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
		mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);

        mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence
 * DESCRIPTION
 *  Get the candidates from the key sequence for Smart BPMF/PinYin
 * PARAMETERS
 *  key_sequence        [IN]         The key sequence of Smart BPMF/PinYin
 *  is_reset            [IN]         MMI_TRUE : Resest the index for the composition box
 *                                   MMI_FALSE : Do not resest the index for the composition box
 *  refresh_candidate   [IN]         Whether to refresh candidate area
 * RETURNS
 *  The number of the candidates
 *****************************************************************************/
S32 mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(
        mmi_pen_editor_key_sequence_struct *key_sequence,
        MMI_BOOL is_reset, MMI_BOOL refresh_candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type syllable_buffer[PEN_EDITOR_MAX_SYLLABLE_BUFFER_SIZE];
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    U32 num = 0, i = 0, j = 0, k = 0;
    S32 start_index,end_index;
    S32 max_syllable_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_syllable_num = mmi_pen_editor_get_the_max_syllable_number();
    if (is_reset)
    {
        start_index = 0;
        end_index = max_syllable_num - 1;
    }
    else
    {
        start_index = g_pen_editor_composition_page * max_syllable_num;
        end_index = (g_pen_editor_composition_page + 1) * max_syllable_num - 1;
    }
    num = mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence(
            key_sequence->KeySequence,
            key_sequence->KeyLength,
            syllable_buffer,
            start_index,
            end_index);
    if (num && refresh_candidate)
    {
        mmi_pen_editor_reset_candidate_index();
        if (is_reset)
        {
            mmi_pen_editor_reset_composition_index();
        }
        if ((mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_OFF))
        {
            int change_height = 0;
        #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__
            gui_virtual_keyboard_language_enum temp_vk_type;
        #endif
            if (PEN_EDITOR_VK_ON == mmi_pen_editor_get_vk_state() && (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type))
            {
				if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
				{
					mmi_pen_editor_enable_multi_block_handwriting();
				}
				else
            {
                #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__   
                    temp_vk_type = MMI_virtual_keyboard.lang_type;
                #endif
                mmi_pen_editor_vk_hide();
                #ifdef  __MMI_EDITOR_PEN_VK_UNFOLD__   
                    wgui_setup_virtual_keyboard(temp_vk_type);
                    if (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_PINYIN || MMI_virtual_keyboard.lang_type ==GUI_VIRTUAL_KEYBOARD_BOPOMO)
                    {
                        mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_TRUE);
                    }
                #endif
            }
            }
            mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
            change_height -= mmi_pen_editor_get_composition_box_height();
            mmi_pen_editor_resize_content_area(change_height);
            mmi_pen_editor_set_candaidate_state(mmi_pen_editor_get_composition_state(), PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
        }
        memset(g_pen_editor_syllable_table, 0, sizeof(g_pen_editor_syllable_table));
        gui_single_line_input_box_delete_all(mmi_pen_editor_get_composition_box());
        for (i = 0;; i++)
        {
            if (syllable_buffer[i])
            {
                gui_single_line_input_box_insert_character(mmi_pen_editor_get_composition_box(), syllable_buffer[i]);
                if (syllable_buffer[i] == 0x20)
                {
                    g_pen_editor_syllable_table[j][k] = '\0';
                    j++;
                    if (j > PEN_EDITOR_MAX_SYLLABLE_CANDIDATE_SIZE)
                        MMI_ASSERT(0);
                    k = 0;
                }
                else
                {
                    g_pen_editor_syllable_table[j][k++] = syllable_buffer[i];
                }
            }
            else
            {
                gui_single_line_input_box_insert_character(mmi_pen_editor_get_composition_box(), 0x20);
                g_pen_editor_syllable_table[j+1][0] = syllable_buffer[i];
                break;
            }
        }
        gui_single_line_input_box_goto_first_character(mmi_pen_editor_get_composition_box());
        for (i = 0;;)
        {
            UI_character_type ch, ch1, ch2;

            ch1 = *(mmi_pen_editor_get_composition_box_current_text() - 2);
            ch2 = *(mmi_pen_editor_get_composition_box_current_text() - 1);
            ch = ch1 | (ch2 << 8);
            if (ch == 0x20)
            {
                i++;
            }
            if (i == g_pen_editor_composition_index)
            {
                for (i = 0; i < g_pen_editor_key_sequence.KeyLength + 1; i++)
                {
                    gui_single_line_input_box_next(mmi_pen_editor_get_composition_box());
                }
                break;
            }
            gui_single_line_input_box_next(mmi_pen_editor_get_composition_box());
        }
        gui_single_line_input_box_previous(mmi_pen_editor_get_composition_box());
        gui_single_line_input_box_highlight_cursor_number(
            mmi_pen_editor_get_composition_box(),
            g_pen_editor_key_sequence.KeyLength);
        //mmi_pen_editor_show_composition_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
        num = mmi_ime_get_candidates_by_composition(
                g_pen_editor_syllable_table[g_pen_editor_composition_index],
                candidate_buffer);
		mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);

        /* To resolve candidate box flashing issue, 
         * move this function call to where calling 
         * mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence
         * and should show candidate area immediately */

        //mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_switch_input_method
 * DESCRIPTION
 *  Change the input method by sequence and do the related action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_switch_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.34 for RSK and LSK issue when gPenEditorVKText reset */
    if (mmi_pen_editor_is_stroke_up_timer_on())
		return;

    gdi_layer_lock_frame_buffer();

    if (mmi_pen_editor_is_candidate_in_selection() || mmi_pen_editor_get_vk_text_string_length() > 0)
    {
        //W05.43 Temp Solution for Switch Input Method Without Complete Selecting Candidate
        //W05.45 Temp Solution for Pen Down When Selecting Candidates
        if (mmi_pen_editor_is_candidate_in_selection())
        {
            gui_cancel_timer(mmi_pen_editor_confirm_selection);
            mmi_pen_editor_confirm_selection();
        }
        mmi_pen_editor_set_candidate_selection_status(MMI_FALSE);
        mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
        wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_FALSE);
        mmi_pen_editor_hide_candidate_area();
        /* Temp Solution for LSK Text Update */
        mmi_pen_editor_set_left_soft_key();
    }
    if (g_pen_editor_smart_latin_pre_candidate_length)
    {
        mmi_pen_editor_smart_latin_confirm_select();
        mmi_pen_editor_set_left_soft_key();
    }
    if (mmi_pen_editor_get_composition_state()->candidate_state != PEN_EDITOR_CANDIDATE_OFF)
    {
        int change_height = 0;

        mmi_pen_editor_set_candaidate_state(mmi_pen_editor_get_composition_state(), PEN_EDITOR_CANDIDATE_OFF);
        change_height += mmi_pen_editor_get_composition_box_height();
        mmi_pen_editor_resize_content_area(change_height);
    }
    /* W05.36 Add Center Soft Key for switching Input Method */
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_EMS_INPUT_BOX:

    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
			wgui_handle_inputbox_change_input_mode_bymultitapthai();
    #else	
            handle_category28_change_input_mode();
    #endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            break;

        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:

	#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
            wgui_handle_inputbox_change_input_mode_bymultitapthai();
    #else
            wgui_handle_inputbox_change_input_mode();
    #endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            break;

        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
            wgui_handle_qsearch_change_input_mode_bymultitapthai();
    #else
            wgui_handle_qsearch_singleline_inputbox_change_input_mode();
    #endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            wgui_set_singleline_RSK();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
            wgui_handle_inputbox_change_input_mode_bymultitapthai();
    #else
            wgui_handle_singleline_inputbox_change_input_mode();
    #endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            break;

        case PEN_EDITOR_INLINE_TEXT:
    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
            wgui_handle_inputbox_change_input_mode_bymultitapthai();
    #else
            wgui_handle_inline_singleline_inputbox_change_input_mode();
    #endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    if (GUI_VIRTUAL_KEYBOARD_TRAY != MMI_virtual_keyboard.lang_type)
    {
        changed_height = MMI_virtual_keyboard.height;
        mmi_pen_editor_hide_virtual_keyboard_area();
        if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            mmi_pen_editor_set_virtual_keyboard_by_input_mode(MMI_current_input_mode);
            if (!mmi_pen_editor_is_there_vk_candidate_box())
            {
                changed_height += (mmi_pen_editor_get_candidate_box_height() + 1);
            }
        }
        else
        {
            mmi_pen_editor_set_virtual_keyboard_by_input_mode(MMI_current_input_mode);
            if (mmi_pen_editor_is_there_vk_candidate_box())
            {
                changed_height -= (mmi_pen_editor_get_candidate_box_height() + 1);
                gui_move_single_line_input_box(
                    mmi_pen_editor_get_candidate_box(),
                    mmi_pen_editor_get_candidate_box_x(),
                    MMI_virtual_keyboard.y - mmi_pen_editor_get_candidate_box_height() - 2);
                mmi_pen_editor_hide_candidate_area();
            }
        }
        changed_height -= MMI_virtual_keyboard.height;
    }
#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
    else
    {
        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
        {
            mmi_pen_editor_disable_multi_block_handwriting();
        }
        else
        {
            mmi_pen_editor_vk_show();
        }

    }
#endif
    mmi_pen_editor_resize_content_area(changed_height);
    /* W05.36 Adjust the List height for In-line Multiline Input Box */
    if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
        || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
    {
        S32 temp_multiline_height = MMI_multiline_inputbox.height;
        MMI_BOOL temp_VKCandidate = mmi_pen_editor_is_there_vk_candidate_box();
        U8 temp_current_input_mode = MMI_current_input_mode;
        gui_virtual_keyboard_language_enum keyboard_type = MMI_virtual_keyboard.lang_type;
    #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
        mmi_pen_editor_set_whether_vk_hide_to_tray(MMI_TRUE);
    #endif    
        mmi_pen_editor_vk_list_menu_resize();
    #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
        mmi_pen_editor_set_whether_vk_hide_to_tray(MMI_FALSE);
    #endif
        MMI_current_input_mode = temp_current_input_mode;
        inputbox_change_mode();
        set_MMI_current_input_type();
        if (PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            gui_resize_multi_line_input_box(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.width,
                temp_multiline_height);
            mmi_pen_editor_set_it_has_vk_candidate_box_or_not(temp_VKCandidate);
            redraw_fixed_list();
            redraw_current_inline_item();
        }
        wgui_setup_virtual_keyboard(keyboard_type);
        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
        {
            if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
            {
                wgui_move_virtual_keyboard(
                    MMI_virtual_keyboard.x,
                    MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + 3);
            }
        }
        if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            gui_move_single_line_input_box(
                mmi_pen_editor_get_candidate_box(),
                mmi_pen_editor_get_candidate_box_x(),
                MMI_virtual_keyboard.y - mmi_pen_editor_get_candidate_box_height() - 2);
            mmi_pen_editor_hide_candidate_area();
        }
    }
    
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        cat200_virtual_keypad_callback();
    }
    else
    {
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
    /* W05.34 Clear key handler when switching input method */
    /* W06.09 Touch Screen With Keypad V1 */
    /* mmi_pen_editor_clear_key_handler(); */
    if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode ||
        INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode)
    {
        mmi_pen_editor_bpmf_pinyin_create_multitap(MMI_current_input_mode);
        mmi_pen_editor_bpmf_pinyin_register_multitap_function();
    }
    else if ((IME_LANG_ATTR_ALPHABETIC & mmi_pen_editor_get_Lang_special_attrib_by_input_mode(MMI_current_input_mode)) &&
             (IME_MODE_ATTR_SMART & mmi_pen_editor_get_mode_special_attrib_by_input_mode(MMI_current_input_mode)))
    {
        mmi_pen_editor_smart_latin_register_key_function();
    }
    else if (INPUT_MODE_TR_STROKE == MMI_current_input_mode || INPUT_MODE_SM_STROKE == MMI_current_input_mode)
    {
        mmi_pen_editor_chinese_stroke_register_key_function();
    }
    else if (INPUT_MODE_TR_BOPOMO == MMI_current_input_mode || INPUT_MODE_SM_PINYIN == MMI_current_input_mode)
    {
        mmi_pen_editor_smart_bpmf_pinyin_register_key_function();
        mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
    }
    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
        SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_LONG_PRESS);
        SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_REPEAT);
    #else
        SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_EVENT_DOWN);
    #endif /*__MMI_MULTITAP_FOR_STAR_AND_POUND__*/
    mmi_pen_editor_set_CSK_content();
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
    if (g_pen_editor_key_sequence.KeyLength !=0)
    {
        mmi_pen_editor_reset_key_sequence(&g_pen_editor_key_sequence);
    }

    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

    /* need by penpower and decuma for initialize engine when switch input method. */
    mmi_pen_editor_hand_writing_initialize();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_change_inputbox_mode
 * DESCRIPTION
 *  Change inputbox input mode
 * PARAMETERS
 *  input_mode           [IN]            desired input mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_change_inputbox_mode(U8 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            change_multiline_inputbox_mode(input_mode);
            wgui_redraw_input_information_bar();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            change_EMS_inputbox_mode(input_mode);
            wgui_EMS_redraw_input_information_bar();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
            change_singleline_inputbox_mode(input_mode);
            break;

        case PEN_EDITOR_INLINE_TEXT:
            inline_edit_change_singleline_inputbox_mode(input_mode);
            break;

        default:
            break;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_pen_editor_setup_input_by_keypad(MMI_current_input_type);
}


/* W06.09 Touch Screen With Keypad V1 */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_key_down_handler
 * DESCRIPTION
 *  The handler of key down(number keys) in Multitap BPMF/PinYin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_key_down_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if (mmi_pen_editor_is_stroke_up_timer_on())
   	return;
    mmi_pen_editor_cancel_handwriting();
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif

	if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
        mmi_pen_editor_disable_multi_block_handwriting();
    }

    if (mmi_pen_editor_is_candidate_in_selection() && (0 == mmi_pen_editor_get_vk_text_string_length()))
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        mmi_pen_editor_confirm_selection();
    }
	
    if (key < 0 || key > MAX_MULTITAPS - 1)
    {
        return;
    }

    if (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL)
    {
        mmi_pen_editor_vk_symbol_picker(MMI_FALSE);
    }
    if (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_TRAY)
    {
        mmi_pen_editor_vk_show();
    }
    if (key != g_pen_editor_active_multitap_index)
    {
        if (g_pen_editor_active_multitap_index >= 0)
        {
            gui_multitap_input_complete(&
                                        (g_pen_editor_bpmf_pinyin_active_multitap[g_pen_editor_active_multitap_index]));
        }
        g_pen_editor_active_multitap_index = key;
    }

    gui_change_multitap_input_state(&(g_pen_editor_bpmf_pinyin_active_multitap[g_pen_editor_active_multitap_index]));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_key_up_handler
 * DESCRIPTION
 *  The handler of key up(number keys) in Multitap BPMF/PinYin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_key_up_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if (mmi_pen_editor_is_stroke_up_timer_on())
   	return;
    UI_UNUSED_PARAMETER(key);
    gui_start_timer(MMI_MULTITAP_TIMEOUT, mmi_pen_editor_bpmf_pinyin_disable_active_multitap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_disable_active_multitap
 * DESCRIPTION
 *  Complete Multitap input for Multitap BPMF/PinYin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_disable_active_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_active_multitap_index < 0)
    {
        return;
    }
    gui_multitap_input_complete(&g_pen_editor_bpmf_pinyin_active_multitap[g_pen_editor_active_multitap_index]);
    g_pen_editor_active_multitap_index = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_multitap_input
 * DESCRIPTION
 *  Handle the multitap input character c in multitap BPMF/PinYin
 * PARAMETERS
 *  c       [IN]        The multitap input character
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_bpmf_pinyin_previous_valid_character)
    {
        mmi_pen_editor_vk_delete_character(mmi_pen_editor_get_vk_text());
    }
    if (mmi_pen_editor_vk_insert_character(mmi_pen_editor_get_vk_text(), c))
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
            if (mmi_pen_editor_get_vk_text_string_length() == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
            {
                mmi_pen_editor_store_LSK_Text();
            }
            mmi_pen_editor_set_left_soft_key_select();
            set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
            set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
            mmi_pen_editor_set_candidate_selection_status(MMI_TRUE);
            mmi_pen_editor_register_arrow_keys();
            mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_CLEAR);
            g_pen_editor_bpmf_pinyin_previous_valid_character = c;
        }
        else
        {
            mmi_pen_editor_vk_delete_character(mmi_pen_editor_get_vk_text());

            /*To synchronize editorpen symbol buffer and IM engine symbol buffer*/
            mmi_pen_editor_get_candidates_by_vk(MMI_FALSE);
            if (g_pen_editor_bpmf_pinyin_previous_valid_character)
            {
                mmi_pen_editor_vk_insert_character(
                    mmi_pen_editor_get_vk_text(),
                    g_pen_editor_bpmf_pinyin_previous_valid_character);
            }
        }
    }
    wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_multitap_input_complete
 * DESCRIPTION
 *  Set g_pen_editor_bpmf_pinyin_previous_valid_character to 0 when conmpleting multitap input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_bpmf_pinyin_previous_valid_character = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_register_multitap_function
 * DESCRIPTION
 *  Register key functions for Multitap BPMF/PinYin and set Multitap BPMF/Pinyin functions to g_pen_editor_bpmf_pinyin_active_multitap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_register_multitap_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(mmi_pen_editor_bpmf_pinyin_key_up_handler);
    register_key_down_handler(mmi_pen_editor_bpmf_pinyin_key_down_handler);
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        gui_set_multitap_input_callbacks(
            &g_pen_editor_bpmf_pinyin_active_multitap[i],
            mmi_pen_editor_bpmf_pinyin_multitap_input,
            mmi_pen_editor_bpmf_pinyin_multitap_input_complete);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bpmf_pinyin_create_multitap
 * DESCRIPTION
 *  Create multitap control according to input_mode
 * PARAMETERS
 *  input_mode      [IN]        Its value should be INPUT_MODE_TR_MULTITAP_BOPOMO or INPUT_MODE_SM_MULTITAP_PINYIN
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bpmf_pinyin_create_multitap(U8 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, width;
    UI_string_type s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width = MMI_multitap_width; /* Width needs to be auto-calculated   */
    g_pen_editor_active_multitap_index = -1;
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode)
        {
            s = get_bpmf_multitap_string(i);
            gui_create_multitap_input(
                &g_pen_editor_bpmf_pinyin_active_multitap[i],
                MMI_multitap_x,
                MMI_multitap_y,
                width,
                MMI_multitap_height,
                s);
        }
        else if (INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode)
        {
            s = (UI_string_type) numberless_lowercase_multitap_strings[i];
            gui_create_multitap_input(
                &g_pen_editor_bpmf_pinyin_active_multitap[i],
                MMI_multitap_x,
                MMI_multitap_y,
                width,
                MMI_multitap_height,
                s);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_register_key_function
 * DESCRIPTION
 *  Register key functions for Smart Latin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_register_key_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(mmi_pen_editor_smart_latin_key_up_handler);
    register_key_down_handler(mmi_pen_editor_smart_latin_key_down_handler);
    ClearKeyHandler(KEY_0, KEY_REPEAT);
    ClearKeyHandler(KEY_1, KEY_REPEAT);
    ClearKeyHandler(KEY_2, KEY_REPEAT);
    ClearKeyHandler(KEY_3, KEY_REPEAT);
    ClearKeyHandler(KEY_4, KEY_REPEAT);
    ClearKeyHandler(KEY_5, KEY_REPEAT);
    ClearKeyHandler(KEY_6, KEY_REPEAT);
    ClearKeyHandler(KEY_7, KEY_REPEAT);
    ClearKeyHandler(KEY_8, KEY_REPEAT);
    ClearKeyHandler(KEY_9, KEY_REPEAT);
#ifdef __MMI_T9_THAI__ /*Only T9 smart Thai need pound key to input characters*/
    if (MMI_current_input_mode == INPUT_MODE_SMART_THAI)
    {
        SetKeyHandler(mmi_pen_editor_smart_thai_pound_key_down_handler, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_pen_editor_smart_thai_pound_key_up_handler, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(mmi_pen_editor_smart_thai_star_key_down_handler, KEY_STAR, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_pen_editor_smart_thai_star_key_up_handler, KEY_STAR, KEY_EVENT_UP);
    }
#endif /*__MMI_T9_THAI__*/

}

#ifdef __MMI_T9_THAI__
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_thai_pound_key_down_handler
 * DESCRIPTION
 *  Key down handler for smart thai
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_editor_smart_thai_pound_key_down_handler(void)
{
    mmi_pen_editor_smart_latin_key_down_handler(KEY_POUND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_thai_pound_key_up_handler
 * DESCRIPTION
 *  Key up handler for smart thai
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_pen_editor_smart_thai_pound_key_up_handler(void)
{
    mmi_pen_editor_smart_latin_key_up_handler(KEY_POUND);
}

/*****************************************************************************
* FUNCTION
*  mmi_pen_editor_smart_thai_star_key_down_handler
* DESCRIPTION
*  Key down handler for smart thai
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_pen_editor_smart_thai_star_key_down_handler(void)
{
    mmi_pen_editor_smart_latin_key_down_handler(KEY_STAR);
}


/*****************************************************************************
* FUNCTION
*  mmi_pen_editor_smart_thai_star_key_up_handler
* DESCRIPTION
*  Key up handler for smart thai
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

static void mmi_pen_editor_smart_thai_star_key_up_handler(void)
{
    mmi_pen_editor_smart_latin_key_up_handler(KEY_STAR);
}

#endif /*__MMI_T9_THAI__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_key_down_handler
 * DESCRIPTION
 *  The handler of key down(number keys) in Smart Latin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_key_down_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_KEY_BUFFER_SIZE];
    U32 candidatelength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if (mmi_pen_editor_is_stroke_up_timer_on())
   	return;
    if (!mmi_pen_editor_get_remaining_length())
    {
        return;
    }
    gdi_layer_lock_frame_buffer();
    if (mmi_pen_editor_is_candidate_in_selection() && !g_pen_editor_key_sequence.KeyLength)
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        mmi_pen_editor_confirm_selection();
    }

    if (KEY_0 == key)
    {
        if (g_pen_editor_smart_latin_pre_candidate_length)
        {
            mmi_pen_editor_smart_latin_confirm_select();
            mmi_pen_editor_set_left_soft_key();
        }
        mmi_pen_editor_input_character(0x20, MMI_FALSE);
    }
    else if (mmi_pen_editor_add_key_sequence(&g_pen_editor_key_sequence, key))
    {
        candidatelength = mmi_ime_smart_latin_get_candidates_by_key_sequence(
                            g_pen_editor_key_sequence.KeySequence,
                            g_pen_editor_key_sequence.KeyLength,
                            candidate_buffer);
        if (candidatelength)
        {
            if (candidatelength < g_pen_editor_key_sequence.KeyLength)
            {
                mmi_pen_editor_smart_latin_confirm_select();
                mmi_pen_editor_del_key_sequence(&g_pen_editor_key_sequence);
                candidatelength = mmi_ime_smart_latin_get_candidates_by_key_sequence(
                                    g_pen_editor_key_sequence.KeySequence,
                                    g_pen_editor_key_sequence.KeyLength,
                                    candidate_buffer);
            }
            mmi_pen_editor_smart_latin_replace_candidate(candidate_buffer, candidatelength);
            if (g_pen_editor_key_sequence.KeyLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
            {
                mmi_pen_editor_store_LSK_Text();
            }
            mmi_pen_editor_set_left_soft_key_select();
            set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
            set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
            mmi_pen_editor_smart_latin_register_arrow_keys();
        }
        else
        {
            mmi_pen_editor_del_key_sequence(&g_pen_editor_key_sequence);

            /*To synchronize editorpen symbol buffer and IM engine symbol buffer*/
            mmi_ime_smart_latin_get_candidates_by_key_sequence(
                g_pen_editor_key_sequence.KeySequence,
                g_pen_editor_key_sequence.KeyLength,
                                    candidate_buffer);
        }
    }
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_key_up_handler
 * DESCRIPTION
 *  The handler of key up(number keys) in Smart Latin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_key_up_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_highlight_candidate
 * DESCRIPTION
 *  Unhighlight the candidate in Smart Latin
 * PARAMETERS
 *  candidate_length        [IN]        The length of the highlighted candidate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_highlight_candidate(U32 candidate_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            count = gui_multi_line_input_box_highlight_cursor_number(&MMI_multiline_inputbox, candidate_length);
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            count = gui_EMS_input_box_highlight_cursor_number(&MMI_EMS_inputbox, candidate_length);
            gui_show_EMS_input_box(&MMI_EMS_inputbox);
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
            count = gui_single_line_input_box_highlight_cursor_number(&MMI_singleline_inputbox, candidate_length);
            break;

        case PEN_EDITOR_INLINE_TEXT:
            count = gui_single_line_input_box_highlight_cursor_number(&MMI_inline_singleline_inputbox, candidate_length);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_unhighlight_candidate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw        [IN]        MMI_TRUE : Redraw the input box
 *                          MMI_FALSE : Do not redraw the input box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_unhighlight_candidate(MMI_BOOL draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            if (draw)
            {
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            }
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
            if (draw)
            {
                gui_show_EMS_input_box(&MMI_EMS_inputbox);
            }
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            if (draw)
            {
                gui_show_single_line_input_box(&MMI_singleline_inputbox);
            }
            break;

        case PEN_EDITOR_INLINE_TEXT:
            MMI_inline_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            if (draw)
            {
                gui_show_single_line_input_box(&MMI_inline_singleline_inputbox);
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_chinese_stroke_register_key_function
 * DESCRIPTION
 *  Register key functions for Chinese Stroke
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_chinese_stroke_register_key_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(mmi_pen_editor_chinese_stroke_key_up_handler);
    register_key_down_handler(mmi_pen_editor_chinese_stroke_key_down_handler);
    ClearKeyHandler(KEY_0, KEY_REPEAT);
    ClearKeyHandler(KEY_1, KEY_REPEAT);
    ClearKeyHandler(KEY_2, KEY_REPEAT);
    ClearKeyHandler(KEY_3, KEY_REPEAT);
    ClearKeyHandler(KEY_4, KEY_REPEAT);
    ClearKeyHandler(KEY_5, KEY_REPEAT);
    ClearKeyHandler(KEY_6, KEY_REPEAT);
    ClearKeyHandler(KEY_7, KEY_REPEAT);
    ClearKeyHandler(KEY_8, KEY_REPEAT);
    ClearKeyHandler(KEY_9, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_chinese_stroke_key_down_handler
 * DESCRIPTION
 *  The handler of key down(number keys) in Chinese Stroke
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_chinese_stroke_key_down_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_pen_editor_is_stroke_up_timer_on())
   	 return;
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_cancel_handwriting();
    if (mmi_pen_editor_is_candidate_in_selection() && (mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_OFF))
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        mmi_pen_editor_confirm_selection();
    }

    if (KEY_0 == key)
    {
    }
    else 
#if defined(__MMI_T9__) 
    if (KEY_7 <= key && KEY_9 >= key)
    {
    }
    else 
#endif
#if defined(__MMI_CSTAR__)
    if (KEY_6 <= key && KEY_9 >= key)
    {
    }
    else
#endif
    if (mmi_pen_editor_add_key_sequence(&g_pen_editor_key_sequence, key))
    {
        if (mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_TRUE))
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
            if (g_pen_editor_key_sequence.KeyLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
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
            mmi_pen_editor_del_key_sequence(&g_pen_editor_key_sequence);

            /*To synchronize editorpen symbol buffer and IM engine symbol buffer*/
            mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE);

        }
    }
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_chinese_stroke_key_up_handler
 * DESCRIPTION
 *  The handler of key up(number keys) in Chinese Stroke
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_chinese_stroke_key_up_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_confirm_select
 * DESCRIPTION
 *  Confirm the selection in Smart Latin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_confirm_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_smart_latin_pre_candidate_length = 0;
    g_pen_editor_smart_latin_candidate_index = 0;
    mmi_pen_editor_smart_latin_unhighlight_candidate(MMI_TRUE);
    mmi_pen_editor_reset_key_sequence(&g_pen_editor_key_sequence);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_latin_replace_candidate
 * DESCRIPTION
 *  Replace the candiate in the input box the candidate is changed
 * PARAMETERS
 *  candidate_buffer        [OUT]         The new candidate
 *  candidatelength         [IN]          The length of the candidate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_latin_replace_candidate(UI_character_type *candidate_buffer, S32 candidatelength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_smart_latin_pre_candidate_length)
    {
        for (i = 0; i < g_pen_editor_smart_latin_pre_candidate_length; i++)
        {
            mmi_pen_editor_backspace();
        }
    }
    g_pen_editor_smart_latin_pre_candidate_length = candidatelength;
    for (i = 0; i < g_pen_editor_smart_latin_pre_candidate_length; i++)
    {
        mmi_pen_editor_input_character(candidate_buffer[i], MMI_FALSE);
    }
    mmi_pen_editor_smart_latin_highlight_candidate(g_pen_editor_smart_latin_pre_candidate_length);
    mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_CLEAR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_register_key_function
 * DESCRIPTION
 *  Register key functions for Smart BPMF/PinYin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_register_key_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(mmi_pen_editor_smart_bpmf_pinyin_key_up_handler);
    register_key_down_handler(mmi_pen_editor_smart_bpmf_pinyin_key_down_handler);
    ClearKeyHandler(KEY_0, KEY_REPEAT);
    ClearKeyHandler(KEY_1, KEY_REPEAT);
    ClearKeyHandler(KEY_2, KEY_REPEAT);
    ClearKeyHandler(KEY_3, KEY_REPEAT);
    ClearKeyHandler(KEY_4, KEY_REPEAT);
    ClearKeyHandler(KEY_5, KEY_REPEAT);
    ClearKeyHandler(KEY_6, KEY_REPEAT);
    ClearKeyHandler(KEY_7, KEY_REPEAT);
    ClearKeyHandler(KEY_8, KEY_REPEAT);
    ClearKeyHandler(KEY_9, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_key_down_handler
 * DESCRIPTION
 *  The handler of key down(number keys) in Smart BPMF/PinYin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_key_down_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_smart_bmpf_pinyin_syllable_confirmed == MMI_TRUE)
        return;
    if (mmi_pen_editor_is_stroke_up_timer_on())
   	return;
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_cancel_handwriting();
    if (mmi_pen_editor_is_candidate_in_selection() && (mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_OFF))
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        mmi_pen_editor_confirm_selection();
    }
    if (KEY_0 == key &&
        (mmi_pen_editor_get_composition_state()->candidate_state == PEN_EDITOR_CANDIDATE_OFF) &&
        INPUT_MODE_SM_PINYIN == MMI_current_input_mode && !mmi_pen_editor_is_candidate_in_selection())
    {
        mmi_pen_editor_input_character(0x20, MMI_FALSE);
    }
    else if (KEY_1 == key && INPUT_MODE_SM_PINYIN == MMI_current_input_mode)
    {
    }
    else if (mmi_pen_editor_add_key_sequence(&g_pen_editor_key_sequence, key))
    {
        if (mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_TRUE, MMI_TRUE))
        {
            mmi_pen_editor_show_composition_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
            mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
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
            if (g_pen_editor_key_sequence.KeyLength == 1 && MMI_FALSE == mmi_pen_editor_is_candidate_in_selection())
            {
                mmi_pen_editor_store_LSK_Text();
            }
            mmi_pen_editor_set_left_soft_key_select();
            set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
            set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
            mmi_pen_editor_set_candidate_selection_status(MMI_TRUE);
            switch (mmi_pen_editor_get_input_box_type())
            {
                case PEN_EDITOR_EMS_INPUT_BOX:
                case PEN_EDITOR_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                    mmi_pen_editor_smart_bpmf_pinyin_register_arrow_keys();
                    break;

                default:
                    break;
            }
            mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_CLEAR);
        }
        else
        {
            mmi_pen_editor_del_key_sequence(&g_pen_editor_key_sequence);

            /*To synchronize editorpen symbol buffer and IM engine symbol buffer*/
            //mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_TRUE, MMI_FALSE);
        }
    }
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_smart_bpmf_pinyin_key_up_handler
 * DESCRIPTION
 *  The handler of key up(number keys) in Smart BPMF/PinYin
 * PARAMETERS
 *  key     [IN]        The key index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_smart_bpmf_pinyin_key_up_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_by_vk
 * DESCRIPTION
 *  To get candidates according to virtual keyboard text
 * PARAMETERS
 *  refresh_candidate   [IN]    Whether to refresh candidate area
 * RETURNS
 *  MMI_TRUE  : The virtual keyboard text is valid
 *  MMI_FALSE : The virtual keyboard text is invalid
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_get_candidates_by_vk(MMI_BOOL refresh_candidate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    int num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_pen_editor_get_vk_text_string_length() > 0)
    {
        /* W05.36 To Fix Candidates Lsit Issue Because of Font Type */
        gui_set_font(mmi_pen_editor_get_candidate_box_text_font());
        num = mmi_ime_get_candidates_by_composition(mmi_pen_editor_get_vk_text_string(), candidate_buffer);
        if (num && refresh_candidate)
        {
            /* W06.10 Reset Candidate Index to avoid incorrect value when adding components */
            mmi_pen_editor_reset_candidate_index();
			mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);

            gdi_layer_lock_frame_buffer();
            mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
            gdi_layer_unlock_frame_buffer();
            gdi_lcd_repaint_all();
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_by_phrase
 * DESCRIPTION
 *  To Get candidates from input character as phrase
 * PARAMETERS
 *  ch      [IN]        The previous character of the phrase
 * RETURNS
 *  MMI_TRUE  : There are candidates as the phrase of ch
 *  MMI_FALSE : There are no candidates as the phrase of ch
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_get_candidates_by_phrase(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    int num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.36 To Fix Candidates Lsit Issue Because of Font Type */
    gui_set_font(mmi_pen_editor_get_candidate_box_text_font());

#ifdef __MMI_PENPOWER_PHRASE__   
    num = mmi_pen_editor_get_candidates_by_phrase_from_penpower(ch, candidate_buffer);
#else
    num = mmi_ime_get_candidates_by_phrase(ch, candidate_buffer);
#endif /* __MMI_PENPOWER_PHRASE__ */

    if (num)
    {
		mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);

        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
        return MMI_TRUE;
    }
    else
    {
        if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            mmi_pen_editor_hide_candidate_area();
        }
        return MMI_FALSE;
    }      

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_by_page
 * DESCRIPTION
 *  To Get the candidates according to the page index
 * PARAMETERS
 *  page        [IN]        The page index
 * RETURNS
 *  MMI_TRUE  : There are candidates for the page index
 *  MMI_FALSE : There are no candidates for the page index
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_get_candidates_by_page(S32 page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    int num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.37 To Fix Candidates Lsit Issue Because of Font Type */
    gui_set_font(mmi_pen_editor_get_candidate_box_text_font());

#ifdef __MMI_PENPOWER_PHRASE__
    num = mmi_pen_editor_get_candidates_by_page_from_penpower(gPenEditorCandidatePage, candidate_buffer);
#else
    num = mmi_ime_get_candidates_by_page(gPenEditorCandidatePage, candidate_buffer);
#endif /* __MMI_PENPOWER_PHRASE__ */

    if (num)
    {
    	  if (gPenEditorCandidateIndex >= num)
        {
            gPenEditorCandidateIndex = num - 1;
        }

		mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE);

        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
        gdi_layer_unlock_frame_buffer();
        /* gdi_lcd_repaint_all(); */
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/************************************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_candidate_and_composition_box
 * DESCRIPTION
 *  To reset candidate and composition box according to the new candidates
 * PARAMETERS
 *  candidate_box        [IN]    Point to the single line input box structure
 *  candidate_buffer     [IN]    The candidate buffer
 *  num                  [IN]    The number of candidates to insert, -1 for the entire candidates
 *  is_highlight_first   [IN]    If should high light the first character or spelling
 * RETURNS
 *  If has inserted new candidates
 ************************************************************************************************/
MMI_BOOL mmi_pen_editor_reset_candidate_and_composition_box(single_line_input_box * candidate_box, UI_character_type * candidate_buffer, S32 num, MMI_BOOL is_highlight_first)
{
	S32 i = 0;

    gui_single_line_input_box_delete_all(candidate_box);
	
	/*insert the candidates*/
	if (num > 0)
	{
		for (; i < num; i++)
		{
			gui_single_line_input_box_insert_character(candidate_box, candidate_buffer[i]);
		}
	}
	else if(num == -1)
	{
        for (; ; i++)
		{
			if (candidate_buffer[i])
			{
				gui_single_line_input_box_insert_character(candidate_box, candidate_buffer[i]);
			}
			else
			{
				gui_single_line_input_box_insert_character(candidate_box, 0x20);
				break;
			}
		}
	}
	else
	{
		return MMI_FALSE;
	}

	/*high light the first candidate when the box is focused*/
	if (is_highlight_first == MMI_TRUE)
	{
		gui_single_line_input_box_goto_first_character(candidate_box);
	    gui_single_line_input_box_next(candidate_box);
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_prev_page
 * DESCRIPTION
 *  To get the candidates of the previous page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_candidates_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorCandidatePage > 0)
    {
        gPenEditorCandidatePage--;
        mmi_pen_editor_get_candidates_by_page(gPenEditorCandidatePage);
        gui_single_line_input_box_next_steps(mmi_pen_editor_get_candidate_box(), gPenEditorCandidateIndex);
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_show_candidate_area(
            mmi_pen_editor_get_candidate_arrow_state(),
            PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_next_page
 * DESCRIPTION
 *  To get the candidates of the next page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_candidates_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorCandidatePage++;
    if (!mmi_pen_editor_get_candidates_by_page(gPenEditorCandidatePage))
    {
        gPenEditorCandidatePage--;
        return;
    }
    gui_single_line_input_box_next_steps(mmi_pen_editor_get_candidate_box(), gPenEditorCandidateIndex);
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_show_candidate_area(mmi_pen_editor_get_candidate_arrow_state(), PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_prev
 * DESCRIPTION
 *  Goto to the previous candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_candidates_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorCandidateIndex > 0)
    {
        gPenEditorCandidateIndex--;
        gui_single_line_input_box_previous(mmi_pen_editor_get_candidate_box());
    }
    else
    {
        if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_STROKE == MMI_current_input_mode
            || INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode
            || INPUT_MODE_SM_PINYIN == MMI_current_input_mode || INPUT_MODE_SM_STROKE == MMI_current_input_mode)
        {
            if (gPenEditorCandidatePage > 0)
            {
                gPenEditorCandidatePage--;
                gPenEditorCandidateIndex = PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS - 1;
                mmi_pen_editor_get_candidates_by_page(gPenEditorCandidatePage);
                gui_single_line_input_box_goto_last_character(mmi_pen_editor_get_candidate_box());
            }
        }
    }
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_show_candidate_area(mmi_pen_editor_get_candidate_arrow_state(), PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_next
 * DESCRIPTION
 *  Goto to the next candidate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_candidates_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.35 For Candidate Index Issue */
    if ((gPenEditorCandidateIndex < PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS - 1)
        && (gPenEditorCandidateIndex < (mmi_pen_editor_get_candidate_box_text_length() / 2) - 2))
    {
        gPenEditorCandidateIndex++;
        gui_single_line_input_box_next(mmi_pen_editor_get_candidate_box());
    }
    else
    {
        if (INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_BOPOMO == MMI_current_input_mode
            || INPUT_MODE_TR_STROKE == MMI_current_input_mode
            || INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode
            || INPUT_MODE_SM_PINYIN == MMI_current_input_mode || INPUT_MODE_SM_STROKE == MMI_current_input_mode)
        {
            gPenEditorCandidatePage++;
            if (!mmi_pen_editor_get_candidates_by_page(gPenEditorCandidatePage))
            {
                gPenEditorCandidatePage--;
                return;
            }
            gPenEditorCandidateIndex = 0;
        }
    }
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_show_candidate_area(mmi_pen_editor_get_candidate_arrow_state(), PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_register_arrow_keys
 * DESCRIPTION
 *  Register functions of the arrow keys when focus on the candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_register_arrow_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_pen_editor_get_input_box_type())
    {
        case PEN_EDITOR_EMS_INPUT_BOX:
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            SetKeyHandler(mmi_pen_editor_get_candidates_prev, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_pen_editor_get_candidates_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_pen_editor_get_candidates_prev_page, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_pen_editor_get_candidates_next_page, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_candidate_is_able_to_next_page
 * DESCRIPTION
 *  Is it able to jump to the next page in the candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : yes
 *  MMI_FALSE : no
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_candidate_is_able_to_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    int num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorCandidatePage++;


#ifdef __MMI_PENPOWER_PHRASE__
    num = mmi_pen_editor_get_candidates_by_page_from_penpower(gPenEditorCandidatePage, candidate_buffer);
#else
    num = mmi_ime_get_candidates_by_page(gPenEditorCandidatePage, candidate_buffer);
#endif /* __MMI_PENPOWER_PHRASE__ */


    if (!num)
    {
        gPenEditorCandidatePage--;
        return MMI_FALSE;
    }
    else
    {
        gPenEditorCandidatePage--;
        return MMI_TRUE;
    }
}   /* end of mmi_pen_editor_candidate_is_able_to_next_page */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_candidate_is_able_to_prev_page
 * DESCRIPTION
 *  Is it able to jump to the previous page in the candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : yes
 *  MMI_FALSE : no
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_candidate_is_able_to_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorCandidatePage)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}   /* end of mmi_pen_editor_candidate_is_able_to_prev_page */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_composition_is_able_to_next
 * DESCRIPTION
 *  Is it able to jump to the next syllable in the composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : yes
 *  MMI_FALSE : no
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_composition_is_able_to_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_syllable_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_syllable_num = mmi_pen_editor_get_the_max_syllable_number();
    
    if ((g_pen_editor_composition_index < max_syllable_num - 1) &&
        g_pen_editor_syllable_table[g_pen_editor_composition_index + 1][0] != '\0')
    {
        return MMI_TRUE;
    }
    else if (g_pen_editor_composition_index == max_syllable_num - 1)
    {
        S32 num = 0;

        g_pen_editor_composition_index = 0;
        g_pen_editor_composition_page++;
        num = mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE, MMI_TRUE);
        g_pen_editor_composition_index = max_syllable_num - 1;
        g_pen_editor_composition_page--;
        mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(&g_pen_editor_key_sequence, MMI_FALSE, MMI_TRUE);
        if (num)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}   /* end of mmi_pen_editor_composition_is_able_to_next */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_composition_is_able_to_prev
 * DESCRIPTION
 *  Is it able to jump to the previous syllable in the composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : yes
 *  MMI_FALSE : no
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_composition_is_able_to_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_editor_composition_index || g_pen_editor_composition_page)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}   /* end of mmi_pen_editor_composition_is_able_to_prev */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_candidate_index
 * DESCRIPTION
 *  Reset the current index and the currect page for the candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_candidate_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.35 Temp Solution for Candidate Index Issue */
    gPenEditorCandidateIndex = 0;
    gPenEditorCandidatePage = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_composition_index
 * DESCRIPTION
 *  Reset the current index and the currect page for the composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_composition_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_composition_index = 0;
    g_pen_editor_composition_page = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_smart_latin_pre_candidate_length
 * DESCRIPTION
 *  Set smart latin pre-candidate length
 * PARAMETERS
 *  candidatelength        [IN]    The length of smart latin pre-candidate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_smart_latin_pre_candidate_length(U32 candidatelength)
{
    g_pen_editor_smart_latin_pre_candidate_length = candidatelength;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_smart_latin_pre_candidate_length
 * DESCRIPTION
 *  Get smart latin pre-candidate length
 * PARAMETERS
 *  void
 * RETURNS
 *  The smart latin pre-candidate length
 *****************************************************************************/
U32 mmi_pen_editor_get_smart_latin_pre_candidate_length(void)
{
    return g_pen_editor_smart_latin_pre_candidate_length;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_smart_latin_candidate_index
 * DESCRIPTION
 *  Get smart latin candidate index
 * PARAMETERS
 *  candidateindex        [IN]    The index of smart latin candidates
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_smart_latin_candidate_index(S32 candidateindex)
{
    g_pen_editor_smart_latin_candidate_index = candidateindex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_smart_latin_candidate_index
 * DESCRIPTION
 *  Get smart latin candidate index
 * PARAMETERS
 *  void
 * RETURNS
 *  The index of smart latin candidates
 *****************************************************************************/
S32 mmi_pen_editor_get_smart_latin_candidate_index(void)
{
    return g_pen_editor_smart_latin_candidate_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_key_sequence
 * DESCRIPTION
 *  Get the pointer to key sequence
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to key sequence
 *****************************************************************************/
mmi_pen_editor_key_sequence_struct * mmi_pen_editor_get_key_sequence(void)
{
   return &g_pen_editor_key_sequence;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_compositon_index
 * DESCRIPTION
 *  Set composition index
 * PARAMETERS
 *  composition_index     [IN]   The index of compositions
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_compositon_index(U32 composion_index)
{
    g_pen_editor_composition_index = composion_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_compositon_index
 * DESCRIPTION
 *  Get composition index
 * PARAMETERS
 *  void
 * RETURNS
 *  The index of composition
 *****************************************************************************/
U32 mmi_pen_editor_get_compositon_index(void)
{
    return g_pen_editor_composition_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_active_multitap_index
 * DESCRIPTION
 *  Set active multitap index
 * PARAMETERS
 *  index        [IN]     Active multitap index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_active_multitap_index(S32 index)
{
    g_pen_editor_active_multitap_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_candidate_page
 * DESCRIPTION
 *  Set candidate page
 * PARAMETERS
 *  page        [IN]     Candidate page to be set
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_candidate_page(S32 page)
{
    gPenEditorCandidatePage = page;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_candidate_index
 * DESCRIPTION
 *  Set candidate index
 * PARAMETERS
 *  index        [IN]     Index of candidates
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_candidate_index(S32 index)
{
    gPenEditorCandidateIndex = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_syllable_confirmed_or_not
 * DESCRIPTION
 *  Set candidate index
 * PARAMETERS
 *  confirmed        [IN]     Syllable has confirmed or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_syllable_confirmed_or_not(MMI_BOOL confirmed)
{
    g_pen_editor_smart_bmpf_pinyin_syllable_confirmed = confirmed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_the_max_syllable_number
 * DESCRIPTION
 *  Get the max number of syllable in one page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_pen_editor_get_the_max_syllable_number(void)
{
    return PEN_EDITOR_MAX_SYLLABLE_CANDIDATE_SIZE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 



