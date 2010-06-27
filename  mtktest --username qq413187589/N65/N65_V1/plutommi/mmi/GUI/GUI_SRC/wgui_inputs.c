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
 *    wgui_inputs.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Input related wrapper functions
 *
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

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_inputs.c
   Author:        manju
   Date Created:  August-07-2002
   Contains:      PixTel UI wrapper routines for Input related objects
**********************************************************************************/

#include "wgui_inputs.h"
#include "MMI_features.h"
#include "TimerEvents.h"
// #include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "CommonScreens.h"
#include "DebugInitDef.h"
#include "Gui_Setting.h"        /* 053005 Calvin added */
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "EditorPenGprot.h"
#endif 
#include "IMEres.h"

#ifdef __MMI_TOUCH_DIAL_SCREEN__
#include "gui_inputs.h"
#include "wgui.h"
#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 
#include "gdi_include.h"
/* W05.36 Fix Vietnamese Tone Input Issue */
#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"
#define MMI_VIET_TONE_KEY 1
#endif /* __MMI_LANG_VIETNAMESE__ */ 
#if defined(__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif /* defined(__MMI_LANG_THAI__) */
#include "gui_ems.h"
extern UI_EMS_input_box MMI_EMS_inputbox;
extern single_line_input_box MMI_inline_singleline_inputbox;
extern UI_character_type gui_EMS_current_character(UI_EMS_input_box *b);
extern UI_character_type gui_single_line_current_character(single_line_input_box *b);
extern void wgui_handle_inputbox_input(void);
extern void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight);

#if defined(__MMI_MIXED_LANG_SUPPORT__)
extern S16 g_ime_sub_writing_lang;
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */

extern void StopTimer(U16 timerid);

#if defined(__MMI_PHB_QUICK_SEARCH__)
extern void mmi_phb_quick_search_change_input_mode(void);
#endif 
#ifdef __MMI_TOUCH_DIAL_SCREEN__
dialing_keypad_struct dialing_keypad;

#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

#ifdef __MMI_T9__
#include "t9definition.h"
#include "t9api.h"
extern void T9KeyStarPressHandlerMultilineInputBox(void);
extern void T9KeyArrowUPHandlerMultilineInputBox(void);
extern void T9KeyArrowDownHandlerMultilineInputBox(void);
extern void T9KeyArrowRightHandlerMultilineInputBox(void);
extern void T9KeyArrowLeftHandlerMultilineInputBox(void);
extern void T9Key0To9HandlerMultilineInputBox(void);
extern void T9Key0PressHandlerMultilineInputBox(void);
extern void T9Key1PressHandlerMultilineInputBox(void);
extern void T9Key2PressHandlerMultilineInputBox(void);
extern void T9Key3PressHandlerMultilineInputBox(void);
extern void T9Key4PressHandlerMultilineInputBox(void);
extern void T9Key5PressHandlerMultilineInputBox(void);
extern void T9Key6PressHandlerMultilineInputBox(void);
extern void T9Key7PressHandlerMultilineInputBox(void);
extern void T9Key8PressHandlerMultilineInputBox(void);
extern void T9Key9PressHandlerMultilineInputBox(void);

/* PMT dara added Modified for Default key functionality for Pound Key */
extern void T9KeyPoundPressHandlerMultilineInputBox(void);
extern void T9InputBoxDisplayMultilineInputBox(void);
extern void T9ScreenStateChnageMultilineInputBox(void);
extern void T9SynT9WithInputBoxMultilineInputBox(void);
extern void T9ChangeLanguageMultilineInputBox(T9U8 inputMethod);
extern void T9ClearKeyNavigationHandler(void);
extern void T9ClearKeyStarAndPoundHandler(void);
extern void T9ClearKey0To9Handler(void);

extern BOOL (*wgui_check_pound_key_buffer_flush)(void);

void wgui_paging_highlight_search_string(S32 text_offset, S8 search_str_len);
#elif defined __MMI_CSTAR__
#include "CStarHMI.h"
extern void CstarInputMethodEnterCategory28(void);
extern void CstarDisplay(void);
extern void CstarSetInputboxLSKFunction(FuncPtr f);
extern void CstarKey0PressHandler(void);
extern void CstarKey1PressHandler(void);
extern void CstarKey2PressHandler(void);
extern void CstarKey3PressHandler(void);
extern void CstarKey4PressHandler(void);
extern void CstarKey5PressHandler(void);
extern void CstarKey6PressHandler(void);
extern void CstarKey7PressHandler(void);
extern void CstarKey8PressHandler(void);
extern void CstarKey9PressHandler(void);
extern void CstarKeyArrowUpHandler(void);
extern void CstarKeyArrowDownHandler(void);
extern void CstarKeyArrowLeftHandler(void);
extern void CstarKeyArrowRightHandler(void);
extern void CstarKeyStarPressHandler(void);
extern void CstarKeyLSKPressHandler(void);
extern void CstarKeyRSKPressHandler(void);
extern void CstarKeyRSKLongPressHandler(void);
extern void CstarClearKey0To9Handler(void);
extern void CstarClearKeyNavigationHandler(void);
extern void CstarClearKeyStarAndPoundHandler(void);
#elif defined __MMI_ZI__

#include "t9def.h"
#include "zi8hmi.h"
extern void ZiResizeSelectionArea(void);

extern void ZiKey0PressHandler(void);
extern void ZiKey1PressHandler(void);
extern void ZiKey2PressHandler(void);
extern void ZiKey3PressHandler(void);
extern void ZiKey4PressHandler(void);
extern void ZiKey5PressHandler(void);
extern void ZiKey6PressHandler(void);
extern void ZiKey7PressHandler(void);
extern void ZiKey8PressHandler(void);
extern void ZiKey9PressHandler(void);

extern void ZiKeyArrowUPHandler(void);
extern void ZiKeyArrowRightHandler(void);
extern void ZiKeyArrowDownHandler(void);
extern void ZiKeyArrowLeftHandler(void);

extern void ZiKeyStarPressHandler(void);
extern void ZiKeyStarLongPressHandler(void);
extern void ZiKeyHashPressHandler(void);
extern void ZiKeyHashLongPressHandler(void);

extern void ZiKeyLSKPressHandler(void);
extern void ZiKeyLSKLongPressHandler(void);
extern void ZiKeyRSKPressHandler(void);
extern void ZiKeyRSKLongPressHandler(void);
#ifdef __MMI_MIXED_LANG_SUPPORT__
extern void ZiChangeInputMethod(INPUT_MODE inputMode, ime_support_writing_lang_enum sec_lang);
#else
extern void ZiChangeInputMethod(INPUT_MODE inputMode);
#endif
extern void ZiClearKeyStarAndPoundHandler(void);
extern void ZiClearKeyNavigationHandler(void);
extern void ZiClearArrowKeyLeftHandler(void);
extern void ZiClearArrowKeyRightHandler(void);
extern void ZiClearKey0To9Handler(void);

extern void ZiInuptMethodEnterCategory28(void);
extern void ZiDisplay(void);
#elif defined __MMI_CSTAR__
#include "CStarHMI.h"
#elif defined(__MMI_KA__)
#include "t9def.h"
#include "konkahmi.h"
extern void KonkaKey0PressHandler(void);
extern void KonkaKey1PressHandler(void);
extern void KonkaKey2PressHandler(void);
extern void KonkaKey3PressHandler(void);
extern void KonkaKey4PressHandler(void);
extern void KonkaKey5PressHandler(void);
extern void KonkaKey6PressHandler(void);
extern void KonkaKey7PressHandler(void);
extern void KonkaKey8PressHandler(void);
extern void KonkaKey9PressHandler(void);

extern void KonkaKeyArrowUPHandler(void);
extern void KonkaKeyArrowRightHandler(void);
extern void KonkaKeyArrowDownHandler(void);
extern void KonkaKeyArrowLeftHandler(void);

extern void KonkaKeyStarPressHandler(void);
extern void KonkaKeyStarLongPressHandler(void);
extern void KonkaKeyHashPressHandler(void);
extern void KonkaKeyHashLongPressHandler(void);

extern void KonkaKeyLSKPressHandler(void);
extern void KonkaKeyLSKLongPressHandler(void);
extern void KonkaKeyRSKPressHandler(void);
extern void KonkaKeyRSKLongPressHandler(void);
extern void KonkaChangeInputMethod(INPUT_MODE inputMode);
extern void KonkaClearKeyStarAndPoundHandler(void);
extern void KonkaClearKeyNavigationHandler(void);
extern void KonkaClearArrowKeyLeftHandler(void);
extern void KonkaClearArrowKeyRightHandler(void);
extern void KonkaClearKey0To9Handler(void);

extern void KonkaInuptMethodEnterCategory28(void);
extern void KonkaDisplay(void);
#elif defined __MMI_ITAP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/*PMT IRE START*/
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
/*PMT IRE END*/
#endif 

/* store Main LCD height */
extern S32 MAIN_LCD_device_height;

#include "wgui_categories.h"

#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
extern void wgui_handle_inputbox_change_input_mode_bymultitapthai(void);
extern void wgui_handle_qsearch_change_input_mode_bymultitapthai(void);
extern void wgui_handle_symbol_picker_bymultitapthai(void);
#endif /* __MMI_MULTITAP_FOR_STAR_AND_POUND__ */ 
extern void wgui_redraw_singleline_input_information_bar(void);

extern U8 EMS_inputbox_check_multitap_thai_input(UI_character_type inputchar, U8 *updatef);


extern void wgui_handle_inputbox_change_input_mode(void);
extern void wgui_set_RSK(void);
extern void wgui_set_singleline_RSK(void);
extern void wgui_handle_singleline_inputbox_change_input_mode(void);
extern void wgui_handle_inputbox_change_input_mode(void);
extern void wgui_handle_qsearch_singleline_inputbox_change_input_mode(void);
extern int gui_set_multitap_input_text(multitap_input *b, UI_string_type text);
extern S32 UI_strlen(UI_string_type text);
/* W05.37 Fix Vietnamese Tone Issue Side effect */
extern U8 MMI_allow_only_english_input_modes;

extern void inline_fixed_list_goto_previous_item(void);

extern void wgui_inputbox_handle_symbol_picker_star_key_down(void);
extern void wgui_redraw_input_information_bar(void);
extern UI_character_type gui_multi_line_current_character(multi_line_input_box *b);
extern S8 hilited_item_changed;


extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];

/* 072904 Calvin moved for centralized control */
//#define ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING              1
//#define ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING             1
//#define ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING                 1
/* Calvin end */

#define ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT 0
#define ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT   0

/* multitap object wrappers            */

S32 MMI_multitap_x;
S32 MMI_multitap_y;
S32 MMI_multitap_width;
S32 MMI_multitap_height;
S32 MMI_singleline_inputbox_x;
S32 MMI_singleline_inputbox_y;
S32 MMI_singleline_inputbox_width;
S32 MMI_singleline_inputbox_height;
S32 MMI_multiline_inputbox_x;
S32 MMI_multiline_inputbox_y;
S32 MMI_multiline_inputbox_width;
S32 MMI_multiline_inputbox_height;
S32 MMI_general_inputbox_x;
S32 MMI_general_inputbox_y;
S32 MMI_general_inputbox_width;
S32 MMI_general_inputbox_height;

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
pBOOL wgui_paging_show_percentage = 0;
typedef void (*percentage_hdlr) (S32 value);
percentage_hdlr percentage_callback = NULL;

typedef void (*stop_scroll_hdlr)(void);
static stop_scroll_hdlr stop_auto_scroll_callback = NULL;

#endif 

static BOOL multi_line_pen_down_hilite_flag = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  dummy_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_input_callback(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(c);
}


/*****************************************************************************
 * FUNCTION
 *  dummy_input_complete_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_input_complete_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
#define MULTITAP_STAR 10
#define MULTITAP_POUND 11
extern void MMI_key_pound_up(void);
extern void MMI_key_pound_down(void);
extern void MMI_key_star_up(void);
extern void MMI_key_star_down(void);
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
/* MTK Elvis to add some APIs for Qsearch */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) || !defined(__MMI_T9_DEFAULT_KEY_DEFINITION__)
const UI_character_type default_bpmf_multitap_strings[MAX_MULTITAPS][32] = 
{
    {0x3127, 0x3128, 0x3129, '\0'},
    {0x3105, 0x3106, 0x3107, 0x3108, '\0'},
    {0x3109, 0x310A, 0x310B, 0x310C, '\0'},
    {0x310D, 0x310E, 0x310F, '\0'},
    {0x3110, 0x3111, 0x3112, '\0'},
    {0x3113, 0x3114, 0x3115, 0x3116, '\0'},
    {0x3117, 0x3118, 0x3119, '\0'},
    {0x311A, 0x311B, 0x311C, 0x311D, '\0'},
    {0x311E, 0x311F, 0x3120, 0x3121, '\0'},
    {0x3122, 0x3123, 0x3124, 0x3125, 0x3126, '\0'},
};
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) || !defined(__MMI_T9_DEFAULT_KEY_DEFINITION__) */ 
const UI_character_type default_bpmf_multitap_strings[MAX_MULTITAPS][32] = 
{
    {'\0'},
    {0x3105, 0x3109, 0x311A, '\0'},
    {0x310D, 0x3110, 0x311E, '\0'},
    {0x3113, 0x3117, 0x3122, 0x3126, '\0'},
    {0x3106, 0x310A, 0x311B, '\0'},
    {0x310E, 0x3111, 0x311F, '\0'},
    {0x3114, 0x3118, 0x3123, 0x3127, '\0'},
    {0x3107, 0x310B, 0x311C, '\0'},
    {0x310F, 0x3112, 0x3120, 0x3121, '\0'},
    {0x3115, 0x3119, 0x3124, 0x3128, '\0'},
    {0x3108, 0x310C, 0x311D, '\0'},
    {0x3116, 0x3125, 0x3129, '\0'},
};
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) || !defined(__MMI_T9_DEFAULT_KEY_DEFINITION__) */ 
/* MTK end */
const UI_character_type default_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x0300,
     0x0309,
     0x0303,
     0x0301,
     0x0323,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
     /* PMT NO_AR_SL_DU START 20050909 */
     '.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1',
     //Norwegian start
    #if defined(__MMI_LANG_NORWEGIAN__) || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__)
     0x0029,
     0x0028,
     0x003B,
     0x002A,
    #endif /* defined(__MMI_LANG_NORWEGIAN__) || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian end */
     '\0'},
    //MTK end
    {'A', 'B', 'C', '2',
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_ROMANIAN__)
     0x0102,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00C4,
    #endif /* defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00C1,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
	#if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00C0,
    #endif 
	#if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_TURKISH__) 
     0x00C2,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_PORTUGUESE__)
     0x00C3,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__)
     0x00C7,
    #endif 
    #if defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) 
     0x010c,
     0x0106,
    #endif /* defined(__MMI_LANG_CROATIAN__) */ 
    //#if defined(__MMI_LANG_TURKISH__)  
    // 0x00C2,
    //#endif 
    #if defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_NORWEGIAN__)
     0x00C5,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_NORWEGIAN__)  
     0x00C6,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) */ 
    //#if defined(__MMI_LANG_DANISH__) 
    // 0x00C5,
    //#endif 
    //#if defined(__MMI_LANG_POLISH__)  
    // 0x00C5,
    //#endif 
    #if defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_ROMANIAN__)
     0x00E1,
    #endif /* defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_ROMANIAN__) */ 
    //#if defined(__MMI_LANG_SWEDISH__) 
    // 0x00C5,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) 
     //0x010c,     
     0x0104,
     //0x0106,     
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_SLOVENIAN__) 
     //0x010c,
     //0x0104,   
     //0x0106,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
     //Norwegian start
   // #if defined(__MMI_LANG_NORWEGIAN__) 
     //0x00C5,
     //0x00C6,
     //0x00C1,
     //0x00C0, 
     //0x00C4,
    //#endif /* defined(__MMI_LANG_NORWEGIAN__) */
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03b1,
     0x03b2,
     0x03ac,
     0x03b3,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'D', 'E', 'F', '3',
	//PMT START 20060713
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_CROATIAN__) 
     0x0110,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00C9,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_HUNGARIAN__)
     0x00E1,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
	 0x00C8,
    #endif 
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__)
     0x00CA,
    #endif 
    #if defined(__MMI_LANG_FRENCH__)
     0x00CB,
    #endif 
    #if defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_HUNGARIAN__) 
     0x010F,
    #endif 
    //#if defined(__MMI_LANG_HUNGARIAN__)  
    // 0x010F,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) 
	 //PMT END 20060713
     0x010e,
     0x011a,
     0x0118,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_SLOVENIAN__)   
     //0x010e,   
     //0x011a,   
     //0x0118,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */
     //Norwegian start
    //#if defined(__MMI_LANG_NORWEGIAN__)
     //0x00C9, 
    // 0x00C8,
    //#endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    //#if defined(__MMI_LANG_CROATIAN__) 
    // 0x0110,
    //#endif 
    #if defined(__MMI_LANG_GREEK__)
     0x03b4,
     0x03b5,
     0x03b6,
     0x03ad,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'G', 'H', 'I', '4',
    #if defined(__MMI_LANG_ITALIAN__)
     0x00CC,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__)
     0x00CD,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ROMANIAN__)
     0x00CE,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__)
     0x00CF,
    #endif 
    #if defined(__MMI_LANG_TURKISH__)
     0x011E,
    #endif 
    #if defined(__MMI_LANG_TURKISH__)
     0x0130,
    #endif 
    #if defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_HUNGARIAN__) 
     0x00ED,
    #endif /* defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_ROMANIAN__) */ 
    //#if defined(__MMI_LANG_HUNGARIAN__)  
    // 0x00ED,
    //#endif 
    #if defined(__MMI_LANG_GREEK__)
     0x03b7,
     0x03b8,
     0x03b9,
     0x03ae,
     0x03af,
     0x03ca,
     0x0390,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'J', 'K', 'L', '5',
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) 
     0x0139,
     0x013d,
     0x0141,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_SLOVENIAN__)  
    // 0x0139,
    // 0x013d,
    // 0x0141,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_GREEK__)
     0x03ba,
     0x03bb,
     0x03bc,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'M', 'N', 'O', '6',
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FRENCH__) 
     0x00D1,
    #endif 
    #if defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00D2,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00D3,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
	 //#if defined(__MMI_LANG_SPANISH__) 
    // 0x00D2,
    //#endif 
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00D4,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x01A0,
    #endif 
    #if defined(__MMI_LANG_PORTUGUESE__)
     0x00D5,
    #endif 
    #if defined(__MMI_LANG_FRENCH__)
     0x0152,
    #endif 
    #if defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00D6,
    #endif /* defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
	 //#if defined(__MMI_LANG_FRENCH__) 
    // 0x00D1,
    //#endif 
    //#if defined(__MMI_LANG_ROMANIAN__)  
    // 0x0150,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_ROMANIAN__)
     0x0143,
     0x0147,
     0x0150,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_SLOVENIAN__)  
    // 0x0143,
    // 0x0147,
    // 0x0150,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
     //Norwegian start
    #if defined(__MMI_LANG_NORWEGIAN__)
     0x00D8,
     //0x00D3, 
     //0x00D2,   
     //0x00D4,  
     //0x00D6,  
    #endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03bd,
     0x03be,
     0x03bf,
     0x03cc,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'P', 'Q', 'R', 'S', '7',
    #if defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_ROMANIAN__)
     0x015E,
    #endif /* defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_CROATIAN__) 
	 //PMT END 20060713
     0x015a,
     0x0154,
     0x0158,
     0x0160,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_CROATIAN__)
    // 0x0160,
    //#endif 
    //#if defined(__MMI_LANG_SLOVENIAN__) 
    // 0x015a,
    // 0x0154,
    // 0x0158,  
    // 0x0160,  
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */  
    #if defined(__MMI_LANG_GREEK__)
     0x03c0,
     0x03c1,
     0x03c3,
     0x03c2,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'T', 'U', 'V', '8',
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x01AF,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__)
     0x00D9,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__)
     0x00DA,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_TURKISH__) 
     0x00DB,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00DC,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
	 // #if defined(__MMI_LANG_TURKISH__) 
   //  0x00DB,
    //#endif 
    #if defined(__MMI_LANG_ROMANIAN__)
     0x0162,
    #endif
    //#if defined(__MMI_LANG_ROMANIAN__)  
     //0x0170,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_ROMANIAN__)  
     0x016e,
     0x0164,
     0x0170,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian start */
    //#if defined(__MMI_LANG_NORWEGIAN__)  
    // 0x00DC,
    //#endif 
     //Norwegian end
    //#if defined(__MMI_LANG_SLOVENIAN__)  
     //0x016e,
     //0x0164,
     //0x0170,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_GREEK__)
     0x03c4,
     0x03c5,
     0x03c6,
     0x03cd,
     0x03cb,
     0x03b0,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'W', 'X', 'Y', 'Z', '9',
    #if defined(__MMI_LANG_FRENCH__)
     0x0178,
    #endif 
    #if defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_POLISH__) 
     0x00DD,
    #endif /* defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    //#if defined(__MMI_LANG_POLISH__)  
    // 0x00DD,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__)  
     0x017b,
     0x017d,
     0x0179,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
    //#if defined(__MMI_LANG_CROATIAN__)  
    // 0x017d,
    //#endif 
    //#if defined(__MMI_LANG_SLOVENIAN__)  
    // 0x017b,
    // 0x017d,
    // 0x0179,
    //#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_GREEK__)
     0x03c7,
     0x03c8,
     0x03c9,
     0x03ce,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x0300,
     0x0309,
     0x0303,
     0x0301,
     0x0323,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
     	'.',',','-','?','!','\'','@',':','#','$','/','_','(',')','1',
     //Norwegian start
    #if defined(__MMI_LANG_NORWEGIAN__) || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__)
     0x0029,
     0x0028,
     0x003B,
     0x002A,
    #endif /* defined(__MMI_LANG_NORWEGIAN__) || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian end */
     '\0'},
    {'a', 'b', 'c', '2',
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_ROMANIAN__)
     0x0103,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E4,
    #endif /* defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__)
     0x00E1,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E0,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__) */ 
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_TURKISH__) 
     0x00E2,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__)
     0x00E3,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__)
     0x00E7,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__) */ 
    //#if defined(__MMI_LANG_TURKISH__)  
    // 0x00E2,
    //#endif 
    #if defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_SLOVAK__) 
     0x010d,
     0x0107,
    #endif /* defined(__MMI_LANG_CROATIAN__) */ 
    #if defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_SLOVAK__) 
	 //0x010d, 
     0x0105,
     //0x0107,
    #endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E6,
    #endif 
    #if defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E5,
    #endif /* defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_FINNISH__) */ 
    //#if defined(__MMI_LANG_SWEDISH__)  
    // 0x00E5,
    //#endif 
    //#if defined(__MMI_LANG_SLOVAK__) 
     //0x010d,
     //0x0105, 
     //0x0107,
    //#endif /* defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian start */
    //#if defined(__MMI_LANG_NORWEGIAN__)
     //0x00E5,
     //0x00E6, 
     //0x00E1, 
     //0x00E0,  
     //0x00E4, 
    //#endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03b1,
     0x03b2,
     0x03ac,
     0x03b3,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'d', 'e', 'f', '3',
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_CROATIAN__) 
     0x0111,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E9,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00E8,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_DUTCH__) */ 
    //#if defined(__MMI_LANG_CROATIAN__)  
    // 0x0111,
    //#endif 
    #if defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_SLOVAK__)
     0x011b,
     0x010f,
     0x0119,
    #endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__)
     0x00EA,
    #endif 
    #if defined(__MMI_LANG_FRENCH__)
     0x00EB,
    #endif 
    //#if defined(__MMI_LANG_SLOVAK__)  
    // 0x011b,
   //  0x010f,
    // 0x0119,
    //#endif /* defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian start */
    //#if defined(__MMI_LANG_NORWEGIAN__)  
     //0x00E9, 
    // 0x00E8,
    //#endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03b4,
     0x03b5,
     0x03b6,
     0x03ad,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'g', 'h', 'i', '4',
    #if defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__)
     0x00EC,
    #endif /* defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__)
     0x00ED,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ROMANIAN__)
     0x00EE,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ROMANIAN__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_FRENCH__)
     0x00EF,
    #endif 
    #if defined(__MMI_LANG_TURKISH__)
     0x011F,
    #endif 
    #if defined(__MMI_LANG_TURKISH__)
     0x0131,
    #endif 
    #if defined(__MMI_LANG_GREEK__)
     0x03b7,
     0x03b8,
     0x03b9,
     0x03ae,
     0x03af,
     0x03ca,
     0x0390,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'j', 'k', 'l', '5',
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__)
     0x013a,
     0x013e,
     0x0142,
    #endif /* defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_GREEK__)
     0x03ba,
     0x03bb,
     0x03bc,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'m', 'n', 'o', '6',
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FRENCH__) 
     0x00F1,
    #endif 
    #if defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00F2,
    #endif /* defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00F3,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    //#if defined(__MMI_LANG_SPANISH__)  
    // 0x00F2,
    //#endif 
    #if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00F4,
    #endif /* defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x01A1,
    #endif 
    #if defined(__MMI_LANG_PORTUGUESE__)
     0x00F5,
    #endif 
    #if defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00F6,
    #endif /* defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_INDONESIAN__) || defined(__MMI_LANG_MALAY__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__)
     0x0153,
    #endif 
    //#if defined(__MMI_LANG_FRENCH__)   
    // 0x00F1,
    //#endif 
    #if defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVAK__) 
     0x0151,
    #endif 
    #if defined(__MMI_LANG_SLOVAK__)
     0x0144,
     0x0148,
    // 0x0151,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian start */
    #if defined(__MMI_LANG_NORWEGIAN__)
     0x00F8,
     //0x00F3,  
     //0x00F2,  
    // 0x00F4,   
     //0x00F6,  
    #endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03bd,
     0x03be,
     0x03bf,
     0x03cc,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'p', 'q', 'r', 's', '7',
    #if defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_NORWEGIAN__) 
     0x00DF,
    #endif /* defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__)
     0x015F,
    #endif /* defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__) 
     0x0161,
    #endif 
    //#if defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SWEDISH__)
    // 0x00DF,
    //#endif /* defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SWEDISH__) */ 
    #if defined(__MMI_LANG_SLOVAK__)
     0x015b,
     0x0155,
     0x0159,
    //0x0161,
    #endif /* defined(__MMI_LANG_SLOVAK__) */ 
     /* Norwegian start */
    //#if defined(__MMI_LANG_NORWEGIAN__)  
    // 0x00DF,
    //#endif 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03c0,
     0x03c1,
     0x03c3,
     0x03c2,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'t', 'u', 'v', '8',
    #if defined(__MMI_LANG_VIETNAMESE__)
     0x01B0,
    #endif 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__)
     0x00F9,
    #endif /* defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_DUTCH__) */ 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__)
     0x00FA,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_TURKISH__) 
     0x00FB,
    #endif 
    #if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_NORWEGIAN__)  
     0x00FC,
    #endif /* defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_DUTCH__) || defined(__MMI_LANG_SWEDISH__) || defined(__MMI_LANG_ROMANIAN__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    //#if defined(__MMI_LANG_TURKISH__)  
    // 0x00FB,
    //#endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__)
     0x016f,
     0x0165,
     0x0171,
    #endif /* defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
     /* Norwegian start */
    #if defined(__MMI_LANG_NORWEGIAN__)  
     //0x00FC,
    #if defined(__MMI_LANG_ROMANIAN__)
     0x0163,
    #endif 
    #endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
     //Norwegian end
    #if defined(__MMI_LANG_GREEK__)
     0x03c4,
     0x03c5,
     0x03c6,
     0x03cd,
     0x03cb,
     0x03b0,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
    {'w', 'x', 'y', 'z', '9',
    #if defined(__MMI_LANG_FRENCH__)
     0x00FF,
    #endif 
    #if defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) 
     0x017e,
    #endif 
    #if defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__)
     0x00FD,
    #endif /* defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_ROMANIAN__)
     0x0171,
    #endif 
    #if defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__)
     0x017a,
     0x017c,
     //0x017e,
    #endif /* defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_SLOVENIAN__) */ 
    #if defined(__MMI_LANG_GREEK__)
     0x03c7,
     0x03c8,
     0x03c9,
     0x03ce,
    #endif /* defined(__MMI_LANG_GREEK__) */ 
     '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
#if defined(__MMI_MULTITAP_SPANISH__)
const UI_character_type default_spanish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C1, 0x00C0, 0x00C7, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, 0x00C8, '\0'},
    {'G', 'H', 'I', '4', 0x00CD, 0x00CF, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D1, 0x00D3, 0x00D2, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', 0x00DA, 0x00DC, '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_spanish_lowercase_multitap_strings[10][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E1, 0x00E0, 0x00E7, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00E8, '\0'},
    {'g', 'h', 'i', '4', 0x00ED, 0x00EF, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F1, 0x00F3, 0x00F2, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', 0x00FA, 0x00FC, '8', '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
#if defined(__MMI_MULTITAP_DANISH__)
const UI_character_type default_danish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C1, 0x00C5, 0x00C6, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, 0x00C8, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D3, 0x00D6, 0x00D8, 0x00D2, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DA, 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', 0x00DD, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_danish_lowercase_multitap_strings[10][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E4, 0x00E5, 0x00E6, 0x00E1, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00E8, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F3, 0x00F6, 0x00F8, 0x00F2, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FA, 0x00FC, '\0'},
    {'w', 'x', 'y', 'z', '9', 0x00FD, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_DANISH__) */ 
#if defined(__MMI_MULTITAP_POLISH__)
const UI_character_type default_polish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C4, 0x00C1, 0x0104, 0x10C, 0x106, '\0'},
    {'D', 'E', 'F', '3', 0x010E, 0x00C9, 0x0114, 0x118, '\0'},
    {'G', 'H', 'I', '4', 0x00CD, '\0'},
    {'J', 'K', 'L', '5', 0x013D, 0x0139, 0x0141, '\0'},
    {'M', 'N', 'O', '6', 0x0143, 0x0147, 0x00D3, 0x00D6, 0x00D4, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x0154, 0x0158, 0x015A, 0x0160, 0x00DF, '\0'},
    {'T', 'U', 'V', '8', 0x0164, 0x016E, 0x00DA, 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x00DD, 0X00179, 0x017D, 0x017B, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_polish_lowercase_multitap_strings[10][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E1, 0x00E4, 0x0105, 0x010D, 0x107, '\0'},
    {'d', 'e', 'f', '3', 0x010F, 0x00E9, 0x0115, 0x0119, '\0'},
    {'g', 'h', 'i', '4', 0x00ED, '\0'},
    {'j', 'k', 'l', '5', 0x013A, 0x013E, 0x0142, '\0'},
    {'m', 'n', 'o', '6', 0x0144, 0x0148, 0x00F3, 0x00F4, 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', 0x0155, 0x00159, 0x015B, 0x0161, 0x00DF, '\0'},
    {'t', 'u', 'v', 0x0165, 0x016F, 0x00FA, 0x00FC, '8', '\0'},
    {'w', 'x', 'y', 'z', '9', 0x00FD, 0x017A, 0x017C, 0x017E, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_POLISH__) */ 
#if defined(__MMI_MULTITAP_FRENCH__)
const UI_character_type default_french_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C0, 0x00C2, 0x00C7, 0x00C6, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, 0x00C8, 0x00CA, 0x00CB, '\0'},
    {'G', 'H', 'I', '4', 0x00CE, 0x00CF, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D4, 0x0152, 0x00D1, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00D9, 0x00DB, '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x0178, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_french_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E0, 0x00E2, 0x00E7, 0x00E6, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00E8, 0x00EA, 0x00EB, '\0'},
    {'g', 'h', 'i', '4', 0x00EE, 0x00EF, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F4, 0x0153, 0x00F1, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', 0x00F9, 0x00FB, '\0'},
    {'w', 'x', 'y', 'z', '9', 0x00FF, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
#if defined(__MMI_MULTITAP_GERMAN__)
const UI_character_type default_german_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C4, 0x00C0, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_german_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E4, 0x00E0, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FC, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
#if defined(__MMI_MULTITAP_ITALIAN__)
const UI_character_type default_italian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C0, '\0'},
    {'D', 'E', 'F', '3', 0x00C8, 0x00C9, '\0'},
    {'G', 'H', 'I', '4', 0x00CC, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D2, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00D9, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_italian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E0, '\0'},
    {'d', 'e', 'f', '3', 0x00E8, 0x00E9, '\0'},
    {'g', 'h', 'i', '4', 0x00EC, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F2, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', 0x00F9, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
#if defined(__MMI_MULTITAP_RUSSIAN__)
const UI_character_type default_russian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {0x0410, 0x0411, 0x0412, 0x0413, '2', 'A', 'B', 'C', '\0'},
    {0x0414, 0x0415, 0x0401, 0x0416, 0x0417, '3', 'D', 'E', 'F', '\0'},
    {0x0418, 0x0419, 0x041a, 0x041b, '4', 'G', 'H', 'I', '\0'},
    {0x041c, 0x041d, 0x041e, 0x041f, '5', 'J', 'K', 'L', '\0'},
    {0x0420, 0x0421, 0x0422, 0x0423, '6', 'M', 'N', 'O', '\0'},
    {0x0424, 0x0425, 0x0426, 0x0427, '7', 'P', 'Q', 'R', 'S', '\0'},
    {0x0428, 0x0429, 0x042a, 0x042b, '8', 'T', 'U', 'V', '\0'},
    {0x042c, 0x042d, 0x042e, 0x042f, '9', 'W', 'X', 'Y', 'Z', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_russian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {0x0430, 0x0431, 0x0432, 0x0433, '2', 'a', 'b', 'c', '\0'},
    {0x0434, 0x0435, 0x0451, 0x0436, 0x0437, '3', 'd', 'e', 'f', '\0'},
    {0x0438, 0x0439, 0x043a, 0x043b, '4', 'g', 'h', 'i', '\0'},
    {0x043c, 0x043d, 0x043e, 0x043f, '5', 'j', 'k', 'l', '\0'},
    {0x0440, 0x0441, 0x0442, 0x0443, '6', 'm', 'n', 'o', '\0'},
    {0x0444, 0x0445, 0x0446, 0x0447, '7', 'p', 'q', 'r', 's', '\0'},
    {0x0448, 0x0449, 0x044a, 0x044b, '8', 't', 'u', 'v', '\0'},
    {0x044c, 0x044d, 0x044e, 0x044f, '9', 'w', 'x', 'y', 'z', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
#if defined(__MMI_MULTITAP_BULGARIAN__)
const UI_character_type default_bulgarian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', ';', '(', ')', '*', '1', '\0'},
    {0x0410, 0x0411, 0x0412, 0x0413, 0x0490, '2', '\0'},
    {0x0414, 0x0415, 0x0416, 0x0417, 0x0401, 0x0404, '3', '\0'},
    {0x0418, 0x0419, 0x041A, 0x041B, 0x0406, 0x0407, '4', '\0'},
    {0x041C, 0x041D, 0x041E, '5', '\0'},
    {0x041F, 0x0420, 0x0421, '6', '\0'},
    {0x0422, 0x0423, 0x0424, 0x0425, '7', '\0'},
    {0x0426, 0x0427, 0x0428, 0x0429, 0x042A, '8', '\0'},
    {0x042B, 0x042C, 0x042D, 0x042E, 0x042F, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_bulgarian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', ';', '(', ')', '*', '1', '\0'},
    {0x0430, 0x0431, 0x0432, 0x0433, 0x0491, '2', '\0'},
    {0x0434, 0x0435, 0x0436, 0x0437, 0x0451, 0x0454, '3', '\0'},
    {0x0438, 0x0439, 0x043A, 0x043B, 0x0456, 0x0457, '4', '\0'},
    {0x043C, 0x043D, 0x043E, '5', '\0'},
    {0x043F, 0x0440, 0x0441, '6', '\0'},
    {0x0442, 0x0443, 0x0444, 0x0445, '7', '\0'},
    {0x0446, 0x0447, 0x0448, 0x0449, 0x044A, '8', '\0'},
    {0x044B, 0x044C, 0x044D, 0x044E, 0x044F, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_BULGARIAN__) */  
#if defined(__MMI_MULTITAP_UKRAINIAN__)
const UI_character_type default_UKRAINIAN_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', ';', '(', ')', '*', '1', '\0'},
    {0x0410, 0x0411, 0x0412, 0x0413, 0x0403, '2', 'A', 'B', 'C', 0x0490,'\0'},
    {0x0414, 0x0415, 0x0401, 0x0416, 0x0417, 0x0402, 0x0404, 0x0405, '3', 'D', 'E', 'F', '\0'},
    {0x0418, 0x0419, 0x041A, 0x041B, 0x0406, 0x0407, 0x0408, 0x040C, 0x0409, '4', 'G', 'H','I', '\0'},
    {0x041C, 0x041D, 0x041E, 0x041f, 0x040A, '5', 'J', 'K', 'L', '\0'},
    {0x0420, 0x0421, 0x0422, 0x0423, 0x040B, 0x040E, '6', 'M', 'N', 'O', '\0'},
    {0x0424, 0x0425, 0x0426, 0x0427, 0x040F, '7', 'P', 'Q', 'R', 'S', '\0'},
    {0x0428, 0x0429, 0x042A, 0x042B, '8', 'T', 'U', 'V', '\0'},
    {0x042C, 0x042D, 0x042E, 0x042F, '9', 'W', 'X', 'Y', 'Z','\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_UKRAINIAN_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', ';', '(', ')', '*', '1', '\0'},
    {0x0430, 0x0431, 0x0432, 0x0433, 0x0453, '2', 'a', 'b', 'c', 0x0491, '\0'},
    {0x0434, 0x0435, 0x0451, 0x0436, 0x0437, 0x0452, 0x0454, 0x0455, '3', 'd', 'e', 'f','\0'},
    {0x0438, 0x0439, 0x043A, 0x043B, 0x0456, 0x0457, 0x0458, 0x045C, 0x0459, '4', 'g', 'h', 'i', '\0'},
    {0x043C, 0x043D, 0x043E, 0x043F, 0x045A, '5', 'j', 'k', 'l', '\0'},
    {0x0440, 0x0441, 0x0442, 0x0443, 0x045B, 0x045E, '6', 'm', 'n', 'o','\0'},
    {0x0444, 0x0445, 0x0446, 0x0447, 0x045F, '7', 'p', 'q', 'r', 's', '\0'},
    {0x0448, 0x0449, 0x044A, 0x044B, '8', 't', 'u', 'v','\0'},
    {0x044C, 0x044D, 0x044E, 0x044F, '9', 'w', 'x', 'y', 'z', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
#if defined(__MMI_MULTITAP_TURKISH__)
const UI_character_type default_turkish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C7, 0x00C2, '\0'},
    {'D', 'E', 'F', '3', '\0'},
    {'G', 'H', 'I', '4', 0x011E, 0x0130, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x015E, '\0'},
    {'T', 'U', 'V', '8', 0x00DC, 0x00DB, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_turkish_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    /* MTK end */
    {'a', 'b', 'c', '2', 0x00E7, 0x00E2, '\0'},
    {'d', 'e', 'f', '3', '\0'},
    {'g', 'h', 'i', '4', 0x011F, 0x0131, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', 0x015F, '\0'},
    {'t', 'u', 'v', '8', 0x00FC, 0x00FB, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
#if defined(__MMI_MULTITAP_PORTUGUESE__)
const UI_character_type default_portuguese_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C1, 0x00C0, 0x00C2, 0x00C3, 0x00C7, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, 0x00CA, '\0'},
    {'G', 'H', 'I', '4', 0x00CD, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D3, 0x00D4, 0x00D5, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DA, 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_portuguese_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E1, 0x00E0, 0x00E2, 0x00E3, 0x00E7, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00EA, '\0'},
    {'g', 'h', 'i', '4', 0x00ED, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F3, 0x00F4, 0x00F5, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', 0x00FA, 0x00FC, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
#if defined(__MMI_MULTITAP_INDONESIAN__)
const UI_character_type default_indonesian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C6, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D1, 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_indonesian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E0, 0x00E6, 0x00E7, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00E8, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F1, 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 

#if defined(__MMI_MULTITAP_CZECH__)
const UI_character_type default_czech_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},

    {'A', 'B', 'C', 0x00C1, 0x010C, 0x00C4, 0x0104, 0x0106, '2', '\0'},
    {'D', 'E', 'F', 0x010E, 0x00C9, 0x011A, 0x0118, '3', '\0'},
    {'G', 'H', 'I', 0x00CD, '4', '\0'},
    {'J', 'K', 'L', 0x0139, 0x013D, 0x0141, '5', '\0'},
    {'M', 'N', 'O', 0x0147, 0x00D3, 0x00D4, 0x0143, 0x00D6, '6', '\0'},
    {'P', 'Q', 'R', 'S', 0x0158, 0x0160, 0x0154, 0x015A, '7', '\0'},
    {'T', 'U', 'V', 0x0164, 0x00DA, 0x016E, 0x00DC, '8', '\0'},
    {'W', 'X', 'Y', 'Z', 0x00DD, 0x017D, 0x0179, 0x017B, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_czech_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},

    {'a', 'b', 'c', 0x00E1, 0x010D, 0x00E4, 0x0105, 0x0107, '2', '\0'},
    {'d', 'e', 'f', 0x010F, 0x00E9, 0x011B, 0x0119, '3', '\0'},
    {'g', 'h', 'i', 0x00ED, '4', '\0'},
    {'j', 'k', 'l', 0x013A, 0x013E, 0x0142, '5', '\0'},
    {'m', 'n', 'o', 0x0148, 0x00F3, 0x00F4, 0x0144, 0x00F6, '6', '\0'},
    {'p', 'q', 'r', 's', 0x0159, 0x0161, 0x0155, 0x015B, 0x00DF, '7', '\0'},
    {'t', 'u', 'v', 0x0165, 0x00FA, 0x016F, 0x00FC, '8', '\0'},
    {'w', 'x', 'y', 'z', 0x00FD, 0x017E, 0x017A, 0x017C, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_CZECH__) */ 


#if defined(__MMI_MULTITAP_MALAY__)
const UI_character_type default_malay_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C6, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D1, 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_malay_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E0, 0x00E6, 0x00E7, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, 0x00E8, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F1, 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_MALAY__) */ 
#if defined(__MMI_MULTITAP_VIETNAMESE__)
const UI_character_type default_vietnamese_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {
     0x0300,
     0x0309,
     0x0303,
     0x0301,
     0x0323,
     '.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x0102, 0x00C2, '\0'},
    {'D', 'E', 'F', '3', 0x0110, 0x00CA, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D4, 0x01A0, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x01AF, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_vietnamese_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {
     0x0300,
     0x0309,
     0x0303,
     0x0301,
     0x0323,
     '.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x0103, 0x00E2, '\0'},
    {'d', 'e', 'f', '3', 0x0111, 0x00EA, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F4, 0x01A1, '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', 0x01B0, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
#if defined(__MMI_MULTITAP_FINNISH__)
const UI_character_type default_finnish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C4, 0x00C5, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_finnish_lowercase_multitap_strings[10][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E4, 0x00E5, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FC, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
#if defined(__MMI_MULTITAP_HUNGARIAN__)
const UI_character_type default_hungarian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},
    {'A', 'B', 'C', 0x00C1, 0x00C4, 0x0102, 0x00C2, 0x0104, 0x0106, 0x010C, '2', '\0'},
    {'D', 'E', 'F', 0x00C9, 0x00CB, 0x011A, 0x0118, 0x010E, 0x0110, '3', '\0'},
    {'G', 'H', 'I', 0x00CD, 0x00CE, '4', '\0'},
    {'J', 'K', 'L', 0x0139, 0x013D, 0x0141, '5', '\0'},
    {'M', 'N', 'O', 0x00D3, 0x00D6, 0x0150, 0x00D4, 0x0143, 0x0147, '6', '\0'},
    {'P', 'Q', 'R', 'S', 0x0154, 0x0158, 0x015A, 0x0160, 0x015E, '7', '\0'},
    {'T', 'U', 'V', 0x00DA, 0x00DC, 0x0170, 0x0164, 0x0162, 0x016E, '8', '\0'},
    {'W', 'X', 'Y', 'Z', 0x00DD, 0x0179, 0x017D, 0x017B, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_hungarian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},
    {'a', 'b', 'c', 0x00E1, 0x00E4, 0x0103, 0x00E2, 0x0105, 0x0107, 0x010D, '2', '\0'},
    {'d', 'e', 'f', 0x00E9, 0x00EB, 0x011B, 0x0119, 0x010F, 0x0111, '3', '\0'},
    {'g', 'h', 'i', 0x00ED, 0x00EE, '4', '\0'},
    {'j', 'k', 'l', 0x013A, 0x013E, 0x0142, '5', '\0'},
    {'m', 'n', 'o', 0x00F3, 0x00F6, 0x0151, 0x00F4, 0x0144, 0x0148, '6', '\0'},
    {'p', 'q', 'r', 's', 0x0155, 0x0159, 0x015B, 0x0161, 0x015F, 0x00DF, '7', '\0'},
    {'t', 'u', 'v', 0x00FA, 0x00FC, 0x0171, 0x0165, 0x0163, 0x016F, '8', '\0'},
    {'w', 'x', 'y', 'z', 0x00FD, 0x017A, 0x017E, 0x017C, '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 

#if defined(__MMI_MULTITAP_SLOVAK__)
const UI_character_type default_slovak_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'A', 'B', 'C', '2', 0x00C4, 0x00C1, 0x0104, 0x010c, 0x0106, '\0'},
    {'D', 'E', 'F', '3', 0x010e, 0x00C9, 0x011a, 0x0118, '\0'},
    {'G', 'H', 'I', '4', 0x00CD, '\0'},
    {'J', 'K', 'L', '5', 0x0139, 0x013d, 0x0141, '\0'},
    {'M', 'N', 'O', '6', 0x0143, 0x0147, 0x00D3, 0x00D4, 0x00D6, 0x0150, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x0154, 0x0158, 0x015a, 0x0160, '\0'},
    {'T', 'U', 'V', '8', 0x0164, 0x00DA, 0x00DC, 0x016e, 0x0170, '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x00DD, 0x017b, 0x017d, 0x0179, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_slovak_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'a', 'b', 'c', '2', 0x00E4, 0x00E1, 0x0105, 0x010d, 0x0107, '\0'},
    {'d', 'e', 'f', '3', 0x010f, 0x00E9, 0x011b, 0x0119, '\0'},
    {'g', 'h', 'i', '4', 0x00ED, '\0'},
    {'j', 'k', 'l', '5', 0x013a, 0x013e, 0x0142, '\0'},
    {'m', 'n', 'o', '6', 0x0144, 0x0148, 0x00F3, 0x00F4, 0x00F6, 0x0151, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, 0x0155, 0x0159, 0x015b, 0x0161, '\0'},
    {'t', 'u', 'v', '8', 0x0165, 0x00FA, 0x00FC, 0x016f, 0x0171, '\0'},
    {'w', 'x', 'y', 'z', '9', 0x00FD, 0x017a, 0x017c, 0x017e, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
#if defined(__MMI_MULTITAP_DUTCH__)
const UI_character_type default_dutch_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},
    {'A', 'B', 'C', '2', 0x00C7, 0x00C4, 0x00C1, 0x00C0, 0x00C2, '\0'},
    {'D', 'E', 'F', '3', 0x00CB, 0x00C9, 0x00C8, 0x00CA, '\0'},
    {'G', 'H', 'I', '4', 0x00CF, 0x00CD, 0x00CC, 0x00CE, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D6, 0x00D3, 0x00D2, 0x00D4, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DC, 0x00DA, 0x00DB, 0x00D9, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_dutch_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},
    {'a', 'b', 'c', '2', 0x00E7, 0x00E4, 0x00E1, 0x00E0, 0x00E2, '\0'},
    {'d', 'e', 'f', '3', 0x00EB, 0x00E9, 0x00E8, 0x00EA, '\0'},
    {'g', 'h', 'i', '4', 0x00EF, 0x00ED, 0x00EC, 0x00EE, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F6, 0x00F3, 0x00F2, 0x00F4, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FC, 0x00FA, 0x00FB, 0x00F9, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
#if defined(__MMI_MULTITAP_ARABIC__)
const UI_character_type default_arabic_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {0x002E, 0x061F, 0x060C, 0x0021, 0x061B, 0x0022, 0x0040, 0x003A, 0x0031, 0x003B, 0x0028, 0x0029, 0x002A, 0x002D,
     '\0'},
    {0x062C, 0x062D, 0x062E, 0x0032, '\0'},
    {0x0627, 0x0623, 0x0625, 0x0622, 0x0628, 0x062A, 0x062B, 0x0033, '\0'},
    {0x0637, 0x0638, 0x0639, 0x063A, 0x0034, '\0'},
    {0x0633, 0x0634, 0x0635, 0x0636, 0x0035, '\0'},
    {0x062F, 0x0630, 0x0631, 0x0632, 0x0036, '\0'},
    {0x0648, 0x0624, 0x0649, 0x064A, 0x0626, 0x0621, 0x0037, '\0'},
    {0x0645, 0x0646, 0x0647, 0x0629, 0x0038, '\0'},
    {0x0641, 0x0642, 0x0643, 0x0644, 0x0039, '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
/* PMT START PERSIAN */
#if defined(__MMI_MULTITAP_PERSIAN__)
const UI_character_type default_persian_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {0x002E, 0x061F, 0x060C, 0x0021, 0x061B, 0x0022, 0x0040, 0x003A, 0x0031, 0x003B, 0x0028, 0x0029, 0x002A, 0x002D,
     '\0'},
    {0x062C, 0x062D, 0x062E, 0x0686, 0x0032, '\0'},
    {0x0627, 0x0623, 0x0625, 0x0622, 0x0628, 0x062A, 0x062B, 0x067E, 0x0033, '\0'},
    {0x0637, 0x0638, 0x0639, 0x063A, 0x0034, '\0'},
    {0x0633, 0x0634, 0x0635, 0x0636, 0x0035, '\0'},
    {0x062F, 0x0630, 0x0631, 0x0632, 0x0698, 0x0036, '\0'},
    {0x0648, 0x0624, 0x0649, 0x064A, 0x0626, 0x0621, 0x06CC, 0x0037, '\0'},
    {0x0645, 0x0646, 0x0647, 0x0629, 0x0038, '\0'},
    {0x0641, 0x0642, 0x0643, 0x0644, 0x06A9, 0x06AF, 0x0039, '\0'},
 #if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
 #else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
 #endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
#if 0
/* under construction !*/
#if defined(__MMI_MULTITAP_URDU__)
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
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/* under construction !*/
#endif /*0*/
/* NEW URDU KEY MAPPING START */
#if defined(__MMI_MULTITAP_URDU__)
/* PMT START ZI */
#if defined (__MMI_ZI_URDU__)
const UI_character_type default_urdu_multitap_strings[MAX_MULTITAPS][32]=
{
    {' ', 0x06F0, '0', '\0'},	/* Key 0 */
    {0x002E, 0x061F, 0x003A, 0x061B, 0x060C, 0x0021, 0x002D, 0x0040, 0x06F1, 0x0031, '\0'},	/* Key 1 */
    {0x062C, 0x0686, 0x062D, 0x062E, 0x06F2, 0x0032, '\0'},	/* Key 2 */
    {0x0627, 0x0622, 0x0624, 0x0626, 0x06d3, 0x0628, 0x067E, 0x062A,  0x0679, 0x062B, 0x06F3, 0x0033, '\0'},	/* Key 3 */
    {0x0637, 0x0638, 0x0639, 0x063A, 0x06F4, 0x0034, '\0'},	/* Key 4 */
    {0x0633, 0x0634, 0x0635, 0x0636, 0x06F5, 0x0035, '\0'},	/* Key 5 */
    {0x062F, 0x0688, 0x0630, 0x0631, 0x0691, 0x0632, 0x0698, 0x06F6, 0x0036, '\0'},	/* Key 6 */
    {0x06BE, 0x06C1, 0x06C2, 0x06CC, 0x06D2, 0x0621, 0x06C3, 0x06F7, 0x0037, '\0'},	/* Key 7 */
    {0x0645, 0x0646, 0x06BA, 0x0648, 0x06f8, 0x0038, '\0'},	/* Key 8 */
    {0x0641, 0x0642, 0x06A9, 0x06AF, 0x0644, 0x06F9, 0x0039, '\0'},	/* Key 9 */
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else
	   {'\0'},
	   {'\0'},
#endif
};
#else
const UI_character_type default_urdu_multitap_strings[MAX_MULTITAPS][32]=
{
        {' ', '0', '\0'},//key0
    {0x002E, 0x061F, 0x060C, 0x0021, 0x061B, 0x0022, 0x0040, 0x003A, 0x0031, 0x003B, 0x0028, 0x0029, 0x002A, 0x002D,
     '\0'},//key1
    {0x062C, 0x0686, 0x062D, 0x062E, 0x062F, 0x0688, 0x0630, 0x0032, '\0'},//key2
    {0x0627,0x0622, 0x0628, 0x067E, 0x062A, 0x0679, 0x062B, 0x0033, '\0'},//key3
    {0x063A, 0x0641, 0x0642, 0x06A9,0x06AF, 0x0034, '\0'},//key4
    {0x0636, 0x0637, 0x0638, 0x0639, 0x0035, '\0'},//key5
    {0x0631, 0x0691, 0x0632, 0x0698, 0x0633, 0x0634, 0x0635,  0x0036, '\0'},//key6
    {0x0621, 0x06CC, 0x0626, 0x06D2, 0x06D3, 0x0037, '\0'},//key7
    {0x06C2, 0x06C1, 0x06BE, 0x06C3, 0x0038, '\0'},//key8
    {0x0644, 0x0645, 0x0646, 0x06BA, 0x0648, 0x0624, 0x0039, '\0'},//key9
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else
	   {'\0'},
	   {'\0'},
#endif
};
#endif
#endif

/* NEW URDU KEY MAPPING END */
#if defined(__MMI_MULTITAP_NORWEGIAN__)
const UI_character_type default_norwegian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ')', '(', ';', '*', '\0'},

    {'A', 'B', 'C', 0x00C5, 0x00C6, 0x00C1, 0x00C0, 0x00C4, '2', '\0'},
    {'D', 'E', 'F', 0x00C9, 0x00C8, '3', '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', 0x00D8, 0x00D3, 0x00D2, 0x00D4, 0x00D6, '6', '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', 0x00DC, '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_norwegian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{

    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ')', '(', ';', '*', '\0'},

    {'a', 'b', 'c', 0x00E5, 0x00E6, 0x00E1, 0x00E0, 0x00E4, '2', '\0'},
    {'d', 'e', 'f', 0x00E9, 0x00E8, '3', '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', 0x00F8, 0x00F3, 0x00F2, 0x00F4, 0x00F6, '6', '\0'},
    {'p', 'q', 'r', 's', 0x00DF, '7', '\0'},
    {'t', 'u', 'v', 0x00FC, '8', '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
//Norwegian end
#if defined(__MMI_MULTITAP_SWEDISH__)
const UI_character_type default_swedish_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', 0x00C4, 0x00C5, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D6, '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', 0x00DC, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_swedish_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', 0x00E4, 0x00E5, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F6, '\0'},
    {'p', 'q', 'r', 's', '7', 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FC, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
#if defined(__MMI_MULTITAP_CROATIAN__)
const UI_character_type default_croatian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'A', 'B', 'C', '2', 0x010c, 0x0106, '\0'},
    {'D', 'E', 'F', '3', 0x0110, '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x0160, '\0'},
    {'T', 'U', 'V', '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x017d, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_croatian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'a', 'b', 'c', '2', 0x010d, 0x0107, '\0'},
    {'d', 'e', 'f', '3', 0x0111, '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', '\0'},
    {'p', 'q', 'r', 's', '7', 0x0161, '\0'},
    {'t', 'u', 'v', '8', '\0'},
    {'w', 'x', 'y', 'z', '9', 0x017e, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
#if defined(__MMI_MULTITAP_ROMANIAN__)
const UI_character_type default_romanian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'A', 'B', 'C', '2', 0x0102, 0x00C2, 0x00C1, 0x00C4, '\0'},
    {'D', 'E', 'F', '3', 0x00C9, '\0'},
    {'G', 'H', 'I', '4', 0x00CE, 0x00CD, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D3, 0x00D6, 0x0150, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x015E, '\0'},
    {'T', 'U', 'V', '8', 0x0162, 0x00DA, 0x00DC, 0x0170, '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_romanian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    //{' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'},
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ')', '(', ';', '*', '\0'},
    {'a', 'b', 'c', '2', 0x0103, 0x00E2, 0x00E1, 0x00E4, '\0'},
    {'d', 'e', 'f', '3', 0x00E9, '\0'},
    {'g', 'h', 'i', '4', 0x00EE, 0x00ED, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F3, 0x00F6, 0x0151, '\0'},
    {'p', 'q', 'r', 's', '7', 0x015F, 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x0163, 0x00FA, 0x00FC, 0x0171, '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
#if defined(__MMI_MULTITAP_SLOVENIAN__)
const UI_character_type default_slovenian_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ')', '(', ';', '*', '\0'},
    {'A', 'B', 'C', '2', 0x010C, 0x0106, 0x00C1, 0x00C4, '\0'},
    {'D', 'E', 'F', '3', 0x0110, 0x00C9, '\0'},
    {'G', 'H', 'I', '4', 0x00CD, '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', 0x00D3, 0x00D6, 0x0150, 0x00D4, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x0160, '\0'},
    {'T', 'U', 'V', '8', 0x00DA, 0x00DC, 0x0170, '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x017D, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_slovenian_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ')', '(', ';', '*', '\0'},
    {'a', 'b', 'c', '2', 0x010D, 0x0107, 0x00E1, 0x00E4, '\0'},
    {'d', 'e', 'f', '3', 0x0111, 0x00E9, '\0'},
    {'g', 'h', 'i', '4', 0x00ED, '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', 0x00F3, 0x00F6, 0x0151, 0x00F4, '\0'},
    {'p', 'q', 'r', 's', '7', 0x0161, 0x00DF, '\0'},
    {'t', 'u', 'v', '8', 0x00FA, 0x00FC, 0x0171, '\0'},
    {'w', 'x', 'y', 'z', '9', 0x017E, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
#if defined(__MMI_MULTITAP_GREEK__)
const UI_character_type default_greek_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ';', '(', ')', '*', '\0'},
    {'A', 'B', 'C', '2', 0x03b1, 0x03b2, 0x03ac, 0x03b3, '\0'},
    {'D', 'E', 'F', '3', 0x03b4, 0x03b5, 0x03b6, 0x03ad, '\0'},
    {'G', 'H', 'I', '4', 0x03b7, 0x03b8, 0x03b9, 0x03ae, 0x03af, 0x03ca, 0x0390, '\0'},
    {'J', 'K', 'L', '5', 0x03ba, 0x03bb, 0x03bc, '\0'},
    {'M', 'N', 'O', '6', 0x03bd, 0x03be, 0x03bf, 0x03cc, '\0'},
    {'P', 'Q', 'R', 'S', '7', 0x03c0, 0x03c1, 0x03c3, 0x03c2, '\0'},
    {'T', 'U', 'V', '8', 0x03c4, 0x03c5, 0x03c6, 0x03cd, 0x03cb, 0x03b0, '\0'},
    {'W', 'X', 'Y', 'Z', '9', 0x03c7, 0x03c8, 0x03c9, 0x03ce, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type default_greek_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','0','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    //{'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', ';', '(', ')', '*', '\0'},
    {'a', 'b', 'c', '2', 0x03b1, 0x03b2, 0x03ac, 0x03b3, '\0'},
    {'d', 'e', 'f', '3', 0x03b4, 0x03b5, 0x03b6, 0x03ad, '\0'},
    {'g', 'h', 'i', '4', 0x03b7, 0x03b8, 0x03b9, 0x03ae, 0x03af, 0x03ca, 0x0390, '\0'},
    {'j', 'k', 'l', '5', 0x03ba, 0x03bb, 0x03bc, '\0'},
    {'m', 'n', 'o', '6', 0x03bd, 0x03be, 0x03bf, 0x03cc, '\0'},
    {'p', 'q', 'r', 's', '7', 0x03c0, 0x03c1, 0x03c3, 0x03c2, '\0'},
    {'t', 'u', 'v', '8', 0x03c4, 0x03c5, 0x03c6, 0x03cd, 0x03cb, 0x03b0, '\0'},
    {'w', 'x', 'y', 'z', '9', 0x03c7, 0x03c8, 0x03c9, 0x03ce, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_GREEK__) */ 
#if defined(__MMI_MULTITAP_HEBREW__)
const UI_character_type default_hebrew_multitap_strings[MAX_MULTITAPS][32] = 
{
    {' ', '0', '\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '1', ';', '(', ')', '*', '\0'},
    //      {0x002E, 0x002c, 0x002d, 0x003f, 0x0021, 0x0027, 0x0022, 0x003A, 0x0031,   '\0'},
    {0x05d3, 0x05d4, 0x05d5, 0x0032, '\0'},
    {0x05d0, 0x05d1, 0x05d2, 0x0033, '\0'},
    {0x05de, 0x05dd, 0x05e0, 0x05df, 0x0034, '\0'},
    {0x05d9, 0x05db, 0x05da, 0x05dc, 0x0035, '\0'},
    {0x05d6, 0x05d7, 0x05d8, 0x0036, '\0'},
    {0x05e8, 0x05e9, 0x05ea, 0x0037, '\0'},
    {0x05e6, 0x05e5, 0x05e7, 0x0038, '\0'},
    {0x05e1, 0x05e2, 0x05e4, 0x05e3, 0x0039, '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
#endif /* defined(__MMI_MULTITAP_HEBREW__) */ 

/* MTK end */

const UI_character_type numberless_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '\0'},
    {'A', 'B', 'C', '\0'},
    {'D', 'E', 'F', '\0'},
    {'G', 'H', 'I', '\0'},
    {'J', 'K', 'L', '\0'},
    {'M', 'N', 'O', '\0'},
    {'P', 'Q', 'R', 'S', '\0'},
    {'T', 'U', 'V', '\0'},
    {'W', 'X', 'Y', 'Z', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type numberless_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '\0'},
    {'a', 'b', 'c', '\0'},
    {'d', 'e', 'f', '\0'},
    {'g', 'h', 'i', '\0'},
    {'j', 'k', 'l', '\0'},
    {'m', 'n', 'o', '\0'},
    {'p', 'q', 'r', 's', '\0'},
    {'t', 'u', 'v', '\0'},
    {'w', 'x', 'y', 'z', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

/* MTK Terry for English Only */
const UI_character_type english_only_uppercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'A', 'B', 'C', '2', '\0'},
    {'D', 'E', 'F', '3', '\0'},
    {'G', 'H', 'I', '4', '\0'},
    {'J', 'K', 'L', '5', '\0'},
    {'M', 'N', 'O', '6', '\0'},
    {'P', 'Q', 'R', 'S', '7', '\0'},
    {'T', 'U', 'V', '8', '\0'},
    {'W', 'X', 'Y', 'Z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};

const UI_character_type english_only_lowercase_multitap_strings[MAX_MULTITAPS][32] = 
{
    /* {' ','.',',','+','*','-','=',':',';','\'','\"','\0'}, */
    {' ', '0', '\0'},
    // {'1','@','!','?','#','$','/','_'/*MTK*/,'\0'},
    {'.', ',', '-', '?', '!', '\'', '@', ':', '#', '$', '/', '_', '1', '\0'},
    {'a', 'b', 'c', '2', '\0'},
    {'d', 'e', 'f', '3', '\0'},
    {'g', 'h', 'i', '4', '\0'},
    {'j', 'k', 'l', '5', '\0'},
    {'m', 'n', 'o', '6', '\0'},
    {'p', 'q', 'r', 's', '7', '\0'},
    {'t', 'u', 'v', '8', '\0'},
    {'w', 'x', 'y', 'z', '9', '\0'},
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {'\0'},
    {'\0'},
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
};
multitap_input MMI_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_lowercase_multitaps[MAX_MULTITAPS];

#if defined (__MMI_MULTITAP_HINDI__) 
multitap_input MMI_hindi_multitaps[MAX_MULTITAPS];
#endif
#if defined (__MMI_MULTITAP_MARATHI__) 
multitap_input MMI_marathi_multitaps[MAX_MULTITAPS];
#endif 

#if defined (__MMI_MULTITAP_TAMIL__) 
multitap_input MMI_tamil_multitaps[MAX_MULTITAPS];
#endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */
#if defined (__MMI_MULTITAP_BENGALI__) 
multitap_input MMI_bengali_multitaps[MAX_MULTITAPS];
#endif 

#if defined (__MMI_MULTITAP_PUNJABI__) 
multitap_input MMI_punjabi_multitaps[MAX_MULTITAPS];
#endif
#if defined (__MMI_MULTITAP_TELUGU__) 
multitap_input MMI_telugu_multitaps[MAX_MULTITAPS];
#endif
multitap_input MMI_bpmf_multitaps[MAX_MULTITAPS];

#if defined (__MMI_MULTITAP_THAI__)
multitap_input MMI_thai_multitaps[MAX_MULTITAPS_THAI];
#endif 

#if defined(__MMI_MULTITAP_SPANISH__)
multitap_input MMI_spanish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_spanish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
#if defined(__MMI_MULTITAP_DANISH__)
multitap_input MMI_danish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_danish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_DANISH__) */ 
#if defined(__MMI_MULTITAP_POLISH__)
multitap_input MMI_polish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_polish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_POLISH__) */ 
#if defined(__MMI_MULTITAP_FRENCH__)
multitap_input MMI_french_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_french_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
#if defined(__MMI_MULTITAP_GERMAN__)
multitap_input MMI_german_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_german_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
#if defined(__MMI_MULTITAP_ITALIAN__)
multitap_input MMI_italian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_italian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
#if defined(__MMI_MULTITAP_RUSSIAN__)
multitap_input MMI_russian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_russian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
#if defined(__MMI_MULTITAP_BULGARIAN__)
multitap_input MMI_bulgarian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_bulgarian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
#if defined(__MMI_MULTITAP_UKRAINIAN__)
multitap_input MMI_UKRAINIAN_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_UKRAINIAN_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
#if defined(__MMI_MULTITAP_TURKISH__)
multitap_input MMI_turkish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_turkish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
#if defined(__MMI_MULTITAP_PORTUGUESE__)
multitap_input MMI_portuguese_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_portuguese_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
#if defined(__MMI_MULTITAP_INDONESIAN__)
multitap_input MMI_indonesian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_indonesian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
#if defined(__MMI_MULTITAP_CZECH__)
multitap_input MMI_czech_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_czech_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_CZECH__) */ 
#if defined(__MMI_MULTITAP_MALAY__)
multitap_input MMI_malay_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_malay_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_MALAY__) */ 
#if defined(__MMI_MULTITAP_VIETNAMESE__)
multitap_input MMI_vietnamese_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_vietnamese_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
#if defined(__MMI_MULTITAP_FINNISH__)
multitap_input MMI_finnish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_finnish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
#if defined(__MMI_MULTITAP_HUNGARIAN__)
multitap_input MMI_hungarian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_hungarian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
#if defined(__MMI_MULTITAP_SWEDISH__)
multitap_input MMI_swedish_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_swedish_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 

#if defined(__MMI_MULTITAP_HEBREW__)
multitap_input MMI_hebrew_multitaps[MAX_MULTITAPS];
#endif 
#if defined(__MMI_MULTITAP_SLOVAK__)
multitap_input MMI_slovak_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_slovak_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
#if defined(__MMI_MULTITAP_DUTCH__)
multitap_input MMI_dutch_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_dutch_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
/* Norwegian start */
#if defined(__MMI_MULTITAP_NORWEGIAN__)
multitap_input MMI_norwegian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_norwegian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
/* Norwegian end */
#if defined(__MMI_MULTITAP_ARABIC__)
multitap_input MMI_arabic_multitaps[MAX_MULTITAPS];
#endif 
/* PMT START PERSIAN */
#if defined(__MMI_MULTITAP_PERSIAN__)
multitap_input MMI_persian_multitaps[MAX_MULTITAPS];
#endif 
//PMT END PERSIAN
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
multitap_input MMI_urdu_multitaps[MAX_MULTITAPS];
#endif
//PMT END URDU
#if defined(__MMI_MULTITAP_CROATIAN__)
multitap_input MMI_croatian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_croatian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
#if defined(__MMI_MULTITAP_ROMANIAN__)
multitap_input MMI_romanian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_romanian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
#if defined(__MMI_MULTITAP_SLOVENIAN__)
multitap_input MMI_slovenian_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_slovenian_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
#if defined(__MMI_MULTITAP_GREEK__)
multitap_input MMI_greek_uppercase_multitaps[MAX_MULTITAPS];
multitap_input MMI_greek_lowercase_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_MULTITAP_GREEK__) */ 
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
multitap_input MMI_uppercase_numberless_multitaps[MAX_MULTITAPS];
multitap_input MMI_lowercase_numberless_multitaps[MAX_MULTITAPS];
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

U8 MMI_current_multitap_mode = 0;

//PMT dara added for Multitap thai 
//W05.36 Fix Vietnamese Tone Input Issue
mmi_editor_inoutbox_enum MMI_current_input_box_type = EDITOR_NONE_INPUT_BOX;


S32 MMI_active_multitap = -1;
S32 MMI_timer_multitap = -1;
MMI_BOOL MMI_EXIT_WITH_MULTITAP_STATE = MMI_FALSE;

void (*hide_multitap) (void);

/* W05.36 Fix Vietnamese Tone Input Issue */


/*****************************************************************************
 * FUNCTION
 *  set_current_input_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_box_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_input_box_type(mmi_editor_inoutbox_enum input_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_input_box_type = input_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  get_multitap_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL get_multitap_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            if (UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP & MMI_multiline_inputbox.flags)
            {
                return MMI_TRUE;
            }
        case EDITOR_EMS_INPUT_BOX:
            if (UI_EMS_INPUT_BOX_STATE_MULTITAP & MMI_EMS_inputbox.flags)
            {
                return MMI_TRUE;
            }
        case EDITOR_SINGLE_LINE_INPU_BOX:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_singleline_inputbox.flags)
            {
                return MMI_TRUE;
            }
        case EDITOR_INLINE_TEXT:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_inline_singleline_inputbox.flags)
            {
                return MMI_TRUE;
            }
            break;
    }
    return MMI_FALSE;
}

#ifdef __MMI_LANG_VIETNAMESE__


/*****************************************************************************
 * FUNCTION
 *  get_viet_multitap_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type *get_viet_multitap_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type previous_char = 0;

    /* W05.37 Fix Vietnamese Tone Issue Side effect */
    U8 test_input_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    switch (MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            previous_char = gui_multi_line_current_character(&MMI_multiline_inputbox);
            break;
        case EDITOR_EMS_INPUT_BOX:
            previous_char = gui_EMS_current_character(&MMI_EMS_inputbox);
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
            previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
            break;
        case EDITOR_INLINE_TEXT:
            previous_char = gui_single_line_current_character(&MMI_inline_singleline_inputbox);
            break;
    }
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    {
        return (UI_character_type*) default_uppercase_multitap_strings[MMI_VIET_TONE_KEY];
    }
}
#endif /* __MMI_LANG_VIETNAMESE__ */ 


/*****************************************************************************
 * FUNCTION
 *  show_multitap
 * DESCRIPTION
 *  Displays the active multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;

    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    U8 max_multitaps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_THAI ||
        MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_THAI)
    {
        max_multitaps = MAX_MULTITAPS_THAI;
    }
    else
    {
        max_multitaps = MAX_MULTITAPS;
    }
#else /* defined(__MMI_MULTITAP_THAI__) */ 
    U8 max_multitaps = MAX_MULTITAPS;
#endif /* defined(__MMI_MULTITAP_THAI__) */ 
    if (MMI_active_multitap >= 0 && MMI_active_multitap < max_multitaps)
    {
        ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, MMI_active_multitap);
        if (ami != NULL)
        {
            gui_show_multitap_input(ami);
        }
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(ami->x, ami->y, (ami->x + ami->width /* +1 */ ), (ami->y + ami->height /* +1 */ ));
#endif 

}

#ifdef __MMI_TOUCH_SCREEN__

/* no output event because multitap_input has its own callback function */


/*****************************************************************************
 * FUNCTION
 *  wgui_multitap_translate_and_handle_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  pen_event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL wgui_multitap_translate_and_handle_pen_event(S32 x, S32 y, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;
    S32 index;
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_active_multitap >= 0 && MMI_active_multitap < MAX_MULTITAPS)
    {
        if (MMI_current_multitap_mode == 0)
        {
            ami = &MMI_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == 1)
        {
            ami = &MMI_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_BPMF)
        {
            ami = &MMI_bpmf_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_PINYIN)
        {
            ami = &MMI_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_ABC)
        {
            ami = &MMI_lowercase_multitaps[MMI_active_multitap];
        }
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC)
        {
            ami = &MMI_uppercase_numberless_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC)
        {
            ami = &MMI_lowercase_numberless_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

        /* PMT dara added for Multitap thai */
    #if defined (__MMI_MULTITAP_THAI__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_THAI)
        {
            ami = &MMI_thai_multitaps[MMI_active_multitap];
        }
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 

    #if defined(__MMI_MULTITAP_SPANISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_SPANISH)
        {
            ami = &MMI_spanish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_SPANISH)
        {
            ami = &MMI_spanish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_SPANISH)
        {
            ami = &MMI_spanish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_DANISH)
        {
            ami = &MMI_danish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_DANISH)
        {
            ami = &MMI_danish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_DANISH)
        {
            ami = &MMI_danish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_POLISH)
        {
            ami = &MMI_polish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_POLISH)
        {
            ami = &MMI_polish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_POLISH)
        {
            ami = &MMI_polish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_FRENCH)
        {
            ami = &MMI_french_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_FRENCH)
        {
            ami = &MMI_french_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_FRENCH)
        {
            ami = &MMI_french_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_GERMAN)
        {
            ami = &MMI_german_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_GERMAN)
        {
            ami = &MMI_german_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_GERMAN)
        {
            ami = &MMI_german_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN)
        {
            ami = &MMI_italian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN)
        {
            ami = &MMI_italian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_ITALIAN)
        {
            ami = &MMI_italian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN)
        {
            ami = &MMI_russian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN)
        {
            ami = &MMI_russian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_RUSSIAN)
        {
            ami = &MMI_russian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN)
        {
            ami = &MMI_bulgarian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN)
        {
            ami = &MMI_bulgarian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_BULGARIAN)
        {
            ami = &MMI_bulgarian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN)
        {
            ami = &MMI_UKRAINIAN_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN)
        {
            ami = &MMI_UKRAINIAN_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_UKRAINIAN)
        {
            ami = &MMI_UKRAINIAN_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_TURKISH)
        {
            ami = &MMI_turkish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_TURKISH)
        {
            ami = &MMI_turkish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_TURKISH)
        {
            ami = &MMI_turkish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE)
        {
            ami = &MMI_portuguese_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE)
        {
            ami = &MMI_portuguese_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_PORTUGUESE)
        {
            ami = &MMI_portuguese_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
/*PMT IRE START*/
    #if defined(__MMI_MULTITAP_HINDI__) 
/*PMT IRE END*/
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_HINDI)
        {
            ami = &MMI_hindi_multitaps[MMI_active_multitap];
        }
/*PMT IRE START*/
    #endif /* defined(__MMI_MULTITAP_HINDI__)  */ 
    #if defined(__MMI_MULTITAP_BENGALI__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_BENGALI)
        {
            ami = &MMI_bengali_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */
/*PMT IRE END*/
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN)
        {
            ami = &MMI_indonesian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN)
        {
            ami = &MMI_indonesian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_INDONESIAN)
        {
            ami = &MMI_indonesian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_CZECH)
        {
            ami = &MMI_czech_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_CZECH)
        {
            ami = &MMI_czech_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_CZECH)
        {
            ami = &MMI_czech_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_MALAY)
        {
            ami = &MMI_malay_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_MALAY)
        {
            ami = &MMI_malay_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_MALAY)
        {
            ami = &MMI_malay_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE)
        {
            ami = &MMI_vietnamese_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE)
        {
            ami = &MMI_vietnamese_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_VIETNAMESE)
        {
            ami = &MMI_vietnamese_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_HEBREW)
        {
            ami = &MMI_hebrew_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_HEBREW)
        {
            ami = &MMI_hebrew_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_FINNISH)
        {
            ami = &MMI_finnish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_FINNISH)
        {
            ami = &MMI_finnish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_FINNISH)
        {
            ami = &MMI_finnish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN)
        {
            ami = &MMI_hungarian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN)
        {
            ami = &MMI_hungarian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_HUNGARIAN)
        {
            ami = &MMI_hungarian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK)
        {
            ami = &MMI_slovak_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK)
        {
            ami = &MMI_slovak_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_SLOVAK)
        {
            ami = &MMI_slovak_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_DUTCH)
        {
            ami = &MMI_dutch_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_DUTCH)
        {
            ami = &MMI_dutch_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_DUTCH)
        {
            ami = &MMI_dutch_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
    #if defined(__MMI_MULTITAP_ARABIC__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_ARABIC)
        {
            ami = &MMI_arabic_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_ARABIC)
        {
            ami = &MMI_arabic_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_PERSIAN)
        {
            ami = &MMI_persian_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_PERSIAN)
        {
            ami = &MMI_persian_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
        /* PMT END PERSIAN */
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
		else if(MMI_current_multitap_mode==INPUT_MODE_MULTITAP_URDU) 
		   ami=&MMI_urdu_multitaps[MMI_active_multitap];
		else if(MMI_current_multitap_mode==INPUT_MODE_MMI_MULTITAP_URDU) 
		   ami=&MMI_urdu_multitaps[MMI_active_multitap];
#endif
//PMT END URDU
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN)
        {
            ami = &MMI_norwegian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN)
        {
            ami = &MMI_norwegian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_NORWEGIAN)
        {
            ami = &MMI_norwegian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        //Norwegian end
    #if defined(__MMI_MULTITAP_SWEDISH__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH)
        {
            ami = &MMI_swedish_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH)
        {
            ami = &MMI_swedish_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_SWEDISH)
        {
            ami = &MMI_swedish_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_CROATIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN)
        {
            ami = &MMI_croatian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN)
        {
            ami = &MMI_croatian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_CROATIAN)
        {
            ami = &MMI_croatian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN)
        {
            ami = &MMI_romanian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN)
        {
            ami = &MMI_romanian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_ROMANIAN)
        {
            ami = &MMI_romanian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN)
        {
            ami = &MMI_slovenian_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN)
        {
            ami = &MMI_slovenian_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_SLOVENIAN)
        {
            ami = &MMI_slovenian_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_UPPERCASE_GREEK)
        {
            ami = &MMI_greek_uppercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_LOWERCASE_GREEK)
        {
            ami = &MMI_greek_lowercase_multitaps[MMI_active_multitap];
        }
        else if (MMI_current_multitap_mode == INPUT_MODE_MMI_LOWERCASE_GREEK)
        {
            ami = &MMI_greek_lowercase_multitaps[MMI_active_multitap];
        }
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
    }

    ret = MMI_TRUE;
    if (ami != NULL)
    {
        switch (pen_event)
        {
            case MMI_PEN_EVENT_DOWN:
                if (gui_multitap_input_translate_pen_position(ami, x, y, &index))
                {
                    ami->current_position = index;
                    show_multitap();
                    ami->input_callback(ami->text[ami->current_position]);
                    gui_cancel_timer(disable_active_multitap);
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;

            case MMI_PEN_EVENT_UP:
                gui_start_timer(MMI_MULTITAP_TIMEOUT, disable_active_multitap);
                break;
            case MMI_PEN_EVENT_MOVE:
                if (gui_multitap_input_translate_pen_position(ami, x, y, &index))
                {
                    ami->current_position = index;
                    show_multitap();
                    ami->input_callback(ami->text[ami->current_position]);
                    gui_cancel_timer(disable_active_multitap);
                }
                else
                {
                    ret = MMI_FALSE;
                }
                break;
            case MMI_PEN_EVENT_LONG_TAP:
                break;
            case MMI_PEN_EVENT_REPEAT:
                break;
            case MMI_PEN_EVENT_ABORT:
                break;
        }
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_multitap_data
 * DESCRIPTION
 *  get multitap data by input mode and index
 * PARAMETERS
 *  U8 input_mode       input mode
 *  S32 multitap_key    multitap key value
 * RETURNS
 *  multitap data
 *****************************************************************************/
multitap_input * mmi_ime_get_multitap_data(U8 input_mode, S32 multitap_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* index check*/
#if defined(__MMI_MULTITAP_THAI__)
    if (input_mode == INPUT_MODE_MULTITAP_THAI || input_mode == INPUT_MODE_MMI_MULTITAP_THAI)
    {
        if (multitap_key < 0 || multitap_key > MAX_MULTITAPS_THAI) 
        {
            return ami;
        }        
    }
    else    
#endif
    if (multitap_key < 0 || multitap_key > MAX_MULTITAPS) 
    {
        return ami;
    }

    switch (input_mode)
    {
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            ami = &MMI_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            ami = &MMI_lowercase_multitaps[multitap_key];
            break;

    #if defined (__MMI_MULTITAP_THAI__)
        case INPUT_MODE_MULTITAP_THAI:
            ami = &MMI_thai_multitaps[multitap_key];
            break;
        case INPUT_MODE_MMI_MULTITAP_THAI:
            ami = &MMI_thai_multitaps[multitap_key];
            break;
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 

    #if defined(__MMI_MULTITAP_SPANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
            ami = &MMI_spanish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
            ami = &MMI_spanish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_SPANISH:
            ami = &MMI_spanish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 

    #if defined(__MMI_MULTITAP_DANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DANISH:
            ami = &MMI_danish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_DANISH:
            ami = &MMI_danish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_DANISH:
            ami = &MMI_danish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_POLISH:
            ami = &MMI_polish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_POLISH:
            ami = &MMI_polish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_POLISH:
            ami = &MMI_polish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FRENCH:
            ami = &MMI_french_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_FRENCH:
            ami = &MMI_french_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_FRENCH:
            ami = &MMI_french_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GERMAN:
            ami = &MMI_german_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_GERMAN:
            ami = &MMI_german_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_GERMAN:
            ami = &MMI_german_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN:
            ami = &MMI_italian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN:
            ami = &MMI_italian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_ITALIAN:
            ami = &MMI_italian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN:
            ami = &MMI_russian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN:
            ami = &MMI_russian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_RUSSIAN:
            ami = &MMI_russian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN:
            ami = &MMI_bulgarian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN:
            ami = &MMI_bulgarian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_BULGARIAN:
            ami = &MMI_bulgarian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN:
            ami = &MMI_UKRAINIAN_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN:
            ami = &MMI_UKRAINIAN_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_UKRAINIAN:
            ami = &MMI_UKRAINIAN_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_TURKISH:
            ami = &MMI_turkish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_TURKISH:
            ami = &MMI_turkish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_TURKISH:
            ami = &MMI_turkish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE:
            ami = &MMI_portuguese_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE:
            ami = &MMI_portuguese_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_PORTUGUESE:
            ami = &MMI_portuguese_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */
    #if defined(__MMI_MULTITAP_HINDI__)
        case INPUT_MODE_MULTITAP_HINDI:
            ami = &MMI_hindi_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_HINDI__) */ 
    #if defined(__MMI_MULTITAP_MARATHI__)
        case INPUT_MODE_MULTITAP_MARATHI:
            ami = &MMI_marathi_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_MARATHI__) */ 
	#if defined (__MMI_MULTITAP_TAMIL__) 
        case INPUT_MODE_MULTITAP_TAMIL:
            ami = &MMI_tamil_multitaps[multitap_key];
            break;
    #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 

    #if defined(__MMI_MULTITAP_BENGALI__) 
        case INPUT_MODE_MULTITAP_BENGALI:
            ami = &MMI_bengali_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */ 

	#if defined (__MMI_MULTITAP_PUNJABI__) 
        case INPUT_MODE_MULTITAP_PUNJABI:
            ami = &MMI_punjabi_multitaps[multitap_key];
            break;
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        case INPUT_MODE_MULTITAP_TELUGU:
            ami = &MMI_telugu_multitaps[multitap_key];
            break;
    #endif 
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN:
            ami = &MMI_indonesian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN:
            ami = &MMI_indonesian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_INDONESIAN:
            ami = &MMI_indonesian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CZECH:
            ami = &MMI_czech_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_CZECH:
            ami = &MMI_czech_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_CZECH:
            ami = &MMI_czech_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        case INPUT_MODE_MULTITAP_UPPERCASE_MALAY:
            ami = &MMI_malay_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_MALAY:
            ami = &MMI_malay_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_MALAY:
            ami = &MMI_malay_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
            ami = &MMI_vietnamese_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
            ami = &MMI_vietnamese_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_VIETNAMESE:
            ami = &MMI_vietnamese_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FINNISH:
            ami = &MMI_finnish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_FINNISH:
            ami = &MMI_finnish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_FINNISH:
            ami = &MMI_finnish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN:
            ami = &MMI_hungarian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN:
            ami = &MMI_hungarian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_HUNGARIAN:
            ami = &MMI_hungarian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        case INPUT_MODE_MULTITAP_HEBREW:
            ami = &MMI_hebrew_multitaps[multitap_key];
            break;
        case INPUT_MODE_MMI_MULTITAP_HEBREW:
            ami = &MMI_hebrew_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK:
            ami = &MMI_slovak_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK:
            ami = &MMI_slovak_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_SLOVAK:
            ami = &MMI_slovak_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DUTCH:
            ami = &MMI_dutch_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_DUTCH:
            ami = &MMI_dutch_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_DUTCH:
            ami = &MMI_dutch_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
    #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_MULTITAP_ARABIC:
            ami = &MMI_arabic_multitaps[multitap_key];
            break;
        case INPUT_MODE_MMI_MULTITAP_ARABIC:
            ami = &MMI_arabic_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
    #if defined(__MMI_MULTITAP_PERSIAN__)
        case INPUT_MODE_MULTITAP_PERSIAN:
            ami = &MMI_persian_multitaps[multitap_key];
            break;
        case INPUT_MODE_MMI_MULTITAP_PERSIAN:
            ami = &MMI_persian_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
            /* PMT END PERSIAN */
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
	   case INPUT_MODE_MULTITAP_URDU:
	   	ami=&MMI_urdu_multitaps[MMI_active_multitap];
	   	break;
	   case INPUT_MODE_MMI_MULTITAP_URDU:
	   	ami=&MMI_urdu_multitaps[MMI_active_multitap];
	   	break;
#endif
//PMT END URDU
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN:
            ami = &MMI_norwegian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN:
            ami = &MMI_norwegian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_NORWEGIAN:
            ami = &MMI_norwegian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH:
            ami = &MMI_swedish_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH:
            ami = &MMI_swedish_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_SWEDISH:
            ami = &MMI_swedish_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_CROATIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN:
            ami = &MMI_croatian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN:
            ami = &MMI_croatian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_CROATIAN:
            ami = &MMI_croatian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN:
            ami = &MMI_romanian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN:
            ami = &MMI_romanian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_ROMANIAN:
            ami = &MMI_romanian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN:
            ami = &MMI_slovenian_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN:
            ami = &MMI_slovenian_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_SLOVENIAN:
            ami = &MMI_slovenian_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GREEK:
            ami = &MMI_greek_uppercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_GREEK:
            ami = &MMI_greek_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_GREEK:
            ami = &MMI_greek_lowercase_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
        case INPUT_MODE_MMI_MULTITAP_BPMF:
            ami = &MMI_bpmf_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_MULTITAP_PINYIN:
            ami = &MMI_lowercase_multitaps[multitap_key];
            break;

        case INPUT_MODE_MMI_LOWERCASE_ABC:
            ami = &MMI_lowercase_multitaps[multitap_key];
            break;

    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
            ami = &MMI_uppercase_numberless_multitaps[multitap_key];
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
            ami = &MMI_lowercase_numberless_multitaps[multitap_key];
            break;
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    }    

    return ami;
}


/*****************************************************************************
 * FUNCTION
 *  disable_active_multitap
 * DESCRIPTION
 *  disables the active multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_active_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.09 Touch Screen With Keypad V1 */
#if defined(__MMI_TOUCH_SCREEN__)
    mmi_pen_editor_bpmf_pinyin_disable_active_multitap();
#endif 
    if (MMI_active_multitap < 0)
    {
        return;
    }
    // for multitap timing issue
    if (MMI_timer_multitap != MMI_active_multitap)
    {
        return;
    }
    
    //MTK Elvis to add some APIs for Qsearch
    //(MMI_current_multitap_mode==0) ami=&MMI_uppercase_multitaps[MMI_active_multitap];
    //se if(MMI_current_multitap_mode==1) ami=&MMI_lowercase_multitaps[MMI_active_multitap];

    ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, MMI_active_multitap);
    
    /* W06.09 Touch Screen With Keypad V1 */
#if defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__)
#else /* defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__) */ 
    hide_multitap();
#endif /* defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__) */ 
    /* PMT dara added for Multitap thai */

    MMI_active_multitap = -1;
    if (ami != NULL)
    {
        gui_multitap_input_complete(ami);
    }

}


/*****************************************************************************
 * FUNCTION
 *  disable_active_multitap_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_active_multitap_no_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_active_multitap < 0)
    {
        return;
    }
    // for timing issue
    if (MMI_timer_multitap != MMI_active_multitap)
    {
        return;
    }
    ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, MMI_active_multitap);
    
    MMI_active_multitap = -1;
    if (ami != NULL)
    {
        gui_multitap_input_complete(ami);
    }
}

/*****************************************************************************
 * FUNCTION
 *  change_multitap_state
 * DESCRIPTION
 *  Changes the state of a specified multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void change_multitap_state(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;
    U8 flag = 0;
    S32 old_active_mi = MMI_active_multitap;

    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    U8 max_multitaps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_THAI ||
        MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_THAI)
    {
        max_multitaps = MAX_MULTITAPS_THAI;
    }
    else
    {
        max_multitaps = MAX_MULTITAPS;
    }
#else /* defined(__MMI_MULTITAP_THAI__) */ 
    U8 max_multitaps = MAX_MULTITAPS;
#endif /* defined(__MMI_MULTITAP_THAI__) */ 
    /* PMT dara added for Multitap thai */
#ifdef __MMI_MULTITAP_THAI__
    if (i == KEY_STAR)
    {
        i = 10;
    }
    if (i == KEY_POUND)
    {
        i = 11;
    }
#endif /* __MMI_MULTITAP_THAI__ */ 
    /* PMT dara added for Multitap thai */

    if ((i < 0) || (i > (max_multitaps - 1)))
    {
        return;
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    /* gui_lock_double_buffer(); */
#endif 

    if (MMI_active_multitap != i)
    {
        flag = 1;
    }
    //START VIJAY 20050725....commented as to show multitap till character is selected      
    //hide_multitap(); 
    //END VIJAY PMT 20050725
    MMI_active_multitap = i;
    if (flag && (old_active_mi >= 0) && (old_active_mi < max_multitaps))
    {
        //MTK Elvis to add some APIs for Qsearch
        //if(MMI_current_multitap_mode==0) ami=&MMI_uppercase_multitaps[old_active_mi];
        //else if(MMI_current_multitap_mode==1) ami=&MMI_lowercase_multitaps[old_active_mi];

        ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, old_active_mi);
    #if defined(__MMI_MULTITAP_HINDI__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_HINDI)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_hindi_multitaps[i], (UI_string_type) get_hindi_multitap_string(i));
             }
         }
    #endif /* (__MMI_MULTITAP_HINDI__)  */   
    #if defined(__MMI_MULTITAP_MARATHI__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_MARATHI)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_marathi_multitaps[i], (UI_string_type) get_marathi_multitap_string(i));
             }
         }
    #endif /* defined(__MMI_MULTITAP_MARATHI__) */         
    #if defined(__MMI_MULTITAP_TAMIL__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_TAMIL)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_tamil_multitaps[i], (UI_string_type) get_tamil_multitap_string(i));
             }
         }
    #endif /* defined(__MMI_MULTITAP_TAMIL__) */         
#if defined(__MMI_MULTITAP_BENGALI__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_BENGALI)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_bengali_multitaps[i], (UI_string_type) get_bengali_multitap_string(i));
             }
         }
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */         
    #if defined(__MMI_MULTITAP_PUNJABI__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_PUNJABI)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_punjabi_multitaps[i], (UI_string_type) get_punjabi_multitap_string(i));
             }
         }
    #endif
    #if defined(__MMI_MULTITAP_TELUGU__) 
         if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_TELUGU)
         {
            for (i = 0; i < MAX_MULTITAPS; i++)
            {
                gui_set_multitap_input_text(&MMI_telugu_multitaps[i], (UI_string_type) get_telugu_multitap_string(i));
             }
         }
    #endif
      
        if (ami != NULL)
        {
            gui_multitap_input_complete(ami);
        }
    }

    //MTK Elvis to add some APIs for Qsearch
    //if(MMI_current_multitap_mode==0) ami=&MMI_uppercase_multitaps[MMI_active_multitap];
    //else if(MMI_current_multitap_mode==1) ami=&MMI_lowercase_multitaps[MMI_active_multitap];

    ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, MMI_active_multitap);
    switch (MMI_current_multitap_mode)
    {
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
    #ifdef __MMI_LANG_VIETNAMESE__
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_uppercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
    #endif /* __MMI_LANG_VIETNAMESE__ */ 
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        #ifdef __MMI_LANG_VIETNAMESE__
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_lowercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
        #endif /* __MMI_LANG_VIETNAMESE__ */ 
            break;

        #if defined(__MMI_MULTITAP_HINDI__)
         case INPUT_MODE_MULTITAP_HINDI:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_hindi_multitaps[i], (UI_string_type) get_hindi_multitap_string(i));
                }
            }
            break;

        #endif /* defined(__MMI_MULTITAP_HINDI__) */ 
        #if defined(__MMI_MULTITAP_MARATHI__)
        case INPUT_MODE_MULTITAP_MARATHI:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(
                        &MMI_marathi_multitaps[i],
                        (UI_string_type) get_marathi_multitap_string(i));
                }
            }
            break;

        #endif /* defined(__MMI_MULTITAP_MARATHI__)  */ 
		#if defined (__MMI_MULTITAP_TAMIL__) 
        case INPUT_MODE_MULTITAP_TAMIL:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_tamil_multitaps[i], (UI_string_type) get_tamil_multitap_string(i));
                }
            }
            break;

        #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 
       #if defined(__MMI_MULTITAP_BENGALI__) 
        case INPUT_MODE_MULTITAP_BENGALI:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(
                        &MMI_bengali_multitaps[i],
                        (UI_string_type) get_bengali_multitap_string(i));
                }
            }
            break;

        #endif /* defined(__MMI_MULTITAP_BENGALI__) */
		#if defined (__MMI_MULTITAP_PUNJABI__) 
        case INPUT_MODE_MULTITAP_PUNJABI:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_punjabi_multitaps[i], (UI_string_type) get_punjabi_multitap_string(i));
                }
            }
            break;

        #endif
        #if defined (__MMI_MULTITAP_TELUGU__) 
        case INPUT_MODE_MULTITAP_TELUGU:
            if (flag)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_telugu_multitaps[i], (UI_string_type) get_telugu_multitap_string(i));
                }
            }
            break;

        #endif
        #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_vietnamese_uppercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_vietnamese_lowercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
            break;

        case INPUT_MODE_MMI_LOWERCASE_VIETNAMESE:
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_vietnamese_lowercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
            break;
        #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 

        case INPUT_MODE_MMI_LOWERCASE_ABC:
        #ifdef __MMI_LANG_VIETNAMESE__
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_lowercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
        #endif /* __MMI_LANG_VIETNAMESE__ */ 
            break;
        #if defined(__MMI_MULTITAP_THAI__)
            case INPUT_MODE_MULTITAP_THAI:
            case INPUT_MODE_MMI_MULTITAP_THAI:
                if (old_active_mi != MMI_active_multitap)
                {
                    for (i = 0; i < max_multitaps; i++)
                    {
                        gui_set_multitap_input_text(&MMI_thai_multitaps[i], (UI_string_type) get_thai_multitap_string(i));
                    }
                }            
                break;
        #endif


    }
    if (ami == NULL) return;
    /* Call gui_change_multitap_input_state(ami) */
    ami->current_position++;
    if (ami->current_position >= ami->length)
    {
        ami->current_position = 0;
    }

    /* MTK Terry for multitap length > lcm width */
    if (ami->text_x <= 0)
    {
        S32 string_width = 0, string_height = 0;

        gui_set_font(ami->text_font);
        Get_StringWidthHeight_multitap((U8*)ami->text, ami->text_gap, &string_width, &string_height);
        if (ami->current_position > ((ami->length) >> 1))
        {
            ami->text_x = ami->width - string_width;
        }
        else
        {
            ami->text_x = 0;
        }
    }
    show_multitap();
    ami->input_callback(ami->text[ami->current_position]);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    //      gui_unlock_double_buffer();
    //      gui_BLT_double_buffer(ami->x,ami->y,ami->x+ami->width+1,ami->y+ami->height+1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  change_multitap_state_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void change_multitap_state_no_draw(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multitap_input *ami = NULL;
    U8 flag = 0;
    S32 old_active_mi = MMI_active_multitap;

    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    U8 max_multitaps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_multitap_mode == INPUT_MODE_MULTITAP_THAI ||
        MMI_current_multitap_mode == INPUT_MODE_MMI_MULTITAP_THAI)
    {
        max_multitaps = MAX_MULTITAPS_THAI;
    }
    else
    {
        max_multitaps = MAX_MULTITAPS;
    }
#else /* defined(__MMI_MULTITAP_THAI__) */ 
    U8 max_multitaps = MAX_MULTITAPS;
#endif /* defined(__MMI_MULTITAP_THAI__) */ 

    /* PMT dara added for Multitap thai */
#ifdef __MMI_MULTITAP_THAI__
    if (i == KEY_STAR)
    {
        i = 10;
    }
    if (i == KEY_POUND)
    {
        i = 11;
    }
#endif /* __MMI_MULTITAP_THAI__ */ 

    if ((i < 0) || (i > (max_multitaps - 1)))
    {
        return;
    }
    if (MMI_active_multitap != i)
    {
        flag = 1;
    }
    MMI_active_multitap = i;
    if (flag && (old_active_mi >= 0) && (old_active_mi < max_multitaps))
    {
        ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, old_active_mi);
        if (ami != NULL)
        {
            gui_multitap_input_complete(ami);
        }
    }

    ami = mmi_ime_get_multitap_data(MMI_current_multitap_mode, MMI_active_multitap);
    switch (MMI_current_multitap_mode)
    {
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
    #ifdef __MMI_LANG_VIETNAMESE__
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && 
                (ami->current_position + 1) == ami->length && !get_multitap_state())
            {
                gui_set_multitap_input_text(
                            &MMI_uppercase_multitaps[MMI_VIET_TONE_KEY],
                            (UI_string_type) get_viet_multitap_string());
            }
    #endif /* __MMI_LANG_VIETNAMESE__ */ 
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case INPUT_MODE_MMI_LOWERCASE_ABC:
    #ifdef __MMI_LANG_VIETNAMESE__
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && 
                (ami->current_position + 1) == ami->length && !get_multitap_state())
            {
                gui_set_multitap_input_text(
                            &MMI_lowercase_multitaps[MMI_VIET_TONE_KEY],
                            (UI_string_type) get_viet_multitap_string());
            }
    #endif /* __MMI_LANG_VIETNAMESE__ */ 
            break;    
    #if defined(__MMI_MULTITAP_HINDI__)
        case INPUT_MODE_MULTITAP_HINDI:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_hindi_multitaps[i], (UI_string_type) get_hindi_multitap_string(i));
                }
            }
            break;
    #endif
    #if defined(__MMI_MULTITAP_MARATHI__)
        case INPUT_MODE_MULTITAP_MARATHI:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_marathi_multitaps[i], (UI_string_type) get_marathi_multitap_string(i));
                }
            }
            break;
/*PMT IRE START*/ 
#endif /* defined(__MMI_MULTITAP_MARATHI__)  */ 
/*PMT IRE END*/ 
/*PMT IRE START*/ 
#if defined (__MMI_MULTITAP_TAMIL__) 
/*PMT IRE END*/ 
        case INPUT_MODE_MULTITAP_TAMIL:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_tamil_multitaps[i], (UI_string_type) get_tamil_multitap_string(i));
                }
            }
            break;
/*PMT IRE START*/ 
#endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 
/*PMT IRE END*/ 
    /* PMT RAKESH START 20061006 */
/*PMT IRE START*/ 
#if defined(__MMI_MULTITAP_BENGALI__) 
/*PMT IRE END*/ 
        case INPUT_MODE_MULTITAP_BENGALI:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_bengali_multitaps[i], (UI_string_type) get_bengali_multitap_string(i));
                }
            }
            break;
#endif /* (__MMI_MULTITAP_BENGALI__)  */
        #if defined (__MMI_MULTITAP_PUNJABI__) 
        case INPUT_MODE_MULTITAP_PUNJABI:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_punjabi_multitaps[i], (UI_string_type) get_punjabi_multitap_string(i));
                }
            }
            break;
        #endif
        #if defined (__MMI_MULTITAP_TELUGU__) 
        case INPUT_MODE_MULTITAP_TELUGU:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < MAX_MULTITAPS; i++)
                {
                    gui_set_multitap_input_text(&MMI_telugu_multitaps[i], (UI_string_type) get_telugu_multitap_string(i));
                }
            }
            break;
        #endif
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_vietnamese_uppercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
        case INPUT_MODE_MMI_LOWERCASE_VIETNAMESE:    
            /* W05.36 Fix Vietnamese Tone Input Issue */
            if (MMI_VIET_TONE_KEY == MMI_active_multitap && (ami->current_position + 1) == ami->length &&
                !get_multitap_state())
            {
                gui_set_multitap_input_text(
                    &MMI_vietnamese_lowercase_multitaps[MMI_VIET_TONE_KEY],
                    (UI_string_type) get_viet_multitap_string());
            }
            break;
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */
    #if defined(__MMI_MULTITAP_THAI__)
        case INPUT_MODE_MULTITAP_THAI:
        case INPUT_MODE_MMI_MULTITAP_THAI:
            if (old_active_mi != MMI_active_multitap)
            {
                for (i = 0; i < max_multitaps; i++)
                {
                    gui_set_multitap_input_text(&MMI_thai_multitaps[i], (UI_string_type) get_thai_multitap_string(i));
                }
            }            
            break;
    #endif
    }

        if (ami != NULL)
        {
            gui_change_multitap_input_state(ami);
        }
}


/*****************************************************************************
 * FUNCTION
 *  multitap_input_key_down
 * DESCRIPTION
 *  Key handler for key pad key down events.
 *  
 *  Internal function
 * PARAMETERS
 *  key     [IN]        Is the keypad key code
 * RETURNS
 *  void
 *****************************************************************************/
void multitap_input_key_down(S32 key)
{
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KEY_STAR == key)
    {
        change_multitap_state(MULTITAP_STAR);
    }
    if (KEY_POUND == key)
    {
        change_multitap_state(MULTITAP_POUND);
    }
    else
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {
        change_multitap_state(key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  multitap_input_key_down_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multitap_input_key_down_no_draw(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)

#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */   
    if (KEY_STAR == key)
    {
        change_multitap_state_no_draw(MULTITAP_STAR);
    }
    else if (KEY_POUND == key)
    {
        change_multitap_state_no_draw(MULTITAP_POUND);
    }
    else
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    {
        change_multitap_state_no_draw(key);
    }
}

/* MTK Elvis 20040104 */
extern void redraw_input_mode_only(void);

extern void PbookListSearchEntryReq(void);


/*****************************************************************************
 * FUNCTION
 *  multitap_input_key_down_no_draw_plus_post_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multitap_input_key_down_no_draw_plus_post_process(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    change_multitap_state_no_draw(key);
    redraw_input_mode_only();
    PbookListSearchEntryReq();
    menu_shortcut_handler_display = 1;
}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  multitap_input_key_up
 * DESCRIPTION
 *  Key handler for key pad key up events.
 *  
 *  Internal function
 * PARAMETERS
 *  key     [IN]        Is the keypad key code
 * RETURNS
 *  void
 *****************************************************************************/
void multitap_input_key_up(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);
    MMI_timer_multitap = MMI_active_multitap;
    gui_start_timer(MMI_MULTITAP_TIMEOUT, disable_active_multitap);
}


/*****************************************************************************
 * FUNCTION
 *  multitap_input_key_up_no_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multitap_input_key_up_no_draw(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key);
    MMI_timer_multitap = MMI_active_multitap;
    gui_start_timer(MMI_MULTITAP_TIMEOUT, disable_active_multitap_no_draw);
}

/* MTK Elvis to add some APIs for Qsearch */


/*****************************************************************************
 * FUNCTION
 *  get_bpmf_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_bpmf_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_bpmf_multitap_strings[i]);
}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_lowercase_multitap_strings[i]);
}

/*PMT IRE START*/
//CODE MOVED TO LANGUAGE FILE
/*PMT IRE END*/


#if defined(__MMI_MULTITAP_SPANISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_spanish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_spanish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_spanish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_spanish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_spanish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_spanish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
#if defined(__MMI_MULTITAP_DANISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_danish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_danish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_danish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_danish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_danish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_danish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_DANISH__) */ 
#if defined(__MMI_MULTITAP_POLISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_polish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_polish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_polish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_polish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_polish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_polish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_POLISH__) */ 
#if defined(__MMI_MULTITAP_FRENCH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_french_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_french_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_french_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_french_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_french_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_french_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
#if defined(__MMI_MULTITAP_GERMAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_german_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_german_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_german_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_german_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_german_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_german_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
#if defined(__MMI_MULTITAP_ITALIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_italian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_italian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_italian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_italian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_italian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_italian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
#if defined(__MMI_MULTITAP_RUSSIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_russian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_russian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_russian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_russian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_russian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_russian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
#if defined(__MMI_MULTITAP_BULGARIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_bulgarian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_bulgarian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_bulgarian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_bulgarian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_bulgarian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_bulgarian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
#if defined(__MMI_MULTITAP_UKRAINIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_UKRAINIAN_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_UKRAINIAN_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_UKRAINIAN_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_UKRAINIAN_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_UKRAINIAN_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_UKRAINIAN_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
#if defined(__MMI_MULTITAP_TURKISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_turkish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_turkish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_turkish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_turkish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_turkish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_turkish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
#if defined(__MMI_MULTITAP_PORTUGUESE__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_portuguese_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_portuguese_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_portuguese_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_portuguese_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_portuguese_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_portuguese_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
#if defined(__MMI_MULTITAP_INDONESIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_indonesian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_indonesian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_indonesian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_indonesian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_indonesian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_indonesian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
#if defined(__MMI_MULTITAP_CZECH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_czech_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_czech_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_czech_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_czech_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_czech_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_czech_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_CZECH__) */ 

#if defined(__MMI_MULTITAP_MALAY__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_malay_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_malay_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_malay_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_malay_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_malay_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_malay_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_MALAY__) */ 
#if defined(__MMI_MULTITAP_VIETNAMESE__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_vietnamese_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_vietnamese_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_vietnamese_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_vietnamese_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_vietnamese_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_vietnamese_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
#if defined(__MMI_MULTITAP_FINNISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_finnish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_finnish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_finnish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_finnish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_finnish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_finnish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
#if defined(__MMI_MULTITAP_HUNGARIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_hungarian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_hungarian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_hungarian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_hungarian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_hungarian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_hungarian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 

#if defined(__MMI_MULTITAP_SLOVAK__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_slovak_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_slovak_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_slovak_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_slovak_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_slovak_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_slovak_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
#if defined(__MMI_MULTITAP_DUTCH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_dutch_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_dutch_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_dutch_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_dutch_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_dutch_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_dutch_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
#if defined(__MMI_MULTITAP_HEBREW__)


/*****************************************************************************
 * FUNCTION
 *  get_hebrew_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_hebrew_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_hebrew_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
#if defined(__MMI_MULTITAP_ARABIC__)


/*****************************************************************************
 * FUNCTION
 *  get_arabic_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_arabic_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_arabic_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
/* PMT START PERSIAN */
#if defined(__MMI_MULTITAP_PERSIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_persian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_persian_multitap_string(s32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_persian_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
/* PMT END PERSIAN */
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
/*----------------------------------------------------------------------------
Function:			get_uppercase_urdu_multitap_string
Description:		Returns the character sequence associated with a multitap object
Input Parameters:	i		(zero based) index to the array of multitap objects
Output Parameters:	none
Returns:			void
Remarks:			Internal function
----------------------------------------------------------------------------*/
UI_character_type *get_urdu_multitap_string(s32 i)
{	return((UI_character_type *) default_urdu_multitap_strings[i]);
}
#endif
//PMT END URDU
#if defined(__MMI_MULTITAP_NORWEGIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_norwegian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_norwegian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_norwegian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_norwegian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_norwegian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_norwegian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
//Norwegian end
#if defined(__MMI_MULTITAP_SWEDISH__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_swedish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_swedish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_swedish_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_swedish_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_swedish_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_swedish_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
#if defined(__MMI_MULTITAP_CROATIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_croatian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_croatian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_croatian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_croatian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_croatian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_croatian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
#if defined(__MMI_MULTITAP_ROMANIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_romanian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_romanian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_romanian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_romanian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_romanian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_romanian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
#if defined(__MMI_MULTITAP_SLOVENIAN__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_slovenian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_slovenian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_slovenian_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_slovenian_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_slovenian_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_slovenian_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 

#if defined(__MMI_MULTITAP_GREEK__)


/*****************************************************************************
 * FUNCTION
 *  get_uppercase_greek_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_uppercase_greek_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_greek_uppercase_multitap_strings[i]);
}


/*****************************************************************************
 * FUNCTION
 *  get_lowercase_greek_multitap_string
 * DESCRIPTION
 *  Returns the character sequence associated with a multitap object
 *  
 *  Internal function
 * PARAMETERS
 *  i       [IN]        (zero based) index to the array of multitap objects
 * RETURNS
 *  void
 *****************************************************************************/
UI_character_type *get_lowercase_greek_multitap_string(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((UI_character_type*) default_greek_lowercase_multitap_strings[i]);
}
#endif /* defined(__MMI_MULTITAP_GREEK__) */ 


/*****************************************************************************
 * FUNCTION
 *  create_numberless_multitap
 * DESCRIPTION
 *  Creates the multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
void create_numberless_multitap(void)
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
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        s = (UI_string_type) numberless_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_uppercase_numberless_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) numberless_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_lowercase_numberless_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    }
}
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  create_multitaps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_multitaps(void)
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
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        s = get_uppercase_multitap_string(i);
        gui_create_multitap_input(
            &MMI_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_multitap_string(i);
        gui_create_multitap_input(
            &MMI_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_bpmf_multitap_string(i);
        gui_create_multitap_input(
            &MMI_bpmf_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);

        /* PMT dara added for Multitap thai */
    #if defined (__MMI_MULTITAP_THAI__)
        s = get_thai_multitap_string(i);
        gui_create_multitap_input(
            &MMI_thai_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 
        /* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_MULTITAP_SPANISH__)
        s = get_uppercase_spanish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_spanish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_spanish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_spanish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        s = get_uppercase_danish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_danish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_danish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_danish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        s = get_uppercase_polish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_polish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_polish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_polish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        s = get_uppercase_french_multitap_string(i);
        gui_create_multitap_input(
            &MMI_french_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_french_multitap_string(i);
        gui_create_multitap_input(
            &MMI_french_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        s = get_uppercase_german_multitap_string(i);
        gui_create_multitap_input(
            &MMI_german_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_german_multitap_string(i);
        gui_create_multitap_input(
            &MMI_german_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        s = get_uppercase_italian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_italian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_italian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_italian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        s = get_uppercase_russian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_russian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_russian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_russian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        s = get_uppercase_bulgarian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_bulgarian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_bulgarian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_bulgarian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        s = get_uppercase_UKRAINIAN_multitap_string(i);
        gui_create_multitap_input(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_UKRAINIAN_multitap_string(i);
        gui_create_multitap_input(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        s = get_uppercase_turkish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_turkish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_turkish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_turkish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        s = get_uppercase_portuguese_multitap_string(i);
        gui_create_multitap_input(
            &MMI_portuguese_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_portuguese_multitap_string(i);
        gui_create_multitap_input(
            &MMI_portuguese_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_HINDI__)
        /* s=get_hindi_multitap_string(i); */
        gui_create_multitap_input(
            &MMI_hindi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_hindi_multitap_strings[i]);
    #endif /* defined(__MMI_MULTITAP_HINDI__)  */ 
	#if defined (__MMI_MULTITAP_TAMIL__) 
        gui_create_multitap_input(
            &MMI_tamil_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_tamil_multitap_strings[i]);
    #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 
    #if defined(__MMI_MULTITAP_MARATHI__) 
        gui_create_multitap_input(
            &MMI_marathi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_marathi_multitap_strings[i]);
    #endif /* defined(__MMI_MULTITAP_MARATHI__)  */ 
    #if defined(__MMI_MULTITAP_BENGALI__) 
        gui_create_multitap_input(
            &MMI_bengali_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_bengali_multitap_strings[i]);
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */ 

	#if defined (__MMI_MULTITAP_PUNJABI__) 
        gui_create_multitap_input(
            &MMI_punjabi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_punjabi_multitap_strings[i]);
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        gui_create_multitap_input(
            &MMI_telugu_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            (UI_string_type) default_telugu_multitap_strings[i]);
    #endif
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        s = get_uppercase_indonesian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_indonesian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_indonesian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_indonesian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        s = get_uppercase_czech_multitap_string(i);
        gui_create_multitap_input(
            &MMI_czech_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_czech_multitap_string(i);
        gui_create_multitap_input(
            &MMI_czech_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        s = get_uppercase_malay_multitap_string(i);
        gui_create_multitap_input(
            &MMI_malay_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_malay_multitap_string(i);
        gui_create_multitap_input(
            &MMI_malay_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        s = get_uppercase_vietnamese_multitap_string(i);
        gui_create_multitap_input(
            &MMI_vietnamese_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_vietnamese_multitap_string(i);
        gui_create_multitap_input(
            &MMI_vietnamese_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        s = get_uppercase_finnish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_finnish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_finnish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_finnish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        s = get_uppercase_hungarian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_hungarian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_hungarian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_hungarian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        s = get_uppercase_swedish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_swedish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_swedish_multitap_string(i);
        gui_create_multitap_input(
            &MMI_swedish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        s = get_hebrew_multitap_string(i);
        gui_create_multitap_input(
            &MMI_hebrew_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        s = get_uppercase_slovak_multitap_string(i);
        gui_create_multitap_input(
            &MMI_slovak_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_slovak_multitap_string(i);
        gui_create_multitap_input(
            &MMI_slovak_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        s = get_uppercase_dutch_multitap_string(i);
        gui_create_multitap_input(
            &MMI_dutch_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_dutch_multitap_string(i);
        gui_create_multitap_input(
            &MMI_dutch_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        /* Norwegian start */
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        s = get_uppercase_norwegian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_norwegian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_norwegian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_norwegian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        /* Norwegian end */
    #if defined(__MMI_MULTITAP_ARABIC__)
        s = get_arabic_multitap_string(i);
        gui_create_multitap_input(
            &MMI_arabic_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        s = get_persian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_persian_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
        //PMT END PERSIAN
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
		s=get_urdu_multitap_string(i);
		gui_create_multitap_input(&MMI_urdu_multitaps[i],MMI_multitap_x,MMI_multitap_y,width,MMI_multitap_height,s);
#endif
//PMT END URDU
    #if defined(__MMI_MULTITAP_CROATIAN__)
        s = get_uppercase_croatian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_croatian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_croatian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_croatian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        s = get_uppercase_romanian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_romanian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_romanian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_romanian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        s = get_uppercase_slovenian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_slovenian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_slovenian_multitap_string(i);
        gui_create_multitap_input(
            &MMI_slovenian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        s = get_uppercase_greek_multitap_string(i);
        gui_create_multitap_input(
            &MMI_greek_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = get_lowercase_greek_multitap_string(i);
        gui_create_multitap_input(
            &MMI_greek_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
        /* PMT END GR_HE_CZ_FI_DA_HU 20051007 */
    }

    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    for (i = 0; i < MAX_MULTITAPS_THAI; i++)
    {
        s = get_thai_multitap_string(i);
        gui_create_multitap_input(
            &MMI_thai_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        /* need to update the with for */
    }
#endif /* defined(__MMI_MULTITAP_THAI__) */ 

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
    create_numberless_multitap();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  set_numberless_multitap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_numberless_multitap(void)
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
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        s = (UI_string_type) numberless_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) numberless_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_english_only_multitap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_english_only_multitap(void)
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
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        s = (UI_string_type) english_only_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) english_only_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_normal_multitap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_normal_multitap(void)
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
    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    for (i = 0; i < MAX_MULTITAPS_THAI; i++)
    {
        s = (UI_string_type) default_multitap_thai_strings_normal[i];
        gui_create_multitap_input(
            &MMI_thai_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    }
#endif /* defined(__MMI_MULTITAP_THAI__) */ 

    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        s = (UI_string_type) default_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_bpmf_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_bpmf_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        /* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_MULTITAP_SPANISH__)
        s = (UI_string_type) default_spanish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_spanish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_spanish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_spanish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        s = (UI_string_type) default_danish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_danish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_danish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_danish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        s = (UI_string_type) default_polish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_polish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_polish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_polish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        s = (UI_string_type) default_french_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_french_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_french_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_french_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        s = (UI_string_type) default_german_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_german_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_german_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_german_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        s = (UI_string_type) default_italian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_italian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_italian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_italian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        s = (UI_string_type) default_russian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_russian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_russian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_russian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        s = (UI_string_type) default_bulgarian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_bulgarian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_bulgarian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_bulgarian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        s = (UI_string_type) default_UKRAINIAN_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_UKRAINIAN_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        s = (UI_string_type) default_turkish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_turkish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_turkish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_turkish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        s = (UI_string_type) default_portuguese_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_portuguese_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_portuguese_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_portuguese_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
/*PMT IRE START*/
    #if defined(__MMI_MULTITAP_HINDI__) 
/*PMT IRE END*/
        s = (UI_string_type) default_hindi_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_hindi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
/*PMT IRE START*/
    #endif /* defined(__MMI_MULTITAP_HINDI__)  */ 
    #if defined(__MMI_MULTITAP_MARATHI__) 
/*PMT IRE END*/
        s = (UI_string_type) default_marathi_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_marathi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_MARATHI__)  */ 
	#if defined (__MMI_MULTITAP_TAMIL__) 
        s = (UI_string_type) default_tamil_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_tamil_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */
        /* PMT RAKESH START 20061006 */
    #if defined(__MMI_MULTITAP_BENGALI__) 
        s = (UI_string_type) default_bengali_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_bengali_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */ 

	#if defined (__MMI_MULTITAP_PUNJABI__) 
        s = (UI_string_type) default_punjabi_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_punjabi_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        s = (UI_string_type) default_telugu_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_telugu_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        s = (UI_string_type) default_indonesian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_indonesian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_indonesian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_indonesian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        s = (UI_string_type) default_czech_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_czech_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_czech_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_czech_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        s = (UI_string_type) default_malay_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_malay_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_malay_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_malay_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        s = (UI_string_type) default_vietnamese_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_vietnamese_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_vietnamese_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_vietnamese_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        s = (UI_string_type) default_finnish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_finnish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_finnish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_finnish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        s = (UI_string_type) default_hungarian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_hungarian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_hungarian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_hungarian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        s = (UI_string_type) default_swedish_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_swedish_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_swedish_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_swedish_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        s = (UI_string_type) default_hebrew_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_hebrew_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        s = (UI_string_type) default_slovak_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_slovak_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_slovak_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_slovak_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        s = (UI_string_type) default_dutch_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_dutch_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_dutch_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_dutch_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        /* Norwegian start */
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        s = (UI_string_type) default_norwegian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_norwegian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_norwegian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_norwegian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        /* Norwegian end */
    #if defined(__MMI_MULTITAP_ARABIC__)
        s = (UI_string_type) default_arabic_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_arabic_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        s = (UI_string_type) default_persian_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_persian_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
        //PMT END PERSIAN
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
		s=(UI_string_type) default_urdu_multitap_strings[i];
		gui_create_multitap_input(&MMI_urdu_multitaps[i],MMI_multitap_x,MMI_multitap_y,width,MMI_multitap_height,s);
#endif
//PMT END URDU
    #if defined(__MMI_MULTITAP_CROATIAN__)
        s = (UI_string_type) default_croatian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_croatian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_croatian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_croatian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        s = (UI_string_type) default_romanian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_romanian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_romanian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_romanian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        s = (UI_string_type) default_slovenian_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_slovenian_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_slovenian_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_slovenian_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        s = (UI_string_type) default_greek_uppercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_greek_uppercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
        s = (UI_string_type) default_greek_lowercase_multitap_strings[i];
        gui_create_multitap_input(
            &MMI_greek_lowercase_multitaps[i],
            MMI_multitap_x,
            MMI_multitap_y,
            width,
            MMI_multitap_height,
            s);
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_multitap_functions
 * DESCRIPTION
 *  Sets the callback functions for the multitap objects
 * PARAMETERS
 *  input_callback              [IN]        Is a function that is called whenever
 *  input_complete_callback     [IN]        Is a function that is called on
 *  compeletion(?)              [IN]        Of the input sequence.
 *  a(?)                        [IN]        New multitap character is entered in an input sequence
 *  This(?)                     [IN]        Function is called with the character that was input
 *  as(?)                       [IN]        The parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void set_multitap_functions(void (*input_callback) (UI_character_type), void (*input_complete_callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    for (i = 0; i < MAX_MULTITAPS_THAI; i++)
    {
        gui_set_multitap_input_callbacks(&MMI_thai_multitaps[i], input_callback, input_complete_callback);
    }
#endif /* defined(__MMI_MULTITAP_THAI__) */ 

    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        gui_set_multitap_input_callbacks(&MMI_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_lowercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_bpmf_multitaps[i], input_callback, input_complete_callback);
        /* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_MULTITAP_SPANISH__)
        gui_set_multitap_input_callbacks(&MMI_spanish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_spanish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        gui_set_multitap_input_callbacks(&MMI_danish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_danish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        gui_set_multitap_input_callbacks(&MMI_polish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_polish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        gui_set_multitap_input_callbacks(&MMI_french_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_french_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        gui_set_multitap_input_callbacks(&MMI_german_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_german_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        gui_set_multitap_input_callbacks(&MMI_italian_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_italian_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        gui_set_multitap_input_callbacks(&MMI_russian_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_russian_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_bulgarian_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_bulgarian_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        gui_set_multitap_input_callbacks(&MMI_turkish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_turkish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        gui_set_multitap_input_callbacks(
            &MMI_portuguese_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_portuguese_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_HINDI__) 
        gui_set_multitap_input_callbacks(&MMI_hindi_multitaps[i], input_callback, input_complete_callback);
    #endif 
    #if defined(__MMI_MULTITAP_MARATHI__) 
        gui_set_multitap_input_callbacks(&MMI_marathi_multitaps[i], input_callback, input_complete_callback);
    #endif 
	#if defined (__MMI_MULTITAP_TAMIL__) 
        gui_set_multitap_input_callbacks(&MMI_tamil_multitaps[i], input_callback, input_complete_callback);
    #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */

    #if defined(__MMI_MULTITAP_BENGALI__) 
        gui_set_multitap_input_callbacks(&MMI_bengali_multitaps[i], input_callback, input_complete_callback);
    #endif 
	#if defined (__MMI_MULTITAP_PUNJABI__) 
        gui_set_multitap_input_callbacks(&MMI_punjabi_multitaps[i], input_callback, input_complete_callback);
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        gui_set_multitap_input_callbacks(&MMI_telugu_multitaps[i], input_callback, input_complete_callback);
    #endif
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_indonesian_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_indonesian_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        gui_set_multitap_input_callbacks(&MMI_czech_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_czech_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        gui_set_multitap_input_callbacks(&MMI_malay_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_malay_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        gui_set_multitap_input_callbacks(
            &MMI_vietnamese_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_vietnamese_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        gui_set_multitap_input_callbacks(&MMI_finnish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_finnish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_hungarian_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_hungarian_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        gui_set_multitap_input_callbacks(&MMI_swedish_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_swedish_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        gui_set_multitap_input_callbacks(&MMI_hebrew_multitaps[i], input_callback, input_complete_callback);
    #endif 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        gui_set_multitap_input_callbacks(&MMI_slovak_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_slovak_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        gui_set_multitap_input_callbacks(&MMI_dutch_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_dutch_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        /* Norwegian start */
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_norwegian_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_norwegian_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        /* Norwegian end */
    #if defined(__MMI_MULTITAP_ARABIC__)
        gui_set_multitap_input_callbacks(&MMI_arabic_multitaps[i], input_callback, input_complete_callback);
    #endif 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        gui_set_multitap_input_callbacks(&MMI_persian_multitaps[i], input_callback, input_complete_callback);
    #endif 
        //PMT END PERSIAN
//PMT START URDU 
    #if defined(__MMI_MULTITAP_URDU__)
		gui_set_multitap_input_callbacks(&MMI_urdu_multitaps[i],input_callback,input_complete_callback);
    #endif      
//PMT END URDU
    #if defined(__MMI_MULTITAP_CROATIAN__)
        gui_set_multitap_input_callbacks(&MMI_croatian_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_croatian_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        gui_set_multitap_input_callbacks(&MMI_romanian_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_romanian_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_slovenian_uppercase_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_slovenian_lowercase_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        gui_set_multitap_input_callbacks(&MMI_greek_uppercase_multitaps[i], input_callback, input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_greek_lowercase_multitaps[i], input_callback, input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        gui_set_multitap_input_callbacks(
            &MMI_uppercase_numberless_multitaps[i],
            input_callback,
            input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_lowercase_numberless_multitaps[i],
            input_callback,
            input_complete_callback);
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  change_multitap_mode
 * DESCRIPTION
 *  Changes the current multitap mode
 * PARAMETERS
 *  mode        [IN]        Is the new multitap mode to use
 * RETURNS
 *  void
 *****************************************************************************/
void change_multitap_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_current_multitap_mode = mode;
}


/*****************************************************************************
 * FUNCTION
 *  register_multitap_key_handlers
 * DESCRIPTION
 *  Registers the key handlers for the multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multitap_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(multitap_input_key_up);
    register_key_down_handler(multitap_input_key_down);
}


/*****************************************************************************
 * FUNCTION
 *  register_multitap_no_draw_key_handlers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multitap_no_draw_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(multitap_input_key_up_no_draw);
    register_key_down_handler(multitap_input_key_down_no_draw);
}


/*****************************************************************************
 * FUNCTION
 *  register_multitap_no_draw_plus_post_process_key_handlers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multitap_no_draw_plus_post_process_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_MMI_key_input_handler();
    register_key_up_handler(multitap_input_key_up_no_draw);
    register_key_down_handler(multitap_input_key_down_no_draw_plus_post_process);
}


/*****************************************************************************
 * FUNCTION
 *  clear_multitap_key_handlers
 * DESCRIPTION
 *  Clears the key handlers used by the multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_multitap_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_MMI_key_input_handler();
}


/*****************************************************************************
 * FUNCTION
 *  register_hide_multitap
 * DESCRIPTION
 *  Registers the function used to hide the multitap indicators
 * PARAMETERS
 *  f       [IN]        Is the function that is called to hide a multitap indicator
 * RETURNS
 *  void
 *****************************************************************************/
void register_hide_multitap(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hide_multitap = f;
}


/*****************************************************************************
 * FUNCTION
 *  query_multitaps_state
 * DESCRIPTION
 *  Return multitap state. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL query_multitaps_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode = 0;
    U16 keytype = 0;
    MMI_BOOL multitap_state = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    switch (MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP)
            {
                multitap_state = MMI_TRUE;
            }
            break;
        case EDITOR_EMS_INPUT_BOX:
            if (MMI_EMS_inputbox.flags & UI_EMS_INPUT_BOX_STATE_MULTITAP)
            {
                multitap_state = MMI_TRUE;
            }
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
        case EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
            {
                multitap_state = MMI_TRUE;
            }
            break;
        case EDITOR_INLINE_TEXT:
            if (MMI_inline_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP)
            {
                multitap_state = MMI_TRUE;
            }
            break;
        default:
            break;
    }

    if (!multitap_state || keycode != MMI_active_multitap)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  reset_multitaps
 * DESCRIPTION
 *  Disables the multitaps, clears the key handlers used by
 *  the multitaps and clears the function used to hide the multitaps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_multitaps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_lock_double_buffer();

    /* phone number input is a special multitap state, hence, process it individually */
    if (MMI_current_input_type == INPUT_TYPE_PHONE_NUMBER)
    {
       wgui_inputbox_handle_multitap_input_complete(/*WGUI_INPUTBOX_EDIT_MULTITAP_ANY*/2);
    }
    else
    {
        if (!query_multitaps_state())
        {
            disable_active_multitap();
        }
        else
        {
        #if defined(__MMI_FULL_SCREEN_EDITOR__)
            gui_cancel_timer(disable_active_multitap_no_draw);    
        #else
            gui_cancel_timer(disable_active_multitap);    
        #endif
            MMI_EXIT_WITH_MULTITAP_STATE = MMI_TRUE;
        }
    }
    gui_unlock_double_buffer();

#if defined (__MMI_MULTITAP_THAI__)
    for (i = 0; i < MAX_MULTITAPS_THAI; i++)
    {
        gui_set_multitap_input_callbacks(&MMI_thai_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    }
#endif /* defined (__MMI_MULTITAP_THAI__) */ 
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        gui_set_multitap_input_callbacks(
            &MMI_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(&MMI_bpmf_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
        /* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_MULTITAP_SPANISH__)
        gui_set_multitap_input_callbacks(
            &MMI_spanish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_spanish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        gui_set_multitap_input_callbacks(
            &MMI_danish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_danish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        gui_set_multitap_input_callbacks(
            &MMI_polish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_polish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        gui_set_multitap_input_callbacks(
            &MMI_french_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_french_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        gui_set_multitap_input_callbacks(
            &MMI_german_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_german_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_italian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_italian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_russian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_russian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_bulgarian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_bulgarian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        gui_set_multitap_input_callbacks(
            &MMI_turkish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_turkish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        gui_set_multitap_input_callbacks(
            &MMI_portuguese_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_portuguese_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_HINDI__) 
        gui_set_multitap_input_callbacks(&MMI_hindi_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
    #if defined(__MMI_MULTITAP_MARATHI__) 
        gui_set_multitap_input_callbacks(&MMI_marathi_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
     #if defined(__MMI_MULTITAP_BENGALI__) 
        gui_set_multitap_input_callbacks(&MMI_bengali_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
     #if defined(__MMI_MULTITAP_TAMIL__) 
        gui_set_multitap_input_callbacks(&MMI_tamil_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
     #if defined(__MMI_MULTITAP_PUNJABI__) 
        gui_set_multitap_input_callbacks(&MMI_punjabi_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
     #if defined(__MMI_MULTITAP_TELUGU__) 
        gui_set_multitap_input_callbacks(&MMI_telugu_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 

    #if defined(__MMI_MULTITAP_INDONESIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_indonesian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_indonesian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        gui_set_multitap_input_callbacks(
            &MMI_czech_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_czech_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        gui_set_multitap_input_callbacks(
            &MMI_malay_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_malay_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        gui_set_multitap_input_callbacks(
            &MMI_vietnamese_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_vietnamese_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        gui_set_multitap_input_callbacks(
            &MMI_finnish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_finnish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_hungarian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_hungarian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        gui_set_multitap_input_callbacks(
            &MMI_swedish_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_swedish_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        gui_set_multitap_input_callbacks(&MMI_hebrew_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        gui_set_multitap_input_callbacks(
            &MMI_slovak_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_slovak_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        gui_set_multitap_input_callbacks(
            &MMI_dutch_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_dutch_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        /* Norwegian start */
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_norwegian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_norwegian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        /* Norwegian end */
    #if defined(__MMI_MULTITAP_ARABIC__)
        gui_set_multitap_input_callbacks(&MMI_arabic_multitaps[i], dummy_input_callback, dummy_input_complete_callback);
    #endif 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_persian_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
        //PMT END PERSIAN
//PMT START URDU 
    #if defined(__MMI_MULTITAP_URDU__)
		gui_set_multitap_input_callbacks(&MMI_urdu_multitaps[i],dummy_input_callback,dummy_input_complete_callback);
    #endif     
//PMT END URDU
    #if defined(__MMI_MULTITAP_CROATIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_croatian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_croatian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_romanian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_romanian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        gui_set_multitap_input_callbacks(
            &MMI_slovenian_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_slovenian_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        gui_set_multitap_input_callbacks(
            &MMI_greek_uppercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_greek_lowercase_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        gui_set_multitap_input_callbacks(
            &MMI_uppercase_numberless_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
        gui_set_multitap_input_callbacks(
            &MMI_lowercase_numberless_multitaps[i],
            dummy_input_callback,
            dummy_input_complete_callback);
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    }
    clear_MMI_key_input_handler();
    clear_key_up_handler();
    clear_key_down_handler();
    hide_multitap = UI_dummy_function;
}

extern S32 MMI_button_bar_height;


/*****************************************************************************
 * FUNCTION
 *  set_MMI_multitap_theme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_MMI_multitap_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fh, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_set_font(current_UI_theme->multitap_input_theme->text_font);

    fh = Get_CharHeightOfAllLang(current_UI_theme->multitap_input_theme->text_font->size);

    if (fh + 3 > MMI_MULTITAP_HEIGHT)
        MMI_multitap_height = fh + 3;
    else
        MMI_multitap_height = MMI_MULTITAP_HEIGHT;
    MMI_multitap_y = (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT- MMI_multitap_height);
    
    for (i = 0; i < MAX_MULTITAPS; i++)
    {
        gui_set_multitap_input_current_theme(&MMI_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_lowercase_multitaps[i]);
        MMI_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_uppercase_multitaps[i], MMI_uppercase_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_uppercase_multitaps[i], MMI_uppercase_multitaps[i].x, MMI_multitap_y);
        gui_resize_multitap_input(&MMI_lowercase_multitaps[i], MMI_lowercase_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_lowercase_multitaps[i], MMI_lowercase_multitaps[i].x, MMI_multitap_y);

        /* PMT dara added for Multitap thai */
    #if defined (__MMI_MULTITAP_THAI__)
        gui_set_multitap_input_current_theme(&MMI_thai_multitaps[i]);
        MMI_thai_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_thai_multitaps[i], MMI_thai_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_thai_multitaps[i], MMI_thai_multitaps[i].x, MMI_multitap_y);
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 
        /* MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_MULTITAP_SPANISH__)
        gui_set_multitap_input_current_theme(&MMI_spanish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_spanish_lowercase_multitaps[i]);
        MMI_spanish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_spanish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_spanish_uppercase_multitaps[i],
            MMI_spanish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_spanish_uppercase_multitaps[i],
            MMI_spanish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_spanish_lowercase_multitaps[i],
            MMI_spanish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_spanish_lowercase_multitaps[i],
            MMI_spanish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        gui_set_multitap_input_current_theme(&MMI_danish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_danish_lowercase_multitaps[i]);
        MMI_danish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_danish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_danish_uppercase_multitaps[i],
            MMI_danish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_danish_uppercase_multitaps[i],
            MMI_danish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_danish_lowercase_multitaps[i],
            MMI_danish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_danish_lowercase_multitaps[i],
            MMI_danish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        gui_set_multitap_input_current_theme(&MMI_polish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_polish_lowercase_multitaps[i]);
        MMI_polish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_polish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_polish_uppercase_multitaps[i],
            MMI_polish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_polish_uppercase_multitaps[i],
            MMI_polish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_polish_lowercase_multitaps[i],
            MMI_polish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_polish_lowercase_multitaps[i],
            MMI_polish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        gui_set_multitap_input_current_theme(&MMI_french_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_french_lowercase_multitaps[i]);
        MMI_french_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_french_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_french_uppercase_multitaps[i],
            MMI_french_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_french_uppercase_multitaps[i],
            MMI_french_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_french_lowercase_multitaps[i],
            MMI_french_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_french_lowercase_multitaps[i],
            MMI_french_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        gui_set_multitap_input_current_theme(&MMI_german_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_german_lowercase_multitaps[i]);
        MMI_german_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_german_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_german_uppercase_multitaps[i],
            MMI_german_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_german_uppercase_multitaps[i],
            MMI_german_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_german_lowercase_multitaps[i],
            MMI_german_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_german_lowercase_multitaps[i],
            MMI_german_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        gui_set_multitap_input_current_theme(&MMI_italian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_italian_lowercase_multitaps[i]);
        MMI_italian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_italian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_italian_uppercase_multitaps[i],
            MMI_italian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_italian_uppercase_multitaps[i],
            MMI_italian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_italian_lowercase_multitaps[i],
            MMI_italian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_italian_lowercase_multitaps[i],
            MMI_italian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        gui_set_multitap_input_current_theme(&MMI_russian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_russian_lowercase_multitaps[i]);
        MMI_russian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_russian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_russian_uppercase_multitaps[i],
            MMI_russian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_russian_uppercase_multitaps[i],
            MMI_russian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_russian_lowercase_multitaps[i],
            MMI_russian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_russian_lowercase_multitaps[i],
            MMI_russian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        gui_set_multitap_input_current_theme(&MMI_bulgarian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_bulgarian_lowercase_multitaps[i]);
        MMI_bulgarian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_bulgarian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_bulgarian_uppercase_multitaps[i],
            MMI_bulgarian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_bulgarian_uppercase_multitaps[i],
            MMI_bulgarian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_bulgarian_lowercase_multitaps[i],
            MMI_bulgarian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_bulgarian_lowercase_multitaps[i],
            MMI_bulgarian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        gui_set_multitap_input_current_theme(&MMI_UKRAINIAN_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_UKRAINIAN_lowercase_multitaps[i]);
        MMI_UKRAINIAN_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_UKRAINIAN_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            MMI_UKRAINIAN_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_UKRAINIAN_uppercase_multitaps[i],
            MMI_UKRAINIAN_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            MMI_UKRAINIAN_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_UKRAINIAN_lowercase_multitaps[i],
            MMI_UKRAINIAN_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */
    #if defined(__MMI_MULTITAP_TURKISH__)
        gui_set_multitap_input_current_theme(&MMI_turkish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_turkish_lowercase_multitaps[i]);
        MMI_turkish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_turkish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_turkish_uppercase_multitaps[i],
            MMI_turkish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_turkish_uppercase_multitaps[i],
            MMI_turkish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_turkish_lowercase_multitaps[i],
            MMI_turkish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_turkish_lowercase_multitaps[i],
            MMI_turkish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        gui_set_multitap_input_current_theme(&MMI_portuguese_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_portuguese_lowercase_multitaps[i]);
        MMI_portuguese_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_portuguese_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_portuguese_uppercase_multitaps[i],
            MMI_portuguese_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_portuguese_uppercase_multitaps[i],
            MMI_portuguese_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_portuguese_lowercase_multitaps[i],
            MMI_portuguese_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_portuguese_lowercase_multitaps[i],
            MMI_portuguese_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        gui_set_multitap_input_current_theme(&MMI_indonesian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_indonesian_lowercase_multitaps[i]);
        MMI_indonesian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_indonesian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_indonesian_uppercase_multitaps[i],
            MMI_indonesian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_indonesian_uppercase_multitaps[i],
            MMI_indonesian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_indonesian_lowercase_multitaps[i],
            MMI_indonesian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_indonesian_lowercase_multitaps[i],
            MMI_indonesian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        gui_set_multitap_input_current_theme(&MMI_czech_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_czech_lowercase_multitaps[i]);
        MMI_czech_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_czech_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_czech_uppercase_multitaps[i],
            MMI_czech_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_czech_uppercase_multitaps[i], MMI_czech_uppercase_multitaps[i].x, MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_czech_lowercase_multitaps[i],
            MMI_czech_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_czech_lowercase_multitaps[i], MMI_czech_lowercase_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 
    #if defined(__MMI_MULTITAP_MALAY__)
        gui_set_multitap_input_current_theme(&MMI_malay_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_malay_lowercase_multitaps[i]);
        MMI_malay_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_malay_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_malay_uppercase_multitaps[i],
            MMI_malay_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_malay_uppercase_multitaps[i], MMI_malay_uppercase_multitaps[i].x, MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_malay_lowercase_multitaps[i],
            MMI_malay_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_malay_lowercase_multitaps[i], MMI_malay_lowercase_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_HINDI__) 
        gui_set_multitap_input_current_theme(&MMI_hindi_multitaps[i]);
        MMI_hindi_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_hindi_multitaps[i], MMI_hindi_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_hindi_multitaps[i], MMI_hindi_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_HINDI__)  */ 
    #if defined(__MMI_MULTITAP_MARATHI__) 
        gui_set_multitap_input_current_theme(&MMI_marathi_multitaps[i]);
        MMI_marathi_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_marathi_multitaps[i], MMI_marathi_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_marathi_multitaps[i], MMI_marathi_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_MARATHI__)  */ 
	#if defined (__MMI_MULTITAP_TAMIL__) 
        gui_set_multitap_input_current_theme(&MMI_tamil_multitaps[i]);
        MMI_tamil_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_tamil_multitaps[i], MMI_tamil_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_tamil_multitaps[i], MMI_tamil_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_TAMIL__)  */ 

    #if defined(__MMI_MULTITAP_BENGALI__) 
        gui_set_multitap_input_current_theme(&MMI_bengali_multitaps[i]);
        MMI_bengali_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_bengali_multitaps[i], MMI_bengali_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_bengali_multitaps[i], MMI_bengali_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_MARATHI__) */ 

	#if defined (__MMI_MULTITAP_PUNJABI__) 
        gui_set_multitap_input_current_theme(&MMI_punjabi_multitaps[i]);
        MMI_punjabi_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_punjabi_multitaps[i], MMI_punjabi_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_punjabi_multitaps[i], MMI_punjabi_multitaps[i].x, MMI_multitap_y);
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        gui_set_multitap_input_current_theme(&MMI_telugu_multitaps[i]);
        MMI_telugu_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_telugu_multitaps[i], MMI_telugu_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_telugu_multitaps[i], MMI_telugu_multitaps[i].x, MMI_multitap_y);
    #endif
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        gui_set_multitap_input_current_theme(&MMI_vietnamese_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_vietnamese_lowercase_multitaps[i]);
        MMI_vietnamese_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_vietnamese_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_vietnamese_uppercase_multitaps[i],
            MMI_vietnamese_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_vietnamese_uppercase_multitaps[i],
            MMI_vietnamese_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_vietnamese_lowercase_multitaps[i],
            MMI_vietnamese_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_vietnamese_lowercase_multitaps[i],
            MMI_vietnamese_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        gui_set_multitap_input_current_theme(&MMI_finnish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_finnish_lowercase_multitaps[i]);
        MMI_finnish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_finnish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_finnish_uppercase_multitaps[i],
            MMI_finnish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_finnish_uppercase_multitaps[i],
            MMI_finnish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_finnish_lowercase_multitaps[i],
            MMI_finnish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_finnish_lowercase_multitaps[i],
            MMI_finnish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        gui_set_multitap_input_current_theme(&MMI_hungarian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_hungarian_lowercase_multitaps[i]);
        MMI_hungarian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_hungarian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_hungarian_uppercase_multitaps[i],
            MMI_hungarian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_hungarian_uppercase_multitaps[i],
            MMI_hungarian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_hungarian_lowercase_multitaps[i],
            MMI_hungarian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_hungarian_lowercase_multitaps[i],
            MMI_hungarian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        gui_set_multitap_input_current_theme(&MMI_swedish_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_swedish_lowercase_multitaps[i]);
        MMI_swedish_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_swedish_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_swedish_uppercase_multitaps[i],
            MMI_swedish_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_swedish_uppercase_multitaps[i],
            MMI_swedish_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_swedish_lowercase_multitaps[i],
            MMI_swedish_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_swedish_lowercase_multitaps[i],
            MMI_swedish_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        gui_set_multitap_input_current_theme(&MMI_hebrew_multitaps[i]);
        MMI_hebrew_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_hebrew_multitaps[i], MMI_hebrew_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_hebrew_multitaps[i], MMI_hebrew_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        gui_set_multitap_input_current_theme(&MMI_slovak_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_slovak_lowercase_multitaps[i]);
        MMI_slovak_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_slovak_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_slovak_uppercase_multitaps[i],
            MMI_slovak_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_slovak_uppercase_multitaps[i],
            MMI_slovak_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_slovak_lowercase_multitaps[i],
            MMI_slovak_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_slovak_lowercase_multitaps[i],
            MMI_slovak_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        gui_set_multitap_input_current_theme(&MMI_dutch_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_dutch_lowercase_multitaps[i]);
        MMI_dutch_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_dutch_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_dutch_uppercase_multitaps[i],
            MMI_dutch_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_dutch_uppercase_multitaps[i], MMI_dutch_uppercase_multitaps[i].x, MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_dutch_lowercase_multitaps[i],
            MMI_dutch_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_dutch_lowercase_multitaps[i], MMI_dutch_lowercase_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        /* Norwegian start */
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        gui_set_multitap_input_current_theme(&MMI_norwegian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_norwegian_lowercase_multitaps[i]);
        MMI_norwegian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_norwegian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_norwegian_uppercase_multitaps[i],
            MMI_norwegian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_norwegian_uppercase_multitaps[i],
            MMI_norwegian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_norwegian_lowercase_multitaps[i],
            MMI_norwegian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_norwegian_lowercase_multitaps[i],
            MMI_norwegian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        /* Norwegian end */
    #if defined(__MMI_MULTITAP_ARABIC__)
        gui_set_multitap_input_current_theme(&MMI_arabic_multitaps[i]);
        MMI_arabic_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_arabic_multitaps[i], MMI_arabic_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_arabic_multitaps[i], MMI_arabic_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        /* PMT START PERSIAN */
    #if defined(__MMI_MULTITAP_PERSIAN__)
        gui_set_multitap_input_current_theme(&MMI_persian_multitaps[i]);
        MMI_persian_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_persian_multitaps[i], MMI_persian_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_persian_multitaps[i], MMI_persian_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
        //PMT END PERSIAN
//PMT START URDU 
#if defined(__MMI_MULTITAP_URDU__)
		gui_set_multitap_input_current_theme(&MMI_urdu_multitaps[i]);
		MMI_urdu_multitaps[i].flags|=UI_MULTITAP_INPUT_CENTER_Y|UI_MULTITAP_INPUT_CENTER_X;
		gui_resize_multitap_input(&MMI_urdu_multitaps[i],MMI_urdu_multitaps[i].width,MMI_multitap_height);
		gui_move_multitap_input(&MMI_urdu_multitaps[i],MMI_urdu_multitaps[i].x,MMI_multitap_y);
#endif
//PMT END URDU
    #if defined(__MMI_MULTITAP_CROATIAN__)
        gui_set_multitap_input_current_theme(&MMI_croatian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_croatian_lowercase_multitaps[i]);
        MMI_croatian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_croatian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_croatian_uppercase_multitaps[i],
            MMI_croatian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_croatian_uppercase_multitaps[i],
            MMI_croatian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_croatian_lowercase_multitaps[i],
            MMI_croatian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_croatian_lowercase_multitaps[i],
            MMI_croatian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        gui_set_multitap_input_current_theme(&MMI_romanian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_romanian_lowercase_multitaps[i]);
        MMI_romanian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_romanian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_romanian_uppercase_multitaps[i],
            MMI_romanian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_romanian_uppercase_multitaps[i],
            MMI_romanian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_romanian_lowercase_multitaps[i],
            MMI_romanian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_romanian_lowercase_multitaps[i],
            MMI_romanian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        gui_set_multitap_input_current_theme(&MMI_slovenian_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_slovenian_lowercase_multitaps[i]);
        MMI_slovenian_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_slovenian_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_slovenian_uppercase_multitaps[i],
            MMI_slovenian_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_slovenian_uppercase_multitaps[i],
            MMI_slovenian_uppercase_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_slovenian_lowercase_multitaps[i],
            MMI_slovenian_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_slovenian_lowercase_multitaps[i],
            MMI_slovenian_lowercase_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        gui_set_multitap_input_current_theme(&MMI_greek_uppercase_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_greek_lowercase_multitaps[i]);
        MMI_greek_uppercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_greek_lowercase_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_greek_uppercase_multitaps[i],
            MMI_greek_uppercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_greek_uppercase_multitaps[i], MMI_greek_uppercase_multitaps[i].x, MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_greek_lowercase_multitaps[i],
            MMI_greek_lowercase_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(&MMI_greek_lowercase_multitaps[i], MMI_greek_lowercase_multitaps[i].x, MMI_multitap_y);
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
        //MTK Elvis to add bpmf multitap window
        gui_set_multitap_input_current_theme(&MMI_bpmf_multitaps[i]);
        MMI_bpmf_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_bpmf_multitaps[i], MMI_bpmf_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_bpmf_multitaps[i], MMI_bpmf_multitaps[i].x, MMI_multitap_y);
        /* MTK end */
    #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        gui_set_multitap_input_current_theme(&MMI_uppercase_numberless_multitaps[i]);
        gui_set_multitap_input_current_theme(&MMI_lowercase_numberless_multitaps[i]);
        MMI_uppercase_numberless_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        MMI_lowercase_numberless_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(
            &MMI_uppercase_numberless_multitaps[i],
            MMI_uppercase_numberless_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_uppercase_numberless_multitaps[i],
            MMI_uppercase_numberless_multitaps[i].x,
            MMI_multitap_y);
        gui_resize_multitap_input(
            &MMI_lowercase_numberless_multitaps[i],
            MMI_lowercase_numberless_multitaps[i].width,
            MMI_multitap_height);
        gui_move_multitap_input(
            &MMI_lowercase_numberless_multitaps[i],
            MMI_lowercase_numberless_multitaps[i].x,
            MMI_multitap_y);
    #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 
    }
    /* PMT dara added for Multitap thai */
#if defined(__MMI_MULTITAP_THAI__)
    for (i = 0; i < MAX_MULTITAPS_THAI; i++)
    {
        gui_set_multitap_input_current_theme(&MMI_thai_multitaps[i]);
        MMI_thai_multitaps[i].flags |= UI_MULTITAP_INPUT_CENTER_Y | UI_MULTITAP_INPUT_CENTER_X;
        gui_resize_multitap_input(&MMI_thai_multitaps[i], MMI_thai_multitaps[i].width, MMI_multitap_height);
        gui_move_multitap_input(&MMI_thai_multitaps[i], MMI_thai_multitaps[i].x, MMI_multitap_y);
    }
#endif /* defined(__MMI_MULTITAP_THAI__) */ 
}

/* single line input box wrappers         */

void (*singleline_inputbox_input_callback) (void) = UI_dummy_function;
void (*singleline_inputbox_navigate_callback) (void) = UI_dummy_function;
single_line_input_box MMI_singleline_inputbox;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
S32 wgui_singleline_inputbox_frame_counter = 0;
#endif 


/*****************************************************************************
 * FUNCTION
 *  create_singleline_inputbox
 * DESCRIPTION
 *  Creates a singleline inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void create_singleline_inputbox(UI_string_type buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_input_callback = UI_dummy_function;
    singleline_inputbox_navigate_callback = UI_dummy_function;
    gui_create_single_line_input_box_use_buffer(
        &MMI_singleline_inputbox,
        MMI_singleline_inputbox_x,
        MMI_singleline_inputbox_y,
        MMI_singleline_inputbox_width,
        MMI_singleline_inputbox_height,
        buffer,
        buffer_length);
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    wgui_singleline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  create_singleline_inputbox_set_buffer
 * DESCRIPTION
 *  Creates a singleline inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void create_singleline_inputbox_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_input_callback = UI_dummy_function;
    singleline_inputbox_navigate_callback = UI_dummy_function;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_single_line_input_box_set_buffer(
        &MMI_singleline_inputbox,
        MMI_singleline_inputbox_x,
        MMI_singleline_inputbox_y,
        MMI_singleline_inputbox_width,
        MMI_singleline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_single_line_input_box_set_buffer(
        &MMI_singleline_inputbox,
        MMI_singleline_inputbox_x,
        MMI_singleline_inputbox_y,
        MMI_singleline_inputbox_width,
        MMI_singleline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    wgui_singleline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  show_singleline_inputbox
 * DESCRIPTION
 *  Displays the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_singleline_inputbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_single_line_input_box(&MMI_singleline_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_singleline_inputbox.x,
        MMI_singleline_inputbox.y,
        MMI_singleline_inputbox.x + MMI_singleline_inputbox.width,
        MMI_singleline_inputbox.y + MMI_singleline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_singleline_inputbox_end_frame
 * DESCRIPTION
 *  Redraws the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))

void wgui_singleline_inputbox_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_singleline_inputbox_frame_counter >= 1)
    {
        S32 y2, BLT_y2;

        gui_show_single_line_input_box(&MMI_singleline_inputbox);
        BLT_y2 = MMI_singleline_inputbox.y + MMI_singleline_inputbox.height;
        y2 = MMI_multitap_y + MMI_multitap_height + 1;
        if (BLT_y2 < y2)
        {
            BLT_y2 = y2;
        }
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_singleline_inputbox.x,
            MMI_singleline_inputbox.y,
            MMI_singleline_inputbox.x + MMI_singleline_inputbox.width,
            BLT_y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_singleline_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_singleline_inputbox_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  redraw_singleline_inputbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_singleline_inputbox(void)
{
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
    if (GetExitScrnID() != POPUP_SCREENID)
    {
#endif /* __MMI_POPUP_REACH_MAX_LENGTH_MSG__ */ 
        if (wgui_singleline_inputbox_frame_counter > 0)
        {
            wgui_singleline_inputbox_frame_counter++;
        }
        else
        {
            wgui_singleline_inputbox_frame_counter = 1;
            gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_singleline_inputbox_end_frame);
        }
    #ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
    }
    #endif 
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 

#ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
    if (GetExitScrnID() != POPUP_SCREENID)
    {
#endif /* __MMI_POPUP_REACH_MAX_LENGTH_MSG__ */ 
        gui_show_single_line_input_box(&MMI_singleline_inputbox);
    #ifdef __MMI_POPUP_REACH_MAX_LENGTH_MSG__
    }
    #endif 
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_singleline_inputbox.x,
        MMI_singleline_inputbox.y,
        MMI_singleline_inputbox.x + MMI_singleline_inputbox.width,
        MMI_singleline_inputbox.y + MMI_singleline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_multitap_input
 * DESCRIPTION
 *  Inserts a multitap character
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((MMI_singleline_inputbox.text[0] == '+') &&
            (MMI_singleline_inputbox.current_text_p == MMI_singleline_inputbox.text) &&
            (MMI_singleline_inputbox.text_length >= (MMI_singleline_inputbox.available_length - ENCODING_LENGTH)))
        {
            return;
        }
    }
    gui_single_line_input_box_insert_multitap_character(&MMI_singleline_inputbox, c);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_confirm_multitap_character(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_direct_input
 * DESCRIPTION
 *  inserts a character at cursor position
 *  
 *  Normally registered to a keyboard input handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((MMI_singleline_inputbox.text[0] == '+') &&
            (MMI_singleline_inputbox.current_text_p == MMI_singleline_inputbox.text) &&
            (MMI_singleline_inputbox.text_length >= (MMI_singleline_inputbox.available_length - ENCODING_LENGTH)))
        {
            return;
        }
    }
    gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, c);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_delete_character
 * DESCRIPTION
 *  deletes a character at cursor position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 inPinyinSearchScreen;

void singleline_inputbox_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_previous(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        redraw_input_mode_only();
        menu_shortcut_handler_display = 1;
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
    singleline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_next(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        redraw_input_mode_only();
        menu_shortcut_handler_display = 1;
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
    singleline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_toggle_insert_mode(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_delete_current_character(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
    redraw_singleline_inputbox();
    singleline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  alphanumeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc > 0x1f)
    {
        singleline_inputbox_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        singleline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        singleline_inputbox_delete_all_characters();
    }
    else if (keyc == 0x0d);
}

#if defined(__MMI_MULTITAP_ARABIC__)

/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_arabic_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        singleline_inputbox_direct_input((UI_character_type)( keyc + 0x0630));
    }
    else if (keyc == 0x08)
    {
        singleline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        singleline_inputbox_delete_all_characters();
    }
}

#endif 

/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
 void singleline_inputbox_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        singleline_inputbox_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        singleline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        singleline_inputbox_delete_all_characters();
    }
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_handle_key_down
 * DESCRIPTION
 *  Keypad Key down handler
 *  
 *  Internal function
 * PARAMETERS
 *  k           [IN]        
 *  keyc(?)     [IN]        Is the keypad key code.
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Elvis 20040104 */
void singleline_inputbox_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_ARABIC__)
    if (MMI_current_input_mode == INPUT_MODE_ARABIC_NUMERIC ||MMI_current_input_mode == INPUT_MODE_MMI_ARABIC_NUMERIC )
        singleline_inputbox_direct_input((UI_character_type) (0x0660 + k));
    else
#endif
    singleline_inputbox_direct_input((UI_character_type) ('0' + k));
#ifdef __MMI_PINYIN_SEARCH__
    if (inPinyinSearchScreen)
    {
        PbookListSearchEntryReq();
        redraw_input_mode_only();
    }
#endif /* __MMI_PINYIN_SEARCH__ */ 
}

/* MTK end */

/* MTK Elvis to add some APIs for Qsearch */


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_handle_stroke_key_down
 * DESCRIPTION
 *  Keypad Key down handler
 *  
 *  Internal function
 * PARAMETERS
 *  k           [IN]        
 *  keyc(?)     [IN]        Is the keypad key code.
 * RETURNS
 *  void
 *****************************************************************************/
/* Elvis, for quick search */
extern S32(*cat200_search_function) (U8 *);
extern void refresh_search_list(U8 *name);
void singleline_inputbox_handle_stroke_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (k)
    {
            /* MTK Terry for iTap eZi stroke quick search */
    #if defined(__MMI_T9__)
        case KEY_1:
            k = 0xF004;
            break;
        case KEY_2:
            k = 0xF001;
            break;
        case KEY_3:
            k = 0xF007;
            break;
        case KEY_4:
            k = 0xF002;
            break;
        case KEY_5:
            k = 0xF005;
            break;
        default:
            k = 0xF004;
            break;
    #elif defined(__MMI_ZI__)
        case KEY_1:
            k = ZI8_CODE_OVER;
            break;
        case KEY_2:
            k = ZI8_CODE_DOWN;
            break;
        case KEY_3:
            k = ZI8_CODE_LEFT;
            break;
        case KEY_4:
            k = ZI8_CODE_DOT;
            break;
        case KEY_5:
            k = ZI8_CODE_OVER_DOWN;
            break;
        case KEY_6:
            k = ZI8_CODE_CURVED_HOOK;
            break;
        case KEY_7:
            k = ZI8_CODE_DOWN_OVER;
            break;
        case KEY_9:
            k = ZI8_CODE_OVER_DOWN_OVER;
            break;
        default:
            k = ZI8_CODE_WILDCARD;
            break;
    #elif defined(__MMI_CSTAR__)
        case KEY_1:
            k = 0xF004;
            break;
        case KEY_2:
            k = 0xF001;
            break;
        case KEY_3:
            k = 0xF007;
            break;
        case KEY_4:
            k = 0xF002;
            break;
        case KEY_5:
            k = 0xF005;
            break;
        default:
            k = 0xF004;
            break;
    #elif defined(__MMI_ITAP__)
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
    }
    singleline_inputbox_direct_input((UI_character_type) (k));
    /* Elvis, for quick search */
    if (cat200_search_function)
    {
        refresh_search_list(MMI_singleline_inputbox.text);
    }
}


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_handle_numeric_key_down
 * DESCRIPTION
 *  Keypad Key down handler
 *  
 *  Internal function
 * PARAMETERS
 *  k           [IN]        
 *  keyc(?)     [IN]        Is the keypad key code.
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_handle_numeric_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_ARABIC__)
    if (MMI_current_input_mode == INPUT_MODE_ARABIC_NUMERIC || MMI_current_input_mode == INPUT_MODE_MMI_ARABIC_NUMERIC)
        singleline_inputbox_direct_input((UI_character_type) (0x0660 + k));
    else
#endif
    singleline_inputbox_direct_input((UI_character_type) ('0' + k));
    /* Elvis, for quick search */
    if (cat200_search_function)
    {
        refresh_search_list(MMI_singleline_inputbox.text);
    }
}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  change_singleline_inputbox_mode
 * DESCRIPTION
 *  Changes the input mode of the singleline inputbox
 * PARAMETERS
 *  mode        [IN]        0: Uppercase, 1: lowercase, 2: Numeric
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Elvis 20040104 */
void change_singleline_inputbox_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 input_type = MMI_current_input_type & INPUT_TYPE_MASK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mode)
    {
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ABC);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ABC);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_123:
            change_multitap_mode(INPUT_MODE_123);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_key_down);
            register_keyboard_input_handler(singleline_inputbox_numeric_keyboard_input_handler);
            wgui_set_singleline_RSK();

            break;

            /* PMT dara added for Multitap thai */
    #if defined (__MMI_MULTITAP_THAI__)
        case INPUT_MODE_MULTITAP_THAI:
            change_multitap_mode(INPUT_MODE_MULTITAP_THAI);
            /* change_inputbox_type_multitapthai(SINGLELINE_INPUTBOX); */
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 
        #if defined(__MMI_MULTITAP_THAI_PROFILE_1__)
            register_MMI_key_input_extend_handler();    /* msz065_20050418 */
        #endif
            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 
            //MTK Add By Elvis for T9
            //MTK Terry for Spanish French German Italian Russian Turkish Portuguese Indonesian Malay Vietnamese
    #if defined(__MMI_MULTITAP_SPANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SPANISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SPANISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
            /* PMT VIKASG START 20050729 */
    #if defined(__MMI_MULTITAP_DANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_DANISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_DANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_DANISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_POLISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_POLISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_POLISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_POLISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FRENCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_FRENCH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_FRENCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_FRENCH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GERMAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_GERMAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_GERMAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_GERMAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_TURKISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_TURKISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_TURKISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_TURKISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CZECH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_CZECH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_CZECH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_CZECH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 

    #if defined(__MMI_MULTITAP_MALAY__)
        case INPUT_MODE_MULTITAP_UPPERCASE_MALAY:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_MALAY);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_MALAY:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_MALAY);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FINNISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_FINNISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_FINNISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_FINNISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 

    #if defined(__MMI_MULTITAP_HEBREW__)
        case INPUT_MODE_MULTITAP_HEBREW:
            change_multitap_mode(INPUT_MODE_MULTITAP_HEBREW);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 
            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DUTCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_DUTCH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_DUTCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_DUTCH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
    #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_MULTITAP_ARABIC:
            change_multitap_mode(INPUT_MODE_MULTITAP_ARABIC);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 

    #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_ARABIC_NUMERIC:
            change_multitap_mode(INPUT_MODE_ARABIC_NUMERIC);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_key_down);
            register_keyboard_input_handler(singleline_inputbox_arabic_numeric_keyboard_input_handler);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */

    #if defined(__MMI_MULTITAP_PERSIAN__)
        case INPUT_MODE_MULTITAP_PERSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_PERSIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
#if defined(__MMI_MULTITAP_URDU__)
		case INPUT_MODE_MULTITAP_URDU:
		change_multitap_mode(INPUT_MODE_MULTITAP_URDU);
                #ifdef __MMI_PINYIN_SEARCH__
                register_multitap_no_draw_plus_post_process_key_handlers();
                #else
		register_multitap_key_handlers();
                #endif

	        register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
		set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete);
		wgui_set_singleline_RSK();
		break;
#endif
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_CROATIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GREEK:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_GREEK);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_GREEK:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_GREEK);
    #ifdef __MMI_PINYIN_SEARCH__
            register_multitap_no_draw_plus_post_process_key_handlers();
    #else 
            register_multitap_key_handlers();
    #endif 

            register_keyboard_input_handler(singleline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(singleline_inputbox_multitap_input, singleline_inputbox_multitap_input_complete);
            wgui_set_singleline_RSK();

            break;
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
    #ifdef __MMI_T9__
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
            /* PMT dara added for T9 thai */
    #if defined (__MMI_T9_THAI__)
        case INPUT_MODE_SMART_THAI:
    #endif 
            /* MTK Terry for Spanish French German Italian */
    #if defined(__MMI_T9_SPANISH__)
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
    #endif /* defined(__MMI_T9_SPANISH__) */ 
            /* PMT VIKASG START 20050729 */
    #if defined(__MMI_T9_DANISH__)
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
        case INPUT_MODE_SMART_LOWERCASE_DANISH:
    #endif /* defined(__MMI_T9_DANISH__) */ 
    #if defined(__MMI_T9_POLISH__)
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
        case INPUT_MODE_SMART_LOWERCASE_POLISH:
    #endif /* defined(__MMI_T9_POLISH__) */ 
    #if defined(__MMI_T9_FRENCH__)
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
    #endif /* defined(__MMI_T9_FRENCH__) */ 
    #if defined(__MMI_T9_GERMAN__)
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
    #endif /* defined(__MMI_T9_GERMAN__) */ 
    #if defined(__MMI_T9_ITALIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
    #endif /* defined(__MMI_T9_ITALIAN__) */ 
    #if defined(__MMI_T9_RUSSIAN__)
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
    #endif /* defined(__MMI_T9_RUSSIAN__) */ 
    #if defined(__MMI_T9_BULGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
    #endif /* defined(__MMI_T9_BULGARIAN__) */ 

    #if defined(__MMI_T9_VIETNAMESE__)
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
    #endif /* defined(__MMI_T9_VIETNAMESE__) */ 

    #if defined(__MMI_T9_TURKISH__)
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
    #endif /* defined(__MMI_T9_TURKISH__) */ 

    #if defined(__MMI_T9_PORTUGUESE__)
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
    #endif /* defined(__MMI_T9_PORTUGUESE__) */ 
    #if defined(__MMI_T9_FINNISH__)
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
    #endif /* defined(__MMI_T9_FINNISH__) */ 
    #if defined(__MMI_T9_HUNGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
    #endif /* defined(__MMI_T9_HUNGARIAN__) */ 
    #if defined(__MMI_T9_ARABIC__)
        case INPUT_MODE_SMART_ARABIC:
    #endif 
    #if defined(__MMI_T9_GREEK__)
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
        case INPUT_MODE_SMART_LOWERCASE_GREEK:
    #endif /* defined(__MMI_T9_GREEK__) */ 
    #if defined(__MMI_T9_HEBREW__)
        case INPUT_MODE_SMART_HEBREW:
    #endif 
/*PMT IRE START*/
    #if defined(__MMI_T9_HINDI__) 
/*PMT IRE END*/
        case INPUT_MODE_SMART_HINDI:
    #endif 
    #if defined(__MMI_T9_NORWEGIAN__)
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
    #endif /* defined(__MMI_T9_NORWEGIAN__) */ 
    #if defined(__MMI_T9_DUTCH__)
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
    #endif /* defined(__MMI_T9_DUTCH__) */ 
    #if defined(__MMI_T9_SLOVENIAN__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
    #endif /* defined(__MMI_T9_SLOVENIAN__) */ 
    #if defined(__MMI_T9_SWEDISH__)
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
    #endif /* defined(__MMI_T9_SWEDISH__) */ 
    #if defined(__MMI_T9_MALAY__)
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
        case INPUT_MODE_SMART_LOWERCASE_MALAY:
    #endif /* defined(__MMI_T9_MALAY__) */ 
    #if defined(__MMI_T9_CROATIAN__)
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
    #endif /* defined(__MMI_T9_CROATIAN__) */ 
    #if defined(__MMI_T9_SLOVAK__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
    #endif /* defined(__MMI_T9_SLOVAK__) */ 
    #if defined(__MMI_T9_ROMANIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
    #endif /* defined(__MMI_T9_ROMANIAN__) */ 
            T9ChangeLanguageMultilineInputBox(mode);
            T9ClearKeyStarAndPoundHandler();
            T9ClearKeyNavigationHandler();
            
            // MBJ hongyu guo 2007/3/30 added for crash issue
            T9ClearKey0To9Handler();
            // MBJ end

            clear_right_softkey();
            /* clear_left_softkey(); */
            clear_multitap_key_handlers();
            /* register_MMI_key_input_handler(); */
            // SetKeyHandler(wgui_handle_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
            //SetKeyHandler(T9KeyStarPressHandlerMultilineInputBox,KEY_STAR,KEY_EVENT_UP);
            //set key arrow handler
            SetKeyHandler(T9KeyArrowUPHandlerMultilineInputBox, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(T9KeyArrowRightHandlerMultilineInputBox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(T9KeyArrowDownHandlerMultilineInputBox, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(T9KeyArrowLeftHandlerMultilineInputBox, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* register_key_down_handler(T9Key0To9HandlerMultilineInputBox); */
            SetKeyHandler(T9Key0PressHandlerMultilineInputBox, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key1PressHandlerMultilineInputBox, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key2PressHandlerMultilineInputBox, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key3PressHandlerMultilineInputBox, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key4PressHandlerMultilineInputBox, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key5PressHandlerMultilineInputBox, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key6PressHandlerMultilineInputBox, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key7PressHandlerMultilineInputBox, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key8PressHandlerMultilineInputBox, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key9PressHandlerMultilineInputBox, KEY_9, KEY_EVENT_DOWN);
            
            wgui_set_singleline_RSK();
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
            T9SynT9WithInputBoxMultilineInputBox();
            T9ScreenStateChnageMultilineInputBox();
            T9InputBoxDisplayMultilineInputBox();

    #elif defined __MMI_ZI__
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
            /* MTK Elvis multitap phonetic input mode */
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
            /* MTK end */
        case INPUT_MODE_SMART_THAI:
            /* MTK Terry for Russian Spanish French German Italian Turkish Portuguese Indonesian Malay Vietnamese */
    #if defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
    #endif /* defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 
            /* PMT START GR_HE_CZ_FI_DA_HU 20051007 */
    #if defined(__MMI_ZI_HEBREW__)
        case INPUT_MODE_SMART_HEBREW:
    #endif 
    #if defined(__MMI_ZI_DANISH__)
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
        case INPUT_MODE_SMART_LOWERCASE_DANISH:
    #endif /* defined(__MMI_ZI_DANISH__) */ 
    #if defined(__MMI_ZI_POLISH__)
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
        case INPUT_MODE_SMART_LOWERCASE_POLISH:
    #endif /* defined(__MMI_ZI_POLISH__) */ 
    #if defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__)
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
    #endif /* defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 
    #if defined(__MMI_ZI_GERMAN__)
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
    #endif /* defined(__MMI_ZI_GERMAN__) */ 
    #if defined(__MMI_ZI_ITALIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
    #endif /* defined(__MMI_ZI_ITALIAN__) */ 
    #if defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
    #endif /* defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) */ 
    #if defined(__MMI_ZI_BULGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
    #endif /* defined(__MMI_ZI_BULGARIAN__) */ 
    #if defined(__MMI_ZI_UKRAINIAN__)
        case INPUT_MODE_SMART_UPPERCASE_UKRAINIAN:
        case INPUT_MODE_SMART_LOWERCASE_UKRAINIAN:
    #endif /* defined(__MMI_ZI_UKRAINIAN__) */ 
    #if defined(__MMI_ZI_TURKISH__)
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
    #endif /* defined(__MMI_ZI_TURKISH__) */ 
    #if defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__)
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
    #endif /* defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) */ 
    #if defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__)
        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
    #endif /* defined(__MMI_ZI_INDONESIAN__) || defined(__MMI_T9_INDONESIAN__) */ 
    #if defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__)
        case INPUT_MODE_SMART_UPPERCASE_CZECH:
        case INPUT_MODE_SMART_LOWERCASE_CZECH:
    #endif /* defined(__MMI_T9_CZECH__) || defined(__MMI_ZI_CZECH__) */ 
    #if defined(__MMI_ZI_MALAY__)
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
        case INPUT_MODE_SMART_LOWERCASE_MALAY:
    #endif /* defined(__MMI_ZI_MALAY__) */ 
    #if defined(__MMI_ZI_VIETNAMESE__)
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
    #endif /* defined(__MMI_ZI_VIETNAMESE__) */ 
    #if defined(__MMI_ZI_SWEDISH__)
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
    #endif /* defined(__MMI_ZI_SWEDISH__) */ 
    #if defined(__MMI_ZI_SLOVAK__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
    #endif /* defined(__MMI_ZI_SLOVAK__) */ 
    #if defined(__MMI_ZI_DUTCH__)
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
    #endif /* defined(__MMI_ZI_DUTCH__) */ 
    #if defined(__MMI_ZI_CROATIAN__)
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
    #endif /* defined(__MMI_ZI_CROATIAN__) */ 
    #if defined(__MMI_ZI_ROMANIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
    #endif /* defined(__MMI_ZI_ROMANIAN__) */ 
    #if defined(__MMI_ZI_SLOVENIAN__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
    #endif /* defined(__MMI_ZI_SLOVENIAN__) */ 
    #if defined(__MMI_ZI_NORWEGIAN__)
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
    #endif /* defined(__MMI_ZI_NORWEGIAN__) */ 
    #if defined(__MMI_ZI_GREEK__)
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
        case INPUT_MODE_SMART_LOWERCASE_GREEK:
    #endif /* defined(__MMI_ZI_GREEK__) */ 
    #if defined(__MMI_ZI_FINNISH__)
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
    #endif /* defined(__MMI_ZI_FINNISH__) */ 
    #if defined(__MMI_ZI_HUNGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
    #endif /* defined(__MMI_ZI_HUNGARIAN__) */ 
        #ifdef __MMI_MIXED_LANG_SUPPORT__
            ZiChangeInputMethod((INPUT_MODE) mode, g_ime_sub_writing_lang);
        #else
            ZiChangeInputMethod((INPUT_MODE) mode);
        #endif
            ZiClearKeyStarAndPoundHandler();
            /* ZiClearKeyNavigationHandler(); */
            ZiClearArrowKeyLeftHandler();
            ZiClearArrowKeyRightHandler();
            ZiClearKey0To9Handler();
            clear_right_softkey();
            clear_left_softkey();
            //set key arrow handler
            //SetKeyHandler(ZiKeyArrowUPHandler,   KEY_UP_ARROW,   KEY_EVENT_DOWN);
            SetKeyHandler(ZiKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            /* SetKeyHandler(ZiKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN); */
            SetKeyHandler(ZiKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* register_key_down_handler(T9Key0To9HandlerForEMSInputBox); */
            SetKeyHandler(ZiKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
            // register the star and hash key handkers
            //SetKeyHandler(wgui_inputbox_handle_symbol_picker_star_key_down,KEY_STAR,KEY_EVENT_DOWN);
            // SetKeyHandler(wgui_handle_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
            /* register the L and R softkey handlers */
            set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            set_right_softkey_function(ZiKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            set_left_softkey_function(ZiKeyLSKPressHandler, KEY_EVENT_UP);
            set_left_softkey_function(ZiKeyLSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            ZiDisplay();

#elif defined __MMI_CSTAR__
    #if defined(__MMI_CSTAR_TR_CHINESE__)
    #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
                            case INPUT_MODE_TR_BOPOMO:
    #endif /*     #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) */
    #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
                            case INPUT_MODE_TR_MULTITAP_BOPOMO:
    #endif
                            case INPUT_MODE_TR_STROKE:
    #endif
    #if defined(__MMI_CSTAR_SM_CHINESE__)
    #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
                            case INPUT_MODE_SM_PINYIN:
    #endif
    #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
                            case INPUT_MODE_SM_MULTITAP_PINYIN:
    #endif
                            case INPUT_MODE_SM_STROKE:
    #endif
                
                            case INPUT_MODE_SMART_UPPERCASE_ABC:
                            case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
                            case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
            
#if defined(__MMI_CSTAR_THAI__)
                            case INPUT_MODE_SMART_THAI:
#endif
#if defined(__MMI_CSTAR_ARABIC__)
                            case INPUT_MODE_SMART_ARABIC:
#endif
#if defined(__MMI_CSTAR_PERSIAN__)
                            case INPUT_MODE_SMART_PERSIAN:
#endif
#if defined(__MMI_CSTAR_HINDI__)
                            case INPUT_MODE_SMART_HINDI:
#endif
#if defined(__MMI_CSTAR_HEBREW__)
                            case INPUT_MODE_SMART_HEBREW:
#endif
#if defined(__MMI_CSTAR_SPANISH__)
                            case INPUT_MODE_SMART_UPPERCASE_SPANISH:
                            case INPUT_MODE_SMART_LOWERCASE_SPANISH:
#endif
#if defined(__MMI_CSTAR_DANISH__)
                            case INPUT_MODE_SMART_UPPERCASE_DANISH:
                            case INPUT_MODE_SMART_LOWERCASE_DANISH:
#endif
#if defined(__MMI_CSTAR_POLISH__)
                            case INPUT_MODE_SMART_UPPERCASE_POLISH:
                            case INPUT_MODE_SMART_LOWERCASE_POLISH:
#endif
#if defined(__MMI_CSTAR_NORWEGIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
                            case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
#endif
#if defined(__MMI_CSTAR_FRENCH__)
                            case INPUT_MODE_SMART_UPPERCASE_FRENCH:
                            case INPUT_MODE_SMART_LOWERCASE_FRENCH:
#endif
#if defined(__MMI_CSTAR_GERMAN__)
                            case INPUT_MODE_SMART_UPPERCASE_GERMAN:
                            case INPUT_MODE_SMART_LOWERCASE_GERMAN:
#endif
#if defined(__MMI_CSTAR_ITALIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
                            case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
#endif
#if defined(__MMI_CSTAR_RUSSIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
                            case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
#endif
#if defined(__MMI_CSTAR_BULGARIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
                            case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
#endif
#if defined(__MMI_CSTAR_TURKISH__)
                            case INPUT_MODE_SMART_UPPERCASE_TURKISH:
                            case INPUT_MODE_SMART_LOWERCASE_TURKISH:
#endif
#if defined(__MMI_CSTAR_PORTUGUESE__)
                            case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
                            case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
#endif
#if defined(__MMI_CSTAR_INDONESIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
                            case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
#endif
#if defined(__MMI_CSTAR_CZECH__)
                            case INPUT_MODE_SMART_UPPERCASE_CZECH:
                            case INPUT_MODE_SMART_LOWERCASE_CZECH:
#endif
#if defined(__MMI_CSTAR_MALAY__)
                            case INPUT_MODE_SMART_UPPERCASE_MALAY:
                            case INPUT_MODE_SMART_LOWERCASE_MALAY:
#endif
#if defined(__MMI_CSTAR_VIETNAMESE__)
                            case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
                            case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
#endif
        #if defined(__MMI_CSTAR_FINNISH__)
                            case INPUT_MODE_SMART_UPPERCASE_FINNISH:
                            case INPUT_MODE_SMART_LOWERCASE_FINNISH:
        #endif /* defined(__MMI_CSTAR_FINNISH__) */ 
        #if defined(__MMI_CSTAR_HUNGARIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:  
                            case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:  
        #endif /* defined(__MMI_CSTAR_HUNGARIAN__) */ 
        #if defined(__MMI_CSTAR_SLOVAK__)
                            case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
                            case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
        #endif /* defined(__MMI_CSTAR_SLOVAK__) */ 
        #if defined(__MMI_CSTAR_DUTCH__)
                            case INPUT_MODE_SMART_UPPERCASE_DUTCH:
                            case INPUT_MODE_SMART_LOWERCASE_DUTCH:
        #endif /* defined(__MMI_CSTAR_DUTCH__) */ 
        #if defined(__MMI_CSTAR_SWEDISH__)
                            case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
                            case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
        #endif /* defined(__MMI_CSTAR_SWEDISH__) */ 
                    
        #if defined(__MMI_CSTAR_CROATIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
                            case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
        #endif /* defined(__MMI_CSTAR_CROATIAN__) */ 
        #if defined(__MMI_CSTAR_ROMANIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
                            case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
        #endif /* defined(__MMI_CSTAR_ROMANIAN__) */ 
        #if defined(__MMI_CSTAR_SLOVENIAN__)
                            case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
                            case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
        #endif /* defined(__MMI_CSTAR_SLOVENIAN__) */ 
                    
        #if defined(__MMI_CSTAR_GREEK__)
                            case INPUT_MODE_SMART_UPPERCASE_GREEK:
                            case INPUT_MODE_SMART_LOWERCASE_GREEK:
        #endif /* defined(__MMI_CSTAR_GREEK__) */ 

                CstarChangeInputMethod(mode);
                CstarClearKeyStarAndPoundHandler();
                CstarClearKeyNavigationHandler();
                CstarClearKey0To9Handler();
                clear_right_softkey();
                clear_left_softkey();

                
                SetKeyHandler(CstarKeyArrowUpHandler, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
            	  // SetKeyHandler(CstarKeyStarPressHandler, KEY_STAR, KEY_EVENT_DOWN);
			
                set_left_softkey_function(CstarKeyLSKPressHandler, KEY_EVENT_DOWN);
                set_right_softkey_function(CstarKeyRSKPressHandler, KEY_EVENT_DOWN);
                set_right_softkey_function(CstarKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);

                SetKeyHandler(CstarKeyStarPressHandler, KEY_STAR, KEY_EVENT_DOWN);
                // SetKeyHandler(wgui_handle_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
                CstarDisplay();
            
    #elif defined __MMI_KA__
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_SM_STROKE:
            KonkaChangeInputMethod(mode);
            KonkaClearKeyStarAndPoundHandler();
            /* KaClearKeyNavigationHandler(); */
            KonkaClearArrowKeyLeftHandler();
            KonkaClearArrowKeyRightHandler();
            KonkaClearKey0To9Handler();
            clear_right_softkey();
            clear_left_softkey();
            /* set key arrow handler */
            SetKeyHandler(KonkaKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* register_key_down_handler(T9Key0To9HandlerForEMSInputBox); */
            SetKeyHandler(KonkaKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
            /* register the star and hash key handkers */
            // SetKeyHandler(wgui_handle_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
            /* register the L and R softkey handlers */
            set_right_softkey_function(KonkaKeyRSKPressHandler, KEY_EVENT_DOWN);
            set_right_softkey_function(KonkaKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            set_left_softkey_function(KonkaKeyLSKPressHandler, KEY_EVENT_UP);
            set_left_softkey_function(KonkaKeyLSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            KonkaDisplay();

    #endif 
            break;

    }
    if (input_type != INPUT_TYPE_NUMERIC &&
        input_type != INPUT_TYPE_DECIMAL_NUMERIC &&
        input_type != INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_KEYPAD_NUMERIC &&
        input_type != INPUT_TYPE_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_PHONE_NUMBER &&
        input_type != INPUT_TYPE_NONE)
    {
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__ )
        if (wgui_inputbox_handle_symbol_picker_star_key_down == currKeyFuncPtrs[KEY_STAR][KEY_EVENT_UP])
        {
            ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
            /* W05.41 Long Press Key * to select symbols when __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            SetKeyHandler(wgui_inputbox_handle_symbol_picker_star_key_down, KEY_STAR, KEY_LONG_PRESS);
        }
        SetKeyHandler(wgui_handle_symbol_picker_bymultitapthai, KEY_STAR, KEY_LONG_PRESS);

        SetKeyHandler(wgui_handle_inputbox_change_input_mode_bymultitapthai, KEY_POUND, KEY_LONG_PRESS);
        SetKeyHandler(wgui_handle_inputbox_change_input_mode_bymultitapthai, KEY_POUND, KEY_REPEAT);
#else
        SetKeyHandler(wgui_handle_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputbox_handle_symbol_picker_star_key_down, KEY_STAR, KEY_EVENT_UP);
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    }
    
}

//MTK end
//MTK Elvis to add some APIs for Qsearch


/*****************************************************************************
 * FUNCTION
 *  change_qsearch_singleline_inputbox_mode
 * DESCRIPTION
 *  Changes the input mode of the singleline inputbox
 * PARAMETERS
 *  mode        [IN]        0:
 * RETURNS
 *  void
 *****************************************************************************/
void change_qsearch_singleline_inputbox_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    SetKeyHandler(wgui_handle_qsearch_singleline_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
#else /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    /* MTK Terry : Switch IME by long press # */
    if (wgui_handle_qsearch_singleline_inputbox_change_input_mode == currKeyFuncPtrs[KEY_POUND][KEY_EVENT_DOWN])
    {
        /* W05.37 Fix Key # issue */
        SetKeyHandler(wgui_handle_qsearch_change_input_mode_bymultitapthai, KEY_POUND, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_DOWN);
    }
    SetKeyHandler(wgui_handle_qsearch_change_input_mode_bymultitapthai, KEY_POUND, KEY_REPEAT);
#endif /* !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    switch (mode)
    {

        case INPUT_MODE_MMI_LOWERCASE_ABC:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_ABC);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;

            /* PMT dara added for Multitap thai */
    #if defined (__MMI_MULTITAP_THAI__)
        case INPUT_MODE_MMI_MULTITAP_THAI:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_THAI);
            //change_inputbox_type_multitapthai(SINGLELINE_INPUTBOX); //msz065_20050418
            //register_multitap_key_handlers();
            register_multitap_no_draw_key_handlers();
            /* because in keymap for profile 1, the star and pound key is used to input Thai character. */
        #if defined(__MMI_MUTLTIAP_THAI_PROFILE_1__)
            register_MMI_key_input_extend_handler();
        #endif
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined (__MMI_MULTITAP_THAI__) */ 

    #if defined(__MMI_MULTITAP_SPANISH__)
        case INPUT_MODE_MMI_LOWERCASE_SPANISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_SPANISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
    #if defined(__MMI_MULTITAP_DANISH__)
        case INPUT_MODE_MMI_LOWERCASE_DANISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_DANISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
    #if defined(__MMI_MULTITAP_POLISH__)
        case INPUT_MODE_MMI_LOWERCASE_POLISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_POLISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
    #if defined(__MMI_MULTITAP_FRENCH__)
        case INPUT_MODE_MMI_LOWERCASE_FRENCH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_FRENCH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
    #if defined(__MMI_MULTITAP_GERMAN__)
        case INPUT_MODE_MMI_LOWERCASE_GERMAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_GERMAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
    #if defined(__MMI_MULTITAP_ITALIAN__)
        case INPUT_MODE_MMI_LOWERCASE_ITALIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_ITALIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
    #if defined(__MMI_MULTITAP_RUSSIAN__)
        case INPUT_MODE_MMI_LOWERCASE_RUSSIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_RUSSIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
    #if defined(__MMI_MULTITAP_BULGARIAN__)
        case INPUT_MODE_MMI_LOWERCASE_BULGARIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_BULGARIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
    #if defined(__MMI_MULTITAP_UKRAINIAN__)
        case INPUT_MODE_MMI_LOWERCASE_UKRAINIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_UKRAINIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
    #if defined(__MMI_MULTITAP_TURKISH__)
        case INPUT_MODE_MMI_LOWERCASE_TURKISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_TURKISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
    #if defined(__MMI_MULTITAP_PORTUGUESE__)
        case INPUT_MODE_MMI_LOWERCASE_PORTUGUESE:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_PORTUGUESE);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */ 
    #if defined(__MMI_MULTITAP_HINDI__) 
        case INPUT_MODE_MMI_MULTITAP_HINDI:
            change_multitap_mode(INPUT_MODE_MULTITAP_HINDI);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_HINDI__)  */ 
    #if defined(__MMI_MULTITAP_MARATHI__) 
        case INPUT_MODE_MMI_MULTITAP_MARATHI:   
            change_multitap_mode(INPUT_MODE_MULTITAP_MARATHI);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_MARATHI__) */ 
 	#if defined (__MMI_MULTITAP_TAMIL__) 
        case INPUT_MODE_MMI_MULTITAP_TAMIL:   
            change_multitap_mode(INPUT_MODE_MULTITAP_TAMIL);
            register_multitap_no_draw_key_handlers();
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 
   #if defined(__MMI_MULTITAP_BENGALI__) 
        case INPUT_MODE_MMI_MULTITAP_BENGALI:   
            change_multitap_mode(INPUT_MODE_MULTITAP_BENGALI);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_BENGALI__) */ 


 	#if defined (__MMI_MULTITAP_PUNJABI__) 
        case INPUT_MODE_MMI_MULTITAP_PUNJABI:   
            change_multitap_mode(INPUT_MODE_MULTITAP_PUNJABI);
            register_multitap_no_draw_key_handlers();
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif
    #if defined (__MMI_MULTITAP_TELUGU__) 
        case INPUT_MODE_MMI_MULTITAP_TELUGU:   
            change_multitap_mode(INPUT_MODE_MULTITAP_TELUGU);
            register_multitap_no_draw_key_handlers();
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif
    #if defined(__MMI_MULTITAP_INDONESIAN__)
        case INPUT_MODE_MMI_LOWERCASE_INDONESIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_INDONESIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
    #if defined(__MMI_MULTITAP_CZECH__)
        case INPUT_MODE_MMI_LOWERCASE_CZECH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_CZECH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_CZECH__) */ 

    #if defined(__MMI_MULTITAP_MALAY__)
        case INPUT_MODE_MMI_LOWERCASE_MALAY:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_MALAY);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
    #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MMI_LOWERCASE_VIETNAMESE:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_VIETNAMESE);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
    #if defined(__MMI_MULTITAP_FINNISH__)
        case INPUT_MODE_MMI_LOWERCASE_FINNISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_FINNISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
    #if defined(__MMI_MULTITAP_HUNGARIAN__)
        case INPUT_MODE_MMI_LOWERCASE_HUNGARIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_HUNGARIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
    #if defined(__MMI_MULTITAP_HEBREW__)
        case INPUT_MODE_MMI_MULTITAP_HEBREW:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_HEBREW);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
    #if defined(__MMI_MULTITAP_SLOVAK__)
        case INPUT_MODE_MMI_LOWERCASE_SLOVAK:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_SLOVAK);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
    #if defined(__MMI_MULTITAP_DUTCH__)
        case INPUT_MODE_MMI_LOWERCASE_DUTCH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_DUTCH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
    #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_MMI_MULTITAP_ARABIC:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_ARABIC);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
    #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_MMI_ARABIC_NUMERIC:
            change_multitap_mode(INPUT_MODE_MMI_ARABIC_NUMERIC);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_numeric_key_down);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
    #if defined(__MMI_MULTITAP_PERSIAN__)
        case INPUT_MODE_MMI_MULTITAP_PERSIAN:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_PERSIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
#if defined(__MMI_MULTITAP_URDU__)
		case INPUT_MODE_MMI_MULTITAP_URDU:
      				change_multitap_mode(INPUT_MODE_MMI_MULTITAP_URDU);
 					//register_multitap_key_handlers();
            register_multitap_no_draw_key_handlers();
 					//set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete);
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
#endif
    #if defined(__MMI_MULTITAP_NORWEGIAN__)
        case INPUT_MODE_MMI_LOWERCASE_NORWEGIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_NORWEGIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
    #if defined(__MMI_MULTITAP_SWEDISH__)
        case INPUT_MODE_MMI_LOWERCASE_SWEDISH:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_SWEDISH);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
    #if defined(__MMI_MULTITAP_CROATIAN__)
        case INPUT_MODE_MMI_LOWERCASE_CROATIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_CROATIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
    #if defined(__MMI_MULTITAP_ROMANIAN__)
        case INPUT_MODE_MMI_LOWERCASE_ROMANIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_ROMANIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
    #if defined(__MMI_MULTITAP_SLOVENIAN__)
        case INPUT_MODE_MMI_LOWERCASE_SLOVENIAN:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_SLOVENIAN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
    #if defined(__MMI_MULTITAP_GREEK__)
        case INPUT_MODE_MMI_LOWERCASE_GREEK:
            change_multitap_mode(INPUT_MODE_MMI_LOWERCASE_GREEK);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
    #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
        case INPUT_MODE_MMI_NUMERIC:
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_numeric_key_down);
            wgui_set_singleline_RSK();
            break;

        case INPUT_MODE_MMI_MULTITAP_BPMF:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_BPMF);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
    #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
					SetKeyHandler(MMI_key_star_down,KEY_STAR,KEY_EVENT_DOWN);
					SetKeyHandler(MMI_key_star_up,KEY_STAR,KEY_EVENT_UP);
					SetKeyHandler(MMI_key_pound_down,KEY_POUND,KEY_EVENT_DOWN);
					SetKeyHandler(MMI_key_pound_up,KEY_POUND,KEY_EVENT_UP);
    #endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
            change_multitap_mode(INPUT_MODE_MMI_MULTITAP_PINYIN);
            /* register_multitap_key_handlers(); */
            register_multitap_no_draw_key_handlers();
            ClearKeyHandler(KEY_0, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_0, KEY_EVENT_UP);
            /* set_multitap_functions(singleline_inputbox_multitap_input,singleline_inputbox_multitap_input_complete); */
            set_multitap_functions(Cat200multitap_inputcallback, Cat200multitap_input_complete_callback);
            wgui_set_singleline_RSK();
            break;
        case INPUT_MODE_MMI_SM_STROKE:
            /* change_multitap_mode(INPUT_MODE_MMI_SM_STROKE); */
            clear_multitap_key_handlers();
            register_MMI_stroke_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_stroke_key_down);
            wgui_set_singleline_RSK();
            break;

        case INPUT_MODE_MMI_TR_STROKE:
            /* change_multitap_mode(INPUT_MODE_MMI_TR_STROKE); */
            clear_multitap_key_handlers();
            register_MMI_stroke_key_input_handler();
            register_key_down_handler(singleline_inputbox_handle_stroke_key_down);
            wgui_set_singleline_RSK();
            break;
        default:
            break;

    }

#if defined(__MMI_ZI__)
#ifdef __MMI_MIXED_LANG_SUPPORT__
    ZiChangeInputMethod((INPUT_MODE) mode, g_ime_sub_writing_lang);
#else
    ZiChangeInputMethod((INPUT_MODE) mode);
#endif
#endif

#if defined(__MMI_CSTAR__)
    CstarChangeInputMethod(mode);
#endif 

#if defined(__MMI_PHB_QUICK_SEARCH__)
    mmi_phb_quick_search_change_input_mode();
#endif 
    /* refresh_search_list(NULL); */

}

/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  singleline_inputbox_key_handler
 * DESCRIPTION
 *  Keyboard (simulator) key handler for the singleline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Is the scan code of the key
 *  key_state       [IN]        Is the key event type (up, down ...)
 * RETURNS
 *  void
 *****************************************************************************/
void singleline_inputbox_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                singleline_inputbox_previous_character();
                break;

            case 38:    /* up */
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_single_line_input_box_highlight_cursor_start(&MMI_singleline_inputbox);
                show_singleline_inputbox();
        #endif /* (ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;

            case 39:
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                singleline_inputbox_next_character();
                break;
            case 40:    /* down */
        #if(ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_single_line_input_box_highlight_cursor_end(&MMI_singleline_inputbox);
                show_singleline_inputbox();
        #endif /* (ENABLE_SINGLELINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 36:    /* home */
                break;
            case 35:    /* end */
                break;
            case 33:    /* page up */
                break;
            case 34:    /* page down */
                break;
            case 45:
                singleline_inputbox_toggle_insert_mode();
                break;
            case 46:
                singleline_inputbox_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_singleline_inputbox_keys
 * DESCRIPTION
 *  Registers the keys for the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_singleline_inputbox_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(singleline_inputbox_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(singleline_inputbox_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(singleline_inputbox_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    register_keyboard_key_handler(singleline_inputbox_key_handler);
    /* Add key handlers here for Clear key and input mode key   */
}


/*****************************************************************************
 * FUNCTION
 *  set_singleline_inputbox_mask
 * DESCRIPTION
 *  Sets masked display of characters
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void set_singleline_inputbox_mask(U8 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (m)
    {
        case 0:
            MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_singleline_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  reset_singleline_inputbox
 * DESCRIPTION
 *  Removes the keyhandlers for the singleline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_singleline_inputbox(void)
{
#if(UI_BLINKING_CURSOR_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);

#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_singleline_inputbox_end_frame);
    wgui_singleline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_SINGLELINE_INPUTBOX_FRAME_SKIPPING)) */ 
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    clear_multitap_key_handlers();
    singleline_inputbox_input_callback = UI_dummy_function;
    singleline_inputbox_navigate_callback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  get_singleline_inputbox_display_status
 * DESCRIPTION
 *  to see if display singleline inputbox
 * PARAMETERS
 *  void
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
MMI_BOOL get_singleline_inputbox_display_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_singleline_inputbox.flags & UI_SINGLE_LINE_INPUT_BOX_DISABLE_DRAW)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  resize_singleline_inputbox
 * DESCRIPTION
 *  Resizes the singleline input box
 * PARAMETERS
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void resize_singleline_inputbox(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&MMI_singleline_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  resize_single_line_input_box_fix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_single_line_input_box_fix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width = 0, string_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string((UI_string_type) MMI_singleline_inputbox.text, &string_width, &string_height);
    gui_resize_single_line_input_box(&MMI_singleline_inputbox, string_width + 6, string_height + 6);
}


/*****************************************************************************
 * FUNCTION
 *  move_singleline_inputbox
 * DESCRIPTION
 *  Resizes the singleline input box
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void move_singleline_inputbox(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_single_line_input_box(&MMI_singleline_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  register_singleline_inputbox_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_singleline_inputbox_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_singleline_inputbox_navigate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_singleline_inputbox_navigate_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    singleline_inputbox_navigate_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  change_singleline_inputbox_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void change_singleline_inputbox_content(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL && MMI_singleline_inputbox.text != (U8*) string)
    {
        gui_single_line_input_box_clear(&MMI_singleline_inputbox);
        gui_single_line_input_box_insert_string(&MMI_singleline_inputbox, string, 0);
    }
}

/* multi line input box wrappers       */

multi_line_input_box MMI_multiline_inputbox;
void (*multiline_inputbox_input_callback) (void);
void (*multiline_inputbox_navigate_callback) (void) = UI_dummy_function;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
S32 wgui_multiline_inputbox_frame_counter = 0;
#endif 


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_input_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_inputbox_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_navigate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_inputbox_navigate_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_navigate_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  create_multiline_inputbox
 * DESCRIPTION
 *  Creates a multiline inputbox
 *  
 *  Blanks the text
 * PARAMETERS
 *  buffer              [IN]        Is the buffer to use
 *  buffer_length       [IN]        Is the length of the buffer to use
 * RETURNS
 *  void
 *****************************************************************************/
void create_multiline_inputbox(UI_string_type buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    gui_create_multi_line_input_box_use_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length);
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    wgui_multiline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  create_multiline_inputbox_set_buffer
 * DESCRIPTION
 *  Creates a multiline inputbox
 *  
 *  Displays the text that was passed and allows editing
 * PARAMETERS
 *  buffer              [IN]        Is the buffer to use
 *  buffer_length       [IN]        Is the length of the buffer to use
 *  text_length         [IN]        Is the length of the text in the buffer
 *  edit_position       [IN]        Is the cursor position on entry
 * RETURNS
 *  void
 *****************************************************************************/
extern S16 MMI_current_input_ext_type;
void create_multiline_inputbox_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    MMI_current_input_ext_type &= INPUT_TYPE_EXT_SIM_NUMERIC;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    wgui_multiline_inputbox_frame_counter = 0;
#endif 
}

//Gurinder - 5/5/2004 Inline Multiline Box History Control
//Duplicate of Above for Inscreen Multiline


/*****************************************************************************
 * FUNCTION
 *  create_multiline_inputbox_set_buffer_no_text_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void create_multiline_inputbox_set_buffer_no_text_reset(
        UI_string_type buffer,
        S32 buffer_length,
        S32 text_length,
        S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
    MMI_current_input_ext_type = 0;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_multi_line_input_box_set_buffer_no_text_reset(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_multi_line_input_box_set_buffer_no_text_reset(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox_x,
        MMI_multiline_inputbox_y,
        MMI_multiline_inputbox_width,
        MMI_multiline_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    wgui_multiline_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  resize_multiline_inputbox_fit
 * DESCRIPTION
 *  Changes the size of the multiline inputbox to fit content
 * PARAMETERS
 *  width           [IN]        Are the new dimensions
 *  height          [IN]        Are the new dimensions
 *  fit_width       [?]         
 *  fit_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void resize_multiline_inputbox_fit(S32 width, S32 height, S32 *fit_width, S32 *fit_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fh = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_multi_line_input_box(&MMI_multiline_inputbox, width, height);
    show_multiline_inputbox_no_draw();
    gui_set_font(MMI_multiline_inputbox.text_font);
    fh = get_multiline_inputbox_line_height();
    gui_resize_multi_line_input_box(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox.width,
        (MMI_multiline_inputbox.n_lines * fh) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
    *fit_width = width;
    *fit_height = (MMI_multiline_inputbox.n_lines * fh) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y;
}


/*****************************************************************************
 * FUNCTION
 *  resize_multiline_inputbox
 * DESCRIPTION
 *  Changes the size of the multiline inputbox
 * PARAMETERS
 *  width       [IN]        Are the new dimensions
 *  height      [IN]        Are the new dimensions
 * RETURNS
 *  void
 *****************************************************************************/
void resize_multiline_inputbox(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_multi_line_input_box(&MMI_multiline_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  move_multiline_inputbox
 * DESCRIPTION
 *  Changes the size of the multiline inputbox
 * PARAMETERS
 *  x       [IN]        Is the new position of the multiline inputbox
 *  y       [IN]        Is the new position of the multiline inputbox
 * RETURNS
 *  void
 *****************************************************************************/
void move_multiline_inputbox(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_multi_line_input_box(&MMI_multiline_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  show_multiline_inputbox
 * DESCRIPTION
 *  Displays the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_multiline_inputbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_multiline_inputbox_no_draw
 * DESCRIPTION
 *  Refreshes the multiline inputbox without redrawing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_multiline_inputbox_no_draw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    gui_show_multi_line_input_box(&MMI_multiline_inputbox);
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_multiline_inputbox_end_frame
 * DESCRIPTION
 *  Redraws the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))

void wgui_multiline_inputbox_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_multiline_inputbox_frame_counter >= 1)
    {
        S32 y2, BLT_y2;

        gui_show_multi_line_input_box(&MMI_multiline_inputbox);
        if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA)
        {
            //redraw_on_input_method_change = 1;
            //START TARUN PMT 20040927  ADDED : Check the flag before redrawing the info bar
            if (wgui_inputbox_information_flag)
            {
                wgui_redraw_input_information_bar();
            }
            //END TARUN PMT 20040927
            //        multiline_inputbox_input_callback();
        }
        BLT_y2 = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height;
        y2 = MMI_multitap_y + MMI_multitap_height + 1;
        if (BLT_y2 < y2)
        {
            BLT_y2 = y2;
        }
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.x + MMI_multiline_inputbox.width - 1,
            BLT_y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_multiline_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_multiline_inputbox_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 

extern U16 GetExitScrnID(void);

#include "IdleAppDef.h"


/*****************************************************************************
 * FUNCTION
 *  redraw_multiline_inputbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_multiline_inputbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() != SCR_POPUP_SCREEN)
    {
    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
        if (wgui_multiline_inputbox_frame_counter > 0)
        {
            wgui_multiline_inputbox_frame_counter++;
        }
        else
        {
            wgui_multiline_inputbox_frame_counter = 1;
            gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_multiline_inputbox_end_frame);
        }
    #else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
		{
			gui_show_multi_line_input_box(&MMI_multiline_inputbox);
		}
        gui_BLT_double_buffer(
            MMI_multiline_inputbox.x,
            MMI_multiline_inputbox.y,
            MMI_multiline_inputbox.x + MMI_multiline_inputbox.width,
            MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
    #endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_multitap_input
 * DESCRIPTION
 *  inserts a multitap character
 *  
 *  Normally called by multitap handlers
 * PARAMETERS
 *  c       [IN]        Is the character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((MMI_multiline_inputbox.text[0] == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text)
            && (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH)))
        {
            return;
        }
    }
    gui_multi_line_input_box_insert_multitap_character(&MMI_multiline_inputbox, c);
    redraw_multiline_inputbox();
    

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();


}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_confirm_multitap_character(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
    
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_direct_input
 * DESCRIPTION
 *  Inserts a character
 *  
 *  Normally registered with keyboard handlers (simulator)
 * PARAMETERS
 *  c       [IN]        Is a character to be inserted
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((MMI_multiline_inputbox.text[0] == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text)
            && (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH)))
        {
            return;
        }
    }
    if (UI_TEST_LF_CHARACTER(c))
    {
        gui_multi_line_input_box_insert_newline(&MMI_multiline_inputbox);
    }
    else
    {
        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);
    }
    redraw_multiline_inputbox();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_direct_input_no_LF_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_direct_input_no_LF_check(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        if ((MMI_multiline_inputbox.text[0] == '+') && (MMI_multiline_inputbox.cursor_p == MMI_multiline_inputbox.text)
            && (MMI_multiline_inputbox.text_length >= (MMI_multiline_inputbox.available_length - ENCODING_LENGTH)))
        {
            return;
        }
    }
    gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, c);
    redraw_multiline_inputbox();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_delete_character
 * DESCRIPTION
 *  Deletes a character before the cursor position (Backspace)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.34 Fix Multitap in arrow keys */
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
    {
        disable_active_multitap();
    }
    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.34 Fix Multitap in arrow keys */
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
    {
        disable_active_multitap();
    }
    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  get_multiline_input_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S8 get_multiline_input_box(void *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i->flags == INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

S8 g_mmi_wgui_halfline_marquee_scroll_enable = 0;


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_vertical_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_vertical_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nvisiblearea = MAIN_LCD_device_height - (MMI_multiline_inputbox.y + MMI_BUTTON_BAR_HEIGHT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvisiblearea > MMI_multiline_inputbox.text_height)
    {
        return;
    }
    if (nvisiblearea > MMI_multiline_inputbox.edit_height)
    {
        nvisiblearea = MMI_multiline_inputbox.edit_height;
    }
    //      if(MMI_multiline_inputbox.vertical_scroll_on)
    //      {
    MMI_multiline_inputbox.vertical_scroll_on = 1;

    if (nvisiblearea - MMI_multiline_inputbox.text_offset_y >= MMI_multiline_inputbox.text_height)
    {
        MMI_multiline_inputbox.text_offset_y = 0;
    }
    else
    {
        gui_set_font(MMI_multiline_inputbox.text_font);

        /* START TARUN PMT 20041002 : To enable the half line scrolling */

        /* MMI_multiline_inputbox.text_y-=(gui_get_character_height()+1); */
        g_mmi_wgui_halfline_marquee_scroll_enable = 1;  /* Enable it here */
        MMI_multiline_inputbox.text_offset_y -= ((gui_get_character_height()) >> 1);

        /* END TARUN PMT 20041002 */

    }

    redraw_multiline_inputbox();
    MMI_multiline_inputbox.vertical_scroll_on = 0;
    multiline_inputbox_navigate_callback();
    gui_start_timer(UI_MULTI_LINE_SCROLL_TIMEOUT, multiline_inputbox_vertical_scroll);
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_previous_line
 * DESCRIPTION
 *  Moves the cursor to the previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
        if (hilited_item_changed != 1)
        {
            /* W05.34 Fix Multitap in arrow keys */
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                disable_active_multitap();
            }
            redraw_multiline_inputbox();
            multiline_inputbox_navigate_callback();
            return;
        }
        else
        {
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                handle_inline_full_screen_edit_close();
            }
            inline_fixed_list_goto_previous_item();
            g_mmi_wgui_halfline_marquee_scroll_enable = 0;
        }
        hilited_item_changed = 0;
    }
    return;
}

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)

/* Pixtel - Gurinder - 2/6/4 Function Pointer to call at presing of up arrow in inscreen multiline edit. */


/*****************************************************************************
 * FUNCTION
 *  multiline_inscreen_inputbox_previous_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inscreen_inputbox_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
    if (hilited_item_changed != 1)
    {
        /* W05.34 Fix Multitap in arrow keys */
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            redraw_multiline_inputbox();
        }
        multiline_inputbox_navigate_callback();
        return;
    }
    else
    {
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            handle_inline_multi_line_edit_complete();
        }
        inline_fixed_list_goto_previous_item();
    }
    hilited_item_changed = 0;
    return;
}
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_next_line
 * DESCRIPTION
 *  Moves the cursor to the next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Pixtel - 2/16/2004 - Gurinder - Api added to check that first hilighted item is multi line view box or not. */
extern U8 wgui_inline_item_handled;
extern wgui_inline_item *current_wgui_inline_item;
extern wgui_inline_item wgui_inline_items[];

void multiline_inputbox_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_wgui_inline_item != NULL)
    {
        /* This case moves the multiline input box up untill it reached at the first item. */
        wgui_inline_item_text_edit *i = (wgui_inline_item_text_edit*) current_wgui_inline_item->item;

        /* Read Only Control Now Only Display For Number Of Lines Text Present - Gurinder - 3/27/2004 */
        if (((i->max_lines + MMI_fixed_list_menu.highlighted_item -
              MMI_fixed_list_menu.first_displayed_item) * MMI_MENUITEM_HEIGHT > MMI_fixed_list_menu.height) &&
            ((MMI_multiline_inputbox.n_lines + MMI_fixed_list_menu.highlighted_item -
              MMI_fixed_list_menu.first_displayed_item) * MMI_MENUITEM_HEIGHT > MMI_fixed_list_menu.height))
        {
            if (get_multiline_input_box(&wgui_inline_items[MMI_fixed_list_menu.first_displayed_item]))
            {
                MMI_fixed_list_menu.first_displayed_item++;
                wgui_inline_item_handled = 0;
                show_fixed_list();
            }
        }
        else
        {
            gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
            if (!hilited_item_changed)
            {
                /* W05.34 Fix Multitap in arrow keys */
                if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
                {
                    disable_active_multitap();
                }
                redraw_multiline_inputbox();
                multiline_inputbox_navigate_callback();
            }
            hilited_item_changed = 0;
        }
    }
    else
    {
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
            (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
            MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.text_height >
            MMI_multiline_inputbox.edit_height)
        {
            gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
            /* W05.34 Fix Multitap in arrow keys */
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                disable_active_multitap();
            }
            redraw_multiline_inputbox();
        }
        multiline_inputbox_navigate_callback();
    }
}
extern void handle_inline_full_screen_edit_complete(void);
extern void inline_fixed_list_goto_next_item(void);

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* Pixtel - Gurinder - 2/6/4 Function Pointer to call at presing of down arrow in inscreen multiline edit. */


/*****************************************************************************
 * FUNCTION
 *  multiline_inscreen_inputbox_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inscreen_inputbox_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
    if (hilited_item_changed != 1)
    {
        /* W05.34 Fix Multitap in arrow keys */
        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            disable_active_multitap();
        }
        redraw_multiline_inputbox();
        multiline_inputbox_navigate_callback();
        return;
    }
    else
    {
        /* Issue #74 UI Internal - Gurinder 22/6/2004 */
        handle_inline_multi_line_edit_complete();
        inline_fixed_list_goto_next_item();
    }
    hilited_item_changed = 0;
    return;
}
#else /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_next_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
    /* W05.34 Fix Multitap in arrow keys */
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
    {
        disable_active_multitap();
    }
    redraw_multiline_inputbox();
    multiline_inputbox_navigate_callback();
}
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_home
 * DESCRIPTION
 *  Moves the cursor to the first line, first character
 *  
 *  Not yet implemented
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Gurinder - 28/4/2004 - Move Contents To Top In Inscreen Multiline Readonly */
    MMI_multiline_inputbox.text_offset_y = 0;
    redraw_multiline_inputbox();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_end
 * DESCRIPTION
 *  Moves the cursor to the last line, last character
 *  
 *  Not yet implemented
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    redraw_multiline_inputbox();
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_previous_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        wgui_paging_multiline_inputbox_previous_page();
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        gui_multi_line_input_box_previous_page(&MMI_multiline_inputbox);
        redraw_multiline_inputbox();
        multiline_inputbox_navigate_callback();
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */    
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_next_page
 * DESCRIPTION
 *  Moves the cursor to the next page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE)
    {
        wgui_paging_multiline_inputbox_next_page();
    }
    else
    {
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
        gui_multi_line_input_box_next_page(&MMI_multiline_inputbox);
        redraw_multiline_inputbox();
        multiline_inputbox_navigate_callback();
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    }
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_previous_page
 * DESCRIPTION
 *  show the previous page of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
gui_page_info_app gui_page_info;

void wgui_paging_multiline_inputbox_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_paging_stop_text_scroll();
        }

        gui_paging_multi_line_input_box_previous_page(&MMI_multiline_inputbox);

        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            disable_active_multitap();
        }
        show_multiline_inputbox_no_draw();

        wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);

        if (wgui_paging_multiline_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (MMI_multiline_inputbox.text_offset_y == 0)
        {
            percentage_scale = 0;
        }

        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        /* PMT Start 00071 */
        /* if (percentage_scale > gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        else */

            gui_page_info.last_showed_percentage = percentage_scale;

        /* PMT End 00071 */
        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);

        gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;        /* ritesh added for text relocation */

        multiline_inputbox_navigate_callback();
        redraw_multiline_inputbox();

        return;
    }
}

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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_next_page
 * DESCRIPTION
 *  show the next page of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        !wgui_paging_multiline_check_to_end())
    {
        gui_paging_multi_line_input_box_next_page(&MMI_multiline_inputbox);

        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            disable_active_multitap();

            if ((MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                && (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p))
            {
                if (stop_auto_scroll_callback)
                    stop_auto_scroll_callback();
                wgui_paging_stop_text_scroll();
            }
        }
        show_multiline_inputbox_no_draw();

        wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);

        if (wgui_paging_multiline_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        /* if (percentage_scale < gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        else */
            gui_page_info.last_showed_percentage = percentage_scale;

        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
        redraw_multiline_inputbox();
    }
    else
    {
        wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);
        if (percentage_scale < COMPLETE_PERCENTAGE_SCALE &&
            MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        /* if(MMI_multiline_inputbox.text_offset_y==0)
           percentage_scale=0; */
        /* if (percentage_scale < gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        else */

            gui_page_info.last_showed_percentage = percentage_scale;

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_paging_stop_text_scroll();
        }
        
        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
        gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;        /* ritesh added for text relocation */
        redraw_multiline_inputbox();
    }
    multiline_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_next_line_in_paging_scroll
 * DESCRIPTION
 *  show the next line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_next_line_in_paging_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
    {
        MMI_multiline_inputbox.next_line_scroll_flag = 1;
    }
    wgui_paging_multiline_inputbox_next_line_in_paging();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_next_line_in_paging
 * DESCRIPTION
 *  show the next line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_next_line_in_paging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        !wgui_paging_multiline_check_to_end())
    {
        gui_paging_multi_line_input_box_next_line_in_paging(&MMI_multiline_inputbox);

        if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
        {
            disable_active_multitap();

            if ((MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                && (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p))
            {
                if (stop_auto_scroll_callback)
                    stop_auto_scroll_callback();
                wgui_paging_stop_text_scroll();
            }
        }
        show_multiline_inputbox_no_draw();
        wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);
        if (wgui_paging_multiline_check_to_end())
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (MMI_multiline_inputbox.text_offset_y == 0)
        {
            percentage_scale = 0;
        }

        if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        
        if (percentage_scale < gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        
        gui_page_info.last_showed_percentage = percentage_scale;

        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
        redraw_multiline_inputbox();
    }
    else
    {
        wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);
        if (percentage_scale < COMPLETE_PERCENTAGE_SCALE && percentage_scale != 0)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }
        /* if(MMI_multiline_inputbox.text_offset_y==0)
           percentage_scale=0; */
        /* PMT Start 00071 */
        /* if (percentage_scale < gui_page_info.last_showed_percentage)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }
        else */

        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_paging_stop_text_scroll();
        }

        gui_page_info.last_showed_percentage = percentage_scale;

        /* PMT End 00071 */
        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
        redraw_multiline_inputbox();
    }
    /*   else
       {
       if(MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
       {
       gui_paging_reset_auto_scroll();
       wgui_paging_stop_text_scroll();
       // MMI_multiline_inputbox.ext_flags|= GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
       }
       } */
    gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* ritesh added for text relocation */
    multiline_inputbox_navigate_callback();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_set_stop_scroll_callback
 * DESCRIPTION
 *  set the autoscroll stop callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_set_stop_scroll_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_auto_scroll_callback = (stop_scroll_hdlr)callback;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_previous_line_in_paging
 * DESCRIPTION
 *  show the previous line of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_previous_line_in_paging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) ||
        (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU) ||
        MMI_multiline_inputbox.text_offset_y < 0)
    {
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            if (stop_auto_scroll_callback)
                stop_auto_scroll_callback();
            wgui_paging_stop_text_scroll();
        }
        gui_paging_multi_line_input_box_previous_line_in_paging(&MMI_multiline_inputbox);
        if (hilited_item_changed != 1)
        {

            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                disable_active_multitap();
            }
            show_multiline_inputbox_no_draw();
            wgui_paging_multiline_inputbox_calculate_percentage(&percentage_scale);
            
            if (wgui_paging_multiline_check_to_end())
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }
            
            if (MMI_multiline_inputbox.text_offset_y == 0)
            {
                percentage_scale = 0;
            }
            if (percentage_scale > COMPLETE_PERCENTAGE_SCALE)
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }

            if (percentage_scale > gui_page_info.last_showed_percentage)
            {
                percentage_scale = gui_page_info.last_showed_percentage;
            }

            gui_page_info.last_showed_percentage = percentage_scale;

            wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
            redraw_multiline_inputbox();
            gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* ritesh added for text relocation */
            multiline_inputbox_navigate_callback();
            return;
        }
        else
        {
            if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE))
            {
                handle_inline_full_screen_edit_close();
            }
            inline_fixed_list_goto_previous_item();
            g_mmi_wgui_halfline_marquee_scroll_enable = 0;
        }
        hilited_item_changed = 0;
    }
    gui_page_info.last_text_offset_y = MMI_multiline_inputbox.text_offset_y;    /* ritesh added for text relocation */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_calculate_percentage
 * DESCRIPTION
 *  show the previous line of text
 * PARAMETERS
 *  percentage_scale        [IN]        
 *  pointer(?)              [IN]        To percentage_value
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_calculate_percentage(PU8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 percentage_offset;
    float actual_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (MMI_multiline_inputbox.header_height != 0 || MMI_multiline_inputbox.footer_height != 0)
	{
		if (wgui_paging_multiline_check_to_end())
		{
			actual_percentage = 1;
		}
		else
		{
			/*check whether stay at header*/
			if (-MMI_multiline_inputbox.text_offset_y < MMI_multiline_inputbox.header_height)
			{
				actual_percentage = (-MMI_multiline_inputbox.text_offset_y) / (float)(MMI_multiline_inputbox.size_of_total_data
					+ MMI_multiline_inputbox.header_height
					+ MMI_multiline_inputbox.footer_height);
			}
			/*check whether stay at footer*/
			else if(-MMI_multiline_inputbox.text_offset_y > MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.footer_height - Get_CharHeightOfAllLang(LARGE_FONT))
			{
				actual_percentage = (-MMI_multiline_inputbox.text_offset_y - (MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.header_height - MMI_multiline_inputbox.footer_height)
					+ MMI_multiline_inputbox.size_of_total_data) 
					/ (float)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
			}
			else
			{
				percentage_offset =
					MMI_multiline_inputbox.text_offset - MMI_multiline_inputbox.previous_shared_bytes +
					(MMI_multiline_inputbox.start_id) * GUI_PAGE_SIZE;
				actual_percentage = (percentage_offset + MMI_multiline_inputbox.header_height) 
                    / (float)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
			}
		}
	}
	else
	{
            percentage_offset =
                MMI_multiline_inputbox.text_offset - MMI_multiline_inputbox.previous_shared_bytes +
                (MMI_multiline_inputbox.start_id) * GUI_PAGE_SIZE;
            actual_percentage = (percentage_offset) / (float)MMI_multiline_inputbox.size_of_total_data;
	}

    actual_percentage = actual_percentage * 100;
    *percentage_scale = (U8) actual_percentage;
    if ((actual_percentage - (float)*percentage_scale) >= 0.8)
    {
        (*percentage_scale)++;
    }
    if ((*percentage_scale) > COMPLETE_PERCENTAGE_SCALE)
    {
        (*percentage_scale) = COMPLETE_PERCENTAGE_SCALE;
    }

    if (!(-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >=
        MMI_multiline_inputbox.text_height && MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id))
    {
        if (*percentage_scale == COMPLETE_PERCENTAGE_SCALE)
            *percentage_scale = 99;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_start_text_scroll
 * DESCRIPTION
 *  Start scrolling of text either page-by-page or line-by-line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_start_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_multiline_inputbox.ext_flags|=GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE; */

    if (gui_page_info.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE &&
        gui_page_info.scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON)
    {
        wgui_paging_multiline_inputbox_next_line_in_paging();
        /*    if(MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.text_height < MMI_multiline_inputbox.edit_height)
           wgui_paging_stop_text_scroll();
           else */
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                gui_page_info.scroll_speed * UI_MULTI_LINE_SCROLL_TIMEOUT / 2,
            wgui_paging_multiline_start_text_scroll);
        }
    }
    else
    {
        wgui_paging_multiline_inputbox_next_page();
        if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
        {
            gui_start_timer(
                (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / gui_page_info.scroll_speed,
            wgui_paging_multiline_start_text_scroll);
        }
    }
}

//PMT SUKRIT START MMSVIEWER
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_scroll_data_cb
 * DESCRIPTION
 *  sets get_data_during_scrolling callback
 * PARAMETERS
 *  gui_scroll_info     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_scroll_data_cb(get_data_during_scrolling_cb data_callback)
{
	gui_page_info.get_data_during_scrolling = data_callback;
}
#endif
//PMT SUKRIT END MMSVIEWER

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_scroll_info
 * DESCRIPTION
 *  sets the speed of scrolling
 * PARAMETERS
 *  gui_scroll_info     [IN]        
 *  instance(?)         [IN]        Of gui_page_info_app structure
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_scroll_info(gui_page_info_app **gui_scroll_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_page_info = **gui_scroll_info;
    MMI_multiline_inputbox.scroll_type = (*gui_scroll_info)->scroll_type;
    MMI_multiline_inputbox.scroll_speed = (*gui_scroll_info)->scroll_speed;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_stop_text_scroll
 * DESCRIPTION
 *  stop the scrolling of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_stop_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    gui_cancel_timer(wgui_paging_multiline_start_text_scroll);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_start_text_scroll
 * DESCRIPTION
 *  stop the scrolling of text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_start_text_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE;
    if (gui_page_info.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
    {
        gui_start_timer(200, wgui_paging_multiline_start_text_scroll);
    }
    else
    {
        gui_start_timer(
            (UI_MULTI_LINE_INIT_SCROLL * WGUI_MAX_SCROLL_TIME) / gui_page_info.scroll_speed,
            wgui_paging_multiline_start_text_scroll);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_font
 * DESCRIPTION
 *  Set the font type of text going to be dispalyed
 * PARAMETERS
 *  gui_paging_font_type        [IN]        
 *  gui_paging_font_style       [IN]        
 *  font(?)                     [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_font(U8 gui_paging_font_type, U8 gui_paging_font_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gui_paging_font_type)
    {
        case FONT_SIZE_SMALL:
            MMI_multiline_inputbox.text_font = &MMI_small_font;
            break;

        case FONT_SIZE_MEDIUM:
            MMI_multiline_inputbox.text_font = &MMI_medium_font;
            break;

        case FONT_SIZE_LARGE:
            MMI_multiline_inputbox.text_font = &MMI_large_font;
            break;
    }
    MMI_multiline_inputbox.font_style = gui_paging_font_style;

}

//PMT SUKRIT START MMSVIEWER
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_get_page_callback
 * DESCRIPTION
 * get_page_callback setter function
 * PARAMETERS
 *  get_page_callback        [IN]        callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_get_page_callback(get_page_callback get_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT (get_page);
    MMI_multiline_inputbox.get_page_cb = get_page;
}

//PMT SUKRIT END MMSVIEWER

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_set_scrollbar_range
 * DESCRIPTION
 *  Sets the scrollbar range according to the book size
 * PARAMETERS
 *  document_size       [IN]        
 *  size(?)             [IN]        Of the text going to be opened
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_set_scrollbar_range(U32 document_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 scrollbar_range = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.last_page_id = (document_size / GUI_PAGE_SIZE)
        + ((document_size % GUI_PAGE_SIZE)>0 ? 1 : 0);

    if (MMI_multiline_inputbox.last_page_id > 0)
    {
        MMI_multiline_inputbox.last_page_id--;
    }

    MMI_multiline_inputbox.last_page_size = document_size % GUI_PAGE_SIZE;

    MMI_multiline_inputbox.size_of_total_data = document_size;

    if (MMI_multiline_inputbox.text_height > MMI_multiline_inputbox.edit_height)
    {
        gui_set_vertical_scrollbar_range(&MMI_multiline_inputbox.vbar, MMI_multiline_inputbox.text_height);
        show_multiline_inputbox_no_draw();
    }

    if (document_size <= GUI_PAGE_SIZE * 4)
    {
        scrollbar_range = MMI_multiline_inputbox.text_height;
    }
    else
    {
        scrollbar_range = (MMI_multiline_inputbox.last_page_id / GUI_NO_OF_PAGES) * MMI_multiline_inputbox.text_height;
    }
    gui_set_vertical_scrollbar_range(&MMI_multiline_inputbox.vbar, scrollbar_range);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  start_id        [IN]        And text_offset
 *  text_offset     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_percentage(U32 start_id, S16 text_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;
    U32 percentage_offset;
    float actual_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    percentage_offset = start_id * GUI_PAGE_SIZE + text_offset;
    if (MMI_multiline_inputbox.size_of_total_data != 0)
    {
        actual_percentage = (percentage_offset) / (float)MMI_multiline_inputbox.size_of_total_data;
        actual_percentage = actual_percentage * 100;
        percentage_scale = (U8) actual_percentage;
        if ((actual_percentage - (float)percentage_scale) >= 0.8)
        {
            percentage_scale++;
        }

        if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
        {
            percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >=
            MMI_multiline_inputbox.text_height && MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id)
        {
            if (percentage_scale != 0)
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
        }

        if (gui_page_info.last_showed_percentage != percentage_scale && gui_page_info.last_showed_percentage != 0)
        {
            percentage_scale = gui_page_info.last_showed_percentage;
        }

        /* if(MMI_multiline_inputbox.text_offset_y==0)
           percentage_scale=0; */
        wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
    }

}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_translate_to_text_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  percentage_scale        [IN]        the scrollbar percentage       
 * RETURNS
 *  void
 *****************************************************************************/
U8 wgui_paging_multiline_translate_to_text_percentage(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 text_offset, pixtel_offset;
    float actual_percentage;
    double percent, header_percent, footer_percent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.header_height != 0 
        ||MMI_multiline_inputbox.footer_height != 0)
    {
        percent = (double)(percentage_scale)/100;
        header_percent = (double)(MMI_multiline_inputbox.header_height)
            /(double)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);
        footer_percent = (double)(MMI_multiline_inputbox.footer_height)
            /(double)(MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height);

        /*stay at the header*/
        if (percent <= header_percent)
            return 1;
        /*stay at the footer*/
        else if (percent >= (1 - footer_percent))
            return COMPLETE_PERCENTAGE_SCALE;
        /*stay at the text content*/
        else
        {
            actual_percentage = (percent - header_percent)/(1 - header_percent - footer_percent);
            actual_percentage = actual_percentage * 100;
            percentage_scale = (U8) actual_percentage;
            if ((actual_percentage - (float)percentage_scale) >= 0.8)
            {
                percentage_scale++;
            }
            
            if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
            {
                percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }

            if (wgui_paging_multiline_check_to_end())
            {
                if (percentage_scale != 0)
                    percentage_scale = COMPLETE_PERCENTAGE_SCALE;
            }
        }
        
    }
    
    return percentage_scale;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_check_to_end
 * DESCRIPTION
 *  check whether the view is to the end
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_paging_multiline_check_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (-MMI_multiline_inputbox.text_offset_y + MMI_multiline_inputbox.edit_height >= MMI_multiline_inputbox.text_height
		&& MMI_multiline_inputbox.end_id == MMI_multiline_inputbox.last_page_id)
	{
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_check_cursor_to_end
 * DESCRIPTION
 *  check whether the cursor line is to the end
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_paging_multiline_check_cursor_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_multiline_inputbox.line_after_cursor_line_p == MMI_multiline_inputbox.cursor_line_p)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_clear_last_percentage
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_clear_last_percentage(void)
{
    gui_page_info.last_showed_percentage = 0;
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_set_percentage_scale_TS
 * DESCRIPTION
 *  sets the percentage parameter
 * PARAMETERS
 *  percentage_scale        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_set_percentage_scale_TS(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s[10];
    S32 l, character_height, shortcut_width;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage_scale >= COMPLETE_PERCENTAGE_SCALE)
    {
        percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    }
    if (percentage_scale == 0)
    {
        MMI_menu_shortcut_number = percentage_scale + 1;
    }
    else
    {
        MMI_menu_shortcut_number = percentage_scale;
    }
    shortcut_width = set_menu_item_count(100) + 7;
    resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    gui_itoa(100, (UI_string_type) s, 10);
    gui_measure_string((UI_string_type) s, &l, &character_height);
    //PMT SUKRIT START MMSVIEWER
    /* TODO: Check if show precentage flag is zero then show??? */
    //if (wgui_paging_show_percentage == 0)
    if (percentage_callback != NULL)
    {
        (*percentage_callback)(MMI_menu_shortcut_number);
    }
    else
    {
        if (wgui_paging_show_percentage == 1)
        {
            gui_redraw_menu_shortcut();
        }
    }
    
    //PMT SUKRIT END MMSVIEWER 
    gui_page_info.last_showed_percentage = percentage_scale;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_set_page
 * DESCRIPTION
 *  Moves the cursor to the previous page
 * PARAMETERS
 *  start_id        [IN]        
 *  end_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_set_page(U32 start_id, U32 end_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.start_id = start_id;
    MMI_multiline_inputbox.end_id = end_id;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_set_show_percentage_flag
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_set_show_percentage_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_show_percentage = 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_reset_show_percentage_flag
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_reset_show_percentage_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_show_percentage = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_dm_set_multiline_data
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  gui_multiline_get_coordinates       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_dm_set_multiline_data(dm_coordinates *gui_multiline_get_coordinates)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox_x = gui_multiline_get_coordinates->s16X;
    MMI_multiline_inputbox_y = gui_multiline_get_coordinates->s16Y;
    MMI_multiline_inputbox_width = gui_multiline_get_coordinates->s16Width;
    MMI_multiline_inputbox_height = gui_multiline_get_coordinates->s16Height;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_set_percentage_scale
 * DESCRIPTION
 *  show how much part of book has been read in percentage
 * PARAMETERS
 *  percentage_scale        [IN]        =percentage of the book read.
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_paging_multiline_inputbox_set_percentage_scale(U8 percentage_scale)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s[10];
    S32 l, character_height, shortcut_width /* ,scroll_offset */ ;
    U32 scroll_offset;
    double percent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (percentage_scale == 0)
    {
        MMI_menu_shortcut_number = percentage_scale + 1;
    }
    else
    {
        MMI_menu_shortcut_number = percentage_scale;
    }

    if (percentage_scale == -1)
    {
        scroll_offset = MMI_multiline_inputbox.text_offset_y;
    }
    else if (percentage_scale == COMPLETE_PERCENTAGE_SCALE)
    {   
        scroll_offset = MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale;
        
    }
    else
    {
        percent = (double)percentage_scale/100;
        scroll_offset = (U32)((MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale) * percent);
    }

    shortcut_width = set_menu_item_count(100) + 7;
    resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    gui_itoa(100, (UI_string_type) s, 10);
    gui_measure_string((UI_string_type) s, &l, &character_height);
    gui_set_vertical_scrollbar_value(&MMI_multiline_inputbox.vbar, scroll_offset);
    //PMT SUKRIT START MMSVIEWER
    /* TODO: Check if show precentage flag is zero then show??? */
    //if (wgui_paging_show_percentage == 0)
    if (percentage_callback != NULL)
    {
        (*percentage_callback)(MMI_menu_shortcut_number);
    }
    else
    {
        if (wgui_paging_show_percentage == 1)
        {
            gdi_layer_lock_frame_buffer();// it should not be displayed to LCD right now 
            gui_redraw_menu_shortcut();
            gdi_layer_unlock_frame_buffer();
        }
    }
    gui_page_info.last_showed_percentage = percentage_scale;

}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_inputbox_set_percentage_callback
 * DESCRIPTION
 *  set the percentage show function callback
 * PARAMETERS
 *  callback        [IN]        =show callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_inputbox_set_percentage_callback(void* callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    percentage_callback = (percentage_hdlr)callback;
}
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_highlight_search_string
 * DESCRIPTION
 *  hightlight the search string
 * PARAMETERS
 *  text_offset         [IN]        And the string_len
 *  search_str_len      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_highlight_search_string(S32 text_offset, S8 search_str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_multiline_inputbox.highlight_start_position = MMI_multiline_inputbox.text + (text_offset * ENCODING_LENGTH);
    MMI_multiline_inputbox.highlight_end_position =
        MMI_multiline_inputbox.text + (text_offset + search_str_len) * ENCODING_LENGTH;

    MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.highlight_start_position;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_get_current_page
 * DESCRIPTION
 *  during exit of the screen concerned application make a demand for current page ,text offset and shared bytes currently existing in the multiline buffer.
 * PARAMETERS
 *  page_id                     [IN]        Pointer to the start_id of the page
 *  text_offset                 [IN]        Pointer to the offset of the displayed text position
 *  shared_bytes                [IN]        Currently number of shared bytes
 *  last_showed_percentage      [IN]        Currently displayed page
 *  last_text_offset_y          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_get_current_page(
        PU32 page_id,
        PS32 text_offset,
        PU8 shared_bytes,
        PU8 last_showed_percentage,
        PS32 last_text_offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.size_of_total_data <= GUI_PAGE_SIZE)
    {
        *page_id = MMI_multiline_inputbox.start_id;
    }
    else
    {
        *page_id = MMI_multiline_inputbox.page_details[PAGE_ZERO].page_id;
    }
    *text_offset = MMI_multiline_inputbox.text_offset;
    *shared_bytes = MMI_multiline_inputbox.previous_shared_bytes / 2;
    *last_showed_percentage = gui_page_info.last_showed_percentage;
/* PMT Start 06_08_06 00071 */
    *last_text_offset_y = MMI_multiline_inputbox.text_offset_y; /* ritesh added for relocation of text at the end */
/* PMT End 06_08_06 00071 */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_jump_to_end
 * DESCRIPTION
 *  sets the percentage flag
 * PARAMETERS
 *  void
 *  start_id(?)     [IN]        And text_offset
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_jump_to_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (MMI_multiline_inputbox.text_height + MMI_multiline_inputbox.text_offset_y >
           MMI_multiline_inputbox.edit_height)
    {
        gui_paging_multi_line_input_box_next_page(&MMI_multiline_inputbox);
    }
    resize_multiline_inputbox(MMI_multiline_inputbox_width, MMI_multiline_inputbox_height);

    percentage_scale = COMPLETE_PERCENTAGE_SCALE;
    wgui_paging_multiline_inputbox_set_percentage_scale(percentage_scale);
    
    gui_lock_double_buffer();
    redraw_multiline_inputbox();
    gui_unlock_double_buffer();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_set_page_info
 * DESCRIPTION
 *  Get the page structure and fill the multiline inputbox element required in 
	 Touch Screen.
 * PARAMETERS
 * gui_page_info_app  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_set_page_info(gui_page_info_app *page_info_d)
{
	wgui_paging_multiline_set_page(page_info_d->start_id, page_info_d->end_id);
	wgui_paging_multiline_set_font(page_info_d->font_size, page_info_d->font_style);
				   
        MMI_multiline_inputbox.text_offset_y = 0;
	MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
	MMI_multiline_inputbox.jump_offset_from_app = page_info_d->jump_offset_from_app;
	MMI_multiline_inputbox.search_flag_is_on = page_info_d->search_flag_is_on;
}

#ifdef __MMI_TOUCH_SCREEN__

pBOOL full_screen_flag;

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_multiline_key_maaping_TS
 * DESCRIPTION
 *  Gives the specified key to application for their handling
 * PARAMETERS
 *  c       [IN]        
 *  UI_character_type
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_multiline_key_maaping_TS(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_page_info.key_callback(c);
}
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_get_data_during_scrolling
 * DESCRIPTION
 *  according to page_id get the data in multiline text buffer for display
 * PARAMETERS
 *  percentage_val  [IN]
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_paging_get_data_during_scrolling(S32 percentage_val)
{
	gui_page_info.get_data_during_scrolling(percentage_val,MMI_multiline_inputbox.text);
}
	

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_set_full_screen_flag
 * DESCRIPTION
 *  sets full screen flag to 0 or 1
 * PARAMETERS
 *  flag_value     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_set_full_screen_flag(pBOOL flag_value)
{
	full_screen_flag=flag_value;
}
/*****************************************************************************
 * FUNCTION
 *  wgui_paging_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hadler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_paging_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        return MMI_TRUE;
    }
    else
    {
        ret = gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_UP,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

        if (ret)
        {
            if (GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR != multi_line_input_box_event)
            {
                gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
                redraw_multiline_inputbox();
                if (percentage_callback != NULL)
                {
                    (*percentage_callback)(MMI_menu_shortcut_number);
                }
                return MMI_TRUE;
            }
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hadler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_paging_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_val_scrollbar = MMI_multiline_inputbox.vbar.value;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
        return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {

            int r = 0;
            
            if(MMI_multiline_inputbox.vbar.scale != 1) /* for file under 4 * page size*/
            {
                r = ((int)MMI_multiline_inputbox.vbar.range - (int)MMI_multiline_inputbox.vbar.scale);
           
                if (prev_val_scrollbar > r) /* means the scroll value large than scrollbar's max value and may adjust the value by scrollbar algo. */
                {
                    if (MMI_multiline_inputbox.vbar.value == r) /* the value has been adjusted */
                    {
                        prev_val_scrollbar = r - 1; /* let pre value less than currnet value for get next page data */
                    }
                }
            }

            if (prev_val_scrollbar < MMI_multiline_inputbox.vbar.value)
            {
                if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
                {
                    wgui_paging_multiline_inputbox_next_line_in_paging_scroll();
                }
                else
                {
                    wgui_paging_multiline_inputbox_next_page();
                }
            }
            else if (prev_val_scrollbar > MMI_multiline_inputbox.vbar.value)
            {
                if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
                {
                    wgui_paging_multiline_inputbox_previous_line_in_paging();
                }
                else
                {
                    wgui_paging_multiline_inputbox_previous_page();
                }
            }
        }
        else if(MMI_multiline_inputbox.vbar.pen_state.state != GUI_SCROLLBAR_PEN_STATE_SBUTTON)
        {
            if (prev_val_scrollbar == 0)
            {
                if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
                {
                    wgui_paging_multiline_inputbox_previous_line_in_paging();
                }
                else
                {
                    wgui_paging_multiline_inputbox_previous_page();
                }
            }
            else
            {
                if (MMI_multiline_inputbox.scroll_type == WGUI_PAGING_SCROLL_LINE_BY_LINE)
                {
                    wgui_paging_multiline_inputbox_next_line_in_paging_scroll();
                }
                else
                {
                    wgui_paging_multiline_inputbox_next_page();
                }
            }
        }
        return MMI_TRUE;
    }
    else
    {
        ret = gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &multi_line_input_box_event);

        if (ret)
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_paging_pen_move_hdlr
 * DESCRIPTION
 *  touch screen handler for category 75 & 77
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_paging_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 wgui_prev_scrollbar_value, page_id, required_bytes, real_val, text_val;
    S32 val;
    double act_val;
    S16 page_offset;

    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR)
        || ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR) && (MMI_multiline_inputbox.vbar.scale > MMI_multiline_inputbox.vbar.range)))
            return MMI_FALSE;

    if (PEN_CHECK_BOUND
        (pos.x, pos.y, MMI_multiline_inputbox.vbar.x, MMI_multiline_inputbox.vbar.y, MMI_multiline_inputbox.vbar.width,
         MMI_multiline_inputbox.vbar.height))
    {
        wgui_prev_scrollbar_value = MMI_multiline_inputbox.vbar.value;
        gui_vertical_scrollbar_translate_pen_event(
            &MMI_multiline_inputbox.vbar,
            MMI_PEN_EVENT_MOVE,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param);

        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            if (MMI_multiline_inputbox.vbar.value != wgui_prev_scrollbar_value)
            {
                act_val = ((double)MMI_multiline_inputbox.vbar.value / (double)(MMI_multiline_inputbox.vbar.range  - MMI_multiline_inputbox.vbar.scale));
                act_val *= (double)100.0;

                real_val = (U32) act_val;
                if (act_val - (double)real_val >= 0.7)
                {
                    real_val++;
                }

                if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_AUTO_SCROLL_MODE)
                {
                    if (stop_auto_scroll_callback)
                        stop_auto_scroll_callback();
                    wgui_paging_stop_text_scroll();
                }

                MMI_multiline_inputbox.text_offset_y = 0;
				/* 0601129 patch starts */
		text_val = (U32)wgui_paging_multiline_translate_to_text_percentage((U8)real_val);

                wgui_paging_get_data_during_scrolling(text_val);
                
                /* 0601129 patch end */
                MMI_multiline_inputbox.previous_shared_bytes = 0;
                
                MMI_multiline_inputbox.search_flag_is_on = 0;
                
                if (MMI_multiline_inputbox.header_height > 0 )
                {
                    MMI_multiline_inputbox.text_offset_y = -MMI_multiline_inputbox.header_height;
                }
                
                if (MMI_multiline_inputbox.ext_flags & GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE)
                {
                    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
                    show_multiline_inputbox_no_draw();
                    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_LOCATE_CURSOR;
                }
                else
                    show_multiline_inputbox_no_draw();
                
                if(MMI_multiline_inputbox.header_height > 0 || MMI_multiline_inputbox.footer_height > 0)
                {
                    act_val = (double)real_val/100;
                    val = (S32)((MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height + MMI_multiline_inputbox.footer_height)
                                      * act_val);
                    if(val <= MMI_multiline_inputbox.header_height)
                        MMI_multiline_inputbox.text_offset_y = -val;
                    else if(val >= MMI_multiline_inputbox.size_of_total_data + MMI_multiline_inputbox.header_height)
                        MMI_multiline_inputbox.text_offset_y = -(MMI_multiline_inputbox.text_height - MMI_multiline_inputbox.footer_height
                        + (val - MMI_multiline_inputbox.size_of_total_data - MMI_multiline_inputbox.header_height));              
                    
                    if (wgui_paging_multiline_check_to_end())
                        MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
                }

                if (MMI_multiline_inputbox.vbar.value == MMI_multiline_inputbox.vbar.range - MMI_multiline_inputbox.vbar.scale)
                {
                    MMI_multiline_inputbox.text_offset_y = MMI_multiline_inputbox.edit_height - MMI_multiline_inputbox.text_height;
                }

                if (wgui_paging_multiline_check_to_end())
                {
                    real_val = COMPLETE_PERCENTAGE_SCALE;
                }

                wgui_paging_multiline_inputbox_set_percentage_scale_TS((U8) real_val);
                redraw_multiline_inputbox();
            }
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_paging_virtual_keypad_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_paging_virtual_keypad_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_show_virtual_keyboard();
}				
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ /* ritesh */


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_toggle_insert_mode(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_delete_current_character(&MMI_multiline_inputbox);
    redraw_multiline_inputbox();
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    if (!(MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INCLUDE_INFO_AREA))
#endif 
        multiline_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  Alphanumeric keyboard input handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc == 0xc0)
    {
        multiline_inputbox_direct_input_no_LF_check((UI_character_type) '\n');
    }
    else if (keyc == 0xbb)
    {
        multiline_inputbox_direct_input((UI_character_type) 0x0d);
    }
    else if (keyc == 0xbd)
    {
        multiline_inputbox_direct_input((UI_character_type) 0x1b);
    }
    else if (keyc == 0x08)
    {
        multiline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        multiline_inputbox_delete_all_characters();
    }
    else if (keyc == 0x0d)
    {
        multiline_inputbox_direct_input((U8) '\n');
    }
    else if (keyc > 0x1f)
    {
        multiline_inputbox_direct_input((U8) keyc);
    }
}

#if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  multiline_WCSS_inputbox_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  Alphabatic keyboard input handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_WCSS_inputbox_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc == 0xc0)
    {
        multiline_inputbox_direct_input_no_LF_check((UI_character_type) '\n');
    }
    else if (keyc == 0xbb)
    {
        multiline_inputbox_direct_input((UI_character_type) 0x0d);
    }
    else if (keyc == 0xbd)
    {
        multiline_inputbox_direct_input((UI_character_type) 0x1b);
    }
    else if (keyc == 0x08)
    {
        multiline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        multiline_inputbox_delete_all_characters();
    }
    else if (keyc == 0x0d)
    {
        multiline_inputbox_direct_input((U8) '\n');
    }
    else if (keyc >= '0' && keyc <= '9');   /* We cannot input numbers for some input formats */
    else if (keyc > 0x1f)
    {
        multiline_inputbox_direct_input((U8) keyc);
    }
}
#endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

#if defined(__MMI_MULTITAP_ARABIC__)
/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_numeric_keyboard_input_handler
 * DESCRIPTION
 *  Numeric keyboard input handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_arabic_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        multiline_inputbox_direct_input((UI_character_type) (keyc + 0x0630)); /* arabic numeric is from 0x0660 to 0x0669 */
    }
    else if (keyc == 0x08)
    {
        multiline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        multiline_inputbox_delete_all_characters();
    }
}

#endif /* defined(__MMI_MULTITAP_ARABIC__) */

/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_numeric_keyboard_input_handler
 * DESCRIPTION
 *  Numeric keyboard input handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc >= '0' && keyc <= '9')
    {
        multiline_inputbox_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        multiline_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        multiline_inputbox_delete_all_characters();
    }
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_handle_key_down
 * DESCRIPTION
 *  Keypad key down event handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  k       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_handle_key_down(MMI_key_code_type k)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_ARABIC__)
    if (MMI_current_input_mode == INPUT_MODE_ARABIC_NUMERIC ||MMI_current_input_mode == INPUT_MODE_MMI_ARABIC_NUMERIC )
        multiline_inputbox_direct_input((UI_character_type) (0x0660 + k));
    else
#endif
    multiline_inputbox_direct_input((UI_character_type) ('0' + k));
}


extern void GetkeyInfo(U16 *keyCode, U16 *keyType); /* gives key code & key type of last key event */

/*****************************************************************************
 * FUNCTION
 *  register_multiline_multitap_function
 * DESCRIPTION
 *  Changes the input mode of the multiline inputbox
 * PARAMETERS
 *  void
 *  mode(?)     [IN]        0: Uppercase, 1: Lowercase, 2: Numeric
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Elvis modify for stacked character--thai */
void register_multiline_multitap_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W06.09 Touch Screen With Keypad V1 */
#if defined(__MMI_FULL_SCREEN_EDITOR__) || defined(__MMI_TOUCH_SCREEN__)
    register_multitap_no_draw_key_handlers();
#else 
    register_multitap_key_handlers();
#endif 
    register_keyboard_input_handler(multiline_inputbox_alphabetic_keyboard_input_handler);
    set_multitap_functions(multiline_inputbox_multitap_input, multiline_inputbox_multitap_input_complete);
    wgui_set_RSK();
    register_multiline_inputbox_keys();

    if (MMI_EXIT_WITH_MULTITAP_STATE)
    {
        MMI_timer_multitap = MMI_active_multitap;
        /* x 3 is a experimental value */
    #if defined(__MMI_FULL_SCREEN_EDITOR__)
        gui_start_timer(MMI_MULTITAP_TIMEOUT * 3 , disable_active_multitap_no_draw);
    #else
        gui_start_timer(MMI_MULTITAP_TIMEOUT * 3  , disable_active_multitap);
    #endif

        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    MMI_EXIT_WITH_MULTITAP_STATE = MMI_FALSE;
    

}


/*****************************************************************************
 * FUNCTION
 *  change_multiline_inputbox_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void change_multiline_inputbox_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_type = MMI_current_input_type & INPUT_TYPE_MASK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ABC);
            register_multiline_multitap_function();
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ABC);
            register_multiline_multitap_function();
            break;

        case INPUT_MODE_123:
            change_multitap_mode(INPUT_MODE_123);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(multiline_inputbox_handle_key_down);
            register_keyboard_input_handler(multiline_inputbox_numeric_keyboard_input_handler);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;
        #if defined (__MMI_MULTITAP_THAI__)
        case INPUT_MODE_MULTITAP_THAI:
            change_multitap_mode(INPUT_MODE_MULTITAP_THAI);
            /* change_inputbox_type_multitapthai(MULTILINE_INPUTBOX); //msz065_20050420 */
        #if defined(__MMI_FULL_SCREEN_EDITOR__) || defined (__MMI_TOUCH_SCREEN__)
            register_multitap_no_draw_key_handlers();
        #else 
            register_multitap_key_handlers();
        #endif 
        #if defined(__MMI_MULTITAP_THAI_PROFILE_1__)
            register_MMI_key_input_extend_handler();    /* msz065_20050418 */
        #endif
            register_keyboard_input_handler(multiline_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(multiline_inputbox_multitap_input, multiline_inputbox_multitap_input_complete);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;
        #endif /* defined (__MMI_MULTITAP_THAI__) */ 
        #if defined(__MMI_MULTITAP_SPANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SPANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SPANISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SPANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SPANISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_SPANISH__) */ 
        #if defined(__MMI_MULTITAP_DANISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_DANISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_DANISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_DANISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_DANISH__) */ 
        #if defined(__MMI_MULTITAP_POLISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_POLISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_POLISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_POLISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_POLISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_POLISH__) */ 
        #if defined(__MMI_MULTITAP_FRENCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FRENCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_FRENCH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_FRENCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_FRENCH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_FRENCH__) */ 
        #if defined(__MMI_MULTITAP_GERMAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GERMAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_GERMAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_GERMAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_GERMAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_GERMAN__) */ 
        #if defined(__MMI_MULTITAP_ITALIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_ITALIAN__) */ 
        #if defined(__MMI_MULTITAP_RUSSIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_RUSSIAN__) */ 
        #if defined(__MMI_MULTITAP_BULGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_BULGARIAN__) */ 
        #if defined(__MMI_MULTITAP_UKRAINIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_UKRAINIAN__) */ 
        #if defined(__MMI_MULTITAP_TURKISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_TURKISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_TURKISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_TURKISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_TURKISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_TURKISH__) */ 
        #if defined(__MMI_MULTITAP_PORTUGUESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_PORTUGUESE__) */
        #if defined(__MMI_MULTITAP_HINDI__)
        case INPUT_MODE_MULTITAP_HINDI:
            change_multitap_mode(INPUT_MODE_MULTITAP_HINDI);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_HINDI__) */ 
            /* PMT RAKESH START 20061006 */
        #if defined(__MMI_MULTITAP_MARATHI__)
        case INPUT_MODE_MULTITAP_MARATHI:
            change_multitap_mode(INPUT_MODE_MULTITAP_MARATHI);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_MARATHI__) */ 
		#if defined (__MMI_MULTITAP_TAMIL__) 
        case INPUT_MODE_MULTITAP_TAMIL:
            change_multitap_mode(INPUT_MODE_MULTITAP_TAMIL);
            register_multiline_multitap_function();
            break;
        #endif /* #if defined (__MMI_MULTITAP_TAMIL__)  */ 

      #if defined(__MMI_MULTITAP_BENGALI__) 
        case INPUT_MODE_MULTITAP_BENGALI:
            change_multitap_mode(INPUT_MODE_MULTITAP_BENGALI);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_MARATHI__) */  
		#if defined (__MMI_MULTITAP_PUNJABI__) 
        case INPUT_MODE_MULTITAP_PUNJABI:
            change_multitap_mode(INPUT_MODE_MULTITAP_PUNJABI);
            register_multiline_multitap_function();
            break;
        #endif
        #if defined (__MMI_MULTITAP_TELUGU__) 
        case INPUT_MODE_MULTITAP_TELUGU:
            change_multitap_mode(INPUT_MODE_MULTITAP_TELUGU);
            register_multiline_multitap_function();
            break;
        #endif 
        #if defined(__MMI_MULTITAP_INDONESIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_INDONESIAN__) */ 
        #if defined(__MMI_MULTITAP_CZECH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CZECH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_CZECH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_CZECH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_CZECH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_CZECH__) */ 

        #if defined(__MMI_MULTITAP_MALAY__)
        case INPUT_MODE_MULTITAP_UPPERCASE_MALAY:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_MALAY);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_MALAY:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_MALAY);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_MALAY__) */ 
        #if defined(__MMI_MULTITAP_VIETNAMESE__)
        case INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_VIETNAMESE__) */ 
        #if defined(__MMI_MULTITAP_HEBREW__)
        case INPUT_MODE_MULTITAP_HEBREW:
            change_multitap_mode(INPUT_MODE_MULTITAP_HEBREW);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_HEBREW__) */ 
        #if defined(__MMI_MULTITAP_FINNISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_FINNISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_FINNISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_FINNISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_FINNISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_FINNISH__) */ 
        #if defined(__MMI_MULTITAP_HUNGARIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_HUNGARIAN__) */ 
        #if defined(__MMI_MULTITAP_SLOVAK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_SLOVAK__) */ 
        #if defined(__MMI_MULTITAP_DUTCH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_DUTCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_DUTCH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_DUTCH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_DUTCH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_DUTCH__) */ 
        #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_MULTITAP_ARABIC:
            change_multitap_mode(INPUT_MODE_MULTITAP_ARABIC);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        #if defined(__MMI_MULTITAP_ARABIC__)
        case INPUT_MODE_ARABIC_NUMERIC:
            change_multitap_mode(INPUT_MODE_ARABIC_NUMERIC);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(multiline_inputbox_handle_key_down);
            register_keyboard_input_handler(multiline_inputbox_arabic_numeric_keyboard_input_handler);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;
        #endif /* defined(__MMI_MULTITAP_ARABIC__) */ 
        #if defined(__MMI_MULTITAP_PERSIAN__)
        case INPUT_MODE_MULTITAP_PERSIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_PERSIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_PERSIAN__) */ 
    #if defined(__MMI_MULTITAP_URDU__)
      case INPUT_MODE_MULTITAP_URDU:
         change_multitap_mode(INPUT_MODE_MULTITAP_URDU);
         register_multiline_multitap_function();
         break;
    #endif
        #if defined(__MMI_MULTITAP_NORWEGIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_NORWEGIAN__) */ 
        #if defined(__MMI_MULTITAP_SWEDISH__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_SWEDISH__) */ 
        #if defined(__MMI_MULTITAP_CROATIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_CROATIAN__) */ 
        #if defined(__MMI_MULTITAP_ROMANIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_ROMANIAN__) */ 
        #if defined(__MMI_MULTITAP_SLOVENIAN__)
        case INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_SLOVENIAN__) */ 
        #if defined(__MMI_MULTITAP_GREEK__)
        case INPUT_MODE_MULTITAP_UPPERCASE_GREEK:
            change_multitap_mode(INPUT_MODE_MULTITAP_UPPERCASE_GREEK);
            register_multiline_multitap_function();
            break;
        case INPUT_MODE_MULTITAP_LOWERCASE_GREEK:
            change_multitap_mode(INPUT_MODE_MULTITAP_LOWERCASE_GREEK);
            register_multiline_multitap_function();
            break;
        #endif /* defined(__MMI_MULTITAP_GREEK__) */ 
        #if defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__)
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC:
            change_multitap_mode(mode);
        #if defined(__MMI_FULL_SCREEN_EDITOR__)
            register_multitap_no_draw_key_handlers();
        #else 
            register_multitap_key_handlers();
        #endif 
            register_keyboard_input_handler(multiline_WCSS_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(multiline_inputbox_multitap_input, multiline_inputbox_multitap_input_complete);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;

        case INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC:
            change_multitap_mode(mode);
        #if defined(__MMI_FULL_SCREEN_EDITOR__)
            register_multitap_no_draw_key_handlers();
        #else 
            register_multitap_key_handlers();
        #endif 
            register_keyboard_input_handler(multiline_WCSS_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(multiline_inputbox_multitap_input, multiline_inputbox_multitap_input_complete);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;

        case INPUT_MODE_123_SYMBOLS:
            change_multitap_mode(mode);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(multiline_inputbox_handle_key_down);
            register_keyboard_input_handler(multiline_inputbox_numeric_keyboard_input_handler);
            wgui_set_RSK();
            register_multiline_inputbox_keys();
            break;
        #endif /* defined(__MMI_WCSS_INPUT_FORMAT_SUPPORT__) */ 

        #ifdef __MMI_T9__
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
        #if defined(__MMI_T9_DANISH__)
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
        case INPUT_MODE_SMART_LOWERCASE_DANISH:
        #endif /* defined(__MMI_T9_DANISH__) */ 
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
        case INPUT_MODE_SMART_LOWERCASE_POLISH:
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
        case INPUT_MODE_SMART_THAI:
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
        case INPUT_MODE_SMART_UPPERCASE_CZECH:
        case INPUT_MODE_SMART_LOWERCASE_CZECH:

        #if defined(__MMI_T9_VIETNAMESE__)
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
        #endif /* defined(__MMI_T9_VIETNAMESE__) */ 

        #if defined(__MMI_T9_INDONESIAN__)
        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
        #endif /* defined(__MMI_T9_INDONESIAN__) */ 

        #if defined(__MMI_T9_PORTUGUESE__)
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
        #endif /* defined(__MMI_T9_PORTUGUESE__) */ 
        #if defined(__MMI_T9_FINNISH__)
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
        #endif /* defined(__MMI_T9_FINNISH__) */ 
        #if defined(__MMI_T9_HUNGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:  /* Gurdev Start Hungarian */
        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
        #endif /* defined(__MMI_T9_HUNGARIAN__) */ 
            //PMT START PERSIAN
        case INPUT_MODE_SMART_PERSIAN:
            /* PMT END PERSIAN */
        case INPUT_MODE_SMART_ARABIC:
        case INPUT_MODE_SMART_HEBREW:
        #if defined(__MMI_T9_HINDI__)
        case INPUT_MODE_SMART_HINDI:
        #endif
            //Norwegian start
        #if defined(__MMI_T9_NORWEGIAN__)
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
        #endif /* defined(__MMI_T9_NORWEGIAN__) */ 
            //Norwegian end
        #if defined(__MMI_T9_GREEK__)
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
        case INPUT_MODE_SMART_LOWERCASE_GREEK:
        #endif /* defined(__MMI_T9_GREEK__) */ 
        #if defined(__MMI_T9_DUTCH__)
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
        #endif /* defined(__MMI_T9_DUTCH__) */ 
        #if defined(__MMI_T9_SLOVENIAN__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
        #endif /* defined(__MMI_T9_SLOVENIAN__) */ 
        #if defined(__MMI_T9_SWEDISH__)
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
        #endif /* defined(__MMI_T9_SWEDISH__) */ 
        #if defined(__MMI_T9_MALAY__)
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
        case INPUT_MODE_SMART_LOWERCASE_MALAY:
        #endif /* defined(__MMI_T9_MALAY__) */ 
        #if defined(__MMI_T9_CROATIAN__)
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
        #endif /* defined(__MMI_T9_CROATIAN__) */ 
        #if defined(__MMI_T9_SLOVAK__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
        #endif /* defined(__MMI_T9_SLOVAK__) */ 
        #if defined(__MMI_T9_ROMANIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
        #endif /* defined(__MMI_T9_ROMANIAN__) */ 
            T9ChangeLanguageMultilineInputBox(mode);
            T9ClearKeyStarAndPoundHandler();
            T9ClearKeyNavigationHandler();
            // MBJ hongyu guo 2007/3/30 added for crash issue
            T9ClearKey0To9Handler();
            // MBJ end
            //W05.39 For RSK Hide Function Issue
            //clear_right_softkey();
            clear_multitap_key_handlers();
            /* W06.09 Touch Screen With Keypad V1 */
        #if !defined(__MMI_TOUCH_SCREEN__)
            SetKeyHandler(T9KeyPoundPressHandlerMultilineInputBox, KEY_POUND, KEY_EVENT_DOWN);
            SetKeyHandler(T9KeyStarPressHandlerMultilineInputBox, KEY_STAR, KEY_EVENT_DOWN);
        #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
            //set key arrow handler
            //Steven e-dic
            //if callback func not equal to NULL , dont register T9 up/down key handler
            // up/down key is handled by other AP ex. e-dictionary 
            if (wgui_register_multiline_inputbox_up_down_key_handler == NULL)
            {
                SetKeyHandler(T9KeyArrowUPHandlerMultilineInputBox, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(T9KeyArrowDownHandlerMultilineInputBox, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            }
            SetKeyHandler(T9KeyArrowRightHandlerMultilineInputBox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(T9KeyArrowLeftHandlerMultilineInputBox, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            /* register_key_down_handler(T9Key0To9HandlerMultilineInputBox); */
            SetKeyHandler(T9Key0PressHandlerMultilineInputBox, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key1PressHandlerMultilineInputBox, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key2PressHandlerMultilineInputBox, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key3PressHandlerMultilineInputBox, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key4PressHandlerMultilineInputBox, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key5PressHandlerMultilineInputBox, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key6PressHandlerMultilineInputBox, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key7PressHandlerMultilineInputBox, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key8PressHandlerMultilineInputBox, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(T9Key9PressHandlerMultilineInputBox, KEY_9, KEY_EVENT_DOWN);

            wgui_set_RSK();
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
        #if !defined(__MMI_TOUCH_SCREEN__)
            T9SynT9WithInputBoxMultilineInputBox();
            T9ScreenStateChnageMultilineInputBox();
            T9InputBoxDisplayMultilineInputBox();
        #else /* !defined(__MMI_TOUCH_SCREEN__) */ 
            wgui_set_RSK();
            register_multiline_inputbox_keys();
        #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 

        #elif defined __MMI_ZI__
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SMART_THAI:
        case INPUT_MODE_SMART_PERSIAN:
        case INPUT_MODE_SMART_ARABIC:
    #if defined(__MMI_ZI_HINDI__)
        case INPUT_MODE_SMART_HINDI:
    #endif
    #if defined(__MMI_ZI_BENGALI__)
        case INPUT_MODE_SMART_BENGALI:
    #endif

    #if defined(__MMI_ZI_MARATHI__)
        case INPUT_MODE_SMART_MARATHI:
    #endif

    #if defined(__MMI_ZI_PUNJABI__)
        case INPUT_MODE_SMART_PUNJABI:
    #endif

    #if defined(__MMI_ZI_TAMIL__)
        case INPUT_MODE_SMART_TAMIL:
    #endif

    #if defined(__MMI_ZI_TELUGU__)
        case INPUT_MODE_SMART_TELUGU:
    #endif

    #if defined(__MMI_ZI_URDU__)
        case INPUT_MODE_SMART_URDU:
    #endif
        #if defined(__MMI_ZI_HEBREW__)
        case INPUT_MODE_SMART_HEBREW:
        #endif 
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
        case INPUT_MODE_SMART_LOWERCASE_POLISH:
        #if defined(__MMI_ZI_DANISH__)
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
        case INPUT_MODE_SMART_LOWERCASE_DANISH:
        #endif /* defined(__MMI_ZI_DANISH__) */ 
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
        case INPUT_MODE_SMART_UPPERCASE_UKRAINIAN:
        case INPUT_MODE_SMART_LOWERCASE_UKRAINIAN:
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
        case INPUT_MODE_SMART_UPPERCASE_CZECH:
        case INPUT_MODE_SMART_LOWERCASE_CZECH:
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
        case INPUT_MODE_SMART_LOWERCASE_MALAY:
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
        #if defined(__MMI_ZI_SLOVAK__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
        #endif /* defined(__MMI_ZI_SLOVAK__) */ 
        #if defined(__MMI_ZI_DUTCH__)
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
        #endif /* defined(__MMI_ZI_DUTCH__) */ 
        #if defined(__MMI_ZI_NORWEGIAN__)
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
        #endif /* defined(__MMI_ZI_NORWEGIAN__) */ 
        #if defined(__MMI_ZI_SWEDISH__)
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
        #endif /* defined(__MMI_ZI_SWEDISH__) */ 
        #if defined(__MMI_ZI_CROATIAN__)
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
        #endif /* defined(__MMI_ZI_CROATIAN__) */ 
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
        #if defined(__MMI_ZI_SLOVENIAN__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
        #endif /* defined(__MMI_ZI_SLOVENIAN__) */ 
        #if defined(__MMI_ZI_GREEK__)
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
        case INPUT_MODE_SMART_LOWERCASE_GREEK:
        #endif /* defined(__MMI_ZI_GREEK__) */ 
        #if defined(__MMI_ZI_FINNISH__)
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
        #endif /* defined(__MMI_ZI_FINNISH__) */ 
        #if defined(__MMI_ZI_HUNGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:
        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
        #endif /* defined(__MMI_ZI_HUNGARIAN__) */ 
        #ifdef __MMI_MIXED_LANG_SUPPORT__
            ZiChangeInputMethod((INPUT_MODE) mode, g_ime_sub_writing_lang);
        #else
            ZiChangeInputMethod((INPUT_MODE) mode);
        #endif
            ZiClearKeyStarAndPoundHandler();
            ZiClearKeyNavigationHandler();
            ZiClearKey0To9Handler();
            //set key arrow handler
            //Steven e-dic
            //if callback func not equal to NULL , dont register Zi up/down key handler
            // up/down key is handled by other AP ex. e-dictionary 
            if (wgui_register_multiline_inputbox_up_down_key_handler == NULL)
            {
                SetKeyHandler(ZiKeyArrowUPHandler, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(ZiKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            }
            SetKeyHandler(ZiKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(ZiKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
            /* MTK Terry for RSK Display */
            wgui_handle_inputbox_input();
            /* register the star and hash key handkers */
            /* W06.09 Touch Screen With Keypad V1 */
        #if !defined(__MMI_TOUCH_SCREEN__)
            ZiDisplay();
        #else /* !defined(__MMI_TOUCH_SCREEN__) */ 
            wgui_set_RSK();
            register_multiline_inputbox_keys();
        #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 


#elif defined __MMI_CSTAR__
    #if defined(__MMI_CSTAR_TR_CHINESE__)
    #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
                        case INPUT_MODE_TR_BOPOMO:
    #endif /*     #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) */
    #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
                        case INPUT_MODE_TR_MULTITAP_BOPOMO:
    #endif
                        case INPUT_MODE_TR_STROKE:
    #endif
    #if defined(__MMI_CSTAR_SM_CHINESE__)
    #if defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)
                        case INPUT_MODE_SM_PINYIN:
    #endif
    #if defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)
                        case INPUT_MODE_SM_MULTITAP_PINYIN:
    #endif
                        case INPUT_MODE_SM_STROKE:
    #endif
            
                        case INPUT_MODE_SMART_UPPERCASE_ABC:
                        case INPUT_MODE_SMART_LOWERCASE_ABC:
    #if defined(__MMI_SMART_FIRST_UPPERCASE_ABC__)
                        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
    #endif
        
#if defined(__MMI_CSTAR_THAI__)
                        case INPUT_MODE_SMART_THAI:
#endif
#if defined(__MMI_CSTAR_ARABIC__)
                        case INPUT_MODE_SMART_ARABIC:
#endif
#if defined(__MMI_CSTAR_PERSIAN__)
                        case INPUT_MODE_SMART_PERSIAN:
#endif
#if defined(__MMI_CSTAR_HINDI__)
                        case INPUT_MODE_SMART_HINDI:
#endif
#if defined(__MMI_CSTAR_HEBREW__)
                        case INPUT_MODE_SMART_HEBREW:
#endif
#if defined(__MMI_CSTAR_SPANISH__)
                        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
                        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
#endif
#if defined(__MMI_CSTAR_DANISH__)
                        case INPUT_MODE_SMART_UPPERCASE_DANISH:
                        case INPUT_MODE_SMART_LOWERCASE_DANISH:
#endif
#if defined(__MMI_CSTAR_POLISH__)
                        case INPUT_MODE_SMART_UPPERCASE_POLISH:
                        case INPUT_MODE_SMART_LOWERCASE_POLISH:
#endif
#if defined(__MMI_CSTAR_NORWEGIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
                        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
#endif
#if defined(__MMI_CSTAR_FRENCH__)
                        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
                        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
#endif
#if defined(__MMI_CSTAR_GERMAN__)
                        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
                        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
#endif
#if defined(__MMI_CSTAR_ITALIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
                        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
#endif
#if defined(__MMI_CSTAR_RUSSIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
                        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
#endif
#if defined(__MMI_CSTAR_BULGARIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
                        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
#endif
#if defined(__MMI_CSTAR_TURKISH__)
                        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
                        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
#endif
#if defined(__MMI_CSTAR_PORTUGUESE__)
                        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
                        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
#endif
#if defined(__MMI_CSTAR_INDONESIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
                        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
#endif
#if defined(__MMI_CSTAR_CZECH__)
                        case INPUT_MODE_SMART_UPPERCASE_CZECH:
                        case INPUT_MODE_SMART_LOWERCASE_CZECH:
#endif
#if defined(__MMI_CSTAR_MALAY__)
                        case INPUT_MODE_SMART_UPPERCASE_MALAY:
                        case INPUT_MODE_SMART_LOWERCASE_MALAY:
#endif
#if defined(__MMI_CSTAR_VIETNAMESE__)
                        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
                        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
#endif
        #if defined(__MMI_CSTAR_FINNISH__)
                        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
                        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
        #endif /* defined(__MMI_CSTAR_FINNISH__) */ 
        #if defined(__MMI_CSTAR_HUNGARIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:  
                        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:  
        #endif /* defined(__MMI_CSTAR_HUNGARIAN__) */ 
        #if defined(__MMI_CSTAR_SLOVAK__)
                        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
                        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
        #endif /* defined(__MMI_CSTAR_SLOVAK__) */ 
        #if defined(__MMI_CSTAR_DUTCH__)
                        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
                        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
        #endif /* defined(__MMI_CSTAR_DUTCH__) */ 
        #if defined(__MMI_CSTAR_SWEDISH__)
                        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
                        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
        #endif /* defined(__MMI_CSTAR_SWEDISH__) */ 
                
        #if defined(__MMI_CSTAR_CROATIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
                        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
        #endif /* defined(__MMI_CSTAR_CROATIAN__) */ 
        #if defined(__MMI_CSTAR_ROMANIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
                        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
        #endif /* defined(__MMI_CSTAR_ROMANIAN__) */ 
        #if defined(__MMI_CSTAR_SLOVENIAN__)
                        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
                        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
        #endif /* defined(__MMI_CSTAR_SLOVENIAN__) */ 
                
        #if defined(__MMI_CSTAR_GREEK__)
                        case INPUT_MODE_SMART_UPPERCASE_GREEK:
                        case INPUT_MODE_SMART_LOWERCASE_GREEK:
        #endif /* defined(__MMI_CSTAR_GREEK__) */ 

                CstarChangeInputMethod(mode);
                CstarClearKeyStarAndPoundHandler();
                CstarClearKeyNavigationHandler();
                CstarClearKey0To9Handler();

            if (wgui_register_multiline_inputbox_up_down_key_handler == NULL)
            {
                SetKeyHandler(CstarKeyArrowUpHandler, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            }
            SetKeyHandler(CstarKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(CstarKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            
                SetKeyHandler(CstarKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
                SetKeyHandler(CstarKeyStarPressHandler, KEY_STAR, KEY_EVENT_DOWN);
				
                set_left_softkey_function(CstarKeyLSKPressHandler, KEY_EVENT_DOWN);
            #if defined(__MMI_WITH_C_KEY__)
                SetKeyHandler(CstarKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
                SetKeyHandler(CstarKeyRSKLongPressHandler, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
                set_right_softkey_function(GoBackHistory, KEY_EVENT_DOWN);
            #else
                set_right_softkey_function(CstarKeyRSKPressHandler, KEY_EVENT_DOWN);
                set_right_softkey_function(CstarKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            #endif
            #if defined(__MMI_TOUCH_SCREEN__)
                wgui_set_RSK();
                register_multiline_inputbox_keys();
            #endif
            CstarDisplay();

        #elif defined __MMI_KA__
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_SM_STROKE:
            KonkaChangeInputMethod(mode);
            KonkaClearKeyStarAndPoundHandler();
            KonkaClearKeyNavigationHandler();
            KonkaClearKey0To9Handler();
            clear_right_softkey();
            clear_left_softkey();
            /* set key arrow handler */
            SetKeyHandler(KonkaKeyArrowUPHandler, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKeyArrowRightHandler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKeyArrowLeftHandler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey0PressHandler, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey1PressHandler, KEY_1, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey2PressHandler, KEY_2, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey3PressHandler, KEY_3, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey4PressHandler, KEY_4, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey5PressHandler, KEY_5, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey6PressHandler, KEY_6, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey7PressHandler, KEY_7, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey8PressHandler, KEY_8, KEY_EVENT_DOWN);
            SetKeyHandler(KonkaKey9PressHandler, KEY_9, KEY_EVENT_DOWN);
            /* register the star and hash key handkers */
            /* register the L and R softkey handlers */
            set_right_softkey_function(KonkaKeyRSKPressHandler, KEY_EVENT_DOWN);
            set_right_softkey_function(KonkaKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            set_left_softkey_function(KonkaKeyLSKPressHandler, KEY_EVENT_UP);
            set_left_softkey_function(KonkaKeyLSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            KonkaDisplay();

        #elif defined __MMI_ITAP__
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
            break;
    }

    if (input_type != INPUT_TYPE_NUMERIC &&
        input_type != INPUT_TYPE_DECIMAL_NUMERIC &&
        input_type != INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_KEYPAD_NUMERIC &&
        input_type != INPUT_TYPE_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_PHONE_NUMBER &&
        input_type != INPUT_TYPE_SIGNED_DECIMAL_NUMERIC &&
        input_type != INPUT_TYPE_SIGNED_DECIMAL_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_SIGNED_NUMERIC &&
        input_type != INPUT_TYPE_SIGNED_NUMERIC_PASSWORD &&
        input_type != INPUT_TYPE_NONE)
    {
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__ )
        if (wgui_inputbox_handle_symbol_picker_star_key_down == currKeyFuncPtrs[KEY_STAR][KEY_EVENT_UP])
        {
            ClearKeyHandler(KEY_STAR, KEY_EVENT_UP);
            /* W05.41 Long Press Key * to select symbols when __MMI_MULTITAP_FOR_STAR_AND_POUND__ */
            SetKeyHandler(wgui_inputbox_handle_symbol_picker_star_key_down, KEY_STAR, KEY_LONG_PRESS);
        }
        SetKeyHandler(wgui_handle_symbol_picker_bymultitapthai, KEY_STAR, KEY_LONG_PRESS);

        SetKeyHandler(wgui_handle_inputbox_change_input_mode_bymultitapthai, KEY_POUND, KEY_LONG_PRESS);
        SetKeyHandler(wgui_handle_inputbox_change_input_mode_bymultitapthai, KEY_POUND, KEY_REPEAT);
#else
        SetKeyHandler(wgui_handle_inputbox_change_input_mode, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_inputbox_handle_symbol_picker_star_key_down, KEY_STAR, KEY_EVENT_DOWN);
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    }

    if (wgui_e_dictionary_test_clear_inputbox_buffer != NULL &&
        wgui_e_dictionary_test_clear_inputbox_buffer() == MMI_TRUE)
    {
        multiline_inputbox_delete_all_characters();
    }

    //steven e-dic
    //for multitap ABC,abc,123 to register AP's up/down key handler
    if (wgui_register_multiline_inputbox_up_down_key_handler != NULL)
    {
        wgui_register_multiline_inputbox_up_down_key_handler();
    }

}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_key_handler
 * DESCRIPTION
 *  Keyboard handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Scan code of the key
 *  key_state       [IN]        Key event type (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                multiline_inputbox_previous_character();
                break;
            case 38:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_multi_line_input_box_highlight_cursor_start(&MMI_multiline_inputbox);
                /* gui_multi_line_input_box_highlight_cursor_number(&MMI_multiline_inputbox,3); */
                show_multiline_inputbox();
        #else /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                multiline_inputbox_previous_line();
        #endif /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 39:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        #endif 
                multiline_inputbox_next_character();
                break;
            case 40:
        #if(ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT)
                gui_multi_line_input_box_highlight_cursor_end(&MMI_multiline_inputbox);
                show_multiline_inputbox();
        #else /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                multiline_inputbox_next_line();
        #endif /* (ENABLE_MULTILINE_INPUTBOX_TEST_WORD_HIGHLIGHT) */ 
                break;
            case 36:
                multiline_inputbox_home();
                break;
            case 35:
                multiline_inputbox_end();
                break;
            case 33:
                multiline_inputbox_previous_page();
                break;
            case 34:
                multiline_inputbox_next_page();
                break;
            case 45:
                multiline_inputbox_toggle_insert_mode();
                break;
            case 46:
                multiline_inputbox_delete_current_character();
                break;

        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_keys
 * DESCRIPTION
 *  Registers the keys for the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
extern S8 MMI_multi_line_inputbox_present;
#endif 
void register_multiline_inputbox_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(multiline_inputbox_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    if (MMI_multi_line_inputbox_present)
    {
        SetKeyHandler(multiline_inscreen_inputbox_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(multiline_inscreen_inputbox_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(multiline_inscreen_inputbox_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(multiline_inscreen_inputbox_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
    else
    {
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
        SetKeyHandler(multiline_inputbox_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(multiline_inputbox_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
    }
    #endif 
    /* SetKeyHandler(multiline_inputbox_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    register_keyboard_key_handler(multiline_inputbox_key_handler);
    /* Add key handlers here for Clear and input mode key */
}

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
/* Pixtel - Gurinder - 2/6/4 - Function to register arrow key function pointers for inscreen multiline box. */


/*****************************************************************************
 * FUNCTION
 *  register_inscreen_multiline_inputbox_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_inscreen_multiline_inputbox_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(multiline_inputbox_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inscreen_inputbox_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inscreen_inputbox_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(multiline_inputbox_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    register_keyboard_key_handler(multiline_inputbox_key_handler);
}
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 

// #ifdef __MMI_PLUTO_GPRS__


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_previous_line_sms_chat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_previous_line_sms_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /* Gurinder - 7/5/2004 - Scroll to the height of screen. */
    S32 move = (MMI_multiline_inputbox.max_line_height > 0) ?
        ((MMI_multiline_inputbox.height / MMI_multiline_inputbox.max_line_height) - 1) : 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < move; index++)
    {
        multiline_inputbox_previous_line();
    }

}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_next_line_sms_chat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_next_line_sms_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /* Gurinder - 7/5/2004 - Scroll to the height of screen. */
    S32 move = (MMI_multiline_inputbox.max_line_height > 0) ?
        ((MMI_multiline_inputbox.height / MMI_multiline_inputbox.max_line_height) - 1) : 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < move; index++)
    {
        multiline_inputbox_next_line();
    }

}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_sms_chat_inputbox_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_sms_chat_inputbox_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                break;
            case 38:
                multiline_inputbox_previous_line_sms_chat();

                break;
            case 39:
                break;
            case 40:
                multiline_inputbox_next_line_sms_chat();

                break;
            case 36:
                break;
            case 35:
                break;
            case 33:
                break;
            case 34:
                break;
            case 45:
                break;
            case 46:
                break;

        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_sms_chat_inputbox_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_sms_chat_inputbox_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(multiline_inputbox_previous_line_sms_chat, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_previous_line_sms_chat, KEY_UP_ARROW, KEY_REPEAT);
    SetKeyHandler(multiline_inputbox_next_line_sms_chat, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_line_sms_chat, KEY_DOWN_ARROW, KEY_REPEAT);
    register_keyboard_key_handler(register_multiline_sms_chat_inputbox_key_handler);
    /* Add key handlers here for Clear and input mode key */
}

// #endif


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_viewer_key_handler
 * DESCRIPTION
 *  Keyboard handler for the multiline inputbox
 *  
 *  Internal function
 * PARAMETERS
 *  vkey_code       [IN]        Scan code of the key
 *  key_state       [IN]        Key event type (up, down...)
 * RETURNS
 *  void
 *****************************************************************************/
void multiline_inputbox_viewer_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:    /* multiline inputbox viewer supports only two way navigation  */
                /* multiline_inputbox_previous_character(); */
                break;
            case 38:
                multiline_inputbox_previous_line();
                break;
            case 39:    /* multiline inputbox viewer supports only two way navigation  */
                /* multiline_inputbox_next_character(); */
                break;
            case 40:
                multiline_inputbox_next_line();
                break;
            case 36:
                multiline_inputbox_home();
                break;
            case 35:
                multiline_inputbox_end();
                break;
            case 33:
                multiline_inputbox_previous_page();
                break;
            case 34:
                multiline_inputbox_next_page();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_viewer_keys
 * DESCRIPTION
 *  Registers the keys for the multiline inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_inputbox_viewer_keys(void)
{   /* multiline inputbox viewer supports only two way navigation  */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetKeyHandler(multiline_inputbox_previous_character,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    //SetKeyHandler(multiline_inputbox_next_character,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_previous_line, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_line, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    //Gurinder - 28/4/2004 - Move Contents To Top In Inscreen Multiline Readonly
    //#if defined(__MMI_PLUTO_GPRS__)
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_INSIDE_INLINE_MENU)
    {
        SetKeyHandler(multiline_inputbox_home, KEY_UP_ARROW, KEY_LONG_PRESS);
        SetKeyHandler(multiline_inputbox_home, KEY_UP_ARROW, KEY_LONG_PRESS);
    }
    // #endif
    register_keyboard_key_handler(multiline_inputbox_viewer_key_handler);
}
/* barcode */


/*****************************************************************************
 * FUNCTION
 *  wgui_multiline_inputbox_previous_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_multiline_inputbox_previous_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_go_to_pre_hilite(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_multiline_inputbox_next_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_multiline_inputbox_next_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_multi_line_input_box_go_to_next_hilite(&MMI_multiline_inputbox);
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_hilite_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_inputbox_hilite_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(wgui_multiline_inputbox_previous_hilite, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_multiline_inputbox_next_hilite, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(wgui_multiline_inputbox_previous_hilite, KEY_VOL_UP, KEY_EVENT_UP);
    //SetKeyHandler(wgui_multiline_inputbox_next_hilite, KEY_VOL_DOWN, KEY_EVENT_UP);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  wgui_multiline_inputbox_hilite_pen_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_multiline_inputbox_hilite_pen_down_handler(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    gui_multi_line_input_box_pen_enum multi_line_input_box_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gui_multi_line_input_box_translate_pen_event(
            &MMI_multiline_inputbox,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &multi_line_input_box_event);
    if ((ret == MMI_TRUE) && (multi_line_input_box_event != GUI_MULTI_LINE_INPUT_BOX_PEN_SCROLL_BAR))
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        gui_show_multi_line_input_box_ext(&MMI_multiline_inputbox, pos.x, pos.y);
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        if (gui_multi_line_input_box_is_pen_down_in_hilite(&MMI_multiline_inputbox))
        {
            wgui_multi_line_set_pen_down_flag();
            gui_multi_line_input_box_go_to_hilite(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.current_hilite_idx,
                MMI_FALSE);
            wgui_multi_line_clear_pen_down_flag();
        }
        else
        {
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            gui_BLT_double_buffer(MMI_multiline_inputbox.x, MMI_multiline_inputbox.y, MMI_multiline_inputbox.x + MMI_multiline_inputbox.width, 
                MMI_multiline_inputbox.y + MMI_multiline_inputbox.height);
        }
    }
    else
    {
        wgui_general_pen_down_hdlr(pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  register_multiline_inputbox_hilite_pen_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_multiline_inputbox_hilite_pen_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_down_handler(wgui_multiline_inputbox_hilite_pen_down_handler);
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  set_multiline_inputbox_mask
 * DESCRIPTION
 *  Sets character masking for the multiline inputbox
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void set_multiline_inputbox_mask(U8 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (m)
    {
        case 0:
            MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  reset_multiline_inputbox
 * DESCRIPTION
 *  Clears the keyhandlers for the multiline inputbox
 * PARAMETERS
 *  void
 *  m(?)        [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void reset_multiline_inputbox(void)
{
#if(UI_BLINKING_CURSOR_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_multiline_inputbox_end_frame);
    wgui_multiline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 
    gui_cancel_timer(multiline_inputbox_vertical_scroll);

    g_mmi_wgui_halfline_marquee_scroll_enable = 0;  /* Disable it here */

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    clear_multitap_key_handlers();
    /* The callback function might be invalid after screen exit function */
    MMI_multiline_inputbox.icon_callback = NULL;
    multiline_inputbox_input_callback = UI_dummy_function;
    multiline_inputbox_navigate_callback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  reset_multiline_inputbox_vertical_scroll
 * DESCRIPTION
 *  Resets the multiline input bix vertical scroll timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_multiline_inputbox_vertical_scroll()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(multiline_inputbox_vertical_scroll);
#if(UI_BLINKING_CURSOR_SUPPORT)
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);
#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_multiline_inputbox_end_frame);
    wgui_multiline_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_MULTILINE_INPUTBOX_FRAME_SKIPPING)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 multiline_inputbox_empty(void)
{
#ifdef __ASCII
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.text_length <= 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
#endif /* __ASCII */ 
#ifdef __UCS2_ENCODING
    if (MMI_multiline_inputbox.text_length <= 2)
    {
        return (1);
    }
    else
    {
        return (0);
    }
#endif /* __UCS2_ENCODING */ 
}


/*****************************************************************************
 * FUNCTION
 *  multiline_inputbox_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 multiline_inputbox_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Function is not accurate. Should actually return the number of characters, not including the end of string character */
#ifdef __ASCII
    return (MMI_multiline_inputbox.text_length);
#endif 
#ifdef __UCS2_ENCODING
    return (MMI_multiline_inputbox.text_length / 2);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  get_multiline_inputbox_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 get_multiline_inputbox_line_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.max_line_height == 0)
    {
        return (1);
    }
    else
    {
        return (MMI_multiline_inputbox.max_line_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_multiline_inputbox_display_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL get_multiline_inputbox_display_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_multiline_inputbox_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 get_multiline_inputbox_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_multiline_inputbox.height;
}


/*****************************************************************************
 * FUNCTION
 *  get_multiline_inputbox_line_height_with_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 get_multiline_inputbox_line_height_with_obj(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        return 0;
    }

    if (b->max_line_height == 0)
    {
        return (1);
    }
    else
    {
        return (b->max_line_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_multiline_inputbox_in_view_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL is_multiline_inputbox_in_view_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/* 
 * General multiline inputbox icon handler provided by WGUI.
 *
 * Applications can create its own icon handlers or use wgui_general_multiline_icon_handler()
 */

typedef struct
{
    BOOL is_sorted;
    S32 num_items;
    const wgui_multiline_icon_struct *items, *last_items;
} wgui_multiline_icon_handler_struct;

static wgui_multiline_icon_handler_struct g_mmi_wgui_multiline_icon_handler_cntx;


/*****************************************************************************
 * FUNCTION
 *  wgui_config_general_multiline_icon_handler
 * DESCRIPTION
 *  setup general icon handler that can be used inside multiline_input_box
 * PARAMETERS
 *  is_sorted       [IN]        If there are many types of icons, it is suggested
 *  num_items       [IN]        The number of icon types available
 *  items           [IN]        Icon types
 *  to(?)           [IN]        Sort them by gui_multiline_icon_item_struct.string.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_config_general_multiline_icon_handler(BOOL is_sorted, U8 num_items, const wgui_multiline_icon_struct *items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgui_multiline_icon_handler_cntx.is_sorted = is_sorted;
    g_mmi_wgui_multiline_icon_handler_cntx.num_items = num_items;
    g_mmi_wgui_multiline_icon_handler_cntx.items = items;
    g_mmi_wgui_multiline_icon_handler_cntx.last_items = items + num_items - 1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_general_multiline_icon_handler
 * DESCRIPTION
 *  Reset general icon handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_general_multiline_icon_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wgui_multiline_icon_handler_cntx.is_sorted = MMI_FALSE;
    g_mmi_wgui_multiline_icon_handler_cntx.num_items = 0;
    g_mmi_wgui_multiline_icon_handler_cntx.items = NULL;
    g_mmi_wgui_multiline_icon_handler_cntx.last_items = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_general_multiline_icon_handler
 * DESCRIPTION
 *  setup general icon handler that can be used inside multiline_input_box
 * PARAMETERS
 *  s               [IN]        Input string
 *  do_draw         [IN]        Whether to draw the icon
 *  icon_width      [OUT]       
 *  icon_height     [OUT]       
 *  x               [IN]        X-axis of icon position
 *  y               [IN]        Y-axis of icon position
 * RETURNS
 *  the number of character in the icon sequence.
 *****************************************************************************/
S32 wgui_general_multiline_icon_handler(const U8 *s, BOOL do_draw, S32 *icon_width, S32 *icon_height, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL found = MMI_FALSE;
    const wgui_multiline_icon_struct *item;
    S32 char_cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_wgui_multiline_icon_handler_cntx.is_sorted)   /* Use binary search */
    {
        S32 l, r, x;
        const char *t1, *t2;

        l = 0;
        r = g_mmi_wgui_multiline_icon_handler_cntx.num_items - 1;

        while (r >= l)
        {
            x = ((l + r) >> 1);
            item = g_mmi_wgui_multiline_icon_handler_cntx.items + x;

            t1 = item->string;
            t2 = item->string + MMI_MULTILINE_ICON_MAX_STRING_LEN;
            char_cnt = 0;
            for (; t1 <= t2; t1++, char_cnt++)
            {
                S32 char_cnt2 = char_cnt << 1;

                if (!*t1)
                {
                    found = MMI_TRUE;
                    break;
                }
                if (s[char_cnt2 + 1] || ((U8) * t1 < s[char_cnt2]))
                {
                    l = x + 1;
                    break;
                }
                if ((U8) * t1 > s[char_cnt2])
                {
                    r = x - 1;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }
    else    /* Use linear search */
    {
        const wgui_multiline_icon_struct *last_item;
        const char *t1, *t2;

        item = g_mmi_wgui_multiline_icon_handler_cntx.items;
        last_item = g_mmi_wgui_multiline_icon_handler_cntx.last_items;
        for (; item <= last_item; item++)
        {
            t1 = item->string;
            t2 = item->string + MMI_MULTILINE_ICON_MAX_STRING_LEN;
            char_cnt = 0;
            for (; t1 <= t2; t1++, char_cnt++)
            {
                S32 char_cnt2 = char_cnt << 1;

                if (!*t1)
                {
                    found = MMI_TRUE;
                    break;
                }
                if (s[char_cnt2 + 1] || (U8) * t1 != s[char_cnt2])
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }

    if (found)
    {
        if (do_draw)
        {
            gui_show_transparent_image(x, y, item->icon, 0);
        }
        if (icon_width)
        {
            *icon_width = (S32) item->icon_width;
        }
        if (icon_height)
        {
            *icon_height = (S32) item->icon_height;
        }
        return char_cnt;
    }
    else
    {
        return 0;
    }
}

/* 
 * API to read/write color editor buffer (UI_MULTI_LINE_INPUT_BOX_RICHTEXT) 
 * Please refer to gui_inputs.h for color buffer format
 */


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_create_reader
 * DESCRIPTION
 *  Create a reader object for buffer containing text format
 *  
 *  1.  The reader object can be released in memory directly.
 *  There is no other API to release it explicitly.
 *  2. If the content of 'buffer' is modified externally,
 *  reader object should be re-created.
 * PARAMETERS
 *  reader      [IN]        A reader object
 *  buffer      [IN]        Source text buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_color_buffer_create_reader(wgui_color_buffer_reader_struct *reader, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reader->buffer = buffer;
    reader->head = 0;
    reader->byte_count = (mmi_ucs2strlen((S8*) buffer) << 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_read_stripped_text
 * DESCRIPTION
 *  Create a reader object for buffer containing text format
 *  
 *  dest_buffer will be null terminated
 * PARAMETERS
 *  reader              [IN]        A reader object
 *  dest_buffer         [IN]        Destination buffer
 *  size_of_dest        [IN]        Destination buffer size (including '\0')
 *  bytes_written       [OUT]       Number of bytes written into 'dest_buffer' (including '\0')
 * RETURNS
 *  Whether there are more bytes left to read
 *****************************************************************************/
BOOL wgui_color_buffer_read_stripped_text(
        wgui_color_buffer_reader_struct *reader,
        U8 *dest_buffer,
        S32 size_of_dest,
        S32 *bytes_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rest, dst_cnt;
    U8 *src_ptr, *src_end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rest = reader->byte_count - reader->head;

    /* At least two bytes are reserved for  */
    MMI_DBG_ASSERT(rest >= 0 && (rest % 2) == 0 && size_of_dest > 2);

    size_of_dest -= (size_of_dest % 2);
    size_of_dest -= 2;

    if (rest == 0 || size_of_dest <= 0)
    {
        return (rest > 0);
    }

    src_ptr = reader->buffer + reader->head;
    src_end = reader->buffer + reader->byte_count;
    for (dst_cnt = 0; src_ptr < src_end && dst_cnt < size_of_dest; src_ptr += 2)
    {
        U16 ch = ((U16) src_ptr[0]) | (((U16) src_ptr[1]) << 8);

        if (ch < GUI_INPUT_MARKER_BEGIN || ch > GUI_INPUT_MARKER_END)
        {
            dest_buffer[dst_cnt++] = src_ptr[0];
            dest_buffer[dst_cnt++] = src_ptr[1];
        }
    }
    dest_buffer[dst_cnt++] = '\0';
    dest_buffer[dst_cnt++] = '\0';

    *bytes_written = dst_cnt;
    reader->head = src_ptr - reader->buffer;

    if (src_ptr >= src_end)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_create_writer
 * DESCRIPTION
 *  Create a writer object for buffer containing text format
 *  
 *  1.  The writer object can be released in memory directly.
 *  There is no other API to release it explicitly.
 *  2. If the content of 'buffer' is modified externally,
 *  writer object should be re-created.
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  buffer      [IN]        Destination text buffer
 *  size        [IN]        Size of buffer in bytes
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_color_buffer_create_writer(wgui_color_buffer_writer_struct *writer, U8 *buffer, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    writer->buffer = buffer;
    writer->tail = (mmi_ucs2strlen((S8*) buffer) << 1);
    writer->size = size - (size % 2);
    MMI_DBG_ASSERT(writer->size >= writer->tail + 2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_get_space_for_write
 * DESCRIPTION
 *  Get the empty space in the destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 * RETURNS
 *  Number of bytes available to write (excl. '\0')
 *****************************************************************************/
S32 wgui_color_buffer_get_space_for_write(wgui_color_buffer_writer_struct *writer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = writer->size - writer->tail - 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret < 0)
    {
        ret = 0;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_write_char
 * DESCRIPTION
 *  Append a character in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch          [IN]        Character
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_color_buffer_write_char(wgui_color_buffer_writer_struct *writer, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 4)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch & 0xFF);
        *dst_ptr++ = (U8) ((ch >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 2;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_write_2char
 * DESCRIPTION
 *  Append two characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_color_buffer_write_2char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 6)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 4;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_write_3char
 * DESCRIPTION
 *  Append three characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 *  ch3         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_color_buffer_write_3char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2, U16 ch3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 8)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch3 & 0xFF);
        *dst_ptr++ = (U8) ((ch3 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 6;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_write_4char
 * DESCRIPTION
 *  Append four characters in destination buffer
 * PARAMETERS
 *  writer      [IN]        A writer object
 *  ch1         [IN]        Characters
 *  ch2         [IN]        Characters
 *  ch3         [IN]        Characters
 *  ch4         [IN]        Characters
 * RETURNS
 *  Is written successfully
 *****************************************************************************/
BOOL wgui_color_buffer_write_4char(wgui_color_buffer_writer_struct *writer, U16 ch1, U16 ch2, U16 ch3, U16 ch4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->size - writer->tail >= 10)
    {
        U8 *dst_ptr = writer->buffer + writer->tail;

        *dst_ptr++ = (U8) (ch1 & 0xFF);
        *dst_ptr++ = (U8) ((ch1 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch2 & 0xFF);
        *dst_ptr++ = (U8) ((ch2 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch3 & 0xFF);
        *dst_ptr++ = (U8) ((ch3 >> 8) & 0xFF);
        *dst_ptr++ = (U8) (ch4 & 0xFF);
        *dst_ptr++ = (U8) ((ch4 >> 8) & 0xFF);
        *dst_ptr++ = '\0';
        *dst_ptr++ = '\0';
        writer->tail += 8;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_color_buffer_write_string
 * DESCRIPTION
 *  Append a string in destination buffer
 *  
 *  The writer object can be released in memory directly.
 *  There is no other API to release it explicitly.
 * PARAMETERS
 *  writer                      [IN]        A writer object
 *  string                      [IN]        Destination text buffer
 *  allow_partial_write         [IN]        If destination buffer does not have enough space
 *  whole_string_written        [OUT]       The whole string is written
 *  for(?)                      [IN]        The whole string, write partial string?
 * RETURNS
 *  Number of bytes written (excluding '\0')
 *****************************************************************************/
S32 wgui_color_buffer_write_string(
        wgui_color_buffer_writer_struct *writer,
        const U8 *string,
        BOOL allow_partial_write,
        BOOL *whole_string_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_size = (mmi_ucs2strlen((S8*) string) << 1);
    const U8 *src, *src_end;
    U8 *dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (writer->tail + str_size + 2 > writer->size)
    {
        if (!allow_partial_write)
        {
            return 0;
        }
        else
        {
            *whole_string_written = MMI_FALSE;
            str_size = writer->size - writer->tail - 2;
        }
    }
    else
    {
        *whole_string_written = MMI_TRUE;
    }
    src = string;
    src_end = string + str_size;
    dst = writer->buffer + writer->tail;
    while (src < src_end)
    {
        *dst++ = *src++;
    }
    *dst++ = '\0';
    *dst++ = '\0';
    writer->tail += str_size;

    return str_size;
}

/* dialer input box wrappers        */

void (*dialer_inputbox_input_callback) (void) = UI_dummy_function;
void (*dialer_inputbox_navigate_callback) (void) = UI_dummy_function;
dialer_input_box MMI_dialer_inputbox;
S32 wgui_dialer_inputbox_buffer_size = 0;
U8 wgui_dialer_inputbox_plus_character_flag = 0;

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
S32 wgui_dialer_inputbox_frame_counter = 0;
#endif 


/*****************************************************************************
 * FUNCTION
 *  create_dialer_inputbox
 * DESCRIPTION
 *  Creates a dialer inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void create_dialer_inputbox(UI_string_type buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_dialer_inputbox_plus_character_flag = 0;
    wgui_dialer_inputbox_buffer_size = buffer_length;
    dialer_inputbox_input_callback = UI_dummy_function;
    dialer_inputbox_navigate_callback = UI_dummy_function;
    gui_create_dialer_input_box_use_buffer(
        &MMI_dialer_inputbox,
        MMI_general_inputbox_x,
        MMI_general_inputbox_y,
        MMI_general_inputbox_width,
        MMI_general_inputbox_height,
        buffer,
        buffer_length);
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    wgui_dialer_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  create_dialer_inputbox_set_buffer
 * DESCRIPTION
 *  Creates a dialer inputbox
 * PARAMETERS
 *  buffer              [IN]        
 *  buffer_length       [IN]        
 *  text_length         [IN]        
 *  edit_position       [IN]        
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void create_dialer_inputbox_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_dialer_inputbox_plus_character_flag = 0;
    wgui_dialer_inputbox_buffer_size = buffer_length;
    dialer_inputbox_input_callback = UI_dummy_function;
    dialer_inputbox_navigate_callback = UI_dummy_function;
    /* Warning: Temporary change only UCS2 / ASCII. This has to be done in a more formal manner  */
#ifdef __UCS2_ENCODING
    gui_create_dialer_input_box_set_buffer(
        &MMI_dialer_inputbox,
        MMI_general_inputbox_x,
        MMI_general_inputbox_y,
        MMI_general_inputbox_width,
        MMI_general_inputbox_height,
        buffer,
        buffer_length * 2,
        (text_length + 1) * 2,
        edit_position);
#endif /* __UCS2_ENCODING */ 
#ifdef __ASCII
    gui_create_dialer_input_box_set_buffer(
        &MMI_dialer_inputbox,
        MMI_dialer_inputbox_x,
        MMI_dialer_inputbox_y,
        MMI_dialer_inputbox_width,
        MMI_dialer_inputbox_height,
        buffer,
        buffer_length,
        text_length + 1,
        edit_position);
#endif /* __ASCII */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    wgui_dialer_inputbox_frame_counter = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  show_dialer_inputbox
 * DESCRIPTION
 *  Displays the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_dialer_inputbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_dialer_input_box(&MMI_dialer_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_dialer_inputbox.x,
        MMI_dialer_inputbox.y,
        MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
        MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_dialer_inputbox_end_frame
 * DESCRIPTION
 *  Redraws the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))

void wgui_dialer_inputbox_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_dialer_inputbox_frame_counter >= 1)
    {
        gui_show_dialer_input_box(&MMI_dialer_inputbox);
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_BLT_double_buffer(
            MMI_dialer_inputbox.x,
            MMI_dialer_inputbox.y,
            MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
            MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
        wgui_dialer_inputbox_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_dialer_inputbox_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  redraw_dialer_inputbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_dialer_inputbox(void)
{
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_dialer_inputbox_frame_counter > 0)
    {
        wgui_dialer_inputbox_frame_counter++;
    }
    else
    {
        wgui_dialer_inputbox_frame_counter = 1;
        gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_dialer_inputbox_end_frame);
    }
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 

    gui_show_dialer_input_box(&MMI_dialer_inputbox);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(
        MMI_dialer_inputbox.x,
        MMI_dialer_inputbox.y,
        MMI_dialer_inputbox.x + MMI_dialer_inputbox.width,
        MMI_dialer_inputbox.y + MMI_dialer_inputbox.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_handle_plus_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_handle_plus_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_dialer_inputbox.text[0] == '+')
    {
        MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        wgui_dialer_inputbox_plus_character_flag = 1;
    }
    else
    {
        if (wgui_dialer_inputbox_plus_character_flag)
        {
            U8 done = 0;
            UI_buffer_type current_position = MMI_dialer_inputbox.text;
            UI_buffer_type previous_position = MMI_dialer_inputbox.text;
            UI_character_type c;

            wgui_dialer_inputbox_plus_character_flag = 0;
            MMI_dialer_inputbox.available_length = wgui_dialer_inputbox_buffer_size * ENCODING_LENGTH;
            if (MMI_dialer_inputbox.text_length > MMI_dialer_inputbox.allocated_length)
            {
                MMI_dialer_inputbox.text_length -= ENCODING_LENGTH;
                UI_STRING_GET_NEXT_CHARACTER(current_position, c);
                while (!done)
                {
                    UI_STRING_GET_NEXT_CHARACTER(current_position, c);
                    UI_STRING_INSERT_CHARACTER(previous_position, c);
                    if (UI_STRING_END_OF_STRING_CHARACTER(c))
                    {
                        done = 1;
                    }
                }

                UI_STRING_GET_PREVIOUS_CHARACTER(previous_position, c);
                MMI_dialer_inputbox.last_position_p = previous_position;
                if (MMI_dialer_inputbox.current_text_p != MMI_dialer_inputbox.text)
                {
                    UI_STRING_GET_PREVIOUS_CHARACTER(MMI_dialer_inputbox.current_text_p, c);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_multitap_input
 * DESCRIPTION
 *  Inserts a multitap character
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_multitap_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_insert_multitap_character(&MMI_dialer_inputbox, c);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_multitap_input_complete
 * DESCRIPTION
 *  Completes a multitap input sequence
 *  
 *  Normally called by multitap objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_multitap_input_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_confirm_multitap_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_direct_input
 * DESCRIPTION
 *  inserts a character at cursor position
 *  
 *  Normally registered to a keyboard input handler
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_direct_input(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_dialer_inputbox.text[0] == '+')
    {
        MMI_dialer_inputbox.available_length = (wgui_dialer_inputbox_buffer_size + 1) * ENCODING_LENGTH;
        wgui_dialer_inputbox_plus_character_flag = 1;
    }

    gui_dialer_input_box_insert_character(&MMI_dialer_inputbox, c);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_delete_character
 * DESCRIPTION
 *  deletes a character at cursor position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_delete_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_previous_character
 * DESCRIPTION
 *  Moves the cursor to the previous character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_previous(&MMI_dialer_inputbox);
    redraw_dialer_inputbox();
    dialer_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_next_character
 * DESCRIPTION
 *  Moves the cursor to the next character
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_next(&MMI_dialer_inputbox);
    redraw_dialer_inputbox();
    dialer_inputbox_navigate_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_toggle_insert_mode
 * DESCRIPTION
 *  Toggles between insert and overwrite modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_toggle_insert_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_toggle_insert_mode(&MMI_dialer_inputbox);
    redraw_dialer_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_delete_current_character
 * DESCRIPTION
 *  Deletes a character at the cursor position (Delete)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_delete_current_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_current_character(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_delete_all_characters
 * DESCRIPTION
 *  Deletes all characters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_delete_all_characters(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_input_box_delete_all(&MMI_dialer_inputbox);
    if (MMI_dialer_inputbox.flags & UI_DIALER_INPUT_BOX_PLUS_CHARACTER_HANDLING)
    {
        dialer_inputbox_handle_plus_key();
    }
    redraw_dialer_inputbox();
    dialer_inputbox_input_callback();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_alphabetic_keyboard_input_handler
 * DESCRIPTION
 *  alphanumeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_alphabetic_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keyc > 0x1f)
    {
        dialer_inputbox_direct_input((U8) keyc);
    }
    else if (keyc == 0x08)
    {
        dialer_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        dialer_inputbox_delete_all_characters();
    }
    else if (keyc == 0x0d);
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_numeric_keyboard_input_handler
 * DESCRIPTION
 *  numeric keyboard input handler
 *  
 *  Internal function
 * PARAMETERS
 *  keyc        [IN]        Is the character code of a key (ASCII)
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_numeric_keyboard_input_handler(S32 keyc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((keyc >= '0' && keyc <= '9') || (keyc == '-') || (keyc == '+') || (keyc == '*') || (keyc == '#'))
    {
        dialer_inputbox_direct_input((UI_character_type) keyc);
    }
    else if (keyc == 0x08)
    {
        dialer_inputbox_delete_character();
    }
    else if (keyc == 0x1b)
    {
        dialer_inputbox_delete_all_characters();
    }
}


/*****************************************************************************
 * FUNCTION
 *  change_dialer_inputbox_mode
 * DESCRIPTION
 *  Changes the input mode of the dialer inputbox
 * PARAMETERS
 *  mode        [IN]        0: Uppercase, 1: lowercase, 2: Numeric
 * RETURNS
 *  void
 *****************************************************************************/
void change_dialer_inputbox_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case 0:
            change_multitap_mode(0);
            register_multitap_key_handlers();
            register_keyboard_input_handler(dialer_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(dialer_inputbox_multitap_input, dialer_inputbox_multitap_input_complete);
            break;
        case 1:
            change_multitap_mode(1);
            register_multitap_key_handlers();
            register_keyboard_input_handler(dialer_inputbox_alphabetic_keyboard_input_handler);
            set_multitap_functions(dialer_inputbox_multitap_input, dialer_inputbox_multitap_input_complete);
            break;
        case 2:
            change_multitap_mode(2);
            clear_multitap_key_handlers();
            register_MMI_key_input_handler();
            register_key_down_handler(dialer_inputbox_handle_key_down);
            register_keyboard_input_handler(dialer_inputbox_numeric_keyboard_input_handler);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_next_line
 * DESCRIPTION
 *  move to net line of dialer inputr box
 * PARAMETERS
 *  b       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_next_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->current_text_p, prev_text_p, temp_text_p;
    UI_buffer_type backup_curret_text_p = b->current_text_p;
    UI_character_type current_character;

    /* U8 index = 0;  */
    S32 character_height = gui_get_character_height();
    S32 cur_x = b->cursor_x + 1;
    S32 cur_y = b->cursor_y + 1;
    S32 x1, y1, x2, y2;
    S32 text_x, text_y, text_gap, character_width;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_gap = b->text_gap;
    x1 = b->x;
    y1 = b->y;

    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;

    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    text_x = cur_x;
    text_y = cur_y;

    temp_text_p = current_text_p;
    if (b->n_lines > 0)
    {
        cur_y = cur_y - character_height;

        do
        {
            prev_text_p = current_text_p;
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
            {
                if (text_y != cur_y)
                {
                    b->current_text_p = temp_text_p;
                    return;
                }
                if (prev_text_p)
                {
                    b->current_text_p = prev_text_p;
                }
                return;
            }
            character_width = gui_get_character_width(current_character);
            text_x = (text_x - (character_width + text_gap));

            if (text_x < x1)
            {
                text_x = x2 - 4;
                text_y -= character_height;

                if (text_y < y1)
                {
                    b->current_text_p = backup_curret_text_p;
                    UI_editor_play_tone_cannot_navigate();
                    return;
                }
            }
            b->current_text_p = prev_text_p;

            if ((text_y == cur_y) && ((text_x == cur_x) || (text_x < cur_x)))
            {
                flag = 1;
            }

        } while ((flag == 0));

    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
        return;

    }
    UI_UNUSED_PARAMETER(y2);
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_next_line
 * DESCRIPTION
 *  move to next line of dialer inputr box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_next_line(void)
{
    S32 y1, y2;
    S32 y_up;
    S32 character_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(MMI_dialer_inputbox.text_font);
    character_height = gui_get_character_height();

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_up = y2 - character_height * (MMI_dialer_inputbox.n_lines - 1) - character_height/2;

    
    if (MMI_dialer_inputbox.n_lines > 1
        && MMI_dialer_inputbox.cursor_y > y_up)
    {
        gui_dialer_input_box_next_line(&MMI_dialer_inputbox);
        redraw_dialer_inputbox();
        dialer_inputbox_navigate_callback();
    }
    else
        UI_editor_play_tone_cannot_navigate();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_input_box_prev_line
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  b       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_input_box_prev_line(dialer_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type current_text_p = b->last_position_p, prev_text_p, temp_text_p;
    UI_character_type current_character;
    S32 character_height = gui_get_character_height();
    S32 cur_x = b->cursor_x + 1;
    S32 cur_y = b->cursor_y + 1;
    S32 x1, y1, x2, y2;
    S32 text_x, text_y, text_gap, character_width;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_gap = b->text_gap;
    x1 = b->x;
    y1 = b->y;

    x2 = x1 + b->width - 1;
    y2 = y1 + b->height - 1;

    if (b->text == NULL)
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }

    text_x = x2 - 4;

#if( defined(__MMI_TOUCH_DIAL_SCREEN__))
    text_y = y2 - character_height + 2;
#else 
    text_y = y2 - character_height - 1; /* previous implementation */
#endif 
    
    temp_text_p = current_text_p;
    if (b->n_lines > 0)
    {
        cur_y = cur_y + character_height;
        do
        {
            prev_text_p = current_text_p;
            UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p, current_character);
            if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
            {
                if (text_y != cur_y)
                {
                    prev_text_p = temp_text_p;
                }
                if (prev_text_p)
                {
                    b->current_text_p = prev_text_p;
                }
                return;
            }

            character_width = gui_get_character_width(current_character);

            b->current_text_p = prev_text_p;
            if ((text_y == cur_y) && ((text_x == cur_x) || (text_x < cur_x)))
            {
                flag = 1;
            }
            /* MTK Terry for dialer box Key Down Issue */
            text_x = (text_x - (character_width + text_gap));
            /* MTK Terry for dialer box Key Down Issue when lines > 2 */
            if (text_x < x1)
            {
                text_x = x2 - 4;
                text_y -= character_height;
                UI_STRING_GET_NEXT_CHARACTER(current_text_p, current_character);
                if (text_y < y1)
                {
                    break;
                }
            }
        } while ((flag == 0));
    }
    else
    {
        UI_editor_play_tone_cannot_navigate();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_prev_line
 * DESCRIPTION
 *  move to prev line of dialer inputr box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_prev_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    S32 y_last;
    S32 character_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(MMI_dialer_inputbox.text_font);
    character_height = gui_get_character_height();

    y1 = MMI_dialer_inputbox.y;
    y2 = y1 + MMI_dialer_inputbox.height - 1;
    y_last = y2 - character_height - 2;

    if ((MMI_dialer_inputbox.cursor_y + 1) < y_last)
    {
        gui_dialer_input_box_prev_line(&MMI_dialer_inputbox);
        redraw_dialer_inputbox();
        dialer_inputbox_navigate_callback();
    }
    else
        UI_editor_play_tone_cannot_navigate();
}


/*****************************************************************************
 * FUNCTION
 *  dialer_inputbox_key_handler
 * DESCRIPTION
 *  dialer input box key handlers
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dialer_inputbox_key_handler(S32 vkey_code, S32 key_state)
{
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_state)
    {
        switch (vkey_code)
        {
            case 37:
                dialer_inputbox_previous_character();
                break;
            case 38:
                dialer_inputbox_next_line();    /* up */
                break;
            case 39:
                dialer_inputbox_next_character();
                break;
            case 40:
                dialer_inputbox_prev_line();    /* down */
                break;
            case 36:                            /* home */
                break;
            case 35:                            /* end */
                break;
            case 33:                            /* page up */
                break;
            case 34:                            /* page down */
                break;
            case 45:
                dialer_inputbox_toggle_insert_mode();
                break;
            case 46:
                dialer_inputbox_delete_current_character();
                break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_dialer_inputbox_keys
 * DESCRIPTION
 *  Registers the keys for the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dialer_inputbox_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(dialer_inputbox_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dialer_inputbox_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* SetKeyHandler(dialer_inputbox_delete_character,KEY_CLEAR,KEY_EVENT_DOWN); */
    SetKeyHandler(dialer_inputbox_next_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(dialer_inputbox_prev_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    register_keyboard_key_handler(dialer_inputbox_key_handler);
    /* Add key handlers here for Clear key and input mode key   */
}


/*****************************************************************************
 * FUNCTION
 *  set_dialer_inputbox_mask
 * DESCRIPTION
 *  Sets masked display of characters
 * PARAMETERS
 *  m       [IN]        0: Normal, 1: Masked
 * RETURNS
 *  void
 *****************************************************************************/
void set_dialer_inputbox_mask(U8 m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (m)
    {
        case 0:
            MMI_dialer_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
        case 1:
            MMI_dialer_inputbox.flags |= UI_SINGLE_LINE_INPUT_BOX_MASK_CHARACTERS;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  reset_dialer_inputbox
 * DESCRIPTION
 *  Removes the keyhandlers for the dialer inputbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_dialer_inputbox(void)
{
#if(UI_BLINKING_CURSOR_SUPPORT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gui_cancel_timer(UI_inputbox_blink_cursor); */
    StopTimer(BLINKING_CURSOR);

#endif /* (UI_BLINKING_CURSOR_SUPPORT) */ 
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING))
    gui_cancel_timer(wgui_dialer_inputbox_end_frame);
    wgui_dialer_inputbox_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_DIALER_INPUTBOX_FRAME_SKIPPING)) */ 
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    clear_keyboard_key_handler();
    clear_keyboard_input_handler();
    clear_multitap_key_handlers();
    dialer_inputbox_input_callback = UI_dummy_function;
    dialer_inputbox_navigate_callback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  resize_dialer_inputbox
 * DESCRIPTION
 *  Resizes the dialer input box
 * PARAMETERS
 *  width       [IN]        Is the new width
 *  height      [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void resize_dialer_inputbox(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_dialer_input_box(&MMI_dialer_inputbox, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  move_dialer_inputbox
 * DESCRIPTION
 *  Resizes the dialer input box
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  width(?)        [IN]        Is the new width
 *  height(?)       [IN]        Is the new height
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void move_dialer_inputbox(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_dialer_input_box(&MMI_dialer_inputbox, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  register_dialer_inputbox_input_callback
 * DESCRIPTION
 *  regsiter dialer input callback func
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void register_dialer_inputbox_input_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dialer_inputbox_input_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_dialer_inputbox_navigate_callback
 * DESCRIPTION
 *  register the dialer input box navigate callback
 * PARAMETERS
 *  f               [IN]        
 *  function(?)     [IN]        Pointer
 * RETURNS
 *  void
 * VJ
 *****************************************************************************/
void register_dialer_inputbox_navigate_callback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dialer_inputbox_navigate_callback = f;
}

/* PMT dara added for Multitap thai */
/* msz065_20050419 Peng Hua add for check multitap thai input end */

#ifdef __MMI_TOUCH_DIAL_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  setup_dialing_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dialing_keypad      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void setup_dialing_keypad(dialing_keypad_struct *dialing_keypad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dialing_keypad->keypad_x = MMI_DIALING_KEYPAD_LAYER_X + MMI_DIALING_KEYPAD_X;
    dialing_keypad->keypad_y = MMI_DIALING_KEYPAD_LAYER_Y + MMI_DIALING_KEYPAD_Y;
    dialing_keypad->keypad_width = MMI_DIALING_KEYPAD_WIDTH;
    dialing_keypad->keypad_height = MMI_DIALING_KEYPAD_HEIGHT;
    dialing_keypad->key_width = MMI_DIALING_KEY_WIDTH;
    dialing_keypad->key_height = MMI_DIALING_KEY_HEIGHT;
    dialing_keypad->horizontal_gap = MMI_DIALING_KEY_HORIZONTAL_GAP;
    dialing_keypad->vertical_gap = MMI_DIALING_KEY_VERTICAL_GAP;
#ifndef __GDI_MEMORY_PROFILE_2__
    dialing_keypad->selected_key_bitmap.width = 0;
    dialing_keypad->selected_key_bitmap.height = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    dialing_keypad->n_column = MMI_DIALING_KEYPAD_COLOMNS;
    dialing_keypad->n_rows = MMI_DIALING_KEYPAD_ROWS;
    /* start vijay 20050603...added for handling of star character */
    dialing_keypad->key_type = 0;
    /* end vijay */

    /* 053005 Calvin added for function key */
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    dialing_keypad->keypad_func_x = MMI_DIALING_KEYPAD_LAYER_X + MMI_DIALING_KEYPAD_FUNC_X;
    dialing_keypad->keypad_func_y = MMI_DIALING_KEYPAD_LAYER_Y + MMI_DIALING_KEYPAD_FUNC_Y;
    dialing_keypad->func_key_width = MMI_DIALING_FUNC_KEY_WIDTH;
    dialing_keypad->func_key_height = MMI_DIALING_FUNC_KEY_HEIGHT;
    dialing_keypad->func_horizontal_gap = MMI_DIALING_FUNC_KEY_HORIZONTAL_GAP;
    dialing_keypad->func_vertical_gap = MMI_DIALING_FUNC_KEY_VERTICAL_GAP;
    dialing_keypad->func_n_column = MMI_DIALING_KEYPAD_FUNC_COLOMNS;
    dialing_keypad->func_n_rows = MMI_DIALING_KEYPAD_FUNC_ROWS;
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    /* Calvin end */
}


/*****************************************************************************
 * FUNCTION
 *  show_dialing_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void show_dialing_screen(S32 x1, S32 y1, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x2 = x1 + width - 1;
    y2 = y1 + height - 1;

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, UI_device_height - MMI_button_bar_height - 2);
    gui_show_image(x1, y1, (PU8) get_image(IMG_DIALING_SCREEN));
    gdi_layer_pop_clip();
    gui_BLT_double_buffer(x1, y1, x2, UI_device_height - MMI_button_bar_height);
}

#endif /* __MMI_TOUCH_DIAL_SCREEN__ */ 

/* steven e-dic */
void (*wgui_register_multiline_inputbox_up_down_key_handler) (void) = NULL;


/*****************************************************************************
 * FUNCTION
 *  wgui_set_multiline_inputbox_register_up_down_key_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FuncPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_multiline_inputbox_register_up_down_key_funcptr(void (*FuncPtr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_multiline_inputbox_up_down_key_handler = FuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_multiline_inputbox_register_up_down_key_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_multiline_inputbox_register_up_down_key_funcptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_multiline_inputbox_up_down_key_handler = NULL;
}


/* 
 * Functionality for MoDIS direct input 
 */
/* Get the editor style of the current screen */


/*****************************************************************************
 * FUNCTION
 *  mmi_get_current_editor_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_get_current_editor_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_input_box_type != EDITOR_NONE_INPUT_BOX)
    {
        return MMI_current_input_box_type;
    }
    else
    {
        return -1;
    }
}

/* input the content to editor components */

#if !defined (__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  mmi_direct_input_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int mmi_direct_input_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_direct_input_req_struct *data = (mmi_direct_input_req_struct*) p;
    int size = 0;
    U16 *input = data->input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->editor_style)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                multiline_inputbox_direct_input(*input);
                input++;
                size++;
            }
            break;
        case EDITOR_EMS_INPUT_BOX:
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                EMS_inputbox_direct_input(*input);
                input++;
                size++;
            }
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                singleline_inputbox_direct_input(*input);
                input++;
                size++;
            }
            break;
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                multiline_inputbox_direct_input(*input);
                input++;
                size++;
            }
            break;
        case EDITOR_QUICK_SEARCH_SINGLE_LINE_INPU_BOX:
            /* No use */
            break;
        case EDITOR_INLINE_TEXT:
            while ((*input) != 0)
            {
                if (((*input)==0x0d) && (*(input+1)==0x0a))
                {
                    /* Editor component will insert 0x0d, 0x0a when receiving 0x0a */
                    input++;
                }
                inline_edit_singleline_inputbox_direct_input(*input);
                input++;
                size++;
            }
            break;
        default:
            return 0;
            break;
    }
    return size;
}

#define MMI_IS_NUM(c)               ((c) >= L'0' && (c) <= L'9')

#define MMI_IS_VALID_SIM_PHONE_CHAR(c) ((c) == L'*' || (c) == L'+' || (c) == L'#')
#define MMI_IS_VALID_PHONE_CHAR(c)     (MMI_IS_VALID_SIM_PHONE_CHAR(c) || (c) == L'p' || (c) == L'P' || (c) == L'w' || (c) == L'W')

#define MMI_IS_ALPHA(c)             (((c) >= L'a' && (c) <= L'z') || ((c) >= L'A' && (c) <= L'Z'))

extern MMI_BOOL mmi_is_vaild_symbol(unsigned short c);
extern MMI_BOOL mmi_is_no_need_symbol(unsigned short c);

/* Check the content is valid */


/*****************************************************************************
 * FUNCTION
 *  mmi_is_input_content_vaild
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_is_input_content_vaild(unsigned short *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short *in = input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_input_type & INPUT_TYPE_MASK)
    {
        case INPUT_TYPE_PHONE_NUMBER:
            if (MMI_current_input_ext_type & INPUT_TYPE_EXT_SIM_NUMERIC)
            {
                /* Allow to show ' *, +, 0-9, # */
                while (*in != 0)
                {
                    if (!MMI_IS_NUM(*in) && !MMI_IS_VALID_SIM_PHONE_CHAR(*in))
                    {
                        return MMI_FALSE;
                    }
                    if (mmi_is_no_need_symbol(*in))
                    {
                        return FALSE;
                    }
                    in++;
                }
            }
            else
            {
                /* Allow to show '  *, +, p, w, 0-9, # */
                while (*in != 0)
                {
                    if (!MMI_IS_NUM(*in) && !MMI_IS_VALID_PHONE_CHAR(*in))
                    {
                        return MMI_FALSE;
                    }
                    if (mmi_is_no_need_symbol(*in))
                    {
                        return FALSE;
                    }
                    in++;
                }
            }
            break;
        case INPUT_TYPE_NUMERIC:
        case INPUT_TYPE_NUMERIC_PASSWORD:
        case INPUT_TYPE_DECIMAL_NUMERIC:
        case INPUT_TYPE_DECIMAL_NUMERIC_PASSWORD:
            while (*in != 0)
            {
                if (!MMI_IS_NUM(*in))
                {
                    return MMI_FALSE;
                }
                if (mmi_is_no_need_symbol(*in))
                {
                    return FALSE;
                }
                in++;
            }
            break;
        case INPUT_TYPE_ALPHANUMERIC_PASSWORD:
            while (*in != 0)
            {
                if (!MMI_IS_ALPHA(*in) && !MMI_IS_NUM(*in))
                {
                    return MMI_FALSE;
                }
                if (mmi_is_no_need_symbol(*in))
                {
                    return FALSE;
                }
                in++;
            }
            break;
        case INPUT_TYPE_SAT_NUMERIC_PASSWORD:
            while (*in != 0)
            {
                if (!MMI_IS_NUM(*in) || (*in != L'*') || (*in != L'#'))
                {
                    return MMI_FALSE;
                }
                if (mmi_is_no_need_symbol(*in))
                {
                    return FALSE;
                }
                in++;
            }
            break;
        default:
            if (MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL)
            {
                while (*in != 0)
                {
                    /* Don't allow '\n' */
                    if ((*in == L'\n') || (*in == 0x000a) || (*in == 0x000d))
                    {
                        return MMI_FALSE;
                    }

                    /* if character belong to symbol, check is it valid symbol */
                    /*
                     * need to know the code set range of the symbols 
                     * if (!mmi_is_vaild_symbol(*in)
                     * {
                     * return MMI_FALSE;
                     * }
                     */
                    if (mmi_is_no_need_symbol(*in))
                    {
                        return FALSE;
                    }
                    in++;
                }
            }
            break;
    }

    return MMI_TRUE;
}

/* send the message to MMI task to request input directly. */


/*****************************************************************************
 * FUNCTION
 *  mmi_send_direct_input_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input               [?]         
 *  editor_style        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int mmi_send_direct_input_req(unsigned short *input, int editor_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_direct_input_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the input is valid  */
    if (mmi_is_input_content_vaild(input) == MMI_FALSE)
    {
        return 0;
    }

    p = OslConstructDataPtr(sizeof(mmi_direct_input_req_struct));
    memcpy((char*)p->input, (char*)input, sizeof(p->input));
    p->editor_style = editor_style;

    msgStruct.oslSrcId = MOD_L4C;
    msgStruct.oslDestId = MOD_MMI;
    msgStruct.oslMsgId = MSG_ID_MMI_EQ_DIRECT_INPUT_REQ;
    msgStruct.oslSapId = 0;
    msgStruct.oslDataPtr = (oslParaType*) p;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);

    SetProtocolEventHandler(mmi_direct_input_req, MSG_ID_MMI_EQ_DIRECT_INPUT_REQ);
    return 1;
}

#endif 


void wgui_multiline_inputbox_register_infobar_callback(
                void(*redraw_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                void(*reminder_char_callback)(S32 x1,S32 y1,S32 x2,S32 y2),
                U32 height)
{
    S32 old_height = wgui_inputbox_information_bar_height;
    
    gui_multi_line_input_box_register_infobar_callback(
            &MMI_multiline_inputbox,
            redraw_callback,
            reminder_char_callback,
            height);

    if(old_height != wgui_inputbox_information_bar_height)
    {
        S32 new_height = MMI_multiline_inputbox.height + old_height - wgui_inputbox_information_bar_height;
        S32 new_y = MMI_multiline_inputbox.y + MMI_multiline_inputbox.height - new_height;
        gui_move_multi_line_input_box(&MMI_multiline_inputbox, MMI_multiline_inputbox.x,new_y);
        gui_resize_multi_line_input_box(&MMI_multiline_inputbox,MMI_multiline_inputbox.width, new_height);
    }
}

void wgui_multiline_inputbox_register_change_event_handler(
			MMI_BOOL (*handler)(gui_multi_line_input_box_change_event_enum event,U16 C))
{
	gui_multi_line_input_box_register_change_event_handler(&MMI_multiline_inputbox,handler);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_set_multiline_inputbox_text_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_multiline_inputbox_text_color(color c)
{
    MMI_multiline_inputbox.normal_text_color = c;
}

#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
extern single_line_input_box MMI_inline_singleline_inputbox; 
extern void wgui_inputbox_handle_symbol_picker_star_key_down(void);
extern void inline_edit_singleline_inputbox_delete_current_character(void);
extern void wgui_handle_inline_singleline_inputbox_change_input_mode(void);
extern void wgui_EMS_inputbox_handle_symbol_picker_star_key(void);
extern void T9KeyStarAndPoundLongPressHandlerMultilineInputBox(void);
extern void T9KeyStarAndPoundLongPressHandlerForEMSInputBox(void);
/*****************************************************************************
 * FUNCTION
 *  wgui_handle_qsearch_change_input_mode_bymultitapthai
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_handle_qsearch_change_input_mode_bymultitapthai(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete the symbol on key # inserted when key # down */
    if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_singleline_inputbox.flags)
    {
        gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    }
    wgui_handle_qsearch_singleline_inputbox_change_input_mode();                
}


/*****************************************************************************
 * FUNCTION
 *  wgui_handle_inputbox_change_input_mode_bymultitapthai
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_handle_inputbox_change_input_mode_bymultitapthai(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete the symbol on key # inserted when key # down */
    switch(MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            if (UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP & MMI_multiline_inputbox.flags)
            {
                gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
            }
            #if defined(__MMI_T9_THAI__)
            if (MMI_current_input_mode == INPUT_MODE_SMART_THAI)
            {
                T9KeyStarAndPoundLongPressHandlerMultilineInputBox();
            }
            #endif
            wgui_handle_inputbox_change_input_mode();
            break;
        case EDITOR_EMS_INPUT_BOX:
            if (UI_EMS_INPUT_BOX_STATE_MULTITAP & MMI_EMS_inputbox.flags)
            {
                gui_EMS_input_box_backspace(&MMI_EMS_inputbox);
                MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_STATE_MULTITAP;
            }
            #if defined(__MMI_T9_THAI__)
            if (MMI_current_input_mode == INPUT_MODE_SMART_THAI)
            {
                T9KeyStarAndPoundLongPressHandlerForEMSInputBox();
            }
            #endif
            handle_category28_change_input_mode();
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_singleline_inputbox.flags)
            {
                gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            }
            wgui_handle_singleline_inputbox_change_input_mode();
            break;
        case EDITOR_INLINE_TEXT:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_inline_singleline_inputbox.flags)
            {
                inline_edit_singleline_inputbox_delete_current_character();
                MMI_inline_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            }
            wgui_handle_inline_singleline_inputbox_change_input_mode();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_handle_symbol_picker_bymultitapthai
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_handle_symbol_picker_bymultitapthai(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete the symbol on key # inserted when key # down */
    switch(MMI_current_input_box_type)
    {
        case EDITOR_MULTILINE_INPUT_BOX:
        case EDITOR_INLINE_MULTILINE_INPUT_BOX:
            if (UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP & MMI_multiline_inputbox.flags)
        {
            gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
            MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_STATE_MULTITAP;
        }
            #if defined(__MMI_T9_THAI__)
            if (MMI_current_input_mode == INPUT_MODE_SMART_THAI)
            {
                T9KeyStarAndPoundLongPressHandlerMultilineInputBox();
            }
            #endif
            wgui_inputbox_handle_symbol_picker_star_key_down();
            break;
        case EDITOR_EMS_INPUT_BOX:
            if (UI_EMS_INPUT_BOX_STATE_MULTITAP & MMI_EMS_inputbox.flags)
            {
                gui_EMS_input_box_backspace(&MMI_EMS_inputbox);
                MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_STATE_MULTITAP;
            }
            #if defined(__MMI_T9_THAI__)
            if (MMI_current_input_mode == INPUT_MODE_SMART_THAI)
            {
                T9KeyStarAndPoundLongPressHandlerForEMSInputBox();
            }
            #endif
            wgui_EMS_inputbox_handle_symbol_picker_star_key();
            break;
        case EDITOR_SINGLE_LINE_INPU_BOX:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_singleline_inputbox.flags)
            {
                gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
                MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            }
            break;
        case EDITOR_INLINE_TEXT:
            if (UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP & MMI_inline_singleline_inputbox.flags)
            {
                MMI_inline_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            }
            break;
    }
}
#endif /* defined(__MMI_MULTITAP_THAI_PROFILE_1__) */ 

/*****************************************************************************
* FUNCTION
*  wgui_multi_line_clear_pen_down_flag
* DESCRIPTION
*         
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
void wgui_multi_line_clear_pen_down_flag(void)
{
    multi_line_pen_down_hilite_flag = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  wgui_multi_line_set_pen_down_flag
* DESCRIPTION
*  
* PARAMETERS
* void       
* RETURNS
*  void
*****************************************************************************/
void wgui_multi_line_set_pen_down_flag(void)
{
    multi_line_pen_down_hilite_flag = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  wgui_multi_line_get_pen_down_flag
* DESCRIPTION
*  
* PARAMETERS
* void        
* RETURNS
*  void
*****************************************************************************/
BOOL wgui_multi_line_get_pen_down_flag(void)
{
    return multi_line_pen_down_hilite_flag;
}

