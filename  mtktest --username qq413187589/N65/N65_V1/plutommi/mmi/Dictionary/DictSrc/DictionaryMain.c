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
 * DictionaryMain.c
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

#define __NEWSIMULATOR
#include "MMI_include.h"

#if defined(__MMI_DICTIONARY__) && defined(__MTK_TARGET__)

#include "Wgui_inline_edit.h"
#include "Ucs2prot.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "DictionaryMain.h"
#include "DictionaryResDef.h"
#include "Custom_mmi_default_value.h"
#include "Mdi_datatype.h"
#include "Mdi_audio.h"

#if defined(__MMI_DICT_GV__)
#include "DictionaryCoreGV.h"
#elif defined(__MMI_DICT_MOTECH__ )
#include "DictionaryCoreMOTECH.h"
#elif defined(__MMI_DICT_TRILOGY__ )
#include "DictionaryCoreTRILOGY.h"
#endif 

#undef __NEWSIMULATOR

/*
 * Local Variable
 */
static MMI_BOOL g_dictionary_last_item = MMI_FALSE;
static U8 g_mmi_dictionary_prev_input_mode;
static S32 g_dictionary_prev_index;
static S32 g_dictionary_highlighted_item;

static U8 g_dictionary_input_buffer[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];  					/* Input buffer on main dictionary screen */
static U8 *g_dictionary_wildcard_exact_buffer_p; 	/* input buffer for wildcard,exact and chinese string search */
static U8 *g_dictionary_input_p;
static U8 *g_dictionary_last_word_p;
static U8 *g_dictionary_first_displayed_buffer_p;
static U8 *g_dictionary_search_result_p;
static mmi_dictionary_search_type g_dictionary_search_type;    /* Search enum : can be Browse, Exact, Wildcard search */
mmi_dictionary_cntx g_dictionary_cntx;                  /* context stucture to hold various global flags */

#ifdef __MMI_DICTIONARY_TTS__
mmi_dictionary_tts_setting_inline g_dictionary_inline_cntx;
#endif

static S16 *g_dictionary_input_mode;   /* Input mode for dictionary screen */
static S16 g_dictionary_input_mode_Chinese_set[] = 
{
    INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    INPUT_MODE_SMART_UPPERCASE_ABC,
    INPUT_MODE_SMART_LOWERCASE_ABC,
    INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
#ifndef __MMI_DICT_MOTECH__
    INPUT_MODE_TR_MULTITAP_BOPOMO,
#endif
    INPUT_MODE_SM_MULTITAP_PINYIN,
#if !defined(__MMI_TOUCH_SCREEN__)
    #ifndef __MMI_DICT_MOTECH__
    INPUT_MODE_TR_BOPOMO,
    INPUT_MODE_TR_STROKE,
    #endif
    INPUT_MODE_SM_PINYIN,
    INPUT_MODE_SM_STROKE,
#endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
    -1
};

/*
 * Global Variable
 */
extern pBOOL GetUCS2Flag(PS8);
extern U8 MMI_current_input_mode;   /* Global variable to get the input method */
extern U8 wgui_multiline_inputbox_input_type;
extern U8 gactivatedprofile;
extern InlineItem wgui_inline_items[];
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
extern S16 MMI_prefered_input_type;
#endif

/* Adaptation layer structures */
mmi_dict_id_str_struct g_dict_wildcard_ids[MMI_DICT_ID_FETCH_MAX + 1],
    g_dict_chinese_ids[MMI_DICT_ID_FETCH_MAX + 1];
MMI_DICTIONARY_LANGUAGE g_dict_current_language, g_dictionary_language_main_screen;

/*
 * Global Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_DICTIONARY_MENU, mmi_dictionary_main_menu_highlight_hdlr);
    SetHiliteHandler(DICTIONARY_OPTION_SHOW_MEANING_MENU, mmi_dictionary_show_meaning_highlight_hdlr);
#ifdef __MMI_DICTIONARY_WILDCARD_SEARCH__
    SetHiliteHandler(DICTIONARY_OPTION_WILDCARD_SEARCH_MENU, mmi_dictionary_wildcard_highlight_hdlr);
#endif 
    SetHiliteHandler(DICTIONARY_OPTION_EXACT_SEARCH_MENU, mmi_dictionary_exact_highlight_hdlr);
#ifndef __MMI_DICTIONARY_SMALL_SCREEN__
    SetHiliteHandler(DICTIONARY_OPTION_INPUT_METHOD, mmi_dictionary_input_method_highlight_hdlr);
#endif 
    SetHiliteHandler(DICTIONARY_EDITOR_OPTION_SEARCH_MENU, mmi_dictionary_editor_option_search_highlight_hdlr);
#ifdef __MMI_DICTIONARY_TTS__
    SetHiliteHandler(DICTIONARY_OPTION_TTS_SETTING_MENU, mmi_dictionary_setting_highlight_hdlr);
#endif
    SetHiliteHandler(
        DICTIONARY_EDITOR_OPTION_INPUT_METHOD_MENU,
        mmi_dictionary_editor_option_input_method_highlight_hdlr);

    /* Assign input mode for the dictionary */
    g_dictionary_input_mode = g_dictionary_input_mode_Chinese_set;

    /*register ASM*/
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_DICTIONARY,
        STR_DICTIONARY_TITLE,
        IMG_DICTIONARY_TITLE,
        mmi_dictionary_app_mem_stop_callback);
}

/*
 * Local Function
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_app_mem_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free(g_dictionary_cntx.app_mem_pool);
    g_dictionary_cntx.app_mem_pool = NULL;
    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_DICTIONARY, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_main_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Dictionary menu in Extra menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_main_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_dictionary_entry_welcome_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_welcome_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_show_meaning_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Show Meaning in Dictionary option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_show_meaning_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    g_dictionary_search_type = DICTIONARY_BROWSE;
#ifdef __MMI_DICTIONARY_SMALL_SCREEN__
    g_dict_current_language = DICTIONARY_ENGLISH;
#else 
    g_dict_current_language = g_dictionary_language_main_screen;
#endif 
    SetLeftSoftkeyFunction(mmi_dictionary_entry_result_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_result_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_wildcard_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Wildcard Search menu in Dictionary option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_wildcard_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    g_dictionary_search_type = DICTIONARY_WILDCARD_SEARCH;

    SetLeftSoftkeyFunction(mmi_dictionary_entry_wildcard_exact_editor_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_wildcard_exact_editor_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exact_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the Exact Search menu in Dictionary option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_exact_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    g_dictionary_search_type = DICTIONARY_EXACT_SEARCH;

    SetLeftSoftkeyFunction(mmi_dictionary_entry_wildcard_exact_editor_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_wildcard_exact_editor_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_input_method_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the input method menu in Dictionary option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_input_method_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(DictionaryGoBackMainScreen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_editor_option_search_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the search menu in Dictionary editor option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_editor_option_search_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_dictionary_entry_search, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_editor_option_input_method_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the input method menu in Dictionary option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_editor_option_input_method_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(DictionaryGoBackEditorScreen);
}


/*****************************************************************************
 * FUNCTION
 *  DictionaryGoBackMainScreen
 * DESCRIPTION
 *  Go back to Main dictionary screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DictionaryGoBackMainScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_DICTIONARY_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  DictionaryGoBackEditorScreen
 * DESCRIPTION
 *  Go back to  dictionary editor screen(exact/wildcard).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DictionaryGoBackEditorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_DICTIONARY_WILDCARD_EXACT_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_welcome_screen
 * DESCRIPTION
 *  Welcome screen, when user enter first time in this screen,a customer logo is shown.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_welcome_screen(void)
{
#ifdef __MMI_DICTIONARY_WELCOME_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_WELCOME_SCREEN);
    EntryNewScreen(SCR_DICTIONARY_WELCOME_SCREEN, NULL, mmi_dictionary_entry_welcome_screen, NULL);

    ShowCategory129Screen(
        (U8*) get_string(STR_DICTIONARY_TITLE),
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_DICTIONARY_LOGO,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_dictionary_pre_entry_main_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#else /* __MMI_DICTIONARY_WELCOME_SCREEN__ */ 
    mmi_dictionary_pre_entry_main_screen();
#endif /* __MMI_DICTIONARY_WELCOME_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_pre_entry_main_screen
 * DESCRIPTION
 *  initialize dictionary database
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_pre_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL dictResult;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void));
    
    /*ASM alloc,adm create*/
    if(g_dictionary_cntx.app_mem_pool == NULL)
    {
        g_dictionary_cntx.app_mem_pool = 
            applib_mem_ap_alloc(APPLIB_MEM_AP_ID_DICTIONARY, DICTIONARY_APP_TOTAL_SIZE);
        if(g_dictionary_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_DICTIONARY,
                IMG_DICTIONARY_TITLE,
                DICTIONARY_APP_TOTAL_SIZE,
                mmi_dictionary_pre_entry_main_screen);
            return;
        }
        mmi_dictionary_create_adm_resource();
    }
    
    /*engine init*/
    dictResult = mmi_dict_init();
    if (dictResult == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_DICTIONARY_TTS__    
    ReadValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemonoff == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemonoff = DICTIONARY_TTS_STATE_ON;
        WriteValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    }
    
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemspeakspeed == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemspeakspeed = DICTIONARY_TTS_SPEAK_NORMAL;
        WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    }

    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME,&g_dictionary_inline_cntx.HighligtItemspeakvolume, DS_BYTE, &error);
    if(g_dictionary_inline_cntx.HighligtItemspeakvolume == 0xFF)
    {
        g_dictionary_inline_cntx.HighligtItemspeakvolume = DICTIONARY_TTS_SPEAK_VOLUME_4;
        WriteValue(
            NVRAM_DICTIANRY_TTS_SPEAK_VOLUME,
            &g_dictionary_inline_cntx.HighligtItemspeakvolume,
            DS_BYTE,
            &error);
    }
    mdi_audio_suspend_background_play();    /*this line is used to suspend audio player*/
#endif /* __MMI_DICTIONARY_TTS__ */ 
    memset(g_dictionary_input_buffer, 0, ENCODING_LENGTH);
    mmi_dictionary_entry_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_create_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_dictionary_create_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_dictionary_cntx.app_mem_id 
        = kal_adm_create((void*)g_dictionary_cntx.app_mem_pool, DICTIONARY_APP_TOTAL_SIZE, NULL, MMI_FALSE);
	ASSERT(g_dictionary_cntx.app_mem_id != NULL);

	g_dictionary_wildcard_exact_buffer_p 
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_wildcard_exact_buffer_p != NULL);
	g_dictionary_input_p 
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_input_p != NULL);
	g_dictionary_last_word_p
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_last_word_p != NULL);
	g_dictionary_first_displayed_buffer_p
        = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, (MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH);
	ASSERT(g_dictionary_first_displayed_buffer_p != NULL);
    g_dictionary_search_result_p = (U8*) kal_adm_alloc(g_dictionary_cntx.app_mem_id, DICTIONARY_RESULT_LENGTH);
	ASSERT(g_dictionary_search_result_p != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_main_screen
 * DESCRIPTION
 *  Entry function for main dictionary screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 cnt;
    MMI_DICTIONARY_LANGUAGE currentLanguage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_search_type = DICTIONARY_BROWSE;
    g_dictionary_prev_index = -1;

    EntryNewScreen(SCR_DICTIONARY_MAIN, mmi_dictionary_exit_main_screen, mmi_dictionary_entry_main_screen, NULL);
    SetDelScrnIDCallbackHandler((U16)SCR_DICTIONARY_MAIN, (HistoryDelCBPtr)mmi_dictionary_exit_engine);
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_MAIN);
    RegisterCat200SearchFunction(mmi_dictionary_find_entry);
    RegisterHighlightHandler(mmi_dictionary_word_hdlr);

    if (guiBuffer == NULL)
    {
        memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
        g_dictionary_cntx.current_selected_index = 0;
        wgui_multiline_inputbox_input_type = 0;

        /* Default language is English for first time entry */
#if defined(__MMI_PREFER_INPUT_METHOD__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        g_dict_current_language = mmi_dictionary_check_input_family(MMI_prefered_input_type);
#else
        g_dict_current_language = mmi_dictionary_check_input_family(INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
#endif
        switch(g_dict_current_language)
        {
        case DICTIONARY_ENGLISH:
            {
        mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
        cnt = mmi_dict_exact_search_id(
                    (PS8) g_dictionary_input_p,
                    (U8) g_dict_current_language,
                    (U8) ! g_dict_current_language);
        g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
        g_dictionary_cntx.starting_index = cnt;
            }
            break;

        case DICTIONARY_CHINESE:
            {
                g_dictionary_cntx.total_browse_entry = 0;
                g_dictionary_cntx.starting_index = 0;
            }
            break;

        default:
            {
                g_dict_current_language = DICTIONARY_ENGLISH;
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                g_dictionary_cntx.starting_index = cnt;
            }
            break;
        }

        ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        memset(g_dictionary_last_word_p, 0, ENCODING_LENGTH);

        /*
         *  Previous input method is just set to any member of previous family. Here Family is important to know.
         *  the assigned mode can be any mode from a family
         */
        g_dict_current_language = g_dictionary_language_main_screen;
        switch (g_dict_current_language)
        {
            case DICTIONARY_ENGLISH:
                g_mmi_dictionary_prev_input_mode = INPUT_MODE_MULTITAP_LOWERCASE_ABC;
                break;
            case DICTIONARY_CHINESE:
                g_mmi_dictionary_prev_input_mode = INPUT_MODE_TR_MULTITAP_BOPOMO;
                break;
            default:
                g_mmi_dictionary_prev_input_mode = INPUT_MODE_MULTITAP_LOWERCASE_ABC;
        }

        /* 
         *  wgui_multiline_inputbox_input_type =0 means set to none.
         *  wgui_multiline_inputbox_input_type is set when input method is changed from "input method" option.
         */
        if (wgui_multiline_inputbox_input_type != 0)
        {
            currentLanguage = mmi_dictionary_check_input_family((U8) wgui_multiline_inputbox_input_type);

            if (currentLanguage != g_dict_current_language)
            {
                switch (currentLanguage)
                {
                    case DICTIONARY_ENGLISH:
                        mmi_asc_to_ucs2((S8*) g_dictionary_input_p, (S8*) "a");
                        cnt = mmi_dict_exact_search_id(
                                (PS8) g_dictionary_input_p,
                                (U8) g_dict_current_language,
                                (U8) ! g_dict_current_language);
                        g_dictionary_cntx.total_browse_entry = (S32) mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                        g_dictionary_cntx.starting_index = cnt;
                        break;
                    case DICTIONARY_CHINESE:
                        g_dictionary_cntx.total_browse_entry = 0;
                        g_dictionary_cntx.starting_index = 0;
                        break;
                    default:
                        g_dictionary_cntx.total_browse_entry = 0;
                        g_dictionary_cntx.starting_index = 0;
                }

            }
        }
    }

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif 
    Register_pound_key_buffer_flush_test_function(mmi_dictionary_flush_editor_buffer);
    Register_appl_present_function(isFromDictionary);

#ifdef __MMI_DICTIONARY_SMALL_SCREEN__
    ShowCategory200Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dictionary_cntx.total_browse_entry,
        mmi_dictionary_list_get_item,
        NULL,
        0,
        IMG_DICTIONARY_SEARCH,
        (U8*) g_dictionary_input_buffer,
        DICTIONARY_INPUT_LENGTH + 1,
        guiBuffer);

    SetCategory200RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#else /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 

    wgui_set_e_dictionary_test_clear_inputbox_buffer_funcptr(dictionary_dummy_function);
    cat201_register_language_changed_indicator(IsDictionaryLanguageChanged);
    ShowCategory201Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_dictionary_cntx.total_browse_entry,
        mmi_dictionary_list_get_item,
        NULL,
        0,
        IMG_DICTIONARY_SEARCH,
        (U8*) g_dictionary_input_buffer,
        DICTIONARY_INPUT_LENGTH + 1,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        guiBuffer,
        g_dictionary_input_mode);

    SetCategory201RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 

    g_mmi_dictionary_prev_input_mode = MMI_current_input_mode;

    SetCategory200LeftSoftkeyFunction(mmi_dictionary_entry_main_option_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_dictionary_entry_main_option_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_main_screen
 * DESCRIPTION
 *  Exit function for main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_exit_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DICTIONARY_TTS__)
    StopTimer(DICTIONARY_TTS_TIMER);
#endif
    if(g_dictionary_last_word_p != NULL && g_dictionary_first_displayed_buffer_p != NULL)
    {
        memset(g_dictionary_last_word_p, 0, ENCODING_LENGTH);
        memset(g_dictionary_first_displayed_buffer_p, 0, ENCODING_LENGTH);
    }
    if(g_dictionary_cntx.app_mem_id != NULL)
    {
        g_dictionary_language_main_screen = g_dict_current_language;
        g_dictionary_highlighted_item = DynamicListGetHighlightedItem((U8*) g_dictionary_last_word_p);
        DynamicGetFirstDisplayedItem((U8*) g_dictionary_first_displayed_buffer_p);
        g_dictionary_prev_index = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dictionary_dummy_function
 * DESCRIPTION
 *  dummy function assigned
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL dictionary_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  IsDictionaryLanguageChanged
 * DESCRIPTION
 *  This function tell the GUI layer if language has been changes while coming back from history
 * PARAMETERS
 *  input_type      [IN]        changed input type
 * RETURNS
 *  BOOL TRUE : language has been changed.
 *  FALSE : language is not changed
 *****************************************************************************/
BOOL IsDictionaryLanguageChanged(U8 input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE currentLanguage;
    MMI_BOOL languageChanged = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentLanguage = mmi_dictionary_check_input_family((U8) input_type);

    if (g_dict_current_language != currentLanguage)
    {
        languageChanged = MMI_TRUE;
    }
    else
    {
        languageChanged = MMI_FALSE;
    }
    g_dict_current_language = currentLanguage;
    
    return languageChanged;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_engine
 * DESCRIPTION
 *  Exit function dictionary. Deinitilize dictionary memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_exit_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_dict_exit();
    #if defined(__MMI_DICTIONARY_TTS__)
    mdi_audio_resume_background_play();  /*this line is used to resume audio player*/
    #endif
    mmi_dictionary_del_adm_resource();
    applib_mem_ap_free(g_dictionary_cntx.app_mem_pool);
    g_dictionary_cntx.app_mem_pool = NULL;
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_del_adm_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_del_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_wildcard_exact_buffer_p);
    g_dictionary_wildcard_exact_buffer_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_input_p);
    g_dictionary_input_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_last_word_p);
    g_dictionary_last_word_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_first_displayed_buffer_p);
    g_dictionary_first_displayed_buffer_p = NULL;
    
    kal_adm_free(g_dictionary_cntx.app_mem_id, g_dictionary_search_result_p);
    g_dictionary_search_result_p = NULL;

    kal_adm_delete(g_dictionary_cntx.app_mem_id);
    g_dictionary_cntx.app_mem_id = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_word_hdlr
 * DESCRIPTION
 *  General highlight handler for word list in main dictionary screen
 * PARAMETERS
 *  index       [IN]        UI index of current selected word.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_word_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S32 dynamicItems;
    U8 g_dictionary_output[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_cntx.current_selected_index = index;
    g_dictionary_prev_index = index;
    memset(g_dictionary_input_p, 0, ENCODING_LENGTH);
    DynamicListGetHighlightedItem((U8*) g_dictionary_last_word_p);
    dynamicItems = DynamicListGetItems(NULL, 0);
#ifdef __MMI_DICTIONARY_TTS__
    if(g_dictionary_inline_cntx.HighligtItemonoff == DICTIONARY_TTS_STATE_ON && 
        gactivatedprofile != MMI_PROFILE_SILENT)
    {
        StopTimer(DICTIONARY_TTS_TIMER);
        StartTimer(DICTIONARY_TTS_TIMER, 500, mmi_dictionary_tts_word_speak);
    }
#endif /* __MMI_DICTIONARY_TTS__ */ 
    if (index <= 0)
    {
        ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
        return;
    }
    else
    {
        SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    }

    if (g_dict_current_language == DICTIONARY_ENGLISH)
    {

        if (g_dictionary_last_item || dynamicItems < 6)
        {
            return;
        }

        if (index >= (S32) (dynamicItems - 1))
        {
            /* this function is called to find out :whether further words exist in the word list */
            result = mmi_dict_get_word_by_indx(
                        (U8) g_dict_current_language,
                        (U16) (g_dictionary_cntx.starting_index + index + 1),
                        (S8*) g_dictionary_output);

            if (result == MMI_TRUE)
            {
                g_dictionary_last_item = MMI_FALSE;
            }
            else
            {
                g_dictionary_last_item = MMI_TRUE;
            }

            g_dictionary_cntx.total_browse_entry++;
            DynamicListIncreaseItem((S16) 1);

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_list_get_item
 * DESCRIPTION
 *  Fill the UI list for display, on request from UI.
 *  mmi_dict_exact_search_id/mmi_dict_exact_search_prev_id/mmi_dict_exact_search_next_id : set the focus to the word,
 *  mmi_dict_get_word_by_indx : get the focused word
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dictionary_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 g_dictionary_output[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    MMI_BOOL result, bufferCheck;
    S32 index = 0;
    S32 steps;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_MAIN);
    memset(g_dictionary_input_p, 0, ENCODING_LENGTH);

    if (g_dict_current_language == DICTIONARY_ENGLISH)
    {
        /* there is no need to give first 32 elements while coming to history ,when highlighted item is > 35 */
        if (guiBuffer && (g_dictionary_highlighted_item >= 35) && (item_index <= 31))
        {
            index = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
            str_buff = NULL;
            *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
            return MMI_TRUE;
        }

        /* While coming back from history, and UI gets the items to display */
        if (guiBuffer && (item_index > 31))
        {
            steps = DynamicGetFirstDisplayedItem(NULL) - item_index;
            mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_first_displayed_buffer_p);
            if (steps > 0)
            {
                index = mmi_dict_exact_search_prev_id(
                            (PS8) g_dictionary_input_p,
                            (steps),
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
            }
            else
            {
                index = mmi_dict_exact_search_next_id(
                            (PS8) g_dictionary_input_p,
                            (-steps),
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
            }

        }
        else if (item_index == 0)
        {
            mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_input_buffer);
            bufferCheck = mmi_dictionary_check_input_buffer((U8*) g_dictionary_input_p, (U8) g_dict_current_language);

            if (bufferCheck == MMI_TRUE)
            {
                index = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
            else
            {
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                index = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = index;
            }
        }
        else if (g_dictionary_prev_index > item_index)
        {
            /* get the dynamic element from UI. */
            DynamicListGetItems((U8*) g_dictionary_input_p, (U16) (item_index + 1));
            index = mmi_dict_exact_search_prev_id(
                        (PS8) g_dictionary_input_p,
                        1,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
        }
        else if (g_dictionary_prev_index < item_index)
        {
            /* get the dynamic element from UI. */
            DynamicListGetItems((U8*) g_dictionary_input_p, (U16) (item_index - 1));
            index = mmi_dict_exact_search_next_id(
                        (PS8) g_dictionary_input_p,
                        1,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
        }

        memset(g_dictionary_output, 0, ENCODING_LENGTH);
        result = mmi_dict_get_word_by_indx((U8) g_dict_current_language, (U16) (index), (S8*) g_dictionary_output);
        mmi_ucs2cpy((S8*) str_buff, (S8*) g_dictionary_output);
        *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);

        g_dictionary_prev_index = item_index;

        return MMI_TRUE;
    }

#ifndef __MMI_DICTIONARY_SMALL_SCREEN__
    if (g_dict_current_language == DICTIONARY_CHINESE)
    {
        if (item_index < g_dictionary_cntx.total_browse_entry)
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) g_dict_chinese_ids[item_index].dict_word);
            *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
            return MMI_TRUE;

        }
        return MMI_FALSE;
    }
#endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_find_entry
 * DESCRIPTION
 *  Find the entries in dictionary based upon the input buffer.
 * PARAMETERS
 *  keyword     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dictionary_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stringLength, cnt = 0;
    MMI_BOOL bufferCheck;

#ifndef __MMI_DICTIONARY_SMALL_SCREEN__
    U16 resultCount;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_last_item = MMI_FALSE;
    g_dictionary_prev_index = 0;

    switch (MMI_current_input_mode)
    {
    #ifndef __MMI_DICTIONARY_SMALL_SCREEN__
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
        case INPUT_MODE_MMI_LOWERCASE_ABC:
    #else /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
        case INPUT_MODE_MMI_LOWERCASE_ABC:
    #endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ 
        {
            stringLength = mmi_ucs2strlen((S8*) keyword);
            g_dict_current_language = DICTIONARY_ENGLISH;
            memset(g_dictionary_input_p, 0, ENCODING_LENGTH);

            if (stringLength > 0)
            {
                mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) keyword);
                bufferCheck = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (bufferCheck == MMI_FALSE)
                {
                    /* First character  is not alphabet */
                    g_dictionary_cntx.starting_index = 0;
                    mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                    cnt = mmi_dict_exact_search_id(
                            (PS8) g_dictionary_input_p,
                            (U8) g_dict_current_language,
                            (U8) ! g_dict_current_language);
                    g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((S8*) g_dictionary_input_p);
                    break;
                }

                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = cnt;
                g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                break;
            }
            else
            {
                g_dict_current_language = DICTIONARY_ENGLISH;
                mmi_asc_to_ucs2((S8*) g_dictionary_input_p, "a");
                cnt = mmi_dict_exact_search_id(
                        (PS8) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) ! g_dict_current_language);
                g_dictionary_cntx.starting_index = cnt;
                g_dictionary_cntx.total_browse_entry = mmi_dict_get_total_num((PS8) g_dictionary_input_p);
                break;
            }
            break;
        }

    #ifndef __MMI_DICTIONARY_SMALL_SCREEN__
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_BOPOMO:

            g_dict_current_language = DICTIONARY_CHINESE;
            stringLength = mmi_ucs2strlen((S8*) keyword);
            memset(g_dictionary_input_p, 0, ENCODING_LENGTH);
            memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
            g_dictionary_cntx.current_selected_index = 0;
            if (stringLength != 0)
            {
                mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) keyword);
                bufferCheck = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (bufferCheck == MMI_FALSE)
                {
                    /* First character  is not chinese character */
                    g_dictionary_cntx.starting_index = 0;
                    g_dictionary_cntx.total_browse_entry = 0;
                    break;

                }

                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*)g_dict_chinese_ids);
                g_dictionary_cntx.starting_index = 0;
                g_dictionary_cntx.total_browse_entry = resultCount;
                break;
            }
            else
            {
                memset(g_dict_chinese_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                g_dictionary_cntx.starting_index = 0;
                g_dictionary_cntx.total_browse_entry = 0;
                break;
            }

            break;
    #endif /* __MMI_DICTIONARY_SMALL_SCREEN__ */ /* ifndef  __MMI_DICTIONARY_SMALL_SCREEN__ */
        default:
            g_dict_current_language = DICTIONARY_NONE;
            g_dictionary_cntx.starting_index = 0;
            g_dictionary_cntx.total_browse_entry = 0;
            break;
    }

    return g_dictionary_cntx.total_browse_entry;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_result_screen
 * DESCRIPTION
 *  Entry screen for result screen. Shows the meaning of word to the user.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_result_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 *guibuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DICTIONARY_RESULT, NULL, mmi_dictionary_entry_result_screen, NULL);

    guibuffer = GetCurrGuiBuffer(SCR_DICTIONARY_RESULT);
    DeleteScreenIfPresent(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);

    switch (g_dictionary_search_type)
    {
        case DICTIONARY_BROWSE:
            if (g_dict_current_language == DICTIONARY_ENGLISH)
            {
                result = mmi_dict_exact_search(
                            (S8*) g_dictionary_last_word_p,
                            (U8) g_dict_current_language,
                            (U8) (!g_dict_current_language),
                            MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                            g_dictionary_search_result_p);
            }
            else if (g_dict_current_language == DICTIONARY_CHINESE)
            {
                if (mmi_ucs2strlen((S8*) g_dict_chinese_ids[g_dictionary_cntx.current_selected_index].dict_word))
                {
                    result = mmi_dict_exact_search(
                                (S8*) g_dict_chinese_ids[g_dictionary_cntx.current_selected_index]. dict_word,
                                (U8) g_dict_current_language,
                                (U8) (!g_dict_current_language),
                                MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                                g_dictionary_search_result_p);
                }
                else
                {
                    result = MMI_FALSE;
                }
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
        case DICTIONARY_WILDCARD_SEARCH:
            result = mmi_dict_exact_search(
                        (S8*) g_dict_wildcard_ids[g_dictionary_cntx.current_wildcard_search_index]. dict_word,
                        (U8) g_dict_current_language,
                        (U8) (!g_dict_current_language),
                        MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                        g_dictionary_search_result_p);
            break;
        case DICTIONARY_EXACT_SEARCH:
            result = mmi_dict_exact_search(
                        (S8*) g_dictionary_input_p,
                        (U8) g_dict_current_language,
                        (U8) (!g_dict_current_language),
                        MMI_DICT_SYNO | MMI_DICT_ANTO | MMI_DICT_SENTS,
                        g_dictionary_search_result_p);
            break;
    }

    if (result == MMI_FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_DICTIONARY_NO_MATCH_FOUND),
            IMG_GLOBAL_WARNING,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        DeleteNScrId(SCR_DICTIONARY_RESULT);
        return;
    }

    ShowCategory78Screen(
        STR_DICTIONARY_TITLE,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        (U8*) g_dictionary_search_result_p,
        mmi_ucs2strlen((S8*) g_dictionary_search_result_p),
        guibuffer /* guiBuffer */ );
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_main_option_screen
 * DESCRIPTION
 *  Entry screen for dictionary option  screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_main_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];    /* Need Expansion when has more options. */
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DICTIONARY_OPTION, NULL, mmi_dictionary_entry_main_option_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_OPTION);
    nNumofItem = GetNumOfChild(DICTIONARY_OPTION_MENU);
    GetSequenceStringIds(DICTIONARY_OPTION_MENU, nStrItemList);
    SetParentHandler(DICTIONARY_OPTION_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_wildcard_exact_editor_screen
 * DESCRIPTION
 *  Entry screen for wildcard, exact and chinese string search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_wildcard_exact_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 strID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_DICTIONARY_WILDCARD_EXACT_EDITOR,
        mmi_dictionary_exit_wildcard_exact_editor_screen,
        mmi_dictionary_entry_wildcard_exact_editor_screen,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_WILDCARD_EXACT_EDITOR);

    switch (g_dictionary_search_type)
    {
        case DICTIONARY_WILDCARD_SEARCH:
    #ifdef __MMI_DICT_GV__
            strID = STR_DICTIONARY_WILDCARD_SEARCH;
    #endif 

            break;
        case DICTIONARY_EXACT_SEARCH:
            strID = STR_DICTIONARY_EXACT_SEARCH;
            break;
    }

    Register_cat5_editor_buffer_need_flush(mmi_dictionary_flush_exact_wild_editor_buffer);
    ShowCategory5Screen_ext(
        strID,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (PU8) g_dictionary_wildcard_exact_buffer_p,
        DICTIONARY_INPUT_LENGTH + 1,
        guiBuffer,
        0,
        g_dictionary_input_mode,
        NULL);

    SetLeftSoftkeyFunction(mmi_dictionary_entry_editor_option_screen, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    g_mmi_dictionary_prev_input_mode = MMI_current_input_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_exit_wildcard_exact_editor_screen
 * DESCRIPTION
 *  Exit function for exact/wildcard buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_exit_wildcard_exact_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_multiline_inputbox_input_type = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_editor_option_screen
 * DESCRIPTION
 *  Entry function for editor option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_editor_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[2];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DICTIONARY_EDITOR_OPTION_SCREEN, NULL, mmi_dictionary_entry_editor_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
    nNumofItem = GetNumOfChild(DICTIONARY_EDITOR_OPTION_MENU);
    GetSequenceStringIds(DICTIONARY_EDITOR_OPTION_MENU, nStrItemList);
    SetParentHandler(DICTIONARY_EDITOR_OPTION_MENU);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_search
 * DESCRIPTION
 *  This function search the database according to input in wildcard/exact search buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resultCount = 0;
    U8 length;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((S8*) g_dictionary_wildcard_exact_buffer_p);

    length = length * 2;
    if (length == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_WARNING,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
        return;
    }
    mmi_ucs2cpy((S8*) g_dictionary_input_p, (S8*) g_dictionary_wildcard_exact_buffer_p);

    if (g_dictionary_search_type == DICTIONARY_WILDCARD_SEARCH)
    {
        switch (MMI_current_input_mode)
        {
            case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            case INPUT_MODE_SMART_UPPERCASE_ABC:
            case INPUT_MODE_SMART_LOWERCASE_ABC:
                /* clean the string .check: for english string only */

                g_dict_current_language = DICTIONARY_ENGLISH;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }

                memset(g_dict_wildcard_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*)g_dict_wildcard_ids);
                if (resultCount != 0)
                {
                    g_dictionary_cntx.wildcard_results = resultCount;
                    mmi_dictionary_entry_wildcard_result_list_screen();
                }
                break;

            case INPUT_MODE_TR_MULTITAP_BOPOMO:
            case INPUT_MODE_TR_STROKE:
            case INPUT_MODE_SM_MULTITAP_PINYIN:
            case INPUT_MODE_SM_STROKE:
            case INPUT_MODE_SM_PINYIN:
            case INPUT_MODE_TR_BOPOMO:
                /* clean the string .check: for chinese string only  */
                g_dict_current_language = DICTIONARY_CHINESE;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }

                memset(g_dict_wildcard_ids, 0, sizeof(mmi_dict_id_str_struct) * (MMI_DICT_ID_FETCH_MAX + 1));
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                resultCount = mmi_dict_wild_search(
                                (U8) g_dict_current_language,
                                (S8*) g_dictionary_input_p,
                                0,
                                MMI_DICT_ID_FETCH_MAX,
                                (void*) /* g_dict_chinese_ids */ g_dict_wildcard_ids);
                if (resultCount != 0)
                {
                    g_dictionary_cntx.wildcard_results = resultCount;
                    mmi_dictionary_entry_wildcard_result_list_screen();

                }
                break;

            default:
                DisplayPopup(
                    (PU8) GetString(STR_DICTIONARY_LANGUAGE_NOT_SUPPORTED),
                    IMG_GLOBAL_WARNING,
                    MMI_FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
                break;

        }
        if (resultCount == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_DICTIONARY_NO_MATCH_FOUND),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
        }
        else if (result == MMI_FALSE)
        {
            DisplayPopup(
                (PU8) GetString(STR_DICTIONARY_NO_MATCH_FOUND),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
        }
    }
    else if (g_dictionary_search_type == DICTIONARY_EXACT_SEARCH)
    {
        switch (MMI_current_input_mode)
        {
            case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
            case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
            case INPUT_MODE_SMART_UPPERCASE_ABC:
            case INPUT_MODE_SMART_LOWERCASE_ABC:
                /* clean the string  */
                g_dict_current_language = DICTIONARY_ENGLISH;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                mmi_dictionary_entry_result_screen();
                break;
            case INPUT_MODE_TR_MULTITAP_BOPOMO:
            case INPUT_MODE_TR_STROKE:
            case INPUT_MODE_SM_MULTITAP_PINYIN:
            case INPUT_MODE_SM_STROKE:
            case INPUT_MODE_SM_PINYIN:
            case INPUT_MODE_TR_BOPOMO:
                /* clean the string */
                g_dict_current_language = DICTIONARY_CHINESE;
                result = mmi_dictionary_check_input_buffer(g_dictionary_input_p, (U8) g_dict_current_language);
                if (result == MMI_FALSE)
                {
                    break;
                }
                /* DictionaryWaitingPopup(IMG_DICTIONARY_WAIT); */
                mmi_dictionary_entry_result_screen();
                break;
            default:
                DisplayPopup(
                    (PU8) GetString(STR_DICTIONARY_LANGUAGE_NOT_SUPPORTED),
                    IMG_GLOBAL_WARNING,
                    MMI_FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
                break;
        }

        /* result popup */
        if (result == MMI_FALSE)
        {
            DisplayPopup(
                (PU8) GetString(STR_DICTIONARY_NO_MATCH_FOUND),
                IMG_GLOBAL_WARNING,
                MMI_FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            DeleteNScrId(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
        }
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_check_input_buffer
 * DESCRIPTION
 *  This function check the input buffer according to language passed
 * PARAMETERS
 *  inputBuffer     [?]         
 *  language        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dictionary_check_input_buffer(U8 *inputBuffer, U8 language)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length, cnt = 0;
    S16 end_cnt;
    U8 tempBuf[(MMI_DICT_CORE_WORD_MAX + 1) * ENCODING_LENGTH];
    U16 chineseCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filter out any space in the beginning */
    mmi_ucs2cpy((S8*) tempBuf, (S8*) inputBuffer);
    length = mmi_ucs2strlen((S8*) inputBuffer);
    length = length * ENCODING_LENGTH;
    while (length > cnt)
    {
        if ((tempBuf[cnt] == 0x20 || tempBuf[cnt] == 0x0A || tempBuf[cnt] == 0x0D) && (tempBuf[cnt + 1] == 0x00))       /* if first character is space */
        {
            cnt = cnt + 2;
            continue;
        }
        else
        {
            break;
        }
    }

    if (cnt == length)
    {
        /* user has entered only spaces in editor screen */
        return MMI_FALSE;
    }

    /* filter out any space in the end */
    end_cnt = length - 1;
    while (end_cnt > 0)
    {
        if ((tempBuf[end_cnt - 1] == 0x20) && (tempBuf[end_cnt] == 0x00))
        {
            end_cnt = end_cnt - 2;
        }
        else
        {
            break;
        }
    }
    memset(&tempBuf[end_cnt + 1], 0, 2);

    if (cnt != length)
    {
        mmi_ucs2cpy((S8*) inputBuffer, (S8*) & tempBuf[cnt]);    /* copy after intitial space */

        switch (language)
        {
            case DICTIONARY_ENGLISH:

                /* first char have to be  english alphabet only */
                if (!((inputBuffer[0] >= 65) && (inputBuffer[0] <= 90))
                    && !((inputBuffer[0] >= 97) && (inputBuffer[0] <= 122)))
                {
                    return MMI_FALSE;
                }
                /* there should not be any chinese character in english string */
                if (GetUCS2Flag((S8*) inputBuffer))
                {
                    return MMI_FALSE;
                }
                break;

            case DICTIONARY_CHINESE:

                memcpy(&chineseCode, &inputBuffer[0], 2);
                if ((chineseCode < 0x4e00) || (chineseCode > 0x9fa5))
                {
                    /* First character  is not chinese character */
                    return MMI_FALSE;
                }

                break;

        }

    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_wildcard_result_list_screen
 * DESCRIPTION
 *  This function shows the search result of wildcard and chinese search strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_wildcard_result_list_screen(void)
{
#ifdef __MMI_DICT_GV__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DICTIONARY_WILDCARD_RESULT_LIST, NULL, mmi_dictionary_entry_wildcard_result_list_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_DICTIONARY_WILDCARD_RESULT_LIST);
    RegisterHighlightHandler(mmi_dictionary_wildcard_word_list_hdlr);
    DeleteScreenIfPresent(SCR_DICTIONARY_EDITOR_OPTION_SCREEN);
    ShowCategory184Screen(
                             STR_DICTIONARY_WILDCARD_SEARCH,
                             GetRootTitleIcon(EXTRA_DICTIONARY_MENU),
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK, g_dictionary_cntx.wildcard_results, mmi_dictionary_wildcard_list_get_item,
                             /* HintPtr */ 0,
                             0, guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_dictionary_entry_result_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_result_screen, KEY_ENTER, KEY_EVENT_DOWN);
#endif /* __MMI_DICT_GV__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_wildcard_list_get_item
 * DESCRIPTION
 *  This function is to pass the wildcard and chinese strings to the UI to display
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_dictionary_wildcard_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < g_dictionary_cntx.wildcard_results)
    {

        mmi_ucs2cpy((S8*) str_buff, (S8*) g_dict_wildcard_ids[item_index].dict_word);
        *img_buff_p = get_image(IMG_DICTIONARY_WORD_LIST_SCREEN);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_wildcard_word_list_hdlr
 * DESCRIPTION
 *  This function is the highlight handler for words in wildcard and chinese search list
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_wildcard_word_list_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_cntx.current_wildcard_search_index = index;
    return;
}


#ifdef __MMI_DICTIONARY_TTS__

U8 g_dictionary_result_phonic[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];
U8 g_dictionary_is_speaking = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_setting_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the setting menu in Dictionary option menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_dictionary_entry_setting_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_dictionary_entry_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_entry_setting_screen
 * DESCRIPTION
 *  entry tts setting screen
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guibuffer;
    U8 *inputbuffer;
    U16 inputBufferSize;
    U16 iconimagelist[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_DICTIONARY_TTS_SETTING, NULL, mmi_dictionary_entry_setting_screen, NULL);
    inputbuffer = GetCurrNInputBuffer(SCR_DICTIONARY_TTS_SETTING, &inputBufferSize);
    guibuffer = GetCurrGuiBuffer(SCR_DICTIONARY_TTS_SETTING);

    InitializeCategory57Screen();
    mmi_dictionary_set_inline_item();
    if(inputbuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, DICTIONARY_TTS_SETTING_TOTAL, inputbuffer);
    }
    RegisterHighlightHandler(mmi_dictionary_setting_item_highlight_hdlr);
    ShowCategory57Screen(
        STR_DICTIONARY_TTS_SETTING, 
        GetRootTitleIcon(EXTRA_DICTIONARY_MENU), 
        STR_GLOBAL_OK, 
        IMG_GLOBAL_OK, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK, 
        DICTIONARY_TTS_SETTING_INLINE_NUM,
        iconimagelist, 
        wgui_inline_items,
        0, 
        guibuffer);

    SetCategory57LeftSoftkeyFunction(mmi_dictionary_save_speak_setting);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_set_inline_item
 * DESCRIPTION
 *  Highlight handler for the set on menu in Dictionary setting menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_set_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.onoffbuffer, DS_BYTE, &error);
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.speedbuffer, DS_BYTE, &error);
    ReadValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME, &g_dictionary_inline_cntx.volumebuffer, DS_BYTE, &error);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) (U8*) GetString(STR_DICTIOANRY_TTS_SPEAKING));
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) (U8*) GetString(STR_DICTIOANRY_TTS_SPEAK_SPEED));
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) (U8*) GetString(STR_DICTIONARY_TTS_SPEAK_VOLUME));
    
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_dictionary_inline_cntx.dict_setting_onoff[0] = (U8 *)get_string(STR_GLOBAL_ON);
    g_dictionary_inline_cntx.dict_setting_onoff[1] = (U8 *)get_string(STR_GLOBAL_OFF);
    SetInlineItemSelect(
        &wgui_inline_items[1],
        DICTIONARY_TTS_STATE_TOTAL,
        (U8 **)g_dictionary_inline_cntx.dict_setting_onoff,
        &g_dictionary_inline_cntx.onoffbuffer);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    g_dictionary_inline_cntx.dict_setting_speak_speed[0] = (U8 *)get_string(STR_DICTIOANRY_TTS_SPEAK_SLOW);
    g_dictionary_inline_cntx.dict_setting_speak_speed[1] = (U8 *)get_string(STR_DICTIOANRY_TTS_SPEAK_NORMAL);
    g_dictionary_inline_cntx.dict_setting_speak_speed[2] = (U8 *)get_string(STR_DICTIOANRY_TTS_SPEAK_FAST);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        DICTIONARY_TTS_SPEAK_TOTAL,
        (U8 **)g_dictionary_inline_cntx.dict_setting_speak_speed,
        &g_dictionary_inline_cntx.speedbuffer);
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    while(i < DICTIONARY_TTS_SPEAK_VOLUME_TOTAL)
    {
        g_dictionary_inline_cntx.dict_setting_speak_volume[i] = &g_dictionary_inline_cntx.dict_speak_volume_array[i][0];
        i++;
    }
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[0], "1");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[1], "2");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[2], "3");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[3], "4");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[4], "5");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[5], "6");
    mmi_asc_to_ucs2((S8 *)g_dictionary_inline_cntx.dict_setting_speak_volume[6], "7");
    
    SetInlineItemSelect(
        &wgui_inline_items[5],
        7,
        (U8 **)g_dictionary_inline_cntx.dict_setting_speak_volume,
        &g_dictionary_inline_cntx.volumebuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_save_speak_setting
 * DESCRIPTION
 *  speak the word by tts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_save_speak_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dictionary_inline_cntx.HighligtItemonoff = g_dictionary_inline_cntx.onoffbuffer;
    g_dictionary_inline_cntx.HighligtItemspeakspeed = g_dictionary_inline_cntx.speedbuffer;
    g_dictionary_inline_cntx.HighligtItemspeakvolume = g_dictionary_inline_cntx.volumebuffer;
    WriteValue(NVRAM_DICTIANRY_TTS_ON_OFF, &g_dictionary_inline_cntx.HighligtItemonoff, DS_BYTE, &error);
    WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_SPEED, &g_dictionary_inline_cntx.HighligtItemspeakspeed, DS_BYTE, &error);
    WriteValue(NVRAM_DICTIANRY_TTS_SPEAK_VOLUME, &g_dictionary_inline_cntx.HighligtItemspeakvolume, DS_BYTE, &error);
    DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE), 
        IMG_GLOBAL_ACTIVATED,
        1, 
        UI_POPUP_NOTIFYDURATION_TIME, 
        SUCCESS_TONE);
    DeleteNScrId(SCR_DICTIONARY_TTS_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_setting_item_highlight_hdlr
 * DESCRIPTION
 *  speak the word by tts
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_setting_item_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_dictionary_save_speak_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_tts_word_speak
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_tts_word_speak(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out_phonic[(DICTIONARY_INPUT_LENGTH + 1) * ENCODING_LENGTH];
    S8 *input_word;
    U8  tts_volume;
    U8  tts_speed;
    mdi_audio_tts_struct tts_play;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_word = (S8 *)g_dictionary_last_word_p;
    memset(out_phonic, 0, ENCODING_LENGTH);
    if(!mmi_dict_get_word_phonic(input_word, g_dict_current_language, out_phonic))
    {
        return;
    }

    memset(g_dictionary_result_phonic, 0, ENCODING_LENGTH);
    mmi_dictionary_tts_phonic_switch((U16 *)out_phonic, (U16 *)g_dictionary_result_phonic);

    if(g_dictionary_is_speaking == 1)
    {
        mdi_audio_tts_stop();
    }
    
    tts_volume = mmi_dictionary_get_tts_volume();
    tts_speed = mmi_dictionary_get_tts_speed();
    tts_play.text_string = (U16 *)g_dictionary_result_phonic;
    tts_play.str_type = MDI_TTS_STR_PHN_SBL;
    tts_play.lang = MDI_TTS_LANG_ENG;
    tts_play.app_type = MDI_TTS_TYPE_DIC;
    tts_play.gander = MDI_TTS_GENDER_MALE;
    tts_play.volume = tts_volume;
    tts_play.path = MDI_DEVICE_SPEAKER2;
    tts_play.pitch = 50;
    tts_play.speed = tts_speed;
    tts_play.callback = mmi_dict_play_tts_finish_ind;

    result = mdi_audio_tts_play(tts_play);
    if(result == MDI_AUDIO_SUCCESS)
    {
        g_dictionary_is_speaking = 1;
    }
    else
    {
        g_dictionary_is_speaking = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_get_tts_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_get_tts_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tts_speed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_dictionary_inline_cntx.HighligtItemspeakspeed)
        {
        case DICTIONARY_TTS_SPEAK_SLOW:
        tts_speed = DICTIONARY_TTS_SLOW;
        break;
        
        case DICTIONARY_TTS_SPEAK_NORMAL:
        tts_speed = DICTIONARY_TTS_NORMAL;
        break;
        
        case DICTIONARY_TTS_SPEAK_FAST:
        tts_speed = DICTIONARY_TTS_FAST;
        break;
        
        default:
        tts_speed = DICTIONARY_TTS_NORMAL;
        break;
        }
    return tts_speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_get_tts_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_dictionary_get_tts_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tts_volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_dictionary_inline_cntx.HighligtItemspeakvolume)
    {
    case DICTIONARY_TTS_SPEAK_VOLUME_0:
    case DICTIONARY_TTS_SPEAK_VOLUME_1:
    case DICTIONARY_TTS_SPEAK_VOLUME_2:
    case DICTIONARY_TTS_SPEAK_VOLUME_3:
    case DICTIONARY_TTS_SPEAK_VOLUME_4:
    case DICTIONARY_TTS_SPEAK_VOLUME_5:
    case DICTIONARY_TTS_SPEAK_VOLUME_6:
        tts_volume = g_dictionary_inline_cntx.HighligtItemspeakvolume;
        break;
    
    default:
        tts_volume = DICTIONARY_TTS_SPEAK_VOLUME_4;
        break;
    }
        return tts_volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dict_play_tts_finish_ind
 * DESCRIPTION
 *  call back function for mdi_audio_tts_play
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dict_play_tts_finish_ind(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == MDI_AUDIO_SUCCESS)
    {
        g_dictionary_is_speaking = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_tts_phonic_switch
 * DESCRIPTION
 *  switch the phonic 
 * PARAMETERS
 *  in_phonic [in]
 *  result_phonic[out]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_tts_phonic_switch(U16 *in_phonic, U16 *result_phonic)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_mark, out_mark;
    S32 input_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_len = mmi_ucs2strlen((S8 *)in_phonic);
    if(input_len <= 0)
    {
        return;
    }
#ifdef __MMI_DICT_MOTECH__
    if (input_len >= 2)
    {
        if (in_phonic[input_len - 2] == 0x0283 && in_phonic[input_len - 1] == 0x006E)
        {
            in_phonic[input_len - 1] = 0x0259;
            in_phonic[input_len] = 0x006E;
            in_phonic[input_len + 1] = 0x0000;
            input_len += 1;
        }
    }
#endif
    in_mark = 0;
    out_mark = 0;
    while(in_mark < input_len)
    {
        switch(in_phonic[in_mark])
        {
        case 0x0065:
            {
                if((in_phonic[in_mark + 1] == 0x0049 ||in_phonic[in_mark + 1] == 0x0069) && in_phonic[in_mark + 2] != 0x003A)
                {
                    result_phonic[out_mark] = 0x0065;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x005A;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0069:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0069;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0049;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0075:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0075;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x004A;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x00E6:
            {
                result_phonic[out_mark] = 0x0041;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0251:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0042;
                    in_mark += 2;
                    out_mark++;
                }  
            }
            break;

        case 0x0259:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x005B;
                    in_mark += 2;
                    out_mark++;
                }
                else if(in_phonic[in_mark + 1] == 0x0075)
                {
                    result_phonic[out_mark] = 0x006F;
                    in_mark += 2;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0044;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x0283:
            {
                result_phonic[out_mark] = 0x0046;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x014B:
            {
                result_phonic[out_mark] = 0x004E;
                in_mark++;
                out_mark++;    
            }
            break;

        case 0x028C:
            {
                result_phonic[out_mark] = 0x0051;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0254:
            {
                if(in_phonic[in_mark + 1] == 0x003A)
                {
                    result_phonic[out_mark] = 0x0052;
                    in_mark += 2;
                    out_mark++;
                }
                else if(in_phonic[in_mark + 1] == 0x0069)
                {
                    result_phonic[out_mark] = 0x0052;
                    in_mark++;
                    out_mark++;
                }
                else
                {
                    result_phonic[out_mark] = 0x0053;
                    in_mark++;
                    out_mark++;
                }
            }
            break;

        case 0x00F0:
            {
                result_phonic[out_mark] = 0x0054;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0292:
            {
                result_phonic[out_mark] = 0x0056;
                in_mark++;
                out_mark++;
            }
            break;

        case 0xF403:
            {
                result_phonic[out_mark] = 0x0057;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x02CF:
        case 0x02CC:
            {
                result_phonic[out_mark] = 0x0037;
                in_mark++;
                out_mark++;
            } 
            break;

        case 0x0027:
        case 0x0060:
            {
                result_phonic[out_mark] = 0x0035;
                in_mark++;
                out_mark++;
            }
            break;
            
        case 0x0061:
            {
                result_phonic[out_mark] = 0x0061;
                if(in_phonic[in_mark + 1] == 0x0069 || in_phonic[in_mark + 1] == 0x0049)
                {
                    result_phonic[out_mark + 1] = 0x0049;
                }
                else if(in_phonic[in_mark + 1] == 0x0075)
                {
                    result_phonic[out_mark + 1] = 0x004A;
                }
                in_mark += 2;
                out_mark += 2;
            }
            break;

        case 0x025B:
            {
                result_phonic[out_mark] = 0x005A;
                in_mark++;
                out_mark++;
            }
            break;

        case 0x0028:/* ( ) - */
        case 0x0029:
        case 0x002D:
            {
                in_mark++;
            }
            break;
            
        case 0x0062:
        case 0x0063:
        case 0x0064:
        case 0x0066:
        case 0x0067:
        case 0x0068:
        case 0x006A:
        case 0x006B:
        case 0x006C:
        case 0x006D:
        case 0x006E:
        case 0x0070:
        case 0x0071:
        case 0x0072:
        case 0x0073:
        case 0x0074:
        case 0x0076:
        case 0x0077:
        case 0x0078:
        case 0x0079:
        case 0x007A:
            {
                result_phonic[out_mark] = in_phonic[in_mark];
                in_mark++;
                out_mark++;
            }
            break;

        default:
            in_mark = input_len;
            break;
        }
    }
    memset(&result_phonic[out_mark], 0, 2);
}
#endif /*__MMI_DICTIONARY_TTS__*/


/*****************************************************************************
 * FUNCTION
 *  isFromDictionary
 * DESCRIPTION
 *  This function returns to the UI whether control has come from dictionary or not
 *  vice versa
 * PARAMETERS
 *  max_number      [?]     
 * RETURNS
 *  pBOOL : TRUE :From dictionary
 *  FALSE : Not from the dictionary
 *****************************************************************************/
BOOL isFromDictionary(S32 *max_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrID;
    MMI_BOOL scrPresent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrID = GetActiveScreenId();
    scrPresent = IsScreenPresent(SCR_DICTIONARY_MAIN);
    if (scrID == SCR_DICTIONARY_MAIN || scrPresent)
    {
        *max_number = DICTIONARY_MAX_WORDS;
        return MMI_TRUE;

    }
    else
    {
        *max_number = 0;
        return MMI_FALSE;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_flush_editor_buffer
 * DESCRIPTION
 *  This function is  to flush buffer when user change input method, from english family to chinese
 *  vice versa
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL : TRUE :Family has been changed. Flush the buffer
 *  FALSE : Need to flush the output.
 *****************************************************************************/
BOOL mmi_dictionary_flush_editor_buffer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL isOldFamily, scrPresent;
    U16 activeScrID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activeScrID = GetActiveScreenId();
    scrPresent = IsScreenPresent(SCR_DICTIONARY_MAIN);

    if (activeScrID == SCR_INPUT_METHOD_LIST)
    {
        if (!scrPresent)
        {
            return MMI_FALSE;
        }

    }
    else if (!(activeScrID == SCR_DICTIONARY_WILDCARD_EXACT_EDITOR || activeScrID == SCR_DICTIONARY_MAIN))
    {
        return MMI_FALSE;
    }

    switch (g_mmi_dictionary_prev_input_mode)
    {
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
            switch (MMI_current_input_mode)
            {
                case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
                case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
                case INPUT_MODE_SMART_UPPERCASE_ABC:
                case INPUT_MODE_SMART_LOWERCASE_ABC:
                    isOldFamily = MMI_TRUE;
                    break;
                default:
                    isOldFamily = MMI_FALSE;

            }
            break;
        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_BOPOMO:
            switch (MMI_current_input_mode)
            {
                case INPUT_MODE_TR_MULTITAP_BOPOMO:
                case INPUT_MODE_TR_STROKE:
                case INPUT_MODE_SM_MULTITAP_PINYIN:
                case INPUT_MODE_SM_STROKE:
                case INPUT_MODE_SM_PINYIN:
                case INPUT_MODE_TR_BOPOMO:
                    isOldFamily = MMI_TRUE;
                    break;
                default:
                    isOldFamily = MMI_FALSE;

            }
            break;
        default:
            isOldFamily = MMI_FALSE;
    }

    g_mmi_dictionary_prev_input_mode = MMI_current_input_mode;

    if (isOldFamily)
    {
        return MMI_FALSE;
    }
    else
    {
        g_dict_current_language = mmi_dictionary_check_input_family_bymode((U8) MMI_current_input_mode);
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_check_input_family
 * DESCRIPTION
 *  This function is  return the input family type
 * PARAMETERS
 *  inputType       [IN]        
 *  input type(?)
 * RETURNS
 *  MMI_DICTIONARY_LANGUAGE : english/chinese/none
 *****************************************************************************/
MMI_DICTIONARY_LANGUAGE mmi_dictionary_check_input_family(U8 inputType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE family;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inputType)
    {
        case INPUT_TYPE_ALPHANUMERIC_UPPERCASE:
        case INPUT_TYPE_ALPHANUMERIC_LOWERCASE:
        case INPUT_TYPE_SMART_UPPERCASE_ABC:
        case INPUT_TYPE_SMART_LOWERCASE_ABC:
            family = DICTIONARY_ENGLISH;
            break;

        case INPUT_TYPE_SM_MULTITAP_PINYIN:
        case INPUT_TYPE_SM_PINYIN:
        case INPUT_TYPE_SM_STROKE:
#ifndef __MMI_DICT_MOTECH__
        case INPUT_TYPE_TR_MULTITAP_BOPOMO:
        case INPUT_TYPE_TR_BOPOMO:
        case INPUT_TYPE_TR_STROKE:
#endif
            family = DICTIONARY_CHINESE;
            break;

        default:
            family = DICTIONARY_NONE;
    }

    return family;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_check_input_family_bymode
 * DESCRIPTION
 *  This function is  return the input family type
 * PARAMETERS
 *  inputmode           [IN]            
 * RETURNS
 *  MMI_DICTIONARY_LANGUAGE : english/chinese/none
 *****************************************************************************/
MMI_DICTIONARY_LANGUAGE mmi_dictionary_check_input_family_bymode(U8 inputmode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_DICTIONARY_LANGUAGE family;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(inputmode)
    {
        case INPUT_MODE_MULTITAP_LOWERCASE_ABC:
        case INPUT_MODE_MULTITAP_UPPERCASE_ABC:
        case INPUT_MODE_SMART_UPPERCASE_ABC:
        case INPUT_MODE_SMART_LOWERCASE_ABC:
        case INPUT_MODE_SMART_FIRST_UPPERCASE_ABC:
            family = DICTIONARY_ENGLISH;
            break;

        case INPUT_MODE_TR_MULTITAP_BOPOMO:
        case INPUT_MODE_TR_STROKE:
        case INPUT_MODE_SM_MULTITAP_PINYIN:
        case INPUT_MODE_SM_STROKE:
        case INPUT_MODE_SM_PINYIN:
        case INPUT_MODE_TR_BOPOMO:
            family = DICTIONARY_CHINESE;
            break;

        default:
            family = DICTIONARY_NONE;
        }
    return family;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_flush_exact_wild_editor_buffer
 * DESCRIPTION
 *  This function is  called when  input method is changed from exact/wildcard editor -> option->input method
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL TRUE : language has been changed
 *  FALSE : language is not changed
 *****************************************************************************/
BOOL mmi_dictionary_flush_exact_wild_editor_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL scrPresent;
    U16 activeScrID;
    MMI_DICTIONARY_LANGUAGE currentLanguage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activeScrID = GetActiveScreenId();
    scrPresent = IsScreenPresent(SCR_DICTIONARY_WILDCARD_EXACT_EDITOR);

    if (activeScrID == SCR_INPUT_METHOD_LIST)
    {
        if (!scrPresent)
        {
            return MMI_FALSE;
        }

    }
    else if (!(activeScrID == SCR_DICTIONARY_WILDCARD_EXACT_EDITOR))
    {
        return MMI_FALSE;
    }

    if (wgui_multiline_inputbox_input_type != 0)
    {
        currentLanguage = mmi_dictionary_check_input_family((U8) wgui_multiline_inputbox_input_type);
        if (currentLanguage != g_dict_current_language)
        {
            g_dict_current_language = currentLanguage;
            return MMI_TRUE;
        }
    }
    else
    {
        /* Reset language if input type not assigned */
        g_dict_current_language = mmi_dictionary_check_input_family_bymode((U8) MMI_current_input_mode);
        return MMI_FALSE;
    }

    return MMI_FALSE;

}
#elif defined(__MMI_DICTIONARY__)

#include "CommonScreens.h"

/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_main_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dictionary_init
 * DESCRIPTION
 *  Initialize Dictionary database. Set highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dictionary_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EXTRA_DICTIONARY_MENU, mmi_dictionary_main_menu_highlight_hdlr);
}
#endif /* defined(__MMI_DICTIONARY__) */

