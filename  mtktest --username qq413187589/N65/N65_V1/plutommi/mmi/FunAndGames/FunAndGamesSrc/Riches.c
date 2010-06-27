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
 *  Riches.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Riches Game
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "GameDefs.h"

#ifdef IS_RICHES_BASE_GAME
#include "GameInc.h"
#include "RichesResDef.h"
#include "RichesProts.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#define RICHES_IMAGEBITBUFFER 400

#define MAX_RICHES_LEVEL      3
#define DONE_TIMEROUT         1000
#define OBJECT_DROP_TIME      200
#define MAX_DROP_OBJECT       6

#define GAME_WINDOW_X1        0
#define GAME_WINDOW_Y1        0
#define GAME_WINDOW_X2        90
#define GAME_WINDOW_Y2        128       /* 160 */

#define OBJ_DIS_LIMIT         12

#define INFO_WINDOW_X1        90
#define INFO_WINDOW_Y1        0
#define INFO_WINDOW_X2        128
#define INFO_WINDOW_Y2        128

#define MAX_DROPPING_OBJECTS  10
#define MAX_HIGHEST_GRADE     5
#define BUCKETX               33
#define BUCKETY               GAME_WINDOW_Y2 - 16

#define ENERGY_BARBG_X        101
#define ENERGY_BARBG_Y        92

#define ENERGY_BAR_X          103
#define ENERGY_BAR_Y          121

#define BONUS_TIMER_COUNT     1000
#define BUCKET_WIDTH          40

#define BOUNSTIMEINSEC        15
#define POPUP_RICHES_DURATION 1000
#define BUCKET_MOVE_PX        11
#define MAX_SCORE_LEN         40

#define MAX_DROP_DISTANCE        15
#define RICHES_GIFT_WEIGHT       10
#define RICHES_GOLDNOTE_WEIGHT   8
#define RICHES_BOMB_WEIGHT       20
#define RICHES_APPLE_WEIGHT      5
#define RICHES_SPIDER_WEIGHT     14
#define RICHES_BATTER20_WEIGHT   1
#define RICHES_BATTERY_WEIGHT    1
#define RICHES_ANGLE_WEIGHT      2
#define RICHES_THEIF_WEIGHT      6
#define RICHES_DENONATOR_WEIGHT  12
#define RICHES_MONEY_WEIGHT      15
#define RICHES_BAT_WEIGHT        20
#define RICHES_DEAMON_WEIGHT     5

/************************************************************************/
/* Structure                                             */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_RICHES_STRING_BACKGROUND,
    MMI_RICHES_STRING_BACKGROUND_TIMER,
    MMI_RICHES_STRING_BACKGROUND_LEVEL,
    MMI_RICHES_STRING_GAMEOVER,
    MMI_RICHES_STRING_TOTAL
}mmi_riches_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef struct
{
    S32 objWidth;
    S32 objHeight;
    U8 objWeight;
    PU8 objImage;
    S32 scoreRate;
    U8 dropLevel;
} RICHES_OBJECT_IMAGE_STRUCT;

typedef struct
{
    U8 ObjectType;  /* One of the RICHES_OBJECT_IMAGE_STRUCT Type */
    U16 X;
    U16 Y;
    bitmap richesBitmap;
} RICHES_FLOATING_OBJECT_STRUCT;

typedef struct
{
    U8 isValidMemory[MAX_DROPPING_OBJECTS];
    void *bitBuffer[MAX_DROPPING_OBJECTS];
} RICHES_BUFFER_POOL_STRUCT;

typedef enum
{
    RICHES_GIFT = 0,
    RICHES_GOLDNOTE,
    RICHES_BOMB,
    RICHES_APPLE,
    RICHES_SPIDER,
    RICHES_BATTER20,
    RICHES_BATTERY,
    RICHES_ANGLE,
    RICHES_THEIF,
    RICHES_DENONATOR,
    RICHES_MONEY,
    RICHES_BAT,
    RICHES_DEAMON,
    RICHES_TOTAL_OBJECTS    /* Dont Remove This Keeping The Count */
} RICHES_OBJECT;

/************************************************************************/
/* Golbal Varable [Const]                                   */
/************************************************************************/
const static U8 riches_column[5] = {4, 21, 38, 55, 72};

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define RICHESEATGOOD         138
#define RICHESEATBAD          133

__align(2)
     const U8 RichesEatGood[138] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x74, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x05, 0x24, 0xB7, 0x00, 0xC0, 0x0A, 0x00, 0xB0, 0x07,
         0x60, 0x00, 0x90, 0x48, 0x64, 0x00, 0xC1, 0x61, 0x00, 0xB1, 0x07, 0x7C, 0x00, 0x91, 0x48, 0x64,
         0x81, 0x70, 0x90, 0x48, 0x00, 0x00, 0x4A, 0x64, 0x81, 0x70, 0x4A, 0x00, 0x00, 0x4C, 0x64, 0x81,
         0x70, 0x4C, 0x00, 0x00, 0x4F, 0x64, 0x81, 0x70, 0x4F, 0x00, 0x00, 0x54, 0x64, 0x81, 0x70, 0x54,
         0x00, 0x00, 0x91, 0x48, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

__align(2)
     const U8 RichesEatBad[133] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x6F, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xB9, 0x07, 0x7D, 0x00, 0x99,
         0x4F, 0x7D, 0x00, 0xC0, 0x10, 0x00, 0xB0, 0x07, 0x62, 0x00, 0x90, 0x42, 0x7A, 0x00, 0x41, 0x7A,
         0x05, 0x40, 0x7A, 0x00, 0x43, 0x7A, 0x73, 0x99, 0x4E, 0x7D, 0x83, 0x5C, 0x90, 0x41, 0x00, 0x00,
         0x42, 0x00, 0x05, 0x40, 0x00, 0x00, 0x99, 0x4F, 0x00, 0x00, 0x4E, 0x00, 0x00, 0x90, 0x43, 0x00,
         0x00, 0xFF, 0x2F, 0x00
     };

/************************************************************************/
/* Golbal Varable [295 Byte]                                */
/************************************************************************/
static U8 riches_game_level;
static color riches_bg_color;
static bitmap riches_basket_bitmap;
static U8 riches_bucket_x = BUCKETX;
static U8 riches_bucket_y;
static S32 riches_bucket_width;
static S32 riches_bucket_height;
static U8 riches_game_status = 0;
static U16 riches_drop_timer;
static U8 riches_decrease_energy;           /* Decrese Energy after 100 Moves by 20 Units. */
static U8 riches_current_drop_object;
static U8 riches_runtime_object_num;
static S16 riches_game_grade;
static S32 riches_fla_decrease_energy = 10; /* ??? what is this ?? */
static S32 riches_level_img_height;
static S32 riches_level_img_width;
static U8 riches_life = 3;
static U8 riches_bonus_flag = 0;            /* Bonus Flag 1    - for Angle,    Flag 2 - for Denonator */
static U8 riches_bouns_timer;
static U8 riches_game_end = 0;
static U8 riches_mem_allocated = 0;
static U8 riches_flag_continue = 0;
static U8 riches_bucket_move = 0;
static U8 riches_energy_counter = 0;
static U8 riches_flag_angle_denonator = 0;
static BOOL riches_is_new_game = TRUE;
static U8 riches_basket_position = 3;
static U8 riches_object_weight[RICHES_GIFT_WEIGHT + RICHES_GOLDNOTE_WEIGHT + RICHES_BOMB_WEIGHT
                               + RICHES_APPLE_WEIGHT + RICHES_SPIDER_WEIGHT + RICHES_BATTER20_WEIGHT
                               + RICHES_BATTERY_WEIGHT + RICHES_ANGLE_WEIGHT + RICHES_THEIF_WEIGHT
                               + RICHES_DENONATOR_WEIGHT + RICHES_MONEY_WEIGHT + RICHES_BAT_WEIGHT +
                               RICHES_DEAMON_WEIGHT];

static PU8 riches_bucket;

static RICHES_BUFFER_POOL_STRUCT riches_bit_buffer_pool;    /* 20 bytes */
static RICHES_OBJECT_IMAGE_STRUCT *riches_dropping_object[RICHES_TOTAL_OBJECTS];        /* 13 Byte */
static RICHES_FLOATING_OBJECT_STRUCT riches_object_on_screen[MAX_DROPPING_OBJECTS];     /* 20*10 Byte = 200 */

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
S32 eatgood_midi;
S32 eatbad_midi;
 #endif /* defined (__MMI_GAME_MULTICHANNEL_SOUND__) */ 

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_riches_language_index;
#define MMI_RICHES_STRING_COUNT MMI_RICHES_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void Riches_Draw_GameOver(void);
void Riches_Enter_Game(void);
void Riches_Exit_Game(void);
S16 Riches_Calc_Best_Grade(S16 old_grade, S16 new_grade);

/* Game play functions */
void Riches_Enter_New_Game(void);
void Riches_Enter_Resume_Game(void);
void Riches_Init_App(void);
void Riches_Init_Bit_Buffer_Pool(void);
void Riches_Init_Falling_Object(void);
pBOOL Riches_Allocate_Bit_Buffer(U8 ID);
void Riches_Draw_Background(void);
void Riches_Move_Left(void);
void Riches_Move_Right(void);
void Riches_Show_Timer_Text(void);
void Riches_Create_Object(void);
void Riches_Drop_Object_Timer_Callback(void);
void Riches_Check_Object_Status(void);
void Riches_Redraw_Screen(void);
void Riches_Draw_Energy_Level(void);
void Riches_Decrease_Energy(void);
void Riches_Free_Bit_Buffer(U8 ID);
void Riches_Kill_Running_Object(U8 ID);
U8 Riches_Check_Object_Crash(U8 i);
void Riches_Full_Crash(U8 i);
void Riches_Action_Angle(void);
void Riches_Action_Denonator(void);
void Riches_Reset_Running_Object(void);
void Riches_Bonus_Time_Out(void);
void Riches_Decrease_Life(void);
void Riches_End_Game(void);
void Riches_Reset_Level_From_Timer(void);

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);


/*****************************************************************************
 * FUNCTION
 *  Riches_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_RICHES_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_RICHES_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;       /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GAME_HELP;         /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_RICHES_EASY;    /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_RICHES_NORMAL;  /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_RICHES_HARD;    /* level string ID */

    GFX.game_data.grade_nvram_id_list[0] = NVRAM_RICHES_EASY_SCORE;     /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_RICHES_NORMAL_SCORE;   /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_RICHES_HARD_SCORE;     /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_GAME_RICHES_STATUS;    /* current lvl idnex stored in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_RICHES_HELP_DESCRIPTION; /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&riches_game_grade);       /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&riches_game_level);        /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) & riches_is_new_game;  /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = Riches_Calc_Best_Grade; /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = Riches_Enter_Game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = Riches_Exit_Game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = Riches_Draw_GameOver;        /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 Riches_Calc_Best_Grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_grade > old_grade)
    {
        return new_grade;
    }
    else
    {
        return old_grade;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Draw_GameOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();

    /* call this function to draw standard gameover screen */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_gfx_draw_gameover_screen(IMG_GX_RICHES_GOTEXT, IMG_GX_RICHES_GRADESMAP, IMG_GX_RICHES_GOPIC, riches_game_grade);
#else
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_riches_language_index, 
         IMG_GX_RICHES_BACKGROUND_LANGUAGE0, 
         MMI_RICHES_STRING_COUNT, 
         MMI_RICHES_STRING_GAMEOVER),
        IMG_GX_RICHES_GRADESMAP,
        IMG_GX_RICHES_GOPIC,
        riches_game_grade);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Enter_Game()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_riches_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_riches_language_index, 
        IMG_GX_RICHES_BACKGROUND_LANGUAGE0, 
        MMI_RICHES_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_SOUND_EFFECTS_MIDI(RichesEatGood, RICHESEATGOOD, 1, eatgood_midi);
    GFX_OPEN_SOUND_EFFECTS_MIDI(RichesEatBad, RICHESEATBAD, 1, eatbad_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    if (riches_is_new_game == TRUE)
    {
        riches_is_new_game = FALSE;
        Riches_Enter_New_Game();
    }
    else
    {
        Riches_Enter_Resume_Game();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Exit_Game(void)
{
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
    GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

    GFX_CLOSE_SOUND_EFFECTS_MIDI(eatgood_midi);
    GFX_CLOSE_SOUND_EFFECTS_MIDI(eatbad_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    gui_cancel_timer(Riches_Bonus_Time_Out);
    gui_cancel_timer(Riches_Drop_Object_Timer_Callback);
}

/************************************************************************/
/************************************************************************/
/* BELOW THIS LINE IS GAME KERNAL IMPLMENTED BY PIXTEL.              */
/************************************************************************/
/************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  Riches_Enter_Resume_Game
 * DESCRIPTION
 *  Entry Function On Game Resume. Set The Game Running Flag TRUE and Enter
 *  Riches Init Application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Enter_Resume_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_game_end = 0;
    clear_screen();
    riches_flag_continue = 1;
    Riches_Init_App();
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Enter_New_Game
 * DESCRIPTION
 *  Riches New Game Entry Function, Reinit Various Flags, Enter Riches Init
 *  Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Enter_New_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 CurrentLevel;
    U8 dropTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_flag_continue = 0;
    riches_game_end = 0;
    riches_game_grade = 0;
    riches_fla_decrease_energy = 10;
    riches_current_drop_object = 0;
    riches_bonus_flag = 0;
    riches_basket_position = 2;
    CurrentLevel = riches_game_level;
    dropTime = OBJECT_DROP_TIME / (CurrentLevel + 1);

    riches_bg_color = gui_color(247, 211, 0);

    memset(&riches_object_on_screen[i], 0, sizeof(RICHES_FLOATING_OBJECT_STRUCT) * MAX_DROPPING_OBJECTS);

    clear_screen();
    Riches_Init_App();
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Init_App
 * DESCRIPTION
 *  Init Riches Games, Allocate Bit Buffer, Initalize Objects, Draw Background,
 *  Get DS Values In Case Of Resume, Set Key Handlers, Enter Game Kernal
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Init_App(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_disable_alignment_timers();

    riches_game_status = 1;
    clear_screen();

    /* Set The Drop Time Depending On Game Level */
    riches_drop_timer = 2 * (OBJECT_DROP_TIME - riches_game_level * 50);

    /* Initialize Bit Buffer Pool */
    Riches_Init_Bit_Buffer_Pool();
    /* Init Falling Objects Data */
    Riches_Init_Falling_Object();

    /* Set The Energy Counter To Zero */
    riches_energy_counter = 0;

    /* In Case Of Resume Allocate Bit Buffer To Valid Falling Objects */
    if (riches_flag_continue == 1)  /* Case Of Continue */
    {
        for (i = 0; i < riches_current_drop_object; i++)
        {
            Riches_Allocate_Bit_Buffer(i);
        }
    }
    /* In Case Of New Game, Get Bucket Size And Default Cordinates */
    else    /* New Game */
    {
        if (riches_mem_allocated == 0)
        {
            riches_bucket = get_image(IMG_GX_RICHES_BASKET);
            gui_measure_image(riches_bucket, &riches_bucket_width, &riches_bucket_height);
            gui_measure_image(get_image(IMG_GX_RICHES_OBJECT_LEVEL), &riches_level_img_height, &riches_level_img_width);
            riches_bucket_y = (U8) (GAME_WINDOW_Y2 - riches_bucket_height);
        }
        riches_bucket_x = BUCKETX;
        riches_mem_allocated = 1;
    }

    /* Set Game UI Value */
    gui_set_font(&MMI_small_font);
    gui_set_clip(0, 0, 128, 128);
    gui_set_text_color(gui_color(0, 0, 0));

    /* Draw The Game Background */
    Riches_Draw_Background();
    gui_show_transparent_image(riches_bucket_x, riches_bucket_y, riches_bucket, 0);

    /* Draw The Game Level On Side Bar */
    for (i = 0; i <= riches_game_level; i++)
    {
        gui_show_transparent_image(91 + i * 12, 20, get_image(IMG_GX_RICHES_OBJECT_LEVEL), 0);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(0, 0, 128, 128);
#endif 

    if (riches_flag_continue == 0)
    {
        _get_bitmap(
            riches_bucket_x - riches_bucket_width - 2,
            riches_bucket_y,
            riches_bucket_x - 2,
            riches_bucket_y + riches_bucket_height,
            &riches_basket_bitmap);
    }
    else
    {
        if (riches_bucket_x > BUCKETX)
        {
            _get_bitmap(
                riches_bucket_x - riches_bucket_width - 2,
                riches_bucket_y,
                riches_bucket_x - 2,
                riches_bucket_y + riches_bucket_height,
                &riches_basket_bitmap);
        }
        else
        {
            _get_bitmap(
                riches_bucket_x + riches_bucket_width + 2,
                riches_bucket_y,
                riches_bucket_x + (2 * riches_bucket_width) + 2,
                riches_bucket_y + riches_bucket_height,
                &riches_basket_bitmap);
        }

        for (i = 0; i < riches_current_drop_object; i++)
        {
            U8 objectType = riches_object_on_screen[i].ObjectType;

            _get_bitmap(
                riches_object_on_screen[i].X,
                riches_object_on_screen[i].Y,
                riches_object_on_screen[i].X + riches_dropping_object[objectType]->objWidth - 1,
                riches_object_on_screen[i].Y + riches_dropping_object[objectType]->objHeight - 1,
                &riches_object_on_screen[i].richesBitmap);
        }
    }

    /* Set Various Key Handlers */
    SetKeyHandler(Riches_Move_Left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Riches_Move_Right, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Riches_Move_Left, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(Riches_Move_Right, KEY_6, KEY_EVENT_DOWN);

    /* If Resume Game Was On Bonus Start The Bonus Timer Callback */
    if (riches_bonus_flag == 1 || riches_bonus_flag == 2)
    {
        gui_start_timer(BONUS_TIMER_COUNT, Riches_Bonus_Time_Out);
        Riches_Show_Timer_Text();
    }

    /* If Game End Flag Is False Start The Game Kernal */
    if (riches_game_end != 1)
    {
        gui_start_timer(riches_drop_timer, Riches_Drop_Object_Timer_Callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Move_Left
 * DESCRIPTION
 *  Move Riches Basket To Left
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Move_Left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_basket_position == 0)
    {
        return;
    }
    _show_bitmap(riches_bucket_x, riches_bucket_y, &riches_basket_bitmap);
    riches_bucket_x = riches_column[--riches_basket_position] - 4;
    riches_bucket_move = 0;
    gui_show_transparent_image(riches_bucket_x, riches_bucket_y, riches_bucket, 0);
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Move_Right
 * DESCRIPTION
 *  Move Riches Basket To Right
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Move_Right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_basket_position == 4)
    {
        return;
    }
    _show_bitmap(riches_bucket_x, riches_bucket_y, &riches_basket_bitmap);
    riches_bucket_x = riches_column[++riches_basket_position] - 4;
    riches_bucket_move = 1;
    gui_show_transparent_image(riches_bucket_x, riches_bucket_y, riches_bucket, 0);
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Drop_Object_Timer_Callback
 * DESCRIPTION
 *  Riches Game Main Kernal
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Drop_Object_Timer_Callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_current_drop_object < MAX_DROPPING_OBJECTS)
    {
        Riches_Create_Object();
    }

    /* Drop The Object Depending Upon their , drop level less means object is faster. */
    for (i = 0; i < riches_current_drop_object; i++)
    {
        riches_object_on_screen[i].Y +=
            (MAX_DROP_DISTANCE / riches_dropping_object[riches_object_on_screen[i].ObjectType]->dropLevel);
    }

    /* Check for Crash */
    Riches_Check_Object_Status();

    /* If Game Over Then Return. */
    if (riches_game_status == 0)
    {
        return;
    }

    /* Redraw Screen. */
    Riches_Redraw_Screen();

    /* Reset the timer. */
    if (riches_game_end != 1)
    {
        if (riches_bonus_flag == 1 || riches_bonus_flag == 2)
        {
            riches_drop_timer = 30;
        }
        else
        {
            riches_drop_timer = 2 * (OBJECT_DROP_TIME - riches_game_level * 50);
        }
        gui_start_timer(riches_drop_timer, Riches_Drop_Object_Timer_Callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Create_Object
 * DESCRIPTION
 *  Riches New Objects Are Created In This API.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Create_Object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 randnum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In This Loop Object is created and its X value is determined on the Basis of no other slower in that colomn */
    if (!Riches_Allocate_Bit_Buffer(riches_current_drop_object))
    {
        return;
    }
    while (1)
    {

        switch (riches_bonus_flag)
        {
            case 1:
                randnum = rand() % 2;
                if (randnum == 0)
                {
                    riches_object_on_screen[riches_current_drop_object].ObjectType = RICHES_MONEY;
                }
                else
                {
                    riches_object_on_screen[riches_current_drop_object].ObjectType = RICHES_GIFT;
                }
                break;
            case 2:
                if (randnum == 0)
                {
                    riches_object_on_screen[riches_current_drop_object].ObjectType = RICHES_BAT;
                }
                else
                {
                    riches_object_on_screen[riches_current_drop_object].ObjectType = RICHES_DENONATOR;
                }
                break;
            default:
            {
                randnum = rand() % riches_runtime_object_num;
                riches_object_on_screen[riches_current_drop_object].ObjectType =
                    riches_object_weight[rand() % riches_runtime_object_num];
            }
        }

        randnum = rand() % 5;
        riches_object_on_screen[riches_current_drop_object].X = riches_column[randnum];

        for (i = 0; i < riches_current_drop_object; i++)
        {
            if (riches_object_on_screen[riches_current_drop_object].X == riches_object_on_screen[i].X)
                if (riches_dropping_object[riches_object_on_screen[riches_current_drop_object].ObjectType]->dropLevel <= riches_dropping_object[riches_object_on_screen[i].ObjectType]->dropLevel)      /* Drop level less means object is faster. */
                    if (((GAME_WINDOW_Y2 -
                          riches_object_on_screen[i].Y) *
                         riches_dropping_object[riches_object_on_screen[i].ObjectType]->dropLevel) + 60 >=
                        (GAME_WINDOW_Y2 *
                         riches_dropping_object[riches_object_on_screen[riches_current_drop_object].ObjectType]->
                         dropLevel))
                        /* if( riches_dropping_object[riches_object_on_screen[riches_current_drop_object].ObjectType].objHeight + 23 > riches_object_on_screen[i].Y ) */
                    {
                        i = 0xFF;
                        break;
                    }
        }
        if (i == 0xFF)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    /* Set the object Y to zero */
    riches_object_on_screen[riches_current_drop_object].Y = 0;

    /* Allocate Bit Buffer from the Pool */

    /* Increment Droping Object */
    riches_current_drop_object++;
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Check_Object_Status
 * DESCRIPTION
 *  Check Riches Falling Object Status
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Check_Object_Status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 flagKilled = FALSE;
    U8 tempRunningObjects = riches_current_drop_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < tempRunningObjects; i++)
    {
        /* Check The Object For Crash With Basket */
        U8 crashResult = Riches_Check_Object_Crash(i);

        switch (crashResult)    /* return 0 for Alive, 1 for Half Clash, 2 for Full Cash, 3 for Dead */
        {
            case 0:
                break;

            case 1: /* halfCrash(i); */
                Riches_Full_Crash(i);
                if (riches_game_status == 0)
                {
                    return;
                }
                /* Remove The Fallinf Object From Data Structure */
                Riches_Kill_Running_Object(i);
                if (riches_current_drop_object != 0)
                {
                    riches_current_drop_object--;
                }
                flagKilled = TRUE;
                break;

            case 2:
                Riches_Full_Crash(i);
                if (riches_game_status == 0)
                {
                    return;
                }
                if (riches_flag_angle_denonator == 1)
                {
                    riches_flag_angle_denonator = 0;
                    return;
                }
                Riches_Kill_Running_Object(i);
                if (riches_current_drop_object != 0)
                {
                    riches_current_drop_object--;
                }
                flagKilled = TRUE;
                break;

            case 3:
                Riches_Kill_Running_Object(i);
                if (riches_current_drop_object != 0)
                {
                    riches_current_drop_object--;
                }
                flagKilled = TRUE;
                break;

            default:
                break;
        }
    }

    /* If Any Of The Objects Is Removed From Data Structure, Re Seqence The Riches Object Data Structure */
    if (flagKilled == TRUE)
    {
        for (i = 0; i < tempRunningObjects; i++)
        {
            if (i == riches_current_drop_object)
            {
                break;
            }
            if (riches_object_on_screen[i].ObjectType == 0 && riches_object_on_screen[i].X == 0 &&
                riches_object_on_screen[i].Y == 0)
            {
                U8 j = i + 1;

                memcpy(
                    (void*)(riches_object_on_screen + i),
                    (void*)(riches_object_on_screen + j),
                    sizeof(RICHES_FLOATING_OBJECT_STRUCT) * (MAX_DROPPING_OBJECTS - j));
                --i;
            }
        }
        flagKilled = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Redraw_Screen
 * DESCRIPTION
 *  Redraw The Modified Portion Of Riches Game Screen
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Redraw_Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 displayString[20];
    U8 tempString[10];
    S32 strWidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_text_clip();

    /* Draw The Energy Bar */
    Riches_Draw_Energy_Level();

    gui_set_font(&MMI_small_font);

    /* Draw The Falling Riches Objects */
    for (i = 0; i < riches_current_drop_object; i++)
    {
        U8 objectType = riches_object_on_screen[i].ObjectType;

        if ((riches_object_on_screen[i].Y -
             MAX_DROP_DISTANCE / riches_dropping_object[riches_object_on_screen[i].ObjectType]->dropLevel) != 0)
        {
            _show_bitmap(
                riches_object_on_screen[i].X,
                riches_object_on_screen[i].Y - (MAX_DROP_DISTANCE / riches_dropping_object[objectType]->dropLevel),
                &riches_object_on_screen[i].richesBitmap);
        }
        _get_bitmap(
            riches_object_on_screen[i].X,
            riches_object_on_screen[i].Y,
            riches_object_on_screen[i].X + riches_dropping_object[objectType]->objWidth - 1,
            riches_object_on_screen[i].Y + riches_dropping_object[objectType]->objHeight - 1,
            &riches_object_on_screen[i].richesBitmap);
        gui_show_transparent_image(
            riches_object_on_screen[i].X,
            riches_object_on_screen[i].Y,
            riches_dropping_object[objectType]->objImage,
            0);
    }
    riches_flag_continue = 0;
    gui_show_transparent_image(riches_bucket_x, riches_bucket_y, riches_bucket, 0);

    /* Fill The Back Ground Rectangle Of Score/Timer */
    gui_fill_rectangle(INFO_WINDOW_X1 + 5, 59, INFO_WINDOW_X2 - 2, 57 + 10, riches_bg_color);

    sprintf((PS8) tempString, "%d", riches_game_grade);
    mmi_asc_to_ucs2((PS8) displayString, (PS8) tempString);
    strWidth = gui_get_string_width((UI_string_type) displayString);
    strWidth /= 2;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(INFO_WINDOW_X1 + 19 + strWidth, 59);
    }
    else
    {
        gui_move_text_cursor(INFO_WINDOW_X1 + 19 - strWidth, 59);
    }

    gui_print_text((UI_string_type) displayString);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_BLT_double_buffer(0, 0, 128, 128);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  Riches_Draw_Energy_Level
 * DESCRIPTION
 *  Draw Riches Energy On Side Bar
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Draw_Energy_Level(void) /* 0 - Down,        1 - Up */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_energy_counter != riches_fla_decrease_energy || riches_bonus_flag != 0)
    {
        /* If Energy Is Reduces Draw Whole Energy Bar */
        if (riches_energy_counter >= riches_fla_decrease_energy || riches_energy_counter == 0)
        {
            gui_show_transparent_image(ENERGY_BARBG_X, ENERGY_BARBG_Y, get_image(IMG_GX_RICHES_ENERGYBG), 0);
            for (riches_energy_counter = 0; riches_energy_counter < riches_fla_decrease_energy; riches_energy_counter++)
            {
                gui_show_transparent_image(
                    ENERGY_BAR_X,
                    ENERGY_BAR_Y - riches_energy_counter * 3,
                    get_image(IMG_GX_RICHES_ENERGYBAR),
                    0);
            }
        }
        /* Else Draw Only Energy Bars Which Are Added */
        else
        {
            for (; riches_energy_counter < riches_fla_decrease_energy; riches_energy_counter++)
            {
                gui_show_transparent_image(
                    ENERGY_BAR_X,
                    ENERGY_BAR_Y - riches_energy_counter * 3,
                    get_image(IMG_GX_RICHES_ENERGYBAR),
                    0);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Decrease_Energy
 * DESCRIPTION
 *  Reduce Energy On Bucket Movement Not Used Now
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Decrease_Energy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_decrease_energy < 100)
    {
        riches_decrease_energy++;
    }
    if (riches_decrease_energy >= 100)
    {
        riches_fla_decrease_energy--;
        if (riches_fla_decrease_energy == 0)
        {
            Riches_Decrease_Life();
        }
        riches_decrease_energy = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Init_Falling_Object
 * DESCRIPTION
 *  Initlize Riches Object Data Structure
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Init_Falling_Object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k = 1; /* Temp Variables; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < RICHES_TOTAL_OBJECTS; i++)
    {
        switch (i)
        {
            case RICHES_GIFT:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_GIFT);
                riches_dropping_object[i]->objWeight = RICHES_GIFT_WEIGHT;
                riches_dropping_object[i]->scoreRate = 5;
                riches_dropping_object[i]->dropLevel = 2;
                break;  /* Predefined */

            case RICHES_GOLDNOTE:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_GOLDNOTE);
                riches_dropping_object[i]->objWeight = RICHES_GOLDNOTE_WEIGHT;
                riches_dropping_object[i]->scoreRate = 20;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_BOMB:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_BOMB);
                riches_dropping_object[i]->objWeight = RICHES_BOMB_WEIGHT;
                riches_dropping_object[i]->scoreRate = -4;
                riches_dropping_object[i]->dropLevel = 2;
                break;  /* Predefined */

            case RICHES_APPLE:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_APPLE);
                riches_dropping_object[i]->objWeight = RICHES_APPLE_WEIGHT;
                riches_dropping_object[i]->scoreRate = 10;
                riches_dropping_object[i]->dropLevel = 2;
                break;  /* Predefined */

            case RICHES_SPIDER:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_SPIDER);
                riches_dropping_object[i]->objWeight = RICHES_SPIDER_WEIGHT;
                riches_dropping_object[i]->scoreRate = -5;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_BATTER20:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_BATTERY20);
                riches_dropping_object[i]->objWeight = RICHES_BATTER20_WEIGHT;
                riches_dropping_object[i]->scoreRate = 1;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_BATTERY:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_BATTERYFULL);
                riches_dropping_object[i]->objWeight = RICHES_BATTERY_WEIGHT;
                riches_dropping_object[i]->scoreRate = 3;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_ANGLE:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_ANGLE);
                riches_dropping_object[i]->objWeight = RICHES_ANGLE_WEIGHT;
                riches_dropping_object[i]->scoreRate = 0;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_THEIF:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_THEIF);
                riches_dropping_object[i]->objWeight = RICHES_THEIF_WEIGHT;
                riches_dropping_object[i]->scoreRate = -100;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_DENONATOR:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_DENONATOR);
                riches_dropping_object[i]->objWeight = RICHES_DENONATOR_WEIGHT;
                riches_dropping_object[i]->scoreRate = -2;
                riches_dropping_object[i]->dropLevel = 2;
                break;  /* Predefined */

            case RICHES_MONEY:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_MONEY);
                riches_dropping_object[i]->objWeight = RICHES_MONEY_WEIGHT;
                riches_dropping_object[i]->scoreRate = 10;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_BAT:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_BAT);
                riches_dropping_object[i]->objWeight = RICHES_BAT_WEIGHT;
                riches_dropping_object[i]->scoreRate = -10;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            case RICHES_DEAMON:
                riches_dropping_object[i]->objImage = get_image(IMG_GX_RICHES_OBJECT_EVIL);
                riches_dropping_object[i]->objWeight = RICHES_DEAMON_WEIGHT;
                riches_dropping_object[i]->scoreRate = 0;
                riches_dropping_object[i]->dropLevel = 1;
                break;  /* Predefined */

            default:
                riches_dropping_object[i]->objImage = get_image(IMG_GLOBAL_L1);
                riches_dropping_object[i]->objWeight = 4;
                riches_dropping_object[i]->scoreRate = 0;
                riches_dropping_object[i]->dropLevel = 0;
                break;  /* Predefined */
        }
        gui_measure_image(
            riches_dropping_object[i]->objImage,
            &riches_dropping_object[i]->objWidth,
            &riches_dropping_object[i]->objHeight);
    }

    k = 0;
    for (i = 0; i < RICHES_TOTAL_OBJECTS; i++)
    {
        for (j = 0; j < riches_dropping_object[i]->objWeight; j++)
        {
            riches_object_weight[k++] = i;  /*  */
        }
    }

    riches_runtime_object_num = k - 1;

}


/*****************************************************************************
 * FUNCTION
 *  Riches_Init_Bit_Buffer_Pool
 * DESCRIPTION
 *  Initlize Bit Buffer Pool For Background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Init_Bit_Buffer_Pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < RICHES_TOTAL_OBJECTS; i++)
    {
        riches_dropping_object[i] = (RICHES_OBJECT_IMAGE_STRUCT*) (&hintData[i]);
    }

    for (i = 0; i < MAX_DROPPING_OBJECTS; i++)
    {
        riches_bit_buffer_pool.bitBuffer[i] = subMenuDataPtrs[i * 5];
        memset(riches_bit_buffer_pool.bitBuffer[i], 0, RICHES_IMAGEBITBUFFER);
        riches_bit_buffer_pool.isValidMemory[i] = 0xFF;
    }
    if (riches_flag_continue != 1)
    {
        riches_basket_bitmap.data = subMenuDataPtrs[i * 5];
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Allocate_Bit_Buffer
 * DESCRIPTION
 *  Riches Bit Buffer Alocation To New Object
 * PARAMETERS
 *  ID      [IN]        New Object ID
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL Riches_Allocate_Bit_Buffer(U8 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_DROPPING_OBJECTS; i++)
    {
        if (riches_bit_buffer_pool.isValidMemory[i] == 0xFF)
        {
            riches_object_on_screen[ID].richesBitmap.data = riches_bit_buffer_pool.bitBuffer[i];
            riches_bit_buffer_pool.isValidMemory[i] = 0;
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Free_Bit_Buffer
 * DESCRIPTION
 *  Free Buffer Pool On Object Kill
 * PARAMETERS
 *  ID      [IN]        Killed Object ID
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Free_Bit_Buffer(U8 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_DROPPING_OBJECTS; i++)
    {
        if (riches_object_on_screen[ID].richesBitmap.data == riches_bit_buffer_pool.bitBuffer[i])
        {
            memset(riches_bit_buffer_pool.bitBuffer[i], 0, RICHES_IMAGEBITBUFFER);
            riches_bit_buffer_pool.isValidMemory[i] = 0xFF;
            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  Riches_Kill_Running_Object
 * DESCRIPTION
 *  Remove The Object From The Data Structure
 * PARAMETERS
 *  ID      [IN]        id of the object to be removed.
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Kill_Running_Object(U8 ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _show_bitmap(
        riches_object_on_screen[ID].X,
        riches_object_on_screen[ID].Y - (MAX_DROP_DISTANCE / riches_dropping_object[riches_object_on_screen[ID].ObjectType]->dropLevel),
        &riches_object_on_screen[ID].richesBitmap);
    if ((riches_column[riches_basket_position]) != riches_object_on_screen[ID].X)
    {
        _show_bitmap((riches_object_on_screen[ID].X - 4), riches_bucket_y, &riches_basket_bitmap);
    }
    riches_object_on_screen[ID].ObjectType = 0;
    riches_object_on_screen[ID].X = 0;
    riches_object_on_screen[ID].Y = 0;
    Riches_Free_Bit_Buffer(ID);
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Check_Object_Crash
 * DESCRIPTION
 *  Check The Object Crash With Bucket
 * PARAMETERS
 *  i       [IN]        Object Id Need To Check For Crash With Basket
 * RETURNS
 *  void
 *****************************************************************************/
U8 Riches_Check_Object_Crash(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 objId = riches_object_on_screen[i].ObjectType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (riches_object_on_screen[i].Y + riches_dropping_object[objId]->objHeight - OBJ_DIS_LIMIT / 2 > riches_bucket_y)
    {
        if (riches_object_on_screen[i].X > riches_bucket_x)
        {
            if ((riches_object_on_screen[i].X + riches_dropping_object[objId]->objWidth) <
                (riches_bucket_x + riches_bucket_width))
            {
                return 2;
            }
            else if ((riches_object_on_screen[i].X + (riches_dropping_object[objId]->objWidth) * 3 / 4) < riches_bucket_x + riches_bucket_width)        /* If Object Right By Less Then 25% */
            {
                return 1;
            }
        }
        else
        {
            if ((riches_object_on_screen[i].X + riches_dropping_object[objId]->objWidth / 4) > riches_bucket_x) /* If Object Left By Less Then 25% */
            {
                return 1;
            }
        }
    }
    if (riches_object_on_screen[i].Y > GAME_WINDOW_Y2 - riches_dropping_object[objId]->objHeight - 1)
    {
        return 3;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Full_Crash
 * DESCRIPTION
 *  Action Taken On Riches Full Crash
 * PARAMETERS
 *  i       [IN]        Object Id Which Crashes
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Full_Crash(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 objId = riches_object_on_screen[i].ObjectType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (objId)
    {
/***********************************************/
        case RICHES_GIFT:
        case RICHES_GOLDNOTE:
        case RICHES_APPLE:
        case RICHES_MONEY:
        case RICHES_THEIF:
        case RICHES_BAT:
        {
            riches_game_grade += (S16) riches_dropping_object[objId]->scoreRate;

            if (riches_game_grade < 0)
            {
                riches_game_grade = 0;
            }

            if (riches_dropping_object[objId]->scoreRate > 0)
            {
            #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

                GFX_PLAY_SOUND_EFFECTS_MIDI(eatgood_midi);
            #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                GFX_PLAY_AUDIO_MIDI(RichesEatGood, RICHESEATGOOD, DEVICE_AUDIO_PLAY_ONCE);
            #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            }
            else if (riches_dropping_object[objId]->scoreRate < 0)
            {
            #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

                GFX_PLAY_SOUND_EFFECTS_MIDI(eatbad_midi);
            #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                GFX_PLAY_AUDIO_MIDI(RichesEatBad, RICHESEATBAD, DEVICE_AUDIO_PLAY_ONCE);
            #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            }
            break;
        }
/***********************************************/
        case RICHES_BOMB:
        {
            GFX_PLAY_VIBRATION();
        }
        case RICHES_SPIDER:
        case RICHES_DENONATOR:
        case RICHES_BATTER20:
        case RICHES_BATTERY:
        {
            riches_fla_decrease_energy += riches_dropping_object[objId]->scoreRate;
            if (riches_dropping_object[objId]->scoreRate > 0)
            {
            #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

                GFX_PLAY_SOUND_EFFECTS_MIDI(eatgood_midi);
            #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                GFX_PLAY_AUDIO_MIDI(RichesEatGood, RICHESEATGOOD, DEVICE_AUDIO_PLAY_ONCE);
            #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            }
            else if (riches_dropping_object[objId]->scoreRate < 0)
            {
            #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

                GFX_PLAY_SOUND_EFFECTS_MIDI(eatbad_midi);
            #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                GFX_PLAY_AUDIO_MIDI(RichesEatBad, RICHESEATBAD, DEVICE_AUDIO_PLAY_ONCE);
            #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            }

            if (riches_fla_decrease_energy <= 0)
            {
                riches_game_status = 0;
                riches_game_end = 1;
                Riches_End_Game();
                return;
            }
            else if (riches_fla_decrease_energy > 10)
            {
                riches_fla_decrease_energy = 10;
            }

            break;
        }
/***********************************************/
        case RICHES_ANGLE:
        {
            Riches_Action_Angle();
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
            GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(eatgood_midi);
        #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            GFX_PLAY_AUDIO_MIDI(RichesEatGood, RICHESEATGOOD, DEVICE_AUDIO_PLAY_ONCE);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            break;
        }

/***********************************************/
        case RICHES_DEAMON:
        {
            Riches_Action_Denonator();
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(eatgood_midi);
            GFX_STOP_SOUND_EFFECTS_MIDI(eatbad_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(eatbad_midi);
        #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            GFX_PLAY_AUDIO_MIDI(RichesEatBad, RICHESEATBAD, DEVICE_AUDIO_PLAY_ONCE);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            break;
        }
    }   /* switch */
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Action_Angle
 * DESCRIPTION
 *  Action Taken In Case Of Angle Crash.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Action_Angle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_bonus_flag = 1;
    Riches_Reset_Running_Object();
    if (riches_game_end != 1)
    {
        gui_start_timer(BONUS_TIMER_COUNT, Riches_Bonus_Time_Out);
        Riches_Show_Timer_Text();
    }
    riches_flag_angle_denonator = 1;
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Action_Denonator
 * DESCRIPTION
 *  Action Taken On Deamon Crash With Basket
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Action_Denonator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_bonus_flag = 2;
    Riches_Reset_Running_Object();
    if (riches_game_end != 1)
    {
        gui_start_timer(BONUS_TIMER_COUNT, Riches_Bonus_Time_Out);
        Riches_Show_Timer_Text();
    }
    riches_flag_angle_denonator = 1;
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Reset_Running_Object
 * DESCRIPTION
 *  Reset All Running Objects On Deamon Or Angle Crash.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Reset_Running_Object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < riches_current_drop_object; i++)
    {
        Riches_Kill_Running_Object(i);
    }
    riches_current_drop_object = 0;
    Riches_Draw_Background();
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Bonus_Time_Out
 * DESCRIPTION
 *  Reset The Timer Text To Score On Bonus Time Out.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Bonus_Time_Out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_bouns_timer++;
    if (riches_bouns_timer == BOUNSTIMEINSEC)
    {
        riches_bonus_flag = 0;
        riches_bouns_timer = 0;
        Riches_Reset_Level_From_Timer();
    }
    else
    {
        if (riches_game_end != 1)
        {
            Riches_Show_Timer_Text();
            gui_start_timer(BONUS_TIMER_COUNT, Riches_Bonus_Time_Out);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Decrease_Life
 * DESCRIPTION
 *  Decrease Riches Life On Reduceing Energy To Zero, Not Used Now.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Decrease_Life(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    riches_life--;
    if (riches_life != 0)
    {
        riches_decrease_energy = 0;
        riches_fla_decrease_energy = 5;
    }
    else
    {
        riches_game_status = 0;
        riches_game_end = 1;
        Riches_End_Game();
        //showGameEndPopUp();
        //   ShowGameEndScreen();
        //   gameEndScoreStatus = checkSocreOnEnd();

    }
}


/*****************************************************************************
 * FUNCTION
 *  Riches_End_Game
 * DESCRIPTION
 *  Set Riches Game End Flags, Enter Game End Screen.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_End_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(Riches_Bonus_Time_Out);
    gui_cancel_timer(Riches_Drop_Object_Timer_Callback);

    riches_mem_allocated = 0;
    riches_is_new_game = TRUE;
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Draw_Background
 * DESCRIPTION
 *  Draw Riches Background
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Draw_Background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_transparent_image(0, 0, get_image(IMG_GX_RICHES_BACKGROUND), 0);
#else
    gui_show_transparent_image(
        0, 
        0, 
        get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_riches_language_index, 
             IMG_GX_RICHES_BACKGROUND_LANGUAGE0, 
             MMI_RICHES_STRING_COUNT, 
             MMI_RICHES_STRING_BACKGROUND)),
        0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  Riches_Show_Timer_Text
 * DESCRIPTION
 *  This API Called After 1 Sec When Bonus Time Is Running To Display Remaining
 *  Bonus Time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Show_Timer_Text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bufferCount[64];
    U8 bufferUcs2[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(INFO_WINDOW_X1 + 2, 8, INFO_WINDOW_X2 - 2, 20 + 10, riches_bg_color);

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(INFO_WINDOW_X1 + 3, 9, (PU8) get_image(IMG_GX_RICHES_BACKGROUND_TIMER));
#else
    gui_show_image(
        INFO_WINDOW_X1 + 3, 
        9,
        (PU8) get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_riches_language_index, 
             IMG_GX_RICHES_BACKGROUND_LANGUAGE0, 
             MMI_RICHES_STRING_COUNT, 
             MMI_RICHES_STRING_BACKGROUND_TIMER)));
#endif
    gui_reset_text_clip();

    sprintf((PS8) bufferCount, "%d", BOUNSTIMEINSEC - riches_bouns_timer);
    mmi_asc_to_ucs2((PS8) bufferUcs2, (PS8) bufferCount);

    gui_move_text_cursor(INFO_WINDOW_X1 + 15, 22);
    gui_print_text((UI_string_type) bufferUcs2);

}


/*****************************************************************************
 * FUNCTION
 *  Riches_Reset_Level_From_Timer
 * DESCRIPTION
 *  Show Games Level After Bouns Timer Is Complete.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Riches_Reset_Level_From_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(INFO_WINDOW_X1 + 2, 8, INFO_WINDOW_X2 - 2, 20 + 10, riches_bg_color);
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(INFO_WINDOW_X1 + 3, 9, (PU8) get_image(IMG_GX_RICHES_BACKGROUND_LEVEL));;
#else
    gui_show_image(
        INFO_WINDOW_X1 + 3, 
        9,
        (PU8) get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_riches_language_index, 
             IMG_GX_RICHES_BACKGROUND_LANGUAGE0, 
             MMI_RICHES_STRING_COUNT, 
             MMI_RICHES_STRING_BACKGROUND_LEVEL)));
#endif

    gui_reset_text_clip();

    for (i = 0; i <= riches_game_level; i++)
    {
        gui_show_transparent_image(91 + i * 12, 20, get_image(IMG_GX_RICHES_OBJECT_LEVEL), 0);
    }
}

#endif /* IS_RICHES_BASE_GAME */ 

