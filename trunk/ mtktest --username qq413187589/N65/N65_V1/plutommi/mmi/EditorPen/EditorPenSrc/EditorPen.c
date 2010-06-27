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
 * EditorPen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Pen Function in Editor
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
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*  Include: MMI header file */
#include "MMI_features.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "EditorPenGprot.h"
#include "EditorPenProt.h"


#ifdef UI_SMALL_PIN_EDITOR_SCREEN
#include "HistoryGprot.h"
#endif


/***************************************************************************** 
* Define
*****************************************************************************/
/* This compile option is used to save the stroke data to the file */
//#defined __MMI_HAND_WRITING_GET_STROKES__

#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
/* this is used to decide the timer's timeout for word prediction in editor */
#define WORD_PREDICTION_TIMEOUT 2000
#endif

/* We need at least 3 layers for extra handwriting layer.
   MT6223 only has 2 layers. We need to dynamically switch 
   to stroke layer on writing a char */

#if defined(GDI_2_LAYERS)
#define MMI_PEN_EDITOR_ON_2_LAYER
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* The point used to draw the stroke */
static mmi_pen_point_struct gPenEditorPreviousPoint;

/* The color of the stroke */
static color gPenEditorStrokeColor = {0, 0, 0, 100};

/* The text buffer for the candidates */
static UI_character_type gPenEditorCandidateBuffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];

/* Which kind of controls are in the category */
static mmi_pen_editor_control_set_struct gPenEditorControlSet;

/* The Active Control to process Pen Event (Activated by Pen Pown) */
static mmi_pen_editor_control_type_enum gPenEditorActiveControl;

#ifdef MMI_PEN_EDITOR_ON_2_LAYER 

/* Pointer to the GDI handler, used by Draw Manager */
static gdi_handle gPenEditorStrokeHandle = GDI_ERROR_HANDLE;

/* Original layer 1 before handwriting is started */
static gdi_handle gPenEditorGDIOriginalHandle1;

/* Original layer 2 before handwriting is started */
static gdi_handle gPenEditorGDIOriginalHandle2;

/* Set blt layer to gPenEditorStrokeHandle during handwriting is progressing */
static MMI_BOOL gPenEditorBltLayerSwitched = MMI_FALSE;

#else /* MMI_PEN_EDITOR_ON_2_LAYER */

/* Pointer to the GDI handler, used by Draw Manager */
static gdi_handle *gPenEditorGDIHandler = NULL;

#endif /* MMI_PEN_EDITOR_ON_2_LAYER */

//Layer Buffer for Stroke
//static U32 gPenEditorStrokeGDIBuffer[(GDI_LCD_WIDTH *
//              GDI_LCD_HEIGHT * (GDI_MAINLCD_BIT_PER_PIXEL>>3) + 3) / 4];
static U8 *gPenEditorStrokeGDIBuffer = NULL;

/* Used for Multitap (need to revise) */
static multitap_input *gPenEditorMultitapInput;

/* Used for Multitap (need to revise) */
static MMI_BOOL gPenEditorMultitapInputState = MMI_FALSE;

/* The First Stroke or not */
static MMI_BOOL gPenEditorFirstStroke = MMI_TRUE;

/* Display the virtual Keyboard or not */
static MMI_BOOL gPenEditorShowVK = MMI_TRUE;

/* LSK function from Application */
static void (*gPenEditorLSKfunction) (void);

/* To Store the text of LSK */
static UI_string_type gPenEditorLSKText;

/* The valid characters for INPUT_TYPE_PHONE_NUMBER */
static const UI_character_type gPenEditorPhoneNumberValidCharacters[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', 'p', 'w', '#', '*', '\0' };
/* The valid characters for INPUT_TYPE_KEYPAD_NUMERIC */
static const UI_character_type gPenEditorKeyPadNumbericValidCharacters[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '#', '*', '\0' };
/* The valid characters for INPUT_TYPE_EXT_SIM_NUMERIC */
static const UI_character_type gPenEditorPhoneNumberSIMValidCharacters[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '#', '*', '\0' };
/* The valid characters for INPUT_TYPE_DECIMAL_NUMERIC */
static const UI_character_type gPenEditorDecimalNumericValidCharacters[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '\0' };
/* The valid characters for INPUT_TYPE_SIGNED_DECIMAL_NUMERIC */
static const UI_character_type gPenEditorSignedDecimalNumericValidCharacters[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-', '\0' };


/* To store the height of list menu for in line editor */
static S32 gPenEditorListMenuHeight = 0;

/* The pen speed from PhnsetGetHandwritingSpeed */
static PHNSET_HANDWRITING_SPEED_ENUM gPenEditorHWSpeed = PHNSET_HANDWRITING_MEDIUM;

static multiline_inputbox_category_history gPenEditorInlineEditHistory;

static const S32 gPenEditorHWSpeedSet[3][2] = 
{
    {750, 2000},
    {1000, 3000},
    {1250, 4000}
};

/* The Filler for candidate input box */
static UI_filled_area candidate_inputbox_BG_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_ROUNDED_BORDER | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {192, 240, 248, 100},
    {0, 0, 0, 0},
    {64, 96, 176, 100},
    {255, 0, 0, 100},
    0
};

/* The theme for candidate input box */
static UI_single_line_input_box_theme candidate_singleline_inputbox_theme = 
{
    &candidate_inputbox_BG_filler,
    &candidate_inputbox_BG_filler,
    &candidate_inputbox_BG_filler,
    {0, 0, 0, 100},
    {128, 128, 128, 100},
    {0, 0, 0, 100},
    {255, 255, 255, 100},
    {51, 88, 171, 100},
    {255, 0, 0, 100},
    &MMI_large_font,
    1,
    UI_SINGLE_LINE_INPUT_BOX_CENTER_Y,
    '*'
};

/* W06.11 Do not lock GDI buffer when process wgui_general_pen_up_hdlr */
static MMI_BOOL g_pen_editor_hold_confirm = MMI_FALSE;

static MMI_BOOL g_pen_editor_disable_keypad = MMI_FALSE;

static UI_character_type g_pen_editor_composition_buffer[PEN_EDITOR_MAX_COMPOSITION_SIZE];

static S32 g_pen_editor_candidate_x;

static S32 g_pen_editor_active_block = 0;

static MMI_BOOL g_pen_editor_resize_by_vk = MMI_FALSE;

/* The candidate is in selection state or not */
static MMI_BOOL gPenEditorSelectCandidate = MMI_FALSE;

static mmi_pen_editor_candidate_state_struct g_pen_editor_composition_state;

/* The single line input box for the composition */
static single_line_input_box gPenEditorCompositionInputBox;

/* The single line input box for the candidates */
static single_line_input_box gPenEditorCandidateInputBox;

static mmi_pen_editor_candidate_state_struct g_pen_editor_candidate_state;

#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
static MMI_BOOL gPenEditorOnlyRedrawInputBox = MMI_FALSE;
#endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */

/* Enable Hand Writing or not */
static MMI_BOOL gPenEditorEnableHandWriting = MMI_FALSE;

/* Which kind of input box */
static mmi_pen_editor_input_box_type_enum gPenEditorInputBoxType = PEN_EDITOR_NONE_INPUT_BOX;

static MMI_BOOL g_stroke_up_timer_is_on = MMI_FALSE;

static MMI_BOOL g_is_from_word_prediction = MMI_FALSE;

static MMI_BOOL g_not_resize_input_box = MMI_FALSE;

static S32 g_input_box_changed_height = -1;
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_pen_editor_handwriting_direct_input(void);
static void mmi_pen_editor_setup_create_layer_and_register_pen_handler(mmi_pen_handwriting_area_struct *stroke_area,
                                                                       mmi_pen_handwriting_area_struct *ext_stroke,
                                                                       U16 input_type_only);
static void mmi_pen_editor_setup_create_candidate_and_composition_box(void);
static void mmi_pen_editor_setup_virtual_keyboard(U16 input_type_only);
#ifdef MMI_PEN_EDITOR_ON_2_LAYER
static void mmi_pen_editor_backup_and_set_blt_layer(void);
static void mmi_pen_editor_restore_blt_layer(void);
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */



/***************************************************************************** 
* Global Variable
*****************************************************************************/
/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern const sIMEModeDetails mtk_gIMEModeArray[];
extern const sIMEModeDetails mtk_gIMEQSearchModeArray[];
/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_vk_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_pen_editor_set_vk_resize(MMI_BOOL v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_resize_by_vk = v;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_compute_candidate_input_box_height
 * DESCRIPTION
 *  To compute the height of the candidate input box
 * PARAMETERS
 *  void
 * RETURNS
 *  The height of the candidate input box
 *****************************************************************************/
S32 mmi_pen_editor_compute_candidate_input_box_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    height = Get_CharHeightOfAllLang(candidate_singleline_inputbox_theme.text_font->size) + 2;
    if (height < MMI_multitap_height)
    {
        height = MMI_multitap_height;
    }
    return height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_left_soft_key
 * DESCRIPTION
 *  Change Left Soft Key text according to previous
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_left_soft_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_left_softkey_label_for_IME(gPenEditorLSKText);
    set_left_softkey_icon(NULL);
    redraw_left_softkey();
    register_left_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_left_soft_key_select
 * DESCRIPTION
 *  Change Left Soft Key text to STR_GLOBAL_SELECT for selecting candidate purpose
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_left_soft_key_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_left_softkey_label_for_IME((UI_string_type) get_string(STR_GLOBAL_SELECT));
    set_left_softkey_icon(NULL);
    redraw_left_softkey();
    register_left_softkey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_right_soft_key_inline_text
 * DESCRIPTION
 *  Set Right Soft Key for in-line text control according its status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_editor_set_right_soft_key_inline_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_single_line_input_box_get_text_length(&MMI_inline_singleline_inputbox) > 0)
    {
        set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
        set_right_softkey_icon(NULL);
        register_right_softkey_handler();
        redraw_right_softkey();
        set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
        set_right_softkey_function(handle_inline_text_edit_right_softkey_down, KEY_EVENT_DOWN);
        set_right_softkey_function(handle_inline_text_edit_right_softkey_long_press, KEY_EVENT_LONG_PRESS);
    }
    else
    {
        if (wgui_inline_list_menu_changed)
        {
            wgui_inline_text_edit_set_RSK_BACK_function();
            /* W06.11 Set RSK as handle_inline_text_edit_right_softkey_up when buffer is empty */
            set_right_softkey_function(handle_inline_text_edit_right_softkey_up, KEY_EVENT_UP);
        }
        else
        {
            set_right_softkey_label(inline_text_edit_RSK_label_string);
            set_right_softkey_icon(inline_text_edit_RSK_label_icon);
            register_right_softkey_handler();
            redraw_right_softkey();
            set_right_softkey_function(register_inline_text_edit_handle_right_softkey_up, KEY_EVENT_UP);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_right_softkey
 * DESCRIPTION
 *  Set Right Soft Key according to the state
 * PARAMETERS
 *  rsk_type        [IN]        PEN_EDITOR_RSK_BY_STATE : The candidate box is on and set RSK to CLEAR if the candidate is in input control
 *                              PEN_EDITOR_RSK_BACK : Set RSK to STR_GLOBAL_BACK
 *                              PEN_EDITOR_RSK_CLEAR : Set RSK to STR_GLOBAL_CLEAR
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_right_softkey(mmi_pen_editor_rsk_type_enum rsk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsk_type)
    {
        case PEN_EDITOR_RSK_BY_STATE:
            if (get_multitap_state())
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
            }
            else
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
            }
            break;

        case PEN_EDITOR_RSK_BACK:
            set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
            break;

        case PEN_EDITOR_RSK_CLEAR:
            set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
            break;

        default:
            MMI_DBG_ASSERT(0);
    }
    set_right_softkey_icon(NULL);
    redraw_right_softkey();
    register_right_softkey_handler();
    /* W06.10 Fix Right Soft Key Issue */
    set_right_softkey_function(mmi_pen_editor_right_soft_key_handler, KEY_EVENT_UP);
    set_right_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
    set_right_softkey_function(UI_dummy_function, KEY_LONG_PRESS);
}

#if defined(__MMI_HAND_WRITING_GET_STROKES__)


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_save_stroke_to_file
 * DESCRIPTION
 *  Save the stroke data to the file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_editor_save_stroke_to_file(void)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        FS_HANDLE stroke_out;
        U32 write_len;
        int i = 0;
        mmi_pen_point_struct point;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        stroke_out = FS_Open(L"Stroke_Out.str", FS_CREATE | FS_READ_WRITE);
        if (stroke_out <= 0)
        {
            MMI_ASSERT(0);
        }

        FS_Seek(stroke_out, 0, FS_FILE_END);
        for (i = 0; i < PEN_EDITOR_STROKE_BUFFER_SIZE; i++)
        {
            mmi_pen_editor_get_point_by_index(i, &point);
            FS_Write(stroke_out, &(point.x), sizeof(S16), (U32*) & write_len);
            FS_Write(stroke_out, &(point.y), sizeof(S16), (U32*) & write_len);
        #if defined(__MMI_HANWANG__)
            if ((-1) == point.x && (-1) == point.y)
            {
                break;
            }
        #elif defined(__MMI_PENPOWER__)
            if ((-1) == point.x && (0) == point.y)
            {
                break;
            }
        #else 
            if ((-1) == point.x && (-1) == point.y)
            {
                break;
            }
        #endif 
        }
        FS_Close(stroke_out);
    }
#else /* defined(__MTK_TARGET__) */ 
    {
        FILE *stroke_out;
        int i = 0;
        mmi_pen_point_struct point;

        if ((stroke_out = fopen("Stroke_Out.str", "a+")) == NULL)
        {
            fprintf(stderr, "Cannot open output file.\n");
        }

        fseek(stroke_out, 0, SEEK_END);
        for (i = 0; i < PEN_EDITOR_STROKE_BUFFER_SIZE; i++)
        {
            mmi_pen_editor_get_point_by_index(i, &point);
            fwrite(&(point.x), sizeof(S16), 1, stroke_out);
            fwrite(&(point.y), sizeof(S16), 1, stroke_out);
            if ((-1) == point.x && (-1) == point.y)
            {
                break;
            }
        }
        fclose(stroke_out);
    }
#endif /* defined(__MTK_TARGET__) */ 
}
#endif /* defined(__MMI_HAND_WRITING_GET_STROKES__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_disable_input
 * DESCRIPTION
 *  To Disable the way to input characters at the beginning
 * PARAMETERS
 *  disable_input_flag      [IN]        PEN_EDITOR_DISABLE_HANDWRITNG : Disable Handwriting
 *                                      PEN_EDITOR_DISABLE_VIRTUAL_KEYBOARD : Disable Virtual Keyboard
 *                                      PEN_EDITOR_DISABLE_KEYPAD : Not Implemented
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_disable_input(U32 disable_input_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (disable_input_flag & PEN_EDITOR_DISABLE_HANDWRITNG)
    {
        mmi_pen_editor_set_handwriting_disabled_or_not(MMI_TRUE);
    }
    if (disable_input_flag & PEN_EDITOR_DISABLE_VIRTUAL_KEYBOARD)
    {
        mmi_pen_editor_set_vk_disabled_or_not(MMI_TRUE);
    }
    if (disable_input_flag & PEN_EDITOR_DISABLE_KEYPAD)
    {
        g_pen_editor_disable_keypad = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_check_phrase
 * DESCRIPTION
 *  Check the character is able to be phrase-completed or not. If yes, do the related action
 * PARAMETERS
 *  ch      [IN]        The character to be checked
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_check_phrase(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 0x4e00 && ch <= 0x9fff)
    {
        /* W05.35 Temp Solution for Candidate Index Issue */
        mmi_pen_editor_reset_candidate_index();
        if (g_pen_editor_composition_state.candidate_state != PEN_EDITOR_CANDIDATE_OFF)
        {
            int change_height = gPenEditorCompositionInputBox.height;

            g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;

            if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type)
            {
                mmi_pen_editor_hide_composition_area(); 
            }
            mmi_pen_editor_resize_content_area(change_height);
            mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
        }
        if (mmi_pen_editor_get_candidates_by_phrase(ch))
        {
            
            /* Temp Solution for LSK Text Update */
	        if (g_is_from_word_prediction && !gPenEditorSelectCandidate)
                mmi_pen_editor_store_LSK_Text();

            gPenEditorSelectCandidate = MMI_TRUE;

            mmi_pen_editor_set_left_soft_key_select();
            set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
            set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
            mmi_pen_editor_register_arrow_keys();
            if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
            {
                if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
                {
                    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
                }
            }
            else
            {
                if (gPenEditorCandidateInputBox.y >= (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM))
                {
                    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
                }
            }
            mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BY_STATE);
        }
        else
        {
            gui_cancel_timer(mmi_pen_editor_confirm_selection);
            gPenEditorSelectCandidate = MMI_TRUE;
            mmi_pen_editor_confirm_selection();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_hide_candidate_area
 * DESCRIPTION
 *  Clear the area of the candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_hide_candidate_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gdi_layer_lock_frame_buffer();
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(
            0,
            gPenEditorCandidateInputBox.y - 1,
            UI_device_width,
            gPenEditorCandidateInputBox.y + gPenEditorCandidateInputBox.height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_fill_rectangle(
            0,
            gPenEditorCandidateInputBox.y - 1,
            UI_device_width,
            gPenEditorCandidateInputBox.y + gPenEditorCandidateInputBox.height - 1,
            current_MMI_theme->general_background_filler->c);
    }
    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(
        0,
        gPenEditorCandidateInputBox.y,
        UI_device_width - 1,
        gPenEditorCandidateInputBox.y + gPenEditorCandidateInputBox.height - 1);
}   /* end of mmi_pen_editor_hide_candidate_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_draw_arrow
 * DESCRIPTION
 *  Darw the arrows for the composition box or the candidate box
 * PARAMETERS
 *  arrow_direction     [IN]        The direction of the arrow. Now we only support PEN_EDITOR_ARROW_DIRECTION_RIGHT and PEN_EDITOR_ARROW_DIRECTION_LEFT
 *  arrow_state         [IN]        The state of the arrow. PEN_EDITOR_ARROW_DISABLE, PEN_EDITOR_ARROW_PRESS_DOWN, and PEN_EDITOR_ARROW_PRESS_UP
 *  arrow_type          [IN]        The arrow is for the composition box and the candidate box. PEN_EDITOR_ARROW_FOR_CANDIDATE and PEN_EDITOR_ARROW_FOR_COMPOSITION
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_draw_arrow(
        mmi_pen_editor_arrow_direction_enum arrow_direction,
        mmi_pen_editor_arrow_state_enum arrow_state,
        mmi_pen_editor_arrow_type_enum arrow_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color arrow_color;
    S32 x = 0, y = 0, width = 0, height = 0;
    S32 input_box_x = 0, input_box_width = 0, input_box_grid_width = 0;
    U8 direction = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_ARROW_FOR_CANDIDATE == arrow_type)
    {
        input_box_x = gPenEditorCandidateInputBox.x;
        input_box_width = gPenEditorCandidateInputBox.width;
        input_box_grid_width = gPenEditorCandidateInputBox.grid_width;
        y = gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3) + 1;
        width = gPenEditorCandidateInputBox.grid_width >> 1;
        height = ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2;
    }
    else if (PEN_EDITOR_ARROW_FOR_COMPOSITION == arrow_type)
    {
        input_box_x = gPenEditorCompositionInputBox.x;
        input_box_width = gPenEditorCompositionInputBox.width;
        input_box_grid_width = gPenEditorCompositionInputBox.grid_width;
        y = gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3) + 1;
        width = gPenEditorCompositionInputBox.grid_width >> 1;
        height = ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2;
    }
    if (PEN_EDITOR_ARROW_DISABLE == arrow_state)
    {
        arrow_color = gui_color(200, 200, 200);
    }
    else
    {
        arrow_color = gui_color(0, 102, 204);
    }

    if (PEN_EDITOR_ARROW_DIRECTION_RIGHT == arrow_direction)
    {
        x = input_box_x + input_box_width + (input_box_grid_width >> 2);
        direction = 1;
        if (PEN_EDITOR_ARROW_DISABLE == arrow_state || PEN_EDITOR_ARROW_PRESS_UP == arrow_state)
        {
        }
        else if (PEN_EDITOR_ARROW_PRESS_DOWN == arrow_state)
        {
            x++;
            y++;
        }
    }
    else if (PEN_EDITOR_ARROW_DIRECTION_LEFT == arrow_direction)
    {
        x = input_box_x - (((input_box_grid_width << 1) + input_box_grid_width) >> 2) - 2;
        direction = 0;
        if (PEN_EDITOR_ARROW_DISABLE == arrow_state || PEN_EDITOR_ARROW_PRESS_UP == arrow_state)
        {
        }
        else if (PEN_EDITOR_ARROW_PRESS_DOWN == arrow_state)
        {
            x--;
            y++;
        }
    }
    draw_resizeable_arrow(x, y, direction, arrow_color, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_show_candidate_area
 * DESCRIPTION
 *  Draw the candidate box according to its state
 * PARAMETERS
 *  arrow_enable        [IN]        Draw the arrows or not. MMI_TRUE : yes MMI_FALSE : no
 *  candiate_state      [IN]        PEN_EDITOR_CANDIDATE_ON_AND_FOCUS : Focus on the candidate box
 *                                  PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS : Not focus on the candidate box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_show_candidate_area(MMI_BOOL arrow_enable, mmi_pen_editor_candidate_state_enum candiate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resize_width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_hide_candidate_area();
    if (PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == candiate_state)
    {
        gPenEditorCandidateInputBox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    }
    else if (PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS == candiate_state)
    {
      // 07.33 touch with keypad also needs cursor draw in candidate box.
      //  gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    }

    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT;

    if (!arrow_enable)
    {
        resize_width = gPenEditorCandidateInputBox.grid_width * PEN_EDITOR_CANDIDATE_SIZE + 1;
        gui_resize_single_line_input_box(
            &gPenEditorCandidateInputBox,
            resize_width,
            gPenEditorCandidateInputBox.height);
        gui_move_single_line_input_box(
            &gPenEditorCandidateInputBox,
            (UI_device_width - resize_width) / 2,
            gPenEditorCandidateInputBox.y);
        g_pen_editor_candidate_state.arrow_enable = MMI_FALSE;
        g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_DISABLE;
    }
    else
    {
        g_pen_editor_candidate_state.arrow_enable = MMI_TRUE;
        g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        if (mmi_pen_editor_candidate_is_able_to_next_page() &&
            !(UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW & gPenEditorCandidateInputBox.flags))
        {
            g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
        }
        if (mmi_pen_editor_candidate_is_able_to_prev_page() &&
            !(UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW & gPenEditorCandidateInputBox.flags))
        {
            g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
        }

        resize_width = gPenEditorCandidateInputBox.grid_width * PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS + 1;
        gui_resize_single_line_input_box(
            &gPenEditorCandidateInputBox,
            resize_width,
            gPenEditorCandidateInputBox.height);
        gui_move_single_line_input_box(
            &gPenEditorCandidateInputBox,
            (UI_device_width - resize_width) / 2,
            gPenEditorCandidateInputBox.y);
        mmi_pen_editor_draw_arrow(
            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
            g_pen_editor_candidate_state.right_arrow_state,
            PEN_EDITOR_ARROW_FOR_CANDIDATE);
        mmi_pen_editor_draw_arrow(
            PEN_EDITOR_ARROW_DIRECTION_LEFT,
            g_pen_editor_candidate_state.left_arrow_state,
            PEN_EDITOR_ARROW_FOR_CANDIDATE);
    }
    gui_show_single_line_input_box(&gPenEditorCandidateInputBox);
}   /* end of mmi_pen_editor_show_candidate_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_hide_composition_area
 * DESCRIPTION
 *  Clear the area of the composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_hide_composition_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gdi_layer_lock_frame_buffer();
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(
            0,
            gPenEditorCompositionInputBox.y - 1,
            UI_device_width,
            gPenEditorCompositionInputBox.y + gPenEditorCompositionInputBox.height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_fill_rectangle(
            0,
            gPenEditorCompositionInputBox.y - 1,
            UI_device_width,
            gPenEditorCompositionInputBox.y + gPenEditorCompositionInputBox.height - 1,
            current_MMI_theme->general_background_filler->c);
    }
    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(
        0,
        gPenEditorCompositionInputBox.y,
        UI_device_width - 1,
        gPenEditorCompositionInputBox.y + gPenEditorCompositionInputBox.height - 1);
}   /* end of mmi_pen_editor_hide_composition_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_show_composition_area
 * DESCRIPTION
 *  Draw the composition box according to its state
 * PARAMETERS
 *  arrow_enable        [IN]        Draw the arrows or not. MMI_TRUE : yes MMI_FALSE : no
 *  candiate_state      [IN]        PEN_EDITOR_CANDIDATE_ON_AND_FOCUS : Focus on the composition box
 *                                  PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS : Not focus on the composition box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_show_composition_area(MMI_BOOL arrow_enable, mmi_pen_editor_candidate_state_enum candiate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_hide_composition_area();
    gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
    gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT;
    if (PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == candiate_state)
    {
        gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
    }
    else if (PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS == candiate_state)
    {
        gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
        gPenEditorCompositionInputBox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        gPenEditorCompositionInputBox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
        gPenEditorCompositionInputBox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT;
        gPenEditorCompositionInputBox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }

    if (!arrow_enable)
    {
        gui_resize_single_line_input_box(
            &gPenEditorCompositionInputBox,
            gPenEditorCompositionInputBox.grid_width * PEN_EDITOR_CANDIDATE_SIZE,
            gPenEditorCompositionInputBox.height);
        gui_move_single_line_input_box(
            &gPenEditorCompositionInputBox,
            MMI_multitap_x,
            gPenEditorCompositionInputBox.y);
        g_pen_editor_composition_state.arrow_enable = MMI_FALSE;
        g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_DISABLE;
    }
    else
    {
        g_pen_editor_composition_state.arrow_enable = MMI_TRUE;
        g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_DISABLE;
        if (mmi_pen_editor_composition_is_able_to_next() && PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == candiate_state)
        {
            g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
        }
        if (mmi_pen_editor_composition_is_able_to_prev() && PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == candiate_state)
        {
            g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
        }
        gui_resize_single_line_input_box(
            &gPenEditorCompositionInputBox,
            gPenEditorCompositionInputBox.grid_width * PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS,
            gPenEditorCompositionInputBox.height);
        gui_move_single_line_input_box(
            &gPenEditorCompositionInputBox,
            MMI_multitap_x + gPenEditorCompositionInputBox.grid_width,
            gPenEditorCompositionInputBox.y);
        mmi_pen_editor_draw_arrow(
            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
            g_pen_editor_composition_state.right_arrow_state,
            PEN_EDITOR_ARROW_FOR_COMPOSITION);
        mmi_pen_editor_draw_arrow(
            PEN_EDITOR_ARROW_DIRECTION_LEFT,
            g_pen_editor_composition_state.left_arrow_state,
            PEN_EDITOR_ARROW_FOR_COMPOSITION);
    }
    gui_show_single_line_input_box(&gPenEditorCompositionInputBox);
}   /* end of mmi_pen_editor_show_composition_area */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_stroke_down_handler
 * DESCRIPTION
 *  When receiving the stroke down event, do the related action according to the current situation
 * PARAMETERS
 *  pos     [IN]        The position of the stroke down event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height;

    /*----------------------------------------------------------------*/
    /* Local Variables Initializing                                   */
    /*----------------------------------------------------------------*/
    changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
    {
        mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
        mmi_pen_editor_smart_latin_confirm_select();
        mmi_pen_editor_set_left_soft_key();
    }
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif
    if (g_pen_editor_composition_state.candidate_state != PEN_EDITOR_CANDIDATE_OFF)
    {
        int change_height = 0;

        g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
        change_height += gPenEditorCompositionInputBox.height;
        mmi_pen_editor_resize_content_area(change_height);
        mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
    }

#if !defined(MMI_PEN_EDITOR_ON_2_LAYER)
    /* create new layer for stroke through Draw Manager// */
    if (gPenEditorGDIHandler == NULL || *gPenEditorGDIHandler == GDI_ERROR_HANDLE)
    {
        gPenEditorStrokeGDIBuffer = (U8*) mmi_frm_scrmem_alloc(handwriting_stroke_layer_mem);
        MMI_ASSERT(gPenEditorStrokeGDIBuffer);
        if (GDI_LAYER_SUCCEED != dm_create_layer_using_outside_memory(
                                    0,
                                    0,
                                    UI_device_width,
                                    UI_device_height,
                                    &gPenEditorGDIHandler,
                                    (U8*) gPenEditorStrokeGDIBuffer,
                                    handwriting_stroke_layer_mem,
                                    DM_LAYER_TOP))
        {
            MMI_ASSERT(0);
        }
        gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
#endif /* !defined(MMI_PEN_EDITOR_ON_2_LAYER) */


    /* W05.47 If Chinese Symbol Keyboard, set to PinYin or Zhuyin Virtual Keyboard */
    /* W06.08 Avoid changing handwriting area when stroke down */
    //if (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL==MMI_virtual_keyboard.lang_type)
    //{
    //   mmi_pen_editor_vk_symbol_picker();
    //}

    /* If the state requires confirm, confirm it directly in this situation// */
    if (gPenEditorSelectCandidate && (gPenEditorCandidateInputBox.y >= (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM)))
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        gPenEditorShowVK = MMI_FALSE;
        mmi_pen_editor_confirm_selection();
        mmi_pen_editor_hide_candidate_area();
    }

    /* Clear Virtual Keyboard Area only at the first stroke */
    if (gPenEditorFirstStroke)
    {
        gPenEditorFirstStroke = MMI_FALSE;
        /* Clear Virtual Keyboard Text */
        if (mmi_pen_editor_get_vk_text_string_length() > 0 || gPenEditorSelectCandidate)
        {
            mmi_pen_editor_set_left_soft_key();
            switch (gPenEditorInputBoxType)
            {
                case PEN_EDITOR_EMS_INPUT_BOX:
                    register_EMS_inputbox_keys();
                    break;
                case PEN_EDITOR_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                    register_multiline_inputbox_keys();
                    if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                    {
                        cat201_register_key_func();
                    }
                    break;
                default:
                    break;
            }
            mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
            wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_FALSE);
        }

        if (gPenEditorShowVK)
        {
            mmi_pen_editor_hide_virtual_keyboard_area();
        }
    }

    /* W05.44 Change the Input Control Height when the VK is not Tray Type */
    if ((PEN_EDITOR_VK_ON == mmi_pen_editor_get_vk_state()) &&
        !(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type ||
          GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type ||
          GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type ||
          GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type))
    {
        /* Resize the content area for candidate input box if needed// */
        changed_height = MMI_virtual_keyboard.height;
        if (!mmi_pen_editor_is_there_vk_candidate_box())
        {
            changed_height -= gPenEditorCandidateInputBox.height;
        }
        if (gPenEditorShowVK)
        {
	    if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType && mmi_pen_editor_is_there_vk_candidate_box())
	        mmi_pen_editor_hide_candidate_area();
            if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
            {
                mmi_pen_editor_resize_content_area(changed_height);
            }
            gui_move_single_line_input_box(
                &gPenEditorCandidateInputBox,
                gPenEditorCandidateInputBox.x,
                (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM));
        }
    }
    gPenEditorShowVK = MMI_TRUE;
    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
    gPenEditorPreviousPoint.x = pos.x;
    gPenEditorPreviousPoint.y = pos.y;

#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif

#ifdef MMI_PEN_EDITOR_ON_2_LAYER
    /* Create new stroke layer after editor/virtual keyboard is resized */
    mmi_pen_editor_backup_and_set_blt_layer();
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_stroke_move_handler
 * DESCRIPTION
 *  Draw the stroke when moving the pen in the stroke mode
 * PARAMETERS
 *  pos     [IN]        The position of the stroke move event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    gdi_layer_lock_frame_buffer();
#ifdef MMI_PEN_EDITOR_ON_2_LAYER     
    gdi_layer_push_and_set_active(gPenEditorStrokeHandle);
#else
    if (gPenEditorGDIHandler != NULL)
    {	
    gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
    }	
#endif
    gdi_layer_push_clip();

#if 0
// Huyanwei Del it 
    /* Draw the point of the stroke */
    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y, pos.x, pos.y, gPenEditorStrokeColor);
    gui_line(gPenEditorPreviousPoint.x + 1, gPenEditorPreviousPoint.y, pos.x + 1, pos.y, gPenEditorStrokeColor);
    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y + 1, pos.x, pos.y + 1, gPenEditorStrokeColor);
    gui_line(gPenEditorPreviousPoint.x - 1, gPenEditorPreviousPoint.y, pos.x - 1, pos.y, gPenEditorStrokeColor);
    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y - 1, pos.x, pos.y - 1, gPenEditorStrokeColor);
#else
	#if !defined( LANG_TH_HANDWRITE_SUPPORT)
		// Huyanwei Modify It
            if(MMI_virtual_keyboard.lang_type <= GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL) //sc.wu remove handwriting for multilanguage
	#else
		#if defined(LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT)
                  if((MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_THAI) || (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL) || (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_ENGLISH) || (MMI_virtual_keyboard.lang_type == GUI_VIRTUAL_KEYBOARD_ENGLISH_UPPERCASE))
   		#else
                 if((MMI_virtual_keyboard.lang_type <= GUI_VIRTUAL_KEYBOARD_THAI_SYMBOL) )
		#endif				
	#endif
	{
	    /* Draw the point of the stroke */
	    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y, pos.x, pos.y, gPenEditorStrokeColor);
	    gui_line(gPenEditorPreviousPoint.x + 1, gPenEditorPreviousPoint.y, pos.x + 1, pos.y, gPenEditorStrokeColor);
	    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y + 1, pos.x, pos.y + 1, gPenEditorStrokeColor);
	    gui_line(gPenEditorPreviousPoint.x - 1, gPenEditorPreviousPoint.y, pos.x - 1, pos.y, gPenEditorStrokeColor);
	    gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y - 1, pos.x, pos.y - 1, gPenEditorStrokeColor);
	}
#endif

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(
        PEN_MIN(gPenEditorPreviousPoint.x, pos.x) - 1,
        PEN_MIN(gPenEditorPreviousPoint.y, pos.y) - 1,
        PEN_MAX(gPenEditorPreviousPoint.x, pos.x) + 1,
        PEN_MAX(gPenEditorPreviousPoint.y, pos.y) + 1);

    gPenEditorPreviousPoint.x = pos.x;
    gPenEditorPreviousPoint.y = pos.y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_stroke_up_handler
 * DESCRIPTION
 *  Draw the last point of the stroke and start the timer to check this is the last stroke or not
 * PARAMETERS
 *  pos     [IN]        The position of the stroke up event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    mmi_pen_editor_stroke_move_handler(pos);
    gPenEditorPreviousPoint.x = -1;
    gPenEditorPreviousPoint.y = -1;
    gui_cancel_timer(mmi_pen_editor_stroke_up_timer_handler);
    /* The end of the stroke, if no more stroke in the period, the end of the character */
    gui_start_timer(PEN_EDITOR_CHARACTER_END_PERIOD, mmi_pen_editor_stroke_up_timer_handler);
    g_stroke_up_timer_is_on = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_stroke_up_timer_handler
 * DESCRIPTION
 *  If no more stroke, then pass the strokes to the handwiritng module to get candidates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_stroke_up_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL has_unfinished_stroke = MMI_FALSE;
    int num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	g_stroke_up_timer_is_on = MMI_FALSE;

    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    mmi_pen_peek_stroke_state(&has_unfinished_stroke);
    if (!has_unfinished_stroke)
    {
        /* The end of the character, pass the stroke data for hand writing recognization */
        mmi_pen_end_strokes_of_character();
    #if defined(__MMI_HAND_WRITING_GET_STROKES__)
        mmi_pen_editor_save_stroke_to_file();
    #endif 
    
    #ifdef MMI_PEN_EDITOR_ON_2_LAYER
        mmi_pen_editor_restore_blt_layer();
    #else /* MMI_PEN_EDITOR_ON_2_LAYER */
	if (gPenEditorGDIHandler != NULL)
	{	
            gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
	}	
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    #endif /* MMI_PEN_EDITOR_ON_2_LAYER */
        gPenEditorFirstStroke = MMI_TRUE;
        
        gdi_layer_lock_frame_buffer();
        num = mmi_pen_editor_get_candidates_from_hand_writing();
        gdi_layer_unlock_frame_buffer();
        
        /* W05.36 Check the Candidates List, if empty, just clear stroke */
        if (num == 0)
        {
            int changed_height = 0;

            mmi_pen_begin_strokes_of_character();
            gdi_layer_lock_frame_buffer();
            mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
            if (gPenEditorShowVK && (gPenEditorCandidateInputBox.y >= (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM)))
            {
                /* W05.47 Change the Input Control Height when the VK is not Tray Type */
                if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                      || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                      || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                      || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type))
                {
                    changed_height = gPenEditorCandidateInputBox.height;
                    if (mmi_pen_editor_is_there_vk_candidate_box())
                    {
                        changed_height -= gPenEditorCandidateInputBox.height;
                    }
                    changed_height -= MMI_virtual_keyboard.height;
                    if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
                    {
                        mmi_pen_editor_resize_content_area(changed_height);
                    }
                }
            }

            if (gPenEditorShowVK)
            {
                mmi_pen_editor_clear_and_show_virtual_keyboard_area();
            }

            if (mmi_pen_editor_is_there_vk_candidate_box())
            {
                if (gPenEditorShowVK)
                {
                    gui_move_single_line_input_box(
                        &gPenEditorCandidateInputBox,
                        gPenEditorCandidateInputBox.x,
                        MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                }
                mmi_pen_editor_hide_candidate_area();
            }
            gdi_layer_unlock_frame_buffer();
            gdi_lcd_repaint_all();
            return;
        }

        /* According different input box, do different actions */
        mmi_pen_editor_input_character(gPenEditorCandidateBuffer[0], MMI_TRUE);
        /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
        mmi_pen_editor_change_handwriting_area();
        /* Temp Solution for LSK Text Update */
        mmi_pen_editor_store_LSK_Text();
        mmi_pen_editor_set_left_soft_key_select();
        /* W05.32 Fix LSK issue in in-line multiline input box */
        if (get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY) != mmi_pen_editor_left_soft_key_handler)
        {
            mmi_pen_editor_set_inputbox_LSK_Function(get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY));
        }
        set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
        set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
    #if !defined(__MMI_HANDWRITING_PAD__)
        gui_start_timer(PEN_EDITOR_CONFIRM_PERIOD, mmi_pen_editor_confirm_selection);
    #endif 
        mmi_pen_begin_strokes_of_character();
        g_pen_editor_active_block = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_multi_block_stroke_down_handler
 * DESCRIPTION
 *  When receiving the stroke down event, do the related action according to the current situation
 * PARAMETERS
 *  pos     [IN]        The position of the stroke down event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_multi_block_stroke_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height;
    S32 active_block = 0;

    /*----------------------------------------------------------------*/
    /* Local Variables Initializing                                   */
    /*----------------------------------------------------------------*/
    changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif
    if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
    {
        mmi_pen_editor_smart_latin_confirm_select();
        mmi_pen_editor_set_left_soft_key();
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                register_EMS_inputbox_keys();
                handle_category28_input();
                wgui_set_EMS_inputbox_RSK();
                break;
    
            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                register_multiline_inputbox_keys();
                wgui_handle_inputbox_input();
                wgui_set_RSK();
                break;
    
            default:
                break;
        }
        gdi_lcd_repaint_all();
    }
    if (g_pen_editor_composition_state.candidate_state != PEN_EDITOR_CANDIDATE_OFF)
    {
        int change_height = 0;

        g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
        mmi_pen_editor_hide_composition_area();
        mmi_pen_editor_hide_candidate_area();
        change_height += gPenEditorCompositionInputBox.height;
        mmi_pen_editor_resize_content_area(change_height);
        mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
    }

    /* create new layer for stroke through Draw Manager */
#if !defined(MMI_PEN_EDITOR_ON_2_LAYER)
    if (gPenEditorGDIHandler == NULL || *gPenEditorGDIHandler == GDI_ERROR_HANDLE)
    {
        gPenEditorStrokeGDIBuffer = (U8*) mmi_frm_scrmem_alloc(handwriting_stroke_layer_mem);
        MMI_ASSERT(gPenEditorStrokeGDIBuffer);
        if (GDI_LAYER_SUCCEED != dm_create_layer_using_outside_memory(
                                    0,
                                    0,
                                    UI_device_width,
                                    UI_device_height,
                                    &gPenEditorGDIHandler,
                                    (U8*) gPenEditorStrokeGDIBuffer,
                                    handwriting_stroke_layer_mem,
                                    DM_LAYER_TOP))
        {
            MMI_ASSERT(0);
        }
        gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
#endif /* !defined(MMI_PEN_EDITOR_ON_2_LAYER) */

    /* If the state requires confirm, confirm it directly in this situation// */
    if (gPenEditorSelectCandidate)
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        gPenEditorShowVK = MMI_FALSE;
        mmi_pen_editor_confirm_selection();
        mmi_pen_editor_hide_candidate_area();
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    }
    active_block = mmi_pen_editor_handwriting_check_block(pos);
    if (g_pen_editor_active_block)
    {
        if (g_pen_editor_active_block != active_block)
        {
            mmi_pen_editor_handwriting_direct_input();
        }
    }
    g_pen_editor_active_block = active_block;
    if (!g_pen_editor_active_block)
    {
        g_pen_editor_active_block = 0;
    }
    /* Clear Virtual Keyboard Area only at the first stroke */
    if (gPenEditorFirstStroke)
    {
        gPenEditorFirstStroke = MMI_FALSE;
    }
    gPenEditorShowVK = MMI_TRUE;
    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
    gPenEditorPreviousPoint.x = pos.x;
    gPenEditorPreviousPoint.y = pos.y;

#ifdef MMI_PEN_EDITOR_ON_2_LAYER
    /* Create new stroke layer after editor/virtual keyboard is resized */
    mmi_pen_editor_backup_and_set_blt_layer();
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_multi_block_stroke_move_handler
 * DESCRIPTION
 *  Draw the stroke when moving the pen in the stroke mode and check the stroke is out of the current block or not.
 *  If yes, pass the stroke buffer to the handwriting module for recognizing
 * PARAMETERS
 *  pos     [IN]        The position of the stroke move event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_multi_block_stroke_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 active_block = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    active_block = mmi_pen_editor_handwriting_check_block(pos);
    if (active_block)
    {
        S32 previous_block = mmi_pen_editor_handwriting_check_block(gPenEditorPreviousPoint);

        if (active_block == previous_block)
        {
            gdi_layer_lock_frame_buffer();
        #ifdef MMI_PEN_EDITOR_ON_2_LAYER     
            gdi_layer_push_and_set_active(gPenEditorStrokeHandle);
        #else
	    if (gPenEditorGDIHandler != NULL)
	    {	
                gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
	    }	
        #endif            
            gdi_layer_push_clip();

            /* Draw the point of the stroke */
            gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y, pos.x, pos.y, gPenEditorStrokeColor);
            gui_line(gPenEditorPreviousPoint.x + 1, gPenEditorPreviousPoint.y, pos.x + 1, pos.y, gPenEditorStrokeColor);
            gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y + 1, pos.x, pos.y + 1, gPenEditorStrokeColor);
            gui_line(gPenEditorPreviousPoint.x - 1, gPenEditorPreviousPoint.y, pos.x - 1, pos.y, gPenEditorStrokeColor);
            gui_line(gPenEditorPreviousPoint.x, gPenEditorPreviousPoint.y - 1, pos.x, pos.y - 1, gPenEditorStrokeColor);

            gdi_layer_pop_clip();
            gdi_layer_pop_and_restore_active();
            gdi_layer_unlock_frame_buffer();

            gdi_layer_blt_previous(
                PEN_MIN(gPenEditorPreviousPoint.x, pos.x) - 1,
                PEN_MIN(gPenEditorPreviousPoint.y, pos.y) - 1,
                PEN_MAX(gPenEditorPreviousPoint.x, pos.x) + 1,
                PEN_MAX(gPenEditorPreviousPoint.y, pos.y) + 1);

        }
        gPenEditorPreviousPoint.x = pos.x;
        gPenEditorPreviousPoint.y = pos.y;
    }
    if (g_pen_editor_active_block)
    {
        if (g_pen_editor_active_block != active_block)
        {
            mmi_pen_editor_handwriting_direct_input();
            if (active_block)
            {
                gPenEditorFirstStroke = MMI_FALSE;
            }
        }
    }
    g_pen_editor_active_block = active_block;
    if (!g_pen_editor_active_block)
    {
        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
    }
    else
    {
        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_OFF);
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_multi_block_stroke_up_handler
 * DESCRIPTION
 *  Draw the last point of the stroke and start the timer to check this is the last stroke or not if pos in the handwriting block
 * PARAMETERS
 *  pos     [IN]        The position of the stroke up event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_multi_block_stroke_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int active_block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    active_block = mmi_pen_editor_handwriting_check_block(pos);
    if (active_block)
    {
        mmi_pen_editor_stroke_move_handler(pos);
        gui_cancel_timer(mmi_pen_editor_stroke_up_timer_handler);
        /* The end of the stroke, if no more stroke in the period, the end of the character */
        gui_start_timer(PEN_EDITOR_CHARACTER_END_PERIOD, mmi_pen_editor_stroke_up_timer_handler);
	 g_stroke_up_timer_is_on = MMI_TRUE;
    }
    gPenEditorPreviousPoint.x = -1;
    gPenEditorPreviousPoint.y = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_confirm_selection
 * DESCRIPTION
 *  When the candidate input box is on, confirm the selection and update the state by its situation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_confirm_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if hand writing is not enabled, it should not go here */
    if (!gPenEditorEnableHandWriting)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    /* gPenEditorShowVK to avoid clear the virtual keyboard area in some situation */
    if (gPenEditorSelectCandidate)
    {
        gdi_layer_lock_frame_buffer();
        gPenEditorSelectCandidate = MMI_FALSE;
        /* Temp Solution for LSK Text Update */
        mmi_pen_editor_set_left_soft_key();
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                register_EMS_inputbox_keys();
                handle_category28_input();
                wgui_set_EMS_inputbox_RSK();
                break;

            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                register_multiline_inputbox_keys();
                wgui_handle_inputbox_input();
                wgui_set_RSK();
                if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                {
                    cat201_register_key_func();
                }
                break;

            case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
                wgui_singleline_inputbox_RSK_label_clear = 0;
                singleline_inputbox_multitap_input_complete();
                wgui_set_singleline_RSK();
                break;

            case PEN_EDITOR_INLINE_TEXT:
                inline_edit_singleline_inputbox_multitap_input_complete();
                mmi_pen_editor_set_right_soft_key_inline_text();
                break;

            case PEN_EDITOR_DATE:
            case PEN_EDITOR_IP4:
            case PEN_EDITOR_TIME:
            case PEN_EDITOR_TIME_PERIOD:
                set_right_softkey_label(wgui_inline_edit_get_RSK_string());
                set_right_softkey_icon(NULL);
                register_right_softkey_handler();
                set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
                redraw_right_softkey();
                break;
            default:
                break;
        }
        mmi_pen_editor_hide_candidate_area();
        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
	 if (mmi_pen_editor_get_handwriting_style() == PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK)
	 {
	     if (PEN_EDITOR_CANDIDATE_OFF != g_pen_editor_composition_state.candidate_state)
            {
                g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
                changed_height += gPenEditorCandidateInputBox.height;
                mmi_pen_editor_hide_composition_area();
                mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
            }
            /* W05.47 Change the Input Control Height when the VK is not Tray Type */
         #ifndef __MMI_EDITOR_PEN_VK_UNFOLD__
            if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type))
            {
                changed_height += gPenEditorCandidateInputBox.height;
                if (mmi_pen_editor_is_there_vk_candidate_box())
                {
                    changed_height -= gPenEditorCandidateInputBox.height;
                }
                changed_height -= MMI_virtual_keyboard.height;
            }
         #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
            if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
            {
                mmi_pen_editor_resize_content_area(changed_height);
            }
	 }
     else if (gPenEditorShowVK && (gPenEditorCandidateInputBox.y >= (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM)))
        {
            if (PEN_EDITOR_CANDIDATE_OFF != g_pen_editor_composition_state.candidate_state)
            {
                g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
                changed_height += gPenEditorCandidateInputBox.height;
             mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
            }
            /* W05.47 Change the Input Control Height when the VK is not Tray Type */
            if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type ||
                  GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type))
            {
                changed_height += gPenEditorCandidateInputBox.height;
             if (mmi_pen_editor_is_there_vk_candidate_box())
                {
                    changed_height -= gPenEditorCandidateInputBox.height;
                }
                changed_height -= MMI_virtual_keyboard.height;
            }
            if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
            {
                mmi_pen_editor_resize_content_area(changed_height);
            }
        }

        if (gPenEditorShowVK)
        {
            mmi_pen_editor_clear_and_show_virtual_keyboard_area();
        }

     if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            if (gPenEditorShowVK)
            {
                /* W05.48 If vk text is null, clear it */
             if (mmi_pen_editor_get_vk_text_string_length() > 0)
                {
                 mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
                 wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_TRUE);
                }
                gui_move_single_line_input_box(
                    &gPenEditorCandidateInputBox,
                    gPenEditorCandidateInputBox.x,
                    MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
            }
            mmi_pen_editor_hide_candidate_area();
        }
        /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
        if (gPenEditorShowVK)
        {
            mmi_pen_editor_change_handwriting_area();
        }
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
    else
    {
        return;
    }

    /* According different input box, do different action */
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            multiline_inputbox_multitap_input_complete();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            EMS_inputbox_multitap_input_complete();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
            singleline_inputbox_multitap_input_complete();
            break;

        case PEN_EDITOR_INLINE_TEXT:
            inline_edit_singleline_inputbox_multitap_input_complete();
            break;

        case PEN_EDITOR_DATE:
            date_input_next_character();
            break;

        case PEN_EDITOR_IP4:
            IP4_input_next_character();
            break;

        case PEN_EDITOR_TIME:
            time_input_next_character();
            break;

        case PEN_EDITOR_TIME_PERIOD:
            time_period_input_next_character();
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_input_selection_character
 * DESCRIPTION
 *  Empty Function
 * PARAMETERS
 *  c       [IN]        The character to input
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_input_selection_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_previous_character_in_editor
 * DESCRIPTION
 *  According to InputBox Type, to get previous character in editor
 * PARAMETERS
 *  c     [OUT]        character's unicode
 * RETURNS
 *  1 : got the character 
 *  0 : got nothing
 *****************************************************************************/
U8 mmi_pen_editor_get_previous_character_in_editor(UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_get_previous_character(&MMI_multiline_inputbox, c);
            break;
        
        case PEN_EDITOR_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_get_previous_character(&MMI_EMS_inputbox, c);
            break;        
    }

    return ret;

}


#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_show_word_prediction
 * DESCRIPTION
 *  show predicted associate words on editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_show_word_prediction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode ||
        INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode) &&
        (MMI_virtual_keyboard.lang_type != GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL)
        )
    {
        if(mmi_pen_editor_get_previous_character_in_editor(&c))
        {
	    g_is_from_word_prediction = MMI_TRUE;
            mmi_pen_editor_check_phrase(c);
	    g_is_from_word_prediction = MMI_FALSE;
        }
    }

}
#endif /* defined(__MMI_HANDWRITING_WORD_PREDICTION__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_down_handler
 * DESCRIPTION
 *  According to the control which pen down on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen down event
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined(__MMI_HANDWRITING_PAD__)
void mmi_pen_editor_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 no_of_control_set = 0;
    gui_single_line_input_box_pen_enum single_line_input_box_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;
    S32 multitap_index = 0;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
        if (!gPenEditorFirstStroke && (g_pen_editor_active_block != mmi_pen_editor_handwriting_check_block(pos)))
        {
            mmi_pen_editor_handwriting_direct_input();
        }
        else if (!gPenEditorFirstStroke && g_pen_editor_active_block)
        {
            gui_start_timer(PEN_EDITOR_CHARACTER_END_PERIOD, mmi_pen_editor_stroke_up_timer_handler);
	     g_stroke_up_timer_is_on = MMI_TRUE;
        }
    }
    for (; no_of_control_set < gPenEditorControlSet.NumberofControlSets; no_of_control_set++)
    {
        switch (gPenEditorControlSet.PenEditorControlSet[no_of_control_set])
        {
            case PEN_EDITOR_CONTROL_INFORMATION_BAR:
                /* W06.11 Check information bar range according to gPenEditorInputBoxType */
                switch (gPenEditorInputBoxType)
                {
                    case PEN_EDITOR_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
                    case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
                    case PEN_EDITOR_INLINE_TEXT:
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                wgui_inputbox_information_bar_x,
                                wgui_inputbox_information_bar_y,
                                wgui_inputbox_information_bar_width,
                                wgui_inputbox_information_bar_height);
                        break;
                    case PEN_EDITOR_EMS_INPUT_BOX:
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                wgui_EMS_inputbox_information_bar_x,
                                wgui_EMS_inputbox_information_bar_y,
                                wgui_EMS_inputbox_information_bar_width,
                                wgui_EMS_inputbox_information_bar_height);
                        break;
                    case PEN_EDITOR_DATE:
                    case PEN_EDITOR_IP4:
                    case PEN_EDITOR_TIME:
                    case PEN_EDITOR_TIME_PERIOD:
                        break;
                    default:
                        break;
                }

                if (ret)
                {
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_INFORMATION_BAR;
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                        gui_cancel_timer(mmi_pen_editor_show_word_prediction);
                    #endif
                    }
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
                if (MMI_multiline_inputbox.n_lines > PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_LINES)
                {
                    gui_multi_line_input_box_set_pen_scroll_delay(
                        &MMI_multiline_inputbox,
                        PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_SCROLL_DELAY);
                }
                ret = gui_multi_line_input_box_translate_pen_event(
                        &MMI_multiline_inputbox,
                        MMI_PEN_EVENT_DOWN,
                        pos.x,
                        pos.y,
                        &multi_line_input_box_event);
                if (ret)
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)    
                        gui_cancel_timer(mmi_pen_editor_show_word_prediction);
                    #endif
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
                if (MMI_EMS_inputbox.n_lines > PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_LINES)
                {
                    gui_EMS_input_box_set_pen_scroll_delay(
                        &MMI_EMS_inputbox,
                        PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_SCROLL_DELAY);
                }
                ret = gui_EMS_input_box_translate_pen_event(
                        &MMI_EMS_inputbox,
                        MMI_PEN_EVENT_DOWN,
                        pos.x,
                        pos.y,
                        &EMS_input_box_event);
                if (ret)
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                        gui_cancel_timer(mmi_pen_editor_show_word_prediction);
                    #endif
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_EMS_INPUT_BOX;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
                if (MMI_multiline_inputbox.n_lines > PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_LINES)
                {
                    gui_multi_line_input_box_set_pen_scroll_delay(
                        &MMI_multiline_inputbox,
                        PEN_EDITOR_GUI_MULTI_LINE_INPUT_BOX_SCROLL_DELAY);
                }
                ret = gui_multi_line_input_box_translate_pen_event(
                        &MMI_multiline_inputbox,
                        MMI_PEN_EVENT_DOWN,
                        pos.x,
                        pos.y,
                        &multi_line_input_box_event);
                if (ret)
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                        gui_cancel_timer(mmi_pen_editor_show_word_prediction);
                    #endif
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
                ret = gui_single_line_input_box_translate_pen_event(
                        &MMI_singleline_inputbox,
                        MMI_PEN_EVENT_DOWN,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret)
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_INLINE_TEXT:
                ret = gui_single_line_input_box_translate_pen_event(
                        &MMI_inline_singleline_inputbox,
                        MMI_PEN_EVENT_DOWN,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret)
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_INLINE_TEXT;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_DATE:
                if (PEN_CHECK_BOUND
                    (pos.x, pos.y, current_date_input->x, current_date_input->y, current_date_input->width,
                     current_date_input->height))
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_DATE;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_IP4:
                if (PEN_CHECK_BOUND
                    (pos.x, pos.y, current_IP4_input->x, current_IP4_input->y, current_IP4_input->width,
                     current_IP4_input->height))
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_IP4;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_TIME:
                if (PEN_CHECK_BOUND
                    (pos.x, pos.y, current_time_input->x, current_time_input->y, current_time_input->width,
                     current_time_input->height))
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_TIME;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_TIME_PERIOD:
                if (PEN_CHECK_BOUND
                    (pos.x, pos.y, current_time_period_input->x, current_time_period_input->y,
                     current_time_period_input->width, current_time_period_input->height))
                {
                    /* W05.45 Temp Solution for Pen Down When Selecting Candidates */
                    if (gPenEditorSelectCandidate)
                    {
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_TIME_PERIOD;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_SCROLL_BAR:
                break;
            case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
                if (PEN_EDITOR_VK_ON == mmi_pen_editor_get_vk_state())
                {
                    ret = gui_virtual_keyboard_translate_pen_event(
                            &MMI_virtual_keyboard,
                            pos.x,
                            pos.y,
                            MMI_PEN_EVENT_DOWN,
                            &vk_event,
                            &vk_para);
                }
                else
                {
                    break;
                }
                if (ret)
                {
                    switch (vk_event)
                    {
                        case GUI_VKBD_PEN_BAKSPACE:
                            break;
                        case GUI_VKBD_PEN_BRACKET:
                            break;
                        case GUI_VKBD_PEN_CAPSLOCK:
                            break;
                        case GUI_VKBD_PEN_CHAR_I:
                            break;
                        case GUI_VKBD_PEN_DISPLAY_AREA:
                            break;
                        case GUI_VKBD_PEN_HIDE:
                            break;
                        case GUI_VKBD_PEN_NEWLINE:
                            break;
                        case GUI_VKBD_PEN_NONE:
                            break;
                        case GUI_VKBD_PEN_SHOW:
                            break;
                        case GUI_VKBD_PEN_SPACE:
                            break;
                        case GUI_VKBD_PEN_SYMBPICKER:
                            break;
                        case GUI_VKBD_PEN_EUROSYMB:
                            break;
                        default:
                            MMI_ASSERT(0);
                            break;
                    }
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD;
                #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)    
                    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
                #endif
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
                if (PEN_EDITOR_CANDIDATE_OFF != g_pen_editor_composition_state.candidate_state)
                {
                    ret = gui_single_line_input_box_translate_pen_event(
                            &gPenEditorCompositionInputBox,
                            MMI_PEN_EVENT_DOWN,
                            pos.x,
                            pos.y,
                            &single_line_input_box_event);
                    if (ret)
                    {
                        g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_CONTROL;
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                        gPenEditorActiveControl = PEN_EDITOR_CONTROL_COMPOSITION_AREA;
                        gui_show_single_line_input_box_ext(&gPenEditorCompositionInputBox, pos.x, pos.y);
                        gdi_layer_lock_frame_buffer();
                        /* /TODO : Jump to the index */
                        if ((INPUT_MODE_TR_BOPOMO == MMI_current_input_mode ||
                             INPUT_MODE_SM_PINYIN == MMI_current_input_mode) &&
                            PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == g_pen_editor_composition_state.candidate_state)
                        {
                            mmi_pen_editor_set_compositon_index(mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position());
                            mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(mmi_pen_editor_get_compositon_index());
                        }
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                    if (g_pen_editor_composition_state.arrow_enable)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCompositionInputBox.x - (((gPenEditorCompositionInputBox.grid_width << 1) + gPenEditorCompositionInputBox.grid_width) >> 2) - 1,
                                gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                                gPenEditorCompositionInputBox.grid_width >> 1,
                                ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                        if (ret)
                        {
                            g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_LEFT_ARROW;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_COMPOSITION_AREA;
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_hide_composition_area();
                            gui_show_single_line_input_box(&gPenEditorCompositionInputBox);
                            if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_composition_state.left_arrow_state)
                            {
                                g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                            }
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_LEFT,
                                g_pen_editor_composition_state.left_arrow_state,
                                PEN_EDITOR_ARROW_FOR_COMPOSITION);
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                                g_pen_editor_composition_state.right_arrow_state,
                                PEN_EDITOR_ARROW_FOR_COMPOSITION);
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                            return;
                        }
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCompositionInputBox.x + gPenEditorCompositionInputBox.width + (gPenEditorCompositionInputBox.grid_width >> 2) - 1,
                                gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                                gPenEditorCompositionInputBox.grid_width >> 1,
                                ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                        if (ret)
                        {
                            g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_RIGHT_ARROW;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_COMPOSITION_AREA;
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_hide_composition_area();
                            gui_show_single_line_input_box(&gPenEditorCompositionInputBox);
                            if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_composition_state.right_arrow_state)
                            {
                                g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                            }
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_LEFT,
                                g_pen_editor_composition_state.left_arrow_state,
                                PEN_EDITOR_ARROW_FOR_COMPOSITION);
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                                g_pen_editor_composition_state.right_arrow_state,
                                PEN_EDITOR_ARROW_FOR_COMPOSITION);
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                            return;
                        }
                        ret = PEN_CHECK_BOUND(
                                pos.x, 
                                pos.y, 
                                0, 
                                gPenEditorCompositionInputBox.y, 
                                UI_device_width, 
                                gPenEditorCompositionInputBox.height);
                        if (ret)
                        {
                            g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_OUT_OF_RANGE;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_COMPOSITION_AREA;
                            return;
                        }
                    }
                }
                break;
            case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
                if (gPenEditorSelectCandidate)
                {
                    g_pen_editor_candidate_state.selected_candidate = 0;
                    ret = gui_single_line_input_box_translate_pen_event(
                            &gPenEditorCandidateInputBox,
                            MMI_PEN_EVENT_DOWN,
                            pos.x,
                            pos.y,
                            &single_line_input_box_event);
                    if (ret)
                    {
                        UI_character_type ch, ch1, ch2;

                        g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_CONTROL;
                        gui_cancel_timer(mmi_pen_editor_confirm_selection);
                        gPenEditorActiveControl = PEN_EDITOR_CONTROL_CANDIDATE_AREA;
                        gui_show_single_line_input_box_ext(&gPenEditorCandidateInputBox, pos.x, pos.y);
                        gui_single_line_input_box_next(&gPenEditorCandidateInputBox);
                        ch1 = *(gPenEditorCandidateInputBox.current_text_p - 2);
                        ch2 = *(gPenEditorCandidateInputBox.current_text_p - 1);
                        ch = ch1 | (ch2 << 8);
                        g_pen_editor_candidate_state.selected_candidate = ch;

                        gdi_layer_lock_frame_buffer();
                        switch (gPenEditorInputBoxType)
                        {
                                /* W05.32 Fix typo error */
                            case PEN_EDITOR_MULTILINE_INPUT_BOX:
                            case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                                multiline_inputbox_multitap_input(ch);
                                break;
                            case PEN_EDITOR_EMS_INPUT_BOX:
                                EMS_inputbox_multitap_input(ch);
                                break;
                            case PEN_EDITOR_INLINE_TEXT:
                                inline_edit_singleline_inputbox_multitap_input(ch);
                                break;
                            default:
                                break;
                        }
                        mmi_pen_editor_show_candidate_area(
                            g_pen_editor_candidate_state.arrow_enable,
                            g_pen_editor_candidate_state.candidate_state);
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                    if (g_pen_editor_candidate_state.arrow_enable)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCandidateInputBox.x - (((gPenEditorCandidateInputBox.grid_width << 1) + gPenEditorCandidateInputBox.grid_width) >> 2) - 1,
                                gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                                gPenEditorCandidateInputBox.grid_width >> 1,
                                ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                        if (ret)
                        {
                            g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_LEFT_ARROW;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_CANDIDATE_AREA;
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_hide_candidate_area();
                            gui_show_single_line_input_box(&gPenEditorCandidateInputBox);
                            if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_candidate_state.left_arrow_state)
                            {
                                g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                            }
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_LEFT,
                                g_pen_editor_candidate_state.left_arrow_state,
                                PEN_EDITOR_ARROW_FOR_CANDIDATE);
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                                g_pen_editor_candidate_state.right_arrow_state,
                                PEN_EDITOR_ARROW_FOR_CANDIDATE);
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                            return;
                        }
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCandidateInputBox.x + gPenEditorCandidateInputBox.width + (gPenEditorCandidateInputBox.grid_width >> 2) - 1,
                                gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                                gPenEditorCandidateInputBox.grid_width >> 1,
                                ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                        if (ret)
                        {
                            g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_RIGHT_ARROW;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_CANDIDATE_AREA;
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_hide_candidate_area();
                            gui_show_single_line_input_box(&gPenEditorCandidateInputBox);
                            if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_candidate_state.right_arrow_state)
                            {
                                g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                            }
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_LEFT,
                                g_pen_editor_candidate_state.left_arrow_state,
                                PEN_EDITOR_ARROW_FOR_CANDIDATE);
                            mmi_pen_editor_draw_arrow(
                                PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                                g_pen_editor_candidate_state.right_arrow_state,
                                PEN_EDITOR_ARROW_FOR_CANDIDATE);
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                            return;
                        }
                        ret = PEN_CHECK_BOUND(
                                pos.x, 
                                pos.y, 
                                0, 
                                gPenEditorCandidateInputBox.y, 
                                UI_device_width, 
                                gPenEditorCandidateInputBox.height);
                        if (ret)
                        {
                            g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_OUT_OF_RANGE;
                            gPenEditorActiveControl = PEN_EDITOR_CONTROL_CANDIDATE_AREA;
                            return;
                        }
                    }
                }
                break;
            case PEN_EDITOR_CONTROL_IME_BUTTON:
                if (ret)
                {
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_IME_BUTTON;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_MULTITAP:
                if (MMI_TRUE == gPenEditorMultitapInputState)
                {
                    ret = gui_multitap_input_translate_pen_position(
                            gPenEditorMultitapInput,
                            pos.x,
                            pos.y,
                            &multitap_index);
                }
                if (ret)
                {
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_MULTITAP;
                    return;
                }
                break;
            case PEN_EDITOR_CONTROL_NONE:
                break;
            default:
                MMI_ASSERT(0);
        }
    }
    if (MMI_FALSE == ret)
    {
        //W05.43 Temp Solution for Switch Input Method Without Complete Selecting Candidate
        //W05.45 Temp Solution for Pen Down When Selecting Candidates
        gPenEditorActiveControl = PEN_EDITOR_CONTROL_NONE;
        wgui_general_pen_down_hdlr(pos);
        if (gPenEditorSelectCandidate && !g_pen_editor_hold_confirm)
        {
            gui_cancel_timer(mmi_pen_editor_confirm_selection);
            mmi_pen_editor_confirm_selection();
        }
    }
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_up_handler
 * DESCRIPTION
 *  According to the control which pen up on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen up event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_up_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 no_of_control_set = 0; */
    gui_single_line_input_box_pen_enum single_line_input_box_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;
    MMI_BOOL ret = MMI_FALSE;
    S32 multitap_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.09 Confirm Selection before moving cursor or switching input method */
    switch (gPenEditorActiveControl)
    {
        case PEN_EDITOR_CONTROL_INFORMATION_BAR:
            /* W06.11 Check information bar range according to gPenEditorInputBoxType */
            switch (gPenEditorInputBoxType)
            {
                case PEN_EDITOR_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
                case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
                case PEN_EDITOR_INLINE_TEXT:
		    if (r2lMMIFlag )
		    {
			ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            wgui_inputbox_information_bar_x + wgui_inputbox_information_bar_width - wgui_information_bar_input_mode_display_width,
                            wgui_inputbox_information_bar_y + (wgui_information_bar_input_mode_height - wgui_information_bar_input_mode_display_height) / 2 - 1,
                            wgui_information_bar_input_mode_display_width,
                            wgui_information_bar_input_mode_display_height + 2);
		    }
                    else
		    {
                    ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            wgui_inputbox_information_bar_x,
                            wgui_inputbox_information_bar_y + (wgui_information_bar_input_mode_height - wgui_information_bar_input_mode_display_height) / 2 - 1,
                            wgui_information_bar_input_mode_display_width,
                            wgui_information_bar_input_mode_display_height + 2);
		    }
                    break;
                case PEN_EDITOR_EMS_INPUT_BOX:
		    if (r2lMMIFlag )
		    {
		       ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            wgui_EMS_inputbox_information_bar_x + wgui_EMS_inputbox_information_bar_width - wgui_information_bar_input_mode_display_width,
                            wgui_EMS_inputbox_information_bar_y + (wgui_information_bar_input_mode_height - wgui_information_bar_input_mode_display_height) / 2 - 1,
                            wgui_information_bar_input_mode_display_width,
                            wgui_information_bar_input_mode_display_height + 2);
		    }
                    else
		    {
                        ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            wgui_EMS_inputbox_information_bar_x,
                            wgui_EMS_inputbox_information_bar_y + (wgui_information_bar_input_mode_height - wgui_information_bar_input_mode_display_height) / 2 - 1,
                            wgui_information_bar_input_mode_display_width,
                            wgui_information_bar_input_mode_display_height + 2);
		    }
                    break;
                case PEN_EDITOR_DATE:
                case PEN_EDITOR_IP4:
                case PEN_EDITOR_TIME:
                case PEN_EDITOR_TIME_PERIOD:
                    break;
                default:
                    break;
            }
            if (!ret)
            {
                break;
            }
            if (gPenEditorSelectCandidate)
            {
                mmi_pen_editor_confirm_selection();
            }
            mmi_pen_editor_switch_input_method();
            if (ret)
            {
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            if (ret)
            {
                if (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN)
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                }
                if (gPenEditorSelectCandidate && mmi_pen_editor_get_vk_text_string_length() == 0)
                {
                    mmi_pen_editor_confirm_selection();
                }
                if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
                {
                    mmi_pen_editor_smart_latin_confirm_select();
                    mmi_pen_editor_set_left_soft_key();
                }   
                if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != multi_line_input_box_event)
                {
                    gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
                    redraw_multiline_inputbox();
                #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                    gui_start_timer(WORD_PREDICTION_TIMEOUT,mmi_pen_editor_show_word_prediction);
                #endif

                }
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_translate_pen_event(
                    &MMI_EMS_inputbox,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &EMS_input_box_event);
            if (ret)
            {
                if (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN)
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                }
                if (gPenEditorSelectCandidate && mmi_pen_editor_get_vk_text_string_length() == 0)
                {
                    mmi_pen_editor_confirm_selection();
                }
                if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
                {
                    mmi_pen_editor_smart_latin_confirm_select();
                    mmi_pen_editor_set_left_soft_key();
                }                
                if (GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR != EMS_input_box_event)
                {
                    gui_show_EMS_input_box_ext(&MMI_EMS_inputbox, pos.x, pos.y);
                    wgui_EMS_set_text_format(MMI_EMS_inputbox.text_format);
                    redraw_EMS_inputbox();
                #if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
                    gui_start_timer(WORD_PREDICTION_TIMEOUT,mmi_pen_editor_show_word_prediction);
                #endif
                }
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            if (ret)
            {
                if (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN)
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                }
                if (gPenEditorSelectCandidate && mmi_pen_editor_get_vk_text_string_length() == 0)
                {
                    mmi_pen_editor_confirm_selection();
                }
                if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
                {
                    mmi_pen_editor_smart_latin_confirm_select();
                    mmi_pen_editor_set_left_soft_key();
                } 
                if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != multi_line_input_box_event)
                {
                    gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
                }
                redraw_multiline_inputbox();
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
            ret = gui_single_line_input_box_translate_pen_event(
                    &MMI_singleline_inputbox,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &single_line_input_box_event);
            if (ret)
            {
                if (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN)
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                }
                if (gPenEditorSelectCandidate)
                {
                    mmi_pen_editor_confirm_selection();
                }
                gui_show_single_line_input_box_ext(&MMI_singleline_inputbox, pos.x, pos.y);
                /* W06.15 Reloacate Curesor after moving cursor by pen */
                gui_single_line_input_box_locate_cursor(&MMI_singleline_inputbox);
                redraw_singleline_inputbox();
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_INLINE_TEXT:
            ret = gui_single_line_input_box_translate_pen_event(
                    &MMI_inline_singleline_inputbox,
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &single_line_input_box_event);
            if (ret)
            {
                if (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN)
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                }
                if (gPenEditorSelectCandidate)
                {
                    mmi_pen_editor_confirm_selection();
                }
                gui_show_single_line_input_box_ext(&MMI_inline_singleline_inputbox, pos.x, pos.y);
                /* W06.15 Reloacate Curesor after moving cursor by pen */
                gui_single_line_input_box_locate_cursor(&MMI_inline_singleline_inputbox);
                show_inline_singleline_inputbox();
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_DATE:
            if (gPenEditorSelectCandidate)
            {
                mmi_pen_editor_confirm_selection();
            }
            date_input_move_to_x_y(current_date_input, pos.x, pos.y);
            if (ret)
            {
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_IP4:
            if (gPenEditorSelectCandidate)
            {
                mmi_pen_editor_confirm_selection();
            }
            IP4_input_move_to_x_y(current_IP4_input, pos.x, pos.y);
            if (ret)
            {
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_TIME:
            if (gPenEditorSelectCandidate)
            {
                mmi_pen_editor_confirm_selection();
            }
            time_input_move_to_x_y(current_time_input, pos.x, pos.y);
            if (ret)
            {
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_TIME_PERIOD:
            if (gPenEditorSelectCandidate)
            {
                mmi_pen_editor_confirm_selection();
            }
            time_period_input_move_to_x_y(current_time_period_input, pos.x, pos.y);
            if (ret)
            {
                return;
            }
            break;
        case PEN_EDITOR_CONTROL_SCROLL_BAR:
            break;
        case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
            ret = gui_virtual_keyboard_translate_pen_event(
                    &MMI_virtual_keyboard,
                    pos.x,
                    pos.y,
                    MMI_PEN_EVENT_UP,
                    &vk_event,
                    &vk_para);
            if (ret)
            {
                if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
                {
                    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
                    mmi_pen_editor_smart_latin_confirm_select();
                    mmi_pen_editor_set_left_soft_key();
                    switch (gPenEditorInputBoxType)
                    {
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            register_EMS_inputbox_keys();
                            handle_category28_input();
                            wgui_set_EMS_inputbox_RSK();
                            break;
                
                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                            register_multiline_inputbox_keys();
                            wgui_handle_inputbox_input();
                            wgui_set_RSK();
                            break;
                
                        default:
                            break;
                    }
                    gdi_lcd_repaint_all();
                }

                switch (vk_event)
                {
                    case GUI_VKBD_PEN_BAKSPACE:
                        mmi_pen_editor_right_soft_key_handler();
                        break;
                    case GUI_VKBD_PEN_BRACKET:
                        mmi_pen_editor_bracket();
                        break;
                    case GUI_VKBD_PEN_CAPSLOCK:
                        mmi_pen_editor_vk_caps_lock();
                        break;
                    case GUI_VKBD_PEN_CHAR_I:
                        mmi_pen_editor_vk_insertcharacter(vk_para);
                        break;
                    case GUI_VKBD_PEN_DISPLAY_AREA:
                        break;
                    case GUI_VKBD_PEN_HIDE:
                        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
                        {
#if !defined( LANG_TH_HANDWRITE_SUPPORT)
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
                        else
                        {
                            mmi_pen_editor_vk_hide();
                        }
                        break;
                    case GUI_VKBD_PEN_NEWLINE:
                        mmi_pen_editor_new_line();
                        break;
                    case GUI_VKBD_PEN_NONE:
                        ret = MMI_FALSE;
                        break;
                    case GUI_VKBD_PEN_SHOW:
                        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
                        {
                            mmi_pen_editor_disable_multi_block_handwriting();
                        }
                        else
                        {
                            mmi_pen_editor_vk_show();
                        }
                        break;
                    case GUI_VKBD_PEN_SPACE:
                        /* Code for ?? */
                        mmi_pen_editor_input_character(' ', MMI_FALSE);
                        break;
                    case GUI_VKBD_PEN_SYMBPICKER:
                        mmi_pen_editor_vk_symbol_picker(MMI_FALSE);
                        break;
                    case GUI_VKBD_PEN_EUROSYMB:
                        mmi_pen_editor_vk_symbol_picker(MMI_TRUE);
                        break;
                    default:
                        MMI_ASSERT(0);
                }
                if (ret)
                {
                    return;
                }
            }
            break;
        case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
            if (PEN_EDITOR_CANDIDATE_OFF != g_pen_editor_composition_state.candidate_state)
            {
                if (g_pen_editor_composition_state.arrow_enable &&
                    PEN_EDITOR_MOVE_OUT != g_pen_editor_composition_state.pen_down_state)
                {
                    if (PEN_EDITOR_ARROW_PRESS_DOWN == g_pen_editor_composition_state.right_arrow_state)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCompositionInputBox.x + gPenEditorCompositionInputBox.width + (gPenEditorCompositionInputBox.grid_width >> 2) - 1,
                                gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                                gPenEditorCompositionInputBox.grid_width >> 1,
                                ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                        if (ret)
                        {
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_smart_bpmf_pinyin_get_syllable_next();
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                        }
                        //if (PEN_EDITOR_ARROW_DISABLE != g_pen_editor_composition_state.right_arrow_state)
                        //{
                        //    g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                        //}
                    }
                    else if (PEN_EDITOR_ARROW_PRESS_DOWN == g_pen_editor_composition_state.left_arrow_state)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCompositionInputBox.x - (((gPenEditorCompositionInputBox.grid_width << 1) + gPenEditorCompositionInputBox.grid_width) >> 2) - 1,
                                gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                                gPenEditorCompositionInputBox.grid_width >> 1,
                                ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                        if (ret)
                        {
                            gdi_layer_lock_frame_buffer();
                            mmi_pen_editor_smart_bpmf_pinyin_get_syllable_prev();
                            gdi_layer_unlock_frame_buffer();
                            gdi_lcd_repaint_all();
                        }
                        //if (PEN_EDITOR_ARROW_DISABLE != g_pen_editor_composition_state.left_arrow_state)
                        //{
                        //    g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                        //}
                    }
                }
                ret = gui_single_line_input_box_translate_pen_event(
                        &gPenEditorCompositionInputBox,
                        MMI_PEN_EVENT_UP,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret)
                {
                    gdi_layer_lock_frame_buffer();
                    gui_show_single_line_input_box_ext(&gPenEditorCompositionInputBox, pos.x, pos.y);
                    if ((INPUT_MODE_TR_BOPOMO == MMI_current_input_mode ||
                         INPUT_MODE_SM_PINYIN == MMI_current_input_mode) &&
                        PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == g_pen_editor_composition_state.candidate_state)
                    {
                        mmi_pen_editor_set_compositon_index(mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position());
                        mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(mmi_pen_editor_get_compositon_index());
                        mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable();
                    }
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();
                }
            }
            break;
        case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
            if (gPenEditorSelectCandidate)
            {
                if (g_pen_editor_candidate_state.arrow_enable &&
                    PEN_EDITOR_MOVE_OUT != g_pen_editor_candidate_state.pen_down_state)
                {
                    if (PEN_EDITOR_ARROW_PRESS_DOWN == g_pen_editor_candidate_state.right_arrow_state)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCandidateInputBox.x + gPenEditorCandidateInputBox.width + (gPenEditorCandidateInputBox.grid_width >> 2) - 1,
                                gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                                gPenEditorCandidateInputBox.grid_width >> 1,
                                ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                        if (ret)
                        {
                            mmi_pen_editor_get_candidates_next_page();
                        }
                        /* g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP; */
                    }
                    else if (PEN_EDITOR_ARROW_PRESS_DOWN == g_pen_editor_candidate_state.left_arrow_state)
                    {
                        ret = PEN_CHECK_BOUND(
                                pos.x,
                                pos.y,
                                gPenEditorCandidateInputBox.x - (((gPenEditorCandidateInputBox.grid_width << 1) + gPenEditorCandidateInputBox.grid_width) >> 2) - 1,
                                gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                                gPenEditorCandidateInputBox.grid_width >> 1,
                                ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                        if (ret)
                        {
                            mmi_pen_editor_get_candidates_prev_page();
                        }
                        /* g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP; */
                    }
                }
                ret = gui_single_line_input_box_translate_pen_event(
                        &gPenEditorCandidateInputBox,
                        MMI_PEN_EVENT_UP,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret || g_pen_editor_candidate_state.selected_candidate)
                {
                    UI_character_type ch, ch1, ch2;

                    gdi_layer_lock_frame_buffer();
                    /* W05.36 To Fix Candidates Lsit Issue Because of Font Type */
                    gPenEditorCandidateInputBox.text_offset_x = 0;
                    gui_show_single_line_input_box_ext(&gPenEditorCandidateInputBox, pos.x, pos.y);
                    if (!gui_single_line_input_box_test_last_position(&gPenEditorCandidateInputBox))
                    {
                        gui_single_line_input_box_next(&gPenEditorCandidateInputBox);
                    }
                    ch1 = *(gPenEditorCandidateInputBox.current_text_p - 2);
                    ch2 = *(gPenEditorCandidateInputBox.current_text_p - 1);
                    ch = ch1 | (ch2 << 8);
                    if (PEN_EDITOR_MOVE_OUT == g_pen_editor_candidate_state.pen_down_state)
                    {
                        ch = g_pen_editor_candidate_state.selected_candidate;
                    }
                    mmi_pen_editor_input_character(ch, MMI_FALSE);
                    switch (gPenEditorInputBoxType)
                    {
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            wgui_set_EMS_inputbox_RSK();
                            break;
                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                            wgui_set_RSK();
                            break;
                        case PEN_EDITOR_INLINE_TEXT:
                            mmi_pen_editor_set_right_soft_key_inline_text();
                            break;
                        case PEN_EDITOR_DATE:
                        case PEN_EDITOR_IP4:
                        case PEN_EDITOR_TIME:
                        case PEN_EDITOR_TIME_PERIOD:
                            set_right_softkey_label(wgui_inline_edit_get_RSK_string());
                            set_right_softkey_icon(NULL);
                            register_right_softkey_handler();
                            set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
                            redraw_right_softkey();
                            break;
                        default:
                            break;
                    }
                    /* Temp Solution for checking Chinese Characters */
                    mmi_pen_editor_check_phrase(ch);
                    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
                    mmi_pen_editor_change_handwriting_area();
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();
                }
            }
            g_pen_editor_candidate_state.selected_candidate = 0;
            break;
        case PEN_EDITOR_CONTROL_IME_BUTTON:
            if (ret)
            {

            }
            break;
        case PEN_EDITOR_CONTROL_MULTITAP:
            ret = gui_multitap_input_translate_pen_position(gPenEditorMultitapInput, pos.x, pos.y, &multitap_index);
            if (ret)
            {

            }
            break;
        case PEN_EDITOR_CONTROL_NONE:
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    if (MMI_FALSE == ret)
    {
        wgui_general_pen_up_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_long_tap_handler
 * DESCRIPTION
 *  According to the control which pen long tap on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen long tap event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_long_tap_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    S32 multitap_index = 0;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPenEditorActiveControl)
    {
        case PEN_EDITOR_CONTROL_INFORMATION_BAR:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_LONG_TAP,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_translate_pen_event(
                    &MMI_EMS_inputbox,
                    MMI_PEN_EVENT_LONG_TAP,
                    pos.x,
                    pos.y,
                    &EMS_input_box_event);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_INLINE_TEXT:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_DATE:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_IP4:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_TIME:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_TIME_PERIOD:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_SCROLL_BAR:
            break;

        case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
            break;

        case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_IME_BUTTON:
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_MULTITAP:
            ret = gui_multitap_input_translate_pen_position(gPenEditorMultitapInput, pos.x, pos.y, &multitap_index);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_NONE:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    if (MMI_FALSE == ret)
    {
        wgui_general_pen_long_tap_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_repeat_handler
 * DESCRIPTION
 *  According to the control which pen repeat on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen repeat event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_repeat_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    MMI_BOOL ret = MMI_FALSE;
    S32 multitap_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPenEditorActiveControl)
    {
        case PEN_EDITOR_CONTROL_INFORMATION_BAR:
            break;

        case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_REPEAT,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_translate_pen_event(
                    &MMI_EMS_inputbox,
                    MMI_PEN_EVENT_REPEAT,
                    pos.x,
                    pos.y,
                    &EMS_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
            break;

        case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
            break;

        case PEN_EDITOR_CONTROL_INLINE_TEXT:
            break;

        case PEN_EDITOR_CONTROL_DATE:
            break;

        case PEN_EDITOR_CONTROL_IP4:
            break;

        case PEN_EDITOR_CONTROL_TIME:
            break;

        case PEN_EDITOR_CONTROL_TIME_PERIOD:
            break;

        case PEN_EDITOR_CONTROL_SCROLL_BAR:
            break;

        case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
            break;

        case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
            break;

        case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
            break;

        case PEN_EDITOR_CONTROL_IME_BUTTON:
            break;

        case PEN_EDITOR_CONTROL_MULTITAP:
            ret = gui_multitap_input_translate_pen_position(gPenEditorMultitapInput, pos.x, pos.y, &multitap_index);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_NONE:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    if (MMI_FALSE == ret)
    {
        wgui_general_pen_repeat_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_abort_handler
 * DESCRIPTION
 *  According to the control which pen abort on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen abort event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_abort_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    MMI_BOOL ret = MMI_FALSE;
    S32 multitap_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPenEditorActiveControl)
    {
        case PEN_EDITOR_CONTROL_INFORMATION_BAR:
            break;

        case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_ABORT,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_translate_pen_event(
                    &MMI_EMS_inputbox,
                    MMI_PEN_EVENT_ABORT,
                    pos.x,
                    pos.y,
                    &EMS_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
            break;

        case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
            break;

        case PEN_EDITOR_CONTROL_INLINE_TEXT:
            break;

        case PEN_EDITOR_CONTROL_DATE:
            break;

        case PEN_EDITOR_CONTROL_IP4:
            break;

        case PEN_EDITOR_CONTROL_TIME:
            break;

        case PEN_EDITOR_CONTROL_TIME_PERIOD:
            break;

        case PEN_EDITOR_CONTROL_SCROLL_BAR:
            break;

        case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
        {
            gui_virtual_keyboard_pen_enum vk_event;
            gui_pen_event_param_struct vk_para;

            ret = gui_virtual_keyboard_translate_pen_event(
                    &MMI_virtual_keyboard,
                    pos.x,
                    pos.y,
                    MMI_PEN_EVENT_ABORT,
                    &vk_event,
                    &vk_para);
        }
            break;

        case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
            break;

        case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
            break;

        case PEN_EDITOR_CONTROL_IME_BUTTON:
            break;

        case PEN_EDITOR_CONTROL_MULTITAP:
            ret = gui_multitap_input_translate_pen_position(gPenEditorMultitapInput, pos.x, pos.y, &multitap_index);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_NONE:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    gPenEditorActiveControl = PEN_EDITOR_CONTROL_NONE;

    if (MMI_FALSE == ret)
    {
        wgui_general_pen_abort_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_move_handler
 * DESCRIPTION
 *  According to the control which pen move on, do the related action
 * PARAMETERS
 *  pos     [IN]        The position of the pen move event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_move_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_pen_enum single_line_input_box_event;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    gui_EMS_input_box_pen_enum EMS_input_box_event;
    S32 multitap_index = 0;
    MMI_BOOL ret = MMI_FALSE;
    gui_pen_event_param_struct vk_para;
    gui_virtual_keyboard_pen_enum vk_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPenEditorActiveControl)
    {
        case PEN_EDITOR_CONTROL_INFORMATION_BAR:
            break;

        case PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX:
            ret = gui_multi_line_input_box_translate_pen_event(
                    &MMI_multiline_inputbox,
                    MMI_PEN_EVENT_MOVE,
                    pos.x,
                    pos.y,
                    &multi_line_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_EMS_INPUT_BOX:
            ret = gui_EMS_input_box_translate_pen_event(
                    &MMI_EMS_inputbox,
                    MMI_PEN_EVENT_MOVE,
                    pos.x,
                    pos.y,
                    &EMS_input_box_event);
            break;

        case PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX:
            break;

        case PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX:
            break;

        case PEN_EDITOR_CONTROL_INLINE_TEXT:
            break;

        case PEN_EDITOR_CONTROL_DATE:
            break;

        case PEN_EDITOR_CONTROL_IP4:
            break;

        case PEN_EDITOR_CONTROL_TIME:
            break;

        case PEN_EDITOR_CONTROL_TIME_PERIOD:
            break;

        case PEN_EDITOR_CONTROL_SCROLL_BAR:
            break;

        case PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD:
            ret = gui_virtual_keyboard_translate_pen_event(
                    &MMI_virtual_keyboard,
                    pos.x,
                    pos.y,
                    MMI_PEN_EVENT_MOVE,
                    &vk_event,
                    &vk_para);
            break;

        case PEN_EDITOR_CONTROL_COMPOSITION_AREA:
            if (PEN_EDITOR_CANDIDATE_OFF != g_pen_editor_composition_state.candidate_state)
            {
                if (g_pen_editor_composition_state.arrow_enable)
                {
                    ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            gPenEditorCompositionInputBox.x - (((gPenEditorCompositionInputBox.grid_width << 1) + gPenEditorCompositionInputBox.grid_width) >> 2) - 1,
                            gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                            gPenEditorCompositionInputBox.grid_width >> 1,
                            ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                    if (ret && g_pen_editor_composition_state.pen_down_state == PEN_EDITOR_IN_LEFT_ARROW)
                    {
                        g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_LEFT_ARROW;
                        gdi_layer_lock_frame_buffer();
                        mmi_pen_editor_hide_candidate_area();
                        gui_show_single_line_input_box(&gPenEditorCompositionInputBox);
                        if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_composition_state.left_arrow_state)
                        {
                            g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                        }
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_LEFT,
                            g_pen_editor_composition_state.left_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                            g_pen_editor_composition_state.right_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                    ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            gPenEditorCompositionInputBox.x + gPenEditorCompositionInputBox.width + (gPenEditorCompositionInputBox.grid_width >> 2) - 1,
                            gPenEditorCompositionInputBox.y + (gPenEditorCompositionInputBox.height >> 3),
                            gPenEditorCompositionInputBox.grid_width >> 1,
                            ((gPenEditorCompositionInputBox.height << 1) + gPenEditorCompositionInputBox.height) >> 2);
                    if (ret && g_pen_editor_composition_state.pen_down_state == PEN_EDITOR_IN_RIGHT_ARROW)
                    {
                        g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_RIGHT_ARROW;
                        gdi_layer_lock_frame_buffer();
                        mmi_pen_editor_hide_candidate_area();
                        gui_show_single_line_input_box(&gPenEditorCompositionInputBox);
                        if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_composition_state.right_arrow_state)
                        {
                            g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                        }
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_LEFT,
                            g_pen_editor_composition_state.left_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                            g_pen_editor_composition_state.right_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                }
                ret = gui_single_line_input_box_translate_pen_event(
                        &gPenEditorCompositionInputBox,
                        MMI_PEN_EVENT_MOVE,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret)
                {
                    g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_IN_CONTROL;
                    gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    gui_show_single_line_input_box_ext(&gPenEditorCompositionInputBox, pos.x, pos.y);
                    gdi_layer_lock_frame_buffer();
                    if ((INPUT_MODE_TR_BOPOMO == MMI_current_input_mode ||
                         INPUT_MODE_SM_PINYIN == MMI_current_input_mode) &&
                        PEN_EDITOR_CANDIDATE_ON_AND_FOCUS == g_pen_editor_composition_state.candidate_state)
                    {
                        mmi_pen_editor_set_compositon_index(mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_position());
                        mmi_pen_editor_smart_bpmf_pinyin_set_syllable_by_index(mmi_pen_editor_get_compositon_index());
                    }
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();
                    return;
                }
                if (PEN_EDITOR_OUT_OF_RANGE != g_pen_editor_composition_state.pen_down_state)
				{
                    g_pen_editor_composition_state.pen_down_state = PEN_EDITOR_MOVE_OUT;
                }
                if (g_pen_editor_composition_state.right_arrow_state == PEN_EDITOR_ARROW_PRESS_DOWN)
                {
                    g_pen_editor_composition_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                }
                if (g_pen_editor_composition_state.left_arrow_state == PEN_EDITOR_ARROW_PRESS_DOWN)
                {
                    g_pen_editor_composition_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                }
            }
            break;

        case PEN_EDITOR_CONTROL_CANDIDATE_AREA:
            if (gPenEditorSelectCandidate)
            {
                if (g_pen_editor_candidate_state.arrow_enable)
                {
                    ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            gPenEditorCandidateInputBox.x - (((gPenEditorCandidateInputBox.grid_width << 1) + gPenEditorCandidateInputBox.grid_width) >> 2) - 1,
                            gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                            gPenEditorCandidateInputBox.grid_width >> 1,
                            ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                    if (ret && g_pen_editor_candidate_state.pen_down_state == PEN_EDITOR_IN_LEFT_ARROW)
                    {
                        g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_LEFT_ARROW;
                        gdi_layer_lock_frame_buffer();
                        mmi_pen_editor_hide_candidate_area();
                        gui_show_single_line_input_box(&gPenEditorCandidateInputBox);
                        if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_candidate_state.left_arrow_state)
                        {
                            g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                        }
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_LEFT,
                            g_pen_editor_candidate_state.left_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                            g_pen_editor_candidate_state.right_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                    ret = PEN_CHECK_BOUND(
                            pos.x,
                            pos.y,
                            gPenEditorCandidateInputBox.x + gPenEditorCandidateInputBox.width + (gPenEditorCandidateInputBox.grid_width >> 2) - 1,
                            gPenEditorCandidateInputBox.y + (gPenEditorCandidateInputBox.height >> 3),
                            gPenEditorCandidateInputBox.grid_width >> 1,
                            ((gPenEditorCandidateInputBox.height << 1) + gPenEditorCandidateInputBox.height) >> 2);
                    if (ret && g_pen_editor_candidate_state.pen_down_state == PEN_EDITOR_IN_RIGHT_ARROW)
                    {
                        g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_RIGHT_ARROW;
                        gdi_layer_lock_frame_buffer();
                        mmi_pen_editor_hide_candidate_area();
                        gui_show_single_line_input_box(&gPenEditorCandidateInputBox);
                        if (PEN_EDITOR_ARROW_PRESS_UP == g_pen_editor_candidate_state.right_arrow_state)
                        {
                            g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_DOWN;
                        }
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_LEFT,
                            g_pen_editor_candidate_state.left_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        mmi_pen_editor_draw_arrow(
                            PEN_EDITOR_ARROW_DIRECTION_RIGHT,
                            g_pen_editor_candidate_state.right_arrow_state,
                            PEN_EDITOR_ARROW_FOR_CANDIDATE);
                        gdi_layer_unlock_frame_buffer();
                        gdi_lcd_repaint_all();
                        return;
                    }
                }
                ret = gui_single_line_input_box_translate_pen_event(
                        &gPenEditorCandidateInputBox,
                        MMI_PEN_EVENT_MOVE,
                        pos.x,
                        pos.y,
                        &single_line_input_box_event);
                if (ret)
                {
                    UI_character_type ch, ch1, ch2;

                    g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_IN_CONTROL;
                    gui_cancel_timer(mmi_pen_editor_confirm_selection);
                    gPenEditorActiveControl = PEN_EDITOR_CONTROL_CANDIDATE_AREA;
                    gui_show_single_line_input_box_ext(&gPenEditorCandidateInputBox, pos.x, pos.y);
                    if (!gui_single_line_input_box_test_last_position(&gPenEditorCandidateInputBox))
                    {
                        gui_single_line_input_box_next(&gPenEditorCandidateInputBox);
                    }
                    ch1 = *(gPenEditorCandidateInputBox.current_text_p - 2);
                    ch2 = *(gPenEditorCandidateInputBox.current_text_p - 1);
                    ch = ch1 | (ch2 << 8);
                    g_pen_editor_candidate_state.selected_candidate = ch;
                    gdi_layer_lock_frame_buffer();
                    switch (gPenEditorInputBoxType)
                    {
                            /* W05.32 Fix typo error */
                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                            multiline_inputbox_multitap_input(ch);
                            break;
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            EMS_inputbox_multitap_input(ch);
                            break;
                        case PEN_EDITOR_INLINE_TEXT:                            
                            inline_edit_singleline_inputbox_multitap_input(ch);
                            break;
                        default:
                            break;
                    }
                    mmi_pen_editor_show_candidate_area(
                        g_pen_editor_candidate_state.arrow_enable,
                        g_pen_editor_candidate_state.candidate_state);
                    gdi_layer_unlock_frame_buffer();
                    gdi_lcd_repaint_all();
                    return;
                }
                if (PEN_EDITOR_OUT_OF_RANGE != g_pen_editor_candidate_state.pen_down_state)
				{
                    g_pen_editor_candidate_state.pen_down_state = PEN_EDITOR_MOVE_OUT;
                }
                if (g_pen_editor_candidate_state.right_arrow_state == PEN_EDITOR_ARROW_PRESS_DOWN)
                {
                    g_pen_editor_candidate_state.right_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                }
                if (g_pen_editor_candidate_state.left_arrow_state == PEN_EDITOR_ARROW_PRESS_DOWN)
                {
                    g_pen_editor_candidate_state.left_arrow_state = PEN_EDITOR_ARROW_PRESS_UP;
                }
            }
            break;

        case PEN_EDITOR_CONTROL_IME_BUTTON:
            break;

        case PEN_EDITOR_CONTROL_MULTITAP:
            ret = gui_multitap_input_translate_pen_position(gPenEditorMultitapInput, pos.x, pos.y, &multitap_index);
            if (ret)
            {

            }
            break;

        case PEN_EDITOR_CONTROL_NONE:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    if (MMI_FALSE == ret)
    {
        wgui_general_pen_move_hdlr(pos);
    }
}
#endif /* !defined(__MMI_HANDWRITING_PAD__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_pen_set_stroke_color
 * DESCRIPTION
 *  Set the color of the stroke
 * PARAMETERS
 *  stroke_color        [IN]        The desired color of the stroke
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_pen_set_stroke_color(color stroke_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorStrokeColor = stroke_color;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_setup_input_box
 * DESCRIPTION
 *  Set the related setting for the handwriting componemt
 * PARAMETERS
 *  stroke_area                 [IN]        The original stroke area (most exculde the title, virtual keyboard, and soft key)
 *  ext_stroke                  [IN]        The stroke area after stroke (most the full screen)
 *  input_type                  [IN]        The current input type used to set the virtual keyboard and some functions
 *  information_bar_flag        [IN]        The information bar is enabled or not
 *  input_box_type              [IN]        Which kind of input box is active
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_setup_input_box(
        mmi_pen_handwriting_area_struct *stroke_area,
        mmi_pen_handwriting_area_struct *ext_stroke,
        U16 input_type,
        U8 information_bar_flag,
        mmi_pen_editor_input_box_type_enum input_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_type_only = input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_HANDWRITING_MULTI_BLOCK__)
    if (PEN_EDITOR_MULTILINE_INPUT_BOX == input_box_type||
        PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == input_box_type||
        PEN_EDITOR_EMS_INPUT_BOX == input_box_type)
    {
        mmi_pen_editor_set_handwriting_style(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK);
    }
    else
#endif /* defined(__MMI_HANDWRITING_MULTI_BLOCK__) */ 
    {
        mmi_pen_editor_set_handwriting_style(PEN_EDITOR_HANDWRITING_STYLE_FULL_SCREEN);
    }

	mmi_pen_editor_setup_create_layer_and_register_pen_handler(stroke_area, ext_stroke, input_type_only);

    mmi_pen_editor_setup_create_candidate_and_composition_box();

    gPenEditorInputBoxType = input_box_type;

    if ((PEN_EDITOR_DATE == gPenEditorInputBoxType)
        || (PEN_EDITOR_IP4 == gPenEditorInputBoxType)
        || (PEN_EDITOR_TIME == gPenEditorInputBoxType) || (PEN_EDITOR_TIME_PERIOD == gPenEditorInputBoxType))
    {
        MMI_current_input_mode = INPUT_MODE_123;
    }

    //W05.36 Disable switch Input Method when INPUT_TYPE_NUMERIC
    //W05.36 Add Center Soft Key for switching Input Method
    if (!(INPUT_TYPE_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_PHONE_NUMBER == input_type_only
          || INPUT_TYPE_SAT_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_KEYPAD_NUMERIC == input_type_only
          || INPUT_TYPE_DECIMAL_NUMERIC == input_type_only
          || INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_ALPHABATIC_LOWERCASE == input_type_only
          || INPUT_TYPE_ALPHABATIC_UPPERCASE == input_type_only
          || INPUT_TYPE_NUMERIC_SYMBOL == input_type_only 
          || INPUT_TYPE_NUMERIC == input_type_only
	      || INPUT_TYPE_SIGNED_NUMERIC == input_type_only
          || INPUT_TYPE_SIGNED_DECIMAL_NUMERIC == input_type_only
          || INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_SIGNED_NUMERIC_PASSWORD == input_type_only))
    {
        if (information_bar_flag)
        {
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_INFORMATION_BAR);
        }
    #ifdef __MMI_WGUI_CSK_ENABLE__
        if (!((PEN_EDITOR_DATE == gPenEditorInputBoxType)
              || (PEN_EDITOR_IP4 == gPenEditorInputBoxType)
              || (PEN_EDITOR_TIME == gPenEditorInputBoxType) 
	      || (PEN_EDITOR_TIME_PERIOD == gPenEditorInputBoxType)
	      || (PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR == gPenEditorInputBoxType)))
        {
            mmi_pen_editor_set_CSK_content();
            set_softkey_function(mmi_pen_editor_switch_input_method, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
            register_softkey_handler(MMI_CENTER_SOFTKEY);
        }
    #endif /* __MMI_WGUI_CSK_ENABLE__ */ 
    }

    mmi_pen_editor_setup_virtual_keyboard(input_type_only);

    mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_IME_BUTTON);

    //W05.44 Draw Manager will free the stroke layer
    //gPenEditorGDIHandler = NULL;

    gPenEditorFirstStroke = MMI_TRUE;
    mmi_pen_editor_pen_set_stroke_color(PhnsetGetHandwritingColor());
    gPenEditorHWSpeed = PhnsetGetHandwritingSpeed();

    /* W06.09 Touch Screen With Keypad V1 */
    /* mmi_pen_editor_clear_key_handler(); */
    if (gPenEditorInputBoxType != PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR)
    {
        mmi_pen_editor_setup_input_by_keypad(input_type_only);
    }

    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
    {
        if (MMI_virtual_keyboard.height <= gPenEditorCandidateInputBox.height)
        {
            wgui_move_virtual_keyboard(
                MMI_virtual_keyboard.x,
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + 3);
        }
        else
        {
            int different_height = MMI_virtual_keyboard.height - gPenEditorCandidateInputBox.height;

            wgui_move_virtual_keyboard(
                MMI_virtual_keyboard.x,
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT - different_height);
        }
	    gui_move_single_line_input_box(
			    &gPenEditorCandidateInputBox, 
			    gPenEditorCandidateInputBox.x, 
			    MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + 3);

		gui_move_single_line_input_box(
			    &gPenEditorCompositionInputBox, 
			    gPenEditorCompositionInputBox.x, 
			    gPenEditorCandidateInputBox.y - gPenEditorCompositionInputBox.height - 2);
    }

    if (!g_pen_editor_resize_by_vk)
        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    SetLeftSoftkeyAlwaysKeyUpByPen();
    SetRightSoftkeyAlwaysKeyUpByPen();
#ifdef __MMI_WGUI_CSK_ENABLE__
    SetCenterSoftkeyAlwaysKeyUpByPen();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_setup_create_layer_and_register_pen_handler
 * DESCRIPTION
 *  Create layer and register pen handler
 * PARAMETERS
 *  stroke_area    [IN]     The original stroke area (most exculde the title, virtual keyboard, and soft key)
 *  ext_stroke     [IN]     The stroke area after stroke (most the full screen)
 *  input_type     [IN]     The current input type used to set the virtual keyboard and some functions
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_pen_editor_setup_create_layer_and_register_pen_handler(mmi_pen_handwriting_area_struct *stroke_area,
                                                                 mmi_pen_handwriting_area_struct *ext_stroke,
                                                                 U16 input_type_only)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != stroke_area) &&
        (NULL != ext_stroke) &&
        !(INPUT_TYPE_NUMERIC_PASSWORD == input_type_only ||
          INPUT_TYPE_SIGNED_NUMERIC_PASSWORD == input_type_only ||
	     INPUT_TYPE_SAT_NUMERIC_PASSWORD == input_type_only) &&
        (!mmi_pen_editor_get_handwriting_state()))
    {
        gPenEditorEnableHandWriting = MMI_TRUE;
        if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style())
        {
		       mmi_pen_editor_set_multi_block_stroke_area(0,
			   	                                                                3, 
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT +
				                                                                mmi_pen_editor_compute_candidate_input_box_height() + 5,
				                                                                (UI_device_width >> 1) - 2,
				                                                                MMI_content_y + MMI_content_height - 3);
                    mmi_pen_editor_set_multi_block_stroke_area(1,
						                                                    (UI_device_width >> 1) + 2,
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT +
				                                                                 mmi_pen_editor_compute_candidate_input_box_height() + 5,
				                                                                 UI_device_width - 4,
				                                                                 MMI_content_y + MMI_content_height - 3);
            mmi_pen_start_capture_strokes(
                PEN_EDITOR_STROKE_BUFFER_SIZE,
				 mmi_pen_editor_get_stroke_buffer(),
                2,
				 mmi_pen_editor_get_multi_block_stroke_area(),
                NULL);
			 memcpy(mmi_pen_editor_get_original_handwriting_area(), stroke_area, sizeof(mmi_pen_handwriting_area_struct));
            mmi_pen_register_stroke_down_handler(mmi_pen_editor_multi_block_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(NULL, NULL, mmi_pen_editor_multi_block_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_pen_editor_multi_block_stroke_up_handler);
            wgui_virtual_keyboard_set_global_multi_block_mode(MMI_TRUE);
        }
        else
        {
        
            mmi_pen_start_capture_strokes(
                PEN_EDITOR_STROKE_BUFFER_SIZE,
				 mmi_pen_editor_get_stroke_buffer(),
                1,
                stroke_area,
                ext_stroke);
			 memcpy(mmi_pen_editor_get_original_handwriting_area(), stroke_area, sizeof(mmi_pen_handwriting_area_struct));
            mmi_pen_register_stroke_down_handler(mmi_pen_editor_stroke_down_handler);
            mmi_pen_register_stroke_move_handler(NULL, NULL, mmi_pen_editor_stroke_move_handler);
            mmi_pen_register_stroke_up_handler(mmi_pen_editor_stroke_up_handler);
        }

        /* W05.39 Call these functions only when enabling handwriting */
       mmi_pen_editor_hand_writing_initialize(); 
        
        mmi_pen_begin_strokes_of_character();
    }

#if !defined(__MMI_HANDWRITING_PAD__)
    mmi_pen_register_abort_handler(mmi_pen_editor_pen_abort_handler);
    mmi_pen_register_down_handler(mmi_pen_editor_pen_down_handler);
    mmi_pen_register_long_tap_handler(mmi_pen_editor_pen_long_tap_handler);
    mmi_pen_register_move_handler(mmi_pen_editor_pen_move_handler);
    mmi_pen_register_up_handler(mmi_pen_editor_pen_up_handler);
    mmi_pen_register_repeat_handler(mmi_pen_editor_pen_repeat_handler);
#endif /* !defined(__MMI_HANDWRITING_PAD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_setup_create_candidate_and_composition_box
 * DESCRIPTION
 *  Create candidate and composition box
 * PARAMETERS
    void
 * RETURNS
 *  void
 *****************************************************************************/
 static void  mmi_pen_editor_setup_create_candidate_and_composition_box(void)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 S32 grid_width = 0;
     S32 font_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    /*
     * font_height = UI_get_font_height(candidate_singleline_inputbox_theme.text_font) + 2;
     * if (font_height < MMI_multitap_height)
     * {
     * font_height = MMI_multitap_height;
     * }
    */
    font_height = mmi_pen_editor_compute_candidate_input_box_height();
    grid_width = (S32)(((float)(MMI_multitap_width) / (float)(PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS + 2)) + 0.5);


    gui_create_single_line_input_box_use_buffer(
        &gPenEditorCandidateInputBox,
        MMI_multitap_x + grid_width,
        MMI_content_y + MMI_content_height - font_height,
        grid_width * PEN_EDITOR_CANDIDATE_SIZE,
        font_height,
        gPenEditorCandidateBuffer,
        ((PEN_EDITOR_MAX_CANDIDATE_SIZE + 1) * sizeof(U16)));
    gui_set_single_line_input_box_theme(&gPenEditorCandidateInputBox, &candidate_singleline_inputbox_theme);
    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING;
    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
    gPenEditorCandidateInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS;
    gPenEditorCandidateInputBox.ext_flags |= UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID;
    //W05.35 Temp Solution for Candidates List Grid Width
    //W05.39 Adjust the grid width by the number of characters in Candidate List
    gPenEditorCandidateInputBox.text_x = 0;
    gPenEditorCandidateInputBox.grid_width = grid_width;
    g_pen_editor_candidate_x = MMI_multitap_x + grid_width;
    gui_create_single_line_input_box_use_buffer(
        &gPenEditorCompositionInputBox,
        MMI_multitap_x,
        gPenEditorCandidateInputBox.y - font_height - 2,
        MMI_multitap_width,
        font_height,
        g_pen_editor_composition_buffer,
        ((PEN_EDITOR_MAX_COMPOSITION_SIZE + 1) * sizeof(U16)));
    gui_set_single_line_input_box_theme(&gPenEditorCompositionInputBox, &candidate_singleline_inputbox_theme);
    gPenEditorCompositionInputBox.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    gPenEditorCompositionInputBox.grid_width = grid_width;

	 mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_COMPOSITION_AREA);
     mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_CANDIDATE_AREA);
 }


 /*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_setup_virtual_keyboard
 * DESCRIPTION
 *  Setup virtual keyboard and add control set
 * PARAMETERS
 *  input_type_only   [IN]    The input type
 * RETURNS
 *  void
 *****************************************************************************/
 static void  mmi_pen_editor_setup_virtual_keyboard(U16 input_type_only)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S32 changed_height = 0;
	 static MMI_BOOL is_init = MMI_FALSE;
     gui_virtual_keyboard_language_enum temp_vk_type;
	 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 mmi_pen_editor_set_history_vk_type(GUI_VIRTUAL_KEYBOARD_MAX_LANG);

    /* W05.32 History Issue */
    if (MMI_FALSE == is_init)
    {
        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY);
        is_init = MMI_TRUE;
    }

    if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type) &&
        !(PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == gPenEditorInputBoxType))
    {
        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
    }
    
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            /* W05.32 Check special input type for virtual keyboard */
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            temp_vk_type = mmi_pen_editor_get_vk_type_by_input_type(input_type_only);

            if (temp_vk_type != 0xFF)
            {
                if (input_type_only == INPUT_TYPE_NUMERIC_CHANGEABLE)
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
                else if (!((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                         (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)))
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
            }
        #endif /*__MMI_EDITOR_PEN_VK_UNFOLD__*/
            switch (input_type_only)
            {
                case INPUT_TYPE_PHONE_NUMBER:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
                case INPUT_TYPE_KEYPAD_NUMERIC:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_DECIMAL_NUMERIC:
		        case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY);
                    break;

                case INPUT_TYPE_NUMERIC:
                case INPUT_TYPE_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
                    break;

		        case INPUT_TYPE_SIGNED_NUMERIC:
		        case INPUT_TYPE_SIGNED_NUMERIC_PASSWORD:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
		  	        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER);
			        break;

                default:
                    break;
            }
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_MULTILINE_INPUT_BOX);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_MULTITAP);
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            temp_vk_type = mmi_pen_editor_get_vk_type_by_input_type(input_type_only);

            if (temp_vk_type != 0xFF)
            {
                if (input_type_only == INPUT_TYPE_NUMERIC_CHANGEABLE)
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
                else if (!((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                         (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)))
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
            }
        #endif /*__MMI_EDITOR_PEN_VK_UNFOLD__*/
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_EMS_INPUT_BOX);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_MULTITAP);
            break;

        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            /* W05.32 Check special input type for virtual keyboard */
            switch (input_type_only)
            {
                case INPUT_TYPE_PHONE_NUMBER:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
                case INPUT_TYPE_KEYPAD_NUMERIC:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_DECIMAL_NUMERIC:   
		        case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:	    
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY);
                    break;

                case INPUT_TYPE_NUMERIC:
                case INPUT_TYPE_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
                    break;


		        case INPUT_TYPE_SIGNED_NUMERIC:
		        case INPUT_TYPE_SIGNED_NUMERIC_PASSWORD:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
		  	        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER);
			        break;


                default:
                    break;
            }
            mmi_pen_editor_set_inputbox_LSK_Function(wgui_inline_edit_DONE_function);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_INLINE_MULTILINE_INPUT_BOX);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_MULTITAP);
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            temp_vk_type = mmi_pen_editor_get_vk_type_by_input_type(input_type_only);

            if (temp_vk_type != 0xFF)
            {
                if (input_type_only == INPUT_TYPE_NUMERIC_CHANGEABLE)
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
                else if (!((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                         (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)))
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
            }
        #endif /*__MMI_EDITOR_PEN_VK_UNFOLD__*/
            switch (input_type_only)
            {
                case INPUT_TYPE_PHONE_NUMBER:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
                case INPUT_TYPE_KEYPAD_NUMERIC:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_DECIMAL_NUMERIC:
		        case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY);
                    break;

                case INPUT_TYPE_NUMERIC:
                case INPUT_TYPE_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
                    break;


		        case INPUT_TYPE_SIGNED_NUMERIC:
		        case INPUT_TYPE_SIGNED_NUMERIC_PASSWORD:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
		  	        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER);
			        break;

                default:
                    /* MMI_ASSERT(0); */
                    break;
            }
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX);
            break;

		 case PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR:
            switch (input_type_only)
            {
				case INPUT_TYPE_NUMERIC:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
                    break;

                default:
                    /* MMI_ASSERT(0); */
                    break;
            }
            break;

        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            //W06.04 Fix category200 history issue of virtual keyboard
            //W06.06 Set virtual keyboard according to the input method
            if ((GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type))
            {
		        temp_vk_type = mmi_pen_editor_get_vk_type_by_input_type_for_quick_search(input_type_only);

		        if (temp_vk_type == 0xFF)
		        {
		            //MMI_ASSERT(0);
		            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ENGLISH);
		        }
		        else
		        {
	                    wgui_setup_virtual_keyboard(temp_vk_type);
		        }
            }
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_SINGLE_LINE_INPU_BOX);
            break;

        case PEN_EDITOR_INLINE_TEXT:
            if (mmi_pen_editor_is_valid_input_type_for_inline_editor(input_type_only) == MMI_TRUE)
            {
            changed_height = MMI_virtual_keyboard.height;
            
        #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
            temp_vk_type = mmi_pen_editor_get_vk_type_by_input_type(input_type_only);

            if (temp_vk_type != 0xFF && !mmi_pen_editor_need_to_hide_to_tray_or_not())
            {
                if (!((GUI_VIRTUAL_KEYBOARD_SYMBOL == MMI_virtual_keyboard.lang_type) ||
                         (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)))
                {
                    wgui_setup_virtual_keyboard(temp_vk_type);
                }
            }
        #endif /*__MMI_EDITOR_PEN_VK_UNFOLD__*/
        
            switch (input_type_only)
            {
                case INPUT_TYPE_PHONE_NUMBER:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
                case INPUT_TYPE_KEYPAD_NUMERIC:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
                    break;

                case INPUT_TYPE_DECIMAL_NUMERIC:
   		        case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY);
                    break;

                case INPUT_TYPE_NUMERIC:
                case INPUT_TYPE_NUMERIC_PASSWORD:
                    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
                    break;

		        case INPUT_TYPE_SIGNED_NUMERIC:
		        case INPUT_TYPE_SIGNED_NUMERIC_PASSWORD:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
		        case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
		  	        wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER);
			        break;

                default:
                    /* MMI_ASSERT(0); */
                    break;
            }
	    }
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_INLINE_TEXT);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_MULTITAP);
            break;

        case PEN_EDITOR_DATE:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_DATE);
            break;

        case PEN_EDITOR_IP4:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_IP4);
            break;

        case PEN_EDITOR_TIME:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_TIME);
            break;

        case PEN_EDITOR_TIME_PERIOD:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
            mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_TIME_PERIOD);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    if (!(INPUT_TYPE_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_SIGNED_NUMERIC_PASSWORD == input_type_only
          || INPUT_TYPE_SAT_NUMERIC_PASSWORD == input_type_only)
          || !(PEN_EDITOR_SINGLE_LINE_INPU_BOX == gPenEditorInputBoxType)
    #ifdef UI_SMALL_PIN_EDITOR_SCREEN
          || whether_no_small_screen()
    #endif
        )
    {
        mmi_pen_editor_add_cocontrol(&gPenEditorControlSet, PEN_EDITOR_CONTROL_VIRTUAL_KEYBOARD);
    }

	mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
      mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_FALSE);
    gPenEditorShowVK = MMI_TRUE;
	mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
    wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_FALSE);
 }


  /*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_setup_input_by_keypad
 * DESCRIPTION
 *  Setup input by keypad by input mode
 * PARAMETERS
 *  input_type_only  [IN]  Input type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_setup_input_by_keypad(U16 input_type_only)
 {

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 mmi_pen_editor_set_active_multitap_index(-1);
    g_pen_editor_hold_confirm = MMI_FALSE;
       mmi_pen_editor_set_smart_latin_pre_candidate_length(0);	 
	 mmi_pen_editor_set_smart_latin_candidate_index(0);
    g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
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
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
    /* W06.09 Touch Screen With Keypad V1 */
    if (wgui_handle_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN] ||
        handle_category28_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN] ||
        wgui_handle_qsearch_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN] ||
        wgui_handle_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN] ||
        wgui_handle_inline_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN] ||
        wgui_handle_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] ||
        handle_category28_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] ||
        wgui_handle_qsearch_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] ||
        wgui_handle_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] ||
        wgui_handle_inline_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] ||
#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
        wgui_handle_inputbox_change_input_mode_bymultitapthai == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] || 
        wgui_handle_qsearch_change_input_mode_bymultitapthai == currKeyFuncPtrs[KEY_POUND][KEY_LONG_PRESS] || 
#endif
        INPUT_MODE_TR_MULTITAP_BOPOMO == MMI_current_input_mode ||
        INPUT_MODE_SM_MULTITAP_PINYIN == MMI_current_input_mode ||
        INPUT_MODE_TR_BOPOMO == MMI_current_input_mode ||
        INPUT_MODE_SM_PINYIN == MMI_current_input_mode ||
        INPUT_MODE_TR_STROKE == MMI_current_input_mode ||
        INPUT_MODE_SM_STROKE == MMI_current_input_mode ||
        ((IME_LANG_ATTR_ALPHABETIC & mmi_pen_editor_get_Lang_special_attrib_by_input_mode(MMI_current_input_mode)) &&
        (IME_MODE_ATTR_SMART & mmi_pen_editor_get_mode_special_attrib_by_input_mode(MMI_current_input_mode))))
    {
		if (!(INPUT_TYPE_NUMERIC_PASSWORD == input_type_only
			|| INPUT_TYPE_PHONE_NUMBER == input_type_only
			|| INPUT_TYPE_SAT_NUMERIC_PASSWORD == input_type_only
			|| INPUT_TYPE_KEYPAD_NUMERIC == input_type_only
			|| INPUT_TYPE_DECIMAL_NUMERIC == input_type_only
			|| INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD == input_type_only
			|| INPUT_TYPE_ALPHABATIC_LOWERCASE == input_type_only
			|| INPUT_TYPE_ALPHABATIC_UPPERCASE == input_type_only
            || INPUT_TYPE_NUMERIC_SYMBOL == input_type_only 
		    || INPUT_TYPE_SIGNED_NUMERIC == input_type_only
	        || INPUT_TYPE_SIGNED_DECIMAL_NUMERIC == input_type_only
	        || INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD == input_type_only
	        || INPUT_TYPE_SIGNED_NUMERIC_PASSWORD == input_type_only
            || INPUT_TYPE_NUMERIC == input_type_only))
		{
			if (!((PEN_EDITOR_DATE == gPenEditorInputBoxType)
			      || (PEN_EDITOR_IP4 == gPenEditorInputBoxType)
                              || (PEN_EDITOR_TIME == gPenEditorInputBoxType) 
			      || (PEN_EDITOR_TIME_PERIOD == gPenEditorInputBoxType)
			      || (PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR == gPenEditorInputBoxType)))
			{
			#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
                SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_LONG_PRESS);
                SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_REPEAT);
            #else
                            SetKeyHandler(mmi_pen_editor_switch_input_method, KEY_POUND, KEY_EVENT_DOWN);
            #endif /*__MMI_MULTITAP_FOR_STAR_AND_POUND__*/
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_close_input_box
 * DESCRIPTION
 *  Reset the state when exiting handwriting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_close_input_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.32 History Issue */
    mmi_pen_editor_set_history_vk_type(MMI_virtual_keyboard.lang_type);
    changed_height = MMI_virtual_keyboard.height;
    /* W05.44 If the user does not select the candidate and quit the input box, help the user to select the candiadte */
    if (gPenEditorSelectCandidate)
    {
        mmi_pen_editor_confirm_selection();
    }
    //Disable Hand Writing
    //W06.03 Reentering stroke mode after mmi_pen_stop_capture_strokes because of mmi_pen_change_handwriting_area
    mmi_pen_stop_capture_strokes();
    gPenEditorEnableHandWriting = MMI_FALSE;
    //Reset Pen Event Queue
    //Flush pen event queue in mmi_pen_stop_capture_strokes instead of mmi_pen_reset here
    //Clear stroke event handler as nothing
    //mmi_pen_reset();
    //W05.43 clear stroke layer for category57
#ifdef MMI_PEN_EDITOR_ON_2_LAYER    
    mmi_pen_editor_restore_blt_layer();
#else /* MMI_PEN_EDITOR_ON_2_LAYER */
    if (gPenEditorGDIHandler != NULL && *gPenEditorGDIHandler != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */
    mmi_pen_register_stroke_down_handler(mmi_pen_dummy_hdlr);
    mmi_pen_register_stroke_move_handler(NULL, NULL, mmi_pen_dummy_hdlr);
    mmi_pen_register_stroke_up_handler(mmi_pen_dummy_hdlr);
    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY);
    gui_cancel_timer(mmi_pen_editor_stroke_up_timer_handler);
    g_stroke_up_timer_is_on = MMI_FALSE;
    gui_cancel_timer(mmi_pen_editor_confirm_selection);
#if defined(__MMI_HANDWRITING_WORD_PREDICTION__)
    gui_cancel_timer(mmi_pen_editor_show_word_prediction);
#endif
    mmi_pen_editor_reset_control_set(&gPenEditorControlSet);
    mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
    wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_FALSE);
    gPenEditorActiveControl = PEN_EDITOR_CONTROL_NONE;
    mmi_pen_editor_set_candidate_index(0);
    mmi_pen_editor_set_candidate_page(0);
    mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_FALSE);
    g_pen_editor_hold_confirm = MMI_FALSE;
    mmi_pen_editor_set_show_vk_at_start_or_not(MMI_FALSE);
    mmi_pen_editor_set_handwriting_disabled_or_not(MMI_FALSE);
   mmi_pen_editor_set_vk_disabled_or_not(MMI_FALSE);
    g_pen_editor_disable_keypad = MMI_FALSE;
    mmi_pen_editor_set_smart_latin_pre_candidate_length(0);    
    mmi_pen_editor_set_smart_latin_candidate_index(0);
    mmi_pen_editor_set_resized_by_vk_or_not(MMI_FALSE);
    mmi_pen_editor_smart_latin_unhighlight_candidate(MMI_FALSE);
    mmi_pen_editor_reset_key_sequence(mmi_pen_editor_get_key_sequence());
    wgui_virtual_keyboard_set_global_multi_block_mode(MMI_FALSE);
    mmi_pen_editor_reset_vk_key_set();
    g_not_resize_input_box = MMI_FALSE;
    g_input_box_changed_height = -1;
#ifdef __MMI_WGUI_CSK_ENABLE__
    /* W05.36 Add Center Soft Key for switching Input Method */
    set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
    set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
    //W06.09 Draw Center Softkey when entering new screen instead of drawing here
    //But in in-line editor, redrawing is needed when completing in-line item
    //redraw_softkey(MMI_CENTER_SOFTKEY);
    clear_softkey_handler(MMI_CENTER_SOFTKEY);
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 

   mmi_pen_editor_hand_writing_deinitialize();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_show_component
 * DESCRIPTION
 *  Empty function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_show_component(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_add_cocontrol
 * DESCRIPTION
 *  Add the pen editor control to the control sets
 * PARAMETERS
 *  peneditorcontrolset     [OUT]       The Control Set to be added
 *  peneditorcontrol        [IN]        The Control to add
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_add_cocontrol(
        mmi_pen_editor_control_set_struct *peneditorcontrolset,
        mmi_pen_editor_control_type_enum peneditorcontrol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    peneditorcontrolset->PenEditorControlSet[peneditorcontrolset->NumberofControlSets++] = peneditorcontrol;
    MMI_ASSERT(peneditorcontrolset->NumberofControlSets < PEN_EDITOR_MAX_CONTROL_SET_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_control_set
 * DESCRIPTION
 *  Reset the control stes
 * PARAMETERS
 *  peneditorcontrolset     [OUT]     The control set to be reset
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_control_set(mmi_pen_editor_control_set_struct *peneditorcontrolset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(peneditorcontrolset, 0, sizeof(mmi_pen_editor_control_set_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_check_valid_input
 * DESCRIPTION
 *  Check the input is in the valid input list or not
 * PARAMETERS
 *  input           [IN]        The character to check
 *  valid_input     [IN]        The valid input list
 * RETURNS
 *  MMI_TRUE  : Valid
 * 	MMI_FALSE : Invalid
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_check_valid_input(UI_character_type input, const UI_character_type *valid_input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0;; i++)
    {
        if (0 == valid_input[i])
        {
            return MMI_FALSE;
        }
        else if (input == valid_input[i])
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_input_character
 * DESCRIPTION
 *  Input the character c to the input box
 * PARAMETERS
 *  c               [IN]        The character to input
 *  needselect      [IN]        The candidate can be replaced or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_input_character(UI_character_type c, MMI_BOOL needselect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    MMI_BOOL is_last = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
    /* W05.32 Check the character is valid in somespecial input type or not */
    if (INPUT_TYPE_PHONE_NUMBER == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        if (MMI_current_input_ext_type & INPUT_TYPE_EXT_SIM_NUMERIC)
        {
            if (!mmi_pen_editor_check_valid_input(c, gPenEditorPhoneNumberSIMValidCharacters))
            {
                return;
            }
        }
        else
        {
            if (!mmi_pen_editor_check_valid_input(c, gPenEditorPhoneNumberValidCharacters))
            {
                return;
            }
        }
    }
    else if ((INPUT_TYPE_DECIMAL_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK))
		 || (INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK)))
    {
        if (!mmi_pen_editor_check_valid_input(c, gPenEditorDecimalNumericValidCharacters))
        {
            return;
        }
    }
    else if ((INPUT_TYPE_SIGNED_DECIMAL_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK))
             || (INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK)))
    {
        if (!mmi_pen_editor_check_valid_input(c, gPenEditorSignedDecimalNumericValidCharacters))
        {
            return;
        }
    }
    else if (INPUT_TYPE_KEYPAD_NUMERIC == (MMI_current_input_type & INPUT_TYPE_MASK)
             || INPUT_TYPE_SAT_NUMERIC_PASSWORD == (MMI_current_input_type & INPUT_TYPE_MASK))
    {
        if (!mmi_pen_editor_check_valid_input(c, gPenEditorKeyPadNumbericValidCharacters))
        {
            return;
        }
    }
    else if (MMI_allow_only_english_input_modes)
    {
        //W05.35 Temp Solution for European Dollar Sign Issue
        //W05.36 Correct for wrong way to check the input
        if ((c > 0xFF))
        {
            return;
        }
    }

    gdi_layer_lock_frame_buffer();
    if (needselect)
    {
        gPenEditorSelectCandidate = MMI_TRUE;
    }
    else
    {
        {
            if (mmi_pen_editor_get_vk_text_string_length() > 0)
            {
                mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
                wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_TRUE);
            }
            if (GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type
                || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
            {
                if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX != gPenEditorInputBoxType)
                {
                    mmi_pen_editor_hide_candidate_area();
                }
            }
        }
    }
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            if (needselect)
            {
                multiline_inputbox_multitap_input(c);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BY_STATE);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    multiline_inputbox_multitap_input(c);
                    /* Temp Solution for LSK Text Update */
                    gPenEditorSelectCandidate = MMI_FALSE;
                    mmi_pen_editor_set_left_soft_key();
                    register_multiline_inputbox_keys();
                    if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                    {
                        cat201_register_key_func();
                    }
                    multiline_inputbox_multitap_input_complete();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        /* W05.47 Change the Input Control Height when the VK is not Tray Type */
                        if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type)
                              && !(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()))
                        {
                            changed_height -= MMI_virtual_keyboard.height;
                            if (!mmi_pen_editor_is_there_vk_candidate_box())
                            {
                                changed_height += gPenEditorCandidateInputBox.height;
                            }
                            if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
                            {
                                mmi_pen_editor_resize_content_area(changed_height);
                            }
                            gui_move_single_line_input_box(
                                &gPenEditorCandidateInputBox,
                                gPenEditorCandidateInputBox.x,
                                MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                        }
                        mmi_pen_editor_hide_candidate_area();
                        /* W06.08 Avoid changing handwriting area when stroke down */
                        if (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL != MMI_virtual_keyboard.lang_type)
                        {
                            mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                        }
                    }
                }
                else
                {
                    if (wgui_multiline_inputbox_decimal_input_mode_flag && (c == (UI_character_type) '.'))
                    {
                        wgui_multiline_inputbox_decimal_numeric_handle_pound_key_down();
                    }
                    else
                    {	
						U16 input_type = MMI_current_input_type & INPUT_TYPE_MASK;
						if ((input_type == INPUT_TYPE_SIGNED_NUMERIC ||
						     input_type == INPUT_TYPE_SIGNED_NUMERIC_PASSWORD ||
						     input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC ||
						     input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD) &&
							 (c == (UI_character_type) '-'))
						{
							wgui_multiline_inputbox_signed_numeric_handle_star_key_down();
						}
						else
						{
							multiline_inputbox_direct_input(c);
						}
                    }
                }
            }
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            if (needselect)
            {
                EMS_inputbox_multitap_input(c);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BY_STATE);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    EMS_inputbox_multitap_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    mmi_pen_editor_set_left_soft_key();
                    register_EMS_inputbox_keys();
                    EMS_inputbox_multitap_input_complete();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        /* W05.47 Change the Input Control Height when the VK is not Tray Type */
                        if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
                              || GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL == MMI_virtual_keyboard.lang_type))
                        {
                            changed_height -= MMI_virtual_keyboard.height;
                            if (!mmi_pen_editor_is_there_vk_candidate_box())
                            {
                                changed_height += gPenEditorCandidateInputBox.height;
                            }
                            mmi_pen_editor_resize_content_area(changed_height);
                            gui_move_single_line_input_box(
                                &gPenEditorCandidateInputBox,
                                gPenEditorCandidateInputBox.x,
                                MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                        }
                        /* W06.08 Avoid changing handwriting area when stroke down */
                        if (GUI_VIRTUAL_KEYBOARD_CHINESE_SYMBOL != MMI_virtual_keyboard.lang_type)
                        {
                            mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                        }
                    }
                }
                else
                {
                    EMS_inputbox_direct_input(c);
                }
            }
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            if (needselect)
            {
                singleline_inputbox_multitap_input(c);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BY_STATE);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    singleline_inputbox_multitap_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    singleline_inputbox_multitap_input_complete();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        /* W05.32 Virtual Keyboard Display Issue in single Line Input Box */
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == gPenEditorInputBoxType)
                    {
                        if (cat200_search_function)
                        {
                            singleline_inputbox_direct_input(c);
                            refresh_search_list(MMI_singleline_inputbox.text);
                            RedrawCategoryFunction();
                        }
                    }
                    else
                    {
                        if (wgui_singleline_inputbox_decimal_input_mode_flag && (c == (UI_character_type) '.'))
                        {
                            wgui_singleline_inputbox_decimal_numeric_handle_pound_key_down();
                        }
                        else
                        {
				            U16 input_type = MMI_current_input_type & INPUT_TYPE_MASK;
				            if ((input_type == INPUT_TYPE_SIGNED_NUMERIC ||
				                 input_type == INPUT_TYPE_SIGNED_NUMERIC_PASSWORD ||
				                 input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC ||
				                 input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD) &&
					             (c == (UI_character_type) '-'))
				            {
					             wgui_singleline_inputbox_signed_numeric_handle_star_key_down();
				            }
				            else
				            {
					             singleline_inputbox_direct_input(c);
				            }				
                        }
                    }
                }
            }
            break;

        case PEN_EDITOR_INLINE_TEXT:
            if (needselect)
            {
                inline_edit_singleline_inputbox_multitap_input(c);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BY_STATE);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    inline_edit_singleline_inputbox_multitap_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    inline_edit_singleline_inputbox_multitap_input_complete();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    if (wgui_inline_singleline_inputbox_decimal_input_mode_flag && (c == (UI_character_type) '.'))
                    {
                        wgui_inline_singleline_inputbox_decimal_numeric_handle_pound_key_down();
                    }
                    else
                    {
				        U16 input_type = MMI_current_input_type & INPUT_TYPE_MASK;
				        if ((input_type == INPUT_TYPE_SIGNED_NUMERIC ||
				             input_type == INPUT_TYPE_SIGNED_NUMERIC_PASSWORD ||
				             input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC ||
				             input_type == INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD) &&
					         (c == (UI_character_type) '-'))
				        {
					        wgui_inline_singleline_inputbox_signed_numeric_handle_star_key_down();
				        }
				        else
				        {
					        inline_edit_singleline_inputbox_direct_input(c);
				        }
                    }
                }
            }
            break;

        case PEN_EDITOR_DATE:
            if (needselect)
            {
                if (date_input_test_last_position(current_date_input))
                {
                    is_last = MMI_TRUE;
                }
                date_input_direct_input_nodraw(c);
                if (!is_last)
                {
                    date_input_previous_character();
                }
                show_date_input(current_date_input);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BACK);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    date_input_direct_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    date_input_direct_input(c);
                }
            }
            break;

        case PEN_EDITOR_IP4:
            if (needselect)
            {
                if (IP4_input_test_last_position(current_IP4_input))
                {
                    is_last = MMI_TRUE;
                }
                IP4_input_direct_input_nodraw(c);
                if (!is_last)
                {
                    IP4_input_previous_character();
                }
                show_IP4_input(current_IP4_input);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BACK);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    IP4_input_direct_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                       mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    IP4_input_direct_input(c);
                }
            }
            break;

        case PEN_EDITOR_TIME:
            if (needselect)
            {
                if (time_input_test_last_position(current_time_input))
                {
                    is_last = MMI_TRUE;
                }
                time_input_direct_input_nodraw(c);
                if (!is_last)
                {
                    time_input_previous_character();
                }
                show_time_input(current_time_input);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BACK);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    time_input_direct_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    time_input_direct_input(c);
                }
            }
            break;

        case PEN_EDITOR_TIME_PERIOD:
            if (needselect)
            {
                if (time_period_input_test_last_position(current_time_period_input))
                {
                    is_last = MMI_TRUE;
                }
                time_period_input_direct_input_nodraw(c);
                if (!is_last)
                {
                    time_period_input_previous_character();
                }
                show_time_period_input(current_time_period_input);
                mmi_pen_editor_set_right_softkey(PEN_EDITOR_RSK_BACK);
            }
            else
            {
                if (gPenEditorSelectCandidate)
                {
                    time_period_input_direct_input(c);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
                    {
                        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                        mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    }
                }
                else
                {
                    time_period_input_direct_input(c);
                }
            }
            break;

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
	case PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR:
					wgui_paging_multiline_key_maaping_TS(c);
					break;
#endif

        default:
            MMI_ASSERT(0);
    }
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_handwriting_direct_input
 * DESCRIPTION
 *  Insert the recognizing result from handwriting to the input box directly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_handwriting_direct_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[10];
    int num = 0;
    mmi_pen_editor_input_type_enum hand_writing_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The end of the character, pass the stroke data for hand writing recognization */
    gdi_layer_lock_frame_buffer();
    gui_cancel_timer(mmi_pen_editor_stroke_up_timer_handler);
    g_stroke_up_timer_is_on = MMI_FALSE;
    mmi_pen_end_strokes_of_character();
    /* mmi_pen_end_strokes_of_character_with_dropping_last_point(); */
#if defined(__MMI_HAND_WRITING_GET_STROKES__)
    mmi_pen_editor_save_stroke_to_file();
#endif 
#ifdef MMI_PEN_EDITOR_ON_2_LAYER
    mmi_pen_editor_restore_blt_layer();
#else /* MMI_PEN_EDITOR_ON_2_LAYER */
    if (gPenEditorGDIHandler != NULL)
    {	
        gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
    }	
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */
    gPenEditorFirstStroke = MMI_TRUE;

    hand_writing_type = mmi_pen_editor_get_hand_writing_type_by_input_mode(MMI_current_input_mode);

    if (hand_writing_type != 0)
    {
            num = mmi_pen_editor_hand_writing_get_candidates(
                    (U16*) mmi_pen_editor_get_stroke_buffer(),
                    candidate_buffer,
                    hand_writing_type,
                    1);
    }

    if (num)
    {
        mmi_pen_editor_input_character(candidate_buffer[0], MMI_FALSE);
    }
    g_pen_editor_active_block = 0;
    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
    mmi_pen_begin_strokes_of_character();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_backspace
 * DESCRIPTION
 *  Backspace in the input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_backspace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.11 Set RSK after backspace in virtual keyboard */
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            if (wgui_multiline_inputbox_decimal_input_mode_flag)
            {
                wgui_handle_inputbox_right_softkey_down();
            }
            else
            {
                multiline_inputbox_delete_character();
            }
            wgui_set_RSK();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            EMS_inputbox_backspace();
            wgui_set_EMS_inputbox_RSK();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            if (wgui_singleline_inputbox_decimal_input_mode_flag)
            {
                wgui_handle_singleline_inputbox_right_softkey_down();
            }
            else
            {
                singleline_inputbox_delete_character();
            }
            if (cat200_search_function)
            {
                refresh_search_list(MMI_singleline_inputbox.text);
                RedrawCategoryFunction();
            }
            wgui_set_singleline_RSK();
            break;

        case PEN_EDITOR_INLINE_TEXT:
            /* W06.16 Temp Solution for RSK in Category57. Only delete the character when there is something. */
            if (gui_single_line_input_box_get_text_length(&MMI_inline_singleline_inputbox) > 0)
            {
                if (wgui_inline_singleline_inputbox_decimal_input_mode_flag)
                {
                    handle_inline_text_edit_right_softkey_down();
                }
                else
                {
                    inline_edit_singleline_inputbox_delete_character();
                }
                mmi_pen_editor_set_right_soft_key_inline_text();
            }
            else
            {
                UI_editor_play_tone_cannot_change();
            }
            break;

        case PEN_EDITOR_DATE:
            date_input_previous_character();
            break;

        case PEN_EDITOR_IP4:
            IP4_input_previous_character();
            break;

        case PEN_EDITOR_TIME:
            time_input_previous_character();
            break;

        case PEN_EDITOR_TIME_PERIOD:
            time_period_input_previous_character();
            break;

		case PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR:
			break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_bracket
 * DESCRIPTION
 *  Add brackets in the input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_bracket(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.36 Temp Solution Do nothing when there is candidates list */
    if (gPenEditorSelectCandidate)
    {
        return;
    }
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            if (gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, '(') == MMI_TRUE)
            {
                if (gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, ')') == MMI_TRUE)
                {
                    multiline_inputbox_previous_character();
                }
            }
            redraw_multiline_inputbox();
            multiline_inputbox_input_callback();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
        {
            //W06.03 EMS_get_remaining_length > 0 does not make sure that we could insert one more character
            //We check this by gui_EMS_input_box_insert_character
            U8 ret = gui_EMS_input_box_insert_character(&MMI_EMS_inputbox, '(');

            if (0 < EMS_get_remaining_length(MMI_EMS_inputbox.data) && (ret == EMS_OK))
            {
                if (gui_EMS_input_box_insert_character(&MMI_EMS_inputbox, ')') == EMS_OK)
                {
                    EMS_inputbox_previous();
                }
            }
            redraw_EMS_inputbox();
            EMS_inputbox_input_callback();
            break;
        }

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            if (0 < gui_single_line_input_box_get_remaining_length(&MMI_singleline_inputbox))
            {
                gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, '(');
                if (0 < gui_single_line_input_box_get_remaining_length(&MMI_singleline_inputbox))
                {
                    gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, ')');
                    singleline_inputbox_previous_character();
                }
                else
                {
                    gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, ')');
                }
            }
            else
            {
                gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, '(');            
            }
            redraw_singleline_inputbox();
            singleline_inputbox_input_callback();
            /* W05.52 Fix Quick Search Issue */
            if (cat200_search_function)
            {
                refresh_search_list(MMI_singleline_inputbox.text);
                RedrawCategoryFunction();
            }
            break;

        case PEN_EDITOR_INLINE_TEXT:
            gui_single_line_input_box_insert_character(&MMI_inline_singleline_inputbox, '(');
            if (0 < gui_single_line_input_box_get_remaining_length(&MMI_inline_singleline_inputbox))
            {
                gui_single_line_input_box_insert_character(&MMI_inline_singleline_inputbox, ')');
                inline_edit_singleline_inputbox_previous_character();
            }
            else
            {
                redraw_inline_singleline_inputbox();
            }
            inline_singleline_inputbox_input_callback();
            break;

        case PEN_EDITOR_DATE:
        case PEN_EDITOR_IP4:
        case PEN_EDITOR_TIME:
        case PEN_EDITOR_TIME_PERIOD:
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_new_line
 * DESCRIPTION
 *  Add "Enter (0x0A 0x0D)" symbol in the input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_new_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.48 If INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, do not insert new line */
    if (INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL & MMI_current_input_ext_type)
    {
        return;
    }
    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            gui_multi_line_input_box_insert_newline(&MMI_multiline_inputbox);
            redraw_multiline_inputbox();
            multiline_inputbox_input_callback();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            EMS_inputbox_insert_new_line();
            redraw_EMS_inputbox();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
        case PEN_EDITOR_INLINE_TEXT:
        case PEN_EDITOR_DATE:
        case PEN_EDITOR_IP4:
        case PEN_EDITOR_TIME:
        case PEN_EDITOR_TIME_PERIOD:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_resize_content_area
 * DESCRIPTION
 *  Resize the content area according to the changed height.
 * PARAMETERS
 *  changed_height      [IN]        The height to change
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_resize_content_area(int changed_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 input_box_bottom_y = -1; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == changed_height 
    #ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
        && !gPenEditorOnlyRedrawInputBox
    #endif /* __MMI_EDITOR_PEN_VK_UNFOLD__ */
       )
    {
        return;
    }

    switch (gPenEditorInputBoxType)
    {
    case PEN_EDITOR_MULTILINE_INPUT_BOX:
    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
    case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
        input_box_bottom_y = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height;
        break;
        
    case PEN_EDITOR_EMS_INPUT_BOX:
        input_box_bottom_y = MMI_EMS_inputbox.y + MMI_EMS_inputbox.height;
        break;
        
    case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
        input_box_bottom_y = MMI_singleline_inputbox.y + MMI_singleline_inputbox.height;
        break;
        
    case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
    case PEN_EDITOR_INLINE_TEXT:
    case PEN_EDITOR_DATE:
    case PEN_EDITOR_IP4:
    case PEN_EDITOR_TIME:
    case PEN_EDITOR_TIME_PERIOD:
    case PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR:
        input_box_bottom_y = -1;
        break;
        
    default:
        MMI_ASSERT(0);
        break;
    }

    if (input_box_bottom_y == -1)
    {
        return;
    }
    
    if (g_input_box_changed_height == -1)
    {
        g_input_box_changed_height = input_box_bottom_y - (MMI_content_y + MMI_content_height);
    }

    g_input_box_changed_height += changed_height;

    /* For fixed input box, when it should be enlarged
     * due to the resizing mechanism of EditorPen, 
     * clear the region below its bottom */
    if (g_not_resize_input_box)
    {
        if (changed_height > 0)
        {
            gui_reset_clip();
            gdi_layer_lock_frame_buffer();
            if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
            {
                gdi_draw_solid_rect(
                    0,
                    input_box_bottom_y,
                    UI_device_width - 1,
                    MMI_content_y + MMI_content_height + g_input_box_changed_height,
                    GDI_COLOR_TRANSPARENT);
            }
            else
            {
                gui_fill_rectangle(
                    0,
                    input_box_bottom_y,
                    UI_device_width - 1,
                    MMI_content_y + MMI_content_height + g_input_box_changed_height,
                    current_MMI_theme->general_background_filler->c);
            }
            gdi_layer_unlock_frame_buffer();
            gui_BLT_double_buffer(
                0,
                input_box_bottom_y,
                UI_device_width - 1,
                MMI_content_y + MMI_content_height + g_input_box_changed_height);
        }
        return;
    }

    switch (gPenEditorInputBoxType)
    {
        case PEN_EDITOR_MULTILINE_INPUT_BOX:
            gui_resize_multi_line_input_box(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.width,
                MMI_multiline_inputbox.height + changed_height);
            redraw_multiline_inputbox();
            break;

        case PEN_EDITOR_EMS_INPUT_BOX:
            gui_resize_EMS_input_box(
                &MMI_EMS_inputbox,
                MMI_EMS_inputbox.width,
                MMI_EMS_inputbox.height + changed_height);
            redraw_EMS_inputbox();
            break;

        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            gui_resize_multi_line_input_box(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.width,
                MMI_multiline_inputbox.height + changed_height);
            redraw_multiline_inputbox();
            break;

        case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
            break;

        case PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height + changed_height);
            /* W06.03 Adjust highlight position */
            gui_dynamic_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
            move_singleline_inputbox(MMI_singleline_inputbox.x, MMI_fixed_list_menu.y + MMI_fixed_list_menu.height + 1);
            break;

        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height + changed_height);
            gui_dynamic_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
            move_multiline_inputbox(
                MMI_multiline_inputbox.x,
                MMI_fixed_list_menu.y + MMI_fixed_list_menu.height + wgui_inputbox_information_bar_height);
            wgui_setup_input_information(
                MMI_multiline_inputbox.x,
                MMI_multiline_inputbox.y - wgui_inputbox_information_bar_height,
                MMI_multiline_inputbox.width,
                wgui_inputbox_information_bar_height);
            RedrawCategoryControlledArea201Screen();
            break;

        case PEN_EDITOR_INLINE_TEXT:
            break;

        case PEN_EDITOR_DATE:
            break;

        case PEN_EDITOR_IP4:
            break;

        case PEN_EDITOR_TIME:
            break;

        case PEN_EDITOR_TIME_PERIOD:
            break;

        case PEN_EDITOR_PAGING_IN_MULTLINE_EDITOR:
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_inline_text_item
 * DESCRIPTION
 *  Set the virtual keyboard and resize by in-line text item (Not Used Now)
 * PARAMETERS
 *  i       [IN]        The inline text item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_inline_text_item(const wgui_inline_item *i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    wgui_inline_item_text_edit *item_text =
        (wgui_inline_item_text_edit*) wgui_inline_items[wgui_inline_item_highlighted_index].item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    changed_height = MMI_virtual_keyboard.height;
    switch ((item_text->input_type) & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_ALPHANUMERIC_LOWERCASE:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_ENGLISH);
            break;

        case INPUT_TYPE_PHONE_NUMBER:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
            break;

        case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
        case INPUT_TYPE_KEYPAD_NUMERIC:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER);
            break;

        case INPUT_TYPE_DECIMAL_NUMERIC:
	    case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY);
            break;

        case INPUT_TYPE_NUMERIC:
            wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY);
            break;

	    case INPUT_TYPE_SIGNED_NUMERIC:
	    case INPUT_TYPE_SIGNED_NUMERIC_PASSWORD:
	    case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC:
	    case INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD:
	  	    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_NUMBER);
		    break;

        default:
            MMI_ASSERT(0);
            break;
    }
    changed_height -= MMI_virtual_keyboard.height;
    gPenEditorInputBoxType = PEN_EDITOR_INLINE_TEXT;
    mmi_pen_editor_resize_content_area(changed_height);
    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_right_soft_key_handler
 * DESCRIPTION
 *  Do the corresponding action for RSK according the state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_right_soft_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int candidatelength = 0;
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_hold_confirm = MMI_FALSE;
    
    if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
    {
        if (mmi_pen_editor_del_key_sequence(mmi_pen_editor_get_key_sequence()))
        {
            gdi_layer_lock_frame_buffer();
            if (mmi_pen_editor_get_key_sequence()->KeyLength)
            {
                candidatelength = mmi_ime_smart_latin_get_candidates_by_key_sequence(
                                    mmi_pen_editor_get_key_sequence()->KeySequence,
                                    mmi_pen_editor_get_key_sequence()->KeyLength,
                                    candidate_buffer);
                if (candidatelength)
                {
                    mmi_pen_editor_smart_latin_replace_candidate(candidate_buffer, candidatelength);
                }
            }
            else
            {
                mmi_pen_editor_set_smart_latin_pre_candidate_length(0);
                mmi_pen_editor_smart_latin_unhighlight_candidate(MMI_TRUE);
                mmi_pen_editor_set_left_soft_key();
                mmi_pen_editor_backspace();
                mmi_pen_editor_set_smart_latin_candidate_index(0);
                switch (gPenEditorInputBoxType)
                {
                    case PEN_EDITOR_EMS_INPUT_BOX:
                        register_EMS_inputbox_keys();
                        handle_category28_input();
                        wgui_set_EMS_inputbox_RSK();
                        break;

                    case PEN_EDITOR_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                        register_multiline_inputbox_keys();
                        wgui_handle_inputbox_input();
                        wgui_set_RSK();
                        break;

                    default:
                        break;
                }
            }
            gdi_layer_unlock_frame_buffer();
            gdi_lcd_repaint_all();
        }
        return;
    }

    if (g_pen_editor_composition_state.candidate_state == PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS &&
        (MMI_current_input_mode == INPUT_MODE_TR_STROKE || MMI_current_input_mode == INPUT_MODE_SM_STROKE))
    {
        if (mmi_pen_editor_del_key_sequence(mmi_pen_editor_get_key_sequence()))
        {
            gdi_layer_lock_frame_buffer();
            if (mmi_pen_editor_get_key_sequence()->KeyLength)
            {
                mmi_pen_editor_chinese_stroke_get_candidates_by_key_sequence(mmi_pen_editor_get_key_sequence(), MMI_TRUE);
            }
            else
            {
                int change_height = 0;

                g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
                change_height += (gPenEditorCompositionInputBox.height);
                if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                    || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                    || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                    || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type)
                    && !(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()))
                {
                    change_height -= MMI_virtual_keyboard.height;
                    if (!mmi_pen_editor_is_there_vk_candidate_box())
                    {
                        change_height += gPenEditorCandidateInputBox.height;
                    }
                    /* W05.36 For Clear Candidates Lsit Area when it need to display */
                    if (mmi_pen_editor_is_there_vk_candidate_box())
                    {
                        gui_move_single_line_input_box(
                            &gPenEditorCandidateInputBox,
                            gPenEditorCandidateInputBox.x,
                            MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                        /* W05.35 For Candidates Lsit Issue */
                        mmi_pen_editor_hide_candidate_area();
                    }
                }
                mmi_pen_editor_hide_composition_area();
                mmi_pen_editor_resize_content_area(change_height);
                mmi_pen_editor_set_left_soft_key();
                mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                gPenEditorSelectCandidate = MMI_FALSE;
                mmi_pen_editor_hide_candidate_area();
                mmi_pen_editor_change_handwriting_area();
                mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                switch (gPenEditorInputBoxType)
                {
                    case PEN_EDITOR_EMS_INPUT_BOX:
                        register_EMS_inputbox_keys();
                        handle_category28_input();
                        wgui_set_EMS_inputbox_RSK();
                        break;

                    case PEN_EDITOR_MULTILINE_INPUT_BOX:
                    case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                        register_multiline_inputbox_keys();
                        wgui_handle_inputbox_input();
                        wgui_set_RSK();
                        break;

                    default:
                        break;
                }
            }
            gdi_layer_unlock_frame_buffer();
            gdi_lcd_repaint_all();
        }
        return;
    }
    if (g_pen_editor_composition_state.candidate_state != PEN_EDITOR_CANDIDATE_OFF &&
        (MMI_current_input_mode == INPUT_MODE_TR_BOPOMO || MMI_current_input_mode == INPUT_MODE_SM_PINYIN))
    {
        gdi_layer_lock_frame_buffer();
        if (g_pen_editor_composition_state.candidate_state == PEN_EDITOR_CANDIDATE_ON_AND_FOCUS)
        {
            if (mmi_pen_editor_del_key_sequence(mmi_pen_editor_get_key_sequence()))
            {
                if (mmi_pen_editor_get_key_sequence()->KeyLength)
                {
                    mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(
                        mmi_pen_editor_get_key_sequence(),
                        MMI_TRUE, MMI_TRUE);
                    mmi_pen_editor_show_composition_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
                    mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
                }
                else
                {
                    int change_height = 0;

                    g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_OFF;
                    change_height += (gPenEditorCompositionInputBox.height);
                    if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                        || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                        || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                        || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type)
                        && !(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()))
                    {
                        change_height -= MMI_virtual_keyboard.height;
                        if (!mmi_pen_editor_is_there_vk_candidate_box())
                        {
                            change_height += gPenEditorCandidateInputBox.height;
                        }
                        /* W05.36 For Clear Candidates Lsit Area when it need to display */
                        if (mmi_pen_editor_is_there_vk_candidate_box())
                        {
                            gui_move_single_line_input_box(
                                &gPenEditorCandidateInputBox,
                                gPenEditorCandidateInputBox.x,
                                MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                            /* W05.35 For Candidates Lsit Issue */
                            mmi_pen_editor_hide_candidate_area();
                        }
                    }
                    mmi_pen_editor_hide_composition_area();
                    mmi_pen_editor_resize_content_area(change_height);
                    mmi_pen_editor_set_left_soft_key();
                    mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
                    gPenEditorSelectCandidate = MMI_FALSE;
                    mmi_pen_editor_hide_candidate_area();
                    mmi_pen_editor_change_handwriting_area();
                    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
                    switch (gPenEditorInputBoxType)
                    {
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            register_EMS_inputbox_keys();
                            handle_category28_input();
                            wgui_set_EMS_inputbox_RSK();
                            break;

                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                            register_multiline_inputbox_keys();
                            wgui_handle_inputbox_input();
                            wgui_set_RSK();
                            break;

                        default:
                            break;
                    }
                }
            }
        }
        else if (g_pen_editor_composition_state.candidate_state == PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS)
        {
            mmi_pen_editor_smart_bpmf_pinyin_get_candidates_by_key_sequence(mmi_pen_editor_get_key_sequence(), MMI_FALSE, MMI_TRUE);
            g_pen_editor_composition_state.candidate_state = PEN_EDITOR_CANDIDATE_ON_AND_FOCUS;
            mmi_pen_editor_show_composition_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
            mmi_pen_editor_set_syllable_confirmed_or_not(MMI_FALSE);
            mmi_pen_editor_show_candidate_area(MMI_TRUE, PEN_EDITOR_CANDIDATE_ON_NOT_FOCUS);
            mmi_pen_editor_smart_bpmf_pinyin_register_arrow_keys();
        }
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
        return;
    }

    if (gPenEditorSelectCandidate && (0 == mmi_pen_editor_get_vk_text_string_length()))
    {
        gdi_layer_lock_frame_buffer();
        gPenEditorSelectCandidate = MMI_FALSE;
        /* W05.50 Reset candidate index */
        mmi_pen_editor_reset_candidate_index();
        /* Temp Solution for LSK Text Update */
        mmi_pen_editor_set_left_soft_key();
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                if (UI_EMS_INPUT_BOX_STATE_MULTITAP & MMI_EMS_inputbox.flags)
                {
                    EMS_inputbox_multitap_input_complete();
                    mmi_pen_editor_backspace();
                }
                register_EMS_inputbox_keys();
                wgui_set_EMS_inputbox_RSK();
                break;

            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                if (UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP & MMI_multiline_inputbox.flags)
                {
                    multiline_inputbox_multitap_input_complete();
                    mmi_pen_editor_backspace();
                }
                register_multiline_inputbox_keys();
                if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                {
                    cat201_register_key_func();
                }
                wgui_set_RSK();
                break;

            case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
                wgui_singleline_inputbox_RSK_label_clear = 0;
                if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_singleline_inputbox.flags)
                {
                    singleline_inputbox_multitap_input_complete();
                    mmi_pen_editor_backspace();
                }
                register_singleline_inputbox_keys();
                wgui_set_singleline_RSK();
                break;

            case PEN_EDITOR_INLINE_TEXT:
                if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_inline_singleline_inputbox.flags)
                {
                    inline_edit_singleline_inputbox_multitap_input_complete();
                    mmi_pen_editor_backspace();
                }
                mmi_pen_editor_set_right_soft_key_inline_text();
                break;

            case PEN_EDITOR_DATE:
            case PEN_EDITOR_IP4:
            case PEN_EDITOR_TIME:
            case PEN_EDITOR_TIME_PERIOD:
                set_right_softkey_label(wgui_inline_edit_get_RSK_string());
                set_right_softkey_icon(NULL);
                register_right_softkey_handler();
                set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
                redraw_right_softkey();
                break;

            default:
                break;
        }
        /* W05.35 For Candidates Lsit Issue */
        mmi_pen_editor_hide_candidate_area();
        if (PEN_EDITOR_VK_OFF == mmi_pen_editor_get_vk_state())
        {
            int changed_height = 0;

            mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
            /* W05.47 Change the Input Control Height when the VK is not Tray Type */
            if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type)
                  && !(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()))
            {
                changed_height -= MMI_virtual_keyboard.height;
                if (!mmi_pen_editor_is_there_vk_candidate_box())
                {
                    changed_height += gPenEditorCandidateInputBox.height;
                }
                if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
                {
                    mmi_pen_editor_resize_content_area(changed_height);
                }
                /* W05.36 For Clear Candidates Lsit Area when it need to display */
                if (mmi_pen_editor_is_there_vk_candidate_box())
                {
                    gui_move_single_line_input_box(
                        &gPenEditorCandidateInputBox,
                        gPenEditorCandidateInputBox.x,
                        MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
                    /* W05.35 For Candidates Lsit Issue */
                    mmi_pen_editor_hide_candidate_area();
                }
            }
            /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
            mmi_pen_editor_change_handwriting_area();
            mmi_pen_editor_clear_and_show_virtual_keyboard_area();
        }
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
        return;
    }
    if ((GUI_VIRTUAL_KEYBOARD_BOPOMO == MMI_virtual_keyboard.lang_type)
        || GUI_VIRTUAL_KEYBOARD_PINYIN == MMI_virtual_keyboard.lang_type)
    {
        if (INPUT_MODE_MMI_MULTITAP_BPMF == MMI_current_input_mode
            || INPUT_MODE_MMI_MULTITAP_PINYIN == MMI_current_input_mode)
        {
            mmi_pen_editor_backspace();
        }
        else
        {
            if (mmi_pen_editor_vk_delete_character(mmi_pen_editor_get_vk_text()))
            {
                /* W05.35 Temp Solution for Candidate Index Issue */
                mmi_pen_editor_reset_candidate_index();
                gdi_layer_lock_frame_buffer();
                mmi_pen_editor_hide_candidate_area();
                gdi_layer_unlock_frame_buffer();
                if (mmi_pen_editor_get_candidates_by_vk(MMI_TRUE))
                {
                    gPenEditorSelectCandidate = MMI_TRUE;
                    /* Temp Solution for LSK Text Update */
                    //W05.35 For LSK Text Issue
                    //mmi_pen_editor_store_LSK_Text();
                    mmi_pen_editor_set_left_soft_key_select();
                    set_left_softkey_function(mmi_pen_editor_left_soft_key_handler, KEY_EVENT_UP);
                    set_left_softkey_function(mmi_pen_editor_hold_confirm, KEY_EVENT_DOWN);
                    mmi_pen_editor_register_arrow_keys();
                }
                else
                {
                    gPenEditorSelectCandidate = MMI_FALSE;
                    /* Temp Solution for LSK Text Update */
                    mmi_pen_editor_set_left_soft_key();
                    switch (gPenEditorInputBoxType)
                    {
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            register_EMS_inputbox_keys();
                            break;

                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                            register_multiline_inputbox_keys();
                            if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                            {
                                cat201_register_key_func();
                            }
                            break;

                        default:
                            break;
                    }
                }
                wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_TRUE);
                if (0 == mmi_pen_editor_get_vk_text_string_length())
                {
                    switch (gPenEditorInputBoxType)
                    {
                        case PEN_EDITOR_EMS_INPUT_BOX:
                            handle_category28_input();
                            wgui_set_EMS_inputbox_RSK();
                            break;

                        case PEN_EDITOR_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                        case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                            wgui_handle_inputbox_input();
                            wgui_set_RSK();
                            break;

                        default:
                            break;
                    }
                }
            }
            else
            {
                mmi_pen_editor_backspace();
            }
        }
    }
    else
    {
        mmi_pen_editor_backspace();
    }
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_left_soft_key_handler
 * DESCRIPTION
 *  Do the corresponding action for LSK according the state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_left_soft_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(!(mmi_pen_editor_left_soft_key_handler == gPenEditorLSKfunction));
    if (mmi_pen_editor_get_smart_latin_pre_candidate_length())
    {
        mmi_pen_editor_smart_latin_confirm_select();
        mmi_pen_editor_set_left_soft_key();
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                register_EMS_inputbox_keys();
                handle_category28_input();
                wgui_set_EMS_inputbox_RSK();
                break;

            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
                register_multiline_inputbox_keys();
                wgui_handle_inputbox_input();
                wgui_set_RSK();
                break;

            default:
                break;
        }
        gdi_lcd_repaint_all();
    }
    else if (g_pen_editor_composition_state.candidate_state == PEN_EDITOR_CANDIDATE_ON_AND_FOCUS)
    {
        mmi_pen_editor_smart_bpmf_pinyin_confirm_syllable();
    }
    else if (gPenEditorSelectCandidate)
    {
        UI_character_type ch, ch1, ch2;

        g_pen_editor_hold_confirm = MMI_FALSE;
        gdi_layer_lock_frame_buffer();
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        ch1 = *(gPenEditorCandidateInputBox.current_text_p - 2);
        ch2 = *(gPenEditorCandidateInputBox.current_text_p - 1);
        ch = ch1 | (ch2 << 8);
        mmi_pen_editor_input_character(ch, MMI_FALSE);
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                wgui_set_EMS_inputbox_RSK();
                break;

            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                wgui_set_RSK();
                break;

            case PEN_EDITOR_SINGLE_LINE_INPU_BOX:
                wgui_singleline_inputbox_RSK_label_clear = 0;
                wgui_set_singleline_RSK();
                break;

            case PEN_EDITOR_INLINE_TEXT:
                mmi_pen_editor_set_right_soft_key_inline_text();
                break;

            case PEN_EDITOR_DATE:
            case PEN_EDITOR_IP4:
            case PEN_EDITOR_TIME:
            case PEN_EDITOR_TIME_PERIOD:
                set_right_softkey_label(wgui_inline_edit_get_RSK_string());
                set_right_softkey_icon(NULL);
                register_right_softkey_handler();
                set_right_softkey_function(execute_wgui_inline_edit_RSK_function, KEY_EVENT_UP);
                redraw_right_softkey();
                break;

            default:
                break;
        }
        /* Temp Solution for checking Chinese Characters */
        mmi_pen_editor_check_phrase(ch);
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
    else
    {
	if (gPenEditorLSKfunction != NULL)
        {	
            gPenEditorLSKfunction();
        }
    }
    /* W05.50 Exclude Virtual Keyboard Area from Handwriting Area */
    mmi_pen_editor_change_handwriting_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_inputbox_LSK_Function
 * DESCRIPTION
 *  Set gPenEditorLSKfunction as f. gPenEditorLSKfunction is used in mmi_pen_editor_left_soft_key_handler.
 * PARAMETERS
 *  f       [IN]        Usually the LSK function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_inputbox_LSK_Function(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorLSKfunction = f;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_store_LSK_Text
 * DESCRIPTION
 *  Save current LSK text to gPenEditorLSKText. gPenEditorLSKText is used in mmi_pen_editor_set_left_soft_key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_store_LSK_Text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorLSKText = get_softkey_label(MMI_LEFT_SOFTKEY);
}


/* W05.33 For candidates sorting issue */
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_resort_candidates
 * DESCRIPTION
 *  Resort the candidates according to SortRequirement
 * PARAMETERS
 *  candidates          [OUT]       The buffer of the candidates to resort
 *  num                 [IN]        The number of the candidates
 *  SortRequirement     [IN]        PEN_EDITOR_SORT_CAPITAL_FIRST : Capital characters are in the front of non-capital characters
 *                                  PEN_EDITOR_SORT_NON_CAPITAL_FIRST : Non-capital characters are in the front of capital characters
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_resort_candidates(
        UI_character_type *candidates,
        int num,
        mmi_pen_editor_resort_type_enum SortRequirement)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num - 1; i++)
    {
        if (PEN_EDITOR_SORT_NON_CAPITAL_FIRST == SortRequirement)
        {
            if ((candidates[i + 1] - 0x20) == candidates[i])
            {
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = candidates[i] - 0x20;
            }
        }
        else if (PEN_EDITOR_SORT_CAPITAL_FIRST == SortRequirement)
        {
            if ((candidates[i + 1] + 0x20) == candidates[i])
            {
                candidates[i] = candidates[i + 1];
                candidates[i + 1] = candidates[i] + 0x20;
            }
        }
    }

    /* For '0' special case */
    if ('0' == candidates[0])
    {
        if (PEN_EDITOR_SORT_NON_CAPITAL_FIRST == SortRequirement)
        {
            if ('o' == candidates[1] && 'O' == candidates[2])
            {
                candidates[0] = 'o';
                candidates[1] = 'O';
                candidates[2] = '0';
            }
        }
        else if (PEN_EDITOR_SORT_CAPITAL_FIRST == SortRequirement)
        {
            if ('O' == candidates[1] && 'o' == candidates[2])
            {
                candidates[0] = 'O';
                candidates[1] = 'o';
                candidates[2] = '0';
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_clear_key_handler
 * DESCRIPTION
 *  Clear the key handler of Number Keys, Key Pound, and Key Star
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_clear_key_handler(void)
{
#if !defined(__MMI_HANDWRITING_PAD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();

    /* W05.51 Fix Long Press Key Handler cannot be cleared in clear_MMI_key_input_handler */
    ClearKeyHandler(KEY_0, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_1, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_2, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_3, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_4, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_5, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_6, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_7, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_8, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_9, KEY_LONG_PRESS);

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

    ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
#endif /* !defined(__MMI_HANDWRITING_PAD__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_vk_list_menu_resize
 * DESCRIPTION
 *  Resize the height of the list menu according to the state of the candidate box and the virtual keyboard.Then redraw the list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_vk_list_menu_resize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.36 Add Center Soft Key for switching Input Method */
    /*
     * if ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) != INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
     * {
     * resize_fixed_list(MMI_content_width, gPenEditorListMenuHeight - MMI_virtual_keyboard.height - 1);
     * }
     * else
     * {
     * if (gPenEditorVKCandidate)
     * {
     * resize_fixed_list(
     * MMI_content_width,
     * gPenEditorListMenuHeight - MMI_virtual_keyboard.height - gPenEditorCandidateInputBox.height - 1);
     * mmi_pen_editor_hide_candidate_area();
     * }
     * else
     * {
     * resize_fixed_list(MMI_content_width, gPenEditorListMenuHeight - MMI_virtual_keyboard.height - 1);
     * }
     * }
     */
    mmi_pen_editor_list_menu_highlight_resize();
    /* W06.05 Do not draw fixed list in category57 because of virtual keyboard */
    if (((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
        ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT))
    {
        memset(&gPenEditorInlineEditHistory, 0, sizeof(gPenEditorInlineEditHistory));
        wgui_inline_edit_get_current_item_history((U8*) & gPenEditorInlineEditHistory);
    }
    complete_inline_item_edit();
    wgui_inline_edit_default_list_highlight_handler(MMI_fixed_list_menu.highlighted_item);
    wgui_inline_item_handled = 0;
    gui_fixed_list_menu_locate_highlighted_item(&MMI_fixed_list_menu);
    if ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
    {
        MMI_fixed_list_menu.first_displayed_item = MMI_fixed_list_menu.highlighted_item;
    }
    if (((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_TEXT_EDIT) ||
        ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) == INLINE_ITEM_TYPE_MULTI_LINE_EDIT))
    {
        memset(&gPenEditorInlineEditHistory, 0, sizeof(gPenEditorInlineEditHistory));
        wgui_inline_edit_get_current_item_history((U8*) & gPenEditorInlineEditHistory);
    }
    redraw_fixed_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_list_menu_highlight_resize
 * DESCRIPTION
 *  Resize the height of the list menu according to the state of the candidate box and the virtual keyboard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_list_menu_highlight_resize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.05 Temp solution for Do not draw fixed list in category57 because of virtual keyboard */
    if (gPenEditorListMenuHeight)
    {
        int changed_height = MMI_virtual_keyboard.height;
        int candidate_inpt_box_height = gPenEditorCandidateInputBox.height;

        if (!candidate_inpt_box_height)
        {
            candidate_inpt_box_height = mmi_pen_editor_compute_candidate_input_box_height();
        }
        if (changed_height < candidate_inpt_box_height)
        {
            changed_height = candidate_inpt_box_height;
        }
        if ((current_wgui_inline_item->flags & INLINE_ITEM_TYPE_MASK) != INLINE_ITEM_TYPE_MULTI_LINE_EDIT)
        {
            resize_fixed_list(MMI_content_width, gPenEditorListMenuHeight - changed_height - 1);
        }
        else
        {
            if (mmi_pen_editor_is_there_vk_candidate_box())
            {
                resize_fixed_list(
                    MMI_content_width,
                    gPenEditorListMenuHeight - MMI_virtual_keyboard.height - gPenEditorCandidateInputBox.height - 1);
                mmi_pen_editor_hide_candidate_area();
            }
            else
            {
                resize_fixed_list(MMI_content_width, gPenEditorListMenuHeight - changed_height - 1);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_store_list_menu_height
 * DESCRIPTION
 *  Store the height of the lsit menu in gPenEditorListMenuHeight
 * PARAMETERS
 *  list_menu_height        [IN]        The height of the list menu
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_store_list_menu_height(S32 list_menu_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorListMenuHeight = list_menu_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_list_menu_height
 * DESCRIPTION
 *  Get the stored height of the list menu
 * PARAMETERS
 *  void
 * RETURNS
 *  The stored height of the list menu
 *****************************************************************************/
S32 mmi_pen_editor_get_list_menu_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPenEditorListMenuHeight;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_CSK_content
 * DESCRIPTION
 *  Set the CSK content by the input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_CSK_content(void)
{
#ifdef __MMI_WGUI_CSK_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* W05.36 Add Center Soft Key for switching Input Method */
    UI_string_type inputmode_string = NULL;
    PU8 inputbox_information_icon = NULL;
/*PMT IRE START*/
//REMOVED
/*PMT IRE END*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
    set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);

    switch (MMI_current_input_mode)
    {
        case INPUT_MODE_SMART_UPPERCASE_ABC:
             /* inputbox_information_icon = get_image(WGUI_IME_SMART_ENGLISH_IMG); */
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_ABC_STRING_ID);
            break;

        case INPUT_MODE_SMART_LOWERCASE_ABC:
             /* inputbox_information_icon = get_image(WGUI_IME_SMART_ENGLISH_IMG); */
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case INPUT_MODE_MMI_LOWERCASE_ABC:
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_abc_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_THAI:
        case INPUT_MODE_MMI_MULTITAP_THAI:
        case INPUT_MODE_SMART_THAI:
        #if defined(__MMI_MULTITAP_THAI__)
            inputmode_string=(UI_string_type)get_string(WGUI_CATEGORY_thai_STRING_ID); 
        #endif /* (__MMI_MULTITAP_THAI__) */
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_SPANISH_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
        case INPUT_MODE_MMI_LOWERCASE_SPANISH:
        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_spanish_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_DANISH:
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_DANISH_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_DANISH:
        case INPUT_MODE_MMI_LOWERCASE_DANISH:
        case INPUT_MODE_SMART_LOWERCASE_DANISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_danish_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_FRENCH:
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_FRENCH_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_FRENCH:
        case INPUT_MODE_MMI_LOWERCASE_FRENCH:
        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_french_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_GERMAN:
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_GERMAN_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_GERMAN:
        case INPUT_MODE_MMI_LOWERCASE_GERMAN:
        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_german_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN:
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_ITALIAN_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN:
        case INPUT_MODE_MMI_LOWERCASE_ITALIAN:
        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_italian_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN:
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_RUSSIAN_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN:
        case INPUT_MODE_MMI_LOWERCASE_RUSSIAN:
        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_russian_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_TURKISH:
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_TURKISH_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_TURKISH:
        case INPUT_MODE_MMI_LOWERCASE_TURKISH:
        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_turkish_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_PORTUGUESE_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE:
        case INPUT_MODE_MMI_LOWERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_portuguese_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN:
        case INPUT_MODE_SMART_UPPERCASE_UKRAINIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_UKRAINIAN_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN:
        case INPUT_MODE_MMI_LOWERCASE_UKRAINIAN:
        case INPUT_MODE_SMART_LOWERCASE_UKRAINIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_L_UKRAINIAN_STRING_ID);
            break;

    #if defined(__MMI_MULTITAP_HINDI__)  
        case INPUT_MODE_MULTITAP_HINDI:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_HINDI_STRING_ID);
            break;
    #endif /* defined(__MMI_MULTITAP_HINDI__) */ 
            
    #if defined(__MMI_MULTITAP_MARATHI__)
        case INPUT_MODE_MULTITAP_MARATHI:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_MARATHI_STRING_ID);
            break;
    #endif /* defined(__MMI_MULTITAP_MARATHI__) */ 
            

        case INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN:
        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_INDONESIAN_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN:
        case INPUT_MODE_MMI_LOWERCASE_INDONESIAN:
        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_indonesian_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_MALAY:
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_MALAY_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_MALAY:
        case INPUT_MODE_MMI_LOWERCASE_MALAY:
        case INPUT_MODE_SMART_LOWERCASE_MALAY:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_malay_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_VIETNAMESE_STRING_ID);
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
        case INPUT_MODE_MMI_LOWERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_vietnamese_STRING_ID);
            break;

        case INPUT_MODE_123:
        case INPUT_MODE_MMI_NUMERIC:
        case INPUT_MODE_123_SYMBOLS:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_123_STRING_ID);
            break;

        case INPUT_MODE_SMART_ARABIC:
        case INPUT_MODE_MULTITAP_ARABIC:
        case INPUT_MODE_MMI_MULTITAP_ARABIC:
            inputmode_string=(UI_string_type)get_string(WGUI_CATEGORY_ARABIC_STRING_ID); 
            break;
            
        case INPUT_MODE_ARABIC_NUMERIC:
        case INPUT_MODE_MMI_ARABIC_NUMERIC:
            /*inputmode_string=(UI_string_type)get_string(WGUI_CATEGORY_ARABIC_NUMERIC_STRING_ID);*/
            inputmode_string=(UI_string_type)get_string(WGUI_CATEGORY_ARABIC_STRING_ID); 
            break;

        case INPUT_MODE_MMI_MULTITAP_BPMF:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_BPMF_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #endif 
            break;

        case INPUT_MODE_MMI_MULTITAP_PINYIN:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_PINYIN_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #endif 
            break;

        case INPUT_MODE_MMI_SM_STROKE:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_SM_STROKE_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #endif 
            break;

        case INPUT_MODE_MMI_TR_STROKE:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_TR_STROKE_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #endif 
            break;

        case INPUT_MODE_TR_MULTITAP_BOPOMO:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_BPMF_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_BPMF_IMG);
    #endif 
            break;

        case INPUT_MODE_SM_MULTITAP_PINYIN:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_PINYIN_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_MULTITAP_PINYIN_IMG);
    #endif 
            break;

        case INPUT_MODE_TR_STROKE:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_TR_STROKE_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_TR_STROKE_IMG);
    #endif 
            break;

        case INPUT_MODE_SM_STROKE:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_SM_STROKE_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_SM_STROKE_IMG);
    #endif 
            break;

        case INPUT_MODE_TR_BOPOMO:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_SMART_BPMF_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_BPMF_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_SMART_BPMF_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_SMART_BPMF_IMG);
    #endif 
            break;

        case INPUT_MODE_SM_PINYIN:
    #if defined(__MMI_T9__)
            inputbox_information_icon = get_image(WGUI_IME_SMART_PINYIN_IMG);
    #elif defined(__MMI_ZI__)
            inputbox_information_icon = get_image(WGUI_ZI_EZITEXT_PINYIN_LOGO);
    #elif defined(__MMI_CSTAR__)
            inputbox_information_icon = get_image(WGUI_IME_SMART_PINYIN_IMG);
    #else 
            inputbox_information_icon = get_image(WGUI_IME_SMART_PINYIN_IMG);
    #endif 
            break;
    //Liu Jun add 20070319
        case INPUT_MODE_MULTITAP_UPPERCASE_POLISH:
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_POLISH_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_POLISH:
        case INPUT_MODE_MMI_LOWERCASE_POLISH:
        case INPUT_MODE_SMART_LOWERCASE_POLISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_polish_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN:
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_BULGARIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN:
        case INPUT_MODE_MMI_LOWERCASE_BULGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_bulgarian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_HEBREW:
        case INPUT_MODE_MMI_MULTITAP_HEBREW:
        case INPUT_MODE_SMART_HEBREW:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_HEBREW_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_PERSIAN:
        case INPUT_MODE_MMI_MULTITAP_PERSIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_PERSIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_CZECH:
            case INPUT_MODE_SMART_UPPERCASE_CZECH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_CZECH_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_CZECH:
        case INPUT_MODE_MMI_LOWERCASE_CZECH:
        case INPUT_MODE_SMART_LOWERCASE_CZECH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_czech_STRING_ID);
            break;
            
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
        case INPUT_MODE_MULTITAP_UPPERCASE_FINNISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_FINNISH_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_FINNISH:
        case INPUT_MODE_MMI_LOWERCASE_FINNISH:
        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_finnish_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN:
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_HUNGARIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN:
        case INPUT_MODE_MMI_LOWERCASE_HUNGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_hungarian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK:
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_SLOVAK_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK:
        case INPUT_MODE_MMI_LOWERCASE_SLOVAK:
        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_slovak_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_DUTCH:
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_DUTCH_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_DUTCH:
        case INPUT_MODE_MMI_LOWERCASE_DUTCH:
        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_dutch_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_NORWEGIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN:
        case INPUT_MODE_MMI_LOWERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_norwegian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH:
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_SWEDISH_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH:
        case INPUT_MODE_MMI_LOWERCASE_SWEDISH:
        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_swedish_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN:
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_CROATIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN:
        case INPUT_MODE_MMI_LOWERCASE_CROATIAN:
        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_croatian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN:
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_ROMANIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN:
        case INPUT_MODE_MMI_LOWERCASE_ROMANIAN:
        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_romanian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_SLOVENIAN_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN:
        case INPUT_MODE_MMI_LOWERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_slovenian_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_UPPERCASE_GREEK:
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_GREEK_STRING_ID);
            break;
            
        case INPUT_MODE_MULTITAP_LOWERCASE_GREEK:
        case INPUT_MODE_MMI_LOWERCASE_GREEK:
        case INPUT_MODE_SMART_LOWERCASE_GREEK:
            inputmode_string = (UI_string_type) get_string(WGUI_CATEGORY_greek_STRING_ID);
            break;
            
    //Liu Jun add end
    }
    if (NULL != inputmode_string)
    {
        set_softkey_label(inputmode_string, MMI_CENTER_SOFTKEY);
    }
    if (NULL != inputbox_information_icon)
    {
        set_softkey_icon(inputbox_information_icon, MMI_CENTER_SOFTKEY);
    }
    redraw_softkey(MMI_CENTER_SOFTKEY);
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_exit_screen
 * DESCRIPTION
 *  Common function for handwriting when exiting screen. This is used in UI_common_screen_exit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.04 Set gPenEditorGDIHandler to NULL when exiting screen */
#ifdef MMI_PEN_EDITOR_ON_2_LAYER    
    mmi_pen_editor_restore_blt_layer();
    if (gPenEditorStrokeHandle != GDI_ERROR_HANDLE)
    {
        gdi_layer_free(gPenEditorStrokeHandle);
        gPenEditorStrokeHandle = GDI_ERROR_HANDLE;
    }
#else /* MMI_PEN_EDITOR_ON_2_LAYER */
    gPenEditorGDIHandler = NULL;
#endif /* MMI_PEN_EDITOR_ON_2_LAYER */
    gPenEditorListMenuHeight = 0;
    if (gPenEditorStrokeGDIBuffer)
    {
        mmi_frm_scrmem_free((void*)gPenEditorStrokeGDIBuffer);
    }
    gPenEditorStrokeGDIBuffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_hold_confirm
 * DESCRIPTION
 *  Do not confirm the selection directly when the candidate box is on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_hold_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorSelectCandidate)
    {
        gui_cancel_timer(mmi_pen_editor_confirm_selection);
        g_pen_editor_hold_confirm = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_cancel_handwriting
 * DESCRIPTION
 *  Cancel the handwriting. This function is usually used when key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_cancel_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gPenEditorFirstStroke)
    {
        int changed_height = 0;
    #ifdef MMI_PEN_EDITOR_ON_2_LAYER        
        mmi_pen_editor_restore_blt_layer();
    #else /* MMI_PEN_EDITOR_ON_2_LAYER */
        if (gPenEditorGDIHandler != NULL && *gPenEditorGDIHandler != GDI_ERROR_HANDLE)
        {
            gdi_layer_push_and_set_active(*gPenEditorGDIHandler);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
    #endif /* MMI_PEN_EDITOR_ON_2_LAYER */
        gui_cancel_timer(mmi_pen_editor_stroke_up_timer_handler);
        g_stroke_up_timer_is_on = MMI_FALSE;
        mmi_pen_begin_strokes_of_character();
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_set_vk_state(PEN_EDITOR_VK_ON);
        if (gPenEditorShowVK && (gPenEditorCandidateInputBox.y >= (PEN_EDITOR_Y_OF_CANDIDATE_INPUT_BOX_IN_BOTTOM)))
        {
            /* W05.47 Change the Input Control Height when the VK is not Tray Type */
            if (!(GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
                  || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type))
            {
                changed_height = gPenEditorCandidateInputBox.height;
                if (mmi_pen_editor_is_there_vk_candidate_box())
                {
                    changed_height -= gPenEditorCandidateInputBox.height;
                }
                changed_height -= MMI_virtual_keyboard.height;
                if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX != gPenEditorInputBoxType)
                {
                    mmi_pen_editor_resize_content_area(changed_height);
                }
            }
        }

        if (gPenEditorShowVK)
        {
            mmi_pen_editor_clear_and_show_virtual_keyboard_area();
        }

        if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            if (gPenEditorShowVK)
            {
                gui_move_single_line_input_box(
                    &gPenEditorCandidateInputBox,
                    gPenEditorCandidateInputBox.x,
                    MMI_virtual_keyboard.y - gPenEditorCandidateInputBox.height - 2);
            }
            mmi_pen_editor_hide_candidate_area();
        }
        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_reset_LSK_and_RSK_state
 * DESCRIPTION
 *  Reset LSK and RSK label and function to un-selected state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_reset_LSK_and_RSK_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorSelectCandidate)
    {
        gPenEditorSelectCandidate = MMI_FALSE;
        mmi_pen_editor_set_left_soft_key();
        switch (gPenEditorInputBoxType)
        {
            case PEN_EDITOR_EMS_INPUT_BOX:
                /* LSK */
                register_EMS_inputbox_keys();
                /* RSK */
                handle_category28_input();
                wgui_set_EMS_inputbox_RSK();
                break;

            case PEN_EDITOR_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX:
            case PEN_EDITOR_DICT_MULTILINE_INPUT_BOX:
                /* LSK */
                register_multiline_inputbox_keys();
                /* RSK */
                wgui_handle_inputbox_input();
                wgui_set_RSK();
                
                if (PEN_EDITOR_DICT_MULTILINE_INPUT_BOX == gPenEditorInputBoxType)
                {
                    cat201_register_key_func();
                }
                break;

            default:
                break;
        }
        mmi_pen_editor_reset_vk_text(mmi_pen_editor_get_vk_text());
        wgui_set_virtual_keyboard_display_area((U8*) (mmi_pen_editor_get_vk_text_string()), MMI_FALSE);
    }     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_is_candidate_in_selection
 * DESCRIPTION
 *  Is candidate in selection
 * PARAMETERS
 *  void
 * RETURNS
 *  The candidate is in selection state or not
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_candidate_in_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorSelectCandidate;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_candidate_selection_status
 * DESCRIPTION
 *  Set candidate to be in selection or not
 * PARAMETERS
 *  is_in_selection      [IN]    is in selection or not
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_pen_editor_set_candidate_selection_status(MMI_BOOL is_in_selection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPenEditorSelectCandidate = is_in_selection;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_state
 * DESCRIPTION
 *  Get candidate state
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to candidate state
 *****************************************************************************/
mmi_pen_editor_candidate_state_struct * mmi_pen_editor_get_composition_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return &g_pen_editor_composition_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_candaidate_state
 * DESCRIPTION
 *  Set candidate state
 * PARAMETERS
 *  candidate_state_struct    [IN]   The pointer to candidate structure
 *  candidate_state             [IN]   The candidate state to be set
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_candaidate_state(mmi_pen_editor_candidate_state_struct * candidate_state_struct, mmi_pen_editor_candidate_state_enum candidate_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    candidate_state_struct->candidate_state = candidate_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box
 * DESCRIPTION
 *  Get composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to composition box
 *****************************************************************************/
single_line_input_box * mmi_pen_editor_get_composition_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return &gPenEditorCompositionInputBox;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box_height
 * DESCRIPTION
 *  Get composition box height
 * PARAMETERS
 *  void
 * RETURNS
 *  Composition box height
 *****************************************************************************/
S32 mmi_pen_editor_get_composition_box_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCompositionInputBox.height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box_x
 * DESCRIPTION
 *  Get x coordinate of composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  X coordinate of composition box
 *****************************************************************************/
S32 mmi_pen_editor_get_composition_box_x(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCompositionInputBox.x;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box_y
 * DESCRIPTION
 *  Get y coordinate of composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  Y coordinate of composition box
 *****************************************************************************/
S32 mmi_pen_editor_get_composition_box_y(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCompositionInputBox.y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box_current_text
 * DESCRIPTION
 *  Get current text of composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to current text of composition box
 *****************************************************************************/
UI_buffer_type mmi_pen_editor_get_composition_box_current_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCompositionInputBox.current_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_composition_box_text
 * DESCRIPTION
 *  Get text of composition box
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to text of composition box
 *****************************************************************************/
UI_buffer_type mmi_pen_editor_get_composition_box_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCompositionInputBox.text;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box
 * DESCRIPTION
 *  Get candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to candidate box
 *****************************************************************************/
single_line_input_box * mmi_pen_editor_get_candidate_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return &gPenEditorCandidateInputBox;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box_height
 * DESCRIPTION
 *  Get candidate box height
 * PARAMETERS
 *  void
 * RETURNS
 *  Candidate box height
 *****************************************************************************/
S32 mmi_pen_editor_get_candidate_box_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCandidateInputBox.height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box_x
 * DESCRIPTION
 *  Get x coordinate of candidate box 
 * PARAMETERS
 *  void
 * RETURNS
 *  X coordinate of candidate box 
 *****************************************************************************/
S32 mmi_pen_editor_get_candidate_box_x(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCandidateInputBox.x;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box_y
 * DESCRIPTION
 *  Get y coordinate of candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  Y coordinate of candidate box
 *****************************************************************************/
S32 mmi_pen_editor_get_candidate_box_y(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCandidateInputBox.y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box_text_font
 * DESCRIPTION
 *  Get text font of candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  Text font of candidate box
 *****************************************************************************/
UI_font_type mmi_pen_editor_get_candidate_box_text_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCandidateInputBox.text_font;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_box_text_length
 * DESCRIPTION
 *  Get text length of candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  Text length of candidate box
 *****************************************************************************/
S32 mmi_pen_editor_get_candidate_box_text_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorCandidateInputBox.text_length;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidate_arrow_state
 * DESCRIPTION
 *  Get candidate arrow state
 * PARAMETERS
 *  void
 * RETURNS
 *  Arrow is enabled or not
 *****************************************************************************/
MMI_BOOL  mmi_pen_editor_get_candidate_arrow_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return g_pen_editor_candidate_state.arrow_enable;
    }     


#ifdef __MMI_EDITOR_PEN_VK_UNFOLD__
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_only_redraw_input_box_or_not
 * DESCRIPTION
 *  Set only redraw input box or not
 * PARAMETERS
 *  redraw_or_not           [IN]      Only redraw input box or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_only_redraw_input_box_or_not(MMI_BOOL redraw_or_not)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gPenEditorOnlyRedrawInputBox = redraw_or_not;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_is_handwriting_enabled
 * DESCRIPTION
 *  Return handwriting is enabled or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Handwriting is enabled or not
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_handwriting_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return gPenEditorEnableHandWriting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_handwriting_enabled_or_not
 * DESCRIPTION
 *  Set handwriting to be enabled or not
 * PARAMETERS
 *  enabled_or_not           [IN]     Handwriting to be enabled or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_handwriting_enabled_or_not(MMI_BOOL enabled_or_not)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gPenEditorEnableHandWriting = enabled_or_not;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_input_box_type
 * DESCRIPTION
 *  Get current input box type
 * PARAMETERS
 *  void
 * RETURNS
 *  Current input box type
 *****************************************************************************/
mmi_pen_editor_input_box_type_enum mmi_pen_editor_get_input_box_type(void)
{
    return gPenEditorInputBoxType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_is_stroke_up_timer_on
 * DESCRIPTION
 *  Judge the stroke up timer is on or not
 * PARAMETERS
 *  void
 * RETURNS
 *  The stroke up timer is on or not
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_stroke_up_timer_on(void)
{
    return g_stroke_up_timer_is_on;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_type_by_input_mode
 * DESCRIPTION
 *  Query the virtual keyboard type by specified  input mode
 * PARAMETERS
 *  input_mode          [IN]    Input mode
 *  vk_type             [OUT]   Virtual keyboard type
 *  has_candidate_box   [OUT]   Whether the vk has candidate box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_vk_type_by_input_mode(S32 input_mode, U8 *vk_type, MMI_BOOL *has_candidate_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  i =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (input_mode == mtk_gIMEModeArray[i].IME_Mode_ID)
        {
            *vk_type =  (gui_virtual_keyboard_language_enum)(U8)((mtk_gIMEModeArray[i].Handwriting_Attrib)>>8);
	        *has_candidate_box = (MMI_BOOL)((mtk_gIMEModeArray[i].Handwriting_Attrib)>>24);
	        return;
        }
	    else
	        i++;
    }

    *vk_type =  0xFF;
    *has_candidate_box = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_type_by_input_mode_for_quick_search
 * DESCRIPTION
 *  Query the virtual keyboard type by specified  input mode
 * PARAMETERS
 *  input_mode          [IN]    Input mode
 *  vk_type             [OUT]   Virtual keyboard type
 *  has_candidate_box   [OUT]   Whether the vk has candidate box
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_vk_type_by_input_mode_for_quick_search(S32 input_mode, U8 *vk_type, MMI_BOOL *has_candidate_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  i =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEQSearchModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (input_mode == mtk_gIMEQSearchModeArray[i].IME_Mode_ID)
        {
            *vk_type =  (gui_virtual_keyboard_language_enum)(U8)((mtk_gIMEQSearchModeArray[i].Handwriting_Attrib)>>8);
	        *has_candidate_box = (MMI_BOOL)((mtk_gIMEQSearchModeArray[i].Handwriting_Attrib)>>24);
	        return;
        }
	    else
	        i++;
    }

    *vk_type =  0xFF;
    *has_candidate_box = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_type_by_input_mode_for_quick_search
 * DESCRIPTION
 *  Judge whether the virtual keyboard type is valid
 * PARAMETERS
 *  vk_type             [IN]   Virtual keyboard type
 * RETURNS
 *  Whether the virtual keyboard type is valid
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_valid_vk_type_for_quick_search(gui_virtual_keyboard_language_enum vk_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  i =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEQSearchModeArray[i].IME_Mode_ID != 0xFF)
    {
        if ((gui_virtual_keyboard_language_enum)(U8)((mtk_gIMEQSearchModeArray[i].Handwriting_Attrib)>>8) == vk_type)
        {
	        return MMI_TRUE;
        }
	    else
	        i++;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_hand_writing_type_by_input_mode
 * DESCRIPTION
 *  Query the hand writing type by specified  input mode
 * PARAMETERS
 *  input_mode  [IN]    Input mode
 * RETURNS
 *  Hand writing type
 *****************************************************************************/
mmi_pen_editor_input_type_enum mmi_pen_editor_get_hand_writing_type_by_input_mode(S32 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  i =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while(mtk_gIMEModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (input_mode == mtk_gIMEModeArray[i].IME_Mode_ID)
        {
	        return (U8)(mtk_gIMEModeArray[i].Handwriting_Attrib);
        }
	    else
	        i++;
    }

    return PEN_EDITOR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_caps_lock_input_mode
 * DESCRIPTION
 *  Query the virtual keyboard's caps lock vk type
 * PARAMETERS
 *  input_mode  [IN]  Oringnal input mode
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_pen_editor_get_caps_lock_input_mode(S32 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Thai don't have upper case input method, but its vk use caps lock to 
     * switch its string case and symbol case */
    if (input_mode == INPUT_MODE_MULTITAP_THAI 
        || input_mode == INPUT_MODE_MMI_MULTITAP_THAI
        || input_mode == INPUT_MODE_SMART_THAI)
    {
        return input_mode;
    }
   
    while(mtk_gIMEModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (mtk_gIMEModeArray[i].IME_Mode_ID == input_mode)
        {
            return (U8)((mtk_gIMEModeArray[i].Handwriting_Attrib)>>16);
        }
        else
        {
            i++;
        }
    }

    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_Lang_special_attrib_by_input_mode
 * DESCRIPTION
 *  Query the special language attributs by input mode
 * PARAMETERS
 *  input_mode  [IN]  Input mode
 * RETURNS
 *  The special language attributes
 *****************************************************************************/
U16 mmi_pen_editor_get_Lang_special_attrib_by_input_mode(U8 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (mtk_gIMEModeArray[i].IME_Mode_ID == input_mode)
        {
            return mtk_gIMEModeArray[i].Lang_Special_Attrib;
        }
        else
        {
            i++;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_mode_special_attrib_by_input_mode
 * DESCRIPTION
 *  Query the special input mode attributes by input mode
 * PARAMETERS
 *  input_mode  [IN]  Input mode
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_pen_editor_get_mode_special_attrib_by_input_mode(U8 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEModeArray[i].IME_Mode_ID != 0xFF)
    {
        if (mtk_gIMEModeArray[i].IME_Mode_ID == input_mode)
        {
            return mtk_gIMEModeArray[i].Mode_Special_Attrib;
        }
        else
        {
            i++;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_type_by_input_type
 * DESCRIPTION
 *  Query the virtual keyboard type by input type
 * PARAMETERS
 *  input_type  [IN]  Input type
 * RETURNS
 *  void
 *****************************************************************************/
gui_virtual_keyboard_language_enum mmi_pen_editor_get_vk_type_by_input_type(U16 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEModeArray[i].IME_Type_ID != 0xFF)
    {
        if (mtk_gIMEModeArray[i].IME_Type_ID == input_type)
        {
            return (gui_virtual_keyboard_language_enum)((U8)((mtk_gIMEModeArray[i].Handwriting_Attrib)>>8));
        }
        else
        {
            i++;
        }
    }

    if (input_type == INPUT_TYPE_ALPHANUMERIC_SENTENCECASE
		|| input_type == INPUT_TYPE_ALPHANUMERIC_PASSWORD)
    {
        return GUI_VIRTUAL_KEYBOARD_ENGLISH;
    }

    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_vk_type_by_input_type_for_quick_search
 * DESCRIPTION
 *  Query the virtual keyboard type by input type
 * PARAMETERS
 *  input_type  [IN]  Input type
 * RETURNS
 *  void
 *****************************************************************************/
gui_virtual_keyboard_language_enum mmi_pen_editor_get_vk_type_by_input_type_for_quick_search(U16 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(mtk_gIMEQSearchModeArray[i].IME_Type_ID != 0xFF)
    {
        if (mtk_gIMEQSearchModeArray[i].IME_Type_ID == input_type)
        {
            return (gui_virtual_keyboard_language_enum)((U8)((mtk_gIMEQSearchModeArray[i].Handwriting_Attrib)>>8));
        }
        else
        {
            i++;
        }
    }

    if (input_type == INPUT_TYPE_ALPHANUMERIC_SENTENCECASE
		|| input_type == INPUT_TYPE_ALPHANUMERIC_PASSWORD)
    {
        return GUI_VIRTUAL_KEYBOARD_ENGLISH;
    }

    return 0xFF;
}



#ifdef MMI_PEN_EDITOR_ON_2_LAYER

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_backup_and_set_blt_layer
 * DESCRIPTION
 *  Backup the current layer and set stroke layer to limit the maximum layer 
 *  count to 2 (in some platforms such as MT6223)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_editor_backup_and_set_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle tmp_layer_3, tmp_layer_4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorStrokeHandle == GDI_ERROR_HANDLE)
    {    
        MMI_ASSERT(!gPenEditorBltLayerSwitched);
    
        gPenEditorStrokeGDIBuffer = (U8*) mmi_frm_scrmem_alloc(handwriting_stroke_layer_mem);
        MMI_ASSERT(gPenEditorStrokeGDIBuffer);

        /* Use native GDI layer API instead of draw manager API to control blt layers directly */
        if (GDI_LAYER_SUCCEED != gdi_layer_create_using_outside_memory(
                                    0,
                                    0,
                                    UI_device_width,
                                    UI_device_height,
                                    &gPenEditorStrokeHandle,
                                    (U8*) gPenEditorStrokeGDIBuffer,
                                    handwriting_stroke_layer_mem))
        {
            MMI_ASSERT(0);
        }
    }

    if (!gPenEditorBltLayerSwitched)
    {
        gdi_layer_get_blt_layer(
            &gPenEditorGDIOriginalHandle1, 
            &gPenEditorGDIOriginalHandle2, 
            &tmp_layer_3,
            &tmp_layer_4);

        gdi_layer_push_and_set_active(gPenEditorStrokeHandle);                        

        /* Set source key for layer flattening */
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

        /* copy the display content from scr_bg & base layer to stroke layer*/        
        gdi_layer_flatten(
            gPenEditorGDIOriginalHandle1, 
            gPenEditorGDIOriginalHandle2,
            tmp_layer_3,
            tmp_layer_4);

        /* Set current active layer to the stroke layer only */
        gdi_layer_set_blt_layer(gPenEditorStrokeHandle, GDI_ERROR_HANDLE, GDI_ERROR_HANDLE, GDI_ERROR_HANDLE);

        /* Note: active layer != BLT layers because other UI component like softkey 
           may redraw itself in the current active layer. 
           As a result, they are redrawn in the base layer */
        gdi_layer_pop_and_restore_active();

        gPenEditorBltLayerSwitched = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_restore_blt_layer
 * DESCRIPTION
 *  Restore the original editor layer configurations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_editor_restore_blt_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPenEditorBltLayerSwitched)
    {
        gdi_layer_set_blt_layer(gPenEditorGDIOriginalHandle1, gPenEditorGDIOriginalHandle2, GDI_ERROR_HANDLE, GDI_ERROR_HANDLE);
        gPenEditorBltLayerSwitched = MMI_FALSE;
    }
}

#endif /* MMI_PEN_EDITOR_ON_2_LAYER */


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_is_valid_input_type_for_inline_editor
 * DESCRIPTION
 *  Restore the original editor layer configurations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_is_valid_input_type_for_inline_editor(U16 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (input_type == INPUT_TYPE_NUMERIC_CHANGEABLE)
		return MMI_FALSE;
	else
		return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_do_not_resize_input_box
 * DESCRIPTION
 *  Don't resize input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_do_not_resize_input_box(void)
{
    g_not_resize_input_box = MMI_TRUE;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 


