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
 * Filename:
 * ---------
 * Game.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Game Menu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_GAME__
#include "gui.h"
#include "CustResDef.h"
#include "MiscFunctions.h"
#include "GameResDef.h"
#include "GameProts.h"
#include "FunAndGamesDefs.h"
#include "MainMenuDef.h"
#include "GameFramework.h"
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "Commonscreens.h"

#ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_F1RACE_BASE_GAME */ 

#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_HANOI_BASE_GAME */ 

#ifdef IS_RICHES_BASE_GAME
#include "RichesProts.h"
#include "RichesResDef.h"
#endif /* IS_RICHES_BASE_GAME */ 

#ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_COLORBALL_BASE_GAME */ 

#ifdef IS_SNAKE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_SNAKE_BASE_GAME */ 

#ifdef IS_SMASH_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_SMASH_BASE_GAME */ 

#ifdef IS_DOLL_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_DOLL_BASE_GAME */  

#ifdef IS_MAJUNG_BASE_GAME
#include "MajungProts.h"
#include "MajungResDef.h"
#endif /* IS_MAJUNG_BASE_GAME */ 

#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_COPTER_BASE_GAME */ 

#ifdef IS_PUZZLE_BASE_GAME
#include "PuzzleResDef.h"
#include "PuzzleProts.h"
#endif /* IS_PUZZLE_BASE_GAME */ 

#ifdef IS_PANDA_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_PANDA_BASE_GAME */ 

#ifdef IS_STAIR_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_STAIR_BASE_GAME */ 

#ifdef IS_UFO_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_UFO_BASE_GAME */ 

#ifdef IS_DANCE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_DANCE_BASE_GAME */ 

#ifdef IS_MAGICSUSHI_BASE_GAME
#include "MagicsushiResDef.h"
#include "MagicsushiProts.h"
#endif /* IS_MAGICSUSHI_BASE_GAME */ 

#ifdef IS_FRUIT_BASE_GAME
#include "FruitResDef.h"
#include "FruitProts.h"
#endif /* IS_FRUIT_BASE_GAME */ 

#ifdef IS_VSMJ_BASE_GAME
#include "VsmjResDef.h"
#include "VsmjProts.h"
#endif /* IS_VSMJ_BASE_GAME */ 

#include "DateTimeType.h"
#include "App_DateTime.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif

/****************************************************************************
* Macro                                                                
*****************************************************************************/
#define GAME_SWITCH(index, func_ptr)                             \
{                                                                \
   case index:                                                   \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         SetKeyHandler(func_ptr, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);\
      }                                                          \
      break;                                                     \
}

typedef enum
{
#if defined(__MMI_GAME__)
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    MMI_GAME_SETTING_BACKGROUND,
    MMI_GAME_SETTING_SOUND_EFFECTS,
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULTICHANNEL_SOUND__ */
    MMI_GAME_SETTING_AUD,
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    MMI_GAME_SETTING_VIB,
#endif /* defined(__MMI_GAME__) */ 
    MMI_GAME_SETTING_ITEM_COUNT
} mmi_game_setting_inline_enum;

typedef struct
{

    /* strings for inline selection display */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    UI_string_type background_music_str[2];
    UI_string_type sound_effect_str[2];
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    UI_string_type aud_str[2];
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    UI_string_type vib_str[2];

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    S32 bgm_selected;
    S32 sound_effect_selected;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    S32 aud_selected;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    S32 vib_selected;

    /* inline selection item */
    InlineItem inline_game_items[MMI_GAME_SETTING_ITEM_COUNT *2];      /* one for caption, one for selection */

} mmi_game_cntx_struct;

mmi_game_cntx_struct g_mmi_game_cntx;

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   
/*used for multi-language language_mapping_table_struct     , currently we max support ten languages*/
mmi_game_language_mapping_table_struct g_mmi_game_language_mapping_table[] =
{
        {MMI_GAME_LANGUAGE0,  "English", "*#0044#"},
        {MMI_GAME_LANGUAGE1,  "Chinese", "*#0086#"},
        {MMI_GAME_LANGUAGE2,  "Arabic" , "*#0966#"},
        {MMI_GAME_LANGUAGE3,  "", ""},
        {MMI_GAME_LANGUAGE4,  "", ""},
        {MMI_GAME_LANGUAGE5,  "", ""},
        {MMI_GAME_LANGUAGE6,  "", ""},
        {MMI_GAME_LANGUAGE7,  "", ""},
        {MMI_GAME_LANGUAGE8,  "", ""},
        {MMI_GAME_LANGUAGE9,  "", ""}
};
extern U16 gCurrLangIndex;
extern const sLanguageDetails mtk_gLanguageArray[];
U16 g_mmi_game_current_language_index;
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

/****************************************************************************
* Local Functions                                                        
*****************************************************************************/
static void mmi_game_highlight_hdlr(S32 index);
static void mmi_game_entry_app_screen(void);
static void mmi_game_exit_setting_screen(void);
static void mmi_game_setting_highlight_hdlr(S32 index);
static void mmi_game_setting_done_hdlr(void);
static void mmi_game_entry_setting_screen(void);

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   /*used for multi-language*/
    static U16 mmi_gfx_get_current_language_index(void);
    static U8 mmi_gfx_get_fisrt_valid_language_index(void);  
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_game_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for games
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_HANOI_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_RICHES_BASE_GAME
            GAME_SWITCH(game_riches, Riches_Enter_GFX);
    #endif 

    #ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_SNAKE_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_SMASH_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_DOLL_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_MAJUNG_BASE_GAME
            GAME_SWITCH(game_majung, Majung_Enter_GFX);
    #endif 

    #ifdef IS_COPTER_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_PUZZLE_BASE_GAME
            GAME_SWITCH(game_puzzle, mmi_gx_puzzle_enter_gfx);
    #endif 

    #ifdef IS_PANDA_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_STAIR_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_UFO_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_DANCE_BASE_GAME
/* under construction !*/
    #endif 

    #ifdef IS_MAGICSUSHI_BASE_GAME
            GAME_SWITCH(game_magicsushi, mmi_gx_magicsushi_enter_gfx);
    #endif 

    #ifdef IS_FRUIT_BASE_GAME
            GAME_SWITCH(game_fruit, mmi_gx_fruit_enter_gfx);
    #endif 

    #ifdef IS_VSMJ_BASE_GAME
            GAME_SWITCH(game_vsmj, mmi_gx_vsmj_enter_gfx);
    #endif 

        default:
            SetLeftSoftkeyFunction(mmi_game_entry_setting_screen, KEY_EVENT_UP);
            SetKeyHandler(mmi_game_entry_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_game_highlight_app
 * DESCRIPTION
 *  highlight game app menitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_GAME__)
void mmi_game_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_game_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_game_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_GAME__) */ 





/*****************************************************************************
 * FUNCTION
 *  mmi_game_entry_app_screen
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    UI_time t;
    U16 menu_str[game_list_count + 1];
    U16 menu_img[game_list_count + 1];
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* str and img +1 for setting */
#ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_F1RACE_BASE_GAME */ 

#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_HANOI_BASE_GAME */ 

#ifdef IS_RICHES_BASE_GAME
    menu_str[index] = STR_GX_RICHES_GAME_NAME;
    menu_img[index++] = IMG_GX_RICHES_GAME_ICON;
#endif /* IS_RICHES_BASE_GAME */ 

#ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_COLORBALL_BASE_GAME */ 

#ifdef IS_SNAKE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_SNAKE_BASE_GAME */ 

#ifdef IS_SMASH_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_SMASH_BASE_GAME */ 

#ifdef IS_DOLL_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_DOLL_BASE_GAME */ 

#ifdef IS_MAJUNG_BASE_GAME
    menu_str[index] = STR_GX_MAJUNG_GAME_NAME;
    menu_img[index++] = IMG_GX_MAJUNG_GAME_ICON;
#endif /* IS_MAJUNG_BASE_GAME */ 

#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
#if defined(__MMI_GAME_COPTER_128x128__) || defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_SUBMARINE_128x128__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_JET_128x128__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_COPTER_BASE_GAME */ 

#ifdef IS_PUZZLE_BASE_GAME
    menu_str[index] = STR_ID_GX_PUZZLE_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_PUZZLE_GAME_ICON;
#endif /* IS_PUZZLE_BASE_GAME */ 

#ifdef IS_PANDA_BASE_GAME
/* under construction !*/
#if defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_176x220__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_176x220__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_PANDA_BASE_GAME */ 

#ifdef IS_STAIR_BASE_GAME
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_CHICKEN_128x160__) || defined(__MMI_GAME_CHICKEN_128x128__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#endif /* IS_STAIR_BASE_GAME */ 

#ifdef IS_UFO_BASE_GAME
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_UFO_128x160__) || defined(__MMI_GAME_UFO_128x128__) || defined(__MMI_GAME_UFO_176x220__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_AIRFORCE_128x160__) || defined(__MMI_GAME_AIRFORCE_128x128__)
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#endif /* IS_UFO_BASE_GAME */ 

#ifdef IS_DANCE_BASE_GAME
/* under construction !*/
/* under construction !*/
#endif /* IS_DANCE_BASE_GAME */ 

#ifdef IS_MAGICSUSHI_BASE_GAME
    menu_str[index] = STR_ID_GX_MAGICSUSHI_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_MAGICSUSHI_GAME_ICON;
#endif /* IS_MAGICSUSHI_BASE_GAME */ 

#ifdef IS_FRUIT_BASE_GAME
    menu_str[index] = STR_ID_GX_FRUIT_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_FRUIT_GAME_ICON;
#endif /* IS_FRUIT_BASE_GAME */ 

#ifdef IS_VSMJ_BASE_GAME
    menu_str[index] = STR_ID_GX_VSMJ_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_VSMJ_GAME_ICON;
#endif /* IS_VSMJ_BASE_GAME */ 

    menu_str[index] = STR_ID_GAME_SETTING;
    menu_img[index++] = IMG_ID_GAME_SETTING;

    /* Set random seed */
    GetDateTime(&t);
    srand(t.nMin);

    //get current language , used for multi-language
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    g_mmi_game_current_language_index = mmi_gfx_get_current_language_index(); 
#endif
    
    EntryNewScreen(SCR_ID_GAME, NULL, mmi_game_entry_app_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_GAME);

    RegisterHighlightHandler(mmi_game_highlight_hdlr);

    ShowCategory15Screen(
        STR_GAME_CAPTION,
        GetRootTitleIcon(MENU3105_GAMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        menu_str,
        menu_img,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW,KEY_EVENT_DOWN);

    /* load game settings */
    mmi_gfx_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_entry_setting_screen
 * DESCRIPTION
 *  entry point for game setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_entry_setting_screen(void)
{
#if defined(__MMI_GAME__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;

    MMI_ID_TYPE item_icons[] = 
    {
    #if defined(__MMI_GAME__)
    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        IMG_ID_GAME_SETTING_BACK_AUD,
        0,
        IMG_ID_GAME_SETTING_AUD,
        0,
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        IMG_ID_GAME_SETTING_AUD,
        0,
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        IMG_ID_GAME_SETTING_VIB,
        0,
    #endif /* defined(__MMI_GAME__) */ 
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load setting */
#if defined(__MMI_GAME__)
    mmi_gfx_load_setting();
#endif 

    EntryNewScreen(SCR_ID_GAME_SETTING, mmi_game_exit_setting_screen, NULL, NULL);

   /***************************************************************************** 
   * Game  
   *****************************************************************************/
#if defined(__MMI_GAME__)
    /* TRUE (1) is on */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    g_mmi_game_cntx.bgm_selected = GFX.is_background_music_on;
    g_mmi_game_cntx.sound_effect_selected = GFX.is_sound_effect_on;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    g_mmi_game_cntx.aud_selected = GFX.is_aud_on;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    g_mmi_game_cntx.vib_selected = GFX.is_vib_on;

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    g_mmi_game_cntx.background_music_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_mmi_game_cntx.background_music_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
    g_mmi_game_cntx.sound_effect_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_mmi_game_cntx.sound_effect_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    g_mmi_game_cntx.aud_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_mmi_game_cntx.aud_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    g_mmi_game_cntx.vib_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_mmi_game_cntx.vib_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));

    memset((void*)g_mmi_game_cntx.inline_game_items, 0, sizeof(InlineItem) * MMI_GAME_SETTING_ITEM_COUNT * 2);

    InitializeCategory57Screen();

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    /* background music */
    SetInlineItemCaption(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC)));

    SetInlineItemActivation(&g_mmi_game_cntx.inline_game_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        2,
        (U8 **) g_mmi_game_cntx.background_music_str,
        &g_mmi_game_cntx.bgm_selected);

    /* sound effect */
    SetInlineItemCaption(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT)));

    SetInlineItemActivation(&g_mmi_game_cntx.inline_game_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        2,
        (U8 **) g_mmi_game_cntx.sound_effect_str,
        &g_mmi_game_cntx.sound_effect_selected);

#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    /* game audio */
    SetInlineItemCaption(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_GAME_SETTING_AUD)));

    SetInlineItemActivation(&g_mmi_game_cntx.inline_game_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        2,
        (U8 **) g_mmi_game_cntx.aud_str,
        &g_mmi_game_cntx.aud_selected);

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    /* game vib */
    SetInlineItemCaption(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_GAME_SETTING_VIB)));

    SetInlineItemActivation(&g_mmi_game_cntx.inline_game_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &g_mmi_game_cntx.inline_game_items[item_offset++],
        2,
        (U8 **) g_mmi_game_cntx.vib_str,
        &g_mmi_game_cntx.vib_selected);

#endif /* defined(__MMI_GAME__) */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_GAME_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_GAME_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(g_mmi_game_cntx.inline_game_items, MMI_GAME_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_game_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_ID_GAME_SETTING,
        GetRootTitleIcon(MENU3105_GAMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        g_mmi_game_cntx.inline_game_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_game_setting_done_hdlr);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
#endif /* defined(__MMI_GAME__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_setting_done_hdlr
 * DESCRIPTION
 *  done hdlr for game setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_setting_done_hdlr(void)
{
#if defined(__MMI_GAME__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* game effect */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX.is_background_music_on = g_mmi_game_cntx.bgm_selected;
    GFX.is_sound_effect_on = g_mmi_game_cntx.sound_effect_selected;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    GFX.is_aud_on = g_mmi_game_cntx.aud_selected;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    GFX.is_vib_on = g_mmi_game_cntx.vib_selected;
    mmi_gfx_store_setting();

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
#endif /* defined(__MMI_GAME__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_setting_highlight_hdlr(S32 index)
{
#if defined(__MMI_GAME__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_game_setting_done_hdlr);
#endif /* defined(__MMI_GAME__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_exit_setting_screen
 * DESCRIPTION
 *  exit point for game setting screen
 * PARAMETERS
 *  void
 *  viud(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_exit_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_GAME_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_game_entry_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ColorBall_Get_Current_Language_Index
 * DESCRIPTION
 *  get current language index
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
U16 mmi_gfx_get_current_language_index()
{
    U8 i;
    
    for (i = MMI_GAME_LANGUAGE0 ; i < MMI_GAME_LANGUAGE_TATAL ; i++)
    {
        if(strcmp((PS8)mtk_gLanguageArray[gCurrLangIndex].aLangSSC, (PS8)g_mmi_game_language_mapping_table[i].aLangSSC) == 0)
            return i;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Get_Current_Language_Image_ID
 * DESCRIPTION
 *  get image id of current language
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_gfx_get_multilanguage_image_ID(
        MMI_GAME_MULTI_LANGUAGE_ENUM language, 
        U16 image_ID_base, 
        U16 total_string_count, 
        U16 string_number)
{

    return (image_ID_base + language*total_string_count + string_number);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Check_Image_Validity
 * DESCRIPTION
 *  check image in current language is valid or not, and get valid language
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gfx_check_image_get_valid_language(
            U16 *game_language_index, 
            U16 image_ID_base, 
            U16 total_string_count)
{
    U8 *pData = NULL;
    BOOL image_validate = TRUE;
    U8  first_valid_language_index;
    U16 image_handle;
    U8 i;

    for (i = 0 ; i < total_string_count ; i++)
    {
        image_handle = (*game_language_index) * total_string_count + image_ID_base + i;
        pData = (PU8)GetImage(image_handle);    
        if (pData == MMI_GAME_DEFAULT_IMAGE_BMP|| pData == MMI_GAME_EMPTYIMAGE_BMP)
        {
            image_validate = FALSE;
            break;
        }      
    }
    
    if(image_validate == FALSE)
    {
        first_valid_language_index = mmi_gfx_get_fisrt_valid_language_index();
        *game_language_index= first_valid_language_index;
    }
        
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Get_Fisrt_Valid_Language_Index
 * DESCRIPTION
 *  get first valid language index
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_gfx_get_fisrt_valid_language_index()
{
    U32 i;
        
    for(i = MMI_GAME_LANGUAGE0 ; i < MMI_GAME_LANGUAGE_TATAL ; i++)
    {
        if(strlen((PS8)g_mmi_game_language_mapping_table[i].aLangSSC) != 0)
        {
            return i;
        }
    }

    return MMI_GAME_LANGUAGE0;
}
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#endif /* __MMI_GAME__ */ 

