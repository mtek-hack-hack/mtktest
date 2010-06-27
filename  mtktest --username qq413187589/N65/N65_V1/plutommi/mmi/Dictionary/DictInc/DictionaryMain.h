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
 * DictionaryMain.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Dictionary UI implementation
 *
 * Author:
 * Rajbir Singh
 * -------
 *
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_DICTIONARYMAIN_H
#define _MMI_DICTIONARYMAIN_H

#include "MMIDatatype.h"
#include "gui_data_types.h"

#define DICTIONARY_MAX_WORDS 50000      /* this is maximum limit set for shortcut width rectange in title bar. */
#define DICTIONARY_INPUT_LENGTH 30      /* input buffer length for main dictionary, wildcard and exact search */
#define DICTIONARY_RESULT_LENGTH 5 * 1024
#define DICTIONARY_TTS_SETTING_TOTAL 2
#define DICTIONARY_TTS_SETTING_INLINE_NUM 6
/*Dictionary TTS speak speed*/
#define DICTIONARY_TTS_SLOW                 100
#define DICTIONARY_TTS_NORMAL             25
#define DICTIONARY_TTS_FAST        1

typedef enum    /* Search type : To differentiate between wildcard,exact and chinese string */
{
    DICTIONARY_WILDCARD_SEARCH,
    DICTIONARY_EXACT_SEARCH,
    DICTIONARY_BROWSE
} mmi_dictionary_search_type;

typedef struct
{
    S32 total_browse_entry;     /* Number of character present in main dictionary editor screen   */
    S32 starting_index;         /* starting index of first word in main dictionary browse screen  */
    S32 wildcard_results;       /* Number of wildcard result found  */
    S32 current_selected_index; /* Index of current selected word in list  */
    S32 current_wildcard_search_index;
    void*  app_mem_id;
    KAL_ADM_ID app_mem_pool;
} mmi_dictionary_cntx;

typedef enum
{
    DICTIONARY_ENGLISH,
    DICTIONARY_CHINESE,
    DICTIONARY_LANG_TOTAL,
    DICTIONARY_NONE
} MMI_DICTIONARY_LANGUAGE;


enum DICTIONARY_TTS_ONOFF
{
    DICTIONARY_TTS_STATE_ON,
    DICTIONARY_TTS_STATE_OFF,
    DICTIONARY_TTS_STATE_TOTAL
};


enum
{
    DICTIONARY_TTS_SPEAK_SLOW,
    DICTIONARY_TTS_SPEAK_NORMAL,
    DICTIONARY_TTS_SPEAK_FAST,
    DICTIONARY_TTS_SPEAK_TOTAL
};
enum
{
    DICTIONARY_TTS_SPEAK_VOLUME_0,
    DICTIONARY_TTS_SPEAK_VOLUME_1,
    DICTIONARY_TTS_SPEAK_VOLUME_2,
    DICTIONARY_TTS_SPEAK_VOLUME_3,
    DICTIONARY_TTS_SPEAK_VOLUME_4,
    DICTIONARY_TTS_SPEAK_VOLUME_5,
    DICTIONARY_TTS_SPEAK_VOLUME_6,
    DICTIONARY_TTS_SPEAK_VOLUME_TOTAL
};


typedef struct
{
    U8  *dict_setting_onoff[DICTIONARY_TTS_STATE_TOTAL];
    U8  *dict_setting_speak_speed[DICTIONARY_TTS_SPEAK_TOTAL];
    U8  *dict_setting_speak_volume[DICTIONARY_TTS_SPEAK_VOLUME_TOTAL];
    U8   dict_speak_volume_array[DICTIONARY_TTS_SPEAK_VOLUME_TOTAL][4];
    S32 HighligtItemonoff;
    S32 HighligtItemspeakspeed;
    S32 HighligtItemspeakvolume;
    S32 onoffbuffer;
    S32 speedbuffer;
    S32 volumebuffer;
}mmi_dictionary_tts_setting_inline;

extern void mmi_dictionary_init(void);
extern void mmi_dictionary_main_menu_highlight_hdlr(void);
extern void mmi_dictionary_show_meaning_highlight_hdlr(void);
extern void mmi_dictionary_wildcard_highlight_hdlr(void);
extern void mmi_dictionary_wildcard_word_list_hdlr(S32 index);
extern void mmi_dictionary_input_method_highlight_hdlr(void);
extern void mmi_dictionary_editor_option_search_highlight_hdlr(void);
extern void mmi_dictionary_setting_highlight_hdlr(void);
extern void mmi_dictionary_editor_option_input_method_highlight_hdlr(void);
extern void mmi_dictionary_word_hdlr(S32 index);
extern void mmi_dictionary_exact_highlight_hdlr(void);
extern S32 mmi_dictionary_find_entry(U8 *keyword);
extern pBOOL mmi_dictionary_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_dictionary_wildcard_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p,U8 str_img_mask);
extern void mmi_dictionary_entry_welcome_screen(void);
extern void mmi_dictionary_entry_main_screen(void);
extern void mmi_dictionary_entry_result_screen(void);
extern void mmi_dictionary_entry_main_option_screen(void);
extern void mmi_dictionary_entry_wildcard_exact_editor_screen(void);
extern void mmi_dictionary_entry_editor_option_screen(void);
extern void mmi_dictionary_entry_search(void);
extern void mmi_dictionary_entry_setting_screen(void);
extern void mmi_dictionary_entry_wildcard_result_list_screen(void);
extern void mmi_dictionary_pre_entry_main_screen(void);
extern MMI_BOOL mmi_dictionary_check_input_buffer(U8 *inputBuffer, U8 language);
extern MMI_DICTIONARY_LANGUAGE mmi_dictionary_check_input_family(U8 inputMethod);
extern MMI_DICTIONARY_LANGUAGE mmi_dictionary_check_input_family_bymode(U8 inputmode);
extern BOOL mmi_dictionary_flush_editor_buffer(void);
extern void mmi_dictionary_exit_main_screen(void);
extern BOOL isFromDictionary(S32 *);
extern BOOL mmi_dictionary_flush_exact_wild_editor_buffer(void);
extern U8 mmi_dictionary_exit_engine(void);
extern void DictionaryGoBackEditorScreen(void);
extern void DictionaryGoBackMainScreen(void);
extern pBOOL dictionary_dummy_function(void);
extern void mmi_dictionary_exit_wildcard_exact_editor_screen(void);
extern BOOL IsDictionaryLanguageChanged(U8 input_type);
void mmi_dictionary_create_adm_resource(void);
void mmi_dictionary_app_mem_stop_callback(void);
void mmi_dictionary_del_adm_resource(void);
void mmi_dictionary_tts_word_speak(void);
void mmi_dictionary_tts_phonic_switch(U16 *in_phonic, U16 *result_phonic);
void mmi_dict_play_tts_finish_ind(S32 result);
void mmi_dictionary_set_inline_item(void);
void mmi_dictionary_save_speak_setting(void);
void mmi_dictionary_setting_item_highlight_hdlr(S32 index);
U8 mmi_dictionary_get_tts_speed(void);
U8 mmi_dictionary_get_tts_volume(void);
#endif /* _MMI_DICTIONARYMAIN_H */ 

