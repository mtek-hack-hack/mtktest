/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*=====================  =======================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/InputMethod/ZI/adaptation/src/Zi8HMI.c,v 1.12 2007/10/08 09:08:40 bw Exp $
*
* $Id: Zi8HMI.c,v 1.12 2007/10/08 09:08:40 bw Exp $
*
* $Date: 2007/10/08 09:08:40 $
*
* $Name: 1.12 $
*
* $Locker$
*
* $Revision: 1.12 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: Zi8HMI.c,v $
* Revision 1.12  2007/10/08 09:08:40  bw
* P_U25U26_06B_V30_M31_bw_0003 MTK升级软件V36 TO V68
*
* Revision 1.11  2007/08/06 12:22:48  bw
* UNI@bw_20070806 20:20:48 非触摸版本也要加上欣然的头文件
*
* Revision 1.10  2007/07/28 07:43:32  bw
* UNI@bw_20070728 13:32:16   06b 非触摸移植新然输入法
*
* Revision 1.9  2007/07/28 05:46:47  bw
* UNI@bw_20070728 13:45:50   非触摸,新然输入法,优化代码
*
* Revision 1.8  2007/07/28 05:32:53  bw
* UNI@bw_20070728 13:32:16   06b 非触摸移植新然输入法
*
* Revision 1.7  2007/07/23 10:01:22  bw
* UNI@bw_20070723 18:00:42 新然输入法,简体,繁体,英文分开,原来头文件分开
*
* Revision 1.6  2007/07/17 08:04:03  bw
* UNI@bw_20070717 16:01:52 使用欣然输入法时为了保证PC 可以编译使用__MMI_UNI_XINRAN_INPUT_METHORD__宏定义几个缺少的函数和变量
*
* Revision 1.5  2007/07/13 01:56:33  bw
* UNI@bw_20070713 17:55:54   新然输入法,将简体和繁体的库分开控制,节省空间
*
* Revision 1.4  2007/06/05 05:15:19  bw
* __MMI_UNI_XINRAN_INPUT_METHORD__  移植新然输入法
*
* Revision 1.3  2007/06/01 05:43:32  bw
* P_U25U26_06B_V30_M31_bw_0002 MTK升级软件V30 TO V36
*
* Revision 1.2  2007/05/24 09:45:22  bw
*  UNI@bw_20070524 解决在比划输入法界面, 如果使用虚拟键盘输入拼音, 则zi的全局变量IMEzi8GetParam.GetMode会被修建, 导致再使用按键输入比划时, 没有候选字出现, 修改为在进入比划输入法时给IMEzi8GetParam.GetMode赋值ZI8_GETMODE_STROKES
*
* Revision 1.1  2007/05/17 07:26:23  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 *    zi8hmi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is to implement Human Machine Interface between UI layer and eZi Text core engine.
 *   Some function calls are provided from eZi(Sample code).
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* MTK Terry for Move before zi8hmi.h for MMI_LOW_MEMORY_PHONE */
#include "MMI_features.h"
#include "zi8hmi.h"
#include "zi8api.h"
#include "debuginitdef.h"

#include "gui_inputs.h"
#include "oslmemory.h"
#include "GlobalConstants.h"
#include "Eventsdef.h"
#include "Pixteldatatypes.h"
#include "Frameworkstruct.h"
#include "EventsDef.h"
#include "Wgui.h"
#include "Timerevents.h"
#include "DebugInitDef.h"
#include "CustDataRes.h"
#include "MessagesResourceData.h"
#include "GlobalDefs.h"
#include "Gui_config.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_defs.h"
#include "wgui_softkeys.h"
#include "Gui_ems.h"
#include "t9def.h"
#include "CommonScreens.h"
#include "gui.h"
/*UNI@bw_20070806 20:20:48 非触摸版本也要加上欣然的头文件*/
#ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
#include "tiELibEn.h"
/*UNI@bw_20070723 18:00:42 新然输入法,简体,繁体,英文分开,原来头文件分开  */
#ifdef __MMI_LANG_TR_CHINESE__ //定义了繁体
#include "tiELib_tr.h"
#endif
#ifdef __MMI_LANG_SM_CHINESE__ //定义了繁体
#include "tiELib.h"
#endif
#endif

#if defined(__MMI_TOUCH_SCREEN__)
//#include "EditorPen.h"
#include "EditorPenGprot.h"
#include "EditorPenProt.h"
#endif 
#if defined __MMI_UI_SMALL_SCREEN_SUPPORT__
#include "gui_config.h"
#endif 
// __CUSTPACK_MULTIBIN     Terry   BEGIN
#include "IMERes.h"
extern sIMELDBDetails *gIMELDBArray;

/* __CUSTPACK_MULTIBIN     Terry   END */

/* PMT Dara 24/11/04 .... flags for compostion & candidate window display */
#ifdef MMI_LOW_MEMORY_PHONE
static unsigned char CompositionWindowHideFlag;
static unsigned char CharacterInsertedFlag;
unsigned char ZiSmartPinyinFlag;    
#endif /* MMI_LOW_MEMORY_PHONE */ 

#if defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__)

#include "zi8ARshape.h"
#endif 


#ifdef  __MMI_ZI_HINDI__
#include "hf_rules.h"
extern UI_character_type gui_EMS_current_character(UI_EMS_input_box *b);
static U8 hindi_flag;
static KEYID hindi_keyId;
#endif

#ifndef NEPTUNE_MMI
/* steven e-dic */
extern void (*wgui_register_multiline_inputbox_up_down_key_handler) (void);
#endif /* NEPTUNE_MMI */ 

#if defined(NEPTUNE_MMI)
#define MMI_multiline_inputbox (MMI_multiline_dailer_inputbox_union.MMI_multiline_inputbox)
#endif 
#ifdef MMI_LOW_MEMORY_PHONE
ZI8BOOL ziFlagRSK = 0;
#endif  
ZI8LONG ziFrameCounterForEMSEditor;
single_line_input_box ziCompositionArea;
single_line_input_box ziCandidateArea;
ZI8WCHAR ziCompositionBuffer[ZI_COMPOSITION_BUFFER_SIZE + 1];
ZI8WCHAR ziCandidateBuffer[ZI_CANDIDATE_MAX_BUFFER_SIZE + 1];
ZI8LONG ziEngWordLen = 0;
void (*zi_inputbox_LSK_function) (void) = NULL;
ZI8LONG ziInputMethodCategoryFlag; 
ZI8SHORT ziPhoneticIndex;
ZI8BOOL bSkipGetCandidate;
ZI8BOOL bSkipGetZHCandidate;
ZI8BOOL ziRefillPhoneticBuffer;
ZI8WCHAR zifirstPhoneticCandidate;
ZI8BOOL ziAddEndOfPhoneticCandidate;

#if defined (MONO_LCD)
UI_filled_area MMI_ZI_COMPOSITION_WINDOW_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,  /* |UI_FILLED_AREA_SINGLE_BORDER, */
    UI_NULL_IMAGE,
    NULL,
    {WHITE},                    /* { 206,206,206,100 }, */
    {BLACK},
    {BLACK},
    {WHITE},                    /* {   128,128,128,100 }, */
    0,
};

#else /* defined (MONO_LCD) */ 
UI_filled_area MMI_ZI_COMPOSITION_WINDOW_filler = 
{
    UI_FILLED_AREA_TYPE_COLOR,  /* |UI_FILLED_AREA_SINGLE_BORDER, */
    UI_NULL_IMAGE,
    NULL,
    {182, 189, 210, 100},       /* { 206,206,206,100 }, */
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {10, 36, 106, 100},         /* {   128,128,128,100 }, */
    0,
};
#endif /* defined (MONO_LCD) */ 
ZI8BOOL ziNoDrawRightArrowSymbol;
ZI8BOOL ziNoDrawCandidateRightArrowSymbol;
KEYID ziCurrKeyId;

#if defined (MONO_LCD)
/* PMT Dara 24/11/04 ..changed for the MonoLcd */
color MMI_ZI_COMPONENT_SELECTOR_COLOR = {BLACK};    /* WHITE..........as it was yellow colour earlier */

/* PMT end */
color MMI_ZI_COMPONENT_SELECTION_TXT_COLOR = {WHITE};
#else /* defined (MONO_LCD) */ 
color MMI_ZI_COMPONENT_SELECTOR_COLOR = {255, 248, 175, 100};
color MMI_ZI_COMPONENT_SELECTION_TXT_COLOR = {255, 0, 0, 100};
#endif /* defined (MONO_LCD) */ 
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
EMSTextFormat ziKeepEMSTextFormat;
#endif 
ZI8LONG ziMultilineEditorHeight;

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
ZI8LONG ziEMSEditorHeight;
#endif 

ZI8BOOL ziFrameTimerStart;

/* MTK Terry temp solution for composition and candidate window display */
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
#define ZI_COMPOSITION_Y UI_device_height-MMI_BUTTON_BAR_HEIGHT-1-MMI_multitap_height-1-MMI_multitap_height
#define ZI_CANDIDATE_Y UI_device_height-MMI_BUTTON_BAR_HEIGHT-1-MMI_multitap_height
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 

extern S32 MMI_multiline_inputbox_x;
extern S32 MMI_multiline_inputbox_y;
extern S32 MMI_multiline_inputbox_width;
extern S32 MMI_multiline_inputbox_height;
extern S32 UI_device_height;
extern S32 UI_device_width;
extern S32 MMI_title_y;
extern S32 MMI_title_height;
extern S32 MMI_button_bar_height;
extern S32 MMI_multitap_x;
extern S32 MMI_multitap_y;
extern S32 MMI_multitap_width;
extern S32 MMI_multitap_height;

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern UI_EMS_input_box MMI_EMS_inputbox;
#endif 

extern S16 MMI_current_input_type;

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern S16 MMI_current_input_ext_type;
#endif 
// #ifdef __MMI_DEFAULT_THEME_3__
#if !defined(__MTK_TARGET__) && defined(MMI_LOW_MEMORY_PHONE)
extern const UI_filled_area MMI_multitap_filler;
#else 
extern CONST_HARDWARE UI_filled_area MMI_multitap_filler;
#endif 
#if defined(MONO_LCD)
color multitap_selector_txt_col_Default = BLACK;

/* PMT Dara 24/11/04 ....as selected text should be WHITE */
color multitap_selected_txt_col_Default = WHITE;    /* BLACK */

/* PMT end */
#else /* defined(MONO_LCD) */ 
extern CONST_HARDWARE color multitap_selector_txt_col_Default;
extern CONST_HARDWARE color multitap_selected_txt_col_Default;
#endif /* defined(MONO_LCD) */ 
// #endif
extern U8 inline_full_screen_edit_changed;
extern U8 wgui_inline_list_menu_disable_done;

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern EMSTextFormat wgui_EMS_text_format;
#endif 
extern U8 wgui_singleline_inputbox_RSK_label_clear;
extern UI_theme *current_UI_theme;
extern UI_multitap_input_theme *current_multitap_input_theme;
extern U8 category28_RSK_label_clear;
extern UI_string_type category28_RSK_label_string;
extern PU8 category28_RSK_label_icon;
extern U8 wgui_inputbox_RSK_label_clear;
extern UI_string_type wgui_inputbox_RSK_label_string;
extern PU8 wgui_inputbox_RSK_label_icon;

extern void (*wgui_inline_edit_DONE_function) (void);
extern void EntryInLineMultilineEditorOption(void);

extern void (*gui_start_timer) (S32 count, void (*callback) (void));

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern void gui_show_EMS_input_box(UI_EMS_input_box *b);
#endif 
extern void gui_show_single_line_input_box(single_line_input_box *b);
extern void (*gui_BLT_double_buffer) (S32 x1, S32 y1, S32 x2, S32 y2);
extern void (*gui_lock_double_buffer) (void);
extern void (*gui_unlock_double_buffer) (void);
extern void gui_create_single_line_input_box_use_buffer(
                single_line_input_box *b,
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                UI_string_type buffer,
                S32 length);
extern void gui_single_line_input_box_next(single_line_input_box *b);
extern void gui_single_line_input_box_previous(single_line_input_box *b);
extern void (*hide_multitap) (void);
extern void gui_single_line_input_box_goto_first_character(single_line_input_box *b);

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern void wgui_EMS_redraw_remaining_characters_display(void);

/* extern void gui_EMS_input_box_insert_character(UI_EMS_input_box *b,UI_character_type c); */
extern void gui_EMS_input_box_backspace(UI_EMS_input_box *b);
extern void gui_EMS_input_box_delete_all(UI_EMS_input_box *b);
extern void gui_EMS_input_box_previous(UI_EMS_input_box *b);
extern void gui_EMS_input_box_next(UI_EMS_input_box *b);
extern void gui_EMS_input_box_previous_line(UI_EMS_input_box *b);
extern void gui_EMS_input_box_next_line(UI_EMS_input_box *b);
extern S32 gui_EMS_input_box_highlight_cursor_end(UI_EMS_input_box *b);
extern S32 gui_EMS_input_box_highlight_cursor_start(UI_EMS_input_box *b);
extern S32 gui_EMS_input_box_highlight_cursor_number(UI_EMS_input_box *b, S32 numOfChar);
extern void register_category28_handle_right_softkey_up(void);
extern void handle_category28_input(void);
extern void show_EMS_inputbox(void);
extern void gui_resize_EMS_input_box(UI_EMS_input_box *b, S32 width, S32 height);

#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
extern S8 *UCS2Strcat(S8 *strDestination, const S8 *strSource);
extern S8 *UCS2Strcpy(S8 *strDestination, const S8 *strSource);
extern S32 UCS2Strlen(const S8 *arrOut);
extern S32 gui_single_line_input_box_highlight_cursor_start(single_line_input_box *b);
extern void (*gui_cancel_timer) (void (*callback) (void));
extern MMI_BOOL gui_multi_line_input_box_insert_character(multi_line_input_box *b, UI_character_type c);
//extern void gui_multi_line_input_box_insert_character(multi_line_input_box *b, UI_character_type c);
extern void gui_multi_line_input_box_delete_character(multi_line_input_box *b);
extern void gui_multi_line_input_box_previous(multi_line_input_box *b);
extern void gui_multi_line_input_box_next(multi_line_input_box *b);
extern void wgui_redraw_remaining_characters_display(void);
extern S32 gui_multi_line_input_box_highlight_cursor_number(multi_line_input_box *b, S32 n);
extern void wgui_register_inputbox_handle_right_softkey_up(void);
extern void gui_multi_line_input_box_delete_all(multi_line_input_box *b);
extern void wgui_handle_inputbox_input(void);
extern void show_multiline_inputbox(void);
extern S32 gui_single_line_input_box_highlight_cursor_number(single_line_input_box *b, S32 numOfChar);
extern S32 gui_single_line_input_box_insert_string(single_line_input_box *b, UI_string_type s, S32 o);
extern void (*gui_reset_clip) (void);

#if defined(MONO_LCD)
extern color(*gui_color) (color c);
#else 
extern color(*gui_color) (U8 r, U8 g, U8 b);
#endif 

#include "MMITimer.h"
#define StopMyTimer  StopTimer
#define StartMyTimerInt  StartTimerEx
extern void draw_resizeable_arrow(S32 x, S32 y, U8 arrow_type, color c, S32 width, S32 height);
extern void draw_arrow(S32 x, S32 y, U8 arrow_type, color c);
extern void (*gui_putpixel) (S32 x, S32 y, color c);
//extern U16 StopMyTimer(U16 nTimerId);
//extern U16 StartMyTimerInt(U16 nTimerId, U32 nTimeDuration, oslTimerFuncPtr TimerExpiry, U8 alignment);
extern void wgui_register_singleline_inputbox_handle_right_softkey_up(void);
extern void wgui_handle_singleline_inputbox_input(void);
extern void redraw_input_mode_only(void);
extern void redraw_fixed_list(void);
extern void gui_show_fixed_list_menu(fixed_list_menu *m);
extern void PbookListSearchEntryReq(void);
extern void show_softkey_background(void);
extern void UI_editor_play_tone_cannot_insert(void);
extern void register_category28_handle_clear_key_up(void);
extern void wgui_register_inputbox_handle_clear_key_up(void);
extern void wgui_handle_inputbox_right_softkey_up(void);
extern void handle_category28_right_softkey_up(void);
extern void (*multiline_inputbox_input_callback) (void);

#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)

#if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_TAIWAN__)
extern ZI8BOOL Initialize_TR_DATA(void);
#endif 

#if defined(__MMI_ZI_SM_CHINESE__)
extern ZI8BOOL Initialize_SM_DATA(void);
#endif 

extern ZI8_LANGUAGE_ENTRY ziLanguageLibs[];

#endif /* defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__) */ 
/* ************************************************************************ */

static ZI8UCHAR CenterOutCandidates(ZI8UCHAR);
static ZI8UCHAR CenterOutIndex(ZI8UCHAR);

static ZI8BOOL IMEinsertChar(ZI8WCHAR);
static ZI8BOOL IMEdeleteChar(void);
static int IMEinsertText(PZI8WCHAR);
static void IMEtoCapMode(PZI8WCHAR);

static void IMEchangeInputMethod(void);
static ZI8BOOL IMEchangeSubLanguage(ZI8BOOL);

static void IMEstartEZI_STROKE(void);
static void IMEstartEZI_PHONETIC(ZI8UCHAR);
static void IMEstartEZI_PINYIN(void);
static void IMEstartEZI_BOPOMOFO(void);
static void IMEstartEZI_ABC(void);
static void IMEstartEZI_MULTITAP_PINYIN(void);
static void IMEstartEZI_MULTITAP_BOPOMOFO(void);
static void IMEstartEZI_THAI(void);

#ifdef __MMI_ZI_ARABIC__        
static void IMEstartEZI_ARABIC(void);
#endif 

#ifdef __MMI_ZI_PERSIAN__       
static void IMEstartEZI_PERSIAN(void);
#endif 


#ifdef __MMI_ZI_HINDI__
static void IMEstartEZI_HINDI(void);
#endif 
#ifdef __MMI_ZI_HEBREW__        /* can be remove while checking Hebrew into GPRS branch */
static void IMEstartEZI_HEBREW(void);
#endif 
IME_RETURN_CODE IMEprocessKey(KEYID keyID, int, int);
static IME_RETURN_CODE IMEprocessKeyEZI_STROKE(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKey1Phonetic(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKey2Phonetic(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKeyMultitapPhonetic(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKey1N2Phonetic(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKeyDirectPhonetic(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKeyEZI_ABC(KEYID, int, int);
static IME_RETURN_CODE IMEprocessKeyEZI_THAI(KEYID, int, int);

#ifdef __MMI_ZI_ARABIC__        
static IME_RETURN_CODE IMEprocessKeyEZI_ARABIC(KEYID, int, int);
#endif 

#ifdef __MMI_ZI_PERSIAN__       
static IME_RETURN_CODE IMEprocessKeyEZI_PERSIAN(KEYID, int, int);
#endif 

#ifdef __MMI_ZI_HINDI__ /* Hindi */
static IME_RETURN_CODE IMEprocessKeyEZI_HINDI(KEYID, int, int);
#endif 

#ifdef __MMI_ZI_HEBREW__        /* can be remove while checking Hebrew into GPRS branch */
static IME_RETURN_CODE IMEprocessKeyEZI_HEBREW(KEYID, int, int);
#endif 

void InitZiInputMethod(void);

void ZiKey0PressHandler(void);
void ZiKey1PressHandler(void);
void ZiKey2PressHandler(void);
void ZiKey3PressHandler(void);
void ZiKey4PressHandler(void);
void ZiKey5PressHandler(void);
void ZiKey6PressHandler(void);
void ZiKey7PressHandler(void);
void ZiKey8PressHandler(void);
void ZiKey9PressHandler(void);

void ZiKeyArrowUPHandler(void);
void ZiKeyArrowRightHandler(void);
void ZiKeyArrowDownHandler(void);
void ZiKeyArrowLeftHandler(void);

/* PMT dara added for UP & DOWN long press functionality */
#ifdef MMI_LOW_MEMORY_PHONE
void ZiKeyArrowDownLongPressHandler(void);  
void ZiKeyArrowUPLongPressHandler(void);
#endif /* MMI_LOW_MEMORY_PHONE */ 
/* PMT end */

void ZiKeyStarPressHandler(void);
void ZiKeyStarLongPressHandler(void);
void ZiKeyHashPressHandler(void);
void ZiKeyHashLongPressHandler(void);

void ZiKeyLSKPressHandler(void);
void ZiKeyLSKLongPressHandler(void);
void ZiKeyRSKPressHandler(void);
void ZiKeyRSKLongPressHandler(void);

void ZiDisplay(void);
void ZiDisplayForEmsEditorEndFrame(void);
void ZiChangeInputMethod(INPUT_MODE inputMode);

void ZiClearKeyStarAndPoundHandler(void);
void ZiClearKeyNavigationHandler(void);
void ZiClearArrowKeyLeftHandler(void);
void ZiClearArrowKeyRightHandler(void);
void ZiClearKey0To9Handler(void);

#if defined(__MTK_TARGET__)
int wcslen(char *);
char wcscat(char *, char *);
char wcscpy(char *, char *);
#endif /* defined(__MTK_TARGET__) */ 
ZI8WCHAR ZI_towupper(ZI8WCHAR wChar);
ZI8WCHAR ZI_towlower(ZI8WCHAR wChar);
void ZiInuptMethodEnterSinglelineInputBox(void);
void ZiInuptMethodExitSinglelineInputBox(void);
void ZiInuptMethodEnterCategory5(void);
void ZiInuptMethodExitCategory5(void);
void ZiInuptMethodEnterCategory28(void);
void ZiInuptMethodExitCategory28(void);
void ZiInputBoxScreenStateChange(void);
void ZiInputMethodExit(void);
void ZiHideCompositionArea(void);
ZI8UCHAR ZiMaxLengthCheck(void);
void ZiMultitapKeyTimeoutHandler(void);
void ZiSetCandidateWindowCurrentTheme(void);

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
extern icontext_button MMI_softkeys[];
#endif 
/* **************** */
/* Global variables */
/* **************** */
ZI8UCHAR IMEprediction_Startat;

ZI8WCHAR labelSoftR[MAX_CHAR_PER_LINE + 1];
ZI8WCHAR labelSoftL[MAX_CHAR_PER_LINE + 1];
ZI8WCHAR labelTop[MAX_CHAR_PER_LINE + 1];

ZI8UCHAR dictionaryPUD[MAX_DICTIONARY_SIZE];
ZI8UCHAR dictionaryUWD[MAX_DICTIONARY_SIZE];
ZI8UCHAR dictionaryUWD_ZH[MAX_DICTIONARY_SIZE];
SUPPORTED_LANGUAGES dictLanguage;
PB_ORDER pbOrder;
ZI8BOOL bNoComponent;
IME_PHONETIC_METHOD iStepID;
ZI8BOOL bComponentOn2ndKey;
ZI8BOOL bNoRadicals;
ALPHA_LANGUAGE IMEalphaLangID;

ZI8UCHAR IMEsubLanguage;
INPUT_MODE IMEmethodZH;
INPUT_MODE IMEmethodLast;
ZI8UCHAR IMEletterCase;
ZI8UCHAR IMEpudID;
ZI8UCHAR IMEuwdID;
ZI8UCHAR IMEuwd_ZHID;
ZI8UCHAR IMEoemID;
ZI8BOOL bUseZHUWD;
ZI8BOOL bZHwordCand;
ZI8BOOL bSingleChar;

#if 0
/* under construction !*/
#endif /* 0 */ 

/* *************** */
/* Local variables */
/* *************** */
static int IMEnumOfChars;
static int IMEmaxBufferSize;
static IME_TEXT_TYPE IMEtextType;
static ZI8BOOL IMEsearchPB;

//static int                 IMEstartX;
//static int                 IMEstartY;
static int IMEmaxCols;

/* static int                 IMEmaxRows; */
static int IMEcurPos;
static ZI8WCHAR IMEinline[MAX_ELEMENT_BUFFERSIZE + 1];
static int IMEprediction;

static ZI8BOOL IMEactive;

/* static ZI8BOOL             IMEcaretOn; */
static INPUT_MODE IMEmethod;
static ZI8UCHAR IMElastLetterCase;
static ZI8UCHAR IMElastSubLanguage;

/* static PIMEPROCESSKEYFUNC  IMElastProcessKeyFunc; */
static PIMEPROCESSKEYFUNC IMEprocessKeyFunc;
static ZI8GETPARAM IMEzi8GetParam;
static ZI8WCHAR IMEelementBuffer[MAX_ELEMENT_BUFFERSIZE + 1];
#ifdef __MMI_UNI_XINRAN_INPUT_METHORD__
static char     IMEXinranCharBuffer[MAX_ELEMENT_BUFFERSIZE+1];//按键序列
static ZI8WCHAR IMEXinrancandidateBuffer[MAX_CAND_BUFFERSIZE + 1];//笔划输入法的返回序列
static ZI8UCHAR IMEXinrancandCount;//新然输入法的返回的汉字长度
#endif
static ZI8WCHAR IMEwordBuffer[MAX_WORD_BUFFERSIZE + 1];
static ZI8WCHAR IMEcandidateBuffer[MAX_CAND_BUFFERSIZE + 1];
static ZI8WCHAR IMEphoneticBuffer[MAX_PHONETIC_BUFFERSIZE + 1];

#if defined __MMI_ZI_USING_PSCRATCH_BUFFER__
static ZI8UCHAR IMEScratchBuffer[1536];
#endif
static ZI8WCHAR IMEfirstCandidate;
static ZI8UCHAR IMEelementCount;
static ZI8UCHAR IMEwordCharacterCount;

static ZI8BOOL IMEbValidPhonetic;
static ZI8BOOL IMEbFocusOnPhonetic;
static ZI8BOOL IMEbPhoneticComfirmed;
static ZI8WCHAR IMEpPhoneticPtr[MAX_PHONETIC_CANDSIZE][30];
static ZI8UCHAR IMEphoneticIndex;
static ZI8UCHAR IMEphoneticBase;
static ZI8UCHAR IMEphoneticCount;
static ZI8WCHAR IMEtoneMark;

static ZI8BOOL IMEbValidCandidates;
static ZI8UCHAR IMEcandIndex;
static ZI8UCHAR IMEcandCount;

static ZI8BOOL IMEbValidAlphaWords;
static ZI8UCHAR IMEalphaCount;

static ZI8UCHAR COindexs[MAX_CHAR_PER_LINE];
static ZI8WCHAR COcands[MAX_CHAR_PER_LINE];

static ZI8WCHAR lastKeyID;
static int index;
static ZI8BOOL IMEdoWordCand;
static UI_string_type temp_left_softkey_text;

#define MAX_SYM_PER_KEY         5
#define ZI8_ZH_SPACE                0x0020

static ZI8WCHAR ZI8ROMDATA IMElayoutPY[12][MAX_SYM_PER_KEY] = 
{
    {0},
    {ZI8_CODE_PINYIN_A, ZI8_CODE_PINYIN_B, ZI8_CODE_PINYIN_C},
    {ZI8_CODE_PINYIN_D, ZI8_CODE_PINYIN_E, ZI8_CODE_PINYIN_F},
    {ZI8_CODE_PINYIN_G, ZI8_CODE_PINYIN_H, ZI8_CODE_PINYIN_I},
    {ZI8_CODE_PINYIN_J, ZI8_CODE_PINYIN_K, ZI8_CODE_PINYIN_L},
    {ZI8_CODE_PINYIN_M, ZI8_CODE_PINYIN_N, ZI8_CODE_PINYIN_O},
    {ZI8_CODE_PINYIN_P, ZI8_CODE_PINYIN_Q, ZI8_CODE_PINYIN_R, ZI8_CODE_PINYIN_S},
    {ZI8_CODE_PINYIN_T, ZI8_CODE_PINYIN_U, ZI8_CODE_PINYIN_V},
    {ZI8_CODE_PINYIN_W, ZI8_CODE_PINYIN_X, ZI8_CODE_PINYIN_Y, ZI8_CODE_PINYIN_Z},
    {0},
    {ZI8_CODE_TONES_1, ZI8_CODE_TONES_2, ZI8_CODE_TONES_3, ZI8_CODE_TONES_4,
     ZI8_CODE_TONES_5}
};

static ZI8WCHAR ZI8ROMDATA IMElayoutZY[12][MAX_SYM_PER_KEY] = 
{
    {ZI8_CODE_BPMF_B, ZI8_CODE_BPMF_P, ZI8_CODE_BPMF_M, ZI8_CODE_BPMF_F,},
    {ZI8_CODE_BPMF_D, ZI8_CODE_BPMF_T, ZI8_CODE_BPMF_N, ZI8_CODE_BPMF_L,},
    {ZI8_CODE_BPMF_G, ZI8_CODE_BPMF_K, ZI8_CODE_BPMF_H,},
    {ZI8_CODE_BPMF_J, ZI8_CODE_BPMF_Q, ZI8_CODE_BPMF_X,},
    {ZI8_CODE_BPMF_ZH, ZI8_CODE_BPMF_CH, ZI8_CODE_BPMF_SH, ZI8_CODE_BPMF_R,},
    {ZI8_CODE_BPMF_Z, ZI8_CODE_BPMF_C, ZI8_CODE_BPMF_S},
    {ZI8_CODE_BPMF_A, ZI8_CODE_BPMF_O, ZI8_CODE_BPMF_E, ZI8_CODE_BPMF_EH},
    {ZI8_CODE_BPMF_AI, ZI8_CODE_BPMF_EI, ZI8_CODE_BPMF_AU, ZI8_CODE_BPMF_OU},
    {ZI8_CODE_BPMF_AN, ZI8_CODE_BPMF_EN, ZI8_CODE_BPMF_ANG, ZI8_CODE_BPMF_ENG,
     ZI8_CODE_BPMF_ER},
    {ZI8_CODE_BPMF_I, ZI8_CODE_BPMF_U, ZI8_CODE_BPMF_IU},
    {ZI8_CODE_TONES_1, ZI8_CODE_TONES_2, ZI8_CODE_TONES_3, ZI8_CODE_TONES_4,
     ZI8_CODE_TONES_5}
};

static ZI8UCHAR COindexs[MAX_CHAR_PER_LINE];
static ZI8WCHAR COcands[MAX_CHAR_PER_LINE];


/*****************************************************************************
 * FUNCTION 
 *  ZiUpdateLSKString
 * DESCRIPTION
 *  Update the temp_left_softkey_txt from MMI_left_softkey_text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiUpdateLSKString(void)
{
#if !defined(MMI_LOW_MEMORY_PHONE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_left_softkey_text = MMI_softkeys[MMI_LEFT_SOFTKEY].text;
#else /* !defined(MMI_LOW_MEMORY_PHONE) */ 
    temp_left_softkey_text = MMI_left_softkey.text;
#endif /* !defined(MMI_LOW_MEMORY_PHONE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  CenterOutCandidates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  numOfCand       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ZI8UCHAR CenterOutCandidates(ZI8UCHAR numOfCand)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(COindexs); i++)
    {
        COindexs[i] = i;
    }
    if (numOfCand <= 2)
    {
        return (0);
    }

    j = numOfCand / 2;
    COindexs[j] = 0;
    COcands[j] = IMEcandidateBuffer[0];
    for (i = j - 1, k = 1; i >= 0; i--, k += 2)
    {
        COindexs[i] = k;
        COcands[i] = IMEcandidateBuffer[k];
    }
    for (i = j + 1, k = 2; i < numOfCand; i++, k += 2)
    {
        COindexs[i] = k;
        COcands[i] = IMEcandidateBuffer[k];
    }
    for (i = 0; i < numOfCand; i++)
    {
        IMEcandidateBuffer[i] = COcands[i];
    }
    return (j);
}


/*****************************************************************************
 * FUNCTION
 *  CenterOutIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uIndex      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ZI8UCHAR CenterOutIndex(ZI8UCHAR uIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (COindexs[uIndex]);
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  IMEdeleteChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static ZI8BOOL IMEdeleteChar(void)
{
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
        gui_EMS_input_box_backspace(&MMI_EMS_inputbox);
        wgui_EMS_text_format = MMI_EMS_inputbox.text_format;
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
    {
        gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
        /* setup the inline edit changed flag */
        inline_full_screen_edit_changed = 1;
        multiline_inputbox_input_callback();
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
    {
        gui_single_line_input_box_delete_character(&MMI_singleline_inputbox);
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        gui_multi_line_input_box_delete_character(&MMI_multiline_inputbox);
        multiline_inputbox_input_callback();
    }
    return (ZI8TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  IMEinsertChar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wcChar      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ZI8BOOL IMEinsertChar(ZI8WCHAR wcChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
    /* Removed by Ankit Start */ //#ifdef __MMI_LANG_ARABIC__
    #ifdef MMI_LOW_MEMORY_PHONE
        CharacterInsertedFlag = 1;
    #endif 
    /* Removed by Ankit Start */ //#endif /* __MMI_LANG_ARABIC__ */ 
        gui_EMS_input_box_insert_character(&MMI_EMS_inputbox, wcChar);
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
    {
        /* PMT Dara 24/11/04 ....to take the decision when to dispaly the composition window */
    #ifdef MMI_LOW_MEMORY_PHONE
        CharacterInsertedFlag = 1;
    #endif 
        /* PMT end */
        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, wcChar);
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
    {
        gui_single_line_input_box_insert_character(&MMI_singleline_inputbox, wcChar);
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        gui_multi_line_input_box_insert_character(&MMI_multiline_inputbox, wcChar);
    }

    /* setup the inline edit changed flag */
    inline_full_screen_edit_changed = 1;

    if (IMEnumOfChars >= IMEmaxBufferSize)
    {
        return (ZI8FALSE);
    }

    switch (IMEmethod)
    {
        case INPUT_EZI_MULTITAP_BOPOMOFO:
            IMEmethodZH = IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_MULTITAP_PINYIN:
            IMEmethodZH = IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_STROKE:
            IMEmethodZH = IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_PINYIN:
            IMEmethodZH = IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_BOPOMOFO:
            IMEmethodZH = IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_ABC:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_RUSSIAN:
            IMEmethodLast = IMEmethod;
            break;
	    case INPUT_EZI_BULGARIAN:      
            IMEmethodLast = IMEmethod; 
         break;
        case INPUT_EZI_FRENCH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_GERMAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_ITALIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_SPANISH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_POLISH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_NORWEGIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_ABC:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_SLOVAK:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_DUTCH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_SWEDISH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_CROATIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_ROMANIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_SLOVENIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_GREEK:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_CZECH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_FINNISH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_DANISH:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_HUNGARIAN:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_VIETNAMESE:
            IMEmethodLast = IMEmethod;
            break;
        case INPUT_EZI_INDONESIAN:
            IMEmethodLast = IMEmethod;
            break;
    }
    IMElastLetterCase = IMEletterCase;
    IMElastSubLanguage = IMEsubLanguage;

    return (ZI8TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  IMEinsertText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pText       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int IMEinsertText(PZI8WCHAR pText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; pText[i]; i++)
    {
        if (!IMEinsertChar(pText[i]))
        {
            break;
        }
    }
    return (i);
}


/*****************************************************************************
 * FUNCTION
 *  IMEtoCapMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pText       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEtoCapMode(PZI8WCHAR pText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IMEletterCase == ZI8_CASE_TITLE)
    {
        pText[0] = ZI_towupper(pText[0]);
        for (; pText[i]; i++)
        {
            if (pText[i] == 0x0020)
            {
                if (!pText[++i])
                {
                    return;
                }
                pText[i] = ZI_towupper(pText[i]);
            }
            else if (i)
            {
                /*
                 * #ifdef WIN32
                 * if((pText[i] >= 0x0430 && pText[i] <= 0x044f)||(pText[i] >= 0x00e0 && pText[i] <= 0x00ff))
                 * {
                 * pText[i]-=0x20;
                 * }
                 * #endif            
                 */
                pText[i] = ZI_towlower(pText[i]);
            }
        }
        return;
    }
    for (; pText[i]; i++)
    {

        switch (IMEletterCase)
        {
            case ZI8_CASE_UPPER:
                /*
                 * #ifdef WIN32
                 * if((pText[i] >= 0x0430 && pText[i] <= 0x044f)||(pText[i] >= 0x00e0 && pText[i] <= 0x00ff))
                 * {
                 * pText[i]-=0x20;
                 * }
                 * #endif            
                 */
                pText[i] = ZI_towupper(pText[i]);
                break;
            case ZI8_CASE_LOWER:
                break;
            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEchangeInputMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEchangeInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IMElastProcessKeyFunc = 0; */

    IMEletterCase = IMElastLetterCase;
    IMEsubLanguage = IMElastSubLanguage;
    switch (IMEmethod)
    {
        case INPUT_EZI_STROKE:
            IMEstartEZI_STROKE();
            break;
        case INPUT_EZI_PINYIN:
            iStepID = PHONETIC_2_STEPS;
            IMEstartEZI_PINYIN();
            break;
        case INPUT_EZI_BOPOMOFO:
            iStepID = PHONETIC_2_STEPS;
            IMEstartEZI_BOPOMOFO();
            break;
        case INPUT_EZI_ABC:
            IMEalphaLangID = ALPHA_LANG_EN;
            IMEstartEZI_ABC();
            break;
        case INPUT_EZI_MULTITAP_PINYIN:
            iStepID = PHONETIC_MULTITAP;
            IMEstartEZI_MULTITAP_PINYIN();
            break;
        case INPUT_EZI_MULTITAP_BOPOMOFO:
            iStepID = PHONETIC_MULTITAP;
            IMEstartEZI_MULTITAP_BOPOMOFO();
            break;
        case INPUT_EZI_THAI:
            IMEstartEZI_THAI();
            break;
    #ifdef __MMI_ZI_ARABIC__        
        case INPUT_EZI_ARABIC:
            IMEstartEZI_ARABIC();
            break;
    #endif /* __MMI_ZI_ARABIC__ */ 

    #ifdef __MMI_ZI_PERSIAN__       
        case INPUT_EZI_PERSIAN:
            IMEstartEZI_PERSIAN();
            break;
    #endif /* __MMI_ZI_PERSIAN__ */ 

    #ifdef __MMI_ZI_HEBREW__        /* can be remove while checking Arabic into GPRS branch */
        case INPUT_EZI_HEBREW:
            IMEstartEZI_HEBREW();
            break;
    #endif /* __MMI_ZI_HEBREW__ */ 
    #if defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
        case INPUT_EZI_RUSSIAN:
            IMEalphaLangID = ALPHA_LANG_RU;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) */ 
    #if defined(__MMI_ZI_BULGARIAN__)
	    case INPUT_EZI_BULGARIAN:
		   IMEalphaLangID = ALPHA_LANG_BG;
	    	IMEstartEZI_ABC();
	    	break;
    #endif
    #if defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__)
        case INPUT_EZI_FRENCH:
            IMEalphaLangID = ALPHA_LANG_FR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 
    #if defined(__MMI_ZI_GERMAN__)
        case INPUT_EZI_GERMAN:
            IMEalphaLangID = ALPHA_LANG_DE;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_GERMAN__) */ 
    #if defined(__MMI_ZI_ITALIAN__)
        case INPUT_EZI_ITALIAN:
            IMEalphaLangID = ALPHA_LANG_IT;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_ITALIAN__) */ 
    #if defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
        case INPUT_EZI_SPANISH:
            IMEalphaLangID = ALPHA_LANG_ES;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 
    #if defined(__MMI_ZI_TURKISH__)
        case INPUT_EZI_TURKISH:
            IMEalphaLangID = ALPHA_LANG_TR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_TURKISH__) */ 
    #if defined(__MMI_ZI_HINDI__)
        case INPUT_EZI_HINDI:
            IMEalphaLangID = ALPHA_LANG_HI;
            IMEstartEZI_HINDI();
            break;
    #endif /* defined(__MMI_ZI_HINDI__) */ 
    #if defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__)
        case INPUT_EZI_PORTUGUESE:
            IMEalphaLangID = ALPHA_LANG_PT;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) */ 
    #if defined(__MMI_ZI_INDONESIAN__)
        case INPUT_EZI_INDONESIAN:
            IMEalphaLangID = ALPHA_LANG_ID;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_INDONESIAN__) */ 
    #if defined(__MMI_ZI_MALAY__)
        case INPUT_EZI_MALAY:
            IMEalphaLangID = ALPHA_LANG_MS;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_MALAY__) */ 
    #if defined(__MMI_ZI_VIETNAMESE__)
        case INPUT_EZI_VIETNAMESE:
            IMEalphaLangID = ALPHA_LANG_VI;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_VIETNAMESE__) */ 
    #if defined(__MMI_ZI_POLISH__)
        case INPUT_EZI_POLISH:
            IMEalphaLangID = ALPHA_LANG_PL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_POLISH__) */ 
    #if defined(__MMI_ZI_NORWEGIAN__)
        case INPUT_EZI_NORWEGIAN:
            IMEalphaLangID = ALPHA_LANG_NO;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_NORWEGIAN__) */ 
    #if defined(__MMI_ZI_SLOVAK__)
        case INPUT_EZI_SLOVAK:
            IMEalphaLangID = ALPHA_LANG_SK;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SLOVAK__) */ 
    #if defined(__MMI_ZI_DUTCH__)
        case INPUT_EZI_DUTCH:
            IMEalphaLangID = ALPHA_LANG_NL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_DUTCH__) */ 
    #if defined(__MMI_ZI_SWEDISH__)
        case INPUT_EZI_SWEDISH:
            IMEalphaLangID = ALPHA_LANG_SV;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SWEDISH__) */ 
    #if defined(__MMI_ZI_CROATIAN__)
        case INPUT_EZI_CROATIAN:
            IMEalphaLangID = ALPHA_LANG_HR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CROATIAN__) */ 
    #if defined(__MMI_ZI_ROMANIAN__)
        case INPUT_EZI_ROMANIAN:
            IMEalphaLangID = ALPHA_LANG_RO;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_ROMANIAN__) */ 
    #if defined(__MMI_ZI_SLOVENIAN__)
        case INPUT_EZI_SLOVENIAN:
            IMEalphaLangID = ALPHA_LANG_SL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SLOVENIAN__) */ 
    #if defined(__MMI_ZI_GREEK__)
        case INPUT_EZI_GREEK:
            IMEalphaLangID = ALPHA_LANG_EL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_GREEK__) */ 
    #if defined(__MMI_ZI_CZECH__)
        case INPUT_EZI_CZECH:
            IMEalphaLangID = ALPHA_LANG_CZ;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CZECH__) */ 
    #if defined(__MMI_ZI_FINNISH__)
        case INPUT_EZI_FINNISH:
            IMEalphaLangID = ALPHA_LANG_FI;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_FINNISH__) */ 
    #if defined(__MMI_ZI_DANISH__)
        case INPUT_EZI_DANISH:
            IMEalphaLangID = ALPHA_LANG_DA;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_DANISH__) */ 
    #if defined(__MMI_ZI_HUNGARIAN__)
        case INPUT_EZI_HUNGARIAN:
            IMEalphaLangID = ALPHA_LANG_HU;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_HUNGARIAN__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEchangeSubLanguage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bSetup      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ZI8BOOL IMEchangeSubLanguage(ZI8BOOL bSetup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ZI8GETPARAM zi8GetParam;
    ZI8WCHAR tmpCandBuffer[2];
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&zi8GetParam, 0, sizeof(zi8GetParam));
    zi8GetParam.Language = ZI8_LANG_ZH;
    zi8GetParam.GetMode = ZI8_GETMODE_STROKES;
    zi8GetParam.Context = ZI8_GETCONTEXT_SMS;
    zi8GetParam.GetOptions = ZI8_GETOPTION_DEFAULT;
    zi8GetParam.pCandidates = tmpCandBuffer;
    zi8GetParam.MaxCandidates = 1;
    zi8GetParam.SubLanguage = IMEsubLanguage;

    if (bSetup)
    {
        if (!Zi8GetCandidates(&zi8GetParam))
        {
            zi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
            if (!Zi8GetCandidates(&zi8GetParam))
            {
                zi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
                if (!Zi8GetCandidates(&zi8GetParam))
                {
                    bSetup = ZI8FALSE;
                }
            }
        }
    }
    if (!bSetup)
    {
        for (i = 0; i < 3; i++)
        {
            switch (zi8GetParam.SubLanguage)
            {
                case ZI8_SUBLANG_ZH_TW:
                    zi8GetParam.SubLanguage = ZI8_SUBLANG_ZH_HK;
                    break;
                case ZI8_SUBLANG_ZH_HK:
                    zi8GetParam.SubLanguage = ZI8_SUBLANG_ZH;
                    break;
                case ZI8_SUBLANG_ZH:
                    zi8GetParam.SubLanguage = ZI8_SUBLANG_ZH_TW;
                    break;
            }

            zi8GetParam.GetMode = ZI8_GETMODE_STROKES;
            if (Zi8GetCandidates(&zi8GetParam))
            {
                break;
            }

            zi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
            if (Zi8GetCandidates(&zi8GetParam))
            {
                break;
            }

            zi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
            if (Zi8GetCandidates(&zi8GetParam))
            {
                break;
            }
        }
    }

    switch (IMEzi8GetParam.GetMode)
    {
        case ZI8_GETMODE_1KEYPRESS_BOPOMOFO:
        case ZI8_GETMODE_BOPOMOFO:
            break;
        case ZI8_GETMODE_1KEYPRESS_PINYIN:
        case ZI8_GETMODE_PINYIN:
            break;
        case ZI8_GETMODE_CANGJIE:
            break;
        case ZI8_GETMODE_STROKES:
        default:
            break;
    }
    switch (zi8GetParam.SubLanguage)
    {
        case ZI8_SUBLANG_ZH_TW:
            break;
        case ZI8_SUBLANG_ZH_HK:
            break;
        case ZI8_SUBLANG_ZH:
        default:
            break;
    }

    if (IMEsubLanguage != zi8GetParam.SubLanguage)
    {
        IMEzi8GetParam.SubLanguage = IMEsubLanguage = zi8GetParam.SubLanguage;
        return (ZI8TRUE);
    }
    return (ZI8FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_STROKE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_STROKE(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8BOOL bNotAllow = ZI8FALSE;
    int i;
    U16 			ret; //新然输入法返回值
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_LOW_MEMORY_PHONE
    if (keyID == KEY0)
    {
        goto IME_EXIT;
    }
#endif /* MMI_LOW_MEMORY_PHONE */ 

    bSkipGetCandidate = ZI8FALSE;
    ziNoDrawCandidateRightArrowSymbol = ZI8FALSE;

    /* MTK Terry for eZi Max Length Check */
    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
        case KEYSOFTR:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEbValidCandidates || (!IMEfirstCandidate && !IMEelementCount))
        {
            if ((keyID == KEYSTAR))
            {
                /* IMElastProcessKeyFunc = IMEprocessKeyEZI_STROKE; */
                rtnCode = IME_CONTINUE;
                goto IME_EXIT;
            }
        }
        if (IMEbValidCandidates)
        {
            i = 0;
            switch (keyID)
            {
                case KEY0:
                    i++;    /* NO BREAK */
                case KEY9:
                    i++;    /* NO BREAK */
                case KEY8:
                    i++;    /* NO BREAK */
                case KEY7:
                    i++;    /* NO BREAK */
                case KEY6:
                    i++;    /* NO BREAK */
                case KEY5:
                    i++;    /* NO BREAK */
                case KEY4:
                    i++;    /* NO BREAK */
                case KEY3:
                    i++;    /* NO BREAK */
                case KEY2:
                    i++;    /* NO BREAK */
                case KEY1:
                    if (IMEcandCount >= ++i)
                    {
                        IMEcandIndex = i - 1;
                        keyID = KEYSOFTR;
                        break;
                    }
                    goto IME_EXIT;
            }
        }
        else
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandIndex = 0;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
            }
    }
    switch (keyID)
    {
    #ifdef MMI_LOW_MEMORY_PHONE
        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEcandIndex == 0)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
                    break;
                }
                goto IME_EXIT;
            }
            IMEcandIndex--;
            if (bLongPress)
            {
                if (!IMEbValidCandidates)
                {
                    goto IME_EXIT;  
                }
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
                    break;
                }
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (++IMEcandIndex >= IMEcandCount)
            {
                IMEfirstCandidate += IMEzi8GetParam.MaxCandidates;
            }
            else
            {
                if (bLongPress)
                {
                    if (!IMEbValidCandidates)
                    {
                        goto IME_EXIT;  
                    }
                    IMEfirstCandidate += IMEzi8GetParam.MaxCandidates;
                    break;
                }
                bSkipGetCandidate = ZI8TRUE;
            }
            break;

    #else /* MMI_LOW_MEMORY_PHONE */ 
        case KEYLEFT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEcandIndex == 0)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
                    break;
                }
                goto IME_EXIT;
            }
            IMEcandIndex--;
            if (bLongPress)
            {
                IMEcandIndex = 0;
            }
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
                break;
            }
            goto IME_EXIT;

        case KEYRIGHT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (++IMEcandIndex >= IMEcandCount)
            {
                IMEfirstCandidate += IMEzi8GetParam.MaxCandidates;
            }
            else
            {
                if (bLongPress)
                {
                    IMEcandIndex = IMEcandCount - 1;
                }
                bSkipGetCandidate = ZI8TRUE;
            }
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate += IMEzi8GetParam.MaxCandidates;
            break;
    #endif /* MMI_LOW_MEMORY_PHONE */ 
        case KEYSOFTL:
            if (bLongPress)
            {
                if (IMEbValidCandidates)
                {
                    if (IMEfirstCandidate)
                    {
                        IMEfirstCandidate = 0;
                        break;
                    }
                    if (IMEelementCount)
                    {
                        IMEelementCount = 0;
                        break;
                    }
                    IMEbValidCandidates = ZI8FALSE;
                    bSkipGetCandidate = ZI8TRUE;
                    break;
                }
                goto IME_EXIT;
            }
            if (IMEbValidCandidates)
            {
                if (IMEfirstCandidate && IMEelementCount != 0)
                {
                    IMEfirstCandidate = 0;
                    IMEbValidCandidates = ZI8FALSE;
                    bSkipGetCandidate = ZI8TRUE;
                    IMEwordCharacterCount = 0;
                    IMEelementCount = 0;
                    IMEinline[0] = 0;
                    break;

                }
                else if (IMEfirstCandidate && IMEelementCount == 0)
                {
                    IMEfirstCandidate = 0;
                    IMEbValidCandidates = ZI8FALSE;
                    bSkipGetCandidate = ZI8TRUE;
                    IMEwordCharacterCount = 0;
                    IMEinline[0] = 0;
                    break;
                }

                if (IMEelementCount)
                {
                    if (--IMEelementCount == 0)
                    {
                        IMEbValidCandidates = ZI8FALSE;
                        bSkipGetCandidate = ZI8TRUE;
                        IMEwordCharacterCount = 0;
                        IMEinline[0] = 0;
                        break;
                    }
                    break;
                }

                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                IMEwordCharacterCount = 0;
                break;
            }
            goto IME_EXIT;

        case KEYSOFTR:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (Zi8IsComponent(IMEcandidateBuffer[IMEcandIndex]))
            {
                IMEelementBuffer[0] = IMEcandidateBuffer[IMEcandIndex];
                IMEelementCount = 1;
            }
            else if ((IMEcandidateBuffer[IMEcandIndex] >= '0') && (IMEcandidateBuffer[IMEcandIndex] <= '9'))
            {
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
            }
            else
            {
                if (IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]))
                {
                    if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                    {
                        IMEwordCharacterCount = 0;
                    }
                    IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
                }
                IMEelementCount = 0;
            }
            IMEfirstCandidate = 0;
        #ifdef MMI_LOW_MEMORY_PHONE
            IMEwordCharacterCount = 0;  /* Vandana added for candidate 6 */
        #endif 
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
#ifndef __MMI_UNI_XINRAN_INPUT_METHORD__
{
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOWN;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LEFT;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOT;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER_DOWN;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_CURVED_HOOK;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOWN_OVER;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_WILDCARD;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER_DOWN_OVER;
                    break;
 }
/*UNI@bw_20070728 13:32:16   06b 非触摸移植新然输入法 */
#else
 {
        case KEY1:
	   IMEXinranCharBuffer[IMEelementCount] = 1;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER;           break;
        case KEY2:
			IMEXinranCharBuffer[IMEelementCount] = 2;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOWN;           break;
        case KEY3:
			IMEXinranCharBuffer[IMEelementCount] = 3;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LEFT;           break;
        case KEY4:
			IMEXinranCharBuffer[IMEelementCount] = 4;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOT;            break;
        case KEY5:
			IMEXinranCharBuffer[IMEelementCount] = 5;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER_DOWN;      break;
        case KEY6:
 #ifdef __MMI_UNI_XINRAN_INPUT_METHORD_SIX_KEY__
			IMEXinranCharBuffer[IMEelementCount] = 6;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_WILDCARD;    break;
case KEY7:
case KEY8:
case KEY9:
 bNotAllow = ZI8TRUE;
            break;
#else
		   
        case KEY7:
			IMEXinranCharBuffer[IMEelementCount] = 7;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_DOWN_OVER;      break;
        case KEY8:
			IMEXinranCharBuffer[IMEelementCount] = 8;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_WILDCARD;       break;
        case KEY9:
			IMEXinranCharBuffer[IMEelementCount] = 9;
           IMEelementBuffer[IMEelementCount++] = ZI8_CODE_OVER_DOWN_OVER; break;
#endif
        }
#endif
            break;

        case KEY0:
            bNotAllow = ZI8TRUE;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

        if (IMEtextType == IME_NAME_TEXT)
        {
            if (IMEcurPos)
            {
                IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
            }
            else
            {
                IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
            }
        }
        if (bNoRadicals)
        {
            IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
        }
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        if (bNoComponent || (bComponentOn2ndKey && (IMEelementCount < 2)))
        {
            IMEzi8GetParam.GetOptions = ZI8_GETOPTION_NOCOMPONENTS;
        }
        else
        {
            IMEzi8GetParam.GetOptions = ZI8_GETOPTION_DEFAULT;
        }
#ifdef __MMI_UNI_XINRAN_INPUT_METHORD__
		 /////////////////////////////////////////////////////////////////////////////////////////////
		 
		 if(IMEelementCount == 0)
	 	{
/*UNI@bw_20070728 13:45:50   非触摸,新然输入法,优化代码 */
			 memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
	 		ret = fnCharAssociation( IMEcandidateBuffer[IMEcandIndex],IMEXinrancandidateBuffer);
			if(ret != 0)
			{	
				IMEXinrancandCount = 0;
				memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
			}
	 	}
		 else if(IMEfirstCandidate == 0)
		{ //重新获取按键结果			 
			 IMEXinranCharBuffer[IMEelementCount] = 0x0; 
			 memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
	         ret  =  fnBhSearch(IMEXinranCharBuffer,IMEXinrancandidateBuffer);
			 IMEXinrancandCount = UCS2Strlen((const S8 * )IMEXinrancandidateBuffer);
			 if(ret != 0)
			{	
				IMEXinrancandCount = 0;
				memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
			}			
		}
		
		//拷贝,检查长度
		memset(IMEcandidateBuffer, 0x0, sizeof(IMEcandidateBuffer));
		UCS2Strncpy(( S8 * ) IMEcandidateBuffer,( const S8 * ) &IMEXinrancandidateBuffer[IMEfirstCandidate], IMEzi8GetParam.MaxCandidates);
		IMEcandCount = UCS2Strlen((const S8 * )IMEcandidateBuffer); 

		if( IMEcandCount == 0)//拷贝失败,没有字符串了
		{
			if(IMEfirstCandidate >= IMEzi8GetParam.MaxCandidates)
			{
				IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
			}
			
			UCS2Strncpy(( S8 * ) IMEcandidateBuffer, ( const S8 * )&IMEXinrancandidateBuffer[IMEfirstCandidate], IMEzi8GetParam.MaxCandidates);
			IMEcandCount = UCS2Strlen((const S8 * )IMEcandidateBuffer); 
			
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
#else 
IMEcandCount = Zi8GetCandidates( &IMEzi8GetParam );
#endif

        if (!IMEcandCount)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
                ziNoDrawCandidateRightArrowSymbol = ZI8TRUE;

            }
            else if (IMEelementCount)
            {
                IMEzi8GetParam.ElementCount = --IMEelementCount;
                IMEfirstCandidate = lastFirstCandidate;
            }
            IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
            if (bNoComponent || (bComponentOn2ndKey && (IMEelementCount < 2)))
            {
                IMEzi8GetParam.GetOptions = ZI8_GETOPTION_NOCOMPONENTS;
            }
            else
            {
                IMEzi8GetParam.GetOptions = ZI8_GETOPTION_DEFAULT;
            }
#ifdef __MMI_UNI_XINRAN_INPUT_METHORD__
		 /////////////////////////////////////////////////////////////////////////////////////////////
		 
		 if(IMEelementCount == 0)
	 	{
			 memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
	 		ret = fnCharAssociation( IMEcandidateBuffer[IMEcandIndex],IMEXinrancandidateBuffer);
			if(ret != 0)
			{	
				IMEXinrancandCount = 0;
				memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
			}
	 	}
		 else if(IMEfirstCandidate == 0)
		{ //重新获取按键结果			 
			 IMEXinranCharBuffer[IMEelementCount] = 0x0; 
			 memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
	         ret  =  fnBhSearch(IMEXinranCharBuffer,IMEXinrancandidateBuffer);
			 IMEXinrancandCount = UCS2Strlen((const S8 * )IMEXinrancandidateBuffer);
			 if(ret != 0)
			{	
				IMEXinrancandCount = 0;
				memset(IMEXinrancandidateBuffer, 0x0, sizeof(IMEXinrancandidateBuffer));
			}			
		}
		
		//拷贝,检查长度
		memset(IMEcandidateBuffer, 0x0, sizeof(IMEcandidateBuffer));
		UCS2Strncpy( ( S8 * )IMEcandidateBuffer, ( const S8 * )&IMEXinrancandidateBuffer[IMEfirstCandidate], IMEzi8GetParam.MaxCandidates);
		IMEcandCount = UCS2Strlen((const S8 * )IMEcandidateBuffer); 

		if( IMEcandCount == 0)//拷贝失败,没有字符串了
		{
			if(IMEfirstCandidate >= IMEzi8GetParam.MaxCandidates)
			{
				IMEfirstCandidate -= IMEzi8GetParam.MaxCandidates;
			}
			
			UCS2Strncpy( ( S8 * )IMEcandidateBuffer, ( const S8 * )&IMEXinrancandidateBuffer[IMEfirstCandidate], IMEzi8GetParam.MaxCandidates);
			IMEcandCount = UCS2Strlen((const S8 * )IMEcandidateBuffer); 
			
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
#else 
IMEcandCount = Zi8GetCandidates( &IMEzi8GetParam );
#endif
            bNotAllow = ZI8FALSE;
            if (IMEelementCount == 0)
            {
                bNotAllow = ZI8TRUE;
            }
        }

        if (!IMEcandCount || (bNotAllow && (!IMEfirstCandidate && !IMEelementCount && !IMEzi8GetParam.wordCandidates)))
        {
            IMEbValidCandidates = ZI8FALSE;
        }
        else
        {
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            if (ziNoDrawCandidateRightArrowSymbol)
            {
                IMEcandIndex = IMEcandCount - 1;
            }

            IMEbValidCandidates = ZI8TRUE;
            if (keyID == KEYLEFT)
            {
                IMEcandIndex = IMEcandCount - 1;
            }
        }

        for (i = 0; i < IMEelementCount; i++)
        {
            IMEinline[i] = IMEelementBuffer[i];
        }
        if (IMEfirstCandidate)
        {
            IMEinline[i++] = ZI8_CODE_MORE;
        }
        IMEinline[i] = 0;
        IMEprediction = i;
    }

    if (IMEbValidCandidates)
    {
        labelSoftR[0] = 'S';
        if (!IMEfirstCandidate && !IMEelementCount)
        {
            labelSoftL[0] = 'S';
        }
        else
        {
            labelSoftL[0] = 'C';
        }
    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKey1Phonetic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKey1Phonetic(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8BOOL bSkipGetZHCandidate = ZI8FALSE;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8WCHAR lastIMEtoneMark = IMEtoneMark;
    ZI8BOOL bNotAllow = ZI8FALSE;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry for eZi Max Length Check */
    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
        case KEYSOFTR:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEbPhoneticComfirmed && (!IMEbValidCandidates || (!IMEfirstCandidate && !IMEelementCount)))
        {
            if ((keyID == KEYSTAR))
            {
                /* IMElastProcessKeyFunc = IMEprocessKey1Phonetic; */
                rtnCode = IME_CONTINUE;
                goto IME_EXIT;
            }
        }
        if (IMEbValidCandidates)
        {
            i = 0;
            switch (keyID)
            {
                case KEY0:
                    i++;    /* NO BREAK */
                case KEY9:
                    i++;    /* NO BREAK */
                case KEY8:
                    i++;    /* NO BREAK */
                case KEY7:
                    i++;    /* NO BREAK */
                case KEY6:
                    i++;    /* NO BREAK */
                case KEY5:
                    i++;    /* NO BREAK */
                case KEY4:
                    i++;    /* NO BREAK */
                case KEY3:
                    i++;    /* NO BREAK */
                case KEY2:
                    i++;    /* NO BREAK */
                case KEY1:
                    if (IMEcandCount >= ++i)
                    {
                        IMEcandIndex = i - 1;
                        keyID = KEYSOFTR;
                        break;
                    }
                    goto IME_EXIT;
            }
        }
        else if (!IMEbValidCandidates)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandIndex = 0;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandIndex == 0) || bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                    break;
                }
                if (IMEcandIndex)
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = 0;
                    break;
                }
                goto IME_EXIT;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEcandIndex--;
            break;

        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            goto IME_EXIT;

        case KEYSTAR:
            if (!IMEbValidCandidates || IMEbPhoneticComfirmed)
            {
                goto IME_EXIT;
            }
            IMEprediction = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEpPhoneticPtr[0], 0) - 1;
            if ((IMEinline[IMEprediction - 1] >= ZI8_CODE_TONES_1) &&
                (IMEinline[IMEprediction - 1] <= ZI8_CODE_TONES_5))
            {
                IMEtoneMark = IMEinline[IMEprediction - 1];
                IMEinline[IMEprediction - 1] = 0;
            }
            else
            {
                IMEtoneMark = 0;
            }
            IMEelementBuffer[IMEelementCount] = 0;
            IMEelementCount = 0;
            IMEfirstCandidate = 0;
            IMEbPhoneticComfirmed = ZI8TRUE;
            break;

        case KEYRIGHT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
            {
                if (IMEcandCount == (IMEmaxCols / 2))
                {
                    IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = IMEcandCount - 1;
                }
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
            }
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEcandCount == (IMEmaxCols / 2))
            {
                IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
                IMEcandIndex = IMEcandCount - 1;
            }
            break;

        case KEYSOFTL:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate = 0;
                    break;
                }
                if (IMEbPhoneticComfirmed)
                {
                    IMEbPhoneticComfirmed = ZI8FALSE;
                    IMEinline[0] = 0;
                    IMEprediction = 0;
                    break;
                }
                if (IMEelementCount)
                {
                    IMEelementCount = 0;
                    break;
                }
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                break;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            if (IMEbPhoneticComfirmed)
            {
                if ((IMEtoneMark >= ZI8_CODE_TONES_1) && (IMEtoneMark <= ZI8_CODE_TONES_5))
                {
                    IMEtoneMark = 0;
                    break;
                }
                for (IMEelementCount = 0; IMEelementBuffer[IMEelementCount]; IMEelementCount++);
                IMEprediction = IMEelementCount;
                IMEbPhoneticComfirmed = ZI8FALSE;
                break;
            }
            if (IMEelementCount)
            {
                IMEelementBuffer[--IMEelementCount] = 0;
                break;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEbValidCandidates = ZI8FALSE;
            IMEwordCharacterCount = 0;
            IMEprediction = 0;
            IMEinline[0] = 0;
            break;

        case KEYSOFTR:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandidateBuffer[IMEcandIndex] >= '0') && (IMEcandidateBuffer[IMEcandIndex] <= '9'))
            {
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
                break;
            }
            if (IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]))
            {
                if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                {
                    IMEwordCharacterCount = 0;
                }
                IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
            }
            IMEbPhoneticComfirmed = ZI8FALSE;
            IMEfirstCandidate = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (IMEbPhoneticComfirmed)
            {
                switch (keyID)
                {
                    case KEY1:
                        IMEtoneMark = ZI8_CODE_TONES_1;
                        break;
                    case KEY2:
                        IMEtoneMark = ZI8_CODE_TONES_2;
                        break;
                    case KEY3:
                        IMEtoneMark = ZI8_CODE_TONES_3;
                        break;
                    case KEY4:
                        IMEtoneMark = ZI8_CODE_TONES_4;
                        break;
                    case KEY5:
                        IMEtoneMark = ZI8_CODE_TONES_5;
                        break;
                    default:
                        goto IME_EXIT;
                }
                IMEfirstCandidate = 0;
                break;
            }
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
                case KEY0:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
                    break;
            }
            IMEelementBuffer[IMEelementCount] = 0;
            IMEfirstCandidate = 0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;
        default:
            goto IME_EXIT;
    }

    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
    if (!bSkipGetZHCandidate)
    {
        if (IMEbPhoneticComfirmed)
        {
            i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEpPhoneticPtr[0], 0) - 1;
            if ((IMEinline[i - 1] >= ZI8_CODE_TONES_1) && (IMEinline[i - 1] <= ZI8_CODE_TONES_5))
            {
                IMEinline[--i] = 0;
            }
            IMEzi8GetParam.ElementCount = i;
            if (IMEtoneMark)
            {
                IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                IMEinline[IMEzi8GetParam.ElementCount] = 0;
            }
            IMEzi8GetParam.pElements = IMEinline;
            if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_BOPOMOFO)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
            }
            else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_PINYIN)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
            }
        }
        else
        {
            if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
            {
                IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
            }
            IMEzi8GetParam.ElementCount = IMEelementCount;
            IMEzi8GetParam.pElements = IMEelementBuffer;
            if (IMEzi8GetParam.GetMode == ZI8_GETMODE_BOPOMOFO)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_BOPOMOFO;
            }
            else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_PINYIN;
            }
        }
        #ifdef __MMI_ZI_USING_PSCRATCH_BUFFER__
        memset(IMEScratchBuffer, 0, sizeof(IMEScratchBuffer));
        IMEzi8GetParam.pScratch = IMEScratchBuffer;
        #endif /* __MMI_ZI_USING_PSCRATCH_BUFFER__ */  
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        if (!IMEcandCount)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else if (IMEzi8GetParam.ElementCount)
            {
                --IMEzi8GetParam.ElementCount;
                if (IMEtoneMark)
                {
                    IMEtoneMark = lastIMEtoneMark;
                }
                if (IMEtoneMark)
                {
                    IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                    IMEinline[IMEzi8GetParam.ElementCount] = 0;
                }
                else if (!IMEbPhoneticComfirmed)
                {
                    IMEelementCount--;
                }
                IMEfirstCandidate = lastFirstCandidate;
            }
            IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
            IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        }
        if (!IMEcandCount ||
            (bNotAllow && (!IMEfirstCandidate && !IMEbPhoneticComfirmed &&
                           !IMEelementCount && !IMEzi8GetParam.wordCandidates)))
        {
            IMEbValidCandidates = ZI8FALSE;
        }
        else
        {
            IMEbValidCandidates = ZI8TRUE;
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
        }
        if (IMEfirstCandidate)
        {
            IMEinline[IMEzi8GetParam.ElementCount++] = ZI8_CODE_MORE;
        }
        IMEinline[IMEzi8GetParam.ElementCount] = 0;

        if (!IMEbPhoneticComfirmed)
        {
            IMEprediction = IMEelementCount;
        }
        else
        {
            IMEprediction = IMEzi8GetParam.ElementCount;
        }
    }
    if (IMEbValidCandidates && !IMEbPhoneticComfirmed)
    {
        Zi8GetCharInfo2(
            IMEcandidateBuffer[IMEcandIndex],
            IMEpPhoneticPtr[0],
            8,
            IMEzi8GetParam.GetMode,
            IMEelementBuffer,
            IMEelementCount);
    }
    if (IMEbValidCandidates && IMEelementCount)
    {
        IMEbValidPhonetic = ZI8TRUE;
    }
    else
    {
        IMEbValidPhonetic = ZI8FALSE;
    }

    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKey2Phonetic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKey2Phonetic(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    int i;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8WCHAR lastIMEtoneMark = IMEtoneMark;
    ZI8UCHAR lastIMEphoneticIndex = IMEphoneticIndex;
    ZI8BOOL bNotAllow = ZI8FALSE;
    ZI8WCHAR lastZiFirstPhoneticCandidate = zifirstPhoneticCandidate;

#if 0
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT Dara Added ..on 16/12/2k4 ....for display problem of long words in smart pinyin */
#ifdef MMI_LOW_MEMORY_PHONE
    ZiSmartPinyinFlag = 0x01;
#endif 
    /* PMT end */
    bSkipGetCandidate = ZI8FALSE;
    bSkipGetZHCandidate = ZI8FALSE;
    ziRefillPhoneticBuffer = ZI8FALSE;
    ziNoDrawRightArrowSymbol = ZI8FALSE;
    ziNoDrawCandidateRightArrowSymbol = ZI8FALSE;

    /* MTK Terry for eZi Max Length Check */
    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
        case KEYSOFTR:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEbPhoneticComfirmed && (!IMEbValidCandidates || (!IMEfirstCandidate && !IMEelementCount)))
        {
            if ((keyID == KEYSTAR))
            {
                /* IMElastProcessKeyFunc = IMEprocessKey2Phonetic; */
                rtnCode = IME_CONTINUE;
                goto IME_EXIT;
            }
        }
        if (IMEbValidCandidates && !IMEbFocusOnPhonetic)
        {
            i = 0;
            switch (keyID)
            {
                case KEY0:
                    i++;    /* NO BREAK */
                case KEY9:
                    i++;    /* NO BREAK */
                case KEY8:
                    i++;    /* NO BREAK */
                case KEY7:
                    i++;    /* NO BREAK */
                case KEY6:
                    i++;    /* NO BREAK */
                case KEY5:
                    i++;    /* NO BREAK */
                case KEY4:
                    i++;    /* NO BREAK */
                case KEY3:
                    i++;    /* NO BREAK */
                case KEY2:
                    i++;    /* NO BREAK */
                case KEY1:
                    if (IMEcandCount >= ++i)
                    {
                        IMEcandIndex = i - 1;
                        keyID = KEYSOFTR;
                        break;
                    }
                    goto IME_EXIT;
            }
        }
        else if (!IMEbValidCandidates)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandIndex = 0;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
            }
        }
    }
    switch (keyID)
    {
    #ifdef MMI_LOW_MEMORY_PHONE
        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (!IMEbFocusOnPhonetic)
            {
                if ((IMEcandIndex == 0) || bLongPress)
                {
                    if (IMEfirstCandidate)
                    {
                        IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                        break;
                    }
                    if (IMEcandIndex)
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                        IMEcandIndex = 0;
                        break;
                    }
                    goto IME_EXIT;
                }
                bSkipGetZHCandidate = ZI8TRUE;
                IMEcandIndex--;
                break;
            }
            IMEfirstCandidate = 0;
            if (!IMEphoneticIndex)
            {
                if ((IMEphoneticIndex == 0) || bLongPress)
                {
                    if (zifirstPhoneticCandidate)
                    {
                        zifirstPhoneticCandidate--;
                        /* zifirstPhoneticCandidate  -= MAX_PHONETIC_CANDSIZE; */
                        bSkipGetCandidate = ZI8FALSE;
                        break;
                    }
                    if (IMEphoneticIndex)
                    {
                        bSkipGetCandidate = ZI8TRUE;
                        IMEphoneticIndex = 0;
                        break;
                    }
                    goto IME_EXIT;
                }
                bSkipGetCandidate = ZI8TRUE;
                IMEphoneticIndex--;
                break;

            }
            else
            {
                bSkipGetCandidate = ZI8TRUE;
                IMEphoneticIndex--;
            }
            break;

        case KEYSTAR:
            if (!IMEbValidCandidates || IMEbPhoneticComfirmed)
            {
                goto IME_EXIT;
            }
            if (!bLongPress)
            {
                bSkipGetCandidate = ZI8TRUE;
                IMEfirstCandidate = 0;
                if (++IMEphoneticIndex >= IMEphoneticCount)
                {
                    IMEphoneticIndex = 0;
                }
            }
            else
            {
                IMEbFocusOnPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8TRUE;
                i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEphoneticBuffer, IMEphoneticIndex);
                IMEprediction = i - 1;
                IMEtoneMark = 0;
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEelementCount = 0;
            }
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (!IMEbFocusOnPhonetic)
            {
                if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
                {
                    if (IMEcandCount == (IMEmaxCols / 2))
                    {
                        IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                    }
                    else
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                        IMEcandIndex = IMEcandCount - 1;
                    }
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                }
                break;
            }
            IMEfirstCandidate = 0;
            if (++IMEphoneticIndex >= IMEphoneticCount || bLongPress)
            {
                if (IMEphoneticCount == MAX_PHONETIC_CANDSIZE)
                {
                    zifirstPhoneticCandidate += MAX_PHONETIC_CANDSIZE;
                    IMEphoneticIndex = 0;
                    bSkipGetCandidate = ZI8FALSE;

                }
                else
                {
                    bSkipGetCandidate = ZI8TRUE;
                    IMEphoneticIndex = IMEphoneticCount - 1;
                }

            }
            break;

    #else /* MMI_LOW_MEMORY_PHONE */ 
        case KEYLEFT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (!IMEbFocusOnPhonetic)
            {
                if ((IMEcandIndex == 0) || bLongPress)
                {
                    if (IMEfirstCandidate)
                    {
                        IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                        break;
                    }
                    if (IMEcandIndex)
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                        IMEcandIndex = 0;
                        break;
                    }
                    goto IME_EXIT;
                }
                bSkipGetZHCandidate = ZI8TRUE;
                IMEcandIndex--;
                break;
            }
            IMEfirstCandidate = 0;
            if (!IMEphoneticIndex)
            {
                if ((IMEphoneticIndex == 0) || bLongPress)
                {
                    if (zifirstPhoneticCandidate)
                    {
                        zifirstPhoneticCandidate -= MAX_PHONETIC_CANDSIZE;
                        bSkipGetCandidate = ZI8FALSE;
                        break;
                    }
                    if (IMEphoneticIndex)
                    {
                        bSkipGetCandidate = ZI8TRUE;
                        IMEphoneticIndex = 0;
                        break;
                    }
                    goto IME_EXIT;
                }
                bSkipGetCandidate = ZI8TRUE;
                IMEphoneticIndex--;
                break;

            }
            else
            {
                bSkipGetCandidate = ZI8TRUE;
                IMEphoneticIndex--;
            }
            break;

        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (IMEbPhoneticComfirmed || !IMEbValidPhonetic)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                    break;
                }
                goto IME_EXIT;
            }
            IMEbFocusOnPhonetic = !IMEbFocusOnPhonetic;
            bSkipGetCandidate = ZI8TRUE;
            bSkipGetZHCandidate = ZI8TRUE;
            if (IMEbFocusOnPhonetic)
            {
                IMEcandIndex = 0xFF;
            }
            else
            {
                IMEcandIndex = IMEcandCount / 2;
            }
            break;

        case KEYSTAR:
            if (!IMEbValidCandidates || IMEbPhoneticComfirmed)
            {
                goto IME_EXIT;
            }
            if (!bLongPress)
            {
                bSkipGetCandidate = ZI8TRUE;
                IMEfirstCandidate = 0;
                if (++IMEphoneticIndex >= IMEphoneticCount)
                {
                    IMEphoneticIndex = 0;
                }
            }
            else
            {
                IMEbFocusOnPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8TRUE;
                i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEphoneticBuffer, IMEphoneticIndex);
                IMEprediction = i - 1;
                IMEtoneMark = 0;
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEelementCount = 0;
            }
            break;

        case KEYRIGHT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (!IMEbFocusOnPhonetic)
            {
                if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
                {
                    if (IMEcandCount == (IMEmaxCols / 2))
                    {
                        IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                    }
                    else
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                        IMEcandIndex = IMEcandCount - 1;
                    }
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                }
                break;
            }
            IMEfirstCandidate = 0;
            if (++IMEphoneticIndex >= IMEphoneticCount || bLongPress)
            {
                if (IMEphoneticCount == MAX_PHONETIC_CANDSIZE)
                {
                    zifirstPhoneticCandidate += MAX_PHONETIC_CANDSIZE;
                    IMEphoneticIndex = 0;
                    bSkipGetCandidate = ZI8FALSE;

                }
                else
                {
                    bSkipGetCandidate = ZI8TRUE;
                    IMEphoneticIndex = IMEphoneticCount - 1;
                }

            }
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            bSkipGetCandidate = ZI8TRUE;
            if (IMEbPhoneticComfirmed || !IMEbValidPhonetic)
            {
                if (IMEcandCount == (IMEmaxCols / 2))
                {
                    IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = IMEcandCount - 1;
                }
                break;
            }
            IMEbFocusOnPhonetic = !IMEbFocusOnPhonetic;
            bSkipGetCandidate = ZI8TRUE;
            bSkipGetZHCandidate = ZI8TRUE;
            if (IMEbFocusOnPhonetic)
            {
                IMEcandIndex = 0xFF;
            }
            else
            {
                IMEcandIndex = IMEcandCount / 2;
            }
            break;
    #endif /* MMI_LOW_MEMORY_PHONE */ 
        case KEYSOFTL:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEbFocusOnPhonetic)
            {
                zifirstPhoneticCandidate = 0;
            }

            if (bLongPress)
            {
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEfirstCandidate = 0;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEinline[0] = 0;
                IMEprediction = 0;
                IMEelementCount = 0;
                IMEbValidPhonetic = ZI8FALSE;
                break;
            }
            /* MTK Terry for Behavior of Smart Chinese IME */
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
        #endif /* 0 */ 
        #ifdef MMI_LOW_MEMORY_PHONE
            if (ziFlagRSK)
            {
                CharacterInsertedFlag = 1;
                ziFlagRSK = 0;
            }
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            if (IMEbPhoneticComfirmed)
            {
                bSkipGetCandidate = ZI8TRUE;
                if ((IMEtoneMark >= ZI8_CODE_TONES_1) && (IMEtoneMark <= ZI8_CODE_TONES_5))
                {
                    IMEtoneMark = 0;
                    break;
                }
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEbValidPhonetic = ZI8TRUE;
                bSkipGetCandidate = ZI8TRUE;
                IMEbFocusOnPhonetic = ZI8TRUE;
                ziRefillPhoneticBuffer = ZI8TRUE;
                for (IMEelementCount = 0; IMEelementBuffer[IMEelementCount]; IMEelementCount++);
                IMEprediction = IMEelementCount;
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount == 0)
                {
                    bSkipGetCandidate = ZI8TRUE;
                    IMEbFocusOnPhonetic = ZI8FALSE;
                    IMEbValidPhonetic = ZI8FALSE;
                    IMEbValidCandidates = ZI8FALSE;
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEwordCharacterCount = 0;
                    IMEprediction = 0;
                    IMEinline[0] = 0;

                }
                IMEelementBuffer[IMEelementCount] = 0;
                break;
            }
            IMEbValidCandidates = ZI8FALSE;
            bSkipGetCandidate = ZI8TRUE;
            bSkipGetZHCandidate = ZI8TRUE;
            IMEbValidPhonetic = ZI8FALSE;
            IMEwordCharacterCount = 0;
            IMEprediction = 0;
            IMEinline[0] = 0;
            break;

        case KEYSOFTR:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }

            /* zifirstPhoneticCandidate = 0; */

            if ((IMEcandidateBuffer[IMEcandIndex] >= '0') && (IMEcandidateBuffer[IMEcandIndex] <= '9'))
            {
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
                break;
            }
            if (!IMEbFocusOnPhonetic)
            {
                if (IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]))
                {
                    if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                    {
                        IMEwordCharacterCount = 0;
                    }
                    IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
                }
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEfirstCandidate = 0;
            }
            else
            {
                IMEbFocusOnPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8TRUE;
                i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEphoneticBuffer, IMEphoneticIndex);
                IMEprediction = i - 1;
                IMEtoneMark = 0;
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEbValidPhonetic = ZI8FALSE;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            zifirstPhoneticCandidate = 0;
            if (IMEbPhoneticComfirmed)
            {
                switch (keyID)
                {
                    case KEY1:
                        IMEtoneMark = ZI8_CODE_TONES_1;
                        break;
                    case KEY2:
                        IMEtoneMark = ZI8_CODE_TONES_2;
                        break;
                    case KEY3:
                        IMEtoneMark = ZI8_CODE_TONES_3;
                        break;
                    case KEY4:
                        IMEtoneMark = ZI8_CODE_TONES_4;
                        break;
                    case KEY5:
                        IMEtoneMark = ZI8_CODE_TONES_5;
                        break;
                    default:
                        goto IME_EXIT;
                }
                IMEfirstCandidate = 0;
                break;
            }
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
                case KEY0:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
                    break;
            }
            IMEelementBuffer[IMEelementCount] = 0;
            IMEbFocusOnPhonetic = ZI8TRUE;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            zifirstPhoneticCandidate = 0;
            break;
        default:
            goto IME_EXIT;
    }

    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
    if (!bSkipGetCandidate && !IMEbPhoneticComfirmed)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

    #if 0
/* under construction !*/
    #endif /* 0 */ 

    #ifdef __MMI_ZI_USING_PSCRATCH_BUFFER__
        memset(IMEScratchBuffer, 0, sizeof(IMEScratchBuffer));
        IMEzi8GetParam.pScratch = IMEScratchBuffer;
    #endif /* __MMI_ZI_USING_PSCRATCH_BUFFER__ */
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        IMEzi8GetParam.FirstCandidate = zifirstPhoneticCandidate;
        IMEzi8GetParam.pElements = IMEelementBuffer;
        IMEzi8GetParam.pCandidates = IMEphoneticBuffer;
        IMEzi8GetParam.MaxCandidates = MAX_PHONETIC_CANDSIZE;
        if (IMEzi8GetParam.GetMode == ZI8_GETMODE_BOPOMOFO)
        {
            IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_BOPOMOFO;
        }
        else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN)
        {
            IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_PINYIN;
        }

        IMEbValidPhonetic = ZI8FALSE;
        IMEbValidCandidates = ZI8FALSE;
        IMEfirstCandidate = 0;
        IMEinline[0] = 0;
        IMEprediction = 0;
        IMEphoneticIndex = 0;
        IMEphoneticBase = 0;
        IMEphoneticCount = Zi8GetCandidates(&IMEzi8GetParam);

        if (keyID == KEYLEFT && !bLongPress && IMEphoneticCount)
        {
            IMEphoneticIndex = IMEphoneticCount - 1;
        }

        if (!IMEphoneticCount)
        {
        #if defined MMI_LOW_MEMORY_PHONE
            if (keyID == KEYDOWN && zifirstPhoneticCandidate)   /* look for down event since right key is not mapped */
        #else 
            if (keyID == KEYRIGHT && zifirstPhoneticCandidate)
        #endif 
            {
                zifirstPhoneticCandidate -= MAX_PHONETIC_CANDSIZE;
                IMEzi8GetParam.FirstCandidate = zifirstPhoneticCandidate;
                IMEphoneticCount = Zi8GetCandidates(&IMEzi8GetParam);
                IMEphoneticIndex = lastIMEphoneticIndex;
                IMEfirstCandidate = lastFirstCandidate;
                bSkipGetCandidate = ZI8TRUE;
                ziNoDrawRightArrowSymbol = ZI8TRUE;
            }
            else
            {

                if (IMEelementCount)
                {
                    IMEzi8GetParam.ElementCount = --IMEelementCount;
                    IMEelementBuffer[IMEelementCount] = 0;
                    zifirstPhoneticCandidate = lastZiFirstPhoneticCandidate;
                    IMEzi8GetParam.FirstCandidate = zifirstPhoneticCandidate;
                }
                IMEphoneticCount = Zi8GetCandidates(&IMEzi8GetParam);
                if (IMEelementCount)
                {
                    IMEphoneticIndex = lastIMEphoneticIndex;
                    IMEfirstCandidate = lastFirstCandidate;
                    bSkipGetCandidate = ZI8TRUE;
                #if 0
/* under construction !*/
                #endif /* 0 */ 

                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEbValidPhonetic = ZI8FALSE;
                    IMEinline[0] = 0;
                    IMEphoneticCount = 0;
                }

            }

        }
        if (IMEphoneticCount)
        {
            IMEbValidPhonetic = ZI8TRUE;
            for (i = 0; i < IMEphoneticCount; i++)
            {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* 0 */ 
                Zi8CopyWordListW(IMEpPhoneticPtr[i], 8, IMEphoneticBuffer, (ZI8UCHAR) i);
            }
        }
    }

    if (!bSkipGetZHCandidate)
    {
        if (IMEbPhoneticComfirmed || IMEelementCount)
        {
            //PMT dara added ..on 1/12/2k4 
            //#ifdef MMI_LOW_MEMORY_PHONE
            //                      CompositionWindowHideFlag=0;
            //#endif 
            //PMT end
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            {
                IMEzi8GetParam.ElementCount = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEphoneticBuffer, IMEphoneticIndex) - 1;
            }
            if (IMEbPhoneticComfirmed && IMEtoneMark)
            {
                IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                IMEinline[IMEzi8GetParam.ElementCount] = 0;
            }
        }
        else
        {
            IMEzi8GetParam.ElementCount = 0;
        }
    #ifdef __MMI_ZI_USING_PSCRATCH_BUFFER__
        memset(IMEScratchBuffer, 0, sizeof(IMEScratchBuffer));
        IMEzi8GetParam.pScratch = IMEScratchBuffer;
    #endif /* __MMI_ZI_USING_PSCRATCH_BUFFER__ */
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        IMEzi8GetParam.pElements = IMEinline;
        IMEzi8GetParam.pCandidates = IMEcandidateBuffer;
        IMEzi8GetParam.MaxCandidates = (ZI8UCHAR) (IMEmaxCols / 2);
        if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_BOPOMOFO)
        {
            IMEzi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
        }
        else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_PINYIN)
        {
            IMEzi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
        }

        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);   /* will change the buffer and send it */
    #ifdef MMI_LOW_MEMORY_PHONE     /* vandana added for showing of the right arrow when only one candidate is there */
        if (IMEcandCount < 2)                               /* if there is one candidate the arrow disappears since there is no ch */
    #else 
        if (!IMEcandCount)
    #endif 
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                ziNoDrawCandidateRightArrowSymbol = ZI8TRUE;
            }
            else if (IMEzi8GetParam.ElementCount)
            {
                --IMEzi8GetParam.ElementCount;
                if (IMEbPhoneticComfirmed && IMEtoneMark)
                {
                    IMEtoneMark = lastIMEtoneMark;
                    if (IMEtoneMark)
                    {
                        IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                        IMEinline[IMEzi8GetParam.ElementCount] = 0;
                    }
                }
                IMEfirstCandidate = lastFirstCandidate;
            }
            IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
            IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        }
        if (!IMEcandCount ||
            (bNotAllow && (!IMEfirstCandidate && !IMEbPhoneticComfirmed &&
                           !IMEelementCount && !IMEzi8GetParam.wordCandidates)))
        {
            IMEbValidCandidates = ZI8FALSE;
            IMEbValidPhonetic = ZI8FALSE;
        }
        else
        {
            IMEbValidCandidates = ZI8TRUE;
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            if (ziNoDrawCandidateRightArrowSymbol)
            {
                IMEcandIndex = IMEcandCount - 1;
            }
            if (IMEbFocusOnPhonetic)
            {
                IMEcandIndex = 0xFF;
            }
        }
        if (!IMEelementCount)
        {
            IMEbValidPhonetic = ZI8FALSE;
        }

        if (IMEfirstCandidate)
        {
            IMEinline[IMEzi8GetParam.ElementCount++] = ZI8_CODE_MORE;

        }
        
        IMEinline[IMEzi8GetParam.ElementCount] = 0;

        if (!IMEbPhoneticComfirmed)
        {
            IMEprediction = IMEelementCount;
        }
        else
        {
            IMEprediction = IMEzi8GetParam.ElementCount;
        }
    }

    if (IMEbValidPhonetic && (IMEphoneticIndex != IMEphoneticBase))
    {
        IMEphoneticBase = IMEphoneticIndex;
    }

    if (IMEbValidCandidates)
    {
        labelSoftR[0] = 'S';
        if (!IMEbPhoneticComfirmed && !IMEfirstCandidate && !IMEelementCount)
        {
            labelSoftL[0] = 'S';
        }
        else
        {
            labelSoftL[0] = 'C';
        }
    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }

    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyMultitapPhonetic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyMultitapPhonetic(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8BOOL bSkipGetZHCandidate = ZI8FALSE;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8WCHAR lastIMEtoneMark = IMEtoneMark;
    PZI8WCHAR pLayout = ZI8NULL;
    ZI8BOOL bBackSapce = ZI8FALSE;
    ZI8BOOL bCheckRefWord = ZI8FALSE;
    int i = 0;
    ZI8WCHAR preKeyID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    bSkipGetZHCandidate = ZI8FALSE;
    ziRefillPhoneticBuffer = ZI8FALSE;
    ziNoDrawRightArrowSymbol = ZI8FALSE;
    ziNoDrawCandidateRightArrowSymbol = ZI8FALSE;
    bSingleChar = ZI8TRUE;

    /* MTK Terry for eZi Max Length Check */
    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
        case KEYSOFTR:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN)
    {
        if (keyID == KEY0 || (keyID == KEY1  && !IMEbPhoneticComfirmed))
        {
            goto IME_EXIT;
        }
    }

    if (!IMEbPhoneticComfirmed && IMEelementCount != 0)
    {
    #ifdef MMI_LOW_MEMORY_PHONE
        if (keyID == KEYLEFT || keyID == KEYRIGHT)
    #else 
        if (keyID == KEYLEFT || keyID == KEYRIGHT || keyID == KEYUP)
    #endif 

            goto IME_EXIT;
    }

    if (!IMEelementCount)
    {
        lastKeyID = 0;
        index = 0;
    }

    preKeyID = lastKeyID;
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
    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    if (bSingleChar)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_SINGLE_CHAR;
    }

    switch (keyID)
    {
        case KEYLEFT:
        case KEYRIGHT:
        case KEYUP:
        case KEYDOWN:
            lastKeyID = 0;
            if (!IMEbPhoneticComfirmed && IMEelementCount != 0)
            {
                IMEbPhoneticComfirmed = ZI8TRUE;
                bSkipGetZHCandidate = ZI8FALSE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbFocusOnPhonetic = ZI8FALSE;
                break;
            }
            switch (keyID)
            {
            #ifdef MMI_LOW_MEMORY_PHONE
                case KEYUP:
            #else 
                case KEYLEFT:
            #endif 
                  IME_DO_IT_AS_LEFT:
                    if (!IMEbValidCandidates)
                    {
                        goto IME_EXIT;
                    }
                    if ((IMEcandIndex == 0) || bLongPress)
                    {
                        if (IMEfirstCandidate)
                        {
                            /* bBackSapce = ZI8TRUE; */
                            IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                            break;
                        }
                        if (IMEcandIndex)
                        {
                            bSkipGetZHCandidate = ZI8TRUE;
                            IMEcandIndex = 0;
                            break;
                        }
                        goto IME_EXIT;
                    }
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex--;
                    break;
                #ifdef MMI_LOW_MEMORY_PHONE
                case KEYDOWN:
                #else 
                case KEYRIGHT:
                #endif 
                  IME_DO_IT_AS_RIGHT:
                    if (!IMEbValidCandidates)
                    {
                        goto IME_EXIT;
                    }
                    if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
                    {
                        if (IMEcandCount == (IMEmaxCols / 2))
                        {
                            IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                        }
                        else
                        {
                            bSkipGetZHCandidate = ZI8TRUE;
                            IMEcandIndex = IMEcandCount - 1;
                        }

                    }
                    else
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                    }
                    break;
                #ifdef MMI_LOW_MEMORY_PHONE

                #else /* MMI_LOW_MEMORY_PHONE */ 
                case KEYUP:
                    if (IMEdoWordCand)
                    {
                        goto IME_DO_IT_AS_LEFT;
                    }
                    if (!IMEbValidCandidates)
                    {
                        goto IME_EXIT;
                    }
                    if (IMEfirstCandidate)
                    {
                        /* bBackSapce = ZI8TRUE; */
                        IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                        break;
                    }
                    goto IME_EXIT;

                case KEYDOWN:
                    if (IMEdoWordCand)
                    {
                        goto IME_DO_IT_AS_RIGHT;
                    }
                    if (!IMEbValidCandidates)
                    {
                        goto IME_EXIT;
                    }
                    if (IMEcandCount == (IMEmaxCols / 2))
                    {
                        IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                    }
                    else
                    {
                        bSkipGetZHCandidate = ZI8TRUE;
                        IMEcandIndex = IMEcandCount - 1;
                    }
                    break;
                #endif /* MMI_LOW_MEMORY_PHONE */ 
            }
            break;

        case KEYSOFTL:
            lastKeyID = 0;
            index = 0;
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                IMEtoneMark = 0;
                IMEfirstCandidate = 0;
                bSkipGetCandidate = ZI8TRUE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEelementCount = 0;
                bSkipGetCandidate = ZI8TRUE;
                IMEbFocusOnPhonetic = ZI8FALSE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                IMEelementBuffer[IMEelementCount] = 0;
                break;
            }
            /* IMEbPhoneticComfirmed = ZI8TRUE; */
            if (IMEfirstCandidate)
            {
                /* IMEfirstCandidate -= (ZI8UCHAR)(IMEmaxCols / 2); */
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEelementCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                break;
            }

            if (IMEbPhoneticComfirmed)
            {
                bSkipGetCandidate = ZI8TRUE;
                if ((IMEtoneMark >= ZI8_CODE_TONES_1) && (IMEtoneMark <= ZI8_CODE_TONES_5))
                {
                    IMEtoneMark = 0;
                    break;
                }
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEbFocusOnPhonetic = ZI8TRUE;
                IMEwordCharacterCount = 0;
                IMEelementCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                break;
            }

            if (IMEelementCount)
            {
                if (--IMEelementCount == 0)
                {
                    bSkipGetCandidate = ZI8TRUE;
                    IMEbFocusOnPhonetic = ZI8FALSE;
                    IMEbValidPhonetic = ZI8FALSE;
                    IMEbValidCandidates = ZI8FALSE;
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEwordCharacterCount = 0;
                    IMEprediction = 0;
                    IMEinline[0] = 0;

                }
                IMEelementBuffer[IMEelementCount] = 0;

                break;
            }
            if (IMEwordCharacterCount > 1)
            {
                Zi8AddUsedWordW_ZH(IMEuwd_ZHID, IMEwordBuffer, IMEwordCharacterCount);
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEbValidCandidates = ZI8FALSE;
            IMEwordCharacterCount = 0;
            IMEprediction = 0;
            IMEinline[0] = 0;

            break;

        case KEYSOFTR:
            lastKeyID = 0;
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandidateBuffer[IMEcandIndex] >= '0') && (IMEcandidateBuffer[IMEcandIndex] <= '9'))
            {
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
                break;
            }
            if (IMEbFocusOnPhonetic)
            {
                i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEelementBuffer, 0);
                IMEprediction = i - 1;
                IMEbFocusOnPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8TRUE;
                /* bSkipGetZHCandidate   = ZI8TRUE; */
                bSkipGetZHCandidate = ZI8FALSE;
                /* IMEbValidPhonetic = ZI8FALSE; */
                IMEtoneMark = 0;

            }
            else
            {

                if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                {
                    if (IMEwordCharacterCount > 1)
                    {
                        Zi8AddUsedWordW_ZH(IMEuwd_ZHID, IMEwordBuffer, IMEwordCharacterCount);
                    }
                    IMEwordCharacterCount = 0;
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
            #endif /* 0 */ 
                {
                    IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
                    IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
                }
                IMEwordBuffer[IMEwordCharacterCount] = 0;
                if (IMEwordCharacterCount > 1)
                {
                    bCheckRefWord = ZI8TRUE;
                }

                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEfirstCandidate = 0;

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
        #endif /* 0 */ 
            IMEprediction = 0;
            bSkipGetCandidate = ZI8TRUE;
            IMEbValidPhonetic = ZI8FALSE;
            IMEelementCount = 0;

            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEYSTAR:
        case KEY0:
            if (IMEbPhoneticComfirmed)
            {
                switch (keyID)
                {
                    case KEY1:
                        IMEtoneMark = ZI8_CODE_TONES_1;
                        break;
                    case KEY2:
                        IMEtoneMark = ZI8_CODE_TONES_2;
                        break;
                    case KEY3:
                        IMEtoneMark = ZI8_CODE_TONES_3;
                        break;
                    case KEY4:
                        IMEtoneMark = ZI8_CODE_TONES_4;
                        break;
                    case KEY5:
                        IMEtoneMark = ZI8_CODE_TONES_5;
                        break;
                    default:
                        goto IME_EXIT;
                }
                IMEfirstCandidate = 0;
                break;
            }

            if (lastKeyID == keyID)
            {
                IMEelementCount--;
                if (index >= MAX_SYM_PER_KEY)
                {
                    index = 0;
                }
            }
            else
            {
                index = 0;
            }
            StopMyTimer(ZI_REQ_TIMER);
            StartMyTimerInt(ZI_REQ_TIMER, ZI_MULTITAP_TIMER_DURATION, (oslTimerFuncPtr) ZiMultitapKeyTimeoutHandler, 0);

            lastKeyID = keyID;
            switch (keyID)
            {
                case KEY1:
                    i = 0;
                    break;
                case KEY2:
                    i = 1;
                    break;
                case KEY3:
                    i = 2;
                    break;
                case KEY4:
                    i = 3;
                    break;
                case KEY5:
                    i = 4;
                    break;
                case KEY6:
                    i = 5;
                    break;
                case KEY7:
                    i = 6;
                    break;
                case KEY8:
                    i = 7;
                    break;
                case KEY9:
                    i = 8;
                    break;
                case KEY0:
                    i = 9;
                    break;
                case KEYSTAR:
                    i = 10;
                    break;
            }
            if (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN)
            {
                if (keyID == KEY0 || keyID == KEY1)
                {
                    goto IME_EXIT;
                }
                else
                {
                    pLayout = (PZI8WCHAR) IMElayoutPY[i];
                }
            }
            else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_BOPOMOFO)
            {
                pLayout = (PZI8WCHAR) IMElayoutZY[i];
            }
            //else {
            //    pLayout = (PZI8WCHAR)IMElayoutCJ[i];
            //}
            if (!pLayout[index])
            {
                index = 0;
            }
            IMEelementBuffer[IMEelementCount++] = pLayout[index++];
            IMEelementBuffer[IMEelementCount] = 0;
            IMEfirstCandidate = 0;
            IMEbPhoneticComfirmed = ZI8FALSE;
            IMEbFocusOnPhonetic = ZI8TRUE;
            IMEbValidPhonetic = ZI8TRUE;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetZHCandidate)
    {

        if (IMEbPhoneticComfirmed || IMEelementCount)
        {
            IMEzi8GetParam.ElementCount = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEelementBuffer, 0) - 1;

            if (IMEbPhoneticComfirmed && IMEtoneMark)
            {
                IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                IMEinline[IMEzi8GetParam.ElementCount] = 0;
            }
        }
        else
        {
            IMEzi8GetParam.ElementCount = 0;
        }

        if (IMEzi8GetParam.ElementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEzi8GetParam.ElementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }
        /* IMEzi8GetParam.ElementCount = IMEelementCount; */
        IMEzi8GetParam.pElements = IMEinline;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        #ifdef __MMI_ZI_USING_PSCRATCH_BUFFER__
        memset(IMEScratchBuffer, 0, sizeof(IMEScratchBuffer));
        IMEzi8GetParam.pScratch = IMEScratchBuffer;
        #endif /* __MMI_ZI_USING_PSCRATCH_BUFFER__ */ 

        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        if (bCheckRefWord && IMEcandCount && !IMEzi8GetParam.wordCandidates)
        {
            Zi8AddUsedWordW_ZH(IMEuwd_ZHID, IMEwordBuffer, IMEwordCharacterCount);
            IMEwordCharacterCount = 0;
        }
        if (!IMEcandCount)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
                IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
                ziNoDrawCandidateRightArrowSymbol = ZI8TRUE;
            }
            else if (IMEbPhoneticComfirmed && IMEtoneMark)
            {
                --IMEzi8GetParam.ElementCount;
                IMEtoneMark = lastIMEtoneMark;
                if (IMEtoneMark)
                {
                    IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                    IMEinline[IMEzi8GetParam.ElementCount] = 0;
                }
                IMEfirstCandidate = lastFirstCandidate;
                IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
                IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);

            }
            else if (IMEzi8GetParam.ElementCount && pLayout)
            {
                for (i = 0; (i < MAX_SYM_PER_KEY) && !IMEcandCount; i++)
                {
                    if (index >= MAX_SYM_PER_KEY)
                    {
                        index = 0;
                    }
                    IMEelementBuffer[IMEelementCount - 1] = pLayout[index];
                    IMEinline[IMEelementCount - 1] = pLayout[index];
                    index++;
                    if (IMEinline[IMEelementCount - 1])
                    {
                        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
                    }
                }
            }
        }

        if (!IMEcandCount && IMEzi8GetParam.ElementCount)
        {
            IMEfirstCandidate = lastFirstCandidate;
            IMEelementCount = --IMEzi8GetParam.ElementCount;
            IMEelementBuffer[IMEelementCount] = 0;
            IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
            //IMEbPhoneticComfirmed = ZI8TRUE;
            //IMEbValidPhonetic = ZI8FALSE;
            lastKeyID = preKeyID;

        }

        if (!IMEcandCount)
        {
            IMEbValidCandidates = ZI8FALSE;
        }
        else
        {
            IMEbValidCandidates = ZI8TRUE;
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            if (ziNoDrawCandidateRightArrowSymbol)
            {
                IMEcandIndex = IMEcandCount - 1;
            }
            if (bBackSapce)
            {
                IMEcandIndex = IMEcandCount - 1;
            }
            if (IMEbFocusOnPhonetic)
            {
                IMEcandIndex = 0xFF;
            }

        }
        IMEprediction = IMEelementCount;

        if (IMEfirstCandidate)
        {
            IMEinline[IMEzi8GetParam.ElementCount++] = ZI8_CODE_MORE;
        }
        IMEinline[IMEzi8GetParam.ElementCount] = 0;

    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    if (IMEbValidCandidates)
    {
        for (i = 0; i < IMEelementCount; i++)
        {
            {
                IMEpPhoneticPtr[0][i] = IMEelementBuffer[i];
            }
        }
        if (IMEfirstCandidate)
        {
            IMEpPhoneticPtr[0][i] = ZI8_CODE_MORE;
            i++;
        }
        IMEpPhoneticPtr[0][i] = 0;
    }

    if (IMEbValidCandidates)
    {
        labelSoftR[0] = 'S';
        if (!IMEfirstCandidate && !IMEelementCount)
        {
            labelSoftL[0] = 'S';
        }
        else
        {
            labelSoftL[0] = 'C';
        }
    }

    rtnCode = IME_CONTINUE;

#if 0
/* under construction !*/
#endif /* 0 */ 
    //if( IMEbFocusOnPhonetic )
    //{
    //    IMEcandIndex = 0xFF;
    //}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }
    return (rtnCode);

}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKey1N2Phonetic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKey1N2Phonetic(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8BOOL bSkipGetZHCandidate = ZI8FALSE;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8WCHAR lastIMEtoneMark = IMEtoneMark;
    ZI8BOOL bNotAllow = ZI8FALSE;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Terry for eZi Max Length Check */
    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
        case KEYSOFTR:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                IMEfirstCandidate = 0;
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetCandidate = ZI8TRUE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEbValidPhonetic = ZI8FALSE;
                IMEbPhoneticComfirmed = ZI8FALSE;
                IMEwordCharacterCount = 0;
                IMEprediction = 0;
                IMEinline[0] = 0;
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEbPhoneticComfirmed && (!IMEbValidCandidates || (!IMEfirstCandidate && !IMEelementCount)))
        {
            if ((keyID == KEYSTAR))
            {
                /* IMElastProcessKeyFunc = IMEprocessKey1N2Phonetic; */
                rtnCode = IME_CONTINUE;
                goto IME_EXIT;
            }
        }
        if (IMEbValidCandidates)
        {
            i = 0;
            switch (keyID)
            {
                case KEY0:
                    i++;    /* NO BREAK */
                case KEY9:
                    i++;    /* NO BREAK */
                case KEY8:
                    i++;    /* NO BREAK */
                case KEY7:
                    i++;    /* NO BREAK */
                case KEY6:
                    i++;    /* NO BREAK */
                case KEY5:
                    i++;    /* NO BREAK */
                case KEY4:
                    i++;    /* NO BREAK */
                case KEY3:
                    i++;    /* NO BREAK */
                case KEY2:
                    i++;    /* NO BREAK */
                case KEY1:
                    if (IMEcandCount >= ++i)
                    {
                        IMEcandIndex = i - 1;
                        keyID = KEYSOFTR;
                        break;
                    }
                    goto IME_EXIT;
            }
        }
        else if (!IMEbValidCandidates)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandIndex = 0;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
            }
        }
    }
    switch (keyID)
    {

        case KEYLEFT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandIndex == 0) || bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                    break;
                }
                if (IMEcandIndex)
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = 0;
                    break;
                }
                goto IME_EXIT;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEcandIndex--;
            break;

        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            goto IME_EXIT;

        case KEYSTAR:
            if (!IMEbValidCandidates || IMEbPhoneticComfirmed)
            {
                goto IME_EXIT;
            }
            if (!bLongPress && IMEbValidPhonetic)
            {
                if (IMEphoneticCount <= 1)
                {
                    goto IME_EXIT;
                }
                IMEfirstCandidate = 0;
                if (++IMEphoneticIndex >= IMEphoneticCount)
                {
                    IMEphoneticIndex = 0;
                }
            }
            else
            {
                IMEprediction = Zi8CopyWordListW(
                                    IMEinline,
                                    MAX_ELEMENT_BUFFERSIZE,
                                    IMEpPhoneticPtr[IMEphoneticIndex],
                                    0) - 1;
                if ((IMEinline[IMEprediction - 1] >= ZI8_CODE_TONES_1) &&
                    (IMEinline[IMEprediction - 1] <= ZI8_CODE_TONES_5))
                {
                    IMEtoneMark = IMEinline[IMEprediction - 1];
                    IMEinline[IMEprediction - 1] = 0;
                }
                else
                {
                    IMEtoneMark = 0;
                }
                IMEelementBuffer[IMEelementCount] = 0;
                IMEelementCount = 0;
                IMEfirstCandidate = 0;
                IMEbPhoneticComfirmed = ZI8TRUE;
            }
            break;

        case KEYRIGHT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
            {
                if (IMEcandCount == (IMEmaxCols / 2))
                {
                    IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = IMEcandCount - 1;
                }
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
            }
            break;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEcandCount == (IMEmaxCols / 2))
            {
                IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
                IMEcandIndex = IMEcandCount - 1;
            }
            break;

        case KEYSOFTL:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate = 0;
                    break;
                }
                if (IMEbPhoneticComfirmed)
                {
                    IMEbPhoneticComfirmed = ZI8FALSE;
                    IMEinline[0] = 0;
                    IMEprediction = 0;
                    break;
                }
                IMEphoneticIndex = 0;
                if (IMEelementCount)
                {
                    IMEelementCount = 0;
                    break;
                }
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                break;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            if (IMEbPhoneticComfirmed)
            {
                if ((IMEtoneMark >= ZI8_CODE_TONES_1) && (IMEtoneMark <= ZI8_CODE_TONES_5))
                {
                    IMEtoneMark = 0;
                    break;
                }
                for (IMEelementCount = 0; IMEelementBuffer[IMEelementCount]; IMEelementCount++);
                IMEprediction = IMEelementCount;
                IMEbPhoneticComfirmed = ZI8FALSE;
                break;
            }
            IMEphoneticIndex = 0;
            if (IMEelementCount)
            {
                IMEelementBuffer[--IMEelementCount] = 0;
                break;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEbValidCandidates = ZI8FALSE;
            IMEwordCharacterCount = 0;
            IMEprediction = 0;
            IMEinline[0] = 0;
            break;

        case KEYSOFTR:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandidateBuffer[IMEcandIndex] >= '0') && (IMEcandidateBuffer[IMEcandIndex] <= '9'))
            {
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]);
                break;
            }
            if (IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]))
            {
                if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                {
                    IMEwordCharacterCount = 0;
                }
                IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
            }
            IMEbPhoneticComfirmed = ZI8FALSE;
            IMEfirstCandidate = 0;
            IMEelementCount = 0;
            IMEphoneticIndex = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (IMEbPhoneticComfirmed)
            {
                switch (keyID)
                {
                    case KEY1:
                        IMEtoneMark = ZI8_CODE_TONES_1;
                        break;
                    case KEY2:
                        IMEtoneMark = ZI8_CODE_TONES_2;
                        break;
                    case KEY3:
                        IMEtoneMark = ZI8_CODE_TONES_3;
                        break;
                    case KEY4:
                        IMEtoneMark = ZI8_CODE_TONES_4;
                        break;
                    case KEY5:
                        IMEtoneMark = ZI8_CODE_TONES_5;
                        break;
                    default:
                        goto IME_EXIT;
                }
                IMEfirstCandidate = 0;
                break;
            }
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
                case KEY0:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
                    break;
            }
            IMEelementBuffer[IMEelementCount] = 0;
            IMEfirstCandidate = 0;
            IMEphoneticIndex = 0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;
        default:
            goto IME_EXIT;
    }

    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
    if (!bSkipGetZHCandidate)
    {
        if (IMEbPhoneticComfirmed || IMEphoneticIndex)
        {
            i = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEpPhoneticPtr[IMEphoneticIndex], 0) - 1;
            if ((IMEinline[i - 1] >= ZI8_CODE_TONES_1) && (IMEinline[i - 1] <= ZI8_CODE_TONES_5))
            {
                IMEinline[--i] = 0;
            }
            IMEzi8GetParam.ElementCount = i;
            if (IMEtoneMark)
            {
                IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                IMEinline[IMEzi8GetParam.ElementCount] = 0;
            }
            IMEzi8GetParam.pElements = IMEinline;
            if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_BOPOMOFO)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
            }
            else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_PINYIN)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
            }
        }
        else
        {
            if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
            {
                IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
            }
            IMEzi8GetParam.ElementCount = IMEelementCount;
            IMEzi8GetParam.pElements = IMEelementBuffer;
            if (IMEzi8GetParam.GetMode == ZI8_GETMODE_BOPOMOFO)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_BOPOMOFO;
            }
            else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN)
            {
                IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_PINYIN;
            }
        }
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        #ifdef __MMI_ZI_USING_PSCRATCH_BUFFER__
        memset(IMEScratchBuffer, 0, sizeof(IMEScratchBuffer));
        IMEzi8GetParam.pScratch = IMEScratchBuffer;
        #endif /* __MMI_ZI_USING_PSCRATCH_BUFFER__ */ 

        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        if (!IMEcandCount)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else if (IMEzi8GetParam.ElementCount)
            {
                --IMEzi8GetParam.ElementCount;
                if (IMEtoneMark)
                {
                    IMEtoneMark = lastIMEtoneMark;
                }
                if (IMEtoneMark)
                {
                    IMEinline[IMEzi8GetParam.ElementCount++] = IMEtoneMark;
                    IMEinline[IMEzi8GetParam.ElementCount] = 0;
                }
                else if (!IMEbPhoneticComfirmed)
                {
                    IMEelementCount--;
                }
                IMEfirstCandidate = lastFirstCandidate;
            }
            IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
            IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        }
        if (!IMEcandCount ||
            (bNotAllow && (!IMEfirstCandidate && !IMEbPhoneticComfirmed &&
                           !IMEelementCount && !IMEzi8GetParam.wordCandidates)))
        {
            IMEbValidCandidates = ZI8FALSE;
        }
        else
        {
            IMEbValidCandidates = ZI8TRUE;
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
        }
        if (IMEfirstCandidate)
        {
            IMEinline[IMEzi8GetParam.ElementCount++] = ZI8_CODE_MORE;
        }
        IMEinline[IMEzi8GetParam.ElementCount] = 0;

        if (!IMEbPhoneticComfirmed)
        {
            IMEprediction = IMEelementCount;
        }
        else
        {
            IMEprediction = IMEzi8GetParam.ElementCount;
        }
    }
    if (IMEbValidCandidates && !IMEbPhoneticComfirmed)
    {
        int j, k, l;

        j = Zi8GetCharInfo2(
                IMEcandidateBuffer[IMEcandIndex],
                IMEpPhoneticPtr[0],
                8,
                IMEzi8GetParam.GetMode,
                IMEelementBuffer,
                IMEelementCount);
        if ((IMEpPhoneticPtr[0][j - 1] >= ZI8_CODE_TONES_1) && (IMEpPhoneticPtr[0][j - 1] <= ZI8_CODE_TONES_5))
        {
            if (IMEprediction < j--)
            {
                IMEpPhoneticPtr[0][j] = 0;
            }
        }
        if (!bSkipGetZHCandidate && !IMEphoneticIndex)
        {
            IMEzi8GetParam.pCandidates = IMEphoneticBuffer;
            IMEzi8GetParam.MaxCandidates = MAX_PHONETIC_CANDSIZE - 1;
            IMEzi8GetParam.GetOptions = ZI8_GETOPTION_GET_SPELLING;

            IMEphoneticCount = Zi8GetCandidates(&IMEzi8GetParam);
            if (IMEphoneticCount > 1)
            {
                IMEbValidPhonetic = ZI8TRUE;
                for (i = 0, l = 1; i < IMEphoneticCount; i++)
                {
                    k = Zi8CopyWordListW(IMEpPhoneticPtr[l], 8, IMEphoneticBuffer, (ZI8UCHAR) i) - 1;
                    if (j != k)
                    {
                        l++;
                        continue;
                    }
                    for (j = 0; j < k; j++)
                    {
                        if (IMEpPhoneticPtr[0][j] != IMEpPhoneticPtr[l][j])
                        {
                            break;
                        }
                    }
                    if (j != k)
                    {
                        l++;
                    }
                }
                IMEphoneticCount = l;
            }
            else
            {
                IMEphoneticCount = 1;
            }

            IMEzi8GetParam.pCandidates = IMEcandidateBuffer;
            IMEzi8GetParam.MaxCandidates = (ZI8UCHAR) (IMEmaxCols / 2);
            IMEzi8GetParam.GetOptions = ZI8_GETOPTION_DEFAULT;
        }
    }
    IMEphoneticBase = IMEphoneticIndex;
    if (IMEbValidCandidates && IMEelementCount)
    {
        IMEbValidPhonetic = ZI8TRUE;
    }
    else
    {
        IMEbValidPhonetic = ZI8FALSE;
    }

    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_ABC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_ABC(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    int count;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;

#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    //                IMElastProcessKeyFunc = IMEprocessKeyEZI_ABC;
                    //IMEstartSYM();
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            /* MTK Terry to set Cursor at the beginning of the word */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
                for (; ziEngWordLen > 0; ziEngWordLen--)
                {
                #ifndef MMI_LOW_MEMORY_PHONE
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
                    {
                        gui_EMS_input_box_previous(&MMI_EMS_inputbox);
                    }
                    else
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
                    {
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                    {
                        gui_single_line_input_box_previous(&MMI_singleline_inputbox);
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
                    {
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    }
                }
            }

            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
            /* PMT DARA ....added to make selection of words a cyclic process ...using UP & DOWN key */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEfirstCandidate)
            {
                IMEfirstCandidate = IMEcandCount;
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
                {
                    gui_EMS_input_box_delete_all(&MMI_EMS_inputbox);
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
                {
                    gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                    inline_full_screen_edit_changed = 1;
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
                {
                    gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                    inline_full_screen_edit_changed = 1;
                }
                IMEcurPos = 0;
                IMEnumOfChars = 0;
                IMEelementCount = 0;
                IMEinline[0] = 0;
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEYSTAR:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEYSTAR:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_PUNCT;
                    break;
                case KEY1:
                    /* MTK Terry for Key 1 behavior in smart abc */
                    /* IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY1;  break; */
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_PUNCT;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_CODE_LATIN_KEY9;
                    break;
            }
            break;

        case KEY0:
            /* MTK Terry for Key 0 behavior */
            // #if 0
            if (!IMEinline[0])
            {
                IMEinsertChar(0x0020);
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            // #endif
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            IMEinsertChar(0x0020);
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                if ((IMEelementBuffer[--IMEelementCount] == ZI8_CODE_LATIN_PUNCT) && !IMEcandidateBuffer[IMEprediction])
                {
                    IMEinsertText(IMEcandidateBuffer);
                    IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                    IMEelementCount = 1;
                    goto RETRY_GETCANDIDATE;
                }
                if (IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT)
                {
                    IMEinsertChar(0x002D);
                    for (i = 0; i < IMEelementCount; i++)
                    {
                        IMEelementBuffer[i] = IMEelementBuffer[i + 1];
                    }
                    goto RETRY_GETCANDIDATE;
                }
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEcandCount = 0;
        }
        else
        {
            IMEcandCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            if (IMEcandCount > MAX_COUNT_CANDIDATES)
            {
                IMEcandCount = MAX_COUNT_CANDIDATES;
            }
        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        IMEtoCapMode(IMEinline);
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_THAI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_THAI(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    int count;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;

#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_THAI; */
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            /* MTK Terry to set Cursor at the beginning of the word */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
                for (; ziEngWordLen > 0; ziEngWordLen--)
                {
                #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
                    {
                        gui_EMS_input_box_previous(&MMI_EMS_inputbox);
                    }
                    else
                #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
                    {
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                    {
                        gui_single_line_input_box_previous(&MMI_singleline_inputbox);
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
                    {
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                    }
                }
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
			/* pmt00061/280906/smart-thai-press key 2 or 3 */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEfirstCandidate)
            {
                IMEfirstCandidate = IMEalphaCount;
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
          /* pmt00061/280906/smart-thai-press key 2 or 3 */
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
            }
            break;

        case KEY0:
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            /* IMEinsertChar( 0x0020 ); */
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                /*
                 * if( (IMEelementBuffer[--IMEelementCount] ==
                 * ZI8_CODE_LATIN_PUNCT) &&
                 * !IMEcandidateBuffer[IMEprediction] )
                 * {
                 * IMEinsertText( IMEcandidateBuffer );
                 * IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                 * IMEelementCount = 1;
                 * goto RETRY_GETCANDIDATE;
                 * }
                 * if( IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT )
                 * {
                 * IMEinsertChar( 0x002D );
                 * for( i = 0; i < IMEelementCount; i++ )
                 * {
                 * IMEelementBuffer[i] = IMEelementBuffer[i+1];
                 * }
                 * goto RETRY_GETCANDIDATE;
                 * }
                 */
                --IMEelementCount;
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEalphaCount = 0;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8FALSE; */
        }
        else
        {
            IMEalphaCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8TRUE; */
            if (IMEalphaCount > MAX_COUNT_CANDIDATES)
            {
                IMEalphaCount = MAX_COUNT_CANDIDATES;
            }

            for (i = 0; i < IMEalphaCount; i++)
            {
                Zi8CopyW(IMEpPhoneticPtr[i], &IMEzi8GetParam, (ZI8UCHAR) i);
                /* Zi8CopyWordListW(IMEpPhoneticPtr[i], 8, IMEphoneticBuffer, i); */
            }

        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        /* IMEtoCapMode( IMEinline ); */
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}

#ifdef __MMI_ZI_ARABIC__        /* can be remove while checking Arabic into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_ARABIC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_ARABIC(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;

    /* ZI8LONG             lastCandCount      = IMEalphaCount; */
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8LONG count;
    ZI8LONG i /* , nLen=0 */ ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;

#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_ARABIC; */
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
            }
            break;

        case KEY0:
            if (!IMEinline[0])
            {
                IMEinsertChar(0x0020);
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            IMEinsertChar(0x0020);
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                if ((IMEelementBuffer[--IMEelementCount] == ZI8_CODE_LATIN_PUNCT) && !IMEcandidateBuffer[IMEprediction])
                {
                    IMEinsertText(IMEcandidateBuffer);
                    IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                    IMEelementCount = 1;
                    goto RETRY_GETCANDIDATE;
                }
                if (IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT)
                {
                    IMEinsertChar(0x002D);
                    for (i = 0; i < IMEelementCount; i++)
                    {
                        IMEelementBuffer[i] = IMEelementBuffer[i + 1];
                    }
                    goto RETRY_GETCANDIDATE;
                }
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEalphaCount = 0;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8FALSE; */
        }
        else
        {
            IMEalphaCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8TRUE; */
            if (IMEalphaCount > MAX_COUNT_CANDIDATES)
            {
                IMEalphaCount = MAX_COUNT_CANDIDATES;
            }

            for (i = 0; i < IMEalphaCount; i++)
            {
                /* Big bug here. Max number of IMEpPhoneticPtr is 5, but IMEalphaCount may be bigger than 5. */
                Zi8CopyW(IMEpPhoneticPtr[i], &IMEzi8GetParam, (unsigned char)i);
                //nLen = UCS2Strlen((const char *)IMEpPhoneticPtr[i]);
                //ArabicStringShape((unsigned short *)&nLen, IMEpPhoneticPtr[i]);             //output will replace the input string after returning
            }

        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        /* IMEtoCapMode( IMEinline ); */
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}
#endif /* __MMI_ZI_ARABIC__ */ 


#ifdef __MMI_ZI_PERSIAN__       /* can be remove while checking PERSIAN into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_PERSIAN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_PERSIAN(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;

    /* ZI8LONG             lastCandCount      = IMEalphaCount; */
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8LONG count;
    ZI8LONG i /* , nLen=0 */ ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;

#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_PERSIAN; */
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
            }
            break;

        case KEY0:
            if (!IMEinline[0])
            {
                IMEinsertChar(0x0020);
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            IMEinsertChar(0x0020);
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                if ((IMEelementBuffer[--IMEelementCount] == ZI8_CODE_LATIN_PUNCT) && !IMEcandidateBuffer[IMEprediction])
                {
                    IMEinsertText(IMEcandidateBuffer);
                    IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                    IMEelementCount = 1;
                    goto RETRY_GETCANDIDATE;
                }
                if (IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT)
                {
                    IMEinsertChar(0x002D);
                    for (i = 0; i < IMEelementCount; i++)
                    {
                        IMEelementBuffer[i] = IMEelementBuffer[i + 1];
                    }
                    goto RETRY_GETCANDIDATE;
                }
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEalphaCount = 0;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8FALSE; */
        }
        else
        {
            IMEalphaCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8TRUE; */
            if (IMEalphaCount > MAX_COUNT_CANDIDATES)
            {
                IMEalphaCount = MAX_COUNT_CANDIDATES;
            }

            for (i = 0; i < IMEalphaCount; i++)
            {
                /* Big bug here. Max number of IMEpPhoneticPtr is 5, but IMEalphaCount may be bigger than 5. */
                Zi8CopyW(IMEpPhoneticPtr[i], &IMEzi8GetParam, (unsigned char)i);
                //nLen = UCS2Strlen((const char *)IMEpPhoneticPtr[i]);
                //ArabicStringShape((unsigned short *)&nLen, IMEpPhoneticPtr[i]);             //output will replace the input string after returning
            }

        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        /* IMEtoCapMode( IMEinline ); */
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}
#endif /* __MMI_ZI_PERSIAN__ */ 



#if defined(__MMI_ZI_HINDI__)


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_HINDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_HINDI(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;

    /* ZI8LONG             lastCandCount      = IMEalphaCount; */
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8LONG count;
    ZI8LONG i /* , nLen=0 */ ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;
//PMT START MAUI_00223197
	#ifdef  __MMI_ZI_HINDI__
	hindi_keyId = keyID;
	#endif
//PMT END MAUI_00223197
#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_ARABIC; */
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if(ziInputMethodCategoryFlag &ZI_IN_CATEGORY_28_FLAG)
                {
                    gui_EMS_input_box_delete_all(&MMI_EMS_inputbox);
                }
                else 
#endif
                if(ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
                {
                    gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                    inline_full_screen_edit_changed = 1;
                }
                else if(ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
                }
                else if(ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
                {
                   gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                   inline_full_screen_edit_changed = 1;
                }
                IMEcurPos = 0;
                IMEnumOfChars = 0;
                IMEelementCount = 0;
                IMEinline[0]      = 0;
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
            }
            break;

        case KEY0:
            if (!IMEinline[0])
            {
                IMEinsertChar(0x0020);
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            IMEinsertChar(0x0020);
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                if ((IMEelementBuffer[--IMEelementCount] == ZI8_CODE_LATIN_PUNCT) && !IMEcandidateBuffer[IMEprediction])
                {
                    IMEinsertText(IMEcandidateBuffer);
                    IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                    IMEelementCount = 1;
                    goto RETRY_GETCANDIDATE;
                }
                if (IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT)
                {
                    IMEinsertChar(0x002D);
                    for (i = 0; i < IMEelementCount; i++)
                    {
                        IMEelementBuffer[i] = IMEelementBuffer[i + 1];
                    }
                    goto RETRY_GETCANDIDATE;
                }
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEalphaCount = 0;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8FALSE; */
        }
        else
        {
            IMEalphaCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8TRUE; */
            if (IMEalphaCount > MAX_COUNT_CANDIDATES)
            {
                IMEalphaCount = MAX_COUNT_CANDIDATES;
            }

            for (i = 0; i < IMEalphaCount; i++)
            {
                /* Big bug here. Max number of IMEpPhoneticPtr is 5, but IMEalphaCount may be bigger than 5. */
                Zi8CopyW(IMEpPhoneticPtr[i], &IMEzi8GetParam, (unsigned char)i);
                //nLen = UCS2Strlen((const char *)IMEpPhoneticPtr[i]);
                //ArabicStringShape((unsigned short *)&nLen, IMEpPhoneticPtr[i]);             //output will replace the input string after returning
            }

        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        /* IMEtoCapMode( IMEinline ); */
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}
#endif /* defined(__MMI_ZI_HINDI__) */ 

#ifdef __MMI_ZI_HEBREW__


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyEZI_HEBREW
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyEZI_HEBREW(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;

    /* ZI8LONG             lastCandCount      = IMEalphaCount; */
    ZI8WCHAR lastFirstCandidate = IMEfirstCandidate;
    ZI8LONG count;
    ZI8LONG i /* , nLen=0 */ ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bSkipGetCandidate = ZI8FALSE;
    ziCurrKeyId = keyID;

#if defined(__MTK_TARGET__)
    wcscpy((char*)IMEcandidateBuffer, (char*)IMEinline);
#else 
    wcscpy(IMEcandidateBuffer, IMEinline);
#endif 

    switch (keyID)
    {
        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
        case KEY0:
            if (ZiMaxLengthCheck() == ZI8FALSE)
            {
                UI_editor_play_tone_cannot_insert();
                goto IME_EXIT;
            }
            break;
        default:
            break;
    }

    if (bLongPress)
    {
        if (!IMEelementCount)
        {
            switch (keyID)
            {
                case KEY1:
                case KEY2:
                case KEY3:
                case KEY4:
                case KEY5:
                case KEY6:
                case KEY7:
                case KEY8:
                case KEY9:
                case KEY0:
                    IMEbValidCandidates = ZI8TRUE;
                    IMEcandidateBuffer[0] = keyID & 0x00FF;
                    keyID = KEYSOFTR;
                    break;
                case KEYSTAR:
                    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_ARABIC; */
                    rtnCode = IME_CONTINUE;
                    goto IME_EXIT;
            }
        }
    }
    switch (keyID)
    {
        case KEYLEFT:
            IMEprediction = IMEcurPos + IMEprediction;
            /* NO BREAK */
        case KEYRIGHT:
            /* IMEinsertText( IMEinline ); */
            if (keyID == KEYLEFT)
            {
                IMEcurPos = IMEprediction;
            }
            bSkipGetCandidate = ZI8TRUE;
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEYUP:
            if (!IMEinline[0] || !IMEfirstCandidate)
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate--;
            break;

        case KEYDOWN:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            IMEfirstCandidate++;
            break;

        case KEYSOFTL:
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                break;
            }
            if (IMEelementCount)
            {
                if (--IMEelementCount)
                {
                    break;
                }
                else
                {
                    IMEdeleteChar();
                }
            }
            IMEinline[0] = 0;
            bSkipGetCandidate = ZI8TRUE;
            break;

        case KEYSOFTR:
            if (IMEbValidCandidates)
            {
                IMEinsertChar(IMEcandidateBuffer[0]);
                bSkipGetCandidate = ZI8TRUE;
                IMEbValidCandidates = ZI8FALSE;
                IMEinline[0] = 0;
                break;
            }
            if (!IMEinline[0])
            {
                goto IME_EXIT;
            }
            if (!IMEinline[1] /* && iswpunct(IMEinline[0]) */ )
            {
                bSkipGetCandidate = ZI8TRUE;
            }
            IMEinline[0] = 0;
            IMEelementCount = 0;
            break;

        case KEY1:
        case KEY2:
        case KEY3:
        case KEY4:
        case KEY5:
        case KEY6:
        case KEY7:
        case KEY8:
        case KEY9:
            IMEfirstCandidate = 0;
            switch (keyID)
            {
                case KEY1:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY1;
                    break;
                case KEY2:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY2;
                    break;
                case KEY3:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY3;
                    break;
                case KEY4:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY4;
                    break;
                case KEY5:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY5;
                    break;
                case KEY6:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY6;
                    break;
                case KEY7:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY7;
                    break;
                case KEY8:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY8;
                    break;
                case KEY9:
                    IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY9;
                    break;
            }
            break;

        case KEY0:
            if (!IMEinline[0])
            {
                IMEinsertChar(0x0020);
                bSkipGetCandidate = ZI8TRUE;
                break;
            }
            IMEfirstCandidate = 0;
            IMEelementBuffer[IMEelementCount++] = ZI8_ONEKEY_KEY0;
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            goto IME_EXIT;
    }

    if (!bSkipGetCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }

      RETRY_GETCANDIDATE:
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = 0;

        count = Zi8GetCandidates(&IMEzi8GetParam);

        if (!count && IMEelementCount && (IMEelementBuffer[IMEelementCount - 1] == ZI8_ONEKEY_KEY0))
        {
            IMEinsertChar(0x0020);
        }
        else if (!count)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate = 0;
                goto RETRY_GETCANDIDATE;
            }
            if (IMEelementCount > 1)
            {
                if ((IMEelementBuffer[--IMEelementCount] == ZI8_CODE_LATIN_PUNCT) && !IMEcandidateBuffer[IMEprediction])
                {
                    IMEinsertText(IMEcandidateBuffer);
                    IMEelementBuffer[0] = ZI8_CODE_LATIN_PUNCT;
                    IMEelementCount = 1;
                    goto RETRY_GETCANDIDATE;
                }
                if (IMEelementBuffer[0] == ZI8_CODE_LATIN_PUNCT)
                {
                    IMEinsertChar(0x002D);
                    for (i = 0; i < IMEelementCount; i++)
                    {
                        IMEelementBuffer[i] = IMEelementBuffer[i + 1];
                    }
                    goto RETRY_GETCANDIDATE;
                }
                IMEfirstCandidate = lastFirstCandidate;
                goto RETRY_GETCANDIDATE;
            }
            IMEelementCount = 0;
        }
        if (!count)
        {
            IMEinline[0] = 0;
            IMEelementCount = 0;
            IMEalphaCount = 0;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8FALSE; */
        }
        else
        {
            IMEalphaCount = Zi8GetCandidatesCount(&IMEzi8GetParam) + IMEfirstCandidate;
            /* MTK Terry Temp Solution for Highlight in Candidate Area */
            /* IMEbValidAlphaWords = ZI8TRUE; */
            if (IMEalphaCount > MAX_COUNT_CANDIDATES)
            {
                IMEalphaCount = MAX_COUNT_CANDIDATES;
            }

            for (i = 0; i < IMEalphaCount; i++)
            {
                /* Big bug here. Max number of IMEpPhoneticPtr is 5, but IMEalphaCount may be bigger than 5. */
                Zi8CopyW(IMEpPhoneticPtr[i], &IMEzi8GetParam, (unsigned char)i);
                //nLen = UCS2Strlen((const char *)IMEpPhoneticPtr[i]);
                //ArabicStringShape((unsigned short *)&nLen, IMEpPhoneticPtr[i]);             //output will replace the input string after returning
            }

        }
        IMEprediction = IMEelementCount;
    }

    labelSoftR[0] = 0;

    if (IMEinline[0])
    {

        /* IMEtoCapMode( IMEinline ); */
        labelSoftL[0] = 'C';
        if (IMEinline[0] != 62)
        {
            labelSoftR[0] = 'S';
        }

    }
    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEinline[0])
    {
        IMEactive = ZI8TRUE;
    }
    lastKeyID = keyID;
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}
#endif /* __MMI_ZI_HEBREW__ */ 


/*****************************************************************************
 * FUNCTION
 *  IMEtranslateKeyID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID       [IN]        
 *  GetMode     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static ZI8WCHAR IMEtranslateKeyID(ZI8WCHAR keyID, ZI8UCHAR GetMode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetMode == ZI8_GETMODE_PINYIN)
    {
        if ((keyID >= 0x61) && (keyID <= 0x7a))
        {
            return (keyID - 0x61 + ZI8_CODE_PINYIN_A);
        }
        if ((keyID >= 0x31) && (keyID <= 0x35))
        {
            return (keyID - 0x31 + ZI8_CODE_TONES_1);
        }
        if (keyID == 0x27)
        {
            return (ZI8_CODE_PHONETIC_SEPARATOR);
        }
        return (0);
    }
    switch (keyID)
    {
        case '1':
            return (ZI8_CODE_BPMF_B);
        case 'q':
            return (ZI8_CODE_BPMF_P);
        case 'a':
            return (ZI8_CODE_BPMF_M);
        case 'z':
            return (ZI8_CODE_BPMF_F);
        case '2':
            return (ZI8_CODE_BPMF_D);
        case 'w':
            return (ZI8_CODE_BPMF_T);
        case 's':
            return (ZI8_CODE_BPMF_N);
        case 'x':
            return (ZI8_CODE_BPMF_L);
        case 'e':
            return (ZI8_CODE_BPMF_G);
        case 'd':
            return (ZI8_CODE_BPMF_K);
        case 'c':
            return (ZI8_CODE_BPMF_H);
        case 'r':
            return (ZI8_CODE_BPMF_J);
        case 'f':
            return (ZI8_CODE_BPMF_Q);
        case 'v':
            return (ZI8_CODE_BPMF_X);
        case '5':
            return (ZI8_CODE_BPMF_ZH);
        case 't':
            return (ZI8_CODE_BPMF_CH);
        case 'g':
            return (ZI8_CODE_BPMF_SH);
        case 'b':
            return (ZI8_CODE_BPMF_R);
        case 'y':
            return (ZI8_CODE_BPMF_Z);
        case 'h':
            return (ZI8_CODE_BPMF_C);
        case 'n':
            return (ZI8_CODE_BPMF_S);
        case '8':
            return (ZI8_CODE_BPMF_A);
        case 'i':
            return (ZI8_CODE_BPMF_O);
        case 'k':
            return (ZI8_CODE_BPMF_E);
        case ',':
            return (ZI8_CODE_BPMF_EH);
        case '9':
            return (ZI8_CODE_BPMF_AI);
        case 'o':
            return (ZI8_CODE_BPMF_EI);
        case 'l':
            return (ZI8_CODE_BPMF_AU);
        case '.':
            return (ZI8_CODE_BPMF_OU);
        case '0':
            return (ZI8_CODE_BPMF_AN);
        case 'p':
            return (ZI8_CODE_BPMF_EN);
        case ';':
            return (ZI8_CODE_BPMF_ANG);
        case '/':
            return (ZI8_CODE_BPMF_ENG);
        case '-':
            return (ZI8_CODE_BPMF_ER);
        case 'u':
            return (ZI8_CODE_BPMF_I);
        case 'j':
            return (ZI8_CODE_BPMF_U);
        case 'm':
            return (ZI8_CODE_BPMF_IU);

        case ' ':
            return (ZI8_CODE_TONES_1);
        case '6':
            return (ZI8_CODE_TONES_2);
        case '3':
            return (ZI8_CODE_TONES_3);
        case '4':
            return (ZI8_CODE_TONES_4);
        case '7':
            return (ZI8_CODE_TONES_5);
        default:
            break;
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKeyDirectPhonetic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static IME_RETURN_CODE IMEprocessKeyDirectPhonetic(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IME_RETURN_CODE rtnCode = IME_SKIP;
    ZI8BOOL bSkipGetZHCandidate = ZI8FALSE;
    ZI8BOOL bNotAllow = ZI8FALSE;
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (keyID)
    {

        case KEYLEFT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((IMEcandIndex == 0) || bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                    break;
                }
                if (IMEcandIndex)
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = 0;
                    break;
                }
                goto IME_EXIT;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEcandIndex--;
            break;

        case KEYRIGHT:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if ((++IMEcandIndex >= IMEcandCount) || bLongPress)
            {
                if (IMEcandCount == (IMEmaxCols / 2))
                {
                    IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
                }
                else
                {
                    bSkipGetZHCandidate = ZI8TRUE;
                    IMEcandIndex = IMEcandCount - 1;
                }
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
            }
            break;

        case KEYUP:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            goto IME_EXIT;

        case KEYDOWN:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEcandCount == (IMEmaxCols / 2))
            {
                IMEfirstCandidate += (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else
            {
                bSkipGetZHCandidate = ZI8TRUE;
                IMEcandIndex = IMEcandCount - 1;
            }
            break;

        case KEYSOFTL:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (bLongPress)
            {
                if (IMEfirstCandidate)
                {
                    IMEfirstCandidate = 0;
                    break;
                }
                if (IMEelementCount)
                {
                    IMEelementCount = 0;
                    break;
                }
                IMEbValidCandidates = ZI8FALSE;
                bSkipGetZHCandidate = ZI8TRUE;
                break;
            }
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
                break;
            }
            if (IMEelementCount)
            {
                IMEelementBuffer[--IMEelementCount] = 0;
                break;
            }
            bSkipGetZHCandidate = ZI8TRUE;
            IMEbValidCandidates = ZI8FALSE;
            IMEwordCharacterCount = 0;
            IMEprediction = 0;
            IMEinline[0] = 0;
            break;

        case KEYSOFTR:
            if (!IMEbValidCandidates)
            {
                goto IME_EXIT;
            }
            if (IMEinsertChar(IMEcandidateBuffer[IMEcandIndex]))
            {
                if (IMEzi8GetParam.wordCandidates <= CenterOutIndex(IMEcandIndex))
                {
                    IMEwordCharacterCount = 0;
                }
                IMEwordBuffer[IMEwordCharacterCount++] = IMEcandidateBuffer[IMEcandIndex];
            }
            IMEfirstCandidate = 0;
            if (IMEelementCount && (IMEzi8GetParam.GetMode == ZI8_GETMODE_PINYIN))
            {
                for (j = 0, i = IMEzi8GetParam.letters; i < IMEelementCount;)
                {
                    IMEelementBuffer[j++] = IMEelementBuffer[i++];
                }
                IMEelementCount = IMEelementCount - IMEzi8GetParam.letters;
            }
            else
            {
                IMEelementCount = 0;
            }
            break;

        case KEYDUMMY:
            IMEfirstCandidate = 0;
            break;

        default:
            i = IMEtranslateKeyID((ZI8WCHAR) keyID, IMEzi8GetParam.GetMode);
            if (i)
            {
                IMEelementBuffer[IMEelementCount++] = (ZI8WCHAR) i;
                IMEfirstCandidate = 0;
                break;
            }
            goto IME_EXIT;
    }

    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
    if (!bSkipGetZHCandidate)
    {
        if (IMEelementCount >= MAX_ELEMENT_BUFFERSIZE)
        {
            IMEelementCount = MAX_ELEMENT_BUFFERSIZE - 1;
        }
        IMEzi8GetParam.ElementCount = IMEelementCount;
        IMEzi8GetParam.pElements = IMEelementBuffer;
        IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
        IMEzi8GetParam.WordCharacterCount = IMEwordCharacterCount;
        IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        if (!IMEcandCount)
        {
            if (IMEfirstCandidate)
            {
                IMEfirstCandidate -= (ZI8UCHAR) (IMEmaxCols / 2);
            }
            else if (IMEzi8GetParam.ElementCount)
            {
                --IMEzi8GetParam.ElementCount;
                --IMEelementCount;
            }
            IMEzi8GetParam.FirstCandidate = IMEfirstCandidate;
            IMEcandCount = Zi8GetCandidates(&IMEzi8GetParam);
        }
        if (!IMEcandCount || (bNotAllow && (!IMEfirstCandidate && !IMEelementCount && !IMEzi8GetParam.wordCandidates)))
        {
            IMEbValidCandidates = ZI8FALSE;
        }
        else
        {
            IMEbValidCandidates = ZI8TRUE;
            /* PMT dara  Added 0n..3/12/04..to highlight the first member in candidate window when window is small */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (!CompositionWindowHideFlag || (!CharacterInsertedFlag))
            {
                IMEcandIndex = 0;
            }
            else
            {
                IMEcandIndex = CenterOutCandidates(IMEcandCount);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            IMEcandIndex = CenterOutCandidates(IMEcandCount);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
        }
        for (i = 0; i < IMEelementCount; i++)
        {
            IMEpPhoneticPtr[0][i] = IMEelementBuffer[i];
        }
        if (IMEfirstCandidate)
        {
            IMEpPhoneticPtr[0][i++] = ZI8_CODE_MORE;
        }
        IMEpPhoneticPtr[0][i] = 0;
        IMEprediction = i;
    }

    if (IMEbValidCandidates && IMEelementCount)
    {
        IMEbValidPhonetic = ZI8TRUE;
    }
    else
    {
        IMEbValidPhonetic = ZI8FALSE;
    }

    rtnCode = IME_CONTINUE;

  IME_EXIT:
    if (IMEbValidCandidates)
    {
        IMEactive = ZI8TRUE;
    }
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_STROKE
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_STROKE(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_STROKE;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.Language = ZI8_LANG_ZH;
    IMEzi8GetParam.GetMode = ZI8_GETMODE_STROKES;
    IMEzi8GetParam.SubLanguage = IMEsubLanguage;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_SMS;
    if (IMEtextType == IME_NAME_TEXT)
    {
        if (IMEcurPos)
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_GIVENNAME;
        }
        else
        {
            IMEzi8GetParam.Context = ZI8_GETCONTEXT_SURNAME;
        }
    }
    if (bNoRadicals)
    {
        IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    }
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCurrentWord = IMEwordBuffer;
    IMEzi8GetParam.pCandidates = IMEcandidateBuffer;
    IMEzi8GetParam.MaxCandidates = (ZI8UCHAR) (IMEmaxCols / 2);

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;

    IMEchangeSubLanguage(ZI8TRUE);
    /* MTK Terry for IME switching to disable word highlight */
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
        MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
    {
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_PHONETIC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  getMode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_PHONETIC(ZI8UCHAR getMode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));

    if (iStepID != PHONETIC_2_STEPS)
    {
        IMEphoneticIndex = 0;
        IMEphoneticBase = 0;
        IMEphoneticCount = 1;
        IMEzi8GetParam.pCandidates = IMEcandidateBuffer;
        IMEzi8GetParam.MaxCandidates = (ZI8UCHAR) (IMEmaxCols / 2);
        IMEzi8GetParam.GetOptions = ZI8_GETOPTION_DEFAULT;
        if (iStepID == PHONETIC_DIRECT)
        {
            IMEprocessKeyFunc = IMEprocessKeyDirectPhonetic;
        }
        else if (iStepID == PHONETIC_1_STEP)
        {
            IMEprocessKeyFunc = IMEprocessKey1Phonetic;
        }
        else if (iStepID == PHONETIC_MULTITAP)
        {
            IMEprocessKeyFunc = IMEprocessKeyMultitapPhonetic;
        }
        else
        {
            IMEprocessKeyFunc = IMEprocessKey1N2Phonetic;
        }
    }
    else
    {
        IMEzi8GetParam.GetOptions = ZI8_GETOPTION_GET_SPELLING;
        IMEprocessKeyFunc = IMEprocessKey2Phonetic;
    }
    IMEzi8GetParam.Language = ZI8_LANG_ZH;
    IMEzi8GetParam.GetMode = getMode;
    IMEzi8GetParam.SubLanguage = IMEsubLanguage;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_SMS | ZI8_GETCONTEXT_NO_DUPLICATE;
    IMEzi8GetParam.pCurrentWord = IMEwordBuffer;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;
    IMEtoneMark = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbPhoneticComfirmed = ZI8FALSE;
    IMEbFocusOnPhonetic = ZI8FALSE;

    IMEchangeSubLanguage(ZI8TRUE);
    /* MTK Terry for IME switching to disable word highlight */
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
        MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
    {
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_PINYIN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_PINYIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iStepID == PHONETIC_DIRECT)
    {
        IMEstartEZI_PHONETIC(ZI8_GETMODE_PINYIN);
    }
    else
    {
        IMEstartEZI_PHONETIC(ZI8_GETMODE_1KEYPRESS_PINYIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_BOPOMOFO
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_BOPOMOFO(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iStepID == PHONETIC_DIRECT)
    {
        IMEstartEZI_PHONETIC(ZI8_GETMODE_BOPOMOFO);
    }
    else
    {
        IMEstartEZI_PHONETIC(ZI8_GETMODE_1KEYPRESS_BOPOMOFO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_MULTITAP_PINYIN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_MULTITAP_PINYIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEstartEZI_PHONETIC(ZI8_GETMODE_PINYIN);
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_MULTITAP_BOPOMOFO
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_MULTITAP_BOPOMOFO(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEstartEZI_PHONETIC(ZI8_GETMODE_BOPOMOFO);
}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_ABC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_ABC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_ABC;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;
    switch (IMEalphaLangID)
    {
        case ALPHA_LANG_FR:
            IMEzi8GetParam.Language = ZI8_LANG_FR;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_RU:
            IMEzi8GetParam.Language = ZI8_LANG_RU;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_DE:
            IMEzi8GetParam.Language = ZI8_LANG_DE;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_IT:
            IMEzi8GetParam.Language = ZI8_LANG_IT;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_ES:
            IMEzi8GetParam.Language = ZI8_LANG_ES;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_PT:
            IMEzi8GetParam.Language = ZI8_LANG_PT;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_TR:
            IMEzi8GetParam.Language = ZI8_LANG_TR;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_ID:
            IMEzi8GetParam.Language = ZI8_LANG_IN;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_MS:
            IMEzi8GetParam.Language = ZI8_LANG_MS;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_VI:
            IMEzi8GetParam.Language = ZI8_LANG_VI;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_EN_FR:
            IMEzi8GetParam.Language = ZI8_LANG_EN;
            IMEzi8GetParam.SubLanguage = ZI8_LANG_FR;
            break;
        case ALPHA_LANG_FR_EN:
            IMEzi8GetParam.Language = ZI8_LANG_FR;
            IMEzi8GetParam.SubLanguage = ZI8_LANG_EN;
            break;
            /* PMT VIKAS GUPTA START PO_NO_ZI 20050930 */
        case ALPHA_LANG_PL:
            IMEzi8GetParam.Language = ZI8_LANG_PL;
            IMEzi8GetParam.SubLanguage = ZI8_LANG_EN;
            break;
        case ALPHA_LANG_NO:
            IMEzi8GetParam.Language = ZI8_LANG_NO;
            IMEzi8GetParam.SubLanguage = ZI8_LANG_EN;
            break;
            //PMT VIKAS GUPTA END PO_NO_ZI 20050930
            //PMT NO_AR_SL_DU START 20050909
        case ALPHA_LANG_SK:
            IMEzi8GetParam.Language = ZI8_LANG_SK;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_NL:
            IMEzi8GetParam.Language = ZI8_LANG_NL;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
            //PMT NO_AR_SL_DU END 20050909
            //PMT START SWEDISH 20050916
        case ALPHA_LANG_SV:
            IMEzi8GetParam.Language = ZI8_LANG_SV;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
            /* PMT END SWEDISH 20050916 */
        case ALPHA_LANG_HR:
            IMEzi8GetParam.Language = ZI8_LANG_HR;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_RO:
            IMEzi8GetParam.Language = ZI8_LANG_RO;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_SL:
            IMEzi8GetParam.Language = ZI8_LANG_SL;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_EL:
            IMEzi8GetParam.Language = ZI8_LANG_EL;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_CZ:
            IMEzi8GetParam.Language = ZI8_LANG_CS;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_FI:
            IMEzi8GetParam.Language = ZI8_LANG_FI;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_DA:
            IMEzi8GetParam.Language = ZI8_LANG_DA;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_HU:
            IMEzi8GetParam.Language = ZI8_LANG_HU;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
        case ALPHA_LANG_EN:
        default:
            IMEzi8GetParam.Language = ZI8_LANG_EN;
            IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;
            break;
    }

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;

    labelSoftR[0] = 0;

}


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_THAI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_THAI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_THAI;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;

    IMEzi8GetParam.Language = ZI8_LANG_TH;
    IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbValidAlphaWords = ZI8FALSE;
    labelSoftR[0] = 0;

}

#ifdef __MMI_ZI_ARABIC__        /* can be remove while checking Arabic into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_ARABIC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_ARABIC(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_ARABIC;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;

    IMEzi8GetParam.Language = ZI8_LANG_AR;
    IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbValidAlphaWords = ZI8FALSE;
    labelSoftR[0] = 0;

}
#endif /* __MMI_ZI_ARABIC__ */ 

#ifdef __MMI_ZI_PERSIAN__       /* can be remove while checking Arabic into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_PERSIAN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_PERSIAN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_PERSIAN;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;

    IMEzi8GetParam.Language = ZI8_LANG_FA;
    IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbValidAlphaWords = ZI8FALSE;
    labelSoftR[0] = 0;

}
#endif /* __MMI_ZI_PERSIAN__ */ 

#ifdef __MMI_ZI_HINDI__ /* can be remove while checking Arabic into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_HINDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_HINDI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_HINDI;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;

    IMEzi8GetParam.Language = ZI8_LANG_HI;
    IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbValidAlphaWords = ZI8FALSE;
    labelSoftR[0] = 0;

}
#endif /* __MMI_ZI_HINDI__ */ 
/* PMT VIKAS GUPTA END 20051129 */

/* PMT START GR_HE_CZ_FI_DA_HU 20051007 */
#ifdef __MMI_ZI_HEBREW__        /* can be remove while checking Arabic into GPRS branch */


/*****************************************************************************
 * FUNCTION
 *  IMEstartEZI_HEBREW
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IMEstartEZI_HEBREW(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKeyFunc = IMEprocessKeyEZI_HEBREW;

    memset(&IMEzi8GetParam, 0, sizeof(IMEzi8GetParam));
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    IMEzi8GetParam.Context = ZI8_GETCONTEXT_DEFAULT;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_WSTRINGS;
    IMEzi8GetParam.pCurrentWord = NULL;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = IMEinline;
    IMEzi8GetParam.MaxCandidates = 1;

    IMEzi8GetParam.Language = ZI8_LANG_IW;
    IMEzi8GetParam.SubLanguage = ZI8_SUBLANG_DEFAULT;

    IMEfirstCandidate = 0;
    IMEelementCount = 0;
    IMEwordCharacterCount = 0;
    IMEinline[0] = 0;

    IMEbValidCandidates = ZI8FALSE;
    IMEbValidPhonetic = ZI8FALSE;
    IMEbValidAlphaWords = ZI8FALSE;
    labelSoftR[0] = 0;

}
#endif /* __MMI_ZI_HEBREW__ */ 
/* PMT END GR_HE_CZ_FI_DA_HU 20051007 */


/*****************************************************************************
 * FUNCTION
 *  IMEstart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  numOfChars          [IN]        
 *  maxBufferSize       [IN]        
 *  textType            [IN]        
 *  language            [IN]        
 *  startX              [IN]        
 *  startY              [IN]        
 *  maxCols             [IN]        
 *  maxRows             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
IME_RETURN_CODE IMEstart(
                    /* PZI8WCHAR           pTextBuffer, */ int numOfChars,
                    int maxBufferSize,
                    IME_TEXT_TYPE textType,
                    SUPPORTED_LANGUAGES language,
                    int startX,
                    int startY,
                    int maxCols,
                    int maxRows)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEnumOfChars = numOfChars;
    IMEmaxBufferSize = maxBufferSize;
    //    IMEstartX               = startX;
    //    IMEstartY               = startY;
    IMEmaxCols = maxCols;
    /* IMEmaxRows              = maxRows; */
    IMEcurPos = numOfChars;
    IMEinline[0] = 0;
    IMEprediction = 0;
    IMEmethod = INPUT_EZI_STROKE;
    IMEactive = ZI8FALSE;
    /* IMEcaretOn              = ZI8FALSE; */
    IMElastLetterCase = IMEletterCase;
    IMElastSubLanguage = IMEsubLanguage;
    labelSoftR[0] = 0;
    IMEtextType = textType;
    IMEsearchPB = ZI8FALSE;

    if (IMEtextType == IME_SEARCH_PB_TEXT)
    {
        IMEtextType = IME_NAME_TEXT;
        IMEsearchPB = ZI8TRUE;
        Zi8SetPredictionStartAt(0);
    }
    else
    {
        Zi8SetPredictionStartAt(IMEprediction_Startat);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    IMEprocessKeyFunc = IMEprocessKeyEZI_STROKE;
    /* IMElastProcessKeyFunc = IMEprocessKeyEZI_STROKE; */
    IMEchangeInputMethod();

    if (IMEnumOfChars)
    {
        labelSoftL[0] = 'C';
        if (!labelSoftR[0])
        {
            labelSoftR[0] = 'D';
        }
    }
    else
    {
        labelSoftL[0] = 'E';
        if (IMEsearchPB && !labelSoftR[0])
        {
            labelSoftR[0] = 'D';
        }
    }
    UI_UNUSED_PARAMETER(startX);
    UI_UNUSED_PARAMETER(startY);
    UI_UNUSED_PARAMETER(maxRows);
    return (IME_CONTINUE);
}


/*****************************************************************************
 * FUNCTION
 *  IMEprocessKey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyID                   [IN]        
 *  bLongPress              [IN]        
 *  timeBetweenKeyPress     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
IME_RETURN_CODE IMEprocessKey(KEYID keyID, int bLongPress, int timeBetweenKeyPress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static KEYID lastKeyID = KEYUNKNOWN;
    IME_RETURN_CODE rtnCode = IME_SKIP;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef NEPTUNE_MMI
    //steven e-dic
    //to re-register Zi key up/down key handler when Zi in ACTIVE mode
    if (wgui_register_multiline_inputbox_up_down_key_handler != NULL)
    {
        SetKeyHandler(ZiKeyArrowUPHandler, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ZiKeyArrowDownHandler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    }
#endif /* NEPTUNE_MMI */ 

    /* PMT Dara 24/11/04 .....to handle display of composition window */
#ifdef MMI_LOW_MEMORY_PHONE
    if (keyID >= KEY1 && keyID <= KEY9 || (keyID == KEYSTAR) || (keyID == KEYHASH))
    {
        /* PMT dara added on...9/12/2k4 */
        if (ZiMaxLengthCheck() == ZI8FALSE)
        {
            CompositionWindowHideFlag = 1;
            CharacterInsertedFlag = 1;
        }
        else
        {
            CompositionWindowHideFlag = 0;
            CharacterInsertedFlag = 0;  
        }
    }
    else if (keyID == KEY0)
    {
		
        CompositionWindowHideFlag = 1; 
		
        CharacterInsertedFlag = 1;      
    }
    else if ((keyID == KEYUP) || (keyID == KEYDOWN) || (keyID == KEYSOFTR) || (keyID == KEYSOFTL))
    {
        CompositionWindowHideFlag = 1;
        if ((keyID == KEYUP) || (keyID == KEYDOWN))
        {
            CharacterInsertedFlag = 1;
        }

    }
#endif /* MMI_LOW_MEMORY_PHONE */ 
    /* PMT end */
	#ifdef  __MMI_ZI_HINDI__
	if(IMEactive)
		hindi_flag = 2;
	else
		hindi_flag = 0;
	#endif
    if (!IMEactive)
    {
        switch (keyID)
        {

            case KEYLEFT:
        #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    gui_EMS_input_box_previous(&MMI_EMS_inputbox);
                }
                else
        #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
                {
                    gui_single_line_input_box_previous(&MMI_singleline_inputbox);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    gui_multi_line_input_box_previous(&MMI_multiline_inputbox);
                }
                break;
                /* NO BREAK */
            case KEYUP:
            #if defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                #ifndef MMI_LOW_MEMORY_PHONE
                    gui_EMS_input_box_previous_line(&MMI_EMS_inputbox);
				#else
					gui_EMS_input_box_previous(&MMI_EMS_inputbox);     
				#endif
                }
                else
            #endif /* defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    /* PMT dara added for UP long press functionality */
                #ifdef MMI_LOW_MEMORY_PHONE
                    if (!bLongPress)
                    {
                        gui_multi_line_input_box_previous(&MMI_multiline_inputbox);     
                    }
                    else
                    {
                        gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
                    }
                #else /* MMI_LOW_MEMORY_PHONE */ 
                    /* PMT end */
                    gui_multi_line_input_box_previous_line(&MMI_multiline_inputbox);
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
                {
                    gui_single_line_input_box_previous(&MMI_singleline_inputbox);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    /* Commented By Alok */
                #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
                    multiline_inscreen_inputbox_previous_line();
                #endif 
                    goto IME_EXIT;
                }
                break;

            case KEYRIGHT:
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    gui_EMS_input_box_next(&MMI_EMS_inputbox);
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
                {
                    gui_single_line_input_box_next(&MMI_singleline_inputbox);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    gui_multi_line_input_box_next(&MMI_multiline_inputbox);
                }
                break;
                /* NO BREAK */
            case KEYDOWN:
            #if defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
			    #ifndef MMI_LOW_MEMORY_PHONE
                    gui_EMS_input_box_next_line(&MMI_EMS_inputbox);
				#else
					gui_EMS_input_box_next(&MMI_EMS_inputbox);     
				#endif
                }
                else
            #endif /*  defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    /* PMT dara added for UP & DOWN long press functionality */
                #ifdef MMI_LOW_MEMORY_PHONE
                    if (!bLongPress)
                    {
                        gui_multi_line_input_box_next(&MMI_multiline_inputbox);
                    }
                    else
                    {
                        gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
                    }
                #else /* MMI_LOW_MEMORY_PHONE */ 
                    /* PMT end */
                    gui_multi_line_input_box_next_line(&MMI_multiline_inputbox);
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    
                #if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
                    multiline_inscreen_inputbox_next_line();
                #endif 
                    goto IME_EXIT;
                }
                break;

            case KEYSOFTL:
                if (bLongPress)
                {
                #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
                    {
                        gui_EMS_input_box_delete_all(&MMI_EMS_inputbox);
                    }
                    else
                #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
                    {
                        gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                        /* setup the inline edit changed flag */
                        inline_full_screen_edit_changed = 1;
                        multiline_inputbox_input_callback();
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                    {
                        gui_single_line_input_box_delete_all(&MMI_singleline_inputbox);
                    }
                    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
                    {
                        gui_multi_line_input_box_delete_all(&MMI_multiline_inputbox);
                        /* setup the inline edit changed flag */
                        inline_full_screen_edit_changed = 1;
                        multiline_inputbox_input_callback();
                    }

                    IMEcurPos = 0;
                    IMEnumOfChars = 0;
                    break;
                }
                IMEdeleteChar();
                break;

            case KEYSOFTR:
                if (IMEnumOfChars || IMEsearchPB)
                {
                    rtnCode = IME_DONE;
                }
                goto IME_EXIT;

            default:
                IMEactive = ZI8TRUE;
                break;
        }
    }

    rtnCode = IME_CONTINUE;
    if (IMEactive)
    {
        IMEactive = ZI8FALSE;
        rtnCode = IMEprocessKeyFunc(keyID, bLongPress, timeBetweenKeyPress);
    }

  IME_EXIT:
    if ((KEYRED == keyID) || (KEYPOWER == keyID) || (rtnCode == IME_DONE))
    {
        if (IMEsearchPB)
        {
            Zi8SetLatinSearchOrder(0, 0);
            if (IMEoemID)
            {
                Zi8DetachOEMdata(IMEoemID);
                IMEoemID = 0;
            }
        }
        IMEelementCount = 0;
    }
    if (!IMEactive)
    {
        if (IMEnumOfChars || IMEsearchPB)
        {
            labelSoftR[0] = 'D';
        }
        else
        {
            labelSoftR[0] = 0;
        }
        if (IMEnumOfChars)
        {
            labelSoftL[0] = 'C';
        }
        else
        {
            labelSoftL[0] = 'E';
        }
    }

#ifndef NEPTUNE_MMI
    //steven e-dic
    // if Zi is not at Active mode , register up/down key handler by AP
    if (wgui_register_multiline_inputbox_up_down_key_handler != NULL && !IMEactive)
    {
        wgui_register_multiline_inputbox_up_down_key_handler();
    }
#endif /* NEPTUNE_MMI */ 

    /* MTK Terry for __MMI_POPUP_REACH_MAX_LENGTH_MSG__ issues */
    lastKeyID = keyID;
    ZiDisplay();
    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
    {
        PbookListSearchEntryReq();
    }
    UI_UNUSED_PARAMETER(lastKeyID);
    return (rtnCode);
}


/*****************************************************************************
 * FUNCTION
 *  IMEgetCurrentMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
INPUT_MODE IMEgetCurrentMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (IMEmethod);
}


/*****************************************************************************
 * FUNCTION
 *  InitZiInputMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitZiInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ZI8BOOL ziReturnStatus;

#if 0
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
/* under construction !*/
#else
/* under construction !*/
#endif
#else /* 0 */ 
    /* __CUSTPACK_MULTIBIN     Terry   BEGIN */
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
    ZI8_LANGUAGE_ENTRY *Zi8StaticLanguageTable = gIMELDBArray[ZI_TR_CHINESE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziReturnStatus = Zi8InitializeDynamic(Zi8StaticLanguageTable);
#else /* defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__) */ 
    ZI8_LANGUAGE_ENTRY *Zi8StaticLanguageTable = gIMELDBArray;

    ziReturnStatus = Zi8InitializeDynamic(Zi8StaticLanguageTable);
#endif /* defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__) */ 
    /* __CUSTPACK_MULTIBIN     Terry   END */
#endif /* 0 */ 
    if (ziReturnStatus == ZI8TRUE)
    {
#if defined(NOKE_DEBUG)
        noke_dbg_printf(("<<** ZI ZI ZI ZI ZI ZI Successfully **>>\n"));
#endif

    }
    else
    {
#if defined(NOKE_DEBUG)
        noke_dbg_printf(("<<** ZI ZI ZI ZI ZI ZI ZI failed **>>\n"));
#endif
    }
    /* PMT  Dara Added 24/11/2k4 .....for setting new coordinates for Composition & candidate window */
#ifdef MMI_LOW_MEMORY_PHONE
    /* create the single line input box */
    gui_create_single_line_input_box_use_buffer(&ziCompositionArea, MMI_multitap_x,     /* MMI_multitap_x+50, */
#ifdef __MMI_MAINLCD_128X128__
                                                MMI_multitap_y, MMI_multitap_width - 64,  
#else /* __MMI_MAINLCD_128X128__ */
                                                MMI_multitap_y, MMI_multitap_width - 49,        /* try 52 */
#endif /* __MMI_MAINLCD_128X128__ */
                                                
#if defined __MMI_UI_STYLE_14x14__
#ifdef __MMI_MAINLCD_128X128__
                                                MMI_multitap_height,
#else /* __MMI_MAINLCD_128X128__ */									 
                                                MMI_multitap_height - 2,
#endif /*__MMI_MAINLCD_128X128__*/

#else /* __MMI_UI_STYLE_14x14__ */
                                                MMI_multitap_height,
#endif /* __MMI_UI_STYLE_14x14__ */
                                                ziCompositionBuffer,
                                                ((ZI_COMPOSITION_BUFFER_SIZE + 1) * sizeof(ZI8WCHAR)));

    gui_create_single_line_input_box_use_buffer(
        &ziCandidateArea,
#ifdef __MMI_MAINLCD_128X128__
        MMI_multitap_x + 64,     
        MMI_multitap_y,
        MMI_multitap_width - 64, 
#else /* __MMI_MAINLCD_128X128__ */
        MMI_multitap_x + 53,        /* MMI_multitap_x, */
        MMI_multitap_y,
        MMI_multitap_width - 46,    /* 43 */
#endif /* __MMI_MAINLCD_128X128__ */
        MMI_multitap_height,
        ziCandidateBuffer,
        ((ZI_CANDIDATE_BUFFER_SIZE + 1) * sizeof(ZI8WCHAR)));

#else /* MMI_LOW_MEMORY_PHONE */ 
    /* PMT end */
    /* MTK Terry temp solution for composition and candidate window display */
    gui_create_single_line_input_box_use_buffer(
        &ziCompositionArea,
        MMI_multitap_x + 8,
        ZI_COMPOSITION_Y,
        MMI_multitap_width - 16,
        MMI_multitap_height - 1,
        ziCompositionBuffer,
        ((ZI_COMPOSITION_BUFFER_SIZE + 1) * sizeof(ZI8WCHAR)));

    gui_create_single_line_input_box_use_buffer(
        &ziCandidateArea,
        MMI_multitap_x + 8,
        ZI_CANDIDATE_Y,
        MMI_multitap_width - 16,
        MMI_multitap_height,
        ziCandidateBuffer,
        ((ZI_CANDIDATE_BUFFER_SIZE + 1) * sizeof(ZI8WCHAR)));
	ziCandidateArea.flags |= (UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY);
#endif /* MMI_LOW_MEMORY_PHONE */ 
    ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW;
    /* ziCompositionArea.flags |=UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS; */
#if !defined(MONO_LCD)
    ziCompositionArea.cursor_color.r = 255;
    ziCompositionArea.cursor_color.g = 255;
    ziCompositionArea.cursor_color.b = 255;
    ziCompositionArea.cursor_color.alpha = 100;
#else /* !defined(MONO_LCD) */ 
    ziCompositionArea.cursor_color = WHITE;
#endif /* !defined(MONO_LCD) */ 
    // #ifdef __MMI_DEFAULT_THEME_3__
    ziCompositionArea.normal_filler = &MMI_ZI_COMPOSITION_WINDOW_filler;
    ziCompositionArea.selection_color = multitap_selector_txt_col_Default;
    ziCompositionArea.selection_text_color = multitap_selected_txt_col_Default;
    // #endif

    ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
    ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_DISABLE_SCROLLING;
    ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_VIEW_FULL_CHARACTERS;
#if !defined(MONO_LCD)
    ziCandidateArea.cursor_color.r = 255;
    ziCandidateArea.cursor_color.g = 255;
    ziCandidateArea.cursor_color.b = 255;
    ziCandidateArea.cursor_color.alpha = 100;
#else /* !defined(MONO_LCD) */ 
    ziCandidateArea.cursor_color = WHITE;
#endif /* !defined(MONO_LCD) */ 
    //#ifdef __MMI_DEFAULT_THEME_3__
    //ziCandidateArea.normal_filler =(UI_filled_area*) &MMI_multitap_filler;
    ziCandidateArea.normal_filler = (current_UI_theme->multitap_input_theme->f);
    ziCandidateArea.selection_color = multitap_selector_txt_col_Default;
    ziCandidateArea.selection_text_color = multitap_selected_txt_col_Default;
    ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_CHARACTER_HIGHLIGHT;
    // #endif

    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    ziNoDrawRightArrowSymbol = ZI8FALSE;
    ziNoDrawCandidateRightArrowSymbol = ZI8FALSE;

    ziMultilineEditorHeight = 0;
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    ziEMSEditorHeight = 0;
#endif 
    ziFrameTimerStart = ZI8FALSE;

    IMEoemID = 0;
    IMEmethod = INPUT_EZI_PINYIN;
    IMEletterCase = ZI8_CASE_LOWER;
    IMEmethodZH = INPUT_EZI_PINYIN;     /* for pinyin */
    IMEmethodLast = INPUT_EZI_PINYIN;   /* for pinyin */
    IMEsubLanguage = ZI8_SUBLANG_ZH_HK; /* for pinyin */
    pbOrder = PB_ORDER_UNICODE;
    iStepID = PHONETIC_2_STEPS;
    bNoComponent = ZI8FALSE;
    bUseZHUWD = ZI8FALSE;
    bComponentOn2ndKey = ZI8FALSE;
    IMEprediction_Startat = PREDICTION_STARTAT;
    bNoRadicals = ZI8TRUE;
    IMEalphaLangID = ALPHA_LANG_EN;

    IMEstart(
        /* ziTextBuffer, */ 0,
        MAX_MESSAGE_LENGTH,
        IME_NORMAL_TEXT,
        ANY_LANGUAGE,
        0,
        1,
        ZI_CANDIDATE_BUFFER_SIZE * 2,
        10);

}

#ifdef UI_SMALL_CATEGORY_EDITOR
extern BOOL g_small_editor_category_present;


/*****************************************************************************
 * FUNCTION
 *  ZiResizeSinglelineInputbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiResizeSinglelineInputbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_single_line_input_box(&ziCompositionArea, MMI_multitap_width - 16, MMI_multitap_height - 1);
    gui_resize_single_line_input_box(&ziCandidateArea, MMI_multitap_width - 16, MMI_multitap_height);
#if defined(PLUTO_MMI)
    ziCandidateArea.flags |= (UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY);
#endif
    if (g_small_editor_category_present)
    {
        gui_move_single_line_input_box(&ziCompositionArea, MMI_multitap_x + 8, MMI_multitap_y - MMI_multitap_height);
        gui_move_single_line_input_box(&ziCandidateArea, MMI_multitap_x + 8, MMI_multitap_y);
    #if defined(PLUTO_MMI)
        /*                    (editor width          - x start)              / (width of Chinese character one with text gap)       */                
        IMEmaxCols = (((MMI_multitap_width - 16) - ziCandidateArea.text_x) / (gui_get_character_width(0x4E00) + ziCandidateArea.text_gap)) << 1;
    #else
        IMEmaxCols = 14;
    #endif
    }
    else
    {
        gui_move_single_line_input_box(
            &ziCompositionArea,
            MMI_multitap_x + 8,
            MMI_multitap_y - MMI_multitap_height - 2);
        gui_move_single_line_input_box(&ziCandidateArea, MMI_multitap_x + 8, MMI_multitap_y - 1);
        IMEmaxCols = ZI_CANDIDATE_BUFFER_SIZE * 2;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ZiResizeSelectionArea
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiResizeSelectionArea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ZiResizeSinglelineInputbox();
}
#endif /* UI_SMALL_CATEGORY_EDITOR */ 


/*****************************************************************************
 * FUNCTION
 *  ZiKey0PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey0PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY0, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey1PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey1PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY1, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey2PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey2PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY2, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey3PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey3PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY3, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey4PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey4PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY4, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey5PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey5PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY5, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey6PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey6PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY6, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey7PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey7PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY7, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey8PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey8PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY8, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKey9PressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKey9PressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEY9, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowUPHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowUPHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYUP, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowRightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowRightHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYRIGHT, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowDownHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYDOWN, 0, 0);

}

/* PMT dara added for UP & DOWN long press functionality */
#ifdef MMI_LOW_MEMORY_PHONE


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowDownLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowDownLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYDOWN, 1, 0);
}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowUPLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowUPLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYUP, 1, 0);
}
#endif /* MMI_LOW_MEMORY_PHONE */ 
/* PMT end */


/*****************************************************************************
 * FUNCTION
 *  ZiKeyArrowLeftHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyArrowLeftHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYLEFT, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyStarPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyStarPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYSTAR, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyStarLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyStarLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYSTAR, 1, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyHashPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyHashPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYHASH, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyHashLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyHashLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYHASH, 1, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyLSKPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyLSKPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYSOFTR, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyLSKLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyLSKLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IMEprocessKey(KEYSOFTR,1,0 ); */

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyRSKPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyRSKPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYSOFTL, 0, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiKeyRSKLongPressHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiKeyRSKLongPressHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEprocessKey(KEYSOFTL, 1, 0);

}


/*****************************************************************************
 * FUNCTION
 *  ZiDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef  __MMI_ZI_HINDI__
	ZI8LONG textLength=0;
	U16 previous_char;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ziFrameCounterForEMSEditor > 0)
    {
        ziFrameCounterForEMSEditor++;
    }
    else
    {
        ziFrameCounterForEMSEditor = 1;
		#ifdef  __MMI_ZI_HINDI__
		if(IMEinline[0])
		{
		if((ziInputMethodCategoryFlag &ZI_IN_CATEGORY_5_FLAG))
		{
			UI_buffer_type		current_text_p;
			current_text_p = MMI_multiline_inputbox.cursor_p-hindi_flag;
			textLength = MMI_multiline_inputbox.text_length-2;
			UI_STRING_GET_PREVIOUS_CHARACTER(current_text_p,previous_char);
		}
		else
		{
			textLength = MMI_EMS_inputbox.data->textLength;		
			previous_char = *((UI_character_type*)(MMI_EMS_inputbox.data->textBuffer+MMI_EMS_inputbox.data->CurrentPosition.OffsetToText-2-hindi_flag));
		}
		if((textLength==0)&&UI_HINDI_SIGN_RANGE(IMEinline[0]))
		 {
		  if( IdentifyCharacter(IMEinline[0]) != CON)
		  {	
			  ziFrameCounterForEMSEditor = 0;
			  IMEprocessKey(hindi_keyId,0,0 );
			  return;
		  }
		  }
		  else if(UI_HINDI_SIGN_RANGE(IMEinline[0]))
		  {
		  if( (IdentifyCharacter(previous_char) != CON)&&(IdentifyCharacter(previous_char) != INDVOW))
		  {
			  ziFrameCounterForEMSEditor = 0;
			  IMEprocessKey(hindi_keyId,0,0 );
			   return;
		  }				  
		  }	
		}
		#endif
        gui_start_timer(ZI_FRAME_START_TIMEOUT, ZiDisplayForEmsEditorEndFrame);
        /* StartMyTimerInt(ZI_FRAME_TIMER, ZI_FRAME_START_TIMEOUT, (oslTimerFuncPtr) ZiDisplayForEmsEditorEndFrame, 0); */
        ziFrameTimerStart = ZI8TRUE;
    }
#if defined(__MMI_POPUP_REACH_MAX_LENGTH_MSG__)
    /* MTK Terry for __MMI_POPUP_REACH_MAX_LENGTH_MSG__ issues */
    if (ZiMaxLengthCheck() == ZI8FALSE)
    {
        switch (lastKeyID)
        {
            case KEY1:
            case KEY2:
            case KEY3:
            case KEY4:
            case KEY5:
            case KEY6:
            case KEY7:
            case KEY8:
            case KEY9:
            case KEY0:
            case KEYSOFTR:
                gui_start_timer(UI_POPUP_NOTIFYDURATION_TIME, ZiDisplayForEmsEditorEndFrame);
                ziFrameTimerStart = ZI8TRUE;
                break;
            default:
                break;
        }
    }
    /* MTK end */
#endif /* defined(__MMI_POPUP_REACH_MAX_LENGTH_MSG__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  ZiDisplayForEmsEditorEndFrame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiDisplayForEmsEditorEndFrame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ZI8LONG i, j, k, count;
    ZI8LONG cursorPosition;
    ZI8WCHAR iChar = 0;
    UI_character_type current_character;
    ZI8LONG h;
    ZI8LONG textLength = 0;


#if defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_HEBREW__) || defined(__MMI_ZI_PERSIAN__)

    ZI8USHORT nLen = 0;

#endif /* defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_HEBREW__) || defined(__MMI_ZI_PERSIAN__) */ 

    //#ifdef UI_SMALL_CATEGORY_EDITOR
    ZI8USHORT candidate_buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //#endif        /* UI_SMALL_CATEGORY_EDITOR  */

    if (ziFrameCounterForEMSEditor >= 1 && ziFrameTimerStart == ZI8TRUE)
    {
        gui_lock_double_buffer();
    #ifdef UI_SMALL_CATEGORY_EDITOR
        if (g_small_editor_category_present)
        {
            candidate_buffer_size = ZI_CANDIDATE_BUFFER_SIZE - 2;
        }
        else
    #else /* UI_SMALL_CATEGORY_EDITOR */ 
        candidate_buffer_size = ZI_CANDIDATE_BUFFER_SIZE;
    #endif /* UI_SMALL_CATEGORY_EDITOR */ 
        if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
        {
            gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        }

        /* draw EMS input box */
        if ((IMEmethod != INPUT_EZI_PINYIN) &&
            (IMEmethod != INPUT_EZI_BOPOMOFO) &&
            (IMEmethod != INPUT_EZI_STROKE) &&
            (IMEmethod != INPUT_EZI_MULTITAP_PINYIN) && (IMEmethod != INPUT_EZI_MULTITAP_BOPOMOFO))
        {

            if (IMEinline[0] == 0)
            {
                ziEngWordLen = 0;
            }

        #if defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__)

            else
            {
                nLen = UCS2Strlen((const char*)IMEinline);
            }

        #endif /* defined(__MMI_ZI_ARABIC__) || defined(__MMI_ZI_PERSIAN__) */ 


        #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
            /* to keep the EMS text format state */
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
            {
                ziKeepEMSTextFormat = MMI_EMS_inputbox.text_format;
            }
        #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
            for (k = 0; k < ziEngWordLen; k++)
            {
                IMEdeleteChar();

            }

        #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
            /* to restore the EMS text format state */
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
            {
                MMI_EMS_inputbox.text_format = ziKeepEMSTextFormat;
                wgui_EMS_text_format = MMI_EMS_inputbox.text_format;

            }
        #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
            ziEngWordLen = 0;

            /* it is not required to convert the 0x62 to appropriated charaters */
            /*
             * for( k = 0; IMEinline[k]; k++ )
             * {
             * if(IMEinline[k] == 62)
             * {
             * switch(IMEelementBuffer[0])
             * {
             * case  ZI8_ONEKEY_KEY2:
             * IMEinline[k]=0x61;
             * break;
             * case  ZI8_ONEKEY_KEY3:
             * IMEinline[k]=0x64;
             * break;
             * case  ZI8_ONEKEY_KEY4:
             * IMEinline[k]=0x67;
             * break;
             * case  ZI8_ONEKEY_KEY5:
             * IMEinline[k]=0x6A;
             * break;
             * case  ZI8_ONEKEY_KEY6:
             * IMEinline[k]=0x6D;
             * break;
             * case  ZI8_ONEKEY_KEY7:
             * IMEinline[k]=0x70;
             * break;
             * case  ZI8_ONEKEY_KEY8:
             * IMEinline[k]=0x74;
             * break;
             * case  ZI8_ONEKEY_KEY9:
             * IMEinline[k]=0x77;
             * break;
             * }
             * if(IMEletterCase == ZI8_CASE_UPPER)
             * IMEinline[k] = towupper(IMEinline[k]);
             * 
             * 
             * }
             * }
             */

            for (k = 0; IMEinline[k]; k++)
            {
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    textLength = MMI_EMS_inputbox.data->textLength;
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    textLength = MMI_multiline_inputbox.text_length;
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    textLength = MMI_singleline_inputbox.text_length;
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    textLength = MMI_multiline_inputbox.text_length;
                }

                IMEinsertChar(IMEinline[k]);

            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    if (MMI_EMS_inputbox.data->textLength > textLength)
                    {
                        ziEngWordLen++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    if (MMI_multiline_inputbox.text_length > textLength)
                    {
                        ziEngWordLen++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    if (MMI_singleline_inputbox.text_length > textLength)
                    {
                        ziEngWordLen++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    if (MMI_multiline_inputbox.text_length > textLength)
                    {
                        ziEngWordLen++;
                    }
                    else
                    {
                        break;
                    }
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
/* under construction !*/
        #endif /* 0 */ 

            if (IMEinline[0])
            {
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    count = gui_EMS_input_box_highlight_cursor_number(&MMI_EMS_inputbox, ziEngWordLen);
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    count = gui_multi_line_input_box_highlight_cursor_number(&MMI_multiline_inputbox, ziEngWordLen);
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    count = gui_single_line_input_box_highlight_cursor_number(&MMI_singleline_inputbox, ziEngWordLen);
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    count = gui_multi_line_input_box_highlight_cursor_number(&MMI_multiline_inputbox, ziEngWordLen);
                }
            }
            else
            {
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
                {
                    MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
                }
                else
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
                {
                    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                }
                else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
                {
                    MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                }
                else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
                {
                    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                }
            }

        }

    #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)

        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
        {
            if (MMI_EMS_inputbox.height > ziEMSEditorHeight)
            {
                ziEMSEditorHeight = MMI_EMS_inputbox.height;
            }

            if ((IMEbValidPhonetic) ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                /* h=MMI_content_height-MMI_multitap_height*2-12; */
                /* MTK Terry temp solution for composition and candidate window display */
            #if defined(__MMI_FULL_SCREEN_EDITOR__)
                h = ziEMSEditorHeight - MMI_multitap_height - MMI_multitap_height - 3;  /* 12; */
            #else /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            #ifdef __MMI_UI_STYLE_14x14__
                h = ziEMSEditorHeight;
            #else /* __MMI_UI_STYLE_14x14__ */ 
				#if defined(MMI_LOW_MEMORY_PHONE) && (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__))
					h = ziEMSEditorHeight;
				#else
					h = ziEMSEditorHeight - MMI_multitap_height - 3;        /* 12; */
				#endif
            #endif /* __MMI_UI_STYLE_14x14__ */ 
            #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
                gui_resize_EMS_input_box(&MMI_EMS_inputbox, MMI_EMS_inputbox.width, h);
                MMI_EMS_inputbox.flags |= (UI_EMS_INPUT_BOX_DISABLE_DRAW);
                gui_show_EMS_input_box(&MMI_EMS_inputbox);
                MMI_EMS_inputbox.flags &= ~(UI_EMS_INPUT_BOX_DISABLE_DRAW);
                ZiHideCompositionArea();
                hide_multitap();

            }
        #if defined(__MMI_FULL_SCREEN_EDITOR__)
            else if ((IMEbValidCandidates && ((IMEmethod == INPUT_EZI_STROKE) ||
                                              (IMEmethod == INPUT_EZI_PINYIN) ||
                                              (IMEmethod == INPUT_EZI_BOPOMOFO) ||
                                              (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                                              (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                h = ziEMSEditorHeight - MMI_multitap_height-3;
                gui_resize_EMS_input_box(&MMI_EMS_inputbox, MMI_EMS_inputbox.width, h);
                MMI_EMS_inputbox.flags |= (UI_EMS_INPUT_BOX_DISABLE_DRAW);
                gui_show_EMS_input_box(&MMI_EMS_inputbox);
                MMI_EMS_inputbox.flags &= ~(UI_EMS_INPUT_BOX_DISABLE_DRAW);
                ZiHideCompositionArea();
                hide_multitap();
            }
        #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            else
            {
                /* h=MMI_content_height-MMI_multitap_height-12; */
                h = ziEMSEditorHeight;
                gui_resize_EMS_input_box(&MMI_EMS_inputbox, MMI_EMS_inputbox.width, h);
                MMI_EMS_inputbox.flags |= (UI_EMS_INPUT_BOX_DISABLE_DRAW);
                gui_show_EMS_input_box(&MMI_EMS_inputbox);
                MMI_EMS_inputbox.flags &= ~(UI_EMS_INPUT_BOX_DISABLE_DRAW);
                ZiHideCompositionArea();
            #if defined(__MMI_FULL_SCREEN_EDITOR__)
            #else /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
                hide_multitap();
            #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            }
            gui_show_EMS_input_box(&MMI_EMS_inputbox);
        }
        else
    #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
        {
            if (MMI_multiline_inputbox.height > ziMultilineEditorHeight)
            {
                ziMultilineEditorHeight = MMI_multiline_inputbox.height;
            }
            if ((IMEbValidPhonetic) ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                /* h=MMI_content_height-MMI_multitap_height*2-12; */
            #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
                /* MTK Terry temp solution for composition and candidate window display */
            #if defined(__MMI_FULL_SCREEN_EDITOR__)
                h = ziMultilineEditorHeight - MMI_multitap_height - MMI_multitap_height - 3;
            #else /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            #ifdef __MMI_UI_STYLE_14x14__
                h = ziMultilineEditorHeight;
            #else /* __MMI_UI_STYLE_14x14__ */ 
                h = ziMultilineEditorHeight - MMI_multitap_height - 3;
            #endif /* __MMI_UI_STYLE_14x14__ */ 
            #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            #else /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                h = ziMultilineEditorHeight;
            #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
                resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                ZiHideCompositionArea();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //set_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
                hide_multitap();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //reset_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
            }
        #if defined(__MMI_FULL_SCREEN_EDITOR__)
            else if ((IMEbValidCandidates && ((IMEmethod == INPUT_EZI_STROKE) ||
                                              (IMEmethod == INPUT_EZI_PINYIN) ||
                                              (IMEmethod == INPUT_EZI_BOPOMOFO) ||
                                              (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                                              (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                    h = ziMultilineEditorHeight - MMI_multitap_height - 3;
                resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                ZiHideCompositionArea();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //set_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
                hide_multitap();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //reset_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
            }
        #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            else
            {
                /* h=MMI_content_height-MMI_multitap_height-12; */
                h = ziMultilineEditorHeight;
                resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                ZiHideCompositionArea();
            #if defined(__MMI_FULL_SCREEN_EDITOR__)
            #else /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //set_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
                hide_multitap();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //reset_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
            #endif /* defined(__MMI_FULL_SCREEN_EDITOR__) */ 
            }
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);

        }
        else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
        {
            redraw_input_mode_only();
            gui_show_single_line_input_box(&MMI_singleline_inputbox);
            /* redraw_fixed_list(); */
            gui_show_fixed_list_menu(&MMI_fixed_list_menu);

        }
        else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
        {
            if (MMI_multiline_inputbox.height > ziMultilineEditorHeight)
            {
                ziMultilineEditorHeight = MMI_multiline_inputbox.height;
            }
            if ((IMEbValidPhonetic) ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                /* h=MMI_content_height-MMI_multitap_height*2-12; */
                /* MTK Terry temp solution for composition and candidate window display */
                h = ziMultilineEditorHeight - MMI_multitap_height - 3;
                resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                ZiHideCompositionArea();
                hide_multitap();
            }
            else
            {
                /* h=MMI_content_height-MMI_multitap_height-12; */
                h = ziMultilineEditorHeight;
                resize_multiline_inputbox(MMI_multiline_inputbox.width, h);
                MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
                MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
                /* ZiHideCompositionArea(); */
                if (IMEbValidCandidates && ((IMEmethod == INPUT_EZI_STROKE) ||
                                            (IMEmethod == INPUT_EZI_PINYIN) ||
                                            (IMEmethod == INPUT_EZI_BOPOMOFO) ||
                                            (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                                            (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO)))
                {
                    hide_multitap();
                }
            }
            gui_show_multi_line_input_box(&MMI_multiline_inputbox);

        }

        /* draw composition input box */
        if (IMEbValidPhonetic /* && !bSkipGetZHCandidate */ )
        {
            /* MTK Terry for Composition Window Update Issue */
            /* if(!IMEbFocusOnPhonetic ||!bSkipGetCandidate || ziRefillPhoneticBuffer) */
            {
                /* update candinates selection input box parameters */
                if (ziCompositionArea.text_length > ENCODING_LENGTH)
                {
                    gui_single_line_input_box_delete_all(&ziCompositionArea);
                }

                for (i = 0; i < IMEphoneticCount; i++)
                {

                    switch (IMEmethod)
                    {
                        case INPUT_EZI_STROKE:
                            break;
                        case INPUT_EZI_MULTITAP_BOPOMOFO:
                        case INPUT_EZI_BOPOMOFO:

                        #ifdef __MMI_ZI_V7__
                            gui_single_line_input_box_insert_string(
                                &ziCompositionArea,
                                IMEpPhoneticPtr[i], /*-2991 */
                                0xc200);
                         #else /* __MMI_ZI_V7__ */ 
                            /* gui_single_line_input_box_insert_character(&ziCompositionArea,IMEpPhoneticPtr[i][j]-0xc200); */
                            gui_single_line_input_box_insert_string(
                                &ziCompositionArea,
                                IMEpPhoneticPtr[i], /*-2991 */
                                0xc300);
                         #endif /* __MMI_ZI_V7__ */ 
                            break;
                        case INPUT_EZI_MULTITAP_PINYIN:
                        case INPUT_EZI_PINYIN:
                        #ifdef __MMI_ZI_V7__
                            gui_single_line_input_box_insert_string(&ziCompositionArea, IMEpPhoneticPtr[i], 0xf300);
                        #else /* __MMI_ZI_V7__ */ 
                            /* gui_single_line_input_box_insert_character(&ziCompositionArea,IMEpPhoneticPtr[i][j]-0xf300); */
                            gui_single_line_input_box_insert_string(&ziCompositionArea, IMEpPhoneticPtr[i], 0xf400);
                        #endif /* __MMI_ZI_V7__ */ 
                            break;
                    }
                    gui_single_line_input_box_insert_character(&ziCompositionArea, 0x20);

                }
                gui_single_line_input_box_goto_first_character(&ziCompositionArea);
                ziPhoneticIndex = 0;

            }

            /* move the cursor to IMEphoneticIndex */
            if (IMEphoneticIndex == 0)
            {
                gui_single_line_input_box_goto_first_character(&ziCompositionArea);
                /* j = 0; */
                for (j = 0; j < IMEelementCount; j++)
                {
                    gui_single_line_input_box_next(&ziCompositionArea);

                }
            }
            else
            {

                if (IMEphoneticIndex > ziPhoneticIndex)
                {

                    current_character =
                        (ZI8WCHAR) *
                        (ziCompositionArea.current_text_p) | (ZI8WCHAR) (*(ziCompositionArea.current_text_p + 1)) << 8;
                    while (IMEphoneticIndex != ziPhoneticIndex)
                    {
                        gui_single_line_input_box_next(&ziCompositionArea);
                        /* MTK Terry to avoid infinite loop */
                        if (UI_STRING_END_OF_STRING_CHARACTER(current_character))
                        {
                            break;
                        }
                        if (current_character == 0x0020)
                        {
                            ziPhoneticIndex++;
                            if (IMEphoneticIndex == ziPhoneticIndex)
                            {
                                break;
                            }
                        }
                        current_character =
                            (ZI8WCHAR) *
                            (ziCompositionArea.
                             current_text_p) | (ZI8WCHAR) (*(ziCompositionArea.current_text_p + 1)) << 8;
                    }
                    /* gui_single_line_input_box_next(&ziCompositionArea); */
                    for (j = 0; j < IMEelementCount; j++)
                    {
                        gui_single_line_input_box_next(&ziCompositionArea);

                    }

                }
                else if (IMEphoneticIndex < ziPhoneticIndex)
                {

                    current_character =
                        (ZI8WCHAR) * (ziCompositionArea.current_text_p -
                                      2) | (ZI8WCHAR) (*(ziCompositionArea.current_text_p - 1)) << 8;
                    while ((IMEphoneticIndex - 1) != ziPhoneticIndex)
                    {
                        gui_single_line_input_box_previous(&ziCompositionArea);
                        if (current_character == 0x0020)
                        {
                            ziPhoneticIndex--;
                            if (ziPhoneticIndex == (IMEphoneticIndex - 1))
                            {
                                gui_single_line_input_box_next(&ziCompositionArea);
                                break;

                            }
                        }
                        current_character =
                            (ZI8WCHAR) * (ziCompositionArea.current_text_p -
                                          2) | (ZI8WCHAR) (*(ziCompositionArea.current_text_p - 1)) << 8;
                    }

                    for (j = 0; j < IMEelementCount; j++)
                    {
                        gui_single_line_input_box_next(&ziCompositionArea);

                    }

                }

            }
            ziPhoneticIndex = IMEphoneticIndex;
            if (IMEbFocusOnPhonetic)
            {
                /*
                 * if(iStepID != PHONETIC_MULTITAP)
                 * {
                 * gui_single_line_input_box_highlight_cursor_number(&ziCompositionArea, IMEelementCount);
                 * ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                 * ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
                 * }
                 * else
                 * {
                 * if(lastKeyID == 0)
                 * {
                 * ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                 * ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
                 * }
                 * else
                 * {
                 * gui_single_line_input_box_highlight_cursor_number(&ziCompositionArea, 1);
                 * ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                 * ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;
                 * 
                 * }
                 * 
                 * }
                 */
                gui_single_line_input_box_highlight_cursor_number(&ziCompositionArea, IMEelementCount);
                ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                ziCompositionArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            }
            else
            {
                ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            }
            gui_show_single_line_input_box(&ziCompositionArea);
            /* draw one dotted line */
            /*
             * gui_reset_clip();
             * for(i= ziCompositionArea.x; i <(ziCompositionArea.x+ziCompositionArea.width); i++)
             * {
             * if((i%3) != 0)
             * gui_putpixel(i, ziCompositionArea.y+ziCompositionArea.height-1, gui_color(0,0,0));
             * }
             */
            /* draw the arrow to infor that user can press arrow left or right to select desired phonetic */
            gui_reset_clip();
            gui_fill_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y, ziCompositionArea.x, ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
#if defined(MMI_LOW_MEMORY_PHONE) && defined(__MMI_MAINLCD_128X128__)
                               gui_color(0, 0, 0)
#else
                               gui_color(182, 189, 210)
#endif
        #else 
                               WHITE
        #endif 
                );

#ifdef MMI_LOW_MEMORY_PHONE 
#ifndef __MMI_MAINLCD_128X128__
            gui_fill_rectangle(ziCompositionArea.x + ziCompositionArea.width,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(182, 189, 210)
        #else 
                               WHITE
        #endif 
                );

            gui_draw_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height - 1,
        #if !defined(MONO_LCD)
                               gui_color(0, 0, 0)
        #else 
                               BLACK
        #endif 
                );

#endif	/* __MMI_MAINLCD_128X128__*/
#else	/* MMI_LOW_MEMORY_PHONE */
            gui_fill_rectangle(ziCompositionArea.x + ziCompositionArea.width,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(182, 189, 210)
        #else 
                               WHITE
        #endif 
                );

            gui_draw_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(0, 0, 0)
        #else 
                               BLACK
        #endif 
                );
#endif	/* MMI_LOW_MEMORY_PHONE */
            gui_reset_clip();
            if (IMEbFocusOnPhonetic)
            {
                /* R */
                if (IMEphoneticIndex == 0 && zifirstPhoneticCandidate == 0 && IMEphoneticCount > 1)
                {
                    draw_resizeable_arrow(
                #ifdef MMI_LOW_MEMORY_PHONE
                                             ziCompositionArea.x + ziCompositionArea.width + 1, ziCompositionArea.y + 7,
                                             1,
                #else /* MMI_LOW_MEMORY_PHONE */ 
                                             ziCompositionArea.x + ziCompositionArea.width, ziCompositionArea.y + 5, 1,
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                #if !defined(MONO_LCD)
                                             gui_color(0, 0, 0)
                #else 
                                             BLACK
                #endif 
                                             , 3, 6);
                }
                //L
            #ifdef MMI_LOW_MEMORY_PHONE
                else if (((IMEphoneticIndex == IMEphoneticCount - 1) && IMEphoneticCount < MAX_PHONETIC_CANDSIZE &&
                          IMEphoneticCount >= 1) || ziNoDrawRightArrowSymbol)
            #else /* MMI_LOW_MEMORY_PHONE */ 
                else if (((IMEphoneticIndex == IMEphoneticCount - 1) && IMEphoneticCount < MAX_PHONETIC_CANDSIZE &&
                          IMEphoneticCount > 1) || ziNoDrawRightArrowSymbol)
            #endif /* MMI_LOW_MEMORY_PHONE */ 
                {
                #ifdef MMI_LOW_MEMORY_PHONE
                    if ((IMEmethod != INPUT_EZI_MULTITAP_BOPOMOFO) && (IMEmethod != INPUT_EZI_MULTITAP_PINYIN))
                    {
                        draw_resizeable_arrow(ziCompositionArea.x + ziCompositionArea.width + 1,
                                              ziCompositionArea.y + 2, 0,
                    #if !defined(MONO_LCD)
                                              gui_color(0, 0, 0)
                    #else 
                                              BLACK
                    #endif 
                                              , 3, 6);
                    }

                #else /* MMI_LOW_MEMORY_PHONE */ 
                    draw_resizeable_arrow(ziCompositionArea.x - 5, ziCompositionArea.y + 5, 0,
                #if !defined(MONO_LCD)
                                          gui_color(0, 0, 0)
                #else 
                                          BLACK
                #endif 
                                          , 3, 6);
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                }
                /* L and R */
                else if (IMEphoneticCount > 1)
                {
                #ifdef MMI_LOW_MEMORY_PHONE
                    draw_resizeable_arrow(ziCompositionArea.x + ziCompositionArea.width + 1, ziCompositionArea.y + 2, 0,
                #if !defined(MONO_LCD)
                                          gui_color(0, 0, 0)
                #else 
                                          BLACK
                #endif 
                                          , 3, 6);
                    draw_resizeable_arrow(ziCompositionArea.x + ziCompositionArea.width + 1, ziCompositionArea.y + 7, 1,
                #if !defined(MONO_LCD)
                                          gui_color(0, 0, 0)
                #else 
                                          BLACK
                #endif 
                                          , 3, 6);

                #else /* MMI_LOW_MEMORY_PHONE */ 
                    draw_resizeable_arrow(ziCompositionArea.x + ziCompositionArea.width, ziCompositionArea.y + 5, 1,
                #if !defined(MONO_LCD)
                                          gui_color(0, 0, 0)
                #else 
                                          BLACK
                #endif 
                                          , 3, 6);
                    draw_resizeable_arrow(ziCompositionArea.x - 5, ziCompositionArea.y + 5, 0,
                #if !defined(MONO_LCD)
                                          gui_color(0, 0, 0)
                #else 
                                          BLACK
                #endif 
                                          , 3, 6);
                #endif /* MMI_LOW_MEMORY_PHONE */ 
                }

            }

        }
        else if (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) && ((IMEmethod == INPUT_EZI_STROKE) ||
                                                                     (IMEmethod == INPUT_EZI_PINYIN) ||
                                                                     (IMEmethod == INPUT_EZI_BOPOMOFO) ||
                                                                     (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                                                                     (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO)))
        {
            /* update candinates selection input box parameters */
            if (ziCompositionArea.text_length > ENCODING_LENGTH)
            {
                gui_single_line_input_box_delete_all(&ziCompositionArea);
            }

            j = 0;
            while (IMEinline[j])
            {
                switch (IMEmethod)
                {
                    case INPUT_EZI_STROKE:
                        if (IMEinline[j] == ZI8_CODE_MORE)
                        {
                            gui_single_line_input_box_insert_character(&ziCompositionArea, 0x2026);
                        }
                        else
                        {
                            gui_single_line_input_box_insert_character(
                                &ziCompositionArea,
                                IMEinline[j] /*-0xf000+0x30 */ );
                        }
                        break;
                    case INPUT_EZI_MULTITAP_BOPOMOFO:
                    case INPUT_EZI_BOPOMOFO:
                        if (IMEinline[j] >= ZI8_CODE_TONES_1 &&
                            IMEinline[j] <= ZI8_CODE_TONES_5 /* && j==IMEprediction-1 */ )
                        {
                            switch (IMEinline[j])
                            {
                                case 0xf431:
                                    iChar = 0x002D; /* '-' */
                                    break;
                                case 0xf432:
                                    iChar = 0x02CA;
                                    break;
                                case 0xf433:
                                    iChar = 0x02C7;
                                    break;
                                case 0xf434:
                                    iChar = 0x02CB;
                                    break;
                                case 0xf435:
                                    iChar = 0x02D9;
                                    break;

                            }
                            gui_single_line_input_box_insert_character(&ziCompositionArea, iChar);
                        }
                        else
                        {
                            if (IMEinline[j] == ZI8_CODE_MORE)
                            {
                                gui_single_line_input_box_insert_character(&ziCompositionArea, 0x2026);
                            }
                            else
                            {
                             #ifdef __MMI_ZI_V7__
                                gui_single_line_input_box_insert_character(
                                    &ziCompositionArea, /* IMEinline[j]+2991 */
                                    (UI_character_type) (IMEinline[j] - 0xc200));
                             #else /* __MMI_ZI_V7 */ 
                                gui_single_line_input_box_insert_character(
                                    &ziCompositionArea, /* IMEinline[j]+2991 */ 
                                    (UI_character_type) (IMEinline[j] - 0xc300));
                             #endif /* __MMI_ZI_V7 */ 
                            }
                        }
                        break;
                    case INPUT_EZI_MULTITAP_PINYIN:
                    case INPUT_EZI_PINYIN:
                        if (IMEinline[j] >= ZI8_CODE_TONES_1 &&
                            IMEinline[j] <= ZI8_CODE_TONES_5 /* && j==IMEprediction-1 */ )
                        {
                            switch (IMEinline[j])
                            {
                                case 0xf431:
                                    iChar = 0x002D; /* '-' */
                                    break;
                                case 0xf432:
                                    iChar = 0x02CA;
                                    break;
                                case 0xf433:
                                    iChar = 0x02C7;
                                    break;
                                case 0xf434:
                                    iChar = 0x02CB;
                                    break;
                                case 0xf435:
                                    iChar = 0x02D9;
                                    break;

                            }
                            gui_single_line_input_box_insert_character(&ziCompositionArea, iChar);
                        }
                        else
                        {
                            if (IMEinline[j] == ZI8_CODE_MORE)
                            {
                                gui_single_line_input_box_insert_character(&ziCompositionArea, 0x2026);
                            }
                            else
                            {
                            #ifdef __MMI_ZI_V7__
                                gui_single_line_input_box_insert_character(
                                    &ziCompositionArea,
                                    (UI_character_type) ( IMEinline[j] - 0xf300));
                            #else 
                                gui_single_line_input_box_insert_character(
                                    &ziCompositionArea,
                                    (UI_character_type) (IMEinline[j] - 0xf400));
                            #endif 
                            }
                        }
                        break;

                }

                j++;
            }
            gui_single_line_input_box_insert_character(&ziCompositionArea, 0x20);

            ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
            ziCompositionArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

        #ifdef MMI_LOW_MEMORY_PHONE     /* Vandana added for spacing chars in the symbol window for Stroke */
            if (IMEmethod == INPUT_EZI_STROKE)
            {
                ziCompositionArea.text_x = 10;
            }
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            gui_show_single_line_input_box(&ziCompositionArea);
            /* draw one dotted line */
            /*
             * gui_reset_clip();
             * for(i= ziCompositionArea.x; i <(ziCompositionArea.x+ziCompositionArea.width); i++)
             * {
             * if((i%3) != 0)
             * gui_putpixel(i, ziCompositionArea.y+ziCompositionArea.height-1, gui_color(0,0,0));
             * }
             */
            gui_reset_clip();
            gui_fill_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y, ziCompositionArea.x, ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
#if defined(MMI_LOW_MEMORY_PHONE) && defined(__MMI_MAINLCD_128X128__)
                               gui_color(0, 0, 0)
#else
                               gui_color(182, 189, 210)
#endif
        #else 
                               WHITE
        #endif 
                );

#ifdef MMI_LOW_MEMORY_PHONE   
#ifndef __MMI_MAINLCD_128X128__
            gui_fill_rectangle(ziCompositionArea.x + ziCompositionArea.width,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(182, 189, 210)
        #else 
                               WHITE
        #endif 
                );

            gui_draw_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height-1, //pmt00097
        #if !defined(MONO_LCD)
                               gui_color(0, 0, 0)
        #else 
                               BLACK
        #endif 
                );
#endif	/* __MMI_MAINLCD_128X128__ */
#else	/* MMI_LOW_MEMORY_PHONE*/

    gui_fill_rectangle(ziCompositionArea.x + ziCompositionArea.width,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(182, 189, 210)
        #else 
                               WHITE
        #endif 
                );

            gui_draw_rectangle(ziCompositionArea.x - 7,
                               ziCompositionArea.y,
                               ziCompositionArea.x + ziCompositionArea.width + 6,
                               ziCompositionArea.y + ziCompositionArea.height,
        #if !defined(MONO_LCD)
                               gui_color(0, 0, 0)
        #else 
                               BLACK
        #endif 
                );
#endif	/* MMI_LOW_MEMORY_PHONE */
	
        }

        /* draw candidate window */
        if (IMEbValidCandidates && (IMEcandIndex != 0xff))
        {
            /* update candinates selection input box parameters */
            if (ziCandidateArea.text_length > ENCODING_LENGTH)
            {
                gui_single_line_input_box_delete_all(&ziCandidateArea);
            }

            IMEcandidateBuffer[IMEcandCount] = 0;
            gui_single_line_input_box_insert_string(&ziCandidateArea, IMEcandidateBuffer, 0);

            cursorPosition = ((ZI8LONG) ziCandidateArea.current_text_p - (ZI8LONG) ziCandidateArea.text) / 2;
            cursorPosition--;
            if (IMEcandIndex > (cursorPosition))
            {
                while (IMEcandIndex > cursorPosition)
                {
                    gui_single_line_input_box_next(&ziCandidateArea);
                    cursorPosition++;
                }
            }
            else if (IMEcandIndex < cursorPosition)
            {
                while (IMEcandIndex < cursorPosition)
                {
                    gui_single_line_input_box_previous(&ziCandidateArea);
                    cursorPosition--;
                }
            }
            ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            current_character =
                (ZI8WCHAR) * (ziCandidateArea.current_text_p -
                              2) | (ZI8WCHAR) (*(ziCandidateArea.current_text_p - 1)) << 8;
            if (current_character >= 0xF010 && current_character <= 0xF404)     /* UCS2 range of components */
            {
                ziCandidateArea.selection_color = MMI_ZI_COMPONENT_SELECTOR_COLOR;
                ziCandidateArea.selection_text_color = MMI_ZI_COMPONENT_SELECTION_TXT_COLOR;
            }
            else
            {
            #if 0
/* under construction !*/
/* under construction !*/
            #endif /* 0 */ 
                ZiSetCandidateWindowCurrentTheme();

            }
            /* PMT Dara 24/11/2k4 added for the resizing of candidate window */
        #ifdef MMI_LOW_MEMORY_PHONE
            if (CompositionWindowHideFlag)
            {
                if (CharacterInsertedFlag)
                {
                    ziCandidateArea.text_gap = 2;
                    ziCandidateArea.x = 0;
#ifdef __MMI_MAINLCD_128X128__
                   gui_resize_single_line_input_box(&ziCandidateArea, 122, 18);
#else	/* __MMI_MAINLCD_128X128__ */
                    gui_resize_single_line_input_box(&ziCandidateArea, (UI_device_width - ziCandidateArea.x - 8), MMI_multitap_height); //pmt00097
#endif	/* __MMI_MAINLCD_128X128__ */
                #ifdef MMI_LOW_MEMORY_PHONE
                    ziFlagRSK = 1;
                #endif 
                }
                else
                {
                    ziCandidateArea.text_gap = 1;
#ifdef __MMI_MAINLCD_128X128__
                   ziCandidateArea.x = 64;
                    gui_resize_single_line_input_box(&ziCandidateArea, 63, 18);
#else	/* __MMI_MAINLCD_128X128__ */
                    ziCandidateArea.x = ziCompositionArea.y + ziCompositionArea.height -3; 
                    gui_resize_single_line_input_box(&ziCandidateArea, (UI_device_width - ziCandidateArea.x - 8), MMI_multitap_height); //pmt00097
#endif	/* __MMI_MAINLCD_128X128__ */
                }
                CharacterInsertedFlag = 0;
                gui_show_single_line_input_box(&ziCandidateArea);
            }
            else
            {
                ziCandidateArea.text_gap = 1;
#ifdef __MMI_MAINLCD_128X128__
                ziCandidateArea.x = 64;
                gui_resize_single_line_input_box(&ziCandidateArea, 63, 18);
#else	/* __MMI_MAINLCD_128X128__ */
                ziCandidateArea.x = ziCompositionArea.y + ziCompositionArea.height - 3; 
                gui_resize_single_line_input_box(&ziCandidateArea, (UI_device_width - ziCandidateArea.x - 8), MMI_multitap_height); //pmt00097
#endif	/* __MMI_MAINLCD_128X128__ */
                gui_show_single_line_input_box(&ziCandidateArea);
            }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            gui_reset_clip();
        #if defined (UI_SMALL_CATEGORY_EDITOR)
            if (g_small_editor_category_present)
            {
                gui_fill_rectangle(
                    ziCandidateArea.x,
                    ziCandidateArea.y,
                    ziCandidateArea.x + ziCandidateArea.width - 1,
                    ziCandidateArea.y + ziCandidateArea.height - 1,
                    ziCandidateArea.normal_filler->c);
            }
            else
        #endif /* defined (UI_SMALL_CATEGORY_EDITOR) */ /* UI_SMALL_EDITOR_SCREEN */
                gui_fill_rectangle(
                    0,
                    ziCandidateArea.y,
                    UI_device_width,
                    ziCandidateArea.y + ziCandidateArea.height,
                    ziCandidateArea.normal_filler->c);
            gui_show_single_line_input_box(&ziCandidateArea);
        #endif /* MMI_LOW_MEMORY_PHONE */ 
            /* draw the arrow to infor that user can press arrow left or right to select desired character */
            gui_reset_clip();
            /* R */
            if (IMEcandIndex == 0 && IMEfirstCandidate == 0 && IMEcandCount > 1)
            {
            #ifdef MMI_LOW_MEMORY_PHONE
                draw_resizeable_arrow(ziCandidateArea.x + ziCandidateArea.width, ziCandidateArea.y, 1,
            #if !defined(MONO_LCD)
                                      gui_color(0, 0, 0)
            #else 
                                      BLACK
            #endif 
                                      , 4, 7);

            #else /* MMI_LOW_MEMORY_PHONE */ 
                draw_arrow(ziCandidateArea.x + ziCandidateArea.width + 2, ziCandidateArea.y + 3, 1,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            #endif /* MMI_LOW_MEMORY_PHONE */ 
            }
            //L
            else if (((IMEcandIndex == IMEcandCount - 1) && IMEcandCount < candidate_buffer_size &&
                /* MBJ Hongyu Guo 2007/03/30 added for fix left arrow display issue when only one candidate */
                    ((IMEcandCount > 1) || (IMEcandCount == 1 && IMEfirstCandidate > 0)) &&
                /* MBJ end */
                    (IMEcandCount != (IMEmaxCols/2)) ) || ziNoDrawCandidateRightArrowSymbol)
            {
            #ifdef MMI_LOW_MEMORY_PHONE
                draw_resizeable_arrow(ziCandidateArea.x + ziCandidateArea.width, ziCandidateArea.y, 0,
            #if !defined(MONO_LCD)
                                      gui_color(0, 0, 0)
            #else 
                                      BLACK
            #endif 
                                      , 4, 7);

            #else /* MMI_LOW_MEMORY_PHONE */ 
                draw_arrow(ziCandidateArea.x - 9, ziCandidateArea.y + 3, 0,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            #endif /* MMI_LOW_MEMORY_PHONE */ 
            }
            /* L and R */
            else if (IMEcandCount > 1)
            {
            #ifdef MMI_LOW_MEMORY_PHONE
                draw_resizeable_arrow(ziCandidateArea.x + ziCandidateArea.width, ziCandidateArea.y, 1,
            #if !defined(MONO_LCD)
                                      gui_color(0, 0, 0)
            #else 
                                      BLACK
            #endif 
                                      , 4, 7);

                draw_resizeable_arrow(ziCandidateArea.x + ziCandidateArea.width, ziCandidateArea.y + 6, 0,
            #if !defined(MONO_LCD)
                                      gui_color(0, 0, 0)
            #else 
                                      BLACK
            #endif 
                                      , 4, 7);
            #else /* MMI_LOW_MEMORY_PHONE */ 
                draw_arrow(ziCandidateArea.x - 9, ziCandidateArea.y + 3, 0,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
                draw_arrow(ziCandidateArea.x + ziCandidateArea.width + 2, ziCandidateArea.y + 3, 1,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            #endif /* MMI_LOW_MEMORY_PHONE */ 

            }

        }
        else if (IMEbValidCandidates)
        {
        #if 0
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            ZiSetCandidateWindowCurrentTheme();

            /* update candinates selection input box parameters */
            if (ziCandidateArea.text_length > ENCODING_LENGTH)
            {
                gui_single_line_input_box_delete_all(&ziCandidateArea);
            }

            IMEcandidateBuffer[IMEcandCount] = 0;
            gui_single_line_input_box_insert_string(&ziCandidateArea, IMEcandidateBuffer, 0);

            ziCandidateArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_STATE_MULTITAP;
            ziCandidateArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            /* PMT Dara 24/11/2k4 added for the resizing of candiadate window */
        #ifdef MMI_LOW_MEMORY_PHONE
            //                      if(!CompositionWindowHideFlag) 
            //                      {
            ziCandidateArea.text_gap = 1;
#ifdef __MMI_MAINLCD_128X128__
            ziCandidateArea.x = 64;
            gui_resize_single_line_input_box(&ziCandidateArea, 63, 18);
#else /* __MMI_MAINLCD_128X128__ */
            ziCandidateArea.x = 53;
            gui_resize_single_line_input_box(&ziCandidateArea, 43, MMI_multitap_height); //pmt00097
#endif /* __MMI_MAINLCD_128X128__ */
            gui_show_single_line_input_box(&ziCandidateArea);
            //                      }
            //                      else 
            //                      {       ziCandidateArea.text_gap=2;
            //                              gui_show_single_line_input_box(&ziCandidateArea);
            //                      }
        #else /* MMI_LOW_MEMORY_PHONE */ 
            /* PMT end */
            gui_reset_clip();
        #if defined (UI_SMALL_CATEGORY_EDITOR)
            if (g_small_editor_category_present)
            {
                gui_fill_rectangle(
                    ziCandidateArea.x,
                    ziCandidateArea.y,
                    ziCandidateArea.x + ziCandidateArea.width - 1,
                    ziCandidateArea.y + ziCandidateArea.height - 1,
                    ziCandidateArea.normal_filler->c);
            }
            else
        #endif /* defined (UI_SMALL_CATEGORY_EDITOR) */ /* UI_SMALL_EDITOR_SCREEN */
                gui_fill_rectangle(
                    0,
                    ziCandidateArea.y,
                    UI_device_width,
                    ziCandidateArea.y + ziCandidateArea.height,
                    ziCandidateArea.normal_filler->c);
            gui_show_single_line_input_box(&ziCandidateArea);
        #endif /* MMI_LOW_MEMORY_PHONE */ 

            /* draw the arrow to infor that user can press arrow left or right to select desired character */
            gui_reset_clip();
            /* R */
            if ((IMEcandIndex == 0 && IMEfirstCandidate == 0 && IMEcandCount > 1))
            {
                draw_arrow(ziCandidateArea.x + ziCandidateArea.width + 2, ziCandidateArea.y + 3, 1,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            }
            //L
            else if (((IMEcandIndex == IMEcandCount - 1) && IMEcandCount < candidate_buffer_size && IMEcandCount > 1 && (IMEcandCount != (IMEmaxCols/2)) ) ||
                     ziNoDrawCandidateRightArrowSymbol)
            {
                draw_arrow(ziCandidateArea.x - 9, ziCandidateArea.y + 3, 0,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            }
            else if (IMEcandCount > 1)
            {
            #ifdef MMI_LOW_MEMORY_PHONE
            #else /* MMI_LOW_MEMORY_PHONE */ 
                draw_arrow(ziCandidateArea.x - 9, ziCandidateArea.y + 3, 0,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
                draw_arrow(ziCandidateArea.x + ziCandidateArea.width + 2, ziCandidateArea.y + 3, 1,
            #if !defined(MONO_LCD)
                           gui_color(255, 0, 0)
            #else 
                           BLACK
            #endif 
                    );
            #endif /* MMI_LOW_MEMORY_PHONE */ 
            }

        }
        /* for valid Thai/English word candidates */
        else if (IMEbValidAlphaWords)
        {
            if (1)
            {
                /* update candinates selection input box parameters */
                if (ziCandidateArea.text_length > ENCODING_LENGTH)
                {
                    gui_single_line_input_box_delete_all(&ziCandidateArea);
                }

                for (i = 0; i < IMEalphaCount; i++)
                {

                    switch (IMEmethod)
                    {
                        case INPUT_EZI_THAI:
                            //MTK Terry for Scorpio_plus#261
                            //gui_single_line_input_box_insert_string(&ziCandidateArea,IMEpPhoneticPtr[i], 0);
                            break;
                    }
                    //MTK Terry for Scorpio_plus#261
                    //gui_single_line_input_box_insert_character(&ziCandidateArea,0x20);

                }
                gui_single_line_input_box_goto_first_character(&ziCandidateArea);
                /* ziPhoneticIndex = 0; */

            }

            if (1)
            {
                gui_single_line_input_box_highlight_cursor_number(&ziCandidateArea, IMEelementCount);
                ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                ziCandidateArea.flags |= UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            }
            else
            {
                ziCandidateArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
                ziCandidateArea.flags &= ~UI_SINGLE_LINE_INPUT_BOX_FULL_HEIGHT_BLOCK_CURSOR;

            }
            /* gui_show_single_line_input_box(&ziCandidateArea); */

        }
        else
        {
            /* hide_multitap(); */
        #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
            {
            #if !defined(__MMI_FULL_SCREEN_EDITOR__)
                hide_multitap();
            #endif 
                gui_show_EMS_input_box(&MMI_EMS_inputbox);
            }
            else
        #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
            {
            #if !defined(__MMI_FULL_SCREEN_EDITOR__)
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //set_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
                hide_multitap();
                //START FARHADPMT 20050812
                //PMT START FARHAD 20051006
                //#ifdef __MMI_UI_STYLE_14x14__
                //reset_multiline_infobar();
                //#endif
                //PMT END FARHAD 20051006
                //END FARHADPMT 20050812
            #endif /* !defined(__MMI_FULL_SCREEN_EDITOR__) */ 
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            }
            //else if(ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG)
            //  gui_show_single_line_input_box(&MMI_singleline_inputbox);
            else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
            {
                gui_show_multi_line_input_box(&MMI_multiline_inputbox);
            }

        }

        /* MTK Terry for __MMI_POPUP_REACH_MAX_LENGTH_MSG__ issues */
    #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
        {
            ZiInputBoxScreenStateChange();
        #ifndef __MMI_UI_STYLE_14x14__
            wgui_EMS_redraw_remaining_characters_display();
        #endif 
        }
        else
    #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
        {
            ZiInputBoxScreenStateChange();
        #ifndef __MMI_UI_STYLE_14x14__
            wgui_redraw_remaining_characters_display();
        #endif 
        }
        else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
        {
            ZiInputBoxScreenStateChange();
        }
        else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
        {
            ZiInputBoxScreenStateChange();
            wgui_redraw_remaining_characters_display();
        }
        /* MTK end */

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_multiline_inputbox_x,
            MMI_multiline_inputbox_y,
            MMI_multiline_inputbox_width,
            UI_device_height - (MMI_title_y + MMI_title_height) - MMI_button_bar_height);

        ziFrameCounterForEMSEditor = 0;
        gui_start_timer(ZI_FRAME_SKIP_TIMEOUT, ZiDisplayForEmsEditorEndFrame);
        ziFrameTimerStart = ZI8TRUE;
        /* StartMyTimerInt(ZI_FRAME_TIMER, ZI_FRAME_SKIP_TIMEOUT, (oslTimerFuncPtr) ZiDisplayForEmsEditorEndFrame, 0); */

    #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
        /* to restore the EMS text format state */
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
        {
            wgui_EMS_text_format = MMI_EMS_inputbox.text_format;
        }
    #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 

    }
    UI_UNUSED_PARAMETER(count);
}


/*****************************************************************************
 * FUNCTION
 *  ZiChangeInputMethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputMode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ZiChangeInputMethod(INPUT_MODE inputMode)
{
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ZI8_LANGUAGE_ENTRY *Zi8StaticLanguageTable;
    ZI8BOOL ziReturnStatus;
#endif /* defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ZiSetCandidateWindowCurrentTheme();

    IMEnumOfChars = 0;
    IMEcurPos = 0;
    labelSoftL[0] = 0;
    labelSoftR[0] = 0;
    IMEactive = ZI8FALSE;
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    IMEbFocusOnPhonetic = ZI8FALSE;
    ziEngWordLen = 0;

#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
    switch (inputMode)
    {

        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_TR_BOPOMO:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_MMI_MULTITAP_BPMF:
        case INPUT_MODE_MMI_TR_STROKE:
    #if defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_TAIWAN__)
            Zi8StaticLanguageTable = gIMELDBArray[ZI_TR_CHINESE];
            ziReturnStatus = Zi8InitializeDynamic(Zi8StaticLanguageTable);
    #endif /* defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_TAIWAN__) */ 
            break;
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
        case INPUT_MODE_MMI_SM_STROKE:
    #if defined(__MMI_ZI_SM_CHINESE__)
            Zi8StaticLanguageTable = gIMELDBArray[ZI_SIM_CHINESE];
            ziReturnStatus = Zi8InitializeDynamic(Zi8StaticLanguageTable);
    #endif /* defined(__MMI_ZI_SM_CHINESE__) */ 
            break;
    }
#endif /* defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__) */ 

    switch (inputMode)
    {
        case INPUT_MODE_MMI_MULTITAP_BPMF:
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
            iStepID = PHONETIC_MULTITAP;
            IMEmethod = INPUT_EZI_MULTITAP_BOPOMOFO;
            IMEmethodZH = INPUT_EZI_MULTITAP_BOPOMOFO;
            IMEmethodLast = INPUT_EZI_MULTITAP_BOPOMOFO;
            IMEsubLanguage = ZI8_SUBLANG_ZH_TW;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_MULTITAP_BOPOMOFO();
            break;
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
            iStepID = PHONETIC_MULTITAP;
            IMEmethod = INPUT_EZI_MULTITAP_PINYIN;
            IMEmethodZH = INPUT_EZI_MULTITAP_PINYIN;
            IMEmethodLast = INPUT_EZI_MULTITAP_PINYIN;
            IMEsubLanguage = ZI8_SUBLANG_ZH;    /* ZI8_SUBLANG_ZH_HK; */
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_MULTITAP_PINYIN();
            break;

        case INPUT_MODE_TR_BOPOMO:
            iStepID = PHONETIC_2_STEPS;
            IMEmethod = INPUT_EZI_BOPOMOFO;
            IMEmethodZH = INPUT_EZI_BOPOMOFO;
            IMEmethodLast = INPUT_EZI_BOPOMOFO;
            IMEsubLanguage = ZI8_SUBLANG_ZH_TW;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_BOPOMOFO();
            break;
        case INPUT_MODE_SM_PINYIN:
            iStepID = PHONETIC_2_STEPS;
            IMEmethod = INPUT_EZI_PINYIN;
            IMEmethodZH = INPUT_EZI_PINYIN;
            IMEmethodLast = INPUT_EZI_PINYIN;
            IMEsubLanguage = ZI8_SUBLANG_ZH;    /* ZI8_SUBLANG_ZH_HK; */
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_PINYIN();
            break;

        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_MMI_TR_STROKE:
            IMEmethod = INPUT_EZI_STROKE;
            IMEmethodZH = INPUT_EZI_STROKE;
            IMEmethodLast = INPUT_EZI_STROKE;
            IMEsubLanguage = ZI8_SUBLANG_ZH_TW;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_STROKE();
            break;

        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_MMI_SM_STROKE:
            IMEmethod = INPUT_EZI_STROKE;
            IMEmethodZH = INPUT_EZI_STROKE;
            IMEmethodLast = INPUT_EZI_STROKE;
            IMEsubLanguage = ZI8_SUBLANG_ZH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_STROKE();
            break;

        case INPUT_MODE_SMART_UPPERCASE_ABC:
            IMEmethod = INPUT_EZI_ABC;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_ABC;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_EN;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_ABC:
            IMEmethod = INPUT_EZI_ABC;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_ABC;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_EN;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_THAI:
            IMEmethod = INPUT_EZI_THAI;
            IMEmethodLast = INPUT_EZI_THAI;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_THAI();
            break;
    #ifdef __MMI_ZI_ARABIC__        
        case INPUT_MODE_SMART_ARABIC:
            IMEmethod = INPUT_EZI_ARABIC;
            IMEmethodLast = INPUT_EZI_ARABIC;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_ARABIC();

            break;
    #endif /* __MMI_ZI_ARABIC__ */ 

    #ifdef __MMI_ZI_PERSIAN__       
        case INPUT_MODE_SMART_PERSIAN:
            IMEmethod = INPUT_EZI_PERSIAN;
            IMEmethodLast = INPUT_EZI_PERSIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_PERSIAN();

            break;
    #endif /* __MMI_ZI_PERSIAN__ */ 

    #ifdef __MMI_ZI_HEBREW__        
        case INPUT_MODE_SMART_HEBREW:
            IMEmethod = INPUT_EZI_HEBREW;
            IMEmethodLast = INPUT_EZI_HEBREW;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_HEBREW();

            break;
    #endif /* __MMI_ZI_HEBREW__ */ 
    #ifdef __MMI_ZI_HINDI__ /* can be remove while checking Arabic into GPRS branch */
        case INPUT_MODE_SMART_HINDI:
            IMEmethod = INPUT_EZI_HINDI;
            IMEmethodLast = INPUT_EZI_HINDI;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEstartEZI_HINDI();

            break;
    #endif /* __MMI_ZI_HINDI__ */ 
    #if defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__)
        case INPUT_MODE_SMART_UPPERCASE_RUSSIAN:
            IMEmethod = INPUT_EZI_RUSSIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_RUSSIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_RU;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_RUSSIAN:
            IMEmethod = INPUT_EZI_RUSSIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_RUSSIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_RU;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_RUSSIAN__) || defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) */ 
    #if defined(__MMI_ZI_BULGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_BULGARIAN:
               IMEmethod   = INPUT_EZI_BULGARIAN;
               IMEletterCase = ZI8_CASE_UPPER;
               IMEmethodLast = INPUT_EZI_BULGARIAN;
               bNoComponent = ZI8FALSE;
               bComponentOn2ndKey = ZI8FALSE;
               bNoRadicals = ZI8TRUE;
               IMEalphaLangID = ALPHA_LANG_BG;
               IMEstartEZI_ABC();
             break;

        case INPUT_MODE_SMART_LOWERCASE_BULGARIAN:
               IMEmethod   = INPUT_EZI_BULGARIAN;
               IMEletterCase = ZI8_CASE_LOWER;
               IMEmethodLast = INPUT_EZI_BULGARIAN;
               bNoComponent = ZI8FALSE;
               bComponentOn2ndKey = ZI8FALSE;
               bNoRadicals = ZI8TRUE;
               IMEalphaLangID = ALPHA_LANG_BG;
               IMEstartEZI_ABC();
             break;
    #endif
    #if defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__)
        case INPUT_MODE_SMART_UPPERCASE_FRENCH:
            IMEmethod = INPUT_EZI_FRENCH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_FRENCH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_FR;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_FRENCH:
            IMEmethod = INPUT_EZI_FRENCH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_FRENCH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_FR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) */ 
    #if defined(__MMI_ZI_GERMAN__)
        case INPUT_MODE_SMART_UPPERCASE_GERMAN:
            IMEmethod = INPUT_EZI_GERMAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_GERMAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_DE;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_GERMAN:
            IMEmethod = INPUT_EZI_GERMAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_GERMAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_DE;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_GERMAN__) */ 
    #if defined(__MMI_ZI_ITALIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ITALIAN:
            IMEmethod = INPUT_EZI_ITALIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_ITALIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_IT;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_ITALIAN:
            IMEmethod = INPUT_EZI_ITALIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_ITALIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_IT;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_ITALIAN__) */ 
    #if defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
        case INPUT_MODE_SMART_UPPERCASE_SPANISH:
            IMEmethod = INPUT_EZI_SPANISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_SPANISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_ES;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_SPANISH:
            IMEmethod = INPUT_EZI_SPANISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_SPANISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_ES;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__) */ 
    #if defined(__MMI_ZI_TURKISH__)
        case INPUT_MODE_SMART_UPPERCASE_TURKISH:
            IMEmethod = INPUT_EZI_TURKISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_TURKISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_TR;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_TURKISH:
            IMEmethod = INPUT_EZI_TURKISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_TURKISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_TR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_TURKISH__) */ 
    #if defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__)
        case INPUT_MODE_SMART_UPPERCASE_PORTUGUESE:
            IMEmethod = INPUT_EZI_PORTUGUESE;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_PORTUGUESE;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_PT;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_PORTUGUESE:
            IMEmethod = INPUT_EZI_PORTUGUESE;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_PORTUGUESE;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_PT;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_EU_PORTUGUESE__) || defined(__MMI_ZI_SA_PORTUGUESE__) || defined(__MMI_ZI_BZ_PORTUGUESE__) */ 
    #if defined(__MMI_ZI_INDONESIAN__)
        case INPUT_MODE_SMART_UPPERCASE_INDONESIAN:
            IMEmethod = INPUT_EZI_INDONESIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_INDONESIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_ID;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_INDONESIAN:
            IMEmethod = INPUT_EZI_INDONESIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_INDONESIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_ID;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_INDONESIAN__) */ 
    #if defined(__MMI_ZI_MALAY__)
        case INPUT_MODE_SMART_UPPERCASE_MALAY:
            IMEmethod = INPUT_EZI_MALAY;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_MALAY;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_MS;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_MALAY:
            IMEmethod = INPUT_EZI_MALAY;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_MALAY;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_MS;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_MALAY__) */ 
    #if defined(__MMI_ZI_VIETNAMESE__)
        case INPUT_MODE_SMART_UPPERCASE_VIETNAMESE:
            IMEmethod = INPUT_EZI_VIETNAMESE;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_VIETNAMESE;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_VI;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_VIETNAMESE:
            IMEmethod = INPUT_EZI_VIETNAMESE;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_VIETNAMESE;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_VI;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_VIETNAMESE__) */ 
    #if defined(__MMI_ZI_SLOVAK__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVAK:
            IMEmethod = INPUT_EZI_SLOVAK;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_SLOVAK;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SK;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_SLOVAK:
            IMEmethod = INPUT_EZI_SLOVAK;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_SLOVAK;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SK;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SLOVAK__) */ 
    #if defined(__MMI_ZI_DUTCH__)
        case INPUT_MODE_SMART_UPPERCASE_DUTCH:
            IMEmethod = INPUT_EZI_DUTCH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_DUTCH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_NL;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_DUTCH:
            IMEmethod = INPUT_EZI_DUTCH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_DUTCH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_NL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_DUTCH__) */ 
    #if defined(__MMI_ZI_SWEDISH__)
        case INPUT_MODE_SMART_UPPERCASE_SWEDISH:
            IMEmethod = INPUT_EZI_SWEDISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_SWEDISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SV;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_SWEDISH:
            IMEmethod = INPUT_EZI_SWEDISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_SWEDISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SV;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SWEDISH__) */ 
    #if defined(__MMI_ZI_CROATIAN__)
        case INPUT_MODE_SMART_UPPERCASE_CROATIAN:
            IMEmethod = INPUT_EZI_CROATIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_CROATIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_HR;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_CROATIAN:
            IMEmethod = INPUT_EZI_CROATIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_CROATIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_HR;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CROATIAN__) */ 
    #if defined(__MMI_ZI_ROMANIAN__)
        case INPUT_MODE_SMART_UPPERCASE_ROMANIAN:
            IMEmethod = INPUT_EZI_ROMANIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_ROMANIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_RO;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_ROMANIAN:
            IMEmethod = INPUT_EZI_ROMANIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_ROMANIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_RO;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_ROMANIAN__) */ 
    #if defined(__MMI_ZI_POLISH__)
        case INPUT_MODE_SMART_UPPERCASE_POLISH:
            IMEmethod = INPUT_EZI_POLISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_POLISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_PL;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_POLISH:
            IMEmethod = INPUT_EZI_POLISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_POLISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_PL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_POLISH__) */ 
    #if defined(__MMI_ZI_NORWEGIAN__)
        case INPUT_MODE_SMART_UPPERCASE_NORWEGIAN:
            IMEmethod = INPUT_EZI_NORWEGIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_NORWEGIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_NO;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_NORWEGIAN:
            IMEmethod = INPUT_EZI_NORWEGIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_NORWEGIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_NO;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_NORWEGIAN__) */ 
    #if defined(__MMI_ZI_SLOVENIAN__)
        case INPUT_MODE_SMART_UPPERCASE_SLOVENIAN:
            IMEmethod = INPUT_EZI_SLOVENIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_SLOVENIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SL;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_SLOVENIAN:
            IMEmethod = INPUT_EZI_SLOVENIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_SLOVENIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_SL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_SLOVENIAN__) */ 
    #if defined(__MMI_ZI_GREEK__)
        case INPUT_MODE_SMART_UPPERCASE_GREEK:
            IMEmethod = INPUT_EZI_GREEK;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_GREEK;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_EL;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_GREEK:
            IMEmethod = INPUT_EZI_GREEK;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_GREEK;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_EL;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_GREEK__) */ 
    #if defined(__MMI_ZI_CZECH__)
        case INPUT_MODE_SMART_UPPERCASE_CZECH:
            IMEmethod = INPUT_EZI_CZECH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_CZECH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_CZ;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_CZECH:
            IMEmethod = INPUT_EZI_CZECH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_CZECH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_CZ;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_CZECH__) */ 
    #if defined(__MMI_ZI_FINNISH__)
        case INPUT_MODE_SMART_UPPERCASE_FINNISH:
            IMEmethod = INPUT_EZI_FINNISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_FINNISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_FI;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_FINNISH:
            IMEmethod = INPUT_EZI_FINNISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_FINNISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_FI;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_FINNISH__) */ 
    #if defined(__MMI_ZI_DANISH__)
        case INPUT_MODE_SMART_UPPERCASE_DANISH:
            IMEmethod = INPUT_EZI_DANISH;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_DANISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_DA;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_DANISH:
            IMEmethod = INPUT_EZI_DANISH;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_DANISH;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_DA;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_DANISH__) */ 
    #if defined(__MMI_ZI_HUNGARIAN__)
        case INPUT_MODE_SMART_UPPERCASE_HUNGARIAN:
            IMEmethod = INPUT_EZI_HUNGARIAN;
            IMEletterCase = ZI8_CASE_UPPER;
            IMEmethodLast = INPUT_EZI_HUNGARIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_HU;
            IMEstartEZI_ABC();
            break;

        case INPUT_MODE_SMART_LOWERCASE_HUNGARIAN:
            IMEmethod = INPUT_EZI_HUNGARIAN;
            IMEletterCase = ZI8_CASE_LOWER;
            IMEmethodLast = INPUT_EZI_HUNGARIAN;
            bNoComponent = ZI8FALSE;
            bComponentOn2ndKey = ZI8FALSE;
            bNoRadicals = ZI8TRUE;
            IMEalphaLangID = ALPHA_LANG_HU;
            IMEstartEZI_ABC();
            break;
    #endif /* defined(__MMI_ZI_HUNGARIAN__) */ 
    }
#if defined(__MMI_ZI_DYNAMIC_LAN_LIB_INIT__)
    /* Zi8InitializeDynamic(ziLanguageLibs); */
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ZiClearKeyStarAndPoundHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiClearKeyStarAndPoundHandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (keyCode = KEY_STAR; keyCode < KEY_POUND; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            ClearKeyHandler(keyCode, keyType);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZiClearKeyNavigationHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiClearKeyNavigationHandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (keyCode = KEY_UP_ARROW; keyCode < KEY_RIGHT_ARROW; keyCode++)
    {
        /* PMT Dara add 24/11/2k4 to avoid clearing key handler for end key */
        switch (keyCode)
        {
            case KEY_UP_ARROW:
            case KEY_DOWN_ARROW:
            case KEY_RIGHT_ARROW:
            case KEY_LEFT_ARROW:
            {
                /* PMT Dara End */
                for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
                {
                    ClearKeyHandler(keyCode, keyType);
                }
            }
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZiClearArrowKeyLeftHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiClearArrowKeyLeftHandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (keyCode = KEY_LEFT_ARROW; keyCode < KEY_LEFT_ARROW; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            ClearKeyHandler(keyCode, keyType);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZiClearArrowKeyRightHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiClearArrowKeyRightHandler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (keyCode = KEY_RIGHT_ARROW; keyCode < KEY_RIGHT_ARROW; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            ClearKeyHandler(keyCode, keyType);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZiClearKey0To9Handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiClearKey0To9Handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0;
    U16 keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Vandana Bug fix */
    for (keyCode = KEY_0; keyCode <= KEY_9; keyCode++)
    {
        for (keyType = 0; keyType < MAX_KEY_TYPE; keyType++)
        {
            ClearKeyHandler(keyCode, keyType);
        }
    }

}

#if defined(__MTK_TARGET__)


/*****************************************************************************
 * FUNCTION
 *  wcslen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arrOut      [?]     
 * RETURNS
 *  
 *****************************************************************************/
int wcslen(char *arrOut)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = UCS2Strlen(arrOut);
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  wcscat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strDestination      [?]     
 *  strSource           [?]     
 * RETURNS
 *  
 *****************************************************************************/
char wcscat(char *strDestination, char *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return *UCS2Strcat(strDestination, strSource);
}


/*****************************************************************************
 * FUNCTION
 *  wcscpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strDestination      [?]     
 *  strSource           [?]     
 * RETURNS
 *  
 *****************************************************************************/
char wcscpy(char *strDestination, char *strSource)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return *UCS2Strcpy(strDestination, strSource);
}
#endif /* defined(__MTK_TARGET__) */ 


/*****************************************************************************
 * FUNCTION
 *  ZI_towupper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ZI8WCHAR ZI_towupper(ZI8WCHAR wChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wChar >= 97 && wChar <= 122) || (wChar >= 0xe0 && wChar <= 0xf6) || (wChar >= 0xf8 && wChar <= 0xfe) ||
        (wChar >= 0x0430 && wChar <= 0x044f))
    {
        return (wChar - 0x20);
    }
    else if (wChar == 0x0103 || wChar == 0x01A1 || wChar == 0x01B0)
    {
        return (wChar - 1);
    }
    else if (wChar >= 0x0450 && wChar <= 0x045f)
    {
        return (wChar - 0x50);
    }
    else if (wChar == 0x0491)
    {
        return 0x0490;
    }
    else
    {
        return wChar;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZI_towlower
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ZI8WCHAR ZI_towlower(ZI8WCHAR wChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wChar >= 65 && wChar <= 90) || (wChar >= 0xc0 && wChar <= 0xd6) || (wChar >= 0xd8 && wChar <= 0xde) ||
        (wChar >= 0x0410 && wChar <= 0x042f))
    {
        return wChar + 0x20;
    }
    else if (wChar == 0x0102 || wChar == 0x01A0 || wChar == 0x01AF)
    {
        return (wChar + 1);
    }
    else if (wChar >= 0x0400 && wChar <= 0x040f)
    {
        return (wChar + 0x50);
    }
    else if (wChar == 0x0490)
    {
        return 0x0491;
    }
    else
    {
        return wChar;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodEnterSinglelineInputBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodEnterSinglelineInputBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag |= ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG;
    ziFrameCounterForEMSEditor = 0;
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;

}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodExitSinglelineInputBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodExitSinglelineInputBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag &= ~ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG;
    ziFrameCounterForEMSEditor = 0;
    gui_cancel_timer(ZiDisplayForEmsEditorEndFrame);
    ziFrameTimerStart = ZI8FALSE;
    ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_FRAME_TIMER);
    //ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_REQ_TIMER);
    ZiClearKeyStarAndPoundHandler();
    ZiClearKeyNavigationHandler();
    ZiClearKey0To9Handler();
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    ziMultilineEditorHeight = 0;
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    ziEMSEditorHeight = 0;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodEnterCategory5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodEnterCategory5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag |= ZI_IN_CATEGORY_5_FLAG;
    ZiUpdateLSKString();
    ziFrameCounterForEMSEditor = 0;
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;

}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodExitCategory5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodExitCategory5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag &= ~ZI_IN_CATEGORY_5_FLAG;
    ziInputMethodCategoryFlag &= ~ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG;
    ziFrameCounterForEMSEditor = 0;
    ziEngWordLen = 0;
    gui_cancel_timer(ZiDisplayForEmsEditorEndFrame);
    ziFrameTimerStart = ZI8FALSE;
    ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_FRAME_TIMER);
    //ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_REQ_TIMER);
    ZiClearKeyStarAndPoundHandler();
    ZiClearKeyNavigationHandler();
    ZiClearKey0To9Handler();
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    ziMultilineEditorHeight = 0;
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    ziEMSEditorHeight = 0;
#endif 
#ifdef MMI_LOW_MEMORY_PHONE
    ziCandidateArea.text_gap = 1;
#endif 
}

#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodEnterCategory28
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodEnterCategory28(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag |= ZI_IN_CATEGORY_28_FLAG;
    ziFrameCounterForEMSEditor = 0;
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;

}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodExitCategory28
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodExitCategory28(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag &= ~ZI_IN_CATEGORY_28_FLAG;
    ziFrameCounterForEMSEditor = 0;
    ziEngWordLen = 0;
    gui_cancel_timer(ZiDisplayForEmsEditorEndFrame);
    ziFrameTimerStart = ZI8FALSE;
    ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_FRAME_TIMER);
    //ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_REQ_TIMER);
    ZiClearKeyStarAndPoundHandler();
    ZiClearKeyNavigationHandler();
    ZiClearKey0To9Handler();
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    ziMultilineEditorHeight = 0;
    ziEMSEditorHeight = 0;

}
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodEnterInline_Multiline_InputBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodEnterInline_Multiline_InputBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag |= ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG;
    ziFrameCounterForEMSEditor = 0;
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;

}


/*****************************************************************************
 * FUNCTION
 *  ZiInuptMethodExitInline_Multiline_InputBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInuptMethodExitInline_Multiline_InputBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziInputMethodCategoryFlag &= ~ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG;
    ziFrameCounterForEMSEditor = 0;
    gui_cancel_timer(ZiDisplayForEmsEditorEndFrame);
    ziFrameTimerStart = ZI8FALSE;
    ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_FRAME_TIMER);
    //ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_REQ_TIMER);
    ZiClearKeyStarAndPoundHandler();
    ZiClearKeyNavigationHandler();
    ZiClearKey0To9Handler();
    ziPhoneticIndex = 0;
    zifirstPhoneticCandidate = 0;
    ziMultilineEditorHeight = 0;
#if !defined(MONO_LCD)
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    ziEMSEditorHeight = 0;
#endif 
#endif /* !defined(MONO_LCD) */ 

}


/*****************************************************************************
 * FUNCTION
 *  ZiInputBoxScreenStateChange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInputBoxScreenStateChange()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WITH_C_KEY__
    /* clear_right_softkey(); */
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear_left_softkey(); */
    show_softkey_background();
#ifdef __MMI_WITH_C_KEY__
    redraw_right_softkey();
#endif 
    //MTK Terry for RSK overlap problem
    //register_default_hide_softkeys();

#ifdef __MMI_WITH_C_KEY__
    SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(ZiKeyRSKLongPressHandler, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_REPEAT);
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
        set_right_softkey_function(handle_category28_right_softkey_up, KEY_EVENT_UP);
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
    {
        set_right_softkey_function(wgui_handle_inputbox_right_softkey_up, KEY_EVENT_UP);
    }
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
    {
        set_right_softkey_function(wgui_handle_inputbox_right_softkey_up, KEY_EVENT_UP);
    }
#else /* __MMI_WITH_C_KEY__ */ 
    set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
    set_right_softkey_function(ZiKeyRSKLongPressHandler, KEY_EVENT_LONG_PRESS);
#endif /* __MMI_WITH_C_KEY__ */ 

    set_left_softkey_function(ZiKeyLSKPressHandler, KEY_EVENT_UP);
    set_left_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
    set_left_softkey_function(ZiKeyLSKLongPressHandler, KEY_EVENT_LONG_PRESS);

    //redraw the LSK and RSK
    //RSK
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG))
    {
        if (MMI_EMS_inputbox.data == NULL)
        {
            return;
        }
        if (!gui_EMS_inputbox_empty(&MMI_EMS_inputbox))
        {
        #ifdef __MMI_WITH_C_KEY__
            if (category28_RSK_label_clear == 0)
            {
                category28_RSK_label_clear = 1;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (category28_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                category28_RSK_label_clear = 1;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }

            if (IMEbValidPhonetic ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
            else if (IMEbValidCandidates)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
            else
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
        else
        {
        #ifdef __MMI_WITH_C_KEY__
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                category28_RSK_label_clear = 0;
                SetKeyHandler(register_category28_handle_clear_key_up, KEY_CLEAR, KEY_EVENT_DOWN);
                /* SetKeyHandler(UI_dummy_function,KEY_CLEAR,KEY_EVENT_UP); */
            }
            else
            {
                category28_RSK_label_clear = 0;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label(category28_RSK_label_string);
                set_right_softkey_icon(category28_RSK_label_icon);
                redraw_right_softkey();
                category28_RSK_label_clear = 0;
                set_right_softkey_function(register_category28_handle_right_softkey_up, KEY_EVENT_DOWN);
                /* set_right_softkey_function(UI_dummy_function,KEY_EVENT_UP); */
            }
            else
            {
                if (IMEbValidPhonetic ||
                    (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                     ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                      (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                      (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                category28_RSK_label_clear = 0;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
    }
    else
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
    {
        if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
        {
        #ifdef __MMI_WITH_C_KEY__
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_inputbox_RSK_label_clear = 1;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                redraw_right_softkey();
                wgui_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }

            if (IMEbValidPhonetic ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            else if (IMEbValidCandidates)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
            else
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
        else
        {
        #ifdef __MMI_WITH_C_KEY__
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                wgui_inputbox_RSK_label_clear = 0;
                SetKeyHandler(wgui_register_inputbox_handle_clear_key_up, KEY_CLEAR, KEY_EVENT_DOWN);
                /* SetKeyHandler(UI_dummy_function,KEY_CLEAR,KEY_EVENT_UP); */
            }
            else
            {
                wgui_inputbox_RSK_label_clear = 0;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label(wgui_inputbox_RSK_label_string);
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
                wgui_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(wgui_register_inputbox_handle_right_softkey_up, KEY_EVENT_DOWN);
                /* set_right_softkey_function(UI_dummy_function,KEY_EVENT_UP); */
            }
            else
            {
                if (IMEbValidPhonetic ||
                    (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                     ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                      (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                      (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                wgui_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
    {
        if (gui_single_line_input_box_get_text_length(&MMI_singleline_inputbox) > 0)
        {
        #ifdef __MMI_WITH_C_KEY__
            if (wgui_singleline_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_singleline_inputbox_RSK_label_clear = 1;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (wgui_singleline_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                redraw_right_softkey();
                wgui_singleline_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            if (IMEbValidPhonetic ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            else if (IMEbValidCandidates)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
            else
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
        else
        {
        #ifdef __MMI_WITH_C_KEY__
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                wgui_singleline_inputbox_RSK_label_clear = 0;
                /* SetKeyHandler(wgui_register_singleline_inputbox_handle_clear_key_up,KEY_CLEAR,KEY_EVENT_DOWN); */
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
            else
            {
                wgui_singleline_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                if (wgui_singleline_inputbox_RSK_label_clear == 1)
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    if (wgui_inputbox_empty_callback != NULL)
                    {
                        wgui_inputbox_empty_callback();
                    }
                    redraw_right_softkey();
                    wgui_singleline_inputbox_RSK_label_clear = 0;
                    set_right_softkey_function(
                        wgui_register_singleline_inputbox_handle_right_softkey_up,
                        KEY_EVENT_DOWN);
                    set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    if (wgui_inputbox_empty_callback != NULL)
                    {
                        wgui_inputbox_empty_callback();
                    }
                    redraw_right_softkey();
                    wgui_singleline_inputbox_RSK_label_clear = 0;
                    /* wgui_register_inputbox_handle_right_softkey_up(); */
                    set_right_softkey_function(
                        wgui_register_singleline_inputbox_handle_right_softkey_up,
                        KEY_EVENT_DOWN);
                    set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                }
            }
            else
            {
                if (IMEbValidPhonetic ||
                    (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                     ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                      (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                      (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                wgui_singleline_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
    }
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
        {
        #ifdef __MMI_WITH_C_KEY__
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                wgui_inputbox_RSK_label_clear = 1;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
            if (inline_full_screen_edit_changed && !(wgui_inline_list_menu_disable_done))
            {
                set_right_softkey_label(NULL);
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (wgui_inputbox_RSK_label_clear == 0)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
                redraw_right_softkey();
                wgui_inputbox_RSK_label_clear = 1;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            if (IMEbValidPhonetic ||
                (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                 ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                  (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                  (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            else if (IMEbValidCandidates)
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
            else
            {
                set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            register_right_softkey_handler();
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
        else
        {
        #ifdef __MMI_WITH_C_KEY__
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                wgui_inputbox_RSK_label_clear = 0;
                SetKeyHandler(wgui_register_inputbox_handle_clear_key_up, KEY_CLEAR, KEY_EVENT_DOWN);
                /* SetKeyHandler(UI_dummy_function,KEY_CLEAR,KEY_EVENT_UP); */
            }
            else
            {
                wgui_inputbox_RSK_label_clear = 0;
                SetKeyHandler(ZiKeyRSKPressHandler, KEY_CLEAR, KEY_EVENT_DOWN);
                SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            }
            if (inline_full_screen_edit_changed && !(wgui_inline_list_menu_disable_done))
            {
                set_right_softkey_label(NULL);
                set_right_softkey_icon(NULL);
                redraw_right_softkey();
            }
        #else /* __MMI_WITH_C_KEY__ */ 
            if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                  ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                   (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                   (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
            {
                if (inline_full_screen_edit_changed && !(wgui_inline_list_menu_disable_done))
                {
                    set_right_softkey_label(NULL);
                    set_right_softkey_icon(NULL);
                    reset_right_softkey();
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                }
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
                redraw_right_softkey();
                register_right_softkey_handler();
                wgui_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(wgui_register_inputbox_handle_right_softkey_up, KEY_EVENT_DOWN);
                /* set_right_softkey_function(UI_dummy_function,KEY_EVENT_UP); */
            }
            else
            {
                if (IMEbValidPhonetic ||
                    (IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                     ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                      (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                      (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                else
                {
                    set_right_softkey_label((UI_string_type) get_string(STR_GLOBAL_BACK));
                    set_right_softkey_icon(NULL);
                    redraw_right_softkey();
                }
                wgui_inputbox_RSK_label_clear = 0;
                set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
                set_right_softkey_function(ZiKeyRSKPressHandler, KEY_EVENT_DOWN);
            }
            register_right_softkey_handler();
        #endif /* __MMI_WITH_C_KEY__ */ 
        }
    }

    /* LSK */
    switch (labelSoftR[0])
    {
        case 'D':   /* Done => Option */
            set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
            set_left_softkey_icon(NULL);
            register_left_softkey_handler();
            set_left_softkey_function(zi_inputbox_LSK_function, KEY_EVENT_UP);
            set_left_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
            {
                if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                    !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                      ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                       (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                       (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
                    set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
                    set_left_softkey_icon(NULL);
                    redraw_left_softkey();
                    register_left_softkey_handler();
                    SetLeftSoftkeyFunction(EntryInLineMultilineEditorOption, KEY_EVENT_UP);
                #else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
                    set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OK));
                    set_left_softkey_icon(NULL);
                    register_left_softkey_handler();
                    set_left_softkey_function(wgui_inline_edit_DONE_function, KEY_EVENT_UP);
                #endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
                }
            }
            else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
            {
                set_left_softkey_label((UI_string_type) temp_left_softkey_text);
                if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
                {
                    if (wgui_inputbox_not_empty_callback != NULL)
                    {
                        wgui_inputbox_not_empty_callback();
                    }
                }
                else
                {
                    if (wgui_inputbox_empty_callback != NULL)
                    {
                        wgui_inputbox_empty_callback();
                    }
                }
            }
            redraw_left_softkey();
            break;

        case 'S':   /* Select => Select */
            set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_SELECT));
            set_left_softkey_icon(NULL);
            redraw_left_softkey();
            register_left_softkey_handler();
            set_left_softkey_function(ZiKeyLSKPressHandler, KEY_EVENT_UP);
            set_left_softkey_function(ZiKeyLSKLongPressHandler, KEY_EVENT_LONG_PRESS);
            break;

        default:    /* Option */
            set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
            set_left_softkey_icon(NULL);
            register_left_softkey_handler();
            set_left_softkey_function(zi_inputbox_LSK_function, KEY_EVENT_UP);
            set_left_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
            if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
            {
                if (!IMEbValidPhonetic && !IMEbValidCandidates &&
                    !(IMEinline[0] && (IMEinline[0] != ZI8_CODE_MORE) &&
                      ((IMEmethod == INPUT_EZI_STROKE) || (IMEmethod == INPUT_EZI_PINYIN) ||
                       (IMEmethod == INPUT_EZI_BOPOMOFO) || (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) ||
                       (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))))
                {
                #if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
                    set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
                    set_left_softkey_icon(NULL);
                    redraw_left_softkey();
                    register_left_softkey_handler();
                    SetLeftSoftkeyFunction(EntryInLineMultilineEditorOption, KEY_EVENT_UP);
                #else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
                    set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OK));
                    set_left_softkey_icon(NULL);
                    register_left_softkey_handler();
                    set_left_softkey_function(wgui_inline_edit_DONE_function, KEY_EVENT_UP);
                #endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
                }
            }
            else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
            {
                set_left_softkey_label((UI_string_type) temp_left_softkey_text);
                if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
                {
                    if (wgui_inputbox_not_empty_callback != NULL)
                    {
                        wgui_inputbox_not_empty_callback();
                    }
                }
                else
                {
                    if (wgui_inputbox_empty_callback != NULL)
                    {
                        wgui_inputbox_empty_callback();
                    }
                }
            }

            if (wgui_inputbox_validation_callback != NULL &&
                wgui_inputbox_validation_callback != UI_dummy_validation_function)
            {
                wgui_inputbox_validation_callback(
                    MMI_multiline_inputbox.text,
                    MMI_multiline_inputbox.cursor_p,
                    (MMI_multiline_inputbox.text_length >> 1) - 1);
            }
            else
            {
                redraw_left_softkey();
            }
            break;
    }
}

/* MTK Add steven 050601 for solving display issue (scorpio_plus_demo scr #165) */


/*****************************************************************************
 * FUNCTION
 *  ZiHideCandiateArea
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiHideCandiateArea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

#if defined(MONO_LCD)
    c = WHITE;
#else /* defined(MONO_LCD) */ 
#ifdef __MMI_DEFAULT_THEME_3__
    c.r = 206;
    c.g = 206;
    c.b = 206;
#else /* __MMI_DEFAULT_THEME_3__ */ 
    c.r = 255;
    c.g = 255;
    c.b = 255;
#endif /* __MMI_DEFAULT_THEME_3__ */ 
    c.alpha = 100;
#endif /* defined(MONO_LCD) */ 

    gui_reset_clip();

    gui_fill_rectangle(0, ziCandidateArea.y, UI_device_width, ziCandidateArea.y + ziCandidateArea.height, c);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, ziCandidateArea.y, UI_device_width, ziCandidateArea.y + ziCandidateArea.height);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}

/* MTK End */


/*****************************************************************************
 * FUNCTION
 *  ZiInputMethodExit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiInputMethodExit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop the display-end-frame timer */
    gui_lock_double_buffer();

    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
    {
        bSkipGetCandidate = ZI8TRUE;
        IMEinline[0] = 0;
        IMEelementCount = 0;
        labelSoftR[0] = 'D';
        ZiInputBoxScreenStateChange();
    }
    gui_cancel_timer(ZiDisplayForEmsEditorEndFrame);
    ziFrameTimerStart = ZI8FALSE;
    ziFrameCounterForEMSEditor = 0;
    ziEngWordLen = 0;
    //StopMyTimer(ZI_FRAME_TIMER);
    //ziFrameCounterForEMSEditor = 0;
    //StopMyTimer(ZI_REQ_TIMER);

#if !defined(__MMI_TOUCH_SCREEN__)
    if ((IMEmethod == INPUT_EZI_STROKE) ||
        (IMEmethod == INPUT_EZI_PINYIN) ||
        (IMEmethod == INPUT_EZI_BOPOMOFO) ||
        (IMEmethod == INPUT_EZI_MULTITAP_PINYIN) || (IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO))
    {
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG) &&
            (MMI_multiline_inputbox.height != ziMultilineEditorHeight))
        {
            if (ziMultilineEditorHeight != 0)
            {
                MMI_multiline_inputbox.height = ziMultilineEditorHeight;
            }
            gui_resize_multi_line_input_box(
                &MMI_multiline_inputbox,
                MMI_multiline_inputbox.width,
                MMI_multiline_inputbox.height);
        }
    #if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
        else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG) && (MMI_EMS_inputbox.height != ziEMSEditorHeight))
        {
            if (ziEMSEditorHeight != 0)
            {
                MMI_EMS_inputbox.height = ziEMSEditorHeight;
            }
            gui_resize_EMS_input_box(&MMI_EMS_inputbox, MMI_EMS_inputbox.width, MMI_EMS_inputbox.height);
        }
    #endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
        if (IMEbValidCandidates)
        {
        #ifdef UI_SMALL_CATEGORY_EDITOR
            if (g_small_editor_category_present)
            {
                hide_multitap();
            }
            else
        #endif /* UI_SMALL_CATEGORY_EDITOR */ 
                ZiHideCandiateArea();
        }
    }
#endif /* !defined(__MMI_TOUCH_SCREEN__) */ 

    /* register the LSK */
    if ((!(ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)))
    {
        set_left_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS));
        if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG))
        {
            set_left_softkey_label((UI_string_type) temp_left_softkey_text);
            if (gui_multi_line_input_box_get_text_length(&MMI_multiline_inputbox) > 0)
            {
                if (wgui_inputbox_not_empty_callback != NULL)
                {
                    wgui_inputbox_not_empty_callback();
                }
            }
            else
            {
                if (wgui_inputbox_empty_callback != NULL)
                {
                    wgui_inputbox_empty_callback();
                }
            }
        }
        set_left_softkey_icon(NULL);

        if (wgui_inputbox_validation_callback != NULL &&
            wgui_inputbox_validation_callback != UI_dummy_validation_function)
        {
            wgui_inputbox_validation_callback(
                MMI_multiline_inputbox.text,
                MMI_multiline_inputbox.cursor_p,
                (MMI_multiline_inputbox.text_length >> 1) - 1);
        }
        else
        {
            redraw_left_softkey();
        }
        register_left_softkey_handler();
        set_left_softkey_function(zi_inputbox_LSK_function, KEY_EVENT_UP);
        set_left_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS);
    }

    /* re-register the LSK and RSK functions and redraw the screen */
    if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG)
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        wgui_handle_inputbox_input();
        show_multiline_inputbox();
    }
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
    {
        MMI_EMS_inputbox.flags &= ~UI_EMS_INPUT_BOX_WORD_HIGHLIGHT;
        handle_category28_input();
        show_EMS_inputbox();
    }
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
    {
        MMI_singleline_inputbox.flags &= ~UI_SINGLE_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        wgui_handle_singleline_inputbox_input();
        show_singleline_inputbox();
    }
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG)
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        wgui_handle_inputbox_input();
        show_multiline_inputbox();
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        0,
        0,
        UI_device_width,
        UI_device_height);
    
}


/*****************************************************************************
 * FUNCTION
 *  ZiHideCompositionArea
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiHideCompositionArea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(MONO_LCD)
    c = WHITE;
#else /* defined(MONO_LCD) */ 
#ifdef __MMI_DEFAULT_THEME_3__
    c.r = 206;
    c.g = 206;
    c.b = 206;
#else /* __MMI_DEFAULT_THEME_3__ */ 
    c.r = 255;
    c.g = 255;
    c.b = 255;
#endif /* __MMI_DEFAULT_THEME_3__ */ 
    c.alpha = 100;
#endif /* defined(MONO_LCD) */ 

    gui_reset_clip();
    //Temp solution for Scroll Bar Display
    //#ifdef __MMI_CHANGABLE_FONT__
    //      gui_fill_rectangle(0,ziCompositionArea.y-1-30,UI_device_width,ziCompositionArea.y+ziCompositionArea.height+1,c);
    //#else
#if defined (UI_SMALL_CATEGORY_EDITOR)
    if (g_small_editor_category_present)
    {
        gui_fill_rectangle(
            ziCompositionArea.x - 7,
            ziCompositionArea.y - 2,
            ziCompositionArea.x + ziCompositionArea.width + 7,
            ziCompositionArea.y + ziCompositionArea.height,
            c);
    }
    else
#endif /* defined (UI_SMALL_CATEGORY_EDITOR) */ /* UI_SMALL_EDITOR_SCREEN */
        gui_fill_rectangle(
            0,
            ziCompositionArea.y - 5,
            UI_device_width,
            ziCompositionArea.y + ziCompositionArea.height + 5,
            c);
    // #endif
}


/*****************************************************************************
 * FUNCTION
 *  ZiMaxLengthCheck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
extern U8 mmi_phb_convert_to_0x81(S8* input_name, BOOL is_convert);
ZI8UCHAR ZiMaxLengthCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ZI8LONG remaining_length;
    ZI8LONG b_flags;
    U8 temp_0x81 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_5_FLAG) ||
        (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_INLINE_MULTILINE_INPUTBOX_FLAG))
    {
        b_flags = MMI_multiline_inputbox.flags;
    #if !defined(MMI_LOW_MEMORY_PHONE)
        if (MMI_current_input_ext_type & INPUT_TYPE_EXT_USE_0x81_ENCODING)
        {
            temp_0x81 = mmi_phb_convert_to_0x81((S8*) MMI_multiline_inputbox.text, FALSE);
            if (temp_0x81 != 0)
            {
                if ((MMI_multiline_inputbox.text_length >> 1)>= MMI_multiline_inputbox.available_length - 3)
                {
                    return ZI8FALSE;
                }
                else
                {
                    return ZI8TRUE;
                }
            }
        }
    #endif /* !defined(MMI_LOW_MEMORY_PHONE) */ 
        switch (IMEmethod)
        {
            case INPUT_EZI_ABC:
            case INPUT_EZI_FRENCH:
            case INPUT_EZI_GERMAN:
            case INPUT_EZI_ITALIAN:
            case INPUT_EZI_SPANISH:
            case INPUT_EZI_PORTUGUESE:
            case INPUT_EZI_TURKISH:
            case INPUT_EZI_POLISH:
            case INPUT_EZI_NORWEGIAN:
            case INPUT_EZI_INDONESIAN:
            case INPUT_EZI_MALAY:
            case INPUT_EZI_SLOVAK:
            case INPUT_EZI_DUTCH:
            case INPUT_EZI_SWEDISH:
            case INPUT_EZI_CROATIAN:
            case INPUT_EZI_ROMANIAN:
            case INPUT_EZI_SLOVENIAN:
            case INPUT_EZI_GREEK:
            case INPUT_EZI_CZECH:
            case INPUT_EZI_FINNISH:
            case INPUT_EZI_DANISH:
            case INPUT_EZI_HUNGARIAN:
                if ((MMI_multiline_inputbox.last_position_p - MMI_multiline_inputbox.text) >=
                    (MMI_multiline_inputbox.available_length))
                {
                    return ZI8FALSE;
                }
                break;

            case INPUT_EZI_RUSSIAN:
            case INPUT_EZI_BULGARIAN:
            case INPUT_EZI_STROKE:
            case INPUT_EZI_PINYIN:
            case INPUT_EZI_BOPOMOFO:
            case INPUT_EZI_MULTITAP_PINYIN:
            case INPUT_EZI_MULTITAP_BOPOMOFO:
            case INPUT_EZI_THAI:
            case INPUT_EZI_VIETNAMESE:
                if ((b_flags & UI_MULTI_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) &&
                    (MMI_multiline_inputbox.UCS2_count == 0))
                {
                    if ((b_flags & UI_MULTI_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                        (MMI_multiline_inputbox.text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(MMI_multiline_inputbox.available_length)))
                    {
                        return ZI8FALSE;
                    }
                    else if (MMI_multiline_inputbox.text_length >= UI_UCS2_STRING_HALF_LENGTH(MMI_multiline_inputbox.available_length))
                    {
                        return ZI8FALSE;
                    }
                }
                else
                {
                    if ((MMI_multiline_inputbox.last_position_p - MMI_multiline_inputbox.text) >=
                        (MMI_multiline_inputbox.available_length))
                    {
                        return ZI8FALSE;
                    }
                }
                break;
        }

    }
#if !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__)
    else if (ziInputMethodCategoryFlag & ZI_IN_CATEGORY_28_FLAG)
    {

        if (MMI_EMS_inputbox.UCS2_count > 0)
        {
            remaining_length = (EMS_get_remaining_length(MMI_EMS_inputbox.data) >> 1);
        }
        else
        {
            remaining_length = EMS_get_remaining_length(MMI_EMS_inputbox.data);
            /* remaining_length-=MMI_EMS_inputbox.GSM_ext_count; */
        }

        if (remaining_length <= 0)
        {
            return ZI8FALSE;
        }

    }
#endif /* !defined(MMI_LOW_MEMORY_PHONE) || defined(__MMI_MESSAGES_EMS__) */ 
    else if ((ziInputMethodCategoryFlag & ZI_IN_CATEGORY_SINGLELINE_INPUTBOX_FLAG))
    {
        b_flags = MMI_singleline_inputbox.flags;
        switch (IMEmethod)
        {
            case INPUT_EZI_ABC:
            case INPUT_EZI_FRENCH:
            case INPUT_EZI_GERMAN:
            case INPUT_EZI_ITALIAN:
            case INPUT_EZI_SPANISH:
            case INPUT_EZI_PORTUGUESE:
            case INPUT_EZI_TURKISH:
            case INPUT_EZI_POLISH:
            case INPUT_EZI_NORWEGIAN:
            case INPUT_EZI_INDONESIAN:
            case INPUT_EZI_MALAY:
            case INPUT_EZI_SLOVAK:
            case INPUT_EZI_DUTCH:
            case INPUT_EZI_SWEDISH:
            case INPUT_EZI_CROATIAN:
            case INPUT_EZI_ROMANIAN:
            case INPUT_EZI_SLOVENIAN:
            case INPUT_EZI_GREEK:
            case INPUT_EZI_CZECH:
            case INPUT_EZI_FINNISH:
            case INPUT_EZI_DANISH:
            case INPUT_EZI_HUNGARIAN:
                if ((MMI_singleline_inputbox.last_position_p - MMI_singleline_inputbox.text) >=
                    (MMI_singleline_inputbox.available_length))
                {
                    return ZI8FALSE;
                }
                break;

            case INPUT_EZI_RUSSIAN:
            case INPUT_EZI_BULGARIAN:
            case INPUT_EZI_STROKE:
            case INPUT_EZI_PINYIN:
            case INPUT_EZI_BOPOMOFO:
            case INPUT_EZI_MULTITAP_PINYIN:
            case INPUT_EZI_MULTITAP_BOPOMOFO:
            case INPUT_EZI_THAI:
            case INPUT_EZI_VIETNAMESE:
                if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_USE_ENCODING_BASED_LENGTH) &&
                    (MMI_singleline_inputbox.UCS2_count == 0))
                {
                    if ((b_flags & UI_SINGLE_LINE_INPUT_BOX_ONE_LESS_CHARACTER) &&
                        (MMI_singleline_inputbox.text_length >= UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE(MMI_singleline_inputbox.available_length)))
                    {
                        return ZI8FALSE;
                    }
                    else if (MMI_singleline_inputbox.text_length >= UI_UCS2_STRING_HALF_LENGTH(MMI_singleline_inputbox.available_length))
                    {
                        return ZI8FALSE;
                    }
                }
                else
                {
                    if ((MMI_singleline_inputbox.last_position_p - MMI_singleline_inputbox.text) >=
                        (MMI_singleline_inputbox.available_length))
                    {
                        return ZI8FALSE;
                    }
                }
                break;
        }

    }

    return ZI8TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  ZiMultitapKeyTimeoutHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiMultitapKeyTimeoutHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lastKeyID = 0;
    /* ZiDisplay(); */

}


/*****************************************************************************
 * FUNCTION
 *  ZiSetCandidateWindowCurrentTheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ZiSetCandidateWindowCurrentTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ziCandidateArea.normal_filler = current_multitap_input_theme->f;
    ziCandidateArea.selection_color = current_multitap_input_theme->selector_color;
    ziCandidateArea.selection_text_color = current_multitap_input_theme->selected_text_color;
    ziCandidateArea.normal_text_color = current_multitap_input_theme->normal_text_color;
    ziCandidateArea.text_font = current_UI_theme->multitap_input_theme->text_font;
    ziCompositionArea.normal_filler = current_multitap_input_theme->f;
    ziCompositionArea.selection_color = current_multitap_input_theme->selector_color;
    ziCompositionArea.selection_text_color = current_multitap_input_theme->selected_text_color;
    ziCompositionArea.normal_text_color = current_multitap_input_theme->normal_text_color;
    ziCompositionArea.text_font = current_UI_theme->multitap_input_theme->text_font;
}


/*****************************************************************************
 * FUNCTION
 *  ZiSetInputboxLSKFunction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ZiSetInputboxLSKFunction(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zi_inputbox_LSK_function = f;
}


//add by Ailsa - start
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_screen_state_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ime_screen_state_query()
{
    MMI_BOOL result = MMI_TRUE;
    switch (labelSoftR[0])
    {
    case 'S':
        result = MMI_FALSE;
        break;
    default:
        result = MMI_TRUE;
        break;
    }
    return result;
}
//add by Ailsa - end


#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#define LEN_RESULT_ONESEARCH 120  //每次搜索返回的汉字候选个数最大值
#define LEN_EACH_PAGE        PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS  //每页显示的候选汉字个数
#define LEN_KEY_SEQUENCE_INPUT 20  //按键输入的最大长度
#define LEN_MAX_SYLLABLE_BUFFER_SIZE 128  //英语搜索的最大长度,测试中发现最长为30
#ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
U16 csSearchResult[LEN_RESULT_ONESEARCH]; //汉字候选结果
static void mmi_pen_editor_get_key_sequence_by_vkText(UI_character_type *composition, U16 composition_len, mmi_keypads_enum *key_sequence);
static U16 g_csEnglishSearchResult[LEN_MAX_SYLLABLE_BUFFER_SIZE];
UI_character_type g_english_candidate_buffer[PEN_EDITOR_MAX_KEY_BUFFER_SIZE];
static char key_sequence_ansii[LEN_KEY_SEQUENCE_INPUT];


/*UNI@bw_20070717 16:01:52 使用欣然输入法时为了保证PC 可以编译使用__MMI_UNI_XINRAN_INPUT_METHORD__宏定义几个缺少的函数和变量*/
#ifdef WIN32
#ifdef __MMI_UNI_XINRAN_INPUT_METHORD__
U16 cscount_result ;
U16 pycount_result ;

U16 fnPySearch(char *keyinput,U16 *csPyzhStore,U16 *searchresult,int count_pyzh_sel)
{
	return 0;
}
U16 fnCharAssociation(U16 selChar,U16 *searchresult)
{
	return 0;
}
int fnEnCapSel(int msel,U16 *csEnglishSearchResult)
{
	return 0;
}
U16 fnEnglishSearch(char *keyinput,U16 *csEnglishSearchResult)
{
	return 0;
}

U16 fnBhSearch(char *keyinput,U16 *searchresult)
{
	return 0;
}
#endif //__MMI_UNI_XINRAN_INPUT_METHORD__
#endif //WIN32

extern void mmi_pen_editor_right_soft_key_handler(void);
extern S32 mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence(mmi_keypads_enum* key_sequence, S32 key_sequence_length, UI_character_type *syllable_buffer, S32 start_index, S32 end_index);
extern U16 fnEnglishSearch(char *keyinput,U16 *csEnglishSearchResult);

#ifndef MMI_ON_WIN32	//Add 08Mar14, Matthew
//通过拼音,获得输入的按键序列 
U16 mmi_pen_editor_get_english_cadidate_count_result(void )
{
/*UNI@bw_20070723 17:59:59  新然输入法,简体,繁体,英文分开,原来公用的变量也要区别使用  */
	return Encount_result;
}
//Add 08Mar14, Matthew
#else
#define	mmi_pen_editor_get_english_cadidate_count_result(void)
#endif

void mmi_pen_editor_get_traditional_key_sequence_by_vkText(UI_character_type *composition, U16 composition_len, mmi_keypads_enum *key_sequence)
{
	U16 i = 0;	
	while(i < composition_len)
	{

		switch(composition[i])
		{//ㄅㄉㄍㄚ		
			case 0x3105:
			case 0x3109:
			case 0x311A:	
			case 0x310D:	
				key_sequence[i] = 0x1;
				break;
				//ㄈㄌㄐㄞ
			case 0x3108:
			case 0x310c:
			case 0x3110:
			case 0x311E:
				key_sequence[i] = 0x2;
				break;
				//ㄓㄗㄢㄧ
			case 0x3113:	
			case 0x3117:
			case 0x3122:
			case 0x3127:
				key_sequence[i] = 0x3;
				break;
				//ㄆㄊㄎㄛ
			case 0x3106:	
			case 0x310a:
			case 0x310E:
			case 0x311B:
				key_sequence[i] = 0x4;
				break;
				//ㄑㄟㄖㄥ
			case 0x3116:	
			case 0x3111:
			case 0x311F:
			case 0x3125:
				key_sequence[i] = 0x5;
				break;
				//ㄔㄘㄣㄨ
			case 0x3114:	
			case 0x3118:
			case 0x3128:
			case 0x3123:
				key_sequence[i] = 0x6;
				break;
				//ㄇㄋㄏㄜㄝ
			case 0x3107:	
			case 0x310B:
			case 0x310f:
			case 0x311C:
			case 0x311D:
				key_sequence[i] = 0x7;
				break;
				//ㄒㄠㄡㄦ
			case 0x3126:	
			case 0x3112:
			case 0x3120:
			case 0x3121:
				key_sequence[i] = 0x8;
				break;	
				//ㄕㄙㄤㄩ
			case 0x3115:	
			case 0x3119:
			case 0x3129:
			case 0x3124:
				key_sequence[i] = 0x9;
				break;
			default:
				break;			
				
		}
	      // key_sequence[i] += 0x30;
		i ++;
	}
	key_sequence[i] = 0x0;
	return ;//key_sequence;000000
}
void mmi_pen_editor_get_key_sequence_by_vkText(UI_character_type *composition, U16 composition_len, mmi_keypads_enum *key_sequence)
{
	U16 i = 0;	
	while(i < composition_len)
	{
		switch(composition[i])
		{
			case 0x61:
			case 0x62:
			case 0x63:
				key_sequence[i] = 0x2;
				break;
			case 0x64:
			case 0x65:
			case 0x66:
				key_sequence[i] = 0x3;
				break;
			case 0x67:
			case 0x68:
			case 0x69:
				key_sequence[i] = 0x4;
				break;
			case 0x6A:
			case 0x6B:
			case 0x6C:
				key_sequence[i] = 0x5;
				break;
			case 0x6D:
			case 0x6E:
			case 0x6F:
				key_sequence[i] = 0x6;
				break;
			case 0x70:
			case 0x71:
			case 0x72:
			case 0x73:
				key_sequence[i] = 0x7;
				break;
			case 0x74:
			case 0x75:
			case 0x76:
				key_sequence[i] = 0x8;
				break;			
			case 0x77:
			case 0x78:
			case 0x79:
			case 0x7A:
				key_sequence[i] = 0x9;
				break;
			default:
				break;			
				
		}
		i ++;
	}
	key_sequence[i] = 0x0;
	return ;//key_sequence;
}
//查找输入的拼音位于返回的串的位置
S16 mmi_pen_editor_get_syllable_index(UI_character_type *VKText, S8 textLength)
{
	int i ,j,n = 0;

	if(VKText[0] == 0) //
		return 0;
	for(i = 0,j = 0; i < LEN_MAX_SYLLABLE_BUFFER_SIZE&&j < textLength; i ++)
	{
		if( VKText[j]== g_csEnglishSearchResult[i])
		{
			j ++;
			//i ++;
		}
		else
		{
			j = 0;
			//i ++;
			if( g_csEnglishSearchResult[i] == 0x20)
			{ 
				n ++;
			}
		}
	}
	if( j == textLength )
	return n;
	else
		return -1;
		
}

extern void mmi_pen_editor_del_key_sequence_default(void);
/*
通过输入的按键序列,获得汉字候选,返回候选字的长度
char* key_input, 输入的按键序列
U16 *csEnglishResult,获得的英文候选
U16 *candidate_buffer,获得的汉字候选
INT32 count_pyzh_sel -1表示取得拼音候选,0,1,2 等表示获得第 多少个拼音的汉字候选
*/
S32 fngetChineseCandidateBuffer(char* key_input, U16 *csEnglishResult,U16 *candidate_buffer,INT32 count_pyzh_sel)
{
    U16 ret = 1;
    S32 input_length; 
    //根据输入的按键,查找中英文,候选汉字放在全局变量中
    memset( csSearchResult, 0x0, sizeof( U16 ) * LEN_RESULT_ONESEARCH );

    input_length = strlen( key_input );
    if ( IMEmethod == INPUT_EZI_BOPOMOFO
      || IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
    {
    #ifdef __MMI_LANG_TR_CHINESE__
        ret = T_ZySearch( key_input, csEnglishResult, csSearchResult,
                          count_pyzh_sel );
	#endif
    }
    else
    {
        ret = fnPySearch( key_input, csEnglishResult, csSearchResult,
                          count_pyzh_sel );
    }

    if ( ret != 0 )//如果调用不成功,重新调用一次,可能为1,可能为2
    {
        //return 0;
        input_length --;
        //mmi_pen_editor_right_soft_key_handler();
        mmi_pen_editor_del_key_sequence_default();
        if ( input_length >= 0 )
        {
            key_input[input_length] = 0x0;
        }
        if ( IMEmethod == INPUT_EZI_BOPOMOFO
          || IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
        {
        #ifdef __MMI_LANG_TR_CHINESE__
            ret = T_ZySearch( key_input, csEnglishResult, csSearchResult,
                              count_pyzh_sel );
		#endif
        }
        else
        {
            ret = fnPySearch( key_input, csEnglishResult, csSearchResult,
                              count_pyzh_sel );
        }
        if ( input_length == 0 )
        {
            return 0;
        }
        if ( ret != 0 )
        {
            return 0;
        }
    }

    //拷贝最前面的 LEN_EACH_PAGE 个汉字到candidate_buffer中去;
    UCS2Strncpy( ( S8 * ) candidate_buffer, ( const S8 * ) csSearchResult,
                 LEN_EACH_PAGE );
    //返回 candidate_buffer的有效长度
    return UCS2Strlen( ( const S8 * ) candidate_buffer );
}
/*
通过输入的按键序列,获得拼音候选,返回候选的长度
char* key_input, 输入的按键序列
U16 *csEnglishResult,获得的英文候选
U16 *candidate_buffer,获得的汉字候选

*/
S32 fngetPinyinCandidateBuffer(char* key_input, S32 input_length, U16 *csEnglishResult)
{
    U16 ret = 1;
    U16 pinyinLength;


    //根据输入的按键,查找中英文,候选汉字放在全局变量中
    if ( IMEmethod == INPUT_EZI_BOPOMOFO
      || IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
    {
    #ifdef __MMI_LANG_TR_CHINESE__
        ret = T_ZySearch( key_input, csEnglishResult, csSearchResult, -1 );
	#endif
    }
    else
    {
        ret = fnPySearch( key_input, csEnglishResult, csSearchResult, -1 );
    }

    if ( ret != 0 || key_input[input_length - 1] == 0x0 )//如果调用不成功,重新调用一次,可能为1,可能为2
    {
        /*UNI@bw_20070420 14:25:43 按了拼音之后按0键,会死机Begin*/
        /*如果最后一个按键是0 ,也要回退一个键*/
        //return 0;
        input_length --;
        //mmi_pen_editor_right_soft_key_handler();
        mmi_pen_editor_del_key_sequence_default();
        key_input[input_length] = 0x0;
        if ( IMEmethod == INPUT_EZI_BOPOMOFO
          || IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
        {
        #ifdef __MMI_LANG_TR_CHINESE__
            ret = T_ZySearch( key_input, csEnglishResult, csSearchResult, -1 );
		#endif
        }
        else
        {
            ret = fnPySearch( key_input, csEnglishResult, csSearchResult, -1 );
        }
        if ( input_length == 0 )
        {
            return 0;
        }
        if ( ret != 0 )
        {
            return 0;
        }
    }
    if ( ret == 0 )
    {
        pinyinLength = UCS2Strlen( ( const S8 * ) csEnglishResult );
        MMI_ASSERT( pinyinLength < LEN_MAX_SYLLABLE_BUFFER_SIZE );      
        csEnglishResult[pinyinLength - 1] = 0x0;
        memcpy( g_csEnglishSearchResult, csEnglishResult,
                sizeof( U16 ) * LEN_MAX_SYLLABLE_BUFFER_SIZE );//拷贝到全局变量中
    }

    if ( ret == 0 && ( csEnglishResult[0] > 'z' || csEnglishResult[0] < 'A' ) )
    {
        //成功取得了拼音,但是拼音为乱码,直接返回失败
        if ( IMEmethod != INPUT_EZI_BOPOMOFO
          && IMEmethod != INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
        {
            return 0;
        }
    }
    if ( IMEmethod == INPUT_EZI_BOPOMOFO
      || IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO ) //如果是繁体注音输入法
    {
    #ifdef __MMI_LANG_TR_CHINESE__
        return zy_zh_count_result;//成功调用,返回拼音的长度
    #endif
    }
    else
    {
        return pycount_result;
    }//成功调用,返回拼音的长度
}
void mmi_keypads_enum_to_char(char * out, mmi_keypads_enum* keyin, size_t length)
{	
	out[length ] = 0x0;	
	while(length-- > 0)
	{
		if(IMEmethod == INPUT_EZI_BOPOMOFO||IMEmethod ==  INPUT_EZI_MULTITAP_BOPOMOFO) //如果是繁体注音输入法
			out[length ] = keyin[length] + 0x30;	
		else
			out[length ] = keyin[length] ;
	}
	
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_composition
 * DESCRIPTION
 *  This function is to get candidates from virtual keyboard input
 * PARAMETERS
 *  composition         [?]     
 *  candidatebuffer     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_composition(UI_character_type *composition, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
    S8                  composition_len, num = 1;
    S16                 index   = -1;
    U16                 csEnglishSearchResult[LEN_MAX_SYLLABLE_BUFFER_SIZE];

    mmi_keypads_enum    key_sequence[LEN_KEY_SEQUENCE_INPUT];

    composition_len = UCS2Strlen( ( const S8 * ) composition );
	
    if ( IMEmethod == INPUT_EZI_MULTITAP_BOPOMOFO
      || IMEmethod == INPUT_EZI_BOPOMOFO )
    {
    	#ifdef __MMI_LANG_TR_CHINESE__
        mmi_pen_editor_get_traditional_key_sequence_by_vkText( composition,
                                                               composition_len,
                                                               key_sequence );
		#endif
    }
    else
    {
        mmi_pen_editor_get_key_sequence_by_vkText( composition, composition_len,
                                                   key_sequence );//通过拼音,获得输入的按键序列
    }
    num = mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence( key_sequence,
                                                                  composition_len,
                                                                  csEnglishSearchResult,
                                                                  0, 0 );
    if ( num > 0 )//返回的拼音候选的个数
    {
        composition_len = UCS2Strlen( ( const S8 * ) composition );//上面取得拼音候选的时候,可能会失败,失败的时候会回退一个字符,所以这里要重新取得长度.
        //P_6226_M21_bw_Z1929 拼音输入法时,第二次按键会只显示汉字,没有拼音
        index = mmi_pen_editor_get_syllable_index( composition, composition_len );//返回位置
    } 


    if ( index == -1 )//如果没有
    {
        num = 0;//表述查找到0个结果
        //MMI_ASSERT(expr)
    }
    else
    {
        mmi_keypads_enum_to_char( key_sequence_ansii, key_sequence,
                                  composition_len );
        num = fngetChineseCandidateBuffer( key_sequence_ansii,
                                           csEnglishSearchResult,
                                           candidatebuffer, index );     
    }
    return num;
	
    #else
    IMEzi8GetParam.ElementCount = 0;
    IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    IMEzi8GetParam.Context |= ZI8_GETCONTEXT_SINGLE_CHAR;
    memset(IMEelementBuffer, 0, sizeof(IMEelementBuffer));
    for (;; IMEzi8GetParam.ElementCount++)
    {
        if ('\0' == composition[IMEzi8GetParam.ElementCount])
        {
            break;
        }
        switch (composition[IMEzi8GetParam.ElementCount])
        {
            case 0x002D:
                IMEelementBuffer[IMEzi8GetParam.ElementCount] = ZI8_CODE_TONES_1;
                break;
            case 0x02C7:
                IMEelementBuffer[IMEzi8GetParam.ElementCount] = ZI8_CODE_TONES_3;
                break;
            case 0x02CA:
                IMEelementBuffer[IMEzi8GetParam.ElementCount] = ZI8_CODE_TONES_2;
                break;
            case 0x02CB:
                IMEelementBuffer[IMEzi8GetParam.ElementCount] = ZI8_CODE_TONES_4;
                break;
            case 0x02D9:
                IMEelementBuffer[IMEzi8GetParam.ElementCount] = ZI8_CODE_TONES_5;
                break;
            default:
                if (composition[IMEzi8GetParam.ElementCount] >= 0x0061 &&
                    composition[IMEzi8GetParam.ElementCount] <= 0x007a)
                {
                #ifdef __MMI_ZI_V7__
                    IMEelementBuffer[IMEzi8GetParam.ElementCount] = composition[IMEzi8GetParam.ElementCount] + 0xF300;
                #else 
                    IMEelementBuffer[IMEzi8GetParam.ElementCount] = composition[IMEzi8GetParam.ElementCount] + 0xF400;
                #endif 
                    IMEzi8GetParam.GetMode = ZI8_GETMODE_PINYIN;
                }
                else if (composition[IMEzi8GetParam.ElementCount] >= 0x3105 &&
                         composition[IMEzi8GetParam.ElementCount] <= 0x3129)
                {
                #ifdef __MMI_ZI_V7__
                    IMEelementBuffer[IMEzi8GetParam.ElementCount] = composition[IMEzi8GetParam.ElementCount] + 0xC200;
                #else 
                    IMEelementBuffer[IMEzi8GetParam.ElementCount] = composition[IMEzi8GetParam.ElementCount] + 0xC300;
                #endif 
                    IMEzi8GetParam.GetMode = ZI8_GETMODE_BOPOMOFO;
                }
                else
                {
                    return 0;
                }
                break;
        }
        MMI_ASSERT(IMEzi8GetParam.ElementCount < MAX_ELEMENT_BUFFERSIZE);
    }
    if (0 == IMEzi8GetParam.ElementCount)
    {
        return 0;
    }
    else
    {
        IMEzi8GetParam.ElementCount = Zi8CopyWordListW(IMEinline, MAX_ELEMENT_BUFFERSIZE, IMEelementBuffer, 0) - 1;
        IMEzi8GetParam.FirstCandidate = 0;
        IMEzi8GetParam.pCandidates = candidatebuffer;
        IMEzi8GetParam.MaxCandidates = PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS;
        IMEzi8GetParam.pElements = IMEelementBuffer;
        return (Zi8GetCandidates(&IMEzi8GetParam));
    }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_phrase
 * DESCRIPTION
 *  This function is to get candidates by phrase
 * PARAMETERS
 *  phrase              [IN]        
 *  candidatebuffer     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_phrase(UI_character_type phrase, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
   U16 ret = 1;
   memset( csSearchResult, 0x0, sizeof(U16)*LEN_RESULT_ONESEARCH);
	#ifdef __MMI_LANG_TR_CHINESE__
   if(IMEmethod == INPUT_EZI_BOPOMOFO||IMEmethod ==  INPUT_EZI_MULTITAP_BOPOMOFO) //如果是繁体注音输入法
	ret = T_fnCharAssociation( phrase,csSearchResult);
    else
	#endif
   ret = fnCharAssociation( phrase,csSearchResult);
   if(ret == 0)
   {
   	UCS2Strncpy( (S8*) candidatebuffer, (const S8*)csSearchResult, LEN_EACH_PAGE);
	return UCS2Strlen((const S8 * )candidatebuffer);
   } 
   else
	return 0;
   #else
    IMEzi8GetParam.Context |= ZI8_GETCONTEXT_NO_RADICALS;
    IMEzi8GetParam.Context |= ZI8_GETCONTEXT_SINGLE_CHAR;
    IMEzi8GetParam.GetMode = ZI8_GETMODE_DEFAULT;
    memset(IMEwordBuffer, 0, sizeof(IMEwordBuffer));
    IMEzi8GetParam.ElementCount = 0;
    IMEzi8GetParam.FirstCandidate = 0;
    IMEzi8GetParam.pCurrentWord = IMEwordBuffer;
    IMEzi8GetParam.pCandidates = candidatebuffer;
    IMEzi8GetParam.WordCharacterCount = 1;
    IMEzi8GetParam.MaxCandidates = PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS;
    IMEwordBuffer[0] = phrase;
    return (Zi8GetCandidates(&IMEzi8GetParam));
   #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_get_candidates_by_page
 * DESCRIPTION
 *  This function is to get candidates of page
 * PARAMETERS
 *  page                [IN]        
 *  candidatebuffer     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_ime_get_candidates_by_page(S32 page, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* W05.35 Set IMEzi8GetParam.MaxCandidates before jumping to page */
    #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
   U16 pagemax = 0;
   if(page < 1)
   	page =0;
	if(page * LEN_EACH_PAGE <  cscount_result)// 
	{//返回指定的汉字
		UCS2Strncpy( (S8*) candidatebuffer, (const S8 *)&csSearchResult[page * LEN_EACH_PAGE], LEN_EACH_PAGE);
	//返回 candidate_buffer的有效长度
		return UCS2Strlen((const S8 * )candidatebuffer);
	}
	else//返回最后的几个汉字
	{
		pagemax = cscount_result / LEN_EACH_PAGE + 1;
		UCS2Strncpy( (S8*) candidatebuffer, (const S8 *)&csSearchResult[pagemax * LEN_EACH_PAGE], LEN_EACH_PAGE);
	//返回 candidate_buffer的有效长度
		return UCS2Strlen((const S8 * )candidatebuffer);	
	}
      #else
    IMEzi8GetParam.MaxCandidates = PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS;
    IMEzi8GetParam.FirstCandidate = IMEzi8GetParam.MaxCandidates * page;
    IMEzi8GetParam.pCandidates = candidatebuffer;
    return (Zi8GetCandidates(&IMEzi8GetParam));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_latin_get_candidates_by_key_sequence
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_sequence            [?]         
 *  key_sequence_length     [IN]        
 *  candidatebuffer         [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_ime_smart_latin_get_candidates_by_key_sequence(
        mmi_keypads_enum *key_sequence,
        S32 key_sequence_length,
        UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
     #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__

	S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(g_english_candidate_buffer, 0x0, PEN_EDITOR_MAX_KEY_BUFFER_SIZE);
	mmi_keypads_enum_to_char(key_sequence_ansii, key_sequence, key_sequence_length);
	ret = fnEnglishSearch(key_sequence_ansii,candidatebuffer);

	if(ret != 0)
	{
		if(key_sequence_length == 1 && key_sequence_ansii[0] == 1)
		{
			//memcpy(candidatebuffer, temp, sizeof(temp));
			candidatebuffer[0] = 0x2E;//英文的句号
			candidatebuffer[1] = 0x0;
			candidatebuffer[2] = 0x0;//英文的句号
			candidatebuffer[3] = 0x0;
			UCS2Strcpy((S8 * )g_english_candidate_buffer, (const S8 * )candidatebuffer);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(IMEletterCase == ZI8_CASE_LOWER)
	{
	    //转换为小写
	    fnEnCapSel(0,candidatebuffer);
	}	
	else if(IMEletterCase == ZI8_CASE_UPPER)
	{
	    //转换为大写
	    fnEnCapSel(2,candidatebuffer);
	}
	else if(IMEletterCase == ZI8_CASE_TITLE)
		fnEnCapSel(1,candidatebuffer); //首字大写
	
	UCS2Strcpy((S8 * )g_english_candidate_buffer, (const S8 * )candidatebuffer);
	MMI_ASSERT(UCS2Strlen((const S8 * )candidatebuffer) <  256);
	for(i = 0; i < UCS2Strlen((const S8 * )candidatebuffer); i++)
	{
		if(candidatebuffer[i] == 0x20)
		{
			candidatebuffer[i] = 0x0;
			break;
		}		
		
	}
	return i;
#else
    IMEzi8GetParam.ElementCount = 0;
    memset(IMEelementBuffer, 0, sizeof(IMEelementBuffer));
    for (; IMEzi8GetParam.ElementCount < key_sequence_length;)
    {
        switch (key_sequence[IMEzi8GetParam.ElementCount])
        {
            case KEY_1:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_PUNCT;
                break;
            case KEY_2:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY2;
                break;
            case KEY_3:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY3;
                break;
            case KEY_4:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY4;
                break;
            case KEY_5:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY5;
                break;
            case KEY_6:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY6;
                break;
            case KEY_7:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY7;
                break;
            case KEY_8:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY8;
                break;
            case KEY_9:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LATIN_KEY9;
                break;
            default:
                return 0;
        }
        MMI_ASSERT(IMEzi8GetParam.ElementCount < MAX_ELEMENT_BUFFERSIZE);
    }
    IMEzi8GetParam.FirstCandidate = 0;
    IMEzi8GetParam.WordCharacterCount = 0;
    IMEzi8GetParam.pCandidates = candidatebuffer;
    i = Zi8GetCandidates(&IMEzi8GetParam);
    IMEtoCapMode(candidatebuffer);
    if (i)
    {
        for (i = 0; candidatebuffer[i]; i++)
        {
        }
        return i;
    }
    else
    {
        return i;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_latin_get_candidates_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index               [?]     
 *  candidatebuffer     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_ime_smart_latin_get_candidates_by_index(S32 *index, UI_character_type *candidatebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
	int i = 0,j =0;
         int n = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
   if(*index >0 )
  { 
   for(i = 0; i < PEN_EDITOR_MAX_KEY_BUFFER_SIZE; i++)//找到指定的候选英语
   	{
   		if(g_english_candidate_buffer[i] == 0x20&&g_english_candidate_buffer[i]!=0x0)
   		{
   			n ++;
			if(n == *index)
			{
				i ++;
				break;
			}
		}
   	}
   }
   for(;;i++,j ++)//拷贝英语
   	{
   		if((g_english_candidate_buffer[i] == 0x20)||(g_english_candidate_buffer[i] == 0x0))
		{
			candidatebuffer[j] = 0x0;
			break;
   		}
		else 
		{
			if(g_english_candidate_buffer[i] <='z' &&g_english_candidate_buffer[i] >='A'  )
			candidatebuffer[j ]= g_english_candidate_buffer[i];
			else
				{
					candidatebuffer[0] = 0x0;
					j = 0;
					return 0;
				}
		}
   	}
   return j ;
#else
    IMEzi8GetParam.FirstCandidate = *index;
    IMEzi8GetParam.WordCharacterCount = 0;
    IMEzi8GetParam.pCandidates = candidatebuffer;
    i = Zi8GetCandidates(&IMEzi8GetParam);
    IMEtoCapMode(candidatebuffer);
    if (i)
    {
        for (i = 0; candidatebuffer[i]; i++)
        {
        }
        return i;
    }
    else
    {
        if (*index < 0)
        {
            *index = 0;
        }
        else
        {
            *index = *index - 1;
        }
        return i;
    }
   #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_chinese_stroke_get_candidates_by_key_sequence
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_sequence            [?]         
 *  key_sequence_length     [IN]        
 *  candidatebuffer         [?]         
 *  strokebuffer            [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_ime_chinese_stroke_get_candidates_by_key_sequence(
        mmi_keypads_enum *key_sequence,
        S32 key_sequence_length,
        UI_character_type *candidatebuffer,
        UI_character_type *strokebuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
   U16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMEzi8GetParam.ElementCount = 0;

	/*UNI@bw_20070524  解决在比划输入法界面, 如果使用虚拟键盘输入拼音, 则zi的全局变量IMEzi8GetParam.GetMode会被修建, 导致再使用按键输入比划时, 没有候选字出现, 修改为在进入比划输入法时给IMEzi8GetParam.GetMode赋值ZI8_GETMODE_STROKES*/
	#if (defined  __UNI_MMI_TOUCH_SCREEN_AMENDMENT__)
	IMEzi8GetParam.GetMode     = ZI8_GETMODE_STROKES;
	#endif

    memset(IMEelementBuffer, 0, sizeof(IMEelementBuffer));
    for (; IMEzi8GetParam.ElementCount < key_sequence_length;)
    {
        switch (key_sequence[IMEzi8GetParam.ElementCount])
        {
            case KEY_1:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_OVER;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_OVER;
                break;
            case KEY_2:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_DOWN;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_DOWN;
                break;
            case KEY_3:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_LEFT;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_LEFT;
                break;
            case KEY_4:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_DOT;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_DOT;
                break;
            case KEY_5:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_OVER_DOWN;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_OVER_DOWN;
                break;
	    #ifdef __MMI_UNI_XINRAN_INPUT_METHORD_SIX_KEY__
	     case KEY_6:
		IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_WILDCARD;  
		strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_WILDCARD;
		break;
	     default:
                 return 0;				
	    #else//使用老的9键丝印
            case KEY_6:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_CURVED_HOOK;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_CURVED_HOOK;
                break;
            case KEY_7:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_DOWN_OVER;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_DOWN_OVER;
                break;
            case KEY_8:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_WILDCARD;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_WILDCARD;
                break;
            case KEY_9:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_CODE_OVER_DOWN_OVER;
                strokebuffer[IMEzi8GetParam.ElementCount - 1] = ZI8_CODE_OVER_DOWN_OVER;
                break;
            default:
                return 0;
            #endif
        }
        MMI_ASSERT(IMEzi8GetParam.ElementCount < MAX_ELEMENT_BUFFERSIZE);
    }

    #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__
	mmi_keypads_enum_to_char(key_sequence_ansii, key_sequence, key_sequence_length);
	
	
	ret  =  fnBhSearch(key_sequence_ansii,csSearchResult);
	if(ret != 0)
	{
		//return 0;
		key_sequence_length --;
		key_sequence_ansii[key_sequence_length] = 0x0;
		strokebuffer[key_sequence_length] = 0x0; //取消刚刚的笔划输入
		//mmi_pen_editor_right_soft_key_handler();
		mmi_pen_editor_del_key_sequence_default();
/*UNI@bw_20070428 10:31:39 速度改进 Begin*/
		ret  =  fnBhSearch(key_sequence_ansii,csSearchResult);
	}
	
	if(ret != 0)
		return 0;
	
	UCS2Strncpy((S8 *) candidatebuffer, (const S8 *) csSearchResult, LEN_EACH_PAGE);
   	return UCS2Strlen((const S8 * )candidatebuffer);
    #else

    IMEzi8GetParam.GetMode = ZI8_GETMODE_STROKES;
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_NOCOMPONENTS;
    IMEzi8GetParam.FirstCandidate = 0;
    IMEzi8GetParam.pCandidates = candidatebuffer;
    IMEzi8GetParam.MaxCandidates = PEN_EDITOR_CANDIDATE_SIZE_WITH_ARROWS;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    return (Zi8GetCandidates(&IMEzi8GetParam));
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_smart_bpmf_pinyin_get_syllable_by_key_sequence
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_sequence            [?]         
 *  key_sequence_length     [IN]        
 *  syllable_buffer         [?]         
 *  start_index             [IN]        
 *  end_index               [IN]        
 * RETURNS
 *  
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
    int i = 0, num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #ifdef  __MMI_UNI_XINRAN_INPUT_METHORD__     
   
     mmi_keypads_enum_to_char(key_sequence_ansii, key_sequence, key_sequence_length);
	
	num = fngetPinyinCandidateBuffer(key_sequence_ansii,key_sequence_length,syllable_buffer);
	return num;
        #else
    IMEzi8GetParam.ElementCount = 0;
    memset(IMEelementBuffer, 0, sizeof(IMEelementBuffer));
    for (; IMEzi8GetParam.ElementCount < key_sequence_length;)
    {
        switch (key_sequence[IMEzi8GetParam.ElementCount])
        {
            case KEY_1:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY1;
                break;
            case KEY_2:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY2;
                break;
            case KEY_3:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY3;
                break;
            case KEY_4:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY4;
                break;
            case KEY_5:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY5;
                break;
            case KEY_6:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY6;
                break;
            case KEY_7:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY7;
                break;
            case KEY_8:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY8;
                break;
            case KEY_9:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY9;
                break;
            case KEY_0:
                IMEelementBuffer[IMEzi8GetParam.ElementCount++] = ZI8_ONEKEY_KEY0;
                break;
            default:
                return 0;
        }
        MMI_ASSERT(IMEzi8GetParam.ElementCount < MAX_ELEMENT_BUFFERSIZE);
    }
#endif
    if (IMEmethod == INPUT_EZI_BOPOMOFO)
    {
        IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_BOPOMOFO;
    }
    else if (IMEmethod == INPUT_EZI_PINYIN)
    {
        IMEzi8GetParam.GetMode = ZI8_GETMODE_1KEYPRESS_PINYIN;
    }
    IMEzi8GetParam.GetOptions = ZI8_GETOPTION_GET_SPELLING;
    IMEzi8GetParam.WordCharacterCount = 0;
    IMEzi8GetParam.FirstCandidate = start_index;
    IMEzi8GetParam.pElements = IMEelementBuffer;
    IMEzi8GetParam.pCandidates = syllable_buffer;
    IMEzi8GetParam.MaxCandidates = end_index - start_index + 1;
    num = Zi8GetCandidates(&IMEzi8GetParam);
    if (num)
    {
        int j = 0;

        for (i = 0;; i++)
        {
            if (syllable_buffer[i])
            {
                if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_BOPOMOFO)
                {
                    syllable_buffer[i] -= 0xc300;
                }
                else if (IMEzi8GetParam.GetMode == ZI8_GETMODE_1KEYPRESS_PINYIN)
                {
                    syllable_buffer[i] -= 0xf400;
                }
            }
            else
            {
                j++;
                if (j >= num)
                {
                    break;
                }
                syllable_buffer[i] = 0x20;
            }
        }
        return num;
    }
    else
    {
        return num;
    }
}
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

