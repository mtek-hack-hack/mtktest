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
 * EditorPen_HW.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is EditorPen's sub module which is related to HandWriting Engine 
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
/* This compile option is used to exclude VK area from handwriting region */
#define __MMI_HAND_WRITING_EXCLUDE_VK_AREA__

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static mmi_pen_editor_handwriting_style_enum g_pen_editor_handwriting_style;

static mmi_pen_handwriting_area_struct g_multi_block_stroke_area[2];

/* The buffer to store points of stroke */
static mmi_pen_point_struct gPenEditorStrokeBuffer[PEN_EDITOR_STROKE_BUFFER_SIZE];

/* Stoke Area for execlude Virtual Keyboard Area */
static mmi_pen_handwriting_area_struct g_pen_editor_original_handwriting_area;

static MMI_BOOL g_pen_editor_disable_handwriting = MMI_FALSE;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


#if !defined(__MMI_HANWANG__) && !defined(__MMI_PENPOWER__) && !defined(__MMI_DECUMA__)

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_hand_writing_initialize
 * DESCRIPTION
 *  Initialize handwriting module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_hand_writing_initialize(void)
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
*  mmi_pen_editor_hand_writing_deinitialize
* DESCRIPTION
*  Deinitialize handwriting module
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_pen_editor_hand_writing_deinitialize(void)
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
 *  mmi_pen_editor_hand_writing_get_candidates
 * DESCRIPTION
 *  Get the candidates from the handwriting strokes
 * PARAMETERS
 *  stroke_buffer       [IN]          Stokes data passed to handwriting module
 *  candidate_array     [OUT]         Buffer to store candidates
 *  h_w_type            [IN]          Which kind of candidates to return, Chinese, English, Symbol (need to revise)
 *  number              [IN]          The wished number of candidate
 * RETURNS
 *  The number of the candidates
 *****************************************************************************/
S32 mmi_pen_editor_hand_writing_get_candidates(
        U16 *stroke_buffer,
        UI_character_type *candidate_array,
        mmi_pen_editor_input_type_enum h_w_type,
        S32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}
#endif /* !defined(__MMI_HANWANG__) && !defined(__MMI_PENPOWER__) && !defined(__MMI_DECUMA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_candidates_from_hand_writing
 * DESCRIPTION
 *  Get the candidates from the handwriting module
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of the candidates
 *****************************************************************************/
int mmi_pen_editor_get_candidates_from_hand_writing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type candidate_buffer[PEN_EDITOR_MAX_CANDIDATE_SIZE];
    int num = 0;
    mmi_pen_editor_input_type_enum hand_writing_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hand_writing_type = mmi_pen_editor_get_hand_writing_type_by_input_mode(MMI_current_input_mode);

    if (hand_writing_type != 0)
    {
            num = mmi_pen_editor_hand_writing_get_candidates(
                    (U16*) gPenEditorStrokeBuffer,
                    candidate_buffer,
                    hand_writing_type,
                    PEN_EDITOR_CANDIDATE_SIZE);

        switch (hand_writing_type)
        {
            case PEN_EDITOR_UPPER_CASE_ENGLISH:
            mmi_pen_editor_resort_candidates(candidate_buffer, num, PEN_EDITOR_SORT_CAPITAL_FIRST);
            break;
            case PEN_EDITOR_LOWER_CASE_ENGLISH:
            mmi_pen_editor_resort_candidates(candidate_buffer, num, PEN_EDITOR_SORT_NON_CAPITAL_FIRST);
            break;
        default:
            break;
        }
    }
    
	/* W05.33 Fix numeric_leading_zero issue make sure that the first candidate can be '0' */
    {
        U8 temp = numeric_leading_zero;

        set_leading_zero(TRUE);
        
		/* W05.36 Check the Candidates List, if empty return 0 */
		if (mmi_pen_editor_reset_candidate_and_composition_box(mmi_pen_editor_get_candidate_box(), candidate_buffer, num, MMI_TRUE))
        {
            set_leading_zero(temp);	
        }
		else
		{
        set_leading_zero(temp);
			return 0;
		}
    }
    gdi_layer_lock_frame_buffer();
    mmi_pen_editor_hide_virtual_keyboard_area();
    mmi_pen_editor_show_candidate_area(MMI_FALSE, PEN_EDITOR_CANDIDATE_ON_AND_FOCUS);
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_handwriting_style
 * DESCRIPTION
 *  Set the current handwriting Style
 * PARAMETERS
 *  style       [IN]        PEN_EDITOR_HANDWRITING_STYLE_FULL_SCREEN : Handwriting on the full screen
 *                          PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK : Handwriting with Handwriting blocks
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_handwriting_style(mmi_pen_editor_handwriting_style_enum style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_editor_handwriting_style = style;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_handwriting_style
 * DESCRIPTION
 *  To get the current handwriting style
 * PARAMETERS
 *  void
 * RETURNS
 *  PEN_EDITOR_HANDWRITING_STYLE_FULL_SCREEN : Handwriting on the full screen
 *  PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK : Handwriting with Handwriting blocks
 *****************************************************************************/
mmi_pen_editor_handwriting_style_enum mmi_pen_editor_get_handwriting_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_pen_editor_handwriting_style;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_enable_multi_block_handwriting
 * DESCRIPTION
 *  Change from the main virtual keybaord mode to the multi-block handwriting mode. Enable the stroke mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_enable_multi_block_handwriting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int changed_height = 0;
    U16 input_type_only = MMI_current_input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_editor_hide_virtual_keyboard_area();
	changed_height = mmi_pen_editor_get_candidate_box_height();
    if (changed_height < MMI_virtual_keyboard.height)
    {
        changed_height = MMI_virtual_keyboard.height;
        if (mmi_pen_editor_is_there_vk_candidate_box())
        {
            changed_height += (mmi_pen_editor_get_candidate_box_height() + 1);
        }
        mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_FALSE);
    }
    changed_height -= PEN_EDITOR_BLOCK_HEIGHT;
	gui_reset_clip();
	mmi_pen_editor_resize_content_area(changed_height);
    mmi_pen_editor_draw_handwriting_block();
    wgui_setup_virtual_keyboard(GUI_VIRTUAL_KEYBOARD_TRAY);
    if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
        || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
    {
        s32 temp_multiline_height = MMI_multiline_inputbox.height;
        MMI_BOOL temp_VKCandidate = mmi_pen_editor_is_there_vk_candidate_box();
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
           mmi_pen_editor_set_it_has_vk_candidate_box_or_not(temp_VKCandidate);
        }
        wgui_setup_virtual_keyboard(keyboard_type);
    }
    wgui_move_virtual_keyboard(
        MMI_virtual_keyboard.x,
        MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + 3);
    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
    if (!(INPUT_TYPE_NUMERIC_PASSWORD == input_type_only ||
          INPUT_TYPE_SAT_NUMERIC_PASSWORD == input_type_only) && (!g_pen_editor_disable_handwriting))
    {
		    g_multi_block_stroke_area[0].x1 = 3;
            g_multi_block_stroke_area[0].y1 =
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT +
                mmi_pen_editor_compute_candidate_input_box_height() + 4;
            g_multi_block_stroke_area[0].x2 = (UI_device_width >> 1) - 2;
		    g_multi_block_stroke_area[0].y2 = MMI_content_y + MMI_content_height - 3;
		    g_multi_block_stroke_area[1].x1 = (UI_device_width >> 1) + 1;
            g_multi_block_stroke_area[1].y1 =
                MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT +
                mmi_pen_editor_compute_candidate_input_box_height() + 4;
            g_multi_block_stroke_area[1].x2 = UI_device_width - 3;
		    g_multi_block_stroke_area[1].y2 = MMI_content_y + MMI_content_height - 3;

		mmi_pen_editor_set_handwriting_enabled_or_not(MMI_TRUE);
        mmi_pen_start_capture_strokes(
            PEN_EDITOR_STROKE_BUFFER_SIZE,
            gPenEditorStrokeBuffer,
            2,
            g_multi_block_stroke_area,
            NULL);
        memcpy(
            &g_pen_editor_original_handwriting_area,
            &g_multi_block_stroke_area[0],
            sizeof(mmi_pen_handwriting_area_struct));
        
        /*
         * 06.38 Fixing LSK/RSK didnt be properly set when changing state 
         * from Virtual Keyboard to Multi-Block HandWriting in the case of
         * Candidate Inputbox in selection state.
         */
        mmi_pen_editor_reset_LSK_and_RSK_state();

        mmi_pen_register_stroke_down_handler(mmi_pen_editor_multi_block_stroke_down_handler);
        mmi_pen_register_stroke_move_handler(NULL, NULL, mmi_pen_editor_multi_block_stroke_move_handler);
        mmi_pen_register_stroke_up_handler(mmi_pen_editor_multi_block_stroke_up_handler);

        mmi_pen_editor_hand_writing_initialize();  //forrest

        mmi_pen_begin_strokes_of_character();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_disable_multi_block_handwriting
 * DESCRIPTION
 *  Change Multi-Block handwriting to the main virtual keyboard mode. Disable the stroke mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_disable_multi_block_handwriting(void)
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
    mmi_pen_stop_capture_strokes();
    if (PEN_EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX == mmi_pen_editor_get_input_box_type())
    {
        changed_height = MMI_virtual_keyboard.height;
        mmi_pen_editor_set_virtual_keyboard_by_input_mode(MMI_current_input_mode);
        changed_height -= MMI_virtual_keyboard.height;
        mmi_pen_editor_resize_content_area(changed_height);
        RedrawCategoryControlledArea200Screen(NULL);
        return;
    }
    if (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type)
    {
		changed_height = PEN_EDITOR_BLOCK_HEIGHT;

        mmi_pen_editor_get_vk_type_by_input_mode(MMI_current_input_mode, &vk_type, &has_candidate);
        
        if (vk_type != 0xFF)
        {
            if (!mmi_pen_editor_is_there_vk_candidate_box() && has_candidate)
            {
                changed_height -= (mmi_pen_editor_get_candidate_box_height() + 1);
                mmi_pen_editor_set_it_has_vk_candidate_box_or_not(MMI_TRUE);
            }
            else if (mmi_pen_editor_is_there_vk_candidate_box() && !has_candidate)
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

        if (mmi_pen_editor_get_candidate_box_height() > MMI_virtual_keyboard.height)
        {
            changed_height -= mmi_pen_editor_get_candidate_box_height();
        }
        else
        {
            changed_height -= MMI_virtual_keyboard.height;
        }
        gdi_layer_lock_frame_buffer();
        mmi_pen_editor_resize_content_area(changed_height);
        if (PEN_EDITOR_INLINE_TEXT == mmi_pen_editor_get_input_box_type()
            || PEN_EDITOR_INLINE_MULTILINE_INPUT_BOX == mmi_pen_editor_get_input_box_type())
        {
            s32 temp_multiline_height = MMI_multiline_inputbox.height;
            MMI_BOOL temp_VKCandidate = mmi_pen_editor_is_there_vk_candidate_box();
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
                mmi_pen_editor_set_it_has_vk_candidate_box_or_not(temp_VKCandidate);
            }
            wgui_setup_virtual_keyboard(keyboard_type);
        }
        gui_move_single_line_input_box(
            mmi_pen_editor_get_candidate_box(),
            mmi_pen_editor_get_candidate_box_x(),
            MMI_virtual_keyboard.y - mmi_pen_editor_get_candidate_box_height() - 2);
        if (mmi_pen_editor_is_there_vk_candidate_box())
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
 *  mmi_pen_editor_handwriting_check_block
 * DESCRIPTION
 *  To check the position is on which block (0 : out of handwriting area)
 * PARAMETERS
 *  pos     [IN]        The position of the point to check
 * RETURNS
 *  Which block the position is on
 *****************************************************************************/
S32 mmi_pen_editor_handwriting_check_block(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 active_block = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            1,
            MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_get_candidate_box_height() + 3,
            ((UI_device_width - 2) >> 1),
            PEN_EDITOR_BLOCK_HEIGHT - mmi_pen_editor_get_candidate_box_height() + 3);
    if (ret)
    {
        active_block = 1;
    }

    ret = PEN_CHECK_BOUND(
            pos.x,
            pos.y,
            1 + ((UI_device_width - 2) >> 1),
            MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_get_candidate_box_height() + 3,
            ((UI_device_width - 2) >> 1),
            PEN_EDITOR_BLOCK_HEIGHT - mmi_pen_editor_get_candidate_box_height() + 3);
    if (ret)
    {
        active_block = 2;
    }
    return active_block;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_draw_handwriting_block
 * DESCRIPTION
 *  To draw the handwriting block area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_draw_handwriting_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
    if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
    {
        gdi_draw_solid_rect(
            0,
            MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT - 2,
            UI_device_width - 1,
            MMI_content_y + MMI_content_height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gui_fill_rectangle(
            0,
            MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT - 2,
            UI_device_width - 1,
            MMI_content_y + MMI_content_height - 1,
            c);
    }
	gdi_draw_rect(
			1,
		   	MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_get_candidate_box_height() + 3, 
			UI_device_width - 2,
			MMI_content_y + MMI_content_height - 1,
			GDI_COLOR_BLACK);
	gdi_draw_line(
			1 + ((UI_device_width - 2) >> 1),
		   	MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + mmi_pen_editor_get_candidate_box_height() + 3, 
			1 + ((UI_device_width - 2) >> 1),
			MMI_content_y + MMI_content_height - 1,
			GDI_COLOR_BLACK);
	gui_move_single_line_input_box(
			mmi_pen_editor_get_candidate_box(), 
			mmi_pen_editor_get_candidate_box_x(), 
			MMI_content_y + MMI_content_height - PEN_EDITOR_BLOCK_HEIGHT + 1);

	gui_move_single_line_input_box(
			    mmi_pen_editor_get_composition_box(), 
			    mmi_pen_editor_get_composition_box_x(), 
			    mmi_pen_editor_get_candidate_box_y() - mmi_pen_editor_get_candidate_box_height() - 2);
}


void mmi_pen_editor_inline_full_screen_redraw_handwriting_area(void)
{
    /* W06.05 Fix Background display issue in virtual keyboard */
    if (PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()&&
        (GUI_VIRTUAL_KEYBOARD_TRAY == MMI_virtual_keyboard.lang_type
         || GUI_VIRTUAL_KEYBOARD_NUMBER_DOT_TRAY == MMI_virtual_keyboard.lang_type
         || GUI_VIRTUAL_KEYBOARD_NUMBER_TRAY == MMI_virtual_keyboard.lang_type
         || GUI_VIRTUAL_KEYBOARD_PHONE_NUMBER == MMI_virtual_keyboard.lang_type))
    {
        mmi_pen_editor_draw_handwriting_block();
    }
    mmi_pen_editor_clear_and_show_virtual_keyboard_area();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_change_handwriting_area
 * DESCRIPTION
 *  Change the handwriting area according the virtual keyboard, composition box, and candidate box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_change_handwriting_area(void)
{
#ifdef __MMI_HAND_WRITING_EXCLUDE_VK_AREA__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(PEN_EDITOR_HANDWRITING_STYLE_MULTI_BLOCK == mmi_pen_editor_get_handwriting_style()))
    {
        if (mmi_pen_editor_is_handwriting_enabled())
        {
            mmi_pen_handwriting_area_struct ext_stroke;

            ext_stroke.x1 = 0;
            ext_stroke.y1 = 0;
            ext_stroke.x2 = UI_device_width - 1;
            ext_stroke.y2 = UI_device_height - 1;

            g_pen_editor_original_handwriting_area.y2 = MMI_virtual_keyboard.y;
            if (mmi_pen_editor_is_candidate_in_selection() || mmi_pen_editor_is_there_vk_candidate_box())
            {
                g_pen_editor_original_handwriting_area.y2 = mmi_pen_editor_get_candidate_box_y();
            }
            if (PEN_EDITOR_CANDIDATE_OFF != mmi_pen_editor_get_composition_state()->candidate_state)
            {
                g_pen_editor_original_handwriting_area.y2 = mmi_pen_editor_get_composition_box_y();
            }
            mmi_pen_change_handwriting_area(1, &g_pen_editor_original_handwriting_area, &ext_stroke);
        }
    }
#endif /* __MMI_HAND_WRITING_EXCLUDE_VK_AREA__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_multi_block_stroke_area
 * DESCRIPTION
 *  Set multi block stroke area
 * PARAMETERS
 *  index   [IN]    The index of the area
 *  x1       [IN]    The x coordinate of the left-top of the area
 *  y1       [IN]    The y coordinate of the left-top of the area
 *  x2       [IN]    The x coordinate of the right-botom of the area
 *  y2       [IN]    The y coordinate of the right-botom of the area
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_multi_block_stroke_area(S16 index, S32 x1, S32 y1, S32 x2, S32 y2)
{
    g_multi_block_stroke_area[index].x1 = (S16)x1;
    g_multi_block_stroke_area[index].y1 = (S16)y1;
    g_multi_block_stroke_area[index].x2 = (S16)x2;
    g_multi_block_stroke_area[index].y2 = (S16)y2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_multi_block_stroke_area
 * DESCRIPTION
 *  Get the multi block stroke area
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the first block
 *****************************************************************************/
mmi_pen_handwriting_area_struct * mmi_pen_editor_get_multi_block_stroke_area(void)
{
    return &g_multi_block_stroke_area[0];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_point_by_index
 * DESCRIPTION
 *  Get the point of a stroke by index
 * PARAMETERS
 *  index          [IN]      The index of the point
 *  point          [OUT]   The points array for storing the data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_get_point_by_index(S16 index, mmi_pen_point_struct * point)
{
    memcpy(point, &gPenEditorStrokeBuffer[index], sizeof(mmi_pen_point_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_point_by_index
 * DESCRIPTION
 *  Get the point of a stroke by index
 * PARAMETERS
 *  void
 * RETURNS
 *  The first address of stroke buffer
 *****************************************************************************/
mmi_pen_point_struct * mmi_pen_editor_get_stroke_buffer(void)
{
    return &gPenEditorStrokeBuffer[0];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_original_handwriting_area
 * DESCRIPTION
 *  Get original handwriting area
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the original handwriting area structure
 *****************************************************************************/
mmi_pen_handwriting_area_struct * mmi_pen_editor_get_original_handwriting_area(void)
{
    return &g_pen_editor_original_handwriting_area;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_get_handwriting_state
 * DESCRIPTION
 *  Get handwriting state, disabled or not
 * PARAMETERS
 *  void
 * RETURNS
 *  Handwriting state, disabled or not
 *****************************************************************************/
MMI_BOOL mmi_pen_editor_get_handwriting_state(void)
{
    return g_pen_editor_disable_handwriting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_editor_set_handwriting_disabled_or_not
 * DESCRIPTION
 *  Set handwriting state, diabled(MMI_TRUE) or not(MMI_FALSE)
 * PARAMETERS
 *  diabled_or_not               [IN]          Handwriting is disabled or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_editor_set_handwriting_disabled_or_not(MMI_BOOL diabled_or_not)
{
    g_pen_editor_disable_handwriting = diabled_or_not;
}


#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 



