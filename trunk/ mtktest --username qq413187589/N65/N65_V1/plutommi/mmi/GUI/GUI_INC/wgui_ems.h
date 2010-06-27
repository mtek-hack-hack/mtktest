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
 * wgui_ems.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UI wrapper routines for EMS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      wgui_ems.h
   Author:         steven wu
   Date Created:  March-22-2003
   Contains:      UI wrapper routines for EMS and category screens
**********************************************************************************/

#ifndef __WGUI_EMS_H__
#define __WGUI_EMS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "gui_config.h"
#include "MMIDataType.h"

#if(!UI_DISABLE_EMS_CATEGORY_SCREENS)



#include "gui_ems.h"
#include "wgui_categories.h"

    /* EMS Application menus               */
    extern void GotoEMSTextFormattingMenu(void);
    extern void EntryEMSMainMenu(void);
    extern void ExitEMSMainMenu(void);
    extern void EntryEMSObjectsMenu(void);
    extern void ExitEMSObjectsMenu(void);
    extern void EntryEMSTextFormattingMenu(void);
    extern void ExitEMSTextFormattingMenu(void);
    extern void EntryEMSTextSizeSelectionMenu(void);
    extern void ExitEMSTextSizeSelectionMenu(void);
    extern void EntryEMSTextStyleSelectionMenu(void);
    extern void ExitEMSTextStyleSelectionMenu(void);
    extern void EntryEMSTextAlignmentSelectionMenu(void);
    extern void ExitEMSTextAlignmentSelectionMenu(void);
    extern void EntryEMSNewParagraphAlignmentMenu(void);
    extern void ExitEMSNewParagraphAlignmentMenu(void); 
    extern void EMS_inputbox_alphanumeric_keyboard_input_handler(S32 keyc);
    extern void EMS_inputbox_multitap_input(UI_character_type c);
    extern void EMS_inputbox_multitap_input_complete(void);
    
    /* External functions from wgui_categories   */
    extern U8 *dummy_get_history(U8 *buffer);
    extern S32 dummy_get_history_size(void);
    extern void show_input_mode(void);
    void register_hide_multitap(void (*f) (void));
    extern void category5_hide_multitap(void);
    extern void change_input_mode(void);
    extern void (*inputbox_change_mode) (void);
    extern void change_multiline_inputbox_input_mode(void);
    extern U8 MMI_current_input_mode;

    /* Leo start 20050722, remove compile warnings */
    extern void wgui_EMS_setup_input_information(S32 x, S32 y, S32 width, S32 height);
    extern void move_EMS_inputbox(S32 x, S32 y);
    extern void resize_EMS_inputbox(S32 width, S32 height);
    extern void wgui_EMS_redraw_input_information_bar(void);
    extern void show_EMS_inputbox(void);
    extern void get_EMS_inputbox_category_history(U16 history_ID, U8 *history_buffer, S16 input_type);
    extern U8 set_EMS_inputbox_category_history(U16 history_ID, U8 *history_buffer, S16 *input_type);
    /* Leo end 20050722 */
#define EMS_USE_INTERNAL_MENU             0
#define ENABLE_EMS_TEST_DEMO              0
#define EMS_USE_STUB_MENU                 0
#define ENABLE_EMS_TEST_OBJECTS              0
#define ENABLE_EMS_TEST_WORD_HIGHLIGHT       0
#define EMS_INPUTBOX_DEBUG                0
#define EMS_USE_GSM_EXTENDED              0


#define EMS_PREDEFINED_PICTURE         1
#define EMS_USERDEFINED_PICTURE        2
#define EMS_PREDEFINED_ANIMATION    3
#define EMS_USERDEFINED_ANIMATION      4
#define EMS_PREDEFINED_SOUND        5
#define EMS_PREDEFINED_MELODY       6
#define EMS_USERDEFINED_MELODY         7
#ifndef CATEGORY144_FMGR_PREVIEW
#define CATEGORY144_FMGR_PREVIEW    0x1000
#endif 
#define CATEGORY144_DISABLE_PREVIEW 0x0100
#define CATEGORY144_EMAIL_PREVIEW       0x0010
#ifdef __MMI_MESSAGES_EMS__
    extern EMSTATUS EMS_load_object(U32 type, U8 *data, S32 index, EMSObjData *object);
#endif 
    extern EMSTATUS EMS_inputbox_insert_predefined_picture(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_picture(U8 *data);
    extern EMSTATUS EMS_inputbox_insert_predefined_animation(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_animation(U8 *data);
    extern EMSTATUS EMS_inputbox_insert_predefined_sound(S32 index);
    extern EMSTATUS EMS_inputbox_insert_predefined_melody(S32 index);
    extern EMSTATUS EMS_inputbox_insert_userdefined_melody(U8 *data);

    extern void EMS_load_predefined_picture(S32 index, U8 *data);
    extern S32 EMS_get_predefined_picture_size(S32 index);
    extern S32 EMS_get_predefined_picture_data_size(U8 *data);
    extern S32 EMS_get_userdefined_picture_size(U8 *data);
    extern S32 EMS_get_predefined_animation_size(S32 index);
    extern S32 EMS_get_userdefined_animation_size(U8 *data);
    extern S32 EMS_get_predefined_sound_size(S32 index);
    extern void EMS_load_predefined_melody(S32 index, U8 *data);
    extern S32 EMS_get_predefined_melody_size(S32 index);
    extern S32 EMS_get_predefined_melody_data_size(U8 *data);
    extern S32 EMS_get_userdefined_melody_size(U8 *data);

    extern S32 EMS_check_userdefined_picture_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_predefined_picture_data_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_userdefined_animation_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_predefined_melody_data_size(U8 *data, U8 *allowed);
    extern S32 EMS_check_userdefined_melody_size(U8 *data, U8 *allowed);

    extern void EMS_userdefined_melody_attach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_userdefined_melody_detach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_predefined_melody_attach_header(U8 *src, U8 *dst, S32 *size);
    extern void EMS_predefined_melody_detach_header(U8 *src, U8 *dst, S32 *size);

    extern void EMS_inputbox_set_text_size(EMSFONTSIZE s);
    extern EMSFONTSIZE EMS_inputbox_get_text_size(void);
    extern void EMS_inputbox_set_text_style(U8 isBold, U8 isItalic, U8 isUnderline, U8 isStrikethrough);
    extern void EMS_inputbox_get_text_style(U8 *isBold, U8 *isItalic, U8 *isUnderline, U8 *isStrikethrough);
    extern EMSTATUS EMS_inputbox_set_text_alignment(EMSALIGNMENT a);
    extern EMSALIGNMENT EMS_inputbox_get_text_alignment(void);
    extern EMSTATUS EMS_inputbox_create_new_paragraph(EMSALIGNMENT a);
    extern void EMS_inputbox_backspace(void);
    extern	void EMS_inputbox_delete_all(void);
    extern U8 test_EMS_inputbox_change_mode(void);
    extern void initialize_EMS_objects(void);
    extern void register_EMS_inputbox_keys(void);
    extern	void change_EMS_inputbox_input_mode(void);
    extern	void wgui_EMS_inputbox_insert_symbol(UI_character_type symbol);
    extern void close_EMS_objects(void);
    extern void reset_EMS_inputbox(void);
    extern void register_EMS_inputbox_viewer_keys(void);
    extern	void create_EMS_viewer_header(U8 *message);
    extern void EMS_viewer_show_header(S32 x1, S32 y1, S32 x2, S32 y2);
    extern	S32 EMS_viewer_measure_header(void);
    extern void EMS_inputbox_handle_key_down(MMI_key_code_type k);
    extern void wgui_set_EMS_inputbox_RSK(void);
    extern void wgui_EMS_inputbox_handle_symbol_picker_star_key(void);
    extern void register_EMS_multitap_function(void);
    extern void EMS_inputbox_numeric_keyboard_input_handler(S32 keyc);




    extern void RedrawCategory28Screen(void);
    extern void ShowCategory28Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *history_buffer);
    extern void ExitCategory28Screen(void);
    extern S32 GetCategory28HistorySize(void);
    extern U8 *GetCategory28History(U8 *history_buffer);
    extern void CloseCategory28Screen(void);
    void SetCategory28RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern U8 AppendCategory28String(S16 input_type, EMSData *data, U8 *s, U8 *history_buffer);
    extern U8 AppendEMSString(S16 input_type, EMSData *data, U8 *s, U8 dcs, U8 *history_buffer);

    extern void RedrawCategory29Screen(void);
    extern void ShowCategory29Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *history_buffer);
    extern void ExitCategory29Screen(void);
    extern S32 GetCategory29HistorySize(void);
    extern U8 *GetCategory29History(U8 *history_buffer);
    extern void CloseCategory29Screen(void);

    extern void RedrawCategory39Screen(void);
    extern void ShowCategory39Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    EMSData *data,
                    U8 *header,
                    U8 *history_buffer);
    extern void ExitCategory39Screen(void);
    extern S32 GetCategory39HistorySize(void);
    extern U8 *GetCategory39History(U8 *history_buffer);
    extern void CloseCategory39Screen(void);

	typedef struct _EMS_inputbox_category_history
	{
		U16 history_ID;
		S16 cursor_ax, cursor_ay;
		S16 cursor_line_height;
		S16 display_y;
		S16 input_type;
             MMI_BOOL multitap_state;
		S16 UCS2_count;
		S16 text_offset;
#if defined(__MMI_TOUCH_SCREEN__)
		S16 vk_lang_type;
#endif 
	} EMS_inputbox_category_history;


    typedef struct
    {
        const U8 *data;
        kal_uint32 len;
    } ems_resource_struct;

    extern void move_EMS_inputbox(S32 x, S32 y);
    extern void resize_EMS_inputbox(S32 width, S32 height);
#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */ 

#ifdef __cplusplus
}
#endif 

#endif /* __WGUI_EMS_H__ */ 

