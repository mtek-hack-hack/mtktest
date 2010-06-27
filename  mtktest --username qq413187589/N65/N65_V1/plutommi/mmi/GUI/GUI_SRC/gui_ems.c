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
 *   gui_ems.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   EMS editor - UI component
 *
 * Author:
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "SettingProfile.h"
#include "KeyBrd.h"

#include "gui_ems.h"
#include "gui_inputs.h"
#include "wgui_categories_defs.h"
#include "DebugInitDef.h"
#include "wgui_categories_inputs.h"
/*PMT IRE START*/
#include  "gui.h"
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
#include "MMI_features.h"
#include "TimerEvents.h"

#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"
#endif 


#ifdef __MMI_ZI_V7__
#include "ezicmn.h"
#endif 
#if defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__)
#include "zi8ARshape.h"
#endif /* defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 

/* for R2L characters */
#include "BIDIDEF.h"
#include "BIDIProt.h"

/* for R2L characters */
extern BOOL r2lMMIFlag;

#ifdef __MMI_BIDI_ALG__
extern U8 visual_str[];
extern U8 MMI_bidi_input_type;
#endif /* __MMI_BIDI_ALG__ */ 

/* MTK Steven 20050505 */
#ifdef __MMI_LANG_THAI__
#define isThaiChar(ch)  (((ch >= 0x0E01) && (ch <= 0x0E7F))? (1):(0))
#endif 
/* MTK End */

extern void StopTimer(U16 nTimerId);
extern U8 mmi_msg_get_seg_num(void);
extern void UI_set_current_text_color(color c);
extern S32 UI_cursor_x1;    /* cursor x1 postioon */
extern S32 UI_cursor_y1;    /* cursor y1 position */
extern S32 UI_cursor_x2;    /* cursor x1 postioon */
extern S32 UI_cursor_y2;    /* cursor y1 position */
extern void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c);

#if defined(__MMI_T9__)
extern void T9SynT9WithInputBoxForEMSInputBox(void);
#endif 

/* PMT START URDU */
#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
extern U16 shaping_str[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
extern U16 OrgToSha[MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
extern S32 unshaped_text_len;
extern S32 shaped_text_len;
#endif /* #if defined(__MMI_BIDI_ALG__) */

/* PMT END LANGUAGE 20060104 */
#if(0)
#include "DebugInitDef.h"
#endif /* (0) */ 
#define EMS_SHOW_HORIZONTAL_RULE_FOR_NEWLINE       0
/* START PMT NEERAJ 20050916 */
#define EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES        1
/* END PMT NEERAJ 20050916 */
#define EMS_ENABLE_EDITOR_OBJECT_PLAYBACK          0
#define EMS_PREVENT_CRLF_DISPLAY                1
#define EMS_USE_CRLF_COMBINATION                1
#define EMS_USE_ESC_COMBINATION                    1
#define EMS_USE_GSM_EXTENDED                    0
#define EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT       1
#define EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER        0x0A
#define EMS_ENABLE_SPECIAL_FONT_DISPLAY               1
#define EMS_HEADER_SCROLL_SIZE                     20
#define EMS_ENABLE_TESTFIX_OBJECT_ORDERING            1
#define EMS_DEFAULT_DCS_ALLOCATED_LENGTH           mmi_msg_get_seg_num() * 153
#define EMS_UCS2_DCS_ALLOCATED_LENGTH              mmi_msg_get_seg_num() * 67

#if defined(__MMI_MESSAGES_CONCAT_SMS__)
#define EMS_DEFAULT_DCS_AVAILABLE_LENGTH           mmi_msg_get_seg_num() * 153
#define EMS_UCS2_DCS_AVAILABLE_LENGTH              mmi_msg_get_seg_num() * 67
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
#define EMS_DEFAULT_DCS_AVAILABLE_LENGTH           160
#define EMS_UCS2_DCS_AVAILABLE_LENGTH              70
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 

UI_EMS_input_box_theme *current_EMS_input_box_theme = NULL;
stFontAttribute UI_EMS_inputbox_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
stFontAttribute UI_EMS_inputbox_medium_font = {0, 0, 0, MEDIUM_FONT, 0, 0};

#ifdef __MMI_DIALLING_FONT__
stFontAttribute UI_EMS_inputbox_large_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
#else 
stFontAttribute UI_EMS_inputbox_large_font = {0, 0, 0, LARGE_FONT, 0, 0};
#endif 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
U8 saved_last_skip_pos = 0;
U8 ems_cursor_pos_flag = 0;
U8 no_objects_adjusted = 0;
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */
/* PMT START MAUI_00024993 */
U8 multitap_to_cancel =0;
U8 donot_call_cancel =0;
/* PMT END MAUI_00024993 */
extern U8 add_template_ems_flag;
#endif /*__MMI_INDIC_ALG__*/
/*PMT IRE END*/
stFontAttribute UI_EMS_inputbox_current_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
color UI_EMS_inputbox_text_color = {0, 0, 0, 100};

#if(EMS_DISPLAY_SPECIAL_CHARACTERS)

/* Temporary data for debugging  */
const U8 EMS_CR_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0xFF, 0xFF,
    0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x34, 0x12,
};

const U8 EMS_LF_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00,
    0x34, 0x12,
};

const U8 EMS_ESC_display_character[] = 
{
    0x04, 0x00, 0xAF, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x12, 0x00, 0x00, 0x00,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0xFF, 0xFF,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F, 0x42, 0x1F,
    0x34, 0x12,
};

#endif /* (EMS_DISPLAY_SPECIAL_CHARACTERS) */ 

#if(!UI_DISABLE_EMS_INPUT_BOX)
EMSObjData UI_EMS_normal_text_format_object_data;
EMSObject UI_EMS_normal_text_format_object;

#ifdef __MMI_MESSAGES_EMS__
extern void EMS_cancel_object_focus(void);
extern U16 EMS_predefined_animations[];
#endif /* __MMI_MESSAGES_EMS__ */ 
#define EMS_DATA_END_OFFSET(x)   ((x))

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


kal_uint16 BackwardCurrentPositionSkipCR(EMSData *data);
kal_uint16 ForwardCurrentPositionSkipCR(EMSData *data);
void MoveCurrentPosition(EMSData *data, EMSPosition *start, EMSPosition *end, kal_uint16 steps);
void EMS_map_position(EMSData *data, EMSPosition *src, EMSPosition *dst);
void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
U8 TestLastPosition(EMSData *data, EMSPosition *p);
U8 TestFirstPosition(EMSData *data, EMSPosition *p);
U8 BackwardCurrentPositionObject(EMSData *data, EMSPosition *dst);
U8 ForwardCurrentPositionObject(EMSData *data, EMSPosition *dst);
void EMS_move_graphical_cursor(EMSData *data, S32 start_x, S32 cursor_x, S32 max_count);



#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_change_input_mode_for_smart_Abc
 * DESCRIPTION
 *  change input mode from smart abc to smart Abc
 * PARAMETERS
 *  b       [IN]        UI_EMS_input_box object
 * RETURNS
 *  MMI_BOOL true -> changed to Abc , false--> else
 *****************************************************************************/
MMI_BOOL gui_EMS_input_box_change_input_mode_for_smart_Abc(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type pre_ch = 0, pre2_ch = 0;
    UI_character_type separator[] = {'.','!','?',0x00};
    U8 idx = 0;
    EMSPosition mapped_cursor_position;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_current_input_mode != INPUT_MODE_SMART_LOWERCASE_ABC)
    {
        return MMI_FALSE;
    }


    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &pre_ch, &current_object);
    if (1 == object_type)
    {
        if(pre_ch != (UI_character_type)0x20)
        {
            return MMI_FALSE;
        }

    }
    else
    {
        return MMI_FALSE;
    }
    
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &pre2_ch, &current_object);
    if (1 == object_type)
    {
        while(pre2_ch != separator[idx])
        {
            if(((UI_character_type)0x00) == separator[idx])
            {
                return MMI_FALSE;
            }
            idx++;
        }
    }
    else
    {
        return MMI_FALSE;
    }    

    
    MMI_current_input_mode = INPUT_MODE_SMART_FIRST_UPPERCASE_ABC;
    change_EMS_inputbox_mode(INPUT_MODE_SMART_FIRST_UPPERCASE_ABC);
    wgui_EMS_redraw_input_information_bar();
    return MMI_TRUE;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_intialize_EMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_intialize_EMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_EMS_normal_text_format_object.Type = EMS_TYPE_TEXT_FORMAT;
    UI_EMS_normal_text_format_object.next = NULL;
    UI_EMS_normal_text_format_object.prev = NULL;
    UI_EMS_normal_text_format_object.OffsetToText = 0;
    UI_EMS_normal_text_format_object.data = &UI_EMS_normal_text_format_object_data;
    ResetTextFormat(&UI_EMS_normal_text_format_object.data->text_format);
#ifdef __MMI_MESSAGES_TEXT_FORMAT_ALIGN_LEFT__
    UI_EMS_normal_text_format_object.data->text_format.Alignment = EMS_ALIGN_LEFT;
#else 
    UI_EMS_normal_text_format_object.data->text_format.Alignment = EMS_ALIGN_LANG_DEP;
#endif 
}
/* PMT START MAUI_00027731 */
/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_find_segment_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

U8* gui_show_EMS_input_box_find_segment_start(EMSData *data,U8* end)
{
    EMSObject *obj;
    S32 end_index = end - data->textBuffer;
    S32 start_index = 0;
    if(end_index <0 || end_index > data->textLength ) return end; // just for safe. it should be assert !

    for(obj = data->listTail; obj && obj->OffsetToText >= end_index;obj = obj->prev)
        ;

    if(obj && obj->OffsetToText < end_index)
        start_index = obj->OffsetToText;


    return data->textBuffer + start_index;
}
/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_find_segment_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/

U8* gui_show_EMS_input_box_find_segment_end(EMSData *data,U8* start)
{
    EMSObject *obj;
    S32 start_index = start - data->textBuffer;
    S32 end_index = data->textLength ; 
   if(start_index <0 || start_index > end_index) return start; // just for safe. it should be assert !
    
    for(obj = data->listHead; obj && obj->OffsetToText <= start_index;obj = obj->next)
        ;

    if(obj && obj->OffsetToText > start_index)
        end_index = obj->OffsetToText;


    return data->textBuffer + end_index;
}
/* PMT END MAUI_00027731 */
/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_theme(UI_EMS_input_box *b, UI_EMS_input_box_theme *t)
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
    b->selected_text_color = t->selected_text_color;
    b->selection_color = t->selection_color;
    b->cursor_color = t->cursor_color;
    b->boundary_color = t->boundary_color;  /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
    b->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_current_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_current_theme(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->normal_filler = current_EMS_input_box_theme->normal_filler;
    b->disabled_filler = current_EMS_input_box_theme->disabled_filler;
    b->selected_filler = current_EMS_input_box_theme->selected_filler;
    b->normal_text_color = current_EMS_input_box_theme->normal_text_color;
    b->selected_text_color = current_EMS_input_box_theme->selected_text_color;
    b->selection_color = current_EMS_input_box_theme->selection_color;
    b->cursor_color = current_EMS_input_box_theme->cursor_color;
    b->boundary_color = current_EMS_input_box_theme->boundary_color;    /* Pixtel - Gurinder - 3/14/2004 - Editor With BG Image */
    b->flags |= current_EMS_input_box_theme->flags;
}

extern S16 MMI_current_input_ext_type;


/*****************************************************************************
 * FUNCTION
 *  gui_create_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height)
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
    b->flags = 0;
    MMI_current_input_ext_type = 0;
    gui_set_EMS_input_box_current_theme(b);
    b->overflow_callback = UI_dummy_function;
    b->change_callback = UI_dummy_function;
    gui_create_vertical_scrollbar(
        &b->vbar,
        b->x + b->width - current_EMS_input_box_theme->vbar_width - 1,
        b->y + 1,
        current_EMS_input_box_theme->vbar_width,
        b->height - 2);
    b->data = NULL;
    b->start_position.Object = NULL;
    b->start_position.OffsetToText = 0;
    b->end_position.Object = NULL;
    b->end_position.OffsetToText = 0;
    b->display_y = 0;
    ResetTextFormat(&b->text_format);
/*PMT IRE START*/
#if defined(__MMI_INDIC_ALG__)
    /*Resetting required in Indic Engine when EMS input box is created */
    ire_reset_use_multitap();
#endif 
/*PMT IRE END*/
    b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
    b->saved_cursor_ax = -1;
    b->underline_color = gui_color(0, 0, 128);
    b->strikethrough_color = gui_color(192, 0, 0);
    b->paragraph_color = gui_color(0, 128, 0);
    
    b->locate_cursor_flag = 1;
    
}

#if(EMS_USE_DCS)


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_change_DCS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_change_DCS(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->UCS2_count > 0)
    {
        EMSSetDCS(b->data, SMSAL_UCS2_DCS);
    #if defined(__MMI_MESSAGES_CONCAT_SMS__)
        b->available_length = b->data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() >> 1;
    #else 
        b->available_length = EMS_UCS2_DCS_AVAILABLE_LENGTH;
    #endif 
    }
    else
    {
        EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
    #if defined(__MMI_MESSAGES_CONCAT_SMS__)
        b->available_length = b->data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num();
    #else 
        b->available_length = EMS_DEFAULT_DCS_AVAILABLE_LENGTH;
    #endif 
    }
}

#endif /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_set_EMS_input_box_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  d       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_EMS_input_box_data(UI_EMS_input_box *b, EMSData *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *text_format_object;
    U8 done = 0;
    EMSPosition current_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->data = d;
    if (d == NULL)
    {
        return;
    }
    /* ResetCurrentPosition(b->data); */
    b->UCS2_count = 0;
    b->object_count = 0;
    b->GSM_ext_count = 0;
/*PMT IRE START*/
    #if defined(__MMI_INDIC_ALG__)
    IRE_RESET_LANGUAGE_VARIABLES();
    #endif
/*PMT IRE END*/
#if(EMS_USE_DCS)
    if ((b->data->textLength > 0) || (b->data->listHead != NULL))
    {
        U8 r;
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;

        p.OffsetToText = 0;
        p.Object = b->data->listHead;
        while (!done)
        {
            r = gui_EMS_input_box_get_next_object(d, &p, &c, &current_object);
            switch (r)
            {
                case 0:
                    done = 1;
                    break;
                case 1:
/*PMT IRE START*/
                    #if defined(__MMI_INDIC_ALG__)
                    IRE_INCREMENT_LANGUAGE_VARIABLES(c);
                    #endif
/*PMT IRE START*/                 
                    if (UI_TEST_UCS2_CHARACTER(c))
                    {
                        b->UCS2_count++;
                    }
                    if (UI_TEST_GSM_EXTENDED(c))
                    {
                        b->GSM_ext_count++;
                    }
                    break;
                case 2:
                    b->object_count++;
                    break;
            }
        }
    }
    gui_EMS_change_DCS(b);
#endif /* (EMS_USE_DCS) */ 
/*PMT START MAUI_00027919*/
        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_INDIC_ALG__) 
 
        {
            U32 i=0;
            U16 character = 0; 
            U8* s=b->data->textBuffer; 
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
    current_position.OffsetToText = 0;
    current_position.Object = NULL;
    text_format_object = GetTextFormatObjectAtPosition(b->data, &current_position);
    if (text_format_object != NULL)
    {
        b->text_format = text_format_object->data->text_format;
    }
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  EMS_get_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_remaining_length(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->dcs == SMSAL_DEFAULT_DCS)
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
        return (data->Reminder.totalRemainingOctet -
                (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
                 data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
        return (data->Reminder.totalRemainingOctet -
                (EMS_DEFAULT_DCS_ALLOCATED_LENGTH - EMS_DEFAULT_DCS_AVAILABLE_LENGTH));
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
    else
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
        return (data->Reminder.totalRemainingOctet -
                (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
                 data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
        return (data->Reminder.totalRemainingOctet -
                ((EMS_UCS2_DCS_ALLOCATED_LENGTH << 1) - (EMS_UCS2_DCS_AVAILABLE_LENGTH << 1)));
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
}

/* Mude Lin(MBJ06016) Add For SMS Remaining Count Display In EMS Editor*/
#ifdef __MMI_MESSAGES_EMS_REMAINING_COUNTER__
/*****************************************************************************
 * FUNCTION
 *  EMS_get_required_segment
 * DESCRIPTION
 *  Get the number of required segments to carry this EMS
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_required_segment(UI_EMS_input_box *input_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)input_data->data->Reminder.requiredSegment;
}

/*****************************************************************************
 * FUNCTION
 *  EMS_get_last_segment_remaining_char
 * DESCRIPTION
 *  Get The number of remaining characters in last segment. 
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 EMS_get_last_segment_remaining_char(UI_EMS_input_box *input_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 RemainingChar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_data->UCS2_count > 0)
    {
        RemainingChar = (S32)input_data->data->Reminder.segRemainingOctet / 2;
    }
    else
    {
        RemainingChar = (S32)input_data->data->Reminder.segRemainingOctet;
    }

    return RemainingChar;   
}
#endif /*__MMI_MESSAGES_EMS_REMAINING_COUNTER__*/

/*End Mude Lin(MBJ06016) Add*/


#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  f       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format_object(UI_EMS_input_box *b, EMSTextFormat *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        b->text_format = *f;
    }
}
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_locate_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_locate_cursor(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_height = b->height - 4;
    S32 cursory;
    S32 content_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
    gui_show_EMS_input_box(b);
    b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_DRAW;

    if (b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
    {
        cursory = b->cursor_ay + b->header_height;
        content_h = b->display_height + b->header_height;
    }
    else
    {
        cursory = b->cursor_ay;
        content_h = b->display_height;
    }
/*    if (b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
    {
        if ((b->cursor_ay + b->header_height) < (-b->display_y))
        {
            b->display_y = -b->cursor_ay - b->header_height;
        }
        else if ((b->cursor_ay + b->header_height + b->cursor_line_height) > ((-b->display_y) + (box_height)))
        {
            b->display_y -=
                (b->cursor_ay + b->cursor_line_height) - ((-b->display_y) + (box_height - b->header_height));
        }
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }
    else*/
    {
        if (cursory < (-b->display_y))
        {
            b->display_y = -cursory;
        }
        else if ((cursory + b->cursor_line_height) > ((-b->display_y) + box_height))
        {
            b->display_y -= (cursory + b->cursor_line_height) - ((-b->display_y) + box_height);
        }
        if ((b->display_y + content_h) < box_height)
        {
            b->display_y = (box_height) - content_h;
        }
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_reset_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_reset_cursor_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data != NULL)
    {
        ResetCurrentPosition(b->data);
        gui_EMS_input_box_locate_cursor(b);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_text_alignment(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    EMSPosition current_position = *p;
    U8 alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        r = gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    alignment = o->data->text_format.Alignment;
                }
                break;
        }
    }
    return (alignment);
}

/* Sets the alignment of the whole paragraph to the value specified.
   Starts from the given cursor position.
   The cursor position given must be at the first position on the paragraph   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_paragraph_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  p               [?]         
 *  alignment       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_paragraph_text_alignment(UI_EMS_input_box *b, EMSPosition *p, U8 alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    EMSPosition current_position = *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    o->data->text_format.Alignment = (EMSALIGNMENT) alignment;
                }
                break;
        }
    }
}

/* Checks if the cursor is at the beginning of a paragraph  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_test_paragraph_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_test_paragraph_start(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paragraph_flag = 0;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    EMSPosition current_position = *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (TestFirstPosition(b->data, &current_position))
    {
        paragraph_flag = 1;
    }
    else
    {
        if (BackwardCurrentPosition(b->data, 1) == 1)
        {
            current_position = b->data->CurrentPosition;
            r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
            ForwardCurrentPosition(b->data, 1);
            if ((r == 1) && (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER))
            {
                paragraph_flag = 1;
            }
        }
    }
    return (paragraph_flag);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format_cursor_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done = 0;
    EMSPosition current_position;
    EMSObject *current_text_format_object;
    UI_character_type c;
    EMSObject *o;
    U8 r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(b->flags & UI_EMS_INPUT_BOX_WORD_HIGHLIGHT)) /*if delete by smart IME input mode, don't replace the current format*/
        b->text_format = UI_EMS_normal_text_format_object.data->text_format;

    if (b->data == NULL)
    {
        return;
    }
    current_position = b->data->CurrentPosition;
    current_text_format_object = b->data->CurrentTextFormatObj;

    if ((current_text_format_object != NULL)
        && (current_position.OffsetToText >= current_text_format_object->OffsetToText)
        && (current_position.OffsetToText <=
            (current_text_format_object->OffsetToText + current_text_format_object->data->text_format.textLength))
        && !(b->flags & UI_EMS_INPUT_BOX_WORD_HIGHLIGHT))
    {
        b->text_format = current_text_format_object->data->text_format;
    }

    /* At the beginning of a paragraph ? Then locate the text alignment to be used   */
    if (gui_EMS_input_box_test_paragraph_start(b, &current_position))
    {
        while (!done)
        {
            r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
            switch (r)
            {
                case 0:
                    b->text_format.Alignment = UI_EMS_normal_text_format_object.data->text_format.Alignment;
                    done = 1;
                    break;
                case 1:
                    if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                    {
                        done = 1;
                    }
                    break;
                case 2:
                    if (o->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        b->text_format.Alignment = o->data->text_format.Alignment;
                        done = 1;
                    }
                    break;
            }
        }
    }
    else
    {
        while (!done)
        {
            r = gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
            switch (r)
            {
                case 0:
                    done = 1;
                    break;
                case 1:
                    if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                    {
                        done = 1;
                    }
                    break;
                case 2:
                    if (o->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        b->text_format.Alignment = o->data->text_format.Alignment;
                        done = 1;
                    }
                    break;
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_cursor_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_cursor_position(UI_EMS_input_box *b, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data != NULL)
    {
        ResetCurrentPosition(b->data);
        while (!
               ((b->data->CurrentPosition.OffsetToText == p->OffsetToText) &&
                (b->data->CurrentPosition.Object == p->Object)))
        {
            if (ForwardCurrentPosition(b->data, 1) != 1)
            {
                break;
            }
        }
        gui_EMS_input_box_locate_cursor(b);
    }
}

/* Macros for graphics functions */

extern stFontAttribute *UI_font;
extern U8 SetFont(stFontAttribute Font, U8 arrCount);

extern S32 UI_clip_x1, UI_clip_x2, UI_clip_y1, UI_clip_y2;
extern S32 UI_text_x, UI_text_y;
extern color UI_text_color;

#define EMS_SET_FONT(f)             \
      {  UI_font=(f);               \
         SetFont(*(f),0);           \
      }

#define EMS_MOVE_TEXT_CURSOR(x,y)      \
      {  UI_text_x=x;                  \
         UI_text_y=y;                  \
      }

#define EMS_SET_TEXT_COLOR(c)                     \
      {  UI_text_color=c;                         \
         UI_set_current_text_color(UI_text_color);\
      }


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_equal_text_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t1      [?]     
 *  t2      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_equal_text_format(EMSTextFormat *t1, EMSTextFormat *t2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t1->Alignment != t2->Alignment)
    {
        return (0);
    }
    if (t1->bgColor != t2->bgColor)
    {
        return (0);
    }
    if (t1->fgColor != t2->fgColor)
    {
        return (0);
    }
    if (t1->FontSize != t2->FontSize)
    {
        return (0);
    }
    if (t1->isBold != t2->isBold)
    {
        return (0);
    }
    if (t1->isItalic != t2->isItalic)
    {
        return (0);
    }
    if (t1->isStrikethrough != t2->isStrikethrough)
    {
        return (0);
    }
    if (t1->isUnderline != t2->isUnderline)
    {
        return (0);
    }
    if (t1->textLength != t2->textLength)
    {
        return (0);
    }
    return (1);
}

#define EMS_EQUAL_TEXT_FORMAT(t1,t2) (~(memcmp((t1),(t2),sizeof(EMSTextFormat)))
#define EMS_ESCAPE_CHARACTER  (27)


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_remove_extension_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_remove_extension_character(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 c, OffsetToText;
    U8 *textBuffer = data->textBuffer;
    U16 textBufferLength = data->textLength;
    EMSPosition currposition = data->CurrentPosition;

#if defined(__MMI_T9__)
    /* PMT VIKAS GUPTA START 20051129 */
    EMSPosition backupcurrposition = data->CurrentPosition;

    /* PMT VIKAS GUPTA END 20051129 */
#endif /* defined(__MMI_T9__) */ 
    kal_uint16 ret_char;
    EMSPosition dummyposition;
    EMSObject *ret_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (textBuffer == NULL)
    {
        return;
    }
    ResetCurrentPosition(data);
    if (data->dcs == SMSAL_DEFAULT_DCS)
    {
        while ((OffsetToText = data->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16) (textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else 
            c = (U16) (textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif 
            if (c == EMS_ESCAPE_CHARACTER)
            {
                dummyposition = data->CurrentPosition;
                while (EMSGetNextObject(data, &dummyposition, &ret_char, &ret_object) == 2)
                {
                    ForwardCurrentPosition(data, 1);
                    dummyposition = data->CurrentPosition;

                    if (ret_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (EMSGetPreviousObject(data, &dummyposition, &ret_char, &ret_object) == 1)
                        {
                            BackwardCurrentPosition(data, 1);
                            break;
                        }
                        dummyposition = data->CurrentPosition;
                    }
                }
				//changes by pawanjeet 080707
            #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                    break;
                }
                CancelCurrentPosition(data, 1);
                if (OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText--;
                }
                OffsetToText = data->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                    break;
                }
                CancelCurrentPosition(data, 1);
                if (OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText -= ENCODING_LENGTH;
                }
                OffsetToText = data->CurrentPosition.OffsetToText;
                textBufferLength -= ENCODING_LENGTH;
            #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
				//changes by pawanjeet 080707
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    MoveCursorToPosition(data, &currposition);
#if defined(__MMI_T9__)

    //hjf, we only need to care about the text offset change
    if(backupcurrposition.OffsetToText == currposition.OffsetToText)    
    {
        return;
    }
    /* PMT VIKAS GUPTA END 20051129 */
    T9SynT9WithInputBoxForEMSInputBox();
#endif /* defined(__MMI_T9__) */ 
}

/* Call before EMSPack  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_extension_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_insert_extension_character(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 c, OffsetToText;
    U8 *textBuffer = data->textBuffer;
    U16 textBufferLength = data->textLength;
    EMSPosition currposition = data->CurrentPosition;

#if defined(__MMI_T9__)
    /* PMT VIKAS GUPTA START 20051129 */
    EMSPosition backupcurrposition = data->CurrentPosition;

    /* PMT VIKAS GUPTA END 20051129 */
#endif /* defined(__MMI_T9__) */ 
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    U8 ESC_string[] = {0x00, 0x1B};
#else 
    U8 ESC_string[] = {0x1B, 0x00};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (textBuffer == NULL)
    {
        return;
    }
    ResetCurrentPosition(data);

    if (data->dcs == SMSAL_DEFAULT_DCS)
    {
        while ((OffsetToText = data->CurrentPosition.OffsetToText) < textBufferLength)
        {
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            c = (U16) (textBuffer[OffsetToText + 1] | (textBuffer[OffsetToText] << 8));
        #else 
            c = (U16) (textBuffer[OffsetToText] | (textBuffer[OffsetToText + 1] << 8));
        #endif 
            if (UI_TEST_GSM_EXTENDED(c))
            {
                AddString(data, ESC_string, 1, NULL);
				//changes by pawanjeet 080707
                if(OffsetToText < currposition.OffsetToText)
                {
                    currposition.OffsetToText += ENCODING_LENGTH;
                }
				//changes by pawanjeet 080707
                OffsetToText = data->CurrentPosition.OffsetToText;
                /* MTK Elvis 20031126 */
                textBufferLength += ENCODING_LENGTH;
                /* MTK end */
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    MoveCursorToPosition(data, &currposition);
#if defined(__MMI_T9__)

    //hjf, we only need to care about the text offset change
    if(backupcurrposition.OffsetToText == currposition.OffsetToText)
    {
        return;
    }
    /* PMT VIKAS GUPTA END 20051129 */
    T9SynT9WithInputBoxForEMSInputBox();
#endif /* defined(__MMI_T9__) */ 
}

#if(EMS_USE_DCS)

#if(EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION)

/* Deletes one object/character before cursor position and updates UCS2 and Object counters  */
/* Also handles CRLF combination                                              */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_cancel_current_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_cancel_current_position(UI_EMS_input_box *b)
{
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lst_pos = 0;
    S32 cancel_two_pos = 0;
    UI_character_type current_character1 = 0;
    //U8 object_type_check1 = 0;
    EMSObject *o1;
    EMSPosition p1 = b->data->CurrentPosition;
    EMSData *data_chk_type1 = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_INDIC_ALG__)  
  if(ems_cursor_pos_flag)
    {
        BackwardCurrentPosition(b->data, saved_last_skip_pos);
        ems_cursor_pos_flag = 0;
        saved_last_skip_pos = 0;
    }
#endif
    if (TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        lst_pos = 1;
    }
/*PMT IRE START*/
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 

    if (BackwardCurrentPosition(b->data, 1) == 1)
    {
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;
        U8 r;
        S32 count;
        U8 dcs_change = 0;

        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
/*PMT IRE START*/    
    #ifdef __MMI_INDIC_ALG__
        if (lst_pos)
        {
            /*If the character is CR & LF combination then put the value 0 at the place for these*/
            /*2 unicode values                                                                   */
            if (b->data->CurrentPosition.OffsetToText >= 4 &&
                UI_TEST_LF_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]) &&
                UI_TEST_CR_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]))
            {
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 1] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText] = 0;
                b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1] = 0;
                cancel_two_pos = 1;

            }
        }
    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
        ForwardCurrentPosition(b->data, 1);
        switch (r)
        {
            case 0:
                break;
            case 1:
/*PMT IRE START*/
                #if defined(__MMI_INDIC_ALG__)
                IRE_DECREMENT_LANGUAGE_VARIABLES(c);
                #endif
/*PMT IRE END*/
        #if(EMS_USE_CRLF_COMBINATION)
                if (UI_TEST_LF_CHARACTER(c))
                {
                    count = BackwardCurrentPosition(b->data, 2);
                    if (count == 2)
                    {
                        p = b->data->CurrentPosition;
                        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);

                        if(r==2 && current_object->Type==EMS_TYPE_TEXT_FORMAT) // solved by pawanjeet , it should ignore the text format between LF CR
                            r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);

                        if ((r == 1) && UI_TEST_CR_CHARACTER(c))
                        {
                            ForwardCurrentPosition(b->data, 2);
                            CancelCurrentPosition(b->data, 1);
                            count = 0;
                        }
                    }
                    ForwardCurrentPosition(b->data, (U16) count);
                }
                else
        #endif /* (EMS_USE_CRLF_COMBINATION) */ 
                if (UI_TEST_UCS2_CHARACTER(c))
                {
                    if (b->UCS2_count > 0)
                    {
                        b->UCS2_count--;
                        if (b->UCS2_count == 0)
                        {
                            dcs_change = 1;
                            gui_EMS_change_DCS(b);
                        }
                    }
                }
                else if (UI_TEST_GSM_EXTENDED(c))
                {
                    if (b->GSM_ext_count > 0)
                    {
                        b->GSM_ext_count--;
                    }
                }
                break;
            case 2:
                /* MTK Joy added for text format case, get the character and set the parameters accordingly, 1230 */
                if (current_object->Type == 0)
                {
                    r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
/*PMT IRE START*/
                    if(r==1)
                    {
                        #if defined(__MMI_INDIC_ALG__)
                        IRE_DECREMENT_LANGUAGE_VARIABLES(c);
                        #endif
                    }
/*PMT IRE END*/
                    if ((r == 1) && UI_TEST_UCS2_CHARACTER(c))
                    {
                        if (b->UCS2_count > 0)
                        {
                            b->UCS2_count--;
                            if (b->UCS2_count == 0)
                            {
                                dcs_change = 1;
                                gui_EMS_change_DCS(b);
                            }
                        }
                    }
                    else if (UI_TEST_GSM_EXTENDED(c))
                    {
                        if (b->GSM_ext_count > 0)
                        {
                            b->GSM_ext_count--;
                        }
                    }
                    break;
                }
                /* MTK end */
                if (b->object_count > 0)
                {
                    b->object_count--;
                    if (b->object_count == 0)
                    {
                        gui_EMS_change_DCS(b);
                    }
                }
                break;
        }
        CancelCurrentPosition(b->data, 1);
/*PMT IRE START*/
/* PMT START MAUI_00024993 */
    #ifdef __MMI_INDIC_ALG__
        b->data->textBuffer[b->data->textLength] = 0;
        b->data->textBuffer[b->data->textLength + 1] = 0;
        if (cancel_two_pos)
        {
            CancelCurrentPosition(b->data, 1);
        }
/* PMT START MAUI_00027731 */
        if ((b->data->CurrentPosition.OffsetToText >= 4)&&(!multitap_to_cancel))
        {
            /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
            /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
            U16 next_object=0,previous_object=0;
            p = b->data->CurrentPosition;
            next_object=gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
            p = b->data->CurrentPosition;
            previous_object=gui_EMS_input_box_get_previous_object(b->data, &p, &c, &current_object);
            if((next_object==1)&&(previous_object==1) &&( IRE_IS_CHAR_TYPE_CONSONANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ))) 
                 && ( IRE_IS_CHAR_TYPE_CONSONANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-4] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -3]<<8) ))) 
                 && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ))) ) 
            {
                
                U32 langid_Halant=0;
                U32 diff_langid_cons_halant=0;
                langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2]
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
                if(langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) )))
                {
                    diff_langid_cons_halant =1;
                }
				if(!diff_langid_cons_halant)
                {
                    /* EMSObject *object_pointer1; */
                    U8 fwd_positions = 0;
                    U8 saved_fwd_positions = 0;
                    PU8 dest_pos;
					/* U8 i=0; */
				    U32 counter =0;
				    U32 langid_Consonant =0;
                    UI_character_type previous_character2 = 0;
					/* U16 array[12]; */
					UI_buffer_type first_cons_ems_position;
					/*EMSTextFormat text_format;*/
                    PU8 src_pos = (&b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
                    p1 = b->data->CurrentPosition;
                    /*This loop detects the presence of Normal object in front of the cursor and  */
                    /* moves the cursor in front of the normal object.                             */
                   p1 = b->data->CurrentPosition;
                    //object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
                    dest_pos = ire_get_next_cluster_p(src_pos, gui_show_EMS_input_box_find_segment_end(b->data,src_pos));
                    fwd_positions = dest_pos - src_pos;    /* Number of moves */
                    fwd_positions = fwd_positions >> 1;
                    saved_fwd_positions = fwd_positions;
				    first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
				    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ));
				
				    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                    
				    while((1==gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1))&&(IRE_GET_CHARACTER_LANG_ID((U16)previous_character2)==langid_Consonant)&&IRE_IS_CHAR_TYPE_HALANT((U16)previous_character2))
					{
						counter +=2;
					    first_cons_ems_position-=2;
					    if(b->data->textBuffer>=first_cons_ems_position)
						{
							break;
						}
					    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                        gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1);
					
					}
				    counter= counter % ((G_MAX-2));
				    fwd_positions = (G_MAX-2) - counter;
				    if(saved_fwd_positions > fwd_positions)
					{
						saved_fwd_positions = fwd_positions;

					}
                    ForwardCurrentPosition(b->data, saved_fwd_positions);

                    
                    PRINT_INFORMATION_2(MMI_TRACE_INFO,"pixtel_UI_EMS_input_box_insert_multitap_character[skip_positions]:%d  ",
                                           saved_fwd_positions);
   	}
 		}
          }
		multitap_to_cancel =0;
		
/* PMT END MAUI_00027731 */
    #endif /* __MMI_INDIC_ALG__ */ 
/* PMT END MAUI_00024993 */
/*PMT IRE END*/
        if (dcs_change)
        {
            gui_EMS_input_box_insert_extension_character(b->data);
        }

    #if(EMS_USE_ESC_COMBINATION)
        if (b->UCS2_count == 0)
        {
            p = b->data->CurrentPosition;
            r = gui_EMS_input_box_get_previous_object(b->data, &p, &c, &current_object);
            if ((r == 1) && UI_TEST_ESC_CHARACTER(c))
            {
                CancelCurrentPosition(b->data, 1);
            }
        }
    #endif /* (EMS_USE_ESC_COMBINATION) */ 
        return (1);
    }
    return (0);
}

#else /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 

/* Deletes one object/character before cursor position and updates UCS2 and Object counters  */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_cancel_current_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_cancel_current_position(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BackwardCurrentPosition(b->data, 1) == 1)
    {
        EMSPosition p = b->data->CurrentPosition;
        EMSObject *current_object;
        UI_character_type c;
        U8 r;

        r = gui_EMS_input_box_get_next_object(b->data, &p, &c, &current_object);
        ForwardCurrentPosition(b->data, 1);
        switch (r)
        {
            case 0:
                break;
            case 1:
                if (UI_TEST_UCS2_CHARACTER(c))
                {
                    if (b->UCS2_count > 0)
                    {
                        b->UCS2_count--;
                        if (b->UCS2_count == 0)
                        {
                            gui_EMS_change_DCS(b);
                        }
                    }
                }
                break;
            case 2:
                if (b->object_count > 0)
                {
                    b->object_count--;
                    if (b->object_count == 0)
                    {
                        gui_EMS_change_DCS(b);
                    }
                }
                break;
        }
        CancelCurrentPosition(b->data, 1);
        return (1);
    }
    return (0);
}

#endif /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 

#define  EMSSWAP(t,a,b) \
{  t temp=a;            \
   a=b;                 \
   b=temp;              \
}

/* Temporary function: Will be removed later                            */
/* For testing purpose only: Using this will cause an assertion in the EMS library  */


/*****************************************************************************
 * FUNCTION
 *  ArrangeEMSObjects
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ArrangeEMSObjects(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    EMSObject *start;
    U8 done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        done = 0;
        start = current;
        while (!done)
        {
            current = current->next;
            if (current == NULL)
            {
                done = 1;
                break;
            }
            if (current->OffsetToText != start->OffsetToText)
            {
                done = 1;
                break;
            }
            if (current->Type == EMS_TYPE_TEXT_FORMAT)
            {
                EMSSWAP(EMSObject, *current, *start);
                EMSSWAP(kal_uint16, current->OffsetToText, start->OffsetToText);
                EMSSWAP(struct _EMSObject *, current->prev, start->prev);
                EMSSWAP(struct _EMSObject *, current->next, start->next);

                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_char = 1;

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    UI_character_type c = ((UI_character_type) s[1]) | (((UI_character_type) s[0]) << 8);
#else 
    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);
#endif 
    EMSTATUS r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
    /*This statement checks whether a template is being added or not.If a template*/
    /* is added then if following sequence: Cons.+Halant+Object(cursor) and the   */
    /*first character from the template to be insert is a consonant then move the */
    /*cursor in front of the object and then insert the character.                */
    /*Note:There could be more than one object in the sequence                    */
    if(add_template_ems_flag) 
    {
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        /* PMT START IRE CODE REVIEW */ 
        U32 character_type=0;
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check = MMI_FALSE;
        }
        
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) )))  );
        /* PMT END IRE CODE REVIEW */
        
        
        if(  dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
/* PMT START MAUI_00027731 */
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                             | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
            if((dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
/* PMT END MAUI_00027731 */     
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */ 
        #if defined(__MMI_BIDI_ALG__) 
        {
            PMT_BIDI_TYPES default_direction = BIDI_L;
            if(IRE_INSERTED_ARABIC_COUNT() && IRE_INDIC_LANGUAGE_RANGE(c))
            {
                c = (U16)'?';
            }
            bidi_get_char_type((U8*) &c, (U8*) & default_direction);
            if (((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))
                &&(IRE_INSERTED_INDIC_COUNT())) 
            {
                c = (U16)'?';
            }
        }
        #endif
        add_template_ems_flag=0;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/    
    if (text_format == NULL)
    {
        r = AddString(b->data, (U8*)&c, num_char, NULL);
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            r = AddString(b->data,(U8*)&c, num_char, NULL);
        }
        else
        {
            r = AddString(b->data, (U8*)&c, num_char, text_format);
        }
    }
    else
    {
        r = AddString(b->data, (U8*)&c, num_char, text_format);
    }
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/
    if (r == EMS_OK)
    {
/*PMT IRE START*/
        #if defined(__MMI_INDIC_ALG__)
        IRE_INCREMENT_LANGUAGE_VARIABLES(c);
        #endif
/*PMT IRE END*/
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            if (b->UCS2_count == 0)
            {
                b->UCS2_count++;
                gui_EMS_change_DCS(b);
            }
            else
            {
                b->UCS2_count++;
            }
        }
        else if (UI_TEST_GSM_EXTENDED(c))
        {
            b->GSM_ext_count++;
        }
        if (b->UCS2_count > 0)
        {
            S32 remaining_length = (EMS_get_remaining_length(b->data) >> 1);

            if (remaining_length < 0)
            {
                gui_EMS_cancel_current_position(b);
                r = EMS_NO_SPACE;
            }
        }
    #if(EMS_USE_GSM_EXTENDED)
        else if (b->GSM_ext_count > 0)
        {
            S32 remaining_length = EMS_get_remaining_length(b->data);

            /* S32 available_length=b->available_length; */
            if (remaining_length < 0)
            {
                gui_EMS_cancel_current_position(b);
                r = EMS_NO_SPACE;
            }
        }
    #endif /* (EMS_USE_GSM_EXTENDED) */ 
    }
    else
    {
        /* MTK Terry for EMS_NO_MEMORY or other error cause */
        gui_EMS_change_DCS(b);
    }

    /* Temporary   */
    /* ArrangeEMSObjects(b->data); */

    return (r);
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_whole_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    UI_character_type c = ((UI_character_type) s[1]) | (((UI_character_type) s[0]) << 8);
#else 
    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);
#endif 
    EMSTATUS r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
    /*This statement checks whether a template is being added or not.If a template*/
    /* is added then if following sequence: Cons.+Halant+Object(cursor) and the   */
    /*first character from the template to be insert is a consonant then move the */
    /*cursor in front of the object and then insert the character.                */
    /*Note:There could be more than one object in the sequence                    */
    if(add_template_ems_flag) 
    {
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        /* PMT START IRE CODE REVIEW */
        U32 character_type = 0;
        character_type ^= character_type;
       	character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) )))  );
        /* PMT END IRE CODE REVIEW */
        
        
        if(  dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
/* PMT START MAUI_00027731 */
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
                             | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
            if((dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
/* PMT END MAUI_00027731 */ 
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */     
/* START PMT PATCH04052007 */
/* START PMT MAUI_00027393 */
        #if defined(__MMI_BIDI_ALG__) 
        {
            int i=0;
            U16 character = 0; 
            for(i=0;i<(U16)mmi_ucs2strlen((S8*)s);i++)
            {
                PMT_BIDI_TYPES default_direction = BIDI_L;
                #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                character  = (U16)((U16) s[2*i+1]) | (((U16) s[2*i]) << 8);
                #else 
                character = (U16)((U16) s[2*i]) | (((U16) s[2*i+1]) << 8);
                #endif

                 if(IRE_INSERTED_ARABIC_COUNT() && IRE_INDIC_LANGUAGE_RANGE(character))
                 {
                     character = (U16)'?';
                 }
                 bidi_get_char_type((U8*) &character, (U8*) & default_direction);
                 if (((default_direction == AL) || (default_direction == AN) || (default_direction == BIDI_R))
                  &&(IRE_INSERTED_INDIC_COUNT())) 
                 {
                     character = (U16)'?';
                 }

                #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                s[2*i] = (character & 0xff00) >> 8;
                s[2*i+1] = (character & 0x00ff);
                #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                s[2*i+1] = (U8) (character >> 8);
                s[2*i] = (U8) character;
                #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                


            }
        }
        #endif
/* END PMT MAUI_00027393 */

/* END PMT PATCH04052007 */
        add_template_ems_flag=0;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/    
/* START PMT PATCH04052007 */   
    if (b->UCS2_count == 0)
    {
        while (c)
        {  
#if defined(__MMI_INDIC_ALG__)
            IRE_INCREMENT_LANGUAGE_VARIABLES(c);
#endif
            if (UI_TEST_UCS2_CHARACTER(c))
            {
                gui_EMS_input_box_remove_extension_character(b->data);
                if ((r = EMSSetDCS(b->data, SMSAL_UCS2_DCS)) != EMS_OK)
                {
                    EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                    gui_EMS_input_box_insert_extension_character(b->data);
                    return r;
                }
                else
                {
                    if (EMS_get_remaining_length(b->data) < mmi_ucs2strlen((S8*)s) *2 )
                    {
                        EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                        gui_EMS_input_box_insert_extension_character(b->data);
                        return EMS_NO_SPACE;
                    }
                    else
                        break; // Success convert to UCS2
                }
            }
            i +=2;
            c = (UI_character_type)(s[i] | (s[i+1]<<8));
        }
        
    }

    if (text_format == NULL)
    {
        r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), NULL);
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            r = AddString(b->data,s, (U16)mmi_ucs2strlen((S8*)s), NULL);
        }
        else
        {
            r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), text_format);
        }
    }
    else
    {
        r = AddString(b->data, s, (U16)mmi_ucs2strlen((S8*)s), text_format);
    }
/* END PMT PATCH04052007 */
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/
    if (r == EMS_OK)
    {
        while (c)
        {
/*PMT IRE START*/
        #if defined(__MMI_INDIC_ALG__)
        IRE_INCREMENT_LANGUAGE_VARIABLES(c);
        #endif
/*PMT IRE END*/
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            if (b->UCS2_count == 0)
            {
                b->UCS2_count++;
                gui_EMS_change_DCS(b);
            }
            else
            {
                b->UCS2_count++;
            }
        }
        else if (UI_TEST_GSM_EXTENDED(c))
        {
            b->GSM_ext_count++;
        }
        i +=2;
        c = (UI_character_type)(s[i] | (s[i+1]<<8));
        }
    }
    else
    {
        /* MTK Terry for EMS_NO_MEMORY or other error cause */
        gui_EMS_change_DCS(b);
    }

    /* Temporary   */
    /* ArrangeEMSObjects(b->data); */

    return (r);
}

#else /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_char = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_format == NULL)
    {
        return (AddString(b->data, s, num_char, NULL));
    }
    else if (b->data->CurrentTextFormatObj == NULL)
    {
        if (gui_EMS_input_box_equal_text_format(&b->text_format, &UI_EMS_normal_text_format_object.data->text_format))
        {
            return (AddString(b->data, s, num_char, NULL));
        }
        else
        {
            return (AddString(b->data, s, num_char, text_format));
        }
    }
    else
    {
        return (AddString(b->data, s, num_char, text_format));
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_add_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  s               [?]     
 *  text_format     [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_add_whole_string(UI_EMS_input_box *b, U8 *s, EMSTextFormat *text_format)
{
    U16 i = 0;

    UI_character_type c = ((UI_character_type) s[0]) | (((UI_character_type) s[1]) << 8);

    while (c)
    {
        gui_EMS_input_box_add_string(b, (U8*)&c, text_format);
        i += 2;
        c = (UI_character_type)(s[i] | (s[i+1]<<8));
    }
    
}
#endif /* (EMS_USE_DCS) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_inputbox_add_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  type                            [IN]        
 *  objData                         [?]         
 *  predefined_object_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_inputbox_add_object(UI_EMS_input_box *b, U8 type, EMSObjData *objData, U8 predefined_object_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* PMT START MAUI_00027731 */
//code removed
/* PMT END MAUI_00027731 */
    r = AddObject(b->data, type, objData, (U8) predefined_object_number);
#if(EMS_USE_DCS)
    if (r == EMS_OK)
    {
        S32 remaining_length;

        if (b->object_count == 0)
        {
            b->object_count++;
            gui_EMS_change_DCS(b);
        }
        else
        {
            b->object_count++;
        }
        if (b->UCS2_count > 0)
        {
            remaining_length = (EMS_get_remaining_length(b->data) >> 1);
        }
        else
        {
            remaining_length = EMS_get_remaining_length(b->data);
        }
        if (remaining_length < 0)
        {
            CancelCurrentPosition(b->data, 1);
            b->object_count--;
            if (b->object_count == 0)
            {
                gui_EMS_change_DCS(b);
            }
            /* UI_editor_play_tone_cannot_insert(); */
            return (EMS_NO_SPACE);
        }
    }
#endif /* (EMS_USE_DCS) */ 
    b->saved_cursor_ax = -1;
    return (r);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_character_no_draw(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //W06.03 EMS_get_remaining_length > 0 does not make sure that we could insert one more character
    //Return EMS_OK if we insert the character successfully
    U16 ch = (U16) c;
    U8 s[2] = {0, 0};
    S32 remaining_length;
    U8 ret = EMS_OK;
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
    //EMSObject *object_pointer1;
/*PMT START MAUI_00025408*/
    UI_character_type current_character1 = 0/*,current_character2 = 0*/;
    U8 /*object_type_check2 = 0,*/object_type_check1 =0;
    EMSObject /**o2,*/*o1;
    EMSPosition p1/*, p2 = b->data->CurrentPosition*/;
    EMSData *data_chk_type1 = b->data/*, *data_chk_type2 = b->data*/;
    UI_buffer_type  first_cons_ems_position,middle_ems_position,second_cons_ems_position;
 /*PMT END MAUI_00025408*/
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;
    U8 halant_cons_combination = 0;
/* PMT START MAUI_00024993 */
	//U16 array[12];
	//EMSTextFormat text_format;
    /* PMT START IRE CODE REVIEW */
    U32 character_type=0;
    /* PMT END IRE CODE REVIEW */
/* PMT END MAUI_00024993 */
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->UCS2_count > 0)
    {
        remaining_length = (EMS_get_remaining_length(b->data) >> 1);
    }
    else
    {
        remaining_length = EMS_get_remaining_length(b->data);
    }
    if (remaining_length <= 0)
    {
        UI_editor_play_tone_cannot_insert();
        return EMS_NO_SPACE;
    }
/* PMT START MAUI_00029915*/
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
/* PMT END MAUI_00029915*/
/* PMT START MAUI_00027731 */
//code removed 
/* PMT END MAUI_00027731 */
    if (b->UCS2_count == 0)
    {
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            gui_EMS_input_box_remove_extension_character(b->data);
            if (EMSSetDCS(b->data, SMSAL_UCS2_DCS) != EMS_OK)
            {
                EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                gui_EMS_input_box_insert_extension_character(b->data);
                UI_editor_play_tone_cannot_insert();
                return EMS_NO_SPACE;
            }
            else
            {
                if (EMS_get_remaining_length(b->data) < 2)
                {
                    EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                    gui_EMS_input_box_insert_extension_character(b->data);
                    UI_editor_play_tone_cannot_insert();
                    return EMS_NO_SPACE;
                }
            }
        }
/*        else if (UI_TEST_GSM_EXTENDED(c))
        {
            if (EMS_get_remaining_length(b->data) < 2)
            {
                UI_editor_play_tone_cannot_insert();
                return EMS_NO_SPACE;
            }
        }*/
    }
    /* MTK end */

    /* If in Overwrite mode, delete the current character/object and insert the new one */
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        if (gui_EMS_input_box_forward_cursor(b) == 1)
        {
            gui_EMS_cancel_current_position(b);
        }
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    s[0] = (ch & 0xff00) >> 8;
    s[1] = (ch & 0x00ff);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    s[1] = (U8) (ch >> 8);
    s[0] = (U8) ch;
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00024993 */
	multitap_to_cancel =0;
/* PMT END MAUI_00024993 */
    ems_cursor_pos_flag = 0;
    saved_last_skip_pos = 0;
/* PMT START MAUI_00027731 */
    second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
/* PMT START IRE CODE REVIEW */
       	character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
    halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
          && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) ))  );
/* PMT END IRE CODE REVIEW */
    /*This statement does not allow addition of format object in the following cases: */
    /*1.When the input character is Dep. Vowel, Halant, Sign                          */
    /*2.When the previous character is Halant and input character is Consonant        */
    if(  dv_hal_sign_check ||  halant_cons_combination)
    {
        U32 langid_Halant=0;
        langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ));
        if((dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
        {
            prev_text_format_flag=1;
            temp_text_format=b->text_format;
            if(b->data->CurrentTextFormatObj)
            {
                b->text_format=b->data->CurrentTextFormatObj->data->text_format;
            }
            else
            {
                b->text_format=UI_EMS_normal_text_format_object.data->text_format;
            }
        }
    }
/* PMT END MAUI_00027731 */
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    if (gui_EMS_input_box_add_string(b, s, &b->text_format) == EMS_NO_SPACE)
    {
        UI_editor_play_tone_cannot_insert();
        b->overflow_callback();
        ret = EMS_NO_SPACE;
    }
    else
    {
/*PMT START MAUI_00025408*/
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00024993 */
		    multitap_to_cancel =0;
/* PMT END MAUI_00024993 */
            p1=b->data->CurrentPosition;
			first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-4]);
			second_cons_ems_position =&(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]); 
			middle_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2]);
            if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
            {
                object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
            }
            /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
            /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
/* PMT START MAUI_00027731 */
            if((object_type_check1==1)&&( IRE_IS_CHAR_TYPE_CONSONANT( (U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ) )) 
                 && (IRE_IS_CHAR_TYPE_CONSONANT((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) )) 
                 && (IRE_IS_CHAR_TYPE_HALANT((U16)( (*middle_ems_position) | ((*(middle_ems_position+1))<<8) ) )) ) 
            { 
                U32 langid_Halant=0;
                U32 diff_langid_cons_halant=0;
                langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2]
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
                if(langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) )))
                {
                    diff_langid_cons_halant =1;
                }
/* PMT START MAUI_00024993 */
                if(!diff_langid_cons_halant)
				{

                    U8 skip_positions = 0;
				    //U8 i=0;
				    U32 counter =0;
				    U32 langid_Consonant =0;
                    PU8 src_ems_pos = second_cons_ems_position;
                    PU8 dest_ems_pos;
				    UI_character_type previous_character2 = 0;
                        dest_ems_pos = ire_get_next_cluster_p(src_ems_pos, gui_show_EMS_input_box_find_segment_end(b->data,src_ems_pos));
                    skip_positions = dest_ems_pos - src_ems_pos;    /* Number of moves */
                    skip_positions = skip_positions >> 1;
                    saved_last_skip_pos = skip_positions;
				    first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
				    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ));
				
				    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                    p1=b->data->CurrentPosition;
				    while((1==gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1))&&(IRE_GET_CHARACTER_LANG_ID((U16)previous_character2)==langid_Consonant)&&IRE_IS_CHAR_TYPE_HALANT((U16)previous_character2))
					{
						counter +=2;
					    first_cons_ems_position-=2;
					    if(b->data->textBuffer>=first_cons_ems_position)
						{
							break;
						}
					    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                        gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1);
					
					}
				    counter= counter % ((G_MAX-2));
				    skip_positions = (G_MAX-2) - counter;
				    if(saved_last_skip_pos > skip_positions)
					{
						saved_last_skip_pos = skip_positions;

					}


                    
                    PRINT_INFORMATION_2(MMI_TRACE_INFO,"pixtel_UI_EMS_input_box_insert_multitap_character[skip_positions]:%d  ",
                                           saved_last_skip_pos);
                    #if defined(__MMI_INDIC_ALG__)                    
                    ems_cursor_pos_flag = 1;//
                    #endif
		   ForwardCurrentPosition(b->data, saved_last_skip_pos);
									}
            }
        #endif /* __MMI_INDIC_ALG__ */ 
/* PMT END MAUI_00027731 */
        b->change_callback();
    }
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
	multitap_to_cancel =0;
#endif /*__MMI_INDIC_ALG__*/
/* PMT END MAUI_00024993 */
    
    


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif  
    return ret;
}

U8 gui_EMS_input_box_insert_character(UI_EMS_input_box *b, UI_character_type c)
{
    U8 ret = gui_EMS_input_box_insert_character_no_draw(b,c);
    if (b->locate_cursor_flag)
    {
        gui_EMS_input_box_locate_cursor(b);
    }
    
    b->saved_cursor_ax = -1;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_multitap_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_insert_multitap_character_no_draw(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ch = (U16) c;
    U8 s[2] = {0, 0};
    EMSTextFormat text_format;
    S32 remaining_length;

#ifdef __MMI_INDIC_ALG__
    //EMSObject *object_pointer1;
    UI_character_type current_character1 = 0;
    U8 object_type_check1 = 0;
    EMSObject *o1;
    EMSPosition p1 = b->data->CurrentPosition;
    EMSData *data_chk_type1 = b->data;
    //UI_character_type current_character2 = 0;
    //U8 object_type_check2 = 0;
    //EMSObject *o2;
    //EMSPosition p2 = b->data->CurrentPosition;
    //EMSData *data_chk_type2 = b->data;
    UI_buffer_type middle_ems_position, first_cons_ems_position, second_cons_ems_position;
    EMSTextFormat temp_text_format;
    U8 prev_text_format_flag=0;
    U8 dv_hal_sign_check = 0;/*checking whether the character is Dep. vowel, sign or halant*/
    U8 halant_cons_combination = 0;/*check for halant and consonant combination */
    /* PMT START IRE CODE REVIEW */
    U32 character_type=0;
    /* PMT END IRE CODE REVIEW */
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->UCS2_count > 0)
    {
        remaining_length = (EMS_get_remaining_length(b->data) >> 1);
    }
    else
    {
        remaining_length = EMS_get_remaining_length(b->data);
    }
    if ((remaining_length <= 0) && !(b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP) &&
        !(b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE))
    {
        UI_editor_play_tone_cannot_insert();
        return;
    }
//* PMT START MAUI_00029915*/
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
/* PMT END MAUI_00029915*/
/* PMT START MAUI_00024993 */
//code removed
/* PMT END MAUI_00024993 */
#if(0)
    if((b->UCS2_count==0) && UI_TEST_UCS2_CHARACTER(c) && (remaining_length<=344))
    {   UI_editor_play_tone_cannot_insert();
        return;
    }
#endif /* (0) */ 
    if (b->UCS2_count == 0)
    {
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            gui_EMS_input_box_remove_extension_character(b->data); // hjf, It should remove gsm extended character when switch to UCS2

            if (EMSSetDCS(b->data, SMSAL_UCS2_DCS) != EMS_OK)
            {
                EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                gui_EMS_input_box_insert_extension_character(b->data);// hjf, can't switch to UCS2, append gsm extended character again
                UI_editor_play_tone_cannot_insert();
                return;
            }
            else
            {
                if (EMS_get_remaining_length(b->data) < 2)
                {
                    EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                    gui_EMS_input_box_insert_extension_character(b->data);// hjf, can't switch to UCS2, append gsm extended character again
                    UI_editor_play_tone_cannot_insert();
                    return;
                }
            }
        }
        else if (UI_TEST_GSM_EXTENDED(c))
        {
            if (EMS_get_remaining_length(b->data) < 2)
            {
                UI_editor_play_tone_cannot_insert();
                return;
            }
        }
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    s[0] = (ch & 0xff00) >> 8;
    s[1] = (ch & 0x00ff);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    s[1] = (U8) (ch >> 8);
    s[0] = (U8) ch;
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
/* PMT START IRE CODE REVIEW */
#ifdef __MMI_INDIC_ALG__
        character_type = ire_identify_character_type((U16)(s[0] | (s[1]<<8) ));
        switch(character_type)
        {
            case IRE_CHAR_TYPE_DEPVOWEL:
            case IRE_CHAR_TYPE_HALANT:
            case IRE_CHAR_TYPE_SIGN:
                dv_hal_sign_check = MMI_TRUE;
                break;
            default:
                dv_hal_sign_check =MMI_FALSE;
        }
#endif
/* PMT END IRE CODE REVIEW */
    if (b->flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
    {
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00024993 */
		multitap_to_cancel =1;
/* PMT START MAUI_00027239 */
		first_cons_ems_position=  &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 4]);
/* PMT END MAUI_00027239 */
/* PMT START IRE CODE REVIEW */
	    halant_cons_combination= ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ) ))  );
/* PMT END IRE CODE REVIEW */
/* PMT START MAUI_00027731 */
        if(ems_cursor_pos_flag)
        {
	    BackwardCurrentPosition(b->data, saved_last_skip_pos);
	    #if defined (__MMI_INDIC_ALG__)
            ems_cursor_pos_flag = 0;
            saved_last_skip_pos = 0;
	    #endif
/* START PMT PATCH04052007 */
/*code is removed*/
/* END PMT PATCH04052007 */
        }
       

#endif /* __MMI_INDIC_ALG__ */ 
            gui_EMS_cancel_current_position(b);
#ifdef __MMI_INDIC_ALG__
/* PMT START MAUI_00027239 */
		if( (dv_hal_sign_check ||  halant_cons_combination))
        {
            U32 langid_Halant=0;
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ));
            if((dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                }
            }
        }
/* PMT END MAUI_00027239 */

        ems_cursor_pos_flag = 0;
        saved_last_skip_pos = 0;
	    multitap_to_cancel=0;
        middle_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
        second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText+2]);
        first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
#endif /* __MMI_INDIC_ALG__ */ 
        text_format = b->text_format;
        /* MTK Terry for EMS_NO_MEMORY or other error cause */
        
		//changes by pawanjeet 080307
		if (b->UCS2_count == 0 && UI_TEST_UCS2_CHARACTER(c))
		{
			gui_EMS_input_box_remove_extension_character(b->data);
		}
		//changes by pawanjeet 080307
		
        if (gui_EMS_input_box_add_string(b, s, &text_format) != EMS_OK /*==EMS_NO_SPACE */ )
        {
            UI_editor_play_tone_cannot_insert();
            b->overflow_callback();
        }
        else
        {
#ifdef __MMI_INDIC_ALG__
            p1=b->data->CurrentPosition;
            if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
            {
                object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
            }
            /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
            /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
            if((object_type_check1==1)&&( IRE_IS_CHAR_TYPE_CONSONANT( (U16)( (*first_cons_ems_position) | ((*(first_cons_ems_position+1))<<8) ) )) 
                 && (IRE_IS_CHAR_TYPE_CONSONANT((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) )) 
                 && (IRE_IS_CHAR_TYPE_HALANT((U16)( (*middle_ems_position) | ((*(middle_ems_position+1))<<8) ) )) ) 
            { 
                U32 langid_Halant=0;
                U32 diff_langid_cons_halant=0;
                langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2]
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
                if(langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                 | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) )))
                {
                    diff_langid_cons_halant =1;
                }
				if(!diff_langid_cons_halant)
				{
					U8 skip_positions = 0;
				    //U8 i=0;
				    U32 counter =0;
				    U32 langid_Consonant =0;
                    PU8 src_ems_pos = second_cons_ems_position;
                    PU8 dest_ems_pos;
				    UI_character_type previous_character2 = 0;
                    dest_ems_pos = ire_get_next_cluster_p(src_ems_pos, gui_show_EMS_input_box_find_segment_end(b->data,src_ems_pos));
                    skip_positions = dest_ems_pos - src_ems_pos;    /* Number of moves */
                    skip_positions = skip_positions >> 1;
                    saved_last_skip_pos = skip_positions;
				    first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
				    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ));
				
				    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                    p1=b->data->CurrentPosition;
				    while((1==gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1))&&(IRE_GET_CHARACTER_LANG_ID((U16)previous_character2)==langid_Consonant)&&IRE_IS_CHAR_TYPE_HALANT((U16)previous_character2))
					{
						counter +=2;
					    first_cons_ems_position-=2;
					    if(b->data->textBuffer>=first_cons_ems_position)
						{
							break;
						}
					    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                        gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1);
					
					}
				    counter= counter % ((G_MAX-2));
				    skip_positions = (G_MAX-2) - counter;
				    if(saved_last_skip_pos > skip_positions)
					{
						saved_last_skip_pos = skip_positions;

					}
					ForwardCurrentPosition(b->data, saved_last_skip_pos);
                                        ems_cursor_pos_flag = 1;
	
                    PRINT_INFORMATION_2(MMI_TRACE_INFO,"pixtel_UI_EMS_input_box_insert_multitap_character[skip_positions]:%d  ",
                                           saved_last_skip_pos);
                }
           }
           #endif /* __MMI_INDIC_ALG__ */ 
           b->change_callback();
        }
    }
    else
    {
#ifdef __MMI_INDIC_ALG__
	multitap_to_cancel =0;
        ems_cursor_pos_flag = 0;
        saved_last_skip_pos = 0;
        no_objects_adjusted=0;
        second_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText - 2]);
/* PMT START IRE CODE REVIEW */
        halant_cons_combination = ( (character_type==IRE_CHAR_TYPE_CON )
              && ( IRE_IS_CHAR_TYPE_HALANT( (U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ) ))  );
/* PMT END IRE CODE REVIEW */
        /*This statement does not allow addition of format object in the following cases: */
        /*1.When the input character is Dep. Vowel, Halant, Sign                          */
        /*2.When the previous character is Halant and input character is Consonant        */
        if(  dv_hal_sign_check ||  halant_cons_combination)
        {
            U32 langid_Halant=0;
            langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)( (*second_cons_ems_position) | ((*(second_cons_ems_position+1))<<8) ));
            if((dv_hal_sign_check) || ((halant_cons_combination) && (langid_Halant==IRE_GET_CHARACTER_LANG_ID((U16)(s[0] | (s[1]<<8) )))))
            {
                prev_text_format_flag=1;
                temp_text_format=b->text_format;
                if(b->data->CurrentTextFormatObj)
                {
                    b->text_format=b->data->CurrentTextFormatObj->data->text_format;
                }
                else
                    {
                    b->text_format=UI_EMS_normal_text_format_object.data->text_format;
                    }
 /* START PMT PATCH04052007 */
/*code is removed*/
/* END PMT PATCH04052007 */
            }
        }
#endif /* __MMI_INDIC_ALG__ */ 
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
        if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
        {
            if (gui_EMS_input_box_forward_cursor(b) == 1)
            {
                gui_EMS_cancel_current_position(b);
                text_format = b->text_format;
                /* MTK Terry for EMS_NO_MEMORY or other error cause */
                if (gui_EMS_input_box_add_string(b, s, &text_format) != EMS_OK /*==EMS_NO_SPACE */ )
                {
                    UI_editor_play_tone_cannot_insert();
                    b->overflow_callback();
                }
                else
                {
                    b->change_callback();
                }
            }
            /* to prevent to enable the multitap flag while reaching the max length(cannot add any char) */
            b->flags |= UI_EMS_INPUT_BOX_STATE_MULTITAP;

        }
        else
        {
            /* MTK Terry for EMS_NO_MEMORY or other error cause */
            if (gui_EMS_input_box_add_string(b, s, &b->text_format) != EMS_OK /*==EMS_NO_SPACE */ )
            {
                UI_editor_play_tone_cannot_insert();
                b->overflow_callback();
            }
            else
            {
                b->change_callback();
                /* MTK Elvis */
                b->flags |= UI_EMS_INPUT_BOX_STATE_MULTITAP;
                /* MTK end */
            }
        }
        //MTK Elvis
        //b->flags|=UI_EMS_INPUT_BOX_STATE_MULTITAP;
        //MTK end
        
    }
/*PMT IRE START*/
    
#ifdef __MMI_INDIC_ALG__
    /*This statement is to check whether prev_text_format_flag is set or not. */
    /*If it is set then reset the text formatng to the one previously added   */
    if(prev_text_format_flag)
    {
        b->text_format=temp_text_format;
    }
    if (TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        b->data->textBuffer[b->data->CurrentPosition.OffsetToText] = 0;
        b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1] = 0;
    }
	multitap_to_cancel =0;
/* PMT END MAUI_00024993 */
#endif /* __MMI_INDIC_ALG__ */ 
}
void gui_EMS_input_box_insert_multitap_character(UI_EMS_input_box *b, UI_character_type c)
{
    gui_EMS_input_box_insert_multitap_character_no_draw(b, c);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_confirm_multitap_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_confirm_multitap_character(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->flags &= ~UI_EMS_INPUT_BOX_STATE_MULTITAP;
}

extern EMSTextFormat wgui_EMS_text_format;


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_delete_all(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    ResetCurrentPosition(b->data);
    /* MTK Elvis 20040611 donot plan tone while the EMS data is empty. */

    /* MTK end */
    /* Probably a better way of doing this is to have a EMS library API  */
    GoToEndPosition(b->data);
    /* START TARUN 20041230 */
    memset(b->data->textBuffer, 0, b->data->CurrentPosition.OffsetToText);
    /* END TARUN 20041230 */
/*PMT IRE START*/
    #if defined(__MMI_INDIC_ALG__)
    IRE_RESET_LANGUAGE_VARIABLES();
    #endif
/*PMT IRE END*/
#if defined(__MMI_MESSAGES_CONCAT_SMS__)
    CancelCurrentPosition(b->data, (U16) (b->data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else 
    CancelCurrentPosition(b->data, (U16) (EMS_DEFAULT_DCS_ALLOCATED_LENGTH));
#endif 
    gui_EMS_input_box_set_text_format_cursor_position(b);
    gui_EMS_input_box_locate_cursor(b);
    b->UCS2_count = 0;
    b->object_count = 0;
    /* MTK Joy added for clear all, 1228 */
    b->GSM_ext_count = 0;
    /* MTK end */
    gui_EMS_change_DCS(b);
    b->saved_cursor_ax = -1;
    ResetTextFormat(&wgui_EMS_text_format);
}

#if(EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION)


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_delete_no_draw(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (UI_TEST_CR_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]))
    {
        if (ForwardCurrentPosition(b->data, 1) == 1)
        {
            if (!UI_TEST_LF_CHARACTER(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]))
            {
                BackwardCurrentPosition(b->data, 1);
            }
        }
    }
    if (gui_EMS_input_box_forward_cursor(b) == 1)
    {
        gui_EMS_cancel_current_position(b);
        gui_EMS_input_box_set_text_format_cursor_position(b);
        //gui_EMS_input_box_locate_cursor(b);
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }
}
void gui_EMS_input_box_delete(UI_EMS_input_box *b)
{
    gui_EMS_input_box_delete_no_draw(b);
    b->saved_cursor_ax = -1;
    gui_EMS_input_box_locate_cursor(b);
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous(UI_EMS_input_box *b)
{
#if defined(__MMI_LANG_VIETNAMESE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    UI_character_type current_character, dummy_c = 0;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Add Steven 20050505  */
#if defined(__MMI_LANG_THAI__)
    EMSPosition mapped_cursor_position_thai;
    UI_character_type current_character_thai, dummy_c_thai = 0;
    EMSData *data_thai = b->data;
    EMSObject *current_object_thai;
    U8 object_type_thai;
    UI_character_type pre_one_char = 0;
    UI_character_type pre_two_char = 0;
    UI_character_type pre_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
    EMSPosition mapped_cursor_position_arabic;
    UI_character_type current_character_arabic;
    EMSData *data_arabic = b->data;
    EMSObject *current_object_arabic;
    U8 object_type_arabic;
#endif /* __MMI_BIDI_ALG__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK End */

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    //EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &current_character, &current_object);
    if (1 == object_type)
    {
        if ((current_character >= 0x0300) && (current_character <= 0x0323))
        {
            object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &dummy_c, &current_object);      /* get next character */
            if (1 == object_type)
            {
                viet_vowel = mmi_viet_vowel_letter(dummy_c);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    tone_mark = mmi_viet_tone_mark(current_character);
                    if (VIET_TONE_NONE != tone_mark)
                    {
                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        BackwardCurrentPositionSkipCR(b->data);
                    }
                    else
                    {
                        object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                    }
                }
                else
                {
                    object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                }
            }
            else if (0 != object_type)
            {
                object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
            }
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    //EMS_map_position(data_thai, &data_thai->CurrentPosition, &mapped_cursor_position_thai);
    mapped_cursor_position_thai = data_thai->CurrentPosition;
    object_type_thai = gui_EMS_input_box_get_previous_object(
                        data_thai,
                        &mapped_cursor_position_thai,
                        &current_character_thai,
                        &current_object_thai);
    if (object_type_thai == 1 && isThaiChar(current_character_thai))    /* object type == 1 --> character */
    {
        object_type_thai = gui_EMS_input_box_get_previous_object(
                            data_thai,
                            &mapped_cursor_position_thai,
                            &pre_one_char,
                            &current_object_thai);
        if (object_type_thai == 1 && isThaiChar(pre_one_char))
        {
            if (!RequireToMoveCursor(pre_one_char, current_character_thai))
            {
                BackwardCurrentPositionSkipCR(b->data);
                object_type_thai = gui_EMS_input_box_get_previous_object(
                                    data_thai,
                                    &mapped_cursor_position_thai,
                                    &pre_two_char,
                                    &current_object_thai);
                if (object_type_thai == 1 && isThaiChar(pre_two_char))
                {
                    if (!RequireToMoveCursor(pre_two_char, pre_one_char))
                    {
                        BackwardCurrentPositionSkipCR(b->data);
                        object_type_thai = gui_EMS_input_box_get_previous_object(
                                            data_thai,
                                            &mapped_cursor_position_thai,
                                            &pre_three_char,
                                            &current_object_thai);
                        if (object_type_thai == 1 && isThaiChar(pre_three_char))
                        {
                            if (!RequireToMoveCursor(pre_three_char, pre_two_char))
                            {
                                BackwardCurrentPositionSkipCR(b->data);
                            }
                            else
                            {
                                object_type_thai = gui_EMS_input_box_get_next_object(
                                                    data_thai,
                                                    &mapped_cursor_position_thai,
                                                    &dummy_c_thai,
                                                    &current_object_thai);
                            }
                        }
                        else
                        {
                            object_type_thai = gui_EMS_input_box_get_next_object(
                                                data_thai,
                                                &mapped_cursor_position_thai,
                                                &dummy_c_thai,
                                                &current_object_thai);
                        }
                    }
                    else
                    {
                        object_type_thai = gui_EMS_input_box_get_next_object(
                                            data_thai,
                                            &mapped_cursor_position_thai,
                                            &dummy_c_thai,
                                            &current_object_thai);
                    }
                }
                else
                {
                    object_type_thai = gui_EMS_input_box_get_next_object(
                                        data_thai,
                                        &mapped_cursor_position_thai,
                                        &dummy_c_thai,
                                        &current_object_thai);
                }
            }
            else
            {
                object_type_thai = gui_EMS_input_box_get_next_object(
                                    data_thai,
                                    &mapped_cursor_position_thai,
                                    &dummy_c_thai,
                                    &current_object_thai);
            }
        }
        else
        {
            object_type_thai = gui_EMS_input_box_get_next_object(
                                data_thai,
                                &mapped_cursor_position_thai,
                                &dummy_c_thai,
                                &current_object_thai);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* PMT END URDU */
    mapped_cursor_position_arabic.OffsetToText = data_arabic->CurrentPosition.OffsetToText;
    mapped_cursor_position_arabic.Object = data_arabic->CurrentPosition.Object;
    object_type_arabic = gui_EMS_input_box_get_previous_object(
                            data_arabic,
                            &mapped_cursor_position_arabic,
                            &current_character_arabic,
                            &current_object_arabic);
    if (1 == object_type_arabic)
    {
        if (IS_ARABIC_CHARACTER(current_character_arabic))
        {
            U16 idx;

            idx = mapped_cursor_position_arabic.OffsetToText / 2;

            while (idx > 0)
            {
                if (OrgToSha[idx] == OrgToSha[idx - 1])
                {
                    BackwardCurrentPositionSkipCR(b->data);
                }
                else
                {
                    break;
                }
                idx--;
            }
        }
    }
//PMT START URDU
#endif /* __MMI_BIDI_ALG__ */ 
//PMT END URDU

    if (BackwardCurrentPositionSkipCR(b->data) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
        gui_EMS_input_box_locate_cursor(b);
        b->saved_cursor_ax = -1;
    }


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_forward_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_forward_cursor(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->CurrentPosition.OffsetToText <= (b->data->textLength))
    {   /* START TARUN 20041212 */
        if (ForwardCurrentPositionSkipCR(b->data) == 1)
            //if(ForwardCurrentPositionSkipCR(b->data)>=1)
            //END TARUN 20041212
        {
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next(UI_EMS_input_box *b)
{
#if defined(__MMI_LANG_VIETNAMESE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    UI_character_type current_character, dummy_c = 0;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Add Steven 20050505  */
#if defined(__MMI_LANG_THAI__)
    EMSPosition mapped_cursor_position_thai;
    UI_character_type current_character_thai, dummy_c_thai = 0;
    EMSData *data_thai = b->data;
    EMSObject *current_object_thai;
    U8 object_type_thai;
    UI_character_type next_one_char = 0;
    UI_character_type next_two_char = 0;
    UI_character_type next_three_char = 0;
#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
    EMSPosition mapped_cursor_position_arabic;
    UI_character_type current_character_arabic;
    EMSData *data_arabic = b->data;
    EMSObject *current_object_arabic;
    U8 object_type_arabic;
#endif /* defined(__MMI_BIDI_ALG__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK End */

#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    //EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &current_character, &current_object);
    if (1 == object_type)
    {
        if ((current_character > 0x0040) && (current_character < 0x01B1))
        {
            object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);  /* get next character */
            if (1 == object_type)
            {
                tone_mark = mmi_viet_tone_mark(dummy_c);
                if (VIET_TONE_NONE != tone_mark)
                {
                    viet_vowel = mmi_viet_vowel_letter(current_character);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        gui_EMS_input_box_forward_cursor(b);
                    }
                    else
                    {
                        object_type = gui_EMS_input_box_get_previous_object(
                                        data,
                                        &mapped_cursor_position,
                                        &dummy_c,
                                        &current_object);
                    }
                }
                else
                {
                    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                }
            }
            else if (0 != object_type)
            {
                object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
            }
        }
    }

#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /* MTK Steven 20050505 */
#if defined(__MMI_LANG_THAI__)
    //EMS_map_position(data_thai, &data_thai->CurrentPosition, &mapped_cursor_position_thai);
    mapped_cursor_position_thai = data_thai->CurrentPosition;
    object_type_thai = gui_EMS_input_box_get_next_object(
                        data_thai,
                        &mapped_cursor_position_thai,
                        &current_character_thai,
                        &current_object_thai);
    if (object_type_thai == 1 && isThaiChar(current_character_thai))    /* object type == 1 --> character */
    {
        object_type_thai = gui_EMS_input_box_get_next_object(
                            data_thai,
                            &mapped_cursor_position_thai,
                            &next_one_char,
                            &current_object_thai);
        if (object_type_thai == 1 && isThaiChar(next_one_char))
        {
            if (!RequireToMoveCursor(current_character_thai, next_one_char))
            {
                gui_EMS_input_box_forward_cursor(b);
                object_type_thai = gui_EMS_input_box_get_next_object(
                                    data_thai,
                                    &mapped_cursor_position_thai,
                                    &next_two_char,
                                    &current_object_thai);
                if (object_type_thai == 1 && isThaiChar(next_two_char))
                {
                    if (!RequireToMoveCursor(next_one_char, next_two_char))
                    {
                        gui_EMS_input_box_forward_cursor(b);
                        object_type_thai = gui_EMS_input_box_get_next_object(
                                            data_thai,
                                            &mapped_cursor_position_thai,
                                            &next_three_char,
                                            &current_object_thai);
                        if (object_type_thai == 1 && isThaiChar(next_three_char))
                        {
                            if (!RequireToMoveCursor(next_two_char, next_three_char))
                            {
                                gui_EMS_input_box_forward_cursor(b);
                            }
                            else
                            {
                                object_type_thai = gui_EMS_input_box_get_previous_object(
                                                    data_thai,
                                                    &mapped_cursor_position_thai,
                                                    &dummy_c_thai,
                                                    &current_object_thai);
                            }
                        }
                        else
                        {
                            object_type_thai = gui_EMS_input_box_get_previous_object(
                                                data_thai,
                                                &mapped_cursor_position_thai,
                                                &dummy_c_thai,
                                                &current_object_thai);
                        }
                    }
                    else
                    {
                        object_type_thai = gui_EMS_input_box_get_previous_object(
                                            data_thai,
                                            &mapped_cursor_position_thai,
                                            &dummy_c_thai,
                                            &current_object_thai);
                    }
                }
                else
                {
                    object_type_thai = gui_EMS_input_box_get_previous_object(
                                        data_thai,
                                        &mapped_cursor_position_thai,
                                        &dummy_c_thai,
                                        &current_object_thai);
                }
            }
            else
            {
                object_type_thai = gui_EMS_input_box_get_previous_object(
                                    data_thai,
                                    &mapped_cursor_position_thai,
                                    &dummy_c_thai,
                                    &current_object_thai);
            }
        }
        else
        {
            object_type_thai = gui_EMS_input_box_get_previous_object(
                                data_thai,
                                &mapped_cursor_position_thai,
                                &dummy_c_thai,
                                &current_object_thai);
        }
    }

#endif /* defined(__MMI_LANG_THAI__) */ 
    /* MTK End */

/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* PMT END URDU */
    mapped_cursor_position_arabic.OffsetToText = data_arabic->CurrentPosition.OffsetToText;
    mapped_cursor_position_arabic.Object = data_arabic->CurrentPosition.Object;
    object_type_arabic = gui_EMS_input_box_get_next_object(
                            data_arabic,
                            &mapped_cursor_position_arabic,
                            &current_character_arabic,
                            &current_object_arabic);
    if (1 == object_type_arabic)
    {
        if (IS_ARABIC_CHARACTER(current_character_arabic))
        {
            U16 idx;

            idx = data_arabic->CurrentPosition.OffsetToText/2;

            while (idx < unshaped_text_len)
            {
                if (OrgToSha[idx] == OrgToSha[idx + 1])
                {
                    gui_EMS_input_box_forward_cursor(b);
                }
                else
                {
                    break;
                }
                idx++;
            }
        }
    }
#endif /* #if defined(__MMI_BIDI_ALG__) */

    if (gui_EMS_input_box_forward_cursor(b) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    else
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
        gui_EMS_input_box_locate_cursor(b);
        b->saved_cursor_ax = -1;
    }

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}

#else /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_delete(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (gui_EMS_input_box_forward_cursor(b) == 1)
    {
        gui_EMS_cancel_current_position(b);
        gui_EMS_input_box_set_text_format_cursor_position(b);
        gui_EMS_input_box_locate_cursor(b);
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous(UI_EMS_input_box *b)
{
#if defined(__MMI_LANG_VIETNAMESE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    UI_character_type current_character, dummy_c = 0;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__)
/* PMT END URDU */
    EMSPosition mapped_cursor_position_arabic;
    UI_character_type current_character_arabic;
    EMSData *data_arabic = b->data;
    EMSObject *current_object_arabic;
    U8 object_type_arabic;
#endif /* #if defined(__MMI_BIDI_ALG__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    //EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &current_character, &current_object);
    if (1 == object_type)
    {
        if ((current_character >= 0x0300) && (current_character <= 0x0323))
        {
            object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &dummy_c, &current_object);      /* get next character */
            if (1 == object_type)
            {
                viet_vowel = mmi_viet_vowel_letter(dummy_c);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    tone_mark = mmi_viet_tone_mark(current_character);
                    if (VIET_TONE_NONE != tone_mark)
                    {
                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        BackwardCurrentPosition(b->data, 1);
                    }
                    else
                    {
                        object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                    }
                }
                else
                {
                    object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                }
            }
            else if (0 != object_type)
            {
                object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
            }
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* PMT END URDU */
    mapped_cursor_position_arabic.OffsetToText = data_arabic->CurrentPosition.OffsetToText;
    mapped_cursor_position_arabic.Object = data_arabic->CurrentPosition.Object;
    object_type_arabic = gui_EMS_input_box_get_previous_object(
                            data_arabic,
                            &mapped_cursor_position_arabic,
                            &current_character_arabic,
                            &current_object_arabic);
    if (1 == object_type_arabic)
    {
        if (IS_ARABIC_CHARACTER(current_character_arabic))
        {
            U16 idx;

            idx = mapped_cursor_position_arabic.OffsetToText / 2;

            while (idx > 0)
            {
                if (OrgToSha[idx] == OrgToSha[idx - 1])
                {
                    BackwardCurrentPositionSkipCR(b->data);
                }
                else
                {
                    break;
                }
                idx--;
            }
        }
    }
#endif /* #if defined(__MMI_BIDI_ALG__) */

    if (BackwardCurrentPosition(b->data, 1) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    gui_EMS_input_box_set_text_format_cursor_position(b);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_forward_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_forward_cursor(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->CurrentPosition.OffsetToText <= (b->data->textLength))
    {
        if (ForwardCurrentPosition(b->data, 1) == 1)
        {
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next(UI_EMS_input_box *b)
{
#if defined(__MMI_LANG_VIETNAMESE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    UI_character_type current_character, dummy_c = 0;
    EMSData *data = b->data;
    EMSObject *current_object;
    U8 object_type;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__)
/* PMT END URDU */
    EMSPosition mapped_cursor_position_arabic;
    UI_character_type current_character_arabic;
    EMSData *data_arabic = b->data;
    EMSObject *current_object_arabic;
    U8 object_type_arabic;
#endif /* #if defined(__MMI_BIDI_ALG__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    //EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    mapped_cursor_position = data->CurrentPosition;
    object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &current_character, &current_object);
    if (1 == object_type)
    {
        if ((current_character > 0x0040) && (current_character < 0x01B1))
        {
            object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);  /* get next character */
            if (1 == object_type)
            {
                tone_mark = mmi_viet_tone_mark(dummy_c);
                if (VIET_TONE_NONE != tone_mark)
                {
                    viet_vowel = mmi_viet_vowel_letter(current_character);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                        gui_EMS_input_box_forward_cursor(b);
                    }
                    else
                    {
                        object_type = gui_EMS_input_box_get_previous_object(
                                        data,
                                        &mapped_cursor_position,
                                        &dummy_c,
                                        &current_object);
                    }
                }
                else
                {
                    object_type = gui_EMS_input_box_get_previous_object(data, &mapped_cursor_position, &dummy_c, &current_object);
                }
            }
            else if (0 != object_type)
            {
                object_type = gui_EMS_input_box_get_next_object(data, &mapped_cursor_position, &dummy_c, &current_object);
            }
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/*PMT IRE START*/
/* PMT START URDU */
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
/* PMT END URDU */
/*PMT IRE END*/    
    mapped_cursor_position_arabic.OffsetToText = data_arabic->CurrentPosition.OffsetToText;
    mapped_cursor_position_arabic.Object = data_arabic->CurrentPosition.Object;
    object_type_arabic = gui_EMS_input_box_get_next_object(
                            data_arabic,
                            &mapped_cursor_position_arabic,
                            &current_character_arabic,
                            &current_object_arabic);
    if (1 == object_type_arabic)
    {
        if (IS_ARABIC_CHARACTER(current_character_arabic))
        {
            U16 idx;

            idx = data_arabic->CurrentPosition.OffsetToText/2;

            while (idx < unshaped_text_len)
            {
                if (OrgToSha[idx] == OrgToSha[idx + 1])
                {
                    gui_EMS_input_box_forward_cursor(b);
                }
                else
                {
                    break;
                }
                idx++;
            }
        }
    }
/* PMT START URDU */
#endif /* defined(__MMI_BIDI_ALG__)*/ 
/* PMT END URDU */
    if (gui_EMS_input_box_forward_cursor(b) != 1)
    {
        UI_editor_play_tone_cannot_navigate();
    }
    gui_EMS_input_box_set_text_format_cursor_position(b);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}

#endif /* (EMS_USE_CRLF_COMBINATION || EMS_USE_ESC_COMBINATION) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_move_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_EMS_input_box(UI_EMS_input_box *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_EMS_input_box(UI_EMS_input_box *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    gui_move_vertical_scrollbar(&b->vbar, b->x + b->width - b->vbar.width - 1, b->y + 1);
    gui_resize_vertical_scrollbar(&b->vbar, b->vbar.width, b->height - 2);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}

/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_next_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_next_object(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{
#if(0)  /* Error in code: Do not enable this block   */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    byte        return_type=0;

    if((current_position->Object!=NULL) && (current_position->Object->OffsetToText==current_position->OffsetToText))
    {
        if((current_position->Object->next!=NULL) && (current_position->Object->OffsetToText==current_position->Object->next->OffsetToText))
        {
            return_type=2;
            *o=current_position->Object;
            current_position->Object=current_position->Object->next;
        }
        else if(current_position->OffsetToText<=EMS_DATA_END_OFFSET(data->textLength))
        {
            return_type=2;
            *o=current_position->Object;
            current_position->Object=current_position->Object->next;
        }
    }
    else if(current_position->OffsetToText<EMS_DATA_END_OFFSET(data->textLength))
    {
        return_type=1;
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
        *c=(data->textBuffer[current_position->OffsetToText+1]|(data->textBuffer[current_position->OffsetToText]<<8));
#else
        *c=(data->textBuffer[current_position->OffsetToText]|(data->textBuffer[current_position->OffsetToText+1]<<8));
#endif
        current_position->OffsetToText+=2;
    }
    return(return_type);
#else /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (EMSGetNextObject(data, current_position, c, o));
#endif /* (0) */ 
}

/* MTK Add By Elvis for Input method */
/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_next_object_for_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_next_object_for_input_method(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 return_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_position->Object != NULL)
    {
        if (current_position->Object->next != NULL &&
            current_position->Object->next->OffsetToText == current_position->OffsetToText)
        {
            return_type = 2;
            *o = current_position->Object->next;
            current_position->Object = current_position->Object->next;
        }
        else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
        {
            return_type = 1;
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            *c = (data->
                  textBuffer[current_position->OffsetToText +
                             1] | (data->textBuffer[current_position->OffsetToText] << 8));
        #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            *c = (data->
                  textBuffer[current_position->OffsetToText] | (data->
                                                                textBuffer[current_position->OffsetToText + 1] << 8));
        #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            current_position->OffsetToText += 2;
        }
    }
    else if (data->listHead != NULL)
    {
        if (data->listHead->OffsetToText == current_position->OffsetToText)
        {
            return_type = 2;
            *o = data->listHead;
            current_position->Object = data->listHead;
        }
        else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
        {
            return_type = 1;
        #if(EMS_BYTE_ORDER_BIG_ENDIAN)
            *c = (data->
                  textBuffer[current_position->OffsetToText +
                             1] | (data->textBuffer[current_position->OffsetToText] << 8));
        #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            *c = (data->
                  textBuffer[current_position->OffsetToText] | (data->
                                                                textBuffer[current_position->OffsetToText + 1] << 8));
        #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            current_position->OffsetToText += 2;
        }

    }
    else if (current_position->OffsetToText < EMS_DATA_END_OFFSET(data->textLength))
    {
        return_type = 1;
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        *c = (data->
              textBuffer[current_position->OffsetToText + 1] | (data->textBuffer[current_position->OffsetToText] << 8));
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        *c = (data->
              textBuffer[current_position->OffsetToText] | (data->textBuffer[current_position->OffsetToText + 1] << 8));
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_position->OffsetToText += 2;
    }
    return (return_type);
}

/* MTK end */

/* Returns 0: none, 1: character, 2:object   */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                    [?]         
 *  current_position        [?]         
 *  c                       [?]         
 *  o                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_object(
    EMSData *data,
    EMSPosition *current_position,
    UI_character_type *c,
    EMSObject **o)
{
    return (EMSGetPreviousObject(data, current_position, c, o));
    }
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_get_previous_character
 * DESCRIPTION
 *  to get previous character according to current cursor position
 * PARAMETERS
 *  b        [IN]          UI_EMS_input_box context object
 *  c        [OUT]         return character's unicode    
 * RETURNS
 *  1 -> success
 *  0 -> no character return
 *****************************************************************************/
U8 gui_EMS_input_box_get_previous_character(UI_EMS_input_box *b, UI_character_type *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current_object = NULL;
    EMSPosition mapped_cursor_position;
    U8 ret = 0;
    EMSData *data = b->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);    
    ret = gui_EMS_input_box_get_previous_object(
            data,
            &mapped_cursor_position,
            c,
            &current_object);

    if(ret == 1) /* character */
    {
        return 1;
    }
    else
    {
        return 0;
    }
            
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  flags       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_EMS_input_box_cursor(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cursor_type = (U8) (flags & 0x0f);
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cursor_type == 1)
    {
        x1 = x - 1;
        y1 = y;
        x2 = x;
        y2 = y + height - 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
    #if(UI_BLINKING_CURSOR_SUPPORT)
        UI_inputbox_show_cursor(x1, y1, x2, y2, b->cursor_color);
    #else 
        UI_cursor_x1 = x1;
        UI_cursor_y1 = y1;
        UI_cursor_x2 = x2;
        UI_cursor_y2 = y2;

        gui_fill_rectangle(x1, y1, x2, y2, b->cursor_color);
    #endif 
    }
    else if (cursor_type == 2)
    {
        x1 = x - 2;
        y1 = y;
        x2 = x - 1;
        y2 = y + height - 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
    #if(UI_BLINKING_CURSOR_SUPPORT)
        UI_inputbox_show_cursor(x1, y1, x2, y2, b->cursor_color);
    #else /* (UI_BLINKING_CURSOR_SUPPORT) */ 
        UI_cursor_x1 = x1;
        UI_cursor_y1 = y1;
        UI_cursor_x2 = x2;
        UI_cursor_y2 = y2;

        gui_fill_rectangle(x1, y1, x2, y2, b->cursor_color);
    #endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
    }
    else if (cursor_type == 3)
    {
        x1 = x - 1;
        y1 = y - 1;
        x2 = x + width - 1 + 1;
        y2 = y + height - 1 + 1;
        if (x1 < (b->x + 1))
        {
            x1 = b->x + 1;
        }
        if (y1 < (b->y + 1))
        {
            y1 = b->y + 1;
        }
        if (x2 > (b->x + b->width - 2))
        {
            x2 = b->x + b->width - 2;
        }
        if (y2 > (b->y + b->height - 2))
        {
            y2 = b->y + b->height - 2;
        }
    #if(UI_BLINKING_CURSOR_SUPPORT)
        StopTimer(BLINKING_CURSOR);
    #endif
        gui_draw_rectangle(x1, y1, x2, y2, b->cursor_color);
    }
}

/* MTK end */

/* CRLF/Esc sequence handling functions:              */
/* These must be made available in the EMS library       */
/* Navigates CRLF/Esc sequence as a single object        */
/* Currently assumes Little endian byte ordering only    */
/* Supports only steps=1                           */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionSkipCR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 BackwardCurrentPositionSkipCR(EMSData *data)
{
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type current_character = 0;
    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = data->CurrentPosition;
    EMSData *data_chk_type = data;
    UI_character_type dummy_c = 0;
    S32 prev_ems_moves = 0;
    UI_buffer_type check_ems_hindi_p;
    PU8 src_p;
    PU8 dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_ems_hindi_p = src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);

    UI_STRING_GET_PREVIOUS_CHARACTER(check_ems_hindi_p, dummy_c);       /* get previous character */
/*PMT IRE START*/
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        dest_p = ire_get_prev_cluster_p(gui_show_EMS_input_box_find_segment_start(data,src_p), src_p);
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
        prev_ems_moves = src_p - dest_p;
        prev_ems_moves = prev_ems_moves >> 1;
        object_type_check = gui_EMS_input_box_get_previous_object(data_chk_type, &p, &current_character, &o);
        if (object_type_check == 2)
        {
            prev_ems_moves = 1;
        }
    }
    else
    {
        prev_ems_moves = 1;
    }
    /* To be checked why its returning 0 for prev_ems_moves>1 */
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "BackwardCurrentPositionSkipCR[prev_ems_moves]:%d  ", prev_ems_moves);
    MMI_ASSERT(!(prev_ems_moves < 0));
    if (BackwardCurrentPosition(data, prev_ems_moves) >= 1)
/*PMT IRE START*/
#else /* __MMI_INDIC_ALG__ */ 
    if (BackwardCurrentPosition(data, 1) == 1)
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    {
        if (data->textBuffer == NULL)
        {
            return (1);
        }
    #if(EMS_USE_CRLF_COMBINATION)
        if (UI_TEST_LF_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
        {
            if (BackwardCurrentPosition(data, 1) == 1)
            {
                if (!UI_TEST_CR_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
                {
                    ForwardCurrentPosition(data, 1);
                }
            }
        }
    #endif /* (EMS_USE_CRLF_COMBINATION) */ 
    #if(EMS_USE_ESC_COMBINATION)
        if (BackwardCurrentPosition(data, 1) == 1)
        {

            if (!UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
            {
                ForwardCurrentPosition(data, 1);
            }
/*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
            //changes by pawanjeet 080707
            /*else if ((UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText])) &&
                     (data->textBuffer[data->CurrentPosition.OffsetToText + 1 == 0x09]))
            {
                ForwardCurrentPosition(data, 1);
            }*/
            //changes by pawanjeet 080707
        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
        }
    #endif /* (EMS_USE_ESC_COMBINATION) */ 
        return (1);
    }
    return (0);
}

/* Navigates CRLF/Esc sequence as a single object        */
/* Currently assumes Little endian byte ordering only    */
/* Supports only steps=1                           */


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionSkipCR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 ForwardCurrentPositionSkipCR(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 count = 0;
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    UI_character_type current_character = 0;
    U8 object_type_check;
    EMSObject *o;
    EMSPosition p = data->CurrentPosition;
    EMSData *data_chk_type = data;
    UI_character_type dummy_c = 0;
    S32 next_ems_moves = 0;
    UI_buffer_type check_ems_hindi_p;
    PU8 src_p;
    PU8 dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_ems_hindi_p = src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);

    UI_STRING_GET_NEXT_CHARACTER(check_ems_hindi_p, dummy_c);   /* get previous character */
/*PMT IRE START*/  
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(dummy_c))
    {
        /* Move by a syllable rather than by a character as in English */
/* PMT START MAUI_00027731 */
        dest_p = ire_get_next_cluster_p(src_p, gui_show_EMS_input_box_find_segment_end(data,src_p));
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
        next_ems_moves = dest_p - src_p;
        next_ems_moves = next_ems_moves >> 1;
        object_type_check = gui_EMS_input_box_get_next_object(data_chk_type, &p, &current_character, &o);
        if (object_type_check == 2 && (next_ems_moves >= 2) && p.Object->Type == EMS_TYPE_TEXT_FORMAT)
        {
            /* Do nothing */
        }

        else if (object_type_check == 2)
        {
            next_ems_moves = 1;
        }
    }
    else
    {
        next_ems_moves = 1;
    }
/*PMT IRE START*/
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
    if (data->textBuffer == NULL)
    {
        count = ForwardCurrentPosition(data, 1);
        return (count);
    }
#if(EMS_USE_ESC_COMBINATION)
    if ((data->dcs == SMSAL_DEFAULT_DCS) &&
        (UI_TEST_ESC_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText])))
    {
        count = ForwardCurrentPosition(data, 1);
        if (count == 1)
        {
            ForwardCurrentPosition(data, 1);
        }
    }
    else
#endif /* (EMS_USE_ESC_COMBINATION) */ 
#if(EMS_USE_CRLF_COMBINATION)
    if (UI_TEST_CR_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
    {
        count = ForwardCurrentPosition(data, 1);
        if (UI_TEST_LF_CHARACTER(data->textBuffer[data->CurrentPosition.OffsetToText]))
        {
            ForwardCurrentPosition(data, 1);
        }
    }
    else
#endif /* (EMS_USE_CRLF_COMBINATION) */ 
    {
/*PMT IRE START*/
    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "ForwardCurrentPositionSkipCR[next_ems_moves]:%d  ", next_ems_moves);
        MMI_ASSERT(!(next_ems_moves < 0));
        count = ForwardCurrentPosition(data, next_ems_moves);
        if (count >= 1)
        {
            count = 1;
        }
/*PMT IRE START*/
    #else /* __MMI_INDIC_ALG__ */ 
        count = ForwardCurrentPosition(data, 1);
    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
    }
    return (count);
}

/* Moves the cursor forwards by the number of steps specified.
   Cursor starts at start position. (If data->CursorPosition is not at
   the given start position, then the cursor will be moved to start position first)
   The cursor will not move beyond one step before the given end position  */


/*****************************************************************************
 * FUNCTION
 *  MoveCurrentPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  start       [?]         
 *  end         [?]         
 *  steps       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MoveCurrentPosition(EMSData *data, EMSPosition *start, EMSPosition *end, kal_uint16 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    U8 object_flag;
    U8 done_flag = 0;
    S32 count = 0;
    U8 back_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_flag = 0;
    diff = data->CurrentPosition.OffsetToText - start->OffsetToText;
    if ((start->Object != NULL) && (start->Object->OffsetToText == start->OffsetToText))
    {
        object_flag = 1;
    }
    if (diff < 0)
    {
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else if (diff > 0)
    {
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        while (!done_flag)
        {
            if (data->CurrentPosition.OffsetToText == start->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == start->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == start->OffsetToText))
                    {
                        BackwardCurrentPosition(data, 1);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    if (steps == 0)
    {
        return;
    }
    object_flag = 0;
    if ((end->Object != NULL) && (end->Object->OffsetToText == end->OffsetToText))
    {
        object_flag = 1;
    }
    if (data->CurrentPosition.OffsetToText == end->OffsetToText)
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
            count--;
        }
        while (!done_flag)
        {
            if (count >= steps)
            {
                break;
            }
            count++;
            if (data->CurrentPosition.OffsetToText == end->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == end->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == end->OffsetToText))
                    {
                        back_flag = 1;
                        break;
                    }
                }
                else
                {
                    back_flag = 1;
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (back_flag)
        {
            BackwardCurrentPosition(data, 1);
        }
        if (data->CurrentPosition.OffsetToText > end->OffsetToText)
        {
            BackwardCurrentPosition(data, 1);
        }
    }
    else
    {
        while (!done_flag)
        {
            if (count >= steps)
            {
                break;
            }
            count++;
            if (data->CurrentPosition.OffsetToText == end->OffsetToText)
            {
                if (object_flag)
                {
                    if ((data->CurrentPosition.Object == end->Object) &&
                        (data->CurrentPosition.Object->OffsetToText == end->OffsetToText))
                    {
                        back_flag = 1;
                        break;
                    }
                }
                else
                {
                    back_flag = 1;
                    break;
                }
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (back_flag)
        {
            BackwardCurrentPosition(data, 1);
        }
        if (data->CurrentPosition.OffsetToText >= end->OffsetToText)
        {
            if ((end->OffsetToText != data->textLength) && !((end->Object != NULL) && (end->Object != data->listHead)))
            {
                BackwardCurrentPosition(data, 1);
            }
            if ((data->CurrentPosition.Object != NULL) && (end->Object != NULL))
            {
                while (data->CurrentPosition.Object->OffsetToText > end->Object->OffsetToText)
                {
                    if (BackwardCurrentPosition(data, 1) != 1)
                    {
                        break;
                    }
                }
            }
        }
    }
}

/* Moves the cursor to a given position   */


/*****************************************************************************
 * FUNCTION
 *  MoveCursorToPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void MoveCursorToPosition(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    U8 done_flag = 0;
    EMSPosition dst_copy = *dst;
    EMSPosition mapped_cursor_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_map_position(data, &dst_copy, dst);
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    diff = data->CurrentPosition.OffsetToText - dst->OffsetToText;

    if (diff < 0)
    {
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if ((mapped_cursor_position.OffsetToText == dst->OffsetToText) &&
                (mapped_cursor_position.Object == dst->Object))
            {
                break;
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else if (diff > 0)
    {
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if ((mapped_cursor_position.OffsetToText == dst->OffsetToText) &&
                (mapped_cursor_position.Object == dst->Object))
            {
                break;
            }
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
    else
    {
        S32 old_OffsetToText = data->CurrentPosition.OffsetToText;

        while (data->CurrentPosition.OffsetToText == old_OffsetToText)
        {
            if (BackwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
        if (data->CurrentPosition.OffsetToText < old_OffsetToText)
        {
            ForwardCurrentPosition(data, 1);
        }
        while (!done_flag)
        {
            EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
            if (mapped_cursor_position.Object == dst->Object)
            {
                break;
            }
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        }
    }
}

/* Moves the cursor backwards to the given position. If an object is encountered, it breaks  */
/* Returns 1 if dst is reached, otherwise, returns 0                                */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 BackwardCurrentPositionObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        if (BackwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
    }
    return (done);
}


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 ForwardCurrentPositionObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        if (ForwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
    }
    return (done);
}

/* Moves the cursor backwards to the given position. If an object is encountered, it breaks  */
/* Returns 1 if dst is reached, otherwise, returns 0                                */


/*****************************************************************************
 * FUNCTION
 *  BackwardCurrentPositionSeekObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 BackwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;
    U8 object_flag = 0;
    EMSPosition last_object_position = data->CurrentPosition;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            last_object_position = data->CurrentPosition;
            object_flag = 1;
            if (count > 0)
            {
                break;
            }
        }
        if (BackwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
        count++;
    }
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    if (object_flag && (count > 0) &&
        ((data->CurrentPosition.OffsetToText != dst->OffsetToText) || (data->CurrentPosition.Object != dst->Object)))
    {
        MoveCursorToPosition(data, &last_object_position);
    }
    else if (mapped_cursor_position.Object == NULL)
    {
        MoveCursorToPosition(data, &last_object_position);
    }
    return (done);
}


/*****************************************************************************
 * FUNCTION
 *  ForwardCurrentPositionSeekObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  dst         [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 ForwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition mapped_cursor_position;
    U8 done = 0;
    EMSPosition last_object_position = data->CurrentPosition;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
    {
        return (1);
    }
    while (!done)
    {
        EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
        if ((mapped_cursor_position.Object != NULL) && (mapped_cursor_position.Object->Type != EMS_TYPE_TEXT_FORMAT))
        {
            last_object_position = data->CurrentPosition;
            if (count > 0)
            {
                break;
            }
        }
        if (ForwardCurrentPosition(data, 1) != 1)
        {
            done = 1;
            break;
        }
        if ((data->CurrentPosition.OffsetToText == dst->OffsetToText) && (data->CurrentPosition.Object == dst->Object))
        {
            done = 1;
            break;
        }
        count++;
    }
    MoveCursorToPosition(data, &last_object_position);
    return (done);
}

/* Returns true if the given position is the last position  */
/* p=un-mapped EMS position                        */


/*****************************************************************************
 * FUNCTION
 *  TestLastPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 TestLastPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_map_position(data, p, &dst);
    if ((dst.OffsetToText >= data->textLength) && (dst.Object == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/* Returns true if the given position is the first position */
/* p=un-mapped EMS position                        */


/*****************************************************************************
 * FUNCTION
 *  TestFirstPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 TestFirstPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p->OffsetToText == 0) && (p->Object == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_map_position
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  src         [?]     
 *  dst         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_map_position(EMSData *data, EMSPosition *src, EMSPosition *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->listHead == NULL)
    {
        *dst = *src;
    }
    else
    {
        EMSObject *object;

        if (src->Object == NULL)
        {
            object = data->listHead;
            if (object->OffsetToText == src->OffsetToText)
            {

            #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                /* Nov-21-2003: TESTFIX: text format object followed by EMS object fix                 */
                /* Object ordering must be as text format object followed by other objects to use this fix   */
                if (object != NULL)
                {
                    if (object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        if (object->next != NULL)
                        {
                            if (object->next->OffsetToText == object->OffsetToText)
                            {
                                dst->OffsetToText = src->OffsetToText;
                                dst->Object = object->next;
                            }
                            else
                            {
                                dst->OffsetToText = src->OffsetToText;
                                dst->Object = object;
                            }
                        }
                        else
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = NULL; //JF: fixed for cursor in text format, it should not mapping to a text format.
                        }
                    }
                    else
                    {
                        dst->OffsetToText = src->OffsetToText;
                        dst->Object = object;
                    }
                }
                else
                {
                    /* Nov-21-2003: TESTFIX: ends */
            #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 

                    dst->OffsetToText = src->OffsetToText;
                    dst->Object = object;

                #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                    /* Nov-21-2003: TESTFIX    */
                }
                /* Nov-21-2003: TESTFIX: ends */
                #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
            }
            else
            {
                dst->OffsetToText = src->OffsetToText;
                dst->Object = NULL;
            }
        }
        else
        {
            object = src->Object->next;
            if ((object != NULL) && (object->OffsetToText == src->OffsetToText))
            {
            #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                /* Nov-21-2003: TESTFIX: text format object followed by EMS object fix                 */
                /* Object ordering must be as text format object followed by other objects to use this fix   */
                if (object->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    if (object->next != NULL)
                    {
                        if (object->next->OffsetToText == object->OffsetToText)
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = object->next;
                        }
                        else
                        {
                            dst->OffsetToText = src->OffsetToText;
                            dst->Object = NULL;
                        }
                    }
                    else
                    {
                        dst->OffsetToText = src->OffsetToText;
                        dst->Object = NULL;
                    }
                }
                else
                {
                    /* Nov-21-2003: TESTFIX: ends */
            #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 

                    dst->OffsetToText = src->OffsetToText;
                    dst->Object = object;

                #if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
                    /* Nov-21-2003: TESTFIX    */
                }
                /* Nov-21-2003: TESTFIX: ends */
                #endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
            }
            else
            {
                dst->OffsetToText = src->OffsetToText;
                dst->Object = NULL;
            }
        }
    }
}

U8 EMS_view_mode = 0;

#ifdef __MMI_MESSAGES_EMS__

#define EMS_ANIMATION_TIME    500

S32 EMS_current_predefined_sound_ID = -1;
U8 EMS_object_pre_defined_sound_flag = 0;
U8 EMS_object_user_defined_melody_flag = 0;
PU8 EMS_editor_sound_icon = NULL;
PU8 EMS_editor_melody_icon = NULL;
S32 EMS_object_x = 0;
S32 EMS_object_y = 0;
S32 EMS_object_width = 0;
S32 EMS_object_height = 0;
S32 EMS_object_frame_counter = 0;
S32 EMS_object_n_frames = 0;
S32 EMS_object_current_frame_size = 0;
S32 EMS_object_repeat_counter = 0;
U8 EMS_object_animation_timer_flag = 0;
U8 EMS_object_predefined_animation_timer_flag = 0;
EMSObject *EMS_current_object = NULL;
PU8 EMS_current_predefined_image;

extern PU8 get_image(U16 i);
extern void AudioPlayIMelodyString(U8 *string, U16 len, U8 style);
extern U16 EMS_predefined_sounds[];

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_is_play_activated(void);
#endif 


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_play_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_play_pre_defined_sound(S32 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ID < 0)
    {
        ID = 0;
    }
    if (ID > 9)
    {
        ID = 9;
    }
    EMS_current_predefined_sound_ID = EMS_predefined_sounds[ID];
    StopCurrentKeyPadTone();
    AudioPlayReq((U8) EMS_current_predefined_sound_ID, DEVICE_AUDIO_PLAY_ONCE);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_stop_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_stop_pre_defined_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq((U8) EMS_current_predefined_sound_ID);
}

#include "Mdi_datatype.h"
#include "Mdi_audio.h"


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_play_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_play_user_defined_melody(U8 *data, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_string(data, (U16) length, MDI_FORMAT_IMELODY, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_normal_stop_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_normal_stop_user_defined_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_string();
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_play_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_play_pre_defined_sound(S32 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(ID);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_stop_pre_defined_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_stop_pre_defined_sound(void)
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
 *  EMS_silent_play_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_play_user_defined_melody(U8 *data, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(data);
    UI_UNUSED_PARAMETER(length);
}


/*****************************************************************************
 * FUNCTION
 *  EMS_silent_stop_user_defined_melody
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_silent_stop_user_defined_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

void (*EMS_play_pre_defined_sound) (S32 ID) = EMS_normal_play_pre_defined_sound;
void (*EMS_stop_pre_defined_sound) (void) = EMS_normal_stop_pre_defined_sound;
void (*EMS_play_user_defined_melody) (U8 *data, S32 length) = EMS_normal_play_user_defined_melody;
void (*EMS_stop_user_defined_melody) (void) = EMS_normal_stop_user_defined_melody;


/*****************************************************************************
 * FUNCTION
 *  EMS_enable_audio_playback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_enable_audio_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_play_pre_defined_sound = EMS_normal_play_pre_defined_sound;
    EMS_stop_pre_defined_sound = EMS_normal_stop_pre_defined_sound;
    EMS_play_user_defined_melody = EMS_normal_play_user_defined_melody;
    EMS_stop_user_defined_melody = EMS_normal_stop_user_defined_melody;
}


/*****************************************************************************
 * FUNCTION
 *  EMS_disable_audio_playback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_disable_audio_playback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_play_pre_defined_sound = EMS_silent_play_pre_defined_sound;
    EMS_stop_pre_defined_sound = EMS_silent_stop_pre_defined_sound;
    EMS_play_user_defined_melody = EMS_silent_play_user_defined_melody;
    EMS_stop_user_defined_melody = EMS_silent_stop_user_defined_melody;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_measure_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  o           [?]     
 *  width       [?]     
 *  height      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_measure_object(EMSObject *o, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = 0;
    *height = 0;
    switch (o->Type)
    {
        case EMS_TYPE_PIC:
        {
            *width = o->data->picture.hDim;
            *height = o->data->picture.vDim;
        }
            break;
        case EMS_TYPE_USERDEF_ANM:
        {
            *width = o->data->animation.hDim;
            *height = o->data->animation.vDim;
        }
            break;
        case EMS_TYPE_PREDEF_ANM:
        {
            PU8 image = get_image(EMS_predefined_animations[o->PredefNo]);

            gui_measure_image(image, width, height);
        }
            break;
        case EMS_TYPE_PREDEF_SND:
        {
            gui_measure_image(EMS_editor_sound_icon, width, height);
        }
            break;
        case EMS_TYPE_USERDEF_SND:
        {
            gui_measure_image(EMS_editor_melody_icon, width, height);
        }
            break;
    }
}


void gui_EMS_input_box_display_object_pic(S32 x,S32 y,U8* src,S32 src_size,S32 w,S32 h,S32 bits_per_pixel)
{
    gdi_color palette[64]; // maximum is 64 colors
    switch(bits_per_pixel)
    {
    case 1:
        {
            palette[0] = gdi_act_color_from_rgb(255,255,255,255); // white
            palette[1] = gdi_act_color_from_rgb(255,0,0,0); // black
        }
        break;
    case 2:
        {
            palette[0] = gdi_act_color_from_rgb(255,0,0,0); // black
            palette[1] = gdi_act_color_from_rgb(255,85,85,85); // dark grey
            palette[2] = gdi_act_color_from_rgb(255,170,170,170); // light grey
            palette[3] = gdi_act_color_from_rgb(255,255,255,255); // white
        }
        break;
    case 6:
        {
            S32 R,G,B,index;
            const static S32 value[]={0,85,170,255};

            index = 0;
            for(R=0;R<4;R++)
                for(G=0;G<4;G++)
                    for(B=0;B<4;B++,index++)
                        palette[index] = gdi_act_color_from_rgb(255,value[R],value[G],value[B]);
        }
        break;
    default:
        MMI_ASSERT(0); // strange bits_per_pixel
        break;
    }
    gdi_bits_draw(
        x,y,
        src,
        src_size,
        w,h,
        bits_per_pixel,
        palette);

}


/*****************************************************************************
 * FUNCTION
 *  EMS_input_box_show_animation_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void EMS_input_box_show_animation_frame(void)
{
    S32 width,height;
    EMS_object_frame_counter++;
    if (EMS_object_frame_counter >= EMS_current_object->data->animation.cFrame)
        EMS_object_frame_counter = 0;

    width = EMS_current_object->data->animation.hDim;
    height = EMS_current_object->data->animation.vDim;
    
    gui_EMS_input_box_display_object_pic(
                        EMS_object_x,EMS_object_y,
                        (U8*) (EMS_current_object->data->animation.pdu 
                             + EMS_object_frame_counter * EMS_object_current_frame_size),
                        EMS_object_current_frame_size,
                        width,
                        height,
                        EMS_current_object->data->animation.bitsPerPixel);
    gui_BLT_double_buffer(EMS_object_x, EMS_object_y, EMS_object_x + width - 1, EMS_object_y + height - 1);
    if (EMS_current_object->data->animation.cFrame != 0)
    {
        if (EMS_object_frame_counter % EMS_current_object->data->animation.cFrame == 0)
            EMS_object_repeat_counter++;
    }
    if (EMS_current_object->data->animation.cRepeat != 0 
    && EMS_object_repeat_counter >= EMS_current_object->data->animation.cRepeat)
    {
        gui_cancel_timer(NULL);
    }
    else
    {
        gui_start_timer((EMS_current_object->data->animation.Duration + 1) * 100, EMS_input_box_show_animation_frame);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_input_box_show_predefined_animation_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_input_box_show_predefined_animation_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_object_frame_counter++;
    if (EMS_object_frame_counter >= EMS_object_n_frames)
    {
        EMS_object_frame_counter = 0;
    }
    gui_push_clip();
    gui_set_clip(0, MMI_title_y + MMI_title_height, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 2);
    gui_show_animated_image_frame(
        EMS_object_x,
        EMS_object_y,
        EMS_current_predefined_image,
        (S16) EMS_object_frame_counter);
    gui_pop_clip();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        EMS_object_x,
        EMS_object_y,
        EMS_object_x + EMS_object_width - 1,
        EMS_object_y + EMS_object_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    gui_start_timer(EMS_ANIMATION_TIME, EMS_input_box_show_predefined_animation_frame);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_display_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  o                   [?]         
 *  display_cursor      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_display_object(S32 x, S32 y, EMSObject *o, U8 display_cursor)
{
#if(EMS_ENABLE_EDITOR_OBJECT_PLAYBACK)
    U8 playback_flag = 1;
#else
    U8 playback_flag = 0;
    if (EMS_view_mode)
        playback_flag = 1;
#endif

    switch (o->Type)
    {
        case EMS_TYPE_PIC:
            gui_EMS_input_box_display_object_pic(
                        x,y,
                        (U8*)o->data->picture.pdu,
                        o->data->picture.pdu_length,
                        o->data->picture.hDim,o->data->picture.vDim,
                        o->data->picture.bitsPerPixel);
            break;

        case EMS_TYPE_USERDEF_ANM:
            if (display_cursor)
            {
                EMS_object_x = x;
                EMS_object_y = y;
                EMS_object_frame_counter = 0;
                EMS_object_repeat_counter = 0;
                EMS_current_object = o;
            }
            
            EMS_object_current_frame_size = o->data->animation.pdu_length;
            if (o->data->animation.cFrame != 0)
                EMS_object_current_frame_size /= o->data->animation.cFrame;

            gui_EMS_input_box_display_object_pic(
                    x,y,
                    (U8*) o->data->animation.pdu,
                    EMS_object_current_frame_size,
                    o->data->animation.hDim,o->data->animation.vDim,
                    o->data->animation.bitsPerPixel);
            
            if (display_cursor && playback_flag)
            {
                EMS_object_animation_timer_flag = 1;
                gui_start_timer((o->data->animation.Duration + 1) * 100, EMS_input_box_show_animation_frame);
            }
            break;
        case EMS_TYPE_PREDEF_ANM:
        {
            PU8 image = get_image(EMS_predefined_animations[o->PredefNo]);

            gui_show_animated_image_frame(x, y, image, 0);
            if (display_cursor && playback_flag)
            {
                EMS_object_x = x;
                EMS_object_y = y;
                gui_measure_image(image, &EMS_object_width, &EMS_object_height);
                EMS_object_n_frames = gui_image_n_frames(image);
                EMS_object_frame_counter = 0;
                EMS_current_object = o;
                EMS_current_predefined_image = image;
                EMS_object_predefined_animation_timer_flag = 1;
                gui_start_timer(EMS_ANIMATION_TIME, EMS_input_box_show_predefined_animation_frame);
            }
        }
            break;
        case EMS_TYPE_PREDEF_SND:
        {
            gui_show_transparent_image(x, y, EMS_editor_sound_icon, 0);
            if (display_cursor && playback_flag)
            {
                EMS_object_pre_defined_sound_flag = 1;
                EMS_play_pre_defined_sound(o->PredefNo);
            }
        }
            break;
        case EMS_TYPE_USERDEF_SND:
        {
            gui_show_transparent_image(x, y, EMS_editor_melody_icon, 0);
            if (display_cursor && playback_flag)
            {
                EMS_object_user_defined_melody_flag = 1;
                /* MTK Joy added for customization, 1014 */
            #if defined(__MMI_IMELODY_SUPPORT__)
                EMS_play_user_defined_melody(o->data->sound.pdu, o->data->sound.pdu_length);
            #endif 
                /* MTK end */
            }
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_playback_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  o       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_playback_object(EMSObject *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (o->Type)
    {
        case EMS_TYPE_PREDEF_SND:
        {
            EMS_object_pre_defined_sound_flag = 1;
            EMS_play_pre_defined_sound(o->PredefNo);
        }
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_TYPE_USERDEF_SND:
        {
            EMS_object_user_defined_melody_flag = 1;
            EMS_play_user_defined_melody(o->data->sound.pdu, o->data->sound.pdu_length);
        }
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EMS_cancel_object_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_cancel_object_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EMS_object_animation_timer_flag)
    {
        gui_cancel_timer(EMS_input_box_show_animation_frame);
        EMS_object_animation_timer_flag = 0;
    }
    else if (EMS_object_predefined_animation_timer_flag)
    {
        gui_cancel_timer(EMS_input_box_show_predefined_animation_frame);
        EMS_object_predefined_animation_timer_flag = 0;
    }
    else if (EMS_object_pre_defined_sound_flag)
    {
        EMS_stop_pre_defined_sound();
        EMS_object_pre_defined_sound_flag = 0;
    }
    else if (EMS_object_user_defined_melody_flag)
    {
        EMS_stop_user_defined_melody();
        EMS_object_user_defined_melody_flag = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_text_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  o       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_text_format(UI_EMS_input_box *b, EMSObject *o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 font_size = (U8) MEDIUM_FONT;
    U8 font_bold = 0;
    U8 font_italic = 0;
    U8 font_underline = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* color        c={0,0,0,100}; */

    /* UI_EMS_inputbox_text_color=c; */
    if (o == NULL)
    {
        EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
        EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
        b->flags &=
            ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
              UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
    }
    else
    {
        if (o->Type == EMS_TYPE_TEXT_FORMAT)
        {
            EMSTextFormat *t = &(o->data->text_format);

            b->flags &=
                ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
                  UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
            switch (t->Alignment)
            {
                case EMS_ALIGN_LEFT:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT;
                    break;
                case EMS_ALIGN_RIGHT:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT;
                    break;
                case EMS_ALIGN_CENTER:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER;
                    break;
                case EMS_ALIGN_LANG_DEP:
                    b->flags |= UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT;
                    break;
            }
            switch (t->FontSize)
            {
                case EMS_FONTSIZE_NORMAL:
                    font_size = (U8) UI_EMS_inputbox_medium_font.size;
                    /* c.r=0;c.g=0;c.b=0; */
                    break;
                case EMS_FONTSIZE_LARGE:
                    font_size = (U8) UI_EMS_inputbox_large_font.size;
                    /* c.r=255;c.g=0;c.b=0; */
                    break;
                case EMS_FONTSIZE_SMALL:
                    font_size = (U8) UI_EMS_inputbox_small_font.size;
                    /* c.r=0;c.g=0;c.b=255; */
                    break;
            }
        #ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
            if (t->isBold)
            {
                font_bold = 1;
            }
        #endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
            if (t->isItalic)
            {
                font_italic = 1;
            }
            if (t->isUnderline)
            {
                font_underline = 1;
            }
            UI_EMS_inputbox_current_font.bold = font_bold;
            UI_EMS_inputbox_current_font.italic = font_italic;
            UI_EMS_inputbox_current_font.underline = font_underline;
            UI_EMS_inputbox_current_font.size = font_size;
            EMS_SET_FONT(&UI_EMS_inputbox_current_font);
            /* UI_EMS_inputbox_text_color=c; */
            EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
        }
    }
}
#endif /* __MMI_MESSAGES_EMS__ */ 
#define UI_EMS_INPUTBOX_N_BREAK_CHARACTERS   2

UI_character_type EMS_input_box_break_characters[] = { ' ',
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

UI_character_type EMS_input_box_new_line_character = (UI_character_type) '\n';


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_breakable_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_breakable_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_EMS_INPUTBOX_N_BREAK_CHARACTERS; i++)
    {
        if ((UI_character_type) c == EMS_input_box_break_characters[i])
        {
            return (1);
        }
    }
    return (0);
}

#define UI_EMS_INPUT_BOX_BREAK_CHARACTER(c,flag)                                                      \
      {  S32 _ii_;                                                                                    \
         flag=0;                                                                                      \
         for(_ii_=0;_ii_<UI_EMS_INPUTBOX_N_BREAK_CHARACTERS;_ii_++)                                   \
         {  if((UI_character_type)c==(UI_character_type)EMS_input_box_break_characters[_ii_])         \
            {  flag=1;                                                                                \
               break;                                                                                 \
            }                                                                                         \
         }                                                                                            \
      }


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_new_line_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_new_line_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((UI_character_type) c == EMS_input_box_new_line_character)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

#if(EMS_USE_CRLF_COMBINATION)

static U8 gui_EMS_input_box_insert_new_line_no_sound(UI_EMS_input_box *b);
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret = EMS_OK;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_EMS_input_box_insert_new_line_no_sound(b);
    if (ret == EMS_NO_SPACE)
        UI_editor_play_tone_cannot_insert();

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line_no_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line_no_sound(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 ret = EMS_OK;

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    U8 s[4] = {0x00, 0x0D, 0x00, 0x0A};
#else 
    U8 s[4] = {0x0D, 0x00, 0x0A, 0x00};
#endif 
    S32 remaining_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->UCS2_count > 0)
    {
        remaining_length = (EMS_get_remaining_length(b->data) >> 1);
    }
    else
    {
        remaining_length = EMS_get_remaining_length(b->data);
    }
    if (remaining_length < 2)
    {
        ret = EMS_NO_SPACE;
        return ret;
    }
    /* Overwrite mode is un-implemented */
    if (AddString(b->data, s, 2, NULL) == EMS_NO_SPACE)
    {
        b->overflow_callback();
        ret = EMS_NO_SPACE;
    }
    else
    {
        b->change_callback();
    }
    b->text_format.Alignment = EMS_ALIGN_LANG_DEP; // reset alignment when input 'enter' symbol
    gui_EMS_input_box_locate_cursor(b);
    return ret;
}

#else /* (EMS_USE_CRLF_COMBINATION) */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_input_box_insert_new_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_EMS_input_box_insert_character(b, EMS_input_box_new_line_character);
    return EMS_OK;
}

#endif /* (EMS_USE_CRLF_COMBINATION) */ 

#define EMS_SET_BREAK_POSITION()                                     \
{  break_line_width=line_width;                                      \
   break_line_height=line_height;                                    \
   break_line_object_count=line_object_count;                        \
   break_line_alignment=line_alignment;                              \
   break_line_text_object_count=line_text_object_count;              \
}

#define EMS_SET_NEXT_BREAK_POSITION()                                \
{  break_line_width=line_width;                                      \
   break_line_height=line_height;                                    \
   break_line_object_count=line_object_count+1;                      \
   break_line_alignment=line_alignment;                              \
   break_line_text_object_count=line_text_object_count;              \
}


/*****************************************************************************
 * FUNCTION
 *  EMS_handle_CRLF_navigation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_handle_CRLF_navigation(EMSData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 r;
    EMSPosition p;
    UI_character_type c;
    EMSObject *o;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(EMS_USE_CRLF_COMBINATION)
    p = data->CurrentPosition;
    r = gui_EMS_input_box_get_next_object(data, &p, &c, &o);
    if ((r == 1) && UI_TEST_LF_CHARACTER(c))
    {
        p = data->CurrentPosition;
        r = gui_EMS_input_box_get_previous_object(data, &p, &c, &o);
        if ((r == 1) && UI_TEST_CR_CHARACTER(c))
        {
            BackwardCurrentPosition(data, 1);
            return;
        }
    }
#endif /* (EMS_USE_CRLF_COMBINATION) */ 
#if(EMS_USE_ESC_COMBINATION)
    if (data->dcs == SMSAL_DEFAULT_DCS)
    {
        p = data->CurrentPosition;
        r = gui_EMS_input_box_get_previous_object(data, &p, &c, &o);
        if ((r == 1) && UI_TEST_ESC_CHARACTER(c))
        {
            BackwardCurrentPosition(data, 1);
        }
    }
#endif /* (EMS_USE_ESC_COMBINATION) */ 
}

#define EMS_EDITOR_DRAW_DOTTED_LINE(x1,x2,y,c)                       \
{  S32 i,xx1=(x1),xx2=(x2),yy=(y);                                   \
   for(i=xx1;i<=xx2;i++)                                             \
   {  if(i&1) gui_putpixel(i,yy,c);                                  \
   }                                                                 \
}

#define EMS_EDITOR_DRAW_LINE(x1,x2,y,c)                              \
{  S32 i,xx1=(x1),xx2=(x2),yy=(y);                                   \
   for(i=xx1;i<=xx2;i++)                                             \
   {  gui_putpixel(i,yy,c);                                          \
   }                                                                 \
}

U8 EMS_object_width_cache[128];
U8 EMS_object_height_cache[128];

/* Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
extern S32 wgui_EMS_inputbox_information_bar_height;

#define MAX_EMS_DISP_CLUSTER_LEN 50
/* START TARUN PMT 20050128 */
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
extern BOOL cancelWidth;
#endif 
//END TARUN PMT 20050128
//W05.52 Fix Cursor Moviong issue for ESC character

#ifdef __MMI_INDIC_ALG__
    #define FONT_CANCEL_WIDTH(X)    cancelWidth = (X)
#else
    #define FONT_CANCEL_WIDTH(X)    
#endif
/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_back_cursor_for_ESC_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]     
 *  position        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_back_cursor_for_ESC_character(EMSData *data, EMSPosition *position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current_object;
    UI_character_type current_character;
    U8 object_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_type = gui_EMS_input_box_get_previous_object(data, position, &current_character, &current_object);   /* get next character */
    if (1 == object_type)
    {
        if (UI_TEST_ESC_CHARACTER(current_character))
        {
            if (BackwardCurrentPositionSkipCR(data) != 1)
            {
                UI_editor_play_tone_cannot_navigate();
            }
        }
    }
}

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
S32 gui_ems_mapping_org_to_sha(S32 position)
{
    if(position > unshaped_text_len)
        return (position - unshaped_text_len) + shaped_text_len;
    
    MMI_ASSERT(0<=position && position<=unshaped_text_len+1); // include NULL char
    return OrgToSha[position];
}
S32 gui_ems_mapping_sha_to_org(S32 position)
{
    int l,r,m;

    if(position > shaped_text_len)
        return (position - shaped_text_len) + unshaped_text_len;

    MMI_ASSERT(0<= position && position <= shaped_text_len+1);
    
    l = 0;
    r = unshaped_text_len; // include NULL char
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
#endif /* defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) */ 

/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_EMS_input_box(UI_EMS_input_box *b)
{
    if(b == NULL || b->data == NULL) return; // avoid invalid data source

    gui_show_EMS_input_box_ext(b, (-1), (-1));
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_EMS_input_box_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  move_to_x       [IN]        
 *  move_to_y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
static void gui_EMS_arabic_shaping(EMSData *data,U16 *length, U16 *text_buffer, U16 *pOrgToSha)
{
    S32 org_len;
    S32 sha_len;
	U16* string_end;
    U16* start;
    U16* end;
    U16* shaped_string;
    EMSObject	  *obj;
    S32 start_pos , end_pos; // unit : bytes

    
    obj = data->listHead;
    org_len = *length;
    sha_len = 0;
    shaped_string = text_buffer;

	string_end = (U16*)(((U8*)text_buffer) + org_len*2);

    for(start = text_buffer; start < string_end ; start = end)
    {
        start_pos = ((U8*)start - (U8*)text_buffer);

        // move obj to the right side of 'start'
        while( obj && obj->OffsetToText <= start_pos )
            obj = obj->next;

        if(obj == NULL)
            end_pos = org_len*2; // end position is at the end of string
        else
            end_pos = obj->OffsetToText;

        end = (U16*)(((U8*)text_buffer) + end_pos);

        // Do this string segment shaping
        {
            S32 i,j;
            S32 current_org_len = ((U8*)end - (U8*)start) / 2;
            U16 current_sha_len = current_org_len;

			for(i=start_pos/2,j=0;i < end_pos/2;i++,j++)
				pOrgToSha[i] = j;
            
            ArabicShapeEngine2_ext((U16*) & current_sha_len, (U16*) start, (U16*) &pOrgToSha[start_pos/2], NULL);

            // remapping the OrgToSha[]
            for(i=start_pos/2;i < end_pos/2;i++)
                pOrgToSha[i] += sha_len;

            // packing the shaping string
            for(i=0;i<current_sha_len;i++)
            {
                *shaped_string = start[i];
                shaped_string++;
            }
            sha_len += current_sha_len;
        }
    }
    *length = sha_len;
    *shaped_string = NULL;
}
#endif

void gui_show_EMS_input_box_ext(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1;                 /* x1,y1 -> left-top corner of the editor windows */
    S32 x2, y2;                 /* x2,y2 -> right-bottom of the editor windows */
    UI_filled_area f;           /* Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
    U8 selection_flag = 0;
    U8 overwrite_mode_flag = 0;
    S32 tx = 0, ty;             /* specify the positon at which the text display starts */
    EMSData *data = b->data;
    UI_character_type current_character = 0, pre2_character = 0, pre_character = 0;
    EMSPosition current_position;
    EMSPosition line_start_position;
    EMSPosition previous_position;
    U8 object_type = 0;
    EMSObject *current_object;
    S32 line_width, line_height = 0;
    S32 break_line_width, break_line_height;
    S32 object_width, object_height;
    U8 done = 0;
    U8 display_done;
    EMSObject *current_text_format;
    EMSObject *line_start_text_format;
    U32 flags = b->flags;
    S32 set_cursor_flag = 0;
    S32 center_x, box_width;
    S32 line_object_count = 0;
    S32 cursor_ax = 0, cursor_ay;   /* Absolute cursor co-ordinates  */
    S32 break_line_object_count;
    S32 text_format_object_count, break_text_format_object_count;
    U8 disable_draw_flag = 0;
    U8 *object_width_cache = EMS_object_width_cache;
    U8 *object_height_cache = EMS_object_height_cache;
    U8 word_highlight = 0;

    /* byte                                 has_ems_boundary_flag   =       0;  //Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
    S32 n_lines = 0;
    U8 first_object_flag;
    EMSPosition mapped_cursor_position;
    EMSPosition mapped_current_position;
    EMSPosition mapped_previous_position;
    U8 cursor_displayed_flag = 0;
    U8 alignment, break_line_alignment = EMS_ALIGN_LANG_DEP, line_alignment;
    S32 line_text_object_count, break_line_text_object_count;
    color normal_text_color = b->normal_text_color;
    color selected_text_color = b->selected_text_color;
/* PMT START URDU */
#if defined __MMI_LANG_HINDI__ && defined(__MMI_BIDI_ALG__)
/* PMT END URDU */
    U16 unicode = 0;
    U16 clFill = 0;
#endif /* defined __MMI_LANG_HINDI__ && defined(__MMI_BIDI_ALG__) */ 
#if(EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES)
    S32 minimum_line_height;
    S32 last_line_y = 0;
#endif /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
#if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
    U8 underline_flag = 0, strikethrough_flag = 0;
#endif /* (EMS_ENABLE_SPECIAL_FONT_DISPLAY) */ 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    PU8 move_ems_cursor_prev_p = data->textBuffer;
    PU8 move_ems_cursor_curr_p = data->textBuffer;
    PU8 temp_ems_cursor_p = data->textBuffer;
    PU8 move_ems_cursor_disp_prev_p = data->textBuffer;
    PU8 move_ems_cursor_disp_curr_p = data->textBuffer;
    U16 disp_ems_cluster[MAX_EMS_DISP_CLUSTER_LEN];
    S32 skip_ems_moves = 1;         /* for skipping by cluster */
    S32 saved_ems_skip_moves = 1;
    S32 display_ems_skip_moves = 1; /* for skipping by cluster while display */
    S32 saved_ems_display_skip_moves = 0;
    S32 ems_cluster_width = 0;
    S32 ems_cursor_width = 0;
    U8 kdx = 0;
    S32 hindi_ems_cluster_counter = 0;
/*PMT IRE START*/
    U8 text_format_object_count_dec_counter=0;
/*PMT IRE END*/
    /* Performance related to store the cluster width */
    S32 hindi_cluster_cache[50];
    S32 hindi_cache_counter = 0;

    /* MTK Begin Hindi patch 0425 */
    BOOL set_hindi_text_format_flag = MMI_FALSE;
    EMSObject *hindi_text_format = NULL;

    /* MTK End Hindi patch 0425 */
/*PMT IRE START*/
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
    PMT_BIDI_TYPES default_direction = BIDI_L;

#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U8 *temp_text_pt;
    U16 temp_text_position = 0;
    U8 temp_text_buffer[MAX_NUM_OF_CHAR_FOR_EACH_LINE];
    U16 temp_cursor_position = 0;
    U16 visual_str_len;
    U16 visual_cur_pos;
    U16 logical_hilight_start;
    U16 logical_hilight_end;
    U16 visual_hilight_start;
    U16 visual_hilight_end;
    U16 temp_hilight_start;
    U16 temp_hilight_end;
    S32 num_char;
    U32 iCount;
    pBOOL arabic_char_flag = MMI_FALSE;
    U8 lastest_char_type;
    UI_character_type test_current_character;
#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
    S32 text_len;
    PU8 backup_text = NULL;
#endif

#endif /* __MMI_BIDI_ALG__ */ 
#if defined(__MMI_LANG_VIETNAMESE__)
    UI_character_type dummy_c = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/* PMT START MAUI_00038534 */
    #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
    U8 vietnamese_indic_flag =0;
    #endif
/* PMT END MAUI_00038534 */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


/*PMT IRE START*/
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
/*PMT IRE END*/
    overwrite_current_language_for_hindi_rules_based_on_input_method();
#endif 
    if (((-1) != move_to_x) || ((-1) != move_to_y))
    {
        flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;

#ifdef __MMI_MESSAGES_EMS__
        EMS_cancel_object_focus();
#endif
    }

#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
    if ((b->data->textLength / ENCODING_LENGTH) != 0)
    {
        EMSObject *obj;
        U32 i;
        unshaped_text_len = text_len = (b->data->textLength / 2);
        backup_text = b->data->textBuffer;

        for (i=0; i<=text_len; i++)
        {
            OrgToSha[i] = i;
        }

        MMI_ASSERT(b->data->textLength <= MAX_TEXT_LENGTH * BIDI_ENCODING_LENGTH);
        memset(shaping_str, 0, b->data->textLength);

        mmi_ucs2ncpy(
                (S8*) shaping_str,
                (const S8*)b->data->textBuffer,
                b->data->textLength / ENCODING_LENGTH);
//        ArabicShapeEngine2_ext((U16*) & text_len, (U16*) shaping_str, (U16*) OrgToSha, NULL);
        gui_EMS_arabic_shaping(b->data,(U16*) &text_len, (U16*) shaping_str, (U16*) OrgToSha);
        shaped_text_len = text_len;
		OrgToSha[unshaped_text_len] = shaped_text_len;

        b->data->textBuffer = (U8*) shaping_str;
        b->data->CurrentPosition.OffsetToText = gui_ems_mapping_org_to_sha(b->data->CurrentPosition.OffsetToText/2)*2;
		b->data->textLength = text_len *2;
        
        for(obj = b->data->listHead; obj ; obj = obj->next)
        {
            obj->OffsetToText = gui_ems_mapping_org_to_sha(obj->OffsetToText/2)*2;
        }

        if (flags & UI_EMS_INPUT_BOX_WORD_HIGHLIGHT)
        {
            if (b->highlight_start_position.OffsetToText > b->data->textLength)
                b->highlight_start_position.OffsetToText = b->data->textLength;
            if (b->highlight_end_position.OffsetToText > b->data->textLength)
                b->highlight_end_position.OffsetToText = b->data->textLength;

            b->highlight_start_position.OffsetToText = gui_ems_mapping_org_to_sha(b->highlight_start_position.OffsetToText/2)*2;
            b->highlight_end_position.OffsetToText = gui_ems_mapping_org_to_sha(b->highlight_end_position.OffsetToText/2)*2;
        }

        #ifdef __MMI_INDIC_ALG__
            move_ems_cursor_prev_p = data->textBuffer;
            move_ems_cursor_curr_p = data->textBuffer;
            temp_ems_cursor_p = data->textBuffer;
            move_ems_cursor_disp_prev_p = data->textBuffer;
            move_ems_cursor_disp_curr_p = data->textBuffer;
        #endif /* __MMI_INDIC_ALG__ */ 
    }

#endif /*  __MMI_BIDI_ALG__*/ 



#ifdef __MMI_BIDI_ALG__
    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) && (data->textLength != 0))
    {

        for (iCount = 0; iCount < (U32) (data->textLength >> 1); iCount++)
        {
            bidi_get_char_type((U8*) (data->textBuffer + iCount * ENCODING_LENGTH), (U8*) & lastest_char_type);
            if ((lastest_char_type == AL) || (lastest_char_type == AN) || (lastest_char_type == BIDI_R))
            {
                arabic_char_flag = MMI_TRUE;
                break;
            }
        }


        bidi_get_char_type(data->textBuffer, (U8 *)&default_direction);
        #ifdef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR
        if (arabic_char_flag)
        #else
        if(default_direction == BIDI_R || default_direction == AL|| default_direction == AN)
        #endif
        {
            default_direction = BIDI_R;
        }
        else
        {
            default_direction = BIDI_L;
        }

    }
#endif /* __MMI_BIDI_ALG__ */ 

    if (r2lMMIFlag)
    {
        x1 = b->x + b->vbar.width + 1;
    }
    else
    {
        x1 = b->x;
    }
    y1 = b->y;
    x2 = b->x /* x1 */  + b->width - 1;
    y2 = y1 + b->height - 1;
    b->display_height = 0;
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    memset(disp_ems_cluster, 0, sizeof(disp_ems_cluster));
#endif 

    if (flags & UI_EMS_INPUT_BOX_DISABLE_DRAW)
    {
        disable_draw_flag = 1;
    }
    if (flags & UI_EMS_INPUT_BOX_VIEW_MODE)
    {
        EMS_view_mode = 1;
    }
    else
    {
        EMS_view_mode = 0;
    }
    if (!disable_draw_flag)
    {
        if (flags & UI_EMS_INPUT_BOX_STATE_SELECTED)
        {
            f = *b->selected_filler;
        }
        else if (flags & UI_EMS_INPUT_BOX_STATE_DISABLED)
        {
            f = *b->disabled_filler;
        }
        /* Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
        else
        {
            f = *b->normal_filler;
        }

        if (r2lMMIFlag)
        {
            gui_set_clip(b->x /* x1 - b->vbar.width */, y1, x2 + 2 /* +b->vbar.width */ , y2 + 2);
        }
        else
        {
            gui_set_clip(x1, y1, x2 + 2, y2 + 2);
        }
        /* Gurinder - 03/15/2004 - EMS Input Box InfoBar BG Image */
        if (!(flags & UI_EMS_INPUT_BOX_DISABLE_BACKGROUND)) /* if not disable background then do ... */
        {
            if (!(flags & UI_EMS_INPUT_BOX_INCLUDE_INFO_AREA))  /* not include info area */
            {
                /* 070405 Calvin Start */
                if (r2lMMIFlag)
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(
                            b->x /* x1 - b->vbar.width */,
                            y1,
                            x2 /* +b->vbar.width */ ,
                            y2,
                            GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(b->x /* x1 - b->vbar.width */, y1, x2 /* +b->vbar.width */ , y2, &f);
                    }
                }
                else
                {
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(x1, y1, x2, y2, &f);
                    }
                }
                /* 070405 Calvin End */

            }
            else    /* include info area */
            {
                if (r2lMMIFlag)
                {
                    gui_set_clip(
                        b->x /* x1 - b->vbar.width */,
                        y1 - wgui_EMS_inputbox_information_bar_height,
                        x2 /* +b->vbar.width */ ,
                        y2);
                }
                else
                {
                    gui_set_clip(x1, y1 - wgui_EMS_inputbox_information_bar_height, x2, y2);
                }

                f.flags = UI_FILLED_AREA_TYPE_BITMAP;
                f.b = get_image(WGUI_VOLUME_LEVEL1);
                if (r2lMMIFlag)
                {
                    /* 070405 Calvin Start */
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(
                            b->x /* x1 - b->vbar.width */,
                            y1 - wgui_EMS_inputbox_information_bar_height,
                            x2 /* + b->vbar.width */ ,
                            y2,
                            GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(
                            b->x /* x1 - b->vbar.width */,
                            y1 - wgui_EMS_inputbox_information_bar_height,
                            x2 /* + b->vbar.width */ ,
                            y2,
                            &f);
                    }
                    /* 070405 Calvin End */
                    gui_draw_rectangle(
                        b->x /* x1 - b->vbar.width */,
                        y1,
                        x2 /* + b->vbar.width */ ,
                        y2,
                        b->boundary_color);
                }
                else
                {
                    /* 070405 Calvin Start */
                    if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) &&
                        (flags & UI_EMS_INPUT_BOX_TRANSPARENT_BACKGROUND))
                    {
                        gdi_draw_solid_rect(
                            x1,
                            y1 - wgui_EMS_inputbox_information_bar_height,
                            x2,
                            y2,
                            GDI_COLOR_TRANSPARENT);
                    }
                    else
                    {
                        gui_draw_filled_area(x1, y1 - wgui_EMS_inputbox_information_bar_height, x2, y2, &f);
                    }
                    /* 070405 Calvin End */
                    gui_draw_rectangle(x1, y1, x2, y2, b->boundary_color);
                }

                if (flags & UI_MULTI_LINE_INPUT_BOX_USE_PRESET_CLIPPING)
                {
                    gui_set_clip_preset(x1, y1, x2 + 2, y2 + 2);
                }
                else
                {
                    gui_set_clip(x1, y1, x2 + 2, y2 + 2);
                }
            }
        }
    }
    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR)&& !r2lMMIFlag)
    {
        if (flags & UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
        {
            if ((b->vbar.scale < b->vbar.range))
                x2 -= b->vbar.width;
        }
        else
            x2 -= b->vbar.width;
    }

    box_width = (x2 - x1 - 2);
    center_x = x1 + (box_width >> 1) + 1;
    ty = y1 + 2 + b->display_y;
    if (flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
    {
        S32 h, ty1, ty2;

        h = b->measure_header();
        b->header_height = h;
        ty1 = ty - 2;
        ty2 = ty + h - 1;
        if (!disable_draw_flag && (ty2 > y1))
        {
            b->display_header(x1, ty1, x2, ty2);
        }
        ty += h;
		ty++; //hjf, for keep one pixel between header & first line text
    }
    else
    {
        b->header_height = 0;
    }
    if (!disable_draw_flag)
    {

        if (flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
        {
        #ifdef __MMI_BIDI_ALG__
            if (arabic_char_flag)
            {
                selection_flag = 0;
            }
            else
        #endif /* __MMI_BIDI_ALG__ */ 
                selection_flag = 1;
        }
        if ((flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE) && (!selection_flag))
        {
            overwrite_mode_flag = 1;
        }
        gui_set_clip(x1 + 1, y1 + 1, x2, y2 - 1);
        EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
        /* gui_set_text_clip(x1+2,y1+2,x2-2,y2-2); */
        EMS_SET_TEXT_COLOR(normal_text_color);
    }
    line_start_position.Object = NULL;
    line_start_position.OffsetToText = 0;
    current_text_format = NULL;
    cursor_ay = 0;
    text_format_object_count = 0;
    b->first_displayed_line = -1;
    b->last_displayed_line = -1;
    EMS_map_position(data, &data->CurrentPosition, &mapped_cursor_position);
    line_alignment = EMS_ALIGN_LANG_DEP;

#if defined(__MMI_LANG_VIETNAMESE__)
    /* W05.38 Fix Viet Tone Cursor Moving Issue */
    if ((flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) && (data->textLength != 0))
    {
        EMSPosition temp_cursor_position;

        //EMS_map_position(data, &data->CurrentPosition, &temp_cursor_position);
	temp_cursor_position = data->CurrentPosition;
        object_type = gui_EMS_input_box_get_next_object(data, &temp_cursor_position, &current_character, &current_object);
        if (1 == object_type)
        {
            if ((current_character >= 0x0300) && (current_character <= 0x0323))
            {
                EMS_map_position(data, &data->CurrentPosition, &temp_cursor_position);
                object_type = gui_EMS_input_box_get_previous_object(data, &temp_cursor_position, &dummy_c, &current_object);    /* get next character */
                if (1 == object_type)
                {
                    viet_vowel = mmi_viet_vowel_letter(dummy_c);
                    if (VIET_VOWEL_NONE != viet_vowel)
                    {
                        tone_mark = mmi_viet_tone_mark(current_character);
                        if (VIET_TONE_NONE != tone_mark)
                        {
                            current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                            gui_EMS_input_box_forward_cursor(b);
                        }
                    }
                }
            }
        }
    }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    while (!done)
    {   /* First Pass: Find the start and end of a line, line height and line width   */
        line_start_text_format = current_text_format;
    #ifdef __MMI_MESSAGES_EMS__
        gui_EMS_input_box_set_text_format(b, current_text_format);
    #else /* __MMI_MESSAGES_EMS__ */ 
        {
            EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
            EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
            b->flags &= ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT |
                          UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
        }
    #endif /* __MMI_MESSAGES_EMS__ */ 
        break_line_height = line_height = gui_get_character_height();
        current_position = line_start_position;
        break_text_format_object_count = text_format_object_count;
/*PMT IRE START*/
    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
        break_line_width = line_width = 1;
    #else 
        break_line_width = line_width = 0;
    #endif 
        break_line_object_count = line_object_count = 0;
        break_line_text_object_count = line_text_object_count = 0;
/*PMT IRE START*/    
    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
        hindi_cache_counter = 0;
        saved_ems_skip_moves = skip_ems_moves = 1;
        object_width = 0;
/*PMT IRE START*/
        move_ems_cursor_prev_p = (data->textBuffer + line_start_position.OffsetToText); 
    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
        first_object_flag = 1;
        while (!done)
        {
/* PMT START MAUI_00038534 */
            #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
            vietnamese_indic_flag =0;
            #endif
/* PMT END MAUI_00038534 */
            previous_position = current_position;
            if (TestLastPosition(data, &current_position))
            {
                current_character = 0;
                EMS_SET_BREAK_POSITION();
                /* MTK Terry for adjust the line width with italic style */
                if (UI_EMS_inputbox_current_font.italic && pre_character != 0)
                {
                    break_line_width += 3;
                }
                done = 1;
                break;
            }
/*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_EMS_input_box[skip_ems_moves]:%d  ", skip_ems_moves);
            while (skip_ems_moves--)
            {
/*PMT IRE START*/
        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE START*/ 
                object_type = gui_EMS_input_box_get_next_object(
                                data,
                                &current_position,
                                &current_character,
                                &current_object);
/*PMT IRE START*/
            #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                /* MTK Begin Hindi patch 0425 */
                if ((skip_ems_moves >= 1) && (object_type == 2) && (current_object->Type == EMS_TYPE_TEXT_FORMAT))
                {
                    object_type = gui_EMS_input_box_get_next_object(
                                    data,
                                    &current_position,
                                    &current_character,
                                    &current_object);
                }
                /* MTK End Hindi patch 0425 */

            }
            /* Not when object is images */
/*PMT IRE START*/
            if (IRE_INDIC_LANGUAGE_RANGE(current_character) && !(object_type == 2))
            {
                object_type = 1;
            }
            #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
            switch (object_type)
            {
                case 0:
                    done = 1;
                    break;
                case 1: /* character */
            #if(EMS_DISPLAY_SPECIAL_CHARACTERS)
                    if (UI_TEST_CR_CHARACTER(current_character) ||
                        UI_TEST_LF_CHARACTER(current_character) || UI_TEST_ESC_CHARACTER(current_character))
                    {
                        object_width = 10;
                        object_height = 10;
                    }
                    else
            #else /* (EMS_DISPLAY_SPECIAL_CHARACTERS) */ 
                #if(EMS_USE_CRLF_COMBINATION)
                    if (UI_TEST_CR_CHARACTER(current_character) &&
                        (current_position.OffsetToText < data->textLength) &&
                        UI_TEST_LF_CHARACTER(data->textBuffer[current_position.OffsetToText]))
                    {
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                        skip_ems_moves = 1;
                    #endif 
                        object_width = 0;
                        object_height = line_height;
                    }
                    else if (UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character))
                    {
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                        skip_ems_moves = 1;
                    #endif 
                        object_width = 0;
                        object_height = line_height;
                    }
                    else
                #endif /* (EMS_USE_CRLF_COMBINATION) */ 
                #if(EMS_USE_ESC_COMBINATION)
                    if (UI_TEST_ESC_CHARACTER(current_character))
                    {
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                        skip_ems_moves = 1;
/*PMT IRE START*/
                        move_ems_cursor_prev_p += 2;
/*PMT IRE END*/
                    #endif 
                        object_width = 0;
                        object_height = gui_get_character_height(); /* line_height */
                    }
                    else
                #endif /* (EMS_USE_ESC_COMBINATION) */ 
            #endif /* (EMS_DISPLAY_SPECIAL_CHARACTERS) */ 
                    if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
                    {
                        /* PMT FARHAD START 20050708 */
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
                        skip_ems_moves = 1;
                        move_ems_cursor_prev_p += 2;
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        /* PMT FARHAD END 20050708 */
                        object_width = 0;
                        object_height = line_height;
                    }
                    else
                    {
                    #if defined(__MMI_LANG_VIETNAMESE__)
                        if ((current_character > 0x0040) && (current_character < 0x01B1))
                        {
                            object_type = gui_EMS_input_box_get_next_object(data, &current_position, &dummy_c, &current_object);        /* get next character */
                            if (1 == object_type)
                            {
                                tone_mark = mmi_viet_tone_mark(dummy_c);
                                if (VIET_TONE_NONE != tone_mark)
                                {
                                    viet_vowel = mmi_viet_vowel_letter(current_character);
                                    if (VIET_VOWEL_NONE != viet_vowel)
                                    {
                                        current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
/* PMT START MAUI_00038534 */
                                        #if defined(__MMI_INDIC_ALG__)
                                        vietnamese_indic_flag =1; 
                                        #endif
                                        if (text_format_object_count)
                                        {
                                            text_format_object_count--;
                                        }
/* PMT END MAUI_00038534 */
                                    }
                                    else
                                    {
                                        object_type = gui_EMS_input_box_get_previous_object(
                                                        data,
                                                        &current_position,
                                                        &dummy_c,
                                                        &current_object);
                                    }
                                }
                                else
                                {
                                    object_type = gui_EMS_input_box_get_previous_object(
                                                    data,
                                                    &current_position,
                                                    &dummy_c,
                                                    &current_object);
                                }
                            }
                            else if (0 != object_type)
                            {
                                object_type = gui_EMS_input_box_get_previous_object(
                                                data,
                                                &current_position,
                                                &dummy_c,
                                                &current_object);
                            }
                        }
                    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

                    #ifdef __MMI_INDIC_ALG__

                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                        {
                            gui_measure_character(current_character, &object_width, &object_height);
                            if (object_height > line_height)
                            {
                                line_height = object_height;
                            }
                            object_height = gui_get_character_height();
                        }
                        else
                        {
                            gui_measure_character(current_character, &object_width, &object_height);
                        }
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_EMS_input_box[object_height]:%d  ",
                                             object_height);
/*PMT IRE START*/
                    #else /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
                        gui_measure_character(current_character, &object_width, &object_height);
/*PMT IRE START*/
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        if (!RequireToMoveCursor(pre_character, current_character))
                        {
                            object_width = 0;
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
                            skip_ems_moves = 1;
                            /* START TARUN PMT 20050128 */
                            move_ems_cursor_prev_p += 2;
                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        }
                        else
                        {
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/

                            /* Move pointer by the cluster width */
                            //For performance issue b->text is also assumed as current cluster pos
/*PMT IRE START*/  
/* PMT START MAUI_00027731 */                          
                            move_ems_cursor_curr_p = ire_get_next_cluster_p(move_ems_cursor_prev_p, gui_show_EMS_input_box_find_segment_end(b->data,move_ems_cursor_prev_p));
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
                            skip_ems_moves = move_ems_cursor_curr_p - move_ems_cursor_prev_p;   /* Number of moves */
                            skip_ems_moves = skip_ems_moves >> 1;
                            saved_ems_skip_moves = skip_ems_moves;      /* Save moves to skip the current_text_p also */

                            /* Calculate the width of current cluster as well as english character */
/*PMT IRE START*/
/*START PMTSW00007778 05222007*/
			   #if defined (__MMI_BIDI_ALG__)
/*PMT START MAUI_00027919*/
                           if((!IRE_INSERTED_ARABIC_COUNT()) || (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) && IRE_INSERTED_ARABIC_COUNT())) 
/*PMT END MAUI_00027919*/
                           {
                            object_width = ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);
						   }
                           #else
							object_width = ire_size_of_current_cluster(move_ems_cursor_prev_p, move_ems_cursor_curr_p, 0);	
                           #endif
/*END PMTSW00007778 05222007*/
/*PMT IRE END*/
                            
                            move_ems_cursor_prev_p = move_ems_cursor_curr_p;
/* PMT START MAUI_00038534 */
                            #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
                            if(vietnamese_indic_flag)
                            {
                                move_ems_cursor_prev_p+=2;
                                vietnamese_indic_flag =0; 

                            }
                            #endif
/* PMT END MAUI_00038534 */
					    #endif /* __MMI_INDIC_ALG__ */

                            if (UI_EMS_inputbox_current_font.italic || UI_EMS_inputbox_current_font.bold)
                            {
                                object_width += 1;
                            }
                            PRINT_INFORMATION_2(MMI_TRACE_INFO, "pixtel_UI_show_EMS_input_box[object_width]:%d  ",
                                                 object_width);
                            if (UI_TEST_CR_CHARACTER(current_character))
                            {
                                object_width = 0;
                            }
                            
                            /* Arabic Connectivity issue */    

                        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                        #ifdef __MMI_INDIC_ALG__
                            if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                        #endif
                            if (!IS_ARABIC_CHARACTER(current_character))
                        #endif /*__MMI_BIDI_ALG__*/ 
                                    object_width++;
                        }
                    }

                    /* MTK Terry for adjust the line width with italic style */
                    if ((line_width + object_width + 1) > box_width ||
                        (UI_EMS_inputbox_current_font.italic && (line_width + object_width + 3) > box_width))
                    {
                        line_width += object_width;
                    }
                    else
                    {
                        U8 bflag;

                        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
                        if (bflag)
                        {
                            EMS_SET_NEXT_BREAK_POSITION();
                        }
                        line_width += object_width;
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
/*PMT IRE END*/
                        {
                            hindi_ems_cluster_counter = line_object_count;
                            while (saved_ems_skip_moves--)
                            {
                                object_width_cache[hindi_ems_cluster_counter] = 0;
                                object_height_cache[hindi_ems_cluster_counter] = (U8) object_height;
                                hindi_ems_cluster_counter++;
                            }
                            hindi_cluster_cache[hindi_cache_counter] = object_width;
                        }
                        else
/*PMT IRE START*/
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        {
                            object_width_cache[line_object_count] = (U8) object_width;
                            /*
                             * #ifdef __MMI_BIDI_ALG__
                             * if(arabic_char_flag)
                             * object_height_cache[line_object_count]=(byte)gui_get_character_height()+2;
                             * else
                             * #endif
                             */
                            object_height_cache[line_object_count] = (U8) object_height;
                        }

                        if (object_height > line_height)
                        {
                            line_height = object_height;
                        }
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                        line_object_count += skip_ems_moves;
                        line_text_object_count += skip_ems_moves;
                        hindi_cache_counter++;
/*PMT IRE START*/
                    #else /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        line_object_count++;
                        line_text_object_count++;
/*PMT IRE START*/
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/

                        if (UI_STRING_LINE_BREAK_CHARACTER(current_character))
                        {
                            EMS_SET_BREAK_POSITION();
                            if (text_format_object_count <= 1)
                            {
                                line_alignment = EMS_ALIGN_LANG_DEP;
                            }
                        }
                        if (text_format_object_count)
                        {
/* START PMT MAUI_00026111 */
                        #ifndef __MMI_INDIC_ALG__
                            text_format_object_count--;
                        #else
                            if(text_format_object_count > skip_ems_moves)
                                text_format_object_count-= skip_ems_moves;
                            else
                                text_format_object_count = 0;
                        #endif
/* END PMT MAUI_00026111 */
                            if ((text_format_object_count == 0) && (current_position.OffsetToText < data->textLength))
                            {
                            #ifdef __MMI_MESSAGES_EMS__
                                gui_EMS_input_box_set_text_format(b, &UI_EMS_normal_text_format_object);
                            #else /* __MMI_MESSAGES_EMS__ */ 
                                {
                                    EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
                                    EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
                                    b->flags &= ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT |
                                                  UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
                                                  UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
                                }
                            #endif /* __MMI_MESSAGES_EMS__ */ 
                                object_height = gui_get_character_height();
                                if (object_height > line_height)
                                {
                                    line_height = object_height;
                                }
                                if (line_object_count == 0)
                                {
                                    line_height = object_height;
                                }
                            }
                        }
                        /* MTK Terry for FireFly#159 */
/*PMT IRE START*/
                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #else
                        if ((!UI_MULTI_LINE_INPUT_BOX_ALPHABETIC_CHARACTER(current_character)))
                    #endif
/*PMT IRE END*/
                        {
                            break_line_object_count = 0;
                        }
                    }
                    pre2_character = pre_character;
                    pre_character = current_character;
                    /* MTK end */
                    break;
                #ifdef __MMI_MESSAGES_EMS__
                case 2: /* object */
                    if (current_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        line_alignment = current_object->data->text_format.Alignment;
                        gui_EMS_input_box_set_text_format(b, current_object);
                        text_format_object_count = ((current_object->data->text_format.textLength) >> 1);
                        object_height = gui_get_character_height();
                        if (object_height > line_height)
                        {
                            line_height = object_height;
                        }
                        if (line_object_count == 0)
                        {
                            line_height = object_height;
                        }
                    }
                    else
                    {
                        gui_EMS_input_box_measure_object(current_object, &object_width, &object_height);
                        //it should not modify object width/height
						//object_width += 2;
                        //if (first_object_flag)
                        //{
                        //    object_width += 1;
                        //}
                        //else
                        //{
                            line_width += 3;
                        //}
                        //object_height += 1; /* 1 pixel gap between lines  */
                        /* MTK Elvis 20040322 to avoid the cursor overlap with scroll bar */
                        if ((line_width + object_width + 1) > box_width)
                            /* MTK end */
                        {
                            line_width += object_width;
                            /* Removed line breaking rule for objects */
                            /* EMS_SET_BREAK_POSITION(); */
                        }
                        else
                        {
                            if (object_height+1 > line_height)
                            {
                                line_height = object_height + 1;
                            }
                            line_width += object_width;
                            //if (first_object_flag)
                            //{
                            //   object_width -= 2;
                            //}
                            object_width_cache[line_object_count] = (S8) object_width;
                            object_height_cache[line_object_count] = (S8) object_height;
                            line_object_count++;
                            
                            pre_character = 0;
                            pre2_character = 0;
                            /* Removed line breaking rule for objects */
                            /* EMS_SET_BREAK_POSITION(); */
                        }
                    }
                    current_character = 0;
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                    skip_ems_moves = 1;
                #endif 
                    break;
                #else /* __MMI_MESSAGES_EMS__ */ 
                case 2: /* object */
                    current_character = 0;
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                    skip_ems_moves = 1;
                #endif 
                    break;
                #endif /* __MMI_MESSAGES_EMS__ */ 
            }
            first_object_flag = 0;
            /* MTK Elvis to avoid the cursor overlap with scroll bar */
            /* MTK Terry for adjust the line width with italic style only for character type */
            if((line_width + 1 > box_width) 
            || ((1 == object_type)
              &&(
                    (UI_EMS_inputbox_current_font.italic && (line_width + 3) > box_width)
                  || UI_STRING_LINE_BREAK_CHARACTER(current_character)
                  || UI_STRING_END_OF_STRING_CHARACTER(current_character)
                )
			   )
              )
                /* MTK end */
            {
                if ((break_line_object_count == 0) && (line_object_count > 0))
                {
                    EMS_SET_BREAK_POSITION();
                    break_line_width -= object_width;
                }
                /* MTK Terry for adjust the line width with italic style */
                if ((UI_EMS_inputbox_current_font.italic && (line_width + 3) > box_width) && pre_character != 0)
                {
                    break_line_width += 3;
                }
                break;
            }
        }

        /* Second pass: Display the line */
        pre2_character = 0;
        pre_character = 0;
/*PMT IRE START*/
    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
        ems_cluster_width = 0;
        ems_cursor_width = 0;
/*PMT IRE START*/
    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/

        line_width = break_line_width;
        line_height = break_line_height;
        current_text_format = line_start_text_format;
        current_position = line_start_position;
        alignment = break_line_alignment;
        if ((alignment != b->text_format.Alignment) &&
            //(break_line_text_object_count == 0) && 
			(line_object_count == 0) && 
			(b->current_line == n_lines) && 
			(EMS_view_mode == 0) )
        {
            alignment = b->text_format.Alignment;
        }
        /*       Old code: For testing                  */
        /*       else if((break_line_text_object_count!=0) && (data->textLength==0))
           alignment=b->text_format.Alignment;    */
        switch (alignment)
        {
            case EMS_ALIGN_LEFT:
                if (default_direction == BIDI_L)
                {
                    tx = x1 + 2;
                }
                else
                {
                    tx = x1 + line_width + 2;
                }
                break;
            case EMS_ALIGN_RIGHT:
                if (default_direction == BIDI_L)
                {
                    tx = x2 - line_width - 2;
                }
                else
                {
                    tx = x1 + box_width;
                }
                break;
            case EMS_ALIGN_CENTER:
                if (default_direction == BIDI_L)
                {
                    tx = center_x - (line_width >> 1);
                }
                else
                {
                    tx = center_x + (line_width >> 1);
                }
                break;
            case EMS_ALIGN_LANG_DEP:
                if (default_direction == BIDI_L)
                {
                    tx = x1 + 2;
                }
                else
                {
                    tx = x1 + box_width;
                }
                break;
            default:
                tx = x1 + 2;
                break;
        }
        if (tx < (x1 + 2))
        {
            tx = x1 + 2;
        }
        cursor_ax = tx - (x1 + 2);
        if ((b->first_displayed_line == -1) && (ty >= (y1 + 2)))
        {
            b->first_displayed_line = n_lines;
        }
        if ((ty + line_height) <= y2)
        {
            b->last_displayed_line = n_lines;
        }
        b->line_positions[n_lines] = line_start_position;
        b->line_object_counts[n_lines] = (U8) break_line_object_count;
        b->line_x_positions[n_lines] = (U8) cursor_ax;
        n_lines++;
    #ifdef __MMI_MESSAGES_EMS__
        gui_EMS_input_box_set_text_format(b, current_text_format);
    #else /* __MMI_MESSAGES_EMS__ */ 
        {
            EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
            EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
            b->flags &= ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT |
                          UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT | UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
        }
    #endif /* __MMI_MESSAGES_EMS__ */ 
        object_height = gui_get_character_height();
        text_format_object_count = break_text_format_object_count;
        display_done = 0;
        line_object_count = 0;
/*PMT IRE START*/
    #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
        hindi_cache_counter = 0;
    #endif 
        first_object_flag = 1;
    #if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
        if (current_text_format != NULL)
        {
            if (current_text_format->data->text_format.isUnderline == KAL_TRUE)
            {
                underline_flag = 1;
            }
            else
            {
                underline_flag = 0;
            }
            if (current_text_format->data->text_format.isStrikethrough == KAL_TRUE)
            {
                strikethrough_flag = 1;
            }
            else
            {
                strikethrough_flag = 0;
            }
        }
    #endif /* (EMS_ENABLE_SPECIAL_FONT_DISPLAY) */ 

    #ifdef __MMI_BIDI_ALG__
        if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
        {

            /* get last character unicode of previous line */
            if (n_lines == 1)
            {
                if (break_line_text_object_count < data->textLength / 2)
                {
                #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                    test_current_character = (data->textBuffer[current_position.OffsetToText +
                                                               ((1 + break_line_text_object_count) * ENCODING_LENGTH) -
                                                               1] | (data->textBuffer[current_position.OffsetToText +
                                                                                      ((1 +
                                                                                        break_line_text_object_count) *
                                                                                       ENCODING_LENGTH) - 2] << 8));
                #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                    test_current_character = (data->textBuffer[current_position.OffsetToText +
                                                               ((1 + break_line_text_object_count) * ENCODING_LENGTH) -
                                                               2] | (data->textBuffer[current_position.OffsetToText +
                                                                                      ((1 +
                                                                                        break_line_text_object_count) *
                                                                                       ENCODING_LENGTH) - 1] << 8));
                #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                }
                else
                {
                #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                    test_current_character = (data->textBuffer[current_position.OffsetToText +
                                                               ((break_line_text_object_count) * ENCODING_LENGTH) - 1] |
                                              (data->textBuffer[current_position.OffsetToText +
                                                                ((break_line_text_object_count) * ENCODING_LENGTH) -
                                                                2] << 8));
                #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                    test_current_character = (data->textBuffer[current_position.OffsetToText +
                                                               ((break_line_text_object_count) * ENCODING_LENGTH) - 2] |
                                              (data->textBuffer[current_position.OffsetToText +
                                                                ((break_line_text_object_count) * ENCODING_LENGTH) -
                                                                1] << 8));
                #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                }

            }
            else
            {
            #if(EMS_BYTE_ORDER_BIG_ENDIAN)
                test_current_character = (data->textBuffer[current_position.OffsetToText - 1] |
                                          (data->textBuffer[current_position.OffsetToText - 2] << 8));
            #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
                test_current_character = (data->textBuffer[current_position.OffsetToText - 2] |
                                          (data->textBuffer[current_position.OffsetToText - 1] << 8));
            #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
            }

            if (line_text_object_count > break_line_text_object_count)
            {
                num_char = break_line_text_object_count + 1;
            }
            else
            {
                num_char = break_line_text_object_count;    /* line_text_object_count; */
            }
            MMI_ASSERT(!(num_char > ((MAX_NUM_OF_CHAR_FOR_EACH_LINE >> 1) - 1)));

            if (((mapped_cursor_position.OffsetToText) / ENCODING_LENGTH) <
                ((current_position.OffsetToText) / ENCODING_LENGTH))
            {
                logical_cur_pos = 0xFFFF;
            }
            else if ((((mapped_cursor_position.OffsetToText) - (current_position.OffsetToText)) / ENCODING_LENGTH) >
                     (num_char))
            {
                logical_cur_pos = 0xFFFF;
            }
            else
            {
                logical_cur_pos =
                    ((mapped_cursor_position.OffsetToText) - (current_position.OffsetToText)) / ENCODING_LENGTH;
            }

            if ((n_lines > 1 && logical_cur_pos == 0))
            {
                /* mmi_ucs2_to_wc(&test_current_character, (data->textBuffer + current_position.OffsetToText - ENCODING_LENGTH)); */
                if (!UI_STRING_LINE_BREAK_CHARACTER(test_current_character))
                {
                    logical_cur_pos = 0xFFFF;
                }
            }

            logical_hilight_start = 0;
            logical_hilight_end = 0;

            bidi_main(
                data->textBuffer + current_position.OffsetToText,
                (U16) num_char,
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

            temp_text_position = current_position.OffsetToText;
            memcpy(
                temp_text_buffer,
                data->textBuffer + current_position.OffsetToText,
                visual_str_len * ENCODING_LENGTH);
            memcpy(data->textBuffer + current_position.OffsetToText, visual_str, visual_str_len * ENCODING_LENGTH);
            temp_cursor_position = mapped_cursor_position.OffsetToText;
            if (visual_cur_pos != 0xFFFF)
            {
                mapped_cursor_position.OffsetToText =
                    line_start_position.OffsetToText + (visual_cur_pos * ENCODING_LENGTH);
            }

        }
    #endif /* __MMI_BIDI_ALG__ */ /* endif of __MMI_BIDI_ALG__ */

        while (!display_done)
        {
/* PMT START MAUI_00038534 */
            #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
            vietnamese_indic_flag =0;
            #endif
/* PMT END MAUI_00038534 */
            previous_position = current_position;
            if (line_object_count >= break_line_object_count)
            {
                break;
            }
            if (flags & UI_EMS_INPUT_BOX_WORD_HIGHLIGHT)
            {
                if (current_position.OffsetToText == b->highlight_start_position.OffsetToText)
                {
                #ifdef __MMI_BIDI_ALG__
                    if (arabic_char_flag)
                    {
                        word_highlight = 0;
                    }
                    else
                #endif /* __MMI_BIDI_ALG__ */ 
                        word_highlight = 1;
                }
                if (current_position.OffsetToText == b->highlight_end_position.OffsetToText)
                {
                    word_highlight = 0;
                }
            }
            object_type = gui_EMS_input_box_get_next_object(
                            data,
                            &current_position,
                            &current_character,
                            &current_object);
            EMS_map_position(data, &previous_position, &mapped_previous_position);
            EMS_map_position(data, &current_position, &mapped_current_position);
            switch (object_type)
            {
                    int no_show_char;

                case 0:
                    current_character = 0;
                    display_done = 1;
                    break;
                case 1: /* character */
                    /* MTK Steven for speed up Editor by only display the characters in the display area */
                    no_show_char = 0;
                    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW))
                    {
                        if (((ty + line_height) < (y1 + 2)) || ((ty - line_height) > y2))
                        {
                            no_show_char = 1;
                        }
                    }
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                    /* MTK Begin Hindi patch 0425 */
                    if (set_hindi_text_format_flag == MMI_TRUE)
                    {
                        gui_EMS_input_box_set_text_format(b, hindi_text_format);
                        set_hindi_text_format_flag = MMI_FALSE;
                        current_text_format = hindi_text_format;
/*PMT IRE START*/
                        text_format_object_count = ((current_text_format->data->text_format.textLength) >> 1) - text_format_object_count_dec_counter;
/*PMT IRE END*/
                    }
                    /* MTK End Hindi patch 0425 */
/*PMT IRE START*/
                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 

                #if defined(__MMI_LANG_VIETNAMESE__)
                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        object_type = gui_EMS_input_box_get_next_object(data, &current_position, &dummy_c, &current_object);    /* get next character */
                        if (1 == object_type)
                        {
                            tone_mark = mmi_viet_tone_mark(dummy_c);
                            if (VIET_TONE_NONE != tone_mark)
                            {
                                viet_vowel = mmi_viet_vowel_letter(current_character);
                                if (VIET_VOWEL_NONE != viet_vowel)
                                {
                                    current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
/* PMT START MAUI_00038534 */
                                    #if defined(__MMI_INDIC_ALG__)
                                        vietnamese_indic_flag =1; 
                                    #endif
                                    if (text_format_object_count)
                                    {
                                        text_format_object_count--;

                                    }
/* PMT END MAUI_00038534 */
                                }
                                else
                                {
                                    object_type = gui_EMS_input_box_get_previous_object(
                                                    data,
                                                    &current_position,
                                                    &dummy_c,
                                                    &current_object);
                                }
                            }
                            else
                            {
                                object_type = gui_EMS_input_box_get_previous_object(
                                                data,
                                                &current_position,
                                                &dummy_c,
                                                &current_object);
                            }
                        }
                        else if(object_type!=0) //hjf, fix for end of string for vietname
                        {
                            object_type = gui_EMS_input_box_get_previous_object(
                                            data,
                                            &current_position,
                                            &dummy_c,
                                            &current_object);
                        }
                    }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

                #ifdef __MMI_BIDI_ALG__
                    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
                    {
                        gui_measure_character(current_character, &object_width, &object_height);
                        if (!RequireToMoveCursor(pre_character, current_character))
                        {
                            object_width = 0;
                        }
                        else
                        {
                            /* Arabic Connectivity issue */
                        #if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                            #if defined(__MMI_INDIC_ALG__)
                            if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                            #endif
                            if (!IS_ARABIC_CHARACTER(current_character))
                        #endif /* __MMI_BIDI_ALG__ */ 
                                    object_width++;
                        }
                    }
					else
                #endif /* __MMI_BIDI_ALG__ */ 
					{
                        object_width = object_width_cache[line_object_count];
                        object_height = object_height_cache[line_object_count];
					}
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))       /* space shud have been added in the Hindi range */
                    {
                        U8 hindi_text_format_length=0;
                        text_format_object_count_dec_counter=0;
/*PMT IRE END*/
                        if (!(TestLastPosition(data, &previous_position)))
                        {
                            //For performance issues first argument= second srgument
/*PMT IRE START*/
/* PMT START MAUI_00027731 */
                            move_ems_cursor_disp_curr_p = ire_get_next_cluster_p(move_ems_cursor_disp_prev_p, gui_show_EMS_input_box_find_segment_end(b->data,move_ems_cursor_disp_prev_p));
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
                            display_ems_skip_moves = move_ems_cursor_disp_curr_p - move_ems_cursor_disp_prev_p;
                            display_ems_skip_moves = display_ems_skip_moves >> 1;

                            /* ems_cluster_width=ems_cursor_width=hf_size_of_current_cluster(data->textBuffer,move_ems_cursor_disp_curr_p,0); */
                            ems_cluster_width = ems_cursor_width = hindi_cluster_cache[hindi_cache_counter];
/*PMT START MAUI_00027919*/
                             #if defined (__MMI_BIDI_ALG__)
                               if(IRE_INDIC_CHARACTER_UCS2_RANGE(current_character) && IRE_INSERTED_ARABIC_COUNT()) 
                               {
                                   object_width=ems_cluster_width;


                               }
                             #endif
/*PMT END MAUI_00027919*/
                            move_ems_cursor_disp_prev_p = move_ems_cursor_disp_curr_p;
                            saved_ems_display_skip_moves = display_ems_skip_moves;
                            display_ems_skip_moves--;
                            for (kdx = 0; kdx < display_ems_skip_moves; kdx++)
                            {
                                object_type = gui_EMS_input_box_get_next_object(
                                                data,
                                                &current_position,
                                                &current_character,
                                                &current_object);
/*PMT IRE START*/
                                if(object_type==1 && set_hindi_text_format_flag == MMI_TRUE )
                                {
                                    text_format_object_count_dec_counter++;
                                }                           
/*PMT IRE END*/                     
                                /* MTK Begin Hindi patch 0425 */
                                if (display_ems_skip_moves >= 1 && object_type == 2 &&
                                    current_object->Type == EMS_TYPE_TEXT_FORMAT)
                                {
                                    hindi_text_format = current_object;
                                    set_hindi_text_format_flag = MMI_TRUE;
/*PMT IRE START*/
                                    hindi_text_format_length=((current_object->data->text_format.textLength)>>1);
/*PMT IRE END*/
                                    object_type = gui_EMS_input_box_get_next_object(
                                                    data,
                                                    &current_position,
                                                    &current_character,
                                                    &current_object);
/*PMT IRE START*/
                                    text_format_object_count_dec_counter=1;            
/*PMT IRE END*/         
                                }
                                /* MTK End Hindi patch 0425 */
/*PMT IRE START*/
                                if(set_hindi_text_format_flag == MMI_TRUE && text_format_object_count_dec_counter >=hindi_text_format_length)
                                {
                                    /*reseting the flags and counter*/
                                    hindi_text_format=NULL;
                                    set_hindi_text_format_flag = MMI_FALSE;
                                    hindi_text_format_length=0;
                                    text_format_object_count_dec_counter=0;
                                }
/*PMT IRE END*/
                            }
                        }
                    }
                    else
                    {
                        move_ems_cursor_disp_prev_p += 2;
                        saved_ems_display_skip_moves = 1;
/* PMT START MAUI_00038534 */
                        #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
                        if(vietnamese_indic_flag)
                        {
                                move_ems_cursor_disp_prev_p +=2;
                               

                        }
                        #endif
/* PMT END MAUI_00038534 */
                    }
/*PMT IRE START*/
                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
                    if (!disable_draw_flag)
                    {
                        EMS_SET_TEXT_COLOR(normal_text_color);
                        if (default_direction == BIDI_R)
                        {
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
                            if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
/*PMT IRE END*/                 
                            {
                                tx -= ems_cluster_width;
                                cursor_ax -= ems_cursor_width;
                            }
                            else
/*PMT IRE START*/
                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                            {
                                tx -= object_width;
                                cursor_ax -= object_width;
                            }
                        }
                        /* MTK end */
                        if (word_highlight ||
                            (overwrite_mode_flag &&
                             !cursor_displayed_flag &&
                             (mapped_previous_position.OffsetToText == mapped_cursor_position.OffsetToText)) ||
                            (selection_flag &&
                             (mapped_current_position.OffsetToText == mapped_cursor_position.OffsetToText)))
                        {
                            S32 rx1, ry1, rx2, ry2;

                            rx1 = tx;
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
                            if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
/*PMT IRE END*/
                            {
                                S32 h, w;

                                gui_measure_character(current_character, &w, &h);
                                ry1 = ty;
                                rx2 = rx1 + ems_cluster_width - 1;
                                ry2 = ry1 + h - 1;
                                PRINT_INFORMATION_2(MMI_TRACE_INFO,
                                                     "pixtel_UI_show_EMS_input_box[ems_cluster_width]:%d  ",
                                                     ems_cluster_width);
                            }
                            else
/*PMT IRE START*/
                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                            {
                                ry1 = line_height - object_height + ty;
                                rx2 = rx1 + object_width - 1;
                                ry2 = ry1 + object_height - 1;
                            }
                            EMS_SET_TEXT_COLOR(selected_text_color);
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
                        #if defined(__MMI_ZI_HINDI__) || defined(__MMI_T9_HINDI__) 
/*PMT IRE END*/
                            if (MMI_current_input_mode == INPUT_MODE_SMART_HINDI)
                            {
/*PMT IRE START*/
                                if (!IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
/*PMT IRE END*/
                                {
                                    gui_fill_rectangle(rx1, ry1, rx2 + 2, ry2, b->selection_color);
                                }
                                else
                                {
                                    gui_fill_rectangle(rx1 + 2, ry1, rx2 + 2, ry2, b->selection_color);
                                }
                            }
                            else
/*PMT IRE START*/
                        #endif /* __MMI_INDIC_ALG__ */ 
                        #endif
                                gui_fill_rectangle(rx1, ry1, rx2, ry2, b->selection_color);
                        }
                    #ifdef __MMI_INDIC_ALG__
                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                        {
                            EMS_MOVE_TEXT_CURSOR(tx, ty);
                        }
                        else
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                            EMS_MOVE_TEXT_CURSOR(tx, line_height - object_height + ty);
                    #if(EMS_DISPLAY_SPECIAL_CHARACTERS)
                        if (UI_TEST_CR_CHARACTER(current_character))
                        {
                            gdi_image_draw_id(tx,
                                line_height - object_height + ty,
                                WGUI_CR_CHARACTER_IMAGE_ID);
                        }
                        else if (UI_TEST_LF_CHARACTER(current_character))
                        {
                            gdi_image_draw_id(tx,
                                line_height - object_height + ty,
                                WGUI_LF_CHARACTER_IMAGE_ID);
                        }
                        else if (UI_TEST_ESC_CHARACTER(current_character))
                        {
                            gdi_image_draw_id(tx,
                                line_height - object_height + ty,
                                WGUI_ESC_CHARACTER_IMAGE_ID);
                        }
                        else
                    #endif /* (EMS_DISPLAY_SPECIAL_CHARACTERS) */ 
                        {
                            /* MTK Terry for Skip Special Character Issue */
                            if (!(
                        #if(EMS_USE_ESC_COMBINATION)
                                     UI_TEST_ESC_CHARACTER(current_character) ||
                        #endif 
                        #if(EMS_PREVENT_CRLF_DISPLAY)
                                     UI_TEST_LF_CHARACTER(current_character) || UI_TEST_CR_CHARACTER(current_character)
                                     ||
                        #endif /* (EMS_PREVENT_CRLF_DISPLAY) */ 
                                     UI_STRING_END_OF_STRING_CHARACTER(current_character)))
                            {

                                /* gui_print_character(current_character); */
/*PMT IRE START*/
                            #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                                PU8 prev_temp_ems_cursor_p;

                                if (TestLastPosition(data, &previous_position))
                                {
                                    goto end_ems_disp;
                                }

                                //Performance issues 
/*PMT IRE START*/
                                prev_temp_ems_cursor_p = temp_ems_cursor_p;
/* PMT START MAUI_00027731 */
                                temp_ems_cursor_p = ire_get_next_cluster_p(temp_ems_cursor_p, gui_show_EMS_input_box_find_segment_end(b->data,temp_ems_cursor_p));
/* PMT START MAUI_00038534 */
                                #if defined(__MMI_LANG_VIETNAMESE__) && defined(__MMI_INDIC_ALG__)
                                if(vietnamese_indic_flag)
                                {
                                    temp_ems_cursor_p +=2;
                                    vietnamese_indic_flag =0; 

                                }
                                #endif

                                if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                {
                                    S32 disp_len =0;
                                    ire_get_current_cluster(prev_temp_ems_cursor_p, temp_ems_cursor_p, disp_ems_cluster);
                                    disp_len = mmi_ucs2strlen((PS8) disp_ems_cluster);
/* PMT END MAUI_00038534 */
                                    MMI_ASSERT(!(disp_len > MAX_EMS_DISP_CLUSTER_LEN));
                                    /* To avoid rule appln in showstring */
/*PMT IRE START*/
                                    ire_disable_indic_rules_parsing();
                                    ire_indic_padding_value(0);
                                    if (!IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
/*PMT IRE END*/
                                    {
                                        if (no_show_char != 1)
                                        {
                                            FONT_CANCEL_WIDTH(1);
                                            if (underline_flag)
                                            {
                                                UI_font->underline = 0;
                                            }
                                            ShowString(
                                                UI_text_x,
                                                UI_text_y,
                                                *UI_font,
                                                0,
                                                (U8*) (disp_ems_cluster),
                                                 object_height);
                                            if (underline_flag)
                                            {
                                                UI_font->underline = 1;
                                            }
/*PMT IRE START*/
                                           if(current_text_format) 
                                           {
                                               if (current_text_format->data->text_format.isStrikethrough == KAL_TRUE)
                                               {
                                                   strikethrough_flag = 1;
                                               }
                                               else
                                               {
                                                   strikethrough_flag = 0;
                                               }
                                           }
/*PMT IRE END*/
                                            FONT_CANCEL_WIDTH(0);
                                        }
                                    }
                                    else
                                    {
                                        if (no_show_char != 1)
                                        {
                                            FONT_CANCEL_WIDTH(1);
                                            if (underline_flag)
                                            {
                                                UI_font->underline = 0;
                                            }
/* START PMT PATCH04052007 */
/*PMT IRE START*/
                                            ShowString(
                                                UI_text_x,
                                                UI_text_y,
                                                *UI_font,
                                                0,
                                                (U8*) (disp_ems_cluster),
                                                0);
/*PMT IRE END*/
/* END PMT PATCH04052007 */
                                            if (underline_flag)
                                            {
                                                UI_font->underline = 1;
                                            }
/*PMT IRE START*/
                                            if(current_text_format) 
                                            {
                                                if (current_text_format->data->text_format.isStrikethrough == KAL_TRUE)
                                                {
                                                    strikethrough_flag = 1;
                                                }
                                                else
                                                {
                                                    strikethrough_flag = 0;
                                                }
                                            }
/*PMT IRE END*/
                                            FONT_CANCEL_WIDTH(0);
                                        }
                                    }
/*PMT IRE START*/
                                    //Open it again
                                    ire_enable_indic_rules_parsing();
                                    ire_indic_padding_def_value();
#if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
                                    //draw underline
                                    if (underline_flag)
                                    {
                                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                        {
                                            S32 h, w;
                                            
                                            gui_measure_character(current_character, &w, &h);
                                            UI_draw_horizontal_line(
                                                tx,
                                                tx + ems_cluster_width - 1,
                                                ty + h ,
                                                b->underline_color);
                                        }
                                        else
                                            UI_draw_horizontal_line(
                                            tx,
                                            tx + object_width - 1,
                                            ty + line_height,
                                            b->underline_color);
                                    }
#endif
                                }
                                else
/*PMT IRE START*/
                            #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                {
                                    if (no_show_char != 1)
                                    {
										FONT_CANCEL_WIDTH(1);
                                        gui_print_stacked_character(current_character, pre2_character, pre_character);
										FONT_CANCEL_WIDTH(0);
                                    }
                                }
                            #if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
                                if (strikethrough_flag)
                                {
/*PMT IRE START*/
                                #ifdef __MMI_INDIC_ALG__
                                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                                    {
                                        S32 h, w;
                                        gui_measure_character(current_character, &w, &h);
                                        UI_draw_horizontal_line(
                                            tx,
                                            tx + ems_cluster_width - 1,
                                            ty + (h >> 1),
                                            b->strikethrough_color);
                                    }
                                    else
                                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                    {

                                        UI_draw_horizontal_line(
                                            tx,
                                            tx + object_width - 1,
                                            ty + line_height - (object_height >> 1),
                                            b->strikethrough_color);
                                    }
                                }
/*PMT IRE START*/
                            #ifdef __MMI_INDIC_ALG__
                              end_ems_disp:
                                memset(disp_ems_cluster, 0, sizeof(disp_ems_cluster));
                            #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                            #endif /* (EMS_ENABLE_SPECIAL_FONT_DISPLAY) */ /* end of #if(EMS_ENABLE_SPECIAL_FONT_DISPLAY) */
                            }
/*PMT IRE START*/
                        #ifdef __MMI_INDIC_ALG__
                            else
                            {
                                temp_ems_cursor_p += 2;
                            }
                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        }
                    }
                    if (!(((-1) != move_to_x) || ((-1) != move_to_y)))
                    {
                        if ((!cursor_displayed_flag) &&
                            (mapped_previous_position.OffsetToText == mapped_cursor_position.OffsetToText))
                        {
                            b->cursor_ax = cursor_ax;
                            b->cursor_ay = cursor_ay;
                            b->cursor_line_height = line_height;
                            b->cursor_line_position = line_object_count;
                            b->current_line = n_lines - 1;
                            if (!disable_draw_flag && !(flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
                            {
                                if (default_direction != BIDI_L)
                                {
/*PMT IRE START*/
                                #ifdef __MMI_INDIC_ALG__
                                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
/*PMT IRE END*/
                                    {
                                        S32 h, w;
                                        gui_measure_character(pre_character, &w, &h);
                                        tx -= ems_cluster_width;
                                        tx += ems_cursor_width;
                                        gui_show_EMS_input_box_cursor(b, tx + 1 + ems_cluster_width, ty, 0, h, 1);
                                    }
/* START PMT PATCH04052007 */
                                #if defined (__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
                                    else if(!IRE_INSERTED_ARABIC_COUNT())
                                #else
                                    else
                                #endif /*__MMI_BIDI_ALG__*/
/* END PMT PATCH04052007 */
                                    {
                                        gui_show_EMS_input_box_cursor(
                                            b,
                                            tx + 1 + ems_cluster_width,
                                            line_height - object_height + ty,
                                            0,
                                            object_height,
                                            1);
                                    }
/* START PMT PATCH04052007 */
                                #if defined (__MMI_BIDI_ALG__)
                                    else
                                    {
                                        
                                    gui_show_EMS_input_box_cursor(
                                        b,
                                        tx + object_width,
                                        line_height - object_height + ty,
                                        0,
                                        object_height,
                                        1);

                                    }
                                #endif /*__MMI_BIDI_ALG__*/
/* END PMT PATCH04052007 */
/*PMT IRE START*/
                                #else /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                    gui_show_EMS_input_box_cursor(
                                        b,
                                        tx + object_width,
                                        line_height - object_height + ty,
                                        0,
                                        object_height,
                                        1);
/*PMT IRE START*/
                                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                }
                                else
                                {
/*PMT IRE START*/
                                #ifdef __MMI_INDIC_ALG__
                                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
/*PMT IRE END*/
                                    {
                                        S32 h, w;
                                        gui_measure_character(pre_character, &w, &h);
                                        tx -= ems_cluster_width;
                                        tx += ems_cursor_width;
                                        gui_show_EMS_input_box_cursor(b, tx + 1, ty, 0, h, 1);
                                    }
                                    else
                                    {
                                        gui_show_EMS_input_box_cursor(
                                            b,
                                            tx + 1,
                                            line_height - object_height + ty,
                                            0,
                                            object_height,
                                            1);
                                    }
/*PMT IRE START*/
                                #else /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                    gui_show_EMS_input_box_cursor(
                                        b,
                                        tx,
                                        line_height - object_height + ty,
                                        0,
                                        object_height,
                                        1);
/*PMT IRE START*/
                                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                }
                            }
                            cursor_displayed_flag = 1;
                        }
                    }
                    else if ((((-1) != move_to_x) || ((-1) != move_to_y)))
                    {
                        PMT_BIDI_TYPES temp_direction = BIDI_L;

                        #ifdef __MMI_BIDI_ALG__
                        bidi_get_char_type(b->data->textBuffer, (U8 *)&temp_direction);
                        #endif
                        
                        if (((temp_direction == BIDI_L)? ((tx + b->x + object_width) > move_to_x) : ((tx + b->x + object_width) > box_width - move_to_x))
                            &&((cursor_ay + line_height + b->y + b->display_y + b->header_height) > move_to_y)
                            &&(!set_cursor_flag))
                        {
                            b->cursor_ax = cursor_ax;
                            b->cursor_ay = cursor_ay;
                            b->cursor_line_height = line_height;
                            b->cursor_line_position = line_object_count;
                            b->current_line = n_lines - 1;
                            /* EMS_map_position(data,&previous_position,&(data->CurrentPosition)); */
                            MoveCursorToPosition(data, &previous_position);
                            set_cursor_flag = 1;
                        #if(EMS_USE_ESC_COMBINATION)
                            /* W05.52 Fix Cursor Moviong issue for ESC character */
                            gui_EMS_input_box_back_cursor_for_ESC_character(data, &previous_position);
                        #endif /* (EMS_USE_ESC_COMBINATION) */ 
                        }
                        else if (((cursor_ay + line_height + b->y + b->display_y + b->header_height) > move_to_y) &&
                                 (n_lines < (b->n_lines)) && (!set_cursor_flag) &&
                                 (((line_object_count + 1) >= break_line_object_count) ||
                                  (UI_TEST_CR_CHARACTER(current_character))))
                        {
                            b->cursor_ax = cursor_ax;
                            b->cursor_ay = cursor_ay;
                            b->cursor_line_height = line_height;
                            b->cursor_line_position = line_object_count;
                            b->current_line = n_lines - 1;
                            /* EMS_map_position(data,&previous_position,&(data->CurrentPosition)); */
                            MoveCursorToPosition(data, &previous_position);
                            set_cursor_flag = 1;
                        #if(EMS_USE_ESC_COMBINATION)
                            /* W05.52 Fix Cursor Moviong issue for ESC character */
                            gui_EMS_input_box_back_cursor_for_ESC_character(data, &previous_position);
                        #endif /* (EMS_USE_ESC_COMBINATION) */ 
                        }
                    }
                    if (default_direction == BIDI_L)
                    {
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
/*PMT IRE END*/
                        {
                            tx += ems_cluster_width;
                            cursor_ax += ems_cursor_width;
                        }
                        else
/*PMT IRE START*/
                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        {
                            tx += object_width;
                            cursor_ax += object_width;
                        }
                    }
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
                    line_object_count += saved_ems_display_skip_moves;
                    hindi_cache_counter++;
/*PMT IRE START*/
                #else /* __MMI_INDIC_ALG__ */ 
                    line_object_count++;
                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/

                    if (text_format_object_count)
                    {
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
                     /*In case text format object count exceed the saved count then    */
                     /*decrement it by saved count else make the text format count zero*/
                     /*This does not let the text format count go less than zero       */
                     if(text_format_object_count>saved_ems_display_skip_moves)
                     {
                         text_format_object_count-=saved_ems_display_skip_moves;
                     }
                     else
                     {
                         text_format_object_count=0;
                     }
#else 
                        text_format_object_count--;
#endif /* __MMI_INDIC_ALG__ */
/*PMT IRE END*/
                        if ((text_format_object_count == 0) && (current_position.OffsetToText <= data->textLength))
                        {
                        #ifdef __MMI_MESSAGES_EMS__
                            gui_EMS_input_box_set_text_format(b, &UI_EMS_normal_text_format_object);
                        #else /* __MMI_MESSAGES_EMS__ */ 
                            {
                                EMS_SET_FONT(&UI_EMS_inputbox_medium_font);
                                EMS_SET_TEXT_COLOR(UI_EMS_inputbox_text_color);
                                b->flags &= ~(UI_EMS_INPUT_BOX_CURRENT_ALIGN_LEFT |
                                              UI_EMS_INPUT_BOX_CURRENT_ALIGN_RIGHT |
                                              UI_EMS_INPUT_BOX_CURRENT_ALIGN_CENTER);
                            }
                        #endif /* __MMI_MESSAGES_EMS__ */ 
                            object_height = gui_get_character_height();
                            if (line_object_count == 0)
                            {
                                line_height = object_height;
                            }
                            current_text_format = &UI_EMS_normal_text_format_object;
                        #if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
                            if (current_text_format != NULL)
                            {
                                if (current_text_format->data->text_format.isUnderline == KAL_TRUE)
                                {
                                    underline_flag = 1;
                                }
                                else
                                {
                                    underline_flag = 0;
                                }
                                if (current_text_format->data->text_format.isStrikethrough == KAL_TRUE)
                                {
                                    strikethrough_flag = 1;
                                }
                                else
                                {
                                    strikethrough_flag = 0;
                                }
                            }
                        #endif /* (EMS_ENABLE_SPECIAL_FONT_DISPLAY) */ 
                        }
                    }
                    pre2_character = pre_character;
                    pre_character = current_character;
                    break;
                #ifdef __MMI_MESSAGES_EMS__
                case 2: /* object */
                    /* MTK Terry for speed up Editor by only display the characters in the display area */
                    if (((ty + line_height) < (y1 + 2)) && ((ty - line_height) > y2))
                    {
                        break;
                    }
                    if (current_object->Type == EMS_TYPE_TEXT_FORMAT)
                    {
                        gui_EMS_input_box_set_text_format(b, current_object);
                        object_height = gui_get_character_height();
                        current_text_format = current_object;
/*PMT IRE START*/
                    #ifdef __MMI_INDIC_ALG__
                        hindi_text_format = current_object;
                    #endif /*__MMI_INDIC_ALG__*/
/*PMT IRE END*/
                    #if(EMS_ENABLE_SPECIAL_FONT_DISPLAY)
                        if (current_text_format != NULL)
                        {
                            if (current_text_format->data->text_format.isUnderline == KAL_TRUE)
                            {
                                underline_flag = 1;
                            }
                            else
                            {
                                underline_flag = 0;
                            }
                            if (current_text_format->data->text_format.isStrikethrough == KAL_TRUE)
                            {
                                strikethrough_flag = 1;
                            }
                            else
                            {
                                strikethrough_flag = 0;
                            }
                        }
                    #endif /* (EMS_ENABLE_SPECIAL_FONT_DISPLAY) */ 
                        text_format_object_count = ((current_object->data->text_format.textLength) >> 1);
                        if (line_object_count == 0)
                        {
                            switch (current_text_format->data->text_format.Alignment)
                            {
                                case EMS_ALIGN_LEFT:
                                    if (default_direction == BIDI_L)
                                    {
                                        tx = x1 + 2;
                                    }
                                    else
                                    {
                                        tx = x1 + line_width + 2;
                                    }
                                    break;
                                case EMS_ALIGN_RIGHT:
                                    if (default_direction == BIDI_L)
                                    {
                                        tx = x2 - line_width - 2;
                                    }
                                    else
                                    {
                                        tx = x1 + box_width;
                                    }
                                    break;
                                case EMS_ALIGN_CENTER:
                                    if (default_direction == BIDI_L)
                                    {
                                        tx = center_x - (line_width >> 1);
                                    }
                                    else
                                    {
                                        tx = center_x + (line_width >> 1);
                                    }
                                    break;
                                case EMS_ALIGN_LANG_DEP:
                                    if (default_direction == BIDI_L)
                                    {
                                        tx = x1 + 2;
                                    }
                                    else
                                    {
                                        tx = x1 + box_width;
                                    }
                                    break;
                            }
                        }
                    }
                    else
                    {
                        pre2_character = 0;
                        pre_character = 0;

                        object_width = object_width_cache[line_object_count];
                        object_height = object_height_cache[line_object_count];
                        //if (first_object_flag)
                        //{
                        //   if (default_direction == BIDI_L)
                        //    {
                        //        object_width += 1;
                        //        tx += 1;
                        //    }
                        //    else
                        //    {
                        //        object_width += 1;
                        //        tx -= 1;
                        //    }
                        //}
                        //else
                        //{
                            if(default_direction == BIDI_L)
                            {
                                tx              +=      3;
                            }                          
							else
							{
								tx -= 3;
								tx -= object_width;
								cursor_ax -= 3;
								cursor_ax -= object_width;
							}
                        /* MTK end */
                        if (!(((-1) != move_to_x) || ((-1) != move_to_y)))
                        {
                            if ((mapped_cursor_position.Object != NULL) &&
                                (mapped_previous_position.Object != NULL) &&
                                (mapped_previous_position.OffsetToText == mapped_cursor_position.OffsetToText) &&
                                (mapped_previous_position.Object == mapped_cursor_position.Object))
                            {
                                b->cursor_ax = cursor_ax;
                                b->cursor_ay = cursor_ay;
                                b->cursor_line_height = line_height;
                                b->cursor_line_position = line_object_count;
                                b->current_line = n_lines - 1;
                                if (!disable_draw_flag)
                                {
                                    gui_EMS_input_box_display_object(
                                        tx,
                                        line_height - (object_height+1) + ty,
                                        current_object,
                                        1);
									if (!cursor_displayed_flag)
                                    if (!(flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
                                    {
                                        /* MTK Terry for EMS Multitap Highlight Issue */
                                        if (overwrite_mode_flag ||
                                            selection_flag && !(flags & UI_EMS_INPUT_BOX_STATE_MULTITAP))
                                        {
                                            S32 rx1, ry1, rx2, ry2;

                                            rx1 = tx;
                                            ry1 = line_height - object_height + ty;
                                            rx2 = rx1 + object_width - 1;
                                            ry2 = ry1 + object_height - 1;
                                            gui_cross_hatch_fill_rectangle(rx1, ry1, rx2, ry2, b->selection_color);
                                        }

                                        if (default_direction != BIDI_L)
                                        {
/*PMT IRE START*/
                                        #ifdef __MMI_INDIC_ALG__
                                            if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
/*PMT IRE END*/
                                            {
                                                S32 h, w;
                                                gui_measure_character(pre_character, &w, &h);
                                                gui_show_EMS_input_box_cursor(
                                                    b,
                                                    tx + object_width,
                                                    ty,
                                                    object_width,
                                                    h,
                                                    2);
                                            }
                                            else
/*PMT IRE START*/
                                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                            {
                                                gui_show_EMS_input_box_cursor(
                                                    b,
                                                    tx + object_width,
                                                    line_height - object_height + ty,
                                                    object_width,
                                                    object_height,
                                                    2);
                                            }
                                        }
                                        else
                                        {
/*PMT IRE START*/
                                        #ifdef __MMI_INDIC_ALG__
                                            if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
/*PMT IRE END*/
                                            {
                                                S32 h, w;

                                                gui_measure_character(pre_character, &w, &h);
                                                gui_show_EMS_input_box_cursor(b, tx, ty, object_width, h, 2);
                                            }
                                            else
/*PMT IRE START*/
                                        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                            {
                                                gui_show_EMS_input_box_cursor(
                                                    b,
                                                    tx,
                                                    line_height - object_height + ty,
                                                    object_width,
                                                    object_height,
                                                    2);
                                            }
                                        }

                                    }
                                    else if (EMS_view_mode)
                                    {
/*PMT IRE START*/
                                    #ifdef __MMI_INDIC_ALG__
                                        if (IRE_INDIC_CHARACTER_UCS2_RANGE(pre_character))
                                        {
                                             gui_show_EMS_input_box_cursor(
                                                b,
                                                tx,
                                                line_height - object_height + ty,
                                                object_width,
                                                object_height,
                                                3);
                                        }
                                        else
                                    #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                                        {
                                            gui_show_EMS_input_box_cursor(
                                                b,
                                                tx,
                                                line_height - (object_height + 1) + ty,
                                                object_width,
                                                object_height,
                                                3);
                                        }
                                    }
                                }
                                cursor_displayed_flag = 1;
                            }
                            else if (!disable_draw_flag)
                            {
                                gui_EMS_input_box_display_object(
                                    tx,
                                    line_height - object_height + ty,
                                    current_object,
                                    0);
                            }
                        }
                        else if ((((-1) != move_to_x) || ((-1) != move_to_y)))
                        {
                            if (((tx + b->x + object_width) > move_to_x) &&
                                ((cursor_ay + line_height + b->y + b->display_y + b->header_height) > move_to_y) &&
                                (!set_cursor_flag))
                            {
                                b->cursor_ax = cursor_ax;
                                b->cursor_ay = cursor_ay;
                                b->cursor_line_height = line_height;
                                b->cursor_line_position = line_object_count;
                                b->current_line = n_lines - 1;
                                /* EMS_map_position(data,&previous_position,&(data->CurrentPosition)); */
                                MoveCursorToPosition(data, &previous_position);
                                set_cursor_flag = 1;
                            }
                        }

                        if (default_direction == BIDI_L)
                        {
                            tx += object_width;
                            cursor_ax += object_width;
                        }
                        line_object_count++;
                    }
                    current_character = 0;
                    break;
                #endif /* __MMI_MESSAGES_EMS__ */ 
            }
            first_object_flag = 0;
        }

    #ifdef __MMI_BIDI_ALG__
        if (!(flags & UI_EMS_INPUT_BOX_DISABLE_DRAW) && arabic_char_flag)
        {
            memcpy(data->textBuffer + temp_text_position, temp_text_buffer, visual_str_len * ENCODING_LENGTH);
            mapped_cursor_position.OffsetToText = temp_cursor_position;

        }
    #endif /* __MMI_BIDI_ALG__ */ 

        line_start_position = current_position;
        if ((current_character == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
    #if(EMS_SHOW_HORIZONTAL_RULE_FOR_NEWLINE)
            || (UI_TEST_LF_CHARACTER(current_character) && (flags & UI_EMS_INPUT_BOX_NEWLINE_DRAW))
    #endif 
            )
        {
            if (!disable_draw_flag)
            {
                EMS_EDITOR_DRAW_DOTTED_LINE(x1 + 2, x2 - 1, ty + line_height + 2, b->paragraph_color);
            }
            ty += 4;    /*  4=height of line break horizontal rule display  */
            cursor_ay += 4;
            b->display_height += 4;
        }
        /* START PMT NEERAJ 20050916 */
    #if(EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES)
        else
        {
            if (flags & UI_EMS_INPUT_BOX_ALL_LINE_DRAW)
            {
                if (!disable_draw_flag)
                {
                    UI_draw_horizontal_line(x1 + 2, x2 - 1, ty + line_height + 2, gui_color(112, 125, 240));
                    last_line_y = ty + line_height + 2;
                    line_height += 4;
                }
                else
                {
                    line_height += 4;
                }
            }
        }
    #endif /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
        /* END PMT NEERAJ 20050916 */
        line_height += 1;   /*  +1 added for 1 pixel gap between lines */
        ty += line_height;
        cursor_ay += line_height;
        b->display_height += line_height;
    }
    b->n_lines = n_lines;
    /* START PMT NEERAJ 20050916 */
#if(EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES)
    if (flags & UI_EMS_INPUT_BOX_ALL_LINE_DRAW)
    {      
        minimum_line_height = Get_CharHeightOfAllLang(MEDIUM_FONT);/* object_height; */
        if (!disable_draw_flag)
        {
            while (last_line_y <= y2)
            {
                last_line_y += minimum_line_height + 5;
                UI_draw_horizontal_line(x1 + 2, x2 - 1, last_line_y, gui_color(112, 125, 240));
            }
/*            if (EMS_view_mode)
            {
            #if defined(__MMI_MAINLCD_240X320__)
                    if (last_line_y - y2 <= minimum_line_height - 13 && b->display_y != 0)
            #elif defined(__MMI_MAINLCD_128X128__)
                if (last_line_y - y2 <= minimum_line_height - 12 && b->display_y != 0)
            #else 
                if (last_line_y - y2 <= minimum_line_height - 11 && b->display_y != 0)
            #endif 
                {
                    b->display_y -= 3;
                }
            }*/
        }
    }
#endif /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
    /* END PMT NEERAJ 20050916 */
    /* W06.12 cursor_displayed_flag is only used when not moving cusrsor by pen */
    if (!cursor_displayed_flag && ((move_to_x == (-1)) && (move_to_y == (-1))))
    {
        cursor_ay -= (line_height);
        b->cursor_ax = cursor_ax;
        b->cursor_ay = cursor_ay;
        b->cursor_line_height = line_height - 1;
        b->cursor_line_position = line_object_count;
        b->current_line = n_lines - 1;
        if (!disable_draw_flag && !(flags & UI_EMS_INPUT_BOX_DISABLE_CURSOR_DRAW))
        {
            /* START PMT NEERAJ 20050916 */
        #if(EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES)
/*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
            if (flags & UI_EMS_INPUT_BOX_ALL_LINE_DRAW)
            {
/* PMT START FOR_7.17INDIC */
				#if defined(__MMI_BIDI_ALG__) 
				if(IRE_INSERTED_ARABIC_COUNT())
				{
					gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 5, 1);
				}
				else
                #endif /*__MMI_BIDI_ALG__*/
/* PMT END FOR_7.17INDIC */
                gui_show_EMS_input_box_cursor(b, tx + 1, ty - line_height, 0, line_height - 5, 1);
            }
            else
            {
/* PMT START FOR_7.17INDIC */
				#if defined(__MMI_BIDI_ALG__) 
				if(IRE_INSERTED_ARABIC_COUNT())
				{
				gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 1, 1);
				}
				else
                #endif /*__MMI_BIDI_ALG__*/
/* PMT END FOR_7.17INDIC */
                gui_show_EMS_input_box_cursor(b, tx + 1, ty - line_height, 0, line_height - 1, 1);
            }
/*PMT IRE START*/
        #else /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
            if (flags & UI_EMS_INPUT_BOX_ALL_LINE_DRAW)
            {
                gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 5, 1);
            }
            else
            {
                gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 1, 1);
            }
/*PMT IRE START*/
        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
        #else /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
            /* END PMT NEERAJ 20050916 */
/*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
/* PMT START FOR_7.17INDIC */
	    #if defined(__MMI_BIDI_ALG__) 
				if(IRE_INSERTED_ARABIC_COUNT())
				{
					gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 1, 1);
				}
				else
            #endif /*__MMI_BIDI_ALG__*/
/* PMT END FOR_7.17INDIC */
            gui_show_EMS_input_box_cursor(b, tx + 1, ty - line_height, 0, line_height - 1, 1);
        #else /* __MMI_INDIC_ALG__ */ 
            gui_show_EMS_input_box_cursor(b, tx, ty - line_height, 0, line_height - 1, 1);
        #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
            /* START PMT NEERAJ 20050916 */
        #endif /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
            /* END PMT NEERAJ 20050916 */
        }
        cursor_ay += line_height;
    }
    if ((((-1) != move_to_x) || ((-1) != move_to_y)) && (!set_cursor_flag))
    {
        cursor_ay -= (line_height);
        b->cursor_ax = cursor_ax;
        b->cursor_ay = cursor_ay;
        b->cursor_line_height = line_height - 1;
        b->cursor_line_position = line_object_count;
        b->current_line = n_lines - 1;
        /* EMS_map_position(data,&current_position,&(data->CurrentPosition)); */
        MoveCursorToPosition(data, &current_position);
        //W05.34 Fix warning tone in stylus on the blank area
        //gui_EMS_input_box_next(b);
        cursor_ay += line_height;
    }
#if(EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES)
    /* W06.16 If EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES, the height of the last line is different */
    if ((flags & UI_EMS_INPUT_BOX_ALL_LINE_DRAW) && (b->current_line == (b->n_lines - 1)))
    {
        b->cursor_line_height = line_height;
    }
#endif /* (EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES) */ 
    if (b->saved_cursor_ax == -1)
    {
        b->saved_cursor_ax = b->cursor_ax;
    }
    /* W06.16 Set text format after changing cursor position by pen */
    if ((!EMS_view_mode) && (((-1) != move_to_x) || ((-1) != move_to_y)))
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
    }
    if (!disable_draw_flag && !(flags & UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR))
    {
        if (flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER)
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, b->height - 2);
            gui_set_vertical_scrollbar_range(&b->vbar, cursor_ay + b->header_height + 2);
            gui_set_vertical_scrollbar_value(&b->vbar, -b->display_y);
        }
        else
        {
            gui_set_vertical_scrollbar_scale(&b->vbar, b->height - 2);
            /* W06.12 Use b->display_height + 2 instead of cursor_ay 
               1.cursor_ay is different when the cusrosr at the last line
               2.(+2)because that the box_height is b->height - 4 in gui_EMS_input_box_locate_cursor */
            gui_set_vertical_scrollbar_range(&b->vbar, b->display_height + 2);
            /* gui_set_vertical_scrollbar_range(    &b->vbar,       cursor_ay               ); */
            gui_set_vertical_scrollbar_value(&b->vbar, -b->display_y);
        }
        if (flags & UI_EMS_INPUT_BOX_AUTO_DISABLE_SCROLLBAR)
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

    /* Handle next line, previous line navigation   */
    if (disable_draw_flag)
    {
        if (flags & UI_EMS_INPUT_BOX_PREVIOUS_LINE)
        {
            if (EMS_view_mode)
            {
                S32 fdl = b->first_displayed_line;
                EMSPosition new_position;

                if (data->listHead == NULL)
                {
                    b->current_line = fdl;
                    if (b->current_line > 0)
                    {
                        b->current_line--;
                    }
                    else
                    {
                        b->cursor_ay = 0;
                    }
                    new_position = b->line_positions[b->current_line];
                    MoveCursorToPosition(data, &new_position);
                }
                else
                {
                    if ((data->CurrentPosition.OffsetToText > 0) || (data->CurrentPosition.Object != NULL))
                    {
                        EMSPosition new_position;
                        U8 flag;
                        U8 done = 0;

                        while (!done)
                        {
                            flag = 0;
                            if (b->current_line > 0)
                            {
                                flag = 1;
                                b->current_line--;
                            }
                            else
                            {
                                b->cursor_ay = 0;
                            }

                            new_position = b->line_positions[b->current_line];
                            if (BackwardCurrentPositionObject(data, &new_position))
                            {
                                if (flag)
                                {
                                    b->current_line++;
                                }
                            }
                            else
                            {
                                break;
                            }
                            if (b->current_line > 0)
                            {
                                b->current_line--;
                            }
                            else
                            {
                                break;
                            }
                            if (b->current_line <= (fdl - 1))
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                if (b->current_line > 0)
                {
                    EMSPosition new_position;
                    S32 object_count = b->cursor_line_position;
                    S32 new_position_object_count;

                    b->current_line--;
                    new_position = b->line_positions[b->current_line];
                    new_position_object_count = b->line_object_counts[b->current_line] - 1;
                    if (object_count > new_position_object_count)
                    {
                        object_count = new_position_object_count;
                    }
                    MoveCursorToPosition(data, &new_position);
                #if(EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT)
                    EMS_move_graphical_cursor(
                        data,
                        b->line_x_positions[b->current_line],
                        b->saved_cursor_ax,
                        new_position_object_count);
                #else /* (EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT) */ 
                    ForwardCurrentPosition(data, (U16) object_count);
                #endif /* (EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT) */ 
                }
                else
                {
                    if (flags & UI_EMS_INPUT_BOX_DISABLE_TONE)
                    {
                        b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_TONE;
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_navigate();
                    }
                }
            }
            /* MTK Terry for scroll down problem for extension character in EMS_view_mode temp solution */
            if (!EMS_view_mode)
            {
                EMS_handle_CRLF_navigation(data);
            }
            /* if(!TestFirstPosition(data,&data->CurrentPosition)) */
            gui_EMS_input_box_set_text_format_cursor_position(b);
        }
        else if (flags & UI_EMS_INPUT_BOX_PREVIOUS_OBJECT)
        {
            if (EMS_view_mode && (data->listHead != NULL))
            {
                if ((data->CurrentPosition.OffsetToText > 0) || (data->CurrentPosition.Object != NULL))
                {
                    EMSPosition new_position;

                    new_position = b->line_positions[b->current_line];
                    BackwardCurrentPositionSeekObject(data, &new_position);
                }
            }
        }
        if (flags & UI_EMS_INPUT_BOX_NEXT_LINE)
        {
            if (EMS_view_mode)
            {
                S32 ldl = b->last_displayed_line;
                EMSPosition new_position;

                if (data->listHead == NULL)
                {
                    b->current_line = ldl;
                    if (b->current_line < (b->n_lines - 1))
                    {
                        b->current_line++;
                    }
                    new_position = b->line_positions[b->current_line];
                    MoveCursorToPosition(data, &new_position);
                }
                else
                {
                    if (!TestLastPosition(data, &data->CurrentPosition))
                    {
                        EMSPosition new_position, old_position;
                        U8 flag;
                        U8 done = 0;

                        while (!done)
                        {
                            flag = 0;
                            if (b->current_line < (b->n_lines - 1))
                            {
                                flag = 1;
                                b->current_line++;
                            }
                            new_position = b->line_positions[b->current_line];
                            if (ForwardCurrentPositionObject(data, &new_position))
                            {
                                if (flag)
                                {
                                    b->current_line--;
                                }
                            }
                            else
                            {
                                break;
                            }
                            flag = 0;
                            if (b->current_line < (b->n_lines - 1))
                            {
                                new_position = b->line_positions[b->current_line + 1];
                            }
                            else
                            {
                                new_position.OffsetToText = data->textLength;
                                new_position.Object = data->listTail;
                                flag = 1;
                            }
                            old_position = data->CurrentPosition;
                            if (ForwardCurrentPositionObject(data, &new_position))
                            {
                                if (!flag)
                                {
                                    MoveCursorToPosition(data, &old_position);
                                }
                            }
                            else
                            {
                                break;
                            }
                            if (b->current_line < (b->n_lines - 1))
                            {
                                b->current_line++;
                            }
                            else
                            {
                                break;
                            }
                            if (b->current_line >= (ldl + 1))
                            {
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                if (b->current_line < (b->n_lines - 1))
                {
                    EMSPosition new_position;
                    S32 object_count = b->cursor_line_position;
                    S32 new_position_object_count;

                    b->current_line++;
                    new_position = b->line_positions[b->current_line];
                    new_position_object_count = b->line_object_counts[b->current_line];
                    if (b->current_line != (b->n_lines - 1))
                    {
                        new_position_object_count -= 1;
                    }
                    if (object_count > new_position_object_count)
                    {
                        object_count = new_position_object_count;
                    }
                    MoveCursorToPosition(data, &new_position);
                #if(EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT)
                    EMS_move_graphical_cursor(
                        data,
                        b->line_x_positions[b->current_line],
                        b->saved_cursor_ax,
                        new_position_object_count);
                #else /* (EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT) */ 
                    ForwardCurrentPosition(data, (U16) object_count);
                #endif /* (EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT) */ 
                }
                else
                {
                    if (flags & UI_EMS_INPUT_BOX_DISABLE_TONE)
                    {
                        b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_TONE;
                    }
                    else
                    {
                        UI_editor_play_tone_cannot_navigate();
                    }
                }
            }
            /* MTK Terry for scroll down problem for extension character in EMS_view_mode temp solution */
            if (!EMS_view_mode)
            {
                EMS_handle_CRLF_navigation(data);
            }
            /* if(!TestLastPosition(data,&data->CurrentPosition)) */
            gui_EMS_input_box_set_text_format_cursor_position(b);
        }
        else if (flags & UI_EMS_INPUT_BOX_NEXT_OBJECT)
        {
            if (EMS_view_mode && (data->listHead != NULL))
            {
                if (!TestLastPosition(data, &data->CurrentPosition))
                {
                    EMSPosition new_position;

                    if (b->current_line >= (b->n_lines - 1))
                    {
                        new_position.OffsetToText = data->textLength;
                        new_position.Object = data->listTail;
                    }
                    else
                    {
                        new_position = b->line_positions[b->current_line + 1];
                    }
                    ForwardCurrentPositionSeekObject(data, &new_position);
                }
            }
        }
    }

#ifdef __MMI_BIDI_ALG__
    UI_UNUSED_PARAMETER(temp_hilight_start);
    UI_UNUSED_PARAMETER(temp_hilight_end);
    UI_UNUSED_PARAMETER(temp_text_pt);
#endif /* __MMI_BIDI_ALG__ */ 


#if defined(__MMI_BIDI_ALG__) && defined(__MMI_ARSHAPING_ENGINE__)
    if ((b->data->textLength / ENCODING_LENGTH) != 0)
    {
        EMSObject *obj;
        b->data->textBuffer = backup_text;
		b->data->textLength = unshaped_text_len * 2;
        b->data->CurrentPosition.OffsetToText = gui_ems_mapping_sha_to_org(b->data->CurrentPosition.OffsetToText/2)*2;

        if (flags & UI_EMS_INPUT_BOX_WORD_HIGHLIGHT)
        {
            b->highlight_start_position.OffsetToText = gui_ems_mapping_sha_to_org(b->highlight_start_position.OffsetToText/2)*2;
            b->highlight_end_position.OffsetToText = gui_ems_mapping_sha_to_org(b->highlight_end_position.OffsetToText/2)*2;
        }

        for(obj = b->data->listHead; obj ; obj = obj->next)
            obj->OffsetToText = gui_ems_mapping_sha_to_org(obj->OffsetToText/2)*2;

    }
#endif /* __MMI_LANG_ARABIC__ */ 
/*PMT IRE START*/   
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
/*PMT IRE END*/
    restore_current_language_for_hindi_rules();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_toggle_insert_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_toggle_insert_mode(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_OVERWRITE_MODE;
    }
    else
    {
        b->flags |= UI_EMS_INPUT_BOX_OVERWRITE_MODE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_backspace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_backspace_no_draw(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paragraph_text_align_flag = 0;
    U8 previous_paragraph_text_alignment = EMS_ALIGN_LANG_DEP;
    EMSPosition current_position;
    UI_character_type c;
    EMSObject *o;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if ((b->data != NULL) && (b->data->listHead != NULL))
    {
        current_position = b->data->CurrentPosition;
        if (gui_EMS_input_box_test_paragraph_start(b, &current_position))
        {
            gui_EMS_input_box_get_previous_object(b->data, &current_position, &c, &o);
            previous_paragraph_text_alignment = gui_EMS_input_box_get_previous_text_alignment(b, &current_position);
            paragraph_text_align_flag = 1;
        }
    }
    if (gui_EMS_cancel_current_position(b) == 0)
    {
        UI_editor_play_tone_cannot_change();
    }
    else
    {
        gui_EMS_input_box_set_text_format_cursor_position(b);
        if (paragraph_text_align_flag)
        {
            current_position = b->data->CurrentPosition;
            gui_EMS_input_box_set_paragraph_text_alignment(b, &current_position, previous_paragraph_text_alignment);
        }
    }
#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif

}

void gui_EMS_input_box_backspace(UI_EMS_input_box *b)
{
    gui_EMS_input_box_backspace_no_draw(b);
    if (b->locate_cursor_flag)
        gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}

/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_previous_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_previous_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hflag = 0;
    EMSPosition current_position = b->data->CurrentPosition;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if(b->cursor_ay == 0 && b->display_y <0)
    {
        b->display_y +=20;
        if(b->display_y >0) b->display_y = 0;
        return;
    }
    b->flags |= (UI_EMS_INPUT_BOX_PREVIOUS_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_PREVIOUS_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    if (b->cursor_ay == 0)
    {
        hflag = 1;
    }
    /* if(!TestFirstPosition(b->data,&current_position)) */
    gui_EMS_input_box_locate_cursor(b);
    if ((b->flags & UI_EMS_INPUT_BOX_DISPLAY_HEADER) && hflag
        && (b->cursor_ay == 0) && (b->display_y != 0) &&
        (current_position.Object == NULL) /* && TestFirstPosition(b->data,&current_position) */ )
    {
        b->flags |= UI_EMS_INPUT_BOX_DISABLE_TONE;
        b->display_y += EMS_HEADER_SCROLL_SIZE; /* Scroll through header   */
        if (b->display_y > 0)
        {
            b->display_y = 0;
        }
    }


#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_next_line(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    b->flags |= (UI_EMS_INPUT_BOX_NEXT_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_NEXT_LINE | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    /* if(!TestLastPosition(b->data,&b->data->CurrentPosition)) */
    gui_EMS_input_box_locate_cursor(b);

#if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
    gui_EMS_input_box_change_input_mode_for_smart_Abc(b);
#endif
}

#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_view_previous_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_view_previous_object(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    b->flags |= (UI_EMS_INPUT_BOX_PREVIOUS_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_PREVIOUS_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_view_next_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_view_next_object(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_cancel_object_focus();
    b->flags |= (UI_EMS_INPUT_BOX_NEXT_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_show_EMS_input_box(b);
    b->flags &= ~(UI_EMS_INPUT_BOX_NEXT_OBJECT | UI_EMS_INPUT_BOX_DISABLE_DRAW);
    gui_EMS_input_box_locate_cursor(b);
    b->saved_cursor_ax = -1;
}
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_inputbox_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_inputbox_empty(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((b->data->textLength == 0) && (b->data->listHead == NULL))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_end(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition previous_position;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Move cursor backwards until a break character is encountered   */
    while (!done)
    {
        previous_position = *current_position;
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

    /* Move cursor forwards until a break character is encountered */
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (b->data->CurrentPosition.OffsetToText >= b->data->textLength)
    {
        bflag = 1;
    }
    if (bflag)
    {
        done = 1;
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        done = 0;
        b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText >= b->data->textLength)
        {
            break;
        }
        if (ForwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_end_position = *current_position;
    gui_EMS_input_box_locate_cursor(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  numOfChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_number(UI_EMS_input_box *b, S32 numOfChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    U8 bflag;
    UI_character_type current_character;
    S32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined (__MMI_INDIC_ALG__)
    numOfChar += saved_last_skip_pos;
    #endif
    for (i = 0; i < numOfChar; i++)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }

    b->highlight_start_position = *current_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if(current_character == (UI_character_type)0x20) bflag =0;

    if (bflag)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
    {
        b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    b->highlight_end_position = *current_position;
    
    if (b->locate_cursor_flag)
    {
        gui_EMS_input_box_locate_cursor(b);
    }
    
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_highlight_cursor_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_EMS_input_box_highlight_cursor_start(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition *current_position = &b->data->CurrentPosition;
    EMSPosition previous_position;
    EMSPosition saved_current_position = b->data->CurrentPosition;
    U8 done = 0, bflag;
    UI_character_type current_character;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (BackwardCurrentPosition(b->data, 1) != 1)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    /* Move cursor forwards until a break character is encountered */
    while (!done)
    {
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText >= b->data->textLength)
        {
            break;
        }
        if (ForwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_end_position = *current_position;
    /* *current_position=saved_current_position; */
    MoveCursorToPosition(b->data, &saved_current_position);

    /* Move cursor backwards until a break character is encountered   */
    if (BackwardCurrentPosition(b->data, 1) != 1)
    {
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
#if(EMS_BYTE_ORDER_BIG_ENDIAN)
    current_character =
        b->data->textBuffer[current_position->OffsetToText +
                            1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
#else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    current_character =
        b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                               textBuffer[current_position->OffsetToText + 1] << 8);
#endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
    UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
    if (bflag)
    {
        ForwardCurrentPosition(b->data, 1);
        done = 1;
        b->flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        return (0);
    }
    else
    {
        done = 0;
        b->flags |= UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    while (!done)
    {
        previous_position = *current_position;
        if ((current_position->Object != NULL) &&
            (current_position->Object->OffsetToText == current_position->OffsetToText))
        {
            break;
        }
        if (current_position->OffsetToText == 0)
        {
            break;
        }
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    #if(EMS_BYTE_ORDER_BIG_ENDIAN)
        current_character =
            b->data->textBuffer[current_position->OffsetToText +
                                1] | (b->data->textBuffer[current_position->OffsetToText] << 8);
    #else /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        current_character =
            b->data->textBuffer[current_position->OffsetToText] | (b->data->
                                                                   textBuffer[current_position->OffsetToText + 1] << 8);
    #endif /* (EMS_BYTE_ORDER_BIG_ENDIAN) */ 
        count++;
        UI_EMS_INPUT_BOX_BREAK_CHARACTER(current_character, bflag);
        if (bflag)
        {
            break;
        }
    }
    b->highlight_start_position = previous_position;
    /* *current_position=previous_position; */
    MoveCursorToPosition(b->data, &previous_position);
    gui_EMS_input_box_locate_cursor(b);
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_text_format_forward_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  t                               [?]         
 *  length                          [?]         
 *  isModifyExistedTextformat       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_text_format_forward_seek(
        UI_EMS_input_box *b,
        EMSTextFormat *t,
        S32 *length,
        BOOL isModifyExistedTextformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;
    S32 text_format_object_count = 0;
    S32 text_length = 0;
    BOOL isModify = isModifyExistedTextformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (current_position.OffsetToText >= b->data->textLength)
        {
            break;
        }
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                }
                if (text_format_object_count == 0)
                {
                    text_length++;
                }
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    text_format_object_count++;
                    if (isModify)
                    {
                        o->data->text_format.Alignment = t->Alignment;
                    }
                }
                break;
        }
    }
    *length = text_length;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_text_format_backward_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                               [?]         
 *  t                               [?]         
 *  length                          [?]         
 *  isModifyExistedTextformat       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_text_format_backward_seek(
        UI_EMS_input_box *b,
        EMSTextFormat *t,
        S32 *length,
        BOOL isModifyExistedTextformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_length = *length;
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;
    U8 counter_reset_flag = 0;
    S32 saved_text_length = 0;
    S32 old_OffsetToText;
    BOOL isModify = isModifyExistedTextformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            if (counter_reset_flag)
            {
                text_length = saved_text_length;
            }
            break;
        }
        gui_EMS_input_box_set_text_format_cursor_position(b);
        current_position = b->data->CurrentPosition;
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
            case 0:
                if (counter_reset_flag)
                {
                    text_length = saved_text_length;
                }
                counter_reset_flag = 0;
                done = 1;
                break;
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    if (counter_reset_flag)
                    {
                        text_length = saved_text_length;
                    }
                    ForwardCurrentPosition(b->data, 1);
                    done = 1;
                }
                else
                {
                    text_length++;
                }
                counter_reset_flag = 0;
                break;
            case 2:
                if (o->Type == EMS_TYPE_TEXT_FORMAT)
                {
                    if (text_length > 0)
                    {
                        saved_text_length = text_length + 1;
                    }
                    else
                    {
                        saved_text_length = text_length;
                    }
                    text_length = 0;
                    if (isModify)
                    {
                        o->data->text_format.Alignment = t->Alignment;
                    }
                    counter_reset_flag = 1;
                }
                break;
        }
    }
    *length = text_length;

#if(EMS_ENABLE_TESTFIX_OBJECT_ORDERING)
    old_OffsetToText = b->data->CurrentPosition.OffsetToText;
    while (b->data->CurrentPosition.OffsetToText == old_OffsetToText)
    {
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }
    }
    if (b->data->CurrentPosition.OffsetToText != old_OffsetToText)
    {
        ForwardCurrentPosition(b->data, 1);
    }
#endif /* (EMS_ENABLE_TESTFIX_OBJECT_ORDERING) */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetTextFormatObjectAtPosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  p           [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSObject *GetTextFormatObjectAtPosition(EMSData *data, EMSPosition *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSObject *current = data->listHead;
    U16 OffsetToText = (U16) p->OffsetToText;
    EMSObject *return_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (current != NULL)
    {
        if ((current->Type == EMS_TYPE_TEXT_FORMAT) && (current->OffsetToText == OffsetToText))
        {
            return_object = current;
            break;
        }
        if (current->OffsetToText > OffsetToText)
        {
            break;
        }
        current = current->next;
    }
    return (return_object);
}

#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_find_paragraph_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                   [?]     
 *  offsetToText        [?]     
 *  textLength          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_find_paragraph_range(UI_EMS_input_box *b, kal_uint16 *offsetToText, kal_uint16 *textLength)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *offset = offsetToText;
    kal_uint16 *textLen = textLength;
    EMSPosition saved_position = b->data->CurrentPosition;
    EMSPosition current_position = b->data->CurrentPosition;
    UI_character_type c;
    EMSObject *o;
    U8 r;
    U8 done = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Move to the beginning of paragraph */
    while (!done)
    {
        /* Reach the first position */
        if (BackwardCurrentPosition(b->data, 1) != 1)
        {
            break;
        }

        current_position = b->data->CurrentPosition;
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
                /* check if reach the start of paragraph */
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    ForwardCurrentPosition(b->data, 1);
                    done = 1;
                }
                break;

                /* ignore object */
            case 2:
                break;

                /* impossible case */
            case 0:
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    *offset = b->data->CurrentPosition.OffsetToText;

    done = 0;
    current_position = b->data->CurrentPosition;

    /* count to the end of the paragraph */
    while (!done)
    {

        if (current_position.OffsetToText >= b->data->textLength)
        {
            break;
        }
        r = gui_EMS_input_box_get_next_object(b->data, &current_position, &c, &o);
        switch (r)
        {
                /* count the number of characters in the paragraph */
            case 1:
                if (c == EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER)
                {
                    done = 1;
                    (*textLen)++;
                    /* Exclude 0x0d and 0x0a */
                    /* (*textLen)--; */
                }
                else
                {
                    (*textLen)++;
                }
                break;

                /* To the end of the message */
            case 0:
                done = 1;
                break;

                /* ignore object */
            case 2:
                break;

                /* impossible case */
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    MoveCursorToPosition(b->data, &saved_position);

}

/* Warning: Function requires the parameter t to be modified in some cases.
   So it is necessary to pass a copy instead of the actual data            */
/* MTK Joy added for text format insert, 0112 */


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_text_alignment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_insert_text_alignment(UI_EMS_input_box *b, EMSTextFormat *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    kal_uint16 offsetToText = 0;
    kal_uint16 textLength = 0;
    EMSTATUS emsObjectStatus = EMS_OK;
    EMSTextFormat textFormat = *t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->data->textLength == 0)
    {
        return EMS_OK;
    }

    gui_EMS_input_box_find_paragraph_range(b, &offsetToText, &textLength);

    if (textLength == 0)
    {
        return EMS_OK;
    }

    if (b->data->CurrentTextFormatObj == NULL
        && b->text_format.Alignment == t->Alignment)
    {
        return EMS_OK;    
    }

    textFormat.textLength = textLength * 2;
    textFormat.FontSize = EMS_FONTSIZE_NORMAL;
    textFormat.isBold = KAL_FALSE;
    textFormat.isItalic = KAL_FALSE;
    textFormat.isStrikethrough = KAL_FALSE;
    textFormat.isUnderline = KAL_FALSE;
    
    emsObjectStatus = AddTextAlignment(b->data, offsetToText, &textFormat);

    gui_EMS_input_box_set_text_format_cursor_position(b);
    return emsObjectStatus;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_insert_new_paragraph
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 *  t       [?]     
 * RETURNS
 *  
 *****************************************************************************/
EMSTATUS gui_EMS_input_box_insert_new_paragraph(UI_EMS_input_box *b, EMSTextFormat *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(EMS_USE_CRLF_COMBINATION)
    emsObjectStatus = gui_EMS_input_box_insert_new_line_no_sound(b);
#else
    emsObjectStatus = gui_EMS_input_box_insert_new_line(b);
#endif

    if (emsObjectStatus == EMS_OK)
    {
        emsObjectStatus = gui_EMS_input_box_insert_text_alignment(b, t);
    }

    return emsObjectStatus;
}

/* MTK end */
#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  EMS_move_graphical_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  start_x         [IN]        
 *  cursor_x        [IN]        
 *  max_count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_move_graphical_cursor(EMSData *data, S32 start_x, S32 cursor_x, S32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition current_position = data->CurrentPosition;
    U8 done = 0;
    S32 x = start_x;
    S32 count = 0;
    U8 r;
    EMSObject *current_object;
    UI_character_type current_character;
    S32 width = 0, height;
/*PMT IRE START*/
U8 text_format_flag=0;
#ifdef __MMI_INDIC_ALG__
/*PMT IRE END*/
    //EMSData *data_chk_type = data;
    //UI_character_type dummy_c = 0;
    S32 next_ems_moves = 0;
/*PMT IRE START*/
    PU8 src_p=(data->textBuffer + data->CurrentPosition.OffsetToText);
/*PMT IRE END*/
    PU8 dest_p;
/*PMT IRE START*/ 
    U8 cursor_truncation_flag=0;
#endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/ 
#if defined(__MMI_LANG_VIETNAMESE__)
    /* W05.38 Fix Viet Tone Cursor Moving Issue */
    U8 viet_tone_move = 0;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!done)
    {
        if (count >= max_count)
        {
            break;
        }
        /*PMT IRE START*/ 
        #ifdef __MMI_INDIC_ALG__
        if(text_format_flag==0)
        {
            current_position=data->CurrentPosition;
        }
        #endif /* __MMI_HINDI_ALG__ */ 
        /*PMT IRE END*/ 
        
        r = gui_EMS_input_box_get_next_object(data, &current_position, &current_character, &current_object);
        switch (r)
        {
            case 0:
                done = 1;
                break;
            case 1:
        #if(EMS_USE_CRLF_COMBINATION)
                if (UI_TEST_CR_CHARACTER(current_character) && (current_position.OffsetToText < data->textLength) &&
                    UI_TEST_LF_CHARACTER(data->textBuffer[current_position.OffsetToText]))
                {
                    width = 0;
                }
                else if (UI_TEST_LF_CHARACTER(current_character))
                {
                    width = 0;
                }
                else
        #endif /* (EMS_USE_CRLF_COMBINATION) */ 
            #if(EMS_USE_ESC_COMBINATION)
                if (UI_TEST_ESC_CHARACTER(current_character))
                {
                    width = 0;
                }
                else
            #endif /* (EMS_USE_ESC_COMBINATION) */ 
                {
                #if defined(__MMI_LANG_VIETNAMESE__)
                    /* MTK Terry for Cursor Move Up and Down Issue */
                    UI_character_type dummy_c = 0;
                    viet_tone_mark tone_mark = VIET_TONE_NONE;
                    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;

                    if ((current_character > 0x0040) && (current_character < 0x01B1))
                    {
                        r = gui_EMS_input_box_get_next_object(data, &current_position, &dummy_c, &current_object);      /* get next character */
                        if (1 == r)
                        {
                            tone_mark = mmi_viet_tone_mark(dummy_c);
                            if (VIET_TONE_NONE != tone_mark)
                            {
                                viet_vowel = mmi_viet_vowel_letter(current_character);
                                if (VIET_VOWEL_NONE != viet_vowel)
                                {
                                    current_character = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                                    /* W05.38 Fix Viet Tone Cursor Moving Issue */
                                    viet_tone_move = 1;
                                }
                                else
                                {
                                    r = gui_EMS_input_box_get_previous_object(
                                            data,
                                            &current_position,
                                            &dummy_c,
                                            &current_object);
                                }
                            }
                            else
                            {
                                r = gui_EMS_input_box_get_previous_object(
                                        data,
                                        &current_position,
                                        &dummy_c,
                                        &current_object);
                            }
                        }
                        else if (0 != r)
                        {
                            r = gui_EMS_input_box_get_previous_object(
                                    data,
                                    &current_position,
                                    &dummy_c,
                                    &current_object);
                        }
                    }
                #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
/*PMT IRE START*/
                #ifdef __MMI_INDIC_ALG__
                #ifdef __MMI_INDIC_ALG__
                    if(text_format_flag)
                    {
                    src_p = (data->textBuffer + data->CurrentPosition.OffsetToText) - 2;
                    }
                    else
                    {
                        src_p = (data->textBuffer + data->CurrentPosition.OffsetToText);
                    }
        #endif /* __MMI_INDIC_ALG__ */
                    if (IRE_INDIC_CHARACTER_UCS2_RANGE(current_character))
                    {
/* PMT START MAUI_00027731 */
                        dest_p = ire_get_next_cluster_p(src_p, gui_show_EMS_input_box_find_segment_end(data,src_p));
/* PMT END MAUI_00027731 */
/*PMT IRE END*/
                        next_ems_moves = dest_p - src_p;
                        next_ems_moves = next_ems_moves >> 1;
/*PMT IRE START*/
                        if(text_format_flag)
                        {
                            if(count-1+next_ems_moves>max_count)
                            {
                                cursor_truncation_flag=1;
                                BackwardCurrentPosition(data,1);
                                break;
                            }
                        }
                        else
                        {
                            if(count+next_ems_moves>max_count)
                            {
                                cursor_truncation_flag=1;
                                break;
                            }

                        }
/*PMT IRE END*/
/*PMT IRE START*/
                        
                        if (next_ems_moves >= 2)    /* && r==2) //&& current_object->Type==EMS_TYPE_TEXT_FORMAT) */
                        {
                            ForwardCurrentPosition(data, next_ems_moves - 1);
                            count += next_ems_moves - 1;
                            width = ire_size_of_current_cluster(src_p, dest_p, 1);
                            if((x+width+1) > (cursor_x + (width >> 1)))
                            {
                                BackwardCurrentPosition(data, next_ems_moves - 1);
                                if(text_format_flag)
                                {
                                    BackwardCurrentPosition(data,1);
                                }

                            }
                            next_ems_moves = 0;
/*PMT IRE END*/
                        }
                        else
                        {
                            gui_measure_character(current_character, &width, &height);
                        }
                        src_p = dest_p;
                    }
                    else
/*PMT IRE START*/
                #endif /* __MMI_INDIC_ALG__ */ 
/*PMT IRE END*/
                        gui_measure_character(current_character, &width, &height);
                    width += 1;
                }
                x += width;
                break;
            #ifdef __MMI_MESSAGES_EMS__
            case 2:
                if (current_object->Type == EMS_TYPE_TEXT_FORMAT)
                {
/*PMT IRE START*/   
            text_format_flag=1;
/*PMT IRE END*/
                    width = 0;
                }
                else
                {
                    gui_EMS_input_box_measure_object(current_object, &width, &height);
                    width += 2;
                }
                x += width;
                break;
            #endif /* __MMI_MESSAGES_EMS__ */ 
        }
        if (x <= (cursor_x + (width >> 1)))
        {
 /*PMT IRE START*/
        #ifdef __MMI_INDIC_ALG__
            if(cursor_truncation_flag)
            {
                cursor_truncation_flag=0;
                break;

            }
        #endif /* __MMI_INDIC_ALG__ */ 
            if(text_format_flag==1 && r==1)
            {
                text_format_flag=0;
                continue;
            }
/*PMT IRE END*/
            count++;
            if (ForwardCurrentPosition(data, 1) != 1)
            {
                break;
            }
        #if defined(__MMI_LANG_VIETNAMESE__)
            /* W05.38 Fix Viet Tone Cursor Moving Issue */
            if (1 == viet_tone_move)
            {
                if (ForwardCurrentPosition(data, 1) != 1)
                {
                }
                viet_tone_move = 0;
            }
        #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
        }
        else
        {
            break;
        }
    }
}
/*PMT IRE START*/


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
void gui_EMS_post_template_addition_adjustment(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSPosition p1 = b->data->CurrentPosition;
    EMSData *data_chk_type1 = b->data;
    UI_character_type current_character1 = 0;
    EMSObject *o1/*,*object_pointer1*/;
    U8 saved_last_skip_pos_template=0;
    U8 object_type_check1 = 0;
/* PMT START MAUI_00024993 */
	multitap_to_cancel =1;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p1=b->data->CurrentPosition;
    if (!TestLastPosition(b->data, &(b->data->CurrentPosition)))
    {
        object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
    }
    /*This statement checks whether the following sequence :Cons.+Halant(Cursor)+Cons...  */
    /*is there or not.If it is there then move the cursor beyond the cluster formed.      */
/* PMT START MAUI_00027731 */
    if((object_type_check1==1)&&( IRE_IS_CHAR_TYPE_CONSONANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
         | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ))) 
         && ( IRE_IS_CHAR_TYPE_CONSONANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-4] 
         | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -3]<<8) ))) 
         && ( IRE_IS_CHAR_TYPE_HALANT((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2] 
         | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ))) ) 
	{
        U32 langid_Halant=0;
        U32 diff_langid_cons_halant=0;
        langid_Halant =  IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText-2]
                            | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText -1]<<8) ));
        if(langid_Halant != IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
             | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) )))
        {
            diff_langid_cons_halant =1;
        }
		if(!diff_langid_cons_halant)
        {
            
            /*This loop calculates the total length of the cluster if it is equal to 28            */
            /*This loop gets executed when following sequence of characters:Cons+Halant..14 times  */
            /* or more is there                                                                    */
                    //EMSObject *object_pointer1;
                    U8 skip_positions = 0;
                    PU8 dest_pos;
					//U8 i=0;
				    U32 counter =0;
				    U32 langid_Consonant =0;
                    UI_character_type previous_character2 = 0;
					//U16 array[12];
					UI_buffer_type first_cons_ems_position;
					//EMSTextFormat text_format;
                    PU8 src_pos = (&b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
                    p1 = b->data->CurrentPosition;
                    object_type_check1 = gui_EMS_input_box_get_next_object(data_chk_type1, &p1, &current_character1, &o1);
                    dest_pos = ire_get_next_cluster_p(src_pos, gui_show_EMS_input_box_find_segment_end(b->data,src_pos));
                    skip_positions = dest_pos - src_pos;    /* Number of moves */
                    skip_positions = skip_positions >> 1;
                    saved_last_skip_pos_template = skip_positions;
				    first_cons_ems_position = &(b->data->textBuffer[b->data->CurrentPosition.OffsetToText]);
				    langid_Consonant = IRE_GET_CHARACTER_LANG_ID((U16)(b->data->textBuffer[b->data->CurrentPosition.OffsetToText] 
                    | (b->data->textBuffer[b->data->CurrentPosition.OffsetToText + 1]<<8) ));
				
				    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                    p1=b->data->CurrentPosition;
				    while((1==gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1))&&(IRE_GET_CHARACTER_LANG_ID((U16)previous_character2)==langid_Consonant)&&IRE_IS_CHAR_TYPE_HALANT((U16)previous_character2))
					{
						counter +=2;
					    first_cons_ems_position-=2;
					    if(b->data->textBuffer>=first_cons_ems_position)
						{
							break;
						}
					    UI_STRING_GET_PREVIOUS_CHARACTER(first_cons_ems_position,previous_character2);
                        gui_EMS_input_box_get_previous_object(data_chk_type1, &p1, &current_character1, &o1);
					
					}
				    counter= counter % ((G_MAX-2));
				    skip_positions = (G_MAX-2) - counter;
				    if(saved_last_skip_pos_template > skip_positions)
					{
						saved_last_skip_pos_template = skip_positions;

					}
                    ForwardCurrentPosition(b->data, saved_last_skip_pos_template);

                    
                    PRINT_INFORMATION_2(MMI_TRACE_INFO,"pixtel_UI_EMS_input_box_insert_multitap_character[skip_positions]:%d  ",
                                           saved_last_skip_pos_template);
                 }
    }
/* PMT END MAUI_00027731 */
}
#endif /* __MMI_INDIC_ALG__ */ 



/*PMT IRE END*/
#endif /* (!UI_DISABLE_EMS_INPUT_BOX) */ 

/* msz00065_20051010 peng hua add for multitap thai begin */
#ifdef __MMI_MULTITAP_THAI__


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_check_input_test_overflow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]         
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_EMS_check_input_test_overflow(UI_EMS_input_box *b, UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ch = (U16) c;
    U8 s[2] = {0, 0};
    S32 remaining_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    if (b->UCS2_count > 0)
    {
        remaining_length = (EMS_get_remaining_length(b->data) >> 1);
    }
    else
    {
        remaining_length = EMS_get_remaining_length(b->data);

    }
    if (remaining_length <= 0)
    {
        return FALSE;
    }
    if (b->UCS2_count == 0)
    {
        if (UI_TEST_UCS2_CHARACTER(c))
        {
            if (EMSSetDCS(b->data, SMSAL_UCS2_DCS) != EMS_OK)
            {
                EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                return FALSE;
            }
            else
            {
                if (EMS_get_remaining_length(b->data) < 2)
                {
                    EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                    return FALSE;
                }
                else
                {
                    EMSSetDCS(b->data, SMSAL_DEFAULT_DCS);
                    return TRUE;
                }
            }
        }
        else if (UI_TEST_GSM_EXTENDED(c))
        {
            if (EMS_get_remaining_length(b->data) < 1)  /* JP : 408 info bar issue */
            {
                return FALSE;
            }
        }
    }
    /* MTK end */

    /* If in Overwrite mode, delete the current character/object and insert the new one */
    if (b->flags & UI_EMS_INPUT_BOX_OVERWRITE_MODE)
    {
        return TRUE;
    }
    return TRUE;
}
#endif /* __MMI_MULTITAP_THAI__ */ 
/* msz00065_20051010 peng hua add for multitap thai end */

#ifdef __MMI_TOUCH_SCREEN__
static UI_EMS_input_box *gui_pen_scroll_EMS_input_box = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_by_pen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  offset_y                [IN]        
 *  EMS_input_box_event     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_scroll_by_pen(
                UI_EMS_input_box *b,
                S32 offset_y,
                gui_EMS_input_box_pen_enum *EMS_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int move_gap = b->display_y + offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_cancel_object_focus();
#endif 
    b->display_y = -offset_y;
    /* W06.06 Fix Cursor issue in EMS Input Box */
    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE))
    {
        if (b->cursor_ay < -(b->display_y) || b->cursor_ay + b->cursor_line_height > b->height - b->display_y)
        {
            if (move_gap > 0)
            {
                gui_show_EMS_input_box_ext(b, UI_cursor_x1 + 2, UI_cursor_y1 + b->cursor_line_height);
            }
            else
            {
                if (0 == offset_y)
                {
                    gui_show_EMS_input_box_ext(b, UI_cursor_x1 + 2, UI_cursor_y1 + move_gap);
                }
                else
                {
                    gui_show_EMS_input_box_ext(b, UI_cursor_x1 + 2, UI_cursor_y1);
                }
            }
        }
    }
    b->display_y = -offset_y;
    if (!(b->flags & UI_EMS_INPUT_BOX_VIEW_MODE) && (0 != offset_y))
    {
        gui_EMS_input_box_locate_cursor(b);
    }
    gui_show_EMS_input_box(b);
    gui_BLT_double_buffer(b->x, b->y, b->x + b->width, b->y + b->height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_scroll_timer_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_scroll_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = gui_pen_scroll_EMS_input_box;
    gui_EMS_input_box_pen_enum EMS_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_EMS_input_box = NULL;

    if (!b)
    {
        return;
    }

    gui_EMS_input_box_scroll_by_pen(b, b->pen_scroll_after_delay, &EMS_input_box_event);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_abort_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_abort_scroll_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_pen_scroll_EMS_input_box = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_start_scroll_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b           [?]         
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_EMS_input_box_start_scroll_timer(UI_EMS_input_box *b, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assert that no two input box at the same time */
    MMI_DBG_ASSERT(!gui_pen_scroll_EMS_input_box || gui_pen_scroll_EMS_input_box == b);

    b->pen_scroll_after_delay = value;
    gui_pen_scroll_EMS_input_box = b;

    gui_cancel_timer(gui_EMS_input_box_scroll_timer_hdlr);
    gui_start_timer(b->pen_scroll_delay_time, gui_EMS_input_box_scroll_timer_hdlr);

    gui_add_cleanup_hook(gui_EMS_input_box_abort_scroll_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_EMS_input_box_set_pen_scroll_delay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  delay_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_EMS_input_box_set_pen_scroll_delay(UI_EMS_input_box *b, S32 delay_time)
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
 *  gui_EMS_input_box_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]         
 *  pen_event               [IN]        
 *  x                       [IN]        
 *  y                       [IN]        
 *  EMS_input_box_event     [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL gui_EMS_input_box_translate_pen_event(
        UI_EMS_input_box *b,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_EMS_input_box_pen_enum *EMS_input_box_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = MMI_TRUE;
    gui_EMS_input_box_pen_state_struct *pen_state;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    int scroll_bar_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR & b->flags)
    {
        scroll_bar_width = 0;
    }
    else
    {
        scroll_bar_width = b->vbar.width;
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
                gui_EMS_input_box_start_scroll_timer(b, scrollbar_param._u.i);
            }
            else
            {
                gui_EMS_input_box_scroll_by_pen(b, scrollbar_param._u.i, EMS_input_box_event);
            }
        }
        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR;
    }
    else
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width, b->height))
                {
                    pen_state->pen_on_scroll_bar = 0;
                    gui_vertical_scrollbar_set_minimum_pen_offset(&b->vbar, b->cursor_line_height);
                    if (!(b->flags & UI_EMS_INPUT_BOX_DISABLE_SCROLLBAR) &&
                        gui_vertical_scrollbar_translate_pen_event(
                            &b->vbar,
                            MMI_PEN_EVENT_DOWN,
                            x,
                            y,
                            &scrollbar_event,
                            &scrollbar_param))
                    {
                        pen_state->pen_on_scroll_bar = 1;
                        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
                        {
                            if (b->pen_scroll_delay_time > 0)   /* Delay time for scrollbar scrolling */
                            {
                                gui_EMS_input_box_start_scroll_timer(b, scrollbar_param._u.i);
                            }
                            else
                            {
                                gui_EMS_input_box_scroll_by_pen(b, scrollbar_param._u.i, EMS_input_box_event);
                            }
                        }
                        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_SCROLL_BAR;
                    }
                    else
                    {
                        *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_DOWN;
                    }
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
            case MMI_PEN_EVENT_UP:
                if (PEN_CHECK_BOUND(x, y, b->x, b->y, b->width - scroll_bar_width, b->height))
                {
                    *EMS_input_box_event = GUI_EMS_INPUT_BOX_PEN_TEXT_UP;
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

