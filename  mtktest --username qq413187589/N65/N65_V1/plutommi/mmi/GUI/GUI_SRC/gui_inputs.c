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
 *   gui_inputs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   General Editor - UI component
 *
 *   [Single-line input box]
 *   [Multi-line input box]
 *   [Dialer input box]
 *
 * Author:
 * -------
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#undef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR

#include "gui_inputs.h"
#include "gui_themes.h"
#include "MMI_features.h"
#include "gui_theme_struct.h"
#include "GlobalDefs.h"
#include "kal_non_specific_general_types.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"
#include "DebugInitDef.h"
#include "SimDetectionGprot.h"
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
#include "Gui_Setting.h"
#endif 
/* MTK Arabic Connectivity issue */

#ifdef __MMI_ZI_V7__
#include "ezicmn.h"
#endif 
#if defined (__MMI_ZI_ARABIC__) || defined (__MMI_ZI_PERSIAN__)
#include "zi8ARshape.h"
#endif /* defined (__MMI_ZI_ARABIC__) || defined (__MMI_ZI_PERSIAN__) */ 
/* MTK End */

/* if needs to modify this define ,remember to update the define in ChatGType.h */
#define MAX_MSG_SIZE_UCS2   256

#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
extern U32 add_template_multiline_flag;
#define MAX_EDITOR_DISP_LEN      60

#endif /* __MMI_INDIC_ALG__ */ 

#include "gui_ems.h"

/* MTK Elvis for R2L characters */
#include "BIDIDEF.h"
#include "BIDIProt.h"


#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"
#endif 
/* start vijay 20050221 */
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui.h"
#include "TouchScreenGprot.h"
#include "GlobalConstants.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* end vijay */

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
/* PMT HIMANSHU START 20050825 */
#include "IdleAppDef.h"
#include "SimDetectionGprot.h"
/* PMT HIMANSHU END 20050825 */
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 

/* MTK Elvis 20031126 */
#include "TimerEvents.h"

#include "wgui_categories.h"    /* for WCSS editor */
#include "wgui_categories_defs.h"
#include "wgui_categories_inputs.h"

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_PFAL_CC.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
MMI_BOOL gui_multi_line_input_box_clear_wcss(multi_line_input_box *b);
#endif

#if defined (__MMI_ARSHAPING_ENGINE__)
#include "ArabicGProt.h"

// for total text shaping
U16 shaping_str[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
U16 OrgToSha[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
S32 unshaped_text_len = 0;
S32 shaped_text_len;


#endif /* __MMI_ARSHAPING_ENGINE__ */ 

extern void wgui_redraw_remaining_characters_display(void);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
extern void (*dialing_keypad_phonebook_handler) (void); /* Added to disable Phonebook function key */
#endif

#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00025775 */
U8 saved_single_line_skip_moves = 0;
U8 saved_multi_line_skip_moves = 0;
U8 cursor_pos_flag = 0;
/* PMT END MAUI_00025775 */
#endif /* __MMI_INDIC_ALG__ */ 

/* MTK Terry for inline multiline issue */
extern void (*complete_inline_item_edit) (void);

/* MTK Steven 20050505 */
#ifdef __MMI_LANG_THAI__
#define isThaiChar(ch)  (((ch >= 0x0E01) && (ch <= 0x0E7F))? (1):(0))
#endif 
/* MTK End */

/*
 * Rich text
 */

typedef enum
{
    GUI_INPUT_ALIGN_LEFT,
    GUI_INPUT_ALIGN_CENTER,
    GUI_INPUT_ALIGN_RIGHT
} gui_input_alignment_enum;

#define GUI_INPUT_IS_MARKER(ch) \
                  ((ch)>= GUI_INPUT_MARKER_BEGIN && (ch) <= GUI_INPUT_MARKER_END)

#define GUI_INPUT_IS_FORMAT_MARKER(ch) \
                  (((ch) & GUI_INPUT_MARKER_FORMAT_MASK) == GUI_INPUT_MARKER_FORMAT)

#define GUI_INPUT_IS_PARAGRAPH_MARKER(ch) \
                  (((ch) & GUI_INPUT_MARKER_PARAGRAPH_MASK) == GUI_INPUT_MARKER_PARAGRAPH)

/* Format marker */

/* test 1-bit flag */
#define GUI_INPUT_CHECK_FORMAT_MARKER(ch, flag) \
                   (((ch) & (flag)) == (flag))

/* test multiple-bit flag */
#define GUI_INPUT_CHECK_SIZE_MARKER(ch,  flag)  \
                  (((ch) & GUI_INPUT_MARKER_SIZE_MASK) == (flag))

/* test 1-bit flag */
#define GUI_INPUT_CHECK_PARAGRAPH_MARKER(ch, flag) \
                   (((ch) & (flag)) == (flag))

/* test multiple-bit flag */
#define GUI_INPUT_CHECK_ALIGN_MARKER(ch, flag) \
                  (((ch) & GUI_INPUT_MARKER_ALIGN_MASK) == (flag))

#define GUI_INPUT_CHECK_LINE_SPACING_MARKER(ch, flag) \
                  (((ch) & GUI_INPUT_MARKER_LINE_SPACING_MASK) == (flag))


typedef struct
{
    color default_color;
    color curr_color;
    /* USAT */
    color default_text_bg_color;
    color curr_text_bg_color;
    U8 draw_text_bg_color;
    gui_input_alignment_enum default_alignment;
    gui_input_alignment_enum curr_alignment;
    stFontAttribute curr_font;
    U8 curr_border;         /* border not part of font attribute */
    /* USAT */
    U8 curr_strikethrough;  /* strikethrough not part of font attribute */
    /* backup the font used at the beginning of a line */
    stFontAttribute line_begin_font;
    U8 line_begin_border;
    /* USAT */
    U8 line_begin_strikethrough;
    /* attributes that are only active in the current line */
    U8 more_line_spacing;
    U8 line_separator;
} gui_input_richtext_struct;

/* USAT */
extern void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c);
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
color gui_richtext_strikethrough_color = {255, 112, 125, 240};
color gui_richtext_default_text_bg_color = {255, 255, 255, 100};
#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
MMI_BOOL pen_check_func_key_bound(S32 x,S32 y,S32 selected_key_x,S32 selected_key_y,S32 keypad_func_x,S32 keypad_func_y, S32 func_key_width,S32 func_key_height,S32 func_n_rows,S32 func_n_column);
#endif	/* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
/* barcode */
color gui_hilite_underline_color = {0, 0, 220};

/* 122 colors */
static const color g_mmi_gui_input_format_color_table[] = 
{
    {255, 0, 0, 100},
    {255, 255, 0, 100},
    {0, 255, 0, 100},
    {0, 255, 255, 100},
    {0, 0, 235, 100},   /* Avoid transparent color */
    {255, 0, 255, 100},
    {255, 255, 255, 100},
    {230, 230, 230, 100},
    {218, 218, 218, 100},
    {205, 205, 205, 100},
    {192, 192, 192, 100},
    {180, 180, 180, 100},
    {168, 168, 168, 100},
    {154, 154, 154, 100},
    {141, 141, 141, 100},
    {129, 129, 129, 100},
    {230, 0, 6, 100},
    {255, 237, 0, 100},
    {0, 152, 55, 100},
    {0, 166, 234, 100},
    {45, 29, 134, 100},
    {228, 0, 132, 100},
    {116, 116, 116, 100},
    {102, 102, 102, 100},
    {89, 89, 89, 100},
    {75, 75, 75, 100},
    {62, 62, 62, 100},
    {48, 48, 48, 100},
    {33, 33, 33, 100},
    {19, 19, 19, 100},
    {10, 10, 10, 100},
    {0, 0, 0, 100},
    {240, 148, 115, 100},
    {244, 173, 124, 100},
    {249, 200, 134, 100},
    {255, 245, 148, 100},
    {209, 224, 149, 100},
    {173, 210, 149, 100},
    {141, 199, 149, 100},
    {136, 203, 199, 100},
    {129, 207, 244, 100},
    {136, 169, 217, 100},
    {141, 147, 199, 100},
    {144, 127, 186, 100},
    {169, 134, 188, 100},
    {195, 141, 187, 100},
    {238, 155, 193, 100},
    {238, 151, 156, 100},
    {233, 98, 63, 100},
    {240, 136, 70, 100},
    {245, 175, 77, 100},
    {255, 240, 87, 100},
    {138, 208, 96, 100},
    {136, 192, 102, 100},
    {79, 176, 104, 100},
    {66, 138, 177, 100},
    {12, 188, 239, 100},
    {85, 138, 199, 100},
    {98, 109, 179, 100},
    {104, 81, 159, 100},
    {139, 85, 160, 100},
    {172, 91, 161, 100},
    {233, 102, 163, 100},
    {233, 101, 117, 100},
    {230, 0, 6, 100},
    {234, 89, 0, 100},
    {242, 143, 0, 100},
    {255, 237, 0, 100},
    {153, 192, 0, 100},
    {79, 172, 37, 100},
    {0, 152, 55, 100},
    {0, 158, 150, 100},
    {0, 166, 234, 100},
    {0, 104, 180, 100},
    {1, 70, 154, 100},
    {45, 29, 134, 100},
    {107, 18, 133, 100},
    {149, 0, 133, 100},
    {228, 0, 132, 100},
    {229, 0, 79, 100},
    {159, 0, 3, 100},
    {161, 60, 0, 100},
    {167, 98, 0, 100},
    {179, 162, 0, 100},
    {102, 132, 0, 100},
    {45, 118, 21, 100},
    {0, 105, 35, 100},
    {0, 109, 103, 100},
    {0, 113, 164, 100},
    {0, 69, 128, 100},
    {0, 43, 109, 100},
    {32, 4, 95, 100},
    {74, 0, 94, 100},
    {103, 0, 92, 100},
    {159, 0, 90, 100},
    {160, 0, 52, 100},
    {117, 0, 0, 100},
    {120, 43, 0, 100},
    {124, 70, 0, 100},
    {131, 118, 0, 100},
    {69, 96, 0, 100},
    {22, 86, 10, 100},
    {0, 76, 23, 100},
    {0, 79, 74, 100},
    {0, 82, 121, 100},
    {0, 47, 93, 100},
    {0, 23, 77, 100},
    {22, 0, 68, 100},
    {56, 0, 67, 100},
    {78, 0, 65, 100},
    {119, 0, 64, 100},
    {118, 0, 33, 100},
    {203, 187, 164, 100},
    {165, 141, 121, 100},
    {125, 99, 85, 100},
    {90, 65, 58, 100},
    {63, 41, 35, 100},
    {199, 163, 111, 100},
    {176, 130, 78, 100},
    {150, 98, 46, 100},
    {124, 74, 25, 100},
    {101, 51, 7, 100}
};

/* 147 colors */
static const color g_mmi_gui_input_format_w3c_color_table[] = 
{
    {240, 248, 255, 100},
    {250, 235, 215, 100},
    {0, 255, 255, 100},
    {127, 255, 212, 100},
    {240, 255, 255, 100},
    {245, 245, 220, 100},
    {255, 228, 196, 100},
    {0, 0, 0, 100},
    {255, 235, 205, 100},
    {0, 0, 235, 100},   /* Avoid transparent color */
    {138, 43, 226, 100},
    {165, 42, 42, 100},
    {222, 184, 135, 100},
    {95, 158, 160, 100},
    {127, 255, 0, 100},
    {210, 105, 30, 100},
    {255, 127, 80, 100},
    {100, 149, 237, 100},
    {255, 248, 220, 100},
    {220, 20, 60, 100},
    {0, 255, 255, 100},
    {0, 0, 139, 100},
    {0, 139, 139, 100},
    {184, 134, 11, 100},
    {169, 169, 169, 100},
    {0, 100, 0, 100},
    {169, 169, 169, 100},
    {189, 183, 107, 100},
    {139, 0, 139, 100},
    {85, 107, 47, 100},
    {255, 140, 0, 100},
    {153, 50, 204, 100},
    {139, 0, 0, 100},
    {233, 150, 122, 100},
    {143, 188, 143, 100},
    {72, 61, 139, 100},
    {47, 79, 79, 100},
    {47, 79, 79, 100},
    {0, 206, 209, 100},
    {148, 0, 211, 100},
    {255, 20, 147, 100},
    {0, 191, 255, 100},
    {105, 105, 105, 100},
    {105, 105, 105, 100},
    {30, 144, 255, 100},
    {178, 34, 34, 100},
    {255, 250, 240, 100},
    {34, 139, 34, 100},
    {255, 0, 255, 100},
    {220, 220, 220, 100},
    {248, 248, 255, 100},
    {255, 215, 0, 100},
    {218, 165, 32, 100},
    {128, 128, 128, 100},
    {128, 128, 128, 100},
    {0, 128, 0, 100},
    {173, 255, 47, 100},
    {240, 255, 240, 100},
    {255, 105, 180, 100},
    {205, 92, 92, 100},
    {75, 0, 130, 100},
    {255, 255, 240, 100},
    {240, 230, 140, 100},
    {230, 230, 250, 100},
    {255, 240, 245, 100},
    {124, 252, 0, 100},
    {255, 250, 205, 100},
    {173, 216, 230, 100},
    {240, 128, 128, 100},
    {224, 255, 255, 100},
    {250, 250, 210, 100},
    {211, 211, 211, 100},
    {144, 238, 144, 100},
    {211, 211, 211, 100},
    {255, 182, 193, 100},
    {255, 160, 122, 100},
    {32, 178, 170, 100},
    {135, 206, 250, 100},
    {119, 136, 153, 100},
    {119, 136, 153, 100},
    {176, 196, 222, 100},
    {255, 255, 224, 100},
    {0, 255, 0, 100},
    {50, 205, 50, 100},
    {250, 240, 230, 100},
    {255, 0, 255, 100},
    {128, 0, 0, 100},
    {102, 205, 170, 100},
    {0, 0, 205, 100},
    {186, 85, 211, 100},
    {147, 112, 219, 100},
    {60, 179, 113, 100},
    {123, 104, 238, 100},
    {0, 250, 154, 100},
    {72, 209, 204, 100},
    {199, 21, 133, 100},
    {25, 25, 112, 100},
    {245, 255, 250, 100},
    {255, 228, 225, 100},
    {255, 228, 181, 100},
    {255, 222, 173, 100},
    {0, 0, 128, 100},
    {253, 245, 230, 100},
    {128, 128, 0, 100},
    {107, 142, 35, 100},
    {255, 165, 0, 100},
    {255, 69, 0, 100},
    {218, 112, 214, 100},
    {238, 232, 170, 100},
    {152, 251, 152, 100},
    {175, 238, 238, 100},
    {219, 112, 147, 100},
    {255, 239, 213, 100},
    {255, 218, 185, 100},
    {205, 133, 63, 100},
    {255, 192, 203, 100},
    {221, 160, 221, 100},
    {176, 224, 230, 100},
    {128, 0, 128, 100},
    {255, 0, 0, 100},
    {188, 143, 143, 100},
    {65, 105, 225, 100},
    {139, 69, 19, 100},
    {250, 128, 114, 100},
    {244, 164, 96, 100},
    {46, 139, 87, 100},
    {255, 245, 238, 100},
    {160, 82, 45, 100},
    {192, 192, 192, 100},
    {135, 206, 235, 100},
    {106, 90, 205, 100},
    {112, 128, 144, 100},
    {112, 128, 144, 100},
    {255, 250, 250, 100},
    {0, 255, 127, 100},
    {70, 130, 180, 100},
    {210, 180, 140, 100},
    {0, 128, 128, 100},
    {216, 191, 216, 100},
    {255, 99, 71, 100},
    {64, 224, 208, 100},
    {238, 130, 238, 100},
    {245, 222, 179, 100},
    {255, 255, 255, 100},
    {245, 245, 245, 100},
    {255, 255, 0, 100},
    {154, 205, 50, 100}
};

/* USAT */
/* 16 colors */
static const color g_mmi_gui_input_format_w3c_text_background_color_table[] = 
{
    {169, 169, 169, 100},
    {139, 0, 0, 100},
    {255, 255, 0, 100},
    {0, 100, 0, 100},
    {0, 139, 139, 100},
    {0, 0, 139, 100},
    {139, 0, 139, 100},
    {128, 128, 128, 100},
    {255, 255, 255, 100},
    {255, 0, 0, 100},
    {255, 255, 224, 100},
    {144, 238, 144, 100},
    {224, 255, 255, 100},
    {173, 216, 230, 100},
    {255, 0, 255, 100},
    {0, 0, 0, 100}
};

#define MAX_GUI_INPUT_COLOR         (sizeof(g_mmi_gui_input_format_color_table)/sizeof(color))
#define MAX_GUI_INPUT_W3C_COLOR     (sizeof(g_mmi_gui_input_format_w3c_color_table)/sizeof(color))
/* USAT */
#define MAX_GUI_INPUT_W3C_TEXT_BG_COLOR      (sizeof(g_mmi_gui_input_format_w3c_text_background_color_table)/sizeof(color))

/*
 * WCSS
 */

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
#define PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED        0x20
#define PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER     0x40
#define PIXTEL_UI_WCSS_STAR_INPUT               0x80

/* Prevent automatically changing input method while deleting characters 
   and also avoid reentrance of gui_change_WCSS_input_method() */
static U8 WCSS_input_change_enable = 1;

void gui_change_WCSS_input_method(multi_line_input_box *b);

/* Force to change input method regardless of multitap state */
static U8 WCSS_Esc_Char = 0;

extern MMI_BOOL is_fisrt_entry_WCSS_editor;

#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#ifdef __MMI_INDIC_ALG__

extern BOOL cancelWidth;
#endif 
/* for R2L characters */
#ifdef __MMI_BIDI_ALG__
U8 visual_str[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];

/* MTK begin chat issue 2005.10.27 */
#if 0
#ifdef __MMI_MESSAGES_CHAT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MESSAGES_CHAT__ */ 
#endif

/* MTK End */
U8 MMI_bidi_input_type = BIDI_L;
U16 pwcWord[MAX_TEXT_LENGTH];
#endif /* __MMI_BIDI_ALG__ */ 
BOOL r2lMMIFlag;

/* MTK Terry for 0x81 encoding support for Phone Book */
extern S16 MMI_current_input_ext_type;
extern U8 mmi_phb_convert_to_0x81(S8 *input_name, BOOL is_convert);

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
S8 hilited_item_changed = 0;
extern void wgui_redraw_input_information_bar(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
/* GUI: multitap input object functions            */
extern U8 wgui_inputbox_information_flag;
extern S32 wgui_inputbox_information_bar_height;
extern void inline_fixed_list_goto_previous_item(void);
extern void inline_fixed_list_goto_next_item(void);

/* Auto scroll of Multiline Input text */
extern void multiline_inputbox_vertical_scroll(void);

/* START TARUN PMT 20041002 */
extern S8 g_mmi_wgui_halfline_marquee_scroll_enable;

#define MMI_HALF_LINE_MARQUEE_SCROLLING_ENABLE     1
/* END TARUN PMT 20041002 */

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
#include "SmsGuiInterfaceType.h"
#include "SettingProfile.h"
#include "MessagesResourceData.h"
#include "MessagesExDcl.h"
extern nsm_msg_struct g_nsm_msg_context;


#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__)
extern S32 wgui_inputbox_buffer_size;
#endif 

#if defined(__MMI_SMART_MESSAGE_MT__)
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"
#include "HistoryGprot.h"
extern nsm_picmsg_text_struct picmsg_text_struct;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

U8 numeric_leading_zero = TRUE;

UI_multitap_input_theme *current_multitap_input_theme = NULL;
UI_information_bar_theme *current_information_bar_theme = NULL;

#ifdef __MMI_TOUCH_DIAL_SCREEN__
MMI_ID_TYPE dialing_key_image[] = 
{
    IMG_DIALING_KEY_1,
    IMG_DIALING_KEY_2,
    IMG_DIALING_KEY_3,
    IMG_DIALING_KEY_4,
    IMG_DIALING_KEY_5,
    IMG_DIALING_KEY_6,
    IMG_DIALING_KEY_7,
    IMG_DIALING_KEY_8,
    IMG_DIALING_KEY_9,
    IMG_DIALING_KEY_STAR,
    IMG_DIALING_KEY_0,
    IMG_DIALING_KEY_HASH,
    /*shaokai add it.start.090815*/
    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
	#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
    IMG_DIALING_KEY_CALL,
    #endif
    IMG_DIALING_KEY_CALL_SLAVE,
    IMG_DIALING_KEY_PHB,
    #endif
   /*shaokai add it.end 090815*/
   /*shao kai delete it.start 090815*/
#if 0
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    IMG_DIALING_KEY_PHB,
    IMG_DIALING_KEY_CALL,
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
    IMG_DIALING_KEY_CALL_SLAVE,
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif
/*shao kai delete it.end090815*/
};

#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

/* MTK Elvis 20040611 for color dialing font */

#if 0
const color_dialing_font color_dialing_font_map[] = 
{
    {'*', {255, 0, 0, 100}},
    {'#', {0, 0, 247, 100}},
    {'+', {0, 0, 247, 100}},
    {'p', {255, 0, 0, 100}},
    {'w', {0, 255, 0, 100}},
    {'0', {0, 255, 0, 100}},
    {'1', {255, 0, 0, 100}},
    {'2', {0, 255, 0, 100}},
    {'3', {0, 0, 247, 100}},
    {'4', {255, 0, 0, 100}},
    {'5', {0, 255, 0, 100}},
    {'6', {0, 0, 247, 100}},
    {'7', {255, 0, 0, 100}},
    {'8', {0, 255, 0, 100}},
    {'9', {0, 0, 247, 100}},
    {0, {0, 0, 0, 100}},
};
#else
const color_dialing_font color_dialing_font_map[] = 
{
    {'*', {255, 0, 0, 100}},
    {'#', {0, 255, 0, 100}},
    {'+', {0, 255, 255, 100}},//{0,0,255,100}
    {'p', {0, 255, 255, 100}},//{255, 255, 0, 100}//yuyang
    {'w', {0, 255, 255, 100}},
    {'0', {0, 0, 0, 100}},
    {'1', {0, 0, 0, 100}},
    {'2', {0, 0, 0, 100}},
    {'3', {0, 0, 0, 100}},
    {'4', {0, 0, 0, 100}},
    {'5', {0, 0, 0, 100}},
    {'6', {0, 0, 0, 100}},
    {'7', {0, 0, 0, 100}},
    {'8', {0, 0, 0, 100}},
    {'9', {0, 0, 0, 100}},
    {0, {0, 0, 0, 100}},
};

#endif

#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
#define IS_FUNC_KEY 1
#define IS_NOT_FUNC_KEY 0
#endif	/* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#ifdef __MMI_INDIC_ALG__
    #define FONT_CANCEL_WIDTH(X)    cancelWidth = (X)
#else
    #define FONT_CANCEL_WIDTH(X)    
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_change_input_mode_for_smart_Abc
 * DESCRIPTION
 *  change input mode from smart abc to smart Abc
 * PARAMETERS
 *  b       [IN]        multi_line_input_box object
 * RETURNS
 *  MMI_BOOL true -> changed to Abc , false--> else
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_change_input_mode_for_smart_Abc(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type pre_ch = 0, pre2_ch = 0;
    UI_buffer_type tmp_text_p = b->cursor_p;
    UI_character_type separator[] = {'.','!','?',0x00};
    U8 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_current_input_mode != INPUT_MODE_SMART_LOWERCASE_ABC)
    {
        return MMI_FALSE;
    }
    
    if (b->text == NULL || tmp_text_p == b->text)
    {
        return MMI_FALSE;
    }
    
    UI_STRING_GET_PREVIOUS_CHARACTER(tmp_text_p,pre_ch);
    
    if(tmp_text_p == b->text)
    {
        return MMI_FALSE;
    }

    UI_STRING_GET_PREVIOUS_CHARACTER(tmp_text_p,pre2_ch);
    
    if(pre_ch != (UI_character_type)0x20)
    {
        return MMI_FALSE;
    }
    
    while(pre2_ch != separator[idx])
    {
        if(((UI_character_type)0x00) == separator[idx])
        {
            return MMI_FALSE;
        }
        idx++;
    }
    
    MMI_current_input_mode = INPUT_MODE_SMART_FIRST_UPPERCASE_ABC;
    change_multiline_inputbox_mode(INPUT_MODE_SMART_FIRST_UPPERCASE_ABC);
    wgui_redraw_input_information_bar();
    return MMI_TRUE;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  set_leading_zero
 * DESCRIPTION
 *  set the flag..whether zero is allowed as first number or not
 *  Input Parameter      u8 u8type
 * PARAMETERS
 *  u8type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_leading_zero(U8 u8type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numeric_leading_zero = u8type;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multitap_input_current_theme
 * DESCRIPTION
 *  Applies the current theme for a multitap input object
 * PARAMETERS
 *  m       [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multitap_input_current_theme(multitap_input *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->normal_text_color = current_multitap_input_theme->normal_text_color;
    m->selected_text_color = current_multitap_input_theme->selected_text_color;
    m->selector_color = current_multitap_input_theme->selector_color;
    m->f = current_multitap_input_theme->f;
    m->text_font = current_multitap_input_theme->text_font;
    m->text_gap = current_multitap_input_theme->text_gap;
    m->flags |= current_multitap_input_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multitap_input_theme
 * DESCRIPTION
 *  Applies the given theme to a multitap input object
 * PARAMETERS
 *  m       [IN]        Is the multitap input object
 *  t       [IN]        Is the theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multitap_input_theme(multitap_input *m, UI_multitap_input_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->normal_text_color = t->normal_text_color;
    m->selected_text_color = t->selected_text_color;
    m->selector_color = t->selector_color;
    m->f = t->f;
    m->text_font = t->text_font;
    m->text_gap = t->text_gap;
    m->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multitap_input_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multitap_input_text(multitap_input *b, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height;
    S32 width = b->width;
    S32 height = b->height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text = text;
    gui_set_font(b->text_font);
    Get_StringWidthHeight_multitap((U8*) b->text, b->text_gap, &string_width, &string_height);
    if (b->flags & UI_MULTITAP_INPUT_CENTER_X)
    {
        b->text_x = (width >> 1) - (string_width >> 1);
    }
    else
    {
        b->text_x = 0;
    }
    if (b->flags & UI_MULTITAP_INPUT_CENTER_Y)
    {
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 0;
    }
    b->length = gui_strlen(b->text);
    b->current_position = b->length - 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_multitap_input
 * DESCRIPTION
 *  Applies the given theme to a multitap input object
 *  
 *  Note: Each key on a keypad requires one multitap input object.
 *  For example, the text for multitap input for key 2 would be "ABC2"
 * PARAMETERS
 *  b               [?]         
 *  x               [IN]        Is the left-top corner
 *  y               [IN]        Is the left-top corner
 *  width           [IN]        Is the width of the multitap-input object
 *  height          [IN]        Is the height of the multitap-input object
 *  text            [IN]        Is a pointer to the string containing all the characters
 *  m(?)            [IN]        Is the multitap input object
 *  possible(?)     [IN]        With this multitap-input object.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multitap_input(multitap_input *b, S32 x, S32 y, S32 width, S32 height, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->flags = 0;
    b->text = text;
    gui_set_multitap_input_current_theme(b);
    /* Autocalculate the text position based on font   */
    gui_set_font(b->text_font);
    /* PMT dara added for multitap thai */
    Get_StringWidthHeight_multitap((U8*) b->text, b->text_gap, &string_width, &string_height);

    if (b->flags & UI_MULTITAP_INPUT_CENTER_X)
    {
        b->text_x = (width >> 1) - (string_width >> 1);
    }
    else
    {
        b->text_x = 0;
    }
    if (b->flags & UI_MULTITAP_INPUT_CENTER_Y)
    {
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 0;
    }
    b->length = gui_strlen(b->text);
    b->current_position = b->length - 1;
    b->input_complete_callback = UI_dummy_function;
    b->input_callback = UI_dummy_function_character;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_multitap_input
 * DESCRIPTION
 *  move multitap to x , y position
 * PARAMETERS
 *  b           [?]         
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_multitap_input(multitap_input *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_multitap_input
 * DESCRIPTION
 *  resize  multitap
 * PARAMETERS
 *  b           [?]         
 *  width       [IN]        Width of multitap
 *  height      [IN]        Height of multitap
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_multitap_input(multitap_input *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width, string_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    /* Autocalculate the text position based on font   */
    gui_set_font(b->text_font);
    /* PMT dara added for Multitap thai */
    Get_StringWidthHeight_multitap((U8*) b->text, b->text_gap, &string_width, &string_height);

    if (b->flags & UI_MULTITAP_INPUT_CENTER_X)
    {
        b->text_x = (width >> 1) - (string_width >> 1);
    }
    else
    {
        b->text_x = 0;
    }
    if (b->flags & UI_MULTITAP_INPUT_CENTER_Y)
    {
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multitap_input_callbacks
 * DESCRIPTION
 *  Sets the callback functions for a multitap input object
 *  
 *  See the documentation for the operation of the callback functions.
 * PARAMETERS
 *  b                           [?]         
 *  input_callback              [IN]        Is the function that is called whenever the
 *  input_complete_callback     [IN]        Is the function that is called when
 *  the(?)                      [IN]        Input character is confirmed.
 *  m(?)                        [IN]        Is the multitap input object
 *  This(?)                     [IN]        Causes the timer associated witht the multitap object
 *  state(?)                    [IN]        Of the multitap inputobject changes
 *  to(?)                       [IN]        Expire and call the input_complete_callback function)
 *  ke(?)                       [IN]        (Ex: in "ABC2", the user has selected "B" and releases the key,
 *  in(?)                       [IN]        (Ex: in "ABC2", the user has selected "B" and releases the key,
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multitap_input_callbacks(
        multitap_input *b,
        void (*input_callback) (UI_character_type),
        void (*input_complete_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->input_complete_callback = input_complete_callback;
    b->input_callback = input_callback;
}


/*****************************************************************************
 * FUNCTION
 *  gui_change_multitap_input_state
 * DESCRIPTION
 *  Causes the multitap input object to change its state
 *  
 *  Example, if "ABC2" is now highlighting "A", calling this
 *  function will cause it to highlight "B".
 *  This also causes the input_callback function to be called.
 *  This function is normally called on key-down or key-repeat
 * PARAMETERS
 *  b           [?]         
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_multitap_input_state(multitap_input *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry for null multitap */
    if (0 == b->length)
    {
        return;
    }
    b->current_position++;
    if (b->current_position >= b->length)
    {
        b->current_position = 0;
    }
    /* MTK Terry for multitap length > lcm width */
    if (b->text_x <= 0)
    {
        S32 string_width = 0, string_height = 0;

        gui_set_font(b->text_font);
        Get_StringWidthHeight_multitap((U8*) b->text, b->text_gap, &string_width, &string_height);
        if (b->current_position > ((b->length) >> 1))
        {
            b->text_x = b->width - string_width;
        }
        else
        {
            b->text_x = 0;
        }
    }
    b->input_callback(b->text[b->current_position]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multitap_input_complete
 * DESCRIPTION
 *  Completes the input in the current multitap object
 *  
 *  This also causes the input_complete_callback function to be called.
 *  This function is normally called on key-up
 * PARAMETERS
 *  b           [?]         
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multitap_input_complete(multitap_input *b)
{
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Gurinder - It will chnage the cursor location on multitap complete */
    /*
     * Justin: it will not invokes gui_show_multi_line_inputbox on multitap completion
     * * and it needs to change input method by itself
     */
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        /* To Solve Input Mode Change Bug - Gurinder 4/5/2003 */
        WCSS_Esc_Char = 1;
        gui_change_WCSS_input_method(&MMI_multiline_inputbox);
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    b->current_position = b->length - 1;
    b->input_complete_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_multitap_input
 * DESCRIPTION
 *  Displays the multitap input object
 * PARAMETERS
 *  b           [?]         
 *  m(?)        [IN]        Is the multitap input object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_multitap_input(multitap_input *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 sy1, sy2;
    S32 text_x, text_y;
    color text_color;
    UI_filled_area *f;

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    UI_filled_area fTemp;
#endif 
    UI_character_type current_character;
    S32 i;
    S32 character_width;
    UI_string_type text = b->text;

#ifdef __MMI_INDIC_ALG__

    S32 character_height;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;
    y1 = b->y;
    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;
    text_x = b->text_x + x1;
    text_y = b->text_y + y1;
    sy1 = y1;
    sy2 = y2;
    f = b->f;

    if ((b->f->flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        sy1 += 2;
        sy2 -= 2;
    }
    else if (b->f->flags & UI_FILLED_AREA_BORDER)
    {
        sy1 += 1;
        sy2 -= 1;
    }
    gui_push_clip();
    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    /* Pixtel - Gurinder - 2/6/4 - Dont show mutlitap shadow if __MMI_INSCREEN_MULTILINE_TEXTBOX__ is defined. */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    fTemp = *f;
    if (MMI_multi_line_inputbox_present)
    {
        if (f->flags & UI_FILLED_AREA_SHADOW)
        {
            fTemp.flags &= ~UI_FILLED_AREA_SHADOW;
        }
    }
    gui_draw_filled_area(x1, y1, x2, y2, &fTemp);
#else /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    gui_push_text_clip();
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_font(b->text_font);

    for (i = 0; i < b->length; i++)
    {
        current_character = gui_get_next_character(&text);  /* get next character of text */

        /* HACK: Space character should be displayed as 0x86 but input as 0x20  */
        if (current_character == (UI_character_type) 0x20)
        {
            current_character = (UI_character_type) 0x86;
        }
        /* get character width in pixels */
        character_width = gui_get_character_width(current_character);
        /* set text xolor */
        text_color = b->normal_text_color;

    #if defined(__MMI_INDIC_ALG__)
        /*ADDED VALUE 134 FOR DOT */
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) || current_character == 46 || current_character == 134)

        {

            ire_get_multitap_text_x(&text_x, current_character, b->length, i);

        }
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_text_x[text_x]:%d  ", text_x);

    #endif /* defined(__MMI_INDIC_ALG__) */ 


        if (i == b->current_position)
        {

        #if defined(__MMI_INDIC_ALG__)
            if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))

            {
                Get_CharWidthHeight(current_character, &character_width, &character_height);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_character_width[character_width]:%d  ",
                                     character_width);
                gui_fill_rectangle(
                    text_x - (b->text_gap - 1),
                    sy1,
                    text_x + b->text_gap + character_width - 2,
                    sy2,
                    b->selector_color);
            }
            else

        #endif /* defined(__MMI_INDIC_ALG__) */ 


                gui_fill_rectangle(
                    text_x - (b->text_gap - 1),
                    sy1,
                    text_x + b->text_gap + character_width - 2,
                    sy2,
                    b->selector_color);
            text_color = b->selected_text_color;
        }
        /* MTK Elvis for R2L characters */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(text_x + character_width, text_y);
        }
        else
        {
            gui_move_text_cursor(text_x, text_y);
        }
        

        /* gui_move_text_cursor(text_x,text_y); */
        gui_set_text_color(text_color);
        gui_print_character(current_character);
        text_x += b->text_gap + character_width;
    }
    gui_pop_text_clip();
    gui_pop_clip();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_multitap_input_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  index               [?]         
 *  char_index(?)       [OUT]       
 * RETURNS
 *  whether the point is inside multitap input
 *****************************************************************************/
BOOL gui_multitap_input_translate_pen_position(multitap_input *b, S32 x, S32 y, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FIXME. Hindi code has potential problems */
    S32 i;
    S32 xoffset = b->x + b->text_x;
    UI_string_type text = b->text;
    UI_character_type current_character;
    S32 character_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);

    if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height) && x >= xoffset)
    {
        for (i = 0; i < b->length; i++)
        {
            current_character = gui_get_next_character(&text);

            /* HACK: Space character should be displayed as 0x86 but input as 0x20  */
            if (current_character == (UI_character_type) 0x20)
            {
                current_character = (UI_character_type) 0x86;
            }
            character_width = gui_get_character_width(current_character);

        #if defined(__MMI_INDIC_ALG__)
            if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) || current_character == 46)
            {
                ire_get_multitap_text_x(&xoffset, current_character, b->length, i);
            }
        #endif /* defined(__MMI_INDIC_ALG__) */ 


            xoffset += b->text_gap + character_width;
            if (xoffset > x)
            {
                *index = i;
                return MMI_TRUE;
            }
        }

        return MMI_FALSE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_validation_function
 * DESCRIPTION
 *  dummy validation function
 * PARAMETERS
 *  text            [IN]        
 *  cursor_p        [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_validation_function(UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(text);
    UI_UNUSED_PARAMETER(cursor_p);
    UI_UNUSED_PARAMETER(text_length);
}

/* GUI: Blinking cursor functions   */

S32 UI_cursor_x1 = 0;                   /* cursor x1 postioon */
S32 UI_cursor_y1 = 0;                   /* cursor y1 position */
S32 UI_cursor_x2 = 0;                   /* cursor x2 postion */
S32 UI_cursor_y2 = 0;                   /* cursor y2position */

color UI_cursor_color = {0, 0, 0, 0};   /* cursor color black */

#if(UI_BLINKING_CURSOR_SUPPORT)

#define UI_CURSOR_BACKUP_BITMAP_SIZE   256
#define UI_CURSOR_MAX_HEIGHT           30

extern void StopTimer(U16 nTimerId);
extern void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr);
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);
U8 UI_cursor_backup_bitmap_data[UI_CURSOR_BACKUP_BITMAP_SIZE];
U8 UI_cursor_blink_flag = 0;            /* blinking flag of cursor */

/* cusror bitmap */
gdi_image_cache_bmp_struct UI_cursor_backup_bitmap=
{
    0,
    0,
    UI_cursor_backup_bitmap_data
};


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_blink_cursor
 * DESCRIPTION
 *  show blinking crusor in input box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_blink_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_cursor_x1 == 0 && UI_cursor_y1 == 0 && UI_cursor_x2 == 0 && UI_cursor_y2 == 0)
    {
        return;
    }

    gui_reset_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if (UI_cursor_blink_flag)   /* if blinking curosr flag is set */
    {
        gui_fill_rectangle(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
        UI_cursor_blink_flag = 0;
    }
    else
    {
        gdi_image_cache_bmp_draw(UI_cursor_x1, UI_cursor_y1, &UI_cursor_backup_bitmap);
        UI_cursor_blink_flag = 1;
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    StartTimer(BLINKING_CURSOR, UI_CURSOR_WAIT_TIME, UI_inputbox_blink_cursor);
}


/*****************************************************************************
 * FUNCTION
 *  UI_inputbox_show_cursor
 * DESCRIPTION
 *  show blinking crusor in input box
 * PARAMETERS
 *  x1      [IN]        X1 position of cursor
 *  y1      [IN]        Y1 position of cursor
 *  x2      [IN]        X2 position of cursor
 *  y2      [IN]        Y2 position of cursor
 *  c       [IN]        Color of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void UI_inputbox_show_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BLINKING_CURSOR);

    if (y2 - y1 > UI_CURSOR_MAX_HEIGHT)
    {
        y1 = y2 - UI_CURSOR_MAX_HEIGHT;
    }
    
    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &UI_cursor_backup_bitmap);  /* get bitmp of bliknkig cursor */
    gui_fill_rectangle(x1, y1, x2, y2, c);
    StartTimer(BLINKING_CURSOR, UI_CURSOR_WAIT_TIME, UI_inputbox_blink_cursor);
    UI_cursor_blink_flag = 0;
}
void UI_inputbox_pre2_show_cursor(void)
{
    gui_reset_clip();
    gui_lock_double_buffer();
	UI_inputbox_show_cursor(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);

}
void UI_inputbox_pre_show_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    StopTimer(BLINKING_CURSOR);

    if (y2 - y1 > UI_CURSOR_MAX_HEIGHT)
    {
        y1 = y2 - UI_CURSOR_MAX_HEIGHT;
    }
    
    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    StartTimer(BLINKING_CURSOR, 1, UI_inputbox_pre2_show_cursor);
    UI_cursor_blink_flag = 0;
}

#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

void UI_inputbox_pre2_show_fixed_cursor(void)
{
    gui_reset_clip();
    gui_lock_double_buffer();
    gui_fill_rectangle(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2, UI_cursor_color);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(UI_cursor_x1, UI_cursor_y1, UI_cursor_x2, UI_cursor_y2);
}

void UI_inputbox_pre_show_fixed_cursor(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    StopTimer(BLINKING_CURSOR);
    
    UI_cursor_x1 = x1;
    UI_cursor_y1 = y1;
    UI_cursor_x2 = x2;
    UI_cursor_y2 = y2;
    UI_cursor_color = c;
    StartTimer(BLINKING_CURSOR, 1, UI_inputbox_pre2_show_fixed_cursor);
}

/* GUI: single line input box functions   */

UI_single_line_input_box_theme *current_single_line_input_box_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_single_line_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme for the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_single_line_input_box_current_theme(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_single_line_input_box_theme->normal_filler;
    b->disabled_filler = current_single_line_input_box_theme->disabled_filler;
    b->selected_filler = current_single_line_input_box_theme->selected_filler;
    b->normal_text_color = current_single_line_input_box_theme->normal_text_color;
    b->disabled_text_color = current_single_line_input_box_theme->disabled_text_color;
    b->selected_text_color = current_single_line_input_box_theme->selected_text_color;
    b->selection_color = current_single_line_input_box_theme->selection_color;
    b->selection_text_color = current_single_line_input_box_theme->selection_text_color;
    b->cursor_color = current_single_line_input_box_theme->cursor_color;
    b->text_font = current_single_line_input_box_theme->text_font;
    b->text_gap = current_single_line_input_box_theme->text_gap;
    b->mask_character = current_single_line_input_box_theme->mask_character;
    b->flags |= current_single_line_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_single_line_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_single_line_input_box_theme(single_line_input_box *b, UI_single_line_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = t->normal_filler;
    b->disabled_filler = t->disabled_filler;
    b->selected_filler = t->selected_filler;
    b->normal_text_color = t->normal_text_color;
    b->disabled_text_color = t->disabled_text_color;
    b->selected_text_color = t->selected_text_color;
    b->selection_color = t->selection_color;
    b->selection_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->mask_character = t->mask_character;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_clear
 * DESCRIPTION
 *  clearthe single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_clear(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
    }
    else
    {
        b->text[0] = '\0';
        b->text[1] = 0;
        b->text_length = 2;
    }
    b->current_text_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        b->available_length = b->allocated_length;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  The buffer is automatically allocated by the inputbox.
 *  The buffer is set to blank on creation of this object.
 *  See also gui_destroy_single_line_input_box()
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the inputbox
 *  height      [IN]        Is the height of the inputbox
 *  length      [IN]        Is the length of the buffer to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box(single_line_input_box *b, S32 x, S32 y, S32 width, S32 height, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) gui_malloc(length * sizeof(UI_character_type));
    b->allocated_length = length;
    b->available_length = length;
    /* initilze the single input box */
    gui_single_line_input_box_clear(b);
    b->current_text_p = b->text;
    b->text_offset_x = 0;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    /* set theme of single input box */
    gui_set_single_line_input_box_current_theme(b);
    b->validation_callback = UI_dummy_validation_function;  /* set validation input box func handler to dummy */
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->text_x = 2 + b->text_gap;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
    b->UCS2_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box_use_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer is set to blank on creation of this object.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the inputbox
 *  height      [IN]        Is the height of the inputbox
 *  buffer      [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length      [IN]        Is the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box_use_buffer(
        single_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    gui_single_line_input_box_clear(b);
    b->current_text_p = b->text;
    b->text_offset_x = 0;
    gui_set_single_line_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->text_x = 2 + b->text_gap;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
    b->UCS2_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box_set_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * VJ
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box_set_buffer(
        single_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type text;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;                           /* start x position of single lien input box */
    b->y = y;                           /* stat y position of single line inputr box */
    b->width = width;                   /* width of single line input box */
    b->height = height;                 /* heightof ingle lien input box */
    b->text = (UI_buffer_type) buffer;  /* set text of single lie input box */
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;

    #if defined(__MMI_INDIC_ALG__)
    IRE_RESET_LANGUAGE_VARIABLES();
    #endif

    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(dummy_c);
            #endif

            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        b->current_text_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(dummy_c);
            #endif

            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
        }
        b->text_length = text_length;
        b->last_position_p = b->current_text_p;
    }
    else
    {
        b->text_length = 0;
    }
    b->text_offset_x = 0;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    /* set theme of single line input box */
    gui_set_single_line_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->text_x = 2 + b->text_gap;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_single_line_input_box_set_buffer_first_position
 * DESCRIPTION
 *  set the current text to first position straing of text
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * VJ
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_single_line_input_box_set_buffer_first_position(
        single_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;
    b->text_offset_x = 0;
    b->flags = 0;
    b->ext_flags = 0;
    b->grid_width = 0;
    gui_set_single_line_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->text_x = 2 + b->text_gap;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_single_line_input_box
 * DESCRIPTION
 *  Moves a single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object (pre-allocated)
 *  x       [IN]        Is the left-top corner
 *  y       [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_single_line_input_box(single_line_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_show_cursor
 * DESCRIPTION
 *  Displays the cursor in a single-line inputbox (internal function)
 *  
 *  This function is used internally.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  x           [IN]        Is the left-top corner of the cursor
 *  y           [IN]        Is the left-top corner of the cursor
 *  height      [IN]        Is the height of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_show_cursor(single_line_input_box *b, S32 x, S32 y, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > (b->y + b->height) 
        || (y + height) < b->y 
        || x < b->x 
        || x+1 >= b->x + b->width)
        StopTimer(BLINKING_CURSOR);
    else
        UI_inputbox_pre_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_cursor_x1 = x;
    UI_cursor_y1 = y;
    UI_cursor_x2 = x+1;
    UI_cursor_y2 = y+height - 1;

    gui_fill_rectangle(x, y, x + 1, y + height - 1, c);
#endif 
}

#if defined(__MMI_ARSHAPING_ENGINE__)

#include "MessagesresourceData.H"
extern U16 GetActiveScreenId(void);

S32 gui_multi_line_mapping_org_to_sha(S32 position)
{
    if(position > unshaped_text_len)  // temp solution, it should not happen !
        return (position - unshaped_text_len) + shaped_text_len; 

    if(GetActiveScreenId() != SCR_ID_MSG_EMS_OBJECT_LIST) //sc.wu predefined animation
        {
            MMI_ASSERT(0<=position && position<=unshaped_text_len+1); // include NULL char
        }
    else
        {
           if(0<=position && position<=unshaped_text_len+1)
   	        position=0;
        }
        
    return OrgToSha[position];
}
S32 gui_multi_line_mapping_sha_to_org(S32 position)
{
    int l,r,m;
    if(position > shaped_text_len)  // temp solution for b->line_after_cursor_line_last_p, we should remove this variable.
        return (position - shaped_text_len) + unshaped_text_len;

    if(GetActiveScreenId() != SCR_ID_MSG_EMS_OBJECT_LIST)
    {
        MMI_ASSERT(0<= position && position <= shaped_text_len+1);
    }
    else
    {
        if(0<=position && position<=unshaped_text_len+1)
        position=0;
    }
    
    l = 0;
    r = unshaped_text_len+1; // include NULL char
    m = 0;
    while(l<=r)
    {
		int cmp;
        m = (l+r) >> 1;
		cmp = OrgToSha[m] - position;
        if(cmp==0 ) 
			break;
		else if(cmp<0) 
			l=m+1; 
		else 
			r=m-1;
    }

    // seek to the first position
    while(m>0)
        if(OrgToSha[m-1]==position) m--; else break;

    return m;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_show_single_line_input_box
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK modify for stacked character--Thai */
void gui_show_single_line_input_box(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_single_line_input_box_ext(b, -1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_single_line_input_box_ext
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK modify for stacked character--Thai */
void gui_show_single_line_input_box_ext(single_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, cx, cy, ch;
    S32 sy1, sy2;
    color text_color;
    UI_filled_area *f;
    U8 selection_flag = 0, overwrite_mode_flag = 0, set_cursor_flag = 0;
    UI_character_type current_character = 0, pre2_character = 0, pre_character = 0;
    S32 character_width = 0, box_width, current_text_width, text_height;
    UI_buffer_type previous_text_p;
    UI_buffer_type current_text_p;
    U32 flags = b->flags;
    U8 done = 0;
    S32 text_x, text_y, total_width = 0;
    U8 cursor_displayed_flag = 0;
    S32 text_gap = b->text_gap;
    color b_normal_text_color = b->normal_text_color;
    color b_selection_text_color = b->selection_text_color;
    color b_selection_color = b->selection_color;
    UI_character_type mask_character = b->mask_character;
    UI_buffer_type b_current_text_p;
    U8 second_word_highlight = 0;
    U8 word_highlight = 0;
    U8 border_type = 0;
    PMT_BIDI_TYPES default_direction = BIDI_L;
/* START PMT PATCH04052007 */
#if defined (__MMI_BIDI_ALG__)
/* END PMT PATCH04052007 */
    UI_buffer_type temp_p;
    UI_character_type next_char = 0;
/* START PMT PATCH04052007 */
#endif /* __MMI_BIDI_ALG__ */ 
/* END PMT PATCH04052007 */
    
#if defined(__MMI_ARSHAPING_ENGINE__)
    UI_buffer_type backup_text = NULL;
#endif
    

#ifdef __MMI_INDIC_ALG__

    U16 single_line_disp_cluster[MAX_EDITOR_DISP_LEN];
    PU8 single_line_temp_p = b->text;
    PU8 single_line_prev_p = b->text;
    PU8 single_line_curr_p = b->text;
    S32 single_editor_moves = 1;    /* for skipping by cluster */
 
#endif /* __MMI_INDIC_ALG__ */ 


#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U8 *temp_text_pt = NULL;
    U8 *temp_cursor_p = NULL;
    U16 visual_str_len;
    U16 visual_cur_pos;
    U16 logical_hilight_start;
    U16 logical_hilight_end;
    U16 visual_hilight_start;
    U16 visual_hilight_end;
    UI_buffer_type temp_hilight_start = NULL;
    UI_buffer_type temp_hilight_end = NULL;
    U32 iCount;
    pBOOL arabic_char_flag = MMI_FALSE;
    U8 lastest_char_type;
    pBOOL BIDI_done_flag = MMI_FALSE;
    S32 text_len;


#endif /* __MMI_BIDI_ALG__ */ 
/*START PMT MAUI_00026933 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_INDIC_ALG__)
	U8 arabic_indic_flag =0;
#endif
/*END PMT MAUI_00026933 */
#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type next_character = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
    overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif 
    

#if defined(__MMI_ARSHAPING_ENGINE__)
   if( b->text_length >ENCODING_LENGTH ) // not only null ending
    {
    	int i;
        mmi_ucs2ncpy((S8*) shaping_str, (const S8*)b->text, (b->text_length / ENCODING_LENGTH) - 1);
        shaping_str[MAX_TEXT_LENGTH - 1] = 0;
        backup_text = b->text;
        if (b->text_length < MAX_TEXT_LENGTH * ENCODING_LENGTH)
            unshaped_text_len = text_len = (b->text_length / 2) - 1;
        else
            unshaped_text_len = text_len = MAX_TEXT_LENGTH - 1;
        
		for(i=0;i<=text_len;i++) OrgToSha[i] = i;
        ArabicShapeEngine2_ext((U16*) & text_len, (U16*) shaping_str, (U16*) OrgToSha, NULL);
        b->text = (UI_buffer_type)shaping_str;
        shaped_text_len = text_len;
		OrgToSha[unshaped_text_len] = shaped_text_len;
		OrgToSha[unshaped_text_len+1] = shaped_text_len+1;

        b->current_text_p = b->text + gui_multi_line_mapping_org_to_sha((b->current_text_p - backup_text)/2)*2;

        if ( (b->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
        {
            if(b->highlight_start_position - backup_text > b->text_length)
                b->highlight_start_position = backup_text + b->text_length;
            if(b->highlight_end_position - backup_text > b->text_length)
                b->highlight_end_position = backup_text + b->text_length;

            b->highlight_start_position = b->text 
                + gui_multi_line_mapping_org_to_sha((b->highlight_start_position - backup_text)/2)*2;
            b->highlight_end_position = b->text 
                + gui_multi_line_mapping_org_to_sha((b->highlight_end_position - backup_text)/2)*2;
        }
        if ( (b->flags & UI_SINGLE_LINE_INPUT_BOX_SECOND_WORD_HIGHLIGHT) && b->second_highlight_start_position != NULL)
        {
            if(b->second_highlight_start_position - backup_text > b->text_length)
                b->second_highlight_start_position = backup_text + b->text_length;
            if(b->second_highlight_end_position - backup_text > b->text_length)
                b->second_highlight_end_position = backup_text + b->text_length;

            b->second_highlight_start_position = b->text 
                + gui_multi_line_mapping_org_to_sha((b->second_highlight_start_position - backup_text)/2)*2;
            b->second_highlight_end_position = b->text 
                + gui_multi_line_mapping_org_to_sha((b->second_highlight_end_position - backup_text)/2)*2;
        }
        
        b->last_position_p = b->text + (shaped_text_len+1)*2; // initialize
    }
#endif
    previous_text_p = b->text;
    current_text_p = b->text;
    b_current_text_p = b->current_text_p;


   if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    }

#ifdef __MMI_BIDI_ALG__
    /* MTK Terry for BIDI Issue */
    if ((((b->text_length >> 1) - 1) != 0) && (b->text_length > 0))
    {
        bidi_get_char_type(b->text, (U8*) & default_direction);
        if (default_direction == BIDI_R || default_direction == AL || default_direction == AN)
            default_direction = BIDI_R;
        else
            default_direction = BIDI_L;

        for (iCount = 0; iCount < (U32) ((b->text_length >> 1) - 1); iCount++)
        {
            bidi_get_char_type((U8*) (b->text + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
            if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
            {
                arabic_char_flag = MMI_TRUE;
                break;
            }
        }
    }

   if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
   if((((b->text_length>>1)-1) !=0) && (b->text_length > 0))
    {
        bidi_get_char_type(b->text, (U8*) & default_direction);
        logical_cur_pos = ((b->current_text_p - b->text) + 1) / ENCODING_LENGTH;

        if (flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            temp_hilight_start = b->highlight_start_position;
            temp_hilight_end = b->highlight_end_position;

            logical_hilight_start = (b->highlight_start_position - b->text) >> 1;
            logical_hilight_end = (b->highlight_end_position - b->text) >> 1;
        }
        else if (flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            temp_hilight_start = b->highlight_start_position;
            temp_hilight_end = b->highlight_end_position;

            flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;

            b->highlight_start_position = b->current_text_p - ENCODING_LENGTH;
            b->highlight_end_position = b->current_text_p;

            logical_hilight_start = (b->highlight_start_position - b->text) >> 1;
            logical_hilight_end = (b->highlight_end_position - b->text) >> 1;
        }
        else
        {
            logical_hilight_start = 0;
            logical_hilight_end = 0;
        }

        #ifdef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR
        if (arabic_char_flag)
        #else
        if (default_direction == BIDI_R || default_direction == AL|| default_direction == AN)
        #endif
            default_direction = BIDI_R;
        else
            default_direction = BIDI_L;
        
        //disable highlight when arabic character exist
        if(arabic_char_flag)
        {
            logical_hilight_start = 0;
            logical_hilight_end = 0;
        }

        bidi_main(
                b->text,
                (U16) mmi_ucs2strlen((const S8*)b->text),
                logical_cur_pos,
                visual_str,
                &visual_str_len,
                &visual_cur_pos,
                (pBOOL)(default_direction == BIDI_R?TRUE:FALSE),
                MMI_bidi_input_type,
                logical_hilight_start,
                logical_hilight_end,
                &visual_hilight_start,
                &visual_hilight_end);

        BIDI_done_flag = MMI_TRUE;

        temp_text_pt = b->text;
        b->text = visual_str;
        temp_cursor_p = b->current_text_p;
        b->current_text_p = b->text + visual_cur_pos * ENCODING_LENGTH;

        previous_text_p = b->text;
        current_text_p = b->text;
        b_current_text_p = b->current_text_p;

        if (flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            b->highlight_start_position = b->text + (visual_hilight_start * ENCODING_LENGTH);
            b->highlight_end_position = b->text + (visual_hilight_end * ENCODING_LENGTH);
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

#ifdef __MMI_INDIC_ALG__

    memset(single_line_disp_cluster, 0, sizeof(single_line_disp_cluster));
    single_line_temp_p = b->text;
    single_line_prev_p = b->text;
    single_line_curr_p = b->text;

#endif /* __MMI_INDIC_ALG__ */ 


    x1 = b->x;                  /* start x position of single line input box */
    y1 = b->y;                  /* start y position of single line input box */
    x2 = x1 + b->width - 1;     /* end x position of single line input box */
    y2 = y1 + b->height - 1;    /* end y position of single line input box */
    sy1 = y1;
    sy2 = y2;
    /* MTK Leo add 1205 */
    if (flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT)
    {
        text_gap = 0;
    }
    /* MTK Leo end 1205 */
    if (flags & UI_SINGLE_LINE_INPUT_BOX_STATE_SELECTED)
    {
        f = b->selected_filler;
        text_color = b->selected_text_color;
    }
    else if (flags & UI_SINGLE_LINE_INPUT_BOX_STATE_DISABLED)
    {
        f = b->disabled_filler;
        text_color = b->disabled_text_color;
    }
    else
    {
        f = b->normal_filler;
        text_color = b->normal_text_color;
    }
    if ((f->flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        sy1 += 3;
        sy2 -= 3;
        border_type = 2;
    }
    else if (f->flags & UI_FILLED_AREA_BORDER)
    {
        sy1 += 2;
        sy2 -= 2;
        border_type = 1;
    }
    /* PMT VIKAS START 20050524 */
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    //PMT VIKAS START 20050630
    // remove the function call.
    //gui_single_line_disable_transparent_effect(&f);// to disable transparent effect flag for single line edit
    //PMT VIKAS END 20050630
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 
    /* PMT VIKAS END */
    gui_push_clip();
    if (flags & UI_SINGLE_LINE_INPUT_BOX_NO_BORDER)
    {
        gui_set_clip(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        sy1 += 1;
        sy2 -= 1;
        border_type = 1;
    }
    else
    {
        gui_set_clip(x1, y1, x2 + 2, y2 + 2);
    }
    /* Add by Leo */
    if (flags & UI_SINGLE_LINE_INPUT_BOX_FORCE_BORDER_DISPLAY)
    {
        S32 string_width = 0, string_height = 0;

        gui_measure_string((UI_string_type) MMI_singleline_inputbox.text, &string_width, &string_height);
        b->width = string_width + 4;
        b->height = string_height + 4;
        b->text_y = 2;
        x2 = x1 + b->width - 1;     /* end x position of single line input box */
        y2 = y1 + b->height - 1;    /* end y position of single line input box */
        gui_draw_rectangle(x1 + 1, y1 + 1, x2 - 1, y2 - 1, UI_COLOR_BLACK);
    }
    if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) && !(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND))
    {
        gui_draw_filled_area(x1, y1, x2, y2, f);
    }

    /* PMT VIKAS START 20050524 */
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    //PMT VIKAS START 20050630
    // remove the function call.
    //   gui_single_line_enable_transparent_effect(&f);   // to enable transparent effect flag for rest program
    //PMT VIKAS END 20050630  
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 
    /* PMT VIKAS END */
    gui_push_text_clip();
    switch (border_type)
    {
        case 0:
            gui_set_text_clip(x1, y1, x2, y2);
            gui_set_clip(x1, y1, x2, y2);
            break;

        case 1:
            gui_set_text_clip(x1 + 1, y1, x2 - 1, y2);
            gui_set_clip(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
            break;

        case 2:
            gui_set_text_clip(x1 + 2, y1, x2 - 2, y2);
            gui_set_clip(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
            break;
    }
    /* set text font */
#if defined(__MMI_TOUCH_SCREEN__)
    gui_set_font(b->text_font);
#else 
    gui_set_font(&MMI_medium_font);
#endif 
    box_width = (x2 - x1 - 6);
    cy = y1 + 2;
    ch = y2 - y1 - 3;
    if (flags & UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR)
    {
        sy1 -= 1;
        sy2 += 1;
    }

    if (current_text_p != NULL)
    {
        if (flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            selection_flag = 1;
            #ifdef __MMI_BIDI_ALG__
            if(arabic_char_flag) selection_flag = 0;
            #endif
        }
        if ((flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE) && (!selection_flag))
        {
            overwrite_mode_flag = 1;
            #ifdef __MMI_BIDI_ALG__
            if(arabic_char_flag) selection_flag = 0;
            #endif
        }
        gui_measure_string_w((UI_string_type) current_text_p, text_gap, &current_text_width, &text_height);
        text_y = b->text_y = (b->height >> 1) - (text_height >> 1);
        if (text_y == 0)
        {
            text_y = 1;
            b->text_y = 1;
        }
        /* MTK added by Elvis and Manju */
        if (flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW)
        {
            /* MTK Elvis for R2L characters */
            if (default_direction == BIDI_L)
            {
                text_x = b->text_x;
            }
            else
            {
                text_x = box_width;
            }
            
        }
        else
        {
            /* MTK Elvis for R2L characters */
            if (flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING)
            {
                if (default_direction == BIDI_L)
                {
                    text_x = b->text_x;
                }
                else
                {
                    text_x = box_width;
                }
            }
            else
            {
                if (default_direction == BIDI_L)
                {
                    text_x = b->text_x + b->text_offset_x;
                }
                else
                {
                    text_x = box_width - b->text_offset_x;
                }
            }
            
        }
        
        if (current_text_width <= box_width)
        {
            if (flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY)
            {
                if (default_direction == BIDI_L)
                text_x = (b->width >> 1) - (current_text_width >> 1);
                else
                    text_x = (b->width >> 1) - (current_text_width >> 1) + current_text_width;
            }
            else if (flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY)
            {
                if (default_direction == BIDI_L)
                text_x = (box_width - current_text_width + 4);
                else
                    text_x = box_width;
            }
        }
        if ((flags & UI_SINGLE_LINE_INPUT_BOX_RIGHT_JUSTIFY) && (text_x + current_text_width) < box_width)
        {
            text_x = box_width - current_text_width + 4;
        }
        total_width = 0;

    #ifdef __MMI_INDIC_ALG__

        single_editor_moves = 1;
    #endif 

    #if defined(__MMI_LANG_VIETNAMESE__)
        if (((b->text_length >> 1) - 1) != 0)
        {
            UI_buffer_type temp_cursor_p = b->current_text_p;
            UI_character_type temp_tone, temp_vowel, dummy_c;

            UI_STRING_GET_NEXT_CHARACTER(temp_cursor_p, temp_tone);
            if ((temp_tone >= 0x0300) && (temp_tone <= 0x0323))
            {
                temp_cursor_p = b->current_text_p;
                UI_STRING_GET_PREVIOUS_CHARACTER(temp_cursor_p, temp_vowel);        /* get next character */
                viet_vowel = mmi_viet_vowel_letter(temp_vowel);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    tone_mark = mmi_viet_tone_mark(temp_tone);
                    if (VIET_TONE_NONE != tone_mark)
                    {
                        dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    }
                }
            }
        }
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

        while (!done)
        {
/*START PMT MAUI_00026933 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_INDIC_ALG__)
			 arabic_indic_flag =0;
#endif
/*END PMT MAUI_00026933 */
            previous_text_p = current_text_p;
            if (flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
            {
                if (current_text_p == b->highlight_start_position)
                {
                    #ifdef __MMI_BIDI_ALG__
                    if(arabic_char_flag)
                        word_highlight=0;
                    else 
                    #endif
                        word_highlight = 1;
                }
                if (current_text_p == b->highlight_end_position)
                {
                    word_highlight = 0;
                }
            }

            /* MTK Elvis for second word highlight */
            if (flags & UI_SINGLE_LINE_INPUT_BOX_SECOND_WORD_HIGHLIGHT)
            {
                if (current_text_p == (b->second_highlight_start_position))
                {
                    second_word_highlight = 1;
                }
                if (current_text_p == (b->second_highlight_end_position))
                {
                    second_word_highlight = 0;
                }
            }
            

        #ifdef __MMI_INDIC_ALG__

            PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_single_line_input_box[single_editor_moves]:%d  ",
                                 single_editor_moves);
            while (single_editor_moves--)

        #endif /* __MMI_INDIC_ALG__ */ 

            {
                UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);        /* get next character */
            }
/* START PMT PATCH04052007 */          
        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* END PMT PATCH04052007 */        
            temp_p = current_text_p;
            UI_STRING_GET_NEXT_CHARACTER(temp_p, next_char);
            if (IS_ARABIC_CHARACTER(current_character) && IS_ARABIC_CHARACTER(next_char))
            {
                text_gap = 0;
            }
            else
            {
                text_gap = b->text_gap;
            }
/* START PMT PATCH04052007 */          
        #endif /* defined (__MMI_BIDI_ALG__) */ 
/* END PMT PATCH04052007 */
            

        #if defined(__MMI_LANG_VIETNAMESE__)
            if ((current_character > 0x0040) && (current_character < 0x01B1))
            {
                UI_STRING_GET_NEXT_CHARACTER(current_text_p, next_character);   /* get next character */
                tone_mark = mmi_viet_tone_mark(next_character);
                if (VIET_TONE_NONE != tone_mark)
                {
                    viet_vowel = mmi_viet_vowel_letter(current_character);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    }
                    else
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, next_character);
                    }
                }
                else
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, next_character);
                }
            }
        #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
 

            if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
            {
                break;
            }
            if (!UI_STRING_LINE_BREAK_CHARACTER(current_character))     /* check for null or space character */
            {
                if (flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)   /* check if current caharcter is a mask character */
                {   /* single line passwd support */
                    if (!((flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) && (current_text_p == b_current_text_p)))
                    {
                        current_character = mask_character;
                    }
                }
                if (RequireToMoveCursor(pre_character, current_character))
                {

                #ifdef __MMI_INDIC_ALG__
                    /* Move pointer by the cluster width */
/* PMT START MAUI_00027731 */
                    single_line_curr_p = ire_get_next_cluster_p(single_line_prev_p, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */

                    single_editor_moves = single_line_curr_p - single_line_prev_p;      /* Number of moves */

                    if (single_editor_moves <= 0)
                    {
                        single_editor_moves = 1;    /* At least 1 */
                    }
                    else
                    {
                        single_editor_moves = single_editor_moves >> 1;
                    }

                    /* Calculate the width of current cluster as well as english character */
                    if (flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS
                        && (!((flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) && (current_text_p == b_current_text_p))))       /* check if current caharcter is a mask character */
                    {
                        character_width = gui_get_character_width(mask_character);
                    }
/* START PMT PATCH04052007 */
                    #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                    else if(IRE_INSERTED_ARABIC_COUNT())
                    {
                        character_width =  gui_get_character_width(current_character); 

                    }
                    #endif
/* END PMT PATCH04052007 */
                    else
                    {
                        character_width = ire_size_of_current_cluster(single_line_prev_p, single_line_curr_p, 0);
                    }
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_single_line_input_box[character_width]:%d  ",
                                         character_width);
                    previous_text_p = single_line_prev_p;
                    single_line_prev_p = single_line_curr_p;
/*START PMT MAUI_00026933 */
					#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
					single_line_prev_p += arabic_indic_flag*2;
					arabic_indic_flag =0;
                    #endif
/*END PMT MAUI_00026933 */

                #else /* __MMI_INDIC_ALG__ */ 

                    /* single line passwd support */

                    character_width = gui_get_character_width(current_character);   /* get character width in pixels */

                #endif /* __MMI_INDIC_ALG__ */ 

                }
                else
                {
                    character_width = 0;
                }
                if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW))
                {
                    text_color = b_normal_text_color;

                    if(default_direction != BIDI_L)
                    {
                        cx=x1+text_x-character_width;
                    }
                    else
                    {
                        cx=x1+text_x;
                    }

                    if (word_highlight)
                    {
                        if (flags & UI_SINGLE_LINE_INPUT_BOX_SWITCH_WORD_HIGHLIGHT_COLOR)
                        {
                            gui_fill_rectangle(
                                cx,
                                sy1,
                                cx + character_width,
                                sy2,
                                gui_color(255, 0, 0));
                        }
                        else
                        {
                            gui_fill_rectangle(cx, sy1, cx + character_width, sy2, b_selection_color);
                        }
                        text_color = b_selection_text_color;
                    }
                    if (second_word_highlight)
                    {
                        gui_fill_rectangle(cx, sy1, cx + character_width, sy2, b_selection_color);
                        text_color = b_selection_text_color;
                    }
                    if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
                    {
                        if (flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
                        {
                            if (previous_text_p == b_current_text_p)
                            {
                                if (overwrite_mode_flag)    /* if overwrite mode */
                                {
                                    gui_fill_rectangle(
                                        x1 + text_x,
                                        sy1,
                                        x1 + text_x + character_width,
                                        sy2,
                                        b_selection_color);
                                    text_color = b_selection_text_color;
                                }
                                if (default_direction == BIDI_L)
                                {
                                    b->cursor_x = text_x - 1;
                                }
                                else
                                {
                                    b->cursor_x = text_x + 1;
                                }
                                cursor_displayed_flag = 1;
                            }
                            else if (current_text_p == b_current_text_p)
                            {
                                if (selection_flag)
                                {
                                    gui_fill_rectangle(
                                        x1 + text_x,
                                        sy1,
                                        x1 + text_x + character_width,
                                        sy2,
                                        b_selection_color);
                                    text_color = b_selection_text_color;
                                }
                            }
                        }
                        else
                        {
                            if (previous_text_p == b_current_text_p)
                            {
                                if (overwrite_mode_flag)
                                {
                                    gui_fill_rectangle(
                                        x1 + text_x,
                                        sy1,
                                        x1 + text_x + character_width,
                                        sy2,
                                        b_selection_color);
                                    text_color = b_selection_text_color;
                                }
                                /* Added condition to disable vertical cursor drawing in character highlight mode   */
                                if (!(flags & UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT))
                                {

    
                                #ifndef  __MMI_INDIC_ALG__ 
                                    gui_single_line_input_box_show_cursor(b, x1 + text_x - 1 , cy, ch);      /* show cursor of single line input box */
                                #else 
                                    if(!IRE_INDIC_CHARACTER_UCS2_RANGE( *(PU16)(b->current_text_p - 2)))
                                    {
                                        gui_single_line_input_box_show_cursor(b, x1 + text_x - 1 , cy, ch);      /* show cursor of single line input box */
                                    }
                                    else
                                    {
                                        gui_single_line_input_box_show_cursor(b, x1 + text_x, cy, ch);      /* show cursor of single line input box */
                                    }
                                #endif /*__MMI_INDIC_ALG__*/

                                }
                                if (default_direction == BIDI_L)
                                {
                                    b->cursor_x = text_x - 1;
                                }
                                else
                                {
                                    b->cursor_x = text_x + 1;
                                }
                                cursor_displayed_flag = 1;
                            }
                            else if (current_text_p == b_current_text_p)
                            {
                                if (selection_flag)
                                {
                                    if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                                    {
                                        gui_fill_rectangle(
                                            x1 + text_x,
                                            sy1,
                                            x1 + text_x + b->grid_width,
                                            sy2,
                                            b_selection_color);
                                    }
                                    else
                                    {
                                        gui_fill_rectangle(
                                            x1 + text_x,
                                            sy1,
                                            x1 + text_x + character_width,
                                            sy2,
                                            b_selection_color);
                                    }
                                    text_color = b_selection_text_color;
                                }
                            }
                        }
                    }
                    if (flags & UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS)
                    {
                        if ((cx >= x1) && ((cx + character_width) <= x2))
                        {
                            if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                            {
                                gui_move_text_cursor(cx + ((b->grid_width - character_width) >> 1), y1 + text_y);
                                gdi_draw_line(
                                    cx + b->grid_width,
                                    sy1,
                                    cx + b->grid_width,
                                    sy2,
                                    gdi_act_color_from_rgb(255, 112, 125, 240));
                            }
                            else
                            {
                                gui_move_text_cursor(cx, y1 + text_y);
                            }
                            gui_set_text_color(text_color);
                            //gui_print_character((UI_character_type)current_character);
                            //MTK Elvis for stacked character
                            gui_print_stacked_character(current_character, pre2_character, pre_character);
                            pre2_character = pre_character;
                            pre_character = current_character;
                            
                        }
                    }   /* MTK Leo add 1125, trucate too long number/name in call list. */
                    else if (flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT)
                    {
                        if ((cx >= x1) && (cx + 21) >= x2)
                        {
                            gui_set_text_color(text_color);
                            gui_move_text_cursor(cx, y1 + text_y);
                            gui_print_character((UI_character_type) '.');
                            gui_move_text_cursor(cx + 7, y1 + text_y);
                            gui_print_character((UI_character_type) '.');
                            gui_move_text_cursor(cx + 14, y1 + text_y);
                            gui_print_character((UI_character_type) '.');
                            break;
                        }
                        else if ((cx >= x1) && ((cx + character_width) <= x2))
                        {
                            gui_move_text_cursor(cx, y1 + text_y);
                            gui_set_text_color(text_color);
                            //gui_print_character((UI_character_type)current_character);
                            //MTK Elvis for stacked character
                            gui_print_stacked_character(current_character, pre2_character, pre_character);
                            pre2_character = pre_character;
                            pre_character = current_character;
                            
                        }
                        /* MTK Leo end 1125 */
                    }
                    else if (flags & UI_SINGLE_LINE_INPUT_BOX_TRUNCATE_CONTENT_NO_BRIEF)        /* 022405 Calvin added */
                    {
                        if ((cx >= x1) && (cx + 7) >= x2)
                        {
                            gui_set_text_color(text_color);
                            gui_move_text_cursor(cx, y1 + text_y);
                            if (character_width < 7 &&
                                UI_STRING_END_OF_STRING_CHARACTER1((UI_character_type)
                                                                  ((*((current_text_p) + 0)) |
                                                                   ((*((current_text_p) + 1)) << 8))))
                            {
                                gui_print_stacked_character(current_character, pre2_character, pre_character);
                                pre2_character = pre_character;
                                pre_character = current_character;
                            }
                            else
                            {
                                gui_print_character((UI_character_type) ' ');
                            }
                            break;
                        }
                        else if ((cx >= x1) && ((cx + character_width) <= x2))
                        {
                            gui_move_text_cursor(cx, y1 + text_y);
                            gui_set_text_color(text_color);
                            //gui_print_character((UI_character_type)current_character);
                            //MTK Elvis for stacked character
                            gui_print_stacked_character(current_character, pre2_character, pre_character);
                            pre2_character = pre_character;
                            pre_character = current_character;
                            
                        }
                    }
                    else
                    {
                        if ((cx + character_width) >= x1 && (cx <= x2))
                        {

                        #if defined(__MMI_INDIC_ALG__)
                            PU8 prev_single_line_temp_p;
/* START PMT PATCH04052007 */
                            #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                            if(!IRE_INSERTED_ARABIC_COUNT())
                            #endif
                            {
/* END PMT PATCH04052007 */ 
                            if (ire_is_indic_rules_parsing())
                            {
                                ire_reset_indic_bordered_params();
                            }
                            ire_get_bordered_text_x(&cx, current_character, text_y);
                            ire_disable_indic_rules_parsing();
/* START PMT PATCH04052007 */
                            
                            }
/* END PMT PATCH04052007 */
                        #endif /* defined(__MMI_INDIC_ALG__) */ 

                            gui_move_text_cursor(cx, y1 + text_y);      /* move text cursor */
                            gui_set_text_color(text_color); /* set text color */
                            /* gui_print_character((UI_character_type)current_character);//print text */

                        #ifdef __MMI_INDIC_ALG__

                            if (single_line_temp_p == (b->last_position_p))
                            {
                                goto enddisp;
                            }
                            /* Performance issue */
                            prev_single_line_temp_p = single_line_temp_p;
/* PMT START MAUI_00027731 */
                            single_line_temp_p = ire_get_next_cluster_p(single_line_temp_p, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
/* START PMT PATCH04052007 */
                          #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__) 
                            if ( (!IRE_INSERTED_ARABIC_COUNT())&&ire_get_current_cluster
                                (prev_single_line_temp_p, single_line_temp_p, single_line_disp_cluster))
                            #else
                            if (ire_get_current_cluster
                                (prev_single_line_temp_p, single_line_temp_p, single_line_disp_cluster))
                            #endif
/* END PMT PATCH04052007 */
                            {
                                S32 disp_clus_len = mmi_ucs2strlen((PS8) single_line_disp_cluster);

                                MMI_ASSERT(!(disp_clus_len > MAX_EDITOR_DISP_LEN));
                                /* To avoid rule appln in showstring */
                                ire_disable_indic_rules_parsing();
                                ire_indic_padding_value(0);
                                if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))

                                {
                                    if (flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)       /* check if current caharcter is a mask character */
                                    {
                                        S32 str_len = mmi_ucs2strlen((const S8*)single_line_disp_cluster);
                                        S32 i;

                                        for (i = 0; i < str_len; i++)
                                        {   /* single line passwd support */
                                            if ((flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) &&
                                                (current_text_p == b_current_text_p))
                                            {
                                                single_line_disp_cluster[i] = current_character;
                                            }
                                            else
                                            {
                                                single_line_disp_cluster[i] = mask_character;
                                            }
                                        }
                                    }
                                    FONT_CANCEL_WIDTH(1);
                                    ShowString(
                                        UI_text_x,
                                        UI_text_y,
                                        *UI_font,
                                        0,
                                        (U8*) (single_line_disp_cluster),
                                        UI_text_height);
                                    FONT_CANCEL_WIDTH(0);
                                }
                                else
                                {
                                    if (flags & UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS)       /* check if current caharcter is a mask character */
                                    {
                                        S32 str_len = mmi_ucs2strlen((const S8*)single_line_disp_cluster);
                                        S32 i;

                                        for (i = 0; i < str_len; i++)
                                        {   /* single line passwd support */
                                            if ((flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP) &&
                                                (current_text_p == b_current_text_p))
                                            {
                                                single_line_disp_cluster[i] = current_character;
                                            }
                                            else
                                            {
                                                single_line_disp_cluster[i] = mask_character;
                                            }
                                        }
                                    }
                                    FONT_CANCEL_WIDTH(1);
                                    ShowString(
                                        UI_text_x,
                                        UI_text_y,
                                        *UI_font,
                                        0,
                                        (U8*) (single_line_disp_cluster),
                                        UI_text_height);
                                    FONT_CANCEL_WIDTH(0);
                                }

                                /* Open it again */
                                ire_enable_indic_rules_parsing();
                                ire_indic_padding_def_value();
                            }
                            else
                        #endif /* __MMI_INDIC_ALG__ */ 

                            {
                                gui_print_stacked_character(current_character, pre2_character, pre_character);
                            }

                        #ifdef __MMI_INDIC_ALG__

                          enddisp:
                            memset(single_line_disp_cluster, 0, sizeof(single_line_disp_cluster));

                        #endif /* __MMI_INDIC_ALG__ */ 


                        }

                    #if defined __MMI_INDIC_ALG__

                        else
                        {
                            single_line_temp_p += (single_editor_moves * 2);
                        }

                    #endif /* defined __MMI_INDIC_ALG__ */ 

                    }
                }
                else if ((previous_text_p == b_current_text_p) && (((-1) == move_to_x) && ((-1) == move_to_y)))
                {
                    if (default_direction == BIDI_L)
                    {
                        b->cursor_x = text_x - 1;
                    }
                    else
                    {
                        b->cursor_x = text_x + 1;
                    }
                    cursor_displayed_flag = 1;
                }
                else if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!set_cursor_flag))
                {
                    int cursor_with = 0;
                    PMT_BIDI_TYPES temp_direction = BIDI_L;
#ifdef __MMI_BIDI_ALG__
                    bidi_get_char_type(b->text, (U8*) & temp_direction);
                    if (temp_direction == BIDI_R || temp_direction == AL|| temp_direction == AN)
                    {
                        temp_direction = BIDI_R;
                    }
                    else
                    {
                        temp_direction = BIDI_L;
                    }
#endif
                    if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                    {
                        cursor_with = b->grid_width;
                    }
                    else
                    {
                        cursor_with = character_width;
                    }
                    if ((temp_direction == BIDI_L) ? 
                        ((b->text_offset_x + b->x + text_x + text_gap + cursor_with) > move_to_x) : (b->text_offset_x + b->x + text_x <= move_to_x))
                    {
                        b->current_text_p = previous_text_p;
                        if (default_direction == BIDI_L)
                        {
                            b->cursor_x = text_x - 1;
                        }
                        else
                        {
                            b->cursor_x = text_x + 1;
                        }
                        set_cursor_flag = 1;
                    }
                }
                if (default_direction == BIDI_L)
                {
                    if (RequireToMoveCursor(pre_character, current_character))
                    {

                    #ifdef __MMI_INDIC_ALG__
                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))

                        {
                            if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                            {
                            }
                            else
                            {
                                text_x += character_width;
                                total_width += character_width;
                            }
                        }
                        else

                    #endif /* __MMI_INDIC_ALG__ */ 

                        {
                            if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                            {
                                text_x += b->grid_width;
                                total_width += b->grid_width;
                            }
                            else
                            {
                                text_x += (text_gap + character_width);
                                total_width += (text_gap + character_width);
                            }
                        }

                    }
                    else
                    {
                        if (b->ext_flags & UI_SINGLE_LINE_INPUT_BOX_EXT_FIXED_GRID)
                        {
                            text_x += b->grid_width;
                            total_width += b->grid_width;
                        }
                        else
                        {
                            text_x += /* text_gap */ +character_width;
                            total_width += /* text_gap */ +character_width;
                        }
                    }
                }
                else
                {
                    text_x -= (character_width + text_gap);
                    total_width += text_gap + character_width;
                }
                pre2_character = pre_character;
                pre_character = current_character;
            }
        }
        if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!set_cursor_flag))
        {
            b->current_text_p = previous_text_p;
            if (default_direction == BIDI_L)
            {
                b->cursor_x = text_x - 1;
            }
            else
            {
                b->cursor_x = text_x + 1;
            }
            set_cursor_flag = 1;
        }
        b->last_position_p = current_text_p;
        /* W06.15 b->cursor_x is not correct when moving cursor by pen */
        if (!cursor_displayed_flag && (((-1) == move_to_x) && ((-1) == move_to_y)))
        {
            if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) &&
                !(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                if (flags & UI_SINGLE_LINE_INPUT_BOX_SHOW_BLOCK_CURSOR)
                {
                    gui_fill_rectangle(x1 + text_x, sy1, x1 + text_x + character_width, sy2, b_selection_color);
                }
                else
                {
                    /* Added condition to disable vertical cursor drawing in character highlight mode   */
                    if (!(flags & UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT))
                    {

#ifndef  __MMI_INDIC_ALG__ 
                         gui_single_line_input_box_show_cursor(b, x1 + text_x - 1 , cy, ch);      /* show cursor of single line input box */
#else 
                         if(!IRE_INDIC_CHARACTER_UCS2_RANGE( *(PU16)(b->current_text_p - 2)))
                         {
                        gui_single_line_input_box_show_cursor(b, x1 + text_x - 1, cy, ch);      /* show cursor of single line input box */

                         }
                         else
                         {
                             gui_single_line_input_box_show_cursor(b, x1 + text_x, cy, ch);      /* show cursor of single line input box */
                         }
#endif /*__MMI_INDIC_ALG__*/

                    }
                }
            }
            if (default_direction == BIDI_L)
            {
                b->cursor_x = text_x - 1;
            }
            else
            {
                b->cursor_x = text_x + 1;
            }
        }
    }
    b->text_width = total_width;
    gui_pop_text_clip();
    gui_pop_clip();
    /* MTK Elvis for R2L characters */
    
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
    restore_current_language_for_hindi_rules();
#endif 

#ifdef __MMI_BIDI_ALG__
    if (!(flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW) && (((b->text_length >> 1) - 1) != 0) && arabic_char_flag)
    {
        b->text = temp_text_pt;
        b->current_text_p = temp_cursor_p;
        b->last_position_p = b->text + (current_text_p - visual_str);

        if (flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT)
        {
            b->highlight_start_position = temp_hilight_start;
            b->highlight_end_position = temp_hilight_end;
        }

    }
#endif /* __MMI_BIDI_ALG__ */ 

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (b->text_length >ENCODING_LENGTH)
    {
        b->text = backup_text;

        if ( (b->flags & UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
        {
            b->highlight_start_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->highlight_start_position - (UI_buffer_type)shaping_str)/2)*2;
            b->highlight_end_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->highlight_end_position - (UI_buffer_type)shaping_str)/2)*2;
        }
        if ( (b->flags & UI_SINGLE_LINE_INPUT_BOX_SECOND_WORD_HIGHLIGHT) && b->second_highlight_start_position != NULL)
        {
            b->second_highlight_start_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->second_highlight_start_position - (UI_buffer_type)shaping_str)/2)*2;
            b->second_highlight_end_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->second_highlight_end_position - (UI_buffer_type)shaping_str)/2)*2;
        }

		b->current_text_p  =  b->text + gui_multi_line_mapping_sha_to_org((b->current_text_p  - (UI_buffer_type)shaping_str)/2)*2;
		b->last_position_p =  b->text + gui_multi_line_mapping_sha_to_org((b->last_position_p - (UI_buffer_type)shaping_str)/2)*2;
    }
#endif /* __MMI_LANG_ARABIC__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  gui_destroy_single_line_input_box
 * DESCRIPTION
 *  frees the buffer allocated for the box and resets the input box
 *  
 *  This doesn't free the single-line inputbox object. It only
 *  frees the buffer that is used to store the text.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_destroy_single_line_input_box(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_length = 0;
    b->allocated_length = 0;
    b->available_length = 0;
    b->UCS2_count = 0;
    gui_free(b->text);
    b->current_text_p = b->text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_locate_cursor
 * DESCRIPTION
 *  calculate the position ofcusror of single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_locate_cursor(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MTK Elvis for R2L characters */
#ifdef __MMI_BIDI_ALG__
    PMT_BIDI_TYPES default_direction = BIDI_L;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bidi_get_char_type(b->text, (U8*) & default_direction);
#endif /* __MMI_BIDI_ALG__ */ 

#ifdef __MMI_BIDI_ALG__
    if (default_direction != BIDI_R && default_direction != AL && default_direction != AN)
    {
#endif /* __MMI_BIDI_ALG__ */ 
        if ((b->cursor_x + (b->width >> 2) + b->text_offset_x) > (b->width - b->text_x))
        {
            b->text_offset_x = -(b->cursor_x + (b->width >> 2) - (b->width - b->text_x));
            if ((b->text_offset_x + b->text_width) < (b->width - 6))
            {
                b->text_offset_x = (b->width - 6) - (b->text_width);
            }
        }
        else if ((b->cursor_x + b->text_offset_x + 2) < (b->text_x + (b->width >> 2)))
        {
            b->text_offset_x = -(b->cursor_x - 2 - (b->width >> 2));
        }
        if (b->text_offset_x > 0)
        {
            b->text_offset_x = 0;
        }
    #ifdef __MMI_BIDI_ALG__
    }
    else
    {
        if ((b->cursor_x + b->text_offset_x) < 2)
        {
            b->text_offset_x = (b->width - 10) - (b->text_width);
        }
    }
    #endif /* __MMI_BIDI_ALG__ */ 
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    if (previous_text_p == b->text)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_change();
        }
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c); /* get previous caharcter */

    #if defined(__MMI_INDIC_ALG__)
    IRE_DECREMENT_LANGUAGE_VARIABLES(dummy_c);
    #endif

    b->text_length -= ((S32) current_text_p - (S32) previous_text_p);   /* update text length ..decrease value */
    b->current_text_p = previous_text_p;    /* set teh current_tet_p equalto previous */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(dummy_c, b->UCS2_count, b->allocated_length, b->available_length);
    }
    while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;

#ifdef __MMI_INDIC_ALG__

    /* For handling the inbetweeen halanth deletion */
    if ((b->current_text_p - b->text) >= 4)
    {
        UI_buffer_type temp_single_line_cursor_p;

        temp_single_line_cursor_p = b->current_text_p;

        /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
        /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
         if ((IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*(temp_single_line_cursor_p - 4)) | ((*(temp_single_line_cursor_p - 3))<<8))  )) 
              && (IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*(temp_single_line_cursor_p)) | ((*(temp_single_line_cursor_p+1))<<8))  )) 
              && (IRE_IS_CHAR_TYPE_HALANT( (U16)((*(temp_single_line_cursor_p - 2)) | ((*(temp_single_line_cursor_p - 1))<<8))  )))
        {
            /* PMT START MAUI_00025775 */
            U32 langid_Halant = 0;
            U32 diff_langid_cons_halant = 0;

            langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(temp_single_line_cursor_p - 2))
                                                             | ((*(temp_single_line_cursor_p - 1)) << 8)));
            if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*temp_single_line_cursor_p)
                                                                  | ((*(temp_single_line_cursor_p + 1)) << 8))))
            {
                diff_langid_cons_halant = 1;
            }
            if (!diff_langid_cons_halant)
            {
                U8 single_deletion = 0;
                U8 saved_single_deletion = 0;
                UI_character_type previous_character2 = 0;
/* PMT START MAUI_00027731 */
                U32 counter = 0;
                U32 langid_Consonant = 0;
                PU8 single_line_first_pos_p = temp_single_line_cursor_p;
                PU8 single_line_second_pos_p;

            single_line_second_pos_p = ire_get_next_cluster_p(single_line_first_pos_p, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
                single_deletion = single_line_second_pos_p - single_line_first_pos_p;   /* Number of moves */
                single_deletion = single_deletion >> 1;
                saved_single_deletion = single_deletion;
                temp_single_line_cursor_p = b->current_text_p;
                langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*temp_single_line_cursor_p)
                                                                    | ((*(temp_single_line_cursor_p + 1)) << 8)));

                UI_STRING_GET_PREVIOUS_CHARACTER(temp_single_line_cursor_p, previous_character2);
                while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                       IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                {
                    counter += 2;
                    temp_single_line_cursor_p -= 2;
                    if (b->text >= temp_single_line_cursor_p)
                    {
                        break;
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(temp_single_line_cursor_p, previous_character2);
                }
                counter = counter % ((G_MAX - 2));
                single_deletion = (G_MAX - 2) - counter;
                if (saved_single_deletion > single_deletion)
                {
                    saved_single_deletion = single_deletion;

                }
                single_deletion = saved_single_deletion;
            
                while (single_deletion--)
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                }
            }
        }
    }
    /* PMT END MAUI_00025775 */
#endif /* __MMI_INDIC_ALG__ */ 

    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate the cursor position of single lie input box */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_current_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);    /* get next character */
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))  /* check for end of string */
    {
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(
                current_character,
                b->allocated_length,
                b->UCS2_count,
                b->available_length);
        }

        #if defined(__MMI_INDIC_ALG__)
        IRE_DECREMENT_LANGUAGE_VARIABLES(current_character);
        #endif

        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
        }
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_single_line_input_box(b);          /* show single line input box */
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_single_line_input_box_locate_cursor(b); /* locate cursor postion */
        b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);  /* call validation callback func */
        b->change_callback();
    }
    else
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_change();    /* play tone */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_all(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);
    /* MTK Elvis 20040611 donot play tone while text buffer is zero */

    

    #if defined(__MMI_INDIC_ALG__)
    /* PMT START MAUI_00415927 */
	#if defined(__MMI_BIDI_ALG__)
	if(!ire_check_arabic_and_indic() )
	/* */
	#endif
	{
		IRE_RESET_LANGUAGE_VARIABLES();
	}
    /* PMT END MAUI_00415927 */
    #endif

    gui_single_line_input_box_clear(b);         /* initialize single line input box to default */
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor position of sigle lien input box */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_toggle_insert_mode(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the desired position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 *  pos     [IN]        Is the inserted position in bytes
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_insert_character_in_pos(single_line_input_box *b, UI_character_type c, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type old_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_insert();
        }
        return;
    }
    
    p_insert = b->text + pos;
    if (b->current_text_p >= p_insert)
        b->current_text_p += ENCODING_LENGTH;

    p1 = p_insert;
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p_insert, old_c);
        UI_STRING_INSERT_CHARACTER(p1, c);
        c = old_c;
    }
    UI_STRING_INSERT_CHARACTER(p1, c);  /* insert character */
    
    b->text_length += ENCODING_LENGTH;
    
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single lien input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_delete_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  pos     [IN]        Is the desired position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_delete_character_in_pos(single_line_input_box *b, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos >= b->text_length - ENCODING_LENGTH)
        return;
    
    p_insert = b->text + pos;
    if (b->current_text_p > p_insert)
        b->current_text_p -= ENCODING_LENGTH;
    p1 = p_insert;
    
    UI_STRING_GET_NEXT_CHARACTER(p1, c);
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, c);
        UI_STRING_INSERT_CHARACTER(p_insert, c);
    }
    
    b->text_length -= ENCODING_LENGTH;
    
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single lien input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_insert_character(single_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U8 flag = 0;
    U32 b_flags = b->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
        UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return;
        }
        else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return;
        }
    }
    p1 = p2 = b->current_text_p;
    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next caharater */
        if ((p1 == b->last_position_p) && ((b->last_position_p - b->text) >= b->available_length))
        {
            return;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of character */
        {

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert caharactr */
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->current_text_p = p2;

            //MTK Elvis for R2L characters
            //It is not required to increase the length while in overwrite mode
            //b->text_length+=ENCODING_LENGTH;     //incraese length of text
            //MTK end
        }
        else
        {
            p1 = b->current_text_p;

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);   /* get next character */
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of character */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                UI_STRING_INSERT_CHARACTER(p2, c);          /* insert character */
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else
    {
        if ((b->last_position_p - b->text) >= (b->available_length))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return;
        }
        /* check if leading zero flag is set or not ,
           if leading zero flag is false and lengthis  equal to 4 and if character is not zero then a chatracter is insert */
        if ((numeric_leading_zero == FALSE) && (b->text_length == 4) )
        {
            if (b->text[0] == 48)
            {
                if (p1 == b->text)
                {
                    if (c == 48)
                    {
                         p1 = b->text;
                         flag = 1;
                         UI_STRING_INSERT_CHARACTER(p1, c);  /* insert a charcter */
                    }
                }
                else
                {
                    if (c != 46) /* '.' */ 
                    {
                        p1 = b->text;
                        flag = 1;
                        UI_STRING_INSERT_CHARACTER(p1, c);  /* insert a charcter */
                    }
                }
            }
        }
        if (flag == 0)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);   /* get next character */
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }

    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single lien input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor psotion */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_overflow
 * DESCRIPTION
 *  check for overflow..if the length is equal to availabel lengt or not
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte return true if length is equa to available length else false
 *****************************************************************************/
U8 gui_single_line_input_box_test_overflow(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis to allow user to change the current hilighted multitap character */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        if ((b->last_position_p - b->text) == (b->available_length))
        {
            return (0);
        }
        else if ((b->last_position_p - b->text) > (b->available_length))
        {
            return (1);
        }
    }
    else
    {
        if ((b->last_position_p - b->text) >= (b->available_length))
        {
            return (1);
        }
    }
    
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_first_position
 * DESCRIPTION
 *  check for overflow..if the length is equal to availabel lengt or not
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte return true if length is equa to available length else false
 *****************************************************************************/
U8 gui_single_line_input_box_test_first_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_position
 * DESCRIPTION
 *  check for overflow..if the length is equal to availabel lengt or not
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte return true if length is equa to available length else false
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_character_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_character_position(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_test_last_position_overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_single_line_input_box_test_last_position_overflow(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_text_length
 * DESCRIPTION
 *  Return text length
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 :- return text length
 *****************************************************************************/
S32 gui_single_line_input_box_get_text_length(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_insert_multitap_character(single_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;

#ifdef __MMI_INDIC_ALG__

    UI_buffer_type middle_p, first_cons_p, second_cons_p;
    static U8 single_line_cursor_pos = 0;

#endif /* __MMI_INDIC_ALG__ */ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
        UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return;
        }
        else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
            {
                UI_editor_play_tone_cannot_insert();
            }
            return;
        }
    }

    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);

    #ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        if (single_line_cursor_pos)
        {
            while (saved_single_line_skip_moves)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                saved_single_line_skip_moves--;
            }
        }
        saved_single_line_skip_moves = 0;
        /* PMT END MAUI_00025775 */
            single_line_cursor_pos = 0;
    #endif /* __MMI_INDIC_ALG__ */ 
 

        p1 = p2 = b->current_text_p;

    #ifdef __MMI_INDIC_ALG__

        middle_p = p1;
        first_cons_p = p1 - 2;

    #endif /* __MMI_INDIC_ALG__ */ 
 

        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next xharacter */
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->current_text_p = p2;

        #ifdef __MMI_INDIC_ALG__
            second_cons_p = b->current_text_p;
            /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
            /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
             if ((IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*first_cons_p) | ((*(first_cons_p+1))<<8))  )) 
                  && (IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*second_cons_p) | ((*(second_cons_p+1))<<8))  ))  
                  && (IRE_IS_CHAR_TYPE_HALANT( (U16)((*middle_p) | ((*(middle_p+1))<<8))  )))
            {
                /* PMT START MAUI_00025775 */
                U32 langid_Halant = 0;
                U32 diff_langid_cons_halant = 0;

                langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(second_cons_p - 2))
                                                                 | ((*(second_cons_p - 1)) << 8)));
                if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_p)
                                                                      | ((*(second_cons_p + 1)) << 8))))
                {
                    diff_langid_cons_halant = 1;
                }
                if (!diff_langid_cons_halant)
                {
                    UI_character_type previous_character2 = 0;
/* PMT START MAUI_00027731 */
                    U32 counter = 0;
                    U32 langid_Consonant = 0;
                    U8 single_line_skip_moves = 0;
                    PU8 single_line_first_ptr = second_cons_p;
                    PU8 single_line_second_ptr;

                    /* save_cursor_text_p = b->current_text_p; */
                    single_line_second_ptr = ire_get_next_cluster_p(single_line_first_ptr, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
                    single_line_skip_moves = single_line_second_ptr - single_line_first_ptr;    /* Number of moves */
                    single_line_skip_moves = single_line_skip_moves >> 1;
                    saved_single_line_skip_moves = single_line_skip_moves;
                    first_cons_p = b->current_text_p;
                    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*first_cons_p)
                                                                        | ((*(first_cons_p + 1)) << 8)));

                    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_p, previous_character2);
                    while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                           IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                    {
                        counter += 2;
                        first_cons_p -= 2;
                        if (b->text >= first_cons_p)
                        {
                            break;
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_p, previous_character2);

                    }
                    counter = counter % ((G_MAX - 2));
                    single_line_skip_moves = (G_MAX - 2) - counter;
                    if (saved_single_line_skip_moves > single_line_skip_moves)
                    {
                        saved_single_line_skip_moves = single_line_skip_moves;

                    }
                    single_line_skip_moves = saved_single_line_skip_moves;

                    while (single_line_skip_moves--)
                    {
                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    }
                    single_line_cursor_pos = 1;
                }

            }
            /* PMT END MAUI_00025775 */
        #endif /* __MMI_INDIC_ALG__ */ 

        }
        else
        {
            p1 = b->current_text_p;
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);   /* get next character */

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(dummy_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else
    {

    #ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        saved_single_line_skip_moves = 0;
        /* PMT END MAUI_00025775 */
        single_line_cursor_pos = 0;
    #endif 
        p1 = p2 = b->current_text_p;
        if (b_flags & UI_SINGLE_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            if ((p1 == b->last_position_p) && ((b->last_position_p - b->text) >= b->available_length))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return;
            }
            if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))
            {

                #if defined(__MMI_INDIC_ALG__)
                IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
                IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                #endif

                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->current_text_p = p2;
            }
            else
            {
                p1 = b->current_text_p;
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);

                #if defined(__MMI_INDIC_ALG__)
                IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                #endif

                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
        else
        {
            int flag = 0;

            if ((b->last_position_p - b->text) >= (b->available_length))
            {
                if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
                {
                    UI_editor_play_tone_cannot_insert();
                }
                return;
            }
            /* W05.33 if leading zero flag is false and lengthis  equal to 4 and if character is not zero then a chatracter is insert */
            if ((numeric_leading_zero == FALSE) && (b->text_length == 4))
            {
                if (b->text[0] == 48 && (c != 46))
                {
                    p1 = b->text;
                    flag = 1;
                    UI_STRING_INSERT_CHARACTER(p1, c);  /* insert a charcter */
                }
            }
            if (0 == flag)
            {
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }

                #if defined(__MMI_INDIC_ALG__)
                IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                #endif

                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence.
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_confirm_multitap_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
}

/* PMT dara added for multitap thai */
#ifdef __MMI_MULTITAP_THAI__


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_previous_character
 * DESCRIPTION
 *  get  the previous character
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  c               [?]         
 *  means(?)        [OUT]       None, 1 means have one, save in c
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_single_line_input_box_get_previous_character(single_line_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        return 0;
    }
    if (b->current_text_p == b->text)
    {
        return 0;
    }
    *c = (*(b->current_text_p - 2)) | (*(b->current_text_p - 1)) << 8;
    return 1;
}
#endif /* __MMI_MULTITAP_THAI__ */ 
/* msz065_20050420 Peng Hua add for multitap thai input method end */


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_previous(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;

#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type previous_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    UI_character_type pre_one_char = 0;
    UI_character_type pre_two_char = 0;
    UI_character_type pre_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */


#ifdef __MMI_INDIC_ALG__

    UI_buffer_type single_line_check_text_p = b->current_text_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return;
    }
    if (b->current_text_p == b->text)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return;
    }

    gui_single_line_input_box_confirm_multitap_character(b);
    
#ifdef __MMI_INDIC_ALG__

    UI_STRING_GET_PREVIOUS_CHARACTER(single_line_check_text_p, dummy_c);        /* get previous character */
    /* If Hindi Character */

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))

    {
        /* Move by a syllable rather than by a character as in English */

        b->current_text_p = (U8*) ire_get_prev_cluster_p(b->text, b->current_text_p);
    }
    else
#endif /* __MMI_INDIC_ALG__ */ 
 
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);   /* get previous character */
    }
#if defined(__MMI_LANG_VIETNAMESE__)
    if ((dummy_c >= 0x0300) && (dummy_c <= 0x0323))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, previous_unicode);  /* get next character */
        viet_vowel = mmi_viet_vowel_letter(previous_unicode);
        if (VIET_VOWEL_NONE != viet_vowel)
        {
            tone_mark = mmi_viet_tone_mark(dummy_c);
            if (VIET_TONE_NONE != tone_mark)
            {
                dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
            }
            else
            {
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, previous_unicode);
            }
        }
        else
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, previous_unicode);
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /* MTK Steven 20050505  */
#if defined(__MMI_LANG_THAI__)
    if (isThaiChar(dummy_c))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, pre_one_char);
        if (isThaiChar(pre_one_char))
        {
            if (!RequireToMoveCursor(pre_one_char, dummy_c))
            {
                if (b->current_text_p != b->text)
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, pre_two_char);
                    if (isThaiChar(pre_two_char))
                    {
                        if (!RequireToMoveCursor(pre_two_char, pre_one_char))
                        {
                            if (b->current_text_p != b->text)
                            {
                                UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, pre_three_char);
                                if (isThaiChar(pre_three_char))
                                {
                                    if (RequireToMoveCursor(pre_three_char, pre_two_char))
                                    {
                                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                                    }
                                }
                                else
                                {
                                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                                }
                            }
                        }
                        else
                        {
                            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                        }
                    }
                    else
                    {
                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    }
                }
            }
            else
            {
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            }
        }
        else
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */
       /* Begin BIRD arabic 0908 */
/* START PMT PATCH04052007 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* END PMT PATCH04052007 */
       if (IS_ARABIC_CHARACTER(dummy_c))
       {
           U16 idx;
           idx = (b->current_text_p - b->text + 2 )/2-1;
   
           while(idx > 0)
           {
               if(OrgToSha[idx] == OrgToSha[idx-1])
               {
                   UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
               }
               else
               {
                   break;
               }
               idx--;
           }
       } 
#endif
       /* End BIRD arabic 0908 */

    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_previous_steps
 * DESCRIPTION
 *  Moves the cursor to the  character
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  steps       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_single_line_input_box_previous_steps(single_line_input_box *b, S32 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c;
    S32 count = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return (count);
    }
    if (b->current_text_p == b->text)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return (count);
    }
    while (!done)
    {
        if (b->current_text_p == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        count++;
        if (count >= steps)
        {
            break;
        }
    }
    if (count != steps)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
    }


    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b);
    UI_UNUSED_PARAMETER(dummy_c);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_next(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character;

#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type next_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    UI_character_type next_one_char = 0;
    UI_character_type next_two_char = 0;
    UI_character_type next_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */


#ifdef __MMI_INDIC_ALG__

    UI_buffer_type check_single_line_text_p = b->current_text_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* text buffer is empty and want to navigate next --> play error tone if not disable tones */
    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return;
    }

    gui_single_line_input_box_confirm_multitap_character(b);

#ifdef __MMI_INDIC_ALG__
    UI_STRING_GET_NEXT_CHARACTER(check_single_line_text_p, current_character);  /* get previous character */
    /* If Hindi Character */
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        current_text_p = ire_get_next_cluster_p(b->current_text_p,b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
    }
    else
#endif /* __MMI_INDIC_ALG__ */ 

    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);        /* get next character */
    }
#if defined(__MMI_LANG_VIETNAMESE__)
    if ((current_character > 0x0040) && (current_character < 0x01B1))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, next_unicode);     /* get next character */
        tone_mark = mmi_viet_tone_mark(next_unicode);
        if (VIET_TONE_NONE != tone_mark)
        {
            viet_vowel = mmi_viet_vowel_letter(current_character);
            if (VIET_VOWEL_NONE != viet_vowel)
            {
                current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
            }
            else
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, next_unicode);
            }
        }
        else
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, next_unicode);
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    if (isThaiChar(current_character) && *current_text_p != '\0')
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, next_one_char);
        if (isThaiChar(next_one_char))
        {
            if (!RequireToMoveCursor(current_character, next_one_char))
            {
                if (*current_text_p == '\0')
                {
                    current_character = next_one_char;
                }
                else
                {
                    UI_STRING_GET_NEXT_CHARACTER(current_text_p, next_two_char);
                    if (isThaiChar(next_two_char))
                    {
                        if (!RequireToMoveCursor(next_one_char, next_two_char))
                        {
                            if (*current_text_p == '\0')
                            {
                                current_character = next_two_char;
                            }
                            else
                            {
                                UI_STRING_GET_NEXT_CHARACTER(current_text_p, next_three_char);
                                if (isThaiChar(next_three_char))
                                {
                                    if (!RequireToMoveCursor(next_two_char, next_three_char))
                                    {
                                        current_character = next_three_char;
                                    }
                                    else
                                    {
                                        UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                                    }
                                }
                                else
                                {
                                    UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                                }
                            }
                        }
                        else
                        {
                            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                        }
                    }
                    else
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                    }
                }
            }
            else
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            }
        }
        else
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

/* START PMT PATCH04052007 */
#if defined (__MMI_BIDI_ALG__) && defined (__MMI_ARSHAPING_ENGINE__)
/* END PMT PATCH04052007 */
  
     if (IS_ARABIC_CHARACTER(current_character))
     {
         U16 idx;
         idx = (current_text_p - b->text)/2-1;
       
         while(idx < unshaped_text_len)
         {
             if(OrgToSha[idx] == OrgToSha[idx+1])
             {
                 UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
             }
             else
             {
                 break;
             }
             idx++;
         }
     } 
#endif


    /* if current character is end of string and want to navigate next --> play error tone if not disable tones */
    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return;
    }
    b->current_text_p = current_text_p;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_next_steps
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  steps       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_single_line_input_box_next_steps(single_line_input_box *b, S32 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character;
    S32 count = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == steps)
    {
        return 0;
    }

    if (b->text == NULL)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
        return (count);
    }
    while (!done)
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            break;
        }
        count++;
        if (count >= steps)
        {
            break;
        }
    }
    if (count != steps)
    {
        if (!(b->flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_TONES))
        {
            UI_editor_play_tone_cannot_navigate();
        }
    }
    b->current_text_p = current_text_p;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_single_line_input_box
 * DESCRIPTION
 *  Changes the size of the single-line inputbox.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_single_line_input_box(single_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    /* Autocalculate the text position based on font   */
    if (b->flags & UI_SINGLE_LINE_INPUT_BOX_CENTER_Y)
    {
        S32 string_height;

        gui_set_font(b->text_font);
        string_height = gui_get_character_height();
        b->text_y = (height >> 1) - (string_height >> 1);
    }
    else
    {
        b->text_y = 2;
    }
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single inout box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_goto_first_character
 * DESCRIPTION
 *  Move the cursor to first chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_goto_first_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_goto_last_character
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_single_line_input_box_goto_last_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    if (b->text != NULL)
    {
        while (!done)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        if (b->current_text_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        }
    }
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line inut box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_end
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_end(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_PREVIOUS_CHARACTER(last_position_p, current_character);
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            break;  /* check for space */
        }
    }
    b->highlight_start_position = previous_position;
    current_position = saved_current_position;
    /* Move cursor forwards until a break character is encountered */
    if (current_position >= last_position_p)
    {
        done = 1;
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);      /* get next character */
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);  /* get previous charcter */
        if (UI_STRING_SPACE_CHARACTER(current_character))   /* check for space */
        {
            done = 1;
            b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        else
        {
            done = 0;
            b->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
    }
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    b->current_text_p = current_position;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_number
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b               [IN]        Is the single-line inputbox object
 *  numOfChar       [IN]        
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_number(single_line_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;

    /* UI_buffer_type previous_position; */
    UI_character_type current_character;
    S32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < numOfChar; i++)
    {
        /* previous_position=current_position; */
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);  /* get previous charcter */
        count++;
    }

    b->highlight_start_position = current_position;
    current_position = saved_current_position;
    b->highlight_end_position = current_position;
    b->current_text_p = current_position;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single lien input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    UI_UNUSED_PARAMETER(current_character);
    return (count);
}

/* for second word highlight */


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_number_backward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  numOfChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_number_backward(single_line_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;

    /* UI_buffer_type previous_position; */
    UI_character_type current_character = 0xff;
    S32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < numOfChar; i++)
    {
        /* previous_position=current_position; */
        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);      /* get previous charcter */
        count++;
    }

    b->second_highlight_end_position = current_position;
    current_position = saved_current_position;
    b->second_highlight_start_position = current_position;
    b->current_text_p = current_position;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single lien input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_highlight_cursor_start
 * DESCRIPTION
 *  Move the cursor to last  chahrcter
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  S32 count return the number of charcters traverse
 *****************************************************************************/
S32 gui_single_line_input_box_highlight_cursor_start(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->current_text_p;
    UI_buffer_type current_position = b->current_text_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position == b->text)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);      /* get previous charcter */
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    current_position = saved_current_position;
    /* Move cursor backwards until a break character is encountered   */
    if (current_position == b->text)
    {
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    if (UI_STRING_SPACE_CHARACTER(current_character))   /* check for space */
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        if (UI_STRING_SPACE_CHARACTER(current_character))
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    b->current_text_p = previous_position;
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_insert_string
 * DESCRIPTION
 *  insert a string in single lien input box at particular poistion
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  s       [IN]        String to insert
 *  o       [IN]        Index
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_single_line_input_box_insert_string(single_line_input_box *b, UI_string_type s, S32 o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;
    U8 done = 0;
    S32 count = 0;
    UI_character_type c;
    UI_buffer_type text = (UI_buffer_type) s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        UI_STRING_GET_NEXT_CHARACTER(text, c);
        if (UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            done = 1;
            break;
        }
        if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {
            if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                done = 1;
                break;
            }
            else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                done = 1;
                break;
            }
        }
        p1 = p2 = b->current_text_p;
        if ((b->last_position_p - b->text) >= (b->available_length))
        {
            done = 1;
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
        if (b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            if (b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
            {
                UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                    c,
                    b->UCS2_count,
                    b->allocated_length,
                    b->available_length);
            }
            else
            {
                UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
            }
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            /* MTK Add By Elvis */
            UI_STRING_INSERT_CHARACTER(p2, c - o);
            
            c = old_c;
        }
        UI_STRING_INSERT_CHARACTER(p2, c);
        count++;
        b->text_length += ((S32) p2 - (S32) p1);
    }
    b->flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_single_line_input_box(b);          /* show single line input box */
    b->flags &= ~UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_single_line_input_box_locate_cursor(b); /* locate cursor */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
    return (count);
}

/* GUI: multiline input box functions              */

UI_multi_line_input_box_theme *current_multi_line_input_box_theme = NULL;

#define UI_MULTI_LINE_INPUT_BOX_NUMBER_OF_BREAK_CHARACTERS     2        /* 15 */
#define MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES              1
#define MULTILINE_INPUTBOX_USE_CRLF_COMBINATION             1
/* To use this flag, turn ON EMS_DISPLAY_SPECIAL_CHARACTERS also (outside this file)   */
#define MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS       0
#define MULTILINE_INPUTBOX_USE_GSM_EXTENDED                 1

UI_character_type multi_line_input_box_break_characters[] = { ' ',
    /*
     * '.',
     * ',',
     * '\\',
     * '/',
     * '-',
     * ':',
     * ';',
     * '?',
     * '!',
     * '|',
     * '+',
     * '=',
     * '_',
     */
    '\n'
};

/* Linear search. Should be improved to something else   */
#define UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(c,flag)                                               \
      {  S32 _ii_;                                                                                    \
         flag=0;                                                                                      \
         for(_ii_=0;_ii_<UI_MULTI_LINE_INPUT_BOX_NUMBER_OF_BREAK_CHARACTERS;_ii_++)                   \
         {  if((UI_character_type)c==(UI_character_type)multi_line_input_box_break_characters[_ii_])  \
            {  flag=1;                                                                                \
               break;                                                                                 \
            }                                                                                         \
         }                                                                                            \
      }

#define UI_MULTI_LINE_INPUT_BOX_SPACE_CHARACTER(c) (((UI_character_type)(c)==(UI_character_type)' ')?(1):(0))

/* Basic Latin,Latin 1,Latin Extended A, Latin Extended B */
/* Cyrillic */
/* Latin Extended Additional  */
/* Combining Marks  */
/* Basic Arabic  */
/* Arabic Presentation Forms-A */
/* Arabic Presentation Forms-B */

#define UI_MULTI_LINE_INPUT_BOX_ALPHABETIC_CHARACTER(c)                                                              \
   (( ((UI_character_type)(c)>=(UI_character_type)0x2180) && ((UI_character_type)(c)<=(UI_character_type)0x9FAF) )?0:1) // only CJK will not word wrapping

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#define UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(x,y)                                        \
      {                                                                                      \
         UI_text_x=x;                                                                        \
         UI_text_y=y;                                                                        \
      }

#define UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(c)                                            \
      {                                                                                      \
         UI_text_color=c;                                                                    \
      }

#define UI_MULTI_LINE_INPUT_BOX_DRAW_CURSOR(x,y,height,c)                                       \
      {                                                                                         \
         gui_fill_rectangle((x)-1,( y),(x),(y)+(height)-1,c);                                   \
      }

#define MULTI_LINE_INPUT_BOX_CHARACTER_WIDTH_CACHE_SIZE  ((UI_device_width)>>1)
#define UI_TEST_GRP_SEP_CHARACTER(c)            (((UI_character_type)(c)==(UI_character_type)0x1D)?(1):(0))

#define UI_TEST_FILE_SEP_CHARACTER(c)           (((UI_character_type)(c)==(UI_character_type)0x1C)?(1):(0))
#define UI_TEST_SENDER_TRUNCATE_SEP_CHARACTER(c)   (((UI_character_type)(c)==(UI_character_type)0x1E)?(1):(0))
#define UI_TEST_RECEIVER_TRUNCATE_SEP_CHARACTER(c)  (((UI_character_type)(c)==(UI_character_type)0x1F)?(1):(0))


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_show_cursor
 * DESCRIPTION
 *  show cursor of  multiline input box
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object
 *  x           [IN]        
 *  y           [IN]        
 *  height      [IN]        
 *  clip_x1     [IN]        
 *  clip_y1     [IN]        
 *  clip_x2     [IN]        
 *  clip_y2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void gui_multi_line_input_box_show_cursor(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 height,
        S32 clip_x1,
        S32 clip_y1,
        S32 clip_x2,
        S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.06 Fix Cursor Clipping issue when storing cursor area to bmp */
    gdi_layer_push_clip();
    gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    if (x > clip_x2)
    {
        x = clip_x2;
    }
    x--;
    if (x < clip_x1)
    {
        x = clip_x1;
    }
    if (y < clip_y1)
    {
        height -= (clip_y1 - y + 1);
        y = clip_y1 + 1;
    }
    if ((y + height - 1) > clip_y2)
    {
        height -= (y + height - 1) - clip_y2;
    }
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > (b->y + b->height) || (y + height) < b->y)
        StopTimer(BLINKING_CURSOR);
    else
        UI_inputbox_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_cursor_x1 = x;
    UI_cursor_y1 = y;
    UI_cursor_x2 = x+1;
    UI_cursor_y2 = y+height - 1;

    gui_fill_rectangle(x, y, x + 1, y + height - 1, c);
#endif 
    gdi_layer_pop_clip();
}




/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme to the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_current_theme(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_multi_line_input_box_theme->normal_filler;
    b->disabled_filler = current_multi_line_input_box_theme->disabled_filler;
    b->focussed_filler = current_multi_line_input_box_theme->selected_filler;
    b->text_filler = NULL;  /* Disabled by default */
    b->special_text_color = current_multi_line_input_box_theme->special_text_color;
    b->normal_text_color = current_multi_line_input_box_theme->normal_text_color;
    b->disabled_text_color = current_multi_line_input_box_theme->disabled_text_color;
    b->focussed_text_color = current_multi_line_input_box_theme->selected_text_color;
    b->selector_color = current_multi_line_input_box_theme->selection_color;
    b->selected_text_color = current_multi_line_input_box_theme->selection_text_color;
    b->cursor_color = current_multi_line_input_box_theme->cursor_color;
    b->text_font = current_multi_line_input_box_theme->text_font;
    b->mask_character = current_multi_line_input_box_theme->mask_character;
    b->text_gap = current_multi_line_input_box_theme->text_gap;
    b->flags |= current_multi_line_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_theme(multi_line_input_box *b, UI_multi_line_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = t->normal_filler;
    b->disabled_filler = t->disabled_filler;
    b->focussed_filler = t->selected_filler;
    b->text_filler = NULL;  /* Disabled by default */
    b->special_text_color = t->special_text_color;
    b->normal_text_color = t->normal_text_color;
    b->disabled_text_color = t->disabled_text_color;
    b->focussed_text_color = t->selected_text_color;
    b->boundary_color = t->boundary_color;
    b->selector_color = t->selection_color;
    b->selected_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->mask_character = t->mask_character;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_clear
 * DESCRIPTION
 *  Initilize the multi-line inputbox to default
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_clear(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
        return;
    }
    else
    {
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        if(!gui_multi_line_input_box_clear_wcss(b))
#endif 
        {
            b->text[0] = '\0';
            b->text[1] = 0;
            b->text_length = 2;
        }
    }
    b->cursor_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    b->GSM_ext_count = 0;
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        b->available_length = b->allocated_length;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_text_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object   (pre-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multi_line_input_box_text_size(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->normal_filler->flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
    {
        b->edit_height = b->height - b->text_y - 1 - 4;
    }
    else if (b->normal_filler->flags & UI_FILLED_AREA_BORDER)
    {
        b->edit_height = b->height - b->text_y - 1 - 2;
    }
    else
        b->edit_height = b->height - b->text_y - 1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box
 * DESCRIPTION
 *  Creates a multi-line inputbox object
 *  Starts with an empty string
 *  
 *  See also gui_destroy_multi_line_input_box()
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object   (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the multi-line inputbox
 *  height      [IN]        Is the height of the multi-line inputbox
 *  length      [IN]        Is the length of the buffer         (auto-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box(multi_line_input_box *b, S32 x, S32 y, S32 width, S32 height, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) gui_malloc(length * sizeof(UI_character_type));
    b->allocated_length = length;
    b->available_length = length;
    gui_multi_line_input_box_clear(b);  /* show multi line input box to defualt values */
    b->cursor_p = b->text;
    /* set theme of multiline input box */
    gui_set_multi_line_input_box_current_theme(b);
    b->text_x = 2 + b->text_gap;
    b->text_y = 2;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    /* create vertial scroll bar */
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_multi_line_input_box_theme->vbar_width,
        b->height - 2);
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }

    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);
#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box_use_buffer
 * DESCRIPTION
 *  Creates a multi-line inputbox object with a user specifed buffer
 *  Starts with an empty string
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object   (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the multi-line inputbox
 *  height      [IN]        Is the height of the multi-line inputbox
 *  buffer      [IN]        Is a pointer to the text buffer to use (pre-allocated)
 *  length      [IN]        Is the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box_use_buffer(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    gui_multi_line_input_box_clear(b);
    b->cursor_p = b->text;
    /* set theme of multiline input box */
    gui_set_multi_line_input_box_current_theme(b);
    b->text_x = 2 + b->text_gap;
    b->text_y = 2;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    /* create vertical scroll  bar */
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_multi_line_input_box_theme->vbar_width,
        b->height - 2);
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }
    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);
#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */

#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box_set_buffer
 * DESCRIPTION
 *  Creates a multi-line inputbox object,
 *  Starts with a given string and allows the user to edit it.
 * PARAMETERS
 *  b                   [IN]        Is the multi-line inputbox object   (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the multi-line inputbox
 *  height              [IN]        Is the height of the multi-line inputbox
 *  buffer              [IN]        Is the buffer to use          (pre-allocated)
 *  length              [IN]        Is the length of the buffer         (buffer size)
 *  text_length         [IN]        Is the number of characters in the text
 *  edit_position       [IN]        Is the start position of the cursor
 *  Note(?)             [IN]        The buffer should contain a valid string.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box_set_buffer(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /* MTK Elvis to init this parameter */
    UI_character_type dummy_c = '\0';

    
    UI_buffer_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->text_length = text_length;
    b->cursor_p = b->text;
    b->show_action_flag = 1;
    #if defined(__MMI_INDIC_ALG__)
    IRE_RESET_LANGUAGE_VARIABLES();
    #endif

    if (b->text != NULL)
    {
/* PMT START FOR_7.17INDIC */
        text = b->text;
        UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
        text = b->text;
        for (i = 0; i < text_length/2; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            #if defined(__MMI_INDIC_ALG__)
	    IRE_INCREMENT_LANGUAGE_VARIABLES(dummy_c);
            #endif
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
           
        }
/* PMT END FOR_7.17INDIC */
        text = b->text;
        UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
/* PMT START FOR_7.17INDIC */
//REMOVED
/* PMT END FOR_7.17INDIC */

            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->cursor_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);

/* PMT START FOR_7.17INDIC */
//REMOVED
/* PMT END FOR_7.17INDIC */
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->last_position_p = b->cursor_p;
    }
    /*PMT START MAUI_00027919*/
        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_INDIC_ALG__) 
 
        {
            U32 i=0;
            U16 character = 0; 
            U8* s=b->text; 
            for(i=0;((s[2*i]!=0x0) ||(s[2*i+1]!=0x0));i++)
            {
                PMT_BIDI_TYPES default_direction = BIDI_L;
                #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                character  = (U16)((U16) s[2*i+1]) | (((U16) s[2*i]) << 8);
                #else 
                character = (U16)((U16) s[2*i]) | (((U16) s[2*i+1]) << 8);
                #endif

                 if(IRE_INSERTED_ARABIC_COUNT() && IRE_INDIC_LANGUAGE_RANGE(character))
                 {
                     IRE_DECREMENT_LANGUAGE_VARIABLES(character);
                     character = (U16)'?';
                     #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                     s[2*i] = (character & 0xff00) >> 8;
                     s[2*i+1] = (character & 0x00ff);
                     #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                     s[2*i+1] = (U8) (character >> 8);
                     s[2*i] = (U8) character;
                     #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */
                     b->UCS2_count--;
                     
                     
                 }
  
            }
        }
        #endif
 /*PMT END MAUI_00027919*/
    /* set theme of multiline input bx */
    gui_set_multi_line_input_box_current_theme(b);
    b->text_x = 2 + b->text_gap;
    b->text_y = 2;
    b->text_x2_gap_width = 0;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        gui_create_vertical_scrollbar(
            &b->vbar,
            b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
            b->y + 1,
            current_multi_line_input_box_theme->vbar_width,
            b->height - 2);
        b->edit_width -= b->vbar.width;
    }
    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);

#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);
}

//Gurinder - 5/5/2004 Inline Multiline Box History Control
//Duplicate Function With No Position Reset.


/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_input_box_set_buffer_no_text_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [?]         
 *  x                   [IN]        
 *  y                   [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  buffer              [IN]        
 *  length              [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_multi_line_input_box_set_buffer_no_text_reset(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_character_type dummy_c = 0;
    UI_buffer_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* so many members need to be set zero. To avoid non-initialized bug, use memset*/
    memset(b, 0, sizeof(multi_line_input_box));

    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->text_length = text_length;
    b->cursor_p = b->text;
    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->cursor_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_TEST_GSM_EXTENDED(dummy_c))
            {
                b->GSM_ext_count++;
            }
        }
        b->last_position_p = b->cursor_p;
    }
    /* set theme of multiline input bx */
    gui_set_multi_line_input_box_current_theme(b);
    b->text_x = 2 + b->text_gap;
    b->text_y = 2;
    b->text_x2_gap_width = 0;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    b->edit_height = b->height - (b->text_y * 2);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_multi_line_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_multi_line_input_box_theme->vbar_width,
        b->height - 2);
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }
    gui_multi_line_input_box_register_infobar_callback(b,NULL,NULL,0);

#ifdef __MMI_TOUCH_SCREEN__
    b->pen_scroll_after_delay = -1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 

    gui_set_multi_line_input_box_text_size(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_multi_line_input_box
 * DESCRIPTION
 *  Moves a multi-line input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  x       [IN]        Is the new position (left-top corner)
 *  y       [IN]        Is the new position (left-top corner)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_multi_line_input_box(multi_line_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width, b->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_multi_line_input_box
 * DESCRIPTION
 *  Moves a multi-line input box
 * PARAMETERS
 *  b           [IN]        Is the multi-line inputbox object
 *  width       [IN]        
 *  height      [IN]        
 *  x(?)        [IN]        Is the new position (left-top corner)
 *  y(?)        [IN]        Is the new position (left-top corner)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_multi_line_input_box(multi_line_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    b->edit_width = b->width - (b->text_x + b->text_x2_gap_width);
    //b->edit_height = b->height - (b->text_y * 2);
    gui_set_multi_line_input_box_text_size(b);
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
    gui_resize_vertical_scrollbar(&b->vbar, b->vbar.width, b->height - 2);
    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        b->edit_width -= b->vbar.width;
    }

    StopTimer(BLINKING_CURSOR);

    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_overflow
 * DESCRIPTION
 *  check for overflow of multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_overflow(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_first_position
 * DESCRIPTION
 *  check forif cursor is at first position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_first_position(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->cursor_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_last_position
 * DESCRIPTION
 *  check forif cursor is at last  position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_last_position(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_test_last_position_overflow
 * DESCRIPTION
 *  check forif cursor is at last  position of  multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_multi_line_input_box_test_last_position_overflow(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->cursor_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->last_position_p - b->text) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_text_length
 * DESCRIPTION
 *  return the text length of multiline input box
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  byte
 *****************************************************************************/
S32 gui_multi_line_input_box_get_text_length(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
/****************WCSS Related Functions***********************/

/* Cursor position previously set by WCSS editor.
   This variable is used to avoid unnecessary input method switching 
   when cursor is not moved. */
static UI_buffer_type WCSS_cursor_pos = NULL;
extern U8 *cat115buffer;
extern void change_input_mode(void);
extern void (*inputbox_change_mode) (void);
extern void change_multiline_inputbox_input_mode(void);

/* Set # Key Depeding Upon The Value Of Status Parameter. */

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_clear_wcss
 * DESCRIPTION
 *  Initilize the multi-line inputbox to default
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_clear_wcss(multi_line_input_box *b)
{
    if(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        UI_buffer_type old_cursor=NULL;
        while(old_cursor != b->cursor_p)
        {
            old_cursor = b->cursor_p;
            gui_multi_line_input_box_next(b);
        }

        old_cursor = NULL;
        while(old_cursor != b->cursor_p)
        {
            old_cursor = b->cursor_p;
            gui_multi_line_input_box_delete_character(b);
        }
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_WCSS_input_method_change_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_set_WCSS_input_method_change_handler(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status)
    {
        SetKeyHandler(wgui_handle_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
        inputbox_change_mode = change_multiline_inputbox_input_mode;
    }
    else
    {
        SetKeyHandler(UI_dummy_function, KEY_POUND, KEY_EVENT_DOWN);
        inputbox_change_mode = UI_dummy_function;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_reset_WCSS_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_WCSS_cursor_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WCSS_cursor_pos = NULL;
}

/* Change the input method on cursor movement. */


/*****************************************************************************
 * FUNCTION
 *  gui_change_WCSS_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_WCSS_input_method(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
    {
        return;
    }

    /* Prevent gui_show_multi_line_input_box() invokes this function recursively */
    WCSS_input_change_enable = 0;

    while (WCSS_cursor_pos != b->cursor_p &&
           (b->cursor_p - b->text) < (b->allocated_length - 2) /* out-of-edit area */ )
    {
        U16 temp_var;
        U8 input_method;

        UI_buffer_type prv_cursor_pos = WCSS_cursor_pos;

        temp_var = ((b->cursor_p - b->text) >> 1);

        /* If \c appears in the head of input format */
        if (temp_var == 0)
        {
            while (cat115buffer[temp_var] == 0xFF)
            {
                gui_multi_line_input_box_next(b);
                temp_var = ((b->cursor_p - b->text) >> 1);
            }
        }

        /* Set WCSS_cursor_pos if input mode is chaged here */
        if (MMI_active_multitap == -1 || WCSS_Esc_Char)
        {
            WCSS_cursor_pos = b->cursor_p;
        }

        if (cat115buffer[temp_var] == 0xFF)
        {
            if (MMI_active_multitap == -1 || WCSS_Esc_Char)
            {
                /* It always invokes gui_change_WCSS_input_method again (recursive) */
                if (prv_cursor_pos > b->cursor_p)
                {
                    gui_multi_line_input_box_previous(b);
                }
                else
                {
                    gui_multi_line_input_box_next(b);
                }
            }
            else
            {
                break;
            }
        }

        temp_var = ((b->cursor_p - b->text) >> 1);
        input_method = cat115buffer[temp_var] & 0x1F;

        if (MMI_active_multitap == -1 || WCSS_Esc_Char)
        {
            /* If switch from 'm' to 'm', do not switch input method automatically. */
            if (!(cat115buffer[temp_var] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED) ||
                !prv_cursor_pos ||
                !(cat115buffer[(prv_cursor_pos - b->text) >> 1] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED)
                || ((cat115buffer[(prv_cursor_pos - b->text) >> 1] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED) 
                     && cat115buffer[(prv_cursor_pos - b->text) >> 1] != cat115buffer[temp_var]))
            {
                /* If entry category115 from history (prv_cursor_pos = WCSS_cursor_pos was set to NULL), 
                   we should not change the input method according the WCSS input format string to
                   keep the previous input method in history */
                if (prv_cursor_pos /* not first time in category screen */  ||
                    is_fisrt_entry_WCSS_editor /* input method was not set in history */ )
                {
                    if (MMI_current_input_mode != (input_method & (~PIXTEL_UI_WCSS_STAR_INPUT)))
                    {
                        MMI_current_input_mode = input_method & (~PIXTEL_UI_WCSS_STAR_INPUT);
                        gui_lock_double_buffer();
                        change_multiline_inputbox_mode(MMI_current_input_mode);
                        set_MMI_current_input_type();
                        change_multiline_information_bar_input_method();
                        gui_unlock_double_buffer();
                    }
                }
                is_fisrt_entry_WCSS_editor = MMI_FALSE;

                /* Fix for 'N'. */
                if (MMI_current_input_type == INPUT_TYPE_NUMERIC_CHANGEABLE)
                {
                    ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
                    ClearKeyHandler(KEY_STAR, KEY_EVENT_DOWN);
                    /* Tricky. set_MMI_current_input_type() change INPUT_MODE_123 to INPUT_TYPE_NUMERIC_CHANGEABLE */
                    MMI_current_input_type = INPUT_TYPE_NUMERIC;
                }
            }

            if (((input_method & 0xFF) == INPUT_MODE_MULTITAP_UPPERCASE_ABC || (input_method & 0xFF) == INPUT_MODE_MULTITAP_LOWERCASE_ABC) && cat115buffer[temp_var] & PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED)     /* 'm' and 'M', not 'x' or 'X' */
            {
                MMI_allow_only_english_input_modes = 1; /* Only support english input */
                gui_set_WCSS_input_method_change_handler(1);
            }
            else
            {
                gui_set_WCSS_input_method_change_handler(0);
            }
        }

        if (cat115buffer[((b->cursor_p - b->text) >> 1)] != 0xFF)
        {
            break;
        }
    }

    /* hjf: set again because cursor position is changed */
    if (MMI_active_multitap == -1 || WCSS_Esc_Char)
        WCSS_cursor_pos = b->cursor_p;

    WCSS_input_change_enable = 1;
    WCSS_Esc_Char = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_WCSS_check_next_multitap_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_WCSS_check_next_multitap_input(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_var;
    U8 input_method;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_var = ((b->cursor_p - b->text) >> 1);
    while (cat115buffer[temp_var] == 0xFF)
    {
        temp_var++;
    }
    input_method = cat115buffer[temp_var] & 0x1F;
    if (input_method == INPUT_MODE_123 || input_method == INPUT_MODE_123_SYMBOLS)       /* Add Here Other Input Method For Which Multitap is not require. */
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Wrapper function for WCSS_input_change_enable Variable use to Enable Input Method Change
//While deleting the characters.


/*****************************************************************************
 * FUNCTION
 *  gui_WCSS_input_method_change_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_WCSS_input_method_change_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WCSS_input_change_enable;
}

/****************************WCSS Related Functions**************************/
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

/* Set The Editor Chnaged Variable To True On Contents Change. */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_change(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->editor_changed = 1;
}

/* bar code */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  idx         [IN]        
 *  by_pen      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_hilite(multi_line_input_box *b, U16 idx, MMI_BOOL need_scroll_to_pos)
{
    if (idx <= b->hilite_str_number - 1)
    {

        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[idx].str_addr);
        b->highlight_end_position = (UI_buffer_type) (b->hilite_list[idx].str_addr + b->hilite_list[idx].length * 2);

    }

    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    if (need_scroll_to_pos)
    {
        if(b->text_height > b->edit_height)
        {
            S32 highy = -b->curr_hilite_text_offset_y;
            S32 oy = -b->text_offset_y;

            // check if highlight begin is above the windows begin
            if( highy < oy) 
            {
                // move window begin to highlight begin
                b->text_offset_y = b->curr_hilite_text_offset_y;
            }
            // check if highlight end is below the window end
            else if(oy+b->edit_height < highy + b->max_line_height*2)
            {
                // move window begin to the hightlight end - window height
                b->text_offset_y = - ( highy + b->max_line_height*2 -b->edit_height);
            }
        }
    }
    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
    b->hilite_cb(b->current_hilite_idx);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_pre_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_pre_hilite(multi_line_input_box *b)
{
	if(b->hilite_str_number == 0) return; // no hilite, no need to scroll anything

    if (b->current_hilite_idx > 0)
    {
        b->current_hilite_idx--;
        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr);
        b->highlight_end_position =
            (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr +
                              b->hilite_list[b->current_hilite_idx].length * 2);

    }

    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    if(b->text_height > b->edit_height)
    {
        b->text_offset_y = b->curr_hilite_text_offset_y;
    }
    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
    b->hilite_cb(b->current_hilite_idx);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_go_to_next_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_go_to_next_hilite(multi_line_input_box *b)
{
	if(b->hilite_str_number == 0) return; // no hilite, no need to scroll anything

    if (b->current_hilite_idx < b->hilite_str_number - 1)
    {
        b->current_hilite_idx++;
        b->highlight_start_position = (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr);
        b->highlight_end_position =
            (UI_buffer_type) (b->hilite_list[b->current_hilite_idx].str_addr +
                              b->hilite_list[b->current_hilite_idx].length * 2);

    }
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    if(b->text_height > b->edit_height)
    {
        b->text_offset_y = b->curr_hilite_text_offset_y;
    }
    gui_show_multi_line_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);

    b->hilite_cb(b->current_hilite_idx);
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pos_inside_hilite_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  current_pos     [IN]        
 *  hilite_idx      [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite_ext(
            multi_line_input_box *b,
            UI_buffer_type current_pos,
            U16 *hilite_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_no = b->hilite_str_number;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < hilite_no; i++)
    {
        if (((S8*)current_pos >= b->hilite_list[i].str_addr) &&
            ((S8*)current_pos < b->hilite_list[i].str_addr + b->hilite_list[i].length * 2))
        {
            *hilite_idx = i;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pos_inside_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  current_pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite(multi_line_input_box *b, UI_buffer_type current_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hilite_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, current_pos, &hilite_idx));
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_is_pen_down_in_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_is_pen_down_in_hilite(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_pos = b->cursor_p;
    U16 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_multi_line_input_box_is_pos_inside_hilite_ext(b, current_pos, &idx))
    {
        b->current_hilite_idx = idx;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}



/***Ritesh started here***/

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_get_next_page_callback
 * DESCRIPTION
 *  callback function for demand of next page by multiline editor
 * PARAMETERS
 *  b       [IN]        (instance of multi_line_input_box)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_get_next_page_callback(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_index;
    S32 cursor_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mbj06060 add for cursor movement at paging mode
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        cursor_move = (b->previous_shared_bytes + GUI_PAGE_SIZE_IN_UCS2) - b->page_details[PAGE_ZERO].shared_no_of_bytes;
        b->cursor_p -= cursor_move;

        if (b->cursor_p < b->text)
            b->cursor_p = b->text;
    }
    
    memcpy(b->text, b->page_details[PAGE_ZERO].shared_data, b->page_details[PAGE_ZERO].shared_no_of_bytes);

    for (page_index = 0; page_index < GUI_NO_OF_PAGES - 1; page_index++)
    {
        memcpy(
            b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index) + b->page_details[PAGE_ZERO].shared_no_of_bytes,
            b->text + b->previous_shared_bytes + (GUI_PAGE_SIZE_IN_UCS2 * (page_index + 1)),
            GUI_PAGE_SIZE_IN_UCS2);
    }
    b->previous_shared_bytes = b->page_details[PAGE_ZERO].shared_no_of_bytes;

    b->start_id++;
    b->end_id++;
    b->page_details[PAGE_ZERO].page_id = b->start_id;
          
    ASSERT(b->get_page_cb);
    b->get_page_cb(
        b->end_id,
        b->end_id,
        b->text + (GUI_PAGE_SIZE_IN_UCS2 * PAGE_THREE) + b->page_details[PAGE_ZERO].shared_no_of_bytes);

    b->text_length = (mmi_ucs2strlen((const S8*)b->text)+1)*ENCODING_LENGTH;
    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_get_previous_page_callback
 * DESCRIPTION
 *  callback function for previous page
 * PARAMETERS
 *  b       [IN]        (instance of multi_line_input_box)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_get_previous_page_callback(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 page_index;
    S32 cursor_move;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->page_details[0].page_id > 0)
    {
        //mbj06060 add for cursor movement at paging mode
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
        {
            cursor_move = GUI_PAGE_SIZE_IN_UCS2 - b->previous_shared_bytes;
            b->cursor_p += cursor_move;
            
            if (b->cursor_p > b->text + b->text_length)
                b->cursor_p = b->text + b->text_length;
        }
        
        b->page_zero_prev_height = b->page_details[PAGE_ZERO].page_height;
        for (page_index = GUI_NO_OF_PAGES - 1; page_index != 0; page_index--)
        {
            memcpy(
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index) + b->previous_shared_bytes,
                b->text + (b->previous_shared_bytes * ENCODING_LENGTH) + (GUI_PAGE_SIZE_IN_UCS2 * (page_index - 1)),
                GUI_PAGE_SIZE_IN_UCS2 - b->previous_shared_bytes);
            memcpy(
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * page_index),
                b->text + (GUI_PAGE_SIZE_IN_UCS2 * (page_index - 1)) + b->previous_shared_bytes,
                b->previous_shared_bytes);
        }

        ASSERT(b->get_page_cb);
        b->get_page_cb(b->start_id - 1, b->start_id - 1, b->text);
        b->previous_shared_bytes = 0;

        b->text_length = (mmi_ucs2strlen((const S8*)b->text)+1)*ENCODING_LENGTH;
        show_multiline_inputbox();
        b->start_id--;
        b->end_id--;
    }
}

#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
/***** ritesh ended here*****/


/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box
 * DESCRIPTION
 *  Displays the multi-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 EMS_object_width_cache[];
extern U8 EMS_object_height_cache[];

extern void (*wgui_inline_edit_DONE_function) (void);


void gui_show_multi_line_input_box(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_multi_line_input_box_ext(b, (-1), (-1));
}




/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box_ext_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

/*****************************************************************************
    while()
    {
        // P1BEGIN
        while()
        {
        }
        // P1END

        bidi_main

        // P2BEGIN
        while()
        {
        }
        // P2END
    }

 ******************************************************************************/
 
void gui_show_multi_line_input_box_ext_internal(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1;                                     /* x1,y1 -> left-top corner of the editor windows */
    S32 x2, y2;                                     /* x2,y2 -> right-bottom of the editor windows */
    UI_buffer_type current_text_p, line_start_text_p, line_break_text_p;
    UI_buffer_type previous_line_start_text_p, previous_text_p = NULL;
    UI_buffer_type current_cursor_p = b->cursor_p;  /* points to the character at which the cursor is positioned */
    UI_buffer_type previous_cursor_p = b->cursor_p;
    MMI_BOOL is_cursor_show = MMI_FALSE; //hjf , to avoid cursor to display two place. for BIDI, some case will cause two cursor

    S32 character_width = 0, character_height;
    UI_character_type current_character = 0, pre2_character = 0, pre_character = 0, dummy_c = 0;
    S32 tx = 0, ty, xx, yy, temp_d;
    color selector_color = b->selector_color;
    color selected_text_color = b->selected_text_color;
	S32 reserve_line_height_for_hilite; // using in barcode
    S32 cursor_line_height = 0;
    S32 current_line_width, previous_line_width;
    S32 current_line_height = 0, previous_line_height, previous2_line_height, saved_line_height = 1;
    S32 current_line_character_counter = 0;
    S32 current_line_break_character_counter;
    U8 done = 0, locate_cursor = 0/*, first_text_display = 0*/, border_y = 0;
    S32 edit_width, edit_height;
    U8 *character_widths_cache = EMS_object_width_cache;
    U8 *character_heights_cache = EMS_object_height_cache;
    U32 flags = b->flags;
    S32 line_counter = 0;
    U8 multitap_flag = 0;
    U8 overwrite_flag = 0;
    S32 set_cursor_flag = 0;
    UI_buffer_type temp_text_p;
    U8 next_line_found_flag = 0;
    S32 mask_character_width = 0, mask_character_height;
    U8 word_highlight = 0;
    S32 xtx, yty = 0;
    S32 l_clip = 0;
    PMT_BIDI_TYPES default_direction = BIDI_L;
    gui_input_richtext_struct rich_text;

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    U8 shared_data_count, check_flag = 0, i;
    U32 height_previous_page = 0;
#endif 

#if defined(__MMI_BIDI_ALG__)
    UI_buffer_type temp_p;
    UI_character_type next_char = 0;
#endif /*__MMI_BIDI_ALG__ */ 

    

    /* PMT VIKAS START 20050707 */
#ifdef __MMI_UI_DALMATIAN_EDITOR__
    S32 image_width, image_height;
#endif 
    /* PMT VIKAS END 20050707 */
#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U8 *temp_text_pt = NULL;
    U8 *temp_cursor_p = NULL;
    U8 *temp_pre_cursor_p = NULL;
    U16 visual_str_len;
    U16 visual_cur_pos;
    U16 logical_hilight_start;
    U16 logical_hilight_end;
    U16 visual_hilight_start;
    U16 visual_hilight_end;
    UI_buffer_type temp_hilight_start = NULL;
    UI_buffer_type temp_hilight_end = NULL;

    pBOOL reverse_flag;
    S32 num_char;
    U32 iCount;
    pBOOL arabic_char_flag = MMI_FALSE, line_arabic_char_flag = MMI_FALSE;
    U8 lastest_char_type;
    UI_character_type test_current_character;

    S32 text_len;

#ifdef __MMI_MESSAGES_CHAT__
    pBOOL Show_Chat_NickName = MMI_FALSE;
#endif 
    /* MTK End */
#endif /* __MMI_BIDI_ALG__ */ 

    BOOL draw_separator;    /* Used by UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR */
    U8 break_flag;
    S32 current_cluster_width = 0;

#ifdef __MMI_INDIC_ALG__
    U16 disp_cluster[MAX_EDITOR_DISP_LEN];
    PU8 temp_hindi_cursor_p = b->text;
    S32 cluster_width = 0;
    S32 cursor_width = 0;
    PU8 move_cursor_prev_p = b->text;
    PU8 move_cursor_curr_p = b->text;
    PU8 move_cursor_disp_prev_p = b->text;
    PU8 move_cursor_disp_curr_p = b->text;
    S32 display_skip_moves = 1; /* for skipping by cluster while display */
    S32 saved_display_skip_moves = 0;
    S32 hindi_cluster_counter;

    S32 cluster_width_filler[50];
    S32 cluster_filler_count = 0;
#endif /* __MMI_INDIC_ALG__ */ 

#if defined (__MMI_BIDI_ALG__) && defined (__MMI_INDIC_ALG__)
   U8 indic_bidi_flag =0;
#endif
#if defined (__MMI_LANG_VIETNAMESE__) && defined (__MMI_INDIC_ALG__) 
   U8 vietnamese_indic_flag = 0;
#endif
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    U8 count_flag = 0; /*jump_to_offset_flag = 0;*/
    S32 total_page_height = 0;  /* ritesh */
    S32 char_count = 0;
    U8 page_index = 0;
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 

#if defined(__MMI_LANG_VIETNAMESE__)
    /* U16 next_unicode = 0; */
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    UI_buffer_type backup_text = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_cursor_x1 = 0;
    UI_cursor_y1 = 0;
    UI_cursor_x2 = 0;
    UI_cursor_y2 = 0;
 
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )

    overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif 
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    b->edit_height_displayed_lines = 0; /* ritesh */
#endif 
    
    if(b->hilite_cb)
        reserve_line_height_for_hilite = 1;
    else
        reserve_line_height_for_hilite = 0;

    if (b->header_height > 0)
        b->header_gap = 1;
    else
        b->header_gap = 0;

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)

    if ((b->text_length / ENCODING_LENGTH) - 1 != 0)
    {
			int i;
     
            mmi_ucs2ncpy((S8*) shaping_str, (const S8*)b->text, MAX_TEXT_LENGTH - 1);
            shaping_str[MAX_TEXT_LENGTH - 1] = 0;
            backup_text = b->text;
            if (b->text_length < MAX_TEXT_LENGTH * ENCODING_LENGTH)
            unshaped_text_len = text_len = (b->text_length / 2) - 1;
            else
                unshaped_text_len = text_len = MAX_TEXT_LENGTH - 1;
			
			for(i=0;i<=text_len;i++) OrgToSha[i] = i;
            ArabicShapeEngine2_ext((U16*) & text_len, (U16*) shaping_str, (U16*) OrgToSha, NULL);
            b->text = (UI_buffer_type)shaping_str;
            shaped_text_len = text_len;
			OrgToSha[unshaped_text_len] = shaped_text_len;
			OrgToSha[unshaped_text_len+1] = shaped_text_len+1;

            b->cursor_p = b->text + gui_multi_line_mapping_org_to_sha((b->cursor_p - backup_text)/2)*2;

            if ( (b->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
            {
                if(b->highlight_start_position - backup_text > b->text_length)
                    b->highlight_start_position = backup_text + b->text_length;
                if(b->highlight_end_position - backup_text > b->text_length)
                    b->highlight_end_position = backup_text + b->text_length;

                b->highlight_start_position = b->text 
                    + gui_multi_line_mapping_org_to_sha((b->highlight_start_position - backup_text)/2)*2;
                b->highlight_end_position = b->text 
                    + gui_multi_line_mapping_org_to_sha((b->highlight_end_position - backup_text)/2)*2;
            }

            b->line_before_cursor_line_p		= b->text; // initialize
            b->cursor_line_p					= b->text; // initialize
            b->line_after_cursor_line_p			= b->text; // initialize
            b->line_after_cursor_line_last_p = b->text; // initialize
            b->last_position_p					= b->text; // initialize


        #ifdef __MMI_INDIC_ALG__
        //Indic pointers should also run at new text buffer.
        {
            move_cursor_prev_p = b->text;
            move_cursor_curr_p = b->text;
            move_cursor_disp_prev_p = b->text;
            move_cursor_disp_curr_p = b->text;
        }
        #endif /* __MMI_INDIC_ALG__ */ 
    }
#endif /* defined (__MMI_ARSHAPING_ENGINE__)*/ 


    /* Current implementation does not support icon_callback on overwrite mode */
    MMI_DBG_ASSERT(!(flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE) || !b->icon_callback);

    /* Setup rich text context */
    rich_text.default_color = rich_text.curr_color = b->normal_text_color;
    /* USAT */
    rich_text.default_text_bg_color = rich_text.curr_text_bg_color = gui_richtext_default_text_bg_color;
    rich_text.draw_text_bg_color = 0;
    if (flags & UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY)
    {
        rich_text.default_alignment = GUI_INPUT_ALIGN_CENTER;
    }
    else if (flags & UI_MULTI_LINE_INPUT_BOX_RIGHT_JUSTIFY)
    {
        rich_text.default_alignment = GUI_INPUT_ALIGN_RIGHT;
    }
    else
    {
        rich_text.default_alignment = GUI_INPUT_ALIGN_LEFT;
    }
    rich_text.curr_alignment = rich_text.default_alignment;
    rich_text.line_begin_font = rich_text.curr_font = *b->text_font;
    rich_text.line_begin_border = rich_text.curr_border = 0;
    /* USAT */
    rich_text.line_begin_strikethrough = rich_text.curr_strikethrough = 0;
    rich_text.more_line_spacing = 0;
    rich_text.line_separator = 0;

    /* Setup runtime variables */
    current_cursor_p = b->cursor_p;  /* points to the character at which the cursor is positioned */
    previous_cursor_p = b->cursor_p;


    if (r2lMMIFlag)
    {
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        {
            x1 = b->x;
        }
        else if (b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        {
            if (b->vbar.scale < b->vbar.range)
            {
                x1 = b->x + b->vbar.width + 1;//hjf it should not  - 5;
            }
            else
            {
                x1 = b->x;
            }
        }
        else
        {
            x1 = b->x + b->vbar.width + 1;//hjf it should not - 5;
        }
    }
    else
    {
        x1 = b->x;
    }

    y1 = b->y;
    x2 = b->x + b->width - 1;   /* b->width contains the width of vbar */
    y2 = y1 + b->height - 1;
    edit_width = b->edit_width;
    edit_height = b->edit_height;
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }

#ifdef __MMI_INDIC_ALG__

    memset(disp_cluster, 0, sizeof(disp_cluster));
#endif 

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /*
     * Evertime the cursor position is changed, GUI will invoke the current function,
     * there is no other place to hook it cleanly.
     * However, it's protected by the flag UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE
     */
    if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE && gui_WCSS_input_method_change_enable())
    {
        /* gui_change_WCSS_input_method() will change cursor position */
        gui_change_WCSS_input_method(b);
        current_cursor_p = b->cursor_p;
        previous_cursor_p = b->cursor_p;
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ /* MMI_WCSS_INPUT_FORMAT_SUPPORT_ */
    /* Pixtel - Gurinder 2/4/6 - Use Auto Scrollbar if current multi line box is Inscreen */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU;
        l_clip = y2 - (MMI_content_height + MMI_content_y - 1);

        if (l_clip < 0)
        {
            l_clip = 0;
        }
    }
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* If not disable draw then do it.. */
    {
        UI_filled_area f;
        S32 l_height = 0;

        if (flags & UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED)
        {
            f = *b->focussed_filler;
            rich_text.default_color = rich_text.curr_color = b->focussed_text_color;
        }
        else if (flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED)
        {
            f = *b->disabled_filler;
            rich_text.default_color = rich_text.curr_color = b->disabled_text_color;
        }
        else
        {
            f = *b->normal_filler;
            rich_text.default_color = rich_text.curr_color = b->normal_text_color;
        }

        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR)
        {
           f.c = b->default_bg_color;
        }

    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        if (MMI_multi_line_inputbox_present == 1)
        {
            /* Inline Multiline Edit Infobar Height Change. - Gurinder - 12/5/2004 */
            l_height = INFORMATION_BAR_HEIGHT + 2;
            /* Gurinder 7/14/2004 - Inscreen Multiline Title Enable/Disable */
        #if(!INSCREEN_MUTLILINE_TITLE_ENABLE)
            if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
            {
                l_height = 0;
            }
        #endif /* (!INSCREEN_MUTLILINE_TITLE_ENABLE) */ 
        }
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

        gui_push_clip();
        if (flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
        {
            gui_set_clip_preset(b->x, y1 - l_height, x2 + 2, y2 + 2 - l_clip);
        }
        else
        {
            /* MTK Terry instead y2+1-l_clip with y2-l_clip for overlap soft key area */
            gui_set_clip(b->x, y1 - l_height, x2 + 2, y2 - l_clip);
        }

        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND))      /* if not disable background then do .. */
        {
            if(b->ext_flags & 
                (GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER 
                | GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER 
                | GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER))
            {
                /* If user set these flag, use the user setting instead of the theme setting */
                f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER))
                {
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_SINGLE_BORDER;
                    }
                    else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
                    }
                }
                
            }
                
            if (!(flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))   /* if not include info_area then do .. */
            {
                /* Draw standard background filler */
                /* 070405 Calvin Start */
                if (r2lMMIFlag)
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(b->x, y1 - l_height, x2 /* +b->vbar.width */ , y2, GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(b->x, y1 - l_height, x2 /* +b->vbar.width */ , y2, &f);
                    }
                }
                else
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(x1, y1 - l_height, x2, y2, GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(x1, y1 - l_height, x2, y2, &f);
                    }
                }
                /* 070405 Calvin End */

                /*
                 * Draw b->text_filler for text area only.
                 * (typically when b->header_height or b->footer_callback is non-zero)
                 */
                if (b->text_filler)
                {
                    /*
                     * This filler can only be used in View Mode such that b->text_height can be pre-computed
                     * * at the first time in something like show_multiline_inputbox_no_draw().
                     */

                    S32 text_border_y1, text_border_y2;

                    MMI_DBG_ASSERT((flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) != 0 && l_clip == 0);

                    text_border_y1 = y1 + b->text_y + b->text_offset_y + b->header_height - 1;
                    text_border_y2 = y1 + b->text_y + b->text_offset_y + b->text_height - b->footer_height;

                    /* If text_height is large, we should shrink the filling area */
                    if (text_border_y1 < 0)
                    {
                        text_border_y1 = 0;
                    }
                    if (text_border_y2 >= UI_device_height)
                    {
                        text_border_y2 = UI_device_height - 1;
                    }

                    gui_push_clip();
                    if ((f.flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
                    {
                        gui_set_clip(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
                    }
                    else if (f.flags & UI_FILLED_AREA_BORDER)
                    {
                        gui_set_clip(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                    }
                    gui_draw_filled_area(
                        x1 + b->text_x + b->text_offset_x - 1,
                        text_border_y1,
                        x1 + b->text_x + b->text_offset_x + b->edit_width,
                        text_border_y2,
                        b->text_filler);
                    gui_pop_clip();
                }
            }
            else    /* if including info_area then do .. */
            {
                gui_set_clip(b->x, y1 - wgui_inputbox_information_bar_height - l_height, x2, y2 - l_clip);
                f.flags = UI_FILLED_AREA_TYPE_BITMAP;
                f.b = get_image(WGUI_VOLUME_LEVEL1);    /* test */

                /* 070405 Calvin Start */
                if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                    (flags & UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND))
                {
                    gdi_draw_solid_rect(
                        b->x,
                        y1 - wgui_inputbox_information_bar_height - l_height,
                        x2,
                        y2,
                        GDI_COLOR_TRANSPARENT);
                }
                else
                {
                    gui_draw_filled_area(b->x, y1 - wgui_inputbox_information_bar_height - l_height, x2, y2, &f);
                }
                /* 070405 Calvin End */

                if (r2lMMIFlag)
                {
                    gui_draw_rectangle(b->x, y1 - l_height, x2 /* +b->vbar.width */ , y2, b->boundary_color);
                }
                else
                {
                    gui_draw_rectangle(x1, y1 - l_height, x2, y2, b->boundary_color);
                }

                if (flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
                {
                    gui_set_clip_preset(x1, y1 - l_height, x2 + 2, y2 + 2 - l_clip);
                }
                else
                {
                    gui_set_clip(x1, y1 - l_height, x2 + 2, y2 + 2 - l_clip);
                }
            }
        }

    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
        if (MMI_multi_line_inputbox_present)
        {
            /* Gurinder 6/5/2004 - Show Information Bar / Caption String */
            if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                //Show Information Bar
                //START TARUN PMT 20040927  ADDED : Check the flag before redrawing the info bar
                if (wgui_inputbox_information_flag)
                {
                    wgui_redraw_input_information_bar();
                }
                /* END TARUN PMT 20040927 */
            }
        #if(INSCREEN_MUTLILINE_TITLE_ENABLE)
            /* Gurinder 7/14/2004 - Inscreen Multiline Title Enable/Disable */
            else
            {
                /* Show Signature Text.... */
                gui_draw_inscreen_multi_line_input_box_title(x1, y1 - l_height + 1, x2 - 2, y1 - 1);
            }
        #endif /* (INSCREEN_MUTLILINE_TITLE_ENABLE) */ 
        }
    #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
    }

#ifdef __MMI_BIDI_ALG__
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && (((b->text_length >> 1) - 1) != 0))
    {
        for (iCount = 0; iCount < (U32) ((b->text_length >> 1) - 1); iCount++)
        {
            bidi_get_char_type((U8*) (b->text + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
            if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
            {
                arabic_char_flag = MMI_TRUE;
                break;
            }
        }


        bidi_get_char_type(b->text, (U8*) & default_direction);
#ifdef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR
        if (arabic_char_flag)
#else
        if (default_direction == BIDI_R || default_direction == AL|| default_direction == AN)
#endif
        {
            default_direction = BIDI_R;
        }
        else
        {
            default_direction = BIDI_L;
        }


        if (arabic_char_flag)
        {
            /* 
             * Tricky: icon is not supported in Arabic because text order is rearranged.
             * Set icon_callback to NULL to disable icon in cursor movement, delete character, and display.
             * Otherwise, we have to modify BIDI to support 'icon_callback'.
             */
            b->icon_callback = NULL;
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    //hjf recalculate the x boundary
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)&& !r2lMMIFlag)
    {
        if (flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        {
            if ((b->vbar.scale < b->vbar.range))
                x2 -= b->vbar.width;
        }
        else
            x2 -= b->vbar.width;
    }

    x2 -= b->text_x2_gap_width;
    edit_width = (x2 - x1 - b->text_x);

    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
    {
        edit_width -= 2;
    }
    else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
    {
        edit_width -= 4;
    }

    b->edit_width = edit_width;

    if (b->text != NULL)
    {

    #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
        {
            switch (b->font_style)
            {
                case FONT_DEFAULT:
                    rich_text.curr_font.italic = rich_text.curr_font.bold = 0;
                    break;
                case FONT_BOLD:
                    rich_text.curr_font.bold = 1;
                    rich_text.curr_font.italic = 0;
                    break;
                case FONT_ITALIC:
                    rich_text.curr_font.italic = 1;
                    rich_text.curr_font.bold = 0;
                    break;
            }
        }
    #endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
        gui_set_font(&rich_text.curr_font); /* set text font */
        previous2_line_height = previous_line_height = character_height = gui_get_character_height();
        if (b->min_line_height > previous_line_height)
        {
            previous_line_height = character_height = b->min_line_height;
        }

        if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
        {
            gui_measure_character(b->mask_character, &mask_character_width, &mask_character_height);
        }

        /* Setup clipping for text and icon */
        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* if not disable draw then do ... */
        {
            UI_filled_area f;
            S32 clip_x1, clip_y1, clip_x2, clip_y2;
            U32 chk_flags;

            if (flags & UI_MULTI_LINE_INPUT_BOX_STATE_FOCUSSED)
            {
                f = *b->focussed_filler;
            }
            else if (flags & UI_MULTI_LINE_INPUT_BOX_STATE_DISABLED)
            {
                f = *b->disabled_filler;
            }
            else
            {
                f = *b->normal_filler;
            }

            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR)
            {
                f.c = b->default_bg_color;
            }

            if(b->ext_flags & 
                (GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER 
                | GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER 
                | GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER))
            {
                /* If user set these flag, use the user setting instead of the theme setting */
                f.flags &= ~(UI_FILLED_AREA_SINGLE_BORDER | UI_FILLED_AREA_DOUBLE_BORDER);
                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_NONE_BORDER))
                {
                    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SINGLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_SINGLE_BORDER;
                    }
                    else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DOUBLE_BORDER)
                    {
                        f.flags |= UI_FILLED_AREA_DOUBLE_BORDER;
                    }
                }
            }
            chk_flags = f.flags;

            /* Clipping is poped after the editor has finished drawing */
            gui_push_text_clip();
            gui_push_clip();

            if ((chk_flags & UI_FILLED_AREA_DOUBLE_BORDER) == UI_FILLED_AREA_DOUBLE_BORDER)
            {
                border_y = 2;
                clip_x1 = x1 + 2;
                clip_y1 = y1 + 2;
                clip_x2 = x2 - 2;
                clip_y2 = y2 - ((l_clip > 2) ? l_clip : 2);
            }
            else if (chk_flags & UI_FILLED_AREA_BORDER)
            {
                border_y = 1;
                clip_x1 = x1 + 1;
                clip_y1 = y1 + 1;
                clip_x2 = x2 - 1;
                clip_y2 = y2 - ((l_clip > 1) ? l_clip : 1);
            }
            else
            {
                border_y = 0;
                clip_x1 = x1;
                clip_y1 = y1;
                clip_x2 = x2;
                clip_y2 = y2 - l_clip;
            }

            clip_y1 += b->text_y;

            if (flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
            {
                gui_set_text_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
                gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
            }
            else
            {
                gui_set_text_clip(clip_x1, clip_y1, clip_x2, clip_y2);
                gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
            }
            edit_height = b->edit_height = clip_y2 - clip_y1;
        }


        if (previous_cursor_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(previous_cursor_p, dummy_c);
        }
        previous_line_start_text_p = line_start_text_p = b->text;
        if (flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
        #ifdef __MMI_BIDI_ALG__
            if (arabic_char_flag)
            {
                multitap_flag = 0;
            }
            else
        #endif /* __MMI_BIDI_ALG__ */ 
                multitap_flag = 1;
        }
        if (flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            overwrite_flag = 1;
        }
        xx = x1 + b->text_x + b->text_offset_x;
        yy = y1 + b->text_y + b->text_offset_y + border_y;
        ty = b->header_height + b->header_gap;       /* 1: gap between header and text content */
        b->max_line_height = 0;

        if (move_to_y < yy + ty)
        {
            /* pointed at the header , ignore it */
            move_to_y = -1;
            move_to_x = -1;
        }

    #if defined(__MMI_LANG_VIETNAMESE__)
        /* W05.38 Fix Viet Tone Cursor Moving Issue */
        /* MTI START MAUI_00048270 */
        if ((((b->text_length >> 1) - 1) != 0))
        /* MTI END MAUI_00048270 */ 
        {
            UI_buffer_type temp_cursor_p = b->cursor_p;
            UI_character_type temp_tone, temp_vowel;

            UI_STRING_GET_NEXT_CHARACTER(temp_cursor_p, temp_tone);
            if ((temp_tone >= 0x0300) && (temp_tone <= 0x0323))
            {
                temp_cursor_p = b->cursor_p;
                UI_STRING_GET_PREVIOUS_CHARACTER(temp_cursor_p, temp_vowel);    /* get next character */
                viet_vowel = mmi_viet_vowel_letter(temp_vowel);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    tone_mark = mmi_viet_tone_mark(temp_tone);
                    if (VIET_TONE_NONE != tone_mark)
                    {
                        dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                    }
                }
            }
        }
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

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
/* under construction !*/
#endif
        ///////////// MULTILINE BIG LOOP BEGIN ////////////////////////////////
        ///////////// MULTILINE BIG LOOP BEGIN ////////////////////////////////
        ///////////// MULTILINE BIG LOOP BEGIN ////////////////////////////////
        while (!done && (edit_width >= 0))   // 
        {

        #ifdef __MMI_INDIC_ALG__
            S32 idx = 0;
        #endif 

            gui_set_font(&rich_text.curr_font);
            // Restore the text_gap and line spacing
            rich_text.more_line_spacing = 0;
            rich_text.line_separator = 0;

            previous_line_width = current_line_width = 0;
            current_cluster_width = 0;

        #ifdef __MMI_INDIC_ALG__
            cluster_filler_count = 0;
        #endif 
            if (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
                previous_line_height = current_line_height = gui_get_character_height() + 2;
            else
            previous_line_height = current_line_height = gui_get_character_height() + 1;
            if (b->min_line_height > current_line_height)
            {
                previous_line_height = current_line_height = b->min_line_height;
            }
            current_line_character_counter = 0;
            current_line_break_character_counter = 0;

            /* MTK for Chinese Characters Display */
            break_flag = 0;
            

            previous_text_p = line_break_text_p = current_text_p = line_start_text_p;

        #ifdef __MMI_INDIC_ALG__

            move_cursor_prev_p = line_start_text_p; /* TARUN 20041122 */
        #endif 
            draw_separator = FALSE;

            /*
             * Backup the font at the beginning of line
             * Alignment is setup in the first pass only, and color is set in the second pass only.
             */
            rich_text.line_begin_font = rich_text.curr_font;
            rich_text.line_begin_border = rich_text.curr_border;
            rich_text.line_begin_strikethrough = rich_text.curr_strikethrough;

            ///////////// BEGIN OF FIRST PASS LOOP  (P1BEGIN) ////////////////////////////////
            ///////////// BEGIN OF FIRST PASS LOOP  (P1BEGIN) ////////////////////////////////
            ///////////// BEGIN OF FIRST PASS LOOP  (P1BEGIN) ////////////////////////////////
            {
                S32 P1_char_cnt_for_control_seq = 0;    // number of characters consumed by b->icon_callback
                S32 P1_skip_moves = 1;                  // for skipping by cluster
                S32 P1_text_gap = 0; // the gap between current object and previous object
                
                while (current_line_width < (edit_width - 1) 
                && current_line_character_counter< 128 ) // because EMS_object_height_cache[128]
                {
                    U8  P1_break_character_flag; // current object is a word split symbol


#if defined (__MMI_BIDI_ALG__) && defined (__MMI_INDIC_ALG__)
                    indic_bidi_flag =0;
#endif
                    #if defined (__MMI_LANG_VIETNAMESE__) && defined (__MMI_INDIC_ALG__) 
                    vietnamese_indic_flag = 0;
                    #endif
                    previous_text_p = current_text_p;
                    gui_set_font(&rich_text.curr_font); //hjf, set font for measure_char bug

                    /* GET NEXT CHARACTER with skip cluster*/
                    #ifdef __MMI_INDIC_ALG__
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_multi_line_input_box:[skip_moves] :%d",P1_skip_moves);
                    while (P1_skip_moves--)
                    #endif /* __MMI_INDIC_ALG__ */ 
                    {
                        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
                    }

                    // process text_gap between characters
                    {
                        P1_text_gap = b->text_gap;

                        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                        if (IS_ARABIC_CHARACTER(current_character) && IS_ARABIC_CHARACTER(pre_character))
                            P1_text_gap = 0;
                        #endif
                    }


                    P1_skip_moves = 1; // default cluster count is 1

                    #if defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__)
                    if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
                    {
                        if ((flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) && (previous_text_p == previous_cursor_p))
                        {
                            gui_measure_character(current_character, &mask_character_width, &mask_character_height);
                        }
                        else
                        {
                            gui_measure_character(b->mask_character, &mask_character_width, &mask_character_height);
                        }
                    }
                    #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__) */ 

                #if defined(__MMI_LANG_VIETNAMESE__)
                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);      /* get next character */
                        tone_mark = mmi_viet_tone_mark(dummy_c);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                            viet_vowel = mmi_viet_vowel_letter(current_character);
                            if (VIET_VOWEL_NONE != viet_vowel)
                            {
                                current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                                #if defined (__MMI_INDIC_ALG__) 
                                vietnamese_indic_flag = 1;
                                #endif
                            }
                            else
                            {
                                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                            }
                        }
                        else
                        {
                            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                        }
                    }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

                    if ((flags & UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR) && UI_TEST_ESC_CHARACTER(current_character))
                    {

                        current_cluster_width = 0;
                    #ifdef __MMI_BIDI_ALG__
                        if (arabic_char_flag)
                        {
                            character_height = gui_get_character_height() + 3;
                        }
                        else
                    #endif /* __MMI_BIDI_ALG__ */ 
                            character_height = gui_get_character_height() + 2;      /* reserve one more pixel */
                        draw_separator = TRUE;
                    }
                    else
                #if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                    if (UI_TEST_CR_CHARACTER(current_character) ||
                        UI_TEST_LF_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character))
                    {
                        current_cluster_width = 10; 
                        character_height = 10;
                    }
                    else
                    {
                #endif /* (MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS) */ 
                    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
                        if (UI_TEST_CR_CHARACTER(current_character) && UI_TEST_LF_CHARACTER(*current_text_p))
                        {
                            current_cluster_width = 0;  
                            character_height = gui_get_character_height();

                        }
                        else
                    #endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
                        if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
                        {
                            current_cluster_width = mask_character_width;  
                            character_height = mask_character_height;
                        }
                        else if (P1_char_cnt_for_control_seq > 0)
                        {
                            P1_text_gap = 0;
                            current_cluster_width = 0;
    	                    character_height = character_heights_cache[current_line_character_counter-1]; // reuse last char's height
                        }
                        else if ((flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character))
                        {
                            BOOL change_font = MMI_FALSE;

                            P1_text_gap = 0;
                            current_cluster_width = 0;
                            /* We do not want to assign 'current_line_height' because we might change to small font */
                            character_height = 1;

                            switch (current_character)
                            {
                                case GUI_INPUT_MARKER_RESET_ALL:
                                    /* Reset font format and alignment (no color) */
                                    rich_text.curr_alignment = rich_text.default_alignment;
                                    rich_text.curr_font = *b->text_font;
                                    rich_text.curr_border = 0;
                                    /* USAT */
                                    rich_text.curr_strikethrough = 0;
                                    rich_text.more_line_spacing = 0;
                                    rich_text.line_separator = 0;
                                    change_font = MMI_TRUE;
                                    break;

                                case GUI_INPUT_MARKER_RESET_PARAGRAPH:
                                    rich_text.curr_alignment = rich_text.default_alignment;
                                    rich_text.more_line_spacing = 0;
                                    rich_text.line_separator = 0;
                                    break;

                                case GUI_INPUT_MARKER_RESET_FORMAT:
                                    rich_text.curr_font = *b->text_font;
                                    rich_text.curr_border = 0;
                                    /* USAT */
                                    rich_text.curr_strikethrough = 0;
                                    change_font = MMI_TRUE;
                                    break;

                                case GUI_INPUT_MARKER_RESET_COLOR:
                                    /* Do not change color because characters is not drawn in the first pass */
                                    break;

                                default:
                                    /* UAT */
                                    if ((current_character >= GUI_INPUT_MARKER_W3C_COLOR_BEGIN &&
                                         current_character <= GUI_INPUT_MARKER_W3C_COLOR_END) ||
                                        (current_character >= GUI_INPUT_MARKER_COLOR_BEGIN &&
                                         current_character <= GUI_INPUT_MARKER_COLOR_END) ||
                                        (current_character >= GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN &&
                                         current_character <= GUI_INPUT_MARKER_W3C_BORDER_COLOR_END) ||
                                        (current_character >= GUI_INPUT_MARKER_BORDER_COLOR_BEGIN &&
                                         current_character <= GUI_INPUT_MARKER_BORDER_COLOR_END) ||
                                        (current_character >= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN &&
                                         current_character <= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_END))
                                    {
                                        /* Do not change color because characters is not drawn in the first pass */
                                    }
                                    else if (GUI_INPUT_IS_FORMAT_MARKER(current_character))
                                    {
                                        if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BOLD))
                                        {
                                            rich_text.curr_font.bold = 1;
                                            change_font = MMI_TRUE;
                                        }
                                        if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_ITALIC))
                                        {
                                            rich_text.curr_font.italic = 1;
                                            change_font = MMI_TRUE;
                                        }
                                        if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_UNDERLINE))
                                        {
                                            rich_text.curr_font.underline = 1;
                                            change_font = MMI_TRUE;
                                        }
                                        /* USAT */
                                        if (GUI_INPUT_CHECK_FORMAT_MARKER
                                            (current_character, GUI_INPUT_MARKER_STRIKETHROUGH))
                                        {
                                            rich_text.curr_strikethrough = 1;
                                        }
                                        if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BORDER))
                                        {
                                            /* We do not increase font size for bordered font because text gap is already enlarged */
                                            rich_text.curr_border = 1;
                                        }
                                        if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_SMALL))
                                        {
                                            rich_text.curr_font.size = SMALL_FONT;
                                            change_font = MMI_TRUE;
                                        }
                                        else if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_MEDIUM))
                                        {
                                            rich_text.curr_font.size = MEDIUM_FONT;
                                            change_font = MMI_TRUE;
                                        }
                                        else if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_LARGE))
                                        {
                                            rich_text.curr_font.size = LARGE_FONT;
                                            change_font = MMI_TRUE;
                                        }
                                    }
                                    else if (GUI_INPUT_IS_PARAGRAPH_MARKER(current_character))
                                    {
                                        if (GUI_INPUT_CHECK_ALIGN_MARKER(current_character, GUI_INPUT_MARKER_ALIGN_LEFT))
                                        {
                                            rich_text.curr_alignment = GUI_INPUT_ALIGN_LEFT;
                                        }
                                        else if (GUI_INPUT_CHECK_ALIGN_MARKER
                                                 (current_character, GUI_INPUT_MARKER_ALIGN_CENTER))
                                        {
                                            rich_text.curr_alignment = GUI_INPUT_ALIGN_CENTER;
                                        }
                                        else if (GUI_INPUT_CHECK_ALIGN_MARKER
                                                 (current_character, GUI_INPUT_MARKER_ALIGN_RIGHT))
                                        {
                                            rich_text.curr_alignment = GUI_INPUT_ALIGN_RIGHT;
                                        }

                                        if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                            (current_character, GUI_INPUT_MARKER_LINE_SPACING_1))
                                        {
                                            rich_text.more_line_spacing = 1;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_2))
                                        {
                                            rich_text.more_line_spacing = 2;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_3))
                                        {
                                            rich_text.more_line_spacing = 3;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_4))
                                        {
                                            rich_text.more_line_spacing = 4;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_5))
                                        {
                                            rich_text.more_line_spacing = 5;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_6))
                                        {
                                            rich_text.more_line_spacing = 6;
                                        }
                                        else if (GUI_INPUT_CHECK_LINE_SPACING_MARKER
                                                 (current_character, GUI_INPUT_MARKER_LINE_SPACING_7))
                                        {
                                            rich_text.more_line_spacing = 7;
                                        }

                                        if (GUI_INPUT_CHECK_PARAGRAPH_MARKER
                                            (current_character, GUI_INPUT_MARKER_LINE_SEPARATOR))
                                        {
                                            rich_text.line_separator = 1;
                                        }

                                        /* Reserve minimum line spacing for line separator */
                                        if (rich_text.line_separator && rich_text.more_line_spacing < 3)
                                        {
                                            rich_text.more_line_spacing = 3;
                                        }
                                    }

                                    break;
                            }

                            if (change_font)
                            {
                                gui_set_font(&rich_text.curr_font);
                            }
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00027731 */
                            move_cursor_curr_p = ire_get_next_cluster_p(move_cursor_prev_p, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
                            move_cursor_prev_p = move_cursor_curr_p;
#endif
                        }
/* PMT START MAUI_00028225 */
                        else if (b->icon_callback &&
                                 (P1_char_cnt_for_control_seq =
                                  b->icon_callback(
#if defined(__MMI_INDIC_ALG__)
	                                   move_cursor_prev_p,
#else
                                        previous_text_p,
#endif
                                        MMI_FALSE,
                                        &current_cluster_width,
                                        &character_height,
                                        0,
                                        0)) > 0)
/* PMT END MAUI_00028225 */
                        {
                            #ifdef __MMI_INDIC_ALG__
                            move_cursor_prev_p += P1_char_cnt_for_control_seq * 2;
                            #endif
                        }
                        else
                        {
                            gui_measure_character(current_character, &current_cluster_width, &character_height);

                            if (!RequireToMoveCursor(pre_character, current_character))
                            {
                                current_cluster_width = 0;
                            #ifdef __MMI_INDIC_ALG__
                                move_cursor_prev_p += 2;
                                #endif
                            }

                        #ifdef __MMI_INDIC_ALG__
                            else // if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                            {
                                /* Move pointer by the cluster width */
                                //Performance issue
/* PMT START MAUI_00027731 */
/* PMT START MAUI_00537445 */
                                if(IRE_INDIC_LANGUAGE_RANGE(current_character))
                                {
                                    move_cursor_curr_p = ire_get_next_cluster_p(move_cursor_prev_p, b->text + b->text_length-2);

                                }
                                else if(move_cursor_prev_p != b->text + b->text_length-2)
                                {
                                    move_cursor_curr_p=move_cursor_prev_p + 2 ;
                                }
/* PMT END MAUI_00537445 */
/* PMT END MAUI_00027731 */


                                P1_skip_moves = move_cursor_curr_p - move_cursor_prev_p;       /* Number of moves */
                                if (P1_skip_moves <= 0)    /* Not Required Now 20041228 */
                                    P1_skip_moves = 1; /* At least 1 */
                                else
                                    P1_skip_moves = P1_skip_moves >> 1;
                                #if defined (__MMI_LANG_VIETNAMESE__)
                                if(vietnamese_indic_flag)
                                {
                                    vietnamese_indic_flag =0;
                                    move_cursor_curr_p+= 2 ;
                                }
                                #endif 
/* PMT START MAUI_00537445 */
                                /* Calculate the width of current cluster as well as english character */
                               if(IRE_INDIC_LANGUAGE_RANGE(current_character)) 
                               {
                                   current_cluster_width = ire_size_of_current_cluster(move_cursor_prev_p, move_cursor_curr_p, 0);
                               }
/* PMT END MAUI_00537445 */
                                PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                                     "pixtel_UI_show_multi_line_input_box:[current_cluster_width] :%d",
                                                     current_cluster_width);

                                if (current_cluster_width + current_line_width >= edit_width)
                                {
                                    previous_text_p = move_cursor_prev_p;
                                }

                                move_cursor_prev_p = move_cursor_curr_p;

                                #if defined (__MMI_BIDI_ALG__)
                                if(indic_bidi_flag)
                                {
                                    move_cursor_prev_p = move_cursor_curr_p = current_text_p;
                                    indic_bidi_flag =0;

                                }
                                #endif

                            }

                        #endif /* __MMI_INDIC_ALG__ */ 

                        #ifdef __MMI_MESSAGES_CHAT__
                            if(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY)
                            {
                                if (UI_TEST_GRP_SEP_CHARACTER(current_character))
                                {
                                    gdi_image_get_dimension(
                                        (U8*) GetImage(CHAT_LOCAL_IMG),
                                        &current_cluster_width,
                                        &character_height);
                                    current_line_width += current_cluster_width;
                                }
                                else if (UI_TEST_FILE_SEP_CHARACTER(current_character))
                                {
                                    gdi_image_get_dimension(
                                        (U8*) GetImage(CHAT_REMOTE_IMG),
                                        &current_cluster_width,
                                        &character_height);
                                    current_line_width += current_cluster_width;
                                }
                                else if (UI_TEST_SENDER_TRUNCATE_SEP_CHARACTER(current_character))
                                {
                                    gdi_image_get_dimension(
                                        (U8*) GetImage(CHAT_SENDER_TRUNCATE_IMG),
                                        &current_cluster_width,
                                        &character_height);
                                    current_line_width += current_cluster_width;
                                }
                                else if (UI_TEST_RECEIVER_TRUNCATE_SEP_CHARACTER(current_character))
                                {
                                    gdi_image_get_dimension(
                                        (U8*) GetImage(CHAT_RECEIVER_TRUNCATE_IMG),
                                        &current_cluster_width,
                                        &character_height);
                                    current_line_width += current_cluster_width;
                                }
                            }
                        #endif /* __MMI_MESSAGES_CHAT__ */ 

                        }

                        if (UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character))
                        {
                            current_cluster_width = 0;
                        }
                    #if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                    }
                    #endif 


                    if (UI_STRING_END_OF_STRING_CHARACTER(current_character) ||
                        UI_STRING_LINE_BREAK_CHARACTER(current_character))
                    {
                        current_cluster_width = 0;
                    }
                #ifdef __MMI_INDIC_ALG__
                    if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) && !(UI_STRING_END_OF_STRING_CHARACTER(current_character)))       /* bakshi */
                #endif 
                    {
                        character_widths_cache[current_line_character_counter] = (U8) current_cluster_width;        /* TARUN 20041122 */
                        character_heights_cache[current_line_character_counter] = (U8) character_height;
                    }
                    if (RequireToMoveCursor(pre_character, current_character))
                    {
                        #ifdef __MMI_INDIC_ALG__
                        /* To stop the unwanted text to be added in cuurent_line_width */
                        if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
                        {
                            /* Calculate the width for the whole string as well as single english char */
                            if (current_cluster_width != 0)
                            {
                                current_line_width += current_cluster_width + P1_text_gap;
                            }
                        }
                        else
                        {
                            current_line_width += P1_text_gap * 2; //hjf? why ?
                        }
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "gui_show_multi_line_input_box:[current_line_width] :%d",
                                             current_line_width);
                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) && P1_skip_moves>0)
                        {
                            S32 saved_skip_moves = P1_skip_moves;
                            hindi_cluster_counter = current_line_character_counter;
                            while (saved_skip_moves--)
                            {
                                character_widths_cache[hindi_cluster_counter] = 0;
                                character_heights_cache[hindi_cluster_counter] = (U8) character_height;
                                hindi_cluster_counter++;
                            }
                            cluster_width_filler[cluster_filler_count] = current_cluster_width;
                        }
                        #else /* __MMI_INDIC_ALG__ */ 
                        if (current_cluster_width != 0)
                        {
                            current_line_width += current_cluster_width + P1_text_gap;
                        }
                        /* MTK Terry for cursor overlap scroll bar */
                        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
                        {
                            current_line_width += P1_text_gap;
                        }
                        #endif /* __MMI_INDIC_ALG__ */ 
                    }
                    else
                    {
                        current_line_width += current_cluster_width /* +P1_text_gap */ ;
                    }
                    pre2_character = pre_character;
                    pre_character = current_character;
                #ifdef __MMI_INDIC_ALG__
                    current_line_character_counter += P1_skip_moves;
                    cluster_filler_count++;
                #else /* __MMI_INDIC_ALG__ */ 
                    current_line_character_counter++;
                #endif /* __MMI_INDIC_ALG__ */ 

                    if (P1_char_cnt_for_control_seq == 0 && !(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_WRAPPING_BY_WORD))
                    {
                        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, P1_break_character_flag);
                    }
                    else
                    {
                        P1_break_character_flag = 0;
                    }
                    /* MTK Terry For the last character of the line is 0x20 and the cursor moving will be incorrect */
                    if ((!P1_break_character_flag || current_character == 0x20) && (current_line_width > edit_width - 1))
                    {
                        /* Get rid of infinite loop If editor width is smaller than one character. */
                        if (current_line_character_counter == 1)
                        {
                            done = 1;
                        }
                        break;
                    }
                    saved_line_height = current_line_height;

    			    // character height + 1 if bigger then current line height
                    if((character_height + rich_text.more_line_spacing +reserve_line_height_for_hilite + 1) > current_line_height)
                    {
                        current_line_height = character_height + rich_text.more_line_spacing + reserve_line_height_for_hilite +1;
                    }
                    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
                    {
                        current_line_break_character_counter = current_line_character_counter;
                        line_break_text_p = current_text_p;
                        b->last_position_p = current_text_p;
                        previous_line_width = current_line_width - current_cluster_width - P1_text_gap;
                        previous_line_height = saved_line_height;
                        done = 1;
                        break;
                    }
                    else if (UI_STRING_LINE_BREAK_CHARACTER(current_character))
                    {
                        current_line_break_character_counter = current_line_character_counter;
                        line_break_text_p = current_text_p;
                        previous_line_width = current_line_width - current_cluster_width - P1_text_gap;
                        previous_line_height = saved_line_height;
                        break;
                    }
                    else
                    {
                        if (P1_break_character_flag)
                        {
                            current_line_break_character_counter = current_line_character_counter;
                            line_break_text_p = current_text_p;
                            if (UI_MULTI_LINE_INPUT_BOX_SPACE_CHARACTER(current_character))
                            {
                                previous_line_width = current_line_width - current_cluster_width - P1_text_gap;
                                previous_line_height = saved_line_height;
                                break_flag = 1;
                            }
                            else
                            {
                                previous_line_width = current_line_width;
                                previous_line_height = current_line_height;
                            }
                        }
                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #else
                        if (!UI_MULTI_LINE_INPUT_BOX_ALPHABETIC_CHARACTER(current_character) &&
                            !((flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character)) &&
                            (1 == break_flag))
                    #endif
                        {
                            current_line_break_character_counter = 0;
                        }
                        
                    }

                    if (P1_char_cnt_for_control_seq > 0)
                        P1_char_cnt_for_control_seq--;
                    
                }

                
                if ((current_line_break_character_counter == 0) && (current_line_character_counter > 0))
                {
                    if(!(UI_STRING_END_OF_STRING_CHARACTER(current_character)))
                    {
                #ifdef __MMI_INDIC_ALG__
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_multi_line_input_box:NEW LINE  ");
                    current_line_break_character_counter = current_line_character_counter - P1_skip_moves;
                #else /* __MMI_INDIC_ALG__ */ 
                    current_line_break_character_counter = current_line_character_counter - 1;
                #endif /* __MMI_INDIC_ALG__ */ 
                    }
                    else
                    {
                        current_line_break_character_counter = current_line_character_counter;
                    }

                    if (current_line_break_character_counter <= 0)
                        current_line_break_character_counter = 1;

                    line_break_text_p = previous_text_p;
                    previous_line_width = current_line_width - current_cluster_width - P1_text_gap;
                    previous_line_height = saved_line_height;
                }

            }
            ///////////// END OF FIRST PASS LOOP  (P1END) ////////////////////////////////
            ///////////// END OF FIRST PASS LOOP  (P1END) ////////////////////////////////
            ///////////// END OF FIRST PASS LOOP  (P1END) ////////////////////////////////


            /* Second pass. Display the entire line            */
            pre2_character = 0;
            pre_character = 0;
        #ifdef __MMI_INDIC_ALG__
            cluster_filler_count = 0;
            b->last_position_p = current_text_p;
        #endif /* __MMI_INDIC_ALG__ */ 
            current_line_character_counter = 0;

            current_text_p = line_start_text_p;
            current_line_height = previous_line_height;
            tx = 0;

            /* Restore the font at the beginning of line  */
            rich_text.curr_font = rich_text.line_begin_font;
            rich_text.curr_border = rich_text.line_begin_border;
            
            /* USAT */
            rich_text.curr_strikethrough = rich_text.line_begin_strikethrough;
            gui_set_font(&rich_text.curr_font);

            //for page height concept from here
            #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
            {

                /** to determine the height of the currently displayed window.if condition is taken here to get the current **/
                if (total_page_height + b->header_gap + b->header_height>= -(b->text_offset_y) && (total_page_height + b->header_gap + b->header_height< (-(b->text_offset_y) + edit_height))
                    && b->edit_height_displayed_lines + current_line_height <= edit_height)
                {

                    if (total_page_height + b->header_gap + b->header_height== -b->text_offset_y)
                    {
                        if (b->text_offset_y == -(b->header_gap + b->header_height))
                        {
                            b->text_offset = 0; /* text_count :offset of the character where text_offset_y is currently pointing.char_count variable is needed when application exit. */
                        }
                        else
                        {
                            b->text_offset = char_count;
                        }
                    }
                    if (total_page_height + b->header_gap + b->header_height> -b->text_offset_y &&
                        total_page_height + b->header_gap + b->header_height - (-b->text_offset_y) < previous2_line_height)
                    {
                        b->text_offset = char_count;
                    }

                    total_page_height += current_line_height;
                    b->edit_height_displayed_lines += current_line_height;
                }
                else
                {
                    total_page_height += current_line_height;
                }
                char_count += current_line_break_character_counter;     /* for every line ,char_count is incermented by the no of containing in that line */
                previous2_line_height = current_line_height;

                /* if concerned application wants to show the text from the particular offset then this offset value is copied into 
                   page_offset element of the multiline structure.According to this text_offset_y is calculated.This page_offset is compared against char_count to get text_offset_y */
                if (b->page_offset >= char_count || b->jump_offset_from_app >= char_count)
                {
                    if (b->text_offset_y == b->header_height)
                        b->text_offset_y -= b->header_gap;    /*for 1 gap between header and text content*/

                    b->text_offset_y -= current_line_height;
                    b->text_offset = char_count;
                    b->edit_height_displayed_lines = 0;
                }
                else if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR
                         && (ty + b->text_offset_y + current_line_height > 0)
                         &&locate_cursor == 0)
                {
                    b->cursor_p = line_start_text_p;
                    locate_cursor = 1;
                }
                
                /*
                if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_SEARCH_WORD
                    && (ty + b->text_offset_y> 0)
                    &&first_text_display == 0)
                {
                    if (b->displayed_text_callback != NULL)
                        b->displayed_text_callback(line_start_text_p, b->text_length - (line_start_text_p - b->text));
                    first_text_display = 1;    
                }
                */
                
                /*
                 * this condition is tested for the 1st page.
                 * "b->previous_shared_bytes" is considered to be the part of the page at 0th index in the buffer.it is needed to maintain the height of page 
                 * available in the buffer.height of page is also dependent on the shared_bytes with next or previous page.
                 * In case of next page entry,the page at 0th index will be out from the buffer and the page next to the removed one will come to 0th index and so on
                 * 
                 * check_flag: check_flag is needed to prevent the body of every if should be executed once.
                 * 
                 * page_size=512 bytes.if char_count>=512 then it should go through the if condition and set the check_flag to 1. 
                 */
                if (char_count >= (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH)) && check_flag == 0)
                {
                    /* if shared bytes is zero. previous_shared_bytes is the bytes which is shared between page at 0th and 1st index in the buffer** */
                    if ((shared_data_count =
                         char_count % (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH))) == 0)
                    {
                        b->page_details[PAGE_ZERO].page_id = b->start_id;
                        b->page_details[PAGE_ZERO].page_height = total_page_height;
                        b->page_details[PAGE_ZERO].shared_no_of_bytes = 0;

                    }
                    else
                    {
                        memcpy(
                            b->page_details[PAGE_ZERO].shared_data,
                            b->text + (GUI_PAGE_SIZE + (b->previous_shared_bytes / ENCODING_LENGTH) - current_line_break_character_counter + shared_data_count) * ENCODING_LENGTH,
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH);
                        b->page_details[PAGE_ZERO].page_id = b->start_id;
                        b->page_details[PAGE_ZERO].page_height = total_page_height - current_line_height;
                        b->page_details[PAGE_ZERO].shared_no_of_bytes =
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH;
                    }
                    check_flag = 1;
                }
                /*
                 * 2nd page details calculation:
                 * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*2 then it should go through the if condition and set the check_flag to 2. 
                 */
                else if (char_count >= GUI_PAGE_SIZE * 2 && check_flag == 1)
                {
                    if ((shared_data_count = char_count % (GUI_PAGE_SIZE * 2)) == 0)
                    {
                        b->page_details[PAGE_ONE].page_id = b->start_id + 1;
                        b->page_details[PAGE_ONE].page_height =
                            total_page_height - b->page_details[PAGE_ZERO].page_height;
                        b->page_details[PAGE_ONE].shared_no_of_bytes = 0;
                    }
                    else
                    {
                        memcpy(
                            b->page_details[PAGE_ONE].shared_data,
                            b->text + ((GUI_PAGE_SIZE * 2) - current_line_break_character_counter + shared_data_count) * ENCODING_LENGTH,
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH);
                        b->page_details[PAGE_ONE].page_id = b->start_id + 1;
                        b->page_details[PAGE_ONE].page_height =
                            total_page_height - b->page_details[PAGE_ZERO].page_height - current_line_height;
                        b->page_details[PAGE_ONE].shared_no_of_bytes =
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH;
                    }
                    check_flag = 2;
                }
                /*
                 * 3rd page details calculation: 
                 * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*3 then it should go through the if condition and set the check_flag to 3. 
                 */
                else if (char_count >= GUI_PAGE_SIZE * 3 && check_flag == 2)
                {
                    if ((shared_data_count = char_count % (GUI_PAGE_SIZE * 3)) == 0)
                    {
                        b->page_details[PAGE_TWO].page_id = b->start_id + 2;
                        b->page_details[PAGE_TWO].page_height =
                            total_page_height - b->page_details[PAGE_ONE].page_height -
                            b->page_details[PAGE_ZERO].page_height;
                        b->page_details[PAGE_TWO].shared_no_of_bytes = 0;
                    }
                    else
                    {
                        memcpy(
                            b->page_details[PAGE_TWO].shared_data,
                            b->text + ((GUI_PAGE_SIZE * 3) - current_line_break_character_counter + shared_data_count) * ENCODING_LENGTH,
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH);
                        b->page_details[PAGE_TWO].page_id = b->start_id + 2;
                        b->page_details[PAGE_TWO].page_height =
                            total_page_height - b->page_details[page_index + 1].page_height -
                            b->page_details[page_index + 0].page_height + current_line_height;
                        b->page_details[PAGE_TWO].shared_no_of_bytes =
                            (current_line_break_character_counter - shared_data_count) * ENCODING_LENGTH;
                    }
                    check_flag = 3;
                }
                /*
                 * 4th page details calculation: 
                 * GUI_PAGE_SIZE=512 bytes.if char_count>=GUI_PAGE_SIZE*4 then it should go through the if coditon. 
                 */
                else if ((char_count >= GUI_PAGE_SIZE * 4 /* && count_flag==0 */ ) && check_flag == 3)
                {
                    /* count_flag=1; */
                    b->page_details[PAGE_THREE].shared_no_of_bytes = 0;
                    b->page_details[PAGE_THREE].page_id = b->start_id + 3;
                    b->page_details[PAGE_THREE].page_height =
                        total_page_height - b->page_details[page_index + PAGE_TWO].page_height -
                        b->page_details[page_index + PAGE_ONE].page_height - b->page_details[page_index +
                                                                                             PAGE_ZERO].page_height;
                    check_flag = 4;
                }
            }
            #endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 

            if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
            {
                if (rich_text.curr_alignment == GUI_INPUT_ALIGN_CENTER)
                {
                    temp_text_p = current_text_p;
                    UI_STRING_GET_NEXT_CHARACTER(temp_text_p, current_character);
                    
                    #if defined(__MMI_LANG_VIETNAMESE__)
                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        //next_unicode = String[2];
                        //next_unicode |= (String[3]<<8);
                        UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);  /* get next character */
                        tone_mark = mmi_viet_tone_mark(dummy_c);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                            viet_vowel = mmi_viet_vowel_letter(current_character);
                            if (VIET_VOWEL_NONE != viet_vowel)
                            {
                                current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                            }
                            else
                            {
                                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                            }
                        }
                        else
                        {
                            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                        }
                    }
                    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

                    if (UI_MULTI_LINE_INPUT_BOX_SPACE_CHARACTER(current_character))
                    {
                        /* MTK Terry for Center Align when the beginning of the line is space */
                        //previous_line_width-=(character_widths_cache[current_line_character_counter]+text_gap); 
                        //UI_STRING_GET_NEXT_CHARACTER(current_text_p,dummy_c);
                        //current_line_character_counter++;
                        //current_line_break_character_counter--;
                    }
                    if (default_direction == BIDI_R)
                    {
                        tx = ((edit_width >> 1) + (previous_line_width >> 1));
                        if (tx < 0)
                        {
                            tx = 0;
                        }
                        if (tx > edit_width)
                        {
                            tx = edit_width - 1;
                        }
                    }
                    else
                    {
                        tx = ((edit_width >> 1) - (previous_line_width >> 1));
                        if (tx < 0)
                        {
                            tx = 0;
                        }
                    }
                }
                else if (rich_text.curr_alignment == GUI_INPUT_ALIGN_RIGHT)
                {
                    if (default_direction == BIDI_R)
                    {
                        tx = edit_width - 1;
                        if (tx < 0)
                        {
                            tx = 0;
                        }
                        if (tx > edit_width)
                        {
                            tx = edit_width - 1;
                        }
                    }
                    else
                    {
                        tx = edit_width - previous_line_width;
                        if (tx < 0)
                        {
                            tx = 0;
                        }
                    }
                }
                else
                {
                    if (default_direction == BIDI_R)
                    {
                        tx = edit_width - 1;
                    }
                    else
                    {
                        tx = 0;
                    }
                }
            }

        #ifdef __MMI_INDIC_ALG__
            cluster_width = 0;
            cursor_width = 0;
        #endif /* __MMI_INDIC_ALG__ */ 

        #ifdef __MMI_BIDI_ALG__

            if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
            {
                num_char = current_line_break_character_counter;
                MMI_ASSERT(!(num_char > ((MAX_NUM_OF_CHAR_FOR_EACH_LINE >> 1) - 1)));

                /* bidi_get_char_type(b->text, (U8 *)&default_direction); */
                if (b->cursor_p < current_text_p)
                {
                    logical_cur_pos = 0xFFFF;
                }
                else if (((b->cursor_p - current_text_p) / ENCODING_LENGTH) > (num_char))
                {
                    logical_cur_pos = 0xFFFF;
                }
                else
                {
                    logical_cur_pos = (b->cursor_p - current_text_p) / ENCODING_LENGTH;
                }

                /* to get the last character unicode of previous line */
                if (line_counter == 0)
                {
                    mmi_ucs2_to_wc(
                        &test_current_character,
                        (current_text_p + current_line_break_character_counter * ENCODING_LENGTH - ENCODING_LENGTH));
                }
                else
                {
                    mmi_ucs2_to_wc(&test_current_character, (current_text_p - ENCODING_LENGTH));
                }

                //cursor already be show
                if(is_cursor_show)
                    logical_cur_pos = 0xFFFF;

                logical_hilight_start = 0;
                logical_hilight_end = 0;

                if (default_direction == BIDI_R)
                    reverse_flag = MMI_TRUE;
                else
                    reverse_flag = MMI_FALSE;
#if 0
            #ifdef __MMI_MESSAGES_CHAT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_MESSAGES_CHAT__ */ 
#endif

                line_arabic_char_flag = MMI_FALSE;
                for (iCount = 0; iCount < num_char; iCount++)
                {
                    bidi_get_char_type((U8*) (current_text_p + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
                    if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
                    {
                        line_arabic_char_flag = MMI_TRUE;
                        break;
                    }
                }
                
                bidi_main(
                    current_text_p,
                    (U16) num_char,
                    logical_cur_pos,
                    visual_str,
                    &visual_str_len,
                    &visual_cur_pos,
                    (pBOOL)(line_arabic_char_flag ? reverse_flag : 2),
                    MMI_bidi_input_type,
                    logical_hilight_start,
                    logical_hilight_end,
                    &visual_hilight_start,
                    &visual_hilight_end);

#if 0
            #ifdef __MMI_MESSAGES_CHAT__
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
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_MESSAGES_CHAT__ */ 
/* under construction !*/
#endif
                temp_text_pt = current_text_p;
                current_text_p = visual_str;
                temp_cursor_p = current_cursor_p;
                temp_pre_cursor_p = previous_cursor_p;
                if (visual_cur_pos != 0xFFFF)
                {
                    current_cursor_p = previous_cursor_p = current_text_p + (visual_cur_pos) * ENCODING_LENGTH;

					//if(visual_cur_pos>= num_char) // it means cursor is at the end of string, 2nd parse should process the NULL END char
					//	current_line_break_character_counter = num_char+1;

                    /* previous_cursor_p = current_cursor_p - ENCODING_LENGTH; */
                    if (previous_cursor_p != current_text_p)
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(previous_cursor_p, dummy_c);
                    }

                }
            }
        #endif /* __MMI_BIDI_ALG__ */ 


            ///////////// BEGIN OF SECOND PASS LOOP  (P2BEGIN) ////////////////////////////////
            ///////////// BEGIN OF SECOND PASS LOOP  (P2BEGIN) ////////////////////////////////
            ///////////// BEGIN OF SECOND PASS LOOP  (P2BEGIN) ////////////////////////////////
            {
                S32 P2_char_cnt_for_control_seq = 0; // number of characters consumed by b->icon_callback
                UI_buffer_type P2_line_start_text_p = current_text_p; // hjf, second pass current line start

                while (current_line_break_character_counter>0)
                {
                    S32 P2_text_gap ; // the gap between current object and previous object

                    previous_text_p = current_text_p;
                #ifdef __MMI_INDIC_ALG__
                    temp_hindi_cursor_p = current_text_p;
                #endif 
                #if defined (__MMI_LANG_VIETNAMESE__) && defined (__MMI_INDIC_ALG__) 
                    vietnamese_indic_flag = 0;
                #endif
                    if ((flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
                    {
                    #ifdef __MMI_BIDI_ALG__
                        if (arabic_char_flag)
                        {
                            word_highlight = 0;
                        }
                        else
                    #endif /* __MMI_BIDI_ALG__ */ 
                        if (current_text_p == b->highlight_start_position)
                        {
                           /* barcode */
                            int temp_y = ty;

                            word_highlight = 1;
                            if (b->hilite_cb != NULL)
                            {
                                b->curr_hilite_text_offset_y = -temp_y;
                                if(b->hilite_str_number == 0)
                                {
                                    word_highlight = 0;
                                }
                            }
                        }

                    #ifdef __MMI_BIDI_ALG__
                        if (arabic_char_flag)
                        {
                            word_highlight = 0;
                        }
                        else
                    #endif /* __MMI_BIDI_ALG__ */ 
                        if (current_text_p == b->highlight_end_position)
                        {
                            word_highlight = 0;
                        }
                    }

                    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);        /* get next character */
                    
                    // process text_gap between characters
                    {
                        P2_text_gap = b->text_gap;

                        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                        if (IS_ARABIC_CHARACTER(current_character) && IS_ARABIC_CHARACTER(pre_character))
                            P2_text_gap = 0;
                        #endif
                    }

                #if defined(__MMI_LANG_VIETNAMESE__)
                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        //next_unicode = String[2];
                        //next_unicode |= (String[3]<<8);
                        UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);      /* get next character */
                        tone_mark = mmi_viet_tone_mark(dummy_c);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                            viet_vowel = mmi_viet_vowel_letter(current_character);
                            if (VIET_VOWEL_NONE != viet_vowel)
                            {
                                current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                                #if defined (__MMI_INDIC_ALG__) 
                                vietnamese_indic_flag = 1;
                                #endif
                            }
                            else
                            {
                                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                            }
                        }
                        else
                        {
                            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, dummy_c);
                        }
                    }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

                #ifdef __MMI_BIDI_ALG__
                    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
                    {
                        gui_measure_character(current_character, &character_width, &character_height);
                        if (!RequireToMoveCursor(pre_character, current_character))
                        {
                            character_width = 0;
    					}

                        /* add by mbj06060 to fix the character width and height*/
                        if ((flags & UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR) && UI_TEST_ESC_CHARACTER(current_character))
                        {
                            character_width = 0;
                            
                            character_height = gui_get_character_height() + 3;
                        }
                        else
#if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                            if (UI_TEST_CR_CHARACTER(current_character) ||
                                UI_TEST_LF_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character))
                            {
                                character_width = 10; 
                                character_height = 10;
                            }
                            else
                            {
#endif /* (MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS) */ 
#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
                                if (UI_TEST_CR_CHARACTER(current_character) && UI_TEST_LF_CHARACTER(*current_text_p))
                                {
                                    character_width = 0;  
                                    character_height = gui_get_character_height();
                                    
                                }
                                else
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
                                    if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
                                    {
                                        character_width = mask_character_width;  
                                        character_height = mask_character_height;
                                    }
                                    else if (P2_char_cnt_for_control_seq > 0)
                                    {
                                        P2_text_gap = 0;
                                        character_width = 0;
                                        character_height = character_heights_cache[current_line_character_counter-1]; // reuse last char's height
                                    }
                                    else if ((flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character))
                                    {
                                        P2_text_gap = 0;
                                        character_width = 0;
                                        /* We do not want to assign 'current_line_height' because we might change to small font */
                                        character_height = 1;
                                    }

#ifdef __MMI_MESSAGES_CHAT__
                                    if(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY)
                                    {
                                        if (UI_TEST_GRP_SEP_CHARACTER(current_character))
                                        {
                                            gdi_image_get_dimension(
                                                (U8*) GetImage(CHAT_LOCAL_IMG),
                                                &character_width,
                                                &character_height);
                                        }
                                        else if (UI_TEST_FILE_SEP_CHARACTER(current_character))
                                        {
                                            gdi_image_get_dimension(
                                                (U8*) GetImage(CHAT_REMOTE_IMG),
                                                &character_width,
                                                &character_height);
                                        }
                                        else if (UI_TEST_SENDER_TRUNCATE_SEP_CHARACTER(current_character))
                                        {
                                            gdi_image_get_dimension(
                                                (U8*) GetImage(CHAT_SENDER_TRUNCATE_IMG),
                                                &character_width,
                                                &character_height);
                                        }
                                        else if (UI_TEST_RECEIVER_TRUNCATE_SEP_CHARACTER(current_character))
                                        {
                                            gdi_image_get_dimension(
                                                (U8*) GetImage(CHAT_RECEIVER_TRUNCATE_IMG),
                                                &character_width,
                                                &character_height);
                                        }
                                    }
#endif /* __MMI_MESSAGES_CHAT__ */ 
                                                  
                            if (UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character))
                            {
                                character_width = 0;
                            }
#if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                    }
#endif 
                   /* add by mbj06060 to fix the character width and height end*/
                    }
                    else
                #endif /* __MMI_BIDI_ALG__ */ 
                    {
                        character_width = character_widths_cache[current_line_character_counter];
                        character_height = character_heights_cache[current_line_character_counter];
                    }

                    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
                        character_width = 0;

                #ifdef __MMI_INDIC_ALG__
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))   /* space shud have been added in the Hindi range */
                    {
                        /* if (move_cursor_disp_prev_p <= (b->last_position_p)) */ /* mbj06060 temp resolve*/        
                        {
/* PMT START MAUI_00027731 */
                            move_cursor_disp_curr_p = ire_get_next_cluster_p(move_cursor_disp_prev_p, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */

                            display_skip_moves = move_cursor_disp_curr_p - move_cursor_disp_prev_p;
                            display_skip_moves = display_skip_moves >> 1;
                            cluster_width = cursor_width = cluster_width_filler[cluster_filler_count];
/*PMT START MAUI_00027919*/
                             #if defined (__MMI_BIDI_ALG__)
                               if(IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) && IRE_INSERTED_ARABIC_COUNT()) 
                               {
                                   character_width=cluster_width;


                               }
                             #endif
/*PMT END MAUI_00027919*/

                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_cursor_width[cursor_width]:%d  ",
                                                 cursor_width);

                            move_cursor_disp_prev_p = move_cursor_disp_curr_p;

                            saved_display_skip_moves = display_skip_moves;
                            display_skip_moves--;
                            for (idx = 0; idx < display_skip_moves; idx++)
                            {
                                UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);    /* get next character */
                            }
                        }
                    }
                    else
                    {
                        move_cursor_disp_prev_p += 2;
                        saved_display_skip_moves = 1;
                        #if defined (__MMI_LANG_VIETNAMESE__) 
                        if(vietnamese_indic_flag)
                        {
                            move_cursor_disp_prev_p += 2;
                        }
                        #endif
                    }

                #endif /* __MMI_INDIC_ALG__ */ 

                    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
                    {
                        /* MTK Elvis for R2L characters */
                        if (default_direction == BIDI_L)
                        {
                            xtx = xx + tx;
                            yty = yy + ty;
                        }
                        else
                        {
                        #ifdef __MMI_INDIC_ALG__
                            if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                            {
                                tx -= cluster_width;
                            }
                            else
                        #endif /* __MMI_INDIC_ALG__ */ 
                            {
                                if(character_width) //only move to next position if character_width >0
                                    tx -= (character_width + P2_text_gap);
                            }
                            xtx = xx + tx;
                            yty = yy + ty;
                        }
                        
                        if ((flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character))
                        {
                            BOOL change_font = MMI_FALSE;
                            BOOL change_color = MMI_FALSE;
                            
                            switch (current_character)
                            {
                                /* Alignment is handled in the first pass */
                            case GUI_INPUT_MARKER_RESET_ALL:
                                /* Reset font format and color (no paragraph) */
                                rich_text.curr_font = *b->text_font;
                                rich_text.curr_border = 0;
                                /* USAT */
                                rich_text.curr_strikethrough = 0;
                                rich_text.curr_text_bg_color = rich_text.default_text_bg_color;
                                rich_text.draw_text_bg_color = 0;
                                rich_text.curr_color = rich_text.default_color;
                                change_font = MMI_TRUE;
                                change_color = MMI_TRUE;
                                break;
                                
                            case GUI_INPUT_MARKER_RESET_PARAGRAPH:
                                /* Paragraph handled in the first pass */
                                break;
                                
                            case GUI_INPUT_MARKER_RESET_FORMAT:
                                rich_text.curr_font = *b->text_font;
                                rich_text.curr_border = 0;
                                /* USAT */
                                rich_text.curr_strikethrough = 0;
                                change_font = MMI_TRUE;
                                break;
                                
                            case GUI_INPUT_MARKER_RESET_COLOR:
                                rich_text.curr_color = rich_text.default_color;
                                /* USAT */
                                rich_text.curr_text_bg_color = rich_text.default_text_bg_color;
                                rich_text.draw_text_bg_color = 0;
                                change_color = MMI_TRUE;
                                break;
                                
                            default:
                                if (current_character >= GUI_INPUT_MARKER_COLOR_BEGIN &&
                                    current_character <= GUI_INPUT_MARKER_COLOR_END)
                                {
                                    if (current_character - GUI_INPUT_MARKER_COLOR_BEGIN < MAX_GUI_INPUT_COLOR)
                                    {
                                        rich_text.curr_color =
                                            g_mmi_gui_input_format_color_table[current_character -
                                            GUI_INPUT_MARKER_COLOR_BEGIN];
                                        change_color = MMI_TRUE;
                                    }
                                }
                                else if (current_character >= GUI_INPUT_MARKER_W3C_COLOR_BEGIN &&
                                    current_character <= GUI_INPUT_MARKER_W3C_COLOR_END)
                                {
                                    if (current_character - GUI_INPUT_MARKER_W3C_COLOR_BEGIN <
                                        MAX_GUI_INPUT_W3C_COLOR)
                                    {
                                        rich_text.curr_color =
                                            g_mmi_gui_input_format_w3c_color_table[current_character -
                                            GUI_INPUT_MARKER_W3C_COLOR_BEGIN];
                                        change_color = MMI_TRUE;
                                    }
                                }
                                /* USAT */
                                else if (current_character >= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN &&
                                    current_character <= GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_END)
                                {
                                    if (current_character - GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN <
                                        MAX_GUI_INPUT_W3C_TEXT_BG_COLOR)
                                    {
                                        rich_text.curr_text_bg_color =
                                            g_mmi_gui_input_format_w3c_text_background_color_table[current_character
                                            -
                                            GUI_INPUT_MARKER_TEXT_BACKGROUND_COLOR_BEGIN];
                                        rich_text.draw_text_bg_color = 1;
                                    }
                                }
                                
                                if (current_character >= GUI_INPUT_MARKER_BORDER_COLOR_BEGIN &&
                                    current_character <= GUI_INPUT_MARKER_BORDER_COLOR_END)
                                {
                                    if (current_character - GUI_INPUT_MARKER_BORDER_COLOR_BEGIN <
                                        MAX_GUI_INPUT_COLOR)
                                    {
                                        gui_set_text_border_color(g_mmi_gui_input_format_color_table
                                            [current_character -
                                            GUI_INPUT_MARKER_BORDER_COLOR_BEGIN]);
                                    }
                                }
                                else if (current_character >= GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN &&
                                    current_character <= GUI_INPUT_MARKER_W3C_BORDER_COLOR_END)
                                {
                                    if (current_character - GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN <
                                        MAX_GUI_INPUT_W3C_COLOR)
                                    {
                                        gui_set_text_border_color(g_mmi_gui_input_format_w3c_color_table
                                            [current_character -
                                            GUI_INPUT_MARKER_W3C_BORDER_COLOR_BEGIN]);
                                    }
                                }
                                else if (GUI_INPUT_IS_FORMAT_MARKER(current_character))
                                {
                                    if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BOLD))
                                    {
                                        rich_text.curr_font.bold = 1;
                                        change_font = MMI_TRUE;
                                    }
                                    if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_ITALIC))
                                    {
                                        rich_text.curr_font.italic = 1;
                                        change_font = MMI_TRUE;
                                    }
                                    if (GUI_INPUT_CHECK_FORMAT_MARKER
                                        (current_character, GUI_INPUT_MARKER_UNDERLINE))
                                    {
                                        rich_text.curr_font.underline = 1;
                                        change_font = MMI_TRUE;
                                    }
                                    /* USAT */
                                    if (GUI_INPUT_CHECK_FORMAT_MARKER
                                        (current_character, GUI_INPUT_MARKER_STRIKETHROUGH))
                                    {
                                        rich_text.curr_strikethrough = 1;
                                    }
                                    
                                    if (GUI_INPUT_CHECK_FORMAT_MARKER(current_character, GUI_INPUT_MARKER_BORDER))
                                    {
                                        /* We do not increase font size for bordered font because text gap is already enlarged */
                                        rich_text.curr_border = 1;
                                    }
                                    
                                    if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_SMALL))
                                    {
                                        rich_text.curr_font.size = SMALL_FONT;
                                        change_font = MMI_TRUE;
                                    }
                                    else if (GUI_INPUT_CHECK_SIZE_MARKER
                                        (current_character, GUI_INPUT_MARKER_MEDIUM))
                                    {
                                        rich_text.curr_font.size = MEDIUM_FONT;
                                        change_font = MMI_TRUE;
                                    }
                                    else if (GUI_INPUT_CHECK_SIZE_MARKER(current_character, GUI_INPUT_MARKER_LARGE))
                                    {
                                        rich_text.curr_font.size = LARGE_FONT;
                                        change_font = MMI_TRUE;
                                    }
                                }
                                /* Paragraph handled in the first pass */
                                
                                break;
                                }
                                
                                if (change_font)
                                {
                                    gui_set_font(&rich_text.curr_font);
                                }
                                if (change_color)
                                {
                                    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(rich_text.curr_color);
                                }
                        }
                    #if(MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES)
                        /* MTK Terry for speed up Editor by only display the characters in the display area */
                        /* MTK Terry for show the last line in the display area even it can't display whole line */
                        if ((((-1) == move_to_x) || ((-1) == move_to_y)) &&
                            ((!(flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) && (yty >= y1 - current_line_height) &&
                              ((yty - current_line_height) <= y2)) || ((flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) &&
                                                                       ((yty /* +current_line_height */ ) <= y2)
                                                                       /* START TARUN PMT 20041002 No need to check it */
                    #ifndef MMI_HALF_LINE_MARQUEE_SCROLLING_ENABLE
                                                                       && (yty >= y1)
                    #endif 
                                                                       /* END TARUN PMT 20041002 */
                             )))
                        {
                    #endif /* (MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES) */ 
                            UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(rich_text.curr_color);
                            if (word_highlight || (multitap_flag && (previous_text_p == previous_cursor_p)))
                            {

                            #ifdef __MMI_INDIC_ALG__
                                if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                {
                                    /* PMT START 17082006 */
                                    #if (defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__)) 

                                    if (MMI_current_input_mode == INPUT_MODE_SMART_HINDI)
                                    {

                                        if (!IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))

                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_fill_rectangle(
                                                xtx - 1,
                                                yty,
                                                xtx + cluster_width ,
                                                yty + current_line_height - 1,
                                                selector_color);
                                            }
                                            
                                        }
                                        else
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_fill_rectangle(
                                                xtx,
                                                yty,
                                                xtx + cluster_width ,
                                                yty + current_line_height - 1,
                                                selector_color);
                                        }
                                            
                                        }

                                    }
                                    else

                                    #endif/* (defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__)) */ 
                                    
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        gui_fill_rectangle(
                                            xtx - 1,
                                            yty,
                                            xtx + cluster_width - 1,
                                            yty + current_line_height - 1,
                                            selector_color);
                                    }
                                        
                                    }
                                }
                                else

                            #endif /* __MMI_INDIC_ALG__ */ 

                                {
                                    
                                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                    {
                                    gui_fill_rectangle(
                                        xtx,
                                        yty,
                                        xtx + character_width,
                                        yty + current_line_height - 1,
                                        selector_color);
                                    }
                                    
                                }

                                UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(selected_text_color);        /* set text color */
                            }
                            if (previous_text_p == current_cursor_p)
                            {
                                if (overwrite_flag && !multitap_flag)
                                {
                                    
                                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                    {
                                        if (character_width != 0)
                                        {
                                            gui_fill_rectangle(
                                                xtx,
                                                yty,
                                                xtx + character_width - 1,
                                                yty + current_line_height - 1,
                                                selector_color);
                                        }
                                     }
                                     
                                    UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(selected_text_color);
                                }
                            }
                            if (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)     /* Prevent text and underline connected together */
                            {

                                UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(
                                    xtx-1,
                                    yty + current_line_height - character_height - 2);
                            }
                            else
                            {
                                #if defined(__MMI_INDIC_ALG__)
                                if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                {
                                    UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(xtx-1, yty + current_line_height - character_height);
                                }
                                else
                                #endif
                                {
                                    if (b->hilite_cb)  /* for hilite under line*/
                                    {
                                        UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(xtx, yty + current_line_height - character_height - 2);
                                    }
                                    else
                                    {
                                        UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(xtx, yty + current_line_height - character_height);
                                    }
                                }
                            }

                        #if(MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS)
                            if (UI_TEST_CR_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                    gdi_image_draw_id(xtx,
                                    current_line_height - character_height + yty,
                                        WGUI_CR_CHARACTER_IMAGE_ID);
                                }
                                
                            }
                            else if (UI_TEST_LF_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                    gdi_image_draw_id(
                                    xtx,
                                    current_line_height - character_height + yty,
                                        WGUI_LF_CHARACTER_IMAGE_ID);
                                }
                                
                            }
                            else if (UI_TEST_ESC_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                    gdi_image_draw_id(
                                    xtx,
                                    current_line_height - character_height + yty,
                                        WGUI_ESC_CHARACTER_IMAGE_ID);
                                }
                                
                            }
                            else
                        #endif /* (MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS) */ 
                            if (P2_char_cnt_for_control_seq > 0)
                            {
                                /* Dummy */
                            }
                            else if ((flags & UI_MULTI_LINE_INPUT_BOX_RICHTEXT) && GUI_INPUT_IS_MARKER(current_character))
                            {
                               /* move up to the front */
                            }
                            else if (b->icon_callback &&
                                     (P2_char_cnt_for_control_seq =
                                      b->icon_callback(
                                            previous_text_p,
                                            MMI_TRUE,
                                            NULL,
                                            NULL,
                                            xtx,
                                            /* current_line_height-character_height+ */ yty)) > 0)
                            {
                                /* Dummy */
                            }
                            else
                        #ifdef __MMI_MESSAGES_CHAT__
                            if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY) && UI_TEST_GRP_SEP_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                /* For Chat Buddy Icon - Gurinder - 15/4/2004 */
                                gui_show_transparent_image(
                                    xtx,
                                    current_line_height - character_height + yty,
                                    (PU8) GetImage(CHAT_LOCAL_IMG),
                                    0);
                                }
                                
                            #if 0//hjf, it should not adjust position def __MMI_BIDI_ALG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif /* __MMI_BIDI_ALG__ */ 
                            }
                            else if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY) && UI_TEST_FILE_SEP_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                /* For Chat Buddy Icon - Gurinder - 15/4/2004 */
                                gui_show_transparent_image(
                                    xtx,
                                    current_line_height - character_height + yty,
                                    (PU8) GetImage(CHAT_REMOTE_IMG),
                                    0);
                                }
                                
                            #if 0//hjf, it should not adjust position def __MMI_BIDI_ALG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif /* __MMI_BIDI_ALG__ */ 
                            }
                            else if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY) && UI_TEST_SENDER_TRUNCATE_SEP_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                gui_show_transparent_image(
                                    xtx,
                                    current_line_height - character_height + yty,
                                    (PU8) GetImage(CHAT_SENDER_TRUNCATE_IMG),
                                    0);
                                }
                                
                            #if 0//hjf, it should not adjust position def __MMI_BIDI_ALG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif /* __MMI_BIDI_ALG__ */ 
                            }
                            else if ((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY) && UI_TEST_RECEIVER_TRUNCATE_SEP_CHARACTER(current_character))
                            {
                                
                                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                {
                                gui_show_transparent_image(
                                    xtx,
                                    current_line_height - character_height + yty,
                                    (PU8) GetImage(CHAT_RECEIVER_TRUNCATE_IMG),
                                    0);
                                }
                                
                            #if 0//hjf, it should not adjust position def __MMI_BIDI_ALG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif /* __MMI_BIDI_ALG__ */ 
                            }
                            else
                        #endif /* __MMI_MESSAGES_CHAT__ */ 
                            if (!(UI_STRING_END_OF_STRING_CHARACTER(current_character) ||
                                      UI_TEST_LF_CHARACTER(current_character) ||
                                      UI_TEST_CR_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character)))
                            {

                            #ifdef __MMI_INDIC_ALG__

                                PU8 prev_temp_cursor_p;
                            #endif
                            
                                /* USAT */
                                if (rich_text.draw_text_bg_color)
                                {
                                    
                                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                    {
                                    UI_fill_rectangle(
                                        xtx,
                                        yty - 1,
                                        xtx + character_width,
                                        yty + current_line_height /* character_height */ - 1,
                                        rich_text.curr_text_bg_color);
                                    }
                                    
                                }


                               if((b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT) && (flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR))
                               {
                                   if(b->text_height > b->edit_height)
                                   {
                                       if(yty + current_line_height * 2 > y2)
                                       {
                                          UI_character_type next_char;
                                          S32 width, height;

                                          {
                                              UI_buffer_type tmp = current_text_p;
                                              UI_STRING_GET_NEXT_CHARACTER(tmp,next_char);
                                          }

                                          gui_measure_character((UI_character_type) '.', &width, &height);
                                          
                                          if(current_line_break_character_counter == 1 
                                          || UI_text_x + character_width + 4 * width >= b->x + b->edit_width
                                          || UI_TEST_LF_CHARACTER(next_char)
                                          || UI_TEST_CR_CHARACTER(next_char))
                                          {
                                             gui_move_text_cursor(UI_text_x,UI_text_y);
                                             FONT_CANCEL_WIDTH(1);
                                             if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                             {
                                             gui_print_character((UI_character_type)'.');
                                             }
                                             gui_move_text_cursor(UI_text_x+3,UI_text_y);
                                             if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                             {
                                             gui_print_character((UI_character_type)'.');
                                             }
                                             gui_move_text_cursor(UI_text_x+3,UI_text_y);
                                             if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                             {
                                             gui_print_character((UI_character_type)'.');
                                             }
                                             FONT_CANCEL_WIDTH(0);
                                             done = 1;
                                             break;
                                          }

                                       }
                                    }
                                }

                            #ifdef __MMI_INDIC_ALG__

                                if (temp_hindi_cursor_p == (b->last_position_p))    /* tarun2 don't go further after whole string */
                                {
                                    goto enddisp;
                                }
                                {
                                    prev_temp_cursor_p = temp_hindi_cursor_p;
/* PMT START MAUI_00027731 */
/* PMT START MAUI_00537445 */
                                    if(IRE_INDIC_LANGUAGE_RANGE(current_character))
                                    {
                                        temp_hindi_cursor_p = ire_get_next_cluster_p(temp_hindi_cursor_p, b->text + b->text_length-2);
                                    }
                                    else if(temp_hindi_cursor_p != b->text + b->text_length-2)
                                    {
                                        temp_hindi_cursor_p +=2;
                                        #if defined (__MMI_LANG_VIETNAMESE__) 
                                        if(vietnamese_indic_flag)
                                        {
                                            temp_hindi_cursor_p += 2;
                                            vietnamese_indic_flag =0;
                                        }
                                        #endif
                                    }
/* PMT END MAUI_00537445 */
/* PMT END MAUI_00027731 */

                                }
                                if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
                                {
                                    /* W06.09 Touch Screen With Keypad V1 */
                                #if defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__)
                                    /* MTK Terry for password display for __MMI_FULL_SCREEN_EDITOR__ */
                                    if ((flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) &&
                                        (previous_text_p == previous_cursor_p))
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_character(current_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                    else
                                #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__) */ 
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_character(b->mask_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                }
                                /* for getting the current cluster for display */

    /* START PMT PATCH04052007 */
    /* PMT START FOR_7.17INDIC */                           
/* PMT START MAUI_00537445 */                           
                                else if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                {
                                    S32 disp_multi_clust_len =0;
                                    ire_get_current_cluster(prev_temp_cursor_p, temp_hindi_cursor_p, disp_cluster);
                                    disp_multi_clust_len = mmi_ucs2strlen((PS8) disp_cluster);
/* PMT END MAUI_00537445 */
                                    MMI_ASSERT(!(disp_multi_clust_len > MAX_EDITOR_DISP_LEN));
                                    UI_text_height = character_height;

                                    /* To avoid rule appln in showstring */

                                    ire_disable_indic_rules_parsing();
                                    ire_indic_padding_value(0);
                                    gui_set_text_color(UI_text_color);
                                    if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))

                                    {
                                        FONT_CANCEL_WIDTH(1);
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        ShowString(
                                            UI_text_x,
                                            UI_text_y,
                                            *UI_font,
                                            0,
                                            (U8*) (disp_cluster),
                                            UI_text_height);
                                        FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                    else
                                    {
                                        FONT_CANCEL_WIDTH(1);
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        ShowString(
                                            UI_text_x,
                                            UI_text_y,
                                            *UI_font,
                                            0,
                                            (U8*) (disp_cluster),
                                            UI_text_height);
                                        }
                                        
                                        FONT_CANCEL_WIDTH(0);
                                    }

                                    //Open it again
                                    ire_enable_indic_rules_parsing();
                                    ire_indic_padding_def_value();

                                }
                                else
                                {
                                    if (rich_text.curr_border)
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_bordered_stacked_character(
                                                current_character,
                                                pre2_character,
                                                pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                    else
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_stacked_character(current_character, pre2_character, pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                }

                              enddisp:
                                memset(disp_cluster, 0, sizeof(disp_cluster));

                            #else /* __MMI_INDIC_ALG__ */ 

                                if (flags & UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS)
                                {
                                    /* W06.09 Touch Screen With Keypad V1 */
                                #if defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__)
                                    /* MTK Terry for password display for __MMI_FULL_SCREEN_EDITOR__ */
                                    if ((flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) &&
                                        (previous_text_p == previous_cursor_p))
                                    {
                                        //VIKAS 20060120 PMT START
                                        //gui_print_character(current_character);
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_stacked_character(current_character, pre2_character, pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                        /* VIKAS 20060120 PMT END */
                                    }
                                    else
                                #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__) */ 
                                    {
                                        //VIKAS 20060120 PMT START
                                        //gui_print_character(b->mask_character);
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_stacked_character(b->mask_character, pre2_character, pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                        /* VIKAS 20060120 PMT END */
                                    }
                                }
                                else
                                {
                                    if (rich_text.curr_border)
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_bordered_stacked_character(
                                                current_character,
                                                pre2_character,
                                                pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                    else
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
											FONT_CANCEL_WIDTH(1);
                                            gui_print_stacked_character(current_character, pre2_character, pre_character);
											FONT_CANCEL_WIDTH(0);
                                        }
                                        
                                    }
                                    /* USAT */
                                    if (rich_text.curr_strikethrough)
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        UI_draw_horizontal_line(
                                            xtx,
                                            xtx + character_width - 1,
                                            yty + (current_line_height >> 1),
                                            gui_richtext_strikethrough_color);
                                        }
                                        

                                    }
                                    /* barcode */
                                    if (b->hilite_cb != NULL)
                                    {
                                        if (gui_multi_line_input_box_is_pos_inside_hilite(b, current_text_p - 2))
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            UI_draw_horizontal_line(
                                                xtx,
                                                xtx + character_width,
                                                yty + current_line_height -1 ,
                                                gui_hilite_underline_color);
                                            }
                                            

                                        }
                                    }

                                }

                            #endif /* __MMI_INDIC_ALG__ */ 
                            }
                        #ifdef __MMI_INDIC_ALG__
                            else
                            {
                                temp_hindi_cursor_p += 2;
                            }
                        #endif /* __MMI_INDIC_ALG__ */ 

                            if ((previous_text_p == current_cursor_p) &&
                                !(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW) &&
								!is_cursor_show)
                            {
                                S32 BX2,BY2;
                                //hjf x2 already - vbar width, 
                                    BX2 = x2;
                                BY2 = y2-2;
                                is_cursor_show = MMI_TRUE; // hjf, to record the cursor is be show

                                /* gui_multi_line_input_box_show_cursor(b,xtx,yty,current_line_height,x1,x2-b->vbar.width); */
                            #ifdef __MMI_INDIC_ALG__
                                if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
                                {
                                    xtx -= cluster_width;
                                    xtx += cursor_width;
                                }
                            #endif /* __MMI_INDIC_ALG__ */ 

                                /* For every multiline input box the value remains as y1-2 */
                                if (default_direction != BIDI_L)
                                {
                                    if (g_mmi_wgui_halfline_marquee_scroll_enable)
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        gui_multi_line_input_box_show_cursor(
                                            b,
                                            xtx + character_width,
                                            y1,
                                            current_line_height,
                                            x1,
                                            y1,
                                            BX2,
                                            BY2);
                                        }
                                        
                                    }
                                    else
                                    {
                                        if (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_multi_line_input_box_show_cursor(
                                                b,
                                                xtx + character_width,
                                                yty,
                                                current_line_height - 2,
                                                x1,
                                                y1,
                                                BX2,
                                                BY2);
                                        }
                                             

                                        }
                                        else
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_multi_line_input_box_show_cursor(
                                                b,
                                                xtx + character_width,
                                                yty,
                                                current_line_height,
                                                x1,
                                                y1,
                                                BX2,
                                                BY2);
                                            }
                                            
                                        }
                                    }
                                }
                                else
                                {
                                    if (g_mmi_wgui_halfline_marquee_scroll_enable)
                                    {
                                        
                                        if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                        {
                                        gui_multi_line_input_box_show_cursor(
                                            b,
                                            xtx,
                                            y1 + 2,
                                            current_line_height,
                                            x1,
                                            y1,
                                            BX2,
                                            BY2);
                                        }
                                        
                                    }
                                    else
                                    {
                                        
                                        if (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE)
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_multi_line_input_box_show_cursor(
                                                b,
                                                xtx,
                                                yty,
                                                current_line_height - 1,
                                                x1,
                                                y1,
                                                BX2,
                                                BY2);
                                        }
                                            
                                        }
                                        else
                                        {
                                            
                                            if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                                            {
                                            gui_multi_line_input_box_show_cursor(
                                                b,
                                                xtx,
                                                yty,
                                                current_line_height,
                                                x1,
                                                y1,
                                                BX2,
                                                BY2);
                                        }
                                            
                                        }
                                    }
                                }
                            }
                        #if(MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES)
                        }
                        #endif 
                        if (default_direction == BIDI_L)
                        {
                            if (RequireToMoveCursor(pre_character, current_character))
                            {
                                #ifdef __MMI_INDIC_ALG__
                                if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                {
                                    tx += cluster_width;
                                }
                                else
                                #endif /* __MMI_INDIC_ALG__ */ 
                                {
                                    if(character_width) //only move to next position if character_width >0
                                        tx += character_width + P2_text_gap;
                                }
                            }
                            else
                            {
                                tx += character_width /* +text_gap */ ;
                            }
                        }
                        pre2_character = pre_character;
                        pre_character = current_character;
                    }

                    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
                    {
                        if ((((-1) == move_to_x) || ((-1) == move_to_y)))
                        {
                            S32 line_x, line_x2, line_y;
                            
                            if (previous_text_p == current_cursor_p)
                            {
                                b->cursor_line_position_counter = current_line_character_counter;
                                b->line_before_cursor_line_p = previous_line_start_text_p;
                                b->cursor_line_p = line_start_text_p;
                                b->cursor_x = tx;
                                b->cursor_y = ty;
                                cursor_line_height = current_line_height;
                                next_line_found_flag = 0;

                                if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
                                {
                                    line_x = b->x + b->text_x;
                                    line_x2 = line_x + b->width - 1;
                                    line_y = yty + current_line_height;
                                    gdi_draw_line(line_x, line_y, line_x2, line_y, gdi_act_color_from_rgb(255, b->underline_color.r, b->underline_color.g, b->underline_color.b));

                            #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
                                    if (b->underline_callback != NULL)
                                        b->underline_callback(b->text, (S32)(b->cursor_line_p - b->text - b->previous_shared_bytes +
                                                              (b->start_id) * GUI_PAGE_SIZE * ENCODING_LENGTH), b->text_length);
                            #endif
                                }
                            }
                        }
                        else
                        {
                            if(  ((default_direction == BIDI_L)?(tx + x1)-move_to_x: move_to_x - (tx + x1))>0 
                              && ((ty + b->y + current_line_height + b->text_offset_y) > move_to_y)
                              && ((ty + b->y + b->text_offset_y) <= move_to_y)
                                && (!set_cursor_flag))
                            {
                                b->cursor_line_position_counter = current_line_character_counter;
                                b->line_before_cursor_line_p = previous_line_start_text_p;
                                b->cursor_line_p = line_start_text_p;
                                b->cursor_x = tx;
                                b->cursor_y = ty;
                                b->cursor_p = line_start_text_p+ (previous_text_p - P2_line_start_text_p); //hjf,should consider vistual_str
                                cursor_line_height = current_line_height;
                                set_cursor_flag = 1;
                                next_line_found_flag = 0;
                            #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
                                if (b->locate_cursor_callback != NULL)
                                {
                                    b->locate_cursor_callback(b->text, b->cursor_p, 
                                        (S32)(b->cursor_p - b->text - b->previous_shared_bytes + (b->start_id) * GUI_PAGE_SIZE * ENCODING_LENGTH), 
                                        b->text_length);
                                }
                            #endif
                            }
                            else if (((ty + b->y + current_line_height + b->text_offset_y) > move_to_y) 
                                     && ((ty + b->y + b->text_offset_y) <= move_to_y)
                                     && (!set_cursor_flag) &&
                                     ((1 == current_line_break_character_counter) || (UI_TEST_CR_CHARACTER(current_character))))
                            {
                                b->cursor_line_position_counter = current_line_character_counter;
                                b->line_before_cursor_line_p = previous_line_start_text_p;
                                b->cursor_line_p = line_start_text_p;
                                b->cursor_x = tx;
                                b->cursor_y = ty;
                                b->cursor_p = line_start_text_p+ (previous_text_p - P2_line_start_text_p); //hjf,should consider vistual_str
                                cursor_line_height = current_line_height;
                                set_cursor_flag = 1;
                                next_line_found_flag = 0;
                            #if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
                                if (b->locate_cursor_callback != NULL)
                                {
                                    b->locate_cursor_callback(b->text, b->cursor_p,
                                        (S32)(b->cursor_p - b->text - b->previous_shared_bytes + (b->start_id) * GUI_PAGE_SIZE * ENCODING_LENGTH),
                                         b->text_length);
                                }
                            #endif
                            }
                        }
                    }

                #ifdef __MMI_INDIC_ALG__
                    current_line_break_character_counter -= saved_display_skip_moves;
                    current_line_character_counter += saved_display_skip_moves;
                    cluster_filler_count++;
                #else /* __MMI_INDIC_ALG__ */ 
                    current_line_break_character_counter--;
                    current_line_character_counter++;
                #endif /* __MMI_INDIC_ALG__ */ 
     
                    if (P2_char_cnt_for_control_seq > 0)
                        P2_char_cnt_for_control_seq--;
                }
            }
            ///////////// END OF SECOND PASS LOOP  (P2END) ////////////////////////////////
            ///////////// END OF SECOND PASS LOOP  (P2END) ////////////////////////////////
            ///////////// END OF SECOND PASS LOOP  (P2END) ////////////////////////////////

        #ifdef __MMI_BIDI_ALG__
            if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
            {
//                current_text_p = temp_text_pt + (current_text_p - visual_str);
//                previous_text_p = temp_text_pt + (previous_text_p - visual_str);
                current_text_p = temp_text_pt + num_char*2;
                previous_text_p = temp_text_pt + (num_char-1)*2;

                current_cursor_p = temp_cursor_p;
                previous_cursor_p = temp_pre_cursor_p;
                /*
                 * if(flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)
                 * {
                 * b->highlight_start_position = temp_hilight_start;
                 * b->highlight_end_position = temp_hilight_end;
                 * }
                 */
            }
        #endif /* __MMI_BIDI_ALG__ */ 

            if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) &&
                (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR) && draw_separator)
            {
                static const U8 dotted_line_bitvalues[] = {1, 1, 0, 0};
            #ifdef __MMI_BIDI_ALG__
                if (arabic_char_flag)
                {
                    
                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                    gdi_draw_line_style(
                        xx + 5,
                        yty + current_line_height - 1,
                        xx + b->edit_width - 1 - 5,
                        yty + current_line_height - 1,
                        gdi_act_color_from_rgb(255, 112, 125, 240),
                        sizeof(dotted_line_bitvalues),
                        dotted_line_bitvalues);
                }
                    
                }
                else
            #endif /* __MMI_BIDI_ALG__ */ 
                    
                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                    gdi_draw_line_style(
                        xx + 5,
                        yty + current_line_height - 0,
                        xx + b->edit_width - 1 - 5,
                        yty + current_line_height - 0,
                        gdi_act_color_from_rgb(255, 112, 125, 240),
                        sizeof(dotted_line_bitvalues),
                        dotted_line_bitvalues);
            }
                    
            }

            if (rich_text.line_separator)
            {
                static const U8 line_separator_value[] = {1, 0};
                S32 gap = b->edit_width >> 3;
                S32 yoffset = (rich_text.more_line_spacing >> 1) + 1;
                
                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                {
                gdi_draw_line_style(
                    (S32) xx + gap,
                    (S32) yty + yoffset,
                    (S32) xx + b->edit_width - 1 - gap,
                    (S32) yty + yoffset,
                    (gdi_color) gdi_act_color_from_rgb(255, rich_text.curr_color.r, rich_text.curr_color.g, rich_text.curr_color.b),
                    sizeof(line_separator_value),
                    line_separator_value);
            }
                
            }

            ty += current_line_height;
            if (current_line_height > b->max_line_height)
            {
                b->max_line_height = current_line_height;
            }

            if (b->cursor_line_p == previous_line_start_text_p)
            {
                b->line_after_cursor_line_p = line_start_text_p;
                b->line_after_cursor_line_last_p = previous_text_p;
                next_line_found_flag = 1;
            }
            previous_line_start_text_p = line_start_text_p;

#ifndef __MMI_INDIC_ALG__
            line_start_text_p = line_break_text_p;
#else   
            line_start_text_p = current_text_p;
#endif /*__MMI_INDIC_ALG__*/


            if (flags & UI_MULTI_LINE_INPUT_BOX_ONLY_SHOW_FIRST_LINE)
            {
                /* Used by WAP to emulate single line input gadget  */
                done = 1;
            }

            line_counter++;
        }
        ///////////// MULTILINE BIG LOOP END ////////////////////////////////
        ///////////// MULTILINE BIG LOOP END ////////////////////////////////
        ///////////// MULTILINE BIG LOOP END ////////////////////////////////

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
        {   
            if (check_flag <= PAGE_THREE)
            {
                for (i=0; i<check_flag; i++)
                    height_previous_page += b->page_details[i].page_height;
                
                b->page_details[check_flag].shared_no_of_bytes = 0;
                b->page_details[check_flag].page_id = b->start_id + check_flag;
                b->page_details[check_flag].page_height = total_page_height - height_previous_page;
            }
        }
#endif

        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!set_cursor_flag))
        {
            b->cursor_line_position_counter = current_line_character_counter;
            b->line_before_cursor_line_p = previous_line_start_text_p;
            b->cursor_line_p = line_start_text_p;
            b->cursor_x = tx;
            b->cursor_y = ty - current_line_height;
            b->cursor_p = previous_text_p;
            set_cursor_flag = 1;
            cursor_line_height = current_line_height;
        }

        /* ty + b->footer_height will become b->text_height */
        if (b->min_text_height > 0 && ty + b->footer_height < b->min_text_height)
        {
            ty = b->min_text_height - b->footer_height;
        }

        if (b->max_empty_text_height > 0 && !b->text[0] && !b->text[1])
        {
            ty = b->header_height + b->max_empty_text_height;
        }

        /* Draw underline */
        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && (flags & UI_MULTI_LINE_INPUT_BOX_DRAW_UNDERLINE))
        if(b->min_line_height > 0) // only assign min_line_height should be draw line
		if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
        {
            S32 line_x, line_x2, line_y, line_y_end, line_jump = (b->min_line_height < b->max_line_height) ? b->max_line_height : b->min_line_height;
			gdi_color line_color = gdi_act_color_from_rgb(255, 112, 125, 240);

            line_y = yy + (b->header_height + b->header_gap) + line_jump - 1;
            line_y_end = b->y + b->text_y + border_y + b->edit_height;

            if (b->footer_height > 0 && (line_y_end > yy + ty))
                line_y_end = yy + ty;

			//we always draw line in whole area, only depeonds on the clipping area is correct
			line_x  = b->x;
			line_x2 = b->x + b->width - 1; 

			while (line_y <= line_y_end && line_y < b->y) line_y += line_jump; // loop until line_y is visible

            while (line_y <= line_y_end)
            {
                gdi_draw_line(line_x, line_y, line_x2, line_y, line_color);
                line_y += line_jump;
            }
        }

        /* Draw header region */
        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->header_callback)
        {
            /* Not overlapped with single-pixel border */
            b->header_callback(
                    (MMI_BOOL)((b->header_height > 0) && (b->text_offset_y + b->header_height > 0)),
                    yy, 
                    b->header_height,
                    x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        }

        /* Draw footer region */
        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && b->footer_callback)
        {
            /* Not overlapped with single-pixel border */
            b->footer_callback(
                (MMI_BOOL) ((b->footer_height > 0) && (b->text_offset_y + ty < b->edit_height)),
                yy + ty,
                b->footer_height,
                x1 + 1, y1 + 1, x2 - 1, y2 - 1);
        }

        if (b->max_line_height > 0)
        {
            if (b->text_length == 0)
            {
                b->max_line_height = 0;
            }
            else if ((b->text != NULL) && (b->text[0] == 0 && b->text[1] == 0))
            {
                b->max_line_height = 0;
            }
        }
        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            gui_pop_text_clip();
            gui_pop_clip();
        }
        if (!next_line_found_flag)
        {
            b->line_after_cursor_line_p = b->cursor_line_p;
        }

        /* Footer area should be included in b->text_height */
        ty += b->footer_height;

        b->text_height = ty;
        temp_d = b->text_offset_y + ty;
        /* View mode condition added. Nov-19, TESTFIX   */
        if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) && (flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))
        {
            if (temp_d < edit_height)
            {

            #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
                if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
                {
                    b->text_offset_y += 15;
                }
                else
            #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
                    b->text_offset_y += (edit_height - temp_d);
                if (b->text_offset_y > 0)
                {
                    b->text_offset_y = 0;
                }
            }
        }
        b->n_lines = line_counter;
    #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
        /* Once text_offset_y value is acheived for the text display from the offset given by the concerned application 
           then reset the offset value */
        if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
        {
            if (b->jump_offset_from_app != 0 && b->search_flag_is_on)
            {
/* PMT Start 09_08_06 00071 */
      /*          if(((-b->text_offset_y) % b->edit_height_displayed_lines)<b->edit_height_displayed_lines -(current_line_height*2))
                    {
                    b->text_offset_y += (-b->text_offset_y) % b->edit_height_displayed_lines;
                }
                */
/* PMT End 09_08_06 00071 */
                b->text_offset_y += 40;
                if (b->text_offset_y > 0)
                    b->text_offset_y = 0;
            }
            //begin steven ebook 
            if(-b->text_offset_y==b->text_height && b->text_height >b->edit_height_displayed_lines)
            {
                b->text_offset_y+=b->edit_height_displayed_lines;
            }
            //end steve ebook
            b->page_offset = 0;
            b->jump_offset_from_app = 0;
/* PMT Start 06_08_06 00071 */
          if(b->size_of_total_data < GUI_PAGE_SIZE)
         {
             gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);        
         }
        else
         {
             gui_set_vertical_scrollbar_scale(&b->vbar, 1);
         }
/* PMT End 06_08_06 00071 */

            rich_text.curr_font.bold = rich_text.curr_font.italic = 0;
        }
        else
    #endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);
            
            /* if content is empty, don't show the scrollbar */
            if (b->text_length <= 1 * ENCODING_LENGTH
                && b->header_height <=0 
                && b->footer_height <=0)
                gui_set_vertical_scrollbar_range(&b->vbar, 0);
            else
                gui_set_vertical_scrollbar_range(&b->vbar, ty);
            
            gui_set_vertical_scrollbar_value(&b->vbar, -b->text_offset_y);
        }

        /* Set global font to default because rich_text.curr_font is local variable released dynamically. */
        gui_set_font(b->text_font);
    }
    else    /* else of if(b->text != NULL) */
    {
        gui_set_vertical_scrollbar_scale(&b->vbar, b->edit_height);
        gui_set_vertical_scrollbar_range(&b->vbar, 0);
        gui_set_vertical_scrollbar_value(&b->vbar, 0);
    }
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    count_flag = 0;                                         /* ritesh */
#endif 
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))    /* if not disable draw then do .. */
    {
        gui_pop_clip();

        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) && (edit_width > 0))
        {
            if (flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
            {
                if (b->vbar.scale < b->vbar.range)
                {
                    if (r2lMMIFlag)
                    {
                        /* move vertical scrollbar to the left side */
                        gui_move_vertical_scrollbar(
                            &b->vbar, 
                            b->x + 1, 
                            b->vbar.y);
                    }
                    
                    gui_show_vertical_scrollbar(&b->vbar);
                }
            }
            else
            {
                if (r2lMMIFlag)
                {
                    /* move vertical scrollbar to the left side */
                    gui_move_vertical_scrollbar(
                        &b->vbar, 
                        b->x + 1, 
                        b->vbar.y);
                }

                gui_show_vertical_scrollbar(&b->vbar);
            }
        }
        if (((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) ==
             UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL) && !b->vertical_scroll_on)
        {
        #if(UI_BLINKING_CURSOR_SUPPORT)
            StopTimer(BLINKING_CURSOR);
        #endif 
            gui_cancel_timer(multiline_inputbox_vertical_scroll);
            gui_start_timer(UI_MULTI_LINE_INIT_SCROLL, multiline_inputbox_vertical_scroll);
        }
    }


#ifdef __MMI_BIDI_ALG__
    UI_UNUSED_PARAMETER(temp_hilight_start);
    UI_UNUSED_PARAMETER(temp_hilight_end);
#endif /* __MMI_BIDI_ALG__ */ 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;   /* To fix outbox edit bug */
        g_nsm_msg_context.textlength = b->text_length;
    }

    if ((GetExitScrnID() == SCR_ID_MSG_OUTBOX_MSG) && (mmi_nsm_get_msg_type() == PICTURE_MESSAGE))
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;   /* To fix outbox SEND bug */
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    /* PMT VIKAS START 20050707 */
#ifdef __MMI_UI_DALMATIAN_EDITOR__
if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_DISABLE_DALMATIAN_EDITOR))
{
    if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW))//053006 dalmatian editor Calvin
    {
        S32 draw_dal_image = 1;

        if (!(flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) &&
            b->header_callback && (b->header_height > 0) && (b->text_offset_y + b->header_height >= 0))
        {
            draw_dal_image = 0; /* Not to draw image when image insert in editor. */
        }

        /* Draw Dalmatian editor image */
        if (b->height >= 100)   /* To draw image according to screen size. */
        {
            gui_measure_image(get_image(IMG_EDITOR_DALMATIAN), &image_width, &image_height);
        }
        else
        {
            gui_measure_image(get_image(IMG_EDITOR_DALMATIAN_SMALL), &image_width, &image_height);
        }

        //PMT SUKRIT START 20060104
        //The image will be drawn if the editor height is 25% more than image height
        if (image_height > (b->height - (image_height >> 2)))
        {
            draw_dal_image = 0;
        }
        /* PMT SUKRIT END 20060104 */

        if (draw_dal_image && b->text_length <= 2 && (!(flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)) &&
            (0 == b->footer_height))
        {
            /* PMT VIKAS START 20050817 */
            if (b->height >= 100)
                if (!r2lMMIFlag)
                {
                    
                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                    gui_show_image(
                        (U16) b->x + b->width - (b->vbar.width + image_width + 2),
                        (U16) b->y + b->height - (image_height + 4),
                        get_image(IMG_EDITOR_DALMATIAN));
                }
                    
                }
                else
                {
                    
                    if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                    {
                    gui_show_image(
                        (U16) b->x + (b->vbar.width + 2),
                        (U16) b->y + b->height - (image_height + 4),
                        get_image(IMG_EDITOR_DALMATIAN));
                }
                    
                }
            else if (!r2lMMIFlag)
            {
                
                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                {
                gui_show_image(
                    (U16) b->x + b->width - (b->vbar.width + image_width + 2),
                    (U16) b->y + b->height - (image_height + 4),
                    get_image(IMG_EDITOR_DALMATIAN_SMALL));
            }
                
            }
            else
            {
                
                if(!(b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_HIDE_TEXT_CONTENT))
                {
                gui_show_image(
                    (U16) b->x + (b->vbar.width + 2),
                    (U16) b->y + b->height - (image_height + 4),
                    get_image(IMG_EDITOR_DALMATIAN_SMALL));
            }
                
            }
            /* PMT VIKAS END 20050817 */
        }
    }
}
#endif /* __MMI_UI_DALMATIAN_EDITOR__ */ 
    /* PMT VIKAS END 20050707 */
#if defined(__MMI_SMART_MESSAGE_MT__)
    if ((GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR) || ((GetExitScrnID() == SCR_ID_MSG_OUTBOX_MSG) && (mmi_nsm_get_msg_type() == PICTURE_MESSAGE))   /* Update ucs2 flag when entering outbox msg */
        )
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    if (!(b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
        && !(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
        && !(b->ext_flags &GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR))
    {
        if (cursor_line_height == 0)
            cursor_line_height = current_line_height;

        if ((b->cursor_y+cursor_line_height+b->text_offset_y) > edit_height  &&  edit_height > cursor_line_height)
        {
            b->text_offset_y = -(b->cursor_y+cursor_line_height - edit_height);
            StopTimer(BLINKING_CURSOR);
        }
        else if ((b->cursor_y + b->text_offset_y) < 0)
        {
            b->text_offset_y = -(b->cursor_y);
            StopTimer(BLINKING_CURSOR);
        }
    }

    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        if (b->text_offset_y < b->edit_height - b->text_height)
        {
            b->text_offset_y = b->edit_height - b->text_height;
        }
        if( b->text_offset_y >0) b->text_offset_y = 0;
    }

    UI_UNUSED_PARAMETER(dummy_c);

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    if ((b->text_length / ENCODING_LENGTH) - 1 != 0)
    {
        b->text = backup_text;

        if ( (b->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT) && b->highlight_start_position != NULL)
        {
            b->highlight_start_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->highlight_start_position - (UI_buffer_type)shaping_str)/2)*2;
            b->highlight_end_position = b->text 
                + gui_multi_line_mapping_sha_to_org((b->highlight_end_position - (UI_buffer_type)shaping_str)/2)*2;
        }

		b->cursor_p                      =  b->text + gui_multi_line_mapping_sha_to_org((b->cursor_p                      - (UI_buffer_type)shaping_str)/2)*2;
		b->line_before_cursor_line_p     =  b->text + gui_multi_line_mapping_sha_to_org((b->line_before_cursor_line_p     - (UI_buffer_type)shaping_str)/2)*2;
		b->cursor_line_p                 =  b->text + gui_multi_line_mapping_sha_to_org((b->cursor_line_p                 - (UI_buffer_type)shaping_str)/2)*2;
		b->line_after_cursor_line_p      =  b->text + gui_multi_line_mapping_sha_to_org((b->line_after_cursor_line_p      - (UI_buffer_type)shaping_str)/2)*2;
		b->line_after_cursor_line_last_p =  b->text + gui_multi_line_mapping_sha_to_org((b->line_after_cursor_line_last_p - (UI_buffer_type)shaping_str)/2)*2;
		b->last_position_p               =  b->text + gui_multi_line_mapping_sha_to_org((b->last_position_p               - (UI_buffer_type)shaping_str)/2)*2;
    }
#endif /* __MMI_LANG_ARABIC__ */ 

 
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )

    restore_current_language_for_hindi_rules();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  gui_show_multi_line_input_box_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_multi_line_input_box_ext(multi_line_input_box *b, S32 move_to_x, S32 move_to_y)
{
    S32 text_offset_y;
    do
    {
        text_offset_y = b->text_offset_y;
        gui_show_multi_line_input_box_ext_internal(b, move_to_x, move_to_y);

        /* only locate the cursor once */
        move_to_x = -1;
        move_to_y = -1;
    }while( !(b->flags&UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW) && text_offset_y != b->text_offset_y);
}

/*****************************************************************************
 * FUNCTION
 *  gui_destroy_multi_line_input_box
 * DESCRIPTION
 *  Destroys the multi-line inputbox
 *  
 *  This function only frees the buffer used by the multi-line input box.
 *  It does not destroy the multi-line inputbox object.
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_destroy_multi_line_input_box(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_free(b->text);
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_character_in_pos
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  pos     [IN]        Is the desired position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_character_in_pos(multi_line_input_box *b, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type c, dummy_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b->change_event_handler)
    {
        UI_buffer_type tmp_p = b->text + pos;
        
        UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p,dummy_c);
        
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
            return;
    }
    
    if(pos >= b->text_length - ENCODING_LENGTH)
        return;
    
    p_insert = b->text + pos;
    if (b->cursor_p > p_insert)
        b->cursor_p -= ENCODING_LENGTH;
    
    p1 = p_insert;
    UI_STRING_GET_NEXT_CHARACTER(p1, c);
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, c);
        UI_STRING_INSERT_CHARACTER(p_insert, c);
    }
    
    b->text_length -= ENCODING_LENGTH;
    
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    U8 input_mode = 1;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        if (cursor_pos_flag)
        {
            while (saved_multi_line_skip_moves > 0)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
                saved_multi_line_skip_moves--;

            }
            saved_multi_line_skip_moves = 0;
            cursor_pos_flag = 0;

        }
        /* PMT END MAUI_00025775 */
            cursor_pos_flag = 0;
    #endif /* __MMI_INDIC_ALG__ */

    if (b->cursor_p != b->text)
    {
        if(b->change_event_handler)
        {
            UI_buffer_type tmp_p = b->cursor_p;

            UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p,dummy_c);
            
            if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c))
                return;
        }
    }

    current_text_p = b->cursor_p;
    previous_text_p = b->cursor_p;
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    WCSS_input_change_enable = 0;
    if (b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE)
    {
        if (b->cursor_p - 2 >= b->text)
        {
            UI_buffer_type cursor_p = b->cursor_p;
            BOOL has_editable_char = MMI_FALSE;

            while (cursor_p - 2 >= b->text)
            {
                if (cat115buffer[(cursor_p - 2 - b->text) >> 1] != 0xFF)
                {
                    has_editable_char = MMI_TRUE;
                    break;
                }
                cursor_p -= 2;
            }

            if (!has_editable_char) /* eg. "\-\-nnn" */
            {
                UI_editor_play_tone_cannot_change();
                WCSS_input_change_enable = 1;
                return;
            }

            input_mode = cat115buffer[(b->cursor_p - 2 - b->text) >> 1];
            while (input_mode == 0xFF && b->cursor_p - 2 >= b->text /* redundant check */ )
            {
                gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                input_mode = cat115buffer[(b->cursor_p - 2 - b->text) >> 1];
            }
            current_text_p = b->cursor_p;
            previous_text_p = b->cursor_p;
        }
    }
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    if (previous_text_p == b->text)
    {
        UI_editor_play_tone_cannot_change();    /* play tone */
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        WCSS_input_change_enable = 1;           /* change back to 1 after returing from this function */
    #endif 
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);

    #if defined(__MMI_INDIC_ALG__)
    IRE_DECREMENT_LANGUAGE_VARIABLES(dummy_c);
    #endif

    if (UI_TEST_GSM_EXTENDED(dummy_c))
    {
        if (b->GSM_ext_count > 0)
        {
            b->GSM_ext_count--;
        }
    }
    if (b->icon_callback)
    {
        /* previous_text_p is the first character to be deleted */
        S32 gsm_char_cnt = 0;
        UI_buffer_type tmp_text_p = previous_text_p, tmp_p;
        UI_character_type tmp_c;

        tmp_text_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, tmp_text_p, 0);
        if(tmp_text_p != previous_text_p)
            {
            tmp_p = tmp_text_p;

            while(tmp_p <previous_text_p)
                {
                UI_STRING_GET_NEXT_CHARACTER(tmp_p, tmp_c);
            if (UI_TEST_GSM_EXTENDED(tmp_c))
            {
                gsm_char_cnt++;
            }
        }

            previous_text_p = tmp_text_p;
            b->GSM_ext_count -= gsm_char_cnt;
        }
        
    }

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_LF_CHARACTER(dummy_c))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);
        if (!UI_TEST_CR_CHARACTER(dummy_c)
        ||  (b->change_event_handler && !b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)dummy_c)))
        {
            UI_STRING_GET_NEXT_CHARACTER(previous_text_p, dummy_c);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    /* If In Non * Mode No Need To Decrease the text_length */
    if (((b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) && (input_mode & PIXTEL_UI_WCSS_STAR_INPUT)) ||
        !(b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE))
    {
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        b->cursor_p = previous_text_p;
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(dummy_c, b->UCS2_count, b->allocated_length, b->available_length);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);     /* insert character */
        }
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    }   /* if non-WCSS or not in * mode */
    else if ((b->flags & UI_MULTI_LINE_WCSS_INPUT_BOX_ENABLE) && (!(input_mode & PIXTEL_UI_WCSS_STAR_INPUT)))
    {
        b->cursor_p = previous_text_p;
        if (input_mode & PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER)
        {
            current_character = 0x20;   /* ' ' */
        }
        else
        {
            current_character = 0x30;   /* '0' */
        }
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    WCSS_input_change_enable = 1;
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

#ifdef __MMI_INDIC_ALG__
    if ((b->cursor_p - b->text) >= 4)
    {
        UI_buffer_type temp_multi_line_cursor_p;

        temp_multi_line_cursor_p = b->cursor_p;
        /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
        /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
        if ((IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*(temp_multi_line_cursor_p - 4)) | ((*(temp_multi_line_cursor_p - 3))<<8))  )) 
              && (IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*(temp_multi_line_cursor_p)) | ((*(temp_multi_line_cursor_p+1))<<8))  )) 
              && (IRE_IS_CHAR_TYPE_HALANT( (U16)((*(temp_multi_line_cursor_p - 2)) | ((*(temp_multi_line_cursor_p - 1))<<8))  )))
        {
            /* PMT START MAUI_00025775 */
            U32 langid_Halant = 0;
            U32 diff_langid_cons_halant = 0;

            langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(temp_multi_line_cursor_p - 2))
                                                             | ((*(temp_multi_line_cursor_p - 1)) << 8)));
            if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*temp_multi_line_cursor_p)
                                                                  | ((*(temp_multi_line_cursor_p + 1)) << 8))))
            {
                diff_langid_cons_halant = 1;
            }
            if (!diff_langid_cons_halant)
            {
                U8 saved_skip_after_delete = 0;
                U8 skip_after_delete = 0;
                PU8 first_pos_p = temp_multi_line_cursor_p;
                PU8 second_pos_p;
                UI_character_type previous_character2 = 0;
/* PMT START MAUI_00027731 */
                U32 counter = 0;
                U32 langid_Consonant = 0;

                second_pos_p = ire_get_next_cluster_p(first_pos_p, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
                skip_after_delete = second_pos_p - first_pos_p; /* Number of moves */
                skip_after_delete = skip_after_delete >> 1;
                saved_skip_after_delete = skip_after_delete;
                first_pos_p = b->cursor_p;
                langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*first_pos_p) | ((*(first_pos_p + 1)) << 8)));

                UI_STRING_GET_PREVIOUS_CHARACTER(first_pos_p, previous_character2);
                while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                       IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                {
                    counter += 2;
                    first_pos_p -= 2;
                    if (b->text >= first_pos_p)
                    {
                        break;
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(first_pos_p, previous_character2);
                }
                counter = counter % ((G_MAX - 2));
                skip_after_delete = (G_MAX - 2) - counter;
                if (saved_skip_after_delete > skip_after_delete)
                {
                    saved_skip_after_delete = skip_after_delete;

                }
                skip_after_delete = saved_skip_after_delete;

                while (skip_after_delete--)
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                }

            }
            /* PMT END MAUI_00025775 */
        }
    }
#endif /* __MMI_INDIC_ALG__ */ 


    
    if (b->show_action_flag)
    {
        gui_show_multi_line_input_box(b);   /* show multiline input box */
    }
    

    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    /* !!! Note : For for Nokia smart message write message screen */
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        if (g_nsm_msg_context.UCS2_count == 0)
        {
            MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
            wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
            wgui_redraw_input_information_bar();
        }
        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        if (picmsg_text_struct.ucs2_count == 0)
        {
            MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
            wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
            wgui_redraw_input_information_bar();
        }
    }

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif
 
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_all(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);

    #if defined(__MMI_INDIC_ALG__)
    IRE_RESET_LANGUAGE_VARIABLES();
    #endif


    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETEALL,0))
            return;
    }
    
    gui_multi_line_input_box_clear(b);  /* initilaize multiline box */
    b->cursor_p = b->text;
    b->cursor_line_position_counter = 0;
    b->text_offset_y = 0;
    //hjf, force to update text_offset_y, because cursor position is changed.
    //b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    //b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

    /* For clear all characters from multiline input box */
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)    /* For nsm2 write message only */
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_remaining_characters_display();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_delete_current_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->cursor_p;
    previous_text_p = b->cursor_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (b->icon_callback)
    {
        /* current_text_p is the character next to the last character to be deleted */
        S32 cnt;

        if ((cnt = b->icon_callback(previous_text_p, MMI_FALSE, NULL, NULL, 0, 0)) > 0)
        {
            /* Delete an icon as character sequence */
            current_text_p = previous_text_p + ((cnt - 1) << 1);
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        }
    }
#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    if (UI_TEST_CR_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        if (!UI_TEST_LF_CHARACTER(current_character)
        ||  !b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,(U16)current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {

        #if defined(__MMI_INDIC_ALG__)
        IRE_DECREMENT_LANGUAGE_VARIABLES(current_character);
        #endif

        if (UI_TEST_GSM_EXTENDED(current_character))
        {
            if (b->GSM_ext_count > 0)
            {
                b->GSM_ext_count--;
            }
        }
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(
                current_character,
                b->UCS2_count,
                b->allocated_length,
                b->available_length);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        }
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
        b->change_callback();
    }
    else
    {
        UI_editor_play_tone_cannot_change();    /* play error tone */
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_character_in_pos
 * DESCRIPTION
 *  Inserts a character at the desired position
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 *  pos     [IN]        Is the inserted position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_insert_character_in_pos(multi_line_input_box *b, UI_character_type c, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p_insert, p1;
    UI_character_type old_c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }
    
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
        UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length>= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
        if ((b->flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
            (b->text_length>= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
        else if (b->text_length>= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            UI_editor_play_tone_cannot_insert();    /* play eror tone */
            return;
        }
    }
    
    if (b->text_length >= b->available_length)
    {
        UI_editor_play_tone_cannot_insert();
        return;
    }
    
    p_insert = b->text + pos;
    if (b->cursor_p >= p_insert)
        b->cursor_p += ENCODING_LENGTH;

    p1 = p_insert;
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(p_insert, old_c);
        UI_STRING_INSERT_CHARACTER(p1, c);
        c = old_c;
    }
    UI_STRING_INSERT_CHARACTER(p1, c);  /* insert character */
    
    b->text_length += ENCODING_LENGTH;
    
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_inputbox_adjust_cursor_for_icon_callback
 * DESCRIPTION
 *  adjust the cursor position by the icon callback
 * PARAMETERS
 *  b               [IN]        Is the multi-line inputbox object
 *  direction       [IN]        if 0, to previouse position; or to the next position
 * RETURNS
 *  void
 *****************************************************************************/
UI_buffer_type gui_multi_line_inputbox_adjust_cursor_for_icon_callback(multi_line_input_box *b, UI_buffer_type current_p, U8 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type temp_text_p = b->text;
    S32 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_text_p < current_p)
    {
        cnt = b->icon_callback(temp_text_p, MMI_FALSE, NULL, NULL, 0, 0);
        if (cnt)
        {
            if (current_p > temp_text_p && current_p < temp_text_p + cnt*ENCODING_LENGTH)
            {
                if (direction == 0)
                {
                    /* to the previous */
                    return (temp_text_p);
                }
                else
                {
                    /* to the next */
                    return (temp_text_p + cnt*ENCODING_LENGTH);
                }
            }
            temp_text_p += cnt*ENCODING_LENGTH;
        }
        else
        {
            temp_text_p += ENCODING_LENGTH;
        }
    }

    return current_p;
}

/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_multi_line_input_box_insert_character_internal(multi_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;
    S32 text_length = b->text_length;
    U8 GSM_extended_flag = 0;

    /* MTK Terry for 0x81 encoding support for Phone Book */
    U8 temp_0x81 = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    /* PMT START MAUI_00029915 */
    #if defined(__MMI_BIDI_ALG__) && defined(__MMI_INDIC_ALG__) 
        {
            PMT_BIDI_TYPES default_direction = BIDI_L;
			bidi_get_char_type((U8*) &c, (U8*) & default_direction);
            if(IRE_INSERTED_ARABIC_COUNT() && IRE_INDIC_LANGUAGE_RANGE(c))
            {
				if(add_template_multiline_flag)
				{
                c = (U16)'?';
            }
				else
				{
					UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return MMI_FALSE;
				}
					
            }
            else  if (((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))
                &&(IRE_INSERTED_INDIC_COUNT())) 
            {
                if(add_template_multiline_flag)
				{
                c = (U16)'?';
            }
				else
				{
					UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return MMI_FALSE;
				}
            }
        }
    #endif /*defined(__MMI_BIDI_ALG__) && defined(__MMI_INDIC_ALG__)*/
    /* PMT END MAUI_00029915 */
    if(b->change_event_handler)
    {
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,(U16)c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }
    
    /* MTK Terry for 0x81 memory corrupt issue */
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        if((text_length >> 1) -1 < b->available_length - 3) // current character count = text lenght /2 - NULL
        {
            if(text_length >=2) // NULL should use at least 2 bytes
            {
                ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = c;
				((U16*)MMI_multiline_inputbox.text)[(text_length/2)  ] = 0;
                temp_0x81 = mmi_phb_convert_to_0x81((S8*) b->text, FALSE);
                ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = 0;
            }
        }
    }

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81))
    {
        if ((text_length >> 1) -1 >= b->available_length - 3)//text_length is UCS2 domain ( + NULL) , available_length is bytes domain(+NULL) , -3 is 0x81 header length
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return MMI_FALSE;
        }
    }
    else
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            if (UI_TEST_GSM_EXTENDED(c))
            {
                GSM_extended_flag = 1;
            }
            if (b->UCS2_count == 0 && !UI_TEST_UCS2_CHARACTER(c))
            {
                text_length += (b->GSM_ext_count * ENCODING_LENGTH);
            }
        }

        if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            if ((b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
                (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return MMI_FALSE;
            }
            else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
            {
                UI_editor_play_tone_cannot_insert();    /* play eror tone */
                return MMI_FALSE;
            }
        }

        if (b->UCS2_count == 0  && GSM_extended_flag 
		&& (text_length >= (b->available_length - ENCODING_LENGTH)))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
    }

    p1 = p2 = b->cursor_p;
    if (b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if ((p1 == b->last_position_p) && (text_length >= b->available_length))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
        if (GSM_extended_flag)
        {
            b->GSM_ext_count++;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);             
            #endif

            UI_STRING_INSERT_CHARACTER(p2, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->cursor_p = p2;
        }
        else    /* UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            p1 = b->cursor_p;

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE */
    {
        if (text_length >= (b->available_length) &&
            !((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81)))
        {
            UI_editor_play_tone_cannot_insert();
            return MMI_FALSE;
        }
        if (GSM_extended_flag)
        {
            b->GSM_ext_count++;
        }
        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
            {
                UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                    c,
                    b->UCS2_count,
                    b->allocated_length,
                    b->available_length);
            }
            else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
            {
                UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(
                    c,
                    b->UCS2_count,
                    b->allocated_length,
                    b->available_length);
            }
            else
            {
                UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
            }
        }

        #if defined(__MMI_INDIC_ALG__)
        IRE_INCREMENT_LANGUAGE_VARIABLES(c);
        #endif

        while (!UI_STRING_END_OF_STRING_CHARACTER(c))
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            UI_STRING_INSERT_CHARACTER(p2, c);
            c = old_c;
        }
        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
        b->text_length += ((S32) p2 - (S32) p1);
    }
    /* PMT START MAUI_00025775 */
#ifdef __MMI_INDIC_ALG__
    {
        UI_buffer_type second_cons_ptr;

        second_cons_ptr = b->cursor_p;

        /* This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
        /* is there or not.If it is there then move the cursor beyond the cluster formed.      */
        if ((!add_template_multiline_flag)&&(IRE_IS_CHAR_TYPE_CONSONANT((U16) ((*(second_cons_ptr - 4)) | ((*(second_cons_ptr - 3)) << 8))))
            && (IRE_IS_CHAR_TYPE_CONSONANT((U16) ((*second_cons_ptr) | ((*(second_cons_ptr + 1)) << 8))))
            && (IRE_IS_CHAR_TYPE_HALANT((U16) ((*(second_cons_ptr - 2)) | ((*(second_cons_ptr - 1)) << 8)))))
        {
            U32 langid_Halant = 0;
            U32 diff_langid_cons_halant = 0;

            langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(second_cons_ptr - 2))
                                                             | ((*(second_cons_ptr - 1)) << 8)));
            if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_ptr)
                                                                  | ((*(second_cons_ptr + 1)) << 8))))
            {
                diff_langid_cons_halant = 1;
            }
            if (!diff_langid_cons_halant)
            {
                U8 skip_moves = 0;
               /* U8 saved_skip_moves = 0; */
                UI_character_type previous_character2 = 0;
/* PMT START MAUI_00027731 */
                U32 counter = 0;
                U32 langid_Consonant = 0;
                PU8 first_ptr = second_cons_ptr;
                PU8 second_ptr;

                /* save_cursor_p = b->cursor_p; */
                second_ptr = ire_get_next_cluster_p(first_ptr, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
                skip_moves = second_ptr - first_ptr;    /* Number of moves */
                skip_moves = skip_moves >> 1;
                saved_multi_line_skip_moves = skip_moves;

                second_cons_ptr = b->cursor_p;
                langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_ptr)
                                                                    | ((*(second_cons_ptr + 1)) << 8)));

                UI_STRING_GET_PREVIOUS_CHARACTER(second_cons_ptr, previous_character2);
                while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                       IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                {
                    counter += 2;
                    second_cons_ptr -= 2;
                    if (b->text >= second_cons_ptr)
                    {
                        break;
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(second_cons_ptr, previous_character2);

                }
                counter = counter % ((G_MAX - 2));
                skip_moves = (G_MAX - 2) - counter;
                if (saved_multi_line_skip_moves > skip_moves)
                {
                    saved_multi_line_skip_moves = skip_moves;

                }
                skip_moves = saved_multi_line_skip_moves;

                while (skip_moves--)
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                }
                cursor_pos_flag =1;


            }
        }
    }
#endif /* __MMI_INDIC_ALG__ */ 

    /* PMT END MAUI_00025775 */

    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 1);
    }
    
    if (b->show_action_flag)
    {
        //hjf,force to update offset_y b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);
        //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_input_information_bar();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);
    b->change_callback();


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif
    
    UI_UNUSED_PARAMETER(dummy_c);
    return MMI_TRUE;
}

MMI_BOOL gui_multi_line_input_box_insert_character(multi_line_input_box *b, UI_character_type c)
{
    return gui_multi_line_input_box_insert_character_internal(b,c);
}
/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_newline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_insert_newline(multi_line_input_box *b)
{
    if(gui_multi_line_input_box_insert_character_internal(b,(UI_character_type)0x0D))
        if(!gui_multi_line_input_box_insert_character_internal(b,(UI_character_type)0x0A))
            gui_multi_line_input_box_delete_character(b);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_multi_line_current_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->cursor_p == b->text)
    {
        return 0;
    }
    else
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        return current_character;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_EMS_current_character(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type current_character = 0;


#ifdef __MMI_INDIC_ALG__

    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = b->data->CurrentPosition;
    EMSData *data = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_type_check = gui_EMS_input_box_get_previous_object(data, &p, &current_character, &o);
    if (object_type_check == 2)
    {
        return 0;
    }

#endif /* __MMI_INDIC_ALG__ */ 

    if (b->data->CurrentPosition.OffsetToText == 0)
    {
        return 0;
    }
    else
    {
        current_character = *((UI_character_type*) (b->data->textBuffer + b->data->CurrentPosition.OffsetToText - 2));
        return current_character;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_current_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type gui_single_line_current_character(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == 0)
    {
        return 0;
    }
    else
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
        return current_character;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_insert_multitap_character(multi_line_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;


#ifdef __MMI_INDIC_ALG__
    UI_buffer_type middle_pointer, first_cons_ptr, second_cons_ptr;
#endif /* __MMI_INDIC_ALG__ */ 

    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;
    S32 text_length = b->text_length;

    /* MTK Terry for 0x81 support for Phone Book */
    U8 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // check can be changed or not 
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
/* PMT START MAUI_00029915 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_INDIC_ALG__)
        {
            PMT_BIDI_TYPES default_direction = BIDI_L;
			bidi_get_char_type((U8*) &c, (U8*) & default_direction);
            if(IRE_INSERTED_ARABIC_COUNT() && IRE_INDIC_LANGUAGE_RANGE(c))
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
            else if (((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))
                &&(IRE_INSERTED_INDIC_COUNT())) 
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
        }
#endif
/* PMT END MAUI_00029915 */
    if(b->change_event_handler)
    {
        UI_buffer_type tmp_p = b->cursor_p;
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(tmp_p, dummy_c);
            if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_DELETE_CHAR,dummy_c))
                return;
        }
        if(!b->change_event_handler(GUI_MULTI_LINE_INPUT_BOX_INSERT_CHAR,c))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }
    
    p1 = p2 = b->cursor_p;

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
        /* &&(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP) */ )
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
        {
            if(text_length >=4 ) // one character + NULL should use at least 4 bytes
            {
                S32 last_char_pos = (text_length/2) -1 -1;
			    old_c = ((U16*)MMI_multiline_inputbox.text)[last_char_pos];
			    ((U16*)MMI_multiline_inputbox.text)[last_char_pos] = c;

                temp_0x81 = mmi_phb_convert_to_0x81((S8*) b->text, FALSE);

    			((U16*)MMI_multiline_inputbox.text)[last_char_pos] = old_c;
            }
        }
        else
        {
            if((text_length >> 1) -1 < b->available_length - 3) // current character count = text lenght /2 - NULL
            {
                if(text_length >=2) // NULL should use at least 2 bytes
                {
                    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = c;
				    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)  ] = 0;
                    temp_0x81 = mmi_phb_convert_to_0x81((S8*) b->text, FALSE);
                    ((U16*)MMI_multiline_inputbox.text)[(text_length/2)-1] = 0;
                }
            }
        }
    }

    if ((MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING) && (0 != temp_0x81))
    {
        if ((text_length >> 1) >= (b->allocated_length >> 1) - 3)
        if (!(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }
    else
    {
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED)
        {
            /* No support for inserting GSM extended characters through multitap */
            if (UI_TEST_GSM_EXTENDED(c))
            {
                UI_editor_play_tone_cannot_insert();    /* play error tone */
                return;
            }
            if (b->UCS2_count == 0)
            {
                text_length += (b->GSM_ext_count * ENCODING_LENGTH);
            }
        }

        if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) &&
            UI_TEST_UCS2_CHARACTER(c))
        {

            if ((((b->flags & UI_MULTI_LINE_INPUT_BOX_SMS_MAX_LENGTH_HANDLING) &&
                  ((((b->text_length - 2) - ENCODING_LENGTH) >> 1) >= MAX_MSG_SIZE_UCS2)) ||
                 ((b->flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                  ((b->text_length - 2 + 2) >= ((b->available_length >> 1) - 1))) ||
                 ((b->text_length - 2) >= ((b->available_length-2) >> 1))))
            {
                if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
/* MTI START MAUI_00054333 */
                 (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length))
                 &&(!(b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)) )
/* MTI END MAUI_00054333 */
                {
                    UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return;
                }
                else if ((b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER) &&
                         (text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_FORTYFOUR(b->available_length)))
                {
                    UI_editor_play_tone_cannot_insert();    /* play error tone */
                    return;
                }
                else if (text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
            }

        }

        /* MTK Terry for 0x81 encoding */
        if (text_length > b->available_length)
        {
            UI_editor_play_tone_cannot_insert();
            return;
        }
    }

    if (b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c); /* get previous character */

    #ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        if (cursor_pos_flag)
        {
            while (saved_multi_line_skip_moves > 0)
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
                saved_multi_line_skip_moves--;

            }
            saved_multi_line_skip_moves = 0;
            cursor_pos_flag = 0;

        }
        /* PMT END MAUI_00025775 */
            cursor_pos_flag = 0;
    #endif /* __MMI_INDIC_ALG__ */ 

        p1 = p2 = b->cursor_p;

    #ifdef __MMI_INDIC_ALG__

        middle_pointer = p1;
        first_cons_ptr = p1 - 2;

    #endif /* __MMI_INDIC_ALG__ */ 


        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))
        {

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            UI_STRING_INSERT_CHARACTER(p2, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->cursor_p = p2;

        #ifdef __MMI_INDIC_ALG__
            second_cons_ptr = b->cursor_p;
            
            /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
            /*is there or not.If it is there then move the cursor beyond the cluster formed.      */           
            if ((IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*first_cons_ptr) | ((*(first_cons_ptr+1))<<8))  )) 
                  && (IRE_IS_CHAR_TYPE_CONSONANT( (U16)((*second_cons_ptr) | ((*(second_cons_ptr+1))<<8))  ))  
                  && (IRE_IS_CHAR_TYPE_HALANT( (U16)((*middle_pointer) | ((*(middle_pointer+1))<<8))  ))) 
            {
                /* PMT START MAUI_00025775 */
                U32 langid_Halant = 0;
                U32 diff_langid_cons_halant = 0;

                langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(second_cons_ptr - 2))
                                                                 | ((*(second_cons_ptr - 1)) << 8)));
                if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_ptr)
                                                                      | ((*(second_cons_ptr + 1)) << 8))))
                {
                    diff_langid_cons_halant = 1;
                }
                if (!diff_langid_cons_halant)
                {
                    U8 skip_moves = 0;
                    UI_character_type previous_character2 = 0;
/* PMT START MAUI_00027731 */
                U32 counter = 0;
                    U32 langid_Consonant = 0;
                    PU8 first_ptr = second_cons_ptr;
                    PU8 second_ptr;

                    /* save_cursor_p = b->cursor_p; */
                second_ptr = ire_get_next_cluster_p(first_ptr, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
                    skip_moves = second_ptr - first_ptr;    /* Number of moves */
                    skip_moves = skip_moves >> 1;
                    saved_multi_line_skip_moves = skip_moves;

                    first_cons_ptr = b->cursor_p;
                    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*first_cons_ptr)
                                                                        | ((*(first_cons_ptr + 1)) << 8)));

                    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ptr, previous_character2);
                    while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                           IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                    {
                        counter += 2;
                        first_cons_ptr -= 2;
                        if (b->text >= first_cons_ptr)
                        {
                            break;
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ptr, previous_character2);

                    }
                    counter = counter % ((G_MAX - 2));
                    skip_moves = (G_MAX - 2) - counter;
                    if (saved_multi_line_skip_moves > skip_moves)
                    {
                        saved_multi_line_skip_moves = skip_moves;

                    }
                    skip_moves = saved_multi_line_skip_moves;

                    while (skip_moves--)
                    {
                        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                    }

                    cursor_pos_flag = 1;
                }
            }
            /* PMT END MAUI_00025775 */
        #endif /* __MMI_INDIC_ALG__ */ 

        }
        else    /* UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            p1 = b->cursor_p;
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c); /* get next character */

            #if defined(__MMI_INDIC_ALG__)
            IRE_DECREMENT_LANGUAGE_VARIABLES(dummy_c);
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(old_c, c, b->UCS2_count, b->allocated_length, b->available_length);
            }
            b->text_length += ((S32) p2 - (S32) p1);
        }
    }
    else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP */
    {

    #ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        saved_multi_line_skip_moves = 0;
        /* PMT END MAUI_00025775 */
        cursor_pos_flag = 0;
    #endif 
        p1 = p2 = b->cursor_p;
        if (b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            if ((p1 == b->last_position_p) && (text_length >= b->available_length))
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
            if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))
            {

                #if defined(__MMI_INDIC_ALG__)
                IRE_DECREMENT_LANGUAGE_VARIABLES(old_c);
                IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                #endif

                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->cursor_p = p2;
            }
            else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
            {
                p1 = b->cursor_p;
                UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);

                #if defined(__MMI_INDIC_ALG__)
                IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                #endif

                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE3(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
        else    /* b_flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE */
        {
            if (text_length >= b->available_length && (0 == temp_0x81))
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
            if (b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else if (b_flags & UI_MULTI_LINE_INPUT_BOX_FORTY_FOUR_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE3(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }

            #if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
            #endif

            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
        }
        b->flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    //hjf,force to update offset_y  b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);   /* show multiline input box */
    //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_WRITE)
    {
        g_nsm_msg_context.UCS2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm2_get_remaining_len();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);

        if (wgui_inputbox_information_flag)
        {
            wgui_redraw_input_information_bar();
        }

        g_nsm_msg_context.textlength = b->text_length;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)
    if (GetMessagesCurrScrnID() == SCR_ID_NSM_EDITOR)
    {
        picmsg_text_struct.ucs2_count = b->UCS2_count;
        MMI_multiline_inputbox.available_length = mmi_nsm_get_infobar_maxlen();
        wgui_inputbox_buffer_size = (MMI_multiline_inputbox.available_length >> 1);
        wgui_redraw_input_information_bar();
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    b->validation_callback(b->text, b->cursor_p, (b->text_length >> 1) - 1);    /* call validation callback func */
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_confirm_multitap_character(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_previous_character
 * DESCRIPTION
 *  get the previous character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  c       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 gui_multi_line_input_box_get_previous_character(multi_line_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        return 0;
    }
    if (b->cursor_p == b->text)
    {
        return 0;
    }
    /* c = (data->textBuffer[current_position->OffsetToText-1]|(data->textBuffer[current_position->OffsetToText-2]<<8)); */
    *c = (*(b->cursor_p - 2)) | (*(b->cursor_p - 1)) << 8;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;

#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type previous_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    UI_character_type pre_one_char = 0;
    UI_character_type pre_two_char = 0;
    UI_character_type pre_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */


#ifdef __MMI_INDIC_ALG__
    /* Added for knowing the current character is hindi or not */
    UI_buffer_type check_text_p = b->cursor_p;
#endif /* __MMI_INDIC_ALG__ */ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

    if (b->cursor_p == b->text)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

#ifdef __MMI_INDIC_ALG__
    UI_STRING_GET_PREVIOUS_CHARACTER(check_text_p, dummy_c);    /* get previous character */
    /* If Hindi Character */
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))
    {
        /* Move by a syllable rather than by a character as in English */
        b->cursor_p = ire_get_prev_cluster_p(b->text, b->cursor_p);
    }
    else
#endif /* __MMI_INDIC_ALG__ */ 

    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c); /* get previous character */
    }
#if defined(__MMI_LANG_VIETNAMESE__)
    if ((dummy_c >= 0x0300) && (dummy_c <= 0x0323))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, previous_unicode);        /* get next character */
        viet_vowel = mmi_viet_vowel_letter(previous_unicode);
        if (VIET_VOWEL_NONE != viet_vowel)
        {
            tone_mark = mmi_viet_tone_mark(dummy_c);
            if (VIET_TONE_NONE != tone_mark)
            {
                dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
            }
            else
            {
                UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, previous_unicode);
            }
        }
        else
        {
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, previous_unicode);
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /* MTK Steven 20050505  */
#if defined(__MMI_LANG_THAI__)
    if (isThaiChar(dummy_c))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, pre_one_char);
        if (isThaiChar(pre_one_char))
        {
            if (!RequireToMoveCursor(pre_one_char, dummy_c))
            {
                if (b->cursor_p != b->text)
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, pre_two_char);
                    if (isThaiChar(pre_two_char))
                    {
                        if (!RequireToMoveCursor(pre_two_char, pre_one_char))
                        {
                            if (b->cursor_p != b->text)
                            {
                                UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, pre_three_char);
                                if (isThaiChar(pre_three_char))
                                {
                                    if (RequireToMoveCursor(pre_three_char, pre_two_char))
                                    {
                                        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                                    }
                                }
                                else
                                {
                                    UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                                }
                            }
                        }
                        else
                        {
                            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                        }
                    }
                    else
                    {
                        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                    }
                }
            }
            else
            {
                UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
            }
        }
        else
        {
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */
/* START PMT PATCH04052007 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* END PMT PATCH04052007 */

    if (IS_ARABIC_CHARACTER(dummy_c))
    {
        U16 idx;

        idx = (b->cursor_p - b->text + 2) / 2 - 1;

        while (idx > 0)
        {
            if (OrgToSha[idx] == OrgToSha[idx - 1])
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
            }
            else
            {
                break;
            }
            idx--;
        }
    }
/* START PMT PATCH04052007 */
#endif /* __MMI_BIDI_ALG__*/
/* END PMT PATCH04052007 */

    if (b->icon_callback)
    {
        b->cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, b->cursor_p, 0);
    }
#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    else if (UI_TEST_LF_CHARACTER(dummy_c) && (b->cursor_p != b->text))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, dummy_c);
        if (!UI_TEST_CR_CHARACTER(dummy_c))
        {
            UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 

    
    if (b->show_action_flag)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)    
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type next_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    UI_character_type next_one_char = 0;
    UI_character_type next_two_char = 0;
    UI_character_type next_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

#ifdef __MMI_INDIC_ALG__
    /* Added for knowing the current character is hindi or not */
    UI_buffer_type check_text_p = b->cursor_p;
#endif /* __MMI_INDIC_ALG__ */ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

#ifdef __MMI_INDIC_ALG__
    UI_STRING_GET_NEXT_CHARACTER(check_text_p, current_character);      /* get previous character */

    /* If Hindi Character */
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        cursor_p = (U8*) ire_get_next_cluster_p(b->cursor_p,b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
    }
    else
#endif /* __MMI_INDIC_ALG__ */ 
 
    {
        UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);      /* get next character */
    }
#if defined(__MMI_LANG_VIETNAMESE__)
    if ((current_character > 0x0040) && (current_character < 0x01B1))
    {
        UI_STRING_GET_NEXT_CHARACTER(cursor_p, next_unicode);   /* get next character */
        tone_mark = mmi_viet_tone_mark(next_unicode);
        if (VIET_TONE_NONE != tone_mark)
        {
            viet_vowel = mmi_viet_vowel_letter(current_character);
            if (VIET_VOWEL_NONE != viet_vowel)
            {
                current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
            }
            else
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, next_unicode);
            }
        }
        else
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, next_unicode);
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    if (isThaiChar(current_character) && *cursor_p != '\0')
    {
        UI_STRING_GET_NEXT_CHARACTER(cursor_p, next_one_char);
        if (isThaiChar(next_one_char))
        {
            if (!RequireToMoveCursor(current_character, next_one_char))
            {
                if (*cursor_p == '\0')
                {
                    current_character = next_one_char;
                }
                else
                {
                    UI_STRING_GET_NEXT_CHARACTER(cursor_p, next_two_char);
                    if (isThaiChar(next_two_char))
                    {
                        if (!RequireToMoveCursor(next_one_char, next_two_char))
                        {
                            if (*cursor_p == '\0')
                            {
                                current_character = next_two_char;
                            }
                            else
                            {
                                UI_STRING_GET_NEXT_CHARACTER(cursor_p, next_three_char);
                                if (isThaiChar(next_three_char))
                                {
                                    if (!RequireToMoveCursor(next_two_char, next_three_char))
                                    {
                                        current_character = next_three_char;
                                    }
                                    else
                                    {
                                        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
                                    }
                                }
                                else
                                {
                                    UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
                                }
                            }
                        }
                        else
                        {
                            UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
                        }
                    }
                    else
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
                    }
                }
            }
            else
            {
                UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
            }
        }
        else
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

/* START PMT PATCH04052007 */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* END PMT PATCH04052007 */
    if (IS_ARABIC_CHARACTER(current_character))
    {
        U16 idx;

        idx = (cursor_p - b->text) / 2 - 1;

        while (idx < unshaped_text_len)
        {
            if (OrgToSha[idx] == OrgToSha[idx + 1])
            {
                UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
            }
            else
            {
                break;
            }
            idx++;
        }
    }
/* START PMT PATCH04052007 */
#endif /* __MMI_BIDI_ALG__*/
/* END PMT PATCH04052007 */

    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    if (b->icon_callback)
    {
        cursor_p = gui_multi_line_inputbox_adjust_cursor_for_icon_callback(b, cursor_p, 1);
    }
#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
    else if (UI_TEST_CR_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
        if (!UI_TEST_LF_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        }
    }
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 
    b->cursor_p = cursor_p;
    
    if (b->show_action_flag)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)    
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif

   
}

#if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_handle_CRLF_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_handle_CRLF_navigation(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(cursor_p, current_character);
    if (UI_TEST_LF_CHARACTER(current_character))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, current_character);
        if (UI_TEST_CR_CHARACTER(current_character))
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->cursor_p, current_character);
        }
    }
}
#endif /* (MULTILINE_INPUTBOX_USE_CRLF_COMBINATION) */ 

/* Used for move to next and previous line */


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_handle_icon_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_handle_icon_navigation(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type cursor_p = b->cursor_p;
    UI_character_type dummy_c;
    S32 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!b->icon_callback)
    {
        return;
    }

    UI_STRING_GET_PREVIOUS_CHARACTER(cursor_p, dummy_c);
    for (cnt = 2; cnt <= MMI_MULTILINE_ICON_MAX_STRING_LEN; cnt++)
    {
        /* Inside character sequence */
        if (b->icon_callback(cursor_p, MMI_FALSE, NULL, NULL, 0, 0) >= cnt)
        {
            b->cursor_p = cursor_p;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous_line
 * DESCRIPTION
 *  Moves the cursor to the previous line
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, fh;
    UI_buffer_type p;
    UI_character_type dummy_c = 0;
    S32 line_width = 0, width = 0, height = 0;
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
	PU8 move_ems_cursor_prev_p=0,move_ems_cursor_curr_p=0;
#endif
/* END PMT MAUI_00024783 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry For Font Type when Key Down or UP */
    gui_set_font(b->text_font);
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        if (b->text_offset_y < 0)
        {
            /* Note that scrolling offset might be exactly one line if UI_MULTI_LINE_INPUT_BOX_RICHTEXT is set. */
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            b->text_offset_y += fh;
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
        else if (b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) /* Pixtel - 2/16/04 - Gurinder - Move to the previos item on up key in case on inline box. */
        {
            //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
            //gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
            //show_fixed_list();
            //inline_fixed_list_goto_previous_item();
            hilited_item_changed = 1;
        }
    }
    else
    {
        if (b->line_before_cursor_line_p == b->cursor_line_p)
        {
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
            if (MMI_multi_line_inputbox_present)
            {
                //handle_inline_full_screen_edit_close();
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
                //show_fixed_list();
                //inline_fixed_list_goto_previous_item();
                hilited_item_changed = 1;
            }
            else
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            if (b->header_height > 0 && b->text_offset_y < 0)
            {
                b->text_offset_y += 20;
                if (b->text_offset_y > 0)
                {
                    b->text_offset_y = 0;
                }
                b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                gui_show_multi_line_input_box(b);   /* show multiline input box */
                b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                StopTimer(BLINKING_CURSOR);
            }
            else if (b->header_height == 0 && b->text_offset_y < 0)
            {
                b->text_offset_y = 0;
                b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(b);
                b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
            }
            else
            {
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                UI_editor_play_tone_cannot_navigate();  /* play error tone */
            }
            return;
        }
        /* MTK Terry for Move Up by Width */
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
		if(IRE_INDIC_CHARACTER_UCS2_RANGE((*b->cursor_p) | (*(b->cursor_p+1)<<8) ))
		{
			move_ems_cursor_prev_p=b->cursor_p;
/* PMT START MAUI_00027731 */
			move_ems_cursor_curr_p = ire_get_next_cluster_p(move_ems_cursor_prev_p, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
			b->cursor_p=move_ems_cursor_curr_p;
			width=ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);
			move_ems_cursor_curr_p=move_ems_cursor_prev_p=0;
		}
		else
#endif
        {
/* END PMT MAUI_00024783 */
        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
        gui_measure_character(dummy_c, &width, &height);
        if (UI_TEST_CR_CHARACTER(dummy_c))
        {
            width = 0;
        }
        else if (UI_TEST_LF_CHARACTER(dummy_c))
        {
            width = 0;
        }
        else if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
        {
            width = 0;
        }
/* START PMT MAUI_00024783 */
		}
/* END PMT MAUI_00024783 */
        b->cursor_x -= (width);
        p = b->cursor_p = b->line_before_cursor_line_p;
        for (i = 0; line_width <= b->cursor_x + (width >> 1); i++)
        {
            if (p == b->cursor_line_p)
            {
                break;
            }
            else
            {
                b->cursor_p = p;
            }
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
if(IRE_INDIC_CHARACTER_UCS2_RANGE((*p) | (*(p+1)<<8) ))
{
	move_ems_cursor_prev_p =p;
/* PMT START MAUI_00027731 */
    move_ems_cursor_curr_p = ire_get_next_cluster_p(move_ems_cursor_prev_p, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
    p=move_ems_cursor_curr_p;
}
else
#endif            
            UI_STRING_GET_NEXT_CHARACTER(p, dummy_c);
/* END PMT MAUI_00024783 */
        #if defined(__MMI_LANG_VIETNAMESE__)
            /* MTK Terry for Cursor Move Up and Down Issue */
            if ((dummy_c > 0x0040) && (dummy_c < 0x01B1))
            {
                UI_character_type next_unicode = 0;
                viet_tone_mark tone_mark = VIET_TONE_NONE;
                viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;

                UI_STRING_GET_NEXT_CHARACTER(p, next_unicode);  /* get next character */
                tone_mark = mmi_viet_tone_mark(next_unicode);
                if (VIET_TONE_NONE != tone_mark)
                {
                    viet_vowel = mmi_viet_vowel_letter(dummy_c);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    }
                    else
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(p, next_unicode);
                    }
                }
                else
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(p, next_unicode);
                }
            }
        #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
if((move_ems_cursor_prev_p)&&IRE_INDIC_CHARACTER_UCS2_RANGE((*move_ems_cursor_prev_p) | (*(move_ems_cursor_prev_p+1)<<8) ))
{
			width = ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);
}
else
#endif
/* END PMT MAUI_00024783 */
            gui_measure_character(dummy_c, &width, &height);
            line_width += (width + b->text_gap);
        }
        gui_multi_line_input_box_handle_icon_navigation(b);
    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
        gui_multi_line_input_box_handle_CRLF_navigation(b);
    #endif 
        //hjf,force to update offset_y b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)    
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next_line
 * DESCRIPTION
 *  Moves the cursor to the next line
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next_line(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MTK Terry Redesign the next line operation */
    /* Some issues happened because the dh is not the same as the b->text_height and we can't get the next line height */
    /* We use b->text_height instead of dh and adjust the move distance when reaching the last line of the text */
    S32 i, fh /* ,dh */ ;
    UI_buffer_type p;
    UI_character_type dummy_c = 0;
    S32 line_width = 0, width = 0, height = 0;
/* START PMT MAUI_00024783 */
	#if defined __MMI_INDIC_ALG__
	PU8 move_ems_cursor_prev_p=0,move_ems_cursor_curr_p=0;
    #endif
/* END PMT MAUI_00024783 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry For Font Type when Key Down or UP */
    gui_set_font(b->text_font);
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        /* Note that scrolling offset might be exactly one line if UI_MULTI_LINE_INPUT_BOX_RICHTEXT is set. */
        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        /* Leo add: enlarge the hidden area to show all strings when strings with different languages */
        //dh=(b->edit_height/fh);   /*MTK Terry roll back for stop watch title display need to discuss with Leo*/
        //dh=(b->edit_height/fh)-1;
        //dh*=fh;
        //START TARUN PMT 20041023 Added for sms chat issue
        //if ( (b->text_offset_y-fh)!=(-(b->text_height-(dh+fh)))) /*Comment this line here and have no idea why to need this line*/
        //END TARUN PMT 20041023
        {
            /* MTK Terry for In-Line Multiline Next Line Behavior */
            if ((b->text_offset_y /*-fh */ ) > (-(b->text_height - b->edit_height /* dh */ )))
            {
                b->text_offset_y -= fh;

                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }
            }
            else if (b->flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU)
            {
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //gui_fixed_list_menu_goto_first_item(&MMI_fixed_list_menu);
                /* MTK Terry for in line multiline read only to clear g_mmi_wgui_halfline_marquee_scroll_enable */
                if (complete_inline_item_edit)
                {
                    complete_inline_item_edit();
                }
                inline_fixed_list_goto_next_item();
                hilited_item_changed = 1;
                //show_fixed_list();
                //Fix List Navigation Problem With Read Only Control - Gurinder - 3/27/2004.
                //register_fixed_list_keys();
                //End
            }
        }
    }
    else    /* b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE */
    {
        if (b->line_after_cursor_line_p == b->cursor_line_p)
        {
        #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
            if (MMI_multi_line_inputbox_present)
            {
                //handle_inline_full_screen_edit_close();
                //Gurinder - 20/4/2004 - Use Inline Navigation Function Instead Of Noraml Text Menu
                //inline_fixed_list_goto_next_item();
                //gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
                //show_fixed_list();
                hilited_item_changed = 1;
            }
            else
        #endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
            if (b->footer_height > 0 && (b->text_offset_y + b->text_height > b->edit_height))
            {
                b->text_offset_y -= 20;
                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }
                b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                gui_show_multi_line_input_box(b);   /* show multiline input box */
                b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                StopTimer(BLINKING_CURSOR);
            }
            else if (b->text_offset_y + b->text_height > b->edit_height && b->header_height > 0)
            {
                b->text_offset_y -= 20;
                if (b->text_offset_y < b->edit_height - b->text_height)
                {
                    b->text_offset_y = b->edit_height - b->text_height;
                }

                b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(b);   /* show multiline input box */
                b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
				StopTimer(BLINKING_CURSOR);
            }
            else
            {
                b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
                UI_editor_play_tone_cannot_navigate();
            }
            return;
        }
        /* MTK Terry for Move Down by Width */
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
		if(IRE_INDIC_CHARACTER_UCS2_RANGE((*b->cursor_p) | (*(b->cursor_p+1)<<8) ))
		{
			move_ems_cursor_prev_p=b->cursor_p;
/* PMT START MAUI_00027731 */
			move_ems_cursor_curr_p = ire_get_next_cluster_p(move_ems_cursor_prev_p, b->text + b->text_length -2);
/* PMT END MAUI_00027731 */
			b->cursor_p=move_ems_cursor_curr_p;
			width=ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);
            move_ems_cursor_curr_p=move_ems_cursor_prev_p=0;

		}
		else
#endif
        {
/* END PMT MAUI_00024783 */
        UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
        gui_measure_character(dummy_c, &width, &height);
        if (UI_TEST_CR_CHARACTER(dummy_c))
        {
            width = 0;
        }
        else if (UI_TEST_LF_CHARACTER(dummy_c))
        {
            width = 0;
        }
        else if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
        {
            width = 0;
        }
/* START PMT MAUI_00024783 */
		}
/* END PMT MAUI_00024783 */
        b->cursor_x -= (width);
        p = b->cursor_p = b->line_after_cursor_line_p;
        for (i = 0; line_width <= b->cursor_x + (width >> 1); i++)
        {
            /* MTK Terry for Cursor Moving */
            b->cursor_p = p;
            if (p == b->line_after_cursor_line_last_p || (((*p) | (*(p+1)<<8)) == 0))
            {
                break;
            }
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
if(IRE_INDIC_CHARACTER_UCS2_RANGE((*p) | (*(p+1)<<8) ))
{
	move_ems_cursor_prev_p =p;
/* PMT START MAUI_00027731 */
    move_ems_cursor_curr_p = ire_get_next_cluster_p(move_ems_cursor_prev_p, b->text + b->text_length-2);
/* PMT END MAUI_00027731 */
    p=move_ems_cursor_curr_p;
}
else
#endif
/* END PMT MAUI_00024783 */   
            UI_STRING_GET_NEXT_CHARACTER(p, dummy_c);
        #if defined(__MMI_LANG_VIETNAMESE__)
            /* MTK Terry for Cursor Move Up and Down Issue */
            if ((dummy_c > 0x0040) && (dummy_c < 0x01B1))
            {
                UI_character_type next_unicode = 0;
                viet_tone_mark tone_mark = VIET_TONE_NONE;
                viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;

                UI_STRING_GET_NEXT_CHARACTER(p, next_unicode);  /* get next character */
                tone_mark = mmi_viet_tone_mark(next_unicode);
                if (VIET_TONE_NONE != tone_mark)
                {
                    viet_vowel = mmi_viet_vowel_letter(dummy_c);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        dummy_c = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    }
                    else
                    {
                        UI_STRING_GET_PREVIOUS_CHARACTER(p, next_unicode);
                    }
                }
                else
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(p, next_unicode);
                }
            }
        #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* START PMT MAUI_00024783 */
#if defined __MMI_INDIC_ALG__
if((move_ems_cursor_prev_p)&&IRE_INDIC_CHARACTER_UCS2_RANGE((*move_ems_cursor_prev_p) | (*(move_ems_cursor_prev_p+1)<<8) ))
{
			width = ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);
}
else
#endif
/* END PMT MAUI_00024783 */
            gui_measure_character(dummy_c, &width, &height);
            line_width += (width + b->text_gap);
        }
        gui_multi_line_input_box_handle_icon_navigation(b);
    #if(MULTILINE_INPUTBOX_USE_CRLF_COMBINATION)
        gui_multi_line_input_box_handle_CRLF_navigation(b);
    #endif 
        //hjf,force to update offset_y b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);   /* show multiline input box */
        //hjf,force to update offset_y b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_multi_line_input_box_change_input_mode_for_smart_Abc(b);
#endif
    UI_UNUSED_PARAMETER(dummy_c);
}



/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_previous_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_previous_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        gui_paging_multi_line_input_box_previous_page(b);
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        UI_UNUSED_PARAMETER(b);
        /* Feature not available */
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_next_page
 * DESCRIPTION
 *  Moves the cursor to the next page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_next_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        gui_paging_multi_line_input_box_next_page(b);
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */       
        UI_UNUSED_PARAMETER(b);
        /* Feature not available */
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}


#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__

/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_previous_page
 * DESCRIPTION
 *  show the previous page of the book
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_previous_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 fh;

    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }

        if (b->text_offset_y < 0)
        {
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            if (b->end_id == b->last_page_id && b->last_page_flag == 1)
            {
                /* prev_height=height of the text in the last page which can be a maximum of the window height.This variable is used to 
                   maintain the text relocation */
                b->text_offset_y += b->last_window_text_height;
                b->last_page_flag = 0;
            }
            else
            {
                b->text_offset_y += b->edit_height_displayed_lines;
            }
            if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines) &&
                b->size_of_total_data > GUI_PAGE_SIZE)
            {
                gui_paging_multi_line_input_box_get_previous_page_callback(b);
                if (b->page_details[PAGE_ZERO].page_id != 0)
                {
                    b->text_offset_y -= b->page_details[PAGE_ZERO].page_height;
                    /*
                     * to maintain the text relocation issue we save the height of page at 0th index before a new page entry.According to 
                     * paging algorithm,after a new page entry ,page at 0th index will come to index 1 of the buffer.If the height of the saved value differs 
                     * with the height of page at index 1 then this condition will be tested
                     */
                    b->page_details[PAGE_ZERO].page_id = b->start_id;
                    if (b->page_zero_prev_height != b->page_details[PAGE_ONE].page_height)
                    {
                        b->text_offset_y -= fh;
                    }
                }
            }
            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }

    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_next_page
 * DESCRIPTION
 *  show the next page of the book
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_next_page(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;

    UI_character_type dummy_c = 0;

    /* static S32 percentage_offset = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }
        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        if ((b->text_offset_y) > (-(b->text_height - b->edit_height)))
        {
            b->text_offset_y -= b->edit_height_displayed_lines; /* ritesh */
            if (b->text_offset_y <=
                -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
                  b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
            {
                if (b->end_id < b->last_page_id)
                {
                    b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                    gui_paging_multi_line_input_box_get_next_page_callback(b);
                }
                else
                {
                    if (b->text_offset_y - b->edit_height_displayed_lines < -b->text_height && b->last_page_flag == 0)
                    {
                        b->last_window_text_height = b->text_height + b->text_offset_y;
                        b->last_page_flag = 1;
                    }
                }
            }

            if (b->text_offset_y < b->edit_height - b->text_height)
            {
                b->text_offset_y = b->edit_height_displayed_lines - b->text_height;
            }
        }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box(b);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    }
    
    if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    }
    
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_next_line_in_paging
 * DESCRIPTION
 *  show the next line of current page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_next_line_in_paging(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {

        fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
        if (fh <= 0)
        {
            fh = 1;
        }
        if ((b->text_offset_y) > (-(b->text_height - b->edit_height)))
        {
            if (b->ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE && b->scroll_speed != 0 &&
                b->next_line_scroll_flag == 0)
            {
                b->text_offset_y -= (fh * b->scroll_speed) / GUI_SCROLL_STEPS_LINE_BY_LINE;     /* ritesh */

            }
            else
            {
                b->text_offset_y -= fh;
                b->next_line_scroll_flag = 0;
            }
            /* if text_offset_y reaches to the height of last page -  currently dispalyed height then we need next page */
            if (b->text_offset_y <=
                -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
                  b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
            {
                if (b->last_page_id > 0 && (b->end_id <= b->last_page_id - 1))
                {
                    b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                    gui_paging_multi_line_input_box_get_next_page_callback(b);
                }
            }
            if (b->text_offset_y < b->edit_height - b->text_height)
            {
                b->text_offset_y = b->edit_height - b->text_height;
            }
            
            if (b->text_offset_y > 0)
                b->text_offset_y = 0;
        }
    }
    else
    {
        gui_multi_line_input_box_next_line(b);
        if (b->text_offset_y <=
            -(b->page_details[PAGE_ZERO].page_height + b->page_details[PAGE_ONE].page_height +
            b->page_details[PAGE_TWO].page_height - b->edit_height_displayed_lines))
        {
            if (b->last_page_id > 0 && (b->end_id <= b->last_page_id - 1))
            {
                b->text_offset_y += b->page_details[PAGE_ZERO].page_height;
                gui_paging_multi_line_input_box_get_next_page_callback(b);
            }
        }
        
        if (b->text_offset_y < b->edit_height - b->text_height)
        {
            b->text_offset_y = b->edit_height - b->text_height;
        }

        if (b->text_offset_y > 0)
            b->text_offset_y = 0;
    }

    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multi_line_input_box_previous_line_in_paging
 * DESCRIPTION
 *  show the previous line of current page
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_multi_line_input_box_previous_line_in_paging(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh;

    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(b->text_font);
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        if (b->text_offset_y < 0)
        {
            fh = gui_get_character_height() + 1;    /* +1 added for 1 pixel gap between lines */
            b->text_offset_y += fh;
            if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines)) /* if text_offset_y reaches to height of page at 0th index */
            {
                gui_paging_multi_line_input_box_get_previous_page_callback(b);
                if (b->page_details[0].page_id != PAGE_ZERO)
                {
                    b->text_offset_y -= b->page_details[PAGE_ZERO].page_height;
                    b->page_details[PAGE_ZERO].page_id = b->start_id;
                    /*
                     * to maintain the text relocation issue we save the height of page at 0th index before a new page entry.According to 
                     * paging algorithm,after a new page entry ,page at 0th index will come to index 1 of the buffer.If the height of the saved value differs 
                     * with the height of page at index 1 then this condition will be tested
                     */
                    if (b->page_zero_prev_height != b->page_details[PAGE_ONE].page_height)
                    {
                        b->text_offset_y -= fh;
                    }
                }
            }

            if (b->text_offset_y > 0)
            {
                b->text_offset_y = 0;
            }
        }
    }
    else
    {
        gui_multi_line_input_box_previous_line(b);
        if (b->text_offset_y >= -(b->page_details[PAGE_ZERO].page_height - b->edit_height_displayed_lines)) /* if text_offset_y reaches to height of page at 0th index */
        {
            gui_paging_multi_line_input_box_get_previous_page_callback(b);
            if (b->page_details[0].page_id != PAGE_ZERO)
            {
                b->page_details[PAGE_ZERO].page_id = b->start_id;
            }
        }

        if (b->text_offset_y > 0)
        {
           b->text_offset_y = 0;
        } 
    }

    UI_UNUSED_PARAMETER(dummy_c);
}
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_toggle_insert_mode(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_end(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_PREVIOUS_CHARACTER(last_position_p, current_character);
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    current_position = saved_current_position;
    /* Move cursor forwards until a break character is encountered */
    if (current_position >= last_position_p)
    {
        done = 1;
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            done = 1;
            b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
        else
        {
            done = 0;
            b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        }
    }

    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    b->cursor_p = current_position;
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_start(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    UI_buffer_type last_position_p = b->last_position_p;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if (current_position >= last_position_p)
        {
            break;
        }
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
            break;
        }
    }
    b->highlight_end_position = current_position;
    current_position = saved_current_position;
    /* Move cursor backwards until a break character is encountered   */
    if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
    UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (bflag)
    {
        UI_STRING_GET_NEXT_CHARACTER(current_position, current_character);
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }

    while (!done)
    {
        previous_position = current_position;
        if (current_position == b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        count++;
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    b->cursor_p = previous_position;
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(b);
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_highlight_cursor_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [IN]        Is the multi-line inputbox object
 *  n       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_multi_line_input_box_highlight_cursor_number(multi_line_input_box *b, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type saved_current_position = b->cursor_p;
    UI_buffer_type current_position = b->cursor_p;
    UI_buffer_type previous_position;
    U8 done = 0, bflag = 0;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   #ifdef __MMI_INDIC_ALG__
        /* PMT START MAUI_00025775 */
        if (cursor_pos_flag)
        {
           n+=saved_multi_line_skip_moves;
           

        }
    #endif /* __MMI_INDIC_ALG__ */

       if (current_position == b->text)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    b->highlight_end_position = current_position;
    /* Move cursor backwards until n characters count out or a break character is encountered    */
    while (!done)
    {
        previous_position = current_position;
        if (n <= 0)
        {
            break;
        }
        if (current_position <= b->text)
        {
            break;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(current_position, current_character);
        UI_MULTI_LINE_INPUT_BOX_BREAK_CHARACTER(current_character, bflag) if (bflag)
        {
            break;
        }
        count++;
        n--;
    }

    b->highlight_start_position = previous_position;
    b->cursor_p = saved_current_position;
    if (current_position == b->cursor_p)
    {
        b->flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if (!(bflag && (count == 0)))
    {
        b->flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    b->highlight_start_position = previous_position;
    
    if (b->show_action_flag)
    {
        gui_show_multi_line_input_box(b);
    }
    
    b->flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    return (count);
}

/* GUI: dialer input box functions              */

UI_dialer_input_box_theme *current_dialer_input_box_theme = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_set_dialer_input_box_current_theme
 * DESCRIPTION
 *  Applies the current theme for the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_dialer_input_box_current_theme(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_color = current_dialer_input_box_theme->normal_text_color;
    b->background_filler = current_dialer_input_box_theme->normal_filler;
    b->selection_color = current_dialer_input_box_theme->selection_color;
    b->selection_text_color = current_dialer_input_box_theme->selection_text_color;
    b->cursor_color = current_dialer_input_box_theme->cursor_color;
    b->text_font = current_dialer_input_box_theme->text_font;
    b->text_gap = current_dialer_input_box_theme->text_gap;
    b->flags |= current_dialer_input_box_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_dialer_input_box_theme
 * DESCRIPTION
 *  Applies the given theme to the single-line inputbox.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_dialer_input_box_theme(dialer_input_box *b, UI_dialer_input_box_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_color = t->normal_text_color;
    b->background_filler = t->normal_filler;
    b->selection_color = t->selection_color;
    b->selection_text_color = t->selection_text_color;
    b->cursor_color = t->cursor_color;
    b->text_font = t->text_font;
    b->text_gap = t->text_gap;
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_clear
 * DESCRIPTION
 *  Initilaize dialer input box to defualtr
 * PARAMETERS
 *  b       [IN]        Is the dialer inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_clear(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        b->text_length = 0;
        b->allocated_length = 0;
        b->available_length = 0;
    }
    else
    {
        b->text[0] = '\0';
        b->text[1] = 0;
        b->text_length = 2;
    }
    b->current_text_p = b->text;
    b->last_position_p = b->text;
    b->UCS2_count = 0;
    if (b->flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        b->available_length = b->allocated_length;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_dialer_input_box
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  The buffer is automatically allocated by the inputbox.
 *  The buffer is set to blank on creation of this object.
 *  See also gui_destroy_dialer_input_box()
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the inputbox
 *  height      [IN]        Is the height of the inputbox
 *  length      [IN]        Is the length of the buffer to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_dialer_input_box(dialer_input_box *b, S32 x, S32 y, S32 width, S32 height, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) gui_malloc(length * sizeof(UI_character_type));
    b->allocated_length = length;
    b->available_length = length;

    gui_dialer_input_box_clear(b);
    b->current_text_p = b->text;
    b->flags = 0;
    gui_set_dialer_input_box_current_theme(b);
    b->validation_callback = UI_dummy_validation_function;
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->UCS2_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_dialer_input_box_use_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer is set to blank on creation of this object.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object (pre-allocated)
 *  x           [IN]        Is the left-top corner
 *  y           [IN]        Is the left-top corner
 *  width       [IN]        Is the width of the inputbox
 *  height      [IN]        Is the height of the inputbox
 *  buffer      [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length      [IN]        Is the length of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_dialer_input_box_use_buffer(
        dialer_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->allocated_length = length;
    b->available_length = length;
    b->flags = 0;
    gui_dialer_input_box_clear(b);
    b->current_text_p = b->text;
    gui_set_dialer_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
    b->UCS2_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_dialer_input_box_set_buffer
 * DESCRIPTION
 *  Creates a single line input box
 *  
 *  The object should be allocated before calling this function.
 *  Also, the buffer should be allocated and passed to this function.
 *  The buffer retains the string passed.
 * PARAMETERS
 *  b                   [IN]        Is the single-line inputbox object (pre-allocated)
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 *  width               [IN]        Is the width of the inputbox
 *  height              [IN]        Is the height of the inputbox
 *  buffer              [IN]        Is the buffer the inputbox should use (pre-allocated)
 *  length              [IN]        Is the length of the buffer
 *  text_length         [IN]        
 *  edit_position       [IN]        Is the cursor_position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_dialer_input_box_set_buffer(
        dialer_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type text;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->text = (UI_buffer_type) buffer;
    b->current_text_p = b->text;
    b->allocated_length = length;
    b->available_length = length;
    b->UCS2_count = 0;
    if (b->text != NULL)
    {
        text = b->text;
        for (i = 0; i < edit_position; i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        b->current_text_p = text;
        for (i = edit_position; !UI_STRING_END_OF_STRING_CHARACTER(dummy_c); i++)
        {
            UI_STRING_GET_NEXT_CHARACTER(text, dummy_c);
            UI_TEST_UCS2_INCREMENT_COUNT(dummy_c, b->UCS2_count);
        }
        b->text_length = text_length;
        b->last_position_p = b->current_text_p;
    }
    else    /* b->text!=NULL */
    {
        b->text_length = 0;
    }
    b->flags = 0;
    gui_set_dialer_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    b->validation_callback = UI_dummy_validation_function;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_dialer_input_box
 * DESCRIPTION
 *  Moves a single line input box
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object (pre-allocated)
 *  x       [IN]        Is the left-top corner
 *  y       [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_dialer_input_box(dialer_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_show_cursor
 * DESCRIPTION
 *  Displays the cursor in a single-line inputbox (internal function)
 *  
 *  This function is used internally.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  x           [IN]        Is the left-top corner of the cursor
 *  y           [IN]        Is the left-top corner of the cursor
 *  height      [IN]        Is the height of cursor
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_show_cursor(dialer_input_box *b, S32 x, S32 y, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = b->cursor_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_BLINKING_CURSOR_SUPPORT)
    if (y > (b->y + b->height) || (y + height) < b->y)
        StopTimer(BLINKING_CURSOR);
    else
        UI_inputbox_pre_show_cursor(x, y, x + 1, y + height - 1, c);
#else 
    UI_inputbox_pre_show_fixed_cursor(x, y, x+1, y+height-1, c);
#endif 
}

/* MTK Elvis for color dialing font */


/*****************************************************************************
 * FUNCTION
 *  gui_get_dialing_font_color
 * DESCRIPTION
 *  get dialing font color
 * PARAMETERS
 *  c       [IN]        Is the single-line inputbox object
 * RETURNS
 *  color
 *****************************************************************************/
color gui_get_dialing_font_color(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nIdx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (nIdx = 0; color_dialing_font_map[nIdx].ch; nIdx++)
    {
        if (color_dialing_font_map[nIdx].ch == c)
        {
            return color_dialing_font_map[nIdx].c;
        }
    }
    return color_dialing_font_map[nIdx].c;
}




/*****************************************************************************
 * FUNCTION
 *  gui_show_dialer_input_box
 * DESCRIPTION
 *  Displays a single-line inputbox
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialer_input_box(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_dialer_input_box_ext(b, (-1), (-1));
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_dialer_input_box_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialer_input_box_ext(dialer_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    UI_filled_area *f = b->background_filler;
    U8 selection_flag = 0;

#if(0)
   byte             overwrite_mode_flag=0;
#endif /* (0) */ 
    UI_character_type current_character;
    S32 character_width = 0;
    UI_buffer_type previous_text_p;
    UI_buffer_type current_text_p = b->text;
    U32 flags = b->flags;
    S32 text_x, right_x, text_y, character_height;
    U8 cursor_displayed_flag = 0;
    U8 cusrsor_set_flag = 0;
    S32 text_gap = b->text_gap;
    color b_normal_text_color = b->text_color;
    color b_selection_text_color = b->selection_text_color;
    color b_selection_color = b->selection_color;

    /* UI_character_type  mask_character=b->mask_character; */
    UI_buffer_type b_current_text_p = b->current_text_p;
    UI_buffer_type b_text = b->text;
    b->first_position_p = b->text;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;
    y1 = b->y;
    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(x1, y1, x2, y2, f);
    gui_set_text_clip(x1, y1, x2, y2);
    gui_set_font(b->text_font);
    
    character_width = gui_get_character_width(0x31);
    right_x = (b->width % (character_width + text_gap))/2;
    if (right_x == 0)
        right_x = (character_width + text_gap)/2;
    
    b->n_lines = 1;

    if (current_text_p != NULL)
    {
        if (flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
        {
            selection_flag = 1;
        }
    #if(0)
      if((flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE) && (!selection_flag))
      {
         overwrite_mode_flag=1;
      }
    #endif /* (0) */ 
        character_height = gui_get_character_height();
        current_character = (UI_character_type) - 1;
    #if(0)
      while(!UI_STRING_END_OF_STRING_CHARACTER(current_character))
      {
         UI_STRING_GET_NEXT_CHARACTER(current_text_p,current_character);
      }
      UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p,current_character);
      b->last_position_p=current_text_p;
    #else /* (0) */ 
        current_text_p = b->last_position_p;
    #endif /* (0) */ 
        text_x = x2 - right_x;
        /* start vijay 20050228, for touch dial screen */
    #if( defined(__MMI_TOUCH_DIAL_SCREEN__))
        text_y = y2 - character_height + 2;
    #else 
        text_y = y2 - character_height - 1; /* previous implementation */
    #endif 
        /* end vijay */
        if (b_text != current_text_p)
        {
            gui_set_text_color(b_normal_text_color);
            while (current_text_p != b_text)
            {
                previous_text_p = current_text_p;
                UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
                character_width = gui_get_character_width(current_character);
                if ((text_x - (character_width + text_gap)) <= x1)
                {
                    b->n_lines++;   /* vandana */
                    text_x = x2 - right_x;
                    text_y -= character_height;
                    if (text_y < y1)
                    {
                        b->first_position_p = previous_text_p + 2;
                        break;
                    }
                }
                if ((-1) == move_to_x && (-1) == move_to_y)
                {
                    if (previous_text_p == b_current_text_p)
                    {
                        if (selection_flag)
                        {
                            text_x -= (character_width + text_gap);
                            gui_fill_rectangle(
                                text_x,
                                text_y - 1,
                                text_x + character_width-1,
                                text_y + character_height-1,
                                b_selection_color);
                            gui_set_text_color(b_selection_text_color);
                            /* MTK Elvis for R2L characters */
                            if (r2lMMIFlag)
                            {
                                gui_move_text_cursor(text_x + character_width, text_y);
                            }
                            else
                            {
                                gui_move_text_cursor(text_x, text_y);
                            }
                            
                            gui_print_character(current_character);
                            gui_set_text_color(b_normal_text_color);
                            cursor_displayed_flag = 1;
                        }
                        else
                        {
                            if (!cursor_displayed_flag)
                            {
                                if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW) &&
                                    !(flags & UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW))
                                {
                                    if (flags & UI_DIALER_INPUT_BOX_SHOW_BLOCK_CURSOR)
                                    {
                                        gui_fill_rectangle(
                                            text_x,
                                            text_y - 1,
                                            text_x + character_width,
                                            text_y + character_height,
                                            b_selection_color);
                                    }
                                    else
                                    {
                                        gui_dialer_input_box_show_cursor(b, text_x - 1, text_y - 1, character_height);
                                        b->cursor_x = (text_x - 1);
                                        b->cursor_y = (text_y - 1);
                                    }
                                }
                                cursor_displayed_flag = 1;
                            }
                            text_x -= (character_width + text_gap);
                            /* MTK Elvis for R2L characters */
                            if (r2lMMIFlag)
                            {
                                gui_move_text_cursor(text_x + character_width, text_y);
                            }
                            else
                            {
                                gui_move_text_cursor(text_x, text_y);
                            }
                            //MTK end
                            //MTK Elvis for color dialling font
                        #ifdef __MMI_COLOR_DIALLING_FONT__
                            gui_set_text_color(gui_get_dialing_font_color(current_character));
                        #endif 
                            
                            gui_print_character(current_character);
                        }
                    }
                #if(0)
            else if(overwrite_mode_flag && (current_text_p==b_current_text_p))
            {
               text_x-=(character_width+text_gap);
               pixtel_UI_fill_rectangle(text_x,text_y-1,text_x+character_width,text_y+character_height,b_selection_color);
               pixtel_UI_set_text_color(b_selection_text_color);
               pixtel_UI_move_text_cursor(text_x,text_y);
               pixtel_UI_print_character(current_character);
               pixtel_UI_set_text_color(b_normal_text_color);
               cursor_displayed_flag=1;
            }
                #endif /* (0) */ 
                    else    /* previous_text_p==b_current_text_p */
                    {
                        text_x -= (character_width + text_gap);
                        /* MTK Elvis for R2L characters */
                        if (r2lMMIFlag)
                        {
                            gui_move_text_cursor(text_x + character_width, text_y);
                        }
                        else
                        {
                            gui_move_text_cursor(text_x, text_y);
                        }
                        

                        /* MTK Elvis for color dialling font */
                    #ifdef __MMI_COLOR_DIALLING_FONT__
                        gui_set_text_color(gui_get_dialing_font_color(current_character));
                    #endif 
                        
                        gui_print_character(current_character);
                    }
                }
                else    /* (-1) == move_to_x && (-1) == move_to_y */
                {
                    text_x -= (character_width + text_gap);
                    if (((text_x) < move_to_x) && ((text_y + character_height) >= move_to_y) && (text_y < move_to_y) &&
                        (!cusrsor_set_flag))
                    {
                        b->cursor_x = text_x - 1;
                        b->cursor_y = text_y - 1;
                        b->current_text_p = previous_text_p;
                        cusrsor_set_flag = 1;
                    }
                }
            }
        }
        if (!cursor_displayed_flag && ((-1) == move_to_x) && ((-1) == move_to_y))
        {
            if (!(flags & UI_DIALER_INPUT_BOX_DISABLE_DRAW) && !(flags & UI_DIALER_INPUT_BOX_DISABLE_CURSOR_DRAW))
            {
                if (flags & UI_DIALER_INPUT_BOX_SHOW_BLOCK_CURSOR)
                {
                    gui_fill_rectangle(
                        text_x,
                        text_y - 1,
                        text_x + character_width,
                        text_y + character_height,
                        b_selection_color);
                }
                else
                {
                    gui_dialer_input_box_show_cursor(b, text_x - 1, text_y - 1, character_height);
                    b->cursor_x = (text_x - 1);
                    b->cursor_y = (text_y - 1);
                }
            }
        }
        if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!cusrsor_set_flag))
        {
            b->cursor_x = text_x - 1;
            b->cursor_y = text_y - 1;
            b->current_text_p = current_text_p;
            cusrsor_set_flag = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_destroy_dialer_input_box
 * DESCRIPTION
 *  frees the buffer allocated for the box and resets the input box
 *  
 *  This doesn't free the single-line inputbox object. It only
 *  frees the buffer that is used to store the text.
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_destroy_dialer_input_box(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_length = 0;
    b->allocated_length = 0;
    b->available_length = 0;
    b->UCS2_count = 0;
    gui_free(b->text);
    b->current_text_p = b->text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_inputbox_locate_cursor
 * DESCRIPTION
 *  locate cursor positin of dialer input box
 *  
 *  This doesn't free the single-line inputbox object. It only
 *  frees the buffer that is used to store the text.
 * PARAMETERS
 *  b       [IN]        Is the dialer inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_inputbox_locate_cursor(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c = (UI_character_type) - 1;
    UI_buffer_type current_text_p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, c);
    }
    b->last_position_p = current_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_character
 * DESCRIPTION
 *  Deletes a character before the current cursor position (Backspace)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    if (previous_text_p == b->text)
    {
        UI_editor_play_tone_cannot_change();
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(previous_text_p, dummy_c);
    b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
    b->current_text_p = previous_text_p;
    if (b->flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
    {
        UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(dummy_c, b->UCS2_count, b->allocated_length, b->available_length);
    }
    while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
        UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
    }
    if (b->flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
    {
        b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(b->last_position_p, current_character);
    /* gui_dialer_inputbox_locate_cursor(b); */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the current cursor position (Delete)
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_current_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p;
    UI_buffer_type previous_text_p;
    UI_character_type current_character = (UI_character_type) - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_text_p = b->current_text_p;
    previous_text_p = b->current_text_p;
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        if (b->flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
        {
            UI_TEST_UCS2_DECREMENT_COUNT_SET_LENGTH(
                current_character,
                b->allocated_length,
                b->UCS2_count,
                b->available_length);
        }
        while (!UI_STRING_END_OF_STRING_CHARACTER(current_character))
        {
            UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
            UI_STRING_INSERT_CHARACTER(previous_text_p, current_character);
        }
        b->text_length -= ((S32) current_text_p - (S32) previous_text_p);
        if (b->flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP)
        {
            b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
        }
        UI_STRING_GET_PREVIOUS_CHARACTER(b->last_position_p, current_character);
        /* gui_dialer_inputbox_locate_cursor(b); */
        b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
        b->change_callback();
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_delete_all
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_delete_all(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    UI_buffer_type p = b->text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(p, c);
    UI_UNUSED_PARAMETER(c);
    /* MTK Elvis 20040611 donot play tone while the text buffer is zero */

    gui_dialer_input_box_clear(b);
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between Insert and Overwrite modes
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_toggle_insert_mode(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_DIALER_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_DIALER_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_insert_character
 * DESCRIPTION
 *  Inserts a character at the current cursor position
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_insert_character(dialer_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) && UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();
            return;
        }
        else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone */
            return;
        }
    }
    p1 = p2 = b->current_text_p;
    if (b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
    {
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
        if ((p1 == b->last_position_p) && ((b->text_length) >= b->available_length))
        {
            return;
        }
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->current_text_p = p2;
        }
        else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);   /* get previous character */
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);       /* insert character */
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                    {
                        if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                        {
                            UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                        else
                        {
                            UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                    }
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))       /* check for end of string */
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    b->text_length += ((S32) p2 - (S32) p1);
                    UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
                p1 = b->current_text_p;
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))   /* check for end of string */
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);    /* get next character */
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
    }
    else    /* b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE */
    {
        if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
        {
            if ((b->text_length) >= (b->available_length))
            {
                UI_buffer_type p3, p4;
                UI_character_type cc;

                if (b->current_text_p != b->text)
                {
                    p3 = p4 = b->text;
                    UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                    while (p3 != b->current_text_p)
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        UI_STRING_INSERT_CHARACTER(p4, cc);
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                    UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                }
            }
            else    /* (b->text_length)>=(b->available_length) */
            {
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
                UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
            }
        }
        else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
        {
            if ((b->text_length) >= (b->available_length))
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(c, b->UCS2_count, b->allocated_length, b->available_length);
                }
            }
            while (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                UI_STRING_INSERT_CHARACTER(p2, c);
                c = old_c;
            }
            UI_STRING_INSERT_CHARACTER(p2, c);
            b->text_length += ((S32) p2 - (S32) p1);
            UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
        }
    }
    /* gui_dialer_inputbox_locate_cursor(b); */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_overflow
 * DESCRIPTION
 *  check ifor overfloaw of dialer input box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_overflow(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->text_length) >= (b->available_length))
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_first_position
 * DESCRIPTION
 *  check if current cursorposition is at first character
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_first_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->current_text_p == b->text)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_position
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_character_position
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_character_position(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_test_last_position_overflow
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  byte
 *****************************************************************************/
U8 gui_dialer_input_box_test_last_position_overflow(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag1 = 0;
    U8 flag2 = 0;
    UI_character_type dummy_c = 0;
    UI_buffer_type current_text_p = b->current_text_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, dummy_c);
    UI_UNUSED_PARAMETER(dummy_c);
    if (current_text_p == b->last_position_p)
    {
        flag1 = 1;
    }
    if ((b->text_length) >= (b->available_length))
    {
        flag2 = 1;
    }
    if (flag1 && flag2)
    {
        return (1);
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_get_text_length
 * DESCRIPTION
 *  return text length of dialer nut box
 * PARAMETERS
 *  b       [IN]        Is the dialer input box object
 * RETURNS
 *  S32 return txt length of dialer iput box
 *****************************************************************************/
S32 gui_dialer_input_box_get_text_length(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((b->text_length) >> 1) - 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_insert_multitap_character
 * DESCRIPTION
 *  Inserts a multitap character at the current cursor position
 *  
 *  This function is normally used as the input_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_insert_multitap_character(dialer_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type p1, p2;
    UI_character_type old_c, dummy_c = 0;
    U32 b_flags = b->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH) && (b->UCS2_count == 0) && UI_TEST_UCS2_CHARACTER(c))
    {
        if ((b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER) &&
            (b->text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(b->available_length)))
        {
            UI_editor_play_tone_cannot_insert();    /* play error tone of cannot insert */
            return;
        }
        else if (b->text_length >= UI_UCS2_STRING_HALF_LENGTH(b->available_length))
        {
            UI_editor_play_tone_cannot_insert();
            return;
        }
    }

    if ((b_flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP) && (b->current_text_p != b->text))
    {
        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        p1 = p2 = b->current_text_p;
        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
        if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
        {
            UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
            if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
            {
                if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
                else
                {
                    UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                        old_c,
                        c,
                        b->UCS2_count,
                        b->allocated_length,
                        b->available_length);
                }
            }
            b->current_text_p = p2;
        }
        else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);   /* get next character */
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    p1 = b->current_text_p;
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))       /* check for end of string */
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);        /* get next character */
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                    {
                        if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                        {
                            UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                                old_c,
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                        else
                        {
                            UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                                old_c,
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                    }
                    b->text_length += ((S32) p2 - (S32) p1);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                p1 = b->current_text_p;
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->text_length += ((S32) p2 - (S32) p1);
            }
        }
    }
    else    /* (b_flags & UI_DIALER_INPUT_BOX_STATE_MULTITAP) && (b->current_text_p!=b->text) */
    {
        p1 = p2 = b->current_text_p;
        if (b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE)
        {
            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
            if ((p1 == b->last_position_p) && ((b->text_length) >= b->available_length))
            {
                if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);   /* get next character */
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                    return;
                }
                else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
                {
                    UI_editor_play_tone_cannot_insert();    /* play error tone of cannot insert */
                    return;
                }
            }
            if (!UI_STRING_END_OF_STRING_CHARACTER(old_c))  /* check for end of string */
            {
                UI_STRING_INSERT_CHARACTER(p2, c);
                if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                            old_c,
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                b->current_text_p = p2;
            }
            else    /* !UI_STRING_END_OF_STRING_CHARACTER(old_c) */
            {
                if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
                {
                    if ((b->text_length) >= (b->available_length))
                    {
                        UI_buffer_type p3, p4;
                        UI_character_type cc;

                        if (b->current_text_p != b->text)
                        {
                            p3 = p4 = b->text;
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);       /* get */
                            while (p3 != b->current_text_p)
                            {
                                UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                                UI_STRING_INSERT_CHARACTER(p4, cc);
                            }
                            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                            UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                        }
                    }
                    else    /* (b->text_length)>=(b->available_length) */
                    {
                        p1 = b->current_text_p;
                        UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                        while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                            UI_STRING_INSERT_CHARACTER(p2, c);
                            c = old_c;
                        }
                        UI_STRING_INSERT_CHARACTER(p2, c);  /* insert character */
                        if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                        {
                            if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                            {
                                UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                                    old_c,
                                    c,
                                    b->UCS2_count,
                                    b->allocated_length,
                                    b->available_length);
                            }
                            else
                            {
                                UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                                    old_c,
                                    c,
                                    b->UCS2_count,
                                    b->allocated_length,
                                    b->available_length);
                            }
                        }
                        b->text_length += ((S32) p2 - (S32) p1);
                    }
                }
                else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
                {
                    if ((b->text_length) >= (b->available_length))
                    {
                        UI_editor_play_tone_cannot_insert();
                        return;
                    }
                    p1 = b->current_text_p;
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);  /* insert chatracte */
                    if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                    {
                        if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                        {
                            UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH_TYPE2(
                                old_c,
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                        else
                        {
                            UI_TEST_UCS2_CHANGE_COUNT_SET_LENGTH(
                                old_c,
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                    }
                    b->text_length += ((S32) p2 - (S32) p1);
                }
            }
        }
        else    /* b_flags & UI_DIALER_INPUT_BOX_OVERWRITE_MODE */
        {
            if (b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE)
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_buffer_type p3, p4;
                    UI_character_type cc;

                    if (b->current_text_p != b->text)
                    {
                        p3 = p4 = b->text;
                        UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                        while (p3 != b->current_text_p)
                        {
                            UI_STRING_GET_NEXT_CHARACTER(p3, cc);
                            UI_STRING_INSERT_CHARACTER(p4, cc);
                        }
                        UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
                        UI_STRING_INSERT_CHARACTER(b->current_text_p, c);
                    }
                }
                else    /* (b->text_length)>=(b->available_length) */
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                    if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                    {
                        if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                        {
                            UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                        else
                        {
                            UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(
                                c,
                                b->UCS2_count,
                                b->allocated_length,
                                b->available_length);
                        }
                    }
                    while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                        UI_STRING_INSERT_CHARACTER(p2, c);
                        c = old_c;
                    }
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    b->text_length += ((S32) p2 - (S32) p1);
                    UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
                }
            }
            else    /* b_flags & UI_DIALER_INPUT_BOX_CHARACTER_QUEUE */
            {
                if ((b->text_length) >= (b->available_length))
                {
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
                UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
                if (b_flags & UI_DIALER_INPUT_BOX_USE_ENCODING_BASED_LENGTH)
                {
                    if (b_flags & UI_DIALER_INPUT_BOX_ONE_LESS_CHARACTER)
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH_TYPE2(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                    else
                    {
                        UI_TEST_UCS2_INCREMENT_COUNT_SET_LENGTH(
                            c,
                            b->UCS2_count,
                            b->allocated_length,
                            b->available_length);
                    }
                }
                while (!UI_STRING_END_OF_STRING_CHARACTER(c))
                {
                    UI_STRING_GET_NEXT_CHARACTER(p1, old_c);
                    UI_STRING_INSERT_CHARACTER(p2, c);
                    c = old_c;
                }
                UI_STRING_INSERT_CHARACTER(p2, c);
                b->text_length += ((S32) p2 - (S32) p1);
                UI_STRING_GET_NEXT_CHARACTER(b->last_position_p, dummy_c);
            }
        }
        b->flags |= UI_DIALER_INPUT_BOX_STATE_MULTITAP;
    }
    /* gui_dialer_inputbox_locate_cursor(b); */
    b->validation_callback(b->text, b->current_text_p, (b->text_length >> 1) - 1);
    b->change_callback();
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_confirm_multitap_character
 * DESCRIPTION
 *  Completes the multitap input sequence.
 *  
 *  This function is normally used as the input_complete_callback
 *  function with multitap input objects
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_confirm_multitap_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_DIALER_INPUT_BOX_STATE_MULTITAP;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_previous
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_previous(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    if (b->current_text_p == b->text)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
    if (b->current_text_p < b->first_position_p)
        b->current_text_p = b->first_position_p;
    UI_UNUSED_PARAMETER(dummy_c);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_next
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  b       [IN]        Is the single-line inputbox object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_next(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p;
    UI_character_type current_character;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
    b->current_text_p = current_text_p;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_dialer_input_box
 * DESCRIPTION
 *  Changes the size of the single-line inputbox.
 * PARAMETERS
 *  b           [IN]        Is the single-line inputbox object
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_dialer_input_box(dialer_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_goto_first_character
 * DESCRIPTION
 *  go to first charcter of dialer input box
 * PARAMETERS
 *  b       [IN]        Dialer input bx
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_goto_first_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_goto_last_character
 * DESCRIPTION
 *  go to last charcter of dialer input box
 * PARAMETERS
 *  b       [IN]        Dialer input bx
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_goto_last_character(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type dummy_c = 0;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->current_text_p = b->text;
    if (b->text != NULL)
    {
        while (!done)
        {
            UI_STRING_GET_NEXT_CHARACTER(b->current_text_p, dummy_c);
            if (UI_STRING_END_OF_STRING_CHARACTER(dummy_c))
            {
                break;
            }
        }
        if (b->current_text_p != b->text)
        {
            UI_STRING_GET_PREVIOUS_CHARACTER(b->current_text_p, dummy_c);
        }
    }
}

/* Interfaces to play error tones in the editors   */

#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "KeyBrd.h"

U8 UI_editor_tones_flag = 1;


/*****************************************************************************
 * FUNCTION
 *  UI_editor_play_tone_cannot_change
 * DESCRIPTION
 *  play tone of cannot change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_play_tone_cannot_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!UI_editor_tones_flag)
    {
        return;
    }
    StopCurrentKeyPadTone();
    playRequestedTone(ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_play_tone_cannot_navigate
 * DESCRIPTION
 *  play tone of cannot navigate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_play_tone_cannot_navigate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!UI_editor_tones_flag)
    {
        return;
    }
    StopCurrentKeyPadTone();
    playRequestedTone(ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_play_tone_cannot_insert
 * DESCRIPTION
 *  play tone of cannot insert error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
#include "globaldefs.h"
#include "t9def.h"
#endif /* __MMI_POPUP_REACH_MAX_LENGTH_MSG__ */ 
void UI_editor_play_tone_cannot_insert(void)
{
#ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_INPUT_METHOD_REACH_MAX_LEN), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
#else /* __MMI_POPUP_REACH_MAX_LENGTH_MSG__ */ 
    if (!UI_editor_tones_flag)
    {
        return;
    }
    StopCurrentKeyPadTone();
    playRequestedTone(ERROR_TONE);
#endif /* __MMI_POPUP_REACH_MAX_LENGTH_MSG__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_play_tone_invalid_data
 * DESCRIPTION
 *  play tone of invalid data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_play_tone_invalid_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!UI_editor_tones_flag)
    {
        return;
    }
    StopCurrentKeyPadTone();    /* stop cuurent tone */
    playRequestedTone(ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_disable_tones
 * DESCRIPTION
 *  disable editor tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_disable_tones(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_editor_tones_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_editor_enable_tones
 * DESCRIPTION
 *  enabel editor tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_editor_enable_tones(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_editor_tones_flag = 1;
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
/* Check the chracter for WCSS permitted input character */


/*****************************************************************************
 * FUNCTION
 *  UI_check_WCSS_normal_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c               [IN]        
 *  input_type      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S8 UI_check_WCSS_normal_character(UI_character_type c, U8 *input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((UI_character_type) c == (UI_character_type) 0x41))    /* 'A' */
    {
        *input_type = INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x61))       /* 'a' */
    {
        *input_type = INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x4E))       /* 'N' */
    {
        *input_type = INPUT_MODE_123;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x6E))       /* 'n' */
    {
        *input_type = INPUT_MODE_123_SYMBOLS;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x58))       /* 'X' */
    {
        *input_type = INPUT_MODE_MULTITAP_UPPERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x78))       /* 'x' */
    {
        *input_type = INPUT_MODE_MULTITAP_LOWERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x4D))       /* 'M' */
    {
        *input_type =
            INPUT_MODE_MULTITAP_UPPERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER |
            PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED;
        return 1;
    }
    else if (((UI_character_type) c == (UI_character_type) 0x6D))       /* 'm' */
    {
        *input_type =
            INPUT_MODE_MULTITAP_LOWERCASE_ABC | PIXTEL_UI_WCSS_SPACE_DEFAULT_CHARACTER |
            PIXTEL_UI_ALL_INPUT_METHODS_ALLOWED;
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Insert default chracter 0 or ' ' according to input format character. */


/*****************************************************************************
 * FUNCTION
 *  UI_insert_WCSS_default_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 *UI_insert_WCSS_default_character(U8 *str, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (c)
    {
        case 0x41:
        case 0x61:
        case 0x58:
        case 0x78:
        case 0x4D:
        case 0x6D:
            c = 0x20;   /* ' ' */
            break;

        case 0x4E:
        case 0x6E:
            c = 0x30;   /* '0' */
            break;
        default:
            /* Keep default value of c */
            break;
    }
    (*((str))++) = (U8) (((c) & 0xff));
    (*((str))++) = (U8) (((c) >> 8));
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  gui_parse_WCSS_string
 * DESCRIPTION
 *  Parse the WCSS format string, check for invalid format and create default string.
 * PARAMETERS
 *  s1                  [IN]        IN input format
 *  s2                  [IN]        OUT   text buffer
 *  s3                  [IN]        OUT   parsed format (typically cat115buffer)
 *  str_len             [IN]        IN length of dchar including '\0'
 *  reserve_data        [IN]        IN whether history is present
 *  for(?)              [OUT]       Invalid format
 * RETURNS
 *  void
 *****************************************************************************/
S8 gui_parse_WCSS_string(U8 *s1, U8 *s2, U8 *s3, S16 str_len, U8 reserve_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c, dst_ch;
    U8 input_type;
    U8 *original_s2 = s2;
    U8 *prev_s2;
    U8 *original_s3 = s3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(s1, c) while (!UI_STRING_END_OF_STRING_CHARACTER(c) && str_len > 1)
    {
        if (UI_check_WCSS_normal_character(c, &input_type))
        {
            *s3++ = input_type;
            if (reserve_data == 0)
            {
                s2 = UI_insert_WCSS_default_character(s2, c);
            }
            else
            {
                /* Default string might be shorter than required by s1 (input format) */
                prev_s2 = s2;
                UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                if (dst_ch == 0)
                {
                    reserve_data = 0;
                    s2 = UI_insert_WCSS_default_character(prev_s2, c);
                }
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            str_len--;
        }
        else if (c == 0x5C) /* '\\' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                goto parse_error;
            }

            *s3++ = 0xff;   /* Not editable character */
            if (reserve_data == 0)
            {
                UI_STRING_INSERT_CHARACTER(s2, c);
            }
            else
            {
                /* Default string might be shorter than required by s1 (input format) */
                prev_s2 = s2;
                UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                if (dst_ch == 0)
                {
                    reserve_data = 0;
                    s2 = prev_s2;
                    UI_STRING_INSERT_CHARACTER(s2, c);
                }
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            str_len--;
        }
        else if (c == 0x2A) /* '*' */
        {
            S16 i = 0;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                goto parse_error;
            }

            for (i = 0; i < str_len - 1; i++)
            {
                /* Setup format only. No default value for * format */
                /* s2 = UI_insert_WCSS_default_character(s2, c); */
                *s3++ = input_type | PIXTEL_UI_WCSS_STAR_INPUT;
            }

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (!UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                goto parse_error;
            }
            c = 0;
            break;
        }
        else if ((c >= 0x31) && (c <= 0x39))    /* '1' - '9' */
        {
            S16 n = c - 0x30;
            S16 i = 0;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            while ((c >= 0x30) && (c <= 0x39))  /* '0' - '9' */
            {
                n *= 10;
                n += (c - 0x30);
                UI_STRING_GET_NEXT_CHARACTER(s1, c);
            }
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                goto parse_error;
            }

            if (n > str_len - 1)
            {
                goto parse_error;
            }

            for (i = 0; i < n; i++)
            {
                *s3++ = input_type;
                if (reserve_data == 0)
                {
                    s2 = UI_insert_WCSS_default_character(s2, c);
                }
                else
                {
                    /* Default string might be shorter than required by s1 (input format) */
                    prev_s2 = s2;
                    UI_STRING_GET_NEXT_CHARACTER(s2, dst_ch);
                    if (dst_ch == 0)
                    {
                        reserve_data = 0;
                        s2 = UI_insert_WCSS_default_character(prev_s2, c);
                    }
                }
            }

            str_len -= n;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else
        {
            goto parse_error;
        }
    }

    /* Buffer size smaller than required by input-format */
    if (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        goto parse_error;
    }

    *s3 = '\0';
    if (reserve_data == 0)
    {
        *s2++ = 0;
        *s2 = 0;
    }
    return 0;

  parse_error:
    *original_s3 = '\0';
    if (reserve_data == 0)
    {
        *original_s2++ = 0;
        *original_s2 = 0;
    }
    return (S8) (-1);
}


/*****************************************************************************
 * FUNCTION
 *  get_category_115_format_buffer_length
 * DESCRIPTION
 *  Get the exact length of WCSS input format buffer
 * PARAMETERS
 *  s1              [IN]        IN input format
 *  buffer_size     [IN]        IN maximum length of dchar including '\0'
 * RETURNS
 *  0        Variable length
 *  -1       Invalid format
 *  otherwise
 *****************************************************************************/
S32 get_category_115_format_buffer_length(U8 *s1, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c;
    U8 input_type;
    S32 special_char = 0;
    S32 format_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_STRING_GET_NEXT_CHARACTER(s1, c) while (!UI_STRING_END_OF_STRING_CHARACTER(c))
    {
        if (UI_check_WCSS_normal_character(c, &input_type))
        {
            format_length++;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else if (c == 0x5C) /* '\\' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c))
            {
                return -1;
            }
            special_char++;
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else if (c == 0x2A) /* '*' */
        {
            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                return -1;
            }
            else
            {
                if (format_length + special_char <= buffer_size - 1)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
        }
        else if ((c >= 0x31) && (c <= 0x39))    /* '1' - '9' */
        {
            S16 n = c - 0x30;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
            while ((c >= 0x30) && (c <= 0x39))  /* '0' - '9' */
            {
                n *= 10;
                n += (c - 0x30);
                UI_STRING_GET_NEXT_CHARACTER(s1, c);
            }
            if (UI_STRING_END_OF_STRING_CHARACTER(c) || (!UI_check_WCSS_normal_character(c, &input_type)))
            {
                return -1;
            }

            format_length += n;

            UI_STRING_GET_NEXT_CHARACTER(s1, c);
        }
        else
        {
            return -1;
        }
    }

    /* Note: we allow the case that format_length == 0. However, user cannot
       edit at all */
    if (format_length + special_char <= buffer_size - 1)
    {
        return (format_length + special_char);
    }
    else
    {
        return -1;
    }
}

#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#ifdef __MMI_TOUCH_DIAL_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_screen_translate_pen_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]         
 *  x                   [IN]        
 *  y                   [IN]        
 *  item_index          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_screen_translate_pen_position(dialing_keypad_struct *dialing_keypad, S32 x, S32 y, S32 *item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_height = 0, total_width = 0;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_height += dialing_keypad->keypad_y;
    total_width += dialing_keypad->keypad_x;
    *item_index = -1;   /* 053005 Calvin added for function key */

    for (i = 0; i < dialing_keypad->n_rows; i++)
    {
        total_height += dialing_keypad->key_height;
        if (total_height > y)
        {
            for (j = 0; j < dialing_keypad->n_column; j++)
            {
                total_width += dialing_keypad->key_width;
                if (total_width > x)
                {
                    *item_index = i * dialing_keypad->n_column + j + 1;
                    dialing_keypad->selected_key_x =
                        dialing_keypad->keypad_x + (dialing_keypad->key_width) * j +
                        (dialing_keypad->horizontal_gap) * j;
                    dialing_keypad->selected_key_y =
                        dialing_keypad->keypad_y + (dialing_keypad->key_height) * i +
                        (dialing_keypad->vertical_gap) * i;
                    dialing_keypad->key_type = *item_index;
                    break;
                }
                else
                {
                    total_width += dialing_keypad->horizontal_gap;
                    if (total_width > x)
                    {
                        *item_index = -1;
                        break;
                    }
                }

            }
            break;
        }
        else
        {
            total_height += dialing_keypad->vertical_gap;
            if (total_height > y)
            {
                *item_index = -1;
                break;
            }
        }
    }

    /* 053005 Calvin added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (*item_index != -1)
    {
        return;
    }

    total_height = dialing_keypad->keypad_func_y;
    total_width = dialing_keypad->keypad_func_x;

    if (x < dialing_keypad->keypad_func_x || y < dialing_keypad->keypad_func_y) /* 110105 dialing handle Calvin added */
    {
        return;
    }

    for (i = 0; i < dialing_keypad->func_n_rows; i++)
    {
        total_height += dialing_keypad->func_key_height;
        if (total_height > y)
        {
            for (j = 0; j < dialing_keypad->func_n_column; j++)
            {
                total_width += dialing_keypad->func_key_width;
                if (total_width > x)
                {
                    *item_index =
                        dialing_keypad->n_rows * dialing_keypad->n_column + i * dialing_keypad->func_n_column + j + 1;
                    dialing_keypad->selected_key_x =
                        dialing_keypad->keypad_func_x + (dialing_keypad->func_key_width) * j +
                        (dialing_keypad->func_horizontal_gap) * j;
                    dialing_keypad->selected_key_y =
                        dialing_keypad->keypad_func_y + (dialing_keypad->func_key_height) * i +
                        (dialing_keypad->func_vertical_gap) * i;
                    dialing_keypad->key_type = *item_index;
                    break;
                }
                else
                {
                    total_width += dialing_keypad->func_horizontal_gap;
                    if (total_width > x)
                    {
                        *item_index = -1;
                        return;
                    }
                }

            }
            break;
        }
        else
        {
            total_height += dialing_keypad->func_vertical_gap;
            if (total_height > y)
            {
                *item_index = -1;
                return;
            }
        }
    }
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    /* Calvin end */
}

/***********************************************************************
   __GDI_MEMORY_PROFILE_2__ is used to decide whether multilayer is on or off.
   if multilayer is enable, no buffer is used.
   we can use one layer for keypad bg image, and another for selected keys.
***********************************************************************/
#ifndef __GDI_MEMORY_PROFILE_2__
U8 key_buffer[(MMI_DIALING_KEY_WIDTH + 1) * (MMI_DIALING_KEY_HEIGHT + 1) * 2];
#endif 


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_key_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]         
 *  item_index          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_key_select(dialing_keypad_struct *dialing_keypad, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width, height;
    S32 key_width, key_height;
    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 053005 Calvin added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (item_index >= MMI_DIALING_KEY_FUNC)
    {
        key_width = dialing_keypad->func_key_width;
        key_height = dialing_keypad->func_key_height;
    }
    else
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    {
        key_width = dialing_keypad->key_width;
        key_height = dialing_keypad->key_height;
    }
    /* Calvin end */

    x1 = dialing_keypad->selected_key_x;
    y1 = dialing_keypad->selected_key_y;
    /* 053005 Calvin added for function key */
    x2 = x1 + key_width - 1;
    y2 = y1 + key_height - 1;
    /* Calvin end */
#ifndef __GDI_MEMORY_PROFILE_2__
    dialing_keypad->selected_key_bitmap.buf_ptr = key_buffer;   /* (U8*)gui_malloc((MMI_DIALING_KEY_WIDTH+1)*(MMI_DIALING_KEY_HEIGHT+1)*2); */
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_cache_bmp_get(x1, y1, x2, y2, &dialing_keypad->selected_key_bitmap);
    gdi_layer_pop_clip();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    if (0<= (item_index-1) && (item_index-1) < sizeof(dialing_key_image) / sizeof(dialing_key_image[0]))
    {
        image_id = dialing_key_image[item_index - 1];
        gui_measure_image(get_image(image_id), &width, &height);
        /* 053005 Calvin added for function key */
        x1 = x1 + ((key_width - width) >> 1);
        y1 = y1 + ((key_height - height) >> 1);
        /* Calvin end */
        gui_show_image(x1, y1, get_image(image_id));
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_key_unselect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialing_key_unselect(dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x1, x2, y1, y2;

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    S32 item_index = dialing_keypad->key_type;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = dialing_keypad->selected_key_x;
    y1 = dialing_keypad->selected_key_y;

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    if (item_index >= MMI_DIALING_KEY_FUNC)
    {
        x2 = x1 + dialing_keypad->func_key_width - 1;
        y2 = y1 + dialing_keypad->func_key_height - 1;
    }
    else
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    {
        x2 = x1 + dialing_keypad->key_width - 1;
        y2 = y1 + dialing_keypad->key_height - 1;
    }

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#else 
    gdi_image_cache_bmp_draw(x1, y1, &dialing_keypad->selected_key_bitmap);
#endif 
    gdi_layer_pop_clip();

}

/* 110105 dialing deflect Calvin Start */
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__


/*****************************************************************************
 * FUNCTION
 *  gui_show_dialing_key
 * DESCRIPTION
 *  Shows the phonebook icon on the dialing screen.
 * PARAMETERS
 *  key             [IN]        
 *  enableFlag      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_dialing_key(gui_dialing_key key, BOOL enableFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 item_index = 0;
    MMI_ID_TYPE item_icon;

	#if 1
	//Huyanwei Add it 
	return ;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key)
    {
        case MMI_DIALING_KEY_PHB:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_PHB;
            }
            else
            {
                item_icon = IMG_DIALING_KEY_PHB_DISABLED;
            }
            break;

        case MMI_DIALING_KEY_CALL:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_CALL;
            }
            else
            {
                item_icon = IMG_DIALING_KEY_CALL_DISABLED;
            }
            break;
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
        case MMI_DIALING_KEY_CALL_SLAVE:
            if (enableFlag)
            {
                item_icon = IMG_DIALING_KEY_CALL_SLAVE;
            }
            else
            {
                item_icon = IMG_DIALING_KEY_CALL_SLAVE_DISABLED;
            }
            break;
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
        default:
            return;
    }

    item_index = key - (MMI_DIALING_KEY_FUNC);

    x1 = MMI_DIALING_KEYPAD_FUNC_X + (item_index / MMI_DIALING_KEYPAD_FUNC_ROWS) * (MMI_DIALING_FUNC_KEY_WIDTH +
                                                                                    MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP);
    y1 = MMI_DIALING_KEYPAD_FUNC_Y + (item_index / MMI_DIALING_KEYPAD_FUNC_COLOMNS) * (MMI_DIALING_FUNC_KEY_HEIGHT +
                                                                                       MMI_DIALING_FUNC_KEY_VERTICAL_GAP);
    x2 = x1 + MMI_DIALING_FUNC_KEY_WIDTH - 1;
    y2 = y1 + MMI_DIALING_FUNC_KEY_HEIGHT - 1;
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_image_draw(x1, y1, (U8*) get_image(item_icon));
    gdi_layer_pop_clip();
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
/* 110105 dialing deflect Calvin Start */


/*****************************************************************************
 * FUNCTION
 *  gui_dialing_screen_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad          [?]         
 *  x                       [IN]        
 *  y                       [IN]        
 *  pen_event               [IN]        
 *  menu_event              [?]         
 *  dialing_key_param       [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_dialing_screen_translate_pen_event(
        dialing_keypad_struct *dialing_keypad,
        S32 x,
        S32 y,
        mmi_pen_event_type_enum pen_event,
        gui_dialing_key_pen_enum *menu_event,
        gui_pen_event_param_struct *dialing_key_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S32 item_index;
    S32 x1, y1, x2, y2;
#if defined(__MMI_DUAL_SIM_MASTER__)
    U8 m_dial_enable = 1;
    U8 s_dial_enable = 1;
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = TRUE;
    *menu_event = GUI_DIALING_PEN_NONE;

    /* 053005 Calvin */
#if defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__)
    x1 = dialing_keypad->keypad_x;
    y1 = dialing_keypad->keypad_y;
#else /* defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__) */ 
    x1 = dialing_keypad->keypad_x;
    y1 = dialing_keypad->keypad_y;
#endif /* defined (__MMI_MAINLCD_240X320__) && defined (__MMI_TOUCH_DIAL_SCREEN__) */ 
    /* Calvin end */

    x2 = x1 + dialing_keypad->keypad_width - 1;
    y2 = y1 + dialing_keypad->keypad_height - 1;

#if defined(__MMI_DUAL_SIM_MASTER__)
    MTPNP_PFAL_Retrieve_CallDial_State(&m_dial_enable, &s_dial_enable);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, x1, y1, dialing_keypad->keypad_width, dialing_keypad->keypad_height))
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                if (item_index == -1)   /* No key is selected */
                {
                    ret = FALSE;
                }
        #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__                
                if (item_index == MMI_DIALING_KEY_PHB && dialing_keypad_phonebook_handler == NULL)
                {
                    ret = FALSE; /* Disable Phonebook function key */
                }
        #endif
                /* PMT HIMANSHU START 20050825 */
        #if !defined(__MMI_DUAL_SIM_MASTER__)
            #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
                else if (item_index == MMI_DIALING_KEY_CALL && mmi_bootup_get_active_flight_mode())
                {
                    ret = FALSE;
                }
            #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
        #else   /* __MMI_DUAL_SIM_MASTER__ */
            #ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
                else if (item_index == MMI_DIALING_KEY_CALL && 
                    (mmi_bootup_get_active_flight_mode() || m_dial_enable == 0))
                {
                    ret = FALSE;
                }
            #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                else if (item_index == MMI_DIALING_KEY_CALL_SLAVE &&
                    (mmi_bootup_get_active_flight_mode() || s_dial_enable == 0))
                {
                    ret = FALSE;
                }
            #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
            #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
        #endif  /* __MERCURY_MASTER__ */
                /* PMT HIMANSHU END 20050825 */
                else
                {
                    gui_dialing_key_select(dialing_keypad, item_index);
                }
            }
            else
            {
                ret = FALSE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 ||pen_check_func_key_bound(
                 x, y, 
                 dialing_keypad->selected_key_x, dialing_keypad->selected_key_y,
                 dialing_keypad->keypad_func_x,dialing_keypad->keypad_func_y,
                 dialing_keypad->func_key_width,dialing_keypad->func_key_height,
                 dialing_keypad->func_n_rows,dialing_keypad->func_n_column)
		   #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                gui_dialing_key_unselect(dialing_keypad);
                if (item_index > MMI_DIALING_KEY_START && item_index < MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else
                {
                    switch (item_index)
                    {
                        case MMI_DIALING_KEY_STAR:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_STAR);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                            break;
                        case MMI_DIALING_KEY_ZERO:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, 0);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                            break;
                        case MMI_DIALING_KEY_HASH:
                            GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_POUND);
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                            break;
                            /* 071005 Calvin added for function key */
                    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
                        case MMI_DIALING_KEY_PHB:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_PHB;
                            break;
                        case MMI_DIALING_KEY_CALL:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_CALL;
                            break;
			 #ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
                        case MMI_DIALING_KEY_CALL_SLAVE:
                            *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_CALL_SLAVE;
                            break;
			 #endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                    #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
                            /* Calvin end */
                    }
                }
            }
            else
            {

                ret = FALSE;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            if (!PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
		   #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 &&!pen_check_func_key_bound(
                 x, y, 
                 dialing_keypad->selected_key_x, dialing_keypad->selected_key_y,
                 dialing_keypad->keypad_func_x,dialing_keypad->keypad_func_y,
                 dialing_keypad->func_key_width,dialing_keypad->func_key_height,
                 dialing_keypad->func_n_rows,dialing_keypad->func_n_column)
		   #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
		  )
            {
                if (dialing_keypad->key_type == MMI_DIALING_KEY_STAR)
                {
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_STAR);
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                }
                else
                {
                    *menu_event = GUI_DIALING_KEYPAD_HIGHLIGHT_CHANGED;
                }

            }
            else if (PEN_CHECK_BOUND
                     (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                      dialing_keypad->key_height)
                     #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 	||pen_check_func_key_bound(
                 	x, y, 
                 	dialing_keypad->selected_key_x, dialing_keypad->selected_key_y,
                 	dialing_keypad->keypad_func_x,dialing_keypad->keypad_func_y,
                 	dialing_keypad->func_key_width,dialing_keypad->func_key_height,
                 	dialing_keypad->func_n_rows,dialing_keypad->func_n_column)
		   	#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
		   )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                gui_dialing_key_select(dialing_keypad, item_index);
                //*menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                //GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param,item_index );
            }
            break;
        case MMI_PEN_EVENT_LONG_TAP:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 ||pen_check_func_key_bound(
                 x, y, 
                 dialing_keypad->selected_key_x, dialing_keypad->selected_key_y,
                 dialing_keypad->keypad_func_x,dialing_keypad->keypad_func_y,
                 dialing_keypad->func_key_width,dialing_keypad->func_key_height,
                 dialing_keypad->func_n_rows,dialing_keypad->func_n_column)
		   #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                /* start vijay 20050624vijay...chngaes done for activating silent mode */
                if (item_index >= MMI_DIALING_KEY_START && item_index <= MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else if (item_index == MMI_DIALING_KEY_HASH)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, KEY_POUND);
                }
                /* end vijay */
            }
            break;
        case MMI_PEN_EVENT_REPEAT:
            if (PEN_CHECK_BOUND
                (x, y, dialing_keypad->selected_key_x, dialing_keypad->selected_key_y, dialing_keypad->key_width,
                 dialing_keypad->key_height)
                 #if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
                 ||pen_check_func_key_bound(
                 x, y, 
                 dialing_keypad->selected_key_x, dialing_keypad->selected_key_y,
                 dialing_keypad->keypad_func_x,dialing_keypad->keypad_func_y,
                 dialing_keypad->func_key_width,dialing_keypad->func_key_height,
                 dialing_keypad->func_n_rows,dialing_keypad->func_n_column)
		   #endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
                 )
            {
                gui_dialing_screen_translate_pen_position(dialing_keypad, x, y, &item_index);
                if (item_index > MMI_DIALING_KEY_START && item_index < MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, item_index);
                }
                else if (item_index == MMI_DIALING_KEY_STAR)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_STAR;
                }
                else if (item_index == MMI_DIALING_KEY_ZERO)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_DIG_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(dialing_key_param, 0);
                }
                else if (item_index == MMI_DIALING_KEY_HASH)
                {
                    *menu_event = GUI_DIALING_KEYPAD_PEN_INSERT_HASH;
                }
            }
            else
            {
                ret = FALSE;
            }
            break;
    }
    return ret;
}
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ /* __MMI_TOUCH_SCREEN__ */
/* end vijay */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  pen_event                       [IN]        
 *  x                               [IN]        
 *  y                               [IN]        
 *  single_line_input_box_event     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_single_line_input_box_translate_pen_event(
        single_line_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_single_line_input_box_pen_enum *single_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
                *single_line_input_box_event = GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_DOWN;
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
                *single_line_input_box_event = GUI_SINGLE_LINE_INPUT_BOX_PEN_TEXT_UP;
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
        case MMI_PEN_EVENT_ABORT:
            if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
            {
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;
    }
    return ret;
}

static multi_line_input_box *gui_pen_scroll_multi_line_input_box = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  offset_y                        [IN]        
 *  multi_line_input_box_event      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_scroll_by_pen(
                multi_line_input_box *b,
                S32 offset_y,
                gui_multi_line_input_box_pen_enum *multi_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int move_gap = b->text_offset_y + offset_y;
    int line_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->text_offset_y = -offset_y;
    /* W05.35 For Scroll Issue with Header Height */
    /* W06.02 Fix Cursor Display Issue */
    /* W06.26 Remove compile warnings and review cursor position issue */
    StopTimer(BLINKING_CURSOR);
    if (b->max_line_height)
    {
        line_height = b->max_line_height;
    }
    else
    {
        line_height = b->min_line_height;
    }
    if ((b->cursor_y) < -(b->text_offset_y) ||
        (b->cursor_y + line_height) > b->edit_height - b->text_offset_y)
    {
        S32 new_UI_cursor_y1 = UI_cursor_y1;
        if (move_gap > 0)
        {
            new_UI_cursor_y1 = UI_cursor_y1 + line_height;
        }
        if ((new_UI_cursor_y1 + line_height) > (b->y + b->height))
        {
            new_UI_cursor_y1 = b->y + b->height - line_height;
        }
        else if (new_UI_cursor_y1 < b->y)
        {
            new_UI_cursor_y1 = b->y  + line_height;
        }
        gui_show_multi_line_input_box_ext(b, UI_cursor_x1, new_UI_cursor_y1);
    }
    
    b->text_offset_y = -offset_y;
    b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;
    gui_show_multi_line_input_box(b);
    b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_DISABLE_FORCE_CURSOR_APPEAR;

    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = gui_pen_scroll_multi_line_input_box;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_multi_line_input_box = NULL;

    if (!b)
    {
        return;
    }

    gui_multi_line_input_box_scroll_by_pen(b, b->pen_scroll_after_delay, &multi_line_input_box_event);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_abort_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_multi_line_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_start_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_multi_line_input_box_start_scroll_timer(multi_line_input_box *b, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assert that no two input box at the same time */
    MMI_DBG_ASSERT(!gui_pen_scroll_multi_line_input_box || gui_pen_scroll_multi_line_input_box == b);

    b->pen_scroll_after_delay = value;
    gui_pen_scroll_multi_line_input_box = b;

    gui_cancel_timer(gui_multi_line_input_box_scroll_timer_hdlr);
    gui_start_timer(b->pen_scroll_delay_time, gui_multi_line_input_box_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_multi_line_input_box_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_set_pen_scroll_delay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_input_box_set_pen_scroll_delay(multi_line_input_box *b, S32 delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(delay_time < (S32) 0x0000FFFF);
    b->pen_scroll_delay_time = (S16) delay_time;
}


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  pen_event                       [IN]        
 *  x                               [IN]        
 *  y                               [IN]        
 *  multi_line_input_box_event      [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_multi_line_input_box_translate_pen_event(
        multi_line_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_multi_line_input_box_pen_enum *multi_line_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    gui_multi_line_input_box_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    int scroll_bar_width;
    BOOL scroll_bar_active = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.04 Fix UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR issue in Touch Screen */
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((b->flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (b->vbar.scale > b->vbar.range)))
    {
        scroll_bar_width = 0;
        scroll_bar_active = FALSE;
    }
    else
    {
        scroll_bar_width = b->vbar.width;
        scroll_bar_active = TRUE;
    }

    pen_state = &b->pen_state;
    ret = MMI_TRUE;

    if (pen_event != MMI_PEN_EVENT_DOWN && pen_state->pen_on_scroll_bar)
    {
        gui_vertical_scrollbar_translate_pen_event(&b->vbar, pen_event, x, y, &scrollbar_event, &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
            {
                gui_multi_line_input_box_start_scroll_timer(b, scrollbar_param._u.i);
            }
            else
            {
                gui_multi_line_input_box_scroll_by_pen(b, scrollbar_param._u.i, multi_line_input_box_event);
            }
        }
        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                    pen_state->pen_on_scroll_bar = 0;
                    if (scroll_bar_active /* !(b->flags&UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR) */  &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &b->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_scroll_bar = 1;
                        /* W06.06 When the text is empty, max_line_height equals zero */
                        if (b->max_line_height)
                        {
                            gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->max_line_height);
                        }
                        else
                        {
                            gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->min_line_height);
                        }
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
                            {
                                gui_multi_line_input_box_start_scroll_timer(b, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_multi_line_input_box_scroll_by_pen(
                                    b,
                                    scrollbar_param._u.i,
                                    multi_line_input_box_event);
                            }
                        }
                        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR;
                    }
                    else
                    {
                        *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_DOWN;
                        
                        if (b->pen_down_control_area_callback != NULL)
                        {
                            if (b->header_height > 0 && b->y + b->text_offset_y + b->header_height >= y)
                                b->pen_down_control_area_callback(0, x, y - (b->y + b->text_offset_y));
                            else if(b->footer_height > 0 &&b->y + b->text_offset_y + b->text_height - b->footer_height < y)
                                b->pen_down_control_area_callback(1, x, y - (b->y + b->text_offset_y + b->text_height - b->footer_height));
                        }
                    }
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_UP:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width - scroll_bar_width, b->height) &&
                    (!(b->flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) || (b->flags & UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT)))
                {
                    *multi_line_input_box_event = GUI_MULTI_LINE_INPUT_BOX_PEN_TEXT_UP;
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_MOVE:
            case MMI_PEN_EVENT_LONG_TAP:
            case MMI_PEN_EVENT_REPEAT:
            case MMI_PEN_EVENT_ABORT:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width - scroll_bar_width, b->height))
                {
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
        }
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_multi_line_input_box_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int gui_multi_line_input_box_get_remaining_length(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n, max_n;
    U8 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = (b->text_length >> 1) - 1;
    max_n = (b->available_length >> 1) - 1;
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) && (b->UCS2_count == 0))
    {
        n += b->GSM_ext_count;
    }
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) && (b->text[0] == '+'))
    {
        n--;
        max_n--;
    }
    if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
    {
        temp_0x81 = mmi_phb_convert_to_0x81((S8*) b->text, FALSE);
        if (0 != temp_0x81)
        {
            max_n = (b->allocated_length >> 1) - 4;
            n = temp_0x81 - 3;
        }
    }
    return max_n - n;
}


/*****************************************************************************
 * FUNCTION
 *  gui_single_line_input_box_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int gui_single_line_input_box_get_remaining_length(single_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n, max_n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = (b->text_length >> 1) - 1;
    max_n = (b->available_length >> 1) - 1;
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_CHECK_GSM_EXTENDED) && (b->UCS2_count == 0))
    {
        n += b->GSM_ext_count;
    }
    if ((b->flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING) && (b->text[0] == '+'))
    {
        n--;
        max_n--;
    }
    return max_n - n;
}

void gui_multi_line_input_box_register_infobar_callback(
                        multi_line_input_box *b,
                        void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                        U32 height)
{
    if(height == 0)   height = INFORMATION_BAR_HEIGHT;
    
    b->infobar_redraw_callback = redraw_callback;
    b->infobar_reminder_char_callback = reminder_char_callback;
    wgui_inputbox_information_bar_height = height;
}

void gui_multi_line_input_box_register_change_event_handler(
                        multi_line_input_box *b,
                        MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
    b->change_event_handler = handler;
}

/*****************************************************************************
 * FUNCTION
 *  gui_get_multi_line_input_box_default_font_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN]
 *  text_font   [OUT]
 * RETURNS
 *  
 *****************************************************************************/
void gui_get_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *text_font = *(b->text_font);
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_default_font_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  text_font   [IN]
 * RETURNS
 *  
 *****************************************************************************/
void gui_set_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(b->text_font) = *text_font;
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_default_bg_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  c           [IN]
 *  b_set       [IN]
 * RETURNS
 *  
*****************************************************************************/
void gui_set_multi_line_input_box_default_bg_color(
                          multi_line_input_box *b, 
                          color c, 
                          MMI_BOOL b_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b_set)
    {
        b->ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR;
        b->default_bg_color = c;
    }
    else
    {
        b->ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_SET_BG_COLOR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_set_multi_line_input_box_underline_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  
 *****************************************************************************/
void gui_set_multi_line_input_box_underline_color(multi_line_input_box *b, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    b->underline_color = c;
}

#ifdef __MMI_INDIC_ALG__

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_post_template_addition_adjustment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]       
 * RETURNS
 *  void
 *****************************************************************************/
void gui_multi_line_post_template_addition_adjustment(multi_line_input_box *b)
{
    
    
        UI_buffer_type second_cons_ptr;
        UI_character_type /*old_c,*/ dummy_c = 0;
        second_cons_ptr = b->cursor_p;

        /* This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
        /* is there or not.If it is there then move the cursor beyond the cluster formed.      */
        if ((IRE_IS_CHAR_TYPE_CONSONANT((U16) ((*(second_cons_ptr - 4)) | ((*(second_cons_ptr - 3)) << 8))))
            && (IRE_IS_CHAR_TYPE_CONSONANT((U16) ((*second_cons_ptr) | ((*(second_cons_ptr + 1)) << 8))))
            && (IRE_IS_CHAR_TYPE_HALANT((U16) ((*(second_cons_ptr - 2)) | ((*(second_cons_ptr - 1)) << 8)))))
        {
            U32 langid_Halant = 0;
            U32 diff_langid_cons_halant = 0;

            langid_Halant = IRE_GET_CHARACTER_LANG_ID((U16) ((*(second_cons_ptr - 2))
                                                             | ((*(second_cons_ptr - 1)) << 8)));
            if (langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_ptr)
                                                                  | ((*(second_cons_ptr + 1)) << 8))))
            {
                diff_langid_cons_halant = 1;
            }
            if (!diff_langid_cons_halant)
            {
                U8 skip_moves = 0;
                U8 saved_skip_moves = 0;
                UI_character_type previous_character2 = 0;
                U32 counter = 0;
                U32 langid_Consonant = 0;
                PU8 first_ptr = second_cons_ptr;
                PU8 second_ptr;

                /* save_cursor_p = b->cursor_p; */
                second_ptr = ire_get_next_cluster_p(first_ptr, b->text + b->text_length-2);
                skip_moves = second_ptr - first_ptr;    /* Number of moves */
                skip_moves = skip_moves >> 1;
                saved_skip_moves = skip_moves;

                second_cons_ptr = b->cursor_p;
                langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16) ((*second_cons_ptr)
                                                                    | ((*(second_cons_ptr + 1)) << 8)));

                UI_STRING_GET_PREVIOUS_CHARACTER(second_cons_ptr, previous_character2);
                while ((IRE_GET_CHARACTER_LANG_ID((U16) previous_character2) == langid_Consonant) &&
                       IRE_IS_CHAR_TYPE_HALANT((U16) previous_character2))
                {
                    counter += 2;
                    second_cons_ptr -= 2;
                    if (b->text >= second_cons_ptr)
                    {
                        break;
                    }
                    UI_STRING_GET_PREVIOUS_CHARACTER(second_cons_ptr, previous_character2);

                }
                counter = counter % ((G_MAX - 2));
                skip_moves = (G_MAX - 2) - counter;
                if (saved_skip_moves > skip_moves)
                {
                    saved_skip_moves = skip_moves;

                }
                skip_moves = saved_skip_moves;

                while (skip_moves--)
                {
                    UI_STRING_GET_NEXT_CHARACTER(b->cursor_p, dummy_c);
                }

            }
        }
}
#endif /* __MMI_INDIC_ALG__ */ 

#if (defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) && defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__))
/*****************************************************************************
 * FUNCTION
 *  pen_check_func_key_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 * x					[IN]
 * y					[IN]
 * selected_key_x		[IN]
 * selected_key_y		[IN]
 * keypad_func_x		[IN]
 * keypad_func_y 		[IN]
 * func_key_width		[IN]	
 * func_key_height		[IN]
 * func_n_rows		[IN]
 * func_n_column		[IN]

 * RETURNS
 * MMI_BOOL
*****************************************************************************/
MMI_BOOL pen_check_func_key_bound(S32 x,S32 y,
                                                                       S32 selected_key_x,S32 selected_key_y,
                                                                       S32 keypad_func_x,S32 keypad_func_y, 
                                                                       S32 func_key_width,S32 func_key_height,
                                                                       S32 func_n_rows,S32 func_n_column)
{
MMI_BOOL is_func_key_flag = IS_NOT_FUNC_KEY;
if(x>keypad_func_x&&y>keypad_func_y&&
	x<selected_key_x+func_key_width*func_n_rows&&
	y<selected_key_y+func_key_height*func_n_column)
if(PEN_CHECK_BOUND
                (x, y, selected_key_x, selected_key_y, func_key_width,
                 func_key_height))
{
	is_func_key_flag = IS_FUNC_KEY;
}
return is_func_key_flag;
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ && __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

